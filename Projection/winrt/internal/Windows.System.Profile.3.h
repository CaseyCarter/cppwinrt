// C++ for the Windows Runtime v1.0.private
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "Windows.System.Profile.2.h"

WINRT_EXPORT namespace winrt {

namespace Windows::System::Profile {

struct AnalyticsInfo
{
    AnalyticsInfo() = delete;
    static Windows::System::Profile::AnalyticsVersionInfo VersionInfo();
    static hstring DeviceForm();
};

struct WINRT_EBO AnalyticsVersionInfo :
    Windows::System::Profile::IAnalyticsVersionInfo
{
    AnalyticsVersionInfo(std::nullptr_t) noexcept {}
};

struct HardwareIdentification
{
    HardwareIdentification() = delete;
    static Windows::System::Profile::HardwareToken GetPackageSpecificToken(const Windows::Storage::Streams::IBuffer & nonce);
};

struct WINRT_EBO HardwareToken :
    Windows::System::Profile::IHardwareToken
{
    HardwareToken(std::nullptr_t) noexcept {}
};

struct PlatformDiagnosticsAndUsageDataSettings
{
    PlatformDiagnosticsAndUsageDataSettings() = delete;
    static Windows::System::Profile::PlatformDataCollectionLevel CollectionLevel();
    static event_token CollectionLevelChanged(const Windows::Foundation::EventHandler<Windows::IInspectable> & handler);
    using CollectionLevelChanged_revoker = factory_event_revoker<IPlatformDiagnosticsAndUsageDataSettingsStatics>;
    static CollectionLevelChanged_revoker CollectionLevelChanged(auto_revoke_t, const Windows::Foundation::EventHandler<Windows::IInspectable> & handler);
    static void CollectionLevelChanged(event_token token);
    static bool CanCollectDiagnostics(Windows::System::Profile::PlatformDataCollectionLevel level);
};

struct SharedModeSettings
{
    SharedModeSettings() = delete;
    static bool IsEnabled();
};

struct SystemIdentification
{
    SystemIdentification() = delete;
    static Windows::System::Profile::SystemIdentificationInfo GetSystemIdForPublisher();
    static Windows::System::Profile::SystemIdentificationInfo GetSystemIdForUser(const Windows::System::User & user);
};

struct WINRT_EBO SystemIdentificationInfo :
    Windows::System::Profile::ISystemIdentificationInfo
{
    SystemIdentificationInfo(std::nullptr_t) noexcept {}
};

}

}
