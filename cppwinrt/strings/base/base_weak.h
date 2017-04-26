
namespace impl
{
    struct __declspec(uuid("00000037-0000-0000-C000-000000000046")) __declspec(novtable) IWeakReference : ::IUnknown
    {
        virtual HRESULT __stdcall Resolve(GUID const& iid, ::IInspectable** objectReference) = 0;

        template <typename Qi> HRESULT __stdcall Resolve(Qi** objectReference) noexcept
        {
            return Resolve(__uuidof(Qi), reinterpret_cast<::IInspectable**>(objectReference));
        }
    };

    struct __declspec(uuid("00000038-0000-0000-C000-000000000046")) __declspec(novtable) IWeakReferenceSource : ::IUnknown
    {
        virtual HRESULT __stdcall GetWeakReference(IWeakReference** weakReference) = 0;
    };
}

template <typename T>
struct weak_ref
{
    weak_ref(std::nullptr_t = nullptr) noexcept {}

    weak_ref(T const& object)
    {
        check_hresult(object.template as<impl::IWeakReferenceSource>()->GetWeakReference(put_abi(m_ref)));
    }

    T get() const noexcept
    {
        T object = nullptr;
        if (m_ref)
        {
            m_ref->Resolve(impl::guid_v<T>, reinterpret_cast<::IInspectable*>(put_abi(object)));
        }
        return object;
    }

    explicit operator bool() const noexcept
    {
        return static_cast<bool>(m_ref);
    }

private:

    com_ptr<impl::IWeakReference> m_ref;
};

template <typename T>
weak_ref<T> make_weak(T const& object)
{
    return object;
}
