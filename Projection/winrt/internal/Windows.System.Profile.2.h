// C++ for the Windows Runtime v1.0.private
// Copyright (c) 2016 Microsoft Corporation. All rights reserved.

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
    auto operator->() const noexcept { return ptr<IAnalyticsInfoStatics>(m_ptr); }
};

struct IAnalyticsVersionInfo :
    Windows::IInspectable,
    impl::consume<IAnalyticsVersionInfo>
{
    IAnalyticsVersionInfo(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IAnalyticsVersionInfo>(m_ptr); }
};

struct IHardwareIdentificationStatics :
    Windows::IInspectable,
    impl::consume<IHardwareIdentificationStatics>
{
    IHardwareIdentificationStatics(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IHardwareIdentificationStatics>(m_ptr); }
};

struct IHardwareToken :
    Windows::IInspectable,
    impl::consume<IHardwareToken>
{
    IHardwareToken(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IHardwareToken>(m_ptr); }
};

struct IPlatformDiagnosticsAndUsageDataSettingsStatics :
    Windows::IInspectable,
    impl::consume<IPlatformDiagnosticsAndUsageDataSettingsStatics>
{
    IPlatformDiagnosticsAndUsageDataSettingsStatics(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IPlatformDiagnosticsAndUsageDataSettingsStatics>(m_ptr); }
};

struct ISharedModeSettingsStatics :
    Windows::IInspectable,
    impl::consume<ISharedModeSettingsStatics>
{
    ISharedModeSettingsStatics(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<ISharedModeSettingsStatics>(m_ptr); }
};

struct ISystemIdentificationInfo :
    Windows::IInspectable,
    impl::consume<ISystemIdentificationInfo>
{
    ISystemIdentificationInfo(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<ISystemIdentificationInfo>(m_ptr); }
};

struct ISystemIdentificationStatics :
    Windows::IInspectable,
    impl::consume<ISystemIdentificationStatics>
{
    ISystemIdentificationStatics(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<ISystemIdentificationStatics>(m_ptr); }
};

}

}
