
namespace winrt::impl
{
    template <typename D>
    Windows::Foundation::IInspectable consume_IActivationFactory<D>::ActivateInstance() const
    {
        Windows::Foundation::IInspectable instance;
        check_hresult(WINRT_SHIM(Windows::Foundation::IActivationFactory)->ActivateInstance(put_abi(instance)));
        return instance;
    }

    template <typename D>
    struct produce<D, Windows::Foundation::IActivationFactory> : produce_base<D, Windows::Foundation::IActivationFactory>
    {
        HRESULT __stdcall ActivateInstance(::IUnknown** instance) noexcept final
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
                return to_hresult();
            }
        }
    };

    template <typename Class, typename Interface>
    Interface get_activation_factory()
    {
        param::hstring classId(string_data(impl::name_v<Class>));

        Interface factory;
        check_hresult(WINRT_RoGetActivationFactory(get_abi(classId), guid_v<Interface>, reinterpret_cast<void**>(put_abi(factory))));
        return factory;
    }

#ifndef WINRT_DISABLE_FACTORY_CACHE
    template <typename Class, typename Interface>
    Interface get_agile_activation_factory()
    {
        Interface factory = get_activation_factory<Class, Interface>();

        if (!factory.template try_as<IAgileObject>())
        {
            return nullptr;
        }

        return factory;
    }
#endif
}

WINRT_EXPORT namespace winrt
{
    namespace Windows::Foundation
    {
        struct IActivationFactory :
            IInspectable,
            impl::consume_t<IActivationFactory>
        {
            IActivationFactory(std::nullptr_t = nullptr) noexcept {}
        };
    }

    enum class apartment_type
    {
        single_threaded,
        multi_threaded
    };

    inline void init_apartment(apartment_type const type = apartment_type::multi_threaded)
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
#ifdef WINRT_DISABLE_FACTORY_CACHE
        return impl::get_activation_factory<Class, Interface>();
#else
        static Interface factory = impl::get_agile_activation_factory<Class, Interface>();

        if (!factory)
        {
            return impl::get_activation_factory<Class, Interface>();
        }

        return factory;
#endif
    }

    template <typename Class, typename Instance = Class>
    Instance activate_instance()
    {
        return get_activation_factory<Class>().ActivateInstance().template as<Instance>();
    }
}
