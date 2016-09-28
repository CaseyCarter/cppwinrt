// C++ for the Windows Runtime v1.29
// Copyright (c) 2016 Microsoft Corporation

#pragma once

#include "../base.h"
#include "Windows.System.UserProfile.0.h"
#include "Windows.Globalization.0.h"
#include "Windows.Storage.0.h"
#include "Windows.System.0.h"
#include "Windows.Foundation.1.h"
#include "Windows.Foundation.Collections.1.h"

WINRT_EXPORT namespace winrt {

namespace ABI::Windows::System::UserProfile {

struct __declspec(uuid("928bf3d0-cf7c-4ab0-a7dc-6dc5bcd44252")) __declspec(novtable) IAdvertisingManagerForUser : Windows::IInspectable
{
    virtual HRESULT __stdcall get_AdvertisingId(hstring * value) = 0;
    virtual HRESULT __stdcall get_User(Windows::System::IUser ** value) = 0;
};

struct __declspec(uuid("add3468c-a273-48cb-b346-3544522d5581")) __declspec(novtable) IAdvertisingManagerStatics : Windows::IInspectable
{
    virtual HRESULT __stdcall get_AdvertisingId(hstring * value) = 0;
};

struct __declspec(uuid("dd0947af-1a6d-46b0-95bc-f3f9d6beb9fb")) __declspec(novtable) IAdvertisingManagerStatics2 : Windows::IInspectable
{
    virtual HRESULT __stdcall abi_GetForUser(Windows::System::IUser * user, Windows::System::UserProfile::IAdvertisingManagerForUser ** value) = 0;
};

struct __declspec(uuid("3e945153-3a5e-452e-a601-f5baad2a4870")) __declspec(novtable) IFirstSignInSettings : Windows::IInspectable
{
};

struct __declspec(uuid("1ce18f0f-1c41-4ea0-b7a2-6f0c1c7e8438")) __declspec(novtable) IFirstSignInSettingsStatics : Windows::IInspectable
{
    virtual HRESULT __stdcall abi_GetDefault(Windows::System::UserProfile::IFirstSignInSettings ** result) = 0;
};

struct __declspec(uuid("01bf4326-ed37-4e96-b0e9-c1340d1ea158")) __declspec(novtable) IGlobalizationPreferencesStatics : Windows::IInspectable
{
    virtual HRESULT __stdcall get_Calendars(Windows::Foundation::Collections::IVectorView<hstring> ** value) = 0;
    virtual HRESULT __stdcall get_Clocks(Windows::Foundation::Collections::IVectorView<hstring> ** value) = 0;
    virtual HRESULT __stdcall get_Currencies(Windows::Foundation::Collections::IVectorView<hstring> ** value) = 0;
    virtual HRESULT __stdcall get_Languages(Windows::Foundation::Collections::IVectorView<hstring> ** value) = 0;
    virtual HRESULT __stdcall get_HomeGeographicRegion(hstring * value) = 0;
    virtual HRESULT __stdcall get_WeekStartsOn(winrt::Windows::Globalization::DayOfWeek * value) = 0;
};

struct __declspec(uuid("8ceddab4-7998-46d5-8dd3-184f1c5f9ab9")) __declspec(novtable) IUserProfilePersonalizationSettings : Windows::IInspectable
{
    virtual HRESULT __stdcall abi_TrySetLockScreenImageAsync(Windows::Storage::IStorageFile * imageFile, Windows::Foundation::IAsyncOperation<bool> ** operation) = 0;
    virtual HRESULT __stdcall abi_TrySetWallpaperImageAsync(Windows::Storage::IStorageFile * imageFile, Windows::Foundation::IAsyncOperation<bool> ** operation) = 0;
};

struct __declspec(uuid("91acb841-5037-454b-9883-bb772d08dd16")) __declspec(novtable) IUserProfilePersonalizationSettingsStatics : Windows::IInspectable
{
    virtual HRESULT __stdcall get_Current(Windows::System::UserProfile::IUserProfilePersonalizationSettings ** value) = 0;
    virtual HRESULT __stdcall abi_IsSupported(bool * result) = 0;
};

}

namespace ABI {

template <> struct traits<Windows::System::UserProfile::AdvertisingManagerForUser> { using default_interface = Windows::System::UserProfile::IAdvertisingManagerForUser; };
template <> struct traits<Windows::System::UserProfile::FirstSignInSettings> { using default_interface = Windows::System::UserProfile::IFirstSignInSettings; };
template <> struct traits<Windows::System::UserProfile::UserProfilePersonalizationSettings> { using default_interface = Windows::System::UserProfile::IUserProfilePersonalizationSettings; };

}

namespace Windows::System::UserProfile {

template <typename T> struct impl_IAdvertisingManagerForUser;
template <typename T> struct impl_IAdvertisingManagerStatics;
template <typename T> struct impl_IAdvertisingManagerStatics2;
template <typename T> struct impl_IFirstSignInSettings;
template <typename T> struct impl_IFirstSignInSettingsStatics;
template <typename T> struct impl_IGlobalizationPreferencesStatics;
template <typename T> struct impl_IUserProfilePersonalizationSettings;
template <typename T> struct impl_IUserProfilePersonalizationSettingsStatics;

}

namespace impl {

template <> struct traits<Windows::System::UserProfile::IAdvertisingManagerForUser>
{
    using abi = ABI::Windows::System::UserProfile::IAdvertisingManagerForUser;
    template <typename D> using consume = Windows::System::UserProfile::impl_IAdvertisingManagerForUser<D>;
};

template <> struct traits<Windows::System::UserProfile::IAdvertisingManagerStatics>
{
    using abi = ABI::Windows::System::UserProfile::IAdvertisingManagerStatics;
    template <typename D> using consume = Windows::System::UserProfile::impl_IAdvertisingManagerStatics<D>;
};

template <> struct traits<Windows::System::UserProfile::IAdvertisingManagerStatics2>
{
    using abi = ABI::Windows::System::UserProfile::IAdvertisingManagerStatics2;
    template <typename D> using consume = Windows::System::UserProfile::impl_IAdvertisingManagerStatics2<D>;
};

template <> struct traits<Windows::System::UserProfile::IFirstSignInSettings>
{
    using abi = ABI::Windows::System::UserProfile::IFirstSignInSettings;
    template <typename D> using consume = Windows::System::UserProfile::impl_IFirstSignInSettings<D>;
};

template <> struct traits<Windows::System::UserProfile::IFirstSignInSettingsStatics>
{
    using abi = ABI::Windows::System::UserProfile::IFirstSignInSettingsStatics;
    template <typename D> using consume = Windows::System::UserProfile::impl_IFirstSignInSettingsStatics<D>;
};

template <> struct traits<Windows::System::UserProfile::IGlobalizationPreferencesStatics>
{
    using abi = ABI::Windows::System::UserProfile::IGlobalizationPreferencesStatics;
    template <typename D> using consume = Windows::System::UserProfile::impl_IGlobalizationPreferencesStatics<D>;
};

template <> struct traits<Windows::System::UserProfile::IUserProfilePersonalizationSettings>
{
    using abi = ABI::Windows::System::UserProfile::IUserProfilePersonalizationSettings;
    template <typename D> using consume = Windows::System::UserProfile::impl_IUserProfilePersonalizationSettings<D>;
};

template <> struct traits<Windows::System::UserProfile::IUserProfilePersonalizationSettingsStatics>
{
    using abi = ABI::Windows::System::UserProfile::IUserProfilePersonalizationSettingsStatics;
    template <typename D> using consume = Windows::System::UserProfile::impl_IUserProfilePersonalizationSettingsStatics<D>;
};

template <> struct traits<Windows::System::UserProfile::AdvertisingManager>
{
    static constexpr const wchar_t * name() noexcept { return L"Windows.System.UserProfile.AdvertisingManager"; }
};

template <> struct traits<Windows::System::UserProfile::AdvertisingManagerForUser>
{
    using abi = ABI::Windows::System::UserProfile::AdvertisingManagerForUser;
    static constexpr const wchar_t * name() noexcept { return L"Windows.System.UserProfile.AdvertisingManagerForUser"; }
};

template <> struct traits<Windows::System::UserProfile::FirstSignInSettings>
{
    using abi = ABI::Windows::System::UserProfile::FirstSignInSettings;
    static constexpr const wchar_t * name() noexcept { return L"Windows.System.UserProfile.FirstSignInSettings"; }
};

template <> struct traits<Windows::System::UserProfile::GlobalizationPreferences>
{
    static constexpr const wchar_t * name() noexcept { return L"Windows.System.UserProfile.GlobalizationPreferences"; }
};

template <> struct traits<Windows::System::UserProfile::UserProfilePersonalizationSettings>
{
    using abi = ABI::Windows::System::UserProfile::UserProfilePersonalizationSettings;
    static constexpr const wchar_t * name() noexcept { return L"Windows.System.UserProfile.UserProfilePersonalizationSettings"; }
};

}

}
