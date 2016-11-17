// C++ for the Windows Runtime v1.0.private
// Copyright (c) 2016 Microsoft Corporation. All rights reserved.

#pragma once

#include "Windows.Media.ClosedCaptioning.1.h"

WINRT_EXPORT namespace winrt {

namespace Windows::Media::ClosedCaptioning {

struct IClosedCaptionPropertiesStatics :
    Windows::IInspectable,
    impl::consume<IClosedCaptionPropertiesStatics>
{
    IClosedCaptionPropertiesStatics(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IClosedCaptionPropertiesStatics>(m_ptr); }
};

}

}
