using Microsoft.VisualStudio.TestTools.UnitTesting;
using Microsoft.Wcl;
using System.Diagnostics;
using System.IO;
using System.Text.RegularExpressions;

namespace Microsoft.Wtl.Tests
{
    public static class MetadataTestHelper
    {
        public static void GetDataFromSQLite(string databaseFullFileName, string query, string outputFullFileName, out string outputFileContent)
        {
            var currentDirectory = Directory.GetCurrentDirectory();
            var parameters = @"""" + databaseFullFileName + @""" " + @"""" + query + @"""";
            ProcessStartInfo info = new ProcessStartInfo();

            info.UseShellExecute = false;
            info.RedirectStandardOutput = true;

            info.Arguments = parameters;
            info.FileName = Path.Combine(currentDirectory, @"TestData\SQLite\sqlite.exe");
            info.CreateNoWindow = true;

            Process proc = Process.Start(info);
            string output = proc.StandardOutput.ReadToEnd().Trim();
            proc.WaitForExit();

            using (StreamWriter writer = new StreamWriter(outputFullFileName))
            {
                writer.WriteLine(output);
            }

            outputFileContent = output;
        }

        public static void GetBaseFileContent(string leftFileFullPath, out string leftString)
        {
            // TODO change output to be the return value
            using (StreamReader left = new StreamReader(leftFileFullPath))
            {
                leftString = left.ReadToEnd().Trim();
            }
        }

        internal static Wcl.FrontEndConfiguration RunFrontEnd(string[] winmds, bool skipGenericInterfaceResolution = true)
        {
            var argHelper = new string[winmds.Length + 1];
            int i = 0;
            argHelper[i++] = @"-winmd";
            foreach (var winmd in winmds)
            {
                argHelper[i++] = winmd;
            }

            var arguments = new Wcl.ArgumentsParser(argHelper);
            arguments.Parse();
            var configuration = new Wcl.FrontEndConfiguration();
            configuration.Arguments.Add(arguments.ArgumentsDictionary.GetEnumerator());
            configuration.SkipGenericInterfaceResolution = skipGenericInterfaceResolution;

            var databaseFilePath = GetDatabaseFullPath();
            if (File.Exists(databaseFilePath))
            {
                File.Delete(databaseFilePath);
            }

            var frontEnd = new Wcl.Steps.FrontEnd();
            frontEnd.Initialize();
            frontEnd.Run(configuration);

            return configuration;
        }

        public static void RunBasicTest(string sourceWinmdDirectory, string sourceWinmd, string verifyFilePath, string verifyFileName, string testFilePath, string testFileName, string query, bool skipGenericInterfaceResolution = true)
        {
            var directory = Path.Combine(Directory.GetCurrentDirectory(), sourceWinmdDirectory);
            var winmd = Path.Combine(directory, sourceWinmd);

            RunBasicTest(new string[] { winmd }, verifyFilePath, verifyFileName, testFilePath, testFileName, query, skipGenericInterfaceResolution);
        }

        public static void RunBasicTest(string[] winmds, string verifyFilePath, string verifyFileName, string testFilePath, string testFileName, string query, bool skipGenericInterfaceResolution = true)
        {
            MetadataTestHelper.RunFrontEnd(winmds, skipGenericInterfaceResolution);

            VerifyDatabaseByQuery(verifyFilePath, verifyFileName, testFilePath, testFileName, query);
        }

        public static void VerifyDatabaseByQuery(string verifyFilePath, string verifyFileName, string testFilePath, string testFileName, string query)
        {
            string rightString = null;

            var verifyFileFullPath = Path.Combine(Directory.GetCurrentDirectory(), verifyFilePath + @"\" + verifyFileName);
            var testFileFullPath = Path.Combine(Directory.GetCurrentDirectory(), verifyFilePath + @"\" + testFileName);

            if (File.Exists(testFileFullPath))
            {
                File.Delete(testFileFullPath);
            }

            // When the output of sqlite is obtained from the console output, it comes with windows style with respect to the end of lines.
            var databaseFilePath = GetDatabaseFullPath();
            MetadataTestHelper.GetDataFromSQLite(databaseFilePath, query, testFileFullPath, out rightString);

            string leftString = null;
            MetadataTestHelper.GetBaseFileContent(verifyFileFullPath, out leftString);

            // Depending on certain variables of Git/Source-Control content of the file may come the Unix way with respect to end of lines.
            // Change that to match windows style which is needed to compare against the content of the database. 
            leftString = EnsureStringHasCRLF(leftString);

            Assert.AreEqual(leftString, rightString);
        }

        // Force a full match of \r\n first before matching any other option to avoid errors while replacing.
        static Regex NewLineRegEx = new Regex(@"\r\n|\r|\n", RegexOptions.Compiled);
        private static string EnsureStringHasCRLF(string input)
        {
            return NewLineRegEx.Replace(input, "\r\n");
        }

        private static string GetDatabaseFullPath()
        {
            var databaseDirectory = Directory.GetCurrentDirectory();
            return Path.Combine(databaseDirectory, "winrt.db");
        }
    }
}