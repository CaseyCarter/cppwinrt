using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace Microsoft.Wtl.Tests
{
    [TestClass]
    public class RuntimeclassTests
    {
        [TestMethod]
        public void ParseRuntimeclasses()
        {
            MetadataTestHelper.RunBasicTest(@"TestData\RuntimeclassInput", 
                "Runtimeclass1.winmd",
                @"TestData\RuntimeclassInput",
                "1Runtimeclass.base",
                @"TestData\RuntimeclassInput",
                "1Runtimeclass.test",
                "SELECT * FROM Classes;");
        }
    }
}
