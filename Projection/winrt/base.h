// C++ for the Windows Runtime v1.29
// Copyright (c) 2016 Microsoft Corporation

#pragma once

#ifndef WINRT_NO_DEFAULT_LIB 
#pragma comment(lib, "windowsapp") 
#endif

#include <ctxtcall.h>
#include <restrictederrorinfo.h>
#include <winstring.h>

#include <atomic>
#include <chrono>
#include <functional>
#include <vector>

extern "C"
{
    HRESULT __stdcall WINRT_GetRestrictedErrorInfo(IRestrictedErrorInfo ** info);
    HRESULT __stdcall WINRT_RoActivateInstance(HSTRING classId, void ** instance);
    HRESULT __stdcall WINRT_RoGetActivationFactory(HSTRING classId, const GUID & iid, void ** factory);
    HRESULT __stdcall WINRT_RoInitialize(uint32_t type);
    BOOL    __stdcall WINRT_RoOriginateError(HRESULT error, HSTRING message);
    void    __stdcall WINRT_RoUninitialize();
    HRESULT __stdcall WINRT_SetRestrictedErrorInfo(IRestrictedErrorInfo * info);
}

#ifdef _M_IX86
#pragma comment(linker, "/alternatename:_WINRT_GetRestrictedErrorInfo@4=_GetRestrictedErrorInfo@4")
#pragma comment(linker, "/alternatename:_WINRT_RoActivateInstance@8=_RoActivateInstance@8")
#pragma comment(linker, "/alternatename:_WINRT_RoGetActivationFactory@12=_RoGetActivationFactory@12")
#pragma comment(linker, "/alternatename:_WINRT_RoInitialize@4=_RoInitialize@4")
#pragma comment(linker, "/alternatename:_WINRT_RoOriginateError@8=_RoOriginateError@8")
#pragma comment(linker, "/alternatename:_WINRT_RoUninitialize@0=_RoUninitialize@0")
#pragma comment(linker, "/alternatename:_WINRT_SetRestrictedErrorInfo@4=_SetRestrictedErrorInfo@4")
#else
#pragma comment(linker, "/alternatename:WINRT_GetRestrictedErrorInfo=GetRestrictedErrorInfo")
#pragma comment(linker, "/alternatename:WINRT_RoActivateInstance=RoActivateInstance")
#pragma comment(linker, "/alternatename:WINRT_RoGetActivationFactory=RoGetActivationFactory")
#pragma comment(linker, "/alternatename:WINRT_RoInitialize=RoInitialize")
#pragma comment(linker, "/alternatename:WINRT_RoOriginateError=RoOriginateError")
#pragma comment(linker, "/alternatename:WINRT_RoUninitialize=RoUninitialize")
#pragma comment(linker, "/alternatename:WINRT_SetRestrictedErrorInfo=SetRestrictedErrorInfo")
#endif

#define _WINDOWS_NUMERICS_NAMESPACE_ winrt::Windows::Foundation::Numerics
#define _WINDOWS_NUMERICS_BEGIN_NAMESPACE_ namespace winrt { namespace Windows { namespace Foundation { namespace Numerics
#define _WINDOWS_NUMERICS_END_NAMESPACE_ }}}

#ifdef __clang__
#define _XM_NO_INTRINSICS_
#endif

#include "WindowsNumerics.impl.h"

#ifdef __clang__
#undef _XM_NO_INTRINSICS_
#endif

#undef _WINDOWS_NUMERICS_NAMESPACE_
#undef _WINDOWS_NUMERICS_BEGIN_NAMESPACE_
#undef _WINDOWS_NUMERICS_END_NAMESPACE_

#ifdef _DEBUG

#include <assert.h>

#define WINRT_ASSERT assert
#define WINRT_VERIFY WINRT_ASSERT
#define WINRT_VERIFY_(result, expression) WINRT_ASSERT(result == expression)

template <typename ... Args>
void WINRT_TRACE(const char * const message, Args ... args) noexcept
{
    char buffer[1024] {};
    sprintf_s(buffer, message, args ...);
    OutputDebugStringA(buffer);
}

#else

#define WINRT_ASSERT __noop
#define WINRT_VERIFY(expression) (expression)
#define WINRT_VERIFY_(result, expression) (expression)
#define WINRT_TRACE __noop

#endif

#ifndef WINRT_EXPORT
#define WINRT_EXPORT
#endif

#if defined(__clang__) || defined(__INTELLISENSE__)
#define WINRT_EBO
#else
#define WINRT_EBO __declspec(empty_bases)
#endif

#ifdef _WIN64
#define WINRT_64
#endif

#ifndef FORMAT_MESSAGE_ALLOCATE_BUFFER
#define FORMAT_MESSAGE_ALLOCATE_BUFFER 0x00000100
#endif

WINRT_EXPORT namespace winrt {

namespace impl {

template <typename T>
struct traits
{
    using abi = T;
};

}

template <typename T>
using abi = typename impl::traits<T>::abi;

namespace impl {

template <typename T, typename Enable = void>
struct accessors
{
    static abi<T> get(const T & object) noexcept
    {
        return reinterpret_cast<const abi<T> &>(object);
    }

    static abi<T> * put(T & object) noexcept
    {
        return reinterpret_cast<abi<T> *>(&object);
    }

    static void copy_from(T & object, const abi<T> & value) noexcept
    {
        object = reinterpret_cast<const T &>(value);
    }

    static void copy_to(const T & object, abi<T> & value) noexcept
    {
        reinterpret_cast<T &>(value) = object;
    }

    static abi<T> detach(T & object) noexcept
    {
        abi<T> result {};
        reinterpret_cast<T &>(result) = std::move(object);
        return result;
    }
};

}

template <typename T>
auto get(const T & object) noexcept
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
void copy_to(const T & object, V & value)
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
        return T::invalid() != m_value;
    }

    friend type impl_get(const handle & handle) noexcept
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
        std::swap(left.m_value, right.m_value);
    }

private:

    type m_value = T::invalid();
};

template <typename T>
bool operator==(const handle<T> & left, const handle<T> & right) noexcept
{
    return get(left) == get(right);
}

template <typename T>
bool operator!=(const handle<T> & left, const handle<T> & right) noexcept
{
    return !(left == right);
}

template <typename T>
bool operator<(const handle<T> & left, const handle<T> & right) noexcept
{
    return get(left) < get(right);
}

template <typename T>
bool operator>(const handle<T> & left, const handle<T> & right) noexcept
{
    return right < left;
}

template <typename T>
bool operator<=(const handle<T> & left, const handle<T> & right) noexcept
{
    return !(right < left);
}

template <typename T>
bool operator>=(const handle<T> & left, const handle<T> & right) noexcept
{
    return !(left < right);
}

namespace impl {

template <typename T>
struct accessors<handle<T>>
{
    using type = typename handle<T>::type;

    static type get(const handle<T> & object) noexcept
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

}

namespace Windows {

enum class TrustLevel
{
    BaseTrust,
    PartialTrust,
    FullTrust,
};

enum class AsyncStatus
{
    Started,
    Completed,
    Canceled,
    Error,
};

}

namespace ABI { namespace Windows {

struct __declspec(uuid("af86e2e0-b12d-4c6a-9c5a-d7aa65101e90")) __declspec(novtable) IInspectable : IUnknown
{
    virtual HRESULT __stdcall get_Iids(uint32_t * iidCount, GUID ** iids) = 0;
    virtual HRESULT __stdcall get_RuntimeClassName(HSTRING * className) = 0;
    virtual HRESULT __stdcall get_TrustLevel(winrt::Windows::TrustLevel * trustLevel) = 0;
};

struct __declspec(uuid("00000036-0000-0000-c000-000000000046")) __declspec(novtable) IAsyncInfo : IInspectable
{
    virtual HRESULT __stdcall get_Id(uint32_t * id) = 0;
    virtual HRESULT __stdcall get_Status(winrt::Windows::AsyncStatus * status) = 0;
    virtual HRESULT __stdcall get_ErrorCode(HRESULT * errorCode) = 0;
    virtual HRESULT __stdcall abi_Cancel() = 0;
    virtual HRESULT __stdcall abi_Close() = 0;
};

struct __declspec(uuid("00000035-0000-0000-c000-000000000046")) __declspec(novtable) IActivationFactory : IInspectable
{
    virtual HRESULT __stdcall abi_ActivateInstance(IInspectable ** instance) = 0;
};

}}

namespace ABI {

template <typename T>
struct traits
{
    using default_interface = T;
};

template <typename T>
using default_interface = typename traits<T>::default_interface;

template <typename T>
using arg_in = std::conditional_t<std::is_base_of_v< ::IUnknown, default_interface<T>>, default_interface<T> *, T>;

template <typename T>
using arg_out = std::conditional_t<std::is_base_of_v< ::IUnknown, default_interface<T>>, default_interface<T> **, T *>;

}

namespace impl {

template <typename T>
class has_GetAt
{
    template <typename U, typename = decltype(std::declval<U>().GetAt(0))> static constexpr bool get_value(int) { return true; }
    template <typename> static constexpr bool get_value(...) { return false; }

public:

    static constexpr bool value = get_value<T>(nullptr);
};

template <typename T>
class has_composable
{
    template <typename U> static constexpr bool get_value(typename U::composable *) { return true; }
    template <typename>   static constexpr bool get_value(...) { return false; }

public:

    static constexpr bool value = get_value<T>(nullptr);
};

template <typename T>
class can_produce
{
    template <typename U> static constexpr bool get_value(typename impl::traits<U>::produce *) { return true; }
    template <typename>   static constexpr bool get_value(...) { return false; }

public:

    static constexpr bool value = get_value<T>(nullptr);
};

template <typename Crtp, typename Qi, typename Base>
auto shim(const Base * base)
{
    return get(static_cast<const Qi &>(static_cast<const Crtp &>(*base)));
}

template <typename T, typename R>
struct requires : traits<R>::template consume<requires<T, R>>
{
    operator R() const noexcept
    {
        return static_cast<const T *>(this)->template as<R>();
    }
};

template <typename T, typename B>
struct bases
{
    operator B() const noexcept
    {
        return static_cast<const T *>(this)->as<B>();
    }
};

template <typename T>
class no_ref : public T
{
    unsigned long __stdcall AddRef();
    unsigned long __stdcall Release();
};

}

template <typename T>
using abi_arg_in = ABI::arg_in<abi<T>>;

template <typename T>
using abi_arg_out = ABI::arg_out<abi<T>>;

template <typename T>
using abi_default_interface = ABI::default_interface<abi<T>>;

template <typename T>
auto ptr(IUnknown * object) noexcept
{
    return static_cast<impl::no_ref<abi<T>> *>(object);
}

template <typename T>
using consume = typename impl::traits<T>::template consume<T>;

template <typename T, typename ... R>
struct WINRT_EBO requires : impl::requires<T, R> ...
{};

template <typename T, typename ... B>
struct WINRT_EBO bases : impl::bases<T, B> ...
{};

namespace impl {

template <typename To, typename From>
auto abi_cast(From * from) noexcept
{
    return const_cast<abi<To> *>(static_cast<const abi<To> *>(from));
}

template <typename To, typename From>
auto winrt_cast(From * from) noexcept
{
    To result = nullptr;
    copy_from(result, abi_cast<To>(from));
    return result;
}

}
namespace Windows {

struct IUnknown;

}

template <typename T>
struct com_ptr
{
    using type = abi<T>;

    com_ptr(std::nullptr_t = nullptr) noexcept {}

    com_ptr(const com_ptr & other) noexcept :
        m_ptr(other.m_ptr)
    {
        addref();
    }

    template <typename U>
    com_ptr(const com_ptr<U> & other) noexcept :
        m_ptr(other.m_ptr)
    {
        addref();
    }

    template <typename U>
    com_ptr(com_ptr<U> && other) noexcept :
        m_ptr(other.m_ptr)
    {
        other.m_ptr = nullptr;
    }

    ~com_ptr() noexcept
    {
        release();
    }

    com_ptr & operator=(const com_ptr & other) noexcept
    {
        copy(other.m_ptr);
        return *this;
    }

    template <typename U>
    com_ptr & operator=(const com_ptr<U> & other) noexcept
    {
        copy(other.m_ptr);
        return *this;
    }

    template <typename U>
    com_ptr & operator=(com_ptr<U> && other) noexcept
    {
        if (m_ptr != other.m_ptr)
        {
            release();
            m_ptr = other.m_ptr;
            other.m_ptr = nullptr;
        }

        return *this;
    }

    explicit operator bool() const noexcept
    {
        return nullptr != m_ptr;
    }

    auto operator->() const noexcept
    {
        return static_cast<impl::no_ref<type> *>(m_ptr);
    }

    friend type * impl_get(const com_ptr & object) noexcept
    {
        return object.m_ptr;
    }

    friend type ** impl_put(com_ptr & object) noexcept
    {
        WINRT_ASSERT(object.m_ptr == nullptr);
        return &object.m_ptr;
    }

    friend type * impl_detach(com_ptr & object) noexcept
    {
        type * temp = object.m_ptr;
        object.m_ptr = nullptr;
        return temp;
    }

    friend void swap(com_ptr & left, com_ptr & right) noexcept
    {
        std::swap(left.m_ptr, right.m_ptr);
    }

    template <typename U>
    auto as() const
    {
        std::conditional_t<std::is_base_of_v<Windows::IUnknown, U>, U, com_ptr<U>> temp = nullptr;
        check_hresult(m_ptr->QueryInterface(__uuidof(abi_default_interface<U>), reinterpret_cast<void **>(put(temp))));
        return temp;
    }

    void copy_from(type * other) noexcept
    {
        copy(other);
    }

    void copy_to(type ** other) const noexcept
    {
        addref();
        *other = m_ptr;
    }

private:

    void copy(type * other) noexcept
    {
        if (m_ptr != other)
        {
            release();
            m_ptr = other;
            addref();
        }
    }

    void addref() const noexcept
    {
        if (m_ptr)
        {
            m_ptr->AddRef();
        }
    }

    void release() noexcept
    {
        type * temp = m_ptr;

        if (temp)
        {
            m_ptr = nullptr;
            temp->Release();
        }
    }

    template <typename U>
    friend struct com_ptr;

    type * m_ptr = nullptr;
};

namespace impl {

template <typename T>
struct accessors<com_ptr<T>>
{
    static auto get(const com_ptr<T> & object) noexcept
    {
        return impl_get(object);
    }

    static auto put(com_ptr<T> & object) noexcept
    {
        return impl_put(object);
    }

    static void attach(com_ptr<T> & object, abi<T> * value) noexcept
    {
        object = nullptr;
        *put(object) = value;
    }

    static auto detach(com_ptr<T> & object) noexcept
    {
        return impl_detach(object);
    }
};

}

template <typename T>
bool operator==(const com_ptr<T> & left, const com_ptr<T> & right) noexcept
{
    return get(left) == get(right);
}

template <typename T>
bool operator!=(const com_ptr<T> & left, const com_ptr<T> & right) noexcept
{
    return !(left == right);
}

template <typename T>
bool operator<(const com_ptr<T> & left, const com_ptr<T> & right) noexcept
{
    return get(left) < get(right);
}

template <typename T>
bool operator>(const com_ptr<T> & left, const com_ptr<T> & right) noexcept
{
    return right < left;
}

template <typename T>
bool operator<=(const com_ptr<T> & left, const com_ptr<T> & right) noexcept
{
    return !(right < left);
}

template <typename T>
bool operator>=(const com_ptr<T> & left, const com_ptr<T> & right) noexcept
{
    return !(left < right);
}

__forceinline void check_hresult(HRESULT result);

namespace impl {

inline HSTRING duplicate_string(HSTRING other)
{
    HSTRING result = nullptr;
    check_hresult(WindowsDuplicateString(other, &result));
    return result;
}

inline HSTRING create_string(const wchar_t * value, const uint32_t length)
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
    using const_reference = const value_type &;
    using const_pointer = const value_type *;
    using const_iterator = const_pointer;
    using const_reverse_iterator = std::reverse_iterator<const_iterator>;

    hstring() noexcept = default;
    hstring(const hstring & value);
    hstring & operator=(const hstring & value);
    hstring(hstring && value) noexcept;
    hstring & operator=(hstring && value) noexcept;

    hstring(const std::wstring & value);
    hstring(hstring_ref value);
    hstring(const wchar_t * value);
    hstring(const wchar_t * value, size_type size);

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

    friend HSTRING impl_get(const hstring & string) noexcept
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
        swap(left.m_handle, right.m_handle);
    }

private:

    handle<impl::hstring_traits> m_handle;
};

struct hstring_ref
{
    using value_type = wchar_t;
    using size_type = uint32_t;
    using const_reference = const value_type &;
    using const_pointer = const value_type *;
    using const_iterator = const_pointer;
    using const_reverse_iterator = std::reverse_iterator<const_iterator>;

    hstring_ref(const std::wstring & value) noexcept;
    hstring_ref(const hstring & value) noexcept;
    hstring_ref(const wchar_t * value) noexcept;
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

    hstring_ref(const wchar_t * value, size_type size) noexcept;

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
    static HSTRING get(const hstring & object) noexcept
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

    static void copy_to(const hstring & object, HSTRING & value)
    {
        WINRT_ASSERT(value == nullptr);
        value = duplicate_string(get(object));
    }

    static HSTRING detach(hstring & object) noexcept
    {
        return impl_detach(object);
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

template <> struct accessors<const wchar_t *>
{
    static HSTRING detach(const wchar_t * const value)
    {
        return create_string(value, static_cast<uint32_t>(wcslen(value)));
    }
};

template <> struct accessors<std::wstring>
{
    static HSTRING detach(const std::wstring & value)
    {
        return create_string(value.c_str(), static_cast<uint32_t>(value.size()));
    }
};

}

inline bool embedded_null(hstring_ref value) noexcept
{
    return impl::embedded_null(get(value));
}

inline bool embedded_null(const hstring & value) noexcept
{
    return impl::embedded_null(get(value));
}

// TODO: this must be removed. The ABI projection should just use HSTRING directly.
namespace ABI { using hstring = HSTRING; }

inline hstring::hstring(const hstring & value) :
    m_handle(impl::duplicate_string(get(value.m_handle)))
{}

inline hstring & hstring::operator=(const hstring & value)
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

inline hstring::hstring(const std::wstring & value) :
    hstring(value.c_str(), static_cast<size_type>(value.size()))
{}

inline hstring::hstring(hstring_ref value) :
    m_handle(impl::duplicate_string(get(value)))
{}

inline hstring::hstring(const wchar_t * const value) :
    hstring(value, static_cast<size_type>(wcslen(value)))
{}

inline hstring::hstring(const wchar_t * const value, const size_type size) :
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

inline hstring::const_reference hstring::operator[](const size_type pos) const noexcept
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
    uint32_t length = 0;
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

inline bool operator==(hstring_ref left, hstring_ref right) noexcept
{
    return std::equal(left.begin(), left.end(), right.begin(), right.end());
}

inline bool operator==(hstring_ref left, const hstring & right) noexcept
{
    return std::equal(left.begin(), left.end(), right.begin(), right.end());
}

inline bool operator==(const hstring & left, hstring_ref right) noexcept
{
    return std::equal(left.begin(), left.end(), right.begin(), right.end());
}

inline bool operator==(const hstring & left, const hstring & right) noexcept
{
    return std::equal(left.begin(), left.end(), right.begin(), right.end());
}

inline bool operator==(hstring_ref left, const wchar_t * const right) noexcept
{
    return std::equal(left.begin(), left.end(), right, right + wcslen(right));
}

inline bool operator==(const wchar_t * const left, hstring_ref right) noexcept
{
    return std::equal(left, left + wcslen(left), right.begin(), right.end());
}

inline bool operator==(hstring_ref left, const std::wstring & right) noexcept
{
    return std::equal(left.begin(), left.end(), right.begin(), right.end());
}

inline bool operator==(const std::wstring & left, hstring_ref right) noexcept
{
    return std::equal(left.begin(), left.end(), right.begin(), right.end());
}

inline bool operator==(const hstring & left, const wchar_t * const right) noexcept
{
    return std::equal(left.begin(), left.end(), right, right + wcslen(right));
}

inline bool operator==(const wchar_t * const left, const hstring & right) noexcept
{
    return std::equal(left, left + wcslen(left), right.begin(), right.end());
}

inline bool operator==(const hstring & left, const std::wstring & right) noexcept
{
    return std::equal(left.begin(), left.end(), right.begin(), right.end());
}

inline bool operator==(const std::wstring & left, const hstring & right) noexcept
{
    return std::equal(left.begin(), left.end(), right.begin(), right.end());
}

inline bool operator<(hstring_ref left, hstring_ref right) noexcept
{
    return std::lexicographical_compare(left.begin(), left.end(), right.begin(), right.end());
}

inline bool operator<(hstring_ref left, const hstring & right) noexcept
{
    return std::lexicographical_compare(left.begin(), left.end(), right.begin(), right.end());
}

inline bool operator<(const hstring & left, hstring_ref right) noexcept
{
    return std::lexicographical_compare(left.begin(), left.end(), right.begin(), right.end());
}

inline bool operator<(const hstring & left, const hstring & right) noexcept
{
    return std::lexicographical_compare(left.begin(), left.end(), right.begin(), right.end());
}

inline bool operator<(hstring_ref left, const wchar_t * const right) noexcept
{
    return std::lexicographical_compare(left.begin(), left.end(), right, right + wcslen(right));
}

inline bool operator<(const wchar_t * const left, hstring_ref right) noexcept
{
    return std::lexicographical_compare(left, left + wcslen(left), right.begin(), right.end());
}

inline bool operator<(hstring_ref left, const std::wstring & right) noexcept
{
    return std::lexicographical_compare(left.begin(), left.end(), right.begin(), right.end());
}

inline bool operator<(const std::wstring & left, hstring_ref right) noexcept
{
    return std::lexicographical_compare(left.begin(), left.end(), right.begin(), right.end());
}

inline bool operator<(const hstring & left, const wchar_t * const right) noexcept
{
    return std::lexicographical_compare(left.begin(), left.end(), right, right + wcslen(right));
}

inline bool operator<(const wchar_t * const left, const hstring & right) noexcept
{
    return std::lexicographical_compare(left, left + wcslen(left), right.begin(), right.end());
}

inline bool operator<(const hstring & left, const std::wstring & right) noexcept
{
    return std::lexicographical_compare(left.begin(), left.end(), right.begin(), right.end());
}

inline bool operator<(const std::wstring & left, const hstring & right) noexcept
{
    return std::lexicographical_compare(left.begin(), left.end(), right.begin(), right.end());
}

inline bool operator!=(hstring_ref left, hstring_ref right) noexcept { return !(left == right); }
inline bool operator >(hstring_ref left, hstring_ref right) noexcept { return right < left; }
inline bool operator<=(hstring_ref left, hstring_ref right) noexcept { return !(right < left); }
inline bool operator>=(hstring_ref left, hstring_ref right) noexcept { return !(left < right); }

inline bool operator!=(hstring_ref left, const wchar_t * const right) noexcept { return !(left == right); }
inline bool operator >(hstring_ref left, const wchar_t * const right) noexcept { return right < left; }
inline bool operator<=(hstring_ref left, const wchar_t * const right) noexcept { return !(right < left); }
inline bool operator>=(hstring_ref left, const wchar_t * const right) noexcept { return !(left < right); }

inline bool operator!=(const wchar_t * const left, hstring_ref right) noexcept { return !(left == right); }
inline bool operator >(const wchar_t * const left, hstring_ref right) noexcept { return right < left; }
inline bool operator<=(const wchar_t * const left, hstring_ref right) noexcept { return !(right < left); }
inline bool operator>=(const wchar_t * const left, hstring_ref right) noexcept { return !(left < right); }

inline bool operator!=(hstring_ref left, const std::wstring & right) noexcept { return !(left == right); }
inline bool operator >(hstring_ref left, const std::wstring & right) noexcept { return right < left; }
inline bool operator<=(hstring_ref left, const std::wstring & right) noexcept { return !(right < left); }
inline bool operator>=(hstring_ref left, const std::wstring & right) noexcept { return !(left < right); }

inline bool operator!=(const std::wstring & left, hstring_ref right) noexcept { return !(left == right); }
inline bool operator >(const std::wstring & left, hstring_ref right) noexcept { return right < left; }
inline bool operator<=(const std::wstring & left, hstring_ref right) noexcept { return !(right < left); }
inline bool operator>=(const std::wstring & left, hstring_ref right) noexcept { return !(left < right); }

inline bool operator!=(hstring_ref left, const hstring & right) noexcept { return !(left == right); }
inline bool operator >(hstring_ref left, const hstring & right) noexcept { return right < left; }
inline bool operator<=(hstring_ref left, const hstring & right) noexcept { return !(right < left); }
inline bool operator>=(hstring_ref left, const hstring & right) noexcept { return !(left < right); }

inline bool operator!=(const hstring & left, hstring_ref right) noexcept { return !(left == right); }
inline bool operator >(const hstring & left, hstring_ref right) noexcept { return right < left; }
inline bool operator<=(const hstring & left, hstring_ref right) noexcept { return !(right < left); }
inline bool operator>=(const hstring & left, hstring_ref right) noexcept { return !(left < right); }

inline bool operator!=(const hstring & left, const hstring & right) noexcept { return !(left == right); }
inline bool operator >(const hstring & left, const hstring & right) noexcept { return right < left; }
inline bool operator<=(const hstring & left, const hstring & right) noexcept { return !(right < left); }
inline bool operator>=(const hstring & left, const hstring & right) noexcept { return !(left < right); }

inline bool operator!=(const hstring & left, const wchar_t * const right) noexcept { return !(left == right); }
inline bool operator >(const hstring & left, const wchar_t * const right) noexcept { return right < left; }
inline bool operator<=(const hstring & left, const wchar_t * const right) noexcept { return !(right < left); }
inline bool operator>=(const hstring & left, const wchar_t * const right) noexcept { return !(left < right); }

inline bool operator!=(const wchar_t * const left, const hstring & right) noexcept { return !(left == right); }
inline bool operator >(const wchar_t * const left, const hstring & right) noexcept { return right < left; }
inline bool operator<=(const wchar_t * const left, const hstring & right) noexcept { return !(right < left); }
inline bool operator>=(const wchar_t * const left, const hstring & right) noexcept { return !(left < right); }

inline bool operator!=(const hstring & left, const std::wstring & right) noexcept { return !(left == right); }
inline bool operator >(const hstring & left, const std::wstring & right) noexcept { return right < left; }
inline bool operator<=(const hstring & left, const std::wstring & right) noexcept { return !(right < left); }
inline bool operator>=(const hstring & left, const std::wstring & right) noexcept { return !(left < right); }

inline bool operator!=(const std::wstring & left, const hstring & right) noexcept { return !(left == right); }
inline bool operator >(const std::wstring & left, const hstring & right) noexcept { return right < left; }
inline bool operator<=(const std::wstring & left, const hstring & right) noexcept { return !(right < left); }
inline bool operator>=(const std::wstring & left, const hstring & right) noexcept { return !(left < right); }

namespace impl {

struct heap_traits : handle_traits<wchar_t *>
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

inline hstring trim_hresult_message(const wchar_t * const message, uint32_t size) noexcept
{
    const wchar_t * back = message + size - 1;

    while (size && isspace(*back))
    {
        --size;
        --back;
    }

    hstring result;
    WindowsCreateString(message, size, put(result));
    return result;
}

}

struct hresult_error
{
    struct from_abi_t {};
    static constexpr from_abi_t from_abi {};

    explicit hresult_error(const HRESULT code) noexcept :
        m_code(code)
    {
        WINRT_RoOriginateError(code, nullptr);
        WINRT_GetRestrictedErrorInfo(put(m_info));
    }

    hresult_error(const HRESULT code, hstring_ref message) noexcept :
        m_code(code)
    {
        WINRT_RoOriginateError(code, get(message));
        WINRT_GetRestrictedErrorInfo(put(m_info));
    }

    hresult_error(const HRESULT code, from_abi_t) noexcept :
        m_code(code)
    {
        WINRT_GetRestrictedErrorInfo(put(m_info));
    }

    HRESULT code() const noexcept
    {
        return m_code;
    }

    hstring message() const noexcept
    {
        if (m_info)
        {
            handle<impl::bstr_traits> unused1;
            handle<impl::bstr_traits> unused2;

            HRESULT code = S_OK;
            handle<impl::bstr_traits> message;

            if (S_OK == m_info->GetErrorDetails(put(unused1), &code, put(message), put(unused2)))
            {
                if (code == m_code)
                {
                    return impl::trim_hresult_message(get(message), SysStringLen(get(message)));
                }
            }
        }

        handle<impl::heap_traits> message;

        const uint32_t size = FormatMessageW(FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_IGNORE_INSERTS,
                                             nullptr,
                                             m_code,
                                             MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),
                                             reinterpret_cast<wchar_t *>(put(message)),
                                             0,
                                             nullptr);

        return impl::trim_hresult_message(get(message), size);
    }

    HRESULT to_abi() const noexcept
    {
        WINRT_TRACE("winrt::hresult_error (0x%8X) %ls\n", code(), message().c_str());

        if (m_info)
        {
            WINRT_SetRestrictedErrorInfo(get(m_info));
        }

        return m_code;
    }

private:

    HRESULT m_code = S_OK;
    com_ptr<IRestrictedErrorInfo> m_info;
};

struct hresult_access_denied : hresult_error
{
    hresult_access_denied() : hresult_error(E_ACCESSDENIED) {}
    hresult_access_denied(hstring_ref message) : hresult_error(E_ACCESSDENIED, message) {}
    hresult_access_denied(from_abi_t) : hresult_error(E_ACCESSDENIED, from_abi) {}
};

struct hresult_wrong_thread : hresult_error
{
    hresult_wrong_thread() : hresult_error(RPC_E_WRONG_THREAD) {}
    hresult_wrong_thread(hstring_ref message) : hresult_error(RPC_E_WRONG_THREAD, message) {}
    hresult_wrong_thread(from_abi_t) : hresult_error(RPC_E_WRONG_THREAD, from_abi) {}
};

struct hresult_not_implemented : hresult_error
{
    hresult_not_implemented() : hresult_error(E_NOTIMPL) {}
    hresult_not_implemented(hstring_ref message) : hresult_error(E_NOTIMPL, message) {}
    hresult_not_implemented(from_abi_t) : hresult_error(E_NOTIMPL, from_abi) {}
};

struct hresult_invalid_argument : hresult_error
{
    hresult_invalid_argument() : hresult_error(E_INVALIDARG) {}
    hresult_invalid_argument(hstring_ref message) : hresult_error(E_INVALIDARG, message) {}
    hresult_invalid_argument(from_abi_t) : hresult_error(E_INVALIDARG, from_abi) {}
};

struct hresult_out_of_bounds : hresult_error
{
    hresult_out_of_bounds() : hresult_error(E_BOUNDS) {}
    hresult_out_of_bounds(hstring_ref message) : hresult_error(E_BOUNDS, message) {}
    hresult_out_of_bounds(from_abi_t) : hresult_error(E_BOUNDS, from_abi) {}
};

struct hresult_no_interface : hresult_error
{
    hresult_no_interface() : hresult_error(E_NOINTERFACE) {}
    hresult_no_interface(hstring_ref message) : hresult_error(E_NOINTERFACE, message) {}
    hresult_no_interface(from_abi_t) : hresult_error(E_NOINTERFACE, from_abi) {}
};

struct hresult_disconnected : hresult_error
{
    hresult_disconnected() : hresult_error(RPC_E_DISCONNECTED) {}
    hresult_disconnected(hstring_ref message) : hresult_error(RPC_E_DISCONNECTED, message) {}
    hresult_disconnected(from_abi_t) : hresult_error(RPC_E_DISCONNECTED, from_abi) {}
};

namespace impl {

[[noreturn]] inline __declspec(noinline) void throw_hresult(const HRESULT result)
{
    if (result == E_OUTOFMEMORY)
    {
        throw std::bad_alloc();
    }

    if (result == E_ACCESSDENIED)
    {
        throw hresult_access_denied(hresult_error::from_abi);
    }

    if (result == RPC_E_WRONG_THREAD)
    {
        throw hresult_wrong_thread(hresult_error::from_abi);
    }

    if (result == E_NOTIMPL)
    {
        throw hresult_not_implemented(hresult_error::from_abi);
    }

    if (result == E_INVALIDARG)
    {
        throw hresult_invalid_argument(hresult_error::from_abi);
    }

    if (result == E_BOUNDS)
    {
        throw hresult_out_of_bounds(hresult_error::from_abi);
    }

    if (result == E_NOINTERFACE)
    {
        throw hresult_no_interface(hresult_error::from_abi);
    }

    throw hresult_error(result, hresult_error::from_abi);
}

inline __declspec(noinline) HRESULT to_hresult() noexcept
{
    HRESULT value = S_OK;

    try
    {
        throw;
    }
    catch (const hresult_error & e)
    {
        return e.to_abi();
    }
    catch (const std::bad_alloc &)
    {
        return E_OUTOFMEMORY;
    }
    catch (const std::out_of_range &)
    {
        value = E_BOUNDS;
    }
    catch (const std::invalid_argument &)
    {
        value = E_INVALIDARG;
    }
    catch (const std::exception &)
    {
        value = E_FAIL;
    }

    WINRT_RoOriginateError(value, nullptr);
    return value;
}

}

__forceinline void check_hresult(const HRESULT result)
{
    if (result != S_OK)
    {
        impl::throw_hresult(result);
    }
}

struct lock
{
    lock(const lock &) = delete;
    lock & operator=(const lock &) = delete;

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
    lock_guard(const lock_guard &) = delete;
    lock_guard & operator=(const lock_guard &) = delete;

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

template <typename T>
struct array_ref
{
    using value_type = T;
    using size_type = std::uint32_t;
    using reference = value_type &;
    using const_reference = const value_type &;
    using pointer = value_type *;
    using const_pointer = const value_type *;
    using iterator = pointer;
    using const_iterator = const_pointer;
    using reverse_iterator = std::reverse_iterator<iterator>;
    using const_reverse_iterator = std::reverse_iterator<const_iterator>;

    array_ref() noexcept = default;

    array_ref(pointer begin, pointer end) noexcept :
        m_begin(begin),
        m_end(end)
    {}

    array_ref(std::initializer_list<value_type> value) noexcept :
        array_ref(value.begin(), value.begin() + value.size())
    {}

    template <typename C, size_type N>
    array_ref(C(&value)[N]) noexcept :
        array_ref(value, value + N)
    {}

    template <typename C>
    array_ref(std::vector<C> & value) noexcept :
        array_ref(value.data(), value.data() + value.size())
    {}

    template <typename C>
    array_ref(const std::vector<C> & value) noexcept :
        array_ref(value.data(), value.data() + value.size())
    {}

    template <typename C, size_type N>
    array_ref(std::array<C, N> & value) noexcept :
        array_ref(value.data(), value.data() + value.size())
    {}

    template <typename C, size_type N>
    array_ref(const std::array<C, N> & value) noexcept :
        array_ref(value.data(), value.data() + value.size())
    {}

    reference operator[](const size_type pos) noexcept
    {
        WINRT_ASSERT(pos < size());
        return m_begin[pos];
    }

    const_reference operator[](const size_type pos) const noexcept
    {
        WINRT_ASSERT(pos < size());
        return m_begin[pos];
    }

    reference at(const size_type pos)
    {
        if (size() <= pos)
        {
            throw std::out_of_range("Invalid array subscript");
        }

        return m_begin[pos];
    }

    const_reference at(const size_type pos) const
    {
        if (size() <= pos)
        {
            throw std::out_of_range("Invalid array subscript");
        }

        return m_begin[pos];
    }

    reference front() noexcept
    {
        WINRT_ASSERT(m_begin != m_end);
        return *m_begin;
    }

    const_reference front() const noexcept
    {
        WINRT_ASSERT(m_begin != m_end);
        return *m_begin;
    }

    reference back() noexcept
    {
        WINRT_ASSERT(m_begin != m_end);
        return *(m_end - 1);
    }

    const_reference back() const noexcept
    {
        WINRT_ASSERT(m_begin != m_end);
        return *(m_end - 1);
    }

    pointer data() noexcept
    {
        return m_begin;
    }

    const_pointer data() const noexcept
    {
        return m_begin;
    }

    iterator begin() noexcept
    {
        return m_begin;
    }

    const_iterator begin() const noexcept
    {
        return m_begin;
    }

    const_iterator cbegin() const noexcept
    {
        return m_begin;
    }

    iterator end() noexcept
    {
        return m_end;
    }

    const_iterator end() const noexcept
    {
        return m_end;
    }

    const_iterator cend() const noexcept
    {
        return m_end;
    }

    reverse_iterator rbegin() noexcept
    {
        return reverse_iterator(end());
    }

    const_reverse_iterator rbegin() const noexcept
    {
        return const_reverse_iterator(end());
    }

    const_reverse_iterator crbegin() const noexcept
    {
        return rbegin();
    }

    reverse_iterator rend() noexcept
    {
        return reverse_iterator(begin());
    }

    const_reverse_iterator rend() const noexcept
    {
        return const_reverse_iterator(begin());
    }

    const_reverse_iterator crend() const noexcept
    {
        return rend();
    }

    bool empty() const noexcept
    {
        return m_begin == m_end;
    }

    size_type size() const noexcept
    {
        return static_cast<size_type>(m_end - m_begin);
    }

protected:

    pointer m_begin = nullptr;
    pointer m_end = nullptr;
};

template <typename T>
struct com_array : array_ref<T>
{
    using value_type = T;
    using size_type = std::uint32_t;
    using reference = value_type &;
    using const_reference = const value_type &;
    using pointer = value_type *;
    using const_pointer = const value_type *;
    using iterator = pointer;
    using const_iterator = const_pointer;
    using reverse_iterator = std::reverse_iterator<iterator>;
    using const_reverse_iterator = std::reverse_iterator<const_iterator>;

    com_array(const com_array &) = delete;
    com_array & operator=(const com_array &) = delete;

    com_array() noexcept = default;

    explicit com_array(const size_type count) :
        com_array(count, value_type())
    {}

    com_array(const size_type count, const value_type & value)
    {
        alloc(count);
        std::uninitialized_fill_n(m_begin, count, value);
    }

    template <typename InIt> com_array(InIt first, InIt last)
    {
        alloc(static_cast<size_type>(std::distance(first, last)));
        std::uninitialized_copy(first, last, stdext::make_unchecked_array_iterator(m_begin));
    }

    explicit com_array(const std::vector<value_type> & value) :
        com_array(value.begin(), value.end())
    {}

    template <size_type N>
    explicit com_array(const std::array<value_type, N> & value) :
        com_array(value.begin(), value.end())
    {}

    template <size_type N>
    explicit com_array(const value_type (&value)[N]) :
        com_array(value, value + N)
    {}

    com_array(std::initializer_list<value_type> value) :
        com_array(value.begin(), value.end())
    {}

    com_array(com_array && other) noexcept :
        array_ref(other.m_begin, other.m_end)
    {
        other.m_begin = nullptr;
        other.m_end = nullptr;
    }

    com_array & operator=(com_array && other) noexcept
    {
        m_begin = other.m_begin;
        m_end = other.m_end;
        other.m_begin = nullptr;
        other.m_end = nullptr;
        return *this;
    }

    ~com_array() noexcept
    {
        clear();
    }

    void clear() noexcept
    {
        if (m_begin)
        {
            destruct(std::is_trivially_destructible<value_type>());
            CoTaskMemFree(m_begin);
            m_begin = nullptr;
        }
    }

    friend abi_arg_out<T> * impl_put(com_array & value) noexcept
    {
        WINRT_ASSERT(!value.m_begin);
        return reinterpret_cast<abi_arg_out<T> *>(&value.m_begin);
    }

    friend auto impl_data(com_array & value) noexcept
    {
        return value.m_begin;
    }

    friend void impl_put_size(com_array & value, const uint32_t size) noexcept
    {
        WINRT_ASSERT(value.m_begin || (!value.m_begin && size == 0));
        value.m_end = value.m_begin + size;
    }

    friend auto impl_detach(com_array & value) noexcept
    {
        std::pair<uint32_t, abi_arg_in<T> *> result(value.size(), *reinterpret_cast<abi_arg_in<T> **>(&value));
        value.m_begin = nullptr;
        value.m_end = nullptr;
        return result;
    }

    friend void swap(com_array & left, com_array & right) noexcept
    {
        std::swap(left.m_begin, right.m_begin);
        std::swap(left.m_end, right.m_end);
    }

private:

    void alloc(const size_type count)
    {
        WINRT_ASSERT(empty());

        if (0 != count)
        {
            m_begin = static_cast<value_type *>(CoTaskMemAlloc(count * sizeof(value_type)));

            if (nullptr == m_begin)
            {
                throw std::bad_alloc();
            }

            m_end = m_begin + count;
        }
    }

    void destruct(std::true_type) noexcept
    {}

    void destruct(std::false_type) noexcept
    {
        for (value_type & v : *this)
        {
            v.~value_type();
        }
    }
};

template <typename T>
bool operator==(const array_ref<T> & left, const array_ref<T> & right) noexcept
{
    return std::equal(left.begin(), left.end(), right.begin(), right.end());
}

template <typename T>
bool operator<(const array_ref<T> & left, const array_ref<T> & right) noexcept
{
    return std::lexicographical_compare(left.begin(), left.end(), right.begin(), right.end());
}

template <typename T> bool operator!=(const array_ref<T> & left, const array_ref<T> & right) noexcept { return !(left == right); }
template <typename T> bool operator>(const array_ref<T> & left, const array_ref<T> & right) noexcept { return right < left; }
template <typename T> bool operator<=(const array_ref<T> & left, const array_ref<T> & right) noexcept { return !(right < left); }
template <typename T> bool operator>=(const array_ref<T> & left, const array_ref<T> & right) noexcept { return !(left < right); }

namespace impl {

template <typename T>
struct array_size_proxy
{
    array_size_proxy & operator=(const array_size_proxy &) = delete;

    array_size_proxy(com_array<T> & value) noexcept :
        m_value(value)
    {}

    ~array_size_proxy() noexcept
    {
        impl_put_size(m_value, m_size);
    }

    operator uint32_t * () noexcept
    {
        return &m_size;
    }

    operator unsigned long * () noexcept
    {
        return reinterpret_cast<unsigned long *>(&m_size);
    }

private:

    com_array<T> & m_value;
    uint32_t m_size = 0;
};

template <typename T>
struct com_array_proxy
{
    com_array_proxy(uint32_t * size, abi_arg_out<T> * value) noexcept :
        m_size(size),
        m_value(value)
    {}

    ~com_array_proxy() noexcept
    {
        std::tie(*m_size, *m_value) = impl_detach(m_temp);
    }

    operator com_array<T> &() noexcept
    {
        return m_temp;
    }

    com_array_proxy(const com_array_proxy &) noexcept
    {
        WINRT_ASSERT(false);
    }

    com_array_proxy & operator=(const com_array_proxy &) noexcept
    {
        WINRT_ASSERT(false);
        return *this;
    }

private:

    uint32_t * m_size;
    abi_arg_out<T> * m_value;
    com_array<T> m_temp;
};

template <typename T>
struct accessors<com_array<T>>
{
    static auto put(com_array<T> & object) noexcept
    {
        return impl_put(object);
    }

    static array_size_proxy<T> put_size(com_array<T> & object) noexcept
    {
        return array_size_proxy<T>(object);
    }

    static auto detach(com_array<T> & object) noexcept
    {
        return impl_detach(object);
    }

    static auto data(com_array<T> & object) noexcept
    {
        return impl_data(object);
    }
};

template <typename T>
struct accessors<array_ref<T>>
{
    static auto get(array_ref<T> object) noexcept
    {
        return reinterpret_cast<abi_arg_out<std::remove_const_t<T>>>(const_cast<std::remove_const_t<T> *>(object.data()));
    }
};

}

template <typename T>
auto detach(uint32_t * __valueSize, abi_arg_out<T> * value) noexcept
{
    return impl::com_array_proxy<T>(__valueSize, value);
}

namespace Windows {

struct IUnknown
{
    IUnknown() noexcept = default;
    IUnknown(std::nullptr_t) noexcept {}
    void * operator new(size_t) = delete;

    IUnknown(const IUnknown & other) noexcept :
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

    IUnknown & operator=(const IUnknown & other) noexcept
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

    auto operator->() const noexcept
    {
        return static_cast<impl::no_ref< ::IUnknown> *>(m_ptr);
    }

    IUnknown & operator=(std::nullptr_t) noexcept
    {
        impl_release();
        return *this;
    }

    template <typename U>
    auto as() const
    {
        std::conditional_t<std::is_base_of_v<IUnknown, U>, U, com_ptr<U>> temp = nullptr;
        check_hresult(m_ptr->QueryInterface(__uuidof(abi_default_interface<U>), reinterpret_cast<void **>(put(temp))));
        return temp;
    }

    friend auto impl_get(const IUnknown & object) noexcept
    {
        return object.m_ptr;
    }

    friend auto impl_put(IUnknown & object) noexcept
    {
        WINRT_ASSERT(!object);
        return &object.m_ptr;
    }

    friend auto impl_detach(IUnknown & object) noexcept
    {
        auto temp = object.m_ptr;
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

    void impl_copy(const IUnknown & other) noexcept
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
        auto temp = m_ptr;

        if (temp)
        {
            m_ptr = nullptr;
            temp->Release();
        }
    }
};

}

namespace impl {

template <> struct traits<Windows::IUnknown>
{
    using abi = ::IUnknown;
};

template <typename T>
struct accessors<T, std::enable_if_t<std::is_base_of<Windows::IUnknown, T>::value>>
{
    static auto get(const T & object) noexcept
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
    static void copy_to(const T & object, V & value) noexcept
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
};

}

namespace Windows {

inline bool operator==(const IUnknown & left, const IUnknown & right) noexcept
{
    return get(left) == get(right);
}

inline bool operator!=(const IUnknown & left, const IUnknown & right) noexcept
{
    return !(left == right);
}

inline bool operator<(const IUnknown & left, const IUnknown & right) noexcept
{
    return get(left) < get(right);
}

inline bool operator>(const IUnknown & left, const IUnknown & right) noexcept
{
    return right < left;
}

inline bool operator<=(const IUnknown & left, const IUnknown & right) noexcept
{
    return !(right < left);
}

inline bool operator>=(const IUnknown & left, const IUnknown & right) noexcept
{
    return !(left < right);
}

}

namespace Windows {

struct IInspectable;
struct IAsyncInfo;
struct IActivationFactory;

template <typename T>
class impl_IInspectable
{
    auto shim() const { return impl::shim<T, IInspectable>(this); }

public:

    hstring RuntimeClassName() const;
    com_array<GUID> Iids() const;
};

template <typename T>
class impl_IAsyncInfo
{
    auto shim() const { return impl::shim<T, IAsyncInfo>(this); }

public:

    uint32_t Id() const;
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

}

namespace impl {

template <> struct traits<Windows::IInspectable>
{
    using abi = ABI::Windows::IInspectable;
    template <typename T> using consume = Windows::impl_IInspectable<T>;
};

template <> struct traits<Windows::IAsyncInfo>
{
    using abi = ABI::Windows::IAsyncInfo;
    template <typename T> using consume = Windows::impl_IAsyncInfo<T>;
};

template <> struct traits<Windows::IActivationFactory>
{
    using abi = ABI::Windows::IActivationFactory;
    template <typename T> using consume = Windows::impl_IActivationFactory<T>;
};

}

namespace Windows {

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

template <typename T> hstring impl_IInspectable<T>::RuntimeClassName() const
{
    hstring name;
    check_hresult(shim()->get_RuntimeClassName(put(name)));
    return name;
}

template <typename T> com_array<GUID> impl_IInspectable<T>::Iids() const
{
    com_array<GUID> result;
    check_hresult(shim()->get_Iids(put_size(result), put(result)));
    return result;
}

template <typename T> uint32_t impl_IAsyncInfo<T>::Id() const
{
    uint32_t id = 0;
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

template <typename T, typename I = typename T::default_interface, typename ... Args, std::enable_if_t<!impl::has_composable<T>::value> * = nullptr>
auto make(Args && ... args)
{
    std::conditional_t<std::is_base_of_v<Windows::IUnknown, I>, I, com_ptr<I>> instance = nullptr;
    *put(instance) = new T(std::forward<Args>(args) ...);
    return instance;
}

template <typename T, typename I = typename T::default_interface, typename ... Args, std::enable_if_t<impl::has_composable<T>::value> * = nullptr>
auto make(Args && ... args)
{
    com_ptr<I> instance;
    *put(instance) = new T(std::forward<Args>(args) ...);
    return instance.template as<typename T::composable>();
}

template <typename T, typename ... Args>
auto make_self(Args && ... args)
{
    com_ptr<T> instance;
    *put(instance) = new T(std::forward<Args>(args) ...);
    return instance;
}

template <typename Interface>
struct cloaked : Interface {};

namespace impl {

template <typename T>
struct uncloak
{
    using type = T;
};

template <typename T>
struct uncloak<cloaked<T>>
{
    using type = T;
};

template <typename T>
using uncloak_t = typename uncloak<T>::type;

template <typename T, typename Interface, typename Enable = void>
struct derive_from : abi<uncloak_t<Interface>> {};

template <typename T, typename Interface>
struct derive_from<T, Interface, std::enable_if_t<can_produce<uncloak_t<Interface>>::value>> : traits<uncloak_t<Interface>>::template produce<T> {};

}

template <typename T, typename ... Interfaces>
class __declspec(novtable) implements : public impl::derive_from<T, Interfaces> ...
{
    template <typename Interface>
    struct is_cloaked : std::conditional_t<std::is_base_of_v<ABI::Windows::IInspectable, abi<Interface>>, std::false_type, std::true_type> {};

    template <typename Interface>
    struct is_cloaked<cloaked<Interface>> : std::true_type {};

    template <typename First, typename ... Rest>
    struct first
    {
        using type = impl::uncloak_t<First>;
    };

    template <int = 0>
    constexpr uint32_t uncloaked_interfaces() const noexcept
    {
        return 0;
    }

    template <typename First, typename ... Rest>
    constexpr uint32_t uncloaked_interfaces() const noexcept
    {
        return !is_cloaked<First>::value + uncloaked_interfaces<Rest ...>();
    }

    template <int = 0>
    void copy_interfaces(GUID *) const noexcept {}

    template <typename First, typename ... Rest>
    void copy_interfaces(GUID * ids, std::enable_if_t<is_cloaked<First>::value> * = nullptr) const noexcept
    {
        copy_interfaces<Rest ...>(ids);
    }

    template <typename First, typename ... Rest>
    void copy_interfaces(GUID * ids, std::enable_if_t<!is_cloaked<First>::value> * = nullptr) const noexcept
    {
        *ids++ = __uuidof(abi<First>);
        copy_interfaces<Rest ...>(ids);
    }

    template <int = 0>
    constexpr bool is_inspectable() const noexcept
    {
        return false;
    }

    template <typename First, typename ... Rest>
    constexpr bool is_inspectable() const noexcept
    {
        return std::is_base_of_v<ABI::Windows::IInspectable, abi<impl::uncloak_t<First>>> || is_inspectable<Rest ...>();
    }

    template <typename First, typename ... Rest>
    auto find_unknown() const noexcept
    {
        return impl::abi_cast<impl::uncloak_t<First>>(this);
    }

    template <int = 0>
    auto find_inspectable() const noexcept
    {
        return nullptr;
    }

    template <typename First, typename ... Rest>
    auto find_inspectable(std::enable_if_t<std::is_base_of_v<ABI::Windows::IInspectable, abi<impl::uncloak_t<First>>>> * = nullptr) const noexcept
    {
        return impl::abi_cast<impl::uncloak_t<First>>(this);
    }

    template <typename First, typename ... Rest>
    auto find_inspectable(std::enable_if_t<!std::is_base_of_v<ABI::Windows::IInspectable, abi<impl::uncloak_t<First>>>> * = nullptr) const noexcept
    {
        return find_inspectable<Rest ...>();
    }

    template <int = 0>
    void * find_interface(const GUID &) const noexcept
    {
        return nullptr;
    }

    template <typename First, typename ... Rest>
    void * find_interface(const GUID & id) const noexcept
    {
        if (id == __uuidof(abi<impl::uncloak_t<First>>))
        {
            return impl::abi_cast<impl::uncloak_t<First>>(this);
        }

        return find_interface<Rest ...>(id);
    }

protected:

    std::atomic<uint32_t> m_references{1};

    implements() noexcept = default;

    void * query_interface(const GUID & id) noexcept
    {
        if (id == __uuidof(IUnknown) || id == __uuidof(::IAgileObject))
        {
            return find_unknown<Interfaces ...>();
        }

        if (is_inspectable<Interfaces ...>() && id == __uuidof(ABI::Windows::IInspectable))
        {
            return find_inspectable<Interfaces ...>();
        }

        return find_interface<Interfaces ...>(id);
    }

public:

    using default_interface = typename first<Interfaces ...>::type;

    implements(const implements &) = delete;
    implements & operator=(const implements &) = delete;

    auto impl_unknown() const noexcept
    {
        return static_cast<IUnknown *>(find_unknown<Interfaces ...>());
    }

    operator Windows::IUnknown() const noexcept
    {
        return impl::winrt_cast<Windows::IUnknown>(static_cast<IUnknown *>(find_unknown<Interfaces ...>()));
    }

    operator Windows::IInspectable() const noexcept
    {
        return impl::winrt_cast<Windows::IInspectable>(static_cast<ABI::Windows::IInspectable *>(find_inspectable<Interfaces ...>()));
    }

    HRESULT __stdcall QueryInterface(const GUID & id, void ** object) noexcept override
    {
        *object = query_interface(id);

        if (*object == nullptr)
        {
            return E_NOINTERFACE;
        }

        static_cast<IUnknown *>(*object)->AddRef();
        return S_OK;
    }

    unsigned long __stdcall AddRef() noexcept override
    {
        return 1 + m_references.fetch_add(1, std::memory_order_relaxed);
    }

    unsigned long __stdcall Release() noexcept override
    {
        const uint32_t remaining = m_references.fetch_sub(1, std::memory_order_release) - 1;

        if (remaining == 0)
        {
            std::atomic_thread_fence(std::memory_order_acquire);
            delete static_cast<T *>(this);
        }

        return remaining;
    }

    hstring RuntimeClassName()
    {
        throw hresult_not_implemented();
    }

    HRESULT __stdcall get_RuntimeClassName(HSTRING * name) noexcept
    {
        try
        {
            *name = detach(static_cast<T *>(this)->RuntimeClassName());
            return S_OK;
        }
        catch (...) { return impl::to_hresult(); }
    }

    HRESULT __stdcall get_Iids(uint32_t * count, GUID ** array) noexcept
    {
        *count = 0;
        *array = nullptr;

        const uint32_t localCount = uncloaked_interfaces<Interfaces ...>();

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

    HRESULT __stdcall get_TrustLevel(Windows::TrustLevel * trustLevel) noexcept
    {
        *trustLevel = Windows::TrustLevel::BaseTrust;
        return S_OK;
    }
};

namespace ABI { namespace Windows {

struct __declspec(uuid("00000037-0000-0000-C000-000000000046")) __declspec(novtable) IWeakReference : IUnknown
{
    virtual HRESULT __stdcall abi_Resolve(const GUID & iid, IInspectable ** objectReference) = 0;

    template <typename Qi> HRESULT __stdcall abi_Resolve(Qi ** objectReference) noexcept
    {
        return abi_Resolve(__uuidof(Qi), reinterpret_cast<IInspectable **>(objectReference));
    }
};

struct __declspec(uuid("00000038-0000-0000-C000-000000000046")) __declspec(novtable) IWeakReferenceSource : IUnknown
{
    virtual HRESULT __stdcall abi_GetWeakReference(IWeakReference ** weakReference) = 0;
};

}}

template <typename T>
struct weak
{
    weak() noexcept = default;

    weak(const T & object)
    {
        check_hresult(object.as<ABI::Windows::IWeakReferenceSource>()->abi_GetWeakReference(put(m_ref)));
    }

    T resolve() const noexcept
    {
        T object = nullptr;
        m_ref->abi_Resolve(put(object));
        return object;
    }

private:

    com_ptr<ABI::Windows::IWeakReference> m_ref;
};

template <typename T>
weak<T> make_weak(T const & object)
{
    return object;
}

template <typename T, typename ... R>
struct overrides : implements<T, R ...>
{
    template <typename Qi>
    Qi as() const
    {
        return m_inner.as<Qi>();
    }

    HRESULT __stdcall QueryInterface(const GUID & id, void ** object) noexcept override
    {
        *object = query_interface(id);

        if (*object == nullptr)
        {
            return m_inner->QueryInterface(id, object);
        }

        static_cast<IUnknown *>(*object)->AddRef();
        return S_OK;
    }

protected:

    Windows::IInspectable m_inner;
};

struct event_token
{
    int64_t value;
};

namespace impl {

inline void ActivateInstance(HSTRING classId, Windows::IInspectable & instance)
{
    check_hresult(WINRT_RoActivateInstance(classId, reinterpret_cast<void **>(put(instance))));
}

template <typename Interface>
void ActivateInstance(HSTRING classId, Interface & result)
{
    Windows::IInspectable instance;
    ActivateInstance(classId, instance);
    result = instance.as<Interface>();
}

}

enum class InitializeType
{
    SingleThreaded,
    MultiThreaded
};

inline void Initialize(const InitializeType type = InitializeType::MultiThreaded)
{
    check_hresult(WINRT_RoInitialize(static_cast<uint32_t>(type)));
}

inline void Uninitialize() noexcept
{
    WINRT_RoUninitialize();
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
    check_hresult(WINRT_RoGetActivationFactory(get(classId), __uuidof(abi<Interface>), reinterpret_cast<void **>(put(factory))));
    return factory;
}

namespace impl {

template <typename T, typename Enable = void>
struct argument
{
    static constexpr T empty() noexcept
    {
        return{};
    }
};

template <typename T>
struct argument<T, std::enable_if_t<std::is_base_of<Windows::IUnknown, T>::value>>
{
    static constexpr T empty() noexcept
    {
        return nullptr;
    }
};

}

namespace ABI { namespace Windows { namespace Foundation {

template <typename TProgress> struct AsyncActionProgressHandler;
template <typename TProgress> struct IAsyncActionWithProgress;
template <typename TProgress> struct AsyncActionWithProgressCompletedHandler;
template <typename TResult, typename TProgress> struct AsyncOperationProgressHandler;
template <typename TResult, typename TProgress> struct AsyncOperationWithProgressCompletedHandler;
template <typename TResult> struct AsyncOperationCompletedHandler;
template <typename T> struct EventHandler;
template <typename TSender, typename TArgs> struct TypedEventHandler;
template <typename TResult> struct IAsyncOperation;
template <typename TResult, typename TProgress> struct IAsyncOperationWithProgress;
template <typename T> struct IReference;

template <typename TProgress>
struct __declspec(novtable) impl_AsyncActionProgressHandler : IUnknown
{
    virtual HRESULT __stdcall abi_Invoke(IAsyncActionWithProgress<TProgress> * asyncInfo, arg_in<TProgress> progressInfo) = 0;
};

template <typename TProgress>
struct __declspec(novtable) impl_IAsyncActionWithProgress : IInspectable
{
    virtual HRESULT __stdcall put_Progress(AsyncActionProgressHandler<TProgress> * handler) = 0;
    virtual HRESULT __stdcall get_Progress(AsyncActionProgressHandler<TProgress> ** handler) = 0;
    virtual HRESULT __stdcall put_Completed(AsyncActionWithProgressCompletedHandler<TProgress> * handler) = 0;
    virtual HRESULT __stdcall get_Completed(AsyncActionWithProgressCompletedHandler<TProgress> ** handler) = 0;
    virtual HRESULT __stdcall abi_GetResults() = 0;
};

template <typename TProgress>
struct __declspec(novtable) impl_AsyncActionWithProgressCompletedHandler : IUnknown
{
    virtual HRESULT __stdcall abi_Invoke(IAsyncActionWithProgress<TProgress> * asyncInfo, winrt::Windows::AsyncStatus status) = 0;
};

template <typename TResult, typename TProgress>
struct __declspec(novtable) impl_AsyncOperationProgressHandler : IUnknown
{
    virtual HRESULT __stdcall abi_Invoke(IAsyncOperationWithProgress<TResult, TProgress> * asyncInfo, arg_in<TProgress> progressInfo) = 0;
};

template <typename TResult, typename TProgress>
struct __declspec(novtable) impl_AsyncOperationWithProgressCompletedHandler : IUnknown
{
    virtual HRESULT __stdcall abi_Invoke(IAsyncOperationWithProgress<TResult, TProgress> * asyncInfo, winrt::Windows::AsyncStatus status) = 0;
};

template <typename TResult>
struct __declspec(novtable) impl_AsyncOperationCompletedHandler : IUnknown
{
    virtual HRESULT __stdcall abi_Invoke(IAsyncOperation<TResult> * asyncInfo, winrt::Windows::AsyncStatus status) = 0;
};

template <typename T>
struct __declspec(novtable) impl_EventHandler : IUnknown
{
    virtual HRESULT __stdcall abi_Invoke(IInspectable * sender, arg_in<T> args) = 0;
};

template <typename TSender, typename TArgs>
struct __declspec(novtable) impl_TypedEventHandler : IUnknown
{
    virtual HRESULT __stdcall abi_Invoke(arg_in<TSender> sender, arg_in<TArgs> args) = 0;
};

template <typename TResult>
struct __declspec(novtable) impl_IAsyncOperation : IInspectable
{
    virtual HRESULT __stdcall put_Completed(AsyncOperationCompletedHandler<TResult> * handler) = 0;
    virtual HRESULT __stdcall get_Completed(AsyncOperationCompletedHandler<TResult> ** handler) = 0;
    virtual HRESULT __stdcall abi_GetResults(arg_out<TResult> results) = 0;
};

template <typename TResult, typename TProgress>
struct __declspec(novtable) impl_IAsyncOperationWithProgress : IInspectable
{
    virtual HRESULT __stdcall put_Progress(AsyncOperationProgressHandler<TResult, TProgress> * handler) = 0;
    virtual HRESULT __stdcall get_Progress(AsyncOperationProgressHandler<TResult, TProgress> ** handler) = 0;
    virtual HRESULT __stdcall put_Completed(AsyncOperationWithProgressCompletedHandler<TResult, TProgress> * handler) = 0;
    virtual HRESULT __stdcall get_Completed(AsyncOperationWithProgressCompletedHandler<TResult, TProgress> ** handler) = 0;
    virtual HRESULT __stdcall abi_GetResults(arg_out<TResult> results) = 0;
};

template <typename T>
struct __declspec(novtable) impl_IReference : IInspectable
{
    virtual HRESULT __stdcall get_Value(arg_out<T> value) = 0;
};

}}}

namespace Windows { namespace Foundation {

template <typename TProgress> struct AsyncActionProgressHandler;
template <typename TProgress> struct IAsyncActionWithProgress;
template <typename TProgress> struct AsyncActionWithProgressCompletedHandler;
template <typename TResult, typename TProgress> struct AsyncOperationProgressHandler;
template <typename TResult, typename TProgress> struct AsyncOperationWithProgressCompletedHandler;
template <typename TResult> struct AsyncOperationCompletedHandler;
template <typename T> struct EventHandler;
template <typename TSender, typename TArgs> struct TypedEventHandler;
template <typename TResult> struct IAsyncOperation;
template <typename TResult, typename TProgress> struct IAsyncOperationWithProgress;
template <typename T> struct IReference;

template <typename D, typename TProgress>
class impl_consume_IAsyncActionWithProgress
{
    auto shim() const { return impl::shim<D, IAsyncActionWithProgress<TProgress>>(this); }

public:

    void Progress(const AsyncActionProgressHandler<TProgress> & handler) const
    {
        check_hresult(shim()->put_Progress(get(handler)));
    }

    AsyncActionProgressHandler<TProgress> Progress() const
    {
        AsyncActionProgressHandler<TProgress> handler;
        check_hresult(shim()->get_Progress(put(handler)));
        return handler;
    }

    void Completed(const AsyncActionWithProgressCompletedHandler<TProgress> & handler) const
    {
        check_hresult(shim()->put_Completed(get(handler)));
    }

    AsyncActionWithProgressCompletedHandler<TProgress> Completed() const
    {
        AsyncActionWithProgressCompletedHandler<TProgress> handler;
        check_hresult(shim()->get_Completed(put(handler)));
        return handler;
    }

    void GetResults() const
    {
        check_hresult(shim()->abi_GetResults());
    }
};

template <typename D, typename TResult>
class impl_consume_IAsyncOperation
{
    auto shim() const { return impl::shim<D, IAsyncOperation<TResult>>(this); }

public:

    void Completed(const AsyncOperationCompletedHandler<TResult> & handler) const
    {
        check_hresult(shim()->put_Completed(get(handler)));
    }

    AsyncOperationCompletedHandler<TResult> Completed() const
    {
        AsyncOperationCompletedHandler<TResult> temp;
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
class impl_consume_IAsyncOperationWithProgress
{
    auto shim() const { return impl::shim<D, IAsyncOperationWithProgress<TResult, TProgress>>(this); }

public:

    void Progress(const AsyncOperationProgressHandler<TResult, TProgress> & handler) const
    {
        check_hresult(shim()->put_Progress(get(handler)));
    }

    AsyncOperationProgressHandler<TResult, TProgress> Progress() const
    {
        AsyncOperationProgressHandler<TResult, TProgress> handler;
        check_hresult(shim()->get_Progress(put(handler)));
        return handler;
    }

    void Completed(const AsyncOperationWithProgressCompletedHandler<TResult, TProgress> & handler) const
    {
        check_hresult(shim()->put_Completed(get(handler)));
    }

    AsyncOperationWithProgressCompletedHandler<TResult, TProgress> Completed() const
    {
        AsyncOperationWithProgressCompletedHandler<TResult, TProgress> handler;
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
class impl_consume_IReference
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

}}

namespace impl {

template <typename TProgress> struct traits<Windows::Foundation::AsyncActionProgressHandler<TProgress>>
{
    using abi = ABI::Windows::Foundation::AsyncActionProgressHandler<abi<TProgress>>;
};

template <typename TProgress> struct traits<Windows::Foundation::IAsyncActionWithProgress<TProgress>>
{
    using abi = ABI::Windows::Foundation::IAsyncActionWithProgress<abi<TProgress>>;
    template <typename D> using consume = Windows::Foundation::impl_consume_IAsyncActionWithProgress<D, TProgress>;
};

template <typename TProgress> struct traits<Windows::Foundation::AsyncActionWithProgressCompletedHandler<TProgress>>
{
    using abi = ABI::Windows::Foundation::AsyncActionWithProgressCompletedHandler<abi<TProgress>>;
};

template <typename TResult, typename TProgress> struct traits<Windows::Foundation::AsyncOperationProgressHandler<TResult, TProgress>>
{
    using abi = ABI::Windows::Foundation::AsyncOperationProgressHandler<abi<TResult>, abi<TProgress>>;
};

template <typename TResult, typename TProgress> struct traits<Windows::Foundation::AsyncOperationWithProgressCompletedHandler<TResult, TProgress>>
{
    using abi = ABI::Windows::Foundation::AsyncOperationWithProgressCompletedHandler<abi<TResult>, abi<TProgress>>;
};

template <typename TResult> struct traits<Windows::Foundation::AsyncOperationCompletedHandler<TResult>>
{
    using abi = ABI::Windows::Foundation::AsyncOperationCompletedHandler<abi<TResult>>;
};

template <typename T> struct traits<Windows::Foundation::EventHandler<T>>
{
    using abi = ABI::Windows::Foundation::EventHandler<abi<T>>;
};

template <typename TSender, typename TArgs> struct traits<Windows::Foundation::TypedEventHandler<TSender, TArgs>>
{
    using abi = ABI::Windows::Foundation::TypedEventHandler<abi<TSender>, abi<TArgs>>;
};

template <typename TResult> struct traits<Windows::Foundation::IAsyncOperation<TResult>>
{
    using abi = ABI::Windows::Foundation::IAsyncOperation<abi<TResult>>;
    template <typename D> using consume = Windows::Foundation::impl_consume_IAsyncOperation<D, TResult>;
};

template <typename TResult, typename TProgress> struct traits<Windows::Foundation::IAsyncOperationWithProgress<TResult, TProgress>>
{
    using abi = ABI::Windows::Foundation::IAsyncOperationWithProgress<abi<TResult>, abi<TProgress>>;
    template <typename D> using consume = Windows::Foundation::impl_consume_IAsyncOperationWithProgress<D, TResult, TProgress>;
};

template <typename T> struct traits<Windows::Foundation::IReference<T>>
{
    using abi = ABI::Windows::Foundation::IReference<abi<T>>;
    template <typename D> using consume = Windows::Foundation::impl_consume_IReference<D, T>;
};

}

namespace Windows { namespace Foundation {


template <typename TProgress>
struct WINRT_EBO AsyncActionProgressHandler : IUnknown
{
    AsyncActionProgressHandler(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<AsyncActionProgressHandler>(m_ptr); }
    template <typename H> AsyncActionProgressHandler(H handler);
    template <typename Object, typename Method> AsyncActionProgressHandler(Object * object, Method method);
    void operator()(const IAsyncActionWithProgress<TProgress> & sender, const TProgress & args) const;
};

template <typename TProgress>
struct WINRT_EBO IAsyncActionWithProgress :
    IInspectable,
    consume<IAsyncActionWithProgress<TProgress>>,
    requires<IAsyncActionWithProgress<TProgress>, IAsyncInfo>
{
    IAsyncActionWithProgress(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IAsyncActionWithProgress>(m_ptr); }
};

template <typename TProgress>
struct WINRT_EBO AsyncActionWithProgressCompletedHandler : IUnknown
{
    AsyncActionWithProgressCompletedHandler(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<AsyncActionWithProgressCompletedHandler>(m_ptr); }
    template <typename H> AsyncActionWithProgressCompletedHandler(H handler);
    template <typename Object, typename Method> AsyncActionWithProgressCompletedHandler(Object * object, Method method);
    void operator()(const IAsyncActionWithProgress<TProgress> & sender, const AsyncStatus args) const;
};

template <typename TResult, typename TProgress>
struct WINRT_EBO AsyncOperationProgressHandler : IUnknown
{
    AsyncOperationProgressHandler(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<AsyncOperationProgressHandler>(m_ptr); }
    template <typename H> AsyncOperationProgressHandler(H handler);
    template <typename Object, typename Method> AsyncOperationProgressHandler(Object * object, Method method);
    void operator()(const IAsyncOperationWithProgress<TResult, TProgress> & sender, const TProgress & args) const;
};

template <typename TResult, typename TProgress>
struct WINRT_EBO AsyncOperationWithProgressCompletedHandler : IUnknown
{
    AsyncOperationWithProgressCompletedHandler(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<AsyncOperationWithProgressCompletedHandler>(m_ptr); }
    template <typename H> AsyncOperationWithProgressCompletedHandler(H handler);
    template <typename Object, typename Method> AsyncOperationWithProgressCompletedHandler(Object * object, Method method);
    void operator()(const IAsyncOperationWithProgress<TResult, TProgress> & sender, const AsyncStatus args) const;
};

template <typename TResult>
struct WINRT_EBO AsyncOperationCompletedHandler : IUnknown
{
    AsyncOperationCompletedHandler(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<AsyncOperationCompletedHandler>(m_ptr); }
    template <typename H> AsyncOperationCompletedHandler(H handler);
    template <typename Object, typename Method> AsyncOperationCompletedHandler(Object * object, Method method);
    void operator()(const IAsyncOperation<TResult> & sender, const AsyncStatus args) const;
};

template <typename T>
struct WINRT_EBO EventHandler : IUnknown
{
    EventHandler(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<EventHandler>(m_ptr); }
    template <typename Handler> EventHandler(Handler handler);
    template <typename Object, typename Method> EventHandler(Object * object, Method method);
    void operator()(const IInspectable & sender, const T & args) const;
};

template <typename TSender, typename TArgs>
struct WINRT_EBO TypedEventHandler : IUnknown
{
    TypedEventHandler(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<TypedEventHandler>(m_ptr); }
    template <typename Handler> TypedEventHandler(Handler handler);
    template <typename Object, typename Method> TypedEventHandler(Object * object, Method method);
    void operator()(const TSender & sender, const TArgs & args) const;
};

template <typename TResult>
struct WINRT_EBO IAsyncOperation :
    IInspectable,
    consume<IAsyncOperation<TResult>>,
    requires<IAsyncOperation<TResult>, IAsyncInfo>
{
    IAsyncOperation(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IAsyncOperation>(m_ptr); }
};

template <typename TResult, typename TProgress>
struct WINRT_EBO IAsyncOperationWithProgress :
    IInspectable,
    consume<IAsyncOperationWithProgress<TResult, TProgress>>,
    requires<IAsyncOperationWithProgress<TResult, TProgress>, IAsyncInfo>
{
    IAsyncOperationWithProgress(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IAsyncOperationWithProgress>(m_ptr); }
};

struct IPropertyValue;

template <typename T>
struct WINRT_EBO IReference :
    IInspectable,
    consume<IReference<T>> //,
    // requires<IReference<T>, IPropertyValue>
{
    IReference(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IReference>(m_ptr); }

    IReference(const T & value);
};

template <typename TProgress, typename H>
struct impl_AsyncActionProgressHandler : implements<impl_AsyncActionProgressHandler<TProgress, H>, abi<AsyncActionProgressHandler<TProgress>>>
{
    H m_handler;
    impl_AsyncActionProgressHandler(H handler) : m_handler(handler) {}

    HRESULT __stdcall abi_Invoke(abi_arg_in<IAsyncActionWithProgress<TProgress>> sender, abi_arg_in<TProgress> args) noexcept override
    {
        try
        {
            m_handler(*reinterpret_cast<const IAsyncActionWithProgress<TProgress> *>(&sender), *reinterpret_cast<const TProgress *>(&args));
            return S_OK;
        }
        catch (...) { return impl::to_hresult(); }
    }
};

template <typename TProgress> template <typename H> AsyncActionProgressHandler<TProgress>::AsyncActionProgressHandler(H handler) :
    AsyncActionProgressHandler(make<impl_AsyncActionProgressHandler<TProgress, H>, AsyncActionProgressHandler>(handler))
{}

template <typename TProgress> template <typename Object, typename Method> AsyncActionProgressHandler<TProgress>::AsyncActionProgressHandler(Object * object, Method method) :
    AsyncActionProgressHandler(std::bind(std::mem_fn(method), object, std::placeholders::_1, std::placeholders::_2))
{}

template <typename TProgress> void AsyncActionProgressHandler<TProgress>::operator()(const IAsyncActionWithProgress<TProgress> & sender, const TProgress & args) const
{
    check_hresult((*this)->abi_Invoke(get(sender), get(args)));
}

template <typename TProgress, typename H>
struct impl_AsyncActionWithProgressCompletedHandler : implements<impl_AsyncActionWithProgressCompletedHandler<TProgress, H>, abi<AsyncActionWithProgressCompletedHandler<TProgress>>>
{
    H m_handler;
    impl_AsyncActionWithProgressCompletedHandler(H handler) : m_handler(handler) {}

    HRESULT __stdcall abi_Invoke(abi_arg_in<IAsyncActionWithProgress<TProgress>> sender, AsyncStatus args) noexcept override
    {
        try
        {
            m_handler(*reinterpret_cast<const IAsyncActionWithProgress<TProgress> *>(&sender), args);
            return S_OK;
        }
        catch (...) { return impl::to_hresult(); }
    }
};

template <typename TProgress> template <typename H> AsyncActionWithProgressCompletedHandler<TProgress>::AsyncActionWithProgressCompletedHandler(H handler) :
    AsyncActionWithProgressCompletedHandler(make<impl_AsyncActionWithProgressCompletedHandler<TProgress, H>, AsyncActionWithProgressCompletedHandler<TProgress>>(handler))
{}

template <typename TProgress> template <typename Object, typename Method> AsyncActionWithProgressCompletedHandler<TProgress>::AsyncActionWithProgressCompletedHandler(Object * object, Method method) :
    AsyncActionWithProgressCompletedHandler(std::bind(std::mem_fn(method), object, std::placeholders::_1, std::placeholders::_2))
{}

template <typename TProgress> void AsyncActionWithProgressCompletedHandler<TProgress>::operator()(const IAsyncActionWithProgress<TProgress> & sender, const AsyncStatus args) const
{
    check_hresult((*this)->abi_Invoke(get(sender), args));
}

template <typename TResult, typename TProgress, typename H>
struct impl_AsyncOperationProgressHandler : implements<impl_AsyncOperationProgressHandler<TResult, TProgress, H>, abi<AsyncOperationProgressHandler<TResult, TProgress>>>
{
    H m_handler;
    impl_AsyncOperationProgressHandler(H handler) : m_handler(handler) {}

    HRESULT __stdcall abi_Invoke(abi_arg_in<IAsyncOperationWithProgress<TResult, TProgress>> sender, abi_arg_in<TProgress> args) noexcept override
    {
        try
        {
            m_handler(*reinterpret_cast<const IAsyncOperationWithProgress<TResult, TProgress> *>(&sender), *reinterpret_cast<const TProgress *>(&args));
            return S_OK;
        }
        catch (...) { return impl::to_hresult(); }
    }
};

template <typename TResult, typename TProgress> template <typename H> AsyncOperationProgressHandler<TResult, TProgress>::AsyncOperationProgressHandler(H handler) :
    AsyncOperationProgressHandler(make<impl_AsyncOperationProgressHandler<TResult, TProgress, H>, AsyncOperationProgressHandler<TResult, TProgress>>(handler))
{}

template <typename TResult, typename TProgress> template <typename Object, typename Method> AsyncOperationProgressHandler<TResult, TProgress>::AsyncOperationProgressHandler(Object * object, Method method) :
    AsyncOperationProgressHandler(std::bind(std::mem_fn(method), object, std::placeholders::_1, std::placeholders::_2))
{}

template <typename TResult, typename TProgress> void AsyncOperationProgressHandler<TResult, TProgress>::operator()(const IAsyncOperationWithProgress<TResult, TProgress> & sender, const TProgress & args) const
{
    check_hresult((*this)->abi_Invoke(get(sender), get(args)));
}

template <typename TResult, typename TProgress, typename H>
struct impl_AsyncOperationWithProgressCompletedHandler : implements<impl_AsyncOperationWithProgressCompletedHandler<TResult, TProgress, H>, abi<AsyncOperationWithProgressCompletedHandler<TResult, TProgress>>>
{
    H m_handler;
    impl_AsyncOperationWithProgressCompletedHandler(H handler) : m_handler(handler) {}

    HRESULT __stdcall abi_Invoke(abi_arg_in<IAsyncOperationWithProgress<TResult, TProgress>> sender, AsyncStatus args) noexcept override
    {
        try
        {
            m_handler(*reinterpret_cast<const IAsyncOperationWithProgress<TResult, TProgress> *>(&sender), args);
            return S_OK;
        }
        catch (...) { return impl::to_hresult(); }
    }
};

template <typename TResult, typename TProgress> template <typename H> AsyncOperationWithProgressCompletedHandler<TResult, TProgress>::AsyncOperationWithProgressCompletedHandler(H handler) :
    AsyncOperationWithProgressCompletedHandler(make<impl_AsyncOperationWithProgressCompletedHandler<TResult, TProgress, H>, AsyncOperationWithProgressCompletedHandler<TResult, TProgress>>(handler))
{}

template <typename TResult, typename TProgress> template <typename Object, typename Method> AsyncOperationWithProgressCompletedHandler<TResult, TProgress>::AsyncOperationWithProgressCompletedHandler(Object * object, Method method) :
    AsyncOperationWithProgressCompletedHandler(std::bind(std::mem_fn(method), object, std::placeholders::_1, std::placeholders::_2))
{}

template <typename TResult, typename TProgress> void AsyncOperationWithProgressCompletedHandler<TResult, TProgress>::operator()(const IAsyncOperationWithProgress<TResult, TProgress> & sender, const AsyncStatus args) const
{
    check_hresult((*this)->abi_Invoke(get(sender), args));
}

template <typename TResult, typename H>
struct impl_AsyncOperationCompletedHandler : implements<impl_AsyncOperationCompletedHandler<TResult, H>, abi<AsyncOperationCompletedHandler<TResult>>>
{
    H m_handler;
    impl_AsyncOperationCompletedHandler(H handler) : m_handler(handler) {}

    HRESULT __stdcall abi_Invoke(abi_arg_in<IAsyncOperation<TResult>> sender, AsyncStatus args) noexcept override
    {
        try
        {
            m_handler(*reinterpret_cast<const IAsyncOperation<TResult> *>(&sender), args);
            return S_OK;
        }
        catch (...) { return impl::to_hresult(); }
    }
};

template <typename TResult> template <typename H> AsyncOperationCompletedHandler<TResult>::AsyncOperationCompletedHandler(H handler) :
    AsyncOperationCompletedHandler(make<impl_AsyncOperationCompletedHandler<TResult, H>, AsyncOperationCompletedHandler<TResult>>(handler))
{}

template <typename TResult> template <typename Object, typename Method> AsyncOperationCompletedHandler<TResult>::AsyncOperationCompletedHandler(Object * object, Method method) :
    AsyncOperationCompletedHandler(std::bind(std::mem_fn(method), object, std::placeholders::_1, std::placeholders::_2))
{}

template <typename TResult> void AsyncOperationCompletedHandler<TResult>::operator()(const IAsyncOperation<TResult> & sender, const AsyncStatus args) const
{
    check_hresult((*this)->abi_Invoke(get(sender), args));
}

template <typename T, typename H>
struct impl_EventHandler : implements<impl_EventHandler<T, H>, abi<EventHandler<T>>>
{
    H m_handler;
    impl_EventHandler(H handler) : m_handler(handler) {}

    HRESULT __stdcall abi_Invoke(abi_arg_in<IInspectable> sender, abi_arg_in<T> args) noexcept override
    {
        try
        {
            m_handler(*reinterpret_cast<const IInspectable *>(&sender), *reinterpret_cast<const T *>(&args));
            return S_OK;
        }
        catch (...) { return impl::to_hresult(); }
    }
};

template <typename T> template <typename Handler> EventHandler<T>::EventHandler(Handler handler) :
    EventHandler(make<impl_EventHandler<T, Handler>, EventHandler<T>>(handler))
{}

template <typename T> template <typename Object, typename Method> EventHandler<T>::EventHandler(Object * object, Method method) :
    EventHandler(std::bind(std::mem_fn(method), object, std::placeholders::_1, std::placeholders::_2))
{}

template <typename T> void EventHandler<T>::operator()(const IInspectable & sender, const T & args) const
{
    check_hresult((*this)->abi_Invoke(get(sender), get(args)));
}

template <typename TSender, typename TArgs, typename H>
struct impl_TypedEventHandler : implements<impl_TypedEventHandler<TSender, TArgs, H>, abi<TypedEventHandler<TSender, TArgs>>>
{
    H m_handler;
    impl_TypedEventHandler(H handler) : m_handler(handler) {}

    HRESULT __stdcall abi_Invoke(abi_arg_in<TSender> sender, abi_arg_in<TArgs> args) noexcept override
    {
        try
        {
            m_handler(*reinterpret_cast<const TSender *>(&sender), *reinterpret_cast<const TArgs *>(&args));
            return S_OK;
        }
        catch (...) { return impl::to_hresult(); }
    }
};

template <typename TSender, typename TArgs> template <typename Handler> TypedEventHandler<TSender, TArgs>::TypedEventHandler(Handler handler) :
    TypedEventHandler(make<impl_TypedEventHandler<TSender, TArgs, Handler>, TypedEventHandler<TSender, TArgs>>(handler))
{}

template <typename TSender, typename TArgs> template <typename Object, typename Method> TypedEventHandler<TSender, TArgs>::TypedEventHandler(Object * object, Method method) :
    TypedEventHandler(std::bind(std::mem_fn(method), object, std::placeholders::_1, std::placeholders::_2))
{}

template <typename TSender, typename TArgs> void TypedEventHandler<TSender, TArgs>::operator()(const TSender & sender, const TArgs & args) const
{
    check_hresult((*this)->abi_Invoke(get(sender), get(args)));
}

}}

namespace Windows { namespace Foundation { namespace Collections {

enum class CollectionChange
{
    Reset,
    ItemInserted,
    ItemRemoved,
    ItemChanged,
};

}}}

namespace ABI { namespace Windows { namespace Foundation { namespace Collections {


struct __declspec(uuid("575933df-34fe-4480-af15-07691f3d5d9b")) __declspec(novtable) IVectorChangedEventArgs : IInspectable
{
    virtual HRESULT __stdcall get_CollectionChange(winrt::Windows::Foundation::Collections::CollectionChange * value) = 0;
    virtual HRESULT __stdcall get_Index(uint32_t * value) = 0;
};

}}}}

namespace Windows { namespace Foundation { namespace Collections {

struct IVectorChangedEventArgs;

template <typename D>
class impl_IVectorChangedEventArgs
{
    auto shim() const { return impl::shim<D, IVectorChangedEventArgs>(this); }

public:

    CollectionChange CollectionChange() const;
    uint32_t Index() const;
};

}}}

namespace impl {

template <> struct traits<Windows::Foundation::Collections::IVectorChangedEventArgs>
{
    using abi = ABI::Windows::Foundation::Collections::IVectorChangedEventArgs;
    template <typename T> using consume = Windows::Foundation::Collections::impl_IVectorChangedEventArgs<T>;
};

template <typename From, typename To>
using is_convertible = typename std::is_convertible<From, To>::type *;

}

namespace Windows { namespace Foundation { namespace Collections {

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

template <typename T> uint32_t impl_IVectorChangedEventArgs<T>::Index() const
{
    uint32_t index = 0;
    check_hresult(shim()->get_Index(&index));
    return index;
}

}}}

namespace ABI { namespace Windows { namespace Foundation { namespace Collections {

template <typename T> struct IIterator;
template <typename T> struct IIterable;
template <typename K, typename V> struct IKeyValuePair;
template <typename T> struct IVectorView;
template <typename T> struct IVector;
template <typename K, typename V> struct IMapView;
template <typename K, typename V> struct IMap;
template <typename K> struct IMapChangedEventArgs;
template <typename K, typename V> struct MapChangedEventHandler;
template <typename K, typename V> struct IObservableMap;
template <typename T> struct VectorChangedEventHandler;
template <typename T> struct IObservableVector;

template <typename T>
struct __declspec(novtable) impl_IIterator : IInspectable
{
    virtual HRESULT __stdcall get_Current(arg_out<T> current) = 0;
    virtual HRESULT __stdcall get_HasCurrent(bool * hasCurrent) = 0;
    virtual HRESULT __stdcall abi_MoveNext(bool * hasCurrent) = 0;
    virtual HRESULT __stdcall abi_GetMany(uint32_t capacity, arg_out<T> value, uint32_t * actual) = 0;

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
    virtual HRESULT __stdcall abi_GetAt(uint32_t index, arg_out<T> item) = 0;
    virtual HRESULT __stdcall get_Size(uint32_t * size) = 0;
    virtual HRESULT __stdcall abi_IndexOf(arg_in<T> value, uint32_t * index, bool * found) = 0;
    virtual HRESULT __stdcall abi_GetMany(uint32_t startIndex, uint32_t capacity, arg_out<T> value, uint32_t * actual) = 0;
};

template <typename T>
struct __declspec(novtable) impl_IVector : IInspectable
{
    virtual HRESULT __stdcall abi_GetAt(uint32_t index, arg_out<T> item) = 0;
    virtual HRESULT __stdcall get_Size(uint32_t * size) = 0;
    virtual HRESULT __stdcall abi_GetView(IVectorView<T> ** view) = 0;
    virtual HRESULT __stdcall abi_IndexOf(arg_in<T> value, uint32_t * index, bool * found) = 0;
    virtual HRESULT __stdcall abi_SetAt(uint32_t index, arg_in<T> item) = 0;
    virtual HRESULT __stdcall abi_InsertAt(uint32_t index, arg_in<T> item) = 0;
    virtual HRESULT __stdcall abi_RemoveAt(uint32_t index) = 0;
    virtual HRESULT __stdcall abi_Append(arg_in<T> item) = 0;
    virtual HRESULT __stdcall abi_RemoveAtEnd() = 0;
    virtual HRESULT __stdcall abi_Clear() = 0;
    virtual HRESULT __stdcall abi_GetMany(uint32_t startIndex, uint32_t capacity, arg_out<T> value, uint32_t * actual) = 0;
    virtual HRESULT __stdcall abi_ReplaceAll(uint32_t count, arg_out<T> value) = 0;

};

template <typename K, typename V>
struct __declspec(novtable) impl_IMapView : IInspectable
{
    virtual HRESULT __stdcall abi_Lookup(arg_in<K> key, arg_out<V> value) = 0;
    virtual HRESULT __stdcall get_Size(uint32_t * size) = 0;
    virtual HRESULT __stdcall abi_HasKey(arg_in<K> key, bool * found) = 0;
    virtual HRESULT __stdcall abi_Split(IMapView<K, V> ** firstPartition, IMapView<K, V> ** secondPartition) = 0;
};

template <typename K, typename V>
struct __declspec(novtable) impl_IMap : IInspectable
{
    virtual HRESULT __stdcall abi_Lookup(arg_in<K> key, arg_out<V> value) = 0;
    virtual HRESULT __stdcall get_Size(uint32_t * size) = 0;
    virtual HRESULT __stdcall abi_HasKey(arg_in<K> key, bool * found) = 0;
    virtual HRESULT __stdcall abi_GetView(IMapView<K, V> ** view) = 0;
    virtual HRESULT __stdcall abi_Insert(arg_in<K> key, arg_in<V> value, bool * replaced) = 0;
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
struct __declspec(novtable) impl_MapChangedEventHandler : IUnknown
{
    virtual HRESULT __stdcall abi_Invoke(IObservableMap<K, V> * sender, IMapChangedEventArgs<K> * args) = 0;
};

template <typename K, typename V>
struct __declspec(novtable) impl_IObservableMap : IInspectable
{
    virtual HRESULT __stdcall add_MapChanged(MapChangedEventHandler<K, V> * handler, long long * token) = 0;
    virtual HRESULT __stdcall remove_MapChanged(long long token) = 0;
};

template <typename T>
struct __declspec(novtable) impl_VectorChangedEventHandler : IUnknown
{
    virtual HRESULT __stdcall abi_Invoke(IObservableVector<T> * sender, IVectorChangedEventArgs * args) = 0;
};

template <typename T>
struct __declspec(novtable) impl_IObservableVector : IInspectable
{
    virtual HRESULT __stdcall add_VectorChanged(VectorChangedEventHandler<T> * handler, long long *  token) = 0;
    virtual HRESULT __stdcall remove_VectorChanged(long long token) = 0;
};

}}}}

namespace Windows { namespace Foundation { namespace Collections {

template <typename T> struct IIterator;
template <typename T> struct IIterable;
template <typename K, typename V> struct IKeyValuePair;
template <typename T> struct IVectorView;
template <typename T> struct IVector;
template <typename K, typename V> struct IMapView;
template <typename K, typename V> struct IMap;
template <typename K> struct IMapChangedEventArgs;
template <typename K, typename V> struct MapChangedEventHandler;
template <typename K, typename V> struct IObservableMap;
template <typename T> struct VectorChangedEventHandler;
template <typename T> struct IObservableVector;

template <typename D, typename T>
class impl_consume_IIterator
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
        check_hresult(shim()->get_HasCurrent(put(temp)));
        return temp;
    }

    bool MoveNext() const
    {
        bool temp = false;
        check_hresult(shim()->abi_MoveNext(put(temp)));
        return temp;
    }

    uint32_t GetMany(array_ref<T> values) const
    {
        uint32_t actual = 0;
        check_hresult(shim()->abi_GetMany(values.size(), get(values), &actual));
        return actual;
    }

    auto & operator++()
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
class impl_consume_IIterable
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
class impl_consume_IKeyValuePair
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

    bool operator==(const IKeyValuePair<K, V> & other) const noexcept
    {
        return Key() == other.Key() && Value() == other.Value();
    }

    bool operator!=(const IKeyValuePair<K, V> & other) const noexcept
    {
        return !(*this == other);
    }
};

template <typename D, typename T>
class impl_consume_IVectorView
{
    auto shim() const { return impl::shim<D, IVectorView<T>>(this); }

public:

    T GetAt(const uint32_t index) const
    {
        T result = impl::argument<T>::empty();
        check_hresult(shim()->abi_GetAt(index, put(result)));
        return result;
    }

    uint32_t Size() const
    {
        uint32_t size = 0;
        check_hresult(shim()->get_Size(&size));
        return size;
    }

    bool IndexOf(const T & value, uint32_t & index) const
    {
        bool found = false;
        check_hresult(shim()->abi_IndexOf(get(value), &index, put(found)));
        return found;
    }
};

template <typename D, typename T>
class impl_consume_IVector
{
    auto shim() const { return impl::shim<D, IVector<T>>(this); }

public:

    T GetAt(const uint32_t index) const
    {
        T result = impl::argument<T>::empty();
        check_hresult(shim()->abi_GetAt(index, put(result)));
        return result;
    }

    uint32_t Size() const
    {
        uint32_t size = 0;
        check_hresult(shim()->get_Size(&size));
        return size;
    }

    IVectorView<T> GetView() const
    {
        IVectorView<T> view;
        check_hresult(shim()->abi_GetView(put(view)));
        return view;
    }

    bool IndexOf(const T & value, uint32_t & index) const
    {
        bool found = false;
        check_hresult(shim()->abi_IndexOf(get(value), &index, put(found)));
        return found;
    }

    void SetAt(const uint32_t index, const T & value) const
    {
        check_hresult(shim()->abi_SetAt(index, get(value)));
    }

    void InsertAt(const uint32_t index, const T & value) const
    {
        check_hresult(shim()->abi_InsertAt(index, get(value)));
    }

    void RemoveAt(const uint32_t index) const
    {
        check_hresult(shim()->abi_RemoveAt(index));
    }

    void Append(const T & value) const
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

    uint32_t GetMany(uint32_t startIndex, array_ref<T> values) const
    {
        uint32_t actual = 0;
        check_hresult(shim()->abi_GetMany(startIndex, values.size(), get(values), &actual));
        return actual;
    }

    template <typename Array>
    void ReplaceAll(const Array & values) const
    {
        check_hresult(shim()->abi_ReplaceAll(static_cast<uint32_t>(values.size()), reinterpret_cast<abi_arg_out<T>>(const_cast<Array &>(values).data())));
    }
};

template <typename D, typename K, typename V>
class impl_consume_IMapView
{
    auto shim() const { return impl::shim<D, IMapView<K, V>>(this); }

public:

    V Lookup(const K & key) const
    {
        V result = impl::argument<V>::empty();
        check_hresult(shim()->abi_Lookup(get(key), put(result)));
        return result;
    }

    uint32_t Size() const
    {
        uint32_t size = 0;
        check_hresult(shim()->get_Size(&size));
        return size;
    }

    bool HasKey(const K & key) const
    {
        bool found = false;
        check_hresult(shim()->abi_HasKey(get(key), put(found)));
        return found;
    }

    void Split(IMapView<K, V> & firstPartition, IMapView<K, V> & secondPartition)
    {
        check_hresult(shim()->abi_Split(put(firstPartition), put(secondPartition)));
    }
};

template <typename D, typename K, typename V>
class impl_consume_IMap
{
    auto shim() const { return impl::shim<D, IMap<K, V>>(this); }

public:

    V Lookup(const K & key) const
    {
        V result = impl::argument<V>::empty();
        check_hresult(shim()->abi_Lookup(get(key), put(result)));
        return result;
    }

    uint32_t Size() const
    {
        uint32_t size = 0;
        check_hresult(shim()->get_Size(&size));
        return size;
    }

    bool HasKey(const K & key) const
    {
        bool found = false;
        check_hresult(shim()->abi_HasKey(get(key), put(found)));
        return found;
    }

    IMapView<K, V> GetView() const
    {
        IMapView<K, V> view;
        check_hresult(shim()->abi_GetView(put(view)));
        return view;
    }

    bool Insert(const K & key, const V & value) const
    {
        bool replaced = false;
        check_hresult(shim()->abi_Insert(get(key), get(value), put(replaced)));
        return replaced;
    }

    void Remove(const K & key) const
    {
        check_hresult(shim()->abi_Remove(get(key)));
    }

    void Clear() const
    {
        check_hresult(shim()->abi_Clear());
    }
};

template <typename D, typename K>
class impl_consume_IMapChangedEventArgs
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
class impl_consume_MapChangedEventHandler
{
    auto shim() const { return impl::shim<D, MapChangedEventHandler<K, V>>(this); }

public:

    void Invoke(const IObservableMap<K, V> & sender, const IMapChangedEventArgs<K> & args) const
    {
        check_hresult(shim()->abi_Invoke(get(sender), get(args)));
    }
};

template <typename D, typename K, typename V>
class impl_consume_IObservableMap
{
    auto shim() const { return impl::shim<D, IObservableMap<K, V>>(this); }

public:

    long long MapChanged(const MapChangedEventHandler<K, V> & handler) const
    {
        long long cookie = {};
        check_hresult(shim()->add_MapChanged(get(handler), &cookie));
        return cookie;
    }

    void MapChanged(const long long cookie) const
    {
        check_hresult(shim()->remove_MapChanged(cookie));
    }
};

template <typename D, typename T>
class impl_consume_VectorChangedEventHandler
{
    auto shim() const { return impl::shim<D, VectorChangedEventHandler<T>>(this); }

public:

    void Invoke(const IObservableVector<T> & sender, const IVectorChangedEventArgs & args) const
    {
        check_hresult(shim()->abi_Invoke(get(sender), get(args)));
    }
};

template <typename D, typename T>
class impl_consume_IObservableVector
{
    auto shim() const { return impl::shim<D, IObservableVector<T>>(this); }

public:

    long long VectorChanged(const VectorChangedEventHandler<T> & handler) const
    {
        long long cookie = {};
        check_hresult(shim()->add_VectorChanged(get(handler), &cookie));
        return cookie;
    }

    void VectorChanged(const long long cookie) const
    {
        check_hresult(shim()->remove_VectorChanged(cookie));
    }
};

}}}

namespace impl {

template <typename T> struct traits<Windows::Foundation::Collections::IIterator<T>>
{
    using abi = ABI::Windows::Foundation::Collections::IIterator<abi<T>>;
    template <typename D> using consume = Windows::Foundation::Collections::impl_consume_IIterator<D, T>;
};

template <typename T> struct traits<Windows::Foundation::Collections::IIterable<T>>
{
    using abi = ABI::Windows::Foundation::Collections::IIterable<abi<T>>;
    template <typename D> using consume = Windows::Foundation::Collections::impl_consume_IIterable<D, T>;
};

template <typename K, typename V> struct traits<Windows::Foundation::Collections::IKeyValuePair<K, V>>
{
    using abi = ABI::Windows::Foundation::Collections::IKeyValuePair<abi<K>, abi<V>>;
    template <typename D> using consume = Windows::Foundation::Collections::impl_consume_IKeyValuePair<D, K, V>;
};

template <typename T> struct traits<Windows::Foundation::Collections::IVectorView<T>>
{
    using abi = ABI::Windows::Foundation::Collections::IVectorView<abi<T>>;
    template <typename D> using consume = Windows::Foundation::Collections::impl_consume_IVectorView<D, T>;
};

template <typename T> struct traits<Windows::Foundation::Collections::IVector<T>>
{
    using abi = ABI::Windows::Foundation::Collections::IVector<abi<T>>;
    template <typename D> using consume = Windows::Foundation::Collections::impl_consume_IVector<D, T>;
};

template <typename K, typename V> struct traits<Windows::Foundation::Collections::IMapView<K, V>>
{
    using abi = ABI::Windows::Foundation::Collections::IMapView<abi<K>, abi<V>>;
    template <typename D> using consume = Windows::Foundation::Collections::impl_consume_IMapView<D, K, V>;
};

template <typename K, typename V> struct traits<Windows::Foundation::Collections::IMap<K, V>>
{
    using abi = ABI::Windows::Foundation::Collections::IMap<abi<K>, abi<V>>;
    template <typename D> using consume = Windows::Foundation::Collections::impl_consume_IMap<D, K, V>;
};

template <typename K> struct traits<Windows::Foundation::Collections::IMapChangedEventArgs<K>>
{
    using abi = ABI::Windows::Foundation::Collections::IMapChangedEventArgs<abi<K>>;
    template <typename D> using consume = Windows::Foundation::Collections::impl_consume_IMapChangedEventArgs<D, K>;
};

template <typename K, typename V> struct traits<Windows::Foundation::Collections::MapChangedEventHandler<K, V>>
{
    using abi = ABI::Windows::Foundation::Collections::MapChangedEventHandler<abi<K>, abi<V>>;
    template <typename D> using consume = Windows::Foundation::Collections::impl_consume_MapChangedEventHandler<D, K, V>;
};

template <typename K, typename V> struct traits<Windows::Foundation::Collections::IObservableMap<K, V>>
{
    using abi = ABI::Windows::Foundation::Collections::IObservableMap<abi<K>, abi<V>>;
    template <typename D> using consume = Windows::Foundation::Collections::impl_consume_IObservableMap<D, K, V>;
};

template <typename T> struct traits<Windows::Foundation::Collections::VectorChangedEventHandler<T>>
{
    using abi = ABI::Windows::Foundation::Collections::VectorChangedEventHandler<abi<T>>;
    template <typename D> using consume = Windows::Foundation::Collections::impl_consume_VectorChangedEventHandler<D, T>;
};

template <typename T> struct traits<Windows::Foundation::Collections::IObservableVector<T>>
{
    using abi = ABI::Windows::Foundation::Collections::IObservableVector<abi<T>>;
    template <typename D> using consume = Windows::Foundation::Collections::impl_consume_IObservableVector<D, T>;
};

template <typename T>
struct fast_iterator : std::iterator<std::input_iterator_tag, T>
{
    fast_iterator(const T & collection, const uint32_t index) noexcept :
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

    bool operator==(const fast_iterator & other) const noexcept
    {
        WINRT_ASSERT(m_collection == other.m_collection);
        return m_index == other.m_index;
    }

    bool operator!=(const fast_iterator & other) const noexcept
    {
        return !(*this == other);
    }

private:

    const T * m_collection = nullptr;
    uint32_t m_index = 0;
};

}

namespace Windows { namespace Foundation { namespace Collections {

template <typename T>
struct WINRT_EBO IIterator :
    IInspectable,
    consume<IIterator<T>>
{
    IIterator(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IIterator>(m_ptr); }
};

template <typename T>
struct WINRT_EBO IIterable :
    IInspectable,
    consume<IIterable<T>>
{
    IIterable(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IIterable>(m_ptr); }
};

template <typename K, typename V>
struct WINRT_EBO IIterable<IKeyValuePair<K, V>> :
    IInspectable,
    consume<IIterable<IKeyValuePair<K, V>>>
{
    IIterable(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IIterable>(m_ptr); }
};

template <typename K, typename V>
struct WINRT_EBO IKeyValuePair :
    IInspectable,
    consume<IKeyValuePair<K, V>>
{
    IKeyValuePair(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IKeyValuePair>(m_ptr); }
};

template <typename T>
struct WINRT_EBO IVectorView :
    IInspectable,
    consume<IVectorView<T>>,
    requires<IVectorView<T>, IIterable<T>>
{
    IVectorView(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IVectorView>(m_ptr); }
};

template <typename T>
struct WINRT_EBO IVector :
    IInspectable,
    consume<IVector<T>>,
    requires<IVector<T>, IIterable<T>>
{
    IVector(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IVector>(m_ptr); }
};

template <typename K, typename V>
struct WINRT_EBO IMapView :
    IInspectable,
    consume<IMapView<K, V>>,
    requires<IMapView<K, V>, IIterable<IKeyValuePair<K, V>>>
{
    IMapView(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IMapView>(m_ptr); }
};

template <typename K, typename V>
struct WINRT_EBO IMap :
    IInspectable,
    consume<IMap<K, V>>,
    requires<IMap<K, V>, IIterable<IKeyValuePair<K, V>>>
{
    IMap(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IMap>(m_ptr); }
};

template <typename K>
struct WINRT_EBO IMapChangedEventArgs :
    IInspectable,
    consume<IMapChangedEventArgs<K>>
{
    IMapChangedEventArgs(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IMapChangedEventArgs>(m_ptr); }
};

template <typename K, typename V>
struct WINRT_EBO MapChangedEventHandler :
    IUnknown,
    consume<MapChangedEventHandler<K, V>>
{
    MapChangedEventHandler(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<MapChangedEventHandler>(m_ptr); }
    template <typename H> MapChangedEventHandler(H handler);
};

template <typename K, typename V>
struct WINRT_EBO IObservableMap :
    IInspectable,
    consume<IObservableMap<K, V>>,
    requires<IObservableMap<K, V>, IMap<K, V>, IIterable<IKeyValuePair<K, V>>>
{
    IObservableMap(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IObservableMap>(m_ptr); }
};

template <typename T>
struct WINRT_EBO VectorChangedEventHandler :
    IUnknown,
    consume<VectorChangedEventHandler<T>>
{
    VectorChangedEventHandler(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<VectorChangedEventHandler>(m_ptr); }
    template <typename H> VectorChangedEventHandler(H handler);
};

template <typename T>
struct WINRT_EBO IObservableVector :
    IInspectable,
    consume<IObservableVector<T>>,
    requires<IObservableVector<T>, IVector<T>, IIterable<T>>
{
    IObservableVector(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IObservableVector>(m_ptr); }
};

template <typename T, std::enable_if_t<!impl::has_GetAt<T>::value> * = nullptr>
auto begin(const T & collection) -> decltype(collection.First())
{
    auto result = collection.First();

    if (!result.HasCurrent())
    {
        return {};
    }

    return result;
}

template <typename T, std::enable_if_t<!impl::has_GetAt<T>::value> * = nullptr>
auto end(const T & collection) -> decltype(collection.First())
{
    collection;
    return {};
}

template <typename T, std::enable_if_t<impl::has_GetAt<T>::value> * = nullptr>
impl::fast_iterator<T> begin(const T & collection) noexcept
{
    return impl::fast_iterator<T>(collection, 0);
}

template <typename T, std::enable_if_t<impl::has_GetAt<T>::value> * = nullptr>
impl::fast_iterator<T> end(const T & collection)
{
    return impl::fast_iterator<T>(collection, collection.Size());
}

}}}

namespace ABI { namespace Windows { namespace Foundation {

struct AsyncActionCompletedHandler;
struct IAsyncAction;

struct __declspec(uuid("a4ed5c81-76c9-40bd-8be6-b1d90fb20ae7")) __declspec(novtable) AsyncActionCompletedHandler : IUnknown
{
    virtual HRESULT __stdcall abi_Invoke(IAsyncAction * asyncInfo, winrt::Windows::AsyncStatus asyncStatus) = 0;
};

struct __declspec(uuid("5a648006-843a-4da9-865b-9d26e5dfad7b")) __declspec(novtable) IAsyncAction : IInspectable
{
    virtual HRESULT __stdcall put_Completed(AsyncActionCompletedHandler * handler) = 0;
    virtual HRESULT __stdcall get_Completed(AsyncActionCompletedHandler ** handler) = 0;
    virtual HRESULT __stdcall abi_GetResults() = 0;
};

}}}

namespace Windows { namespace Foundation {

struct AsyncActionCompletedHandler;
struct IAsyncAction;

template <typename T>
class WINRT_EBO impl_consume_IAsyncAction
{
    auto shim() const { return impl::shim<T, IAsyncAction>(this); }

public:

    void Completed(const AsyncActionCompletedHandler & handler) const;
    AsyncActionCompletedHandler Completed() const;
    void GetResults() const;
};

template <typename T> struct impl_produce_IAsyncAction;

}}

namespace impl {

template <> struct traits<Windows::Foundation::AsyncActionCompletedHandler>
{
    using abi = ABI::Windows::Foundation::AsyncActionCompletedHandler;
};

template <> struct traits<Windows::Foundation::IAsyncAction>
{
    using abi = ABI::Windows::Foundation::IAsyncAction;
    template <typename T> using consume = Windows::Foundation::impl_consume_IAsyncAction<T>;
    template <typename T> using produce = Windows::Foundation::impl_produce_IAsyncAction<T>;
};

}

namespace Windows { namespace Foundation {

struct AsyncActionCompletedHandler : IUnknown
{
    AsyncActionCompletedHandler(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<AsyncActionCompletedHandler>(m_ptr); }
    template <typename H> AsyncActionCompletedHandler(H handler);
    template <typename O, typename M> AsyncActionCompletedHandler(O * object, M method);
    void operator()(const IAsyncAction & asyncInfo, AsyncStatus asyncStatus) const;
};

struct IAsyncAction :
    Windows::IInspectable,
    consume<IAsyncAction>,
    requires<IAsyncAction, IAsyncInfo>
{
    IAsyncAction(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IAsyncAction>(m_ptr); }
};

template <typename T>
struct impl_produce_IAsyncAction : abi<IAsyncAction>
{
    using IAsyncAction = winrt::Windows::Foundation::IAsyncAction;

    operator IAsyncAction() const noexcept
    {
        return impl::winrt_cast<IAsyncAction>(this);
    }

    void Completed(const AsyncActionCompletedHandler & handler)
    {
        throw hresult_not_implemented();
    }

    AsyncActionCompletedHandler Completed()
    {
        throw hresult_not_implemented();
    }

    void GetResults()
    {
        throw hresult_not_implemented();
    }

    HRESULT __stdcall put_Completed(abi_arg_in<AsyncActionCompletedHandler> handler) noexcept override
    {
        try
        {
            static_cast<T *>(this)->Completed(*reinterpret_cast<const AsyncActionCompletedHandler *>(&handler));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Completed(abi_arg_out<AsyncActionCompletedHandler> handler) noexcept override
    {
        try
        {
            *handler = detach(static_cast<T *>(this)->Completed());
            return S_OK;
        }
        catch (...)
        {
            *handler = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetResults() noexcept override
    {
        try
        {
            static_cast<T *>(this)->GetResults();
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename T> struct impl_AsyncActionCompletedHandler : implements<impl_AsyncActionCompletedHandler<T>, abi<AsyncActionCompletedHandler>>
{
    T m_handler;
    impl_AsyncActionCompletedHandler(T handler) : m_handler(handler) {}

    HRESULT __stdcall abi_Invoke(abi_arg_in<IAsyncAction> asyncInfo, AsyncStatus asyncStatus) noexcept override
    {
        try
        {
            m_handler(*reinterpret_cast<const IAsyncAction *>(&asyncInfo), asyncStatus);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename H> AsyncActionCompletedHandler::AsyncActionCompletedHandler(H handler) :
    AsyncActionCompletedHandler(make<impl_AsyncActionCompletedHandler<H>, AsyncActionCompletedHandler>(handler))
{}

template <typename O, typename M> AsyncActionCompletedHandler::AsyncActionCompletedHandler(O * object, M method) :
    AsyncActionCompletedHandler(std::bind(std::mem_fn(method), object, std::placeholders::_1, std::placeholders::_2))
{}

inline void AsyncActionCompletedHandler::operator()(const IAsyncAction & asyncInfo, const AsyncStatus asyncStatus) const
{
    check_hresult((*this)->abi_Invoke(get(asyncInfo), asyncStatus));
}

template <typename T> void impl_consume_IAsyncAction<T>::Completed(const AsyncActionCompletedHandler & handler) const
{
    check_hresult(shim()->put_Completed(get(handler)));
}

template <typename T> AsyncActionCompletedHandler impl_consume_IAsyncAction<T>::Completed() const
{
    AsyncActionCompletedHandler handler{};
    check_hresult(shim()->get_Completed(put(handler)));
    return handler;
}

template <typename T> void impl_consume_IAsyncAction<T>::GetResults() const
{
    check_hresult(shim()->abi_GetResults());
}

}}
 
namespace Windows { namespace Foundation {

struct Point
{
    float X;
    float Y;

    Point() noexcept = default;

    Point(float X, float Y) noexcept
        : X(X), Y(Y)
    {}

    Point(const Numerics::float2 & value) noexcept
        : X(value.x), Y(value.y)
    {}

    operator Numerics::float2() const noexcept
    {
        return { X, Y };
    }
};

struct Size
{
    float Width;
    float Height;

    Size() noexcept = default;

    Size(float Width, float Height) noexcept
        : Width(Width), Height(Height)
    {}

    Size(const Numerics::float2 & value) noexcept
        : Width(value.x), Height(value.y)
    {}

    operator Numerics::float2() const noexcept
    {
        return { Width, Height };
    }
};

using TimeSpan = std::chrono::duration<int64_t, std::ratio<1, 10'000'000>>;

}}

namespace ABI { namespace Windows { namespace Foundation {

using Point = winrt::Windows::Foundation::Point;
using Size = winrt::Windows::Foundation::Size;
using TimeSpan = winrt::Windows::Foundation::TimeSpan;

}}}

namespace ABI { namespace Windows { namespace Foundation { namespace Numerics {

using float2 = winrt::Windows::Foundation::Numerics::float2;
using float3 = winrt::Windows::Foundation::Numerics::float3;
using float4 = winrt::Windows::Foundation::Numerics::float4;
using float3x2 = winrt::Windows::Foundation::Numerics::float3x2;
using float4x4 = winrt::Windows::Foundation::Numerics::float4x4;
using plane = winrt::Windows::Foundation::Numerics::plane;
using quaternion = winrt::Windows::Foundation::Numerics::quaternion;

}}}}

namespace Windows { namespace Foundation {

template <typename T, typename F>
void impl_suspend(const T & object, F resume)
{
    com_ptr<IContextCallback> context;
    check_hresult(CoGetObjectContext(__uuidof(context), reinterpret_cast<void **>(put(context))));

    object.Completed([resume, context](const auto &, AsyncStatus)
    {
        ComCallData data = {};
        data.pUserDefined = resume.to_address();

        check_hresult(context->ContextCallback([](ComCallData * data)
        {
            F::from_address(data->pUserDefined)();
            return S_OK;
        },
        &data,
        IID_ICallbackWithNoReentrancyToApplicationSTA,
        5,
        nullptr));
    });
}

template <typename TProgress>
bool await_ready(const IAsyncActionWithProgress<TProgress> & object)
{
    return object.Status() == AsyncStatus::Completed;
}

template <typename TProgress, typename F>
void await_suspend(const IAsyncActionWithProgress<TProgress> & object, F resume)
{
    impl_suspend(object, resume);
}

template <typename TProgress>
void await_resume(const IAsyncActionWithProgress<TProgress> & object)
{
    object.GetResults();
}

template <typename TResult, typename TProgress>
bool await_ready(const IAsyncOperationWithProgress<TResult, TProgress> & object)
{
    return object.Status() == AsyncStatus::Completed;
}

template <typename TResult, typename TProgress, typename F>
void await_suspend(const IAsyncOperationWithProgress<TResult, TProgress> & object, F resume)
{
    impl_suspend(object, resume);
}

template <typename TResult, typename TProgress>
TResult await_resume(const IAsyncOperationWithProgress<TResult, TProgress> & object)
{
    return object.GetResults();
}

template <typename TResult>
bool await_ready(const IAsyncOperation<TResult> & object)
{
    return object.Status() == AsyncStatus::Completed;
}

template <typename TResult, typename F>
void await_suspend(const IAsyncOperation<TResult> & object, F resume)
{
    impl_suspend(object, resume);
}

template <typename TResult>
TResult await_resume(const IAsyncOperation<TResult> & object)
{
    return object.GetResults();
}

inline bool await_ready(const IAsyncAction & object)
{
    return object.Status() == AsyncStatus::Completed;
}

template <typename F>
void await_suspend(const IAsyncAction & object, F resume)
{
    impl_suspend(object, resume);
}

inline void await_resume(const IAsyncAction & object)
{
    object.GetResults();
}

}}

}

namespace std {

template <> struct hash<winrt::hstring>
{
    size_t operator()(const winrt::hstring & value) const noexcept
    {
#ifdef WINRT_64
        const size_t fnv_offset_basis = 14695981039346656037ULL;
        const size_t fnv_prime = 1099511628211ULL;
#else
        const size_t fnv_offset_basis = 2166136261U;
        const size_t fnv_prime = 16777619U;
#endif

        uint32_t length = 0;

        const uint8_t * const buffer = reinterpret_cast<const uint8_t *>(WindowsGetStringRawBuffer(get(value),
                                                                                                   &length));

        length *= sizeof(wchar_t);
        size_t result = fnv_offset_basis;

        for (size_t next = 0; next < length; ++next)
        {
            result ^= buffer[next];
            result *= fnv_prime;
        }

        return result;
    }
};

}
