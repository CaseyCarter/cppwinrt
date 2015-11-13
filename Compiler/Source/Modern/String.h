
namespace Modern { namespace Internal {

struct StringTraits : HandleTraits<HSTRING>
{
	static void Close(Type value) noexcept
	{
		MODERN_VERIFY_(S_OK, WindowsDeleteString(value));
	}
};

struct StringBufferTraits : HandleTraits<HSTRING_BUFFER>
{
	static void Close(Type value) noexcept
	{
		MODERN_VERIFY_(S_OK, WindowsDeleteStringBuffer(value));
	}
};

}}

namespace Modern {

class StringReference
{
public:

	StringReference(StringReference const &) = delete;
	StringReference & operator=(StringReference const &) = delete;

	StringReference(wchar_t const * const value, unsigned length)
	{
		Check(WindowsCreateStringReference(value, length, &m_header, &m_string));
	}

	template <unsigned Count>
	StringReference(wchar_t const (&value)[Count]) :
		StringReference(value, Count - 1)
	{
	}

	HSTRING Get() const noexcept
	{
		return m_string;
	}

private:

	HSTRING_HEADER m_header;
	HSTRING m_string;
};

class String
{
public:

	String() noexcept = default;
	String(String && other) noexcept = default;
	String & operator=(String && other) noexcept = default;

	String(wchar_t const * value, unsigned const length) :
		m_string(InternalCreate(value, length))
	{}

	template <unsigned Count>
	String(wchar_t const (&value)[Count]) :
		String(value, Count - 1)
	{}

	String(wchar_t const * value) :
		String(value, static_cast<unsigned>(wcslen(value)))
	{}

	String(String const & other) :
		m_string(InternalDuplicate(Get(other)))
	{}

	String & operator=(String const & other) noexcept
	{
		m_string.Reset(InternalDuplicate(Get(other)));
		return *this;
	}

	void Swap(String & other) noexcept
	{
		m_string.Swap(other.m_string);
	}

	void Clear() noexcept
	{
		m_string.Reset();
	}

	wchar_t const * Buffer() const noexcept
	{
		return WindowsGetStringRawBuffer(m_string.Get(), nullptr);
	}

	wchar_t const * Buffer(unsigned & length) const noexcept
	{
		return WindowsGetStringRawBuffer(m_string.Get(), &length);
	}

	unsigned Length() const noexcept
	{
		return WindowsGetStringLen(m_string.Get());
	}

	bool Empty() const noexcept
	{
		return 0 != WindowsIsStringEmpty(m_string.Get());
	}

	bool HasEmbeddedNull() const
	{
		BOOL result = 0;
		Check(WindowsStringHasEmbeddedNull(m_string.Get(), &result));
		return 0 != result;
	}

	String Substring(unsigned const startIndex)
	{
		String result;
		Check(WindowsSubstring(m_string.Get(), startIndex, Set(result)));
		return result;
	}

	String Substring(unsigned const startIndex, unsigned const length)
	{
		String result;
		Check(WindowsSubstringWithSpecifiedLength(m_string.Get(), startIndex, length, Set(result)));
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

	template <typename ... Args>
	static String Format(wchar_t const * format, Args ... args)
	{
		int const size = swprintf(nullptr, 0, format, Internal::FormatArgument(args) ...);

		if (-1 == size)
		{
			throw Exception(E_INVALIDARG);
		}

		if (0 == size)
		{
			return String();
		}

		Handle<Internal::StringBufferTraits> buffer;
		wchar_t * target = nullptr;

		Check(WindowsPreallocateStringBuffer(size, &target, buffer.Set()));
		swprintf(target, size + 1, format, Internal::FormatArgument(args) ...);

		String result;
		Check(WindowsPromoteStringBuffer(buffer.Get(), result.Set()));

		buffer.Detach();
		return result;
	}

private:

	static HSTRING InternalDuplicate(HSTRING other)
	{
        HSTRING result = nullptr;
		Check(WindowsDuplicateString(other, &result));
		return result;
	}

	static HSTRING InternalCreate(wchar_t const * value, unsigned const length)
	{
        HSTRING result = nullptr;
		Check(WindowsCreateString(value, length, &result));
		return result;
	}

	friend HSTRING Get(String const & string) noexcept
	{
		return string.m_string.Get();
	}

	friend HSTRING * Set(String & string) noexcept
	{
		return string.m_string.Set();
	}

	friend void Attach(String & string, HSTRING handle) noexcept
	{
		string.m_string.Reset(handle);
	}

	friend void Copy(String & string, HSTRING handle) noexcept
	{
		string.m_string.Reset(InternalDuplicate(handle));
	}

	friend HSTRING Detach(String & string) noexcept
	{
		return string.m_string.Detach();
	}

	Handle<Internal::StringTraits> m_string;
};

inline void swap(String & left, String & right) noexcept
{
	left.Swap(right);
}
inline bool operator==(String const & left, String const & right) noexcept
{
	return left.Compare(right) == 0;
}
inline bool operator!=(String const & left, String const & right) noexcept
{
	return !(left == right);
}
inline bool operator<(String const & left, String const & right) noexcept
{
	return left.Compare(right) < 0;
}
inline bool operator>(String const & left, String const & right) noexcept
{
	return right < left;
}
inline bool operator<=(String const & left, String const & right) noexcept
{
	return !(right < left);
}
inline bool operator>=(String const & left, String const & right) noexcept
{
	return !(left < right);
}
inline bool operator<(wchar_t const * left, String const & right) noexcept
{
	return right.Compare(left) > 0;
}
inline bool operator==(String const & left, wchar_t const * right) noexcept
{
	return left.Compare(right) == 0;
}
inline bool operator!=(String const & left, wchar_t const * right) noexcept
{
	return !(left == right);
}
inline bool operator<(String const & left, wchar_t const * right) noexcept
{
	return left.Compare(right) < 0;
}
inline bool operator>(String const & left, wchar_t const * right) noexcept
{
	return right < left;
}
inline bool operator<=(String const & left, wchar_t const * right) noexcept
{
	return !(right < left);
}
inline bool operator>=(String const & left, wchar_t const * right) noexcept
{
	return !(left < right);
}
inline bool operator==(wchar_t const * left, String const & right) noexcept
{
	return right.Compare(left) == 0;
}
inline bool operator!=(wchar_t const * left, String const & right) noexcept
{
	return !(left == right);
}
inline bool operator>(wchar_t const * left, String const & right) noexcept
{
	return right < left;
}
inline bool operator<=(wchar_t const * left, String const & right) noexcept
{
	return !(right < left);
}
inline bool operator>=(wchar_t const * left, String const & right) noexcept
{
	return !(left < right);
}

}

namespace Modern { namespace Internal {

inline String StringConcat(HSTRING left, HSTRING right)
{
	String result;
	Check(WindowsConcatString(left, right, Set(result)));
	return result;
}

}}

namespace Modern {

inline String operator+(String const & left, String const & right)
{
	return Internal::StringConcat(Get(left), Get(right));
}
template <unsigned Count>
String operator+(String const & left, wchar_t const (&right)[Count])
{
	return Internal::StringConcat(Get(left), StringReference(right).Get());
}
template <unsigned Count>
String operator+(wchar_t const (&left)[Count], String const & right)
{
	return Internal::StringConcat(StringReference(left).Get(), Get(right));
}

}