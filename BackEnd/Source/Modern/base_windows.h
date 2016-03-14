
namespace winrt { namespace Windows {

struct IUnknown
{
	IUnknown() noexcept = default;
	IUnknown(std::nullptr_t) noexcept {}
	void * operator new(size_t) = delete;

	IUnknown(IUnknown const & other) noexcept :
		m_ptr(other.m_ptr)
	{
		impl_addref();
	}

	IUnknown(IUnknown && other) noexcept :
		m_ptr(other.m_ptr)
	{
		other.m_ptr = nullptr;
	}

	~IUnknown() noexcept
	{
		impl_release();
	}

	IUnknown & operator=(IUnknown const & other) noexcept
	{
		impl_copy(other);
		return *this;
	}

	IUnknown & operator=(IUnknown && other) noexcept
	{
		impl_move(std::forward<IUnknown>(other));
		return *this;
	}

	explicit operator bool() const noexcept
	{
		return nullptr != m_ptr;
	}

	impl::no_ref<::IUnknown> * operator->() const noexcept
	{
		return static_cast<impl::no_ref<::IUnknown> *>(m_ptr);
	}

	IUnknown & operator=(std::nullptr_t) noexcept
	{
		impl_release();
		return *this;
	}

	template <typename T>
	T As() const
	{
		T temp = nullptr;
		check_hresult(m_ptr->QueryInterface(put(temp)));
		return temp;
	}

	friend ::IUnknown * impl_get(IUnknown const & object) noexcept
	{
		return object.m_ptr;
	}

	friend ::IUnknown ** impl_put(IUnknown & object) noexcept
	{
		WINRT_ASSERT(!object);
		return &object.m_ptr;
	}

	friend ::IUnknown * impl_detach(IUnknown & object) noexcept
	{
		::IUnknown * temp = object.m_ptr;
		object.m_ptr = nullptr;
		return temp;
	}

	friend void swap(IUnknown & left, IUnknown & right) noexcept
	{
		std::swap(left.m_ptr, right.m_ptr);
	}

protected:

	void impl_copy(::IUnknown * other) noexcept
	{
		if (m_ptr != other)
		{
			impl_release();
			m_ptr = other;
			impl_addref();
		}
	}

	void impl_copy(IUnknown const & other) noexcept
	{
		if (this != &other)
		{
			impl_release();
			m_ptr = other.m_ptr;
			impl_addref();
		}
	}

	void impl_move(IUnknown && other) noexcept
	{
		if (this != &other)
		{
			impl_release();
			m_ptr = other.m_ptr;
			other.m_ptr = nullptr;
		}
	}

	::IUnknown * m_ptr = nullptr;
	
private:

	void impl_addref() const noexcept
	{
		if (m_ptr)
		{
			m_ptr->AddRef();
		}
	}

	void impl_release() noexcept
	{
		::IUnknown * temp = m_ptr;

		if (temp)
		{
			m_ptr = nullptr;
			temp->Release();
		}
	}
};

}}

namespace winrt { namespace impl {

template <> struct traits<Windows::IUnknown>
{
	using abi = ::IUnknown;
};

template <typename T>
struct accessors<T, typename std::enable_if<std::is_base_of<Windows::IUnknown, T>::value>::type>
{
	static auto get(T const & object) noexcept
	{
		return static_cast<abi_arg_in<T>>(impl_get(object));
	}

	static auto put(T & object) noexcept
	{
		return reinterpret_cast<abi_arg_out<T>>(impl_put(object));
	}

	static void attach(T & object, abi_arg_in<T> value) noexcept
	{
		object = nullptr;
		*put(object) = value;
	}

	static void copy_from(T & object, abi_arg_in<T> value) noexcept
	{
		object = nullptr;

		if (value)
		{
			value->AddRef();
			*put(object) = value;
		}
	}

	static void copy_to(T const & object, abi_arg_in<T> & value) noexcept
	{
		if (object)
		{
			value = get(object);
			value->AddRef();
		}
		else
		{
			value = nullptr;
		}
	}

	static auto detach(T & object) noexcept
	{
		return static_cast<abi_arg_in<T>>(impl_detach(object));
	}
};

}}

namespace winrt { namespace Windows {

inline bool operator==(IUnknown const & left, IUnknown const & right) noexcept
{
	return get(left) == get(right);
}

inline bool operator!=(IUnknown const & left, IUnknown const & right) noexcept
{
	return !(left == right);
}

inline bool operator<(IUnknown const & left, IUnknown const & right) noexcept
{
	return get(left) < get(right);
}

inline bool operator>(IUnknown const & left, IUnknown const & right) noexcept
{
	return right < left;
}

inline bool operator<=(IUnknown const & left, IUnknown const & right) noexcept
{
	return !(right < left);
}

inline bool operator>=(IUnknown const & left, IUnknown const & right) noexcept
{
	return !(left < right);
}

}}

namespace winrt {

enum class AsyncStatus
{
	Started,
	Completed,
	Canceled,
	Error,
};

}

namespace winrt { namespace ABI { namespace Windows {

struct __declspec(uuid("00000036-0000-0000-c000-000000000046")) __declspec(novtable) IAsyncInfo : ::IInspectable
{
	virtual HRESULT __stdcall get_Id(unsigned * id) = 0;
	virtual HRESULT __stdcall get_Status(AsyncStatus * status) = 0;
	virtual HRESULT __stdcall get_ErrorCode(HRESULT * errorCode) = 0;
	virtual HRESULT __stdcall abi_Cancel() = 0;
	virtual HRESULT __stdcall abi_Close() = 0;
};

struct __declspec(uuid("00000035-0000-0000-c000-000000000046")) __declspec(novtable) IActivationFactory : ::IInspectable
{
	virtual HRESULT __stdcall abi_ActivateInstance(::IInspectable ** instance) = 0;
};

}}}

namespace winrt { namespace Windows {

struct IInspectable;
struct IAsyncInfo;
struct IActivationFactory;

template <typename T>
class impl_IInspectable
{
	auto shim() const { return impl::shim<T, IInspectable>(this); }

public:

	String GetRuntimeClassName() const;
};

template <typename T>
class impl_IAsyncInfo
{
	auto shim() const { return impl::shim<T, IAsyncInfo>(this); }

public:

	unsigned Id() const;
	AsyncStatus Status() const;
	HRESULT ErrorCode() const;
	void Cancel() const;
	void Close() const;
};

template <typename T>
class impl_IActivationFactory
{
	auto shim() const { return impl::shim<T, IActivationFactory>(this); }

public:

	IInspectable ActivateInstance() const;
};

}}

namespace winrt { namespace impl {

template <> struct traits<Windows::IInspectable>
{
	using abi = ::IInspectable;
	template <typename T> using methods = Windows::impl_IInspectable<T>;
};

template <> struct traits<Windows::IAsyncInfo>
{
	using abi = ABI::Windows::IAsyncInfo;
	template <typename T> using methods = Windows::impl_IAsyncInfo<T>;
};

template <> struct traits<Windows::IActivationFactory>
{
	using abi = ABI::Windows::IActivationFactory;
	template <typename T> using methods = Windows::impl_IActivationFactory<T>;
};

}}

namespace winrt { namespace Windows {

struct IInspectable :
	IUnknown,
	impl_IInspectable<IInspectable>
{
	IInspectable(std::nullptr_t = nullptr) noexcept {}
	auto operator->() const noexcept { return ptr<IInspectable>(m_ptr); }
};

struct IAsyncInfo :
	IUnknown,
	impl_IAsyncInfo<IAsyncInfo>
{
	IAsyncInfo(std::nullptr_t = nullptr) noexcept {}
	auto operator->() const noexcept { return ptr<IAsyncInfo>(m_ptr); }
};

struct IActivationFactory :
	IUnknown,
	impl_IActivationFactory<IActivationFactory>
{
	IActivationFactory(std::nullptr_t = nullptr) noexcept {}
	auto operator->() const noexcept { return ptr<IActivationFactory>(m_ptr); }
};

template <typename T> String impl_IInspectable<T>::GetRuntimeClassName() const
{
	String name;
	check_hresult(shim()->get_RuntimeClassName(put(name)));
	return name;
}

template <typename T> unsigned impl_IAsyncInfo<T>::Id() const
{
	unsigned id = 0;
	check_hresult(shim()->get_Id(&id));
	return id;
}

template <typename T> AsyncStatus impl_IAsyncInfo<T>::Status() const
{
	AsyncStatus status = {};
	check_hresult(shim()->get_Status(&status));
	return status;
}

template <typename T> HRESULT impl_IAsyncInfo<T>::ErrorCode() const
{
	HRESULT code = S_OK;
	check_hresult(shim()->get_ErrorCode(&code));
	return code;
}

template <typename T> void impl_IAsyncInfo<T>::Cancel() const
{
	check_hresult(shim()->abi_Cancel());
}

template <typename T> void impl_IAsyncInfo<T>::Close() const
{
	check_hresult(shim()->abi_Close());
}

template <typename T> IInspectable impl_IActivationFactory<T>::ActivateInstance() const
{
	IInspectable instance;
	check_hresult(shim()->abi_ActivateInstance(put(instance)));
	return instance;
}

}}

namespace winrt {

template <typename ... R>
struct overrides : implements<R ...>
{
	template <typename T>
	T As() const
	{
		return m_inner.As<T>();
	}

	virtual HRESULT __stdcall QueryInterface(GUID const & id, void ** object) noexcept override
	{
		*object = query_interface<R ...>(id);

		if (*object == nullptr)
		{
			return m_inner->QueryInterface(id, object);
		}

		static_cast<::IUnknown *>(*object)->AddRef();
		return S_OK;
	}

protected:

	Windows::IInspectable m_inner;
};

}
