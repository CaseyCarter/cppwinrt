// C++ for the Windows Runtime v1.29
// Copyright (c) 2016 Microsoft Corporation

#pragma once

#include "internal\Windows.Management.Workplace.class.h"

WINRT_EXPORT namespace winrt {

namespace impl {

template <typename D>
struct produce<D, Windows::Management::Workplace::IMdmAllowPolicyStatics> : produce_base<D, Windows::Management::Workplace::IMdmAllowPolicyStatics>
{
    HRESULT __stdcall abi_IsBrowserAllowed(bool * value) noexcept override
    {
        try
        {
            *value = detach(shim().IsBrowserAllowed());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_IsCameraAllowed(bool * value) noexcept override
    {
        try
        {
            *value = detach(shim().IsCameraAllowed());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_IsMicrosoftAccountAllowed(bool * value) noexcept override
    {
        try
        {
            *value = detach(shim().IsMicrosoftAccountAllowed());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_IsStoreAllowed(bool * value) noexcept override
    {
        try
        {
            *value = detach(shim().IsStoreAllowed());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Management::Workplace::IMdmPolicyStatics2> : produce_base<D, Windows::Management::Workplace::IMdmPolicyStatics2>
{
    HRESULT __stdcall abi_GetMessagingSyncPolicy(Windows::Management::Workplace::MessagingSyncPolicy * value) noexcept override
    {
        try
        {
            *value = detach(shim().GetMessagingSyncPolicy());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

}

namespace Windows::Management::Workplace {

template <typename D> bool impl_IMdmAllowPolicyStatics<D>::IsBrowserAllowed() const
{
    bool value {};
    check_hresult(shim()->abi_IsBrowserAllowed(&value));
    return value;
}

template <typename D> bool impl_IMdmAllowPolicyStatics<D>::IsCameraAllowed() const
{
    bool value {};
    check_hresult(shim()->abi_IsCameraAllowed(&value));
    return value;
}

template <typename D> bool impl_IMdmAllowPolicyStatics<D>::IsMicrosoftAccountAllowed() const
{
    bool value {};
    check_hresult(shim()->abi_IsMicrosoftAccountAllowed(&value));
    return value;
}

template <typename D> bool impl_IMdmAllowPolicyStatics<D>::IsStoreAllowed() const
{
    bool value {};
    check_hresult(shim()->abi_IsStoreAllowed(&value));
    return value;
}

template <typename D> Windows::Management::Workplace::MessagingSyncPolicy impl_IMdmPolicyStatics2<D>::GetMessagingSyncPolicy() const
{
    Windows::Management::Workplace::MessagingSyncPolicy value {};
    check_hresult(shim()->abi_GetMessagingSyncPolicy(&value));
    return value;
}

inline bool MdmPolicy::IsBrowserAllowed()
{
    return GetActivationFactory<MdmPolicy, IMdmAllowPolicyStatics>().IsBrowserAllowed();
}

inline bool MdmPolicy::IsCameraAllowed()
{
    return GetActivationFactory<MdmPolicy, IMdmAllowPolicyStatics>().IsCameraAllowed();
}

inline bool MdmPolicy::IsMicrosoftAccountAllowed()
{
    return GetActivationFactory<MdmPolicy, IMdmAllowPolicyStatics>().IsMicrosoftAccountAllowed();
}

inline bool MdmPolicy::IsStoreAllowed()
{
    return GetActivationFactory<MdmPolicy, IMdmAllowPolicyStatics>().IsStoreAllowed();
}

inline Windows::Management::Workplace::MessagingSyncPolicy MdmPolicy::GetMessagingSyncPolicy()
{
    return GetActivationFactory<MdmPolicy, IMdmPolicyStatics2>().GetMessagingSyncPolicy();
}

}

}
