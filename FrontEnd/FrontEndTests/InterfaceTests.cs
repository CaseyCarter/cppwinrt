using Microsoft.VisualStudio.TestTools.UnitTesting;
using System.IO;

namespace Microsoft.Wtl.Tests
{
    [TestClass]
    public class InterfaceTests
    {
        [TestInitialize]
        public void Initialize()
        {
            var currentDirectory = Directory.GetCurrentDirectory();

            string[] winmds =
            {
                Path.Combine(currentDirectory, @"TestData\InterfacesInput\Interface1.winmd"),
                Path.Combine(currentDirectory, @"TestData\SDK\Windows.Foundation.FoundationContract.winmd")
            };

            MetadataTestHelper.RunFrontEnd(winmds);
        }

        [TestMethod]
        public void ParseInterfaces()
        {
            MetadataTestHelper.VerifyDatabaseByQuery(@"TestData\InterfacesInput",
                "Interface1.base",
                @"TestData\InterfacesInput",
                "Interface1.test",
                "SELECT * FROM Interfaces WHERE FullName NOT LIKE 'Windows::Foundation%';");
        }

        [TestMethod]
        public void ParseInterfaceMethods()
        {
            MetadataTestHelper.VerifyDatabaseByQuery(@"TestData\InterfacesInput",
                "Interface1_Methods.base",
                @"TestData\InterfacesInput",
                "Interface1_Methods.test",
                "SELECT Methods.Name, Methods.AbiName, Interfaces.FullName, Methods.Deprecated FROM Methods, Interfaces WHERE Methods.InterfaceId = Interfaces.RowId AND Interfaces.FullName NOT LIKE 'Windows::Foundation%';");
        }

        [TestMethod]
        public void ParseInterfaceMethodParameters()
        {
            MetadataTestHelper.VerifyDatabaseByQuery(@"TestData\InterfacesInput",
                "Interface1_Parameters.base",
                @"TestData\InterfacesInput",
                "Interface1_Parameters.test",
                "SELECT Parameters.Name, Parameters.Type, Parameters.ClassType, Parameters.Category, Parameters.Flags, Methods.AbiName FROM Parameters, Methods, Interfaces WHERE Parameters.MethodId = Methods.RowId AND Methods.InterfaceId = Interfaces.RowId AND Interfaces.FullName NOT LIKE 'Windows::Foundation%';");
        }

        [TestMethod]
        public void ParseInterfaceRequiredInterfaces()
        {
            MetadataTestHelper.VerifyDatabaseByQuery(@"TestData\InterfacesInput",
                "Interface1_RequiredInterfaces.base",
                @"TestData\InterfacesInput",
                "Interface1_RequiredInterfaces.test",
                "SELECT Interfaces1.FullName, Interfaces2.FullName FROM RequiredInterfaces, Interfaces Interfaces1, Interfaces Interfaces2 WHERE RequiredInterfaces.InterfaceId = Interfaces1.RowId AND RequiredInterfaces.Requires = Interfaces2.RowId AND Interfaces1.FullName NOT LIKE 'Windows::Foundation%';");
        }
    }
}