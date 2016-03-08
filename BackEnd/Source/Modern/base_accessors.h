
namespace winrt {

namespace impl {

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

	static void copy_from(T & object, T const & value) noexcept
	{
		object = value;
	}

	static void copy_to(T const & object, T & value) noexcept
	{
		value = object;
	}

	static T detach(T & object) noexcept
	{
		return object;
	}

	static T const & lease(T const & object) noexcept
	{
		return object;
	}
};

struct bool_proxy
{
	bool_proxy & operator=(bool_proxy const &) = delete;

	bool_proxy(bool & value) noexcept :
		m_value(value)
	{}

	~bool_proxy() noexcept
	{
		m_value = false != m_value;
	}

	operator bool * () noexcept
	{
		return &m_value;
	}

private:

	bool & m_value;
};

template <>
struct accessors<bool>
{
	static bool_proxy put(bool & object) noexcept
	{
		return bool_proxy(object);
	}

	static bool detach(bool object) noexcept
	{
		return object;
	}
};

}

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
void copy_to(T const & object, V & value)
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

template <typename T, typename V>
auto lease(V && object) noexcept
{
	return impl::accessors<T>::lease(object);
}

}
