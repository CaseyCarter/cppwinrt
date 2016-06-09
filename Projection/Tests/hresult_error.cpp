#include "pch.h"
#include "catch.hpp"

using namespace winrt;
using namespace Windows::Foundation;

TEST_CASE("hresult,S_OK")
{
    // This won't throw

    check_hresult(S_OK);
}

TEST_CASE("hresult,S_FALSE")
{
    // We consider S_FALSE a false positive - the caller can handle it explicitly.

    // Incoming error...

    try
    {
        check_hresult(S_FALSE);
        FAIL(L"Previous line should throw");
    }
    catch (hresult_error const & e)
    {
        REQUIRE(S_FALSE == e.code());
    }

    // Outgoing error...

    try
    {
        throw hresult_error(S_FALSE);
    }
    catch (...)
    {
        REQUIRE(S_FALSE == impl::to_hresult());
    }
}

TEST_CASE("hresult,restricted,consuming")
{
    // An error originates in a component and is consumed within C++/WinRT

    try
    {
        Uri uri(L"BAD");
        FAIL(L"Previous line should throw");
    }
    catch (hresult_invalid_argument const & e) // catching specific exception type
    {
        REQUIRE(E_INVALIDARG == e.code());
        REQUIRE(L"BAD is not a valid absolute URI." == e.message());
    }

    try
    {
        Uri uri(L"BAD");
        FAIL(L"Previous line should throw");
    }
    catch (hresult_error const & e) // catching generic exception type
    {
        REQUIRE(E_INVALIDARG == e.code());
        REQUIRE(L"BAD is not a valid absolute URI." == e.message());
    }
}

TEST_CASE("hresult,restricted,producing")
{
    // An original error raised within C++/WinRT

    try
    {
        throw hresult_invalid_argument(); // default restricted error info message
    }
    catch (hresult_invalid_argument const & e)
    {
        REQUIRE(E_INVALIDARG == e.code());
        REQUIRE(L"The parameter is incorrect." == e.message());
    }

    try
    {
        throw hresult_invalid_argument(hresult_error::from_abi); // no restricted error info at all
    }
    catch (hresult_invalid_argument const & e)
    {
        REQUIRE(E_INVALIDARG == e.code());
        REQUIRE(L"The parameter is incorrect." == e.message());
    }

    try
    {
        throw hresult_invalid_argument(L"Better luck next time!"); // custom message for restricted error info message
    }
    catch (hresult_invalid_argument const & e)
    {
        REQUIRE(E_INVALIDARG == e.code());
        REQUIRE(L"Better luck next time!" == e.message());
    }

    try
    {
        WINRT_RoOriginateError(E_INVALIDARG, get(hstring_ref(L"Correctly matched error info")));
        throw hresult_invalid_argument(hresult_error::from_abi); // no restricted error info at all
    }
    catch (hresult_invalid_argument const & e)
    {
        REQUIRE(E_INVALIDARG == e.code());
        REQUIRE(L"Correctly matched error info" == e.message());
    }

    try
    {
        WINRT_RoOriginateError(E_FAIL, get(hstring_ref(L"Incorrectly matched error info")));
        throw hresult_invalid_argument(hresult_error::from_abi); // no restricted error info at all
    }
    catch (hresult_invalid_argument const & e)
    {
        REQUIRE(E_INVALIDARG == e.code());
        REQUIRE(L"The parameter is incorrect." == e.message());
    }
}

struct SamplePropagate : implements<SamplePropagate, IStringable>
{
    hstring ToString()
    {
        Uri uri(L"BAD");
        return uri.ToString();
    }
};

TEST_CASE("hresult,propagate,implements")
{
    // An error raised within an implementation (component) that crosses the ABI and consumed within C++/WinRT.
    // This is the same as the URI case above, but implemented purely within the projection.

    try
    {
        IStringable value = make<SamplePropagate>();
        value.ToString();
    }
    catch (hresult_invalid_argument const & e)
    {
        REQUIRE(E_INVALIDARG == e.code());
        REQUIRE(L"BAD is not a valid absolute URI." == e.message());
    }
}

struct SampleOriginate : implements<SampleOriginate, IStringable>
{
    hstring ToString()
    {
        throw hresult_access_denied(L"Not so fast!");
    }
};

TEST_CASE("hresult,originate,implements")
{
    // An error raised within an implementation (component) that crosses the ABI and consumed within C++/WinRT.
    // In this case we're not merely propagating an error. We're actually raising an original error originating
    // in this implementation.

    try
    {
        IStringable value = make<SampleOriginate>();
        value.ToString();
    }
    catch (hresult_access_denied const & e)
    {
        REQUIRE(E_ACCESSDENIED == e.code());
        REQUIRE(L"Not so fast!" == e.message());
    }
}

TEST_CASE("hresult_access_denied")
{
    // An original error raised within C++/WinRT

    try
    {
        throw hresult_access_denied(); // default restricted error info message
    }
    catch (hresult_access_denied const & e)
    {
        REQUIRE(E_ACCESSDENIED == e.code());
        REQUIRE(L"Access is denied." == e.message());
    }

    try
    {
        throw hresult_access_denied(hresult_error::from_abi); // no restricted error info at all
    }
    catch (hresult_access_denied const & e)
    {
        REQUIRE(E_ACCESSDENIED == e.code());
        REQUIRE(L"Access is denied." == e.message());
    }

    try
    {
        throw hresult_access_denied(L"test message"); // custom message for restricted error info message
    }
    catch (hresult_access_denied const & e)
    {
        REQUIRE(E_ACCESSDENIED == e.code());
        REQUIRE(L"test message" == e.message());
    }
}

TEST_CASE("hresult_wrong_thread")
{
    // An original error raised within C++/WinRT

    try
    {
        throw hresult_wrong_thread(); // default restricted error info message
    }
    catch (hresult_wrong_thread const & e)
    {
        REQUIRE(RPC_E_WRONG_THREAD == e.code());
        REQUIRE(L"The application called an interface that was marshalled for a different thread." == e.message());
    }

    try
    {
        throw hresult_wrong_thread(hresult_error::from_abi); // no restricted error info at all
    }
    catch (hresult_wrong_thread const & e)
    {
        REQUIRE(RPC_E_WRONG_THREAD == e.code());
        REQUIRE(L"The application called an interface that was marshalled for a different thread." == e.message());
    }

    try
    {
        throw hresult_wrong_thread(L"test message"); // custom message for restricted error info message
    }
    catch (hresult_wrong_thread const & e)
    {
        REQUIRE(RPC_E_WRONG_THREAD == e.code());
        REQUIRE(L"test message" == e.message());
    }
}

TEST_CASE("hresult_not_implemented")
{
    // An original error raised within C++/WinRT

    try
    {
        throw hresult_not_implemented(); // default restricted error info message
    }
    catch (hresult_not_implemented const & e)
    {
        REQUIRE(E_NOTIMPL == e.code());
        REQUIRE(L"Not implemented" == e.message());
    }

    try
    {
        throw hresult_not_implemented(hresult_error::from_abi); // no restricted error info at all
    }
    catch (hresult_not_implemented const & e)
    {
        REQUIRE(E_NOTIMPL == e.code());
        REQUIRE(L"Not implemented" == e.message());
    }

    try
    {
        throw hresult_not_implemented(L"test message"); // custom message for restricted error info message
    }
    catch (hresult_not_implemented const & e)
    {
        REQUIRE(E_NOTIMPL == e.code());
        REQUIRE(L"test message" == e.message());
    }
}

TEST_CASE("hresult_invalid_argument")
{
    // An original error raised within C++/WinRT

    try
    {
        throw hresult_invalid_argument(); // default restricted error info message
    }
    catch (hresult_invalid_argument const & e)
    {
        REQUIRE(E_INVALIDARG == e.code());
        REQUIRE(L"The parameter is incorrect." == e.message());
    }

    try
    {
        throw hresult_invalid_argument(hresult_error::from_abi); // no restricted error info at all
    }
    catch (hresult_invalid_argument const & e)
    {
        REQUIRE(E_INVALIDARG == e.code());
        REQUIRE(L"The parameter is incorrect." == e.message());
    }

    try
    {
        throw hresult_invalid_argument(L"test message"); // custom message for restricted error info message
    }
    catch (hresult_invalid_argument const & e)
    {
        REQUIRE(E_INVALIDARG == e.code());
        REQUIRE(L"test message" == e.message());
    }
}

TEST_CASE("hresult_out_of_bounds")
{
    // An original error raised within C++/WinRT

    try
    {
        throw hresult_out_of_bounds(); // default restricted error info message
    }
    catch (hresult_out_of_bounds const & e)
    {
        REQUIRE(E_BOUNDS == e.code());
        REQUIRE(L"The operation attempted to access data outside the valid range" == e.message());
    }

    try
    {
        throw hresult_out_of_bounds(hresult_error::from_abi); // no restricted error info at all
    }
    catch (hresult_out_of_bounds const & e)
    {
        REQUIRE(E_BOUNDS == e.code());
        REQUIRE(L"The operation attempted to access data outside the valid range" == e.message());
    }

    try
    {
        throw hresult_out_of_bounds(L"test message"); // custom message for restricted error info message
    }
    catch (hresult_out_of_bounds const & e)
    {
        REQUIRE(E_BOUNDS == e.code());
        REQUIRE(L"test message" == e.message());
    }
}

TEST_CASE("hresult_no_interface")
{
    // An original error raised within C++/WinRT

    try
    {
        throw hresult_no_interface(); // default restricted error info message
    }
    catch (hresult_no_interface const & e)
    {
        REQUIRE(E_NOINTERFACE == e.code());
        REQUIRE(L"No such interface supported" == e.message());
    }

    try
    {
        throw hresult_no_interface(hresult_error::from_abi); // no restricted error info at all
    }
    catch (hresult_no_interface const & e)
    {
        REQUIRE(E_NOINTERFACE == e.code());
        REQUIRE(L"No such interface supported" == e.message());
    }

    try
    {
        throw hresult_no_interface(L"test message"); // custom message for restricted error info message
    }
    catch (hresult_no_interface const & e)
    {
        REQUIRE(E_NOINTERFACE == e.code());
        REQUIRE(L"test message" == e.message());
    }
}

TEST_CASE("hresult_disconnected")
{
    // An original error raised within C++/WinRT

    try
    {
        throw hresult_disconnected(); // default restricted error info message
    }
    catch (hresult_disconnected const & e)
    {
        REQUIRE(RPC_E_DISCONNECTED == e.code());
        REQUIRE(L"The object invoked has disconnected from its clients." == e.message());
    }

    try
    {
        throw hresult_disconnected(hresult_error::from_abi); // no restricted error info at all
    }
    catch (hresult_disconnected const & e)
    {
        REQUIRE(RPC_E_DISCONNECTED == e.code());
        REQUIRE(L"The object invoked has disconnected from its clients." == e.message());
    }

    try
    {
        throw hresult_disconnected(L"test message"); // custom message for restricted error info message
    }
    catch (hresult_disconnected const & e)
    {
        REQUIRE(RPC_E_DISCONNECTED == e.code());
        REQUIRE(L"test message" == e.message());
    }
}

TEST_CASE("hresult, bad_alloc")
{
    try
    {
        throw std::bad_alloc();
    }
    catch (...)
    {
        REQUIRE(E_OUTOFMEMORY == impl::to_hresult());
    }
}

TEST_CASE("hresult, out_of_range")
{
    try
    {
        throw std::out_of_range("");
    }
    catch (...)
    {
        REQUIRE(E_BOUNDS == impl::to_hresult());
    }
}

TEST_CASE("hresult, invalid_argument")
{
    try
    {
        throw std::invalid_argument("");
    }
    catch (...)
    {
        REQUIRE(E_INVALIDARG == impl::to_hresult());
    }
}

TEST_CASE("hresult, exception")
{
    try
    {
        throw std::exception();
    }
    catch (...)
    {
        REQUIRE(E_FAIL == impl::to_hresult());
    }
}
