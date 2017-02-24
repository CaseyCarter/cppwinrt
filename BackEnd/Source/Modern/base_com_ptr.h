
template<HRESULT ... ValuesToIgnore>
__forceinline void check_hresult(HRESULT result);

namespace Windows::Foundation
{
    struct IUnknown;
}

template <typename T>
struct com_ptr
{
    using type = abi<T>;

    com_ptr(std::nullptr_t = nullptr) noexcept {}

    com_ptr(const com_ptr & other) noexcept :
        m_ptr(other.m_ptr)
    {
        addref();
    }

    template <typename U>
    com_ptr(const com_ptr<U> & other) noexcept :
        m_ptr(other.m_ptr)
    {
        addref();
    }

    template <typename U>
    com_ptr(com_ptr<U> && other) noexcept :
        m_ptr(other.m_ptr)
    {
        other.m_ptr = nullptr;
    }

    ~com_ptr() noexcept
    {
        release();
    }

    com_ptr & operator=(const com_ptr & other) noexcept
    {
        copy(other.m_ptr);
        return *this;
    }

    template <typename U>
    com_ptr & operator=(const com_ptr<U> & other) noexcept
    {
        copy(other.m_ptr);
        return *this;
    }

    template <typename U>
    com_ptr & operator=(com_ptr<U> && other) noexcept
    {
        if (m_ptr != other.m_ptr)
        {
            release();
            m_ptr = other.m_ptr;
            other.m_ptr = nullptr;
        }

        return *this;
    }

    explicit operator bool() const noexcept
    {
        return m_ptr != nullptr;
    }

    auto operator->() const noexcept
    {
        return static_cast<impl::no_ref<type> *>(m_ptr);
    }

    T & operator *() const noexcept
    {
        return *m_ptr;
    }

    friend type * impl_get(const com_ptr & object) noexcept
    {
        return object.m_ptr;
    }

    friend type ** impl_put(com_ptr & object) noexcept
    {
        WINRT_ASSERT(object.m_ptr == nullptr);
        return &object.m_ptr;
    }

    friend type * impl_detach(com_ptr & object) noexcept
    {
        type * temp = object.m_ptr;
        object.m_ptr = nullptr;
        return temp;
    }

    friend void swap(com_ptr & left, com_ptr & right) noexcept
    {
        std::swap(left.m_ptr, right.m_ptr);
    }

    template <typename U>
    auto as() const
    {
        std::conditional_t<impl::is_base_of_v<Windows::Foundation::IUnknown, U>, U, com_ptr<U>> temp = nullptr;
        check_hresult(m_ptr->QueryInterface(__uuidof(impl::abi_default_interface<U>), reinterpret_cast<void **>(put_abi(temp))));
        return temp;
    }

    template <typename U>
    auto try_as() const
    {
        std::conditional_t<impl::is_base_of_v<Windows::Foundation::IUnknown, U>, U, com_ptr<U>> temp = nullptr;
        m_ptr->QueryInterface(__uuidof(impl::abi_default_interface<U>), reinterpret_cast<void **>(put_abi(temp)));
        return temp;
    }
    
    void copy_from(type * other) noexcept
    {
        copy(other);
    }

    void copy_to(type ** other) const noexcept
    {
        addref();
        *other = m_ptr;
    }
    
private:

    void copy(type * other) noexcept
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
        type * temp = m_ptr;

        if (temp)
        {
            m_ptr = nullptr;
            temp->Release();
        }
    }

    template <typename U>
    friend struct com_ptr;

    type * m_ptr = nullptr;
};

namespace impl {

template <typename T>
struct accessors<com_ptr<T>>
{
    static auto get(const com_ptr<T> & object) noexcept
    {
        return impl_get(object);
    }

    static auto put(com_ptr<T> & object) noexcept
    {
        return impl_put(object);
    }

    static void attach(com_ptr<T> & object, abi<T> * value) noexcept
    {
        object = nullptr;
        *put(object) = value;
    }

    static auto detach(com_ptr<T> & object) noexcept
    {
        return impl_detach(object);
    }
};

}

template <typename T>
bool operator==(const com_ptr<T> & left, const com_ptr<T> & right) noexcept
{
    return get_abi(left) == get_abi(right);
}

template <typename T>
bool operator==(const com_ptr<T> & left, std::nullptr_t) noexcept
{
    return get_abi(left) == nullptr;
}

template <typename T>
bool operator==(std::nullptr_t, const com_ptr<T> & right) noexcept
{
    return nullptr == get_abi(right);
}

template <typename T>
bool operator!=(const com_ptr<T> & left, const com_ptr<T> & right) noexcept
{
    return !(left == right);
}

template <typename T>
bool operator!=(const com_ptr<T> & left, std::nullptr_t) noexcept
{
    return !(left == nullptr);
}

template <typename T>
bool operator!=(std::nullptr_t, const com_ptr<T> & right) noexcept
{
    return !(nullptr == right);
}

template <typename T>
bool operator<(const com_ptr<T> & left, const com_ptr<T> & right) noexcept
{
    return get_abi(left) < get_abi(right);
}

template <typename T>
bool operator>(const com_ptr<T> & left, const com_ptr<T> & right) noexcept
{
    return right < left;
}

template <typename T>
bool operator<=(const com_ptr<T> & left, const com_ptr<T> & right) noexcept
{
    return !(right < left);
}

template <typename T>
bool operator>=(const com_ptr<T> & left, const com_ptr<T> & right) noexcept
{
    return !(left < right);
}
