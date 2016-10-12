using Microsoft.Wcl.DataStore;
using Microsoft.Wcl.NamespaceDependencies;
using Microsoft.Wcl.Parsers;

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

            // Resolve misc dependencies namespaces have, like generic interfaces, other namespaces and such.
            // *** NOTE: This has to be the last action within this step because it uses the generic interfaces added in previous lines.
            var namespaceDependepenciesResolver = new NamespaceDependenciesResolver(this.Configuration);
            namespaceDependepenciesResolver.ResolveAndInsertIntoRepository();

            this.Configuration.DataStore.UpdateSchema();

            FrontEndConfiguration.Output.WriteLine(StringMessageFormats.TimeInsertingToDatabase, FrontEndDatabase.watch.ElapsedMilliseconds);
        }

        private FrontEndConfiguration Configuration { get; set; }
    }
}
