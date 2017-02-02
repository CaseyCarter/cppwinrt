// C++ for the Windows Runtime v1.0.private
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "Windows.UI.Xaml.Resources.1.h"

WINRT_EXPORT namespace winrt {

namespace Windows::UI::Xaml::Resources {

struct ICustomXamlResourceLoader :
    Windows::IInspectable,
    impl::consume<ICustomXamlResourceLoader>
{
    ICustomXamlResourceLoader(std::nullptr_t = nullptr) noexcept {}
};

struct ICustomXamlResourceLoaderFactory :
    Windows::IInspectable,
    impl::consume<ICustomXamlResourceLoaderFactory>
{
    ICustomXamlResourceLoaderFactory(std::nullptr_t = nullptr) noexcept {}
};

struct ICustomXamlResourceLoaderOverrides :
    Windows::IInspectable,
    impl::consume<ICustomXamlResourceLoaderOverrides>
{
    ICustomXamlResourceLoaderOverrides(std::nullptr_t = nullptr) noexcept {}
};

struct ICustomXamlResourceLoaderStatics :
    Windows::IInspectable,
    impl::consume<ICustomXamlResourceLoaderStatics>
{
    ICustomXamlResourceLoaderStatics(std::nullptr_t = nullptr) noexcept {}
};

}

}
