using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Reflection.Metadata;

namespace Microsoft.Wcl.Parsers
{
    internal enum CustomAttributeKind
    {
        Composable,
        Activatable,
        DefaultActivatable,
        DefaultInterface,
        Guid,
        Flags,
        ExclusiveTo,
        Static,
        Deprecated,
        Overload,
        Overridable,
        Protected,
        Other
    }

    // mirrors Windows.Foundation.Metadata.CompositionType
    internal enum CompositionTypeInfo
    {
        // NotSet is private to the Front End. It does not exist in metadata.
        Unknown = 0,
        Protected = 1,
        Public = 2
    }

    internal class CustomAttributeInfo
    {
        public string FullTypeName;
        public string Namespace;
        public EntityHandle Constructor;
        public BlobHandle BlobHandle;
    }

    internal class CustomAttributeMetadataParser
    {
        public static IList<CustomAttributeInfo> GetAttributes(MetadataReader assembly, InterfaceImplementation interfaceImpl)
        {
            return GetAttributes(assembly, interfaceImpl.GetCustomAttributes());
        }

        public static IList<CustomAttributeInfo> GetAttributes(MetadataReader assembly, TypeDefinition typeDef)
        {
            return GetAttributes(assembly, typeDef.GetCustomAttributes());
        }

        public static IList<CustomAttributeInfo> GetAttributes(MetadataReader assembly, CustomAttributeHandleCollection customAttributeHandles)
        {
            var list = new List<CustomAttributeInfo>();

            foreach (var customAttributeHandle in customAttributeHandles)
            {
                var attribute = new CustomAttributeInfo();

                var customAttribute = assembly.GetCustomAttribute(customAttributeHandle);

                if (customAttribute.Constructor.Kind == HandleKind.MemberReference)
                {
                    attribute.FullTypeName = MetadataParserHelpers.GetFullTypeNameFromMetadata(assembly, customAttribute.Constructor);
                    // Both of the following objects may be needed later on if more information about the CustomAttribute is needed.
                    // They are not expanded (values from the blob are not read, because in many cases it is not needed)
                    // When actually needed, callee can call other methods to get information, for example, type of a parameter and such.
                    attribute.Constructor = customAttribute.Constructor;
                    attribute.BlobHandle = customAttribute.Value;

                    list.Add(attribute);
                }
                else
                {
                    throw new NotImplementedException();
                }
            }

            return list;
        }

        public static bool FindAttribute(MetadataReader assembly, IList<CustomAttributeInfo> attributes, CustomAttributeKind attributeType)
        {
            CustomAttributeInfo output = null;
            return FindAttribute(assembly, attributes, attributeType, out output);
        }

        public static bool FindAttribute(MetadataReader assembly, IList<CustomAttributeInfo> attributes, CustomAttributeKind attributeType, out CustomAttributeInfo output)
        {
            output = null;

            foreach (var attribute in attributes)
            {
                Debug.Assert(!attribute.FullTypeName.Contains("."));

                if (attributeType == CustomAttributeKind.Activatable && attribute.FullTypeName == FullTypeNameConstants.Windows_Foundation_Metadata_ActivatableAttribute)
                {
                    output = attribute;
                    return true;
                }
                else if (attributeType == CustomAttributeKind.Composable && attribute.FullTypeName == FullTypeNameConstants.Windows_Foundation_Metadata_ComposableAttribute)
                {
                    output = attribute;
                    return true;
                }
                else if (attributeType == CustomAttributeKind.Guid && attribute.FullTypeName == FullTypeNameConstants.Windows_Foundation_Metadata_GuidAttribute)
                {
                    output = attribute;
                    return true;
                }
                else if (attributeType == CustomAttributeKind.DefaultActivatable && attribute.FullTypeName == FullTypeNameConstants.Windows_Foundation_Metadata_ActivatableAttribute)
                {
                    TypeHolderInfo typeHolderInfo;
                    var memberReferenceHandle = (MemberReferenceHandle)attribute.Constructor;
                    var memberReference = assembly.GetMemberReference(memberReferenceHandle);
                    CustomAttributeMetadataParser.GetDeferedCustomAttributes(assembly, memberReference.Signature, attribute.BlobHandle, out typeHolderInfo);

                    // Activatable attribute has several overloads. When the first parameter is a Uint32, we know it is the right one.
                    // Windows.Foundation.Metadata.ActivatableAttribute overloads show that when the first parameter is a uint, it is a version,
                    // whereas if it is a TypeHandle, it is an Interface.
                    // This is even though examples like #3 shows the contract as the first parameter.
                    // From IDL
                    // 1. [activatable(NTDDI_WIN8)]
                    // 2. [activatable(NTDDI_WINBLUE, Platform.WindowsPhone)]
                    // 3. [activatable(Windows.Foundation.UniversalApiContract, 1)]
                    // 4. [activatable(IVideoCompositorDefinitionFactory, Windows.Foundation.UniversalApiContract, 1)]

                    if (typeHolderInfo.Items[0].SignatureTypeCode == SignatureTypeCode.UInt32)
                    {
                        output = attribute;
                        return true;
                    }
                    else
                    {
                        continue;
                    }
                }
                else if (attributeType == CustomAttributeKind.DefaultInterface && attribute.FullTypeName == FullTypeNameConstants.Windows_Foundation_Metadata_DefaultAttribute)
                {
                    output = attribute;
                    return true;
                }
                else if (attributeType == CustomAttributeKind.Flags && attribute.FullTypeName == FullTypeNameConstants.System_FlagsAttribute)
                {
                    output = attribute;
                    return true;
                }
                else if (attributeType == CustomAttributeKind.ExclusiveTo && attribute.FullTypeName == FullTypeNameConstants.Windows_Foundation_Metadata_ExclusiveToAttribute)
                {
                    output = attribute;
                    return true;
                }
                else if (attributeType == CustomAttributeKind.Static && attribute.FullTypeName == FullTypeNameConstants.Windows_Foundation_Metadata_StaticAttribute)
                {
                    output = attribute;
                    return true;
                }
                else if (attributeType == CustomAttributeKind.Deprecated && attribute.FullTypeName == FullTypeNameConstants.Windows_Foundation_Metadata_DeprecatedAttribute)
                {
                    output = attribute;
                    return true;
                }
                else if (attributeType == CustomAttributeKind.Overload && attribute.FullTypeName == FullTypeNameConstants.Windows_Foundation_Metadata_OverloadAttribute)
                {
                    output = attribute;
                    return true;
                }
                else if (attributeType == CustomAttributeKind.Overridable && attribute.FullTypeName == FullTypeNameConstants.Windows_Foundation_Metadata_OverridableAttribute)
                {
                    output = attribute;
                    return true;
                }
                else if (attributeType == CustomAttributeKind.Protected && attribute.FullTypeName == FullTypeNameConstants.Windows_Foundation_Metadata_ProtectedAttribute)
                {
                    output = attribute;
                    return true;
                }
            }

            return false;
        }

        public static void GetGuidValue(MetadataReader assembly, CustomAttributeInfo customAttributeInfo, out Guid guid)
        {
            Debug.Assert(customAttributeInfo.Constructor.Kind == HandleKind.MemberReference);
            
            var memberReference = assembly.GetMemberReference((MemberReferenceHandle)customAttributeInfo.Constructor);

            TypeHolderInfo typeHolderInfo = null;
            CustomAttributeMetadataParser.GetDeferedCustomAttributes(assembly, memberReference.Signature, customAttributeInfo.BlobHandle, out typeHolderInfo);

            if (typeHolderInfo.Items.Count != 11)
            {
                throw new InvalidOperationException(String.Format(StringExceptionFormats.CantBuildTypeInfoFromCustomAttribute, "Guid"));
            }

            var a = (uint)MetadataParserHelpers.GetValueForSignatureTypeCode<uint>(assembly, ref typeHolderInfo.BlobReader, typeHolderInfo.Items[0].SignatureTypeCode, typeHolderInfo.Items[0].Handle);
            var b = (ushort)MetadataParserHelpers.GetValueForSignatureTypeCode<ushort>(assembly, ref typeHolderInfo.BlobReader, typeHolderInfo.Items[1].SignatureTypeCode, typeHolderInfo.Items[1].Handle);
            var c = (ushort)MetadataParserHelpers.GetValueForSignatureTypeCode<ushort>(assembly, ref typeHolderInfo.BlobReader, typeHolderInfo.Items[2].SignatureTypeCode, typeHolderInfo.Items[2].Handle);
            var d = (byte)MetadataParserHelpers.GetValueForSignatureTypeCode<byte>(assembly, ref typeHolderInfo.BlobReader, typeHolderInfo.Items[3].SignatureTypeCode, typeHolderInfo.Items[3].Handle);
            var e = (byte)MetadataParserHelpers.GetValueForSignatureTypeCode<byte>(assembly, ref typeHolderInfo.BlobReader, typeHolderInfo.Items[4].SignatureTypeCode, typeHolderInfo.Items[4].Handle);
            var f = (byte)MetadataParserHelpers.GetValueForSignatureTypeCode<byte>(assembly, ref typeHolderInfo.BlobReader, typeHolderInfo.Items[5].SignatureTypeCode, typeHolderInfo.Items[5].Handle);
            var g = (byte)MetadataParserHelpers.GetValueForSignatureTypeCode<byte>(assembly, ref typeHolderInfo.BlobReader, typeHolderInfo.Items[6].SignatureTypeCode, typeHolderInfo.Items[6].Handle);
            var h = (byte)MetadataParserHelpers.GetValueForSignatureTypeCode<byte>(assembly, ref typeHolderInfo.BlobReader, typeHolderInfo.Items[7].SignatureTypeCode, typeHolderInfo.Items[7].Handle);
            var i = (byte)MetadataParserHelpers.GetValueForSignatureTypeCode<byte>(assembly, ref typeHolderInfo.BlobReader, typeHolderInfo.Items[8].SignatureTypeCode, typeHolderInfo.Items[8].Handle);
            var j = (byte)MetadataParserHelpers.GetValueForSignatureTypeCode<byte>(assembly, ref typeHolderInfo.BlobReader, typeHolderInfo.Items[9].SignatureTypeCode, typeHolderInfo.Items[9].Handle);
            var k = (byte)MetadataParserHelpers.GetValueForSignatureTypeCode<byte>(assembly, ref typeHolderInfo.BlobReader, typeHolderInfo.Items[10].SignatureTypeCode, typeHolderInfo.Items[10].Handle);

            guid = new Guid(a, b, c, d, e, f, g, h, i, j, k);
        }

        public static void GetCompositionTypeInfo(MetadataReader assembly, CustomAttributeInfo customAttributeInfo, out CompositionTypeInfo compositionTypeInfo, out string composableInterfaceFullTypeName)
        {
            Debug.Assert(customAttributeInfo.Constructor.Kind == HandleKind.MemberReference);

            TypeHolderInfo typeHolderInfo = null;
            var compositionTypeInfoLocal = CompositionTypeInfo.Unknown;

            compositionTypeInfo = CompositionTypeInfo.Unknown;
            composableInterfaceFullTypeName = null;

            var memberReference = assembly.GetMemberReference((MemberReferenceHandle)customAttributeInfo.Constructor);
            CustomAttributeMetadataParser.GetDeferedCustomAttributes(assembly, memberReference.Signature, customAttributeInfo.BlobHandle, out typeHolderInfo);

            if (typeHolderInfo.Items.Count != 4)
            {
                throw new InvalidOperationException(String.Format(StringExceptionFormats.CantBuildTypeInfoFromCustomAttribute, "composable interface type name"));
            }

            var blobReader = assembly.GetBlobReader(customAttributeInfo.BlobHandle);
            var value1 = (string)MetadataParserHelpers.GetValueForSignatureTypeCode<string>(assembly, ref typeHolderInfo.BlobReader, typeHolderInfo.Items[0].SignatureTypeCode, typeHolderInfo.Items[0].Handle);
            var value2 = MetadataParserHelpers.GetValueForSignatureTypeCode<int>(assembly, ref typeHolderInfo.BlobReader, SignatureTypeCode.Int32, typeHolderInfo.Items[1].Handle);

            if (Enum.IsDefined(typeof(CompositionTypeInfo), value2))
            {
                compositionTypeInfoLocal = (CompositionTypeInfo)value2;
            }

            composableInterfaceFullTypeName = value1;
            compositionTypeInfo = compositionTypeInfoLocal;
            Debug.Assert(composableInterfaceFullTypeName != null);
        }

        public static void GetStaticInterface(MetadataReader assembly, CustomAttributeInfo customAttributeInfo, out string staticInterfaceFullTypeName)
        {
            TypeHolderInfo typeHolderInfo = null;

            var memberReference = assembly.GetMemberReference((MemberReferenceHandle)customAttributeInfo.Constructor);
            CustomAttributeMetadataParser.GetDeferedCustomAttributes(assembly, memberReference.Signature, customAttributeInfo.BlobHandle, out typeHolderInfo);

            if (typeHolderInfo.Items.Count != 3)
            {
                throw new InvalidOperationException(String.Format(StringExceptionFormats.CantBuildTypeInfoFromCustomAttribute, "static interface type name"));
            }
            
            var value1 = (string)MetadataParserHelpers.GetValueForSignatureTypeCode<string>(assembly, ref typeHolderInfo.BlobReader, typeHolderInfo.Items[0].SignatureTypeCode, typeHolderInfo.Items[0].Handle);

            staticInterfaceFullTypeName = value1;
        }

        public static void GetOverloadName(MetadataReader assembly, CustomAttributeInfo customAttributeInfo, out string overloadName)
        {
            TypeHolderInfo typeHolderInfo = null;

            var memberReference = assembly.GetMemberReference((MemberReferenceHandle)customAttributeInfo.Constructor);
            CustomAttributeMetadataParser.GetDeferedCustomAttributes(assembly, memberReference.Signature, customAttributeInfo.BlobHandle, out typeHolderInfo);

            if (typeHolderInfo.Items.Count != 1)
            {
                throw new InvalidOperationException(String.Format(StringExceptionFormats.CantBuildTypeInfoFromCustomAttribute, "function overload name"));
            }

            var value1 = (string)MetadataParserHelpers.GetValueForSignatureTypeCode<string>(assembly, ref typeHolderInfo.BlobReader, typeHolderInfo.Items[0].SignatureTypeCode, typeHolderInfo.Items[0].Handle);

            overloadName = value1;
        }

        public static void GetActivatableInterface(MetadataReader assembly, CustomAttributeInfo customAttributeInfo, out string activatableInterfaceFullTypeName)
        {
            activatableInterfaceFullTypeName = null;

            TypeHolderInfo typeHolderInfo = null;
            string value = null;

            var memberReference = assembly.GetMemberReference((MemberReferenceHandle)customAttributeInfo.Constructor);
            CustomAttributeMetadataParser.GetDeferedCustomAttributes(assembly, memberReference.Signature, customAttributeInfo.BlobHandle, out typeHolderInfo);

            if (typeHolderInfo.Items.Count < 2 && typeHolderInfo.Items.Count > 3)
            {
                throw new InvalidOperationException(String.Format(StringExceptionFormats.CantBuildTypeInfoFromCustomAttribute, "activatable interface type name"));
            }
            
            if (typeHolderInfo.Items.Count == 3)
            {
                value = Convert.ToString(MetadataParserHelpers.GetValueForSignatureTypeCode<string>(assembly, ref typeHolderInfo.BlobReader, typeHolderInfo.Items[0].SignatureTypeCode, typeHolderInfo.Items[0].Handle));
            }
            
            activatableInterfaceFullTypeName = value;
        }

        private static void GetDeferedCustomAttributes(MetadataReader assembly, BlobHandle signatureBlobHandle, BlobHandle blobHandle, out TypeHolderInfo typeHolderInfo)
        {
            typeHolderInfo = null;

            if (blobHandle.IsNil)
            {
                Debugger.Break();
                return;
            }

            var typeHolderInfoLocal = new TypeHolderInfo();
            typeHolderInfoLocal.Items = new List<TypeHolderInfoItem>();

            // .ctor method signature
            var sigReader = assembly.GetBlobReader(signatureBlobHandle);

            // Blob containing the parameter values to pass to the above .ctor method
            var blobReader = assembly.GetBlobReader(blobHandle);

            // Read the blob prolog and validate it
            var prolog = blobReader.ReadInt16();
            Debug.Assert(prolog == 1);

            // Start processing the .ctor method signature to identify the types of the method's parameters
            // We can't read the values from the parameter blob until we know the type of each parameter
            var sigHeader = sigReader.ReadSignatureHeader();

            // When calling convention is GENERIC, read the generic param count
            if (sigHeader.IsGeneric)
            {
                sigReader.ReadCompressedInteger();
            }

            // Read the param count
            var paramCount = sigReader.ReadCompressedInteger();

            // Read the return type
            var returnSignatureTypeCode = sigReader.ReadSignatureTypeCode();

            for (var count = 0; count < paramCount; count++)
            {
                var typeHolderinfoItem = new TypeHolderInfoItem();
                typeHolderinfoItem.SignatureTypeCode = sigReader.ReadSignatureTypeCode();

                if (typeHolderinfoItem.SignatureTypeCode == SignatureTypeCode.TypeHandle)
                {
                    typeHolderinfoItem.Handle = sigReader.ReadTypeHandle();
                }

                typeHolderInfoLocal.Items.Add(typeHolderinfoItem);
            }

            typeHolderInfoLocal.BlobReader = blobReader;
            typeHolderInfo = typeHolderInfoLocal;
        }
    }
}
