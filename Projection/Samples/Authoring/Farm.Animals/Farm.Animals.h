﻿// WARNING: Please don't edit this file. It was generated by C++/WinRT v1.1.private

#pragma once
#include "winrt/base.h"

namespace winrt {

namespace Farm::Animals {

struct IEgg;
struct IEggFactory;
struct IHen;
struct Egg;
struct Hen;

}

namespace impl {

template <> struct category<Farm::Animals::IEgg>{ using type = interface_category; };
template <> struct category<Farm::Animals::IEggFactory>{ using type = interface_category; };
template <> struct category<Farm::Animals::IHen>{ using type = interface_category; };
template <> struct category<Farm::Animals::Egg>{ using type = class_category; };
template <> struct category<Farm::Animals::Hen>{ using type = class_category; };
template <> struct name<Farm::Animals::IEgg>{ static constexpr auto & value{ L"Farm.Animals.IEgg" }; };
template <> struct name<Farm::Animals::IEggFactory>{ static constexpr auto & value{ L"Farm.Animals.IEggFactory" }; };
template <> struct name<Farm::Animals::IHen>{ static constexpr auto & value{ L"Farm.Animals.IHen" }; };
template <> struct name<Farm::Animals::Egg>{ static constexpr auto & value{ L"Farm.Animals.Egg" }; };
template <> struct name<Farm::Animals::Hen>{ static constexpr auto & value{ L"Farm.Animals.Hen" }; };
template <> struct guid<Farm::Animals::IEgg>{ static constexpr GUID value{ 0x20BF2128,0x6328,0x48CA,{ 0x8B,0x48,0x9B,0xA8,0x58,0x72,0xAD,0xB2 } }; };
template <> struct guid<Farm::Animals::IEggFactory>{ static constexpr GUID value{ 0xB9E01F66,0xC31F,0x40AA,{ 0xB7,0xC2,0x1F,0x71,0x14,0xF8,0xC6,0x42 } }; };
template <> struct guid<Farm::Animals::IHen>{ static constexpr GUID value{ 0xD81C56DE,0x8304,0x46EB,{ 0xAD,0xAD,0x23,0x82,0x33,0x6B,0x69,0xDF } }; };
template <> struct default_interface<Farm::Animals::Egg>{ using type = Farm::Animals::IEgg; };
template <> struct default_interface<Farm::Animals::Hen>{ using type = Farm::Animals::IHen; };

template <typename D>
struct consume_Farm_Animals_IEgg
{
    Farm::Animals::Hen Mother() const;
};
template <> struct consume<Farm::Animals::IEgg> { template <typename D> using type = consume_Farm_Animals_IEgg<D>; };

template <typename D>
struct consume_Farm_Animals_IEggFactory
{
    Farm::Animals::Egg CreateWithHen(Farm::Animals::Hen const& mother) const;
};
template <> struct consume<Farm::Animals::IEggFactory> { template <typename D> using type = consume_Farm_Animals_IEggFactory<D>; };

template <typename D>
struct consume_Farm_Animals_IHen
{
    hstring Français() const;
    Windows::Foundation::IAsyncOperationWithProgress<Farm::Animals::Egg, uint32_t> LayEggAsync() const;
    Windows::Foundation::Rect StructByValue(Windows::Foundation::Rect const& byValue) const;
    Windows::Foundation::Rect StructByRef(Windows::Foundation::Rect const& byRef) const;
};
template <> struct consume<Farm::Animals::IHen> { template <typename D> using type = consume_Farm_Animals_IHen<D>; };

template <> struct abi<Farm::Animals::IEgg>{ struct type : ::IInspectable
{
    virtual HRESULT __stdcall get_Mother(::IUnknown** mother) = 0;
};};

template <> struct abi<Farm::Animals::IEggFactory>{ struct type : ::IInspectable
{
    virtual HRESULT __stdcall CreateWithHen(::IUnknown* mother, ::IUnknown** egg) = 0;
};};

template <> struct abi<Farm::Animals::IHen>{ struct type : ::IInspectable
{
    virtual HRESULT __stdcall get_Français(HSTRING* name) = 0;
    virtual HRESULT __stdcall LayEggAsync(::IUnknown** operation) = 0;
    virtual HRESULT __stdcall StructByValue(abi_t<Windows::Foundation::Rect> byValue, abi_t<Windows::Foundation::Rect>* result) = 0;
    virtual HRESULT __stdcall StructByRef(abi_t<Windows::Foundation::Rect> const& byRef, abi_t<Windows::Foundation::Rect>* result) = 0;
};};

}

namespace Farm::Animals {

struct IEgg :
    Windows::Foundation::IInspectable,
    impl::consume_t<IEgg>
{
    IEgg(std::nullptr_t = nullptr) noexcept {}
};

struct IEggFactory :
    Windows::Foundation::IInspectable,
    impl::consume_t<IEggFactory>
{
    IEggFactory(std::nullptr_t = nullptr) noexcept {}
};

struct IHen :
    Windows::Foundation::IInspectable,
    impl::consume_t<IHen>
{
    IHen(std::nullptr_t = nullptr) noexcept {}
};

struct Egg :
    Farm::Animals::IEgg
{
    Egg(std::nullptr_t) noexcept {}
    Egg(Farm::Animals::Hen const& mother);
};

struct Hen :
    Farm::Animals::IHen
{
    Hen(std::nullptr_t) noexcept {}
    Hen();
};

}

namespace impl {

template <typename D> Farm::Animals::Hen consume_Farm_Animals_IEgg<D>::Mother() const
{
    Farm::Animals::Hen mother{ nullptr };
    check_hresult(WINRT_SHIM(Farm::Animals::IEgg)->get_Mother(put_abi(mother)));
    return mother;
}

template <typename D> Farm::Animals::Egg consume_Farm_Animals_IEggFactory<D>::CreateWithHen(Farm::Animals::Hen const& mother) const
{
    Farm::Animals::Egg egg{ nullptr };
    check_hresult(WINRT_SHIM(Farm::Animals::IEggFactory)->CreateWithHen(get_abi(mother), put_abi(egg)));
    return egg;
}

template <typename D> hstring consume_Farm_Animals_IHen<D>::Français() const
{
    hstring name{};
    check_hresult(WINRT_SHIM(Farm::Animals::IHen)->get_Français(put_abi(name)));
    return name;
}

template <typename D> Windows::Foundation::IAsyncOperationWithProgress<Farm::Animals::Egg, uint32_t> consume_Farm_Animals_IHen<D>::LayEggAsync() const
{
    Windows::Foundation::IAsyncOperationWithProgress<Farm::Animals::Egg, uint32_t> operation{ nullptr };
    check_hresult(WINRT_SHIM(Farm::Animals::IHen)->LayEggAsync(put_abi(operation)));
    return operation;
}

template <typename D> Windows::Foundation::Rect consume_Farm_Animals_IHen<D>::StructByValue(Windows::Foundation::Rect const& byValue) const
{
    Windows::Foundation::Rect result{};
    check_hresult(WINRT_SHIM(Farm::Animals::IHen)->StructByValue(get_abi(byValue), put_abi(result)));
    return result;
}

template <typename D> Windows::Foundation::Rect consume_Farm_Animals_IHen<D>::StructByRef(Windows::Foundation::Rect const& byRef) const
{
    Windows::Foundation::Rect result{};
    check_hresult(WINRT_SHIM(Farm::Animals::IHen)->StructByRef(get_abi(byRef), put_abi(result)));
    return result;
}

template <typename D>
struct produce<D, Farm::Animals::IEgg> : produce_base<D, Farm::Animals::IEgg>
{
    HRESULT __stdcall get_Mother(::IUnknown** mother) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *mother = detach_abi(this->shim().Mother());
            return S_OK;
        }
        catch (...)
        {
            *mother = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Farm::Animals::IEggFactory> : produce_base<D, Farm::Animals::IEggFactory>
{
    HRESULT __stdcall CreateWithHen(::IUnknown* mother, ::IUnknown** egg) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *egg = detach_abi(this->shim().CreateWithHen(*reinterpret_cast<Farm::Animals::Hen const*>(&mother)));
            return S_OK;
        }
        catch (...)
        {
            *egg = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Farm::Animals::IHen> : produce_base<D, Farm::Animals::IHen>
{
    HRESULT __stdcall get_Français(HSTRING* name) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *name = detach_abi(this->shim().Français());
            return S_OK;
        }
        catch (...)
        {
            *name = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall LayEggAsync(::IUnknown** operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().LayEggAsync());
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall StructByValue(abi_t<Windows::Foundation::Rect> byValue, abi_t<Windows::Foundation::Rect>* result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().StructByValue(*reinterpret_cast<Windows::Foundation::Rect const*>(&byValue)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall StructByRef(abi_t<Windows::Foundation::Rect> const& byRef, abi_t<Windows::Foundation::Rect>* result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().StructByRef(*reinterpret_cast<Windows::Foundation::Rect const*>(&byRef)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

}

namespace Farm::Animals {

inline Egg::Egg(Farm::Animals::Hen const& mother) :
    Egg(get_activation_factory<Egg, Farm::Animals::IEggFactory>().CreateWithHen(mother))
{}

inline Hen::Hen() :
    Hen(activate_instance<Hen>())
{}

}

}

namespace std {

template<> struct hash<winrt::Farm::Animals::IEgg> : 
    winrt::impl::impl_hash_unknown<winrt::Farm::Animals::IEgg> {};

template<> struct hash<winrt::Farm::Animals::IEggFactory> : 
    winrt::impl::impl_hash_unknown<winrt::Farm::Animals::IEggFactory> {};

template<> struct hash<winrt::Farm::Animals::IHen> : 
    winrt::impl::impl_hash_unknown<winrt::Farm::Animals::IHen> {};

template<> struct hash<winrt::Farm::Animals::Egg> : 
    winrt::impl::impl_hash_unknown<winrt::Farm::Animals::Egg> {};

template<> struct hash<winrt::Farm::Animals::Hen> : 
    winrt::impl::impl_hash_unknown<winrt::Farm::Animals::Hen> {};

}
