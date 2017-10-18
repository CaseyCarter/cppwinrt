#include "pch.h"
#include "catch.hpp"
#include "guid_compare.h"

#pragma warning(disable:4471) // a forward declaration of an unscoped enumeration must have an underlying type
#include <windows.foundation.h>

using namespace winrt;
using namespace Windows::Foundation;
using namespace Windows::UI::Xaml::Interop;
using namespace Windows::Web::Http::Headers;

namespace
{
    // I used midlrt to generate IReference<T> pinterfaces for the Numerics types and "manually" obtain their GUIDs.
    constexpr GUID ireference_matrix3x2 { 0x76358cfd, 0x2cbd, 0x525b,{ 0xa4, 0x9e, 0x90, 0xee, 0x18, 0x24, 0x7b, 0x71 } };
    constexpr GUID ireference_matrix4x4 { 0xdacbffdc, 0x68ef, 0x5fd0,{ 0xb6, 0x57, 0x78, 0x2d, 0x0a, 0xc9, 0x80, 0x7e } };
    constexpr GUID ireference_plane     { 0x46d542a1, 0x52f7, 0x58e7,{ 0xac, 0xfc, 0x9a, 0x6d, 0x36, 0x4d, 0xa0, 0x22 } };
    constexpr GUID ireference_quaternion{ 0xb27004bb, 0xc014, 0x5dce,{ 0x9a, 0x21, 0x79, 0x9c, 0x5a, 0x3c, 0x14, 0x61 } };
    constexpr GUID ireference_vector2   { 0x48f6a69e, 0x8465, 0x57ae,{ 0x94, 0x00, 0x97, 0x64, 0x08, 0x7f, 0x65, 0xad } };
    constexpr GUID ireference_vector3   { 0x1ee770ff, 0xc954, 0x59ca,{ 0xa7, 0x54, 0x61, 0x99, 0xa9, 0xbe, 0x28, 0x2c } };
    constexpr GUID ireference_vector4   { 0xa5e843c9, 0xed20, 0x5339,{ 0x8f, 0x8d, 0x9f, 0xe4, 0x04, 0xcf, 0x36, 0x54 } };
}

static_assert(guid_equal(guid_of<IReference<Numerics::float2>>(), ireference_vector2));
static_assert(guid_equal(guid_of<IReference<Numerics::float3>>(), ireference_vector3));
static_assert(guid_equal(guid_of<IReference<Numerics::float4>>(), ireference_vector4));
static_assert(guid_equal(guid_of<IReference<Numerics::float3x2>>(), ireference_matrix3x2));
static_assert(guid_equal(guid_of<IReference<Numerics::float4x4>>(), ireference_matrix4x4));
static_assert(guid_equal(guid_of<IReference<Numerics::plane>>(), ireference_plane));
static_assert(guid_equal(guid_of<IReference<Numerics::quaternion>>(), ireference_quaternion));

static_assert(guid_equal(guid_of<IReference<bool>>(), __uuidof(::ABI::Windows::Foundation::IReference<bool>)));
static_assert(guid_equal(guid_of<IReference<uint8_t>>(), __uuidof(::ABI::Windows::Foundation::IReference<uint8_t>)));
static_assert(guid_equal(guid_of<IReference<int16_t>>(), __uuidof(::ABI::Windows::Foundation::IReference<int16_t>)));
static_assert(guid_equal(guid_of<IReference<uint32_t>>(), __uuidof(::ABI::Windows::Foundation::IReference<uint32_t>)));
static_assert(guid_equal(guid_of<IReference<int32_t>>(), __uuidof(::ABI::Windows::Foundation::IReference<int32_t>)));
static_assert(guid_equal(guid_of<IReference<uint64_t>>(), __uuidof(::ABI::Windows::Foundation::IReference<uint64_t>)));
static_assert(guid_equal(guid_of<IReference<int64_t>>(), __uuidof(::ABI::Windows::Foundation::IReference<int64_t>)));
static_assert(guid_equal(guid_of<IReference<float>>(), __uuidof(::ABI::Windows::Foundation::IReference<float>)));
static_assert(guid_equal(guid_of<IReference<double>>(), __uuidof(::ABI::Windows::Foundation::IReference<double>)));
static_assert(guid_equal(guid_of<IReference<GUID>>(), __uuidof(::ABI::Windows::Foundation::IReference<GUID>)));

static_assert(guid_equal(guid_of<IReference<winrt::Windows::Foundation::Point>>(), __uuidof(::ABI::Windows::Foundation::IReference<::ABI::Windows::Foundation::Point>)));
static_assert(guid_equal(guid_of<IReference<winrt::Windows::Foundation::Rect>>(), __uuidof(::ABI::Windows::Foundation::IReference<::ABI::Windows::Foundation::Rect>)));

static_assert(guid_equal(guid_of<IReference<winrt::Windows::Foundation::DateTime>>(), __uuidof(::ABI::Windows::Foundation::IReference<::ABI::Windows::Foundation::DateTime>)));
static_assert(guid_equal(guid_of<IReference<winrt::Windows::Foundation::TimeSpan>>(), __uuidof(::ABI::Windows::Foundation::IReference<::ABI::Windows::Foundation::TimeSpan>)));

struct my_struct
{
    int cool_factor; 
    double salary; 
};

enum my_enum
{
    double_plus_bad,
    double_bad,
    bad,
    good,
    plus_good,
    double_plus_good
};

namespace winrt::impl
{
    template <>
    struct name<my_enum>
    {
        static constexpr auto & value{ L"my_enum" };
        static constexpr auto & data{ "my_enum" };
    };

    template <>
    struct signature<my_enum>
    {
        static constexpr auto data{ category_signature<enum_category, my_enum>::data };
    };

    template <>
    struct name<my_struct>
    {
        static constexpr auto & value{ L"my_struct" };
        static constexpr auto & data{ "my_struct" };
    };

    template <>
    struct signature<my_struct>
    {
        static constexpr auto data{ category_signature<struct_category<int, double>, my_struct>::data };
    };
}

TEST_CASE("IReference, constructor and getter")
{
    uint64_t val_uint64 = 100;
    uint64_t const & ref_uint64 = val_uint64;
    IReference<uint64_t> obj_uint64(ref_uint64);
    REQUIRE(obj_uint64.Value() == 100);

    hstring val_hstring = L"Everything is awesome";
    IReference<hstring> obj_hstring(val_hstring);
    REQUIRE(obj_hstring.Value() == L"Everything is awesome");

    my_struct val_user_struct = { 10, 101010.0 };
    IReference<my_struct> obj_user_struct(val_user_struct);
    my_struct fetched_user_struct = obj_user_struct.Value();
    REQUIRE(fetched_user_struct.cool_factor == 10);
    REQUIRE(fetched_user_struct.salary == 101010.0);

    my_enum val_user_enum = plus_good;
    IReference<my_enum> obj_user_enum(val_user_enum);
    my_enum fetched_user_enum = obj_user_enum.Value();
    REQUIRE(fetched_user_enum == plus_good);

    // Test a struct type that has both an enum and hstring member
    TypeName val_xaml_struct = { L"Super cool type", TypeKind::Primitive };
    IReference<TypeName> obj_xaml_struct(val_xaml_struct);
    TypeName fetched_xaml_struct = obj_xaml_struct.Value();
    REQUIRE(fetched_xaml_struct.Kind == TypeKind::Primitive);
    REQUIRE(fetched_xaml_struct.Name == L"Super cool type");

    // Re-enable once we support IReferenceArray
    //array_view<DateTime const> val_date_array = { {100}, {200} };
    //IReference<array_view<DateTime const>> obj_date_array(val_date_array);
    //array_view<DateTime const>  fetched_date_array = *obj_date_array;
    //REQUIRE(fetched_date_array[1].UniversalTime == 200);
    //REQUIRE(fetched_date_array[2].UniversalTime == 200);

    //array_view<int32_t const> val_int_array = { 1, 2, 3 };
    //IReference<array_view<int32_t const>> obj_int_array(val_int_array);
    //array_view<int32_t const> fetched_int_array = obj_int_array.value();
    //REQUIRE(fetched_int_array[0] == 1);
    //REQUIRE(fetched_int_array[1] == 2);
    //REQUIRE(fetched_int_array[2] == 3);
}

TEST_CASE("IReference, set WinRT runtime class property")
{
    HttpContentDispositionHeaderValue value(L"inline");
    value.Size(200);
}