// C++ for the Windows Runtime v1.29 - http://moderncpp.com
// Copyright (c) 2016 Microsoft Corporation

#pragma comment(lib, "runtimeobject")
#pragma comment(lib, "ole32")

#include <inspectable.h>
#include <winstring.h>
#include <ctxtcall.h>
#include <restrictederrorinfo.h>

#include <set>
#include <memory>
#include <vector>
#include <utility>
#include <type_traits>
#include <locale>
#include <codecvt>

extern "C"
{
	enum RO_INIT_TYPE;

	BOOL __stdcall RoOriginateErrorW(HRESULT error, unsigned length, wchar_t const * message);
	HRESULT __stdcall GetRestrictedErrorInfo(IRestrictedErrorInfo ** info);
	HRESULT __stdcall RoInitialize(RO_INIT_TYPE type);
	void __stdcall RoUninitialize();
	HRESULT __stdcall RoGetActivationFactory(HSTRING classId, GUID const & iid, void ** factory);
	HRESULT __stdcall RoActivateInstance(HSTRING classId, ::IInspectable ** instance);
}

#ifdef _DEBUG

#include <crtdbg.h>

#define WINRT_ASSERT _ASSERTE
#define WINRT_VERIFY WINRT_ASSERT
#define WINRT_VERIFY_(result, expression) WINRT_ASSERT(result == expression)

template <typename ... Args>
void WINRT_TRACE(char const * const message, Args ... args) noexcept
{
	char buffer[1024] = {};
	sprintf_s(buffer, message, args ...);
	OutputDebugStringA(buffer);
}

#else

#define WINRT_ASSERT __noop
#define WINRT_VERIFY(expression) (expression)
#define WINRT_VERIFY_(result, expression) (expression)
#define WINRT_TRACE __noop

#endif

namespace winrt {

namespace impl {

template <typename T, typename Enable = void>
struct accessors
{
	static T get(T const & object) noexcept
	{
		return object;
	}

	static T * put(T & object) noexcept
	{
		return &object;
	}

	static void attach(T & object, T const & value) noexcept
	{
		object = value;
	}

	static void copy_from(T & object, T const & value) noexcept
	{
		object = value;
	}

	static void copy_to(T const & object, T & value) noexcept
	{
		value = object;
	}

	static T detach(T & object) noexcept
	{
		return object;
	}

	static T const & lease(T const & object) noexcept
	{
		return object;
	}
};

struct bool_proxy
{
	bool_proxy & operator=(bool_proxy const &) = delete;

	bool_proxy(bool & value) noexcept :
		m_value(value)
	{}

	~bool_proxy() noexcept
	{
		m_value = false != m_value;
	}

	operator bool * () noexcept
	{
		return &m_value;
	}

private:

	bool & m_value;
};

template <>
struct accessors<bool>
{
	static bool_proxy put(bool & object) noexcept
	{
		return bool_proxy(object);
	}

	static bool detach(bool object) noexcept
	{
		return object;
	}
};

}

template <typename T>
auto get(T const & object) noexcept
{
	return impl::accessors<T>::get(object);
}

template <typename T>
auto put(T & object) noexcept
{
	return impl::accessors<T>::put(object);
}

template <typename T>
auto put_size(T & object) noexcept
{
	return impl::accessors<T>::put_size(object);
}

template <typename T, typename V>
void attach(T & object, V && value) noexcept
{
	impl::accessors<T>::attach(object, value);
}

template <typename T, typename V>
void copy_from(T & object, V && value)
{
	impl::accessors<T>::copy_from(object, value);
}

template <typename T, typename V>
void copy_to(T const & object, V & value)
{
	impl::accessors<T>::copy_to(object, value);
}

template <typename T>
auto detach(T & object)
{
	return impl::accessors<std::decay_t<T>>::detach(object);
}

template <typename T>
auto detach(T && object)
{
	return impl::accessors<T>::detach(object);
}

template <typename T, typename V>
auto lease(V && object) noexcept
{
	return impl::accessors<T>::lease(object);
}

}

namespace winrt {

namespace impl {

template <typename T>
class no_ref : public T
{
	unsigned long __stdcall AddRef();
	unsigned long __stdcall Release();
};

}

template <typename T>
struct com_ptr
{
	using type = T;

	com_ptr() noexcept = default;

	com_ptr(com_ptr const & other) noexcept :
		m_ptr(other.m_ptr)
	{
		impl_addref();
	}

	template <typename T>
	com_ptr(com_ptr<T> const & other) noexcept :
		m_ptr(other.m_ptr)
	{
		impl_addref();
	}

	template <typename T>
	com_ptr(com_ptr<T> && other) noexcept :
		m_ptr(other.m_ptr)
	{
		other.m_ptr = nullptr;
	}

	~com_ptr() noexcept
	{
		impl_release();
	}

	com_ptr & operator=(com_ptr const & other) noexcept
	{
		impl_copy(other.m_ptr);
		return *this;
	}

	template <typename T>
	com_ptr & operator=(com_ptr<T> const & other) noexcept
	{
		impl_copy(other.m_ptr);
		return *this;
	}

	template <typename T>
	com_ptr & operator=(com_ptr<T> && other) noexcept
	{
		impl_move(other);
		return *this;
	}

	explicit operator bool() const noexcept
	{
		return nullptr != m_ptr;
	}

	impl::no_ref<T> * operator->() const noexcept
	{
		return static_cast<impl::no_ref<T> *>(m_ptr);
	}

	friend T * impl_get(com_ptr const & object) noexcept
	{
		return object.m_ptr;
	}

	friend T ** impl_put(com_ptr & object) noexcept
	{
		WINRT_ASSERT(object.m_ptr == nullptr);
		return &object.m_ptr;
	}

	friend T * impl_detach(com_ptr & object) noexcept
	{
		T * temp = object.m_ptr;
		object.m_ptr = nullptr;
		return temp;
	}

	friend void swap(com_ptr & left, com_ptr & right) noexcept
	{
		std::swap(left.m_ptr, right.m_ptr);
	}

	com_ptr & operator=(std::nullptr_t) noexcept
	{
		impl_release();
		return *this;
	}

	template <typename T>
	com_ptr<T> as() const noexcept
	{
		com_ptr<T> temp;
		m_ptr->QueryInterface(put(temp));
		return temp;
	}

	void copy_from(T * other) noexcept
	{
		impl_copy(other);
	}

	void copy_to(T ** other) const noexcept
	{
		impl_addref();
		*other = m_ptr;
	}

private:

	void impl_copy(T * other) noexcept
	{
		if (m_ptr != other)
		{
			impl_release();
			m_ptr = other;
			impl_addref();
		}
	}

	template <typename T>
	void impl_move(com_ptr<T> & other) noexcept
	{
		if (m_ptr != other.m_ptr)
		{
			impl_release();
			m_ptr = other.m_ptr;
			other.m_ptr = nullptr;
		}
	}

	void impl_addref() const noexcept
	{
		if (m_ptr)
		{
			m_ptr->AddRef();
		}
	}

	void impl_release() noexcept
	{
		T * temp = m_ptr;

		if (temp)
		{
			m_ptr = nullptr;
			temp->Release();
		}
	}

	template <typename T>
	friend struct com_ptr;

	T * m_ptr = nullptr;
};

}

namespace winrt { namespace impl {

template <typename T>
struct accessors<com_ptr<T>>
{
	static T * get(com_ptr<T> const & object) noexcept
	{
		return impl_get(object);
	}

	static T ** put(com_ptr<T> & object) noexcept
	{
		return impl_put(object);
	}

	static void attach(com_ptr<T> & object, T * value) noexcept
	{
		object = nullptr;
		*put(object) = value;
	}

	static void copy_from(com_ptr<T> & object, T * value)
	{
		object = nullptr;

		if (value)
		{
			value->AddRef();
			*put(object) = value;
		}
	}

	static void copy_to(com_ptr<T> const & object, T * & value)
	{
		if (object)
		{
			value = get(object);
			value->AddRef();
		}
		else
		{
			value = nullptr;
		}
	}

	static T * detach(com_ptr<T> & object) noexcept
	{
		return impl_detach(object);
	}
};

}}

namespace winrt {

template <typename T>
bool operator==(com_ptr<T> const & left, com_ptr<T> const & right) noexcept
{
	return get(left) == get(right);
}

template <typename T>
bool operator!=(com_ptr<T> const & left, com_ptr<T> const & right) noexcept
{
	return !(left == right);
}

template <typename T>
bool operator<(com_ptr<T> const & left, com_ptr<T> const & right) noexcept
{
	return get(left) < get(right);
}

template <typename T>
bool operator>(com_ptr<T> const & left, com_ptr<T> const & right) noexcept
{
	return right < left;
}

template <typename T>
bool operator<=(com_ptr<T> const & left, com_ptr<T> const & right) noexcept
{
	return !(right < left);
}

template <typename T>
bool operator>=(com_ptr<T> const & left, com_ptr<T> const & right) noexcept
{
	return !(left < right);
}

}

namespace winrt {

template <typename T>
struct handle_traits
{
	using type = T;

	constexpr static type invalid() noexcept
	{
		return nullptr;
	}

	// static void close(type value) noexcept;
};

template <typename T>
struct handle
{
	using type = typename T::type;

	handle() noexcept = default;

	handle(type value) noexcept :
		m_value(value)
	{}

	handle(handle && other) noexcept :
		m_value(detach(other))
	{}

	handle & operator=(handle && other) noexcept
	{
		if (this != &other)
		{
			attach(*this, detach(other));
		}

		return *this;
	}

	~handle() noexcept
	{
		close();
	}

	void close() noexcept
	{
		if (*this)
		{
			T::close(m_value);
			m_value = T::invalid();
		}
	}

	explicit operator bool() const noexcept
	{
		return m_value != T::invalid();
	}

	friend type impl_get(handle const & handle) noexcept
	{
		return handle.m_value;
	}

	friend type * impl_put(handle & handle) noexcept
	{
		WINRT_ASSERT(!handle);
		return &handle.m_value;
	}

	friend type impl_detach(handle & handle) noexcept
	{
		type value = handle.m_value;
		handle.m_value = T::invalid();
		return value;
	}

	friend void swap(handle & left, handle & right) noexcept
	{
		std::swap(left, right);
	}

private:

	type m_value = T::invalid();
};

template <typename T>
bool operator==(handle<T> const & left, handle<T> const & right) noexcept
{
	return get(left) == get(right);
}

template <typename T>
bool operator!=(handle<T> const & left, handle<T> const & right) noexcept
{
	return !(left == right);
}

template <typename T>
bool operator<(handle<T> const & left, handle<T> const & right) noexcept
{
	return get(left) < get(right);
}

template <typename T>
bool operator>(handle<T> const & left, handle<T> const & right) noexcept
{
	return right < left;
}

template <typename T>
bool operator<=(handle<T> const & left, handle<T> const & right) noexcept
{
	return !(right < left);
}

template <typename T>
bool operator>=(handle<T> const & left, handle<T> const & right) noexcept
{
	return !(left < right);
}

}

namespace winrt { namespace impl {

template <typename T>
struct accessors<handle<T>>
{
	using type = typename handle<T>::type;

	static type get(handle<T> const & object) noexcept
	{
		return impl_get(object);
	}

	static type * put(handle<T> & object) noexcept
	{
		return impl_put(object);
	}

	static void attach(handle<T> & object, type value) noexcept
	{
		object.close();
		*put(object) = value;
	}

	static type detach(handle<T> & object) noexcept
	{
		return impl_detach(object);
	}
};

}}

#ifndef FORMAT_MESSAGE_ALLOCATE_BUFFER
#define FORMAT_MESSAGE_ALLOCATE_BUFFER 0x00000100
#endif

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

inline void trim_trailing_whitespace(std::string & message) noexcept
{
	while (!message.empty() && (isspace(message.back())))
	{
		message.resize(message.size() - 1);
	}
}

inline std::string format_message(HRESULT const result)
{
	handle<format_traits> buffer;
	std::string message;

	if (FormatMessageA(FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_IGNORE_INSERTS,
					   nullptr,
					   result,
					   MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),
					   reinterpret_cast<char *>(put(buffer)),
					   0,
					   nullptr))
	{
		message = get(buffer);
		trim_trailing_whitespace(message);
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
			trim_trailing_whitespace(message);
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
	if (E_OUTOFMEMORY == result)
	{
		throw std::bad_alloc();
	}

	if (E_BOUNDS == result)
	{
		throw std::out_of_range("");
	}

	if (E_INVALIDARG == result)
	{
		throw std::invalid_argument("");
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
	catch (std::invalid_argument const &)
	{
		return E_INVALIDARG;
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

namespace winrt {

template <typename ... Interfaces>
class __declspec(novtable) implements : public Interfaces ...
{
	template <typename T>
	using is_cloaked = std::integral_constant<bool, !std::is_base_of<::IInspectable, typename T>::value>;

	template <int = 0>
	constexpr unsigned count_interfaces() const noexcept
	{
		return 0;
	}

	template <typename First, typename ... Rest>
	constexpr unsigned count_interfaces() const noexcept
	{
		return !is_cloaked<First>::value + count_interfaces<Rest ...>();
	}

	template <int = 0>
	constexpr bool inspectable() const noexcept
	{
		return false;
	}

	template <typename First, typename ... Rest>
	constexpr bool inspectable() const noexcept
	{
		return std::is_base_of<::IInspectable, First>::value || inspectable<Rest ...>();
	}

	template <int = 0>
	void * find_inspectable() noexcept
	{
		return nullptr;
	}

	template <typename First, typename ... Rest>
	void * find_inspectable() noexcept
	{
		#pragma warning(push)
		#pragma warning(disable:4127) // conditional expression is constant

		if (std::is_base_of<::IInspectable, First>::value)
		{
			return static_cast<First *>(this);
		}

		#pragma warning(pop)

		return find_inspectable<Rest ...>();
	}

	template <int = 0>
	void copy_interfaces(GUID *) const noexcept {}

	template <typename First, typename ... Rest>
	void copy_interfaces(GUID * ids) const noexcept
	{
		#pragma warning(push)
		#pragma warning(disable:4127) // conditional expression is constant

		if (!is_cloaked<First>::value)
		{
			*ids++ = __uuidof(First);
		}

		#pragma warning(pop)

		copy_interfaces<Rest ...>(ids);
	}

	template <int = 0>
	void * find_interface(GUID const &) noexcept
	{
		return nullptr;
	}

	template <typename First, typename ... Rest>
	void * find_interface(GUID const & id) noexcept
	{
		if (id == __uuidof(First))
		{
			return static_cast<First *>(this);
		}

		return find_interface<Rest ...>(id);
	}

protected:

	unsigned long m_references = 1;

	implements() noexcept = default;

	virtual ~implements() noexcept
	{}

	template <typename First, typename ... Rest>
	void * query_interface(GUID const & id) noexcept
	{
		if (id == __uuidof(First) || id == __uuidof(::IUnknown))
		{
			return static_cast<First *>(this);
		}

		if (inspectable<Interfaces ...>() && id == __uuidof(::IInspectable))
		{
			return find_inspectable<Interfaces ...>();
		}

		return find_interface<Rest ...>(id);
	}

public:

	implements(implements const &) = delete;
	implements & operator=(implements const &) = delete;

	virtual HRESULT __stdcall QueryInterface(GUID const & id, void ** object) noexcept override
	{
		*object = query_interface<Interfaces ...>(id);

		if (nullptr == *object)
		{
			return E_NOINTERFACE;
		}

		static_cast<::IUnknown *>(*object)->AddRef();
		return S_OK;
	}

	virtual unsigned long __stdcall AddRef() noexcept override
	{
		return InterlockedIncrement(&m_references);
	}

	virtual unsigned long __stdcall Release() noexcept override
	{
		unsigned long const remaining = InterlockedDecrement(&m_references);

		if (0 == remaining)
		{
			delete this;
		}

		return remaining;
	}

	HRESULT __stdcall GetIids(unsigned long * count, GUID ** array) noexcept
	{
		*count = 0;
		*array = nullptr;

		unsigned const localCount = count_interfaces<Interfaces ...>();

		if (0 == localCount)
		{
			return S_OK;
		}

		GUID * localArray = static_cast<GUID *>(CoTaskMemAlloc(sizeof(GUID) * localCount));

		if (nullptr == localArray)
		{
			return E_OUTOFMEMORY;
		}

		copy_interfaces<Interfaces ...>(localArray);

		*count = localCount;
		*array = localArray;
		return S_OK;
	}

	HRESULT __stdcall GetRuntimeClassName(HSTRING * name) noexcept
	{
		*name = nullptr;
		return E_NOTIMPL;
	}

	HRESULT __stdcall GetTrustLevel(TrustLevel * trustLevel) noexcept
	{
		*trustLevel = BaseTrust;
		return S_OK;
	}
};

}

namespace winrt { namespace ABI {

template <typename T>
struct traits
{
	using default_interface = T;
};

template <typename T>
using default_interface = typename traits<T>::default_interface;

template <typename T, typename Enable = void>
struct arg
{
	using in = T;
	using out = T *;
};

template <typename T>
struct arg<T, typename std::enable_if<std::is_base_of<::IUnknown, T>::value>::type>
{
	using in = T *;
	using out = T **;
};

template <typename T>
using arg_in = typename arg<default_interface<T>>::in;

template <typename T>
using arg_out = typename arg<default_interface<T>>::out;

}}

namespace winrt { namespace impl {

template <typename T>
struct traits
{
	using abi = T;
};

template <typename T>
class has_GetAt
{
	template <typename U, typename = decltype(std::declval<U>().GetAt(0))> static constexpr bool check(int) { return true; }
	template <typename> static constexpr bool check(...) { return false; }

public:

	static constexpr bool value = check<T>(0);
};

template <typename T>
class has_composable
{
	template <typename U> static constexpr bool check(typename U::composable *) { return true; }
	template <typename>   static constexpr bool check(...) { return false; }

public:

	static constexpr bool value = check<T>(nullptr);
};

template <typename Crtp, typename Qi, typename Base>
auto shim(Base const * base)
{
	return get(static_cast<Qi const &>(static_cast<Crtp const &>(*base)));
}

template <typename T, typename R>
struct requires : traits<R>::template methods<requires<T, R>>
{
	operator R() const noexcept
	{
		return static_cast<T const *>(this)->template As<R>();
	}
};

template <typename T, typename B>
struct bases
{
	operator B() const noexcept
	{
		return static_cast<T const *>(this)->As<B>();
	}
};

}}

namespace winrt {

template <typename T>
using abi = typename impl::traits<T>::abi;

template <typename T>
using abi_arg_in = ABI::arg_in<abi<T>>;

template <typename T>
using abi_arg_out = ABI::arg_out<abi<T>>;

template <typename T>
auto ptr(::IUnknown * object) noexcept
{
	return static_cast<impl::no_ref<abi<T>> *>(object);
}

template <typename T, typename ... R>
struct requires : impl::requires<T, R> ...
{};

template <typename T, typename ... B>
struct bases : impl::bases<T, B> ...
{};

namespace impl {

template <typename First, typename ... Rest>
struct implements : winrt::implements<abi<First>, abi<Rest> ..., ::IAgileObject>
{
	using default_interface = First;
};

}}

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

inline bool operator==(hstring_ref left, hstring_ref right)
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

inline bool operator==(hstring const & left, hstring const & right)
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

inline bool operator<(hstring_ref left, hstring_ref right)
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

inline bool operator<(hstring const & left, hstring const & right)
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

inline bool operator!=(hstring_ref left, hstring_ref right) { return !(left == right); }
inline bool operator >(hstring_ref left, hstring_ref right) { return right < left; }
inline bool operator<=(hstring_ref left, hstring_ref right) { return !(right < left); }
inline bool operator>=(hstring_ref left, hstring_ref right) { return !(left < right); }

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

namespace winrt {

struct lock
{
	lock(lock const &) = delete;
	lock & operator=(lock const &) = delete;

	lock() noexcept
	{
		InitializeSRWLock(&m_lock);
	}

	void enter() noexcept
	{
		AcquireSRWLockExclusive(&m_lock);
	}

	bool try_enter() noexcept
	{
		return 0 != TryAcquireSRWLockExclusive(&m_lock);
	}

	void exit() noexcept
	{
		ReleaseSRWLockExclusive(&m_lock);
	}

private:

	SRWLOCK m_lock;
};

struct lock_guard
{
	lock_guard(lock_guard const &) = delete;
	lock_guard & operator=(lock_guard const &) = delete;

	explicit lock_guard(lock & lock) noexcept :
		m_lock(lock)
	{
		m_lock.enter();
	}

	~lock_guard() noexcept
	{
		m_lock.exit();
	}

private:

	lock & m_lock;
};

}

namespace winrt { namespace Windows {

struct IUnknown
{
	IUnknown() noexcept = default;
	IUnknown(std::nullptr_t) noexcept {}
	void * operator new(size_t) = delete;

	IUnknown(IUnknown const & other) noexcept :
		m_ptr(other.m_ptr)
	{
		impl_addref();
	}

	IUnknown(IUnknown && other) noexcept :
		m_ptr(other.m_ptr)
	{
		other.m_ptr = nullptr;
	}

	~IUnknown() noexcept
	{
		impl_release();
	}

	IUnknown & operator=(IUnknown const & other) noexcept
	{
		impl_copy(other);
		return *this;
	}

	IUnknown & operator=(IUnknown && other) noexcept
	{
		impl_move(std::forward<IUnknown>(other));
		return *this;
	}

	explicit operator bool() const noexcept
	{
		return nullptr != m_ptr;
	}

	impl::no_ref<::IUnknown> * operator->() const noexcept
	{
		return static_cast<impl::no_ref<::IUnknown> *>(m_ptr);
	}

	IUnknown & operator=(std::nullptr_t) noexcept
	{
		impl_release();
		return *this;
	}

	template <typename T>
	T As() const
	{
		T temp = nullptr;
		check_hresult(m_ptr->QueryInterface(put(temp)));
		return temp;
	}

	friend ::IUnknown * impl_get(IUnknown const & object) noexcept
	{
		return object.m_ptr;
	}

	friend ::IUnknown ** impl_put(IUnknown & object) noexcept
	{
		WINRT_ASSERT(!object);
		return &object.m_ptr;
	}

	friend ::IUnknown * impl_detach(IUnknown & object) noexcept
	{
		::IUnknown * temp = object.m_ptr;
		object.m_ptr = nullptr;
		return temp;
	}

	friend void swap(IUnknown & left, IUnknown & right) noexcept
	{
		std::swap(left.m_ptr, right.m_ptr);
	}

protected:

	void impl_copy(::IUnknown * other) noexcept
	{
		if (m_ptr != other)
		{
			impl_release();
			m_ptr = other;
			impl_addref();
		}
	}

	void impl_copy(IUnknown const & other) noexcept
	{
		if (this != &other)
		{
			impl_release();
			m_ptr = other.m_ptr;
			impl_addref();
		}
	}

	void impl_move(IUnknown && other) noexcept
	{
		if (this != &other)
		{
			impl_release();
			m_ptr = other.m_ptr;
			other.m_ptr = nullptr;
		}
	}

	::IUnknown * m_ptr = nullptr;
	
private:

	void impl_addref() const noexcept
	{
		if (m_ptr)
		{
			m_ptr->AddRef();
		}
	}

	void impl_release() noexcept
	{
		::IUnknown * temp = m_ptr;

		if (temp)
		{
			m_ptr = nullptr;
			temp->Release();
		}
	}
};

}}

namespace winrt { namespace impl {

template <> struct traits<Windows::IUnknown>
{
	using abi = ::IUnknown;
};

template <typename To>
struct lease_t : To
{
	template <typename From>
	lease_t(From value) noexcept : To(nullptr)
	{
		*put(*static_cast<To *>(this)) = value;
	}

	~lease_t() noexcept
	{
		detach(*static_cast<To *>(this));
	}
};

template <typename T>
struct accessors<T, typename std::enable_if<std::is_base_of<Windows::IUnknown, T>::value>::type>
{
	static auto get(T const & object) noexcept
	{
		return static_cast<abi_arg_in<T>>(impl_get(object));
	}

	static auto put(T & object) noexcept
	{
		return reinterpret_cast<abi_arg_out<T>>(impl_put(object));
	}

	static void attach(T & object, abi_arg_in<T> value) noexcept
	{
		object = nullptr;
		*put(object) = value;
	}

	static void copy_from(T & object, abi_arg_in<T> value) noexcept
	{
		object = nullptr;

		if (value)
		{
			value->AddRef();
			*put(object) = value;
		}
	}

	template <typename V>
	static void copy_to(T const & object, V & value) noexcept
	{
		if (object)
		{
			value = get(object);
			value->AddRef();
		}
		else
		{
			value = nullptr;
		}
	}

	static auto detach(T & object) noexcept
	{
		return static_cast<abi_arg_in<T>>(impl_detach(object));
	}

	template <typename V>
	static lease_t<T> lease(V value) noexcept
	{
		return lease_t<T>(value);
	}
};

}}

namespace winrt { namespace Windows {

inline bool operator==(IUnknown const & left, IUnknown const & right) noexcept
{
	return get(left) == get(right);
}

inline bool operator!=(IUnknown const & left, IUnknown const & right) noexcept
{
	return !(left == right);
}

inline bool operator<(IUnknown const & left, IUnknown const & right) noexcept
{
	return get(left) < get(right);
}

inline bool operator>(IUnknown const & left, IUnknown const & right) noexcept
{
	return right < left;
}

inline bool operator<=(IUnknown const & left, IUnknown const & right) noexcept
{
	return !(right < left);
}

inline bool operator>=(IUnknown const & left, IUnknown const & right) noexcept
{
	return !(left < right);
}

}}

namespace winrt {

enum class AsyncStatus
{
	Started,
	Completed,
	Canceled,
	Error,
};

}

namespace winrt { namespace ABI { namespace Windows {

struct __declspec(uuid("00000036-0000-0000-c000-000000000046")) __declspec(novtable) IAsyncInfo : ::IInspectable
{
	virtual HRESULT __stdcall get_Id(unsigned * id) = 0;
	virtual HRESULT __stdcall get_Status(AsyncStatus * status) = 0;
	virtual HRESULT __stdcall get_ErrorCode(HRESULT * errorCode) = 0;
	virtual HRESULT __stdcall abi_Cancel() = 0;
	virtual HRESULT __stdcall abi_Close() = 0;
};

struct __declspec(uuid("00000035-0000-0000-c000-000000000046")) __declspec(novtable) IActivationFactory : ::IInspectable
{
	virtual HRESULT __stdcall abi_ActivateInstance(::IInspectable ** instance) = 0;
};

}}}

namespace winrt { namespace Windows {

struct IInspectable;
struct IAsyncInfo;
struct IActivationFactory;

template <typename T>
class impl_IInspectable
{
	auto shim() const { return impl::shim<T, IInspectable>(this); }

public:

	hstring GetRuntimeClassName() const;
};

template <typename T>
class impl_IAsyncInfo
{
	auto shim() const { return impl::shim<T, IAsyncInfo>(this); }

public:

	unsigned Id() const;
	AsyncStatus Status() const;
	HRESULT ErrorCode() const;
	void Cancel() const;
	void Close() const;
};

template <typename T>
class impl_IActivationFactory
{
	auto shim() const { return impl::shim<T, IActivationFactory>(this); }

public:

	IInspectable ActivateInstance() const;
};

}}

namespace winrt { namespace impl {

template <> struct traits<Windows::IInspectable>
{
	using abi = ::IInspectable;
	template <typename T> using methods = Windows::impl_IInspectable<T>;
};

template <> struct traits<Windows::IAsyncInfo>
{
	using abi = ABI::Windows::IAsyncInfo;
	template <typename T> using methods = Windows::impl_IAsyncInfo<T>;
};

template <> struct traits<Windows::IActivationFactory>
{
	using abi = ABI::Windows::IActivationFactory;
	template <typename T> using methods = Windows::impl_IActivationFactory<T>;
};

}}

namespace winrt { namespace Windows {

struct IInspectable :
	IUnknown,
	impl_IInspectable<IInspectable>
{
	IInspectable(std::nullptr_t = nullptr) noexcept {}
	auto operator->() const noexcept { return ptr<IInspectable>(m_ptr); }
};

struct IAsyncInfo :
	IUnknown,
	impl_IAsyncInfo<IAsyncInfo>
{
	IAsyncInfo(std::nullptr_t = nullptr) noexcept {}
	auto operator->() const noexcept { return ptr<IAsyncInfo>(m_ptr); }
};

struct IActivationFactory :
	IUnknown,
	impl_IActivationFactory<IActivationFactory>
{
	IActivationFactory(std::nullptr_t = nullptr) noexcept {}
	auto operator->() const noexcept { return ptr<IActivationFactory>(m_ptr); }
};

template <typename T> hstring impl_IInspectable<T>::GetRuntimeClassName() const
{
	hstring name;
	check_hresult(shim()->get_RuntimeClassName(put(name)));
	return name;
}

template <typename T> unsigned impl_IAsyncInfo<T>::Id() const
{
	unsigned id = 0;
	check_hresult(shim()->get_Id(&id));
	return id;
}

template <typename T> AsyncStatus impl_IAsyncInfo<T>::Status() const
{
	AsyncStatus status = {};
	check_hresult(shim()->get_Status(&status));
	return status;
}

template <typename T> HRESULT impl_IAsyncInfo<T>::ErrorCode() const
{
	HRESULT code = S_OK;
	check_hresult(shim()->get_ErrorCode(&code));
	return code;
}

template <typename T> void impl_IAsyncInfo<T>::Cancel() const
{
	check_hresult(shim()->abi_Cancel());
}

template <typename T> void impl_IAsyncInfo<T>::Close() const
{
	check_hresult(shim()->abi_Close());
}

template <typename T> IInspectable impl_IActivationFactory<T>::ActivateInstance() const
{
	IInspectable instance;
	check_hresult(shim()->abi_ActivateInstance(put(instance)));
	return instance;
}

}

template <typename T, typename As, typename ... Args>
auto make_as(Args && ... args)
{
	As instance;
	*put(instance) = new T(std::forward<Args>(args) ...);
	return instance;
}

template <typename T, typename ... Args, typename std::enable_if<!impl::has_composable<T>::value>::type * = nullptr>
auto make(Args && ... args)
{
	typename T::default_interface instance;
	*put(instance) = new T(std::forward<Args>(args) ...);
	return instance;
}

template <typename T, typename ... Args, typename std::enable_if<impl::has_composable<T>::value>::type * = nullptr>
auto make(Args && ... args)
{
	Windows::IInspectable instance;
	*put(instance) = new T(std::forward<Args>(args) ...);
	return instance.As<T::composable>();
}

template <typename ... R>
struct overrides : implements<R ...>
{
	template <typename T>
	T As() const
	{
		return m_inner.As<T>();
	}

	HRESULT __stdcall QueryInterface(GUID const & id, void ** object) noexcept override
	{
			*object = query_interface<R ...>(id);

		if (*object == nullptr)
		{
			return m_inner->QueryInterface(id, object);
		}

		static_cast<::IUnknown *>(*object)->AddRef();
		return S_OK;
	}

protected:

	Windows::IInspectable m_inner;
};

}

namespace winrt {

namespace impl {

inline void ActivateInstance(HSTRING classId, Windows::IInspectable & instance)
{
	check_hresult(RoActivateInstance(classId, put(instance)));
}

template <typename Interface>
void ActivateInstance(HSTRING classId, Interface & result)
{
	Windows::IInspectable instance;
	ActivateInstance(classId, instance);
	result = instance.As<Interface>();
}

}

enum class InitializeType
{
	SingleThreaded,
	MultiThreaded
};

inline void Initialize(InitializeType const type = InitializeType::MultiThreaded)
{
	check_hresult(RoInitialize(static_cast<RO_INIT_TYPE>(type)));
}

inline void Uninitialize() noexcept
{
	RoUninitialize();
}

template <typename Class, typename Instance = Class>
Instance ActivateInstance()
{
	hstring_ref classId(impl::traits<Class>::name());

	Instance instance = nullptr;
	impl::ActivateInstance(get(classId), instance);
	return instance;
}

template <typename Class, typename Interface = Windows::IActivationFactory>
Interface GetActivationFactory()
{
	hstring_ref classId(impl::traits<Class>::name());

	Interface factory;
	check_hresult(RoGetActivationFactory(get(classId), __uuidof(abi<Interface>), reinterpret_cast<void **>(put(factory))));
	return factory;
}

}

namespace winrt { namespace impl {

template <typename T, typename Enable = void>
struct argument
{
	static constexpr T empty() noexcept
	{
		return{};
	}
};

template <typename T>
struct argument<T, typename std::enable_if<std::is_base_of<Windows::IUnknown, T>::value>::type>
{
	static constexpr T empty() noexcept
	{
		return nullptr;
	}
};

}}

namespace winrt { namespace ABI { namespace Windows { namespace Foundation {

template <typename TProgress> struct IAsyncActionProgressHandler;
template <typename TProgress> struct IAsyncActionWithProgress;
template <typename TProgress> struct IAsyncActionWithProgressCompletedHandler;
template <typename TResult, typename TProgress> struct IAsyncOperationProgressHandler;
template <typename TResult, typename TProgress> struct IAsyncOperationWithProgressCompletedHandler;
template <typename TResult> struct IAsyncOperationCompletedHandler;
template <typename T> struct IEventHandler;
template <typename TSender, typename TArgs> struct ITypedEventHandler;
template <typename TResult> struct IAsyncOperation;
template <typename TResult, typename TProgress> struct IAsyncOperationWithProgress;
template <typename T> struct IReference;

template <typename TProgress>
struct __declspec(novtable) impl_IAsyncActionProgressHandler : IUnknown
{
	virtual HRESULT __stdcall abi_Invoke(IAsyncActionWithProgress<TProgress> * asyncInfo, arg_in<TProgress> progressInfo) = 0;
};

template <typename TProgress>
struct __declspec(novtable) impl_IAsyncActionWithProgress : IInspectable
{
	virtual HRESULT __stdcall put_Progress(IAsyncActionProgressHandler<TProgress> * handler) = 0;
	virtual HRESULT __stdcall get_Progress(IAsyncActionProgressHandler<TProgress> ** handler) = 0;
	virtual HRESULT __stdcall put_Completed(IAsyncActionWithProgressCompletedHandler<TProgress> * handler) = 0;
	virtual HRESULT __stdcall get_Completed(IAsyncActionWithProgressCompletedHandler<TProgress> ** handler) = 0;
	virtual HRESULT __stdcall abi_GetResults() = 0;
};

template <typename TProgress>
struct __declspec(novtable) impl_IAsyncActionWithProgressCompletedHandler : IUnknown
{
	virtual HRESULT __stdcall abi_Invoke(IAsyncActionWithProgress<TProgress> * asyncInfo, AsyncStatus status) = 0;
};

template <typename TResult, typename TProgress>
struct __declspec(novtable) impl_IAsyncOperationProgressHandler : IUnknown
{
	virtual HRESULT __stdcall abi_Invoke(IAsyncOperationWithProgress<TResult, TProgress> * asyncInfo, arg_in<TProgress> progressInfo) = 0;
};

template <typename TResult, typename TProgress>
struct __declspec(novtable) impl_IAsyncOperationWithProgressCompletedHandler : IUnknown
{
	virtual HRESULT __stdcall abi_Invoke(IAsyncOperationWithProgress<TResult, TProgress> * asyncInfo, AsyncStatus status) = 0;
};

template <typename TResult>
struct __declspec(novtable) impl_IAsyncOperationCompletedHandler : IUnknown
{
	virtual HRESULT __stdcall abi_Invoke(IAsyncOperation<TResult> * asyncInfo, AsyncStatus status) = 0;
};

template <typename T>
struct __declspec(novtable) impl_IEventHandler : IUnknown
{
	virtual HRESULT __stdcall abi_Invoke(IInspectable * sender, arg_in<T> args) = 0;
};

template <typename TSender, typename TArgs>
struct __declspec(novtable) impl_ITypedEventHandler : IUnknown
{
	virtual HRESULT __stdcall abi_Invoke(arg_in<TSender> sender, arg_in<TArgs> args) = 0;
};

template <typename TResult>
struct __declspec(novtable) impl_IAsyncOperation : IInspectable
{
	virtual HRESULT __stdcall put_Completed(IAsyncOperationCompletedHandler<TResult> * handler) = 0;
	virtual HRESULT __stdcall get_Completed(IAsyncOperationCompletedHandler<TResult> ** handler) = 0;
	virtual HRESULT __stdcall abi_GetResults(arg_out<TResult> results) = 0;
};

template <typename TResult, typename TProgress>
struct __declspec(novtable) impl_IAsyncOperationWithProgress : IInspectable
{
	virtual HRESULT __stdcall put_Progress(IAsyncOperationProgressHandler<TResult, TProgress> * handler) = 0;
	virtual HRESULT __stdcall get_Progress(IAsyncOperationProgressHandler<TResult, TProgress> ** handler) = 0;
	virtual HRESULT __stdcall put_Completed(IAsyncOperationWithProgressCompletedHandler<TResult, TProgress> * handler) = 0;
	virtual HRESULT __stdcall get_Completed(IAsyncOperationWithProgressCompletedHandler<TResult, TProgress> ** handler) = 0;
	virtual HRESULT __stdcall abi_GetResults(arg_out<TResult> results) = 0;
};

template <typename T>
struct __declspec(novtable) impl_IReference : IInspectable
{
	virtual HRESULT __stdcall get_Value(arg_out<T> value) = 0;
};

}}}}

namespace winrt { namespace Windows { namespace Foundation {

template <typename TProgress> struct IAsyncActionProgressHandler;
template <typename TProgress> struct IAsyncActionWithProgress;
template <typename TProgress> struct IAsyncActionWithProgressCompletedHandler;
template <typename TResult, typename TProgress> struct IAsyncOperationProgressHandler;
template <typename TResult, typename TProgress> struct IAsyncOperationWithProgressCompletedHandler;
template <typename TResult> struct IAsyncOperationCompletedHandler;
template <typename T> struct IEventHandler;
template <typename TSender, typename TArgs> struct ITypedEventHandler;
template <typename TResult> struct IAsyncOperation;
template <typename TResult, typename TProgress> struct IAsyncOperationWithProgress;
template <typename T> struct IReference;

template <typename D, typename TProgress>
class impl_IAsyncActionProgressHandler
{
	auto shim() const { return impl::shim<D, IAsyncActionProgressHandler<TProgress>>(this); }

public:

	void Invoke(IAsyncActionWithProgress<TProgress> const & sender, TProgress const & args) const
	{
		check_hresult(shim()->abi_Invoke(get(sender), get(args)));
	}
};

template <typename D, typename TProgress>
class impl_IAsyncActionWithProgress
{
	auto shim() const { return impl::shim<D, IAsyncActionWithProgress<TProgress>>(this); }

public:

	void Progress(IAsyncActionProgressHandler<TProgress> const & handler) const
	{
		check_hresult(shim()->put_Progress(get(handler)));
	}

	template <typename Handler>
	void Progress(Handler handler) const
	{
		return Progress(AsyncActionProgressHandler<TProgress>(handler));
	}

	IAsyncActionProgressHandler<TProgress> Progress() const
	{
		IAsyncActionProgressHandler<TProgress> handler;
		check_hresult(shim()->get_Progress(put(handler)));
		return handler;
	}

	void Completed(IAsyncActionWithProgressCompletedHandler<TProgress> const & handler) const
	{
		check_hresult(shim()->put_Completed(get(handler)));
	}

	template <typename Handler>
	void Completed(Handler handler) const
	{
		return Completed(AsyncActionWithProgressCompletedHandler<TProgress>(handler));
	}

	IAsyncActionWithProgressCompletedHandler<TProgress> Completed() const
	{
		IAsyncActionWithProgressCompletedHandler<TProgress> handler;
		check_hresult(shim()->get_Completed(put(handler)));
		return handler;
	}

	void GetResults() const
	{
		check_hresult(shim()->abi_GetResults());
	}
};

template <typename D, typename TProgress>
class impl_IAsyncActionWithProgressCompletedHandler
{
	auto shim() const { return impl::shim<D, IAsyncActionWithProgressCompletedHandler<TProgress>>(this); }

public:

	void Invoke(IAsyncActionWithProgress<TProgress> const & sender, AsyncStatus const args) const
	{
		check_hresult(shim()->abi_Invoke(get(sender), args));
	}
};

template <typename D, typename TResult, typename TProgress>
class impl_IAsyncOperationProgressHandler
{
	auto shim() const { return impl::shim<D, IAsyncOperationProgressHandler<TResult, TProgress>>(this); }

public:

	void Invoke(IAsyncOperationWithProgress<TResult, TProgress> const & sender, TProgress const & args) const
	{
		check_hresult(shim()->abi_Invoke(get(sender), get(args)));
	}
};

template <typename D, typename TResult, typename TProgress>
class impl_IAsyncOperationWithProgressCompletedHandler
{
	auto shim() const { return impl::shim<D, IAsyncOperationWithProgressCompletedHandler<TResult, TProgress>>(this); }

public:

	void Invoke(IAsyncOperationWithProgress<TResult, TProgress> const & sender, AsyncStatus const args) const
	{
		check_hresult(shim()->abi_Invoke(get(sender), args));
	}
};

template <typename D, typename TResult>
class impl_IAsyncOperationCompletedHandler
{
	auto shim() const { return impl::shim<D, IAsyncOperationCompletedHandler<TResult>>(this); }

public:

	void Invoke(IAsyncOperation<TResult> const & sender, AsyncStatus const args) const
	{
		check_hresult(shim()->abi_Invoke(get(sender), args));
	}
};

template <typename D, typename T>
class impl_IEventHandler
{
	auto shim() const { return impl::shim<D, IEventHandler<T>>(this); }

public:

	void Invoke(IInspectable const & sender, T const & args) const
	{
		check_hresult(shim()->abi_Invoke(get(sender), get(args)));
	}
};

template <typename D, typename TSender, typename TArgs>
class impl_ITypedEventHandler
{
	auto shim() const { return impl::shim<D, ITypedEventHandler<TSender, TArgs>>(this); }

public:

	void Invoke(TSender const & sender, TArgs const & args) const
	{
		check_hresult(shim()->abi_Invoke(get(sender), get(args)));
	}
};

template <typename D, typename TResult>
class impl_IAsyncOperation
{
	auto shim() const { return impl::shim<D, IAsyncOperation<TResult>>(this); }

public:

	void Completed(IAsyncOperationCompletedHandler<TResult> const & handler) const
	{
		check_hresult(shim()->put_Completed(get(handler)));
	}

	template <typename Handler>
	void Completed(Handler handler) const
	{
		return Completed(AsyncOperationCompletedHandler<TResult>(handler));
	}

	IAsyncOperationCompletedHandler<TResult> Completed() const
	{
		IAsyncOperationCompletedHandler<TResult> temp;
		check_hresult(shim()->get_Completed(put(temp)));
		return temp;
	}

	TResult GetResults() const
	{
		TResult result = impl::argument<TResult>::empty();
		check_hresult(shim()->abi_GetResults(put(result)));
		return result;
	}
};

template <typename D, typename TResult, typename TProgress>
class impl_IAsyncOperationWithProgress
{
	auto shim() const { return impl::shim<D, IAsyncOperationWithProgress<TResult, TProgress>>(this); }

public:

	void Progress(IAsyncOperationProgressHandler<TResult, TProgress> const & handler) const
	{
		check_hresult(shim()->put_Progress(get(handler)));
	}

	template <typename Handler>
	void Progress(Handler handler) const
	{
		return Progress(AsyncOperationProgressHandler<TResult, TProgress>(handler));
	}

	IAsyncOperationProgressHandler<TResult, TProgress> Progress() const
	{
		IAsyncOperationProgressHandler<TResult, TProgress> handler;
		check_hresult(shim()->get_Progress(put(handler)));
		return handler;
	}

	void Completed(IAsyncOperationWithProgressCompletedHandler<TResult, TProgress> const & handler) const
	{
		check_hresult(shim()->put_Completed(get(handler)));
	}

	template <typename Handler>
	void Completed(Handler handler) const
	{
		return Completed(AsyncOperationWithProgressCompletedHandler<TResult, TProgress>(handler));
	}

	IAsyncOperationWithProgressCompletedHandler<TResult, TProgress> Completed() const
	{
		IAsyncOperationWithProgressCompletedHandler<TResult, TProgress> handler;
		check_hresult(shim()->get_Completed(put(handler)));
		return handler;
	}

	TResult GetResults() const
	{
		TResult result = impl::argument<TResult>::empty();
		check_hresult(shim()->abi_GetResults(put(result)));
		return result;
	}
};

template <typename D, typename T>
class impl_IReference
{
	auto shim() const { return impl::shim<D, IReference<T>>(this); }

public:

	T Value() const
	{
		T result = impl::argument<T>::empty();
		check_hresult(shim()->get_Value(put(result)));
		return result;
	}
};

template <typename TProgress>
struct IAsyncActionProgressHandler :
	IUnknown,
	impl_IAsyncActionProgressHandler<IAsyncActionProgressHandler<TProgress>, TProgress>
{
	IAsyncActionProgressHandler(std::nullptr_t = nullptr) noexcept {}
	auto operator->() const noexcept { return ptr<IAsyncActionProgressHandler>(m_ptr); }
};

template <typename TProgress>
struct IAsyncActionWithProgress :
	IInspectable,
	impl_IAsyncActionWithProgress<IAsyncActionWithProgress<TProgress>, TProgress>,
	requires<IAsyncActionWithProgress<TProgress>, IAsyncInfo>
{
	IAsyncActionWithProgress(std::nullptr_t = nullptr) noexcept {}
	auto operator->() const noexcept { return ptr<IAsyncActionWithProgress>(m_ptr); }
};

template <typename TProgress>
struct IAsyncActionWithProgressCompletedHandler :
	IUnknown,
	impl_IAsyncActionWithProgressCompletedHandler<IAsyncActionWithProgressCompletedHandler<TProgress>, TProgress>
{
	IAsyncActionWithProgressCompletedHandler(std::nullptr_t = nullptr) noexcept {}
	auto operator->() const noexcept { return ptr<IAsyncActionWithProgressCompletedHandler>(m_ptr); }
};

template <typename TResult, typename TProgress>
struct IAsyncOperationProgressHandler :
	IUnknown,
	impl_IAsyncOperationProgressHandler<IAsyncOperationProgressHandler<TResult, TProgress>, TResult, TProgress>
{
	IAsyncOperationProgressHandler(std::nullptr_t = nullptr) noexcept {}
	auto operator->() const noexcept { return ptr<IAsyncOperationProgressHandler>(m_ptr); }
};

template <typename TResult, typename TProgress>
struct IAsyncOperationWithProgressCompletedHandler :
	IUnknown,
	impl_IAsyncOperationWithProgressCompletedHandler<IAsyncOperationWithProgressCompletedHandler<TResult, TProgress>, TResult, TProgress>
{
	IAsyncOperationWithProgressCompletedHandler(std::nullptr_t = nullptr) noexcept {}
	auto operator->() const noexcept { return ptr<IAsyncOperationWithProgressCompletedHandler>(m_ptr); }
};

template <typename TResult>
struct IAsyncOperationCompletedHandler :
	IUnknown,
	impl_IAsyncOperationCompletedHandler<IAsyncOperationCompletedHandler<TResult>, TResult>
{
	IAsyncOperationCompletedHandler(std::nullptr_t = nullptr) noexcept {}
	auto operator->() const noexcept { return ptr<IAsyncOperationCompletedHandler>(m_ptr); }
};

template <typename T>
struct IEventHandler :
	IUnknown,
	impl_IEventHandler<IEventHandler<T>, T>
{
	IEventHandler(std::nullptr_t = nullptr) noexcept {}
	auto operator->() const noexcept { return ptr<IEventHandler>(m_ptr); }
};

template <typename TSender, typename TArgs>
struct ITypedEventHandler :
	IUnknown,
	impl_ITypedEventHandler<ITypedEventHandler<TSender, TArgs>, TSender, TArgs>
{
	ITypedEventHandler(std::nullptr_t = nullptr) noexcept {}
	auto operator->() const noexcept { return ptr<ITypedEventHandler>(m_ptr); }
};

template <typename TResult>
struct IAsyncOperation :
	IInspectable,
	impl_IAsyncOperation<IAsyncOperation<TResult>, TResult>,
	requires<IAsyncOperation<TResult>, IAsyncInfo>
{
	IAsyncOperation(std::nullptr_t = nullptr) noexcept {}
	auto operator->() const noexcept { return ptr<IAsyncOperation>(m_ptr); }
};

template <typename TResult, typename TProgress>
struct IAsyncOperationWithProgress :
	IInspectable,
	impl_IAsyncOperationWithProgress<IAsyncOperationWithProgress<TResult, TProgress>, TResult, TProgress>,
	requires<IAsyncOperationWithProgress<TResult, TProgress>, IAsyncInfo>
{
	IAsyncOperationWithProgress(std::nullptr_t = nullptr) noexcept {}
	auto operator->() const noexcept { return ptr<IAsyncOperationWithProgress>(m_ptr); }
};

struct IPropertyValue;

template <typename T>
struct IReference :
	IInspectable,
	impl_IReference<IReference<T>, T> //,
	// requires<IReference<T>, IPropertyValue>
{
	IReference(std::nullptr_t = nullptr) noexcept {}
	auto operator->() const noexcept { return ptr<IReference>(m_ptr); }

	IReference(T const & value);
};

}}}

namespace winrt { namespace impl {

template <typename TProgress> struct traits<Windows::Foundation::IAsyncActionProgressHandler<TProgress>>
{
	using abi = ABI::Windows::Foundation::IAsyncActionProgressHandler<abi<TProgress>>;
	template <typename D> using methods = Windows::Foundation::impl_IAsyncActionProgressHandler<D, TProgress>;
};

template <typename TProgress> struct traits<Windows::Foundation::IAsyncActionWithProgress<TProgress>>
{
	using abi = ABI::Windows::Foundation::IAsyncActionWithProgress<abi<TProgress>>;
	template <typename D> using methods = Windows::Foundation::impl_IAsyncActionWithProgress<D, TProgress>;
};

template <typename TProgress> struct traits<Windows::Foundation::IAsyncActionWithProgressCompletedHandler<TProgress>>
{
	using abi = ABI::Windows::Foundation::IAsyncActionWithProgressCompletedHandler<abi<TProgress>>;
	template <typename D> using methods = Windows::Foundation::impl_IAsyncActionWithProgressCompletedHandler<D, TProgress>;
};

template <typename TResult, typename TProgress> struct traits<Windows::Foundation::IAsyncOperationProgressHandler<TResult, TProgress>>
{
	using abi = ABI::Windows::Foundation::IAsyncOperationProgressHandler<abi<TResult>, abi<TProgress>>;
	template <typename D> using methods = Windows::Foundation::impl_IAsyncOperationProgressHandler<D, TResult, TProgress>;
};

template <typename TResult, typename TProgress> struct traits<Windows::Foundation::IAsyncOperationWithProgressCompletedHandler<TResult, TProgress>>
{
	using abi = ABI::Windows::Foundation::IAsyncOperationWithProgressCompletedHandler<abi<TResult>, abi<TProgress>>;
	template <typename D> using methods = Windows::Foundation::impl_IAsyncOperationWithProgressCompletedHandler<D, TResult, TProgress>;
};

template <typename TResult> struct traits<Windows::Foundation::IAsyncOperationCompletedHandler<TResult>>
{
	using abi = ABI::Windows::Foundation::IAsyncOperationCompletedHandler<abi<TResult>>;
	template <typename D> using methods = Windows::Foundation::impl_IAsyncOperationCompletedHandler<D, TResult>;
};

template <typename T> struct traits<Windows::Foundation::IEventHandler<T>>
{
	using abi = ABI::Windows::Foundation::IEventHandler<abi<T>>;
	template <typename D> using methods = Windows::Foundation::impl_IEventHandler<D, T>;
};

template <typename TSender, typename TArgs> struct traits<Windows::Foundation::ITypedEventHandler<TSender, TArgs>>
{
	using abi = ABI::Windows::Foundation::ITypedEventHandler<abi<TSender>, abi<TArgs>>;
	template <typename D> using methods = Windows::Foundation::impl_ITypedEventHandler<D, TSender, TArgs>;
};

template <typename TResult> struct traits<Windows::Foundation::IAsyncOperation<TResult>>
{
	using abi = ABI::Windows::Foundation::IAsyncOperation<abi<TResult>>;
	template <typename D> using methods = Windows::Foundation::impl_IAsyncOperation<D, TResult>;
};

template <typename TResult, typename TProgress> struct traits<Windows::Foundation::IAsyncOperationWithProgress<TResult, TProgress>>
{
	using abi = ABI::Windows::Foundation::IAsyncOperationWithProgress<abi<TResult>, abi<TProgress>>;
	template <typename D> using methods = Windows::Foundation::impl_IAsyncOperationWithProgress<D, TResult, TProgress>;
};

template <typename T> struct traits<Windows::Foundation::IReference<T>>
{
	using abi = ABI::Windows::Foundation::IReference<abi<T>>;
	template <typename D> using methods = Windows::Foundation::impl_IReference<D, T>;
};

}}

namespace winrt { namespace Windows { namespace Foundation {

template <typename TProgress, typename THandler>
struct impl_AsyncActionProgressHandler : impl::implements<IAsyncActionProgressHandler<TProgress>>, THandler
{
	impl_AsyncActionProgressHandler(THandler handler) : THandler(handler) {}

	HRESULT __stdcall abi_Invoke(abi_arg_in<IAsyncActionWithProgress<TProgress>> sender, abi_arg_in<TProgress> args) noexcept override
	{
		try
		{
			(*this)(lease<IAsyncActionWithProgress<TProgress>>(sender), lease<TProgress>(args));
			return S_OK;
		}
		catch (...) { return impl::to_hresult(); }
	}
};

template <typename TProgress, typename THandler>
IAsyncActionProgressHandler<TProgress> AsyncActionProgressHandler(THandler handler)
{
	return make<impl_AsyncActionProgressHandler<TProgress, THandler>>(handler);
}

template <typename TProgress, typename THandler>
struct impl_AsyncActionWithProgressCompletedHandler : impl::implements<IAsyncActionWithProgressCompletedHandler<TProgress>>, THandler
{
	impl_AsyncActionWithProgressCompletedHandler(THandler handler) : THandler(handler) {}

	HRESULT __stdcall abi_Invoke(abi_arg_in<IAsyncActionWithProgress<TProgress>> sender, AsyncStatus args) noexcept override
	{
		try
		{
			(*this)(lease<IAsyncActionWithProgress<TProgress>>(sender), args);
			return S_OK;
		}
		catch (...) { return impl::to_hresult(); }
	}
};

template <typename TProgress, typename THandler>
IAsyncActionWithProgressCompletedHandler<TProgress> AsyncActionWithProgressCompletedHandler(THandler handler)
{
	return make<impl_AsyncActionWithProgressCompletedHandler<TProgress, THandler>>(handler);
}

template <typename TResult, typename TProgress, typename THandler>
struct impl_AsyncOperationProgressHandler : impl::implements<IAsyncOperationProgressHandler<TResult, TProgress>>, THandler
{
	impl_AsyncOperationProgressHandler(THandler handler) : THandler(handler) {}

	HRESULT __stdcall abi_Invoke(abi_arg_in<IAsyncOperationWithProgress<TResult, TProgress>> sender, abi_arg_in<TProgress> args) noexcept override
	{
		try
		{
			(*this)(lease<IAsyncOperationWithProgress<TResult, TProgress>>(sender), lease<TProgress>(args));
			return S_OK;
		}
		catch (...) { return impl::to_hresult(); }
	}
};

template <typename TResult, typename TProgress, typename THandler>
IAsyncOperationProgressHandler<TResult, TProgress> AsyncOperationProgressHandler(THandler handler)
{
	return make<impl_AsyncOperationProgressHandler<TResult, TProgress, THandler>>(handler);
}

template <typename TResult, typename TProgress, typename THandler>
struct impl_AsyncOperationWithProgressCompletedHandler : impl::implements<IAsyncOperationWithProgressCompletedHandler<TResult, TProgress>>, THandler
{
	impl_AsyncOperationWithProgressCompletedHandler(THandler handler) : THandler(handler) {}

	HRESULT __stdcall abi_Invoke(abi_arg_in<IAsyncOperationWithProgress<TResult, TProgress>> sender, AsyncStatus args) noexcept override
	{
		try
		{
			(*this)(lease<IAsyncOperationWithProgress<TResult, TProgress>>(sender), args);
			return S_OK;
		}
		catch (...) { return impl::to_hresult(); }
	}
};

template <typename TResult, typename TProgress, typename THandler>
IAsyncOperationWithProgressCompletedHandler<TResult, TProgress> AsyncOperationWithProgressCompletedHandler(THandler handler)
{
	return make<impl_AsyncOperationWithProgressCompletedHandler<TResult, TProgress, THandler>>(handler);
}

template <typename TResult, typename THandler>
struct impl_AsyncOperationCompletedHandler : impl::implements<IAsyncOperationCompletedHandler<TResult>>, THandler
{
	impl_AsyncOperationCompletedHandler(THandler handler) : THandler(handler) {}

	HRESULT __stdcall abi_Invoke(abi_arg_in<IAsyncOperation<TResult>> sender, AsyncStatus args) noexcept override
	{
		try
		{
			(*this)(lease<IAsyncOperation<TResult>>(sender), args);
			return S_OK;
		}
		catch (...) { return impl::to_hresult(); }
	}
};

template <typename TResult, typename THandler>
IAsyncOperationCompletedHandler<TResult> AsyncOperationCompletedHandler(THandler handler)
{
	return make<impl_AsyncOperationCompletedHandler<TResult, THandler>>(handler);
}

template <typename TArgs, typename THandler>
struct impl_EventHandler : impl::implements<IEventHandler<TArgs>>, THandler
{
	impl_EventHandler(THandler handler) : THandler(handler) {}

	HRESULT __stdcall abi_Invoke(abi_arg_in<IInspectable> sender, abi_arg_in<TArgs> args) noexcept override
	{
		try
		{
			(*this)(lease<IInspectable>(sender), lease<TArgs>(args));
			return S_OK;
		}
		catch (...) { return impl::to_hresult(); }
	}
};

template <typename TArgs, typename THandler>
IEventHandler<TArgs> EventHandler(THandler handler)
{
	return make<impl_EventHandler<TArgs, THandler>>(handler);
}

template <typename TSender, typename TArgs, typename THandler>
struct impl_TypedEventHandler : impl::implements<Windows::Foundation::ITypedEventHandler<TSender, TArgs>>, THandler
{
	impl_TypedEventHandler(THandler handler) : THandler(handler) {}

	HRESULT __stdcall abi_Invoke(abi_arg_in<TSender> sender, abi_arg_in<TArgs> args) noexcept override
	{
		try
		{
			(*this)(lease<TSender>(sender), lease<TArgs>(args));
			return S_OK;
		}
		catch (...) { return impl::to_hresult(); }
	}
};

template <typename TSender, typename TArgs, typename THandler>
ITypedEventHandler<TSender, TArgs> TypedEventHandler(THandler handler)
{
	return make<impl_TypedEventHandler<TSender, TArgs, THandler>>(handler);
}

}}}

namespace winrt { namespace Windows { namespace Foundation { namespace Collections {

enum class CollectionChange
{
	Reset,
	ItemInserted,
	ItemRemoved,
	ItemChanged,
};

}}}}


namespace winrt { namespace ABI { namespace Windows { namespace Foundation { namespace Collections {


struct __declspec(uuid("575933df-34fe-4480-af15-07691f3d5d9b")) __declspec(novtable) IVectorChangedEventArgs : IInspectable
{
	virtual HRESULT __stdcall get_CollectionChange(winrt::Windows::Foundation::Collections::CollectionChange * value) = 0;
	virtual HRESULT __stdcall get_Index(unsigned * value) = 0;
};

}}}}}

namespace winrt { namespace Windows { namespace Foundation { namespace Collections {

struct IVectorChangedEventArgs;

template <typename D>
class impl_IVectorChangedEventArgs
{
	auto shim() const { return impl::shim<D, IVectorChangedEventArgs>(this); }

public:

	CollectionChange CollectionChange() const;
	unsigned Index() const;
};

}}}}

namespace winrt { namespace impl {

template <> struct traits<Windows::Foundation::Collections::IVectorChangedEventArgs>
{
	using abi = ABI::Windows::Foundation::Collections::IVectorChangedEventArgs;
	template <typename T> using methods = Windows::Foundation::Collections::impl_IVectorChangedEventArgs<T>;
};

}}

namespace winrt { namespace Windows { namespace Foundation { namespace Collections {

struct IVectorChangedEventArgs :
	IInspectable,
	impl_IVectorChangedEventArgs<IVectorChangedEventArgs>
{
	IVectorChangedEventArgs(std::nullptr_t = nullptr) noexcept {}
	auto operator->() const noexcept { return ptr<IVectorChangedEventArgs>(m_ptr); }
};


template <typename T> CollectionChange impl_IVectorChangedEventArgs<T>::CollectionChange() const
{
	Collections::CollectionChange value = {};
	check_hresult(shim()->get_CollectionChange(&value));
	return value;
}

template <typename T> unsigned impl_IVectorChangedEventArgs<T>::Index() const
{
	unsigned index = 0;
	check_hresult(shim()->get_Index(&index));
	return index;
}

}}}}

namespace winrt { namespace ABI { namespace Windows { namespace Foundation { namespace Collections {

template <typename T> struct IIterator;
template <typename T> struct IIterable;
template <typename K, typename V> struct IKeyValuePair;
template <typename T> struct IVectorView;
template <typename T> struct IVector;
template <typename K, typename V> struct IMapView;
template <typename K, typename V> struct IMap;
template <typename K> struct IMapChangedEventArgs;
template <typename K, typename V> struct IMapChangedEventHandler;
template <typename K, typename V> struct IObservableMap;
template <typename T> struct IVectorChangedEventHandler;
template <typename T> struct IObservableVector;

template <typename T>
struct __declspec(novtable) impl_IIterator : IInspectable
{
	virtual HRESULT __stdcall get_Current(arg_out<T> current) = 0;
	virtual HRESULT __stdcall get_HasCurrent(bool * hasCurrent) = 0;
	virtual HRESULT __stdcall abi_MoveNext(bool * hasCurrent) = 0;
	virtual HRESULT __stdcall abi_GetMany(unsigned capacity, arg_out<T> value, unsigned * actual) = 0;

};

template <typename T>
struct __declspec(novtable) impl_IIterable : IInspectable
{
	virtual HRESULT __stdcall abi_First(IIterator<T> ** first) = 0;
};

template <typename K, typename V>
struct __declspec(novtable) impl_IKeyValuePair : IInspectable
{
	virtual HRESULT __stdcall get_Key(arg_out<K> key) = 0;
	virtual HRESULT __stdcall get_Value(arg_out<V> value) = 0;
};

template <typename T>
struct __declspec(novtable) impl_IVectorView : IInspectable
{
	virtual HRESULT __stdcall abi_GetAt(unsigned index, arg_out<T> item) = 0;
	virtual HRESULT __stdcall get_Size(unsigned * size) = 0;
	virtual HRESULT __stdcall abi_IndexOf(arg_in<T> value, unsigned * index, bool * found) = 0;
	virtual HRESULT __stdcall abi_GetMany(unsigned startIndex, unsigned capacity, arg_out<T> value, unsigned * actual) = 0;
};

template <typename T>
struct __declspec(novtable) impl_IVector : IInspectable
{
	virtual HRESULT __stdcall abi_GetAt(unsigned index, arg_out<T> item) = 0;
	virtual HRESULT __stdcall get_Size(unsigned * size) = 0;
	virtual HRESULT __stdcall abi_GetView(IVectorView<T> ** view) = 0;
	virtual HRESULT __stdcall abi_IndexOf(arg_in<T> value, unsigned * index, bool * found) = 0;
	virtual HRESULT __stdcall abi_SetAt(unsigned index, arg_in<T> item) = 0;
	virtual HRESULT __stdcall abi_InsertAt(unsigned index, arg_in<T> item) = 0;
	virtual HRESULT __stdcall abi_RemoveAt(unsigned index) = 0;
	virtual HRESULT __stdcall abi_Append(arg_in<T> item) = 0;
	virtual HRESULT __stdcall abi_RemoveAtEnd() = 0;
	virtual HRESULT __stdcall abi_Clear() = 0;
	virtual HRESULT __stdcall abi_GetMany(unsigned startIndex, unsigned capacity, arg_out<T> value, unsigned * actual) = 0;
	virtual HRESULT __stdcall abi_ReplaceAll(unsigned count, arg_out<T> value) = 0;

};

template <typename K, typename V>
struct __declspec(novtable) impl_IMapView : IInspectable
{
	virtual HRESULT __stdcall abi_Lookup(arg_in<K> key, arg_out<V> value) = 0;
	virtual HRESULT __stdcall get_Size(unsigned * size) = 0;
	virtual HRESULT __stdcall abi_HasKey(arg_in<K> key, bool * found) = 0;
	virtual HRESULT __stdcall abi_Split(IMapView<K, V> ** firstPartition, IMapView<K, V> ** secondPartition) = 0;
};

template <typename K, typename V>
struct __declspec(novtable) impl_IMap : IInspectable
{
	virtual HRESULT __stdcall abi_Lookup(arg_in<K> key, arg_out<V> value) = 0;
	virtual HRESULT __stdcall get_Size(unsigned * size) = 0;
	virtual HRESULT __stdcall abi_HasKey(arg_in<K> key, bool * found) = 0;
	virtual HRESULT __stdcall abi_GetView(IMapView<K, V> ** view) = 0;
	virtual HRESULT __stdcall abi_Insert(arg_in<K> key, V const & value, bool * replaced) = 0;
	virtual HRESULT __stdcall abi_Remove(arg_in<K> key) = 0;
	virtual HRESULT __stdcall abi_Clear() = 0;
};

template <typename K>
struct __declspec(novtable) impl_IMapChangedEventArgs : IInspectable
{
	virtual HRESULT __stdcall get_CollectionChange(winrt::Windows::Foundation::Collections::CollectionChange * value) = 0;
	virtual HRESULT __stdcall get_Key(arg_out<K> value) = 0;
};

template <typename K, typename V>
struct __declspec(novtable) impl_IMapChangedEventHandler : IUnknown
{
	virtual HRESULT __stdcall abi_Invoke(IObservableMap<K, V> * sender, IMapChangedEventArgs<K> * args) = 0;
};

template <typename K, typename V>
struct __declspec(novtable) impl_IObservableMap : IInspectable
{
	virtual HRESULT __stdcall add_MapChanged(IMapChangedEventHandler<K, V> * handler, long long * token) = 0;
	virtual HRESULT __stdcall remove_MapChanged(long long token) = 0;
};

template <typename T>
struct __declspec(novtable) impl_IVectorChangedEventHandler : IUnknown
{
	virtual HRESULT __stdcall abi_Invoke(IObservableVector<T> * sender, IVectorChangedEventArgs * args) = 0;
};

template <typename T>
struct __declspec(novtable) impl_IObservableVector : IInspectable
{
	virtual HRESULT __stdcall add_VectorChanged(IVectorChangedEventHandler<T> * handler, long long *  token) = 0;
	virtual HRESULT __stdcall remove_VectorChanged(long long token) = 0;
};

}}}}}

namespace winrt { namespace Windows { namespace Foundation { namespace Collections {

template <typename T> struct IIterator;
template <typename T> struct IIterable;
template <typename K, typename V> struct IKeyValuePair;
template <typename T> struct IVectorView;
template <typename T> struct IVector;
template <typename K, typename V> struct IMapView;
template <typename K, typename V> struct IMap;
template <typename K> struct IMapChangedEventArgs;
template <typename K, typename V> struct IMapChangedEventHandler;
template <typename K, typename V> struct IObservableMap;
template <typename T> struct IVectorChangedEventHandler;
template <typename T> struct IObservableVector;

template <typename D, typename T>
class impl_IIterator
{
	auto shim() const { return impl::shim<D, IIterator<T>>(this); }

public:

	T Current() const
	{
		T result = impl::argument<T>::empty();
		check_hresult(shim()->get_Current(put(result)));
		return result;
	}

	bool HasCurrent() const
	{
		bool temp = false;
		check_hresult(shim()->get_HasCurrent(&temp));
		return temp;
	}

	bool MoveNext() const
	{
		bool temp = false;
		check_hresult(shim()->abi_MoveNext(&temp));
		return temp;
	}

	impl_IIterator & operator++()
	{
		if (!MoveNext())
		{
			static_cast<D &>(*this) = nullptr;
		}

		return *this;
	}

	T operator *() const
	{
		return Current();
	}
};

template <typename D, typename T>
class impl_IIterable
{
	auto shim() const { return impl::shim<D, IIterable<T>>(this); }

public:

	IIterator<T> First() const
	{
		IIterator<T> iterator;
		check_hresult(shim()->abi_First(put(iterator)));
		return iterator;
	}
};

template <typename D, typename K, typename V>
class impl_IKeyValuePair
{
	auto shim() const { return impl::shim<D, IKeyValuePair<K, V>>(this); }

public:

	K Key() const
	{
		K result = impl::argument<K>::empty();
		check_hresult(shim()->get_Key(put(result)));
		return result;
	}

	V Value() const
	{
		V result = impl::argument<V>::empty();
		check_hresult(shim()->get_Value(put(result)));
		return result;
	}
};

template <typename D, typename T>
class impl_IVectorView
{
	auto shim() const { return impl::shim<D, IVectorView<T>>(this); }

public:

	T GetAt(unsigned const index) const
	{
		T result = impl::argument<T>::empty();
		check_hresult(shim()->abi_GetAt(index, put(result)));
		return result;
	}

	unsigned Size() const
	{
		unsigned size = 0;
		check_hresult(shim()->get_Size(&size));
		return size;
	}

	bool IndexOf(T const & value, unsigned & index) const
	{
		bool found = false;
		check_hresult(shim()->abi_IndexOf(get(value), &index, &found));
		return found;
	}
};

template <typename D, typename T>
class impl_IVector
{
	auto shim() const { return impl::shim<D, IVector<T>>(this); }

public:

	T GetAt(unsigned const index) const
	{
		T result = impl::argument<T>::empty();
		check_hresult(shim()->abi_GetAt(index, put(result)));
		return result;
	}

	unsigned Size() const
	{
		unsigned size = 0;
		check_hresult(shim()->get_Size(&size));
		return size;
	}

	IVectorView<T> GetView() const
	{
		IVectorView<T> view;
		check_hresult(shim()->abi_GetView(put(view)));
		return view;
	}

	bool IndexOf(T const & value, unsigned & index) const
	{
		bool found = false;
		check_hresult(shim()->abi_IndexOf(get(value), &index, &found));
		return found;
	}

	void SetAt(unsigned const index, T const & value) const
	{
		check_hresult(shim()->abi_SetAt(index, get(value)));
	}

	void InsertAt(unsigned const index, T const & value) const
	{
		check_hresult(shim()->abi_InsertAt(index, get(value)));
	}

	void RemoveAt(unsigned const index) const
	{
		check_hresult(shim()->abi_RemoveAt(index));
	}

	void Append(T const & value) const
	{
		check_hresult(shim()->abi_Append(get(value)));
	}

	void RemoveAtEnd() const
	{
		check_hresult(shim()->abi_RemoveAtEnd());
	}

	void Clear() const
	{
		check_hresult(shim()->abi_Clear());
	}
};

template <typename D, typename K, typename V>
class impl_IMapView
{
	auto shim() const { return impl::shim<D, IMapView<K, V>>(this); }

public:

	V Lookup(K const & key) const
	{
		V result = impl::argument<V>::empty();
		check_hresult(shim()->abi_Lookup(get(key), put(result)));
		return result;
	}

	unsigned Size() const
	{
		unsigned size = 0;
		check_hresult(shim()->get_Size(&size));
		return size;
	}

	bool HasKey(K const & key) const
	{
		bool found = false;
		check_hresult(shim()->abi_HasKey(get(key), &found));
		return found;
	}

	void Split(IMapView<K, V> & firstPartition, IMapView<K, V> & secondPartition)
	{
		check_hresult(shim()->abi_Split(put(firstPartition), put(secondPartition)));
	}
};

template <typename D, typename K, typename V>
class impl_IMap
{
	auto shim() const { return impl::shim<D, IMap<K, V>>(this); }

public:

	V Lookup(K const & key) const
	{
		V result = impl::argument<V>::empty();
		check_hresult(shim()->abi_Lookup(get(key), put(result)));
		return result;
	}

	unsigned Size() const
	{
		unsigned size = 0;
		check_hresult(shim()->get_Size(&size));
		return size;
	}

	bool HasKey(K const & key) const
	{
		bool found = false;
		check_hresult(shim()->abi_HasKey(get(key), &found));
		return found;
	}

	IMapView<K, V> GetView() const
	{
		IMapView<K, V> view;
		check_hresult(shim()->abi_GetView(put(view)));
		return view;
	}

	bool Insert(K const & key, V const & value) const
	{
		bool replaced = false;
		check_hresult(shim()->abi_Insert(get(key), get(value), &replaced));
		return replaced;
	}

	void Remove(K const & key) const
	{
		check_hresult(shim()->abi_Remove(get(key)));
	}

	void Clear() const
	{
		check_hresult(shim()->abi_Clear());
	}
};

template <typename D, typename K>
class impl_IMapChangedEventArgs
{
	auto shim() const { return impl::shim<D, IMapChangedEventArgs<K>>(this); }

public:

	CollectionChange CollectionChange() const
	{
		CollectionChange value = {};
		check_hresult(shim()->get_CollectionChange(&value));
		return value;
	}

	K Key() const
	{
		K result = impl::argument<K>::empty();
		check_hresult(shim()->get_Key(put(result)));
		return result;
	}
};

template <typename D, typename K, typename V>
class impl_IMapChangedEventHandler
{
	auto shim() const { return impl::shim<D, IMapChangedEventHandler<K, V>>(this); }

public:

	void Invoke(IObservableMap<K, V> const & sender, IMapChangedEventArgs<K> const & args) const
	{
		check_hresult(shim()->abi_Invoke(get(sender), get(args)));
	}
};

template <typename D, typename K, typename V>
class impl_IObservableMap
{
	auto shim() const { return impl::shim<D, IObservableMap<K, V>>(this); }

public:

	long long MapChanged(IMapChangedEventHandler<K, V> const & handler) const
	{
		long long cookie = {};
		check_hresult(shim()->add_MapChanged(get(handler), &cookie));
		return cookie;
	}

	template <typename T> long long MapChanged(T handler) const
	{
		return MapChanged(MapChangedEventHandler<K, V>(handler));
	}

	void MapChanged(long long const cookie) const
	{
		check_hresult(shim()->remove_MapChanged(cookie));
	}
};

template <typename D, typename T>
class impl_IVectorChangedEventHandler
{
	auto shim() const { return impl::shim<D, IVectorChangedEventHandler<T>>(this); }

public:

	void Invoke(IObservableVector<T> const & sender, IVectorChangedEventArgs const & args) const
	{
		check_hresult(shim()->abi_Invoke(get(sender), get(args)));
	}
};

template <typename D, typename T>
class impl_IObservableVector
{
	auto shim() const { return impl::shim<D, IObservableVector<T>>(this); }

public:

	long long VectorChanged(IVectorChangedEventHandler<T> const & handler) const
	{
		long long cookie = {};
		check_hresult(shim()->add_VectorChanged(get(handler), &cookie));
		return cookie;
	}

	template <typename Handler> long long VectorChanged(Handler handler) const
	{
		return VectorChanged(VectorChangedEventHandler<T>(handler));
	}

	void VectorChanged(long long const cookie) const
	{
		check_hresult(shim()->remove_VectorChanged(cookie));
	}
};

template <typename T>
struct IIterator :
	IInspectable,
	impl_IIterator<IIterator<T>, T>
{
	IIterator(std::nullptr_t = nullptr) noexcept {}
	auto operator->() const noexcept { return ptr<IIterator>(m_ptr); }
};

template <typename T>
struct IIterable :
	IInspectable,
	impl_IIterable<IIterable<T>, T>
{
	IIterable(std::nullptr_t = nullptr) noexcept {}
	auto operator->() const noexcept { return ptr<IIterable>(m_ptr); }
};

template <typename K, typename V>
struct IKeyValuePair :
	IInspectable,
	impl_IKeyValuePair<IKeyValuePair<K, V>, K, V>
{
	IKeyValuePair(std::nullptr_t = nullptr) noexcept {}
	auto operator->() const noexcept { return ptr<IKeyValuePair>(m_ptr); }
};

template <typename T>
struct IVectorView :
	IInspectable,
	impl_IVectorView<IVectorView<T>, T>,
	requires<IVectorView<T>, IIterable<T>>
{
	IVectorView(std::nullptr_t = nullptr) noexcept {}
	auto operator->() const noexcept { return ptr<IVectorView>(m_ptr); }
};

template <typename T>
struct IVector :
	IInspectable,
	impl_IVector<IVector<T>, T>,
	requires<IVector<T>, IIterable<T>>
{
	IVector(std::nullptr_t = nullptr) noexcept {}
	auto operator->() const noexcept { return ptr<IVector>(m_ptr); }

	IVector(std::vector<T> const & other);
	IVector(std::vector<T> && other);
	IVector(std::initializer_list<T> other);
};

template <typename K, typename V>
struct IMapView :
	IInspectable,
	impl_IMapView<IMapView<K, V>, K, V>,
	requires<IMapView<K, V>, IIterable<IKeyValuePair<K, V>>>
{
	IMapView(std::nullptr_t = nullptr) noexcept {}
	auto operator->() const noexcept { return ptr<IMapView>(m_ptr); }
};

template <typename K, typename V>
struct IMap :
	IInspectable,
	impl_IMap<IMap<K, V>, K, V>,
	requires<IMap<K, V>, IIterable<IKeyValuePair<K, V>>>
{
	IMap(std::nullptr_t = nullptr) noexcept {}
	auto operator->() const noexcept { return ptr<IMap>(m_ptr); }
};

template <typename K>
struct IMapChangedEventArgs :
	IInspectable,
	impl_IMapChangedEventArgs<IMapChangedEventArgs<K>, K>
{
	IMapChangedEventArgs(std::nullptr_t = nullptr) noexcept {}
	auto operator->() const noexcept { return ptr<IMapChangedEventArgs>(m_ptr); }
};

template <typename K, typename V>
struct IMapChangedEventHandler :
	IUnknown,
	impl_IMapChangedEventHandler<IMapChangedEventHandler<K, V>, K, V>
{
	IMapChangedEventHandler(std::nullptr_t = nullptr) noexcept {}
	auto operator->() const noexcept { return ptr<IMapChangedEventHandler>(m_ptr); }
};

template <typename K, typename V>
struct IObservableMap :
	IInspectable,
	impl_IObservableMap<IObservableMap<K, V>, K, V>,
	requires<IObservableMap<K, V>, IMap<K, V>, IIterable<IKeyValuePair<K, V>>>
{
	IObservableMap(std::nullptr_t = nullptr) noexcept {}
	auto operator->() const noexcept { return ptr<IObservableMap>(m_ptr); }
};

template <typename T>
struct IVectorChangedEventHandler :
	IUnknown,
	impl_IVectorChangedEventHandler<IVectorChangedEventHandler<T>, T>
{
	IVectorChangedEventHandler(std::nullptr_t = nullptr) noexcept {}
	auto operator->() const noexcept { return ptr<IVectorChangedEventHandler>(m_ptr); }
};

template <typename T>
struct IObservableVector :
	IInspectable,
	impl_IObservableVector<IObservableVector<T>, T>,
	requires<IObservableVector<T>, IVector<T>, IIterable<T>>
{
	IObservableVector(std::nullptr_t = nullptr) noexcept {}
	auto operator->() const noexcept { return ptr<IObservableVector>(m_ptr); }
};

}}}}

namespace winrt { namespace impl {

template <typename T> struct traits<Windows::Foundation::Collections::IIterator<T>>
{
	using abi = ABI::Windows::Foundation::Collections::IIterator<abi<T>>;
	template <typename D> using methods = Windows::Foundation::Collections::impl_IIterator<D, T>;
};

template <typename T> struct traits<Windows::Foundation::Collections::IIterable<T>>
{
	using abi = ABI::Windows::Foundation::Collections::IIterable<abi<T>>;
	template <typename D> using methods = Windows::Foundation::Collections::impl_IIterable<D, T>;
};

template <typename K, typename V> struct traits<Windows::Foundation::Collections::IKeyValuePair<K, V>>
{
	using abi = ABI::Windows::Foundation::Collections::IKeyValuePair<abi<K>, abi<V>>;
	template <typename D> using methods = Windows::Foundation::Collections::impl_IKeyValuePair<D, K, V>;
};

template <typename T> struct traits<Windows::Foundation::Collections::IVectorView<T>>
{
	using abi = ABI::Windows::Foundation::Collections::IVectorView<abi<T>>;
	template <typename D> using methods = Windows::Foundation::Collections::impl_IVectorView<D, T>;
};

template <typename T> struct traits<Windows::Foundation::Collections::IVector<T>>
{
	using abi = ABI::Windows::Foundation::Collections::IVector<abi<T>>;
	template <typename D> using methods = Windows::Foundation::Collections::impl_IVector<D, T>;
};

template <typename K, typename V> struct traits<Windows::Foundation::Collections::IMapView<K, V>>
{
	using abi = ABI::Windows::Foundation::Collections::IMapView<abi<K>, abi<V>>;
	template <typename D> using methods = Windows::Foundation::Collections::impl_IMapView<D, K, V>;
};

template <typename K, typename V> struct traits<Windows::Foundation::Collections::IMap<K, V>>
{
	using abi = ABI::Windows::Foundation::Collections::IMap<abi<K>, abi<V>>;
	template <typename D> using methods = Windows::Foundation::Collections::impl_IMap<D, K, V>;
};

template <typename K> struct traits<Windows::Foundation::Collections::IMapChangedEventArgs<K>>
{
	using abi = ABI::Windows::Foundation::Collections::IMapChangedEventArgs<abi<K>>;
	template <typename D> using methods = Windows::Foundation::Collections::impl_IMapChangedEventArgs<D, K>;
};

template <typename K, typename V> struct traits<Windows::Foundation::Collections::IMapChangedEventHandler<K, V>>
{
	using abi = ABI::Windows::Foundation::Collections::IMapChangedEventHandler<abi<K>, abi<V>>;
	template <typename D> using methods = Windows::Foundation::Collections::impl_IMapChangedEventHandler<D, K, V>;
};

template <typename K, typename V> struct traits<Windows::Foundation::Collections::IObservableMap<K, V>>
{
	using abi = ABI::Windows::Foundation::Collections::IObservableMap<abi<K>, abi<V>>;
	template <typename D> using methods = Windows::Foundation::Collections::impl_IObservableMap<D, K, V>;
};

template <typename T> struct traits<Windows::Foundation::Collections::IVectorChangedEventHandler<T>>
{
	using abi = ABI::Windows::Foundation::Collections::IVectorChangedEventHandler<abi<T>>;
	template <typename D> using methods = Windows::Foundation::Collections::impl_IVectorChangedEventHandler<D, T>;
};

template <typename T> struct traits<Windows::Foundation::Collections::IObservableVector<T>>
{
	using abi = ABI::Windows::Foundation::Collections::IObservableVector<abi<T>>;
	template <typename D> using methods = Windows::Foundation::Collections::impl_IObservableVector<D, T>;
};

}}


namespace winrt { namespace impl {

template <typename T>
struct fast_iterator : std::iterator<std::input_iterator_tag, T>
{
	fast_iterator(T const & collection, unsigned const index) noexcept :
		m_collection(&collection),
		m_index(index)
	{}

	fast_iterator & operator++() noexcept
	{
		++m_index;
		return *this;
	}

	auto operator *() const
	{
		return m_collection->GetAt(m_index);
	}

	bool operator==(fast_iterator const & other) const noexcept
	{
		WINRT_ASSERT(m_collection == other.m_collection);
		return m_index == other.m_index;
	}

	bool operator!=(fast_iterator const & other) const noexcept
	{
		return !(*this == other);
	}

private:

	T const * m_collection = nullptr;
	unsigned m_index = 0;
};

}}

namespace winrt { namespace Windows { namespace Foundation { namespace Collections {

template <typename T, typename std::enable_if<!impl::has_GetAt<T>::value>::type * = nullptr>
auto begin(T const & collection) -> decltype(collection.First())
{
	auto result = collection.First();

	if (!result.HasCurrent())
	{
		return {};
	}

	return result;
}

template <typename T, typename std::enable_if<!impl::has_GetAt<T>::value>::type * = nullptr>
auto end(T const & collection) -> decltype(collection.First())
{
	collection;
	return {};
}

template <typename T, typename std::enable_if<impl::has_GetAt<T>::value>::type * = nullptr>
impl::fast_iterator<T> begin(T const & collection) noexcept
{
	return impl::fast_iterator<T>(collection, 0);
}

template <typename T, typename std::enable_if<impl::has_GetAt<T>::value>::type * = nullptr>
impl::fast_iterator<T> end(T const & collection)
{
	return impl::fast_iterator<T>(collection, collection.Size());
}

}}}}

namespace winrt { namespace Windows { namespace Foundation { namespace Collections {

template <typename T>
struct impl_VectorIterator : impl::implements<IIterator<T>>
{
	IVectorView<T> v;
	unsigned i = 0;

	impl_VectorIterator(abi_arg_in<IVectorView<T>> other)
	{
		copy_from(v, other);
	}

	virtual HRESULT __stdcall get_Current(abi_arg_out<T> current) noexcept override
	{
		return v->abi_GetAt(i, current);
	}

	virtual HRESULT __stdcall get_HasCurrent(bool * hasCurrent) noexcept override
	{
		try
		{
			*hasCurrent = i < v.Size();
			return S_OK;
		}
		catch (...) { return impl::to_hresult(); }
	}

	virtual HRESULT __stdcall abi_MoveNext(bool * hasCurrent) noexcept override
	{
		try
		{
			if (i + 1 < v.Size())
			{
				++i;
				*hasCurrent = true;
			}
			else
			{
				*hasCurrent = false;
			}

			return S_OK;
		}
		catch (...) { return impl::to_hresult(); }
	}

	virtual HRESULT __stdcall abi_GetMany(unsigned /*capacity*/, abi_arg_out<T> /*value*/, unsigned * /*actual*/) noexcept override
	{
		return E_NOTIMPL;
	}
};

template <typename T>
struct impl_Vector : impl::implements<IVector<T>, IVectorView<T>, IIterable<T>>
{
	std::vector<T> v;

	impl_Vector(std::vector<T> const & other) :
		v(other)
	{}

	impl_Vector(std::vector<T> && other) :
		v(std::move(other))
	{}

	virtual HRESULT __stdcall abi_GetAt(unsigned index, abi_arg_out<T> item) noexcept override
	{
		try
		{
			copy_to(v.at(index), *item);
			return S_OK;
		}
		catch (...) { return impl::to_hresult(); }
	}

	virtual HRESULT __stdcall get_Size(unsigned * size) noexcept override
	{
		*size = static_cast<unsigned>(v.size());
		return S_OK;
	}

	virtual HRESULT __stdcall abi_GetView(IVectorView<abi<T>> ** view) noexcept override
	{
		*view = this;
		static_cast<::IUnknown *>(*view)->AddRef();
		return S_OK;
	}

	virtual HRESULT __stdcall abi_IndexOf(abi_arg_in<T> value, unsigned * index, bool * found) noexcept override
	{
		try
		{
			*index = static_cast<unsigned>(std::find(begin(v), end(v), impl::forward<T>(value)) - begin(v));
			*found = *index < v.size();
			return S_OK;
		}
		catch (...) { return impl::to_hresult(); }
	}

	virtual HRESULT __stdcall abi_SetAt(unsigned index, abi_arg_in<T> item) noexcept override
	{
		try
		{
			copy_from(v.at(index), item);
			return S_OK;
		}
		catch (...) { return impl::to_hresult(); }
	}

	virtual HRESULT __stdcall abi_InsertAt(unsigned index, abi_arg_in<T> item) noexcept override
	{
		if (index > v.size())
		{
			return E_BOUNDS;
		}

		try
		{
			copy_from(*v.emplace(begin(v) + index), item);
			return S_OK;
		}
		catch (...) { return impl::to_hresult(); }
	}

	virtual HRESULT __stdcall abi_RemoveAt(unsigned index) noexcept override
	{
		if (index >= v.size())
		{
			return E_BOUNDS;
		}

		try
		{
			v.erase(begin(v) + index);
			return S_OK;
		}
		catch (...) { return impl::to_hresult(); }
	}

	virtual HRESULT __stdcall abi_Append(abi_arg_in<T> item) noexcept override
	{
		try
		{
			v.emplace_back();
			copy_from(v.back(), item);
			return S_OK;
		}
		catch (...) { return impl::to_hresult(); }
	}

	virtual HRESULT __stdcall abi_RemoveAtEnd() noexcept override
	{
		if (v.empty())
		{
			return E_BOUNDS;
		}

		try
		{
			v.pop_back();
			return S_OK;
		}
		catch (...) { return impl::to_hresult(); }
	}

	virtual HRESULT __stdcall abi_Clear() noexcept override
	{
		v.clear();
		return S_OK;
	}

	virtual HRESULT __stdcall abi_GetMany(unsigned startIndex, unsigned capacity, abi_arg_out<T> /*value*/, unsigned * actual) noexcept override
	{
		try
		{
			*actual = static_cast<unsigned>(v.size() - startIndex);

			if (*actual > capacity)
			{
				*actual = capacity;
			}

			for (unsigned i = 0; i != *actual; ++i)
			{
				//value[i] = v[startIndex + i];
			}

			return S_OK;
		}
		catch (...) { return impl::to_hresult(); }
	}

	virtual HRESULT __stdcall abi_ReplaceAll(unsigned /*count*/, abi_arg_out<T> /*value*/) noexcept override
	{
		try
		{
			// v.assign(value, value + count);
			return S_OK;
		}
		catch (...) { return impl::to_hresult(); }
	}

	virtual HRESULT __stdcall abi_First(abi_arg_out<IIterator<T>> first) noexcept override
	{
		try
		{
			*first = detach(make<impl_VectorIterator<T>>(this));
			return S_OK;
		}
		catch (...) { return impl::to_hresult(); }
	}
};

template <typename T> IVector<T>::IVector(std::vector<T> const & other) : IVector<T>(make<impl_Vector<T>>(other)) {}

template <typename T> IVector<T>::IVector(std::vector<T> && other) : IVector<T>(make<impl_Vector<T>>(std::move(other))) {}

template <typename T> IVector<T>::IVector(std::initializer_list<T> other) : IVector<T>(make<impl_Vector<T>>(other)) {}

}}}}

namespace winrt { namespace ABI { namespace Windows {

struct __declspec(uuid("00000037-0000-0000-C000-000000000046")) __declspec(novtable) IWeakReference : ::IUnknown
{
	virtual HRESULT __stdcall abi_Resolve(GUID const & iid, ::IInspectable ** objectReference) = 0;

	template <typename Qi> HRESULT __stdcall abi_Resolve(Qi ** objectReference) noexcept
	{
		return abi_Resolve(__uuidof(Qi), reinterpret_cast<::IInspectable **>(objectReference));
	}
};

struct __declspec(uuid("00000038-0000-0000-C000-000000000046")) __declspec(novtable) IWeakReferenceSource : ::IUnknown
{
	virtual HRESULT __stdcall abi_GetWeakReference(IWeakReference ** weakReference) = 0;
};

}}}

namespace winrt { namespace Windows {

struct IWeakReference;
struct IWeakReferenceSource;

template <typename T>
class impl_IWeakReference
{
	auto shim() const { return impl::shim<T, IWeakReference>(this); }

public:

	template <typename Qi> Qi Resolve() const noexcept;
};

template <typename T>
class impl_IWeakReferenceSource
{
	auto shim() const { return impl::shim<T, IWeakReferenceSource>(this); }

public:

	IWeakReference GetWeakReference() const;
};

}}

namespace winrt { namespace impl {

template <> struct traits<Windows::IWeakReference>
{
	using abi = ABI::Windows::IWeakReference;
	template <typename T> using methods = Windows::impl_IWeakReference<T>;
};

template <> struct traits<Windows::IWeakReferenceSource>
{
	using abi = ABI::Windows::IWeakReferenceSource;
	template <typename T> using methods = Windows::impl_IWeakReferenceSource<T>;
};

}}

namespace winrt { namespace Windows {

struct IWeakReference :
	IUnknown,
	impl_IWeakReference<IWeakReference>
{
	IWeakReference(std::nullptr_t = nullptr) noexcept {}
	auto operator->() const noexcept { return ptr<IWeakReference>(m_ptr); }
};

struct IWeakReferenceSource :
	IUnknown,
	impl_IWeakReferenceSource<IWeakReferenceSource>
{
	IWeakReferenceSource(std::nullptr_t = nullptr) noexcept {}
	auto operator->() const noexcept { return ptr<IWeakReferenceSource>(m_ptr); }
};

template <typename T> template <typename Qi> Qi impl_IWeakReference<T>::Resolve() const noexcept
{
	Qi objectReference = nullptr;

	if (S_OK == shim()->abi_Resolve(put(objectReference)))
	{
		return objectReference;
	}

	return nullptr;
}

template <typename T> IWeakReference impl_IWeakReferenceSource<T>::GetWeakReference() const
{
	IWeakReference weakReference;
	check_hresult(shim()->abi_GetWeakReference(put(weakReference)));
	return weakReference;
}

}}

namespace winrt {

template <typename T>
struct weak
{
	weak(std::nullptr_t) {}
	weak(T const & object) : m_ref(object.As<Windows::IWeakReferenceSource>().GetWeakReference()) {}

	T resolve() const noexcept
	{
		return m_ref.Resolve<T>();
	}

private:

	Windows::IWeakReference m_ref;
};

template <typename T>
weak<T> make_weak(T const & object)
{
	return object;
}

}

namespace std {

template <> struct hash<winrt::hstring> : unary_function<winrt::hstring, size_t>
{
	size_t operator()(winrt::hstring const & value) const
	{
		unsigned length = 0;
		wchar_t const * const buffer = WindowsGetStringRawBuffer(get(value), &length);

		return _Hash_seq(reinterpret_cast<const unsigned char *>(buffer), length * sizeof(wchar_t));
	}
};

}
