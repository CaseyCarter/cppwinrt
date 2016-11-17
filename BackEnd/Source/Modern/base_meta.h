
namespace impl {

template <typename Base, typename Derived>
constexpr bool is_base_of_v = std::is_base_of<Base, Derived>::value;

template<typename T, typename U>
constexpr bool is_same_v = std::is_same<T, U>::value;

template<typename ...>
struct disjunction : std::false_type {};

template<typename B>
struct disjunction<B> : B {};

template<typename B1, typename ... Bn>
struct disjunction<B1, Bn ...> : std::conditional_t<B1::value, B1, disjunction<Bn ...>> {};

template<typename ... B>
constexpr bool disjunction_v = disjunction<B ...>::value;

template<typename ...>
struct conjunction : std::true_type {};

template<typename B>
struct conjunction<B> : B {};

template<typename B1, typename ... Bn>
struct conjunction<B1, Bn ...> : std::conditional_t<B1::value, conjunction<Bn ...>, B1> {};

template<typename ... B>
constexpr bool conjunction_v = conjunction<B ...>::value;

}

namespace ABI {

template <typename T>
struct traits
{
    using default_interface = T;
};

template <typename T>
using default_interface = typename traits<T>::default_interface;

template <typename T>
using arg_in = std::conditional_t<impl::is_base_of_v< ::IUnknown, default_interface<T>>, default_interface<T> *, T>;

template <typename T>
using arg_out = std::conditional_t<impl::is_base_of_v< ::IUnknown, default_interface<T>>, default_interface<T> **, T *>;

}

namespace impl {

template <typename D, typename I = D>
using consume = typename traits<I>::template consume<D>;

template <typename D, typename I>
struct require_one : consume<D, I>
{
    operator I() const
    {
        return static_cast<const D *>(this)->template as<I>();
    }
};

template <typename D, typename ... I>
struct WINRT_EBO require : impl::require_one<D, I> ...
{};

template <typename D, typename I>
struct bases_one
{
    operator I() const
    {
        return static_cast<const D *>(this)->template as<I>();
    }
};

template <typename D, typename ... I>
struct WINRT_EBO bases : impl::bases_one<D, I> ...
{};

template <typename T>
class no_ref : public T
{
    unsigned long __stdcall AddRef() noexcept;
    unsigned long __stdcall Release() noexcept;
};

template <typename T>
struct not_specialized_type
{
    static constexpr bool value = false;
};

template <typename T>
struct not_specialized
{
    static_assert(not_specialized_type<T>::value, "This generic interface has not been specialized.");
};

}

template <typename T>
using abi_arg_in = ABI::arg_in<abi<T>>;

template <typename T>
using abi_arg_out = ABI::arg_out<abi<T>>;

template <typename T>
using abi_default_interface = ABI::default_interface<abi<T>>;

template <typename T>
auto ptr(::IUnknown * object) noexcept
{
    return static_cast<impl::no_ref<abi<T>> *>(object);
}
