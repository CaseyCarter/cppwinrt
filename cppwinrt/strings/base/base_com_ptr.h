
void check_hresult(HRESULT result);

template <typename T>
struct com_ptr;


namespace Windows::Foundation
{
    struct IUnknown;
}

namespace impl
{
    template <typename U>
    auto as(::IUnknown* ptr, std::enable_if_t<std::is_base_of_v<Windows::Foundation::IUnknown, U>>* = nullptr)
    {
        U temp{ nullptr };
        check_hresult(ptr->QueryInterface(guid_v<U>, reinterpret_cast<void**>(&temp)));
        return temp;
    }

    template <typename U>
    auto as(::IUnknown* ptr, std::enable_if_t<std::is_base_of_v<::IUnknown, U>>* = nullptr)
    {
        com_ptr<U> temp;
        check_hresult(ptr->QueryInterface(__uuidof(U), reinterpret_cast<void**>(&temp)));
        return temp;
    }

    template <typename U>
    auto try_as(::IUnknown* ptr, std::enable_if_t<std::is_base_of_v<Windows::Foundation::IUnknown, U>>* = nullptr) noexcept
    {
        U temp{ nullptr };
        ptr->QueryInterface(guid_v<U>, reinterpret_cast<void**>(&temp));
        return temp;
    }

    template <typename U>
    auto try_as(::IUnknown* ptr, std::enable_if_t<std::is_base_of_v<::IUnknown, U>>* = nullptr) noexcept
    {
        com_ptr<U> temp;
        ptr->QueryInterface(__uuidof(U), reinterpret_cast<void**>(&temp));
        return temp;
    }
}

template <typename T>
struct com_ptr
{
    using type = abi_t<T>;

    com_ptr(std::nullptr_t = nullptr) noexcept {}

    com_ptr(com_ptr const& other) noexcept :
    m_ptr(other.m_ptr)
    {
        addref();
    }

    template <typename U>
    com_ptr(com_ptr<U> const& other) noexcept :
    m_ptr(other.m_ptr)
    {
        addref();
    }

    template <typename U>
    com_ptr(com_ptr<U>&& other) noexcept :
    m_ptr(other.m_ptr)
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

    friend type** impl_put(com_ptr& object) noexcept
    {
        WINRT_ASSERT(object.m_ptr == nullptr);
        return&object.m_ptr;
    }

    friend type* impl_detach(com_ptr& object) noexcept
    {
        type* temp = object.m_ptr;
        object.m_ptr = nullptr;
        return temp;
    }

    friend void swap(com_ptr& left, com_ptr& right) noexcept
    {
        std::swap(left.m_ptr, right.m_ptr);
    }

    template <typename U>
    auto as() const
    {
        return impl::as<U>(m_ptr);
    }

    template <typename U>
    auto try_as() const noexcept
    {
        return impl::try_as<U>(m_ptr);
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
        type* temp = m_ptr;

        if (temp)
        {
            m_ptr = nullptr;
            temp->Release();
        }
    }

    template <typename U>
    friend struct com_ptr;

    type* m_ptr = nullptr;
};

namespace impl
{
    template <typename T>
    struct accessors<com_ptr<T>>
    {
        static auto get(com_ptr<T> const& object) noexcept
        {
            return object.get();
        }

        static auto put(com_ptr<T>& object) noexcept
        {
            return impl_put(object);
        }

        static void attach(com_ptr<T>& object, abi_t<T>* value) noexcept
        {
            object = nullptr;
            *put(object) = value;
        }

        static auto detach(com_ptr<T>& object) noexcept
        {
            return impl_detach(object);
        }
    };
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
