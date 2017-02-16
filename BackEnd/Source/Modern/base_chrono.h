
namespace impl
{
    using filetime_period = std::ratio_multiply<std::ratio<100>, std::nano>;
}

struct clock;

namespace Windows::Foundation
{
    using TimeSpan = std::chrono::duration<int64_t, impl::filetime_period>;
    using DateTime = std::chrono::time_point<clock, TimeSpan>;
}

namespace ABI::Windows::Foundation
{
    using TimeSpan = winrt::Windows::Foundation::TimeSpan;
    using DateTime = winrt::Windows::Foundation::DateTime;
}

struct clock
{
    using rep = int64_t;
    using period = impl::filetime_period;
    using duration = Windows::Foundation::TimeSpan;
    using time_point = Windows::Foundation::DateTime;

    static constexpr bool is_steady = false;

    static time_point now() noexcept
    {
        FILETIME ft;
        ::GetSystemTimePreciseAsFileTime(&ft);
        return from_FILETIME(ft);
    }

    static time_t to_time_t(const time_point& time) noexcept
    {
        return std::chrono::duration_cast<time_t_duration>(time - time_t_epoch).count();
    }

    static time_point from_time_t(time_t time) noexcept
    {
        return time_t_epoch + time_t_duration{ time };
    }

    // FILETIME is identical to WinRT's DateTime, save for the fact that it's unsigned.
    // Detect mismatch, but this only matters for dates before 27000 BC or after 29000 AD.
    static FILETIME to_FILETIME(const time_point& time) noexcept
    {
        ULARGE_INTEGER ul;
        ul.QuadPart = time.time_since_epoch().count();
        WINRT_ASSERT(static_cast<int32_t>(ul.HighPart) >= 0);
        return FILETIME{ ul.LowPart, ul.HighPart };
    }

    static time_point from_FILETIME(const FILETIME& time) noexcept
    {
        ULARGE_INTEGER ul{ { time.dwLowDateTime, time.dwHighDateTime } };
        WINRT_ASSERT(static_cast<int32_t>(ul.HighPart) >= 0);
        return time_point{ duration{ ul.QuadPart } };
    }

private:
    // Define 00:00:00, Jan 1 1970 UTC in FILETIME units
    static constexpr time_point time_t_epoch{ duration{ 0x019DB1DED53E8000 } };
    using time_t_duration = std::chrono::duration<time_t>;
};
