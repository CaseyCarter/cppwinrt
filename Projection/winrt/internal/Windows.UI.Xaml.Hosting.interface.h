// C++ for the Windows Runtime v1.29
// Copyright (c) 2016 Microsoft Corporation

#pragma once

#include "Windows.UI.Xaml.Hosting.abi.h"

WINRT_EXPORT namespace winrt {

namespace Windows::UI::Xaml::Hosting {

template <typename D>
class WINRT_EBO impl_IElementCompositionPreview
{
    auto shim() const { return impl::shim<D, IElementCompositionPreview>(this); }

public:

};

template <typename D>
class WINRT_EBO impl_IElementCompositionPreviewStatics
{
    auto shim() const { return impl::shim<D, IElementCompositionPreviewStatics>(this); }

public:

    Windows::UI::Composition::Visual GetElementVisual(const Windows::UI::Xaml::UIElement & element) const;
    Windows::UI::Composition::Visual GetElementChildVisual(const Windows::UI::Xaml::UIElement & element) const;
    void SetElementChildVisual(const Windows::UI::Xaml::UIElement & element, const Windows::UI::Composition::Visual & visual) const;
    Windows::UI::Composition::CompositionPropertySet GetScrollViewerManipulationPropertySet(const Windows::UI::Xaml::Controls::ScrollViewer & scrollViewer) const;
};

struct IElementCompositionPreview :
    Windows::IInspectable,
    impl::consume<IElementCompositionPreview>
{
    IElementCompositionPreview(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IElementCompositionPreview>(m_ptr); }
};

struct IElementCompositionPreviewStatics :
    Windows::IInspectable,
    impl::consume<IElementCompositionPreviewStatics>
{
    IElementCompositionPreviewStatics(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IElementCompositionPreviewStatics>(m_ptr); }
};

}

}
