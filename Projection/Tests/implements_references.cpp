#include "pch.h"
#include "catch.hpp"

//
// This test ensures that you can override the default reference count.
//

using namespace winrt;

struct References : implements<References, Windows::Foundation::IStringable>
{
    bool & m_destroyed;

    References(bool & destroyed) :
        implements(2),
        m_destroyed(destroyed)
    {
        m_destroyed = false;
    }

    ~References()
    {
        m_destroyed = true;
    }

    hstring ToString()
    {
        return L"value";
    }
};

TEST_CASE("implements_references")
{
    bool destroyed = false;
    com_ptr<References> ref = make_self<References>(destroyed);

    References * p = get(ref);

    REQUIRE(p->Release() == 1);

    REQUIRE(!destroyed);

    ref = nullptr;

    REQUIRE(destroyed);
}
