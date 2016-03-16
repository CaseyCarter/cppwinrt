using Microsoft.Wcl.DataStore;
using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Threading.Tasks;

namespace Microsoft.Wcl.Parsers
{
    internal class GenericIntefacesPreProcessor
    {
        public GenericIntefacesPreProcessor(FrontEndConfiguration configuration)
        {
            this.Configuration = configuration;
        }

        public void Run()
        {
            // In some tests, some processing around generic interfaces is skipped
            if (!this.Configuration.SkipGenericInterfaceResolution)
            {
                this.PreProcessGenericInterfaces();
                this.GenerateGenericInterfacesIIDs();
            }
        }

        /// <summary>
        /// Some GenericInterfaces have dependencies that exists implicity, but not explicity in the metadata.
        /// For such cases, generate the dependencies and load them into the generic interfaces repository
        /// </summary>
        private void PreProcessGenericInterfaces()
        {
            List<GenericInterfaceInfo> newList = new List<GenericInterfaceInfo>();
            var genericInterfacesRepository = this.Configuration.DataStore.GetGenericInterfacesRepository();

            foreach (var info in genericInterfacesRepository.Values)
            {
                var tempList = GenerateDependencyGenericInterfaces(info);
                newList.Add(tempList);
            }

            foreach (var info in newList)
            {
                genericInterfacesRepository.Add(info.FullName, info);
            }
        }

        class GenericInterfaceDependency
        {
            public string FullTypeName;
            public IList<string> Dependencies;
        }

        static IList<GenericInterfaceDependency> GenericInterfaceDependencies = new List<GenericInterfaceDependency>()
        {
            new GenericInterfaceDependency() { FullTypeName = "Windows::Foundation::IAsyncOperation`1", Dependencies =
                new List<string>() {
                    "Windows::Foundation::AsyncOperationCompletedHandler`1" }  },
            new GenericInterfaceDependency() { FullTypeName = "Windows::Foundation::IAsyncOperationWithProgress`2",
                Dependencies = new List<string>() {
                    "Windows::Foundation::AsyncOperationWithProgressCompletedHandler`2",
                    "Windows::Foundation::AsyncOperationProgressHandler`2" } },
            new GenericInterfaceDependency() { FullTypeName = "Windows::Foundation::IAsyncActionWithProgress`1",
                Dependencies = new List<string>() {
                    "Windows::Foundation::AsyncActionWithProgressCompletedHandler`1",
                    "Windows::Foundation::AsyncActionProgressHandler`1" } },
        };

        List<GenericInterfaceInfo> GenerateDependencyGenericInterfaces(GenericInterfaceInfo info)
        {
            List<GenericInterfaceInfo> list = new List<GenericInterfaceInfo>();

            foreach (var set in GenericInterfaceDependencies)
            {
                if (info.FullName.StartsWith(set.FullTypeName))
                {
                    string arguments = null;

                    if (GenericInterfaceParser.TryGetGenericInterfaceArguments(info.FullName, out arguments))
                    {
                        foreach (var dependency in set.Dependencies)
                        {
                            string newDependency = String.Format(StringFormats.DependencyInterface, dependency, arguments);

                            GenericInterfaceInfo newInfo = new GenericInterfaceInfo()
                            {
                                FullName = newDependency,
                                Name = TypeNameUtilities.GetIndexOfTypeNameForGenericInterface(newDependency),
                                MetadataFullTypeNameInDotForm = TypeNameUtilities.GetFullTypeNameInDotForm(newDependency)
                            };

                            list.Add(newInfo);
                        }
                    }
                    else
                    {
                        throw new InvalidOperationException(String.Format(StringExceptionFormats.CouldNotParseGenericInterface, info.FullName));
                    }
                }
            }

            return list;
        }

        private bool parallelGenerateGenericInterfaces = true;

        private void GenerateGenericInterfacesIIDs()
        {
            FrontEndConfiguration.Output.WriteLine(StringMessageFormats.GeneratingGenericInterfaceIIDs);

            Stopwatch watch = new Stopwatch();
            var genericInterfacesRepository = this.Configuration.DataStore.GetGenericInterfacesRepository();

            watch.Start();

            var iidMaker = new ParameterizedTypeInstanceIID.ParameterizedTypeInstanceIIDMaker(this.Configuration.DataStore.GetRepository());

            if (parallelGenerateGenericInterfaces)
            {
                // Cut time by doing all the calculation of iids in parallel
                // In my box it reduced ~40ms (non parallel version takes ~160ms)
                Parallel.ForEach(genericInterfacesRepository.Values, (info) =>
                {
                    GenerateGenericInterfaceIID(iidMaker, info);
                });

                foreach (var info in genericInterfacesRepository.Values)
                {
                    this.Configuration.DataStore.InsertGenericInterfaceInfo(info);
                }
            }
            else
            {
                foreach (var info in genericInterfacesRepository.Values)
                {
                    GenerateGenericInterfaceIID(iidMaker, info);
                    this.Configuration.DataStore.InsertGenericInterfaceInfo(info);
                }
            }

            watch.Stop();
            FrontEndConfiguration.Output.WriteLine(StringMessageFormats.TimeGeneratingGenericInterfacesIIDs, watch.ElapsedMilliseconds);
        }

        private void GenerateGenericInterfaceIID(ParameterizedTypeInstanceIID.ParameterizedTypeInstanceIIDMaker iidMaker, GenericInterfaceInfo info)
        {
            string originalFullTypeName = info.FullName;
            string newName = null;
            if (!GenericInterfaceParser.TryGetNormalizedInterfaceFullTypeName(originalFullTypeName, out newName))
            {
                throw new InvalidOperationException(String.Format(StringExceptionFormats.CouldNotParseGenericInterface, originalFullTypeName));
            }

            info.Uuid = iidMaker.GetIID(info.MetadataFullTypeNameInDotForm).ToString();
            info.FullName = newName;
        }

        private FrontEndConfiguration Configuration { get; set; }
    }
}
