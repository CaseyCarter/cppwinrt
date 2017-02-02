// C++ for the Windows Runtime v1.0.private
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "Windows.ApplicationModel.Resources.1.h"

WINRT_EXPORT namespace winrt {

namespace Windows::ApplicationModel::Resources {

struct IResourceLoader :
    Windows::IInspectable,
    impl::consume<IResourceLoader>
{
    IResourceLoader(std::nullptr_t = nullptr) noexcept {}
};

struct IResourceLoader2 :
    Windows::IInspectable,
    impl::consume<IResourceLoader2>
{
    IResourceLoader2(std::nullptr_t = nullptr) noexcept {}
};

struct IResourceLoaderFactory :
    Windows::IInspectable,
    impl::consume<IResourceLoaderFactory>
{
    IResourceLoaderFactory(std::nullptr_t = nullptr) noexcept {}
};

struct IResourceLoaderStatics :
    Windows::IInspectable,
    impl::consume<IResourceLoaderStatics>
{
    IResourceLoaderStatics(std::nullptr_t = nullptr) noexcept {}
};

struct IResourceLoaderStatics2 :
    Windows::IInspectable,
    impl::consume<IResourceLoaderStatics2>
{
    IResourceLoaderStatics2(std::nullptr_t = nullptr) noexcept {}
};

}

}
