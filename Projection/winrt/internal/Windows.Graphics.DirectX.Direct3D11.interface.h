// C++ for the Windows Runtime v1.29
// Copyright (c) 2016 Microsoft Corporation

#pragma once

#include "Windows.Graphics.DirectX.Direct3D11.abi.h"
#include "Windows.Graphics.DirectX.abi.h"

WINRT_EXPORT namespace winrt {

namespace Windows::Graphics::DirectX::Direct3D11 {

template <typename D>
class WINRT_EBO impl_IDirect3DDevice
{
    auto shim() const { return impl::shim<D, IDirect3DDevice>(this); }

public:

    void Trim() const;
};

template <typename D>
class WINRT_EBO impl_IDirect3DSurface
{
    auto shim() const { return impl::shim<D, IDirect3DSurface>(this); }

public:

    Windows::Graphics::DirectX::Direct3D11::Direct3DSurfaceDescription Description() const;
};

struct IDirect3DDevice :
    Windows::IInspectable,
    impl::consume<IDirect3DDevice>
{
    IDirect3DDevice(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IDirect3DDevice>(m_ptr); }
};

struct IDirect3DSurface :
    Windows::IInspectable,
    impl::consume<IDirect3DSurface>
{
    IDirect3DSurface(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IDirect3DSurface>(m_ptr); }
};

}

}
