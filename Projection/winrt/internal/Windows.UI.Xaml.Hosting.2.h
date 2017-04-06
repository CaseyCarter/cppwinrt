// C++ for the Windows Runtime v1.0.private
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "Windows.UI.Xaml.Hosting.1.h"

WINRT_EXPORT namespace winrt {

namespace Windows::UI::Xaml::Hosting {

struct IElementCompositionPreview :
    Windows::Foundation::IInspectable,
    impl::consume<IElementCompositionPreview>
{
    IElementCompositionPreview(std::nullptr_t = nullptr) noexcept {}
};

struct IElementCompositionPreviewStatics :
    Windows::Foundation::IInspectable,
    impl::consume<IElementCompositionPreviewStatics>
{
    IElementCompositionPreviewStatics(std::nullptr_t = nullptr) noexcept {}
};

struct IElementCompositionPreviewStatics2 :
    Windows::Foundation::IInspectable,
    impl::consume<IElementCompositionPreviewStatics2>
{
    IElementCompositionPreviewStatics2(std::nullptr_t = nullptr) noexcept {}
};

}

}
