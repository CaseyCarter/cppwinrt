// C++ for the Windows Runtime v1.29
// Copyright (c) 2016 Microsoft Corporation

#pragma once

#include "../base.h"
#include "Windows.Networking.Vpn.0.h"
#include "Windows.Foundation.0.h"
#include "Windows.Networking.0.h"
#include "Windows.Security.Credentials.0.h"
#include "Windows.Security.Cryptography.Certificates.0.h"
#include "Windows.Storage.Streams.0.h"
#include "Windows.Foundation.Collections.1.h"
#include "Windows.Networking.1.h"
#include "Windows.Foundation.1.h"

WINRT_EXPORT namespace winrt {

namespace ABI::Windows::Networking::Vpn {

struct __declspec(uuid("7b06a635-5c58-41d9-94a7-bfbcf1d8ca54")) __declspec(novtable) IVpnAppId : Windows::IInspectable
{
    virtual HRESULT __stdcall get_Type(winrt::Windows::Networking::Vpn::VpnAppIdType * value) = 0;
    virtual HRESULT __stdcall put_Type(winrt::Windows::Networking::Vpn::VpnAppIdType value) = 0;
    virtual HRESULT __stdcall get_Value(hstring * value) = 0;
    virtual HRESULT __stdcall put_Value(hstring value) = 0;
};

struct __declspec(uuid("46adfd2a-0aab-4fdb-821d-d3ddc919788b")) __declspec(novtable) IVpnAppIdFactory : Windows::IInspectable
{
    virtual HRESULT __stdcall abi_Create(winrt::Windows::Networking::Vpn::VpnAppIdType type, hstring value, Windows::Networking::Vpn::IVpnAppId ** result) = 0;
};

struct __declspec(uuid("4ac78d07-d1a8-4303-a091-c8d2e0915bc3")) __declspec(novtable) IVpnChannel : Windows::IInspectable
{
    virtual HRESULT __stdcall abi_AssociateTransport(Windows::IInspectable * mainOuterTunnelTransport, Windows::IInspectable * optionalOuterTunnelTransport) = 0;
    virtual HRESULT __stdcall abi_Start(Windows::Foundation::Collections::IVectorView<Windows::Networking::HostName> * assignedClientIPv4list, Windows::Foundation::Collections::IVectorView<Windows::Networking::HostName> * assignedClientIPv6list, Windows::Networking::Vpn::IVpnInterfaceId * vpnInterfaceId, Windows::Networking::Vpn::IVpnRouteAssignment * routeScope, Windows::Networking::Vpn::IVpnNamespaceAssignment * namespaceScope, uint32_t mtuSize, uint32_t maxFrameSize, bool optimizeForLowCostNetwork, Windows::IInspectable * mainOuterTunnelTransport, Windows::IInspectable * optionalOuterTunnelTransport) = 0;
    virtual HRESULT __stdcall abi_Stop() = 0;
    virtual HRESULT __stdcall abi_RequestCredentials(winrt::Windows::Networking::Vpn::VpnCredentialType credType, bool isRetry, bool isSingleSignOnCredential, Windows::Security::Cryptography::Certificates::ICertificate * certificate, Windows::Networking::Vpn::IVpnPickedCredential ** credential) = 0;
    virtual HRESULT __stdcall abi_RequestVpnPacketBuffer(winrt::Windows::Networking::Vpn::VpnDataPathType type, Windows::Networking::Vpn::IVpnPacketBuffer ** vpnPacketBuffer) = 0;
    virtual HRESULT __stdcall abi_LogDiagnosticMessage(hstring message) = 0;
    virtual HRESULT __stdcall get_Id(uint32_t * value) = 0;
    virtual HRESULT __stdcall get_Configuration(Windows::Networking::Vpn::IVpnChannelConfiguration ** value) = 0;
    virtual HRESULT __stdcall add_ActivityChange(Windows::Foundation::TypedEventHandler<Windows::Networking::Vpn::VpnChannel, Windows::Networking::Vpn::VpnChannelActivityEventArgs> * handler, event_token * token) = 0;
    virtual HRESULT __stdcall remove_ActivityChange(event_token token) = 0;
    virtual HRESULT __stdcall put_PlugInContext(Windows::IInspectable * value) = 0;
    virtual HRESULT __stdcall get_PlugInContext(Windows::IInspectable ** value) = 0;
    virtual HRESULT __stdcall get_SystemHealth(Windows::Networking::Vpn::IVpnSystemHealth ** value) = 0;
    virtual HRESULT __stdcall abi_RequestCustomPrompt(Windows::Foundation::Collections::IVectorView<Windows::Networking::Vpn::IVpnCustomPrompt> * customPrompt) = 0;
    virtual HRESULT __stdcall abi_SetErrorMessage(hstring message) = 0;
    virtual HRESULT __stdcall abi_SetAllowedSslTlsVersions(Windows::IInspectable * tunnelTransport, bool useTls12) = 0;
};

struct __declspec(uuid("2255d165-993b-4629-ad60-f1c3f3537f50")) __declspec(novtable) IVpnChannel2 : Windows::IInspectable
{
    virtual HRESULT __stdcall abi_StartWithMainTransport(Windows::Foundation::Collections::IVectorView<Windows::Networking::HostName> * assignedClientIPv4list, Windows::Foundation::Collections::IVectorView<Windows::Networking::HostName> * assignedClientIPv6list, Windows::Networking::Vpn::IVpnInterfaceId * vpnInterfaceId, Windows::Networking::Vpn::IVpnRouteAssignment * assignedRoutes, Windows::Networking::Vpn::IVpnDomainNameAssignment * assignedDomainName, uint32_t mtuSize, uint32_t maxFrameSize, bool Reserved, Windows::IInspectable * mainOuterTunnelTransport) = 0;
    virtual HRESULT __stdcall abi_StartExistingTransports(Windows::Foundation::Collections::IVectorView<Windows::Networking::HostName> * assignedClientIPv4list, Windows::Foundation::Collections::IVectorView<Windows::Networking::HostName> * assignedClientIPv6list, Windows::Networking::Vpn::IVpnInterfaceId * vpnInterfaceId, Windows::Networking::Vpn::IVpnRouteAssignment * assignedRoutes, Windows::Networking::Vpn::IVpnDomainNameAssignment * assignedDomainName, uint32_t mtuSize, uint32_t maxFrameSize, bool Reserved) = 0;
    virtual HRESULT __stdcall add_ActivityStateChange(Windows::Foundation::TypedEventHandler<Windows::Networking::Vpn::VpnChannel, Windows::Networking::Vpn::VpnChannelActivityStateChangedArgs> * handler, event_token * token) = 0;
    virtual HRESULT __stdcall remove_ActivityStateChange(event_token token) = 0;
    virtual HRESULT __stdcall abi_GetVpnSendPacketBuffer(Windows::Networking::Vpn::IVpnPacketBuffer ** vpnSendPacketBuffer) = 0;
    virtual HRESULT __stdcall abi_GetVpnReceivePacketBuffer(Windows::Networking::Vpn::IVpnPacketBuffer ** vpnReceivePacketBuffer) = 0;
    virtual HRESULT __stdcall abi_RequestCustomPromptAsync(Windows::Foundation::Collections::IVectorView<Windows::Networking::Vpn::IVpnCustomPromptElement> * customPromptElement, Windows::Foundation::IAsyncAction ** action) = 0;
    virtual HRESULT __stdcall abi_RequestCredentialsWithCertificateAsync(winrt::Windows::Networking::Vpn::VpnCredentialType credType, uint32_t credOptions, Windows::Security::Cryptography::Certificates::ICertificate * certificate, Windows::Foundation::IAsyncOperation<Windows::Networking::Vpn::VpnCredential> ** credential) = 0;
    virtual HRESULT __stdcall abi_RequestCredentialsWithOptionsAsync(winrt::Windows::Networking::Vpn::VpnCredentialType credType, uint32_t credOptions, Windows::Foundation::IAsyncOperation<Windows::Networking::Vpn::VpnCredential> ** credential) = 0;
    virtual HRESULT __stdcall abi_RequestCredentialsSimpleAsync(winrt::Windows::Networking::Vpn::VpnCredentialType credType, Windows::Foundation::IAsyncOperation<Windows::Networking::Vpn::VpnCredential> ** credential) = 0;
    virtual HRESULT __stdcall abi_TerminateConnection(hstring message) = 0;
    virtual HRESULT __stdcall abi_StartWithTrafficFilter(Windows::Foundation::Collections::IVectorView<Windows::Networking::HostName> * assignedClientIpv4List, Windows::Foundation::Collections::IVectorView<Windows::Networking::HostName> * assignedClientIpv6List, Windows::Networking::Vpn::IVpnInterfaceId * vpnInterfaceId, Windows::Networking::Vpn::IVpnRouteAssignment * assignedRoutes, Windows::Networking::Vpn::IVpnDomainNameAssignment * assignedNamespace, uint32_t mtuSize, uint32_t maxFrameSize, bool reserved, Windows::IInspectable * mainOuterTunnelTransport, Windows::IInspectable * optionalOuterTunnelTransport, Windows::Networking::Vpn::IVpnTrafficFilterAssignment * assignedTrafficFilters) = 0;
};

struct __declspec(uuid("a36c88f2-afdc-4775-855d-d4ac0a35fc55")) __declspec(novtable) IVpnChannelActivityEventArgs : Windows::IInspectable
{
    virtual HRESULT __stdcall get_Type(winrt::Windows::Networking::Vpn::VpnChannelActivityEventType * value) = 0;
};

struct __declspec(uuid("3d750565-fdc0-4bbe-a23b-45fffc6d97a1")) __declspec(novtable) IVpnChannelActivityStateChangedArgs : Windows::IInspectable
{
    virtual HRESULT __stdcall get_ActivityState(winrt::Windows::Networking::Vpn::VpnChannelActivityEventType * value) = 0;
};

struct __declspec(uuid("0e2ddca2-2012-4fe4-b179-8c652c6d107e")) __declspec(novtable) IVpnChannelConfiguration : Windows::IInspectable
{
    virtual HRESULT __stdcall get_ServerServiceName(hstring * value) = 0;
    virtual HRESULT __stdcall get_ServerHostNameList(Windows::Foundation::Collections::IVectorView<Windows::Networking::HostName> ** value) = 0;
    virtual HRESULT __stdcall get_CustomField(hstring * value) = 0;
};

struct __declspec(uuid("f30b574c-7824-471c-a118-63dbc93ae4c7")) __declspec(novtable) IVpnChannelConfiguration2 : Windows::IInspectable
{
    virtual HRESULT __stdcall get_ServerUris(Windows::Foundation::Collections::IVectorView<Windows::Foundation::Uri> ** value) = 0;
};

struct __declspec(uuid("88eb062d-e818-4ffd-98a6-363e3736c95d")) __declspec(novtable) IVpnChannelStatics : Windows::IInspectable
{
    virtual HRESULT __stdcall abi_ProcessEventAsync(Windows::IInspectable * thirdPartyPlugIn, Windows::IInspectable * event) = 0;
};

struct __declspec(uuid("b7e78af3-a46d-404b-8729-1832522853ac")) __declspec(novtable) IVpnCredential : Windows::IInspectable
{
    virtual HRESULT __stdcall get_PasskeyCredential(Windows::Security::Credentials::IPasswordCredential ** value) = 0;
    virtual HRESULT __stdcall get_CertificateCredential(Windows::Security::Cryptography::Certificates::ICertificate ** value) = 0;
    virtual HRESULT __stdcall get_AdditionalPin(hstring * value) = 0;
    virtual HRESULT __stdcall get_OldPasswordCredential(Windows::Security::Credentials::IPasswordCredential ** value) = 0;
};

struct __declspec(uuid("43878753-03c5-4e61-93d7-a957714c4282")) __declspec(novtable) IVpnCustomCheckBox : Windows::IInspectable
{
    virtual HRESULT __stdcall put_InitialCheckState(bool value) = 0;
    virtual HRESULT __stdcall get_InitialCheckState(bool * value) = 0;
    virtual HRESULT __stdcall get_Checked(bool * value) = 0;
};

struct __declspec(uuid("9a24158e-dba1-4c6f-8270-dcf3c9761c4c")) __declspec(novtable) IVpnCustomComboBox : Windows::IInspectable
{
    virtual HRESULT __stdcall put_OptionsText(Windows::Foundation::Collections::IVectorView<hstring> * value) = 0;
    virtual HRESULT __stdcall get_OptionsText(Windows::Foundation::Collections::IVectorView<hstring> ** value) = 0;
    virtual HRESULT __stdcall get_Selected(uint32_t * value) = 0;
};

struct __declspec(uuid("3002d9a0-cfbf-4c0b-8f3c-66f503c20b39")) __declspec(novtable) IVpnCustomEditBox : Windows::IInspectable
{
    virtual HRESULT __stdcall put_DefaultText(hstring value) = 0;
    virtual HRESULT __stdcall get_DefaultText(hstring * value) = 0;
    virtual HRESULT __stdcall put_NoEcho(bool value) = 0;
    virtual HRESULT __stdcall get_NoEcho(bool * value) = 0;
    virtual HRESULT __stdcall get_Text(hstring * value) = 0;
};

struct __declspec(uuid("9ec4efb2-c942-42af-b223-588b48328721")) __declspec(novtable) IVpnCustomErrorBox : Windows::IInspectable
{
};

struct __declspec(uuid("9b2ebe7b-87d5-433c-b4f6-eee6aa68a244")) __declspec(novtable) IVpnCustomPrompt : Windows::IInspectable
{
    virtual HRESULT __stdcall put_Label(hstring value) = 0;
    virtual HRESULT __stdcall get_Label(hstring * value) = 0;
    virtual HRESULT __stdcall put_Compulsory(bool value) = 0;
    virtual HRESULT __stdcall get_Compulsory(bool * value) = 0;
    virtual HRESULT __stdcall put_Bordered(bool value) = 0;
    virtual HRESULT __stdcall get_Bordered(bool * value) = 0;
};

struct __declspec(uuid("c4c9a69e-ff47-4527-9f27-a49292019979")) __declspec(novtable) IVpnCustomPromptBooleanInput : Windows::IInspectable
{
    virtual HRESULT __stdcall put_InitialValue(bool value) = 0;
    virtual HRESULT __stdcall get_InitialValue(bool * value) = 0;
    virtual HRESULT __stdcall get_Value(bool * value) = 0;
};

struct __declspec(uuid("73bd5638-6f04-404d-93dd-50a44924a38b")) __declspec(novtable) IVpnCustomPromptElement : Windows::IInspectable
{
    virtual HRESULT __stdcall put_DisplayName(hstring value) = 0;
    virtual HRESULT __stdcall get_DisplayName(hstring * value) = 0;
    virtual HRESULT __stdcall put_Compulsory(bool value) = 0;
    virtual HRESULT __stdcall get_Compulsory(bool * value) = 0;
    virtual HRESULT __stdcall put_Emphasized(bool value) = 0;
    virtual HRESULT __stdcall get_Emphasized(bool * value) = 0;
};

struct __declspec(uuid("3b8f34d9-8ec1-4e95-9a4e-7ba64d38f330")) __declspec(novtable) IVpnCustomPromptOptionSelector : Windows::IInspectable
{
    virtual HRESULT __stdcall get_Options(Windows::Foundation::Collections::IVector<hstring> ** value) = 0;
    virtual HRESULT __stdcall get_SelectedIndex(uint32_t * value) = 0;
};

struct __declspec(uuid("3bc8bdee-3a42-49a3-abdd-07b2edea752d")) __declspec(novtable) IVpnCustomPromptText : Windows::IInspectable
{
    virtual HRESULT __stdcall put_Text(hstring value) = 0;
    virtual HRESULT __stdcall get_Text(hstring * value) = 0;
};

struct __declspec(uuid("c9da9c75-913c-47d5-88ba-48fc48930235")) __declspec(novtable) IVpnCustomPromptTextInput : Windows::IInspectable
{
    virtual HRESULT __stdcall put_PlaceholderText(hstring value) = 0;
    virtual HRESULT __stdcall get_PlaceholderText(hstring * value) = 0;
    virtual HRESULT __stdcall put_IsTextHidden(bool value) = 0;
    virtual HRESULT __stdcall get_IsTextHidden(bool * value) = 0;
    virtual HRESULT __stdcall get_Text(hstring * value) = 0;
};

struct __declspec(uuid("daa4c3ca-8f23-4d36-91f1-76d937827942")) __declspec(novtable) IVpnCustomTextBox : Windows::IInspectable
{
    virtual HRESULT __stdcall put_DisplayText(hstring value) = 0;
    virtual HRESULT __stdcall get_DisplayText(hstring * value) = 0;
};

struct __declspec(uuid("4135b141-ccdb-49b5-9401-039a8ae767e9")) __declspec(novtable) IVpnDomainNameAssignment : Windows::IInspectable
{
    virtual HRESULT __stdcall get_DomainNameList(Windows::Foundation::Collections::IVector<Windows::Networking::Vpn::VpnDomainNameInfo> ** value) = 0;
    virtual HRESULT __stdcall put_ProxyAutoConfigurationUri(Windows::Foundation::IUriRuntimeClass * value) = 0;
    virtual HRESULT __stdcall get_ProxyAutoConfigurationUri(Windows::Foundation::IUriRuntimeClass ** value) = 0;
};

struct __declspec(uuid("ad2eb82f-ea8e-4f7a-843e-1a87e32e1b9a")) __declspec(novtable) IVpnDomainNameInfo : Windows::IInspectable
{
    virtual HRESULT __stdcall put_DomainName(Windows::Networking::IHostName * value) = 0;
    virtual HRESULT __stdcall get_DomainName(Windows::Networking::IHostName ** value) = 0;
    virtual HRESULT __stdcall put_DomainNameType(winrt::Windows::Networking::Vpn::VpnDomainNameType value) = 0;
    virtual HRESULT __stdcall get_DomainNameType(winrt::Windows::Networking::Vpn::VpnDomainNameType * value) = 0;
    virtual HRESULT __stdcall get_DnsServers(Windows::Foundation::Collections::IVector<Windows::Networking::HostName> ** value) = 0;
    virtual HRESULT __stdcall get_WebProxyServers(Windows::Foundation::Collections::IVector<Windows::Networking::HostName> ** value) = 0;
};

struct __declspec(uuid("ab871151-6c53-4828-9883-d886de104407")) __declspec(novtable) IVpnDomainNameInfo2 : Windows::IInspectable
{
    virtual HRESULT __stdcall get_WebProxyUris(Windows::Foundation::Collections::IVector<Windows::Foundation::Uri> ** value) = 0;
};

struct __declspec(uuid("2507bb75-028f-4688-8d3a-c4531df37da8")) __declspec(novtable) IVpnDomainNameInfoFactory : Windows::IInspectable
{
    virtual HRESULT __stdcall abi_CreateVpnDomainNameInfo(hstring name, winrt::Windows::Networking::Vpn::VpnDomainNameType nameType, Windows::Foundation::Collections::IIterable<Windows::Networking::HostName> * dnsServerList, Windows::Foundation::Collections::IIterable<Windows::Networking::HostName> * proxyServerList, Windows::Networking::Vpn::IVpnDomainNameInfo ** domainNameInfo) = 0;
};

struct __declspec(uuid("9e2ddca2-1712-4ce4-b179-8c652c6d1011")) __declspec(novtable) IVpnInterfaceId : Windows::IInspectable
{
    virtual HRESULT __stdcall abi_GetAddressInfo(uint32_t * __idSize, uint8_t ** id) = 0;
};

struct __declspec(uuid("9e2ddca2-1712-4ce4-b179-8c652c6d1000")) __declspec(novtable) IVpnInterfaceIdFactory : Windows::IInspectable
{
    virtual HRESULT __stdcall abi_CreateVpnInterfaceId(uint32_t __addressSize, uint8_t * address, Windows::Networking::Vpn::IVpnInterfaceId ** vpnInterfaceId) = 0;
};

struct __declspec(uuid("193696cd-a5c4-4abe-852b-785be4cb3e34")) __declspec(novtable) IVpnManagementAgent : Windows::IInspectable
{
    virtual HRESULT __stdcall abi_AddProfileFromXmlAsync(hstring xml, Windows::Foundation::IAsyncOperation<winrt::Windows::Networking::Vpn::VpnManagementErrorStatus> ** operation) = 0;
    virtual HRESULT __stdcall abi_AddProfileFromObjectAsync(Windows::Networking::Vpn::IVpnProfile * profile, Windows::Foundation::IAsyncOperation<winrt::Windows::Networking::Vpn::VpnManagementErrorStatus> ** operation) = 0;
    virtual HRESULT __stdcall abi_UpdateProfileFromXmlAsync(hstring xml, Windows::Foundation::IAsyncOperation<winrt::Windows::Networking::Vpn::VpnManagementErrorStatus> ** operation) = 0;
    virtual HRESULT __stdcall abi_UpdateProfileFromObjectAsync(Windows::Networking::Vpn::IVpnProfile * profile, Windows::Foundation::IAsyncOperation<winrt::Windows::Networking::Vpn::VpnManagementErrorStatus> ** operation) = 0;
    virtual HRESULT __stdcall abi_GetProfilesAsync(Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::Networking::Vpn::IVpnProfile>> ** operation) = 0;
    virtual HRESULT __stdcall abi_DeleteProfileAsync(Windows::Networking::Vpn::IVpnProfile * profile, Windows::Foundation::IAsyncOperation<winrt::Windows::Networking::Vpn::VpnManagementErrorStatus> ** operation) = 0;
    virtual HRESULT __stdcall abi_ConnectProfileAsync(Windows::Networking::Vpn::IVpnProfile * profile, Windows::Foundation::IAsyncOperation<winrt::Windows::Networking::Vpn::VpnManagementErrorStatus> ** operation) = 0;
    virtual HRESULT __stdcall abi_ConnectProfileWithPasswordCredentialAsync(Windows::Networking::Vpn::IVpnProfile * profile, Windows::Security::Credentials::IPasswordCredential * passwordCredential, Windows::Foundation::IAsyncOperation<winrt::Windows::Networking::Vpn::VpnManagementErrorStatus> ** operation) = 0;
    virtual HRESULT __stdcall abi_DisconnectProfileAsync(Windows::Networking::Vpn::IVpnProfile * profile, Windows::Foundation::IAsyncOperation<winrt::Windows::Networking::Vpn::VpnManagementErrorStatus> ** operation) = 0;
};

struct __declspec(uuid("d7f7db18-307d-4c0e-bd62-8fa270bbadd6")) __declspec(novtable) IVpnNamespaceAssignment : Windows::IInspectable
{
    virtual HRESULT __stdcall put_NamespaceList(Windows::Foundation::Collections::IVector<Windows::Networking::Vpn::VpnNamespaceInfo> * value) = 0;
    virtual HRESULT __stdcall get_NamespaceList(Windows::Foundation::Collections::IVector<Windows::Networking::Vpn::VpnNamespaceInfo> ** value) = 0;
    virtual HRESULT __stdcall put_ProxyAutoConfigUri(Windows::Foundation::IUriRuntimeClass * value) = 0;
    virtual HRESULT __stdcall get_ProxyAutoConfigUri(Windows::Foundation::IUriRuntimeClass ** value) = 0;
};

struct __declspec(uuid("30edfb43-444f-44c5-8167-a35a91f1af94")) __declspec(novtable) IVpnNamespaceInfo : Windows::IInspectable
{
    virtual HRESULT __stdcall put_Namespace(hstring value) = 0;
    virtual HRESULT __stdcall get_Namespace(hstring * value) = 0;
    virtual HRESULT __stdcall put_DnsServers(Windows::Foundation::Collections::IVector<Windows::Networking::HostName> * value) = 0;
    virtual HRESULT __stdcall get_DnsServers(Windows::Foundation::Collections::IVector<Windows::Networking::HostName> ** value) = 0;
    virtual HRESULT __stdcall put_WebProxyServers(Windows::Foundation::Collections::IVector<Windows::Networking::HostName> * value) = 0;
    virtual HRESULT __stdcall get_WebProxyServers(Windows::Foundation::Collections::IVector<Windows::Networking::HostName> ** value) = 0;
};

struct __declspec(uuid("cb3e951a-b0ce-442b-acbb-5f99b202c31c")) __declspec(novtable) IVpnNamespaceInfoFactory : Windows::IInspectable
{
    virtual HRESULT __stdcall abi_CreateVpnNamespaceInfo(hstring name, Windows::Foundation::Collections::IVector<Windows::Networking::HostName> * dnsServerList, Windows::Foundation::Collections::IVector<Windows::Networking::HostName> * proxyServerList, Windows::Networking::Vpn::IVpnNamespaceInfo ** namespaceInfo) = 0;
};

struct __declspec(uuid("a4aee29e-6417-4333-9842-f0a66db69802")) __declspec(novtable) IVpnNativeProfile : Windows::IInspectable
{
    virtual HRESULT __stdcall get_Servers(Windows::Foundation::Collections::IVector<hstring> ** value) = 0;
    virtual HRESULT __stdcall get_RoutingPolicyType(winrt::Windows::Networking::Vpn::VpnRoutingPolicyType * value) = 0;
    virtual HRESULT __stdcall put_RoutingPolicyType(winrt::Windows::Networking::Vpn::VpnRoutingPolicyType value) = 0;
    virtual HRESULT __stdcall get_NativeProtocolType(winrt::Windows::Networking::Vpn::VpnNativeProtocolType * value) = 0;
    virtual HRESULT __stdcall put_NativeProtocolType(winrt::Windows::Networking::Vpn::VpnNativeProtocolType value) = 0;
    virtual HRESULT __stdcall get_UserAuthenticationMethod(winrt::Windows::Networking::Vpn::VpnAuthenticationMethod * value) = 0;
    virtual HRESULT __stdcall put_UserAuthenticationMethod(winrt::Windows::Networking::Vpn::VpnAuthenticationMethod value) = 0;
    virtual HRESULT __stdcall get_TunnelAuthenticationMethod(winrt::Windows::Networking::Vpn::VpnAuthenticationMethod * value) = 0;
    virtual HRESULT __stdcall put_TunnelAuthenticationMethod(winrt::Windows::Networking::Vpn::VpnAuthenticationMethod value) = 0;
    virtual HRESULT __stdcall get_EapConfiguration(hstring * Value) = 0;
    virtual HRESULT __stdcall put_EapConfiguration(hstring value) = 0;
};

struct __declspec(uuid("0fec2467-cdb5-4ac7-b5a3-0afb5ec47682")) __declspec(novtable) IVpnNativeProfile2 : Windows::IInspectable
{
    virtual HRESULT __stdcall get_RequireVpnClientAppUI(bool * value) = 0;
    virtual HRESULT __stdcall put_RequireVpnClientAppUI(bool value) = 0;
    virtual HRESULT __stdcall get_ConnectionStatus(winrt::Windows::Networking::Vpn::VpnManagementConnectionStatus * value) = 0;
};

struct __declspec(uuid("c2f891fc-4d5c-4a63-b70d-4e307eacce55")) __declspec(novtable) IVpnPacketBuffer : Windows::IInspectable
{
    virtual HRESULT __stdcall get_Buffer(Windows::Storage::Streams::IBuffer ** value) = 0;
    virtual HRESULT __stdcall put_Status(winrt::Windows::Networking::Vpn::VpnPacketBufferStatus value) = 0;
    virtual HRESULT __stdcall get_Status(winrt::Windows::Networking::Vpn::VpnPacketBufferStatus * value) = 0;
    virtual HRESULT __stdcall put_TransportAffinity(uint32_t value) = 0;
    virtual HRESULT __stdcall get_TransportAffinity(uint32_t * value) = 0;
};

struct __declspec(uuid("665e91f0-8805-4bf5-a619-2e84882e6b4f")) __declspec(novtable) IVpnPacketBuffer2 : Windows::IInspectable
{
    virtual HRESULT __stdcall get_AppId(Windows::Networking::Vpn::IVpnAppId ** value) = 0;
};

struct __declspec(uuid("9e2ddca2-1712-4ce4-b179-8c652c6d9999")) __declspec(novtable) IVpnPacketBufferFactory : Windows::IInspectable
{
    virtual HRESULT __stdcall abi_CreateVpnPacketBuffer(Windows::Networking::Vpn::IVpnPacketBuffer * parentBuffer, uint32_t offset, uint32_t length, Windows::Networking::Vpn::IVpnPacketBuffer ** vpnPacketBuffer) = 0;
};

struct __declspec(uuid("c2f891fc-4d5c-4a63-b70d-4e307eacce77")) __declspec(novtable) IVpnPacketBufferList : Windows::IInspectable
{
    virtual HRESULT __stdcall abi_Append(Windows::Networking::Vpn::IVpnPacketBuffer * nextVpnPacketBuffer) = 0;
    virtual HRESULT __stdcall abi_AddAtBegin(Windows::Networking::Vpn::IVpnPacketBuffer * nextVpnPacketBuffer) = 0;
    virtual HRESULT __stdcall abi_RemoveAtEnd(Windows::Networking::Vpn::IVpnPacketBuffer ** nextVpnPacketBuffer) = 0;
    virtual HRESULT __stdcall abi_RemoveAtBegin(Windows::Networking::Vpn::IVpnPacketBuffer ** nextVpnPacketBuffer) = 0;
    virtual HRESULT __stdcall abi_Clear() = 0;
    virtual HRESULT __stdcall put_Status(winrt::Windows::Networking::Vpn::VpnPacketBufferStatus value) = 0;
    virtual HRESULT __stdcall get_Status(winrt::Windows::Networking::Vpn::VpnPacketBufferStatus * value) = 0;
    virtual HRESULT __stdcall get_Size(uint32_t * value) = 0;
};

struct __declspec(uuid("3e7acfe5-ea1e-482a-8d98-c065f57d89ea")) __declspec(novtable) IVpnPacketBufferList2 : Windows::IInspectable
{
    virtual HRESULT __stdcall abi_AddLeadingPacket(Windows::Networking::Vpn::IVpnPacketBuffer * nextVpnPacketBuffer) = 0;
    virtual HRESULT __stdcall abi_RemoveLeadingPacket(Windows::Networking::Vpn::IVpnPacketBuffer ** nextVpnPacketBuffer) = 0;
    virtual HRESULT __stdcall abi_AddTrailingPacket(Windows::Networking::Vpn::IVpnPacketBuffer * nextVpnPacketBuffer) = 0;
    virtual HRESULT __stdcall abi_RemoveTrailingPacket(Windows::Networking::Vpn::IVpnPacketBuffer ** nextVpnPacketBuffer) = 0;
};

struct __declspec(uuid("9a793ac7-8854-4e52-ad97-24dd9a842bce")) __declspec(novtable) IVpnPickedCredential : Windows::IInspectable
{
    virtual HRESULT __stdcall get_PasskeyCredential(Windows::Security::Credentials::IPasswordCredential ** value) = 0;
    virtual HRESULT __stdcall get_AdditionalPin(hstring * value) = 0;
    virtual HRESULT __stdcall get_OldPasswordCredential(Windows::Security::Credentials::IPasswordCredential ** value) = 0;
};

struct __declspec(uuid("ceb78d07-d0a8-4703-a091-c8c2c0915bc4")) __declspec(novtable) IVpnPlugIn : Windows::IInspectable
{
    virtual HRESULT __stdcall abi_Connect(Windows::Networking::Vpn::IVpnChannel * channel) = 0;
    virtual HRESULT __stdcall abi_Disconnect(Windows::Networking::Vpn::IVpnChannel * channel) = 0;
    virtual HRESULT __stdcall abi_GetKeepAlivePayload(Windows::Networking::Vpn::IVpnChannel * channel, Windows::Networking::Vpn::IVpnPacketBuffer ** keepAlivePacket) = 0;
    virtual HRESULT __stdcall abi_Encapsulate(Windows::Networking::Vpn::IVpnChannel * channel, Windows::Networking::Vpn::IVpnPacketBufferList * packets, Windows::Networking::Vpn::IVpnPacketBufferList * encapulatedPackets) = 0;
    virtual HRESULT __stdcall abi_Decapsulate(Windows::Networking::Vpn::IVpnChannel * channel, Windows::Networking::Vpn::IVpnPacketBuffer * encapBuffer, Windows::Networking::Vpn::IVpnPacketBufferList * decapsulatedPackets, Windows::Networking::Vpn::IVpnPacketBufferList * controlPacketsToSend) = 0;
};

struct __declspec(uuid("0edf0da4-4f00-4589-8d7b-4bf988f6542c")) __declspec(novtable) IVpnPlugInProfile : Windows::IInspectable
{
    virtual HRESULT __stdcall get_ServerUris(Windows::Foundation::Collections::IVector<Windows::Foundation::Uri> ** value) = 0;
    virtual HRESULT __stdcall get_CustomConfiguration(hstring * value) = 0;
    virtual HRESULT __stdcall put_CustomConfiguration(hstring value) = 0;
    virtual HRESULT __stdcall get_VpnPluginPackageFamilyName(hstring * value) = 0;
    virtual HRESULT __stdcall put_VpnPluginPackageFamilyName(hstring value) = 0;
};

struct __declspec(uuid("611c4892-cf94-4ad6-ba99-00f4ff34565e")) __declspec(novtable) IVpnPlugInProfile2 : Windows::IInspectable
{
    virtual HRESULT __stdcall get_RequireVpnClientAppUI(bool * value) = 0;
    virtual HRESULT __stdcall put_RequireVpnClientAppUI(bool value) = 0;
    virtual HRESULT __stdcall get_ConnectionStatus(winrt::Windows::Networking::Vpn::VpnManagementConnectionStatus * value) = 0;
};

struct __declspec(uuid("7875b751-b0d7-43db-8a93-d3fe2479e56a")) __declspec(novtable) IVpnProfile : Windows::IInspectable
{
    virtual HRESULT __stdcall get_ProfileName(hstring * value) = 0;
    virtual HRESULT __stdcall put_ProfileName(hstring value) = 0;
    virtual HRESULT __stdcall get_AppTriggers(Windows::Foundation::Collections::IVector<Windows::Networking::Vpn::VpnAppId> ** value) = 0;
    virtual HRESULT __stdcall get_Routes(Windows::Foundation::Collections::IVector<Windows::Networking::Vpn::VpnRoute> ** value) = 0;
    virtual HRESULT __stdcall get_DomainNameInfoList(Windows::Foundation::Collections::IVector<Windows::Networking::Vpn::VpnDomainNameInfo> ** value) = 0;
    virtual HRESULT __stdcall get_TrafficFilters(Windows::Foundation::Collections::IVector<Windows::Networking::Vpn::VpnTrafficFilter> ** value) = 0;
    virtual HRESULT __stdcall get_RememberCredentials(bool * value) = 0;
    virtual HRESULT __stdcall put_RememberCredentials(bool value) = 0;
    virtual HRESULT __stdcall get_AlwaysOn(bool * value) = 0;
    virtual HRESULT __stdcall put_AlwaysOn(bool value) = 0;
};

struct __declspec(uuid("b5731b83-0969-4699-938e-7776db29cfb3")) __declspec(novtable) IVpnRoute : Windows::IInspectable
{
    virtual HRESULT __stdcall put_Address(Windows::Networking::IHostName * value) = 0;
    virtual HRESULT __stdcall get_Address(Windows::Networking::IHostName ** value) = 0;
    virtual HRESULT __stdcall put_PrefixSize(uint8_t value) = 0;
    virtual HRESULT __stdcall get_PrefixSize(uint8_t * value) = 0;
};

struct __declspec(uuid("db64de22-ce39-4a76-9550-f61039f80e48")) __declspec(novtable) IVpnRouteAssignment : Windows::IInspectable
{
    virtual HRESULT __stdcall put_Ipv4InclusionRoutes(Windows::Foundation::Collections::IVector<Windows::Networking::Vpn::VpnRoute> * value) = 0;
    virtual HRESULT __stdcall put_Ipv6InclusionRoutes(Windows::Foundation::Collections::IVector<Windows::Networking::Vpn::VpnRoute> * value) = 0;
    virtual HRESULT __stdcall get_Ipv4InclusionRoutes(Windows::Foundation::Collections::IVector<Windows::Networking::Vpn::VpnRoute> ** value) = 0;
    virtual HRESULT __stdcall get_Ipv6InclusionRoutes(Windows::Foundation::Collections::IVector<Windows::Networking::Vpn::VpnRoute> ** value) = 0;
    virtual HRESULT __stdcall put_Ipv4ExclusionRoutes(Windows::Foundation::Collections::IVector<Windows::Networking::Vpn::VpnRoute> * value) = 0;
    virtual HRESULT __stdcall put_Ipv6ExclusionRoutes(Windows::Foundation::Collections::IVector<Windows::Networking::Vpn::VpnRoute> * value) = 0;
    virtual HRESULT __stdcall get_Ipv4ExclusionRoutes(Windows::Foundation::Collections::IVector<Windows::Networking::Vpn::VpnRoute> ** value) = 0;
    virtual HRESULT __stdcall get_Ipv6ExclusionRoutes(Windows::Foundation::Collections::IVector<Windows::Networking::Vpn::VpnRoute> ** value) = 0;
    virtual HRESULT __stdcall put_ExcludeLocalSubnets(bool value) = 0;
    virtual HRESULT __stdcall get_ExcludeLocalSubnets(bool * value) = 0;
};

struct __declspec(uuid("bdeab5ff-45cf-4b99-83fb-db3bc2672b02")) __declspec(novtable) IVpnRouteFactory : Windows::IInspectable
{
    virtual HRESULT __stdcall abi_CreateVpnRoute(Windows::Networking::IHostName * address, uint8_t prefixSize, Windows::Networking::Vpn::IVpnRoute ** route) = 0;
};

struct __declspec(uuid("99a8f8af-c0ee-4e75-817a-f231aee5123d")) __declspec(novtable) IVpnSystemHealth : Windows::IInspectable
{
    virtual HRESULT __stdcall get_StatementOfHealth(Windows::Storage::Streams::IBuffer ** value) = 0;
};

struct __declspec(uuid("2f691b60-6c9f-47f5-ac36-bb1b042e2c50")) __declspec(novtable) IVpnTrafficFilter : Windows::IInspectable
{
    virtual HRESULT __stdcall get_AppId(Windows::Networking::Vpn::IVpnAppId ** value) = 0;
    virtual HRESULT __stdcall put_AppId(Windows::Networking::Vpn::IVpnAppId * value) = 0;
    virtual HRESULT __stdcall get_AppClaims(Windows::Foundation::Collections::IVector<hstring> ** value) = 0;
    virtual HRESULT __stdcall get_Protocol(winrt::Windows::Networking::Vpn::VpnIPProtocol * value) = 0;
    virtual HRESULT __stdcall put_Protocol(winrt::Windows::Networking::Vpn::VpnIPProtocol value) = 0;
    virtual HRESULT __stdcall get_LocalPortRanges(Windows::Foundation::Collections::IVector<hstring> ** value) = 0;
    virtual HRESULT __stdcall get_RemotePortRanges(Windows::Foundation::Collections::IVector<hstring> ** value) = 0;
    virtual HRESULT __stdcall get_LocalAddressRanges(Windows::Foundation::Collections::IVector<hstring> ** value) = 0;
    virtual HRESULT __stdcall get_RemoteAddressRanges(Windows::Foundation::Collections::IVector<hstring> ** value) = 0;
    virtual HRESULT __stdcall get_RoutingPolicyType(winrt::Windows::Networking::Vpn::VpnRoutingPolicyType * value) = 0;
    virtual HRESULT __stdcall put_RoutingPolicyType(winrt::Windows::Networking::Vpn::VpnRoutingPolicyType value) = 0;
};

struct __declspec(uuid("56ccd45c-e664-471e-89cd-601603b9e0f3")) __declspec(novtable) IVpnTrafficFilterAssignment : Windows::IInspectable
{
    virtual HRESULT __stdcall get_TrafficFilterList(Windows::Foundation::Collections::IVector<Windows::Networking::Vpn::VpnTrafficFilter> ** value) = 0;
    virtual HRESULT __stdcall get_AllowOutbound(bool * value) = 0;
    virtual HRESULT __stdcall put_AllowOutbound(bool value) = 0;
    virtual HRESULT __stdcall get_AllowInbound(bool * value) = 0;
    virtual HRESULT __stdcall put_AllowInbound(bool value) = 0;
};

struct __declspec(uuid("480d41d5-7f99-474c-86ee-96df168318f1")) __declspec(novtable) IVpnTrafficFilterFactory : Windows::IInspectable
{
    virtual HRESULT __stdcall abi_Create(Windows::Networking::Vpn::IVpnAppId * appId, Windows::Networking::Vpn::IVpnTrafficFilter ** result) = 0;
};

}

namespace ABI {

template <> struct traits<Windows::Networking::Vpn::VpnAppId> { using default_interface = Windows::Networking::Vpn::IVpnAppId; };
template <> struct traits<Windows::Networking::Vpn::VpnChannel> { using default_interface = Windows::Networking::Vpn::IVpnChannel; };
template <> struct traits<Windows::Networking::Vpn::VpnChannelActivityEventArgs> { using default_interface = Windows::Networking::Vpn::IVpnChannelActivityEventArgs; };
template <> struct traits<Windows::Networking::Vpn::VpnChannelActivityStateChangedArgs> { using default_interface = Windows::Networking::Vpn::IVpnChannelActivityStateChangedArgs; };
template <> struct traits<Windows::Networking::Vpn::VpnChannelConfiguration> { using default_interface = Windows::Networking::Vpn::IVpnChannelConfiguration; };
template <> struct traits<Windows::Networking::Vpn::VpnCredential> { using default_interface = Windows::Networking::Vpn::IVpnCredential; };
template <> struct traits<Windows::Networking::Vpn::VpnCustomCheckBox> { using default_interface = Windows::Networking::Vpn::IVpnCustomCheckBox; };
template <> struct traits<Windows::Networking::Vpn::VpnCustomComboBox> { using default_interface = Windows::Networking::Vpn::IVpnCustomComboBox; };
template <> struct traits<Windows::Networking::Vpn::VpnCustomEditBox> { using default_interface = Windows::Networking::Vpn::IVpnCustomEditBox; };
template <> struct traits<Windows::Networking::Vpn::VpnCustomErrorBox> { using default_interface = Windows::Networking::Vpn::IVpnCustomErrorBox; };
template <> struct traits<Windows::Networking::Vpn::VpnCustomPromptBooleanInput> { using default_interface = Windows::Networking::Vpn::IVpnCustomPromptBooleanInput; };
template <> struct traits<Windows::Networking::Vpn::VpnCustomPromptOptionSelector> { using default_interface = Windows::Networking::Vpn::IVpnCustomPromptOptionSelector; };
template <> struct traits<Windows::Networking::Vpn::VpnCustomPromptText> { using default_interface = Windows::Networking::Vpn::IVpnCustomPromptText; };
template <> struct traits<Windows::Networking::Vpn::VpnCustomPromptTextInput> { using default_interface = Windows::Networking::Vpn::IVpnCustomPromptTextInput; };
template <> struct traits<Windows::Networking::Vpn::VpnCustomTextBox> { using default_interface = Windows::Networking::Vpn::IVpnCustomTextBox; };
template <> struct traits<Windows::Networking::Vpn::VpnDomainNameAssignment> { using default_interface = Windows::Networking::Vpn::IVpnDomainNameAssignment; };
template <> struct traits<Windows::Networking::Vpn::VpnDomainNameInfo> { using default_interface = Windows::Networking::Vpn::IVpnDomainNameInfo; };
template <> struct traits<Windows::Networking::Vpn::VpnInterfaceId> { using default_interface = Windows::Networking::Vpn::IVpnInterfaceId; };
template <> struct traits<Windows::Networking::Vpn::VpnManagementAgent> { using default_interface = Windows::Networking::Vpn::IVpnManagementAgent; };
template <> struct traits<Windows::Networking::Vpn::VpnNamespaceAssignment> { using default_interface = Windows::Networking::Vpn::IVpnNamespaceAssignment; };
template <> struct traits<Windows::Networking::Vpn::VpnNamespaceInfo> { using default_interface = Windows::Networking::Vpn::IVpnNamespaceInfo; };
template <> struct traits<Windows::Networking::Vpn::VpnNativeProfile> { using default_interface = Windows::Networking::Vpn::IVpnNativeProfile; };
template <> struct traits<Windows::Networking::Vpn::VpnPacketBuffer> { using default_interface = Windows::Networking::Vpn::IVpnPacketBuffer; };
template <> struct traits<Windows::Networking::Vpn::VpnPacketBufferList> { using default_interface = Windows::Networking::Vpn::IVpnPacketBufferList; };
template <> struct traits<Windows::Networking::Vpn::VpnPickedCredential> { using default_interface = Windows::Networking::Vpn::IVpnPickedCredential; };
template <> struct traits<Windows::Networking::Vpn::VpnPlugInProfile> { using default_interface = Windows::Networking::Vpn::IVpnPlugInProfile; };
template <> struct traits<Windows::Networking::Vpn::VpnRoute> { using default_interface = Windows::Networking::Vpn::IVpnRoute; };
template <> struct traits<Windows::Networking::Vpn::VpnRouteAssignment> { using default_interface = Windows::Networking::Vpn::IVpnRouteAssignment; };
template <> struct traits<Windows::Networking::Vpn::VpnSystemHealth> { using default_interface = Windows::Networking::Vpn::IVpnSystemHealth; };
template <> struct traits<Windows::Networking::Vpn::VpnTrafficFilter> { using default_interface = Windows::Networking::Vpn::IVpnTrafficFilter; };
template <> struct traits<Windows::Networking::Vpn::VpnTrafficFilterAssignment> { using default_interface = Windows::Networking::Vpn::IVpnTrafficFilterAssignment; };

}

namespace Windows::Networking::Vpn {

template <typename T> class impl_IVpnAppId;
template <typename T> class impl_IVpnAppIdFactory;
template <typename T> class impl_IVpnChannel;
template <typename T> class impl_IVpnChannel2;
template <typename T> class impl_IVpnChannelActivityEventArgs;
template <typename T> class impl_IVpnChannelActivityStateChangedArgs;
template <typename T> class impl_IVpnChannelConfiguration;
template <typename T> class impl_IVpnChannelConfiguration2;
template <typename T> class impl_IVpnChannelStatics;
template <typename T> class impl_IVpnCredential;
template <typename T> class impl_IVpnCustomCheckBox;
template <typename T> class impl_IVpnCustomComboBox;
template <typename T> class impl_IVpnCustomEditBox;
template <typename T> class impl_IVpnCustomErrorBox;
template <typename T> class impl_IVpnCustomPrompt;
template <typename T> class impl_IVpnCustomPromptBooleanInput;
template <typename T> class impl_IVpnCustomPromptElement;
template <typename T> class impl_IVpnCustomPromptOptionSelector;
template <typename T> class impl_IVpnCustomPromptText;
template <typename T> class impl_IVpnCustomPromptTextInput;
template <typename T> class impl_IVpnCustomTextBox;
template <typename T> class impl_IVpnDomainNameAssignment;
template <typename T> class impl_IVpnDomainNameInfo;
template <typename T> class impl_IVpnDomainNameInfo2;
template <typename T> class impl_IVpnDomainNameInfoFactory;
template <typename T> class impl_IVpnInterfaceId;
template <typename T> class impl_IVpnInterfaceIdFactory;
template <typename T> class impl_IVpnManagementAgent;
template <typename T> class impl_IVpnNamespaceAssignment;
template <typename T> class impl_IVpnNamespaceInfo;
template <typename T> class impl_IVpnNamespaceInfoFactory;
template <typename T> class impl_IVpnNativeProfile;
template <typename T> class impl_IVpnNativeProfile2;
template <typename T> class impl_IVpnPacketBuffer;
template <typename T> class impl_IVpnPacketBuffer2;
template <typename T> class impl_IVpnPacketBufferFactory;
template <typename T> class impl_IVpnPacketBufferList;
template <typename T> class impl_IVpnPacketBufferList2;
template <typename T> class impl_IVpnPickedCredential;
template <typename T> class impl_IVpnPlugIn;
template <typename T> class impl_IVpnPlugInProfile;
template <typename T> class impl_IVpnPlugInProfile2;
template <typename T> class impl_IVpnProfile;
template <typename T> class impl_IVpnRoute;
template <typename T> class impl_IVpnRouteAssignment;
template <typename T> class impl_IVpnRouteFactory;
template <typename T> class impl_IVpnSystemHealth;
template <typename T> class impl_IVpnTrafficFilter;
template <typename T> class impl_IVpnTrafficFilterAssignment;
template <typename T> class impl_IVpnTrafficFilterFactory;

}

namespace impl {

template <> struct traits<Windows::Networking::Vpn::IVpnAppId>
{
    using abi = ABI::Windows::Networking::Vpn::IVpnAppId;
    template <typename D> using consume = Windows::Networking::Vpn::impl_IVpnAppId<D>;
};

template <> struct traits<Windows::Networking::Vpn::IVpnAppIdFactory>
{
    using abi = ABI::Windows::Networking::Vpn::IVpnAppIdFactory;
    template <typename D> using consume = Windows::Networking::Vpn::impl_IVpnAppIdFactory<D>;
};

template <> struct traits<Windows::Networking::Vpn::IVpnChannel>
{
    using abi = ABI::Windows::Networking::Vpn::IVpnChannel;
    template <typename D> using consume = Windows::Networking::Vpn::impl_IVpnChannel<D>;
};

template <> struct traits<Windows::Networking::Vpn::IVpnChannel2>
{
    using abi = ABI::Windows::Networking::Vpn::IVpnChannel2;
    template <typename D> using consume = Windows::Networking::Vpn::impl_IVpnChannel2<D>;
};

template <> struct traits<Windows::Networking::Vpn::IVpnChannelActivityEventArgs>
{
    using abi = ABI::Windows::Networking::Vpn::IVpnChannelActivityEventArgs;
    template <typename D> using consume = Windows::Networking::Vpn::impl_IVpnChannelActivityEventArgs<D>;
};

template <> struct traits<Windows::Networking::Vpn::IVpnChannelActivityStateChangedArgs>
{
    using abi = ABI::Windows::Networking::Vpn::IVpnChannelActivityStateChangedArgs;
    template <typename D> using consume = Windows::Networking::Vpn::impl_IVpnChannelActivityStateChangedArgs<D>;
};

template <> struct traits<Windows::Networking::Vpn::IVpnChannelConfiguration>
{
    using abi = ABI::Windows::Networking::Vpn::IVpnChannelConfiguration;
    template <typename D> using consume = Windows::Networking::Vpn::impl_IVpnChannelConfiguration<D>;
};

template <> struct traits<Windows::Networking::Vpn::IVpnChannelConfiguration2>
{
    using abi = ABI::Windows::Networking::Vpn::IVpnChannelConfiguration2;
    template <typename D> using consume = Windows::Networking::Vpn::impl_IVpnChannelConfiguration2<D>;
};

template <> struct traits<Windows::Networking::Vpn::IVpnChannelStatics>
{
    using abi = ABI::Windows::Networking::Vpn::IVpnChannelStatics;
    template <typename D> using consume = Windows::Networking::Vpn::impl_IVpnChannelStatics<D>;
};

template <> struct traits<Windows::Networking::Vpn::IVpnCredential>
{
    using abi = ABI::Windows::Networking::Vpn::IVpnCredential;
    template <typename D> using consume = Windows::Networking::Vpn::impl_IVpnCredential<D>;
};

template <> struct traits<Windows::Networking::Vpn::IVpnCustomCheckBox>
{
    using abi = ABI::Windows::Networking::Vpn::IVpnCustomCheckBox;
    template <typename D> using consume = Windows::Networking::Vpn::impl_IVpnCustomCheckBox<D>;
};

template <> struct traits<Windows::Networking::Vpn::IVpnCustomComboBox>
{
    using abi = ABI::Windows::Networking::Vpn::IVpnCustomComboBox;
    template <typename D> using consume = Windows::Networking::Vpn::impl_IVpnCustomComboBox<D>;
};

template <> struct traits<Windows::Networking::Vpn::IVpnCustomEditBox>
{
    using abi = ABI::Windows::Networking::Vpn::IVpnCustomEditBox;
    template <typename D> using consume = Windows::Networking::Vpn::impl_IVpnCustomEditBox<D>;
};

template <> struct traits<Windows::Networking::Vpn::IVpnCustomErrorBox>
{
    using abi = ABI::Windows::Networking::Vpn::IVpnCustomErrorBox;
    template <typename D> using consume = Windows::Networking::Vpn::impl_IVpnCustomErrorBox<D>;
};

template <> struct traits<Windows::Networking::Vpn::IVpnCustomPrompt>
{
    using abi = ABI::Windows::Networking::Vpn::IVpnCustomPrompt;
    template <typename D> using consume = Windows::Networking::Vpn::impl_IVpnCustomPrompt<D>;
};

template <> struct traits<Windows::Networking::Vpn::IVpnCustomPromptBooleanInput>
{
    using abi = ABI::Windows::Networking::Vpn::IVpnCustomPromptBooleanInput;
    template <typename D> using consume = Windows::Networking::Vpn::impl_IVpnCustomPromptBooleanInput<D>;
};

template <> struct traits<Windows::Networking::Vpn::IVpnCustomPromptElement>
{
    using abi = ABI::Windows::Networking::Vpn::IVpnCustomPromptElement;
    template <typename D> using consume = Windows::Networking::Vpn::impl_IVpnCustomPromptElement<D>;
};

template <> struct traits<Windows::Networking::Vpn::IVpnCustomPromptOptionSelector>
{
    using abi = ABI::Windows::Networking::Vpn::IVpnCustomPromptOptionSelector;
    template <typename D> using consume = Windows::Networking::Vpn::impl_IVpnCustomPromptOptionSelector<D>;
};

template <> struct traits<Windows::Networking::Vpn::IVpnCustomPromptText>
{
    using abi = ABI::Windows::Networking::Vpn::IVpnCustomPromptText;
    template <typename D> using consume = Windows::Networking::Vpn::impl_IVpnCustomPromptText<D>;
};

template <> struct traits<Windows::Networking::Vpn::IVpnCustomPromptTextInput>
{
    using abi = ABI::Windows::Networking::Vpn::IVpnCustomPromptTextInput;
    template <typename D> using consume = Windows::Networking::Vpn::impl_IVpnCustomPromptTextInput<D>;
};

template <> struct traits<Windows::Networking::Vpn::IVpnCustomTextBox>
{
    using abi = ABI::Windows::Networking::Vpn::IVpnCustomTextBox;
    template <typename D> using consume = Windows::Networking::Vpn::impl_IVpnCustomTextBox<D>;
};

template <> struct traits<Windows::Networking::Vpn::IVpnDomainNameAssignment>
{
    using abi = ABI::Windows::Networking::Vpn::IVpnDomainNameAssignment;
    template <typename D> using consume = Windows::Networking::Vpn::impl_IVpnDomainNameAssignment<D>;
};

template <> struct traits<Windows::Networking::Vpn::IVpnDomainNameInfo>
{
    using abi = ABI::Windows::Networking::Vpn::IVpnDomainNameInfo;
    template <typename D> using consume = Windows::Networking::Vpn::impl_IVpnDomainNameInfo<D>;
};

template <> struct traits<Windows::Networking::Vpn::IVpnDomainNameInfo2>
{
    using abi = ABI::Windows::Networking::Vpn::IVpnDomainNameInfo2;
    template <typename D> using consume = Windows::Networking::Vpn::impl_IVpnDomainNameInfo2<D>;
};

template <> struct traits<Windows::Networking::Vpn::IVpnDomainNameInfoFactory>
{
    using abi = ABI::Windows::Networking::Vpn::IVpnDomainNameInfoFactory;
    template <typename D> using consume = Windows::Networking::Vpn::impl_IVpnDomainNameInfoFactory<D>;
};

template <> struct traits<Windows::Networking::Vpn::IVpnInterfaceId>
{
    using abi = ABI::Windows::Networking::Vpn::IVpnInterfaceId;
    template <typename D> using consume = Windows::Networking::Vpn::impl_IVpnInterfaceId<D>;
};

template <> struct traits<Windows::Networking::Vpn::IVpnInterfaceIdFactory>
{
    using abi = ABI::Windows::Networking::Vpn::IVpnInterfaceIdFactory;
    template <typename D> using consume = Windows::Networking::Vpn::impl_IVpnInterfaceIdFactory<D>;
};

template <> struct traits<Windows::Networking::Vpn::IVpnManagementAgent>
{
    using abi = ABI::Windows::Networking::Vpn::IVpnManagementAgent;
    template <typename D> using consume = Windows::Networking::Vpn::impl_IVpnManagementAgent<D>;
};

template <> struct traits<Windows::Networking::Vpn::IVpnNamespaceAssignment>
{
    using abi = ABI::Windows::Networking::Vpn::IVpnNamespaceAssignment;
    template <typename D> using consume = Windows::Networking::Vpn::impl_IVpnNamespaceAssignment<D>;
};

template <> struct traits<Windows::Networking::Vpn::IVpnNamespaceInfo>
{
    using abi = ABI::Windows::Networking::Vpn::IVpnNamespaceInfo;
    template <typename D> using consume = Windows::Networking::Vpn::impl_IVpnNamespaceInfo<D>;
};

template <> struct traits<Windows::Networking::Vpn::IVpnNamespaceInfoFactory>
{
    using abi = ABI::Windows::Networking::Vpn::IVpnNamespaceInfoFactory;
    template <typename D> using consume = Windows::Networking::Vpn::impl_IVpnNamespaceInfoFactory<D>;
};

template <> struct traits<Windows::Networking::Vpn::IVpnNativeProfile>
{
    using abi = ABI::Windows::Networking::Vpn::IVpnNativeProfile;
    template <typename D> using consume = Windows::Networking::Vpn::impl_IVpnNativeProfile<D>;
};

template <> struct traits<Windows::Networking::Vpn::IVpnNativeProfile2>
{
    using abi = ABI::Windows::Networking::Vpn::IVpnNativeProfile2;
    template <typename D> using consume = Windows::Networking::Vpn::impl_IVpnNativeProfile2<D>;
};

template <> struct traits<Windows::Networking::Vpn::IVpnPacketBuffer>
{
    using abi = ABI::Windows::Networking::Vpn::IVpnPacketBuffer;
    template <typename D> using consume = Windows::Networking::Vpn::impl_IVpnPacketBuffer<D>;
};

template <> struct traits<Windows::Networking::Vpn::IVpnPacketBuffer2>
{
    using abi = ABI::Windows::Networking::Vpn::IVpnPacketBuffer2;
    template <typename D> using consume = Windows::Networking::Vpn::impl_IVpnPacketBuffer2<D>;
};

template <> struct traits<Windows::Networking::Vpn::IVpnPacketBufferFactory>
{
    using abi = ABI::Windows::Networking::Vpn::IVpnPacketBufferFactory;
    template <typename D> using consume = Windows::Networking::Vpn::impl_IVpnPacketBufferFactory<D>;
};

template <> struct traits<Windows::Networking::Vpn::IVpnPacketBufferList>
{
    using abi = ABI::Windows::Networking::Vpn::IVpnPacketBufferList;
    template <typename D> using consume = Windows::Networking::Vpn::impl_IVpnPacketBufferList<D>;
};

template <> struct traits<Windows::Networking::Vpn::IVpnPacketBufferList2>
{
    using abi = ABI::Windows::Networking::Vpn::IVpnPacketBufferList2;
    template <typename D> using consume = Windows::Networking::Vpn::impl_IVpnPacketBufferList2<D>;
};

template <> struct traits<Windows::Networking::Vpn::IVpnPickedCredential>
{
    using abi = ABI::Windows::Networking::Vpn::IVpnPickedCredential;
    template <typename D> using consume = Windows::Networking::Vpn::impl_IVpnPickedCredential<D>;
};

template <> struct traits<Windows::Networking::Vpn::IVpnPlugIn>
{
    using abi = ABI::Windows::Networking::Vpn::IVpnPlugIn;
    template <typename D> using consume = Windows::Networking::Vpn::impl_IVpnPlugIn<D>;
};

template <> struct traits<Windows::Networking::Vpn::IVpnPlugInProfile>
{
    using abi = ABI::Windows::Networking::Vpn::IVpnPlugInProfile;
    template <typename D> using consume = Windows::Networking::Vpn::impl_IVpnPlugInProfile<D>;
};

template <> struct traits<Windows::Networking::Vpn::IVpnPlugInProfile2>
{
    using abi = ABI::Windows::Networking::Vpn::IVpnPlugInProfile2;
    template <typename D> using consume = Windows::Networking::Vpn::impl_IVpnPlugInProfile2<D>;
};

template <> struct traits<Windows::Networking::Vpn::IVpnProfile>
{
    using abi = ABI::Windows::Networking::Vpn::IVpnProfile;
    template <typename D> using consume = Windows::Networking::Vpn::impl_IVpnProfile<D>;
};

template <> struct traits<Windows::Networking::Vpn::IVpnRoute>
{
    using abi = ABI::Windows::Networking::Vpn::IVpnRoute;
    template <typename D> using consume = Windows::Networking::Vpn::impl_IVpnRoute<D>;
};

template <> struct traits<Windows::Networking::Vpn::IVpnRouteAssignment>
{
    using abi = ABI::Windows::Networking::Vpn::IVpnRouteAssignment;
    template <typename D> using consume = Windows::Networking::Vpn::impl_IVpnRouteAssignment<D>;
};

template <> struct traits<Windows::Networking::Vpn::IVpnRouteFactory>
{
    using abi = ABI::Windows::Networking::Vpn::IVpnRouteFactory;
    template <typename D> using consume = Windows::Networking::Vpn::impl_IVpnRouteFactory<D>;
};

template <> struct traits<Windows::Networking::Vpn::IVpnSystemHealth>
{
    using abi = ABI::Windows::Networking::Vpn::IVpnSystemHealth;
    template <typename D> using consume = Windows::Networking::Vpn::impl_IVpnSystemHealth<D>;
};

template <> struct traits<Windows::Networking::Vpn::IVpnTrafficFilter>
{
    using abi = ABI::Windows::Networking::Vpn::IVpnTrafficFilter;
    template <typename D> using consume = Windows::Networking::Vpn::impl_IVpnTrafficFilter<D>;
};

template <> struct traits<Windows::Networking::Vpn::IVpnTrafficFilterAssignment>
{
    using abi = ABI::Windows::Networking::Vpn::IVpnTrafficFilterAssignment;
    template <typename D> using consume = Windows::Networking::Vpn::impl_IVpnTrafficFilterAssignment<D>;
};

template <> struct traits<Windows::Networking::Vpn::IVpnTrafficFilterFactory>
{
    using abi = ABI::Windows::Networking::Vpn::IVpnTrafficFilterFactory;
    template <typename D> using consume = Windows::Networking::Vpn::impl_IVpnTrafficFilterFactory<D>;
};

template <> struct traits<Windows::Networking::Vpn::VpnAppId>
{
    using abi = ABI::Windows::Networking::Vpn::VpnAppId;
    using default_interface = Windows::Networking::Vpn::IVpnAppId;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Networking.Vpn.VpnAppId"; }
};

template <> struct traits<Windows::Networking::Vpn::VpnChannel>
{
    using abi = ABI::Windows::Networking::Vpn::VpnChannel;
    using default_interface = Windows::Networking::Vpn::IVpnChannel;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Networking.Vpn.VpnChannel"; }
};

template <> struct traits<Windows::Networking::Vpn::VpnChannelActivityEventArgs>
{
    using abi = ABI::Windows::Networking::Vpn::VpnChannelActivityEventArgs;
    using default_interface = Windows::Networking::Vpn::IVpnChannelActivityEventArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Networking.Vpn.VpnChannelActivityEventArgs"; }
};

template <> struct traits<Windows::Networking::Vpn::VpnChannelActivityStateChangedArgs>
{
    using abi = ABI::Windows::Networking::Vpn::VpnChannelActivityStateChangedArgs;
    using default_interface = Windows::Networking::Vpn::IVpnChannelActivityStateChangedArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Networking.Vpn.VpnChannelActivityStateChangedArgs"; }
};

template <> struct traits<Windows::Networking::Vpn::VpnChannelConfiguration>
{
    using abi = ABI::Windows::Networking::Vpn::VpnChannelConfiguration;
    using default_interface = Windows::Networking::Vpn::IVpnChannelConfiguration;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Networking.Vpn.VpnChannelConfiguration"; }
};

template <> struct traits<Windows::Networking::Vpn::VpnCredential>
{
    using abi = ABI::Windows::Networking::Vpn::VpnCredential;
    using default_interface = Windows::Networking::Vpn::IVpnCredential;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Networking.Vpn.VpnCredential"; }
};

template <> struct traits<Windows::Networking::Vpn::VpnCustomCheckBox>
{
    using abi = ABI::Windows::Networking::Vpn::VpnCustomCheckBox;
    using default_interface = Windows::Networking::Vpn::IVpnCustomCheckBox;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Networking.Vpn.VpnCustomCheckBox"; }
};

template <> struct traits<Windows::Networking::Vpn::VpnCustomComboBox>
{
    using abi = ABI::Windows::Networking::Vpn::VpnCustomComboBox;
    using default_interface = Windows::Networking::Vpn::IVpnCustomComboBox;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Networking.Vpn.VpnCustomComboBox"; }
};

template <> struct traits<Windows::Networking::Vpn::VpnCustomEditBox>
{
    using abi = ABI::Windows::Networking::Vpn::VpnCustomEditBox;
    using default_interface = Windows::Networking::Vpn::IVpnCustomEditBox;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Networking.Vpn.VpnCustomEditBox"; }
};

template <> struct traits<Windows::Networking::Vpn::VpnCustomErrorBox>
{
    using abi = ABI::Windows::Networking::Vpn::VpnCustomErrorBox;
    using default_interface = Windows::Networking::Vpn::IVpnCustomErrorBox;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Networking.Vpn.VpnCustomErrorBox"; }
};

template <> struct traits<Windows::Networking::Vpn::VpnCustomPromptBooleanInput>
{
    using abi = ABI::Windows::Networking::Vpn::VpnCustomPromptBooleanInput;
    using default_interface = Windows::Networking::Vpn::IVpnCustomPromptBooleanInput;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Networking.Vpn.VpnCustomPromptBooleanInput"; }
};

template <> struct traits<Windows::Networking::Vpn::VpnCustomPromptOptionSelector>
{
    using abi = ABI::Windows::Networking::Vpn::VpnCustomPromptOptionSelector;
    using default_interface = Windows::Networking::Vpn::IVpnCustomPromptOptionSelector;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Networking.Vpn.VpnCustomPromptOptionSelector"; }
};

template <> struct traits<Windows::Networking::Vpn::VpnCustomPromptText>
{
    using abi = ABI::Windows::Networking::Vpn::VpnCustomPromptText;
    using default_interface = Windows::Networking::Vpn::IVpnCustomPromptText;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Networking.Vpn.VpnCustomPromptText"; }
};

template <> struct traits<Windows::Networking::Vpn::VpnCustomPromptTextInput>
{
    using abi = ABI::Windows::Networking::Vpn::VpnCustomPromptTextInput;
    using default_interface = Windows::Networking::Vpn::IVpnCustomPromptTextInput;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Networking.Vpn.VpnCustomPromptTextInput"; }
};

template <> struct traits<Windows::Networking::Vpn::VpnCustomTextBox>
{
    using abi = ABI::Windows::Networking::Vpn::VpnCustomTextBox;
    using default_interface = Windows::Networking::Vpn::IVpnCustomTextBox;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Networking.Vpn.VpnCustomTextBox"; }
};

template <> struct traits<Windows::Networking::Vpn::VpnDomainNameAssignment>
{
    using abi = ABI::Windows::Networking::Vpn::VpnDomainNameAssignment;
    using default_interface = Windows::Networking::Vpn::IVpnDomainNameAssignment;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Networking.Vpn.VpnDomainNameAssignment"; }
};

template <> struct traits<Windows::Networking::Vpn::VpnDomainNameInfo>
{
    using abi = ABI::Windows::Networking::Vpn::VpnDomainNameInfo;
    using default_interface = Windows::Networking::Vpn::IVpnDomainNameInfo;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Networking.Vpn.VpnDomainNameInfo"; }
};

template <> struct traits<Windows::Networking::Vpn::VpnInterfaceId>
{
    using abi = ABI::Windows::Networking::Vpn::VpnInterfaceId;
    using default_interface = Windows::Networking::Vpn::IVpnInterfaceId;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Networking.Vpn.VpnInterfaceId"; }
};

template <> struct traits<Windows::Networking::Vpn::VpnManagementAgent>
{
    using abi = ABI::Windows::Networking::Vpn::VpnManagementAgent;
    using default_interface = Windows::Networking::Vpn::IVpnManagementAgent;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Networking.Vpn.VpnManagementAgent"; }
};

template <> struct traits<Windows::Networking::Vpn::VpnNamespaceAssignment>
{
    using abi = ABI::Windows::Networking::Vpn::VpnNamespaceAssignment;
    using default_interface = Windows::Networking::Vpn::IVpnNamespaceAssignment;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Networking.Vpn.VpnNamespaceAssignment"; }
};

template <> struct traits<Windows::Networking::Vpn::VpnNamespaceInfo>
{
    using abi = ABI::Windows::Networking::Vpn::VpnNamespaceInfo;
    using default_interface = Windows::Networking::Vpn::IVpnNamespaceInfo;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Networking.Vpn.VpnNamespaceInfo"; }
};

template <> struct traits<Windows::Networking::Vpn::VpnNativeProfile>
{
    using abi = ABI::Windows::Networking::Vpn::VpnNativeProfile;
    using default_interface = Windows::Networking::Vpn::IVpnNativeProfile;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Networking.Vpn.VpnNativeProfile"; }
};

template <> struct traits<Windows::Networking::Vpn::VpnPacketBuffer>
{
    using abi = ABI::Windows::Networking::Vpn::VpnPacketBuffer;
    using default_interface = Windows::Networking::Vpn::IVpnPacketBuffer;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Networking.Vpn.VpnPacketBuffer"; }
};

template <> struct traits<Windows::Networking::Vpn::VpnPacketBufferList>
{
    using abi = ABI::Windows::Networking::Vpn::VpnPacketBufferList;
    using default_interface = Windows::Networking::Vpn::IVpnPacketBufferList;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Networking.Vpn.VpnPacketBufferList"; }
};

template <> struct traits<Windows::Networking::Vpn::VpnPickedCredential>
{
    using abi = ABI::Windows::Networking::Vpn::VpnPickedCredential;
    using default_interface = Windows::Networking::Vpn::IVpnPickedCredential;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Networking.Vpn.VpnPickedCredential"; }
};

template <> struct traits<Windows::Networking::Vpn::VpnPlugInProfile>
{
    using abi = ABI::Windows::Networking::Vpn::VpnPlugInProfile;
    using default_interface = Windows::Networking::Vpn::IVpnPlugInProfile;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Networking.Vpn.VpnPlugInProfile"; }
};

template <> struct traits<Windows::Networking::Vpn::VpnRoute>
{
    using abi = ABI::Windows::Networking::Vpn::VpnRoute;
    using default_interface = Windows::Networking::Vpn::IVpnRoute;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Networking.Vpn.VpnRoute"; }
};

template <> struct traits<Windows::Networking::Vpn::VpnRouteAssignment>
{
    using abi = ABI::Windows::Networking::Vpn::VpnRouteAssignment;
    using default_interface = Windows::Networking::Vpn::IVpnRouteAssignment;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Networking.Vpn.VpnRouteAssignment"; }
};

template <> struct traits<Windows::Networking::Vpn::VpnSystemHealth>
{
    using abi = ABI::Windows::Networking::Vpn::VpnSystemHealth;
    using default_interface = Windows::Networking::Vpn::IVpnSystemHealth;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Networking.Vpn.VpnSystemHealth"; }
};

template <> struct traits<Windows::Networking::Vpn::VpnTrafficFilter>
{
    using abi = ABI::Windows::Networking::Vpn::VpnTrafficFilter;
    using default_interface = Windows::Networking::Vpn::IVpnTrafficFilter;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Networking.Vpn.VpnTrafficFilter"; }
};

template <> struct traits<Windows::Networking::Vpn::VpnTrafficFilterAssignment>
{
    using abi = ABI::Windows::Networking::Vpn::VpnTrafficFilterAssignment;
    using default_interface = Windows::Networking::Vpn::IVpnTrafficFilterAssignment;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Networking.Vpn.VpnTrafficFilterAssignment"; }
};

}

}