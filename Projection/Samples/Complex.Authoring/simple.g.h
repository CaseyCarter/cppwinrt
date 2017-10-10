﻿// WARNING: Please don't edit this file. It was generated by C++/WinRT v1.0.170906.1

#pragma once

#include "module.h"
#include "winrt/Complex.Authoring.h"

namespace winrt::Complex::Authoring::implementation {

template <typename D, typename ... I>
struct WINRT_EBO Simple_base : impl::module_lock, implements<D, Complex::Authoring::ISimple, I ...>
{
    using class_type = Complex::Authoring::Simple;
    
    operator class_type() const noexcept
    {
        static_assert(std::is_same_v<typename D::first_interface, impl::default_interface_t<class_type>>);
        class_type result{ nullptr };
        attach_abi(result, detach_abi(static_cast<impl::default_interface_t<class_type>>(*this)));
        return result;
    }

    hstring GetRuntimeClassName() const
    {
        return L"Complex.Authoring.Simple";
    }
};

}

namespace winrt::Complex::Authoring::factory_implementation {

template <typename D, typename T, typename ... I>
struct WINRT_EBO SimpleT : impl::module_lock, implements<D, Windows::Foundation::IActivationFactory, I ...>
{
    hstring GetRuntimeClassName() const
    {
        return L"Complex.Authoring.Simple";
    }

    Windows::Foundation::IInspectable ActivateInstance() const
    {
        return make<T>();
    }
};

}

#if defined(WINRT_FORCE_INCLUDE_SIMPLE_XAML_G_H) || __has_include("Simple.xaml.g.h")

#include "Simple.xaml.g.h"

#else

namespace winrt::Complex::Authoring::implementation
{
    template <typename D, typename ... I>
    using SimpleT = Simple_base<D, I ...>;
}

#endif
