﻿// WARNING: Please don't edit this file. It was generated by C++/WinRT v1.1.private

#pragma once

#include "module.h"

namespace winrt {

namespace Complex::Authoring::implementation {

template <typename D, typename ... I>
struct SimpleBase : impl::module_lock, implements<D, Complex::Authoring::ISimple, I ...>
{
    using class_type = Complex::Authoring::Simple;

    operator class_type() const noexcept
    {
        class_type result{ nullptr };
        attach_abi(result, detach_abi(static_cast<typename D::first_interface>(*this)));
        return result;
    }

    hstring GetRuntimeClassName() const
    {
        return L"Complex.Authoring.Simple";
    }
};

template <typename D, typename T, typename ... I>
struct SimpleFactoryBase : impl::module_lock, implements<D, Windows::Foundation::IActivationFactory, I ...>
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

#pragma warning(suppress: 4067)
#if defined(WINRT_FORCE_INCLUDE_SIMPLE_X_H) || __has_include("Simple.x.h")

#include "Simple.x.h"

#else

template <typename D, typename ... I>
using SimpleT = SimpleBase<D, I ...>;

template <typename D, typename T, typename ... I>
using SimpleFactoryT = SimpleFactoryBase<D, T, I ...>;

#endif

}

}
