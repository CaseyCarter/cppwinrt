
WINRT_EXPORT namespace winrt::Windows::Foundation
{
    struct IInspectable;
    struct IActivationFactory;
}

namespace winrt::impl
{
    template <> struct abi<Windows::Foundation::IUnknown>
    {
        using type = ::IUnknown;
    };

    template <> struct abi<Windows::Foundation::IInspectable>
    {
        using type = ::IInspectable;
    };

    template <> struct abi<Windows::Foundation::IActivationFactory>
    {
        struct __declspec(uuid("00000035-0000-0000-C000-000000000046")) __declspec(novtable) type : ::IInspectable
        {
            virtual HRESULT __stdcall ActivateInstance(void** instance) = 0;
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

        friend ::IUnknown* impl_detach(IUnknown& object) noexcept
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

        ::IUnknown* m_ptr{ nullptr };

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

namespace winrt::impl
{
    template <typename T>
    struct accessors<T, std::enable_if_t<std::is_base_of_v<Windows::Foundation::IUnknown, T>>>
    {
        static ::IUnknown* get(T const& object) noexcept
        {
            return *(::IUnknown**)(&object);
        }

        static void** put(T& object) noexcept
        {
            return reinterpret_cast<void**>(&object);
        }

        static void attach(T& object, ::IUnknown* value) noexcept
        {
            object = nullptr;
            *put(object) = value;
        }

        static void copy_from(T& object, ::IUnknown* value) noexcept
        {
            object = nullptr;

            if (value)
            {
                value->AddRef();
                *put(object) = value;
            }
        }

        template <typename V>
        static void copy_to(T const& object, V& value) noexcept
        {
            if (object)
            {
                value = get(object);
                value->AddRef();
            }
            else
            {
                value = nullptr;
            }
        }

        static ::IUnknown* detach(T& object) noexcept
        {
            return impl_detach(object);
        }
    };
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

    inline hstring GetRuntimeClassName(IInspectable const& object)
    {
        hstring value;
        check_hresult((*(::IInspectable**)&object)->GetRuntimeClassName(put_abi(value)));
        return value;
    }

    inline TrustLevel GetTrustLevel(IInspectable const& object)
    {
        TrustLevel value{};
        check_hresult((*(::IInspectable**)&object)->GetTrustLevel(&value));
        return value;
    }
}

namespace winrt::impl
{
    template <typename T, std::enable_if_t<!std::is_base_of_v<Windows::Foundation::IUnknown, T>>* = nullptr>
    T empty_value() noexcept
    {
        return {};
    }

    template <typename T, std::enable_if_t<std::is_base_of_v<Windows::Foundation::IUnknown, T>>* = nullptr>
    T empty_value() noexcept
    {
        return nullptr;
    }

    template <typename T, typename Enable = void>
    struct arg
    {
        using in = abi_t<T>;
        using out = in*;
    };

    template <typename T>
    struct arg<T, std::enable_if_t<std::is_base_of_v<Windows::Foundation::IUnknown, T>>>
    {
        using in = ::IUnknown*;
        using out = void**;
    };

    template <typename T>
    using arg_in = typename arg<T>::in;

    template <typename T>
    using arg_out = typename arg<T>::out;
}
