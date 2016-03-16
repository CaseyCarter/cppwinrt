using Microsoft.VisualStudio.TestTools.UnitTesting;
using System.Diagnostics;
using System.IO;

using Microsoft.Wcl;
using System.Collections.Generic;

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

            var databaseFilePath = GetDatabaseFullPath();
            MetadataTestHelper.GetDataFromSQLite(databaseFilePath, query, testFileFullPath, out rightString);

            string leftString = null;
            MetadataTestHelper.GetBaseFileContent(verifyFileFullPath, out leftString);
            Assert.AreEqual(leftString, rightString);
        }

        private static string GetDatabaseFullPath()
        {
            var databaseDirectory = Directory.GetCurrentDirectory();
            return Path.Combine(databaseDirectory, "winrt.db");
        }
    }
}
