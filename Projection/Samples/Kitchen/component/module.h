// WARNING: Please don't edit this file. It was generated by C++/WinRT v1.1.private

#pragma once

#include "Microsoft.SDKSamples.Kitchen.h"

namespace winrt {

namespace impl {

struct module_lock
{
    module_lock();
    ~module_lock();
};

}

namespace Microsoft::SDKSamples::Kitchen::implementation {

template <typename D, typename ... I>
struct BreadT
    : impl::module_lock, implements<D, Microsoft::SDKSamples::Kitchen::IBread, I ...>
{
    hstring GetRuntimeClassName() const
    {
        return L"Microsoft.SDKSamples.Kitchen.Bread";
    }
};

template <typename D, typename T, typename ... I>
struct BreadFactoryT : impl::module_lock, implements<D, Windows::Foundation::IActivationFactory, I ...>
{
    hstring GetRuntimeClassName() const
    {
        return L"Microsoft.SDKSamples.Kitchen.Bread";
    }

    Windows::Foundation::IInspectable ActivateInstance() const
    {
        throw hresult_not_implemented();
    }
};

template <typename D, typename ... I>
struct BreadBakedEventArgsT
    : impl::module_lock, implements<D, Microsoft::SDKSamples::Kitchen::IBreakBakedEventArgs, I ...>
{
    hstring GetRuntimeClassName() const
    {
        return L"Microsoft.SDKSamples.Kitchen.BreadBakedEventArgs";
    }
};

template <typename D, typename T, typename ... I>
struct BreadBakedEventArgsFactoryT : impl::module_lock, implements<D, Windows::Foundation::IActivationFactory, I ...>
{
    hstring GetRuntimeClassName() const
    {
        return L"Microsoft.SDKSamples.Kitchen.BreadBakedEventArgs";
    }

    Windows::Foundation::IInspectable ActivateInstance() const
    {
        throw hresult_not_implemented();
    }
};

template <typename D, typename ... I>
struct OvenT
    : impl::module_lock, implements<D, Microsoft::SDKSamples::Kitchen::IOven, Microsoft::SDKSamples::Kitchen::IAppliance, I ...>
{
    hstring GetRuntimeClassName() const
    {
        return L"Microsoft.SDKSamples.Kitchen.Oven";
    }
};

template <typename D, typename T, typename ... I>
struct OvenFactoryT : impl::module_lock, implements<D, Windows::Foundation::IActivationFactory, Microsoft::SDKSamples::Kitchen::IOvenFactory, I ...>
{
    hstring GetRuntimeClassName() const
    {
        return L"Microsoft.SDKSamples.Kitchen.Oven";
    }

    Windows::Foundation::IInspectable ActivateInstance() const
    {
        return make<T>();
    }

    Microsoft::SDKSamples::Kitchen::IOven CreateOven(Microsoft::SDKSamples::Kitchen::Dimensions const& dimensions)
    {
        return make<T>(dimensions);
    }
};

}

}
