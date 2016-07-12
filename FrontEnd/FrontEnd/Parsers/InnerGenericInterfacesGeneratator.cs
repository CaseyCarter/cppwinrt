using Microsoft.Wcl.DataStore;
using Microsoft.Wcl.ParameterizedTypeInstanceIID;
using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Microsoft.Wcl.Parsers
{
    class InnerGenericInterfacesGeneratator
    {
        static public List<GenericInterfaceInfo> GenerateInnerGenericInterface(GenericInterfaceInfo info)
        {
            var outputList = new List<GenericInterfaceInfo>();
            var genericType = MetadataGenericInterfaceParser.Parse(info.MetadataFullTypeNameInCppForm);

            List<GenericType> list = new List<GenericType>();
            ProcessGenericType(genericType, list);

            foreach (var innerGenericType in list)
            {
                var nameIndex = TypeNameUtilities.GetIndexOfTypeNameForGenericInterface(innerGenericType.FullTypeName);

                GenericInterfaceInfo newInfo = new GenericInterfaceInfo()
                {
                    FullName = innerGenericType.FullTypeName,
                    Namespace = innerGenericType.FullTypeName.Substring(0, nameIndex),
                    Name = innerGenericType.FullTypeName.Substring(nameIndex + 2),
                    MetadataFullTypeNameInDotForm = TypeNameUtilities.GetFullTypeNameInDotForm(innerGenericType.FullTypeName),
                    MetadataFullTypeNameInCppForm = innerGenericType.FullTypeName,
                    Depth = GenericInterfaceParser.GetGenericInterfaceDepthness(innerGenericType.FullTypeName)
                };

                outputList.Add(newInfo);
            }

            return outputList;
        }

        static private void ProcessGenericType(GenericType genericType, List<GenericType> list)
        {
            foreach (var item in genericType.Arguments)
            {
                if (item is GenericType)
                {
                    list.Add((GenericType)item);
                    ProcessGenericType((GenericType)item, list);
                }
            }
        }

        static class MetadataGenericInterfaceParser
        {
            static public GenericType Parse(string metadataFullTypeName)
            {
                // Encounter open type. Skip
                if (metadataFullTypeName.Contains("!!")) return null;

                var parts = TypeNameParser.GetParts(metadataFullTypeName);
                int innerIndex = 0;

                return GetTypesFromGenericType(parts, 0, ref innerIndex);
            }

            static private GenericType GetTypesFromGenericType(string[] parts, int startIndex, ref int innerIndex)
            {
                var arguments = new List<object>();

                Debug.Assert(GenericInterfaceParser.IsOpenInterface(parts[startIndex]));
                uint argumentCount = GenericInterfaceParser.GetGenericInterfaceArgumentCount(parts[startIndex]);

                var openTypeName = parts[startIndex];
                startIndex++;
                innerIndex++;
                int offset = 0;

                for (int j = 0; j < argumentCount; j++, innerIndex++)
                {
                    int index = j + startIndex + offset;

                    if (GenericInterfaceParser.IsOpenInterface(parts[index]))
                    {
                        var innerGenericType = GetTypesFromGenericType(parts, index, ref innerIndex);
                        arguments.Add(innerGenericType);
                        offset = innerIndex - startIndex - 1;
                    }
                    else
                    {
                        arguments.Add(parts[index]);
                    }
                }

                var genericType = new GenericType(openTypeName, arguments);
                return genericType;
            }
        }

        class GenericType
        {
            public GenericType(string openType, IReadOnlyList<object> arguments)
            {
                this.OpenType = openType;
                this.Arguments = arguments;

                this.FullTypeName = GetFullTypeName();
            }

            public string OpenType { get; private set; }
            public IReadOnlyList<object> Arguments { get; private set; }
            public string FullTypeName { get; private set; }

            private string GetFullTypeName()
            {
                StringBuilder builder = new StringBuilder();

                builder.Append(this.OpenType);
                builder.Append("<");

                foreach (var parameter in this.Arguments)
                {
                    if (parameter is string)
                    {
                        builder.Append((string)parameter);
                    }
                    else if (parameter is GenericType)
                    {
                        builder.Append(((GenericType)parameter).FullTypeName);
                    }

                    builder.Append(", ");
                }

                builder.Length -= 2;
                builder.Append(">");

                return builder.ToString();
            }
        }
    }
}
