#include "pch.h"
#include "catch.hpp"
#include "winrt/Windows.Globalization.h"
#include <ctime>

using namespace winrt;
using namespace Windows::Foundation;
using namespace Windows::Globalization;
using namespace std::chrono;

namespace
{
    bool operator==(const FILETIME& lhs, const FILETIME& rhs) noexcept
    {
        return lhs.dwHighDateTime == rhs.dwHighDateTime &&
            lhs.dwLowDateTime == rhs.dwLowDateTime;
    }
}

TEST_CASE("clock, now")
{
    Calendar calendar;
    calendar.SetToNow();
    auto time = clock::now();
    auto diff = calendar.GetDateTime() - time;
    REQUIRE(abs(diff) < milliseconds{ 1 });
}

TEST_CASE("clock, units")
{
    auto time = clock::now();
    Calendar calendar;
    calendar.SetDateTime(time);

    // Add 5 minutes to both to verify that units conversion is working properly
    calendar.AddMinutes(5);
    REQUIRE(calendar.GetDateTime() == (time + 5min));
}

TEST_CASE("clock, time_t")
{
    // Round trip from DateTime to time_t and back.
    // confirm that nothing happens other than truncating the fractional seconds
    const DateTime now_dt = clock::now();
    REQUIRE(clock::from_time_t(clock::to_time_t(now_dt)) == time_point_cast<seconds>(now_dt));

    // Same thing in reverse
    const time_t now_tt = time(nullptr);
    REQUIRE(clock::to_time_t(clock::from_time_t(now_tt)) == now_tt);

    // Conversions are verified to be consistent. Now, verify that we're correctly converting epochs
    const auto diff = abs(clock::now() - clock::from_time_t(time(nullptr)));
    REQUIRE(diff < seconds{ 1 });
}

TEST_CASE("clock, FILETIME")
{
    // Round trip conversions
    const DateTime now_dt = clock::now();
    REQUIRE(clock::from_FILETIME(clock::to_FILETIME(now_dt)) == now_dt);

    FILETIME now_ft;
    ::GetSystemTimePreciseAsFileTime(&now_ft);
    REQUIRE(clock::to_FILETIME(clock::from_FILETIME(now_ft)) == now_ft);

    // Verify epoch
    ::GetSystemTimePreciseAsFileTime(&now_ft);
    const auto diff = abs(clock::now() - clock::from_FILETIME(now_ft));
    REQUIRE(diff < milliseconds{ 1 });
}