#pragma once

#define WIN32_LEAN_AND_MEAN 
#define NOMINMAX
#define WINRT_NATVIS

#pragma comment(lib, "windowsapp") 

#include "winrt\Windows.Foundation.Collections.h"
#include "winrt\Windows.Foundation.Diagnostics.h"
#include "winrt\Windows.ApplicationModel.Activation.h"
#include "winrt\Windows.ApplicationModel.Core.h"
#include "winrt\Windows.ApplicationModel.DataTransfer.h"
#include "winrt\Windows.ApplicationModel.Store.h"
#include "winrt\Windows.Data.Json.h"
#include "winrt\Windows.Devices.Perception.Provider.h"
#include "winrt\Windows.Devices.Sms.h"
#include "winrt\Windows.Graphics.Display.h"
#include "winrt\Windows.Graphics.Effects.h"
#include "winrt\Windows.Management.Deployment.h"
#include "winrt\Windows.Media.Audio.h"
#include "winrt\Windows.Media.Core.h"
#include "winrt\Windows.Media.Transcoding.h"
#include "winrt\Windows.Networking.Sockets.h"
#include "winrt\Windows.Security.Cryptography.Certificates.h"
#include "winrt\Windows.Storage.Streams.h"
#include "winrt\Windows.System.Threading.h"
#include "winrt\Windows.UI.Core.h"
#include "winrt\Windows.UI.Xaml.Controls.h"
#include "winrt\Windows.UI.Xaml.Interop.h"
#include "winrt\Windows.Web.AtomPub.h"
#include "winrt\Windows.Web.Http.Headers.h"
#include "winrt\Windows.Web.Syndication.h"

#include <memory>
#include <future>
#include <array>
#include <forward_list>
