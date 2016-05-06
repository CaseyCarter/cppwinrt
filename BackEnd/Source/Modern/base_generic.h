
namespace impl {

template <typename T, typename Enable = void>
struct argument
{
    static constexpr T empty() noexcept
    {
        return{};
    }
};

template <typename T>
struct argument<T, std::enable_if_t<std::is_base_of<Windows::IUnknown, T>::value>>
{
    static constexpr T empty() noexcept
    {
        return nullptr;
    }
};

}

namespace ABI { namespace Windows { namespace Foundation {

template <typename TProgress> struct AsyncActionProgressHandler;
template <typename TProgress> struct IAsyncActionWithProgress;
template <typename TProgress> struct AsyncActionWithProgressCompletedHandler;
template <typename TResult, typename TProgress> struct AsyncOperationProgressHandler;
template <typename TResult, typename TProgress> struct AsyncOperationWithProgressCompletedHandler;
template <typename TResult> struct AsyncOperationCompletedHandler;
template <typename T> struct EventHandler;
template <typename TSender, typename TArgs> struct TypedEventHandler;
template <typename TResult> struct IAsyncOperation;
template <typename TResult, typename TProgress> struct IAsyncOperationWithProgress;
template <typename T> struct IReference;

template <typename TProgress>
struct __declspec(novtable) impl_AsyncActionProgressHandler : IUnknown
{
    virtual HRESULT __stdcall abi_Invoke(IAsyncActionWithProgress<TProgress> * asyncInfo, arg_in<TProgress> progressInfo) = 0;
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

template <typename TProgress>
struct __declspec(novtable) impl_AsyncActionWithProgressCompletedHandler : IUnknown
{
    virtual HRESULT __stdcall abi_Invoke(IAsyncActionWithProgress<TProgress> * asyncInfo, winrt::Windows::AsyncStatus status) = 0;
};

template <typename TResult, typename TProgress>
struct __declspec(novtable) impl_AsyncOperationProgressHandler : IUnknown
{
    virtual HRESULT __stdcall abi_Invoke(IAsyncOperationWithProgress<TResult, TProgress> * asyncInfo, arg_in<TProgress> progressInfo) = 0;
};

template <typename TResult, typename TProgress>
struct __declspec(novtable) impl_AsyncOperationWithProgressCompletedHandler : IUnknown
{
    virtual HRESULT __stdcall abi_Invoke(IAsyncOperationWithProgress<TResult, TProgress> * asyncInfo, winrt::Windows::AsyncStatus status) = 0;
};

template <typename TResult>
struct __declspec(novtable) impl_AsyncOperationCompletedHandler : IUnknown
{
    virtual HRESULT __stdcall abi_Invoke(IAsyncOperation<TResult> * asyncInfo, winrt::Windows::AsyncStatus status) = 0;
};

template <typename T>
struct __declspec(novtable) impl_EventHandler : IUnknown
{
    virtual HRESULT __stdcall abi_Invoke(IInspectable * sender, arg_in<T> args) = 0;
};

template <typename TSender, typename TArgs>
struct __declspec(novtable) impl_TypedEventHandler : IUnknown
{
    virtual HRESULT __stdcall abi_Invoke(arg_in<TSender> sender, arg_in<TArgs> args) = 0;
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

template <typename T>
struct __declspec(novtable) impl_IReference : IInspectable
{
    virtual HRESULT __stdcall get_Value(arg_out<T> value) = 0;
};

}}}

namespace Windows { namespace Foundation {

template <typename TProgress> struct AsyncActionProgressHandler;
template <typename TProgress> struct IAsyncActionWithProgress;
template <typename TProgress> struct AsyncActionWithProgressCompletedHandler;
template <typename TResult, typename TProgress> struct AsyncOperationProgressHandler;
template <typename TResult, typename TProgress> struct AsyncOperationWithProgressCompletedHandler;
template <typename TResult> struct AsyncOperationCompletedHandler;
template <typename T> struct EventHandler;
template <typename TSender, typename TArgs> struct TypedEventHandler;
template <typename TResult> struct IAsyncOperation;
template <typename TResult, typename TProgress> struct IAsyncOperationWithProgress;
template <typename T> struct IReference;

template <typename D, typename TProgress>
class impl_consume_IAsyncActionWithProgress
{
    auto shim() const { return impl::shim<D, IAsyncActionWithProgress<TProgress>>(this); }

public:

    void Progress(const AsyncActionProgressHandler<TProgress> & handler) const
    {
        check_hresult(shim()->put_Progress(get(handler)));
    }

    AsyncActionProgressHandler<TProgress> Progress() const
    {
        AsyncActionProgressHandler<TProgress> handler;
        check_hresult(shim()->get_Progress(put(handler)));
        return handler;
    }

    void Completed(const AsyncActionWithProgressCompletedHandler<TProgress> & handler) const
    {
        check_hresult(shim()->put_Completed(get(handler)));
    }

    AsyncActionWithProgressCompletedHandler<TProgress> Completed() const
    {
        AsyncActionWithProgressCompletedHandler<TProgress> handler;
        check_hresult(shim()->get_Completed(put(handler)));
        return handler;
    }

    void GetResults() const
    {
        check_hresult(shim()->abi_GetResults());
    }
};

template <typename D, typename TResult>
class impl_consume_IAsyncOperation
{
    auto shim() const { return impl::shim<D, IAsyncOperation<TResult>>(this); }

public:

    void Completed(const AsyncOperationCompletedHandler<TResult> & handler) const
    {
        check_hresult(shim()->put_Completed(get(handler)));
    }

    AsyncOperationCompletedHandler<TResult> Completed() const
    {
        AsyncOperationCompletedHandler<TResult> temp;
        check_hresult(shim()->get_Completed(put(temp)));
        return temp;
    }

    TResult GetResults() const
    {
        TResult result = impl::argument<TResult>::empty();
        check_hresult(shim()->abi_GetResults(put(result)));
        return result;
    }
};

template <typename D, typename TResult, typename TProgress>
class impl_consume_IAsyncOperationWithProgress
{
    auto shim() const { return impl::shim<D, IAsyncOperationWithProgress<TResult, TProgress>>(this); }

public:

    void Progress(const AsyncOperationProgressHandler<TResult, TProgress> & handler) const
    {
        check_hresult(shim()->put_Progress(get(handler)));
    }

    AsyncOperationProgressHandler<TResult, TProgress> Progress() const
    {
        AsyncOperationProgressHandler<TResult, TProgress> handler;
        check_hresult(shim()->get_Progress(put(handler)));
        return handler;
    }

    void Completed(const AsyncOperationWithProgressCompletedHandler<TResult, TProgress> & handler) const
    {
        check_hresult(shim()->put_Completed(get(handler)));
    }

    AsyncOperationWithProgressCompletedHandler<TResult, TProgress> Completed() const
    {
        AsyncOperationWithProgressCompletedHandler<TResult, TProgress> handler;
        check_hresult(shim()->get_Completed(put(handler)));
        return handler;
    }

    TResult GetResults() const
    {
        TResult result = impl::argument<TResult>::empty();
        check_hresult(shim()->abi_GetResults(put(result)));
        return result;
    }
};

template <typename D, typename T>
class impl_consume_IReference
{
    auto shim() const { return impl::shim<D, IReference<T>>(this); }

public:

    T Value() const
    {
        T result = impl::argument<T>::empty();
        check_hresult(shim()->get_Value(put(result)));
        return result;
    }
};

}}

namespace impl {

template <typename TProgress> struct traits<Windows::Foundation::AsyncActionProgressHandler<TProgress>>
{
    using abi = ABI::Windows::Foundation::AsyncActionProgressHandler<abi<TProgress>>;
};

template <typename TProgress> struct traits<Windows::Foundation::IAsyncActionWithProgress<TProgress>>
{
    using abi = ABI::Windows::Foundation::IAsyncActionWithProgress<abi<TProgress>>;
    template <typename D> using consume = Windows::Foundation::impl_consume_IAsyncActionWithProgress<D, TProgress>;
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

template <typename T> struct traits<Windows::Foundation::EventHandler<T>>
{
    using abi = ABI::Windows::Foundation::EventHandler<abi<T>>;
};

template <typename TSender, typename TArgs> struct traits<Windows::Foundation::TypedEventHandler<TSender, TArgs>>
{
    using abi = ABI::Windows::Foundation::TypedEventHandler<abi<TSender>, abi<TArgs>>;
};

template <typename TResult> struct traits<Windows::Foundation::IAsyncOperation<TResult>>
{
    using abi = ABI::Windows::Foundation::IAsyncOperation<abi<TResult>>;
    template <typename D> using consume = Windows::Foundation::impl_consume_IAsyncOperation<D, TResult>;
};

template <typename TResult, typename TProgress> struct traits<Windows::Foundation::IAsyncOperationWithProgress<TResult, TProgress>>
{
    using abi = ABI::Windows::Foundation::IAsyncOperationWithProgress<abi<TResult>, abi<TProgress>>;
    template <typename D> using consume = Windows::Foundation::impl_consume_IAsyncOperationWithProgress<D, TResult, TProgress>;
};

template <typename T> struct traits<Windows::Foundation::IReference<T>>
{
    using abi = ABI::Windows::Foundation::IReference<abi<T>>;
    template <typename D> using consume = Windows::Foundation::impl_consume_IReference<D, T>;
};

}

namespace Windows { namespace Foundation {


template <typename TProgress>
struct WINRT_EBO AsyncActionProgressHandler : IUnknown
{
    AsyncActionProgressHandler(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<AsyncActionProgressHandler>(m_ptr); }
    template <typename H> AsyncActionProgressHandler(H handler);
    template <typename Object, typename Method> AsyncActionProgressHandler(Object * object, Method method);
    void operator()(const IAsyncActionWithProgress<TProgress> & sender, const TProgress & args) const;
};

template <typename TProgress>
struct WINRT_EBO IAsyncActionWithProgress :
    IInspectable,
    consume<IAsyncActionWithProgress<TProgress>>,
    requires<IAsyncActionWithProgress<TProgress>, IAsyncInfo>
{
    IAsyncActionWithProgress(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IAsyncActionWithProgress>(m_ptr); }
};

template <typename TProgress>
struct WINRT_EBO AsyncActionWithProgressCompletedHandler : IUnknown
{
    AsyncActionWithProgressCompletedHandler(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<AsyncActionWithProgressCompletedHandler>(m_ptr); }
    template <typename H> AsyncActionWithProgressCompletedHandler(H handler);
    template <typename Object, typename Method> AsyncActionWithProgressCompletedHandler(Object * object, Method method);
    void operator()(const IAsyncActionWithProgress<TProgress> & sender, const AsyncStatus args) const;
};

template <typename TResult, typename TProgress>
struct WINRT_EBO AsyncOperationProgressHandler : IUnknown
{
    AsyncOperationProgressHandler(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<AsyncOperationProgressHandler>(m_ptr); }
    template <typename H> AsyncOperationProgressHandler(H handler);
    template <typename Object, typename Method> AsyncOperationProgressHandler(Object * object, Method method);
    void operator()(const IAsyncOperationWithProgress<TResult, TProgress> & sender, const TProgress & args) const;
};

template <typename TResult, typename TProgress>
struct WINRT_EBO AsyncOperationWithProgressCompletedHandler : IUnknown
{
    AsyncOperationWithProgressCompletedHandler(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<AsyncOperationWithProgressCompletedHandler>(m_ptr); }
    template <typename H> AsyncOperationWithProgressCompletedHandler(H handler);
    template <typename Object, typename Method> AsyncOperationWithProgressCompletedHandler(Object * object, Method method);
    void operator()(const IAsyncOperationWithProgress<TResult, TProgress> & sender, const AsyncStatus args) const;
};

template <typename TResult>
struct WINRT_EBO AsyncOperationCompletedHandler : IUnknown
{
    AsyncOperationCompletedHandler(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<AsyncOperationCompletedHandler>(m_ptr); }
    template <typename H> AsyncOperationCompletedHandler(H handler);
    template <typename Object, typename Method> AsyncOperationCompletedHandler(Object * object, Method method);
    void operator()(const IAsyncOperation<TResult> & sender, const AsyncStatus args) const;
};

template <typename T>
struct WINRT_EBO EventHandler : IUnknown
{
    EventHandler(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<EventHandler>(m_ptr); }
    template <typename Handler> EventHandler(Handler handler);
    template <typename Object, typename Method> EventHandler(Object * object, Method method);
    void operator()(const IInspectable & sender, const T & args) const;
};

template <typename TSender, typename TArgs>
struct WINRT_EBO TypedEventHandler : IUnknown
{
    TypedEventHandler(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<TypedEventHandler>(m_ptr); }
    template <typename Handler> TypedEventHandler(Handler handler);
    template <typename Object, typename Method> TypedEventHandler(Object * object, Method method);
    void operator()(const TSender & sender, const TArgs & args) const;
};

template <typename TResult>
struct WINRT_EBO IAsyncOperation :
    IInspectable,
    consume<IAsyncOperation<TResult>>,
    requires<IAsyncOperation<TResult>, IAsyncInfo>
{
    IAsyncOperation(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IAsyncOperation>(m_ptr); }
};

template <typename TResult, typename TProgress>
struct WINRT_EBO IAsyncOperationWithProgress :
    IInspectable,
    consume<IAsyncOperationWithProgress<TResult, TProgress>>,
    requires<IAsyncOperationWithProgress<TResult, TProgress>, IAsyncInfo>
{
    IAsyncOperationWithProgress(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IAsyncOperationWithProgress>(m_ptr); }
};

struct IPropertyValue;

template <typename T>
struct WINRT_EBO IReference :
    IInspectable,
    consume<IReference<T>> //,
    // requires<IReference<T>, IPropertyValue>
{
    IReference(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IReference>(m_ptr); }

    IReference(const T & value);
};

template <typename TProgress, typename H>
struct impl_AsyncActionProgressHandler : implements<impl_AsyncActionProgressHandler<TProgress, H>, abi<AsyncActionProgressHandler<TProgress>>>
{
    H m_handler;
    impl_AsyncActionProgressHandler(H handler) : m_handler(handler) {}

    HRESULT __stdcall abi_Invoke(abi_arg_in<IAsyncActionWithProgress<TProgress>> sender, abi_arg_in<TProgress> args) noexcept override
    {
        try
        {
            m_handler(*reinterpret_cast<const IAsyncActionWithProgress<TProgress> *>(&sender), *reinterpret_cast<const TProgress *>(&args));
            return S_OK;
        }
        catch (...) { return impl::to_hresult(); }
    }
};

template <typename TProgress> template <typename H> AsyncActionProgressHandler<TProgress>::AsyncActionProgressHandler(H handler) :
    AsyncActionProgressHandler(make<impl_AsyncActionProgressHandler<TProgress, H>, AsyncActionProgressHandler>(handler))
{}

template <typename TProgress> template <typename Object, typename Method> AsyncActionProgressHandler<TProgress>::AsyncActionProgressHandler(Object * object, Method method) :
    AsyncActionProgressHandler(std::bind(std::mem_fn(method), object, std::placeholders::_1, std::placeholders::_2))
{}

template <typename TProgress> void AsyncActionProgressHandler<TProgress>::operator()(const IAsyncActionWithProgress<TProgress> & sender, const TProgress & args) const
{
    check_hresult((*this)->abi_Invoke(get(sender), get(args)));
}

template <typename TProgress, typename H>
struct impl_AsyncActionWithProgressCompletedHandler : implements<impl_AsyncActionWithProgressCompletedHandler<TProgress, H>, abi<AsyncActionWithProgressCompletedHandler<TProgress>>>
{
    H m_handler;
    impl_AsyncActionWithProgressCompletedHandler(H handler) : m_handler(handler) {}

    HRESULT __stdcall abi_Invoke(abi_arg_in<IAsyncActionWithProgress<TProgress>> sender, AsyncStatus args) noexcept override
    {
        try
        {
            m_handler(*reinterpret_cast<const IAsyncActionWithProgress<TProgress> *>(&sender), args);
            return S_OK;
        }
        catch (...) { return impl::to_hresult(); }
    }
};

template <typename TProgress> template <typename H> AsyncActionWithProgressCompletedHandler<TProgress>::AsyncActionWithProgressCompletedHandler(H handler) :
    AsyncActionWithProgressCompletedHandler(make<impl_AsyncActionWithProgressCompletedHandler<TProgress, H>, AsyncActionWithProgressCompletedHandler<TProgress>>(handler))
{}

template <typename TProgress> template <typename Object, typename Method> AsyncActionWithProgressCompletedHandler<TProgress>::AsyncActionWithProgressCompletedHandler(Object * object, Method method) :
    AsyncActionWithProgressCompletedHandler(std::bind(std::mem_fn(method), object, std::placeholders::_1, std::placeholders::_2))
{}

template <typename TProgress> void AsyncActionWithProgressCompletedHandler<TProgress>::operator()(const IAsyncActionWithProgress<TProgress> & sender, const AsyncStatus args) const
{
    check_hresult((*this)->abi_Invoke(get(sender), args));
}

template <typename TResult, typename TProgress, typename H>
struct impl_AsyncOperationProgressHandler : implements<impl_AsyncOperationProgressHandler<TResult, TProgress, H>, abi<AsyncOperationProgressHandler<TResult, TProgress>>>
{
    H m_handler;
    impl_AsyncOperationProgressHandler(H handler) : m_handler(handler) {}

    HRESULT __stdcall abi_Invoke(abi_arg_in<IAsyncOperationWithProgress<TResult, TProgress>> sender, abi_arg_in<TProgress> args) noexcept override
    {
        try
        {
            m_handler(*reinterpret_cast<const IAsyncOperationWithProgress<TResult, TProgress> *>(&sender), *reinterpret_cast<const TProgress *>(&args));
            return S_OK;
        }
        catch (...) { return impl::to_hresult(); }
    }
};

template <typename TResult, typename TProgress> template <typename H> AsyncOperationProgressHandler<TResult, TProgress>::AsyncOperationProgressHandler(H handler) :
    AsyncOperationProgressHandler(make<impl_AsyncOperationProgressHandler<TResult, TProgress, H>, AsyncOperationProgressHandler<TResult, TProgress>>(handler))
{}

template <typename TResult, typename TProgress> template <typename Object, typename Method> AsyncOperationProgressHandler<TResult, TProgress>::AsyncOperationProgressHandler(Object * object, Method method) :
    AsyncOperationProgressHandler(std::bind(std::mem_fn(method), object, std::placeholders::_1, std::placeholders::_2))
{}

template <typename TResult, typename TProgress> void AsyncOperationProgressHandler<TResult, TProgress>::operator()(const IAsyncOperationWithProgress<TResult, TProgress> & sender, const TProgress & args) const
{
    check_hresult((*this)->abi_Invoke(get(sender), get(args)));
}

template <typename TResult, typename TProgress, typename H>
struct impl_AsyncOperationWithProgressCompletedHandler : implements<impl_AsyncOperationWithProgressCompletedHandler<TResult, TProgress, H>, abi<AsyncOperationWithProgressCompletedHandler<TResult, TProgress>>>
{
    H m_handler;
    impl_AsyncOperationWithProgressCompletedHandler(H handler) : m_handler(handler) {}

    HRESULT __stdcall abi_Invoke(abi_arg_in<IAsyncOperationWithProgress<TResult, TProgress>> sender, AsyncStatus args) noexcept override
    {
        try
        {
            m_handler(*reinterpret_cast<const IAsyncOperationWithProgress<TResult, TProgress> *>(&sender), args);
            return S_OK;
        }
        catch (...) { return impl::to_hresult(); }
    }
};

template <typename TResult, typename TProgress> template <typename H> AsyncOperationWithProgressCompletedHandler<TResult, TProgress>::AsyncOperationWithProgressCompletedHandler(H handler) :
    AsyncOperationWithProgressCompletedHandler(make<impl_AsyncOperationWithProgressCompletedHandler<TResult, TProgress, H>, AsyncOperationWithProgressCompletedHandler<TResult, TProgress>>(handler))
{}

template <typename TResult, typename TProgress> template <typename Object, typename Method> AsyncOperationWithProgressCompletedHandler<TResult, TProgress>::AsyncOperationWithProgressCompletedHandler(Object * object, Method method) :
    AsyncOperationWithProgressCompletedHandler(std::bind(std::mem_fn(method), object, std::placeholders::_1, std::placeholders::_2))
{}

template <typename TResult, typename TProgress> void AsyncOperationWithProgressCompletedHandler<TResult, TProgress>::operator()(const IAsyncOperationWithProgress<TResult, TProgress> & sender, const AsyncStatus args) const
{
    check_hresult((*this)->abi_Invoke(get(sender), args));
}

template <typename TResult, typename H>
struct impl_AsyncOperationCompletedHandler : implements<impl_AsyncOperationCompletedHandler<TResult, H>, abi<AsyncOperationCompletedHandler<TResult>>>
{
    H m_handler;
    impl_AsyncOperationCompletedHandler(H handler) : m_handler(handler) {}

    HRESULT __stdcall abi_Invoke(abi_arg_in<IAsyncOperation<TResult>> sender, AsyncStatus args) noexcept override
    {
        try
        {
            m_handler(*reinterpret_cast<const IAsyncOperation<TResult> *>(&sender), args);
            return S_OK;
        }
        catch (...) { return impl::to_hresult(); }
    }
};

template <typename TResult> template <typename H> AsyncOperationCompletedHandler<TResult>::AsyncOperationCompletedHandler(H handler) :
    AsyncOperationCompletedHandler(make<impl_AsyncOperationCompletedHandler<TResult, H>, AsyncOperationCompletedHandler<TResult>>(handler))
{}

template <typename TResult> template <typename Object, typename Method> AsyncOperationCompletedHandler<TResult>::AsyncOperationCompletedHandler(Object * object, Method method) :
    AsyncOperationCompletedHandler(std::bind(std::mem_fn(method), object, std::placeholders::_1, std::placeholders::_2))
{}

template <typename TResult> void AsyncOperationCompletedHandler<TResult>::operator()(const IAsyncOperation<TResult> & sender, const AsyncStatus args) const
{
    check_hresult((*this)->abi_Invoke(get(sender), args));
}

template <typename T, typename H>
struct impl_EventHandler : implements<impl_EventHandler<T, H>, abi<EventHandler<T>>>
{
    H m_handler;
    impl_EventHandler(H handler) : m_handler(handler) {}

    HRESULT __stdcall abi_Invoke(abi_arg_in<IInspectable> sender, abi_arg_in<T> args) noexcept override
    {
        try
        {
            m_handler(*reinterpret_cast<const IInspectable *>(&sender), *reinterpret_cast<const T *>(&args));
            return S_OK;
        }
        catch (...) { return impl::to_hresult(); }
    }
};

template <typename T> template <typename Handler> EventHandler<T>::EventHandler(Handler handler) :
    EventHandler(make<impl_EventHandler<T, Handler>, EventHandler<T>>(handler))
{}

template <typename T> template <typename Object, typename Method> EventHandler<T>::EventHandler(Object * object, Method method) :
    EventHandler(std::bind(std::mem_fn(method), object, std::placeholders::_1, std::placeholders::_2))
{}

template <typename T> void EventHandler<T>::operator()(const IInspectable & sender, const T & args) const
{
    check_hresult((*this)->abi_Invoke(get(sender), get(args)));
}

template <typename TSender, typename TArgs, typename H>
struct impl_TypedEventHandler : implements<impl_TypedEventHandler<TSender, TArgs, H>, abi<TypedEventHandler<TSender, TArgs>>>
{
    H m_handler;
    impl_TypedEventHandler(H handler) : m_handler(handler) {}

    HRESULT __stdcall abi_Invoke(abi_arg_in<TSender> sender, abi_arg_in<TArgs> args) noexcept override
    {
        try
        {
            m_handler(*reinterpret_cast<const TSender *>(&sender), *reinterpret_cast<const TArgs *>(&args));
            return S_OK;
        }
        catch (...) { return impl::to_hresult(); }
    }
};

template <typename TSender, typename TArgs> template <typename Handler> TypedEventHandler<TSender, TArgs>::TypedEventHandler(Handler handler) :
    TypedEventHandler(make<impl_TypedEventHandler<TSender, TArgs, Handler>, TypedEventHandler<TSender, TArgs>>(handler))
{}

template <typename TSender, typename TArgs> template <typename Object, typename Method> TypedEventHandler<TSender, TArgs>::TypedEventHandler(Object * object, Method method) :
    TypedEventHandler(std::bind(std::mem_fn(method), object, std::placeholders::_1, std::placeholders::_2))
{}

template <typename TSender, typename TArgs> void TypedEventHandler<TSender, TArgs>::operator()(const TSender & sender, const TArgs & args) const
{
    check_hresult((*this)->abi_Invoke(get(sender), get(args)));
}

}}
