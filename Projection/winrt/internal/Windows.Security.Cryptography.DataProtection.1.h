// C++ for the Windows Runtime v1.29
// Copyright (c) 2016 Microsoft Corporation

#pragma once

#include "..\base.h"
#include "Windows.Security.Cryptography.DataProtection.0.h"
#include "Windows.Foundation.0.h"
#include "Windows.Storage.Streams.0.h"
#include "Windows.Storage.Streams.1.h"
#include "Windows.Foundation.1.h"

WINRT_EXPORT namespace winrt {

namespace ABI::Windows::Security::Cryptography::DataProtection {

struct __declspec(uuid("09639948-ed22-4270-bd1c-6d72c00f8787")) __declspec(novtable) IDataProtectionProvider : Windows::IInspectable
{
    virtual HRESULT __stdcall abi_ProtectAsync(Windows::Storage::Streams::IBuffer * data, Windows::Foundation::IAsyncOperation<Windows::Storage::Streams::IBuffer> ** value) = 0;
    virtual HRESULT __stdcall abi_UnprotectAsync(Windows::Storage::Streams::IBuffer * data, Windows::Foundation::IAsyncOperation<Windows::Storage::Streams::IBuffer> ** value) = 0;
    virtual HRESULT __stdcall abi_ProtectStreamAsync(Windows::Storage::Streams::IInputStream * src, Windows::Storage::Streams::IOutputStream * dest, Windows::Foundation::IAsyncAction ** value) = 0;
    virtual HRESULT __stdcall abi_UnprotectStreamAsync(Windows::Storage::Streams::IInputStream * src, Windows::Storage::Streams::IOutputStream * dest, Windows::Foundation::IAsyncAction ** value) = 0;
};

struct __declspec(uuid("adf33dac-4932-4cdf-ac41-7214333514ca")) __declspec(novtable) IDataProtectionProviderFactory : Windows::IInspectable
{
    virtual HRESULT __stdcall abi_CreateOverloadExplicit(hstring protectionDescriptor, Windows::Security::Cryptography::DataProtection::IDataProtectionProvider ** value) = 0;
};

}

namespace ABI {

template <> struct traits<Windows::Security::Cryptography::DataProtection::DataProtectionProvider> { using default_interface = Windows::Security::Cryptography::DataProtection::IDataProtectionProvider; };

}

namespace Windows::Security::Cryptography::DataProtection {

template <typename T> class impl_IDataProtectionProvider;
template <typename T> class impl_IDataProtectionProviderFactory;

}

namespace impl {

template <> struct traits<Windows::Security::Cryptography::DataProtection::IDataProtectionProvider>
{
    using abi = ABI::Windows::Security::Cryptography::DataProtection::IDataProtectionProvider;
    template <typename D> using consume = Windows::Security::Cryptography::DataProtection::impl_IDataProtectionProvider<D>;
};

template <> struct traits<Windows::Security::Cryptography::DataProtection::IDataProtectionProviderFactory>
{
    using abi = ABI::Windows::Security::Cryptography::DataProtection::IDataProtectionProviderFactory;
    template <typename D> using consume = Windows::Security::Cryptography::DataProtection::impl_IDataProtectionProviderFactory<D>;
};

template <> struct traits<Windows::Security::Cryptography::DataProtection::DataProtectionProvider>
{
    using abi = ABI::Windows::Security::Cryptography::DataProtection::DataProtectionProvider;
    using default_interface = Windows::Security::Cryptography::DataProtection::IDataProtectionProvider;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Security.Cryptography.DataProtection.DataProtectionProvider"; }
};

}

}