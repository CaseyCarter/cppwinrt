// C++ for the Windows Runtime v1.0.private
// Copyright (c) 2016 Microsoft Corporation. All rights reserved.

#pragma once

#include "Windows.Security.Cryptography.1.h"

WINRT_EXPORT namespace winrt {

namespace Windows::Security::Cryptography {

struct ICryptographicBufferStatics :
    Windows::IInspectable,
    impl::consume<ICryptographicBufferStatics>
{
    ICryptographicBufferStatics(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<ICryptographicBufferStatics>(m_ptr); }
};

}

}
