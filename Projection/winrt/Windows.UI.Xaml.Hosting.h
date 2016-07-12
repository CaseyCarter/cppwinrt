// C++ for the Windows Runtime v1.29
// Copyright (c) 2016 Microsoft Corporation

#pragma once

#include "internal\Windows.UI.Xaml.Hosting.class.h"
#include "internal\Windows.UI.Xaml.class.h"
#include "internal\Windows.UI.Composition.class.h"
#include "internal\Windows.UI.Xaml.Controls.class.h"
#include "Windows.UI.Xaml.h"

WINRT_EXPORT namespace winrt {

namespace impl {

template <typename D>
struct produce<D, Windows::UI::Xaml::Hosting::IElementCompositionPreview> : produce_base<D, Windows::UI::Xaml::Hosting::IElementCompositionPreview>
{};

template <typename D>
struct produce<D, Windows::UI::Xaml::Hosting::IElementCompositionPreviewStatics> : produce_base<D, Windows::UI::Xaml::Hosting::IElementCompositionPreviewStatics>
{
    HRESULT __stdcall abi_GetElementVisual(abi_arg_in<Windows::UI::Xaml::IUIElement> element, abi_arg_out<Windows::UI::Composition::IVisual> result) noexcept override
    {
        try
        {
            *result = detach(shim().GetElementVisual(*reinterpret_cast<const Windows::UI::Xaml::UIElement *>(&element)));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetElementChildVisual(abi_arg_in<Windows::UI::Xaml::IUIElement> element, abi_arg_out<Windows::UI::Composition::IVisual> result) noexcept override
    {
        try
        {
            *result = detach(shim().GetElementChildVisual(*reinterpret_cast<const Windows::UI::Xaml::UIElement *>(&element)));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_SetElementChildVisual(abi_arg_in<Windows::UI::Xaml::IUIElement> element, abi_arg_in<Windows::UI::Composition::IVisual> visual) noexcept override
    {
        try
        {
            shim().SetElementChildVisual(*reinterpret_cast<const Windows::UI::Xaml::UIElement *>(&element), *reinterpret_cast<const Windows::UI::Composition::Visual *>(&visual));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetScrollViewerManipulationPropertySet(abi_arg_in<Windows::UI::Xaml::Controls::IScrollViewer> scrollViewer, abi_arg_out<Windows::UI::Composition::ICompositionPropertySet> result) noexcept override
    {
        try
        {
            *result = detach(shim().GetScrollViewerManipulationPropertySet(*reinterpret_cast<const Windows::UI::Xaml::Controls::ScrollViewer *>(&scrollViewer)));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }
};

}

namespace Windows::UI::Xaml::Hosting {

template <typename D> Windows::UI::Composition::Visual impl_IElementCompositionPreviewStatics<D>::GetElementVisual(const Windows::UI::Xaml::UIElement & element) const
{
    Windows::UI::Composition::Visual result { nullptr };
    check_hresult(shim()->abi_GetElementVisual(get(element), put(result)));
    return result;
}

template <typename D> Windows::UI::Composition::Visual impl_IElementCompositionPreviewStatics<D>::GetElementChildVisual(const Windows::UI::Xaml::UIElement & element) const
{
    Windows::UI::Composition::Visual result { nullptr };
    check_hresult(shim()->abi_GetElementChildVisual(get(element), put(result)));
    return result;
}

template <typename D> void impl_IElementCompositionPreviewStatics<D>::SetElementChildVisual(const Windows::UI::Xaml::UIElement & element, const Windows::UI::Composition::Visual & visual) const
{
    check_hresult(shim()->abi_SetElementChildVisual(get(element), get(visual)));
}

template <typename D> Windows::UI::Composition::CompositionPropertySet impl_IElementCompositionPreviewStatics<D>::GetScrollViewerManipulationPropertySet(const Windows::UI::Xaml::Controls::ScrollViewer & scrollViewer) const
{
    Windows::UI::Composition::CompositionPropertySet result { nullptr };
    check_hresult(shim()->abi_GetScrollViewerManipulationPropertySet(get(scrollViewer), put(result)));
    return result;
}

inline Windows::UI::Composition::Visual ElementCompositionPreview::GetElementVisual(const Windows::UI::Xaml::UIElement & element)
{
    return GetActivationFactory<ElementCompositionPreview, IElementCompositionPreviewStatics>().GetElementVisual(element);
}

inline Windows::UI::Composition::Visual ElementCompositionPreview::GetElementChildVisual(const Windows::UI::Xaml::UIElement & element)
{
    return GetActivationFactory<ElementCompositionPreview, IElementCompositionPreviewStatics>().GetElementChildVisual(element);
}

inline void ElementCompositionPreview::SetElementChildVisual(const Windows::UI::Xaml::UIElement & element, const Windows::UI::Composition::Visual & visual)
{
    GetActivationFactory<ElementCompositionPreview, IElementCompositionPreviewStatics>().SetElementChildVisual(element, visual);
}

inline Windows::UI::Composition::CompositionPropertySet ElementCompositionPreview::GetScrollViewerManipulationPropertySet(const Windows::UI::Xaml::Controls::ScrollViewer & scrollViewer)
{
    return GetActivationFactory<ElementCompositionPreview, IElementCompositionPreviewStatics>().GetScrollViewerManipulationPropertySet(scrollViewer);
}

}

}
