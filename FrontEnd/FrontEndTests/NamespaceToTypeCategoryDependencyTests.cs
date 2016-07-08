using System;
using Microsoft.VisualStudio.TestTools.UnitTesting;
using System.IO;

namespace Microsoft.Wtl.Tests
{
    [TestClass]
    public class NamespaceToTypeCategoryDependencyTests
    {
        [TestInitialize]
        public void Initialize()
        {
            var currentDirectory = Directory.GetCurrentDirectory();

            string[] winmds =
            {
                Path.Combine(currentDirectory, @"TestData\NamespaceToTypeCategoryDependencyInput\NamespaceToTypeCategoryDependency1.winmd"),
                Path.Combine(currentDirectory, @"TestData\SDK\Windows.Foundation.FoundationContract.winmd")
            };

            MetadataTestHelper.RunFrontEnd(winmds);
        }

        [TestMethod]
        public void ParseNamespaceToTypeCategoryDependency()
        {
            MetadataTestHelper.VerifyDatabaseByQuery(@"TestData\NamespaceToTypeCategoryDependencyInput",
                "NamespaceToTypeCategoryDependency1.base",
                @"TestData\NamespaceToTypeCategoryDependencyInput",
                "NamespaceToTypeCategoryDependency1.test",
                "SELECT * FROM NamespaceToTypeCategoryDependency ORDER BY RowId;");
        }
    }
}
