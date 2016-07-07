
namespace ABI { namespace Windows { namespace Foundation {

template <typename T> struct IReference;

template <typename T>
struct __declspec(novtable) impl_IReference : IInspectable
{
    virtual HRESULT __stdcall get_Value(arg_out<T> value) = 0;
};

}}}

namespace Windows { namespace Foundation {

template <typename T> struct IReference;

template <typename D, typename T>
class impl_IReference
{
    auto shim() const { return impl::shim<D, IReference<T>>(this); }

public:

    T Value() const
    {
        T result {};
        check_hresult(shim()->get_Value(put(result)));
        return result;
    }
};

}}

namespace impl {

template <typename T> struct traits<Windows::Foundation::IReference<T>>
{
    using abi = ABI::Windows::Foundation::IReference<abi<T>>;
    template <typename D> using consume = Windows::Foundation::impl_IReference<D, T>;
};

template <typename D, typename T>
struct produce<D, Windows::Foundation::IReference<T>> : produce_base<D, Windows::Foundation::IReference<abi<T>>>
{
    HRESULT __stdcall get_Value(abi_arg_out<T> value) noexcept final
    {
        try
        {
            *value = detach(shim().Value());
            return S_OK;
        }
        catch (...)
        {
            clear_abi(value);
            return to_hresult();
        }
    }
};

}

namespace Windows { namespace Foundation {

template <typename T>
struct WINRT_EBO IReference :
    IInspectable,
    impl::consume<IReference<T>>
{
    IReference(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IReference>(m_ptr); }
};

}}
