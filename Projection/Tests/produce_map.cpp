#include "pch.h"
#include "catch.hpp"
#include <array>
#include "event.h"

namespace winrt { namespace ABI { namespace Windows { namespace Foundation { namespace Collections {

template <> struct __declspec(uuid("81a643fb-f51c-5565-83c4-f96425777b64")) __declspec(novtable) IMapChangedEventArgs<uint32_t> : impl_IMapChangedEventArgs<uint32_t> {};

template <> struct __declspec(uuid("81a643fb-f51c-5565-83c4-f96425777b61")) __declspec(novtable) IKeyValuePair<int32_t, hstring> : impl_IKeyValuePair<int32_t, hstring> {};
template <> struct __declspec(uuid("81a643fb-f51c-5565-83c4-f96425777b62")) __declspec(novtable) IIterator<IKeyValuePair<int32_t, hstring>> : impl_IIterator<IKeyValuePair<int32_t, hstring>> {};
template <> struct __declspec(uuid("81a643fb-f51c-5565-83c4-f96425777b63")) __declspec(novtable) IIterable<IKeyValuePair<int32_t, hstring>> : impl_IIterable<IKeyValuePair<int32_t, hstring>> {};
template <> struct __declspec(uuid("81a643fb-f51c-5565-83c4-f96425777b64")) __declspec(novtable) IMap<int32_t, hstring> : impl_IMap<int32_t, hstring> {};
template <> struct __declspec(uuid("81a643fb-f51c-5565-83c4-f96425777b65")) __declspec(novtable) IMapView<int32_t, hstring> : impl_IMapView<int32_t, hstring> {};
template <> struct __declspec(uuid("81a643fb-f51c-5565-83c4-f96425777b66")) __declspec(novtable) MapChangedEventHandler<int32_t, hstring> : impl_MapChangedEventHandler<int32_t, hstring> {};
template <> struct __declspec(uuid("81a643fb-f51c-5565-83c4-f96425777b66")) __declspec(novtable) IObservableMap<int32_t, hstring> : impl_IObservableMap<int32_t, hstring> {};
template <> struct __declspec(uuid("81a643fb-f51c-5565-83c4-f96425777b67")) __declspec(novtable) IMapChangedEventArgs<int32_t> : impl_IMapChangedEventArgs<int32_t> {};

template <> struct __declspec(uuid("81a643fb-f51c-5565-83c4-f96425777b61")) __declspec(novtable) IKeyValuePair<hstring, int32_t> : impl_IKeyValuePair<hstring, int32_t> {};
template <> struct __declspec(uuid("81a643fb-f51c-5565-83c4-f96425777b62")) __declspec(novtable) IIterator<IKeyValuePair<hstring, int32_t>> : impl_IIterator<IKeyValuePair<hstring, int32_t>> {};
template <> struct __declspec(uuid("81a643fb-f51c-5565-83c4-f96425777b63")) __declspec(novtable) IIterable<IKeyValuePair<hstring, int32_t>> : impl_IIterable<IKeyValuePair<hstring, int32_t>> {};
template <> struct __declspec(uuid("81a643fb-f51c-5565-83c4-f96425777b64")) __declspec(novtable) IMap<hstring, int32_t> : impl_IMap<hstring, int32_t> {};
template <> struct __declspec(uuid("81a643fb-f51c-5565-83c4-f96425777b65")) __declspec(novtable) IMapView<hstring, int32_t> : impl_IMapView<hstring, int32_t> {};
template <> struct __declspec(uuid("81a643fb-f51c-5565-83c4-f96425777b66")) __declspec(novtable) MapChangedEventHandler<hstring, int32_t> : impl_MapChangedEventHandler<hstring, int32_t> {};
template <> struct __declspec(uuid("81a643fb-f51c-5565-83c4-f96425777b66")) __declspec(novtable) IObservableMap<hstring, int32_t> : impl_IObservableMap<hstring, int32_t> {};

}}}}}

//
// These tests cover the production of the various map-related interfaces.
// Tests ensure that the ABI surface lines up on the consumer and producer sides and this is mainly done simply by calling
// the various inteface methods.
//

using namespace winrt;
using namespace Windows::Foundation;
using namespace Windows::Foundation::Collections;

//
// IMapChangedEventArgs
//

template <typename K>
struct produce_IMapChangedEventArgs : implements<produce_IMapChangedEventArgs<K>,
                                                 IMapChangedEventArgs<K>>
{
    CollectionChange m_change;
    K m_key;

    produce_IMapChangedEventArgs(CollectionChange change, const K & key) :
        m_change(change),
        m_key(key)
    {}

    CollectionChange CollectionChange() const
    {
        return m_change;
    }

    K Key() const
    {
        return m_key;
    }
};

TEST_CASE("produce_IMapChangedEventArgs")
{
    {
        IMapChangedEventArgs<uint32_t> args = make<produce_IMapChangedEventArgs<uint32_t>>(CollectionChange::Reset, 123);
        REQUIRE(args.CollectionChange() == CollectionChange::Reset);
        REQUIRE(args.Key() == 123);
    }

    {
        IMapChangedEventArgs<hstring> args = make<produce_IMapChangedEventArgs<hstring>>(CollectionChange::Reset, L"value");
        REQUIRE(args.CollectionChange() == CollectionChange::Reset);
        REQUIRE(args.Key() == L"value");
    }
}

//
// What follows is a complete reference implementation of IMap/IMapView/IIterable/IIterator used for testing
// both the consumer and producer sides of the projection of these collection interfaces.
//

template <typename K, typename V>
struct produce_IKeyValuePair : implements<produce_IKeyValuePair<K, V>,
                                          IKeyValuePair<K, V>>
{
    K m_key;
    V m_value;

    produce_IKeyValuePair(const K & key, const V & value) :
        m_key(key),
        m_value(value)
    {}

    K Key() const
    {
        return m_key;
    }

    V Value() const
    {
        return m_value;
    }
};

template <typename C>
struct produce_IIterator_IKeyValuePair : implements<produce_IIterator_IKeyValuePair<C>,
                                                    IIterator<IKeyValuePair<typename C::key_type, typename C::mapped_type>>>
{
    using key_type = typename C::key_type;
    using mapped_type = typename C::mapped_type;
    using value_type = IKeyValuePair<key_type, mapped_type>;
    using const_iterator = typename C::const_iterator;

    Windows::IInspectable m_reference;
    const_iterator m_iterator;
    const_iterator m_end;

    produce_IIterator_IKeyValuePair(const Windows::IInspectable & reference,
                                    const C & container) :
        m_reference(reference),
        m_iterator(begin(container)),
        m_end(end(container))
    {}

    value_type Current() const
    {
        if (m_iterator == m_end)
        {
            throw hresult_out_of_bounds();
        }

        return make<produce_IKeyValuePair<key_type, mapped_type>>(m_iterator->first, m_iterator->second);
    }

    bool HasCurrent() const
    {
        return m_iterator != m_end;
    }

    bool MoveNext()
    {
        if (m_iterator == m_end)
        {
            throw hresult_out_of_bounds();
        }

        return ++m_iterator != m_end;
    }

    uint32_t GetMany(array_ref<IKeyValuePair<typename C::key_type, typename C::mapped_type>> values)
    {
        uint32_t capacity = values.size();
        uint32_t actual = 0;

        while (capacity && m_iterator != m_end)
        {
            values[actual] = make<produce_IKeyValuePair<key_type, mapped_type>>(m_iterator->first, m_iterator->second);
            ++m_iterator;
            --capacity;
            ++actual;
        }

        return actual;
    }
};

template <typename C>
struct produce_IMap : implements<produce_IMap<C>,
                                 IObservableMap<typename C::key_type, typename C::mapped_type>,
                                 IMap<typename C::key_type, typename C::mapped_type>,
                                 IMapView<typename C::key_type, typename C::mapped_type>,
                                 IIterable<IKeyValuePair<typename C::key_type, typename C::mapped_type>>>
{
    using key_type = typename C::key_type;
    using mapped_type = typename C::mapped_type;

    C m;
    event<MapChangedEventHandler<key_type, mapped_type>> m_mapChanged;

    produce_IMap() = default;

    produce_IMap(C && container) :
        m(std::move(container))
    {}

    produce_IMap(const C & container) :
        m(container)
    {}

    mapped_type Lookup(const key_type & key) const
    {
        auto i = m.find(key);

        if (i == end(m))
        {
            throw hresult_out_of_bounds();
        }

        return i->second;
    }

    uint32_t Size() const
    {
        return static_cast<uint32_t>(m.size());
    }

    bool HasKey(const key_type & key) const
    {
        return end(m) != m.find(key);
    }

    IMapView<key_type, mapped_type> GetView()
    {
        return *this;
    }

    bool Insert(const key_type & key, const mapped_type & value)
    {
        auto result = m.insert_or_assign(key, value);

        // This is very inefficient but it will do for testing.
        m_mapChanged(*this, make<produce_IMapChangedEventArgs<key_type>>(CollectionChange::ItemInserted, key));

        return !result.second;
    }

    void Remove(const key_type & key)
    {
        m.erase(key);
    }

    void Clear()
    {
        m.clear();
    }

    void Split(IMapView<key_type, mapped_type> & firstPartition, IMapView<key_type, mapped_type> & secondPartition)
    {
        firstPartition = nullptr;
        secondPartition = nullptr;
    }

    IIterator<IKeyValuePair<key_type, mapped_type>> First()
    {
        return make<produce_IIterator_IKeyValuePair<C>>(*this, m);
    }

    event_token MapChanged(const MapChangedEventHandler<key_type, mapped_type> & handler)
    {
        return m_mapChanged.add(handler);
    }

    void MapChanged(const event_token cookie)
    {
        m_mapChanged.remove(cookie);
    }
};

// This producer tests that IMap may be specialized with a value type key and hstring value.

TEST_CASE("produce_IMap_int32_t_hstring")
{
    using Container = std::map<int32_t, hstring>;

    IMap<int32_t, hstring> m = make<produce_IMap<Container>>();

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
    REQUIRE(!m.Insert(1, L"one"));
    REQUIRE(handlerCount == 1);

    om.MapChanged(token); // Unregister and thus handlerCount should not increase after this.

    REQUIRE(handlerCount == 1);
    REQUIRE(m.Insert(1, L"one"));
    REQUIRE(handlerCount == 1);

    REQUIRE(handlerCount == 1);
    REQUIRE(!m.Insert(2, L"two"));
    REQUIRE(handlerCount == 1);

    REQUIRE(m.Insert(2, L"two"));

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

    IMap<int32_t, hstring> m = make<produce_IMap<Container>>();
    m.Insert(1, L"one");
    m.Insert(2, L"two");
    m.Insert(3, L"three");

    IIterable<IKeyValuePair<int32_t, hstring>> iterable = m;

    // Both should produce identical iterators but the iterators are unique objects.
    REQUIRE(iterable.First());
    REQUIRE(m.First());
    REQUIRE(iterable.First() != m.First());

    IIterator<IKeyValuePair<int32_t, hstring>> i = m.First();
    REQUIRE((i.Current() == make<produce_IKeyValuePair<int32_t, hstring>>(1, L"one")));
    REQUIRE(i.HasCurrent());
    REQUIRE(i.MoveNext());
    REQUIRE((i.Current() == make<produce_IKeyValuePair<int32_t, hstring>>(2, L"two")));
    REQUIRE(i.HasCurrent());
    REQUIRE(i.MoveNext());
    REQUIRE((i.Current() == make<produce_IKeyValuePair<int32_t, hstring>>(3, L"three")));
    REQUIRE(i.HasCurrent());
    REQUIRE(!i.MoveNext());

    std::array<IKeyValuePair<int32_t, hstring>, 4> many{};
    REQUIRE(0 == i.GetMany(many));

    // Reset iterator
    i = m.First();
    REQUIRE(3 == i.GetMany(many));
    REQUIRE((many[0] == make<produce_IKeyValuePair<int32_t, hstring>>(1, L"one")));
    REQUIRE((many[1] == make<produce_IKeyValuePair<int32_t, hstring>>(2, L"two")));
    REQUIRE((many[2] == make<produce_IKeyValuePair<int32_t, hstring>>(3, L"three")));
    REQUIRE((!many[3]));
}

// This producer tests that IMap may be specialized with an hstring key and int32_t value.

TEST_CASE("produce_IMap_hstring_int32_t")
{
    using Container = std::map<hstring, int32_t>;

    IMap<hstring, int32_t> m = make<produce_IMap<Container>>();

    REQUIRE(!m.Insert(L"one", 1));
    REQUIRE(m.Insert(L"one", 1));

    REQUIRE(!m.Insert(L"two", 2));
    REQUIRE(m.Insert(L"two", 2));

    REQUIRE(m.Lookup(L"one") == 1);
    REQUIRE(m.Lookup(L"two") == 2);
    REQUIRE_THROWS_AS(m.Lookup(L"three"), hresult_out_of_bounds);

    REQUIRE(m.Size() == 2);

    REQUIRE(m.HasKey(L"one"));
    REQUIRE(!m.HasKey(L"three"));

    IMapView<hstring, int32_t> view = m.GetView();
    const bool same = view.as<IMap<hstring, int32_t>>() == m;
    REQUIRE(same);

    REQUIRE(m.Size() == 2);
    m.Remove(L"one"); // existing
    REQUIRE(m.Size() == 1);
    m.Remove(L"three"); // not existing
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

    IMap<hstring, int32_t> m = make<produce_IMap<Container>>();
    m.Insert(L"one", 1);
    m.Insert(L"two", 2);
    m.Insert(L"three", 3);

    IIterable<IKeyValuePair<hstring, int32_t>> iterable = m;

    // Both should produce identical iterators but the iterators are unique objects.
    REQUIRE(iterable.First());
    REQUIRE(m.First());
    REQUIRE(iterable.First() != m.First());

    IIterator<IKeyValuePair<hstring, int32_t>> i = m.First();
    REQUIRE((i.Current() == make<produce_IKeyValuePair<hstring, int32_t>>(L"one", 1)));
    REQUIRE(i.HasCurrent());
    REQUIRE(i.MoveNext());
    REQUIRE((i.Current() == make<produce_IKeyValuePair<hstring, int32_t>>(L"three", 3)));
    REQUIRE(i.HasCurrent());
    REQUIRE(i.MoveNext());
    REQUIRE((i.Current() == make<produce_IKeyValuePair<hstring, int32_t>>(L"two", 2)));
    REQUIRE(i.HasCurrent());
    REQUIRE(!i.MoveNext());

    std::array<IKeyValuePair<hstring, int32_t>, 4> many{};
    REQUIRE(0 == i.GetMany(many));

    // Reset iterator
    i = m.First();
    REQUIRE(3 == i.GetMany(many));
    REQUIRE((many[0] == make<produce_IKeyValuePair<hstring, int32_t>>(L"one", 1)));
    REQUIRE((many[1] == make<produce_IKeyValuePair<hstring, int32_t>>(L"three", 3)));
    REQUIRE((many[2] == make<produce_IKeyValuePair<hstring, int32_t>>(L"two", 2)));
    REQUIRE((!many[3]));
}
