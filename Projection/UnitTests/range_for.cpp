#include "pch.h"
#include "catch.hpp"
#include "vector.h"
#include "map.h"

//
// These tests confirm that the C++/WinRT collections support range-based for loop iteration
// by providing the appropriate begin/end functions required by the C++ compiler.
//

using namespace winrt;
using namespace Windows::Foundation::Collections;

TEST_CASE("range_for,IIterable")
{
    IIterable<int> c = make<impl::Vector<int>>(std::vector<int> { 1, 2, 3 });
    std::vector<int> result;

    for (int i : c)
    {
        result.push_back(i);
    }

    REQUIRE(result[0] == 1);
    REQUIRE(result[1] == 2);
    REQUIRE(result[2] == 3);
}

TEST_CASE("range_for,IVector")
{
    IVector<int> c = make<impl::Vector<int>>(std::vector<int> { 1, 2, 3 });
    std::vector<int> result;

    for (int i : c)
    {
        result.push_back(i);
    }

    REQUIRE(result[0] == 1);
    REQUIRE(result[1] == 2);
    REQUIRE(result[2] == 3);
}

TEST_CASE("range_for,IVectorView")
{
    IVectorView<int> c = make<impl::Vector<int>>(std::vector<int> { 1, 2, 3 }).GetView();
    std::vector<int> result;

    for (int i : c)
    {
        result.push_back(i);
    }

    REQUIRE(result[0] == 1);
    REQUIRE(result[1] == 2);
    REQUIRE(result[2] == 3);
}

TEST_CASE("range_for,IIterable,IKeyValuePair")
{
    std::map<int, hstring> values
    {
        { 1, hstring{ L"one" }},
        { 2, hstring{ L"two" }},
        { 3, hstring{ L"three" }},
    };

    IIterable<IKeyValuePair<int32_t, hstring>> c = make<impl::Map<std::map<int, hstring>>>(values);
    std::map<int, hstring> result;

    for (IKeyValuePair<int32_t, hstring> i : c)
    {
        result[i.Key()] = i.Value();
    }

    REQUIRE(result == values);
}

TEST_CASE("range_for,IMap")
{
    std::map<int, hstring> values
    {
        { 1, hstring{ L"one" } },
        { 2, hstring{ L"two" } },
        { 3, hstring{ L"three" } },
    };

    IMap<int32_t, hstring> c = make<impl::Map<std::map<int, hstring>>>(values);
    std::map<int, hstring> result;

    for (IKeyValuePair<int32_t, hstring> i : c)
    {
        result[i.Key()] = i.Value();
    }

    REQUIRE(result == values);
}

TEST_CASE("range_for,IMapView")
{
    std::map<int, hstring> values
    {
        { 1, hstring{ L"one" } },
        { 2, hstring{ L"two" } },
        { 3, hstring{ L"three" } },
    };

    IMapView<int32_t, hstring> c = make<impl::Map<std::map<int, hstring>>>(values).GetView();
    std::map<int, hstring> result;

    for (IKeyValuePair<int32_t, hstring> i : c)
    {
        result[i.Key()] = i.Value();
    }

    REQUIRE(result == values);
}

