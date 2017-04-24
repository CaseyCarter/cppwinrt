#include "pch.h"
#include "catch.hpp"
#include <deque>

namespace winrt::ABI::Windows::Foundation::Collections
{
    template <> struct __declspec(uuid("81a643fb-f51c-5565-83c4-f96425777b61")) __declspec(novtable) IKeyValuePair<int, int> : impl_IKeyValuePair<int, int> {};
    template <> struct __declspec(uuid("81a643fb-f51c-5565-83c4-f96425777b62")) __declspec(novtable) IIterator<IKeyValuePair<int, int>> : impl_IIterator<IKeyValuePair<int, int>> {};
    template <> struct __declspec(uuid("81a643fb-f51c-5565-83c4-f96425777b63")) __declspec(novtable) IIterable<IKeyValuePair<int, int>> : impl_IIterable<IKeyValuePair<int, int>> {};
    template <> struct __declspec(uuid("81a643fb-f51c-5565-83c4-f96425777b65")) __declspec(novtable) IMapView<int, int> : impl_IMapView<int, int> {};
    template <> struct __declspec(uuid("81a643fb-f51c-5565-83c4-f96425777b66")) __declspec(novtable) IMap<int, int> : impl_IMap<int, int> {};
}

using namespace winrt;
using namespace Windows::Foundation::Collections;

namespace
{
    void compare(IMap<int, int> const & left, std::map<int, int> && right)
    {
        std::map<int, int> copy;

        for (auto pair : left)
        {
            copy[pair.Key()] = pair.Value();
        }

        REQUIRE(copy == right);
    }

    template <typename Change>
    void test_invalidation(IMap<int, int> const & values, Change change)
    {
        std::array<IKeyValuePair<int, int>, 3> array;

        values.Insert(1,10);
        values.Insert(2,20);
        values.Insert(3,30);
        IIterator<IKeyValuePair<int, int>> first = values.First();
        first.HasCurrent();
        first.Current();
        first.MoveNext();
        first.GetMany(array);

        change(); // <-- invalidate

        REQUIRE_THROWS_AS(first.HasCurrent(), hresult_changed_state);
        REQUIRE_THROWS_AS(first.Current(), hresult_changed_state);
        REQUIRE_THROWS_AS(first.MoveNext(), hresult_changed_state);
        REQUIRE_THROWS_AS(first.GetMany(array), hresult_changed_state);
    }

    void test_map(IMap<int, int> const & values)
    {
        compare(values, {});

        REQUIRE(!values.Insert(1, 10));
        compare(values, {{1,10}});
        REQUIRE(values.Insert(1, 100));
        compare(values, { { 1,100 } });
        REQUIRE(!values.Insert(2, 20));
        compare(values, { { 1,100 }, {2,20} });

        values.Remove(3);
        compare(values, { { 1,100 },{ 2,20 } });
        values.Remove(2);
        compare(values, { { 1,100 } });
        values.Remove(1);
        compare(values, { });

        values.Insert(1,10);
        compare(values, { { 1,10 } });
        values.Clear();
        compare(values, {});

        test_invalidation(values, [&] { values.Clear(); });
        test_invalidation(values, [&] { values.Remove(10); });
        test_invalidation(values, [&] { values.Insert(1,10); });
    }
}

TEST_CASE("single_threaded_map - construction")
{
    IMap<int, int> values;

    values = single_threaded_map<int, int>();
    REQUIRE(values.Size() == 0);

    values = single_threaded_map<int, int>(std::map<int, int>{ { 1,10 },{ 2,20 },{ 3,30 } });
    compare(values, { { 1,10 },{ 2,20 },{ 3,30 } });

    values = single_threaded_map<int, int>(std::unordered_map<int, int>{ { 1, 10 }, { 2,20 }, { 3,30 } });
    compare(values, { { 1,10 },{ 2,20 },{ 3,30 } });
}

TEST_CASE("test_map")
{
    test_map(single_threaded_map<int, int>());

    // TODO: Uncomment these tests once the collection variants are available.
    //test_map(agile_map<int, int>());
    //test_map(non_agile_map<int, int>());
}
