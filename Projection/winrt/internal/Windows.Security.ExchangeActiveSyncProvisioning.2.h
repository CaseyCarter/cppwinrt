// C++ for the Windows Runtime v1.29
// Copyright (c) 2016 Microsoft Corporation

#pragma once

#include "Windows.Security.ExchangeActiveSyncProvisioning.1.h"

WINRT_EXPORT namespace winrt {

namespace Windows::Security::ExchangeActiveSyncProvisioning {

template <typename D>
class WINRT_EBO impl_IEasClientDeviceInformation
{
    auto shim() const { return impl::shim<D, IEasClientDeviceInformation>(this); }

public:

    GUID Id() const;
    hstring OperatingSystem() const;
    hstring FriendlyName() const;
    hstring SystemManufacturer() const;
    hstring SystemProductName() const;
    hstring SystemSku() const;
};

template <typename D>
class WINRT_EBO impl_IEasClientDeviceInformation2
{
    auto shim() const { return impl::shim<D, IEasClientDeviceInformation2>(this); }

public:

    hstring SystemHardwareVersion() const;
    hstring SystemFirmwareVersion() const;
};

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
