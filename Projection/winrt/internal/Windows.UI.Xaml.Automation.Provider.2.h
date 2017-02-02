// C++ for the Windows Runtime v1.0.private
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

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
};

struct ICustomNavigationProvider :
    Windows::IInspectable,
    impl::consume<ICustomNavigationProvider>
{
    ICustomNavigationProvider(std::nullptr_t = nullptr) noexcept {}
};

struct IDockProvider :
    Windows::IInspectable,
    impl::consume<IDockProvider>
{
    IDockProvider(std::nullptr_t = nullptr) noexcept {}
};

struct IDragProvider :
    Windows::IInspectable,
    impl::consume<IDragProvider>
{
    IDragProvider(std::nullptr_t = nullptr) noexcept {}
};

struct IDropTargetProvider :
    Windows::IInspectable,
    impl::consume<IDropTargetProvider>
{
    IDropTargetProvider(std::nullptr_t = nullptr) noexcept {}
};

struct IExpandCollapseProvider :
    Windows::IInspectable,
    impl::consume<IExpandCollapseProvider>
{
    IExpandCollapseProvider(std::nullptr_t = nullptr) noexcept {}
};

struct IGridItemProvider :
    Windows::IInspectable,
    impl::consume<IGridItemProvider>
{
    IGridItemProvider(std::nullptr_t = nullptr) noexcept {}
};

struct IGridProvider :
    Windows::IInspectable,
    impl::consume<IGridProvider>
{
    IGridProvider(std::nullptr_t = nullptr) noexcept {}
};

struct IIRawElementProviderSimple :
    Windows::IInspectable,
    impl::consume<IIRawElementProviderSimple>
{
    IIRawElementProviderSimple(std::nullptr_t = nullptr) noexcept {}
};

struct IInvokeProvider :
    Windows::IInspectable,
    impl::consume<IInvokeProvider>
{
    IInvokeProvider(std::nullptr_t = nullptr) noexcept {}
};

struct IItemContainerProvider :
    Windows::IInspectable,
    impl::consume<IItemContainerProvider>
{
    IItemContainerProvider(std::nullptr_t = nullptr) noexcept {}
};

struct IMultipleViewProvider :
    Windows::IInspectable,
    impl::consume<IMultipleViewProvider>
{
    IMultipleViewProvider(std::nullptr_t = nullptr) noexcept {}
};

struct IObjectModelProvider :
    Windows::IInspectable,
    impl::consume<IObjectModelProvider>
{
    IObjectModelProvider(std::nullptr_t = nullptr) noexcept {}
};

struct IRangeValueProvider :
    Windows::IInspectable,
    impl::consume<IRangeValueProvider>
{
    IRangeValueProvider(std::nullptr_t = nullptr) noexcept {}
};

struct IScrollItemProvider :
    Windows::IInspectable,
    impl::consume<IScrollItemProvider>
{
    IScrollItemProvider(std::nullptr_t = nullptr) noexcept {}
};

struct IScrollProvider :
    Windows::IInspectable,
    impl::consume<IScrollProvider>
{
    IScrollProvider(std::nullptr_t = nullptr) noexcept {}
};

struct ISelectionItemProvider :
    Windows::IInspectable,
    impl::consume<ISelectionItemProvider>
{
    ISelectionItemProvider(std::nullptr_t = nullptr) noexcept {}
};

struct ISelectionProvider :
    Windows::IInspectable,
    impl::consume<ISelectionProvider>
{
    ISelectionProvider(std::nullptr_t = nullptr) noexcept {}
};

struct ISpreadsheetItemProvider :
    Windows::IInspectable,
    impl::consume<ISpreadsheetItemProvider>
{
    ISpreadsheetItemProvider(std::nullptr_t = nullptr) noexcept {}
};

struct ISpreadsheetProvider :
    Windows::IInspectable,
    impl::consume<ISpreadsheetProvider>
{
    ISpreadsheetProvider(std::nullptr_t = nullptr) noexcept {}
};

struct IStylesProvider :
    Windows::IInspectable,
    impl::consume<IStylesProvider>
{
    IStylesProvider(std::nullptr_t = nullptr) noexcept {}
};

struct ISynchronizedInputProvider :
    Windows::IInspectable,
    impl::consume<ISynchronizedInputProvider>
{
    ISynchronizedInputProvider(std::nullptr_t = nullptr) noexcept {}
};

struct ITableItemProvider :
    Windows::IInspectable,
    impl::consume<ITableItemProvider>
{
    ITableItemProvider(std::nullptr_t = nullptr) noexcept {}
};

struct ITableProvider :
    Windows::IInspectable,
    impl::consume<ITableProvider>
{
    ITableProvider(std::nullptr_t = nullptr) noexcept {}
};

struct ITextChildProvider :
    Windows::IInspectable,
    impl::consume<ITextChildProvider>
{
    ITextChildProvider(std::nullptr_t = nullptr) noexcept {}
};

struct ITextEditProvider :
    Windows::IInspectable,
    impl::consume<ITextEditProvider>,
    impl::require<ITextEditProvider, Windows::UI::Xaml::Automation::Provider::ITextProvider>
{
    ITextEditProvider(std::nullptr_t = nullptr) noexcept {}
};

struct ITextProvider :
    Windows::IInspectable,
    impl::consume<ITextProvider>
{
    ITextProvider(std::nullptr_t = nullptr) noexcept {}
};

struct ITextProvider2 :
    Windows::IInspectable,
    impl::consume<ITextProvider2>,
    impl::require<ITextProvider2, Windows::UI::Xaml::Automation::Provider::ITextProvider>
{
    ITextProvider2(std::nullptr_t = nullptr) noexcept {}
};

struct ITextRangeProvider :
    Windows::IInspectable,
    impl::consume<ITextRangeProvider>
{
    ITextRangeProvider(std::nullptr_t = nullptr) noexcept {}
};

struct ITextRangeProvider2 :
    Windows::IInspectable,
    impl::consume<ITextRangeProvider2>,
    impl::require<ITextRangeProvider2, Windows::UI::Xaml::Automation::Provider::ITextRangeProvider>
{
    ITextRangeProvider2(std::nullptr_t = nullptr) noexcept {}
};

struct IToggleProvider :
    Windows::IInspectable,
    impl::consume<IToggleProvider>
{
    IToggleProvider(std::nullptr_t = nullptr) noexcept {}
};

struct ITransformProvider :
    Windows::IInspectable,
    impl::consume<ITransformProvider>
{
    ITransformProvider(std::nullptr_t = nullptr) noexcept {}
};

struct ITransformProvider2 :
    Windows::IInspectable,
    impl::consume<ITransformProvider2>,
    impl::require<ITransformProvider2, Windows::UI::Xaml::Automation::Provider::ITransformProvider>
{
    ITransformProvider2(std::nullptr_t = nullptr) noexcept {}
};

struct IValueProvider :
    Windows::IInspectable,
    impl::consume<IValueProvider>
{
    IValueProvider(std::nullptr_t = nullptr) noexcept {}
};

struct IVirtualizedItemProvider :
    Windows::IInspectable,
    impl::consume<IVirtualizedItemProvider>
{
    IVirtualizedItemProvider(std::nullptr_t = nullptr) noexcept {}
};

struct IWindowProvider :
    Windows::IInspectable,
    impl::consume<IWindowProvider>
{
    IWindowProvider(std::nullptr_t = nullptr) noexcept {}
};

}

}
