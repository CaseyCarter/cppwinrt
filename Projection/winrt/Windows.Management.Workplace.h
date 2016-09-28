// C++ for the Windows Runtime v1.29
// Copyright (c) 2016 Microsoft Corporation

#pragma once

#include "internal/Windows.Management.Workplace.3.h"

WINRT_EXPORT namespace winrt {

namespace impl {

template <typename D>
struct produce<D, Windows::Management::Workplace::IMdmAllowPolicyStatics> : produce_base<D, Windows::Management::Workplace::IMdmAllowPolicyStatics>
{
    HRESULT __stdcall abi_IsBrowserAllowed(bool * value) noexcept override
    {
        try
        {
            *value = detach(this->shim().IsBrowserAllowed());
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
            *value = detach(this->shim().IsCameraAllowed());
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
            *value = detach(this->shim().IsMicrosoftAccountAllowed());
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
            *value = detach(this->shim().IsStoreAllowed());
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
            *value = detach(this->shim().GetMessagingSyncPolicy());
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
    check_hresult(static_cast<const IMdmAllowPolicyStatics &>(static_cast<const D &>(*this))->abi_IsBrowserAllowed(&value));
    return value;
}

template <typename D> bool impl_IMdmAllowPolicyStatics<D>::IsCameraAllowed() const
{
    bool value {};
    check_hresult(static_cast<const IMdmAllowPolicyStatics &>(static_cast<const D &>(*this))->abi_IsCameraAllowed(&value));
    return value;
}

template <typename D> bool impl_IMdmAllowPolicyStatics<D>::IsMicrosoftAccountAllowed() const
{
    bool value {};
    check_hresult(static_cast<const IMdmAllowPolicyStatics &>(static_cast<const D &>(*this))->abi_IsMicrosoftAccountAllowed(&value));
    return value;
}

template <typename D> bool impl_IMdmAllowPolicyStatics<D>::IsStoreAllowed() const
{
    bool value {};
    check_hresult(static_cast<const IMdmAllowPolicyStatics &>(static_cast<const D &>(*this))->abi_IsStoreAllowed(&value));
    return value;
}

template <typename D> Windows::Management::Workplace::MessagingSyncPolicy impl_IMdmPolicyStatics2<D>::GetMessagingSyncPolicy() const
{
    Windows::Management::Workplace::MessagingSyncPolicy value {};
    check_hresult(static_cast<const IMdmPolicyStatics2 &>(static_cast<const D &>(*this))->abi_GetMessagingSyncPolicy(&value));
    return value;
}

inline bool MdmPolicy::IsBrowserAllowed()
{
    return get_activation_factory<MdmPolicy, IMdmAllowPolicyStatics>().IsBrowserAllowed();
}

inline bool MdmPolicy::IsCameraAllowed()
{
    return get_activation_factory<MdmPolicy, IMdmAllowPolicyStatics>().IsCameraAllowed();
}

inline bool MdmPolicy::IsMicrosoftAccountAllowed()
{
    return get_activation_factory<MdmPolicy, IMdmAllowPolicyStatics>().IsMicrosoftAccountAllowed();
}

inline bool MdmPolicy::IsStoreAllowed()
{
    return get_activation_factory<MdmPolicy, IMdmAllowPolicyStatics>().IsStoreAllowed();
}

inline Windows::Management::Workplace::MessagingSyncPolicy MdmPolicy::GetMessagingSyncPolicy()
{
    return get_activation_factory<MdmPolicy, IMdmPolicyStatics2>().GetMessagingSyncPolicy();
}

}

}
