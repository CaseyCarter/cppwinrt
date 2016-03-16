
namespace winrt { namespace ABI {

template <typename T>
struct traits
{
	using default_interface = T;
};

template <typename T>
using default_interface = typename traits<T>::default_interface;

template <typename T, typename Enable = void>
struct arg
{
	using in = T;
	using out = T *;
};

template <typename T>
struct arg<T, typename std::enable_if<std::is_base_of<::IUnknown, T>::value>::type>
{
	using in = T *;
	using out = T **;
};

template <typename T>
using arg_in = typename arg<default_interface<T>>::in;

template <typename T>
using arg_out = typename arg<default_interface<T>>::out;

}}

namespace winrt { namespace impl {

template <typename T>
struct traits
{
	using abi = T;
};

template <typename T>
class has_GetAt
{
	template <typename U, typename = decltype(std::declval<U>().GetAt(0))> static constexpr bool check(int) { return true; }
	template <typename> static constexpr bool check(...) { return false; }

public:

	static constexpr bool value = check<T>(0);
};

template <typename T>
class has_composable
{
	template <typename U> static constexpr bool check(typename U::composable *) { return true; }
	template <typename>   static constexpr bool check(...) { return false; }

public:

	static constexpr bool value = check<T>(nullptr);
};

template <typename Crtp, typename Qi, typename Base>
auto shim(Base const * base)
{
	return get(static_cast<Qi const &>(static_cast<Crtp const &>(*base)));
}

template <typename T, typename R>
struct requires : traits<R>::template methods<requires<T, R>>
{
	operator R() const noexcept
	{
		return static_cast<T const *>(this)->template As<R>();
	}
};

template <typename T, typename B>
struct bases
{
	operator B() const noexcept
	{
		return static_cast<T const *>(this)->As<B>();
	}
};

}}

namespace winrt {

template <typename T>
using abi = typename impl::traits<T>::abi;

template <typename T>
using abi_arg_in = ABI::arg_in<abi<T>>;

template <typename T>
using abi_arg_out = ABI::arg_out<abi<T>>;

template <typename T>
auto ptr(::IUnknown * object) noexcept
{
	return static_cast<impl::no_ref<abi<T>> *>(object);
}

template <typename T, typename ... R>
struct requires : impl::requires<T, R> ...
{};

template <typename T, typename ... B>
struct bases : impl::bases<T, B> ...
{};

namespace impl {

template <typename First, typename ... Rest>
struct implements : winrt::implements<abi<First>, abi<Rest> ..., ::IAgileObject>
{
	using default_interface = First;
};

}}
