
namespace winrt::impl
{
    template <typename D>
    struct produce<D, wfc::IVectorChangedEventArgs> : produce_base<D, wfc::IVectorChangedEventArgs>
    {
        HRESULT __stdcall get_CollectionChange(wfc::CollectionChange* value) noexcept final
        {
            try
            {
                typename D::abi_guard guard(this->shim());
                *value = this->shim().CollectionChange();
                return S_OK;
            }
            catch (...)
            {
                return to_hresult();
            }
        }

        HRESULT __stdcall get_Index(uint32_t* value) noexcept final
        {
            try
            {
                typename D::abi_guard guard(this->shim());
                *value = this->shim().Index();
                return S_OK;
            }
            catch (...)
            {
                return to_hresult();
            }
        }
    };

    template <typename D, typename T>
    struct produce<D, wfc::IIterator<T>> : produce_base<D, wfc::IIterator<T>>
    {
        HRESULT __stdcall get_Current(arg_out<T> current) noexcept final
        {
            try
            {
                typename D::abi_guard guard(this->shim());
                *current = detach_abi(this->shim().Current());
                return S_OK;
            }
            catch (...)
            {
                clear_abi(current);
                return to_hresult();
            }
        }

        HRESULT __stdcall get_HasCurrent(bool* hasCurrent) noexcept final
        {
            try
            {
                typename D::abi_guard guard(this->shim());
                *hasCurrent = this->shim().HasCurrent();
                return S_OK;
            }
            catch (...)
            {
                return to_hresult();
            }
        }

        HRESULT __stdcall MoveNext(bool* hasCurrent) noexcept final
        {
            try
            {
                typename D::abi_guard guard(this->shim());
                *hasCurrent = this->shim().MoveNext();
                return S_OK;
            }
            catch (...)
            {
                return to_hresult();
            }
        }

        HRESULT __stdcall GetMany(uint32_t capacity, arg_out<T> value, uint32_t* actual) noexcept final
        {
            try
            {
                typename D::abi_guard guard(this->shim());
                *actual = this->shim().GetMany({ reinterpret_cast<T*>(value), reinterpret_cast<T*>(value) + capacity });
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
    struct produce<D, wfc::IIterable<T>> : produce_base<D, wfc::IIterable<T>>
    {
        HRESULT __stdcall First(arg_out<wfc::IIterator<T>> first) noexcept final
        {
            try
            {
                typename D::abi_guard guard(this->shim());
                *first = detach_abi(this->shim().First());
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
    struct produce<D, wfc::IKeyValuePair<K, V>> : produce_base<D, wfc::IKeyValuePair<K, V>>
    {
        HRESULT __stdcall get_Key(arg_out<K> key) noexcept final
        {
            try
            {
                typename D::abi_guard guard(this->shim());
                *key = detach_abi(this->shim().Key());
                return S_OK;
            }
            catch (...)
            {
                clear_abi(key);
                return to_hresult();
            }
        }

        HRESULT __stdcall get_Value(arg_out<V> value) noexcept final
        {
            try
            {
                typename D::abi_guard guard(this->shim());
                *value = detach_abi(this->shim().Value());
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
    struct produce<D, wfc::IVectorView<T>> : produce_base<D, wfc::IVectorView<T>>
    {
        HRESULT __stdcall GetAt(uint32_t index, arg_out<T> item) noexcept final
        {
            try
            {
                typename D::abi_guard guard(this->shim());
                *item = detach_abi(this->shim().GetAt(index));
                return S_OK;
            }
            catch (...)
            {
                clear_abi(item);
                return to_hresult();
            }
        }

        HRESULT __stdcall get_Size(uint32_t* size) noexcept final
        {
            try
            {
                typename D::abi_guard guard(this->shim());
                *size = this->shim().Size();
                return S_OK;
            }
            catch (...)
            {
                return to_hresult();
            }
        }

        HRESULT __stdcall IndexOf(arg_in<T> value, uint32_t* index, bool* found) noexcept final
        {
            try
            {
                typename D::abi_guard guard(this->shim());
                *found = this->shim().IndexOf(*reinterpret_cast<T const*>(&value), *index);
                return S_OK;
            }
            catch (...)
            {
                return to_hresult();
            }
        }

        HRESULT __stdcall GetMany(uint32_t startIndex, uint32_t capacity, arg_out<T> value, uint32_t* actual) noexcept final
        {
            try
            {
                typename D::abi_guard guard(this->shim());
                *actual = this->shim().GetMany(startIndex, { reinterpret_cast<T*>(value), reinterpret_cast<T*>(value) + capacity });
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
    struct produce<D, wfc::IVector<T>> : produce_base<D, wfc::IVector<T>>
    {
        HRESULT __stdcall GetAt(uint32_t index, arg_out<T> item) noexcept final
        {
            try
            {
                typename D::abi_guard guard(this->shim());
                *item = detach_abi(this->shim().GetAt(index));
                return S_OK;
            }
            catch (...)
            {
                clear_abi(item);
                return to_hresult();
            }
        }

        HRESULT __stdcall get_Size(uint32_t* size) noexcept final
        {
            try
            {
                typename D::abi_guard guard(this->shim());
                *size = this->shim().Size();
                return S_OK;
            }
            catch (...)
            {
                return to_hresult();
            }
        }

        HRESULT __stdcall GetView(::IUnknown** view) noexcept final
        {
            try
            {
                typename D::abi_guard guard(this->shim());
                *view = detach_abi(this->shim().GetView());
                return S_OK;
            }
            catch (...)
            {
                *view = nullptr;
                return to_hresult();
            }
        }

        HRESULT __stdcall IndexOf(arg_in<T> value, uint32_t* index, bool* found) noexcept final
        {
            try
            {
                typename D::abi_guard guard(this->shim());
                *found = this->shim().IndexOf(*reinterpret_cast<T const*>(&value), *index);
                return S_OK;
            }
            catch (...)
            {
                return to_hresult();
            }
        }

        HRESULT __stdcall SetAt(uint32_t index, arg_in<T> item) noexcept final
        {
            try
            {
                typename D::abi_guard guard(this->shim());
                this->shim().SetAt(index, *reinterpret_cast<T const*>(&item));
                return S_OK;
            }
            catch (...)
            {
                return to_hresult();
            }
        }

        HRESULT __stdcall InsertAt(uint32_t index, arg_in<T> item) noexcept final
        {
            try
            {
                typename D::abi_guard guard(this->shim());
                this->shim().InsertAt(index, *reinterpret_cast<T const*>(&item));
                return S_OK;
            }
            catch (...)
            {
                return to_hresult();
            }
        }

        HRESULT __stdcall RemoveAt(uint32_t index) noexcept final
        {
            try
            {
                typename D::abi_guard guard(this->shim());
                this->shim().RemoveAt(index);
                return S_OK;
            }
            catch (...)
            {
                return to_hresult();
            }
        }

        HRESULT __stdcall Append(arg_in<T> item) noexcept final
        {
            try
            {
                typename D::abi_guard guard(this->shim());
                this->shim().Append(*reinterpret_cast<T const*>(&item));
                return S_OK;
            }
            catch (...)
            {
                return to_hresult();
            }
        }

        HRESULT __stdcall RemoveAtEnd() noexcept final
        {
            try
            {
                typename D::abi_guard guard(this->shim());
                this->shim().RemoveAtEnd();
                return S_OK;
            }
            catch (...)
            {
                return to_hresult();
            }
        }

        HRESULT __stdcall Clear() noexcept final
        {
            try
            {
                typename D::abi_guard guard(this->shim());
                this->shim().Clear();
                return S_OK;
            }
            catch (...)
            {
                return to_hresult();
            }
        }

        HRESULT __stdcall GetMany(uint32_t startIndex, uint32_t capacity, arg_out<T> value, uint32_t* actual) noexcept final
        {
            try
            {
                typename D::abi_guard guard(this->shim());
                *actual = this->shim().GetMany(startIndex, { reinterpret_cast<T*>(value), reinterpret_cast<T*>(value) + capacity });
                return S_OK;
            }
            catch (...)
            {
                clear_abi(value);
                *actual = 0;
                return to_hresult();
            }
        }

        HRESULT __stdcall ReplaceAll(uint32_t count, arg_out<T> item) noexcept final
        {
            try
            {
                typename D::abi_guard guard(this->shim());
                this->shim().ReplaceAll({ reinterpret_cast<T const*>(item), reinterpret_cast<T const*>(item) + count });
                return S_OK;
            }
            catch (...)
            {
                return to_hresult();
            }
        }
    };

    template <typename D, typename K, typename V>
    struct produce<D, wfc::IMapView<K, V>> : produce_base<D, wfc::IMapView<K, V>>
    {
        HRESULT __stdcall Lookup(arg_in<K> key, arg_out<V> value) noexcept final
        {
            try
            {
                typename D::abi_guard guard(this->shim());
                *value = detach_abi(this->shim().Lookup(*reinterpret_cast<K const*>(&key)));
                return S_OK;
            }
            catch (...)
            {
                clear_abi(value);
                return to_hresult();
            }
        }

        HRESULT __stdcall get_Size(uint32_t* size) noexcept final
        {
            try
            {
                typename D::abi_guard guard(this->shim());
                *size = this->shim().Size();
                return S_OK;
            }
            catch (...)
            {
                return to_hresult();
            }
        }

        HRESULT __stdcall HasKey(arg_in<K> key, bool* found) noexcept final
        {
            try
            {
                typename D::abi_guard guard(this->shim());
                *found = this->shim().HasKey(*reinterpret_cast<K const*>(&key));
                return S_OK;
            }
            catch (...)
            {
                return to_hresult();
            }
        }

        HRESULT __stdcall Split(arg_out<wfc::IMapView<K, V>> firstPartition, arg_out<wfc::IMapView<K, V>> secondPartition) noexcept final
        {
            try
            {
                typename D::abi_guard guard(this->shim());
                this->shim().Split(*reinterpret_cast<wfc::IMapView<K, V>*>(firstPartition), *reinterpret_cast<wfc::IMapView<K, V>*>(secondPartition));
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
    struct produce<D, wfc::IMap<K, V>> : produce_base<D, wfc::IMap<K, V>>
    {
        HRESULT __stdcall Lookup(arg_in<K> key, arg_out<V> value) noexcept final
        {
            try
            {
                typename D::abi_guard guard(this->shim());
                *value = detach_abi(this->shim().Lookup(*reinterpret_cast<K const*>(&key)));
                return S_OK;
            }
            catch (...)
            {
                clear_abi(value);
                return to_hresult();
            }
        }

        HRESULT __stdcall get_Size(uint32_t* size) noexcept final
        {
            try
            {
                typename D::abi_guard guard(this->shim());
                *size = this->shim().Size();
                return S_OK;
            }
            catch (...)
            {
                return to_hresult();
            }
        }

        HRESULT __stdcall HasKey(arg_in<K> key, bool* found) noexcept final
        {
            try
            {
                typename D::abi_guard guard(this->shim());
                *found = this->shim().HasKey(*reinterpret_cast<K const*>(&key));
                return S_OK;
            }
            catch (...)
            {
                return to_hresult();
            }
        }

        HRESULT __stdcall GetView(arg_out<wfc::IMapView<K, V>> view) noexcept final
        {
            try
            {
                typename D::abi_guard guard(this->shim());
                *view = detach_abi(this->shim().GetView());
                return S_OK;
            }
            catch (...)
            {
                *view = nullptr;
                return to_hresult();
            }
        }

        HRESULT __stdcall Insert(arg_in<K> key, arg_in<V> value, bool* replaced) noexcept final
        {
            try
            {
                typename D::abi_guard guard(this->shim());
                *replaced = this->shim().Insert(*reinterpret_cast<K const*>(&key), *reinterpret_cast<V const*>(&value));
                return S_OK;
            }
            catch (...)
            {
                return to_hresult();
            }
        }

        HRESULT __stdcall Remove(arg_in<K> key) noexcept final
        {
            try
            {
                typename D::abi_guard guard(this->shim());
                this->shim().Remove(*reinterpret_cast<K const*>(&key));
                return S_OK;
            }
            catch (...)
            {
                return to_hresult();
            }
        }

        HRESULT __stdcall Clear() noexcept final
        {
            try
            {
                typename D::abi_guard guard(this->shim());
                this->shim().Clear();
                return S_OK;
            }
            catch (...)
            {
                return to_hresult();
            }
        }
    };

    template <typename D, typename K>
    struct produce<D, wfc::IMapChangedEventArgs<K>> : produce_base<D, wfc::IMapChangedEventArgs<K>>
    {
        HRESULT __stdcall get_CollectionChange(wfc::CollectionChange* value) noexcept final
        {
            try
            {
                typename D::abi_guard guard(this->shim());
                *value = this->shim().CollectionChange();
                return S_OK;
            }
            catch (...)
            {
                return to_hresult();
            }
        }

        HRESULT __stdcall get_Key(arg_out<K> value) noexcept final
        {
            try
            {
                typename D::abi_guard guard(this->shim());
                *value = detach_abi(this->shim().Key());
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
    struct produce<D, wfc::IObservableMap<K, V>> : produce_base<D, wfc::IObservableMap<K, V>>
    {
        HRESULT __stdcall add_MapChanged(arg_in<wfc::MapChangedEventHandler<K, V>> handler, event_token* token) noexcept final
        {
            try
            {
                typename D::abi_guard guard(this->shim());
                *token = this->shim().MapChanged(*reinterpret_cast<wfc::MapChangedEventHandler<K, V> const*>(&handler));
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
                typename D::abi_guard guard(this->shim());
                this->shim().MapChanged(token);
                return S_OK;
            }
            catch (...)
            {
                return to_hresult();
            }
        }
    };

    template <typename D, typename T>
    struct produce<D, wfc::IObservableVector<T>> : produce_base<D, wfc::IObservableVector<T>>
    {
        HRESULT __stdcall add_VectorChanged(arg_in<wfc::VectorChangedEventHandler<T>> handler, event_token* token) noexcept final
        {
            try
            {
                typename D::abi_guard guard(this->shim());
                *token = this->shim().VectorChanged(*reinterpret_cast<wfc::VectorChangedEventHandler<T> const*>(&handler));
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
                typename D::abi_guard guard(this->shim());
                this->shim().VectorChanged(token);
                return S_OK;
            }
            catch (...)
            {
                return to_hresult();
            }
        }
    };
}
