
namespace ABI { namespace Windows { namespace Foundation {

struct AsyncActionCompletedHandler;
struct IAsyncAction;

struct __declspec(uuid("a4ed5c81-76c9-40bd-8be6-b1d90fb20ae7")) __declspec(novtable) AsyncActionCompletedHandler : IUnknown
{
    virtual HRESULT __stdcall abi_Invoke(IAsyncAction * asyncInfo, winrt::Windows::AsyncStatus asyncStatus) = 0;
};

struct __declspec(uuid("5a648006-843a-4da9-865b-9d26e5dfad7b")) __declspec(novtable) IAsyncAction : IInspectable
{
    virtual HRESULT __stdcall put_Completed(AsyncActionCompletedHandler * handler) = 0;
    virtual HRESULT __stdcall get_Completed(AsyncActionCompletedHandler ** handler) = 0;
    virtual HRESULT __stdcall abi_GetResults() = 0;
};

}}}

namespace Windows { namespace Foundation {

struct AsyncActionCompletedHandler;
struct IAsyncAction;

template <typename T>
class WINRT_EBO impl_consume_IAsyncAction
{
    auto shim() const { return impl::shim<T, IAsyncAction>(this); }

public:

    void Completed(const AsyncActionCompletedHandler & handler) const;
    AsyncActionCompletedHandler Completed() const;
    void GetResults() const;
};

template <typename T> struct impl_produce_IAsyncAction;

}}

namespace impl {

template <> struct traits<Windows::Foundation::AsyncActionCompletedHandler>
{
    using abi = ABI::Windows::Foundation::AsyncActionCompletedHandler;
};

template <> struct traits<Windows::Foundation::IAsyncAction>
{
    using abi = ABI::Windows::Foundation::IAsyncAction;
    template <typename T> using consume = Windows::Foundation::impl_consume_IAsyncAction<T>;
    template <typename T> using produce = Windows::Foundation::impl_produce_IAsyncAction<T>;
};

}

namespace Windows { namespace Foundation {

struct AsyncActionCompletedHandler : IUnknown
{
    AsyncActionCompletedHandler(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<AsyncActionCompletedHandler>(m_ptr); }
    template <typename H> AsyncActionCompletedHandler(H handler);
    template <typename O, typename M> AsyncActionCompletedHandler(O * object, M method);
    void operator()(const IAsyncAction & asyncInfo, AsyncStatus asyncStatus) const;
};

struct IAsyncAction :
    Windows::IInspectable,
    consume<IAsyncAction>,
    requires<IAsyncAction, IAsyncInfo>
{
    IAsyncAction(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IAsyncAction>(m_ptr); }
};

template <typename T>
struct impl_produce_IAsyncAction : abi<IAsyncAction>
{
    using IAsyncAction = winrt::Windows::Foundation::IAsyncAction;

    operator IAsyncAction() const noexcept
    {
        return impl::winrt_cast<IAsyncAction>(this);
    }

    void Completed(const AsyncActionCompletedHandler & handler)
    {
        throw hresult_not_implemented();
    }

    AsyncActionCompletedHandler Completed()
    {
        throw hresult_not_implemented();
    }

    void GetResults()
    {
        throw hresult_not_implemented();
    }

    HRESULT __stdcall put_Completed(abi_arg_in<AsyncActionCompletedHandler> handler) noexcept override
    {
        try
        {
            static_cast<T *>(this)->Completed(*reinterpret_cast<const AsyncActionCompletedHandler *>(&handler));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Completed(abi_arg_out<AsyncActionCompletedHandler> handler) noexcept override
    {
        try
        {
            *handler = detach(static_cast<T *>(this)->Completed());
            return S_OK;
        }
        catch (...)
        {
            *handler = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetResults() noexcept override
    {
        try
        {
            static_cast<T *>(this)->GetResults();
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename T> struct impl_AsyncActionCompletedHandler : implements<impl_AsyncActionCompletedHandler<T>, abi<AsyncActionCompletedHandler>>
{
    T m_handler;
    impl_AsyncActionCompletedHandler(T handler) : m_handler(handler) {}

    HRESULT __stdcall abi_Invoke(abi_arg_in<IAsyncAction> asyncInfo, AsyncStatus asyncStatus) noexcept override
    {
        try
        {
            m_handler(*reinterpret_cast<const IAsyncAction *>(&asyncInfo), asyncStatus);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename H> AsyncActionCompletedHandler::AsyncActionCompletedHandler(H handler) :
    AsyncActionCompletedHandler(make<impl_AsyncActionCompletedHandler<H>, AsyncActionCompletedHandler>(handler))
{}

template <typename O, typename M> AsyncActionCompletedHandler::AsyncActionCompletedHandler(O * object, M method) :
    AsyncActionCompletedHandler(std::bind(std::mem_fn(method), object, std::placeholders::_1, std::placeholders::_2))
{}

inline void AsyncActionCompletedHandler::operator()(const IAsyncAction & asyncInfo, const AsyncStatus asyncStatus) const
{
    check_hresult((*this)->abi_Invoke(get(asyncInfo), asyncStatus));
}

template <typename T> void impl_consume_IAsyncAction<T>::Completed(const AsyncActionCompletedHandler & handler) const
{
    check_hresult(shim()->put_Completed(get(handler)));
}

template <typename T> AsyncActionCompletedHandler impl_consume_IAsyncAction<T>::Completed() const
{
    AsyncActionCompletedHandler handler{};
    check_hresult(shim()->get_Completed(put(handler)));
    return handler;
}

template <typename T> void impl_consume_IAsyncAction<T>::GetResults() const
{
    check_hresult(shim()->abi_GetResults());
}

}}
