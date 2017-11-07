
namespace winrt::impl
{
    struct marker {};
}

WINRT_EXPORT namespace winrt
{
    struct non_agile : impl::marker {};
    struct no_weak_ref : impl::marker {};
    struct composing : impl::marker {};
    struct composable : impl::marker {};

    template <typename Interface>
    struct cloaked : Interface {};

    template <typename D, typename... I>
    struct implements;
}

namespace winrt::impl
{
    template <typename T>
    struct is_marker : std::is_base_of<impl::marker, T> {};

    template <typename T>
    constexpr bool is_marker_v = is_marker<T>::value;

    template <typename T>
    struct uncloak
    {
        using type = T;
    };

    template <typename T>
    struct uncloak<cloaked<T>>
    {
        using type = T;
    };

    template <typename T>
    using uncloak_t = typename uncloak<T>::type;

    template <typename I>
    struct is_cloaked : std::disjunction<
        std::is_same<::IInspectable, abi_t<I>>,
        std::negation<std::is_base_of<::IInspectable, abi_t<I>>>
    > {};

    template <typename I>
    struct is_cloaked<cloaked<I>> : std::true_type {};

    template <typename I>
    constexpr bool is_cloaked_v = is_cloaked<I>::value;


    template <typename D, typename... I>
    struct root_implements;
    
    template <typename, typename = std::void_t<>>
    struct is_implements : std::false_type {};

    template <typename T>
    struct is_implements<T, std::void_t<typename T::implements_type>> : std::true_type {};

    template <typename T>
    constexpr bool is_implements_v = is_implements<T>::value;

    template <typename...>
    struct nested_implements
    {};

    template <typename First, typename... Rest>
    struct nested_implements<First, Rest...>
        : std::conditional_t<is_implements_v<First>,
        impl::identity<First>, nested_implements<Rest...>>
    {
        static_assert(!is_implements_v<First> || !std::disjunction_v<is_implements<Rest>...>,
            "Duplicate nested implements found");
    };

    template <typename D, typename Dummy = std::void_t<>, typename... I>
    struct base_implements_impl
        : impl::identity<root_implements<D, I...>> {};

    template <typename D, typename... I>
    struct base_implements_impl<D, std::void_t<typename nested_implements<I...>::type>, I...>
        : nested_implements<I...> {};

    template <typename D, typename... I>
    using base_implements = base_implements_impl<D, void, I...>;

    template <typename...>
    struct uncloaked_interfaces;

    template <typename I, typename = std::void_t<>>
    struct uncloaked_interface_one
        : std::integral_constant<uint32_t, 1> {};

    template <typename I>
    struct uncloaked_interface_one<I, std::enable_if_t<(is_cloaked_v<I> || is_marker_v<I>) && !is_implements_v<I>>>
        : std::integral_constant<uint32_t, 0> {};

    template <typename D, typename... I>
    struct uncloaked_interface_one<implements<D, I...>>
        : uncloaked_interfaces<I...> {};

    template <typename T>
    struct uncloaked_interface_one<T, std::void_t<typename T::implements_type>>
        : uncloaked_interface_one<typename T::implements_type> {};

    template <typename...>
    struct uncloaked_interfaces
        : std::integral_constant<uint32_t, 0> {};

    template <typename First, typename... Rest>
    struct uncloaked_interfaces<First, Rest...>
        : std::integral_constant<uint32_t, uncloaked_interface_one<First>::value + uncloaked_interfaces<Rest...>::value> {};

    template <typename T, typename = std::void_t<>>
    struct extract_interface
    {
        using type = T;
    };

    template <typename T>
    struct extract_interface<T, std::enable_if_t<is_implements_v<T>>>
    {
        using type = typename T::first_interface;
    };

    template <typename T>
    struct extract_interface<T, std::enable_if_t<is_marker_v<T>>>
    {};

    template <typename... >
    struct first_interface
    {};

    template <typename First, typename... Rest>
    struct first_interface<First, Rest...>
        : std::conditional_t<!is_marker_v<First>,
            extract_interface<First>, first_interface<Rest...>
        >
    {};

    template <typename D, typename I>
    struct produce;

    template <typename D, typename I, typename Enable = void>
    struct producer;

    template <typename T, typename = std::void_t<>>
    struct has_composable : std::false_type {};

    template <typename T>
    struct has_composable<T, std::void_t<typename T::composable>> : std::true_type {};

    template <typename T, typename = std::void_t<>>
    struct has_class_type : std::false_type {};

    template <typename T>
    struct has_class_type<T, std::void_t<typename T::class_type>> : std::true_type {};

    template <typename I, typename = std::void_t<>>
    struct runtime_class_name
    {
        static hstring get()
        {
            throw hresult_not_implemented{};
        }
    };

    template <typename I>
    struct runtime_class_name<I, std::void_t<decltype(name<I>::value)>>
    {
        static hstring get()
        {
            return hstring{ name_of<I>() };
        }
    };

    template <typename T>
    void clear_abi(T*) noexcept
    {}

    template <typename T>
    void clear_abi(T** value) noexcept
    {
        *value = nullptr;
    }
}

WINRT_EXPORT namespace winrt
{
    template <typename D, typename I>
    D* from_abi(I const& from) noexcept
    {
        return &static_cast<impl::produce<D, impl::default_interface_t<I>>*>(get_abi(from))->shim();
    }

    template <typename I, typename D, std::enable_if_t<std::is_base_of_v<Windows::Foundation::IUnknown, I>>* = nullptr>
    impl::abi_t<I>* to_abi(impl::producer<D, I> const* from) noexcept
    {
        return reinterpret_cast<impl::abi_t<I>*>(const_cast<impl::producer<D, I>*>(from));
    }

    template <typename I, typename D, std::enable_if_t<std::is_base_of_v< ::IUnknown, I>>* = nullptr>
    impl::abi_t<I>* to_abi(impl::producer<D, I> const* from) noexcept
    {
        return const_cast<impl::producer<D, I>*>(from);
    }

    template <typename D, typename I = typename D::first_interface, typename... Args, std::enable_if_t<!impl::has_composable<D>::value && !impl::has_class_type<D>::value>* = nullptr>
    impl::com_ref<I> make(Args&&... args)
    {
        impl::com_ref<I> result{ nullptr };
        *put_abi(result) = to_abi<I>(new D(std::forward<Args>(args)...));
        return result;
    }

    template <typename D, typename... Args, std::enable_if_t<!impl::has_composable<D>::value && impl::has_class_type<D>::value>* = nullptr>
    auto make(Args&&... args)
    {
        static_assert(std::is_same_v<typename D::first_interface, impl::default_interface_t<typename D::class_type>>);
        typename D::class_type result{ nullptr };
        *put_abi(result) = to_abi<typename D::first_interface>(new D(std::forward<Args>(args)...));
        return result;
    }

    template <typename D, typename I = typename D::first_interface, typename... Args, std::enable_if_t<impl::has_composable<D>::value>* = nullptr>
    auto make(Args&&... args)
    {
        com_ptr<I> result;
        *put_abi(result) = to_abi<I>(new D(std::forward<Args>(args)...));
        return result.template as<typename D::composable>();
    }

    template <typename D, typename... Args>
    auto make_self(Args&&... args)
    {
        com_ptr<D> result;
        *put_abi(result) = new D(std::forward<Args>(args)...);
        return result;
    }
}

namespace winrt::impl
{
    template <typename D, typename I, typename Enable>
    struct producer
    {
        operator I() const noexcept
        {
            I result = nullptr;
            copy_from_abi(result, const_cast<produce<D, I>*>(&vtable));
            return result;
        }

    private:

        produce<D, I> vtable;
    };

    template <typename D, typename I>
    struct produce_base : abi_t<I>
    {
        D& shim() noexcept
        {
            return*static_cast<D*>(reinterpret_cast<producer<D, I>*>(this));
        }

        HRESULT __stdcall QueryInterface(GUID const& id, void** object) noexcept override
        {
            return shim().QueryInterface(id, object);
        }

        unsigned long __stdcall AddRef() noexcept override
        {
            return shim().AddRef();
        }

        unsigned long __stdcall Release() noexcept override
        {
            return shim().Release();
        }

        HRESULT __stdcall GetIids(ULONG* count, GUID** array) noexcept override
        {
            return shim().GetIids(count, array);
        }

        HRESULT __stdcall GetRuntimeClassName(HSTRING* name) noexcept override
        {
            return shim().abi_GetRuntimeClassName(name);
        }

        HRESULT __stdcall GetTrustLevel(TrustLevel* trustLevel) noexcept final
        {
            *trustLevel = BaseTrust;
            return S_OK;
        }
    };

    template <typename D, typename I>
    struct producer<D, I, std::enable_if_t<std::is_base_of_v< ::IUnknown, I> && !is_implements_v<I>>> : abi_t<I>
    {};

    template <typename D, typename I>
    struct producer<D, I, std::enable_if_t<is_marker_v<I>>>
    {};

    template <typename D, typename I>
    struct producer<D, I, std::enable_if_t<is_implements_v<I>>>
    {};

    template <typename D>
    struct produce<D, Windows::Foundation::IInspectable> : produce_base<D, Windows::Foundation::IInspectable>
    {};

    struct INonDelegatingInspectable : Windows::Foundation::IUnknown
    {
        INonDelegatingInspectable(std::nullptr_t = nullptr) noexcept {}
    };

    template <> struct abi<INonDelegatingInspectable>
    {
        using type = ::IInspectable;
    };

    template <typename D>
    struct produce<D, INonDelegatingInspectable> : produce_base<D, INonDelegatingInspectable>
    {
        HRESULT __stdcall QueryInterface(const GUID& id, void** object) noexcept final
        {
            return this->shim().NonDelegatingQueryInterface(id, object);
        }

        unsigned long __stdcall AddRef() noexcept final
        {
            return this->shim().NonDelegatingAddRef();
        }

        unsigned long __stdcall Release() noexcept final
        {
            return this->shim().NonDelegatingRelease();
        }

        HRESULT __stdcall GetIids(ULONG* count, GUID** array) noexcept final
        {
            return this->shim().NonDelegatingGetIids(count, array);
        }

        HRESULT __stdcall GetRuntimeClassName(HSTRING* name) noexcept final
        {
            return this->shim().NonDelegatingGetRuntimeClassName(name);
        }
    };

    template <bool Agile>
    struct weak_ref;

    template <bool Agile>
    struct weak_source_producer;

    template <bool Agile>
    struct weak_source : IWeakReferenceSource
    {
        weak_ref<Agile>* that() noexcept
        {
            return static_cast<weak_ref<Agile>*>(reinterpret_cast<weak_source_producer<Agile>*>(this));
        }

        HRESULT __stdcall QueryInterface(GUID const& id, void** object) noexcept override
        {
            if (id == guid_of<IWeakReferenceSource>())
            {
                *object = static_cast<IWeakReferenceSource*>(this);
                that()->increment_strong();
                return S_OK;
            }

            return that()->m_object->QueryInterface(id, object);
        }

        unsigned long __stdcall AddRef() noexcept override
        {
            return that()->increment_strong();
        }

        unsigned long __stdcall Release() noexcept override
        {
            return that()->m_object->Release();
        }

        HRESULT __stdcall GetWeakReference(IWeakReference** weakReference) noexcept override
        {
            *weakReference = that();
            that()->AddRef();
            return S_OK;
        }
    };

    template <bool Agile>
    struct weak_source_producer
    {
    protected:
        weak_source<Agile> m_source;
    };

    template <bool Agile>
    struct weak_ref : IWeakReference, weak_source_producer<Agile>
    {
        weak_ref(::IUnknown* object, uint32_t const strong) noexcept :
            m_object(object),
            m_strong(strong)
        {
            WINRT_ASSERT(object);
        }

        HRESULT __stdcall QueryInterface(GUID const& id, void** object) noexcept override
        {
            if (id == guid_of<IWeakReference>() || id == guid_of<Windows::Foundation::IUnknown>())
            {
                *object = static_cast<IWeakReference*>(this);
                AddRef();
                return S_OK;
            }

            if constexpr (Agile)
            {
                if (id == guid_of<IAgileObject>())
                {
                    *object = static_cast<::IUnknown*>(this);
                    AddRef();
                    return S_OK;
                }

                if (id == guid_of<IMarshal>())
                {
                    *object = new (std::nothrow) free_threaded_marshaler(this);
                    return *object ? S_OK : E_OUTOFMEMORY;
                }
            }

            *object = nullptr;
            return E_NOINTERFACE;
        }

        unsigned long __stdcall AddRef() noexcept override
        {
            return 1 + m_weak.fetch_add(1, std::memory_order_relaxed);
        }

        unsigned long __stdcall Release() noexcept override
        {
            uint32_t const target = m_weak.fetch_sub(1, std::memory_order_relaxed) - 1;

            if (target == 0)
            {
                delete this;
            }

            return target;
        }

        HRESULT __stdcall Resolve(GUID const& id, void** objectReference) noexcept override
        {
            uint32_t target = m_strong.load(std::memory_order_relaxed);

            while (true)
            {
                if (target == 0)
                {
                    *objectReference = nullptr;
                    return S_OK;
                }

                if (m_strong.compare_exchange_weak(target, target + 1, std::memory_order_acquire, std::memory_order_relaxed))
                {
                    HRESULT hr = m_object->QueryInterface(id, objectReference);
                    m_strong.fetch_sub(1, std::memory_order_relaxed);
                    return hr;
                }
            }
        }

        void set_strong(uint32_t const count) noexcept
        {
            m_strong = count;
        }

        uint32_t increment_strong() noexcept
        {
            return 1 + m_strong.fetch_add(1, std::memory_order_relaxed);
        }

        uint32_t decrement_strong() noexcept
        {
            uint32_t const target = m_strong.fetch_sub(1, std::memory_order_release) - 1;

            if (target == 0)
            {
                Release();
            }

            return target;
        }

        IWeakReferenceSource* get_source() noexcept
        {
            increment_strong();
            return &this->m_source;
        }

    private:
        template <bool Agile>
        friend struct weak_source;

        static_assert(sizeof(weak_source_producer<Agile>) == sizeof(weak_source<Agile>));

        ::IUnknown* m_object{};
        std::atomic<uint32_t> m_strong{ 1 };
        std::atomic<uint32_t> m_weak{ 1 };
    };

    template <bool>
    struct WINRT_EBO root_implements_composing_outer
    {
    protected:
        static constexpr ::IInspectable* m_inner = nullptr;
    };

    template <>
    struct WINRT_EBO root_implements_composing_outer<true>
    {
        template <typename Qi>
        Qi try_as() const noexcept
        {
            return m_inner.try_as<Qi>();
        }

        explicit operator bool() const noexcept
        {
            return m_inner.operator bool();
        }
    protected:
        Windows::Foundation::IInspectable m_inner;
    };

    template <typename D, bool>
    struct WINRT_EBO root_implements_composable_inner
    {
    protected:
        static constexpr ::IInspectable* outer() noexcept { return nullptr; }

        template <typename T, typename D, typename I>
        friend class produce_dispatch_to_super_base;
    };

    template <typename D>
    struct WINRT_EBO root_implements_composable_inner<D, true> : producer<D, INonDelegatingInspectable>
    {
    protected:
        ::IInspectable* outer() noexcept { return m_outer; }
    private:
        ::IInspectable* m_outer = nullptr;

        template <typename T, typename D, typename I>
        friend class produce_dispatch_to_super_base;

        template <typename D>
        friend struct composable_factory;
    };

    template <typename D, typename... I>
    struct root_implements
        : root_implements_composing_outer<std::disjunction<std::is_same<composing, I>...>::value>
        , root_implements_composable_inner<D, std::disjunction<std::is_same<composable, I>...>::value>
    {
        using IInspectable = Windows::Foundation::IInspectable;
        using root_implements_type = root_implements;

        HRESULT __stdcall QueryInterface(GUID const& id, void** object) noexcept
        {
            if (this->outer())
            {
                return this->outer()->QueryInterface(id, object);
            }

            HRESULT result = query_interface(id, object);

            if (result == E_NOINTERFACE && this->m_inner)
            {
                result = get_abi(this->m_inner)->QueryInterface(id, object);
            }

            return result;
        }

        unsigned long __stdcall AddRef() noexcept
        {
            if (this->outer())
            {
                return this->outer()->AddRef();
            }

            return NonDelegatingAddRef();
        }

        unsigned long __stdcall Release() noexcept
        {
            if (this->outer())
            {
                return this->outer()->Release();
            }

            return NonDelegatingRelease();
        }

        struct abi_guard
        {
            abi_guard(D& derived) :
                m_derived(derived)
            {
                m_derived.abi_enter();
            }

            ~abi_guard()
            {
                m_derived.abi_exit();
            }

        private:

            D& m_derived;
        };

    protected:

        explicit root_implements(uint32_t references = 1) noexcept
            : m_references(references)
        {}

        virtual ~root_implements() {}

        HRESULT __stdcall GetIids(ULONG* count, GUID** array) noexcept
        {
            if (this->outer())
            {
                return this->outer()->GetIids(count, array);
            }

            return NonDelegatingGetIids(count, array);
        }

        HRESULT __stdcall abi_GetRuntimeClassName(HSTRING* name) noexcept
        {
            if (this->outer())
            {
                return this->outer()->GetRuntimeClassName(name);
            }

            return NonDelegatingGetRuntimeClassName(name);
        }

        HRESULT __stdcall abi_GetTrustLevel(TrustLevel* trustLevel) noexcept
        {
            if (this->outer())
            {
                return this->outer()->GetTrustLevel(trustLevel);
            }

            return NonDelegatingGetTrustLevel(trustLevel);
        }

        unsigned long __stdcall NonDelegatingAddRef() noexcept
        {
            if constexpr (is_weak_ref_source::value)
            {
                uintptr_t count_or_pointer = m_references.load(std::memory_order_relaxed);

                while (true)
                {
                    if (is_weak_ref(count_or_pointer))
                    {
                        return decode_weak_ref(count_or_pointer)->increment_strong();
                    }

                    uintptr_t const target = count_or_pointer + 1;

                    if (m_references.compare_exchange_weak(count_or_pointer, target, std::memory_order_relaxed))
                    {
                        return static_cast<uint32_t>(target);
                    }
                }
            }
            else
            {
                return 1 + m_references.fetch_add(1, std::memory_order_relaxed);
            }
        }

        unsigned long __stdcall NonDelegatingRelease() noexcept
        {
            uint32_t const target = subtract_reference();

            if (target == 0)
            {
                std::atomic_thread_fence(std::memory_order_acquire);
                delete static_cast<D*>(this);
            }

            return target;
        }

        HRESULT __stdcall NonDelegatingQueryInterface(const GUID& id, void** object) noexcept
        {
            if (id == guid_of<Windows::Foundation::IInspectable>() || id == guid_of<Windows::Foundation::IUnknown>())
            {
                ::IInspectable* result = to_abi<impl::INonDelegatingInspectable>(this);
                NonDelegatingAddRef();
                *object = result;
                return S_OK;
            }

            HRESULT result = query_interface(id, object);

            if (result == E_NOINTERFACE && this->m_inner)
            {
                result = get_abi(this->m_inner)->QueryInterface(id, object);
            }

            return result;
        }

        HRESULT __stdcall NonDelegatingGetIids(ULONG* count, GUID** array) noexcept
        {
            *count = static_cast<D*>(this)->uncloaked_interfaces_nested();

            if (*count == 0)
            {
                *array = nullptr;
                return S_OK;
            }

            *array = static_cast<GUID*>(CoTaskMemAlloc(sizeof(GUID)**count));

            if (*array == nullptr)
            {
                return E_OUTOFMEMORY;
            }

            copy_guids_nested(*array);
            return S_OK;
        }

        HRESULT __stdcall NonDelegatingGetRuntimeClassName(HSTRING* name) noexcept
        {
            try
            {
                *name = detach_abi(static_cast<D*>(this)->GetRuntimeClassName());
                return S_OK;
            }
            catch (...) { return impl::to_hresult(); }
        }

        HRESULT __stdcall NonDelegatingGetTrustLevel(TrustLevel* trustLevel) noexcept
        {
            try
            {
                *trustLevel = static_cast<D*>(this)->GetTrustLevel();
                return S_OK;
            }
            catch (...) { return impl::to_hresult(); }
        }

        virtual void* find_interface_nested(GUID const&) const noexcept
        {
            return nullptr;
        }

        virtual ::IInspectable* find_inspectable_nested() const noexcept
        {
            return nullptr;
        }

        virtual void copy_guids_nested(GUID*) const noexcept
        {
        }

        uint32_t subtract_reference() noexcept
        {
            if constexpr (is_weak_ref_source::value)
            {
                uintptr_t count_or_pointer = m_references.load(std::memory_order_relaxed);

                while (true)
                {
                    if (is_weak_ref(count_or_pointer))
                    {
                        return decode_weak_ref(count_or_pointer)->decrement_strong();
                    }

                    uintptr_t const target = count_or_pointer - 1;

                    if (m_references.compare_exchange_weak(count_or_pointer, target, std::memory_order_release, std::memory_order_relaxed))
                    {
                        return static_cast<uint32_t>(target);
                    }
                }
            }
            else
            {
                return m_references.fetch_sub(1, std::memory_order_release) - 1;
            }
        }

    private:
        void abi_enter() noexcept {}
        void abi_exit() noexcept {}

        using is_agile = std::negation<std::disjunction<std::is_same<non_agile, I>...>>;
        using is_factory = std::disjunction<std::is_same<abi_t<Windows::Foundation::IActivationFactory>, abi_t<I>>...>;
        using is_inspectable = std::disjunction<std::is_base_of<::IInspectable, abi_t<I>>...>;
        using is_weak_ref_source = std::conjunction<is_inspectable, std::negation<is_factory>, std::negation<std::disjunction<std::is_same<no_weak_ref, I>...>>>;
        using weak_ref_t = impl::weak_ref<is_agile::value>;

        static_assert(!is_factory::value || (is_factory::value&& is_agile::value), "winrt::implements - activation factories must be agile.");

        std::atomic<std::conditional_t<is_weak_ref_source::value, uintptr_t, uint32_t>> m_references;

        HRESULT query_interface(GUID const& id, void** object) noexcept
        {
            *object = static_cast<D*>(this)->find_interface_nested(id);

            if (*object != nullptr)
            {
                AddRef();
                return S_OK;
            }

            if constexpr (is_agile::value)
            {
                if (id == guid_of<IAgileObject>())
                {
                    *object = get_unknown();
                    AddRef();
                    return S_OK;
                }

                if (id == guid_of<IMarshal>())
                {
                    *object = new (std::nothrow) free_threaded_marshaler(get_unknown());
                    return *object ? S_OK : E_OUTOFMEMORY;
                }
            }

            if constexpr (is_inspectable::value)
            {
                if (id == __uuidof(::IInspectable))
                {
                    *object = find_inspectable_nested();
                    AddRef();
                    return S_OK;
                }
            }

            if (id == __uuidof(::IUnknown))
            {
                *object = get_unknown();
                AddRef();
                return S_OK;
            }

            if constexpr (is_weak_ref_source::value)
            {
                if (id == __uuidof(impl::IWeakReferenceSource))
                {
                    *object = make_weak_ref();
                    return*object ? S_OK : E_OUTOFMEMORY;
                }
            }

            return E_NOINTERFACE;
        }

        impl::IWeakReferenceSource* make_weak_ref() noexcept
        {
            static_assert(is_weak_ref_source::value, "This is only for weak ref support.");
            uintptr_t count_or_pointer = m_references.load(std::memory_order_relaxed);

            if (is_weak_ref(count_or_pointer))
            {
                return decode_weak_ref(count_or_pointer)->get_source();
            }

            com_ptr<weak_ref_t> weak_ref;
            *weak_ref.put() = new (std::nothrow) weak_ref_t(get_unknown(), static_cast<uint32_t>(count_or_pointer));

            if (!weak_ref)
            {
                return nullptr;
            }

            uintptr_t const encoding = encode_weak_ref(weak_ref.get());

            for (;;)
            {
                if (m_references.compare_exchange_weak(count_or_pointer, encoding, std::memory_order_acq_rel, std::memory_order_relaxed))
                {
                    impl::IWeakReferenceSource* result = weak_ref->get_source();
                    detach_abi(weak_ref);
                    return result;
                }

                if (is_weak_ref(count_or_pointer))
                {
                    return decode_weak_ref(count_or_pointer)->get_source();
                }

                weak_ref->set_strong(static_cast<uint32_t>(count_or_pointer));
            }
        }

        static bool is_weak_ref(intptr_t const value) noexcept
        {
            static_assert(is_weak_ref_source::value, "This is only for weak ref support.");
            return value < 0;
        }

        static weak_ref_t* decode_weak_ref(uintptr_t const value) noexcept
        {
            static_assert(is_weak_ref_source::value, "This is only for weak ref support.");
            return reinterpret_cast<weak_ref_t*>(value << 1);
        }

        static uintptr_t encode_weak_ref(weak_ref_t* value) noexcept
        {
            static_assert(is_weak_ref_source::value, "This is only for weak ref support.");
            constexpr uintptr_t pointer_flag = static_cast<uintptr_t>(1) << ((sizeof(uintptr_t) * 8) - 1);
            WINRT_ASSERT((reinterpret_cast<uintptr_t>(value) & 1) == 0);
            return (reinterpret_cast<uintptr_t>(value) >> 1) | pointer_flag;
        }

        virtual ::IUnknown* get_unknown() const noexcept = 0;
        virtual uint32_t uncloaked_interfaces_nested() const noexcept = 0;
        virtual hstring GetRuntimeClassName() const = 0;

        virtual TrustLevel GetTrustLevel() const noexcept
        {
            return BaseTrust;
        }

        template <typename D, typename I>
        friend struct impl::produce_base;

        template <typename D, typename I>
        friend struct impl::produce;
    };
}

WINRT_EXPORT namespace winrt
{
    template <typename D, typename... I>
    struct implements : impl::producer<D, impl::uncloak_t<I>>..., impl::base_implements<D, I...>::type
    {
    protected:

        using base_type = typename impl::base_implements<D, I...>::type;
        using root_implements_type = typename base_type::root_implements_type;

        template <typename... Args>
        explicit implements(Args&&... args)
            : base_type(std::forward<Args>(args)...)
        {}

    public:

        using implements_type = implements;
        using first_interface = typename impl::first_interface<impl::uncloak_t<I>...>::type;
        using IInspectable = Windows::Foundation::IInspectable;

        operator IInspectable() const noexcept
        {
            IInspectable result;
            copy_from_abi(result, find_inspectable<I...>());
            return result;
        }

        HRESULT __stdcall QueryInterface(GUID const& id, void** object) noexcept
        {
            return root_implements_type::QueryInterface(id, object);
        }

        unsigned long __stdcall AddRef() noexcept
        {
            return root_implements_type::AddRef();
        }

        unsigned long __stdcall Release() noexcept
        {
            return root_implements_type::Release();
        }
        void* find_interface_nested(GUID const& id) const noexcept override
        {
            return find_interface<impl::uncloak_t<I>...>(id);
        }

        ::IInspectable* find_inspectable_nested() const noexcept override
        {
            return find_inspectable<I...>();
        }

        uint32_t uncloaked_interfaces_nested() const noexcept override
        {
            return impl::uncloaked_interfaces<I...>();
        }

        virtual void copy_guids_nested(GUID* ids) const noexcept override
        {
            return copy_guids<I...>(ids);
        }

    private:
        template <typename First, typename... Rest>
        void copy_guids(GUID* ids) const noexcept
        {
            if constexpr (!impl::is_cloaked_v<First>)
            {
                *ids++ = guid_of<First>();
            }
            if constexpr (sizeof...(Rest) > 0)
            {
                copy_guids<Rest...>(ids);
            }
            else
            {
                base_type::copy_guids_nested(ids);
            }
        }

        template <typename First, typename... Rest>
        void* find_interface(GUID const& id) const noexcept
        {
            if constexpr (!impl::is_marker_v<First> && !impl::is_implements_v<First>)
            {
                if (id == guid_of<First>())
                {
                    return to_abi<First>(this);
                }
            }
            if constexpr (sizeof...(Rest) > 0)
            {
                return find_interface<Rest...>(id);
            }
            else
            {
                return base_type::find_interface_nested(id);
            }
        }

        template <typename First, typename... Rest>
        ::IInspectable* find_inspectable() const noexcept
        {
            if constexpr (std::is_base_of_v<::IInspectable, impl::abi_t<First>>)
            {
                return to_abi<First>(this);
            }
            else if constexpr (sizeof...(Rest) > 0)
            {
                return find_inspectable<Rest...>();
            }
            else
            {
                return base_type::find_inspectable_nested();
            }
        }

        ::IUnknown* get_unknown() const noexcept override
        {
            return to_abi<first_interface>(this);
        }

        hstring GetRuntimeClassName() const override
        {
            return impl::runtime_class_name<first_interface>::get();
        }

        template <typename D, typename... I>
        friend struct impl::root_implements;
    };
}
