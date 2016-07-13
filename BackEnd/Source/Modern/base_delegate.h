
namespace ABI::Windows::Foundation {

template <typename T> struct EventHandler;
template <typename TSender, typename TArgs> struct TypedEventHandler;

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

}

namespace Windows::Foundation {

template <typename T> struct EventHandler;
template <typename TSender, typename TArgs> struct TypedEventHandler;

}

namespace impl {

template <typename T> struct traits<Windows::Foundation::EventHandler<T>>
{
    using abi = ABI::Windows::Foundation::EventHandler<abi<T>>;
};

template <typename TSender, typename TArgs> struct traits<Windows::Foundation::TypedEventHandler<TSender, TArgs>>
{
    using abi = ABI::Windows::Foundation::TypedEventHandler<abi<TSender>, abi<TArgs>>;
};

template <typename T, typename H>
struct event_handler : implements<event_handler<T, H>, abi<Windows::Foundation::EventHandler<T>>>, H
{
    event_handler(H && handler) : H(std::forward<H>(handler)) {}

    HRESULT __stdcall abi_Invoke(abi_arg_in<Windows::IInspectable> sender, abi_arg_in<T> args) noexcept override
    {
        try
        {
            (*this)(*reinterpret_cast<const Windows::IInspectable *>(&sender), *reinterpret_cast<const T *>(&args));
            return S_OK;
        }
        catch (...) { return impl::to_hresult(); }
    }
};

template <typename TSender, typename TArgs, typename H>
struct typed_event_handler : implements<typed_event_handler<TSender, TArgs, H>, abi<Windows::Foundation::TypedEventHandler<TSender, TArgs>>>, H
{
    typed_event_handler(H && handler) : H(std::forward<H>(handler)) {}

    HRESULT __stdcall abi_Invoke(abi_arg_in<TSender> sender, abi_arg_in<TArgs> args) noexcept override
    {
        try
        {
            (*this)(*reinterpret_cast<const TSender *>(&sender), *reinterpret_cast<const TArgs *>(&args));
            return S_OK;
        }
        catch (...) { return impl::to_hresult(); }
    }
};

}

namespace Windows::Foundation {

template <typename T>
struct WINRT_EBO EventHandler : IUnknown
{
    EventHandler(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<EventHandler>(m_ptr); }

    template <typename L>
    EventHandler(L handler) :
        EventHandler(impl::make_delegate<impl::event_handler<T, L>, EventHandler<T>>(std::forward<L>(handler)))
    {}

    template <typename F> EventHandler(F * handler) :
        EventHandler([=](auto && ... args) { handler(args ...); })
    {}

    template <typename O, typename M> EventHandler(O * object, M method) :
        EventHandler([=](auto && ... args) { ((*object).*(method))(args ...); })
    {}

    void operator()(const IInspectable & sender, const T & args) const
    {
        check_hresult((*this)->abi_Invoke(get(sender), get(args)));
    }
};

template <typename TSender, typename TArgs>
struct WINRT_EBO TypedEventHandler : IUnknown
{
    TypedEventHandler(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<TypedEventHandler>(m_ptr); }

    template <typename L>
    TypedEventHandler(L handler) :
        TypedEventHandler(impl::make_delegate<impl::typed_event_handler<TSender, TArgs, L>, TypedEventHandler<TSender, TArgs>>(std::forward<L>(handler)))
    {}

    template <typename F> TypedEventHandler(F * handler) :
        TypedEventHandler([=](auto && ... args) { handler(args ...); })
    {}

    template <typename O, typename M> TypedEventHandler(O * object, M method) :
        TypedEventHandler([=](auto && ... args) { ((*object).*(method))(args ...); })
    {}

    void operator()(const TSender & sender, const TArgs & args) const
    {
        check_hresult((*this)->abi_Invoke(get(sender), get(args)));
    }
};

}
