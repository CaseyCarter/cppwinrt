
namespace Modern { namespace ABI { namespace Windows { namespace Foundation {

template <typename TProgress> struct IAsyncActionProgressHandler;
template <typename TProgress> struct IAsyncActionWithProgress;
template <typename TProgress> struct IAsyncActionWithProgressCompletedHandler;
template <typename TResult, typename TProgress> struct IAsyncOperationProgressHandler;
template <typename TResult, typename TProgress> struct IAsyncOperationWithProgressCompletedHandler;
template <typename TResult> struct IAsyncOperationCompletedHandler;
template <typename T> struct IEventHandler;
template <typename TSender, typename TArgs> struct ITypedEventHandler;
template <typename TResult> struct IAsyncOperation;
template <typename TResult, typename TProgress> struct IAsyncOperationWithProgress;
template <typename T> struct IReference;

template <typename TProgress>
struct __declspec(novtable) impl_IAsyncActionProgressHandler : IUnknown
{
	virtual HRESULT __stdcall abi_Invoke(IAsyncActionWithProgress<TProgress> * asyncInfo, ArgIn<TProgress> progressInfo) = 0;
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
	virtual HRESULT __stdcall abi_Invoke(IAsyncActionWithProgress<TProgress> * asyncInfo, AsyncStatus status) = 0;
};

template <typename TResult, typename TProgress>
struct __declspec(novtable) impl_IAsyncOperationProgressHandler : IUnknown
{
	virtual HRESULT __stdcall abi_Invoke(IAsyncOperationWithProgress<TResult, TProgress> * asyncInfo, ArgIn<TProgress> progressInfo) = 0;
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
	virtual HRESULT __stdcall abi_Invoke(IInspectable * sender, ArgIn<T> args) = 0;
};

template <typename TSender, typename TArgs>
struct __declspec(novtable) impl_ITypedEventHandler : IUnknown
{
	virtual HRESULT __stdcall abi_Invoke(ArgIn<TSender> sender, ArgIn<TArgs> args) = 0;
};

template <typename TResult>
struct __declspec(novtable) impl_IAsyncOperation : IInspectable
{
	virtual HRESULT __stdcall put_Completed(IAsyncOperationCompletedHandler<TResult> * handler) = 0;
	virtual HRESULT __stdcall get_Completed(IAsyncOperationCompletedHandler<TResult> ** handler) = 0;
	virtual HRESULT __stdcall abi_GetResults(ArgOut<TResult> results) = 0;
};

template <typename TResult, typename TProgress>
struct __declspec(novtable) impl_IAsyncOperationWithProgress : IInspectable
{
	virtual HRESULT __stdcall put_Progress(IAsyncOperationProgressHandler<TResult, TProgress> * handler) = 0;
	virtual HRESULT __stdcall get_Progress(IAsyncOperationProgressHandler<TResult, TProgress> ** handler) = 0;
	virtual HRESULT __stdcall put_Completed(IAsyncOperationWithProgressCompletedHandler<TResult, TProgress> * handler) = 0;
	virtual HRESULT __stdcall get_Completed(IAsyncOperationWithProgressCompletedHandler<TResult, TProgress> ** handler) = 0;
	virtual HRESULT __stdcall abi_GetResults(ArgOut<TResult> results) = 0;
};

template <typename T>
struct __declspec(novtable) impl_IReference : IInspectable
{
	virtual HRESULT __stdcall get_Value(ArgOut<T> value) = 0;
};

}}}}

namespace Modern { namespace Windows { namespace Foundation {

template <typename TProgress> struct IAsyncActionProgressHandler;
template <typename TProgress> struct IAsyncActionWithProgress;
template <typename TProgress> struct IAsyncActionWithProgressCompletedHandler;
template <typename TResult, typename TProgress> struct IAsyncOperationProgressHandler;
template <typename TResult, typename TProgress> struct IAsyncOperationWithProgressCompletedHandler;
template <typename TResult> struct IAsyncOperationCompletedHandler;
template <typename T> struct IEventHandler;
template <typename TSender, typename TArgs> struct ITypedEventHandler;
template <typename TResult> struct IAsyncOperation;
template <typename TResult, typename TProgress> struct IAsyncOperationWithProgress;
template <typename T> struct IReference;

template <typename D, typename TProgress>
struct impl_IAsyncActionProgressHandler
{
	void Invoke(IAsyncActionWithProgress<TProgress> const & sender, TProgress const & args) const
	{
		check(static_cast<D const &>(*this)->abi_Invoke(get(sender), abi(args)));
	}
};

template <typename D, typename TProgress>
struct impl_IAsyncActionWithProgress
{
	void Progress(IAsyncActionProgressHandler<TProgress> const & handler) const
	{
		check(static_cast<D const &>(*this)->put_Progress(get(handler)));
	}

	template <typename Handler>
	void Progress(Handler handler) const
	{
		return Progress(AsyncActionProgressHandler<TProgress>(handler));
	}

	IAsyncActionProgressHandler<TProgress> Progress() const
	{
		IAsyncActionProgressHandler<TProgress> handler;
		check(static_cast<D const &>(*this)->get_Progress(put(handler)));
		return handler;
	}

	void Completed(IAsyncActionWithProgressCompletedHandler<TProgress> const & handler) const
	{
		check(static_cast<D const &>(*this)->put_Completed(get(handler)));
	}

	template <typename Handler>
	void Completed(Handler handler) const
	{
		return Completed(AsyncActionWithProgressCompletedHandler<TProgress>(handler));
	}

	IAsyncActionWithProgressCompletedHandler<TProgress> Completed() const
	{
		IAsyncActionWithProgressCompletedHandler<TProgress> handler;
		check(static_cast<D const &>(*this)->get_Completed(put(handler)));
		return handler;
	}

	void GetResults() const
	{
		check(static_cast<D const &>(*this)->abi_GetResults());
	}
};

template <typename D, typename TProgress>
struct impl_IAsyncActionWithProgressCompletedHandler
{
	void Invoke(IAsyncActionWithProgress<TProgress> const & sender, AsyncStatus const args) const
	{
		check(static_cast<D const &>(*this)->abi_Invoke(get(sender), args));
	}
};

template <typename D, typename TResult, typename TProgress>
struct impl_IAsyncOperationProgressHandler
{
	void Invoke(IAsyncOperationWithProgress<TResult, TProgress> const & sender, TProgress const & args) const
	{
		check(static_cast<D const &>(*this)->abi_Invoke(get(sender), abi(args)));
	}
};

template <typename D, typename TResult, typename TProgress>
struct impl_IAsyncOperationWithProgressCompletedHandler
{
	void Invoke(IAsyncOperationWithProgress<TResult, TProgress> const & sender, AsyncStatus const args) const
	{
		check(static_cast<D const &>(*this)->abi_Invoke(get(sender), args));
	}
};

template <typename D, typename TResult>
struct impl_IAsyncOperationCompletedHandler
{
	void Invoke(IAsyncOperation<TResult> const & sender, AsyncStatus const args) const
	{
		check(static_cast<D const &>(*this)->abi_Invoke(get(sender), args));
	}
};

template <typename D, typename T>
struct impl_IEventHandler
{
	void Invoke(IInspectable const & sender, T const & args) const
	{
		check(static_cast<D const &>(*this)->abi_Invoke(get(sender), abi(args)));
	}
};

template <typename D, typename TSender, typename TArgs>
struct impl_ITypedEventHandler
{
	void Invoke(TSender const & sender, TArgs const & args) const
	{
		check(static_cast<D const &>(*this)->abi_Invoke(abi(sender), abi(args)));
	}
};

template <typename D, typename TResult>
struct impl_IAsyncOperation
{
	void Completed(IAsyncOperationCompletedHandler<TResult> const & handler) const
	{
		check(static_cast<D const &>(*this)->put_Completed(get(handler)));
	}

	template <typename Handler>
	void Completed(Handler handler) const
	{
		return Completed(AsyncOperationCompletedHandler<TResult>(handler));
	}

	IAsyncOperationCompletedHandler<TResult> Completed() const
	{
		IAsyncOperationCompletedHandler<TResult> temp;
		check(static_cast<D const &>(*this)->get_Completed(put(temp)));
		return temp;
	}

	TResult GetResults() const
	{
		TResult result = Argument<TResult>::Empty();
		check(static_cast<D const &>(*this)->abi_GetResults(abi(&result)));
		return result;
	}
};

template <typename D, typename TResult, typename TProgress>
struct impl_IAsyncOperationWithProgress
{
	void Progress(IAsyncOperationProgressHandler<TResult, TProgress> const & handler) const
	{
		check(static_cast<D const &>(*this)->put_Progress(get(handler)));
	}

	template <typename Handler>
	void Progress(Handler handler) const
	{
		return Progress(AsyncOperationProgressHandler<TResult, TProgress>(handler));
	}

	IAsyncOperationProgressHandler<TResult, TProgress> Progress() const
	{
		IAsyncOperationProgressHandler<TResult, TProgress> handler;
		check(static_cast<D const &>(*this)->get_Progress(put(handler)));
		return handler;
	}

	void Completed(IAsyncOperationWithProgressCompletedHandler<TResult, TProgress> const & handler) const
	{
		check(static_cast<D const &>(*this)->put_Completed(get(handler)));
	}

	template <typename Handler>
	void Completed(Handler handler) const
	{
		return Completed(AsyncOperationWithProgressCompletedHandler<TResult, TProgress>(handler));
	}

	IAsyncOperationWithProgressCompletedHandler<TResult, TProgress> Completed() const
	{
		IAsyncOperationWithProgressCompletedHandler<TResult, TProgress> handler;
		check(static_cast<D const &>(*this)->get_Completed(put(handler)));
		return handler;
	}

	TResult GetResults() const
	{
		TResult result = Argument<TResult>::Empty();
		check(static_cast<D const &>(*this)->abi_GetResults(abi(&result)));
		return result;
	}
};

template <typename D, typename T>
struct impl_IReference
{
	T Value() const
	{
		T result = Argument<T>::Empty();
		check(static_cast<D const &>(*this)->get_Value(abi(&result)));
		return result;
	}
};

template <typename TProgress>
struct IAsyncActionProgressHandler :
	IUnknown,
	impl_IAsyncActionProgressHandler<IAsyncActionProgressHandler<TProgress>, TProgress>
{
	IAsyncActionProgressHandler(std::nullptr_t = nullptr) noexcept {}
	auto operator->() const noexcept { return static_cast<AbiPtr<IAsyncActionProgressHandler>>(m_ptr); }
};

template <typename TProgress>
struct IAsyncActionWithProgress :
	IInspectable,
	impl_IAsyncActionWithProgress<IAsyncActionWithProgress<TProgress>, TProgress>,
	Requires<IAsyncActionWithProgress<TProgress>, IAsyncInfo>
{
	IAsyncActionWithProgress(std::nullptr_t = nullptr) noexcept {}
	auto operator->() const noexcept { return static_cast<AbiPtr<IAsyncActionWithProgress>>(m_ptr); }
};

template <typename TProgress>
struct IAsyncActionWithProgressCompletedHandler :
	IUnknown,
	impl_IAsyncActionWithProgressCompletedHandler<IAsyncActionWithProgressCompletedHandler<TProgress>, TProgress>
{
	IAsyncActionWithProgressCompletedHandler(std::nullptr_t = nullptr) noexcept {}
	auto operator->() const noexcept { return static_cast<AbiPtr<IAsyncActionWithProgressCompletedHandler>>(m_ptr); }
};

template <typename TResult, typename TProgress>
struct IAsyncOperationProgressHandler :
	IUnknown,
	impl_IAsyncOperationProgressHandler<IAsyncOperationProgressHandler<TResult, TProgress>, TResult, TProgress>
{
	IAsyncOperationProgressHandler(std::nullptr_t = nullptr) noexcept {}
	auto operator->() const noexcept { return static_cast<AbiPtr<IAsyncOperationProgressHandler>>(m_ptr); }
};

template <typename TResult, typename TProgress>
struct IAsyncOperationWithProgressCompletedHandler :
	IUnknown,
	impl_IAsyncOperationWithProgressCompletedHandler<IAsyncOperationWithProgressCompletedHandler<TResult, TProgress>, TResult, TProgress>
{
	IAsyncOperationWithProgressCompletedHandler(std::nullptr_t = nullptr) noexcept {}
	auto operator->() const noexcept { return static_cast<AbiPtr<IAsyncOperationWithProgressCompletedHandler>>(m_ptr); }
};

template <typename TResult>
struct IAsyncOperationCompletedHandler :
	IUnknown,
	impl_IAsyncOperationCompletedHandler<IAsyncOperationCompletedHandler<TResult>, TResult>
{
	IAsyncOperationCompletedHandler(std::nullptr_t = nullptr) noexcept {}
	auto operator->() const noexcept { return static_cast<AbiPtr<IAsyncOperationCompletedHandler>>(m_ptr); }
};

template <typename T>
struct IEventHandler :
	IUnknown,
	impl_IEventHandler<IEventHandler<T>, T>
{
	IEventHandler(std::nullptr_t = nullptr) noexcept {}
	auto operator->() const noexcept { return static_cast<AbiPtr<IEventHandler>>(m_ptr); }
};

template <typename TSender, typename TArgs>
struct ITypedEventHandler :
	IUnknown,
	impl_ITypedEventHandler<ITypedEventHandler<TSender, TArgs>, TSender, TArgs>
{
	ITypedEventHandler(std::nullptr_t = nullptr) noexcept {}
	auto operator->() const noexcept { return static_cast<AbiPtr<ITypedEventHandler>>(m_ptr); }
};

template <typename TResult>
struct IAsyncOperation :
	IInspectable,
	impl_IAsyncOperation<IAsyncOperation<TResult>, TResult>,
	Requires<IAsyncOperation<TResult>, IAsyncInfo>
{
	IAsyncOperation(std::nullptr_t = nullptr) noexcept {}
	auto operator->() const noexcept { return static_cast<AbiPtr<IAsyncOperation>>(m_ptr); }
};

template <typename TResult, typename TProgress>
struct IAsyncOperationWithProgress :
	IInspectable,
	impl_IAsyncOperationWithProgress<IAsyncOperationWithProgress<TResult, TProgress>, TResult, TProgress>,
	Requires<IAsyncOperationWithProgress<TResult, TProgress>, IAsyncInfo>
{
	IAsyncOperationWithProgress(std::nullptr_t = nullptr) noexcept {}
	auto operator->() const noexcept { return static_cast<AbiPtr<IAsyncOperationWithProgress>>(m_ptr); }
};

struct IPropertyValue;

template <typename T>
struct IReference :
	IInspectable,
	impl_IReference<IReference<T>, T>,
	Requires<IReference<T>, IPropertyValue>
{
	IReference(std::nullptr_t = nullptr) noexcept {}
	auto operator->() const noexcept { return static_cast<AbiPtr<IReference>>(m_ptr); }

	IReference(T const & value);
};

}}}

namespace Modern {

template <typename TProgress> struct Traits<Windows::Foundation::IAsyncActionProgressHandler<TProgress>>
{
	using Abi = ABI::Windows::Foundation::IAsyncActionProgressHandler<Abi<TProgress>>;
	template <typename D> using Methods = Windows::Foundation::impl_IAsyncActionProgressHandler<D, TProgress>;
};

template <typename TProgress> struct Traits<Windows::Foundation::IAsyncActionWithProgress<TProgress>>
{
	using Abi = ABI::Windows::Foundation::IAsyncActionWithProgress<Abi<TProgress>>;
	template <typename D> using Methods = Windows::Foundation::impl_IAsyncActionWithProgress<D, TProgress>;
};

template <typename TProgress> struct Traits<Windows::Foundation::IAsyncActionWithProgressCompletedHandler<TProgress>>
{
	using Abi = ABI::Windows::Foundation::IAsyncActionWithProgressCompletedHandler<Abi<TProgress>>;
	template <typename D> using Methods = Windows::Foundation::impl_IAsyncActionWithProgressCompletedHandler<D, TProgress>;
};

template <typename TResult, typename TProgress> struct Traits<Windows::Foundation::IAsyncOperationProgressHandler<TResult, TProgress>>
{
	using Abi = ABI::Windows::Foundation::IAsyncOperationProgressHandler<Abi<TResult>, Abi<TProgress>>;
	template <typename D> using Methods = Windows::Foundation::impl_IAsyncOperationProgressHandler<D, TResult, TProgress>;
};

template <typename TResult, typename TProgress> struct Traits<Windows::Foundation::IAsyncOperationWithProgressCompletedHandler<TResult, TProgress>>
{
	using Abi = ABI::Windows::Foundation::IAsyncOperationWithProgressCompletedHandler<Abi<TResult>, Abi<TProgress>>;
	template <typename D> using Methods = Windows::Foundation::impl_IAsyncOperationWithProgressCompletedHandler<D, TResult, TProgress>;
};

template <typename TResult> struct Traits<Windows::Foundation::IAsyncOperationCompletedHandler<TResult>>
{
	using Abi = ABI::Windows::Foundation::IAsyncOperationCompletedHandler<Abi<TResult>>;
	template <typename D> using Methods = Windows::Foundation::impl_IAsyncOperationCompletedHandler<D, TResult>;
};

template <typename T> struct Traits<Windows::Foundation::IEventHandler<T>>
{
	using Abi = ABI::Windows::Foundation::IEventHandler<Abi<T>>;
	template <typename D> using Methods = Windows::Foundation::impl_IEventHandler<D, T>;
};

template <typename TSender, typename TArgs> struct Traits<Windows::Foundation::ITypedEventHandler<TSender, TArgs>>
{
	using Abi = ABI::Windows::Foundation::ITypedEventHandler<Abi<TSender>, Abi<TArgs>>;
	template <typename D> using Methods = Windows::Foundation::impl_ITypedEventHandler<D, TSender, TArgs>;
};

template <typename TResult> struct Traits<Windows::Foundation::IAsyncOperation<TResult>>
{
	using Abi = ABI::Windows::Foundation::IAsyncOperation<Abi<TResult>>;
	template <typename D> using Methods = Windows::Foundation::impl_IAsyncOperation<D, TResult>;
};

template <typename TResult, typename TProgress> struct Traits<Windows::Foundation::IAsyncOperationWithProgress<TResult, TProgress>>
{
	using Abi = ABI::Windows::Foundation::IAsyncOperationWithProgress<Abi<TResult>, Abi<TProgress>>;
	template <typename D> using Methods = Windows::Foundation::impl_IAsyncOperationWithProgress<D, TResult, TProgress>;
};

template <typename T> struct Traits<Windows::Foundation::IReference<T>>
{
	using Abi = ABI::Windows::Foundation::IReference<Abi<T>>;
	template <typename D> using Methods = Windows::Foundation::impl_IReference<D, T>;
};

}




namespace Modern { namespace Windows { namespace Foundation {

template <typename TProgress, typename THandler>
struct impl_AsyncActionProgressHandler : ImplementsDefault<IAsyncActionProgressHandler<TProgress>>
{
	impl_AsyncActionProgressHandler(THandler handler) : m_handler(handler) {}
	THandler m_handler;

	virtual HRESULT __stdcall abi_Invoke(AbiArgIn<IAsyncActionWithProgress<TProgress>> sender, AbiArgIn<TProgress> args) noexcept override
	{
		return call([&]
		{
			m_handler(forward<IAsyncActionWithProgress<TProgress>>(sender), forward<TProgress>(args));
		});
	}
};

template <typename TProgress, typename THandler>
IAsyncActionProgressHandler<TProgress> AsyncActionProgressHandler(THandler handler)
{
	return make<impl_AsyncActionProgressHandler<TProgress, THandler>>(handler);
}

template <typename TProgress, typename THandler>
struct impl_AsyncActionWithProgressCompletedHandler : ImplementsDefault<IAsyncActionWithProgressCompletedHandler<TProgress>>
{
	impl_AsyncActionWithProgressCompletedHandler(THandler handler) : m_handler(handler) {}
	THandler m_handler;

	virtual HRESULT __stdcall abi_Invoke(AbiArgIn<IAsyncActionWithProgress<TProgress>> sender, AsyncStatus args) noexcept override
	{
		return call([&]
		{
			m_handler(forward<IAsyncActionWithProgress<TProgress>>(sender), args);
		});
	}
};

template <typename TProgress, typename THandler>
IAsyncActionWithProgressCompletedHandler<TProgress> AsyncActionWithProgressCompletedHandler(THandler handler)
{
	return make<impl_AsyncActionWithProgressCompletedHandler<TProgress, THandler>>(handler);
}

template <typename TResult, typename TProgress, typename THandler>
struct impl_AsyncOperationProgressHandler : ImplementsDefault<IAsyncOperationProgressHandler<TResult, TProgress>>
{
	impl_AsyncOperationProgressHandler(THandler handler) : m_handler(handler) {}
	THandler m_handler;

	virtual HRESULT __stdcall abi_Invoke(AbiArgIn<IAsyncOperationWithProgress<TResult, TProgress>> sender, AbiArgIn<TProgress> args) noexcept override
	{
		return call([&]
		{
			m_handler(forward<IAsyncOperationWithProgress<TResult, TProgress>>(sender), forward<TProgress>(args));
		});
	}
};

template <typename TResult, typename TProgress, typename THandler>
IAsyncOperationProgressHandler<TResult, TProgress> AsyncOperationProgressHandler(THandler handler)
{
	return make<impl_AsyncOperationProgressHandler<TResult, TProgress, THandler>>(handler);
}

template <typename TResult, typename TProgress, typename THandler>
struct impl_AsyncOperationWithProgressCompletedHandler : ImplementsDefault<IAsyncOperationWithProgressCompletedHandler<TResult, TProgress>>
{
	impl_AsyncOperationWithProgressCompletedHandler(THandler handler) : m_handler(handler) {}
	THandler m_handler;

	virtual HRESULT __stdcall abi_Invoke(AbiArgIn<IAsyncOperationWithProgress<TResult, TProgress>> sender, AsyncStatus args) noexcept override
	{
		return call([&]
		{
			m_handler(forward<IAsyncOperationWithProgress<TResult, TProgress>>(sender), args);
		});
	}
};

template <typename TResult, typename TProgress, typename THandler>
IAsyncOperationWithProgressCompletedHandler<TResult, TProgress> AsyncOperationWithProgressCompletedHandler(THandler handler)
{
	return make<impl_AsyncOperationWithProgressCompletedHandler<TResult, TProgress, THandler>>(handler);
}

template <typename TResult, typename THandler>
struct impl_AsyncOperationCompletedHandler : ImplementsDefault<IAsyncOperationCompletedHandler<TResult>>
{
	impl_AsyncOperationCompletedHandler(THandler handler) : m_handler(handler) {}
	THandler m_handler;

	virtual HRESULT __stdcall abi_Invoke(AbiArgIn<IAsyncOperation<TResult>> sender, AsyncStatus args) noexcept override
	{
		return call([&]
		{
			m_handler(forward<IAsyncOperation<TResult>>(sender), args);
		});
	}
};

template <typename TResult, typename THandler>
IAsyncOperationCompletedHandler<TResult> AsyncOperationCompletedHandler(THandler handler)
{
	return make<impl_AsyncOperationCompletedHandler<TResult, THandler>>(handler);
}

template <typename TArgs, typename THandler>
struct impl_EventHandler : ImplementsDefault<IEventHandler<TArgs>>
{
	impl_EventHandler(THandler handler) : m_handler(handler) {}
	THandler m_handler;

	virtual HRESULT __stdcall abi_Invoke(AbiArgIn<IInspectable> sender, AbiArgIn<TArgs> args) noexcept override
	{
		return call([&]
		{
			m_handler(forward<IInspectable>(sender), forward<TArgs>(args));
		});
	}
};

template <typename TArgs, typename THandler>
IEventHandler<TArgs> EventHandler(THandler handler)
{
	return make<impl_EventHandler<TArgs, THandler>>(handler);
}

template <typename TSender, typename TArgs, typename THandler>
struct impl_TypedEventHandler : ImplementsDefault<Windows::Foundation::ITypedEventHandler<TSender, TArgs>>
{
	impl_TypedEventHandler(THandler handler) : m_handler(handler) {}
	THandler m_handler;

	virtual HRESULT __stdcall abi_Invoke(AbiArgIn<TSender> sender, AbiArgIn<TArgs> args) noexcept override
	{
		return call([&]
		{
			m_handler(forward<TSender>(sender), forward<TArgs>(args));
		});
	}
};

template <typename TSender, typename TArgs, typename THandler>
ITypedEventHandler<TSender, TArgs> TypedEventHandler(THandler handler)
{
	return make<impl_TypedEventHandler<TSender, TArgs, THandler>>(handler);
}

}}}
