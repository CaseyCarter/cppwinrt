// C++ for the Windows Runtime v1.0.private
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "internal/Windows.System.Display.3.h"
#include "Windows.System.h"

WINRT_EXPORT namespace winrt {

namespace impl {

template <typename D>
struct produce<D, Windows::System::Display::IDisplayRequest> : produce_base<D, Windows::System::Display::IDisplayRequest>
{
    HRESULT __stdcall abi_RequestActive() noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().RequestActive();
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_RequestRelease() noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().RequestRelease();
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

}

namespace Windows::System::Display {

template <typename D> void impl_IDisplayRequest<D>::RequestActive() const
{
    check_hresult(static_cast<const IDisplayRequest &>(static_cast<const D &>(*this))->abi_RequestActive());
}

template <typename D> void impl_IDisplayRequest<D>::RequestRelease() const
{
    check_hresult(static_cast<const IDisplayRequest &>(static_cast<const D &>(*this))->abi_RequestRelease());
}

inline DisplayRequest::DisplayRequest() :
    DisplayRequest(activate_instance<DisplayRequest>())
{}

}

}
