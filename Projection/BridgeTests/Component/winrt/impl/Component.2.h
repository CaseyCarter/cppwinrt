// C++/WinRT v1.0.170906.1
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once
#include "winrt/impl/Component.1.h"

WINRT_EXPORT namespace winrt::Component {

}

namespace winrt::impl {

}

WINRT_EXPORT namespace winrt::Component {

struct WINRT_EBO Parameters :
    Component::IParameters
{
    Parameters(std::nullptr_t) noexcept {}
    Parameters();
};

}
