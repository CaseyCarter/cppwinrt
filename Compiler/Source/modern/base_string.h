
namespace winrt { namespace impl {

struct string_traits : handle_traits<HSTRING>
{
	static void close(type value) noexcept
	{
		WINRT_VERIFY_(S_OK, WindowsDeleteString(value));
	}
};

struct string_buffer_traits : handle_traits<HSTRING_BUFFER>
{
	static void close(type value) noexcept
	{
		WINRT_VERIFY_(S_OK, WindowsDeleteStringBuffer(value));
	}
};

}}

namespace winrt {

struct String
{
	String() noexcept = default;
	String(String && other) noexcept = default;
	String & operator=(String && other) noexcept = default;

	String(std::nullptr_t) noexcept {}

	String(wchar_t const * value, unsigned const length) :
		m_handle(create_string(value, length))
	{}

	template <unsigned Count>
	String(wchar_t const (&value)[Count]) :
		String(value, Count - 1)
	{}

	String(wchar_t const * const value) :
		String(value, static_cast<unsigned>(wcslen(value)))
	{}

	String(String const & other) :
		m_handle(duplicate_string(get(other.m_handle)))
	{}

	String & operator=(String const & other) noexcept
	{
		attach(m_handle, duplicate_string(get(other.m_handle)));
		return *this;
	}

	String & operator=(std::nullptr_t) noexcept
	{
		m_handle.close();
		return *this;
	}

	wchar_t const * Buffer() const noexcept
	{
		return WindowsGetStringRawBuffer(get(m_handle), nullptr);
	}

	wchar_t const * Buffer(unsigned & length) const noexcept
	{
		return WindowsGetStringRawBuffer(get(m_handle), &length);
	}

	unsigned Length() const noexcept
	{
		return WindowsGetStringLen(get(m_handle));
	}

	bool Empty() const noexcept
	{
		return 0 != WindowsIsStringEmpty(get(m_handle));
	}

	bool EmbeddedNull() const
	{
		BOOL result = 0;
		check(WindowsStringHasEmbeddedNull(get(m_handle), &result));
		return 0 != result;
	}

	String Substring(unsigned const startIndex)
	{
		String result;
		check(WindowsSubstring(get(m_handle), startIndex, put(result.m_handle)));
		return result;
	}

	String Substring(unsigned const startIndex, unsigned const length)
	{
		String result;
		check(WindowsSubstringWithSpecifiedLength(get(m_handle), startIndex, length, put(result.m_handle)));
		return result;
	}

	int Compare(wchar_t const * other) const noexcept
	{
		return wcscmp(Buffer(), other);
	}

	int Compare(String const & other) const noexcept
	{
		return Compare(other.Buffer());
	}

	friend HSTRING impl_get(String const & string) noexcept
	{
		return get(string.m_handle);
	}

	friend HSTRING * impl_put(String & string) noexcept
	{
		return put(string.m_handle);
	}

	friend HSTRING impl_detach(String & string) noexcept
	{
		return detach(string.m_handle);
	}

	friend void swap(String & left, String & right) noexcept
	{
		std::swap(left.m_handle, right.m_handle);
	}

	operator std::wstring() const
	{
		return std::wstring(Buffer(), Length());
	}

private:

	static HSTRING duplicate_string(HSTRING other)
	{
		HSTRING result = nullptr;
		check(WindowsDuplicateString(other, &result));
		return result;
	}

	static HSTRING create_string(wchar_t const * value, unsigned const length)
	{
		HSTRING result = nullptr;
		check(WindowsCreateString(value, length, &result));
		return result;
	}

	handle<impl::string_traits> m_handle;
};

}

namespace winrt { namespace impl {

template <>
struct accessors<String>
{
	static HSTRING get(String const & object) noexcept
	{
		return impl_get(object);
	}

	static HSTRING * put(String & object) noexcept
	{
		return impl_put(object);
	}

	static void attach(String & object, HSTRING value) noexcept
	{
		object = nullptr;
		*put(object) = value;
	}

	static void copy_from(String & object, HSTRING value)
	{
		object = nullptr;
		check(WindowsDuplicateString(value, put(object)));
	}

    static void copy_to(String const & object, HSTRING & value)
    {
        check(WindowsDuplicateString(get(object), &value));
    }

	static HSTRING detach(String & object) noexcept
	{
		return impl_detach(object);
	}
};

}}

namespace winrt {

inline bool operator==(String const & left, String const & right)
{
	int result = 0;
	check(WindowsCompareStringOrdinal(get(left), get(right), &result));
	return result == 0;
}

inline bool operator!=(String const & left, String const & right)
{
	return !(left == right);
}

inline bool operator<(String const & left, String const & right)
{
	int result = 0;
	check(WindowsCompareStringOrdinal(get(left), get(right), &result));
	return result == -1;
}

inline bool operator>(String const & left, String const & right)
{
	return right < left;
}

inline bool operator<=(String const & left, String const & right)
{
	return !(right < left);
}

inline bool operator>=(String const & left, String const & right)
{
	return !(left < right);
}

struct StringReference
{
	StringReference(StringReference const &) = delete;
	StringReference & operator=(StringReference const &) = delete;

	StringReference(wchar_t const * const value, size_t const length)
	{
		check(WindowsCreateStringReference(value, static_cast<unsigned>(length), &m_header, &m_handle));
	}

	StringReference(wchar_t const * const value) :
		StringReference(value, wcslen(value))
	{}

	StringReference(String const & value) noexcept :
		m_handle(get(value))
	{}

	StringReference(std::wstring const & value) :
		StringReference(value.c_str(), value.size())
	{}

	friend HSTRING impl_get(StringReference const & string) noexcept
	{
		return string.m_handle;
	}

private:

	HSTRING_HEADER m_header;
	HSTRING m_handle;
};

}

namespace winrt { namespace impl {

template <> struct traits<String>
{
	using abi = HSTRING;
};

template <>
struct accessors<StringReference>
{
	static HSTRING get(StringReference const & object) noexcept
	{
		return impl_get(object);
	}
};

}}

namespace winrt { namespace ABI {

using String = HSTRING;

}}
