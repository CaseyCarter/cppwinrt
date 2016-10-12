// C++ for the Windows Runtime v1.0.private
// Copyright (c) 2016 Microsoft Corporation. All rights reserved.

#pragma once

#include "Windows.Devices.Printers.Extensions.1.h"

WINRT_EXPORT namespace winrt {

namespace ABI::Windows::Foundation {

#ifndef WINRT_GENERIC_5f4c6603_5512_59aa_8d96_b1389d8b5796
#define WINRT_GENERIC_5f4c6603_5512_59aa_8d96_b1389d8b5796
template <> struct __declspec(uuid("5f4c6603-5512-59aa-8d96-b1389d8b5796")) __declspec(novtable) TypedEventHandler<Windows::Devices::Printers::Extensions::Print3DWorkflow, Windows::Devices::Printers::Extensions::Print3DWorkflowPrintRequestedEventArgs> : impl_TypedEventHandler<Windows::Devices::Printers::Extensions::Print3DWorkflow, Windows::Devices::Printers::Extensions::Print3DWorkflowPrintRequestedEventArgs> {};
#endif

#ifndef WINRT_GENERIC_b4b5ddc2_1a74_5905_9fc5_ddaae9a3ab93
#define WINRT_GENERIC_b4b5ddc2_1a74_5905_9fc5_ddaae9a3ab93
template <> struct __declspec(uuid("b4b5ddc2-1a74-5905-9fc5-ddaae9a3ab93")) __declspec(novtable) TypedEventHandler<Windows::Devices::Printers::Extensions::Print3DWorkflow, Windows::Devices::Printers::Extensions::Print3DWorkflowPrinterChangedEventArgs> : impl_TypedEventHandler<Windows::Devices::Printers::Extensions::Print3DWorkflow, Windows::Devices::Printers::Extensions::Print3DWorkflowPrinterChangedEventArgs> {};
#endif


}

namespace Windows::Devices::Printers::Extensions {

template <typename D>
struct WINRT_EBO impl_IPrint3DWorkflow
{
    hstring DeviceID() const;
    Windows::IInspectable GetPrintModelPackage() const;
    bool IsPrintReady() const;
    void IsPrintReady(bool value) const;
    event_token PrintRequested(const Windows::Foundation::TypedEventHandler<Windows::Devices::Printers::Extensions::Print3DWorkflow, Windows::Devices::Printers::Extensions::Print3DWorkflowPrintRequestedEventArgs> & eventHandler) const;
    using PrintRequested_revoker = event_revoker<IPrint3DWorkflow>;
    PrintRequested_revoker PrintRequested(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Devices::Printers::Extensions::Print3DWorkflow, Windows::Devices::Printers::Extensions::Print3DWorkflowPrintRequestedEventArgs> & eventHandler) const;
    void PrintRequested(event_token eventCookie) const;
};

template <typename D>
struct WINRT_EBO impl_IPrint3DWorkflow2
{
    event_token PrinterChanged(const Windows::Foundation::TypedEventHandler<Windows::Devices::Printers::Extensions::Print3DWorkflow, Windows::Devices::Printers::Extensions::Print3DWorkflowPrinterChangedEventArgs> & eventHandler) const;
    using PrinterChanged_revoker = event_revoker<IPrint3DWorkflow2>;
    PrinterChanged_revoker PrinterChanged(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Devices::Printers::Extensions::Print3DWorkflow, Windows::Devices::Printers::Extensions::Print3DWorkflowPrinterChangedEventArgs> & eventHandler) const;
    void PrinterChanged(event_token eventCookie) const;
};

template <typename D>
struct WINRT_EBO impl_IPrint3DWorkflowPrintRequestedEventArgs
{
    Windows::Devices::Printers::Extensions::Print3DWorkflowStatus Status() const;
    void SetExtendedStatus(Windows::Devices::Printers::Extensions::Print3DWorkflowDetail value) const;
    void SetSource(const Windows::IInspectable & source) const;
    void SetSourceChanged(bool value) const;
};

template <typename D>
struct WINRT_EBO impl_IPrint3DWorkflowPrinterChangedEventArgs
{
    hstring NewDeviceId() const;
};

struct IPrint3DWorkflow :
    Windows::IInspectable,
    impl::consume<IPrint3DWorkflow>
{
    IPrint3DWorkflow(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IPrint3DWorkflow>(m_ptr); }
};

struct IPrint3DWorkflow2 :
    Windows::IInspectable,
    impl::consume<IPrint3DWorkflow2>
{
    IPrint3DWorkflow2(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IPrint3DWorkflow2>(m_ptr); }
};

struct IPrint3DWorkflowPrintRequestedEventArgs :
    Windows::IInspectable,
    impl::consume<IPrint3DWorkflowPrintRequestedEventArgs>
{
    IPrint3DWorkflowPrintRequestedEventArgs(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IPrint3DWorkflowPrintRequestedEventArgs>(m_ptr); }
};

struct IPrint3DWorkflowPrinterChangedEventArgs :
    Windows::IInspectable,
    impl::consume<IPrint3DWorkflowPrinterChangedEventArgs>
{
    IPrint3DWorkflowPrinterChangedEventArgs(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IPrint3DWorkflowPrinterChangedEventArgs>(m_ptr); }
};

}

}
