#include "pch.h"
#include "catch.hpp"
#include "map.h"
#include "vector.h"

using namespace winrt;
using namespace Windows::Foundation::Collections;

//
// These tests simply ensure that the empty_collection does in fact create an instance that is empty.
//

TEST_CASE("empty_collection, IIterable<T>")
{
    IIterable<int> c(empty_collection);
    REQUIRE(!c.First().HasCurrent()); // IIterable has no efficient way to check for empty.
}

TEST_CASE("empty_collection, IIterable<IKeyValuePair<K, V>>")
{
    IIterable<IKeyValuePair<int32_t, hstring>> c(empty_collection);
    REQUIRE(!c.First().HasCurrent()); // IIterable has no efficient way to check for empty.
}

TEST_CASE("empty_collection, IVectorView<T>")
{
    IVectorView<int> c(empty_collection);
    REQUIRE(c.Size() == 0);
}

TEST_CASE("empty_collection, IVector<T>")
{
    IVector<int> c(empty_collection);
    REQUIRE(c.Size() == 0);
}

TEST_CASE("empty_collection, IMapView<K, V>")
{
    IMapView<int32_t, hstring> c(empty_collection);
    REQUIRE(c.Size() == 0);
}

TEST_CASE("empty_collection, IMap<K, V>")
{
    IMap<int32_t, hstring> c(empty_collection);
    REQUIRE(c.Size() == 0);
}

//
// These tests addditionally ensure that implicit parameter binding works without forcing the developer
// to utter the type name on the call site.
//

namespace
{
    void empty_iterable(IIterable<int> const & c)
    {
        REQUIRE(!c.First().HasCurrent()); // IIterable has no efficient way to check for empty.
    }

    void empty_iterable_key_value_pair(IIterable<IKeyValuePair<int32_t, hstring>> const & c)
    {
        REQUIRE(!c.First().HasCurrent()); // IIterable has no efficient way to check for empty.
    }

    void empty_vector_view(IVectorView<int> const & c)
    {
        REQUIRE(c.Size() == 0);
    }

    void empty_vector(IVector<int> const & c)
    {
        REQUIRE(c.Size() == 0);
    }

    void empty_map_view(IMapView<int32_t, hstring> const & c)
    {
        REQUIRE(c.Size() == 0);
    }

    void empty_map(IMap<int32_t, hstring> const & c)
    {
        REQUIRE(c.Size() == 0);
    }
}

TEST_CASE("empty_collection, parameters")
{
    empty_iterable(empty_collection);
    empty_iterable_key_value_pair(empty_collection);
    empty_vector_view(empty_collection);
    empty_vector(empty_collection);
    empty_map_view(empty_collection);
    empty_map(empty_collection);
}
