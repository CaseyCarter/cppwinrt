
inline bool operator==(hstring const& left, hstring const& right) noexcept
{
    return std::wstring_view(left) == std::wstring_view(right);
}

inline bool operator==(hstring const& left, std::wstring const& right) noexcept
{
    return std::wstring_view(left) == right;
}

inline bool operator==(std::wstring const& left, hstring const& right) noexcept
{
    return left == std::wstring_view(right);
}

inline bool operator==(hstring const& left, wchar_t const* right) noexcept
{
    return std::wstring_view(left) == right;
}

inline bool operator==(wchar_t const* left, hstring const& right) noexcept
{
    return left == std::wstring_view(right);
}

inline bool operator==(hstring const& left, nullptr_t) noexcept
{
    return left == hstring();
}

inline bool operator==(nullptr_t, hstring const& right) noexcept
{
    return hstring() == right;
}

inline bool operator<(hstring const& left, hstring const& right) noexcept
{
    return std::wstring_view(left) < std::wstring_view(right);
}

inline bool operator<(std::wstring const& left, hstring const& right) noexcept
{
    return left < std::wstring_view(right);
}

inline bool operator<(hstring const& left, std::wstring const& right) noexcept
{
    return std::wstring_view(left) < right;
}

inline bool operator<(hstring const& left, wchar_t const* right) noexcept
{
    return std::wstring_view(left) < right;
}

inline bool operator<(wchar_t const* left, hstring const& right) noexcept
{
    return left < std::wstring_view(right);
}

inline bool operator<(hstring const& left, nullptr_t) noexcept
{
    return left < hstring();
}

inline bool operator<(nullptr_t, hstring const& right) noexcept
{
    return hstring() < right;
}

inline bool operator!=(hstring const& left, hstring const& right) noexcept { return !(left == right); }
inline bool operator>(hstring const& left, hstring const& right) noexcept { return right < left; }
inline bool operator<=(hstring const& left, hstring const& right) noexcept { return !(right < left); }
inline bool operator>=(hstring const& left, hstring const& right) noexcept { return !(left < right); }

inline bool operator!=(hstring const& left, std::wstring const& right) noexcept { return !(left == right); }
inline bool operator>(hstring const& left, std::wstring const& right) noexcept { return right < left; }
inline bool operator<=(hstring const& left, std::wstring const& right) noexcept { return !(right < left); }
inline bool operator>=(hstring const& left, std::wstring const& right) noexcept { return !(left < right); }

inline bool operator!=(std::wstring const& left, hstring const& right) noexcept { return !(left == right); }
inline bool operator>(std::wstring const& left, hstring const& right) noexcept { return right < left; }
inline bool operator<=(std::wstring const& left, hstring const& right) noexcept { return !(right < left); }
inline bool operator>=(std::wstring const& left, hstring const& right) noexcept { return !(left < right); }

inline bool operator!=(hstring const& left, wchar_t const* right) noexcept { return !(left == right); }
inline bool operator>(hstring const& left, wchar_t const* right) noexcept { return right < left; }
inline bool operator<=(hstring const& left, wchar_t const* right) noexcept { return !(right < left); }
inline bool operator>=(hstring const& left, wchar_t const* right) noexcept { return !(left < right); }

inline bool operator!=(wchar_t const* left, hstring const& right) noexcept { return !(left == right); }
inline bool operator>(wchar_t const* left, hstring const& right) noexcept { return right < left; }
inline bool operator<=(wchar_t const* left, hstring const& right) noexcept { return !(right < left); }
inline bool operator>=(wchar_t const* left, hstring const& right) noexcept { return !(left < right); }

inline bool operator!=(hstring const& left, nullptr_t right) noexcept { return !(left == right); }
inline bool operator>(hstring const& left, nullptr_t right) noexcept { return right < left; }
inline bool operator<=(hstring const& left, nullptr_t right) noexcept { return !(right < left); }
inline bool operator>=(hstring const& left, nullptr_t right) noexcept { return !(left < right); }

inline bool operator!=(nullptr_t left, hstring const& right) noexcept { return !(left == right); }
inline bool operator>(nullptr_t left, hstring const& right) noexcept { return right < left; }
inline bool operator<=(nullptr_t left, hstring const& right) noexcept { return !(right < left); }
inline bool operator>=(nullptr_t left, hstring const& right) noexcept { return !(left < right); }

namespace impl
{
    inline hstring concat_hstring_abi(HSTRING left, HSTRING right)
    {
        hstring result;
        check_hresult(WindowsConcatString(left, right, put_abi(result)));
        return result;
    }

    inline hstring concat_hstring_abi(HSTRING left, std::wstring_view const& right)
    {
        HSTRING_HEADER hdr;
        HSTRING str;
        WINRT_VERIFY_(S_OK, WindowsCreateStringReference(right.data(), static_cast<uint32_t>(right.length()), &hdr, &str));
        return concat_hstring_abi(left, str);
    }

    inline hstring concat_hstring_abi(std::wstring_view const& left, HSTRING right)
    {
        HSTRING_HEADER hdr;
        HSTRING str;
        WINRT_VERIFY_(S_OK, WindowsCreateStringReference(left.data(), static_cast<uint32_t>(left.length()), &hdr, &str));
        return concat_hstring_abi(str, right);
    }
}

inline hstring operator+(hstring const& left, hstring const& right)
{
    return impl::concat_hstring_abi(get_abi(left), get_abi(right));
}

inline hstring operator+(hstring const& left, std::wstring const& right)
{
    return impl::concat_hstring_abi(get_abi(left), std::wstring_view(right));
}

inline hstring operator+(std::wstring const& left, hstring const& right)
{
    return impl::concat_hstring_abi(std::wstring_view(left), get_abi(right));
}

inline hstring operator+(hstring const& left, wchar_t const* right)
{
    return impl::concat_hstring_abi(get_abi(left), std::wstring_view(right));
}

inline hstring operator+(wchar_t const* left, hstring const& right)
{
    return impl::concat_hstring_abi(std::wstring_view(left), get_abi(right));
}

inline hstring operator+(hstring const& left, wchar_t right)
{
    return impl::concat_hstring_abi(get_abi(left), std::wstring_view(&right, 1));
}

inline hstring operator+(wchar_t left, hstring const& right)
{
    return impl::concat_hstring_abi(std::wstring_view(&left, 1), get_abi(right));
}

inline hstring operator+(hstring const& left, nullptr_t)
{
    return impl::concat_hstring_abi(get_abi(left), nullptr);
}

inline hstring operator+(nullptr_t, hstring const& right)
{
    return impl::concat_hstring_abi(nullptr, get_abi(right));
}

inline hstring operator+(hstring const& left, std::wstring_view const& right)
{
    return impl::concat_hstring_abi(get_abi(left), right);
}

inline hstring operator+(std::wstring_view const& left, hstring const& right)
{
    return impl::concat_hstring_abi(left, get_abi(right));
}
