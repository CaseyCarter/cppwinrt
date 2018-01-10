
WINRT_EXPORT namespace winrt::Windows::Foundation
{
    template <typename T> struct EventHandler;
    template <typename TSender, typename TArgs> struct TypedEventHandler;
}

namespace winrt::impl
{
    template <typename T, typename H>
    struct implements_delegate : abi_t<T>, H
    {
        implements_delegate(H&& handler) : H(std::forward<H>(handler)) {}

        HRESULT __stdcall QueryInterface(GUID const& id, void** result) noexcept final
        {
            if (id == guid_of<T>() || id == guid_of<Windows::Foundation::IUnknown>() || id == guid_of<IAgileObject>())
            {
                *result = static_cast<abi_t<T>*>(this);
                AddRef();
                return S_OK;
            }

            if (id == guid_of<IMarshal>())
            {
                *result = new (std::nothrow) free_threaded_marshaler(this);
                return *result ? S_OK : E_OUTOFMEMORY;
            }

            *result = nullptr;
            return E_NOINTERFACE;
        }

        unsigned long __stdcall AddRef() noexcept final
        {
            return 1 + m_references.fetch_add(1, std::memory_order_relaxed);
        }

        unsigned long __stdcall Release() noexcept final
        {
            uint32_t const target = m_references.fetch_sub(1, std::memory_order_release) - 1;

            if (target == 0)
            {
                std::atomic_thread_fence(std::memory_order_acquire);
                delete this;
            }

            return target;
        }

    private:

        std::atomic<uint32_t> m_references{ 1 };
    };

    template <typename T, typename H>
    auto make_delegate(H&& handler)
    {
        T instance{};
        *put_abi(instance) = (new delegate_t<T, H>(std::forward<H>(handler)));
        return instance;
    }

    template <typename T>
    struct abi<Windows::Foundation::EventHandler<T>>
    {
        struct __declspec(novtable) type : IUnknown
        {
            virtual HRESULT __stdcall Invoke(void* sender, arg_in<T> args) noexcept = 0;
        };
    };

    template <typename TSender, typename TArgs>
    struct abi<Windows::Foundation::TypedEventHandler<TSender, TArgs>>
    {
        struct __declspec(novtable) type : IUnknown
        {
            virtual HRESULT __stdcall Invoke(arg_in<TSender> sender, arg_in<TArgs> args) noexcept = 0;
        };
    };

    template <typename T>
    struct delegate<Windows::Foundation::EventHandler<T>>
    {
        template <typename H>
        struct type : implements_delegate<Windows::Foundation::EventHandler<T>, H>
        {
            type(H&& handler) : implements_delegate<Windows::Foundation::EventHandler<T>, H>(std::forward<H>(handler)) {}

            HRESULT __stdcall Invoke(void* sender, arg_in<T> args) noexcept final
            {
                try
                {
                    (*this)(*reinterpret_cast<Windows::Foundation::IInspectable const*>(&sender), *reinterpret_cast<T const*>(&args));
                    return S_OK;
                }
                catch (...) { return to_hresult(); }
            }
        };
    };

    template <typename TSender, typename TArgs>
    struct delegate<Windows::Foundation::TypedEventHandler<TSender, TArgs>>
    {
        template <typename H>
        struct type : implements_delegate<Windows::Foundation::TypedEventHandler<TSender, TArgs>, H>
        {
            type(H&& handler) : implements_delegate<Windows::Foundation::TypedEventHandler<TSender, TArgs>, H>(std::forward<H>(handler)) {}

            HRESULT __stdcall Invoke(arg_in<TSender> sender, arg_in<TArgs> args) noexcept final
            {
                try
                {
                    (*this)(*reinterpret_cast<TSender const*>(&sender), *reinterpret_cast<TArgs const*>(&args));
                    return S_OK;
                }
                catch (...) { return to_hresult(); }
            }
        };
    };

    template <typename T>
    struct guid<Windows::Foundation::EventHandler<T>>
    {
        static constexpr GUID value{ pinterface_guid<Windows::Foundation::EventHandler<T>>::value };
    };

    template <typename TSender, typename TArgs>
    struct guid<Windows::Foundation::TypedEventHandler<TSender, TArgs>>
    {
        static constexpr GUID value{ pinterface_guid<Windows::Foundation::TypedEventHandler<TSender, TArgs>>::value };
    };

    template <typename T>
    struct name<Windows::Foundation::EventHandler<T>>
    {
        static constexpr auto value{ L"Windows.Foundation.EventHandler`1<" + to_array(name_v<T>) + L">" };
    };

    template <typename TSender, typename TArgs>
    struct name<Windows::Foundation::TypedEventHandler<TSender, TArgs>>
    {
        static constexpr auto value{ L"Windows.Foundation.TypedEventHandler`2<" + to_array(name_v<TSender>) + L", " + to_array(name_v<TArgs>) + L">" };
    };

    template <typename T>
    struct category<Windows::Foundation::EventHandler<T>>
    {
        using type = pinterface_category<T>;
        static constexpr GUID value{ 0x9de1c535, 0x6ae1, 0x11e0,{ 0x84, 0xe1, 0x18, 0xa9, 0x05, 0xbc, 0xc5, 0x3f } };
    };

    template <typename TSender, typename TArgs>
    struct category<Windows::Foundation::TypedEventHandler<TSender, TArgs>>
    {
        using type = pinterface_category<TSender, TArgs>;
        static constexpr GUID value{ 0x9de1c534, 0x6ae1, 0x11e0,{ 0x84, 0xe1, 0x18, 0xa9, 0x05, 0xbc, 0xc5, 0x3f } };
    };
}

WINRT_EXPORT namespace winrt::Windows::Foundation
{
    template <typename T>
    struct WINRT_EBO EventHandler : IUnknown
    {
        static_assert(impl::has_category_v<T>, "T must be WinRT type.");
        EventHandler(std::nullptr_t = nullptr) noexcept {}

        template <typename L>
        EventHandler(L handler) :
            EventHandler(impl::make_delegate<EventHandler<T>>(std::forward<L>(handler)))
        {}

        template <typename F> EventHandler(F* handler) :
            EventHandler([=](auto&&... args) { handler(args...); })
        {}

        template <typename O, typename M> EventHandler(O* object, M method) :
            EventHandler([=](auto&&... args) { ((*object).*(method))(args...); })
        {}

        void operator()(IInspectable const& sender, T const& args) const
        {
            check_hresult((*(impl::abi_t<EventHandler<T>>**)this)->Invoke(get_abi(sender), get_abi(args)));
        }
    };

    template <typename TSender, typename TArgs>
    struct WINRT_EBO TypedEventHandler : IUnknown
    {
        static_assert(impl::has_category_v<TSender>, "TSender must be WinRT type.");
        static_assert(impl::has_category_v<TArgs>, "TArgs must be WinRT type.");
        TypedEventHandler(std::nullptr_t = nullptr) noexcept {}

        template <typename L>
        TypedEventHandler(L handler) :
            TypedEventHandler(impl::make_delegate<TypedEventHandler<TSender, TArgs>>(std::forward<L>(handler)))
        {}

        template <typename F> TypedEventHandler(F* handler) :
            TypedEventHandler([=](auto&&... args) { handler(args...); })
        {}

        template <typename O, typename M> TypedEventHandler(O* object, M method) :
            TypedEventHandler([=](auto&&... args) { ((*object).*(method))(args...); })
        {}

        void operator()(TSender const& sender, TArgs const& args) const
        {
            check_hresult((*(impl::abi_t<TypedEventHandler<TSender, TArgs>>**)this)->Invoke(get_abi(sender), get_abi(args)));
        }
    };
}
