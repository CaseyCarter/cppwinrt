// C++ for the Windows Runtime v1.29
// Copyright (c) 2016 Microsoft Corporation

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

template <typename D>
struct WINRT_EBO impl_IAnalyticsInfoStatics
{
    Windows::System::Profile::AnalyticsVersionInfo VersionInfo() const;
    hstring DeviceForm() const;
};

template <typename D>
struct WINRT_EBO impl_IAnalyticsVersionInfo
{
    hstring DeviceFamily() const;
    hstring DeviceFamilyVersion() const;
};

template <typename D>
struct WINRT_EBO impl_IHardwareIdentificationStatics
{
    Windows::System::Profile::HardwareToken GetPackageSpecificToken(const Windows::Storage::Streams::IBuffer & nonce) const;
};

template <typename D>
struct WINRT_EBO impl_IHardwareToken
{
    Windows::Storage::Streams::IBuffer Id() const;
    Windows::Storage::Streams::IBuffer Signature() const;
    Windows::Storage::Streams::IBuffer Certificate() const;
};

template <typename D>
struct WINRT_EBO impl_IPlatformDiagnosticsAndUsageDataSettingsStatics
{
    Windows::System::Profile::PlatformDataCollectionLevel CollectionLevel() const;
    event_token CollectionLevelChanged(const Windows::Foundation::EventHandler<Windows::IInspectable> & handler) const;
    using CollectionLevelChanged_revoker = event_revoker<IPlatformDiagnosticsAndUsageDataSettingsStatics>;
    CollectionLevelChanged_revoker CollectionLevelChanged(auto_revoke_t, const Windows::Foundation::EventHandler<Windows::IInspectable> & handler) const;
    void CollectionLevelChanged(event_token token) const;
    bool CanCollectDiagnostics(Windows::System::Profile::PlatformDataCollectionLevel level) const;
};

template <typename D>
struct WINRT_EBO impl_ISharedModeSettingsStatics
{
    bool IsEnabled() const;
};

template <typename D>
struct WINRT_EBO impl_ISystemIdentificationInfo
{
    Windows::Storage::Streams::IBuffer Id() const;
    Windows::System::Profile::SystemIdentificationSource Source() const;
};

template <typename D>
struct WINRT_EBO impl_ISystemIdentificationStatics
{
    Windows::System::Profile::SystemIdentificationInfo GetSystemIdForPublisher() const;
    Windows::System::Profile::SystemIdentificationInfo GetSystemIdForUser(const Windows::System::User & user) const;
};

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
