
namespace winrt::impl
{
    template <typename T>
    struct identity
    {
        using type = T;
    };

    template <typename T, typename Enable = void>
    struct abi
    {
        using type = T;
    };

    template <typename T>
    using abi_t = typename abi<T>::type;

    template <typename T>
    struct consume;

    template <typename D, typename I = D>
    using consume_t = typename consume<I>::template type<D>;

    template <typename T>
    struct delegate;

    template <typename T, typename H>
    using delegate_t = typename delegate<T>::template type<H>;

    template <typename D, typename I>
    struct produce;

    template <typename T>
    struct default_interface
    {
        using type = T;
    };

    template <typename T>
    using default_interface_t = typename default_interface<T>::type;

    template <typename T>
    struct category;

    template <typename T>
    using category_t = typename category<T>::type;

    struct basic_category;
    struct interface_category;
    struct delegate_category;
    struct enum_category;
    struct class_category;

    template <typename... Args>
    struct pinterface_category;

    template <typename... Fields>
    struct struct_category;

    template <typename Category, typename T>
    struct category_signature;

    template <typename T>
    struct signature
    {
        static constexpr auto data{ category_signature<typename category<T>::type, T>::data };
    };

    template <typename T>
    struct guid
    {
        static constexpr GUID value = __uuidof(T);
    };

#ifdef __clang__
    template <typename T>
    constexpr GUID const guid_v = guid<default_interface_t<T>>::value;
#endif

    template <uint32_t Size>
    struct struct_base
    {
        uint8_t padding[Size];
    };

    template <uint32_t Size32, uint32_t Size64 = Size32>
    using struct_of =
#ifdef WINRT_64
        struct_base<Size64>;
#else
        struct_base<Size32>;
#endif

    template <typename T>
    struct is_struct
    {
        static constexpr bool value{ false };
    };

    template <typename T>
    struct abi<T, std::enable_if_t<is_struct<T>::value>>
    {
        using type = struct_of<sizeof(T)>;
    };

    template <typename T>
    struct is_enum_flag : std::false_type {};

    template <typename T>
    constexpr bool is_enum_flag_v = is_enum_flag<T>::value;

    template <typename T>
    constexpr auto to_underlying_type(T const value) noexcept
    {
        return static_cast<std::underlying_type_t<T>>(value);
    }
}

template <typename T>
constexpr auto operator|(T const left, T const right) noexcept -> std::enable_if_t<winrt::impl::is_enum_flag_v<T>, T>
{
    return static_cast<T>(winrt::impl::to_underlying_type(left) | winrt::impl::to_underlying_type(right));
}

template <typename T>
constexpr auto operator|=(T& left, T const right) noexcept -> std::enable_if_t<winrt::impl::is_enum_flag_v<T>, T>
{
    left = left | right;
    return left;
}

template <typename T>
constexpr auto operator&(T const left, T const right) noexcept -> std::enable_if_t<winrt::impl::is_enum_flag_v<T>, T>
{
    return static_cast<T>(winrt::impl::to_underlying_type(left) & winrt::impl::to_underlying_type(right));
}

template <typename T>
constexpr auto operator&=(T& left, T const right) noexcept -> std::enable_if_t<winrt::impl::is_enum_flag_v<T>, T>
{
    left = left & right;
    return left;
}

template <typename T>
constexpr auto operator~(T const value) noexcept -> std::enable_if_t<winrt::impl::is_enum_flag_v<T>, T>
{
    return static_cast<T>(~winrt::impl::to_underlying_type(value));
}

template <typename T>
constexpr auto operator^(T const left, T const right) noexcept -> std::enable_if_t<winrt::impl::is_enum_flag_v<T>, T>
{
    return static_cast<T>(winrt::impl::to_underlying_type(left) ^ winrt::impl::to_underlying_type(right));
}

template <typename T>
constexpr auto operator^=(T& left, T const right) noexcept -> std::enable_if_t<winrt::impl::is_enum_flag_v<T>, T>
{
    left = left ^ right;
    return left;
}

WINRT_EXPORT namespace winrt
{
    template <typename T>
    constexpr GUID const& guid_of() noexcept
    {
#ifdef __clang__
        return impl::guid_v<T>;
#else
        return impl::guid<impl::default_interface_t<T>>::value;
#endif
    }

    struct event_token;
}

namespace winrt::impl
{
    template <typename D, typename I>
    struct require_one : consume_t<D, I>
    {
        operator I() const noexcept
        {
            D const& d = *static_cast<D const*>(this);

            if (d)
            {
                return d.template try_as<I>();
            }

            return nullptr;
        }
    };

    template <typename D, typename... I>
    struct WINRT_EBO require : require_one<D, I>...
    {};

    template <typename D, typename I>
    struct base_one
    {
        operator I() const noexcept
        {
            D const& d = *static_cast<D const*>(this);

            if (d)
            {
                return d.template try_as<I>();
            }

            return nullptr;
        }
    };

    template <typename D, typename... I>
    struct WINRT_EBO base : base_one<D, I>...
    {};

    template <typename T>
    class no_ref : public T
    {
        unsigned long __stdcall AddRef() noexcept;
        unsigned long __stdcall Release() noexcept;
    };
}
