// C++ for the Windows Runtime v1.0.private
// Copyright (c) 2016 Microsoft Corporation. All rights reserved.

#pragma once

#include "Windows.UI.Xaml.Automation.Peers.1.h"
#include "Windows.UI.Xaml.1.h"
#include "Windows.UI.Xaml.Automation.Provider.1.h"
#include "Windows.UI.Xaml.2.h"

WINRT_EXPORT namespace winrt {

namespace ABI::Windows::Foundation::Collections {

#ifndef WINRT_GENERIC_2f13c006_a03a_5f69_b090_75a43e33423e
#define WINRT_GENERIC_2f13c006_a03a_5f69_b090_75a43e33423e
template <> struct __declspec(uuid("2f13c006-a03a-5f69-b090-75a43e33423e")) __declspec(novtable) IVectorView<hstring> : impl_IVectorView<hstring> {};
#endif

#ifndef WINRT_GENERIC_e2fcc7c1_3bfc_5a0b_b2b0_72e769d1cb7e
#define WINRT_GENERIC_e2fcc7c1_3bfc_5a0b_b2b0_72e769d1cb7e
template <> struct __declspec(uuid("e2fcc7c1-3bfc-5a0b-b2b0-72e769d1cb7e")) __declspec(novtable) IIterable<hstring> : impl_IIterable<hstring> {};
#endif

#ifndef WINRT_GENERIC_a8d8a409_9130_5e14_8426_0782aaf01608
#define WINRT_GENERIC_a8d8a409_9130_5e14_8426_0782aaf01608
template <> struct __declspec(uuid("a8d8a409-9130-5e14-8426-0782aaf01608")) __declspec(novtable) IVector<Windows::UI::Xaml::Automation::Peers::AutomationPeer> : impl_IVector<Windows::UI::Xaml::Automation::Peers::AutomationPeer> {};
#endif

#ifndef WINRT_GENERIC_b56a6076_19e2_50c1_930f_825bfc39635c
#define WINRT_GENERIC_b56a6076_19e2_50c1_930f_825bfc39635c
template <> struct __declspec(uuid("b56a6076-19e2-50c1-930f-825bfc39635c")) __declspec(novtable) IVectorView<Windows::UI::Xaml::Automation::Peers::AutomationPeer> : impl_IVectorView<Windows::UI::Xaml::Automation::Peers::AutomationPeer> {};
#endif

#ifndef WINRT_GENERIC_d353f885_4bf0_5dc2_878e_ec7a394ee880
#define WINRT_GENERIC_d353f885_4bf0_5dc2_878e_ec7a394ee880
template <> struct __declspec(uuid("d353f885-4bf0-5dc2-878e-ec7a394ee880")) __declspec(novtable) IVector<Windows::UI::Xaml::Automation::Peers::AutomationPeerAnnotation> : impl_IVector<Windows::UI::Xaml::Automation::Peers::AutomationPeerAnnotation> {};
#endif

#ifndef WINRT_GENERIC_7f67a4e2_96e0_522b_8710_14c42d834f1e
#define WINRT_GENERIC_7f67a4e2_96e0_522b_8710_14c42d834f1e
template <> struct __declspec(uuid("7f67a4e2-96e0-522b-8710-14c42d834f1e")) __declspec(novtable) IIterable<Windows::UI::Xaml::Automation::Peers::AutomationPeer> : impl_IIterable<Windows::UI::Xaml::Automation::Peers::AutomationPeer> {};
#endif

#ifndef WINRT_GENERIC_8c304ebb_6615_50a4_8829_879ecd443236
#define WINRT_GENERIC_8c304ebb_6615_50a4_8829_879ecd443236
template <> struct __declspec(uuid("8c304ebb-6615-50a4-8829-879ecd443236")) __declspec(novtable) IIterator<hstring> : impl_IIterator<hstring> {};
#endif

#ifndef WINRT_GENERIC_1f93cd7a_8075_5ba9_bc3e_b04a94e14bc0
#define WINRT_GENERIC_1f93cd7a_8075_5ba9_bc3e_b04a94e14bc0
template <> struct __declspec(uuid("1f93cd7a-8075-5ba9-bc3e-b04a94e14bc0")) __declspec(novtable) IIterator<Windows::UI::Xaml::Automation::Peers::AutomationPeer> : impl_IIterator<Windows::UI::Xaml::Automation::Peers::AutomationPeer> {};
#endif

#ifndef WINRT_GENERIC_3b415733_48f2_58b0_9884_6f0d0e35dc1a
#define WINRT_GENERIC_3b415733_48f2_58b0_9884_6f0d0e35dc1a
template <> struct __declspec(uuid("3b415733-48f2-58b0-9884-6f0d0e35dc1a")) __declspec(novtable) IIterator<Windows::UI::Xaml::Automation::Peers::AutomationPeerAnnotation> : impl_IIterator<Windows::UI::Xaml::Automation::Peers::AutomationPeerAnnotation> {};
#endif

#ifndef WINRT_GENERIC_dd28ff94_d11e_5ae7_b819_6177c1599313
#define WINRT_GENERIC_dd28ff94_d11e_5ae7_b819_6177c1599313
template <> struct __declspec(uuid("dd28ff94-d11e-5ae7-b819-6177c1599313")) __declspec(novtable) IIterable<Windows::UI::Xaml::Automation::Peers::AutomationPeerAnnotation> : impl_IIterable<Windows::UI::Xaml::Automation::Peers::AutomationPeerAnnotation> {};
#endif

#ifndef WINRT_GENERIC_00775c79_589b_5c36_ae72_2e7aab0270c6
#define WINRT_GENERIC_00775c79_589b_5c36_ae72_2e7aab0270c6
template <> struct __declspec(uuid("00775c79-589b-5c36-ae72-2e7aab0270c6")) __declspec(novtable) IVectorView<Windows::UI::Xaml::Automation::Peers::AutomationPeerAnnotation> : impl_IVectorView<Windows::UI::Xaml::Automation::Peers::AutomationPeerAnnotation> {};
#endif


}

namespace Windows::UI::Xaml::Automation::Peers {

struct IAppBarAutomationPeer :
    Windows::IInspectable,
    impl::consume<IAppBarAutomationPeer>
{
    IAppBarAutomationPeer(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IAppBarAutomationPeer>(m_ptr); }
};

struct IAppBarAutomationPeerFactory :
    Windows::IInspectable,
    impl::consume<IAppBarAutomationPeerFactory>
{
    IAppBarAutomationPeerFactory(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IAppBarAutomationPeerFactory>(m_ptr); }
};

struct IAppBarButtonAutomationPeer :
    Windows::IInspectable,
    impl::consume<IAppBarButtonAutomationPeer>
{
    IAppBarButtonAutomationPeer(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IAppBarButtonAutomationPeer>(m_ptr); }
};

struct IAppBarButtonAutomationPeerFactory :
    Windows::IInspectable,
    impl::consume<IAppBarButtonAutomationPeerFactory>
{
    IAppBarButtonAutomationPeerFactory(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IAppBarButtonAutomationPeerFactory>(m_ptr); }
};

struct IAppBarToggleButtonAutomationPeer :
    Windows::IInspectable,
    impl::consume<IAppBarToggleButtonAutomationPeer>
{
    IAppBarToggleButtonAutomationPeer(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IAppBarToggleButtonAutomationPeer>(m_ptr); }
};

struct IAppBarToggleButtonAutomationPeerFactory :
    Windows::IInspectable,
    impl::consume<IAppBarToggleButtonAutomationPeerFactory>
{
    IAppBarToggleButtonAutomationPeerFactory(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IAppBarToggleButtonAutomationPeerFactory>(m_ptr); }
};

struct IAutoSuggestBoxAutomationPeer :
    Windows::IInspectable,
    impl::consume<IAutoSuggestBoxAutomationPeer>
{
    IAutoSuggestBoxAutomationPeer(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IAutoSuggestBoxAutomationPeer>(m_ptr); }
};

struct IAutoSuggestBoxAutomationPeerFactory :
    Windows::IInspectable,
    impl::consume<IAutoSuggestBoxAutomationPeerFactory>
{
    IAutoSuggestBoxAutomationPeerFactory(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IAutoSuggestBoxAutomationPeerFactory>(m_ptr); }
};

struct IAutomationPeer :
    Windows::IInspectable,
    impl::consume<IAutomationPeer>
{
    IAutomationPeer(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IAutomationPeer>(m_ptr); }
};

struct IAutomationPeer2 :
    Windows::IInspectable,
    impl::consume<IAutomationPeer2>
{
    IAutomationPeer2(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IAutomationPeer2>(m_ptr); }
};

struct IAutomationPeer3 :
    Windows::IInspectable,
    impl::consume<IAutomationPeer3>
{
    IAutomationPeer3(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IAutomationPeer3>(m_ptr); }
};

struct IAutomationPeer4 :
    Windows::IInspectable,
    impl::consume<IAutomationPeer4>
{
    IAutomationPeer4(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IAutomationPeer4>(m_ptr); }
};

struct IAutomationPeer5 :
    Windows::IInspectable,
    impl::consume<IAutomationPeer5>
{
    IAutomationPeer5(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IAutomationPeer5>(m_ptr); }
};

struct IAutomationPeerAnnotation :
    Windows::IInspectable,
    impl::consume<IAutomationPeerAnnotation>
{
    IAutomationPeerAnnotation(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IAutomationPeerAnnotation>(m_ptr); }
};

struct IAutomationPeerAnnotationFactory :
    Windows::IInspectable,
    impl::consume<IAutomationPeerAnnotationFactory>
{
    IAutomationPeerAnnotationFactory(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IAutomationPeerAnnotationFactory>(m_ptr); }
};

struct IAutomationPeerAnnotationStatics :
    Windows::IInspectable,
    impl::consume<IAutomationPeerAnnotationStatics>
{
    IAutomationPeerAnnotationStatics(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IAutomationPeerAnnotationStatics>(m_ptr); }
};

struct IAutomationPeerFactory :
    Windows::IInspectable,
    impl::consume<IAutomationPeerFactory>
{
    IAutomationPeerFactory(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IAutomationPeerFactory>(m_ptr); }
};

struct IAutomationPeerOverrides :
    Windows::IInspectable,
    impl::consume<IAutomationPeerOverrides>
{
    IAutomationPeerOverrides(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IAutomationPeerOverrides>(m_ptr); }
};

struct IAutomationPeerOverrides2 :
    Windows::IInspectable,
    impl::consume<IAutomationPeerOverrides2>
{
    IAutomationPeerOverrides2(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IAutomationPeerOverrides2>(m_ptr); }
};

struct IAutomationPeerOverrides3 :
    Windows::IInspectable,
    impl::consume<IAutomationPeerOverrides3>
{
    IAutomationPeerOverrides3(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IAutomationPeerOverrides3>(m_ptr); }
};

struct IAutomationPeerOverrides4 :
    Windows::IInspectable,
    impl::consume<IAutomationPeerOverrides4>
{
    IAutomationPeerOverrides4(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IAutomationPeerOverrides4>(m_ptr); }
};

struct IAutomationPeerOverrides5 :
    Windows::IInspectable,
    impl::consume<IAutomationPeerOverrides5>
{
    IAutomationPeerOverrides5(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IAutomationPeerOverrides5>(m_ptr); }
};

struct IAutomationPeerProtected :
    Windows::IInspectable,
    impl::consume<IAutomationPeerProtected>
{
    IAutomationPeerProtected(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IAutomationPeerProtected>(m_ptr); }
};

struct IAutomationPeerStatics :
    Windows::IInspectable,
    impl::consume<IAutomationPeerStatics>
{
    IAutomationPeerStatics(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IAutomationPeerStatics>(m_ptr); }
};

struct IAutomationPeerStatics3 :
    Windows::IInspectable,
    impl::consume<IAutomationPeerStatics3>
{
    IAutomationPeerStatics3(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IAutomationPeerStatics3>(m_ptr); }
};

struct IButtonAutomationPeer :
    Windows::IInspectable,
    impl::consume<IButtonAutomationPeer>
{
    IButtonAutomationPeer(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IButtonAutomationPeer>(m_ptr); }
};

struct IButtonAutomationPeerFactory :
    Windows::IInspectable,
    impl::consume<IButtonAutomationPeerFactory>
{
    IButtonAutomationPeerFactory(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IButtonAutomationPeerFactory>(m_ptr); }
};

struct IButtonBaseAutomationPeer :
    Windows::IInspectable,
    impl::consume<IButtonBaseAutomationPeer>
{
    IButtonBaseAutomationPeer(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IButtonBaseAutomationPeer>(m_ptr); }
};

struct IButtonBaseAutomationPeerFactory :
    Windows::IInspectable,
    impl::consume<IButtonBaseAutomationPeerFactory>
{
    IButtonBaseAutomationPeerFactory(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IButtonBaseAutomationPeerFactory>(m_ptr); }
};

struct ICaptureElementAutomationPeer :
    Windows::IInspectable,
    impl::consume<ICaptureElementAutomationPeer>
{
    ICaptureElementAutomationPeer(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<ICaptureElementAutomationPeer>(m_ptr); }
};

struct ICaptureElementAutomationPeerFactory :
    Windows::IInspectable,
    impl::consume<ICaptureElementAutomationPeerFactory>
{
    ICaptureElementAutomationPeerFactory(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<ICaptureElementAutomationPeerFactory>(m_ptr); }
};

struct ICheckBoxAutomationPeer :
    Windows::IInspectable,
    impl::consume<ICheckBoxAutomationPeer>
{
    ICheckBoxAutomationPeer(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<ICheckBoxAutomationPeer>(m_ptr); }
};

struct ICheckBoxAutomationPeerFactory :
    Windows::IInspectable,
    impl::consume<ICheckBoxAutomationPeerFactory>
{
    ICheckBoxAutomationPeerFactory(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<ICheckBoxAutomationPeerFactory>(m_ptr); }
};

struct IComboBoxAutomationPeer :
    Windows::IInspectable,
    impl::consume<IComboBoxAutomationPeer>
{
    IComboBoxAutomationPeer(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IComboBoxAutomationPeer>(m_ptr); }
};

struct IComboBoxAutomationPeerFactory :
    Windows::IInspectable,
    impl::consume<IComboBoxAutomationPeerFactory>
{
    IComboBoxAutomationPeerFactory(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IComboBoxAutomationPeerFactory>(m_ptr); }
};

struct IComboBoxItemAutomationPeer :
    Windows::IInspectable,
    impl::consume<IComboBoxItemAutomationPeer>
{
    IComboBoxItemAutomationPeer(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IComboBoxItemAutomationPeer>(m_ptr); }
};

struct IComboBoxItemAutomationPeerFactory :
    Windows::IInspectable,
    impl::consume<IComboBoxItemAutomationPeerFactory>
{
    IComboBoxItemAutomationPeerFactory(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IComboBoxItemAutomationPeerFactory>(m_ptr); }
};

struct IComboBoxItemDataAutomationPeer :
    Windows::IInspectable,
    impl::consume<IComboBoxItemDataAutomationPeer>
{
    IComboBoxItemDataAutomationPeer(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IComboBoxItemDataAutomationPeer>(m_ptr); }
};

struct IComboBoxItemDataAutomationPeerFactory :
    Windows::IInspectable,
    impl::consume<IComboBoxItemDataAutomationPeerFactory>
{
    IComboBoxItemDataAutomationPeerFactory(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IComboBoxItemDataAutomationPeerFactory>(m_ptr); }
};

struct IDatePickerAutomationPeer :
    Windows::IInspectable,
    impl::consume<IDatePickerAutomationPeer>
{
    IDatePickerAutomationPeer(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IDatePickerAutomationPeer>(m_ptr); }
};

struct IDatePickerAutomationPeerFactory :
    Windows::IInspectable,
    impl::consume<IDatePickerAutomationPeerFactory>
{
    IDatePickerAutomationPeerFactory(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IDatePickerAutomationPeerFactory>(m_ptr); }
};

struct IDatePickerFlyoutPresenterAutomationPeer :
    Windows::IInspectable,
    impl::consume<IDatePickerFlyoutPresenterAutomationPeer>
{
    IDatePickerFlyoutPresenterAutomationPeer(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IDatePickerFlyoutPresenterAutomationPeer>(m_ptr); }
};

struct IFlipViewAutomationPeer :
    Windows::IInspectable,
    impl::consume<IFlipViewAutomationPeer>
{
    IFlipViewAutomationPeer(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IFlipViewAutomationPeer>(m_ptr); }
};

struct IFlipViewAutomationPeerFactory :
    Windows::IInspectable,
    impl::consume<IFlipViewAutomationPeerFactory>
{
    IFlipViewAutomationPeerFactory(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IFlipViewAutomationPeerFactory>(m_ptr); }
};

struct IFlipViewItemAutomationPeer :
    Windows::IInspectable,
    impl::consume<IFlipViewItemAutomationPeer>
{
    IFlipViewItemAutomationPeer(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IFlipViewItemAutomationPeer>(m_ptr); }
};

struct IFlipViewItemAutomationPeerFactory :
    Windows::IInspectable,
    impl::consume<IFlipViewItemAutomationPeerFactory>
{
    IFlipViewItemAutomationPeerFactory(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IFlipViewItemAutomationPeerFactory>(m_ptr); }
};

struct IFlipViewItemDataAutomationPeer :
    Windows::IInspectable,
    impl::consume<IFlipViewItemDataAutomationPeer>
{
    IFlipViewItemDataAutomationPeer(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IFlipViewItemDataAutomationPeer>(m_ptr); }
};

struct IFlipViewItemDataAutomationPeerFactory :
    Windows::IInspectable,
    impl::consume<IFlipViewItemDataAutomationPeerFactory>
{
    IFlipViewItemDataAutomationPeerFactory(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IFlipViewItemDataAutomationPeerFactory>(m_ptr); }
};

struct IFlyoutPresenterAutomationPeer :
    Windows::IInspectable,
    impl::consume<IFlyoutPresenterAutomationPeer>
{
    IFlyoutPresenterAutomationPeer(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IFlyoutPresenterAutomationPeer>(m_ptr); }
};

struct IFlyoutPresenterAutomationPeerFactory :
    Windows::IInspectable,
    impl::consume<IFlyoutPresenterAutomationPeerFactory>
{
    IFlyoutPresenterAutomationPeerFactory(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IFlyoutPresenterAutomationPeerFactory>(m_ptr); }
};

struct IFrameworkElementAutomationPeer :
    Windows::IInspectable,
    impl::consume<IFrameworkElementAutomationPeer>
{
    IFrameworkElementAutomationPeer(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IFrameworkElementAutomationPeer>(m_ptr); }
};

struct IFrameworkElementAutomationPeerFactory :
    Windows::IInspectable,
    impl::consume<IFrameworkElementAutomationPeerFactory>
{
    IFrameworkElementAutomationPeerFactory(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IFrameworkElementAutomationPeerFactory>(m_ptr); }
};

struct IFrameworkElementAutomationPeerStatics :
    Windows::IInspectable,
    impl::consume<IFrameworkElementAutomationPeerStatics>
{
    IFrameworkElementAutomationPeerStatics(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IFrameworkElementAutomationPeerStatics>(m_ptr); }
};

struct IGridViewAutomationPeer :
    Windows::IInspectable,
    impl::consume<IGridViewAutomationPeer>
{
    IGridViewAutomationPeer(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IGridViewAutomationPeer>(m_ptr); }
};

struct IGridViewAutomationPeerFactory :
    Windows::IInspectable,
    impl::consume<IGridViewAutomationPeerFactory>
{
    IGridViewAutomationPeerFactory(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IGridViewAutomationPeerFactory>(m_ptr); }
};

struct IGridViewHeaderItemAutomationPeer :
    Windows::IInspectable,
    impl::consume<IGridViewHeaderItemAutomationPeer>
{
    IGridViewHeaderItemAutomationPeer(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IGridViewHeaderItemAutomationPeer>(m_ptr); }
};

struct IGridViewHeaderItemAutomationPeerFactory :
    Windows::IInspectable,
    impl::consume<IGridViewHeaderItemAutomationPeerFactory>
{
    IGridViewHeaderItemAutomationPeerFactory(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IGridViewHeaderItemAutomationPeerFactory>(m_ptr); }
};

struct IGridViewItemAutomationPeer :
    Windows::IInspectable,
    impl::consume<IGridViewItemAutomationPeer>
{
    IGridViewItemAutomationPeer(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IGridViewItemAutomationPeer>(m_ptr); }
};

struct IGridViewItemAutomationPeerFactory :
    Windows::IInspectable,
    impl::consume<IGridViewItemAutomationPeerFactory>
{
    IGridViewItemAutomationPeerFactory(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IGridViewItemAutomationPeerFactory>(m_ptr); }
};

struct IGridViewItemDataAutomationPeer :
    Windows::IInspectable,
    impl::consume<IGridViewItemDataAutomationPeer>
{
    IGridViewItemDataAutomationPeer(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IGridViewItemDataAutomationPeer>(m_ptr); }
};

struct IGridViewItemDataAutomationPeerFactory :
    Windows::IInspectable,
    impl::consume<IGridViewItemDataAutomationPeerFactory>
{
    IGridViewItemDataAutomationPeerFactory(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IGridViewItemDataAutomationPeerFactory>(m_ptr); }
};

struct IGroupItemAutomationPeer :
    Windows::IInspectable,
    impl::consume<IGroupItemAutomationPeer>
{
    IGroupItemAutomationPeer(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IGroupItemAutomationPeer>(m_ptr); }
};

struct IGroupItemAutomationPeerFactory :
    Windows::IInspectable,
    impl::consume<IGroupItemAutomationPeerFactory>
{
    IGroupItemAutomationPeerFactory(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IGroupItemAutomationPeerFactory>(m_ptr); }
};

struct IHubAutomationPeer :
    Windows::IInspectable,
    impl::consume<IHubAutomationPeer>
{
    IHubAutomationPeer(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IHubAutomationPeer>(m_ptr); }
};

struct IHubAutomationPeerFactory :
    Windows::IInspectable,
    impl::consume<IHubAutomationPeerFactory>
{
    IHubAutomationPeerFactory(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IHubAutomationPeerFactory>(m_ptr); }
};

struct IHubSectionAutomationPeer :
    Windows::IInspectable,
    impl::consume<IHubSectionAutomationPeer>
{
    IHubSectionAutomationPeer(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IHubSectionAutomationPeer>(m_ptr); }
};

struct IHubSectionAutomationPeerFactory :
    Windows::IInspectable,
    impl::consume<IHubSectionAutomationPeerFactory>
{
    IHubSectionAutomationPeerFactory(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IHubSectionAutomationPeerFactory>(m_ptr); }
};

struct IHyperlinkButtonAutomationPeer :
    Windows::IInspectable,
    impl::consume<IHyperlinkButtonAutomationPeer>
{
    IHyperlinkButtonAutomationPeer(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IHyperlinkButtonAutomationPeer>(m_ptr); }
};

struct IHyperlinkButtonAutomationPeerFactory :
    Windows::IInspectable,
    impl::consume<IHyperlinkButtonAutomationPeerFactory>
{
    IHyperlinkButtonAutomationPeerFactory(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IHyperlinkButtonAutomationPeerFactory>(m_ptr); }
};

struct IImageAutomationPeer :
    Windows::IInspectable,
    impl::consume<IImageAutomationPeer>
{
    IImageAutomationPeer(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IImageAutomationPeer>(m_ptr); }
};

struct IImageAutomationPeerFactory :
    Windows::IInspectable,
    impl::consume<IImageAutomationPeerFactory>
{
    IImageAutomationPeerFactory(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IImageAutomationPeerFactory>(m_ptr); }
};

struct IInkToolbarAutomationPeer :
    Windows::IInspectable,
    impl::consume<IInkToolbarAutomationPeer>
{
    IInkToolbarAutomationPeer(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IInkToolbarAutomationPeer>(m_ptr); }
};

struct IItemAutomationPeer :
    Windows::IInspectable,
    impl::consume<IItemAutomationPeer>
{
    IItemAutomationPeer(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IItemAutomationPeer>(m_ptr); }
};

struct IItemAutomationPeerFactory :
    Windows::IInspectable,
    impl::consume<IItemAutomationPeerFactory>
{
    IItemAutomationPeerFactory(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IItemAutomationPeerFactory>(m_ptr); }
};

struct IItemsControlAutomationPeer :
    Windows::IInspectable,
    impl::consume<IItemsControlAutomationPeer>
{
    IItemsControlAutomationPeer(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IItemsControlAutomationPeer>(m_ptr); }
};

struct IItemsControlAutomationPeer2 :
    Windows::IInspectable,
    impl::consume<IItemsControlAutomationPeer2>
{
    IItemsControlAutomationPeer2(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IItemsControlAutomationPeer2>(m_ptr); }
};

struct IItemsControlAutomationPeerFactory :
    Windows::IInspectable,
    impl::consume<IItemsControlAutomationPeerFactory>
{
    IItemsControlAutomationPeerFactory(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IItemsControlAutomationPeerFactory>(m_ptr); }
};

struct IItemsControlAutomationPeerOverrides2 :
    Windows::IInspectable,
    impl::consume<IItemsControlAutomationPeerOverrides2>
{
    IItemsControlAutomationPeerOverrides2(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IItemsControlAutomationPeerOverrides2>(m_ptr); }
};

struct IListBoxAutomationPeer :
    Windows::IInspectable,
    impl::consume<IListBoxAutomationPeer>
{
    IListBoxAutomationPeer(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IListBoxAutomationPeer>(m_ptr); }
};

struct IListBoxAutomationPeerFactory :
    Windows::IInspectable,
    impl::consume<IListBoxAutomationPeerFactory>
{
    IListBoxAutomationPeerFactory(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IListBoxAutomationPeerFactory>(m_ptr); }
};

struct IListBoxItemAutomationPeer :
    Windows::IInspectable,
    impl::consume<IListBoxItemAutomationPeer>
{
    IListBoxItemAutomationPeer(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IListBoxItemAutomationPeer>(m_ptr); }
};

struct IListBoxItemAutomationPeerFactory :
    Windows::IInspectable,
    impl::consume<IListBoxItemAutomationPeerFactory>
{
    IListBoxItemAutomationPeerFactory(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IListBoxItemAutomationPeerFactory>(m_ptr); }
};

struct IListBoxItemDataAutomationPeer :
    Windows::IInspectable,
    impl::consume<IListBoxItemDataAutomationPeer>
{
    IListBoxItemDataAutomationPeer(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IListBoxItemDataAutomationPeer>(m_ptr); }
};

struct IListBoxItemDataAutomationPeerFactory :
    Windows::IInspectable,
    impl::consume<IListBoxItemDataAutomationPeerFactory>
{
    IListBoxItemDataAutomationPeerFactory(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IListBoxItemDataAutomationPeerFactory>(m_ptr); }
};

struct IListPickerFlyoutPresenterAutomationPeer :
    Windows::IInspectable,
    impl::consume<IListPickerFlyoutPresenterAutomationPeer>
{
    IListPickerFlyoutPresenterAutomationPeer(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IListPickerFlyoutPresenterAutomationPeer>(m_ptr); }
};

struct IListViewAutomationPeer :
    Windows::IInspectable,
    impl::consume<IListViewAutomationPeer>
{
    IListViewAutomationPeer(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IListViewAutomationPeer>(m_ptr); }
};

struct IListViewAutomationPeerFactory :
    Windows::IInspectable,
    impl::consume<IListViewAutomationPeerFactory>
{
    IListViewAutomationPeerFactory(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IListViewAutomationPeerFactory>(m_ptr); }
};

struct IListViewBaseAutomationPeer :
    Windows::IInspectable,
    impl::consume<IListViewBaseAutomationPeer>
{
    IListViewBaseAutomationPeer(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IListViewBaseAutomationPeer>(m_ptr); }
};

struct IListViewBaseAutomationPeerFactory :
    Windows::IInspectable,
    impl::consume<IListViewBaseAutomationPeerFactory>
{
    IListViewBaseAutomationPeerFactory(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IListViewBaseAutomationPeerFactory>(m_ptr); }
};

struct IListViewBaseHeaderItemAutomationPeer :
    Windows::IInspectable,
    impl::consume<IListViewBaseHeaderItemAutomationPeer>
{
    IListViewBaseHeaderItemAutomationPeer(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IListViewBaseHeaderItemAutomationPeer>(m_ptr); }
};

struct IListViewBaseHeaderItemAutomationPeerFactory :
    Windows::IInspectable,
    impl::consume<IListViewBaseHeaderItemAutomationPeerFactory>
{
    IListViewBaseHeaderItemAutomationPeerFactory(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IListViewBaseHeaderItemAutomationPeerFactory>(m_ptr); }
};

struct IListViewHeaderItemAutomationPeer :
    Windows::IInspectable,
    impl::consume<IListViewHeaderItemAutomationPeer>
{
    IListViewHeaderItemAutomationPeer(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IListViewHeaderItemAutomationPeer>(m_ptr); }
};

struct IListViewHeaderItemAutomationPeerFactory :
    Windows::IInspectable,
    impl::consume<IListViewHeaderItemAutomationPeerFactory>
{
    IListViewHeaderItemAutomationPeerFactory(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IListViewHeaderItemAutomationPeerFactory>(m_ptr); }
};

struct IListViewItemAutomationPeer :
    Windows::IInspectable,
    impl::consume<IListViewItemAutomationPeer>
{
    IListViewItemAutomationPeer(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IListViewItemAutomationPeer>(m_ptr); }
};

struct IListViewItemAutomationPeerFactory :
    Windows::IInspectable,
    impl::consume<IListViewItemAutomationPeerFactory>
{
    IListViewItemAutomationPeerFactory(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IListViewItemAutomationPeerFactory>(m_ptr); }
};

struct IListViewItemDataAutomationPeer :
    Windows::IInspectable,
    impl::consume<IListViewItemDataAutomationPeer>
{
    IListViewItemDataAutomationPeer(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IListViewItemDataAutomationPeer>(m_ptr); }
};

struct IListViewItemDataAutomationPeerFactory :
    Windows::IInspectable,
    impl::consume<IListViewItemDataAutomationPeerFactory>
{
    IListViewItemDataAutomationPeerFactory(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IListViewItemDataAutomationPeerFactory>(m_ptr); }
};

struct ILoopingSelectorAutomationPeer :
    Windows::IInspectable,
    impl::consume<ILoopingSelectorAutomationPeer>
{
    ILoopingSelectorAutomationPeer(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<ILoopingSelectorAutomationPeer>(m_ptr); }
};

struct ILoopingSelectorItemAutomationPeer :
    Windows::IInspectable,
    impl::consume<ILoopingSelectorItemAutomationPeer>
{
    ILoopingSelectorItemAutomationPeer(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<ILoopingSelectorItemAutomationPeer>(m_ptr); }
};

struct ILoopingSelectorItemDataAutomationPeer :
    Windows::IInspectable,
    impl::consume<ILoopingSelectorItemDataAutomationPeer>
{
    ILoopingSelectorItemDataAutomationPeer(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<ILoopingSelectorItemDataAutomationPeer>(m_ptr); }
};

struct IMapControlAutomationPeer :
    Windows::IInspectable,
    impl::consume<IMapControlAutomationPeer>
{
    IMapControlAutomationPeer(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IMapControlAutomationPeer>(m_ptr); }
};

struct IMediaElementAutomationPeer :
    Windows::IInspectable,
    impl::consume<IMediaElementAutomationPeer>
{
    IMediaElementAutomationPeer(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IMediaElementAutomationPeer>(m_ptr); }
};

struct IMediaElementAutomationPeerFactory :
    Windows::IInspectable,
    impl::consume<IMediaElementAutomationPeerFactory>
{
    IMediaElementAutomationPeerFactory(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IMediaElementAutomationPeerFactory>(m_ptr); }
};

struct IMediaPlayerElementAutomationPeer :
    Windows::IInspectable,
    impl::consume<IMediaPlayerElementAutomationPeer>
{
    IMediaPlayerElementAutomationPeer(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IMediaPlayerElementAutomationPeer>(m_ptr); }
};

struct IMediaPlayerElementAutomationPeerFactory :
    Windows::IInspectable,
    impl::consume<IMediaPlayerElementAutomationPeerFactory>
{
    IMediaPlayerElementAutomationPeerFactory(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IMediaPlayerElementAutomationPeerFactory>(m_ptr); }
};

struct IMediaTransportControlsAutomationPeer :
    Windows::IInspectable,
    impl::consume<IMediaTransportControlsAutomationPeer>
{
    IMediaTransportControlsAutomationPeer(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IMediaTransportControlsAutomationPeer>(m_ptr); }
};

struct IMediaTransportControlsAutomationPeerFactory :
    Windows::IInspectable,
    impl::consume<IMediaTransportControlsAutomationPeerFactory>
{
    IMediaTransportControlsAutomationPeerFactory(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IMediaTransportControlsAutomationPeerFactory>(m_ptr); }
};

struct IMenuFlyoutItemAutomationPeer :
    Windows::IInspectable,
    impl::consume<IMenuFlyoutItemAutomationPeer>
{
    IMenuFlyoutItemAutomationPeer(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IMenuFlyoutItemAutomationPeer>(m_ptr); }
};

struct IMenuFlyoutItemAutomationPeerFactory :
    Windows::IInspectable,
    impl::consume<IMenuFlyoutItemAutomationPeerFactory>
{
    IMenuFlyoutItemAutomationPeerFactory(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IMenuFlyoutItemAutomationPeerFactory>(m_ptr); }
};

struct IMenuFlyoutPresenterAutomationPeer :
    Windows::IInspectable,
    impl::consume<IMenuFlyoutPresenterAutomationPeer>
{
    IMenuFlyoutPresenterAutomationPeer(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IMenuFlyoutPresenterAutomationPeer>(m_ptr); }
};

struct IMenuFlyoutPresenterAutomationPeerFactory :
    Windows::IInspectable,
    impl::consume<IMenuFlyoutPresenterAutomationPeerFactory>
{
    IMenuFlyoutPresenterAutomationPeerFactory(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IMenuFlyoutPresenterAutomationPeerFactory>(m_ptr); }
};

struct IPasswordBoxAutomationPeer :
    Windows::IInspectable,
    impl::consume<IPasswordBoxAutomationPeer>
{
    IPasswordBoxAutomationPeer(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IPasswordBoxAutomationPeer>(m_ptr); }
};

struct IPasswordBoxAutomationPeerFactory :
    Windows::IInspectable,
    impl::consume<IPasswordBoxAutomationPeerFactory>
{
    IPasswordBoxAutomationPeerFactory(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IPasswordBoxAutomationPeerFactory>(m_ptr); }
};

struct IPickerFlyoutPresenterAutomationPeer :
    Windows::IInspectable,
    impl::consume<IPickerFlyoutPresenterAutomationPeer>
{
    IPickerFlyoutPresenterAutomationPeer(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IPickerFlyoutPresenterAutomationPeer>(m_ptr); }
};

struct IPivotAutomationPeer :
    Windows::IInspectable,
    impl::consume<IPivotAutomationPeer>
{
    IPivotAutomationPeer(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IPivotAutomationPeer>(m_ptr); }
};

struct IPivotAutomationPeerFactory :
    Windows::IInspectable,
    impl::consume<IPivotAutomationPeerFactory>
{
    IPivotAutomationPeerFactory(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IPivotAutomationPeerFactory>(m_ptr); }
};

struct IPivotItemAutomationPeer :
    Windows::IInspectable,
    impl::consume<IPivotItemAutomationPeer>
{
    IPivotItemAutomationPeer(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IPivotItemAutomationPeer>(m_ptr); }
};

struct IPivotItemAutomationPeerFactory :
    Windows::IInspectable,
    impl::consume<IPivotItemAutomationPeerFactory>
{
    IPivotItemAutomationPeerFactory(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IPivotItemAutomationPeerFactory>(m_ptr); }
};

struct IPivotItemDataAutomationPeer :
    Windows::IInspectable,
    impl::consume<IPivotItemDataAutomationPeer>
{
    IPivotItemDataAutomationPeer(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IPivotItemDataAutomationPeer>(m_ptr); }
};

struct IPivotItemDataAutomationPeerFactory :
    Windows::IInspectable,
    impl::consume<IPivotItemDataAutomationPeerFactory>
{
    IPivotItemDataAutomationPeerFactory(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IPivotItemDataAutomationPeerFactory>(m_ptr); }
};

struct IProgressBarAutomationPeer :
    Windows::IInspectable,
    impl::consume<IProgressBarAutomationPeer>
{
    IProgressBarAutomationPeer(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IProgressBarAutomationPeer>(m_ptr); }
};

struct IProgressBarAutomationPeerFactory :
    Windows::IInspectable,
    impl::consume<IProgressBarAutomationPeerFactory>
{
    IProgressBarAutomationPeerFactory(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IProgressBarAutomationPeerFactory>(m_ptr); }
};

struct IProgressRingAutomationPeer :
    Windows::IInspectable,
    impl::consume<IProgressRingAutomationPeer>
{
    IProgressRingAutomationPeer(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IProgressRingAutomationPeer>(m_ptr); }
};

struct IProgressRingAutomationPeerFactory :
    Windows::IInspectable,
    impl::consume<IProgressRingAutomationPeerFactory>
{
    IProgressRingAutomationPeerFactory(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IProgressRingAutomationPeerFactory>(m_ptr); }
};

struct IRadioButtonAutomationPeer :
    Windows::IInspectable,
    impl::consume<IRadioButtonAutomationPeer>
{
    IRadioButtonAutomationPeer(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IRadioButtonAutomationPeer>(m_ptr); }
};

struct IRadioButtonAutomationPeerFactory :
    Windows::IInspectable,
    impl::consume<IRadioButtonAutomationPeerFactory>
{
    IRadioButtonAutomationPeerFactory(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IRadioButtonAutomationPeerFactory>(m_ptr); }
};

struct IRangeBaseAutomationPeer :
    Windows::IInspectable,
    impl::consume<IRangeBaseAutomationPeer>
{
    IRangeBaseAutomationPeer(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IRangeBaseAutomationPeer>(m_ptr); }
};

struct IRangeBaseAutomationPeerFactory :
    Windows::IInspectable,
    impl::consume<IRangeBaseAutomationPeerFactory>
{
    IRangeBaseAutomationPeerFactory(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IRangeBaseAutomationPeerFactory>(m_ptr); }
};

struct IRepeatButtonAutomationPeer :
    Windows::IInspectable,
    impl::consume<IRepeatButtonAutomationPeer>
{
    IRepeatButtonAutomationPeer(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IRepeatButtonAutomationPeer>(m_ptr); }
};

struct IRepeatButtonAutomationPeerFactory :
    Windows::IInspectable,
    impl::consume<IRepeatButtonAutomationPeerFactory>
{
    IRepeatButtonAutomationPeerFactory(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IRepeatButtonAutomationPeerFactory>(m_ptr); }
};

struct IRichEditBoxAutomationPeer :
    Windows::IInspectable,
    impl::consume<IRichEditBoxAutomationPeer>
{
    IRichEditBoxAutomationPeer(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IRichEditBoxAutomationPeer>(m_ptr); }
};

struct IRichEditBoxAutomationPeerFactory :
    Windows::IInspectable,
    impl::consume<IRichEditBoxAutomationPeerFactory>
{
    IRichEditBoxAutomationPeerFactory(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IRichEditBoxAutomationPeerFactory>(m_ptr); }
};

struct IRichTextBlockAutomationPeer :
    Windows::IInspectable,
    impl::consume<IRichTextBlockAutomationPeer>
{
    IRichTextBlockAutomationPeer(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IRichTextBlockAutomationPeer>(m_ptr); }
};

struct IRichTextBlockAutomationPeerFactory :
    Windows::IInspectable,
    impl::consume<IRichTextBlockAutomationPeerFactory>
{
    IRichTextBlockAutomationPeerFactory(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IRichTextBlockAutomationPeerFactory>(m_ptr); }
};

struct IRichTextBlockOverflowAutomationPeer :
    Windows::IInspectable,
    impl::consume<IRichTextBlockOverflowAutomationPeer>
{
    IRichTextBlockOverflowAutomationPeer(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IRichTextBlockOverflowAutomationPeer>(m_ptr); }
};

struct IRichTextBlockOverflowAutomationPeerFactory :
    Windows::IInspectable,
    impl::consume<IRichTextBlockOverflowAutomationPeerFactory>
{
    IRichTextBlockOverflowAutomationPeerFactory(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IRichTextBlockOverflowAutomationPeerFactory>(m_ptr); }
};

struct IScrollBarAutomationPeer :
    Windows::IInspectable,
    impl::consume<IScrollBarAutomationPeer>
{
    IScrollBarAutomationPeer(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IScrollBarAutomationPeer>(m_ptr); }
};

struct IScrollBarAutomationPeerFactory :
    Windows::IInspectable,
    impl::consume<IScrollBarAutomationPeerFactory>
{
    IScrollBarAutomationPeerFactory(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IScrollBarAutomationPeerFactory>(m_ptr); }
};

struct IScrollViewerAutomationPeer :
    Windows::IInspectable,
    impl::consume<IScrollViewerAutomationPeer>
{
    IScrollViewerAutomationPeer(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IScrollViewerAutomationPeer>(m_ptr); }
};

struct IScrollViewerAutomationPeerFactory :
    Windows::IInspectable,
    impl::consume<IScrollViewerAutomationPeerFactory>
{
    IScrollViewerAutomationPeerFactory(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IScrollViewerAutomationPeerFactory>(m_ptr); }
};

struct ISearchBoxAutomationPeer :
    Windows::IInspectable,
    impl::consume<ISearchBoxAutomationPeer>
{
    ISearchBoxAutomationPeer(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<ISearchBoxAutomationPeer>(m_ptr); }
};

struct ISearchBoxAutomationPeerFactory :
    Windows::IInspectable,
    impl::consume<ISearchBoxAutomationPeerFactory>
{
    ISearchBoxAutomationPeerFactory(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<ISearchBoxAutomationPeerFactory>(m_ptr); }
};

struct ISelectorAutomationPeer :
    Windows::IInspectable,
    impl::consume<ISelectorAutomationPeer>
{
    ISelectorAutomationPeer(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<ISelectorAutomationPeer>(m_ptr); }
};

struct ISelectorAutomationPeerFactory :
    Windows::IInspectable,
    impl::consume<ISelectorAutomationPeerFactory>
{
    ISelectorAutomationPeerFactory(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<ISelectorAutomationPeerFactory>(m_ptr); }
};

struct ISelectorItemAutomationPeer :
    Windows::IInspectable,
    impl::consume<ISelectorItemAutomationPeer>
{
    ISelectorItemAutomationPeer(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<ISelectorItemAutomationPeer>(m_ptr); }
};

struct ISelectorItemAutomationPeerFactory :
    Windows::IInspectable,
    impl::consume<ISelectorItemAutomationPeerFactory>
{
    ISelectorItemAutomationPeerFactory(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<ISelectorItemAutomationPeerFactory>(m_ptr); }
};

struct ISemanticZoomAutomationPeer :
    Windows::IInspectable,
    impl::consume<ISemanticZoomAutomationPeer>
{
    ISemanticZoomAutomationPeer(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<ISemanticZoomAutomationPeer>(m_ptr); }
};

struct ISemanticZoomAutomationPeerFactory :
    Windows::IInspectable,
    impl::consume<ISemanticZoomAutomationPeerFactory>
{
    ISemanticZoomAutomationPeerFactory(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<ISemanticZoomAutomationPeerFactory>(m_ptr); }
};

struct ISettingsFlyoutAutomationPeer :
    Windows::IInspectable,
    impl::consume<ISettingsFlyoutAutomationPeer>
{
    ISettingsFlyoutAutomationPeer(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<ISettingsFlyoutAutomationPeer>(m_ptr); }
};

struct ISettingsFlyoutAutomationPeerFactory :
    Windows::IInspectable,
    impl::consume<ISettingsFlyoutAutomationPeerFactory>
{
    ISettingsFlyoutAutomationPeerFactory(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<ISettingsFlyoutAutomationPeerFactory>(m_ptr); }
};

struct ISliderAutomationPeer :
    Windows::IInspectable,
    impl::consume<ISliderAutomationPeer>
{
    ISliderAutomationPeer(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<ISliderAutomationPeer>(m_ptr); }
};

struct ISliderAutomationPeerFactory :
    Windows::IInspectable,
    impl::consume<ISliderAutomationPeerFactory>
{
    ISliderAutomationPeerFactory(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<ISliderAutomationPeerFactory>(m_ptr); }
};

struct ITextBlockAutomationPeer :
    Windows::IInspectable,
    impl::consume<ITextBlockAutomationPeer>
{
    ITextBlockAutomationPeer(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<ITextBlockAutomationPeer>(m_ptr); }
};

struct ITextBlockAutomationPeerFactory :
    Windows::IInspectable,
    impl::consume<ITextBlockAutomationPeerFactory>
{
    ITextBlockAutomationPeerFactory(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<ITextBlockAutomationPeerFactory>(m_ptr); }
};

struct ITextBoxAutomationPeer :
    Windows::IInspectable,
    impl::consume<ITextBoxAutomationPeer>
{
    ITextBoxAutomationPeer(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<ITextBoxAutomationPeer>(m_ptr); }
};

struct ITextBoxAutomationPeerFactory :
    Windows::IInspectable,
    impl::consume<ITextBoxAutomationPeerFactory>
{
    ITextBoxAutomationPeerFactory(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<ITextBoxAutomationPeerFactory>(m_ptr); }
};

struct IThumbAutomationPeer :
    Windows::IInspectable,
    impl::consume<IThumbAutomationPeer>
{
    IThumbAutomationPeer(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IThumbAutomationPeer>(m_ptr); }
};

struct IThumbAutomationPeerFactory :
    Windows::IInspectable,
    impl::consume<IThumbAutomationPeerFactory>
{
    IThumbAutomationPeerFactory(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IThumbAutomationPeerFactory>(m_ptr); }
};

struct ITimePickerAutomationPeer :
    Windows::IInspectable,
    impl::consume<ITimePickerAutomationPeer>
{
    ITimePickerAutomationPeer(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<ITimePickerAutomationPeer>(m_ptr); }
};

struct ITimePickerAutomationPeerFactory :
    Windows::IInspectable,
    impl::consume<ITimePickerAutomationPeerFactory>
{
    ITimePickerAutomationPeerFactory(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<ITimePickerAutomationPeerFactory>(m_ptr); }
};

struct ITimePickerFlyoutPresenterAutomationPeer :
    Windows::IInspectable,
    impl::consume<ITimePickerFlyoutPresenterAutomationPeer>
{
    ITimePickerFlyoutPresenterAutomationPeer(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<ITimePickerFlyoutPresenterAutomationPeer>(m_ptr); }
};

struct IToggleButtonAutomationPeer :
    Windows::IInspectable,
    impl::consume<IToggleButtonAutomationPeer>
{
    IToggleButtonAutomationPeer(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IToggleButtonAutomationPeer>(m_ptr); }
};

struct IToggleButtonAutomationPeerFactory :
    Windows::IInspectable,
    impl::consume<IToggleButtonAutomationPeerFactory>
{
    IToggleButtonAutomationPeerFactory(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IToggleButtonAutomationPeerFactory>(m_ptr); }
};

struct IToggleMenuFlyoutItemAutomationPeer :
    Windows::IInspectable,
    impl::consume<IToggleMenuFlyoutItemAutomationPeer>
{
    IToggleMenuFlyoutItemAutomationPeer(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IToggleMenuFlyoutItemAutomationPeer>(m_ptr); }
};

struct IToggleMenuFlyoutItemAutomationPeerFactory :
    Windows::IInspectable,
    impl::consume<IToggleMenuFlyoutItemAutomationPeerFactory>
{
    IToggleMenuFlyoutItemAutomationPeerFactory(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IToggleMenuFlyoutItemAutomationPeerFactory>(m_ptr); }
};

struct IToggleSwitchAutomationPeer :
    Windows::IInspectable,
    impl::consume<IToggleSwitchAutomationPeer>
{
    IToggleSwitchAutomationPeer(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IToggleSwitchAutomationPeer>(m_ptr); }
};

struct IToggleSwitchAutomationPeerFactory :
    Windows::IInspectable,
    impl::consume<IToggleSwitchAutomationPeerFactory>
{
    IToggleSwitchAutomationPeerFactory(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IToggleSwitchAutomationPeerFactory>(m_ptr); }
};

}

}
