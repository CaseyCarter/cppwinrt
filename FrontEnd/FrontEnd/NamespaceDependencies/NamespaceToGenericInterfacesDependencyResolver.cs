using Microsoft.Wcl.DataStore;
using Microsoft.Wcl.Parsers;
using System.Collections.Generic;
using System.Diagnostics;

namespace Microsoft.Wcl.NamespaceDependencies
{
    class NamespaceToGenericInterfaceDependencyResolver
    {
        private IDictionary<string, NamespaceDependencyInfo> NamespaceDependenciesTable { get; set; }

        private IDictionary<string, GenericInterfaceInfo> GenericInterfacesRepository { get; set; }

        public NamespaceToGenericInterfaceDependencyResolver(IDictionary<string, NamespaceDependencyInfo> namespaceDependenciesTable, IDictionary<string, GenericInterfaceInfo> genericInterfacesRepository)
        {
            this.NamespaceDependenciesTable = namespaceDependenciesTable;
            this.GenericInterfacesRepository = genericInterfacesRepository;
        }

        /// <summary>
        /// For a given container type and a generic interface, save per namespace of the container type, all the generic interfaces it depends on.
        /// It includes all the inner generic interfaces and the implicit generic interfaces.
        /// </summary>
        /// <param name="containerFullTypeName"></param>
        /// <param name="fullTypeName"></param>
        public void Resolve(string containerFullTypeName, string fullTypeName)
        {
            NamespaceDependencyInfo namespaceDependencyInfo = null;
            var namespaceName = TypeNameUtilities.GetNamespaceNameFromType(containerFullTypeName);
            var genericInterfaceInfo = this.GenericInterfacesRepository[fullTypeName];

            if (!this.NamespaceDependenciesTable.TryGetValue(namespaceName, out namespaceDependencyInfo))
            {
                namespaceDependencyInfo = new NamespaceDependencyInfo();
                namespaceDependencyInfo.NamespaceName = namespaceName;

                this.NamespaceDependenciesTable.Add(namespaceName, namespaceDependencyInfo);
            }

            foreach (var info in genericInterfaceInfo.InnerGenericInterfaces)
            {
                if (!namespaceDependencyInfo.DependentGenericInterfaces.Contains(info.MetadataFullTypeNameInCppForm))
                {
                    namespaceDependencyInfo.DependentGenericInterfaces.Add(info.MetadataFullTypeNameInCppForm);
                }
            }

            foreach (var info in genericInterfaceInfo.ImplicitGenericInterfaces)
            {
                if (!namespaceDependencyInfo.DependentGenericInterfaces.Contains(info.MetadataFullTypeNameInCppForm))
                {
                    namespaceDependencyInfo.DependentGenericInterfaces.Add(info.MetadataFullTypeNameInCppForm);
                }
            }

            Debug.Assert(fullTypeName == genericInterfaceInfo.MetadataFullTypeNameInCppForm);
            if (!namespaceDependencyInfo.DependentGenericInterfaces.Contains(genericInterfaceInfo.MetadataFullTypeNameInCppForm))
            {
                namespaceDependencyInfo.DependentGenericInterfaces.Add(genericInterfaceInfo.MetadataFullTypeNameInCppForm);
            }
        }
    }
}
