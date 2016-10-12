using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace Microsoft.Wtl.Tests
{
    [TestClass]
    public class ClassConstructors
    {
        [TestMethod]
        public void ParseClassConstructors()
        {
            MetadataTestHelper.RunBasicTest(@"TestData\ClassConstructorsInput",
                "ClassConstructors1.winmd",
                @"TestData\ClassConstructorsInput",
                "ClassConstructors1.base",
                @"TestData\ClassConstructorsInput",
                "ClassConstructors1.test",
                "SELECT Classes.FullName, Interfaces.FullName, ClassConstructors.Composable, ClassConstructors.Protected FROM ClassConstructors, Classes, Interfaces WHERE ClassConstructors.ClassId = Classes.RowId AND ClassConstructors.Interface = Interfaces.RowId;");
        }
    }
}
