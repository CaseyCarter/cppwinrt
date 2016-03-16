using Microsoft.VisualStudio.TestTools.UnitTesting;

using Wcl = Microsoft.Wcl;
using Microsoft.Wtl.Tests;

namespace FrontEndTests
{
    [TestClass]
    public class ArgumentsTests
    {
        [TestMethod]
        public void ParameterCanUseDash()
        {
            HelperForValidate("-");
        }

        [TestMethod]
        public void ParameterCanUseForwardSlash()
        {
            HelperForValidate("/");
        }

        public void HelperForValidate(string argumentDelimiter)
        {
            const string parameterName = "winmd";
            string[] args = new string[] { argumentDelimiter + parameterName };

            Wcl.ArgumentsParser arguments = new Microsoft.Wcl.ArgumentsParser(args);
            arguments.Parse();

            Assert.IsNotNull(arguments.ArgumentsDictionary);
            Assert.AreEqual(arguments.ArgumentsDictionary.Count, 1);
            Assert.IsTrue(arguments.ArgumentsDictionary.ContainsKey(parameterName));

            Wcl.Argument argument = null;
            Assert.IsTrue(arguments.ArgumentsDictionary.TryGetValue(parameterName, out argument));
            Assert.AreEqual(parameterName, argument.Name);
        }

        [TestMethod]
        public void ParameterWithOneValidValue()
        {
            const string parameterName = "winmd";
            const string parameterValue = @"c:\my foo\foo.winmd";
            string[] args = new string[] { "-" + parameterName, parameterValue };

            Wcl.ArgumentsParser arguments = new Microsoft.Wcl.ArgumentsParser(args);

            arguments.Parse();

            Assert.IsNotNull(arguments.ArgumentsDictionary);
            Assert.AreEqual(arguments.ArgumentsDictionary.Count, 1);
            Assert.IsTrue(arguments.ArgumentsDictionary.ContainsKey(parameterName));

            Wcl.Argument argument = null;
            Assert.IsTrue(arguments.ArgumentsDictionary.TryGetValue(parameterName, out argument));
            Assert.AreEqual(parameterName, argument.Name);

            Assert.AreEqual(argument.Values.Count, 1);
            Assert.AreEqual(parameterName, argument.Name);
            Assert.AreEqual(parameterValue, argument.Values[0]);
        }

        [TestMethod]
        public void ParameterWithTwoValidValues()
        {
            const string parameterName = "winmd";
            const string parameterValue1 = @"c:\my foo\foo.winmd";
            const string parameterValue2 = @"bar.winmd";
            string[] args = new string[] { "-" + parameterName, parameterValue1, parameterValue2 };

            Wcl.ArgumentsParser arguments = new Microsoft.Wcl.ArgumentsParser(args);

            arguments.Parse();

            Assert.IsNotNull(arguments.ArgumentsDictionary);
            Assert.AreEqual(arguments.ArgumentsDictionary.Count, 1);
            Assert.IsTrue(arguments.ArgumentsDictionary.ContainsKey(parameterName));

            Wcl.Argument argument = null;
            Assert.IsTrue(arguments.ArgumentsDictionary.TryGetValue(parameterName, out argument));
            Assert.AreEqual(parameterName, argument.Name);
            Assert.AreEqual(2, argument.Values.Count);
            Assert.AreEqual(parameterValue1, argument.Values[0]);
            Assert.AreEqual(parameterValue2, argument.Values[1]);
        }

        [TestMethod]
        public void TwoParametersOneWithValues()
        {
            const string parameterName1 = "winmd";
            const string parameterValue1 = @"c:\my foo\foo.winmd";
            const string parameterValue2 = @"bar.winmd";
            const string parameterName2 = "noinclude";

            string[] args = new string[] { "-" + parameterName1, parameterValue1, parameterValue2, "-" + parameterName2 };

            Wcl.ArgumentsParser arguments = new Microsoft.Wcl.ArgumentsParser(args);
            arguments.Parse();

            Assert.IsNotNull(arguments.ArgumentsDictionary);
            Assert.AreEqual(arguments.ArgumentsDictionary.Count, 2);

            Wcl.Argument argument = null;
            Assert.IsTrue(arguments.ArgumentsDictionary.TryGetValue(parameterName1, out argument));
            Assert.AreEqual(parameterName1, argument.Name);
            Assert.AreEqual(2, argument.Values.Count);
            Assert.AreEqual(parameterValue1, argument.Values[0]);
            Assert.AreEqual(parameterValue2, argument.Values[1]);

            Assert.IsTrue(arguments.ArgumentsDictionary.TryGetValue(parameterName2, out argument));
            Assert.AreEqual(parameterName2, argument.Name);
        }

        [TestMethod]
        public void TwoParametersBothWithValues()
        {
            const string parameterName1 = "winmd";
            const string parameterValue11 = @"c:\my foo\foo.winmd";
            const string parameterValue12 = @"bar.winmd";
            const string parameterName2 = "winmd2";
            const string parameterValue21 = @"c:\my foo2\foo2.winmd";
            const string parameterValue22 = @"bar2.winmd";
            string[] args = new string[] { "-" + parameterName1, parameterValue11, parameterValue12, "-" + parameterName2, parameterValue21, parameterValue22 };

            Wcl.ArgumentsParser arguments = new Microsoft.Wcl.ArgumentsParser(args);

            arguments.Parse();

            Assert.IsNotNull(arguments.ArgumentsDictionary);
            Assert.AreEqual(arguments.ArgumentsDictionary.Count, 2);
            Assert.IsTrue(arguments.ArgumentsDictionary.ContainsKey(parameterName1));

            Wcl.Argument argument = null;
            Assert.IsTrue(arguments.ArgumentsDictionary.TryGetValue(parameterName1, out argument));
            Assert.AreEqual(parameterName1, argument.Name);
            Assert.AreEqual(2, argument.Values.Count);
            Assert.AreEqual(parameterValue11, argument.Values[0]);
            Assert.AreEqual(parameterValue12, argument.Values[1]);

            Assert.IsTrue(arguments.ArgumentsDictionary.TryGetValue(parameterName2, out argument));
            Assert.AreEqual(parameterName2, argument.Name);
            Assert.AreEqual(2, argument.Values.Count);
            Assert.AreEqual(parameterValue21, argument.Values[0]);
            Assert.AreEqual(parameterValue22, argument.Values[1]);
        }

        [TestMethod]
        public void OneInvalidParameter()
        {
            const string parameterName1 = "winmd";
            string[] args = new string[] { parameterName1 };

            Wcl.ArgumentsParser arguments = new Microsoft.Wcl.ArgumentsParser(args);

            AssertHelper.VerifiyThrows<Wcl.ArgumentsParseException>(() => arguments.Parse());
            Assert.IsNull(arguments.ArgumentsDictionary);
        }

        [TestMethod]
        public void TwoParametersOneInvalid()
        {
            const string parameterName1 = "winmd";
            const string parameterName2 = "noinclude";
            string[] args = new string[] { parameterName1, "-" + parameterName2};

            Wcl.ArgumentsParser arguments = new Microsoft.Wcl.ArgumentsParser(args);

            AssertHelper.VerifiyThrows<Wcl.ArgumentsParseException>(() => arguments.Parse());
            Assert.IsNull(arguments.ArgumentsDictionary);
        }

        [TestMethod]
        public void NoParameters()
        {
            string[] args = new string[0];

            Wcl.ArgumentsParser arguments = new Microsoft.Wcl.ArgumentsParser(args);
            arguments.Parse();

            Assert.IsNotNull(arguments.ArgumentsDictionary);
            Assert.AreEqual(0, arguments.ArgumentsDictionary.Count);
        }

        [TestMethod]
        public void InvalidParameterDueToNoDashOrForwardSlash()
        {
            const string parameterName = "winmd";
            string[] args = new string[] { "*" + parameterName };

            Wcl.ArgumentsParser arguments = new Microsoft.Wcl.ArgumentsParser(args);
            AssertHelper.VerifiyThrows<Wcl.ArgumentsParseException>(() => arguments.Parse());
            Assert.IsNull(arguments.ArgumentsDictionary);
        }

        [TestMethod]
        public void ParameterUsesTwoDashesParameterNameHasOneOfThem()
        {
            const string parameterName = "-winmd";
            string[] args = new string[] { "-" + parameterName };

            Wcl.ArgumentsParser arguments = new Microsoft.Wcl.ArgumentsParser(args);
            arguments.Parse();

            Assert.IsNotNull(arguments.ArgumentsDictionary);
            Assert.AreEqual(arguments.ArgumentsDictionary.Count, 1);

            Wcl.Argument argument = null;
            Assert.IsTrue(arguments.ArgumentsDictionary.TryGetValue(parameterName, out argument));
            Assert.AreEqual(parameterName, argument.Name);
        }
    }
}