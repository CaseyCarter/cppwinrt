﻿// WARNING: Please don't edit this file. It was generated by C++/WinRT v1.1.private

#pragma once
#include "winrt/base.h"

namespace winrt {

namespace Composable::Base {

struct IDerived;
struct IDerivedFactory;
struct IDerivedOverrides;
struct IRoot;
struct IRootFactory;
struct IRootOverrides;
struct Derived;
struct Root;

}

namespace impl {

template <> struct category<Composable::Base::IDerived>{ using type = interface_category; };
template <> struct category<Composable::Base::IDerivedFactory>{ using type = interface_category; };
template <> struct category<Composable::Base::IDerivedOverrides>{ using type = interface_category; };
template <> struct category<Composable::Base::IRoot>{ using type = interface_category; };
template <> struct category<Composable::Base::IRootFactory>{ using type = interface_category; };
template <> struct category<Composable::Base::IRootOverrides>{ using type = interface_category; };
template <> struct category<Composable::Base::Derived>{ using type = class_category; };
template <> struct category<Composable::Base::Root>{ using type = class_category; };
template <> struct name<Composable::Base::IDerived>{ static constexpr auto & value{ L"Composable.Base.IDerived" }; };
template <> struct name<Composable::Base::IDerivedFactory>{ static constexpr auto & value{ L"Composable.Base.IDerivedFactory" }; };
template <> struct name<Composable::Base::IDerivedOverrides>{ static constexpr auto & value{ L"Composable.Base.IDerivedOverrides" }; };
template <> struct name<Composable::Base::IRoot>{ static constexpr auto & value{ L"Composable.Base.IRoot" }; };
template <> struct name<Composable::Base::IRootFactory>{ static constexpr auto & value{ L"Composable.Base.IRootFactory" }; };
template <> struct name<Composable::Base::IRootOverrides>{ static constexpr auto & value{ L"Composable.Base.IRootOverrides" }; };
template <> struct name<Composable::Base::Derived>{ static constexpr auto & value{ L"Composable.Base.Derived" }; };
template <> struct name<Composable::Base::Root>{ static constexpr auto & value{ L"Composable.Base.Root" }; };
template <> struct guid<Composable::Base::IDerived>{ static constexpr GUID value{ 0x27ECA5A0,0xF765,0x404A,{ 0x9B,0xB2,0x8F,0xB9,0x9B,0xED,0x74,0xCB } }; };
template <> struct guid<Composable::Base::IDerivedFactory>{ static constexpr GUID value{ 0x307F5696,0xB194,0x4AA8,{ 0xB9,0xBF,0xB6,0x01,0xD5,0xD5,0xF9,0xB3 } }; };
template <> struct guid<Composable::Base::IDerivedOverrides>{ static constexpr GUID value{ 0x70ED6303,0x3C59,0x4913,{ 0x99,0x6B,0x4D,0xDB,0x25,0xB7,0xFC,0x3A } }; };
template <> struct guid<Composable::Base::IRoot>{ static constexpr GUID value{ 0x5AF1D906,0xD669,0x42B3,{ 0xA9,0x00,0x22,0x77,0xD3,0x28,0xA3,0xBE } }; };
template <> struct guid<Composable::Base::IRootFactory>{ static constexpr GUID value{ 0x9F102F80,0x7151,0x4B32,{ 0xA0,0xC6,0xFE,0xBC,0xBB,0x77,0x31,0x91 } }; };
template <> struct guid<Composable::Base::IRootOverrides>{ static constexpr GUID value{ 0xF6A711E9,0xC1C9,0x4E46,{ 0x9E,0x43,0x3D,0x8E,0x8E,0x22,0x0D,0x2B } }; };
template <> struct default_interface<Composable::Base::Derived>{ using type = Composable::Base::IDerived; };
template <> struct default_interface<Composable::Base::Root>{ using type = Composable::Base::IRoot; };

template <typename D>
struct consume_Composable_Base_IDerived
{
    hstring DerivedMethod() const;
    hstring CallVirtualPublicDerivedMethod() const;
};
template <> struct consume<Composable::Base::IDerived> { template <typename D> using type = consume_Composable_Base_IDerived<D>; };

template <typename D>
struct consume_Composable_Base_IDerivedFactory
{
    Composable::Base::Derived CreateInstance(Windows::Foundation::IInspectable const& outer, Windows::Foundation::IInspectable& inner) const;
};
template <> struct consume<Composable::Base::IDerivedFactory> { template <typename D> using type = consume_Composable_Base_IDerivedFactory<D>; };

template <typename D>
struct consume_Composable_Base_IDerivedOverrides
{
    hstring VirtualPublicDerivedMethod() const;
};
template <> struct consume<Composable::Base::IDerivedOverrides> { template <typename D> using type = consume_Composable_Base_IDerivedOverrides<D>; };

template <typename D>
struct consume_Composable_Base_IRoot
{
    hstring RootMethod() const;
    hstring VirtualInternalRootMethod() const;
    hstring CallVirtualPublicRootMethod() const;
};
template <> struct consume<Composable::Base::IRoot> { template <typename D> using type = consume_Composable_Base_IRoot<D>; };

template <typename D>
struct consume_Composable_Base_IRootFactory
{
    Composable::Base::Root CreateInstance(Windows::Foundation::IInspectable const& outer, Windows::Foundation::IInspectable& inner) const;
};
template <> struct consume<Composable::Base::IRootFactory> { template <typename D> using type = consume_Composable_Base_IRootFactory<D>; };

template <typename D>
struct consume_Composable_Base_IRootOverrides
{
    hstring VirtualPublicRootMethod() const;
};
template <> struct consume<Composable::Base::IRootOverrides> { template <typename D> using type = consume_Composable_Base_IRootOverrides<D>; };

template <> struct abi<Composable::Base::IDerived>{ struct type : ::IInspectable
{
    virtual HRESULT __stdcall DerivedMethod(HSTRING* result) = 0;
    virtual HRESULT __stdcall CallVirtualPublicDerivedMethod(HSTRING* result) = 0;
};};

template <> struct abi<Composable::Base::IDerivedFactory>{ struct type : ::IInspectable
{
    virtual HRESULT __stdcall CreateInstance(::IUnknown* outer, ::IUnknown** inner, ::IUnknown** instance) = 0;
};};

template <> struct abi<Composable::Base::IDerivedOverrides>{ struct type : ::IInspectable
{
    virtual HRESULT __stdcall VirtualPublicDerivedMethod(HSTRING* result) = 0;
};};

template <> struct abi<Composable::Base::IRoot>{ struct type : ::IInspectable
{
    virtual HRESULT __stdcall RootMethod(HSTRING* result) = 0;
    virtual HRESULT __stdcall VirtualInternalRootMethod(HSTRING* result) = 0;
    virtual HRESULT __stdcall CallVirtualPublicRootMethod(HSTRING* result) = 0;
};};

template <> struct abi<Composable::Base::IRootFactory>{ struct type : ::IInspectable
{
    virtual HRESULT __stdcall CreateInstance(::IUnknown* outer, ::IUnknown** inner, ::IUnknown** instance) = 0;
};};

template <> struct abi<Composable::Base::IRootOverrides>{ struct type : ::IInspectable
{
    virtual HRESULT __stdcall VirtualPublicRootMethod(HSTRING* result) = 0;
};};

}

namespace Composable::Base {

struct IDerived :
    Windows::Foundation::IInspectable,
    impl::consume_t<IDerived>
{
    IDerived(std::nullptr_t = nullptr) noexcept {}
};

struct IDerivedFactory :
    Windows::Foundation::IInspectable,
    impl::consume_t<IDerivedFactory>
{
    IDerivedFactory(std::nullptr_t = nullptr) noexcept {}
};

struct IDerivedOverrides :
    Windows::Foundation::IInspectable,
    impl::consume_t<IDerivedOverrides>
{
    IDerivedOverrides(std::nullptr_t = nullptr) noexcept {}
};

struct IRoot :
    Windows::Foundation::IInspectable,
    impl::consume_t<IRoot>
{
    IRoot(std::nullptr_t = nullptr) noexcept {}
};

struct IRootFactory :
    Windows::Foundation::IInspectable,
    impl::consume_t<IRootFactory>
{
    IRootFactory(std::nullptr_t = nullptr) noexcept {}
};

struct IRootOverrides :
    Windows::Foundation::IInspectable,
    impl::consume_t<IRootOverrides>
{
    IRootOverrides(std::nullptr_t = nullptr) noexcept {}
};

struct Derived :
    Composable::Base::IDerived,
    impl::base<Derived, Composable::Base::Root>,
    impl::require<Derived, Composable::Base::IDerivedOverrides, Composable::Base::IRoot, Composable::Base::IRootOverrides>
{
    Derived(std::nullptr_t) noexcept {}
    Derived();
};

struct Root :
    Composable::Base::IRoot,
    impl::require<Root, Composable::Base::IRootOverrides>
{
    Root(std::nullptr_t) noexcept {}
    Root();
};

template <typename D>
class IDerivedOverridesT
{
    D& shim() noexcept { return *static_cast<D*>(this); }
    D const& shim() const noexcept { return *static_cast<const D*>(this); }

public:

    using IDerivedOverrides = winrt::Composable::Base::IDerivedOverrides;

    hstring VirtualPublicDerivedMethod() const;
};

template <typename D>
class IRootOverridesT
{
    D& shim() noexcept { return *static_cast<D*>(this); }
    D const& shim() const noexcept { return *static_cast<const D*>(this); }

public:

    using IRootOverrides = winrt::Composable::Base::IRootOverrides;

    hstring VirtualPublicRootMethod() const;
};

}

namespace impl {

template <typename D> hstring consume_Composable_Base_IDerived<D>::DerivedMethod() const
{
    hstring result{};
    check_hresult(WINRT_SHIM(Composable::Base::IDerived)->DerivedMethod(put_abi(result)));
    return result;
}

template <typename D> hstring consume_Composable_Base_IDerived<D>::CallVirtualPublicDerivedMethod() const
{
    hstring result{};
    check_hresult(WINRT_SHIM(Composable::Base::IDerived)->CallVirtualPublicDerivedMethod(put_abi(result)));
    return result;
}

template <typename D> Composable::Base::Derived consume_Composable_Base_IDerivedFactory<D>::CreateInstance(Windows::Foundation::IInspectable const& outer, Windows::Foundation::IInspectable& inner) const
{
    Composable::Base::Derived instance{ nullptr };
    check_hresult(WINRT_SHIM(Composable::Base::IDerivedFactory)->CreateInstance(get_abi(outer), put_abi(inner), put_abi(instance)));
    return instance;
}

template <typename D> hstring consume_Composable_Base_IDerivedOverrides<D>::VirtualPublicDerivedMethod() const
{
    hstring result{};
    check_hresult(WINRT_SHIM(Composable::Base::IDerivedOverrides)->VirtualPublicDerivedMethod(put_abi(result)));
    return result;
}

template <typename D> hstring consume_Composable_Base_IRoot<D>::RootMethod() const
{
    hstring result{};
    check_hresult(WINRT_SHIM(Composable::Base::IRoot)->RootMethod(put_abi(result)));
    return result;
}

template <typename D> hstring consume_Composable_Base_IRoot<D>::VirtualInternalRootMethod() const
{
    hstring result{};
    check_hresult(WINRT_SHIM(Composable::Base::IRoot)->VirtualInternalRootMethod(put_abi(result)));
    return result;
}

template <typename D> hstring consume_Composable_Base_IRoot<D>::CallVirtualPublicRootMethod() const
{
    hstring result{};
    check_hresult(WINRT_SHIM(Composable::Base::IRoot)->CallVirtualPublicRootMethod(put_abi(result)));
    return result;
}

template <typename D> Composable::Base::Root consume_Composable_Base_IRootFactory<D>::CreateInstance(Windows::Foundation::IInspectable const& outer, Windows::Foundation::IInspectable& inner) const
{
    Composable::Base::Root instance{ nullptr };
    check_hresult(WINRT_SHIM(Composable::Base::IRootFactory)->CreateInstance(get_abi(outer), put_abi(inner), put_abi(instance)));
    return instance;
}

template <typename D> hstring consume_Composable_Base_IRootOverrides<D>::VirtualPublicRootMethod() const
{
    hstring result{};
    check_hresult(WINRT_SHIM(Composable::Base::IRootOverrides)->VirtualPublicRootMethod(put_abi(result)));
    return result;
}

template <typename D>
struct produce<D, Composable::Base::IDerived> : produce_base<D, Composable::Base::IDerived>
{
    HRESULT __stdcall DerivedMethod(HSTRING* result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().DerivedMethod());
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall CallVirtualPublicDerivedMethod(HSTRING* result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().CallVirtualPublicDerivedMethod());
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Composable::Base::IDerivedFactory> : produce_base<D, Composable::Base::IDerivedFactory>
{
    HRESULT __stdcall CreateInstance(::IUnknown* outer, ::IUnknown** inner, ::IUnknown** instance) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            Windows::Foundation::IInspectable __local_inner;
            *instance = detach_abi(this->shim().CreateInstance(*reinterpret_cast<Windows::Foundation::IInspectable const*>(&outer), __local_inner));
            if (inner) *inner = detach_abi(__local_inner);
            return S_OK;
        }
        catch (...)
        {
            if (inner) *inner = nullptr;
            *instance = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Composable::Base::IDerivedOverrides> : produce_base<D, Composable::Base::IDerivedOverrides>
{
    HRESULT __stdcall VirtualPublicDerivedMethod(HSTRING* result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().VirtualPublicDerivedMethod());
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Composable::Base::IRoot> : produce_base<D, Composable::Base::IRoot>
{
    HRESULT __stdcall RootMethod(HSTRING* result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().RootMethod());
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall VirtualInternalRootMethod(HSTRING* result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().VirtualInternalRootMethod());
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall CallVirtualPublicRootMethod(HSTRING* result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().CallVirtualPublicRootMethod());
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Composable::Base::IRootFactory> : produce_base<D, Composable::Base::IRootFactory>
{
    HRESULT __stdcall CreateInstance(::IUnknown* outer, ::IUnknown** inner, ::IUnknown** instance) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            Windows::Foundation::IInspectable __local_inner;
            *instance = detach_abi(this->shim().CreateInstance(*reinterpret_cast<Windows::Foundation::IInspectable const*>(&outer), __local_inner));
            if (inner) *inner = detach_abi(__local_inner);
            return S_OK;
        }
        catch (...)
        {
            if (inner) *inner = nullptr;
            *instance = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Composable::Base::IRootOverrides> : produce_base<D, Composable::Base::IRootOverrides>
{
    HRESULT __stdcall VirtualPublicRootMethod(HSTRING* result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().VirtualPublicRootMethod());
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }
};

}

namespace Composable::Base {

inline Derived::Derived()
{
    Windows::Foundation::IInspectable outer, inner;
    impl_move(get_activation_factory<Derived, Composable::Base::IDerivedFactory>().CreateInstance(outer, inner));
}

inline Root::Root()
{
    Windows::Foundation::IInspectable outer, inner;
    impl_move(get_activation_factory<Root, Composable::Base::IRootFactory>().CreateInstance(outer, inner));
}

template <typename D> hstring IDerivedOverridesT<D>::VirtualPublicDerivedMethod() const
{
    return shim().template as<IDerivedOverrides>().VirtualPublicDerivedMethod();
}

template <typename D> hstring IRootOverridesT<D>::VirtualPublicRootMethod() const
{
    return shim().template as<IRootOverrides>().VirtualPublicRootMethod();
}

template <typename D, typename ... Interfaces>
struct DerivedT :
    implements<D, Composable::Base::IDerivedOverrides, Composable::Base::IRootOverrides, composing, Interfaces ...>,
    impl::require<D, Composable::Base::IDerived, Composable::Base::IRoot>,
    Composable::Base::IDerivedOverridesT<D>, Composable::Base::IRootOverridesT<D>
{
    using composable = Derived;

protected:
    DerivedT()
    {
        get_activation_factory<Composable::Base::Derived, Composable::Base::IDerivedFactory>().CreateInstance(*this, this->m_inner);
    }
};

template <typename D, typename ... Interfaces>
struct RootT :
    implements<D, Composable::Base::IRootOverrides, composing, Interfaces ...>,
    impl::require<D, Composable::Base::IRoot>,
    Composable::Base::IRootOverridesT<D>
{
    using composable = Root;

protected:
    RootT()
    {
        get_activation_factory<Composable::Base::Root, Composable::Base::IRootFactory>().CreateInstance(*this, this->m_inner);
    }
};

}

}

namespace std {

template<> struct hash<winrt::Composable::Base::IDerived> : 
    winrt::impl::impl_hash_unknown<winrt::Composable::Base::IDerived> {};

template<> struct hash<winrt::Composable::Base::IDerivedFactory> : 
    winrt::impl::impl_hash_unknown<winrt::Composable::Base::IDerivedFactory> {};

template<> struct hash<winrt::Composable::Base::IDerivedOverrides> : 
    winrt::impl::impl_hash_unknown<winrt::Composable::Base::IDerivedOverrides> {};

template<> struct hash<winrt::Composable::Base::IRoot> : 
    winrt::impl::impl_hash_unknown<winrt::Composable::Base::IRoot> {};

template<> struct hash<winrt::Composable::Base::IRootFactory> : 
    winrt::impl::impl_hash_unknown<winrt::Composable::Base::IRootFactory> {};

template<> struct hash<winrt::Composable::Base::IRootOverrides> : 
    winrt::impl::impl_hash_unknown<winrt::Composable::Base::IRootOverrides> {};

template<> struct hash<winrt::Composable::Base::Derived> : 
    winrt::impl::impl_hash_unknown<winrt::Composable::Base::Derived> {};

template<> struct hash<winrt::Composable::Base::Root> : 
    winrt::impl::impl_hash_unknown<winrt::Composable::Base::Root> {};

}
