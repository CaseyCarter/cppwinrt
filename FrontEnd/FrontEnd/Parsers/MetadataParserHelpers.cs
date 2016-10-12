using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Reflection.Metadata;
using System.Text;

namespace Microsoft.Wcl.Parsers
{
    internal static class MetadataParserHelpers
    {
        public static event EventHandler<ParameterizedTypeInstanceParsedEventArgs> ParameterizedTypeInstanceParsed;

        public static string GetFullTypeNameFromMetadata(MetadataReader assembly, ref BlobReader sigReader, SignatureTypeCode sigTypeCode)
        {
            switch (sigTypeCode)
            {
                case SignatureTypeCode.Object:
                    return "Object";

                case SignatureTypeCode.Void:
                    return "void";

                case SignatureTypeCode.Int16:
                    return "Int16";

                case SignatureTypeCode.Int32:
                    return "Int32";

                case SignatureTypeCode.Int64:
                    return "Int64";

                case SignatureTypeCode.Byte:
                    return "UInt8";

                case SignatureTypeCode.UInt16:
                    return "UInt16";

                case SignatureTypeCode.UInt32:
                    return "UInt32";

                case SignatureTypeCode.UInt64:
                    return "UInt64";

                case SignatureTypeCode.String:
                    return "String";

                case SignatureTypeCode.Boolean:
                    return "Boolean";

                case SignatureTypeCode.Char:
                    return "Char16";

                case SignatureTypeCode.Double:
                    return "Double";

                case SignatureTypeCode.Single:
                    return "Single";

                case SignatureTypeCode.TypeHandle:
                    var typeHandle = sigReader.ReadTypeHandle();

                    return GetFullTypeNameFromMetadata(assembly, typeHandle);

                case SignatureTypeCode.GenericTypeInstance:
                    var genericTypeCode = sigReader.ReadSignatureTypeCode();
                    var genericTypeHandle = sigReader.ReadTypeHandle();
                    var genericArgCount = sigReader.ReadCompressedInteger();

                    var genericFullTypeNameBuilder = new StringBuilder();

                    var openInterfaceFullTypeName = GetFullTypeNameFromMetadata(assembly, genericTypeHandle);
                    genericFullTypeNameBuilder.AppendFormat("{0}<", openInterfaceFullTypeName);

                    for (int i = 0; i < genericArgCount; i++)
                    {
                        var argumentSignatureTypeHandle = sigReader.ReadSignatureTypeCode();
                        var argumentFullTypeName = GetFullTypeNameFromMetadata(assembly, ref sigReader, argumentSignatureTypeHandle);
                        genericFullTypeNameBuilder.AppendFormat("{0}, ", argumentFullTypeName);
                    }

                    // Get rid of the last comma
                    genericFullTypeNameBuilder.Length = genericFullTypeNameBuilder.Length - 2;
                    genericFullTypeNameBuilder.Append(">");

                    var genericFullTypeName = genericFullTypeNameBuilder.ToString();
                    if (MetadataParserHelpers.ParameterizedTypeInstanceParsed != null)
                    {
                        MetadataParserHelpers.ParameterizedTypeInstanceParsed(null, new ParameterizedTypeInstanceParsedEventArgs(openInterfaceFullTypeName, genericFullTypeName));
                    }
                    return genericFullTypeName;

                case SignatureTypeCode.SZArray:
                    {
                        var arrayTypeCode = sigReader.ReadSignatureTypeCode();

                        // Read the custom modifiers and ignore them
                        var modifiers = ReadCustomMods(assembly, ref sigReader, ref sigTypeCode);

                        var arrayType = GetFullTypeNameFromMetadata(assembly, ref sigReader, arrayTypeCode);
                        return arrayType;
                    }

                case SignatureTypeCode.GenericTypeParameter:
                    {
                        var genericTypeParameterNumber = sigReader.ReadCompressedInteger();
                        return String.Format(StringFormats.OpenTypeFormat, genericTypeParameterNumber);
                    }
                default:
                    throw new NotImplementedException();
            }

            throw new NotImplementedException();
        }

        public static string GetFullTypeNameFromMetadata(MetadataReader assembly, EntityHandle entityHandle)
        {
            string typeNamespaceName = null;
            string typeName = null;

            switch (entityHandle.Kind)
            {
                case HandleKind.TypeDefinition:
                    TypeDefinition typeDef = assembly.GetTypeDefinition((TypeDefinitionHandle)entityHandle);
                    typeNamespaceName = assembly.GetString(typeDef.Namespace);
                    typeName = assembly.GetString(typeDef.Name);

                    // Guid is a special case
                    if (typeName == "Guid" && typeNamespaceName == "System")
                    {
                        return typeName;
                    }
                    else
                    {
                        return TypeNameUtilities.GetFormattedFullTypeName(typeNamespaceName, typeName);
                    }

                case HandleKind.TypeReference:
                    TypeReference typeRef = assembly.GetTypeReference((TypeReferenceHandle)entityHandle);
                    typeNamespaceName = assembly.GetString(typeRef.Namespace);
                    typeName = assembly.GetString(typeRef.Name);

                    // Guid is a special case
                    if (typeName == "Guid" && typeNamespaceName == "System")
                    {
                        return typeName;
                    }
                    else
                    {
                        return TypeNameUtilities.GetFormattedFullTypeName(typeNamespaceName, typeName);
                    }

                case HandleKind.MemberReference:

                    MemberReference memberRef = assembly.GetMemberReference((MemberReferenceHandle)entityHandle);

                    return GetFullTypeNameFromMetadata(assembly, memberRef.Parent);

                case HandleKind.TypeSpecification:
                    TypeSpecification typeSpec = assembly.GetTypeSpecification((TypeSpecificationHandle)entityHandle);
                    var someBytes = assembly.GetBlobBytes(typeSpec.Signature);
                    var blobReader = assembly.GetBlobReader(typeSpec.Signature);

                    var typeCode = blobReader.ReadSignatureTypeCode();
                    return GetFullTypeNameFromMetadata(assembly, ref blobReader, typeCode);

                default:
                    throw new NotImplementedException();
            }
        }

        public static IList<TypeModifier> ReadCustomMods(MetadataReader assembly, ref BlobReader sigReader, ref SignatureTypeCode sigTypeCode)
        {
            var list = new List<TypeModifier>();

            while(sigTypeCode == SignatureTypeCode.RequiredModifier || sigTypeCode == SignatureTypeCode.OptionalModifier)
            {
                // Read the type and then proceed with the next one until done.
                var typeHandle = sigReader.ReadTypeHandle();
                Debug.Assert(typeHandle.Kind == HandleKind.TypeDefinition || typeHandle.Kind == HandleKind.TypeReference || typeHandle.Kind == HandleKind.TypeSpecification);
                var typeFullTypeName = MetadataParserHelpers.GetFullTypeNameFromMetadata(assembly, typeHandle);

                var modifier = new TypeModifier();
                modifier.TypeCode = sigTypeCode;
                modifier.FullTypeName = typeFullTypeName;
                list.Add(modifier);

                sigTypeCode = sigReader.ReadSignatureTypeCode();
            }

            return list;
        }

        public static TypeDefinitionKind GetTypeDefinitionKind(MetadataReader assembly, TypeDefinition typeDef)
        {
            if ((typeDef.Attributes & System.Reflection.TypeAttributes.Interface) == System.Reflection.TypeAttributes.Interface)
            {
                return TypeDefinitionKind.Interface;
            }
            else
            {
                var parentFullTypeName = GetFullTypeNameFromMetadata(assembly, typeDef.BaseType);

                switch (parentFullTypeName)
                {
                    case FullTypeNameConstants.System_Enum:
                        return TypeDefinitionKind.Enum;
                        
                    case FullTypeNameConstants.System_Value:
                        return TypeDefinitionKind.Struct;
                        
                    case FullTypeNameConstants.System_Attribute:
                        return TypeDefinitionKind.Attribute;
                        
                    case FullTypeNameConstants.System_MulticastDelegate:
                        return TypeDefinitionKind.Delegate;
                        
                    default:
                        return TypeDefinitionKind.RuntimeClass;
                }
            }
        }

        public static object GetValueForSignatureTypeCode<T>(MetadataReader assembly, ref BlobReader attributeBlobReader, SignatureTypeCode signatureTypeCode, EntityHandle typeHandle)
        {
            object value = null;

            switch (signatureTypeCode)
            {
                case SignatureTypeCode.Boolean:

                    value = attributeBlobReader.ReadBoolean();
                    break;

                case SignatureTypeCode.SByte:
                    value = attributeBlobReader.ReadSByte();
                    break;

                case SignatureTypeCode.Char:
                    value = attributeBlobReader.ReadChar();
                    break;

                case SignatureTypeCode.Int16:
                    value = attributeBlobReader.ReadInt16();
                    break;

                case SignatureTypeCode.Int32:
                    value = attributeBlobReader.ReadInt32();
                    break;

                case SignatureTypeCode.Int64:
                    value = attributeBlobReader.ReadInt64();
                    break;

                case SignatureTypeCode.Byte:
                    value = attributeBlobReader.ReadByte();
                    break;

                case SignatureTypeCode.UInt16:
                    value = attributeBlobReader.ReadUInt16();
                    break;

                case SignatureTypeCode.UInt32:
                    value = attributeBlobReader.ReadUInt32();
                    break;

                case SignatureTypeCode.UInt64:
                    value = attributeBlobReader.ReadUInt64();
                    break;

                case SignatureTypeCode.Single:
                    value = attributeBlobReader.ReadSingle();
                    break;

                case SignatureTypeCode.Double:
                    value = attributeBlobReader.ReadDouble();
                    break;

                case SignatureTypeCode.String:
                    value = attributeBlobReader.ReadSerializedString();
                    break;

                case SignatureTypeCode.TypeHandle:
                    value = TypeNameUtilities.GetFullTypeNameInCPPForm((string)GetValueForSignatureTypeCode<string>(assembly, ref attributeBlobReader, SignatureTypeCode.String, typeHandle));
                    break;

                case SignatureTypeCode.TypedReference:

                    value = attributeBlobReader.ReadSerializedString();
                    break;

                default:
                    throw new NotImplementedException();
            }

            if (!(value is T))
            {
                throw new InvalidOperationException();
            }

            return value;
        }

        public static object GetValueForConstantTypeCode<T>(MetadataReader assembly, ref BlobReader blobReader, ConstantTypeCode constantTypeCode)
        {
            object value = null;

            switch (constantTypeCode)
            {
                case ConstantTypeCode.Boolean:

                    value = blobReader.ReadBoolean();
                    break;

                case ConstantTypeCode.SByte:
                    value = blobReader.ReadSByte();
                    break;

                case ConstantTypeCode.Char:
                    value = blobReader.ReadChar();
                    break;

                case ConstantTypeCode.Int16:
                    value = blobReader.ReadInt16();
                    break;

                case ConstantTypeCode.Int32:
                    value = blobReader.ReadInt32();
                    break;

                case ConstantTypeCode.Int64:
                    value = blobReader.ReadInt64();
                    break;

                case ConstantTypeCode.Byte:
                    value = blobReader.ReadByte();
                    break;

                case ConstantTypeCode.UInt16:
                    value = blobReader.ReadUInt16();
                    break;

                case ConstantTypeCode.UInt32:
                    value = blobReader.ReadUInt32();
                    break;

                case ConstantTypeCode.UInt64:
                    value = blobReader.ReadUInt64();
                    break;

                case ConstantTypeCode.Single:
                    value = blobReader.ReadSingle();
                    break;

                case ConstantTypeCode.Double:
                    value = blobReader.ReadDouble();
                    break;

                case ConstantTypeCode.String:
                    value = blobReader.ReadSerializedString();
                    break;
                default:
                    throw new NotImplementedException();
            }

            if (!(value is T))
            {
                throw new InvalidOperationException();
            }

            return value;
        }
    }
}
