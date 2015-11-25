
namespace Modern {

template <typename T>
class FastIterator
{
	T const * m_collection = nullptr;
	unsigned m_index = 0;

public:

	FastIterator(T const & collection, unsigned const index) noexcept :
		m_collection(&collection),
		m_index(index)
	{}

	FastIterator & operator++() noexcept
	{
		++m_index;
		return *this;
	}

	auto operator *() const
	{
		return m_collection->GetAt(m_index);
	}

	bool operator==(FastIterator const & other) const noexcept
	{
		MODERN_ASSERT(m_collection == other.m_collection);
		return m_index == other.m_index;
	}

	bool operator!=(FastIterator const & other) const noexcept
	{
		return !(*this == other);
	}
};

}

namespace Modern { namespace Windows { namespace Foundation { namespace Collections {

enum class CollectionChange
{
	Reset,
	ItemInserted,
	ItemRemoved,
	ItemChanged,
};

}}}}


namespace Modern { namespace ABI { namespace Windows { namespace Foundation { namespace Collections {


struct __declspec(uuid("575933df-34fe-4480-af15-07691f3d5d9b")) __declspec(novtable) IVectorChangedEventArgs : IInspectable
{
	virtual HRESULT __stdcall get_CollectionChange(Modern::Windows::Foundation::Collections::CollectionChange * value) = 0;
	virtual HRESULT __stdcall get_Index(unsigned * value) = 0;
};

}}}}}

namespace Modern { namespace Windows { namespace Foundation { namespace Collections {

template <typename D>
struct impl_IVectorChangedEventArgs
{
	CollectionChange CollectionChange() const
	{
		Collections::CollectionChange value = {};
		check(static_cast<D const &>(*this)->get_CollectionChange(&value));
		return value;
	}

	unsigned Index() const
	{
		unsigned index;
		check(static_cast<D const &>(*this)->get_Index(&index));
		return index;
	}
};

struct IVectorChangedEventArgs;

}}}}

namespace Modern {

template <> struct Traits<Windows::Foundation::Collections::IVectorChangedEventArgs>
{
	using Abi = ABI::Windows::Foundation::Collections::IVectorChangedEventArgs;
	template <typename T> using Methods = Windows::Foundation::Collections::impl_IVectorChangedEventArgs<T>;
};

}

namespace Modern { namespace Windows { namespace Foundation { namespace Collections {

struct IVectorChangedEventArgs :
	IInspectable,
	impl_IVectorChangedEventArgs<IVectorChangedEventArgs>
{
	IVectorChangedEventArgs(std::nullptr_t = nullptr) noexcept {}
	auto operator->() const noexcept { return static_cast<AbiPtr<IVectorChangedEventArgs>>(m_ptr); }
};

}}}}

namespace Modern { namespace ABI { namespace Windows { namespace Foundation { namespace Collections {

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
	virtual HRESULT __stdcall get_Current(ArgOut<T> current) = 0;
	virtual HRESULT __stdcall get_HasCurrent(boolean * hasCurrent) = 0;
	virtual HRESULT __stdcall abi_MoveNext(boolean * hasCurrent) = 0;
	virtual HRESULT __stdcall abi_GetMany(unsigned capacity, ArgOut<T> value, unsigned * actual) = 0;

};

template <typename T>
struct __declspec(novtable) impl_IIterable : IInspectable
{
	virtual HRESULT __stdcall abi_First(IIterator<T> ** first) = 0;
};

template <typename K, typename V>
struct __declspec(novtable) impl_IKeyValuePair : IInspectable
{
	virtual HRESULT __stdcall get_Key(ArgOut<K> key) = 0;
	virtual HRESULT __stdcall get_Value(ArgOut<V> value) = 0;
};

template <typename T>
struct __declspec(novtable) impl_IVectorView : IInspectable
{
	virtual HRESULT __stdcall abi_GetAt(unsigned index, ArgOut<T> item) = 0;
	virtual HRESULT __stdcall get_Size(unsigned * size) = 0;
	virtual HRESULT __stdcall abi_IndexOf(ArgIn<T> value, unsigned * index, boolean * found) = 0;
	virtual HRESULT __stdcall abi_GetMany(unsigned startIndex, unsigned capacity, ArgOut<T> value, unsigned * actual) = 0;
};

template <typename T>
struct __declspec(novtable) impl_IVector : IInspectable
{
	virtual HRESULT __stdcall abi_GetAt(unsigned index, ArgOut<T> item) = 0;
	virtual HRESULT __stdcall get_Size(unsigned * size) = 0;
	virtual HRESULT __stdcall abi_GetView(IVectorView<T> ** view) = 0;
	virtual HRESULT __stdcall abi_IndexOf(ArgIn<T> value, unsigned * index, boolean * found) = 0;
	virtual HRESULT __stdcall abi_SetAt(unsigned index, ArgIn<T> item) = 0;
	virtual HRESULT __stdcall abi_InsertAt(unsigned index, ArgIn<T> item) = 0;
	virtual HRESULT __stdcall abi_RemoveAt(unsigned index) = 0;
	virtual HRESULT __stdcall abi_Append(ArgIn<T> item) = 0;
	virtual HRESULT __stdcall abi_RemoveAtEnd() = 0;
	virtual HRESULT __stdcall abi_Clear() = 0;
	virtual HRESULT __stdcall abi_GetMany(unsigned startIndex, unsigned capacity, ArgOut<T> value, unsigned * actual) = 0;
	virtual HRESULT __stdcall abi_ReplaceAll(unsigned count, ArgOut<T> value) = 0;

};

template <typename K, typename V>
struct __declspec(novtable) impl_IMapView : IInspectable
{
	virtual HRESULT __stdcall abi_Lookup(K const & key, ArgOut<V> value) = 0;
	virtual HRESULT __stdcall get_Size(unsigned int * size) = 0;
	virtual HRESULT __stdcall abi_HasKey(K const & key, boolean * found) = 0;
	virtual HRESULT __stdcall abi_Split(IMapView<K, V> ** firstPartition, IMapView<K, V> ** secondPartition) = 0;
};

template <typename K, typename V>
struct __declspec(novtable) impl_IMap : IInspectable
{
	virtual HRESULT __stdcall abi_Lookup(K const & key, ArgOut<V> value) = 0;
	virtual HRESULT __stdcall get_Size(unsigned int * size) = 0;
	virtual HRESULT __stdcall abi_HasKey(K const & key, boolean * found) = 0;
	virtual HRESULT __stdcall abi_GetView(IMapView<K, V> ** view) = 0;
	virtual HRESULT __stdcall abi_Insert(K const & key, V const & value, boolean * replaced) = 0;
	virtual HRESULT __stdcall abi_Remove(K const & key) = 0;
	virtual HRESULT __stdcall abi_Clear() = 0;
};

template <typename K>
struct __declspec(novtable) impl_IMapChangedEventArgs : IInspectable
{
	virtual HRESULT __stdcall get_CollectionChange(Modern::Windows::Foundation::Collections::CollectionChange * value) = 0;
	virtual HRESULT __stdcall get_Key(ArgOut<K> value) = 0;
};

template <typename K, typename V>
struct __declspec(novtable) impl_IMapChangedEventHandler : IUnknown
{
	virtual HRESULT __stdcall abi_Invoke(IObservableMap<K, V> * sender, IMapChangedEventArgs<K> * args) = 0;
};

template <typename K, typename V>
struct __declspec(novtable) impl_IObservableMap : IInspectable
{
	virtual HRESULT __stdcall add_MapChanged(IMapChangedEventHandler<K, V> * handler, EventRegistrationToken * token) = 0;
	virtual HRESULT __stdcall remove_MapChanged(EventRegistrationToken token) = 0;
};

template <typename T>
struct __declspec(novtable) impl_IVectorChangedEventHandler : IUnknown
{
	virtual HRESULT __stdcall abi_Invoke(IObservableVector<T> * sender, IVectorChangedEventArgs * args) = 0;
};

template <typename T>
struct __declspec(novtable) impl_IObservableVector : IInspectable
{
	virtual HRESULT __stdcall add_VectorChanged(IVectorChangedEventHandler<T> * handler, EventRegistrationToken *  token) = 0;
	virtual HRESULT __stdcall remove_VectorChanged(EventRegistrationToken token) = 0;
};

}}}}}

namespace Modern { namespace Windows { namespace Foundation { namespace Collections {

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
struct impl_IIterator
{
	T Current() const
	{
		T result = Argument<T>::Empty();
		check(static_cast<D const &>(*this)->get_Current(abi(&result)));
		return result;
	}

	bool HasCurrent() const
	{
		boolean temp = 0;
		check(static_cast<D const &>(*this)->get_HasCurrent(&temp));
		return 0 != temp;
	}

	bool MoveNext() const
	{
		boolean temp = 0;
		check(static_cast<D const &>(*this)->abi_MoveNext(&temp));
		return 0 != temp;
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
struct impl_IIterable
{
	IIterator<T> First() const
	{
		IIterator<T> iterator;
		check(static_cast<IIterable<T> const &>(static_cast<D const &>(*this))->abi_First(put(iterator)));
		return iterator;
	}
};

template <typename D, typename K, typename V>
struct impl_IKeyValuePair
{
	K Key() const
	{
		K result = Argument<K>::Empty();
		check(static_cast<D const &>(*this)->get_Key(abi(&result)));
		return result;
	}

	V Value() const
	{
		V result = Argument<V>::Empty();
		check(static_cast<D const &>(*this)->get_Value(abi(&result)));
		return result;
	}
};

template <typename D, typename T>
struct impl_IVectorView
{
	T GetAt(unsigned const index) const
	{
		T result = Argument<T>::Empty();
		check(static_cast<IVectorView<T> const &>(static_cast<D const &>(*this))->abi_GetAt(index, abi(&result)));
		return result;
	}

	unsigned Size() const
	{
		unsigned size = 0;
		check(static_cast<IVectorView<T> const &>(static_cast<D const &>(*this))->get_Size(&size));
		return size;
	}

	bool IndexOf(T const & value, unsigned & index) const
	{
		boolean found = false;
		check(static_cast<IVectorView<T> const &>(static_cast<D const &>(*this))->abi_IndexOf(get(value), &index, &found));
		return 0 != found;
	}
};

template <typename D, typename T>
struct impl_IVector
{
	T GetAt(unsigned const index) const
	{
		T result = Argument<T>::Empty();
		check(static_cast<IVector<T> const &>(static_cast<D const &>(*this))->abi_GetAt(index, abi(&result)));
		return result;
	}

	unsigned Size() const
	{
		unsigned size = 0;
		check(static_cast<IVector<T> const &>(static_cast<D const &>(*this))->get_Size(&size));
		return size;
	}

	IVectorView<T> GetView() const
	{
		IVectorView<T> view;
		check(static_cast<IVector<T> const &>(static_cast<D const &>(*this))->abi_GetView(put(view)));
		return view;
	}

	bool IndexOf(T const & value, unsigned & index) const
	{
		boolean found = false;
		check(static_cast<IVector<T> const &>(static_cast<D const &>(*this))->abi_IndexOf(abi(value), &index, &found));
		return 0 != found;
	}

	void SetAt(unsigned const index, T const & value) const
	{
		check(static_cast<IVector<T> const &>(static_cast<D const &>(*this))->abi_SetAt(index, abi(value)));
	}

	void InsertAt(unsigned const index, T const & value) const
	{
		check(static_cast<IVector<T> const &>(static_cast<D const &>(*this))->abi_InsertAt(index, abi(value)));
	}

	void RemoveAt(unsigned const index) const
	{
		check(static_cast<IVector<T> const &>(static_cast<D const &>(*this))->abi_RemoveAt(index));
	}

	void Append(T const & value) const
	{
		check(static_cast<IVector<T> const &>(static_cast<D const &>(*this))->abi_Append(abi(value)));
	}

	void RemoveAtEnd() const
	{
		check(static_cast<IVector<T> const &>(static_cast<D const &>(*this))->abi_RemoveAtEnd());
	}

	void Clear() const
	{
		check(static_cast<IVector<T> const &>(static_cast<D const &>(*this))->abi_Clear());
	}
};

template <typename D, typename K, typename V>
struct impl_IMapView
{
	V Lookup(K const & key) const
	{
		V result = Argument<V>::Empty();
		check(static_cast<IMapView<K, V> const &>(static_cast<D const &>(*this))->abi_Lookup(abi(key), abi(&result)));
		return result;
	}

	unsigned Size() const
	{
		unsigned size = 0;
		check(static_cast<IMapView<K, V> const &>(static_cast<D const &>(*this))->get_Size(&size));
		return size;
	}

	bool HasKey(K const & key) const
	{
		boolean found = false;
		check(static_cast<IMapView<K, V> const &>(static_cast<D const &>(*this))->abi_HasKey(abi(key), &found));
		return 0 != found;
	}

	void Split(IMapView<K, V> & firstPartition, IMapView<K, V> & secondPartition)
	{
		check(static_cast<IMapView<K, V> const &>(static_cast<D const &>(*this))->abi_Split(put(firstPartition), put(secondPartition)));
	}
};

template <typename D, typename K, typename V>
struct impl_IMap
{
	V Lookup(K const & key) const
	{
		V result = Argument<V>::Empty();
		check(static_cast<IMap<K, V> const &>(static_cast<D const &>(*this))->abi_Lookup(abi(key), abi(&result)));
		return result;
	}

	unsigned Size() const
	{
		unsigned size = 0;
		check(static_cast<IMap<K, V> const &>(static_cast<D const &>(*this))->get_Size(&size));
		return size;
	}

	bool HasKey(K const & key) const
	{
		boolean found = false;
		check(static_cast<IMap<K, V> const &>(static_cast<D const &>(*this))->abi_HasKey(abi(key), &found));
		return 0 != found;
	}

	IMapView<K, V> GetView() const
	{
		IMapView<K, V> view;
		check(static_cast<IMap<K, V> const &>(static_cast<D const &>(*this))->abi_GetView(put(view)));
		return view;
	}

	bool Insert(K const & key, V const & value) const
	{
		boolean replaced = false;
		check(static_cast<IMap<K, V> const &>(static_cast<D const &>(*this))->abi_Insert(abi(key), abi(value), &replaced));
		return 0 != replaced;
	}

	void Remove(K const & key) const
	{
		check(static_cast<IMap<K, V> const &>(static_cast<D const &>(*this))->abi_Remove(abi(key)));
	}

	void Clear() const
	{
		check(static_cast<IMap<K, V> const &>(static_cast<D const &>(*this))->abi_Clear());
	}
};

template <typename D, typename K>
struct impl_IMapChangedEventArgs
{
	CollectionChange CollectionChange() const
	{
		CollectionChange value = {};
		check(static_cast<D const &>(*this)->get_CollectionChange(&value));
		return value;
	}

	K Key() const
	{
		K result = Argument<K>::Empty();
		check(static_cast<D const &>(*this)->get_Key(abi(&result)));
		return result;
	}
};

template <typename D, typename K, typename V>
struct impl_IMapChangedEventHandler
{
	void Invoke(IObservableMap<K, V> const & sender, IMapChangedEventArgs<K> const & args) const
	{
		check(static_cast<D const &>(*this)->abi_Invoke(get(sender), get(args)));
	}
};

template <typename D, typename K, typename V>
struct impl_IObservableMap
{
	EventRegistrationToken MapChanged(IMapChangedEventHandler<K, V> const & handler) const
	{
		EventRegistrationToken cookie = {};
		check(static_cast<IObservableMap<K, V> const &>(static_cast<D const &>(*this))->add_MapChanged(get(handler), &cookie));
		return cookie;
	}

	template <typename T> EventRegistrationToken MapChanged(T handler) const
	{
		return MapChanged(MapChangedEventHandler<K, V>(handler));
	}

	void MapChanged(EventRegistrationToken const cookie) const
	{
		check(static_cast<IObservableMap<K, V> const &>(static_cast<D const &>(*this))->remove_MapChanged(cookie));
	}
};

template <typename D, typename T>
struct impl_IVectorChangedEventHandler
{
	void Invoke(IObservableVector<T> const & sender, IVectorChangedEventArgs const & args) const
	{
		check(static_cast<D const &>(*this)->abi_Invoke(get(sender), get(args)));
	}
};

template <typename D, typename T>
struct impl_IObservableVector
{
	EventRegistrationToken VectorChanged(IVectorChangedEventHandler<T> const & handler) const
	{
		EventRegistrationToken cookie = {};
		check(static_cast<IObservableVector<T> const &>(static_cast<D const &>(*this))->add_VectorChanged(get(handler), &cookie));
		return cookie;
	}

	template <typename Handler> EventRegistrationToken VectorChanged(Handler handler) const
	{
		return VectorChanged(VectorChangedEventHandler<T>(handler));
	}

	void VectorChanged(EventRegistrationToken const cookie) const
	{
		check(static_cast<IObservableVector<T> const &>(static_cast<D const &>(*this))->remove_VectorChanged(cookie));
	}
};

template <typename T>
struct IIterator :
	IInspectable,
	impl_IIterator<IIterator<T>, T>
{
	IIterator(std::nullptr_t = nullptr) noexcept {}
	auto operator->() const noexcept { return static_cast<AbiPtr<IIterator>>(m_ptr); }
};

template <typename T>
struct IIterable :
	IInspectable,
	impl_IIterable<IIterable<T>, T>
{
	IIterable(std::nullptr_t = nullptr) noexcept {}
	auto operator->() const noexcept { return static_cast<AbiPtr<IIterable>>(m_ptr); }
};

template <typename K, typename V>
struct IKeyValuePair :
	IInspectable,
	impl_IKeyValuePair<IKeyValuePair<K, V>, K, V>
{
	IKeyValuePair(std::nullptr_t = nullptr) noexcept {}
	auto operator->() const noexcept { return static_cast<AbiPtr<IKeyValuePair>>(m_ptr); }
};

template <typename T>
struct IVectorView :
	IInspectable,
	impl_IVectorView<IVectorView<T>, T>,
	Requires<IVectorView<T>, IIterable<T>>
{
	IVectorView(std::nullptr_t = nullptr) noexcept {}
	auto operator->() const noexcept { return static_cast<AbiPtr<IVectorView>>(m_ptr); }
};

template <typename T>
struct IVector :
	IInspectable,
	impl_IVector<IVector<T>, T>,
	Requires<IVector<T>, IIterable<T>>
{
	IVector(std::nullptr_t = nullptr) noexcept {}
	auto operator->() const noexcept { return static_cast<AbiPtr<IVector>>(m_ptr); }
};

template <typename K, typename V>
struct IMapView :
	IInspectable,
	impl_IMapView<IMapView<K, V>, K, V>,
	Requires<IMapView<K, V>, IIterable<IKeyValuePair<K, V>>>
{
	IMapView(std::nullptr_t = nullptr) noexcept {}
	auto operator->() const noexcept { return static_cast<AbiPtr<IMapView>>(m_ptr); }
};

template <typename K, typename V>
struct IMap :
	IInspectable,
	impl_IMap<IMap<K, V>, K, V>,
	Requires<IMap<K, V>, IIterable<IKeyValuePair<K, V>>>
{
	IMap(std::nullptr_t = nullptr) noexcept {}
	auto operator->() const noexcept { return static_cast<AbiPtr<IMap>>(m_ptr); }
};

template <typename K>
struct IMapChangedEventArgs :
	IInspectable,
	impl_IMapChangedEventArgs<IMapChangedEventArgs<K>, K>
{
	IMapChangedEventArgs(std::nullptr_t = nullptr) noexcept {}
	auto operator->() const noexcept { return static_cast<AbiPtr<IMapChangedEventArgs>>(m_ptr); }
};

template <typename K, typename V>
struct IMapChangedEventHandler :
	IUnknown,
	impl_IMapChangedEventHandler<IMapChangedEventHandler<K, V>, K, V>
{
	IMapChangedEventHandler(std::nullptr_t = nullptr) noexcept {}
	auto operator->() const noexcept { return static_cast<AbiPtr<IMapChangedEventHandler>>(m_ptr); }
};

template <typename K, typename V>
struct IObservableMap :
	IInspectable,
	impl_IObservableMap<IObservableMap<K, V>, K, V>,
	Requires<IObservableMap<K, V>, IMap<K, V>, IIterable<IKeyValuePair<K, V>>>
{
	IObservableMap(std::nullptr_t = nullptr) noexcept {}
	auto operator->() const noexcept { return static_cast<AbiPtr<IObservableMap>>(m_ptr); }
};

template <typename T>
struct IVectorChangedEventHandler :
	IUnknown,
	impl_IVectorChangedEventHandler<IVectorChangedEventHandler<T>, T>
{
	IVectorChangedEventHandler(std::nullptr_t = nullptr) noexcept {}
	auto operator->() const noexcept { return static_cast<AbiPtr<IVectorChangedEventHandler>>(m_ptr); }
};

template <typename T>
struct IObservableVector :
	IInspectable,
	impl_IObservableVector<IObservableVector<T>, T>,
	Requires<IObservableVector<T>, IVector<T>, IIterable<T>>
{
	IObservableVector(std::nullptr_t = nullptr) noexcept {}
	auto operator->() const noexcept { return static_cast<AbiPtr<IObservableVector>>(m_ptr); }
};

}}}}

namespace Modern {

template <typename T> struct Traits<Windows::Foundation::Collections::IIterator<T>>
{
	using Abi = ABI::Windows::Foundation::Collections::IIterator<Abi<T>>;
	template <typename D> using Methods = Windows::Foundation::Collections::impl_IIterator<D, T>;
};

template <typename T> struct Traits<Windows::Foundation::Collections::IIterable<T>>
{
	using Abi = ABI::Windows::Foundation::Collections::IIterable<Abi<T>>;
	template <typename D> using Methods = Windows::Foundation::Collections::impl_IIterable<D, T>;
};

template <typename K, typename V> struct Traits<Windows::Foundation::Collections::IKeyValuePair<K, V>>
{
	using Abi = ABI::Windows::Foundation::Collections::IKeyValuePair<Abi<K>, Abi<V>>;
	template <typename D> using Methods = Windows::Foundation::Collections::impl_IKeyValuePair<D, K, V>;
};

template <typename T> struct Traits<Windows::Foundation::Collections::IVectorView<T>>
{
	using Abi = ABI::Windows::Foundation::Collections::IVectorView<Abi<T>>;
	template <typename D> using Methods = Windows::Foundation::Collections::impl_IVectorView<D, T>;
};

template <typename T> struct Traits<Windows::Foundation::Collections::IVector<T>>
{
	using Abi = ABI::Windows::Foundation::Collections::IVector<Abi<T>>;
	template <typename D> using Methods = Windows::Foundation::Collections::impl_IVector<D, T>;
};

template <typename K, typename V> struct Traits<Windows::Foundation::Collections::IMapView<K, V>>
{
	using Abi = ABI::Windows::Foundation::Collections::IMapView<Abi<K>, Abi<V>>;
	template <typename D> using Methods = Windows::Foundation::Collections::impl_IMapView<D, K, V>;
};

template <typename K, typename V> struct Traits<Windows::Foundation::Collections::IMap<K, V>>
{
	using Abi = ABI::Windows::Foundation::Collections::IMap<Abi<K>, Abi<V>>;
	template <typename D> using Methods = Windows::Foundation::Collections::impl_IMap<D, K, V>;
};

template <typename K> struct Traits<Windows::Foundation::Collections::IMapChangedEventArgs<K>>
{
	using Abi = ABI::Windows::Foundation::Collections::IMapChangedEventArgs<Abi<K>>;
	template <typename D> using Methods = Windows::Foundation::Collections::impl_IMapChangedEventArgs<D, K>;
};

template <typename K, typename V> struct Traits<Windows::Foundation::Collections::IMapChangedEventHandler<K, V>>
{
	using Abi = ABI::Windows::Foundation::Collections::IMapChangedEventHandler<Abi<K>, Abi<V>>;
	template <typename D> using Methods = Windows::Foundation::Collections::impl_IMapChangedEventHandler<D, K, V>;
};

template <typename K, typename V> struct Traits<Windows::Foundation::Collections::IObservableMap<K, V>>
{
	using Abi = ABI::Windows::Foundation::Collections::IObservableMap<Abi<K>, Abi<V>>;
	template <typename D> using Methods = Windows::Foundation::Collections::impl_IObservableMap<D, K, V>;
};

template <typename T> struct Traits<Windows::Foundation::Collections::IVectorChangedEventHandler<T>>
{
	using Abi = ABI::Windows::Foundation::Collections::IVectorChangedEventHandler<Abi<T>>;
	template <typename D> using Methods = Windows::Foundation::Collections::impl_IVectorChangedEventHandler<D, T>;
};

template <typename T> struct Traits<Windows::Foundation::Collections::IObservableVector<T>>
{
	using Abi = ABI::Windows::Foundation::Collections::IObservableVector<Abi<T>>;
	template <typename D> using Methods = Windows::Foundation::Collections::impl_IObservableVector<D, T>;
};

}

namespace Modern { namespace Windows { namespace Foundation { namespace Collections {

template <typename T, IsNotRandomAccess<T> = nullptr>
auto begin(T const & collection) -> decltype(collection.First())
{
	auto result = collection.First();

	if (!result.HasCurrent())
	{
		return {};
	}

	return result;
}

template <typename T, IsNotRandomAccess<T> = nullptr>
auto end(T const & collection) -> decltype(collection.First())
{
	collection;
	return {};
}

template <typename T, IsRandomAccess<T> = nullptr>
FastIterator<T> begin(T const & collection) noexcept
{
	return FastIterator<T>(collection, 0);
}

template <typename T, IsRandomAccess<T> = nullptr>
FastIterator<T> end(T const & collection)
{
	return FastIterator<T>(collection, collection.Size());
}

}}}}
