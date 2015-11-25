
namespace winrt { namespace Windows {

enum class AsyncStatus
{
	Started,
	Completed,
	Canceled,
	Error,
};

enum class TrustLevel
{
	BaseTrust,
	PartialTrust,
	FullTrust
};

}}

namespace winrt { namespace ABI { namespace Windows {

struct __declspec(uuid("af86e2e0-b12d-4c6a-9c5a-d7aa65101e90")) __declspec(novtable) IInspectable : ::IUnknown
{
	virtual HRESULT __stdcall get_Iids(unsigned * count, GUID ** iids) = 0;
	virtual HRESULT __stdcall get_RuntimeClassName(HSTRING * className) = 0;
	virtual HRESULT __stdcall get_TrustLevel(winrt::Windows::TrustLevel * trustLevel) = 0;

	};

struct __declspec(uuid("00000036-0000-0000-c000-000000000046")) __declspec(novtable) IAsyncInfo : IInspectable
{
	virtual HRESULT __stdcall get_Id(unsigned * id) = 0;
	virtual HRESULT __stdcall get_Status(winrt::Windows::AsyncStatus * status) = 0;
	virtual HRESULT __stdcall get_ErrorCode(HRESULT * errorCode) = 0;
	virtual HRESULT __stdcall abi_Cancel() = 0;
	virtual HRESULT __stdcall abi_Close() = 0;
};

struct __declspec(uuid("00000035-0000-0000-c000-000000000046")) __declspec(novtable) IActivationFactory : IInspectable
{
	virtual HRESULT __stdcall abi_ActivateInstance(IInspectable ** instance) = 0;
};

}}}

namespace winrt { namespace Windows {

struct IUnknown
{
	IUnknown() noexcept = default;
	IUnknown(std::nullptr_t) noexcept {}

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

	impl::no_addref_release<::IUnknown> * operator->() const noexcept
	{
		return static_cast<impl::no_addref_release<::IUnknown> *>(m_ptr);
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
		check(m_ptr->QueryInterface(put(temp)));
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
	static abi<default_interface<T>> * get(T const & object) noexcept
	{
		return static_cast<abi<default_interface<T>> *>(impl_get(object));
	}

	static abi<default_interface<T>> ** put(T & object) noexcept
	{
		return reinterpret_cast<abi<default_interface<T>> **>(impl_put(object));
	}

	static void attach(T & object, abi<default_interface<T>> * value) noexcept
	{
		object = nullptr;
		*put(object) = value;
	}

	static void copy(T & object, abi<default_interface<T>> * value) noexcept
	{
		object = nullptr;

		if (value)
		{
			value->AddRef();
			*put(object) = value;
		}
	}

	static abi<default_interface<T>> * detach(T & object) noexcept
	{
		return static_cast<abi<default_interface<T>> *>(impl_detach(object));
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

//
//namespace Modern {
//
//template <> struct Traits<Windows::IUnknown>
//{
//	using Abi = ::IUnknown;
//};
//
//}
//
//
//
//namespace Modern { namespace Windows {
//
//struct IInspectable;
//struct IAsyncInfo;
//struct IActivationFactory;
//
//template <typename T> struct impl_IAsyncInfo;
//
//}}
//
//namespace Modern {
//
//using IInspectable = Windows::IInspectable;
//
//}
//
//namespace Modern { namespace ABI {
//
//using IInspectable = ::IInspectable;
//
//}}
//
//namespace Modern {
//
//template <> struct Traits<Windows::IInspectable>
//{
//	using Abi = ::IInspectable;
//};
//
//template <> struct Traits<Windows::IAsyncInfo>
//{
//	using Abi = ABI::Windows::IAsyncInfo;
//	template <typename T> using Methods = Windows::impl_IAsyncInfo<T>;
//};
//
//template <> struct Traits<Windows::IActivationFactory>
//{
//	using Abi = ABI::Windows::IActivationFactory;
//};
//
//}
//
//
//namespace Modern { namespace Windows {
//
//struct IInspectable : IUnknown
//{
//	IInspectable(std::nullptr_t = nullptr) noexcept {}
//	auto operator->() const noexcept { return static_cast<AbiPtr<IInspectable>>(m_ptr); }
//
//	String GetRuntimeClassName() const
//	{
//		String name;
//		check((*this)->GetRuntimeClassName(put(name)));
//		return name;
//	}
//};
//
//template <typename T>
//struct impl_IAsyncInfo
//{
//	unsigned Id() const
//	{
//		unsigned id;
//		check(static_cast<IAsyncInfo const &>(static_cast<T const &>(*this))->get_Id(&id));
//		return id;
//	}
//
//	AsyncStatus Status() const
//	{
//		AsyncStatus status;
//		check(static_cast<IAsyncInfo const &>(static_cast<T const &>(*this))->get_Status(&status));
//		return status;
//	}
//
//	HRESULT ErrorCode() const
//	{
//		HRESULT code;
//		check(static_cast<IAsyncInfo const &>(static_cast<T const &>(*this))->get_ErrorCode(&code));
//		return code;
//	}
//
//	void Cancel() const
//	{
//		check(static_cast<IAsyncInfo const &>(static_cast<T const &>(*this))->abi_Cancel());
//	}
//
//	void Close() const
//	{
//		check(static_cast<IAsyncInfo const &>(static_cast<T const &>(*this))->abi_Close());
//	}
//};
//
//struct IAsyncInfo :
//	IInspectable,
//	impl_IAsyncInfo<IAsyncInfo>
//{
//	IAsyncInfo(std::nullptr_t = nullptr) noexcept {}
//	auto operator->() const noexcept { return static_cast<AbiPtr<IAsyncInfo>>(m_ptr); }
//};
//
//template <typename T>
//struct impl_IActivationFactory
//{
//	IInspectable ActivateInstance() const
//	{
//		IInspectable instance;
//		check(static_cast<T const &>(*this)->abi_ActivateInstance(put(instance)));
//		return instance;
//	}
//};
//
//struct IActivationFactory :
//	IInspectable,
//	impl_IActivationFactory<IActivationFactory>
//{
//	IActivationFactory(std::nullptr_t = nullptr) noexcept {}
//	auto operator->() const noexcept { return static_cast<AbiPtr<IActivationFactory>>(m_ptr); }
//};
//
//}}
//
//
