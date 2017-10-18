#include "pch.h"
#include "catch.hpp"
#include "guid_compare.h"
#include "string_view_compare.h"

#pragma warning(disable:4471) // a forward declaration of an unscoped enumeration must have an underlying type
#include <Windows.Applicationmodel.Activation.h>

using namespace std::string_view_literals;

namespace winrt
{
    using namespace Windows::Foundation;
    using namespace Windows::Foundation::Collections;
}

namespace midl
{
    using namespace ABI::Windows::Foundation;
    using namespace ABI::Windows::Foundation::Collections;
}

// These really should be static_assert but due to VC bugs we currently have to run them as runtime asserts.
// These assertions just provide a degree of smoke testing against the MIDL-generated constants.

using winrt_container = winrt::IMapView<winrt::hstring, winrt::IInspectable>;
using midl_container = midl::IMapView<HSTRING, ::IInspectable*>;

static_assert(guid_equal(winrt::guid_of<winrt::IUnknown>(), __uuidof(::IUnknown)));
static_assert(guid_equal(winrt::guid_of<winrt::IInspectable>(), __uuidof(::IInspectable)));
static_assert(guid_equal(winrt::guid_of<winrt_container>(), __uuidof(midl_container)));

static_assert(string_view_equal(winrt::name_of<winrt::IInspectable>(), L"Object"sv));

TEST_CASE("constexpr")
{
    REQUIRE(winrt::name_of<winrt_container>() == midl_container::z_get_rc_name_impl());

    constexpr auto name = winrt::name_of<GUID>();
}
