
#ifdef _DEBUG

#include <assert.h>

#define WINRT_DEBUG
#define WINRT_ASSERT assert
#define WINRT_VERIFY WINRT_ASSERT
#define WINRT_VERIFY_(result, expression) WINRT_ASSERT(result == expression)

template <typename ... Args>
void WINRT_TRACE(const char * const message, Args ... args) noexcept
{
    char buffer[1024] {};
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
