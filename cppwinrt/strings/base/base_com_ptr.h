
WINRT_EXPORT namespace winrt
{
    template <typename T>
    struct com_ptr
    {
        using type = impl::abi_t<T>;

        com_ptr(std::nullptr_t = nullptr) noexcept {}

        com_ptr(com_ptr const& other) noexcept : m_ptr(other.m_ptr)
        {
            addref();
        }

        template <typename U>
        com_ptr(com_ptr<U> const& other) noexcept : m_ptr(other.m_ptr)
        {
            addref();
        }

        template <typename U>
        com_ptr(com_ptr<U>&& other) noexcept : m_ptr(other.m_ptr)
        {
            other.m_ptr = nullptr;
        }

        ~com_ptr() noexcept
        {
            release();
        }

        com_ptr& operator=(com_ptr const& other) noexcept
        {
            copy(other.m_ptr);
            return*this;
        }

        template <typename U>
        com_ptr& operator=(com_ptr<U> const& other) noexcept
        {
            copy(other.m_ptr);
            return*this;
        }

        template <typename U>
        com_ptr& operator=(com_ptr<U>&& other) noexcept
        {
            if (m_ptr != other.m_ptr)
            {
                release();
                m_ptr = other.m_ptr;
                other.m_ptr = nullptr;
            }

            return*this;
        }

        explicit operator bool() const noexcept
        {
            return m_ptr != nullptr;
        }

        auto operator->() const noexcept
        {
            return static_cast<impl::no_ref<type>*>(m_ptr);
        }

        T& operator*() const noexcept
        {
            return*m_ptr;
        }

        type* get() const noexcept
        {
            return m_ptr;
        }

        type** put() noexcept
        {
            WINRT_ASSERT(m_ptr == nullptr);
            return &m_ptr;
        }

        void** put_void() noexcept
        {
            return reinterpret_cast<void**>(put());
        }

        void attach(type* value) noexcept
        {
            release();
            *put() = value;
        }

        type* detach() noexcept
        {
            type* temp = m_ptr;
            m_ptr = nullptr;
            return temp;
        }

        friend void swap(com_ptr& left, com_ptr& right) noexcept
        {
            std::swap(left.m_ptr, right.m_ptr);
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

        void copy_from(type* other) noexcept
        {
            copy(other);
        }

        void copy_to(type** other) const noexcept
        {
            addref();
            *other = m_ptr;
        }

    private:

        void copy(type* other) noexcept
        {
            if (m_ptr != other)
            {
                release();
                m_ptr = other;
                addref();
            }
        }

        void addref() const noexcept
        {
            if (m_ptr)
            {
                m_ptr->AddRef();
            }
        }

        void release() noexcept
        {
            if (m_ptr)
            {
                impl_decref();
            }
        }

        __declspec(noinline) void impl_decref() noexcept
        {
            WINRT_ASSERT(m_ptr != nullptr);
            type* temp = m_ptr;
            m_ptr = nullptr;
            temp->Release();
        }

        template <typename U>
        friend struct com_ptr;

        type* m_ptr{ nullptr };
    };

    template <typename T>
    auto get_abi(com_ptr<T> const& object) noexcept
    {
        return object.get();
    }

    template <typename T>
    auto put_abi(com_ptr<T>& object) noexcept
    {
        return object.put_void();
    }

    template <typename T>
    void attach_abi(com_ptr<T>& object, impl::abi_t<T>* value) noexcept
    {
        object.attach(value);
    }

    template <typename T>
    auto detach_abi(com_ptr<T>& object) noexcept
    {
        return object.detach();
    }

    template <typename T>
    bool operator==(com_ptr<T> const& left, com_ptr<T> const& right) noexcept
    {
        return get_abi(left) == get_abi(right);
    }

    template <typename T>
    bool operator==(com_ptr<T> const& left, std::nullptr_t) noexcept
    {
        return get_abi(left) == nullptr;
    }

    template <typename T>
    bool operator==(std::nullptr_t, com_ptr<T> const& right) noexcept
    {
        return nullptr == get_abi(right);
    }

    template <typename T>
    bool operator!=(com_ptr<T> const& left, com_ptr<T> const& right) noexcept
    {
        return !(left == right);
    }

    template <typename T>
    bool operator!=(com_ptr<T> const& left, std::nullptr_t) noexcept
    {
        return !(left == nullptr);
    }

    template <typename T>
    bool operator!=(std::nullptr_t, com_ptr<T> const& right) noexcept
    {
        return !(nullptr == right);
    }

    template <typename T>
    bool operator<(com_ptr<T> const& left, com_ptr<T> const& right) noexcept
    {
        return get_abi(left) < get_abi(right);
    }

    template <typename T>
    bool operator>(com_ptr<T> const& left, com_ptr<T> const& right) noexcept
    {
        return right < left;
    }

    template <typename T>
    bool operator<=(com_ptr<T> const& left, com_ptr<T> const& right) noexcept
    {
        return !(right < left);
    }

    template <typename T>
    bool operator>=(com_ptr<T> const& left, com_ptr<T> const& right) noexcept
    {
        return !(left < right);
    }
}

namespace winrt::impl
{
    template <typename To, typename From>
    com_ref<To> as(From* ptr)
    {
#ifdef WINRT_DIAGNOSTICS
        get_diagnostics_info().add_query<To>();
#endif

        com_ref<To> temp{ nullptr };
        check_hresult(ptr->QueryInterface(guid_of<To>(), put_abi(temp)));
        return temp;
    }

    template <typename To, typename From>
    com_ref<To> try_as(From* ptr) noexcept
    {
#ifdef WINRT_DIAGNOSTICS
        get_diagnostics_info().add_query<To>();
#endif

        com_ref<To> temp{ nullptr };
        ptr->QueryInterface(guid_of<To>(), put_abi(temp));
        return temp;
    }
}