using Microsoft.VisualStudio.TestTools.UnitTesting;
using System.IO;

namespace Microsoft.Wtl.Tests
{
    [TestClass]
    public class StructuresTests
    {
        [TestInitialize]
        public void Initialize()
        {
            var currentDirectory = Directory.GetCurrentDirectory();

            string[] winmds =
            {
                Path.Combine(currentDirectory, @"TestData\StructuresInput\Structures1.winmd"),
                Path.Combine(currentDirectory, @"TestData\SDK\Windows.Foundation.FoundationContract.winmd")
            };

            MetadataTestHelper.RunFrontEnd(winmds);
        }

        [TestMethod]
        public void ParseStructures()
        {
            MetadataTestHelper.VerifyDatabaseByQuery(@"TestData\StructuresInput",
                "Structures1.base",
                @"TestData\StructuresInput",
                "Structures1.test",
                "SELECT * FROM Structures WHERE FullName NOT LIKE 'Windows::Foundation%';");
        }

        [TestMethod]
        public void ParseStructureFields()
        {
            MetadataTestHelper.VerifyDatabaseByQuery(@"TestData\StructuresInput",
                "Structures1_Fields.base",
                @"TestData\StructuresInput",
                "Structures1_Fields.test",
                "SELECT Fields.Name, Fields.Type, Fields.Category, Structures.FullName FROM Fields, Structures WHERE Fields.StructureId = Structures.RowId AND Structures.FullName NOT LIKE 'Windows::Foundation%';");
        }
    }
}
