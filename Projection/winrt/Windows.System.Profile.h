// C++ for the Windows Runtime v1.29
// Copyright (c) 2016 Microsoft Corporation

#pragma once

#include "internal\Windows.System.Profile.class.h"
#include "internal\Windows.Storage.Streams.class.h"
#include "internal\Windows.System.class.h"
#include "internal\Windows.Foundation.class.h"
#include "Windows.System.h"

WINRT_EXPORT namespace winrt {

namespace impl {

template <typename D>
struct produce<D, Windows::System::Profile::IAnalyticsInfoStatics> : produce_base<D, Windows::System::Profile::IAnalyticsInfoStatics>
{
    HRESULT __stdcall get_VersionInfo(abi_arg_out<Windows::System::Profile::IAnalyticsVersionInfo> value) noexcept override
    {
        try
        {
            *value = detach(shim().VersionInfo());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_DeviceForm(abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            *value = detach(shim().DeviceForm());
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
struct produce<D, Windows::System::Profile::IAnalyticsVersionInfo> : produce_base<D, Windows::System::Profile::IAnalyticsVersionInfo>
{
    HRESULT __stdcall get_DeviceFamily(abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            *value = detach(shim().DeviceFamily());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_DeviceFamilyVersion(abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            *value = detach(shim().DeviceFamilyVersion());
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
struct produce<D, Windows::System::Profile::IHardwareIdentificationStatics> : produce_base<D, Windows::System::Profile::IHardwareIdentificationStatics>
{
    HRESULT __stdcall abi_GetPackageSpecificToken(abi_arg_in<Windows::Storage::Streams::IBuffer> nonce, abi_arg_out<Windows::System::Profile::IHardwareToken> packageSpecificHardwareToken) noexcept override
    {
        try
        {
            *packageSpecificHardwareToken = detach(shim().GetPackageSpecificToken(*reinterpret_cast<const Windows::Storage::Streams::IBuffer *>(&nonce)));
            return S_OK;
        }
        catch (...)
        {
            *packageSpecificHardwareToken = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::System::Profile::IHardwareToken> : produce_base<D, Windows::System::Profile::IHardwareToken>
{
    HRESULT __stdcall get_Id(abi_arg_out<Windows::Storage::Streams::IBuffer> value) noexcept override
    {
        try
        {
            *value = detach(shim().Id());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Signature(abi_arg_out<Windows::Storage::Streams::IBuffer> value) noexcept override
    {
        try
        {
            *value = detach(shim().Signature());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Certificate(abi_arg_out<Windows::Storage::Streams::IBuffer> value) noexcept override
    {
        try
        {
            *value = detach(shim().Certificate());
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
struct produce<D, Windows::System::Profile::IPlatformDiagnosticsAndUsageDataSettingsStatics> : produce_base<D, Windows::System::Profile::IPlatformDiagnosticsAndUsageDataSettingsStatics>
{
    HRESULT __stdcall get_CollectionLevel(Windows::System::Profile::PlatformDataCollectionLevel * value) noexcept override
    {
        try
        {
            *value = detach(shim().CollectionLevel());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_CollectionLevelChanged(abi_arg_in<Windows::Foundation::EventHandler<Windows::IInspectable>> handler, event_token * token) noexcept override
    {
        try
        {
            *token = detach(shim().CollectionLevelChanged(*reinterpret_cast<const Windows::Foundation::EventHandler<Windows::IInspectable> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_CollectionLevelChanged(event_token token) noexcept override
    {
        try
        {
            shim().CollectionLevelChanged(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_CanCollectDiagnostics(Windows::System::Profile::PlatformDataCollectionLevel level, bool * result) noexcept override
    {
        try
        {
            *result = detach(shim().CanCollectDiagnostics(level));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::System::Profile::ISharedModeSettingsStatics> : produce_base<D, Windows::System::Profile::ISharedModeSettingsStatics>
{
    HRESULT __stdcall get_IsEnabled(bool * value) noexcept override
    {
        try
        {
            *value = detach(shim().IsEnabled());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::System::Profile::ISystemIdentificationInfo> : produce_base<D, Windows::System::Profile::ISystemIdentificationInfo>
{
    HRESULT __stdcall get_Id(abi_arg_out<Windows::Storage::Streams::IBuffer> value) noexcept override
    {
        try
        {
            *value = detach(shim().Id());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Source(Windows::System::Profile::SystemIdentificationSource * value) noexcept override
    {
        try
        {
            *value = detach(shim().Source());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::System::Profile::ISystemIdentificationStatics> : produce_base<D, Windows::System::Profile::ISystemIdentificationStatics>
{
    HRESULT __stdcall abi_GetSystemIdForPublisher(abi_arg_out<Windows::System::Profile::ISystemIdentificationInfo> result) noexcept override
    {
        try
        {
            *result = detach(shim().GetSystemIdForPublisher());
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetSystemIdForUser(abi_arg_in<Windows::System::IUser> user, abi_arg_out<Windows::System::Profile::ISystemIdentificationInfo> result) noexcept override
    {
        try
        {
            *result = detach(shim().GetSystemIdForUser(*reinterpret_cast<const Windows::System::User *>(&user)));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }
};

}

namespace Windows::System::Profile {

template <typename D> Windows::System::Profile::AnalyticsVersionInfo impl_IAnalyticsInfoStatics<D>::VersionInfo() const
{
    Windows::System::Profile::AnalyticsVersionInfo value { nullptr };
    check_hresult(shim()->get_VersionInfo(put(value)));
    return value;
}

template <typename D> hstring impl_IAnalyticsInfoStatics<D>::DeviceForm() const
{
    hstring value;
    check_hresult(shim()->get_DeviceForm(put(value)));
    return value;
}

template <typename D> hstring impl_IAnalyticsVersionInfo<D>::DeviceFamily() const
{
    hstring value;
    check_hresult(shim()->get_DeviceFamily(put(value)));
    return value;
}

template <typename D> hstring impl_IAnalyticsVersionInfo<D>::DeviceFamilyVersion() const
{
    hstring value;
    check_hresult(shim()->get_DeviceFamilyVersion(put(value)));
    return value;
}

template <typename D> Windows::Storage::Streams::IBuffer impl_ISystemIdentificationInfo<D>::Id() const
{
    Windows::Storage::Streams::IBuffer value;
    check_hresult(shim()->get_Id(put(value)));
    return value;
}

template <typename D> Windows::System::Profile::SystemIdentificationSource impl_ISystemIdentificationInfo<D>::Source() const
{
    Windows::System::Profile::SystemIdentificationSource value {};
    check_hresult(shim()->get_Source(&value));
    return value;
}

template <typename D> Windows::System::Profile::SystemIdentificationInfo impl_ISystemIdentificationStatics<D>::GetSystemIdForPublisher() const
{
    Windows::System::Profile::SystemIdentificationInfo result { nullptr };
    check_hresult(shim()->abi_GetSystemIdForPublisher(put(result)));
    return result;
}

template <typename D> Windows::System::Profile::SystemIdentificationInfo impl_ISystemIdentificationStatics<D>::GetSystemIdForUser(const Windows::System::User & user) const
{
    Windows::System::Profile::SystemIdentificationInfo result { nullptr };
    check_hresult(shim()->abi_GetSystemIdForUser(get(user), put(result)));
    return result;
}

template <typename D> Windows::System::Profile::PlatformDataCollectionLevel impl_IPlatformDiagnosticsAndUsageDataSettingsStatics<D>::CollectionLevel() const
{
    Windows::System::Profile::PlatformDataCollectionLevel value {};
    check_hresult(shim()->get_CollectionLevel(&value));
    return value;
}

template <typename D> event_token impl_IPlatformDiagnosticsAndUsageDataSettingsStatics<D>::CollectionLevelChanged(const Windows::Foundation::EventHandler<Windows::IInspectable> & handler) const
{
    event_token token {};
    check_hresult(shim()->add_CollectionLevelChanged(get(handler), &token));
    return token;
}

template <typename D> event_revoker<IPlatformDiagnosticsAndUsageDataSettingsStatics> impl_IPlatformDiagnosticsAndUsageDataSettingsStatics<D>::CollectionLevelChanged(auto_revoke_t, const Windows::Foundation::EventHandler<Windows::IInspectable> & handler) const
{
    return impl::make_event_revoker<D, IPlatformDiagnosticsAndUsageDataSettingsStatics>(this, &ABI::Windows::System::Profile::IPlatformDiagnosticsAndUsageDataSettingsStatics::remove_CollectionLevelChanged, CollectionLevelChanged(handler));
}

template <typename D> void impl_IPlatformDiagnosticsAndUsageDataSettingsStatics<D>::CollectionLevelChanged(event_token token) const
{
    check_hresult(shim()->remove_CollectionLevelChanged(token));
}

template <typename D> bool impl_IPlatformDiagnosticsAndUsageDataSettingsStatics<D>::CanCollectDiagnostics(Windows::System::Profile::PlatformDataCollectionLevel level) const
{
    bool result {};
    check_hresult(shim()->abi_CanCollectDiagnostics(level, &result));
    return result;
}

template <typename D> Windows::Storage::Streams::IBuffer impl_IHardwareToken<D>::Id() const
{
    Windows::Storage::Streams::IBuffer value;
    check_hresult(shim()->get_Id(put(value)));
    return value;
}

template <typename D> Windows::Storage::Streams::IBuffer impl_IHardwareToken<D>::Signature() const
{
    Windows::Storage::Streams::IBuffer value;
    check_hresult(shim()->get_Signature(put(value)));
    return value;
}

template <typename D> Windows::Storage::Streams::IBuffer impl_IHardwareToken<D>::Certificate() const
{
    Windows::Storage::Streams::IBuffer value;
    check_hresult(shim()->get_Certificate(put(value)));
    return value;
}

template <typename D> Windows::System::Profile::HardwareToken impl_IHardwareIdentificationStatics<D>::GetPackageSpecificToken(const Windows::Storage::Streams::IBuffer & nonce) const
{
    Windows::System::Profile::HardwareToken packageSpecificHardwareToken { nullptr };
    check_hresult(shim()->abi_GetPackageSpecificToken(get(nonce), put(packageSpecificHardwareToken)));
    return packageSpecificHardwareToken;
}

template <typename D> bool impl_ISharedModeSettingsStatics<D>::IsEnabled() const
{
    bool value {};
    check_hresult(shim()->get_IsEnabled(&value));
    return value;
}

inline Windows::System::Profile::AnalyticsVersionInfo AnalyticsInfo::VersionInfo()
{
    return GetActivationFactory<AnalyticsInfo, IAnalyticsInfoStatics>().VersionInfo();
}

inline hstring AnalyticsInfo::DeviceForm()
{
    return GetActivationFactory<AnalyticsInfo, IAnalyticsInfoStatics>().DeviceForm();
}

inline Windows::System::Profile::HardwareToken HardwareIdentification::GetPackageSpecificToken(const Windows::Storage::Streams::IBuffer & nonce)
{
    return GetActivationFactory<HardwareIdentification, IHardwareIdentificationStatics>().GetPackageSpecificToken(nonce);
}

inline Windows::System::Profile::PlatformDataCollectionLevel PlatformDiagnosticsAndUsageDataSettings::CollectionLevel()
{
    return GetActivationFactory<PlatformDiagnosticsAndUsageDataSettings, IPlatformDiagnosticsAndUsageDataSettingsStatics>().CollectionLevel();
}

inline event_token PlatformDiagnosticsAndUsageDataSettings::CollectionLevelChanged(const Windows::Foundation::EventHandler<Windows::IInspectable> & handler)
{
    return GetActivationFactory<PlatformDiagnosticsAndUsageDataSettings, IPlatformDiagnosticsAndUsageDataSettingsStatics>().CollectionLevelChanged(handler);
}

inline factory_event_revoker<IPlatformDiagnosticsAndUsageDataSettingsStatics> PlatformDiagnosticsAndUsageDataSettings::CollectionLevelChanged(auto_revoke_t, const Windows::Foundation::EventHandler<Windows::IInspectable> & handler)
{
    auto factory = GetActivationFactory<PlatformDiagnosticsAndUsageDataSettings, IPlatformDiagnosticsAndUsageDataSettingsStatics>();
    return { factory, &ABI::Windows::System::Profile::IPlatformDiagnosticsAndUsageDataSettingsStatics::remove_CollectionLevelChanged, factory.CollectionLevelChanged(handler) };
}

inline void PlatformDiagnosticsAndUsageDataSettings::CollectionLevelChanged(event_token token)
{
    GetActivationFactory<PlatformDiagnosticsAndUsageDataSettings, IPlatformDiagnosticsAndUsageDataSettingsStatics>().CollectionLevelChanged(token);
}

inline bool PlatformDiagnosticsAndUsageDataSettings::CanCollectDiagnostics(Windows::System::Profile::PlatformDataCollectionLevel level)
{
    return GetActivationFactory<PlatformDiagnosticsAndUsageDataSettings, IPlatformDiagnosticsAndUsageDataSettingsStatics>().CanCollectDiagnostics(level);
}

inline bool SharedModeSettings::IsEnabled()
{
    return GetActivationFactory<SharedModeSettings, ISharedModeSettingsStatics>().IsEnabled();
}

inline Windows::System::Profile::SystemIdentificationInfo SystemIdentification::GetSystemIdForPublisher()
{
    return GetActivationFactory<SystemIdentification, ISystemIdentificationStatics>().GetSystemIdForPublisher();
}

inline Windows::System::Profile::SystemIdentificationInfo SystemIdentification::GetSystemIdForUser(const Windows::System::User & user)
{
    return GetActivationFactory<SystemIdentification, ISystemIdentificationStatics>().GetSystemIdForUser(user);
}

}

}
