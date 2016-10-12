namespace Microsoft.Wcl.Steps
{
    /// <summary>
    /// Step 3 deals with reconciling data so that it can be consumed by the back end when the projection is built.
    /// It mainly deals with projecting metadata types to types that will are understood by the backend and/or are the actual types needed by the projection.
    /// It will finish by running a small set of semantic checks. 
    /// </summary>
    internal class FrontEndStep3 : IFrontEndStep
    {
        public void Run(FrontEndConfiguration configuration)
        {
            this.Configuration = configuration;

            FrontEndConfiguration.Output.WriteLine(StringMessageFormats.ReconcilingData);
            this.Configuration.DataStore.ReconcileData();

            this.Configuration.DataStore.VerifySemantics();
        }

        private FrontEndConfiguration Configuration { get; set; }
    }
}