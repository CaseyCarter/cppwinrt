﻿// WARNING: Please don't edit this file. It was generated by C++/WinRT v1.0.170906.1

#pragma once

#include "module.h"

namespace winrt::Complex::Authoring::Composability::Closed::implementation {

template <typename D, typename ... I>
struct Base_base : impl::module_lock, implements<D, Complex::Authoring::Composability::Closed::IBase, I ...>
{
    using class_type = Complex::Authoring::Composability::Closed::Base;

    operator class_type() const noexcept
    {
        class_type result{ nullptr };
        attach_abi(result, detach_abi(static_cast<typename D::first_interface>(*this)));
        return result;
    }

    hstring GetRuntimeClassName() const
    {
        return L"Complex.Authoring.Composability.Closed.Base";
    }
};

}

#pragma warning(suppress: 4067)
#if defined(WINRT_FORCE_INCLUDE_BASE_XAML_G_H) || __has_include("Composability.Closed.Base.xaml.g.h")

#include "Composability.Closed.Base.xaml.g.h"

#else

namespace winrt::Complex::Authoring::Composability::Closed::implementation
{
    template <typename D, typename ... I>
    using BaseT = Base_base<D, I ...>;
}

#endif
