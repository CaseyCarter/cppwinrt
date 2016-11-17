// C++ for the Windows Runtime v1.0.private
// Copyright (c) 2016 Microsoft Corporation. All rights reserved.

#pragma once

#include "Windows.Graphics.Display.1.h"

WINRT_EXPORT namespace winrt {

namespace ABI::Windows::Foundation {

#ifndef WINRT_GENERIC_86c4f619_67b6_51c7_b30d_d8cf13625327
#define WINRT_GENERIC_86c4f619_67b6_51c7_b30d_d8cf13625327
template <> struct __declspec(uuid("86c4f619-67b6-51c7-b30d-d8cf13625327")) __declspec(novtable) TypedEventHandler<Windows::Graphics::Display::DisplayInformation, Windows::IInspectable> : impl_TypedEventHandler<Windows::Graphics::Display::DisplayInformation, Windows::IInspectable> {};
#endif

#ifndef WINRT_GENERIC_430ecece_1418_5d19_81b2_5ddb381603cc
#define WINRT_GENERIC_430ecece_1418_5d19_81b2_5ddb381603cc
template <> struct __declspec(uuid("430ecece-1418-5d19-81b2-5ddb381603cc")) __declspec(novtable) IAsyncOperation<Windows::Storage::Streams::IRandomAccessStream> : impl_IAsyncOperation<Windows::Storage::Streams::IRandomAccessStream> {};
#endif

#ifndef WINRT_GENERIC_2f2d6c29_5473_5f3e_92e7_96572bb990e2
#define WINRT_GENERIC_2f2d6c29_5473_5f3e_92e7_96572bb990e2
template <> struct __declspec(uuid("2f2d6c29-5473-5f3e-92e7-96572bb990e2")) __declspec(novtable) IReference<double> : impl_IReference<double> {};
#endif

#ifndef WINRT_GENERIC_398c4183_793d_5b00_819b_4aef92485e94
#define WINRT_GENERIC_398c4183_793d_5b00_819b_4aef92485e94
template <> struct __declspec(uuid("398c4183-793d-5b00-819b-4aef92485e94")) __declspec(novtable) AsyncOperationCompletedHandler<Windows::Storage::Streams::IRandomAccessStream> : impl_AsyncOperationCompletedHandler<Windows::Storage::Streams::IRandomAccessStream> {};
#endif


}

namespace Windows::Graphics::Display {

struct DisplayPropertiesEventHandler : Windows::IUnknown
{
    DisplayPropertiesEventHandler(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<DisplayPropertiesEventHandler>(m_ptr); }
    template <typename L> DisplayPropertiesEventHandler(L lambda);
    template <typename F> DisplayPropertiesEventHandler (F * function);
    template <typename O, typename M> DisplayPropertiesEventHandler(O * object, M method);
    void operator()(const Windows::IInspectable & sender) const;
};

struct IDisplayInformation :
    Windows::IInspectable,
    impl::consume<IDisplayInformation>
{
    IDisplayInformation(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IDisplayInformation>(m_ptr); }
};

struct IDisplayInformation2 :
    Windows::IInspectable,
    impl::consume<IDisplayInformation2>,
    impl::require<IDisplayInformation2, Windows::Graphics::Display::IDisplayInformation>
{
    IDisplayInformation2(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IDisplayInformation2>(m_ptr); }
};

struct IDisplayInformation3 :
    Windows::IInspectable,
    impl::consume<IDisplayInformation3>
{
    IDisplayInformation3(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IDisplayInformation3>(m_ptr); }
};

struct IDisplayInformation4 :
    Windows::IInspectable,
    impl::consume<IDisplayInformation4>
{
    IDisplayInformation4(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IDisplayInformation4>(m_ptr); }
};

struct IDisplayInformationStatics :
    Windows::IInspectable,
    impl::consume<IDisplayInformationStatics>
{
    IDisplayInformationStatics(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IDisplayInformationStatics>(m_ptr); }
};

struct IDisplayPropertiesStatics :
    Windows::IInspectable,
    impl::consume<IDisplayPropertiesStatics>
{
    IDisplayPropertiesStatics(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IDisplayPropertiesStatics>(m_ptr); }
};

}

}
