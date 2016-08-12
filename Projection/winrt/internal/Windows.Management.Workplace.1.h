// C++ for the Windows Runtime v1.29
// Copyright (c) 2016 Microsoft Corporation

#pragma once

#include "../base.h"
#include "Windows.Management.Workplace.0.h"

WINRT_EXPORT namespace winrt {

namespace ABI::Windows::Management::Workplace {

struct __declspec(uuid("c39709e7-741c-41f2-a4b6-314c31502586")) __declspec(novtable) IMdmAllowPolicyStatics : Windows::IInspectable
{
    virtual HRESULT __stdcall abi_IsBrowserAllowed(bool * value) = 0;
    virtual HRESULT __stdcall abi_IsCameraAllowed(bool * value) = 0;
    virtual HRESULT __stdcall abi_IsMicrosoftAccountAllowed(bool * value) = 0;
    virtual HRESULT __stdcall abi_IsStoreAllowed(bool * value) = 0;
};

struct __declspec(uuid("c99c7526-03d4-49f9-a993-43efccd265c4")) __declspec(novtable) IMdmPolicyStatics2 : Windows::IInspectable
{
    virtual HRESULT __stdcall abi_GetMessagingSyncPolicy(winrt::Windows::Management::Workplace::MessagingSyncPolicy * value) = 0;
};

}

namespace ABI {


}

namespace Windows::Management::Workplace {

template <typename T> class impl_IMdmAllowPolicyStatics;
template <typename T> class impl_IMdmPolicyStatics2;

}

namespace impl {

template <> struct traits<Windows::Management::Workplace::IMdmAllowPolicyStatics>
{
    using abi = ABI::Windows::Management::Workplace::IMdmAllowPolicyStatics;
    template <typename D> using consume = Windows::Management::Workplace::impl_IMdmAllowPolicyStatics<D>;
};

template <> struct traits<Windows::Management::Workplace::IMdmPolicyStatics2>
{
    using abi = ABI::Windows::Management::Workplace::IMdmPolicyStatics2;
    template <typename D> using consume = Windows::Management::Workplace::impl_IMdmPolicyStatics2<D>;
};

template <> struct traits<Windows::Management::Workplace::MdmPolicy>
{
    static constexpr const wchar_t * name() noexcept { return L"Windows.Management.Workplace.MdmPolicy"; }
};

}

}
