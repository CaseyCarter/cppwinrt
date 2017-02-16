#pragma once

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
// What follows is a complete reference implementation of IMap/IMapView/IIterable/IIterator used for testing
// both the consumer and producer sides of the projection of these collection interfaces.
//

namespace winrt::impl {

template <typename K>
struct MapChangedEventArgs : implements<MapChangedEventArgs<K>,
                                        Windows::Foundation::Collections::IMapChangedEventArgs<K>>
{
    Windows::Foundation::Collections::CollectionChange m_change;
    K m_key;

    MapChangedEventArgs(Windows::Foundation::Collections::CollectionChange change, const K & key) :
        m_change(change),
        m_key(key)
    {}

    Windows::Foundation::Collections::CollectionChange CollectionChange() const
    {
        return m_change;
    }

    K Key() const
    {
        return m_key;
    }
};

template <typename K, typename V>
struct KeyValuePair : implements<KeyValuePair<K, V>,
                                 Windows::Foundation::Collections::IKeyValuePair<K, V>>
{
    K m_key;
    V m_value;

    KeyValuePair(const K & key, const V & value) :
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
struct KeyValuePairIterator : implements<KeyValuePairIterator<C>,
                                         Windows::Foundation::Collections::IIterator<Windows::Foundation::Collections::IKeyValuePair<typename C::key_type, typename C::mapped_type>>>
{
    using key_type = typename C::key_type;
    using mapped_type = typename C::mapped_type;
    using value_type = Windows::Foundation::Collections::IKeyValuePair<key_type, mapped_type>;
    using const_iterator = typename C::const_iterator;

    Windows::Foundation::IInspectable m_reference;
    const_iterator m_iterator;
    const_iterator m_end;

    KeyValuePairIterator(const Windows::Foundation::IInspectable & reference,
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

        return make<KeyValuePair<key_type, mapped_type>>(m_iterator->first, m_iterator->second);
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

    uint32_t GetMany(array_view<Windows::Foundation::Collections::IKeyValuePair<typename C::key_type, typename C::mapped_type>> values)
    {
        uint32_t capacity = values.size();
        uint32_t actual = 0;

        while (capacity && m_iterator != m_end)
        {
            values[actual] = make<KeyValuePair<key_type, mapped_type>>(m_iterator->first, m_iterator->second);
            ++m_iterator;
            --capacity;
            ++actual;
        }

        return actual;
    }
};

template <typename C>
struct Map : implements<Map<C>,
                        Windows::Foundation::Collections::IObservableMap<typename C::key_type, typename C::mapped_type>,
                        Windows::Foundation::Collections::IMap<typename C::key_type, typename C::mapped_type>,
                        Windows::Foundation::Collections::IMapView<typename C::key_type, typename C::mapped_type>,
                        Windows::Foundation::Collections::IIterable<Windows::Foundation::Collections::IKeyValuePair<typename C::key_type, typename C::mapped_type>>>
{
    using key_type = typename C::key_type;
    using mapped_type = typename C::mapped_type;

    C m;
    agile_event<Windows::Foundation::Collections::MapChangedEventHandler<key_type, mapped_type>> m_mapChanged;

    Map() = default;

    Map(C && container) :
        m(std::move(container))
    {}

    Map(const C & container) :
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

    Windows::Foundation::Collections::IMapView<key_type, mapped_type> GetView()
    {
        return *this;
    }

    bool Insert(const key_type & key, const mapped_type & value)
    {
        auto result = m.insert_or_assign(key, value);

        // This is very inefficient but it will do for testing.
        m_mapChanged(*this, make<MapChangedEventArgs<key_type>>(Windows::Foundation::Collections::CollectionChange::ItemInserted, key));

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

    void Split(Windows::Foundation::Collections::IMapView<key_type, mapped_type> & firstPartition, Windows::Foundation::Collections::IMapView<key_type, mapped_type> & secondPartition)
    {
        firstPartition = nullptr;
        secondPartition = nullptr;
    }

    Windows::Foundation::Collections::IIterator<Windows::Foundation::Collections::IKeyValuePair<key_type, mapped_type>> First()
    {
        return make<KeyValuePairIterator<C>>(*this, m);
    }

    event_token MapChanged(const Windows::Foundation::Collections::MapChangedEventHandler<key_type, mapped_type> & handler)
    {
        return m_mapChanged.add(handler);
    }

    void MapChanged(const event_token cookie)
    {
        m_mapChanged.remove(cookie);
    }
};

}