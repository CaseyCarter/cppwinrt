// C++ for the Windows Runtime v1.29
// Copyright (c) 2016 Microsoft Corporation

#pragma once

#include "internal\Windows.Security.ExchangeActiveSyncProvisioning.class.h"

WINRT_EXPORT namespace winrt {

namespace impl {

template <typename D>
struct produce<D, Windows::Security::ExchangeActiveSyncProvisioning::IEasClientDeviceInformation> : produce_base<D, Windows::Security::ExchangeActiveSyncProvisioning::IEasClientDeviceInformation>
{
    HRESULT __stdcall get_Id(GUID * value) noexcept override
    {
        try
        {
            *value = detach(shim().Id());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_OperatingSystem(abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            *value = detach(shim().OperatingSystem());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_FriendlyName(abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            *value = detach(shim().FriendlyName());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_SystemManufacturer(abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            *value = detach(shim().SystemManufacturer());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_SystemProductName(abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            *value = detach(shim().SystemProductName());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_SystemSku(abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            *value = detach(shim().SystemSku());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Security::ExchangeActiveSyncProvisioning::IEasClientDeviceInformation2> : produce_base<D, Windows::Security::ExchangeActiveSyncProvisioning::IEasClientDeviceInformation2>
{
    HRESULT __stdcall get_SystemHardwareVersion(abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            *value = detach(shim().SystemHardwareVersion());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_SystemFirmwareVersion(abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            *value = detach(shim().SystemFirmwareVersion());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }
};

}

namespace Windows::Security::ExchangeActiveSyncProvisioning {

template <typename D> GUID impl_IEasClientDeviceInformation<D>::Id() const
{
    GUID value {};
    check_hresult(shim()->get_Id(&value));
    return value;
}

template <typename D> hstring impl_IEasClientDeviceInformation<D>::OperatingSystem() const
{
    hstring value;
    check_hresult(shim()->get_OperatingSystem(put(value)));
    return value;
}

template <typename D> hstring impl_IEasClientDeviceInformation<D>::FriendlyName() const
{
    hstring value;
    check_hresult(shim()->get_FriendlyName(put(value)));
    return value;
}

template <typename D> hstring impl_IEasClientDeviceInformation<D>::SystemManufacturer() const
{
    hstring value;
    check_hresult(shim()->get_SystemManufacturer(put(value)));
    return value;
}

template <typename D> hstring impl_IEasClientDeviceInformation<D>::SystemProductName() const
{
    hstring value;
    check_hresult(shim()->get_SystemProductName(put(value)));
    return value;
}

template <typename D> hstring impl_IEasClientDeviceInformation<D>::SystemSku() const
{
    hstring value;
    check_hresult(shim()->get_SystemSku(put(value)));
    return value;
}

template <typename D> hstring impl_IEasClientDeviceInformation2<D>::SystemHardwareVersion() const
{
    hstring value;
    check_hresult(shim()->get_SystemHardwareVersion(put(value)));
    return value;
}

template <typename D> hstring impl_IEasClientDeviceInformation2<D>::SystemFirmwareVersion() const
{
    hstring value;
    check_hresult(shim()->get_SystemFirmwareVersion(put(value)));
    return value;
}

inline EasClientDeviceInformation::EasClientDeviceInformation() :
    EasClientDeviceInformation(ActivateInstance<EasClientDeviceInformation>())
{}

}

}
