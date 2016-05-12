#include "pch.h"
#include "catch.hpp"

using namespace winrt;
using namespace Windows::Foundation;

static_assert(std::is_same_v<abi_arg_in<int>, int>, "fail");
static_assert(std::is_same_v<abi_arg_out<int>, int *>, "fail");

static_assert(std::is_same_v<abi_arg_in<IUriRuntimeClass>, ABI::Windows::Foundation::IUriRuntimeClass *>, "fail");
static_assert(std::is_same_v<abi_arg_out<IUriRuntimeClass>, ABI::Windows::Foundation::IUriRuntimeClass **>, "fail");
