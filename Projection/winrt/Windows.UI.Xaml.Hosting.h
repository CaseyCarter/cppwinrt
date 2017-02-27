// C++ for the Windows Runtime v1.0.private
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "base.h"
WINRT_WARNING_PUSH

#include "internal/Windows.UI.Xaml.3.h"
#include "internal/Windows.UI.Composition.3.h"
#include "internal/Windows.UI.Xaml.Controls.3.h"
#include "internal/Windows.UI.Xaml.Hosting.3.h"
#include "Windows.UI.Xaml.h"

WINRT_EXPORT namespace winrt {

namespace impl {

template <typename D>
struct produce<D, Windows::UI::Xaml::Hosting::IElementCompositionPreview> : produce_base<D, Windows::UI::Xaml::Hosting::IElementCompositionPreview>
{};

template <typename D>
struct produce<D, Windows::UI::Xaml::Hosting::IElementCompositionPreviewStatics> : produce_base<D, Windows::UI::Xaml::Hosting::IElementCompositionPreviewStatics>
{
    HRESULT __stdcall abi_GetElementVisual(impl::abi_arg_in<Windows::UI::Xaml::IUIElement> element, impl::abi_arg_out<Windows::UI::Composition::IVisual> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().GetElementVisual(*reinterpret_cast<const Windows::UI::Xaml::UIElement *>(&element)));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetElementChildVisual(impl::abi_arg_in<Windows::UI::Xaml::IUIElement> element, impl::abi_arg_out<Windows::UI::Composition::IVisual> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().GetElementChildVisual(*reinterpret_cast<const Windows::UI::Xaml::UIElement *>(&element)));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_SetElementChildVisual(impl::abi_arg_in<Windows::UI::Xaml::IUIElement> element, impl::abi_arg_in<Windows::UI::Composition::IVisual> visual) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SetElementChildVisual(*reinterpret_cast<const Windows::UI::Xaml::UIElement *>(&element), *reinterpret_cast<const Windows::UI::Composition::Visual *>(&visual));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetScrollViewerManipulationPropertySet(impl::abi_arg_in<Windows::UI::Xaml::Controls::IScrollViewer> scrollViewer, impl::abi_arg_out<Windows::UI::Composition::ICompositionPropertySet> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().GetScrollViewerManipulationPropertySet(*reinterpret_cast<const Windows::UI::Xaml::Controls::ScrollViewer *>(&scrollViewer)));
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
    check_hresult(WINRT_SHIM(IElementCompositionPreviewStatics)->abi_GetElementVisual(get_abi(element), put_abi(result)));
    return result;
}

template <typename D> Windows::UI::Composition::Visual impl_IElementCompositionPreviewStatics<D>::GetElementChildVisual(const Windows::UI::Xaml::UIElement & element) const
{
    Windows::UI::Composition::Visual result { nullptr };
    check_hresult(WINRT_SHIM(IElementCompositionPreviewStatics)->abi_GetElementChildVisual(get_abi(element), put_abi(result)));
    return result;
}

template <typename D> void impl_IElementCompositionPreviewStatics<D>::SetElementChildVisual(const Windows::UI::Xaml::UIElement & element, const Windows::UI::Composition::Visual & visual) const
{
    check_hresult(WINRT_SHIM(IElementCompositionPreviewStatics)->abi_SetElementChildVisual(get_abi(element), get_abi(visual)));
}

template <typename D> Windows::UI::Composition::CompositionPropertySet impl_IElementCompositionPreviewStatics<D>::GetScrollViewerManipulationPropertySet(const Windows::UI::Xaml::Controls::ScrollViewer & scrollViewer) const
{
    Windows::UI::Composition::CompositionPropertySet result { nullptr };
    check_hresult(WINRT_SHIM(IElementCompositionPreviewStatics)->abi_GetScrollViewerManipulationPropertySet(get_abi(scrollViewer), put_abi(result)));
    return result;
}

inline Windows::UI::Composition::Visual ElementCompositionPreview::GetElementVisual(const Windows::UI::Xaml::UIElement & element)
{
    return get_activation_factory<ElementCompositionPreview, IElementCompositionPreviewStatics>().GetElementVisual(element);
}

inline Windows::UI::Composition::Visual ElementCompositionPreview::GetElementChildVisual(const Windows::UI::Xaml::UIElement & element)
{
    return get_activation_factory<ElementCompositionPreview, IElementCompositionPreviewStatics>().GetElementChildVisual(element);
}

inline void ElementCompositionPreview::SetElementChildVisual(const Windows::UI::Xaml::UIElement & element, const Windows::UI::Composition::Visual & visual)
{
    get_activation_factory<ElementCompositionPreview, IElementCompositionPreviewStatics>().SetElementChildVisual(element, visual);
}

inline Windows::UI::Composition::CompositionPropertySet ElementCompositionPreview::GetScrollViewerManipulationPropertySet(const Windows::UI::Xaml::Controls::ScrollViewer & scrollViewer)
{
    return get_activation_factory<ElementCompositionPreview, IElementCompositionPreviewStatics>().GetScrollViewerManipulationPropertySet(scrollViewer);
}

}

}

template<>
struct std::hash<winrt::Windows::UI::Xaml::Hosting::IElementCompositionPreview>
{
    size_t operator()(const winrt::Windows::UI::Xaml::Hosting::IElementCompositionPreview & value) const noexcept
    {
        return winrt::impl::hash_unknown(value);
    }
};

template<>
struct std::hash<winrt::Windows::UI::Xaml::Hosting::IElementCompositionPreviewStatics>
{
    size_t operator()(const winrt::Windows::UI::Xaml::Hosting::IElementCompositionPreviewStatics & value) const noexcept
    {
        return winrt::impl::hash_unknown(value);
    }
};

template<>
struct std::hash<winrt::Windows::UI::Xaml::Hosting::ElementCompositionPreview>
{
    size_t operator()(const winrt::Windows::UI::Xaml::Hosting::ElementCompositionPreview & value) const noexcept
    {
        return winrt::impl::hash_unknown(value);
    }
};

WINRT_WARNING_POP
