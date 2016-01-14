#include "stdafx.h"

#define CATCH_CONFIG_MAIN
#include "catch.hpp"

using namespace winrt;
using namespace Windows::Foundation;

TEST_CASE("Instantiate URI type. Do valid/invalid As() calls")
{
    try
    {
        Initialize();

        Uri uri(L"http://kennykerr.ca/articles");
        
        REQUIRE_THROWS(uri.As<IMemoryBuffer>());
        REQUIRE_NOTHROW(uri.As<IUriRuntimeClass>());
    }
    catch (Exception ex)
    {
        FAIL(std::string("Exception during Uri constructor. Ex result is 0x") + std::to_string(ex.Result));
    }
}