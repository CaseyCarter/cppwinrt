// C++ for the Windows Runtime v1.0.private
// Copyright (c) 2016 Microsoft Corporation. All rights reserved.

#pragma once

#include "Windows.ApplicationModel.h"
#include "Windows.ApplicationModel.Activation.h"
#include "Windows.ApplicationModel.AppExtensions.h"
#include "Windows.ApplicationModel.AppService.h"
#include "Windows.ApplicationModel.Appointments.h"
#include "Windows.ApplicationModel.Appointments.AppointmentsProvider.h"
#include "Windows.ApplicationModel.Appointments.DataProvider.h"
#include "Windows.ApplicationModel.Background.h"
#include "Windows.ApplicationModel.Calls.h"
#include "Windows.ApplicationModel.Chat.h"
#include "Windows.ApplicationModel.Contacts.h"
#include "Windows.ApplicationModel.Contacts.DataProvider.h"
#include "Windows.ApplicationModel.Contacts.Provider.h"
#include "Windows.ApplicationModel.Core.h"
#include "Windows.ApplicationModel.DataTransfer.h"
#include "Windows.ApplicationModel.DataTransfer.DragDrop.h"
#include "Windows.ApplicationModel.DataTransfer.DragDrop.Core.h"
#include "Windows.ApplicationModel.DataTransfer.ShareTarget.h"
#include "Windows.ApplicationModel.Email.h"
#include "Windows.ApplicationModel.Email.DataProvider.h"
#include "Windows.ApplicationModel.ExtendedExecution.h"
#include "Windows.ApplicationModel.ExtendedExecution.Foreground.h"
#include "Windows.ApplicationModel.LockScreen.h"
#include "Windows.ApplicationModel.Resources.h"
#include "Windows.ApplicationModel.Resources.Core.h"
#include "Windows.ApplicationModel.Search.h"
#include "Windows.ApplicationModel.SocialInfo.h"
#include "Windows.ApplicationModel.SocialInfo.Provider.h"
#include "Windows.ApplicationModel.Store.h"
#include "Windows.ApplicationModel.Store.LicenseManagement.h"
#include "Windows.ApplicationModel.Store.Preview.h"
#include "Windows.ApplicationModel.Store.Preview.InstallControl.h"
#include "Windows.ApplicationModel.UserDataAccounts.h"
#include "Windows.ApplicationModel.UserDataAccounts.Provider.h"
#include "Windows.ApplicationModel.UserDataAccounts.SystemAccess.h"
#include "Windows.ApplicationModel.VoiceCommands.h"
#include "Windows.ApplicationModel.Wallet.h"
#include "Windows.ApplicationModel.Wallet.System.h"
#include "Windows.Data.Html.h"
#include "Windows.Data.Json.h"
#include "Windows.Data.Pdf.h"
#include "Windows.Data.Text.h"
#include "Windows.Data.Xml.Dom.h"
#include "Windows.Data.Xml.Xsl.h"
#include "Windows.Devices.h"
#include "Windows.Devices.Adc.h"
#include "Windows.Devices.Adc.Provider.h"
#include "Windows.Devices.AllJoyn.h"
#include "Windows.Devices.Background.h"
#include "Windows.Devices.Bluetooth.h"
#include "Windows.Devices.Bluetooth.Advertisement.h"
#include "Windows.Devices.Bluetooth.Background.h"
#include "Windows.Devices.Bluetooth.GenericAttributeProfile.h"
#include "Windows.Devices.Bluetooth.Rfcomm.h"
#include "Windows.Devices.Enumeration.h"
#include "Windows.Devices.Enumeration.Pnp.h"
#include "Windows.Devices.Geolocation.h"
#include "Windows.Devices.Geolocation.Geofencing.h"
#include "Windows.Devices.Gpio.h"
#include "Windows.Devices.Gpio.Provider.h"
#include "Windows.Devices.HumanInterfaceDevice.h"
#include "Windows.Devices.I2c.h"
#include "Windows.Devices.I2c.Provider.h"
#include "Windows.Devices.Input.h"
#include "Windows.Devices.Lights.h"
#include "Windows.Devices.Midi.h"
#include "Windows.Devices.Perception.h"
#include "Windows.Devices.Perception.Provider.h"
#include "Windows.Devices.PointOfService.h"
#include "Windows.Devices.Power.h"
#include "Windows.Devices.Printers.h"
#include "Windows.Devices.Printers.Extensions.h"
#include "Windows.Devices.Pwm.h"
#include "Windows.Devices.Pwm.Provider.h"
#include "Windows.Devices.Radios.h"
#include "Windows.Devices.Sensors.h"
#include "Windows.Devices.Sensors.Custom.h"
#include "Windows.Devices.SerialCommunication.h"
#include "Windows.Devices.SmartCards.h"
#include "Windows.Devices.Sms.h"
#include "Windows.Devices.Spi.h"
#include "Windows.Devices.Spi.Provider.h"
#include "Windows.Devices.Usb.h"
#include "Windows.Devices.WiFi.h"
#include "Windows.Devices.WiFiDirect.h"
#include "Windows.Devices.WiFiDirect.Services.h"
#include "Windows.Foundation.h"
#include "Windows.Foundation.Collections.h"
#include "Windows.Foundation.Diagnostics.h"
#include "Windows.Foundation.Metadata.h"
#include "Windows.Gaming.Input.h"
#include "Windows.Gaming.Input.Custom.h"
#include "Windows.Gaming.Input.ForceFeedback.h"
#include "Windows.Gaming.UI.h"
#include "Windows.Globalization.h"
#include "Windows.Globalization.Collation.h"
#include "Windows.Globalization.DateTimeFormatting.h"
#include "Windows.Globalization.Fonts.h"
#include "Windows.Globalization.NumberFormatting.h"
#include "Windows.Globalization.PhoneNumberFormatting.h"
#include "Windows.Graphics.DirectX.h"
#include "Windows.Graphics.DirectX.Direct3D11.h"
#include "Windows.Graphics.Display.h"
#include "Windows.Graphics.Effects.h"
#include "Windows.Graphics.Holographic.h"
#include "Windows.Graphics.Imaging.h"
#include "Windows.Graphics.Printing.h"
#include "Windows.Graphics.Printing3D.h"
#include "Windows.Graphics.Printing.OptionDetails.h"
#include "Windows.Management.Core.h"
#include "Windows.Management.Deployment.h"
#include "Windows.Management.Workplace.h"
#include "Windows.Media.h"
#include "Windows.Media.Audio.h"
#include "Windows.Media.Capture.h"
#include "Windows.Media.Capture.Core.h"
#include "Windows.Media.Capture.Frames.h"
#include "Windows.Media.Casting.h"
#include "Windows.Media.ClosedCaptioning.h"
#include "Windows.Media.ContentRestrictions.h"
#include "Windows.Media.Core.h"
#include "Windows.Media.Devices.h"
#include "Windows.Media.Devices.Core.h"
#include "Windows.Media.DialProtocol.h"
#include "Windows.Media.Editing.h"
#include "Windows.Media.Effects.h"
#include "Windows.Media.FaceAnalysis.h"
#include "Windows.Media.Import.h"
#include "Windows.Media.MediaProperties.h"
#include "Windows.Media.Ocr.h"
#include "Windows.Media.PlayTo.h"
#include "Windows.Media.Playback.h"
#include "Windows.Media.Protection.h"
#include "Windows.Media.Protection.PlayReady.h"
#include "Windows.Media.Render.h"
#include "Windows.Media.SpeechRecognition.h"
#include "Windows.Media.SpeechSynthesis.h"
#include "Windows.Media.Streaming.Adaptive.h"
#include "Windows.Media.Transcoding.h"
#include "Windows.Networking.h"
#include "Windows.Networking.BackgroundTransfer.h"
#include "Windows.Networking.Connectivity.h"
#include "Windows.Networking.NetworkOperators.h"
#include "Windows.Networking.Proximity.h"
#include "Windows.Networking.PushNotifications.h"
#include "Windows.Networking.ServiceDiscovery.Dnssd.h"
#include "Windows.Networking.Sockets.h"
#include "Windows.Networking.Vpn.h"
#include "Windows.Perception.h"
#include "Windows.Perception.People.h"
#include "Windows.Perception.Spatial.h"
#include "Windows.Perception.Spatial.Surfaces.h"
#include "Windows.Security.Authentication.Identity.h"
#include "Windows.Security.Authentication.Identity.Core.h"
#include "Windows.Security.Authentication.Identity.Provider.h"
#include "Windows.Security.Authentication.OnlineId.h"
#include "Windows.Security.Authentication.Web.h"
#include "Windows.Security.Authentication.Web.Core.h"
#include "Windows.Security.Authentication.Web.Provider.h"
#include "Windows.Security.Credentials.h"
#include "Windows.Security.Credentials.UI.h"
#include "Windows.Security.Cryptography.h"
#include "Windows.Security.Cryptography.Certificates.h"
#include "Windows.Security.Cryptography.Core.h"
#include "Windows.Security.Cryptography.DataProtection.h"
#include "Windows.Security.EnterpriseData.h"
#include "Windows.Security.ExchangeActiveSyncProvisioning.h"
#include "Windows.Services.Maps.h"
#include "Windows.Services.Store.h"
#include "Windows.Storage.h"
#include "Windows.Storage.AccessCache.h"
#include "Windows.Storage.BulkAccess.h"
#include "Windows.Storage.Compression.h"
#include "Windows.Storage.FileProperties.h"
#include "Windows.Storage.Pickers.h"
#include "Windows.Storage.Pickers.Provider.h"
#include "Windows.Storage.Provider.h"
#include "Windows.Storage.Search.h"
#include "Windows.Storage.Streams.h"
#include "Windows.System.h"
#include "Windows.System.Diagnostics.h"
#include "Windows.System.Display.h"
#include "Windows.System.Power.h"
#include "Windows.System.Power.Diagnostics.h"
#include "Windows.System.Profile.h"
#include "Windows.System.RemoteDesktop.h"
#include "Windows.System.RemoteSystems.h"
#include "Windows.System.Threading.h"
#include "Windows.System.Threading.Core.h"
#include "Windows.System.UserProfile.h"
#include "Windows.UI.h"
#include "Windows.UI.ApplicationSettings.h"
#include "Windows.UI.Composition.h"
#include "Windows.UI.Composition.Effects.h"
#include "Windows.UI.Composition.Interactions.h"
#include "Windows.UI.Core.h"
#include "Windows.UI.Input.h"
#include "Windows.UI.Input.Inking.h"
#include "Windows.UI.Input.Inking.Core.h"
#include "Windows.UI.Input.Preview.Injection.h"
#include "Windows.UI.Input.Spatial.h"
#include "Windows.UI.Notifications.h"
#include "Windows.UI.Notifications.Management.h"
#include "Windows.UI.Popups.h"
#include "Windows.UI.StartScreen.h"
#include "Windows.UI.Text.h"
#include "Windows.UI.Text.Core.h"
#include "Windows.UI.ViewManagement.h"
#include "Windows.UI.WebUI.h"
#include "Windows.UI.Xaml.h"
#include "Windows.UI.Xaml.Automation.h"
#include "Windows.UI.Xaml.Automation.Peers.h"
#include "Windows.UI.Xaml.Automation.Provider.h"
#include "Windows.UI.Xaml.Automation.Text.h"
#include "Windows.UI.Xaml.Controls.h"
#include "Windows.UI.Xaml.Controls.Maps.h"
#include "Windows.UI.Xaml.Controls.Primitives.h"
#include "Windows.UI.Xaml.Data.h"
#include "Windows.UI.Xaml.Documents.h"
#include "Windows.UI.Xaml.Hosting.h"
#include "Windows.UI.Xaml.Input.h"
#include "Windows.UI.Xaml.Interop.h"
#include "Windows.UI.Xaml.Markup.h"
#include "Windows.UI.Xaml.Media.h"
#include "Windows.UI.Xaml.Media.Animation.h"
#include "Windows.UI.Xaml.Media.Imaging.h"
#include "Windows.UI.Xaml.Media.Media3D.h"
#include "Windows.UI.Xaml.Navigation.h"
#include "Windows.UI.Xaml.Printing.h"
#include "Windows.UI.Xaml.Resources.h"
#include "Windows.UI.Xaml.Shapes.h"
#include "Windows.Web.h"
#include "Windows.Web.AtomPub.h"
#include "Windows.Web.Http.h"
#include "Windows.Web.Http.Filters.h"
#include "Windows.Web.Http.Headers.h"
#include "Windows.Web.Syndication.h"