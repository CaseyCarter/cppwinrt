using Microsoft.VisualStudio.TestTools.UnitTesting;

using Microsoft.Wcl;
using System.Collections.Generic;
using System.IO;

namespace Microsoft.Wtl.Tests
{

    class ResponseFileParserTest : ResponseFileParser
    { 
        public IList<string> ParseResponseFileContentHelper(string input)
        {
            return this.ParseResponseFileContent(input);
        }
    }

    [TestClass]
    public class ResponseFileTests
    {
        [TestMethod]
        public void OneParameter_OneValidValueWithSpaces()
        {
            var name = "-winmd";
            var value = "C:\\Program Files (x86)\\Windows Kits\\10\\References\\Windows.Foundation.FoundationContract\\1.0.0.0\\Windows.Foundation.FoundationContract.winmd";
            var input = string.Format("{0} \"{1}\"", name, value);
            var parser = new ResponseFileParserTest();
            var list = parser.ParseResponseFileContentHelper(input);

            Assert.AreEqual(2, list.Count);
            Assert.AreEqual(name, list[0]);
            Assert.AreEqual(value, list[1]);
        }

        [TestMethod]
        public void OneParameter_TwoValidValuesWithSpaces()
        {
            var name = "-winmd";
            var value1 = "C:\\Program Files (x86)\\Windows Kits\\10\\References\\Windows.Foundation.FoundationContract\\1.0.0.0\\Windows.Foundation.FoundationContract.winmd";
            var value2 = "C:\\Program Files (x86)\\Windows Kits\\10\\References\\Windows.Foundation.UniversalApiContract\\1.0.0.0\\Windows.Foundation.UniversalApiContract.winmd";
            var input = string.Format("{0} \"{1}\" \"{2}\"", name, value1, value2);
            var parser = new ResponseFileParserTest();
            var list = parser.ParseResponseFileContentHelper(input);

            Assert.AreEqual(3, list.Count);
            Assert.AreEqual(name, list[0]);
            Assert.AreEqual(value1, list[1]);
            Assert.AreEqual(value2, list[2]);
        }

        [TestMethod]
        public void OneParameter_OneValidValueNoSpaces()
        {
            var name = "-winmd";
            var value = "Windows.Foundation.FoundationContract.winmd";
            var input = string.Format("{0} \"{1}\"", name, value);
            var parser = new ResponseFileParserTest();
            var list = parser.ParseResponseFileContentHelper(input);

            Assert.AreEqual(2, list.Count);
            Assert.AreEqual(name, list[0]);
            Assert.AreEqual(value, list[1]);
        }

        [TestMethod]
        public void OneParameter_TwoValidValuesNoSpaces()
        {
            var name = "-winmd";
            var value1 = "Windows.Foundation.FoundationContract.winmd";
            var value2 = "Windows.Foundation.UniversalApiContract.winmd";
            var input = string.Format("{0} \"{1}\" \"{2}\"", name, value1, value2);
            var parser = new ResponseFileParserTest();
            var list = parser.ParseResponseFileContentHelper(input);

            Assert.AreEqual(3, list.Count);
            Assert.AreEqual(name, list[0]);
            Assert.AreEqual(value1, list[1]);
            Assert.AreEqual(value2, list[2]);
        }

        [TestMethod]
        public void OneParameter_TwoValidValuesEndsWithValueWithNoSpaces()
        {
            var name = "-winmd";
            var value1 = "C:\\Program Files (x86)\\Windows Kits\\10\\References\\Windows.Foundation.FoundationContract\\1.0.0.0\\Windows.Foundation.FoundationContract.winmd";
            var value2 = "Windows.Foundation.UniversalApiContract.winmd";
            var input = string.Format("{0} \"{1}\" \"{2}\"", name, value1, value2);
            var parser = new ResponseFileParserTest();
            var list = parser.ParseResponseFileContentHelper(input);

            Assert.AreEqual(3, list.Count);
            Assert.AreEqual(name, list[0]);
            Assert.AreEqual(value1, list[1]);
            Assert.AreEqual(value2, list[2]);
        }
        [TestMethod]
        public void OneParameter_TwoValidValuesEndsWithValueWithSpaces()
        {
            var name = "-winmd";
            var value1 = "Windows.Foundation.UniversalApiContract.winmd";
            var value2 = "C:\\Program Files (x86)\\Windows Kits\\10\\References\\Windows.Foundation.FoundationContract\\1.0.0.0\\Windows.Foundation.FoundationContract.winmd";
            var input = string.Format("{0} \"{1}\" \"{2}\"", name, value1, value2);
            var parser = new ResponseFileParserTest();
            var list = parser.ParseResponseFileContentHelper(input);

            Assert.AreEqual(3, list.Count);
            Assert.AreEqual(name, list[0]);
            Assert.AreEqual(value1, list[1]);
            Assert.AreEqual(value2, list[2]);
        }

        [TestMethod]
        public void TwoParameter_OneValidValueWithSpaces()
        {
            var name1 = "-winmd";
            var value1 = "C:\\Program Files (x86)\\Windows Kits\\10\\References\\Windows.Foundation.FoundationContract\\1.0.0.0\\Windows.Foundation.FoundationContract.winmd";
            var name2 = "-winmd";
            var value2 = "C:\\Program Files (x86)\\Windows Kits\\10\\References\\Windows.Foundation.UniversalApiContract\\1.0.0.0\\Windows.Foundation.UniversalApiContract.winmd";

            var input = string.Format("{0} \"{1}\" {2} \"{3}\"", name1, value1, name2, value2);
            var parser = new ResponseFileParserTest();
            var list = parser.ParseResponseFileContentHelper(input);

            Assert.AreEqual(4, list.Count);
            Assert.AreEqual(name1, list[0]);
            Assert.AreEqual(value1, list[1]);
            Assert.AreEqual(name2, list[2]);
            Assert.AreEqual(value2, list[3]);
        }

        [TestMethod]
        public void TwoParameter_OneValidValueWithNoSpaces()
        {
            var name1 = "-winmd";
            var value1 = "Windows.Foundation.FoundationContract.winmd";
            var name2 = "-winmd";
            var value2 = "Windows.Foundation.UniversalApiContract.winmd";

            var input = string.Format("{0} \"{1}\" {2} \"{3}\"", name1, value1, name2, value2);
            var parser = new ResponseFileParserTest();
            var list = parser.ParseResponseFileContentHelper(input);

            Assert.AreEqual(4, list.Count);
            Assert.AreEqual(name1, list[0]);
            Assert.AreEqual(value1, list[1]);
            Assert.AreEqual(name2, list[2]);
            Assert.AreEqual(value2, list[3]);
        }

        [TestMethod]
        public void TwoParameter_EachWithTwoValues()
        {
            var name1 = "-winmd";
            var value11 = "Windows.Foundation.FoundationContract.winmd";
            var value12 = "Windows.Foundation.UniversalApiContract.winmd";
            var name2 = "-foo";
            var value21 = "C:\\Program Files (x86)\\Windows Kits\\10\\References\\Windows.Foundation.FoundationContract\\1.0.0.0\\Windows.Foundation.FoundationContract.winmd";
            var value22 = "C:\\Program Files (x86)\\Windows Kits\\10\\References\\Windows.Foundation.UniversalApiContract\\1.0.0.0\\Windows.Foundation.UniversalApiContract.winmd";


            var input = string.Format("{0} \"{1}\" \"{2}\" {3} \"{4}\" \"{5}\"", name1, value11, value12, name2, value21, value22);
            var parser = new ResponseFileParserTest();
            var list = parser.ParseResponseFileContentHelper(input);

            Assert.AreEqual(6, list.Count);
            Assert.AreEqual(name1, list[0]);
            Assert.AreEqual(value11, list[1]);
            Assert.AreEqual(value12, list[2]);
            Assert.AreEqual(name2, list[3]);
            Assert.AreEqual(value21, list[4]);
            Assert.AreEqual(value22, list[5]);
        }

        [TestMethod]
        public void OneParameter_OneValidValueNoSpacesAndNoQuotes()
        {
            var name = "-winmd";
            var value = "Windows.Foundation.FoundationContract.winmd";
            var input = string.Format("{0} {1}", name, value);
            var parser = new ResponseFileParserTest();
            var list = parser.ParseResponseFileContentHelper(input);

            Assert.AreEqual(2, list.Count);
            Assert.AreEqual(name, list[0]);
            Assert.AreEqual(value, list[1]);
        }

        [TestMethod]
        public void OneParameter_TwoValidValuesNoSpacesAndNoQuotes()
        {
            var name = "-winmd";
            var value1 = "Windows.Foundation.FoundationContract.winmd";
            var value2 = "Windows.Foundation.UniversalApiContract.winmd";
            var input = string.Format("{0} {1} {2}", name, value1, value2);

            var parser = new ResponseFileParserTest();
            var list = parser.ParseResponseFileContentHelper(input);

            Assert.AreEqual(3, list.Count);
            Assert.AreEqual(name, list[0]);
            Assert.AreEqual(value1, list[1]);
            Assert.AreEqual(value2, list[2]);
        }

        [TestMethod]
        public void OneParameter_OneValidValueWithSpacesAndNoQuotes()
        {
            var name = "-winmd";
            var chunk1 = "C:\\Program";
            var chunk2 = "Files";
            var chunk3 = "(x86)\\Windows";
            var chunk4 = "Kits\\10\\References\\Windows.Foundation.FoundationContract\\1.0.0.0\\Windows.Foundation.FoundationContract.winmd";

            var input = string.Format("{0} {1} {2} {3} {4}", name, chunk1, chunk2, chunk3, chunk4);
            var parser = new ResponseFileParserTest();
            var list = parser.ParseResponseFileContentHelper(input);

            Assert.AreEqual(5, list.Count);
            Assert.AreEqual(name, list[0]);
            Assert.AreEqual(chunk1, list[1]);
            Assert.AreEqual(chunk2, list[2]);
            Assert.AreEqual(chunk3, list[3]);
            Assert.AreEqual(chunk4, list[4]);
        }

        [TestMethod]
        public void ResponseFileNotFound()
        {
            var responseFileParser = new ResponseFileParser();
            var file = @"c:\filethatdoesnotexists.txt";

            AssertHelper.VerifiyThrows<ResponseFileNotFoundException>(() => { responseFileParser.Parse(file); }, string.Format(StringExceptionFormats.ResponseFileNotFound, file));
        }

        [TestMethod]
        public void InvalidResponseFile()
        {
            var name = "-winmd";
            var chunk1 = "\"C:\\Program Files (x86)\\Windows Kits\\10\\References\\Windows.Foundation.FoundationContract\\1.0.0.0\\Windows.Foundation.FoundationContract.winmd\"\"";

            var input = string.Format("{0} {1}", name, chunk1);
            var parser = new ResponseFileParserTest();
            AssertHelper.VerifiyThrows< InvalidResponseFileException>(() => { parser.ParseResponseFileContentHelper(input); });
        }

        [TestMethod]
        public void OneParameter_TwoValidValuesWithMultipleSpaces()
        {
            var name = "-winmd";
            var value1 = "C:\\Program Files (x86)\\Windows Kits\\10\\References\\Windows.Foundation.FoundationContract\\1.0.0.0\\Windows.Foundation.FoundationContract.winmd";
            var value2 = "C:\\Program Files (x86)\\Windows Kits\\10\\References\\Windows.Foundation.UniversalApiContract\\1.0.0.0\\Windows.Foundation.UniversalApiContract.winmd";
            var input = string.Format("           {0}       \"{1}\"                   \"{2}\"            ", name, value1, value2);
            var parser = new ResponseFileParserTest();
            var list = parser.ParseResponseFileContentHelper(input);

            Assert.AreEqual(3, list.Count);
            Assert.AreEqual(name, list[0]);
            Assert.AreEqual(value1, list[1]);
            Assert.AreEqual(value2, list[2]);
        }

        [TestMethod]
        public void OneParameter_TwoValidValuesWithMultipleSpacesBetweenValuesOneInvalid()
        {
            var name = "-winmd";
            var value1 = "C:\\Program Files (x86)\\Windows Kits\\10\\References\\Windows.Foundation.FoundationContract\\1.0.0.0\\Windows.Foundation.FoundationContract.winmd";
            var value2 = "C:\\Program Files (x86)\\Windows Kits\\10\\References\\Windows.Foundation.UniversalApiContract\\1.0.0.0\\Windows.Foundation.UniversalApiContract.winmd";
            var input = string.Format("           {0}       \"{1}\"\"                   \"{2}\"           ", name, value1, value2);
            var parser = new ResponseFileParserTest();

            AssertHelper.VerifiyThrows<InvalidResponseFileException>(() => { parser.ParseResponseFileContentHelper(input); });
        }

        [TestMethod]
        public void TwoParameter_TwoValidValuesWithMultipleSpacesBetweenValues()
        {
            var name1 = "-winmd";
            var value11 = "C:\\Program Files (x86)\\Windows Kits\\10\\References\\Windows.Foundation.FoundationContract\\1.0.0.0\\Windows.Foundation.FoundationContract.winmd";
            var value12 = "C:\\Program Files (x86)\\Windows Kits\\10\\References\\Windows.Foundation.UniversalApiContract\\1.0.0.0\\Windows.Foundation.UniversalApiContract.winmd";
            var name2 = "-winmd";
            var value21 = "C:\\Program Files (x86)\\Windows Kits\\10\\References\\Windows.Foundation.FoundationContract\\1.0.0.0\\Windows.Foundation.FoundationContract.winmd";
            var value22 = "C:\\Program Files (x86)\\Windows Kits\\10\\References\\Windows.Foundation.UniversalApiContract\\1.0.0.0\\Windows.Foundation.UniversalApiContract.winmd";
            var input = string.Format("           {0}       \"{1}\"                   \"{2}\"           {3}     \"{4}\"    \"{5}\"    ", name1, value11, value12, name2, value21, value22);
            var parser = new ResponseFileParserTest();

            var list = parser.ParseResponseFileContentHelper(input);

            Assert.AreEqual(6, list.Count);
            Assert.AreEqual(name1, list[0]);
            Assert.AreEqual(value11, list[1]);
            Assert.AreEqual(value12, list[2]);
            Assert.AreEqual(name2, list[3]);
            Assert.AreEqual(value21, list[4]);
            Assert.AreEqual(value22, list[5]);
        }

        [TestMethod]
        public void TwoParameter_TwoValidValuesWithMultipleSpacesBetweenValuesOneInvalid()
        {
            var name1 = "-winmd";
            var value11 = "C:\\Program Files (x86)\\Windows Kits\\10\\References\\Windows.Foundation.FoundationContract\\1.0.0.0\\Windows.Foundation.FoundationContract.winmd";
            var value12 = "C:\\Program Files (x86)\\Windows Kits\\10\\References\\Windows.Foundation.UniversalApiContract\\1.0.0.0\\Windows.Foundation.UniversalApiContract.winmd";
            var name2 = "-winmd";
            var value21 = "C:\\Program Files (x86)\\Windows Kits\\10\\References\\Windows.Foundation.FoundationContract\\1.0.0.0\\Windows.Foundation.FoundationContract.winmd";
            var value22 = "C:\\Program Files (x86)\\Windows Kits\\10\\References\\Windows.Foundation.UniversalApiContract\\1.0.0.0\\Windows.Foundation.UniversalApiContract.winmd";
            var input = string.Format("           {0}       \"{1}\"                   \"{2}\"           {3}     \"{4}\"    \"{5}\"\"    ", name1, value11, value12, name2, value21, value22);
            var parser = new ResponseFileParserTest();

            AssertHelper.VerifiyThrows<InvalidResponseFileException>(() => { parser.ParseResponseFileContentHelper(input); });
        }

        [TestMethod]
        public void ThreeParameter_TwoValidValuesWithSpacesAndEndOfLine()
        {
            var name1 = "-winmd";
            var value11 = "C:\\Program Files (x86)\\Windows Kits\\10\\References\\Windows.Foundation.FoundationContract\\1.0.0.0\\Windows.Foundation.FoundationContract.winmd";
            var value12 = "C:\\Program Files (x86)\\Windows Kits\\10\\References\\Windows.Foundation.UniversalApiContract\\1.0.0.0\\Windows.Foundation.UniversalApiContract.winmd";
            var name2 = "-winmd";
            var value21 = "Windows.Foundation.FoundationContract.winmd";
            var value22 = "Windows.Foundation.UniversalApiContract.winmd";
            var name3 = "-winmd";
            var value31 = "C:\\Program Files (x86)\\Windows Kits\\10\\References\\Windows.Foundation.FoundationContract\\1.0.0.0\\Windows.Foundation.FoundationContract.winmd";
            var value32 = "C:\\Program Files (x86)\\Windows Kits\\10\\References\\Windows.Foundation.UniversalApiContract\\1.0.0.0\\Windows.Foundation.UniversalApiContract.winmd";
            var input = string.Format("\r\n  \r\n           {0}       \"{1}\"      \r\n             \"{2}\"           {3}     {4}    {5}   {6}       \"{7}\"                   \"{8}\"    ", name1, value11, value12, name2, value21, value22, name3, value31, value32);
            var parser = new ResponseFileParserTest();

            var list = parser.ParseResponseFileContentHelper(input);

            Assert.AreEqual(9, list.Count);
            Assert.AreEqual(name1, list[0]);
            Assert.AreEqual(value11, list[1]);
            Assert.AreEqual(value12, list[2]);
            Assert.AreEqual(name2, list[3]);
            Assert.AreEqual(value21, list[4]);
            Assert.AreEqual(value22, list[5]);
            Assert.AreEqual(name3, list[6]);
            Assert.AreEqual(value31, list[7]);
            Assert.AreEqual(value32, list[8]);
        }

        [TestMethod]
        public void OneParameter_TwoValidValuesWithQuotesThatContainDashesEndWithExtraTokens()
        {
            var name = "-winmd";
            var value1 = "C:\\Program Files (x86)\\Windows Kits\\10\\References\\Windows-Foundation-FoundationContract\\1.0.0.0\\Windows.Foundation.FoundationContract.winmd";
            var value2 = "C:\\Program Files (x86)\\Windows Kits\\10\\References\\Windows.Foundation.UniversalApiContract\\1.0.0.0\\Windows-Foundation-UniversalApiContract.winmd";
            var input = string.Format("   \r\n        {0}       \"{1}\"        \r\n           \"{2}\"        \r\n    ", name, value1, value2);
            var parser = new ResponseFileParserTest();
            var list = parser.ParseResponseFileContentHelper(input);

            Assert.AreEqual(3, list.Count);
            Assert.AreEqual(name, list[0]);
            Assert.AreEqual(value1, list[1]);
            Assert.AreEqual(value2, list[2]);
        }

        [TestMethod]
        public void OneParameter_TwoValidValuesWithQuotesThatContainDashesEndWithNoExtraTokens()
        {
            var name = "-winmd";
            var value1 = "C:\\Program Files (x86)\\Windows Kits\\10\\References\\Windows-Foundation-FoundationContract\\1.0.0.0\\Windows.Foundation.FoundationContract.winmd";
            var value2 = "C:\\Program Files (x86)\\Windows Kits\\10\\References\\Windows.Foundation.UniversalApiContract\\1.0.0.0\\Windows-Foundation-UniversalApiContract.winmd";
            var input = string.Format("   \r\n        {0}       \"{1}\"        \r\n           \"{2}\"", name, value1, value2);
            var parser = new ResponseFileParserTest();
            var list = parser.ParseResponseFileContentHelper(input);

            Assert.AreEqual(3, list.Count);
            Assert.AreEqual(name, list[0]);
            Assert.AreEqual(value1, list[1]);
            Assert.AreEqual(value2, list[2]);
        }

        [TestMethod]
        public void OneParameter_TwoValidValuesOneWithQuotesThatContainDashesEndWithExtraTokens()
        {
            var name = "-winmd";
            var value1 = "C:\\Program Files (x86)\\Windows Kits\\10\\References\\Windows-Foundation-FoundationContract\\1.0.0.0\\Windows.Foundation.FoundationContract.winmd";
            var value2 = "C:\\Windows-Foundation-UniversalApiContract.winmd";
            var input = string.Format("   \r\n        {0}       \"{1}\"        \r\n           {2}   \r\n      ", name, value1, value2);
            var parser = new ResponseFileParserTest();
            var list = parser.ParseResponseFileContentHelper(input);

            Assert.AreEqual(3, list.Count);
            Assert.AreEqual(name, list[0]);
            Assert.AreEqual(value1, list[1]);
            Assert.AreEqual(value2, list[2]);
        }

        [TestMethod]
        public void OneParameter_TwoValidValuesOneWithQuotesThatContainDashesEndWithNoExtraTokens()
        {
            var name = "-winmd";
            var value1 = "C:\\Program Files (x86)\\Windows Kits\\10\\References\\Windows-Foundation-FoundationContract\\1.0.0.0\\Windows.Foundation.FoundationContract.winmd";
            var value2 = "C:\\Windows-Foundation-UniversalApiContract.winmd";
            var input = string.Format("   \r\n        {0}       \"{1}\"        \r\n           {2}", name, value1, value2);
            var parser = new ResponseFileParserTest();
            var list = parser.ParseResponseFileContentHelper(input);

            Assert.AreEqual(3, list.Count);
            Assert.AreEqual(name, list[0]);
            Assert.AreEqual(value1, list[1]);
            Assert.AreEqual(value2, list[2]);
        }
    }
}
