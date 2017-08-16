﻿// WARNING: Please don't edit this file. It was generated by C++/WinRT v1.1.private

#pragma once

#include "module.h"

namespace winrt::Complex::Authoring::Composability::Open::implementation {

template <typename D, typename ... I>
struct Base_base : impl::module_lock, implements<D, Complex::Authoring::Composability::Open::IBase, composable, I ...>
{
    using class_type = Complex::Authoring::Composability::Open::Base;

    operator class_type() const noexcept
    {
        class_type result{ nullptr };
        attach_abi(result, detach_abi(static_cast<typename D::first_interface>(*this)));
        return result;
    }

    hstring GetRuntimeClassName() const
    {
        return L"Complex.Authoring.Composability.Open.Base";
    }
};

}

namespace winrt::Complex::Authoring::Composability::Open::factory_implementation {

template <typename D, typename T, typename ... I>
struct BaseT : impl::module_lock, implements<D, Windows::Foundation::IActivationFactory, Complex::Authoring::Composability::Open::IBaseFactory, I ...>
{
    hstring GetRuntimeClassName() const
    {
        return L"Complex.Authoring.Composability.Open.Base";
    }

    Windows::Foundation::IInspectable ActivateInstance() const
    {
        throw hresult_not_implemented();
    }

    Complex::Authoring::Composability::Open::IBase CreateInstance(Windows::Foundation::IInspectable const& outer, Windows::Foundation::IInspectable& inner)
    {
        return impl::composable_factory<T>::template CreateInstance<Complex::Authoring::Composability::Open::IBase>(outer, inner);
    }
};

}

#pragma warning(suppress: 4067)
#if defined(WINRT_FORCE_INCLUDE_BASE_XAML_G_H) || __has_include("Composability.Open.Base.xaml.g.h")

#include "Composability.Open.Base.xaml.g.h"

#else

namespace winrt::Complex::Authoring::Composability::Open::implementation
{
    template <typename D, typename ... I>
    using BaseT = Base_base<D, I ...>;
}

#endif
