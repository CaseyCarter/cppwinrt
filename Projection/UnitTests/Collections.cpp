#include "pch.h"
#include "catch.hpp"
#include "vector_iterable.h"
#include "range_iterable.h"

//
// This tests the sample implementations of IIterable<T> namely vector_iterable and range_iterable.
//

using namespace winrt;
using namespace Windows::Foundation::Collections;
using namespace samples;

void TestIterable(IIterable<int> const & collection)
{
    // not null
    REQUIRE(collection);

    // unique iterators
    REQUIRE(collection.First() != collection.First());

    IIterator<int> it = collection.First();

    REQUIRE(it.Current() == 1);
    REQUIRE(it.Current() == 1);
    REQUIRE(it.HasCurrent());
    REQUIRE(it.HasCurrent());
    REQUIRE(it.MoveNext());
    REQUIRE(it.Current() == 2);
    REQUIRE(it.HasCurrent());
    REQUIRE(it.MoveNext());
    REQUIRE(it.Current() == 3);
    REQUIRE(it.HasCurrent());
    REQUIRE(!it.MoveNext());
    REQUIRE(!it.MoveNext());

    REQUIRE_TERMINATE(it.Current(), hresult_out_of_bounds);

    // nothing left
    std::array<int, 4> many {};
    REQUIRE(it.GetMany(many) == 0);

    // reset iterator and ask for more
    it = collection.First();
    std::array<int, 5> more{};
    REQUIRE(it.GetMany(more) == 3);
    REQUIRE(more[0] == 1);
    REQUIRE(more[1] == 2);
    REQUIRE(more[2] == 3);
    REQUIRE(more[3] == 0);
    REQUIRE(more[4] == 0);

    // reset iterator and ask for less
    it = collection.First();
    std::array<int, 2> less{};
    REQUIRE(it.GetMany(less) == 2);
    REQUIRE(less[0] == 1);
    REQUIRE(less[1] == 2);
    REQUIRE(it.GetMany(less) == 1);
    REQUIRE(less[0] == 3);
    REQUIRE(less[1] == 2);
}

TEST_CASE("sample iterable vector")
{
    {
        std::vector<int> values { 1, 2, 3 };
        IIterable<int> collection = make<vector_iterable<int>>(values);
        TestIterable(collection);
    }

    {
        std::list<int> values{ 1, 2, 3 };
        IIterable<int> collection = make_range_iterable(begin(values), end(values));
        TestIterable(collection);
    }

    {
        std::array<int, 3> values{ 1, 2, 3 };
        IIterable<int> collection = make_range_iterable(begin(values), end(values));
        TestIterable(collection);
    }

    {
        std::forward_list<int> values{ 1, 2, 3 };
        IIterable<int> collection = make_range_iterable(begin(values), end(values));
        TestIterable(collection);
    }

    {
        int values [] { 1, 2, 3 };
        IIterable<int> collection = make_range_iterable(values, values + _countof(values));
        TestIterable(collection);
    }
}
