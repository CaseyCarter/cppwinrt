@echo off
setlocal 

call SetBuildVars %*

set compiler=%cd%\cppwinrt\%BuildPlatform%\%BuildConfiguration%\cppwinrt.exe
set output=%cd%\%BuildStaging%

pushd %BuildStaging%\SDKReferences

%compiler% platform -verbose -tests -out %output% ^
-in "Windows.ApplicationModel.Activation.ActivatedEventsContract\1.0.0.0\Windows.ApplicationModel.Activation.ActivatedEventsContract.winmd" ^
-in "Windows.ApplicationModel.Activation.ActivationCameraSettingsContract\1.0.0.0\Windows.ApplicationModel.Activation.ActivationCameraSettingsContract.winmd" ^
-in "Windows.ApplicationModel.Activation.ContactActivatedEventsContract\1.0.0.0\Windows.ApplicationModel.Activation.ContactActivatedEventsContract.winmd" ^
-in "Windows.ApplicationModel.Activation.WebUISearchActivatedEventsContract\1.0.0.0\Windows.ApplicationModel.Activation.WebUISearchActivatedEventsContract.winmd" ^
-in "Windows.ApplicationModel.Background.BackgroundAlarmApplicationContract\1.0.0.0\Windows.ApplicationModel.Background.BackgroundAlarmApplicationContract.winmd" ^
-in "Windows.ApplicationModel.Calls.Background.CallsBackgroundContract\1.0.0.0\Windows.ApplicationModel.Calls.Background.CallsBackgroundContract.winmd" ^
-in "Windows.ApplicationModel.Calls.CallsPhoneContract\3.0.0.0\Windows.ApplicationModel.Calls.CallsPhoneContract.winmd" ^
-in "Windows.ApplicationModel.Calls.CallsVoipContract\1.0.0.0\Windows.ApplicationModel.Calls.CallsVoipContract.winmd" ^
-in "Windows.ApplicationModel.Calls.LockScreenCallContract\1.0.0.0\Windows.ApplicationModel.Calls.LockScreenCallContract.winmd" ^
-in "Windows.ApplicationModel.CommunicationBlocking.CommunicationBlockingContract\2.0.0.0\Windows.ApplicationModel.CommunicationBlocking.CommunicationBlockingContract.winmd" ^
-in "Windows.ApplicationModel.FullTrustAppContract\1.0.0.0\Windows.ApplicationModel.FullTrustAppContract.winmd" ^
-in "Windows.ApplicationModel.Preview.InkWorkspace.PreviewInkWorkspaceContract\1.0.0.0\Windows.ApplicationModel.Preview.InkWorkspace.PreviewInkWorkspaceContract.winmd" ^
-in "Windows.ApplicationModel.Preview.Notes.PreviewNotesContract\2.0.0.0\Windows.ApplicationModel.Preview.Notes.PreviewNotesContract.winmd" ^
-in "Windows.ApplicationModel.Resources.Management.ResourceIndexerContract\1.0.0.0\Windows.ApplicationModel.Resources.Management.ResourceIndexerContract.winmd" ^
-in "Windows.ApplicationModel.Search.Core.SearchCoreContract\1.0.0.0\Windows.ApplicationModel.Search.Core.SearchCoreContract.winmd" ^
-in "Windows.ApplicationModel.Search.SearchContract\1.0.0.0\Windows.ApplicationModel.Search.SearchContract.winmd" ^
-in "Windows.ApplicationModel.SocialInfo.SocialInfoContract\2.0.0.0\Windows.ApplicationModel.SocialInfo.SocialInfoContract.winmd" ^
-in "Windows.ApplicationModel.StartupTaskContract\1.0.0.0\Windows.ApplicationModel.StartupTaskContract.winmd" ^
-in "Windows.ApplicationModel.Wallet.WalletContract\1.0.0.0\Windows.ApplicationModel.Wallet.WalletContract.winmd" ^
-in "Windows.Devices.Custom.CustomDeviceContract\1.0.0.0\Windows.Devices.Custom.CustomDeviceContract.winmd" ^
-in "Windows.Devices.DevicesLowLevelContract\3.0.0.0\Windows.Devices.DevicesLowLevelContract.winmd" ^
-in "Windows.Devices.Portable.PortableDeviceContract\1.0.0.0\Windows.Devices.Portable.PortableDeviceContract.winmd" ^
-in "Windows.Devices.Printers.Extensions.ExtensionsContract\2.0.0.0\Windows.Devices.Printers.Extensions.ExtensionsContract.winmd" ^
-in "Windows.Devices.Printers.PrintersContract\1.0.0.0\Windows.Devices.Printers.PrintersContract.winmd" ^
-in "Windows.Devices.Scanners.ScannerDeviceContract\1.0.0.0\Windows.Devices.Scanners.ScannerDeviceContract.winmd" ^
-in "Windows.Devices.SmartCards.SmartCardBackgroundTriggerContract\3.0.0.0\Windows.Devices.SmartCards.SmartCardBackgroundTriggerContract.winmd" ^
-in "Windows.Devices.SmartCards.SmartCardEmulatorContract\4.0.0.0\Windows.Devices.SmartCards.SmartCardEmulatorContract.winmd" ^
-in "Windows.Devices.Sms.LegacySmsApiContract\1.0.0.0\Windows.Devices.Sms.LegacySmsApiContract.winmd" ^
-in "Windows.Embedded.DeviceLockdown.DeviceLockdownContract\1.0.0.0\Windows.Embedded.DeviceLockdown.DeviceLockdownContract.winmd" ^
-in "Windows.Foundation.FoundationContract\3.0.0.0\Windows.Foundation.FoundationContract.winmd" ^
-in "Windows.Foundation.UniversalApiContract\4.0.0.0\Windows.Foundation.UniversalApiContract.winmd" ^
-in "Windows.Gaming.Input.GamingInputPreviewContract\1.0.0.0\Windows.Gaming.Input.GamingInputPreviewContract.winmd" ^
-in "Windows.Gaming.Preview.GamesEnumerationContract\1.0.0.0\Windows.Gaming.Preview.GamesEnumerationContract.winmd" ^
-in "Windows.Gaming.UI.GameChatOverlayContract\1.0.0.0\Windows.Gaming.UI.GameChatOverlayContract.winmd" ^
-in "Windows.Globalization.GlobalizationJapanesePhoneticAnalyzerContract\1.0.0.0\Windows.Globalization.GlobalizationJapanesePhoneticAnalyzerContract.winmd" ^
-in "Windows.Graphics.Printing3D.Printing3DContract\3.0.0.0\Windows.Graphics.Printing3D.Printing3DContract.winmd" ^
-in "Windows.Management.Deployment.Preview.DeploymentPreviewContract\1.0.0.0\Windows.Management.Deployment.Preview.DeploymentPreviewContract.winmd" ^
-in "Windows.Management.Workplace.WorkplaceSettingsContract\1.0.0.0\Windows.Management.Workplace.WorkplaceSettingsContract.winmd" ^
-in "Windows.Media.Capture.AppBroadcastContract\1.0.0.0\Windows.Media.Capture.AppBroadcastContract.winmd" ^
-in "Windows.Media.Capture.AppCaptureContract\4.0.0.0\Windows.Media.Capture.AppCaptureContract.winmd" ^
-in "Windows.Media.Capture.CameraCaptureUIContract\1.0.0.0\Windows.Media.Capture.CameraCaptureUIContract.winmd" ^
-in "Windows.Media.Capture.GameBarContract\1.0.0.0\Windows.Media.Capture.GameBarContract.winmd" ^
-in "Windows.Media.Devices.CallControlContract\1.0.0.0\Windows.Media.Devices.CallControlContract.winmd" ^
-in "Windows.Media.MediaControlContract\1.0.0.0\Windows.Media.MediaControlContract.winmd" ^
-in "Windows.Media.Playlists.PlaylistsContract\1.0.0.0\Windows.Media.Playlists.PlaylistsContract.winmd" ^
-in "Windows.Media.Protection.ProtectionRenewalContract\1.0.0.0\Windows.Media.Protection.ProtectionRenewalContract.winmd" ^
-in "Windows.Networking.Connectivity.WwanContract\1.0.0.0\Windows.Networking.Connectivity.WwanContract.winmd" ^
-in "Windows.Networking.NetworkOperators.LegacyNetworkOperatorsContract\1.0.0.0\Windows.Networking.NetworkOperators.LegacyNetworkOperatorsContract.winmd" ^
-in "Windows.Networking.NetworkOperators.NetworkOperatorsFdnContract\1.0.0.0\Windows.Networking.NetworkOperators.NetworkOperatorsFdnContract.winmd" ^
-in "Windows.Networking.Sockets.ControlChannelTriggerContract\2.0.0.0\Windows.Networking.Sockets.ControlChannelTriggerContract.winmd" ^
-in "Windows.Perception.Automation.Core.PerceptionAutomationCoreContract\1.0.0.0\Windows.Perception.Automation.Core.PerceptionAutomationCoreContract.winmd" ^
-in "Windows.Phone.PhoneContract\1.0.0.0\Windows.Phone.PhoneContract.winmd" ^
-in "Windows.Phone.StartScreen.DualSimTileContract\1.0.0.0\Windows.Phone.StartScreen.DualSimTileContract.winmd" ^
-in "Windows.Security.EnterpriseData.EnterpriseDataContract\4.0.0.0\Windows.Security.EnterpriseData.EnterpriseDataContract.winmd" ^
-in "Windows.Security.ExchangeActiveSyncProvisioning.EasContract\1.0.0.0\Windows.Security.ExchangeActiveSyncProvisioning.EasContract.winmd" ^
-in "Windows.Services.Maps.GuidanceContract\2.0.0.0\Windows.Services.Maps.GuidanceContract.winmd" ^
-in "Windows.Services.Maps.LocalSearchContract\3.0.0.0\Windows.Services.Maps.LocalSearchContract.winmd" ^
-in "Windows.Services.Store.StoreContract\2.0.0.0\Windows.Services.Store.StoreContract.winmd" ^
-in "Windows.Services.TargetedContent.TargetedContentContract\1.0.0.0\Windows.Services.TargetedContent.TargetedContentContract.winmd" ^
-in "Windows.System.Profile.ProfileHardwareTokenContract\1.0.0.0\Windows.System.Profile.ProfileHardwareTokenContract.winmd" ^
-in "Windows.System.Profile.ProfileRetailInfoContract\1.0.0.0\Windows.System.Profile.ProfileRetailInfoContract.winmd" ^
-in "Windows.System.Profile.ProfileSharedModeContract\2.0.0.0\Windows.System.Profile.ProfileSharedModeContract.winmd" ^
-in "Windows.System.Profile.SystemManufacturers.SystemManufacturersContract\1.0.0.0\Windows.System.Profile.SystemManufacturers.SystemManufacturersContract.winmd" ^
-in "Windows.System.SystemManagementContract\3.0.0.0\Windows.System.SystemManagementContract.winmd" ^
-in "Windows.System.UserProfile.UserProfileContract\1.0.0.0\Windows.System.UserProfile.UserProfileContract.winmd" ^
-in "Windows.System.UserProfile.UserProfileLockScreenContract\1.0.0.0\Windows.System.UserProfile.UserProfileLockScreenContract.winmd" ^
-in "Windows.UI.ApplicationSettings.ApplicationsSettingsContract\1.0.0.0\Windows.UI.ApplicationSettings.ApplicationsSettingsContract.winmd" ^
-in "Windows.UI.Core.AnimationMetrics.AnimationMetricsContract\1.0.0.0\Windows.UI.Core.AnimationMetrics.AnimationMetricsContract.winmd" ^
-in "Windows.UI.Core.CoreWindowDialogsContract\1.0.0.0\Windows.UI.Core.CoreWindowDialogsContract.winmd" ^
-in "Windows.UI.ViewManagement.ViewManagementViewScalingContract\1.0.0.0\Windows.UI.ViewManagement.ViewManagementViewScalingContract.winmd" ^
-in "Windows.UI.WebUI.Core.WebUICommandBarContract\1.0.0.0\Windows.UI.WebUI.Core.WebUICommandBarContract.winmd" ^
-in "Windows.UI.Xaml.Hosting.HostingContract\1.0.0.0\Windows.UI.Xaml.Hosting.HostingContract.winmd" ^
-in "Windows.Web.Http.Diagnostics.HttpDiagnosticsContract\2.0.0.0\Windows.Web.Http.Diagnostics.HttpDiagnosticsContract.winmd"

popd