
#pragma once

#ifdef _DEBUG

#include <crtdbg.h>

namespace Modern { namespace Internal {

template <typename ... Args>
void DebugTrace(wchar_t const * const message, Args ... args) noexcept
{
	wchar_t buffer[512] = {};
	swprintf_s(buffer, message, args ...);
	OutputDebugString(buffer);
}

}}

#define MODERN_ASSERT _ASSERTE
#define MODERN_VERIFY MODERN_ASSERT
#define MODERN_VERIFY_(result, expression) MODERN_ASSERT(result == expression)
#define MODERN_TRACE Modern::Internal::DebugTrace

#else

#define MODERN_ASSERT __noop
#define MODERN_VERIFY(expression) (expression)
#define MODERN_VERIFY_(result, expression) (expression)
#define MODERN_TRACE __noop

#endif
