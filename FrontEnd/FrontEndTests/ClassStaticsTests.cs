using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace Microsoft.Wtl.Tests
{
    [TestClass]
    public class ClassStaticsTests
    {
        [TestMethod]
        public void ParseClassStatics()
        {
            MetadataTestHelper.RunBasicTest(@"TestData\ClassStaticsInput",
                "ClassStatics1.winmd",
                @"TestData\ClassStaticsInput",
                "ClassStatics1.base",
                @"TestData\ClassStaticsInput",
                "ClassStatics1.test",
                "SELECT Classes.FullName, Interfaces.FullName FROM ClassStatics, Classes, Interfaces WHERE ClassStatics.ClassId = Classes.RowId AND ClassStatics.Interface = Interfaces.RowId;");
        }
    }
}
