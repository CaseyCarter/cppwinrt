#include "pch.h"
#include "catch.hpp"

using namespace winrt;
using namespace Windows::Foundation;
using namespace Windows::UI::Xaml::Controls;
using namespace Windows::UI::Xaml::Interop;
using namespace Windows::Web::Http;

//
// This first test ensures that structures with HSTRING fields are projected correctly.
// In this case, a suitable interface is provided by the Windows SDK to simplify testing.
// IControlTemplate provides the necessary methods for excercising input and output 
// patterns for code generation.
//

struct TestTypeName : implements<TestTypeName, IControlTemplate>
{
    TypeName m_value;

    Windows::UI::Xaml::Interop::TypeName TargetType()
    {
        return m_value;
    }

    void TargetType(const Windows::UI::Xaml::Interop::TypeName & value)
    {
        m_value = value;
    }
};

TEST_CASE("struct, TypeName")
{
    IControlTemplate object = make<TestTypeName>();

    TypeName value = object.TargetType();
    REQUIRE(value.Kind == TypeKind::Primitive);
    REQUIRE(value.Name.empty());

    object.TargetType({ L"Value", TypeKind::Custom });

    value = object.TargetType();
    REQUIRE(value.Kind == TypeKind::Custom);
    REQUIRE(value.Name == L"Value");
}

//
// This second test ensures that structures with IReference<T> fields are projected correctly.
// In this case, a suitable interface is not available in the Windows SDK so we hand-roll the 
// the necessary intput and output patterms for code generation. We also rely on a custom 
// implementation of IReference<T> so that we can additionally check that the object is 
// destroyed correctly. 
//

struct TestReference : implements<TestReference, IReference<uint64_t>>
{
    bool * m_destroyed = nullptr;

    TestReference(bool * destroyed = nullptr) :
        m_destroyed(destroyed)
    {
        if (m_destroyed)
        {
            *m_destroyed = false;
        }
    }

    ~TestReference()
    {
        if (m_destroyed)
        {
            *m_destroyed = true;
        }
    }

    uint64_t Value()
    {
        return 200;
    }
};

struct TestHttpProgress
{
    winrt::Windows::Web::Http::HttpProgress m_value {};

    void abi_in(abi_t<Windows::Web::Http::HttpProgress> value)
    {
        copy_from_abi(m_value, value);
    }

    void abi_out(abi_t<Windows::Web::Http::HttpProgress> * value)
    {
        copy_to_abi(m_value, *value);
    }

    void in(winrt::Windows::Web::Http::HttpProgress const & value)
    {
        abi_in(get_abi(value));
    }

    winrt::Windows::Web::Http::HttpProgress out()
    {
        winrt::Windows::Web::Http::HttpProgress value {};
        abi_out(put_abi(value));
        return value;
    }
};

TEST_CASE("struct, HttpProgress")
{
    TestHttpProgress object;

    HttpProgress value = object.out();
    REQUIRE(value.BytesSent == 0);
    REQUIRE(value.TotalBytesToSend == nullptr);

    bool destroyed = true;

    {
        HttpProgress local {};
        local.BytesSent = 10;
        local.TotalBytesToSend = make<TestReference>(&destroyed);

        REQUIRE(!destroyed);

        object.in(local);
    }

    value = object.out();
    REQUIRE(value.BytesSent == 10);
    REQUIRE(value.TotalBytesToSend.Value() == 200);

    // Still one outstanding reference.
    REQUIRE(!destroyed);
    value = {};

    // Last outstanding reference.
    REQUIRE(!destroyed);
    object.m_value = {};

    REQUIRE(destroyed);
}
