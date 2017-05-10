
inline bool operator==(hstring const& left, hstring const& right) noexcept
{
    return std::wstring_view(left) == std::wstring_view(right);
}

inline bool operator==(hstring const& left, std::wstring_view const& right) noexcept
{
    return std::wstring_view(left) == right;
}

inline bool operator==(std::wstring_view const& left, hstring const& right) noexcept
{
    return left == std::wstring_view(right);
}

inline bool operator<(hstring const& left, hstring const& right) noexcept
{
    return std::wstring_view(left) < std::wstring_view(right);
}

inline bool operator<(std::wstring_view const& left, hstring const& right) noexcept
{
    return left < std::wstring_view(right);
}

inline bool operator<(hstring const& left, std::wstring_view const& right) noexcept
{
    return std::wstring_view(left) < right;
}

inline bool operator!=(hstring const& left, hstring const& right) noexcept { return !(left == right); }
inline bool operator>(hstring const& left, hstring const& right) noexcept { return right < left; }
inline bool operator<=(hstring const& left, hstring const& right) noexcept { return !(right < left); }
inline bool operator>=(hstring const& left, hstring const& right) noexcept { return !(left < right); }

inline bool operator!=(hstring const& left, std::wstring_view const& right) noexcept { return !(left == right); }
inline bool operator>(hstring const& left, std::wstring_view const& right) noexcept { return right < left; }
inline bool operator<=(hstring const& left, std::wstring_view const& right) noexcept { return !(right < left); }
inline bool operator>=(hstring const& left, std::wstring_view const& right) noexcept { return !(left < right); }

inline bool operator!=(std::wstring_view const& left, hstring const& right) noexcept { return !(left == right); }
inline bool operator>(std::wstring_view const& left, hstring const& right) noexcept { return right < left; }
inline bool operator<=(std::wstring_view const& left, hstring const& right) noexcept { return !(right < left); }
inline bool operator>=(std::wstring_view const& left, hstring const& right) noexcept { return !(left < right); }

namespace impl
{
    inline hstring concat_hstring_abi(HSTRING left, HSTRING right)
    {
        hstring result;
        check_hresult(WindowsConcatString(left, right, put_abi(result)));
        return result;
    }
}

inline hstring operator+(hstring const& left, hstring const& right)
{
    return impl::concat_hstring_abi(get_abi(left), get_abi(right));
}

inline hstring operator+(hstring const& left, std::wstring_view const& right)
{
    if (right.empty())
    {
        return left;
    }
    HSTRING_HEADER hdr;
    HSTRING str;
    WINRT_VERIFY_(S_OK, WindowsCreateStringReference(right.data(), static_cast<uint32_t>(right.length()), &hdr, &str));
    return impl::concat_hstring_abi(get_abi(left), str);
}

inline hstring operator+(std::wstring_view const& left, hstring const& right)
{
    if (left.empty())
    {
        return right;
    }
    HSTRING_HEADER hdr;
    HSTRING str;
    WINRT_VERIFY_(S_OK, WindowsCreateStringReference(left.data(), static_cast<uint32_t>(left.length()), &hdr, &str));
    return impl::concat_hstring_abi(str, get_abi(right));
}
