// C++ for the Windows Runtime v1.0.private
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "Windows.UI.Xaml.Shapes.1.h"
#include "Windows.UI.Xaml.1.h"
#include "Windows.UI.Xaml.2.h"

WINRT_EXPORT namespace winrt {

namespace Windows::UI::Xaml::Shapes {

struct IEllipse :
    Windows::IInspectable,
    impl::consume<IEllipse>
{
    IEllipse(std::nullptr_t = nullptr) noexcept {}
};

struct ILine :
    Windows::IInspectable,
    impl::consume<ILine>
{
    ILine(std::nullptr_t = nullptr) noexcept {}
};

struct ILineStatics :
    Windows::IInspectable,
    impl::consume<ILineStatics>
{
    ILineStatics(std::nullptr_t = nullptr) noexcept {}
};

struct IPath :
    Windows::IInspectable,
    impl::consume<IPath>
{
    IPath(std::nullptr_t = nullptr) noexcept {}
};

struct IPathFactory :
    Windows::IInspectable,
    impl::consume<IPathFactory>
{
    IPathFactory(std::nullptr_t = nullptr) noexcept {}
};

struct IPathStatics :
    Windows::IInspectable,
    impl::consume<IPathStatics>
{
    IPathStatics(std::nullptr_t = nullptr) noexcept {}
};

struct IPolygon :
    Windows::IInspectable,
    impl::consume<IPolygon>
{
    IPolygon(std::nullptr_t = nullptr) noexcept {}
};

struct IPolygonStatics :
    Windows::IInspectable,
    impl::consume<IPolygonStatics>
{
    IPolygonStatics(std::nullptr_t = nullptr) noexcept {}
};

struct IPolyline :
    Windows::IInspectable,
    impl::consume<IPolyline>
{
    IPolyline(std::nullptr_t = nullptr) noexcept {}
};

struct IPolylineStatics :
    Windows::IInspectable,
    impl::consume<IPolylineStatics>
{
    IPolylineStatics(std::nullptr_t = nullptr) noexcept {}
};

struct IRectangle :
    Windows::IInspectable,
    impl::consume<IRectangle>
{
    IRectangle(std::nullptr_t = nullptr) noexcept {}
};

struct IRectangleStatics :
    Windows::IInspectable,
    impl::consume<IRectangleStatics>
{
    IRectangleStatics(std::nullptr_t = nullptr) noexcept {}
};

struct IShape :
    Windows::IInspectable,
    impl::consume<IShape>
{
    IShape(std::nullptr_t = nullptr) noexcept {}
};

struct IShape2 :
    Windows::IInspectable,
    impl::consume<IShape2>
{
    IShape2(std::nullptr_t = nullptr) noexcept {}
};

struct IShapeFactory :
    Windows::IInspectable,
    impl::consume<IShapeFactory>
{
    IShapeFactory(std::nullptr_t = nullptr) noexcept {}
};

struct IShapeStatics :
    Windows::IInspectable,
    impl::consume<IShapeStatics>
{
    IShapeStatics(std::nullptr_t = nullptr) noexcept {}
};

}

}
