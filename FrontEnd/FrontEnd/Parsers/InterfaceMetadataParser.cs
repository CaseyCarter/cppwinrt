using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Reflection.Metadata;

using Microsoft.Wcl.DataStore;
using System.Reflection;

namespace Microsoft.Wcl.Parsers
{
    internal class InterfaceMetadataParser
    {
        public void Initialize(FrontEndConfiguration configuration)
        {
            this.Configuration = configuration;
        }

        public InterfaceInfo Parse(MetadataReader assembly, TypeDefinition typeDef, string parentFullTypeName, bool isDelegate, IDictionary<MethodDefinitionHandle, string> specialMethodNamesRepository)
        {
            var interfaceInfo = new InterfaceInfo();
            CustomAttributeInfo customAttributeInfo = null;
            Guid guid = Guid.Empty;
            string delegateFullTypeName = null;

            var namespaceName = assembly.GetString(typeDef.Namespace);
            var typeName = assembly.GetString(typeDef.Name);
            var fullTypeName = TypeNameUtilities.GetFormattedFullTypeName(namespaceName, typeName);
            if (isDelegate)
            {
                delegateFullTypeName = TypeNameUtilities.GetFormattedFullTypeName(namespaceName, "I" + typeName);
            }

            var customAttributes = CustomAttributeMetadataParser.GetAttributes(assembly, typeDef);
            if (!CustomAttributeMetadataParser.FindAttribute(assembly, customAttributes, CustomAttributeKind.Guid, out customAttributeInfo))
            {
                throw new InvalidOperationException(String.Format(StringExceptionFormats.InterfaceWithoutGuidAttribute, parentFullTypeName));
            }

            CustomAttributeMetadataParser.GetGuidValue(assembly, customAttributeInfo, out guid);

            interfaceInfo.FullName = (isDelegate ? delegateFullTypeName : fullTypeName);
            interfaceInfo.Name = TypeNameUtilities.GetIndexOfTypeName(interfaceInfo.FullName);
            interfaceInfo.Uuid = guid.ToString();
            interfaceInfo.Deprecated = CustomAttributeMetadataParser.FindAttribute(assembly, customAttributes, CustomAttributeKind.Deprecated); ;
            interfaceInfo.Delegate = (isDelegate ? TypeNameUtilities.GetFormattedFullTypeName(namespaceName, typeName) : null);
            interfaceInfo.MethodsInfo = GetMethodsInfo(assembly, typeDef, interfaceInfo.FullName, isDelegate, specialMethodNamesRepository);
            interfaceInfo.RequiredInterfacesInfo = GetRequiredInterfacesInfo(assembly, typeDef, interfaceInfo.FullName);

            return interfaceInfo;
        }

        private IList<InterfaceMethodInfo> GetMethodsInfo(MetadataReader assembly, TypeDefinition typeDef, string interfaceFullTypeName, bool isDelegate, IDictionary<MethodDefinitionHandle, string> specialMethodNamesRepository)
        {
            var methodInfoList = new List<InterfaceMethodInfo>();

            var methodHandleCollection = typeDef.GetMethods();

            foreach (var methodHandle in methodHandleCollection)
            {
                var methodDef = assembly.GetMethodDefinition(methodHandle);
                var methodName = assembly.GetString(methodDef.Name);
                string abiMethodName = null;
                string overloadMethodName = null;
                string prettyMethodName = null;
                CustomAttributeInfo customAttributeInfo = null;

                // For delegates, the metadata comes with a .ctor method which is not needed.
                if (isDelegate && methodName == ".ctor")
                {
                    continue;
                }

                // Deal with overloads.
                var customAttributes = CustomAttributeMetadataParser.GetAttributes(assembly, methodDef.GetCustomAttributes());
                if (CustomAttributeMetadataParser.FindAttribute(assembly, customAttributes, CustomAttributeKind.Overload, out customAttributeInfo))
                {
                    CustomAttributeMetadataParser.GetOverloadName(assembly, customAttributeInfo, out overloadMethodName);
                }

                UpdateMethodNameAndAbiMethodName(methodHandle, methodDef, methodName, overloadMethodName, specialMethodNamesRepository, out prettyMethodName, out abiMethodName);
                var fullAbiMethodName = TypeNameUtilities.GetFormattedFullTypeName(interfaceFullTypeName, abiMethodName);

                var info = new InterfaceMethodInfo();
                info.Name = prettyMethodName;
                info.AbiName = abiMethodName;
                info.Deprecated = CustomAttributeMetadataParser.FindAttribute(assembly, customAttributes, CustomAttributeKind.Deprecated);
                info.InterfaceFullTypeName = interfaceFullTypeName;
                info.ParametersInfo = GetParametersInfo(assembly, methodDef, fullAbiMethodName);

                methodInfoList.Add(info);
            }

            return methodInfoList;
        }

        private void UpdateMethodNameAndAbiMethodName(MethodDefinitionHandle methodHandle, MethodDefinition methodDef, string methodName, string overloadMethodName, IDictionary<MethodDefinitionHandle, string> specialMethodNamesRepository, out string prettyMethodName, out string abiMethodName)
        {
            string prettyMethodNameLocal = null;
            string abiMethodNameLocal = null;

            // Special name makes names be diferent to what they look in the metadata.
            // For example, a property getter may look as object.PropertyName, but in the metadata it is really object.get_PropertyName.
            // Same thing with property setter (put_),  event add (add_) and event remove (remove_).
            // In this cases, the methodName becomes the abiMethodName and the methodName is fixed to not have the prefix.
            if (((methodDef.Attributes & MethodAttributes.SpecialName) == MethodAttributes.SpecialName))
            {
                string friendlyName;
                if (specialMethodNamesRepository.TryGetValue(methodHandle, out friendlyName))
                {
                    abiMethodNameLocal = methodName;
                    prettyMethodNameLocal = friendlyName;
                }
                // "Invoke" is a special name, but there won't be any data about it (compared to Fields and Events).
                else if (methodName != "Invoke")
                {
                    throw new InvalidOperationException(String.Format(StringExceptionFormats.CouldNotFindFriendlyMethodNameInRepository, methodName));
                }
            }

            // For non especial cases or overloads, append the prefix to the appropiate name
            if (abiMethodNameLocal == null)
            {
                abiMethodNameLocal = String.Format(StringFormats.ProjectedAbiMethod, (overloadMethodName ?? methodName));
                prettyMethodNameLocal = methodName;
            }

            abiMethodName = abiMethodNameLocal;
            prettyMethodName = prettyMethodNameLocal;
        }

        private IList<InterfaceMethodParameterInfo> GetParametersInfo(MetadataReader assembly, MethodDefinition methodDef, string methodId)
        {
            var list = new List<InterfaceMethodParameterInfo>();

            var parameterHandlesCollection = methodDef.GetParameters();
            var blobReader = assembly.GetBlobReader(methodDef.Signature);
            var signatureHeader = blobReader.ReadSignatureHeader();
            Debug.Assert(signatureHeader.Kind == SignatureKind.Method);

            if (signatureHeader.IsGeneric)
            {
                blobReader.ReadCompressedInteger();
            }

            var parameterCount = blobReader.ReadCompressedInteger();
            var returnSignatureTypeCode = blobReader.ReadSignatureTypeCode();

            bool firstParameterIsReturnParameter = (parameterHandlesCollection.Count == (parameterCount + 1));
            if (returnSignatureTypeCode == SignatureTypeCode.GenericTypeParameter)
            {
                Debug.Assert(firstParameterIsReturnParameter == false);
                var returnFullTypeName = MetadataParserHelpers.GetFullTypeNameFromMetadata(assembly, ref blobReader, returnSignatureTypeCode);

                var info = new InterfaceMethodParameterInfo();
                info.Name = "genericTypeParameter";
                info.Type = returnFullTypeName;
                info.Flags = ParameterAttributesInfo.Return;
                info.MethodFullName = methodId;

                list.Add(info);
            }
            else if (returnSignatureTypeCode != SignatureTypeCode.Void)
            {
                firstParameterIsReturnParameter = true;
            }

            foreach (var parameterHandle in parameterHandlesCollection)
            {
                var info = GetParameterInfo(assembly, parameterHandle, ref blobReader, returnSignatureTypeCode, firstParameterIsReturnParameter, methodId);
                firstParameterIsReturnParameter = false;
                list.Add(info);
            }

            return list;
        }

        private InterfaceMethodParameterInfo GetParameterInfo(MetadataReader assembly, ParameterHandle parameterHandle, ref BlobReader blobReader, SignatureTypeCode returnSignatureTypeCode, bool firstParameterIsReturnParameter, string methodFullName)
        {
            var parameter = assembly.GetParameter(parameterHandle);
            var parameterName = assembly.GetString(parameter.Name);
            var parameterSignatureTypeCode = firstParameterIsReturnParameter ? returnSignatureTypeCode : blobReader.ReadSignatureTypeCode();
            var parameterAttributes = ParameterAttributesInfo.None;

            CheckParameterAttributesFromMetadata(parameter.Attributes);

            var modifiers = MetadataParserHelpers.ReadCustomMods(assembly, ref blobReader, ref parameterSignatureTypeCode);

            foreach (var modifier in modifiers)
            {
                if (modifier.FullTypeName == FullTypeNameConstants.System_Runtime_Compiler_Services_IsConst)
                {
                    parameterAttributes |= ParameterAttributesInfo.Const;
                    break;
                }
            }

            if (parameterSignatureTypeCode == SignatureTypeCode.ByReference)
            {
                parameterAttributes |= ParameterAttributesInfo.ByRef;
                parameterSignatureTypeCode = blobReader.ReadSignatureTypeCode();
            }

            parameterAttributes |= (ParameterAttributesInfo)parameter.Attributes;
            if (firstParameterIsReturnParameter)
            {
                parameterAttributes |= ParameterAttributesInfo.Return;
                firstParameterIsReturnParameter = false;
            }

            if (parameterSignatureTypeCode == SignatureTypeCode.SZArray)
            {
                parameterAttributes |= ParameterAttributesInfo.Array;
            }

            var parameterFullTypeName = MetadataParserHelpers.GetFullTypeNameFromMetadata(assembly, ref blobReader, parameterSignatureTypeCode);

            var info = new InterfaceMethodParameterInfo();
            info.Name = parameterName;
            info.Type = parameterFullTypeName;
            info.Flags = parameterAttributes;
            info.MethodFullName = methodFullName;

            return info;
        }

        private IList<InterfaceRequiredInterfaceInfo> GetRequiredInterfacesInfo(MetadataReader assembly, TypeDefinition typeDef, string interfaceFullTypeName)
        {
            var list = new List<InterfaceRequiredInterfaceInfo>();

            foreach (var implDefHandle in typeDef.GetInterfaceImplementations())
            {
                var implDef = assembly.GetInterfaceImplementation(implDefHandle);
                var interfaceHandle = implDef.Interface;
                var interfaceName = MetadataParserHelpers.GetFullTypeNameFromMetadata(assembly, interfaceHandle);

                var info = new InterfaceRequiredInterfaceInfo();
                info.InterfaceFullTypeName = interfaceFullTypeName;
                info.Requires = interfaceName;

                list.Add(info);
            }

            return list;
        }

        private static void CheckParameterAttributesFromMetadata(ParameterAttributes parameterAttributes)
        {
            // We only understand these two attributes from metadata. If anything else, throw
            const System.Reflection.ParameterAttributes flag = ParameterAttributes.In | ParameterAttributes.Out;
            var result = parameterAttributes | flag;
            if (result != flag)
            {
                throw new InvalidOperationException();
            }
        }

        private FrontEndConfiguration Configuration { get; set; }
    }
}