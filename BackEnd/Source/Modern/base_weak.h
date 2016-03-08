
namespace winrt { namespace ABI { namespace Windows {

struct __declspec(uuid("00000037-0000-0000-C000-000000000046")) __declspec(novtable) IWeakReference : ::IUnknown
{
	virtual HRESULT __stdcall abi_Resolve(GUID const & iid, ::IInspectable ** objectReference) = 0;

	template <typename Qi> HRESULT __stdcall abi_Resolve(Qi ** objectReference) noexcept
	{
		return abi_Resolve(__uuidof(Qi), reinterpret_cast<::IInspectable **>(objectReference));
	}
};

struct __declspec(uuid("00000038-0000-0000-C000-000000000046")) __declspec(novtable) IWeakReferenceSource : ::IUnknown
{
	virtual HRESULT __stdcall abi_GetWeakReference(IWeakReference ** weakReference) = 0;
};

}}}

namespace winrt { namespace Windows {

struct IWeakReference;
struct IWeakReferenceSource;

template <typename T>
class impl_IWeakReference
{
	auto shim() const { return impl::shim<T, IWeakReference>(this); }

public:

	template <typename Qi> Qi Resolve() const noexcept;
};

template <typename T>
class impl_IWeakReferenceSource
{
	auto shim() const { return impl::shim<T, IWeakReferenceSource>(this); }

public:

	IWeakReference GetWeakReference() const;
};

}}

namespace winrt { namespace impl {

template <> struct traits<Windows::IWeakReference>
{
	using abi = ABI::Windows::IWeakReference;
	template <typename T> using methods = Windows::impl_IWeakReference<T>;
};

template <> struct traits<Windows::IWeakReferenceSource>
{
	using abi = ABI::Windows::IWeakReferenceSource;
	template <typename T> using methods = Windows::impl_IWeakReferenceSource<T>;
};

}}

namespace winrt { namespace Windows {

struct IWeakReference :
	IUnknown,
	impl_IWeakReference<IWeakReference>
{
	IWeakReference(std::nullptr_t = nullptr) noexcept {}
	auto operator->() const noexcept { return ptr<IWeakReference>(m_ptr); }
};

struct IWeakReferenceSource :
	IUnknown,
	impl_IWeakReferenceSource<IWeakReferenceSource>
{
	IWeakReferenceSource(std::nullptr_t = nullptr) noexcept {}
	auto operator->() const noexcept { return ptr<IWeakReferenceSource>(m_ptr); }
};

template <typename T> template <typename Qi> Qi impl_IWeakReference<T>::Resolve() const noexcept
{
	Qi objectReference = nullptr;

	if (S_OK == shim()->abi_Resolve(put(objectReference)))
	{
		return objectReference;
	}

	return nullptr;
}

template <typename T> IWeakReference impl_IWeakReferenceSource<T>::GetWeakReference() const
{
	IWeakReference weakReference;
	check_hresult(shim()->abi_GetWeakReference(put(weakReference)));
	return weakReference;
}

}}

namespace winrt {

template <typename T>
struct weak
{
	weak(std::nullptr_t) {}
	weak(T const & object) : m_ref(object.As<Windows::IWeakReferenceSource>().GetWeakReference()) {}

	T resolve() const noexcept
	{
		return m_ref.Resolve<T>();
	}

private:

	Windows::IWeakReference m_ref;
};

template <typename T>
weak<T> make_weak(T const & object)
{
	return object;
}

}
