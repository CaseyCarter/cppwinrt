// C++ for the Windows Runtime v1.29
// Copyright (c) 2016 Microsoft Corporation

#pragma once

#include "internal/Windows.UI.3.h"
#include "internal/Windows.Media.ClosedCaptioning.3.h"
#include "Windows.Media.h"

WINRT_EXPORT namespace winrt {

namespace impl {

template <typename D>
struct produce<D, Windows::Media::ClosedCaptioning::IClosedCaptionPropertiesStatics> : produce_base<D, Windows::Media::ClosedCaptioning::IClosedCaptionPropertiesStatics>
{
    HRESULT __stdcall get_FontColor(Windows::Media::ClosedCaptioning::ClosedCaptionColor * value) noexcept override
    {
        try
        {
            *value = detach(this->shim().FontColor());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ComputedFontColor(abi_arg_out<Windows::UI::Color> value) noexcept override
    {
        try
        {
            *value = detach(this->shim().ComputedFontColor());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_FontOpacity(Windows::Media::ClosedCaptioning::ClosedCaptionOpacity * value) noexcept override
    {
        try
        {
            *value = detach(this->shim().FontOpacity());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_FontSize(Windows::Media::ClosedCaptioning::ClosedCaptionSize * value) noexcept override
    {
        try
        {
            *value = detach(this->shim().FontSize());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_FontStyle(Windows::Media::ClosedCaptioning::ClosedCaptionStyle * value) noexcept override
    {
        try
        {
            *value = detach(this->shim().FontStyle());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_FontEffect(Windows::Media::ClosedCaptioning::ClosedCaptionEdgeEffect * value) noexcept override
    {
        try
        {
            *value = detach(this->shim().FontEffect());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_BackgroundColor(Windows::Media::ClosedCaptioning::ClosedCaptionColor * value) noexcept override
    {
        try
        {
            *value = detach(this->shim().BackgroundColor());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ComputedBackgroundColor(abi_arg_out<Windows::UI::Color> value) noexcept override
    {
        try
        {
            *value = detach(this->shim().ComputedBackgroundColor());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_BackgroundOpacity(Windows::Media::ClosedCaptioning::ClosedCaptionOpacity * value) noexcept override
    {
        try
        {
            *value = detach(this->shim().BackgroundOpacity());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_RegionColor(Windows::Media::ClosedCaptioning::ClosedCaptionColor * value) noexcept override
    {
        try
        {
            *value = detach(this->shim().RegionColor());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ComputedRegionColor(abi_arg_out<Windows::UI::Color> value) noexcept override
    {
        try
        {
            *value = detach(this->shim().ComputedRegionColor());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_RegionOpacity(Windows::Media::ClosedCaptioning::ClosedCaptionOpacity * value) noexcept override
    {
        try
        {
            *value = detach(this->shim().RegionOpacity());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

}

namespace Windows::Media::ClosedCaptioning {

template <typename D> Windows::Media::ClosedCaptioning::ClosedCaptionColor impl_IClosedCaptionPropertiesStatics<D>::FontColor() const
{
    Windows::Media::ClosedCaptioning::ClosedCaptionColor value {};
    check_hresult(shim()->get_FontColor(&value));
    return value;
}

template <typename D> Windows::UI::Color impl_IClosedCaptionPropertiesStatics<D>::ComputedFontColor() const
{
    Windows::UI::Color value {};
    check_hresult(shim()->get_ComputedFontColor(put(value)));
    return value;
}

template <typename D> Windows::Media::ClosedCaptioning::ClosedCaptionOpacity impl_IClosedCaptionPropertiesStatics<D>::FontOpacity() const
{
    Windows::Media::ClosedCaptioning::ClosedCaptionOpacity value {};
    check_hresult(shim()->get_FontOpacity(&value));
    return value;
}

template <typename D> Windows::Media::ClosedCaptioning::ClosedCaptionSize impl_IClosedCaptionPropertiesStatics<D>::FontSize() const
{
    Windows::Media::ClosedCaptioning::ClosedCaptionSize value {};
    check_hresult(shim()->get_FontSize(&value));
    return value;
}

template <typename D> Windows::Media::ClosedCaptioning::ClosedCaptionStyle impl_IClosedCaptionPropertiesStatics<D>::FontStyle() const
{
    Windows::Media::ClosedCaptioning::ClosedCaptionStyle value {};
    check_hresult(shim()->get_FontStyle(&value));
    return value;
}

template <typename D> Windows::Media::ClosedCaptioning::ClosedCaptionEdgeEffect impl_IClosedCaptionPropertiesStatics<D>::FontEffect() const
{
    Windows::Media::ClosedCaptioning::ClosedCaptionEdgeEffect value {};
    check_hresult(shim()->get_FontEffect(&value));
    return value;
}

template <typename D> Windows::Media::ClosedCaptioning::ClosedCaptionColor impl_IClosedCaptionPropertiesStatics<D>::BackgroundColor() const
{
    Windows::Media::ClosedCaptioning::ClosedCaptionColor value {};
    check_hresult(shim()->get_BackgroundColor(&value));
    return value;
}

template <typename D> Windows::UI::Color impl_IClosedCaptionPropertiesStatics<D>::ComputedBackgroundColor() const
{
    Windows::UI::Color value {};
    check_hresult(shim()->get_ComputedBackgroundColor(put(value)));
    return value;
}

template <typename D> Windows::Media::ClosedCaptioning::ClosedCaptionOpacity impl_IClosedCaptionPropertiesStatics<D>::BackgroundOpacity() const
{
    Windows::Media::ClosedCaptioning::ClosedCaptionOpacity value {};
    check_hresult(shim()->get_BackgroundOpacity(&value));
    return value;
}

template <typename D> Windows::Media::ClosedCaptioning::ClosedCaptionColor impl_IClosedCaptionPropertiesStatics<D>::RegionColor() const
{
    Windows::Media::ClosedCaptioning::ClosedCaptionColor value {};
    check_hresult(shim()->get_RegionColor(&value));
    return value;
}

template <typename D> Windows::UI::Color impl_IClosedCaptionPropertiesStatics<D>::ComputedRegionColor() const
{
    Windows::UI::Color value {};
    check_hresult(shim()->get_ComputedRegionColor(put(value)));
    return value;
}

template <typename D> Windows::Media::ClosedCaptioning::ClosedCaptionOpacity impl_IClosedCaptionPropertiesStatics<D>::RegionOpacity() const
{
    Windows::Media::ClosedCaptioning::ClosedCaptionOpacity value {};
    check_hresult(shim()->get_RegionOpacity(&value));
    return value;
}

inline Windows::Media::ClosedCaptioning::ClosedCaptionColor ClosedCaptionProperties::FontColor()
{
    return get_activation_factory<ClosedCaptionProperties, IClosedCaptionPropertiesStatics>().FontColor();
}

inline Windows::UI::Color ClosedCaptionProperties::ComputedFontColor()
{
    return get_activation_factory<ClosedCaptionProperties, IClosedCaptionPropertiesStatics>().ComputedFontColor();
}

inline Windows::Media::ClosedCaptioning::ClosedCaptionOpacity ClosedCaptionProperties::FontOpacity()
{
    return get_activation_factory<ClosedCaptionProperties, IClosedCaptionPropertiesStatics>().FontOpacity();
}

inline Windows::Media::ClosedCaptioning::ClosedCaptionSize ClosedCaptionProperties::FontSize()
{
    return get_activation_factory<ClosedCaptionProperties, IClosedCaptionPropertiesStatics>().FontSize();
}

inline Windows::Media::ClosedCaptioning::ClosedCaptionStyle ClosedCaptionProperties::FontStyle()
{
    return get_activation_factory<ClosedCaptionProperties, IClosedCaptionPropertiesStatics>().FontStyle();
}

inline Windows::Media::ClosedCaptioning::ClosedCaptionEdgeEffect ClosedCaptionProperties::FontEffect()
{
    return get_activation_factory<ClosedCaptionProperties, IClosedCaptionPropertiesStatics>().FontEffect();
}

inline Windows::Media::ClosedCaptioning::ClosedCaptionColor ClosedCaptionProperties::BackgroundColor()
{
    return get_activation_factory<ClosedCaptionProperties, IClosedCaptionPropertiesStatics>().BackgroundColor();
}

inline Windows::UI::Color ClosedCaptionProperties::ComputedBackgroundColor()
{
    return get_activation_factory<ClosedCaptionProperties, IClosedCaptionPropertiesStatics>().ComputedBackgroundColor();
}

inline Windows::Media::ClosedCaptioning::ClosedCaptionOpacity ClosedCaptionProperties::BackgroundOpacity()
{
    return get_activation_factory<ClosedCaptionProperties, IClosedCaptionPropertiesStatics>().BackgroundOpacity();
}

inline Windows::Media::ClosedCaptioning::ClosedCaptionColor ClosedCaptionProperties::RegionColor()
{
    return get_activation_factory<ClosedCaptionProperties, IClosedCaptionPropertiesStatics>().RegionColor();
}

inline Windows::UI::Color ClosedCaptionProperties::ComputedRegionColor()
{
    return get_activation_factory<ClosedCaptionProperties, IClosedCaptionPropertiesStatics>().ComputedRegionColor();
}

inline Windows::Media::ClosedCaptioning::ClosedCaptionOpacity ClosedCaptionProperties::RegionOpacity()
{
    return get_activation_factory<ClosedCaptionProperties, IClosedCaptionPropertiesStatics>().RegionOpacity();
}

}

}
