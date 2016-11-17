// C++ for the Windows Runtime v1.0.private
// Copyright (c) 2016 Microsoft Corporation. All rights reserved.

#pragma once


WINRT_EXPORT namespace winrt {

namespace ABI::Windows::ApplicationModel::Resources {

struct IResourceLoader;
struct IResourceLoader2;
struct IResourceLoaderFactory;
struct IResourceLoaderStatics;
struct IResourceLoaderStatics2;
struct ResourceLoader;

}

namespace Windows::ApplicationModel::Resources {

struct IResourceLoader;
struct IResourceLoader2;
struct IResourceLoaderFactory;
struct IResourceLoaderStatics;
struct IResourceLoaderStatics2;
struct ResourceLoader;

}

namespace Windows::ApplicationModel::Resources {

template <typename T> struct impl_IResourceLoader;
template <typename T> struct impl_IResourceLoader2;
template <typename T> struct impl_IResourceLoaderFactory;
template <typename T> struct impl_IResourceLoaderStatics;
template <typename T> struct impl_IResourceLoaderStatics2;

}

}
