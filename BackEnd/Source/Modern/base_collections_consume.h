
namespace impl {

template <typename T, typename containertype> struct iterator;
template <typename T, typename containertype> struct iterator_standalone;

}

namespace Windows::Foundation::Collections {

enum class CollectionChange
{
    Reset,
    ItemInserted,
    ItemRemoved,
    ItemChanged,
};

}

namespace ABI::Windows::Foundation::Collections {

struct __declspec(uuid("575933df-34fe-4480-af15-07691f3d5d9b")) __declspec(novtable) IVectorChangedEventArgs : IInspectable
{
    virtual HRESULT __stdcall get_CollectionChange(winrt::Windows::Foundation::Collections::CollectionChange * value) = 0;
    virtual HRESULT __stdcall get_Index(uint32_t * value) = 0;
};

}

namespace Windows::Foundation::Collections {

struct IVectorChangedEventArgs;

template <typename D>
class WINRT_EBO impl_IVectorChangedEventArgs
{
    auto shim() const { return impl::shim<D, IVectorChangedEventArgs>(this); }

public:

    CollectionChange CollectionChange() const
    {
        Collections::CollectionChange value {};
        check_hresult(shim()->get_CollectionChange(&value));
        return value;
    }

    uint32_t Index() const
    {
        uint32_t index = 0;
        check_hresult(shim()->get_Index(&index));
        return index;
    }
};

}

namespace impl {

template <typename T>
class has_GetAt
{
    template <typename U, typename = decltype(std::declval<U>().GetAt(0))> static constexpr bool get_value(int) { return true; }
    template <typename> static constexpr bool get_value(...) { return false; }

public:

    static constexpr bool value = get_value<T>(0);
};

template <> struct traits<Windows::Foundation::Collections::IVectorChangedEventArgs>
{
    using abi = ABI::Windows::Foundation::Collections::IVectorChangedEventArgs;
    template <typename D> using consume = Windows::Foundation::Collections::impl_IVectorChangedEventArgs<D>;
};

}

namespace Windows::Foundation::Collections {

struct IVectorChangedEventArgs :
    IInspectable,
    impl::consume<IVectorChangedEventArgs>
{
    IVectorChangedEventArgs(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IVectorChangedEventArgs>(m_ptr); }
};

}

namespace ABI::Windows::Foundation::Collections {

template <typename K, typename V> struct MapChangedEventHandler;
template <typename T> struct VectorChangedEventHandler;

template <typename T> struct IIterator;
template <typename T> struct IIterable;
template <typename K, typename V> struct IKeyValuePair;
template <typename T> struct IVectorView;
template <typename T> struct IVector;
template <typename K, typename V> struct IMapView;
template <typename K, typename V> struct IMap;
template <typename K> struct IMapChangedEventArgs;
template <typename K, typename V> struct IObservableMap;
template <typename T> struct IObservableVector;

template <typename K, typename V>
struct __declspec(novtable) impl_MapChangedEventHandler : IUnknown
{
    virtual HRESULT __stdcall abi_Invoke(IObservableMap<K, V> * sender, IMapChangedEventArgs<K> * args) = 0;
};

template <typename T>
struct __declspec(novtable) impl_VectorChangedEventHandler : IUnknown
{
    virtual HRESULT __stdcall abi_Invoke(IObservableVector<T> * sender, IVectorChangedEventArgs * args) = 0;
};

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
struct __declspec(novtable) impl_IObservableMap : IInspectable
{
    virtual HRESULT __stdcall add_MapChanged(MapChangedEventHandler<K, V> * handler, event_token * token) = 0;
    virtual HRESULT __stdcall remove_MapChanged(event_token token) = 0;
};

template <typename T>
struct __declspec(novtable) impl_IObservableVector : IInspectable
{
    virtual HRESULT __stdcall add_VectorChanged(VectorChangedEventHandler<T> * handler, event_token *  token) = 0;
    virtual HRESULT __stdcall remove_VectorChanged(event_token token) = 0;
};

template <typename K, typename V> struct MapChangedEventHandler : impl::not_specialized<MapChangedEventHandler<K, V>> {};
template <typename T> struct VectorChangedEventHandler : impl::not_specialized <VectorChangedEventHandler<T>> {};
template <typename T> struct IIterator : impl::not_specialized <IIterator<T>> {};
template <typename T> struct IIterable : impl::not_specialized <IIterable<T>> {};
template <typename K, typename V> struct IKeyValuePair : impl::not_specialized <IKeyValuePair<K, V>> {};
template <typename T> struct IVectorView : impl::not_specialized <IVectorView<T>> {};
template <typename T> struct IVector : impl::not_specialized <IVector<T>> {};
template <typename K, typename V> struct IMapView : impl::not_specialized <IMapView<K, V>> {};
template <typename K, typename V> struct IMap : impl::not_specialized <IMap<K, V>> {};
template <typename K> struct IMapChangedEventArgs : impl::not_specialized <IMapChangedEventArgs<K>> {};
template <typename K, typename V> struct IObservableMap : impl::not_specialized <IObservableMap<K, V>> {};
template <typename T> struct IObservableVector : impl::not_specialized <IObservableVector<T>> {};

}

namespace Windows::Foundation::Collections {

template <typename K, typename V> struct MapChangedEventHandler;
template <typename T> struct VectorChangedEventHandler;

template <typename T> struct IIterator;
template <typename T> struct IIterable;
template <typename K, typename V> struct IKeyValuePair;
template <typename T> struct IVectorView;
template <typename T> struct IVector;
template <typename K, typename V> struct IMapView;
template <typename K, typename V> struct IMap;
template <typename K> struct IMapChangedEventArgs;
template <typename K, typename V> struct IObservableMap;
template <typename T> struct IObservableVector;

template <typename D, typename T>
class impl_IIterator
{
    auto shim() const { return impl::shim<D, IIterator<T>>(this); }

public:

    T Current() const
    {
        T result = impl::empty_value<T>();
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
class impl_IIterable
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
class impl_IKeyValuePair
{
    auto shim() const { return impl::shim<D, IKeyValuePair<K, V>>(this); }

public:

    K Key() const
    {
        K result = impl::empty_value<K>();
        check_hresult(shim()->get_Key(put(result)));
        return result;
    }

    V Value() const
    {
        V result = impl::empty_value<V>();
        check_hresult(shim()->get_Value(put(result)));
        return result;
    }

    bool operator==(const IKeyValuePair<K, V> & other) const
    {
        return Key() == other.Key() && Value() == other.Value();
    }

    bool operator!=(const IKeyValuePair<K, V> & other) const
    {
        return !(*this == other);
    }
};

template <typename D, typename T>
class impl_IVectorView
{
    auto shim() const { return impl::shim<D, IVectorView<T>>(this); }

public:

    T GetAt(const uint32_t index) const
    {
        T result = impl::empty_value<T>();
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

    uint32_t GetMany(uint32_t startIndex, array_ref<T> values) const
    {
        uint32_t actual = 0;
        check_hresult(shim()->abi_GetMany(startIndex, values.size(), get(values), &actual));
        return actual;
    }
};

template <typename D, typename T>
class impl_IVector
{
    auto shim() const { return impl::shim<D, IVector<T>>(this); }

public:

    T GetAt(const uint32_t index) const
    {
        T result = impl::empty_value<T>();
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

    void ReplaceAll(array_ref<const T> value) const
    {
        check_hresult(shim()->abi_ReplaceAll(value.size(), get(value)));
    }
};

template <typename D, typename K, typename V>
class impl_IMapView
{
    auto shim() const { return impl::shim<D, IMapView<K, V>>(this); }

public:

    V Lookup(const K & key) const
    {
        V result = impl::empty_value<V>();
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
class impl_IMap
{
    auto shim() const { return impl::shim<D, IMap<K, V>>(this); }

public:

    V Lookup(const K & key) const
    {
        V result = impl::empty_value<V>();
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
class impl_IMapChangedEventArgs
{
    auto shim() const { return impl::shim<D, IMapChangedEventArgs<K>>(this); }

public:

    CollectionChange CollectionChange() const
    {
        Collections::CollectionChange value{};
        check_hresult(shim()->get_CollectionChange(&value));
        return value;
    }

    K Key() const
    {
        K result = impl::empty_value<K>();
        check_hresult(shim()->get_Key(put(result)));
        return result;
    }
};

template <typename D, typename K, typename V>
class impl_IObservableMap
{
    auto shim() const { return impl::shim<D, IObservableMap<K, V>>(this); }

public:

    event_token MapChanged(const MapChangedEventHandler<K, V> & handler) const
    {
        event_token cookie {};
        check_hresult(shim()->add_MapChanged(get(handler), &cookie));
        return cookie;
    }

    void MapChanged(const event_token cookie) const
    {
        check_hresult(shim()->remove_MapChanged(cookie));
    }

    using MapChanged_revoker = event_revoker<IObservableMap<K, V>>;

    MapChanged_revoker MapChanged(auto_revoke_t, const MapChangedEventHandler<K, V> & handler) const
    {
        return impl::make_event_revoker<D, IObservableMap<K, V>>(this, &abi<IObservableMap<K, V>>::remove_MapChanged, MapChanged(handler));
    }
};

template <typename D, typename T>
class impl_IObservableVector
{
    auto shim() const { return impl::shim<D, IObservableVector<T>>(this); }

public:

    event_token VectorChanged(const VectorChangedEventHandler<T> & handler) const
    {
        event_token cookie {};
        check_hresult(shim()->add_VectorChanged(get(handler), &cookie));
        return cookie;
    }

    void VectorChanged(const event_token cookie) const
    {
        check_hresult(shim()->remove_VectorChanged(cookie));
    }

    using VectorChanged_revoker = event_revoker<IObservableVector<T>>;

    VectorChanged_revoker VectorChanged(auto_revoke_t, const VectorChangedEventHandler<T> & handler) const
    {
        return impl::make_event_revoker<D, IObservableVector<T>>(this, &abi<IObservableVector<T>>::remove_VectorChanged, VectorChanged(handler));
    }
};

}

namespace impl {

template <typename K, typename V> struct traits<Windows::Foundation::Collections::MapChangedEventHandler<K, V>>
{
    using abi = ABI::Windows::Foundation::Collections::MapChangedEventHandler<abi<K>, abi<V>>;
};

template <typename T> struct traits<Windows::Foundation::Collections::VectorChangedEventHandler<T>>
{
    using abi = ABI::Windows::Foundation::Collections::VectorChangedEventHandler<abi<T>>;
};

template <typename T> struct traits<Windows::Foundation::Collections::IIterator<T>>
{
    using abi = ABI::Windows::Foundation::Collections::IIterator<abi<T>>;
    template <typename D> using consume = Windows::Foundation::Collections::impl_IIterator<D, T>;
};

template <typename T> struct traits<Windows::Foundation::Collections::IIterable<T>>
{
    using abi = ABI::Windows::Foundation::Collections::IIterable<abi<T>>;
    template <typename D> using consume = Windows::Foundation::Collections::impl_IIterable<D, T>;
};

template <typename K, typename V> struct traits<Windows::Foundation::Collections::IKeyValuePair<K, V>>
{
    using abi = ABI::Windows::Foundation::Collections::IKeyValuePair<abi<K>, abi<V>>;
    template <typename D> using consume = Windows::Foundation::Collections::impl_IKeyValuePair<D, K, V>;
};

template <typename T> struct traits<Windows::Foundation::Collections::IVectorView<T>>
{
    using abi = ABI::Windows::Foundation::Collections::IVectorView<abi<T>>;
    template <typename D> using consume = Windows::Foundation::Collections::impl_IVectorView<D, T>;
};

template <typename T> struct traits<Windows::Foundation::Collections::IVector<T>>
{
    using abi = ABI::Windows::Foundation::Collections::IVector<abi<T>>;
    template <typename D> using consume = Windows::Foundation::Collections::impl_IVector<D, T>;
};

template <typename K, typename V> struct traits<Windows::Foundation::Collections::IMapView<K, V>>
{
    using abi = ABI::Windows::Foundation::Collections::IMapView<abi<K>, abi<V>>;
    template <typename D> using consume = Windows::Foundation::Collections::impl_IMapView<D, K, V>;
};

template <typename K, typename V> struct traits<Windows::Foundation::Collections::IMap<K, V>>
{
    using abi = ABI::Windows::Foundation::Collections::IMap<abi<K>, abi<V>>;
    template <typename D> using consume = Windows::Foundation::Collections::impl_IMap<D, K, V>;
};

template <typename K> struct traits<Windows::Foundation::Collections::IMapChangedEventArgs<K>>
{
    using abi = ABI::Windows::Foundation::Collections::IMapChangedEventArgs<abi<K>>;
    template <typename D> using consume = Windows::Foundation::Collections::impl_IMapChangedEventArgs<D, K>;
};

template <typename K, typename V> struct traits<Windows::Foundation::Collections::IObservableMap<K, V>>
{
    using abi = ABI::Windows::Foundation::Collections::IObservableMap<abi<K>, abi<V>>;
    template <typename D> using consume = Windows::Foundation::Collections::impl_IObservableMap<D, K, V>;
};

template <typename T> struct traits<Windows::Foundation::Collections::IObservableVector<T>>
{
    using abi = ABI::Windows::Foundation::Collections::IObservableVector<abi<T>>;
    template <typename D> using consume = Windows::Foundation::Collections::impl_IObservableVector<D, T>;
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

namespace Windows::Foundation::Collections {

template <typename T>
struct WINRT_EBO VectorChangedEventHandler : IUnknown
{
    VectorChangedEventHandler(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<VectorChangedEventHandler>(m_ptr); }
    template <typename L> VectorChangedEventHandler(L handler);
    template <typename F> VectorChangedEventHandler(F * handler);
    template <typename O, typename M> VectorChangedEventHandler(O * object, M method);
    void operator()(const IObservableVector<T> & sender, const IVectorChangedEventArgs & args) const;
};

template <typename K, typename V>
struct WINRT_EBO MapChangedEventHandler : IUnknown
{
    MapChangedEventHandler(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<MapChangedEventHandler>(m_ptr); }
    template <typename L> MapChangedEventHandler(L handler);
    template <typename F> MapChangedEventHandler(F * handler);
    template <typename O, typename M> MapChangedEventHandler(O * object, M method);
    void operator()(const IObservableMap<K, V> & sender, const IMapChangedEventArgs<K> & args) const;
};

template <typename T>
struct WINRT_EBO IIterator :
    IInspectable,
    impl::consume<IIterator<T>>
{
    IIterator(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IIterator>(m_ptr); }
};

template <typename T>
struct WINRT_EBO IIterable :
    IInspectable,
    impl::consume<IIterable<T>>
{
    IIterable(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IIterable>(m_ptr); }

    IIterable(std::vector<T> && values) : IIterable(make<impl::iterable<T, std::vector<T>>>(std::forward<std::vector<T>>(values)))
    {}

    template<class InputIt>
    IIterable(InputIt first, InputIt last) : IIterable(make<impl::iterable<T, std::vector<T>>>(first, last))
    {}

    IIterable(std::initializer_list<T> values) : IIterable(make<impl::iterable<T, std::vector<T>>>(values.begin(), values.end()))
    {}
};

template <typename K, typename V>
struct WINRT_EBO IIterable<IKeyValuePair<K, V>> :
    IInspectable,
    impl::consume<IIterable<IKeyValuePair<K, V>>>
{
    IIterable(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IIterable>(m_ptr); }

    IIterable(std::map<K, V> && values) : IIterable(make<impl::iterable<IKeyValuePair<K, V>, std::map<K, V>>>(std::forward<std::map<K, V>>(values)))
    {}

    IIterable(std::unordered_map<K, V> && values) : IIterable(make<impl::iterable<IKeyValuePair<K, V>, std::unordered_map<K, V>>>(std::forward<std::unordered_map<K, V>>(values)))
    {}

    template<class InputIt>
    IIterable(InputIt first, InputIt last) : IIterable(make<impl::iterable<IKeyValuePair<K, V>, std::unordered_map<K, V>>>(first, last))
    {}

    IIterable(std::initializer_list<std::pair<K, V>> values) : IIterable(make<impl::iterable<IKeyValuePair<K, V>, std::unordered_map<K, V>>>(values.begin(), values.end()))
    {}
};

template <typename K, typename V>
struct WINRT_EBO IKeyValuePair :
    IInspectable,
    impl::consume<IKeyValuePair<K, V>>
{
    IKeyValuePair(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IKeyValuePair>(m_ptr); }

private:
    IKeyValuePair(const std::pair<const K, V> & pair) : IKeyValuePair(make<impl::key_value_pair<K, V>>(pair.first, pair.second))
    {}

    template <typename T, typename containertype>
    friend struct impl::iterator;
    template <typename T, typename containertype>
    friend struct impl::iterator_standalone;
    template<class _InIt, class _Diff, class _OutIt> 
    friend _OutIt std::_Copy_n_unchecked2(_InIt _First, _Diff _Count, _OutIt _Dest, forward_iterator_tag);
};

template <typename T>
struct WINRT_EBO IVectorView :
    IInspectable,
    impl::consume<IVectorView<T>>,
    impl::require<IVectorView<T>, IIterable<T>>
{
    IVectorView(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IVectorView>(m_ptr); }

    IVectorView(std::vector<T> && values) : IVectorView(make<impl::vector_view_standalone<T>>(std::forward<std::vector<T>>(values)))
    {}

    template<class InputIt>
    IVectorView(InputIt first, InputIt last) : IVectorView(make<impl::vector_view_standalone<T>>(first, last))
    {}

    IVectorView(std::initializer_list<T> values) : IVectorView(make<impl::vector_view_standalone<T>>(values.begin(), values.end()))
    {}
};

template <typename T>
struct WINRT_EBO IVector :
    IInspectable,
    impl::consume<IVector<T>>,
    impl::require<IVector<T>, IIterable<T>>
{
    IVector(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IVector>(m_ptr); }

    IVector(std::vector<T> && values) : IVector(make<impl::vector<T>>(std::forward<std::vector<T>>(values)))
    {}

    template<class InputIt>
    IVector(InputIt first, InputIt last) : IVector(make<impl::vector<T>>(first, last))
    {}

    IVector(std::initializer_list<T> values) : IVector(make<impl::vector<T>>(values.begin(), values.end()))
    {}
};

template <typename K, typename V>
struct WINRT_EBO IMapView :
    IInspectable,
    impl::consume<IMapView<K, V>>,
    impl::require<IMapView<K, V>, IIterable<IKeyValuePair<K, V>>>
{
    IMapView(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IMapView>(m_ptr); }

    IMapView(std::map<K, V> && values) : IMapView(make<impl::map_view_standalone<K, V, std::map<K, V>>>(std::forward<std::map<K, V>>(values)))
    {}

    IMapView(std::unordered_map<K, V> && values) : IMapView(make<impl::map_view_standalone<K, V, std::unordered_map<K, V>>>(std::forward<std::unordered_map<K, V>>(values)))
    {}

    template<class InputIt>
    IMapView(InputIt first, InputIt last) : IMapView(make<impl::map_view_standalone<K, V, std::unordered_map<K, V>>>(first, last))
    {}

    IMapView(std::initializer_list<std::pair<K, V>> values) : IMapView(make<impl::map_view_standalone<K, V, std::unordered_map<K, V>>>(values.begin(), values.end()))
    {}
};

template <typename K, typename V>
struct WINRT_EBO IMap :
    IInspectable,
    impl::consume<IMap<K, V>>,
    impl::require<IMap<K, V>, IIterable<IKeyValuePair<K, V>>>
{
    IMap(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IMap>(m_ptr); }

    IMap(std::map<K, V> && values) : IMap(make<impl::map<K, V, std::map<K, V>>>(std::forward<std::map<K, V>>(values)))
    {}

    IMap(std::unordered_map<K, V> && values) : IMap(make<impl::map<K, V, std::unordered_map<K, V>>>(std::forward<std::unordered_map<K, V>>(values)))
    {}

    template<class InputIt>
    IMap(InputIt first, InputIt last) : IMap(make<impl::map<K, V, std::unordered_map<K, V>>>(first, last))
    {}

    IMap(std::initializer_list<std::pair<K, V>> values) : IMap(make<impl::map<K, V, std::unordered_map<K, V>>>(values.begin(), values.end()))
    {}
};

template <typename K>
struct WINRT_EBO IMapChangedEventArgs :
    IInspectable,
    impl::consume<IMapChangedEventArgs<K>>
{
    IMapChangedEventArgs(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IMapChangedEventArgs>(m_ptr); }
};

template <typename K, typename V>
struct WINRT_EBO IObservableMap :
    IInspectable,
    impl::consume<IObservableMap<K, V>>,
    impl::require<IObservableMap<K, V>, IMap<K, V>, IIterable<IKeyValuePair<K, V>>>
{
    IObservableMap(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IObservableMap>(m_ptr); }
};

template <typename T>
struct WINRT_EBO IObservableVector :
    IInspectable,
    impl::consume<IObservableVector<T>>,
    impl::require<IObservableVector<T>, IVector<T>, IIterable<T>>
{
    IObservableVector(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IObservableVector>(m_ptr); }
};

}

namespace impl {

template <typename K, typename V, typename H>
struct map_changed_event_handler : implements<map_changed_event_handler<K, V, H>, abi<Windows::Foundation::Collections::MapChangedEventHandler<K, V>>>, H
{
    map_changed_event_handler(H && handler) : H(std::forward<H>(handler)) {}

    HRESULT __stdcall abi_Invoke(abi_arg_in<Windows::Foundation::Collections::IObservableMap<K, V>> sender, abi_arg_in<Windows::Foundation::Collections::IMapChangedEventArgs<K>> args) noexcept override
    {
        try
        {
            (*this)(*reinterpret_cast<const Windows::Foundation::Collections::IObservableMap<K, V> *>(&sender), *reinterpret_cast<const Windows::Foundation::Collections::IMapChangedEventArgs<K> *>(&args));
            return S_OK;
        }
        catch (...) { return impl::to_hresult(); }
    }
};

template <typename T, typename H>
struct vector_changed_event_handler : implements<vector_changed_event_handler<T, H>, abi<Windows::Foundation::Collections::VectorChangedEventHandler<T>>>, H
{
    vector_changed_event_handler(H && handler) : H(std::forward<H>(handler)) {}

    HRESULT __stdcall abi_Invoke(abi_arg_in<Windows::Foundation::Collections::IObservableVector<T>> sender, abi_arg_in<Windows::Foundation::Collections::IVectorChangedEventArgs> args) noexcept override
    {
        try
        {
            (*this)(*reinterpret_cast<const Windows::Foundation::Collections::IObservableVector<T> *>(&sender), *reinterpret_cast<const Windows::Foundation::Collections::IVectorChangedEventArgs *>(&args));
            return S_OK;
        }
        catch (...) { return impl::to_hresult(); }
    }
};

}

namespace Windows::Foundation::Collections {

template <typename K, typename V> template <typename L> MapChangedEventHandler<K, V>::MapChangedEventHandler(L handler) :
    MapChangedEventHandler(impl::make_delegate<impl::map_changed_event_handler<K, V, L>, MapChangedEventHandler<K, V>>(std::forward<L>(handler)))
{}

template <typename K, typename V> template <typename F> MapChangedEventHandler<K, V>::MapChangedEventHandler(F * handler) :
    MapChangedEventHandler([=](auto && ... args) { handler(args ...); })
{}

template <typename K, typename V> template <typename O, typename M> MapChangedEventHandler<K, V>::MapChangedEventHandler(O * object, M method) :
    MapChangedEventHandler([=](auto && ... args) { ((*object).*(method))(args ...); })
{}

template <typename K, typename V> void MapChangedEventHandler<K, V>::operator()(const IObservableMap<K, V> & sender, const IMapChangedEventArgs<K> & args) const
{
    check_hresult((*this)->abi_Invoke(get(sender), get(args)));
}

template <typename T> template <typename L> VectorChangedEventHandler<T>::VectorChangedEventHandler(L handler) :
    VectorChangedEventHandler(impl::make_delegate<impl::vector_changed_event_handler<T, L>, VectorChangedEventHandler<T>>(std::forward<L>(handler)))
{}

template <typename T> template <typename F> VectorChangedEventHandler<T>::VectorChangedEventHandler(F * handler) :
    VectorChangedEventHandler([=](auto && ... args) { handler(args ...); })
{}

template <typename T> template <typename O, typename M> VectorChangedEventHandler<T>::VectorChangedEventHandler(O * object, M method) :
    VectorChangedEventHandler([=](auto && ... args) { ((*object).*(method))(args ...); })
{}

template <typename T> void VectorChangedEventHandler<T>::operator()(const IObservableVector<T> & sender, const IVectorChangedEventArgs & args) const
{
    check_hresult((*this)->abi_Invoke(get(sender), get(args)));
}

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

}
