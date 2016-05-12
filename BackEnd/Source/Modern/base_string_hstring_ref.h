
inline hstring_ref::hstring_ref(const std::wstring & value) noexcept :
    hstring_ref(value.c_str(), static_cast<size_type>(value.size()))
{}

inline hstring_ref::hstring_ref(const hstring & value) noexcept :
    m_handle(get(value))
{}

inline hstring_ref::hstring_ref(const wchar_t * const value) noexcept :
    hstring_ref(value, static_cast<size_type>(wcslen(value)))
{}

inline hstring_ref::hstring_ref(const wchar_t * const value, const size_type size) noexcept
{
    WINRT_VERIFY_(S_OK, WindowsCreateStringReference(value, size, &m_header, &m_handle));
}

inline hstring_ref::hstring_ref(HSTRING value) noexcept :
    m_handle(value)
{}

inline hstring_ref::operator std::wstring() const
{
    return std::wstring(begin(), end());
}

inline hstring_ref::const_reference hstring_ref::operator[](const size_type pos) const noexcept
{
    WINRT_ASSERT(pos < size());
    return *(begin() + pos);
}

inline hstring_ref::const_reference hstring_ref::front() const noexcept
{
    WINRT_ASSERT(!empty());
    return *begin();
}

inline hstring_ref::const_reference hstring_ref::back() const noexcept
{
    WINRT_ASSERT(!empty());
    return *(end() - 1);
}

inline hstring_ref::const_pointer hstring_ref::data() const noexcept
{
    return begin();
}

inline hstring_ref::const_pointer hstring_ref::c_str() const noexcept
{
    return begin();
}

inline hstring_ref::const_iterator hstring_ref::begin() const noexcept
{
    return WindowsGetStringRawBuffer(m_handle, nullptr);
}

inline hstring_ref::const_iterator hstring_ref::cbegin() const noexcept
{
    return begin();
}

inline hstring_ref::const_iterator hstring_ref::end() const noexcept
{
    uint32_t length = 0;
    const_pointer buffer = WindowsGetStringRawBuffer(m_handle, &length);

    return buffer + length;
}

inline hstring_ref::const_iterator hstring_ref::cend() const noexcept
{
    return end();
}

inline hstring_ref::const_reverse_iterator hstring_ref::rbegin() const noexcept
{
    return const_reverse_iterator(end());
}

inline hstring_ref::const_reverse_iterator hstring_ref::crbegin() const noexcept
{
    return rbegin();
}

inline hstring_ref::const_reverse_iterator hstring_ref::rend() const noexcept
{
    return const_reverse_iterator(begin());
}

inline hstring_ref::const_reverse_iterator hstring_ref::crend() const noexcept
{
    return rend();
}

inline bool hstring_ref::empty() const noexcept
{
    return 0 == size();
}

inline hstring_ref::size_type hstring_ref::size() const noexcept
{
    return WindowsGetStringLen(m_handle);
}
