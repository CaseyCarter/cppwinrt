﻿// WARNING: Please don't edit this file. It was generated by C++/WinRT v1.1.private

#include "pch.h"
#include "Language.h"
#include "Simple.h"
#include "Static.h"
#include "Structs.h"
#include "Composability.Open.Base.h"
#include "Composability.Open.Derived.h"
#include "Factory.Simple.h"
#include "Factory.SimpleFactory.h"
#include "Factory.Static.h"
#include "Factory.StaticFactory.h"
#include "Nested.Simple.h"
#include "Windows.Foundation.Uri.h"

namespace winrt::impl
{
    namespace
    {
        std::atomic<uint32_t> s_module_lock{};
    }

    module_lock::module_lock()
    {
        ++s_module_lock;
    }

    module_lock::~module_lock()
    {
        --s_module_lock;
    }
}

using namespace winrt;

HRESULT __stdcall DllCanUnloadNow()
{
    return impl::s_module_lock ? S_FALSE : S_OK;
}

HRESULT __stdcall DllGetActivationFactory(HSTRING classId, ::IUnknown** factory)
{
    try
    {
        wchar_t const* const name = WindowsGetStringRawBuffer(classId, nullptr);

        if (0 == wcscmp(name, L"Complex.Authoring.Language"))
        {
            *factory = detach_abi(make<Complex::Authoring::factory_implementation::Language>());
            return S_OK;
        }

        if (0 == wcscmp(name, L"Complex.Authoring.Simple"))
        {
            *factory = detach_abi(make<Complex::Authoring::factory_implementation::Simple>());
            return S_OK;
        }

        if (0 == wcscmp(name, L"Complex.Authoring.Static"))
        {
            *factory = detach_abi(make<Complex::Authoring::factory_implementation::Static>());
            return S_OK;
        }

        if (0 == wcscmp(name, L"Complex.Authoring.Structs"))
        {
            *factory = detach_abi(make<Complex::Authoring::factory_implementation::Structs>());
            return S_OK;
        }

        if (0 == wcscmp(name, L"Complex.Authoring.Composability.Open.Base"))
        {
            *factory = detach_abi(make<Complex::Authoring::Composability::Open::factory_implementation::Base>());
            return S_OK;
        }

        if (0 == wcscmp(name, L"Complex.Authoring.Composability.Open.Derived"))
        {
            *factory = detach_abi(make<Complex::Authoring::Composability::Open::factory_implementation::Derived>());
            return S_OK;
        }

        if (0 == wcscmp(name, L"Complex.Authoring.Factory.Simple"))
        {
            *factory = detach_abi(make<Complex::Authoring::Factory::factory_implementation::Simple>());
            return S_OK;
        }

        if (0 == wcscmp(name, L"Complex.Authoring.Factory.SimpleFactory"))
        {
            *factory = detach_abi(make<Complex::Authoring::Factory::factory_implementation::SimpleFactory>());
            return S_OK;
        }

        if (0 == wcscmp(name, L"Complex.Authoring.Factory.Static"))
        {
            *factory = detach_abi(make<Complex::Authoring::Factory::factory_implementation::Static>());
            return S_OK;
        }

        if (0 == wcscmp(name, L"Complex.Authoring.Factory.StaticFactory"))
        {
            *factory = detach_abi(make<Complex::Authoring::Factory::factory_implementation::StaticFactory>());
            return S_OK;
        }

        if (0 == wcscmp(name, L"Complex.Authoring.Nested.Simple"))
        {
            *factory = detach_abi(make<Complex::Authoring::Nested::factory_implementation::Simple>());
            return S_OK;
        }

        if (0 == wcscmp(name, L"Windows.Foundation.Uri"))
        {
            *factory = detach_abi(make<Windows::Foundation::factory_implementation::Uri>());
            return S_OK;
        }

        *factory = nullptr;
        return hresult_class_not_available().to_abi();
    }
    catch (...)
    {
        *factory = nullptr;
        return impl::to_hresult();
    }
}
