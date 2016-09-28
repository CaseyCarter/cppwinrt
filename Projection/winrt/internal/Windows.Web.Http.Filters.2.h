// C++ for the Windows Runtime v1.29
// Copyright (c) 2016 Microsoft Corporation

#pragma once

#include "Windows.Web.Http.Filters.1.h"
#include "Windows.Foundation.2.h"

WINRT_EXPORT namespace winrt {

namespace ABI::Windows::Foundation::Collections {

#ifndef WINRT_GENERIC_0c7d1423_e8fd_5a91_b55c_8bfbe7ac2d40
#define WINRT_GENERIC_0c7d1423_e8fd_5a91_b55c_8bfbe7ac2d40
template <> struct __declspec(uuid("0c7d1423-e8fd-5a91-b55c-8bfbe7ac2d40")) __declspec(novtable) IIterable<Windows::Security::Cryptography::Certificates::Certificate> : impl_IIterable<Windows::Security::Cryptography::Certificates::Certificate> {};
#endif

#ifndef WINRT_GENERIC_963f7013_77c2_51c5_8038_b5bcef633edb
#define WINRT_GENERIC_963f7013_77c2_51c5_8038_b5bcef633edb
template <> struct __declspec(uuid("963f7013-77c2-51c5-8038-b5bcef633edb")) __declspec(novtable) IVectorView<Windows::Security::Cryptography::Certificates::Certificate> : impl_IVectorView<Windows::Security::Cryptography::Certificates::Certificate> {};
#endif

#ifndef WINRT_GENERIC_cb383486_c2bc_5756_912d_6a708a07e5bd
#define WINRT_GENERIC_cb383486_c2bc_5756_912d_6a708a07e5bd
template <> struct __declspec(uuid("cb383486-c2bc-5756-912d-6a708a07e5bd")) __declspec(novtable) IVectorView<winrt::Windows::Security::Cryptography::Certificates::ChainValidationResult> : impl_IVectorView<winrt::Windows::Security::Cryptography::Certificates::ChainValidationResult> {};
#endif

#ifndef WINRT_GENERIC_d7828cf7_4301_58d3_aab5_06e5eefcf79f
#define WINRT_GENERIC_d7828cf7_4301_58d3_aab5_06e5eefcf79f
template <> struct __declspec(uuid("d7828cf7-4301-58d3-aab5-06e5eefcf79f")) __declspec(novtable) IVector<winrt::Windows::Security::Cryptography::Certificates::ChainValidationResult> : impl_IVector<winrt::Windows::Security::Cryptography::Certificates::ChainValidationResult> {};
#endif


}

namespace ABI::Windows::Foundation {

#ifndef WINRT_GENERIC_5d144364_77d7_5eca_8b09_936a69446652
#define WINRT_GENERIC_5d144364_77d7_5eca_8b09_936a69446652
template <> struct __declspec(uuid("5d144364-77d7-5eca-8b09-936a69446652")) __declspec(novtable) IAsyncOperationWithProgress<Windows::Web::Http::HttpResponseMessage, Windows::Web::Http::HttpProgress> : impl_IAsyncOperationWithProgress<Windows::Web::Http::HttpResponseMessage, Windows::Web::Http::HttpProgress> {};
#endif

#ifndef WINRT_GENERIC_ed0260c6_41f2_5a04_9a8b_2930d7ff8a9e
#define WINRT_GENERIC_ed0260c6_41f2_5a04_9a8b_2930d7ff8a9e
template <> struct __declspec(uuid("ed0260c6-41f2-5a04-9a8b-2930d7ff8a9e")) __declspec(novtable) TypedEventHandler<Windows::Web::Http::Filters::HttpBaseProtocolFilter, Windows::Web::Http::Filters::HttpServerCustomValidationRequestedEventArgs> : impl_TypedEventHandler<Windows::Web::Http::Filters::HttpBaseProtocolFilter, Windows::Web::Http::Filters::HttpServerCustomValidationRequestedEventArgs> {};
#endif


}

namespace ABI::Windows::Foundation::Collections {

#ifndef WINRT_GENERIC_676fc159_f15c_58bd_91a7_28f7e795c756
#define WINRT_GENERIC_676fc159_f15c_58bd_91a7_28f7e795c756
template <> struct __declspec(uuid("676fc159-f15c-58bd-91a7-28f7e795c756")) __declspec(novtable) IIterator<Windows::Security::Cryptography::Certificates::Certificate> : impl_IIterator<Windows::Security::Cryptography::Certificates::Certificate> {};
#endif

#ifndef WINRT_GENERIC_8bcad2b7_0e3b_5eae_bf69_e1f6d9c888f8
#define WINRT_GENERIC_8bcad2b7_0e3b_5eae_bf69_e1f6d9c888f8
template <> struct __declspec(uuid("8bcad2b7-0e3b-5eae-bf69-e1f6d9c888f8")) __declspec(novtable) IIterator<winrt::Windows::Security::Cryptography::Certificates::ChainValidationResult> : impl_IIterator<winrt::Windows::Security::Cryptography::Certificates::ChainValidationResult> {};
#endif

#ifndef WINRT_GENERIC_2628f58f_3f02_54f2_808f_e1117709d6d0
#define WINRT_GENERIC_2628f58f_3f02_54f2_808f_e1117709d6d0
template <> struct __declspec(uuid("2628f58f-3f02-54f2-808f-e1117709d6d0")) __declspec(novtable) IIterable<winrt::Windows::Security::Cryptography::Certificates::ChainValidationResult> : impl_IIterable<winrt::Windows::Security::Cryptography::Certificates::ChainValidationResult> {};
#endif


}

namespace ABI::Windows::Foundation {

#ifndef WINRT_GENERIC_68e4606a_76ec_5816_b2fe_a04ecde4126a
#define WINRT_GENERIC_68e4606a_76ec_5816_b2fe_a04ecde4126a
template <> struct __declspec(uuid("68e4606a-76ec-5816-b2fe-a04ecde4126a")) __declspec(novtable) AsyncOperationProgressHandler<Windows::Web::Http::HttpResponseMessage, Windows::Web::Http::HttpProgress> : impl_AsyncOperationProgressHandler<Windows::Web::Http::HttpResponseMessage, Windows::Web::Http::HttpProgress> {};
#endif

#ifndef WINRT_GENERIC_beadb572_f9a3_5e93_b6ca_e311b65933fc
#define WINRT_GENERIC_beadb572_f9a3_5e93_b6ca_e311b65933fc
template <> struct __declspec(uuid("beadb572-f9a3-5e93-b6ca-e311b65933fc")) __declspec(novtable) AsyncOperationWithProgressCompletedHandler<Windows::Web::Http::HttpResponseMessage, Windows::Web::Http::HttpProgress> : impl_AsyncOperationWithProgressCompletedHandler<Windows::Web::Http::HttpResponseMessage, Windows::Web::Http::HttpProgress> {};
#endif


}

namespace Windows::Web::Http::Filters {

template <typename D>
struct WINRT_EBO impl_IHttpBaseProtocolFilter
{
    bool AllowAutoRedirect() const;
    void AllowAutoRedirect(bool value) const;
    bool AllowUI() const;
    void AllowUI(bool value) const;
    bool AutomaticDecompression() const;
    void AutomaticDecompression(bool value) const;
    Windows::Web::Http::Filters::HttpCacheControl CacheControl() const;
    Windows::Web::Http::HttpCookieManager CookieManager() const;
    Windows::Security::Cryptography::Certificates::Certificate ClientCertificate() const;
    void ClientCertificate(const Windows::Security::Cryptography::Certificates::Certificate & value) const;
    Windows::Foundation::Collections::IVector<winrt::Windows::Security::Cryptography::Certificates::ChainValidationResult> IgnorableServerCertificateErrors() const;
    uint32_t MaxConnectionsPerServer() const;
    void MaxConnectionsPerServer(uint32_t value) const;
    Windows::Security::Credentials::PasswordCredential ProxyCredential() const;
    void ProxyCredential(const Windows::Security::Credentials::PasswordCredential & value) const;
    Windows::Security::Credentials::PasswordCredential ServerCredential() const;
    void ServerCredential(const Windows::Security::Credentials::PasswordCredential & value) const;
    bool UseProxy() const;
    void UseProxy(bool value) const;
};

template <typename D>
struct WINRT_EBO impl_IHttpBaseProtocolFilter2
{
    Windows::Web::Http::HttpVersion MaxVersion() const;
    void MaxVersion(Windows::Web::Http::HttpVersion value) const;
};

template <typename D>
struct WINRT_EBO impl_IHttpBaseProtocolFilter3
{
    Windows::Web::Http::Filters::HttpCookieUsageBehavior CookieUsageBehavior() const;
    void CookieUsageBehavior(Windows::Web::Http::Filters::HttpCookieUsageBehavior value) const;
};

template <typename D>
struct WINRT_EBO impl_IHttpBaseProtocolFilter4
{
    event_token ServerCustomValidationRequested(const Windows::Foundation::TypedEventHandler<Windows::Web::Http::Filters::HttpBaseProtocolFilter, Windows::Web::Http::Filters::HttpServerCustomValidationRequestedEventArgs> & eventHandler) const;
    using ServerCustomValidationRequested_revoker = event_revoker<IHttpBaseProtocolFilter4>;
    ServerCustomValidationRequested_revoker ServerCustomValidationRequested(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Web::Http::Filters::HttpBaseProtocolFilter, Windows::Web::Http::Filters::HttpServerCustomValidationRequestedEventArgs> & eventHandler) const;
    void ServerCustomValidationRequested(event_token eventCookie) const;
    void ClearAuthenticationCache() const;
};

template <typename D>
struct WINRT_EBO impl_IHttpCacheControl
{
    Windows::Web::Http::Filters::HttpCacheReadBehavior ReadBehavior() const;
    void ReadBehavior(Windows::Web::Http::Filters::HttpCacheReadBehavior value) const;
    Windows::Web::Http::Filters::HttpCacheWriteBehavior WriteBehavior() const;
    void WriteBehavior(Windows::Web::Http::Filters::HttpCacheWriteBehavior value) const;
};

template <typename D>
struct WINRT_EBO impl_IHttpFilter
{
    Windows::Foundation::IAsyncOperationWithProgress<Windows::Web::Http::HttpResponseMessage, Windows::Web::Http::HttpProgress> SendRequestAsync(const Windows::Web::Http::HttpRequestMessage & request) const;
};

template <typename D>
struct WINRT_EBO impl_IHttpServerCustomValidationRequestedEventArgs
{
    Windows::Web::Http::HttpRequestMessage RequestMessage() const;
    Windows::Security::Cryptography::Certificates::Certificate ServerCertificate() const;
    Windows::Networking::Sockets::SocketSslErrorSeverity ServerCertificateErrorSeverity() const;
    Windows::Foundation::Collections::IVectorView<winrt::Windows::Security::Cryptography::Certificates::ChainValidationResult> ServerCertificateErrors() const;
    Windows::Foundation::Collections::IVectorView<Windows::Security::Cryptography::Certificates::Certificate> ServerIntermediateCertificates() const;
    void Reject() const;
    Windows::Foundation::Deferral GetDeferral() const;
};

struct IHttpBaseProtocolFilter :
    Windows::IInspectable,
    impl::consume<IHttpBaseProtocolFilter>,
    impl::require<IHttpBaseProtocolFilter, Windows::Foundation::IClosable, Windows::Web::Http::Filters::IHttpFilter>
{
    IHttpBaseProtocolFilter(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IHttpBaseProtocolFilter>(m_ptr); }
};

struct IHttpBaseProtocolFilter2 :
    Windows::IInspectable,
    impl::consume<IHttpBaseProtocolFilter2>,
    impl::require<IHttpBaseProtocolFilter2, Windows::Foundation::IClosable, Windows::Web::Http::Filters::IHttpFilter>
{
    IHttpBaseProtocolFilter2(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IHttpBaseProtocolFilter2>(m_ptr); }
};

struct IHttpBaseProtocolFilter3 :
    Windows::IInspectable,
    impl::consume<IHttpBaseProtocolFilter3>,
    impl::require<IHttpBaseProtocolFilter3, Windows::Foundation::IClosable, Windows::Web::Http::Filters::IHttpFilter>
{
    IHttpBaseProtocolFilter3(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IHttpBaseProtocolFilter3>(m_ptr); }
};

struct IHttpBaseProtocolFilter4 :
    Windows::IInspectable,
    impl::consume<IHttpBaseProtocolFilter4>,
    impl::require<IHttpBaseProtocolFilter4, Windows::Foundation::IClosable, Windows::Web::Http::Filters::IHttpFilter>
{
    IHttpBaseProtocolFilter4(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IHttpBaseProtocolFilter4>(m_ptr); }
};

struct IHttpCacheControl :
    Windows::IInspectable,
    impl::consume<IHttpCacheControl>
{
    IHttpCacheControl(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IHttpCacheControl>(m_ptr); }
};

struct IHttpFilter :
    Windows::IInspectable,
    impl::consume<IHttpFilter>,
    impl::require<IHttpFilter, Windows::Foundation::IClosable>
{
    IHttpFilter(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IHttpFilter>(m_ptr); }
};

struct IHttpServerCustomValidationRequestedEventArgs :
    Windows::IInspectable,
    impl::consume<IHttpServerCustomValidationRequestedEventArgs>
{
    IHttpServerCustomValidationRequestedEventArgs(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IHttpServerCustomValidationRequestedEventArgs>(m_ptr); }
};

}

}
