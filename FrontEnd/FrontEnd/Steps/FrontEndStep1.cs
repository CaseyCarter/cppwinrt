using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.IO;

using Microsoft.Wcl.DataStore;

namespace Microsoft.Wcl.Steps
{
    internal class MissingWimdException : Exception
    {
        public MissingWimdException(string winmd) : base(String.Format(StringExceptionFormats.MissingWinmd, winmd))
        {            
        }
    }

    /// <summary>
    /// Step1 deals with preparing the database for writes and checking that all the winmds are present
    /// </summary>
    internal class FrontEndStep1 : IFrontEndStep
    {
        public void Run(FrontEndConfiguration configuration)
        {
            this.Configuration = configuration;

            FrontEndConfiguration.Output.WriteLine(StringMessageFormats.InitializingDatabase);
            this.InitializeDatabase();
            this.CheckAndUpdateDataStoreLocation();

            FrontEndConfiguration.Output.WriteLine(StringMessageFormats.VerifyingWinmds);
            this.CheckAndUpdateConfigurationWinmds();
        }

        private void InitializeDatabase()
        {
            FrontEndDatabase database = new FrontEndDatabase(this.Configuration);
            database.Initialize();

            this.Configuration.DataStore = (IDataStore)database;
        }

        private void CheckAndUpdateConfigurationWinmds()
        {
            Debug.Assert(this.Configuration.Arguments.ContainsKey(WinmdArgumentValue));

            // Required argument. If not present, it will bail here.
            var winmdArgument = this.Configuration.Arguments[WinmdArgumentValue];

            CheckWinmdsExists(winmdArgument.Values);
            this.Configuration.Winmds.Add(winmdArgument.Values);
        }

        private void CheckWinmdsExists(IList<string> winmds)
        {
            foreach (var winmd in winmds)
            {
                if (!File.Exists(winmd))
                {
                    throw new MissingWimdException(winmd);
                }
            }
        }

        private void CheckAndUpdateDataStoreLocation()
        {
            Argument dbArgument = null;

            if (this.Configuration.Arguments.TryGetValue(DatabaseArgumentValue, out dbArgument))
            {
                Debug.Assert(dbArgument.Values.Count == 1);
                this.Configuration.DataStoreLocation = dbArgument.Values[0];
            }
            else
            {
                this.Configuration.DataStoreLocation = DefaultDatabaseFileName;
            }
        }

        protected FrontEndConfiguration Configuration { get; set; }

        private const string DefaultDatabaseFileName = "winrt.db";
        private const string WinmdArgumentValue = "winmd";
        private const string DatabaseArgumentValue = "db";
    }
}