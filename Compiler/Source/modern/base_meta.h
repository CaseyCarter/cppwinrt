
namespace winrt { namespace impl {

template <typename T>
struct traits
{
	using abi = T;
};

template <typename T>
class no_ref : public T
{
	unsigned long __stdcall AddRef();
	unsigned long __stdcall Release();
};

template <typename T>
class has_default_interface
{
	template <typename U> static constexpr bool check(typename traits<U>::default_interface *) { return true; }
	template <typename>   static constexpr bool check(...) { return false; }

public:

	static constexpr bool value = check<T>(nullptr);
};

template <typename T>
class has_GetAt
{
	template <typename U, typename = decltype(std::declval<U>().GetAt(0))> static constexpr bool check(int) { return true; }
	template <typename> static constexpr bool check(...) { return false; }

public:

	static constexpr bool value = check<T>(0);
};

template <typename V, typename T>
auto shim(T const * t)
{
	return static_cast<V const &>(static_cast<T const &>(*t));
}

template <typename T, typename Enable = void>
struct lookup_default_interface
{
	using type = T;
};

template <typename T>
struct lookup_default_interface<T, typename std::enable_if<has_default_interface<T>::Value>::type>
{
	using type = typename traits<T>::default_interface;
};

template <typename T, typename R>
struct requires : traits<R>::template methods<requires<T, R>>
{
	operator R() const noexcept
	{
		return static_cast<T const *>(this)->As<R>();
	}
};

}}

namespace winrt {

template <typename T>
using abi = typename impl::traits<T>::abi;

template <typename T>
auto ptr(::IUnknown * object) noexcept
{
	return static_cast<impl::no_ref<abi<T>> *>(object);
}

template <typename T>
using default_interface = typename impl::lookup_default_interface<T>::type;

template <typename T, typename ... R>
struct requires : impl::requires<T, R> ...
{};

}

namespace winrt { namespace impl {

template <typename First, typename ... Rest>
struct implements :
	winrt::implements<abi<First>, abi<Rest> ..., ::IAgileObject>
{
	using default_interface = First;
};

}}

namespace winrt { namespace ABI {

template <typename T>
struct traits
{
	using default_interface = T;
};

template <typename T>
using default_interface = typename traits<T>::default_interface;

template <typename T, typename Enable = void>
struct argument
{
	using in = T;
	using out = T *;
};

template <typename T>
struct argument<T, typename std::enable_if<std::is_base_of<::IUnknown, T>::value>::type>
{
	using in = T *;
	using out = T **;
};

template <typename T>
using argument_in = typename argument<default_interface<T>>::in;

template <typename T>
using argument_out = typename argument<default_interface<T>>::out;

}}
