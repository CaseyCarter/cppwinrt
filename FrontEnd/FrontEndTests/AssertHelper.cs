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
            catch (Exception e)
            {
                Assert.IsTrue(e is T);
                return;
            }
            Assert.Fail(String.Format("Expected exception {0} was not thrown", typeof(T).ToString()));
        }

        public static void VerifiyThrows<T>(Action task, string message) where T : Exception
        {
            try
            {
                task();
            }
            catch (Exception e)
            {
                Assert.IsTrue(e is T);
                Assert.IsTrue(e.Message == message);
                return;
            }
            Assert.Fail(String.Format("Expected exception {0} was not thrown", typeof(T).ToString()));
        }
    }
}
