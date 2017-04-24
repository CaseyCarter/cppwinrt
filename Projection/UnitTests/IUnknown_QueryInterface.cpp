#include "pch.h"
#include "catch.hpp"

using namespace winrt;
using namespace Windows::Foundation;

//
// These tests cover the behaviour of the 'as' and 'try_as' members that provide the
// projection's access to IUnknown's QueryInterface virtual function. Both the 
// projected IUnknown (value type) and the com_ptr class template provide both 'as' 
// and 'try_as' and while those types are different, these two methods should behave
// the same way.
//

TEST_CASE("IUnknown::as,try_as")
{
    Uri uri(L"http://host/path");

    {
        IStringable s = uri.as<IStringable>();
        REQUIRE(s);

        REQUIRE_THROWS_AS(uri.as<IClosable>(), hresult_no_interface);

        IClosable c = uri.try_as<IClosable>();
        REQUIRE(!c);
    }

    {
        com_ptr<IStringable> s = uri.as<abi<IStringable>>();
        REQUIRE(s);

        REQUIRE_THROWS_AS(uri.as<abi<IClosable>>(), hresult_no_interface);

        com_ptr<IClosable> c = uri.try_as<abi<IClosable>>();
        REQUIRE(!c);
    }
}

TEST_CASE("com_ptr::as,try_as")
{
    Uri uri(L"http://host/path");

    com_ptr<IUriRuntimeClass> p = uri.as<abi<IUriRuntimeClass>>();

    {
        IStringable s = p.as<IStringable>();
        REQUIRE(s);

        REQUIRE_THROWS_AS(p.as<IClosable>(), hresult_no_interface);

        IClosable c = p.try_as<IClosable>();
        REQUIRE(!c);
    }

    {
        com_ptr<IStringable> s = p.as<abi<IStringable>>();
        REQUIRE(s);

        REQUIRE_THROWS_AS(p.as<abi<IClosable>>(), hresult_no_interface);

        com_ptr<IClosable> c = p.try_as<abi<IClosable>>();
        REQUIRE(!c);
    }
}
