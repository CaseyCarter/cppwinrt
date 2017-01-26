// C++ for the Windows Runtime v1.0.private
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "../base.h"
#include "Windows.UI.Xaml.Hosting.0.h"
#include "Windows.UI.Composition.0.h"
#include "Windows.UI.Xaml.0.h"
#include "Windows.UI.Xaml.Controls.0.h"

WINRT_EXPORT namespace winrt {

namespace ABI::Windows::UI::Xaml::Hosting {

struct __declspec(uuid("b6f1a676-cfe6-46ac-acf6-c4687bb65e60")) __declspec(novtable) IElementCompositionPreview : Windows::IInspectable
{
};

struct __declspec(uuid("08c92b38-ec99-4c55-bc85-a1c180b27646")) __declspec(novtable) IElementCompositionPreviewStatics : Windows::IInspectable
{
    virtual HRESULT __stdcall abi_GetElementVisual(Windows::UI::Xaml::IUIElement * element, Windows::UI::Composition::IVisual ** result) = 0;
    virtual HRESULT __stdcall abi_GetElementChildVisual(Windows::UI::Xaml::IUIElement * element, Windows::UI::Composition::IVisual ** result) = 0;
    virtual HRESULT __stdcall abi_SetElementChildVisual(Windows::UI::Xaml::IUIElement * element, Windows::UI::Composition::IVisual * visual) = 0;
    virtual HRESULT __stdcall abi_GetScrollViewerManipulationPropertySet(Windows::UI::Xaml::Controls::IScrollViewer * scrollViewer, Windows::UI::Composition::ICompositionPropertySet ** result) = 0;
};

}

namespace ABI {

template <> struct traits<Windows::UI::Xaml::Hosting::ElementCompositionPreview> { using default_interface = Windows::UI::Xaml::Hosting::IElementCompositionPreview; };

}

namespace Windows::UI::Xaml::Hosting {

template <typename D>
struct WINRT_EBO impl_IElementCompositionPreview
{
};

template <typename D>
struct WINRT_EBO impl_IElementCompositionPreviewStatics
{
    Windows::UI::Composition::Visual GetElementVisual(const Windows::UI::Xaml::UIElement & element) const;
    Windows::UI::Composition::Visual GetElementChildVisual(const Windows::UI::Xaml::UIElement & element) const;
    void SetElementChildVisual(const Windows::UI::Xaml::UIElement & element, const Windows::UI::Composition::Visual & visual) const;
    Windows::UI::Composition::CompositionPropertySet GetScrollViewerManipulationPropertySet(const Windows::UI::Xaml::Controls::ScrollViewer & scrollViewer) const;
};

}

namespace impl {

template <> struct traits<Windows::UI::Xaml::Hosting::IElementCompositionPreview>
{
    using abi = ABI::Windows::UI::Xaml::Hosting::IElementCompositionPreview;
    template <typename D> using consume = Windows::UI::Xaml::Hosting::impl_IElementCompositionPreview<D>;
};

template <> struct traits<Windows::UI::Xaml::Hosting::IElementCompositionPreviewStatics>
{
    using abi = ABI::Windows::UI::Xaml::Hosting::IElementCompositionPreviewStatics;
    template <typename D> using consume = Windows::UI::Xaml::Hosting::impl_IElementCompositionPreviewStatics<D>;
};

template <> struct traits<Windows::UI::Xaml::Hosting::ElementCompositionPreview>
{
    using abi = ABI::Windows::UI::Xaml::Hosting::ElementCompositionPreview;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Hosting.ElementCompositionPreview"; }
};

}

}
