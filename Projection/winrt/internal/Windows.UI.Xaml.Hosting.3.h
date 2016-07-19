// C++ for the Windows Runtime v1.29
// Copyright (c) 2016 Microsoft Corporation

#pragma once

#include "Windows.UI.Xaml.Hosting.2.h"

WINRT_EXPORT namespace winrt {

namespace Windows::UI::Xaml::Hosting {

struct WINRT_EBO ElementCompositionPreview :
    Windows::UI::Xaml::Hosting::IElementCompositionPreview
{
    ElementCompositionPreview(std::nullptr_t) noexcept {}
    static Windows::UI::Composition::Visual GetElementVisual(const Windows::UI::Xaml::UIElement & element);
    static Windows::UI::Composition::Visual GetElementChildVisual(const Windows::UI::Xaml::UIElement & element);
    static void SetElementChildVisual(const Windows::UI::Xaml::UIElement & element, const Windows::UI::Composition::Visual & visual);
    static Windows::UI::Composition::CompositionPropertySet GetScrollViewerManipulationPropertySet(const Windows::UI::Xaml::Controls::ScrollViewer & scrollViewer);
};

}

}
