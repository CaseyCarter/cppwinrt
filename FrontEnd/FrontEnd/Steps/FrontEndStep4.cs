namespace Microsoft.Wcl.Steps
{
    /// <summary>
    /// Step 4, the last one, will save the database to disk.
    /// </summary>
    class FrontEndStep4 : IFrontEndStep
    {
        public void Run(FrontEndConfiguration configuration)
        {
            this.Configuration = configuration;
            this.Configuration.DataStore.Save();
        }

        private FrontEndConfiguration Configuration { get; set; }
    }
}
