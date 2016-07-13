#include "pch.h"
#include "catch.hpp"

using namespace winrt;
using namespace Windows::Media::Capture;
using namespace Windows::Media::Devices;
using namespace Windows::System::Threading;

std::future<void> test_agile_ref()
{
    MediaCapture object;

    //
    // Here we're creating an agile_ref explicitly and using a traditional lambda variable capture
    // to pass it to the delegate.
    //

    agile_ref<MediaCapture> ref = object;

    await ThreadPool::RunAsync([ref](auto && ...)
    {
        MediaCapture object = ref.get();

        REQUIRE(object.CameraStreamState() == CameraStreamState::NotStreaming);
    });

    //
    // Here's we're using the make_agile helper with generalized lambda capture to produce a
    // variable local to the lambda.
    //

    await ThreadPool::RunAsync([ref = make_agile(object)](auto && ...)
    {
        MediaCapture object = ref.get();

        REQUIRE(object.CameraStreamState() == CameraStreamState::NotStreaming);
    });
}

TEST_CASE("agile_ref")
{
    test_agile_ref().get();
}
