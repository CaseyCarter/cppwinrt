
namespace Windows::Foundation
{

    struct IActivationFactory;

    template <typename D>
    struct WINRT_EBO impl_IActivationFactory
    {
        IInspectable ActivateInstance() const;
    };
}

namespace impl
{
    template <> struct traits<Windows::Foundation::IActivationFactory>
    {
        using abi = ABI::Windows::Foundation::IActivationFactory;
        template <typename D> using consume = Windows::Foundation::impl_IActivationFactory<D>;
    };

    template <typename D>
    struct produce<D, Windows::Foundation::IActivationFactory> : produce_base<D, Windows::Foundation::IActivationFactory>
    {
        HRESULT __stdcall abi_ActivateInstance(abi_arg_out<Windows::Foundation::IInspectable> instance) noexcept final
        {
            try
            {
                typename D::abi_guard guard(this->shim());
                *instance = detach_abi(this->shim().ActivateInstance());
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
        hstring_view classId(impl::traits<Class>::name());

        Interface factory;
        check_hresult(WINRT_RoGetActivationFactory(get_abi(classId), __uuidof(abi<Interface>), reinterpret_cast<void **>(put_abi(factory))));

        if (!factory.template try_as<IAgileObject>())
        {
            return nullptr;
        }

        return factory;
    }

    template <typename Class, typename Interface>
    Interface get_activation_factory()
    {
        hstring_view classId(impl::traits<Class>::name());

        Interface factory;
        check_hresult(WINRT_RoGetActivationFactory(get_abi(classId), __uuidof(abi<Interface>), reinterpret_cast<void **>(put_abi(factory))));
        return factory;
    }
}

namespace Windows::Foundation
{
    struct IActivationFactory :
        IInspectable,
        impl::consume<IActivationFactory>
    {
        IActivationFactory(std::nullptr_t = nullptr) noexcept {}
    };

    template <typename D>
    IInspectable impl_IActivationFactory<D>::ActivateInstance() const
    {
        IInspectable instance;
        check_hresult(WINRT_SHIM(IActivationFactory)->abi_ActivateInstance(put_abi(instance)));
        return instance;
    }

}

enum class apartment_type
{
    single_threaded,
    multi_threaded
};

inline void init_apartment(const apartment_type type = apartment_type::multi_threaded)
{
    HRESULT const result = WINRT_RoInitialize(static_cast<uint32_t>(type));

    if (result < 0)
    {
        impl::throw_hresult(result);
    }
}

inline void uninit_apartment() noexcept
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
