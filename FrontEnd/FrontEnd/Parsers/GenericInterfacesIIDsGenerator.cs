using Microsoft.Wcl.DataStore;
using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Microsoft.Wcl.Parsers
{
    class GenericInterfacesIIDsGenerator
    {
        static bool parallelGenerateGenericInterfaces = true;

        static public void GenerateGenericInterfacesIIDs(IDataStore dataStore)
        {
            FrontEndConfiguration.Output.WriteLine(StringMessageFormats.GeneratingGenericInterfaceIIDs);

            var watch = new Stopwatch();
            var genericInterfacesRepository = dataStore.GetGenericInterfacesRepository();

            watch.Start();

            var iidMaker = new ParameterizedTypeInstanceIID.ParameterizedTypeInstanceIIDMaker(dataStore.GetRepository());

            if (parallelGenerateGenericInterfaces)
            {
                // Cut time by doing all the calculation of iids in parallel
                // In my box it reduced ~40ms (non parallel version takes ~160ms)
                Parallel.ForEach(genericInterfacesRepository.Values, (info) =>
                {
                    GenerateGenericInterfaceIID(iidMaker, info);
                });
            }
            else
            {
                foreach (var info in genericInterfacesRepository.Values)
                {
                    GenerateGenericInterfaceIID(iidMaker, info);
                }
            }

            watch.Stop();
            FrontEndConfiguration.Output.WriteLine(StringMessageFormats.TimeGeneratingGenericInterfacesIIDs, watch.ElapsedMilliseconds);
        }

        static private void GenerateGenericInterfaceIID(ParameterizedTypeInstanceIID.ParameterizedTypeInstanceIIDMaker iidMaker, GenericInterfaceInfo info)
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
    }
}
