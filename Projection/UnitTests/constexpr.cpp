#include "pch.h"
#include "catch.hpp"

#pragma warning(disable:4471) // a forward declaration of an unscoped enumeration must have an underlying type
#include <Windows.Applicationmodel.Activation.h>

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

TEST_CASE("constexpr")
{
    using winrt_container = winrt::IMapView<winrt::hstring, winrt::IInspectable>;
    using midl_container = midl::IMapView<HSTRING, ::IInspectable*>;

    REQUIRE(winrt::guid_of<winrt::IUnknown>() == __uuidof(::IUnknown));
    REQUIRE(winrt::guid_of<winrt::IInspectable>() == __uuidof(::IInspectable));
    REQUIRE(winrt::guid_of<winrt_container>() == __uuidof(midl_container));

    REQUIRE(winrt::name_of<winrt::IInspectable>() == L"Object");
    REQUIRE(winrt::name_of<winrt_container>() == midl_container::z_get_rc_name_impl());
}
