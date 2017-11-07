#include "pch.h"
#include "catch.hpp"

#pragma warning(disable: 4505)

using namespace winrt;
using namespace Windows::Foundation;

template<typename T>
using get_abi_t = decltype(get_abi(std::declval<T&>()));

template<typename T>
using put_abi_t = decltype(put_abi(std::declval<T&>()));

static_assert(std::is_same_v<get_abi_t<int>, int>, "fail");
static_assert(std::is_same_v<put_abi_t<int>, int *>, "fail");

static_assert(std::is_same_v<get_abi_t<IUriRuntimeClass>, ::IUnknown *>, "fail");
static_assert(std::is_same_v<put_abi_t<IUriRuntimeClass>, void**>, "fail");

namespace
{
    struct __declspec(uuid("0C9DCED5-6436-495F-B422-EBA74DC23CB8")) IFoo : ::IInspectable {};
    struct __declspec(uuid("B5D6112A-75F6-454C-BE86-8F3AE4155D45")) IFoo2 : ::IInspectable {};
    struct __declspec(uuid("1E4EA9CB-3146-4C2C-9E50-25065394F541")) IBar : ::IInspectable {};
    struct __declspec(uuid("2BD9AE4B-9B03-4766-8583-215535BE5125")) IBar2 : ::IInspectable {};

    struct Foo : implements<Foo, IFoo, IFoo2> {};
    struct Bar : implements<Bar, IBar, IBar2> {};

    static_assert(impl::uncloaked_interfaces<composable, composing>() == 0);
    static_assert(impl::uncloaked_interfaces<composable, IFoo, composing, IBar>() == 2);
    static_assert(impl::uncloaked_interfaces<cloaked<IFoo>, IBar>() == 1);
    static_assert(impl::uncloaked_interfaces<IFoo, Bar>() == 3);

    static_assert(impl::is_implements<Foo>());
    
    static_assert(std::is_same<impl::nested_implements<IFoo, Bar, IFoo2>::type, Bar>::value);
    static_assert(std::is_same<impl::base_implements<Foo, IFoo>::type, impl::root_implements<Foo, IFoo>>::value);
    static_assert(std::is_same<impl::base_implements<Foo, IFoo, Bar, IFoo2>::type, Bar>::value);

    static_assert(std::is_same<impl::first_interface<IFoo, IFoo2>::type, IFoo>::value);
    static_assert(std::is_same<impl::first_interface<IFoo, Bar, IFoo2>::type, IFoo>::value);
    static_assert(std::is_same<impl::first_interface<Bar, IFoo, IFoo2>::type, IBar>::value);
}
