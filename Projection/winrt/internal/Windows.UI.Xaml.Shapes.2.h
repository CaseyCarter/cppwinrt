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
    auto operator->() const noexcept { return ptr<IEllipse>(m_ptr); }
};

struct ILine :
    Windows::IInspectable,
    impl::consume<ILine>
{
    ILine(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<ILine>(m_ptr); }
};

struct ILineStatics :
    Windows::IInspectable,
    impl::consume<ILineStatics>
{
    ILineStatics(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<ILineStatics>(m_ptr); }
};

struct IPath :
    Windows::IInspectable,
    impl::consume<IPath>
{
    IPath(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IPath>(m_ptr); }
};

struct IPathFactory :
    Windows::IInspectable,
    impl::consume<IPathFactory>
{
    IPathFactory(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IPathFactory>(m_ptr); }
};

struct IPathStatics :
    Windows::IInspectable,
    impl::consume<IPathStatics>
{
    IPathStatics(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IPathStatics>(m_ptr); }
};

struct IPolygon :
    Windows::IInspectable,
    impl::consume<IPolygon>
{
    IPolygon(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IPolygon>(m_ptr); }
};

struct IPolygonStatics :
    Windows::IInspectable,
    impl::consume<IPolygonStatics>
{
    IPolygonStatics(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IPolygonStatics>(m_ptr); }
};

struct IPolyline :
    Windows::IInspectable,
    impl::consume<IPolyline>
{
    IPolyline(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IPolyline>(m_ptr); }
};

struct IPolylineStatics :
    Windows::IInspectable,
    impl::consume<IPolylineStatics>
{
    IPolylineStatics(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IPolylineStatics>(m_ptr); }
};

struct IRectangle :
    Windows::IInspectable,
    impl::consume<IRectangle>
{
    IRectangle(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IRectangle>(m_ptr); }
};

struct IRectangleStatics :
    Windows::IInspectable,
    impl::consume<IRectangleStatics>
{
    IRectangleStatics(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IRectangleStatics>(m_ptr); }
};

struct IShape :
    Windows::IInspectable,
    impl::consume<IShape>
{
    IShape(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IShape>(m_ptr); }
};

struct IShape2 :
    Windows::IInspectable,
    impl::consume<IShape2>
{
    IShape2(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IShape2>(m_ptr); }
};

struct IShapeFactory :
    Windows::IInspectable,
    impl::consume<IShapeFactory>
{
    IShapeFactory(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IShapeFactory>(m_ptr); }
};

struct IShapeStatics :
    Windows::IInspectable,
    impl::consume<IShapeStatics>
{
    IShapeStatics(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IShapeStatics>(m_ptr); }
};

}

}
