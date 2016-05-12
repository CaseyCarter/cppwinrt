
template <typename T>
struct array_ref
{
    using value_type = T;
    using size_type = std::uint32_t;
    using reference = value_type &;
    using const_reference = const value_type &;
    using pointer = value_type *;
    using const_pointer = const value_type *;
    using iterator = pointer;
    using const_iterator = const_pointer;
    using reverse_iterator = std::reverse_iterator<iterator>;
    using const_reverse_iterator = std::reverse_iterator<const_iterator>;

    array_ref() noexcept = default;

    array_ref(pointer begin, pointer end) noexcept :
        m_begin(begin),
        m_end(end)
    {}

    array_ref(std::initializer_list<value_type> value) noexcept :
        array_ref(value.begin(), value.begin() + value.size())
    {}

    template <typename C, size_type N>
    array_ref(C(&value)[N]) noexcept :
        array_ref(value, value + N)
    {}

    template <typename C>
    array_ref(std::vector<C> & value) noexcept :
        array_ref(value.data(), value.data() + value.size())
    {}

    template <typename C>
    array_ref(const std::vector<C> & value) noexcept :
        array_ref(value.data(), value.data() + value.size())
    {}

    template <typename C, size_type N>
    array_ref(std::array<C, N> & value) noexcept :
        array_ref(value.data(), value.data() + value.size())
    {}

    template <typename C, size_type N>
    array_ref(const std::array<C, N> & value) noexcept :
        array_ref(value.data(), value.data() + value.size())
    {}

    reference operator[](const size_type pos) noexcept
    {
        WINRT_ASSERT(pos < size());
        return m_begin[pos];
    }

    const_reference operator[](const size_type pos) const noexcept
    {
        WINRT_ASSERT(pos < size());
        return m_begin[pos];
    }

    reference at(const size_type pos)
    {
        if (size() <= pos)
        {
            throw std::out_of_range("Invalid array subscript");
        }

        return m_begin[pos];
    }

    const_reference at(const size_type pos) const
    {
        if (size() <= pos)
        {
            throw std::out_of_range("Invalid array subscript");
        }

        return m_begin[pos];
    }

    reference front() noexcept
    {
        WINRT_ASSERT(m_begin != m_end);
        return *m_begin;
    }

    const_reference front() const noexcept
    {
        WINRT_ASSERT(m_begin != m_end);
        return *m_begin;
    }

    reference back() noexcept
    {
        WINRT_ASSERT(m_begin != m_end);
        return *(m_end - 1);
    }

    const_reference back() const noexcept
    {
        WINRT_ASSERT(m_begin != m_end);
        return *(m_end - 1);
    }

    pointer data() noexcept
    {
        return m_begin;
    }

    const_pointer data() const noexcept
    {
        return m_begin;
    }

    iterator begin() noexcept
    {
        return m_begin;
    }

    const_iterator begin() const noexcept
    {
        return m_begin;
    }

    const_iterator cbegin() const noexcept
    {
        return m_begin;
    }

    iterator end() noexcept
    {
        return m_end;
    }

    const_iterator end() const noexcept
    {
        return m_end;
    }

    const_iterator cend() const noexcept
    {
        return m_end;
    }

    reverse_iterator rbegin() noexcept
    {
        return reverse_iterator(end());
    }

    const_reverse_iterator rbegin() const noexcept
    {
        return const_reverse_iterator(end());
    }

    const_reverse_iterator crbegin() const noexcept
    {
        return rbegin();
    }

    reverse_iterator rend() noexcept
    {
        return reverse_iterator(begin());
    }

    const_reverse_iterator rend() const noexcept
    {
        return const_reverse_iterator(begin());
    }

    const_reverse_iterator crend() const noexcept
    {
        return rend();
    }

    bool empty() const noexcept
    {
        return m_begin == m_end;
    }

    size_type size() const noexcept
    {
        return static_cast<size_type>(m_end - m_begin);
    }

protected:

    pointer m_begin = nullptr;
    pointer m_end = nullptr;
};

template <typename T>
struct com_array : array_ref<T>
{
    using value_type = T;
    using size_type = std::uint32_t;
    using reference = value_type &;
    using const_reference = const value_type &;
    using pointer = value_type *;
    using const_pointer = const value_type *;
    using iterator = pointer;
    using const_iterator = const_pointer;
    using reverse_iterator = std::reverse_iterator<iterator>;
    using const_reverse_iterator = std::reverse_iterator<const_iterator>;

    com_array(const com_array &) = delete;
    com_array & operator=(const com_array &) = delete;

    com_array() noexcept = default;

    explicit com_array(const size_type count) :
        com_array(count, value_type())
    {}

    com_array(const size_type count, const value_type & value)
    {
        alloc(count);
        std::uninitialized_fill_n(m_begin, count, value);
    }

    template <typename InIt> com_array(InIt first, InIt last)
    {
        alloc(static_cast<size_type>(std::distance(first, last)));
        std::uninitialized_copy(first, last, stdext::make_unchecked_array_iterator(m_begin));
    }

    explicit com_array(const std::vector<value_type> & value) :
        com_array(value.begin(), value.end())
    {}

    template <size_type N>
    explicit com_array(const std::array<value_type, N> & value) :
        com_array(value.begin(), value.end())
    {}

    template <size_type N>
    explicit com_array(const value_type (&value)[N]) :
        com_array(value, value + N)
    {}

    com_array(std::initializer_list<value_type> value) :
        com_array(value.begin(), value.end())
    {}

    com_array(com_array && other) noexcept :
        array_ref(other.m_begin, other.m_end)
    {
        other.m_begin = nullptr;
        other.m_end = nullptr;
    }

    com_array & operator=(com_array && other) noexcept
    {
        m_begin = other.m_begin;
        m_end = other.m_end;
        other.m_begin = nullptr;
        other.m_end = nullptr;
        return *this;
    }

    ~com_array() noexcept
    {
        clear();
    }

    void clear() noexcept
    {
        if (m_begin)
        {
            destruct(std::is_trivially_destructible<value_type>());
            CoTaskMemFree(m_begin);
            m_begin = nullptr;
        }
    }

    friend abi_arg_out<T> * impl_put(com_array & value) noexcept
    {
        WINRT_ASSERT(!value.m_begin);
        return reinterpret_cast<abi_arg_out<T> *>(&value.m_begin);
    }

    friend auto impl_data(com_array & value) noexcept
    {
        return value.m_begin;
    }

    friend void impl_put_size(com_array & value, const uint32_t size) noexcept
    {
        WINRT_ASSERT(value.m_begin || (!value.m_begin && size == 0));
        value.m_end = value.m_begin + size;
    }

    friend auto impl_detach(com_array & value) noexcept
    {
        std::pair<uint32_t, abi_arg_in<T> *> result(value.size(), *reinterpret_cast<abi_arg_in<T> **>(&value));
        value.m_begin = nullptr;
        value.m_end = nullptr;
        return result;
    }

    friend void swap(com_array & left, com_array & right) noexcept
    {
        std::swap(left.m_begin, right.m_begin);
        std::swap(left.m_end, right.m_end);
    }

private:

    void alloc(const size_type count)
    {
        WINRT_ASSERT(empty());

        if (0 != count)
        {
            m_begin = static_cast<value_type *>(CoTaskMemAlloc(count * sizeof(value_type)));

            if (nullptr == m_begin)
            {
                throw std::bad_alloc();
            }

            m_end = m_begin + count;
        }
    }

    void destruct(std::true_type) noexcept
    {}

    void destruct(std::false_type) noexcept
    {
        for (value_type & v : *this)
        {
            v.~value_type();
        }
    }
};

template <typename T>
bool operator==(const array_ref<T> & left, const array_ref<T> & right) noexcept
{
    return std::equal(left.begin(), left.end(), right.begin(), right.end());
}

template <typename T>
bool operator<(const array_ref<T> & left, const array_ref<T> & right) noexcept
{
    return std::lexicographical_compare(left.begin(), left.end(), right.begin(), right.end());
}

template <typename T> bool operator!=(const array_ref<T> & left, const array_ref<T> & right) noexcept { return !(left == right); }
template <typename T> bool operator>(const array_ref<T> & left, const array_ref<T> & right) noexcept { return right < left; }
template <typename T> bool operator<=(const array_ref<T> & left, const array_ref<T> & right) noexcept { return !(right < left); }
template <typename T> bool operator>=(const array_ref<T> & left, const array_ref<T> & right) noexcept { return !(left < right); }

namespace impl {

template <typename T>
struct array_size_proxy
{
    array_size_proxy & operator=(const array_size_proxy &) = delete;

    array_size_proxy(com_array<T> & value) noexcept :
        m_value(value)
    {}

    ~array_size_proxy() noexcept
    {
        impl_put_size(m_value, m_size);
    }

    operator uint32_t * () noexcept
    {
        return &m_size;
    }

    operator unsigned long * () noexcept
    {
        return reinterpret_cast<unsigned long *>(&m_size);
    }

private:

    com_array<T> & m_value;
    uint32_t m_size = 0;
};

template <typename T>
struct com_array_proxy
{
    com_array_proxy(uint32_t * size, abi_arg_out<T> * value) noexcept :
        m_size(size),
        m_value(value)
    {}

    ~com_array_proxy() noexcept
    {
        std::tie(*m_size, *m_value) = impl_detach(m_temp);
    }

    operator com_array<T> &() noexcept
    {
        return m_temp;
    }

    com_array_proxy(const com_array_proxy &) noexcept
    {
        WINRT_ASSERT(false);
    }

    com_array_proxy & operator=(const com_array_proxy &) noexcept
    {
        WINRT_ASSERT(false);
        return *this;
    }

private:

    uint32_t * m_size;
    abi_arg_out<T> * m_value;
    com_array<T> m_temp;
};

template <typename T>
struct accessors<com_array<T>>
{
    static auto put(com_array<T> & object) noexcept
    {
        return impl_put(object);
    }

    static array_size_proxy<T> put_size(com_array<T> & object) noexcept
    {
        return array_size_proxy<T>(object);
    }

    static auto detach(com_array<T> & object) noexcept
    {
        return impl_detach(object);
    }

    static auto data(com_array<T> & object) noexcept
    {
        return impl_data(object);
    }
};

template <typename T>
struct accessors<array_ref<T>>
{
    static auto get(array_ref<T> object) noexcept
    {
        return reinterpret_cast<abi_arg_out<std::remove_const_t<T>>>(const_cast<std::remove_const_t<T> *>(object.data()));
    }
};

}

template <typename T>
auto detach(uint32_t * __valueSize, abi_arg_out<T> * value) noexcept
{
    return impl::com_array_proxy<T>(__valueSize, value);
}
