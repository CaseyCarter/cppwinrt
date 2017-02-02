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
};

struct ILowLevelDevicesAggregateProviderFactory :
    Windows::IInspectable,
    impl::consume<ILowLevelDevicesAggregateProviderFactory>
{
    ILowLevelDevicesAggregateProviderFactory(std::nullptr_t = nullptr) noexcept {}
};

struct ILowLevelDevicesController :
    Windows::IInspectable,
    impl::consume<ILowLevelDevicesController>
{
    ILowLevelDevicesController(std::nullptr_t = nullptr) noexcept {}
};

struct ILowLevelDevicesControllerStatics :
    Windows::IInspectable,
    impl::consume<ILowLevelDevicesControllerStatics>
{
    ILowLevelDevicesControllerStatics(std::nullptr_t = nullptr) noexcept {}
};

}

}
