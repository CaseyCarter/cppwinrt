#include "pch.h"
#include "catch.hpp"

using namespace winrt;
using namespace Windows::Foundation;
using namespace Windows::System::Threading;

// Optimized coroutines with multiple suspend points are messing up move semantics
// DevDiv bug 504923 https://devdiv.visualstudio.com/DevDiv/_workitems?id=504923&_a=edit
#pragma optimize("", off)
std::future<void> test_agile_ref()
{
    Uri object(L"http://host/path");

    //
    // Here we're creating an agile_ref explicitly and using a traditional lambda variable capture
    // to pass it to the delegate.
    //

    agile_ref<Uri> ref = object;

    await ThreadPool::RunAsync([ref](auto && ...)
    {
        Uri object = ref.get();

        REQUIRE(object.ToString() == L"http://host/path");
    });

    //
    // Here's we're using the make_agile helper with generalized lambda capture to produce a
    // variable local to the lambda.
    //

    await ThreadPool::RunAsync([ref = make_agile(object)](auto && ...)
    {
        Uri object = ref.get();

        REQUIRE(object.ToString() == L"http://host/path");
    });
}

TEST_CASE("agile_ref")
{
    test_agile_ref().get();
}
