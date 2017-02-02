// C++ for the Windows Runtime v1.0.private
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "Windows.UI.Xaml.Media.Imaging.1.h"
#include "Windows.Foundation.1.h"
#include "Windows.UI.Xaml.1.h"
#include "Windows.UI.Xaml.Media.1.h"
#include "Windows.UI.Xaml.2.h"
#include "Windows.UI.Xaml.Media.2.h"

WINRT_EXPORT namespace winrt {

namespace ABI::Windows::Foundation {

#ifndef WINRT_GENERIC_3bee8834_b9a7_5a80_a746_5ef097227878
#define WINRT_GENERIC_3bee8834_b9a7_5a80_a746_5ef097227878
template <> struct __declspec(uuid("3bee8834-b9a7-5a80-a746-5ef097227878")) __declspec(novtable) IAsyncOperation<Windows::Storage::Streams::IBuffer> : impl_IAsyncOperation<Windows::Storage::Streams::IBuffer> {};
#endif

#ifndef WINRT_GENERIC_51c3d2fd_b8a1_5620_b746_7ee6d533aca3
#define WINRT_GENERIC_51c3d2fd_b8a1_5620_b746_7ee6d533aca3
template <> struct __declspec(uuid("51c3d2fd-b8a1-5620-b746-7ee6d533aca3")) __declspec(novtable) AsyncOperationCompletedHandler<Windows::Storage::Streams::IBuffer> : impl_AsyncOperationCompletedHandler<Windows::Storage::Streams::IBuffer> {};
#endif


}

namespace Windows::UI::Xaml::Media::Imaging {

struct DownloadProgressEventHandler : Windows::IUnknown
{
    DownloadProgressEventHandler(std::nullptr_t = nullptr) noexcept {}
    template <typename L> DownloadProgressEventHandler(L lambda);
    template <typename F> DownloadProgressEventHandler (F * function);
    template <typename O, typename M> DownloadProgressEventHandler(O * object, M method);
    void operator()(const Windows::IInspectable & sender, const Windows::UI::Xaml::Media::Imaging::DownloadProgressEventArgs & e) const;
};

struct IBitmapImage :
    Windows::IInspectable,
    impl::consume<IBitmapImage>
{
    IBitmapImage(std::nullptr_t = nullptr) noexcept {}
};

struct IBitmapImage2 :
    Windows::IInspectable,
    impl::consume<IBitmapImage2>
{
    IBitmapImage2(std::nullptr_t = nullptr) noexcept {}
};

struct IBitmapImage3 :
    Windows::IInspectable,
    impl::consume<IBitmapImage3>
{
    IBitmapImage3(std::nullptr_t = nullptr) noexcept {}
};

struct IBitmapImageFactory :
    Windows::IInspectable,
    impl::consume<IBitmapImageFactory>
{
    IBitmapImageFactory(std::nullptr_t = nullptr) noexcept {}
};

struct IBitmapImageStatics :
    Windows::IInspectable,
    impl::consume<IBitmapImageStatics>
{
    IBitmapImageStatics(std::nullptr_t = nullptr) noexcept {}
};

struct IBitmapImageStatics2 :
    Windows::IInspectable,
    impl::consume<IBitmapImageStatics2>
{
    IBitmapImageStatics2(std::nullptr_t = nullptr) noexcept {}
};

struct IBitmapImageStatics3 :
    Windows::IInspectable,
    impl::consume<IBitmapImageStatics3>
{
    IBitmapImageStatics3(std::nullptr_t = nullptr) noexcept {}
};

struct IBitmapSource :
    Windows::IInspectable,
    impl::consume<IBitmapSource>
{
    IBitmapSource(std::nullptr_t = nullptr) noexcept {}
};

struct IBitmapSourceFactory :
    Windows::IInspectable,
    impl::consume<IBitmapSourceFactory>
{
    IBitmapSourceFactory(std::nullptr_t = nullptr) noexcept {}
};

struct IBitmapSourceStatics :
    Windows::IInspectable,
    impl::consume<IBitmapSourceStatics>
{
    IBitmapSourceStatics(std::nullptr_t = nullptr) noexcept {}
};

struct IDownloadProgressEventArgs :
    Windows::IInspectable,
    impl::consume<IDownloadProgressEventArgs>
{
    IDownloadProgressEventArgs(std::nullptr_t = nullptr) noexcept {}
};

struct IRenderTargetBitmap :
    Windows::IInspectable,
    impl::consume<IRenderTargetBitmap>
{
    IRenderTargetBitmap(std::nullptr_t = nullptr) noexcept {}
};

struct IRenderTargetBitmapStatics :
    Windows::IInspectable,
    impl::consume<IRenderTargetBitmapStatics>
{
    IRenderTargetBitmapStatics(std::nullptr_t = nullptr) noexcept {}
};

struct ISoftwareBitmapSource :
    Windows::IInspectable,
    impl::consume<ISoftwareBitmapSource>
{
    ISoftwareBitmapSource(std::nullptr_t = nullptr) noexcept {}
};

struct ISurfaceImageSource :
    Windows::IInspectable,
    impl::consume<ISurfaceImageSource>
{
    ISurfaceImageSource(std::nullptr_t = nullptr) noexcept {}
};

struct ISurfaceImageSourceFactory :
    Windows::IInspectable,
    impl::consume<ISurfaceImageSourceFactory>
{
    ISurfaceImageSourceFactory(std::nullptr_t = nullptr) noexcept {}
};

struct IVirtualSurfaceImageSource :
    Windows::IInspectable,
    impl::consume<IVirtualSurfaceImageSource>
{
    IVirtualSurfaceImageSource(std::nullptr_t = nullptr) noexcept {}
};

struct IVirtualSurfaceImageSourceFactory :
    Windows::IInspectable,
    impl::consume<IVirtualSurfaceImageSourceFactory>
{
    IVirtualSurfaceImageSourceFactory(std::nullptr_t = nullptr) noexcept {}
};

struct IWriteableBitmap :
    Windows::IInspectable,
    impl::consume<IWriteableBitmap>
{
    IWriteableBitmap(std::nullptr_t = nullptr) noexcept {}
};

struct IWriteableBitmapFactory :
    Windows::IInspectable,
    impl::consume<IWriteableBitmapFactory>
{
    IWriteableBitmapFactory(std::nullptr_t = nullptr) noexcept {}
};

struct IXamlRenderingBackgroundTask :
    Windows::IInspectable,
    impl::consume<IXamlRenderingBackgroundTask>
{
    IXamlRenderingBackgroundTask(std::nullptr_t = nullptr) noexcept {}
};

struct IXamlRenderingBackgroundTaskFactory :
    Windows::IInspectable,
    impl::consume<IXamlRenderingBackgroundTaskFactory>
{
    IXamlRenderingBackgroundTaskFactory(std::nullptr_t = nullptr) noexcept {}
};

struct IXamlRenderingBackgroundTaskOverrides :
    Windows::IInspectable,
    impl::consume<IXamlRenderingBackgroundTaskOverrides>
{
    IXamlRenderingBackgroundTaskOverrides(std::nullptr_t = nullptr) noexcept {}
};

}

}
