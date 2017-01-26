// C++ for the Windows Runtime v1.0.private
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "Windows.UI.Xaml.Hosting.1.h"

WINRT_EXPORT namespace winrt {

namespace Windows::UI::Xaml::Hosting {

struct IElementCompositionPreview :
    Windows::IInspectable,
    impl::consume<IElementCompositionPreview>
{
    IElementCompositionPreview(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IElementCompositionPreview>(m_ptr); }
};

struct IElementCompositionPreviewStatics :
    Windows::IInspectable,
    impl::consume<IElementCompositionPreviewStatics>
{
    IElementCompositionPreviewStatics(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IElementCompositionPreviewStatics>(m_ptr); }
};

}

}
