#include "pch.h"
#include "catch.hpp"

using namespace winrt;
using namespace Windows::Foundation;

namespace
{
    struct Thing : implements<Thing, IStringable, IClosable>
    {
        hstring ToString()
        {
            return {};
        }

        void Close()
        {
        }
    };
}

TEST_CASE("as<T>")
{
    IStringable s = make<Thing>();

    com_ptr<::IUnknown> u = s.as<::IUnknown>();

    IClosable c = u.as<IClosable>();

    REQUIRE_THROWS_AS(u.as<::IDispatch>(), hresult_no_interface);

    REQUIRE_THROWS_AS(u.as<IPropertyValue>(), hresult_no_interface);

    REQUIRE(s == c);
}

TEST_CASE("try_as<T>")
{
    IStringable s = make<Thing>();

    com_ptr<::IUnknown> u = s.try_as<::IUnknown>();
    REQUIRE(u);

    IClosable c = u.try_as<IClosable>();
    REQUIRE(s == c);

    com_ptr<::IDispatch> d = s.try_as<::IDispatch>();
    REQUIRE(!d);

    IPropertyValue pv = s.try_as<IPropertyValue>();
    REQUIRE(!pv);
}

TEST_CASE("as(T)")
{
    IStringable s = make<Thing>();

    com_ptr<::IUnknown> u;
    s.as(u);

    IClosable c;
    u.as(c);

    com_ptr<::IDispatch> d;
    REQUIRE_THROWS_AS(u.as(d), hresult_no_interface);

    IPropertyValue pv;
    REQUIRE_THROWS_AS(u.as(pv), hresult_no_interface);

    REQUIRE(s == c);
}

TEST_CASE("try_as(T)")
{
    IStringable s = make<Thing>();

    com_ptr<::IUnknown> u;
    s.try_as(u);
    REQUIRE(u);

    IClosable c;
    u.try_as(c);
    REQUIRE(s == c);

    com_ptr<::IDispatch> d;
    s.try_as(d);
    REQUIRE(!d);

    IPropertyValue pv;
    s.try_as(pv);
    REQUIRE(!pv);
}
