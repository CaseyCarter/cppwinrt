// C++ for the Windows Runtime v1.0.private
// Copyright (c) 2016 Microsoft Corporation. All rights reserved.

#pragma once

#include "../base.h"
#include "Windows.System.Profile.0.h"
#include "Windows.Storage.Streams.0.h"
#include "Windows.System.0.h"
#include "Windows.Foundation.1.h"

WINRT_EXPORT namespace winrt {

namespace ABI::Windows::System::Profile {

struct __declspec(uuid("1d5ee066-188d-5ba9-4387-acaeb0e7e305")) __declspec(novtable) IAnalyticsInfoStatics : Windows::IInspectable
{
    virtual HRESULT __stdcall get_VersionInfo(Windows::System::Profile::IAnalyticsVersionInfo ** value) = 0;
    virtual HRESULT __stdcall get_DeviceForm(hstring * value) = 0;
};

struct __declspec(uuid("926130b8-9955-4c74-bdc1-7cd0decf9b03")) __declspec(novtable) IAnalyticsVersionInfo : Windows::IInspectable
{
    virtual HRESULT __stdcall get_DeviceFamily(hstring * value) = 0;
    virtual HRESULT __stdcall get_DeviceFamilyVersion(hstring * value) = 0;
};

struct __declspec(uuid("971260e0-f170-4a42-bd55-a900b212dae2")) __declspec(novtable) IHardwareIdentificationStatics : Windows::IInspectable
{
    virtual HRESULT __stdcall abi_GetPackageSpecificToken(Windows::Storage::Streams::IBuffer * nonce, Windows::System::Profile::IHardwareToken ** packageSpecificHardwareToken) = 0;
};

struct __declspec(uuid("28f6d4c0-fb12-40a4-8167-7f4e03d2724c")) __declspec(novtable) IHardwareToken : Windows::IInspectable
{
    virtual HRESULT __stdcall get_Id(Windows::Storage::Streams::IBuffer ** value) = 0;
    virtual HRESULT __stdcall get_Signature(Windows::Storage::Streams::IBuffer ** value) = 0;
    virtual HRESULT __stdcall get_Certificate(Windows::Storage::Streams::IBuffer ** value) = 0;
};

struct __declspec(uuid("b6e24c1b-7b1c-4b32-8c62-a66597ce723a")) __declspec(novtable) IPlatformDiagnosticsAndUsageDataSettingsStatics : Windows::IInspectable
{
    virtual HRESULT __stdcall get_CollectionLevel(winrt::Windows::System::Profile::PlatformDataCollectionLevel * value) = 0;
    virtual HRESULT __stdcall add_CollectionLevelChanged(Windows::Foundation::EventHandler<Windows::IInspectable> * handler, event_token * token) = 0;
    virtual HRESULT __stdcall remove_CollectionLevelChanged(event_token token) = 0;
    virtual HRESULT __stdcall abi_CanCollectDiagnostics(winrt::Windows::System::Profile::PlatformDataCollectionLevel level, bool * result) = 0;
};

struct __declspec(uuid("893df40e-cad6-4d50-8c49-6fcfc03edb29")) __declspec(novtable) ISharedModeSettingsStatics : Windows::IInspectable
{
    virtual HRESULT __stdcall get_IsEnabled(bool * value) = 0;
};

struct __declspec(uuid("0c659e7d-c3c2-4d33-a2df-21bc41916eb3")) __declspec(novtable) ISystemIdentificationInfo : Windows::IInspectable
{
    virtual HRESULT __stdcall get_Id(Windows::Storage::Streams::IBuffer ** value) = 0;
    virtual HRESULT __stdcall get_Source(winrt::Windows::System::Profile::SystemIdentificationSource * value) = 0;
};

struct __declspec(uuid("5581f42a-d3df-4d93-a37d-c41a616c6d01")) __declspec(novtable) ISystemIdentificationStatics : Windows::IInspectable
{
    virtual HRESULT __stdcall abi_GetSystemIdForPublisher(Windows::System::Profile::ISystemIdentificationInfo ** result) = 0;
    virtual HRESULT __stdcall abi_GetSystemIdForUser(Windows::System::IUser * user, Windows::System::Profile::ISystemIdentificationInfo ** result) = 0;
};

}

namespace ABI {

template <> struct traits<Windows::System::Profile::AnalyticsVersionInfo> { using default_interface = Windows::System::Profile::IAnalyticsVersionInfo; };
template <> struct traits<Windows::System::Profile::HardwareToken> { using default_interface = Windows::System::Profile::IHardwareToken; };
template <> struct traits<Windows::System::Profile::SystemIdentificationInfo> { using default_interface = Windows::System::Profile::ISystemIdentificationInfo; };

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

}

namespace impl {

template <> struct traits<Windows::System::Profile::IAnalyticsInfoStatics>
{
    using abi = ABI::Windows::System::Profile::IAnalyticsInfoStatics;
    template <typename D> using consume = Windows::System::Profile::impl_IAnalyticsInfoStatics<D>;
};

template <> struct traits<Windows::System::Profile::IAnalyticsVersionInfo>
{
    using abi = ABI::Windows::System::Profile::IAnalyticsVersionInfo;
    template <typename D> using consume = Windows::System::Profile::impl_IAnalyticsVersionInfo<D>;
};

template <> struct traits<Windows::System::Profile::IHardwareIdentificationStatics>
{
    using abi = ABI::Windows::System::Profile::IHardwareIdentificationStatics;
    template <typename D> using consume = Windows::System::Profile::impl_IHardwareIdentificationStatics<D>;
};

template <> struct traits<Windows::System::Profile::IHardwareToken>
{
    using abi = ABI::Windows::System::Profile::IHardwareToken;
    template <typename D> using consume = Windows::System::Profile::impl_IHardwareToken<D>;
};

template <> struct traits<Windows::System::Profile::IPlatformDiagnosticsAndUsageDataSettingsStatics>
{
    using abi = ABI::Windows::System::Profile::IPlatformDiagnosticsAndUsageDataSettingsStatics;
    template <typename D> using consume = Windows::System::Profile::impl_IPlatformDiagnosticsAndUsageDataSettingsStatics<D>;
};

template <> struct traits<Windows::System::Profile::ISharedModeSettingsStatics>
{
    using abi = ABI::Windows::System::Profile::ISharedModeSettingsStatics;
    template <typename D> using consume = Windows::System::Profile::impl_ISharedModeSettingsStatics<D>;
};

template <> struct traits<Windows::System::Profile::ISystemIdentificationInfo>
{
    using abi = ABI::Windows::System::Profile::ISystemIdentificationInfo;
    template <typename D> using consume = Windows::System::Profile::impl_ISystemIdentificationInfo<D>;
};

template <> struct traits<Windows::System::Profile::ISystemIdentificationStatics>
{
    using abi = ABI::Windows::System::Profile::ISystemIdentificationStatics;
    template <typename D> using consume = Windows::System::Profile::impl_ISystemIdentificationStatics<D>;
};

template <> struct traits<Windows::System::Profile::AnalyticsInfo>
{
    static constexpr const wchar_t * name() noexcept { return L"Windows.System.Profile.AnalyticsInfo"; }
};

template <> struct traits<Windows::System::Profile::AnalyticsVersionInfo>
{
    using abi = ABI::Windows::System::Profile::AnalyticsVersionInfo;
    static constexpr const wchar_t * name() noexcept { return L"Windows.System.Profile.AnalyticsVersionInfo"; }
};

template <> struct traits<Windows::System::Profile::HardwareIdentification>
{
    static constexpr const wchar_t * name() noexcept { return L"Windows.System.Profile.HardwareIdentification"; }
};

template <> struct traits<Windows::System::Profile::HardwareToken>
{
    using abi = ABI::Windows::System::Profile::HardwareToken;
    static constexpr const wchar_t * name() noexcept { return L"Windows.System.Profile.HardwareToken"; }
};

template <> struct traits<Windows::System::Profile::PlatformDiagnosticsAndUsageDataSettings>
{
    static constexpr const wchar_t * name() noexcept { return L"Windows.System.Profile.PlatformDiagnosticsAndUsageDataSettings"; }
};

template <> struct traits<Windows::System::Profile::SharedModeSettings>
{
    static constexpr const wchar_t * name() noexcept { return L"Windows.System.Profile.SharedModeSettings"; }
};

template <> struct traits<Windows::System::Profile::SystemIdentification>
{
    static constexpr const wchar_t * name() noexcept { return L"Windows.System.Profile.SystemIdentification"; }
};

template <> struct traits<Windows::System::Profile::SystemIdentificationInfo>
{
    using abi = ABI::Windows::System::Profile::SystemIdentificationInfo;
    static constexpr const wchar_t * name() noexcept { return L"Windows.System.Profile.SystemIdentificationInfo"; }
};

}

}
