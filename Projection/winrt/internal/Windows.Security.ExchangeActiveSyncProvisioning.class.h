// C++ for the Windows Runtime v1.29
// Copyright (c) 2016 Microsoft Corporation

#pragma once

#include "Windows.Security.ExchangeActiveSyncProvisioning.interface.h"

WINRT_EXPORT namespace winrt {

namespace Windows::Security::ExchangeActiveSyncProvisioning {

struct WINRT_EBO EasClientDeviceInformation :
    Windows::Security::ExchangeActiveSyncProvisioning::IEasClientDeviceInformation,
    impl::require<EasClientDeviceInformation, Windows::Security::ExchangeActiveSyncProvisioning::IEasClientDeviceInformation2>
{
    EasClientDeviceInformation(std::nullptr_t) noexcept {}
    EasClientDeviceInformation();
};

}

}
