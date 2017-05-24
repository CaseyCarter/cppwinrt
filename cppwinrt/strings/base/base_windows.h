
namespace Windows::Foundation
{
    struct IInspectable;
    struct IActivationFactory;
}

namespace impl
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
            virtual HRESULT __stdcall ActivateInstance(::IUnknown** instance) = 0;
        };
    };

    template <> struct guid<Windows::Foundation::IUnknown>
    {
        static constexpr GUID value{ 0x00000000,0x0000,0x0000,{ 0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x46 } };
    };

    template <> struct name<Windows::Foundation::IUnknown>
    {
        static constexpr auto & value{ L"Windows.Foundation.IUnknown" };
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
        static constexpr auto & value{ L"Windows.Foundation.IInspectable" };
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

namespace Windows::Foundation
{
    struct IUnknown
    {
        IUnknown() noexcept = default;
        IUnknown(std::nullptr_t) noexcept {}
        void* operator new(size_t) = delete;

        IUnknown(IUnknown const& other) noexcept :
        m_ptr(other.m_ptr)
        {
            impl_addref();
        }

        IUnknown(IUnknown&& other) noexcept :
        m_ptr(other.m_ptr)
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
        void as(To& to)
        {
            to = as<impl::wrapped_type_t<To>>();
        }

        template <typename To>
        bool try_as(To& to)
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

        void impl_copy(::IUnknown* other) noexcept
        {
            if (m_ptr != other)
            {
                impl_release();
                m_ptr = other;
                impl_addref();
            }
        }

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

        ::IUnknown* m_ptr = nullptr;

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
            auto temp = m_ptr;

            if (temp)
            {
                m_ptr = nullptr;
                temp->Release();
            }
        }
    };
}

namespace impl
{
    template <typename T>
    struct accessors<T, std::enable_if_t<std::is_base_of_v<Windows::Foundation::IUnknown, T>>>
    {
        static ::IUnknown* get(T const& object) noexcept
        {
            return *(::IUnknown**)(&object);
        }

        static ::IUnknown** put(T& object) noexcept
        {
            return reinterpret_cast<::IUnknown**>(&object);
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

namespace Windows::Foundation
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
        return get_abi(left.as<IUnknown>()) == get_abi(right.as<IUnknown>());
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
        return get_abi(left.as<IUnknown>()) < get_abi(right.as<IUnknown>());
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

namespace impl
{
    template <typename T, std::enable_if_t<!std::is_base_of_v<Windows::Foundation::IUnknown, T>>* = nullptr>
    T empty_value()
    {
        return {};
    }

    template <typename T, std::enable_if_t<std::is_base_of_v<Windows::Foundation::IUnknown, T>>* = nullptr>
    T empty_value()
    {
        return nullptr;
    }

    template <typename T, typename Enable = void>
    struct arg
    {
        using in = abi_t<T>;
    };

    template <typename T>
    struct arg<T, std::enable_if_t<std::is_base_of_v<Windows::Foundation::IUnknown, T>>>
    {
        using in = ::IUnknown*;
    };

    template <typename T>
    using arg_in = typename arg<T>::in;

    template <typename T>
    using arg_out = arg_in<T>*;
}
