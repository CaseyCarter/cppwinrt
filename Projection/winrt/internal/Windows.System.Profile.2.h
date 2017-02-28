// C++ for the Windows Runtime v1.0.private
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "Windows.System.Profile.1.h"

WINRT_EXPORT namespace winrt {

namespace ABI::Windows::Foundation {

#ifndef WINRT_GENERIC_c50898f6_c536_5f47_8583_8b2c2438a13b
#define WINRT_GENERIC_c50898f6_c536_5f47_8583_8b2c2438a13b
template <> struct __declspec(uuid("c50898f6-c536-5f47-8583-8b2c2438a13b")) __declspec(novtable) EventHandler<Windows::Foundation::IInspectable> : impl_EventHandler<Windows::Foundation::IInspectable> {};
#endif


}

namespace Windows::System::Profile {

struct IAnalyticsInfoStatics :
    Windows::Foundation::IInspectable,
    impl::consume<IAnalyticsInfoStatics>
{
    IAnalyticsInfoStatics(std::nullptr_t = nullptr) noexcept {}
};

struct IAnalyticsVersionInfo :
    Windows::Foundation::IInspectable,
    impl::consume<IAnalyticsVersionInfo>
{
    IAnalyticsVersionInfo(std::nullptr_t = nullptr) noexcept {}
};

struct IHardwareIdentificationStatics :
    Windows::Foundation::IInspectable,
    impl::consume<IHardwareIdentificationStatics>
{
    IHardwareIdentificationStatics(std::nullptr_t = nullptr) noexcept {}
};

struct IHardwareToken :
    Windows::Foundation::IInspectable,
    impl::consume<IHardwareToken>
{
    IHardwareToken(std::nullptr_t = nullptr) noexcept {}
};

struct IPlatformDiagnosticsAndUsageDataSettingsStatics :
    Windows::Foundation::IInspectable,
    impl::consume<IPlatformDiagnosticsAndUsageDataSettingsStatics>
{
    IPlatformDiagnosticsAndUsageDataSettingsStatics(std::nullptr_t = nullptr) noexcept {}
};

struct ISharedModeSettingsStatics :
    Windows::Foundation::IInspectable,
    impl::consume<ISharedModeSettingsStatics>
{
    ISharedModeSettingsStatics(std::nullptr_t = nullptr) noexcept {}
};

struct ISystemIdentificationInfo :
    Windows::Foundation::IInspectable,
    impl::consume<ISystemIdentificationInfo>
{
    ISystemIdentificationInfo(std::nullptr_t = nullptr) noexcept {}
};

struct ISystemIdentificationStatics :
    Windows::Foundation::IInspectable,
    impl::consume<ISystemIdentificationStatics>
{
    ISystemIdentificationStatics(std::nullptr_t = nullptr) noexcept {}
};

}

}
