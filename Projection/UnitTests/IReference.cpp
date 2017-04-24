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

namespace winrt::ABI::Windows::Foundation
{
    template <> struct __declspec(uuid("e5198cc8-2873-55f5-b0a1-84ff9e4aad62")) __declspec(novtable) IReference<uint8_t> : impl_IReference<uint8_t> {};
    template <> struct __declspec(uuid("fd416dfb-2a07-52eb-aae3-dfce14116c05")) __declspec(novtable) IReference<hstring> : impl_IReference<hstring> {};
    template <> struct __declspec(uuid("afa37cbd-31f7-495c-a85d-534B4f15969e")) __declspec(novtable) IReference<my_struct> : impl_IReference<my_struct> {};
    template <> struct __declspec(uuid("b8c904ef-43e9-4b77-82a0-5d65970960a4")) __declspec(novtable) IReference<my_enum> : impl_IReference<my_enum> {};
    template <> struct __declspec(uuid("01968daa-f6cc-42fd-b6f3-6c12cdf7df94")) __declspec(novtable) IReference<ABI::Windows::UI::Xaml::Interop::TypeName> : impl_IReference<ABI::Windows::UI::Xaml::Interop::TypeName> {};

    // Re-enable once we support IReferenceArray
    //template <> struct __declspec(uuid("1b8e9594-588e-5a07-9e65-0731a4c9a2db")) __declspec(novtable) IReference<array_view<DateTime const>> : impl_IReference<array_view<DateTime const>> {};
    //template <> struct __declspec(uuid("a6d080a5-b087-5bc2-9a9f-5cd687b4d1f7")) __declspec(novtable) IReference<array_view<int32_t const>> : impl_IReference<array_view<int32_t const>> {};
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