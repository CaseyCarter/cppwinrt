﻿// WARNING: Please don't edit this file. It was generated by C++/WinRT v1.1.private

#pragma once

#include "module.h"

namespace winrt {

namespace Complex::Authoring::Factory::factory_implementation {

template <typename D, typename T, typename ... I>
struct StaticT : impl::module_lock, implements<D, Windows::Foundation::IActivationFactory, Complex::Authoring::Factory::IStatic, I ...>
{
    hstring GetRuntimeClassName() const
    {
        return L"Complex.Authoring.Factory.Static";
    }

    Windows::Foundation::IInspectable ActivateInstance() const
    {
        throw hresult_not_implemented();
    }

    void StaticMethod()
    {
        T::StaticMethod();
    }
};

}

}
