// C++ for the Windows Runtime v1.0.private
// Copyright (c) 2016 Microsoft Corporation. All rights reserved.

#pragma once

#include "Windows.UI.Composition.Effects.1.h"
#include "Windows.Graphics.Effects.1.h"

WINRT_EXPORT namespace winrt {

namespace Windows::UI::Composition::Effects {

struct ISceneLightingEffect :
    Windows::IInspectable,
    impl::consume<ISceneLightingEffect>
{
    ISceneLightingEffect(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<ISceneLightingEffect>(m_ptr); }
};

}

}
