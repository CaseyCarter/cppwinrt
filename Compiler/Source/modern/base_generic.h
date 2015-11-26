
namespace winrt { namespace impl {

template <typename T, typename Enable = void>
struct argument
{
	static constexpr T empty() noexcept
	{
		return{};
	}
};

template <typename T>
struct argument<T, typename std::enable_if<std::is_base_of<Windows::IUnknown, T>::value>::type>
{
	static constexpr T empty() noexcept
	{
		return nullptr;
	}
};

}}

namespace winrt { namespace ABI { namespace Windows { namespace Foundation {

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
	virtual HRESULT __stdcall abi_Invoke(IAsyncActionWithProgress<TProgress> * asyncInfo, argument_in<TProgress> progressInfo) = 0;
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
	virtual HRESULT __stdcall abi_Invoke(IAsyncOperationWithProgress<TResult, TProgress> * asyncInfo, argument_in<TProgress> progressInfo) = 0;
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
	virtual HRESULT __stdcall abi_Invoke(IInspectable * sender, argument_in<T> args) = 0;
};

template <typename TSender, typename TArgs>
struct __declspec(novtable) impl_ITypedEventHandler : IUnknown
{
	virtual HRESULT __stdcall abi_Invoke(argument_in<TSender> sender, argument_in<TArgs> args) = 0;
};

template <typename TResult>
struct __declspec(novtable) impl_IAsyncOperation : IInspectable
{
	virtual HRESULT __stdcall put_Completed(IAsyncOperationCompletedHandler<TResult> * handler) = 0;
	virtual HRESULT __stdcall get_Completed(IAsyncOperationCompletedHandler<TResult> ** handler) = 0;
	virtual HRESULT __stdcall abi_GetResults(argument_out<TResult> results) = 0;
};

template <typename TResult, typename TProgress>
struct __declspec(novtable) impl_IAsyncOperationWithProgress : IInspectable
{
	virtual HRESULT __stdcall put_Progress(IAsyncOperationProgressHandler<TResult, TProgress> * handler) = 0;
	virtual HRESULT __stdcall get_Progress(IAsyncOperationProgressHandler<TResult, TProgress> ** handler) = 0;
	virtual HRESULT __stdcall put_Completed(IAsyncOperationWithProgressCompletedHandler<TResult, TProgress> * handler) = 0;
	virtual HRESULT __stdcall get_Completed(IAsyncOperationWithProgressCompletedHandler<TResult, TProgress> ** handler) = 0;
	virtual HRESULT __stdcall abi_GetResults(argument_out<TResult> results) = 0;
};

template <typename T>
struct __declspec(novtable) impl_IReference : IInspectable
{
	virtual HRESULT __stdcall get_Value(argument_out<T> value) = 0;
};

}}}}

namespace winrt { namespace Windows { namespace Foundation {

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
class impl_IAsyncActionProgressHandler
{
	auto shim() const { return impl::shim<D, IAsyncActionProgressHandler<TProgress>>(this); }

public:

	void Invoke(IAsyncActionWithProgress<TProgress> const & sender, TProgress const & args) const
	{
		check(shim()->abi_Invoke(get(sender), abi(args)));
	}
};

template <typename D, typename TProgress>
class impl_IAsyncActionWithProgress
{
	auto shim() const { return impl::shim<D, IAsyncActionWithProgress<TProgress>>(this); }

public:

	void Progress(IAsyncActionProgressHandler<TProgress> const & handler) const
	{
		check(shim()->put_Progress(get(handler)));
	}

	template <typename Handler>
	void Progress(Handler handler) const
	{
		return Progress(AsyncActionProgressHandler<TProgress>(handler));
	}

	IAsyncActionProgressHandler<TProgress> Progress() const
	{
		IAsyncActionProgressHandler<TProgress> handler;
		check(shim()->get_Progress(put(handler)));
		return handler;
	}

	void Completed(IAsyncActionWithProgressCompletedHandler<TProgress> const & handler) const
	{
		check(shim()->put_Completed(get(handler)));
	}

	template <typename Handler>
	void Completed(Handler handler) const
	{
		return Completed(AsyncActionWithProgressCompletedHandler<TProgress>(handler));
	}

	IAsyncActionWithProgressCompletedHandler<TProgress> Completed() const
	{
		IAsyncActionWithProgressCompletedHandler<TProgress> handler;
		check(shim()->get_Completed(put(handler)));
		return handler;
	}

	void GetResults() const
	{
		check(shim()->abi_GetResults());
	}
};

template <typename D, typename TProgress>
class impl_IAsyncActionWithProgressCompletedHandler
{
	auto shim() const { return impl::shim<D, IAsyncActionWithProgressCompletedHandler<TProgress>>(this); }

public:

	void Invoke(IAsyncActionWithProgress<TProgress> const & sender, AsyncStatus const args) const
	{
		check(shim()->abi_Invoke(get(sender), args));
	}
};

template <typename D, typename TResult, typename TProgress>
class impl_IAsyncOperationProgressHandler
{
	auto shim() const { return impl::shim<D, IAsyncOperationProgressHandler<TResult, TProgress>>(this); }

public:

	void Invoke(IAsyncOperationWithProgress<TResult, TProgress> const & sender, TProgress const & args) const
	{
		check(shim()->abi_Invoke(get(sender), abi(args)));
	}
};

template <typename D, typename TResult, typename TProgress>
class impl_IAsyncOperationWithProgressCompletedHandler
{
	auto shim() const { return impl::shim<D, IAsyncOperationWithProgressCompletedHandler<TResult, TProgress>>(this); }

public:

	void Invoke(IAsyncOperationWithProgress<TResult, TProgress> const & sender, AsyncStatus const args) const
	{
		check(shim()->abi_Invoke(get(sender), args));
	}
};

template <typename D, typename TResult>
class impl_IAsyncOperationCompletedHandler
{
	auto shim() const { return impl::shim<D, IAsyncOperationCompletedHandler<TResult>>(this); }

public:

	void Invoke(IAsyncOperation<TResult> const & sender, AsyncStatus const args) const
	{
		check(shim()->abi_Invoke(get(sender), args));
	}
};

template <typename D, typename T>
class impl_IEventHandler
{
	auto shim() const { return impl::shim<D, IEventHandler<T>>(this); }

public:

	void Invoke(IInspectable const & sender, T const & args) const
	{
		check(shim()->abi_Invoke(get(sender), abi(args)));
	}
};

template <typename D, typename TSender, typename TArgs>
class impl_ITypedEventHandler
{
	auto shim() const { return impl::shim<D, ITypedEventHandler<TSender, TArgs>>(this); }

public:

	void Invoke(TSender const & sender, TArgs const & args) const
	{
		check(shim()->abi_Invoke(abi(sender), abi(args)));
	}
};

template <typename D, typename TResult>
class impl_IAsyncOperation
{
	auto shim() const { return impl::shim<D, IAsyncOperation<TResult>>(this); }

public:

	void Completed(IAsyncOperationCompletedHandler<TResult> const & handler) const
	{
		check(shim()->put_Completed(get(handler)));
	}

	template <typename Handler>
	void Completed(Handler handler) const
	{
		return Completed(AsyncOperationCompletedHandler<TResult>(handler));
	}

	IAsyncOperationCompletedHandler<TResult> Completed() const
	{
		IAsyncOperationCompletedHandler<TResult> temp;
		check(shim()->get_Completed(put(temp)));
		return temp;
	}

	TResult GetResults() const
	{
		TResult result = impl::argument<TResult>::empty();
		check(shim()->abi_GetResults(abi(&result)));
		return result;
	}
};

template <typename D, typename TResult, typename TProgress>
class impl_IAsyncOperationWithProgress
{
	auto shim() const { return impl::shim<D, IAsyncOperationWithProgress<TResult, TProgress>>(this); }

public:

	void Progress(IAsyncOperationProgressHandler<TResult, TProgress> const & handler) const
	{
		check(shim()->put_Progress(get(handler)));
	}

	template <typename Handler>
	void Progress(Handler handler) const
	{
		return Progress(AsyncOperationProgressHandler<TResult, TProgress>(handler));
	}

	IAsyncOperationProgressHandler<TResult, TProgress> Progress() const
	{
		IAsyncOperationProgressHandler<TResult, TProgress> handler;
		check(shim()->get_Progress(put(handler)));
		return handler;
	}

	void Completed(IAsyncOperationWithProgressCompletedHandler<TResult, TProgress> const & handler) const
	{
		check(shim()->put_Completed(get(handler)));
	}

	template <typename Handler>
	void Completed(Handler handler) const
	{
		return Completed(AsyncOperationWithProgressCompletedHandler<TResult, TProgress>(handler));
	}

	IAsyncOperationWithProgressCompletedHandler<TResult, TProgress> Completed() const
	{
		IAsyncOperationWithProgressCompletedHandler<TResult, TProgress> handler;
		check(shim()->get_Completed(put(handler)));
		return handler;
	}

	TResult GetResults() const
	{
		TResult result = impl::argument<TResult>::empty();
		check(shim()->abi_GetResults(abi(&result)));
		return result;
	}
};

template <typename D, typename T>
class impl_IReference
{
	auto shim() const { return impl::shim<D, IReference<T>>(this); }

public:

	T Value() const
	{
		T result = impl::argument<T>::empty();
		check(shim()->get_Value(put(result)));
		return result;
	}
};

template <typename TProgress>
struct IAsyncActionProgressHandler :
	IUnknown,
	impl_IAsyncActionProgressHandler<IAsyncActionProgressHandler<TProgress>, TProgress>
{
	IAsyncActionProgressHandler(std::nullptr_t = nullptr) noexcept {}
	auto operator->() const noexcept { return ptr<IAsyncActionProgressHandler>(m_ptr); }
};

template <typename TProgress>
struct IAsyncActionWithProgress :
	IInspectable,
	impl_IAsyncActionWithProgress<IAsyncActionWithProgress<TProgress>, TProgress>,
	requires<IAsyncActionWithProgress<TProgress>, IAsyncInfo>
{
	IAsyncActionWithProgress(std::nullptr_t = nullptr) noexcept {}
	auto operator->() const noexcept { return ptr<IAsyncActionWithProgress>(m_ptr); }
};

template <typename TProgress>
struct IAsyncActionWithProgressCompletedHandler :
	IUnknown,
	impl_IAsyncActionWithProgressCompletedHandler<IAsyncActionWithProgressCompletedHandler<TProgress>, TProgress>
{
	IAsyncActionWithProgressCompletedHandler(std::nullptr_t = nullptr) noexcept {}
	auto operator->() const noexcept { return ptr<IAsyncActionWithProgressCompletedHandler>(m_ptr); }
};

template <typename TResult, typename TProgress>
struct IAsyncOperationProgressHandler :
	IUnknown,
	impl_IAsyncOperationProgressHandler<IAsyncOperationProgressHandler<TResult, TProgress>, TResult, TProgress>
{
	IAsyncOperationProgressHandler(std::nullptr_t = nullptr) noexcept {}
	auto operator->() const noexcept { return ptr<IAsyncOperationProgressHandler>(m_ptr); }
};

template <typename TResult, typename TProgress>
struct IAsyncOperationWithProgressCompletedHandler :
	IUnknown,
	impl_IAsyncOperationWithProgressCompletedHandler<IAsyncOperationWithProgressCompletedHandler<TResult, TProgress>, TResult, TProgress>
{
	IAsyncOperationWithProgressCompletedHandler(std::nullptr_t = nullptr) noexcept {}
	auto operator->() const noexcept { return ptr<IAsyncOperationWithProgressCompletedHandler>(m_ptr); }
};

template <typename TResult>
struct IAsyncOperationCompletedHandler :
	IUnknown,
	impl_IAsyncOperationCompletedHandler<IAsyncOperationCompletedHandler<TResult>, TResult>
{
	IAsyncOperationCompletedHandler(std::nullptr_t = nullptr) noexcept {}
	auto operator->() const noexcept { return ptr<IAsyncOperationCompletedHandler>(m_ptr); }
};

template <typename T>
struct IEventHandler :
	IUnknown,
	impl_IEventHandler<IEventHandler<T>, T>
{
	IEventHandler(std::nullptr_t = nullptr) noexcept {}
	auto operator->() const noexcept { return ptr<IEventHandler>(m_ptr); }
};

template <typename TSender, typename TArgs>
struct ITypedEventHandler :
	IUnknown,
	impl_ITypedEventHandler<ITypedEventHandler<TSender, TArgs>, TSender, TArgs>
{
	ITypedEventHandler(std::nullptr_t = nullptr) noexcept {}
	auto operator->() const noexcept { return ptr<ITypedEventHandler>(m_ptr); }
};

template <typename TResult>
struct IAsyncOperation :
	IInspectable,
	impl_IAsyncOperation<IAsyncOperation<TResult>, TResult>,
	requires<IAsyncOperation<TResult>, IAsyncInfo>
{
	IAsyncOperation(std::nullptr_t = nullptr) noexcept {}
	auto operator->() const noexcept { return ptr<IAsyncOperation>(m_ptr); }
};

template <typename TResult, typename TProgress>
struct IAsyncOperationWithProgress :
	IInspectable,
	impl_IAsyncOperationWithProgress<IAsyncOperationWithProgress<TResult, TProgress>, TResult, TProgress>,
	requires<IAsyncOperationWithProgress<TResult, TProgress>, IAsyncInfo>
{
	IAsyncOperationWithProgress(std::nullptr_t = nullptr) noexcept {}
	auto operator->() const noexcept { return ptr<IAsyncOperationWithProgress>(m_ptr); }
};

struct IPropertyValue;

template <typename T>
struct IReference :
	IInspectable,
	impl_IReference<IReference<T>, T> //,
	// requires<IReference<T>, IPropertyValue>
{
	IReference(std::nullptr_t = nullptr) noexcept {}
	auto operator->() const noexcept { return ptr<IReference>(m_ptr); }

	IReference(T const & value);
};

}}}

namespace winrt { namespace impl {

template <typename TProgress> struct traits<Windows::Foundation::IAsyncActionProgressHandler<TProgress>>
{
	using abi = ABI::Windows::Foundation::IAsyncActionProgressHandler<abi<TProgress>>;
	template <typename D> using methods = Windows::Foundation::impl_IAsyncActionProgressHandler<D, TProgress>;
};

template <typename TProgress> struct traits<Windows::Foundation::IAsyncActionWithProgress<TProgress>>
{
	using abi = ABI::Windows::Foundation::IAsyncActionWithProgress<abi<TProgress>>;
	template <typename D> using methods = Windows::Foundation::impl_IAsyncActionWithProgress<D, TProgress>;
};

template <typename TProgress> struct traits<Windows::Foundation::IAsyncActionWithProgressCompletedHandler<TProgress>>
{
	using abi = ABI::Windows::Foundation::IAsyncActionWithProgressCompletedHandler<abi<TProgress>>;
	template <typename D> using methods = Windows::Foundation::impl_IAsyncActionWithProgressCompletedHandler<D, TProgress>;
};

template <typename TResult, typename TProgress> struct traits<Windows::Foundation::IAsyncOperationProgressHandler<TResult, TProgress>>
{
	using abi = ABI::Windows::Foundation::IAsyncOperationProgressHandler<abi<TResult>, abi<TProgress>>;
	template <typename D> using methods = Windows::Foundation::impl_IAsyncOperationProgressHandler<D, TResult, TProgress>;
};

template <typename TResult, typename TProgress> struct traits<Windows::Foundation::IAsyncOperationWithProgressCompletedHandler<TResult, TProgress>>
{
	using abi = ABI::Windows::Foundation::IAsyncOperationWithProgressCompletedHandler<abi<TResult>, abi<TProgress>>;
	template <typename D> using methods = Windows::Foundation::impl_IAsyncOperationWithProgressCompletedHandler<D, TResult, TProgress>;
};

template <typename TResult> struct traits<Windows::Foundation::IAsyncOperationCompletedHandler<TResult>>
{
	using abi = ABI::Windows::Foundation::IAsyncOperationCompletedHandler<abi<TResult>>;
	template <typename D> using methods = Windows::Foundation::impl_IAsyncOperationCompletedHandler<D, TResult>;
};

template <typename T> struct traits<Windows::Foundation::IEventHandler<T>>
{
	using abi = ABI::Windows::Foundation::IEventHandler<abi<T>>;
	template <typename D> using methods = Windows::Foundation::impl_IEventHandler<D, T>;
};

template <typename TSender, typename TArgs> struct traits<Windows::Foundation::ITypedEventHandler<TSender, TArgs>>
{
	using abi = ABI::Windows::Foundation::ITypedEventHandler<abi<TSender>, abi<TArgs>>;
	template <typename D> using methods = Windows::Foundation::impl_ITypedEventHandler<D, TSender, TArgs>;
};

template <typename TResult> struct traits<Windows::Foundation::IAsyncOperation<TResult>>
{
	using abi = ABI::Windows::Foundation::IAsyncOperation<abi<TResult>>;
	template <typename D> using methods = Windows::Foundation::impl_IAsyncOperation<D, TResult>;
};

template <typename TResult, typename TProgress> struct traits<Windows::Foundation::IAsyncOperationWithProgress<TResult, TProgress>>
{
	using abi = ABI::Windows::Foundation::IAsyncOperationWithProgress<abi<TResult>, abi<TProgress>>;
	template <typename D> using methods = Windows::Foundation::impl_IAsyncOperationWithProgress<D, TResult, TProgress>;
};

template <typename T> struct traits<Windows::Foundation::IReference<T>>
{
	using abi = ABI::Windows::Foundation::IReference<abi<T>>;
	template <typename D> using methods = Windows::Foundation::impl_IReference<D, T>;
};

}}

namespace winrt { namespace Windows { namespace Foundation {

template <typename TProgress, typename THandler>
class impl_AsyncActionProgressHandler : impl::implements<IAsyncActionProgressHandler<TProgress>>
{
	impl_AsyncActionProgressHandler(THandler handler) : m_handler(handler) {}
	THandler m_handler;

	virtual HRESULT __stdcall abi_Invoke(ABI::argument_in<IAsyncActionWithProgress<TProgress>> sender, ABI::argument_in<TProgress> args) noexcept override
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
class impl_AsyncActionWithProgressCompletedHandler : impl::implements<IAsyncActionWithProgressCompletedHandler<TProgress>>
{
	impl_AsyncActionWithProgressCompletedHandler(THandler handler) : m_handler(handler) {}
	THandler m_handler;

	virtual HRESULT __stdcall abi_Invoke(ABI::argument_in<IAsyncActionWithProgress<TProgress>> sender, AsyncStatus args) noexcept override
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
class impl_AsyncOperationProgressHandler : impl::implements<IAsyncOperationProgressHandler<TResult, TProgress>>
{
	impl_AsyncOperationProgressHandler(THandler handler) : m_handler(handler) {}
	THandler m_handler;

	virtual HRESULT __stdcall abi_Invoke(ABI::argument_in<IAsyncOperationWithProgress<TResult, TProgress>> sender, ABI::argument_in<TProgress> args) noexcept override
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
class impl_AsyncOperationWithProgressCompletedHandler : impl::implements<IAsyncOperationWithProgressCompletedHandler<TResult, TProgress>>
{
	impl_AsyncOperationWithProgressCompletedHandler(THandler handler) : m_handler(handler) {}
	THandler m_handler;

	virtual HRESULT __stdcall abi_Invoke(ABI::argument_in<IAsyncOperationWithProgress<TResult, TProgress>> sender, AsyncStatus args) noexcept override
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
class impl_AsyncOperationCompletedHandler : impl::implements<IAsyncOperationCompletedHandler<TResult>>
{
	impl_AsyncOperationCompletedHandler(THandler handler) : m_handler(handler) {}
	THandler m_handler;

	virtual HRESULT __stdcall abi_Invoke(ABI::argument_in<IAsyncOperation<TResult>> sender, AsyncStatus args) noexcept override
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
class impl_EventHandler : impl::implements<IEventHandler<TArgs>>
{
	impl_EventHandler(THandler handler) : m_handler(handler) {}
	THandler m_handler;

	virtual HRESULT __stdcall abi_Invoke(ABI::argument_in<IInspectable> sender, ABI::argument_in<TArgs> args) noexcept override
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
class impl_TypedEventHandler : impl::implements<Windows::Foundation::ITypedEventHandler<TSender, TArgs>>
{
	impl_TypedEventHandler(THandler handler) : m_handler(handler) {}
	THandler m_handler;

	virtual HRESULT __stdcall abi_Invoke(ABI::argument_in<TSender> sender, ABI::argument_in<TArgs> args) noexcept override
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
