
namespace impl
{
    inline HSTRING duplicate_string(HSTRING other)
    {
        HSTRING result = nullptr;
        check_hresult(WindowsDuplicateString(other, &result));
        return result;
    }

    inline HSTRING create_string(wchar_t const* value, uint32_t const length)
    {
        HSTRING result = nullptr;
        check_hresult(WindowsCreateString(value, length, &result));
        return result;
    }

    inline uint32_t string_length(wchar_t const* value) noexcept
    {
        size_t length = 0;
        if (value)
        {
            length = wcslen(value);
        }
        WINRT_ASSERT(length <= 0xffffffff);
        return static_cast<uint32_t>(length);
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

struct hstring
{
    using value_type = wchar_t;
    using size_type = uint32_t;
    using const_reference = value_type const&;
    using const_pointer = value_type const*;
    using const_iterator = const_pointer;
    using const_reverse_iterator = std::reverse_iterator<const_iterator>;

    hstring(std::nullptr_t = nullptr) noexcept {}
    hstring(hstring const& value);
    hstring& operator=(hstring const& value);
    hstring(hstring&&) noexcept = default;
    hstring& operator=(hstring&&)  = default;

    hstring(wchar_t const* value);
    hstring(wchar_t const* value, size_type size);
    hstring(std::wstring const& value);

    explicit hstring(std::wstring_view const& value);

    hstring& operator=(std::wstring_view const& value);

    void clear() noexcept;
    operator std::wstring_view() const noexcept;

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

    friend HSTRING impl_get(hstring const& string) noexcept
    {
        return get_abi(string.m_handle);
    }

    friend HSTRING* impl_put(hstring& string) noexcept
    {
        return put_abi(string.m_handle);
    }

    friend HSTRING impl_detach(hstring& string) noexcept
    {
        return detach_abi(string.m_handle);
    }

    friend void swap(hstring& left, hstring& right) noexcept
    {
        swap(left.m_handle, right.m_handle);
    }

private:

    impl::handle<impl::hstring_traits> m_handle;
};

namespace impl
{
    template <> struct abi<hstring>
    {
        using type = HSTRING;
    };

    template <> struct name<hstring>
    {
        static constexpr auto & value{ L"String" };
        static constexpr auto & data{ "string" };
    };

    template <> struct category<hstring>
    {
        using type = basic_category;
    };

    template <> struct accessors<hstring>
    {
        static HSTRING get(hstring const& object) noexcept
        {
            return impl_get(object);
        }

        static HSTRING* put(hstring& object) noexcept
        {
            return impl_put(object);
        }

        static void attach(hstring& object, HSTRING value) noexcept
        {
            object.clear();
            *put(object) = value;
        }

        static void copy_from(hstring& object, HSTRING value)
        {
            attach(object, duplicate_string(value));
        }

        static void copy_to(hstring const& object, HSTRING& value)
        {
            WINRT_ASSERT(value == nullptr);
            value = duplicate_string(get(object));
        }

        static HSTRING detach(hstring& object) noexcept
        {
            return impl_detach(object);
        }
    };

    template <> struct accessors<wchar_t const*>
    {
        static HSTRING detach(wchar_t const* const value)
        {
            return create_string(value, string_length(value));
        }
    };

    template <> struct accessors<std::wstring>
    {
        static HSTRING detach(std::wstring const& value)
        {
            return create_string(value.c_str(), static_cast<uint32_t>(value.size()));
        }
    };

    template <> struct accessors<std::wstring_view>
    {
        static HSTRING detach(std::wstring_view const& value)
        {
            return create_string(value.data(), static_cast<uint32_t>(value.size()));
        }
    };
}

inline bool embedded_null(hstring const& value) noexcept
{
    return impl::embedded_null(get_abi(value));
}
