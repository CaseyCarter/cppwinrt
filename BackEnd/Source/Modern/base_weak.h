
namespace ABI::Windows {

struct __declspec(uuid("00000037-0000-0000-C000-000000000046")) __declspec(novtable) IWeakReference : IUnknown
{
    virtual HRESULT __stdcall abi_Resolve(const GUID & iid, IInspectable ** objectReference) = 0;

    template <typename Qi> HRESULT __stdcall abi_Resolve(Qi ** objectReference) noexcept
    {
        return abi_Resolve(__uuidof(Qi), reinterpret_cast<IInspectable **>(objectReference));
    }
};

struct __declspec(uuid("00000038-0000-0000-C000-000000000046")) __declspec(novtable) IWeakReferenceSource : IUnknown
{
    virtual HRESULT __stdcall abi_GetWeakReference(IWeakReference ** weakReference) = 0;
};

}

template <typename T>
struct weak_ref
{
    weak_ref(std::nullptr_t = nullptr) noexcept {}

    weak_ref(const T & object)
    {
        check_hresult(object.template as<ABI::Windows::IWeakReferenceSource>()->abi_GetWeakReference(put(m_ref)));
    }

    T get() const noexcept
    {
        T object = nullptr;
        m_ref->abi_Resolve(put(object));
        return object;
    }

    explicit operator bool() const noexcept
    {
        return static_cast<bool>(m_ref);
    }

private:

    com_ptr<ABI::Windows::IWeakReference> m_ref;
};

template <typename T>
weak_ref<T> make_weak(T const & object)
{
    return object;
}
