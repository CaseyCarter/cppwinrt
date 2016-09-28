// C++ for the Windows Runtime v1.29
// Copyright (c) 2016 Microsoft Corporation

#pragma once

#include "../base.h"
#include "Windows.Devices.Sms.0.h"
#include "Windows.Foundation.0.h"
#include "Windows.Storage.Streams.0.h"
#include "Windows.Foundation.Collections.1.h"
#include "Windows.Foundation.1.h"

WINRT_EXPORT namespace winrt {

namespace ABI::Windows::Devices::Sms {

struct SmsEncodedLength
{
    uint32_t SegmentCount;
    uint32_t CharacterCountLastSegment;
    uint32_t CharactersPerSegment;
    uint32_t ByteCountLastSegment;
    uint32_t BytesPerSegment;
};

}

namespace Windows::Devices::Sms {

using SmsEncodedLength = ABI::Windows::Devices::Sms::SmsEncodedLength;

}

namespace ABI::Windows::Devices::Sms {

struct __declspec(uuid("e8bb8494-d3a0-4a0a-86d7-291033a8cf54")) __declspec(novtable) ISmsAppMessage : Windows::IInspectable
{
    virtual HRESULT __stdcall get_Timestamp(Windows::Foundation::DateTime * value) = 0;
    virtual HRESULT __stdcall get_To(hstring * value) = 0;
    virtual HRESULT __stdcall put_To(hstring value) = 0;
    virtual HRESULT __stdcall get_From(hstring * value) = 0;
    virtual HRESULT __stdcall get_Body(hstring * value) = 0;
    virtual HRESULT __stdcall put_Body(hstring value) = 0;
    virtual HRESULT __stdcall get_CallbackNumber(hstring * value) = 0;
    virtual HRESULT __stdcall put_CallbackNumber(hstring value) = 0;
    virtual HRESULT __stdcall get_IsDeliveryNotificationEnabled(bool * value) = 0;
    virtual HRESULT __stdcall put_IsDeliveryNotificationEnabled(bool value) = 0;
    virtual HRESULT __stdcall get_RetryAttemptCount(int32_t * value) = 0;
    virtual HRESULT __stdcall put_RetryAttemptCount(int32_t value) = 0;
    virtual HRESULT __stdcall get_Encoding(winrt::Windows::Devices::Sms::SmsEncoding * value) = 0;
    virtual HRESULT __stdcall put_Encoding(winrt::Windows::Devices::Sms::SmsEncoding value) = 0;
    virtual HRESULT __stdcall get_PortNumber(int32_t * value) = 0;
    virtual HRESULT __stdcall put_PortNumber(int32_t value) = 0;
    virtual HRESULT __stdcall get_TeleserviceId(int32_t * value) = 0;
    virtual HRESULT __stdcall put_TeleserviceId(int32_t value) = 0;
    virtual HRESULT __stdcall get_ProtocolId(int32_t * value) = 0;
    virtual HRESULT __stdcall put_ProtocolId(int32_t value) = 0;
    virtual HRESULT __stdcall get_BinaryBody(Windows::Storage::Streams::IBuffer ** value) = 0;
    virtual HRESULT __stdcall put_BinaryBody(Windows::Storage::Streams::IBuffer * value) = 0;
};

struct __declspec(uuid("75aebbf1-e4b7-4874-a09c-2956e592f957")) __declspec(novtable) ISmsBroadcastMessage : Windows::IInspectable
{
    virtual HRESULT __stdcall get_Timestamp(Windows::Foundation::DateTime * value) = 0;
    virtual HRESULT __stdcall get_To(hstring * value) = 0;
    virtual HRESULT __stdcall get_Body(hstring * value) = 0;
    virtual HRESULT __stdcall get_Channel(int32_t * value) = 0;
    virtual HRESULT __stdcall get_GeographicalScope(winrt::Windows::Devices::Sms::SmsGeographicalScope * value) = 0;
    virtual HRESULT __stdcall get_MessageCode(int32_t * value) = 0;
    virtual HRESULT __stdcall get_UpdateNumber(int32_t * value) = 0;
    virtual HRESULT __stdcall get_BroadcastType(winrt::Windows::Devices::Sms::SmsBroadcastType * value) = 0;
    virtual HRESULT __stdcall get_IsEmergencyAlert(bool * value) = 0;
    virtual HRESULT __stdcall get_IsUserPopupRequested(bool * value) = 0;
};

struct __declspec(uuid("bd8a5c13-e522-46cb-b8d5-9ead30fb6c47")) __declspec(novtable) ISmsDevice2 : Windows::IInspectable
{
    virtual HRESULT __stdcall get_SmscAddress(hstring * value) = 0;
    virtual HRESULT __stdcall put_SmscAddress(hstring value) = 0;
    virtual HRESULT __stdcall get_DeviceId(hstring * value) = 0;
    virtual HRESULT __stdcall get_ParentDeviceId(hstring * value) = 0;
    virtual HRESULT __stdcall get_AccountPhoneNumber(hstring * value) = 0;
    virtual HRESULT __stdcall get_CellularClass(winrt::Windows::Devices::Sms::CellularClass * value) = 0;
    virtual HRESULT __stdcall get_DeviceStatus(winrt::Windows::Devices::Sms::SmsDeviceStatus * value) = 0;
    virtual HRESULT __stdcall abi_CalculateLength(Windows::Devices::Sms::ISmsMessageBase * message, Windows::Devices::Sms::SmsEncodedLength * value) = 0;
    virtual HRESULT __stdcall abi_SendMessageAndGetResultAsync(Windows::Devices::Sms::ISmsMessageBase * message, Windows::Foundation::IAsyncOperation<Windows::Devices::Sms::SmsSendMessageResult> ** asyncInfo) = 0;
    virtual HRESULT __stdcall add_DeviceStatusChanged(Windows::Foundation::TypedEventHandler<Windows::Devices::Sms::SmsDevice2, Windows::IInspectable> * eventHandler, event_token * eventCookie) = 0;
    virtual HRESULT __stdcall remove_DeviceStatusChanged(event_token eventCookie) = 0;
};

struct __declspec(uuid("65c78325-1031-491e-8fb6-ef9991afe363")) __declspec(novtable) ISmsDevice2Statics : Windows::IInspectable
{
    virtual HRESULT __stdcall abi_GetDeviceSelector(hstring * value) = 0;
    virtual HRESULT __stdcall abi_FromId(hstring deviceId, Windows::Devices::Sms::ISmsDevice2 ** value) = 0;
    virtual HRESULT __stdcall abi_GetDefault(Windows::Devices::Sms::ISmsDevice2 ** value) = 0;
    virtual HRESULT __stdcall abi_FromParentId(hstring parentDeviceId, Windows::Devices::Sms::ISmsDevice2 ** value) = 0;
};

struct __declspec(uuid("40e32fae-b049-4fbc-afe9-e2a610eff55c")) __declspec(novtable) ISmsFilterRule : Windows::IInspectable
{
    virtual HRESULT __stdcall get_MessageType(winrt::Windows::Devices::Sms::SmsMessageType * value) = 0;
    virtual HRESULT __stdcall get_ImsiPrefixes(Windows::Foundation::Collections::IVector<hstring> ** value) = 0;
    virtual HRESULT __stdcall get_DeviceIds(Windows::Foundation::Collections::IVector<hstring> ** value) = 0;
    virtual HRESULT __stdcall get_SenderNumbers(Windows::Foundation::Collections::IVector<hstring> ** value) = 0;
    virtual HRESULT __stdcall get_TextMessagePrefixes(Windows::Foundation::Collections::IVector<hstring> ** value) = 0;
    virtual HRESULT __stdcall get_PortNumbers(Windows::Foundation::Collections::IVector<int32_t> ** value) = 0;
    virtual HRESULT __stdcall get_CellularClass(winrt::Windows::Devices::Sms::CellularClass * value) = 0;
    virtual HRESULT __stdcall put_CellularClass(winrt::Windows::Devices::Sms::CellularClass value) = 0;
    virtual HRESULT __stdcall get_ProtocolIds(Windows::Foundation::Collections::IVector<int32_t> ** value) = 0;
    virtual HRESULT __stdcall get_TeleserviceIds(Windows::Foundation::Collections::IVector<int32_t> ** value) = 0;
    virtual HRESULT __stdcall get_WapApplicationIds(Windows::Foundation::Collections::IVector<hstring> ** value) = 0;
    virtual HRESULT __stdcall get_WapContentTypes(Windows::Foundation::Collections::IVector<hstring> ** value) = 0;
    virtual HRESULT __stdcall get_BroadcastTypes(Windows::Foundation::Collections::IVector<winrt::Windows::Devices::Sms::SmsBroadcastType> ** value) = 0;
    virtual HRESULT __stdcall get_BroadcastChannels(Windows::Foundation::Collections::IVector<int32_t> ** value) = 0;
};

struct __declspec(uuid("00c36508-6296-4f29-9aad-8920ceba3ce8")) __declspec(novtable) ISmsFilterRuleFactory : Windows::IInspectable
{
    virtual HRESULT __stdcall abi_CreateFilterRule(winrt::Windows::Devices::Sms::SmsMessageType messageType, Windows::Devices::Sms::ISmsFilterRule ** value) = 0;
};

struct __declspec(uuid("4e47eafb-79cd-4881-9894-55a4135b23fa")) __declspec(novtable) ISmsFilterRules : Windows::IInspectable
{
    virtual HRESULT __stdcall get_ActionType(winrt::Windows::Devices::Sms::SmsFilterActionType * value) = 0;
    virtual HRESULT __stdcall get_Rules(Windows::Foundation::Collections::IVector<Windows::Devices::Sms::SmsFilterRule> ** value) = 0;
};

struct __declspec(uuid("a09924ed-6e2e-4530-9fde-465d02eed00e")) __declspec(novtable) ISmsFilterRulesFactory : Windows::IInspectable
{
    virtual HRESULT __stdcall abi_CreateFilterRules(winrt::Windows::Devices::Sms::SmsFilterActionType actionType, Windows::Devices::Sms::ISmsFilterRules ** value) = 0;
};

struct __declspec(uuid("2cf0fe30-fe50-4fc6-aa88-4ccfe27a29ea")) __declspec(novtable) ISmsMessageBase : Windows::IInspectable
{
    virtual HRESULT __stdcall get_MessageType(winrt::Windows::Devices::Sms::SmsMessageType * value) = 0;
    virtual HRESULT __stdcall get_DeviceId(hstring * value) = 0;
    virtual HRESULT __stdcall get_CellularClass(winrt::Windows::Devices::Sms::CellularClass * value) = 0;
    virtual HRESULT __stdcall get_MessageClass(winrt::Windows::Devices::Sms::SmsMessageClass * value) = 0;
    virtual HRESULT __stdcall get_SimIccId(hstring * value) = 0;
};

struct __declspec(uuid("2bcfcbd4-2657-4128-ad5f-e3877132bdb1")) __declspec(novtable) ISmsMessageReceivedTriggerDetails : Windows::IInspectable
{
    virtual HRESULT __stdcall get_MessageType(winrt::Windows::Devices::Sms::SmsMessageType * value) = 0;
    virtual HRESULT __stdcall get_TextMessage(Windows::Devices::Sms::ISmsTextMessage2 ** value) = 0;
    virtual HRESULT __stdcall get_WapMessage(Windows::Devices::Sms::ISmsWapMessage ** value) = 0;
    virtual HRESULT __stdcall get_AppMessage(Windows::Devices::Sms::ISmsAppMessage ** value) = 0;
    virtual HRESULT __stdcall get_BroadcastMessage(Windows::Devices::Sms::ISmsBroadcastMessage ** value) = 0;
    virtual HRESULT __stdcall get_VoicemailMessage(Windows::Devices::Sms::ISmsVoicemailMessage ** value) = 0;
    virtual HRESULT __stdcall get_StatusMessage(Windows::Devices::Sms::ISmsStatusMessage ** value) = 0;
    virtual HRESULT __stdcall abi_Drop() = 0;
    virtual HRESULT __stdcall abi_Accept() = 0;
};

struct __declspec(uuid("1720503e-f34f-446b-83b3-0ff19923b409")) __declspec(novtable) ISmsMessageRegistration : Windows::IInspectable
{
    virtual HRESULT __stdcall get_Id(hstring * value) = 0;
    virtual HRESULT __stdcall abi_Unregister() = 0;
    virtual HRESULT __stdcall add_MessageReceived(Windows::Foundation::TypedEventHandler<Windows::Devices::Sms::SmsMessageRegistration, Windows::Devices::Sms::SmsMessageReceivedTriggerDetails> * eventHandler, event_token * eventCookie) = 0;
    virtual HRESULT __stdcall remove_MessageReceived(event_token eventCookie) = 0;
};

struct __declspec(uuid("63a05464-2898-4778-a03c-6f994907d63a")) __declspec(novtable) ISmsMessageRegistrationStatics : Windows::IInspectable
{
    virtual HRESULT __stdcall get_AllRegistrations(Windows::Foundation::Collections::IVectorView<Windows::Devices::Sms::SmsMessageRegistration> ** value) = 0;
    virtual HRESULT __stdcall abi_Register(hstring id, Windows::Devices::Sms::ISmsFilterRules * filterRules, Windows::Devices::Sms::ISmsMessageRegistration ** value) = 0;
};

struct __declspec(uuid("db139af2-78c9-4feb-9622-452328088d62")) __declspec(novtable) ISmsSendMessageResult : Windows::IInspectable
{
    virtual HRESULT __stdcall get_IsSuccessful(bool * value) = 0;
    virtual HRESULT __stdcall get_MessageReferenceNumbers(Windows::Foundation::Collections::IVectorView<int32_t> ** value) = 0;
    virtual HRESULT __stdcall get_CellularClass(winrt::Windows::Devices::Sms::CellularClass * value) = 0;
    virtual HRESULT __stdcall get_ModemErrorCode(winrt::Windows::Devices::Sms::SmsModemErrorCode * value) = 0;
    virtual HRESULT __stdcall get_IsErrorTransient(bool * value) = 0;
    virtual HRESULT __stdcall get_NetworkCauseCode(int32_t * value) = 0;
    virtual HRESULT __stdcall get_TransportFailureCause(int32_t * value) = 0;
};

struct __declspec(uuid("e6d28342-b70b-4677-9379-c9783fdff8f4")) __declspec(novtable) ISmsStatusMessage : Windows::IInspectable
{
    virtual HRESULT __stdcall get_To(hstring * value) = 0;
    virtual HRESULT __stdcall get_From(hstring * value) = 0;
    virtual HRESULT __stdcall get_Body(hstring * value) = 0;
    virtual HRESULT __stdcall get_Status(int32_t * value) = 0;
    virtual HRESULT __stdcall get_MessageReferenceNumber(int32_t * value) = 0;
    virtual HRESULT __stdcall get_ServiceCenterTimestamp(Windows::Foundation::DateTime * value) = 0;
    virtual HRESULT __stdcall get_DischargeTime(Windows::Foundation::DateTime * value) = 0;
};

struct __declspec(uuid("22a0d893-4555-4755-b5a1-e7fd84955f8d")) __declspec(novtable) ISmsTextMessage2 : Windows::IInspectable
{
    virtual HRESULT __stdcall get_Timestamp(Windows::Foundation::DateTime * value) = 0;
    virtual HRESULT __stdcall get_To(hstring * value) = 0;
    virtual HRESULT __stdcall put_To(hstring value) = 0;
    virtual HRESULT __stdcall get_From(hstring * value) = 0;
    virtual HRESULT __stdcall get_Body(hstring * value) = 0;
    virtual HRESULT __stdcall put_Body(hstring value) = 0;
    virtual HRESULT __stdcall get_Encoding(winrt::Windows::Devices::Sms::SmsEncoding * value) = 0;
    virtual HRESULT __stdcall put_Encoding(winrt::Windows::Devices::Sms::SmsEncoding value) = 0;
    virtual HRESULT __stdcall get_CallbackNumber(hstring * value) = 0;
    virtual HRESULT __stdcall put_CallbackNumber(hstring value) = 0;
    virtual HRESULT __stdcall get_IsDeliveryNotificationEnabled(bool * value) = 0;
    virtual HRESULT __stdcall put_IsDeliveryNotificationEnabled(bool value) = 0;
    virtual HRESULT __stdcall get_RetryAttemptCount(int32_t * value) = 0;
    virtual HRESULT __stdcall put_RetryAttemptCount(int32_t value) = 0;
    virtual HRESULT __stdcall get_TeleserviceId(int32_t * value) = 0;
    virtual HRESULT __stdcall get_ProtocolId(int32_t * value) = 0;
};

struct __declspec(uuid("271aa0a6-95b1-44ff-bcb8-b8fdd7e08bc3")) __declspec(novtable) ISmsVoicemailMessage : Windows::IInspectable
{
    virtual HRESULT __stdcall get_Timestamp(Windows::Foundation::DateTime * value) = 0;
    virtual HRESULT __stdcall get_To(hstring * value) = 0;
    virtual HRESULT __stdcall get_Body(hstring * value) = 0;
    virtual HRESULT __stdcall get_MessageCount(Windows::Foundation::IReference<int32_t> ** value) = 0;
};

struct __declspec(uuid("cd937743-7a55-4d3b-9021-f22e022d09c5")) __declspec(novtable) ISmsWapMessage : Windows::IInspectable
{
    virtual HRESULT __stdcall get_Timestamp(Windows::Foundation::DateTime * value) = 0;
    virtual HRESULT __stdcall get_To(hstring * value) = 0;
    virtual HRESULT __stdcall get_From(hstring * value) = 0;
    virtual HRESULT __stdcall get_ApplicationId(hstring * value) = 0;
    virtual HRESULT __stdcall get_ContentType(hstring * value) = 0;
    virtual HRESULT __stdcall get_BinaryBody(Windows::Storage::Streams::IBuffer ** value) = 0;
    virtual HRESULT __stdcall get_Headers(Windows::Foundation::Collections::IMap<hstring, hstring> ** value) = 0;
};

}

namespace ABI {

template <> struct traits<Windows::Devices::Sms::SmsAppMessage> { using default_interface = Windows::Devices::Sms::ISmsAppMessage; };
template <> struct traits<Windows::Devices::Sms::SmsBroadcastMessage> { using default_interface = Windows::Devices::Sms::ISmsBroadcastMessage; };
template <> struct traits<Windows::Devices::Sms::SmsDevice2> { using default_interface = Windows::Devices::Sms::ISmsDevice2; };
template <> struct traits<Windows::Devices::Sms::SmsFilterRule> { using default_interface = Windows::Devices::Sms::ISmsFilterRule; };
template <> struct traits<Windows::Devices::Sms::SmsFilterRules> { using default_interface = Windows::Devices::Sms::ISmsFilterRules; };
template <> struct traits<Windows::Devices::Sms::SmsMessageReceivedTriggerDetails> { using default_interface = Windows::Devices::Sms::ISmsMessageReceivedTriggerDetails; };
template <> struct traits<Windows::Devices::Sms::SmsMessageRegistration> { using default_interface = Windows::Devices::Sms::ISmsMessageRegistration; };
template <> struct traits<Windows::Devices::Sms::SmsSendMessageResult> { using default_interface = Windows::Devices::Sms::ISmsSendMessageResult; };
template <> struct traits<Windows::Devices::Sms::SmsStatusMessage> { using default_interface = Windows::Devices::Sms::ISmsStatusMessage; };
template <> struct traits<Windows::Devices::Sms::SmsTextMessage2> { using default_interface = Windows::Devices::Sms::ISmsTextMessage2; };
template <> struct traits<Windows::Devices::Sms::SmsVoicemailMessage> { using default_interface = Windows::Devices::Sms::ISmsVoicemailMessage; };
template <> struct traits<Windows::Devices::Sms::SmsWapMessage> { using default_interface = Windows::Devices::Sms::ISmsWapMessage; };

}

namespace Windows::Devices::Sms {

template <typename T> struct impl_ISmsAppMessage;
template <typename T> struct impl_ISmsBroadcastMessage;
template <typename T> struct impl_ISmsDevice2;
template <typename T> struct impl_ISmsDevice2Statics;
template <typename T> struct impl_ISmsFilterRule;
template <typename T> struct impl_ISmsFilterRuleFactory;
template <typename T> struct impl_ISmsFilterRules;
template <typename T> struct impl_ISmsFilterRulesFactory;
template <typename T> struct impl_ISmsMessageBase;
template <typename T> struct impl_ISmsMessageReceivedTriggerDetails;
template <typename T> struct impl_ISmsMessageRegistration;
template <typename T> struct impl_ISmsMessageRegistrationStatics;
template <typename T> struct impl_ISmsSendMessageResult;
template <typename T> struct impl_ISmsStatusMessage;
template <typename T> struct impl_ISmsTextMessage2;
template <typename T> struct impl_ISmsVoicemailMessage;
template <typename T> struct impl_ISmsWapMessage;

}

namespace impl {

template <> struct traits<Windows::Devices::Sms::ISmsAppMessage>
{
    using abi = ABI::Windows::Devices::Sms::ISmsAppMessage;
    template <typename D> using consume = Windows::Devices::Sms::impl_ISmsAppMessage<D>;
};

template <> struct traits<Windows::Devices::Sms::ISmsBroadcastMessage>
{
    using abi = ABI::Windows::Devices::Sms::ISmsBroadcastMessage;
    template <typename D> using consume = Windows::Devices::Sms::impl_ISmsBroadcastMessage<D>;
};

template <> struct traits<Windows::Devices::Sms::ISmsDevice2>
{
    using abi = ABI::Windows::Devices::Sms::ISmsDevice2;
    template <typename D> using consume = Windows::Devices::Sms::impl_ISmsDevice2<D>;
};

template <> struct traits<Windows::Devices::Sms::ISmsDevice2Statics>
{
    using abi = ABI::Windows::Devices::Sms::ISmsDevice2Statics;
    template <typename D> using consume = Windows::Devices::Sms::impl_ISmsDevice2Statics<D>;
};

template <> struct traits<Windows::Devices::Sms::ISmsFilterRule>
{
    using abi = ABI::Windows::Devices::Sms::ISmsFilterRule;
    template <typename D> using consume = Windows::Devices::Sms::impl_ISmsFilterRule<D>;
};

template <> struct traits<Windows::Devices::Sms::ISmsFilterRuleFactory>
{
    using abi = ABI::Windows::Devices::Sms::ISmsFilterRuleFactory;
    template <typename D> using consume = Windows::Devices::Sms::impl_ISmsFilterRuleFactory<D>;
};

template <> struct traits<Windows::Devices::Sms::ISmsFilterRules>
{
    using abi = ABI::Windows::Devices::Sms::ISmsFilterRules;
    template <typename D> using consume = Windows::Devices::Sms::impl_ISmsFilterRules<D>;
};

template <> struct traits<Windows::Devices::Sms::ISmsFilterRulesFactory>
{
    using abi = ABI::Windows::Devices::Sms::ISmsFilterRulesFactory;
    template <typename D> using consume = Windows::Devices::Sms::impl_ISmsFilterRulesFactory<D>;
};

template <> struct traits<Windows::Devices::Sms::ISmsMessageBase>
{
    using abi = ABI::Windows::Devices::Sms::ISmsMessageBase;
    template <typename D> using consume = Windows::Devices::Sms::impl_ISmsMessageBase<D>;
};

template <> struct traits<Windows::Devices::Sms::ISmsMessageReceivedTriggerDetails>
{
    using abi = ABI::Windows::Devices::Sms::ISmsMessageReceivedTriggerDetails;
    template <typename D> using consume = Windows::Devices::Sms::impl_ISmsMessageReceivedTriggerDetails<D>;
};

template <> struct traits<Windows::Devices::Sms::ISmsMessageRegistration>
{
    using abi = ABI::Windows::Devices::Sms::ISmsMessageRegistration;
    template <typename D> using consume = Windows::Devices::Sms::impl_ISmsMessageRegistration<D>;
};

template <> struct traits<Windows::Devices::Sms::ISmsMessageRegistrationStatics>
{
    using abi = ABI::Windows::Devices::Sms::ISmsMessageRegistrationStatics;
    template <typename D> using consume = Windows::Devices::Sms::impl_ISmsMessageRegistrationStatics<D>;
};

template <> struct traits<Windows::Devices::Sms::ISmsSendMessageResult>
{
    using abi = ABI::Windows::Devices::Sms::ISmsSendMessageResult;
    template <typename D> using consume = Windows::Devices::Sms::impl_ISmsSendMessageResult<D>;
};

template <> struct traits<Windows::Devices::Sms::ISmsStatusMessage>
{
    using abi = ABI::Windows::Devices::Sms::ISmsStatusMessage;
    template <typename D> using consume = Windows::Devices::Sms::impl_ISmsStatusMessage<D>;
};

template <> struct traits<Windows::Devices::Sms::ISmsTextMessage2>
{
    using abi = ABI::Windows::Devices::Sms::ISmsTextMessage2;
    template <typename D> using consume = Windows::Devices::Sms::impl_ISmsTextMessage2<D>;
};

template <> struct traits<Windows::Devices::Sms::ISmsVoicemailMessage>
{
    using abi = ABI::Windows::Devices::Sms::ISmsVoicemailMessage;
    template <typename D> using consume = Windows::Devices::Sms::impl_ISmsVoicemailMessage<D>;
};

template <> struct traits<Windows::Devices::Sms::ISmsWapMessage>
{
    using abi = ABI::Windows::Devices::Sms::ISmsWapMessage;
    template <typename D> using consume = Windows::Devices::Sms::impl_ISmsWapMessage<D>;
};

template <> struct traits<Windows::Devices::Sms::SmsAppMessage>
{
    using abi = ABI::Windows::Devices::Sms::SmsAppMessage;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Devices.Sms.SmsAppMessage"; }
};

template <> struct traits<Windows::Devices::Sms::SmsBroadcastMessage>
{
    using abi = ABI::Windows::Devices::Sms::SmsBroadcastMessage;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Devices.Sms.SmsBroadcastMessage"; }
};

template <> struct traits<Windows::Devices::Sms::SmsDevice2>
{
    using abi = ABI::Windows::Devices::Sms::SmsDevice2;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Devices.Sms.SmsDevice2"; }
};

template <> struct traits<Windows::Devices::Sms::SmsFilterRule>
{
    using abi = ABI::Windows::Devices::Sms::SmsFilterRule;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Devices.Sms.SmsFilterRule"; }
};

template <> struct traits<Windows::Devices::Sms::SmsFilterRules>
{
    using abi = ABI::Windows::Devices::Sms::SmsFilterRules;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Devices.Sms.SmsFilterRules"; }
};

template <> struct traits<Windows::Devices::Sms::SmsMessageReceivedTriggerDetails>
{
    using abi = ABI::Windows::Devices::Sms::SmsMessageReceivedTriggerDetails;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Devices.Sms.SmsMessageReceivedTriggerDetails"; }
};

template <> struct traits<Windows::Devices::Sms::SmsMessageRegistration>
{
    using abi = ABI::Windows::Devices::Sms::SmsMessageRegistration;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Devices.Sms.SmsMessageRegistration"; }
};

template <> struct traits<Windows::Devices::Sms::SmsSendMessageResult>
{
    using abi = ABI::Windows::Devices::Sms::SmsSendMessageResult;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Devices.Sms.SmsSendMessageResult"; }
};

template <> struct traits<Windows::Devices::Sms::SmsStatusMessage>
{
    using abi = ABI::Windows::Devices::Sms::SmsStatusMessage;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Devices.Sms.SmsStatusMessage"; }
};

template <> struct traits<Windows::Devices::Sms::SmsTextMessage2>
{
    using abi = ABI::Windows::Devices::Sms::SmsTextMessage2;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Devices.Sms.SmsTextMessage2"; }
};

template <> struct traits<Windows::Devices::Sms::SmsVoicemailMessage>
{
    using abi = ABI::Windows::Devices::Sms::SmsVoicemailMessage;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Devices.Sms.SmsVoicemailMessage"; }
};

template <> struct traits<Windows::Devices::Sms::SmsWapMessage>
{
    using abi = ABI::Windows::Devices::Sms::SmsWapMessage;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Devices.Sms.SmsWapMessage"; }
};

}

}
