#include "pch.h"
#include "catch.hpp"

using namespace winrt;
using namespace Windows::Foundation;

// {C40D08D9-051A-48DB-8DB1-B5902D89D594}
static constexpr GUID TestClassObjectGuid =
{ 0xc40d08d9, 0x51a, 0x48db,{ 0x8d, 0xb1, 0xb5, 0x90, 0x2d, 0x89, 0xd5, 0x94 } };

TEST_CASE("DllGetClassObject")
{
    //IStringable a = create_instance<IStringable>(TestClassObjectGuid);
    //REQUIRE(a.ToString() == L"ClassObject");

    //com_ptr<::IUnknown> b = create_instance<::IUnknown>(TestClassObjectGuid);
    //REQUIRE(b.as<IStringable>().ToString() == L"ClassObject");
}
