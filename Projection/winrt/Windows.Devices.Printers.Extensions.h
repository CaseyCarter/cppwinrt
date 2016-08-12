// C++ for the Windows Runtime v1.29
// Copyright (c) 2016 Microsoft Corporation

#pragma once

#include "internal/Windows.Foundation.3.h"
#include "internal/Windows.Devices.Printers.Extensions.3.h"
#include "Windows.Devices.Printers.h"

WINRT_EXPORT namespace winrt {

namespace impl {

template <typename D>
struct produce<D, Windows::Devices::Printers::Extensions::IPrint3DWorkflow> : produce_base<D, Windows::Devices::Printers::Extensions::IPrint3DWorkflow>
{
    HRESULT __stdcall get_DeviceID(abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            *value = detach(this->shim().DeviceID());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetPrintModelPackage(abi_arg_out<Windows::IInspectable> printModelPackage) noexcept override
    {
        try
        {
            *printModelPackage = detach(this->shim().GetPrintModelPackage());
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
            *value = detach(this->shim().IsPrintReady());
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
            this->shim().IsPrintReady(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_PrintRequested(abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::Devices::Printers::Extensions::Print3DWorkflow, Windows::Devices::Printers::Extensions::Print3DWorkflowPrintRequestedEventArgs>> eventHandler, event_token * eventCookie) noexcept override
    {
        try
        {
            *eventCookie = detach(this->shim().PrintRequested(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::Devices::Printers::Extensions::Print3DWorkflow, Windows::Devices::Printers::Extensions::Print3DWorkflowPrintRequestedEventArgs> *>(&eventHandler)));
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
    HRESULT __stdcall add_PrinterChanged(abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::Devices::Printers::Extensions::Print3DWorkflow, Windows::Devices::Printers::Extensions::Print3DWorkflowPrinterChangedEventArgs>> eventHandler, event_token * eventCookie) noexcept override
    {
        try
        {
            *eventCookie = detach(this->shim().PrinterChanged(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::Devices::Printers::Extensions::Print3DWorkflow, Windows::Devices::Printers::Extensions::Print3DWorkflowPrinterChangedEventArgs> *>(&eventHandler)));
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
            *value = detach(this->shim().Status());
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
            this->shim().SetExtendedStatus(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_SetSource(abi_arg_in<Windows::IInspectable> source) noexcept override
    {
        try
        {
            this->shim().SetSource(*reinterpret_cast<const Windows::IInspectable *>(&source));
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
    HRESULT __stdcall get_NewDeviceId(abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            *value = detach(this->shim().NewDeviceId());
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
    check_hresult(shim()->get_Status(&value));
    return value;
}

template <typename D> void impl_IPrint3DWorkflowPrintRequestedEventArgs<D>::SetExtendedStatus(Windows::Devices::Printers::Extensions::Print3DWorkflowDetail value) const
{
    check_hresult(shim()->abi_SetExtendedStatus(value));
}

template <typename D> void impl_IPrint3DWorkflowPrintRequestedEventArgs<D>::SetSource(const Windows::IInspectable & source) const
{
    check_hresult(shim()->abi_SetSource(get(source)));
}

template <typename D> void impl_IPrint3DWorkflowPrintRequestedEventArgs<D>::SetSourceChanged(bool value) const
{
    check_hresult(shim()->abi_SetSourceChanged(value));
}

template <typename D> hstring impl_IPrint3DWorkflowPrinterChangedEventArgs<D>::NewDeviceId() const
{
    hstring value;
    check_hresult(shim()->get_NewDeviceId(put(value)));
    return value;
}

template <typename D> hstring impl_IPrint3DWorkflow<D>::DeviceID() const
{
    hstring value;
    check_hresult(shim()->get_DeviceID(put(value)));
    return value;
}

template <typename D> Windows::IInspectable impl_IPrint3DWorkflow<D>::GetPrintModelPackage() const
{
    Windows::IInspectable printModelPackage;
    check_hresult(shim()->abi_GetPrintModelPackage(put(printModelPackage)));
    return printModelPackage;
}

template <typename D> bool impl_IPrint3DWorkflow<D>::IsPrintReady() const
{
    bool value {};
    check_hresult(shim()->get_IsPrintReady(&value));
    return value;
}

template <typename D> void impl_IPrint3DWorkflow<D>::IsPrintReady(bool value) const
{
    check_hresult(shim()->put_IsPrintReady(value));
}

template <typename D> event_token impl_IPrint3DWorkflow<D>::PrintRequested(const Windows::Foundation::TypedEventHandler<Windows::Devices::Printers::Extensions::Print3DWorkflow, Windows::Devices::Printers::Extensions::Print3DWorkflowPrintRequestedEventArgs> & eventHandler) const
{
    event_token eventCookie {};
    check_hresult(shim()->add_PrintRequested(get(eventHandler), &eventCookie));
    return eventCookie;
}

template <typename D> event_revoker<IPrint3DWorkflow> impl_IPrint3DWorkflow<D>::PrintRequested(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Devices::Printers::Extensions::Print3DWorkflow, Windows::Devices::Printers::Extensions::Print3DWorkflowPrintRequestedEventArgs> & eventHandler) const
{
    return impl::make_event_revoker<D, IPrint3DWorkflow>(this, &ABI::Windows::Devices::Printers::Extensions::IPrint3DWorkflow::remove_PrintRequested, PrintRequested(eventHandler));
}

template <typename D> void impl_IPrint3DWorkflow<D>::PrintRequested(event_token eventCookie) const
{
    check_hresult(shim()->remove_PrintRequested(eventCookie));
}

template <typename D> event_token impl_IPrint3DWorkflow2<D>::PrinterChanged(const Windows::Foundation::TypedEventHandler<Windows::Devices::Printers::Extensions::Print3DWorkflow, Windows::Devices::Printers::Extensions::Print3DWorkflowPrinterChangedEventArgs> & eventHandler) const
{
    event_token eventCookie {};
    check_hresult(shim()->add_PrinterChanged(get(eventHandler), &eventCookie));
    return eventCookie;
}

template <typename D> event_revoker<IPrint3DWorkflow2> impl_IPrint3DWorkflow2<D>::PrinterChanged(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Devices::Printers::Extensions::Print3DWorkflow, Windows::Devices::Printers::Extensions::Print3DWorkflowPrinterChangedEventArgs> & eventHandler) const
{
    return impl::make_event_revoker<D, IPrint3DWorkflow2>(this, &ABI::Windows::Devices::Printers::Extensions::IPrint3DWorkflow2::remove_PrinterChanged, PrinterChanged(eventHandler));
}

template <typename D> void impl_IPrint3DWorkflow2<D>::PrinterChanged(event_token eventCookie) const
{
    check_hresult(shim()->remove_PrinterChanged(eventCookie));
}

}

}
