using Microsoft.Wcl.DataStore;
using Microsoft.Wcl.Parsers;
using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Threading.Tasks;

namespace Microsoft.Wcl.NamespaceDependencies
{
    class NamespaceDependenciesResolver
    {
        NamespaceToGenericInterfaceDependencyResolver NamespaceToGenericInterfaceResolver { get; set; }

        NamespaceToTypeCategoryDependencyResolver NamespaceToTypeCategoryDependencyResolver { get; set; }

        FrontEndConfiguration Configuration { get; set; }

        IDictionary<string, NamespaceDependencyInfo> NamespaceDependenciesTable { get; set; } = new Dictionary<string, NamespaceDependencyInfo>();

        public NamespaceDependenciesResolver(FrontEndConfiguration configuration)
        {
            this.NamespaceToTypeCategoryDependencyResolver = new NamespaceToTypeCategoryDependencyResolver(this.NamespaceDependenciesTable, configuration.DataStore.GetRepository());
            this.NamespaceToGenericInterfaceResolver = new NamespaceToGenericInterfaceDependencyResolver(this.NamespaceDependenciesTable, configuration.DataStore.GetGenericInterfacesRepository());
            this.Configuration = configuration;
        }

        public void ResolveAndInsertIntoRepository()
        {
            var watch = new Stopwatch();
            var dataStore = this.Configuration.DataStore;

            FrontEndConfiguration.Output.WriteLine(StringMessageFormats.ResolvingNamespaceDependencies);
            watch.Start();

            foreach (var info in dataStore.GetRepository().Values)
            {
                ResolveInfo(info);
            }

            watch.Stop();
            FrontEndConfiguration.Output.WriteLine(StringMessageFormats.TimeToResolveNamespaceDependencies, watch.ElapsedMilliseconds);

            foreach (var namespaceDependencyInfo in this.NamespaceDependenciesTable.Values)
            {
                foreach (var namespaceToTypeCategory in namespaceDependencyInfo.DependentNamespaceTypeCategoriesTable.Values)
                {
                    dataStore.InsertNamespaceToTypeCategoryDependency(namespaceDependencyInfo.NamespaceName, namespaceToTypeCategory.DependentNamespaceName, namespaceToTypeCategory.Categories);
                }

                dataStore.InsertNamespaceToGenericInterfaceDependency(namespaceDependencyInfo.NamespaceName, namespaceDependencyInfo.DependentGenericInterfaces);
            }
        }

        private void ResolveInfo(object info)
        {
            if (info is StructInfo)
            {
                ProcessStruct((StructInfo)info);
            }
            if (info is InterfaceInfo)
            {
                ProcessInterface((InterfaceInfo)info);
            }
            if (info is RuntimeClassInfo)
            {
                ProcessRuntimeclass((RuntimeClassInfo)info);
            }
        }

        private void ProcessRuntimeclass(RuntimeClassInfo info)
        {
            // No Activatable interface is a candidate for namespace dependency. The interface can't be a generic interface (it is a IFactory).
            // Same for the static interface. They can't be a generic interface.
            // Base can only be another runtimeclass

            // Not all runtimeclasses have a default interface
            if (!String.IsNullOrEmpty(info.DefaultInterface) && (this.IsTypeACandidate(info.DefaultInterface)))
            {
                this.NamespaceToGenericInterfaceResolver.Resolve(info.FullTypeName, info.DefaultInterface);
                this.NamespaceToTypeCategoryDependencyResolver.Resolve(info.FullTypeName, info.DefaultInterface);
            }

            foreach (var item in info.InterfacesInfo)
            {
                if (this.IsTypeACandidate(item.Interface))
                {
                    this.NamespaceToGenericInterfaceResolver.Resolve(info.FullTypeName, item.Interface);
                    this.NamespaceToTypeCategoryDependencyResolver.Resolve(info.FullTypeName, item.Interface);
                }
            }
        }

        private void ProcessStruct(StructInfo info)
        {
            foreach (var field in info.FieldsInfo)
            {
                if (this.IsTypeACandidate(field.Type))
                {
                    this.NamespaceToGenericInterfaceResolver.Resolve(info.FullName, field.Type);
                    this.NamespaceToTypeCategoryDependencyResolver.Resolve(info.FullName, field.Type);
                }
            }
        }

        private void ProcessInterface(InterfaceInfo info)
        {
            foreach (var method in info.MethodsInfo)
            {
                foreach (var parameter in method.ParametersInfo)
                {
                    if (this.IsTypeACandidate(parameter.Type))
                    {
                        this.NamespaceToGenericInterfaceResolver.Resolve(info.FullName, parameter.Type);
                        this.NamespaceToTypeCategoryDependencyResolver.Resolve(info.FullName, parameter.Type);
                    }
                }
            }

            foreach (var required in info.RequiredInterfacesInfo)
            {
                if (this.IsTypeACandidate(required.Requires))
                {
                    this.NamespaceToGenericInterfaceResolver.Resolve(info.FullName, required.Requires);
                    this.NamespaceToTypeCategoryDependencyResolver.Resolve(info.FullName, required.Requires);
                }
            }
        }

        private bool IsTypeACandidate(string fullTypeName)
        {
            // Weed out open types that exists in metadata. These are the ones that look like generic interfaces, but are open like IVector<!!0> (they are the unespecialized ones)
            return GenericInterfaceParser.IsGenericInterface(fullTypeName) && !GenericInterfaceParser.IsOpenType(fullTypeName);
        }
    }
}
