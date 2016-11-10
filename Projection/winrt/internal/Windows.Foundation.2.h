// C++ for the Windows Runtime v1.0.private
// Copyright (c) 2016 Microsoft Corporation. All rights reserved.

#pragma once

#include "Windows.Foundation.1.h"

WINRT_EXPORT namespace winrt {

namespace ABI::Windows::Foundation::Collections {

#ifndef WINRT_GENERIC_b1f00d3b_1f06_5117_93ea_2a0d79116701
#define WINRT_GENERIC_b1f00d3b_1f06_5117_93ea_2a0d79116701
template <> struct __declspec(uuid("b1f00d3b-1f06-5117-93ea-2a0d79116701")) __declspec(novtable) IVectorView<Windows::Foundation::IWwwFormUrlDecoderEntry> : impl_IVectorView<Windows::Foundation::IWwwFormUrlDecoderEntry> {};
#endif

#ifndef WINRT_GENERIC_876be83b_7218_5bfb_a169_83152ef7e146
#define WINRT_GENERIC_876be83b_7218_5bfb_a169_83152ef7e146
template <> struct __declspec(uuid("876be83b-7218-5bfb-a169-83152ef7e146")) __declspec(novtable) IIterable<Windows::Foundation::IWwwFormUrlDecoderEntry> : impl_IIterable<Windows::Foundation::IWwwFormUrlDecoderEntry> {};
#endif


}

namespace ABI::Windows::Foundation {

#ifndef WINRT_GENERIC_f4637d4a_0760_5431_bfc0_24eb1d4f6c4f
#define WINRT_GENERIC_f4637d4a_0760_5431_bfc0_24eb1d4f6c4f
template <> struct __declspec(uuid("f4637d4a-0760-5431-bfc0-24eb1d4f6c4f")) __declspec(novtable) TypedEventHandler<Windows::Foundation::IMemoryBufferReference, Windows::IInspectable> : impl_TypedEventHandler<Windows::Foundation::IMemoryBufferReference, Windows::IInspectable> {};
#endif


}

namespace ABI::Windows::Foundation::Collections {

#ifndef WINRT_GENERIC_32e54295_373c_50cb_80a1_468a990ca780
#define WINRT_GENERIC_32e54295_373c_50cb_80a1_468a990ca780
template <> struct __declspec(uuid("32e54295-373c-50cb-80a1-468a990ca780")) __declspec(novtable) IIterator<Windows::Foundation::IWwwFormUrlDecoderEntry> : impl_IIterator<Windows::Foundation::IWwwFormUrlDecoderEntry> {};
#endif


}

namespace Windows::Foundation {

struct DeferralCompletedHandler : Windows::IUnknown
{
    DeferralCompletedHandler(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<DeferralCompletedHandler>(m_ptr); }
    template <typename L> DeferralCompletedHandler(L lambda);
    template <typename F> DeferralCompletedHandler (F * function);
    template <typename O, typename M> DeferralCompletedHandler(O * object, M method);
    void operator()() const;
};

struct IClosable :
    Windows::IInspectable,
    impl::consume<IClosable>
{
    IClosable(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IClosable>(m_ptr); }
};

struct IDeferral :
    Windows::IInspectable,
    impl::consume<IDeferral>,
    impl::require<IDeferral, Windows::Foundation::IClosable>
{
    IDeferral(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IDeferral>(m_ptr); }
};

struct IDeferralFactory :
    Windows::IInspectable,
    impl::consume<IDeferralFactory>
{
    IDeferralFactory(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IDeferralFactory>(m_ptr); }
};

struct IGetActivationFactory :
    Windows::IInspectable,
    impl::consume<IGetActivationFactory>
{
    IGetActivationFactory(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IGetActivationFactory>(m_ptr); }
};

struct IMemoryBuffer :
    Windows::IInspectable,
    impl::consume<IMemoryBuffer>,
    impl::require<IMemoryBuffer, Windows::Foundation::IClosable>
{
    IMemoryBuffer(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IMemoryBuffer>(m_ptr); }
};

struct IMemoryBufferFactory :
    Windows::IInspectable,
    impl::consume<IMemoryBufferFactory>
{
    IMemoryBufferFactory(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IMemoryBufferFactory>(m_ptr); }
};

struct IMemoryBufferReference :
    Windows::IInspectable,
    impl::consume<IMemoryBufferReference>,
    impl::require<IMemoryBufferReference, Windows::Foundation::IClosable>
{
    IMemoryBufferReference(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IMemoryBufferReference>(m_ptr); }
};

struct IPropertyValue :
    Windows::IInspectable,
    impl::consume<IPropertyValue>
{
    IPropertyValue(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IPropertyValue>(m_ptr); }
};

struct IPropertyValueStatics :
    Windows::IInspectable,
    impl::consume<IPropertyValueStatics>
{
    IPropertyValueStatics(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IPropertyValueStatics>(m_ptr); }
};

struct IStringable :
    Windows::IInspectable,
    impl::consume<IStringable>
{
    IStringable(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IStringable>(m_ptr); }
};

struct IUriEscapeStatics :
    Windows::IInspectable,
    impl::consume<IUriEscapeStatics>
{
    IUriEscapeStatics(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IUriEscapeStatics>(m_ptr); }
};

struct IUriRuntimeClass :
    Windows::IInspectable,
    impl::consume<IUriRuntimeClass>
{
    IUriRuntimeClass(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IUriRuntimeClass>(m_ptr); }
};

struct IUriRuntimeClassFactory :
    Windows::IInspectable,
    impl::consume<IUriRuntimeClassFactory>
{
    IUriRuntimeClassFactory(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IUriRuntimeClassFactory>(m_ptr); }
};

struct IUriRuntimeClassWithAbsoluteCanonicalUri :
    Windows::IInspectable,
    impl::consume<IUriRuntimeClassWithAbsoluteCanonicalUri>
{
    IUriRuntimeClassWithAbsoluteCanonicalUri(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IUriRuntimeClassWithAbsoluteCanonicalUri>(m_ptr); }
};

struct IWwwFormUrlDecoderEntry :
    Windows::IInspectable,
    impl::consume<IWwwFormUrlDecoderEntry>
{
    IWwwFormUrlDecoderEntry(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IWwwFormUrlDecoderEntry>(m_ptr); }
};

struct IWwwFormUrlDecoderRuntimeClass :
    Windows::IInspectable,
    impl::consume<IWwwFormUrlDecoderRuntimeClass>,
    impl::require<IWwwFormUrlDecoderRuntimeClass, Windows::Foundation::Collections::IIterable<Windows::Foundation::IWwwFormUrlDecoderEntry>, Windows::Foundation::Collections::IVectorView<Windows::Foundation::IWwwFormUrlDecoderEntry>>
{
    IWwwFormUrlDecoderRuntimeClass(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IWwwFormUrlDecoderRuntimeClass>(m_ptr); }
};

struct IWwwFormUrlDecoderRuntimeClassFactory :
    Windows::IInspectable,
    impl::consume<IWwwFormUrlDecoderRuntimeClassFactory>
{
    IWwwFormUrlDecoderRuntimeClassFactory(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IWwwFormUrlDecoderRuntimeClassFactory>(m_ptr); }
};

}

}
