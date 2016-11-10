// C++ for the Windows Runtime v1.0.private
// Copyright (c) 2016 Microsoft Corporation. All rights reserved.

#pragma once


WINRT_EXPORT namespace winrt {

namespace ABI::Windows::System::Profile {

struct IAnalyticsInfoStatics;
struct IAnalyticsVersionInfo;
struct IHardwareIdentificationStatics;
struct IHardwareToken;
struct IPlatformDiagnosticsAndUsageDataSettingsStatics;
struct ISharedModeSettingsStatics;
struct ISystemIdentificationInfo;
struct ISystemIdentificationStatics;
struct AnalyticsVersionInfo;
struct HardwareToken;
struct SystemIdentificationInfo;

}

namespace Windows::System::Profile {

struct IAnalyticsInfoStatics;
struct IAnalyticsVersionInfo;
struct IHardwareIdentificationStatics;
struct IHardwareToken;
struct IPlatformDiagnosticsAndUsageDataSettingsStatics;
struct ISharedModeSettingsStatics;
struct ISystemIdentificationInfo;
struct ISystemIdentificationStatics;
struct AnalyticsInfo;
struct AnalyticsVersionInfo;
struct HardwareIdentification;
struct HardwareToken;
struct PlatformDiagnosticsAndUsageDataSettings;
struct SharedModeSettings;
struct SystemIdentification;
struct SystemIdentificationInfo;

}

namespace Windows::System::Profile {

template <typename T> struct impl_IAnalyticsInfoStatics;
template <typename T> struct impl_IAnalyticsVersionInfo;
template <typename T> struct impl_IHardwareIdentificationStatics;
template <typename T> struct impl_IHardwareToken;
template <typename T> struct impl_IPlatformDiagnosticsAndUsageDataSettingsStatics;
template <typename T> struct impl_ISharedModeSettingsStatics;
template <typename T> struct impl_ISystemIdentificationInfo;
template <typename T> struct impl_ISystemIdentificationStatics;

}

namespace Windows::System::Profile {

enum class PlatformDataCollectionLevel
{
    Security = 0,
    Basic = 1,
    Enhanced = 2,
    Full = 3,
};

enum class SystemIdentificationSource
{
    None = 0,
    Tpm = 1,
    Uefi = 2,
};

}

}
