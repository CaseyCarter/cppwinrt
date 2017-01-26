// C++ for the Windows Runtime v1.0.private
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "Windows.Networking.1.h"
#include "Windows.Foundation.1.h"

WINRT_EXPORT namespace winrt {

namespace Windows::Networking {

struct IEndpointPair :
    Windows::IInspectable,
    impl::consume<IEndpointPair>
{
    IEndpointPair(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IEndpointPair>(m_ptr); }
};

struct IEndpointPairFactory :
    Windows::IInspectable,
    impl::consume<IEndpointPairFactory>
{
    IEndpointPairFactory(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IEndpointPairFactory>(m_ptr); }
};

struct IHostName :
    Windows::IInspectable,
    impl::consume<IHostName>
{
    IHostName(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IHostName>(m_ptr); }
};

struct IHostNameFactory :
    Windows::IInspectable,
    impl::consume<IHostNameFactory>
{
    IHostNameFactory(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IHostNameFactory>(m_ptr); }
};

struct IHostNameStatics :
    Windows::IInspectable,
    impl::consume<IHostNameStatics>
{
    IHostNameStatics(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IHostNameStatics>(m_ptr); }
};

}

}
