using System;
using System.Collections.Generic;
using System.Reflection.Metadata;

using Microsoft.Wcl.DataStore;

namespace Microsoft.Wcl.Parsers
{
    internal class EnumMetadataParser
    {
        public void Initialize(FrontEndConfiguration configuration)
        {
            this.Configuration = configuration;
        }

        public EnumInfo Parse(MetadataReader assembly, TypeDefinition typeDef)
        {
            var info = new EnumInfo();

            var namespaceName = assembly.GetString(typeDef.Namespace);
            var typeName = assembly.GetString(typeDef.Name);
            var fullTypeName = TypeNameUtilities.GetFormattedFullTypeName(namespaceName, typeName);
            var customAttributeList = CustomAttributeMetadataParser.GetAttributes(assembly, typeDef); 

            info.FullName = TypeNameUtilities.GetFormattedFullTypeName(namespaceName, typeName);
            var nameIndex = TypeNameUtilities.GetIndexOfTypeName(info.FullName);
            info.Namespace = info.FullName.Substring(0, nameIndex);
            info.Name = info.FullName.Substring(nameIndex + 2);

            info.Flags = CustomAttributeMetadataParser.FindAttribute(assembly, customAttributeList, CustomAttributeKind.Flags); ;
            info.Deprecated = CustomAttributeMetadataParser.FindAttribute(assembly, customAttributeList, CustomAttributeKind.Deprecated);
            info.FieldNames = this.GetFieldsNames(assembly, typeDef.GetFields(), fullTypeName);

            return info;
        }

        private IList<EnumFieldInfo> GetFieldsNames(MetadataReader assembly, FieldDefinitionHandleCollection fieldDefinitionHandleCollection, string enumFullTypeName)
        {
            var fields = new List<EnumFieldInfo>();

            foreach (var fieldHandle in fieldDefinitionHandleCollection)
            {
                var fieldDef = assembly.GetFieldDefinition(fieldHandle);

                if ((fieldDef.Attributes & System.Reflection.FieldAttributes.Literal) != System.Reflection.FieldAttributes.Literal)
                {
                    continue;
                }

                var fieldName = assembly.GetString(fieldDef.Name);
                var customAttributes = CustomAttributeMetadataParser.GetAttributes(assembly, fieldDef.GetCustomAttributes());

                var constantHandle = fieldDef.GetDefaultValue();
                var constant = assembly.GetConstant(constantHandle);
                var blobReader = assembly.GetBlobReader(constant.Value);

                // Type of the Field could be Int32 or uint. Box it.
                object value = null;
                switch (constant.TypeCode)
                {
                    case ConstantTypeCode.Int32:
                        value = MetadataParserHelpers.GetValueForConstantTypeCode<Int32>(assembly, ref blobReader, constant.TypeCode);
                        break;
                    case ConstantTypeCode.UInt32:
                        value = MetadataParserHelpers.GetValueForConstantTypeCode<uint>(assembly, ref blobReader, constant.TypeCode);
                        break;
                    default:
                        throw new InvalidOperationException(String.Format(StringExceptionFormats.InvalidTypeValueForEnumField, enumFullTypeName));
                }

                var info = new EnumFieldInfo();
                info.Name = fieldName;
                info.Value = value;
                info.EnumerationFullTypeName = enumFullTypeName;
                info.Deprecated = CustomAttributeMetadataParser.FindAttribute(assembly, customAttributes, CustomAttributeKind.Deprecated);

                fields.Add(info);
            }

            return fields;
        }

        private FrontEndConfiguration Configuration { get; set; }
    }
}
