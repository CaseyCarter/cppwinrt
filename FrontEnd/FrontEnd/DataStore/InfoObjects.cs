using Microsoft.Wcl.Projection;
using System;
using System.Collections.Generic;

namespace Microsoft.Wcl.DataStore
{
    // Notes: 
    // 1. All class names match CLR names, not the one in the database. For example, Enum versus Enumerators, Struct versus Structures.
    // 2. All members names match the ones in the database to help with the the database operations. 
    // 3. Only the fields that are used during metadata parsing are declared.
    // 4. Extra fields, used for example during debugging, are added at the bottom of the types.

    internal class EnumInfo
    {
        public string FullName;
        public int Name;
        public bool Flags;
        public bool Deprecated;

        public IList<EnumFieldInfo> FieldNames;
    }

    internal class EnumFieldInfo
    {
        public string Name;
        public object Value;
        public bool Deprecated;

        // Not in the database.
        public string EnumerationFullTypeName;
    }

    internal class InterfaceInfo
    {
        public string FullName;
        public int Name;
        public bool Delegate;
        public string Uuid;
        public bool Deprecated;

        public IList<InterfaceMethodInfo> MethodsInfo;
        public IList<InterfaceRequiredInterfaceInfo> RequiredInterfacesInfo;
    }

    internal class InterfaceMethodInfo
    {
        public string Name;
        public string AbiName;
        public bool Deprecated;

        public IList<InterfaceMethodParameterInfo> ParametersInfo;

        // Not in the database
        public string InterfaceFullTypeName;
    }

    internal class InterfaceRequiredInterfaceInfo
    {
        public string Requires;

        public string InterfaceFullTypeName;
    }

    internal class InterfaceMethodParameterInfo
    {
        public string Name;
        public string Type;
        public ParameterAttributesInfo Flags;

        public string MethodFullName;
    }

    [Flags]
    internal enum ParameterAttributesInfo
    {
        None = System.Reflection.ParameterAttributes.None,
        In = System.Reflection.ParameterAttributes.In,
        Out = System.Reflection.ParameterAttributes.Out,
        Return = 0x10000,
        ByRef = 0x20000,
        Array = 0x40000,
        Const = 0x80000
    }

    internal class RuntimeClassInfo
    {
        public string FullTypeName;
        // It is actually the index
        public int Name;
        public string Base;
        public string DefaultInterface;
        public bool Activatable;
        public bool Deprecated;

        public IList<RuntimeClassInterfaceInfo> InterfacesInfo;
        public IList<RuntimeClassStaticInterfaceInfo> StaticInterfacesInfo;
        public IList<RuntimeClassConstructorInterfaceInfo> ContructorInterfacesInfo;
    }

    internal class RuntimeClassInterfaceInfo
    {
        public string Interface;
        public bool IsDefault;
        public bool Overridable;
        public bool Protected;

        // Not in database
        public string RuntimeclassFullTypeName;
    }

    internal class RuntimeClassStaticInterfaceInfo
    {
        public string Interface;

        // Not in database
        public string RuntimeclassFullTypeName;
    }

    // Used for Activatable and Composable interfaces
    internal class RuntimeClassConstructorInterfaceInfo
    {
        public string Interface;
        public bool Composable;
        public bool Protected;

        // Not in database
        public string RuntimeclassFullTypeName;
    }

    internal class StructInfo
    {
        public string FullName;
        public int Name;
        public int Depends;
        public bool Deprecated;

        public IList<StructFieldInfo> FieldsInfo;
    }

    internal class StructFieldInfo
    {
        public string Name;
        public string Type;
        public string Category;

        public string StructFullTypeName;
    }

    internal class GenericInterfaceInfo
    {
        public string FullName;
        public int Name;
        public string Uuid;
        public int Depth;

        
        public string MetadataFullTypeNameInDotForm;
        public string MetadataFullTypeNameInCppForm;

        public List<GenericInterfaceInfo> ImplicitGenericInterfaces;
        public List<GenericInterfaceInfo> InnerGenericInterfaces;
    }

    class NamespaceDependencyInfo
    {
        /// <summary>
        /// Top level namespace (refered as A in all comments below).
        /// </summary>
        public string NamespaceName;

        /// <summary>
        /// Namespace A depends on Namespace B. Namespace B uses X Type Categories.
        /// </summary>
        public Dictionary<string, NamespaceToTypeCategoryDependencyInfoEntry> DependentNamespaceTypeCategoriesTable = new Dictionary<string, NamespaceToTypeCategoryDependencyInfoEntry>();

        /// <summary>
        /// Namespace A depends on X Generic Interfaces
        /// </summary>
        public List<string> DependentGenericInterfaces = new List<string>();

        /// <summary>
        /// Namespace B uses X Type Categories
        /// </summary>
        public class NamespaceToTypeCategoryDependencyInfoEntry
        {
            public string DependentNamespaceName;
            public List<TypeCategory> Categories = new List<TypeCategory>();
        }
    }
}
