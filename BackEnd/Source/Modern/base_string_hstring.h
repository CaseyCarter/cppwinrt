
inline hstring::hstring(hstring const & value) :
	m_handle(impl::duplicate_string(get(value.m_handle)))
{}

inline hstring & hstring::operator=(hstring const & value)
{
	m_handle = impl::duplicate_string(get(value.m_handle));
	return *this;
}

inline hstring::hstring(hstring && value) noexcept :
	m_handle(std::move(value.m_handle))
{}

inline hstring & hstring::operator=(hstring && value) noexcept
{
	m_handle = std::move(value.m_handle);
	return *this;
}

inline hstring::hstring(std::wstring const & value) :
	hstring(value.c_str(), static_cast<size_type>(value.size()))
{}

inline hstring::hstring(hstring_ref value) :
	m_handle(impl::duplicate_string(get(value)))
{}

inline hstring::hstring(wchar_t const * const value) :
	hstring(value, static_cast<size_type>(wcslen(value)))
{}

inline hstring::hstring(wchar_t const * const value, size_type const size) :
	m_handle(impl::create_string(value, size))
{}

inline void hstring::clear() noexcept
{
	m_handle.close();
}

inline hstring::operator std::wstring() const
{
	return std::wstring(begin(), end());
}

inline hstring::const_reference hstring::operator[](size_type const pos) const noexcept
{
	WINRT_ASSERT(pos < size());
	return *(begin() + pos);
}

inline hstring::const_reference hstring::front() const noexcept
{
	WINRT_ASSERT(!empty());
	return *begin();
}

inline hstring::const_reference hstring::back() const noexcept
{
	WINRT_ASSERT(!empty());
	return *(end() - 1);
}

inline hstring::const_pointer hstring::data() const noexcept
{
	return begin();
}

inline hstring::const_pointer hstring::c_str() const noexcept
{
	return begin();
}

inline hstring::const_iterator hstring::begin() const noexcept
{
	return WindowsGetStringRawBuffer(get(m_handle), nullptr);
}

inline hstring::const_iterator hstring::cbegin() const noexcept
{
	return begin();
}

inline hstring::const_iterator hstring::end() const noexcept
{
	unsigned length = 0;
	const_pointer buffer = WindowsGetStringRawBuffer(get(m_handle), &length);
	return buffer + length;
}

inline hstring::const_iterator hstring::cend() const noexcept
{
	return end();
}

inline hstring::const_reverse_iterator hstring::rbegin() const noexcept
{
	return const_reverse_iterator(end());
}

inline hstring::const_reverse_iterator hstring::crbegin() const noexcept
{
	return rbegin();
}

inline hstring::const_reverse_iterator hstring::rend() const noexcept
{
	return const_reverse_iterator(begin());
}

inline hstring::const_reverse_iterator hstring::crend() const noexcept
{
	return rend();
}

inline bool hstring::empty() const noexcept
{
	return 0 == size();
}

inline hstring::size_type hstring::size() const noexcept
{
	return WindowsGetStringLen(get(m_handle));
}