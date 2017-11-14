﻿// C++/WinRT v1.0.170906.1
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once
#include "winrt/impl/Component.0.h"

WINRT_EXPORT namespace winrt::Component {

struct WINRT_EBO IParameters :
    Windows::Foundation::IInspectable,
    impl::consume_t<IParameters>
{
    IParameters(std::nullptr_t = nullptr) noexcept {}
};

}
