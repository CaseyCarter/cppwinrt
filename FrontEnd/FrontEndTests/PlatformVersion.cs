using System;
using Microsoft.VisualStudio.TestTools.UnitTesting;
using System.IO;

namespace Microsoft.Wtl.Tests
{
    [TestClass]
    public class PlatformVersion
    {
        [TestInitialize]
        public void Initialize()
        {
            var currentDirectory = Directory.GetCurrentDirectory();

            string[] winmds =
            {
                Path.Combine(currentDirectory, @"TestData\PlatformVersion\PlatformVersion.winmd"),
                Path.Combine(currentDirectory, @"TestData\SDK\Windows.Foundation.FoundationContract.winmd")
            };

            MetadataTestHelper.RunFrontEnd(winmds);
        }

        [TestMethod]
        public void ParseClasses()
        {
            MetadataTestHelper.VerifyDatabaseByQuery(@"TestData\PlatformVersion",
                "Classes.base",
                @"TestData\PlatformVersion",
                "Classes.test",
                "SELECT FullName, Name, (SELECT FullName FROM Classes C1 WHERE C1.FullName = Classes.Base), DefaultInterface, Activatable, ifnull(Deprecated, 0) FROM Classes WHERE FullName NOT LIKE 'Windows::Foundation%' ORDER BY FullName;");
        }

        [TestMethod]
        public void ParseClassStatics()
        {
            MetadataTestHelper.VerifyDatabaseByQuery(@"TestData\PlatformVersion",
                "ClassStatics.base",
                @"TestData\PlatformVersion",
                "ClassStatics.test",
                "SELECT Classes.FullName, Interfaces.FullName FROM ClassStatics, Classes, Interfaces WHERE ClassStatics.ClassId = Classes.RowId AND Interfaces.RowId = ClassStatics.Interface AND Classes.FullName NOT LIKE 'Windows::Foundation%' ORDER BY Classes.FullName, Interfaces.FullName;");
        }

        [TestMethod]
        public void ParseClassConstructors()
        {
            MetadataTestHelper.VerifyDatabaseByQuery(@"TestData\PlatformVersion",
                "ClassConstructors.base",
                @"TestData\PlatformVersion",
                "ClassConstructors.test",
                "SELECT Classes.FullName, Interfaces.FullName, ClassConstructors.Composable, ClassConstructors.Protected FROM ClassConstructors, Classes, Interfaces WHERE ClassConstructors.ClassId = Classes.RowId AND Interfaces.RowId = ClassConstructors.Interface AND Classes.FullName NOT LIKE 'Windows::Foundation%' ORDER BY Classes.FullName, Interfaces.FullName;");
        }
    }
}
