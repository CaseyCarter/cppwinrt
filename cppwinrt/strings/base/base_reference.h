
WINRT_EXPORT namespace winrt::Windows::Foundation
{
    template <typename T> struct IReference;
}

namespace winrt::impl
{
    template <typename T>
    struct abi<Windows::Foundation::IReference<T>>
    {
        struct __declspec(novtable) type : ::IInspectable
        {
            virtual HRESULT __stdcall get_Value(arg_out<T> value) = 0;
        };
    };

    template <typename D, typename T>
    struct consume_IReference
    {
        T Value() const
        {
            T result{};
            check_hresult((*(abi_t<Windows::Foundation::IReference<T>>**)&static_cast<const Windows::Foundation::IReference<T>&>(static_cast<const D&>(*this)))->get_Value(put_abi(result)));
            return result;
        }
    };

    template <typename T>
    struct consume<Windows::Foundation::IReference<T>>
    {
        template <typename D> using type = consume_IReference<D, T>;
    };

    template <typename T>
    struct guid<Windows::Foundation::IReference<T>>
    {
        static constexpr GUID value{ pinterface_guid<Windows::Foundation::IReference<T>>::value };
    };

    template <typename T> 
    struct name<Windows::Foundation::IReference<T>>
    {
        static constexpr auto value{ L"Windows.Foundation.IReference`1<" + make_constexpr_string(name_v<T>) + L">" };
    };

    template <typename T>
    struct category<Windows::Foundation::IReference<T>>
    {
        using type = pinterface_category<T>;
        static constexpr GUID value{ 0x61c17706, 0x2d65, 0x11e0,{ 0x9a, 0xe8, 0xd4, 0x85, 0x64, 0x01, 0x54, 0x72 } };
    };
}

WINRT_EXPORT namespace winrt
{
    template <typename T>
    using optional = Windows::Foundation::IReference<T>;
}
