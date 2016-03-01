
namespace winrt {

namespace impl {

template <typename T>
class no_ref : public T
{
	unsigned long __stdcall AddRef();
	unsigned long __stdcall Release();
};

}

template <typename T>
struct com_ptr
{
	using type = T;

	com_ptr() noexcept = default;

	com_ptr(com_ptr const & other) noexcept :
		m_ptr(other.m_ptr)
	{
		impl_addref();
	}

	template <typename T>
	com_ptr(com_ptr<T> const & other) noexcept :
		m_ptr(other.m_ptr)
	{
		impl_addref();
	}

	template <typename T>
	com_ptr(com_ptr<T> && other) noexcept :
		m_ptr(other.m_ptr)
	{
		other.m_ptr = nullptr;
	}

	~com_ptr() noexcept
	{
		impl_release();
	}

	com_ptr & operator=(com_ptr const & other) noexcept
	{
		impl_copy(other.m_ptr);
		return *this;
	}

	template <typename T>
	com_ptr & operator=(com_ptr<T> const & other) noexcept
	{
		impl_copy(other.m_ptr);
		return *this;
	}

	template <typename T>
	com_ptr & operator=(com_ptr<T> && other) noexcept
	{
		impl_move(other);
		return *this;
	}

	explicit operator bool() const noexcept
	{
		return nullptr != m_ptr;
	}

	impl::no_ref<T> * operator->() const noexcept
	{
		return static_cast<impl::no_ref<T> *>(m_ptr);
	}

	friend T * impl_get(com_ptr const & object) noexcept
	{
		return object.m_ptr;
	}

	friend T ** impl_put(com_ptr & object) noexcept
	{
		WINRT_ASSERT(object.m_ptr == nullptr);
		return &object.m_ptr;
	}

	friend T * impl_detach(com_ptr & object) noexcept
	{
		T * temp = object.m_ptr;
		object.m_ptr = nullptr;
		return temp;
	}

	friend void swap(com_ptr & left, com_ptr & right) noexcept
	{
		std::swap(left.m_ptr, right.m_ptr);
	}

	com_ptr & operator=(std::nullptr_t) noexcept
	{
		impl_release();
		return *this;
	}

	template <typename T>
	com_ptr<T> as() const noexcept
	{
		com_ptr<T> temp;
		m_ptr->QueryInterface(put(temp));
		return temp;
	}

	void copy_from(T * other) noexcept
	{
		impl_copy(other);
	}

	void copy_to(T ** other) const noexcept
	{
		impl_addref();
		*other = m_ptr;
	}

private:

	void impl_copy(T * other) noexcept
	{
		if (m_ptr != other)
		{
			impl_release();
			m_ptr = other;
			impl_addref();
		}
	}

	template <typename T>
	void impl_move(com_ptr<T> & other) noexcept
	{
		if (m_ptr != other.m_ptr)
		{
			impl_release();
			m_ptr = other.m_ptr;
			other.m_ptr = nullptr;
		}
	}

	void impl_addref() const noexcept
	{
		if (m_ptr)
		{
			m_ptr->AddRef();
		}
	}

	void impl_release() noexcept
	{
		T * temp = m_ptr;

		if (temp)
		{
			m_ptr = nullptr;
			temp->Release();
		}
	}

	template <typename T>
	friend struct com_ptr;

	T * m_ptr = nullptr;
};

}

namespace winrt { namespace impl {

template <typename T>
struct accessors<com_ptr<T>>
{
	static T * get(com_ptr<T> const & object) noexcept
	{
		return impl_get(object);
	}

	static T ** put(com_ptr<T> & object) noexcept
	{
		return impl_put(object);
	}

	static void attach(com_ptr<T> & object, T * value) noexcept
	{
		object = nullptr;
		*put(object) = value;
	}

	static void copy_from(com_ptr<T> & object, T * value)
	{
		object = nullptr;

		if (value)
		{
			value->AddRef();
			*put(object) = value;
		}
	}

	static void copy_to(com_ptr<T> const & object, T * & value)
	{
		if (object)
		{
			value = get(object);
			value->AddRef();
		}
		else
		{
			value = nullptr;
		}
	}

	static T * detach(com_ptr<T> & object) noexcept
	{
		return impl_detach(object);
	}
};

}}

namespace winrt {

template <typename T>
bool operator==(com_ptr<T> const & left, com_ptr<T> const & right) noexcept
{
	return get(left) == get(right);
}

template <typename T>
bool operator!=(com_ptr<T> const & left, com_ptr<T> const & right) noexcept
{
	return !(left == right);
}

template <typename T>
bool operator<(com_ptr<T> const & left, com_ptr<T> const & right) noexcept
{
	return get(left) < get(right);
}

template <typename T>
bool operator>(com_ptr<T> const & left, com_ptr<T> const & right) noexcept
{
	return right < left;
}

template <typename T>
bool operator<=(com_ptr<T> const & left, com_ptr<T> const & right) noexcept
{
	return !(right < left);
}

template <typename T>
bool operator>=(com_ptr<T> const & left, com_ptr<T> const & right) noexcept
{
	return !(left < right);
}

}
