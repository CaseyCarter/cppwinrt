// C++ for the Windows Runtime v1.29
// Copyright (c) 2016 Microsoft Corporation

#pragma once

#include "base.h"
#include "Windows.Devices.Printers.Extensions.0.h"
#include "Windows.Foundation.1.h"

WINRT_EXPORT namespace winrt {

namespace ABI::Windows::Devices::Printers::Extensions {

struct __declspec(uuid("c56f74bd-3669-4a66-ab42-c8151930cd34")) __declspec(novtable) IPrint3DWorkflow : Windows::IInspectable
{
    virtual HRESULT __stdcall get_DeviceID(hstring * value) = 0;
    virtual HRESULT __stdcall abi_GetPrintModelPackage(Windows::IInspectable ** printModelPackage) = 0;
    virtual HRESULT __stdcall get_IsPrintReady(bool * value) = 0;
    virtual HRESULT __stdcall put_IsPrintReady(bool value) = 0;
    virtual HRESULT __stdcall add_PrintRequested(Windows::Foundation::TypedEventHandler<Windows::Devices::Printers::Extensions::Print3DWorkflow, Windows::Devices::Printers::Extensions::Print3DWorkflowPrintRequestedEventArgs> * eventHandler, event_token * eventCookie) = 0;
    virtual HRESULT __stdcall remove_PrintRequested(event_token eventCookie) = 0;
};

struct __declspec(uuid("a2a6c54f-8ac1-4918-9741-e34f3004239e")) __declspec(novtable) IPrint3DWorkflow2 : Windows::IInspectable
{
    virtual HRESULT __stdcall add_PrinterChanged(Windows::Foundation::TypedEventHandler<Windows::Devices::Printers::Extensions::Print3DWorkflow, Windows::Devices::Printers::Extensions::Print3DWorkflowPrinterChangedEventArgs> * eventHandler, event_token * eventCookie) = 0;
    virtual HRESULT __stdcall remove_PrinterChanged(event_token eventCookie) = 0;
};

struct __declspec(uuid("19f8c858-5ac8-4b55-8a5f-e61567dafb4d")) __declspec(novtable) IPrint3DWorkflowPrintRequestedEventArgs : Windows::IInspectable
{
    virtual HRESULT __stdcall get_Status(winrt::Windows::Devices::Printers::Extensions::Print3DWorkflowStatus * value) = 0;
    virtual HRESULT __stdcall abi_SetExtendedStatus(winrt::Windows::Devices::Printers::Extensions::Print3DWorkflowDetail value) = 0;
    virtual HRESULT __stdcall abi_SetSource(Windows::IInspectable * source) = 0;
    virtual HRESULT __stdcall abi_SetSourceChanged(bool value) = 0;
};

struct __declspec(uuid("45226402-95fc-4847-93b3-134dbf5c60f7")) __declspec(novtable) IPrint3DWorkflowPrinterChangedEventArgs : Windows::IInspectable
{
    virtual HRESULT __stdcall get_NewDeviceId(hstring * value) = 0;
};

}

namespace ABI {

template <> struct traits<Windows::Devices::Printers::Extensions::Print3DWorkflow> { using default_interface = Windows::Devices::Printers::Extensions::IPrint3DWorkflow; };
template <> struct traits<Windows::Devices::Printers::Extensions::Print3DWorkflowPrintRequestedEventArgs> { using default_interface = Windows::Devices::Printers::Extensions::IPrint3DWorkflowPrintRequestedEventArgs; };
template <> struct traits<Windows::Devices::Printers::Extensions::Print3DWorkflowPrinterChangedEventArgs> { using default_interface = Windows::Devices::Printers::Extensions::IPrint3DWorkflowPrinterChangedEventArgs; };

}

namespace Windows::Devices::Printers::Extensions {

template <typename T> class impl_IPrint3DWorkflow;
template <typename T> class impl_IPrint3DWorkflow2;
template <typename T> class impl_IPrint3DWorkflowPrintRequestedEventArgs;
template <typename T> class impl_IPrint3DWorkflowPrinterChangedEventArgs;

}

namespace impl {

template <> struct traits<Windows::Devices::Printers::Extensions::IPrint3DWorkflow>
{
    using abi = ABI::Windows::Devices::Printers::Extensions::IPrint3DWorkflow;
    template <typename D> using consume = Windows::Devices::Printers::Extensions::impl_IPrint3DWorkflow<D>;
};

template <> struct traits<Windows::Devices::Printers::Extensions::IPrint3DWorkflow2>
{
    using abi = ABI::Windows::Devices::Printers::Extensions::IPrint3DWorkflow2;
    template <typename D> using consume = Windows::Devices::Printers::Extensions::impl_IPrint3DWorkflow2<D>;
};

template <> struct traits<Windows::Devices::Printers::Extensions::IPrint3DWorkflowPrintRequestedEventArgs>
{
    using abi = ABI::Windows::Devices::Printers::Extensions::IPrint3DWorkflowPrintRequestedEventArgs;
    template <typename D> using consume = Windows::Devices::Printers::Extensions::impl_IPrint3DWorkflowPrintRequestedEventArgs<D>;
};

template <> struct traits<Windows::Devices::Printers::Extensions::IPrint3DWorkflowPrinterChangedEventArgs>
{
    using abi = ABI::Windows::Devices::Printers::Extensions::IPrint3DWorkflowPrinterChangedEventArgs;
    template <typename D> using consume = Windows::Devices::Printers::Extensions::impl_IPrint3DWorkflowPrinterChangedEventArgs<D>;
};

template <> struct traits<Windows::Devices::Printers::Extensions::Print3DWorkflow>
{
    using abi = ABI::Windows::Devices::Printers::Extensions::Print3DWorkflow;
    using default_interface = Windows::Devices::Printers::Extensions::IPrint3DWorkflow;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Devices.Printers.Extensions.Print3DWorkflow"; }
};

template <> struct traits<Windows::Devices::Printers::Extensions::Print3DWorkflowPrintRequestedEventArgs>
{
    using abi = ABI::Windows::Devices::Printers::Extensions::Print3DWorkflowPrintRequestedEventArgs;
    using default_interface = Windows::Devices::Printers::Extensions::IPrint3DWorkflowPrintRequestedEventArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Devices.Printers.Extensions.Print3DWorkflowPrintRequestedEventArgs"; }
};

template <> struct traits<Windows::Devices::Printers::Extensions::Print3DWorkflowPrinterChangedEventArgs>
{
    using abi = ABI::Windows::Devices::Printers::Extensions::Print3DWorkflowPrinterChangedEventArgs;
    using default_interface = Windows::Devices::Printers::Extensions::IPrint3DWorkflowPrinterChangedEventArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Devices.Printers.Extensions.Print3DWorkflowPrinterChangedEventArgs"; }
};

}

}
