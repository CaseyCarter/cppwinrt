using Microsoft.Wcl.DataStore;
using System;
using System.Collections.Generic;
using System.Diagnostics;

namespace Microsoft.Wcl.Parsers
{
    internal class GenericIntefacesPreProcessor
    {
        private Dictionary<string, GenericInterfaceInfo> InnerGenericInterfacesTable { get; set; } = new Dictionary<string, GenericInterfaceInfo>();
        private Dictionary<string, GenericInterfaceInfo> ImplicitGenericInterfacesTable { get; set; } = new Dictionary<string, GenericInterfaceInfo>();

        public GenericIntefacesPreProcessor(FrontEndConfiguration configuration)
        {
            this.Configuration = configuration;
        }

        public void Run()
        {
            // The below steps have to be in order.
            // From the generic interfaces repository, that contains all the generic interfaces parsed from metadata
            // we need to generate few things.
            // 1. Generate the inner generic interfaces, for example, from IIterable<IVector<int>> (found in metadata), generate IVector<int>.
            //    without this, projection does not work.
            //    Add all those inner generic interfaces to the repository
            // 2. Now that we have metadata generic interfaces + inner genercit interfaces, it is now time to generate the implicit ones.
            //    For example, from IIterable<int>, an implicit inteface is IITerator<int>
            //    This is required to be done after #1, because an inner generic type may need some implicit ones.
            //    All of the new implicit generic interfaces are added to the repository.
            // 3. Generate the corresponding Uuid's for all the generic interfaces
            // 4. Now that all the data for the generic interfaces is complete, save it into the data store.

            this.GenerateInnerGenericInterfaces();
            this.GenerateImplicitGenericInterfaces();

            // In some tests, some processing around generic interfaces is skipped
            if (!this.Configuration.SkipGenericInterfaceResolution)
            {
                this.GenerateGenericInterfacesIIDs();
            }

            this.SaveGenericInterfacesInDataStore();
        }

        /// <summary>
        /// Some generic interfaces have as parameters/arguments another generic interface.
        /// For such cases, generate the inner generic interfaces and load them into the generic interfaces repository.
        /// For example, from IIterableIVector&lt;int&gt;&gt;, generate IVector&lt;int&gt;
        /// </summary>
        private void GenerateInnerGenericInterfaces()
        {
            var genericInterfacesRepository = this.Configuration.DataStore.GetGenericInterfacesRepository();
            var generatedList = new List<GenericInterfaceInfo>();

            // If we have an IVector<IVector<Point>>, we need to also add all inner generic interfaces to the repository
            // because they are needed by the projection.
            foreach (var info in genericInterfacesRepository.Values)
            {
                var tempList = InnerGenericInterfacesGeneratator.GenerateInnerGenericInterface(info);
                Debug.Assert(tempList != null);
                info.InnerGenericInterfaces = tempList;

                // No foreach so that the items can be accessed by index
                for (int i = 0; i < tempList.Count; i++)
                {
                    GenericInterfaceInfo innerInfo = tempList[i];
                    GenericInterfaceInfo infoThatExists = null;

                    if (genericInterfacesRepository.TryGetValue(innerInfo.MetadataFullTypeNameInCppForm, out infoThatExists))
                    {
                        // An inner generic interface had already been processed before (eg, it was used in a type).
                        // In such case, use that one and discard the current one
                        tempList[i] = infoThatExists;
                        innerInfo = infoThatExists;
                    }

                    // Only add to dictionary & list (to be used later on to insert first) if we don't have it already
                    if (!this.InnerGenericInterfacesTable.ContainsKey(innerInfo.MetadataFullTypeNameInCppForm))
                    {
                        this.InnerGenericInterfacesTable.Add(innerInfo.MetadataFullTypeNameInCppForm, innerInfo);
                        generatedList.Add(innerInfo);
                    }
                }
            }

            foreach (var info in generatedList)
            {
                if (!genericInterfacesRepository.ContainsKey(info.MetadataFullTypeNameInCppForm))
                {
                    genericInterfacesRepository.Add(info.MetadataFullTypeNameInCppForm, info);
                }
            }
        }

        /// <summary>
        /// Some GenericInterfaces have dependencies that exists implicity, but not explicity in the metadata.
        /// For such cases, generate the dependencies and load them into the generic interfaces repository.
        /// For example, from IIterable&lt;int>, an implicit inteface is IITerator&lt;int&gt;
        /// </summary>
        private void GenerateImplicitGenericInterfaces()
        {
            var generatedList = new List<GenericInterfaceInfo>();
            var genericInterfacesRepository = this.Configuration.DataStore.GetGenericInterfacesRepository();

            // Go over the generic interfaces repository and build a list with all the implicit ones.
            // To be used later within the front end, associate each implicit set with the one it got generated from.
            foreach (var info in genericInterfacesRepository.Values)
            {
                var tempList = ImplicitGenericInterfacesGenerator.GenerateDependencyGenericInterfaces(info);
                Debug.Assert(tempList != null);
                info.ImplicitGenericInterfaces = tempList;

                // No foreach so that the items can be accessed by index
                for (int i = 0; i < tempList.Count; i++)
                {
                    GenericInterfaceInfo implicitInfo = tempList[i];
                    GenericInterfaceInfo infoThatExists = null;

                    // An implicit generic interface had already been processed before (eg, it was used in a type).
                    // In such case, use that one and discard the current one
                    if (genericInterfacesRepository.TryGetValue(implicitInfo.MetadataFullTypeNameInCppForm, out infoThatExists))
                    {
                        tempList[i] = infoThatExists;
                        implicitInfo = infoThatExists;
                    }

                    // Only add to dictionary & list (to be used later on to insert first) if we don't have it already
                    if (!this.ImplicitGenericInterfacesTable.ContainsKey(implicitInfo.MetadataFullTypeNameInCppForm))
                    {
                        this.ImplicitGenericInterfacesTable.Add(implicitInfo.MetadataFullTypeNameInCppForm, implicitInfo);
                        generatedList.Add(implicitInfo);
                    }
                }
            }

            foreach (var info in generatedList)
            {
                if (!genericInterfacesRepository.ContainsKey(info.MetadataFullTypeNameInCppForm))
                {
                    genericInterfacesRepository.Add(info.MetadataFullTypeNameInCppForm, info);
                }
            }
        }

        /// <summary>
        /// Generate the IIDs for all the generic interfaces in the repository
        /// </summary>
        private void GenerateGenericInterfacesIIDs()
        {
            GenericInterfacesIIDsGenerator.GenerateGenericInterfacesIIDs(this.Configuration.DataStore);
        }

        /// <summary>
        /// Commit into the data store all the generic interfaces.
        /// </summary>
        private void SaveGenericInterfacesInDataStore()
        {
            var genericInterfacesRepository = this.Configuration.DataStore.GetGenericInterfacesRepository();

            foreach (var info in genericInterfacesRepository.Values)
            {
                this.Configuration.DataStore.InsertGenericInterfaceInfo(info);
            }
        }

        private FrontEndConfiguration Configuration { get; set; }
    }
}