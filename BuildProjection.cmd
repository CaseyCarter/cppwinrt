@echo off
setlocal 

call SetBuildVars %*

set compiler=%cd%\cppwinrt\%BuildPlatform%\%BuildConfiguration%\cppwinrt.exe
set output=%cd%\%BuildStaging%

pushd %BuildStaging%\SDKReferences

%compiler% platform -verbose -tests -out %output% ^
-in "Windows.ApplicationModel.Calls.CallsVoipContract\1.0.0.0\Windows.ApplicationModel.Calls.CallsVoipContract.winmd" ^
-in "Windows.ApplicationModel.SocialInfo.SocialInfoContract\1.0.0.0\Windows.ApplicationModel.SocialInfo.SocialInfoContract.winmd" ^
-in "Windows.Devices.DevicesLowLevelContract\2.0.0.0\Windows.Devices.DevicesLowLevelContract.winmd" ^
-in "Windows.Devices.Printers.PrintersContract\1.0.0.0\Windows.Devices.Printers.PrintersContract.winmd" ^
-in "Windows.Foundation.FoundationContract\2.0.0.0\Windows.Foundation.FoundationContract.winmd" ^
-in "Windows.Foundation.UniversalApiContract\3.0.0.0\Windows.Foundation.UniversalApiContract.winmd" ^
-in "Windows.Graphics.Printing3D.Printing3DContract\3.0.0.0\Windows.Graphics.Printing3D.Printing3DContract.winmd" ^
-in "Windows.Networking.Connectivity.WwanContract\1.0.0.0\Windows.Networking.Connectivity.WwanContract.winmd" ^
-in "Windows.Services.Store.StoreContract\1.0.0.0\Windows.Services.Store.StoreContract.winmd" ^
-in "Windows.System.Profile.ProfileHardwareTokenContract\1.0.0.0\Windows.System.Profile.ProfileHardwareTokenContract.winmd" ^
-in "Windows.System.Profile.ProfileSharedModeContract\1.0.0.0\Windows.System.Profile.ProfileSharedModeContract.winmd" ^
-in "Windows.UI.ViewManagement.ViewManagementViewScalingContract\1.0.0.0\Windows.UI.ViewManagement.ViewManagementViewScalingContract.winmd"

popd