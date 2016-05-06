
namespace impl {

template <typename T, typename Enable = void>
struct accessors
{
    static T get(const T & object) noexcept
    {
        return object;
    }

    static T * put(T & object) noexcept
    {
        return &object;
    }

    static void copy_from(T & object, const T & value) noexcept
    {
        object = value;
    }

    static void copy_to(const T & object, T & value) noexcept
    {
        value = object;
    }

    static T detach(T & object) noexcept
    {
        return object;
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
