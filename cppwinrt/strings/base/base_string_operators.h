
inline bool operator==(hstring_view left, hstring_view right) noexcept
{
    return std::equal(left.begin(), left.end(), right.begin(), right.end());
}

inline bool operator==(hstring_view left, hstring const& right) noexcept
{
    return std::equal(left.begin(), left.end(), right.begin(), right.end());
}

inline bool operator==(hstring const& left, hstring_view right) noexcept
{
    return std::equal(left.begin(), left.end(), right.begin(), right.end());
}

inline bool operator==(hstring const& left, hstring const& right) noexcept
{
    return std::equal(left.begin(), left.end(), right.begin(), right.end());
}

inline bool operator==(hstring_view left, wchar_t const* const right) noexcept
{
    return std::equal(left.begin(), left.end(), right, right + wcslen(right));
}

inline bool operator==(wchar_t const* const left, hstring_view right) noexcept
{
    return std::equal(left, left + wcslen(left), right.begin(), right.end());
}

inline bool operator==(hstring_view left, std::wstring const& right) noexcept
{
    return std::equal(left.begin(), left.end(), right.begin(), right.end());
}

inline bool operator==(std::wstring const& left, hstring_view right) noexcept
{
    return std::equal(left.begin(), left.end(), right.begin(), right.end());
}

inline bool operator==(hstring const& left, wchar_t const* const right) noexcept
{
    return std::equal(left.begin(), left.end(), right, right + wcslen(right));
}

inline bool operator==(wchar_t const* const left, hstring const& right) noexcept
{
    return std::equal(left, left + wcslen(left), right.begin(), right.end());
}

inline bool operator==(hstring const& left, std::wstring const& right) noexcept
{
    return std::equal(left.begin(), left.end(), right.begin(), right.end());
}

inline bool operator==(std::wstring const& left, hstring const& right) noexcept
{
    return std::equal(left.begin(), left.end(), right.begin(), right.end());
}

inline bool operator<(hstring_view left, hstring_view right) noexcept
{
    return std::lexicographical_compare(left.begin(), left.end(), right.begin(), right.end());
}

inline bool operator<(hstring_view left, hstring const& right) noexcept
{
    return std::lexicographical_compare(left.begin(), left.end(), right.begin(), right.end());
}

inline bool operator<(hstring const& left, hstring_view right) noexcept
{
    return std::lexicographical_compare(left.begin(), left.end(), right.begin(), right.end());
}

inline bool operator<(hstring const& left, hstring const& right) noexcept
{
    return std::lexicographical_compare(left.begin(), left.end(), right.begin(), right.end());
}

inline bool operator<(hstring_view left, wchar_t const* const right) noexcept
{
    return std::lexicographical_compare(left.begin(), left.end(), right, right + wcslen(right));
}

inline bool operator<(wchar_t const* const left, hstring_view right) noexcept
{
    return std::lexicographical_compare(left, left + wcslen(left), right.begin(), right.end());
}

inline bool operator<(hstring_view left, std::wstring const& right) noexcept
{
    return std::lexicographical_compare(left.begin(), left.end(), right.begin(), right.end());
}

inline bool operator<(std::wstring const& left, hstring_view right) noexcept
{
    return std::lexicographical_compare(left.begin(), left.end(), right.begin(), right.end());
}

inline bool operator<(hstring const& left, wchar_t const* const right) noexcept
{
    return std::lexicographical_compare(left.begin(), left.end(), right, right + wcslen(right));
}

inline bool operator<(wchar_t const* const left, hstring const& right) noexcept
{
    return std::lexicographical_compare(left, left + wcslen(left), right.begin(), right.end());
}

inline bool operator<(hstring const& left, std::wstring const& right) noexcept
{
    return std::lexicographical_compare(left.begin(), left.end(), right.begin(), right.end());
}

inline bool operator<(std::wstring const& left, hstring const& right) noexcept
{
    return std::lexicographical_compare(left.begin(), left.end(), right.begin(), right.end());
}

inline bool operator!=(hstring_view left, hstring_view right) noexcept { return !(left == right); }
inline bool operator >(hstring_view left, hstring_view right) noexcept { return right < left; }
inline bool operator<=(hstring_view left, hstring_view right) noexcept { return !(right < left); }
inline bool operator>=(hstring_view left, hstring_view right) noexcept { return !(left < right); }

inline bool operator!=(hstring_view left, wchar_t const* const right) noexcept { return !(left == right); }
inline bool operator >(hstring_view left, wchar_t const* const right) noexcept { return right < left; }
inline bool operator<=(hstring_view left, wchar_t const* const right) noexcept { return !(right < left); }
inline bool operator>=(hstring_view left, wchar_t const* const right) noexcept { return !(left < right); }

inline bool operator!=(wchar_t const* const left, hstring_view right) noexcept { return !(left == right); }
inline bool operator >(wchar_t const* const left, hstring_view right) noexcept { return right < left; }
inline bool operator<=(wchar_t const* const left, hstring_view right) noexcept { return !(right < left); }
inline bool operator>=(wchar_t const* const left, hstring_view right) noexcept { return !(left < right); }

inline bool operator!=(hstring_view left, std::wstring const& right) noexcept { return !(left == right); }
inline bool operator >(hstring_view left, std::wstring const& right) noexcept { return right < left; }
inline bool operator<=(hstring_view left, std::wstring const& right) noexcept { return !(right < left); }
inline bool operator>=(hstring_view left, std::wstring const& right) noexcept { return !(left < right); }

inline bool operator!=(std::wstring const& left, hstring_view right) noexcept { return !(left == right); }
inline bool operator >(std::wstring const& left, hstring_view right) noexcept { return right < left; }
inline bool operator<=(std::wstring const& left, hstring_view right) noexcept { return !(right < left); }
inline bool operator>=(std::wstring const& left, hstring_view right) noexcept { return !(left < right); }

inline bool operator!=(hstring_view left, hstring const& right) noexcept { return !(left == right); }
inline bool operator >(hstring_view left, hstring const& right) noexcept { return right < left; }
inline bool operator<=(hstring_view left, hstring const& right) noexcept { return !(right < left); }
inline bool operator>=(hstring_view left, hstring const& right) noexcept { return !(left < right); }

inline bool operator!=(hstring const& left, hstring_view right) noexcept { return !(left == right); }
inline bool operator >(hstring const& left, hstring_view right) noexcept { return right < left; }
inline bool operator<=(hstring const& left, hstring_view right) noexcept { return !(right < left); }
inline bool operator>=(hstring const& left, hstring_view right) noexcept { return !(left < right); }

inline bool operator!=(hstring const& left, hstring const& right) noexcept { return !(left == right); }
inline bool operator >(hstring const& left, hstring const& right) noexcept { return right < left; }
inline bool operator<=(hstring const& left, hstring const& right) noexcept { return !(right < left); }
inline bool operator>=(hstring const& left, hstring const& right) noexcept { return !(left < right); }

inline bool operator!=(hstring const& left, wchar_t const* const right) noexcept { return !(left == right); }
inline bool operator >(hstring const& left, wchar_t const* const right) noexcept { return right < left; }
inline bool operator<=(hstring const& left, wchar_t const* const right) noexcept { return !(right < left); }
inline bool operator>=(hstring const& left, wchar_t const* const right) noexcept { return !(left < right); }

inline bool operator!=(wchar_t const* const left, hstring const& right) noexcept { return !(left == right); }
inline bool operator >(wchar_t const* const left, hstring const& right) noexcept { return right < left; }
inline bool operator<=(wchar_t const* const left, hstring const& right) noexcept { return !(right < left); }
inline bool operator>=(wchar_t const* const left, hstring const& right) noexcept { return !(left < right); }

inline bool operator!=(hstring const& left, std::wstring const& right) noexcept { return !(left == right); }
inline bool operator >(hstring const& left, std::wstring const& right) noexcept { return right < left; }
inline bool operator<=(hstring const& left, std::wstring const& right) noexcept { return !(right < left); }
inline bool operator>=(hstring const& left, std::wstring const& right) noexcept { return !(left < right); }

inline bool operator!=(std::wstring const& left, hstring const& right) noexcept { return !(left == right); }
inline bool operator >(std::wstring const& left, hstring const& right) noexcept { return right < left; }
inline bool operator<=(std::wstring const& left, hstring const& right) noexcept { return !(right < left); }
inline bool operator>=(std::wstring const& left, hstring const& right) noexcept { return !(left < right); }
