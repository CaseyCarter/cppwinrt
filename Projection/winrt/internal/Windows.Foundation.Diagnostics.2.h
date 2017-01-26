// C++ for the Windows Runtime v1.0.private
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "Windows.Foundation.Diagnostics.1.h"
#include "Windows.Foundation.1.h"

WINRT_EXPORT namespace winrt {

namespace ABI::Windows::Foundation {

#ifndef WINRT_GENERIC_2bf27008_2eb4_5675_b1cd_e9906cc5ce64
#define WINRT_GENERIC_2bf27008_2eb4_5675_b1cd_e9906cc5ce64
template <> struct __declspec(uuid("2bf27008-2eb4-5675-b1cd-e9906cc5ce64")) __declspec(novtable) EventHandler<Windows::Foundation::Diagnostics::TracingStatusChangedEventArgs> : impl_EventHandler<Windows::Foundation::Diagnostics::TracingStatusChangedEventArgs> {};
#endif

#ifndef WINRT_GENERIC_5e52f8ce_aced_5a42_95b4_f674dd84885e
#define WINRT_GENERIC_5e52f8ce_aced_5a42_95b4_f674dd84885e
template <> struct __declspec(uuid("5e52f8ce-aced-5a42-95b4-f674dd84885e")) __declspec(novtable) IAsyncOperation<Windows::Storage::StorageFile> : impl_IAsyncOperation<Windows::Storage::StorageFile> {};
#endif

#ifndef WINRT_GENERIC_9b05106d_77e0_5c24_82b0_9b2dc8f79671
#define WINRT_GENERIC_9b05106d_77e0_5c24_82b0_9b2dc8f79671
template <> struct __declspec(uuid("9b05106d-77e0-5c24-82b0-9b2dc8f79671")) __declspec(novtable) IAsyncOperation<Windows::Foundation::Diagnostics::ErrorDetails> : impl_IAsyncOperation<Windows::Foundation::Diagnostics::ErrorDetails> {};
#endif

#ifndef WINRT_GENERIC_52c9c2a1_54a3_5ef9_9aff_014e7c454655
#define WINRT_GENERIC_52c9c2a1_54a3_5ef9_9aff_014e7c454655
template <> struct __declspec(uuid("52c9c2a1-54a3-5ef9-9aff-014e7c454655")) __declspec(novtable) TypedEventHandler<Windows::Foundation::Diagnostics::ILoggingChannel, Windows::IInspectable> : impl_TypedEventHandler<Windows::Foundation::Diagnostics::ILoggingChannel, Windows::IInspectable> {};
#endif

#ifndef WINRT_GENERIC_0c6563b0_9d8b_5b60_994b_dee1174d1efb
#define WINRT_GENERIC_0c6563b0_9d8b_5b60_994b_dee1174d1efb
template <> struct __declspec(uuid("0c6563b0-9d8b-5b60-994b-dee1174d1efb")) __declspec(novtable) TypedEventHandler<Windows::Foundation::Diagnostics::IFileLoggingSession, Windows::Foundation::Diagnostics::LogFileGeneratedEventArgs> : impl_TypedEventHandler<Windows::Foundation::Diagnostics::IFileLoggingSession, Windows::Foundation::Diagnostics::LogFileGeneratedEventArgs> {};
#endif

#ifndef WINRT_GENERIC_e521c894_2c26_5946_9e61_2b5e188d01ed
#define WINRT_GENERIC_e521c894_2c26_5946_9e61_2b5e188d01ed
template <> struct __declspec(uuid("e521c894-2c26-5946-9e61-2b5e188d01ed")) __declspec(novtable) AsyncOperationCompletedHandler<Windows::Storage::StorageFile> : impl_AsyncOperationCompletedHandler<Windows::Storage::StorageFile> {};
#endif

#ifndef WINRT_GENERIC_a6997f9d_7195_5972_8ecd_1c73aa5cb312
#define WINRT_GENERIC_a6997f9d_7195_5972_8ecd_1c73aa5cb312
template <> struct __declspec(uuid("a6997f9d-7195-5972-8ecd-1c73aa5cb312")) __declspec(novtable) AsyncOperationCompletedHandler<Windows::Foundation::Diagnostics::ErrorDetails> : impl_AsyncOperationCompletedHandler<Windows::Foundation::Diagnostics::ErrorDetails> {};
#endif


}

namespace Windows::Foundation::Diagnostics {

struct IAsyncCausalityTracerStatics :
    Windows::IInspectable,
    impl::consume<IAsyncCausalityTracerStatics>
{
    IAsyncCausalityTracerStatics(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IAsyncCausalityTracerStatics>(m_ptr); }
};

struct IErrorDetails :
    Windows::IInspectable,
    impl::consume<IErrorDetails>
{
    IErrorDetails(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IErrorDetails>(m_ptr); }
};

struct IErrorDetailsStatics :
    Windows::IInspectable,
    impl::consume<IErrorDetailsStatics>
{
    IErrorDetailsStatics(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IErrorDetailsStatics>(m_ptr); }
};

struct IErrorReportingSettings :
    Windows::IInspectable,
    impl::consume<IErrorReportingSettings>
{
    IErrorReportingSettings(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IErrorReportingSettings>(m_ptr); }
};

struct IFileLoggingSession :
    Windows::IInspectable,
    impl::consume<IFileLoggingSession>,
    impl::require<IFileLoggingSession, Windows::Foundation::IClosable>
{
    IFileLoggingSession(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IFileLoggingSession>(m_ptr); }
};

struct IFileLoggingSessionFactory :
    Windows::IInspectable,
    impl::consume<IFileLoggingSessionFactory>
{
    IFileLoggingSessionFactory(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IFileLoggingSessionFactory>(m_ptr); }
};

struct ILogFileGeneratedEventArgs :
    Windows::IInspectable,
    impl::consume<ILogFileGeneratedEventArgs>
{
    ILogFileGeneratedEventArgs(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<ILogFileGeneratedEventArgs>(m_ptr); }
};

struct ILoggingActivity :
    Windows::IInspectable,
    impl::consume<ILoggingActivity>,
    impl::require<ILoggingActivity, Windows::Foundation::IClosable>
{
    ILoggingActivity(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<ILoggingActivity>(m_ptr); }
};

struct ILoggingActivity2 :
    Windows::IInspectable,
    impl::consume<ILoggingActivity2>,
    impl::require<ILoggingActivity2, Windows::Foundation::Diagnostics::ILoggingActivity, Windows::Foundation::Diagnostics::ILoggingTarget, Windows::Foundation::IClosable>
{
    ILoggingActivity2(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<ILoggingActivity2>(m_ptr); }
};

struct ILoggingActivityFactory :
    Windows::IInspectable,
    impl::consume<ILoggingActivityFactory>
{
    ILoggingActivityFactory(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<ILoggingActivityFactory>(m_ptr); }
};

struct ILoggingChannel :
    Windows::IInspectable,
    impl::consume<ILoggingChannel>,
    impl::require<ILoggingChannel, Windows::Foundation::IClosable>
{
    ILoggingChannel(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<ILoggingChannel>(m_ptr); }
};

struct ILoggingChannel2 :
    Windows::IInspectable,
    impl::consume<ILoggingChannel2>,
    impl::require<ILoggingChannel2, Windows::Foundation::Diagnostics::ILoggingChannel, Windows::Foundation::Diagnostics::ILoggingTarget, Windows::Foundation::IClosable>
{
    ILoggingChannel2(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<ILoggingChannel2>(m_ptr); }
};

struct ILoggingChannelFactory :
    Windows::IInspectable,
    impl::consume<ILoggingChannelFactory>
{
    ILoggingChannelFactory(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<ILoggingChannelFactory>(m_ptr); }
};

struct ILoggingChannelFactory2 :
    Windows::IInspectable,
    impl::consume<ILoggingChannelFactory2>
{
    ILoggingChannelFactory2(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<ILoggingChannelFactory2>(m_ptr); }
};

struct ILoggingChannelOptions :
    Windows::IInspectable,
    impl::consume<ILoggingChannelOptions>
{
    ILoggingChannelOptions(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<ILoggingChannelOptions>(m_ptr); }
};

struct ILoggingChannelOptionsFactory :
    Windows::IInspectable,
    impl::consume<ILoggingChannelOptionsFactory>
{
    ILoggingChannelOptionsFactory(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<ILoggingChannelOptionsFactory>(m_ptr); }
};

struct ILoggingFields :
    Windows::IInspectable,
    impl::consume<ILoggingFields>
{
    ILoggingFields(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<ILoggingFields>(m_ptr); }
};

struct ILoggingOptions :
    Windows::IInspectable,
    impl::consume<ILoggingOptions>
{
    ILoggingOptions(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<ILoggingOptions>(m_ptr); }
};

struct ILoggingOptionsFactory :
    Windows::IInspectable,
    impl::consume<ILoggingOptionsFactory>
{
    ILoggingOptionsFactory(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<ILoggingOptionsFactory>(m_ptr); }
};

struct ILoggingSession :
    Windows::IInspectable,
    impl::consume<ILoggingSession>,
    impl::require<ILoggingSession, Windows::Foundation::IClosable>
{
    ILoggingSession(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<ILoggingSession>(m_ptr); }
};

struct ILoggingSessionFactory :
    Windows::IInspectable,
    impl::consume<ILoggingSessionFactory>
{
    ILoggingSessionFactory(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<ILoggingSessionFactory>(m_ptr); }
};

struct ILoggingTarget :
    Windows::IInspectable,
    impl::consume<ILoggingTarget>
{
    ILoggingTarget(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<ILoggingTarget>(m_ptr); }
};

struct ITracingStatusChangedEventArgs :
    Windows::IInspectable,
    impl::consume<ITracingStatusChangedEventArgs>
{
    ITracingStatusChangedEventArgs(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<ITracingStatusChangedEventArgs>(m_ptr); }
};

}

}
