#include "pch.h"
#include "catch.hpp"

//
// Tests both the production and consumption of IInspectable's GetIids method. Specifically tests:
//
// 1. The non_agile policy type does not interfere with the generation of the resulting GUID array.
// 2. IStringable is included as it is an an IInspectable-derived interface.
// 3. LicenseChangedEventHandler is not included as it is not an IInspectable-derived interface.
// 4. IClosable is not included as it is cloaked.
// 5. IDesignModeStatics is included as it is an an IInspectable-derived interface and even though it is an ABI
//

using namespace winrt;
using namespace Windows;

struct Test_GetIids : implements<Test_GetIids,
                                 non_agile,
                                 Windows::Foundation::IStringable,
                                 ABI::Windows::ApplicationModel::Store::LicenseChangedEventHandler,
                                 cloaked<Windows::Foundation::IClosable>,
                                 ABI::Windows::ApplicationModel::IDesignModeStatics>
{
    hstring ToString() { return{}; }
    void Close() {}
    HRESULT __stdcall get_DesignModeEnabled(bool * result) { *result = false; return S_OK; }
    HRESULT __stdcall abi_Invoke() override { return S_OK; }
};

TEST_CASE("Test_GetIids")
{
    IInspectable i = make<Test_GetIids>();

    com_array<GUID> iids = GetIids(i);

    REQUIRE(iids.size() == 2);
    REQUIRE(iids[0] == __uuidof(abi<Windows::Foundation::IStringable>));
    REQUIRE(iids[1] == __uuidof(abi<Windows::ApplicationModel::IDesignModeStatics>));
}
