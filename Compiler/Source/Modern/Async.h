
#pragma once

#include <modern\comptr.h>
#include <ctxtcall.h>
#include <ppltasks.h>
#include <future>

namespace Modern { namespace Interop {

inline concurrency::task<void> Task(Windows::Foundation::IAsyncAction const & action)
{
    concurrency::task_completion_event<void> event;

    action.Completed([event](Windows::Foundation::IAsyncAction const & action, AsyncStatus)
    {
        try
        {
            action.GetResults();
            event.set();
        }
        catch (Exception const & e)
        {
            event.set_exception(e);
        }
    });

    return concurrency::task<void>(event);
}

template <typename TResult, typename TProgress>
concurrency::task<typename Interop::Argument<TResult>::Type> Task(Windows::Foundation::IAsyncOperationWithProgress<TResult, TProgress> const & operation)
{
    concurrency::task_completion_event<typename Interop::Argument<TResult>::Type> event;

    operation.Completed([event](IAsyncOperationWithProgress<TResult, TProgress> const & sender, AsyncStatus)
    {
        try
        {
            event.set(sender.GetResults());
        }
        catch (Exception const & e)
        {
            event.set_exception(e);
        }
    });

    return concurrency::task<typename Interop::Argument<TResult>::Type>(event);
}

}}

namespace Modern { namespace Windows { namespace Foundation {

inline bool await_ready(Windows::Foundation::IAsyncAction const &) noexcept
{
    return false;
}

template <typename F>
void await_suspend(Windows::Foundation::IAsyncAction const & action, F resume) noexcept
{
    ComPtr<IContextCallback> context;
    CoGetObjectContext(__uuidof(IContextCallback), reinterpret_cast<void **>(context.SetAbi()));

    action.Completed([context, resume](Windows::Foundation::IAsyncAction const &, AsyncStatus)
    {
        if (context)
        {
            ComCallData callData = {};
            callData.pUserDefined = resume.to_address();

            HRESULT hr = context->ContextCallback(
                [](ComCallData * callData)
                {
                    F::from_address(callData->pUserDefined)();

                    //(*static_cast<F *>(callData->pUserDefined))();

                    //printf("call! %d\n", GetCurrentThreadId());
                    return S_OK;
                },
                &callData,
                IID_ICallbackWithNoReentrancyToApplicationSTA,
                5,
                nullptr);

            if (hr != S_OK)
            {
                throw Modern::Exception(hr);
            }
        }
        else
        {
            resume();
        }
    });
}

inline void await_resume(Windows::Foundation::IAsyncAction const & action) noexcept
{
    action.GetResults();
}

}}}

namespace Modern { namespace Windows { namespace Foundation {

template <typename TResult, typename TProgress>
bool await_ready(Windows::Foundation::IAsyncOperationWithProgress<TResult, TProgress> const &) noexcept
{
    return false;
}

template <typename TResult, typename TProgress, typename F>
void await_suspend(Windows::Foundation::IAsyncOperationWithProgress<TResult, TProgress> const & operation, F resume) noexcept
{
    operation.Completed([resume](IAsyncOperationWithProgress<TResult, TProgress> const &, AsyncStatus)
    {
        resume();
    });
}

template <typename TResult, typename TProgress>
typename Interop::Argument<TResult>::Type await_resume(Windows::Foundation::IAsyncOperationWithProgress<TResult, TProgress> const & operation) noexcept
{
    return operation.GetResults();
}

}}}

namespace Modern { namespace Windows { namespace Foundation {

template <typename TResult>
bool await_ready(Windows::Foundation::IAsyncOperation<TResult> const &) noexcept
{
    return false;
}

template <typename TResult, typename F>
void await_suspend(Windows::Foundation::IAsyncOperation<TResult> const & operation, F resume) noexcept
{
    operation.Completed([resume](IAsyncOperation<TResult> const &, AsyncStatus)
    {
        resume();
    });
}

template <typename TResult>
typename Interop::Argument<TResult>::Type await_resume(Windows::Foundation::IAsyncOperation<TResult> const & operation) noexcept
{
    return operation.GetResults();
}

}}}
