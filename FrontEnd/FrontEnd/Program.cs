using System;
using System.Collections.Generic;
using System.Runtime.CompilerServices;

using Microsoft.Wcl.Steps;
using System.Diagnostics;

[assembly: InternalsVisibleToAttribute("FrontEndTests")]

namespace Microsoft.Wcl
{

    class Program
    {
        static int Main(string[] args)
        {
            //if (Debugger.IsAttached)
            //{
            //    args = new string[] { @"-winmd", @"D:\testmetadata\windows.networking.connectivity.wwancontract.winmd",
            //    @"-winmd", @"D:\testmetadata\Windows.Foundation.FoundationContract.winmd",
            //    @"-winmd", @"D:\testmetadata\Windows.Foundation.UniversalApiContract.winmd",
            //    @"D:\testmetadata\Windows.Devices.Sms.LegacySmsApiContract.winmd",
            //    @"-db",
            //    @"d:\modern\testdatabaseoutput.db" };

            //    int value = ProcessMain(args);
            //    FrontEndConfiguration.Output.WriteLine("Done");
            //    Console.ReadKey();
            //    return value;
            //}
            //else
            {
                try
                {
                    return ProcessMain(args);
                }
                catch (WinmdFileNotFoundException e)
                {
                    // No catastrophic. No need to generate WER report and such
                    Console.WriteLine(e.Message);
                    Console.WriteLine();
                    return -1;
                }
                catch (ArgumentsParseException e)
                {
                    // No catastrophic. No need to generate WER report and such
                    Console.WriteLine(e.Message);
                    Console.WriteLine();
                    ShowHelp();
                    Console.WriteLine();
                    return -1;
                }
                catch (ResponseFileNotFoundException e)
                {
                    // No catastrophic. No need to generate WER report and such
                    Console.WriteLine(e.Message);
                    return -1;
                }
                catch (Exception e)
                {
                    Console.Error.WriteLine("An error ocured during the execution of the program");
                    while (e != null)
                    {
                        Console.Error.WriteLine(e.Message);
                        Console.Error.WriteLine(e.StackTrace);
                        e = e.InnerException;
                    }

                    // This will generate a WER report
                    throw;
                }
            }
        }

        static int ProcessMain(string[] args)
        {
            var expandedArgs = ExpandArgs(args);

            var validator = new ArgumentValidator();
            var arguments = new ArgumentsParser(expandedArgs, validator);
            arguments.Parse();

            if (arguments.ArgumentsDictionary.ContainsKey("?") || arguments.ArgumentsDictionary.Count == 0)
            {
                ShowHelp();
            }
            else
            {
                Stopwatch watch = new Stopwatch();
                watch.Start();

                var frontEnd = new FrontEnd();
                frontEnd.Initialize();

                var configuration = new FrontEndConfiguration();
                configuration.Arguments.Add(arguments.ArgumentsDictionary.GetEnumerator());

                frontEnd.Run(configuration);

                watch.Stop();
                FrontEndConfiguration.Output.WriteLine(StringMessageFormats.TotalTimeToProcessInput, watch.ElapsedMilliseconds);
            }

            // If something went wrong, in the form of an exception, it was re-thrown in the catch section. Therefore, always return 0 here.
            return 0;
        }

        private static void ShowHelp()
        {
            FrontEndConfiguration.Output.WriteLine(HelpText);
        }

        static string[] ExpandArgs(string[] args)
        {
            var finalList = new List<string>();
            var responseFileParser = new ResponseFileParser();

            foreach (var element in args)
            {
                if (element.StartsWith("@"))
                {
                    var responseFileName = element.Substring(1);
                    var list = responseFileParser.Parse(responseFileName);
                    finalList.Add(list);
                }
                else
                {
                    finalList.Add(element);
                }
            }

            return finalList.ToArray();
        }

        internal const string HelpText =
@"Microsoft (R) C++ for the Windows Runtime metadata parser
Copyright(C) Microsoft Corporation.All rights reserved.

Usage:

- To show this help:
    WinMDc1.exe -?
- To process a winmd (output sqlite database default name will be winrt.db and it will placed in the same directory):
    WinMDc1.exe -winmd foo.winmd
- To process a winmd and specify a location and name of the output sqlite database:
    WinMDc1.exe -winmd foo.winmd -db c:\output\mydatabase.db
- To process more than one winmd
    WinMDc1.exe -winmd foo.winmd bar.winmd
- To process more than one set of winmds
    WinMDc1.exe -winmd c:\foo\foo1.winmd c:\foo\foo2.winmd -winmd d:\bar\bar1.winmd d:\bar\bar2.winmd
- To process a response file (for long static inputs)
    WinMDc1.exe @c:\data\responseFile.txt
- To process a winmd and use a response file
    WinMDc1.exe -winmd c:\foo\foo1.winmd @c:\data\responseFile.txt
- To process a winmd with path and name that contain spaces
    WinMDc1.exe -winmd ""C:\Program Files(x86)\Windows Kits\10\References\Windows.Foundation.FoundationContract\1.0.0.0\Windows.Foundation.FoundationContract.winmd""
";
    }
}