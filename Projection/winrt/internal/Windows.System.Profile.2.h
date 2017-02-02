// C++ for the Windows Runtime v1.0.private
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "Windows.System.Profile.1.h"

WINRT_EXPORT namespace winrt {

namespace ABI::Windows::Foundation {

#ifndef WINRT_GENERIC_c50898f6_c536_5f47_8583_8b2c2438a13b
#define WINRT_GENERIC_c50898f6_c536_5f47_8583_8b2c2438a13b
template <> struct __declspec(uuid("c50898f6-c536-5f47-8583-8b2c2438a13b")) __declspec(novtable) EventHandler<Windows::IInspectable> : impl_EventHandler<Windows::IInspectable> {};
#endif


}

namespace Windows::System::Profile {

struct IAnalyticsInfoStatics :
    Windows::IInspectable,
    impl::consume<IAnalyticsInfoStatics>
{
    IAnalyticsInfoStatics(std::nullptr_t = nullptr) noexcept {}
};

struct IAnalyticsVersionInfo :
    Windows::IInspectable,
    impl::consume<IAnalyticsVersionInfo>
{
    IAnalyticsVersionInfo(std::nullptr_t = nullptr) noexcept {}
};

struct IHardwareIdentificationStatics :
    Windows::IInspectable,
    impl::consume<IHardwareIdentificationStatics>
{
    IHardwareIdentificationStatics(std::nullptr_t = nullptr) noexcept {}
};

struct IHardwareToken :
    Windows::IInspectable,
    impl::consume<IHardwareToken>
{
    IHardwareToken(std::nullptr_t = nullptr) noexcept {}
};

struct IPlatformDiagnosticsAndUsageDataSettingsStatics :
    Windows::IInspectable,
    impl::consume<IPlatformDiagnosticsAndUsageDataSettingsStatics>
{
    IPlatformDiagnosticsAndUsageDataSettingsStatics(std::nullptr_t = nullptr) noexcept {}
};

struct ISharedModeSettingsStatics :
    Windows::IInspectable,
    impl::consume<ISharedModeSettingsStatics>
{
    ISharedModeSettingsStatics(std::nullptr_t = nullptr) noexcept {}
};

struct ISystemIdentificationInfo :
    Windows::IInspectable,
    impl::consume<ISystemIdentificationInfo>
{
    ISystemIdentificationInfo(std::nullptr_t = nullptr) noexcept {}
};

struct ISystemIdentificationStatics :
    Windows::IInspectable,
    impl::consume<ISystemIdentificationStatics>
{
    ISystemIdentificationStatics(std::nullptr_t = nullptr) noexcept {}
};

}

}
