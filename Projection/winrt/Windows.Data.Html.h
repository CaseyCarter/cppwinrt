// C++ for the Windows Runtime v1.0.private
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "internal/Windows.Data.Html.3.h"

WINRT_EXPORT namespace winrt {

namespace impl {

template <typename D>
struct produce<D, Windows::Data::Html::IHtmlUtilities> : produce_base<D, Windows::Data::Html::IHtmlUtilities>
{
    HRESULT __stdcall abi_ConvertToText(abi_arg_in<hstring> html, abi_arg_out<hstring> text) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *text = detach(this->shim().ConvertToText(*reinterpret_cast<const hstring *>(&html)));
            return S_OK;
        }
        catch (...)
        {
            *text = nullptr;
            return impl::to_hresult();
        }
    }
};

}

namespace Windows::Data::Html {

template <typename D> hstring impl_IHtmlUtilities<D>::ConvertToText(hstring_ref html) const
{
    hstring text;
    check_hresult(WINRT_SHIM(IHtmlUtilities)->abi_ConvertToText(get(html), put(text)));
    return text;
}

inline hstring HtmlUtilities::ConvertToText(hstring_ref html)
{
    return get_activation_factory<HtmlUtilities, IHtmlUtilities>().ConvertToText(html);
}

}

}
