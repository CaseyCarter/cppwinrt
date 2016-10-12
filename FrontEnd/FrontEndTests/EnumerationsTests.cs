using Microsoft.VisualStudio.TestTools.UnitTesting;
using System.IO;

namespace Microsoft.Wtl.Tests
{
    [TestClass]
    public class EnumerationsTests
    {
        [TestInitialize]
        public void Initialize()
        {
            var currentDirectory = Directory.GetCurrentDirectory();

            string[] winmds =
            {
                Path.Combine(currentDirectory, @"TestData\EnumerationsInput\Enumerations1.winmd"),
                Path.Combine(currentDirectory, @"TestData\SDK\Windows.Foundation.FoundationContract.winmd")
            };

            MetadataTestHelper.RunFrontEnd(winmds);
        }

        [TestMethod]
        public void ParseEnumerations()
        {
            MetadataTestHelper.VerifyDatabaseByQuery(@"TestData\EnumerationsInput",
                "Enumerations1.base",
                @"TestData\EnumerationsInput",
                "Enumerations1.test",
                "SELECT * FROM Enumerations WHERE FullName NOT LIKE 'Windows::Foundation%';");
        }

        [TestMethod]
        public void ParseEnumerationEnumerators()
        {
            MetadataTestHelper.VerifyDatabaseByQuery(@"TestData\EnumerationsInput",
                "Enumerations1_Enumerators.base",
                @"TestData\EnumerationsInput",
                "Enumerations1_Enumerators.test",
                "SELECT Enumerators.Name, Enumerators.Value, Enumerations.FullName, Enumerators.Deprecated FROM Enumerators, Enumerations WHERE Enumerators.EnumerationId = Enumerations.RowId AND Enumerations.FullName NOT LIKE 'Windows::Foundation%';");
        }
    }
}
