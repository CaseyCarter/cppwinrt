// C++ for the Windows Runtime v1.0.private
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once
#pragma warning(push)
#pragma warning(disable: 4996)

#include "internal/Windows.Security.ExchangeActiveSyncProvisioning.3.h"

WINRT_EXPORT namespace winrt {

namespace impl {

template <typename D>
struct produce<D, Windows::Security::ExchangeActiveSyncProvisioning::IEasClientDeviceInformation> : produce_base<D, Windows::Security::ExchangeActiveSyncProvisioning::IEasClientDeviceInformation>
{
    HRESULT __stdcall get_Id(GUID * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Id());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_OperatingSystem(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().OperatingSystem());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_FriendlyName(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().FriendlyName());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_SystemManufacturer(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().SystemManufacturer());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_SystemProductName(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().SystemProductName());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_SystemSku(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().SystemSku());
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
    HRESULT __stdcall get_SystemHardwareVersion(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().SystemHardwareVersion());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_SystemFirmwareVersion(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().SystemFirmwareVersion());
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
    check_hresult(WINRT_SHIM(IEasClientDeviceInformation)->get_Id(&value));
    return value;
}

template <typename D> hstring impl_IEasClientDeviceInformation<D>::OperatingSystem() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IEasClientDeviceInformation)->get_OperatingSystem(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IEasClientDeviceInformation<D>::FriendlyName() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IEasClientDeviceInformation)->get_FriendlyName(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IEasClientDeviceInformation<D>::SystemManufacturer() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IEasClientDeviceInformation)->get_SystemManufacturer(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IEasClientDeviceInformation<D>::SystemProductName() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IEasClientDeviceInformation)->get_SystemProductName(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IEasClientDeviceInformation<D>::SystemSku() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IEasClientDeviceInformation)->get_SystemSku(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IEasClientDeviceInformation2<D>::SystemHardwareVersion() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IEasClientDeviceInformation2)->get_SystemHardwareVersion(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IEasClientDeviceInformation2<D>::SystemFirmwareVersion() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IEasClientDeviceInformation2)->get_SystemFirmwareVersion(put_abi(value)));
    return value;
}

inline EasClientDeviceInformation::EasClientDeviceInformation() :
    EasClientDeviceInformation(activate_instance<EasClientDeviceInformation>())
{}

}

}
#pragma warning(pop)
