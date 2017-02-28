
namespace Windows::Foundation
{
    enum class TrustLevel
    {
        BaseTrust,
        PartialTrust,
        FullTrust,
    };
}

namespace ABI::Windows::Foundation
{
    struct __declspec(uuid("af86e2e0-b12d-4c6a-9c5a-d7aa65101e90")) __declspec(novtable) IInspectable : IUnknown
    {
        virtual HRESULT __stdcall abi_GetIids(uint32_t * iidCount, GUID ** iids) = 0;
        virtual HRESULT __stdcall abi_GetRuntimeClassName(HSTRING * className) = 0;
        virtual HRESULT __stdcall abi_GetTrustLevel(winrt::Windows::Foundation::TrustLevel * trustLevel) = 0;
    };

    struct __declspec(uuid("00000035-0000-0000-c000-000000000046")) __declspec(novtable) IActivationFactory : IInspectable
    {
        virtual HRESULT __stdcall abi_ActivateInstance(IInspectable ** instance) = 0;
    };
}

namespace Windows::Foundation
{
    struct IUnknown
    {
        IUnknown() noexcept = default;
        IUnknown(std::nullptr_t) noexcept {}
        void * operator new(size_t) = delete;

        IUnknown(const IUnknown & other) noexcept :
        m_ptr(other.m_ptr)
        {
            impl_addref();
        }

        IUnknown(IUnknown && other) noexcept :
        m_ptr(other.m_ptr)
        {
            other.m_ptr = nullptr;
        }

        ~IUnknown() noexcept
        {
            impl_release();
        }

        IUnknown & operator=(const IUnknown & other) noexcept
        {
            impl_copy(other);
            return *this;
        }

        IUnknown & operator=(IUnknown && other) noexcept
        {
            impl_move(std::forward<IUnknown>(other));
            return *this;
        }

        explicit operator bool() const noexcept
        {
            return nullptr != m_ptr;
        }

        IUnknown & operator=(std::nullptr_t) noexcept
        {
            impl_release();
            return *this;
        }

        template <typename U>
        auto as() const
        {
            std::conditional_t<impl::is_base_of_v<IUnknown, U>, U, com_ptr<U>> temp = nullptr;
            check_hresult(m_ptr->QueryInterface(__uuidof(impl::abi_default_interface<U>), reinterpret_cast<void **>(put_abi(temp))));
            return temp;
        }

        template <typename U>
        auto try_as() const
        {
            std::conditional_t<impl::is_base_of_v<IUnknown, U>, U, com_ptr<U>> temp = nullptr;
            m_ptr->QueryInterface(__uuidof(impl::abi_default_interface<U>), reinterpret_cast<void **>(put_abi(temp)));
            return temp;
        }

        friend auto impl_get(const IUnknown & object) noexcept
        {
            return object.m_ptr;
        }

        friend auto impl_put(IUnknown & object) noexcept
        {
            WINRT_ASSERT(!object);
            return &object.m_ptr;
        }

        friend auto impl_detach(IUnknown & object) noexcept
        {
            auto temp = object.m_ptr;
            object.m_ptr = nullptr;
            return temp;
        }

        friend void swap(IUnknown & left, IUnknown & right) noexcept
        {
            std::swap(left.m_ptr, right.m_ptr);
        }

    protected:

        void impl_copy(::IUnknown * other) noexcept
        {
            if (m_ptr != other)
            {
                impl_release();
                m_ptr = other;
                impl_addref();
            }
        }

        void impl_copy(const IUnknown & other) noexcept
        {
            if (this != &other)
            {
                impl_release();
                m_ptr = other.m_ptr;
                impl_addref();
            }
        }

        void impl_move(IUnknown && other) noexcept
        {
            if (this != &other)
            {
                impl_release();
                m_ptr = other.m_ptr;
                other.m_ptr = nullptr;
            }
        }

        ::IUnknown * m_ptr = nullptr;

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
    template <> struct traits<Windows::Foundation::IUnknown>
    {
        using abi = ::IUnknown;
    };

    template <typename T>
    struct accessors<T, std::enable_if_t<std::is_base_of<Windows::Foundation::IUnknown, T>::value>>
    {
        static auto get(const T & object) noexcept
        {
            return static_cast<abi_arg_in<T>>(impl_get(object));
        }

        static auto put(T & object) noexcept
        {
            return reinterpret_cast<abi_arg_out<T>>(impl_put(object));
        }

        static void attach(T & object, abi_arg_in<T> value) noexcept
        {
            object = nullptr;
            *put(object) = value;
        }

        static void copy_from(T & object, abi_arg_in<T> value) noexcept
        {
            object = nullptr;

            if (value)
            {
                value->AddRef();
                *put(object) = value;
            }
        }

        template <typename V>
        static void copy_to(const T & object, V & value) noexcept
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

        static auto detach(T & object) noexcept
        {
            return static_cast<abi_arg_in<T>>(impl_detach(object));
        }
    };
}

namespace Windows::Foundation
{
    inline bool operator==(const IUnknown & left, const IUnknown & right) noexcept
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

    inline bool operator!=(const IUnknown & left, const IUnknown & right) noexcept
    {
        return !(left == right);
    }

    inline bool operator<(const IUnknown & left, const IUnknown & right) noexcept
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

    inline bool operator>(const IUnknown & left, const IUnknown & right) noexcept
    {
        return right < left;
    }

    inline bool operator<=(const IUnknown & left, const IUnknown & right) noexcept
    {
        return !(right < left);
    }

    inline bool operator>=(const IUnknown & left, const IUnknown & right) noexcept
    {
        return !(left < right);
    }
}

namespace Windows::Foundation
{
    struct IInspectable;
}

namespace impl
{
    template <> struct traits<Windows::Foundation::IInspectable>
    {
        using abi = ABI::Windows::Foundation::IInspectable;
    };
}

namespace Windows::Foundation
{
    struct IInspectable : IUnknown
    {
        IInspectable(std::nullptr_t = nullptr) noexcept {}
    };

    inline com_array<GUID> GetIids(const IInspectable & object)
    {
        com_array<GUID> value;
        check_hresult((*(abi<IInspectable> **)&object)->abi_GetIids(impl::put_size_abi(value), put_abi(value)));
        return value;
    }

    inline hstring GetRuntimeClassName(const IInspectable & object)
    {
        hstring value;
        check_hresult((*(abi<IInspectable> **)&object)->abi_GetRuntimeClassName(put_abi(value)));
        return value;
    }

    inline TrustLevel GetTrustLevel(const IInspectable & object)
    {
        TrustLevel value{};
        check_hresult((*(abi<IInspectable> **)&object)->abi_GetTrustLevel(&value));
        return value;
    }
}

namespace impl
{
    template <typename T, std::enable_if_t<!std::is_base_of<Windows::Foundation::IUnknown, T>::value> * = nullptr>
    T empty_value()
    {
        return {};
    }

    template <typename T, std::enable_if_t<std::is_base_of<Windows::Foundation::IUnknown, T>::value> * = nullptr>
    T empty_value()
    {
        return nullptr;
    }
}
