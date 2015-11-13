
namespace Modern {

enum class AsyncStatus
{
  Started = 0,
  Completed, 
  Canceled, 
  Error,
};

enum class InitializeType
{
	SingleThreaded,
	MultiThreaded
};

struct IInspectable;
class IAsyncInfo;
class IActivationFactory;

template <typename T>
struct impl_IAsyncInfo;

template <typename T>
struct impl_IActivationFactory;

template <typename T>
struct IInspectableT
{
};

}

namespace Modern { namespace ABI {

struct __declspec(uuid("00000036-0000-0000-C000-000000000046")) __declspec(novtable) IAsyncInfo : ::IInspectable
{
    virtual HRESULT __stdcall get_Id(unsigned int * id) = 0;
    virtual HRESULT __stdcall get_Status(AsyncStatus * status) = 0;
    virtual HRESULT __stdcall get_ErrorCode(HRESULT * errorCode) = 0;
    virtual HRESULT __stdcall abi_Cancel() = 0;
    virtual HRESULT __stdcall abi_Close() = 0;
};

struct __declspec(uuid("00000035-0000-0000-C000-000000000046")) __declspec(novtable) IActivationFactory : ::IInspectable
{
    virtual HRESULT __stdcall abi_ActivateInstance(::IInspectable ** instance) = 0;
};

}}

namespace Modern { namespace Internal {

template <typename T>
struct Implementation
{
};

template <> struct Implementation<String>
{
	using AbiType = HSTRING;
};

template <> struct Implementation<IInspectable>
{
	using AbiType = ::IInspectable;
    template <typename T> using Overrides = IInspectableT<T>;
};

template <> struct Implementation<IAsyncInfo>
{
	using AbiType = ABI::IAsyncInfo;
	template <typename T> using Methods = impl_IAsyncInfo<T>;
};

template <> struct Implementation<IActivationFactory>
{
	using AbiType = ABI::IActivationFactory;
	template <typename T> using Methods = impl_IActivationFactory<T>;
};

template <typename T>
class IsComposable
{
    template <typename U> static std::true_type Check(decltype(std::is_void<U::Composable>::value));
    template <typename>   static std::false_type Check(...);

public:

    static constexpr bool Value = decltype(Check<T>(0))::value;
};

}}

namespace Modern {

struct IInspectable : IUnknown
{
	MODERN_INTERFACE(IInspectable)

	String GetRuntimeClassName() const
	{
		String name;
		Check((*this)->GetRuntimeClassName(Set(name)));
		return name;
	}
};

template <typename T>
struct impl_IAsyncInfo
{
	unsigned Id() const
	{
		unsigned id;
		Check((*static_cast<T const *>(this))->get_Id(&id));
		return id;
	}

	AsyncStatus Status() const
	{
		AsyncStatus status;
		Check((*static_cast<T const *>(this))->get_Status(&status));
		return status;
	}

	HRESULT ErrorCode() const
	{
		HRESULT code;
		Check((*static_cast<T const *>(this))->get_ErrorCode(&code));
		return code;
	}

	void Cancel() const
	{
		Check((*static_cast<T const *>(this))->abi_Cancel());
	}

	void Close() const
	{
		Check((*static_cast<T const *>(this))->abi_Close());
	}
};

class IAsyncInfo :
	public IInspectable,
	public impl_IAsyncInfo<IAsyncInfo>
{
public:
	MODERN_INTERFACE(IAsyncInfo)
};

template <typename T>
struct impl_IActivationFactory
{
	IInspectable ActivateInstance() const
	{
		IInspectable instance;
		Check((*static_cast<T const *>(this))->abi_ActivateInstance(instance.SetAbi()));
		return instance;
	}
};

class IActivationFactory :
	public IInspectable,
	public impl_IActivationFactory<IActivationFactory>
{
public:
	MODERN_INTERFACE(IActivationFactory)
};

template <typename T>
class EventHandlerArray
{
	Lock m_writeLock;
	std::shared_ptr<std::set<T>> m_handlers;

public:

	using Type = T;

	EventHandlerArray(EventHandlerArray const &) = delete;
	EventHandlerArray & operator=(EventHandlerArray const &) = delete;

	EventHandlerArray() = default;

	EventRegistrationToken Add(T const & handler)
	{
		LockGuard guard(m_writeLock);

		std::shared_ptr<std::set<T>> handlers = std::make_shared<std::set<T>>();

		if (std::set<T> * set = m_handlers.get())
		{
			handlers->insert(set->begin(), set->end());
		}

		handlers->insert(handler);

		m_handlers = std::move(handlers);

		return EventRegistrationToken { reinterpret_cast<long long>(Abi(handler)) };
	}

	void Remove(EventRegistrationToken const token)
	{
		LockGuard guard(m_writeLock);

		std::shared_ptr<std::set<T>> handlers = std::make_shared<std::set<T>>();

		if (std::set<T> * set = m_handlers.get())
		{
			handlers->insert(set->begin(), set->end());
		}

		handlers->erase(reinterpret_cast<T const &>(token.value));

		m_handlers = std::move(handlers);
	}

	template <typename F>
	void ForEach(F call) const
	{
		std::shared_ptr<std::set<T>> handlers = m_handlers;

		if (std::set<T> * set = handlers.get())
		{
			for (T const & handler : *set)
			{
				call(handler);
			}
		}
	}
};

inline void Initialize(InitializeType const type = InitializeType::MultiThreaded)
{
	Check(RoInitialize(static_cast<RO_INIT_TYPE>(type)));
}

template <typename Class, typename Interface = IActivationFactory>
Interface GetActivationFactory()
{
	StringReference classId(Internal::Abi<Class>::Type::Name(),
							Internal::Abi<Class>::Type::NameLength);

	Interface factory;

	Check(RoGetActivationFactory(Abi(classId), __uuidof(Interface::AbiType), reinterpret_cast<void **>(Abi(&factory))));

	return factory;
}

template <typename Class, typename Interface = Internal::Implementation<Class>::Default>
Interface ActivateInstance()
{
	StringReference classId(Internal::Abi<Class>::Type::Name(),
                            Internal::Abi<Class>::Type::NameLength);

	IInspectable instance;

	Check(RoActivateInstance(Abi(classId), Abi(&instance)));

	return instance.As<Interface>();
}

template <typename T, typename ... Args, typename std::enable_if<!Internal::IsComposable<T>::Value>::type * = nullptr>
auto Make(Args && ... args)
{
	T::DefaultInterface temp;
	temp.AttachAbi(new T(std::forward<Args>(args) ...));
	return temp;
}

template <typename T, typename ... Args, typename std::enable_if<Internal::IsComposable<T>::Value>::type * = nullptr>
auto Make(Args && ... args)
{
    Modern::IInspectable temp;
    temp.AttachAbi(new T(std::forward<Args>(args) ...));
    return temp.As<T::Composable>();
}

}

namespace Modern { namespace Internal {

template <typename T>
HRESULT Call(T && call) noexcept
{
	try
	{
		call();
	}
	catch (Exception const & e)
	{
		return e.Result;
	}
	catch (std::bad_alloc const &)
	{
		return E_OUTOFMEMORY;
	}
	catch (std::exception const &)
	{
		return E_FAIL;
	}

	return S_OK;
}

}}
