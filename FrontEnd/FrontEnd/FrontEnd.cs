using System.Collections.Generic;

namespace Microsoft.Wcl.Steps
{
    internal class FrontEnd
    {
        public void Initialize()
        {
            this.Phases = new List<IFrontEndStep>();
            // Parse arguments and prepare database
            this.Phases.Add(new FrontEndStep1());
            // Parse metadata and pre process the data in the database
            this.Phases.Add(new FrontEndStep2());
            // Updates to database schema & reconcile data
            this.Phases.Add(new FrontEndStep3());
            // Save the database to disk
            this.Phases.Add(new FrontEndStep4());
        }

        public void Run(FrontEndConfiguration configuration)
        {
            foreach (var phase in this.Phases)
            {
                phase.Run(configuration);
            }
        }

        private IList<IFrontEndStep> Phases { get; set; }
    }
}
