// C++ for the Windows Runtime v1.0.private
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "Windows.Devices.1.h"

WINRT_EXPORT namespace winrt {

namespace Windows::Devices {

struct ILowLevelDevicesAggregateProvider :
    Windows::IInspectable,
    impl::consume<ILowLevelDevicesAggregateProvider>
{
    ILowLevelDevicesAggregateProvider(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<ILowLevelDevicesAggregateProvider>(m_ptr); }
};

struct ILowLevelDevicesAggregateProviderFactory :
    Windows::IInspectable,
    impl::consume<ILowLevelDevicesAggregateProviderFactory>
{
    ILowLevelDevicesAggregateProviderFactory(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<ILowLevelDevicesAggregateProviderFactory>(m_ptr); }
};

struct ILowLevelDevicesController :
    Windows::IInspectable,
    impl::consume<ILowLevelDevicesController>
{
    ILowLevelDevicesController(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<ILowLevelDevicesController>(m_ptr); }
};

struct ILowLevelDevicesControllerStatics :
    Windows::IInspectable,
    impl::consume<ILowLevelDevicesControllerStatics>
{
    ILowLevelDevicesControllerStatics(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<ILowLevelDevicesControllerStatics>(m_ptr); }
};

}

}
