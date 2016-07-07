#pragma once

namespace winrt {

namespace ABI { namespace Windows { namespace Foundation {

struct __declspec(uuid("30d5a829-7fa4-4026-83bb-d75bae4ea99e")) __declspec(novtable) IClosable : Windows::IInspectable
{
    virtual HRESULT __stdcall abi_Close() = 0;
};

struct __declspec(uuid("96369f54-8eb6-48f0-abce-c1b211e627c3")) __declspec(novtable) IStringable : Windows::IInspectable
{
    virtual HRESULT __stdcall abi_ToString(hstring * value) = 0;
};

template <> struct __declspec(uuid("3750b1b2-2a32-4747-9462-d3918eb35c96")) __declspec(novtable) 
TypedEventHandler<int, int> : impl_TypedEventHandler<int, int> {};

}}}

namespace Windows { namespace Foundation {

struct IClosable;
struct IStringable;

template <typename D>
class WINRT_EBO impl_IClosable
{
    auto shim() const { return impl::shim<D, IClosable>(this); }

public:

    void Close() const
    {
        check_hresult(shim()->abi_Close());
    }
};

template <typename D>
class WINRT_EBO impl_IStringable
{
    auto shim() const { return impl::shim<D, IStringable>(this); }

public:

    hstring ToString() const
    {
        hstring value;
        check_hresult(shim()->abi_ToString(put(value)));
        return value;
    }
};

}}

namespace impl {

template <> struct traits<Windows::Foundation::IClosable>
{
    using abi = ABI::Windows::Foundation::IClosable;
    template <typename T> using consume = Windows::Foundation::impl_IClosable<T>;
};

template <> struct traits<Windows::Foundation::IStringable>
{
    using abi = ABI::Windows::Foundation::IStringable;
    template <typename T> using consume = Windows::Foundation::impl_IStringable<T>;
};

}

namespace Windows { namespace Foundation {

struct IClosable :
    Windows::IInspectable,
    impl::consume<IClosable>
{
    IClosable(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IClosable>(m_ptr); }
};

struct IStringable :
    Windows::IInspectable,
    impl::consume<IStringable>
{
    IStringable(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IStringable>(m_ptr); }
};

}}

namespace impl {

template <typename D>
struct produce<D, Windows::Foundation::IStringable> : produce_base<D, Windows::Foundation::IStringable>
{
    HRESULT __stdcall abi_ToString(abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            *value = detach(shim().ToString());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Foundation::IClosable> : produce_base<D, Windows::Foundation::IClosable>
{
    HRESULT __stdcall abi_Close() noexcept override
    {
        try
        {
            shim().Close();
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

}

}
