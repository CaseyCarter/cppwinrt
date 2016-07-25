// C++ for the Windows Runtime v1.29
// Copyright (c) 2016 Microsoft Corporation

#pragma once

#include "..\base.h"
#include "Windows.ApplicationModel.LockScreen.0.h"
#include "Windows.Foundation.0.h"
#include "Windows.Storage.Streams.0.h"
#include "Windows.Foundation.1.h"
#include "Windows.Foundation.Collections.1.h"

WINRT_EXPORT namespace winrt {

namespace ABI::Windows::ApplicationModel::LockScreen {

struct __declspec(uuid("38ee31ad-d94f-4e7c-81fa-4f4436506281")) __declspec(novtable) ILockApplicationHost : Windows::IInspectable
{
    virtual HRESULT __stdcall abi_RequestUnlock() = 0;
    virtual HRESULT __stdcall add_Unlocking(Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::LockScreen::LockApplicationHost, Windows::ApplicationModel::LockScreen::LockScreenUnlockingEventArgs> * handler, event_token * token) = 0;
    virtual HRESULT __stdcall remove_Unlocking(event_token token) = 0;
};

struct __declspec(uuid("f48fab8e-23d7-4e63-96a1-666ff52d3b2c")) __declspec(novtable) ILockApplicationHostStatics : Windows::IInspectable
{
    virtual HRESULT __stdcall abi_GetForCurrentView(Windows::ApplicationModel::LockScreen::ILockApplicationHost ** result) = 0;
};

struct __declspec(uuid("e95105d9-2bff-4db0-9b4f-3824778b9c9a")) __declspec(novtable) ILockScreenBadge : Windows::IInspectable
{
    virtual HRESULT __stdcall get_Logo(Windows::Storage::Streams::IRandomAccessStream ** value) = 0;
    virtual HRESULT __stdcall get_Glyph(Windows::Storage::Streams::IRandomAccessStream ** value) = 0;
    virtual HRESULT __stdcall get_Number(Windows::Foundation::IReference<uint32_t> ** value) = 0;
    virtual HRESULT __stdcall get_AutomationName(hstring * value) = 0;
    virtual HRESULT __stdcall abi_LaunchApp() = 0;
};

struct __declspec(uuid("f59aa65c-9711-4dc9-a630-95b6cb8cdad0")) __declspec(novtable) ILockScreenInfo : Windows::IInspectable
{
    virtual HRESULT __stdcall add_LockScreenImageChanged(Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::LockScreen::LockScreenInfo, Windows::IInspectable> * handler, event_token * token) = 0;
    virtual HRESULT __stdcall remove_LockScreenImageChanged(event_token token) = 0;
    virtual HRESULT __stdcall get_LockScreenImage(Windows::Storage::Streams::IRandomAccessStream ** value) = 0;
    virtual HRESULT __stdcall add_BadgesChanged(Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::LockScreen::LockScreenInfo, Windows::IInspectable> * handler, event_token * token) = 0;
    virtual HRESULT __stdcall remove_BadgesChanged(event_token token) = 0;
    virtual HRESULT __stdcall get_Badges(Windows::Foundation::Collections::IVectorView<Windows::ApplicationModel::LockScreen::LockScreenBadge> ** value) = 0;
    virtual HRESULT __stdcall add_DetailTextChanged(Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::LockScreen::LockScreenInfo, Windows::IInspectable> * handler, event_token * token) = 0;
    virtual HRESULT __stdcall remove_DetailTextChanged(event_token token) = 0;
    virtual HRESULT __stdcall get_DetailText(Windows::Foundation::Collections::IVectorView<hstring> ** value) = 0;
    virtual HRESULT __stdcall add_AlarmIconChanged(Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::LockScreen::LockScreenInfo, Windows::IInspectable> * handler, event_token * token) = 0;
    virtual HRESULT __stdcall remove_AlarmIconChanged(event_token token) = 0;
    virtual HRESULT __stdcall get_AlarmIcon(Windows::Storage::Streams::IRandomAccessStream ** value) = 0;
};

struct __declspec(uuid("7e7d1ad6-5203-43e7-9bd6-7c3947d1e3fe")) __declspec(novtable) ILockScreenUnlockingDeferral : Windows::IInspectable
{
    virtual HRESULT __stdcall abi_Complete() = 0;
};

struct __declspec(uuid("44e6c007-75fb-4abb-9f8b-824748900c71")) __declspec(novtable) ILockScreenUnlockingEventArgs : Windows::IInspectable
{
    virtual HRESULT __stdcall abi_GetDeferral(Windows::ApplicationModel::LockScreen::ILockScreenUnlockingDeferral ** deferral) = 0;
    virtual HRESULT __stdcall get_Deadline(Windows::Foundation::DateTime * value) = 0;
};

}

namespace ABI {

template <> struct traits<Windows::ApplicationModel::LockScreen::LockApplicationHost> { using default_interface = Windows::ApplicationModel::LockScreen::ILockApplicationHost; };
template <> struct traits<Windows::ApplicationModel::LockScreen::LockScreenBadge> { using default_interface = Windows::ApplicationModel::LockScreen::ILockScreenBadge; };
template <> struct traits<Windows::ApplicationModel::LockScreen::LockScreenInfo> { using default_interface = Windows::ApplicationModel::LockScreen::ILockScreenInfo; };
template <> struct traits<Windows::ApplicationModel::LockScreen::LockScreenUnlockingDeferral> { using default_interface = Windows::ApplicationModel::LockScreen::ILockScreenUnlockingDeferral; };
template <> struct traits<Windows::ApplicationModel::LockScreen::LockScreenUnlockingEventArgs> { using default_interface = Windows::ApplicationModel::LockScreen::ILockScreenUnlockingEventArgs; };

}

namespace Windows::ApplicationModel::LockScreen {

template <typename T> class impl_ILockApplicationHost;
template <typename T> class impl_ILockApplicationHostStatics;
template <typename T> class impl_ILockScreenBadge;
template <typename T> class impl_ILockScreenInfo;
template <typename T> class impl_ILockScreenUnlockingDeferral;
template <typename T> class impl_ILockScreenUnlockingEventArgs;

}

namespace impl {

template <> struct traits<Windows::ApplicationModel::LockScreen::ILockApplicationHost>
{
    using abi = ABI::Windows::ApplicationModel::LockScreen::ILockApplicationHost;
    template <typename D> using consume = Windows::ApplicationModel::LockScreen::impl_ILockApplicationHost<D>;
};

template <> struct traits<Windows::ApplicationModel::LockScreen::ILockApplicationHostStatics>
{
    using abi = ABI::Windows::ApplicationModel::LockScreen::ILockApplicationHostStatics;
    template <typename D> using consume = Windows::ApplicationModel::LockScreen::impl_ILockApplicationHostStatics<D>;
};

template <> struct traits<Windows::ApplicationModel::LockScreen::ILockScreenBadge>
{
    using abi = ABI::Windows::ApplicationModel::LockScreen::ILockScreenBadge;
    template <typename D> using consume = Windows::ApplicationModel::LockScreen::impl_ILockScreenBadge<D>;
};

template <> struct traits<Windows::ApplicationModel::LockScreen::ILockScreenInfo>
{
    using abi = ABI::Windows::ApplicationModel::LockScreen::ILockScreenInfo;
    template <typename D> using consume = Windows::ApplicationModel::LockScreen::impl_ILockScreenInfo<D>;
};

template <> struct traits<Windows::ApplicationModel::LockScreen::ILockScreenUnlockingDeferral>
{
    using abi = ABI::Windows::ApplicationModel::LockScreen::ILockScreenUnlockingDeferral;
    template <typename D> using consume = Windows::ApplicationModel::LockScreen::impl_ILockScreenUnlockingDeferral<D>;
};

template <> struct traits<Windows::ApplicationModel::LockScreen::ILockScreenUnlockingEventArgs>
{
    using abi = ABI::Windows::ApplicationModel::LockScreen::ILockScreenUnlockingEventArgs;
    template <typename D> using consume = Windows::ApplicationModel::LockScreen::impl_ILockScreenUnlockingEventArgs<D>;
};

template <> struct traits<Windows::ApplicationModel::LockScreen::LockApplicationHost>
{
    using abi = ABI::Windows::ApplicationModel::LockScreen::LockApplicationHost;
    using default_interface = Windows::ApplicationModel::LockScreen::ILockApplicationHost;
    static constexpr const wchar_t * name() noexcept { return L"Windows.ApplicationModel.LockScreen.LockApplicationHost"; }
};

template <> struct traits<Windows::ApplicationModel::LockScreen::LockScreenBadge>
{
    using abi = ABI::Windows::ApplicationModel::LockScreen::LockScreenBadge;
    using default_interface = Windows::ApplicationModel::LockScreen::ILockScreenBadge;
    static constexpr const wchar_t * name() noexcept { return L"Windows.ApplicationModel.LockScreen.LockScreenBadge"; }
};

template <> struct traits<Windows::ApplicationModel::LockScreen::LockScreenInfo>
{
    using abi = ABI::Windows::ApplicationModel::LockScreen::LockScreenInfo;
    using default_interface = Windows::ApplicationModel::LockScreen::ILockScreenInfo;
    static constexpr const wchar_t * name() noexcept { return L"Windows.ApplicationModel.LockScreen.LockScreenInfo"; }
};

template <> struct traits<Windows::ApplicationModel::LockScreen::LockScreenUnlockingDeferral>
{
    using abi = ABI::Windows::ApplicationModel::LockScreen::LockScreenUnlockingDeferral;
    using default_interface = Windows::ApplicationModel::LockScreen::ILockScreenUnlockingDeferral;
    static constexpr const wchar_t * name() noexcept { return L"Windows.ApplicationModel.LockScreen.LockScreenUnlockingDeferral"; }
};

template <> struct traits<Windows::ApplicationModel::LockScreen::LockScreenUnlockingEventArgs>
{
    using abi = ABI::Windows::ApplicationModel::LockScreen::LockScreenUnlockingEventArgs;
    using default_interface = Windows::ApplicationModel::LockScreen::ILockScreenUnlockingEventArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.ApplicationModel.LockScreen.LockScreenUnlockingEventArgs"; }
};

}

}
