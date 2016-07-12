// C++ for the Windows Runtime v1.29
// Copyright (c) 2016 Microsoft Corporation

#pragma once

#include "Windows.UI.Composition.Effects.abi.h"
#include "Windows.Graphics.Effects.interface.h"

WINRT_EXPORT namespace winrt {

namespace Windows::UI::Composition::Effects {

template <typename D>
class WINRT_EBO impl_ISceneLightingEffect
{
    auto shim() const { return impl::shim<D, ISceneLightingEffect>(this); }

public:

    float AmbientAmount() const;
    void AmbientAmount(float value) const;
    float DiffuseAmount() const;
    void DiffuseAmount(float value) const;
    Windows::Graphics::Effects::IGraphicsEffectSource NormalMapSource() const;
    void NormalMapSource(const Windows::Graphics::Effects::IGraphicsEffectSource & value) const;
    float SpecularAmount() const;
    void SpecularAmount(float value) const;
    float SpecularShine() const;
    void SpecularShine(float value) const;
};

struct ISceneLightingEffect :
    Windows::IInspectable,
    impl::consume<ISceneLightingEffect>
{
    ISceneLightingEffect(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<ISceneLightingEffect>(m_ptr); }
};

}

}
