
#define MODERN_GENERIC_INTERFACE(THIS_CLASS)\
public:\
THIS_CLASS() noexcept = default;\
THIS_CLASS(std::nullptr_t) {}\
Modern::Internal::RemoveAddRefRelease<AbiType> * operator->() const noexcept { return static_cast<Modern::Internal::RemoveAddRefRelease<AbiType> *>(GetAbi()); }\
AbiType * GetAbi() const noexcept { return static_cast<AbiType *>(IUnknown::GetAbi()); }\
AbiType ** SetAbi() noexcept { return reinterpret_cast<AbiType **>(IUnknown::SetAbi()); }\
void AttachAbi(AbiType * other) noexcept { IUnknown::AttachAbi(other); };\
void CopyAbi(AbiType * other) noexcept { IUnknown::CopyAbi(other); };\
AbiType * DetachAbi() noexcept { return static_cast<AbiType *>(IUnknown::DetachAbi()); }

namespace Modern { namespace Internal {

template <typename T>
class CanGetAbi
{
	template <typename U> static std::true_type  Check(decltype(&U::GetAbi));
	template <typename>   static std::false_type Check(...);

public:

	static constexpr bool Value = decltype(Check<T>(0))::value;
};

template <typename T>
class CanSetAbi
{
	template <typename U> static std::true_type  Check(decltype(&U::SetAbi));
	template <typename>   static std::false_type Check(...);

public:

	static constexpr bool Value = decltype(Check<T>(0))::value;
};

template <typename T>
class HasAbiType
{
	template <typename U> static std::true_type Check(decltype(std::is_void<Implementation<U>::AbiType>::value));
	template <typename>   static std::false_type Check(...);

public:

	static constexpr bool Value = decltype(Check<T>(0))::value;
};

template <typename T>
class IsClass
{
    template <typename U> static std::true_type Check(decltype(std::is_void<Implementation<U>::Default>::value));
    template <typename>   static std::false_type Check(...);

public:

    static constexpr bool Value = decltype(Check<T>(0))::value;
};

template <typename T>
class IsRandom
{
    template <typename U, typename = decltype(std::declval<U>().GetAt(0))>
    static std::true_type Check(int);

    template <typename>
    static std::false_type Check(...);

public:

    static constexpr bool Value = decltype(Check<T>(0))::value;
};

template <typename T, typename Enable = void>
struct Abi
{
    using Type = T;
};

template <typename T>
struct Abi<T, typename std::enable_if<HasAbiType<T>::Value>::type>
{
	using Type = typename Implementation<T>::AbiType;
};

template <typename T, typename Enable = void>
struct Argument
{
    using Type = T;
    using In = Type const &;
    using Out = Type &;

    static Type Default() noexcept
    {
        return {};
    }
};

template <typename T>
struct Argument<T, typename std::enable_if<IsClass<T>::Value>::type>
{
    using Type = T;
    using In = Type const &;
    using Out = Type &;

    static Type Default() noexcept
    {
        return { nullptr };
    }
};

template <typename T>
using AbiArgument = ABI::Internal::Argument<typename Abi<T>::Type>;

template <typename T>
struct Lease : T
{
	template <typename U>
    Lease(U abi) noexcept
	{
		AttachAbi(abi);
	}

	~Lease() noexcept
	{
		DetachAbi();
	}
};

template <typename T>
struct LeaseClass : T
{
    template <typename U>
    LeaseClass(U abi) noexcept :
    T(nullptr)
    {
        AttachAbi(abi);
    }

    ~LeaseClass() noexcept
    {
        DetachAbi();
    }
};

struct LeaseString : String
{
	LeaseString(HSTRING abi) noexcept
	{
		Attach(*this, abi);
	}

	~LeaseString() noexcept
	{
		Detach(*this);
	}
};

template <typename T, typename A, typename std::enable_if<IsClass<T>::Value>::type * = nullptr>
auto Forward(A * value) noexcept
{
    return LeaseClass<T>(value);
}

template <typename T, typename A, typename std::enable_if<!IsClass<T>::Value && CanSetAbi<T>::Value>::type * = nullptr>
auto Forward(A * value) noexcept
{
    return Lease<T>(value);
}

template <typename T, typename A, typename std::enable_if<!CanSetAbi<T>::Value>::type * = nullptr>
auto Forward(A value) noexcept
{
    return value;
}

template <typename>
LeaseString Forward(HSTRING value) noexcept
{
	return LeaseString(value);
}

class SetBool
{
    boolean m_abi = 0;
    bool & m_value;

public:

    SetBool & operator=(SetBool const &) = delete;

    SetBool(bool & value) noexcept :
        m_value(value)
    {}

    ~SetBool() noexcept
    {
        m_value = 0 != m_abi;
    }

    operator boolean * () noexcept
    {
        return &m_abi;
    }
};

template <typename To, typename From>
void CopyToAbi(To & to, From const & from)
{
	to = from;
}

inline void CopyToAbi(HSTRING & to, String const & from)
{
	String copy = from;
	to = Detach(copy);
}

template <typename To, typename From>
void CopyFromAbi(To & to, From const & from)
{
	to = from;
}

inline void CopyFromAbi(String & to, HSTRING from)
{
	Copy(to, from);
}

}}

namespace Modern {

template <typename T, typename std::enable_if<!Internal::CanSetAbi<T>::Value>::type * = nullptr>
auto Abi(T * value) noexcept
{
    return value;
}

template <typename T, typename std::enable_if<Internal::CanSetAbi<T>::Value>::type * = nullptr>
auto Abi(T * value) noexcept
{
	return value->SetAbi();
}

inline Internal::SetBool Abi(bool * value) noexcept
{
	return Internal::SetBool(*value);
}

inline HSTRING * Abi(String * value) noexcept
{
	return Set(*value);
}

template <typename T, typename std::enable_if<!Internal::CanGetAbi<T>::Value>::type * = nullptr>
auto Abi(T const & value) noexcept
{
    return value;
}

template <typename T, typename std::enable_if<Internal::CanGetAbi<T>::Value>::type * = nullptr>
auto Abi(T const & value) noexcept
{
	return value.GetAbi();
}

inline HSTRING Abi(String const & value) noexcept
{
	return Get(value);
}

inline HSTRING Abi(StringReference const & value) noexcept
{
	return value.Get();
}

template <typename T, typename B>
struct Base
{
    operator B() const noexcept
    {
        return static_cast<T const *>(this)->As<B>();
    }
};

template <typename T, typename ... B>
struct Bases : Base<T, B> ...
{
};

template <typename T, typename R>
struct RequiresOne : Internal::Implementation<R>::template Methods<RequiresOne<T, R>>
{
    operator R() const noexcept
    {
        return static_cast<T const *>(this)->As<R>();
    }
};

template <typename T, typename ... R>
struct Requires : RequiresOne<T, R> ...
{
};

template <typename ... R>
struct Overrides : Implements<R ...>
{
    template <typename I>
    I As() const
    {
        return m_inner.As<I>();
    }

    virtual HRESULT __stdcall QueryInterface(GUID const & id, void ** object) noexcept override
    {
        *object = BaseQueryInterface<R ...>(id);

        if (nullptr == *object)
        {
            return m_inner->QueryInterface(id, object);
        }

        static_cast<::IUnknown *>(*object)->AddRef();
        return S_OK;
    }

protected:

    Modern::IInspectable m_inner;
};

}

namespace Modern { namespace Windows { namespace Foundation {

template <typename TProgress>
class IAsyncActionProgressHandler;

template <typename TProgress>
class IAsyncActionWithProgress;

template <typename TProgress>
class IAsyncActionWithProgressCompletedHandler;

template <typename TResult, typename TProgress>
class IAsyncOperationProgressHandler;

template <typename TResult, typename TProgress>
class IAsyncOperationWithProgressCompletedHandler;

template <typename TResult>
class IAsyncOperationCompletedHandler;

template <typename T>
class IEventHandler;

template <typename TSender, typename TArgs>
class ITypedEventHandler;

template <typename TResult>
class IAsyncOperation;

template <typename TResult, typename TProgress>
class IAsyncOperationWithProgress;

template <typename T>
class IReference;

}}}

namespace Modern { namespace Windows { namespace Foundation { namespace Collections {

template <typename T>
class IIterator;

template <typename T>
class IIterable;

template <typename K, typename V>
class IKeyValuePair;

template <typename T>
class IVectorView;

template <typename T>
class IVector;

template <typename K, typename V>
class IMapView;

template <typename K, typename V>
class IMap;

template <typename K>
class IMapChangedEventArgs;

template <typename K, typename V>
class IMapChangedEventHandler;

template <typename K, typename V>
class IObservableMap;

template <typename T>
class IVectorChangedEventHandler;

template <typename T>
class IObservableVector;

class IVectorChangedEventArgs;

}}}}

namespace Modern { namespace Windows { namespace Foundation {

template <typename D, typename TProgress>
struct impl_IAsyncActionProgressHandler
{
	void Invoke(IAsyncActionWithProgress<TProgress> const & sender, typename Internal::Argument<TProgress>::In args) const
	{
		Check((*static_cast<D const *>(this))->abi_Invoke(Abi(sender), Abi(args)));
	}
};

template <typename D, typename TProgress>
struct impl_IAsyncActionWithProgress
{
    void Progress(IAsyncActionProgressHandler<TProgress> const & handler) const
    {
        Check((*static_cast<D const *>(this))->put_Progress(Abi(handler)));
    }

    template <typename Handler>
    void Progress(Handler handler) const
    {
        return Progress(AsyncActionProgressHandler<TProgress>(handler));
    }

    IAsyncActionProgressHandler<TProgress> Progress() const
    {
        IAsyncActionProgressHandler<TProgress> handler;
        Check((*static_cast<D const *>(this))->get_Progress(Abi(&handler)));
        return handler;
    }

    void Completed(IAsyncActionWithProgressCompletedHandler<TProgress> const & handler) const
    {
        Check((*static_cast<D const *>(this))->put_Completed(Abi(handler)));
    }

    template <typename Handler>
    void Completed(Handler handler) const
    {
        return Completed(AsyncActionWithProgressCompletedHandler<TProgress>(handler));
    }

    IAsyncActionWithProgressCompletedHandler<TProgress> Completed() const
    {
        IAsyncActionWithProgressCompletedHandler<TProgress> handler;
        Check((*static_cast<D const *>(this))->get_Completed(Abi(&handler)));
        return handler;
    }

    void GetResults() const
    {
        Check((*static_cast<D const *>(this))->abi_GetResults());
    }
};

template <typename D, typename TProgress>
struct impl_IAsyncActionWithProgressCompletedHandler
{
    void Invoke(IAsyncActionWithProgress<TProgress> const & sender, AsyncStatus const args) const
    {
        Check((*static_cast<D const *>(this))->abi_Invoke(Abi(sender), args));
    }
};

template <typename D, typename TResult, typename TProgress>
struct impl_IAsyncOperationProgressHandler
{
    void Invoke(IAsyncOperationWithProgress<TResult, TProgress> const & sender, typename Internal::Argument<TProgress>::In args) const
    {
        Check((*static_cast<D const *>(this))->abi_Invoke(Abi(sender), Abi(args)));
    }
};

template <typename D, typename TResult, typename TProgress>
struct impl_IAsyncOperationWithProgressCompletedHandler
{
    void Invoke(IAsyncOperationWithProgress<TResult, TProgress> const & sender, AsyncStatus const args) const
    {
        Check((*static_cast<D const *>(this))->abi_Invoke(Abi(sender), args));
    }
};

template <typename D, typename TResult>
struct impl_IAsyncOperationCompletedHandler
{
    void Invoke(IAsyncOperation<TResult> const & sender, AsyncStatus const args) const
    {
        Check((*static_cast<D const *>(this))->abi_Invoke(Abi(sender), args));
    }
};

template <typename D, typename T>
struct impl_IEventHandler
{
    void Invoke(IInspectable const & sender, typename Internal::Argument<T>::In args) const
    {
        Check((*static_cast<D const *>(this))->abi_Invoke(Abi(sender), Abi(args)));
    }
};

template <typename D, typename TSender, typename TArgs>
struct impl_ITypedEventHandler
{
    void Invoke(typename Internal::Argument<TSender>::In sender, typename Internal::Argument<TArgs>::In args) const
    {
        Check((*static_cast<D const *>(this))->abi_Invoke(Abi(sender), Abi(args)));
    }
};

template <typename D, typename TResult>
struct impl_IAsyncOperation
{
    void Completed(IAsyncOperationCompletedHandler<TResult> const & handler) const
    {
        Check((*static_cast<D const *>(this))->put_Completed(Abi(handler)));
    }

    template <typename Handler>
    void Completed(Handler handler) const
    {
        return Completed(AsyncOperationCompletedHandler<TResult>(handler));
    }

    IAsyncOperationCompletedHandler<TResult> Completed() const
    {
        IAsyncOperationCompletedHandler<TResult> temp;
        Check((*static_cast<D const *>(this))->get_Completed(Abi(&temp)));
        return temp;
    }

    auto GetResults() const
    {
        auto result = Internal::Argument<TResult>::Default();
        Check((*static_cast<D const *>(this))->abi_GetResults(Abi(&result)));
        return result;
    }
};

template <typename D, typename TResult, typename TProgress>
struct impl_IAsyncOperationWithProgress
{
    void Progress(IAsyncOperationProgressHandler<TResult, TProgress> const & handler) const
    {
        Check((*static_cast<D const *>(this))->put_Progress(Abi(handler)));
    }

    template <typename Handler>
    void Progress(Handler handler) const
    {
        return Progress(AsyncOperationProgressHandler<TResult, TProgress>(handler));
    }

    IAsyncOperationProgressHandler<TResult, TProgress> Progress() const
    {
        IAsyncOperationProgressHandler<TResult, TProgress> handler;
        Check((*static_cast<D const *>(this))->get_Progress(Abi(&handler)));
        return handler;
    }

    void Completed(IAsyncOperationWithProgressCompletedHandler<TResult, TProgress> const & handler) const
    {
        Check((*static_cast<D const *>(this))->put_Completed(Abi(handler)));
    }

    template <typename Handler>
    void Completed(Handler handler) const
    {
        return Completed(AsyncOperationWithProgressCompletedHandler<TResult, TProgress>(handler));
    }

    IAsyncOperationWithProgressCompletedHandler<TResult, TProgress> Completed() const
    {
        IAsyncOperationWithProgressCompletedHandler<TResult, TProgress> handler;
        Check((*static_cast<D const *>(this))->get_Completed(Abi(&handler)));
        return handler;
    }

    auto GetResults() const
    {
        auto result = Internal::Argument<TResult>::Default();
        Check((*static_cast<D const *>(this))->abi_GetResults(Abi(&result)));
        return result;
    }
};

template <typename D, typename T>
struct impl_IReference
{
    auto Value() const
    {
        auto result = Internal::Argument<T>::Default();
        Check((*static_cast<D const *>(this))->get_Value(Abi(&result)));
        return result;
    }
};

}}}

namespace Modern { namespace Windows { namespace Foundation { namespace Collections {

template <typename D, typename T>
struct impl_IIterator
{
	auto Current() const
	{
        auto result = Internal::Argument<T>::Default();
		Check((*static_cast<D const *>(this))->get_Current(Abi(&result)));
		return result;
	}

	bool HasCurrent() const
	{
		boolean temp = 0;
		Check((*static_cast<D const *>(this))->get_HasCurrent(&temp));
		return 0 != temp;
	}

	bool MoveNext() const
	{
		boolean temp = 0;
		Check((*static_cast<D const *>(this))->abi_MoveNext(&temp));
		return 0 != temp;
	}

	impl_IIterator & operator++()
	{
		if (!MoveNext())
		{
			(*static_cast<D *>(this)).Reset();
		}

		return *this;
	}

	auto operator *() const
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
        Check(static_cast<IIterable<T> const &>(*static_cast<D const *>(this))->abi_First(Abi(&iterator)));
        return iterator;
    }
};

template <typename D, typename K, typename V>
struct impl_IKeyValuePair
{
    auto Key() const
    {
        auto result = Internal::Argument<K>::Default();
        Check((*static_cast<D const *>(this))->get_Key(Abi(&result)));
        return result;
    }

    auto Value() const
    {
        auto result = Internal::Argument<V>::Default();
        Check((*static_cast<D const *>(this))->get_Value(Abi(&result)));
        return result;
    }
};

template <typename D, typename T>
struct impl_IVectorView
{
    auto GetAt(unsigned const index) const
    {
        auto result = Internal::Argument<T>::Default();
        Check((*static_cast<D const *>(this))->abi_GetAt(index, Abi(&result)));
        return result;
    }

    unsigned Size() const
    {
        unsigned size = 0;
        Check((*static_cast<D const *>(this))->get_Size(&size));
        return size;
    }

    bool IndexOf(typename Internal::Argument<T>::In value, unsigned & index) const
    {
        boolean found = false;
        Check((*static_cast<D const *>(this))->abi_IndexOf(Abi(value), &index, &found));
        return 0 != found;
    }
};

template <typename D, typename T>
struct impl_IVector
{
    auto GetAt(unsigned const index) const
    {
        auto result = Internal::Argument<T>::Default();
        Check((*static_cast<D const *>(this))->abi_GetAt(index, Abi(&result)));
        return result;
    }

    unsigned Size() const
    {
        unsigned size = 0;
        Check((*static_cast<D const *>(this))->get_Size(&size));
        return size;
    }

    IVectorView<T> GetView() const
    {
        IVectorView<T> view;
        Check((*static_cast<D const *>(this))->abi_GetView(Abi(&view)));
        return view;
    }

    bool IndexOf(typename Internal::Argument<T>::In value, unsigned & index) const
    {
        boolean found = false;
        Check((*static_cast<D const *>(this))->abi_IndexOf(Abi(value), &index, &found));
        return 0 != found;
    }

    void SetAt(unsigned const index, typename Internal::Argument<T>::In value) const
    {
        Check((*static_cast<D const *>(this))->abi_SetAt(index, Abi(value)));
    }

    void InsertAt(unsigned const index, typename Internal::Argument<T>::In value) const
    {
        Check((*static_cast<D const *>(this))->abi_InsertAt(index, Abi(value)));
    }

    void RemoveAt(unsigned const index) const
    {
        Check((*static_cast<D const *>(this))->abi_RemoveAt(index));
    }

    void Append(typename Internal::Argument<T>::In value) const
    {
        Check((*static_cast<D const *>(this))->abi_Append(Abi(value)));
    }

    void RemoveAtEnd() const
    {
        Check((*static_cast<D const *>(this))->abi_RemoveAtEnd());
    }

    void Clear() const
    {
        Check((*static_cast<D const *>(this))->abi_Clear());
    }
};

template <typename D, typename K, typename V>
struct impl_IMapView
{
    auto Lookup(typename Internal::Argument<K>::In key) const
    {
        auto result = Internal::Argument<V>::Default();
        Check((*static_cast<D const *>(this))->abi_Lookup(Abi(key), Abi(&result)));
        return result;
    }

    unsigned Size() const
    {
        unsigned size = 0;
        Check((*static_cast<D const *>(this))->get_Size(&size));
        return size;
    }

    bool HasKey(typename Internal::Argument<K>::In key) const
    {
        boolean found = false;
        Check((*static_cast<D const *>(this))->abi_HasKey(Abi(key), &found));
        return 0 != found;
    }

    void Split(typename Internal::Argument<IMapView<K, V>>::Out firstPartition, typename Internal::Argument<IMapView<K, V>>::Out secondPartition)
    {
        Check((*static_cast<D const *>(this))->abi_Split(Abi(&firstPartition), Abi(&secondPartition)));
    }
};

template <typename D, typename K, typename V>
struct impl_IMap
{
    auto Lookup(typename Internal::Argument<K>::In key) const
    {
        auto result = Internal::Argument<V>::Default();
        Check((*static_cast<D const *>(this))->abi_Lookup(Abi(key), Abi(&result)));
        return result;
    }

    unsigned Size() const
    {
        unsigned size = 0;
        Check((*static_cast<D const *>(this))->get_Size(&size));
        return size;
    }

    bool HasKey(typename Internal::Argument<K>::In key) const
    {
        boolean found = false;
        Check((*static_cast<D const *>(this))->abi_HasKey(Abi(key), &found));
        return 0 != found;
    }

    IMapView<K, V> GetView() const
    {
        IMapView<K, V> view;
        Check((*static_cast<D const *>(this))->abi_GetView(Abi(&view)));
        return view;
    }

    bool Insert(typename Internal::Argument<K>::In key, typename Internal::Argument<V>::In value) const
    {
        boolean replaced = false;
        Check((*static_cast<D const *>(this))->abi_Insert(Abi(key), Abi(value), &replaced));
        return 0 != replaced;
    }

    void Remove(typename Internal::Argument<K>::In key) const
    {
        Check((*static_cast<D const *>(this))->abi_Remove(Abi(key)));
    }

    void Clear() const
    {
        Check((*static_cast<D const *>(this))->abi_Clear());
    }
};

template <typename D, typename K>
struct impl_IMapChangedEventArgs
{
    CollectionChange CollectionChange() const
    {
        CollectionChange value;
        Check((*static_cast<D const *>(this))->get_CollectionChange(Abi(&value)));
        return value;
    }

    auto Key() const
    {
        auto result = Internal::Argument<K>::Default();
        Check((*static_cast<D const *>(this))->get_Key(Abi(&result)));
        return result;
    }
};

template <typename D, typename K, typename V>
struct impl_IMapChangedEventHandler
{
    void Invoke(IObservableMap<K, V> const & sender, IMapChangedEventArgs<K> const & args) const
    {
        Check((*static_cast<D const *>(this))->abi_Invoke(Abi(sender), Abi(args)));
    }
};

template <typename D, typename K, typename V>
struct impl_IObservableMap
{
    EventRegistrationToken MapChanged(IMapChangedEventHandler<K, V> const & handler) const
    {
        EventRegistrationToken cookie = {};
        Check((*static_cast<D const *>(this))->add_MapChanged(Abi(handler), Abi(&cookie)));
        return cookie;
    }

    template <typename T> EventRegistrationToken MapChanged(T handler) const
    {
        return MapChanged(MapChangedEventHandler<K, V>(handler));
    }

    void MapChanged(EventRegistrationToken const cookie) const
    {
        Check((*static_cast<D const *>(this))->remove_MapChanged(Abi(cookie)));
    }
};

template <typename D>
struct impl_IVectorChangedEventArgs
{
    CollectionChange CollectionChange() const
    {
        Collections::CollectionChange value;
        Check((*static_cast<D const *>(this))->get_CollectionChange(Abi(&value)));
        return value;
    }

    unsigned Index() const
    {
        unsigned index;
        Check((*static_cast<D const *>(this))->get_Index(&index));
        return index;
    }
};

template <typename D, typename T>
struct impl_IVectorChangedEventHandler
{
    void Invoke(IObservableVector<T> const & sender, IVectorChangedEventArgs const & args) const
    {
        Check((*static_cast<D const *>(this))->abi_Invoke(Abi(sender), Abi(args)));
    }
};

template <typename D, typename T>
struct impl_IObservableVector
{
    EventRegistrationToken VectorChanged(IVectorChangedEventHandler<T> const & handler) const
    {
        EventRegistrationToken cookie = {};
        Check((*static_cast<D const *>(this))->add_VectorChanged(Abi(handler), Abi(&cookie)));
        return cookie;
    }

    template <typename Handler> EventRegistrationToken VectorChanged(Handler handler) const
    {
        return VectorChanged(VectorChangedEventHandler<T>(handler));
    }

    void VectorChanged(EventRegistrationToken const cookie) const
    {
        Check((*static_cast<D const *>(this))->remove_VectorChanged(Abi(cookie)));
    }
};

}}}}

namespace Modern { namespace Internal {

template <typename TProgress> struct Implementation<Windows::Foundation::IAsyncActionProgressHandler<TProgress>>
{
    using AbiType = ABI::Windows::Foundation::IAsyncActionProgressHandler<typename Internal::Abi<TProgress>::Type>;
	template <typename D> using Methods = Windows::Foundation::impl_IAsyncActionProgressHandler<D, TProgress>;
};

template <typename TProgress> struct Implementation<Windows::Foundation::IAsyncActionWithProgress<TProgress>>
{
    using AbiType = ABI::Windows::Foundation::IAsyncActionWithProgress<typename Internal::Abi<TProgress>::Type>;
	template <typename D> using Methods = Windows::Foundation::impl_IAsyncActionWithProgress<D, TProgress>;
};

template <typename TProgress> struct Implementation<Windows::Foundation::IAsyncActionWithProgressCompletedHandler<TProgress>>
{
    using AbiType = ABI::Windows::Foundation::IAsyncActionWithProgressCompletedHandler<typename Internal::Abi<TProgress>::Type>;
	template <typename D> using Methods = Windows::Foundation::impl_IAsyncActionWithProgressCompletedHandler<D, TProgress>;
};

template <typename TResult, typename TProgress> struct Implementation<Windows::Foundation::IAsyncOperationProgressHandler<TResult, TProgress>>
{
    using AbiType = ABI::Windows::Foundation::IAsyncOperationProgressHandler<typename Internal::Abi<TResult>::Type, typename Internal::Abi<TProgress>::Type>;
	template <typename D> using Methods = Windows::Foundation::impl_IAsyncOperationProgressHandler<D, TResult, TProgress>;
};

template <typename TResult, typename TProgress> struct Implementation<Windows::Foundation::IAsyncOperationWithProgressCompletedHandler<TResult, TProgress>>
{
    using AbiType = ABI::Windows::Foundation::IAsyncOperationWithProgressCompletedHandler<typename Internal::Abi<TResult>::Type, typename Internal::Abi<TProgress>::Type>;
	template <typename D> using Methods = Windows::Foundation::impl_IAsyncOperationWithProgressCompletedHandler<D, TResult, TProgress>;
};

template <typename TResult> struct Implementation<Windows::Foundation::IAsyncOperationCompletedHandler<TResult>>
{
    using AbiType = ABI::Windows::Foundation::IAsyncOperationCompletedHandler<typename Internal::Abi<TResult>::Type>;
	template <typename D> using Methods = Windows::Foundation::impl_IAsyncOperationCompletedHandler<D, TResult>;
};

template <typename T> struct Implementation<Windows::Foundation::IEventHandler<T>>
{
    using AbiType = ABI::Windows::Foundation::IEventHandler<typename Internal::Abi<T>::Type>;
	template <typename D> using Methods = Windows::Foundation::impl_IEventHandler<D, T>;
};

template <typename TSender, typename TArgs> struct Implementation<Windows::Foundation::ITypedEventHandler<TSender, TArgs>>
{
    using AbiType = ABI::Windows::Foundation::ITypedEventHandler<typename Internal::Abi<TSender>::Type, typename Internal::Abi<TArgs>::Type>;
	template <typename D> using Methods = Windows::Foundation::impl_ITypedEventHandler<D, TSender, TArgs>;
};

template <typename TResult> struct Implementation<Windows::Foundation::IAsyncOperation<TResult>>
{
    using AbiType = ABI::Windows::Foundation::IAsyncOperation<typename Internal::Abi<TResult>::Type>;
	template <typename D> using Methods = Windows::Foundation::impl_IAsyncOperation<D, TResult>;
};

template <typename TResult, typename TProgress> struct Implementation<Windows::Foundation::IAsyncOperationWithProgress<TResult, TProgress>>
{
    using AbiType = ABI::Windows::Foundation::IAsyncOperationWithProgress<typename Internal::Abi<TResult>::Type, typename Internal::Abi<TProgress>::Type>;
	template <typename D> using Methods = Windows::Foundation::impl_IAsyncOperationWithProgress<D, TResult, TProgress>;
};

template <typename T> struct Implementation<Windows::Foundation::IReference<T>>
{
    using AbiType = ABI::Windows::Foundation::IReference<typename Internal::Abi<T>::Type>;
	template <typename D> using Methods = Windows::Foundation::impl_IReference<D, T>;
};

template <typename T> struct Implementation<Windows::Foundation::Collections::IIterator<T>>
{
    using AbiType = ABI::Windows::Foundation::Collections::IIterator<typename Internal::Abi<T>::Type>;
	template <typename D> using Methods = Windows::Foundation::Collections::impl_IIterator<D, T>;
};

template <typename T> struct Implementation<Windows::Foundation::Collections::IIterable<T>>
{
    using AbiType = ABI::Windows::Foundation::Collections::IIterable<typename Internal::Abi<T>::Type>;
	template <typename D> using Methods = Windows::Foundation::Collections::impl_IIterable<D, T>;
};

template <typename K, typename V> struct Implementation<Windows::Foundation::Collections::IKeyValuePair<K, V>>
{
    using AbiType = ABI::Windows::Foundation::Collections::IKeyValuePair<typename Internal::Abi<K>::Type, typename Internal::Abi<V>::Type>;
	template <typename D> using Methods = Windows::Foundation::Collections::impl_IKeyValuePair<D, K, V>;
};

template <typename T> struct Implementation<Windows::Foundation::Collections::IVectorView<T>>
{
    using AbiType = ABI::Windows::Foundation::Collections::IVectorView<typename Internal::Abi<T>::Type>;
	template <typename D> using Methods = Windows::Foundation::Collections::impl_IVectorView<D, T>;
};

template <typename T> struct Implementation<Windows::Foundation::Collections::IVector<T>>
{
    using AbiType = ABI::Windows::Foundation::Collections::IVector<typename Internal::Abi<T>::Type>;
	template <typename D> using Methods = Windows::Foundation::Collections::impl_IVector<D, T>;
};

template <typename K, typename V> struct Implementation<Windows::Foundation::Collections::IMapView<K, V>>
{
    using AbiType = ABI::Windows::Foundation::Collections::IMapView<typename Internal::Abi<K>::Type, typename Internal::Abi<V>::Type>;
	template <typename D> using Methods = Windows::Foundation::Collections::impl_IMapView<D, K, V>;
};

template <typename K, typename V> struct Implementation<Windows::Foundation::Collections::IMap<K, V>>
{
    using AbiType = ABI::Windows::Foundation::Collections::IMap<typename Internal::Abi<K>::Type, typename Internal::Abi<V>::Type>;
	template <typename D> using Methods = Windows::Foundation::Collections::impl_IMap<D, K, V>;
};

template <typename K> struct Implementation<Windows::Foundation::Collections::IMapChangedEventArgs<K>>
{
    using AbiType = ABI::Windows::Foundation::Collections::IMapChangedEventArgs<typename Internal::Abi<K>::Type>;
	template <typename D> using Methods = Windows::Foundation::Collections::impl_IMapChangedEventArgs<D, K>;
};

template <typename K, typename V> struct Implementation<Windows::Foundation::Collections::IMapChangedEventHandler<K, V>>
{
    using AbiType = ABI::Windows::Foundation::Collections::IMapChangedEventHandler<typename Internal::Abi<K>::Type, typename Internal::Abi<V>::Type>;
	template <typename D> using Methods = Windows::Foundation::Collections::impl_IMapChangedEventHandler<D, K, V>;
};

template <typename K, typename V> struct Implementation<Windows::Foundation::Collections::IObservableMap<K, V>>
{
    using AbiType = ABI::Windows::Foundation::Collections::IObservableMap<typename Internal::Abi<K>::Type, typename Internal::Abi<V>::Type>;
	template <typename D> using Methods = Windows::Foundation::Collections::impl_IObservableMap<D, K, V>;
};

template <> struct Implementation<Windows::Foundation::Collections::IVectorChangedEventArgs>
{
    using AbiType = ABI::Windows::Foundation::Collections::IVectorChangedEventArgs;
	template <typename D> using Methods = Windows::Foundation::Collections::impl_IVectorChangedEventArgs<D>;
};

template <typename T> struct Implementation<Windows::Foundation::Collections::IVectorChangedEventHandler<T>>
{
    using AbiType = ABI::Windows::Foundation::Collections::IVectorChangedEventHandler<typename Internal::Abi<T>::Type>;
	template <typename D> using Methods = Windows::Foundation::Collections::impl_IVectorChangedEventHandler<D, T>;
};

template <typename T> struct Implementation<Windows::Foundation::Collections::IObservableVector<T>>
{
    using AbiType = ABI::Windows::Foundation::Collections::IObservableVector<typename Internal::Abi<T>::Type>;
	template <typename D> using Methods = Windows::Foundation::Collections::impl_IObservableVector<D, T>;
};

}}

namespace Modern { namespace Windows { namespace Foundation {

template <typename TProgress>
class IAsyncActionProgressHandler :
	public IUnknown,
	public impl_IAsyncActionProgressHandler<IAsyncActionProgressHandler<TProgress>, TProgress>
{
    using AbiType = typename Internal::Implementation<IAsyncActionProgressHandler<TProgress>>::AbiType;
	MODERN_GENERIC_INTERFACE(IAsyncActionProgressHandler)
};

template <typename TProgress>
class IAsyncActionWithProgress :
	public IInspectable,
	public impl_IAsyncActionWithProgress<IAsyncActionWithProgress<TProgress>, TProgress>,
	public Requires<IAsyncActionWithProgress<TProgress>, IAsyncInfo>
{
    using AbiType = typename Internal::Implementation<IAsyncActionWithProgress<TProgress>>::AbiType;
    MODERN_GENERIC_INTERFACE(IAsyncActionWithProgress)
};

template <typename TProgress>
class IAsyncActionWithProgressCompletedHandler :
	public IUnknown,
	public impl_IAsyncActionWithProgressCompletedHandler<IAsyncActionWithProgressCompletedHandler<TProgress>, TProgress>
{
    using AbiType = typename Internal::Implementation<IAsyncActionWithProgressCompletedHandler<TProgress>>::AbiType;
    MODERN_GENERIC_INTERFACE(IAsyncActionWithProgressCompletedHandler)
};

template <typename TResult, typename TProgress>
class IAsyncOperationProgressHandler :
	public IUnknown,
	public impl_IAsyncOperationProgressHandler<IAsyncOperationProgressHandler<TResult, TProgress>, TResult, TProgress>
{
    using AbiType = typename Internal::Implementation<IAsyncOperationProgressHandler<TResult, TProgress>>::AbiType;
    MODERN_GENERIC_INTERFACE(IAsyncOperationProgressHandler)
};

template <typename TResult, typename TProgress>
class IAsyncOperationWithProgressCompletedHandler :
	public IUnknown,
	public impl_IAsyncOperationWithProgressCompletedHandler<IAsyncOperationWithProgressCompletedHandler<TResult, TProgress>, TResult, TProgress>
{
    using AbiType = typename Internal::Implementation<IAsyncOperationWithProgressCompletedHandler<TResult, TProgress>>::AbiType;
    MODERN_GENERIC_INTERFACE(IAsyncOperationWithProgressCompletedHandler)
};

template <typename TResult>
class IAsyncOperationCompletedHandler :
	public IUnknown,
	public impl_IAsyncOperationCompletedHandler<IAsyncOperationCompletedHandler<TResult>, TResult>
{
    using AbiType = typename Internal::Implementation<IAsyncOperationCompletedHandler<TResult>>::AbiType;
    MODERN_GENERIC_INTERFACE(IAsyncOperationCompletedHandler)
};

template <typename T>
class IEventHandler :
	public IUnknown,
	public impl_IEventHandler<IEventHandler<T>, T>
{
    using AbiType = typename Internal::Implementation<IEventHandler<T>>::AbiType;
    MODERN_GENERIC_INTERFACE(IEventHandler)
};

template <typename TSender, typename TArgs>
class ITypedEventHandler :
	public IUnknown,
	public impl_ITypedEventHandler<ITypedEventHandler<TSender, TArgs>, TSender, TArgs>
{
    using AbiType = typename Internal::Implementation<ITypedEventHandler<TSender, TArgs>>::AbiType;
    MODERN_GENERIC_INTERFACE(ITypedEventHandler)
};

template <typename TResult>
class IAsyncOperation :
	public IInspectable,
	public impl_IAsyncOperation<IAsyncOperation<TResult>, TResult>,
	public Requires<IAsyncOperation<TResult>, IAsyncInfo>
{
    using AbiType = typename Internal::Implementation<IAsyncOperation<TResult>>::AbiType;
    MODERN_GENERIC_INTERFACE(IAsyncOperation)
};

template <typename TResult, typename TProgress>
class IAsyncOperationWithProgress :
	public IInspectable,
	public impl_IAsyncOperationWithProgress<IAsyncOperationWithProgress<TResult, TProgress>, TResult, TProgress>,
	public Requires<IAsyncOperationWithProgress<TResult, TProgress>, IAsyncInfo>
{
    using AbiType = typename Internal::Implementation<IAsyncOperationWithProgress<TResult, TProgress>>::AbiType;
    MODERN_GENERIC_INTERFACE(IAsyncOperationWithProgress)
};

class IPropertyValue;

template <typename T>
class IReference :
	public IInspectable,
	public impl_IReference<IReference<T>, T>,
	public Requires<IReference<T>, IPropertyValue>
{
    using AbiType = typename Internal::Implementation<IReference<T>>::AbiType;
    MODERN_GENERIC_INTERFACE(IReference)
};

}}}

namespace Modern { namespace Windows { namespace Foundation { namespace Collections {

template <typename T>
class IIterator :
	public IInspectable,
	public impl_IIterator<IIterator<T>, T>
{
    using AbiType = typename Internal::Implementation<IIterator<T>>::AbiType;
	MODERN_GENERIC_INTERFACE(IIterator)
};

template <typename T>
class IIterable :
	public IInspectable,
	public impl_IIterable<IIterable<T>, T>
{
    using AbiType = typename Internal::Implementation<IIterable<T>>::AbiType;
    MODERN_GENERIC_INTERFACE(IIterable)
};

template <typename K, typename V>
class IKeyValuePair :
	public IInspectable,
	public impl_IKeyValuePair<IKeyValuePair<K, V>, K, V>
{
    using AbiType = typename Internal::Implementation<IKeyValuePair<K, V>>::AbiType;
    MODERN_GENERIC_INTERFACE(IKeyValuePair)
};

template <typename T>
class IVectorView :
	public IInspectable,
	public impl_IVectorView<IVectorView<T>, T>,
	public Requires<IVectorView<T>, IIterable<T>>
{
    using AbiType = typename Internal::Implementation<IVectorView<T>>::AbiType;
    MODERN_GENERIC_INTERFACE(IVectorView)
};

template <typename T>
class IVector :
	public IInspectable,
	public impl_IVector<IVector<T>, T>,
	public Requires<IVector<T>, IIterable<T>>
{
    using AbiType = typename Internal::Implementation<IVector<T>>::AbiType;
    MODERN_GENERIC_INTERFACE(IVector)
};

template <typename K, typename V>
class IMapView :
	public IInspectable,
	public impl_IMapView<IMapView<K, V>, K, V>,
	public Requires<IMapView<K, V>, IIterable<IKeyValuePair<K, V>>>
{
    using AbiType = typename Internal::Implementation<IMapView<K, V>>::AbiType;
    MODERN_GENERIC_INTERFACE(IMapView)
};

template <typename K, typename V>
class IMap :
	public IInspectable,
	public impl_IMap<IMap<K, V>, K, V>,
	public Requires<IMap<K, V>, IIterable<IKeyValuePair<K, V>>>
{
    using AbiType = typename Internal::Implementation<IMap<K, V>>::AbiType;
    MODERN_GENERIC_INTERFACE(IMap)
};

template <typename K>
class IMapChangedEventArgs :
	public IInspectable,
	public impl_IMapChangedEventArgs<IMapChangedEventArgs<K>, K>
{
    using AbiType = typename Internal::Implementation<IMapChangedEventArgs<K>>::AbiType;
    MODERN_GENERIC_INTERFACE(IMapChangedEventArgs)
};

template <typename K, typename V>
class IMapChangedEventHandler :
	public IUnknown,
	public impl_IMapChangedEventHandler<IMapChangedEventHandler<K, V>, K, V>
{
    using AbiType = typename Internal::Implementation<IMapChangedEventHandler<K, V>>::AbiType;
    MODERN_GENERIC_INTERFACE(IMapChangedEventHandler)
};

template <typename K, typename V>
class IObservableMap :
	public IInspectable,
	public impl_IObservableMap<IObservableMap<K, V>, K, V>,
	public Requires<IObservableMap<K, V>, IMap<K, V>>,
	public Requires<IObservableMap<K, V>, IIterable<IKeyValuePair<K, V>>>
{
    using AbiType = typename Internal::Implementation<IObservableMap<K, V>>::AbiType;
    MODERN_GENERIC_INTERFACE(IObservableMap)
};

class IVectorChangedEventArgs :
	public IInspectable,
	public impl_IVectorChangedEventArgs<IVectorChangedEventArgs>
{
    MODERN_INTERFACE(IVectorChangedEventArgs)
};

template <typename T>
class IVectorChangedEventHandler :
	public IUnknown,
	public impl_IVectorChangedEventHandler<IVectorChangedEventHandler<T>, T>
{
    using AbiType = typename Internal::Implementation<IVectorChangedEventHandler<T>>::AbiType;
    MODERN_GENERIC_INTERFACE(IVectorChangedEventHandler)
};

template <typename T>
class IObservableVector :
	public IInspectable,
	public impl_IObservableVector<IObservableVector<T>, T>,
	public Requires<IObservableVector<T>, IVector<T>>,
	public Requires<IObservableVector<T>, IIterable<T>>
{
    using AbiType = typename Internal::Implementation<IObservableVector<T>>::AbiType;
    MODERN_GENERIC_INTERFACE(IObservableVector)
};

}}}}
