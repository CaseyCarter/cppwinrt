
namespace winrt { namespace impl {

template <typename T, typename Enable = void>
struct accessors
{
	static T get(T const & object) noexcept
	{
		return object;
	}

	static T * put(T & object) noexcept
	{
		return &object;
	}

	static void attach(T & object, T const & value) noexcept
	{
		object = value;
	}

	static void copy(T & object, T const & value) noexcept
	{
		object = value;
	}

	static T detach(T & object) noexcept
	{
		return object;
	}
};

}}

namespace winrt {

template <typename T>
auto get(T const & object) noexcept
{
	return impl::accessors<T>::get(object);
}

template <typename T>
auto put(T & object) noexcept
{
	return impl::accessors<T>::put(object);
}

template <typename T, typename V>
void attach(T & object, V && value) noexcept
{
	impl::accessors<T>::attach(object, value);
}

template <typename T, typename V>
void copy(T & object, V && value) noexcept
{
	impl::accessors<T>::copy(object, value);
}

template <typename T>
auto detach(T & object) noexcept
{
	return impl::accessors<T>::detach(object);
}

template <typename T>
auto detach(T && object) noexcept
{
	return impl::accessors<T>::detach(object);
}

}
