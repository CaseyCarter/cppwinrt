// C++ for the Windows Runtime v1.29
// Copyright (c) 2016 Microsoft Corporation

#pragma once

#include "Windows.Devices.Background.2.h"

WINRT_EXPORT namespace winrt {

namespace Windows::Devices::Background {

struct WINRT_EBO DeviceServicingDetails :
    Windows::Devices::Background::IDeviceServicingDetails
{
    DeviceServicingDetails(std::nullptr_t) noexcept {}
};

struct WINRT_EBO DeviceUseDetails :
    Windows::Devices::Background::IDeviceUseDetails
{
    DeviceUseDetails(std::nullptr_t) noexcept {}
};

}

}