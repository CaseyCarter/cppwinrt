#include "pch.h"
#include "catch.hpp"

//
// Tests both the production and consumption of IInspectable's GetRuntimeClassName method. Specifically tests:
//
// 1. Failing to override GetRuntimeClassName results in an hresult_not_implemented exception.
// 2. Overriding GetRuntimeClassName allows the implementation to return a suitable string value.
//

using namespace winrt;
using namespace Windows;
using namespace Windows::Foundation;

struct Test_GetRuntimeClassName_NoOverride : implements<Test_GetRuntimeClassName_NoOverride, IInspectable>
{
};

struct Test_GetRuntimeClassName_Override : implements<Test_GetRuntimeClassName_Override, IInspectable>
{
    hstring GetRuntimeClassName()
    {
        return L"GetRuntimeClassName";
    }
};

TEST_CASE("Test_GetRuntimeClassName_NoOverride")
{
    IInspectable i = make<Test_GetRuntimeClassName_NoOverride>();

    REQUIRE_THROWS_AS(GetRuntimeClassName(i), hresult_not_implemented);
}

TEST_CASE("Test_GetRuntimeClassName_Override")
{
    IInspectable i = make<Test_GetRuntimeClassName_Override>();

    REQUIRE(GetRuntimeClassName(i) == L"GetRuntimeClassName");
}
