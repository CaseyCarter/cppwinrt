// Modern v1.27 - http://moderncpp.com
// Copyright (c) 2015 Kenny Kerr

#pragma once

#ifdef _DEBUG

#include <crtdbg.h>

#define MODERN_ASSERT _ASSERTE
#define MODERN_VERIFY MODERN_ASSERT
#define MODERN_VERIFY_(result, expression) MODERN_ASSERT(result == expression)

template <typename ... Args>
void MODERN_TRACE(char const * const message, Args ... args) noexcept
{
	char buffer[1024] = {};
	sprintf_s(buffer, message, args ...);
	OutputDebugStringA(buffer);
}

#else

#define MODERN_ASSERT __noop
#define MODERN_VERIFY(expression) (expression)
#define MODERN_VERIFY_(result, expression) (expression)
#define MODERN_TRACE __noop

#endif
