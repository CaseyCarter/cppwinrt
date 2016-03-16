
namespace winrt {

template <typename T>
struct handle_traits
{
	using type = T;

	constexpr static type invalid() noexcept
	{
		return nullptr;
	}

	// static void close(type value) noexcept;
};

template <typename T>
struct handle
{
	using type = typename T::type;

	handle() noexcept = default;

	handle(type value) noexcept :
		m_value(value)
	{}

	handle(handle && other) noexcept :
		m_value(detach(other))
	{}

	handle & operator=(handle && other) noexcept
	{
		if (this != &other)
		{
			attach(*this, detach(other));
		}

		return *this;
	}

	~handle() noexcept
	{
		close();
	}

	void close() noexcept
	{
		if (*this)
		{
			T::close(m_value);
			m_value = T::invalid();
		}
	}

	explicit operator bool() const noexcept
	{
		return m_value != T::invalid();
	}

	friend type impl_get(handle const & handle) noexcept
	{
		return handle.m_value;
	}

	friend type * impl_put(handle & handle) noexcept
	{
		WINRT_ASSERT(!handle);
		return &handle.m_value;
	}

	friend type impl_detach(handle & handle) noexcept
	{
		type value = handle.m_value;
		handle.m_value = T::invalid();
		return value;
	}

	friend void swap(handle & left, handle & right) noexcept
	{
		std::swap(left, right);
	}

private:

	type m_value = T::invalid();
};

template <typename T>
bool operator==(handle<T> const & left, handle<T> const & right) noexcept
{
	return get(left) == get(right);
}

template <typename T>
bool operator!=(handle<T> const & left, handle<T> const & right) noexcept
{
	return !(left == right);
}

template <typename T>
bool operator<(handle<T> const & left, handle<T> const & right) noexcept
{
	return get(left) < get(right);
}

template <typename T>
bool operator>(handle<T> const & left, handle<T> const & right) noexcept
{
	return right < left;
}

template <typename T>
bool operator<=(handle<T> const & left, handle<T> const & right) noexcept
{
	return !(right < left);
}

template <typename T>
bool operator>=(handle<T> const & left, handle<T> const & right) noexcept
{
	return !(left < right);
}

}

namespace winrt { namespace impl {

template <typename T>
struct accessors<handle<T>>
{
	using type = typename handle<T>::type;

	static type get(handle<T> const & object) noexcept
	{
		return impl_get(object);
	}

	static type * put(handle<T> & object) noexcept
	{
		return impl_put(object);
	}

	static void attach(handle<T> & object, type value) noexcept
	{
		object.close();
		*put(object) = value;
	}

	static type detach(handle<T> & object) noexcept
	{
		return impl_detach(object);
	}
};

}}
