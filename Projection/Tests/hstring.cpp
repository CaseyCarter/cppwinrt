#include "pch.h"
#include "catch.hpp"

using namespace winrt;

//
// hstring
//

TEST_CASE("hstring,constructor,default")
{
    {
        hstring s;
        REQUIRE(s.empty());
    }

    {
        hstring s{};
        REQUIRE(s.empty());
    }
}

TEST_CASE("hstring,constructor,copy")
{
    {
        hstring a;
        REQUIRE(a.empty());

        hstring b = a;
        REQUIRE(a.empty());
        REQUIRE(b.empty());
    }

    {
        hstring a = L"abc";
        REQUIRE(L"abc" == a);

        hstring b = a;
        REQUIRE(L"abc" == a);
        REQUIRE(L"abc" == b);
    }
}

TEST_CASE("hstring,constructor,move")
{
    {
        hstring a;
        REQUIRE(a.empty());

        hstring b = std::move(a);
        REQUIRE(a.empty());
        REQUIRE(b.empty());
    }

    {
        hstring a = L"abc";
        REQUIRE(L"abc" == a);

        hstring b = std::move(a);
        REQUIRE(a.empty());
        REQUIRE(L"abc" == b);
    }
}

TEST_CASE("hstring,assign,copy")
{
    {
        hstring a;
        hstring b;
        REQUIRE(a.empty());
        REQUIRE(b.empty());

        b = a;
        REQUIRE(a.empty());
        REQUIRE(b.empty());
    }

    {
        hstring a = L"abc";
        hstring b;
        REQUIRE(L"abc" == a);
        REQUIRE(b.empty());

        b = a;
        REQUIRE(L"abc" == a);
        REQUIRE(L"abc" == b);
    }
}

TEST_CASE("hstring,assign,move")
{
    {
        hstring a;
        hstring b;
        REQUIRE(a.empty());
        REQUIRE(b.empty());

        b = std::move(a);
        REQUIRE(a.empty());
        REQUIRE(b.empty());
    }

    {
        hstring a = L"abc";
        hstring b;
        REQUIRE(L"abc" == a);
        REQUIRE(b.empty());

        b = std::move(a);
        REQUIRE(a.empty());
        REQUIRE(L"abc" == b);
    }
}

TEST_CASE("hstring,constructor,wchar_t,size")
{
    {
        hstring s(L"", 0);
        REQUIRE(s.empty());
    }

    {
        hstring s(L"abcde", 3);
        REQUIRE(L"abc" == s);
    }
}

TEST_CASE("hstring,constructor,wchar_t")
{
    {
        hstring s = L"";
        REQUIRE(s.empty());
    }

    {
        hstring s = L"abc";
        REQUIRE(L"abc" == s);

        s = L"abcde";
        REQUIRE(L"abcde" == s);
    }
}

TEST_CASE("hstring,constructor,std::wstring")
{
    {
        hstring s = std::wstring(L"");
        REQUIRE(s.empty());
    }

    {
        hstring s = std::wstring(L"abc");
        REQUIRE(L"abc" == s);

        s = std::wstring(L"abcde");
        REQUIRE(L"abcde" == s);
    }
}

TEST_CASE("hstring,constructor,hstring_ref")
{
    {
        hstring s = hstring_ref(L"");
        REQUIRE(s.empty());
    }

    {
        hstring s = hstring_ref(L"abc");
        REQUIRE(L"abc" == s);

        s = hstring_ref(L"abcde");
        REQUIRE(L"abcde" == s);
    }
}

TEST_CASE("hstring,empty,size,clear")
{
    hstring s;

    REQUIRE(s.empty());
    REQUIRE(0 == s.size());

    s = L"abc";

    REQUIRE(!s.empty());
    REQUIRE(3 == s.size());

    s.clear();

    REQUIRE(s.empty());
    REQUIRE(0 == s.size());

    s = L"abcde";

    REQUIRE(!s.empty());
    REQUIRE(5 == s.size());

    s = L"";

    REQUIRE(s.empty());
    REQUIRE(0 == s.size());
}

TEST_CASE("hstring,operator,std::wstring")
{
    hstring hs;
    std::wstring ws = hs;
    REQUIRE(ws.empty());

    hs = L"abc";
    ws = hs;
    REQUIRE(L"abc" == ws);

    hs.clear();
    REQUIRE(L"abc" == ws);
    ws = hs;
    REQUIRE(ws.empty());
}

TEST_CASE("hstring,[N]")
{
    hstring s = L"abc";

    REQUIRE(L'a' == s[0]);
    REQUIRE(L'b' == s[1]);
    REQUIRE(L'c' == s[2]);
}

TEST_CASE("hstring,front,back")
{
    hstring s = L"abc";

    REQUIRE(L'a' == s.front());
    REQUIRE(L'c' == s.back());
}

TEST_CASE("hstring,data,c_str,begin,cbegin")
{
    hstring s = L"abc";

    REQUIRE(0 == wcscmp(L"abc", s.data()));
    REQUIRE(0 == wcscmp(L"abc", s.c_str()));
    REQUIRE(0 == wcscmp(L"abc", s.begin()));
    REQUIRE(0 == wcscmp(L"abc", s.cbegin()));
    REQUIRE(0 == wcscmp(L"abc", std::begin(s)));
    REQUIRE(0 == wcscmp(L"abc", std::cbegin(s)));
}

TEST_CASE("hstring,begin,end")
{
    hstring s = L"abc";

    std::wstring copy(s.begin(), s.end());

    REQUIRE(L"abc" == copy);
}

TEST_CASE("hstring,cbegin,cend")
{
    hstring s = L"abc";

    std::wstring copy(s.cbegin(), s.cend());

    REQUIRE(L"abc" == copy);
}

TEST_CASE("hstring,rbegin,rend")
{
    hstring s = L"abc";

    std::wstring copy(s.rbegin(), s.rend());

    REQUIRE(L"cba" == copy);
}

TEST_CASE("hstring,crbegin,crend")
{
    hstring s = L"abc";

    std::wstring copy(s.crbegin(), s.crend());

    REQUIRE(L"cba" == copy);
}

TEST_CASE("hstring,accessors,get")
{
    hstring s = L"abc";

    HSTRING h = get(s);

    REQUIRE(0 == wcscmp(L"abc", WindowsGetStringRawBuffer(h, nullptr))); // handle has correct value

    REQUIRE(s.c_str() == WindowsGetStringRawBuffer(h, nullptr)); // pointers compare equal
}

static void test_hstring_put(HSTRING * result)
{
    hstring local = L"abc";
    *result = detach(local);
}

TEST_CASE("hstring,accessors,put")
{
    hstring s;
    test_hstring_put(put(s));

    REQUIRE(L"abc" == s);
}

TEST_CASE("hstring,accessors,detach,hstring")
{
    hstring s = L"abc";
    REQUIRE(!s.empty());

    HSTRING h = detach(s);
    REQUIRE(s.empty());

    attach(s, h);
    REQUIRE(!s.empty());
    REQUIRE(L"abc" == s);

    hstring empty;
    h = detach(empty);
    REQUIRE(nullptr == h);

    attach(empty, h);
    REQUIRE(empty.empty());
}

TEST_CASE("hstring,accessors,detach,wchar_t")
{
    HSTRING h = detach(L"abc");

    hstring s;
    attach(s, h);
    REQUIRE(L"abc" == s);
}

TEST_CASE("hstring,accessors,detach,std::wstring")
{
    HSTRING h = detach(std::wstring(L"abc"));

    hstring s;
    attach(s, h);
    REQUIRE(L"abc" == s);
}

TEST_CASE("hstring,accessors,copy_from")
{
    hstring from = L"abc";
    hstring to;

    copy_from(to, get(from));
    REQUIRE(L"abc" == to);
}

TEST_CASE("hstring,accessors,copy_to")
{
    hstring from = L"abc";
    HSTRING to = nullptr;
    copy_to(from, to);

    hstring copy;
    attach(copy, to);
    REQUIRE(L"abc" == copy);
}

TEST_CASE("hstring,embedded_null")
{
    {
        hstring hs = hstring(L"hello\0world", 11);
        REQUIRE(hs.size() == 11);
        REQUIRE(embedded_null(hs));

        hs = L"hello world";
        REQUIRE(hs.size() == 11);
        REQUIRE(!embedded_null(hs));
    }

    {
        std::wstring ws(L"hello\0world", 11);
        REQUIRE(ws.size() == 11);

        hstring hs = ws;
        REQUIRE(hs.size() == 11);
        REQUIRE(embedded_null(hs));
    }
}

//
// hstring_ref
//

static void test_hstring_ref(hstring_ref s, wchar_t const * const expected)
{
    REQUIRE(s.c_str() == expected); // same pointer
    REQUIRE(wcslen(expected) == s.size());
    REQUIRE(!s.empty());

    REQUIRE(L'a' == s[0]);
    REQUIRE(L'b' == s[1]);
    REQUIRE(L'c' == s[2]);

    REQUIRE(L'a' == s.front());
    REQUIRE(L'c' == s.back());

    REQUIRE(0 == wcscmp(L"abc", s.data()));
    REQUIRE(0 == wcscmp(L"abc", s.c_str()));
    REQUIRE(0 == wcscmp(L"abc", s.begin()));
    REQUIRE(0 == wcscmp(L"abc", s.cbegin()));
    REQUIRE(0 == wcscmp(L"abc", std::begin(s)));
    REQUIRE(0 == wcscmp(L"abc", std::cbegin(s)));

    REQUIRE(L"abc" == std::wstring(s.begin(), s.end()));
    REQUIRE(L"abc" == std::wstring(s.cbegin(), s.cend()));
    REQUIRE(L"cba" == std::wstring(s.rbegin(), s.rend()));
    REQUIRE(L"cba" == std::wstring(s.crbegin(), s.crend()));

    REQUIRE(0 == wcscmp(L"abc", WindowsGetStringRawBuffer(get(s), nullptr)));

    HSTRING d = detach(s);
    hstring copy;
    attach(copy, d);
    REQUIRE(L"abc" == copy);

    REQUIRE(!s.empty()); // detaching from hstring_ref doesn't affect the hstring_ref
    REQUIRE(L"abc" == s);
}

TEST_CASE("hstring_ref,constructor,wchar_t")
{
    {
        wchar_t const * const s = L"abc";
        test_hstring_ref(s, s);
    }

    {
        wchar_t const * const s = L"";
        hstring_ref ref = s;
        REQUIRE(nullptr == get(ref));
    }
}

TEST_CASE("hstring_ref,constructor,std::wstring")
{
    {
        std::wstring s = L"abc";
        test_hstring_ref(s, s.c_str());
    }

    {
        std::wstring s;
        hstring_ref ref = s;
        REQUIRE(nullptr == get(ref));

        std::wstring copy = ref;
        REQUIRE(copy.empty());
    }
}

TEST_CASE("hstring_ref,constructor,hstring")
{
    {
        hstring s = L"abc";
        test_hstring_ref(s, s.c_str());
    }

    {
        hstring s;
        hstring_ref ref = s;
        REQUIRE(nullptr == get(ref));
    }
}

TEST_CASE("hstring_ref,constructor,HSTRING")
{
    hstring s = L"abc";
    test_hstring_ref(hstring_ref(get(s)), s.c_str());
}

TEST_CASE("hstring_ref,constructor,hstring_ref")
{
    {
        hstring_ref s = L"abc";
        test_hstring_ref(s, s.c_str());
    }

    {
        hstring_ref s = L"";
        hstring_ref ref = s;
        REQUIRE(nullptr == get(ref));
    }
}

//
// Comparisons
//

template <typename Left, typename Right>
static void test_compare()
{
    REQUIRE(Left(L"abc") == Right(L"abc"));
    REQUIRE_FALSE(Left(L"abc") == Right(L"abcd"));

    REQUIRE(Left(L"abc") != Right(L"abcd"));
    REQUIRE_FALSE(Left(L"abc") != Right(L"abc"));

    REQUIRE(Left(L"abcd") > Right(L"abc"));
    REQUIRE_FALSE(Left(L"abc") > Right(L"abcd"));

    REQUIRE(Left(L"abc") < Right(L"abcd"));
    REQUIRE_FALSE(Left(L"abcd") < Right(L"abc"));

    REQUIRE(Left(L"abcd") >= Right(L"abc"));
    REQUIRE_FALSE(Left(L"abc") >= Right(L"abcd"));

    REQUIRE(Left(L"abc") <= Right(L"abcd"));
    REQUIRE_FALSE(Left(L"abcd") <= Right(L"abc"));
}

TEST_CASE("std::wstring,compare,std::wstring")
{
    // This tests the test_compare function itself.
    // It is only here to serve as a reference point for the following tests.
    // There is nothing in production code that can affect this test.

    test_compare<std::wstring, std::wstring>();
}

TEST_CASE("hstring,compare,hstring")
{
    test_compare<hstring, hstring>();
}

TEST_CASE("hstring,compare,std::wstring")
{
    test_compare<hstring, std::wstring>();
}

TEST_CASE("std::wstring,compare,hstring")
{
    test_compare<std::wstring, hstring>();
}

TEST_CASE("hstring,compare,wchar_t const *")
{
    test_compare<hstring, wchar_t const *>();
}

TEST_CASE("wchar_t const *,compare,hstring")
{
    test_compare<wchar_t const *, hstring>();
}

TEST_CASE("hstring,compare,hstring_ref")
{
    test_compare<hstring, hstring_ref>();
}

TEST_CASE("hstring_ref,compare,hstring")
{
    test_compare<hstring_ref, hstring>();
}

TEST_CASE("hstring_ref,compare,hstring_ref")
{
    test_compare<hstring_ref, hstring_ref>();
}

TEST_CASE("hstring_ref,compare,std::wstring")
{
    test_compare<hstring_ref, std::wstring>();
}

TEST_CASE("std::wstring,compare,hstring_ref")
{
    test_compare<std::wstring, hstring_ref>();
}

TEST_CASE("hstring_ref,compare,wchar_t const *")
{
    test_compare<hstring_ref, wchar_t const *>();
}

TEST_CASE("wchar_t const *,compare,hstring_ref")
{
    test_compare<wchar_t const *, hstring_ref>();
}

TEST_CASE("hstring,map")
{
    // Ensures that std::less<winrt::hstring> can be instantiated.

    std::map<hstring, int> m{ { L"abc", 10 },{ L"def", 20 } };
    REQUIRE(m[L"abc"] == 10);
    REQUIRE(m[L"def"] == 20);
}

TEST_CASE("hstring,unordered_map")
{
    // Ensures that std::hash<winrt::hstring> can be instantiated.

    std::unordered_map<hstring, int> m{ { L"abc", 10 },{ L"def", 20 } };
    REQUIRE(m[L"abc"] == 10);
    REQUIRE(m[L"def"] == 20);
}

static bool compare_hash(const std::wstring & value)
{
    return std::hash<std::wstring>{}(value) == std::hash<winrt::hstring>{}(value);
}

TEST_CASE("hstring,hash")
{
    // Ensures that std::hash<winrt::hstring> and std::hash<std::wstring> behave the same.
    // Since they both implement the same FNV-1a hash function the results should be the same.

    REQUIRE(compare_hash(L""));
    REQUIRE(compare_hash(L"Hello"));
    REQUIRE(compare_hash(L"World"));
}
