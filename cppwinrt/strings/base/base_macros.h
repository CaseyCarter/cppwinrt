
#ifdef _DEBUG

#define WINRT_DEBUG
#define WINRT_ASSERT _ASSERTE
#define WINRT_VERIFY WINRT_ASSERT
#define WINRT_VERIFY_(result, expression) WINRT_ASSERT(result == expression)

template <typename ... Args>
void WINRT_TRACE(char const* const message, Args ... args) noexcept
{
    char buffer[1024];
    (void)snprintf(buffer, sizeof(buffer), message, args ...);
    OutputDebugStringA(buffer);
}

#else

#define WINRT_ASSERT __noop
#define WINRT_VERIFY(expression) (void)(expression)
#define WINRT_VERIFY_(result, expression) (void)(expression)
#define WINRT_TRACE __noop

#endif

#ifndef WINRT_EXPORT
#define WINRT_EXPORT
#endif

#define WINRT_EBO __declspec(empty_bases)

#ifdef _WIN64
#define WINRT_64
#endif

#if defined(_MSC_VER) && _ITERATOR_DEBUG_LEVEL != 0
#define WINRT_CHECKED_ITERATORS
#endif

#define _WINDOWS_NUMERICS_NAMESPACE_ winrt::Windows::Foundation::Numerics
#define _WINDOWS_NUMERICS_BEGIN_NAMESPACE_ namespace winrt::Windows::Foundation::Numerics
#define _WINDOWS_NUMERICS_END_NAMESPACE_

#ifdef __clang__
#define _XM_NO_INTRINSICS_
#endif

#if !__has_include(<WindowsNumerics.impl.h>)
static_assert(false, "Please target platform version 10.0.14393.0 or later.");
#endif
#include <WindowsNumerics.impl.h>

#ifdef __clang__
#undef _XM_NO_INTRINSICS_
#endif

#undef _WINDOWS_NUMERICS_NAMESPACE_
#undef _WINDOWS_NUMERICS_BEGIN_NAMESPACE_
#undef _WINDOWS_NUMERICS_END_NAMESPACE_

#define WINRT_SHIM(Type) (*(abi_t<Type>**)&static_cast<Type const&>(static_cast<D const&>(*this)))

#undef GetCurrentTime
