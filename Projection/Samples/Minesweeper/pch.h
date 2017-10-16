#pragma once

#pragma comment(lib, "windowsapp")

#ifdef _DEBUG
#define WINRT_DIAGNOSTICS
#endif

#include <winrt/Windows.ApplicationModel.Core.h>
#include <winrt/Windows.UI.Core.h>
#include <winrt/Windows.UI.Composition.h>
#include <winrt/Windows.Media.Core.h>
#include <winrt/Windows.UI.Input.h>

#include <random>
#include <queue>

WINRT_WARNING_PUSH
