// C++ for the Windows Runtime v1.29
// Copyright (c) 2016 Microsoft Corporation

#pragma once

#include "internal/Windows.Foundation.3.h"
#include "internal/Windows.Storage.Streams.3.h"
#include "internal/Windows.Foundation.Collections.3.h"
#include "internal/Windows.Devices.Sms.3.h"
#include "Windows.Devices.h"

WINRT_EXPORT namespace winrt {

namespace impl {

template <typename D>
struct produce<D, Windows::Devices::Sms::ISmsAppMessage> : produce_base<D, Windows::Devices::Sms::ISmsAppMessage>
{
    HRESULT __stdcall get_Timestamp(abi_arg_out<Windows::Foundation::DateTime> value) noexcept override
    {
        try
        {
            *value = detach(this->shim().Timestamp());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_To(abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            *value = detach(this->shim().To());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_To(abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            this->shim().To(*reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_From(abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            *value = detach(this->shim().From());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Body(abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            *value = detach(this->shim().Body());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Body(abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            this->shim().Body(*reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_CallbackNumber(abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            *value = detach(this->shim().CallbackNumber());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_CallbackNumber(abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            this->shim().CallbackNumber(*reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_IsDeliveryNotificationEnabled(bool * value) noexcept override
    {
        try
        {
            *value = detach(this->shim().IsDeliveryNotificationEnabled());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_IsDeliveryNotificationEnabled(bool value) noexcept override
    {
        try
        {
            this->shim().IsDeliveryNotificationEnabled(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_RetryAttemptCount(int32_t * value) noexcept override
    {
        try
        {
            *value = detach(this->shim().RetryAttemptCount());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_RetryAttemptCount(int32_t value) noexcept override
    {
        try
        {
            this->shim().RetryAttemptCount(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Encoding(Windows::Devices::Sms::SmsEncoding * value) noexcept override
    {
        try
        {
            *value = detach(this->shim().Encoding());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Encoding(Windows::Devices::Sms::SmsEncoding value) noexcept override
    {
        try
        {
            this->shim().Encoding(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_PortNumber(int32_t * value) noexcept override
    {
        try
        {
            *value = detach(this->shim().PortNumber());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_PortNumber(int32_t value) noexcept override
    {
        try
        {
            this->shim().PortNumber(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_TeleserviceId(int32_t * value) noexcept override
    {
        try
        {
            *value = detach(this->shim().TeleserviceId());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_TeleserviceId(int32_t value) noexcept override
    {
        try
        {
            this->shim().TeleserviceId(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ProtocolId(int32_t * value) noexcept override
    {
        try
        {
            *value = detach(this->shim().ProtocolId());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_ProtocolId(int32_t value) noexcept override
    {
        try
        {
            this->shim().ProtocolId(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_BinaryBody(abi_arg_out<Windows::Storage::Streams::IBuffer> value) noexcept override
    {
        try
        {
            *value = detach(this->shim().BinaryBody());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_BinaryBody(abi_arg_in<Windows::Storage::Streams::IBuffer> value) noexcept override
    {
        try
        {
            this->shim().BinaryBody(*reinterpret_cast<const Windows::Storage::Streams::IBuffer *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Devices::Sms::ISmsBroadcastMessage> : produce_base<D, Windows::Devices::Sms::ISmsBroadcastMessage>
{
    HRESULT __stdcall get_Timestamp(abi_arg_out<Windows::Foundation::DateTime> value) noexcept override
    {
        try
        {
            *value = detach(this->shim().Timestamp());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_To(abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            *value = detach(this->shim().To());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Body(abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            *value = detach(this->shim().Body());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Channel(int32_t * value) noexcept override
    {
        try
        {
            *value = detach(this->shim().Channel());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_GeographicalScope(Windows::Devices::Sms::SmsGeographicalScope * value) noexcept override
    {
        try
        {
            *value = detach(this->shim().GeographicalScope());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_MessageCode(int32_t * value) noexcept override
    {
        try
        {
            *value = detach(this->shim().MessageCode());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_UpdateNumber(int32_t * value) noexcept override
    {
        try
        {
            *value = detach(this->shim().UpdateNumber());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_BroadcastType(Windows::Devices::Sms::SmsBroadcastType * value) noexcept override
    {
        try
        {
            *value = detach(this->shim().BroadcastType());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_IsEmergencyAlert(bool * value) noexcept override
    {
        try
        {
            *value = detach(this->shim().IsEmergencyAlert());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_IsUserPopupRequested(bool * value) noexcept override
    {
        try
        {
            *value = detach(this->shim().IsUserPopupRequested());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Devices::Sms::ISmsDevice2> : produce_base<D, Windows::Devices::Sms::ISmsDevice2>
{
    HRESULT __stdcall get_SmscAddress(abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            *value = detach(this->shim().SmscAddress());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_SmscAddress(abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            this->shim().SmscAddress(*reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_DeviceId(abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            *value = detach(this->shim().DeviceId());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ParentDeviceId(abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            *value = detach(this->shim().ParentDeviceId());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_AccountPhoneNumber(abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            *value = detach(this->shim().AccountPhoneNumber());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_CellularClass(Windows::Devices::Sms::CellularClass * value) noexcept override
    {
        try
        {
            *value = detach(this->shim().CellularClass());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_DeviceStatus(Windows::Devices::Sms::SmsDeviceStatus * value) noexcept override
    {
        try
        {
            *value = detach(this->shim().DeviceStatus());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_CalculateLength(abi_arg_in<Windows::Devices::Sms::ISmsMessageBase> message, abi_arg_out<Windows::Devices::Sms::SmsEncodedLength> value) noexcept override
    {
        try
        {
            *value = detach(this->shim().CalculateLength(*reinterpret_cast<const Windows::Devices::Sms::ISmsMessageBase *>(&message)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_SendMessageAndGetResultAsync(abi_arg_in<Windows::Devices::Sms::ISmsMessageBase> message, abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Devices::Sms::SmsSendMessageResult>> asyncInfo) noexcept override
    {
        try
        {
            *asyncInfo = detach(this->shim().SendMessageAndGetResultAsync(*reinterpret_cast<const Windows::Devices::Sms::ISmsMessageBase *>(&message)));
            return S_OK;
        }
        catch (...)
        {
            *asyncInfo = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_DeviceStatusChanged(abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::Devices::Sms::SmsDevice2, Windows::IInspectable>> eventHandler, event_token * eventCookie) noexcept override
    {
        try
        {
            *eventCookie = detach(this->shim().DeviceStatusChanged(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::Devices::Sms::SmsDevice2, Windows::IInspectable> *>(&eventHandler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_DeviceStatusChanged(event_token eventCookie) noexcept override
    {
        try
        {
            this->shim().DeviceStatusChanged(eventCookie);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Devices::Sms::ISmsDevice2Statics> : produce_base<D, Windows::Devices::Sms::ISmsDevice2Statics>
{
    HRESULT __stdcall abi_GetDeviceSelector(abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            *value = detach(this->shim().GetDeviceSelector());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_FromId(abi_arg_in<hstring> deviceId, abi_arg_out<Windows::Devices::Sms::ISmsDevice2> value) noexcept override
    {
        try
        {
            *value = detach(this->shim().FromId(*reinterpret_cast<const hstring *>(&deviceId)));
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetDefault(abi_arg_out<Windows::Devices::Sms::ISmsDevice2> value) noexcept override
    {
        try
        {
            *value = detach(this->shim().GetDefault());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_FromParentId(abi_arg_in<hstring> parentDeviceId, abi_arg_out<Windows::Devices::Sms::ISmsDevice2> value) noexcept override
    {
        try
        {
            *value = detach(this->shim().FromParentId(*reinterpret_cast<const hstring *>(&parentDeviceId)));
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Devices::Sms::ISmsFilterRule> : produce_base<D, Windows::Devices::Sms::ISmsFilterRule>
{
    HRESULT __stdcall get_MessageType(Windows::Devices::Sms::SmsMessageType * value) noexcept override
    {
        try
        {
            *value = detach(this->shim().MessageType());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ImsiPrefixes(abi_arg_out<Windows::Foundation::Collections::IVector<hstring>> value) noexcept override
    {
        try
        {
            *value = detach(this->shim().ImsiPrefixes());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_DeviceIds(abi_arg_out<Windows::Foundation::Collections::IVector<hstring>> value) noexcept override
    {
        try
        {
            *value = detach(this->shim().DeviceIds());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_SenderNumbers(abi_arg_out<Windows::Foundation::Collections::IVector<hstring>> value) noexcept override
    {
        try
        {
            *value = detach(this->shim().SenderNumbers());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_TextMessagePrefixes(abi_arg_out<Windows::Foundation::Collections::IVector<hstring>> value) noexcept override
    {
        try
        {
            *value = detach(this->shim().TextMessagePrefixes());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_PortNumbers(abi_arg_out<Windows::Foundation::Collections::IVector<int32_t>> value) noexcept override
    {
        try
        {
            *value = detach(this->shim().PortNumbers());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_CellularClass(Windows::Devices::Sms::CellularClass * value) noexcept override
    {
        try
        {
            *value = detach(this->shim().CellularClass());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_CellularClass(Windows::Devices::Sms::CellularClass value) noexcept override
    {
        try
        {
            this->shim().CellularClass(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ProtocolIds(abi_arg_out<Windows::Foundation::Collections::IVector<int32_t>> value) noexcept override
    {
        try
        {
            *value = detach(this->shim().ProtocolIds());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_TeleserviceIds(abi_arg_out<Windows::Foundation::Collections::IVector<int32_t>> value) noexcept override
    {
        try
        {
            *value = detach(this->shim().TeleserviceIds());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_WapApplicationIds(abi_arg_out<Windows::Foundation::Collections::IVector<hstring>> value) noexcept override
    {
        try
        {
            *value = detach(this->shim().WapApplicationIds());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_WapContentTypes(abi_arg_out<Windows::Foundation::Collections::IVector<hstring>> value) noexcept override
    {
        try
        {
            *value = detach(this->shim().WapContentTypes());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_BroadcastTypes(abi_arg_out<Windows::Foundation::Collections::IVector<winrt::Windows::Devices::Sms::SmsBroadcastType>> value) noexcept override
    {
        try
        {
            *value = detach(this->shim().BroadcastTypes());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_BroadcastChannels(abi_arg_out<Windows::Foundation::Collections::IVector<int32_t>> value) noexcept override
    {
        try
        {
            *value = detach(this->shim().BroadcastChannels());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Devices::Sms::ISmsFilterRuleFactory> : produce_base<D, Windows::Devices::Sms::ISmsFilterRuleFactory>
{
    HRESULT __stdcall abi_CreateFilterRule(Windows::Devices::Sms::SmsMessageType messageType, abi_arg_out<Windows::Devices::Sms::ISmsFilterRule> value) noexcept override
    {
        try
        {
            *value = detach(this->shim().CreateFilterRule(messageType));
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Devices::Sms::ISmsFilterRules> : produce_base<D, Windows::Devices::Sms::ISmsFilterRules>
{
    HRESULT __stdcall get_ActionType(Windows::Devices::Sms::SmsFilterActionType * value) noexcept override
    {
        try
        {
            *value = detach(this->shim().ActionType());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Rules(abi_arg_out<Windows::Foundation::Collections::IVector<Windows::Devices::Sms::SmsFilterRule>> value) noexcept override
    {
        try
        {
            *value = detach(this->shim().Rules());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Devices::Sms::ISmsFilterRulesFactory> : produce_base<D, Windows::Devices::Sms::ISmsFilterRulesFactory>
{
    HRESULT __stdcall abi_CreateFilterRules(Windows::Devices::Sms::SmsFilterActionType actionType, abi_arg_out<Windows::Devices::Sms::ISmsFilterRules> value) noexcept override
    {
        try
        {
            *value = detach(this->shim().CreateFilterRules(actionType));
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Devices::Sms::ISmsMessageBase> : produce_base<D, Windows::Devices::Sms::ISmsMessageBase>
{
    HRESULT __stdcall get_MessageType(Windows::Devices::Sms::SmsMessageType * value) noexcept override
    {
        try
        {
            *value = detach(this->shim().MessageType());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_DeviceId(abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            *value = detach(this->shim().DeviceId());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_CellularClass(Windows::Devices::Sms::CellularClass * value) noexcept override
    {
        try
        {
            *value = detach(this->shim().CellularClass());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_MessageClass(Windows::Devices::Sms::SmsMessageClass * value) noexcept override
    {
        try
        {
            *value = detach(this->shim().MessageClass());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_SimIccId(abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            *value = detach(this->shim().SimIccId());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Devices::Sms::ISmsMessageReceivedTriggerDetails> : produce_base<D, Windows::Devices::Sms::ISmsMessageReceivedTriggerDetails>
{
    HRESULT __stdcall get_MessageType(Windows::Devices::Sms::SmsMessageType * value) noexcept override
    {
        try
        {
            *value = detach(this->shim().MessageType());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_TextMessage(abi_arg_out<Windows::Devices::Sms::ISmsTextMessage2> value) noexcept override
    {
        try
        {
            *value = detach(this->shim().TextMessage());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_WapMessage(abi_arg_out<Windows::Devices::Sms::ISmsWapMessage> value) noexcept override
    {
        try
        {
            *value = detach(this->shim().WapMessage());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_AppMessage(abi_arg_out<Windows::Devices::Sms::ISmsAppMessage> value) noexcept override
    {
        try
        {
            *value = detach(this->shim().AppMessage());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_BroadcastMessage(abi_arg_out<Windows::Devices::Sms::ISmsBroadcastMessage> value) noexcept override
    {
        try
        {
            *value = detach(this->shim().BroadcastMessage());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_VoicemailMessage(abi_arg_out<Windows::Devices::Sms::ISmsVoicemailMessage> value) noexcept override
    {
        try
        {
            *value = detach(this->shim().VoicemailMessage());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_StatusMessage(abi_arg_out<Windows::Devices::Sms::ISmsStatusMessage> value) noexcept override
    {
        try
        {
            *value = detach(this->shim().StatusMessage());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_Drop() noexcept override
    {
        try
        {
            this->shim().Drop();
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_Accept() noexcept override
    {
        try
        {
            this->shim().Accept();
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Devices::Sms::ISmsMessageRegistration> : produce_base<D, Windows::Devices::Sms::ISmsMessageRegistration>
{
    HRESULT __stdcall get_Id(abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            *value = detach(this->shim().Id());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_Unregister() noexcept override
    {
        try
        {
            this->shim().Unregister();
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_MessageReceived(abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::Devices::Sms::SmsMessageRegistration, Windows::Devices::Sms::SmsMessageReceivedTriggerDetails>> eventHandler, event_token * eventCookie) noexcept override
    {
        try
        {
            *eventCookie = detach(this->shim().MessageReceived(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::Devices::Sms::SmsMessageRegistration, Windows::Devices::Sms::SmsMessageReceivedTriggerDetails> *>(&eventHandler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_MessageReceived(event_token eventCookie) noexcept override
    {
        try
        {
            this->shim().MessageReceived(eventCookie);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Devices::Sms::ISmsMessageRegistrationStatics> : produce_base<D, Windows::Devices::Sms::ISmsMessageRegistrationStatics>
{
    HRESULT __stdcall get_AllRegistrations(abi_arg_out<Windows::Foundation::Collections::IVectorView<Windows::Devices::Sms::SmsMessageRegistration>> value) noexcept override
    {
        try
        {
            *value = detach(this->shim().AllRegistrations());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_Register(abi_arg_in<hstring> id, abi_arg_in<Windows::Devices::Sms::ISmsFilterRules> filterRules, abi_arg_out<Windows::Devices::Sms::ISmsMessageRegistration> value) noexcept override
    {
        try
        {
            *value = detach(this->shim().Register(*reinterpret_cast<const hstring *>(&id), *reinterpret_cast<const Windows::Devices::Sms::SmsFilterRules *>(&filterRules)));
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Devices::Sms::ISmsSendMessageResult> : produce_base<D, Windows::Devices::Sms::ISmsSendMessageResult>
{
    HRESULT __stdcall get_IsSuccessful(bool * value) noexcept override
    {
        try
        {
            *value = detach(this->shim().IsSuccessful());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_MessageReferenceNumbers(abi_arg_out<Windows::Foundation::Collections::IVectorView<int32_t>> value) noexcept override
    {
        try
        {
            *value = detach(this->shim().MessageReferenceNumbers());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_CellularClass(Windows::Devices::Sms::CellularClass * value) noexcept override
    {
        try
        {
            *value = detach(this->shim().CellularClass());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ModemErrorCode(Windows::Devices::Sms::SmsModemErrorCode * value) noexcept override
    {
        try
        {
            *value = detach(this->shim().ModemErrorCode());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_IsErrorTransient(bool * value) noexcept override
    {
        try
        {
            *value = detach(this->shim().IsErrorTransient());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_NetworkCauseCode(int32_t * value) noexcept override
    {
        try
        {
            *value = detach(this->shim().NetworkCauseCode());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_TransportFailureCause(int32_t * value) noexcept override
    {
        try
        {
            *value = detach(this->shim().TransportFailureCause());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Devices::Sms::ISmsStatusMessage> : produce_base<D, Windows::Devices::Sms::ISmsStatusMessage>
{
    HRESULT __stdcall get_To(abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            *value = detach(this->shim().To());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_From(abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            *value = detach(this->shim().From());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Body(abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            *value = detach(this->shim().Body());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Status(int32_t * value) noexcept override
    {
        try
        {
            *value = detach(this->shim().Status());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_MessageReferenceNumber(int32_t * value) noexcept override
    {
        try
        {
            *value = detach(this->shim().MessageReferenceNumber());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ServiceCenterTimestamp(abi_arg_out<Windows::Foundation::DateTime> value) noexcept override
    {
        try
        {
            *value = detach(this->shim().ServiceCenterTimestamp());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_DischargeTime(abi_arg_out<Windows::Foundation::DateTime> value) noexcept override
    {
        try
        {
            *value = detach(this->shim().DischargeTime());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Devices::Sms::ISmsTextMessage2> : produce_base<D, Windows::Devices::Sms::ISmsTextMessage2>
{
    HRESULT __stdcall get_Timestamp(abi_arg_out<Windows::Foundation::DateTime> value) noexcept override
    {
        try
        {
            *value = detach(this->shim().Timestamp());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_To(abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            *value = detach(this->shim().To());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_To(abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            this->shim().To(*reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_From(abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            *value = detach(this->shim().From());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Body(abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            *value = detach(this->shim().Body());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Body(abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            this->shim().Body(*reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Encoding(Windows::Devices::Sms::SmsEncoding * value) noexcept override
    {
        try
        {
            *value = detach(this->shim().Encoding());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Encoding(Windows::Devices::Sms::SmsEncoding value) noexcept override
    {
        try
        {
            this->shim().Encoding(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_CallbackNumber(abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            *value = detach(this->shim().CallbackNumber());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_CallbackNumber(abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            this->shim().CallbackNumber(*reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_IsDeliveryNotificationEnabled(bool * value) noexcept override
    {
        try
        {
            *value = detach(this->shim().IsDeliveryNotificationEnabled());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_IsDeliveryNotificationEnabled(bool value) noexcept override
    {
        try
        {
            this->shim().IsDeliveryNotificationEnabled(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_RetryAttemptCount(int32_t * value) noexcept override
    {
        try
        {
            *value = detach(this->shim().RetryAttemptCount());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_RetryAttemptCount(int32_t value) noexcept override
    {
        try
        {
            this->shim().RetryAttemptCount(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_TeleserviceId(int32_t * value) noexcept override
    {
        try
        {
            *value = detach(this->shim().TeleserviceId());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ProtocolId(int32_t * value) noexcept override
    {
        try
        {
            *value = detach(this->shim().ProtocolId());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Devices::Sms::ISmsVoicemailMessage> : produce_base<D, Windows::Devices::Sms::ISmsVoicemailMessage>
{
    HRESULT __stdcall get_Timestamp(abi_arg_out<Windows::Foundation::DateTime> value) noexcept override
    {
        try
        {
            *value = detach(this->shim().Timestamp());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_To(abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            *value = detach(this->shim().To());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Body(abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            *value = detach(this->shim().Body());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_MessageCount(abi_arg_out<Windows::Foundation::IReference<int32_t>> value) noexcept override
    {
        try
        {
            *value = detach(this->shim().MessageCount());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Devices::Sms::ISmsWapMessage> : produce_base<D, Windows::Devices::Sms::ISmsWapMessage>
{
    HRESULT __stdcall get_Timestamp(abi_arg_out<Windows::Foundation::DateTime> value) noexcept override
    {
        try
        {
            *value = detach(this->shim().Timestamp());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_To(abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            *value = detach(this->shim().To());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_From(abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            *value = detach(this->shim().From());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ApplicationId(abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            *value = detach(this->shim().ApplicationId());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ContentType(abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            *value = detach(this->shim().ContentType());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_BinaryBody(abi_arg_out<Windows::Storage::Streams::IBuffer> value) noexcept override
    {
        try
        {
            *value = detach(this->shim().BinaryBody());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Headers(abi_arg_out<Windows::Foundation::Collections::IMap<hstring, hstring>> value) noexcept override
    {
        try
        {
            *value = detach(this->shim().Headers());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }
};

}

namespace Windows::Devices::Sms {

template <typename D> Windows::Devices::Sms::SmsMessageType impl_ISmsMessageBase<D>::MessageType() const
{
    Windows::Devices::Sms::SmsMessageType value {};
    check_hresult(shim()->get_MessageType(&value));
    return value;
}

template <typename D> hstring impl_ISmsMessageBase<D>::DeviceId() const
{
    hstring value;
    check_hresult(shim()->get_DeviceId(put(value)));
    return value;
}

template <typename D> Windows::Devices::Sms::CellularClass impl_ISmsMessageBase<D>::CellularClass() const
{
    Windows::Devices::Sms::CellularClass value {};
    check_hresult(shim()->get_CellularClass(&value));
    return value;
}

template <typename D> Windows::Devices::Sms::SmsMessageClass impl_ISmsMessageBase<D>::MessageClass() const
{
    Windows::Devices::Sms::SmsMessageClass value {};
    check_hresult(shim()->get_MessageClass(&value));
    return value;
}

template <typename D> hstring impl_ISmsMessageBase<D>::SimIccId() const
{
    hstring value;
    check_hresult(shim()->get_SimIccId(put(value)));
    return value;
}

template <typename D> Windows::Foundation::DateTime impl_ISmsTextMessage2<D>::Timestamp() const
{
    Windows::Foundation::DateTime value {};
    check_hresult(shim()->get_Timestamp(put(value)));
    return value;
}

template <typename D> hstring impl_ISmsTextMessage2<D>::To() const
{
    hstring value;
    check_hresult(shim()->get_To(put(value)));
    return value;
}

template <typename D> void impl_ISmsTextMessage2<D>::To(hstring_ref value) const
{
    check_hresult(shim()->put_To(get(value)));
}

template <typename D> hstring impl_ISmsTextMessage2<D>::From() const
{
    hstring value;
    check_hresult(shim()->get_From(put(value)));
    return value;
}

template <typename D> hstring impl_ISmsTextMessage2<D>::Body() const
{
    hstring value;
    check_hresult(shim()->get_Body(put(value)));
    return value;
}

template <typename D> void impl_ISmsTextMessage2<D>::Body(hstring_ref value) const
{
    check_hresult(shim()->put_Body(get(value)));
}

template <typename D> Windows::Devices::Sms::SmsEncoding impl_ISmsTextMessage2<D>::Encoding() const
{
    Windows::Devices::Sms::SmsEncoding value {};
    check_hresult(shim()->get_Encoding(&value));
    return value;
}

template <typename D> void impl_ISmsTextMessage2<D>::Encoding(Windows::Devices::Sms::SmsEncoding value) const
{
    check_hresult(shim()->put_Encoding(value));
}

template <typename D> hstring impl_ISmsTextMessage2<D>::CallbackNumber() const
{
    hstring value;
    check_hresult(shim()->get_CallbackNumber(put(value)));
    return value;
}

template <typename D> void impl_ISmsTextMessage2<D>::CallbackNumber(hstring_ref value) const
{
    check_hresult(shim()->put_CallbackNumber(get(value)));
}

template <typename D> bool impl_ISmsTextMessage2<D>::IsDeliveryNotificationEnabled() const
{
    bool value {};
    check_hresult(shim()->get_IsDeliveryNotificationEnabled(&value));
    return value;
}

template <typename D> void impl_ISmsTextMessage2<D>::IsDeliveryNotificationEnabled(bool value) const
{
    check_hresult(shim()->put_IsDeliveryNotificationEnabled(value));
}

template <typename D> int32_t impl_ISmsTextMessage2<D>::RetryAttemptCount() const
{
    int32_t value {};
    check_hresult(shim()->get_RetryAttemptCount(&value));
    return value;
}

template <typename D> void impl_ISmsTextMessage2<D>::RetryAttemptCount(int32_t value) const
{
    check_hresult(shim()->put_RetryAttemptCount(value));
}

template <typename D> int32_t impl_ISmsTextMessage2<D>::TeleserviceId() const
{
    int32_t value {};
    check_hresult(shim()->get_TeleserviceId(&value));
    return value;
}

template <typename D> int32_t impl_ISmsTextMessage2<D>::ProtocolId() const
{
    int32_t value {};
    check_hresult(shim()->get_ProtocolId(&value));
    return value;
}

template <typename D> Windows::Foundation::DateTime impl_ISmsWapMessage<D>::Timestamp() const
{
    Windows::Foundation::DateTime value {};
    check_hresult(shim()->get_Timestamp(put(value)));
    return value;
}

template <typename D> hstring impl_ISmsWapMessage<D>::To() const
{
    hstring value;
    check_hresult(shim()->get_To(put(value)));
    return value;
}

template <typename D> hstring impl_ISmsWapMessage<D>::From() const
{
    hstring value;
    check_hresult(shim()->get_From(put(value)));
    return value;
}

template <typename D> hstring impl_ISmsWapMessage<D>::ApplicationId() const
{
    hstring value;
    check_hresult(shim()->get_ApplicationId(put(value)));
    return value;
}

template <typename D> hstring impl_ISmsWapMessage<D>::ContentType() const
{
    hstring value;
    check_hresult(shim()->get_ContentType(put(value)));
    return value;
}

template <typename D> Windows::Storage::Streams::IBuffer impl_ISmsWapMessage<D>::BinaryBody() const
{
    Windows::Storage::Streams::IBuffer value;
    check_hresult(shim()->get_BinaryBody(put(value)));
    return value;
}

template <typename D> Windows::Foundation::Collections::IMap<hstring, hstring> impl_ISmsWapMessage<D>::Headers() const
{
    Windows::Foundation::Collections::IMap<hstring, hstring> value;
    check_hresult(shim()->get_Headers(put(value)));
    return value;
}

template <typename D> Windows::Foundation::DateTime impl_ISmsAppMessage<D>::Timestamp() const
{
    Windows::Foundation::DateTime value {};
    check_hresult(shim()->get_Timestamp(put(value)));
    return value;
}

template <typename D> hstring impl_ISmsAppMessage<D>::To() const
{
    hstring value;
    check_hresult(shim()->get_To(put(value)));
    return value;
}

template <typename D> void impl_ISmsAppMessage<D>::To(hstring_ref value) const
{
    check_hresult(shim()->put_To(get(value)));
}

template <typename D> hstring impl_ISmsAppMessage<D>::From() const
{
    hstring value;
    check_hresult(shim()->get_From(put(value)));
    return value;
}

template <typename D> hstring impl_ISmsAppMessage<D>::Body() const
{
    hstring value;
    check_hresult(shim()->get_Body(put(value)));
    return value;
}

template <typename D> void impl_ISmsAppMessage<D>::Body(hstring_ref value) const
{
    check_hresult(shim()->put_Body(get(value)));
}

template <typename D> hstring impl_ISmsAppMessage<D>::CallbackNumber() const
{
    hstring value;
    check_hresult(shim()->get_CallbackNumber(put(value)));
    return value;
}

template <typename D> void impl_ISmsAppMessage<D>::CallbackNumber(hstring_ref value) const
{
    check_hresult(shim()->put_CallbackNumber(get(value)));
}

template <typename D> bool impl_ISmsAppMessage<D>::IsDeliveryNotificationEnabled() const
{
    bool value {};
    check_hresult(shim()->get_IsDeliveryNotificationEnabled(&value));
    return value;
}

template <typename D> void impl_ISmsAppMessage<D>::IsDeliveryNotificationEnabled(bool value) const
{
    check_hresult(shim()->put_IsDeliveryNotificationEnabled(value));
}

template <typename D> int32_t impl_ISmsAppMessage<D>::RetryAttemptCount() const
{
    int32_t value {};
    check_hresult(shim()->get_RetryAttemptCount(&value));
    return value;
}

template <typename D> void impl_ISmsAppMessage<D>::RetryAttemptCount(int32_t value) const
{
    check_hresult(shim()->put_RetryAttemptCount(value));
}

template <typename D> Windows::Devices::Sms::SmsEncoding impl_ISmsAppMessage<D>::Encoding() const
{
    Windows::Devices::Sms::SmsEncoding value {};
    check_hresult(shim()->get_Encoding(&value));
    return value;
}

template <typename D> void impl_ISmsAppMessage<D>::Encoding(Windows::Devices::Sms::SmsEncoding value) const
{
    check_hresult(shim()->put_Encoding(value));
}

template <typename D> int32_t impl_ISmsAppMessage<D>::PortNumber() const
{
    int32_t value {};
    check_hresult(shim()->get_PortNumber(&value));
    return value;
}

template <typename D> void impl_ISmsAppMessage<D>::PortNumber(int32_t value) const
{
    check_hresult(shim()->put_PortNumber(value));
}

template <typename D> int32_t impl_ISmsAppMessage<D>::TeleserviceId() const
{
    int32_t value {};
    check_hresult(shim()->get_TeleserviceId(&value));
    return value;
}

template <typename D> void impl_ISmsAppMessage<D>::TeleserviceId(int32_t value) const
{
    check_hresult(shim()->put_TeleserviceId(value));
}

template <typename D> int32_t impl_ISmsAppMessage<D>::ProtocolId() const
{
    int32_t value {};
    check_hresult(shim()->get_ProtocolId(&value));
    return value;
}

template <typename D> void impl_ISmsAppMessage<D>::ProtocolId(int32_t value) const
{
    check_hresult(shim()->put_ProtocolId(value));
}

template <typename D> Windows::Storage::Streams::IBuffer impl_ISmsAppMessage<D>::BinaryBody() const
{
    Windows::Storage::Streams::IBuffer value;
    check_hresult(shim()->get_BinaryBody(put(value)));
    return value;
}

template <typename D> void impl_ISmsAppMessage<D>::BinaryBody(const Windows::Storage::Streams::IBuffer & value) const
{
    check_hresult(shim()->put_BinaryBody(get(value)));
}

template <typename D> Windows::Foundation::DateTime impl_ISmsBroadcastMessage<D>::Timestamp() const
{
    Windows::Foundation::DateTime value {};
    check_hresult(shim()->get_Timestamp(put(value)));
    return value;
}

template <typename D> hstring impl_ISmsBroadcastMessage<D>::To() const
{
    hstring value;
    check_hresult(shim()->get_To(put(value)));
    return value;
}

template <typename D> hstring impl_ISmsBroadcastMessage<D>::Body() const
{
    hstring value;
    check_hresult(shim()->get_Body(put(value)));
    return value;
}

template <typename D> int32_t impl_ISmsBroadcastMessage<D>::Channel() const
{
    int32_t value {};
    check_hresult(shim()->get_Channel(&value));
    return value;
}

template <typename D> Windows::Devices::Sms::SmsGeographicalScope impl_ISmsBroadcastMessage<D>::GeographicalScope() const
{
    Windows::Devices::Sms::SmsGeographicalScope value {};
    check_hresult(shim()->get_GeographicalScope(&value));
    return value;
}

template <typename D> int32_t impl_ISmsBroadcastMessage<D>::MessageCode() const
{
    int32_t value {};
    check_hresult(shim()->get_MessageCode(&value));
    return value;
}

template <typename D> int32_t impl_ISmsBroadcastMessage<D>::UpdateNumber() const
{
    int32_t value {};
    check_hresult(shim()->get_UpdateNumber(&value));
    return value;
}

template <typename D> Windows::Devices::Sms::SmsBroadcastType impl_ISmsBroadcastMessage<D>::BroadcastType() const
{
    Windows::Devices::Sms::SmsBroadcastType value {};
    check_hresult(shim()->get_BroadcastType(&value));
    return value;
}

template <typename D> bool impl_ISmsBroadcastMessage<D>::IsEmergencyAlert() const
{
    bool value {};
    check_hresult(shim()->get_IsEmergencyAlert(&value));
    return value;
}

template <typename D> bool impl_ISmsBroadcastMessage<D>::IsUserPopupRequested() const
{
    bool value {};
    check_hresult(shim()->get_IsUserPopupRequested(&value));
    return value;
}

template <typename D> Windows::Foundation::DateTime impl_ISmsVoicemailMessage<D>::Timestamp() const
{
    Windows::Foundation::DateTime value {};
    check_hresult(shim()->get_Timestamp(put(value)));
    return value;
}

template <typename D> hstring impl_ISmsVoicemailMessage<D>::To() const
{
    hstring value;
    check_hresult(shim()->get_To(put(value)));
    return value;
}

template <typename D> hstring impl_ISmsVoicemailMessage<D>::Body() const
{
    hstring value;
    check_hresult(shim()->get_Body(put(value)));
    return value;
}

template <typename D> Windows::Foundation::IReference<int32_t> impl_ISmsVoicemailMessage<D>::MessageCount() const
{
    Windows::Foundation::IReference<int32_t> value;
    check_hresult(shim()->get_MessageCount(put(value)));
    return value;
}

template <typename D> hstring impl_ISmsStatusMessage<D>::To() const
{
    hstring value;
    check_hresult(shim()->get_To(put(value)));
    return value;
}

template <typename D> hstring impl_ISmsStatusMessage<D>::From() const
{
    hstring value;
    check_hresult(shim()->get_From(put(value)));
    return value;
}

template <typename D> hstring impl_ISmsStatusMessage<D>::Body() const
{
    hstring value;
    check_hresult(shim()->get_Body(put(value)));
    return value;
}

template <typename D> int32_t impl_ISmsStatusMessage<D>::Status() const
{
    int32_t value {};
    check_hresult(shim()->get_Status(&value));
    return value;
}

template <typename D> int32_t impl_ISmsStatusMessage<D>::MessageReferenceNumber() const
{
    int32_t value {};
    check_hresult(shim()->get_MessageReferenceNumber(&value));
    return value;
}

template <typename D> Windows::Foundation::DateTime impl_ISmsStatusMessage<D>::ServiceCenterTimestamp() const
{
    Windows::Foundation::DateTime value {};
    check_hresult(shim()->get_ServiceCenterTimestamp(put(value)));
    return value;
}

template <typename D> Windows::Foundation::DateTime impl_ISmsStatusMessage<D>::DischargeTime() const
{
    Windows::Foundation::DateTime value {};
    check_hresult(shim()->get_DischargeTime(put(value)));
    return value;
}

template <typename D> bool impl_ISmsSendMessageResult<D>::IsSuccessful() const
{
    bool value {};
    check_hresult(shim()->get_IsSuccessful(&value));
    return value;
}

template <typename D> Windows::Foundation::Collections::IVectorView<int32_t> impl_ISmsSendMessageResult<D>::MessageReferenceNumbers() const
{
    Windows::Foundation::Collections::IVectorView<int32_t> value;
    check_hresult(shim()->get_MessageReferenceNumbers(put(value)));
    return value;
}

template <typename D> Windows::Devices::Sms::CellularClass impl_ISmsSendMessageResult<D>::CellularClass() const
{
    Windows::Devices::Sms::CellularClass value {};
    check_hresult(shim()->get_CellularClass(&value));
    return value;
}

template <typename D> Windows::Devices::Sms::SmsModemErrorCode impl_ISmsSendMessageResult<D>::ModemErrorCode() const
{
    Windows::Devices::Sms::SmsModemErrorCode value {};
    check_hresult(shim()->get_ModemErrorCode(&value));
    return value;
}

template <typename D> bool impl_ISmsSendMessageResult<D>::IsErrorTransient() const
{
    bool value {};
    check_hresult(shim()->get_IsErrorTransient(&value));
    return value;
}

template <typename D> int32_t impl_ISmsSendMessageResult<D>::NetworkCauseCode() const
{
    int32_t value {};
    check_hresult(shim()->get_NetworkCauseCode(&value));
    return value;
}

template <typename D> int32_t impl_ISmsSendMessageResult<D>::TransportFailureCause() const
{
    int32_t value {};
    check_hresult(shim()->get_TransportFailureCause(&value));
    return value;
}

template <typename D> hstring impl_ISmsDevice2Statics<D>::GetDeviceSelector() const
{
    hstring value;
    check_hresult(shim()->abi_GetDeviceSelector(put(value)));
    return value;
}

template <typename D> Windows::Devices::Sms::SmsDevice2 impl_ISmsDevice2Statics<D>::FromId(hstring_ref deviceId) const
{
    Windows::Devices::Sms::SmsDevice2 value { nullptr };
    check_hresult(shim()->abi_FromId(get(deviceId), put(value)));
    return value;
}

template <typename D> Windows::Devices::Sms::SmsDevice2 impl_ISmsDevice2Statics<D>::GetDefault() const
{
    Windows::Devices::Sms::SmsDevice2 value { nullptr };
    check_hresult(shim()->abi_GetDefault(put(value)));
    return value;
}

template <typename D> Windows::Devices::Sms::SmsDevice2 impl_ISmsDevice2Statics<D>::FromParentId(hstring_ref parentDeviceId) const
{
    Windows::Devices::Sms::SmsDevice2 value { nullptr };
    check_hresult(shim()->abi_FromParentId(get(parentDeviceId), put(value)));
    return value;
}

template <typename D> hstring impl_ISmsDevice2<D>::SmscAddress() const
{
    hstring value;
    check_hresult(shim()->get_SmscAddress(put(value)));
    return value;
}

template <typename D> void impl_ISmsDevice2<D>::SmscAddress(hstring_ref value) const
{
    check_hresult(shim()->put_SmscAddress(get(value)));
}

template <typename D> hstring impl_ISmsDevice2<D>::DeviceId() const
{
    hstring value;
    check_hresult(shim()->get_DeviceId(put(value)));
    return value;
}

template <typename D> hstring impl_ISmsDevice2<D>::ParentDeviceId() const
{
    hstring value;
    check_hresult(shim()->get_ParentDeviceId(put(value)));
    return value;
}

template <typename D> hstring impl_ISmsDevice2<D>::AccountPhoneNumber() const
{
    hstring value;
    check_hresult(shim()->get_AccountPhoneNumber(put(value)));
    return value;
}

template <typename D> Windows::Devices::Sms::CellularClass impl_ISmsDevice2<D>::CellularClass() const
{
    Windows::Devices::Sms::CellularClass value {};
    check_hresult(shim()->get_CellularClass(&value));
    return value;
}

template <typename D> Windows::Devices::Sms::SmsDeviceStatus impl_ISmsDevice2<D>::DeviceStatus() const
{
    Windows::Devices::Sms::SmsDeviceStatus value {};
    check_hresult(shim()->get_DeviceStatus(&value));
    return value;
}

template <typename D> Windows::Devices::Sms::SmsEncodedLength impl_ISmsDevice2<D>::CalculateLength(const Windows::Devices::Sms::ISmsMessageBase & message) const
{
    Windows::Devices::Sms::SmsEncodedLength value {};
    check_hresult(shim()->abi_CalculateLength(get(message), put(value)));
    return value;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Devices::Sms::SmsSendMessageResult> impl_ISmsDevice2<D>::SendMessageAndGetResultAsync(const Windows::Devices::Sms::ISmsMessageBase & message) const
{
    Windows::Foundation::IAsyncOperation<Windows::Devices::Sms::SmsSendMessageResult> asyncInfo;
    check_hresult(shim()->abi_SendMessageAndGetResultAsync(get(message), put(asyncInfo)));
    return asyncInfo;
}

template <typename D> event_token impl_ISmsDevice2<D>::DeviceStatusChanged(const Windows::Foundation::TypedEventHandler<Windows::Devices::Sms::SmsDevice2, Windows::IInspectable> & eventHandler) const
{
    event_token eventCookie {};
    check_hresult(shim()->add_DeviceStatusChanged(get(eventHandler), &eventCookie));
    return eventCookie;
}

template <typename D> event_revoker<ISmsDevice2> impl_ISmsDevice2<D>::DeviceStatusChanged(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Devices::Sms::SmsDevice2, Windows::IInspectable> & eventHandler) const
{
    return impl::make_event_revoker<D, ISmsDevice2>(this, &ABI::Windows::Devices::Sms::ISmsDevice2::remove_DeviceStatusChanged, DeviceStatusChanged(eventHandler));
}

template <typename D> void impl_ISmsDevice2<D>::DeviceStatusChanged(event_token eventCookie) const
{
    check_hresult(shim()->remove_DeviceStatusChanged(eventCookie));
}

template <typename D> Windows::Devices::Sms::SmsMessageType impl_ISmsMessageReceivedTriggerDetails<D>::MessageType() const
{
    Windows::Devices::Sms::SmsMessageType value {};
    check_hresult(shim()->get_MessageType(&value));
    return value;
}

template <typename D> Windows::Devices::Sms::SmsTextMessage2 impl_ISmsMessageReceivedTriggerDetails<D>::TextMessage() const
{
    Windows::Devices::Sms::SmsTextMessage2 value { nullptr };
    check_hresult(shim()->get_TextMessage(put(value)));
    return value;
}

template <typename D> Windows::Devices::Sms::SmsWapMessage impl_ISmsMessageReceivedTriggerDetails<D>::WapMessage() const
{
    Windows::Devices::Sms::SmsWapMessage value { nullptr };
    check_hresult(shim()->get_WapMessage(put(value)));
    return value;
}

template <typename D> Windows::Devices::Sms::SmsAppMessage impl_ISmsMessageReceivedTriggerDetails<D>::AppMessage() const
{
    Windows::Devices::Sms::SmsAppMessage value { nullptr };
    check_hresult(shim()->get_AppMessage(put(value)));
    return value;
}

template <typename D> Windows::Devices::Sms::SmsBroadcastMessage impl_ISmsMessageReceivedTriggerDetails<D>::BroadcastMessage() const
{
    Windows::Devices::Sms::SmsBroadcastMessage value { nullptr };
    check_hresult(shim()->get_BroadcastMessage(put(value)));
    return value;
}

template <typename D> Windows::Devices::Sms::SmsVoicemailMessage impl_ISmsMessageReceivedTriggerDetails<D>::VoicemailMessage() const
{
    Windows::Devices::Sms::SmsVoicemailMessage value { nullptr };
    check_hresult(shim()->get_VoicemailMessage(put(value)));
    return value;
}

template <typename D> Windows::Devices::Sms::SmsStatusMessage impl_ISmsMessageReceivedTriggerDetails<D>::StatusMessage() const
{
    Windows::Devices::Sms::SmsStatusMessage value { nullptr };
    check_hresult(shim()->get_StatusMessage(put(value)));
    return value;
}

template <typename D> void impl_ISmsMessageReceivedTriggerDetails<D>::Drop() const
{
    check_hresult(shim()->abi_Drop());
}

template <typename D> void impl_ISmsMessageReceivedTriggerDetails<D>::Accept() const
{
    check_hresult(shim()->abi_Accept());
}

template <typename D> Windows::Devices::Sms::SmsMessageType impl_ISmsFilterRule<D>::MessageType() const
{
    Windows::Devices::Sms::SmsMessageType value {};
    check_hresult(shim()->get_MessageType(&value));
    return value;
}

template <typename D> Windows::Foundation::Collections::IVector<hstring> impl_ISmsFilterRule<D>::ImsiPrefixes() const
{
    Windows::Foundation::Collections::IVector<hstring> value;
    check_hresult(shim()->get_ImsiPrefixes(put(value)));
    return value;
}

template <typename D> Windows::Foundation::Collections::IVector<hstring> impl_ISmsFilterRule<D>::DeviceIds() const
{
    Windows::Foundation::Collections::IVector<hstring> value;
    check_hresult(shim()->get_DeviceIds(put(value)));
    return value;
}

template <typename D> Windows::Foundation::Collections::IVector<hstring> impl_ISmsFilterRule<D>::SenderNumbers() const
{
    Windows::Foundation::Collections::IVector<hstring> value;
    check_hresult(shim()->get_SenderNumbers(put(value)));
    return value;
}

template <typename D> Windows::Foundation::Collections::IVector<hstring> impl_ISmsFilterRule<D>::TextMessagePrefixes() const
{
    Windows::Foundation::Collections::IVector<hstring> value;
    check_hresult(shim()->get_TextMessagePrefixes(put(value)));
    return value;
}

template <typename D> Windows::Foundation::Collections::IVector<int32_t> impl_ISmsFilterRule<D>::PortNumbers() const
{
    Windows::Foundation::Collections::IVector<int32_t> value;
    check_hresult(shim()->get_PortNumbers(put(value)));
    return value;
}

template <typename D> Windows::Devices::Sms::CellularClass impl_ISmsFilterRule<D>::CellularClass() const
{
    Windows::Devices::Sms::CellularClass value {};
    check_hresult(shim()->get_CellularClass(&value));
    return value;
}

template <typename D> void impl_ISmsFilterRule<D>::CellularClass(Windows::Devices::Sms::CellularClass value) const
{
    check_hresult(shim()->put_CellularClass(value));
}

template <typename D> Windows::Foundation::Collections::IVector<int32_t> impl_ISmsFilterRule<D>::ProtocolIds() const
{
    Windows::Foundation::Collections::IVector<int32_t> value;
    check_hresult(shim()->get_ProtocolIds(put(value)));
    return value;
}

template <typename D> Windows::Foundation::Collections::IVector<int32_t> impl_ISmsFilterRule<D>::TeleserviceIds() const
{
    Windows::Foundation::Collections::IVector<int32_t> value;
    check_hresult(shim()->get_TeleserviceIds(put(value)));
    return value;
}

template <typename D> Windows::Foundation::Collections::IVector<hstring> impl_ISmsFilterRule<D>::WapApplicationIds() const
{
    Windows::Foundation::Collections::IVector<hstring> value;
    check_hresult(shim()->get_WapApplicationIds(put(value)));
    return value;
}

template <typename D> Windows::Foundation::Collections::IVector<hstring> impl_ISmsFilterRule<D>::WapContentTypes() const
{
    Windows::Foundation::Collections::IVector<hstring> value;
    check_hresult(shim()->get_WapContentTypes(put(value)));
    return value;
}

template <typename D> Windows::Foundation::Collections::IVector<winrt::Windows::Devices::Sms::SmsBroadcastType> impl_ISmsFilterRule<D>::BroadcastTypes() const
{
    Windows::Foundation::Collections::IVector<winrt::Windows::Devices::Sms::SmsBroadcastType> value;
    check_hresult(shim()->get_BroadcastTypes(put(value)));
    return value;
}

template <typename D> Windows::Foundation::Collections::IVector<int32_t> impl_ISmsFilterRule<D>::BroadcastChannels() const
{
    Windows::Foundation::Collections::IVector<int32_t> value;
    check_hresult(shim()->get_BroadcastChannels(put(value)));
    return value;
}

template <typename D> Windows::Devices::Sms::SmsFilterRule impl_ISmsFilterRuleFactory<D>::CreateFilterRule(Windows::Devices::Sms::SmsMessageType messageType) const
{
    Windows::Devices::Sms::SmsFilterRule value { nullptr };
    check_hresult(shim()->abi_CreateFilterRule(messageType, put(value)));
    return value;
}

template <typename D> Windows::Devices::Sms::SmsFilterActionType impl_ISmsFilterRules<D>::ActionType() const
{
    Windows::Devices::Sms::SmsFilterActionType value {};
    check_hresult(shim()->get_ActionType(&value));
    return value;
}

template <typename D> Windows::Foundation::Collections::IVector<Windows::Devices::Sms::SmsFilterRule> impl_ISmsFilterRules<D>::Rules() const
{
    Windows::Foundation::Collections::IVector<Windows::Devices::Sms::SmsFilterRule> value;
    check_hresult(shim()->get_Rules(put(value)));
    return value;
}

template <typename D> Windows::Devices::Sms::SmsFilterRules impl_ISmsFilterRulesFactory<D>::CreateFilterRules(Windows::Devices::Sms::SmsFilterActionType actionType) const
{
    Windows::Devices::Sms::SmsFilterRules value { nullptr };
    check_hresult(shim()->abi_CreateFilterRules(actionType, put(value)));
    return value;
}

template <typename D> Windows::Foundation::Collections::IVectorView<Windows::Devices::Sms::SmsMessageRegistration> impl_ISmsMessageRegistrationStatics<D>::AllRegistrations() const
{
    Windows::Foundation::Collections::IVectorView<Windows::Devices::Sms::SmsMessageRegistration> value;
    check_hresult(shim()->get_AllRegistrations(put(value)));
    return value;
}

template <typename D> Windows::Devices::Sms::SmsMessageRegistration impl_ISmsMessageRegistrationStatics<D>::Register(hstring_ref id, const Windows::Devices::Sms::SmsFilterRules & filterRules) const
{
    Windows::Devices::Sms::SmsMessageRegistration value { nullptr };
    check_hresult(shim()->abi_Register(get(id), get(filterRules), put(value)));
    return value;
}

template <typename D> hstring impl_ISmsMessageRegistration<D>::Id() const
{
    hstring value;
    check_hresult(shim()->get_Id(put(value)));
    return value;
}

template <typename D> void impl_ISmsMessageRegistration<D>::Unregister() const
{
    check_hresult(shim()->abi_Unregister());
}

template <typename D> event_token impl_ISmsMessageRegistration<D>::MessageReceived(const Windows::Foundation::TypedEventHandler<Windows::Devices::Sms::SmsMessageRegistration, Windows::Devices::Sms::SmsMessageReceivedTriggerDetails> & eventHandler) const
{
    event_token eventCookie {};
    check_hresult(shim()->add_MessageReceived(get(eventHandler), &eventCookie));
    return eventCookie;
}

template <typename D> event_revoker<ISmsMessageRegistration> impl_ISmsMessageRegistration<D>::MessageReceived(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Devices::Sms::SmsMessageRegistration, Windows::Devices::Sms::SmsMessageReceivedTriggerDetails> & eventHandler) const
{
    return impl::make_event_revoker<D, ISmsMessageRegistration>(this, &ABI::Windows::Devices::Sms::ISmsMessageRegistration::remove_MessageReceived, MessageReceived(eventHandler));
}

template <typename D> void impl_ISmsMessageRegistration<D>::MessageReceived(event_token eventCookie) const
{
    check_hresult(shim()->remove_MessageReceived(eventCookie));
}

inline SmsAppMessage::SmsAppMessage() :
    SmsAppMessage(activate_instance<SmsAppMessage>())
{}

inline hstring SmsDevice2::GetDeviceSelector()
{
    return get_activation_factory<SmsDevice2, ISmsDevice2Statics>().GetDeviceSelector();
}

inline Windows::Devices::Sms::SmsDevice2 SmsDevice2::FromId(hstring_ref deviceId)
{
    return get_activation_factory<SmsDevice2, ISmsDevice2Statics>().FromId(deviceId);
}

inline Windows::Devices::Sms::SmsDevice2 SmsDevice2::GetDefault()
{
    return get_activation_factory<SmsDevice2, ISmsDevice2Statics>().GetDefault();
}

inline Windows::Devices::Sms::SmsDevice2 SmsDevice2::FromParentId(hstring_ref parentDeviceId)
{
    return get_activation_factory<SmsDevice2, ISmsDevice2Statics>().FromParentId(parentDeviceId);
}

inline SmsFilterRule::SmsFilterRule(Windows::Devices::Sms::SmsMessageType messageType) :
    SmsFilterRule(get_activation_factory<SmsFilterRule, ISmsFilterRuleFactory>().CreateFilterRule(messageType))
{}

inline SmsFilterRules::SmsFilterRules(Windows::Devices::Sms::SmsFilterActionType actionType) :
    SmsFilterRules(get_activation_factory<SmsFilterRules, ISmsFilterRulesFactory>().CreateFilterRules(actionType))
{}

inline Windows::Foundation::Collections::IVectorView<Windows::Devices::Sms::SmsMessageRegistration> SmsMessageRegistration::AllRegistrations()
{
    return get_activation_factory<SmsMessageRegistration, ISmsMessageRegistrationStatics>().AllRegistrations();
}

inline Windows::Devices::Sms::SmsMessageRegistration SmsMessageRegistration::Register(hstring_ref id, const Windows::Devices::Sms::SmsFilterRules & filterRules)
{
    return get_activation_factory<SmsMessageRegistration, ISmsMessageRegistrationStatics>().Register(id, filterRules);
}

inline SmsTextMessage2::SmsTextMessage2() :
    SmsTextMessage2(activate_instance<SmsTextMessage2>())
{}

}

}