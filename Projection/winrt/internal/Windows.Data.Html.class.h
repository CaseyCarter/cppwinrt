// C++ for the Windows Runtime v1.29
// Copyright (c) 2016 Microsoft Corporation

#pragma once

#include "Windows.Data.Html.interface.h"

WINRT_EXPORT namespace winrt {

namespace Windows::Data::Html {

struct HtmlUtilities
{
    HtmlUtilities() = delete;
    static hstring ConvertToText(hstring_ref html);
};

}

}
