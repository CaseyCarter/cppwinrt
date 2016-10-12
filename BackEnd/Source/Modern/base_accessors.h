
namespace impl {

template <typename T>
struct traits
{
    using abi = T;
};

}

template <typename T>
using abi = typename impl::traits<T>::abi;

namespace impl {

template <typename T, typename Enable = void>
struct accessors
{
    static abi<T> get(const T & object) noexcept
    {
        return reinterpret_cast<const abi<T> &>(object);
    }

    static abi<T> * put(T & object) noexcept
    {
        return reinterpret_cast<abi<T> *>(&object);
    }

    static void copy_from(T & object, const abi<T> & value) noexcept
    {
        object = reinterpret_cast<const T &>(value);
    }

    static void copy_to(const T & object, abi<T> & value) noexcept
    {
        reinterpret_cast<T &>(value) = object;
    }

    static abi<T> detach(T & object) noexcept
    {
        abi<T> result {};
        reinterpret_cast<T &>(result) = std::move(object);
        return result;
    }
};

}

template <typename T>
auto get(const T & object) noexcept
{
    return impl::accessors<T>::get(object);
}

template <typename T>
auto put(T & object) noexcept
{
    return impl::accessors<T>::put(object);
}

template <typename T>
auto put_size(T & object) noexcept
{
    return impl::accessors<T>::put_size(object);
}

template <typename T, typename V>
void attach(T & object, V && value) noexcept
{
    impl::accessors<T>::attach(object, value);
}

template <typename T, typename V>
void copy_from(T & object, V && value)
{
    impl::accessors<T>::copy_from(object, value);
}

template <typename T, typename V>
void copy_to(const T & object, V & value)
{
    impl::accessors<T>::copy_to(object, value);
}

template <typename T>
auto detach(T & object)
{
    return impl::accessors<std::decay_t<T>>::detach(object);
}

template <typename T>
auto detach(T && object)
{
    return impl::accessors<T>::detach(object);
}
