
namespace Windows::Foundation {

template <typename T, typename F>
void impl_suspend(const T & object, F resume)
{
    com_ptr<IContextCallback> context;
    check_hresult(CoGetObjectContext(__uuidof(context), reinterpret_cast<void **>(put(context))));

    object.Completed([resume, context = std::move(context)](const auto &, AsyncStatus)
    {
        ComCallData data = {};
        data.pUserDefined = resume.address();

        check_hresult(context->ContextCallback([](ComCallData * data)
        {
            F::from_address(data->pUserDefined)();
            return S_OK;
        },
        &data,
        IID_ICallbackWithNoReentrancyToApplicationSTA,
        5,
        nullptr));
    });
}

template <typename TProgress>
bool await_ready(const IAsyncActionWithProgress<TProgress> & object)
{
    return object.Status() == AsyncStatus::Completed;
}

template <typename TProgress, typename F>
void await_suspend(const IAsyncActionWithProgress<TProgress> & object, F resume)
{
    impl_suspend(object, resume);
}

template <typename TProgress>
void await_resume(const IAsyncActionWithProgress<TProgress> & object)
{
    object.GetResults();
}

template <typename TResult, typename TProgress>
bool await_ready(const IAsyncOperationWithProgress<TResult, TProgress> & object)
{
    return object.Status() == AsyncStatus::Completed;
}

template <typename TResult, typename TProgress, typename F>
void await_suspend(const IAsyncOperationWithProgress<TResult, TProgress> & object, F resume)
{
    impl_suspend(object, resume);
}

template <typename TResult, typename TProgress>
TResult await_resume(const IAsyncOperationWithProgress<TResult, TProgress> & object)
{
    return object.GetResults();
}

template <typename TResult>
bool await_ready(const IAsyncOperation<TResult> & object)
{
    return object.Status() == AsyncStatus::Completed;
}

template <typename TResult, typename F>
void await_suspend(const IAsyncOperation<TResult> & object, F resume)
{
    impl_suspend(object, resume);
}

template <typename TResult>
TResult await_resume(const IAsyncOperation<TResult> & object)
{
    return object.GetResults();
}

inline bool await_ready(const IAsyncAction & object)
{
    return object.Status() == AsyncStatus::Completed;
}

template <typename F>
void await_suspend(const IAsyncAction & object, F resume)
{
    impl_suspend(object, resume);
}

inline void await_resume(const IAsyncAction & object)
{
    object.GetResults();
}

}
