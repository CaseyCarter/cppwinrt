using Microsoft.Wcl.DataStore;
using Microsoft.Wcl.ParameterizedTypeInstanceIID;
using Microsoft.Wcl.Parsers;
using System;
using System.Collections.Generic;
using System.Text;

namespace Microsoft.Wcl.Projection
{
    internal class ProjectedTypeInfo
    {
        public string ProjectedType;
        public TypeCategory TypeCategory;
    }

    internal static class MetadataTypeToProjectedTypeConverter
    {
        static IDictionary<string, ProjectedTypeInfo> MetadataTypeToProjectedTypeTable = new Dictionary<string, ProjectedTypeInfo>()
        {
                { "Object", new ProjectedTypeInfo() { ProjectedType = "Windows::IInspectable", TypeCategory = TypeCategory.Interface } },
                { "Int16", new ProjectedTypeInfo() { ProjectedType = "int16_t", TypeCategory = TypeCategory.Value } },
                { "Int32", new ProjectedTypeInfo() { ProjectedType = "int32_t", TypeCategory = TypeCategory.Value } },
                { "Int64", new ProjectedTypeInfo() { ProjectedType = "int64_t", TypeCategory = TypeCategory.Value } },
                { "UInt8", new ProjectedTypeInfo() { ProjectedType = "uint8_t", TypeCategory = TypeCategory.Value } },
                { "UInt16", new ProjectedTypeInfo() { ProjectedType = "uint16_t", TypeCategory = TypeCategory.Value } },
                { "UInt32", new ProjectedTypeInfo() { ProjectedType = "uint32_t", TypeCategory = TypeCategory.Value } },
                { "UInt64", new ProjectedTypeInfo() { ProjectedType = "uint64_t", TypeCategory = TypeCategory.Value } },
                { "String", new ProjectedTypeInfo() { ProjectedType = "hstring", TypeCategory = TypeCategory.String } },
                { "Boolean", new ProjectedTypeInfo() { ProjectedType = "bool", TypeCategory = TypeCategory.Value } },
                { "Char16", new ProjectedTypeInfo() { ProjectedType = "wchar_t", TypeCategory = TypeCategory.Value } },
                { "Double", new ProjectedTypeInfo() { ProjectedType = "double", TypeCategory = TypeCategory.Value } },
                { "Single", new ProjectedTypeInfo() { ProjectedType = "float", TypeCategory = TypeCategory.Value } },
                { "Guid", new ProjectedTypeInfo() { ProjectedType = "GUID", TypeCategory = TypeCategory.Value } },
                { FullTypeNameConstants.Windows_Foundation_AsyncStatus, new ProjectedTypeInfo() { ProjectedType = "Windows::AsyncStatus", TypeCategory = TypeCategory.Enumeration} },
                { FullTypeNameConstants.Windows_Foundation_EventRegistrationToken, new ProjectedTypeInfo() { ProjectedType = "event_token", TypeCategory = TypeCategory.Value } },
                { FullTypeNameConstants.Windows_Foundation_HResult, new ProjectedTypeInfo() { ProjectedType = "HRESULT", TypeCategory = TypeCategory.Value } },
                { "AsyncStatus", new ProjectedTypeInfo() { ProjectedType = "Windows::AsyncStatus", TypeCategory = TypeCategory.Enumeration } },
        };

        public static string GetProjectedTypeFromMetadataType(string metadataType, bool isGenericInterfaceArgument, IDictionary<string, object> repository)
        {
            TypeCategory typeCategory;
            string projectedType = null;

            GetProjectedTypeAndCategoryFromMetadataType(metadataType, isGenericInterfaceArgument, repository, out projectedType, out typeCategory);

            return projectedType;
        }

        public static void GetProjectedTypeAndCategoryFromMetadataType(string metadataType, bool isGenericInterfaceArgument, IDictionary<string, object> repository, out string projectedType, out TypeCategory typeCategory)
        {
            string projectedClassType = null;
            GetProjectedTypeAndCategoryFromMetadataType(metadataType, isGenericInterfaceArgument, repository, out projectedType, out typeCategory, out projectedClassType);
        }

        public static void GetProjectedTypeAndCategoryFromMetadataType(string metadataType, bool isGenericInterfaceArgument, IDictionary<string, object> repository, out string projectedType, out TypeCategory typeCategory, out string projectedRuntimeClassType)
        {
            ProjectedTypeInfo projectedTypeInfo = null;
            projectedType = null;
            typeCategory = TypeCategory.Unknown;
            projectedRuntimeClassType = null;

            // Fundamental types from metadata
            if (MetadataTypeToProjectedTypeConverter.MetadataTypeToProjectedTypeTable.TryGetValue(metadataType, out projectedTypeInfo))
            {
                projectedType = projectedTypeInfo.ProjectedType;
                typeCategory = projectedTypeInfo.TypeCategory;
                return;
            }

            // Apply special rules to types when they are an argument in a generic interface
            if (isGenericInterfaceArgument)
            {
                projectedType = GetProjectedTypeFromMetadataTypeForGenericArgument(metadataType, repository);
                // Type category is not determined by the generic argument.
                typeCategory = TypeCategory.Unknown;
                return;
            }

            // Look in the repository
            object infoObj = null;
            var fullTypeNameInDotForm = TypeNameUtilities.GetFullTypeNameInDotForm(metadataType);

            if (repository.TryGetValue(fullTypeNameInDotForm, out infoObj))
            {
                var typeKind = InfoObjectTypeDefinition.GetInfoObjectTypeKind(infoObj, metadataType);

                switch (typeKind)
                {
                    case TypeDefinitionKind.RuntimeClass:
                        var rInfo = (RuntimeClassInfo)infoObj;
                        if (GenericInterfaceParser.IsGenericInterface(rInfo.DefaultInterface))
                        {
                            projectedType = GetProjectedGenericTypeFromMetadataType(rInfo.DefaultInterface, repository);
                            typeCategory = TypeCategory.Interface;
                        }
                        else
                        {
                            projectedType = rInfo.DefaultInterface;
                            typeCategory = TypeCategory.Interface;
                        }

                        projectedRuntimeClassType = metadataType;

                        return;

                    case TypeDefinitionKind.Interface:
                        projectedType = metadataType;
                        typeCategory = TypeCategory.Interface;
                        return;

                    case TypeDefinitionKind.Delegate:
                        var dInfo = (InterfaceInfo)infoObj;
                        projectedType = dInfo.FullName;
                        typeCategory = TypeCategory.Delegate;

                        return;

                    case TypeDefinitionKind.Struct:
                        projectedType = metadataType;
                        typeCategory = TypeCategory.Structure;

                        return;

                    case TypeDefinitionKind.Enum:
                        projectedType = metadataType;
                        typeCategory = TypeCategory.Enumeration;
                        return;

                    default:
                        throw new NotImplementedException(String.Format(StringExceptionFormats.InvalidRepositoryTypeKind, metadataType));
                }
            }

            // Deal with some special kind of delegates
            // Search for the open type and see if it is a delegate
            string openInterfaceFullTypeName = null;
            if (GenericInterfaceParser.TryGetOpenInterface(metadataType, out openInterfaceFullTypeName))
            {
                var openInterfaceFulNameInDotForm = TypeNameUtilities.GetFullTypeNameInDotForm(openInterfaceFullTypeName);

                if (repository.TryGetValue(openInterfaceFulNameInDotForm, out infoObj) && InfoObjectTypeDefinition.GetInfoObjectTypeKind(infoObj, metadataType) == TypeDefinitionKind.Delegate)
                {
                    projectedType = GetProjectedGenericTypeFromMetadataType(metadataType, repository);
                    typeCategory = TypeCategory.Delegate;
                    return;
                }
            }

            // Last resource, is the projected type a generic interface?
            if (GenericInterfaceParser.IsGenericInterface(metadataType))
            {
                projectedType = GetProjectedGenericTypeFromMetadataType(metadataType, repository);
                typeCategory = TypeCategory.Interface;
                return;
            }

            throw new InvalidOperationException(String.Format(StringExceptionFormats.CouldNotDeriveProjectedType, metadataType, "Invalid"));
        }

        private static string GetProjectedGenericTypeFromMetadataType(string metadataType, IDictionary<string, object> repository)
        {
            StringBuilder builder = new StringBuilder();
            GetProjectedGenericTypeFromMetadataTypeHelper(metadataType, builder, repository);
            return builder.ToString();
        }

        private static void GetProjectedGenericTypeFromMetadataTypeHelper(string metadataType, StringBuilder builder, IDictionary<string, object> repository)
        {
            var parts = TypeNameParser.GetParts(metadataType);
            int index = 0;
            GetProjectedGenericTypeFromMetadataTypeHelper(parts, ref index, builder, repository);
        }

        private static void GetProjectedGenericTypeFromMetadataTypeHelper(string[] parts, ref int index, StringBuilder builder, IDictionary<string, object> repository)
        {
            var part = parts[index];
            string projectedInterfaceFullTypeName = GetProjectedTypeFromMetadataType(part, false, repository);

            uint argumentCount = 0;
            if (GenericInterfaceParser.TryGetGenericInterfaceArgumentCount(projectedInterfaceFullTypeName, out argumentCount))
            {
                string openInterfaceFullTypeName;
                if (GenericInterfaceParser.TryGetOpenInterfaceFullTypeNameWithoutArgumentCount(projectedInterfaceFullTypeName, out openInterfaceFullTypeName))
                {
                    builder.Append(openInterfaceFullTypeName);
                    builder.Append("<");
                    for (int i = 0; i < argumentCount; i++)
                    {
                        // Nested generic interfaces.
                        if (GenericInterfaceParser.IsOpenInterface(parts[(int)(index + i + 1)]))
                        {
                            index += (i + 1);
                            GetProjectedGenericTypeFromMetadataTypeHelper(parts, ref index, builder, repository);
                        }
                        else
                        {
                            var projectedArgumentType = MetadataTypeToProjectedTypeConverter.GetProjectedTypeFromMetadataType(parts[index + i + 1], true, repository);
                            builder.Append(projectedArgumentType);
                        }

                        builder.Append(", ");
                    }

                    builder.Length = builder.Length - 2;
                    builder.Append(">");
                }
                else
                {
                    throw new InvalidOperationException(String.Format(StringExceptionFormats.CouldNotDeriveProjectedType, part, "Invalid Open Interface"));
                }
            }
            else
            {
                throw new InvalidOperationException(String.Format(StringExceptionFormats.CouldNotDeriveProjectedType, part, "Invalid argument count"));
            }
        }

        private static string GetProjectedTypeFromMetadataTypeForGenericArgument(string metadataType, IDictionary<string, object> repository)
        {
            object infoObj = null;
            var fullTypeNameInDotForm = TypeNameUtilities.GetFullTypeNameInDotForm(metadataType);

            if (repository.TryGetValue(fullTypeNameInDotForm, out infoObj))
            {
                var typeKind = InfoObjectTypeDefinition.GetInfoObjectTypeKind(infoObj, metadataType);

                switch (typeKind)
                {
                    case TypeDefinitionKind.RuntimeClass:
                        return metadataType;
                        
                    case TypeDefinitionKind.Interface:
                        return metadataType;
                        
                    case TypeDefinitionKind.Delegate:
                        return metadataType;
                        
                    case TypeDefinitionKind.Struct:
                        return metadataType;

                    case TypeDefinitionKind.Enum:
                        return String.Format(StringFormats.ProjectedTypeInWinRTNamespace, metadataType);
                        
                    default:
                        throw new NotImplementedException(String.Format(StringExceptionFormats.InvalidRepositoryTypeKind, metadataType));
                }
            }

            throw new InvalidOperationException(String.Format(StringExceptionFormats.CouldNotDeriveProjectedType, metadataType, "Not found"));
        }
    }
}
