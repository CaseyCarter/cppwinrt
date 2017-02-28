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
            public Predicate<string> Matches;
            public IList<GenericInterfaceDependencyBaseItem> Dependencies;
        }

        abstract class GenericInterfaceDependencyBaseItem
        {
            abstract public string Format(string arguments);
        }

        class GenericInterfaceDependencyItem : GenericInterfaceDependencyBaseItem
        {
            public string Dependency_;
            public string Format_;
            public override string Format(string arguments)
            {
                return String.Format(Format_, Dependency_, arguments);
            }
            public delegate string CustomFormatter(string arguments);
        }

        class ParameterSwallowingGenericInterfaceDependencyItem : GenericInterfaceDependencyBaseItem
        {
            public string Dependency_;
            public string Format_;
            public int[] ArgumentIndexes;
            public override string Format(string arguments)
            {
                // Some templates need all arguments, some need only some of them.
                // Create the appropiate payload based on what the dependency definition is.
                string[] parts = arguments.Split(new char[] { ',' });
                StringBuilder templateArguments = new StringBuilder();
                foreach (var index in ArgumentIndexes)
                {
                    templateArguments.AppendFormat("{0}, ", parts[index].Trim());
                }
                templateArguments.Length -= 2;
                return String.Format(Format_, Dependency_, templateArguments.ToString());
            }
        }

        class TypeWrapperSwallowingGenericInterfaceDependencyItem : GenericInterfaceDependencyBaseItem
        {
            public string Dependency_;
            public string Format_;
            public string WrapperToDiscard_;

            public override string Format(string arguments)
            {
                if (arguments.StartsWith(WrapperToDiscard_))
                {
                    int start = WrapperToDiscard_.Length;
                    int length = arguments.Length - WrapperToDiscard_.Length;
                    if (WrapperToDiscard_.EndsWith("<") && arguments.EndsWith(">"))
                    {
                        --length;
                    }
                    arguments = arguments.Substring(start, length);
                }
                return String.Format(Format_, Dependency_, arguments);
            }
        }

        static IList<GenericInterfaceDependency> GenericInterfaceDependencies = new List<GenericInterfaceDependency>()
        {
            new GenericInterfaceDependency() { Matches = x => x.StartsWith("Windows::Foundation::IAsyncOperation`1"),
                Dependencies = new List<GenericInterfaceDependencyBaseItem>() {
                    new GenericInterfaceDependencyItem() { Dependency_ = "Windows::Foundation::AsyncOperationCompletedHandler`1", Format_ = StringFormats.OpenGenericDependency1 } } },

            new GenericInterfaceDependency() { Matches = x => x.StartsWith("Windows::Foundation::IAsyncOperationWithProgress`2"),
                Dependencies = new List<GenericInterfaceDependencyBaseItem>() {
                    new GenericInterfaceDependencyItem() { Dependency_ = "Windows::Foundation::AsyncOperationWithProgressCompletedHandler`2", Format_ =  StringFormats.OpenGenericDependency1 },
                    new GenericInterfaceDependencyItem() { Dependency_ = "Windows::Foundation::AsyncOperationProgressHandler`2",  Format_ =  StringFormats.OpenGenericDependency1 } } },

            new GenericInterfaceDependency() { Matches = x => x.StartsWith("Windows::Foundation::IAsyncActionWithProgress`1"),
                Dependencies = new List<GenericInterfaceDependencyBaseItem>() {
                    new GenericInterfaceDependencyItem() { Dependency_ = "Windows::Foundation::AsyncActionWithProgressCompletedHandler`1", Format_ =  StringFormats.OpenGenericDependency1 },
                    new GenericInterfaceDependencyItem() { Dependency_ = "Windows::Foundation::AsyncActionProgressHandler`1", Format_ =  StringFormats.OpenGenericDependency1 } } },

            new GenericInterfaceDependency() { Matches = x => x.StartsWith("Windows::Foundation::Collections::IVectorView`1"),
                Dependencies = new List<GenericInterfaceDependencyBaseItem>() {
                    new GenericInterfaceDependencyItem() { Dependency_ = "Windows::Foundation::Collections::IIterable`1", Format_ =  StringFormats.OpenGenericDependency1 },
                    new GenericInterfaceDependencyItem() { Dependency_ = "Windows::Foundation::Collections::IVector`1", Format_ = StringFormats.OpenGenericDependency1 } } },

            new GenericInterfaceDependency() { Matches = x => x.StartsWith("Windows::Foundation::Collections::IVector`1"),
                Dependencies = new List<GenericInterfaceDependencyBaseItem>() {
                    new GenericInterfaceDependencyItem() { Dependency_ = "Windows::Foundation::Collections::IVectorView`1", Format_ =  StringFormats.OpenGenericDependency1 }, } },

            new GenericInterfaceDependency() { Matches = x => x.StartsWith("Windows::Foundation::Collections::IIterable`1"),
                Dependencies = new List<GenericInterfaceDependencyBaseItem>() {
                    new GenericInterfaceDependencyItem() { Dependency_ = "Windows::Foundation::Collections::IIterator`1", Format_ =  StringFormats.OpenGenericDependency1 } } },

            new GenericInterfaceDependency() { Matches = x => x.StartsWith("Windows::Foundation::Collections::IIterable`1") && !x.StartsWith("Windows::Foundation::Collections::IIterable`1<Windows::Foundation::Collections::IKeyValuePair`2"),
                Dependencies = new List<GenericInterfaceDependencyBaseItem>() {
                    new GenericInterfaceDependencyItem() { Dependency_ = "Windows::Foundation::Collections::IVectorView`1", Format_ =  StringFormats.OpenGenericDependency1 } } },

            new GenericInterfaceDependency() { Matches = x => x.StartsWith("Windows::Foundation::Collections::IIterable`1<Windows::Foundation::Collections::IKeyValuePair`2"),
                Dependencies = new List<GenericInterfaceDependencyBaseItem>() {
                    new TypeWrapperSwallowingGenericInterfaceDependencyItem() { Dependency_ = "Windows::Foundation::Collections::IMapView`2", Format_ =  StringFormats.OpenGenericDependency1, WrapperToDiscard_ = "Windows::Foundation::Collections::IKeyValuePair`2<" } } },

            new GenericInterfaceDependency() { Matches = x => x.StartsWith("Windows::Foundation::Collections::IIterator`1"),
                Dependencies = new List<GenericInterfaceDependencyBaseItem>() {
                    new GenericInterfaceDependencyItem() { Dependency_ = "Windows::Foundation::Collections::IIterable`1", Format_ =  StringFormats.OpenGenericDependency1 } } },

            new GenericInterfaceDependency() { Matches = x => x.StartsWith("Windows::Foundation::Collections::IMap`2"),
                Dependencies = new List<GenericInterfaceDependencyBaseItem>() {
                    new GenericInterfaceDependencyItem() { Dependency_ = "Windows::Foundation::Collections::IMapView`2", Format_ =  StringFormats.OpenGenericDependency1 }, } },

            new GenericInterfaceDependency() { Matches = x => x.StartsWith("Windows::Foundation::Collections::IMapView`2"),
                Dependencies = new List<GenericInterfaceDependencyBaseItem>() {
                    new GenericInterfaceDependencyItem() { Dependency_ = "Windows::Foundation::Collections::IIterable`1", Format_ =  StringFormats.OpenGenericDependency2 },
                    new GenericInterfaceDependencyItem() { Dependency_ = "Windows::Foundation::Collections::IMap`2", Format_ =  StringFormats.OpenGenericDependency1 },
                    new GenericInterfaceDependencyItem() { Dependency_ = "Windows::Foundation::Collections::IKeyValuePair`2", Format_ =  StringFormats.OpenGenericDependency1 }, } },

            new GenericInterfaceDependency() { Matches = x => x.StartsWith("Windows::Foundation::Collections::IObservableMap`2"),
                Dependencies = new List<GenericInterfaceDependencyBaseItem>() {
                    new GenericInterfaceDependencyItem() { Dependency_ = "Windows::Foundation::Collections::IMap`2", Format_ =  StringFormats.OpenGenericDependency1 },
                    new GenericInterfaceDependencyItem() { Dependency_ = "Windows::Foundation::Collections::MapChangedEventHandler`2", Format_ =  StringFormats.OpenGenericDependency1 },
                    new ParameterSwallowingGenericInterfaceDependencyItem() { Dependency_ = "Windows::Foundation::Collections::IMapChangedEventArgs`1", Format_ =  StringFormats.OpenGenericDependency1, ArgumentIndexes = new int[] { 0 } },} },

            new GenericInterfaceDependency() { Matches = x => x.StartsWith("Windows::Foundation::Collections::IObservableVector`1"),
                Dependencies = new List<GenericInterfaceDependencyBaseItem>() {
                    new GenericInterfaceDependencyItem() { Dependency_ = "Windows::Foundation::Collections::IVector`1", Format_ =  StringFormats.OpenGenericDependency1 },
                    new GenericInterfaceDependencyItem() { Dependency_ = "Windows::Foundation::Collections::VectorChangedEventHandler`1", Format_ =  StringFormats.OpenGenericDependency1 },} },
        };

        static public List<GenericInterfaceInfo> GenerateDependencyGenericInterfaces(GenericInterfaceInfo info)
        {
            var list = new List<GenericInterfaceInfo>();

            GenerateDependencyGenericInterfacesHelper(info, info, list);

            // Generation is done from top to bottom of the graph,
            // but definition needs to be done from bottom to top.
            // Return the list in reverse order so that back end get's them in the order
            // that they are needed from the compiler POV.
            list.Reverse();

            return list;
        }

        static void GenerateDependencyGenericInterfacesHelper(GenericInterfaceInfo info, GenericInterfaceInfo root, List<GenericInterfaceInfo> list)
        {
            foreach (var set in GenericInterfaceDependencies)
            {
                if (set.Matches(info.FullName))
                {
                    string arguments = null;

                    if (GenericInterfaceParser.TryGetGenericInterfaceArguments(info.FullName, out arguments))
                    {
                        foreach (var dependency in set.Dependencies)
                        {
                            string newDependency = dependency.Format(arguments);

                            if (newDependency != root.FullName && !list.Exists(x => x.FullName == newDependency))
                            {
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
                                GenerateDependencyGenericInterfacesHelper(newInfo, root, list);
                            }
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
