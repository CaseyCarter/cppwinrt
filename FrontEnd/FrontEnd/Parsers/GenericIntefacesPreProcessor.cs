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
            this.GenerateImplicitGenericInterfaces();

            // In some tests, some processing around generic interfaces is skipped
            if (!this.Configuration.SkipGenericInterfaceResolution)
            {
                this.GenerateGenericInterfacesIIDs();
            }
        }

        private void GenerateGenericInterfacesIIDs()
        {
            GenericInterfacesIIDsGenerator.GenerateGenericInterfacesIIDs(this.Configuration.DataStore);

            var genericInterfacesRepository = this.Configuration.DataStore.GetGenericInterfacesRepository();
            foreach (var info in genericInterfacesRepository.Values)
            {
                this.Configuration.DataStore.InsertGenericInterfaceInfo(info);
            }
        }

        /// <summary>
        /// Some GenericInterfaces have dependencies that exists implicity, but not explicity in the metadata.
        /// For such cases, generate the dependencies and load them into the generic interfaces repository
        /// </summary>
        private void GenerateImplicitGenericInterfaces()
        {
            List<GenericInterfaceInfo> newList = new List<GenericInterfaceInfo>();
            var genericInterfacesRepository = this.Configuration.DataStore.GetGenericInterfacesRepository();

            foreach (var info in genericInterfacesRepository.Values)
            {
                var tempList = ImplicitGenericInterfacesGenerator.GenerateDependencyGenericInterfaces(info);
                newList.Add(tempList);
            }

            foreach (var info in newList)
            {
                if (!genericInterfacesRepository.ContainsKey(info.FullName))
                {
                    genericInterfacesRepository.Add(info.FullName, info);
                }
            }
        }

        private FrontEndConfiguration Configuration { get; set; }
    }
}