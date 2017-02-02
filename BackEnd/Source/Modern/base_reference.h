
namespace ABI::Windows::Foundation {

template <typename T> struct IReference;

template <typename T>
struct __declspec(novtable) impl_IReference : IInspectable
{
    virtual HRESULT __stdcall get_Value(arg_out<T> value) = 0;
};

}

namespace Windows::Foundation {

template <typename T> struct IReference;

template <typename D, typename T>
struct impl_IReference
{
    T Value() const;
};

}

namespace impl {

template <typename T> struct traits<Windows::Foundation::IReference<T>>
{
    using abi = ABI::Windows::Foundation::IReference<abi<T>>;
    template <typename D> using consume = Windows::Foundation::impl_IReference<D, T>;
};

template <typename D, typename T>
struct produce<D, Windows::Foundation::IReference<T>> : produce_base<D, Windows::Foundation::IReference<T>>
{
    HRESULT __stdcall get_Value(abi_arg_out<T> value) noexcept final
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach(this->shim().Value());
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

namespace Windows::Foundation {

template <typename T>
struct WINRT_EBO IReference :
    IInspectable,
    impl::consume<IReference<T>>
{
    IReference(std::nullptr_t = nullptr) noexcept {}
};

template <typename D, typename T>
T impl_IReference<D, T>::Value() const
{
    T result{};
    check_hresult((*(abi<IReference<T>> **)&static_cast<const IReference<T> &>(static_cast<const D &>(*this)))->get_Value(put(result)));
    return result;
}

}
