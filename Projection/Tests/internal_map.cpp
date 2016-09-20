#include "pch.h"
#include "catch.hpp"

using namespace winrt::Windows::Foundation::Collections;
using namespace winrt;

namespace winrt::ABI::Windows::Foundation::Collections {

template <> struct __declspec(uuid("81a643fb-f51c-5565-83c4-f96425777b61")) __declspec(novtable) IKeyValuePair<int32_t, hstring> : impl_IKeyValuePair<int32_t, hstring> {};

template <> struct __declspec(uuid("81a643fb-f51c-5565-83c4-f96425777b64")) __declspec(novtable) IMap<int32_t, hstring> : impl_IMap<int32_t, hstring> {};
template <> struct __declspec(uuid("81a643fb-f51c-5565-83c4-f96425777b65")) __declspec(novtable) IMapView<int32_t, hstring> : impl_IMapView<int32_t, hstring> {};
template <> struct __declspec(uuid("81a643fb-f51c-5565-83c4-f96425777b63")) __declspec(novtable) IIterable<IKeyValuePair<int32_t, hstring>> : impl_IIterable<IKeyValuePair<int32_t, hstring>> {};
template <> struct __declspec(uuid("81a643fb-f51c-5565-83c4-f96425777b62")) __declspec(novtable) IIterator<IKeyValuePair<int32_t, hstring>> : impl_IIterator<IKeyValuePair<int32_t, hstring>> {};

}


#pragma region "Tests, create using different source containers, use different destination containers"

void ValidateMap(IMap<int, hstring>& map)
{
    REQUIRE(map != nullptr);
    REQUIRE(map.Size() == 2);
    REQUIRE(map.HasKey(1));
    REQUIRE(map.Lookup(1) == L"value1");
    REQUIRE(map.HasKey(2));
    REQUIRE(map.Lookup(2) == L"value2");
    map = nullptr;
}

void ValidateMapView(IMapView<int, hstring>& view)
{
    REQUIRE(view != nullptr);
    REQUIRE(view.Size() == 2);
    REQUIRE(view.HasKey(1));
    REQUIRE(view.Lookup(1) == L"value1");
    REQUIRE(view.HasKey(2));
    REQUIRE(view.Lookup(2) == L"value2");
    view = nullptr;
}

void ValidateIterable(IIterable<IKeyValuePair<int, hstring>>& iter)
{
    REQUIRE(iter != nullptr);
    iter = nullptr;
}

TEST_CASE("Map, create, r-value from std::map")
{
    std::map<int, hstring> myStdMap { std::pair<int, hstring> { 1, L"value1"}, std::pair<int, hstring> { 2, L"value2"} };
    IMap<int, hstring> obj = winrt::make<winrt::impl::map<int, hstring, std::map<int, hstring>>>(std::move(myStdMap));
    ValidateMap(obj);
}

TEST_CASE("Map, create, r-value from std::unordered_map")
{
    std::unordered_map<int, hstring> myStdMap { std::pair<int, hstring> { 1, L"value1"}, std::pair<int, hstring> { 2, L"value2"} };
    IMap<int, hstring> obj = winrt::make<winrt::impl::map<int, hstring, std::unordered_map<int, hstring>>>(std::move(myStdMap));
    ValidateMap(obj);
}

TEST_CASE("Map, create, iterators from std::map, container std::unordered_map")
{
    std::map<int, hstring> myStdMap { std::pair<int, hstring> { 1, L"value1"}, std::pair<int, hstring> { 2, L"value2"} };
    IMap<int, hstring> obj = winrt::make<winrt::impl::map<int, hstring, std::unordered_map<int, hstring>>>(myStdMap.begin(), myStdMap.end());
    ValidateMap(obj);
}

TEST_CASE("Map, create, iterators from std::unordered_map, container std::map")
{
    std::unordered_map<int, hstring> myStdMap { std::pair<int, hstring> { 1, L"value1"}, std::pair<int, hstring> { 2, L"value2"} };
    IMap<int, hstring> obj = winrt::make<winrt::impl::map<int, hstring, std::map<int, hstring>>>(myStdMap.begin(), myStdMap.end());
    ValidateMap(obj);
}

TEST_CASE("Map, create, il, container std::map")
{
    auto il = { std::pair<int, hstring> { 1, L"value1"}, std::pair<int, hstring> { 2, L"value2"} };
    IMap<int, hstring> obj = winrt::make<winrt::impl::map<int, hstring, std::map<int, hstring>>>(il);
    ValidateMap(obj);
}

TEST_CASE("Map, create, il, container std::unordered_map")
{
    auto il = { std::pair<int, hstring> { 1, L"value1"}, std::pair<int, hstring> { 2, L"value2"} };
    IMap<int, hstring> obj = winrt::make<winrt::impl::map<int, hstring, std::unordered_map<int, hstring>>>(il);
    ValidateMap(obj);
}

TEST_CASE("IMapView, create, r-value from std::map")
{
    std::map<int, hstring> myStdMap { std::pair<int, hstring> { 1, L"value1"}, std::pair<int, hstring> { 2, L"value2"} };
    IMapView<int, hstring> obj = winrt::make<winrt::impl::map_view_standalone<int, hstring, std::map<int, hstring>>>(std::move(myStdMap));
    ValidateMapView(obj);
}

TEST_CASE("IMapView, create, r-value from std::unordered_map")
{
    std::unordered_map<int, hstring> myStdMap { std::pair<int, hstring> { 1, L"value1"}, std::pair<int, hstring> { 2, L"value2"} };
    IMapView<int, hstring> obj = winrt::make<winrt::impl::map_view_standalone<int, hstring, std::unordered_map<int, hstring>>>(std::move(myStdMap));
    ValidateMapView(obj);
}

TEST_CASE("IMapView, create, iterators from std::map, container std::unordered_map")
{
    std::map<int, hstring> myStdMap { std::pair<int, hstring> { 1, L"value1"}, std::pair<int, hstring> { 2, L"value2"} };
    IMapView<int, hstring> obj = winrt::make<winrt::impl::map_view_standalone<int, hstring, std::unordered_map<int, hstring>>>(myStdMap.begin(), myStdMap.end());
    ValidateMapView(obj);
}

TEST_CASE("IMapView, create, iterators from std::unordered_map, container std::map")
{
    std::unordered_map<int, hstring> myStdMap { std::pair<int, hstring> { 1, L"value1"}, std::pair<int, hstring> { 2, L"value2"} };
    IMapView<int, hstring> obj = winrt::make<winrt::impl::map_view_standalone<int, hstring, std::map<int, hstring>>>(myStdMap.begin(), myStdMap.end());
    ValidateMapView(obj);
}

TEST_CASE("IMapView, create, il, container std::map")
{
    auto il = { std::pair<int, hstring> { 1, L"value1"}, std::pair<int, hstring> { 2, L"value2"} };
    IMapView<int, hstring> obj = winrt::make<winrt::impl::map_view_standalone<int, hstring, std::map<int, hstring>>>(il);
    ValidateMapView(obj);
}

TEST_CASE("IMapView, create, il, container std::unordered_map")
{
    auto il = { std::pair<int, hstring> { 1, L"value1"}, std::pair<int, hstring> { 2, L"value2"} };
    IMapView<int, hstring> obj = winrt::make<winrt::impl::map_view_standalone<int, hstring, std::unordered_map<int, hstring>>>(il);
    ValidateMapView(obj);
}

TEST_CASE("IIterable<IKeyValuePair<K, V>>, create, r-value from std::map")
{
    std::map<int, hstring> myStdMap { std::pair<int, hstring> { 1, L"value1"}, std::pair<int, hstring> { 2, L"value2"} };
    IIterable<IKeyValuePair<int, hstring>> obj = winrt::make<winrt::impl::iterable<IKeyValuePair<int, hstring>, std::map<int, hstring>>>(std::move(myStdMap));
    ValidateIterable(obj);
}

TEST_CASE("IIterable<IKeyValuePair<K, V>>, create, r-value from std::unordered_map")
{
    std::unordered_map<int, hstring> myStdMap { std::pair<int, hstring> { 1, L"value1"}, std::pair<int, hstring> { 2, L"value2"} };
    IIterable<IKeyValuePair<int, hstring>> obj = winrt::make<winrt::impl::iterable<IKeyValuePair<int, hstring>, std::unordered_map<int, hstring>>>(std::move(myStdMap));
    ValidateIterable(obj);
}

TEST_CASE("IIterable<IKeyValuePair<K, V>>, create, iterators from std::map, container std::unordered_map")
{
    std::map<int, hstring> myStdMap { std::pair<int, hstring> { 1, L"value1"}, std::pair<int, hstring> { 2, L"value2"} };
    IIterable<IKeyValuePair<int, hstring>> obj = winrt::make<winrt::impl::iterable<IKeyValuePair<int, hstring>, std::unordered_map<int, hstring>>>(myStdMap.begin(), myStdMap.end());
    ValidateIterable(obj);
}

TEST_CASE("IIterable<IKeyValuePair<K, V>>, create, iterators from std::unordered_map, container std::map")
{
    std::unordered_map<int, hstring> myStdMap { std::pair<int, hstring> { 1, L"value1"}, std::pair<int, hstring> { 2, L"value2"} };
    IIterable<IKeyValuePair<int, hstring>> obj = winrt::make<winrt::impl::iterable<IKeyValuePair<int, hstring>, std::map<int, hstring>>>(myStdMap.begin(), myStdMap.end());
    ValidateIterable(obj);
}

#pragma endregion

#pragma region "Tests, IMap"

TEST_CASE("Map, create, empty")
{
    IMap<int, hstring> obj = winrt::make<winrt::impl::map<int, hstring, std::map<int, hstring>>>();

    REQUIRE(obj != nullptr);
    REQUIRE(obj.Size() == 0);
}

TEST_CASE("Map, create, from std::map, rvalue, has elements")
{
    std::map<int, hstring> myStdMap { std::pair<int, hstring> { 1, L"value1"}, std::pair<int, hstring> { 2, L"value2"} };
    IMap<int, hstring> obj = winrt::make<winrt::impl::map<int, hstring, std::map<int, hstring>>>(std::move(myStdMap));

    REQUIRE(obj != nullptr);
    REQUIRE(obj.Size() == 2);
    REQUIRE(obj.HasKey(1));
    REQUIRE(obj.Lookup(1) == L"value1");
    REQUIRE(obj.HasKey(2));
    REQUIRE(obj.Lookup(2) == L"value2");
}

TEST_CASE("Map, create, from il, has elements")
{
    auto il = { std::pair<int, hstring> { 1, L"value1"}, std::pair<int, hstring> { 2, L"value2"} };
    IMap<int, hstring> obj = winrt::make<winrt::impl::map<int, hstring, std::map<int, hstring>>>(il);

    REQUIRE(obj != nullptr);
    REQUIRE(obj.Size() == 2);
    REQUIRE(obj.HasKey(1));
    REQUIRE(obj.Lookup(1) == L"value1");
    REQUIRE(obj.HasKey(2));
    REQUIRE(obj.Lookup(2) == L"value2");
}

TEST_CASE("Map, create, from iterators, has elements")
{
    std::map<int, hstring> myStdMap { std::pair<int, hstring> { 1, L"value1"}, std::pair<int, hstring> { 2, L"value2"} };
    IMap<int, hstring> obj = winrt::make<winrt::impl::map<int, hstring, std::map<int, hstring>>>(myStdMap.begin(), myStdMap.end());

    REQUIRE(obj != nullptr);
    REQUIRE(obj.Size() == 2);
    REQUIRE(obj.HasKey(1));
    REQUIRE(obj.Lookup(1) == L"value1");
    REQUIRE(obj.HasKey(2));
    REQUIRE(obj.Lookup(2) == L"value2");
}

TEST_CASE("Map, Clear")
{
    std::map<int, hstring> myStdMap { std::pair<int, hstring> { 1, L"value1"}, std::pair<int, hstring> { 2, L"value2"} };
    IMap<int, hstring> obj = winrt::make<winrt::impl::map<int, hstring, std::map<int, hstring>>>(std::move(myStdMap));

    REQUIRE(obj.Size() == 2);
    obj.Clear();
    REQUIRE(obj.Size() == 0);

    // Call clear again should just work fine
    obj.Clear();
    REQUIRE(obj.Size() == 0);
}

TEST_CASE("Map, GetView")
{
    std::map<int, hstring> myStdMap { std::pair<int, hstring> { 1, L"value1"}, std::pair<int, hstring> { 2, L"value2"} };
    IMap<int, hstring> obj = winrt::make<winrt::impl::map<int, hstring, std::map<int, hstring>>>(std::move(myStdMap));
    IMapView<int, hstring> view = obj.GetView();

    REQUIRE(view != nullptr);

    REQUIRE(view.Size() == 2);
    REQUIRE(view.HasKey(1));
    REQUIRE(view.HasKey(2));
    REQUIRE(view.Lookup(1) == L"value1");
    REQUIRE(view.Lookup(2) == L"value2");
}

TEST_CASE("Map, Lookup")
{
    std::map<int, hstring> myStdMap { std::pair<int, hstring> { 1, L"value1"}, std::pair<int, hstring> { 2, L"value2"} };
    IMap<int, hstring> obj = winrt::make<winrt::impl::map<int, hstring, std::map<int, hstring>>>(std::move(myStdMap));

    REQUIRE(obj.Lookup(1) == L"value1");
    REQUIRE(obj.Lookup(2) == L"value2");

    REQUIRE_THROWS_AS(obj.Lookup(3), hresult_out_of_bounds);
}

TEST_CASE("Map, HasKey")
{
    std::map<int, hstring> myStdMap { std::pair<int, hstring> { 1, L"value1"}, std::pair<int, hstring> { 2, L"value2"} };
    IMap<int, hstring> obj = winrt::make<winrt::impl::map<int, hstring, std::map<int, hstring>>>(std::move(myStdMap));

    REQUIRE(obj.HasKey(1));
    REQUIRE(obj.HasKey(2));
    REQUIRE(!obj.HasKey(3));

    obj.Clear();

    REQUIRE(!obj.HasKey(1));
    REQUIRE(!obj.HasKey(2));
    REQUIRE(!obj.HasKey(3));
}

TEST_CASE("Map, Insert, empty")
{
    IMap<int, hstring> obj = winrt::make<winrt::impl::map<int, hstring, std::map<int, hstring>>>();
    REQUIRE(!obj.Insert(1, L"value1"));
    REQUIRE(obj.Size() == 1);
    REQUIRE(obj.Lookup(1) == L"value1");

    REQUIRE(!obj.Insert(2, L"value2"));
    REQUIRE(obj.Size() == 2);
    REQUIRE(obj.Lookup(1) == L"value1");
    REQUIRE(obj.Lookup(2) == L"value2");
}

TEST_CASE("Map, Insert, not empty")
{
    std::map<int, hstring> myStdMap { std::pair<int, hstring> { 1, L"value1"}, std::pair<int, hstring> { 2, L"value2"} };
    IMap<int, hstring> obj = winrt::make<winrt::impl::map<int, hstring, std::map<int, hstring>>>(std::move(myStdMap));
    REQUIRE(obj.Size() == 2);

    REQUIRE(!obj.Insert(3, L"value3"));
    REQUIRE(obj.Size() == 3);
    REQUIRE(obj.Lookup(1) == L"value1");
    REQUIRE(obj.Lookup(2) == L"value2");
    REQUIRE(obj.Lookup(3) == L"value3");
}

TEST_CASE("Map, Insert, not empty, insert after Clear")
{
    std::map<int, hstring> myStdMap { std::pair<int, hstring> { 1, L"value1"}, std::pair<int, hstring> { 2, L"value2"} };
    IMap<int, hstring> obj = winrt::make<winrt::impl::map<int, hstring, std::map<int, hstring>>>(std::move(myStdMap));

    REQUIRE(obj.Size() == 2);
    REQUIRE(obj.Lookup(1) == L"value1");
    REQUIRE(obj.Lookup(2) == L"value2");

    obj.Clear();
    REQUIRE(obj.Size() == 0);

    REQUIRE(!obj.Insert(1, L"value3"));
    REQUIRE(!obj.Insert(2, L"value4"));

    REQUIRE(obj.Size() == 2);
    REQUIRE(obj.Lookup(1) == L"value3");
    REQUIRE(obj.Lookup(2) == L"value4");
}

TEST_CASE("Map, Insert, pair replaced")
{
    std::map<int, hstring> myStdMap { std::pair<int, hstring> { 1, L"value1"}, std::pair<int, hstring> { 2, L"value2"} };
    IMap<int, hstring> obj = winrt::make<winrt::impl::map<int, hstring, std::map<int, hstring>>>(std::move(myStdMap));

    REQUIRE(obj.Insert(1, L"value3"));
    REQUIRE(obj.Insert(2, L"value4"));

    REQUIRE(obj.Size() == 2);
    REQUIRE(obj.Lookup(1) == L"value3");
    REQUIRE(obj.Lookup(2) == L"value4");
}

TEST_CASE("Map, Erase, not empty, keys exists")
{
    std::map<int, hstring> myStdMap { std::pair<int, hstring> { 1, L"value1"}, std::pair<int, hstring> { 2, L"value2"} };
    IMap<int, hstring> obj = winrt::make<winrt::impl::map<int, hstring, std::map<int, hstring>>>(std::move(myStdMap));
    REQUIRE(obj.Size() == 2);

    obj.Remove(2);
    REQUIRE(obj.Size() == 1);
    REQUIRE(!obj.HasKey(2));
    REQUIRE(obj.HasKey(1));
    REQUIRE(obj.Lookup(1) == L"value1");

    obj.Remove(1);
    REQUIRE(obj.Size() == 0);
    REQUIRE(!obj.HasKey(1));
    REQUIRE(!obj.HasKey(2));
}

TEST_CASE("Map, Erase, not empty, key does not exists")
{
    std::map<int, hstring> myStdMap { std::pair<int, hstring> { 1, L"value1"}, std::pair<int, hstring> { 2, L"value2"} };
    IMap<int, hstring> obj = winrt::make<winrt::impl::map<int, hstring, std::map<int, hstring>>>(std::move(myStdMap));
    REQUIRE(obj.Size() == 2);

    obj.Remove(3);
    REQUIRE(obj.Size() == 2);
    REQUIRE(obj.HasKey(1));
    REQUIRE(obj.HasKey(2));
    REQUIRE(obj.Lookup(1) == L"value1");
    REQUIRE(obj.Lookup(2) == L"value2");
}

TEST_CASE("Map, Erase, empty, key does not exists")
{
    IMap<int, hstring> obj = winrt::make<winrt::impl::map<int, hstring, std::map<int, hstring>>>();
    REQUIRE(obj.Size() == 0);

    obj.Remove(3);
    REQUIRE(obj.Size() == 0);
}

TEST_CASE("Map, First")
{
    std::map<int, hstring> myStdMap { std::pair<int, hstring> { 1, L"value1"}, std::pair<int, hstring> { 2, L"value2"} };
    IMap<int, hstring> obj = winrt::make<winrt::impl::map<int, hstring, std::map<int, hstring>>>(std::move(myStdMap));
    IIterator<IKeyValuePair<int, hstring>> itor = obj.First();

    REQUIRE(itor != nullptr);
    REQUIRE(itor.HasCurrent());

    REQUIRE(itor.Current().Key() == 1);
    REQUIRE(itor.Current().Value() == L"value1");

    REQUIRE(itor.MoveNext());
    REQUIRE(itor.Current().Key() == 2);
    REQUIRE(itor.Current().Value() == L"value2");

    REQUIRE(!itor.MoveNext());
}

#pragma endregion

#pragma region "Tests, IMapView from IMap"

TEST_CASE("IMapView from IMap, HasKey")
{
    std::map<int, hstring> myStdMap { std::pair<int, hstring> { 1, L"value1"}, std::pair<int, hstring> { 2, L"value2"} };
    IMap<int, hstring> obj = winrt::make<winrt::impl::map<int, hstring, std::map<int, hstring>>>(std::move(myStdMap));
    IMapView<int, hstring> view = obj.GetView();

    REQUIRE(view.HasKey(1));
    REQUIRE(view.HasKey(2));

    REQUIRE(!view.HasKey(3));
}

TEST_CASE("IMapView from IMap, Lookup")
{
    std::map<int, hstring> myStdMap { std::pair<int, hstring> { 1, L"value1"}, std::pair<int, hstring> { 2, L"value2"} };
    IMap<int, hstring> obj = winrt::make<winrt::impl::map<int, hstring, std::map<int, hstring>>>(std::move(myStdMap));
    IMapView<int, hstring> view = obj.GetView();

    REQUIRE(view.Lookup(1) == L"value1");
    REQUIRE(view.Lookup(2) == L"value2");

    REQUIRE_THROWS_AS(obj.Lookup(3), hresult_out_of_bounds);
}

TEST_CASE("IMapView from IMap, Split")
{
    std::map<int, hstring> myStdMap { std::pair<int, hstring> { 1, L"value1"}, std::pair<int, hstring> { 2, L"value2"} };
    IMap<int, hstring> obj = winrt::make<winrt::impl::map<int, hstring, std::map<int, hstring>>>(std::move(myStdMap));
    IMapView<int, hstring> view = obj.GetView();
    IMapView<int, hstring> first;
    IMapView<int, hstring> second;

    view.Split(first, second);

    REQUIRE(first == nullptr);
    REQUIRE(second == nullptr);
}

TEST_CASE("IMapView from IMap, Size, has elements")
{
    std::map<int, hstring> myStdMap { std::pair<int, hstring> { 1, L"value1"}, std::pair<int, hstring> { 2, L"value2"} };
    IMap<int, hstring> obj = winrt::make<winrt::impl::map<int, hstring, std::map<int, hstring>>>(std::move(myStdMap));
    IMapView<int, hstring> view = obj.GetView();

    REQUIRE(view.Size() == 2);
}

TEST_CASE("IMapView from IMap, Size, no elements")
{
    IMap<int, hstring> obj = winrt::make<winrt::impl::map<int, hstring, std::map<int, hstring>>>();
    IMapView<int, hstring> view = obj.GetView();

    REQUIRE(view.Size() == 0);
}

#pragma endregion

#pragma region "Tests IMapView, standalone"

TEST_CASE("IMapView standalone, create from std::map, has elements")
{
    std::unordered_map<int, hstring> myStdMap { std::pair<int, hstring> { 1, L"value1"}, std::pair<int, hstring> { 2, L"value2"} };
    IMapView<int, hstring> view = winrt::make<impl::map_view_standalone<int, hstring, std::unordered_map<int, hstring>>>(std::move(myStdMap));

    REQUIRE(view != nullptr);
    REQUIRE(view.Size() == 2);
    REQUIRE(view.HasKey(1));
    REQUIRE(view.Lookup(1) == L"value1");
    REQUIRE(view.HasKey(2));
    REQUIRE(view.Lookup(2) == L"value2");
}

TEST_CASE("IMapView standalone, create from iterators, has elements")
{
    std::unordered_map<int, hstring> myStdMap { std::pair<int, hstring> { 1, L"value1"}, std::pair<int, hstring> { 2, L"value2"} };
    IMapView<int, hstring> view = winrt::make<impl::map_view_standalone<int, hstring, std::unordered_map<int, hstring>>>(myStdMap.begin(), myStdMap.end());

    REQUIRE(view != nullptr);
    REQUIRE(view.Size() == 2);
    REQUIRE(view.HasKey(1));
    REQUIRE(view.Lookup(1) == L"value1");
    REQUIRE(view.HasKey(2));
    REQUIRE(view.Lookup(2) == L"value2");
}

TEST_CASE("IMapView standalone, create, no elements")
{
    IMapView<int, hstring> view = winrt::make<impl::map_view_standalone<int, hstring, std::unordered_map<int, hstring>>>();

    REQUIRE(view != nullptr);
    REQUIRE(view.Size() == 0);
}

TEST_CASE("IMapView standalone, create, from il, has elements")
{
    auto il = { std::pair<int, hstring> { 1, L"value1"}, std::pair<int, hstring> { 2, L"value2"} };
    IMapView<int, hstring> obj = winrt::make<winrt::impl::map_view_standalone<int, hstring, std::unordered_map<int, hstring>>>(il);

    REQUIRE(obj != nullptr);
    REQUIRE(obj.Size() == 2);
    REQUIRE(obj.HasKey(1));
    REQUIRE(obj.Lookup(1) == L"value1");
    REQUIRE(obj.HasKey(2));
    REQUIRE(obj.Lookup(2) == L"value2");
}

TEST_CASE("IMapView standalone, HasKey")
{
    std::unordered_map<int, hstring> myStdMap { std::pair<int, hstring> { 1, L"value1"}, std::pair<int, hstring> { 2, L"value2"} };
    IMapView<int, hstring> view = winrt::make<impl::map_view_standalone<int, hstring, std::unordered_map<int, hstring>>>(std::move(myStdMap));

    REQUIRE(view.HasKey(1));
    REQUIRE(view.HasKey(2));
    
    REQUIRE(!view.HasKey(3));
}

TEST_CASE("IMapView standalone, Lookup")
{
    std::unordered_map<int, hstring> myStdMap { std::pair<int, hstring> { 1, L"value1"}, std::pair<int, hstring> { 2, L"value2"} };
    IMapView<int, hstring> view = winrt::make<impl::map_view_standalone<int, hstring, std::unordered_map<int, hstring>>>(std::move(myStdMap));

    REQUIRE(view.Lookup(1) == L"value1");
    REQUIRE(view.Lookup(2) == L"value2");

    REQUIRE_THROWS_AS(view.Lookup(3), hresult_out_of_bounds);
}

TEST_CASE("IMapView standalone, Split")
{
    std::unordered_map<int, hstring> myStdMap { std::pair<int, hstring> { 1, L"value1"}, std::pair<int, hstring> { 2, L"value2"} };
    IMapView<int, hstring> view = winrt::make<impl::map_view_standalone<int, hstring, std::unordered_map<int, hstring>>>(std::move(myStdMap));
    IMapView<int, hstring> first;
    IMapView<int, hstring> second;

    view.Split(first, second);

    REQUIRE(first == nullptr);
    REQUIRE(second == nullptr);
}

TEST_CASE("IMapView standalone, Size, has elements")
{
    std::unordered_map<int, hstring> myStdMap { std::pair<int, hstring> { 1, L"value1"}, std::pair<int, hstring> { 2, L"value2"} };
    IMapView<int, hstring> view = winrt::make<impl::map_view_standalone<int, hstring, std::unordered_map<int, hstring>>>(std::move(myStdMap));

    REQUIRE(view.Size() == 2);
}

TEST_CASE("IMapView standalone, Size, no elements")
{
    IMapView<int, hstring> view = winrt::make<impl::map_view_standalone<int, hstring, std::unordered_map<int, hstring>>>();

    REQUIRE(view.Size() == 0);
}

#pragma endregion

#pragma region "Tests, IMap IIterable, standalone"

TEST_CASE("IMap IIterable,create,rvalue")
{
    std::map<int, hstring> myStdMap { std::pair<int, hstring> { 1, L"value1"}, std::pair<int, hstring> { 2, L"value2"} };
    IIterable<IKeyValuePair<int, hstring>> iter = winrt::make<winrt::impl::iterable<IKeyValuePair<int, hstring>, std::map<int, hstring>>>(std::move(myStdMap));
    REQUIRE(iter != nullptr);
    IIterator<IKeyValuePair<int, hstring>> itor = iter.First();
    REQUIRE(itor != nullptr);

    REQUIRE(itor.Current().Key() == 1);
    REQUIRE(itor.Current().Value() == L"value1");
    REQUIRE(itor.MoveNext());
    REQUIRE(itor.Current().Key() == 2);
    REQUIRE(itor.Current().Value() == L"value2");
    REQUIRE_FALSE(itor.MoveNext());
}

TEST_CASE("IMap IIterable,create,iterators")
{
    std::map<int, hstring> myStdMap { std::pair<int, hstring> { 1, L"value1"}, std::pair<int, hstring> { 2, L"value2"} };
    IIterable<IKeyValuePair<int, hstring>> iter = winrt::make<winrt::impl::iterable<IKeyValuePair<int, hstring>, std::map<int, hstring>>>(myStdMap.begin(), myStdMap.end());
    REQUIRE(iter != nullptr);
    IIterator<IKeyValuePair<int, hstring>> itor = iter.First();
    REQUIRE(itor != nullptr);

    REQUIRE(itor.Current().Key() == 1);
    REQUIRE(itor.Current().Value() == L"value1");
    REQUIRE(itor.MoveNext());
    REQUIRE(itor.Current().Key() == 2);
    REQUIRE(itor.Current().Value() == L"value2");
    REQUIRE_FALSE(itor.MoveNext());
}

#pragma endregion

#pragma region "Test, IMap IIterable, from IMap"

TEST_CASE("IMap IIterable, from IMap, create, rvalue")
{
    std::map<int, hstring> myStdMap { std::pair<int, hstring> { 1, L"value1"}, std::pair<int, hstring> { 2, L"value2"} };
    IMap<int, hstring> obj = winrt::make<winrt::impl::map<int, hstring, std::map<int, hstring>>>(std::move(myStdMap));
    IIterable<IKeyValuePair<int, hstring>> iter = obj;

    REQUIRE(iter != nullptr);
    IIterator<IKeyValuePair<int, hstring>> itor = iter.First();
    REQUIRE(itor != nullptr);

    REQUIRE(itor.Current().Key() == 1);
    REQUIRE(itor.Current().Value() == L"value1");
    REQUIRE(itor.MoveNext());
    REQUIRE(itor.Current().Key() == 2);
    REQUIRE(itor.Current().Value() == L"value2");
    REQUIRE_FALSE(itor.MoveNext());
}

TEST_CASE("IMap IIterable, from IMap, create, iterators")
{
    std::map<int, hstring> myStdMap { std::pair<int, hstring> { 1, L"value1"}, std::pair<int, hstring> { 2, L"value2"} };
    IMap<int, hstring> obj = winrt::make<winrt::impl::map<int, hstring, std::map<int, hstring>>>(myStdMap.begin(), myStdMap.end());
    IIterable<IKeyValuePair<int, hstring>> iter = obj;

    REQUIRE(iter != nullptr);
    IIterator<IKeyValuePair<int, hstring>> itor = iter.First();
    REQUIRE(itor != nullptr);

    REQUIRE(itor.Current().Key() == 1);
    REQUIRE(itor.Current().Value() == L"value1");
    REQUIRE(itor.MoveNext());
    REQUIRE(itor.Current().Key() == 2);
    REQUIRE(itor.Current().Value() == L"value2");
    REQUIRE_FALSE(itor.MoveNext());
}

#pragma endregion

#pragma region "Test, IMap IIterable, from IMapView created from IMap"

TEST_CASE("IMap IIterable, from IMapView created from IMap, create, rvalue")
{
    std::map<int, hstring> myStdMap { std::pair<int, hstring> { 1, L"value1"}, std::pair<int, hstring> { 2, L"value2"} };
    IMap<int, hstring> obj = winrt::make<winrt::impl::map<int, hstring, std::map<int, hstring>>>(std::move(myStdMap));
    IMapView<int, hstring> view = obj.GetView();
    IIterable<IKeyValuePair<int, hstring>> iter = view;

    REQUIRE(iter != nullptr);
    IIterator<IKeyValuePair<int, hstring>> itor = iter.First();
    REQUIRE(itor != nullptr);

    REQUIRE(itor.Current().Key() == 1);
    REQUIRE(itor.Current().Value() == L"value1");
    REQUIRE(itor.MoveNext());
    REQUIRE(itor.Current().Key() == 2);
    REQUIRE(itor.Current().Value() == L"value2");
    REQUIRE_FALSE(itor.MoveNext());
}

TEST_CASE("IMap IIterable, from IMapView created from IMap, create, iterators")
{
    std::map<int, hstring> myStdMap { std::pair<int, hstring> { 1, L"value1"}, std::pair<int, hstring> { 2, L"value2"} };
    IMap<int, hstring> obj = winrt::make<winrt::impl::map<int, hstring, std::map<int, hstring>>>(myStdMap.begin(), myStdMap.end());
    IMapView<int, hstring> view = obj.GetView();
    IIterable<IKeyValuePair<int, hstring>> iter = view;

    REQUIRE(iter != nullptr);
    IIterator<IKeyValuePair<int, hstring>> itor = iter.First();
    REQUIRE(itor != nullptr);

    REQUIRE(itor.Current().Key() == 1);
    REQUIRE(itor.Current().Value() == L"value1");
    REQUIRE(itor.MoveNext());
    REQUIRE(itor.Current().Key() == 2);
    REQUIRE(itor.Current().Value() == L"value2");
    REQUIRE_FALSE(itor.MoveNext());
}

#pragma endregion

#pragma region "Test, IMap IIterable, from IMapView standalone"

TEST_CASE("IMap IIterable, from IMapView standalone, create, rvalue")
{
    std::unordered_map<int, hstring> myStdMap { std::pair<int, hstring> { 1, L"value1"}, std::pair<int, hstring> { 2, L"value2"} };
    IMapView<int, hstring> view = winrt::make<winrt::impl::map_view_standalone<int, hstring, std::unordered_map<int, hstring>>>(std::move(myStdMap));
    IIterable<IKeyValuePair<int, hstring>> iter = view;

    REQUIRE(iter != nullptr);
    IIterator<IKeyValuePair<int, hstring>> itor = iter.First();
    REQUIRE(itor != nullptr);

    REQUIRE(itor.Current().Key() == 1);
    REQUIRE(itor.Current().Value() == L"value1");
    REQUIRE(itor.MoveNext());
    REQUIRE(itor.Current().Key() == 2);
    REQUIRE(itor.Current().Value() == L"value2");
    REQUIRE_FALSE(itor.MoveNext());
}

TEST_CASE("IMap IIterable, from IMapView standalone, create, iterators")
{
    std::map<int, hstring> myStdMap { std::pair<int, hstring> { 1, L"value1"}, std::pair<int, hstring> { 2, L"value2"} };
    IMapView<int, hstring> view = winrt::make<winrt::impl::map_view_standalone<int, hstring, std::unordered_map<int, hstring>>>(myStdMap.begin(), myStdMap.end());
    IIterable<IKeyValuePair<int, hstring>> iter = view;

    REQUIRE(iter != nullptr);
    IIterator<IKeyValuePair<int, hstring>> itor = iter.First();
    REQUIRE(itor != nullptr);

    REQUIRE(itor.Current().Key() == 1);
    REQUIRE(itor.Current().Value() == L"value1");
    REQUIRE(itor.MoveNext());
    REQUIRE(itor.Current().Key() == 2);
    REQUIRE(itor.Current().Value() == L"value2");
    REQUIRE_FALSE(itor.MoveNext());
}

#pragma endregion

#pragma region "Tests, IMap IIterator, from IMap"

TEST_CASE("IMap IIterator, from IMap, Current, current has value")
{
    std::map<int, hstring> myStdMap { std::pair<int, hstring> { 1, L"value1"}, std::pair<int, hstring> { 2, L"value2"} };
    IMap<int, hstring> obj = winrt::make<winrt::impl::map<int, hstring, std::map<int, hstring>>>(std::move(myStdMap));
    IIterator<IKeyValuePair<int, hstring>> itor = obj.First();

    REQUIRE(itor.Current());
}

TEST_CASE("IMap IIterator, from IMap, Current, throws when empty")
{
    std::map<int, hstring> myStdMap;
    IMap<int, hstring> obj = winrt::make<winrt::impl::map<int, hstring, std::map<int, hstring>>>(std::move(myStdMap));
    IIterator<IKeyValuePair<int, hstring>> itor = obj.First();

    REQUIRE_THROWS_AS(itor.Current(), winrt::hresult_out_of_bounds);
}

TEST_CASE("IMap IIterator, from IMap, HasCurrent, true")
{
    std::map<int, hstring> myStdMap { std::pair<int, hstring> { 1, L"value1"}, std::pair<int, hstring> { 2, L"value2"} };
    IMap<int, hstring> obj = winrt::make<winrt::impl::map<int, hstring, std::map<int, hstring>>>(std::move(myStdMap));
    IIterator<IKeyValuePair<int, hstring>> itor = obj.First();

    REQUIRE(itor.HasCurrent());
}

TEST_CASE("IMap IIterator, from IMap, HasCurrent, false")
{
    std::map<int, hstring> myStdMap;
    IMap<int, hstring> obj = winrt::make<winrt::impl::map<int, hstring, std::map<int, hstring>>>(std::move(myStdMap));
    IIterator<IKeyValuePair<int, hstring>> itor = obj.First();

    REQUIRE_FALSE(itor.HasCurrent());
}

TEST_CASE("IMap IIterator, from IMap, MoveNext")
{
    std::map<int, hstring> myStdMap { std::pair<int, hstring> { 1, L"value1"}, std::pair<int, hstring> { 2, L"value2"} };
    IMap<int, hstring> obj = winrt::make<winrt::impl::map<int, hstring, std::map<int, hstring>>>(std::move(myStdMap));
    IIterator<IKeyValuePair<int, hstring>> itor = obj.First();

    REQUIRE(itor.HasCurrent());
    REQUIRE(itor.Current().Key() == 1);
    REQUIRE(itor.Current().Value() == L"value1");

    REQUIRE(itor.MoveNext());
    REQUIRE(itor.HasCurrent());
    REQUIRE(itor.Current().Key() == 2);
    REQUIRE(itor.Current().Value() == L"value2");

    REQUIRE_FALSE(itor.MoveNext());
    REQUIRE_FALSE(itor.HasCurrent());
}

TEST_CASE("IMap IIterator, from IMap, GetMany, output array has less size than the iterator")
{
    std::map<int, hstring> myStdMap { std::pair<int, hstring> { 1, L"value1"}, std::pair<int, hstring> { 2, L"value2"} };
    IMap<int, hstring> obj = winrt::make<winrt::impl::map<int, hstring, std::map<int, hstring>>>(std::move(myStdMap));
    IIterator<IKeyValuePair<int, hstring>> itor = obj.First();
    std::array<IKeyValuePair<int, hstring>, 1> output;

    REQUIRE(itor.GetMany(output) == 1);
    REQUIRE(output.size() == 1);
    REQUIRE(output.at(0).Key() == 1);
    REQUIRE(output.at(0).Value() == L"value1");
}

TEST_CASE("IMap IIterator, from IMap, GetMany, output array has the same number of elements")
{
    std::map<int, hstring> myStdMap { std::pair<int, hstring> { 1, L"value1"}, std::pair<int, hstring> { 2, L"value2"} };
    IMap<int, hstring> obj = winrt::make<winrt::impl::map<int, hstring, std::map<int, hstring>>>(std::move(myStdMap));
    IIterator<IKeyValuePair<int, hstring>> itor = obj.First();
    std::array<IKeyValuePair<int, hstring>, 2> output;

    REQUIRE(itor.GetMany(output) == 2);
    REQUIRE(output.size() == 2);
    REQUIRE(output.at(0).Key() == 1);
    REQUIRE(output.at(0).Value() == L"value1");
    REQUIRE(output.at(1).Key() == 2);
    REQUIRE(output.at(1).Value() == L"value2");
}

TEST_CASE("IMap IIterator, from IMap, GetMany, output array has more slots than the iterator")
{
    std::map<int, hstring> myStdMap { std::pair<int, hstring> { 1, L"value1"}, std::pair<int, hstring> { 2, L"value2"} };
    IMap<int, hstring> obj = winrt::make<winrt::impl::map<int, hstring, std::map<int, hstring>>>(std::move(myStdMap));
    IIterator<IKeyValuePair<int, hstring>> itor = obj.First();
    std::array<IKeyValuePair<int, hstring>, 3> output;

    REQUIRE(itor.GetMany(output) == 2);
    REQUIRE(output.size() == 3);
    REQUIRE(output.at(0).Key() == 1);
    REQUIRE(output.at(0).Value() == L"value1");
    REQUIRE(output.at(1).Key() == 2);
    REQUIRE(output.at(1).Value() == L"value2");
}

#pragma endregion

#pragma region "Tests, IMap IIterator, from IMapView created from IMap"

TEST_CASE("IMap IIterator, from IMapView created from IMap, Current, current has value")
{
    std::map<int, hstring> myStdMap { std::pair<int, hstring> { 1, L"value1"}, std::pair<int, hstring> { 2, L"value2"} };
    IMap<int, hstring> obj = winrt::make<winrt::impl::map<int, hstring, std::map<int, hstring>>>(std::move(myStdMap));
    IMapView<int, hstring> view = obj.GetView();
    IIterator<IKeyValuePair<int, hstring>> itor = view.First();

    REQUIRE(itor.Current());
}

TEST_CASE("IMap IIterator, from IMapView created from IMap, Current, throws when empty")
{
    std::map<int, hstring> myStdMap;
    IMap<int, hstring> obj = winrt::make<winrt::impl::map<int, hstring, std::map<int, hstring>>>(std::move(myStdMap));
    IMapView<int, hstring> view = obj.GetView();
    IIterator<IKeyValuePair<int, hstring>> itor = view.First();

    REQUIRE_THROWS_AS(itor.Current(), winrt::hresult_out_of_bounds);
}

TEST_CASE("IMap IIterator, from IMapView created from IMap, HasCurrent, true")
{
    std::map<int, hstring> myStdMap { std::pair<int, hstring> { 1, L"value1"}, std::pair<int, hstring> { 2, L"value2"} };
    IMap<int, hstring> obj = winrt::make<winrt::impl::map<int, hstring, std::map<int, hstring>>>(std::move(myStdMap));
    IMapView<int, hstring> view = obj.GetView();
    IIterator<IKeyValuePair<int, hstring>> itor = view.First();

    REQUIRE(itor.HasCurrent());
}

TEST_CASE("IMap IIterator, from IMapView created from IMap, HasCurrent, false")
{
    std::map<int, hstring> myStdMap;
    IMap<int, hstring> obj = winrt::make<winrt::impl::map<int, hstring, std::map<int, hstring>>>(std::move(myStdMap));
    IMapView<int, hstring> view = obj.GetView();
    IIterator<IKeyValuePair<int, hstring>> itor = view.First();

    REQUIRE_FALSE(itor.HasCurrent());
}

TEST_CASE("IMap IIterator, from IMapView created from IMap, MoveNext")
{
    std::map<int, hstring> myStdMap { std::pair<int, hstring> { 1, L"value1"}, std::pair<int, hstring> { 2, L"value2"} };
    IMap<int, hstring> obj = winrt::make<winrt::impl::map<int, hstring, std::map<int, hstring>>>(std::move(myStdMap));
    IMapView<int, hstring> view = obj.GetView();
    IIterator<IKeyValuePair<int, hstring>> itor = view.First();

    REQUIRE(itor.HasCurrent());
    REQUIRE(itor.Current().Key() == 1);
    REQUIRE(itor.Current().Value() == L"value1");

    REQUIRE(itor.MoveNext());
    REQUIRE(itor.HasCurrent());
    REQUIRE(itor.Current().Key() == 2);
    REQUIRE(itor.Current().Value() == L"value2");

    REQUIRE_FALSE(itor.MoveNext());
    REQUIRE_FALSE(itor.HasCurrent());
}

TEST_CASE("IMap IIterator, from IMapView created from IMap, GetMany, output array has less size than the iterator")
{
    std::map<int, hstring> myStdMap { std::pair<int, hstring> { 1, L"value1"}, std::pair<int, hstring> { 2, L"value2"} };
    IMap<int, hstring> obj = winrt::make<winrt::impl::map<int, hstring, std::map<int, hstring>>>(std::move(myStdMap));
    IMapView<int, hstring> view = obj.GetView();
    IIterator<IKeyValuePair<int, hstring>> itor = view.First();
    std::array<IKeyValuePair<int, hstring>, 1> output;

    REQUIRE(itor.GetMany(output) == 1);
    REQUIRE(output.size() == 1);
    REQUIRE(output.at(0).Key() == 1);
    REQUIRE(output.at(0).Value() == L"value1");
}

TEST_CASE("IMap IIterator, from IMapView created from IMap, GetMany, output array has the same number of elements")
{
    std::map<int, hstring> myStdMap { std::pair<int, hstring> { 1, L"value1"}, std::pair<int, hstring> { 2, L"value2"} };
    IMap<int, hstring> obj = winrt::make<winrt::impl::map<int, hstring, std::map<int, hstring>>>(std::move(myStdMap));
    IMapView<int, hstring> view = obj.GetView();
    IIterator<IKeyValuePair<int, hstring>> itor = view.First();
    std::array<IKeyValuePair<int, hstring>, 2> output;

    REQUIRE(itor.GetMany(output) == 2);
    REQUIRE(output.size() == 2);
    REQUIRE(output.at(0).Key() == 1);
    REQUIRE(output.at(0).Value() == L"value1");
    REQUIRE(output.at(1).Key() == 2);
    REQUIRE(output.at(1).Value() == L"value2");
}

TEST_CASE("IMap IIterator, from IMapView created from IMap, GetMany, output array has more slots than the iterator")
{
    std::map<int, hstring> myStdMap { std::pair<int, hstring> { 1, L"value1"}, std::pair<int, hstring> { 2, L"value2"} };
    IMap<int, hstring> obj = winrt::make<winrt::impl::map<int, hstring, std::map<int, hstring>>>(std::move(myStdMap));
    IMapView<int, hstring> view = obj.GetView();
    IIterator<IKeyValuePair<int, hstring>> itor = view.First();
    std::array<IKeyValuePair<int, hstring>, 3> output;

    REQUIRE(itor.GetMany(output) == 2);
    REQUIRE(output.size() == 3);
    REQUIRE(output.at(0).Key() == 1);
    REQUIRE(output.at(0).Value() == L"value1");
    REQUIRE(output.at(1).Key() == 2);
    REQUIRE(output.at(1).Value() == L"value2");
}

#pragma endregion

#pragma region "Tests, IMap IIterator, from IMapView standalone"

TEST_CASE("IMap IIterator, from IMapView standalone, Current, current has value")
{
    std::unordered_map<int, hstring> myStdMap { std::pair<int, hstring> { 1, L"value1"}, std::pair<int, hstring> { 2, L"value2"} };
    IMapView<int, hstring> view = winrt::make<winrt::impl::map_view_standalone<int, hstring, std::unordered_map<int, hstring>>>(std::move(myStdMap));
    IIterator<IKeyValuePair<int, hstring>> itor = view.First();

    REQUIRE(itor.Current());
}

TEST_CASE("IMap IIterator, from IMapView standalone, Current, throws when empty")
{
    std::unordered_map<int, hstring> myStdMap;
    IMapView<int, hstring> view = winrt::make<winrt::impl::map_view_standalone<int, hstring, std::unordered_map<int, hstring>>>(std::move(myStdMap));
    IIterator<IKeyValuePair<int, hstring>> itor = view.First();

    REQUIRE_THROWS_AS(itor.Current(), winrt::hresult_out_of_bounds);
}

TEST_CASE("IMap IIterator, from IMapView standalone, HasCurrent, true")
{
    std::unordered_map<int, hstring> myStdMap { std::pair<int, hstring> { 1, L"value1"}, std::pair<int, hstring> { 2, L"value2"} };
    IMapView<int, hstring> view = winrt::make<winrt::impl::map_view_standalone<int, hstring, std::unordered_map<int, hstring>>>(std::move(myStdMap));
    IIterator<IKeyValuePair<int, hstring>> itor = view.First();

    REQUIRE(itor.HasCurrent());
}

TEST_CASE("IMap IIterator, from IMapView standalone, HasCurrent, false")
{
    std::unordered_map<int, hstring> myStdMap;
    IMapView<int, hstring> view = winrt::make<winrt::impl::map_view_standalone<int, hstring, std::unordered_map<int, hstring>>>(std::move(myStdMap));
    IIterator<IKeyValuePair<int, hstring>> itor = view.First();

    REQUIRE_FALSE(itor.HasCurrent());
}

TEST_CASE("IMap IIterator, from IMapView standalone, MoveNext")
{
    std::unordered_map<int, hstring> myStdMap { std::pair<int, hstring> { 1, L"value1"}, std::pair<int, hstring> { 2, L"value2"} };
    IMapView<int, hstring> view = winrt::make<winrt::impl::map_view_standalone<int, hstring, std::unordered_map<int, hstring>>>(std::move(myStdMap));
    IIterator<IKeyValuePair<int, hstring>> itor = view.First();

    REQUIRE(itor.HasCurrent());
    REQUIRE(itor.Current().Key() == 1);
    REQUIRE(itor.Current().Value() == L"value1");

    REQUIRE(itor.MoveNext());
    REQUIRE(itor.HasCurrent());
    REQUIRE(itor.Current().Key() == 2);
    REQUIRE(itor.Current().Value() == L"value2");

    REQUIRE_FALSE(itor.MoveNext());
    REQUIRE_FALSE(itor.HasCurrent());
}

TEST_CASE("IMap IIterator, from IMapView standalone, GetMany, output array has less size than the iterator")
{
    std::unordered_map<int, hstring> myStdMap { std::pair<int, hstring> { 1, L"value1"}, std::pair<int, hstring> { 2, L"value2"} };
    IMapView<int, hstring> view = winrt::make<winrt::impl::map_view_standalone<int, hstring, std::unordered_map<int, hstring>>>(std::move(myStdMap));
    IIterator<IKeyValuePair<int, hstring>> itor = view.First();
    std::array<IKeyValuePair<int, hstring>, 1> output;

    REQUIRE(itor.GetMany(output) == 1);
    REQUIRE(output.size() == 1);
    REQUIRE(output.at(0).Key() == 1);
    REQUIRE(output.at(0).Value() == L"value1");
}

TEST_CASE("IMap IIterator, from IMapView standalone, GetMany, output array has the same number of elements")
{
    std::unordered_map<int, hstring> myStdMap { std::pair<int, hstring> { 1, L"value1"}, std::pair<int, hstring> { 2, L"value2"} };
    IMapView<int, hstring> view = winrt::make<winrt::impl::map_view_standalone<int, hstring, std::unordered_map<int, hstring>>>(std::move(myStdMap));
    IIterator<IKeyValuePair<int, hstring>> itor = view.First();
    std::array<IKeyValuePair<int, hstring>, 2> output;

    REQUIRE(itor.GetMany(output) == 2);
    REQUIRE(output.size() == 2);
    REQUIRE(output.at(0).Key() == 1);
    REQUIRE(output.at(0).Value() == L"value1");
    REQUIRE(output.at(1).Key() == 2);
    REQUIRE(output.at(1).Value() == L"value2");
}

TEST_CASE("IMap IIterator, from IMapView standalone, GetMany, output array has more slots than the iterator")
{
    std::unordered_map<int, hstring> myStdMap { std::pair<int, hstring> { 1, L"value1"}, std::pair<int, hstring> { 2, L"value2"} };
    IMapView<int, hstring> view = winrt::make<winrt::impl::map_view_standalone<int, hstring, std::unordered_map<int, hstring>>>(std::move(myStdMap));
    IIterator<IKeyValuePair<int, hstring>> itor = view.First();
    std::array<IKeyValuePair<int, hstring>, 3> output;

    REQUIRE(itor.GetMany(output) == 2);
    REQUIRE(output.size() == 3);
    REQUIRE(output.at(0).Key() == 1);
    REQUIRE(output.at(0).Value() == L"value1");
    REQUIRE(output.at(1).Key() == 2);
    REQUIRE(output.at(1).Value() == L"value2");
}

#pragma endregion

#pragma region "Tests, IMap IIterator, from IIterable standalone"

TEST_CASE("IMap IIterator, from IIterable standalone, Current, current has value")
{
    std::map<int, hstring> myStdMap { std::pair<int, hstring> { 1, L"value1"}, std::pair<int, hstring> { 2, L"value2"} };
    IIterable<IKeyValuePair<int, hstring>> view = winrt::make<winrt::impl::iterable<IKeyValuePair<int, hstring>, std::map<int, hstring>>>(std::move(myStdMap));
    IIterator<IKeyValuePair<int, hstring>> itor = view.First();

    REQUIRE(itor.Current());
}

TEST_CASE("IMap IIterator, from IIterable standalone, Current, throws when empty")
{
    std::map<int, hstring> myStdMap;
    IIterable<IKeyValuePair<int, hstring>> view = winrt::make<winrt::impl::iterable<IKeyValuePair<int, hstring>, std::map<int, hstring>>>(std::move(myStdMap));
    IIterator<IKeyValuePair<int, hstring>> itor = view.First();

    REQUIRE_THROWS_AS(itor.Current(), winrt::hresult_out_of_bounds);
}

TEST_CASE("IMap IIterator, from IIterable standalone, HasCurrent, true")
{
    std::map<int, hstring> myStdMap { std::pair<int, hstring> { 1, L"value1"}, std::pair<int, hstring> { 2, L"value2"} };
    IIterable<IKeyValuePair<int, hstring>> view = winrt::make<winrt::impl::iterable<IKeyValuePair<int, hstring>, std::map<int, hstring>>>(std::move(myStdMap));
    IIterator<IKeyValuePair<int, hstring>> itor = view.First();

    REQUIRE(itor.HasCurrent());
}

TEST_CASE("IMap IIterator, from IIterable standalone, HasCurrent, false")
{
    std::map<int, hstring> myStdMap;
    IIterable<IKeyValuePair<int, hstring>> view = winrt::make<winrt::impl::iterable<IKeyValuePair<int, hstring>, std::map<int, hstring>>>(std::move(myStdMap));
    IIterator<IKeyValuePair<int, hstring>> itor = view.First();

    REQUIRE_FALSE(itor.HasCurrent());
}

TEST_CASE("IMap IIterator, from IIterable standalone, MoveNext")
{
    std::map<int, hstring> myStdMap { std::pair<int, hstring> { 1, L"value1"}, std::pair<int, hstring> { 2, L"value2"} };
    IIterable<IKeyValuePair<int, hstring>> view = winrt::make<winrt::impl::iterable<IKeyValuePair<int, hstring>, std::map<int, hstring>>>(std::move(myStdMap));
    IIterator<IKeyValuePair<int, hstring>> itor = view.First();

    REQUIRE(itor.HasCurrent());
    REQUIRE(itor.Current().Key() == 1);
    REQUIRE(itor.Current().Value() == L"value1");

    REQUIRE(itor.MoveNext());
    REQUIRE(itor.HasCurrent());
    REQUIRE(itor.Current().Key() == 2);
    REQUIRE(itor.Current().Value() == L"value2");

    REQUIRE_FALSE(itor.MoveNext());
    REQUIRE_FALSE(itor.HasCurrent());
}

TEST_CASE("IMap IIterator, from IIterable standalone, GetMany, output array has less size than the iterator")
{
    std::map<int, hstring> myStdMap { std::pair<int, hstring> { 1, L"value1"}, std::pair<int, hstring> { 2, L"value2"} };
    IIterable<IKeyValuePair<int, hstring>> view = winrt::make<winrt::impl::iterable<IKeyValuePair<int, hstring>, std::map<int, hstring>>>(std::move(myStdMap));
    IIterator<IKeyValuePair<int, hstring>> itor = view.First();
    std::array<IKeyValuePair<int, hstring>, 1> output;

    REQUIRE(itor.GetMany(output) == 1);
    REQUIRE(output.size() == 1);
    REQUIRE(output.at(0).Key() == 1);
    REQUIRE(output.at(0).Value() == L"value1");
}

TEST_CASE("IMap IIterator, from IIterable standalone, GetMany, output array has the same number of elements")
{
    std::map<int, hstring> myStdMap { std::pair<int, hstring> { 1, L"value1"}, std::pair<int, hstring> { 2, L"value2"} };
    IIterable<IKeyValuePair<int, hstring>> view = winrt::make<winrt::impl::iterable<IKeyValuePair<int, hstring>, std::map<int, hstring>>>(std::move(myStdMap));
    IIterator<IKeyValuePair<int, hstring>> itor = view.First();
    std::array<IKeyValuePair<int, hstring>, 2> output;

    REQUIRE(itor.GetMany(output) == 2);
    REQUIRE(output.size() == 2);
    REQUIRE(output.at(0).Key() == 1);
    REQUIRE(output.at(0).Value() == L"value1");
    REQUIRE(output.at(1).Key() == 2);
    REQUIRE(output.at(1).Value() == L"value2");
}

TEST_CASE("IMap IIterator, from IIterable standalone, GetMany, output array has more slots than the iterator")
{
    std::map<int, hstring> myStdMap { std::pair<int, hstring> { 1, L"value1"}, std::pair<int, hstring> { 2, L"value2"} };
    IIterable<IKeyValuePair<int, hstring>> view = winrt::make<winrt::impl::iterable<IKeyValuePair<int, hstring>, std::map<int, hstring>>>(std::move(myStdMap));
    IIterator<IKeyValuePair<int, hstring>> itor = view.First();
    std::array<IKeyValuePair<int, hstring>, 3> output;

    REQUIRE(itor.GetMany(output) == 2);
    REQUIRE(output.size() == 3);
    REQUIRE(output.at(0).Key() == 1);
    REQUIRE(output.at(0).Value() == L"value1");
    REQUIRE(output.at(1).Key() == 2);
    REQUIRE(output.at(1).Value() == L"value2");
}

#pragma endregion

#pragma region "Tests IMap IMapView from IMap, invalidate"

TEST_CASE("IMap IMapView, from map, invalidate, HasKey")
{
    std::map<int, hstring> myStdMap { std::pair<int, hstring> { 1, L"value1"}, std::pair<int, hstring> { 2, L"value2"} };
    IMap<int, hstring> obj = winrt::make<winrt::impl::map<int, hstring, std::map<int, hstring>>>(std::move(myStdMap));
    IMapView<int, hstring> view = obj.GetView();

    REQUIRE(view.Size() == 2);
    obj.Clear();
    REQUIRE_THROWS_AS(view.HasKey(1), hresult_changed_state);
}

TEST_CASE("IMap IMapView, from map, invalidate, Lookup")
{
    std::map<int, hstring> myStdMap { std::pair<int, hstring> { 1, L"value1"}, std::pair<int, hstring> { 2, L"value2"} };
    IMap<int, hstring> obj = winrt::make<winrt::impl::map<int, hstring, std::map<int, hstring>>>(std::move(myStdMap));
    IMapView<int, hstring> view = obj.GetView();

    REQUIRE(view.Size() == 2);
    obj.Clear();
    REQUIRE_THROWS_AS(view.Lookup(1), hresult_changed_state);
}

TEST_CASE("IMap IMapView, from map, invalidate, Split")
{
    std::map<int, hstring> myStdMap { std::pair<int, hstring> { 1, L"value1"}, std::pair<int, hstring> { 2, L"value2"} };
    IMap<int, hstring> obj = winrt::make<winrt::impl::map<int, hstring, std::map<int, hstring>>>(std::move(myStdMap));
    IMapView<int, hstring> view = obj.GetView();
    IMapView<int, hstring> left;
    IMapView<int, hstring> right;

    REQUIRE(view.Size() == 2);
    obj.Clear();
    REQUIRE_THROWS_AS(view.Split(left, right), hresult_changed_state);
}

TEST_CASE("IMap IMapView, from map, invalidate, Size")
{
    std::map<int, hstring> myStdMap { std::pair<int, hstring> { 1, L"value1"}, std::pair<int, hstring> { 2, L"value2"} };
    IMap<int, hstring> obj = winrt::make<winrt::impl::map<int, hstring, std::map<int, hstring>>>(std::move(myStdMap));
    IMapView<int, hstring> view = obj.GetView();

    REQUIRE(view.Size() == 2);
    obj.Clear();
    REQUIRE_THROWS_AS(view.Size(), hresult_changed_state);
}

#pragma endregion

#pragma region "Tests, IMap IIterator, from IMap, invalidate"

TEST_CASE("IMap IIterator, from IMap, invalidate, Current")
{
    std::map<int, hstring> myStdMap { std::pair<int, hstring> { 1, L"value1"}, std::pair<int, hstring> { 2, L"value2"} };
    IMap<int, hstring> obj = winrt::make<winrt::impl::map<int, hstring, std::map<int, hstring>>>(std::move(myStdMap));
    IIterator<IKeyValuePair<int, hstring>> itor = obj.First();

    obj.Clear();
    REQUIRE_THROWS_AS(itor.Current(), winrt::hresult_changed_state);
}

TEST_CASE("IMap IIterator, from IMap, invalidate, HasCurrent")
{
    std::map<int, hstring> myStdMap { std::pair<int, hstring> { 1, L"value1"}, std::pair<int, hstring> { 2, L"value2"} };
    IMap<int, hstring> obj = winrt::make<winrt::impl::map<int, hstring, std::map<int, hstring>>>(std::move(myStdMap));
    IIterator<IKeyValuePair<int, hstring>> itor = obj.First();

    obj.Clear();
    REQUIRE_THROWS_AS(itor.HasCurrent(), winrt::hresult_changed_state);
}

TEST_CASE("IMap IIterator, from IMap, invalidate, MoveNext")
{
    std::map<int, hstring> myStdMap { std::pair<int, hstring> { 1, L"value1"}, std::pair<int, hstring> { 2, L"value2"} };
    IMap<int, hstring> obj = winrt::make<winrt::impl::map<int, hstring, std::map<int, hstring>>>(std::move(myStdMap));
    IIterator<IKeyValuePair<int, hstring>> itor = obj.First();

    obj.Clear();
    REQUIRE_THROWS_AS(itor.MoveNext(), winrt::hresult_changed_state);
}

TEST_CASE("IMap IIterator, from IMap, invalidate, GetMany")
{
    std::map<int, hstring> myStdMap { std::pair<int, hstring> { 1, L"value1"}, std::pair<int, hstring> { 2, L"value2"} };
    IMap<int, hstring> obj = winrt::make<winrt::impl::map<int, hstring, std::map<int, hstring>>>(std::move(myStdMap));
    IIterator<IKeyValuePair<int, hstring>> itor = obj.First();
    std::array<IKeyValuePair<int, hstring>, 2> output;

    obj.Clear();
    REQUIRE_THROWS_AS(itor.GetMany(output), winrt::hresult_changed_state);
}

#pragma endregion

#pragma region "Tests, calling a function with an IMap"

void FunctionThatTakesAnIMap(IMap<int, hstring> map)
{
    REQUIRE(map.Size() == 2);
    REQUIRE(map.HasKey(1));
    REQUIRE(map.HasKey(2));
    REQUIRE(map.Lookup(1) == L"value1");
    REQUIRE(map.Lookup(2) == L"value2");
}

TEST_CASE("IMap, projected type, call function, rvalue")
{
    std::map<int, hstring> myStdMap { std::pair<int, hstring> { 1, L"value1"}, std::pair<int, hstring> { 2, L"value2"} };
    
    FunctionThatTakesAnIMap(std::move(myStdMap));
}

TEST_CASE("IMap, projected type, call function, il")
{
    FunctionThatTakesAnIMap({ std::pair<int, hstring> { 1, L"value1"}, std::pair<int, hstring> { 2, L"value2"} });
}

#pragma endregion

#pragma region "Tests, calling a function with an IMapView"

void FunctionThatTakesAnIMapView(IMapView<int, hstring> view)
{
    REQUIRE(view.Size() == 2);
    REQUIRE(view.HasKey(1));
    REQUIRE(view.HasKey(2));
    REQUIRE(view.Lookup(1) == L"value1");
    REQUIRE(view.Lookup(2) == L"value2");
}

TEST_CASE("IMapView, projected type, call function, rvalue")
{
    std::map<int, hstring> myStdMap { std::pair<int, hstring> { 1, L"value1"}, std::pair<int, hstring> { 2, L"value2"} };
    
    FunctionThatTakesAnIMapView(std::move(myStdMap));
}

TEST_CASE("IMapView, projected type, call function, il")
{
    FunctionThatTakesAnIMapView({ std::pair<int, hstring> { 1, L"value1"}, std::pair<int, hstring> { 2, L"value2"} });
}

#pragma endregion

#pragma region "Tests, calling a function with an IIterable<IKeyValue<K, V>>"

void FunctionThatTakesAnIIterable(IIterable<IKeyValuePair<int, hstring>> iter)
{
    IIterator<IKeyValuePair<int, hstring>> itor = iter.First();
    REQUIRE(itor.HasCurrent());
    REQUIRE(itor.Current().Key() == 1);
    REQUIRE(itor.Current().Value() == L"value1");
    REQUIRE(itor.MoveNext());
    REQUIRE(itor.HasCurrent());
    REQUIRE(itor.Current().Key() == 2);
    REQUIRE(itor.Current().Value() == L"value2");
}

TEST_CASE("IIterable<KeyValuePair<K, V>>, projected type, call function, rvalue")
{
    std::map<int, hstring> myStdMap { std::pair<int, hstring> { 1, L"value1"}, std::pair<int, hstring> { 2, L"value2"} };
    
    FunctionThatTakesAnIIterable(std::move(myStdMap));
}

TEST_CASE("IIterable<KeyValuePair<K, V>>, projected type, call function, il")
{
    FunctionThatTakesAnIIterable({ std::pair<int, hstring> { 1, L"value1"}, std::pair<int, hstring> { 2, L"value2"} });
}

#pragma endregion

#pragma region "Tests, IMap, create on return of the function"

IMap<int, hstring> GetIMapFromRValueWithValues()
{
    std::map<int, hstring> myStdMap { std::pair<int, hstring> { 1, L"value1"}, std::pair<int, hstring> { 2, L"value2"} };

    return std::move(myStdMap);
}

TEST_CASE(" IMap, create on return of the function, rvalue, with values")
{
    IMap<int, hstring> obj = GetIMapFromRValueWithValues();

    REQUIRE(obj.Size() == 2);
    REQUIRE(obj.HasKey(1));
    REQUIRE(obj.HasKey(2));
    REQUIRE(obj.Lookup(1) == L"value1");
    REQUIRE(obj.Lookup(2) == L"value2");
}

IMap<int, hstring> GetIMapFromRValueNoValues()
{
    std::map<int, hstring> myStdMap;

    return std::move(myStdMap);
}

TEST_CASE(" IMap, create on return of the function, rvalue, no values")
{
    IMap<int, hstring> obj = GetIMapFromRValueNoValues();

    REQUIRE(obj.Size() == 0);
    REQUIRE_FALSE(obj.HasKey(1));
}

#pragma endregion

#pragma region "Tests, IMap, creating projected type"

TEST_CASE("IMap, creating projected type, r-value std::map, with elements")
{
    std::map<int, hstring> myStdMap { std::pair<int, hstring> { 1, L"value1"}, std::pair<int, hstring> { 2, L"value2"} };
    IMap<int, hstring> obj(std::move(myStdMap));

    REQUIRE(obj != nullptr);
    REQUIRE(obj.Size() == 2);
    REQUIRE(obj.HasKey(1));
    REQUIRE(obj.Lookup(1) == L"value1");
    REQUIRE(obj.HasKey(2));
    REQUIRE(obj.Lookup(2) == L"value2");
}

TEST_CASE("IMap, creating projected type, r-value std::unordered_map, with elements")
{
    std::unordered_map<int, hstring> myStdMap { std::pair<int, hstring> { 1, L"value1"}, std::pair<int, hstring> { 2, L"value2"} };
    IMap<int, hstring> obj(std::move(myStdMap));

    REQUIRE(obj != nullptr);
    REQUIRE(obj.Size() == 2);
    REQUIRE(obj.HasKey(1));
    REQUIRE(obj.Lookup(1) == L"value1");
    REQUIRE(obj.HasKey(2));
    REQUIRE(obj.Lookup(2) == L"value2");
}

TEST_CASE("IMap, creating projected type, r-value, no elements")
{
    std::map<int, hstring> myStdMap;
    IMap<int, hstring> obj(std::move(myStdMap));

    REQUIRE(obj != nullptr);
    REQUIRE(obj.Size() == 0);
    REQUIRE_FALSE(obj.HasKey(1));
}

TEST_CASE("IMap, creating projected type, iterators, with elements")
{
    std::map<int, hstring> myStdMap { std::pair<int, hstring> { 1, L"value1"}, std::pair<int, hstring> { 2, L"value2"} };
    IMap<int, hstring> obj(myStdMap.begin(), myStdMap.end());

    REQUIRE(obj != nullptr);
    REQUIRE(obj.Size() == 2);
    REQUIRE(obj.HasKey(1));
    REQUIRE(obj.Lookup(1) == L"value1");
    REQUIRE(obj.HasKey(2));
    REQUIRE(obj.Lookup(2) == L"value2");
}

TEST_CASE("IMap, creating projected type, iterators, no elements")
{
    std::map<int, hstring> myStdMap;
    IMap<int, hstring> obj(myStdMap.begin(), myStdMap.end());

    REQUIRE(obj != nullptr);
    REQUIRE(obj.Size() == 0);
    REQUIRE_FALSE(obj.HasKey(1));
}

TEST_CASE("IMap, creating projected type, il, with elements")
{
    IMap<int, hstring> obj({ std::pair<int, hstring> { 1, L"value1"}, std::pair<int, hstring> { 2, L"value2"} });

    REQUIRE(obj != nullptr);
    REQUIRE(obj.Size() == 2);
    REQUIRE(obj.HasKey(1));
    REQUIRE(obj.Lookup(1) == L"value1");
    REQUIRE(obj.HasKey(2));
    REQUIRE(obj.Lookup(2) == L"value2");
}

TEST_CASE("IMap, creating projected type, il, no elements")
{
    IMap<int, hstring> obj({});

    REQUIRE(obj != nullptr);
    REQUIRE(obj.Size() == 0);
    REQUIRE_FALSE(obj.HasKey(1));
}

#pragma endregion

#pragma region "Tests, IMapView, creating projected type"

TEST_CASE("IMapView, creating projected type, r-value std::map, with elements")
{
    std::map<int, hstring> myStdMap { std::pair<int, hstring> { 1, L"value1"}, std::pair<int, hstring> { 2, L"value2"} };
    IMapView<int, hstring> view(std::move(myStdMap));

    REQUIRE(view != nullptr);
    REQUIRE(view.Size() == 2);
    REQUIRE(view.HasKey(1));
    REQUIRE(view.Lookup(1) == L"value1");
    REQUIRE(view.HasKey(2));
    REQUIRE(view.Lookup(2) == L"value2");
}

TEST_CASE("IMapView, creating projected type, r-value std::unordered_map, with elements")
{
    std::unordered_map<int, hstring> myStdMap { std::pair<int, hstring> { 1, L"value1"}, std::pair<int, hstring> { 2, L"value2"} };
    IMapView<int, hstring> view(std::move(myStdMap));

    REQUIRE(view != nullptr);
    REQUIRE(view.Size() == 2);
    REQUIRE(view.HasKey(1));
    REQUIRE(view.Lookup(1) == L"value1");
    REQUIRE(view.HasKey(2));
    REQUIRE(view.Lookup(2) == L"value2");
}

TEST_CASE("IMapView, creating projected type, r-value, no elements")
{
    std::map<int, hstring> myStdMap;
    IMapView<int, hstring> view(std::move(myStdMap));

    REQUIRE(view != nullptr);
    REQUIRE(view.Size() == 0);
    REQUIRE_FALSE(view.HasKey(1));
}

TEST_CASE("IMapView, creating projected type, iterators, with elements")
{
    std::map<int, hstring> myStdMap { std::pair<int, hstring> { 1, L"value1"}, std::pair<int, hstring> { 2, L"value2"} };
    IMapView<int, hstring> view(myStdMap.begin(), myStdMap.end());

    REQUIRE(view != nullptr);
    REQUIRE(view.Size() == 2);
    REQUIRE(view.HasKey(1));
    REQUIRE(view.Lookup(1) == L"value1");
    REQUIRE(view.HasKey(2));
    REQUIRE(view.Lookup(2) == L"value2");
}

TEST_CASE("IMapView, creating projected type, iterators, no elements")
{
    std::map<int, hstring> myStdMap;
    IMapView<int, hstring> view(myStdMap.begin(), myStdMap.end());

    REQUIRE(view != nullptr);
    REQUIRE(view.Size() == 0);
    REQUIRE_FALSE(view.HasKey(1));
}

TEST_CASE("IMapView, creating projected type, il, with elements")
{
    IMapView<int, hstring> view({ std::pair<int, hstring> { 1, L"value1"}, std::pair<int, hstring> { 2, L"value2"} });

    REQUIRE(view != nullptr);
    REQUIRE(view.Size() == 2);
    REQUIRE(view.HasKey(1));
    REQUIRE(view.Lookup(1) == L"value1");
    REQUIRE(view.HasKey(2));
    REQUIRE(view.Lookup(2) == L"value2");
}

TEST_CASE("IMapView, creating projected type, il, no elements")
{
    IMapView<int, hstring> view({});

    REQUIRE(view != nullptr);
    REQUIRE(view.Size() == 0);
    REQUIRE_FALSE(view.HasKey(1));
}

#pragma endregion

#pragma region "Tests, IIterable<IKeyValuePair<K, V>>, creating projected type"

TEST_CASE("IIterable<IKeyValuePair<K, V>>, creating projected type, r-value std::map, with elements")
{
    std::map<int, hstring> myStdMap { std::pair<int, hstring> { 1, L"value1"}, std::pair<int, hstring> { 2, L"value2"} };
    IIterable<IKeyValuePair<int, hstring>> iter(std::move(myStdMap));
    IIterator<IKeyValuePair<int, hstring>> itor = iter.First();

    REQUIRE(iter != nullptr);
    REQUIRE(itor != nullptr);
    REQUIRE(itor.HasCurrent());
    REQUIRE(itor.Current().Key() == 1);
    REQUIRE(itor.Current().Value() == L"value1");
    REQUIRE(itor.MoveNext());
    REQUIRE(itor.HasCurrent());
    REQUIRE(itor.Current().Key() == 2);
    REQUIRE(itor.Current().Value() == L"value2");
}

TEST_CASE("IIterable<IKeyValuePair<K, V>>, creating projected type, r-value std::unordered_map, with elements")
{
    std::unordered_map<int, hstring> myStdMap { std::pair<int, hstring> { 1, L"value1"}, std::pair<int, hstring> { 2, L"value2"} };
    IIterable<IKeyValuePair<int, hstring>> iter(std::move(myStdMap));
    IIterator<IKeyValuePair<int, hstring>> itor = iter.First();

    REQUIRE(iter != nullptr);
    REQUIRE(itor != nullptr);
    REQUIRE(itor.HasCurrent());
    REQUIRE(itor.Current().Key() == 1);
    REQUIRE(itor.Current().Value() == L"value1");
    REQUIRE(itor.MoveNext());
    REQUIRE(itor.HasCurrent());
    REQUIRE(itor.Current().Key() == 2);
    REQUIRE(itor.Current().Value() == L"value2");
}

TEST_CASE("IIterable<IKeyValuePair<K, V>>, creating projected type, r-value, no elements")
{
    std::map<int, hstring> myStdMap;
    IIterable<IKeyValuePair<int, hstring>> iter(std::move(myStdMap));
    IIterator<IKeyValuePair<int, hstring>> itor = iter.First();

    REQUIRE(iter != nullptr);
    REQUIRE(itor != nullptr);
    REQUIRE_FALSE(itor.HasCurrent());
}

TEST_CASE("IIterable<IKeyValuePair<K, V>>, creating projected type, iterators, with elements")
{
    std::map<int, hstring> myStdMap { std::pair<int, hstring> { 1, L"value1"}, std::pair<int, hstring> { 2, L"value2"} };
    IIterable<IKeyValuePair<int, hstring>> iter(myStdMap.begin(), myStdMap.end());
    IIterator<IKeyValuePair<int, hstring>> itor = iter.First();

    REQUIRE(iter != nullptr);
    REQUIRE(itor != nullptr);
    REQUIRE(itor.HasCurrent());
    REQUIRE(itor.Current().Key() == 1);
    REQUIRE(itor.Current().Value() == L"value1");
    REQUIRE(itor.MoveNext());
    REQUIRE(itor.HasCurrent());
    REQUIRE(itor.Current().Key() == 2);
    REQUIRE(itor.Current().Value() == L"value2");
}

TEST_CASE("IIterable<IKeyValuePair<K, V>>, creating projected type, iterators, no elements")
{
    std::map<int, hstring> myStdMap;
    IIterable<IKeyValuePair<int, hstring>> iter(myStdMap.begin(), myStdMap.end());
    IIterator<IKeyValuePair<int, hstring>> itor = iter.First();

    REQUIRE(iter != nullptr);
    REQUIRE(itor != nullptr);
    REQUIRE_FALSE(itor.HasCurrent());
}

TEST_CASE("IIterable<IKeyValuePair<K, V>>, creating projected type, il, with elements")
{
    IIterable<IKeyValuePair<int, hstring>> iter({ std::pair<int, hstring> { 1, L"value1"}, std::pair<int, hstring> { 2, L"value2"} });
    IIterator<IKeyValuePair<int, hstring>> itor = iter.First();

    REQUIRE(iter != nullptr);
    REQUIRE(itor != nullptr);
    REQUIRE(itor.HasCurrent());
    REQUIRE(itor.Current().Key() == 1);
    REQUIRE(itor.Current().Value() == L"value1");
    REQUIRE(itor.MoveNext());
    REQUIRE(itor.HasCurrent());
    REQUIRE(itor.Current().Key() == 2);
    REQUIRE(itor.Current().Value() == L"value2");
}

TEST_CASE("IIterable<IKeyValuePair<K, V>>, creating projected type, il, no elements")
{
    IIterable<IKeyValuePair<int, hstring>> iter({});
    IIterator<IKeyValuePair<int, hstring>> itor = iter.First();

    REQUIRE(iter != nullptr);
    REQUIRE(itor != nullptr);
    REQUIRE_FALSE(itor.HasCurrent());
}

#pragma endregion

#pragma region "Tests, IMap, equal operator"

TEST_CASE("IMap, equal operator, rvalue, with elements")
{
    std::map<int, hstring> myStdMap { std::pair<int, hstring> { 1, L"value1"}, std::pair<int, hstring> { 2, L"value2"} };
    IMap<int, hstring> obj = std::move(myStdMap);

    REQUIRE(obj != nullptr);
    REQUIRE(obj.Size() == 2);
    REQUIRE(obj.HasKey(1));
    REQUIRE(obj.Lookup(1) == L"value1");
    REQUIRE(obj.HasKey(2));
    REQUIRE(obj.Lookup(2) == L"value2");
}

TEST_CASE("IMap, equal operator, r-value, no elements")
{
    std::map<int, hstring> myStdMap;
    IMap<int, hstring> obj = std::move(myStdMap);

    REQUIRE(obj != nullptr);
    REQUIRE(obj.Size() == 0);
    REQUIRE_FALSE(obj.HasKey(1));
}

TEST_CASE("IMap, equal operator, il, with elements")
{
    IMap<int, hstring> obj = { std::pair<int, hstring> { 1, L"value1"}, std::pair<int, hstring> { 2, L"value2"} };

    REQUIRE(obj != nullptr);
    REQUIRE(obj.Size() == 2);
    REQUIRE(obj.HasKey(1));
    REQUIRE(obj.Lookup(1) == L"value1");
    REQUIRE(obj.HasKey(2));
    REQUIRE(obj.Lookup(2) == L"value2");
}

TEST_CASE("IMap, equal operator, il, no elements")
{
    IMap<int, hstring> obj = {};

    REQUIRE(obj == nullptr);
}

#pragma endregion

#pragma region "Tests, IMapView, equal operator"

TEST_CASE("IMapView, equal operator, rvalue, with elements")
{
    std::map<int, hstring> myStdMap { std::pair<int, hstring> { 1, L"value1"}, std::pair<int, hstring> { 2, L"value2"} };
    IMapView<int, hstring> view = std::move(myStdMap);

    REQUIRE(view != nullptr);
    REQUIRE(view.Size() == 2);
    REQUIRE(view.HasKey(1));
    REQUIRE(view.Lookup(1) == L"value1");
    REQUIRE(view.HasKey(2));
    REQUIRE(view.Lookup(2) == L"value2");
}

TEST_CASE("IMapView, equal operator, r-value, no elements")
{
    std::map<int, hstring> myStdMap;
    IMapView<int, hstring> view = std::move(myStdMap);

    REQUIRE(view != nullptr);
    REQUIRE(view.Size() == 0);
    REQUIRE_FALSE(view.HasKey(1));
}

TEST_CASE("IMapView, equal operator, il, with elements")
{
    IMapView<int, hstring> view = { std::pair<int, hstring> { 1, L"value1"}, std::pair<int, hstring> { 2, L"value2"} };

    REQUIRE(view != nullptr);
    REQUIRE(view.Size() == 2);
    REQUIRE(view.HasKey(1));
    REQUIRE(view.Lookup(1) == L"value1");
    REQUIRE(view.HasKey(2));
    REQUIRE(view.Lookup(2) == L"value2");
}

TEST_CASE("IMapView, equal operator, il, no elements")
{
    IMapView<int, hstring> view = {};

    REQUIRE(view == nullptr);
}

#pragma endregion

#pragma region "Tests, IIterable<IKeyValuePair<K, V>>, equal operator"

TEST_CASE("IIterable<IKeyValuePair<K, V>>, equal operator, rvalue, with elements")
{
    std::map<int, hstring> myStdMap { std::pair<int, hstring> { 1, L"value1"}, std::pair<int, hstring> { 2, L"value2"} };
    IIterable<IKeyValuePair<int, hstring>> iter = std::move(myStdMap);
    IIterator<IKeyValuePair<int, hstring>> itor = iter.First();

    REQUIRE(iter != nullptr);
    REQUIRE(itor != nullptr);
    REQUIRE(itor.HasCurrent());
    REQUIRE(itor.Current().Key() == 1);
    REQUIRE(itor.Current().Value() == L"value1");
    REQUIRE(itor.MoveNext());
    REQUIRE(itor.HasCurrent());
    REQUIRE(itor.Current().Key() == 2);
    REQUIRE(itor.Current().Value() == L"value2");
}

TEST_CASE("IIterable<IKeyValuePair<K, V>>, equal operator, r-value, no elements")
{
    std::map<int, hstring> myStdMap;
    IIterable<IKeyValuePair<int, hstring>> iter = std::move(myStdMap);
    IIterator<IKeyValuePair<int, hstring>> itor = iter.First();

    REQUIRE(iter != nullptr);
    REQUIRE(itor != nullptr);
    REQUIRE_FALSE(itor.HasCurrent());
}

TEST_CASE("IIterable<IKeyValuePair<K, V>>, equal operator, il, with elements")
{
    IIterable<IKeyValuePair<int, hstring>> iter = { std::pair<int, hstring> { 1, L"value1"}, std::pair<int, hstring> { 2, L"value2"} };
    IIterator<IKeyValuePair<int, hstring>> itor = iter.First();

    REQUIRE(iter != nullptr);
    REQUIRE(itor != nullptr);
    REQUIRE(itor.HasCurrent());
    REQUIRE(itor.Current().Key() == 1);
    REQUIRE(itor.Current().Value() == L"value1");
    REQUIRE(itor.MoveNext());
    REQUIRE(itor.HasCurrent());
    REQUIRE(itor.Current().Key() == 2);
    REQUIRE(itor.Current().Value() == L"value2");
}

TEST_CASE("IIterable<IKeyValuePair<K, V>>, equal operator, il, no elements")
{
    IIterable<IKeyValuePair<int, hstring>> iter = {};

    REQUIRE(iter == nullptr);
}

#pragma endregion

#pragma region "Tests, IMap, inline il"

TEST_CASE("IMap, inline il, with elements")
{
    IMap<int, hstring> obj { std::pair<int, hstring> { 1, L"value1"}, std::pair<int, hstring> { 2, L"value2"} };

    REQUIRE(obj != nullptr);
    REQUIRE(obj.Size() == 2);
    REQUIRE(obj.HasKey(1));
    REQUIRE(obj.Lookup(1) == L"value1");
    REQUIRE(obj.HasKey(2));
    REQUIRE(obj.Lookup(2) == L"value2");
}

TEST_CASE("IMap, inline il, il, no elements")
{
    IMap<int, hstring> obj {};

    REQUIRE(obj == nullptr);
}

#pragma endregion

#pragma region "Tests, IMapView,inline il"

TEST_CASE("IMapView,inline il, with elements")
{
    IMapView<int, hstring> view { std::pair<int, hstring> { 1, L"value1"}, std::pair<int, hstring> { 2, L"value2"} };

    REQUIRE(view != nullptr);
    REQUIRE(view.Size() == 2);
    REQUIRE(view.HasKey(1));
    REQUIRE(view.Lookup(1) == L"value1");
    REQUIRE(view.HasKey(2));
    REQUIRE(view.Lookup(2) == L"value2");
}

TEST_CASE("IMapView,inline il, il, no elements")
{
    IMapView<int, hstring> view {};

    REQUIRE(view == nullptr);
}

#pragma endregion

#pragma region "Tests, IIterable<IKeyValuePair<K, V>>, inline il"

TEST_CASE("IIterable<IKeyValuePair<K, V>>, inline il, with elements")
{
    IIterable<IKeyValuePair<int, hstring>> iter { std::pair<int, hstring> { 1, L"value1"}, std::pair<int, hstring> { 2, L"value2"} };
    IIterator<IKeyValuePair<int, hstring>> itor = iter.First();

    REQUIRE(iter != nullptr);
    REQUIRE(itor != nullptr);
    REQUIRE(itor.HasCurrent());
    REQUIRE(itor.Current().Key() == 1);
    REQUIRE(itor.Current().Value() == L"value1");
    REQUIRE(itor.MoveNext());
    REQUIRE(itor.HasCurrent());
    REQUIRE(itor.Current().Key() == 2);
    REQUIRE(itor.Current().Value() == L"value2");
}

TEST_CASE("IIterable<IKeyValuePair<K, V>>, inline il, il, no elements")
{
    IIterable<IKeyValuePair<int, hstring>> iter {};

    REQUIRE(iter == nullptr);
}

#pragma endregion
