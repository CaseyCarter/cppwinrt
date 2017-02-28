#include "pch.h"
#include "catch.hpp"

//
// Tests both the production and consumption of IInspectable's GetIids method. Specifically tests:
//
// 1. The non_agile policy type does not interfere with the generation of the resulting GUID array.
// 2. IStringable is included as it is an an IInspectable-derived interface.
// 3. LicenseChangedEventHandler is not included as it is not an IInspectable-derived interface.
// 4. IClosable is not included as it is cloaked.
//

using namespace winrt;
using namespace Windows::Foundation;

struct Test_GetIids : implements<Test_GetIids,
                                 non_agile,
                                 Windows::Foundation::IStringable,
                                 ABI::Windows::ApplicationModel::Store::LicenseChangedEventHandler,
                                 cloaked<Windows::Foundation::IClosable>>
{
    hstring ToString() { return{}; }
    void Close() {}
    HRESULT __stdcall get_DesignModeEnabled(bool * result) { *result = false; return S_OK; }
    HRESULT __stdcall abi_Invoke() noexcept override { return S_OK; }
};

TEST_CASE("Test_GetIids")
{
    IInspectable i = make<Test_GetIids>();

    com_array<GUID> iids = GetIids(i);

    REQUIRE(iids.size() == 1);
    REQUIRE(iids[0] == __uuidof(abi<Windows::Foundation::IStringable>));
}
