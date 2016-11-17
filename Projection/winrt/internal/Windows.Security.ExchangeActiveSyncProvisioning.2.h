// C++ for the Windows Runtime v1.0.private
// Copyright (c) 2016 Microsoft Corporation. All rights reserved.

#pragma once

#include "Windows.Security.ExchangeActiveSyncProvisioning.1.h"

WINRT_EXPORT namespace winrt {

namespace Windows::Security::ExchangeActiveSyncProvisioning {

struct IEasClientDeviceInformation :
    Windows::IInspectable,
    impl::consume<IEasClientDeviceInformation>
{
    IEasClientDeviceInformation(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IEasClientDeviceInformation>(m_ptr); }
};

struct IEasClientDeviceInformation2 :
    Windows::IInspectable,
    impl::consume<IEasClientDeviceInformation2>,
    impl::require<IEasClientDeviceInformation2, Windows::Security::ExchangeActiveSyncProvisioning::IEasClientDeviceInformation>
{
    IEasClientDeviceInformation2(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IEasClientDeviceInformation2>(m_ptr); }
};

}

}
