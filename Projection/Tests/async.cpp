#include "pch.h"
#include "catch.hpp"

using namespace winrt;
using namespace Windows::Foundation;
using namespace std::chrono;

//
// These tests confirm that these non-suspending coroutines produce the correct types, complete immediately,
// produce the expected results, and invoke the Completed handler even when the coroutine has already completed.
// These coroutines also check for cancelation and throw if requested since these tests should not be canceled.
// The Cancel_IAsyncXxxx tests cover successful cancelation a bit further down.
//

namespace
{
    IAsyncAction NoSuspend_IAsyncAction()
    {
        co_await 0s;

        auto cancel = co_await get_cancellation_token;

        if (cancel())
        {
            throw hresult_error(E_UNEXPECTED);
        }
    }

    IAsyncActionWithProgress<double> NoSuspend_IAsyncActionWithProgress()
    {
        co_await 0s;

        auto cancel = co_await get_cancellation_token;

        if (cancel())
        {
            throw hresult_error(E_UNEXPECTED);
        }
    }

    IAsyncOperation<uint32_t> NoSuspend_IAsyncOperation()
    {
        co_await 0s;

        auto cancel = co_await get_cancellation_token;

        if (cancel())
        {
            throw hresult_error(E_UNEXPECTED);
        }

        return 123;
    }

    IAsyncOperationWithProgress<uint64_t, uint64_t> NoSuspend_IAsyncOperationWithProgress()
    {
        co_await 0s;

        auto cancel = co_await get_cancellation_token;

        if (cancel())
        {
            throw hresult_error(E_UNEXPECTED);
        }

        return 456;
    }
}

TEST_CASE("async, NoSuspend_IAsyncAction")
{
    IAsyncAction async = NoSuspend_IAsyncAction();
    REQUIRE(async.Status() == AsyncStatus::Completed);
    REQUIRE(async.ErrorCode() == S_OK);
    REQUIRE(async.Id() == 1);
    async.GetResults(); // should not throw

    bool completed = false;
    bool objectMatches = false;
    bool statusMatches = false;

    async.Completed([&](const IAsyncAction & sender, AsyncStatus status)
    {
        completed = true;
        objectMatches = (async == sender);
        statusMatches = (status == AsyncStatus::Completed);
    });

    REQUIRE(completed);
    REQUIRE(objectMatches);
    REQUIRE(statusMatches);

    REQUIRE_THROWS_AS(async.Completed([&](auto && ...) {}), hresult_illegal_delegate_assignment);

    async.Close();
    async.Cancel();
    REQUIRE(async.Status() == AsyncStatus::Completed);
}

TEST_CASE("async, NoSuspend_IAsyncActionWithProgress")
{
    IAsyncActionWithProgress<double> async = NoSuspend_IAsyncActionWithProgress();
    REQUIRE(async.Status() == AsyncStatus::Completed);
    REQUIRE(async.ErrorCode() == S_OK);
    REQUIRE(async.Id() == 1);
    async.GetResults(); // should not throw

    bool completed = false;
    bool objectMatches = false;
    bool statusMatches = false;

    async.Completed([&](const IAsyncActionWithProgress<double> & sender, AsyncStatus status)
    {
        completed = true;
        objectMatches = (async == sender);
        statusMatches = (status == AsyncStatus::Completed);
    });

    REQUIRE(completed);
    REQUIRE(objectMatches);
    REQUIRE(statusMatches);

    REQUIRE_THROWS_AS(async.Completed([&](auto && ...) {}), hresult_illegal_delegate_assignment);

    async.Close();
    async.Cancel();
    REQUIRE(async.Status() == AsyncStatus::Completed);
}

TEST_CASE("async, NoSuspend_IAsyncOperation")
{
    IAsyncOperation<uint32_t> async = NoSuspend_IAsyncOperation();
    REQUIRE(async.Status() == AsyncStatus::Completed);
    REQUIRE(async.ErrorCode() == S_OK);
    REQUIRE(async.Id() == 1);
    REQUIRE(async.GetResults() == 123);

    bool completed = false;
    bool objectMatches = false;
    bool statusMatches = false;

    async.Completed([&](const IAsyncOperation<uint32_t> & sender, AsyncStatus status)
    {
        completed = true;
        objectMatches = (async == sender);
        statusMatches = (status == AsyncStatus::Completed);
    });

    REQUIRE(completed);
    REQUIRE(objectMatches);
    REQUIRE(statusMatches);

    REQUIRE_THROWS_AS(async.Completed([&](auto && ...) {}), hresult_illegal_delegate_assignment);

    async.Close();
    async.Cancel();
    REQUIRE(async.Status() == AsyncStatus::Completed);
}

TEST_CASE("async, NoSuspend_IAsyncOperationWithProgress")
{
    IAsyncOperationWithProgress<uint64_t, uint64_t> async = NoSuspend_IAsyncOperationWithProgress();
    REQUIRE(async.Status() == AsyncStatus::Completed);
    REQUIRE(async.ErrorCode() == S_OK);
    REQUIRE(async.Id() == 1);
    REQUIRE(async.GetResults() == 456);

    bool completed = false;
    bool objectMatches = false;
    bool statusMatches = false;

    async.Completed([&](const IAsyncOperationWithProgress<uint64_t, uint64_t> & sender, AsyncStatus status)
    {
        completed = true;
        objectMatches = (async == sender);
        statusMatches = (status == AsyncStatus::Completed);
    });

    REQUIRE(completed);
    REQUIRE(objectMatches);
    REQUIRE(statusMatches);

    REQUIRE_THROWS_AS(async.Completed([&](auto && ...) {}), hresult_illegal_delegate_assignment);

    async.Close();
    async.Cancel();
    REQUIRE(async.Status() == AsyncStatus::Completed);
}

//
// These tests confirm that these coroutines do in fact suspend, can be queried before and after completion,
// and thus allow both Progress and Completed to be hooked up prior to completion. They all use an auto-reset
// event to coordinate the coroutine's initial resumption and completion to allow for predictable testing
// of the state machine.
//

namespace
{
    IAsyncAction Suspend_IAsyncAction(HANDLE go)
    {
        co_await resume_on_signal(go);
    }

    IAsyncActionWithProgress<double> Suspend_IAsyncActionWithProgress(HANDLE go)
    {
        co_await resume_on_signal(go);
        auto progress = co_await get_progress_token;
        progress(789.0);
    }

    IAsyncOperation<uint32_t> Suspend_IAsyncOperation(HANDLE go)
    {
        co_await resume_on_signal(go);
        return 123;
    }

    IAsyncOperationWithProgress<uint64_t, uint64_t> Suspend_IAsyncOperationWithProgress(HANDLE go)
    {
        co_await resume_on_signal(go);
        auto progress = co_await get_progress_token;
        progress(987);
        return 456;
    }

    struct event_traits : handle_traits<HANDLE>
    {
        static void close(type value) noexcept
        {
            WINRT_VERIFY(CloseHandle(value));
        }
    };

    using event_handle = handle<event_traits>;
}

TEST_CASE("async, Suspend_IAsyncAction")
{
    event_handle event = CreateEvent(nullptr, false, false, nullptr);
    IAsyncAction async = Suspend_IAsyncAction(get(event));
    REQUIRE(async.Status() == AsyncStatus::Started);
    REQUIRE_THROWS_AS(async.Close(), hresult_illegal_state_change);

    bool completed = false;

    async.Completed([&](const IAsyncAction & sender, AsyncStatus status)
    {
        completed = true;
        REQUIRE(async == sender);
        REQUIRE(status == AsyncStatus::Completed);
        SetEvent(get(event)); // signal completion
    });

    REQUIRE_THROWS_AS(async.Completed([&](auto && ...) {}), hresult_illegal_delegate_assignment);

    SetEvent(get(event)); // signal async to run
    REQUIRE(WaitForSingleObject(get(event), INFINITE) == WAIT_OBJECT_0); // wait for async to complete
    REQUIRE(completed);
    REQUIRE(async.Status() == AsyncStatus::Completed);
    REQUIRE(async.ErrorCode() == S_OK);
}

TEST_CASE("async, Suspend_IAsyncActionWithProgress")
{
    event_handle event = CreateEvent(nullptr, false, false, nullptr);
    IAsyncActionWithProgress<double> async = Suspend_IAsyncActionWithProgress(get(event));
    REQUIRE(async.Status() == AsyncStatus::Started);
    REQUIRE_THROWS_AS(async.Close(), hresult_illegal_state_change);

    bool completed = false;
    bool progress = false;

    async.Completed([&](const IAsyncActionWithProgress<double> & sender, AsyncStatus status)
    {
        completed = true;
        REQUIRE(async == sender);
        REQUIRE(status == AsyncStatus::Completed);
        SetEvent(get(event)); // signal completion
    });

    REQUIRE_THROWS_AS(async.Completed([&](auto && ...) {}), hresult_illegal_delegate_assignment);

    async.Progress([&](const IAsyncActionWithProgress<double> & sender, double value)
    {
        progress = true;
        REQUIRE(async == sender);
        REQUIRE(value == 789.0);
    });

    SetEvent(get(event)); // signal async to run
    REQUIRE(WaitForSingleObject(get(event), INFINITE) == WAIT_OBJECT_0); // wait for async to complete
    REQUIRE(completed);
    REQUIRE(progress);
    REQUIRE(async.Status() == AsyncStatus::Completed);
    REQUIRE(async.ErrorCode() == S_OK);
}

TEST_CASE("async, Suspend_IAsyncOperation")
{
    event_handle event = CreateEvent(nullptr, false, false, nullptr);
    IAsyncOperation<uint32_t> async = Suspend_IAsyncOperation(get(event));
    REQUIRE(async.Status() == AsyncStatus::Started);
    REQUIRE_THROWS_AS(async.Close(), hresult_illegal_state_change);

    bool completed = false;

    async.Completed([&](const IAsyncOperation<uint32_t> & sender, AsyncStatus status)
    {
        completed = true;
        REQUIRE(async == sender);
        REQUIRE(status == AsyncStatus::Completed);
        SetEvent(get(event)); // signal completion
    });

    REQUIRE_THROWS_AS(async.Completed([&](auto && ...) {}), hresult_illegal_delegate_assignment);

    SetEvent(get(event)); // signal async to run
    REQUIRE(WaitForSingleObject(get(event), INFINITE) == WAIT_OBJECT_0); // wait for async to complete
    REQUIRE(async.GetResults() == 123);
    REQUIRE(completed);
    REQUIRE(async.Status() == AsyncStatus::Completed);
    REQUIRE(async.ErrorCode() == S_OK);
}

TEST_CASE("async, Suspend_IAsyncOperationWithProgress")
{
    event_handle event = CreateEvent(nullptr, false, false, nullptr);
    IAsyncOperationWithProgress<uint64_t, uint64_t> async = Suspend_IAsyncOperationWithProgress(get(event));
    REQUIRE(async.Status() == AsyncStatus::Started);
    REQUIRE_THROWS_AS(async.Close(), hresult_illegal_state_change);

    bool completed = false;
    bool progress = false;

    async.Completed([&](const IAsyncOperationWithProgress<uint64_t, uint64_t> & sender, AsyncStatus status)
    {
        completed = true;
        REQUIRE(async == sender);
        REQUIRE(status == AsyncStatus::Completed);
        SetEvent(get(event)); // signal completion
    });

    REQUIRE_THROWS_AS(async.Completed([&](auto && ...) {}), hresult_illegal_delegate_assignment);

    async.Progress([&](const IAsyncOperationWithProgress<uint64_t, uint64_t> & sender, uint64_t value)
    {
        progress = true;
        REQUIRE(async == sender);
        REQUIRE(value == 987);
    });

    SetEvent(get(event)); // signal async to run
    REQUIRE(WaitForSingleObject(get(event), INFINITE) == WAIT_OBJECT_0); // wait for async to complete
    REQUIRE(async.GetResults() == 456);
    REQUIRE(completed);
    REQUIRE(progress);
    REQUIRE(async.Status() == AsyncStatus::Completed);
    REQUIRE(async.ErrorCode() == S_OK);
}

//
// These tests confirm how exceptions are propagated when an error occurs. The Completed handler is
// still called, GetResults will throw the exception, and ErrorCode will return the HRESULT *and* prep
// the WinRT error object for pickup.
//

namespace
{
    IAsyncAction Throw_IAsyncAction(HANDLE go)
    {
        co_await resume_on_signal(go);
        throw hresult_invalid_argument(L"Throw_IAsyncAction");
    }

    IAsyncActionWithProgress<double> Throw_IAsyncActionWithProgress(HANDLE go)
    {
        co_await resume_on_signal(go);
        throw hresult_invalid_argument(L"Throw_IAsyncActionWithProgress");
    }

    IAsyncOperation<uint32_t> Throw_IAsyncOperation(HANDLE go)
    {
        co_await resume_on_signal(go);
        throw hresult_invalid_argument(L"Throw_IAsyncOperation");
        return 123;
    }

    IAsyncOperationWithProgress<uint64_t, uint64_t> Throw_IAsyncOperationWithProgress(HANDLE go)
    {
        co_await resume_on_signal(go);
        throw hresult_invalid_argument(L"Throw_IAsyncOperationWithProgress");
        return 456;
    }
}

TEST_CASE("async, Throw_IAsyncAction")
{
    event_handle event = CreateEvent(nullptr, false, false, nullptr);
    IAsyncAction async = Throw_IAsyncAction(get(event));
    REQUIRE(async.Status() == AsyncStatus::Started);

    SetEvent(get(event)); // signal async to run
    while(async.Status() != AsyncStatus::Error);

    bool completed = false;

    async.Completed([&](const IAsyncAction & sender, AsyncStatus status)
    {
        completed = true;
        REQUIRE(async == sender);
        REQUIRE(status == AsyncStatus::Error);
    });

    REQUIRE(completed);

    try
    {
        async.GetResults();
        REQUIRE(false);
    }
    catch (hresult_invalid_argument const & e)
    {
        REQUIRE(e.message() == L"Throw_IAsyncAction");
    }

    try
    {
        impl::throw_hresult(async.ErrorCode());
    }
    catch (hresult_invalid_argument const & e)
    {
        REQUIRE(e.message() == L"Throw_IAsyncAction");
    }
}

TEST_CASE("async, Throw_IAsyncAction, 2")
{
    event_handle event = CreateEvent(nullptr, false, false, nullptr);
    IAsyncAction async = Throw_IAsyncAction(get(event));
    REQUIRE(async.Status() == AsyncStatus::Started);

    bool completed = false;

    async.Completed([&](const IAsyncAction & sender, AsyncStatus status)
    {
        completed = true;
        REQUIRE(async == sender);
        REQUIRE(status == AsyncStatus::Error);
        SetEvent(get(event));
    });

    SetEvent(get(event)); // signal async to run
    REQUIRE(WaitForSingleObject(get(event), INFINITE) == WAIT_OBJECT_0); // wait for async to be completed
    REQUIRE(async.Status() == AsyncStatus::Error);
    REQUIRE(completed);

    try
    {
        async.GetResults();
        REQUIRE(false);
    }
    catch (hresult_invalid_argument const & e)
    {
        REQUIRE(e.message() == L"Throw_IAsyncAction");
    }

    try
    {
        impl::throw_hresult(async.ErrorCode());
    }
    catch (hresult_invalid_argument const & e)
    {
        REQUIRE(e.message() == L"Throw_IAsyncAction");
    }
}

TEST_CASE("async, Throw_IAsyncActionWithProgress")
{
    event_handle event = CreateEvent(nullptr, false, false, nullptr);
    IAsyncActionWithProgress<double> async = Throw_IAsyncActionWithProgress(get(event));
    REQUIRE(async.Status() == AsyncStatus::Started);

    SetEvent(get(event)); // signal async to run
    while (async.Status() != AsyncStatus::Error);

    bool completed = false;

    async.Completed([&](const IAsyncActionWithProgress<double> & sender, AsyncStatus status)
    {
        completed = true;
        REQUIRE(async == sender);
        REQUIRE(status == AsyncStatus::Error);
    });

    REQUIRE(completed);

    try
    {
        async.GetResults();
        REQUIRE(false);
    }
    catch (hresult_invalid_argument const & e)
    {
        REQUIRE(e.message() == L"Throw_IAsyncActionWithProgress");
    }

    try
    {
        impl::throw_hresult(async.ErrorCode());
    }
    catch (hresult_invalid_argument const & e)
    {
        REQUIRE(e.message() == L"Throw_IAsyncActionWithProgress");
    }
}

TEST_CASE("async, Throw_IAsyncActionWithProgress, 2")
{
    event_handle event = CreateEvent(nullptr, false, false, nullptr);
    IAsyncActionWithProgress<double> async = Throw_IAsyncActionWithProgress(get(event));
    REQUIRE(async.Status() == AsyncStatus::Started);

    bool completed = false;

    async.Completed([&](const IAsyncActionWithProgress<double> & sender, AsyncStatus status)
    {
        completed = true;
        REQUIRE(async == sender);
        REQUIRE(status == AsyncStatus::Error);
        SetEvent(get(event));
    });

    SetEvent(get(event)); // signal async to run
    REQUIRE(WaitForSingleObject(get(event), INFINITE) == WAIT_OBJECT_0); // wait for async to be completed
    REQUIRE(async.Status() == AsyncStatus::Error);
    REQUIRE(completed);

    try
    {
        async.GetResults();
        REQUIRE(false);
    }
    catch (hresult_invalid_argument const & e)
    {
        REQUIRE(e.message() == L"Throw_IAsyncActionWithProgress");
    }

    try
    {
        impl::throw_hresult(async.ErrorCode());
    }
    catch (hresult_invalid_argument const & e)
    {
        REQUIRE(e.message() == L"Throw_IAsyncActionWithProgress");
    }
}

TEST_CASE("async, Throw_IAsyncOperation")
{
    event_handle event = CreateEvent(nullptr, false, false, nullptr);
    IAsyncOperation<uint32_t> async = Throw_IAsyncOperation(get(event));
    REQUIRE(async.Status() == AsyncStatus::Started);

    SetEvent(get(event)); // signal async to run
    while (async.Status() != AsyncStatus::Error);

    bool completed = false;

    async.Completed([&](const IAsyncOperation<uint32_t> & sender, AsyncStatus status)
    {
        completed = true;
        REQUIRE(async == sender);
        REQUIRE(status == AsyncStatus::Error);
    });

    REQUIRE(completed);

    try
    {
        async.GetResults();
        REQUIRE(false);
    }
    catch (hresult_invalid_argument const & e)
    {
        REQUIRE(e.message() == L"Throw_IAsyncOperation");
    }

    try
    {
        impl::throw_hresult(async.ErrorCode());
    }
    catch (hresult_invalid_argument const & e)
    {
        REQUIRE(e.message() == L"Throw_IAsyncOperation");
    }
}

TEST_CASE("async, Throw_IAsyncOperation, 2")
{
    event_handle event = CreateEvent(nullptr, false, false, nullptr);
    IAsyncOperation<uint32_t> async = Throw_IAsyncOperation(get(event));
    REQUIRE(async.Status() == AsyncStatus::Started);

    bool completed = false;

    async.Completed([&](const IAsyncOperation<uint32_t> & sender, AsyncStatus status)
    {
        completed = true;
        REQUIRE(async == sender);
        REQUIRE(status == AsyncStatus::Error);
        SetEvent(get(event));
    });

    SetEvent(get(event)); // signal async to run
    REQUIRE(WaitForSingleObject(get(event), INFINITE) == WAIT_OBJECT_0); // wait for async to be completed
    REQUIRE(async.Status() == AsyncStatus::Error);
    REQUIRE(completed);

    try
    {
        async.GetResults();
        REQUIRE(false);
    }
    catch (hresult_invalid_argument const & e)
    {
        REQUIRE(e.message() == L"Throw_IAsyncOperation");
    }

    try
    {
        impl::throw_hresult(async.ErrorCode());
    }
    catch (hresult_invalid_argument const & e)
    {
        REQUIRE(e.message() == L"Throw_IAsyncOperation");
    }
}

TEST_CASE("async, Throw_IAsyncOperationWithProgress")
{
    event_handle event = CreateEvent(nullptr, false, false, nullptr);
    IAsyncOperationWithProgress<uint64_t, uint64_t> async = Throw_IAsyncOperationWithProgress(get(event));
    REQUIRE(async.Status() == AsyncStatus::Started);

    SetEvent(get(event)); // signal async to run
    while (async.Status() != AsyncStatus::Error);

    bool completed = false;

    async.Completed([&](const IAsyncOperationWithProgress<uint64_t, uint64_t> & sender, AsyncStatus status)
    {
        completed = true;
        REQUIRE(async == sender);
        REQUIRE(status == AsyncStatus::Error);
    });

    REQUIRE(completed);

    try
    {
        async.GetResults();
        REQUIRE(false);
    }
    catch (hresult_invalid_argument const & e)
    {
        REQUIRE(e.message() == L"Throw_IAsyncOperationWithProgress");
    }

    try
    {
        impl::throw_hresult(async.ErrorCode());
    }
    catch (hresult_invalid_argument const & e)
    {
        REQUIRE(e.message() == L"Throw_IAsyncOperationWithProgress");
    }
}

TEST_CASE("async, Throw_IAsyncOperationWithProgress, 2")
{
    event_handle event = CreateEvent(nullptr, false, false, nullptr);
    IAsyncOperationWithProgress<uint64_t, uint64_t> async = Throw_IAsyncOperationWithProgress(get(event));
    REQUIRE(async.Status() == AsyncStatus::Started);

    bool completed = false;

    async.Completed([&](const IAsyncOperationWithProgress<uint64_t, uint64_t> & sender, AsyncStatus status)
    {
        completed = true;
        REQUIRE(async == sender);
        REQUIRE(status == AsyncStatus::Error);
        SetEvent(get(event));
    });

    SetEvent(get(event)); // signal async to run
    REQUIRE(WaitForSingleObject(get(event), INFINITE) == WAIT_OBJECT_0); // wait for async to be completed
    REQUIRE(async.Status() == AsyncStatus::Error);
    REQUIRE(completed);

    try
    {
        async.GetResults();
        REQUIRE(false);
    }
    catch (hresult_invalid_argument const & e)
    {
        REQUIRE(e.message() == L"Throw_IAsyncOperationWithProgress");
    }

    try
    {
        impl::throw_hresult(async.ErrorCode());
    }
    catch (hresult_invalid_argument const & e)
    {
        REQUIRE(e.message() == L"Throw_IAsyncOperationWithProgress");
    }
}

//
// These tests confirm cancelation behavior. These coroutines start by waiting for a signal, 
// call get_cancellation_token, check whether cancelation was requested, set the event to indicate
// to the calling test to acknowledge the cancelation. The calling test coordinates the signaling, 
// ensures the Cancel state was reached, and that GetResults has thrown hresult_illegal_method_call. 
//

namespace
{
    IAsyncAction Cancel_IAsyncAction(HANDLE go)
    {
        co_await resume_on_signal(go);

        auto cancel = co_await get_cancellation_token;

        REQUIRE(cancel());
        SetEvent(go); // signal cancelation
    }

    IAsyncActionWithProgress<double> Cancel_IAsyncActionWithProgress(HANDLE go)
    {
        co_await resume_on_signal(go);

        auto cancel = co_await get_cancellation_token;

        REQUIRE(cancel());
        SetEvent(go); // signal cancelation
    }

    IAsyncOperation<uint32_t> Cancel_IAsyncOperation(HANDLE go)
    {
        co_await resume_on_signal(go);

        auto cancel = co_await get_cancellation_token;

        REQUIRE(cancel());
        SetEvent(go); // signal cancelation
        return 123;
    }

    IAsyncOperationWithProgress<uint64_t, uint64_t> Cancel_IAsyncOperationWithProgress(HANDLE go)
    {
        co_await resume_on_signal(go);

        auto cancel = co_await get_cancellation_token;

        REQUIRE(cancel());
        SetEvent(go); // signal cancelation
        return 345;
    }
}

TEST_CASE("async, Cancel_IAsyncAction")
{
    event_handle event = CreateEvent(nullptr, false, false, nullptr);
    IAsyncAction async = Cancel_IAsyncAction(get(event));
    REQUIRE(async.Status() == AsyncStatus::Started);
    REQUIRE_THROWS_AS(async.GetResults(), hresult_illegal_method_call);

    async.Cancel();
    SetEvent(get(event)); // signal async to run
    REQUIRE(WaitForSingleObject(get(event), INFINITE) == WAIT_OBJECT_0); // wait for async to be canceled
    REQUIRE(async.Status() == AsyncStatus::Canceled);
    REQUIRE_THROWS_AS(async.GetResults(), hresult_canceled);
    REQUIRE(async.ErrorCode() == S_OK);

    bool completed = false;
    bool objectMatches = false;
    bool statusMatches = false;

    async.Completed([&](const IAsyncAction & sender, AsyncStatus status)
    {
        completed = true;
        objectMatches = (async == sender);
        statusMatches = (status == AsyncStatus::Canceled);
    });

    REQUIRE(completed);
    REQUIRE(objectMatches);
    REQUIRE(statusMatches);
}

TEST_CASE("async, Cancel_IAsyncAction, 2")
{
    event_handle event = CreateEvent(nullptr, false, false, nullptr);
    IAsyncAction async = Cancel_IAsyncAction(get(event));
    REQUIRE(async.Status() == AsyncStatus::Started);
    REQUIRE_THROWS_AS(async.GetResults(), hresult_illegal_method_call);

    bool completed = false;
    bool objectMatches = false;
    bool statusMatches = false;

    async.Completed([&](const IAsyncAction & sender, AsyncStatus status)
    {
        completed = true;
        objectMatches = (async == sender);
        statusMatches = (status == AsyncStatus::Canceled);
    });

    async.Cancel();
    SetEvent(get(event)); // signal async to run
    REQUIRE(WaitForSingleObject(get(event), INFINITE) == WAIT_OBJECT_0); // wait for async to be canceled
    REQUIRE(async.Status() == AsyncStatus::Canceled);
    REQUIRE_THROWS_AS(async.GetResults(), hresult_canceled);
    REQUIRE(async.ErrorCode() == S_OK);

    REQUIRE(completed);
    REQUIRE(objectMatches);
    REQUIRE(statusMatches);
}

TEST_CASE("async, Cancel_IAsyncActionWithProgress")
{
    event_handle event = CreateEvent(nullptr, false, false, nullptr);
    IAsyncActionWithProgress<double> async = Cancel_IAsyncActionWithProgress(get(event));
    REQUIRE(async.Status() == AsyncStatus::Started);
    REQUIRE_THROWS_AS(async.GetResults(), hresult_illegal_method_call);

    async.Cancel();
    SetEvent(get(event)); // signal async to run
    REQUIRE(WaitForSingleObject(get(event), INFINITE) == WAIT_OBJECT_0); // wait for async to be canceled
    REQUIRE(async.Status() == AsyncStatus::Canceled);
    REQUIRE_THROWS_AS(async.GetResults(), hresult_canceled);
    REQUIRE(async.ErrorCode() == S_OK);

    bool completed = false;
    bool objectMatches = false;
    bool statusMatches = false;

    async.Completed([&](const IAsyncActionWithProgress<double> & sender, AsyncStatus status)
    {
        completed = true;
        objectMatches = (async == sender);
        statusMatches = (status == AsyncStatus::Canceled);
    });

    REQUIRE(completed);
    REQUIRE(objectMatches);
    REQUIRE(statusMatches);
}

TEST_CASE("async, Cancel_IAsyncActionWithProgress, 2")
{
    event_handle event = CreateEvent(nullptr, false, false, nullptr);
    IAsyncActionWithProgress<double> async = Cancel_IAsyncActionWithProgress(get(event));
    REQUIRE(async.Status() == AsyncStatus::Started);
    REQUIRE_THROWS_AS(async.GetResults(), hresult_illegal_method_call);

    bool completed = false;
    bool objectMatches = false;
    bool statusMatches = false;

    async.Completed([&](const IAsyncActionWithProgress<double> & sender, AsyncStatus status)
    {
        completed = true;
        objectMatches = (async == sender);
        statusMatches = (status == AsyncStatus::Canceled);
    });

    async.Cancel();
    SetEvent(get(event)); // signal async to run
    REQUIRE(WaitForSingleObject(get(event), INFINITE) == WAIT_OBJECT_0); // wait for async to be canceled
    REQUIRE(async.Status() == AsyncStatus::Canceled);
    REQUIRE_THROWS_AS(async.GetResults(), hresult_canceled);
    REQUIRE(async.ErrorCode() == S_OK);

    REQUIRE(completed);
    REQUIRE(objectMatches);
    REQUIRE(statusMatches);
}

TEST_CASE("async, Cancel_IAsyncOperation")
{
    event_handle event = CreateEvent(nullptr, false, false, nullptr);
    IAsyncOperation<uint32_t> async = Cancel_IAsyncOperation(get(event));
    REQUIRE(async.Status() == AsyncStatus::Started);
    REQUIRE_THROWS_AS(async.GetResults(), hresult_illegal_method_call);

    async.Cancel();
    SetEvent(get(event)); // signal async to run
    REQUIRE(WaitForSingleObject(get(event), INFINITE) == WAIT_OBJECT_0); // wait for async to be canceled
    REQUIRE(async.Status() == AsyncStatus::Canceled);
    REQUIRE_THROWS_AS(async.GetResults(), hresult_canceled);
    REQUIRE(async.ErrorCode() == S_OK);

    bool completed = false;
    bool objectMatches = false;
    bool statusMatches = false;

    async.Completed([&](const IAsyncOperation<uint32_t> & sender, AsyncStatus status)
    {
        completed = true;
        objectMatches = (async == sender);
        statusMatches = (status == AsyncStatus::Canceled);
    });

    REQUIRE(completed);
    REQUIRE(objectMatches);
    REQUIRE(statusMatches);
}

TEST_CASE("async, Cancel_IAsyncOperation, 2")
{
    event_handle event = CreateEvent(nullptr, false, false, nullptr);
    IAsyncOperation<uint32_t> async = Cancel_IAsyncOperation(get(event));
    REQUIRE(async.Status() == AsyncStatus::Started);
    REQUIRE_THROWS_AS(async.GetResults(), hresult_illegal_method_call);

    bool completed = false;
    bool objectMatches = false;
    bool statusMatches = false;

    async.Completed([&](const IAsyncOperation<uint32_t> & sender, AsyncStatus status)
    {
        completed = true;
        objectMatches = (async == sender);
        statusMatches = (status == AsyncStatus::Canceled);
    });

    async.Cancel();
    SetEvent(get(event)); // signal async to run
    REQUIRE(WaitForSingleObject(get(event), INFINITE) == WAIT_OBJECT_0); // wait for async to be canceled
    REQUIRE(async.Status() == AsyncStatus::Canceled);
    REQUIRE_THROWS_AS(async.GetResults(), hresult_canceled);
    REQUIRE(async.ErrorCode() == S_OK);

    REQUIRE(completed);
    REQUIRE(objectMatches);
    REQUIRE(statusMatches);
}

TEST_CASE("async, Cancel_IAsyncOperationWithProgress")
{
    event_handle event = CreateEvent(nullptr, false, false, nullptr);
    IAsyncOperationWithProgress<uint64_t, uint64_t> async = Cancel_IAsyncOperationWithProgress(get(event));
    REQUIRE(async.Status() == AsyncStatus::Started);
    REQUIRE_THROWS_AS(async.GetResults(), hresult_illegal_method_call);

    async.Cancel();
    SetEvent(get(event)); // signal async to run
    REQUIRE(WaitForSingleObject(get(event), INFINITE) == WAIT_OBJECT_0); // wait for async to be canceled
    REQUIRE(async.Status() == AsyncStatus::Canceled);
    REQUIRE_THROWS_AS(async.GetResults(), hresult_canceled);
    REQUIRE(async.ErrorCode() == S_OK);

    bool completed = false;
    bool objectMatches = false;
    bool statusMatches = false;

    async.Completed([&](const IAsyncOperationWithProgress<uint64_t, uint64_t> & sender, AsyncStatus status)
    {
        completed = true;
        objectMatches = (async == sender);
        statusMatches = (status == AsyncStatus::Canceled);
    });

    REQUIRE(completed);
    REQUIRE(objectMatches);
    REQUIRE(statusMatches);
}

TEST_CASE("async, Cancel_IAsyncOperationWithProgress, 2")
{
    event_handle event = CreateEvent(nullptr, false, false, nullptr);
    IAsyncOperationWithProgress<uint64_t, uint64_t> async = Cancel_IAsyncOperationWithProgress(get(event));
    REQUIRE(async.Status() == AsyncStatus::Started);
    REQUIRE_THROWS_AS(async.GetResults(), hresult_illegal_method_call);

    bool completed = false;
    bool objectMatches = false;
    bool statusMatches = false;

    async.Completed([&](const IAsyncOperationWithProgress<uint64_t, uint64_t> & sender, AsyncStatus status)
    {
        completed = true;
        objectMatches = (async == sender);
        statusMatches = (status == AsyncStatus::Canceled);
    });

    async.Cancel();
    SetEvent(get(event)); // signal async to run
    REQUIRE(WaitForSingleObject(get(event), INFINITE) == WAIT_OBJECT_0); // wait for async to be canceled
    REQUIRE(async.Status() == AsyncStatus::Canceled);
    REQUIRE_THROWS_AS(async.GetResults(), hresult_canceled);
    REQUIRE(async.ErrorCode() == S_OK);

    REQUIRE(completed);
    REQUIRE(objectMatches);
    REQUIRE(statusMatches);
}

//
// These tests confirm the implicit cancelation behavior. The obeservable behavior should be the same as above
// but the implementation relies on an exception so we confirm that the state changes occur as before.
//

namespace
{
    struct signal_done
    {
        HANDLE signal;

        ~signal_done()
        {
            SetEvent(signal);
        }
    };

    IAsyncAction AutoCancel_IAsyncAction(HANDLE go)
    {
        signal_done d{ go };
        co_await resume_on_signal(go);
        co_await std::experimental::suspend_never{};
        REQUIRE(false);
    }

    IAsyncActionWithProgress<double> AutoCancel_IAsyncActionWithProgress(HANDLE go)
    {
        signal_done d{ go };
        co_await resume_on_signal(go);
        co_await std::experimental::suspend_never{};
        REQUIRE(false);
    }

    IAsyncOperation<uint32_t> AutoCancel_IAsyncOperation(HANDLE go)
    {
        signal_done d{ go };
        co_await resume_on_signal(go);
        co_await std::experimental::suspend_never{};
        REQUIRE(false);
        return 0;
    }

    IAsyncOperationWithProgress<uint64_t, uint64_t> AutoCancel_IAsyncOperationWithProgress(HANDLE go)
    {
        signal_done d{ go };
        co_await resume_on_signal(go);
        co_await std::experimental::suspend_never{};
        REQUIRE(false);
        return 0;
    }
}

TEST_CASE("async, AutoCancel_IAsyncAction")
{
    event_handle event = CreateEvent(nullptr, false, false, nullptr);
    IAsyncAction async = AutoCancel_IAsyncAction(get(event));
    REQUIRE(async.Status() == AsyncStatus::Started);

    async.Cancel();
    SetEvent(get(event)); // signal async to run
    REQUIRE(WaitForSingleObject(get(event), INFINITE) == WAIT_OBJECT_0); // wait for async to be canceled
    REQUIRE(async.Status() == AsyncStatus::Canceled);
    REQUIRE_THROWS_AS(async.GetResults(), hresult_canceled);

    bool completed = false;
    bool objectMatches = false;
    bool statusMatches = false;

    async.Completed([&](const IAsyncAction & sender, AsyncStatus status)
    {
        completed = true;
        objectMatches = (async == sender);
        statusMatches = (status == AsyncStatus::Canceled);
    });

    REQUIRE(completed);
    REQUIRE(objectMatches);
    REQUIRE(statusMatches);
}

TEST_CASE("async, AutoCancel_IAsyncAction, 2")
{
    event_handle event = CreateEvent(nullptr, false, false, nullptr);
    IAsyncAction async = AutoCancel_IAsyncAction(get(event));
    REQUIRE(async.Status() == AsyncStatus::Started);

    bool completed = false;
    bool objectMatches = false;
    bool statusMatches = false;

    async.Completed([&](const IAsyncAction & sender, AsyncStatus status)
    {
        completed = true;
        objectMatches = (async == sender);
        statusMatches = (status == AsyncStatus::Canceled);
    });

    async.Cancel();
    SetEvent(get(event)); // signal async to run
    REQUIRE(WaitForSingleObject(get(event), INFINITE) == WAIT_OBJECT_0); // wait for async to be canceled
    REQUIRE(async.Status() == AsyncStatus::Canceled);
    REQUIRE_THROWS_AS(async.GetResults(), hresult_canceled);

    REQUIRE(completed);
    REQUIRE(objectMatches);
    REQUIRE(statusMatches);
}

TEST_CASE("async, AutoCancel_IAsyncActionWithProgress")
{
    event_handle event = CreateEvent(nullptr, false, false, nullptr);
    IAsyncActionWithProgress<double> async = AutoCancel_IAsyncActionWithProgress(get(event));
    REQUIRE(async.Status() == AsyncStatus::Started);

    async.Cancel();
    SetEvent(get(event)); // signal async to run
    REQUIRE(WaitForSingleObject(get(event), INFINITE) == WAIT_OBJECT_0); // wait for async to be canceled
    REQUIRE(async.Status() == AsyncStatus::Canceled);
    REQUIRE_THROWS_AS(async.GetResults(), hresult_canceled);

    bool completed = false;
    bool objectMatches = false;
    bool statusMatches = false;

    async.Completed([&](const IAsyncActionWithProgress<double> & sender, AsyncStatus status)
    {
        completed = true;
        objectMatches = (async == sender);
        statusMatches = (status == AsyncStatus::Canceled);
    });

    REQUIRE(completed);
    REQUIRE(objectMatches);
    REQUIRE(statusMatches);
}

TEST_CASE("async, AutoCancel_IAsyncActionWithProgress, 2")
{
    event_handle event = CreateEvent(nullptr, false, false, nullptr);
    IAsyncActionWithProgress<double> async = AutoCancel_IAsyncActionWithProgress(get(event));
    REQUIRE(async.Status() == AsyncStatus::Started);

    bool completed = false;
    bool objectMatches = false;
    bool statusMatches = false;

    async.Completed([&](const IAsyncActionWithProgress<double> & sender, AsyncStatus status)
    {
        completed = true;
        objectMatches = (async == sender);
        statusMatches = (status == AsyncStatus::Canceled);
    });

    async.Cancel();
    SetEvent(get(event)); // signal async to run
    REQUIRE(WaitForSingleObject(get(event), INFINITE) == WAIT_OBJECT_0); // wait for async to be canceled
    REQUIRE(async.Status() == AsyncStatus::Canceled);
    REQUIRE_THROWS_AS(async.GetResults(), hresult_canceled);

    REQUIRE(completed);
    REQUIRE(objectMatches);
    REQUIRE(statusMatches);
}

TEST_CASE("async, AutoCancel_IAsyncOperation")
{
    event_handle event = CreateEvent(nullptr, false, false, nullptr);
    IAsyncOperation<uint32_t> async = AutoCancel_IAsyncOperation(get(event));
    REQUIRE(async.Status() == AsyncStatus::Started);

    async.Cancel();
    SetEvent(get(event)); // signal async to run
    REQUIRE(WaitForSingleObject(get(event), INFINITE) == WAIT_OBJECT_0); // wait for async to be canceled
    REQUIRE(async.Status() == AsyncStatus::Canceled);
    REQUIRE_THROWS_AS(async.GetResults(), hresult_canceled);

    bool completed = false;
    bool objectMatches = false;
    bool statusMatches = false;

    async.Completed([&](const IAsyncOperation<uint32_t> & sender, AsyncStatus status)
    {
        completed = true;
        objectMatches = (async == sender);
        statusMatches = (status == AsyncStatus::Canceled);
    });

    REQUIRE(completed);
    REQUIRE(objectMatches);
    REQUIRE(statusMatches);
}

TEST_CASE("async, AutoCancel_IAsyncOperation, 2")
{
    event_handle event = CreateEvent(nullptr, false, false, nullptr);
    IAsyncOperation<uint32_t> async = AutoCancel_IAsyncOperation(get(event));
    REQUIRE(async.Status() == AsyncStatus::Started);

    bool completed = false;
    bool objectMatches = false;
    bool statusMatches = false;

    async.Completed([&](const IAsyncOperation<uint32_t> & sender, AsyncStatus status)
    {
        completed = true;
        objectMatches = (async == sender);
        statusMatches = (status == AsyncStatus::Canceled);
    });

    async.Cancel();
    SetEvent(get(event)); // signal async to run
    REQUIRE(WaitForSingleObject(get(event), INFINITE) == WAIT_OBJECT_0); // wait for async to be canceled
    REQUIRE(async.Status() == AsyncStatus::Canceled);
    REQUIRE_THROWS_AS(async.GetResults(), hresult_canceled);

    REQUIRE(completed);
    REQUIRE(objectMatches);
    REQUIRE(statusMatches);
}

TEST_CASE("async, AutoCancel_IAsyncOperationWithProgress")
{
    event_handle event = CreateEvent(nullptr, false, false, nullptr);
    IAsyncOperationWithProgress<uint64_t, uint64_t> async = AutoCancel_IAsyncOperationWithProgress(get(event));
    REQUIRE(async.Status() == AsyncStatus::Started);

    async.Cancel();
    SetEvent(get(event)); // signal async to run
    REQUIRE(WaitForSingleObject(get(event), INFINITE) == WAIT_OBJECT_0); // wait for async to be canceled
    REQUIRE(async.Status() == AsyncStatus::Canceled);
    REQUIRE_THROWS_AS(async.GetResults(), hresult_canceled);

    bool completed = false;
    bool objectMatches = false;
    bool statusMatches = false;

    async.Completed([&](const IAsyncOperationWithProgress<uint64_t, uint64_t> & sender, AsyncStatus status)
    {
        completed = true;
        objectMatches = (async == sender);
        statusMatches = (status == AsyncStatus::Canceled);
    });

    REQUIRE(completed);
    REQUIRE(objectMatches);
    REQUIRE(statusMatches);
}

TEST_CASE("async, AutoCancel_IAsyncOperationWithProgress, 2")
{
    event_handle event = CreateEvent(nullptr, false, false, nullptr);
    IAsyncOperationWithProgress<uint64_t, uint64_t> async = AutoCancel_IAsyncOperationWithProgress(get(event));
    REQUIRE(async.Status() == AsyncStatus::Started);

    bool completed = false;
    bool objectMatches = false;
    bool statusMatches = false;

    async.Completed([&](const IAsyncOperationWithProgress<uint64_t, uint64_t> & sender, AsyncStatus status)
    {
        completed = true;
        objectMatches = (async == sender);
        statusMatches = (status == AsyncStatus::Canceled);
    });

    async.Cancel();
    SetEvent(get(event)); // signal async to run
    REQUIRE(WaitForSingleObject(get(event), INFINITE) == WAIT_OBJECT_0); // wait for async to be canceled
    REQUIRE(async.Status() == AsyncStatus::Canceled);
    REQUIRE_THROWS_AS(async.GetResults(), hresult_canceled);

    REQUIRE(completed);
    REQUIRE(objectMatches);
    REQUIRE(statusMatches);
}

//
// These tests cover the basic behavior of the .get methods for blocking wait. Here we test for both blocking
// and non-blocking coroutines to illustrate both OS sleep and non-suspension.
//

TEST_CASE("async, get, no suspend with success")
{
    NoSuspend_IAsyncAction().get();
    NoSuspend_IAsyncActionWithProgress().get();
    REQUIRE(123 == NoSuspend_IAsyncOperation().get());
    REQUIRE(456 == NoSuspend_IAsyncOperationWithProgress().get());
}

TEST_CASE("async, get, suspend with success")
{
    event_handle event = CreateEvent(nullptr, true, false, nullptr);

    auto a = Suspend_IAsyncAction(get(event));
    auto b = Suspend_IAsyncActionWithProgress(get(event));
    auto c = Suspend_IAsyncOperation(get(event));
    auto d = Suspend_IAsyncOperationWithProgress(get(event));

    SetEvent(get(event)); // signal all to run

    a.get();
    b.get();
    REQUIRE(123 == c.get());
    REQUIRE(456 == d.get());
}

TEST_CASE("async, get, failure")
{
    event_handle event = CreateEvent(nullptr, true, false, nullptr);
    SetEvent(get(event));

    auto a = Throw_IAsyncAction(get(event));
    auto b = Throw_IAsyncActionWithProgress(get(event));
    auto c = Throw_IAsyncOperation(get(event));
    auto d = Throw_IAsyncOperationWithProgress(get(event));

    try
    {
        a.get();
        REQUIRE(false);
    }
    catch (hresult_invalid_argument const & e)
    {
        REQUIRE(e.message() == L"Throw_IAsyncAction");
    }

    try
    {
        b.get();
        REQUIRE(false);
    }
    catch (hresult_invalid_argument const & e)
    {
        REQUIRE(e.message() == L"Throw_IAsyncActionWithProgress");
    }

    try
    {
        c.get();
        REQUIRE(false);
    }
    catch (hresult_invalid_argument const & e)
    {
        REQUIRE(e.message() == L"Throw_IAsyncOperation");
    }

    try
    {
        d.get();
        REQUIRE(false);
    }
    catch (hresult_invalid_argument const & e)
    {
        REQUIRE(e.message() == L"Throw_IAsyncOperationWithProgress");
    }
}

//
// The resume_background test just checks whether a thread switch occurred, indicating that the 
// coroutine resumed on the thread pool.
//

namespace
{
    IAsyncAction test_resume_background(uint32_t & before, uint32_t & after)
    {
        before = GetCurrentThreadId();
        co_await resume_background();
        after = GetCurrentThreadId();
    }
}

TEST_CASE("async, resume_background")
{
    uint32_t before = 0;
    uint32_t after = 0;

    test_resume_background(before, after).get();

    REQUIRE(before == GetCurrentThreadId());
    REQUIRE(after != GetCurrentThreadId());
}

//
// The resume_after test confirms that a zero duration does not suspend the coroutine,
// while a non-zero duration suspends the coroutine and resumes on the thread pool.
//

namespace
{
    IAsyncAction test_resume_after(uint32_t & before, uint32_t & after)
    {
        co_await 0s; // should not suspend
        before = GetCurrentThreadId();

        co_await 1us; // should suspend and resume on background thread
        after = GetCurrentThreadId();
    }
}

TEST_CASE("async, resume_after")
{
    uint32_t before = 0;
    uint32_t after = 0;

    test_resume_after(before, after).get();

    REQUIRE(before == GetCurrentThreadId());
    REQUIRE(after != GetCurrentThreadId());
}

//
// Other tests already excercise resume_on_signal so here we focus on testing the timeout.
//

namespace
{
    IAsyncAction test_resume_on_signal(HANDLE signal)
    {
        const uint32_t caller = GetCurrentThreadId();

        co_await resume_on_signal(signal); // should not suspend because already signaled
        REQUIRE(caller == GetCurrentThreadId()); // still on calling thread

        REQUIRE(false == co_await resume_on_signal(signal, 1us)); // should suspend but timeout
        REQUIRE(caller != GetCurrentThreadId()); // now on background thread

        REQUIRE(true == co_await resume_on_signal(signal, 1s)); // should eventually succeed
    }
}

TEST_CASE("async, resume_on_signal")
{
    event_handle event = CreateEvent(nullptr, false, true, nullptr);
    IAsyncAction async = test_resume_on_signal(get(event));

    Sleep(50);
    SetEvent(get(event)); // allow final resume_on_signal to succeed
    async.get();
}

//
// This test covers the resumable_io helper using a named pipe for convenient testing. The pipe server
// waits for two messages to be read. For each, it writes the message back in capitals. Two pipe clients
// are provided. One uses FILE_SKIP_COMPLETION_PORT_ON_SUCCESS to excercise the resumable_io support for
// skipping suspension in case of synchronous completion. The Catch REQUIRE macro is not used within 
// these tests since it doesn't behave well inside coroutines but the coroutines throw on failure so the
// tests will still fail.
//

namespace
{
    struct file_traits
    {
        using type = HANDLE;

        static type invalid() noexcept
        {
            return INVALID_HANDLE_VALUE;
        }

        static void close(type value) noexcept
        {
            WINRT_VERIFY(CloseHandle(value));
        }
    };

    using file_handle = handle<file_traits>;

    IAsyncAction pipe_server()
    {
        // Create the pipe before hitting the suspension point to ensure the pipe is ready for the client.

        file_handle handle = CreateNamedPipe(L"\\\\.\\pipe\\cppwinrt\\tests\\pipe_server",
            PIPE_ACCESS_DUPLEX | FILE_FLAG_FIRST_PIPE_INSTANCE,
            PIPE_TYPE_MESSAGE | PIPE_READMODE_MESSAGE, 1, 0, 0, 0, nullptr);

        WINRT_VERIFY(handle);

        // The server is synchronous but runs in a background thread.

        co_await resume_background();

        // Wait for the client to connect.

        if (!ConnectNamedPipe(get(handle), nullptr))
        {
            if (GetLastError() != ERROR_PIPE_CONNECTED)
            {
                throw_last_error();
            }
        }

        // Read the message from the client.

        std::array<char, 512> buffer;
        DWORD bytes_copied = 0;

        for (int iteration = 0; iteration <= 1; ++iteration)
        {
            WINRT_VERIFY(ReadFile(get(handle), buffer.data(), static_cast<DWORD>(buffer.size()), &bytes_copied, nullptr));

            // Change message to upper case.

            for (DWORD i = 0; i != bytes_copied; ++i)
            {
                buffer[i] = static_cast<char>(toupper(buffer[i]));
            }

            if (iteration == 1)
            {
                // This forces the overlapped ReadFile to queue a completion packet.

                co_await 50ms;
            }

            // Send message to client and wait for client read it.

            WINRT_VERIFY(WriteFile(get(handle), buffer.data(), bytes_copied, &bytes_copied, nullptr));
        }
    }

    struct pipe_client_skip_completion
    {
        bool m_check1{ false };
        bool m_check2{ false };
        bool m_check3{ false };
        bool m_check4{ false };

        pipe_client_skip_completion() :
            m_handle(create()),
            m_io(get(m_handle))
        {
        }

        ~pipe_client_skip_completion()
        {
            WINRT_VERIFY(m_check1);
            WINRT_VERIFY(m_check2);
            WINRT_VERIFY(m_check3);
            WINRT_VERIFY(m_check4);
        }

        auto read(void * const buffer, const size_t size)
        {
            return m_io.start_pending([=, handle = get(m_handle)](OVERLAPPED & overlapped)
            {
                if (ReadFile(handle, buffer, static_cast<DWORD>(size), nullptr, &overlapped))
                {
                    m_check1 = true;
                    return false;
                }

                const DWORD error = GetLastError();

                if (error != ERROR_IO_PENDING)
                {
                    throw hresult_error(HRESULT_FROM_WIN32(error));
                }

                m_check2 = true;
                return true;
            });
        }

        auto write(const void * const buffer, const size_t size)
        {
            return m_io.start_pending([=, handle = get(m_handle)](OVERLAPPED & overlapped)
            {
                if (WriteFile(handle, buffer, static_cast<DWORD>(size), nullptr, &overlapped))
                {
                    m_check3 = true;
                    return false;
                }

                const DWORD error = GetLastError();

                if (error != ERROR_IO_PENDING)
                {
                    throw hresult_error(HRESULT_FROM_WIN32(error));
                }

                m_check4 = true;
                return true;
            });
        }

    private:

        static file_handle create()
        {
            file_handle handle = CreateFile(L"\\\\.\\pipe\\cppwinrt\\tests\\pipe_server",
                GENERIC_READ | GENERIC_WRITE,
                0,
                nullptr,
                OPEN_EXISTING,
                FILE_FLAG_OVERLAPPED,
                nullptr);

            WINRT_VERIFY(handle);
            WINRT_VERIFY(SetFileCompletionNotificationModes(get(handle), FILE_SKIP_COMPLETION_PORT_ON_SUCCESS));

            return handle;
        }

        file_handle m_handle;
        resumable_io m_io;
    };

    struct pipe_client
    {
        pipe_client() :
            m_handle(create()),
            m_io(get(m_handle))
        {
        }

        auto read(void * const buffer, const size_t size)
        {
            return m_io.start([=, handle = get(m_handle)](OVERLAPPED & overlapped)
            {
                if (!ReadFile(handle, buffer, static_cast<DWORD>(size), nullptr, &overlapped))
                {
                    const DWORD error = GetLastError();

                    if (error != ERROR_IO_PENDING)
                    {
                        throw hresult_error(HRESULT_FROM_WIN32(error));
                    }
                }
            });
        }

        auto write(const void * const buffer, const size_t size)
        {
            return m_io.start([=, handle = get(m_handle)](OVERLAPPED & overlapped)
            {
                if (!WriteFile(handle, buffer, static_cast<DWORD>(size), nullptr, &overlapped))
                {
                    const DWORD error = GetLastError();

                    if (error != ERROR_IO_PENDING)
                    {
                        throw hresult_error(HRESULT_FROM_WIN32(error));
                    }
                }
            });
        }

    private:

        static file_handle create()
        {
            file_handle handle = CreateFile(L"\\\\.\\pipe\\cppwinrt\\tests\\pipe_server",
                GENERIC_READ | GENERIC_WRITE,
                0,
                nullptr,
                OPEN_EXISTING,
                FILE_FLAG_OVERLAPPED,
                nullptr);

            WINRT_VERIFY(handle);
            return handle;
        }

        file_handle m_handle;
        resumable_io m_io;
    };

    IAsyncAction test_pipe_client_skip_completion()
    {
        IAsyncAction server = pipe_server();
        pipe_client_skip_completion client;

        std::string message = "message 1";

        WINRT_VERIFY(message.size() == co_await client.write(message.data(), message.size()));

        WINRT_VERIFY(message.size() == co_await client.read(message.data(), message.size()));

        if (message != "MESSAGE 1")
        {
            throw hresult_out_of_bounds(L"Test failure");
        }

        message = "message 2";

        // This allows the server to get read so that the following overlapped WriteFile can completed synchronously.
        co_await 50ms;

        WINRT_VERIFY(message.size() == co_await client.write(message.data(), message.size()));

        WINRT_VERIFY(message.size() == co_await client.read(message.data(), message.size()));

        if (message != "MESSAGE 2")
        {
            throw hresult_out_of_bounds(L"Test failure");
        }

        co_await server;
    }

    IAsyncAction test_pipe_client()
    {
        IAsyncAction server = pipe_server();
        pipe_client client;

        std::string message = "message 1";

        WINRT_VERIFY(message.size() == co_await client.write(message.data(), message.size()));

        WINRT_VERIFY(message.size() == co_await client.read(message.data(), message.size()));

        if (message != "MESSAGE 1")
        {
            throw hresult_out_of_bounds(L"Test failure");
        }

        message = "message 2";

        WINRT_VERIFY(message.size() == co_await client.write(message.data(), message.size()));

        WINRT_VERIFY(message.size() == co_await client.read(message.data(), message.size()));

        if (message != "MESSAGE 2")
        {
            throw hresult_out_of_bounds(L"Test failure");
        }

        co_await server;
    }
}

TEST_CASE("async, overlapped I/O with completion packet skipping")
{
    test_pipe_client_skip_completion().get();
    test_pipe_client().get();
}
