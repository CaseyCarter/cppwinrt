
namespace impl {

template <typename D>
struct produce<D, Windows::Foundation::Collections::IVectorChangedEventArgs> : produce_base<D, Windows::Foundation::Collections::IVectorChangedEventArgs>
{
    HRESULT __stdcall get_CollectionChange(Windows::Foundation::Collections::CollectionChange * value) noexcept final
    {
        try
        {
            *value = shim().CollectionChange();
            return S_OK;
        }
        catch (...)
        {
            return to_hresult();
        }
    }

    HRESULT __stdcall get_Index(uint32_t * value) noexcept final
    {
        try
        {
            *value = shim().Index();
            return S_OK;
        }
        catch (...)
        {
            return to_hresult();
        }
    }
};

template <typename D, typename T>
struct produce<D, Windows::Foundation::Collections::IIterator<T>> : produce_base<D, Windows::Foundation::Collections::IIterator<T>>
{
    HRESULT __stdcall get_Current(abi_arg_out<T> current) noexcept final
    {
        try
        {
            *current = detach(shim().Current());
            return S_OK;
        }
        catch (...)
        {
            clear_abi(current);
            return to_hresult();
        }
    }

    HRESULT __stdcall get_HasCurrent(bool * hasCurrent) noexcept final
    {
        try
        {
            *hasCurrent = shim().HasCurrent();
            return S_OK;
        }
        catch (...)
        {
            return to_hresult();
        }
    }

    HRESULT __stdcall abi_MoveNext(bool * hasCurrent) noexcept final
    {
        try
        {
            *hasCurrent = shim().MoveNext();
            return S_OK;
        }
        catch (...)
        {
            return to_hresult();
        }
    }

    HRESULT __stdcall abi_GetMany(uint32_t capacity, abi_arg_out<T> value, uint32_t * actual) noexcept final
    {
        try
        {
            *actual = shim().GetMany({ reinterpret_cast<T *>(value), reinterpret_cast<T *>(value) + capacity });
            return S_OK;
        }
        catch (...)
        {
            clear_abi(value);
            *actual = 0;
            return to_hresult();
        }
    }
};

template <typename D, typename T>
struct produce<D, Windows::Foundation::Collections::IIterable<T>> : produce_base<D, Windows::Foundation::Collections::IIterable<T>>
{
    HRESULT __stdcall abi_First(abi_arg_out<Windows::Foundation::Collections::IIterator<T>> first) noexcept final
    {
        try
        {
            *first = detach(shim().First());
            return S_OK;
        }
        catch (...)
        {
            *first = nullptr;
            return to_hresult();
        }
    }
};

template <typename D, typename K, typename V>
struct produce<D, Windows::Foundation::Collections::IKeyValuePair<K, V>> : produce_base<D, Windows::Foundation::Collections::IKeyValuePair<K, V>>
{
    HRESULT __stdcall get_Key(abi_arg_out<K> key) noexcept final
    {
        try
        {
            *key = detach(shim().Key());
            return S_OK;
        }
        catch (...)
        {
            clear_abi(key);
            return to_hresult();
        }
    }

    HRESULT __stdcall get_Value(abi_arg_out<V> value) noexcept final
    {
        try
        {
            *value = detach(shim().Value());
            return S_OK;
        }
        catch (...)
        {
            clear_abi(value);
            return to_hresult();
        }
    }
};

template <typename D, typename T>
struct produce<D, Windows::Foundation::Collections::IVectorView<T>> : produce_base<D, Windows::Foundation::Collections::IVectorView<T>>
{
    HRESULT __stdcall abi_GetAt(uint32_t index, abi_arg_out<T> item) noexcept final
    {
        try
        {
            *item = detach(shim().GetAt(index));
            return S_OK;
        }
        catch (...)
        {
            clear_abi(item);
            return to_hresult();
        }
    }

    HRESULT __stdcall get_Size(uint32_t * size) noexcept final
    {
        try
        {
            *size = shim().Size();
            return S_OK;
        }
        catch (...)
        {
            return to_hresult();
        }
    }

    HRESULT __stdcall abi_IndexOf(abi_arg_in<T> value, uint32_t * index, bool * found) noexcept final
    {
        try
        {
            *found = shim().IndexOf(*reinterpret_cast<const T *>(&value), *index);
            return S_OK;
        }
        catch (...)
        {
            return to_hresult();
        }
    }

    HRESULT __stdcall abi_GetMany(uint32_t startIndex, uint32_t capacity, abi_arg_out<T> value, uint32_t * actual) noexcept final
    {
        try
        {
            *actual = shim().GetMany(startIndex, { reinterpret_cast<T *>(value), reinterpret_cast<T *>(value) + capacity });
            return S_OK;
        }
        catch (...)
        {
            clear_abi(value);
            *actual = 0;
            return to_hresult();
        }
    }
};

template <typename D, typename T>
struct produce<D, Windows::Foundation::Collections::IVector<T>> : produce_base<D, Windows::Foundation::Collections::IVector<T>>
{
    HRESULT __stdcall abi_GetAt(uint32_t index, abi_arg_out<T> item) noexcept final
    {
        try
        {
            *item = detach(shim().GetAt(index));
            return S_OK;
        }
        catch (...)
        {
            clear_abi(item);
            return to_hresult();
        }
    }

    HRESULT __stdcall get_Size(uint32_t * size) noexcept final
    {
        try
        {
            *size = shim().Size();
            return S_OK;
        }
        catch (...)
        {
            return to_hresult();
        }
    }

    HRESULT __stdcall abi_GetView(abi_arg_out<Windows::Foundation::Collections::IVectorView<T>> view) noexcept final
    {
        try
        {
            *view = detach(shim().GetView());
            return S_OK;
        }
        catch (...)
        {
            *view = nullptr;
            return to_hresult();
        }
    }

    HRESULT __stdcall abi_IndexOf(abi_arg_in<T> value, uint32_t * index, bool * found) noexcept final
    {
        try
        {
            *found = shim().IndexOf(*reinterpret_cast<const T *>(&value), *index);
            return S_OK;
        }
        catch (...)
        {
            return to_hresult();
        }
    }

    HRESULT __stdcall abi_SetAt(uint32_t index, abi_arg_in<T> item) noexcept final
    {
        try
        {
            shim().SetAt(index, *reinterpret_cast<const T *>(&item));
            return S_OK;
        }
        catch (...)
        {
            return to_hresult();
        }
    }

    HRESULT __stdcall abi_InsertAt(uint32_t index, abi_arg_in<T> item) noexcept final
    {
        try
        {
            shim().InsertAt(index, *reinterpret_cast<const T *>(&item));
            return S_OK;
        }
        catch (...)
        {
            return to_hresult();
        }
    }

    HRESULT __stdcall abi_RemoveAt(uint32_t index) noexcept final
    {
        try
        {
            shim().RemoveAt(index);
            return S_OK;
        }
        catch (...)
        {
            return to_hresult();
        }
    }

    HRESULT __stdcall abi_Append(abi_arg_in<T> item) noexcept final
    {
        try
        {
            shim().Append(*reinterpret_cast<const T *>(&item));
            return S_OK;
        }
        catch (...)
        {
            return to_hresult();
        }
    }

    HRESULT __stdcall abi_RemoveAtEnd() noexcept final
    {
        try
        {
            shim().RemoveAtEnd();
            return S_OK;
        }
        catch (...)
        {
            return to_hresult();
        }
    }

    HRESULT __stdcall abi_Clear() noexcept final
    {
        try
        {
            shim().Clear();
            return S_OK;
        }
        catch (...)
        {
            return to_hresult();
        }
    }

    HRESULT __stdcall abi_GetMany(uint32_t startIndex, uint32_t capacity, abi_arg_out<T> value, uint32_t * actual) noexcept final
    {
        try
        {
            *actual = shim().GetMany(startIndex, { reinterpret_cast<T *>(value), reinterpret_cast<T *>(value) + capacity });
            return S_OK;
        }
        catch (...)
        {
            clear_abi(value);
            *actual = 0;
            return to_hresult();
        }
    }

    HRESULT __stdcall abi_ReplaceAll(uint32_t count, abi_arg_out<T> item) noexcept final
    {
        try
        {
            shim().ReplaceAll({ reinterpret_cast<T const *>(item), reinterpret_cast<T const *>(item) + count });
            return S_OK;
        }
        catch (...)
        {
            return to_hresult();
        }
    }
};

template <typename D, typename K, typename V>
struct produce<D, Windows::Foundation::Collections::IMapView<K, V>> : produce_base<D, Windows::Foundation::Collections::IMapView<K, V>>
{
    HRESULT __stdcall abi_Lookup(abi_arg_in<K> key, abi_arg_out<V> value) noexcept final
    {
        try
        {
            *value = detach(shim().Lookup(*reinterpret_cast<const K *>(&key)));
            return S_OK;
        }
        catch (...)
        {
            clear_abi(value);
            return to_hresult();
        }
    }

    HRESULT __stdcall get_Size(uint32_t * size) noexcept final
    {
        try
        {
            *size = shim().Size();
            return S_OK;
        }
        catch (...)
        {
            return to_hresult();
        }
    }

    HRESULT __stdcall abi_HasKey(abi_arg_in<K> key, bool * found) noexcept final
    {
        try
        {
            *found = shim().HasKey(*reinterpret_cast<const K *>(&key));
            return S_OK;
        }
        catch (...)
        {
            return to_hresult();
        }
    }

    HRESULT __stdcall abi_Split(abi_arg_out<Windows::Foundation::Collections::IMapView<K, V>> firstPartition, abi_arg_out<Windows::Foundation::Collections::IMapView<K, V>> secondPartition) noexcept final
    {
        try
        {
            shim().Split(*reinterpret_cast<Windows::Foundation::Collections::IMapView<K, V> *>(firstPartition), *reinterpret_cast<Windows::Foundation::Collections::IMapView<K, V> *>(secondPartition));
            return S_OK;
        }
        catch (...)
        {
            *firstPartition = nullptr;
            *secondPartition = nullptr;
            return to_hresult();
        }
    }
};

template <typename D, typename K, typename V>
struct produce<D, Windows::Foundation::Collections::IMap<K, V>> : produce_base<D, Windows::Foundation::Collections::IMap<K, V>>
{
    HRESULT __stdcall abi_Lookup(abi_arg_in<K> key, abi_arg_out<V> value) noexcept final
    {
        try
        {
            *value = detach(shim().Lookup(*reinterpret_cast<const K *>(&key)));
            return S_OK;
        }
        catch (...)
        {
            clear_abi(value);
            return to_hresult();
        }
    }

    HRESULT __stdcall get_Size(uint32_t * size) noexcept final
    {
        try
        {
            *size = shim().Size();
            return S_OK;
        }
        catch (...)
        {
            return to_hresult();
        }
    }

    HRESULT __stdcall abi_HasKey(abi_arg_in<K> key, bool * found) noexcept final
    {
        try
        {
            *found = shim().HasKey(*reinterpret_cast<const K *>(&key));
            return S_OK;
        }
        catch (...)
        {
            return to_hresult();
        }
    }

    HRESULT __stdcall abi_GetView(abi_arg_out<Windows::Foundation::Collections::IMapView<K, V>> view) noexcept final
    {
        try
        {
            *view = detach(shim().GetView());
            return S_OK;
        }
        catch (...)
        {
            *view = nullptr;
            return to_hresult();
        }
    }

    HRESULT __stdcall abi_Insert(abi_arg_in<K> key, abi_arg_in<V> value, bool * replaced) noexcept final
    {
        try
        {
            *replaced = shim().Insert(*reinterpret_cast<const K *>(&key), *reinterpret_cast<const V *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return to_hresult();
        }
    }

    HRESULT __stdcall abi_Remove(abi_arg_in<K> key) noexcept final
    {
        try
        {
            shim().Remove(*reinterpret_cast<const K *>(&key));
            return S_OK;
        }
        catch (...)
        {
            return to_hresult();
        }
    }

    HRESULT __stdcall abi_Clear() noexcept final
    {
        try
        {
            shim().Clear();
            return S_OK;
        }
        catch (...)
        {
            return to_hresult();
        }
    }
};

template <typename D, typename K>
struct produce<D, Windows::Foundation::Collections::IMapChangedEventArgs<K>> : produce_base<D, Windows::Foundation::Collections::IMapChangedEventArgs<K>>
{
    HRESULT __stdcall get_CollectionChange(winrt::Windows::Foundation::Collections::CollectionChange * value) noexcept final
    {
        try
        {
            *value = shim().CollectionChange();
            return S_OK;
        }
        catch (...)
        {
            return to_hresult();
        }
    }

    HRESULT __stdcall get_Key(abi_arg_out<K> value) noexcept final
    {
        try
        {
            *value = detach(shim().Key());
            return S_OK;
        }
        catch (...)
        {
            clear_abi(value);
            return to_hresult();
        }
    }
};

template <typename D, typename K, typename V>
struct produce<D, Windows::Foundation::Collections::IObservableMap<K, V>> : produce_base<D, Windows::Foundation::Collections::IObservableMap<K, V>>
{
    HRESULT __stdcall add_MapChanged(abi_arg_in<Windows::Foundation::Collections::MapChangedEventHandler<K, V>> handler, event_token * token) noexcept final
    {
        try
        {
            *token = shim().MapChanged(*reinterpret_cast<const Windows::Foundation::Collections::MapChangedEventHandler<K, V> *>(&handler));
            return S_OK;
        }
        catch (...)
        {
            return to_hresult();
        }
    }

    HRESULT __stdcall remove_MapChanged(event_token token) noexcept final
    {
        try
        {
            shim().MapChanged(token);
            return S_OK;
        }
        catch (...)
        {
            return to_hresult();
        }
    }
};

template <typename D, typename T>
struct produce<D, Windows::Foundation::Collections::IObservableVector<T>> : produce_base<D, Windows::Foundation::Collections::IObservableVector<T>>
{
    HRESULT __stdcall add_VectorChanged(abi_arg_in<Windows::Foundation::Collections::VectorChangedEventHandler<T>> handler, event_token * token) noexcept final
    {
        try
        {
            *token = shim().VectorChanged(*reinterpret_cast<const Windows::Foundation::Collections::VectorChangedEventHandler<T> *>(&handler));
            return S_OK;
        }
        catch (...)
        {
            return to_hresult();
        }
    }

    HRESULT __stdcall remove_VectorChanged(event_token token) noexcept final
    {
        try
        {
            shim().VectorChanged(token);
            return S_OK;
        }
        catch (...)
        {
            return to_hresult();
        }
    }
};

}