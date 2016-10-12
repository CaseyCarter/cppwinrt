using System;
using Microsoft.VisualStudio.TestTools.UnitTesting;
using System.IO;

namespace Microsoft.Wtl.Tests
{
    [TestClass]
    public class ImplicitGenericInterfaces
    {
        [TestMethod]
        public void ParseGenericInterfaces1()
        {
            var currentDirectory = Directory.GetCurrentDirectory();

            string[] winmds =
            {
                Path.Combine(currentDirectory, @"TestData\GenericInterfacesInput\ImplicitGenericInterfaces1.winmd"),
                Path.Combine(currentDirectory, @"TestData\SDK\Windows.Foundation.FoundationContract.winmd")
            };

            MetadataTestHelper.RunBasicTest(winmds,
                @"TestData\GenericInterfacesInput",
                "ImplicitGenericInterfaces1.base",
                @"TestData\GenericInterfacesInput",
                "ImplicitGenericInterfaces1.test",
                "SELECT * FROM GenericInterfaces ORDER BY RowId;");
        }

        [TestMethod]
        public void ParseGenericInterfaces2()
        {
            var currentDirectory = Directory.GetCurrentDirectory();

            string[] winmds =
            {
                Path.Combine(currentDirectory, @"TestData\GenericInterfacesInput\ImplicitGenericInterfaces2.winmd"),
                Path.Combine(currentDirectory, @"TestData\SDK\Windows.Foundation.FoundationContract.winmd")
            };

            MetadataTestHelper.RunBasicTest(winmds,
                @"TestData\GenericInterfacesInput",
                "ImplicitGenericInterfaces2.base",
                @"TestData\GenericInterfacesInput",
                "ImplicitGenericInterfaces2.test",
                "SELECT * FROM GenericInterfaces ORDER BY RowId;");
        }
    }
}
