// C++ for the Windows Runtime v1.0.private
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "internal/Windows.UI.Xaml.Resources.3.h"
#include "Windows.UI.Xaml.h"
#include "internal/Windows.UI.Xaml.Resources.4.h"
#include "internal/Windows.UI.Xaml.Resources.5.h"

WINRT_EXPORT namespace winrt {

namespace impl {

template <typename D>
struct produce<D, Windows::UI::Xaml::Resources::ICustomXamlResourceLoader> : produce_base<D, Windows::UI::Xaml::Resources::ICustomXamlResourceLoader>
{};

template <typename D>
struct produce<D, Windows::UI::Xaml::Resources::ICustomXamlResourceLoaderFactory> : produce_base<D, Windows::UI::Xaml::Resources::ICustomXamlResourceLoaderFactory>
{
    HRESULT __stdcall abi_CreateInstance(abi_arg_in<Windows::IInspectable> outer, abi_arg_out<Windows::IInspectable> inner, abi_arg_out<Windows::UI::Xaml::Resources::ICustomXamlResourceLoader> instance) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *instance = detach(this->shim().CreateInstance(*reinterpret_cast<const Windows::IInspectable *>(&outer), *inner));
            return S_OK;
        }
        catch (...)
        {
            *inner = nullptr;
            *instance = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Xaml::Resources::ICustomXamlResourceLoaderOverrides> : produce_base<D, Windows::UI::Xaml::Resources::ICustomXamlResourceLoaderOverrides>
{
    HRESULT __stdcall abi_GetResource(abi_arg_in<hstring> resourceId, abi_arg_in<hstring> objectType, abi_arg_in<hstring> propertyName, abi_arg_in<hstring> propertyType, abi_arg_out<Windows::IInspectable> returnValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *returnValue = detach(this->shim().GetResource(*reinterpret_cast<const hstring *>(&resourceId), *reinterpret_cast<const hstring *>(&objectType), *reinterpret_cast<const hstring *>(&propertyName), *reinterpret_cast<const hstring *>(&propertyType)));
            return S_OK;
        }
        catch (...)
        {
            *returnValue = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Xaml::Resources::ICustomXamlResourceLoaderStatics> : produce_base<D, Windows::UI::Xaml::Resources::ICustomXamlResourceLoaderStatics>
{
    HRESULT __stdcall get_Current(abi_arg_out<Windows::UI::Xaml::Resources::ICustomXamlResourceLoader> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach(this->shim().Current());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Current(abi_arg_in<Windows::UI::Xaml::Resources::ICustomXamlResourceLoader> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Current(*reinterpret_cast<const Windows::UI::Xaml::Resources::CustomXamlResourceLoader *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

}

namespace Windows::UI::Xaml::Resources {

template <typename D> Windows::IInspectable impl_ICustomXamlResourceLoaderOverrides<D>::GetResource(hstring_view resourceId, hstring_view objectType, hstring_view propertyName, hstring_view propertyType) const
{
    Windows::IInspectable returnValue;
    check_hresult(WINRT_SHIM(ICustomXamlResourceLoaderOverrides)->abi_GetResource(get(resourceId), get(objectType), get(propertyName), get(propertyType), put(returnValue)));
    return returnValue;
}

template <typename D> Windows::UI::Xaml::Resources::CustomXamlResourceLoader impl_ICustomXamlResourceLoaderStatics<D>::Current() const
{
    Windows::UI::Xaml::Resources::CustomXamlResourceLoader value { nullptr };
    check_hresult(WINRT_SHIM(ICustomXamlResourceLoaderStatics)->get_Current(put(value)));
    return value;
}

template <typename D> void impl_ICustomXamlResourceLoaderStatics<D>::Current(const Windows::UI::Xaml::Resources::CustomXamlResourceLoader & value) const
{
    check_hresult(WINRT_SHIM(ICustomXamlResourceLoaderStatics)->put_Current(get(value)));
}

template <typename D> Windows::UI::Xaml::Resources::CustomXamlResourceLoader impl_ICustomXamlResourceLoaderFactory<D>::CreateInstance(const Windows::IInspectable & outer, Windows::IInspectable & inner) const
{
    Windows::UI::Xaml::Resources::CustomXamlResourceLoader instance { nullptr };
    check_hresult(WINRT_SHIM(ICustomXamlResourceLoaderFactory)->abi_CreateInstance(get(outer), put(inner), put(instance)));
    return instance;
}

inline CustomXamlResourceLoader::CustomXamlResourceLoader()
{
    Windows::IInspectable outer, inner;
    impl_move(get_activation_factory<CustomXamlResourceLoader, ICustomXamlResourceLoaderFactory>().CreateInstance(outer, inner));
}

inline Windows::UI::Xaml::Resources::CustomXamlResourceLoader CustomXamlResourceLoader::Current()
{
    return get_activation_factory<CustomXamlResourceLoader, ICustomXamlResourceLoaderStatics>().Current();
}

inline void CustomXamlResourceLoader::Current(const Windows::UI::Xaml::Resources::CustomXamlResourceLoader & value)
{
    get_activation_factory<CustomXamlResourceLoader, ICustomXamlResourceLoaderStatics>().Current(value);
}

}

}
