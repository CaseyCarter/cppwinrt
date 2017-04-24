#include "pch.h"
#include "catch.hpp"

// These tests ensure that the IReference interface can be implemented with a T that has:
//   - A non-trivial destructor
//   - A distinct ABI/projected representation

namespace winrt::ABI::Windows::Foundation
{
    template <>
    struct __declspec(uuid("81a643fb-f51c-5565-83c4-f96425777b66")) __declspec(novtable)
        IReference<Windows::UI::Xaml::Interop::TypeName> : impl_IReference<Windows::UI::Xaml::Interop::TypeName>
    {};
}

using namespace winrt;
using namespace Windows::Foundation;
using namespace Windows::UI::Xaml::Interop;

namespace
{
    template<typename T>
    struct Reference : implements<Reference<T>, IReference<T>>
    {
        T m_value;

        Reference(const T & value)
            : m_value(value)
        {}

        T Value()
        {
            return m_value;
        }
    };
}

TEST_CASE("IReference<Rect>")
{
    Point original{ 1, 2 };
    IReference<Point> ref = make<Reference<Point>>(original);
    Point value = ref.Value();
    REQUIRE(original.X == value.X);
    REQUIRE(original.Y == value.Y);
}

TEST_CASE("IReference<TypeName>")
{
    TypeName original{ L"TestName", TypeKind::Custom };
    IReference<TypeName> ref = make<Reference<TypeName>>(original);
    TypeName value = ref.Value();
    REQUIRE(original.Name == value.Name);
    REQUIRE(original.Kind == value.Kind);
}