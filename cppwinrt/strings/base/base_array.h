
namespace impl
{
#ifdef WINRT_CHECKED_ITERATORS

    template <typename T>
    using array_iterator = stdext::checked_array_iterator<T*>;

    template <typename T>
    auto make_array_iterator(T* data, uint32_t size, uint32_t index = 0) noexcept
    {
        return array_iterator<T>(data, size, index);
    }

#else

    template <typename T>
    using array_iterator = T*;

    template <typename T>
    auto make_array_iterator(T* data, uint32_t, uint32_t index = 0) noexcept
    {
        return data + index;
    }

#endif
}

template <typename T>
struct array_view
{
    using value_type = T;
    using size_type = uint32_t;
    using reference = value_type&;
    using const_reference = value_type const&;
    using pointer = value_type*;
    using const_pointer = value_type const*;
    using iterator = impl::array_iterator<value_type>;
    using const_iterator = impl::array_iterator<value_type const>;
    using reverse_iterator = std::reverse_iterator<iterator>;
    using const_reverse_iterator = std::reverse_iterator<const_iterator>;

    array_view() noexcept = default;

    array_view(pointer first, pointer last) noexcept :
    m_data(first),
        m_size(static_cast<size_type>(last - first))
    {}

    array_view(std::initializer_list<value_type> value) noexcept :
        array_view(value.begin(), static_cast<size_type>(value.size()))
    {}

    template <typename C, size_type N>
    array_view(C(&value)[N]) noexcept :
        array_view(value, N)
    {}

    template <typename C>
    array_view(std::vector<C>& value) noexcept :
        array_view(value.data(), static_cast<size_type>(value.size()))
    {}

    template <typename C>
    array_view(std::vector<C> const& value) noexcept :
        array_view(value.data(), static_cast<size_type>(value.size()))
    {}

    template <typename C, size_type N>
    array_view(std::array<C, N>& value) noexcept :
        array_view(value.data(), static_cast<size_type>(value.size()))
    {}

    template <typename C, size_type N>
    array_view(std::array<C, N> const& value) noexcept :
        array_view(value.data(), static_cast<size_type>(value.size()))
    {}

    reference operator[](size_type const pos) noexcept
    {
        WINRT_ASSERT(pos < size());
        return m_data[pos];
    }

    const_reference operator[](size_type const pos) const noexcept
    {
        WINRT_ASSERT(pos < size());
        return m_data[pos];
    }

    reference at(size_type const pos)
    {
        if (size() <= pos)
        {
            throw std::out_of_range("Invalid array subscript");
        }

        return m_data[pos];
    }

    const_reference at(size_type const pos) const
    {
        if (size() <= pos)
        {
            throw std::out_of_range("Invalid array subscript");
        }

        return m_data[pos];
    }

    reference front() noexcept
    {
        WINRT_ASSERT(m_size > 0);
        return*m_data;
    }

    const_reference front() const noexcept
    {
        WINRT_ASSERT(m_size > 0);
        return*m_data;
    }

    reference back() noexcept
    {
        WINRT_ASSERT(m_size > 0);
        return m_data[m_size - 1];
    }

    const_reference back() const noexcept
    {
        WINRT_ASSERT(m_size > 0);
        return m_data[m_size - 1];
    }

    pointer data() noexcept
    {
        return m_data;
    }

    const_pointer data() const noexcept
    {
        return m_data;
    }

    iterator begin() noexcept
    {
        return impl::make_array_iterator(m_data, m_size);
    }

    const_iterator begin() const noexcept
    {
        return impl::make_array_iterator<value_type const>(m_data, m_size);
    }

    const_iterator cbegin() const noexcept
    {
        return impl::make_array_iterator<value_type const>(m_data, m_size);
    }

    iterator end() noexcept
    {
        return impl::make_array_iterator(m_data, m_size, m_size);
    }

    const_iterator end() const noexcept
    {
        return impl::make_array_iterator<value_type const>(m_data, m_size, m_size);
    }

    const_iterator cend() const noexcept
    {
        return impl::make_array_iterator<value_type const>(m_data, m_size, m_size);
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
        return m_size == 0;
    }

    size_type size() const noexcept
    {
        return m_size;
    }

protected:

    array_view(pointer data, uint32_t size) :
        m_data(data),
        m_size(size)
    {}

    pointer m_data = nullptr;
    uint32_t m_size = 0;
};

template <typename T>
struct com_array : array_view<T>
{
    using typename array_view<T>::value_type;
    using typename array_view<T>::size_type;
    using typename array_view<T>::reference;
    using typename array_view<T>::const_reference;
    using typename array_view<T>::pointer;
    using typename array_view<T>::const_pointer;
    using typename array_view<T>::iterator;
    using typename array_view<T>::const_iterator;
    using typename array_view<T>::reverse_iterator;
    using typename array_view<T>::const_reverse_iterator;

    com_array(com_array const&) = delete;
    com_array& operator=(com_array const&) = delete;

    com_array() noexcept = default;

    explicit com_array(size_type const count) :
        com_array(count, value_type())
    {}

    com_array(size_type const count, value_type const& value)
    {
        alloc(count);
        std::uninitialized_fill_n(this->m_data, count, value);
    }

    template <typename InIt> com_array(InIt first, InIt last)
    {
        alloc(static_cast<size_type>(std::distance(first, last)));
        std::uninitialized_copy(first, last, this->begin());
    }

    explicit com_array(std::vector<value_type> const& value) :
        com_array(value.begin(), value.end())
    {}

    template <size_type N>
    explicit com_array(std::array<value_type, N> const& value) :
        com_array(value.begin(), value.end())
    {}

    template <size_type N>
    explicit com_array(value_type const(&value)[N]) :
        com_array(value, value + N)
    {}

    com_array(std::initializer_list<value_type> value) :
        com_array(value.begin(), value.end())
    {}

    com_array(com_array&& other) noexcept :
        array_view<T>(other.m_data, other.m_size)
    {
        other.m_data = nullptr;
        other.m_size = 0;
    }

    com_array& operator=(com_array&& other) noexcept
    {
        this->m_data = other.m_data;
        this->m_size = other.m_size;
        other.m_data = nullptr;
        other.m_size = 0;
        return*this;
    }

    ~com_array() noexcept
    {
        clear();
    }

    void clear() noexcept
    {
        if (this->m_data)
        {
            destruct(std::is_trivially_destructible<value_type>());
            CoTaskMemFree(this->m_data);
            this->m_data = nullptr;
            this->m_size = 0;
        }
    }

    friend auto impl_put(com_array& value) noexcept
    {
        WINRT_ASSERT(!value.m_data);
        return reinterpret_cast<impl::arg_out<T>*>(&value.m_data);
    }

    friend auto impl_data(com_array& value) noexcept
    {
        return value.m_data;
    }

    friend void impl_put_size(com_array& value, uint32_t const size) noexcept
    {
        WINRT_ASSERT(value.m_data || (!value.m_data&& size == 0));
        value.m_size = size;
    }

    friend auto impl_detach(com_array& value) noexcept
    {
        std::pair<uint32_t, impl::arg_in<T>*> result(value.size(), *reinterpret_cast<impl::arg_in<T>**>(&value));
        value.m_data = nullptr;
        value.m_size = 0;
        return result;
    }

    friend void swap(com_array& left, com_array& right) noexcept
    {
        std::swap(left.m_data, right.m_data);
        std::swap(left.m_size, right.m_size);
    }

private:

    void alloc(size_type const size)
    {
        WINRT_ASSERT(this->empty());

        if (0 != size)
        {
            this->m_data = static_cast<value_type*>(CoTaskMemAlloc(size * sizeof(value_type)));

            if (this->m_data == nullptr)
            {
                throw std::bad_alloc();
            }

            this->m_size = size;
        }
    }

    void destruct(std::true_type) noexcept
    {}

    void destruct(std::false_type) noexcept
    {
        for (value_type& v : *this)
        {
            v.~value_type();
        }
    }
};

template <typename T>
bool operator==(array_view<T> const& left, array_view<T> const& right) noexcept
{
    return std::equal(left.begin(), left.end(), right.begin(), right.end());
}

template <typename T>
bool operator<(array_view<T> const& left, array_view<T> const& right) noexcept
{
    return std::lexicographical_compare(left.begin(), left.end(), right.begin(), right.end());
}

template <typename T> bool operator!=(array_view<T> const& left, array_view<T> const& right) noexcept { return !(left == right); }
template <typename T> bool operator>(array_view<T> const& left, array_view<T> const& right) noexcept { return right < left; }
template <typename T> bool operator<=(array_view<T> const& left, array_view<T> const& right) noexcept { return !(right < left); }
template <typename T> bool operator>=(array_view<T> const& left, array_view<T> const& right) noexcept { return !(left < right); }

namespace impl
{
    template <typename T>
    struct array_size_proxy
    {
        array_size_proxy& operator=(array_size_proxy const&) = delete;

        array_size_proxy(com_array<T>& value) noexcept :
        m_value(value)
        {}

        ~array_size_proxy() noexcept
        {
            impl_put_size(m_value, m_size);
        }

        operator uint32_t* () noexcept
        {
            return&m_size;
        }

        operator unsigned long* () noexcept
        {
            return reinterpret_cast<unsigned long*>(&m_size);
        }

    private:

        com_array<T>& m_value;
        uint32_t m_size = 0;
    };

    template <typename T>
    struct com_array_proxy
    {
        com_array_proxy(uint32_t* size, winrt::impl::arg_out<T>* value) noexcept :
        m_size(size),
            m_value(value)
        {}

        ~com_array_proxy() noexcept
        {
            std::tie(*m_size, *m_value) = impl_detach(m_temp);
        }

        operator com_array<T>&() noexcept
        {
            return m_temp;
        }

        com_array_proxy(com_array_proxy const&) noexcept
        {
            WINRT_ASSERT(false);
        }

        com_array_proxy& operator=(com_array_proxy const&) noexcept
        {
            WINRT_ASSERT(false);
            return*this;
        }

    private:

        uint32_t* m_size;
        arg_out<T>* m_value;
        com_array<T> m_temp;
    };

    template <typename T>
    struct accessors<com_array<T>>
    {
        static auto put(com_array<T>& object) noexcept
        {
            return impl_put(object);
        }

        static array_size_proxy<T> put_size(com_array<T>& object) noexcept
        {
            return array_size_proxy<T>(object);
        }

        static auto detach(com_array<T>& object) noexcept
        {
            return impl_detach(object);
        }

        static auto data(com_array<T>& object) noexcept
        {
            return impl_data(object);
        }
    };

    template <typename T>
    struct accessors<array_view<T>, std::enable_if_t<!std::is_base_of<Windows::Foundation::IUnknown, T>::value>>
    {
        static auto get(array_view<T> object) noexcept
        {
            return reinterpret_cast<arg_out<std::remove_const_t<T>>>(const_cast<std::remove_const_t<T>*>(object.data()));
        }
    };

    template <typename T>
    struct accessors<array_view<T>, std::enable_if_t<std::is_base_of<Windows::Foundation::IUnknown, T>::value>>
    {
        static auto get(array_view<T> object) noexcept
        {
            return (::IUnknown**)object.data();
        }
    };
}

template <typename T>
auto detach_abi(uint32_t* __valueSize, impl::arg_out<T>* value) noexcept
{
    return impl::com_array_proxy<T>(__valueSize, value);
}

namespace Windows::Foundation
{
    inline com_array<GUID> GetIids(IInspectable const& object)
    {
        com_array<GUID> value;
        check_hresult((*(::IInspectable**)&object)->GetIids(impl::put_size_abi(value), put_abi(value)));
        return value;
    }
}
