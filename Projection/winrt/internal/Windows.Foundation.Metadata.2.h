// C++ for the Windows Runtime v1.0.private
// Copyright (c) 2016 Microsoft Corporation. All rights reserved.

#pragma once

#include "Windows.Foundation.Metadata.1.h"

WINRT_EXPORT namespace winrt {

namespace Windows::Foundation::Metadata {

struct IApiInformationStatics :
    Windows::IInspectable,
    impl::consume<IApiInformationStatics>
{
    IApiInformationStatics(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IApiInformationStatics>(m_ptr); }
};

}

}
