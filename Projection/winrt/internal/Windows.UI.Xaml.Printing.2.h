// C++ for the Windows Runtime v1.0.private
// Copyright (c) 2016 Microsoft Corporation. All rights reserved.

#pragma once

#include "Windows.UI.Xaml.Printing.1.h"
#include "Windows.UI.Xaml.1.h"
#include "Windows.UI.Xaml.2.h"

WINRT_EXPORT namespace winrt {

namespace Windows::UI::Xaml::Printing {

struct AddPagesEventHandler : Windows::IUnknown
{
    AddPagesEventHandler(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<AddPagesEventHandler>(m_ptr); }
    template <typename L> AddPagesEventHandler(L lambda);
    template <typename F> AddPagesEventHandler (F * function);
    template <typename O, typename M> AddPagesEventHandler(O * object, M method);
    void operator()(const Windows::IInspectable & sender, const Windows::UI::Xaml::Printing::AddPagesEventArgs & e) const;
};

struct GetPreviewPageEventHandler : Windows::IUnknown
{
    GetPreviewPageEventHandler(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<GetPreviewPageEventHandler>(m_ptr); }
    template <typename L> GetPreviewPageEventHandler(L lambda);
    template <typename F> GetPreviewPageEventHandler (F * function);
    template <typename O, typename M> GetPreviewPageEventHandler(O * object, M method);
    void operator()(const Windows::IInspectable & sender, const Windows::UI::Xaml::Printing::GetPreviewPageEventArgs & e) const;
};

struct PaginateEventHandler : Windows::IUnknown
{
    PaginateEventHandler(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<PaginateEventHandler>(m_ptr); }
    template <typename L> PaginateEventHandler(L lambda);
    template <typename F> PaginateEventHandler (F * function);
    template <typename O, typename M> PaginateEventHandler(O * object, M method);
    void operator()(const Windows::IInspectable & sender, const Windows::UI::Xaml::Printing::PaginateEventArgs & e) const;
};

struct IAddPagesEventArgs :
    Windows::IInspectable,
    impl::consume<IAddPagesEventArgs>
{
    IAddPagesEventArgs(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IAddPagesEventArgs>(m_ptr); }
};

struct IGetPreviewPageEventArgs :
    Windows::IInspectable,
    impl::consume<IGetPreviewPageEventArgs>
{
    IGetPreviewPageEventArgs(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IGetPreviewPageEventArgs>(m_ptr); }
};

struct IPaginateEventArgs :
    Windows::IInspectable,
    impl::consume<IPaginateEventArgs>
{
    IPaginateEventArgs(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IPaginateEventArgs>(m_ptr); }
};

struct IPrintDocument :
    Windows::IInspectable,
    impl::consume<IPrintDocument>
{
    IPrintDocument(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IPrintDocument>(m_ptr); }
};

struct IPrintDocumentFactory :
    Windows::IInspectable,
    impl::consume<IPrintDocumentFactory>
{
    IPrintDocumentFactory(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IPrintDocumentFactory>(m_ptr); }
};

struct IPrintDocumentStatics :
    Windows::IInspectable,
    impl::consume<IPrintDocumentStatics>
{
    IPrintDocumentStatics(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IPrintDocumentStatics>(m_ptr); }
};

}

}
