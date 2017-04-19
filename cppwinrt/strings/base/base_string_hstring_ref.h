
inline hstring_view::hstring_view(std::wstring const& value) noexcept :
hstring_view(value.c_str(), static_cast<size_type>(value.size()))
{}

inline hstring_view::hstring_view(hstring const& value) noexcept :
    m_handle(get_abi(value))
{}

inline hstring_view::hstring_view(wchar_t const* const value) noexcept :
    hstring_view(value, static_cast<size_type>(wcslen(value)))
{}

inline hstring_view::hstring_view(wchar_t const* const value, size_type const size) noexcept
{
    WINRT_VERIFY_(S_OK, WindowsCreateStringReference(value, size, &m_header, &m_handle));
}

inline hstring_view::hstring_view(HSTRING value) noexcept :
m_handle(value)
{}

inline hstring_view::operator std::wstring() const
{
    return std::wstring(begin(), end());
}

inline hstring_view::const_reference hstring_view::operator[](size_type const pos) const noexcept
{
    WINRT_ASSERT(pos < size());
    return*(begin() + pos);
}

inline hstring_view::const_reference hstring_view::front() const noexcept
{
    WINRT_ASSERT(!empty());
    return*begin();
}

inline hstring_view::const_reference hstring_view::back() const noexcept
{
    WINRT_ASSERT(!empty());
    return*(end() - 1);
}

inline hstring_view::const_pointer hstring_view::data() const noexcept
{
    return begin();
}

inline hstring_view::const_pointer hstring_view::c_str() const noexcept
{
    return begin();
}

inline hstring_view::const_iterator hstring_view::begin() const noexcept
{
    return WindowsGetStringRawBuffer(m_handle, nullptr);
}

inline hstring_view::const_iterator hstring_view::cbegin() const noexcept
{
    return begin();
}

inline hstring_view::const_iterator hstring_view::end() const noexcept
{
    uint32_t length = 0;
    const_pointer buffer = WindowsGetStringRawBuffer(m_handle, &length);

    return buffer + length;
}

inline hstring_view::const_iterator hstring_view::cend() const noexcept
{
    return end();
}

inline hstring_view::const_reverse_iterator hstring_view::rbegin() const noexcept
{
    return const_reverse_iterator(end());
}

inline hstring_view::const_reverse_iterator hstring_view::crbegin() const noexcept
{
    return rbegin();
}

inline hstring_view::const_reverse_iterator hstring_view::rend() const noexcept
{
    return const_reverse_iterator(begin());
}

inline hstring_view::const_reverse_iterator hstring_view::crend() const noexcept
{
    return rend();
}

inline bool hstring_view::empty() const noexcept
{
    return 0 == size();
}

inline hstring_view::size_type hstring_view::size() const noexcept
{
    return WindowsGetStringLen(m_handle);
}
