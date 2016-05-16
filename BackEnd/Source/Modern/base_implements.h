
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

template <typename T, typename Interface, typename Enable = void>
struct derive_from : abi<uncloak_t<Interface>> {};

template <typename T, typename Interface>
struct derive_from<T, Interface, std::enable_if_t<can_produce<uncloak_t<Interface>>::value>> : traits<uncloak_t<Interface>>::template produce<T> {};

}

template <typename T, typename ... Interfaces>
class __declspec(novtable) implements : public impl::derive_from<T, Interfaces> ...
{
    template <typename Interface>
    struct is_cloaked : std::conditional_t<std::is_base_of_v<ABI::Windows::IInspectable, abi<Interface>>, std::false_type, std::true_type> {};

    template <typename Interface>
    struct is_cloaked<cloaked<Interface>> : std::true_type {};

    template <typename First, typename ... Rest>
    struct first
    {
        using type = impl::uncloak_t<First>;
    };

    template <int = 0>
    constexpr uint32_t uncloaked_interfaces() const noexcept
    {
        return 0;
    }

    template <typename First, typename ... Rest>
    constexpr uint32_t uncloaked_interfaces() const noexcept
    {
        return !is_cloaked<First>::value + uncloaked_interfaces<Rest ...>();
    }

    template <int = 0>
    void copy_interfaces(GUID *) const noexcept {}

    template <typename First, typename ... Rest>
    void copy_interfaces(GUID * ids, std::enable_if_t<is_cloaked<First>::value> * = nullptr) const noexcept
    {
        copy_interfaces<Rest ...>(ids);
    }

    template <typename First, typename ... Rest>
    void copy_interfaces(GUID * ids, std::enable_if_t<!is_cloaked<First>::value> * = nullptr) const noexcept
    {
        *ids++ = __uuidof(abi<First>);
        copy_interfaces<Rest ...>(ids);
    }

    template <int = 0>
    constexpr bool is_inspectable() const noexcept
    {
        return false;
    }

    template <typename First, typename ... Rest>
    constexpr bool is_inspectable() const noexcept
    {
        return std::is_base_of_v<ABI::Windows::IInspectable, abi<impl::uncloak_t<First>>> || is_inspectable<Rest ...>();
    }

    template <typename First, typename ... Rest>
    auto find_unknown() const noexcept
    {
        return impl::abi_cast<impl::uncloak_t<First>>(this);
    }

    template <int = 0>
    auto find_inspectable() const noexcept
    {
        return nullptr;
    }

    template <typename First, typename ... Rest>
    auto find_inspectable(std::enable_if_t<std::is_base_of_v<ABI::Windows::IInspectable, abi<impl::uncloak_t<First>>>> * = nullptr) const noexcept
    {
        return impl::abi_cast<impl::uncloak_t<First>>(this);
    }

    template <typename First, typename ... Rest>
    auto find_inspectable(std::enable_if_t<!std::is_base_of_v<ABI::Windows::IInspectable, abi<impl::uncloak_t<First>>>> * = nullptr) const noexcept
    {
        return find_inspectable<Rest ...>();
    }

    template <int = 0>
    void * find_interface(const GUID &) const noexcept
    {
        return nullptr;
    }

    template <typename First, typename ... Rest>
    void * find_interface(const GUID & id) const noexcept
    {
        if (id == __uuidof(abi<impl::uncloak_t<First>>))
        {
            return impl::abi_cast<impl::uncloak_t<First>>(this);
        }

        return find_interface<Rest ...>(id);
    }

protected:

    std::atomic<uint32_t> m_references{1};

    implements() noexcept = default;

    void * query_interface(const GUID & id) noexcept
    {
        if (id == __uuidof(IUnknown) || id == __uuidof(::IAgileObject))
        {
            return find_unknown<Interfaces ...>();
        }

        if (is_inspectable<Interfaces ...>() && id == __uuidof(ABI::Windows::IInspectable))
        {
            return find_inspectable<Interfaces ...>();
        }

        return find_interface<Interfaces ...>(id);
    }

public:

    using default_interface = typename first<Interfaces ...>::type;

    implements(const implements &) = delete;
    implements & operator=(const implements &) = delete;

    auto impl_unknown() const noexcept
    {
        return static_cast<IUnknown *>(find_unknown<Interfaces ...>());
    }

    operator Windows::IUnknown() const noexcept
    {
        return impl::winrt_cast<Windows::IUnknown>(static_cast<IUnknown *>(find_unknown<Interfaces ...>()));
    }

    operator Windows::IInspectable() const noexcept
    {
        return impl::winrt_cast<Windows::IInspectable>(static_cast<ABI::Windows::IInspectable *>(find_inspectable<Interfaces ...>()));
    }

    HRESULT __stdcall QueryInterface(const GUID & id, void ** object) noexcept override
    {
        *object = query_interface(id);

        if (*object == nullptr)
        {
            return E_NOINTERFACE;
        }

        static_cast<IUnknown *>(*object)->AddRef();
        return S_OK;
    }

    unsigned long __stdcall AddRef() noexcept override
    {
        return 1 + m_references.fetch_add(1, std::memory_order_relaxed);
    }

    unsigned long __stdcall Release() noexcept override
    {
        const uint32_t remaining = m_references.fetch_sub(1, std::memory_order_release) - 1;

        if (remaining == 0)
        {
            std::atomic_thread_fence(std::memory_order_acquire);
            delete static_cast<T *>(this);
        }

        return remaining;
    }

    hstring RuntimeClassName()
    {
        throw hresult_not_implemented();
    }

    HRESULT __stdcall get_RuntimeClassName(HSTRING * name) noexcept
    {
        try
        {
            *name = detach(static_cast<T *>(this)->RuntimeClassName());
            return S_OK;
        }
        catch (...) { return impl::to_hresult(); }
    }

    HRESULT __stdcall get_Iids(uint32_t * count, GUID ** array) noexcept
    {
        *count = 0;
        *array = nullptr;

        const uint32_t localCount = uncloaked_interfaces<Interfaces ...>();

        if (0 == localCount)
        {
            return S_OK;
        }

        GUID * localArray = static_cast<GUID *>(CoTaskMemAlloc(sizeof(GUID) * localCount));

        if (nullptr == localArray)
        {
            return E_OUTOFMEMORY;
        }

        copy_interfaces<Interfaces ...>(localArray);

        *count = localCount;
        *array = localArray;
        return S_OK;
    }

    HRESULT __stdcall get_TrustLevel(Windows::TrustLevel * trustLevel) noexcept
    {
        *trustLevel = Windows::TrustLevel::BaseTrust;
        return S_OK;
    }
};
