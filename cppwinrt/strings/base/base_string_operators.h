
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
    inline hstring concat_hstring(param::hstring const& left, param::hstring const& right)
    {
        hstring result;
        check_hresult(WindowsConcatString(get_abi(left), get_abi(right), put_abi(result)));
        return result;
    }
}

inline hstring operator+(hstring const& left, hstring const& right)
{
    return impl::concat_hstring(left, right);
}

inline hstring operator+(hstring const& left, std::wstring const& right)
{
    return impl::concat_hstring(left, right);
}

inline hstring operator+(std::wstring const& left, hstring const& right)
{
    return impl::concat_hstring(left, right);
}

inline hstring operator+(hstring const& left, wchar_t const* right)
{
    return impl::concat_hstring(left, right);
}

inline hstring operator+(wchar_t const* left, hstring const& right)
{
    return impl::concat_hstring(left, right);
}

inline hstring operator+(hstring const& left, wchar_t right)
{
    return impl::concat_hstring(left, std::wstring_view(&right, 1));
}

inline hstring operator+(wchar_t left, hstring const& right)
{
    return impl::concat_hstring(std::wstring_view(&left, 1), right);
}

inline hstring operator+(hstring const& left, nullptr_t)
{
    return left;
}

inline hstring operator+(nullptr_t, hstring const& right)
{
    return right;
}

inline hstring operator+(hstring const& left, std::wstring_view const& right)
{
    return impl::concat_hstring(left, right);
}

inline hstring operator+(std::wstring_view const& left, hstring const& right)
{
    return impl::concat_hstring(left, right);
}
