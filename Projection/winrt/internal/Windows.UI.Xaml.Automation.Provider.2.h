// C++ for the Windows Runtime v1.0.private
// Copyright (c) 2016 Microsoft Corporation. All rights reserved.

#pragma once

#include "Windows.UI.Xaml.Automation.Provider.1.h"
#include "Windows.UI.Xaml.1.h"
#include "Windows.UI.Xaml.2.h"

WINRT_EXPORT namespace winrt {

namespace Windows::UI::Xaml::Automation::Provider {

struct IAnnotationProvider :
    Windows::IInspectable,
    impl::consume<IAnnotationProvider>
{
    IAnnotationProvider(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IAnnotationProvider>(m_ptr); }
};

struct ICustomNavigationProvider :
    Windows::IInspectable,
    impl::consume<ICustomNavigationProvider>
{
    ICustomNavigationProvider(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<ICustomNavigationProvider>(m_ptr); }
};

struct IDockProvider :
    Windows::IInspectable,
    impl::consume<IDockProvider>
{
    IDockProvider(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IDockProvider>(m_ptr); }
};

struct IDragProvider :
    Windows::IInspectable,
    impl::consume<IDragProvider>
{
    IDragProvider(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IDragProvider>(m_ptr); }
};

struct IDropTargetProvider :
    Windows::IInspectable,
    impl::consume<IDropTargetProvider>
{
    IDropTargetProvider(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IDropTargetProvider>(m_ptr); }
};

struct IExpandCollapseProvider :
    Windows::IInspectable,
    impl::consume<IExpandCollapseProvider>
{
    IExpandCollapseProvider(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IExpandCollapseProvider>(m_ptr); }
};

struct IGridItemProvider :
    Windows::IInspectable,
    impl::consume<IGridItemProvider>
{
    IGridItemProvider(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IGridItemProvider>(m_ptr); }
};

struct IGridProvider :
    Windows::IInspectable,
    impl::consume<IGridProvider>
{
    IGridProvider(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IGridProvider>(m_ptr); }
};

struct IIRawElementProviderSimple :
    Windows::IInspectable,
    impl::consume<IIRawElementProviderSimple>
{
    IIRawElementProviderSimple(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IIRawElementProviderSimple>(m_ptr); }
};

struct IInvokeProvider :
    Windows::IInspectable,
    impl::consume<IInvokeProvider>
{
    IInvokeProvider(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IInvokeProvider>(m_ptr); }
};

struct IItemContainerProvider :
    Windows::IInspectable,
    impl::consume<IItemContainerProvider>
{
    IItemContainerProvider(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IItemContainerProvider>(m_ptr); }
};

struct IMultipleViewProvider :
    Windows::IInspectable,
    impl::consume<IMultipleViewProvider>
{
    IMultipleViewProvider(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IMultipleViewProvider>(m_ptr); }
};

struct IObjectModelProvider :
    Windows::IInspectable,
    impl::consume<IObjectModelProvider>
{
    IObjectModelProvider(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IObjectModelProvider>(m_ptr); }
};

struct IRangeValueProvider :
    Windows::IInspectable,
    impl::consume<IRangeValueProvider>
{
    IRangeValueProvider(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IRangeValueProvider>(m_ptr); }
};

struct IScrollItemProvider :
    Windows::IInspectable,
    impl::consume<IScrollItemProvider>
{
    IScrollItemProvider(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IScrollItemProvider>(m_ptr); }
};

struct IScrollProvider :
    Windows::IInspectable,
    impl::consume<IScrollProvider>
{
    IScrollProvider(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IScrollProvider>(m_ptr); }
};

struct ISelectionItemProvider :
    Windows::IInspectable,
    impl::consume<ISelectionItemProvider>
{
    ISelectionItemProvider(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<ISelectionItemProvider>(m_ptr); }
};

struct ISelectionProvider :
    Windows::IInspectable,
    impl::consume<ISelectionProvider>
{
    ISelectionProvider(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<ISelectionProvider>(m_ptr); }
};

struct ISpreadsheetItemProvider :
    Windows::IInspectable,
    impl::consume<ISpreadsheetItemProvider>
{
    ISpreadsheetItemProvider(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<ISpreadsheetItemProvider>(m_ptr); }
};

struct ISpreadsheetProvider :
    Windows::IInspectable,
    impl::consume<ISpreadsheetProvider>
{
    ISpreadsheetProvider(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<ISpreadsheetProvider>(m_ptr); }
};

struct IStylesProvider :
    Windows::IInspectable,
    impl::consume<IStylesProvider>
{
    IStylesProvider(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IStylesProvider>(m_ptr); }
};

struct ISynchronizedInputProvider :
    Windows::IInspectable,
    impl::consume<ISynchronizedInputProvider>
{
    ISynchronizedInputProvider(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<ISynchronizedInputProvider>(m_ptr); }
};

struct ITableItemProvider :
    Windows::IInspectable,
    impl::consume<ITableItemProvider>
{
    ITableItemProvider(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<ITableItemProvider>(m_ptr); }
};

struct ITableProvider :
    Windows::IInspectable,
    impl::consume<ITableProvider>
{
    ITableProvider(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<ITableProvider>(m_ptr); }
};

struct ITextChildProvider :
    Windows::IInspectable,
    impl::consume<ITextChildProvider>
{
    ITextChildProvider(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<ITextChildProvider>(m_ptr); }
};

struct ITextEditProvider :
    Windows::IInspectable,
    impl::consume<ITextEditProvider>,
    impl::require<ITextEditProvider, Windows::UI::Xaml::Automation::Provider::ITextProvider>
{
    ITextEditProvider(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<ITextEditProvider>(m_ptr); }
};

struct ITextProvider :
    Windows::IInspectable,
    impl::consume<ITextProvider>
{
    ITextProvider(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<ITextProvider>(m_ptr); }
};

struct ITextProvider2 :
    Windows::IInspectable,
    impl::consume<ITextProvider2>,
    impl::require<ITextProvider2, Windows::UI::Xaml::Automation::Provider::ITextProvider>
{
    ITextProvider2(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<ITextProvider2>(m_ptr); }
};

struct ITextRangeProvider :
    Windows::IInspectable,
    impl::consume<ITextRangeProvider>
{
    ITextRangeProvider(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<ITextRangeProvider>(m_ptr); }
};

struct ITextRangeProvider2 :
    Windows::IInspectable,
    impl::consume<ITextRangeProvider2>,
    impl::require<ITextRangeProvider2, Windows::UI::Xaml::Automation::Provider::ITextRangeProvider>
{
    ITextRangeProvider2(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<ITextRangeProvider2>(m_ptr); }
};

struct IToggleProvider :
    Windows::IInspectable,
    impl::consume<IToggleProvider>
{
    IToggleProvider(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IToggleProvider>(m_ptr); }
};

struct ITransformProvider :
    Windows::IInspectable,
    impl::consume<ITransformProvider>
{
    ITransformProvider(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<ITransformProvider>(m_ptr); }
};

struct ITransformProvider2 :
    Windows::IInspectable,
    impl::consume<ITransformProvider2>,
    impl::require<ITransformProvider2, Windows::UI::Xaml::Automation::Provider::ITransformProvider>
{
    ITransformProvider2(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<ITransformProvider2>(m_ptr); }
};

struct IValueProvider :
    Windows::IInspectable,
    impl::consume<IValueProvider>
{
    IValueProvider(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IValueProvider>(m_ptr); }
};

struct IVirtualizedItemProvider :
    Windows::IInspectable,
    impl::consume<IVirtualizedItemProvider>
{
    IVirtualizedItemProvider(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IVirtualizedItemProvider>(m_ptr); }
};

struct IWindowProvider :
    Windows::IInspectable,
    impl::consume<IWindowProvider>
{
    IWindowProvider(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IWindowProvider>(m_ptr); }
};

}

}
