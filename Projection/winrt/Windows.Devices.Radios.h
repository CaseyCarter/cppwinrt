// C++ for the Windows Runtime v1.0.private
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "internal/Windows.Foundation.3.h"
#include "internal/Windows.Devices.Radios.3.h"
#include "Windows.Devices.h"

WINRT_EXPORT namespace winrt {

namespace impl {

template <typename D>
struct produce<D, Windows::Devices::Radios::IRadio> : produce_base<D, Windows::Devices::Radios::IRadio>
{
    HRESULT __stdcall abi_SetStateAsync(Windows::Devices::Radios::RadioState value, abi_arg_out<Windows::Foundation::IAsyncOperation<winrt::Windows::Devices::Radios::RadioAccessStatus>> retval) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *retval = detach(this->shim().SetStateAsync(value));
            return S_OK;
        }
        catch (...)
        {
            *retval = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_StateChanged(abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::Devices::Radios::Radio, Windows::IInspectable>> handler, event_token * eventCookie) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *eventCookie = detach(this->shim().StateChanged(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::Devices::Radios::Radio, Windows::IInspectable> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_StateChanged(event_token eventCookie) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().StateChanged(eventCookie);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_State(Windows::Devices::Radios::RadioState * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach(this->shim().State());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Name(abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach(this->shim().Name());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Kind(Windows::Devices::Radios::RadioKind * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach(this->shim().Kind());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Devices::Radios::IRadioStatics> : produce_base<D, Windows::Devices::Radios::IRadioStatics>
{
    HRESULT __stdcall abi_GetRadiosAsync(abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::Devices::Radios::Radio>>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach(this->shim().GetRadiosAsync());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetDeviceSelector(abi_arg_out<hstring> deviceSelector) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *deviceSelector = detach(this->shim().GetDeviceSelector());
            return S_OK;
        }
        catch (...)
        {
            *deviceSelector = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_FromIdAsync(abi_arg_in<hstring> deviceId, abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Devices::Radios::Radio>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach(this->shim().FromIdAsync(*reinterpret_cast<const hstring *>(&deviceId)));
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_RequestAccessAsync(abi_arg_out<Windows::Foundation::IAsyncOperation<winrt::Windows::Devices::Radios::RadioAccessStatus>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach(this->shim().RequestAccessAsync());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }
};

}

namespace Windows::Devices::Radios {

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::Devices::Radios::Radio>> impl_IRadioStatics<D>::GetRadiosAsync() const
{
    Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::Devices::Radios::Radio>> value;
    check_hresult(WINRT_SHIM(IRadioStatics)->abi_GetRadiosAsync(put(value)));
    return value;
}

template <typename D> hstring impl_IRadioStatics<D>::GetDeviceSelector() const
{
    hstring deviceSelector;
    check_hresult(WINRT_SHIM(IRadioStatics)->abi_GetDeviceSelector(put(deviceSelector)));
    return deviceSelector;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Devices::Radios::Radio> impl_IRadioStatics<D>::FromIdAsync(hstring_ref deviceId) const
{
    Windows::Foundation::IAsyncOperation<Windows::Devices::Radios::Radio> value;
    check_hresult(WINRT_SHIM(IRadioStatics)->abi_FromIdAsync(get(deviceId), put(value)));
    return value;
}

template <typename D> Windows::Foundation::IAsyncOperation<winrt::Windows::Devices::Radios::RadioAccessStatus> impl_IRadioStatics<D>::RequestAccessAsync() const
{
    Windows::Foundation::IAsyncOperation<winrt::Windows::Devices::Radios::RadioAccessStatus> value;
    check_hresult(WINRT_SHIM(IRadioStatics)->abi_RequestAccessAsync(put(value)));
    return value;
}

template <typename D> Windows::Foundation::IAsyncOperation<winrt::Windows::Devices::Radios::RadioAccessStatus> impl_IRadio<D>::SetStateAsync(Windows::Devices::Radios::RadioState value) const
{
    Windows::Foundation::IAsyncOperation<winrt::Windows::Devices::Radios::RadioAccessStatus> retval;
    check_hresult(WINRT_SHIM(IRadio)->abi_SetStateAsync(value, put(retval)));
    return retval;
}

template <typename D> event_token impl_IRadio<D>::StateChanged(const Windows::Foundation::TypedEventHandler<Windows::Devices::Radios::Radio, Windows::IInspectable> & handler) const
{
    event_token eventCookie {};
    check_hresult(WINRT_SHIM(IRadio)->add_StateChanged(get(handler), &eventCookie));
    return eventCookie;
}

template <typename D> event_revoker<IRadio> impl_IRadio<D>::StateChanged(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Devices::Radios::Radio, Windows::IInspectable> & handler) const
{
    return impl::make_event_revoker<D, IRadio>(this, &ABI::Windows::Devices::Radios::IRadio::remove_StateChanged, StateChanged(handler));
}

template <typename D> void impl_IRadio<D>::StateChanged(event_token eventCookie) const
{
    check_hresult(WINRT_SHIM(IRadio)->remove_StateChanged(eventCookie));
}

template <typename D> Windows::Devices::Radios::RadioState impl_IRadio<D>::State() const
{
    Windows::Devices::Radios::RadioState value {};
    check_hresult(WINRT_SHIM(IRadio)->get_State(&value));
    return value;
}

template <typename D> hstring impl_IRadio<D>::Name() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IRadio)->get_Name(put(value)));
    return value;
}

template <typename D> Windows::Devices::Radios::RadioKind impl_IRadio<D>::Kind() const
{
    Windows::Devices::Radios::RadioKind value {};
    check_hresult(WINRT_SHIM(IRadio)->get_Kind(&value));
    return value;
}

inline Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::Devices::Radios::Radio>> Radio::GetRadiosAsync()
{
    return get_activation_factory<Radio, IRadioStatics>().GetRadiosAsync();
}

inline hstring Radio::GetDeviceSelector()
{
    return get_activation_factory<Radio, IRadioStatics>().GetDeviceSelector();
}

inline Windows::Foundation::IAsyncOperation<Windows::Devices::Radios::Radio> Radio::FromIdAsync(hstring_ref deviceId)
{
    return get_activation_factory<Radio, IRadioStatics>().FromIdAsync(deviceId);
}

inline Windows::Foundation::IAsyncOperation<winrt::Windows::Devices::Radios::RadioAccessStatus> Radio::RequestAccessAsync()
{
    return get_activation_factory<Radio, IRadioStatics>().RequestAccessAsync();
}

}

}
