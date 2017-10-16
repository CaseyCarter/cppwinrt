#include "pch.h"
#include "catch.hpp"

using namespace winrt;
using namespace Windows::Foundation;
using namespace Windows::UI::Xaml::Interop;

TEST_CASE("IReference<Rect>")
{
    Point original{ 1, 2 };
    IReference<Point> ref = original;
    Point value = ref.Value();
    REQUIRE(original.X == value.X);
    REQUIRE(original.Y == value.Y);
}

TEST_CASE("IReference<TypeName>")
{
    TypeName original{ L"TestName", TypeKind::Custom };
    IReference<TypeName> ref = original;
    TypeName value = ref.Value();
    REQUIRE(original.Name == value.Name);
    REQUIRE(original.Kind == value.Kind);

    REQUIRE(!ref.IsNumericScalar());
    REQUIRE_THROWS_AS(ref.GetUInt8() == 2, hresult_not_implemented);
    REQUIRE_THROWS_AS(ref.GetUInt16() == 2, hresult_not_implemented);
    REQUIRE_THROWS_AS(ref.GetInt16() == 2, hresult_not_implemented);
    REQUIRE_THROWS_AS(ref.GetUInt32() == 2, hresult_not_implemented);
    REQUIRE_THROWS_AS(ref.GetInt32() == 2, hresult_not_implemented);
    REQUIRE_THROWS_AS(ref.GetUInt64() == 2, hresult_not_implemented);
    REQUIRE_THROWS_AS(ref.GetInt64() == 2, hresult_not_implemented);
}

TEST_CASE("IReference<TypeKind>")
{
    IReference<TypeKind> ref = TypeKind::Custom;
    REQUIRE(ref.Value() == TypeKind::Custom);
    REQUIRE(ref.IsNumericScalar());
    REQUIRE(ref.GetUInt8() == 2);
    REQUIRE(ref.GetUInt16() == 2);
    REQUIRE(ref.GetInt16() == 2);
    REQUIRE(ref.GetUInt32() == 2);
    REQUIRE(ref.GetInt32() == 2);
    REQUIRE(ref.GetUInt64() == 2);
    REQUIRE(ref.GetInt64() == 2);
}
