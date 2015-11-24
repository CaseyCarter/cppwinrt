
namespace Modern
{
	template <typename T, typename Enable = void>
	struct accessors;

	template <typename T>
	auto get(T const & object) noexcept
	{
		return accessors<T>::get(object);
	}

	template <typename T>
	auto put(T & object) noexcept
	{
		return accessors<T>::put(object);
	}

	template <typename T, typename V>
	void attach(T & object, V && value) noexcept
	{
		accessors<T>::attach(object, value);
	}

	template <typename T, typename V>
	void copy(T & object, V && value) noexcept
	{
		accessors<T>::copy(object, value);
	}

	template <typename T>
	auto detach(T & object) noexcept
	{
		return accessors<T>::detach(object);
	}

	template <typename T>
	struct accessors<T, typename std::enable_if<std::is_base_of<Windows::IUnknown, T>::value>::type>
	{
		static DefaultAbi<T> * get(T const & object) noexcept
		{
			return static_cast<DefaultAbi<T> *>(impl_get(object));
		}

		static DefaultAbi<T> ** put(T & object) noexcept
		{
			return reinterpret_cast<DefaultAbi<T> **>(impl_put(object));
		}

		static void attach(T & object, DefaultAbi<T> * value) noexcept
		{
			object = nullptr;
			*put(object) = value;
		}

		static void copy(T & object, DefaultAbi<T> * value) noexcept
		{
			object = nullptr;
			value->AddRef();
			*put(object) = value;
		}

		static DefaultAbi<T> * detach(T & object) noexcept
		{
			return static_cast<DefaultAbi<T> *>(impl_detach(object));
		}
	};

	template <>
	struct accessors<String>
	{
		static HSTRING get(String const & object) noexcept
		{
			return impl_get(object);
		}

		static HSTRING * put(String & object) noexcept
		{
			return impl_put(object);
		}

		static void attach(String & object, HSTRING value) noexcept
		{
			object = nullptr;
			*put(object) = value;
		}

		static void copy(String & object, HSTRING value)
		{
			object = nullptr;
			check(WindowsDuplicateString(value, put(object)));
		}

		static HSTRING detach(String & object) noexcept
		{
			return impl_detach(object);
		}
	};
}