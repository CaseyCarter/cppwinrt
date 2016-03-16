using System.Collections.Generic;

using Microsoft.Wcl.DataStore;
using Microsoft.Wcl.Parsers;

namespace Microsoft.Wcl
{
    internal class FrontEndConfiguration
    {
        public FrontEndConfiguration()
        {
            this.Arguments = new Dictionary<string, Argument>();
            this.Winmds = new List<string>();
            this.SkipGenericInterfaceResolution = false;
        }

        public IDataStore DataStore { get; set; }

        public IDictionary<string, Argument> Arguments { get; protected set; }

        public IList<string> Winmds { get; protected set; }

        public string DataStoreLocation { get; set; }

        internal bool SkipGenericInterfaceResolution { get; set; }

        public static IOutput Output = new ConsoleBasedOutput();
    }
}