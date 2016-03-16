using System.Collections.Generic;
using System.Diagnostics;
using System.Reflection.Metadata;

using Microsoft.Wcl.DataStore;

namespace Microsoft.Wcl.Parsers
{
    internal class StructMetadataParser
    {
        public void Initialize(FrontEndConfiguration configuration)
        {
            this.Configuration = configuration;
        }

        public StructInfo Parse(MetadataReader assembly, TypeDefinition typeDef)
        {
            var info = new StructInfo();
            int depends = 0;
            info.FieldsInfo = new List<StructFieldInfo>();

            var namespaceName = assembly.GetString(typeDef.Namespace);
            var typeName = assembly.GetString(typeDef.Name);
            var customAttributes = CustomAttributeMetadataParser.GetAttributes(assembly, typeDef.GetCustomAttributes());

            info.FullName = TypeNameUtilities.GetFormattedFullTypeName(namespaceName, typeName);
            info.Name = TypeNameUtilities.GetIndexOfTypeName(info.FullName);
            info.Deprecated = CustomAttributeMetadataParser.FindAttribute(assembly, customAttributes, CustomAttributeKind.Deprecated);
            info.FieldsInfo = GetStructFieldsInfo(assembly, typeDef, info.FullName, out depends);
            info.Depends = depends;

            return info;
        }

        private List<StructFieldInfo> GetStructFieldsInfo(MetadataReader assembly, TypeDefinition typeDef, string structFullTypeName, out int depends)
        {
            var list = new List<StructFieldInfo>();
            depends = 0;
            int localDepends = 0;

            foreach (var fieldHandle in typeDef.GetFields())
            {
                var field = assembly.GetFieldDefinition(fieldHandle);
                var fieldName = assembly.GetString(field.Name);
                
                var blobReader = assembly.GetBlobReader(field.Signature);
                var signatureTypeHeader = blobReader.ReadSignatureHeader();
                Debug.Assert(signatureTypeHeader.Kind == SignatureKind.Field);
                var signatureTypeCode = blobReader.ReadSignatureTypeCode();
                var fullTypeName = MetadataParserHelpers.GetFullTypeNameFromMetadata(assembly, ref blobReader, signatureTypeCode);

                if (fullTypeName.Contains(":"))
                {
                    localDepends++;
                }

                var fieldInfo = new StructFieldInfo();
                fieldInfo.Name = fieldName;
                fieldInfo.Type = fullTypeName;
                fieldInfo.StructFullTypeName = structFullTypeName;

                list.Add(fieldInfo);
            }

            depends = localDepends;
            return list;
        }

        private FrontEndConfiguration Configuration { get; set; }
    }
}
