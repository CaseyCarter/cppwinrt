
#include "base.h"
#include <ppltasks.h>

namespace winrt::ppl
{
    inline auto create_task(Windows::Foundation::IAsyncAction const & async)
    {
        concurrency::task_completion_event<void> event;

        async.Completed([event](Windows::Foundation::IAsyncAction const & sender,
                                Windows::Foundation::AsyncStatus)
        {
            try
            {
                sender.GetResults();
                event.set();
            }
            catch (...)
            {
                event.set_exception(std::current_exception());
            }
        });

        return concurrency::task<void>(event);
    }

    template <typename TProgress>
    auto create_task(Windows::Foundation::IAsyncActionWithProgress<TProgress> const & async)
    {
        concurrency::task_completion_event<void> event;

        async.Completed([event](Windows::Foundation::IAsyncActionWithProgress<TProgress> const & sender,
                                Windows::Foundation::AsyncStatus)
        {
            try
            {
                sender.GetResults();
                event.set();
            }
            catch (...)
            {
                event.set_exception(std::current_exception());
            }
        });

        return concurrency::task<void>(event);
    }

    template <typename TResult>
    auto create_task(Windows::Foundation::IAsyncOperation<TResult> const & async)
    {
        concurrency::task_completion_event<TResult> event;

        async.Completed([event](Windows::Foundation::IAsyncOperation<TResult> const & sender,
                                Windows::Foundation::AsyncStatus)
        {
            try
            {
                event.set(sender.GetResults());
            }
            catch (...)
            {
                event.set_exception(std::current_exception());
            }
        });

        return concurrency::task<TResult>(event);
    }

    template <typename TResult, typename TProgress>
    auto create_task(Windows::Foundation::IAsyncOperationWithProgress<TResult, TProgress> const & operation)
    {
        concurrency::task_completion_event<TResult> event;

        operation.Completed([event](Windows::Foundation::IAsyncOperationWithProgress<TResult, TProgress> const & sender,
                                    Windows::Foundation::AsyncStatus)
        {
            try
            {
                event.set(sender.GetResults());
            }
            catch (...)
            {
                event.set_exception(std::current_exception());
            }
        });

        return concurrency::task<TResult>(event);
    }
}
