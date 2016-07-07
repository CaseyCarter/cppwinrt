#include "pch.h"
#include "catch.hpp"

//
// These tests confirm the COM identity and other behaviours for agile implementations.
//

using namespace winrt;
using namespace Windows::Foundation;

struct TestAgile : implements<TestAgile, IClosable>
{
    bool & m_destroyed;
    TestAgile(bool & destroyed) : m_destroyed(destroyed) { m_destroyed = false; }
    ~TestAgile() { m_destroyed = true; }

    void Close() {}
};

struct TestNonAgile : implements<TestNonAgile, non_agile, IClosable>
{
    void Close() {}
};

TEST_CASE("TestAgile")
{
    using Windows::IUnknown;
    using Windows::IInspectable;

    bool destroyed = false;

    {
        IInspectable object = make<TestAgile>(destroyed);

        // Confirm agility:

        object.as<IAgileObject>();

        // Confirm legacy agility:

        com_ptr<IMarshal> marshal = object.as<IMarshal>();

        // Confirm tear-off identity:

        IUnknown object_identity = object.as<IUnknown>();
        IUnknown marshal_identity = marshal.as<IUnknown>();

        REQUIRE(object_identity == marshal_identity);

        REQUIRE(!destroyed);
    }

    // Confirm tear-off does not leak reference:

    REQUIRE(destroyed);
}

TEST_CASE("TestNonAgile")
{
    using Windows::IInspectable;

    IInspectable object = make<TestNonAgile>();

    // Does not implement IAgileObject:

    REQUIRE_THROWS_AS(object.as<IAgileObject>(), hresult_no_interface);

    // Does not implement IMarshal:

    REQUIRE_THROWS_AS(object.as<IMarshal>(), hresult_no_interface);
}
