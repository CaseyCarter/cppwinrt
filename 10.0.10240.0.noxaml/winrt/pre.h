// C++ for the Windows Runtime v1.29 - http://moderncpp.com
// Copyright (c) 2015 Microsoft Corporation

#pragma comment(lib, "runtimeobject")
#pragma comment(lib, "ole32")

#include <inspectable.h>
#include <winstring.h>
#include <ctxtcall.h>
#include <set>
#include <memory>
#include <vector>
#include <utility>
#include <type_traits>

extern "C"
{
	enum RO_INIT_TYPE;

	BOOL __stdcall RoOriginateErrorW(HRESULT error, unsigned length, wchar_t const * message);
	HRESULT __stdcall RoInitialize(RO_INIT_TYPE type);
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

struct Exception
{
	HRESULT Result;

	explicit Exception(HRESULT const value) : Result(value)
	{}

	template <unsigned Count>
	Exception(HRESULT const value, wchar_t const (&message)[Count]) : Result(value)
	{
		RoOriginateErrorW(value, Count - 1, message);
	}
};

inline void check(HRESULT const result)
{
	if (S_OK == result)
	{
		return;
	}

	if (E_OUTOFMEMORY == result)
	{
		throw std::bad_alloc();
	}

	throw Exception(result);
}

template <typename T>
HRESULT call(T inner) noexcept
{
	try
	{
		inner();
	}
	catch (Exception const & e)
	{
		return e.Result;
	}
	catch (std::bad_alloc const &)
	{
		return E_OUTOFMEMORY;
	}
	catch (std::exception const &)
	{
		return E_FAIL;
	}

	return S_OK;
}

}
namespace winrt { namespace impl {

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

	static void copy(T & object, T const & value) noexcept
	{
		object = value;
	}

	static T detach(T & object) noexcept
	{
		return object;
	}
};

}}

namespace winrt {

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

template <typename T, typename V>
void attach(T & object, V && value) noexcept
{
	impl::accessors<T>::attach(object, value);
}

template <typename T, typename V>
void copy(T & object, V && value) noexcept
{
	impl::accessors<T>::copy(object, value);
}

template <typename T>
auto detach(T & object) noexcept
{
	return impl::accessors<T>::detach(object);
}

template <typename T>
auto detach(T && object) noexcept
{
	return impl::accessors<T>::detach(object);
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
class no_ref : public T
{
	unsigned long __stdcall AddRef();
	unsigned long __stdcall Release();
};

template <typename To>
struct lease : To
{
	template <typename From>
	lease(From value) noexcept : To(nullptr)
	{
		*put(*static_cast<To *>(this)) = value;
	}

	~lease() noexcept
	{
		detach(*static_cast<To *>(this));
	}
};

template <typename To, typename From, typename std::enable_if<std::is_pod<To>::value>::type * = nullptr>
To forward(From value) noexcept
{
	return value;
}

template <typename To, typename From, typename std::enable_if<!std::is_pod<To>::value>::type * = nullptr>
lease<To> forward(From value) noexcept
{
	return lease<To>(value);
}

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
	return static_cast<Qi const &>(static_cast<Crtp const &>(*base));
}

template <typename T, typename R>
struct requires : traits<R>::template methods<requires<T, R>>
{
	operator R() const noexcept
	{
		return static_cast<T const *>(this)->As<R>();
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


}

namespace winrt { namespace impl {

template <typename First, typename ... Rest>
struct implements : winrt::implements<abi<First>, abi<Rest> ..., ::IAgileObject>
{
	using default_interface = First;
};

}}

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

	static void copy(String & object, HSTRING value)
	{
		object = nullptr;
		check(WindowsDuplicateString(value, put(object)));
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

namespace winrt {

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

	static void copy(com_ptr<T> & object, T * value)
	{
		object = nullptr;

		if (value)
		{
			value->AddRef();
			*put(object) = value;
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
		check(m_ptr->QueryInterface(put(temp)));
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

	static void copy(T & object, abi_arg_in<T> value) noexcept
	{
		object = nullptr;

		if (value)
		{
			value->AddRef();
			*put(object) = value;
		}
	}

	static auto detach(T & object) noexcept
	{
		return static_cast<abi_arg_in<T>>(impl_detach(object));
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

	String GetRuntimeClassName() const;
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

template <typename T> String impl_IInspectable<T>::GetRuntimeClassName() const
{
	String name;
	check(shim()->get_RuntimeClassName(put(name)));
	return name;
}

template <typename T> unsigned impl_IAsyncInfo<T>::Id() const
{
	unsigned id = 0;
	check(shim()->get_Id(&id));
	return id;
}

template <typename T> AsyncStatus impl_IAsyncInfo<T>::Status() const
{
	AsyncStatus status = {};
	check(shim()->get_Status(&status));
	return status;
}

template <typename T> HRESULT impl_IAsyncInfo<T>::ErrorCode() const
{
	HRESULT code = S_OK;
	check(shim()->get_ErrorCode(&code));
	return code;
}

template <typename T> void impl_IAsyncInfo<T>::Cancel() const
{
	check(shim()->abi_Cancel());
}

template <typename T> void impl_IAsyncInfo<T>::Close() const
{
	check(shim()->abi_Close());
}

template <typename T> IInspectable impl_IActivationFactory<T>::ActivateInstance() const
{
	IInspectable instance;
	check(shim()->abi_ActivateInstance(put(instance)));
	return instance;
}

}}

namespace winrt {

template <typename ... R>
struct overrides : implements<R ...>
{
	template <typename T>
	T As() const
	{
		return m_inner.As<T>();
	}

	virtual HRESULT __stdcall QueryInterface(GUID const & id, void ** object) noexcept override
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

namespace winrt { namespace impl {

inline void ActivateInstance(HSTRING classId, Windows::IInspectable & instance)
{
	check(RoActivateInstance(classId, put(instance)));
}

template <typename Interface>
void ActivateInstance(HSTRING classId, Interface & result)
{
	Windows::IInspectable instance;
	ActivateInstance(classId, instance);
	result = instance.As<Interface>();
}

}}

namespace winrt {

enum class InitializeType
{
	SingleThreaded,
	MultiThreaded
};

inline void Initialize(InitializeType const type = InitializeType::MultiThreaded)
{
	check(RoInitialize(static_cast<RO_INIT_TYPE>(type)));
}

template <typename Class, typename Instance = Class>
Instance ActivateInstance()
{
	StringReference classId(impl::traits<Class>::name(),
							impl::traits<Class>::name_length);

	Instance instance = nullptr;
	impl::ActivateInstance(get(classId), instance);
	return instance;
}

template <typename Class, typename Interface = Windows::IActivationFactory>
Interface GetActivationFactory()
{
	StringReference classId(impl::traits<Class>::name(),
							impl::traits<Class>::name_length);

	Interface factory;
	check(RoGetActivationFactory(get(classId), __uuidof(abi<Interface>), reinterpret_cast<void **>(put(factory))));
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
		check(shim()->abi_Invoke(get(sender), get(args)));
	}
};

template <typename D, typename TProgress>
class impl_IAsyncActionWithProgress
{
	auto shim() const { return impl::shim<D, IAsyncActionWithProgress<TProgress>>(this); }

public:

	void Progress(IAsyncActionProgressHandler<TProgress> const & handler) const
	{
		check(shim()->put_Progress(get(handler)));
	}

	template <typename Handler>
	void Progress(Handler handler) const
	{
		return Progress(AsyncActionProgressHandler<TProgress>(handler));
	}

	IAsyncActionProgressHandler<TProgress> Progress() const
	{
		IAsyncActionProgressHandler<TProgress> handler;
		check(shim()->get_Progress(put(handler)));
		return handler;
	}

	void Completed(IAsyncActionWithProgressCompletedHandler<TProgress> const & handler) const
	{
		check(shim()->put_Completed(get(handler)));
	}

	template <typename Handler>
	void Completed(Handler handler) const
	{
		return Completed(AsyncActionWithProgressCompletedHandler<TProgress>(handler));
	}

	IAsyncActionWithProgressCompletedHandler<TProgress> Completed() const
	{
		IAsyncActionWithProgressCompletedHandler<TProgress> handler;
		check(shim()->get_Completed(put(handler)));
		return handler;
	}

	void GetResults() const
	{
		check(shim()->abi_GetResults());
	}
};

template <typename D, typename TProgress>
class impl_IAsyncActionWithProgressCompletedHandler
{
	auto shim() const { return impl::shim<D, IAsyncActionWithProgressCompletedHandler<TProgress>>(this); }

public:

	void Invoke(IAsyncActionWithProgress<TProgress> const & sender, AsyncStatus const args) const
	{
		check(shim()->abi_Invoke(get(sender), args));
	}
};

template <typename D, typename TResult, typename TProgress>
class impl_IAsyncOperationProgressHandler
{
	auto shim() const { return impl::shim<D, IAsyncOperationProgressHandler<TResult, TProgress>>(this); }

public:

	void Invoke(IAsyncOperationWithProgress<TResult, TProgress> const & sender, TProgress const & args) const
	{
		check(shim()->abi_Invoke(get(sender), get(args)));
	}
};

template <typename D, typename TResult, typename TProgress>
class impl_IAsyncOperationWithProgressCompletedHandler
{
	auto shim() const { return impl::shim<D, IAsyncOperationWithProgressCompletedHandler<TResult, TProgress>>(this); }

public:

	void Invoke(IAsyncOperationWithProgress<TResult, TProgress> const & sender, AsyncStatus const args) const
	{
		check(shim()->abi_Invoke(get(sender), args));
	}
};

template <typename D, typename TResult>
class impl_IAsyncOperationCompletedHandler
{
	auto shim() const { return impl::shim<D, IAsyncOperationCompletedHandler<TResult>>(this); }

public:

	void Invoke(IAsyncOperation<TResult> const & sender, AsyncStatus const args) const
	{
		check(shim()->abi_Invoke(get(sender), args));
	}
};

template <typename D, typename T>
class impl_IEventHandler
{
	auto shim() const { return impl::shim<D, IEventHandler<T>>(this); }

public:

	void Invoke(IInspectable const & sender, T const & args) const
	{
		check(shim()->abi_Invoke(get(sender), get(args)));
	}
};

template <typename D, typename TSender, typename TArgs>
class impl_ITypedEventHandler
{
	auto shim() const { return impl::shim<D, ITypedEventHandler<TSender, TArgs>>(this); }

public:

	void Invoke(TSender const & sender, TArgs const & args) const
	{
		check(shim()->abi_Invoke(get(sender), get(args)));
	}
};

template <typename D, typename TResult>
class impl_IAsyncOperation
{
	auto shim() const { return impl::shim<D, IAsyncOperation<TResult>>(this); }

public:

	void Completed(IAsyncOperationCompletedHandler<TResult> const & handler) const
	{
		check(shim()->put_Completed(get(handler)));
	}

	template <typename Handler>
	void Completed(Handler handler) const
	{
		return Completed(AsyncOperationCompletedHandler<TResult>(handler));
	}

	IAsyncOperationCompletedHandler<TResult> Completed() const
	{
		IAsyncOperationCompletedHandler<TResult> temp;
		check(shim()->get_Completed(put(temp)));
		return temp;
	}

	TResult GetResults() const
	{
		TResult result = impl::argument<TResult>::empty();
		check(shim()->abi_GetResults(put(result)));
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
		check(shim()->put_Progress(get(handler)));
	}

	template <typename Handler>
	void Progress(Handler handler) const
	{
		return Progress(AsyncOperationProgressHandler<TResult, TProgress>(handler));
	}

	IAsyncOperationProgressHandler<TResult, TProgress> Progress() const
	{
		IAsyncOperationProgressHandler<TResult, TProgress> handler;
		check(shim()->get_Progress(put(handler)));
		return handler;
	}

	void Completed(IAsyncOperationWithProgressCompletedHandler<TResult, TProgress> const & handler) const
	{
		check(shim()->put_Completed(get(handler)));
	}

	template <typename Handler>
	void Completed(Handler handler) const
	{
		return Completed(AsyncOperationWithProgressCompletedHandler<TResult, TProgress>(handler));
	}

	IAsyncOperationWithProgressCompletedHandler<TResult, TProgress> Completed() const
	{
		IAsyncOperationWithProgressCompletedHandler<TResult, TProgress> handler;
		check(shim()->get_Completed(put(handler)));
		return handler;
	}

	TResult GetResults() const
	{
		TResult result = impl::argument<TResult>::empty();
		check(shim()->abi_GetResults(put(result)));
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
		check(shim()->get_Value(put(result)));
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

	virtual HRESULT __stdcall abi_Invoke(abi_arg_in<IAsyncActionWithProgress<TProgress>> sender, abi_arg_in<TProgress> args) noexcept override
	{
		return call([&]
		{
			(*this)(impl::forward<IAsyncActionWithProgress<TProgress>>(sender), impl::forward<TProgress>(args));
		});
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

	virtual HRESULT __stdcall abi_Invoke(abi_arg_in<IAsyncActionWithProgress<TProgress>> sender, AsyncStatus args) noexcept override
	{
		return call([&]
		{
			(*this)(impl::forward<IAsyncActionWithProgress<TProgress>>(sender), args);
		});
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

	virtual HRESULT __stdcall abi_Invoke(abi_arg_in<IAsyncOperationWithProgress<TResult, TProgress>> sender, abi_arg_in<TProgress> args) noexcept override
	{
		return call([&]
		{
			(*this)(impl::forward<IAsyncOperationWithProgress<TResult, TProgress>>(sender), impl::forward<TProgress>(args));
		});
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

	virtual HRESULT __stdcall abi_Invoke(abi_arg_in<IAsyncOperationWithProgress<TResult, TProgress>> sender, AsyncStatus args) noexcept override
	{
		return call([&]
		{
			(*this)(impl::forward<IAsyncOperationWithProgress<TResult, TProgress>>(sender), args);
		});
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

	virtual HRESULT __stdcall abi_Invoke(abi_arg_in<IAsyncOperation<TResult>> sender, AsyncStatus args) noexcept override
	{
		return call([&]
		{
			(*this)(impl::forward<IAsyncOperation<TResult>>(sender), args);
		});
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

	virtual HRESULT __stdcall abi_Invoke(abi_arg_in<IInspectable> sender, abi_arg_in<TArgs> args) noexcept override
	{
		return call([&]
		{
			(*this)(impl::forward<IInspectable>(sender), impl::forward<TArgs>(args));
		});
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

	virtual HRESULT __stdcall abi_Invoke(abi_arg_in<TSender> sender, abi_arg_in<TArgs> args) noexcept override
	{
		return call([&]
		{
			(*this)(impl::forward<TSender>(sender), impl::forward<TArgs>(args));
		});
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
	check(shim()->get_CollectionChange(&value));
	return value;
}

template <typename T> unsigned impl_IVectorChangedEventArgs<T>::Index() const
{
	unsigned index = 0;
	check(shim()->get_Index(&index));
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
		check(shim()->get_Current(put(result)));
		return result;
	}

	bool HasCurrent() const
	{
		bool temp = false;
		check(shim()->get_HasCurrent(&temp));
		return temp;
	}

	bool MoveNext() const
	{
		bool temp = false;
		check(shim()->abi_MoveNext(&temp));
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
		check(shim()->abi_First(put(iterator)));
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
		check(shim()->get_Key(put(result)));
		return result;
	}

	V Value() const
	{
		V result = impl::argument<V>::empty();
		check(shim()->get_Value(put(result)));
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
		check(shim()->abi_GetAt(index, put(result)));
		return result;
	}

	unsigned Size() const
	{
		unsigned size = 0;
		check(shim()->get_Size(&size));
		return size;
	}

	bool IndexOf(T const & value, unsigned & index) const
	{
		bool found = false;
		check(shim()->abi_IndexOf(get(value), &index, &found));
		return 0 != found;
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
		check(shim()->abi_GetAt(index, put(result)));
		return result;
	}

	unsigned Size() const
	{
		unsigned size = 0;
		check(shim()->get_Size(&size));
		return size;
	}

	IVectorView<T> GetView() const
	{
		IVectorView<T> view;
		check(shim()->abi_GetView(put(view)));
		return view;
	}

	bool IndexOf(T const & value, unsigned & index) const
	{
		bool found = false;
		check(shim()->abi_IndexOf(get(value), &index, &found));
		return 0 != found;
	}

	void SetAt(unsigned const index, T const & value) const
	{
		check(shim()->abi_SetAt(index, get(value)));
	}

	void InsertAt(unsigned const index, T const & value) const
	{
		check(shim()->abi_InsertAt(index, get(value)));
	}

	void RemoveAt(unsigned const index) const
	{
		check(shim()->abi_RemoveAt(index));
	}

	void Append(T const & value) const
	{
		check(shim()->abi_Append(get(value)));
	}

	void RemoveAtEnd() const
	{
		check(shim()->abi_RemoveAtEnd());
	}

	void Clear() const
	{
		check(shim()->abi_Clear());
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
		check(shim()->abi_Lookup(get(key), put(result)));
		return result;
	}

	unsigned Size() const
	{
		unsigned size = 0;
		check(shim()->get_Size(&size));
		return size;
	}

	bool HasKey(K const & key) const
	{
		bool found = false;
		check(shim()->abi_HasKey(get(key), &found));
		return 0 != found;
	}

	void Split(IMapView<K, V> & firstPartition, IMapView<K, V> & secondPartition)
	{
		check(shim()->abi_Split(put(firstPartition), put(secondPartition)));
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
		check(shim()->abi_Lookup(get(key), put(result)));
		return result;
	}

	unsigned Size() const
	{
		unsigned size = 0;
		check(shim()->get_Size(&size));
		return size;
	}

	bool HasKey(K const & key) const
	{
		bool found = false;
		check(shim()->abi_HasKey(get(key), &found));
		return 0 != found;
	}

	IMapView<K, V> GetView() const
	{
		IMapView<K, V> view;
		check(shim()->abi_GetView(put(view)));
		return view;
	}

	bool Insert(K const & key, V const & value) const
	{
		bool replaced = false;
		check(shim()->abi_Insert(get(key), get(value), &replaced));
		return 0 != replaced;
	}

	void Remove(K const & key) const
	{
		check(shim()->abi_Remove(get(key)));
	}

	void Clear() const
	{
		check(shim()->abi_Clear());
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
		check(shim()->get_CollectionChange(&value));
		return value;
	}

	K Key() const
	{
		K result = impl::argument<K>::empty();
		check(shim()->get_Key(put(result)));
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
		check(shim()->abi_Invoke(get(sender), get(args)));
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
		check(shim()->add_MapChanged(get(handler), &cookie));
		return cookie;
	}

	template <typename T> long long MapChanged(T handler) const
	{
		return MapChanged(MapChangedEventHandler<K, V>(handler));
	}

	void MapChanged(long long const cookie) const
	{
		check(shim()->remove_MapChanged(cookie));
	}
};

template <typename D, typename T>
class impl_IVectorChangedEventHandler
{
	auto shim() const { return impl::shim<D, IVectorChangedEventHandler<T>>(this); }

public:

	void Invoke(IObservableVector<T> const & sender, IVectorChangedEventArgs const & args) const
	{
		check(shim()->abi_Invoke(get(sender), get(args)));
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
		check(shim()->add_VectorChanged(get(handler), &cookie));
		return cookie;
	}

	template <typename Handler> long long VectorChanged(Handler handler) const
	{
		return VectorChanged(VectorChangedEventHandler<T>(handler));
	}

	void VectorChanged(long long const cookie) const
	{
		check(shim()->remove_VectorChanged(cookie));
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
struct fast_iterator
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
