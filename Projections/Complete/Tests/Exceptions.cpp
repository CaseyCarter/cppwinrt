#include "pch.h"
#include "catch.hpp"

TEST_CASE("Exceptions,S_OK")
{
    // This won't throw.

    winrt::check_hresult(S_OK);
}

TEST_CASE("Exceptions,E_FAIL")
{
    // This represents the general case for HRESULTs with no specific mapping.

    // Incoming error...

    try
    {
        winrt::check_hresult(E_FAIL);
        FAIL(L"Previous line should throw");
    }
    catch (winrt::hresult_error const & e)
    {
        REQUIRE(E_FAIL == e.code().value());
    }

    // Outgoing error...

    try
    {
        throw winrt::hresult_error(E_FAIL);
    }
    catch (...)
    {
        REQUIRE(E_FAIL == winrt::impl::to_hresult());
    }
}

TEST_CASE("Exceptions,S_FALSE")
{
    // We consider S_FALSE a false positive - the caller can handle it explicitly if so desired.

    // Incoming error...

    try
    {
        winrt::check_hresult(S_FALSE);
        FAIL(L"Previous line should throw");
    }
    catch (winrt::hresult_error const & e)
    {
        REQUIRE(S_FALSE == e.code().value());
    }

    // Outgoing error...

    try
    {
        throw winrt::hresult_error(S_FALSE);
    }
    catch (...)
    {
        REQUIRE(S_FALSE == winrt::impl::to_hresult());
    }
}

TEST_CASE("Exceptions,E_OUTOFMEMORY")
{
    // E_OUTOFMEMORY maps to std::bad_alloc.

    // Incoming error...

    try
    {
        winrt::check_hresult(E_OUTOFMEMORY);
        FAIL(L"Previous line should throw");
    }
    catch (std::bad_alloc const &) {}

    // Outgoing error...

    try
    {
        throw std::bad_alloc();
    }
    catch (...)
    {
        REQUIRE(E_OUTOFMEMORY == winrt::impl::to_hresult());
    }
}

TEST_CASE("Exceptions,E_BOUNDS")
{
    // E_BOUNDS maps to std::out_of_range.

    // Incoming error...

    try
    {
        winrt::check_hresult(E_BOUNDS);
        FAIL(L"Previous line should throw");
    }
    catch (std::out_of_range const &) {}

    // Outgoing error...

    try
    {
        throw std::out_of_range("");
    }
    catch (...)
    {
        REQUIRE(E_BOUNDS == winrt::impl::to_hresult());
    }
}

TEST_CASE("Exceptions,E_INVALIDARG")
{
    // E_INVALIDARG maps to std::out_of_range.

    // Incoming error...

    try
    {
        winrt::check_hresult(E_INVALIDARG);
        FAIL(L"Previous line should throw");
    }
    catch (std::invalid_argument const &) {}

    // Outgoing error...

    try
    {
        throw std::invalid_argument("");
    }
    catch (...)
    {
        REQUIRE(E_INVALIDARG == winrt::impl::to_hresult());
    }
}
