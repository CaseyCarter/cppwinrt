// C++ for the Windows Runtime v1.0.private
// Copyright (c) 2016 Microsoft Corporation. All rights reserved.

#pragma once

#include "Windows.System.RemoteDesktop.1.h"

WINRT_EXPORT namespace winrt {

namespace Windows::System::RemoteDesktop {

struct IInteractiveSessionStatics :
    Windows::IInspectable,
    impl::consume<IInteractiveSessionStatics>
{
    IInteractiveSessionStatics(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IInteractiveSessionStatics>(m_ptr); }
};

}

}
