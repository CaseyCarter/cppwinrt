
WINRT_EXPORT namespace winrt::Windows::Foundation::Collections
{
    enum class CollectionChange : int32_t
    {
        Reset,
        ItemInserted,
        ItemRemoved,
        ItemChanged,
    };

    struct IVectorChangedEventArgs;
    template <typename K> struct IMapChangedEventArgs;

    template <typename T> struct VectorChangedEventHandler;
    template <typename K, typename V> struct MapChangedEventHandler;

    template <typename T> struct IIterator;
    template <typename T> struct IIterable;
    template <typename T> struct IVectorView;
    template <typename T> struct IVector;
    template <typename T> struct IObservableVector;

    template <typename K, typename V> struct IKeyValuePair;
    template <typename K, typename V> struct IMapView;
    template <typename K, typename V> struct IMap;
    template <typename K, typename V> struct IObservableMap;
}

namespace winrt::impl
{
    namespace wfc = Windows::Foundation::Collections;

    template <>
    struct abi<wfc::IVectorChangedEventArgs>
    {
        struct __declspec(novtable) type : ::IInspectable
        {
            virtual HRESULT __stdcall get_CollectionChange(wfc::CollectionChange* value) = 0;
            virtual HRESULT __stdcall get_Index(uint32_t* value) = 0;
        };
    };

    template <typename D>
    struct consume_IVectorChangedEventArgs
    {
        wfc::CollectionChange CollectionChange() const noexcept
        {
            wfc::CollectionChange value{};
            check_terminate((*(abi_t<wfc::IVectorChangedEventArgs>**)&static_cast<wfc::IVectorChangedEventArgs const&>(static_cast<D const&>(*this)))->get_CollectionChange(&value));
            return value;
        }

        uint32_t Index() const noexcept
        {
            uint32_t index{};
            check_terminate((*(abi_t<wfc::IVectorChangedEventArgs>**)&static_cast<wfc::IVectorChangedEventArgs const&>(static_cast<D const&>(*this)))->get_Index(&index));
            return index;
        }
    };

    template <typename D, typename K>
    struct consume_IMapChangedEventArgs
    {
        wfc::CollectionChange CollectionChange() const noexcept
        {
            wfc::CollectionChange value{};
            check_terminate((*(abi_t<wfc::IMapChangedEventArgs<K>>**)&static_cast<wfc::IMapChangedEventArgs<K> const&>(static_cast<D const&>(*this)))->get_CollectionChange(&value));
            return value;
        }

        K Key() const noexcept
        {
            K result{ empty_value<K>() };
            check_terminate((*(abi_t<wfc::IMapChangedEventArgs<K>>**)&static_cast<wfc::IMapChangedEventArgs<K> const&>(static_cast<D const&>(*this)))->get_Key(put_abi(result)));
            return result;
        }
    };

    template <typename D, typename T>
    struct consume_IIterator
    {
        T Current() const noexcept
        {
            T result{ empty_value<T>() };
            check_terminate((*(abi_t<wfc::IIterator<T>>**)&static_cast<wfc::IIterator<T> const&>(static_cast<D const&>(*this)))->get_Current(put_abi(result)));
            return result;
        }

        bool HasCurrent() const noexcept
        {
            bool temp{};
            check_terminate((*(abi_t<wfc::IIterator<T>>**)&static_cast<wfc::IIterator<T> const&>(static_cast<D const&>(*this)))->get_HasCurrent(put_abi(temp)));
            return temp;
        }

        bool MoveNext() const
        {
            bool temp{};
            check_hresult((*(abi_t<wfc::IIterator<T>>**)&static_cast<wfc::IIterator<T> const&>(static_cast<D const&>(*this)))->MoveNext(put_abi(temp)));
            return temp;
        }

        uint32_t GetMany(array_view<T> values) const
        {
            uint32_t actual{};
            check_hresult((*(abi_t<wfc::IIterator<T>>**)&static_cast<wfc::IIterator<T> const&>(static_cast<D const&>(*this)))->GetMany(values.size(), get_abi(values), &actual));
            return actual;
        }

        auto& operator++()
        {
            if (!MoveNext())
            {
                static_cast<D&>(*this) = nullptr;
            }

            return*this;
        }

        T operator*() const noexcept
        {
            return Current();
        }
    };

    template <typename D, typename T>
    struct consume_IIterable
    {
        wfc::IIterator<T> First() const
        {
            wfc::IIterator<T> iterator;
            check_hresult((*(abi_t<wfc::IIterable<T>>**)&static_cast<wfc::IIterable<T> const&>(static_cast<D const&>(*this)))->First(put_abi(iterator)));
            return iterator;
        }
    };

    template <typename D, typename T>
    struct consume_IVectorView
    {
        T GetAt(uint32_t const index) const
        {
            T result{ empty_value<T>() };
            check_hresult((*(abi_t<wfc::IVectorView<T>>**)&static_cast<wfc::IVectorView<T> const&>(static_cast<D const&>(*this)))->GetAt(index, put_abi(result)));
            return result;
        }

        uint32_t Size() const noexcept
        {
            uint32_t size{};
            check_terminate((*(abi_t<wfc::IVectorView<T>>**)&static_cast<wfc::IVectorView<T> const&>(static_cast<D const&>(*this)))->get_Size(&size));
            return size;
        }

        bool IndexOf(T const& value, uint32_t& index) const
        {
            bool found{};
            check_hresult((*(abi_t<wfc::IVectorView<T>>**)&static_cast<wfc::IVectorView<T> const&>(static_cast<D const&>(*this)))->IndexOf(get_abi(value), &index, &found));
            return found;
        }

        uint32_t GetMany(uint32_t startIndex, array_view<T> values) const
        {
            uint32_t actual{};
            check_hresult((*(abi_t<wfc::IVectorView<T>>**)&static_cast<wfc::IVectorView<T> const&>(static_cast<D const&>(*this)))->GetMany(startIndex, values.size(), get_abi(values), &actual));
            return actual;
        }
    };

    template <typename D, typename T>
    struct consume_IVector
    {
        T GetAt(uint32_t const index) const
        {
            T result{ empty_value<T>() };
            check_hresult((*(abi_t<wfc::IVector<T>>**)&static_cast<wfc::IVector<T> const&>(static_cast<D const&>(*this)))->GetAt(index, put_abi(result)));
            return result;
        }

        uint32_t Size() const noexcept
        {
            uint32_t size = 0;
            check_terminate((*(abi_t<wfc::IVector<T>>**)&static_cast<wfc::IVector<T> const&>(static_cast<D const&>(*this)))->get_Size(&size));
            return size;
        }

        wfc::IVectorView<T> GetView() const
        {
            wfc::IVectorView<T> view;
            check_hresult((*(abi_t<wfc::IVector<T>>**)&static_cast<wfc::IVector<T> const&>(static_cast<D const&>(*this)))->GetView(put_abi(view)));
            return view;
        }

        bool IndexOf(T const& value, uint32_t& index) const
        {
            bool found{};
            check_hresult((*(abi_t<wfc::IVector<T>>**)&static_cast<wfc::IVector<T> const&>(static_cast<D const&>(*this)))->IndexOf(get_abi(value), &index, &found));
            return found;
        }

        void SetAt(uint32_t const index, T const& value) const
        {
            check_hresult((*(abi_t<wfc::IVector<T>>**)&static_cast<wfc::IVector<T> const&>(static_cast<D const&>(*this)))->SetAt(index, get_abi(value)));
        }

        void InsertAt(uint32_t const index, T const& value) const
        {
            check_hresult((*(abi_t<wfc::IVector<T>>**)&static_cast<wfc::IVector<T> const&>(static_cast<D const&>(*this)))->InsertAt(index, get_abi(value)));
        }

        void RemoveAt(uint32_t const index) const
        {
            check_hresult((*(abi_t<wfc::IVector<T>>**)&static_cast<wfc::IVector<T> const&>(static_cast<D const&>(*this)))->RemoveAt(index));
        }

        void Append(T const& value) const
        {
            check_hresult((*(abi_t<wfc::IVector<T>>**)&static_cast<wfc::IVector<T> const&>(static_cast<D const&>(*this)))->Append(get_abi(value)));
        }

        void RemoveAtEnd() const
        {
            check_hresult((*(abi_t<wfc::IVector<T>>**)&static_cast<wfc::IVector<T> const&>(static_cast<D const&>(*this)))->RemoveAtEnd());
        }

        void Clear() const
        {
            check_hresult((*(abi_t<wfc::IVector<T>>**)&static_cast<wfc::IVector<T> const&>(static_cast<D const&>(*this)))->Clear());
        }

        uint32_t GetMany(uint32_t startIndex, array_view<T> values) const
        {
            uint32_t actual{};
            check_hresult((*(abi_t<wfc::IVector<T>>**)&static_cast<wfc::IVector<T> const&>(static_cast<D const&>(*this)))->GetMany(startIndex, values.size(), get_abi(values), &actual));
            return actual;
        }

        void ReplaceAll(array_view<T const> value) const
        {
            check_hresult((*(abi_t<wfc::IVector<T>>**)&static_cast<wfc::IVector<T> const&>(static_cast<D const&>(*this)))->ReplaceAll(value.size(), get_abi(value)));
        }
    };

    template <typename D, typename T>
    struct consume_IObservableVector
    {
        event_token VectorChanged(wfc::VectorChangedEventHandler<T> const& handler) const
        {
            event_token cookie{};
            check_hresult((*(abi_t<wfc::IObservableVector<T>>**)&static_cast<wfc::IObservableVector<T> const&>(static_cast<D const&>(*this)))->add_VectorChanged(get_abi(handler), &cookie));
            return cookie;
        }

        void VectorChanged(event_token const cookie) const
        {
            check_hresult((*(abi_t<wfc::IObservableVector<T>>**)&static_cast<wfc::IObservableVector<T> const&>(static_cast<D const&>(*this)))->remove_VectorChanged(cookie));
        }

        using VectorChanged_revoker = event_revoker<wfc::IObservableVector<T>>;

        VectorChanged_revoker VectorChanged(auto_revoke_t, wfc::VectorChangedEventHandler<T> const& handler) const
        {
            return make_event_revoker<D, wfc::IObservableVector<T>>(this, &abi<wfc::IObservableVector<T>>::remove_VectorChanged, VectorChanged(handler));
        }
    };

    template <typename D, typename K, typename V>
    struct consume_IKeyValuePair
    {
        K Key() const noexcept
        {
            K result{ empty_value<K>() };
            check_terminate((*(abi_t<wfc::IKeyValuePair<K, V>>**)&static_cast<wfc::IKeyValuePair<K, V> const&>(static_cast<D const&>(*this)))->get_Key(put_abi(result)));
            return result;
        }

        V Value() const noexcept
        {
            V result{ empty_value<V>() };
            check_terminate((*(abi_t<wfc::IKeyValuePair<K, V>>**)&static_cast<wfc::IKeyValuePair<K, V> const&>(static_cast<D const&>(*this)))->get_Value(put_abi(result)));
            return result;
        }

        bool operator==(wfc::IKeyValuePair<K, V> const& other) const noexcept
        {
            return Key() == other.Key() && Value() == other.Value();
        }

        bool operator!=(wfc::IKeyValuePair<K, V> const& other) const noexcept
        {
            return !(*this == other);
        }
    };

    template <typename D, typename K, typename V>
    struct consume_IMapView
    {
        V Lookup(K const& key) const
        {
            V result{ empty_value<V>() };
            check_hresult((*(abi_t<wfc::IMapView<K, V>>**)&static_cast<wfc::IMapView<K, V> const&>(static_cast<D const&>(*this)))->Lookup(get_abi(key), put_abi(result)));
            return result;
        }

        uint32_t Size() const noexcept
        {
            uint32_t size{};
            check_terminate((*(abi_t<wfc::IMapView<K, V>>**)&static_cast<wfc::IMapView<K, V> const&>(static_cast<D const&>(*this)))->get_Size(&size));
            return size;
        }

        bool HasKey(K const& key) const
        {
            bool found{};
            check_hresult((*(abi_t<wfc::IMapView<K, V>>**)&static_cast<wfc::IMapView<K, V> const&>(static_cast<D const&>(*this)))->HasKey(get_abi(key), &found));
            return found;
        }
        void Split(wfc::IMapView<K, V>& firstPartition, wfc::IMapView<K, V>& secondPartition)
        {
            check_hresult((*(abi_t<wfc::IMapView<K, V>>**)&static_cast<wfc::IMapView<K, V> const&>(static_cast<D const&>(*this)))->Split(put_abi(firstPartition), put_abi(secondPartition)));
        }
    };

    template <typename D, typename K, typename V>
    struct consume_IMap
    {
        V Lookup(K const& key) const
        {
            V result{ empty_value<V>() };
            check_hresult((*(abi_t<wfc::IMap<K, V>>**)&static_cast<wfc::IMap<K, V> const&>(static_cast<D const&>(*this)))->Lookup(get_abi(key), put_abi(result)));
            return result;
        }

        uint32_t Size() const noexcept
        {
            uint32_t size{};
            check_terminate((*(abi_t<wfc::IMap<K, V>>**)&static_cast<wfc::IMap<K, V> const&>(static_cast<D const&>(*this)))->get_Size(&size));
            return size;
        }

        bool HasKey(K const& key) const
        {
            bool found{};
            check_hresult((*(abi_t<wfc::IMap<K, V>>**)&static_cast<wfc::IMap<K, V> const&>(static_cast<D const&>(*this)))->HasKey(get_abi(key), &found));
            return found;
        }

        wfc::IMapView<K, V> GetView() const
        {
            wfc::IMapView<K, V> view;
            check_hresult((*(abi_t<wfc::IMap<K, V>>**)&static_cast<wfc::IMap<K, V> const&>(static_cast<D const&>(*this)))->GetView(put_abi(view)));
            return view;
        }

        bool Insert(K const& key, V const& value) const
        {
            bool replaced{};
            check_hresult((*(abi_t<wfc::IMap<K, V>>**)&static_cast<wfc::IMap<K, V> const&>(static_cast<D const&>(*this)))->Insert(get_abi(key), get_abi(value), &replaced));
            return replaced;
        }

        void Remove(K const& key) const
        {
            check_hresult((*(abi_t<wfc::IMap<K, V>>**)&static_cast<wfc::IMap<K, V> const&>(static_cast<D const&>(*this)))->Remove(get_abi(key)));
        }

        void Clear() const
        {
            check_hresult((*(abi_t<wfc::IMap<K, V>>**)&static_cast<wfc::IMap<K, V> const&>(static_cast<D const&>(*this)))->Clear());
        }
    };

    template <typename D, typename K, typename V>
    struct consume_IObservableMap
    {
        event_token MapChanged(wfc::MapChangedEventHandler<K, V> const& handler) const
        {
            event_token cookie{};
            check_hresult((*(abi_t<wfc::IObservableMap<K, V>>**)&static_cast<wfc::IObservableMap<K, V> const&>(static_cast<D const&>(*this)))->add_MapChanged(get_abi(handler), &cookie));
            return cookie;
        }

        void MapChanged(event_token const cookie) const
        {
            check_hresult((*(abi_t<wfc::IObservableMap<K, V>>**)&static_cast<wfc::IObservableMap<K, V> const&>(static_cast<D const&>(*this)))->remove_MapChanged(cookie));
        }

        using MapChanged_revoker = event_revoker<wfc::IObservableMap<K, V>>;

        MapChanged_revoker MapChanged(auto_revoke_t, wfc::MapChangedEventHandler<K, V> const& handler) const
        {
            return make_event_revoker<D, wfc::IObservableMap<K, V>>(this, &abi_t<wfc::IObservableMap<K, V>>::remove_MapChanged, MapChanged(handler));
        }
    };

    template <>
    struct consume<wfc::IVectorChangedEventArgs>
    {
        template <typename D> using type = consume_IVectorChangedEventArgs<D>;
    };

    template <typename K>
    struct abi<wfc::IMapChangedEventArgs<K>>
    {
        struct __declspec(novtable) type : ::IInspectable
        {
            virtual HRESULT __stdcall get_CollectionChange(wfc::CollectionChange* value) = 0;
            virtual HRESULT __stdcall get_Key(arg_out<K> value) = 0;
        };
    };

    template <typename K>
    struct consume<wfc::IMapChangedEventArgs<K>>
    {
        template <typename D> using type = consume_IMapChangedEventArgs<D, K>;
    };

    template <typename T>
    struct abi<wfc::VectorChangedEventHandler<T>>
    {
        struct __declspec(novtable) type : ::IUnknown
        {
            virtual HRESULT __stdcall Invoke(::IUnknown* sender, ::IUnknown* args) = 0;
        };
    };

    template <typename T>
    struct delegate<wfc::VectorChangedEventHandler<T>>
    {
        template <typename H>
        struct type : implements_delegate<wfc::VectorChangedEventHandler<T>, H>
        {
            type(H&& handler) : implements_delegate<wfc::VectorChangedEventHandler<T>, H>(std::forward<H>(handler)) {}

            HRESULT __stdcall Invoke(::IUnknown* sender, ::IUnknown* args) noexcept final
            {
                try
                {
                    (*this)(*reinterpret_cast<wfc::IObservableVector<T> const*>(&sender), *reinterpret_cast<wfc::IVectorChangedEventArgs const*>(&args));
                    return S_OK;
                }
                catch (...) { return to_hresult(); }
            }
        };
    };

    template <typename K, typename V>
    struct abi<wfc::MapChangedEventHandler<K, V>>
    {
        struct __declspec(novtable) type : ::IUnknown
        {
            virtual HRESULT __stdcall Invoke(::IUnknown* sender, ::IUnknown* args) = 0;
        };
    };

    template <typename K, typename V>
    struct delegate<wfc::MapChangedEventHandler<K, V>>
    {
        template <typename H>
        struct type : implements_delegate<wfc::MapChangedEventHandler<K, V>, H>
        {
            type(H&& handler) : implements_delegate<wfc::MapChangedEventHandler<K, V>, H>(std::forward<H>(handler)) {}

            HRESULT __stdcall Invoke(::IUnknown* sender, ::IUnknown* args) noexcept final
            {
                try
                {
                    (*this)(*reinterpret_cast<wfc::IObservableMap<K, V> const*>(&sender), *reinterpret_cast<wfc::IMapChangedEventArgs<K> const*>(&args));
                    return S_OK;
                }
                catch (...) { return to_hresult(); }
            }
        };
    };

    template <typename T>
    struct abi<wfc::IIterator<T>>
    {
        struct __declspec(novtable) type : ::IInspectable
        {
            virtual HRESULT __stdcall get_Current(arg_out<T> current) = 0;
            virtual HRESULT __stdcall get_HasCurrent(bool* hasCurrent) = 0;
            virtual HRESULT __stdcall MoveNext(bool* hasCurrent) = 0;
            virtual HRESULT __stdcall GetMany(uint32_t capacity, arg_out<T> value, uint32_t* actual) = 0;
        };
    };

    template <typename T>
    struct consume<wfc::IIterator<T>>
    {
        template <typename D> using type = consume_IIterator<D, T>;
    };

    template <typename T>
    struct abi<wfc::IIterable<T>>
    {
        struct __declspec(novtable) type : ::IInspectable
        {
            virtual HRESULT __stdcall First(::IUnknown** first) = 0;
        };
    };

    template <typename T>
    struct consume<wfc::IIterable<T>>
    {
        template <typename D> using type = consume_IIterable<D, T>;
    };

    template <typename T>
    struct abi<wfc::IVectorView<T>>
    {
        struct __declspec(novtable) type : ::IInspectable
        {
            virtual HRESULT __stdcall GetAt(uint32_t index, arg_out<T> item) = 0;
            virtual HRESULT __stdcall get_Size(uint32_t* size) = 0;
            virtual HRESULT __stdcall IndexOf(arg_in<T> value, uint32_t* index, bool* found) = 0;
            virtual HRESULT __stdcall GetMany(uint32_t startIndex, uint32_t capacity, arg_out<T> value, uint32_t* actual) = 0;
        };
    };

    template <typename T>
    struct consume<wfc::IVectorView<T>>
    {
        template <typename D> using type = consume_IVectorView<D, T>;
    };

    template <typename T>
    struct abi<wfc::IVector<T>>
    {
        struct __declspec(novtable) type : ::IInspectable
        {
            virtual HRESULT __stdcall GetAt(uint32_t index, arg_out<T> item) = 0;
            virtual HRESULT __stdcall get_Size(uint32_t* size) = 0;
            virtual HRESULT __stdcall GetView(::IUnknown** view) = 0;
            virtual HRESULT __stdcall IndexOf(arg_in<T> value, uint32_t* index, bool* found) = 0;
            virtual HRESULT __stdcall SetAt(uint32_t index, arg_in<T> item) = 0;
            virtual HRESULT __stdcall InsertAt(uint32_t index, arg_in<T> item) = 0;
            virtual HRESULT __stdcall RemoveAt(uint32_t index) = 0;
            virtual HRESULT __stdcall Append(arg_in<T> item) = 0;
            virtual HRESULT __stdcall RemoveAtEnd() = 0;
            virtual HRESULT __stdcall Clear() = 0;
            virtual HRESULT __stdcall GetMany(uint32_t startIndex, uint32_t capacity, arg_out<T> value, uint32_t* actual) = 0;
            virtual HRESULT __stdcall ReplaceAll(uint32_t count, arg_out<T> value) = 0;
        };
    };

    template <typename T>
    struct consume<wfc::IVector<T>>
    {
        template <typename D> using type = consume_IVector<D, T>;
    };

    template <typename T>
    struct abi<wfc::IObservableVector<T>>
    {
        struct __declspec(novtable) type : ::IInspectable
        {
            virtual HRESULT __stdcall add_VectorChanged(::IUnknown* handler, event_token*  token) = 0;
            virtual HRESULT __stdcall remove_VectorChanged(event_token token) = 0;
        };
    };

    template <typename T>
    struct consume<wfc::IObservableVector<T>>
    {
        template <typename D> using type = consume_IObservableVector<D, T>;
    };

    template <typename K, typename V>
    struct abi<wfc::IKeyValuePair<K, V>>
    {
        struct __declspec(novtable) type : ::IInspectable
        {
            virtual HRESULT __stdcall get_Key(arg_out<K> key) = 0;
            virtual HRESULT __stdcall get_Value(arg_out<V> value) = 0;
        };
    };

    template <typename K, typename V>
    struct consume<wfc::IKeyValuePair<K, V>>
    {
        template <typename D> using type = consume_IKeyValuePair<D, K, V>;
    };

    template <typename K, typename V>
    struct abi<wfc::IMapView<K, V>>
    {
        struct __declspec(novtable) type : ::IInspectable
        {
            virtual HRESULT __stdcall Lookup(arg_in<K> key, arg_out<V> value) = 0;
            virtual HRESULT __stdcall get_Size(uint32_t* size) = 0;
            virtual HRESULT __stdcall HasKey(arg_in<K> key, bool* found) = 0;
            virtual HRESULT __stdcall Split(::IUnknown** firstPartition, ::IUnknown** secondPartition) = 0;
        };
    };

    template <typename K, typename V>
    struct consume<wfc::IMapView<K, V>>
    {
        template <typename D> using type = consume_IMapView<D, K, V>;
    };

    template <typename K, typename V>
    struct abi<wfc::IMap<K, V>>
    {
        struct __declspec(novtable) type : ::IInspectable
        {
            virtual HRESULT __stdcall Lookup(arg_in<K> key, arg_out<V> value) = 0;
            virtual HRESULT __stdcall get_Size(uint32_t* size) = 0;
            virtual HRESULT __stdcall HasKey(arg_in<K> key, bool* found) = 0;
            virtual HRESULT __stdcall GetView(::IUnknown** view) = 0;
            virtual HRESULT __stdcall Insert(arg_in<K> key, arg_in<V> value, bool* replaced) = 0;
            virtual HRESULT __stdcall Remove(arg_in<K> key) = 0;
            virtual HRESULT __stdcall Clear() = 0;
        };
    };

    template <typename K, typename V>
    struct consume<wfc::IMap<K, V>>
    {
        template <typename D> using type = consume_IMap<D, K, V>;
    };

    template <typename K, typename V>
    struct abi<wfc::IObservableMap<K, V>>
    {
        struct __declspec(novtable) type : ::IInspectable
        {
            virtual HRESULT __stdcall add_MapChanged(::IUnknown* handler, event_token* token) = 0;
            virtual HRESULT __stdcall remove_MapChanged(event_token token) = 0;
        };
    };

    template <typename K, typename V>
    struct consume<wfc::IObservableMap<K, V>>
    {
        template <typename D> using type = consume_IObservableMap<D, K, V>;
    };

    template <>
    struct guid<wfc::IVectorChangedEventArgs>
    {
        static constexpr GUID value{ 0x575933DF,0x34FE,0x4480,{ 0xAF,0x15,0x07,0x69,0x1F,0x3D,0x5D,0x9B } };
    };

    template <>
    struct name<wfc::IVectorChangedEventArgs>
    {
        static constexpr auto & value{ L"Windows.Foundation.Collections.IVectorChangedEventArgs" };
    };

    template <>
    struct category<wfc::IVectorChangedEventArgs>
    {
        using type = interface_category;
    };

    template <typename K>
    struct guid<wfc::IMapChangedEventArgs<K>>
    {
        static constexpr GUID value{ pinterface_guid<wfc::IMapChangedEventArgs<K>>::value };
    };

    template <typename K>
    struct name<wfc::IMapChangedEventArgs<K>>
    {
        static constexpr auto value{ L"Windows.Foundation.Collections.IMapChangedEventArgs`1<" + make_constexpr_string(name_v<K>) + L">" };
    };

    template <typename K>
    struct category<wfc::IMapChangedEventArgs<K>>
    {
        using type = pinterface_category<K>;
        static constexpr GUID value{ 0x9939f4df, 0x050a, 0x4c0f,{ 0xaa, 0x60, 0x77, 0x07, 0x5f, 0x9c, 0x47, 0x77 } };
    };

    template <typename T>
    struct guid<wfc::VectorChangedEventHandler<T>>
    {
        static constexpr GUID value{ pinterface_guid<wfc::VectorChangedEventHandler<T>>::value };
    };

    template <typename T>
    struct name<wfc::VectorChangedEventHandler<T>>
    {
        static constexpr auto value{ L"Windows.Foundation.Collections.VectorChangedEventHandler`1<" + make_constexpr_string(name_v<T>) + L">" };
    };

    template <typename T>
    struct category<wfc::VectorChangedEventHandler<T>>
    {
        using type = pinterface_category<T>;
        static constexpr GUID value{ 0x0c051752, 0x9fbf, 0x4c70,{ 0xaa, 0x0c, 0x0e, 0x4c, 0x82, 0xd9, 0xa7, 0x61 } };
    };

    template <typename K, typename V>
    struct guid<wfc::MapChangedEventHandler<K, V>>
    {
        static constexpr GUID value{ pinterface_guid<wfc::MapChangedEventHandler<K, V>>::value };
    };

    template <typename K, typename V>
    struct name<wfc::MapChangedEventHandler<K, V>>
    {
        static constexpr auto value{ L"Windows.Foundation.Collections.MapChangedEventHandler`2<" + make_constexpr_string(name_v<K>) + L", " + make_constexpr_string(name_v<V>) + L">" };
    };

    template <typename K, typename V>
    struct category<wfc::MapChangedEventHandler<K, V>>
    {
        using type = pinterface_category<K, V>;
        static constexpr GUID value{ 0x179517f3, 0x94ee, 0x41f8,{ 0xbd, 0xdc, 0x76, 0x8a, 0x89, 0x55, 0x44, 0xf3 } };
    };

    template <typename T>
    struct guid<wfc::IIterator<T>>
    {
        static constexpr GUID value{ pinterface_guid<wfc::IIterator<T>>::value };
    };

    template <typename T>
    struct name<wfc::IIterator<T>>
    {
        static constexpr auto value{ L"Windows.Foundation.Collections.IIterator`1<" + make_constexpr_string(name_v<T>) + L">" };
    };

    template <typename T>
    struct category<wfc::IIterator<T>>
    {
        using type = pinterface_category<T>;
        static constexpr GUID value{ 0x6a79e863, 0x4300, 0x459a,{ 0x99, 0x66, 0xcb, 0xb6, 0x60, 0x96, 0x3e, 0xe1 } };
    };

    template <typename T>
    struct guid<wfc::IIterable<T>>
    {
        static constexpr GUID value{ pinterface_guid<wfc::IIterable<T>>::value };
    };

    template <typename T>
    struct name<wfc::IIterable<T>>
    {
        static constexpr auto value{ L"Windows.Foundation.Collections.IIterable`1<" + make_constexpr_string(name_v<T>) + L">" };
    };

    template <typename T>
    struct category<wfc::IIterable<T>>
    {
        using type = pinterface_category<T>;
        static constexpr GUID value{ 0xfaa585ea, 0x6214, 0x4217,{ 0xaf, 0xda, 0x7f, 0x46, 0xde, 0x58, 0x69, 0xb3 } };
    };

    template <typename T>
    struct guid<wfc::IVectorView<T>>
    {
        static constexpr GUID value{ pinterface_guid<wfc::IVectorView<T>>::value };
    };

    template <typename T>
    struct name<wfc::IVectorView<T>>
    {
        static constexpr auto value{ L"Windows.Foundation.Collections.IVectorView`1<" + make_constexpr_string(name_v<T>) + L">" };
    };

    template <typename T>
    struct category<wfc::IVectorView<T>>
    {
        using type = pinterface_category<T>;
        static constexpr GUID value{ 0xbbe1fa4c, 0xb0e3, 0x4583,{ 0xba, 0xef, 0x1f, 0x1b, 0x2e, 0x48, 0x3e, 0x56 } };
    };

    template <typename T>
    struct guid<wfc::IVector<T>>
    {
        static constexpr GUID value{ pinterface_guid<wfc::IVector<T>>::value };
    };

    template <typename T>
    struct name<wfc::IVector<T>>
    {
        static constexpr auto value{ L"Windows.Foundation.Collections.IVector`1<" + make_constexpr_string(name_v<T>) + L">" };
    };

    template <typename T>
    struct category<wfc::IVector<T>>
    {
        using type = pinterface_category<T>;
        static constexpr GUID value{ 0x913337e9, 0x11a1, 0x4345,{ 0xa3, 0xa2, 0x4e, 0x7f, 0x95, 0x6e, 0x22, 0x2d } };
    };

    template <typename T>
    struct guid<wfc::IObservableVector<T>>
    {
        static constexpr GUID value{ pinterface_guid<wfc::IObservableVector<T>>::value };
    };

    template <typename T>
    struct name<wfc::IObservableVector<T>>
    {
        static constexpr auto value{ L"Windows.Foundation.Collections.IObservableVector`1<" + make_constexpr_string(name_v<T>) + L">" };
    };

    template <typename T>
    struct category<wfc::IObservableVector<T>>
    {
        using type = pinterface_category<T>;
        static constexpr GUID value{ 0x5917eb53, 0x50b4, 0x4a0d,{ 0xb3, 0x09, 0x65, 0x86, 0x2b, 0x3f, 0x1d, 0xbc } };
    };

    template <typename K, typename V>
    struct guid<wfc::IKeyValuePair<K, V>>
    {
        static constexpr GUID value{ pinterface_guid<wfc::IKeyValuePair<K, V>>::value };
    };

    template <typename K, typename V>
    struct name<wfc::IKeyValuePair<K, V>>
    {
        static constexpr auto value{ L"Windows.Foundation.Collections.IKeyValuePair`2<" + make_constexpr_string(name_v<K>) + L", " + make_constexpr_string(name_v<V>) + L">" };
    };

    template <typename K, typename V>
    struct category<wfc::IKeyValuePair<K, V>>
    {
        using type = pinterface_category<K, V>;
        static constexpr GUID value{ 0x02b51929, 0xc1c4, 0x4a7e,{ 0x89, 0x40, 0x03, 0x12, 0xb5, 0xc1, 0x85, 0x00 } };
    };

    template <typename K, typename V>
    struct guid<wfc::IMapView<K, V>>
    {
        static constexpr GUID value{ pinterface_guid<wfc::IMapView<K, V>>::value };
    };

    template <typename K, typename V>
    struct name<wfc::IMapView<K, V>>
    {
        static constexpr auto value{ L"Windows.Foundation.Collections.IMapView`2<" + make_constexpr_string(name_v<K>) + L", " + make_constexpr_string(name_v<V>) + L">" };
    };

    template <typename K, typename V>
    struct category<wfc::IMapView<K, V>>
    {
        using type = pinterface_category<K, V>;
        static constexpr GUID value{ 0xe480ce40, 0xa338, 0x4ada,{ 0xad, 0xcf, 0x27, 0x22, 0x72, 0xe4, 0x8c, 0xb9 } };
    };

    template <typename K, typename V>
    struct guid<wfc::IMap<K, V>>
    {
        static constexpr GUID value{ pinterface_guid<wfc::IMap<K, V>>::value };
    };

    template <typename K, typename V>
    struct name<wfc::IMap<K, V>>
    {
        static constexpr auto value{ L"Windows.Foundation.Collections.IMap`2<" + make_constexpr_string(name_v<K>) + L", " + make_constexpr_string(name_v<V>) + L">" };
    };

    template <typename K, typename V>
    struct category<wfc::IMap<K, V>>
    {
        using type = pinterface_category<K, V>;
        static constexpr GUID value{ 0x3c2925fe, 0x8519, 0x45c1,{ 0xaa, 0x79, 0x19, 0x7b, 0x67, 0x18, 0xc1, 0xc1 } };
    };

    template <typename K, typename V>
    struct guid<wfc::IObservableMap<K, V>>
    {
        static constexpr GUID value{ pinterface_guid<wfc::IObservableMap<K, V>>::value };
    };

    template <typename K, typename V>
    struct name<wfc::IObservableMap<K, V>>
    {
        static constexpr auto value{ L"Windows.Foundation.Collections.IObservableMap`2<" + make_constexpr_string(name_v<K>) + L", " + make_constexpr_string(name_v<V>) + L">" };
    };

    template <typename K, typename V>
    struct category<wfc::IObservableMap<K, V>>
    {
        using type = pinterface_category<K, V>;
        static constexpr GUID value{ 0x65df2bf5, 0xbf39, 0x41b5,{ 0xae, 0xbc, 0x5a, 0x9d, 0x86, 0x5e, 0x47, 0x2b } };
    };

    template <typename T>
    struct fast_iterator
    {
        using iterator_category = std::input_iterator_tag;
        using value_type = T;
        using difference_type = ptrdiff_t;
        using pointer = T*;
        using reference = T&;

        fast_iterator(T const& collection, uint32_t const index) noexcept :
            m_collection(&collection),
            m_index(index)
        {}

        fast_iterator& operator++() noexcept
        {
            ++m_index;
            return*this;
        }

        auto operator*() const
        {
            return m_collection->GetAt(m_index);
        }

        bool operator==(fast_iterator const& other) const noexcept
        {
            WINRT_ASSERT(m_collection == other.m_collection);
            return m_index == other.m_index;
        }

        bool operator!=(fast_iterator const& other) const noexcept
        {
            return !(*this == other);
        }

    private:

        T const* m_collection = nullptr;
        uint32_t m_index = 0;
    };

    template <typename T>
    class has_GetAt
    {
        template <typename U, typename = decltype(std::declval<U>().GetAt(0))> static constexpr bool get_value(int) { return true; }
        template <typename> static constexpr bool get_value(...) { return false; }

    public:

        static constexpr bool value = get_value<T>(0);
    };

    template <typename T, std::enable_if_t<!has_GetAt<T>::value>* = nullptr>
    auto begin(T const& collection) -> decltype(collection.First())
    {
        auto result = collection.First();

        if (!result.HasCurrent())
        {
            return {};
        }

        return result;
    }

    template <typename T, std::enable_if_t<!has_GetAt<T>::value>* = nullptr>
    auto end(T const& collection) noexcept -> decltype(collection.First())
    {
        collection;
        return {};
    }

    template <typename T, std::enable_if_t<has_GetAt<T>::value>* = nullptr>
    fast_iterator<T> begin(T const& collection) noexcept
    {
        return fast_iterator<T>(collection, 0);
    }

    template <typename T, std::enable_if_t<has_GetAt<T>::value>* = nullptr>
    fast_iterator<T> end(T const& collection) noexcept
    {
        return fast_iterator<T>(collection, collection.Size());
    }
}

WINRT_EXPORT namespace winrt::Windows::Foundation::Collections
{
    struct IVectorChangedEventArgs :
        IInspectable,
        impl::consume_t<IVectorChangedEventArgs>
    {
        IVectorChangedEventArgs(std::nullptr_t = nullptr) noexcept {}
    };

    template <typename K>
    struct WINRT_EBO IMapChangedEventArgs :
        IInspectable,
        impl::consume_t<IMapChangedEventArgs<K>>
    {
        IMapChangedEventArgs(std::nullptr_t = nullptr) noexcept {}
    };

    template <typename T>
    struct WINRT_EBO VectorChangedEventHandler : IUnknown
    {
        VectorChangedEventHandler(std::nullptr_t = nullptr) noexcept {}

        template <typename L>
        VectorChangedEventHandler(L handler) :
            VectorChangedEventHandler(impl::make_delegate<VectorChangedEventHandler<T>>(std::forward<L>(handler)))
        {}

        template <typename F> VectorChangedEventHandler(F* handler) :
            VectorChangedEventHandler([=](auto&& ... args) { handler(args ...); })
        {}

        template <typename O, typename M> VectorChangedEventHandler(O* object, M method) :
            VectorChangedEventHandler([=](auto&& ... args) { ((*object).*(method))(args ...); })
        {}

        void operator()(IObservableVector<T> const& sender, IVectorChangedEventArgs const& args) const
        {
            check_hresult((*(abi_t<VectorChangedEventHandler<T>>**)this)->Invoke(get_abi(sender), get_abi(args)));
        }
    };

    template <typename K, typename V>
    struct WINRT_EBO MapChangedEventHandler : IUnknown
    {
        MapChangedEventHandler(std::nullptr_t = nullptr) noexcept {}

        template <typename L>
        MapChangedEventHandler(L handler) :
            MapChangedEventHandler(impl::make_delegate<MapChangedEventHandler<K, V>>(std::forward<L>(handler)))
        {}

        template <typename F> MapChangedEventHandler(F* handler) :
            MapChangedEventHandler([=](auto&& ... args) { handler(args ...); })
        {}

        template <typename O, typename M> MapChangedEventHandler(O* object, M method) :
            MapChangedEventHandler([=](auto&& ... args) { ((*object).*(method))(args ...); })
        {}

        void operator()(IObservableMap<K, V> const& sender, IMapChangedEventArgs<K> const& args) const
        {
            check_hresult((*(abi_t<MapChangedEventHandler<K, V>>**)this)->Invoke(get_abi(sender), get_abi(args)));
        }
    };

    template <typename T>
    struct WINRT_EBO IIterator :
        IInspectable,
        impl::consume_t<IIterator<T>>
    {
        using iterator_category = std::input_iterator_tag;
        using value_type = T;
        using difference_type = ptrdiff_t;
        using pointer = T*;
        using reference = T&;

        IIterator(std::nullptr_t = nullptr) noexcept {}
    };

    template <typename T>
    struct WINRT_EBO IIterable :
        IInspectable,
        impl::consume_t<IIterable<T>>
    {
        IIterable(std::nullptr_t = nullptr) noexcept {}
    };

    template <typename T>
    struct WINRT_EBO IVectorView :
        IInspectable,
        impl::consume_t<IVectorView<T>>,
        impl::require<IVectorView<T>, IIterable<T>>
    {
        IVectorView(std::nullptr_t = nullptr) noexcept {}
    };

    template <typename T>
    struct WINRT_EBO IVector :
        IInspectable,
        impl::consume_t<IVector<T>>,
        impl::require<IVector<T>, IIterable<T>>
    {
        IVector(std::nullptr_t = nullptr) noexcept {}
    };

    template <typename T>
    struct WINRT_EBO IObservableVector :
        IInspectable,
        impl::consume_t<IObservableVector<T>>,
        impl::require<IObservableVector<T>, IVector<T>, IIterable<T>>
    {
        IObservableVector(std::nullptr_t = nullptr) noexcept {}
    };

    template <typename K, typename V>
    struct WINRT_EBO IKeyValuePair :
        IInspectable,
        impl::consume_t<IKeyValuePair<K, V>>
    {
        IKeyValuePair(std::nullptr_t = nullptr) noexcept {}
    };

    template <typename K, typename V>
    struct WINRT_EBO IMapView :
        IInspectable,
        impl::consume_t<IMapView<K, V>>,
        impl::require<IMapView<K, V>, IIterable<IKeyValuePair<K, V>>>
    {
        IMapView(std::nullptr_t = nullptr) noexcept {}
    };

    template <typename K, typename V>
    struct WINRT_EBO IMap :
        IInspectable,
        impl::consume_t<IMap<K, V>>,
        impl::require<IMap<K, V>, IIterable<IKeyValuePair<K, V>>>
    {
        IMap(std::nullptr_t = nullptr) noexcept {}
    };

    template <typename K, typename V>
    struct WINRT_EBO IObservableMap :
        IInspectable,
        impl::consume_t<IObservableMap<K, V>>,
        impl::require<IObservableMap<K, V>, IMap<K, V>, IIterable<IKeyValuePair<K, V>>>
    {
        IObservableMap(std::nullptr_t = nullptr) noexcept {}
    };
}
