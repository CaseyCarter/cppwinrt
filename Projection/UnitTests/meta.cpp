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
static_assert(std::is_same_v<put_abi_t<IUriRuntimeClass>, ::IUnknown **>, "fail");
