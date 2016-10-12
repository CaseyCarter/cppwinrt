// C++ for the Windows Runtime v1.0.private
// Copyright (c) 2016 Microsoft Corporation. All rights reserved.

#pragma once

#include "Windows.Security.ExchangeActiveSyncProvisioning.2.h"

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
