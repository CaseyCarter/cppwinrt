// C++ for the Windows Runtime v1.0.private
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "base.h"
WINRT_WARNING_PUSH

#include "internal/Windows.Storage.Streams.3.h"
#include "internal/Windows.System.3.h"
#include "internal/Windows.Foundation.3.h"
#include "internal/Windows.System.Profile.3.h"
#include "Windows.System.h"

WINRT_EXPORT namespace winrt {

namespace impl {

template <typename D>
struct produce<D, Windows::System::Profile::IAnalyticsInfoStatics> : produce_base<D, Windows::System::Profile::IAnalyticsInfoStatics>
{
    HRESULT __stdcall get_VersionInfo(impl::abi_arg_out<Windows::System::Profile::IAnalyticsVersionInfo> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().VersionInfo());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_DeviceForm(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().DeviceForm());
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
    HRESULT __stdcall get_DeviceFamily(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().DeviceFamily());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_DeviceFamilyVersion(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().DeviceFamilyVersion());
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
    HRESULT __stdcall abi_GetPackageSpecificToken(impl::abi_arg_in<Windows::Storage::Streams::IBuffer> nonce, impl::abi_arg_out<Windows::System::Profile::IHardwareToken> packageSpecificHardwareToken) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *packageSpecificHardwareToken = detach_abi(this->shim().GetPackageSpecificToken(*reinterpret_cast<const Windows::Storage::Streams::IBuffer *>(&nonce)));
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
    HRESULT __stdcall get_Id(impl::abi_arg_out<Windows::Storage::Streams::IBuffer> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Id());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Signature(impl::abi_arg_out<Windows::Storage::Streams::IBuffer> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Signature());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Certificate(impl::abi_arg_out<Windows::Storage::Streams::IBuffer> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Certificate());
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
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().CollectionLevel());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_CollectionLevelChanged(impl::abi_arg_in<Windows::Foundation::EventHandler<Windows::Foundation::IInspectable>> handler, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().CollectionLevelChanged(*reinterpret_cast<const Windows::Foundation::EventHandler<Windows::Foundation::IInspectable> *>(&handler)));
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
            typename D::abi_guard guard(this->shim());
            this->shim().CollectionLevelChanged(token);
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
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().CanCollectDiagnostics(level));
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
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IsEnabled());
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
    HRESULT __stdcall get_Id(impl::abi_arg_out<Windows::Storage::Streams::IBuffer> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Id());
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
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Source());
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
    HRESULT __stdcall abi_GetSystemIdForPublisher(impl::abi_arg_out<Windows::System::Profile::ISystemIdentificationInfo> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().GetSystemIdForPublisher());
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetSystemIdForUser(impl::abi_arg_in<Windows::System::IUser> user, impl::abi_arg_out<Windows::System::Profile::ISystemIdentificationInfo> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().GetSystemIdForUser(*reinterpret_cast<const Windows::System::User *>(&user)));
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
    check_hresult(WINRT_SHIM(IAnalyticsInfoStatics)->get_VersionInfo(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IAnalyticsInfoStatics<D>::DeviceForm() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IAnalyticsInfoStatics)->get_DeviceForm(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IAnalyticsVersionInfo<D>::DeviceFamily() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IAnalyticsVersionInfo)->get_DeviceFamily(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IAnalyticsVersionInfo<D>::DeviceFamilyVersion() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IAnalyticsVersionInfo)->get_DeviceFamilyVersion(put_abi(value)));
    return value;
}

template <typename D> Windows::Storage::Streams::IBuffer impl_ISystemIdentificationInfo<D>::Id() const
{
    Windows::Storage::Streams::IBuffer value;
    check_hresult(WINRT_SHIM(ISystemIdentificationInfo)->get_Id(put_abi(value)));
    return value;
}

template <typename D> Windows::System::Profile::SystemIdentificationSource impl_ISystemIdentificationInfo<D>::Source() const
{
    Windows::System::Profile::SystemIdentificationSource value {};
    check_hresult(WINRT_SHIM(ISystemIdentificationInfo)->get_Source(&value));
    return value;
}

template <typename D> Windows::System::Profile::SystemIdentificationInfo impl_ISystemIdentificationStatics<D>::GetSystemIdForPublisher() const
{
    Windows::System::Profile::SystemIdentificationInfo result { nullptr };
    check_hresult(WINRT_SHIM(ISystemIdentificationStatics)->abi_GetSystemIdForPublisher(put_abi(result)));
    return result;
}

template <typename D> Windows::System::Profile::SystemIdentificationInfo impl_ISystemIdentificationStatics<D>::GetSystemIdForUser(const Windows::System::User & user) const
{
    Windows::System::Profile::SystemIdentificationInfo result { nullptr };
    check_hresult(WINRT_SHIM(ISystemIdentificationStatics)->abi_GetSystemIdForUser(get_abi(user), put_abi(result)));
    return result;
}

template <typename D> Windows::System::Profile::PlatformDataCollectionLevel impl_IPlatformDiagnosticsAndUsageDataSettingsStatics<D>::CollectionLevel() const
{
    Windows::System::Profile::PlatformDataCollectionLevel value {};
    check_hresult(WINRT_SHIM(IPlatformDiagnosticsAndUsageDataSettingsStatics)->get_CollectionLevel(&value));
    return value;
}

template <typename D> event_token impl_IPlatformDiagnosticsAndUsageDataSettingsStatics<D>::CollectionLevelChanged(const Windows::Foundation::EventHandler<Windows::Foundation::IInspectable> & handler) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(IPlatformDiagnosticsAndUsageDataSettingsStatics)->add_CollectionLevelChanged(get_abi(handler), &token));
    return token;
}

template <typename D> event_revoker<IPlatformDiagnosticsAndUsageDataSettingsStatics> impl_IPlatformDiagnosticsAndUsageDataSettingsStatics<D>::CollectionLevelChanged(auto_revoke_t, const Windows::Foundation::EventHandler<Windows::Foundation::IInspectable> & handler) const
{
    return impl::make_event_revoker<D, IPlatformDiagnosticsAndUsageDataSettingsStatics>(this, &ABI::Windows::System::Profile::IPlatformDiagnosticsAndUsageDataSettingsStatics::remove_CollectionLevelChanged, CollectionLevelChanged(handler));
}

template <typename D> void impl_IPlatformDiagnosticsAndUsageDataSettingsStatics<D>::CollectionLevelChanged(event_token token) const
{
    check_hresult(WINRT_SHIM(IPlatformDiagnosticsAndUsageDataSettingsStatics)->remove_CollectionLevelChanged(token));
}

template <typename D> bool impl_IPlatformDiagnosticsAndUsageDataSettingsStatics<D>::CanCollectDiagnostics(Windows::System::Profile::PlatformDataCollectionLevel level) const
{
    bool result {};
    check_hresult(WINRT_SHIM(IPlatformDiagnosticsAndUsageDataSettingsStatics)->abi_CanCollectDiagnostics(level, &result));
    return result;
}

template <typename D> Windows::Storage::Streams::IBuffer impl_IHardwareToken<D>::Id() const
{
    Windows::Storage::Streams::IBuffer value;
    check_hresult(WINRT_SHIM(IHardwareToken)->get_Id(put_abi(value)));
    return value;
}

template <typename D> Windows::Storage::Streams::IBuffer impl_IHardwareToken<D>::Signature() const
{
    Windows::Storage::Streams::IBuffer value;
    check_hresult(WINRT_SHIM(IHardwareToken)->get_Signature(put_abi(value)));
    return value;
}

template <typename D> Windows::Storage::Streams::IBuffer impl_IHardwareToken<D>::Certificate() const
{
    Windows::Storage::Streams::IBuffer value;
    check_hresult(WINRT_SHIM(IHardwareToken)->get_Certificate(put_abi(value)));
    return value;
}

template <typename D> Windows::System::Profile::HardwareToken impl_IHardwareIdentificationStatics<D>::GetPackageSpecificToken(const Windows::Storage::Streams::IBuffer & nonce) const
{
    Windows::System::Profile::HardwareToken packageSpecificHardwareToken { nullptr };
    check_hresult(WINRT_SHIM(IHardwareIdentificationStatics)->abi_GetPackageSpecificToken(get_abi(nonce), put_abi(packageSpecificHardwareToken)));
    return packageSpecificHardwareToken;
}

template <typename D> bool impl_ISharedModeSettingsStatics<D>::IsEnabled() const
{
    bool value {};
    check_hresult(WINRT_SHIM(ISharedModeSettingsStatics)->get_IsEnabled(&value));
    return value;
}

inline Windows::System::Profile::AnalyticsVersionInfo AnalyticsInfo::VersionInfo()
{
    return get_activation_factory<AnalyticsInfo, IAnalyticsInfoStatics>().VersionInfo();
}

inline hstring AnalyticsInfo::DeviceForm()
{
    return get_activation_factory<AnalyticsInfo, IAnalyticsInfoStatics>().DeviceForm();
}

inline Windows::System::Profile::HardwareToken HardwareIdentification::GetPackageSpecificToken(const Windows::Storage::Streams::IBuffer & nonce)
{
    return get_activation_factory<HardwareIdentification, IHardwareIdentificationStatics>().GetPackageSpecificToken(nonce);
}

inline Windows::System::Profile::PlatformDataCollectionLevel PlatformDiagnosticsAndUsageDataSettings::CollectionLevel()
{
    return get_activation_factory<PlatformDiagnosticsAndUsageDataSettings, IPlatformDiagnosticsAndUsageDataSettingsStatics>().CollectionLevel();
}

inline event_token PlatformDiagnosticsAndUsageDataSettings::CollectionLevelChanged(const Windows::Foundation::EventHandler<Windows::Foundation::IInspectable> & handler)
{
    return get_activation_factory<PlatformDiagnosticsAndUsageDataSettings, IPlatformDiagnosticsAndUsageDataSettingsStatics>().CollectionLevelChanged(handler);
}

inline factory_event_revoker<IPlatformDiagnosticsAndUsageDataSettingsStatics> PlatformDiagnosticsAndUsageDataSettings::CollectionLevelChanged(auto_revoke_t, const Windows::Foundation::EventHandler<Windows::Foundation::IInspectable> & handler)
{
    auto factory = get_activation_factory<PlatformDiagnosticsAndUsageDataSettings, IPlatformDiagnosticsAndUsageDataSettingsStatics>();
    return { factory, &ABI::Windows::System::Profile::IPlatformDiagnosticsAndUsageDataSettingsStatics::remove_CollectionLevelChanged, factory.CollectionLevelChanged(handler) };
}

inline void PlatformDiagnosticsAndUsageDataSettings::CollectionLevelChanged(event_token token)
{
    get_activation_factory<PlatformDiagnosticsAndUsageDataSettings, IPlatformDiagnosticsAndUsageDataSettingsStatics>().CollectionLevelChanged(token);
}

inline bool PlatformDiagnosticsAndUsageDataSettings::CanCollectDiagnostics(Windows::System::Profile::PlatformDataCollectionLevel level)
{
    return get_activation_factory<PlatformDiagnosticsAndUsageDataSettings, IPlatformDiagnosticsAndUsageDataSettingsStatics>().CanCollectDiagnostics(level);
}

inline bool SharedModeSettings::IsEnabled()
{
    return get_activation_factory<SharedModeSettings, ISharedModeSettingsStatics>().IsEnabled();
}

inline Windows::System::Profile::SystemIdentificationInfo SystemIdentification::GetSystemIdForPublisher()
{
    return get_activation_factory<SystemIdentification, ISystemIdentificationStatics>().GetSystemIdForPublisher();
}

inline Windows::System::Profile::SystemIdentificationInfo SystemIdentification::GetSystemIdForUser(const Windows::System::User & user)
{
    return get_activation_factory<SystemIdentification, ISystemIdentificationStatics>().GetSystemIdForUser(user);
}

}

}

template<>
struct std::hash<winrt::Windows::System::Profile::IAnalyticsInfoStatics>
{
    size_t operator()(const winrt::Windows::System::Profile::IAnalyticsInfoStatics & value) const noexcept
    {
        return winrt::impl::hash_unknown(value);
    }
};

template<>
struct std::hash<winrt::Windows::System::Profile::IAnalyticsVersionInfo>
{
    size_t operator()(const winrt::Windows::System::Profile::IAnalyticsVersionInfo & value) const noexcept
    {
        return winrt::impl::hash_unknown(value);
    }
};

template<>
struct std::hash<winrt::Windows::System::Profile::IHardwareIdentificationStatics>
{
    size_t operator()(const winrt::Windows::System::Profile::IHardwareIdentificationStatics & value) const noexcept
    {
        return winrt::impl::hash_unknown(value);
    }
};

template<>
struct std::hash<winrt::Windows::System::Profile::IHardwareToken>
{
    size_t operator()(const winrt::Windows::System::Profile::IHardwareToken & value) const noexcept
    {
        return winrt::impl::hash_unknown(value);
    }
};

template<>
struct std::hash<winrt::Windows::System::Profile::IPlatformDiagnosticsAndUsageDataSettingsStatics>
{
    size_t operator()(const winrt::Windows::System::Profile::IPlatformDiagnosticsAndUsageDataSettingsStatics & value) const noexcept
    {
        return winrt::impl::hash_unknown(value);
    }
};

template<>
struct std::hash<winrt::Windows::System::Profile::ISharedModeSettingsStatics>
{
    size_t operator()(const winrt::Windows::System::Profile::ISharedModeSettingsStatics & value) const noexcept
    {
        return winrt::impl::hash_unknown(value);
    }
};

template<>
struct std::hash<winrt::Windows::System::Profile::ISystemIdentificationInfo>
{
    size_t operator()(const winrt::Windows::System::Profile::ISystemIdentificationInfo & value) const noexcept
    {
        return winrt::impl::hash_unknown(value);
    }
};

template<>
struct std::hash<winrt::Windows::System::Profile::ISystemIdentificationStatics>
{
    size_t operator()(const winrt::Windows::System::Profile::ISystemIdentificationStatics & value) const noexcept
    {
        return winrt::impl::hash_unknown(value);
    }
};

template<>
struct std::hash<winrt::Windows::System::Profile::AnalyticsVersionInfo>
{
    size_t operator()(const winrt::Windows::System::Profile::AnalyticsVersionInfo & value) const noexcept
    {
        return winrt::impl::hash_unknown(value);
    }
};

template<>
struct std::hash<winrt::Windows::System::Profile::HardwareToken>
{
    size_t operator()(const winrt::Windows::System::Profile::HardwareToken & value) const noexcept
    {
        return winrt::impl::hash_unknown(value);
    }
};

template<>
struct std::hash<winrt::Windows::System::Profile::SystemIdentificationInfo>
{
    size_t operator()(const winrt::Windows::System::Profile::SystemIdentificationInfo & value) const noexcept
    {
        return winrt::impl::hash_unknown(value);
    }
};

WINRT_WARNING_POP
