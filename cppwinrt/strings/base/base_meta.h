
namespace winrt::impl
{
    template <typename T>
    struct identity
    {
        using type = T;
    };

    template <typename T>
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
    struct name;

    template <typename T>
    constexpr auto & name_v = name<T>::value;

    template <typename T>
    struct category;

    template <typename T>
    using category_t = typename category<T>::type;

    struct basic_category;
    struct interface_category;
    struct delegate_category;
    struct enum_category;
    struct class_category;

    template <typename ... Args>
    struct pinterface_category;

    template <typename ... Fields>
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

    template <typename T, typename Enable = void>
    struct accessors
    {
        static abi_t<T> get(T const& object) noexcept
        {
            return reinterpret_cast<abi_t<T> const&>(object);
        }

        static abi_t<T>* put(T& object) noexcept
        {
            return reinterpret_cast<abi_t<T>*>(&object);
        }

        static void copy_from(T& object, abi_t<T> const& value) noexcept
        {
            object = reinterpret_cast<T const&>(value);
        }

        static void copy_to(T const& object, abi_t<T>& value) noexcept
        {
            reinterpret_cast<T&>(value) = object;
        }

        static abi_t<T> detach(T& object) noexcept
        {
            abi_t<T> result{};
            reinterpret_cast<T&>(result) = std::move(object);
            return result;
        }
    };

    template <typename T>
    auto put_size_abi(T& object) noexcept
    {
        return accessors<T>::put_size(object);
    }
}

WINRT_EXPORT namespace winrt
{
    template <typename T>
    using abi_t = impl::abi_t<T>;

    template <typename T>
    inline constexpr GUID const& guid_of() noexcept
    {
#ifdef __clang__
        return impl::guid_v<T>;
#else
        return impl::guid<impl::default_interface_t<T>>::value;
#endif
    }

    template <typename T>
    auto get_abi(T const& object) noexcept
    {
        return impl::accessors<T>::get(object);
    }

    template <typename T>
    auto put_abi(T& object) noexcept
    {
        return impl::accessors<T>::put(object);
    }

    template <typename T, typename V>
    void attach_abi(T& object, V&& value) noexcept
    {
        impl::accessors<T>::attach(object, value);
    }

    template <typename T, typename V>
    void copy_from_abi(T& object, V&& value)
    {
        impl::accessors<T>::copy_from(object, value);
    }

    template <typename T, typename V>
    void copy_to_abi(T const& object, V& value)
    {
        impl::accessors<T>::copy_to(object, value);
    }

    template <typename T>
    auto detach_abi(T& object)
    {
        return impl::accessors<std::decay_t<T>>::detach(object);
    }

    template <typename T>
    auto detach_abi(T&& object)
    {
        return impl::accessors<T>::detach(object);
    }
}

namespace winrt::impl
{
    template <typename D, typename I>
    struct require_one : consume_t<D, I>
    {
        operator I() const
        {
            D const& d = *static_cast<D const*>(this);

            if (d)
            {
                return d.template as<I>();
            }

            return nullptr;
        }
    };

    template <typename D, typename ... I>
    struct WINRT_EBO require : require_one<D, I> ...
    {};

    template <typename D, typename I>
    struct base_one
    {
        operator I() const
        {
            D const& d = *static_cast<D const*>(this);

            if (d)
            {
                return d.template as<I>();
            }

            return nullptr;
        }
    };

    template <typename D, typename ... I>
    struct WINRT_EBO base : base_one<D, I> ...
    {};

    template <typename T>
    class no_ref : public T
    {
        unsigned long __stdcall AddRef() noexcept;
        unsigned long __stdcall Release() noexcept;
    };
}
