
namespace Windows::Foundation {

enum class AsyncStatus
{
    Started,
    Completed,
    Canceled,
    Error,
};

}

namespace ABI::Windows::Foundation {

struct AsyncActionCompletedHandler;
template <typename TProgress> struct AsyncActionProgressHandler;
template <typename TProgress> struct AsyncActionWithProgressCompletedHandler;
template <typename TResult, typename TProgress> struct AsyncOperationProgressHandler;
template <typename TResult, typename TProgress> struct AsyncOperationWithProgressCompletedHandler;
template <typename TResult> struct AsyncOperationCompletedHandler;

struct IAsyncAction;
struct IAsyncInfo;
template <typename TProgress> struct IAsyncActionWithProgress;
template <typename TResult> struct IAsyncOperation;
template <typename TResult, typename TProgress> struct IAsyncOperationWithProgress;

struct __declspec(uuid("a4ed5c81-76c9-40bd-8be6-b1d90fb20ae7")) __declspec(novtable) AsyncActionCompletedHandler : IUnknown
{
    virtual HRESULT __stdcall abi_Invoke(IAsyncAction * asyncInfo, winrt::Windows::Foundation::AsyncStatus asyncStatus) = 0;
};

template <typename TProgress>
struct __declspec(novtable) impl_AsyncActionProgressHandler : IUnknown
{
    virtual HRESULT __stdcall abi_Invoke(IAsyncActionWithProgress<TProgress> * asyncInfo, arg_in<TProgress> progressInfo) = 0;
};

template <typename TProgress>
struct __declspec(novtable) impl_AsyncActionWithProgressCompletedHandler : IUnknown
{
    virtual HRESULT __stdcall abi_Invoke(IAsyncActionWithProgress<TProgress> * asyncInfo, winrt::Windows::Foundation::AsyncStatus status) = 0;
};

template <typename TResult, typename TProgress>
struct __declspec(novtable) impl_AsyncOperationProgressHandler : IUnknown
{
    virtual HRESULT __stdcall abi_Invoke(IAsyncOperationWithProgress<TResult, TProgress> * asyncInfo, arg_in<TProgress> progressInfo) = 0;
};

template <typename TResult, typename TProgress>
struct __declspec(novtable) impl_AsyncOperationWithProgressCompletedHandler : IUnknown
{
    virtual HRESULT __stdcall abi_Invoke(IAsyncOperationWithProgress<TResult, TProgress> * asyncInfo, winrt::Windows::Foundation::AsyncStatus status) = 0;
};

template <typename TResult>
struct __declspec(novtable) impl_AsyncOperationCompletedHandler : IUnknown
{
    virtual HRESULT __stdcall abi_Invoke(IAsyncOperation<TResult> * asyncInfo, winrt::Windows::Foundation::AsyncStatus status) = 0;
};

struct __declspec(uuid("5a648006-843a-4da9-865b-9d26e5dfad7b")) __declspec(novtable) IAsyncAction : IInspectable
{
    virtual HRESULT __stdcall put_Completed(AsyncActionCompletedHandler * handler) = 0;
    virtual HRESULT __stdcall get_Completed(AsyncActionCompletedHandler ** handler) = 0;
    virtual HRESULT __stdcall abi_GetResults() = 0;
};

struct __declspec(uuid("00000036-0000-0000-c000-000000000046")) __declspec(novtable) IAsyncInfo : IInspectable
{
    virtual HRESULT __stdcall get_Id(uint32_t * id) = 0;
    virtual HRESULT __stdcall get_Status(winrt::Windows::Foundation::AsyncStatus * status) = 0;
    virtual HRESULT __stdcall get_ErrorCode(HRESULT * errorCode) = 0;
    virtual HRESULT __stdcall abi_Cancel() = 0;
    virtual HRESULT __stdcall abi_Close() = 0;
};

template <typename TProgress>
struct __declspec(novtable) impl_IAsyncActionWithProgress : IInspectable
{
    virtual HRESULT __stdcall put_Progress(AsyncActionProgressHandler<TProgress> * handler) = 0;
    virtual HRESULT __stdcall get_Progress(AsyncActionProgressHandler<TProgress> ** handler) = 0;
    virtual HRESULT __stdcall put_Completed(AsyncActionWithProgressCompletedHandler<TProgress> * handler) = 0;
    virtual HRESULT __stdcall get_Completed(AsyncActionWithProgressCompletedHandler<TProgress> ** handler) = 0;
    virtual HRESULT __stdcall abi_GetResults() = 0;
};


template <typename TResult>
struct __declspec(novtable) impl_IAsyncOperation : IInspectable
{
    virtual HRESULT __stdcall put_Completed(AsyncOperationCompletedHandler<TResult> * handler) = 0;
    virtual HRESULT __stdcall get_Completed(AsyncOperationCompletedHandler<TResult> ** handler) = 0;
    virtual HRESULT __stdcall abi_GetResults(arg_out<TResult> results) = 0;
};

template <typename TResult, typename TProgress>
struct __declspec(novtable) impl_IAsyncOperationWithProgress : IInspectable
{
    virtual HRESULT __stdcall put_Progress(AsyncOperationProgressHandler<TResult, TProgress> * handler) = 0;
    virtual HRESULT __stdcall get_Progress(AsyncOperationProgressHandler<TResult, TProgress> ** handler) = 0;
    virtual HRESULT __stdcall put_Completed(AsyncOperationWithProgressCompletedHandler<TResult, TProgress> * handler) = 0;
    virtual HRESULT __stdcall get_Completed(AsyncOperationWithProgressCompletedHandler<TResult, TProgress> ** handler) = 0;
    virtual HRESULT __stdcall abi_GetResults(arg_out<TResult> results) = 0;
};

template <typename TProgress> struct AsyncActionProgressHandler : impl::not_specialized<AsyncActionProgressHandler<TProgress>> {};
template <typename TProgress> struct AsyncActionWithProgressCompletedHandler : impl::not_specialized<AsyncActionWithProgressCompletedHandler<TProgress>> {};
template <typename TResult, typename TProgress> struct AsyncOperationProgressHandler : impl::not_specialized<AsyncOperationProgressHandler<TResult, TProgress>> {};
template <typename TResult, typename TProgress> struct AsyncOperationWithProgressCompletedHandler : impl::not_specialized<AsyncOperationWithProgressCompletedHandler<TResult, TProgress>> {};
template <typename TResult> struct AsyncOperationCompletedHandler : impl::not_specialized<AsyncOperationCompletedHandler<TResult>> {};
template <typename TProgress> struct IAsyncActionWithProgress : impl::not_specialized<IAsyncActionWithProgress<TProgress>> {};
template <typename TResult> struct IAsyncOperation : impl::not_specialized<IAsyncOperation<TResult>> {};
template <typename TResult, typename TProgress> struct IAsyncOperationWithProgress : impl::not_specialized<IAsyncOperationWithProgress<TResult, TProgress>> {};

}

namespace Windows::Foundation {

struct AsyncActionCompletedHandler;
template <typename TProgress> struct AsyncActionProgressHandler;
template <typename TProgress> struct AsyncActionWithProgressCompletedHandler;
template <typename TResult, typename TProgress> struct AsyncOperationProgressHandler;
template <typename TResult, typename TProgress> struct AsyncOperationWithProgressCompletedHandler;
template <typename TResult> struct AsyncOperationCompletedHandler;

struct IAsyncAction;
struct IAsyncInfo;
template <typename TProgress> struct IAsyncActionWithProgress;
template <typename TResult> struct IAsyncOperation;
template <typename TResult, typename TProgress> struct IAsyncOperationWithProgress;

template <typename D>
struct WINRT_EBO impl_IAsyncAction
{
    void Completed(const AsyncActionCompletedHandler & handler) const;
    AsyncActionCompletedHandler Completed() const;
    void GetResults() const;

};

template <typename D>
struct WINRT_EBO impl_IAsyncInfo
{
    uint32_t Id() const;
    AsyncStatus Status() const;
    HRESULT ErrorCode() const;
    void Cancel() const;
    void Close() const;
};

template <typename D, typename TProgress>
struct impl_IAsyncActionWithProgress
{
    void Progress(const AsyncActionProgressHandler<TProgress> & handler) const;
    AsyncActionProgressHandler<TProgress> Progress() const;
    void Completed(const AsyncActionWithProgressCompletedHandler<TProgress> & handler) const;
    AsyncActionWithProgressCompletedHandler<TProgress> Completed() const;
    void GetResults() const;
};

template <typename D, typename TResult>
struct impl_IAsyncOperation
{
    void Completed(const AsyncOperationCompletedHandler<TResult> & handler) const;
    AsyncOperationCompletedHandler<TResult> Completed() const;
    TResult GetResults() const;
};

template <typename D, typename TResult, typename TProgress>
struct impl_IAsyncOperationWithProgress
{
    void Progress(const AsyncOperationProgressHandler<TResult, TProgress> & handler) const;
    AsyncOperationProgressHandler<TResult, TProgress> Progress() const;
    void Completed(const AsyncOperationWithProgressCompletedHandler<TResult, TProgress> & handler) const;
    AsyncOperationWithProgressCompletedHandler<TResult, TProgress> Completed() const;
    TResult GetResults() const;
};

}

namespace impl {

template <> struct traits<Windows::Foundation::AsyncActionCompletedHandler>
{
    using abi = ABI::Windows::Foundation::AsyncActionCompletedHandler;
};

template <typename TProgress> struct traits<Windows::Foundation::AsyncActionProgressHandler<TProgress>>
{
    using abi = ABI::Windows::Foundation::AsyncActionProgressHandler<abi<TProgress>>;
};

template <typename TProgress> struct traits<Windows::Foundation::AsyncActionWithProgressCompletedHandler<TProgress>>
{
    using abi = ABI::Windows::Foundation::AsyncActionWithProgressCompletedHandler<abi<TProgress>>;
};

template <typename TResult, typename TProgress> struct traits<Windows::Foundation::AsyncOperationProgressHandler<TResult, TProgress>>
{
    using abi = ABI::Windows::Foundation::AsyncOperationProgressHandler<abi<TResult>, abi<TProgress>>;
};

template <typename TResult, typename TProgress> struct traits<Windows::Foundation::AsyncOperationWithProgressCompletedHandler<TResult, TProgress>>
{
    using abi = ABI::Windows::Foundation::AsyncOperationWithProgressCompletedHandler<abi<TResult>, abi<TProgress>>;
};

template <typename TResult> struct traits<Windows::Foundation::AsyncOperationCompletedHandler<TResult>>
{
    using abi = ABI::Windows::Foundation::AsyncOperationCompletedHandler<abi<TResult>>;
};

template <> struct traits<Windows::Foundation::IAsyncAction>
{
    using abi = ABI::Windows::Foundation::IAsyncAction;
    template <typename D> using consume = Windows::Foundation::impl_IAsyncAction<D>;
};

template <> struct traits<Windows::Foundation::IAsyncInfo>
{
    using abi = ABI::Windows::Foundation::IAsyncInfo;
    template <typename D> using consume = Windows::Foundation::impl_IAsyncInfo<D>;
};

template <typename TProgress> struct traits<Windows::Foundation::IAsyncActionWithProgress<TProgress>>
{
    using abi = ABI::Windows::Foundation::IAsyncActionWithProgress<abi<TProgress>>;
    template <typename D> using consume = Windows::Foundation::impl_IAsyncActionWithProgress<D, TProgress>;
};

template <typename TResult> struct traits<Windows::Foundation::IAsyncOperation<TResult>>
{
    using abi = ABI::Windows::Foundation::IAsyncOperation<abi<TResult>>;
    template <typename D> using consume = Windows::Foundation::impl_IAsyncOperation<D, TResult>;
};

template <typename TResult, typename TProgress> struct traits<Windows::Foundation::IAsyncOperationWithProgress<TResult, TProgress>>
{
    using abi = ABI::Windows::Foundation::IAsyncOperationWithProgress<abi<TResult>, abi<TProgress>>;
    template <typename D> using consume = Windows::Foundation::impl_IAsyncOperationWithProgress<D, TResult, TProgress>;
};

}

namespace Windows::Foundation {

struct AsyncActionCompletedHandler : IUnknown
{
    AsyncActionCompletedHandler(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<AsyncActionCompletedHandler>(m_ptr); }
    template <typename L> AsyncActionCompletedHandler(L handler);
    template <typename F> AsyncActionCompletedHandler(F * handler);
    template <typename O, typename M> AsyncActionCompletedHandler(O * object, M method);
    void operator()(const IAsyncAction & asyncInfo, AsyncStatus asyncStatus) const;
};

template <typename TProgress>
struct WINRT_EBO AsyncActionProgressHandler : IUnknown
{
    AsyncActionProgressHandler(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<AsyncActionProgressHandler>(m_ptr); }
    template <typename L> AsyncActionProgressHandler(L handler);
    template <typename F> AsyncActionProgressHandler(F * handler);
    template <typename O, typename M> AsyncActionProgressHandler(O * object, M method);
    void operator()(const IAsyncActionWithProgress<TProgress> & sender, const TProgress & args) const;
};

template <typename TProgress>
struct WINRT_EBO AsyncActionWithProgressCompletedHandler : IUnknown
{
    AsyncActionWithProgressCompletedHandler(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<AsyncActionWithProgressCompletedHandler>(m_ptr); }
    template <typename L> AsyncActionWithProgressCompletedHandler(L handler);
    template <typename F> AsyncActionWithProgressCompletedHandler(F * handler);
    template <typename O, typename M> AsyncActionWithProgressCompletedHandler(O * object, M method);
    void operator()(const IAsyncActionWithProgress<TProgress> & sender, const AsyncStatus args) const;
};

template <typename TResult, typename TProgress>
struct WINRT_EBO AsyncOperationProgressHandler : IUnknown
{
    AsyncOperationProgressHandler(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<AsyncOperationProgressHandler>(m_ptr); }
    template <typename L> AsyncOperationProgressHandler(L handler);
    template <typename F> AsyncOperationProgressHandler(F * handler);
    template <typename O, typename M> AsyncOperationProgressHandler(O * object, M method);
    void operator()(const IAsyncOperationWithProgress<TResult, TProgress> & sender, const TProgress & args) const;
};

template <typename TResult, typename TProgress>
struct WINRT_EBO AsyncOperationWithProgressCompletedHandler : IUnknown
{
    AsyncOperationWithProgressCompletedHandler(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<AsyncOperationWithProgressCompletedHandler>(m_ptr); }
    template <typename L> AsyncOperationWithProgressCompletedHandler(L handler);
    template <typename F> AsyncOperationWithProgressCompletedHandler(F * handler);
    template <typename O, typename M> AsyncOperationWithProgressCompletedHandler(O * object, M method);
    void operator()(const IAsyncOperationWithProgress<TResult, TProgress> & sender, const AsyncStatus args) const;
};

template <typename TResult>
struct WINRT_EBO AsyncOperationCompletedHandler : IUnknown
{
    AsyncOperationCompletedHandler(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<AsyncOperationCompletedHandler>(m_ptr); }
    template <typename L> AsyncOperationCompletedHandler(L handler);
    template <typename F> AsyncOperationCompletedHandler(F * handler);
    template <typename O, typename M> AsyncOperationCompletedHandler(O * object, M method);
    void operator()(const IAsyncOperation<TResult> & sender, const AsyncStatus args) const;
};

struct IAsyncAction :
    IInspectable,
    impl::consume<IAsyncAction>,
    impl::require<IAsyncAction, IAsyncInfo>
{
    IAsyncAction(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IAsyncAction>(m_ptr); }
};

struct IAsyncInfo :
    IUnknown,
    impl::consume<IAsyncInfo>
{
    IAsyncInfo(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IAsyncInfo>(m_ptr); }
};

template <typename TProgress>
struct WINRT_EBO IAsyncActionWithProgress :
    IInspectable,
    impl::consume<IAsyncActionWithProgress<TProgress>>,
    impl::require<IAsyncActionWithProgress<TProgress>, IAsyncInfo>
{
    IAsyncActionWithProgress(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IAsyncActionWithProgress>(m_ptr); }
};

template <typename TResult>
struct WINRT_EBO IAsyncOperation :
    IInspectable,
    impl::consume<IAsyncOperation<TResult>>,
    impl::require<IAsyncOperation<TResult>, IAsyncInfo>
{
    IAsyncOperation(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IAsyncOperation>(m_ptr); }
};

template <typename TResult, typename TProgress>
struct WINRT_EBO IAsyncOperationWithProgress :
    IInspectable,
    impl::consume<IAsyncOperationWithProgress<TResult, TProgress>>,
    impl::require<IAsyncOperationWithProgress<TResult, TProgress>, IAsyncInfo>
{
    IAsyncOperationWithProgress(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IAsyncOperationWithProgress>(m_ptr); }
};

template <typename D>
uint32_t impl_IAsyncInfo<D>::Id() const
{
    uint32_t id = 0;
    check_hresult(static_cast<const IAsyncInfo &>(static_cast<const D &>(*this))->get_Id(&id));
    return id;
}

template <typename D>
AsyncStatus impl_IAsyncInfo<D>::Status() const
{
    AsyncStatus status{};
    check_hresult(static_cast<const IAsyncInfo &>(static_cast<const D &>(*this))->get_Status(&status));
    return status;
}

template <typename D>
HRESULT impl_IAsyncInfo<D>::ErrorCode() const
{
    HRESULT code = S_OK;
    check_hresult(static_cast<const IAsyncInfo &>(static_cast<const D &>(*this))->get_ErrorCode(&code));
    return code;
}

template <typename D>
void impl_IAsyncInfo<D>::Cancel() const
{
    check_hresult(static_cast<const IAsyncInfo &>(static_cast<const D &>(*this))->abi_Cancel());
}

template <typename D>
void impl_IAsyncInfo<D>::Close() const
{
    check_hresult(static_cast<const IAsyncInfo &>(static_cast<const D &>(*this))->abi_Close());
}

template <typename D>
void impl_IAsyncAction<D>::Completed(const AsyncActionCompletedHandler & handler) const
{
    check_hresult(static_cast<const IAsyncAction &>(static_cast<const D &>(*this))->put_Completed(winrt::get(handler)));
}

template <typename D>
AsyncActionCompletedHandler impl_IAsyncAction<D>::Completed() const
{
    AsyncActionCompletedHandler handler{};
    check_hresult(static_cast<const IAsyncAction &>(static_cast<const D &>(*this))->get_Completed(put(handler)));
    return handler;
}

template <typename D>
void impl_IAsyncAction<D>::GetResults() const
{
    check_hresult(static_cast<const IAsyncAction &>(static_cast<const D &>(*this))->abi_GetResults());
}

template <typename D, typename TProgress>
void impl_IAsyncActionWithProgress<D, TProgress>::Progress(const AsyncActionProgressHandler<TProgress> & handler) const
{
    check_hresult(static_cast<const IAsyncActionWithProgress<TProgress> &>(static_cast<const D &>(*this))->put_Progress(winrt::get(handler)));
}

template <typename D, typename TProgress>
AsyncActionProgressHandler<TProgress> impl_IAsyncActionWithProgress<D, TProgress>::Progress() const
{
    AsyncActionProgressHandler<TProgress> handler;
    check_hresult(static_cast<const IAsyncActionWithProgress<TProgress> &>(static_cast<const D &>(*this))->get_Progress(put(handler)));
    return handler;
}

template <typename D, typename TProgress>
void impl_IAsyncActionWithProgress<D, TProgress>::Completed(const AsyncActionWithProgressCompletedHandler<TProgress> & handler) const
{
    check_hresult(static_cast<const IAsyncActionWithProgress<TProgress> &>(static_cast<const D &>(*this))->put_Completed(winrt::get(handler)));
}

template <typename D, typename TProgress>
AsyncActionWithProgressCompletedHandler<TProgress> impl_IAsyncActionWithProgress<D, TProgress>::Completed() const
{
    AsyncActionWithProgressCompletedHandler<TProgress> handler;
    check_hresult(static_cast<const IAsyncActionWithProgress<TProgress> &>(static_cast<const D &>(*this))->get_Completed(put(handler)));
    return handler;
}

template <typename D, typename TProgress>
void impl_IAsyncActionWithProgress<D, TProgress>::GetResults() const
{
    check_hresult(static_cast<const IAsyncActionWithProgress<TProgress> &>(static_cast<const D &>(*this))->abi_GetResults());
}

template <typename D, typename TResult>
void impl_IAsyncOperation<D, TResult>::Completed(const AsyncOperationCompletedHandler<TResult> & handler) const
{
    check_hresult(static_cast<const IAsyncOperation<TResult> &>(static_cast<const D &>(*this))->put_Completed(winrt::get(handler)));
}

template <typename D, typename TResult>
AsyncOperationCompletedHandler<TResult> impl_IAsyncOperation<D, TResult>::Completed() const
{
    AsyncOperationCompletedHandler<TResult> temp;
    check_hresult(static_cast<const IAsyncOperation<TResult> &>(static_cast<const D &>(*this))->get_Completed(put(temp)));
    return temp;
}

template <typename D, typename TResult>
TResult impl_IAsyncOperation<D, TResult>::GetResults() const
{
    TResult result = impl::empty_value<TResult>();
    check_hresult(static_cast<const IAsyncOperation<TResult> &>(static_cast<const D &>(*this))->abi_GetResults(put(result)));
    return result;
}

template <typename D, typename TResult, typename TProgress>
void impl_IAsyncOperationWithProgress<D, TResult, TProgress>::Progress(const AsyncOperationProgressHandler<TResult, TProgress> & handler) const
{
    check_hresult(static_cast<const IAsyncOperationWithProgress<TResult, TProgress> &>(static_cast<const D &>(*this))->put_Progress(winrt::get(handler)));
}

template <typename D, typename TResult, typename TProgress>
AsyncOperationProgressHandler<TResult, TProgress> impl_IAsyncOperationWithProgress<D, TResult, TProgress>::Progress() const
{
    AsyncOperationProgressHandler<TResult, TProgress> handler;
    check_hresult(static_cast<const IAsyncOperationWithProgress<TResult, TProgress> &>(static_cast<const D &>(*this))->get_Progress(put(handler)));
    return handler;
}

template <typename D, typename TResult, typename TProgress>
void impl_IAsyncOperationWithProgress<D, TResult, TProgress>::Completed(const AsyncOperationWithProgressCompletedHandler<TResult, TProgress> & handler) const
{
    check_hresult(static_cast<const IAsyncOperationWithProgress<TResult, TProgress> &>(static_cast<const D &>(*this))->put_Completed(winrt::get(handler)));
}

template <typename D, typename TResult, typename TProgress>
AsyncOperationWithProgressCompletedHandler<TResult, TProgress> impl_IAsyncOperationWithProgress<D, TResult, TProgress>::Completed() const
{
    AsyncOperationWithProgressCompletedHandler<TResult, TProgress> handler;
    check_hresult(static_cast<const IAsyncOperationWithProgress<TResult, TProgress> &>(static_cast<const D &>(*this))->get_Completed(put(handler)));
    return handler;
}

template <typename D, typename TResult, typename TProgress>
TResult impl_IAsyncOperationWithProgress<D, TResult, TProgress>::GetResults() const
{
    TResult result = impl::empty_value<TResult>();
    check_hresult(static_cast<const IAsyncOperationWithProgress<TResult, TProgress> &>(static_cast<const D &>(*this))->abi_GetResults(put(result)));
    return result;
}

}

namespace impl {

template <typename H> struct async_action_completed_handler : implements<async_action_completed_handler<H>, abi<Windows::Foundation::AsyncActionCompletedHandler>>, H
{
    async_action_completed_handler(H && handler) : H(std::forward<H>(handler)) {}

    HRESULT __stdcall abi_Invoke(abi_arg_in<Windows::Foundation::IAsyncAction> asyncInfo, Windows::Foundation::AsyncStatus asyncStatus) noexcept override
    {
        try
        {
            (*this)(*reinterpret_cast<const Windows::Foundation::IAsyncAction *>(&asyncInfo), asyncStatus);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename TProgress, typename H>
struct async_action_progress_handler : implements<async_action_progress_handler<TProgress, H>, abi<Windows::Foundation::AsyncActionProgressHandler<TProgress>>>, H
{
    async_action_progress_handler(H && handler) : H(std::forward<H>(handler)) {}

    HRESULT __stdcall abi_Invoke(abi_arg_in<Windows::Foundation::IAsyncActionWithProgress<TProgress>> sender, abi_arg_in<TProgress> args) noexcept override
    {
        try
        {
            (*this)(*reinterpret_cast<const Windows::Foundation::IAsyncActionWithProgress<TProgress> *>(&sender), *reinterpret_cast<const TProgress *>(&args));
            return S_OK;
        }
        catch (...) { return impl::to_hresult(); }
    }
};

template <typename TProgress, typename H>
struct async_action_with_progress_completed_handler : implements<async_action_with_progress_completed_handler<TProgress, H>, abi<Windows::Foundation::AsyncActionWithProgressCompletedHandler<TProgress>>>, H
{
    async_action_with_progress_completed_handler(H && handler) : H(std::forward<H>(handler)) {}

    HRESULT __stdcall abi_Invoke(abi_arg_in<Windows::Foundation::IAsyncActionWithProgress<TProgress>> sender, Windows::Foundation::AsyncStatus args) noexcept override
    {
        try
        {
            (*this)(*reinterpret_cast<const Windows::Foundation::IAsyncActionWithProgress<TProgress> *>(&sender), args);
            return S_OK;
        }
        catch (...) { return impl::to_hresult(); }
    }
};

template <typename TResult, typename TProgress, typename H>
struct async_operation_progress_handler : implements<async_operation_progress_handler<TResult, TProgress, H>, abi<Windows::Foundation::AsyncOperationProgressHandler<TResult, TProgress>>>, H
{
    async_operation_progress_handler(H && handler) : H(std::forward<H>(handler)) {}

    HRESULT __stdcall abi_Invoke(abi_arg_in<Windows::Foundation::IAsyncOperationWithProgress<TResult, TProgress>> sender, abi_arg_in<TProgress> args) noexcept override
    {
        try
        {
            (*this)(*reinterpret_cast<const Windows::Foundation::IAsyncOperationWithProgress<TResult, TProgress> *>(&sender), *reinterpret_cast<const TProgress *>(&args));
            return S_OK;
        }
        catch (...) { return impl::to_hresult(); }
    }
};

template <typename TResult, typename TProgress, typename H>
struct async_operation_with_progress_completed_handler : implements<async_operation_with_progress_completed_handler<TResult, TProgress, H>, abi<Windows::Foundation::AsyncOperationWithProgressCompletedHandler<TResult, TProgress>>>, H
{
    async_operation_with_progress_completed_handler(H && handler) : H(std::forward<H>(handler)) {}

    HRESULT __stdcall abi_Invoke(abi_arg_in<Windows::Foundation::IAsyncOperationWithProgress<TResult, TProgress>> sender, Windows::Foundation::AsyncStatus args) noexcept override
    {
        try
        {
            (*this)(*reinterpret_cast<const Windows::Foundation::IAsyncOperationWithProgress<TResult, TProgress> *>(&sender), args);
            return S_OK;
        }
        catch (...) { return impl::to_hresult(); }
    }
};

template <typename TResult, typename H>
struct async_operation_completed_handler : implements<async_operation_completed_handler<TResult, H>, abi<Windows::Foundation::AsyncOperationCompletedHandler<TResult>>>, H
{
    async_operation_completed_handler(H && handler) : H(std::forward<H>(handler)) {}

    HRESULT __stdcall abi_Invoke(abi_arg_in<Windows::Foundation::IAsyncOperation<TResult>> sender, Windows::Foundation::AsyncStatus args) noexcept override
    {
        try
        {
            (*this)(*reinterpret_cast<const Windows::Foundation::IAsyncOperation<TResult> *>(&sender), args);
            return S_OK;
        }
        catch (...) { return impl::to_hresult(); }
    }
};

}

namespace Windows::Foundation {

template <typename L> AsyncActionCompletedHandler::AsyncActionCompletedHandler(L handler) :
    AsyncActionCompletedHandler(impl::make_delegate<impl::async_action_completed_handler<L>, AsyncActionCompletedHandler>(std::forward<L>(handler)))
{}

template <typename F> AsyncActionCompletedHandler::AsyncActionCompletedHandler(F * handler) :
    AsyncActionCompletedHandler([=](auto && ... args) { handler(args ...); })
{}

template <typename O, typename M> AsyncActionCompletedHandler::AsyncActionCompletedHandler(O * object, M method) :
    AsyncActionCompletedHandler([=](auto && ... args) { ((*object).*(method))(args ...); })
{}

inline void AsyncActionCompletedHandler::operator()(const IAsyncAction & asyncInfo, const AsyncStatus asyncStatus) const
{
    check_hresult((*this)->abi_Invoke(get(asyncInfo), asyncStatus));
}

template <typename TProgress> template <typename L> AsyncActionProgressHandler<TProgress>::AsyncActionProgressHandler(L handler) :
    AsyncActionProgressHandler(impl::make_delegate<impl::async_action_progress_handler<TProgress, L>, AsyncActionProgressHandler>(std::forward<L>(handler)))
{}

template <typename TProgress> template <typename F> AsyncActionProgressHandler<TProgress>::AsyncActionProgressHandler(F * handler) :
    AsyncActionProgressHandler([=](auto && ... args) { handler(args ...); })
{}

template <typename TProgress> template <typename O, typename M> AsyncActionProgressHandler<TProgress>::AsyncActionProgressHandler(O * object, M method) :
    AsyncActionProgressHandler([=](auto && ... args) { ((*object).*(method))(args ...); })
{}

template <typename TProgress> void AsyncActionProgressHandler<TProgress>::operator()(const IAsyncActionWithProgress<TProgress> & sender, const TProgress & args) const
{
    check_hresult((*this)->abi_Invoke(get(sender), get(args)));
}

template <typename TProgress> template <typename L> AsyncActionWithProgressCompletedHandler<TProgress>::AsyncActionWithProgressCompletedHandler(L handler) :
    AsyncActionWithProgressCompletedHandler(impl::make_delegate<impl::async_action_with_progress_completed_handler<TProgress, L>, AsyncActionWithProgressCompletedHandler<TProgress>>(std::forward<L>(handler)))
{}

template <typename TProgress> template <typename F> AsyncActionWithProgressCompletedHandler<TProgress>::AsyncActionWithProgressCompletedHandler(F * handler) :
    AsyncActionWithProgressCompletedHandler([=](auto && ... args) { handler(args ...); })
{}

template <typename TProgress> template <typename O, typename M> AsyncActionWithProgressCompletedHandler<TProgress>::AsyncActionWithProgressCompletedHandler(O * object, M method) :
    AsyncActionWithProgressCompletedHandler([=](auto && ... args) { ((*object).*(method))(args ...); })
{}

template <typename TProgress> void AsyncActionWithProgressCompletedHandler<TProgress>::operator()(const IAsyncActionWithProgress<TProgress> & sender, const AsyncStatus args) const
{
    check_hresult((*this)->abi_Invoke(get(sender), args));
}

template <typename TResult, typename TProgress> template <typename L> AsyncOperationProgressHandler<TResult, TProgress>::AsyncOperationProgressHandler(L handler) :
    AsyncOperationProgressHandler(impl::make_delegate<impl::async_operation_progress_handler<TResult, TProgress, L>, AsyncOperationProgressHandler<TResult, TProgress>>(std::forward<L>(handler)))
{}

template <typename TResult, typename TProgress> template <typename F> AsyncOperationProgressHandler<TResult, TProgress>::AsyncOperationProgressHandler(F * handler) :
    AsyncOperationProgressHandler([=](auto && ... args) { handler(args ...); })
{}

template <typename TResult, typename TProgress> template <typename O, typename M> AsyncOperationProgressHandler<TResult, TProgress>::AsyncOperationProgressHandler(O * object, M method) :
    AsyncOperationProgressHandler([=](auto && ... args) { ((*object).*(method))(args ...); })
{}

template <typename TResult, typename TProgress> void AsyncOperationProgressHandler<TResult, TProgress>::operator()(const IAsyncOperationWithProgress<TResult, TProgress> & sender, const TProgress & args) const
{
    check_hresult((*this)->abi_Invoke(get(sender), get(args)));
}

template <typename TResult, typename TProgress> template <typename L> AsyncOperationWithProgressCompletedHandler<TResult, TProgress>::AsyncOperationWithProgressCompletedHandler(L handler) :
    AsyncOperationWithProgressCompletedHandler(impl::make_delegate<impl::async_operation_with_progress_completed_handler<TResult, TProgress, L>, AsyncOperationWithProgressCompletedHandler<TResult, TProgress>>(std::forward<L>(handler)))
{}

template <typename TResult, typename TProgress> template <typename F> AsyncOperationWithProgressCompletedHandler<TResult, TProgress>::AsyncOperationWithProgressCompletedHandler(F * handler) :
    AsyncOperationWithProgressCompletedHandler([=](auto && ... args) { handler(args ...); })
{}

template <typename TResult, typename TProgress> template <typename O, typename M> AsyncOperationWithProgressCompletedHandler<TResult, TProgress>::AsyncOperationWithProgressCompletedHandler(O * object, M method) :
    AsyncOperationWithProgressCompletedHandler([=](auto && ... args) { ((*object).*(method))(args ...); })
{}

template <typename TResult, typename TProgress> void AsyncOperationWithProgressCompletedHandler<TResult, TProgress>::operator()(const IAsyncOperationWithProgress<TResult, TProgress> & sender, const AsyncStatus args) const
{
    check_hresult((*this)->abi_Invoke(get(sender), args));
}

template <typename TResult> template <typename L> AsyncOperationCompletedHandler<TResult>::AsyncOperationCompletedHandler(L handler) :
    AsyncOperationCompletedHandler(impl::make_delegate<impl::async_operation_completed_handler<TResult, L>, AsyncOperationCompletedHandler<TResult>>(std::forward<L>(handler)))
{}

template <typename TResult> template <typename F> AsyncOperationCompletedHandler<TResult>::AsyncOperationCompletedHandler(F * handler) :
    AsyncOperationCompletedHandler([=](auto && ... args) { handler(args ...); })
{}

template <typename TResult> template <typename O, typename M> AsyncOperationCompletedHandler<TResult>::AsyncOperationCompletedHandler(O * object, M method) :
    AsyncOperationCompletedHandler([=](auto && ... args) { ((*object).*(method))(args ...); })
{}

template <typename TResult> void AsyncOperationCompletedHandler<TResult>::operator()(const IAsyncOperation<TResult> & sender, const AsyncStatus args) const
{
    check_hresult((*this)->abi_Invoke(get(sender), args));
}

}
