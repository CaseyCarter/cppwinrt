using Microsoft.Wcl.DataStore;
using Microsoft.Wcl.ParameterizedTypeInstanceIID;
using Microsoft.Wcl.Parsers;
using System;
using System.Diagnostics;

namespace Microsoft.Wcl.Steps
{
    /// <summary>
    /// Step 2 deals with processing all the metadata and doing some processing on certain types which need to be derived from the data read from the winmds 
    /// </summary>
    internal class FrontEndStep2 : IFrontEndStep
    {
        public void Run(FrontEndConfiguration configuration)
        {
            this.Configuration = configuration;

            var parser = new FrontEndMetadataParser();
            parser.Initialize(this.Configuration);

            FrontEndConfiguration.Output.WriteLine(StringMessageFormats.ProcessingWinmds);
            parser.ProcessMetadata();

            // Before moving on, pre process (massage) the data where needed and commit to the DataStore.
            // This is done to cover the gaps between what the metadata contains and what is needed at the DataStore level.
            var dataStorePreProcessor = new GenericIntefacesPreProcessor(configuration);
            dataStorePreProcessor.Run();

            this.Configuration.DataStore.UpdateSchema();
        }

        private FrontEndConfiguration Configuration { get; set; }
    }
}
