
struct non_agile {};

template <typename Interface>
struct cloaked : Interface {};

namespace impl {

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
struct is_cloaked : std::conditional_t<std::is_base_of_v<ABI::Windows::IInspectable, abi<I>>, std::false_type, std::true_type> {};

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
    using type = std::conditional_t<std::is_same<non_agile, First>::value, typename first_interface<Rest ...>::type, First>;
};

template <typename D, typename I>
struct produce;

template <typename D, typename I, typename Enable = void>
struct producer;

template <typename T>
class has_composable
{
    template <typename U> static constexpr bool get_value(typename U::composable *) { return true; }
    template <typename>   static constexpr bool get_value(...) { return false; }

public:

    static constexpr bool value = get_value<T>(0);
};

template <typename T>
void clear_abi(T *) noexcept
{}

template <typename T>
void clear_abi(T ** value) noexcept
{
    *value = nullptr;
}

}

template <typename D, typename I>
D * to_impl(const I & from) noexcept
{
    return &static_cast<impl::produce<D, I> *>(get(from))->shim();
}

template <typename I, typename D>
abi<I> * to_abi(impl::producer<D, I> const * from) noexcept
{
    return reinterpret_cast<abi<I> *>(const_cast<impl::producer<D, I> *>(from));
}

template <typename D, typename I = typename D::first_interface, typename ... Args, std::enable_if_t<!impl::has_composable<D>::value> * = nullptr>
auto make(Args && ... args)
{
    std::conditional_t<std::is_base_of_v<Windows::IUnknown, I>, I, com_ptr<I>> instance = nullptr;
    *put(instance) = to_abi<I>(new D(std::forward<Args>(args) ...));
    return instance;
}

template <typename D, typename I = typename D::first_interface, typename ... Args, std::enable_if_t<impl::has_composable<D>::value> * = nullptr>
auto make(Args && ... args)
{
    com_ptr<I> instance;
    *put(instance) = new D(std::forward<Args>(args) ...);
    return instance.template as<typename D::composable>();
}

template <typename D, typename ... Args>
auto make_self(Args && ... args)
{
    com_ptr<D> instance;
    *put(instance) = new D(std::forward<Args>(args) ...);
    return instance;
}

namespace impl {

template <typename D, typename I, typename H>
auto make_delegate(H && handler)
{
    I instance = nullptr;
    *put(instance) = to_abi<abi<I>>(new D(std::forward<H>(handler)));
    return instance;
}

template <typename D, typename I, typename Enable>
struct producer
{
    operator I() const noexcept
    {
        I result = nullptr;
        copy_from(result, const_cast<produce<D, I> *>(&vtable));
        return result;
    }

private:

    produce<D, I> vtable;
};

template <typename D, typename I>
struct produce_base : abi<I>
{
    D & shim() noexcept
    {
        return *static_cast<D *>(reinterpret_cast<producer<D, I> *>(this));
    }

    HRESULT __stdcall QueryInterface(const GUID & id, void ** object) noexcept override
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

    WINRT_IGNORE_MISSING_OVERRIDE_BEGIN

    HRESULT __stdcall abi_GetIids(uint32_t * count, GUID ** array) noexcept
    {
        return shim().abi_GetIids(count, array);
    }

    HRESULT __stdcall abi_GetRuntimeClassName(HSTRING * name) noexcept
    {
        return shim().abi_GetRuntimeClassName(name);
    }

    HRESULT __stdcall abi_GetTrustLevel(Windows::TrustLevel * trustLevel) noexcept
    {
        return shim().abi_GetTrustLevel(trustLevel);
    }

    WINRT_IGNORE_MISSING_OVERRIDE_END
};

template <typename D, typename I>
struct producer<D, I, std::enable_if_t<std::is_base_of< ::IUnknown, I>::value>> : produce_base<D, I>
{};

template <typename D>
struct producer<D, non_agile>
{};

template <typename D>
struct produce<D, Windows::IUnknown> : produce_base<D, Windows::IUnknown>
{};

template <typename D>
struct produce<D, Windows::IInspectable> : produce_base<D, Windows::IInspectable>
{};

}

template <typename D, typename ... I>
struct implements : impl::producer<D, impl::uncloak_t<I>> ...
{
    using first_interface = typename impl::first_interface<impl::uncloak_t<I> ...>::type;

    operator Windows::IInspectable() const noexcept
    {
        Windows::IInspectable result;
        copy_from(result, find_inspectable<I ...>());
        return result;
    }

protected:

    HRESULT QueryInterface(const GUID & id, void ** object) const noexcept
    {
        *object = find_interface<impl::uncloak_t<I> ...>(id);

        if (*object == nullptr)
        {
            if (id == __uuidof(::IUnknown))
            {
                *object = get_unknown();
            }
            else if (is_inspectable<I ...>() && id == __uuidof(ABI::Windows::IInspectable))
            {
                *object = find_inspectable<I ...>();
            }
            else if (!is_non_agile<I ...>())
            {
                if (id == __uuidof(IAgileObject))
                {
                    *object = get_unknown();
                }
                else if (id == __uuidof(IMarshal))
                {
                    com_ptr< ::IUnknown> marshaler;

                    const HRESULT hr = CoCreateFreeThreadedMarshaler(get_unknown(),
                                                                     put(marshaler));

                    if (hr != S_OK)
                    {
                        return hr;
                    }

                    return marshaler->QueryInterface(id, object);
                }
            }

            if (*object == nullptr)
            {
                return E_NOINTERFACE;
            }
        }

        static_cast< ::IUnknown *>(*object)->AddRef();
        return S_OK;
    }

    unsigned long __stdcall AddRef() noexcept
    {
        return 1 + m_references.fetch_add(1, std::memory_order_relaxed);
    }

    unsigned long __stdcall Release() noexcept
    {
        const uint32_t remaining = m_references.fetch_sub(1, std::memory_order_release) - 1;

        if (remaining == 0)
        {
            std::atomic_thread_fence(std::memory_order_acquire);
            delete static_cast<D *>(this);
        }

        return remaining;
    }

    HRESULT abi_GetIids(uint32_t * count, GUID ** array) const noexcept
    {
        *count = uncloaked_interfaces<I ...>();

        if (*count == 0)
        {
            *array = nullptr;
            return S_OK;
        }

        *array = static_cast<GUID *>(CoTaskMemAlloc(sizeof(GUID) * *count));

        if (*array == nullptr)
        {
            return E_OUTOFMEMORY;
        }

        copy_guids<I ...>(*array);
        return S_OK;
    }

    HRESULT __stdcall abi_GetRuntimeClassName(HSTRING * name) noexcept
    {
        try
        {
            *name = detach(static_cast<D *>(this)->GetRuntimeClassName());
            return S_OK;
        }
        catch (...) { return impl::to_hresult(); }
    }

    HRESULT __stdcall abi_GetTrustLevel(Windows::TrustLevel * trustLevel) noexcept
    {
        try
        {
            *trustLevel = static_cast<D *>(this)->GetTrustLevel();
            return S_OK;
        }
        catch (...) { return impl::to_hresult(); }
    }

private:

    template <int = 0>
    static constexpr uint32_t uncloaked_interfaces() noexcept
    {
        return 0;
    }

    template <typename First, typename ... Rest>
    static constexpr uint32_t uncloaked_interfaces() noexcept
    {
        return !impl::is_cloaked_v<First> + uncloaked_interfaces<Rest ...>();
    }

    template <int = 0>
    void copy_guids(GUID *) const noexcept
    {
    }

    template <typename First, typename ... Rest>
    void copy_guids(GUID * ids, std::enable_if_t<impl::is_cloaked_v<First>> * = nullptr) const noexcept
    {
        copy_guids<Rest ...>(ids);
    }

    template <typename First, typename ... Rest>
    void copy_guids(GUID * ids, std::enable_if_t<!impl::is_cloaked_v<First>> * = nullptr) const noexcept
    {
        *ids++ = __uuidof(abi<First>);
        copy_guids<Rest ...>(ids);
    }

    template <int = 0>
    static constexpr bool is_inspectable() noexcept
    {
        return false;
    }

    template <typename First, typename ... Rest>
    static constexpr bool is_inspectable() noexcept
    {
        return std::is_base_of_v<ABI::Windows::IInspectable, abi<First>> || is_inspectable<Rest ...>();
    }

    template <int = 0>
    static constexpr bool is_non_agile() noexcept
    {
        return false;
    }

    template <typename First, typename ... Rest>
    static constexpr bool is_non_agile() noexcept
    {
        return std::is_same_v<non_agile, First> || is_non_agile<Rest ...>();
    }

    template <int = 0>
    ABI::Windows::IInspectable * find_inspectable() const noexcept
    {
        return nullptr;
    }

    template <typename First, typename ... Rest>
    ABI::Windows::IInspectable * find_inspectable(std::enable_if_t<std::is_base_of_v<ABI::Windows::IInspectable, abi<First>>> * = nullptr) const noexcept
    {
        return to_abi<First>(this);
    }

    template <typename First, typename ... Rest>
    ABI::Windows::IInspectable * find_inspectable(std::enable_if_t<!std::is_base_of_v<ABI::Windows::IInspectable, abi<First>>> * = nullptr) const noexcept
    {
        return find_inspectable<Rest ...>();
    }

    template <int = 0>
    void * find_interface(const GUID &) const noexcept
    {
        return nullptr;
    }

    template <typename First, typename ... Rest>
    void * find_interface(const GUID & id, std::enable_if_t<std::is_same_v<non_agile, First>> * = nullptr) const noexcept
    {
        return find_interface<Rest ...>(id);
    }

    template <typename First, typename ... Rest>
    void * find_interface(const GUID & id, std::enable_if_t<!std::is_same_v<non_agile, First>> * = nullptr) const noexcept
    {
        if (id == __uuidof(abi<First>))
        {
            return to_abi<First>(this);
        }

        return find_interface<Rest ...>(id);
    }

    ::IUnknown * get_unknown() const noexcept
    {
        return to_abi<first_interface>(this);
    }

    hstring GetRuntimeClassName() const
    {
        throw hresult_not_implemented();
    }

    Windows::TrustLevel GetTrustLevel() const noexcept
    {
        return Windows::TrustLevel::BaseTrust;
    }

    template <typename D, typename I>
    friend struct impl::produce_base;

    std::atomic<uint32_t> m_references { 1 };
};
