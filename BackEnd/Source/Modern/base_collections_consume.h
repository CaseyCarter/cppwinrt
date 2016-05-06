
namespace Windows { namespace Foundation { namespace Collections {

enum class CollectionChange
{
    Reset,
    ItemInserted,
    ItemRemoved,
    ItemChanged,
};

}}}

namespace ABI { namespace Windows { namespace Foundation { namespace Collections {


struct __declspec(uuid("575933df-34fe-4480-af15-07691f3d5d9b")) __declspec(novtable) IVectorChangedEventArgs : IInspectable
{
    virtual HRESULT __stdcall get_CollectionChange(winrt::Windows::Foundation::Collections::CollectionChange * value) = 0;
    virtual HRESULT __stdcall get_Index(uint32_t * value) = 0;
};

}}}}

namespace Windows { namespace Foundation { namespace Collections {

struct IVectorChangedEventArgs;

template <typename D>
class impl_IVectorChangedEventArgs
{
    auto shim() const { return impl::shim<D, IVectorChangedEventArgs>(this); }

public:

    CollectionChange CollectionChange() const;
    uint32_t Index() const;
};

}}}

namespace impl {

template <> struct traits<Windows::Foundation::Collections::IVectorChangedEventArgs>
{
    using abi = ABI::Windows::Foundation::Collections::IVectorChangedEventArgs;
    template <typename T> using consume = Windows::Foundation::Collections::impl_IVectorChangedEventArgs<T>;
};

template <typename From, typename To>
using is_convertible = typename std::is_convertible<From, To>::type *;

}

namespace Windows { namespace Foundation { namespace Collections {

struct IVectorChangedEventArgs :
    IInspectable,
    impl_IVectorChangedEventArgs<IVectorChangedEventArgs>
{
    IVectorChangedEventArgs(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IVectorChangedEventArgs>(m_ptr); }
};

template <typename T> CollectionChange impl_IVectorChangedEventArgs<T>::CollectionChange() const
{
    Collections::CollectionChange value = {};
    check_hresult(shim()->get_CollectionChange(&value));
    return value;
}

template <typename T> uint32_t impl_IVectorChangedEventArgs<T>::Index() const
{
    uint32_t index = 0;
    check_hresult(shim()->get_Index(&index));
    return index;
}

}}}

namespace ABI { namespace Windows { namespace Foundation { namespace Collections {

template <typename T> struct IIterator;
template <typename T> struct IIterable;
template <typename K, typename V> struct IKeyValuePair;
template <typename T> struct IVectorView;
template <typename T> struct IVector;
template <typename K, typename V> struct IMapView;
template <typename K, typename V> struct IMap;
template <typename K> struct IMapChangedEventArgs;
template <typename K, typename V> struct MapChangedEventHandler;
template <typename K, typename V> struct IObservableMap;
template <typename T> struct VectorChangedEventHandler;
template <typename T> struct IObservableVector;

template <typename T>
struct __declspec(novtable) impl_IIterator : IInspectable
{
    virtual HRESULT __stdcall get_Current(arg_out<T> current) = 0;
    virtual HRESULT __stdcall get_HasCurrent(bool * hasCurrent) = 0;
    virtual HRESULT __stdcall abi_MoveNext(bool * hasCurrent) = 0;
    virtual HRESULT __stdcall abi_GetMany(uint32_t capacity, arg_out<T> value, uint32_t * actual) = 0;

};

template <typename T>
struct __declspec(novtable) impl_IIterable : IInspectable
{
    virtual HRESULT __stdcall abi_First(IIterator<T> ** first) = 0;
};

template <typename K, typename V>
struct __declspec(novtable) impl_IKeyValuePair : IInspectable
{
    virtual HRESULT __stdcall get_Key(arg_out<K> key) = 0;
    virtual HRESULT __stdcall get_Value(arg_out<V> value) = 0;
};

template <typename T>
struct __declspec(novtable) impl_IVectorView : IInspectable
{
    virtual HRESULT __stdcall abi_GetAt(uint32_t index, arg_out<T> item) = 0;
    virtual HRESULT __stdcall get_Size(uint32_t * size) = 0;
    virtual HRESULT __stdcall abi_IndexOf(arg_in<T> value, uint32_t * index, bool * found) = 0;
    virtual HRESULT __stdcall abi_GetMany(uint32_t startIndex, uint32_t capacity, arg_out<T> value, uint32_t * actual) = 0;
};

template <typename T>
struct __declspec(novtable) impl_IVector : IInspectable
{
    virtual HRESULT __stdcall abi_GetAt(uint32_t index, arg_out<T> item) = 0;
    virtual HRESULT __stdcall get_Size(uint32_t * size) = 0;
    virtual HRESULT __stdcall abi_GetView(IVectorView<T> ** view) = 0;
    virtual HRESULT __stdcall abi_IndexOf(arg_in<T> value, uint32_t * index, bool * found) = 0;
    virtual HRESULT __stdcall abi_SetAt(uint32_t index, arg_in<T> item) = 0;
    virtual HRESULT __stdcall abi_InsertAt(uint32_t index, arg_in<T> item) = 0;
    virtual HRESULT __stdcall abi_RemoveAt(uint32_t index) = 0;
    virtual HRESULT __stdcall abi_Append(arg_in<T> item) = 0;
    virtual HRESULT __stdcall abi_RemoveAtEnd() = 0;
    virtual HRESULT __stdcall abi_Clear() = 0;
    virtual HRESULT __stdcall abi_GetMany(uint32_t startIndex, uint32_t capacity, arg_out<T> value, uint32_t * actual) = 0;
    virtual HRESULT __stdcall abi_ReplaceAll(uint32_t count, arg_out<T> value) = 0;

};

template <typename K, typename V>
struct __declspec(novtable) impl_IMapView : IInspectable
{
    virtual HRESULT __stdcall abi_Lookup(arg_in<K> key, arg_out<V> value) = 0;
    virtual HRESULT __stdcall get_Size(uint32_t * size) = 0;
    virtual HRESULT __stdcall abi_HasKey(arg_in<K> key, bool * found) = 0;
    virtual HRESULT __stdcall abi_Split(IMapView<K, V> ** firstPartition, IMapView<K, V> ** secondPartition) = 0;
};

template <typename K, typename V>
struct __declspec(novtable) impl_IMap : IInspectable
{
    virtual HRESULT __stdcall abi_Lookup(arg_in<K> key, arg_out<V> value) = 0;
    virtual HRESULT __stdcall get_Size(uint32_t * size) = 0;
    virtual HRESULT __stdcall abi_HasKey(arg_in<K> key, bool * found) = 0;
    virtual HRESULT __stdcall abi_GetView(IMapView<K, V> ** view) = 0;
    virtual HRESULT __stdcall abi_Insert(arg_in<K> key, arg_in<V> value, bool * replaced) = 0;
    virtual HRESULT __stdcall abi_Remove(arg_in<K> key) = 0;
    virtual HRESULT __stdcall abi_Clear() = 0;
};

template <typename K>
struct __declspec(novtable) impl_IMapChangedEventArgs : IInspectable
{
    virtual HRESULT __stdcall get_CollectionChange(winrt::Windows::Foundation::Collections::CollectionChange * value) = 0;
    virtual HRESULT __stdcall get_Key(arg_out<K> value) = 0;
};

template <typename K, typename V>
struct __declspec(novtable) impl_MapChangedEventHandler : IUnknown
{
    virtual HRESULT __stdcall abi_Invoke(IObservableMap<K, V> * sender, IMapChangedEventArgs<K> * args) = 0;
};

template <typename K, typename V>
struct __declspec(novtable) impl_IObservableMap : IInspectable
{
    virtual HRESULT __stdcall add_MapChanged(MapChangedEventHandler<K, V> * handler, long long * token) = 0;
    virtual HRESULT __stdcall remove_MapChanged(long long token) = 0;
};

template <typename T>
struct __declspec(novtable) impl_VectorChangedEventHandler : IUnknown
{
    virtual HRESULT __stdcall abi_Invoke(IObservableVector<T> * sender, IVectorChangedEventArgs * args) = 0;
};

template <typename T>
struct __declspec(novtable) impl_IObservableVector : IInspectable
{
    virtual HRESULT __stdcall add_VectorChanged(VectorChangedEventHandler<T> * handler, long long *  token) = 0;
    virtual HRESULT __stdcall remove_VectorChanged(long long token) = 0;
};

}}}}

namespace Windows { namespace Foundation { namespace Collections {

template <typename T> struct IIterator;
template <typename T> struct IIterable;
template <typename K, typename V> struct IKeyValuePair;
template <typename T> struct IVectorView;
template <typename T> struct IVector;
template <typename K, typename V> struct IMapView;
template <typename K, typename V> struct IMap;
template <typename K> struct IMapChangedEventArgs;
template <typename K, typename V> struct MapChangedEventHandler;
template <typename K, typename V> struct IObservableMap;
template <typename T> struct VectorChangedEventHandler;
template <typename T> struct IObservableVector;

template <typename D, typename T>
class impl_consume_IIterator
{
    auto shim() const { return impl::shim<D, IIterator<T>>(this); }

public:

    T Current() const
    {
        T result = impl::argument<T>::empty();
        check_hresult(shim()->get_Current(put(result)));
        return result;
    }

    bool HasCurrent() const
    {
        bool temp = false;
        check_hresult(shim()->get_HasCurrent(put(temp)));
        return temp;
    }

    bool MoveNext() const
    {
        bool temp = false;
        check_hresult(shim()->abi_MoveNext(put(temp)));
        return temp;
    }

    uint32_t GetMany(array_ref<T> values) const
    {
        uint32_t actual = 0;
        check_hresult(shim()->abi_GetMany(values.size(), get(values), &actual));
        return actual;
    }

    auto & operator++()
    {
        if (!MoveNext())
        {
            static_cast<D &>(*this) = nullptr;
        }

        return *this;
    }

    T operator *() const
    {
        return Current();
    }
};

template <typename D, typename T>
class impl_consume_IIterable
{
    auto shim() const { return impl::shim<D, IIterable<T>>(this); }

public:

    IIterator<T> First() const
    {
        IIterator<T> iterator;
        check_hresult(shim()->abi_First(put(iterator)));
        return iterator;
    }
};

template <typename D, typename K, typename V>
class impl_consume_IKeyValuePair
{
    auto shim() const { return impl::shim<D, IKeyValuePair<K, V>>(this); }

public:

    K Key() const
    {
        K result = impl::argument<K>::empty();
        check_hresult(shim()->get_Key(put(result)));
        return result;
    }

    V Value() const
    {
        V result = impl::argument<V>::empty();
        check_hresult(shim()->get_Value(put(result)));
        return result;
    }

    bool operator==(const IKeyValuePair<K, V> & other) const noexcept
    {
        return Key() == other.Key() && Value() == other.Value();
    }

    bool operator!=(const IKeyValuePair<K, V> & other) const noexcept
    {
        return !(*this == other);
    }
};

template <typename D, typename T>
class impl_consume_IVectorView
{
    auto shim() const { return impl::shim<D, IVectorView<T>>(this); }

public:

    T GetAt(const uint32_t index) const
    {
        T result = impl::argument<T>::empty();
        check_hresult(shim()->abi_GetAt(index, put(result)));
        return result;
    }

    uint32_t Size() const
    {
        uint32_t size = 0;
        check_hresult(shim()->get_Size(&size));
        return size;
    }

    bool IndexOf(const T & value, uint32_t & index) const
    {
        bool found = false;
        check_hresult(shim()->abi_IndexOf(get(value), &index, put(found)));
        return found;
    }
};

template <typename D, typename T>
class impl_consume_IVector
{
    auto shim() const { return impl::shim<D, IVector<T>>(this); }

public:

    T GetAt(const uint32_t index) const
    {
        T result = impl::argument<T>::empty();
        check_hresult(shim()->abi_GetAt(index, put(result)));
        return result;
    }

    uint32_t Size() const
    {
        uint32_t size = 0;
        check_hresult(shim()->get_Size(&size));
        return size;
    }

    IVectorView<T> GetView() const
    {
        IVectorView<T> view;
        check_hresult(shim()->abi_GetView(put(view)));
        return view;
    }

    bool IndexOf(const T & value, uint32_t & index) const
    {
        bool found = false;
        check_hresult(shim()->abi_IndexOf(get(value), &index, put(found)));
        return found;
    }

    void SetAt(const uint32_t index, const T & value) const
    {
        check_hresult(shim()->abi_SetAt(index, get(value)));
    }

    void InsertAt(const uint32_t index, const T & value) const
    {
        check_hresult(shim()->abi_InsertAt(index, get(value)));
    }

    void RemoveAt(const uint32_t index) const
    {
        check_hresult(shim()->abi_RemoveAt(index));
    }

    void Append(const T & value) const
    {
        check_hresult(shim()->abi_Append(get(value)));
    }

    void RemoveAtEnd() const
    {
        check_hresult(shim()->abi_RemoveAtEnd());
    }

    void Clear() const
    {
        check_hresult(shim()->abi_Clear());
    }

    uint32_t GetMany(uint32_t startIndex, array_ref<T> values) const
    {
        uint32_t actual = 0;
        check_hresult(shim()->abi_GetMany(startIndex, values.size(), get(values), &actual));
        return actual;
    }

    template <typename Array>
    void ReplaceAll(const Array & values) const
    {
        check_hresult(shim()->abi_ReplaceAll(static_cast<uint32_t>(values.size()), reinterpret_cast<abi_arg_out<T>>(const_cast<Array &>(values).data())));
    }
};

template <typename D, typename K, typename V>
class impl_consume_IMapView
{
    auto shim() const { return impl::shim<D, IMapView<K, V>>(this); }

public:

    V Lookup(const K & key) const
    {
        V result = impl::argument<V>::empty();
        check_hresult(shim()->abi_Lookup(get(key), put(result)));
        return result;
    }

    uint32_t Size() const
    {
        uint32_t size = 0;
        check_hresult(shim()->get_Size(&size));
        return size;
    }

    bool HasKey(const K & key) const
    {
        bool found = false;
        check_hresult(shim()->abi_HasKey(get(key), put(found)));
        return found;
    }

    void Split(IMapView<K, V> & firstPartition, IMapView<K, V> & secondPartition)
    {
        check_hresult(shim()->abi_Split(put(firstPartition), put(secondPartition)));
    }
};

template <typename D, typename K, typename V>
class impl_consume_IMap
{
    auto shim() const { return impl::shim<D, IMap<K, V>>(this); }

public:

    V Lookup(const K & key) const
    {
        V result = impl::argument<V>::empty();
        check_hresult(shim()->abi_Lookup(get(key), put(result)));
        return result;
    }

    uint32_t Size() const
    {
        uint32_t size = 0;
        check_hresult(shim()->get_Size(&size));
        return size;
    }

    bool HasKey(const K & key) const
    {
        bool found = false;
        check_hresult(shim()->abi_HasKey(get(key), put(found)));
        return found;
    }

    IMapView<K, V> GetView() const
    {
        IMapView<K, V> view;
        check_hresult(shim()->abi_GetView(put(view)));
        return view;
    }

    bool Insert(const K & key, const V & value) const
    {
        bool replaced = false;
        check_hresult(shim()->abi_Insert(get(key), get(value), put(replaced)));
        return replaced;
    }

    void Remove(const K & key) const
    {
        check_hresult(shim()->abi_Remove(get(key)));
    }

    void Clear() const
    {
        check_hresult(shim()->abi_Clear());
    }
};

template <typename D, typename K>
class impl_consume_IMapChangedEventArgs
{
    auto shim() const { return impl::shim<D, IMapChangedEventArgs<K>>(this); }

public:

    CollectionChange CollectionChange() const
    {
        CollectionChange value = {};
        check_hresult(shim()->get_CollectionChange(&value));
        return value;
    }

    K Key() const
    {
        K result = impl::argument<K>::empty();
        check_hresult(shim()->get_Key(put(result)));
        return result;
    }
};

template <typename D, typename K, typename V>
class impl_consume_MapChangedEventHandler
{
    auto shim() const { return impl::shim<D, MapChangedEventHandler<K, V>>(this); }

public:

    void Invoke(const IObservableMap<K, V> & sender, const IMapChangedEventArgs<K> & args) const
    {
        check_hresult(shim()->abi_Invoke(get(sender), get(args)));
    }
};

template <typename D, typename K, typename V>
class impl_consume_IObservableMap
{
    auto shim() const { return impl::shim<D, IObservableMap<K, V>>(this); }

public:

    long long MapChanged(const MapChangedEventHandler<K, V> & handler) const
    {
        long long cookie = {};
        check_hresult(shim()->add_MapChanged(get(handler), &cookie));
        return cookie;
    }

    void MapChanged(const long long cookie) const
    {
        check_hresult(shim()->remove_MapChanged(cookie));
    }
};

template <typename D, typename T>
class impl_consume_VectorChangedEventHandler
{
    auto shim() const { return impl::shim<D, VectorChangedEventHandler<T>>(this); }

public:

    void Invoke(const IObservableVector<T> & sender, const IVectorChangedEventArgs & args) const
    {
        check_hresult(shim()->abi_Invoke(get(sender), get(args)));
    }
};

template <typename D, typename T>
class impl_consume_IObservableVector
{
    auto shim() const { return impl::shim<D, IObservableVector<T>>(this); }

public:

    long long VectorChanged(const VectorChangedEventHandler<T> & handler) const
    {
        long long cookie = {};
        check_hresult(shim()->add_VectorChanged(get(handler), &cookie));
        return cookie;
    }

    void VectorChanged(const long long cookie) const
    {
        check_hresult(shim()->remove_VectorChanged(cookie));
    }
};

}}}

namespace impl {

template <typename T> struct traits<Windows::Foundation::Collections::IIterator<T>>
{
    using abi = ABI::Windows::Foundation::Collections::IIterator<abi<T>>;
    template <typename D> using consume = Windows::Foundation::Collections::impl_consume_IIterator<D, T>;
};

template <typename T> struct traits<Windows::Foundation::Collections::IIterable<T>>
{
    using abi = ABI::Windows::Foundation::Collections::IIterable<abi<T>>;
    template <typename D> using consume = Windows::Foundation::Collections::impl_consume_IIterable<D, T>;
};

template <typename K, typename V> struct traits<Windows::Foundation::Collections::IKeyValuePair<K, V>>
{
    using abi = ABI::Windows::Foundation::Collections::IKeyValuePair<abi<K>, abi<V>>;
    template <typename D> using consume = Windows::Foundation::Collections::impl_consume_IKeyValuePair<D, K, V>;
};

template <typename T> struct traits<Windows::Foundation::Collections::IVectorView<T>>
{
    using abi = ABI::Windows::Foundation::Collections::IVectorView<abi<T>>;
    template <typename D> using consume = Windows::Foundation::Collections::impl_consume_IVectorView<D, T>;
};

template <typename T> struct traits<Windows::Foundation::Collections::IVector<T>>
{
    using abi = ABI::Windows::Foundation::Collections::IVector<abi<T>>;
    template <typename D> using consume = Windows::Foundation::Collections::impl_consume_IVector<D, T>;
};

template <typename K, typename V> struct traits<Windows::Foundation::Collections::IMapView<K, V>>
{
    using abi = ABI::Windows::Foundation::Collections::IMapView<abi<K>, abi<V>>;
    template <typename D> using consume = Windows::Foundation::Collections::impl_consume_IMapView<D, K, V>;
};

template <typename K, typename V> struct traits<Windows::Foundation::Collections::IMap<K, V>>
{
    using abi = ABI::Windows::Foundation::Collections::IMap<abi<K>, abi<V>>;
    template <typename D> using consume = Windows::Foundation::Collections::impl_consume_IMap<D, K, V>;
};

template <typename K> struct traits<Windows::Foundation::Collections::IMapChangedEventArgs<K>>
{
    using abi = ABI::Windows::Foundation::Collections::IMapChangedEventArgs<abi<K>>;
    template <typename D> using consume = Windows::Foundation::Collections::impl_consume_IMapChangedEventArgs<D, K>;
};

template <typename K, typename V> struct traits<Windows::Foundation::Collections::MapChangedEventHandler<K, V>>
{
    using abi = ABI::Windows::Foundation::Collections::MapChangedEventHandler<abi<K>, abi<V>>;
    template <typename D> using consume = Windows::Foundation::Collections::impl_consume_MapChangedEventHandler<D, K, V>;
};

template <typename K, typename V> struct traits<Windows::Foundation::Collections::IObservableMap<K, V>>
{
    using abi = ABI::Windows::Foundation::Collections::IObservableMap<abi<K>, abi<V>>;
    template <typename D> using consume = Windows::Foundation::Collections::impl_consume_IObservableMap<D, K, V>;
};

template <typename T> struct traits<Windows::Foundation::Collections::VectorChangedEventHandler<T>>
{
    using abi = ABI::Windows::Foundation::Collections::VectorChangedEventHandler<abi<T>>;
    template <typename D> using consume = Windows::Foundation::Collections::impl_consume_VectorChangedEventHandler<D, T>;
};

template <typename T> struct traits<Windows::Foundation::Collections::IObservableVector<T>>
{
    using abi = ABI::Windows::Foundation::Collections::IObservableVector<abi<T>>;
    template <typename D> using consume = Windows::Foundation::Collections::impl_consume_IObservableVector<D, T>;
};

template <typename T>
struct fast_iterator : std::iterator<std::input_iterator_tag, T>
{
    fast_iterator(const T & collection, const uint32_t index) noexcept :
        m_collection(&collection),
        m_index(index)
    {}

    fast_iterator & operator++() noexcept
    {
        ++m_index;
        return *this;
    }

    auto operator *() const
    {
        return m_collection->GetAt(m_index);
    }

    bool operator==(const fast_iterator & other) const noexcept
    {
        WINRT_ASSERT(m_collection == other.m_collection);
        return m_index == other.m_index;
    }

    bool operator!=(const fast_iterator & other) const noexcept
    {
        return !(*this == other);
    }

private:

    const T * m_collection = nullptr;
    uint32_t m_index = 0;
};

}

namespace Windows { namespace Foundation { namespace Collections {

template <typename T>
struct WINRT_EBO IIterator :
    IInspectable,
    consume<IIterator<T>>
{
    IIterator(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IIterator>(m_ptr); }
};

template <typename T>
struct WINRT_EBO IIterable :
    IInspectable,
    consume<IIterable<T>>
{
    IIterable(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IIterable>(m_ptr); }
};

template <typename K, typename V>
struct WINRT_EBO IIterable<IKeyValuePair<K, V>> :
    IInspectable,
    consume<IIterable<IKeyValuePair<K, V>>>
{
    IIterable(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IIterable>(m_ptr); }
};

template <typename K, typename V>
struct WINRT_EBO IKeyValuePair :
    IInspectable,
    consume<IKeyValuePair<K, V>>
{
    IKeyValuePair(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IKeyValuePair>(m_ptr); }
};

template <typename T>
struct WINRT_EBO IVectorView :
    IInspectable,
    consume<IVectorView<T>>,
    requires<IVectorView<T>, IIterable<T>>
{
    IVectorView(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IVectorView>(m_ptr); }
};

template <typename T>
struct WINRT_EBO IVector :
    IInspectable,
    consume<IVector<T>>,
    requires<IVector<T>, IIterable<T>>
{
    IVector(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IVector>(m_ptr); }
};

template <typename K, typename V>
struct WINRT_EBO IMapView :
    IInspectable,
    consume<IMapView<K, V>>,
    requires<IMapView<K, V>, IIterable<IKeyValuePair<K, V>>>
{
    IMapView(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IMapView>(m_ptr); }
};

template <typename K, typename V>
struct WINRT_EBO IMap :
    IInspectable,
    consume<IMap<K, V>>,
    requires<IMap<K, V>, IIterable<IKeyValuePair<K, V>>>
{
    IMap(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IMap>(m_ptr); }
};

template <typename K>
struct WINRT_EBO IMapChangedEventArgs :
    IInspectable,
    consume<IMapChangedEventArgs<K>>
{
    IMapChangedEventArgs(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IMapChangedEventArgs>(m_ptr); }
};

template <typename K, typename V>
struct WINRT_EBO MapChangedEventHandler :
    IUnknown,
    consume<MapChangedEventHandler<K, V>>
{
    MapChangedEventHandler(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<MapChangedEventHandler>(m_ptr); }
    template <typename H> MapChangedEventHandler(H handler);
};

template <typename K, typename V>
struct WINRT_EBO IObservableMap :
    IInspectable,
    consume<IObservableMap<K, V>>,
    requires<IObservableMap<K, V>, IMap<K, V>, IIterable<IKeyValuePair<K, V>>>
{
    IObservableMap(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IObservableMap>(m_ptr); }
};

template <typename T>
struct WINRT_EBO VectorChangedEventHandler :
    IUnknown,
    consume<VectorChangedEventHandler<T>>
{
    VectorChangedEventHandler(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<VectorChangedEventHandler>(m_ptr); }
    template <typename H> VectorChangedEventHandler(H handler);
};

template <typename T>
struct WINRT_EBO IObservableVector :
    IInspectable,
    consume<IObservableVector<T>>,
    requires<IObservableVector<T>, IVector<T>, IIterable<T>>
{
    IObservableVector(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IObservableVector>(m_ptr); }
};

template <typename T, std::enable_if_t<!impl::has_GetAt<T>::value> * = nullptr>
auto begin(const T & collection) -> decltype(collection.First())
{
    auto result = collection.First();

    if (!result.HasCurrent())
    {
        return {};
    }

    return result;
}

template <typename T, std::enable_if_t<!impl::has_GetAt<T>::value> * = nullptr>
auto end(const T & collection) -> decltype(collection.First())
{
    collection;
    return {};
}

template <typename T, std::enable_if_t<impl::has_GetAt<T>::value> * = nullptr>
impl::fast_iterator<T> begin(const T & collection) noexcept
{
    return impl::fast_iterator<T>(collection, 0);
}

template <typename T, std::enable_if_t<impl::has_GetAt<T>::value> * = nullptr>
impl::fast_iterator<T> end(const T & collection)
{
    return impl::fast_iterator<T>(collection, collection.Size());
}

}}}
