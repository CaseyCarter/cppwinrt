// C++ for the Windows Runtime v1.0.private
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "Windows.UI.1.h"

WINRT_EXPORT namespace winrt {

namespace Windows::UI {

struct IColorHelper :
    Windows::IInspectable,
    impl::consume<IColorHelper>
{
    IColorHelper(std::nullptr_t = nullptr) noexcept {}
};

struct IColorHelperStatics :
    Windows::IInspectable,
    impl::consume<IColorHelperStatics>
{
    IColorHelperStatics(std::nullptr_t = nullptr) noexcept {}
};

struct IColors :
    Windows::IInspectable,
    impl::consume<IColors>
{
    IColors(std::nullptr_t = nullptr) noexcept {}
};

struct IColorsStatics :
    Windows::IInspectable,
    impl::consume<IColorsStatics>
{
    IColorsStatics(std::nullptr_t = nullptr) noexcept {}
};

}

}
