#include "pch.h"
#include "catch.hpp"

#include <chrono>

using namespace winrt;
using namespace Windows::Foundation;
using namespace Windows::UI::Xaml::Interop;
using namespace Windows::Web::Http::Headers;

using namespace std::literals::chrono_literals;

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

    hstring val_hstring = hstring{ L"Everything is awesome" };
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
    TypeName val_xaml_struct = { hstring{ L"Super cool type"}, TypeKind::Primitive };
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