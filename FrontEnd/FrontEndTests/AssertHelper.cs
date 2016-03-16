using Microsoft.VisualStudio.TestTools.UnitTesting;
using System;

namespace Microsoft.Wtl.Tests
{
    internal class AssertHelper
    {
        public static void VerifiyThrows<T>(Action task) where T : Exception
        {
            try
            {
                task();
            }
            catch (Exception ex)
            {
                Assert.IsTrue(ex is T);
                return;
            }
            Assert.Fail("Expected was not thrown");
        }
    }
}
