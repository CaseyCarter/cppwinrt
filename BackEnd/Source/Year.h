#pragma once

namespace Modern {

inline unsigned Year() noexcept
{
    time_t t = time(nullptr);
    tm tm = {};
    localtime_s(&tm, &t);

    return 1900 + tm.tm_year;
}

}