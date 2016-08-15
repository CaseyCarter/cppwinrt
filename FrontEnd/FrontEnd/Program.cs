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
            if (Debugger.IsAttached)
            {
                args = new string[] {
                // For reference, the below 3 are the smallest set that can be used to satisfy the dependencies needed by universal api contract
                //@"-winmd", @"D:\testmetadata\windows.networking.connectivity.wwancontract.winmd",
                //@"-winmd", @"D:\testmetadata\Windows.Foundation.FoundationContract.winmd",
                //@"-winmd", @"D:\testmetadata\Windows.Foundation.UniversalApiContract.winmd",
                // The below is a full set of the SDK as it was in TH2.
                //@"-winmd",
                //@"D:\Git\ModernCPP2\FrontEnd\FrontEndTests\TestData\SDK\Windows.ApplicationModel.Background.BackgroundAlarmApplicationContract.winmd",
                //@"D:\Git\ModernCPP2\FrontEnd\FrontEndTests\TestData\SDK\Windows.ApplicationModel.Calls.CallsPhoneContract.winmd",
                //@"D:\Git\ModernCPP2\FrontEnd\FrontEndTests\TestData\SDK\Windows.ApplicationModel.Calls.CallsVoipContract.winmd",
                //@"D:\Git\ModernCPP2\FrontEnd\FrontEndTests\TestData\SDK\Windows.ApplicationModel.Calls.LockScreenCallContract.winmd",
                //@"D:\Git\ModernCPP2\FrontEnd\FrontEndTests\TestData\SDK\Windows.ApplicationModel.Resources.Management.ResourceIndexerContract.winmd",
                //@"D:\Git\ModernCPP2\FrontEnd\FrontEndTests\TestData\SDK\Windows.ApplicationModel.Search.SearchContract.winmd",
                //@"D:\Git\ModernCPP2\FrontEnd\FrontEndTests\TestData\SDK\Windows.Devices.Custom.CustomDeviceContract.winmd",
                //@"D:\Git\ModernCPP2\FrontEnd\FrontEndTests\TestData\SDK\Windows.Devices.DevicesLowLevelContract.winmd",
                //@"D:\Git\ModernCPP2\FrontEnd\FrontEndTests\TestData\SDK\Windows.Devices.Printers.Extensions.ExtensionsContract.winmd",
                //@"D:\Git\ModernCPP2\FrontEnd\FrontEndTests\TestData\SDK\Windows.Devices.Printers.PrintersContract.winmd",
                //@"D:\Git\ModernCPP2\FrontEnd\FrontEndTests\TestData\SDK\Windows.Devices.Scanners.ScannerDeviceContract.winmd",
                //@"D:\Git\ModernCPP2\FrontEnd\FrontEndTests\TestData\SDK\Windows.Devices.Sms.LegacySmsApiContract.winmd",
                //@"D:\Git\ModernCPP2\FrontEnd\FrontEndTests\TestData\SDK\Windows.Foundation.FoundationContract.winmd",
                //@"D:\Git\ModernCPP2\FrontEnd\FrontEndTests\TestData\SDK\Windows.Foundation.UniversalApiContract.winmd",
                //@"D:\Git\ModernCPP2\FrontEnd\FrontEndTests\TestData\SDK\Windows.Gaming.Preview.GamesEnumerationContract.winmd",
                //@"D:\Git\ModernCPP2\FrontEnd\FrontEndTests\TestData\SDK\Windows.Globalization.GlobalizationJapanesePhoneticAnalyzerContract.winmd",
                //@"D:\Git\ModernCPP2\FrontEnd\FrontEndTests\TestData\SDK\Windows.Graphics.Printing3D.Printing3DContract.winmd",
                //@"D:\Git\ModernCPP2\FrontEnd\FrontEndTests\TestData\SDK\Windows.Media.Playlists.PlaylistsContract.winmd",
                //@"D:\Git\ModernCPP2\FrontEnd\FrontEndTests\TestData\SDK\Windows.Media.Protection.ProtectionRenewalContract.winmd",
                //@"D:\Git\ModernCPP2\FrontEnd\FrontEndTests\TestData\SDK\Windows.Networking.Connectivity.WwanContract.winmd",
                //@"D:\Git\ModernCPP2\FrontEnd\FrontEndTests\TestData\SDK\Windows.Security.EnterpriseData.EnterpriseDataContract.winmd",
                //@"D:\Git\ModernCPP2\FrontEnd\FrontEndTests\TestData\SDK\Windows.Security.ExchangeActiveSyncProvisioning.EasContract.winmd",
                //@"D:\Git\ModernCPP2\FrontEnd\FrontEndTests\TestData\SDK\Windows.Services.Maps.GuidanceContract.winmd",
                //@"D:\Git\ModernCPP2\FrontEnd\FrontEndTests\TestData\SDK\Windows.Services.Maps.LocalSearchContract.winmd",
                //@"D:\Git\ModernCPP2\FrontEnd\FrontEndTests\TestData\SDK\Windows.System.SystemManagementContract.winmd",
                //@"D:\Git\ModernCPP2\FrontEnd\FrontEndTests\TestData\SDK\Windows.System.UserProfile.UserProfileContract.winmd",
                //@"D:\Git\ModernCPP2\FrontEnd\FrontEndTests\TestData\SDK\Windows.UI.ApplicationSettings.ApplicationsSettingsContract.winmd",
                //@"D:\Git\ModernCPP2\FrontEnd\FrontEndTests\TestData\SDK\Windows.UI.Core.AnimationMetrics.AnimationMetricsContract.winmd",
                //@"D:\Git\ModernCPP2\FrontEnd\FrontEndTests\TestData\SDK\Windows.UI.Core.CoreWindowDialogsContract.winmd",
                //@"D:\Git\ModernCPP2\FrontEnd\FrontEndTests\TestData\SDK\Windows.Web.Http.Diagnostics.HttpDiagnosticsContract.winmd",
                //@"@D:\xbox\Projection.Xbox_doesnotexists.txt",
                    //@"-winmd",
                    @"-db",
                    @"d:\modern\testdatabaseoutput.db"
                };

                int value = ProcessMain(args);
                FrontEndConfiguration.Output.WriteLine("Done");
                Console.ReadKey();
                return value;
            }
            else
            {
                try
                {
                    return ProcessMain(args);
                }
                //
                // First deal with all the known, nonn catastrophic exceptions.
                // If we don't know about it, then provide extra details.
                //
                catch (WinmdFileNotFoundException e)
                {
                    PrintOutputAfterKnownException(e);
                    return -1;
                }
                catch (ArgumentsParseException e)
                {
                    PrintOutputAfterKnownException(e);
                    return -1;
                }
                catch (ResponseFileNotFoundException e)
                {
                    PrintOutputAfterKnownException(e);
                    return -1;
                }
                catch (NotEnoughArgumentsParseException e)
                {
                    PrintOutputAfterKnownException(e);
                    return -1;
                }
                catch (ArgumentException e)
                {
                    PrintOutputAfterKnownException(e);
                    return 1;
                }
                catch (Exception e)
                {
                    Console.Error.WriteLine("An error occurred during the execution of the program");
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

        static void PrintOutputAfterKnownException(Exception e)
        {
            // No catastrophic. No need to generate WER report and such
            Console.WriteLine(e.Message);
            Console.WriteLine();
            ShowHelp();
            Console.WriteLine();
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
            else if (!arguments.ArgumentsDictionary.ContainsKey("winmd"))
            {
                throw new NotEnoughArgumentsParseException();
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