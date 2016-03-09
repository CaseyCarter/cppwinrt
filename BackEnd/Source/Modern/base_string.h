
namespace winrt {

__forceinline void check_hresult(HRESULT result);

namespace impl {

inline HSTRING duplicate_string(HSTRING other)
{
	HSTRING result = nullptr;
	check_hresult(WindowsDuplicateString(other, &result));
	return result;
}

inline HSTRING create_string(wchar_t const * value, unsigned const length)
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

struct hstring_ref;

struct hstring
{
	using value_type = wchar_t;
	using size_type = uint32_t;
	using const_reference = value_type const &;
	using const_pointer = value_type const *;
	using const_iterator = const_pointer;
	using const_reverse_iterator = std::reverse_iterator<const_iterator>;

	hstring() noexcept = default;
	hstring(hstring const & value);
	hstring & operator=(hstring const & value);
	hstring(hstring && value) noexcept;
	hstring & operator=(hstring && value) noexcept;

	hstring(std::wstring const & value);
	hstring(hstring_ref value);
	hstring(wchar_t const * value);
	hstring(wchar_t const * value, size_type size);

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

	friend HSTRING impl_get(hstring const & string) noexcept
	{
		return get(string.m_handle);
	}

	friend HSTRING * impl_put(hstring & string) noexcept
	{
		return put(string.m_handle);
	}

	friend HSTRING impl_detach(hstring & string) noexcept
	{
		return detach(string.m_handle);
	}

	friend void swap(hstring & left, hstring & right) noexcept
	{
		std::swap(left.m_handle, right.m_handle);
	}

private:

	handle<impl::hstring_traits> m_handle;
};

struct hstring_ref
{
	using value_type = wchar_t;
	using size_type = uint32_t;
	using const_reference = value_type const &;
	using const_pointer = value_type const *;
	using const_iterator = const_pointer;
	using const_reverse_iterator = std::reverse_iterator<const_iterator>;

	hstring_ref(std::wstring const & value) noexcept;
	hstring_ref(hstring const & value) noexcept;
	hstring_ref(wchar_t const * value) noexcept;
	explicit hstring_ref(HSTRING value) noexcept;

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

	friend HSTRING impl_get(hstring_ref string) noexcept
	{
		return string.m_handle;
	}

private:

	hstring_ref(wchar_t const * value, size_type size) noexcept;

	HSTRING m_handle;
	HSTRING_HEADER m_header;
};

namespace impl {

template <> struct traits<hstring>
{
	using abi = HSTRING;
};

template <> struct accessors<hstring>
{
	static HSTRING get(hstring const & object) noexcept
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

	static void copy_to(hstring const & object, HSTRING & value)
	{
		WINRT_ASSERT(value == nullptr);
		value = duplicate_string(get(object));
	}

	static HSTRING detach(hstring & object) noexcept
	{
		return impl_detach(object);
	}

	static hstring_ref lease(HSTRING value) noexcept
	{
		return hstring_ref(value);
	}
};

template <> struct accessors<hstring_ref>
{
	static HSTRING get(hstring_ref object) noexcept
	{
		return impl_get(object);
	}

	static HSTRING detach(hstring_ref object)
	{
		return duplicate_string(get(object));
	}
};

template <> struct accessors<wchar_t const *>
{
	static HSTRING detach(wchar_t const * const value)
	{
		return create_string(value, static_cast<unsigned>(wcslen(value)));
	}
};

template <> struct accessors<std::wstring>
{
	static HSTRING detach(std::wstring const & value)
	{
		return create_string(value.c_str(), static_cast<unsigned>(value.size()));
	}
};

}

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

inline hstring_ref::hstring_ref(std::wstring const & value) noexcept :
	hstring_ref(value.c_str(), static_cast<size_type>(value.size()))
{}

inline hstring_ref::hstring_ref(hstring const & value) noexcept :
	m_handle(get(value))
{}

inline hstring_ref::hstring_ref(wchar_t const * const value) noexcept :
	hstring_ref(value, static_cast<size_type>(wcslen(value)))
{}

inline hstring_ref::hstring_ref(wchar_t const * const value, size_type const size) noexcept
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

inline hstring_ref::const_reference hstring_ref::operator[](size_type const pos) const noexcept
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
	unsigned length = 0;
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

inline bool embedded_null(hstring_ref value) noexcept
{
	return impl::embedded_null(get(value));
}

inline bool embedded_null(hstring const & value) noexcept
{
	return impl::embedded_null(get(value));
}

inline bool operator==(hstring_ref left, hstring_ref right) noexcept
{
	return std::equal(left.begin(), left.end(), right.begin(), right.end());
}

inline bool operator==(hstring_ref left, hstring const & right) noexcept
{
	return std::equal(left.begin(), left.end(), right.begin(), right.end());
}

inline bool operator==(hstring const & left, hstring_ref right) noexcept
{
	return std::equal(left.begin(), left.end(), right.begin(), right.end());
}

inline bool operator==(hstring const & left, hstring const & right) noexcept
{
	return std::equal(left.begin(), left.end(), right.begin(), right.end());
}

inline bool operator==(hstring_ref left, wchar_t const * const right) noexcept
{
	return std::equal(left.begin(), left.end(), right, right + wcslen(right));
}

inline bool operator==(wchar_t const * const left, hstring_ref right) noexcept
{
	return std::equal(left, left + wcslen(left), right.begin(), right.end());
}

inline bool operator==(hstring_ref left, std::wstring const & right) noexcept
{
	return std::equal(left.begin(), left.end(), right.begin(), right.end());
}

inline bool operator==(std::wstring const & left, hstring_ref right) noexcept
{
	return std::equal(left.begin(), left.end(), right.begin(), right.end());
}

inline bool operator==(hstring const & left, wchar_t const * const right) noexcept
{
	return std::equal(left.begin(), left.end(), right, right + wcslen(right));
}

inline bool operator==(wchar_t const * const left, hstring const & right) noexcept
{
	return std::equal(left, left + wcslen(left), right.begin(), right.end());
}

inline bool operator==(hstring const & left, std::wstring const & right) noexcept
{
	return std::equal(left.begin(), left.end(), right.begin(), right.end());
}

inline bool operator==(std::wstring const & left, hstring const & right) noexcept
{
	return std::equal(left.begin(), left.end(), right.begin(), right.end());
}

inline bool operator<(hstring_ref left, hstring_ref right) noexcept
{
	return std::lexicographical_compare(left.begin(), left.end(), right.begin(), right.end());
}

inline bool operator<(hstring_ref left, hstring const & right) noexcept
{
	return std::lexicographical_compare(left.begin(), left.end(), right.begin(), right.end());
}

inline bool operator<(hstring const & left, hstring_ref right) noexcept
{
	return std::lexicographical_compare(left.begin(), left.end(), right.begin(), right.end());
}

inline bool operator<(hstring const & left, hstring const & right) noexcept
{
	return std::lexicographical_compare(left.begin(), left.end(), right.begin(), right.end());
}

inline bool operator<(hstring_ref left, wchar_t const * const right) noexcept
{
	return std::lexicographical_compare(left.begin(), left.end(), right, right + wcslen(right));
}

inline bool operator<(wchar_t const * const left, hstring_ref right) noexcept
{
	return std::lexicographical_compare(left, left + wcslen(left), right.begin(), right.end());
}

inline bool operator<(hstring_ref left, std::wstring const & right) noexcept
{
	return std::lexicographical_compare(left.begin(), left.end(), right.begin(), right.end());
}

inline bool operator<(std::wstring const & left, hstring_ref right) noexcept
{
	return std::lexicographical_compare(left.begin(), left.end(), right.begin(), right.end());
}

inline bool operator<(hstring const & left, wchar_t const * const right) noexcept
{
	return std::lexicographical_compare(left.begin(), left.end(), right, right + wcslen(right));
}

inline bool operator<(wchar_t const * const left, hstring const & right) noexcept
{
	return std::lexicographical_compare(left, left + wcslen(left), right.begin(), right.end());
}

inline bool operator<(hstring const & left, std::wstring const & right) noexcept
{
	return std::lexicographical_compare(left.begin(), left.end(), right.begin(), right.end());
}

inline bool operator<(std::wstring const & left, hstring const & right) noexcept
{
	return std::lexicographical_compare(left.begin(), left.end(), right.begin(), right.end());
}

inline bool operator!=(hstring_ref left, hstring_ref right) noexcept { return !(left == right); }
inline bool operator >(hstring_ref left, hstring_ref right) noexcept { return right < left; }
inline bool operator<=(hstring_ref left, hstring_ref right) noexcept { return !(right < left); }
inline bool operator>=(hstring_ref left, hstring_ref right) noexcept { return !(left < right); }

inline bool operator!=(hstring_ref left, wchar_t const * const right) noexcept { return !(left == right); }
inline bool operator >(hstring_ref left, wchar_t const * const right) noexcept { return right < left; }
inline bool operator<=(hstring_ref left, wchar_t const * const right) noexcept { return !(right < left); }
inline bool operator>=(hstring_ref left, wchar_t const * const right) noexcept { return !(left < right); }

inline bool operator!=(wchar_t const * const left, hstring_ref right) noexcept { return !(left == right); }
inline bool operator >(wchar_t const * const left, hstring_ref right) noexcept { return right < left; }
inline bool operator<=(wchar_t const * const left, hstring_ref right) noexcept { return !(right < left); }
inline bool operator>=(wchar_t const * const left, hstring_ref right) noexcept { return !(left < right); }

inline bool operator!=(hstring_ref left, std::wstring const & right) noexcept { return !(left == right); }
inline bool operator >(hstring_ref left, std::wstring const & right) noexcept { return right < left; }
inline bool operator<=(hstring_ref left, std::wstring const & right) noexcept { return !(right < left); }
inline bool operator>=(hstring_ref left, std::wstring const & right) noexcept { return !(left < right); }

inline bool operator!=(std::wstring const & left, hstring_ref right) noexcept { return !(left == right); }
inline bool operator >(std::wstring const & left, hstring_ref right) noexcept { return right < left; }
inline bool operator<=(std::wstring const & left, hstring_ref right) noexcept { return !(right < left); }
inline bool operator>=(std::wstring const & left, hstring_ref right) noexcept { return !(left < right); }

inline bool operator!=(hstring_ref left, hstring const & right) noexcept { return !(left == right); }
inline bool operator >(hstring_ref left, hstring const & right) noexcept { return right < left; }
inline bool operator<=(hstring_ref left, hstring const & right) noexcept { return !(right < left); }
inline bool operator>=(hstring_ref left, hstring const & right) noexcept { return !(left < right); }

inline bool operator!=(hstring const & left, hstring_ref right) noexcept { return !(left == right); }
inline bool operator >(hstring const & left, hstring_ref right) noexcept { return right < left; }
inline bool operator<=(hstring const & left, hstring_ref right) noexcept { return !(right < left); }
inline bool operator>=(hstring const & left, hstring_ref right) noexcept { return !(left < right); }

inline bool operator!=(hstring const & left, hstring const & right) { return !(left == right); }
inline bool operator >(hstring const & left, hstring const & right) { return right < left; }
inline bool operator<=(hstring const & left, hstring const & right) { return !(right < left); }
inline bool operator>=(hstring const & left, hstring const & right) { return !(left < right); }

inline bool operator!=(hstring const & left, wchar_t const * const right) noexcept { return !(left == right); }
inline bool operator >(hstring const & left, wchar_t const * const right) noexcept { return right < left; }
inline bool operator<=(hstring const & left, wchar_t const * const right) noexcept { return !(right < left); }
inline bool operator>=(hstring const & left, wchar_t const * const right) noexcept { return !(left < right); }

inline bool operator!=(wchar_t const * const left, hstring const & right) noexcept { return !(left == right); }
inline bool operator >(wchar_t const * const left, hstring const & right) noexcept { return right < left; }
inline bool operator<=(wchar_t const * const left, hstring const & right) noexcept { return !(right < left); }
inline bool operator>=(wchar_t const * const left, hstring const & right) noexcept { return !(left < right); }

inline bool operator!=(hstring const & left, std::wstring const & right) noexcept { return !(left == right); }
inline bool operator >(hstring const & left, std::wstring const & right) noexcept { return right < left; }
inline bool operator<=(hstring const & left, std::wstring const & right) noexcept { return !(right < left); }
inline bool operator>=(hstring const & left, std::wstring const & right) noexcept { return !(left < right); }

inline bool operator!=(std::wstring const & left, hstring const & right) noexcept { return !(left == right); }
inline bool operator >(std::wstring const & left, hstring const & right) noexcept { return right < left; }
inline bool operator<=(std::wstring const & left, hstring const & right) noexcept { return !(right < left); }
inline bool operator>=(std::wstring const & left, hstring const & right) noexcept { return !(left < right); }

// TODO: this must be removed. The ABI projection should just use HSTRING directly.
namespace ABI { using hstring = HSTRING; }

}
