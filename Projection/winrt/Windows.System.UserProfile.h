// C++ for the Windows Runtime v1.29
// Copyright (c) 2016 Microsoft Corporation

#pragma once

#include "internal\Windows.System.class.h"
#include "internal\Windows.Storage.class.h"
#include "internal\Windows.Foundation.class.h"
#include "internal\Windows.Foundation.Collections.class.h"
#include "internal\Windows.Globalization.class.h"
#include "internal\Windows.System.UserProfile.class.h"
#include "Windows.System.h"
#include "Windows.Foundation.Collections.h"

WINRT_EXPORT namespace winrt {

namespace impl {

template <typename D>
struct produce<D, Windows::System::UserProfile::IAdvertisingManagerForUser> : produce_base<D, Windows::System::UserProfile::IAdvertisingManagerForUser>
{
    HRESULT __stdcall get_AdvertisingId(abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            *value = detach(shim().AdvertisingId());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_User(abi_arg_out<Windows::System::IUser> value) noexcept override
    {
        try
        {
            *value = detach(shim().User());
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
    HRESULT __stdcall get_AdvertisingId(abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            *value = detach(shim().AdvertisingId());
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
    HRESULT __stdcall abi_GetForUser(abi_arg_in<Windows::System::IUser> user, abi_arg_out<Windows::System::UserProfile::IAdvertisingManagerForUser> value) noexcept override
    {
        try
        {
            *value = detach(shim().GetForUser(*reinterpret_cast<const Windows::System::User *>(&user)));
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
    HRESULT __stdcall abi_GetDefault(abi_arg_out<Windows::System::UserProfile::IFirstSignInSettings> result) noexcept override
    {
        try
        {
            *result = detach(shim().GetDefault());
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
    HRESULT __stdcall get_Calendars(abi_arg_out<Windows::Foundation::Collections::IVectorView<hstring>> value) noexcept override
    {
        try
        {
            *value = detach(shim().Calendars());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Clocks(abi_arg_out<Windows::Foundation::Collections::IVectorView<hstring>> value) noexcept override
    {
        try
        {
            *value = detach(shim().Clocks());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Currencies(abi_arg_out<Windows::Foundation::Collections::IVectorView<hstring>> value) noexcept override
    {
        try
        {
            *value = detach(shim().Currencies());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Languages(abi_arg_out<Windows::Foundation::Collections::IVectorView<hstring>> value) noexcept override
    {
        try
        {
            *value = detach(shim().Languages());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_HomeGeographicRegion(abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            *value = detach(shim().HomeGeographicRegion());
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
            *value = detach(shim().WeekStartsOn());
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
    HRESULT __stdcall abi_TrySetLockScreenImageAsync(abi_arg_in<Windows::Storage::IStorageFile> imageFile, abi_arg_out<Windows::Foundation::IAsyncOperation<bool>> operation) noexcept override
    {
        try
        {
            *operation = detach(shim().TrySetLockScreenImageAsync(*reinterpret_cast<const Windows::Storage::StorageFile *>(&imageFile)));
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_TrySetWallpaperImageAsync(abi_arg_in<Windows::Storage::IStorageFile> imageFile, abi_arg_out<Windows::Foundation::IAsyncOperation<bool>> operation) noexcept override
    {
        try
        {
            *operation = detach(shim().TrySetWallpaperImageAsync(*reinterpret_cast<const Windows::Storage::StorageFile *>(&imageFile)));
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
    HRESULT __stdcall get_Current(abi_arg_out<Windows::System::UserProfile::IUserProfilePersonalizationSettings> value) noexcept override
    {
        try
        {
            *value = detach(shim().Current());
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
            *result = detach(shim().IsSupported());
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
    check_hresult(shim()->get_AdvertisingId(put(value)));
    return value;
}

template <typename D> hstring impl_IAdvertisingManagerForUser<D>::AdvertisingId() const
{
    hstring value;
    check_hresult(shim()->get_AdvertisingId(put(value)));
    return value;
}

template <typename D> Windows::System::User impl_IAdvertisingManagerForUser<D>::User() const
{
    Windows::System::User value { nullptr };
    check_hresult(shim()->get_User(put(value)));
    return value;
}

template <typename D> Windows::System::UserProfile::AdvertisingManagerForUser impl_IAdvertisingManagerStatics2<D>::GetForUser(const Windows::System::User & user) const
{
    Windows::System::UserProfile::AdvertisingManagerForUser value { nullptr };
    check_hresult(shim()->abi_GetForUser(get(user), put(value)));
    return value;
}

template <typename D> Windows::Foundation::IAsyncOperation<bool> impl_IUserProfilePersonalizationSettings<D>::TrySetLockScreenImageAsync(const Windows::Storage::StorageFile & imageFile) const
{
    Windows::Foundation::IAsyncOperation<bool> operation;
    check_hresult(shim()->abi_TrySetLockScreenImageAsync(get(imageFile), put(operation)));
    return operation;
}

template <typename D> Windows::Foundation::IAsyncOperation<bool> impl_IUserProfilePersonalizationSettings<D>::TrySetWallpaperImageAsync(const Windows::Storage::StorageFile & imageFile) const
{
    Windows::Foundation::IAsyncOperation<bool> operation;
    check_hresult(shim()->abi_TrySetWallpaperImageAsync(get(imageFile), put(operation)));
    return operation;
}

template <typename D> Windows::System::UserProfile::UserProfilePersonalizationSettings impl_IUserProfilePersonalizationSettingsStatics<D>::Current() const
{
    Windows::System::UserProfile::UserProfilePersonalizationSettings value { nullptr };
    check_hresult(shim()->get_Current(put(value)));
    return value;
}

template <typename D> bool impl_IUserProfilePersonalizationSettingsStatics<D>::IsSupported() const
{
    bool result {};
    check_hresult(shim()->abi_IsSupported(&result));
    return result;
}

template <typename D> Windows::Foundation::Collections::IVectorView<hstring> impl_IGlobalizationPreferencesStatics<D>::Calendars() const
{
    Windows::Foundation::Collections::IVectorView<hstring> value;
    check_hresult(shim()->get_Calendars(put(value)));
    return value;
}

template <typename D> Windows::Foundation::Collections::IVectorView<hstring> impl_IGlobalizationPreferencesStatics<D>::Clocks() const
{
    Windows::Foundation::Collections::IVectorView<hstring> value;
    check_hresult(shim()->get_Clocks(put(value)));
    return value;
}

template <typename D> Windows::Foundation::Collections::IVectorView<hstring> impl_IGlobalizationPreferencesStatics<D>::Currencies() const
{
    Windows::Foundation::Collections::IVectorView<hstring> value;
    check_hresult(shim()->get_Currencies(put(value)));
    return value;
}

template <typename D> Windows::Foundation::Collections::IVectorView<hstring> impl_IGlobalizationPreferencesStatics<D>::Languages() const
{
    Windows::Foundation::Collections::IVectorView<hstring> value;
    check_hresult(shim()->get_Languages(put(value)));
    return value;
}

template <typename D> hstring impl_IGlobalizationPreferencesStatics<D>::HomeGeographicRegion() const
{
    hstring value;
    check_hresult(shim()->get_HomeGeographicRegion(put(value)));
    return value;
}

template <typename D> Windows::Globalization::DayOfWeek impl_IGlobalizationPreferencesStatics<D>::WeekStartsOn() const
{
    Windows::Globalization::DayOfWeek value {};
    check_hresult(shim()->get_WeekStartsOn(&value));
    return value;
}

template <typename D> Windows::System::UserProfile::FirstSignInSettings impl_IFirstSignInSettingsStatics<D>::GetDefault() const
{
    Windows::System::UserProfile::FirstSignInSettings result { nullptr };
    check_hresult(shim()->abi_GetDefault(put(result)));
    return result;
}

inline hstring AdvertisingManager::AdvertisingId()
{
    return GetActivationFactory<AdvertisingManager, IAdvertisingManagerStatics>().AdvertisingId();
}

inline Windows::System::UserProfile::AdvertisingManagerForUser AdvertisingManager::GetForUser(const Windows::System::User & user)
{
    return GetActivationFactory<AdvertisingManager, IAdvertisingManagerStatics2>().GetForUser(user);
}

inline Windows::System::UserProfile::FirstSignInSettings FirstSignInSettings::GetDefault()
{
    return GetActivationFactory<FirstSignInSettings, IFirstSignInSettingsStatics>().GetDefault();
}

inline Windows::Foundation::Collections::IVectorView<hstring> GlobalizationPreferences::Calendars()
{
    return GetActivationFactory<GlobalizationPreferences, IGlobalizationPreferencesStatics>().Calendars();
}

inline Windows::Foundation::Collections::IVectorView<hstring> GlobalizationPreferences::Clocks()
{
    return GetActivationFactory<GlobalizationPreferences, IGlobalizationPreferencesStatics>().Clocks();
}

inline Windows::Foundation::Collections::IVectorView<hstring> GlobalizationPreferences::Currencies()
{
    return GetActivationFactory<GlobalizationPreferences, IGlobalizationPreferencesStatics>().Currencies();
}

inline Windows::Foundation::Collections::IVectorView<hstring> GlobalizationPreferences::Languages()
{
    return GetActivationFactory<GlobalizationPreferences, IGlobalizationPreferencesStatics>().Languages();
}

inline hstring GlobalizationPreferences::HomeGeographicRegion()
{
    return GetActivationFactory<GlobalizationPreferences, IGlobalizationPreferencesStatics>().HomeGeographicRegion();
}

inline Windows::Globalization::DayOfWeek GlobalizationPreferences::WeekStartsOn()
{
    return GetActivationFactory<GlobalizationPreferences, IGlobalizationPreferencesStatics>().WeekStartsOn();
}

inline Windows::System::UserProfile::UserProfilePersonalizationSettings UserProfilePersonalizationSettings::Current()
{
    return GetActivationFactory<UserProfilePersonalizationSettings, IUserProfilePersonalizationSettingsStatics>().Current();
}

inline bool UserProfilePersonalizationSettings::IsSupported()
{
    return GetActivationFactory<UserProfilePersonalizationSettings, IUserProfilePersonalizationSettingsStatics>().IsSupported();
}

}

}
