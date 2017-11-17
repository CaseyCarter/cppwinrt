#include "pch.h"
#include "catch.hpp"

using namespace winrt;
using namespace Windows::Foundation;
using namespace Component;

TEST_CASE("Events")
{
    {
        Events events;
        int result = 0;

        auto token = events.SimpleEvent([&result](IInspectable const&, int value)
        {
            result = value;
        });

        REQUIRE(result == 0);
        events.RaiseSimpleEvent(123);
        REQUIRE(result == 123);

        events.SimpleEvent(token);

        REQUIRE(result == 123);
        events.RaiseSimpleEvent(321);
        REQUIRE(result == 123); // no change
    }

    {
        Events events;
        int result = 0;

        auto revoker = events.SimpleEvent(auto_revoke, [&result](IInspectable const&, int value)
        {
            result = value;
        });

        REQUIRE(result == 0);
        events.RaiseSimpleEvent(123);
        REQUIRE(result == 123);

        // This validates the operator bool on the revoker, which was previously broken.
        REQUIRE(revoker);
        revoker.revoke();
        REQUIRE(!revoker);

        REQUIRE(result == 123);
        events.RaiseSimpleEvent(321);
        REQUIRE(result == 123); // no change
    }

    {
        Events events;
        int result = 0;

        events.TypedEvent([&](Events const& sender, int value)
        {
            REQUIRE(sender == events);
            result = value;
        });

        REQUIRE(result == 0);
        events.RaiseTypedEvent(123);
        REQUIRE(result == 123);
    }

    {
        Events events;
        int result = 0;

        events.CustomEvent([&](int value)
        {
            result = value;
        });

        REQUIRE(result == 0);
        events.RaiseCustomEvent(123);
        REQUIRE(result == 123);
    }

    {
        ReturnDelegate d = []
        {
            return L"one";
        };

        REQUIRE(d() == L"one");

        d = []
        {
            return std::wstring_view(L"two");
        };

        REQUIRE(d() == L"two");

        d = []
        {
            return hstring(L"three");
        };

        REQUIRE(d() == L"three");
    }
}
