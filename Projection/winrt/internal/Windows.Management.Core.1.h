// C++ for the Windows Runtime v1.29
// Copyright (c) 2016 Microsoft Corporation

#pragma once

#include "..\base.h"
#include "Windows.Management.Core.0.h"
#include "Windows.Storage.0.h"

WINRT_EXPORT namespace winrt {

namespace ABI::Windows::Management::Core {

struct __declspec(uuid("74d10432-2e99-4000-9a3a-64307e858129")) __declspec(novtable) IApplicationDataManager : Windows::IInspectable
{
};

struct __declspec(uuid("1e1862e3-698e-49a1-9752-dee94925b9b3")) __declspec(novtable) IApplicationDataManagerStatics : Windows::IInspectable
{
    virtual HRESULT __stdcall abi_CreateForPackageFamily(hstring packageFamilyName, Windows::Storage::IApplicationData ** applicationData) = 0;
};

}

namespace ABI {

template <> struct traits<Windows::Management::Core::ApplicationDataManager> { using default_interface = Windows::Management::Core::IApplicationDataManager; };

}

namespace Windows::Management::Core {

template <typename T> class impl_IApplicationDataManager;
template <typename T> class impl_IApplicationDataManagerStatics;

}

namespace impl {

template <> struct traits<Windows::Management::Core::IApplicationDataManager>
{
    using abi = ABI::Windows::Management::Core::IApplicationDataManager;
    template <typename D> using consume = Windows::Management::Core::impl_IApplicationDataManager<D>;
};

template <> struct traits<Windows::Management::Core::IApplicationDataManagerStatics>
{
    using abi = ABI::Windows::Management::Core::IApplicationDataManagerStatics;
    template <typename D> using consume = Windows::Management::Core::impl_IApplicationDataManagerStatics<D>;
};

template <> struct traits<Windows::Management::Core::ApplicationDataManager>
{
    using abi = ABI::Windows::Management::Core::ApplicationDataManager;
    using default_interface = Windows::Management::Core::IApplicationDataManager;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Management.Core.ApplicationDataManager"; }
};

}

}