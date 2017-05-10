#include "pch.h"
#include "catch.hpp"
#include <array>
#include "map.h"

//
// These tests cover the production of the various map-related interfaces.
// Tests ensure that the ABI surface lines up on the consumer and producer sides and this is mainly done simply by calling
// the various inteface methods.
//

using namespace winrt;
using namespace Windows::Foundation;
using namespace Windows::Foundation::Collections;

TEST_CASE("produce_IMapChangedEventArgs")
{
    {
        IMapChangedEventArgs<uint32_t> args = make<impl::MapChangedEventArgs<uint32_t>>(CollectionChange::Reset, 123);
        REQUIRE(args.CollectionChange() == CollectionChange::Reset);
        REQUIRE(args.Key() == 123);
    }

    {
        IMapChangedEventArgs<hstring> args = make<impl::MapChangedEventArgs<hstring>>(CollectionChange::Reset, hstring{ L"value" });
        REQUIRE(args.CollectionChange() == CollectionChange::Reset);
        REQUIRE(args.Key() == L"value");
    }
}

// This producer tests that IMap may be specialized with a value type key and hstring value.

TEST_CASE("produce_IMap_int32_t_hstring")
{
    using Container = std::map<int32_t, hstring>;

    IMap<int32_t, hstring> m = make<impl::Map<Container>>();

    IObservableMap<int32_t, hstring> om = m.as<IObservableMap<int32_t, hstring>>();
    int handlerCount = 0; // Tracks the number of times the handler is called.

    event_token token = om.MapChanged([&](IObservableMap<int32_t, hstring> const & sender, IMapChangedEventArgs<int32_t> const & args)
    {
        ++handlerCount;
        REQUIRE(sender == om);
        REQUIRE(args.CollectionChange() == CollectionChange::ItemInserted);
        REQUIRE(args.Key() == 1);
    });

    REQUIRE(handlerCount == 0);
    REQUIRE(!m.Insert(1, hstring{ L"one" }));
    REQUIRE(handlerCount == 1);

    om.MapChanged(token); // Unregister and thus handlerCount should not increase after this.

    REQUIRE(handlerCount == 1);
    REQUIRE(m.Insert(1, hstring{ L"one" }));
    REQUIRE(handlerCount == 1);

    REQUIRE(handlerCount == 1);
    REQUIRE(!m.Insert(2, hstring{ L"two" }));
    REQUIRE(handlerCount == 1);

    REQUIRE(m.Insert(2, hstring{ L"two" }));

    REQUIRE(m.Lookup(1) == L"one");
    REQUIRE(m.Lookup(2) == L"two");
    REQUIRE_THROWS_AS(m.Lookup(3), hresult_out_of_bounds);

    REQUIRE(m.Size() == 2);

    REQUIRE(m.HasKey(1));
    REQUIRE(!m.HasKey(3));

    IMapView<int32_t, hstring> view = m.GetView();
    const bool same = view.as<IMap<int32_t, hstring>>() == m;
    REQUIRE(same);

    REQUIRE(m.Size() == 2);
    m.Remove(1); // existing
    REQUIRE(m.Size() == 1);
    m.Remove(3); // not existing
    REQUIRE(m.Size() == 1);

    m.Clear();
    REQUIRE(m.Size() == 0);

    IMapView<int32_t, hstring> first;
    IMapView<int32_t, hstring> second;
    view.Split(first, second);
    REQUIRE(first == nullptr);
    REQUIRE(second == nullptr);
}

// This test covers the IMap's specialization of IIterable

TEST_CASE("produce_IMap_IIterable_int32_t_hstring")
{
    using Container = std::map<int32_t, hstring>;

    IMap<int32_t, hstring> m = make<impl::Map<Container>>();
    m.Insert(1, hstring{ L"one" });
    m.Insert(2, hstring{ L"two" });
    m.Insert(3, hstring{ L"three" });

    IIterable<IKeyValuePair<int32_t, hstring>> iterable = m;

    // Both should produce identical iterators but the iterators are unique objects.
    REQUIRE(iterable.First());
    REQUIRE(m.First());
    REQUIRE(iterable.First() != m.First());

    IIterator<IKeyValuePair<int32_t, hstring>> i = m.First();
    REQUIRE((i.Current() == make<impl::KeyValuePair<int32_t, hstring>>(1, hstring{ L"one" })));
    REQUIRE(i.HasCurrent());
    REQUIRE(i.MoveNext());
    REQUIRE((i.Current() == make<impl::KeyValuePair<int32_t, hstring>>(2, hstring{ L"two" })));
    REQUIRE(i.HasCurrent());
    REQUIRE(i.MoveNext());
    REQUIRE((i.Current() == make<impl::KeyValuePair<int32_t, hstring>>(3, hstring{ L"three" })));
    REQUIRE(i.HasCurrent());
    REQUIRE(!i.MoveNext());

    std::array<IKeyValuePair<int32_t, hstring>, 4> many{};
    REQUIRE(0 == i.GetMany(many));

    // Reset iterator
    i = m.First();
    REQUIRE(3 == i.GetMany(many));
    REQUIRE((many[0] == make<impl::KeyValuePair<int32_t, hstring>>(1, hstring{ L"one" })));
    REQUIRE((many[1] == make<impl::KeyValuePair<int32_t, hstring>>(2, hstring{ L"two" })));
    REQUIRE((many[2] == make<impl::KeyValuePair<int32_t, hstring>>(3, hstring{ L"three" })));
    REQUIRE((!many[3]));
}

// This producer tests that IMap may be specialized with an hstring key and int32_t value.

TEST_CASE("produce_IMap_hstring_int32_t")
{
    using Container = std::map<hstring, int32_t>;

    IMap<hstring, int32_t> m = make<impl::Map<Container>>();

    REQUIRE(!m.Insert(hstring{ L"one" }, 1));
    REQUIRE(m.Insert(hstring{ L"one" }, 1));

    REQUIRE(!m.Insert(hstring{ L"two" }, 2));
    REQUIRE(m.Insert(hstring{ L"two" }, 2));

    REQUIRE(m.Lookup(hstring{ L"one" }) == 1);
    REQUIRE(m.Lookup(hstring{ L"two" }) == 2);
    REQUIRE_THROWS_AS(m.Lookup(hstring{ L"three" }), hresult_out_of_bounds);

    REQUIRE(m.Size() == 2);

    REQUIRE(m.HasKey(hstring{ L"one" }));
    REQUIRE(!m.HasKey(hstring{ L"three" }));

    IMapView<hstring, int32_t> view = m.GetView();
    const bool same = view.as<IMap<hstring, int32_t>>() == m;
    REQUIRE(same);

    REQUIRE(m.Size() == 2);
    m.Remove(hstring{ L"one" }); // existing
    REQUIRE(m.Size() == 1);
    m.Remove(hstring{ L"three" }); // not existing
    REQUIRE(m.Size() == 1);

    m.Clear();
    REQUIRE(m.Size() == 0);

    IMapView<hstring, int32_t> first;
    IMapView<hstring, int32_t> second;
    view.Split(first, second);
    REQUIRE(first == nullptr);
    REQUIRE(second == nullptr);
}

// This test covers the IMap's specialization of IIterable

TEST_CASE("produce_IMap_IIterable_hstring_int32_t")
{
    using Container = std::map<hstring, int32_t>;

    IMap<hstring, int32_t> m = make<impl::Map<Container>>();
    m.Insert(hstring{ L"one" }, 1);
    m.Insert(hstring{ L"two" }, 2);
    m.Insert(hstring{ L"three" }, 3);

    IIterable<IKeyValuePair<hstring, int32_t>> iterable = m;

    // Both should produce identical iterators but the iterators are unique objects.
    REQUIRE(iterable.First());
    REQUIRE(m.First());
    REQUIRE(iterable.First() != m.First());

    IIterator<IKeyValuePair<hstring, int32_t>> i = m.First();
    REQUIRE((i.Current() == make<impl::KeyValuePair<hstring, int32_t>>(hstring{ L"one" }, 1)));
    REQUIRE(i.HasCurrent());
    REQUIRE(i.MoveNext());
    REQUIRE((i.Current() == make<impl::KeyValuePair<hstring, int32_t>>(hstring{ L"three" }, 3)));
    REQUIRE(i.HasCurrent());
    REQUIRE(i.MoveNext());
    REQUIRE((i.Current() == make<impl::KeyValuePair<hstring, int32_t>>(hstring{ L"two" }, 2)));
    REQUIRE(i.HasCurrent());
    REQUIRE(!i.MoveNext());

    std::array<IKeyValuePair<hstring, int32_t>, 4> many{};
    REQUIRE(0 == i.GetMany(many));

    // Reset iterator
    i = m.First();
    REQUIRE(3 == i.GetMany(many));
    REQUIRE((many[0] == make<impl::KeyValuePair<hstring, int32_t>>(hstring{ L"one" }, 1)));
    REQUIRE((many[1] == make<impl::KeyValuePair<hstring, int32_t>>(hstring{ L"three" }, 3)));
    REQUIRE((many[2] == make<impl::KeyValuePair<hstring, int32_t>>(hstring{ L"two" }, 2)));
    REQUIRE((!many[3]));
}
