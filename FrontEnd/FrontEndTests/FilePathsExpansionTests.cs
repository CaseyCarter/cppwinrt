using System;
using Microsoft.VisualStudio.TestTools.UnitTesting;
using System.IO;

namespace Microsoft.Wtl.Tests
{
    [TestClass]
    public class FilePathsExpansionTests
    {
        const string environmentVariableName = "FRONT_END_CURRENT_DIRECTORY";
        readonly string enviromentVariable;

        public FilePathsExpansionTests()
        {
            enviromentVariable = string.Format("%{0}%", environmentVariableName);
        }

        [TestInitialize]
        public void Initialize()
        {
            var currentDirectory = Directory.GetCurrentDirectory();
            System.Environment.SetEnvironmentVariable(environmentVariableName, currentDirectory, EnvironmentVariableTarget.Process);
        }

        [TestCleanup]
        public void Cleanup()
        {
            System.Environment.SetEnvironmentVariable(environmentVariableName, null);
        }

        [TestMethod]
        public void TestMethod1()
        {
            string winmd = string.Format(@"{0}\{1}", enviromentVariable, @"TestData\SDK\Windows.Foundation.FoundationContract.winmd");

            string[] winmds =
            {
                winmd
            };

            MetadataTestHelper.RunFrontEnd(winmds);
        }

        [TestMethod]
        public void DatabasePath()
        {
            var currentDirectory = Directory.GetCurrentDirectory();
            string winmd = Path.Combine(currentDirectory, @"TestData\SDK\Windows.Foundation.FoundationContract.winmd");
            string databaseLocation = string.Format(@"{0}\{1}", enviromentVariable, @"output.db");

            string[] winmds =
            {
                winmd
            };

            MetadataTestHelper.RunFrontEnd(winmds, true, databaseLocation);

            Assert.IsTrue(System.IO.File.Exists(System.Environment.ExpandEnvironmentVariables(databaseLocation)));

            File.Delete(System.Environment.ExpandEnvironmentVariables(databaseLocation));
        }
    }
}
