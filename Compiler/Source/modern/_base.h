
#pragma once

namespace Modern {

enum class InitializeType
{
	SingleThreaded,
	MultiThreaded
};

inline void Initialize(InitializeType const type = InitializeType::MultiThreaded)
{
	check(RoInitialize(static_cast<RO_INIT_TYPE>(type)));
}

template <typename To>
struct Lease : To
{
	template <typename From>
	Lease(From value) noexcept : To(nullptr)
	{
		*put(*static_cast<To *>(this)) = value;
	}

	~Lease() noexcept
	{
		detach(*static_cast<To *>(this));
	}
};

template <typename T>
struct Traits
{
	using Abi = T;
};

template <typename T>
class HasDefault
{
	template <typename U> static constexpr bool Check(typename Traits<U>::Default *) { return true; }
	template <typename>   static constexpr bool Check(...) { return false; }

public:

	static constexpr bool Value = Check<T>(nullptr);
};

template <typename T>
class HasComposable
{
	template <typename U> static constexpr bool Check(typename U::Composable *) { return true; }
	template <typename>   static constexpr bool Check(...) { return false; }

public:

	static constexpr bool Value = Check<T>(nullptr);
};

template <typename T>
class HasGetAt
{
	template <typename U, typename = decltype(std::declval<U>().GetAt(0))> static constexpr bool Check(int) { return true;  }
	template <typename> static constexpr bool Check(...) { return false; }

public:

	static constexpr bool Value = Check<T>(0);
};

template <typename T>
using IsRandomAccess = typename std::enable_if<HasGetAt<T>::Value>::type *;

template <typename T>
using IsNotRandomAccess = typename std::enable_if<!HasGetAt<T>::Value>::type *;

template <typename T>
using IsComposable = typename std::enable_if<HasComposable<T>::Value>::type *;

template <typename T>
using IsNotComposable = typename std::enable_if<!HasComposable<T>::Value>::type *;

template <typename T>
using IsPod = typename std::enable_if<std::is_pod<T>::value>::type *;

template <typename T>
using IsNotPod = typename std::enable_if<!std::is_pod<T>::value>::type *;

template <typename T>
using Abi = typename Traits<T>::Abi;

template <typename T>
using AbiPtr = NoAddRefRelease<Abi<T>> *;

template <typename T, typename Enable = void>
struct LookupDefaultAbi
{
	using Type = Abi<T>;
};

template <typename T>
struct LookupDefaultAbi<T, typename std::enable_if<HasDefault<T>::Value>::type>
{
	using Type = Abi<typename Traits<T>::Default>;
};

template <typename T>
using DefaultAbi = typename LookupDefaultAbi<T>::Type;


template <typename T, typename Enable = void>
struct LookupDefault
{
	using Type = T;
};

template <typename T>
struct LookupDefault<T, typename std::enable_if<HasDefault<T>::Value>::type>
{
	using Type = typename Traits<T>::Default;
};

template <typename T>
using Default = typename LookupDefault<T>::Type;

template <typename T, IsPod<T> = nullptr>
T const & abi(T const & value) noexcept
{
	return value;
}

template <typename T, IsPod<T> = nullptr>
T * abi(T * value) noexcept
{
	return value;
}

template <typename T, IsNotPod<T> = nullptr>
auto abi(T const & value) noexcept
{
	return get(value);
}

template <typename T, IsNotPod<T> = nullptr>
auto abi(T * value) noexcept
{
	return put(*value);
}

template <typename To, typename From, IsPod<To> = nullptr>
To forward(From value) noexcept
{
	return value;
}

template <typename To, typename From, IsNotPod<To> = nullptr>
Lease<To> forward(From value) noexcept
{
	return Lease<To>(value);
}

template <typename First, typename ... Rest>
struct ImplementsDefault : 
	Implements<Abi<First>, Abi<Rest> ..., ::IAgileObject>
{
	using Default = First;
};

}

namespace Modern {

template <typename T, typename ... Args, IsNotComposable<T> = nullptr>
typename T::Default make(Args && ... args)
{
	typename T::Default instance;
	*put(instance) = new T(std::forward<Args>(args) ...);
	return instance;
}

template <typename T, typename ... Args, IsComposable<T> = nullptr>
typename T::Composable make(Args && ... args)
{
	Windows::IInspectable instance;
	*put(instance) = new T(std::forward<Args>(args) ...);
	return instance.As<T::Composable>();
}

}

namespace Modern { namespace ABI {

template <typename T>
struct Traits
{
	using Default = T;
};

template <typename T>
using Default = typename Traits<T>::Default;

template <typename T, typename Enable = void>
struct Argument
{
	using In = T;
	using Out = T *;
};

template <typename T>
struct Argument<T, typename std::enable_if<std::is_base_of<::IUnknown, T>::value>::type>
{
	using In = T *;
	using Out = T **;
};

template <typename T>
using ArgIn = typename Argument<Default<T>>::In;

template <typename T>
using ArgOut = typename Argument<Default<T>>::Out;

}}

namespace Modern {

template <typename T, typename Enable = void>
struct Argument
{
	static constexpr T Empty() noexcept
	{
		return {};
	}
};

template <typename T>
struct Argument<T, typename std::enable_if<std::is_base_of<Windows::IUnknown, T>::value>::type>
{
	static constexpr T Empty() noexcept
	{
		return nullptr;
	}
};

template <typename T>
using AbiArgIn = typename ABI::ArgIn<DefaultAbi<T>>;

template <typename T>
using AbiArgOut = typename ABI::ArgOut<DefaultAbi<T>>;

template <typename T, typename R>
struct impl_Requires : Traits<R>::template Methods<impl_Requires<T, R>>
{
	operator R() const noexcept
	{
		return static_cast<T const *>(this)->As<R>();
	}
};

template <typename T, typename ... R>
struct Requires : impl_Requires<T, R> ...
{};

template <typename T, typename B>
struct impl_Bases
{
	operator B() const noexcept
	{
		return static_cast<T const *>(this)->As<B>();
	}
};

template <typename T, typename ... B>
struct Bases : impl_Bases<T, B> ...
{};

template <typename ... R>
struct Overrides : Implements<R ...>
{
	template <typename T>
	T As() const
	{
		return m_inner.As<T>();
	}

	virtual HRESULT __stdcall QueryInterface(GUID const & id, void ** object) noexcept override
	{
		*object = BaseQueryInterface<R ...>(id);

		if (*object == nullptr)
		{
			return m_inner->QueryInterface(id, object);
		}

		static_cast<::IUnknown *>(*object)->AddRef();
		return S_OK;
	}

protected:

	Windows::IInspectable m_inner;
};

}

