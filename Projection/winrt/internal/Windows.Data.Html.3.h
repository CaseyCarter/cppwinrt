// C++ for the Windows Runtime v1.0.private
// Copyright (c) 2016 Microsoft Corporation

#pragma once

#include "Windows.Data.Html.2.h"

WINRT_EXPORT namespace winrt {

namespace Windows::Data::Html {

struct HtmlUtilities
{
    HtmlUtilities() = delete;
    static hstring ConvertToText(hstring_ref html);
};

}

}
