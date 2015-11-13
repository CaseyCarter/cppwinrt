
namespace Modern { namespace ABI {

using IUnknown = ::IUnknown;
using IInspectable = ::IInspectable;
using String = HSTRING;

}}

namespace Modern { namespace ABI { namespace Internal {

template <typename T>
class IsClass
{
    template <typename U> static std::true_type Check(decltype(std::is_void<U::DefaultInterface>::value));
    template <typename>   static std::false_type Check(...);

public:

    static constexpr bool Value = decltype(Check<T>(0))::value;
};

template <typename T, typename Enable = void>
struct Argument
{
    using Type = T;
    using In = Type;
    using Out = Type *;
};

template <typename T>
struct Argument<T, typename std::enable_if<IsClass<T>::Value>::type>
{
    using Type = typename T::DefaultInterface;
    using In = Type *;
    using Out = Type **;
};

template <typename T>
struct Argument<T, typename std::enable_if<std::is_convertible<T, IUnknown>::value>::type>
{
    using Type = T;
    using In = Type *;
    using Out = Type **;
};

template <>
struct Argument<String>
{
    using Type = HSTRING;
    using In = Type;
    using Out = Type *;
};

template <class T>
struct NotSpecializedFalse
{
    static constexpr bool Value = false;
};

template <class T>
struct NotSpecialized
{
    static_assert(NotSpecializedFalse<T>::Value, "This interface has not be specialized.");
};

}}}

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

namespace Modern { namespace ABI { namespace Windows { namespace Foundation {

template <typename TProgress>
struct impl_IAsyncActionProgressHandler;

template <typename TProgress>
struct impl_IAsyncActionWithProgress;

template <typename TProgress>
struct impl_IAsyncActionWithProgressCompletedHandler;

template <typename TResult, typename TProgress>
struct impl_IAsyncOperationProgressHandler;

template <typename TResult, typename TProgress>
struct impl_IAsyncOperationWithProgressCompletedHandler;

template <typename TResult>
struct impl_IAsyncOperationCompletedHandler;

template <typename T>
struct impl_IEventHandler;

template <typename TSender, typename TArgs>
struct impl_ITypedEventHandler;

template <typename TResult>
struct impl_IAsyncOperation;

template <typename TResult, typename TProgress>
struct impl_IAsyncOperationWithProgress;

template <typename T>
struct impl_IReference;

template <typename TProgress>
struct IAsyncActionProgressHandler :
    impl_IAsyncActionProgressHandler<TProgress>,
    Internal::NotSpecialized<IAsyncActionProgressHandler<TProgress>>
{};

template <typename TProgress>
struct IAsyncActionWithProgress :
    impl_IAsyncActionWithProgress<TProgress>,
    Internal::NotSpecialized<IAsyncActionWithProgress<TProgress>>
{};

template <typename TProgress>
struct IAsyncActionWithProgressCompletedHandler :
    impl_IAsyncActionWithProgressCompletedHandler<TProgress>,
    Internal::NotSpecialized<IAsyncActionWithProgressCompletedHandler<TProgress>>
{};

template <typename TResult, typename TProgress>
struct IAsyncOperationProgressHandler :
    impl_IAsyncOperationProgressHandler<TResult, TProgress>,
    Internal::NotSpecialized<IAsyncOperationProgressHandler<TResult, TProgress>>
{};

template <typename TResult, typename TProgress>
struct IAsyncOperationWithProgressCompletedHandler :
    impl_IAsyncOperationWithProgressCompletedHandler<TResult, TProgress>,
    Internal::NotSpecialized<IAsyncOperationWithProgressCompletedHandler<TResult, TProgress>>
{};

template <typename TResult>
struct IAsyncOperationCompletedHandler :
    impl_IAsyncOperationCompletedHandler<TResult>,
    Internal::NotSpecialized<IAsyncOperationCompletedHandler<TResult>>
{};

template <typename T>
struct IEventHandler :
    impl_IEventHandler<T>,
    Internal::NotSpecialized<IEventHandler<T>>
{};

template <typename TSender, typename TArgs>
struct ITypedEventHandler :
    impl_ITypedEventHandler<TSender, TArgs>,
    Internal::NotSpecialized<ITypedEventHandler<TSender, TArgs>>
{};

template <typename TResult>
struct IAsyncOperation :
    impl_IAsyncOperation<TResult>,
    Internal::NotSpecialized<IAsyncOperation<TResult>>
{};

template <typename TResult, typename TProgress>
struct IAsyncOperationWithProgress :
    impl_IAsyncOperationWithProgress<TResult, TProgress>,
    Internal::NotSpecialized<IAsyncOperationWithProgress<TResult, TProgress>>
{};

template <typename T>
struct IReference :
    impl_IReference<T>,
    Internal::NotSpecialized<IReference<T>>
{};

template <typename TProgress>
struct __declspec(novtable) impl_IAsyncActionProgressHandler : IUnknown
{
    virtual HRESULT __stdcall abi_Invoke(IAsyncActionWithProgress<TProgress> * asyncInfo, typename Internal::Argument<TProgress>::In progressInfo) = 0;
};

template <typename TProgress>
struct __declspec(novtable) impl_IAsyncActionWithProgress : IInspectable
{
    virtual HRESULT __stdcall put_Progress(IAsyncActionProgressHandler<TProgress> * handler) = 0;
    virtual HRESULT __stdcall get_Progress(IAsyncActionProgressHandler<TProgress> ** handler) = 0;
    virtual HRESULT __stdcall put_Completed(IAsyncActionWithProgressCompletedHandler<TProgress> * handler) = 0;
    virtual HRESULT __stdcall get_Completed(IAsyncActionWithProgressCompletedHandler<TProgress> ** handler) = 0;
    virtual HRESULT __stdcall abi_GetResults() = 0;
};

template <typename TProgress>
struct __declspec(novtable) impl_IAsyncActionWithProgressCompletedHandler : IUnknown
{
    virtual HRESULT __stdcall Invoke(IAsyncActionWithProgress<TProgress> * asyncInfo, AsyncStatus status) = 0;
};

template <typename TResult, typename TProgress>
struct __declspec(novtable) impl_IAsyncOperationProgressHandler : IUnknown
{
    virtual HRESULT __stdcall Invoke(IAsyncOperationWithProgress<TResult, TProgress> * asyncInfo, typename Internal::Argument<TProgress>::In progressInfo) = 0;
};

template <typename TResult, typename TProgress>
struct __declspec(novtable) impl_IAsyncOperationWithProgressCompletedHandler : IUnknown
{
    virtual HRESULT __stdcall abi_Invoke(IAsyncOperationWithProgress<TResult, TProgress> * asyncInfo, AsyncStatus status) = 0;
};

template <typename TResult>
struct __declspec(novtable) impl_IAsyncOperationCompletedHandler : IUnknown
{
    virtual HRESULT __stdcall abi_Invoke(IAsyncOperation<TResult> * asyncInfo, AsyncStatus status) = 0;
};

template <typename T>
struct __declspec(novtable) impl_IEventHandler : IUnknown
{
    virtual HRESULT __stdcall abi_Invoke(IInspectable * sender, typename Internal::Argument<T>::In args) = 0;
};

template <typename TSender, typename TArgs>
struct __declspec(novtable) impl_ITypedEventHandler : IUnknown
{
    virtual HRESULT __stdcall abi_Invoke(typename Internal::Argument<TSender>::In sender, typename Internal::Argument<TArgs>::In args) = 0;
};

template <typename TResult>
struct __declspec(novtable) impl_IAsyncOperation : IInspectable
{
    virtual HRESULT __stdcall put_Completed(IAsyncOperationCompletedHandler<TResult> * handler) = 0;
    virtual HRESULT __stdcall get_Completed(IAsyncOperationCompletedHandler<TResult> ** handler) = 0;
    virtual HRESULT __stdcall abi_GetResults(typename Internal::Argument<TResult>::Out results) = 0;
};

template <typename TResult, typename TProgress>
struct __declspec(novtable) impl_IAsyncOperationWithProgress : IInspectable
{
    virtual HRESULT __stdcall put_Progress(IAsyncOperationProgressHandler<TResult, TProgress> * handler) = 0;
    virtual HRESULT __stdcall get_Progress(IAsyncOperationProgressHandler<TResult, TProgress> ** handler) = 0;
    virtual HRESULT __stdcall put_Completed(IAsyncOperationWithProgressCompletedHandler<TResult, TProgress> * handler) = 0;
    virtual HRESULT __stdcall get_Completed(IAsyncOperationWithProgressCompletedHandler<TResult, TProgress> ** handler) = 0;
    virtual HRESULT __stdcall abi_GetResults(typename Internal::Argument<TResult>::Out results) = 0;
};

template <typename T>
struct __declspec(novtable) impl_IReference : IInspectable
{
    virtual HRESULT __stdcall get_Value(typename Internal::Argument<T>::Out value) = 0;
};

}}}}

namespace Modern { namespace ABI { namespace Windows { namespace Foundation { namespace Collections {

template <typename T>
struct impl_IIterator;

template <typename T>
struct impl_IIterable;

template <typename K, typename V>
struct impl_IKeyValuePair;

template <typename T>
struct impl_IVectorView;

template <typename T>
struct impl_IVector;

template <typename K, typename V>
struct impl_IMapView;

template <typename K, typename V>
struct impl_IMap;

template <typename K>
struct impl_IMapChangedEventArgs;

template <typename K, typename V>
struct impl_IMapChangedEventHandler;

template <typename K, typename V>
struct impl_IObservableMap;

template <typename T>
struct impl_IVectorChangedEventHandler;

template <typename T>
struct impl_IObservableVector;

template <typename T>
struct IIterator :
    impl_IIterator<T>,
    Internal::NotSpecialized<IIterator<T>>
{};

template <typename T>
struct IIterable :
    impl_IIterable<T>,
    Internal::NotSpecialized<IIterable<T>>
{};

template <typename K, typename V>
struct IKeyValuePair :
    impl_IKeyValuePair<K, V>,
    Internal::NotSpecialized<IKeyValuePair<K, V>>
{};

template <typename T>
struct IVectorView :
    impl_IVectorView<T>,
    Internal::NotSpecialized<IVectorView<T>>
{};

template <typename T>
struct IVector :
    impl_IVector<T>,
    Internal::NotSpecialized<IVector<T>>
{};

template <typename K, typename V>
struct IMapView :
    impl_IMapView<K, V>,
    Internal::NotSpecialized<IMapView<K, V>>
{};

template <typename K, typename V>
struct IMap :
    impl_IMap<K, V>,
    Internal::NotSpecialized<IMap<K, V>>
{};

template <typename K>
struct IMapChangedEventArgs :
    impl_IMapChangedEventArgs<K>,
    Internal::NotSpecialized<IMapChangedEventArgs<K>>
{};

template <typename K, typename V>
struct IMapChangedEventHandler :
    impl_IMapChangedEventHandler<K, V>,
    Internal::NotSpecialized<IMapChangedEventHandler<K, V>>
{};

template <typename K, typename V>
struct IObservableMap :
    impl_IObservableMap<K, V>,
    Internal::NotSpecialized<IObservableMap<K, V>>
{};

template <typename T>
struct IVectorChangedEventHandler :
    impl_IVectorChangedEventHandler<T>,
    Internal::NotSpecialized<IVectorChangedEventHandler<T>>
{};

template <typename T>
struct IObservableVector :
    impl_IObservableVector<T>,
    Internal::NotSpecialized<IObservableVector<T>>
{};

template <typename T>
struct __declspec(novtable) impl_IIterator : IInspectable
{
    virtual HRESULT __stdcall get_Current(typename Internal::Argument<T>::Out current) = 0;
    virtual HRESULT __stdcall get_HasCurrent(boolean * hasCurrent) = 0;
    virtual HRESULT __stdcall abi_MoveNext(boolean * hasCurrent) = 0;
    virtual HRESULT __stdcall abi_GetMany(unsigned capacity, typename Internal::Argument<T>::Out value, unsigned * actual) = 0;

};

template <typename T>
struct __declspec(novtable) impl_IIterable : IInspectable
{
    virtual HRESULT __stdcall abi_First(IIterator<T> ** first) = 0;
};

template <typename K, typename V>
struct __declspec(novtable) impl_IKeyValuePair : IInspectable
{
    virtual HRESULT __stdcall get_Key(typename Internal::Argument<K>::Out key) = 0;
    virtual HRESULT __stdcall get_Value(typename Internal::Argument<V>::Out value) = 0;
};

template <typename T>
struct __declspec(novtable) impl_IVectorView : IInspectable
{
    virtual HRESULT __stdcall abi_GetAt(unsigned index, typename Internal::Argument<T>::Out item) = 0;
    virtual HRESULT __stdcall get_Size(unsigned * size) = 0;
    virtual HRESULT __stdcall abi_IndexOf(typename Internal::Argument<T>::In value, unsigned * index, boolean * found) = 0;
    virtual HRESULT __stdcall abi_GetMany(unsigned startIndex, unsigned capacity, typename Internal::Argument<T>::Out value, unsigned * actual) = 0;
};

template <typename T>
struct __declspec(novtable) impl_IVector : IInspectable
{
    virtual HRESULT __stdcall abi_GetAt(unsigned index, typename Internal::Argument<T>::Out item) = 0;
    virtual HRESULT __stdcall get_Size(unsigned * size) = 0;
    virtual HRESULT __stdcall abi_GetView(IVectorView<T> ** view) = 0;
    virtual HRESULT __stdcall abi_IndexOf(typename Internal::Argument<T>::In value, unsigned * index, boolean * found) = 0;
    virtual HRESULT __stdcall abi_SetAt(unsigned index, typename Internal::Argument<T>::In item) = 0;
    virtual HRESULT __stdcall abi_InsertAt(unsigned index, typename Internal::Argument<T>::In item) = 0;
    virtual HRESULT __stdcall abi_RemoveAt(unsigned index) = 0;
    virtual HRESULT __stdcall abi_Append(typename Internal::Argument<T>::In item) = 0;
    virtual HRESULT __stdcall abi_RemoveAtEnd() = 0;
    virtual HRESULT __stdcall abi_Clear() = 0;
    virtual HRESULT __stdcall abi_GetMany(unsigned startIndex, unsigned capacity, typename Internal::Argument<T>::Out value, unsigned * actual) = 0;
    virtual HRESULT __stdcall abi_ReplaceAll(unsigned count, typename Internal::Argument<T>::Out value) = 0;

};

template <typename K, typename V>
struct __declspec(novtable) impl_IMapView : IInspectable
{
    virtual HRESULT __stdcall abi_Lookup(typename Internal::Argument<K>::In key, typename Internal::Argument<V>::Out value) = 0;
    virtual HRESULT __stdcall get_Size(unsigned int * size) = 0;
    virtual HRESULT __stdcall abi_HasKey(typename Internal::Argument<K>::In key, boolean * found) = 0;
    virtual HRESULT __stdcall abi_Split(IMapView<K, V> ** firstPartition, IMapView<K, V> ** secondPartition) = 0;
};

template <typename K, typename V>
struct __declspec(novtable) impl_IMap : IInspectable
{
    virtual HRESULT __stdcall abi_Lookup(typename Internal::Argument<K>::In key, typename Internal::Argument<V>::Out value) = 0;
    virtual HRESULT __stdcall get_Size(unsigned int * size) = 0;
    virtual HRESULT __stdcall abi_HasKey(typename Internal::Argument<K>::In key, boolean * found) = 0;
    virtual HRESULT __stdcall abi_GetView(IMapView<K, V> ** view) = 0;
    virtual HRESULT __stdcall abi_Insert(typename Internal::Argument<K>::In key, typename Internal::Argument<V>::In value, boolean * replaced) = 0;
    virtual HRESULT __stdcall abi_Remove(typename Internal::Argument<K>::In key) = 0;
    virtual HRESULT __stdcall abi_Clear() = 0;
};

template <typename K>
struct __declspec(novtable) impl_IMapChangedEventArgs : IInspectable
{
    virtual HRESULT __stdcall get_CollectionChange(Modern::Windows::Foundation::Collections::CollectionChange * value) = 0;
    virtual HRESULT __stdcall get_Key(typename Internal::Argument<K>::Out value) = 0;
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
