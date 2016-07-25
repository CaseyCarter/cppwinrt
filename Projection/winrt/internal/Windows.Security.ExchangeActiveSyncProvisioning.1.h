// C++ for the Windows Runtime v1.29
// Copyright (c) 2016 Microsoft Corporation

#pragma once

#include "..\base.h"
#include "Windows.Security.ExchangeActiveSyncProvisioning.0.h"

WINRT_EXPORT namespace winrt {

namespace ABI::Windows::Security::ExchangeActiveSyncProvisioning {

struct __declspec(uuid("54dfd981-1968-4ca3-b958-e595d16505eb")) __declspec(novtable) IEasClientDeviceInformation : Windows::IInspectable
{
    virtual HRESULT __stdcall get_Id(GUID * value) = 0;
    virtual HRESULT __stdcall get_OperatingSystem(hstring * value) = 0;
    virtual HRESULT __stdcall get_FriendlyName(hstring * value) = 0;
    virtual HRESULT __stdcall get_SystemManufacturer(hstring * value) = 0;
    virtual HRESULT __stdcall get_SystemProductName(hstring * value) = 0;
    virtual HRESULT __stdcall get_SystemSku(hstring * value) = 0;
};

struct __declspec(uuid("ffb35923-bb26-4d6a-81bc-165aee0ad754")) __declspec(novtable) IEasClientDeviceInformation2 : Windows::IInspectable
{
    virtual HRESULT __stdcall get_SystemHardwareVersion(hstring * value) = 0;
    virtual HRESULT __stdcall get_SystemFirmwareVersion(hstring * value) = 0;
};

}

namespace ABI {

template <> struct traits<Windows::Security::ExchangeActiveSyncProvisioning::EasClientDeviceInformation> { using default_interface = Windows::Security::ExchangeActiveSyncProvisioning::IEasClientDeviceInformation; };

}

namespace Windows::Security::ExchangeActiveSyncProvisioning {

template <typename T> class impl_IEasClientDeviceInformation;
template <typename T> class impl_IEasClientDeviceInformation2;

}

namespace impl {

template <> struct traits<Windows::Security::ExchangeActiveSyncProvisioning::IEasClientDeviceInformation>
{
    using abi = ABI::Windows::Security::ExchangeActiveSyncProvisioning::IEasClientDeviceInformation;
    template <typename D> using consume = Windows::Security::ExchangeActiveSyncProvisioning::impl_IEasClientDeviceInformation<D>;
};

template <> struct traits<Windows::Security::ExchangeActiveSyncProvisioning::IEasClientDeviceInformation2>
{
    using abi = ABI::Windows::Security::ExchangeActiveSyncProvisioning::IEasClientDeviceInformation2;
    template <typename D> using consume = Windows::Security::ExchangeActiveSyncProvisioning::impl_IEasClientDeviceInformation2<D>;
};

template <> struct traits<Windows::Security::ExchangeActiveSyncProvisioning::EasClientDeviceInformation>
{
    using abi = ABI::Windows::Security::ExchangeActiveSyncProvisioning::EasClientDeviceInformation;
    using default_interface = Windows::Security::ExchangeActiveSyncProvisioning::IEasClientDeviceInformation;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Security.ExchangeActiveSyncProvisioning.EasClientDeviceInformation"; }
};

}

}
