// C++ for the Windows Runtime v1.0.private
// Copyright (c) 2016 Microsoft Corporation. All rights reserved.

#pragma once

#include "Windows.UI.ViewManagement.1.h"

WINRT_EXPORT namespace winrt {

namespace ABI::Windows::Foundation {

#ifndef WINRT_GENERIC_cdb5efb3_5788_509d_9be1_71ccb8a3362a
#define WINRT_GENERIC_cdb5efb3_5788_509d_9be1_71ccb8a3362a
template <> struct __declspec(uuid("cdb5efb3-5788-509d-9be1-71ccb8a3362a")) __declspec(novtable) IAsyncOperation<bool> : impl_IAsyncOperation<bool> {};
#endif

#ifndef WINRT_GENERIC_463c606a_8c82_5a29_a2bd_040781f25348
#define WINRT_GENERIC_463c606a_8c82_5a29_a2bd_040781f25348
template <> struct __declspec(uuid("463c606a-8c82-5a29-a2bd-040781f25348")) __declspec(novtable) TypedEventHandler<Windows::UI::ViewManagement::ApplicationView, Windows::UI::ViewManagement::ApplicationViewConsolidatedEventArgs> : impl_TypedEventHandler<Windows::UI::ViewManagement::ApplicationView, Windows::UI::ViewManagement::ApplicationViewConsolidatedEventArgs> {};
#endif

#ifndef WINRT_GENERIC_00c1f983_c836_565c_8bbf_7053055bdb4c
#define WINRT_GENERIC_00c1f983_c836_565c_8bbf_7053055bdb4c
template <> struct __declspec(uuid("00c1f983-c836-565c-8bbf-7053055bdb4c")) __declspec(novtable) TypedEventHandler<Windows::UI::ViewManagement::ApplicationView, Windows::IInspectable> : impl_TypedEventHandler<Windows::UI::ViewManagement::ApplicationView, Windows::IInspectable> {};
#endif

#ifndef WINRT_GENERIC_ab8e5d11_b0c1_5a21_95ae_f16bf3a37624
#define WINRT_GENERIC_ab8e5d11_b0c1_5a21_95ae_f16bf3a37624
template <> struct __declspec(uuid("ab8e5d11-b0c1-5a21-95ae-f16bf3a37624")) __declspec(novtable) IReference<Windows::UI::Color> : impl_IReference<Windows::UI::Color> {};
#endif

#ifndef WINRT_GENERIC_c50898f6_c536_5f47_8583_8b2c2438a13b
#define WINRT_GENERIC_c50898f6_c536_5f47_8583_8b2c2438a13b
template <> struct __declspec(uuid("c50898f6-c536-5f47-8583-8b2c2438a13b")) __declspec(novtable) EventHandler<Windows::IInspectable> : impl_EventHandler<Windows::IInspectable> {};
#endif

#ifndef WINRT_GENERIC_b813d684_d953_5a8a_9b30_78b79fb9147b
#define WINRT_GENERIC_b813d684_d953_5a8a_9b30_78b79fb9147b
template <> struct __declspec(uuid("b813d684-d953-5a8a-9b30-78b79fb9147b")) __declspec(novtable) TypedEventHandler<Windows::UI::ViewManagement::InputPane, Windows::UI::ViewManagement::InputPaneVisibilityEventArgs> : impl_TypedEventHandler<Windows::UI::ViewManagement::InputPane, Windows::UI::ViewManagement::InputPaneVisibilityEventArgs> {};
#endif

#ifndef WINRT_GENERIC_f5917e6f_5abf_5e65_b5b4_1b9c8d94e788
#define WINRT_GENERIC_f5917e6f_5abf_5e65_b5b4_1b9c8d94e788
template <> struct __declspec(uuid("f5917e6f-5abf-5e65-b5b4-1b9c8d94e788")) __declspec(novtable) TypedEventHandler<Windows::UI::ViewManagement::AccessibilitySettings, Windows::IInspectable> : impl_TypedEventHandler<Windows::UI::ViewManagement::AccessibilitySettings, Windows::IInspectable> {};
#endif

#ifndef WINRT_GENERIC_2dbdba9d_20da_519d_9078_09f835bc5bc7
#define WINRT_GENERIC_2dbdba9d_20da_519d_9078_09f835bc5bc7
template <> struct __declspec(uuid("2dbdba9d-20da-519d-9078-09f835bc5bc7")) __declspec(novtable) TypedEventHandler<Windows::UI::ViewManagement::UISettings, Windows::IInspectable> : impl_TypedEventHandler<Windows::UI::ViewManagement::UISettings, Windows::IInspectable> {};
#endif

#ifndef WINRT_GENERIC_c1d3d1a2_ae17_5a5f_b5a2_bdcc8844889a
#define WINRT_GENERIC_c1d3d1a2_ae17_5a5f_b5a2_bdcc8844889a
template <> struct __declspec(uuid("c1d3d1a2-ae17-5a5f-b5a2-bdcc8844889a")) __declspec(novtable) AsyncOperationCompletedHandler<bool> : impl_AsyncOperationCompletedHandler<bool> {};
#endif


}

namespace Windows::UI::ViewManagement {

struct IAccessibilitySettings :
    Windows::IInspectable,
    impl::consume<IAccessibilitySettings>
{
    IAccessibilitySettings(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IAccessibilitySettings>(m_ptr); }
};

struct IActivationViewSwitcher :
    Windows::IInspectable,
    impl::consume<IActivationViewSwitcher>
{
    IActivationViewSwitcher(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IActivationViewSwitcher>(m_ptr); }
};

struct IApplicationView :
    Windows::IInspectable,
    impl::consume<IApplicationView>
{
    IApplicationView(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IApplicationView>(m_ptr); }
};

struct IApplicationView2 :
    Windows::IInspectable,
    impl::consume<IApplicationView2>
{
    IApplicationView2(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IApplicationView2>(m_ptr); }
};

struct IApplicationView3 :
    Windows::IInspectable,
    impl::consume<IApplicationView3>
{
    IApplicationView3(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IApplicationView3>(m_ptr); }
};

struct IApplicationViewConsolidatedEventArgs :
    Windows::IInspectable,
    impl::consume<IApplicationViewConsolidatedEventArgs>
{
    IApplicationViewConsolidatedEventArgs(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IApplicationViewConsolidatedEventArgs>(m_ptr); }
};

struct IApplicationViewFullscreenStatics :
    Windows::IInspectable,
    impl::consume<IApplicationViewFullscreenStatics>
{
    IApplicationViewFullscreenStatics(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IApplicationViewFullscreenStatics>(m_ptr); }
};

struct IApplicationViewInteropStatics :
    Windows::IInspectable,
    impl::consume<IApplicationViewInteropStatics>
{
    IApplicationViewInteropStatics(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IApplicationViewInteropStatics>(m_ptr); }
};

struct IApplicationViewScaling :
    Windows::IInspectable,
    impl::consume<IApplicationViewScaling>
{
    IApplicationViewScaling(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IApplicationViewScaling>(m_ptr); }
};

struct IApplicationViewScalingStatics :
    Windows::IInspectable,
    impl::consume<IApplicationViewScalingStatics>
{
    IApplicationViewScalingStatics(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IApplicationViewScalingStatics>(m_ptr); }
};

struct IApplicationViewStatics :
    Windows::IInspectable,
    impl::consume<IApplicationViewStatics>
{
    IApplicationViewStatics(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IApplicationViewStatics>(m_ptr); }
};

struct IApplicationViewStatics2 :
    Windows::IInspectable,
    impl::consume<IApplicationViewStatics2>
{
    IApplicationViewStatics2(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IApplicationViewStatics2>(m_ptr); }
};

struct IApplicationViewStatics3 :
    Windows::IInspectable,
    impl::consume<IApplicationViewStatics3>
{
    IApplicationViewStatics3(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IApplicationViewStatics3>(m_ptr); }
};

struct IApplicationViewSwitcherStatics :
    Windows::IInspectable,
    impl::consume<IApplicationViewSwitcherStatics>
{
    IApplicationViewSwitcherStatics(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IApplicationViewSwitcherStatics>(m_ptr); }
};

struct IApplicationViewSwitcherStatics2 :
    Windows::IInspectable,
    impl::consume<IApplicationViewSwitcherStatics2>
{
    IApplicationViewSwitcherStatics2(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IApplicationViewSwitcherStatics2>(m_ptr); }
};

struct IApplicationViewTitleBar :
    Windows::IInspectable,
    impl::consume<IApplicationViewTitleBar>
{
    IApplicationViewTitleBar(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IApplicationViewTitleBar>(m_ptr); }
};

struct IApplicationViewTransferContext :
    Windows::IInspectable,
    impl::consume<IApplicationViewTransferContext>
{
    IApplicationViewTransferContext(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IApplicationViewTransferContext>(m_ptr); }
};

struct IApplicationViewTransferContextStatics :
    Windows::IInspectable,
    impl::consume<IApplicationViewTransferContextStatics>
{
    IApplicationViewTransferContextStatics(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IApplicationViewTransferContextStatics>(m_ptr); }
};

struct IInputPane :
    Windows::IInspectable,
    impl::consume<IInputPane>
{
    IInputPane(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IInputPane>(m_ptr); }
};

struct IInputPane2 :
    Windows::IInspectable,
    impl::consume<IInputPane2>
{
    IInputPane2(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IInputPane2>(m_ptr); }
};

struct IInputPaneControl :
    Windows::IInspectable,
    impl::consume<IInputPaneControl>
{
    IInputPaneControl(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IInputPaneControl>(m_ptr); }
};

struct IInputPaneStatics :
    Windows::IInspectable,
    impl::consume<IInputPaneStatics>
{
    IInputPaneStatics(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IInputPaneStatics>(m_ptr); }
};

struct IInputPaneVisibilityEventArgs :
    Windows::IInspectable,
    impl::consume<IInputPaneVisibilityEventArgs>
{
    IInputPaneVisibilityEventArgs(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IInputPaneVisibilityEventArgs>(m_ptr); }
};

struct IProjectionManagerStatics :
    Windows::IInspectable,
    impl::consume<IProjectionManagerStatics>
{
    IProjectionManagerStatics(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IProjectionManagerStatics>(m_ptr); }
};

struct IProjectionManagerStatics2 :
    Windows::IInspectable,
    impl::consume<IProjectionManagerStatics2>
{
    IProjectionManagerStatics2(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IProjectionManagerStatics2>(m_ptr); }
};

struct IUISettings :
    Windows::IInspectable,
    impl::consume<IUISettings>
{
    IUISettings(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IUISettings>(m_ptr); }
};

struct IUISettings2 :
    Windows::IInspectable,
    impl::consume<IUISettings2>
{
    IUISettings2(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IUISettings2>(m_ptr); }
};

struct IUISettings3 :
    Windows::IInspectable,
    impl::consume<IUISettings3>
{
    IUISettings3(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IUISettings3>(m_ptr); }
};

struct IUIViewSettings :
    Windows::IInspectable,
    impl::consume<IUIViewSettings>
{
    IUIViewSettings(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IUIViewSettings>(m_ptr); }
};

struct IUIViewSettingsStatics :
    Windows::IInspectable,
    impl::consume<IUIViewSettingsStatics>
{
    IUIViewSettingsStatics(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IUIViewSettingsStatics>(m_ptr); }
};

}

}
