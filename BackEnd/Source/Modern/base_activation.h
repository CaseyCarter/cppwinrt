
namespace ABI::Windows::Foundation {

struct __declspec(uuid("00000035-0000-0000-c000-000000000046")) __declspec(novtable) IActivationFactory : IInspectable
{
    virtual HRESULT __stdcall abi_ActivateInstance(IInspectable ** instance) = 0;
};

}

namespace Windows::Foundation {

struct IActivationFactory;

template <typename D>
struct WINRT_EBO impl_IActivationFactory
{
    IInspectable ActivateInstance() const;
};

}

namespace impl {

template <> struct traits<Windows::Foundation::IActivationFactory>
{
    using abi = ABI::Windows::Foundation::IActivationFactory;
    template <typename D> using consume = Windows::Foundation::impl_IActivationFactory<D>;
};

template <typename D>
struct produce<D, Windows::Foundation::IActivationFactory> : produce_base<D, Windows::Foundation::IActivationFactory>
{
    HRESULT __stdcall abi_ActivateInstance(abi_arg_out<Windows::IInspectable> instance) noexcept final
    {
        try
        {
            *instance = detach(this->shim().ActivateInstance());
            return S_OK;
        }
        catch (...)
        {
            *instance = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename Class, typename Interface>
Interface get_agile_activation_factory()
{
    hstring_ref classId(impl::traits<Class>::name());

    Interface factory;
    check_hresult(WINRT_RoGetActivationFactory(get(classId), __uuidof(abi<Interface>), reinterpret_cast<void **>(put(factory))));

    if (!factory.template try_as<IAgileObject>())
    {
        return nullptr;
    }

    return factory;
}

template <typename Class, typename Interface>
Interface get_activation_factory()
{
    hstring_ref classId(impl::traits<Class>::name());

    Interface factory;
    check_hresult(WINRT_RoGetActivationFactory(get(classId), __uuidof(abi<Interface>), reinterpret_cast<void **>(put(factory))));
    return factory;
}

}

namespace Windows::Foundation {

struct IActivationFactory :
    IInspectable,
    impl::consume<IActivationFactory>
{
    IActivationFactory(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IActivationFactory>(m_ptr); }
};

template <typename D>
IInspectable impl_IActivationFactory<D>::ActivateInstance() const
{
    IInspectable instance;
    check_hresult(static_cast<const IActivationFactory &>(static_cast<const D &>(*this))->abi_ActivateInstance(put(instance)));
    return instance;
}

}

enum class InitializeType
{
    SingleThreaded,
    MultiThreaded
};

inline void Initialize(const InitializeType type = InitializeType::MultiThreaded)
{
    check_hresult(WINRT_RoInitialize(static_cast<uint32_t>(type)));
}

inline void Uninitialize() noexcept
{
    WINRT_RoUninitialize();
}

template <typename Class, typename Interface = Windows::Foundation::IActivationFactory>
Interface get_activation_factory()
{
    static Interface factory = impl::get_agile_activation_factory<Class, Interface>();

    if (!factory)
    {
        return impl::get_activation_factory<Class, Interface>();
    }

    return factory;
}

template <typename Class, typename Instance = Class>
Instance activate_instance()
{
    return get_activation_factory<Class>().ActivateInstance().template as<Instance>();
}
