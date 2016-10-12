using Microsoft.VisualStudio.TestTools.UnitTesting;
using System.Collections.Generic;

namespace Microsoft.Wtl.Tests
{
    [TestClass]
    public class ArgumentValidatorTests
    {
        [TestMethod]
        public void ValidateSingleWinmd()
        {
            var validator = new Wcl.ArgumentValidator();
            var name = "winmd";
            var values = new string[] { "1" };

            var status = validator.Validate(name, values);
            Assert.AreEqual(Wcl.ArgumentStatus.Ok, status);
        }

        [TestMethod]
        public void ValidateMultipleWinmd()
        {
            var validator = new Wcl.ArgumentValidator();
            var name = "winmd";
            var values = new string[] { "1", "2", "3" };

            var status = validator.Validate(name, values);
            Assert.AreEqual(Wcl.ArgumentStatus.Ok, status);
        }

        [TestMethod]
        public void ValidateNoWinmd()
        {
            var validator = new Wcl.ArgumentValidator();
            var name = "winmd";
            var values = new List<string>();

            var status = validator.Validate(name, values);
            Assert.AreEqual(Wcl.ArgumentStatus.Invalid, status);
        }

        public void ValidateHelp()
        {
            var validator = new Wcl.ArgumentValidator();
            var name = "?";
            var values = new string[] { "1" };

            var status = validator.Validate(name, values);
            Assert.AreEqual(Wcl.ArgumentStatus.Ok, status);
        }
    }
}
