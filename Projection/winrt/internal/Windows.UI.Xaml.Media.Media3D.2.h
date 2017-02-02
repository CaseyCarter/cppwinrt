// C++ for the Windows Runtime v1.0.private
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "Windows.UI.Xaml.Media.Media3D.1.h"
#include "Windows.UI.Xaml.1.h"
#include "Windows.UI.Xaml.2.h"

WINRT_EXPORT namespace winrt {

namespace Windows::UI::Xaml::Media::Media3D {

struct ICompositeTransform3D :
    Windows::IInspectable,
    impl::consume<ICompositeTransform3D>
{
    ICompositeTransform3D(std::nullptr_t = nullptr) noexcept {}
};

struct ICompositeTransform3DStatics :
    Windows::IInspectable,
    impl::consume<ICompositeTransform3DStatics>
{
    ICompositeTransform3DStatics(std::nullptr_t = nullptr) noexcept {}
};

struct IMatrix3DHelper :
    Windows::IInspectable,
    impl::consume<IMatrix3DHelper>
{
    IMatrix3DHelper(std::nullptr_t = nullptr) noexcept {}
};

struct IMatrix3DHelperStatics :
    Windows::IInspectable,
    impl::consume<IMatrix3DHelperStatics>
{
    IMatrix3DHelperStatics(std::nullptr_t = nullptr) noexcept {}
};

struct IPerspectiveTransform3D :
    Windows::IInspectable,
    impl::consume<IPerspectiveTransform3D>
{
    IPerspectiveTransform3D(std::nullptr_t = nullptr) noexcept {}
};

struct IPerspectiveTransform3DStatics :
    Windows::IInspectable,
    impl::consume<IPerspectiveTransform3DStatics>
{
    IPerspectiveTransform3DStatics(std::nullptr_t = nullptr) noexcept {}
};

struct ITransform3D :
    Windows::IInspectable,
    impl::consume<ITransform3D>
{
    ITransform3D(std::nullptr_t = nullptr) noexcept {}
};

struct ITransform3DFactory :
    Windows::IInspectable,
    impl::consume<ITransform3DFactory>
{
    ITransform3DFactory(std::nullptr_t = nullptr) noexcept {}
};

}

}
