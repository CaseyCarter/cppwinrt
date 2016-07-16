// C++ for the Windows Runtime v1.29
// Copyright (c) 2016 Microsoft Corporation

#pragma once

#include "internal\Windows.Foundation.class.h"
#include "internal\Windows.Storage.Streams.class.h"
#include "internal\Windows.Storage.Compression.class.h"
#include "Windows.Storage.h"
#include "Windows.Storage.Streams.h"

WINRT_EXPORT namespace winrt {

namespace impl {

template <typename D>
struct produce<D, Windows::Storage::Compression::ICompressor> : produce_base<D, Windows::Storage::Compression::ICompressor>
{
    HRESULT __stdcall abi_FinishAsync(abi_arg_out<Windows::Foundation::IAsyncOperation<bool>> operation) noexcept override
    {
        try
        {
            *operation = detach(shim().FinishAsync());
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_DetachStream(abi_arg_out<Windows::Storage::Streams::IOutputStream> stream) noexcept override
    {
        try
        {
            *stream = detach(shim().DetachStream());
            return S_OK;
        }
        catch (...)
        {
            *stream = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Storage::Compression::ICompressorFactory> : produce_base<D, Windows::Storage::Compression::ICompressorFactory>
{
    HRESULT __stdcall abi_CreateCompressor(abi_arg_in<Windows::Storage::Streams::IOutputStream> underlyingStream, abi_arg_out<Windows::Storage::Compression::ICompressor> createdCompressor) noexcept override
    {
        try
        {
            *createdCompressor = detach(shim().CreateCompressor(*reinterpret_cast<const Windows::Storage::Streams::IOutputStream *>(&underlyingStream)));
            return S_OK;
        }
        catch (...)
        {
            *createdCompressor = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_CreateCompressorEx(abi_arg_in<Windows::Storage::Streams::IOutputStream> underlyingStream, Windows::Storage::Compression::CompressAlgorithm algorithm, uint32_t blockSize, abi_arg_out<Windows::Storage::Compression::ICompressor> createdCompressor) noexcept override
    {
        try
        {
            *createdCompressor = detach(shim().CreateCompressorEx(*reinterpret_cast<const Windows::Storage::Streams::IOutputStream *>(&underlyingStream), algorithm, blockSize));
            return S_OK;
        }
        catch (...)
        {
            *createdCompressor = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Storage::Compression::IDecompressor> : produce_base<D, Windows::Storage::Compression::IDecompressor>
{
    HRESULT __stdcall abi_DetachStream(abi_arg_out<Windows::Storage::Streams::IInputStream> stream) noexcept override
    {
        try
        {
            *stream = detach(shim().DetachStream());
            return S_OK;
        }
        catch (...)
        {
            *stream = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Storage::Compression::IDecompressorFactory> : produce_base<D, Windows::Storage::Compression::IDecompressorFactory>
{
    HRESULT __stdcall abi_CreateDecompressor(abi_arg_in<Windows::Storage::Streams::IInputStream> underlyingStream, abi_arg_out<Windows::Storage::Compression::IDecompressor> createdDecompressor) noexcept override
    {
        try
        {
            *createdDecompressor = detach(shim().CreateDecompressor(*reinterpret_cast<const Windows::Storage::Streams::IInputStream *>(&underlyingStream)));
            return S_OK;
        }
        catch (...)
        {
            *createdDecompressor = nullptr;
            return impl::to_hresult();
        }
    }
};

}

namespace Windows::Storage::Compression {

template <typename D> Windows::Foundation::IAsyncOperation<bool> impl_ICompressor<D>::FinishAsync() const
{
    Windows::Foundation::IAsyncOperation<bool> operation;
    check_hresult(shim()->abi_FinishAsync(put(operation)));
    return operation;
}

template <typename D> Windows::Storage::Streams::IOutputStream impl_ICompressor<D>::DetachStream() const
{
    Windows::Storage::Streams::IOutputStream stream;
    check_hresult(shim()->abi_DetachStream(put(stream)));
    return stream;
}

template <typename D> Windows::Storage::Streams::IInputStream impl_IDecompressor<D>::DetachStream() const
{
    Windows::Storage::Streams::IInputStream stream;
    check_hresult(shim()->abi_DetachStream(put(stream)));
    return stream;
}

template <typename D> Windows::Storage::Compression::Compressor impl_ICompressorFactory<D>::CreateCompressor(const Windows::Storage::Streams::IOutputStream & underlyingStream) const
{
    Windows::Storage::Compression::Compressor createdCompressor { nullptr };
    check_hresult(shim()->abi_CreateCompressor(get(underlyingStream), put(createdCompressor)));
    return createdCompressor;
}

template <typename D> Windows::Storage::Compression::Compressor impl_ICompressorFactory<D>::CreateCompressorEx(const Windows::Storage::Streams::IOutputStream & underlyingStream, Windows::Storage::Compression::CompressAlgorithm algorithm, uint32_t blockSize) const
{
    Windows::Storage::Compression::Compressor createdCompressor { nullptr };
    check_hresult(shim()->abi_CreateCompressorEx(get(underlyingStream), algorithm, blockSize, put(createdCompressor)));
    return createdCompressor;
}

template <typename D> Windows::Storage::Compression::Decompressor impl_IDecompressorFactory<D>::CreateDecompressor(const Windows::Storage::Streams::IInputStream & underlyingStream) const
{
    Windows::Storage::Compression::Decompressor createdDecompressor { nullptr };
    check_hresult(shim()->abi_CreateDecompressor(get(underlyingStream), put(createdDecompressor)));
    return createdDecompressor;
}

inline Compressor::Compressor(const Windows::Storage::Streams::IOutputStream & underlyingStream) :
    Compressor(GetActivationFactory<Compressor, ICompressorFactory>().CreateCompressor(underlyingStream))
{}

inline Compressor::Compressor(const Windows::Storage::Streams::IOutputStream & underlyingStream, Windows::Storage::Compression::CompressAlgorithm algorithm, uint32_t blockSize) :
    Compressor(GetActivationFactory<Compressor, ICompressorFactory>().CreateCompressorEx(underlyingStream, algorithm, blockSize))
{}

inline Decompressor::Decompressor(const Windows::Storage::Streams::IInputStream & underlyingStream) :
    Decompressor(GetActivationFactory<Decompressor, IDecompressorFactory>().CreateDecompressor(underlyingStream))
{}

}

}
