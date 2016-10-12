#include "pch.h"
#include "catch.hpp"

//
// These tests ensure that the make_self function works as expected to provide direct acccess
// to an implementation.
//
// The IMakeSelf IUnknown interface is also tested as this covers an edge case in the implements
// class template around implementing unprojected interfaces.
//

using namespace winrt;

struct __declspec(uuid("eebb3a22-13a6-43b9-9d53-b7deb5a20ae5")) __declspec(novtable) IMakeSelf : IUnknown
{
    virtual HRESULT __stdcall Call() = 0;
};

struct MakeSelfStringable : implements<MakeSelfStringable, Windows::Foundation::IStringable>
{
    hstring ToString()
    {
        return m_value;
    }

    hstring m_value;
};

struct MakeSelf : implements<MakeSelf, IMakeSelf>
{
    HRESULT __stdcall Call() override
    {
        return m_value;
    }

    HRESULT m_value = S_OK;
};

TEST_CASE("make_self")
{
    com_ptr<MakeSelfStringable> a = make_self<MakeSelfStringable>();
    a->m_value = L"Test value";
    REQUIRE(a->ToString() == L"Test value");

    com_ptr<MakeSelf> b = make_self<MakeSelf>();
    b->m_value = E_ACCESSDENIED;
    REQUIRE(b->Call() == E_ACCESSDENIED);
}
