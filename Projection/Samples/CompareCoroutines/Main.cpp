#include "pch.h"

using namespace std::chrono;
using namespace winrt;
using namespace Windows::Foundation;

static constexpr uint32_t test_passes = 1'000'000;

template <typename coro_type>
struct test_coro
{
    static coro_type three()
    {
        co_await resume_background();
        co_await 0s;
    }

    static coro_type two()
    {
        co_await three();
    }

    static coro_type one()
    {
        co_await two();
    }

    template <typename InputIt>
    static coro_type wait_all(InputIt first, InputIt last)
    {
        for (; first != last; ++first)
        {
            co_await *first;
        }
    }

    static void run_wait_get()
    {
        std::vector<coro_type> container(test_passes);

        for (coro_type & coro : container)
        {
            coro = one();
        }

        wait_all(container.begin(), container.end()).get();
    }

    static coro_type run_all()
    {
        for (uint32_t i = 0; i != test_passes; ++i)
        {
            co_await one();
        }
    }

    static void get_once()
    {
        run_all().get();
    }

    static void get_all()
    {
        for (uint32_t i = 0; i != test_passes; ++i)
        {
            one().get();
        }
    }
};

template <typename F>
void measure(char const * name, F function)
{
    using namespace std::chrono;
    auto start = high_resolution_clock::now();

    function();

    auto finish = high_resolution_clock::now();
    double elapsed = duration_cast<duration<double>>(finish - start).count();
    printf("%.2fs -- %s\n", elapsed, name);
}

int main()
{
    initialize();

    try
    {
        measure("C++/WinRT",      test_coro<IAsyncAction>::get_all);
        measure("concurrency::task", test_coro<concurrency::task<void>>::get_all);
        measure("std::future",       test_coro<std::future<void>>::get_all);
    }
    catch (hresult_error const & e)
    {
        printf("hresult_error (0x%8X) %ls\n", e.code(), e.message().c_str());
    }
}
