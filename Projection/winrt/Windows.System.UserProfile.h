// C++ for the Windows Runtime v1.0.private
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "internal/Windows.System.3.h"
#include "internal/Windows.Storage.3.h"
#include "internal/Windows.Foundation.3.h"
#include "internal/Windows.Foundation.Collections.3.h"
#include "internal/Windows.Globalization.3.h"
#include "internal/Windows.System.UserProfile.3.h"
#include "Windows.System.h"
#include "Windows.Foundation.Collections.h"

WINRT_EXPORT namespace winrt {

namespace impl {

template <typename D>
struct produce<D, Windows::System::UserProfile::IAdvertisingManagerForUser> : produce_base<D, Windows::System::UserProfile::IAdvertisingManagerForUser>
{
    HRESULT __stdcall get_AdvertisingId(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().AdvertisingId());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_User(impl::abi_arg_out<Windows::System::IUser> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().User());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::System::UserProfile::IAdvertisingManagerStatics> : produce_base<D, Windows::System::UserProfile::IAdvertisingManagerStatics>
{
    HRESULT __stdcall get_AdvertisingId(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().AdvertisingId());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::System::UserProfile::IAdvertisingManagerStatics2> : produce_base<D, Windows::System::UserProfile::IAdvertisingManagerStatics2>
{
    HRESULT __stdcall abi_GetForUser(impl::abi_arg_in<Windows::System::IUser> user, impl::abi_arg_out<Windows::System::UserProfile::IAdvertisingManagerForUser> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().GetForUser(*reinterpret_cast<const Windows::System::User *>(&user)));
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::System::UserProfile::IFirstSignInSettings> : produce_base<D, Windows::System::UserProfile::IFirstSignInSettings>
{};

template <typename D>
struct produce<D, Windows::System::UserProfile::IFirstSignInSettingsStatics> : produce_base<D, Windows::System::UserProfile::IFirstSignInSettingsStatics>
{
    HRESULT __stdcall abi_GetDefault(impl::abi_arg_out<Windows::System::UserProfile::IFirstSignInSettings> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().GetDefault());
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::System::UserProfile::IGlobalizationPreferencesStatics> : produce_base<D, Windows::System::UserProfile::IGlobalizationPreferencesStatics>
{
    HRESULT __stdcall get_Calendars(impl::abi_arg_out<Windows::Foundation::Collections::IVectorView<hstring>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Calendars());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Clocks(impl::abi_arg_out<Windows::Foundation::Collections::IVectorView<hstring>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Clocks());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Currencies(impl::abi_arg_out<Windows::Foundation::Collections::IVectorView<hstring>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Currencies());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Languages(impl::abi_arg_out<Windows::Foundation::Collections::IVectorView<hstring>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Languages());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_HomeGeographicRegion(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().HomeGeographicRegion());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_WeekStartsOn(Windows::Globalization::DayOfWeek * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().WeekStartsOn());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::System::UserProfile::IUserProfilePersonalizationSettings> : produce_base<D, Windows::System::UserProfile::IUserProfilePersonalizationSettings>
{
    HRESULT __stdcall abi_TrySetLockScreenImageAsync(impl::abi_arg_in<Windows::Storage::IStorageFile> imageFile, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<bool>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().TrySetLockScreenImageAsync(*reinterpret_cast<const Windows::Storage::StorageFile *>(&imageFile)));
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_TrySetWallpaperImageAsync(impl::abi_arg_in<Windows::Storage::IStorageFile> imageFile, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<bool>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().TrySetWallpaperImageAsync(*reinterpret_cast<const Windows::Storage::StorageFile *>(&imageFile)));
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::System::UserProfile::IUserProfilePersonalizationSettingsStatics> : produce_base<D, Windows::System::UserProfile::IUserProfilePersonalizationSettingsStatics>
{
    HRESULT __stdcall get_Current(impl::abi_arg_out<Windows::System::UserProfile::IUserProfilePersonalizationSettings> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Current());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_IsSupported(bool * result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().IsSupported());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

}

namespace Windows::System::UserProfile {

template <typename D> hstring impl_IAdvertisingManagerStatics<D>::AdvertisingId() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IAdvertisingManagerStatics)->get_AdvertisingId(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IAdvertisingManagerForUser<D>::AdvertisingId() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IAdvertisingManagerForUser)->get_AdvertisingId(put_abi(value)));
    return value;
}

template <typename D> Windows::System::User impl_IAdvertisingManagerForUser<D>::User() const
{
    Windows::System::User value { nullptr };
    check_hresult(WINRT_SHIM(IAdvertisingManagerForUser)->get_User(put_abi(value)));
    return value;
}

template <typename D> Windows::System::UserProfile::AdvertisingManagerForUser impl_IAdvertisingManagerStatics2<D>::GetForUser(const Windows::System::User & user) const
{
    Windows::System::UserProfile::AdvertisingManagerForUser value { nullptr };
    check_hresult(WINRT_SHIM(IAdvertisingManagerStatics2)->abi_GetForUser(get_abi(user), put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::IAsyncOperation<bool> impl_IUserProfilePersonalizationSettings<D>::TrySetLockScreenImageAsync(const Windows::Storage::StorageFile & imageFile) const
{
    Windows::Foundation::IAsyncOperation<bool> operation;
    check_hresult(WINRT_SHIM(IUserProfilePersonalizationSettings)->abi_TrySetLockScreenImageAsync(get_abi(imageFile), put_abi(operation)));
    return operation;
}

template <typename D> Windows::Foundation::IAsyncOperation<bool> impl_IUserProfilePersonalizationSettings<D>::TrySetWallpaperImageAsync(const Windows::Storage::StorageFile & imageFile) const
{
    Windows::Foundation::IAsyncOperation<bool> operation;
    check_hresult(WINRT_SHIM(IUserProfilePersonalizationSettings)->abi_TrySetWallpaperImageAsync(get_abi(imageFile), put_abi(operation)));
    return operation;
}

template <typename D> Windows::System::UserProfile::UserProfilePersonalizationSettings impl_IUserProfilePersonalizationSettingsStatics<D>::Current() const
{
    Windows::System::UserProfile::UserProfilePersonalizationSettings value { nullptr };
    check_hresult(WINRT_SHIM(IUserProfilePersonalizationSettingsStatics)->get_Current(put_abi(value)));
    return value;
}

template <typename D> bool impl_IUserProfilePersonalizationSettingsStatics<D>::IsSupported() const
{
    bool result {};
    check_hresult(WINRT_SHIM(IUserProfilePersonalizationSettingsStatics)->abi_IsSupported(&result));
    return result;
}

template <typename D> Windows::Foundation::Collections::IVectorView<hstring> impl_IGlobalizationPreferencesStatics<D>::Calendars() const
{
    Windows::Foundation::Collections::IVectorView<hstring> value;
    check_hresult(WINRT_SHIM(IGlobalizationPreferencesStatics)->get_Calendars(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::Collections::IVectorView<hstring> impl_IGlobalizationPreferencesStatics<D>::Clocks() const
{
    Windows::Foundation::Collections::IVectorView<hstring> value;
    check_hresult(WINRT_SHIM(IGlobalizationPreferencesStatics)->get_Clocks(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::Collections::IVectorView<hstring> impl_IGlobalizationPreferencesStatics<D>::Currencies() const
{
    Windows::Foundation::Collections::IVectorView<hstring> value;
    check_hresult(WINRT_SHIM(IGlobalizationPreferencesStatics)->get_Currencies(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::Collections::IVectorView<hstring> impl_IGlobalizationPreferencesStatics<D>::Languages() const
{
    Windows::Foundation::Collections::IVectorView<hstring> value;
    check_hresult(WINRT_SHIM(IGlobalizationPreferencesStatics)->get_Languages(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IGlobalizationPreferencesStatics<D>::HomeGeographicRegion() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IGlobalizationPreferencesStatics)->get_HomeGeographicRegion(put_abi(value)));
    return value;
}

template <typename D> Windows::Globalization::DayOfWeek impl_IGlobalizationPreferencesStatics<D>::WeekStartsOn() const
{
    Windows::Globalization::DayOfWeek value {};
    check_hresult(WINRT_SHIM(IGlobalizationPreferencesStatics)->get_WeekStartsOn(&value));
    return value;
}

template <typename D> Windows::System::UserProfile::FirstSignInSettings impl_IFirstSignInSettingsStatics<D>::GetDefault() const
{
    Windows::System::UserProfile::FirstSignInSettings result { nullptr };
    check_hresult(WINRT_SHIM(IFirstSignInSettingsStatics)->abi_GetDefault(put_abi(result)));
    return result;
}

inline hstring AdvertisingManager::AdvertisingId()
{
    return get_activation_factory<AdvertisingManager, IAdvertisingManagerStatics>().AdvertisingId();
}

inline Windows::System::UserProfile::AdvertisingManagerForUser AdvertisingManager::GetForUser(const Windows::System::User & user)
{
    return get_activation_factory<AdvertisingManager, IAdvertisingManagerStatics2>().GetForUser(user);
}

inline Windows::System::UserProfile::FirstSignInSettings FirstSignInSettings::GetDefault()
{
    return get_activation_factory<FirstSignInSettings, IFirstSignInSettingsStatics>().GetDefault();
}

inline Windows::Foundation::Collections::IVectorView<hstring> GlobalizationPreferences::Calendars()
{
    return get_activation_factory<GlobalizationPreferences, IGlobalizationPreferencesStatics>().Calendars();
}

inline Windows::Foundation::Collections::IVectorView<hstring> GlobalizationPreferences::Clocks()
{
    return get_activation_factory<GlobalizationPreferences, IGlobalizationPreferencesStatics>().Clocks();
}

inline Windows::Foundation::Collections::IVectorView<hstring> GlobalizationPreferences::Currencies()
{
    return get_activation_factory<GlobalizationPreferences, IGlobalizationPreferencesStatics>().Currencies();
}

inline Windows::Foundation::Collections::IVectorView<hstring> GlobalizationPreferences::Languages()
{
    return get_activation_factory<GlobalizationPreferences, IGlobalizationPreferencesStatics>().Languages();
}

inline hstring GlobalizationPreferences::HomeGeographicRegion()
{
    return get_activation_factory<GlobalizationPreferences, IGlobalizationPreferencesStatics>().HomeGeographicRegion();
}

inline Windows::Globalization::DayOfWeek GlobalizationPreferences::WeekStartsOn()
{
    return get_activation_factory<GlobalizationPreferences, IGlobalizationPreferencesStatics>().WeekStartsOn();
}

inline Windows::System::UserProfile::UserProfilePersonalizationSettings UserProfilePersonalizationSettings::Current()
{
    return get_activation_factory<UserProfilePersonalizationSettings, IUserProfilePersonalizationSettingsStatics>().Current();
}

inline bool UserProfilePersonalizationSettings::IsSupported()
{
    return get_activation_factory<UserProfilePersonalizationSettings, IUserProfilePersonalizationSettingsStatics>().IsSupported();
}

}

}
