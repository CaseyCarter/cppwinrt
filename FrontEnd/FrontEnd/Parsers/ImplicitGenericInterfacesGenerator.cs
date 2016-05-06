using Microsoft.Wcl.DataStore;
using System;
using System.Collections.Generic;

namespace Microsoft.Wcl.Parsers
{
    static class ImplicitGenericInterfacesGenerator
    {
        class GenericInterfaceDependency
        {
            public string FullTypeName;
            public IList<GenericInterfaceDependecyItem> Dependencies;
        }

        class GenericInterfaceDependecyItem
        {
            public string Dependency;
            public string Format;
        }

        static IList<GenericInterfaceDependency> GenericInterfaceDependencies = new List<GenericInterfaceDependency>()
        {
            new GenericInterfaceDependency() { FullTypeName = "Windows::Foundation::IAsyncOperation`1",
                Dependencies = new List<GenericInterfaceDependecyItem>() {
                    new GenericInterfaceDependecyItem() { Dependency = "Windows::Foundation::AsyncOperationCompletedHandler`1", Format =  StringFormats.OpenGenericDependency1 }  } },

            new GenericInterfaceDependency() { FullTypeName = "Windows::Foundation::IAsyncOperationWithProgress`2",
                Dependencies = new List<GenericInterfaceDependecyItem>() {
                    new GenericInterfaceDependecyItem() { Dependency = "Windows::Foundation::AsyncOperationWithProgressCompletedHandler`2", Format =  StringFormats.OpenGenericDependency1 },
                    new GenericInterfaceDependecyItem() { Dependency = "Windows::Foundation::AsyncOperationProgressHandler`2",  Format =  StringFormats.OpenGenericDependency1 } } },

            new GenericInterfaceDependency() { FullTypeName = "Windows::Foundation::IAsyncActionWithProgress`1",
                Dependencies = new List<GenericInterfaceDependecyItem>() {
                    new GenericInterfaceDependecyItem() { Dependency = "Windows::Foundation::AsyncActionWithProgressCompletedHandler`1", Format =  StringFormats.OpenGenericDependency1 },
                    new GenericInterfaceDependecyItem() { Dependency = "Windows::Foundation::AsyncActionProgressHandler`1", Format =  StringFormats.OpenGenericDependency1 } } },

            new GenericInterfaceDependency() { FullTypeName = "Windows::Foundation::Collections::IVectorView`1",
                Dependencies = new List<GenericInterfaceDependecyItem>() {
                    new GenericInterfaceDependecyItem() { Dependency = "Windows::Foundation::Collections::IIterable`1", Format =  StringFormats.OpenGenericDependency1 }, } },

            new GenericInterfaceDependency() { FullTypeName = "Windows::Foundation::Collections::IVector`1",
                Dependencies = new List<GenericInterfaceDependecyItem>() {
                    new GenericInterfaceDependecyItem() { Dependency = "Windows::Foundation::Collections::IIterable`1", Format =  StringFormats.OpenGenericDependency1 }, } },

            new GenericInterfaceDependency() { FullTypeName = "Windows::Foundation::Collections::IIterable`1",
                Dependencies = new List<GenericInterfaceDependecyItem>() {
                    new GenericInterfaceDependecyItem() { Dependency = "Windows::Foundation::Collections::IIterator`1", Format =  StringFormats.OpenGenericDependency1 } } },

            new GenericInterfaceDependency() { FullTypeName = "Windows::Foundation::Collections::IMap`2",
                Dependencies = new List<GenericInterfaceDependecyItem>() {
                    new GenericInterfaceDependecyItem() { Dependency = "Windows::Foundation::Collections::IMapView`2", Format =  StringFormats.OpenGenericDependency1 }, } },

            new GenericInterfaceDependency() { FullTypeName = "Windows::Foundation::Collections::IMapView`2",
                Dependencies = new List<GenericInterfaceDependecyItem>() {
                    new GenericInterfaceDependecyItem() { Dependency = "Windows::Foundation::Collections::IKeyValuePair`2", Format =  StringFormats.OpenGenericDependency1 },
                    new GenericInterfaceDependecyItem() { Dependency = "Windows::Foundation::Collections::IIterable`1", Format =  StringFormats.OpenGenericDependency2 }, } },

            new GenericInterfaceDependency() { FullTypeName = "Windows::Foundation::Collections::IObservableMap`2",
                Dependencies = new List<GenericInterfaceDependecyItem>() {
                    new GenericInterfaceDependecyItem() { Dependency = "Windows::Foundation::Collections::IMap`2", Format =  StringFormats.OpenGenericDependency1 }, } },

            new GenericInterfaceDependency() { FullTypeName = "Windows::Foundation::Collections::IObservableVector`1",
                Dependencies = new List<GenericInterfaceDependecyItem>() {
                    new GenericInterfaceDependecyItem() { Dependency = "Windows::Foundation::Collections::IVector`1", Format =  StringFormats.OpenGenericDependency1 }, } },
        };

        static public List<GenericInterfaceInfo> GenerateDependencyGenericInterfaces(GenericInterfaceInfo info)
        {
            var list = new List<GenericInterfaceInfo>();

            GenerateDependencyGenericInterfacesHelper(info, list);

            return list;
        }

        static void GenerateDependencyGenericInterfacesHelper(GenericInterfaceInfo info, List<GenericInterfaceInfo> list)
        {
            foreach (var set in GenericInterfaceDependencies)
            {
                if (info.FullName.StartsWith(set.FullTypeName))
                {
                    string arguments = null;

                    if (GenericInterfaceParser.TryGetGenericInterfaceArguments(info.FullName, out arguments))
                    {
                        foreach (var dependency in set.Dependencies)
                        {
                            string newDependency = String.Format(dependency.Format, dependency.Dependency, arguments);

                            GenericInterfaceInfo newInfo = new GenericInterfaceInfo()
                            {
                                FullName = newDependency,
                                Name = TypeNameUtilities.GetIndexOfTypeNameForGenericInterface(newDependency),
                                MetadataFullTypeNameInDotForm = TypeNameUtilities.GetFullTypeNameInDotForm(newDependency)
                            };

                            list.Add(newInfo);
                            GenerateDependencyGenericInterfacesHelper(newInfo, list);
                        }
                    }
                    else
                    {
                        throw new InvalidOperationException(String.Format(StringExceptionFormats.CouldNotParseGenericInterface, info.FullName));
                    }
                }
            }
        }
    }
}
