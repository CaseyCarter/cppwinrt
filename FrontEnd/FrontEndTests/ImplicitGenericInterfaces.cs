using System;
using Microsoft.VisualStudio.TestTools.UnitTesting;
using System.IO;

namespace Microsoft.Wtl.Tests
{
    [TestClass]
    public class ImplicitGenericInterfaces
    {
        [TestInitialize]
        public void Initialize()
        {
            var currentDirectory = Directory.GetCurrentDirectory();

            string[] winmds =
            {
                Path.Combine(currentDirectory, @"TestData\GenericInterfacesInput\ImplicitGenericInterfaces1.winmd"),
                Path.Combine(currentDirectory, @"TestData\SDK\Windows.Foundation.FoundationContract.winmd")
            };

            MetadataTestHelper.RunFrontEnd(winmds);
        }

        [TestMethod]
        public void ParseGenericInterfaces()
        {
            // It is expected that based on the input, specific generic interfaces were generated
            MetadataTestHelper.VerifyDatabaseByQuery(@"TestData\GenericInterfacesInput",
                "ImplicitGenericInterfaces1.base",
                @"TestData\GenericInterfacesInput",
                "ImplicitGenericInterfaces1.test",
                "SELECT * FROM GenericInterfaces ORDER BY RowId;");
        }
    }
}
