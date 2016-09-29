// C++ for the Windows Runtime v1.0.private
// Copyright (c) 2016 Microsoft Corporation

#pragma once


WINRT_EXPORT namespace winrt {

namespace Windows::UI::Xaml::Media {

template <typename D, typename A = ABI::Windows::UI::Xaml::Media::IGeneralTransformOverrides>
class IGeneralTransformOverridesT : public A
{
    D & shim() noexcept { return *static_cast<D *>(this); }

public:

    using IGeneralTransformOverrides = winrt::Windows::UI::Xaml::Media::IGeneralTransformOverrides;

    Windows::UI::Xaml::Media::GeneralTransform InverseCore()
    {
        return shim().as<IGeneralTransformOverrides>().InverseCore();
    }

    bool TryTransformCore(const Windows::Foundation::Point & inPoint, Windows::Foundation::Point & outPoint)
    {
        return shim().as<IGeneralTransformOverrides>().TryTransformCore(inPoint, outPoint);
    }

    Windows::Foundation::Rect TransformBoundsCore(const Windows::Foundation::Rect & rect)
    {
        return shim().as<IGeneralTransformOverrides>().TransformBoundsCore(rect);
    }

    HRESULT __stdcall get_InverseCore(abi_arg_out<Windows::UI::Xaml::Media::IGeneralTransform> value) noexcept override
    {
        try
        {
            *value = detach(this->shim().InverseCore());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_TryTransformCore(abi_arg_in<Windows::Foundation::Point> inPoint, abi_arg_out<Windows::Foundation::Point> outPoint, bool * returnValue) noexcept override
    {
        try
        {
            *returnValue = detach(this->shim().TryTransformCore(*reinterpret_cast<const Windows::Foundation::Point *>(&inPoint), *outPoint));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_TransformBoundsCore(abi_arg_in<Windows::Foundation::Rect> rect, abi_arg_out<Windows::Foundation::Rect> returnValue) noexcept override
    {
        try
        {
            *returnValue = detach(this->shim().TransformBoundsCore(*reinterpret_cast<const Windows::Foundation::Rect *>(&rect)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

}

}
