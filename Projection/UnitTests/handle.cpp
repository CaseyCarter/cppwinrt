#include "pch.h"
#include "catch.hpp"

using namespace winrt;

//
// An example of a full traits class with a non-nullptr invalid value.
//

struct test_file_traits
{
    using type = HANDLE;

    static HANDLE invalid() noexcept
    {
        return INVALID_HANDLE_VALUE;
    }

    static void close(HANDLE value) noexcept
    {
        REQUIRE(0 != CloseHandle(value));
    }
};

TEST_CASE("handle, file")
{
    wchar_t path[1024] {};
    REQUIRE(0 != GetModuleFileName(nullptr, path, _countof(path)));

    impl:: handle<test_file_traits> empty;
    REQUIRE(!empty);
    static_assert(sizeof(empty) == sizeof(HANDLE), "fail");

    impl::handle<test_file_traits> good = CreateFile(path, GENERIC_READ, FILE_SHARE_READ, nullptr, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, nullptr);
    REQUIRE(good);

    impl::handle<test_file_traits> bad = CreateFile(L"BAD", GENERIC_READ, FILE_SHARE_READ, nullptr, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, nullptr);
    REQUIRE(!bad);
}

//
// An example of a full traits class with a nullptr invalid value.
//

struct test_event_traits
{
    using type = HANDLE;

    constexpr static HANDLE invalid() noexcept
    {
        return nullptr;
    }

    static void close(HANDLE value) noexcept
    {
        REQUIRE(0 != CloseHandle(value));
    }
};

TEST_CASE("handle, event")
{
    impl::handle<test_event_traits> empty;
    REQUIRE(!empty);

    impl::handle<test_event_traits> good = CreateEvent(nullptr, true, true, nullptr);
    REQUIRE(good);

    impl::handle<test_event_traits> bad = CreateEvent(nullptr, true, true, L"BAD\\");
    REQUIRE(!bad);
}

TEST_CASE("handle, move")
{
    impl::handle<test_event_traits> a = CreateEvent(nullptr, true, true, nullptr);
    REQUIRE(a);

    impl::handle<test_event_traits> b = std::move(a); // move construct
    REQUIRE(!a);
    REQUIRE(b);

    a = std::move(b); // move assign
    REQUIRE(a);
    REQUIRE(!b);
}

TEST_CASE("handle, close")
{
    impl::handle<test_event_traits> a = CreateEvent(nullptr, true, true, nullptr);
    REQUIRE(a);

    a.close();
    REQUIRE(!a);
}

TEST_CASE("handle, get")
{
    HANDLE h = CreateEvent(nullptr, true, true, nullptr);

    impl::handle<test_event_traits> a = h;

    REQUIRE(h == get_abi(a));
}

static void test_put(HANDLE * value)
{
    REQUIRE(value != nullptr);
    REQUIRE(*value == nullptr);

    *value = CreateEvent(nullptr, true, true, nullptr);;
}

TEST_CASE("handle, put")
{
    impl::handle<test_event_traits> a;
    REQUIRE(!a);

    test_put(put_abi(a));

    REQUIRE(a);
}

TEST_CASE("handle, detach")
{
    HANDLE h = CreateEvent(nullptr, true, true, nullptr);

    impl::handle<test_event_traits> a = h;

    REQUIRE(h == get_abi(a));

    HANDLE detached = detach_abi(a);

    REQUIRE(!a);
    REQUIRE(h == detached);

    attach_abi(a, detached);
    REQUIRE(a);
    REQUIRE(h == get_abi(a));
}

TEST_CASE("handle, swap")
{
    impl::handle<test_event_traits> a = CreateEvent(nullptr, true, true, nullptr);
    impl::handle<test_event_traits> b = CreateEvent(nullptr, true, true, nullptr);

    REQUIRE(a);
    REQUIRE(b);
    REQUIRE(a != b);

    HANDLE ga = get_abi(a);
    HANDLE gb = get_abi(b);

    swap(a, b);

    REQUIRE(a);
    REQUIRE(b);
    REQUIRE(a != b);

    REQUIRE(gb == get_abi(a));
    REQUIRE(ga == get_abi(b));
}

TEST_CASE("handle, compare")
{
    impl::handle<test_event_traits> a = CreateEvent(nullptr, true, true, nullptr);
    impl::handle<test_event_traits> b = CreateEvent(nullptr, true, true, nullptr);

    if (a > b)
    {
        swap(a, b);
    }

    REQUIRE(!(a == b));
    REQUIRE(a != b);

    REQUIRE(a < b);
    REQUIRE(!(b < a));

    REQUIRE(b > a);
    REQUIRE(!(a > b));

    REQUIRE(a <= b);
    REQUIRE(!(b <= a));

    REQUIRE(b >= a);
    REQUIRE(!(a >= b));
}
