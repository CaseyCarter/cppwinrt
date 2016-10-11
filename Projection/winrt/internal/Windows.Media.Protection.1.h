// C++ for the Windows Runtime v1.0.private
// Copyright (c) 2016 Microsoft Corporation. All rights reserved.

#pragma once

#include "../base.h"
#include "Windows.Media.Protection.0.h"
#include "Windows.Foundation.0.h"
#include "Windows.Foundation.Collections.0.h"
#include "Windows.Media.Playback.0.h"
#include "Windows.Foundation.Collections.1.h"
#include "Windows.Foundation.1.h"

WINRT_EXPORT namespace winrt {

namespace ABI::Windows::Media::Protection {

struct __declspec(uuid("95da643c-6db9-424b-86ca-091af432081c")) __declspec(novtable) ComponentLoadFailedEventHandler : IUnknown
{
    virtual HRESULT __stdcall abi_Invoke(Windows::Media::Protection::IMediaProtectionManager * sender, Windows::Media::Protection::IComponentLoadFailedEventArgs * e) = 0;
};

struct __declspec(uuid("95972e93-7746-417e-8495-f031bbc5862c")) __declspec(novtable) IComponentLoadFailedEventArgs : Windows::IInspectable
{
    virtual HRESULT __stdcall get_Information(Windows::Media::Protection::IRevocationAndRenewalInformation ** value) = 0;
    virtual HRESULT __stdcall get_Completion(Windows::Media::Protection::IMediaProtectionServiceCompletion ** value) = 0;
};

struct __declspec(uuid("718845e9-64d7-426d-809b-1be461941a2a")) __declspec(novtable) IHdcpSession : Windows::IInspectable
{
    virtual HRESULT __stdcall abi_IsEffectiveProtectionAtLeast(winrt::Windows::Media::Protection::HdcpProtection protection, bool * value) = 0;
    virtual HRESULT __stdcall abi_GetEffectiveProtection(Windows::Foundation::IReference<winrt::Windows::Media::Protection::HdcpProtection> ** value) = 0;
    virtual HRESULT __stdcall abi_SetDesiredMinProtectionAsync(winrt::Windows::Media::Protection::HdcpProtection protection, Windows::Foundation::IAsyncOperation<winrt::Windows::Media::Protection::HdcpSetProtectionResult> ** value) = 0;
    virtual HRESULT __stdcall add_ProtectionChanged(Windows::Foundation::TypedEventHandler<Windows::Media::Protection::HdcpSession, Windows::IInspectable> * handler, event_token * token) = 0;
    virtual HRESULT __stdcall remove_ProtectionChanged(event_token token) = 0;
};

struct __declspec(uuid("45694947-c741-434b-a79e-474c12d93d2f")) __declspec(novtable) IMediaProtectionManager : Windows::IInspectable
{
    virtual HRESULT __stdcall add_ServiceRequested(Windows::Media::Protection::ServiceRequestedEventHandler * handler, event_token * cookie) = 0;
    virtual HRESULT __stdcall remove_ServiceRequested(event_token cookie) = 0;
    virtual HRESULT __stdcall add_RebootNeeded(Windows::Media::Protection::RebootNeededEventHandler * handler, event_token * cookie) = 0;
    virtual HRESULT __stdcall remove_RebootNeeded(event_token cookie) = 0;
    virtual HRESULT __stdcall add_ComponentLoadFailed(Windows::Media::Protection::ComponentLoadFailedEventHandler * handler, event_token * cookie) = 0;
    virtual HRESULT __stdcall remove_ComponentLoadFailed(event_token cookie) = 0;
    virtual HRESULT __stdcall get_Properties(Windows::Foundation::Collections::IPropertySet ** value) = 0;
};

struct __declspec(uuid("0c111226-7b26-4d31-95bb-9c1b08ef7fc0")) __declspec(novtable) IMediaProtectionPMPServer : Windows::IInspectable
{
    virtual HRESULT __stdcall get_Properties(Windows::Foundation::Collections::IPropertySet ** ppProperties) = 0;
};

struct __declspec(uuid("602c8e5e-f7d2-487e-af91-dbc4252b2182")) __declspec(novtable) IMediaProtectionPMPServerFactory : Windows::IInspectable
{
    virtual HRESULT __stdcall abi_CreatePMPServer(Windows::Foundation::Collections::IPropertySet * pProperties, Windows::Media::Protection::IMediaProtectionPMPServer ** ppObject) = 0;
};

struct __declspec(uuid("8b5cca18-cfd5-44ee-a2ed-df76010c14b5")) __declspec(novtable) IMediaProtectionServiceCompletion : Windows::IInspectable
{
    virtual HRESULT __stdcall abi_Complete(bool success) = 0;
};

struct __declspec(uuid("b1de0ea6-2094-478d-87a4-8b95200f85c6")) __declspec(novtable) IMediaProtectionServiceRequest : Windows::IInspectable
{
    virtual HRESULT __stdcall get_ProtectionSystem(GUID * system) = 0;
    virtual HRESULT __stdcall get_Type(GUID * type) = 0;
};

struct __declspec(uuid("c7ac5d7e-7480-4d29-a464-7bcd913dd8e4")) __declspec(novtable) IProtectionCapabilities : Windows::IInspectable
{
    virtual HRESULT __stdcall abi_IsTypeSupported(hstring type, hstring keySystem, winrt::Windows::Media::Protection::ProtectionCapabilityResult * value) = 0;
};

struct __declspec(uuid("f3a1937b-2501-439e-a6e7-6fc95e175fcf")) __declspec(novtable) IRevocationAndRenewalInformation : Windows::IInspectable
{
    virtual HRESULT __stdcall get_Items(Windows::Foundation::Collections::IVector<Windows::Media::Protection::RevocationAndRenewalItem> ** items) = 0;
};

struct __declspec(uuid("3099c20c-3cf0-49ea-902d-caf32d2dde2c")) __declspec(novtable) IRevocationAndRenewalItem : Windows::IInspectable
{
    virtual HRESULT __stdcall get_Reasons(winrt::Windows::Media::Protection::RevocationAndRenewalReasons * reasons) = 0;
    virtual HRESULT __stdcall get_HeaderHash(hstring * value) = 0;
    virtual HRESULT __stdcall get_PublicKeyHash(hstring * value) = 0;
    virtual HRESULT __stdcall get_Name(hstring * name) = 0;
    virtual HRESULT __stdcall get_RenewalId(hstring * value) = 0;
};

struct __declspec(uuid("34283baf-abb4-4fc1-bd89-93f106573a49")) __declspec(novtable) IServiceRequestedEventArgs : Windows::IInspectable
{
    virtual HRESULT __stdcall get_Request(Windows::Media::Protection::IMediaProtectionServiceRequest ** value) = 0;
    virtual HRESULT __stdcall get_Completion(Windows::Media::Protection::IMediaProtectionServiceCompletion ** value) = 0;
};

struct __declspec(uuid("553c69d6-fafe-4128-8dfa-130e398a13a7")) __declspec(novtable) IServiceRequestedEventArgs2 : Windows::IInspectable
{
    virtual HRESULT __stdcall get_MediaPlaybackItem(Windows::Media::Playback::IMediaPlaybackItem ** value) = 0;
};

struct __declspec(uuid("64e12a45-973b-4a3a-b260-91898a49a82c")) __declspec(novtable) RebootNeededEventHandler : IUnknown
{
    virtual HRESULT __stdcall abi_Invoke(Windows::Media::Protection::IMediaProtectionManager * sender) = 0;
};

struct __declspec(uuid("d2d690ba-cac9-48e1-95c0-d38495a84055")) __declspec(novtable) ServiceRequestedEventHandler : IUnknown
{
    virtual HRESULT __stdcall abi_Invoke(Windows::Media::Protection::IMediaProtectionManager * sender, Windows::Media::Protection::IServiceRequestedEventArgs * e) = 0;
};

}

namespace ABI {

template <> struct traits<Windows::Media::Protection::ComponentLoadFailedEventArgs> { using default_interface = Windows::Media::Protection::IComponentLoadFailedEventArgs; };
template <> struct traits<Windows::Media::Protection::HdcpSession> { using default_interface = Windows::Media::Protection::IHdcpSession; };
template <> struct traits<Windows::Media::Protection::MediaProtectionManager> { using default_interface = Windows::Media::Protection::IMediaProtectionManager; };
template <> struct traits<Windows::Media::Protection::MediaProtectionPMPServer> { using default_interface = Windows::Media::Protection::IMediaProtectionPMPServer; };
template <> struct traits<Windows::Media::Protection::MediaProtectionServiceCompletion> { using default_interface = Windows::Media::Protection::IMediaProtectionServiceCompletion; };
template <> struct traits<Windows::Media::Protection::ProtectionCapabilities> { using default_interface = Windows::Media::Protection::IProtectionCapabilities; };
template <> struct traits<Windows::Media::Protection::RevocationAndRenewalInformation> { using default_interface = Windows::Media::Protection::IRevocationAndRenewalInformation; };
template <> struct traits<Windows::Media::Protection::RevocationAndRenewalItem> { using default_interface = Windows::Media::Protection::IRevocationAndRenewalItem; };
template <> struct traits<Windows::Media::Protection::ServiceRequestedEventArgs> { using default_interface = Windows::Media::Protection::IServiceRequestedEventArgs; };

}

namespace Windows::Media::Protection {

template <typename T> struct impl_IComponentLoadFailedEventArgs;
template <typename T> struct impl_IHdcpSession;
template <typename T> struct impl_IMediaProtectionManager;
template <typename T> struct impl_IMediaProtectionPMPServer;
template <typename T> struct impl_IMediaProtectionPMPServerFactory;
template <typename T> struct impl_IMediaProtectionServiceCompletion;
template <typename T> struct impl_IMediaProtectionServiceRequest;
template <typename T> struct impl_IProtectionCapabilities;
template <typename T> struct impl_IRevocationAndRenewalInformation;
template <typename T> struct impl_IRevocationAndRenewalItem;
template <typename T> struct impl_IServiceRequestedEventArgs;
template <typename T> struct impl_IServiceRequestedEventArgs2;
template <typename T> struct impl_ComponentLoadFailedEventHandler;
template <typename T> struct impl_RebootNeededEventHandler;
template <typename T> struct impl_ServiceRequestedEventHandler;

}

namespace impl {

template <> struct traits<Windows::Media::Protection::ComponentLoadFailedEventHandler>
{
    using abi = ABI::Windows::Media::Protection::ComponentLoadFailedEventHandler;
};

template <> struct traits<Windows::Media::Protection::IComponentLoadFailedEventArgs>
{
    using abi = ABI::Windows::Media::Protection::IComponentLoadFailedEventArgs;
    template <typename D> using consume = Windows::Media::Protection::impl_IComponentLoadFailedEventArgs<D>;
};

template <> struct traits<Windows::Media::Protection::IHdcpSession>
{
    using abi = ABI::Windows::Media::Protection::IHdcpSession;
    template <typename D> using consume = Windows::Media::Protection::impl_IHdcpSession<D>;
};

template <> struct traits<Windows::Media::Protection::IMediaProtectionManager>
{
    using abi = ABI::Windows::Media::Protection::IMediaProtectionManager;
    template <typename D> using consume = Windows::Media::Protection::impl_IMediaProtectionManager<D>;
};

template <> struct traits<Windows::Media::Protection::IMediaProtectionPMPServer>
{
    using abi = ABI::Windows::Media::Protection::IMediaProtectionPMPServer;
    template <typename D> using consume = Windows::Media::Protection::impl_IMediaProtectionPMPServer<D>;
};

template <> struct traits<Windows::Media::Protection::IMediaProtectionPMPServerFactory>
{
    using abi = ABI::Windows::Media::Protection::IMediaProtectionPMPServerFactory;
    template <typename D> using consume = Windows::Media::Protection::impl_IMediaProtectionPMPServerFactory<D>;
};

template <> struct traits<Windows::Media::Protection::IMediaProtectionServiceCompletion>
{
    using abi = ABI::Windows::Media::Protection::IMediaProtectionServiceCompletion;
    template <typename D> using consume = Windows::Media::Protection::impl_IMediaProtectionServiceCompletion<D>;
};

template <> struct traits<Windows::Media::Protection::IMediaProtectionServiceRequest>
{
    using abi = ABI::Windows::Media::Protection::IMediaProtectionServiceRequest;
    template <typename D> using consume = Windows::Media::Protection::impl_IMediaProtectionServiceRequest<D>;
};

template <> struct traits<Windows::Media::Protection::IProtectionCapabilities>
{
    using abi = ABI::Windows::Media::Protection::IProtectionCapabilities;
    template <typename D> using consume = Windows::Media::Protection::impl_IProtectionCapabilities<D>;
};

template <> struct traits<Windows::Media::Protection::IRevocationAndRenewalInformation>
{
    using abi = ABI::Windows::Media::Protection::IRevocationAndRenewalInformation;
    template <typename D> using consume = Windows::Media::Protection::impl_IRevocationAndRenewalInformation<D>;
};

template <> struct traits<Windows::Media::Protection::IRevocationAndRenewalItem>
{
    using abi = ABI::Windows::Media::Protection::IRevocationAndRenewalItem;
    template <typename D> using consume = Windows::Media::Protection::impl_IRevocationAndRenewalItem<D>;
};

template <> struct traits<Windows::Media::Protection::IServiceRequestedEventArgs>
{
    using abi = ABI::Windows::Media::Protection::IServiceRequestedEventArgs;
    template <typename D> using consume = Windows::Media::Protection::impl_IServiceRequestedEventArgs<D>;
};

template <> struct traits<Windows::Media::Protection::IServiceRequestedEventArgs2>
{
    using abi = ABI::Windows::Media::Protection::IServiceRequestedEventArgs2;
    template <typename D> using consume = Windows::Media::Protection::impl_IServiceRequestedEventArgs2<D>;
};

template <> struct traits<Windows::Media::Protection::RebootNeededEventHandler>
{
    using abi = ABI::Windows::Media::Protection::RebootNeededEventHandler;
};

template <> struct traits<Windows::Media::Protection::ServiceRequestedEventHandler>
{
    using abi = ABI::Windows::Media::Protection::ServiceRequestedEventHandler;
};

template <> struct traits<Windows::Media::Protection::ComponentLoadFailedEventArgs>
{
    using abi = ABI::Windows::Media::Protection::ComponentLoadFailedEventArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Media.Protection.ComponentLoadFailedEventArgs"; }
};

template <> struct traits<Windows::Media::Protection::HdcpSession>
{
    using abi = ABI::Windows::Media::Protection::HdcpSession;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Media.Protection.HdcpSession"; }
};

template <> struct traits<Windows::Media::Protection::MediaProtectionManager>
{
    using abi = ABI::Windows::Media::Protection::MediaProtectionManager;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Media.Protection.MediaProtectionManager"; }
};

template <> struct traits<Windows::Media::Protection::MediaProtectionPMPServer>
{
    using abi = ABI::Windows::Media::Protection::MediaProtectionPMPServer;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Media.Protection.MediaProtectionPMPServer"; }
};

template <> struct traits<Windows::Media::Protection::MediaProtectionServiceCompletion>
{
    using abi = ABI::Windows::Media::Protection::MediaProtectionServiceCompletion;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Media.Protection.MediaProtectionServiceCompletion"; }
};

template <> struct traits<Windows::Media::Protection::ProtectionCapabilities>
{
    using abi = ABI::Windows::Media::Protection::ProtectionCapabilities;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Media.Protection.ProtectionCapabilities"; }
};

template <> struct traits<Windows::Media::Protection::RevocationAndRenewalInformation>
{
    using abi = ABI::Windows::Media::Protection::RevocationAndRenewalInformation;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Media.Protection.RevocationAndRenewalInformation"; }
};

template <> struct traits<Windows::Media::Protection::RevocationAndRenewalItem>
{
    using abi = ABI::Windows::Media::Protection::RevocationAndRenewalItem;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Media.Protection.RevocationAndRenewalItem"; }
};

template <> struct traits<Windows::Media::Protection::ServiceRequestedEventArgs>
{
    using abi = ABI::Windows::Media::Protection::ServiceRequestedEventArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Media.Protection.ServiceRequestedEventArgs"; }
};

}

}
