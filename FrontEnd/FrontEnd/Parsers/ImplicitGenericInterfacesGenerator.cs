using Microsoft.Wcl.DataStore;
using System;
using System.Collections.Generic;
using System.Text;

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
            public int[] ArgumentIndexes;
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
                    new GenericInterfaceDependecyItem() { Dependency = "Windows::Foundation::Collections::IVectorView`1", Format =  StringFormats.OpenGenericDependency1 }, } },

            new GenericInterfaceDependency() { FullTypeName = "Windows::Foundation::Collections::IIterable`1",
                Dependencies = new List<GenericInterfaceDependecyItem>() {
                    new GenericInterfaceDependecyItem() { Dependency = "Windows::Foundation::Collections::IIterator`1", Format =  StringFormats.OpenGenericDependency1 } } },

            new GenericInterfaceDependency() { FullTypeName = "Windows::Foundation::Collections::IMap`2",
                Dependencies = new List<GenericInterfaceDependecyItem>() {
                    new GenericInterfaceDependecyItem() { Dependency = "Windows::Foundation::Collections::IMapView`2", Format =  StringFormats.OpenGenericDependency1 }, } },

            new GenericInterfaceDependency() { FullTypeName = "Windows::Foundation::Collections::IMapView`2",
                Dependencies = new List<GenericInterfaceDependecyItem>() {
                    new GenericInterfaceDependecyItem() { Dependency = "Windows::Foundation::Collections::IIterable`1", Format =  StringFormats.OpenGenericDependency2 },
                    new GenericInterfaceDependecyItem() { Dependency = "Windows::Foundation::Collections::IKeyValuePair`2", Format =  StringFormats.OpenGenericDependency1 }, } },

            new GenericInterfaceDependency() { FullTypeName = "Windows::Foundation::Collections::IObservableMap`2",
                Dependencies = new List<GenericInterfaceDependecyItem>() {
                    new GenericInterfaceDependecyItem() { Dependency = "Windows::Foundation::Collections::IMap`2", Format =  StringFormats.OpenGenericDependency1 },
                    new GenericInterfaceDependecyItem() { Dependency = "Windows::Foundation::Collections::MapChangedEventHandler`2", Format =  StringFormats.OpenGenericDependency1 },
                    new GenericInterfaceDependecyItem() { Dependency = "Windows::Foundation::Collections::IMapChangedEventArgs`1", Format =  StringFormats.OpenGenericDependency1, ArgumentIndexes = new int[] { 0 } },} },

            new GenericInterfaceDependency() { FullTypeName = "Windows::Foundation::Collections::IObservableVector`1",
                Dependencies = new List<GenericInterfaceDependecyItem>() {
                    new GenericInterfaceDependecyItem() { Dependency = "Windows::Foundation::Collections::IVector`1", Format =  StringFormats.OpenGenericDependency1 },
                    new GenericInterfaceDependecyItem() { Dependency = "Windows::Foundation::Collections::VectorChangedEventHandler`1", Format =  StringFormats.OpenGenericDependency1 },} },
        };

        static public List<GenericInterfaceInfo> GenerateDependencyGenericInterfaces(GenericInterfaceInfo info)
        {
            var list = new List<GenericInterfaceInfo>();

            GenerateDependencyGenericInterfacesHelper(info, list);

            // Generation is done from top to bottom of the graph,
            // but definition needs to be done from bottom to top.
            // Return the list in reverse order so that back end get's them in the order
            // that they are needed from the compiler POV.
            list.Reverse();

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
                            string newDependency = null;
                            // Some templates need all arguments, some need only some of them.
                            // Create the appropiate payload based on what the dependency definition is.
                            if (dependency.ArgumentIndexes == null)
                            {
                                newDependency = String.Format(dependency.Format, dependency.Dependency, arguments);
                            }
                            else
                            {
                                string[] parts = arguments.Split(new char[] { ',' });
                                StringBuilder templateArguments = new StringBuilder();
                                foreach (var index in dependency.ArgumentIndexes)
                                {
                                    templateArguments.AppendFormat("{0}, ", parts[index].Trim());
                                }
                                templateArguments.Length -= 2;

                                newDependency = String.Format(dependency.Format, dependency.Dependency, templateArguments.ToString());
                            }

                            var nameIndex = TypeNameUtilities.GetIndexOfTypeNameForGenericInterface(newDependency);
                            GenericInterfaceInfo newInfo = new GenericInterfaceInfo()
                            {
                                FullName = newDependency,
                                Namespace = newDependency.Substring(0, nameIndex),
                                Name = newDependency.Substring(nameIndex + 2),
                                MetadataFullTypeNameInDotForm = TypeNameUtilities.GetFullTypeNameInDotForm(newDependency),
                                MetadataFullTypeNameInCppForm = newDependency,
                                Depth = GenericInterfaceParser.GetGenericInterfaceDepthness(newDependency)
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
