
namespace winrt { namespace Windows { namespace Foundation { namespace Collections {

enum class CollectionChange
{
	Reset,
	ItemInserted,
	ItemRemoved,
	ItemChanged,
};

}}}}


namespace winrt { namespace ABI { namespace Windows { namespace Foundation { namespace Collections {


struct __declspec(uuid("575933df-34fe-4480-af15-07691f3d5d9b")) __declspec(novtable) IVectorChangedEventArgs : IInspectable
{
	virtual HRESULT __stdcall get_CollectionChange(winrt::Windows::Foundation::Collections::CollectionChange * value) = 0;
	virtual HRESULT __stdcall get_Index(unsigned * value) = 0;
};

}}}}}

namespace winrt { namespace Windows { namespace Foundation { namespace Collections {

struct IVectorChangedEventArgs;

template <typename D>
class impl_IVectorChangedEventArgs
{
	auto shim() const { return impl::shim<D, IVectorChangedEventArgs>(this); }

public:

	CollectionChange CollectionChange() const;
	unsigned Index() const;
};

}}}}

namespace winrt { namespace impl {

template <> struct traits<Windows::Foundation::Collections::IVectorChangedEventArgs>
{
	using abi = ABI::Windows::Foundation::Collections::IVectorChangedEventArgs;
	template <typename T> using methods = Windows::Foundation::Collections::impl_IVectorChangedEventArgs<T>;
};

}}

namespace winrt { namespace Windows { namespace Foundation { namespace Collections {

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
	check(shim()->get_CollectionChange(&value));
	return value;
}

template <typename T> unsigned impl_IVectorChangedEventArgs<T>::Index() const
{
	unsigned index = 0;
	check(shim()->get_Index(&index));
	return index;
}

}}}}

namespace winrt { namespace ABI { namespace Windows { namespace Foundation { namespace Collections {

template <typename T> struct IIterator;
template <typename T> struct IIterable;
template <typename K, typename V> struct IKeyValuePair;
template <typename T> struct IVectorView;
template <typename T> struct IVector;
template <typename K, typename V> struct IMapView;
template <typename K, typename V> struct IMap;
template <typename K> struct IMapChangedEventArgs;
template <typename K, typename V> struct IMapChangedEventHandler;
template <typename K, typename V> struct IObservableMap;
template <typename T> struct IVectorChangedEventHandler;
template <typename T> struct IObservableVector;

template <typename T>
struct __declspec(novtable) impl_IIterator : IInspectable
{
	virtual HRESULT __stdcall get_Current(argument_out<T> current) = 0;
	virtual HRESULT __stdcall get_HasCurrent(bool * hasCurrent) = 0;
	virtual HRESULT __stdcall abi_MoveNext(bool * hasCurrent) = 0;
	virtual HRESULT __stdcall abi_GetMany(unsigned capacity, argument_out<T> value, unsigned * actual) = 0;

};

template <typename T>
struct __declspec(novtable) impl_IIterable : IInspectable
{
	virtual HRESULT __stdcall abi_First(IIterator<T> ** first) = 0;
};

template <typename K, typename V>
struct __declspec(novtable) impl_IKeyValuePair : IInspectable
{
	virtual HRESULT __stdcall get_Key(argument_out<K> key) = 0;
	virtual HRESULT __stdcall get_Value(argument_out<V> value) = 0;
};

template <typename T>
struct __declspec(novtable) impl_IVectorView : IInspectable
{
	virtual HRESULT __stdcall abi_GetAt(unsigned index, argument_out<T> item) = 0;
	virtual HRESULT __stdcall get_Size(unsigned * size) = 0;
	virtual HRESULT __stdcall abi_IndexOf(argument_in<T> value, unsigned * index, bool * found) = 0;
	virtual HRESULT __stdcall abi_GetMany(unsigned startIndex, unsigned capacity, argument_out<T> value, unsigned * actual) = 0;
};

template <typename T>
struct __declspec(novtable) impl_IVector : IInspectable
{
	virtual HRESULT __stdcall abi_GetAt(unsigned index, argument_out<T> item) = 0;
	virtual HRESULT __stdcall get_Size(unsigned * size) = 0;
	virtual HRESULT __stdcall abi_GetView(IVectorView<T> ** view) = 0;
	virtual HRESULT __stdcall abi_IndexOf(argument_in<T> value, unsigned * index, bool * found) = 0;
	virtual HRESULT __stdcall abi_SetAt(unsigned index, argument_in<T> item) = 0;
	virtual HRESULT __stdcall abi_InsertAt(unsigned index, argument_in<T> item) = 0;
	virtual HRESULT __stdcall abi_RemoveAt(unsigned index) = 0;
	virtual HRESULT __stdcall abi_Append(argument_in<T> item) = 0;
	virtual HRESULT __stdcall abi_RemoveAtEnd() = 0;
	virtual HRESULT __stdcall abi_Clear() = 0;
	virtual HRESULT __stdcall abi_GetMany(unsigned startIndex, unsigned capacity, argument_out<T> value, unsigned * actual) = 0;
	virtual HRESULT __stdcall abi_ReplaceAll(unsigned count, argument_out<T> value) = 0;

};

template <typename K, typename V>
struct __declspec(novtable) impl_IMapView : IInspectable
{
	virtual HRESULT __stdcall abi_Lookup(argument_in<K> key, argument_out<V> value) = 0;
	virtual HRESULT __stdcall get_Size(unsigned * size) = 0;
	virtual HRESULT __stdcall abi_HasKey(argument_in<K> key, bool * found) = 0;
	virtual HRESULT __stdcall abi_Split(IMapView<K, V> ** firstPartition, IMapView<K, V> ** secondPartition) = 0;
};

template <typename K, typename V>
struct __declspec(novtable) impl_IMap : IInspectable
{
	virtual HRESULT __stdcall abi_Lookup(argument_in<K> key, argument_out<V> value) = 0;
	virtual HRESULT __stdcall get_Size(unsigned * size) = 0;
	virtual HRESULT __stdcall abi_HasKey(argument_in<K> key, bool * found) = 0;
	virtual HRESULT __stdcall abi_GetView(IMapView<K, V> ** view) = 0;
	virtual HRESULT __stdcall abi_Insert(argument_in<K> key, V const & value, bool * replaced) = 0;
	virtual HRESULT __stdcall abi_Remove(argument_in<K> key) = 0;
	virtual HRESULT __stdcall abi_Clear() = 0;
};

template <typename K>
struct __declspec(novtable) impl_IMapChangedEventArgs : IInspectable
{
	virtual HRESULT __stdcall get_CollectionChange(winrt::Windows::Foundation::Collections::CollectionChange * value) = 0;
	virtual HRESULT __stdcall get_Key(argument_out<K> value) = 0;
};

template <typename K, typename V>
struct __declspec(novtable) impl_IMapChangedEventHandler : IUnknown
{
	virtual HRESULT __stdcall abi_Invoke(IObservableMap<K, V> * sender, IMapChangedEventArgs<K> * args) = 0;
};

template <typename K, typename V>
struct __declspec(novtable) impl_IObservableMap : IInspectable
{
	virtual HRESULT __stdcall add_MapChanged(IMapChangedEventHandler<K, V> * handler, long long * token) = 0;
	virtual HRESULT __stdcall remove_MapChanged(long long token) = 0;
};

template <typename T>
struct __declspec(novtable) impl_IVectorChangedEventHandler : IUnknown
{
	virtual HRESULT __stdcall abi_Invoke(IObservableVector<T> * sender, IVectorChangedEventArgs * args) = 0;
};

template <typename T>
struct __declspec(novtable) impl_IObservableVector : IInspectable
{
	virtual HRESULT __stdcall add_VectorChanged(IVectorChangedEventHandler<T> * handler, long long *  token) = 0;
	virtual HRESULT __stdcall remove_VectorChanged(long long token) = 0;
};

}}}}}

namespace winrt { namespace Windows { namespace Foundation { namespace Collections {

template <typename T> struct IIterator;
template <typename T> struct IIterable;
template <typename K, typename V> struct IKeyValuePair;
template <typename T> struct IVectorView;
template <typename T> struct IVector;
template <typename K, typename V> struct IMapView;
template <typename K, typename V> struct IMap;
template <typename K> struct IMapChangedEventArgs;
template <typename K, typename V> struct IMapChangedEventHandler;
template <typename K, typename V> struct IObservableMap;
template <typename T> struct IVectorChangedEventHandler;
template <typename T> struct IObservableVector;

template <typename D, typename T>
class impl_IIterator
{
	auto shim() const { return impl::shim<D, IIterator<T>>(this); }

public:

	T Current() const
	{
		T result = impl::argument<T>::empty();
		check(shim()->get_Current(put(result)));
		return result;
	}

	bool HasCurrent() const
	{
		bool temp = false;
		check(shim()->get_HasCurrent(&temp));
		return temp;
	}

	bool MoveNext() const
	{
		bool temp = false;
		check(shim()->abi_MoveNext(&temp));
		return temp;
	}

	impl_IIterator & operator++()
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
		check(shim()->abi_First(put(iterator)));
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
		K result = impl::argument<K>::empty();
		check(shim()->get_Key(put(result)));
		return result;
	}

	V Value() const
	{
		V result = impl::argument<V>::empty();
		check(shim()->get_Value(put(result)));
		return result;
	}
};

template <typename D, typename T>
class impl_IVectorView
{
	auto shim() const { return impl::shim<D, IVectorView<T>>(this); }

public:

	T GetAt(unsigned const index) const
	{
		T result = impl::argument<T>::empty();
		check(shim()->abi_GetAt(index, put(result)));
		return result;
	}

	unsigned Size() const
	{
		unsigned size = 0;
		check(shim()->get_Size(&size));
		return size;
	}

	bool IndexOf(T const & value, unsigned & index) const
	{
		bool found = false;
		check(shim()->abi_IndexOf(get(value), &index, &found));
		return 0 != found;
	}
};

template <typename D, typename T>
class impl_IVector
{
	auto shim() const { return impl::shim<D, IVector<T>>(this); }

public:

	T GetAt(unsigned const index) const
	{
		T result = impl::argument<T>::empty();
		check(shim()->abi_GetAt(index, put(result)));
		return result;
	}

	unsigned Size() const
	{
		unsigned size = 0;
		check(shim()->get_Size(&size));
		return size;
	}

	IVectorView<T> GetView() const
	{
		IVectorView<T> view;
		check(shim()->abi_GetView(put(view)));
		return view;
	}

	bool IndexOf(T const & value, unsigned & index) const
	{
		bool found = false;
		check(shim()->abi_IndexOf(abi(value), &index, &found));
		return 0 != found;
	}

	void SetAt(unsigned const index, T const & value) const
	{
		check(shim()->abi_SetAt(index, abi(value)));
	}

	void InsertAt(unsigned const index, T const & value) const
	{
		check(shim()->abi_InsertAt(index, abi(value)));
	}

	void RemoveAt(unsigned const index) const
	{
		check(shim()->abi_RemoveAt(index));
	}

	void Append(T const & value) const
	{
		check(shim()->abi_Append(abi(value)));
	}

	void RemoveAtEnd() const
	{
		check(shim()->abi_RemoveAtEnd());
	}

	void Clear() const
	{
		check(shim()->abi_Clear());
	}
};

template <typename D, typename K, typename V>
class impl_IMapView
{
	auto shim() const { return impl::shim<D, IMapView<K, V>>(this); }

public:

	V Lookup(K const & key) const
	{
		V result = impl::argument<V>::empty();
		check(shim()->abi_Lookup(abi(key), put(result)));
		return result;
	}

	unsigned Size() const
	{
		unsigned size = 0;
		check(shim()->get_Size(&size));
		return size;
	}

	bool HasKey(K const & key) const
	{
		bool found = false;
		check(shim()->abi_HasKey(abi(key), &found));
		return 0 != found;
	}

	void Split(IMapView<K, V> & firstPartition, IMapView<K, V> & secondPartition)
	{
		check(shim()->abi_Split(put(firstPartition), put(secondPartition)));
	}
};

template <typename D, typename K, typename V>
class impl_IMap
{
	auto shim() const { return impl::shim<D, IMap<K, V>>(this); }

public:

	V Lookup(K const & key) const
	{
		V result = impl::argument<V>::empty();
		check(shim()->abi_Lookup(abi(key), put(result)));
		return result;
	}

	unsigned Size() const
	{
		unsigned size = 0;
		check(shim()->get_Size(&size));
		return size;
	}

	bool HasKey(K const & key) const
	{
		bool found = false;
		check(shim()->abi_HasKey(abi(key), &found));
		return 0 != found;
	}

	IMapView<K, V> GetView() const
	{
		IMapView<K, V> view;
		check(shim()->abi_GetView(put(view)));
		return view;
	}

	bool Insert(K const & key, V const & value) const
	{
		bool replaced = false;
		check(shim()->abi_Insert(abi(key), abi(value), &replaced));
		return 0 != replaced;
	}

	void Remove(K const & key) const
	{
		check(shim()->abi_Remove(abi(key)));
	}

	void Clear() const
	{
		check(shim()->abi_Clear());
	}
};

template <typename D, typename K>
class impl_IMapChangedEventArgs
{
	auto shim() const { return impl::shim<D, IMapChangedEventArgs<K>>(this); }

public:

	CollectionChange CollectionChange() const
	{
		CollectionChange value = {};
		check(shim()->get_CollectionChange(&value));
		return value;
	}

	K Key() const
	{
		K result = impl::argument<K>::empty();
		check(shim()->get_Key(put(result)));
		return result;
	}
};

template <typename D, typename K, typename V>
class impl_IMapChangedEventHandler
{
	auto shim() const { return impl::shim<D, IMapChangedEventHandler<K, V>>(this); }

public:

	void Invoke(IObservableMap<K, V> const & sender, IMapChangedEventArgs<K> const & args) const
	{
		check(shim()->abi_Invoke(get(sender), get(args)));
	}
};

template <typename D, typename K, typename V>
class impl_IObservableMap
{
	auto shim() const { return impl::shim<D, IObservableMap<K, V>>(this); }

public:

	long long MapChanged(IMapChangedEventHandler<K, V> const & handler) const
	{
		long long cookie = {};
		check(shim()->add_MapChanged(get(handler), &cookie));
		return cookie;
	}

	template <typename T> long long MapChanged(T handler) const
	{
		return MapChanged(MapChangedEventHandler<K, V>(handler));
	}

	void MapChanged(long long const cookie) const
	{
		check(shim()->remove_MapChanged(cookie));
	}
};

template <typename D, typename T>
class impl_IVectorChangedEventHandler
{
	auto shim() const { return impl::shim<D, IVectorChangedEventHandler<T>>(this); }

public:

	void Invoke(IObservableVector<T> const & sender, IVectorChangedEventArgs const & args) const
	{
		check(shim()->abi_Invoke(get(sender), get(args)));
	}
};

template <typename D, typename T>
class impl_IObservableVector
{
	auto shim() const { return impl::shim<D, IObservableVector<T>>(this); }

public:

	long long VectorChanged(IVectorChangedEventHandler<T> const & handler) const
	{
		long long cookie = {};
		check(shim()->add_VectorChanged(get(handler), &cookie));
		return cookie;
	}

	template <typename Handler> long long VectorChanged(Handler handler) const
	{
		return VectorChanged(VectorChangedEventHandler<T>(handler));
	}

	void VectorChanged(long long const cookie) const
	{
		check(shim()->remove_VectorChanged(cookie));
	}
};

template <typename T>
struct IIterator :
	IInspectable,
	impl_IIterator<IIterator<T>, T>
{
	IIterator(std::nullptr_t = nullptr) noexcept {}
	auto operator->() const noexcept { return ptr<IIterator>(m_ptr); }
};

template <typename T>
struct IIterable :
	IInspectable,
	impl_IIterable<IIterable<T>, T>
{
	IIterable(std::nullptr_t = nullptr) noexcept {}
	auto operator->() const noexcept { return ptr<IIterable>(m_ptr); }
};

template <typename K, typename V>
struct IKeyValuePair :
	IInspectable,
	impl_IKeyValuePair<IKeyValuePair<K, V>, K, V>
{
	IKeyValuePair(std::nullptr_t = nullptr) noexcept {}
	auto operator->() const noexcept { return ptr<IKeyValuePair>(m_ptr); }
};

template <typename T>
struct IVectorView :
	IInspectable,
	impl_IVectorView<IVectorView<T>, T>,
	requires<IVectorView<T>, IIterable<T>>
{
	IVectorView(std::nullptr_t = nullptr) noexcept {}
	auto operator->() const noexcept { return ptr<IVectorView>(m_ptr); }
};

template <typename T>
struct IVector :
	IInspectable,
	impl_IVector<IVector<T>, T>,
	requires<IVector<T>, IIterable<T>>
{
	IVector(std::nullptr_t = nullptr) noexcept {}
	auto operator->() const noexcept { return ptr<IVector>(m_ptr); }
};

template <typename K, typename V>
struct IMapView :
	IInspectable,
	impl_IMapView<IMapView<K, V>, K, V>,
	requires<IMapView<K, V>, IIterable<IKeyValuePair<K, V>>>
{
	IMapView(std::nullptr_t = nullptr) noexcept {}
	auto operator->() const noexcept { return ptr<IMapView>(m_ptr); }
};

template <typename K, typename V>
struct IMap :
	IInspectable,
	impl_IMap<IMap<K, V>, K, V>,
	requires<IMap<K, V>, IIterable<IKeyValuePair<K, V>>>
{
	IMap(std::nullptr_t = nullptr) noexcept {}
	auto operator->() const noexcept { return ptr<IMap>(m_ptr); }
};

template <typename K>
struct IMapChangedEventArgs :
	IInspectable,
	impl_IMapChangedEventArgs<IMapChangedEventArgs<K>, K>
{
	IMapChangedEventArgs(std::nullptr_t = nullptr) noexcept {}
	auto operator->() const noexcept { return ptr<IMapChangedEventArgs>(m_ptr); }
};

template <typename K, typename V>
struct IMapChangedEventHandler :
	IUnknown,
	impl_IMapChangedEventHandler<IMapChangedEventHandler<K, V>, K, V>
{
	IMapChangedEventHandler(std::nullptr_t = nullptr) noexcept {}
	auto operator->() const noexcept { return ptr<IMapChangedEventHandler>(m_ptr); }
};

template <typename K, typename V>
struct IObservableMap :
	IInspectable,
	impl_IObservableMap<IObservableMap<K, V>, K, V>,
	requires<IObservableMap<K, V>, IMap<K, V>, IIterable<IKeyValuePair<K, V>>>
{
	IObservableMap(std::nullptr_t = nullptr) noexcept {}
	auto operator->() const noexcept { return ptr<IObservableMap>(m_ptr); }
};

template <typename T>
struct IVectorChangedEventHandler :
	IUnknown,
	impl_IVectorChangedEventHandler<IVectorChangedEventHandler<T>, T>
{
	IVectorChangedEventHandler(std::nullptr_t = nullptr) noexcept {}
	auto operator->() const noexcept { return ptr<IVectorChangedEventHandler>(m_ptr); }
};

template <typename T>
struct IObservableVector :
	IInspectable,
	impl_IObservableVector<IObservableVector<T>, T>,
	requires<IObservableVector<T>, IVector<T>, IIterable<T>>
{
	IObservableVector(std::nullptr_t = nullptr) noexcept {}
	auto operator->() const noexcept { return ptr<IObservableVector>(m_ptr); }
};

}}}}

namespace winrt { namespace impl {

template <typename T> struct traits<Windows::Foundation::Collections::IIterator<T>>
{
	using abi = ABI::Windows::Foundation::Collections::IIterator<abi<T>>;
	template <typename D> using methods = Windows::Foundation::Collections::impl_IIterator<D, T>;
};

template <typename T> struct traits<Windows::Foundation::Collections::IIterable<T>>
{
	using abi = ABI::Windows::Foundation::Collections::IIterable<abi<T>>;
	template <typename D> using methods = Windows::Foundation::Collections::impl_IIterable<D, T>;
};

template <typename K, typename V> struct traits<Windows::Foundation::Collections::IKeyValuePair<K, V>>
{
	using abi = ABI::Windows::Foundation::Collections::IKeyValuePair<abi<K>, abi<V>>;
	template <typename D> using methods = Windows::Foundation::Collections::impl_IKeyValuePair<D, K, V>;
};

template <typename T> struct traits<Windows::Foundation::Collections::IVectorView<T>>
{
	using abi = ABI::Windows::Foundation::Collections::IVectorView<abi<T>>;
	template <typename D> using methods = Windows::Foundation::Collections::impl_IVectorView<D, T>;
};

template <typename T> struct traits<Windows::Foundation::Collections::IVector<T>>
{
	using abi = ABI::Windows::Foundation::Collections::IVector<abi<T>>;
	template <typename D> using methods = Windows::Foundation::Collections::impl_IVector<D, T>;
};

template <typename K, typename V> struct traits<Windows::Foundation::Collections::IMapView<K, V>>
{
	using abi = ABI::Windows::Foundation::Collections::IMapView<abi<K>, abi<V>>;
	template <typename D> using methods = Windows::Foundation::Collections::impl_IMapView<D, K, V>;
};

template <typename K, typename V> struct traits<Windows::Foundation::Collections::IMap<K, V>>
{
	using abi = ABI::Windows::Foundation::Collections::IMap<abi<K>, abi<V>>;
	template <typename D> using methods = Windows::Foundation::Collections::impl_IMap<D, K, V>;
};

template <typename K> struct traits<Windows::Foundation::Collections::IMapChangedEventArgs<K>>
{
	using abi = ABI::Windows::Foundation::Collections::IMapChangedEventArgs<abi<K>>;
	template <typename D> using methods = Windows::Foundation::Collections::impl_IMapChangedEventArgs<D, K>;
};

template <typename K, typename V> struct traits<Windows::Foundation::Collections::IMapChangedEventHandler<K, V>>
{
	using abi = ABI::Windows::Foundation::Collections::IMapChangedEventHandler<abi<K>, abi<V>>;
	template <typename D> using methods = Windows::Foundation::Collections::impl_IMapChangedEventHandler<D, K, V>;
};

template <typename K, typename V> struct traits<Windows::Foundation::Collections::IObservableMap<K, V>>
{
	using abi = ABI::Windows::Foundation::Collections::IObservableMap<abi<K>, abi<V>>;
	template <typename D> using methods = Windows::Foundation::Collections::impl_IObservableMap<D, K, V>;
};

template <typename T> struct traits<Windows::Foundation::Collections::IVectorChangedEventHandler<T>>
{
	using abi = ABI::Windows::Foundation::Collections::IVectorChangedEventHandler<abi<T>>;
	template <typename D> using methods = Windows::Foundation::Collections::impl_IVectorChangedEventHandler<D, T>;
};

template <typename T> struct traits<Windows::Foundation::Collections::IObservableVector<T>>
{
	using abi = ABI::Windows::Foundation::Collections::IObservableVector<abi<T>>;
	template <typename D> using methods = Windows::Foundation::Collections::impl_IObservableVector<D, T>;
};

}}


namespace winrt { namespace impl {

template <typename T>
struct fast_iterator
{
	fast_iterator(T const & collection, unsigned const index) noexcept :
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

	bool operator==(fast_iterator const & other) const noexcept
	{
		MODERN_ASSERT(m_collection == other.m_collection);
		return m_index == other.m_index;
	}

	bool operator!=(fast_iterator const & other) const noexcept
	{
		return !(*this == other);
	}

private:

	T const * m_collection = nullptr;
	unsigned m_index = 0;
};

}}

namespace winrt { namespace Windows { namespace Foundation { namespace Collections {

template <typename T, typename std::enable_if<!impl::has_GetAt<T>::value>::type * = nullptr>
auto begin(T const & collection) -> decltype(collection.First())
{
	auto result = collection.First();

	if (!result.HasCurrent())
	{
		return {};
	}

	return result;
}

template <typename T, typename std::enable_if<!impl::has_GetAt<T>::value>::type * = nullptr>
auto end(T const & collection) -> decltype(collection.First())
{
	collection;
	return {};
}

template <typename T, typename std::enable_if<impl::has_GetAt<T>::value>::type * = nullptr>
impl::fast_iterator<T> begin(T const & collection) noexcept
{
	return impl::fast_iterator<T>(collection, 0);
}

template <typename T, typename std::enable_if<impl::has_GetAt<T>::value>::type * = nullptr>
impl::fast_iterator<T> end(T const & collection)
{
	return impl::fast_iterator<T>(collection, collection.Size());
}

}}}}
