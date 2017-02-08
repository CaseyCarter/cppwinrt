namespace impl {

template <typename T>
struct handle_traits
{
    using type = T;

    constexpr static type invalid() noexcept
    {
        return nullptr;
    }

    // static void close(type value) noexcept;
};

template <typename T>
struct handle
{
    using type = typename T::type;

    handle() noexcept = default;

    handle(type value) noexcept :
        m_value(value)
    {}

    handle(handle && other) noexcept :
        m_value(detach_abi(other))
    {}

    handle & operator=(handle && other) noexcept
    {
        if (this != &other)
        {
            attach_abi(*this, detach_abi(other));
        }

        return *this;
    }

    ~handle() noexcept
    {
        close();
    }

    void close() noexcept
    {
        if (*this)
        {
            T::close(m_value);
            m_value = T::invalid();
        }
    }

    explicit operator bool() const noexcept
    {
        return T::invalid() != m_value;
    }

    friend type impl_get(const handle & handle) noexcept
    {
        return handle.m_value;
    }

    friend type * impl_put(handle & handle) noexcept
    {
        WINRT_ASSERT(!handle);
        return &handle.m_value;
    }

    friend type impl_detach(handle & handle) noexcept
    {
        type value = handle.m_value;
        handle.m_value = T::invalid();
        return value;
    }

    friend void swap(handle & left, handle & right) noexcept
    {
        std::swap(left.m_value, right.m_value);
    }

private:

    type m_value = T::invalid();
};

template <typename T>
bool operator==(const handle<T> & left, const handle<T> & right) noexcept
{
    return get_abi(left) == get_abi(right);
}

template <typename T>
bool operator!=(const handle<T> & left, const handle<T> & right) noexcept
{
    return !(left == right);
}

template <typename T>
bool operator<(const handle<T> & left, const handle<T> & right) noexcept
{
    return get_abi(left) < get_abi(right);
}

template <typename T>
bool operator>(const handle<T> & left, const handle<T> & right) noexcept
{
    return right < left;
}

template <typename T>
bool operator<=(const handle<T> & left, const handle<T> & right) noexcept
{
    return !(right < left);
}

template <typename T>
bool operator>=(const handle<T> & left, const handle<T> & right) noexcept
{
    return !(left < right);
}

template <typename T>
struct accessors<handle<T>>
{
    using type = typename handle<T>::type;

    static type get(const handle<T> & object) noexcept
    {
        return impl_get(object);
    }

    static type * put(handle<T> & object) noexcept
    {
        return impl_put(object);
    }

    static void attach(handle<T> & object, type value) noexcept
    {
        object.close();
        *put(object) = value;
    }

    static type detach(handle<T> & object) noexcept
    {
        return impl_detach(object);
    }
};

}
