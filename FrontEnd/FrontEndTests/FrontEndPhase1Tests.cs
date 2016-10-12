using Microsoft.VisualStudio.TestTools.UnitTesting;
using Microsoft.Wcl;
using System.Collections.Generic;
using System.IO;

namespace Microsoft.Wtl.Tests
{
    internal class FrontEndPhase1Test : Wcl.Steps.FrontEndStep1
    {
        public Wcl.FrontEndConfiguration GetConfiguration()
        {
            return this.Configuration;
        }
    }


    [TestClass]
    public class FrontEndPhase1Tests
    {
        [TestMethod]
        public void WinmdListIsUpdatedAfterRun()
        {
            var configuration = new Wcl.FrontEndConfiguration();
            var phase1 = new FrontEndPhase1Test();
            var winmds = new List<string>();

            var file1 = Path.Combine(Directory.GetCurrentDirectory(), "foo.winmd");
            var file2 = Path.Combine(Directory.GetCurrentDirectory(), "bar.winmd");

            var files = new string[] { file1, file2 };

            foreach (var file in files)
            {
                using (File.Create(file)) { };
                winmds.Add(file);
            }

            configuration.Arguments.Add("winmd", new Wcl.Argument("winmd", winmds.ToArray()));
            phase1.Run(configuration);
            Assert.IsNotNull(phase1.GetConfiguration().Winmds);
            var resultList = phase1.GetConfiguration().Winmds;

            for (int i = 0; i < winmds.Count; i++)
            {
                Assert.AreEqual(winmds[i], resultList[i]);
            }

            foreach (var file in files)
            {
                File.Delete(file);
            }
        }

        [TestMethod]
        public void ConfigurationIsUpdatedAfterRun()
        {
            var configuration = new Wcl.FrontEndConfiguration();
            var phase1 = new FrontEndPhase1Test();

            var file1 = Path.Combine(Directory.GetCurrentDirectory(), "foo1.winmd");
            using (File.Create(file1)) { };

            configuration.Arguments.Add("winmd", new Wcl.Argument("winmd", new string[] { file1 } ));
            phase1.Run(configuration);

            Assert.IsNotNull(phase1.GetConfiguration().DataStore);
            Assert.IsNotNull(phase1.GetConfiguration().Arguments);
            Assert.IsNotNull(phase1.GetConfiguration().Winmds);

            File.Delete(file1);
        }

        [TestMethod]
        public void MissingWinmdThrowsExceptionDuringRun()
        {
            var configuration = new Wcl.FrontEndConfiguration();
            FrontEndPhase1Test phase1 = new FrontEndPhase1Test();

            var file1 = Path.Combine(Directory.GetCurrentDirectory(), "foo1.winmd");
            configuration.Arguments.Add("winmd", new Wcl.Argument("winmd", new string[] { file1 }));

            AssertHelper.VerifiyThrows<Wcl.Steps.WinmdFileNotFoundException>(() => phase1.Run(configuration), string.Format(StringExceptionFormats.WinmdFileNotFound, file1));
        }
    }
}
