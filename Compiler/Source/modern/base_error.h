
namespace winrt {

namespace impl {

struct format_traits : handle_traits<char *>
{
	static void close(type value) noexcept
	{
		WINRT_VERIFY(HeapFree(GetProcessHeap(), 0, value));
	}
};

struct bstr_traits : handle_traits<BSTR>
{
	static void close(type value) noexcept
	{
		SysFreeString(value);
	}
};

template <>
struct accessors<handle<bstr_traits>>
{
	static wchar_t const * get(handle<bstr_traits> const & object) noexcept
	{
		if (object)
		{
			return impl_get(object);
		}
		else
		{
			return L"";
		}
	}

	static BSTR * put(handle<bstr_traits> & object) noexcept
	{
		return impl_put(object);
	}
};

inline void trim_error(std::string & message) noexcept
{
	while (!message.empty() && (isspace(message.back()) || '.' == message.back()))
	{
		message.resize(message.size() - 1);
	}
}

inline std::string format_message(HRESULT const result)
{
	handle<format_traits> buffer;
	std::string message;

	if (FormatMessageA(0x00000100 | FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_IGNORE_INSERTS,
					   nullptr,
					   result,
					   MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),
					   reinterpret_cast<char *>(put(buffer)),
					   0,
					   nullptr))
	{
		message = get(buffer);
		trim_error(message);
	}

	return message;
}

inline std::string restricted_message(HRESULT const result)
{
	com_ptr<IRestrictedErrorInfo> info;

	if (S_OK == GetRestrictedErrorInfo(put(info)))
	{
		handle<bstr_traits> description;
		handle<bstr_traits> unused1;
		handle<bstr_traits> unused2;
		HRESULT unused3 = S_OK;

		if (S_OK == info->GetErrorDetails(put(unused1), &unused3, put(description), put(unused2)))
		{
			std::wstring_convert<std::codecvt_utf8<wchar_t>> convert;
			std::string message = convert.to_bytes(get(description));
			trim_error(message);
			return message;
		}
	}

	return format_message(result);
}

struct hresult_category : std::error_category
{
	char const * name() const noexcept override
	{
		return "HRESULT";
	}

	std::string message(int code) const override
	{
		return restricted_message(code);
	}
};

struct error_info
{
	error_info() = default;

	error_info(HRESULT const value, wchar_t const * const message, size_t const size) noexcept
	{
		RoOriginateErrorW(value, static_cast<unsigned>(size), message);
	}
};

}

inline impl::hresult_category const & hresult_category() noexcept
{
	static impl::hresult_category category;
	return category;
}

struct hresult_error :
	impl::error_info,
	std::system_error
{
	explicit hresult_error(HRESULT const value) : 
		std::system_error(value, hresult_category())
	{}

	hresult_error(HRESULT const value, wchar_t const * const message) : 
		impl::error_info(value, message, wcslen(message)), 
		std::system_error(value, hresult_category())
	{}

	hresult_error(HRESULT const value, std::wstring const & message) : 
		impl::error_info(value, message.c_str(), message.size()), 
		std::system_error(value, hresult_category())
	{}
};

namespace impl {

inline __declspec(noinline) void throw_hresult(HRESULT const result)
{
	if (result == E_OUTOFMEMORY)
	{
		throw std::bad_alloc();
	}

	if (result == E_BOUNDS)
	{
		throw std::out_of_range("");
	}

	throw hresult_error(result);
}

inline __declspec(noinline) HRESULT to_hresult() noexcept
{
	try
	{
		throw;
	}
	catch (hresult_error const & e)
	{
		return e.code().value();
	}
	catch (std::bad_alloc const &)
	{
		return E_OUTOFMEMORY;
	}
	catch (std::out_of_range const &)
	{
		return E_BOUNDS;
	}
	catch (std::exception const &)
	{
		return E_FAIL;
	}
}

}

__forceinline void check_hresult(HRESULT const result)
{
	if (result != S_OK)
	{
		impl::throw_hresult(result);
	}
}

}
