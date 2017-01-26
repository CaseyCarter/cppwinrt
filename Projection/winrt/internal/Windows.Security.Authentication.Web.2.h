// C++ for the Windows Runtime v1.0.private
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "Windows.Security.Authentication.Web.1.h"

WINRT_EXPORT namespace winrt {

namespace ABI::Windows::Foundation {

#ifndef WINRT_GENERIC_b34952ac_265e_5947_8735_e9318f4301ff
#define WINRT_GENERIC_b34952ac_265e_5947_8735_e9318f4301ff
template <> struct __declspec(uuid("b34952ac-265e-5947-8735-e9318f4301ff")) __declspec(novtable) IAsyncOperation<Windows::Security::Authentication::Web::WebAuthenticationResult> : impl_IAsyncOperation<Windows::Security::Authentication::Web::WebAuthenticationResult> {};
#endif

#ifndef WINRT_GENERIC_3c1ec44c_e942_54e5_bcd3_e329c951f595
#define WINRT_GENERIC_3c1ec44c_e942_54e5_bcd3_e329c951f595
template <> struct __declspec(uuid("3c1ec44c-e942-54e5-bcd3-e329c951f595")) __declspec(novtable) AsyncOperationCompletedHandler<Windows::Security::Authentication::Web::WebAuthenticationResult> : impl_AsyncOperationCompletedHandler<Windows::Security::Authentication::Web::WebAuthenticationResult> {};
#endif


}

namespace Windows::Security::Authentication::Web {

struct IWebAuthenticationBrokerStatics :
    Windows::IInspectable,
    impl::consume<IWebAuthenticationBrokerStatics>
{
    IWebAuthenticationBrokerStatics(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IWebAuthenticationBrokerStatics>(m_ptr); }
};

struct IWebAuthenticationBrokerStatics2 :
    Windows::IInspectable,
    impl::consume<IWebAuthenticationBrokerStatics2>
{
    IWebAuthenticationBrokerStatics2(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IWebAuthenticationBrokerStatics2>(m_ptr); }
};

struct IWebAuthenticationResult :
    Windows::IInspectable,
    impl::consume<IWebAuthenticationResult>
{
    IWebAuthenticationResult(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IWebAuthenticationResult>(m_ptr); }
};

}

}
