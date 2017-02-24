
#ifdef _DEBUG

#include <assert.h>

#define WINRT_DEBUG
#define WINRT_ASSERT assert
#define WINRT_VERIFY WINRT_ASSERT
#define WINRT_VERIFY_(result, expression) WINRT_ASSERT(result == expression)

template <typename ... Args>
void WINRT_TRACE(const char * const message, Args ... args) noexcept
{
    char buffer[1024]{};
    snprintf(buffer, sizeof(buffer), message, args ...);
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

#if defined(_MSC_VER) && _ITERATOR_DEBUG_LEVEL != 0
#define WINRT_CHECKED_ITERATORS
#endif

#ifndef FORMAT_MESSAGE_ALLOCATE_BUFFER
#define FORMAT_MESSAGE_ALLOCATE_BUFFER 0x00000100
#endif

#ifndef __IAgileReference_INTERFACE_DEFINED__
#define WINRT_NO_AGILE_REFERENCE
#endif

#if NTDDI_VERSION > NTDDI_WINBLUE

#define WINRT_NUMERICS
#define _WINDOWS_NUMERICS_NAMESPACE_ winrt::Windows::Foundation::Numerics
#define _WINDOWS_NUMERICS_BEGIN_NAMESPACE_ namespace winrt::Windows::Foundation::Numerics
#define _WINDOWS_NUMERICS_END_NAMESPACE_

#ifdef __clang__
#define _XM_NO_INTRINSICS_
#endif

// If this include fails it means that you're targeting an older platform version. Please use 10.0.14393.0 or later.
#include <WindowsNumerics.impl.h>

#ifdef __clang__
#undef _XM_NO_INTRINSICS_
#endif

#undef _WINDOWS_NUMERICS_NAMESPACE_
#undef _WINDOWS_NUMERICS_BEGIN_NAMESPACE_
#undef _WINDOWS_NUMERICS_END_NAMESPACE_

namespace winrt::ABI::Windows::Foundation::Numerics {

    using float2 = winrt::Windows::Foundation::Numerics::float2;
    using float3 = winrt::Windows::Foundation::Numerics::float3;
    using float4 = winrt::Windows::Foundation::Numerics::float4;
    using float3x2 = winrt::Windows::Foundation::Numerics::float3x2;
    using float4x4 = winrt::Windows::Foundation::Numerics::float4x4;
    using plane = winrt::Windows::Foundation::Numerics::plane;
    using quaternion = winrt::Windows::Foundation::Numerics::quaternion;

}

#endif

#define WINRT_SHIM(Type) (*(abi<Type> **)&static_cast<const Type &>(static_cast<const D &>(*this)))
