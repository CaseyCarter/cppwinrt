using Microsoft.Wcl.DataStore;
using Microsoft.Wcl.ParameterizedTypeInstanceIID;
using Microsoft.Wcl.Parsers;
using Microsoft.Wcl.Projection;
using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Microsoft.Wcl.NamespaceDependencies
{
    class NamespaceToTypeCategoryDependencyResolver
    {
        IDictionary<string, NamespaceDependencyInfo> NamespaceDependenciesTable { get; set; }

        private IDictionary<string, object> Repository { get; set; }

        public NamespaceToTypeCategoryDependencyResolver(IDictionary<string, NamespaceDependencyInfo> namespaceDependenciesTable, IDictionary<string, object> repository)
        {
            this.NamespaceDependenciesTable = namespaceDependenciesTable;
            this.Repository = repository;
        }

        public void Resolve(string containerFullTypeName, string fullTypeName)
        {
            ResolveHelper(containerFullTypeName, fullTypeName, null);
        }

        /// <summary>
        /// For a given container type, that uses type Foo, resolve the type category (by projecting it if requested) for Foo and insert appropiate data to
        /// the table that maintains a namespace to type category data.
        /// </summary>
        /// <param name="containerFullTypeName">The container type</param>
        /// <param name="fullTypeName">The type for which its type category will be resolved</param>
        /// <param name="targetTypeCategory">If other than Unknown, bypass projecting the type and instead just save the data</param>
        public void Resolve(string containerFullTypeName, string fullTypeName, TypeCategory targetTypeCategory)
        {
            ResolveHelper(containerFullTypeName, fullTypeName, targetTypeCategory);
        }

        private void ResolveHelper(string containerFullTypeName, string fullTypeName, TypeCategory? targetTypeCategory)
        {
            var containerNamespaceName = TypeNameUtilities.GetNamespaceNameFromType(containerFullTypeName);
            NamespaceDependencyInfo namespaceDependencyInfo = null;

            if (!this.NamespaceDependenciesTable.TryGetValue(containerNamespaceName, out namespaceDependencyInfo))
            {
                namespaceDependencyInfo = new NamespaceDependencyInfo();
                namespaceDependencyInfo.NamespaceName = containerNamespaceName;
                this.NamespaceDependenciesTable.Add(containerNamespaceName, namespaceDependencyInfo);
            }

            // Types, like String, Object don't have a namespace. Use empty for them
            var targetTypeNamespaceNameIndex = 0;
            if (TypeNameUtilities.IsTypeInANamespace(fullTypeName))
            {
                if (GenericInterfaceParser.IsGenericInterface(fullTypeName))
                {
                    targetTypeNamespaceNameIndex = TypeNameUtilities.GetIndexOfTypeNameForGenericInterface(fullTypeName);
                    this.ResolveGenericInterfaceParts(containerFullTypeName, fullTypeName);
                }
                else
                {
                    targetTypeNamespaceNameIndex = TypeNameUtilities.GetIndexOfTypeName(fullTypeName);
                }
            }

            var targetTypeNamespaceName = fullTypeName.Substring(0, targetTypeNamespaceNameIndex);

            // Depends on itself ?. If so, no need to add those entries.
            if (containerNamespaceName == targetTypeNamespaceName)
            {
                return;
            }

            this.ResolveDependentNamespaceCategories(namespaceDependencyInfo, targetTypeNamespaceName, fullTypeName, targetTypeCategory);

        }

        private void ResolveDependentNamespaceCategories(NamespaceDependencyInfo namespaceDependencyInfo, string targetTypeNamespaceName, string fullTypeName, TypeCategory? targetTypeCategory)
        {
            NamespaceDependencyInfo.NamespaceToTypeCategoryDependencyInfoEntry dependentNamespace = null;

            if (!namespaceDependencyInfo.DependentNamespaceTypeCategoriesTable.TryGetValue(targetTypeNamespaceName, out dependentNamespace))
            {
                dependentNamespace = new NamespaceDependencyInfo.NamespaceToTypeCategoryDependencyInfoEntry();
                dependentNamespace.DependentNamespaceName = targetTypeNamespaceName;
                namespaceDependencyInfo.DependentNamespaceTypeCategoriesTable.Add(targetTypeNamespaceName, dependentNamespace);
            }

            // If projection is requested (use of null for targetTypeCategory), project, otherwise, use the provided value.
            var typeCategory = targetTypeCategory.HasValue ? targetTypeCategory.Value : TypeCategory.Unknown;
            if (!targetTypeCategory.HasValue)
            {
                string projectedType = null;
                MetadataTypeToProjectedTypeConverter.GetProjectedTypeAndCategoryFromMetadataType(fullTypeName, false, this.Repository, out projectedType, out typeCategory);

                // Once it is determined that the type is an interface, determine if the projected type's namespace is different than the type namespace.
                // If so we are dealing with a runtime class whos default interface is in a different namespace. This affects generic dependencies.
                if (typeCategory == TypeCategory.Interface)
                {
                    string projectedTypeNamespaceName = TypeNameUtilities.GetNamespaceNameFromType(projectedType);

                    if (projectedTypeNamespaceName != targetTypeNamespaceName && !GenericInterfaceParser.IsGenericInterface(projectedType))
                    {
                        NamespaceDependencyInfo.NamespaceToTypeCategoryDependencyInfoEntry dependentDefaultInterfaceNamespace = null;
                        if (!namespaceDependencyInfo.DependentNamespaceTypeCategoriesTable.TryGetValue(projectedTypeNamespaceName, out dependentDefaultInterfaceNamespace))
                        {
                            dependentDefaultInterfaceNamespace = new NamespaceDependencyInfo.NamespaceToTypeCategoryDependencyInfoEntry();
                            dependentDefaultInterfaceNamespace.DependentNamespaceName = projectedTypeNamespaceName;
                            namespaceDependencyInfo.DependentNamespaceTypeCategoriesTable.Add(projectedTypeNamespaceName, dependentDefaultInterfaceNamespace);
                        }

                        if (!dependentDefaultInterfaceNamespace.Categories.Contains(typeCategory))
                        {
                            Debug.Assert(typeCategory != TypeCategory.Unknown);
                            dependentDefaultInterfaceNamespace.Categories.Add(typeCategory);
                        }
                    }
                }
            }

            if (!dependentNamespace.Categories.Contains(typeCategory))
            {
                Debug.Assert(typeCategory != TypeCategory.Unknown);
                dependentNamespace.Categories.Add(typeCategory);
            }
        }

        private void ResolveGenericInterfaceParts(string containerFullTypeName, string fullTypeName)
        {
            // Only interested in non generic interfaces.

            var parts = TypeNameParser.GetParts(fullTypeName);
            var first = true;

            foreach (var part in parts)
            {
                // First part is what brought us here (the generic interface). Only resolve the rest
                if (first)
                {
                    first = false;
                    continue;
                }

                if (!GenericInterfaceParser.IsOpenInterface(part))
                {
                    this.Resolve(containerFullTypeName, part);
                }
            }
        }
    }
}