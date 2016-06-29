
namespace Windows {

enum class TrustLevel
{
    BaseTrust,
    PartialTrust,
    FullTrust,
};

enum class AsyncStatus
{
    Started,
    Completed,
    Canceled,
    Error,
};

}

namespace ABI { namespace Windows {

struct __declspec(uuid("af86e2e0-b12d-4c6a-9c5a-d7aa65101e90")) __declspec(novtable) IInspectable : IUnknown
{
    virtual HRESULT __stdcall get_Iids(uint32_t * iidCount, GUID ** iids) = 0;
    virtual HRESULT __stdcall get_RuntimeClassName(HSTRING * className) = 0;
    virtual HRESULT __stdcall get_TrustLevel(winrt::Windows::TrustLevel * trustLevel) = 0;
};

struct __declspec(uuid("00000036-0000-0000-c000-000000000046")) __declspec(novtable) IAsyncInfo : IInspectable
{
    virtual HRESULT __stdcall get_Id(uint32_t * id) = 0;
    virtual HRESULT __stdcall get_Status(winrt::Windows::AsyncStatus * status) = 0;
    virtual HRESULT __stdcall get_ErrorCode(HRESULT * errorCode) = 0;
    virtual HRESULT __stdcall abi_Cancel() = 0;
    virtual HRESULT __stdcall abi_Close() = 0;
};

struct __declspec(uuid("00000035-0000-0000-c000-000000000046")) __declspec(novtable) IActivationFactory : IInspectable
{
    virtual HRESULT __stdcall abi_ActivateInstance(IInspectable ** instance) = 0;
};

}}

namespace ABI {

template <typename T>
struct traits
{
    using default_interface = T;
};

template <typename T>
using default_interface = typename traits<T>::default_interface;

template <typename T>
using arg_in = std::conditional_t<std::is_base_of_v< ::IUnknown, default_interface<T>>, default_interface<T> *, T>;

template <typename T>
using arg_out = std::conditional_t<std::is_base_of_v< ::IUnknown, default_interface<T>>, default_interface<T> **, T *>;

}

namespace impl {

template <typename T>
class has_GetAt
{
    template <typename U, typename = decltype(std::declval<U>().GetAt(0))> static constexpr bool get_value(int) { return true; }
    template <typename> static constexpr bool get_value(...) { return false; }

public:

    static constexpr bool value = get_value<T>(0);
};

template <typename T>
class has_composable
{
    template <typename U> static constexpr bool get_value(typename U::composable *) { return true; }
    template <typename>   static constexpr bool get_value(...) { return false; }

public:

    static constexpr bool value = get_value<T>(0);
};

template <typename T>
class can_produce
{
    template <typename U> static constexpr bool get_value(typename impl::traits<U>::produce *) { return true; }
    template <typename>   static constexpr bool get_value(...) { return false; }

public:

    static constexpr bool value = get_value<T>(nullptr);
};

template <typename Crtp, typename Qi, typename Base>
auto shim(const Base * base)
{
    return get(static_cast<const Qi &>(static_cast<const Crtp &>(*base)));
}

template <typename T, typename R>
struct requires : traits<R>::template consume<requires<T, R>>
{
    operator R() const noexcept
    {
        return static_cast<const T *>(this)->template as<R>();
    }
};

template <typename T, typename B>
struct bases
{
    operator B() const noexcept
    {
        return static_cast<const T *>(this)->as<B>();
    }
};

template <typename T>
class no_ref : public T
{
    unsigned long __stdcall AddRef();
    unsigned long __stdcall Release();
};

}

template <typename T>
using abi_arg_in = ABI::arg_in<abi<T>>;

template <typename T>
using abi_arg_out = ABI::arg_out<abi<T>>;

template <typename T>
using abi_default_interface = ABI::default_interface<abi<T>>;

template <typename T>
auto ptr(IUnknown * object) noexcept
{
    return static_cast<impl::no_ref<abi<T>> *>(object);
}

template <typename T>
using consume = typename impl::traits<T>::template consume<T>;

template <typename T, typename ... R>
struct WINRT_EBO requires : impl::requires<T, R> ...
{};

template <typename T, typename ... B>
struct WINRT_EBO bases : impl::bases<T, B> ...
{};

namespace impl {

template <typename To, typename From>
auto abi_cast(From * from) noexcept
{
    return const_cast<abi<To> *>(static_cast<const abi<To> *>(from));
}

template <typename To, typename From>
auto winrt_cast(From * from) noexcept
{
    To result = nullptr;
    copy_from(result, abi_cast<To>(from));
    return result;
}

}