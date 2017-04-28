
namespace impl
{
    struct marker {};
}

struct non_agile : impl::marker {};
struct no_weak_ref : impl::marker {};

template <typename Interface>
struct cloaked : Interface {};

namespace impl
{
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

    template <typename ... I>
    struct first_interface
    {
        using type = void;
    };

    template <typename First, typename ... Rest>
    struct first_interface<First, Rest ...>
    {
        using type = std::conditional_t<std::is_base_of_v<marker, First>, typename first_interface<Rest ...>::type, First>;
    };

    template <typename D, typename I>
    struct produce;

    template <typename D, typename I, typename Enable = void>
    struct producer;

    template <typename T>
    class has_composable
    {
        template <typename U> static constexpr bool get_value(typename U::composable*) { return true; }
        template <typename>   static constexpr bool get_value(...) { return false; }

    public:

        static constexpr bool value = get_value<T>(0);
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

template <typename D, typename I>
D* from_abi(I const& from) noexcept
{
    return&static_cast<impl::produce<D, I>*>(get_abi(from))->shim();
}

template <typename I, typename D, std::enable_if_t<std::is_base_of<Windows::Foundation::IUnknown, I>::value>* = nullptr>
abi_t<I>* to_abi(impl::producer<D, I> const* from) noexcept
{
    return reinterpret_cast<abi_t<I>*>(const_cast<impl::producer<D, I>*>(from));
}

template <typename I, typename D, std::enable_if_t<std::is_base_of< ::IUnknown, I>::value>* = nullptr>
abi_t<I>* to_abi(impl::producer<D, I> const* from) noexcept
{
    return const_cast<impl::producer<D, I>*>(from);
}

template <typename D, typename I = typename D::first_interface, typename ... Args, std::enable_if_t<!impl::has_composable<D>::value>* = nullptr>
auto make(Args&& ... args)
{
    std::conditional_t<std::is_base_of_v<Windows::Foundation::IUnknown, I>, I, com_ptr<I>> instance = nullptr;
    *put_abi(instance) = to_abi<I>(new D(std::forward<Args>(args) ...));
    return instance;
}

template <typename D, typename I = typename D::first_interface, typename ... Args, std::enable_if_t<impl::has_composable<D>::value>* = nullptr>
auto make(Args&& ... args)
{
    com_ptr<I> instance;
    *put_abi(instance) = to_abi<I>(new D(std::forward<Args>(args) ...));
    return instance.template as<typename D::composable>();
}

template <typename D, typename ... Args>
auto make_self(Args&& ... args)
{
    com_ptr<D> instance;
    *put_abi(instance) = new D(std::forward<Args>(args) ...);
    return instance;
}

namespace impl
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

        HRESULT __stdcall GetTrustLevel(TrustLevel* trustLevel) noexcept override final
        {
            *trustLevel = BaseTrust;
            return S_OK;
        }
    };

    template <typename D, typename I>
    struct producer<D, I, std::enable_if_t<std::is_base_of< ::IUnknown, I>::value>> : abi_t<I>
    {};

    template <typename D, typename I>
    struct producer<D, I, std::enable_if_t<std::is_base_of_v<marker, I>>>
    {};

    template <typename D>
    struct produce<D, Windows::Foundation::IInspectable> : produce_base<D, Windows::Foundation::IInspectable>
    {};

    template <bool Agile>
    struct free_threaded_marshaler
    {
        void* find_marshal() noexcept
        {
            WINRT_ASSERT(false);
            return nullptr;
        }
    };

    template <>
    struct free_threaded_marshaler<true> : IMarshal
    {
        void* find_marshal() noexcept
        {
            return static_cast<IMarshal*>(this);
        }

        HRESULT __stdcall GetUnmarshalClass(REFIID riid, void* pv, DWORD dwDestContext, void* pvDestContext, DWORD mshlflags, CLSID* pCid) noexcept final
        {
            if (com_ptr<IMarshal> marshal = get_marshaler())
            {
                return marshal->GetUnmarshalClass(riid, pv, dwDestContext, pvDestContext, mshlflags, pCid);
            }

            return E_OUTOFMEMORY;
        }

        HRESULT __stdcall GetMarshalSizeMax(REFIID riid, void* pv, DWORD dwDestContext, void* pvDestContext, DWORD mshlflags, DWORD* pSize) noexcept final
        {
            if (com_ptr<IMarshal> marshal = get_marshaler())
            {
                return marshal->GetMarshalSizeMax(riid, pv, dwDestContext, pvDestContext, mshlflags, pSize);
            }

            return E_OUTOFMEMORY;
        }

        HRESULT __stdcall MarshalInterface(IStream* pStm, REFIID riid, void* pv, DWORD dwDestContext, void* pvDestContext, DWORD mshlflags) noexcept final
        {
            if (com_ptr<IMarshal> marshal = get_marshaler())
            {
                return marshal->MarshalInterface(pStm, riid, pv, dwDestContext, pvDestContext, mshlflags);
            }

            return E_OUTOFMEMORY;
        }

        HRESULT __stdcall UnmarshalInterface(IStream* pStm, REFIID riid, void** ppv) noexcept final
        {
            if (com_ptr<IMarshal> marshal = get_marshaler())
            {
                return marshal->UnmarshalInterface(pStm, riid, ppv);
            }

            return E_OUTOFMEMORY;
        }

        HRESULT __stdcall ReleaseMarshalData(IStream* pStm) noexcept final
        {
            if (com_ptr<IMarshal> marshal = get_marshaler())
            {
                return marshal->ReleaseMarshalData(pStm);
            }

            return E_OUTOFMEMORY;
        }

        HRESULT __stdcall DisconnectObject(DWORD dwReserved) noexcept final
        {
            if (com_ptr<IMarshal> marshal = get_marshaler())
            {
                return marshal->DisconnectObject(dwReserved);
            }

            return E_OUTOFMEMORY;
        }

    private:

        static com_ptr<IMarshal> get_marshaler() noexcept
        {
            com_ptr<::IUnknown> unknown;
            WINRT_VERIFY_(S_OK, CoCreateFreeThreadedMarshaler(nullptr, put_abi(unknown)));
            return unknown ? unknown.try_as<IMarshal>() : nullptr;
        }
    };

    template <bool Agile>
    struct weak_ref : IWeakReference, free_threaded_marshaler<Agile>
    {
        weak_ref(::IUnknown* object, uint32_t const strong) :
            m_object(object),
            m_strong(strong)
        {
            WINRT_ASSERT(object);
        }

        HRESULT __stdcall QueryInterface(GUID const& id, void** object) noexcept override
        {
            if (id == __uuidof(IWeakReference) || id == __uuidof(::IUnknown))
            {
                *object = static_cast<IWeakReference*>(this);
                AddRef();
                return S_OK;
            }

            if (Agile)
            {
                if (id == __uuidof(IAgileObject) || id == __uuidof(IMarshal))
                {
                    *object = this->find_marshal();
                    AddRef();
                    return S_OK;
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

        HRESULT __stdcall Resolve(GUID const& id, ::IInspectable** objectReference) noexcept override
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
                    HRESULT hr = m_object->QueryInterface(id, reinterpret_cast<void**>(objectReference));
                    m_strong.fetch_sub(1, std::memory_order_relaxed);
                    return hr;
                }
            }
        }

        void set_strong(uint32_t const count)
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

        IWeakReferenceSource* get_source()
        {
            increment_strong();
            return&m_source;
        }

    private:

        struct weak_source : IWeakReferenceSource
        {
            weak_ref* that() noexcept
            {
                return reinterpret_cast<weak_ref*>(reinterpret_cast<uint8_t*>(this) - offsetof(weak_ref, m_source));
            }

            HRESULT __stdcall QueryInterface(GUID const& id, void** object) noexcept override
            {
                if (id == __uuidof(IWeakReferenceSource))
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

        weak_source m_source;
        ::IUnknown* m_object{};
        std::atomic<uint32_t> m_strong{ 1 };
        std::atomic<uint32_t> m_weak{ 1 };
    };

    template <typename ... I>
    using is_agile = std::negation<std::disjunction<std::is_same<non_agile, I> ...>>;
}

template <typename D, typename ... I>
struct implements : impl::producer<D, impl::uncloak_t<I>> ..., impl::free_threaded_marshaler<impl::is_agile<I ...>::value>
{
    using first_interface = typename impl::first_interface<impl::uncloak_t<I> ...>::type;
    using IInspectable = Windows::Foundation::IInspectable;

    operator IInspectable() const noexcept
    {
        IInspectable result;
        copy_from_abi(result, find_inspectable<I ...>());
        return result;
    }

    HRESULT __stdcall QueryInterface(GUID const& id, void** object) noexcept
    {
        return query_interface(id, object, is_weak_ref_source{});
    }

    unsigned long __stdcall AddRef() noexcept
    {
        return add_reference(is_weak_ref_source{});
    }

    unsigned long __stdcall Release() noexcept
    {
        uint32_t const target = subtract_reference();

        if (target == 0)
        {
            std::atomic_thread_fence(std::memory_order_acquire);
            delete static_cast<D*>(this);
        }

        return target;
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

    implements(uint32_t references = 1) :
        m_references(references)
    {}

    HRESULT __stdcall GetIids(ULONG* count, GUID** array) noexcept
    {
        *count = uncloaked_interfaces<I ...>();

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

        copy_guids<I ...>(*array);
        return S_OK;
    }

    HRESULT __stdcall abi_GetRuntimeClassName(HSTRING* name) noexcept
    {
        try
        {
            *name = detach_abi(static_cast<D*>(this)->GetRuntimeClassName());
            return S_OK;
        }
        catch (...) { return impl::to_hresult(); }
    }

    HRESULT __stdcall GetTrustLevel(TrustLevel* trustLevel) noexcept
    {
        try
        {
            *trustLevel = static_cast<D*>(this)->GetTrustLevel();
            return S_OK;
        }
        catch (...) { return impl::to_hresult(); }
    }

    uint32_t subtract_reference() noexcept
    {
        return subtract_reference(is_weak_ref_source{});
    }

private:

    void abi_enter() noexcept {}
    void abi_exit() noexcept {}

    using is_agile = impl::is_agile<I ...>;
    using is_factory = std::disjunction<std::is_same<abi_t<Windows::Foundation::IActivationFactory>, abi_t<I>> ...>;
    using is_inspectable = std::disjunction<std::is_base_of<::IInspectable, abi_t<I>> ...>;
    using is_weak_ref_source = std::disjunction<is_inspectable, std::negation<is_factory>, std::negation<std::disjunction<std::is_same<no_weak_ref, I> ...>>>;
    using weak_ref_t = impl::weak_ref<is_agile::value>;

    static_assert(!is_factory::value || (is_factory::value&& is_agile::value), "winrt::implements - activation factories must be agile.");

    std::atomic<std::conditional_t<is_weak_ref_source::value, uintptr_t, uint32_t>> m_references;

    HRESULT query_interface(GUID const& id, void** object, std::true_type) noexcept
    {
        static_assert(is_weak_ref_source::value, "This is only for weak ref support.");

        if (query_interface(id, object, std::false_type{}) == S_OK)
        {
            return S_OK;
        }

        if (id == __uuidof(impl::IWeakReferenceSource))
        {
            *object = make_weak_ref();
            return*object ? S_OK : E_OUTOFMEMORY;
        }

        return E_NOINTERFACE;
    }

    HRESULT query_interface(GUID const& id, void** object, std::false_type) noexcept
    {
        *object = find_interface<impl::uncloak_t<I> ...>(id);

        if (*object != nullptr)
        {
            AddRef();
            return S_OK;
        }

        if (is_agile::value)
        {
            if (id == __uuidof(IAgileObject) || id == __uuidof(IMarshal))
            {
                *object = this->find_marshal();
                AddRef();
                return S_OK;
            }
        }

        if (is_inspectable::value)
        {
            if (id == __uuidof(::IInspectable))
            {
                *object = find_inspectable<I ...>();
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

        return E_NOINTERFACE;
    }

    uint32_t add_reference(std::false_type) noexcept
    {
        return 1 + m_references.fetch_add(1, std::memory_order_relaxed);
    }

    uint32_t subtract_reference(std::false_type) noexcept
    {
        return m_references.fetch_sub(1, std::memory_order_release) - 1;
    }

    uint32_t add_reference(std::true_type) noexcept
    {
        static_assert(is_weak_ref_source::value, "This is only for weak ref support.");
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

    uint32_t subtract_reference(std::true_type) noexcept
    {
        static_assert(is_weak_ref_source::value, "This is only for weak ref support.");
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

    impl::IWeakReferenceSource* make_weak_ref() noexcept
    {
        static_assert(is_weak_ref_source::value, "This is only for weak ref support.");
        uintptr_t count_or_pointer = m_references.load(std::memory_order_relaxed);

        if (is_weak_ref(count_or_pointer))
        {
            return decode_weak_ref(count_or_pointer)->get_source();
        }

        com_ptr<weak_ref_t> weak_ref;
        *put_abi(weak_ref) = new (std::nothrow) weak_ref_t(get_unknown(), static_cast<uint32_t>(count_or_pointer));

        if (!weak_ref)
        {
            return nullptr;
        }

        uintptr_t const encoding = encode_weak_ref(get_abi(weak_ref));

        while (true)
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

    template <int = 0>
    static constexpr uint32_t uncloaked_interfaces() noexcept
    {
        return 0;
    }

    template <typename First, typename ... Rest>
    static constexpr uint32_t uncloaked_interfaces() noexcept
    {
        return !impl::is_cloaked_v<First> +uncloaked_interfaces<Rest ...>();
    }

    template <int = 0>
    void copy_guids(GUID*) const noexcept
    {
    }

    template <typename First, typename ... Rest>
    void copy_guids(GUID* ids, std::enable_if_t<impl::is_cloaked_v<First>>* = nullptr) const noexcept
    {
        copy_guids<Rest ...>(ids);
    }

    template <typename First, typename ... Rest>
    void copy_guids(GUID* ids, std::enable_if_t<!impl::is_cloaked_v<First>>* = nullptr) const noexcept
    {
        *ids++ = impl::guid_v<First>;
        copy_guids<Rest ...>(ids);
    }

    template <int = 0>
    ::IInspectable* find_inspectable() const noexcept
    {
        return nullptr;
    }

    template <typename First, typename ... Rest>
    ::IInspectable* find_inspectable(std::enable_if_t<std::is_base_of_v<::IInspectable, abi_t<First>>>* = nullptr) const noexcept
    {
        return to_abi<First>(this);
    }

    template <typename First, typename ... Rest>
    ::IInspectable* find_inspectable(std::enable_if_t<!std::is_base_of_v<::IInspectable, abi_t<First>>>* = nullptr) const noexcept
    {
        return find_inspectable<Rest ...>();
    }

    template <int = 0>
    void* find_interface(GUID const&) const noexcept
    {
        return nullptr;
    }

    template <typename First, typename ... Rest>
    void* find_interface(GUID const& id, std::enable_if_t<std::is_base_of_v<impl::marker, First>>* = nullptr) const noexcept
    {
        return find_interface<Rest ...>(id);
    }

    template <typename First, typename ... Rest>
    void* find_interface(GUID const& id, std::enable_if_t<!std::is_base_of_v<impl::marker, First>>* = nullptr) const noexcept
    {
        if (id == impl::guid_v<First>)
        {
            return to_abi<First>(this);
        }

        return find_interface<Rest ...>(id);
    }

    ::IUnknown* get_unknown() const noexcept
    {
        return to_abi<first_interface>(this);
    }

    hstring GetRuntimeClassName() const
    {
        return impl::string_data(impl::name_v<first_interface>);
    }

    TrustLevel GetTrustLevel() const noexcept
    {
        return BaseTrust;
    }

    template <typename D, typename I>
    friend struct impl::produce_base;

    template <typename D, typename I>
    friend struct impl::produce;
};
