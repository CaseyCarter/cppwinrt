// C++ for the Windows Runtime v1.0.private
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "Windows.UI.WebUI.1.h"
#include "Windows.ApplicationModel.1.h"
#include "Windows.ApplicationModel.Activation.1.h"
#include "Windows.ApplicationModel.Background.1.h"
#include "Windows.Foundation.1.h"
#include "Windows.Graphics.Printing.1.h"
#include "Windows.ApplicationModel.2.h"
#include "Windows.ApplicationModel.Activation.2.h"

WINRT_EXPORT namespace winrt {

namespace Windows::UI::WebUI {

struct ActivatedEventHandler : Windows::IUnknown
{
    ActivatedEventHandler(std::nullptr_t = nullptr) noexcept {}
    template <typename L> ActivatedEventHandler(L lambda);
    template <typename F> ActivatedEventHandler (F * function);
    template <typename O, typename M> ActivatedEventHandler(O * object, M method);
    void operator()(const Windows::IInspectable & sender, const Windows::ApplicationModel::Activation::IActivatedEventArgs & eventArgs) const;
};

struct EnteredBackgroundEventHandler : Windows::IUnknown
{
    EnteredBackgroundEventHandler(std::nullptr_t = nullptr) noexcept {}
    template <typename L> EnteredBackgroundEventHandler(L lambda);
    template <typename F> EnteredBackgroundEventHandler (F * function);
    template <typename O, typename M> EnteredBackgroundEventHandler(O * object, M method);
    void operator()(const Windows::IInspectable & sender, const Windows::ApplicationModel::IEnteredBackgroundEventArgs & e) const;
};

struct LeavingBackgroundEventHandler : Windows::IUnknown
{
    LeavingBackgroundEventHandler(std::nullptr_t = nullptr) noexcept {}
    template <typename L> LeavingBackgroundEventHandler(L lambda);
    template <typename F> LeavingBackgroundEventHandler (F * function);
    template <typename O, typename M> LeavingBackgroundEventHandler(O * object, M method);
    void operator()(const Windows::IInspectable & sender, const Windows::ApplicationModel::ILeavingBackgroundEventArgs & e) const;
};

struct NavigatedEventHandler : Windows::IUnknown
{
    NavigatedEventHandler(std::nullptr_t = nullptr) noexcept {}
    template <typename L> NavigatedEventHandler(L lambda);
    template <typename F> NavigatedEventHandler (F * function);
    template <typename O, typename M> NavigatedEventHandler(O * object, M method);
    void operator()(const Windows::IInspectable & sender, const Windows::UI::WebUI::IWebUINavigatedEventArgs & e) const;
};

struct ResumingEventHandler : Windows::IUnknown
{
    ResumingEventHandler(std::nullptr_t = nullptr) noexcept {}
    template <typename L> ResumingEventHandler(L lambda);
    template <typename F> ResumingEventHandler (F * function);
    template <typename O, typename M> ResumingEventHandler(O * object, M method);
    void operator()(const Windows::IInspectable & sender) const;
};

struct SuspendingEventHandler : Windows::IUnknown
{
    SuspendingEventHandler(std::nullptr_t = nullptr) noexcept {}
    template <typename L> SuspendingEventHandler(L lambda);
    template <typename F> SuspendingEventHandler (F * function);
    template <typename O, typename M> SuspendingEventHandler(O * object, M method);
    void operator()(const Windows::IInspectable & sender, const Windows::ApplicationModel::ISuspendingEventArgs & e) const;
};

struct IActivatedDeferral :
    Windows::IInspectable,
    impl::consume<IActivatedDeferral>
{
    IActivatedDeferral(std::nullptr_t = nullptr) noexcept {}
};

struct IActivatedEventArgsDeferral :
    Windows::IInspectable,
    impl::consume<IActivatedEventArgsDeferral>
{
    IActivatedEventArgsDeferral(std::nullptr_t = nullptr) noexcept {}
};

struct IActivatedOperation :
    Windows::IInspectable,
    impl::consume<IActivatedOperation>
{
    IActivatedOperation(std::nullptr_t = nullptr) noexcept {}
};

struct IHtmlPrintDocumentSource :
    Windows::IInspectable,
    impl::consume<IHtmlPrintDocumentSource>,
    impl::require<IHtmlPrintDocumentSource, Windows::Graphics::Printing::IPrintDocumentSource>
{
    IHtmlPrintDocumentSource(std::nullptr_t = nullptr) noexcept {}
};

struct IWebUIActivationStatics :
    Windows::IInspectable,
    impl::consume<IWebUIActivationStatics>
{
    IWebUIActivationStatics(std::nullptr_t = nullptr) noexcept {}
};

struct IWebUIActivationStatics2 :
    Windows::IInspectable,
    impl::consume<IWebUIActivationStatics2>
{
    IWebUIActivationStatics2(std::nullptr_t = nullptr) noexcept {}
};

struct IWebUIBackgroundTaskInstance :
    Windows::IInspectable,
    impl::consume<IWebUIBackgroundTaskInstance>
{
    IWebUIBackgroundTaskInstance(std::nullptr_t = nullptr) noexcept {}
};

struct IWebUIBackgroundTaskInstanceStatics :
    Windows::IInspectable,
    impl::consume<IWebUIBackgroundTaskInstanceStatics>
{
    IWebUIBackgroundTaskInstanceStatics(std::nullptr_t = nullptr) noexcept {}
};

struct IWebUINavigatedDeferral :
    Windows::IInspectable,
    impl::consume<IWebUINavigatedDeferral>
{
    IWebUINavigatedDeferral(std::nullptr_t = nullptr) noexcept {}
};

struct IWebUINavigatedEventArgs :
    Windows::IInspectable,
    impl::consume<IWebUINavigatedEventArgs>
{
    IWebUINavigatedEventArgs(std::nullptr_t = nullptr) noexcept {}
};

struct IWebUINavigatedOperation :
    Windows::IInspectable,
    impl::consume<IWebUINavigatedOperation>
{
    IWebUINavigatedOperation(std::nullptr_t = nullptr) noexcept {}
};

}

}
