// C++ for the Windows Runtime v1.29
// Copyright (c) 2016 Microsoft Corporation

#pragma once

#include "Windows.System.UserProfile.1.h"

WINRT_EXPORT namespace winrt {

namespace ABI::Windows::Foundation {

#ifndef WINRT_GENERIC_cdb5efb3_5788_509d_9be1_71ccb8a3362a
#define WINRT_GENERIC_cdb5efb3_5788_509d_9be1_71ccb8a3362a
template <> struct __declspec(uuid("cdb5efb3-5788-509d-9be1-71ccb8a3362a")) __declspec(novtable) IAsyncOperation<bool> : impl_IAsyncOperation<bool> {};
#endif


}

namespace ABI::Windows::Foundation::Collections {

#ifndef WINRT_GENERIC_09335560_6c6b_5a26_9348_97b781132b20
#define WINRT_GENERIC_09335560_6c6b_5a26_9348_97b781132b20
template <> struct __declspec(uuid("09335560-6c6b-5a26-9348-97b781132b20")) __declspec(novtable) IKeyValuePair<hstring, Windows::IInspectable> : impl_IKeyValuePair<hstring, Windows::IInspectable> {};
#endif

#ifndef WINRT_GENERIC_2f13c006_a03a_5f69_b090_75a43e33423e
#define WINRT_GENERIC_2f13c006_a03a_5f69_b090_75a43e33423e
template <> struct __declspec(uuid("2f13c006-a03a-5f69-b090-75a43e33423e")) __declspec(novtable) IVectorView<hstring> : impl_IVectorView<hstring> {};
#endif

#ifndef WINRT_GENERIC_bb78502a_f79d_54fa_92c9_90c5039fdf7e
#define WINRT_GENERIC_bb78502a_f79d_54fa_92c9_90c5039fdf7e
template <> struct __declspec(uuid("bb78502a-f79d-54fa-92c9-90c5039fdf7e")) __declspec(novtable) IMapView<hstring, Windows::IInspectable> : impl_IMapView<hstring, Windows::IInspectable> {};
#endif

#ifndef WINRT_GENERIC_e2fcc7c1_3bfc_5a0b_b2b0_72e769d1cb7e
#define WINRT_GENERIC_e2fcc7c1_3bfc_5a0b_b2b0_72e769d1cb7e
template <> struct __declspec(uuid("e2fcc7c1-3bfc-5a0b-b2b0-72e769d1cb7e")) __declspec(novtable) IIterable<hstring> : impl_IIterable<hstring> {};
#endif


}

namespace ABI::Windows::Foundation {

#ifndef WINRT_GENERIC_c1d3d1a2_ae17_5a5f_b5a2_bdcc8844889a
#define WINRT_GENERIC_c1d3d1a2_ae17_5a5f_b5a2_bdcc8844889a
template <> struct __declspec(uuid("c1d3d1a2-ae17-5a5f-b5a2-bdcc8844889a")) __declspec(novtable) AsyncOperationCompletedHandler<bool> : impl_AsyncOperationCompletedHandler<bool> {};
#endif


}

namespace ABI::Windows::Foundation::Collections {

#ifndef WINRT_GENERIC_8c304ebb_6615_50a4_8829_879ecd443236
#define WINRT_GENERIC_8c304ebb_6615_50a4_8829_879ecd443236
template <> struct __declspec(uuid("8c304ebb-6615-50a4-8829-879ecd443236")) __declspec(novtable) IIterator<hstring> : impl_IIterator<hstring> {};
#endif

#ifndef WINRT_GENERIC_fe2f3d47_5d47_5499_8374_430c7cda0204
#define WINRT_GENERIC_fe2f3d47_5d47_5499_8374_430c7cda0204
template <> struct __declspec(uuid("fe2f3d47-5d47-5499-8374-430c7cda0204")) __declspec(novtable) IIterable<Windows::Foundation::Collections::IKeyValuePair<hstring, Windows::IInspectable>> : impl_IIterable<Windows::Foundation::Collections::IKeyValuePair<hstring, Windows::IInspectable>> {};
#endif

#ifndef WINRT_GENERIC_5db5fa32_707c_5849_a06b_91c8eb9d10e8
#define WINRT_GENERIC_5db5fa32_707c_5849_a06b_91c8eb9d10e8
template <> struct __declspec(uuid("5db5fa32-707c-5849-a06b-91c8eb9d10e8")) __declspec(novtable) IIterator<Windows::Foundation::Collections::IKeyValuePair<hstring, Windows::IInspectable>> : impl_IIterator<Windows::Foundation::Collections::IKeyValuePair<hstring, Windows::IInspectable>> {};
#endif


}

namespace Windows::System::UserProfile {

template <typename D>
struct WINRT_EBO impl_IAdvertisingManagerForUser
{
    hstring AdvertisingId() const;
    Windows::System::User User() const;
};

template <typename D>
struct WINRT_EBO impl_IAdvertisingManagerStatics
{
    hstring AdvertisingId() const;
};

template <typename D>
struct WINRT_EBO impl_IAdvertisingManagerStatics2
{
    Windows::System::UserProfile::AdvertisingManagerForUser GetForUser(const Windows::System::User & user) const;
};

template <typename D>
struct WINRT_EBO impl_IFirstSignInSettings
{
};

template <typename D>
struct WINRT_EBO impl_IFirstSignInSettingsStatics
{
    Windows::System::UserProfile::FirstSignInSettings GetDefault() const;
};

template <typename D>
struct WINRT_EBO impl_IGlobalizationPreferencesStatics
{
    Windows::Foundation::Collections::IVectorView<hstring> Calendars() const;
    Windows::Foundation::Collections::IVectorView<hstring> Clocks() const;
    Windows::Foundation::Collections::IVectorView<hstring> Currencies() const;
    Windows::Foundation::Collections::IVectorView<hstring> Languages() const;
    hstring HomeGeographicRegion() const;
    Windows::Globalization::DayOfWeek WeekStartsOn() const;
};

template <typename D>
struct WINRT_EBO impl_IUserProfilePersonalizationSettings
{
    Windows::Foundation::IAsyncOperation<bool> TrySetLockScreenImageAsync(const Windows::Storage::StorageFile & imageFile) const;
    Windows::Foundation::IAsyncOperation<bool> TrySetWallpaperImageAsync(const Windows::Storage::StorageFile & imageFile) const;
};

template <typename D>
struct WINRT_EBO impl_IUserProfilePersonalizationSettingsStatics
{
    Windows::System::UserProfile::UserProfilePersonalizationSettings Current() const;
    bool IsSupported() const;
};

struct IAdvertisingManagerForUser :
    Windows::IInspectable,
    impl::consume<IAdvertisingManagerForUser>
{
    IAdvertisingManagerForUser(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IAdvertisingManagerForUser>(m_ptr); }
};

struct IAdvertisingManagerStatics :
    Windows::IInspectable,
    impl::consume<IAdvertisingManagerStatics>
{
    IAdvertisingManagerStatics(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IAdvertisingManagerStatics>(m_ptr); }
};

struct IAdvertisingManagerStatics2 :
    Windows::IInspectable,
    impl::consume<IAdvertisingManagerStatics2>
{
    IAdvertisingManagerStatics2(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IAdvertisingManagerStatics2>(m_ptr); }
};

struct IFirstSignInSettings :
    Windows::IInspectable,
    impl::consume<IFirstSignInSettings>,
    impl::require<IFirstSignInSettings, Windows::Foundation::Collections::IIterable<Windows::Foundation::Collections::IKeyValuePair<hstring, Windows::IInspectable>>, Windows::Foundation::Collections::IMapView<hstring, Windows::IInspectable>>
{
    IFirstSignInSettings(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IFirstSignInSettings>(m_ptr); }
};

struct IFirstSignInSettingsStatics :
    Windows::IInspectable,
    impl::consume<IFirstSignInSettingsStatics>
{
    IFirstSignInSettingsStatics(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IFirstSignInSettingsStatics>(m_ptr); }
};

struct IGlobalizationPreferencesStatics :
    Windows::IInspectable,
    impl::consume<IGlobalizationPreferencesStatics>
{
    IGlobalizationPreferencesStatics(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IGlobalizationPreferencesStatics>(m_ptr); }
};

struct IUserProfilePersonalizationSettings :
    Windows::IInspectable,
    impl::consume<IUserProfilePersonalizationSettings>
{
    IUserProfilePersonalizationSettings(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IUserProfilePersonalizationSettings>(m_ptr); }
};

struct IUserProfilePersonalizationSettingsStatics :
    Windows::IInspectable,
    impl::consume<IUserProfilePersonalizationSettingsStatics>
{
    IUserProfilePersonalizationSettingsStatics(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IUserProfilePersonalizationSettingsStatics>(m_ptr); }
};

}

}
