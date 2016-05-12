
inline bool operator==(hstring_ref left, hstring_ref right) noexcept
{
    return std::equal(left.begin(), left.end(), right.begin(), right.end());
}

inline bool operator==(hstring_ref left, const hstring & right) noexcept
{
    return std::equal(left.begin(), left.end(), right.begin(), right.end());
}

inline bool operator==(const hstring & left, hstring_ref right) noexcept
{
    return std::equal(left.begin(), left.end(), right.begin(), right.end());
}

inline bool operator==(const hstring & left, const hstring & right) noexcept
{
    return std::equal(left.begin(), left.end(), right.begin(), right.end());
}

inline bool operator==(hstring_ref left, const wchar_t * const right) noexcept
{
    return std::equal(left.begin(), left.end(), right, right + wcslen(right));
}

inline bool operator==(const wchar_t * const left, hstring_ref right) noexcept
{
    return std::equal(left, left + wcslen(left), right.begin(), right.end());
}

inline bool operator==(hstring_ref left, const std::wstring & right) noexcept
{
    return std::equal(left.begin(), left.end(), right.begin(), right.end());
}

inline bool operator==(const std::wstring & left, hstring_ref right) noexcept
{
    return std::equal(left.begin(), left.end(), right.begin(), right.end());
}

inline bool operator==(const hstring & left, const wchar_t * const right) noexcept
{
    return std::equal(left.begin(), left.end(), right, right + wcslen(right));
}

inline bool operator==(const wchar_t * const left, const hstring & right) noexcept
{
    return std::equal(left, left + wcslen(left), right.begin(), right.end());
}

inline bool operator==(const hstring & left, const std::wstring & right) noexcept
{
    return std::equal(left.begin(), left.end(), right.begin(), right.end());
}

inline bool operator==(const std::wstring & left, const hstring & right) noexcept
{
    return std::equal(left.begin(), left.end(), right.begin(), right.end());
}

inline bool operator<(hstring_ref left, hstring_ref right) noexcept
{
    return std::lexicographical_compare(left.begin(), left.end(), right.begin(), right.end());
}

inline bool operator<(hstring_ref left, const hstring & right) noexcept
{
    return std::lexicographical_compare(left.begin(), left.end(), right.begin(), right.end());
}

inline bool operator<(const hstring & left, hstring_ref right) noexcept
{
    return std::lexicographical_compare(left.begin(), left.end(), right.begin(), right.end());
}

inline bool operator<(const hstring & left, const hstring & right) noexcept
{
    return std::lexicographical_compare(left.begin(), left.end(), right.begin(), right.end());
}

inline bool operator<(hstring_ref left, const wchar_t * const right) noexcept
{
    return std::lexicographical_compare(left.begin(), left.end(), right, right + wcslen(right));
}

inline bool operator<(const wchar_t * const left, hstring_ref right) noexcept
{
    return std::lexicographical_compare(left, left + wcslen(left), right.begin(), right.end());
}

inline bool operator<(hstring_ref left, const std::wstring & right) noexcept
{
    return std::lexicographical_compare(left.begin(), left.end(), right.begin(), right.end());
}

inline bool operator<(const std::wstring & left, hstring_ref right) noexcept
{
    return std::lexicographical_compare(left.begin(), left.end(), right.begin(), right.end());
}

inline bool operator<(const hstring & left, const wchar_t * const right) noexcept
{
    return std::lexicographical_compare(left.begin(), left.end(), right, right + wcslen(right));
}

inline bool operator<(const wchar_t * const left, const hstring & right) noexcept
{
    return std::lexicographical_compare(left, left + wcslen(left), right.begin(), right.end());
}

inline bool operator<(const hstring & left, const std::wstring & right) noexcept
{
    return std::lexicographical_compare(left.begin(), left.end(), right.begin(), right.end());
}

inline bool operator<(const std::wstring & left, const hstring & right) noexcept
{
    return std::lexicographical_compare(left.begin(), left.end(), right.begin(), right.end());
}

inline bool operator!=(hstring_ref left, hstring_ref right) noexcept { return !(left == right); }
inline bool operator >(hstring_ref left, hstring_ref right) noexcept { return right < left; }
inline bool operator<=(hstring_ref left, hstring_ref right) noexcept { return !(right < left); }
inline bool operator>=(hstring_ref left, hstring_ref right) noexcept { return !(left < right); }

inline bool operator!=(hstring_ref left, const wchar_t * const right) noexcept { return !(left == right); }
inline bool operator >(hstring_ref left, const wchar_t * const right) noexcept { return right < left; }
inline bool operator<=(hstring_ref left, const wchar_t * const right) noexcept { return !(right < left); }
inline bool operator>=(hstring_ref left, const wchar_t * const right) noexcept { return !(left < right); }

inline bool operator!=(const wchar_t * const left, hstring_ref right) noexcept { return !(left == right); }
inline bool operator >(const wchar_t * const left, hstring_ref right) noexcept { return right < left; }
inline bool operator<=(const wchar_t * const left, hstring_ref right) noexcept { return !(right < left); }
inline bool operator>=(const wchar_t * const left, hstring_ref right) noexcept { return !(left < right); }

inline bool operator!=(hstring_ref left, const std::wstring & right) noexcept { return !(left == right); }
inline bool operator >(hstring_ref left, const std::wstring & right) noexcept { return right < left; }
inline bool operator<=(hstring_ref left, const std::wstring & right) noexcept { return !(right < left); }
inline bool operator>=(hstring_ref left, const std::wstring & right) noexcept { return !(left < right); }

inline bool operator!=(const std::wstring & left, hstring_ref right) noexcept { return !(left == right); }
inline bool operator >(const std::wstring & left, hstring_ref right) noexcept { return right < left; }
inline bool operator<=(const std::wstring & left, hstring_ref right) noexcept { return !(right < left); }
inline bool operator>=(const std::wstring & left, hstring_ref right) noexcept { return !(left < right); }

inline bool operator!=(hstring_ref left, const hstring & right) noexcept { return !(left == right); }
inline bool operator >(hstring_ref left, const hstring & right) noexcept { return right < left; }
inline bool operator<=(hstring_ref left, const hstring & right) noexcept { return !(right < left); }
inline bool operator>=(hstring_ref left, const hstring & right) noexcept { return !(left < right); }

inline bool operator!=(const hstring & left, hstring_ref right) noexcept { return !(left == right); }
inline bool operator >(const hstring & left, hstring_ref right) noexcept { return right < left; }
inline bool operator<=(const hstring & left, hstring_ref right) noexcept { return !(right < left); }
inline bool operator>=(const hstring & left, hstring_ref right) noexcept { return !(left < right); }

inline bool operator!=(const hstring & left, const hstring & right) noexcept { return !(left == right); }
inline bool operator >(const hstring & left, const hstring & right) noexcept { return right < left; }
inline bool operator<=(const hstring & left, const hstring & right) noexcept { return !(right < left); }
inline bool operator>=(const hstring & left, const hstring & right) noexcept { return !(left < right); }

inline bool operator!=(const hstring & left, const wchar_t * const right) noexcept { return !(left == right); }
inline bool operator >(const hstring & left, const wchar_t * const right) noexcept { return right < left; }
inline bool operator<=(const hstring & left, const wchar_t * const right) noexcept { return !(right < left); }
inline bool operator>=(const hstring & left, const wchar_t * const right) noexcept { return !(left < right); }

inline bool operator!=(const wchar_t * const left, const hstring & right) noexcept { return !(left == right); }
inline bool operator >(const wchar_t * const left, const hstring & right) noexcept { return right < left; }
inline bool operator<=(const wchar_t * const left, const hstring & right) noexcept { return !(right < left); }
inline bool operator>=(const wchar_t * const left, const hstring & right) noexcept { return !(left < right); }

inline bool operator!=(const hstring & left, const std::wstring & right) noexcept { return !(left == right); }
inline bool operator >(const hstring & left, const std::wstring & right) noexcept { return right < left; }
inline bool operator<=(const hstring & left, const std::wstring & right) noexcept { return !(right < left); }
inline bool operator>=(const hstring & left, const std::wstring & right) noexcept { return !(left < right); }

inline bool operator!=(const std::wstring & left, const hstring & right) noexcept { return !(left == right); }
inline bool operator >(const std::wstring & left, const hstring & right) noexcept { return right < left; }
inline bool operator<=(const std::wstring & left, const hstring & right) noexcept { return !(right < left); }
inline bool operator>=(const std::wstring & left, const hstring & right) noexcept { return !(left < right); }
