// C++ for the Windows Runtime v1.29
// Copyright (c) 2016 Microsoft Corporation

#pragma once

#include "../base.h"
#include "Windows.Storage.Compression.0.h"
#include "Windows.Foundation.0.h"
#include "Windows.Storage.Streams.0.h"
#include "Windows.Foundation.1.h"

WINRT_EXPORT namespace winrt {

namespace ABI::Windows::Storage::Compression {

struct __declspec(uuid("0ac3645a-57ac-4ee1-b702-84d39d5424e0")) __declspec(novtable) ICompressor : Windows::IInspectable
{
    virtual HRESULT __stdcall abi_FinishAsync(Windows::Foundation::IAsyncOperation<bool> ** operation) = 0;
    virtual HRESULT __stdcall abi_DetachStream(Windows::Storage::Streams::IOutputStream ** stream) = 0;
};

struct __declspec(uuid("5f3d96a4-2cfb-442c-a8ba-d7d11b039da0")) __declspec(novtable) ICompressorFactory : Windows::IInspectable
{
    virtual HRESULT __stdcall abi_CreateCompressor(Windows::Storage::Streams::IOutputStream * underlyingStream, Windows::Storage::Compression::ICompressor ** createdCompressor) = 0;
    virtual HRESULT __stdcall abi_CreateCompressorEx(Windows::Storage::Streams::IOutputStream * underlyingStream, winrt::Windows::Storage::Compression::CompressAlgorithm algorithm, uint32_t blockSize, Windows::Storage::Compression::ICompressor ** createdCompressor) = 0;
};

struct __declspec(uuid("b883fe46-d68a-4c8b-ada0-4ee813fc5283")) __declspec(novtable) IDecompressor : Windows::IInspectable
{
    virtual HRESULT __stdcall abi_DetachStream(Windows::Storage::Streams::IInputStream ** stream) = 0;
};

struct __declspec(uuid("5337e252-1da2-42e1-8834-0379d28d742f")) __declspec(novtable) IDecompressorFactory : Windows::IInspectable
{
    virtual HRESULT __stdcall abi_CreateDecompressor(Windows::Storage::Streams::IInputStream * underlyingStream, Windows::Storage::Compression::IDecompressor ** createdDecompressor) = 0;
};

}

namespace ABI {

template <> struct traits<Windows::Storage::Compression::Compressor> { using default_interface = Windows::Storage::Compression::ICompressor; };
template <> struct traits<Windows::Storage::Compression::Decompressor> { using default_interface = Windows::Storage::Compression::IDecompressor; };

}

namespace Windows::Storage::Compression {

template <typename T> class impl_ICompressor;
template <typename T> class impl_ICompressorFactory;
template <typename T> class impl_IDecompressor;
template <typename T> class impl_IDecompressorFactory;

}

namespace impl {

template <> struct traits<Windows::Storage::Compression::ICompressor>
{
    using abi = ABI::Windows::Storage::Compression::ICompressor;
    template <typename D> using consume = Windows::Storage::Compression::impl_ICompressor<D>;
};

template <> struct traits<Windows::Storage::Compression::ICompressorFactory>
{
    using abi = ABI::Windows::Storage::Compression::ICompressorFactory;
    template <typename D> using consume = Windows::Storage::Compression::impl_ICompressorFactory<D>;
};

template <> struct traits<Windows::Storage::Compression::IDecompressor>
{
    using abi = ABI::Windows::Storage::Compression::IDecompressor;
    template <typename D> using consume = Windows::Storage::Compression::impl_IDecompressor<D>;
};

template <> struct traits<Windows::Storage::Compression::IDecompressorFactory>
{
    using abi = ABI::Windows::Storage::Compression::IDecompressorFactory;
    template <typename D> using consume = Windows::Storage::Compression::impl_IDecompressorFactory<D>;
};

template <> struct traits<Windows::Storage::Compression::Compressor>
{
    using abi = ABI::Windows::Storage::Compression::Compressor;
    using default_interface = Windows::Storage::Compression::ICompressor;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Storage.Compression.Compressor"; }
};

template <> struct traits<Windows::Storage::Compression::Decompressor>
{
    using abi = ABI::Windows::Storage::Compression::Decompressor;
    using default_interface = Windows::Storage::Compression::IDecompressor;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Storage.Compression.Decompressor"; }
};

}

}
