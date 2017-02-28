// C++ for the Windows Runtime v1.0.private
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "Windows.Devices.Sms.2.h"

WINRT_EXPORT namespace winrt {

namespace Windows::Devices::Sms {

struct WINRT_EBO SmsAppMessage :
    Windows::Devices::Sms::ISmsAppMessage
{
    SmsAppMessage(std::nullptr_t) noexcept {}
    SmsAppMessage();
};

struct WINRT_EBO SmsBroadcastMessage :
    Windows::Devices::Sms::ISmsBroadcastMessage
{
    SmsBroadcastMessage(std::nullptr_t) noexcept {}
};

struct WINRT_EBO SmsDevice2 :
    Windows::Devices::Sms::ISmsDevice2
{
    SmsDevice2(std::nullptr_t) noexcept {}
    static hstring GetDeviceSelector();
    static Windows::Devices::Sms::SmsDevice2 FromId(hstring_view deviceId);
    static Windows::Devices::Sms::SmsDevice2 GetDefault();
    static Windows::Devices::Sms::SmsDevice2 FromParentId(hstring_view parentDeviceId);
};

struct WINRT_EBO SmsFilterRule :
    Windows::Devices::Sms::ISmsFilterRule
{
    SmsFilterRule(std::nullptr_t) noexcept {}
    SmsFilterRule(Windows::Devices::Sms::SmsMessageType messageType);
};

struct WINRT_EBO SmsFilterRules :
    Windows::Devices::Sms::ISmsFilterRules
{
    SmsFilterRules(std::nullptr_t) noexcept {}
    SmsFilterRules(Windows::Devices::Sms::SmsFilterActionType actionType);
};

struct WINRT_EBO SmsMessageReceivedTriggerDetails :
    Windows::Devices::Sms::ISmsMessageReceivedTriggerDetails
{
    SmsMessageReceivedTriggerDetails(std::nullptr_t) noexcept {}
};

struct WINRT_EBO SmsMessageRegistration :
    Windows::Devices::Sms::ISmsMessageRegistration
{
    SmsMessageRegistration(std::nullptr_t) noexcept {}
    static Windows::Foundation::Collections::IVectorView<Windows::Devices::Sms::SmsMessageRegistration> AllRegistrations();
    static Windows::Devices::Sms::SmsMessageRegistration Register(hstring_view id, const Windows::Devices::Sms::SmsFilterRules & filterRules);
};

struct WINRT_EBO SmsSendMessageResult :
    Windows::Devices::Sms::ISmsSendMessageResult
{
    SmsSendMessageResult(std::nullptr_t) noexcept {}
};

struct WINRT_EBO SmsStatusMessage :
    Windows::Devices::Sms::ISmsStatusMessage
{
    SmsStatusMessage(std::nullptr_t) noexcept {}
};

struct WINRT_EBO SmsTextMessage2 :
    Windows::Devices::Sms::ISmsTextMessage2
{
    SmsTextMessage2(std::nullptr_t) noexcept {}
    SmsTextMessage2();
};

struct WINRT_EBO SmsVoicemailMessage :
    Windows::Devices::Sms::ISmsVoicemailMessage
{
    SmsVoicemailMessage(std::nullptr_t) noexcept {}
};

struct WINRT_EBO SmsWapMessage :
    Windows::Devices::Sms::ISmsWapMessage
{
    SmsWapMessage(std::nullptr_t) noexcept {}
};

}

}
