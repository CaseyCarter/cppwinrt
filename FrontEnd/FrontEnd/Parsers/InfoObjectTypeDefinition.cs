using Microsoft.Wcl.DataStore;
using System;

namespace Microsoft.Wcl.Parsers
{
    internal enum TypeDefinitionKind
    {
        RuntimeClass,
        Enum,
        Interface,
        Struct,
        Attribute,
        Delegate,
        GenericInterface
    }

    internal static class InfoObjectTypeDefinition
    {
        public static TypeDefinitionKind GetInfoObjectTypeKind(object obj, string typeName)
        {
            if (obj is RuntimeClassInfo)
            {
                return TypeDefinitionKind.RuntimeClass;
            }
            else if (obj is InterfaceInfo && ((InterfaceInfo)obj).Delegate)
            {
                return TypeDefinitionKind.Delegate;
            }
            else if (obj is InterfaceInfo)
            {
                return TypeDefinitionKind.Interface;
            }
            else if (obj is StructInfo)
            {
                return TypeDefinitionKind.Struct;
            }
            else if (obj is EnumInfo)
            {
                return TypeDefinitionKind.Enum;
            }
            else if (obj is GenericInterfaceInfo)
            {
                return TypeDefinitionKind.GenericInterface;
            }
            else
            {
                throw new NotImplementedException(String.Format(StringExceptionFormats.InvalidRepositoryTypeKind, typeName));
            }
        }
    }
}