// Modern v1.22 - http://moderncpp.com
// Copyright (c) 2015 Kenny Kerr

#pragma once

#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#undef GetCurrentTime
#pragma comment(lib, "runtimeobject")

#include <modern\implements.h>
#include <modern\comptr.h>
#include <modern\handle.h>
#include <inspectable.h>
#include <eventtoken.h>
#include <winstring.h>
#include <set>
#include <memory>
#include <vector>

extern "C"
{
	enum RO_INIT_TYPE;

	BOOL __stdcall RoOriginateErrorW(HRESULT error, unsigned length, wchar_t const * message);
	HRESULT __stdcall RoInitialize(RO_INIT_TYPE type);
	HRESULT __stdcall RoGetActivationFactory(HSTRING classId, GUID const & iid, void ** factory);
	HRESULT __stdcall RoActivateInstance(HSTRING classId, ::IInspectable ** instance);
}

namespace Modern {

enum class AsyncStatus
{
	Started = 0,
	Completed,
	Canceled,
	Error,
};

enum class InitializeType
{
	SingleThreaded,
	MultiThreaded
};

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
	if (result == S_OK)
	{
		return;
	}

	throw Exception(result);
}

inline void Initialize(InitializeType const type = InitializeType::MultiThreaded)
{
	check(RoInitialize(static_cast<RO_INIT_TYPE>(type)));
}

struct BoolProxy
{
	BoolProxy & operator=(BoolProxy const &) = delete;

	BoolProxy(bool & value) noexcept :
		m_value(value)
	{}

	~BoolProxy() noexcept
	{
		m_value = 0 != m_abi;
	}

	operator boolean * () noexcept
	{
		return &m_abi;
	}

private:

	boolean m_abi = 0;
	bool & m_value;
};

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


struct StringReference
{
	StringReference(StringReference const &) = delete;
	StringReference & operator=(StringReference const &) = delete;

	StringReference(wchar_t const * const value, unsigned length)
	{
		check(WindowsCreateStringReference(value, length, &m_header, &m_string));
	}

	template <unsigned Count>
	StringReference(wchar_t const (&value)[Count]) :
		StringReference(value, Count - 1)
	{}

	friend HSTRING get(StringReference const & string) noexcept
	{
		return string.m_string;
	}

private:

	HSTRING_HEADER m_header;
	HSTRING m_string;
};

struct String
{
	String() noexcept = default;
	String(String && other) noexcept = default;
	String & operator=(String && other) noexcept = default;

	String(std::nullptr_t) noexcept {}

	String(wchar_t const * value, unsigned const length) :
		m_handle(CreateString(value, length))
	{}

	template <unsigned Count>
	String(wchar_t const (&value)[Count]) :
		String(value, Count - 1)
	{}

	String(wchar_t const * value) :
		String(value, static_cast<unsigned>(wcslen(value)))
	{}

	String(String const & other) :
		m_handle(DuplicateString(get(other)))
	{}

	String & operator=(String const & other) noexcept
	{
		attach(m_handle, DuplicateString(get(other)));
		return *this;
	}

	String & operator=(std::nullptr_t) noexcept
	{
		m_handle.Close();
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

	bool HasEmbeddedNull() const
	{
		BOOL result = 0;
		check(WindowsStringHasEmbeddedNull(get(m_handle), &result));
		return 0 != result;
	}

	String Substring(unsigned const startIndex)
	{
		String result;
		check(WindowsSubstring(get(m_handle), startIndex, set(result)));
		return result;
	}

	String Substring(unsigned const startIndex, unsigned const length)
	{
		String result;
		check(WindowsSubstringWithSpecifiedLength(get(m_handle), startIndex, length, set(result)));
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

	friend HSTRING get(String const & string) noexcept
	{
		return get(string.m_handle);
	}

	friend HSTRING * set(String & string) noexcept
	{
		return set(string.m_handle);
	}

	friend void attach(String & string, HSTRING handle) noexcept
	{
		attach(string.m_handle, handle);
	}

	friend HSTRING detach(String & string) noexcept
	{
		return detach(string.m_handle);
	}

	friend void swap(String & left, String & right) noexcept
	{
		swap(left.m_handle, right.m_handle);
	}

private:

	static HSTRING DuplicateString(HSTRING other)
	{
		HSTRING result = nullptr;
		check(WindowsDuplicateString(other, &result));
		return result;
	}

	static HSTRING CreateString(wchar_t const * value, unsigned const length)
	{
		HSTRING result = nullptr;
		check(WindowsCreateString(value, length, &result));
		return result;
	}

	Handle<StringTraits> m_handle;
};

}

namespace Modern { namespace Windows {

struct IUnknown;

}}

namespace Modern {

template <typename T>
struct Traits
{
};

template <typename T>
class HasDefault
{
	template <typename U> static constexpr bool Check(typename Traits<U>::Default *) { return true; }
	template <typename>   static constexpr bool Check(...) { return false; }

public:

	static constexpr bool Value = Check<T>(nullptr);
};

//template <typename T>
//using IsIUnknown = typename std::enable_if<std::is_base_of<Windows::IUnknown, T>::value>::type *;
//
//template <typename T>
//using IsNotIUnknown = typename std::enable_if<!std::is_base_of<Windows::IUnknown, T>::value>::type *;
//
//template <typename T>
//using IsClass = typename std::enable_if<HasDefault<T>::Value> ::type *;
//
//template <typename T>
//using IsNotClass = typename std::enable_if<!HasDefault<T>::Value>::type *;

template <typename T>
using IsPod = typename std::enable_if<std::is_pod<T>::value>::type *;

template <typename T>
using IsNotPod = typename std::enable_if<!std::is_pod<T>::value>::type *;

template <typename T, typename Enable = void>
struct LookupAbi
{
	using Type = typename Traits<T>::Abi;
};

template <typename T>
struct LookupAbi<T, typename std::enable_if<HasDefault<T>::Value>::type>
{
	using Type = typename Traits<typename Traits<T>::Default>::Abi;
};

template <typename T>
using Abi = typename LookupAbi<T>::Type;

template <> struct Traits<Windows::IUnknown>
{
	using Abi = ::IUnknown;
};

template <typename T, IsPod<T> = nullptr>
T const & abi(T const & value) noexcept
{
	return value;
}

template <typename T, IsPod<T> = nullptr>
T * abi(T * value) noexcept
{
	return value;
}

template <typename T, IsNotPod<T> = nullptr>
auto abi(T const & value) noexcept
{
	return get(value);
}

template <typename T, IsNotPod<T> = nullptr>
auto abi(T * value) noexcept
{
	return set(*value);
}

inline BoolProxy abi(bool * value) noexcept
{
	return BoolProxy(*value);
}

}

namespace Modern { namespace Windows {

struct IUnknown
{
	IUnknown() noexcept = default;
	IUnknown(std::nullptr_t) noexcept {}

	IUnknown(IUnknown const & other) noexcept :
		m_ptr(other.m_ptr)
	{
		InternalAddRef();
	}

	IUnknown(IUnknown && other) noexcept :
		m_ptr(other.m_ptr)
	{
		other.m_ptr = nullptr;
	}

	~IUnknown() noexcept
	{
		InternalRelease();
	}

	IUnknown & operator=(IUnknown const & other) noexcept
	{
		InternalCopy(other);
		return *this;
	}

	IUnknown & operator=(IUnknown && other) noexcept
	{
		InternalMove(other);
		return *this;
	}

	explicit operator bool() const noexcept
	{
		return nullptr != m_ptr;
	}

	NoAddRefRelease<::IUnknown> * operator->() const noexcept
	{
		return static_cast<NoAddRefRelease<::IUnknown> *>(m_ptr);
	}

	IUnknown & operator=(std::nullptr_t) noexcept
	{
		InternalRelease();
		return *this;
	}

	template <typename T>
	T As() const
	{
		T temp = nullptr;
		check(m_ptr->QueryInterface(set(temp)));
		return temp;
	}

	template <typename T>
	friend Abi<T> * get(T const & object) noexcept
	{
		return static_cast<Abi<T> *>(object.m_ptr);
	}

	template <typename T>
	friend Abi<T> ** set(T & object) noexcept
	{
		MODERN_ASSERT(!object);
		return reinterpret_cast<Abi<T> **>(&object.m_ptr);
	}

	template <typename T>
	friend void attach(T & object, Abi<T> * value) noexcept
	{
		object.InternalRelease();
		object.m_ptr = value;
	}

	template <typename T>
	friend Abi<T> * detach(T & object) noexcept
	{
		Abi<T> * temp = static_cast<Abi<T> *>(object.m_ptr);
		object.m_ptr = nullptr;
		return temp;
	}

	friend void swap(IUnknown & left, IUnknown & right) noexcept
	{
		::IUnknown * temp = left.m_ptr;
		left.m_ptr = right.m_ptr;
		right.m_ptr = temp;
	}

protected:

	void InternalCopy(::IUnknown * other) noexcept
	{
		if (m_ptr != other)
		{
			InternalRelease();
			m_ptr = other;
			InternalAddRef();
		}
	}

	void InternalCopy(IUnknown const & other) noexcept
	{
		if (this != &other)
		{
			InternalRelease();
			m_ptr = other.m_ptr;
			InternalAddRef();
		}
	}

	void InternalMove(IUnknown & other) noexcept
	{
		if (this != &other)
		{
			InternalRelease();
			m_ptr = other.m_ptr;
			other.m_ptr = nullptr;
		}
	}

private:

	void InternalAddRef() const noexcept
	{
		if (m_ptr)
		{
			m_ptr->AddRef();
		}
	}

	void InternalRelease() noexcept
	{
		::IUnknown * temp = m_ptr;

		if (temp)
		{
			m_ptr = nullptr;
			temp->Release();
		}
	}

	::IUnknown * m_ptr = nullptr;
};

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

namespace Modern { namespace ABI { namespace Windows {

struct __declspec(uuid("00000036-0000-0000-c000-000000000046")) __declspec(novtable) IAsyncInfo : IInspectable
{
	virtual HRESULT __stdcall get_Id(unsigned int * id) = 0;
	virtual HRESULT __stdcall get_Status(AsyncStatus * status) = 0;
	virtual HRESULT __stdcall get_ErrorCode(HRESULT * errorCode) = 0;
	virtual HRESULT __stdcall abi_Cancel() = 0;
	virtual HRESULT __stdcall abi_Close() = 0;
};

struct __declspec(uuid("00000035-0000-0000-c000-000000000046")) __declspec(novtable) IActivationFactory : IInspectable
{
	virtual HRESULT __stdcall abi_ActivateInstance(IInspectable ** instance) = 0;
};

}}}

namespace Modern { namespace Windows {

struct IInspectable;
struct IAsyncInfo;
struct IActivationFactory;

}}

namespace Modern {

template <> struct Traits<Windows::IInspectable>
{
	using Abi = ::IInspectable;
};

template <> struct Traits<Windows::IAsyncInfo>
{
	using Abi = ABI::Windows::IAsyncInfo;
};

template <> struct Traits<Windows::IActivationFactory>
{
	using Abi = ABI::Windows::IActivationFactory;
};

}

namespace Modern { namespace Windows {

struct IInspectable : IUnknown
{
	IInspectable(std::nullptr_t = nullptr) noexcept {}
	Abi<IInspectable> * operator->() const noexcept { return get(*this); }

	String GetRuntimeClassName() const
	{
		String name;
		check((*this)->GetRuntimeClassName(set(name)));
		return name;
	}
};

template <typename T>
struct impl_IAsyncInfo
{
	unsigned Id() const
	{
		unsigned id;
		check((*static_cast<T const *>(this))->get_Id(&id));
		return id;
	}

	AsyncStatus Status() const
	{
		AsyncStatus status;
		check((*static_cast<T const *>(this))->get_Status(&status));
		return status;
	}

	HRESULT ErrorCode() const
	{
		HRESULT code;
		check((*static_cast<T const *>(this))->get_ErrorCode(&code));
		return code;
	}

	void Cancel() const
	{
		check((*static_cast<T const *>(this))->abi_Cancel());
	}

	void Close() const
	{
		check((*static_cast<T const *>(this))->abi_Close());
	}
};

struct IAsyncInfo :
	IInspectable,
	impl_IAsyncInfo<IAsyncInfo>
{
public:

	IAsyncInfo(std::nullptr_t = nullptr) noexcept {}
	Abi<IAsyncInfo> * operator->() const noexcept { return get(*this); }
};

template <typename T>
struct impl_IActivationFactory
{
	IInspectable ActivateInstance() const
	{
		IInspectable instance;
		check((*static_cast<T const *>(this))->abi_ActivateInstance(set(instance)));
		return instance;
	}
};

struct IActivationFactory :
	IInspectable,
	impl_IActivationFactory<IActivationFactory>
{
	IActivationFactory(std::nullptr_t = nullptr) noexcept {}
	Abi<IActivationFactory> * operator->() const noexcept { return get(*this); }
};

}}

namespace Modern {

template <typename Class, typename Interface = Windows::IActivationFactory>
Interface GetActivationFactory()
{
	StringReference classId(Traits<Class>Name(),
							Traits<Class>NameLength);

	Interface factory;

	check(RoGetActivationFactory(get(classId), __uuidof(Abi<Interface>), reinterpret_cast<void **>(set(factory))));

	return factory;
}

template <typename Class, typename Interface = typename Traits<Class>::Default>
Interface ActivateInstance()
{
	StringReference classId(Traits<Class>::Name(),
							Traits<Class>::NameLength);

	Windows::IInspectable instance;

	check(RoActivateInstance(get(classId), set(instance)));

	return instance.As<Interface>();
}

}


