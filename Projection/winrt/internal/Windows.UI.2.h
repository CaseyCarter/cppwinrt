// C++ for the Windows Runtime v1.0.private
// Copyright (c) 2016 Microsoft Corporation. All rights reserved.

#pragma once

#include "Windows.UI.1.h"

WINRT_EXPORT namespace winrt {

namespace Windows::UI {

struct IColorHelper :
    Windows::IInspectable,
    impl::consume<IColorHelper>
{
    IColorHelper(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IColorHelper>(m_ptr); }
};

struct IColorHelperStatics :
    Windows::IInspectable,
    impl::consume<IColorHelperStatics>
{
    IColorHelperStatics(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IColorHelperStatics>(m_ptr); }
};

struct IColors :
    Windows::IInspectable,
    impl::consume<IColors>
{
    IColors(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IColors>(m_ptr); }
};

struct IColorsStatics :
    Windows::IInspectable,
    impl::consume<IColorsStatics>
{
    IColorsStatics(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IColorsStatics>(m_ptr); }
};

}

}
