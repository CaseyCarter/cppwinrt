// C++ for the Windows Runtime v1.0.private
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "Windows.System.Display.1.h"

WINRT_EXPORT namespace winrt {

namespace Windows::System::Display {

struct IDisplayRequest :
    Windows::IInspectable,
    impl::consume<IDisplayRequest>
{
    IDisplayRequest(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IDisplayRequest>(m_ptr); }
};

}

}
