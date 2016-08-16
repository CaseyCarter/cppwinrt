using System;
using Microsoft.VisualStudio.TestTools.UnitTesting;
using System.IO;

namespace Microsoft.Wtl.Tests
{
    [TestClass]
    public class InnerGenericInterfacesTests
    {
        [TestInitialize]
        public void Initialize()
        {
            var currentDirectory = Directory.GetCurrentDirectory();
            
            string[] winmds =
            {
                Path.Combine(currentDirectory, @"TestData\GenericInterfacesInput\InnerGenericInterfaces1.winmd"),
                Path.Combine(currentDirectory, @"TestData\SDK\Windows.Foundation.FoundationContract.winmd")
            };

            MetadataTestHelper.RunFrontEnd(winmds);
        }

        [TestMethod]
        public void ParseGenericInterfaces()
        {
            // It is expected that based on the input, specific generic interfaces were generated
            MetadataTestHelper.VerifyDatabaseByQuery(@"TestData\GenericInterfacesInput",
                "InnerGenericInterfaces1.base",
                @"TestData\GenericInterfacesInput",
                "InnerGenericInterfaces1.test",
                "SELECT * FROM GenericInterfaces ORDER BY RowId;");
        }
    }
}
