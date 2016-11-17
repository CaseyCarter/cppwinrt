// C++ for the Windows Runtime v1.0.private
// Copyright (c) 2016 Microsoft Corporation. All rights reserved.

#pragma once

#include "Windows.Management.Core.1.h"

WINRT_EXPORT namespace winrt {

namespace Windows::Management::Core {

struct IApplicationDataManager :
    Windows::IInspectable,
    impl::consume<IApplicationDataManager>
{
    IApplicationDataManager(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IApplicationDataManager>(m_ptr); }
};

struct IApplicationDataManagerStatics :
    Windows::IInspectable,
    impl::consume<IApplicationDataManagerStatics>
{
    IApplicationDataManagerStatics(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IApplicationDataManagerStatics>(m_ptr); }
};

}

}
