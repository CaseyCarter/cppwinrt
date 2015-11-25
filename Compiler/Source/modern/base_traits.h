
namespace winrt { namespace impl {

template <typename T>
struct traits
{
	using abi = T;
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

}}

namespace winrt {

template <typename T>
using abi = typename impl::traits<T>::abi;

}

namespace winrt { namespace impl {

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

}}

namespace winrt {

template <typename T>
using default_interface = typename impl::lookup_default_interface<T>::type;

}
