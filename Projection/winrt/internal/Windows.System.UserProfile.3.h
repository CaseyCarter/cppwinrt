// C++ for the Windows Runtime v1.0.private
// Copyright (c) 2016 Microsoft Corporation

#pragma once

#include "Windows.System.UserProfile.2.h"

WINRT_EXPORT namespace winrt {

namespace Windows::System::UserProfile {

struct AdvertisingManager
{
    AdvertisingManager() = delete;
    static hstring AdvertisingId();
    static Windows::System::UserProfile::AdvertisingManagerForUser GetForUser(const Windows::System::User & user);
};

struct WINRT_EBO AdvertisingManagerForUser :
    Windows::System::UserProfile::IAdvertisingManagerForUser
{
    AdvertisingManagerForUser(std::nullptr_t) noexcept {}
};

struct WINRT_EBO FirstSignInSettings :
    Windows::System::UserProfile::IFirstSignInSettings
{
    FirstSignInSettings(std::nullptr_t) noexcept {}
    static Windows::System::UserProfile::FirstSignInSettings GetDefault();
};

struct GlobalizationPreferences
{
    GlobalizationPreferences() = delete;
    static Windows::Foundation::Collections::IVectorView<hstring> Calendars();
    static Windows::Foundation::Collections::IVectorView<hstring> Clocks();
    static Windows::Foundation::Collections::IVectorView<hstring> Currencies();
    static Windows::Foundation::Collections::IVectorView<hstring> Languages();
    static hstring HomeGeographicRegion();
    static Windows::Globalization::DayOfWeek WeekStartsOn();
};

struct WINRT_EBO UserProfilePersonalizationSettings :
    Windows::System::UserProfile::IUserProfilePersonalizationSettings
{
    UserProfilePersonalizationSettings(std::nullptr_t) noexcept {}
    static Windows::System::UserProfile::UserProfilePersonalizationSettings Current();
    static bool IsSupported();
};

}

}
