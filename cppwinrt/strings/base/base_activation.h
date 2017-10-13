
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
    com_ref<Interface> get_activation_factory()
    {
        param::hstring classId{ name_of<Class>() };

        com_ref<Interface> factory;
        check_hresult(WINRT_RoGetActivationFactory(get_abi(classId), guid_of<Interface>(), reinterpret_cast<void**>(put_abi(factory))));
        return factory;
    }

    struct factory_cache_typeless_entry
    {
        void clear() noexcept
        {
            lock_guard<> const guard(m_lock);
            m_factory = nullptr;
        }

        factory_cache_typeless_entry* next{ nullptr };

    private:

        mutex m_lock;
        Windows::Foundation::IUnknown m_factory;
    };

    struct factory_cache
    {
        void add(factory_cache_typeless_entry* entry) noexcept
        {
            WINRT_ASSERT(entry);
            lock_guard<> const guard(m_lock);
            entry->next = m_begin;
            m_begin = entry;
        }

        void clear() noexcept
        {
            lock_guard<> const guard(m_lock);

            while (m_begin != nullptr)
            {
                m_begin->clear();
                m_begin = m_begin->next;
            }
        }

    private:

        mutex m_lock;
        factory_cache_typeless_entry* m_begin{ nullptr };
    };

    inline factory_cache& get_factory_cache() noexcept
    {
        static factory_cache cache;
        return cache;
    }

    template <typename Class, typename Interface>
    struct factory_cache_entry
    {
        com_ref<Interface> get()
        {
#ifdef WINRT_DIAGNOSTICS
            get_diagnostics_info().add_factory<Class>();
#endif

            {
                shared_lock_guard const guard(m_lock);

                if (m_factory)
                {
                    return m_factory;
                }
            }

            com_ref<Interface> factory = get_activation_factory<Class, Interface>();

            if (!factory.template try_as<IAgileObject>())
            {
#ifdef WINRT_DIAGNOSTICS
                get_diagnostics_info().non_agile_factory<Class>();
#else
                WINRT_TRACE("Warning non-agile factory: %ls\n", name_v<Class>);
#endif
                return factory;
            }

            lock_guard<shared_mutex> const guard(m_lock);

            if (!m_factory)
            {
                m_factory = std::move(factory);
                get_factory_cache().add(reinterpret_cast<factory_cache_typeless_entry*>(this));
            }

            return m_factory;
        }

        void clear() noexcept
        {
            lock_guard<shared_mutex> const guard(m_lock);
            m_factory = nullptr;
        }

    private:

        void* m_next{ nullptr };
        shared_mutex m_lock;
        com_ref<Interface> m_factory;
    };
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

    enum class apartment_type : int32_t
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
    impl::com_ref<Interface> get_activation_factory()
    {
        static impl::factory_cache_entry<Class, Interface> factory;
        return factory.get();
    }

    template <typename Class, typename Instance = Class>
    Instance activate_instance()
    {
        return get_activation_factory<Class>().ActivateInstance().template try_as<Instance>();
    }

    inline void clear_factory_cache() noexcept
    {
        impl::get_factory_cache().clear();
    }
}
