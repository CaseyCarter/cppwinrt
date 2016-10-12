#include "pch.h"
#include "catch.hpp"

using namespace winrt;
using namespace Windows::Foundation;

TEST_CASE("weak")
{
    SECTION("resolved")
    {
        Uri a(L"http://host/path");

        weak_ref<Uri> w = a;
        Uri b = w.get();
        REQUIRE(b.Host() == L"host");

        // still one outstanding reference
        b = nullptr;
        b = w.get();
        REQUIRE(b != nullptr);

        // no outstanding references
        a = nullptr;
        b = nullptr;
        b = w.get();
        REQUIRE(b == nullptr);
    }

    SECTION("unresolved")
    {
        // default construct
        weak_ref<Uri> w;

        w = Uri(L"http://host/path"); // reference is lost right here
        Uri b = w.get();
        REQUIRE(b == nullptr);
    }

    SECTION("make_weak")
    {
        Uri a(L"http://host/path");
        auto w = make_weak(a);
        Uri b = w.get();
        REQUIRE(b.Host() == L"host");
    }
}

struct NoWeak : implements<NoWeak, IStringable>
{
    hstring ToString()
    {
        return L"Value";
    }
};

TEST_CASE("weak,none")
{
    IStringable s = make<NoWeak>();

    REQUIRE_THROWS_AS(make_weak(s), hresult_no_interface);

    try
    {
        weak_ref<IStringable> w = s;
        REQUIRE(false);
    }
    catch (hresult_no_interface const &) {}
}
