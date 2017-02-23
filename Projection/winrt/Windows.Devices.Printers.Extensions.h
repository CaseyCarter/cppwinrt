// C++ for the Windows Runtime v1.0.private
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once
#pragma warning(push)
#pragma warning(disable: 4996)

#include "internal/Windows.Foundation.3.h"
#include "internal/Windows.Devices.Printers.Extensions.3.h"
#include "Windows.Devices.Printers.h"

WINRT_EXPORT namespace winrt {

namespace impl {

template <typename D>
struct produce<D, Windows::Devices::Printers::Extensions::IPrint3DWorkflow> : produce_base<D, Windows::Devices::Printers::Extensions::IPrint3DWorkflow>
{
    HRESULT __stdcall get_DeviceID(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().DeviceID());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetPrintModelPackage(impl::abi_arg_out<Windows::Foundation::IInspectable> printModelPackage) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *printModelPackage = detach_abi(this->shim().GetPrintModelPackage());
            return S_OK;
        }
        catch (...)
        {
            *printModelPackage = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_IsPrintReady(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IsPrintReady());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_IsPrintReady(bool value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().IsPrintReady(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_PrintRequested(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::Devices::Printers::Extensions::Print3DWorkflow, Windows::Devices::Printers::Extensions::Print3DWorkflowPrintRequestedEventArgs>> eventHandler, event_token * eventCookie) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *eventCookie = detach_abi(this->shim().PrintRequested(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::Devices::Printers::Extensions::Print3DWorkflow, Windows::Devices::Printers::Extensions::Print3DWorkflowPrintRequestedEventArgs> *>(&eventHandler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_PrintRequested(event_token eventCookie) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().PrintRequested(eventCookie);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Devices::Printers::Extensions::IPrint3DWorkflow2> : produce_base<D, Windows::Devices::Printers::Extensions::IPrint3DWorkflow2>
{
    HRESULT __stdcall add_PrinterChanged(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::Devices::Printers::Extensions::Print3DWorkflow, Windows::Devices::Printers::Extensions::Print3DWorkflowPrinterChangedEventArgs>> eventHandler, event_token * eventCookie) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *eventCookie = detach_abi(this->shim().PrinterChanged(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::Devices::Printers::Extensions::Print3DWorkflow, Windows::Devices::Printers::Extensions::Print3DWorkflowPrinterChangedEventArgs> *>(&eventHandler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_PrinterChanged(event_token eventCookie) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().PrinterChanged(eventCookie);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Devices::Printers::Extensions::IPrint3DWorkflowPrintRequestedEventArgs> : produce_base<D, Windows::Devices::Printers::Extensions::IPrint3DWorkflowPrintRequestedEventArgs>
{
    HRESULT __stdcall get_Status(Windows::Devices::Printers::Extensions::Print3DWorkflowStatus * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Status());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_SetExtendedStatus(Windows::Devices::Printers::Extensions::Print3DWorkflowDetail value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SetExtendedStatus(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_SetSource(impl::abi_arg_in<Windows::Foundation::IInspectable> source) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SetSource(*reinterpret_cast<const Windows::Foundation::IInspectable *>(&source));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_SetSourceChanged(bool value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SetSourceChanged(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Devices::Printers::Extensions::IPrint3DWorkflowPrinterChangedEventArgs> : produce_base<D, Windows::Devices::Printers::Extensions::IPrint3DWorkflowPrinterChangedEventArgs>
{
    HRESULT __stdcall get_NewDeviceId(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().NewDeviceId());
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

namespace Windows::Devices::Printers::Extensions {

template <typename D> Windows::Devices::Printers::Extensions::Print3DWorkflowStatus impl_IPrint3DWorkflowPrintRequestedEventArgs<D>::Status() const
{
    Windows::Devices::Printers::Extensions::Print3DWorkflowStatus value {};
    check_hresult(WINRT_SHIM(IPrint3DWorkflowPrintRequestedEventArgs)->get_Status(&value));
    return value;
}

template <typename D> void impl_IPrint3DWorkflowPrintRequestedEventArgs<D>::SetExtendedStatus(Windows::Devices::Printers::Extensions::Print3DWorkflowDetail value) const
{
    check_hresult(WINRT_SHIM(IPrint3DWorkflowPrintRequestedEventArgs)->abi_SetExtendedStatus(value));
}

template <typename D> void impl_IPrint3DWorkflowPrintRequestedEventArgs<D>::SetSource(const Windows::Foundation::IInspectable & source) const
{
    check_hresult(WINRT_SHIM(IPrint3DWorkflowPrintRequestedEventArgs)->abi_SetSource(get_abi(source)));
}

template <typename D> void impl_IPrint3DWorkflowPrintRequestedEventArgs<D>::SetSourceChanged(bool value) const
{
    check_hresult(WINRT_SHIM(IPrint3DWorkflowPrintRequestedEventArgs)->abi_SetSourceChanged(value));
}

template <typename D> hstring impl_IPrint3DWorkflowPrinterChangedEventArgs<D>::NewDeviceId() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IPrint3DWorkflowPrinterChangedEventArgs)->get_NewDeviceId(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IPrint3DWorkflow<D>::DeviceID() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IPrint3DWorkflow)->get_DeviceID(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::IInspectable impl_IPrint3DWorkflow<D>::GetPrintModelPackage() const
{
    Windows::Foundation::IInspectable printModelPackage;
    check_hresult(WINRT_SHIM(IPrint3DWorkflow)->abi_GetPrintModelPackage(put_abi(printModelPackage)));
    return printModelPackage;
}

template <typename D> bool impl_IPrint3DWorkflow<D>::IsPrintReady() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IPrint3DWorkflow)->get_IsPrintReady(&value));
    return value;
}

template <typename D> void impl_IPrint3DWorkflow<D>::IsPrintReady(bool value) const
{
    check_hresult(WINRT_SHIM(IPrint3DWorkflow)->put_IsPrintReady(value));
}

template <typename D> event_token impl_IPrint3DWorkflow<D>::PrintRequested(const Windows::Foundation::TypedEventHandler<Windows::Devices::Printers::Extensions::Print3DWorkflow, Windows::Devices::Printers::Extensions::Print3DWorkflowPrintRequestedEventArgs> & eventHandler) const
{
    event_token eventCookie {};
    check_hresult(WINRT_SHIM(IPrint3DWorkflow)->add_PrintRequested(get_abi(eventHandler), &eventCookie));
    return eventCookie;
}

template <typename D> event_revoker<IPrint3DWorkflow> impl_IPrint3DWorkflow<D>::PrintRequested(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Devices::Printers::Extensions::Print3DWorkflow, Windows::Devices::Printers::Extensions::Print3DWorkflowPrintRequestedEventArgs> & eventHandler) const
{
    return impl::make_event_revoker<D, IPrint3DWorkflow>(this, &ABI::Windows::Devices::Printers::Extensions::IPrint3DWorkflow::remove_PrintRequested, PrintRequested(eventHandler));
}

template <typename D> void impl_IPrint3DWorkflow<D>::PrintRequested(event_token eventCookie) const
{
    check_hresult(WINRT_SHIM(IPrint3DWorkflow)->remove_PrintRequested(eventCookie));
}

template <typename D> event_token impl_IPrint3DWorkflow2<D>::PrinterChanged(const Windows::Foundation::TypedEventHandler<Windows::Devices::Printers::Extensions::Print3DWorkflow, Windows::Devices::Printers::Extensions::Print3DWorkflowPrinterChangedEventArgs> & eventHandler) const
{
    event_token eventCookie {};
    check_hresult(WINRT_SHIM(IPrint3DWorkflow2)->add_PrinterChanged(get_abi(eventHandler), &eventCookie));
    return eventCookie;
}

template <typename D> event_revoker<IPrint3DWorkflow2> impl_IPrint3DWorkflow2<D>::PrinterChanged(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Devices::Printers::Extensions::Print3DWorkflow, Windows::Devices::Printers::Extensions::Print3DWorkflowPrinterChangedEventArgs> & eventHandler) const
{
    return impl::make_event_revoker<D, IPrint3DWorkflow2>(this, &ABI::Windows::Devices::Printers::Extensions::IPrint3DWorkflow2::remove_PrinterChanged, PrinterChanged(eventHandler));
}

template <typename D> void impl_IPrint3DWorkflow2<D>::PrinterChanged(event_token eventCookie) const
{
    check_hresult(WINRT_SHIM(IPrint3DWorkflow2)->remove_PrinterChanged(eventCookie));
}

}

}

template<>
struct std::hash<winrt::Windows::Devices::Printers::Extensions::IPrint3DWorkflow>
{
    size_t operator()(const winrt::Windows::Devices::Printers::Extensions::IPrint3DWorkflow & value) const noexcept
    {
        return winrt::impl::hash_unknown(value);
    }
};

template<>
struct std::hash<winrt::Windows::Devices::Printers::Extensions::IPrint3DWorkflow2>
{
    size_t operator()(const winrt::Windows::Devices::Printers::Extensions::IPrint3DWorkflow2 & value) const noexcept
    {
        return winrt::impl::hash_unknown(value);
    }
};

template<>
struct std::hash<winrt::Windows::Devices::Printers::Extensions::IPrint3DWorkflowPrintRequestedEventArgs>
{
    size_t operator()(const winrt::Windows::Devices::Printers::Extensions::IPrint3DWorkflowPrintRequestedEventArgs & value) const noexcept
    {
        return winrt::impl::hash_unknown(value);
    }
};

template<>
struct std::hash<winrt::Windows::Devices::Printers::Extensions::IPrint3DWorkflowPrinterChangedEventArgs>
{
    size_t operator()(const winrt::Windows::Devices::Printers::Extensions::IPrint3DWorkflowPrinterChangedEventArgs & value) const noexcept
    {
        return winrt::impl::hash_unknown(value);
    }
};

template<>
struct std::hash<winrt::Windows::Devices::Printers::Extensions::Print3DWorkflow>
{
    size_t operator()(const winrt::Windows::Devices::Printers::Extensions::Print3DWorkflow & value) const noexcept
    {
        return winrt::impl::hash_unknown(value);
    }
};

template<>
struct std::hash<winrt::Windows::Devices::Printers::Extensions::Print3DWorkflowPrintRequestedEventArgs>
{
    size_t operator()(const winrt::Windows::Devices::Printers::Extensions::Print3DWorkflowPrintRequestedEventArgs & value) const noexcept
    {
        return winrt::impl::hash_unknown(value);
    }
};

template<>
struct std::hash<winrt::Windows::Devices::Printers::Extensions::Print3DWorkflowPrinterChangedEventArgs>
{
    size_t operator()(const winrt::Windows::Devices::Printers::Extensions::Print3DWorkflowPrinterChangedEventArgs & value) const noexcept
    {
        return winrt::impl::hash_unknown(value);
    }
};
#pragma warning(pop)
