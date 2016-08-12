// C++ for the Windows Runtime v1.29
// Copyright (c) 2016 Microsoft Corporation

#pragma once

#include "../base.h"
#include "Windows.Networking.PushNotifications.0.h"
#include "Windows.Foundation.0.h"
#include "Windows.System.0.h"
#include "Windows.UI.Notifications.0.h"
#include "Windows.Foundation.1.h"

WINRT_EXPORT namespace winrt {

namespace ABI::Windows::Networking::PushNotifications {

struct __declspec(uuid("2b28102e-ef0b-4f39-9b8a-a3c194de7081")) __declspec(novtable) IPushNotificationChannel : Windows::IInspectable
{
    virtual HRESULT __stdcall get_Uri(hstring * value) = 0;
    virtual HRESULT __stdcall get_ExpirationTime(Windows::Foundation::DateTime * value) = 0;
    virtual HRESULT __stdcall abi_Close() = 0;
    virtual HRESULT __stdcall add_PushNotificationReceived(Windows::Foundation::TypedEventHandler<Windows::Networking::PushNotifications::PushNotificationChannel, Windows::Networking::PushNotifications::PushNotificationReceivedEventArgs> * handler, event_token * token) = 0;
    virtual HRESULT __stdcall remove_PushNotificationReceived(event_token token) = 0;
};

struct __declspec(uuid("a4c45704-1182-42c7-8890-f563c4890dc4")) __declspec(novtable) IPushNotificationChannelManagerForUser : Windows::IInspectable
{
    virtual HRESULT __stdcall abi_CreatePushNotificationChannelForApplicationAsync(Windows::Foundation::IAsyncOperation<Windows::Networking::PushNotifications::PushNotificationChannel> ** operation) = 0;
    virtual HRESULT __stdcall abi_CreatePushNotificationChannelForApplicationAsyncWithId(hstring applicationId, Windows::Foundation::IAsyncOperation<Windows::Networking::PushNotifications::PushNotificationChannel> ** operation) = 0;
    virtual HRESULT __stdcall abi_CreatePushNotificationChannelForSecondaryTileAsync(hstring tileId, Windows::Foundation::IAsyncOperation<Windows::Networking::PushNotifications::PushNotificationChannel> ** operation) = 0;
    virtual HRESULT __stdcall get_User(Windows::System::IUser ** value) = 0;
};

struct __declspec(uuid("8baf9b65-77a1-4588-bd19-861529a9dcf0")) __declspec(novtable) IPushNotificationChannelManagerStatics : Windows::IInspectable
{
    virtual HRESULT __stdcall abi_CreatePushNotificationChannelForApplicationAsync(Windows::Foundation::IAsyncOperation<Windows::Networking::PushNotifications::PushNotificationChannel> ** operation) = 0;
    virtual HRESULT __stdcall abi_CreatePushNotificationChannelForApplicationAsyncWithId(hstring applicationId, Windows::Foundation::IAsyncOperation<Windows::Networking::PushNotifications::PushNotificationChannel> ** operation) = 0;
    virtual HRESULT __stdcall abi_CreatePushNotificationChannelForSecondaryTileAsync(hstring tileId, Windows::Foundation::IAsyncOperation<Windows::Networking::PushNotifications::PushNotificationChannel> ** operation) = 0;
};

struct __declspec(uuid("b444a65d-a7e9-4b28-950e-f375a907f9df")) __declspec(novtable) IPushNotificationChannelManagerStatics2 : Windows::IInspectable
{
    virtual HRESULT __stdcall abi_GetForUser(Windows::System::IUser * user, Windows::Networking::PushNotifications::IPushNotificationChannelManagerForUser ** result) = 0;
};

struct __declspec(uuid("d1065e0c-36cd-484c-b935-0a99b753cf00")) __declspec(novtable) IPushNotificationReceivedEventArgs : Windows::IInspectable
{
    virtual HRESULT __stdcall put_Cancel(bool value) = 0;
    virtual HRESULT __stdcall get_Cancel(bool * value) = 0;
    virtual HRESULT __stdcall get_NotificationType(winrt::Windows::Networking::PushNotifications::PushNotificationType * value) = 0;
    virtual HRESULT __stdcall get_ToastNotification(Windows::UI::Notifications::IToastNotification ** value) = 0;
    virtual HRESULT __stdcall get_TileNotification(Windows::UI::Notifications::ITileNotification ** value) = 0;
    virtual HRESULT __stdcall get_BadgeNotification(Windows::UI::Notifications::IBadgeNotification ** value) = 0;
    virtual HRESULT __stdcall get_RawNotification(Windows::Networking::PushNotifications::IRawNotification ** value) = 0;
};

struct __declspec(uuid("1a227281-3b79-42ac-9963-22ab00d4f0b7")) __declspec(novtable) IRawNotification : Windows::IInspectable
{
    virtual HRESULT __stdcall get_Content(hstring * value) = 0;
};

}

namespace ABI {

template <> struct traits<Windows::Networking::PushNotifications::PushNotificationChannel> { using default_interface = Windows::Networking::PushNotifications::IPushNotificationChannel; };
template <> struct traits<Windows::Networking::PushNotifications::PushNotificationChannelManagerForUser> { using default_interface = Windows::Networking::PushNotifications::IPushNotificationChannelManagerForUser; };
template <> struct traits<Windows::Networking::PushNotifications::PushNotificationReceivedEventArgs> { using default_interface = Windows::Networking::PushNotifications::IPushNotificationReceivedEventArgs; };
template <> struct traits<Windows::Networking::PushNotifications::RawNotification> { using default_interface = Windows::Networking::PushNotifications::IRawNotification; };

}

namespace Windows::Networking::PushNotifications {

template <typename T> class impl_IPushNotificationChannel;
template <typename T> class impl_IPushNotificationChannelManagerForUser;
template <typename T> class impl_IPushNotificationChannelManagerStatics;
template <typename T> class impl_IPushNotificationChannelManagerStatics2;
template <typename T> class impl_IPushNotificationReceivedEventArgs;
template <typename T> class impl_IRawNotification;

}

namespace impl {

template <> struct traits<Windows::Networking::PushNotifications::IPushNotificationChannel>
{
    using abi = ABI::Windows::Networking::PushNotifications::IPushNotificationChannel;
    template <typename D> using consume = Windows::Networking::PushNotifications::impl_IPushNotificationChannel<D>;
};

template <> struct traits<Windows::Networking::PushNotifications::IPushNotificationChannelManagerForUser>
{
    using abi = ABI::Windows::Networking::PushNotifications::IPushNotificationChannelManagerForUser;
    template <typename D> using consume = Windows::Networking::PushNotifications::impl_IPushNotificationChannelManagerForUser<D>;
};

template <> struct traits<Windows::Networking::PushNotifications::IPushNotificationChannelManagerStatics>
{
    using abi = ABI::Windows::Networking::PushNotifications::IPushNotificationChannelManagerStatics;
    template <typename D> using consume = Windows::Networking::PushNotifications::impl_IPushNotificationChannelManagerStatics<D>;
};

template <> struct traits<Windows::Networking::PushNotifications::IPushNotificationChannelManagerStatics2>
{
    using abi = ABI::Windows::Networking::PushNotifications::IPushNotificationChannelManagerStatics2;
    template <typename D> using consume = Windows::Networking::PushNotifications::impl_IPushNotificationChannelManagerStatics2<D>;
};

template <> struct traits<Windows::Networking::PushNotifications::IPushNotificationReceivedEventArgs>
{
    using abi = ABI::Windows::Networking::PushNotifications::IPushNotificationReceivedEventArgs;
    template <typename D> using consume = Windows::Networking::PushNotifications::impl_IPushNotificationReceivedEventArgs<D>;
};

template <> struct traits<Windows::Networking::PushNotifications::IRawNotification>
{
    using abi = ABI::Windows::Networking::PushNotifications::IRawNotification;
    template <typename D> using consume = Windows::Networking::PushNotifications::impl_IRawNotification<D>;
};

template <> struct traits<Windows::Networking::PushNotifications::PushNotificationChannel>
{
    using abi = ABI::Windows::Networking::PushNotifications::PushNotificationChannel;
    using default_interface = Windows::Networking::PushNotifications::IPushNotificationChannel;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Networking.PushNotifications.PushNotificationChannel"; }
};

template <> struct traits<Windows::Networking::PushNotifications::PushNotificationChannelManager>
{
    static constexpr const wchar_t * name() noexcept { return L"Windows.Networking.PushNotifications.PushNotificationChannelManager"; }
};

template <> struct traits<Windows::Networking::PushNotifications::PushNotificationChannelManagerForUser>
{
    using abi = ABI::Windows::Networking::PushNotifications::PushNotificationChannelManagerForUser;
    using default_interface = Windows::Networking::PushNotifications::IPushNotificationChannelManagerForUser;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Networking.PushNotifications.PushNotificationChannelManagerForUser"; }
};

template <> struct traits<Windows::Networking::PushNotifications::PushNotificationReceivedEventArgs>
{
    using abi = ABI::Windows::Networking::PushNotifications::PushNotificationReceivedEventArgs;
    using default_interface = Windows::Networking::PushNotifications::IPushNotificationReceivedEventArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Networking.PushNotifications.PushNotificationReceivedEventArgs"; }
};

template <> struct traits<Windows::Networking::PushNotifications::RawNotification>
{
    using abi = ABI::Windows::Networking::PushNotifications::RawNotification;
    using default_interface = Windows::Networking::PushNotifications::IRawNotification;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Networking.PushNotifications.RawNotification"; }
};

}

}
