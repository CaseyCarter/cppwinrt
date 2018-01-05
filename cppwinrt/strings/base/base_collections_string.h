
namespace winrt::impl
{
    template <typename D>
    struct consume_IVectorView<D, hstring>
    {
        hstring GetAt(uint32_t const index) const
        {
            hstring result;
            check_hresult((*(abi_t<wfc::IVectorView<hstring>>**)&static_cast<wfc::IVectorView<hstring> const&>(static_cast<D const&>(*this)))->GetAt(index, put_abi(result)));
            return result;
        }

        uint32_t Size() const
        {
            uint32_t size{};
            check_hresult((*(abi_t<wfc::IVectorView<hstring>>**)&static_cast<wfc::IVectorView<hstring> const&>(static_cast<D const&>(*this)))->get_Size(&size));
            return size;
        }

        bool IndexOf(param::hstring const& value, uint32_t& index) const
        {
            bool found{};
            check_hresult((*(abi_t<wfc::IVectorView<hstring>>**)&static_cast<wfc::IVectorView<hstring> const&>(static_cast<D const&>(*this)))->IndexOf(get_abi(value), &index, &found));
            return found;
        }

        uint32_t GetMany(uint32_t startIndex, array_view<hstring> values) const
        {
            uint32_t actual{};
            check_hresult((*(abi_t<wfc::IVectorView<hstring>>**)&static_cast<wfc::IVectorView<hstring> const&>(static_cast<D const&>(*this)))->GetMany(startIndex, values.size(), get_abi(values), &actual));
            return actual;
        }
    };

    template <typename D>
    struct consume_IVector<D, hstring>
    {
        hstring GetAt(uint32_t const index) const
        {
            hstring result;
            check_hresult((*(abi_t<wfc::IVector<hstring>>**)&static_cast<wfc::IVector<hstring> const&>(static_cast<D const&>(*this)))->GetAt(index, put_abi(result)));
            return result;
        }

        uint32_t Size() const
        {
            uint32_t size = 0;
            check_hresult((*(abi_t<wfc::IVector<hstring>>**)&static_cast<wfc::IVector<hstring> const&>(static_cast<D const&>(*this)))->get_Size(&size));
            return size;
        }

        wfc::IVectorView<hstring> GetView() const
        {
            wfc::IVectorView<hstring> view;
            check_hresult((*(abi_t<wfc::IVector<hstring>>**)&static_cast<wfc::IVector<hstring> const&>(static_cast<D const&>(*this)))->GetView(put_abi(view)));
            return view;
        }

        bool IndexOf(param::hstring const& value, uint32_t& index) const
        {
            bool found{};
            check_hresult((*(abi_t<wfc::IVector<hstring>>**)&static_cast<wfc::IVector<hstring> const&>(static_cast<D const&>(*this)))->IndexOf(get_abi(value), &index, &found));
            return found;
        }

        void SetAt(uint32_t const index, param::hstring const& value) const
        {
            check_hresult((*(abi_t<wfc::IVector<hstring>>**)&static_cast<wfc::IVector<hstring> const&>(static_cast<D const&>(*this)))->SetAt(index, get_abi(value)));
        }

        void InsertAt(uint32_t const index, param::hstring const& value) const
        {
            check_hresult((*(abi_t<wfc::IVector<hstring>>**)&static_cast<wfc::IVector<hstring> const&>(static_cast<D const&>(*this)))->InsertAt(index, get_abi(value)));
        }

        void RemoveAt(uint32_t const index) const
        {
            check_hresult((*(abi_t<wfc::IVector<hstring>>**)&static_cast<wfc::IVector<hstring> const&>(static_cast<D const&>(*this)))->RemoveAt(index));
        }

        void Append(param::hstring const& value) const
        {
            check_hresult((*(abi_t<wfc::IVector<hstring>>**)&static_cast<wfc::IVector<hstring> const&>(static_cast<D const&>(*this)))->Append(get_abi(value)));
        }

        void RemoveAtEnd() const
        {
            check_hresult((*(abi_t<wfc::IVector<hstring>>**)&static_cast<wfc::IVector<hstring> const&>(static_cast<D const&>(*this)))->RemoveAtEnd());
        }

        void Clear() const
        {
            check_hresult((*(abi_t<wfc::IVector<hstring>>**)&static_cast<wfc::IVector<hstring> const&>(static_cast<D const&>(*this)))->Clear());
        }

        uint32_t GetMany(uint32_t startIndex, array_view<hstring> values) const
        {
            uint32_t actual{};
            check_hresult((*(abi_t<wfc::IVector<hstring>>**)&static_cast<wfc::IVector<hstring> const&>(static_cast<D const&>(*this)))->GetMany(startIndex, values.size(), get_abi(values), &actual));
            return actual;
        }

        void ReplaceAll(array_view<hstring const> value) const
        {
            check_hresult((*(abi_t<wfc::IVector<hstring>>**)&static_cast<wfc::IVector<hstring> const&>(static_cast<D const&>(*this)))->ReplaceAll(value.size(), get_abi(value)));
        }
    };

    template <typename D, typename V>
    struct consume_IMapView<D, hstring, V>
    {
        V Lookup(param::hstring const& key) const
        {
            V result{ empty_value<V>() };
            check_hresult((*(abi_t<wfc::IMapView<hstring, V>>**)&static_cast<wfc::IMapView<hstring, V> const&>(static_cast<D const&>(*this)))->Lookup(get_abi(key), put_abi(result)));
            return result;
        }

        uint32_t Size() const
        {
            uint32_t size{};
            check_hresult((*(abi_t<wfc::IMapView<hstring, V>>**)&static_cast<wfc::IMapView<hstring, V> const&>(static_cast<D const&>(*this)))->get_Size(&size));
            return size;
        }

        bool HasKey(param::hstring const& key) const
        {
            bool found{};
            check_hresult((*(abi_t<wfc::IMapView<hstring, V>>**)&static_cast<wfc::IMapView<hstring, V> const&>(static_cast<D const&>(*this)))->HasKey(get_abi(key), &found));
            return found;
        }

        void Split(wfc::IMapView<hstring, V>& firstPartition, wfc::IMapView<hstring, V>& secondPartition)
        {
            check_hresult((*(abi_t<wfc::IMapView<hstring, V>>**)&static_cast<wfc::IMapView<hstring, V> const&>(static_cast<D const&>(*this)))->Split(put_abi(firstPartition), put_abi(secondPartition)));
        }
    };

    template <typename D, typename V>
    struct consume_IMap<D, hstring, V>
    {
        V Lookup(param::hstring const& key) const
        {
            V result{ empty_value<V>() };
            check_hresult((*(abi_t<wfc::IMap<hstring, V>>**)&static_cast<wfc::IMap<hstring, V> const&>(static_cast<D const&>(*this)))->Lookup(get_abi(key), put_abi(result)));
            return result;
        }

        uint32_t Size() const
        {
            uint32_t size{};
            check_hresult((*(abi_t<wfc::IMap<hstring, V>>**)&static_cast<wfc::IMap<hstring, V> const&>(static_cast<D const&>(*this)))->get_Size(&size));
            return size;
        }

        bool HasKey(param::hstring const& key) const
        {
            bool found{};
            check_hresult((*(abi_t<wfc::IMap<hstring, V>>**)&static_cast<wfc::IMap<hstring, V> const&>(static_cast<D const&>(*this)))->HasKey(get_abi(key), &found));
            return found;
        }

        wfc::IMapView<hstring, V> GetView() const
        {
            wfc::IMapView<hstring, V> view;
            check_hresult((*(abi_t<wfc::IMap<hstring, V>>**)&static_cast<wfc::IMap<hstring, V> const&>(static_cast<D const&>(*this)))->GetView(put_abi(view)));
            return view;
        }

        bool Insert(param::hstring const& key, V const& value) const
        {
            bool replaced{};
            check_hresult((*(abi_t<wfc::IMap<hstring, V>>**)&static_cast<wfc::IMap<hstring, V> const&>(static_cast<D const&>(*this)))->Insert(get_abi(key), get_abi(value), &replaced));
            return replaced;
        }

        void Remove(param::hstring const& key) const
        {
            check_hresult((*(abi_t<wfc::IMap<hstring, V>>**)&static_cast<wfc::IMap<hstring, V> const&>(static_cast<D const&>(*this)))->Remove(get_abi(key)));
        }

        void Clear() const
        {
            check_hresult((*(abi_t<wfc::IMap<hstring, V>>**)&static_cast<wfc::IMap<hstring, V> const&>(static_cast<D const&>(*this)))->Clear());
        }
    };
}
