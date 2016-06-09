#include "pch.h"
#include "catch.hpp"
#include <array>
#include <future>

using namespace winrt;
using namespace Windows::Foundation;
using namespace Windows::Storage::Streams;
using namespace Windows::Devices::Sms;
using namespace Windows::Security::Cryptography::Certificates;
using namespace Windows::Web::Syndication;

//
// First some array tests using the projection (real-world examples).
//

//
// This is a helper to create a data reader for use in testing arrays.
//
static std::future<IDataReader> CreateDataReader(std::initializer_list<byte> values)
{
    InMemoryRandomAccessStream stream;
    DataWriter writer(stream);
    writer.WriteByte(1);
    writer.WriteByte(2);
    writer.WriteByte(3);
    await writer.StoreAsync();

    stream.Seek(0);
    DataReader reader(stream);
    await reader.LoadAsync(3);
    return reader;
}

//
// This is a helper to create a syndication feed (collection) for testing arrays.
//
static std::future<SyndicationFeed> GetSyndicationFeed()
{
    Uri uri(L"https://blogs.msdn.microsoft.com/vcblog/feed/");
    SyndicationClient client;

    return await client.RetrieveFeedAsync(uri);
}

//
// This test illustrates an array_ref<T const> and a com_array<T> as a retval.
//
TEST_CASE("array,SmsBinaryMessage")
{
    CertificateQuery query;
    query.Thumbprint({ 1, 2, 3 }); // PassArray pattern

    com_array<byte> a = query.Thumbprint(); // ReceiveArray pattern

    REQUIRE(3 == a.size());
    REQUIRE(1 == a[0]);
    REQUIRE(2 == a[1]);
    REQUIRE(3 == a[2]);
}

//
// This test illustrates a com_array<T> as an out param.
//
TEST_CASE("array,CreateInt32Array,GetInt32Array")
{
    com_array<int> a;
    PropertyValue::CreateInt32Array({ 1, 2, 3 }). // PassArray pattern
        as<IPropertyValue>().GetInt32Array(a); // ReceiveArray pattern

    REQUIRE(3 == a.size());
    REQUIRE(1 == a[0]);
    REQUIRE(2 == a[1]);
    REQUIRE(3 == a[2]);
}

//
// This test illustrates an array_ref<T> (non-const) bound to a std::array<T, N>
//
TEST_CASE("array,DataReader")
{
    auto reader = CreateDataReader({1, 2, 3}).get();

    std::array<byte, 3> a;
    reader.ReadBytes(a); // FillArray pattern

    REQUIRE(3 == a.size());
    REQUIRE(1 == a[0]);
    REQUIRE(2 == a[1]);
    REQUIRE(3 == a[2]);
}

//
// This test illustrates an array_ref<T> (non-const) bound to a std::vector<T>
//
TEST_CASE("array,DataReader,std::vector")
{
    auto reader = CreateDataReader({ 1, 2, 3 }).get();

    std::vector<byte> a(3);
    reader.ReadBytes(a); // FillArray pattern

    REQUIRE(a.size() == 3);
    REQUIRE(a[0] == 1);
    REQUIRE(a[1] == 2);
    REQUIRE(a[2] == 3);
}

//
// This test illustrates receiving an IVector and calling GetMany to fill an array.
//
TEST_CASE("array,EBO")
{
    //
    // This version calls GetMany on the collection.
    //
    SECTION("collection")
    {
        SyndicationFeed feed = GetSyndicationFeed().get();

        std::vector<hstring> expected;

        for (auto item : feed.Items())
        {
            expected.emplace_back(item.Title().Text());
        }

        std::vector<SyndicationItem> items(expected.size());
        REQUIRE(expected.size() == feed.Items().GetMany(0, items));

        std::vector<hstring> actual;

        for (auto && item : items)
        {
            actual.emplace_back(item.Title().Text());
        }

        REQUIRE(expected == actual);
    }

    //
    // And this version calls GetMany on the iterator.
    //
    SECTION("iterator")
    {
        SyndicationFeed feed = GetSyndicationFeed().get();

        std::vector<hstring> expected;

        for (auto item : feed.Items())
        {
            expected.emplace_back(item.Title().Text());
        }

        std::vector<SyndicationItem> items(expected.size());
        REQUIRE(expected.size() == feed.Items().First().GetMany(items));

        std::vector<hstring> actual;

        for (auto && item : items)
        {
            actual.emplace_back(item.Title().Text());
        }

        REQUIRE(expected == actual);
    }
}

//
// Now some tests to cover the array members.
//

//
// Here we're testing 'operator[]' for the three array patterns.
//
TEST_CASE("array,[N]")
{
    SECTION("array_ref")
    {
        std::vector<int> v{ 1, 2, 3 };
        array_ref<int> a = v;

        a[1] = 20;

        REQUIRE(a[0] == 1);
        REQUIRE(a[1] == 20);
        REQUIRE(a[2] == 3);

    }

    SECTION("array_cref")
    {
        array_ref<int const> a{ 1, 2, 3 };

        REQUIRE(a[0] == 1);
        REQUIRE(a[1] == 2);
        REQUIRE(a[2] == 3);
    }

    SECTION("com_array")
    {
        com_array<int> a{ 1, 2, 3 };

        a[1] = 20;

        REQUIRE(a[0] == 1);
        REQUIRE(a[1] == 20);
        REQUIRE(a[2] == 3);
    }
}

//
// Here we're testing 'operator[] const' for the three array patterns.
//
TEST_CASE("array,[N],const")
{
    SECTION("array_ref")
    {
        std::vector<int> v{ 1, 2, 3 };
        array_ref<int> const a = v;

        REQUIRE(a[0] == 1);
        REQUIRE(a[1] == 2);
        REQUIRE(a[2] == 3);
    }

    SECTION("array_cref")
    {
        array_ref<int const> const a{ 1, 2, 3 };

        REQUIRE(a[0] == 1);
        REQUIRE(a[1] == 2);
        REQUIRE(a[2] == 3);
    }

    SECTION("com_array")
    {
        com_array<int> const a{ 1, 2, 3 };

        REQUIRE(a[0] == 1);
        REQUIRE(a[1] == 2);
        REQUIRE(a[2] == 3);
    }
}

//
// Here we're testing 'at()' for the three array patterns.
//
TEST_CASE("array,at")
{
    SECTION("array_ref")
    {
        std::vector<int> v{ 1, 2, 3 };
        array_ref<int> a = v;

        a.at(1) = 20;

        REQUIRE(a.at(0) == 1);
        REQUIRE(a.at(1) == 20);
        REQUIRE(a.at(2) == 3);

    }

    SECTION("array_cref")
    {
        array_ref<int const> a{ 1, 2, 3 };

        REQUIRE(a.at(0) == 1);
        REQUIRE(a.at(1) == 2);
        REQUIRE(a.at(2) == 3);
    }

    SECTION("com_array")
    {
        com_array<int> a{ 1, 2, 3 };

        a.at(1) = 20;

        REQUIRE(a.at(0) == 1);
        REQUIRE(a.at(1) == 20);
        REQUIRE(a.at(2) == 3);
    }
}

//
// Here we're testing 'at() const' for the three array patterns.
//
TEST_CASE("array,at,const")
{
    SECTION("array_ref")
    {
        std::vector<int> v{ 1, 2, 3 };
        array_ref<int> const a = v;

        REQUIRE(a.at(0) == 1);
        REQUIRE(a.at(1) == 2);
        REQUIRE(a.at(2) == 3);
    }

    SECTION("array_cref")
    {
        array_ref<int const> const a{ 1, 2, 3 };

        REQUIRE(a.at(0) == 1);
        REQUIRE(a.at(1) == 2);
        REQUIRE(a.at(2) == 3);
    }

    SECTION("com_array")
    {
        com_array<int> const a{ 1, 2, 3 };

        REQUIRE(a.at(0) == 1);
        REQUIRE(a.at(1) == 2);
        REQUIRE(a.at(2) == 3);
    }
}

//
// Here we're testing that 'at()' throws out_of_range for the three array patterns.
//
TEST_CASE("array,at,throw")
{
    SECTION("array_ref")
    {
        std::vector<int> v{ 1, 2, 3 };
        array_ref<int> const a = v;

        try
        {
            a.at(3);
            FAIL(L"Previous line should throw");
        }
        catch (std::out_of_range const & e)
        {
            REQUIRE(std::string("Invalid array subscript") == e.what());
        }
    }

    SECTION("array_cref")
    {
        array_ref<int const> const a{ 1, 2, 3 };

        try
        {
            a.at(4);
            FAIL(L"Previous line should throw");
        }
        catch (std::out_of_range const & e)
        {
            REQUIRE(std::string("Invalid array subscript") == e.what());
        }
    }

    SECTION("com_array")
    {
        com_array<int> const a{ 1, 2, 3 };

        try
        {
            a.at(5);
            FAIL(L"Previous line should throw");
        }
        catch (std::out_of_range const & e)
        {
            REQUIRE(std::string("Invalid array subscript") == e.what());
        }
    }
}

//
// Tests for the front/back methods for the three array patterns.
//
TEST_CASE("array,front,back")
{
    SECTION("array_ref")
    {
        std::vector<int> v{ 1, 2, 3 };
        array_ref<int> a = v;

        a.front() = 10;
        a.back() = 30;

        REQUIRE(a.front() == 10);
        REQUIRE(a.back() == 30);
    }

    SECTION("array_cref")
    {
        array_ref<int const> a{ 1, 2, 3 };

        REQUIRE(a.front() == 1);
        REQUIRE(a.back() == 3);
    }

    SECTION("com_array")
    {
        com_array<int> a{ 1, 2, 3 };

        a.front() = 10;
        a.back() = 30;

        REQUIRE(a.front() == 10);
        REQUIRE(a.back() == 30);
    }
}

//
// Tests for the front/back methods for the three array patterns (const versions).
//
TEST_CASE("array,front,back,const")
{
    SECTION("array_ref")
    {
        std::vector<int> v{ 1, 2, 3 };
        array_ref<int> const a = v;

        REQUIRE(a.front() == 1);
        REQUIRE(a.back() == 3);
    }

    SECTION("array_cref")
    {
        array_ref<int const> const a{ 1, 2, 3 };

        REQUIRE(a.front() == 1);
        REQUIRE(a.back() == 3);
    }

    SECTION("com_array")
    {
        com_array<int> const a{ 1, 2, 3 };

        REQUIRE(a.front() == 1);
        REQUIRE(a.back() == 3);
    }
}

//
// Tests for the 'data' method for the three array patterns.
//
TEST_CASE("array,data")
{
    SECTION("array_ref")
    {
        std::vector<int> v{ 1, 2, 3 };
        array_ref<int> a = v;
        REQUIRE(v.data() == a.data());

        int * p = a.data();

        p[1] = 20;

        REQUIRE(p[0] == 1);
        REQUIRE(p[1] == 20);
        REQUIRE(p[2] == 3);

        REQUIRE(a[0] == 1);
        REQUIRE(a[1] == 20);
        REQUIRE(a[2] == 3);
    }

    SECTION("array_cref")
    {
        std::vector<int> v{ 1, 2, 3 };
        array_ref<int const> a = v;
        REQUIRE(v.data() == a.data());

        int const * p = a.data();

        REQUIRE(p[0] == 1);
        REQUIRE(p[1] == 2);
        REQUIRE(p[2] == 3);
    }

    SECTION("com_array")
    {
        com_array<int> a{ 1, 2, 3 };

        int * p = a.data();

        p[1] = 20;

        REQUIRE(p[0] == 1);
        REQUIRE(p[1] == 20);
        REQUIRE(p[2] == 3);

        REQUIRE(a[0] == 1);
        REQUIRE(a[1] == 20);
        REQUIRE(a[2] == 3);
    }
}

//
// Tests for the 'data' method for the three array patterns.
//
TEST_CASE("array,data,const")
{
    SECTION("array_ref")
    {
        std::vector<int> v{ 1, 2, 3 };
        array_ref<int> const a = v;

        int const * p = a.data();

        REQUIRE(p[0] == 1);
        REQUIRE(p[1] == 2);
        REQUIRE(p[2] == 3);
    }

    SECTION("array_cref")
    {
        array_ref<int const> const a{ 1, 2, 3 };

        int const * p = a.data();

        REQUIRE(p[0] == 1);
        REQUIRE(p[1] == 2);
        REQUIRE(p[2] == 3);
    }

    SECTION("com_array")
    {
        com_array<int> const a{ 1, 2, 3 };

        int const * p = a.data();

        REQUIRE(p[0] == 1);
        REQUIRE(p[1] == 2);
        REQUIRE(p[2] == 3);
    }
}

//
// Tests for the 'begin/end' methods for the three array patterns.
//
TEST_CASE("array,begin,end")
{
    SECTION("array_ref")
    {
        std::vector<int> v{ 1, 2, 3 };
        array_ref<int> a = v;

        int * first = a.begin();
        int * last = a.end();

        for (int * i = first; i != last; ++i)
        {
            *i *= 10;
        }

        REQUIRE(a[0] == 10);
        REQUIRE(a[1] == 20);
        REQUIRE(a[2] == 30);
    }

    SECTION("array_cref")
    {
        std::vector<int> v{ 1, 2, 3 };
        array_ref<int const> a = v;

        std::vector<int> copy(a.begin(), a.end());
        REQUIRE(v == copy);
    }

    SECTION("com_array")
    {
        com_array<int> a{ 1, 2, 3 };

        int * first = a.begin();
        int * last = a.end();

        for (int * i = first; i != last; ++i)
        {
            *i *= 10;
        }

        REQUIRE(a[0] == 10);
        REQUIRE(a[1] == 20);
        REQUIRE(a[2] == 30);
    }

}

//
// Tests for the 'begin/end' methods for the three array patterns (const versions).
//
TEST_CASE("array,begin,end,const")
{
    SECTION("array_ref")
    {
        std::vector<int> v{ 1, 2, 3 };
        array_ref<int> const a = v;

        std::vector<int> copy(a.begin(), a.end());
        REQUIRE(v == copy);
    }

    SECTION("array_cref")
    {
        std::vector<int> v{ 1, 2, 3 };
        array_ref<int const> const a = v;

        std::vector<int> copy(a.begin(), a.end());
        REQUIRE(v == copy);
    }

    SECTION("com_array")
    {
        std::vector<int> v{ 1, 2, 3 };
        com_array<int> const a(v);

        std::vector<int> copy(a.begin(), a.end());
        REQUIRE(v == copy);
    }
}

//
// Tests for the 'cbegin/cend' methods for the three array patterns.
//
TEST_CASE("array,cbegin,cend,const")
{
    SECTION("array_ref")
    {
        std::vector<int> v{ 1, 2, 3 };
        array_ref<int> const a = v;

        std::vector<int> copy(a.cbegin(), a.cend());
        REQUIRE(v == copy);
    }

    SECTION("array_cref")
    {
        std::vector<int> v{ 1, 2, 3 };
        array_ref<int const> const a = v;

        std::vector<int> copy(a.cbegin(), a.cend());
        REQUIRE(v == copy);
    }

    SECTION("com_array")
    {
        std::vector<int> v{ 1, 2, 3 };
        com_array<int> const a(v);

        std::vector<int> copy(a.cbegin(), a.cend());
        REQUIRE(v == copy);
    }
}

//
// Tests for the 'rbegin/rend' methods for the three array patterns.
//
TEST_CASE("array,rbegin,rend")
{
    SECTION("array_ref")
    {
        std::vector<int> v{ 1, 2, 3 };
        array_ref<int> a = v;

        auto first = a.rbegin();
        auto last = a.rend();

        REQUIRE(3 == *first);

        for (auto i = first; i != last; ++i)
        {
            *i *= 10;
        }

        REQUIRE(a[0] == 10);
        REQUIRE(a[1] == 20);
        REQUIRE(a[2] == 30);
    }

    SECTION("array_cref")
    {
        std::vector<int> v{ 1, 2, 3 };
        array_ref<int const> a = v;

        std::vector<int> copy(a.rbegin(), a.rend());

        std::reverse(v.begin(), v.end());
        REQUIRE(v == copy);
    }

    SECTION("com_array")
    {
        com_array<int> a{ 1, 2, 3 };

        auto first = a.rbegin();
        auto last = a.rend();

        REQUIRE(3 == *first);

        for (auto i = first; i != last; ++i)
        {
            *i *= 10;
        }

        REQUIRE(a[0] == 10);
        REQUIRE(a[1] == 20);
        REQUIRE(a[2] == 30);
    }

}

//
// Tests for the 'rbegin/rend' methods for the three array patterns (const versions).
//
TEST_CASE("array,rbegin,rend,const")
{
    SECTION("array_ref")
    {
        std::vector<int> v{ 1, 2, 3 };
        array_ref<int> const a = v;

        std::vector<int> copy(a.rbegin(), a.rend());
        std::reverse(v.begin(), v.end());
        REQUIRE(v == copy);
    }

    SECTION("array_cref")
    {
        std::vector<int> v{ 1, 2, 3 };
        array_ref<int const> const a = v;

        std::vector<int> copy(a.rbegin(), a.rend());
        std::reverse(v.begin(), v.end());
        REQUIRE(v == copy);
    }

    SECTION("com_array")
    {
        std::vector<int> v{ 1, 2, 3 };
        com_array<int> const a(v);

        std::vector<int> copy(a.rbegin(), a.rend());
        std::reverse(v.begin(), v.end());
        REQUIRE(v == copy);
    }
}

//
// Tests for the 'crbegin/crend' methods for the three array patterns.
//
TEST_CASE("array,crbegin,crend,const")
{
    SECTION("array_ref")
    {
        std::vector<int> v{ 1, 2, 3 };
        array_ref<int> const a = v;

        std::vector<int> copy(a.crbegin(), a.crend());
        std::reverse(v.begin(), v.end());
        REQUIRE(v == copy);
    }

    SECTION("array_cref")
    {
        std::vector<int> v{ 1, 2, 3 };
        array_ref<int const> const a = v;

        std::vector<int> copy(a.crbegin(), a.crend());
        std::reverse(v.begin(), v.end());
        REQUIRE(v == copy);
    }

    SECTION("com_array")
    {
        std::vector<int> v{ 1, 2, 3 };
        com_array<int> const a(v);

        std::vector<int> copy(a.crbegin(), a.crend());
        std::reverse(v.begin(), v.end());
        REQUIRE(v == copy);
    }
}

//
// array_ref
//

//
// Tests array_ref support for ranges.
//
TEST_CASE("array_ref,range")
{
    {
        int v[] { 1, 2, 3 };
        array_ref<int> a(v, v + _countof(v));
        REQUIRE(a.begin() == v);
        REQUIRE(a.end() == v + _countof(v));
    }

    {
        int v[]{ 1, 2, 3 };
        array_ref<int const> a(v, v + _countof(v));
        REQUIRE(a.begin() == v);
        REQUIRE(a.end() == v + _countof(v));
    }

    {
        int const v[]{ 1, 2, 3 };
        array_ref<int const> a(v, v + _countof(v));
        REQUIRE(a.begin() == v);
        REQUIRE(a.end() == v + _countof(v));
    }
}

//
// Tests array_ref support for initializer list construction.
//
TEST_CASE("array_ref,initializer_list")
{
    // initializer_list cannot be used with array_ref of non-const T

    array_ref<int const> a { 1, 2, 3 };
    REQUIRE(a.size() == 3);
}

//
// Tests array_ref support for various C-style array construction.
//
TEST_CASE("array_ref,C-style array")
{
    {
        int v[] = { 1, 2, 3 };
        array_ref<int> a = v;
        REQUIRE(a.data() == v);
        REQUIRE(a.size() == 3);
    }

    {
        int v[] = { 1, 2, 3 };
        array_ref<int const> a = v;
        REQUIRE(a.data() == v);
        REQUIRE(a.size() == 3);
    }

    {
        int const v[] = { 1, 2, 3 };
        array_ref<int const> a = v;
        REQUIRE(a.data() == v);
        REQUIRE(a.size() == 3);
    }
}

//
// Tests array_ref support for various std::vector construction.
//
TEST_CASE("array_ref,vector")
{
    {
        std::vector<int> v = { 1, 2, 3 };
        array_ref<int> a = v;
        REQUIRE(a.data() == v.data());
        REQUIRE(a.size() == 3);
    }

    {
        std::vector<int> v = { 1, 2, 3 };
        array_ref<int const> a = v;
        REQUIRE(a.data() == v.data());
        REQUIRE(a.size() == 3);
    }

    {
        std::vector<int> const v = { 1, 2, 3 };
        array_ref<int const> a = v;
        REQUIRE(a.data() == v.data());
        REQUIRE(a.size() == 3);
    }
}

//
// Tests array_ref support for various std::array construction.
//
TEST_CASE("array_ref,array")
{
    {
        std::array<int, 3> v = { 1, 2, 3 };
        array_ref<int> a = v;
        REQUIRE(a.data() == v.data());
        REQUIRE(a.size() == 3);
    }

    {
        std::array<int, 3> v = { 1, 2, 3 };
        array_ref<int const> a = v;
        REQUIRE(a.data() == v.data());
        REQUIRE(a.size() == 3);
    }

    {
        std::array<int, 3> const v = { 1, 2, 3 };
        array_ref<int const> a = v;
        REQUIRE(a.data() == v.data());
        REQUIRE(a.size() == 3);
    }
}

//
// com_array
//

//
// Tests default construction of com_array.
//
TEST_CASE("com_array,default")
{
    com_array<int> a;
    REQUIRE(a.empty());
    REQUIRE(nullptr == a.begin());
    REQUIRE(nullptr == a.end());
}

//
// Tests com_array's count constructor (must not be confused with initializer list).
//
TEST_CASE("com_array,count")
{
    com_array<int> a(3);
    REQUIRE(3 == a.size());
    REQUIRE(a[0] == 0);
    REQUIRE(a[1] == 0);
    REQUIRE(a[2] == 0);
}

//
// Tests com_array's N values constructor (must not be confused with initializer list).
//
TEST_CASE("com_array,count,value")
{
    com_array<int> a(3U, 123);
    REQUIRE(3 == a.size());
    REQUIRE(a[0] == 123);
    REQUIRE(a[1] == 123);
    REQUIRE(a[2] == 123);
}

//
// Tests com_array's range constructor.
//
TEST_CASE("com_array,range")
{
    std::vector<int> v { 1, 2, 3 };
    com_array<int> a(v.begin(), v.end());
    REQUIRE(3 == a.size());
    REQUIRE(a[0] == 1);
    REQUIRE(a[1] == 2);
    REQUIRE(a[2] == 3);
}

//
// Tests com_array's std::vector constructor.
//
TEST_CASE("com_array,vector")
{
    std::vector<int> v{ 1, 2, 3 };
    com_array<int> a(v);
    REQUIRE(3 == a.size());
    REQUIRE(a[0] == 1);
    REQUIRE(a[1] == 2);
    REQUIRE(a[2] == 3);
}

//
// Tests com_array's std::array constructor.
//
TEST_CASE("com_array,array")
{
    std::array<int, 3> v{ 1, 2, 3 };
    com_array<int> a(v);
    REQUIRE(3 == a.size());
    REQUIRE(a[0] == 1);
    REQUIRE(a[1] == 2);
    REQUIRE(a[2] == 3);
}

//
// Tests com_array's C-style array constructor.
//
TEST_CASE("com_array,C-style array")
{
    int v[3] { 1, 2, 3 };
    com_array<int> a(v);
    REQUIRE(3 == a.size());
    REQUIRE(a[0] == 1);
    REQUIRE(a[1] == 2);
    REQUIRE(a[2] == 3);
}

//
// Tests com_array's initializer list constructor.
//
TEST_CASE("com_array,initializer_list")
{
    com_array<int> a { 1, 2, 3 };
    REQUIRE(3 == a.size());
    REQUIRE(a[0] == 1);
    REQUIRE(a[1] == 2);
    REQUIRE(a[2] == 3);
}

//
// Tests com_array's move constructor and move assignment.
//
TEST_CASE("com_array,move")
{
    com_array<int> a{ 1, 2, 3 };
    com_array<int> b = std::move(a);

    REQUIRE(a.empty());
    REQUIRE(3 == b.size());

    a = std::move(b);

    REQUIRE(3 == a.size());
    REQUIRE(b.empty());
}

//
// Now some tests covering producing and consuming arrays
//

struct ProducePropertyValueArray : implements<ProducePropertyValueArray, IPropertyValue>
{
    void GetInt32Array(com_array<int32_t> & value)
    {
        value = { 1, 2, 3 };
    }

    void GetSizeArray(com_array<Windows::Foundation::Size> & value)
    {
        value = { {1,1}, {2,2}, {3,3} };
    }

    void GetInspectableArray(com_array<Windows::IInspectable> & value)
    {
        value = { Uri(L"http://one/"), Uri(L"http://two/"), Uri(L"http://three/") };
    }
};

bool operator==(Size left, Size right)
{
    return left.Width == right.Width &&
           left.Height == right.Height;
}

TEST_CASE("array,PropertyValue")
{
    SECTION("consume,array,int32_t")
    {
        auto inspectable = PropertyValue::CreateInt32Array({ 1, 2, 3 });
        auto pv = inspectable.as<IPropertyValue>();

        com_array<int32_t> a;
        pv.GetInt32Array(a);

        REQUIRE(3 == a.size());
        REQUIRE(a[0] == 1);
        REQUIRE(a[1] == 2);
        REQUIRE(a[2] == 3);
    }

    SECTION("produce,array,int32_t")
    {
        auto pv = make<ProducePropertyValueArray>();

        com_array<int32_t> a;
        pv.GetInt32Array(a);

        REQUIRE(3 == a.size());
        REQUIRE(a[0] == 1);
        REQUIRE(a[1] == 2);
        REQUIRE(a[2] == 3);
    }

    SECTION("consume,array,Size")
    {
        auto inspectable = PropertyValue::CreateSizeArray({ { 1,1 },{ 2,2 },{ 3,3 } });
        auto pv = inspectable.as<IPropertyValue>();

        com_array<Size> a;
        pv.GetSizeArray(a);

        REQUIRE(3 == a.size());
        REQUIRE(a[0].Width == 1); REQUIRE(a[0].Height == 1);
        REQUIRE(a[1].Width == 2); REQUIRE(a[1].Height == 2);
        REQUIRE(a[2].Width == 3); REQUIRE(a[2].Height == 3);
    }

    SECTION("produce,array,Size")
    {
        auto pv = make<ProducePropertyValueArray>();

        com_array<Size> a;
        pv.GetSizeArray(a);

        REQUIRE(3 == a.size());
        REQUIRE(a[0].Width == 1); REQUIRE(a[0].Height == 1);
        REQUIRE(a[1].Width == 2); REQUIRE(a[1].Height == 2);
        REQUIRE(a[2].Width == 3); REQUIRE(a[2].Height == 3);
    }

    SECTION("consume,array,Inspectable")
    {
        auto inspectable = PropertyValue::CreateInspectableArray({ Uri(L"http://one/"), Uri(L"http://two/"), Uri(L"http://three/") });
        auto pv = inspectable.as<IPropertyValue>();

        com_array<Windows::IInspectable> a;
        pv.GetInspectableArray(a);

        REQUIRE(3 == a.size());
        REQUIRE(a[0].as<Uri>().Host() == L"one");
        REQUIRE(a[1].as<Uri>().Host() == L"two");
        REQUIRE(a[2].as<Uri>().Host() == L"three");
    }

    SECTION("produce,array,Inspectable")
    {
        auto pv = make<ProducePropertyValueArray>();

        com_array<Windows::IInspectable> a;
        pv.GetInspectableArray(a);

        REQUIRE(3 == a.size());
        REQUIRE(a[0].as<Uri>().Host() == L"one");
        REQUIRE(a[1].as<Uri>().Host() == L"two");
        REQUIRE(a[2].as<Uri>().Host() == L"three");
    }
}

//
// Comparisons
//

template <typename T, typename ... Args>
static T test_make(Args ... args)
{
    return T{ args ... };
}

//
// This test_compare function produces various productions of arrays for generic types of arrays
// so that we can run the same set of tests against different classes of arrays.
//
template <typename Left, typename Right>
static void test_compare()
{
    REQUIRE(test_make<Left>('a', 'b', 'c') == test_make<Right>('a', 'b', 'c'));
    REQUIRE_FALSE(test_make<Left>('a', 'b', 'c') == test_make<Right>('a', 'b', 'c', 'd'));

    REQUIRE(test_make<Left>('a', 'b', 'c') != test_make<Right>('a', 'b', 'c', 'd'));
    REQUIRE_FALSE(test_make<Left>('a', 'b', 'c') != test_make<Right>('a', 'b', 'c'));

    REQUIRE(test_make<Left>('a', 'b', 'c', 'd') > test_make<Right>('a', 'b', 'c'));
    REQUIRE_FALSE(test_make<Left>('a', 'b', 'c') > test_make<Right>('a', 'b', 'c', 'd'));

    REQUIRE(test_make<Left>('a', 'b', 'c') < test_make<Right>('a', 'b', 'c', 'd'));
    REQUIRE_FALSE(test_make<Left>('a', 'b', 'c', 'd') < test_make<Right>('a', 'b', 'c'));

    REQUIRE(test_make<Left>('a', 'b', 'c', 'd') >= test_make<Right>('a', 'b', 'c'));
    REQUIRE_FALSE(test_make<Left>('a', 'b', 'c') >= test_make<Right>('a', 'b', 'c', 'd'));

    REQUIRE(test_make<Left>('a', 'b', 'c') <= test_make<Right>('a', 'b', 'c', 'd'));
    REQUIRE_FALSE(test_make<Left>('a', 'b', 'c', 'd') <= test_make<Right>('a', 'b', 'c'));
}

TEST_CASE("std::vector,compare,std::vector")
{
    // This tests the test_compare function itself.
    // It is only here to serve as a reference point for the following tests.
    // There is nothing in production code that can affect this test.

    test_compare<std::vector<char>, std::vector<char>>();
}

TEST_CASE("com_array,compare,com_array")
{
    // Tests the comparison operators against com_array 

    test_compare<com_array<char>, com_array<char>>();
}

TEST_CASE("array_ref,compare,array_ref")
{
    // Tests the comparison operators against array_ref 

    test_compare<array_ref<char const>, array_ref<char const>>();
}


