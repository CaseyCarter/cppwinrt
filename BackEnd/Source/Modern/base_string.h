
namespace impl
{
    inline HSTRING duplicate_string(HSTRING other)
    {
        HSTRING result = nullptr;
        check_hresult(WindowsDuplicateString(other, &result));
        return result;
    }

    inline HSTRING create_string(const wchar_t * value, const uint32_t length)
    {
        HSTRING result = nullptr;
        check_hresult(WindowsCreateString(value, length, &result));
        return result;
    }

    inline bool embedded_null(HSTRING value) noexcept
    {
        BOOL result = 0;
        WINRT_VERIFY_(S_OK, WindowsStringHasEmbeddedNull(value, &result));
        return 0 != result;
    }

    struct hstring_traits : handle_traits<HSTRING>
    {
        static void close(type value) noexcept
        {
            WINRT_VERIFY_(S_OK, WindowsDeleteString(value));
        }
    };
}

struct hstring_view;

struct hstring
{
    using value_type = wchar_t;
    using size_type = uint32_t;
    using const_reference = const value_type &;
    using const_pointer = const value_type *;
    using const_iterator = const_pointer;
    using const_reverse_iterator = std::reverse_iterator<const_iterator>;

    hstring() noexcept = default;
    hstring(const hstring & value);
    hstring & operator=(const hstring & value);
    hstring(hstring && value) noexcept;
    hstring & operator=(hstring && value) noexcept;

    hstring(const std::wstring & value);
    hstring(hstring_view value);
    hstring(const wchar_t * value);
    hstring(const wchar_t * value, size_type size);

    void clear() noexcept;
    operator std::wstring() const;

    const_reference operator[](size_type pos) const noexcept;
    const_reference front() const noexcept;
    const_reference back() const noexcept;
    const_pointer data() const noexcept;
    const_pointer c_str() const noexcept;
    const_iterator begin() const noexcept;
    const_iterator cbegin() const noexcept;
    const_iterator end() const noexcept;
    const_iterator cend() const noexcept;
    const_reverse_iterator rbegin() const noexcept;
    const_reverse_iterator crbegin() const noexcept;
    const_reverse_iterator rend() const noexcept;
    const_reverse_iterator crend() const noexcept;
    bool empty() const noexcept;
    size_type size() const noexcept;

    friend HSTRING impl_get(const hstring & string) noexcept
    {
        return get_abi(string.m_handle);
    }

    friend HSTRING * impl_put(hstring & string) noexcept
    {
        return put_abi(string.m_handle);
    }

    friend HSTRING impl_detach(hstring & string) noexcept
    {
        return detach_abi(string.m_handle);
    }

    friend void swap(hstring & left, hstring & right) noexcept
    {
        swap(left.m_handle, right.m_handle);
    }

private:

    impl::handle<impl::hstring_traits> m_handle;
};

struct hstring_view
{
    using value_type = wchar_t;
    using size_type = uint32_t;
    using const_reference = const value_type &;
    using const_pointer = const value_type *;
    using const_iterator = const_pointer;
    using const_reverse_iterator = std::reverse_iterator<const_iterator>;

    hstring_view(const std::wstring & value) noexcept;
    hstring_view(const hstring & value) noexcept;
    hstring_view(const wchar_t * value) noexcept;
    explicit hstring_view(HSTRING value) noexcept;

    operator std::wstring() const;

    const_reference operator[](size_type pos) const noexcept;
    const_reference front() const noexcept;
    const_reference back() const noexcept;
    const_pointer data() const noexcept;
    const_pointer c_str() const noexcept;
    const_iterator begin() const noexcept;
    const_iterator cbegin() const noexcept;
    const_iterator end() const noexcept;
    const_iterator cend() const noexcept;
    const_reverse_iterator rbegin() const noexcept;
    const_reverse_iterator crbegin() const noexcept;
    const_reverse_iterator rend() const noexcept;
    const_reverse_iterator crend() const noexcept;
    bool empty() const noexcept;
    size_type size() const noexcept;

    friend HSTRING impl_get(hstring_view string) noexcept
    {
        return string.m_handle;
    }

private:

    hstring_view(const wchar_t * value, size_type size) noexcept;

    HSTRING m_handle;
    HSTRING_HEADER m_header;
};

namespace impl
{
    template <> struct traits<hstring>
    {
        using abi = HSTRING;
    };

    template <> struct accessors<hstring>
    {
        static HSTRING get(const hstring & object) noexcept
        {
            return impl_get(object);
        }

        static HSTRING * put(hstring & object) noexcept
        {
            return impl_put(object);
        }

        static void attach(hstring & object, HSTRING value) noexcept
        {
            object.clear();
            *put(object) = value;
        }

        static void copy_from(hstring & object, HSTRING value)
        {
            attach(object, duplicate_string(value));
        }

        static void copy_to(const hstring & object, HSTRING & value)
        {
            WINRT_ASSERT(value == nullptr);
            value = duplicate_string(get(object));
        }

        static HSTRING detach(hstring & object) noexcept
        {
            return impl_detach(object);
        }
    };

    template <> struct accessors<hstring_view>
    {
        static HSTRING get(hstring_view object) noexcept
        {
            return impl_get(object);
        }

        static HSTRING detach(hstring_view object)
        {
            return duplicate_string(get(object));
        }
    };

    template <> struct accessors<const wchar_t *>
    {
        static HSTRING detach(const wchar_t * const value)
        {
            return create_string(value, static_cast<uint32_t>(wcslen(value)));
        }
    };

    template <> struct accessors<std::wstring>
    {
        static HSTRING detach(const std::wstring & value)
        {
            return create_string(value.c_str(), static_cast<uint32_t>(value.size()));
        }
    };
}

inline bool embedded_null(hstring_view value) noexcept
{
    return impl::embedded_null(get_abi(value));
}

inline bool embedded_null(const hstring & value) noexcept
{
    return impl::embedded_null(get_abi(value));
}

// TODO: this must be removed. The ABI projection should just use HSTRING directly.
namespace ABI { using hstring = HSTRING; }
