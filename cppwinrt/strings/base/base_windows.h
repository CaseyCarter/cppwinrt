
WINRT_EXPORT namespace winrt::Windows::Foundation
{
    enum class TrustLevel
    {
        BaseTrust,
        PartialTrust,
        FullTrust
    };

    struct IUnknown;
    struct IInspectable;
    struct IInspectable;
    struct IActivationFactory;
}

WINRT_EXPORT namespace winrt
{
    void check_hresult(HRESULT result);

    template <typename T>
    struct com_ptr;

    template <typename T, typename = std::enable_if_t<!std::is_base_of_v<Windows::Foundation::IUnknown, T>>>
    auto get_abi(T const& object) noexcept
    {
        return reinterpret_cast<impl::abi_t<T> const&>(object);
    }

    template <typename T, typename = std::enable_if_t<!std::is_base_of_v<Windows::Foundation::IUnknown, T>>>
    auto put_abi(T& object) noexcept
    {
        return reinterpret_cast<impl::abi_t<T>*>(&object);
    }

    template <typename T, typename V, typename = std::enable_if_t<!std::is_base_of_v<Windows::Foundation::IUnknown, T>>>
    void copy_from_abi(T& object, V&& value)
    {
        object = reinterpret_cast<T const&>(value);
    }

    template <typename T, typename V, typename = std::enable_if_t<!std::is_base_of_v<Windows::Foundation::IUnknown, T>>>
    void copy_to_abi(T const& object, V& value)
    {
        reinterpret_cast<T&>(value) = object;
    }

    template <typename T, typename = std::enable_if_t<!std::is_base_of_v<Windows::Foundation::IUnknown, std::decay_t<T>> &&
        !std::is_convertible_v<T, std::wstring_view>>>
        auto detach_abi(T&& object)
    {
        impl::abi_t<T> result{};
        reinterpret_cast<T&>(result) = std::move(object);
        return result;
    }
}

namespace winrt::impl
{
    template <> struct abi<Windows::Foundation::IUnknown>
    {
        struct __declspec(novtable) type
        {
            virtual HRESULT __stdcall QueryInterface(GUID const& id, void** object) noexcept = 0;
            virtual ULONG __stdcall AddRef() noexcept = 0;
            virtual ULONG __stdcall Release() noexcept = 0;
        };
    };

    using IUnknown = abi_t<Windows::Foundation::IUnknown>;

    template <> struct abi<Windows::Foundation::IInspectable>
    {
        struct __declspec(novtable) type : IUnknown
        {
            virtual HRESULT __stdcall GetIids(ULONG* count, GUID** ids) noexcept = 0;
            virtual HRESULT __stdcall GetRuntimeClassName(HSTRING* name) noexcept = 0;
            virtual HRESULT __stdcall GetTrustLevel(Windows::Foundation::TrustLevel* level) noexcept = 0;
        };
    };

    using IInspectable = abi_t<Windows::Foundation::IInspectable>;

    template <> struct abi<Windows::Foundation::IActivationFactory>
    {
        struct __declspec(novtable) type : IInspectable
        {
            virtual HRESULT __stdcall ActivateInstance(void** instance) noexcept = 0;
        };
    };

    template <> struct guid<Windows::Foundation::IUnknown>
    {
        static constexpr GUID value{ 0x00000000,0x0000,0x0000,{ 0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x46 } };
    };

    template <> struct category<Windows::Foundation::IUnknown>
    {
        using type = interface_category;
    };

    template <> struct guid<Windows::Foundation::IInspectable>
    {
        static constexpr GUID value{ 0xAF86E2E0,0xB12D,0x4C6A,{ 0x9C,0x5A,0xD7,0xAA,0x65,0x10,0x1E,0x90 } };
    };

    template <> struct name<Windows::Foundation::IInspectable>
    {
        static constexpr auto & value{ L"Object" };
        static constexpr auto & data{ "cinterface(IInspectable)" };
    };

    template <> struct category<Windows::Foundation::IInspectable>
    {
        using type = basic_category;
    };

    template <> struct guid<Windows::Foundation::IActivationFactory>
    {
        static constexpr GUID value{ 0x00000035,0x0000,0x0000,{ 0xc0,0x00,0x00,0x00,0x00,0x00,0x00,0x46 } };
    };

    template <> struct guid<::IAgileObject>
    {
        static constexpr GUID value{ 0x94EA2B94,0xE9CC,0x49E0,{ 0xC0,0xFF,0xEE,0x64,0xCA,0x8F,0x5B,0x90 } };
    };

    template <> struct name<Windows::Foundation::IActivationFactory>
    {
        static constexpr auto & value{ L"Windows.Foundation.IActivationFactory" };
    };

    template <> struct category<Windows::Foundation::IActivationFactory>
    {
        using type = interface_category;
    };

    template <> struct name<::IAgileObject>
    {
        static constexpr auto & value{ L"IAgileObject" };
    };

    template <> struct guid<::IMarshal>
    {
        static constexpr GUID value{ 0x00000003,0x0000,0x0000,{ 0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x46 } };
    };

    template <typename D>
    struct consume_IActivationFactory
    {
        Windows::Foundation::IInspectable ActivateInstance() const;
    };

    template <> struct consume<Windows::Foundation::IActivationFactory>
    {
        template <typename D> using type = consume_IActivationFactory<D>;
    };

    template <typename T>
    using com_ref = std::conditional_t<std::is_base_of_v<Windows::Foundation::IUnknown, T>, T, com_ptr<T>>;

    template <typename To, typename From>
    com_ref<To> as(From* ptr);

    template <typename To, typename From>
    com_ref<To> try_as(From* ptr) noexcept;

    template <typename T>
    struct wrapped_type
    {
        using type = T;
    };

    template <typename T>
    struct wrapped_type<com_ptr<T>>
    {
        using type = T;
    };

    template <typename T>
    using wrapped_type_t = typename wrapped_type<T>::type;
}

WINRT_EXPORT namespace winrt::Windows::Foundation
{
    struct IUnknown
    {
        IUnknown() noexcept = default;
        IUnknown(std::nullptr_t) noexcept {}
        void* operator new(size_t) = delete;

        IUnknown(IUnknown const& other) noexcept : m_ptr(other.m_ptr)
        {
            impl_addref();
        }

        IUnknown(IUnknown&& other) noexcept : m_ptr(other.m_ptr)
        {
            other.m_ptr = nullptr;
        }

        ~IUnknown() noexcept
        {
            impl_release();
        }

        IUnknown& operator=(IUnknown const& other) noexcept
        {
            impl_copy(other);
            return*this;
        }

        IUnknown& operator=(IUnknown&& other) noexcept
        {
            impl_move(std::forward<IUnknown>(other));
            return*this;
        }

        explicit operator bool() const noexcept
        {
            return nullptr != m_ptr;
        }

        IUnknown& operator=(std::nullptr_t) noexcept
        {
            impl_release();
            return*this;
        }

        template <typename To>
        auto as() const
        {
            return impl::as<To>(m_ptr);
        }

        template <typename To>
        auto try_as() const noexcept
        {
            return impl::try_as<To>(m_ptr);
        }

        template <typename To>
        void as(To& to) const
        {
            to = as<impl::wrapped_type_t<To>>();
        }

        template <typename To>
        bool try_as(To& to) const noexcept
        {
            to = try_as<impl::wrapped_type_t<To>>();
            return static_cast<bool>(to);
        }

        friend void* impl_detach(IUnknown& object) noexcept
        {
            auto temp = object.m_ptr;
            object.m_ptr = nullptr;
            return temp;
        }

        friend void swap(IUnknown& left, IUnknown& right) noexcept
        {
            std::swap(left.m_ptr, right.m_ptr);
        }

    protected:

        void impl_copy(IUnknown const& other) noexcept
        {
            if (this != &other)
            {
                impl_release();
                m_ptr = other.m_ptr;
                impl_addref();
            }
        }

        void impl_move(IUnknown&& other) noexcept
        {
            if (this != &other)
            {
                impl_release();
                m_ptr = other.m_ptr;
                other.m_ptr = nullptr;
            }
        }

        impl::IUnknown* m_ptr{ nullptr };

    private:

        void impl_addref() const noexcept
        {
            if (m_ptr)
            {
                m_ptr->AddRef();
            }
        }

        void impl_release() noexcept
        {
            if (m_ptr)
            {
                impl_decref();
            }
        }

        __declspec(noinline) void impl_decref() noexcept
        {
            WINRT_ASSERT(m_ptr != nullptr);
            auto temp = m_ptr;
            m_ptr = nullptr;
            temp->Release();
        }
    };
}

WINRT_EXPORT namespace winrt
{
    inline void* get_abi(Windows::Foundation::IUnknown const& object) noexcept
    {
        return *(void**)(&object);
    }

    inline void** put_abi(Windows::Foundation::IUnknown& object) noexcept
    {
        WINRT_ASSERT(get_abi(object) == nullptr);
        return reinterpret_cast<void**>(&object);
    }

    inline void attach_abi(Windows::Foundation::IUnknown& object, void* value) noexcept
    {
        object = nullptr;
        *put_abi(object) = value;
    }

    inline void* detach_abi(Windows::Foundation::IUnknown& object) noexcept
    {
        void* temp = get_abi(object);
        *reinterpret_cast<void**>(&object) = nullptr;
        return temp;
    }

    inline void* detach_abi(Windows::Foundation::IUnknown&& object) noexcept
    {
        void* temp = get_abi(object);
        *reinterpret_cast<void**>(&object) = nullptr;
        return temp;
    }

    inline void copy_from_abi(Windows::Foundation::IUnknown& object, void* value) noexcept
    {
        object = nullptr;

        if (value)
        {
            static_cast<IUnknown*>(value)->AddRef();
            *put_abi(object) = value;
        }
    }

    inline void copy_to_abi(Windows::Foundation::IUnknown const& object, void*& value) noexcept
    {
        WINRT_ASSERT(value == nullptr);
        value = get_abi(object);

        if (value)
        {
            static_cast<IUnknown*>(value)->AddRef();
        }
    }
}

WINRT_EXPORT namespace winrt::Windows::Foundation
{
    inline bool operator==(IUnknown const& left, IUnknown const& right) noexcept
    {
        if (get_abi(left) == get_abi(right))
        {
            return true;
        }
        if (!left || !right)
        {
            return false;
        }
        return get_abi(left.try_as<IUnknown>()) == get_abi(right.try_as<IUnknown>());
    }

    inline bool operator!=(IUnknown const& left, IUnknown const& right) noexcept
    {
        return !(left == right);
    }

    inline bool operator<(IUnknown const& left, IUnknown const& right) noexcept
    {
        if (get_abi(left) == get_abi(right))
        {
            return false;
        }
        if (!left || !right)
        {
            return get_abi(left) < get_abi(right);
        }
        return get_abi(left.try_as<IUnknown>()) < get_abi(right.try_as<IUnknown>());
    }

    inline bool operator>(IUnknown const& left, IUnknown const& right) noexcept
    {
        return right < left;
    }

    inline bool operator<=(IUnknown const& left, IUnknown const& right) noexcept
    {
        return !(right < left);
    }

    inline bool operator>=(IUnknown const& left, IUnknown const& right) noexcept
    {
        return !(left < right);
    }

    struct IInspectable : IUnknown
    {
        IInspectable(std::nullptr_t = nullptr) noexcept {}
    };

    inline TrustLevel GetTrustLevel(IInspectable const& object)
    {
        TrustLevel value{};
        check_hresult((*(impl::IInspectable**)&object)->GetTrustLevel(&value));
        return value;
    }

    inline ::IUnknown* get_unknown(Windows::Foundation::IUnknown const& object) noexcept
    {
        return static_cast<::IUnknown*>(get_abi(object));
    }
}

namespace winrt::impl
{
    template <typename T>
    T empty_value() noexcept
    {
        if constexpr (std::is_base_of_v<Windows::Foundation::IUnknown, T>)
        {
            return nullptr;
        }
        else
        {
            return {};
        }
    }

    template <typename T, typename Enable = void>
    struct arg
    {
        using in = abi_t<T>;
    };

    template <typename T>
    struct arg<T, std::enable_if_t<std::is_base_of_v<Windows::Foundation::IUnknown, T>>>
    {
        using in = void*;
    };

    template <typename T>
    using arg_in = typename arg<T>::in;

    template <typename T>
    using arg_out = arg_in<T>*;
}
