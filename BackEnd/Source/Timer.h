#pragma once

#include "debug.h"

namespace Modern::Timer {

inline long long Now() noexcept
{
    LARGE_INTEGER count = {};
    MODERN_VERIFY(QueryPerformanceCounter(&count));
    return count.QuadPart;
}

inline float Elapsed(long long const begin) noexcept
{
    long long const end = Now();

    LARGE_INTEGER frequency = {};
    MODERN_VERIFY(QueryPerformanceFrequency(&frequency));

    return static_cast<float>(end - begin) / frequency.QuadPart;
}

}
