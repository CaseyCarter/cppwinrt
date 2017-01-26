// C++ for the Windows Runtime v1.0.private
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "Windows.Graphics.Effects.1.h"

WINRT_EXPORT namespace winrt {

namespace Windows::Graphics::Effects {

struct IGraphicsEffect :
    Windows::IInspectable,
    impl::consume<IGraphicsEffect>,
    impl::require<IGraphicsEffect, Windows::Graphics::Effects::IGraphicsEffectSource>
{
    IGraphicsEffect(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IGraphicsEffect>(m_ptr); }
};

struct IGraphicsEffectSource :
    Windows::IInspectable,
    impl::consume<IGraphicsEffectSource>
{
    IGraphicsEffectSource(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IGraphicsEffectSource>(m_ptr); }
};

}

}
