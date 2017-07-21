﻿// WARNING: Please don't edit this file. It was generated by C++/WinRT v1.1.private

#pragma once
#include "winrt/base.h"

namespace winrt {

namespace Complex::Authoring {

struct ILanguage;
struct ISimple;
struct IStatic;
struct IStructByRef;
struct Language;
struct Simple;
struct Static;
struct StructByRef;

}

namespace Complex::Authoring::Factory {

struct ISimple;
struct ISimpleFactory;
struct IStatic;
struct IStaticFactory;
struct Simple;
struct SimpleFactory;
struct Static;
struct StaticFactory;

}

namespace Complex::Authoring::Nested {

struct ISimple;
struct Simple;

}

namespace impl {

template <> struct category<Complex::Authoring::ILanguage>{ using type = interface_category; };
template <> struct category<Complex::Authoring::ISimple>{ using type = interface_category; };
template <> struct category<Complex::Authoring::IStatic>{ using type = interface_category; };
template <> struct category<Complex::Authoring::IStructByRef>{ using type = interface_category; };
template <> struct category<Complex::Authoring::Language>{ using type = class_category; };
template <> struct category<Complex::Authoring::Simple>{ using type = class_category; };
template <> struct category<Complex::Authoring::Static>{ using type = class_category; };
template <> struct category<Complex::Authoring::StructByRef>{ using type = class_category; };
template <> struct name<Complex::Authoring::ILanguage>{ static constexpr auto & value{ L"Complex.Authoring.ILanguage" }; };
template <> struct name<Complex::Authoring::ISimple>{ static constexpr auto & value{ L"Complex.Authoring.ISimple" }; };
template <> struct name<Complex::Authoring::IStatic>{ static constexpr auto & value{ L"Complex.Authoring.IStatic" }; };
template <> struct name<Complex::Authoring::IStructByRef>{ static constexpr auto & value{ L"Complex.Authoring.IStructByRef" }; };
template <> struct name<Complex::Authoring::Language>{ static constexpr auto & value{ L"Complex.Authoring.Language" }; };
template <> struct name<Complex::Authoring::Simple>{ static constexpr auto & value{ L"Complex.Authoring.Simple" }; };
template <> struct name<Complex::Authoring::Static>{ static constexpr auto & value{ L"Complex.Authoring.Static" }; };
template <> struct name<Complex::Authoring::StructByRef>{ static constexpr auto & value{ L"Complex.Authoring.StructByRef" }; };
template <> struct guid<Complex::Authoring::ILanguage>{ static constexpr GUID value{ 0xC242F075,0x4BE5,0x4000,{ 0xB7,0x7E,0x56,0x34,0xBC,0x87,0x54,0x7F } }; };
template <> struct guid<Complex::Authoring::ISimple>{ static constexpr GUID value{ 0x09839E70,0xB064,0x4287,{ 0xA4,0x73,0x78,0x65,0x67,0x19,0xBA,0xDA } }; };
template <> struct guid<Complex::Authoring::IStatic>{ static constexpr GUID value{ 0xC242F075,0x4BE5,0x4000,{ 0xB7,0x7E,0x56,0x34,0xBC,0x87,0x54,0x7F } }; };
template <> struct guid<Complex::Authoring::IStructByRef>{ static constexpr GUID value{ 0x24EC9145,0x7F4B,0x4515,{ 0x89,0x10,0xEF,0x49,0x9B,0x26,0x7C,0x06 } }; };
template <> struct default_interface<Complex::Authoring::Language>{ using type = Complex::Authoring::ILanguage; };
template <> struct default_interface<Complex::Authoring::Simple>{ using type = Complex::Authoring::ISimple; };
template <> struct default_interface<Complex::Authoring::StructByRef>{ using type = Complex::Authoring::IStructByRef; };

template <typename D>
struct consume_Complex_Authoring_ILanguage
{
    hstring Français() const;
};
template <> struct consume<Complex::Authoring::ILanguage> { template <typename D> using type = consume_Complex_Authoring_ILanguage<D>; };

template <typename D>
struct consume_Complex_Authoring_ISimple
{
    hstring Name() const;
};
template <> struct consume<Complex::Authoring::ISimple> { template <typename D> using type = consume_Complex_Authoring_ISimple<D>; };

template <typename D>
struct consume_Complex_Authoring_IStatic
{
    Windows::Foundation::Rect Bounds() const;
};
template <> struct consume<Complex::Authoring::IStatic> { template <typename D> using type = consume_Complex_Authoring_IStatic<D>; };

template <typename D>
struct consume_Complex_Authoring_IStructByRef
{
    Windows::Foundation::Rect CopyByValue(Windows::Foundation::Rect const& byValue) const;
    Windows::Foundation::Rect CopyByRef(Windows::Foundation::Rect const& byRef) const;
};
template <> struct consume<Complex::Authoring::IStructByRef> { template <typename D> using type = consume_Complex_Authoring_IStructByRef<D>; };
template <> struct category<Complex::Authoring::Factory::ISimple>{ using type = interface_category; };
template <> struct category<Complex::Authoring::Factory::ISimpleFactory>{ using type = interface_category; };
template <> struct category<Complex::Authoring::Factory::IStatic>{ using type = interface_category; };
template <> struct category<Complex::Authoring::Factory::IStaticFactory>{ using type = interface_category; };
template <> struct category<Complex::Authoring::Factory::Simple>{ using type = class_category; };
template <> struct category<Complex::Authoring::Factory::SimpleFactory>{ using type = class_category; };
template <> struct category<Complex::Authoring::Factory::Static>{ using type = class_category; };
template <> struct category<Complex::Authoring::Factory::StaticFactory>{ using type = class_category; };
template <> struct name<Complex::Authoring::Factory::ISimple>{ static constexpr auto & value{ L"Complex.Authoring.Factory.ISimple" }; };
template <> struct name<Complex::Authoring::Factory::ISimpleFactory>{ static constexpr auto & value{ L"Complex.Authoring.Factory.ISimpleFactory" }; };
template <> struct name<Complex::Authoring::Factory::IStatic>{ static constexpr auto & value{ L"Complex.Authoring.Factory.IStatic" }; };
template <> struct name<Complex::Authoring::Factory::IStaticFactory>{ static constexpr auto & value{ L"Complex.Authoring.Factory.IStaticFactory" }; };
template <> struct name<Complex::Authoring::Factory::Simple>{ static constexpr auto & value{ L"Complex.Authoring.Factory.Simple" }; };
template <> struct name<Complex::Authoring::Factory::SimpleFactory>{ static constexpr auto & value{ L"Complex.Authoring.Factory.SimpleFactory" }; };
template <> struct name<Complex::Authoring::Factory::Static>{ static constexpr auto & value{ L"Complex.Authoring.Factory.Static" }; };
template <> struct name<Complex::Authoring::Factory::StaticFactory>{ static constexpr auto & value{ L"Complex.Authoring.Factory.StaticFactory" }; };
template <> struct guid<Complex::Authoring::Factory::ISimple>{ static constexpr GUID value{ 0x68504FD7,0xF10E,0x4E7B,{ 0xB2,0xC5,0x2A,0x89,0x06,0x70,0xB3,0x9B } }; };
template <> struct guid<Complex::Authoring::Factory::ISimpleFactory>{ static constexpr GUID value{ 0x3590E075,0x41F5,0x4DBD,{ 0xA5,0xEA,0x30,0xDD,0x29,0x94,0xF8,0x84 } }; };
template <> struct guid<Complex::Authoring::Factory::IStatic>{ static constexpr GUID value{ 0x9987FDEA,0x6A97,0x41AD,{ 0x9B,0x9F,0x0F,0x27,0x4C,0xE0,0x77,0xD9 } }; };
template <> struct guid<Complex::Authoring::Factory::IStaticFactory>{ static constexpr GUID value{ 0xBFA00357,0x1F74,0x48C2,{ 0x9B,0xA2,0x37,0xAD,0x82,0x5A,0x63,0x9C } }; };
template <> struct default_interface<Complex::Authoring::Factory::Simple>{ using type = Complex::Authoring::Factory::ISimple; };
template <> struct default_interface<Complex::Authoring::Factory::SimpleFactory>{ using type = Complex::Authoring::Factory::ISimpleFactory; };

template <typename D>
struct consume_Complex_Authoring_Factory_ISimple
{
};
template <> struct consume<Complex::Authoring::Factory::ISimple> { template <typename D> using type = consume_Complex_Authoring_Factory_ISimple<D>; };

template <typename D>
struct consume_Complex_Authoring_Factory_ISimpleFactory
{
};
template <> struct consume<Complex::Authoring::Factory::ISimpleFactory> { template <typename D> using type = consume_Complex_Authoring_Factory_ISimpleFactory<D>; };

template <typename D>
struct consume_Complex_Authoring_Factory_IStatic
{
};
template <> struct consume<Complex::Authoring::Factory::IStatic> { template <typename D> using type = consume_Complex_Authoring_Factory_IStatic<D>; };

template <typename D>
struct consume_Complex_Authoring_Factory_IStaticFactory
{
};
template <> struct consume<Complex::Authoring::Factory::IStaticFactory> { template <typename D> using type = consume_Complex_Authoring_Factory_IStaticFactory<D>; };
template <> struct category<Complex::Authoring::Nested::ISimple>{ using type = interface_category; };
template <> struct category<Complex::Authoring::Nested::Simple>{ using type = class_category; };
template <> struct name<Complex::Authoring::Nested::ISimple>{ static constexpr auto & value{ L"Complex.Authoring.Nested.ISimple" }; };
template <> struct name<Complex::Authoring::Nested::Simple>{ static constexpr auto & value{ L"Complex.Authoring.Nested.Simple" }; };
template <> struct guid<Complex::Authoring::Nested::ISimple>{ static constexpr GUID value{ 0x34B0D9CC,0x0DBB,0x421C,{ 0xBA,0x71,0x7E,0x40,0xD0,0x96,0x68,0x04 } }; };
template <> struct default_interface<Complex::Authoring::Nested::Simple>{ using type = Complex::Authoring::Nested::ISimple; };

template <typename D>
struct consume_Complex_Authoring_Nested_ISimple
{
    hstring Name() const;
};
template <> struct consume<Complex::Authoring::Nested::ISimple> { template <typename D> using type = consume_Complex_Authoring_Nested_ISimple<D>; };

template <> struct abi<Complex::Authoring::ILanguage>{ struct type : ::IInspectable
{
    virtual HRESULT __stdcall get_Français(HSTRING* value) = 0;
};};

template <> struct abi<Complex::Authoring::ISimple>{ struct type : ::IInspectable
{
    virtual HRESULT __stdcall get_Name(HSTRING* value) = 0;
};};

template <> struct abi<Complex::Authoring::IStatic>{ struct type : ::IInspectable
{
    virtual HRESULT __stdcall get_Bounds(abi_t<Windows::Foundation::Rect>* value) = 0;
};};

template <> struct abi<Complex::Authoring::IStructByRef>{ struct type : ::IInspectable
{
    virtual HRESULT __stdcall CopyByValue(abi_t<Windows::Foundation::Rect> byValue, abi_t<Windows::Foundation::Rect>* result) = 0;
    virtual HRESULT __stdcall CopyByRef(abi_t<Windows::Foundation::Rect> const& byRef, abi_t<Windows::Foundation::Rect>* result) = 0;
};};

template <> struct abi<Complex::Authoring::Factory::ISimple>{ struct type : ::IInspectable
{
};};

template <> struct abi<Complex::Authoring::Factory::ISimpleFactory>{ struct type : ::IInspectable
{
};};

template <> struct abi<Complex::Authoring::Factory::IStatic>{ struct type : ::IInspectable
{
};};

template <> struct abi<Complex::Authoring::Factory::IStaticFactory>{ struct type : ::IInspectable
{
};};

template <> struct abi<Complex::Authoring::Nested::ISimple>{ struct type : ::IInspectable
{
    virtual HRESULT __stdcall get_Name(HSTRING* value) = 0;
};};

}

namespace Complex::Authoring {

struct ILanguage :
    Windows::Foundation::IInspectable,
    impl::consume_t<ILanguage>
{
    ILanguage(std::nullptr_t = nullptr) noexcept {}
};

struct ISimple :
    Windows::Foundation::IInspectable,
    impl::consume_t<ISimple>
{
    ISimple(std::nullptr_t = nullptr) noexcept {}
};

struct IStatic :
    Windows::Foundation::IInspectable,
    impl::consume_t<IStatic>
{
    IStatic(std::nullptr_t = nullptr) noexcept {}
};

struct IStructByRef :
    Windows::Foundation::IInspectable,
    impl::consume_t<IStructByRef>
{
    IStructByRef(std::nullptr_t = nullptr) noexcept {}
};

}

namespace Complex::Authoring::Factory {

struct ISimple :
    Windows::Foundation::IInspectable,
    impl::consume_t<ISimple>
{
    ISimple(std::nullptr_t = nullptr) noexcept {}
};

struct ISimpleFactory :
    Windows::Foundation::IInspectable,
    impl::consume_t<ISimpleFactory>
{
    ISimpleFactory(std::nullptr_t = nullptr) noexcept {}
};

struct IStatic :
    Windows::Foundation::IInspectable,
    impl::consume_t<IStatic>
{
    IStatic(std::nullptr_t = nullptr) noexcept {}
};

struct IStaticFactory :
    Windows::Foundation::IInspectable,
    impl::consume_t<IStaticFactory>
{
    IStaticFactory(std::nullptr_t = nullptr) noexcept {}
};

}

namespace Complex::Authoring::Nested {

struct ISimple :
    Windows::Foundation::IInspectable,
    impl::consume_t<ISimple>
{
    ISimple(std::nullptr_t = nullptr) noexcept {}
};

}

namespace Complex::Authoring {

struct Language :
    Complex::Authoring::ILanguage
{
    Language(std::nullptr_t) noexcept {}
    Language();
};

struct Simple :
    Complex::Authoring::ISimple
{
    Simple(std::nullptr_t) noexcept {}
    Simple();
};

struct Static
{
    Static() = delete;
    static Windows::Foundation::Rect Bounds();
};

struct StructByRef :
    Complex::Authoring::IStructByRef
{
    StructByRef(std::nullptr_t) noexcept {}
    StructByRef();
};

}

namespace Complex::Authoring::Factory {

struct Simple :
    Complex::Authoring::Factory::ISimple
{
    Simple(std::nullptr_t) noexcept {}
    Simple();
};

struct SimpleFactory :
    Complex::Authoring::Factory::ISimpleFactory
{
    SimpleFactory(std::nullptr_t) noexcept {}
    SimpleFactory();
};

struct Static
{
    Static() = delete;
};

struct StaticFactory
{
    StaticFactory() = delete;
};

}

namespace Complex::Authoring::Nested {

struct Simple :
    Complex::Authoring::Nested::ISimple
{
    Simple(std::nullptr_t) noexcept {}
    Simple();
};

}

namespace impl {

template <typename D> hstring consume_Complex_Authoring_ILanguage<D>::Français() const
{
    hstring value{};
    check_hresult(WINRT_SHIM(Complex::Authoring::ILanguage)->get_Français(put_abi(value)));
    return value;
}

template <typename D> hstring consume_Complex_Authoring_ISimple<D>::Name() const
{
    hstring value{};
    check_hresult(WINRT_SHIM(Complex::Authoring::ISimple)->get_Name(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::Rect consume_Complex_Authoring_IStatic<D>::Bounds() const
{
    Windows::Foundation::Rect value{};
    check_hresult(WINRT_SHIM(Complex::Authoring::IStatic)->get_Bounds(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::Rect consume_Complex_Authoring_IStructByRef<D>::CopyByValue(Windows::Foundation::Rect const& byValue) const
{
    Windows::Foundation::Rect result{};
    check_hresult(WINRT_SHIM(Complex::Authoring::IStructByRef)->CopyByValue(get_abi(byValue), put_abi(result)));
    return result;
}

template <typename D> Windows::Foundation::Rect consume_Complex_Authoring_IStructByRef<D>::CopyByRef(Windows::Foundation::Rect const& byRef) const
{
    Windows::Foundation::Rect result{};
    check_hresult(WINRT_SHIM(Complex::Authoring::IStructByRef)->CopyByRef(get_abi(byRef), put_abi(result)));
    return result;
}

template <typename D>
struct produce<D, Complex::Authoring::ILanguage> : produce_base<D, Complex::Authoring::ILanguage>
{
    HRESULT __stdcall get_Français(HSTRING* value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Français());
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
struct produce<D, Complex::Authoring::ISimple> : produce_base<D, Complex::Authoring::ISimple>
{
    HRESULT __stdcall get_Name(HSTRING* value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Name());
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
struct produce<D, Complex::Authoring::IStatic> : produce_base<D, Complex::Authoring::IStatic>
{
    HRESULT __stdcall get_Bounds(abi_t<Windows::Foundation::Rect>* value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Bounds());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Complex::Authoring::IStructByRef> : produce_base<D, Complex::Authoring::IStructByRef>
{
    HRESULT __stdcall CopyByValue(abi_t<Windows::Foundation::Rect> byValue, abi_t<Windows::Foundation::Rect>* result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().CopyByValue(*reinterpret_cast<Windows::Foundation::Rect const*>(&byValue)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall CopyByRef(abi_t<Windows::Foundation::Rect> const& byRef, abi_t<Windows::Foundation::Rect>* result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().CopyByRef(*reinterpret_cast<Windows::Foundation::Rect const*>(&byRef)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Complex::Authoring::Factory::ISimple> : produce_base<D, Complex::Authoring::Factory::ISimple>
{};

template <typename D>
struct produce<D, Complex::Authoring::Factory::ISimpleFactory> : produce_base<D, Complex::Authoring::Factory::ISimpleFactory>
{};

template <typename D>
struct produce<D, Complex::Authoring::Factory::IStatic> : produce_base<D, Complex::Authoring::Factory::IStatic>
{};

template <typename D>
struct produce<D, Complex::Authoring::Factory::IStaticFactory> : produce_base<D, Complex::Authoring::Factory::IStaticFactory>
{};

template <typename D> hstring consume_Complex_Authoring_Nested_ISimple<D>::Name() const
{
    hstring value{};
    check_hresult(WINRT_SHIM(Complex::Authoring::Nested::ISimple)->get_Name(put_abi(value)));
    return value;
}

template <typename D>
struct produce<D, Complex::Authoring::Nested::ISimple> : produce_base<D, Complex::Authoring::Nested::ISimple>
{
    HRESULT __stdcall get_Name(HSTRING* value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Name());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }
};

}

namespace Complex::Authoring {

inline Language::Language() :
    Language(activate_instance<Language>())
{}

inline Simple::Simple() :
    Simple(activate_instance<Simple>())
{}

inline Windows::Foundation::Rect Static::Bounds()
{
    return get_activation_factory<Static, Complex::Authoring::IStatic>().Bounds();
}

inline StructByRef::StructByRef() :
    StructByRef(activate_instance<StructByRef>())
{}

}

namespace Complex::Authoring::Factory {

inline Simple::Simple() :
    Simple(activate_instance<Simple>())
{}

inline SimpleFactory::SimpleFactory() :
    SimpleFactory(activate_instance<SimpleFactory>())
{}

}

namespace Complex::Authoring::Nested {

inline Simple::Simple() :
    Simple(activate_instance<Simple>())
{}

}

}

namespace std {

template<> struct hash<winrt::Complex::Authoring::ILanguage> : 
    winrt::impl::impl_hash_unknown<winrt::Complex::Authoring::ILanguage> {};

template<> struct hash<winrt::Complex::Authoring::ISimple> : 
    winrt::impl::impl_hash_unknown<winrt::Complex::Authoring::ISimple> {};

template<> struct hash<winrt::Complex::Authoring::IStatic> : 
    winrt::impl::impl_hash_unknown<winrt::Complex::Authoring::IStatic> {};

template<> struct hash<winrt::Complex::Authoring::IStructByRef> : 
    winrt::impl::impl_hash_unknown<winrt::Complex::Authoring::IStructByRef> {};

template<> struct hash<winrt::Complex::Authoring::Language> : 
    winrt::impl::impl_hash_unknown<winrt::Complex::Authoring::Language> {};

template<> struct hash<winrt::Complex::Authoring::Simple> : 
    winrt::impl::impl_hash_unknown<winrt::Complex::Authoring::Simple> {};

template<> struct hash<winrt::Complex::Authoring::Static> : 
    winrt::impl::impl_hash_unknown<winrt::Complex::Authoring::Static> {};

template<> struct hash<winrt::Complex::Authoring::StructByRef> : 
    winrt::impl::impl_hash_unknown<winrt::Complex::Authoring::StructByRef> {};

template<> struct hash<winrt::Complex::Authoring::Factory::ISimple> : 
    winrt::impl::impl_hash_unknown<winrt::Complex::Authoring::Factory::ISimple> {};

template<> struct hash<winrt::Complex::Authoring::Factory::ISimpleFactory> : 
    winrt::impl::impl_hash_unknown<winrt::Complex::Authoring::Factory::ISimpleFactory> {};

template<> struct hash<winrt::Complex::Authoring::Factory::IStatic> : 
    winrt::impl::impl_hash_unknown<winrt::Complex::Authoring::Factory::IStatic> {};

template<> struct hash<winrt::Complex::Authoring::Factory::IStaticFactory> : 
    winrt::impl::impl_hash_unknown<winrt::Complex::Authoring::Factory::IStaticFactory> {};

template<> struct hash<winrt::Complex::Authoring::Factory::Simple> : 
    winrt::impl::impl_hash_unknown<winrt::Complex::Authoring::Factory::Simple> {};

template<> struct hash<winrt::Complex::Authoring::Factory::SimpleFactory> : 
    winrt::impl::impl_hash_unknown<winrt::Complex::Authoring::Factory::SimpleFactory> {};

template<> struct hash<winrt::Complex::Authoring::Factory::Static> : 
    winrt::impl::impl_hash_unknown<winrt::Complex::Authoring::Factory::Static> {};

template<> struct hash<winrt::Complex::Authoring::Factory::StaticFactory> : 
    winrt::impl::impl_hash_unknown<winrt::Complex::Authoring::Factory::StaticFactory> {};

template<> struct hash<winrt::Complex::Authoring::Nested::ISimple> : 
    winrt::impl::impl_hash_unknown<winrt::Complex::Authoring::Nested::ISimple> {};

template<> struct hash<winrt::Complex::Authoring::Nested::Simple> : 
    winrt::impl::impl_hash_unknown<winrt::Complex::Authoring::Nested::Simple> {};

}
