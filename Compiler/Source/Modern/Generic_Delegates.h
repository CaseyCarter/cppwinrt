
namespace Modern { namespace Internal {

template <typename TProgress, typename THandler>
class Windows_Foundation_AsyncActionProgressHandler : public Implements<typename Abi<Windows::Foundation::IAsyncActionProgressHandler<TProgress>>::Type>
{
	THandler m_handler;

public:

    using DefaultInterface = Windows::Foundation::IAsyncActionProgressHandler<TProgress>;

	Windows_Foundation_AsyncActionProgressHandler(THandler handler) :
		m_handler(handler)
	{}

	virtual HRESULT __stdcall abi_Invoke(typename AbiArgument<Windows::Foundation::IAsyncActionWithProgress<TProgress>>::In sender, typename AbiArgument<TProgress>::In args) noexcept override
	{
		return Call([&]
		{
			m_handler(Forward<Windows::Foundation::IAsyncActionWithProgress<TProgress>>(sender), Forward<TProgress>(args));
		});
	}
};

template <typename TProgress, typename THandler>
class Windows_Foundation_AsyncActionWithProgressCompletedHandler : public Implements<typename Abi<Windows::Foundation::IAsyncActionWithProgressCompletedHandler<TProgress>>::Type>
{
	THandler m_handler;

public:

    using DefaultInterface = Windows::Foundation::IAsyncActionWithProgressCompletedHandler<TProgress>;

	Windows_Foundation_AsyncActionWithProgressCompletedHandler(THandler handler) :
		m_handler(handler)
	{}

	virtual HRESULT __stdcall abi_Invoke(typename Abi<Windows::Foundation::IAsyncActionWithProgress<TProgress>>::Type * sender, AsyncStatus args) noexcept override
	{
		return Call([&]
		{
			m_handler(Forward<Windows::Foundation::IAsyncActionWithProgress<TProgress>>(sender), args);
		});
	}
};

template <typename TResult, typename TProgress, typename THandler>
class Windows_Foundation_AsyncOperationProgressHandler : public Implements<typename Abi<Windows::Foundation::IAsyncOperationProgressHandler<TResult, TProgress>>::Type>
{
	THandler m_handler;

public:

    using DefaultInterface = Windows::Foundation::IAsyncOperationProgressHandler<TResult, TProgress>;

	Windows_Foundation_AsyncOperationProgressHandler(THandler handler) :
		m_handler(handler)
	{}

	virtual HRESULT __stdcall abi_Invoke(typename Abi<Windows::Foundation::IAsyncOperationWithProgress<TResult, TProgress>>::Type * sender, typename AbiArgument<TProgress>::In args) noexcept override
	{
		return Call([&]
		{
			m_handler(Forward<Windows::Foundation::IAsyncOperationWithProgress<TResult, TProgress>>(sender), Forward<TProgress>(args));
		});
	}
};

template <typename TResult, typename TProgress, typename THandler>
class Windows_Foundation_AsyncOperationWithProgressCompletedHandler : public Implements<typename Abi<Windows::Foundation::IAsyncOperationWithProgressCompletedHandler<TResult, TProgress>>::Type>
{
	THandler m_handler;

public:

    using DefaultInterface = Windows::Foundation::IAsyncOperationWithProgressCompletedHandler<TResult, TProgress>;

	Windows_Foundation_AsyncOperationWithProgressCompletedHandler(THandler handler) :
		m_handler(handler)
	{
	}

	virtual HRESULT __stdcall abi_Invoke(typename Abi<Windows::Foundation::IAsyncOperationWithProgress<TResult, TProgress>>::Type * sender, AsyncStatus args) noexcept override
	{
		return Call([&]
		{
			m_handler(Forward<Windows::Foundation::IAsyncOperationWithProgress<TResult, TProgress>>(sender), args);
		});
	}
};

template <typename TResult, typename THandler>
class Windows_Foundation_AsyncOperationCompletedHandler : public Implements<typename Abi<Windows::Foundation::IAsyncOperationCompletedHandler<TResult>>::Type>
{
	THandler m_handler;

public:

    using DefaultInterface = Windows::Foundation::IAsyncOperationCompletedHandler<TResult>;

	Windows_Foundation_AsyncOperationCompletedHandler(THandler handler) :
		m_handler(handler)
	{
	}

	virtual HRESULT __stdcall abi_Invoke(typename Abi<Windows::Foundation::IAsyncOperation<TResult>>::Type * sender, AsyncStatus args) noexcept override
	{
		return Call([&]
		{
			m_handler(Forward<Windows::Foundation::IAsyncOperation<TResult>>(sender), args);
		});
	}
};

template <typename TArgs, typename THandler>
class Windows_Foundation_EventHandler : public Implements<typename Abi<Windows::Foundation::IEventHandler<TArgs>>::Type>
{
	THandler m_handler;

public:

    using DefaultInterface = Windows::Foundation::IEventHandler<TArgs>;

	Windows_Foundation_EventHandler(THandler handler) :
		m_handler(handler)
	{
	}

	virtual HRESULT __stdcall abi_Invoke(Abi<IInspectable>::Type * sender, typename AbiArgument<TArgs>::In args) noexcept override
	{
		return Call([&]
		{
			m_handler(Forward<IInspectable>(sender), Forward<TArgs>(args));
		});
	}
};

template <typename TSender, typename TArgs, typename THandler>
class Windows_Foundation_TypedEventHandler : public Implements<typename Abi<Windows::Foundation::ITypedEventHandler<TSender, TArgs>>::Type>
{
	THandler m_handler;

public:

    using DefaultInterface = Windows::Foundation::ITypedEventHandler<TSender, TArgs>;

	Windows_Foundation_TypedEventHandler(THandler handler) : 
		m_handler(handler)
	{
	}

	virtual HRESULT __stdcall abi_Invoke(typename AbiArgument<TSender>::In sender, typename AbiArgument<TArgs>::In args) noexcept override
	{
		return Call([&]
		{
			m_handler(Forward<TSender>(sender), Forward<TArgs>(args));
		});
	}
};

template <typename K, typename V, typename Handler>
class Windows_Foundation_Collections_MapChangedEventHandler : public Implements<typename Abi<Windows::Foundation::Collections::IMapChangedEventHandler<K, V>>::Type>
{
	Handler m_handler;

public:

    using DefaultInterface = Windows::Foundation::Collections::IMapChangedEventHandler<K, V>;

	Windows_Foundation_Collections_MapChangedEventHandler(Handler handler) :
		m_handler(handler)
	{}

	virtual HRESULT __stdcall abi_Invoke(typename Abi<Windows::Foundation::Collections::IObservableMap<K, V>>::Type * sender, typename Abi<Windows::Foundation::Collections::IMapChangedEventArgs<K>>::Type * args) noexcept override
	{
		return Call([&]
		{
			m_handler(Forward<Windows::Foundation::Collections::IObservableMap<K, V>>(sender), Forward<Windows::Foundation::Collections::IMapChangedEventArgs<K>>(args));
		});
	}
};

template <typename T, typename Handler>
class Windows_Foundation_Collections_VectorChangedEventHandler : public Implements<typename Abi<Windows::Foundation::Collections::IVectorChangedEventHandler<T>>::Type>
{
	Handler m_handler;

public:

    using DefaultInterface = Windows::Foundation::Collections::IVectorChangedEventHandler<T>;

	Windows_Foundation_Collections_VectorChangedEventHandler(Handler handler) :
		m_handler(handler)
	{}

	virtual HRESULT __stdcall abi_Invoke(typename Abi<Windows::Foundation::Collections::IObservableVector<T>>::Type * sender, typename Abi<Windows::Foundation::Collections::IVectorChangedEventArgs>::Type * args) noexcept override
	{
		return Call([&]
		{
			m_handler(Forward<Windows::Foundation::Collections::IObservableVector<T>>(sender), Forward<Windows::Foundation::Collections::IVectorChangedEventArgs>(args));
		});
	}
};

}}

namespace Modern { namespace Windows { namespace Foundation {

template <typename TProgress, typename THandler>
IAsyncActionProgressHandler<TProgress> AsyncActionProgressHandler(THandler handler)
{
	return Make<Internal::Windows_Foundation_AsyncActionProgressHandler<TProgress, THandler>>(handler);
}

template <typename TProgress, typename THandler>
IAsyncActionWithProgressCompletedHandler<TProgress> AsyncActionWithProgressCompletedHandler(THandler handler)
{
	return Make<Internal::Windows_Foundation_AsyncActionWithProgressCompletedHandler<TProgress, THandler>>(handler);
}

template <typename TResult, typename TProgress, typename THandler>
IAsyncOperationProgressHandler<TResult, TProgress> AsyncOperationProgressHandler(THandler handler)
{
	return Make<Internal::Windows_Foundation_AsyncOperationProgressHandler<TResult, TProgress, THandler>>(handler);
}

template <typename Result, typename Progress, typename Handler>
IAsyncOperationWithProgressCompletedHandler<Result, Progress> AsyncOperationWithProgressCompletedHandler(Handler handler)
{
	return Make<Internal::Windows_Foundation_AsyncOperationWithProgressCompletedHandler<Result, Progress, Handler>>(handler);
}

template <typename TResult, typename THandler>
IAsyncOperationCompletedHandler<TResult> AsyncOperationCompletedHandler(THandler handler)
{
	return Make<Internal::Windows_Foundation_AsyncOperationCompletedHandler<TResult, THandler>>(handler);
}

template <typename TArgs, typename THandler>
IEventHandler<TArgs> EventHandler(THandler handler)
{
	return Make<Internal::Windows_Foundation_EventHandler<TArgs, THandler>>(handler);
}

template <typename TSender, typename TArgs, typename THandler>
ITypedEventHandler<TSender, TArgs> TypedEventHandler(THandler handler)
{
	return Make<Internal::Windows_Foundation_TypedEventHandler<TSender, TArgs, THandler>>(handler);
}

}}}

namespace Modern { namespace Windows { namespace Foundation { namespace Collections {

template <typename K, typename V, typename Handler>
IMapChangedEventHandler<K, V> MapChangedEventHandler(Handler handler)
{
	return Make<Internal::Windows_Foundation_Collections_MapChangedEventHandler<K, V, Handler>>(handler);
}

template <typename T, typename Handler>
IVectorChangedEventHandler<T> VectorChangedEventHandler(Handler handler)
{
	return Make<Internal::Windows_Foundation_Collections_VectorChangedEventHandler<T, Handler>>(handler);
}

}}}}
