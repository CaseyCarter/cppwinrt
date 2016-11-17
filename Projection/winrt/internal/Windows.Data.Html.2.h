// C++ for the Windows Runtime v1.0.private
// Copyright (c) 2016 Microsoft Corporation. All rights reserved.

#pragma once

#include "Windows.Data.Html.1.h"

WINRT_EXPORT namespace winrt {

namespace Windows::Data::Html {

struct IHtmlUtilities :
    Windows::IInspectable,
    impl::consume<IHtmlUtilities>
{
    IHtmlUtilities(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IHtmlUtilities>(m_ptr); }
};

}

}
