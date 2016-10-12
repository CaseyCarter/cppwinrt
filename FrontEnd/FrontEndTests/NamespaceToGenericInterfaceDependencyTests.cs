using System;
using Microsoft.VisualStudio.TestTools.UnitTesting;
using System.IO;

namespace Microsoft.Wtl.Tests
{
    [TestClass]
    public class NamespaceToGenericInterfaceDependencyTests
    {
        [TestInitialize]
        public void Initialize()
        {
        }

        [TestMethod]
        public void ParseGenericInterfaces1()
        {
            var currentDirectory = Directory.GetCurrentDirectory();

            string[] winmds =
            {
                Path.Combine(currentDirectory, @"TestData\NamespaceToGenericInterfaceDependencyInput\NamespaceToGenericInterfaceDependency1.winmd"),
                Path.Combine(currentDirectory, @"TestData\SDK\Windows.Foundation.FoundationContract.winmd")
            };

            MetadataTestHelper.RunFrontEnd(winmds);

            // It is expected that based on the input, specific generic interfaces were generated
            MetadataTestHelper.VerifyDatabaseByQuery(@"TestData\NamespaceToGenericInterfaceDependencyInput",
                "NamespaceToGenericInterfaceDependency1.base",
                @"TestData\NamespaceToGenericInterfaceDependencyInput",
                "NamespaceToGenericInterfaceDependency1.test",
                "SELECT NamespaceToGenericInterfaceDependency.Namespace, GenericInterfaces.FullName, GenericInterfaces.RowId FROM NamespaceToGenericInterfaceDependency, GenericInterfaces WHERE NamespaceToGenericInterfaceDependency.GenericInterfaceId = GenericInterfaces.RowId ORDER BY NamespaceToGenericInterfaceDependency.RowId;");
        }

        [TestMethod]
        public void ParseGenericInterfaces2()
        {
            var currentDirectory = Directory.GetCurrentDirectory();

            string[] winmds =
            {
                Path.Combine(currentDirectory, @"TestData\NamespaceToGenericInterfaceDependencyInput\NamespaceToGenericInterfaceDependency2.winmd"),
                Path.Combine(currentDirectory, @"TestData\SDK\Windows.Foundation.FoundationContract.winmd")
            };

            MetadataTestHelper.RunFrontEnd(winmds);

            MetadataTestHelper.VerifyDatabaseByQuery(@"TestData\NamespaceToGenericInterfaceDependencyInput",
                "NamespaceToGenericInterfaceDependency2.base",
                @"TestData\NamespaceToGenericInterfaceDependencyInput",
                "NamespaceToGenericInterfaceDependency2.test",
                "SELECT NamespaceToGenericInterfaceDependency.Namespace, GenericInterfaces.FullName, GenericInterfaces.RowId FROM NamespaceToGenericInterfaceDependency, GenericInterfaces WHERE NamespaceToGenericInterfaceDependency.GenericInterfaceId = GenericInterfaces.RowId ORDER BY NamespaceToGenericInterfaceDependency.RowId;");
        }
    }
}
