
#ifdef WINRT_ASYNC

namespace impl
{
    template <typename Async>
    struct await_adapter
    {
        const Async & async;

        bool await_ready() const
        {
            return async.Status() == Windows::Foundation::AsyncStatus::Completed;
        }

        void await_suspend(std::experimental::coroutine_handle<> handle) const
        {
            com_ptr<IContextCallback> context;
            check_hresult(CoGetObjectContext(__uuidof(context), reinterpret_cast<void **>(put(context))));

            async.Completed([handle, context = std::move(context)](const auto &, Windows::Foundation::AsyncStatus)
            {
                ComCallData data = {};
                data.pUserDefined = handle.address();

                check_hresult(context->ContextCallback([](ComCallData * data)
                {
                    std::experimental::coroutine_handle<>::from_address(data->pUserDefined)();
                    return S_OK;
                },
                &data,
                IID_ICallbackWithNoReentrancyToApplicationSTA,
                5,
                nullptr));
            });
        }

        auto await_resume() const
        {
            return async.GetResults();
        }
    };
}

namespace Windows::Foundation
{
    inline impl::await_adapter<IAsyncAction> operator co_await(const IAsyncAction & async)
    {
        return{ async };
    }

    template <typename TProgress>
    impl::await_adapter<IAsyncActionWithProgress<TProgress>> operator co_await(const IAsyncActionWithProgress<TProgress> & async)
    {
        return{ async };
    }

    template <typename TResult>
    impl::await_adapter<IAsyncOperation<TResult>> operator co_await(const IAsyncOperation<TResult> & async)
    {
        return{ async };
    }

    template <typename TResult, typename TProgress>
    impl::await_adapter<IAsyncOperationWithProgress<TResult, TProgress>> operator co_await(const IAsyncOperationWithProgress<TResult, TProgress> & async)
    {
        return{ async };
    }
}

#endif
