#include "pch.h"
#include "catch.hpp"
#include "winrt\ppl.h"

using namespace winrt;
using namespace winrt::ppl;
using namespace Windows::Foundation;

//
// These tests ensure the proper operation of the PPL task adapters. A set of minimal IAsyncXxx 
// implementations are followed by a series of tests for each interface for both success and 
// failure paths. For the failure tests, we specifically test that the exact exception type
// and state is propagated correctly.
//

namespace
{
    struct AsyncAction_OK : implements<AsyncAction_OK, IAsyncAction>
    {
        void Completed(const AsyncActionCompletedHandler & handler)
        {
            handler(*this, AsyncStatus::Completed);
        }

        AsyncActionCompletedHandler Completed()
        {
            return nullptr;
        }

        void GetResults() const
        {
        }
    };

    struct AsyncAction_FAIL : implements<AsyncAction_FAIL, IAsyncAction>
    {
        void Completed(const AsyncActionCompletedHandler & handler)
        {
            handler(*this, AsyncStatus::Completed);
        }

        AsyncActionCompletedHandler Completed()
        {
            return nullptr;
        }

        void GetResults() const
        {
            throw hresult_access_denied(L"test");
        }
    };

    struct AsyncActionWithProgress_OK : implements<AsyncActionWithProgress_OK, IAsyncActionWithProgress<double>>
    {
        void Completed(const AsyncActionWithProgressCompletedHandler<double> & handler)
        {
            handler(*this, AsyncStatus::Completed);
        }

        AsyncActionWithProgressCompletedHandler<double> Completed()
        {
            return nullptr;
        }

        void Progress(const AsyncActionProgressHandler<double> &)
        {
        }

        AsyncActionProgressHandler<double> Progress()
        {
            return nullptr;
        }

        void GetResults() const
        {
        }
    };

    struct AsyncActionWithProgress_FAIL : implements<AsyncActionWithProgress_FAIL, IAsyncActionWithProgress<double>>
    {
        void Completed(const AsyncActionWithProgressCompletedHandler<double> & handler)
        {
            handler(*this, AsyncStatus::Completed);
        }

        AsyncActionWithProgressCompletedHandler<double> Completed()
        {
            return nullptr;
        }

        void Progress(const AsyncActionProgressHandler<double> &)
        {
        }

        AsyncActionProgressHandler<double> Progress()
        {
            return nullptr;
        }

        void GetResults() const
        {
            throw hresult_access_denied(L"test");
        }
    };

    struct AsyncOperation_OK : implements<AsyncOperation_OK, IAsyncOperation<uint32_t>>
    {
        void Completed(const AsyncOperationCompletedHandler<uint32_t> & handler)
        {
            handler(*this, AsyncStatus::Completed);
        }

        AsyncOperationCompletedHandler<uint32_t> Completed()
        {
            return nullptr;
        }

        uint32_t GetResults() const
        {
            return 123;
        }
    };

    struct AsyncOperation_FAIL : implements<AsyncOperation_FAIL, IAsyncOperation<uint32_t>>
    {
        void Completed(const AsyncOperationCompletedHandler<uint32_t> & handler)
        {
            handler(*this, AsyncStatus::Completed);
        }

        AsyncOperationCompletedHandler<uint32_t> Completed()
        {
            return nullptr;
        }

        uint32_t GetResults() const
        {
            throw hresult_access_denied(L"test");
        }
    };

    struct AsyncOperationWithProgress_OK : implements<AsyncOperationWithProgress_OK, IAsyncOperationWithProgress<uint64_t, uint64_t>>
    {
        void Completed(const AsyncOperationWithProgressCompletedHandler<uint64_t, uint64_t> & handler)
        {
            handler(*this, AsyncStatus::Completed);
        }

        AsyncOperationWithProgressCompletedHandler<uint64_t, uint64_t> Completed()
        {
            return nullptr;
        }

        void Progress(const AsyncOperationProgressHandler<uint64_t, uint64_t> &)
        {
        }

        AsyncOperationProgressHandler<uint64_t, uint64_t> Progress()
        {
            return nullptr;
        }

        uint32_t GetResults() const
        {
            return 123;
        }
    };

    struct AsyncOperationWithProgress_FAIL : implements<AsyncOperationWithProgress_FAIL, IAsyncOperationWithProgress<uint64_t, uint64_t>>
    {
        void Completed(const AsyncOperationWithProgressCompletedHandler<uint64_t, uint64_t> & handler)
        {
            handler(*this, AsyncStatus::Completed);
        }

        AsyncOperationWithProgressCompletedHandler<uint64_t, uint64_t> Completed()
        {
            return nullptr;
        }

        void Progress(const AsyncOperationProgressHandler<uint64_t, uint64_t> &)
        {
        }

        AsyncOperationProgressHandler<uint64_t, uint64_t> Progress()
        {
            return nullptr;
        }

        uint32_t GetResults() const
        {
            throw hresult_access_denied(L"test");
        }
    };
}

TEST_CASE("ppl, AsyncAction_OK")
{
    IAsyncAction async = make<AsyncAction_OK>();
    create_task(async).wait();
}

TEST_CASE("ppl, AsyncAction_FAIL")
{
    IAsyncAction async = make<AsyncAction_FAIL>();

    try
    {
        auto task = create_task(async);
        task.wait();
        REQUIRE(false);
    }
    catch (hresult_access_denied const & e)
    {
        REQUIRE(e.message() == L"test");
    }
}

TEST_CASE("ppl, AsyncActionWithProgress_OK")
{
    IAsyncActionWithProgress<double> async = make<AsyncActionWithProgress_OK>();
    create_task(async).wait();
}

TEST_CASE("ppl, AsyncActionWithProgress_FAIL")
{
    IAsyncActionWithProgress<double> async = make<AsyncActionWithProgress_FAIL>();

    try
    {
        auto task = create_task(async);
        task.wait();
        REQUIRE(false);
    }
    catch (hresult_access_denied const & e)
    {
        REQUIRE(e.message() == L"test");
    }
}

TEST_CASE("ppl, AsyncOperation_OK")
{
    IAsyncOperation<uint32_t> async = make<AsyncOperation_OK>();
    REQUIRE(create_task(async).get() == 123);
}

TEST_CASE("ppl, AsyncOperation_FAIL")
{
    IAsyncOperation<uint32_t> async = make<AsyncOperation_FAIL>();

    try
    {
        auto task = create_task(async);
        task.wait();
        REQUIRE(false);
    }
    catch (hresult_access_denied const & e)
    {
        REQUIRE(e.message() == L"test");
    }
}

TEST_CASE("ppl, AsyncOperationWithProgress_OK")
{
    IAsyncOperationWithProgress<uint64_t, uint64_t> async = make<AsyncOperationWithProgress_OK>();
    REQUIRE(create_task(async).get() == 123);
}

TEST_CASE("ppl, AsyncOperationWithProgress_FAIL")
{
    IAsyncOperationWithProgress<uint64_t, uint64_t> async = make<AsyncOperationWithProgress_FAIL>();

    try
    {
        auto task = create_task(async);
        task.wait();
        REQUIRE(false);
    }
    catch (hresult_access_denied const & e)
    {
        REQUIRE(e.message() == L"test");
    }
}
