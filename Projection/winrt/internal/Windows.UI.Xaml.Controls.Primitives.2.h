// C++ for the Windows Runtime v1.0.private
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "Windows.UI.Xaml.Controls.Primitives.1.h"
#include "Windows.UI.Xaml.1.h"
#include "Windows.UI.Xaml.Controls.1.h"
#include "Windows.UI.Xaml.Data.1.h"
#include "Windows.UI.Xaml.2.h"
#include "Windows.UI.Xaml.Controls.2.h"

WINRT_EXPORT namespace winrt {

namespace ABI::Windows::Foundation {

#ifndef WINRT_GENERIC_c50898f6_c536_5f47_8583_8b2c2438a13b
#define WINRT_GENERIC_c50898f6_c536_5f47_8583_8b2c2438a13b
template <> struct __declspec(uuid("c50898f6-c536-5f47-8583-8b2c2438a13b")) __declspec(novtable) EventHandler<Windows::IInspectable> : impl_EventHandler<Windows::IInspectable> {};
#endif


}

namespace ABI::Windows::Foundation::Collections {

#ifndef WINRT_GENERIC_a6487363_b074_5c60_ab16_866dce4ee54d
#define WINRT_GENERIC_a6487363_b074_5c60_ab16_866dce4ee54d
template <> struct __declspec(uuid("a6487363-b074-5c60-ab16-866dce4ee54d")) __declspec(novtable) IVectorView<Windows::IInspectable> : impl_IVectorView<Windows::IInspectable> {};
#endif


}

namespace ABI::Windows::Foundation {

#ifndef WINRT_GENERIC_3c00fd60_2950_5939_a21a_2d12c5a01b8a
#define WINRT_GENERIC_3c00fd60_2950_5939_a21a_2d12c5a01b8a
template <> struct __declspec(uuid("3c00fd60-2950-5939-a21a-2d12c5a01b8a")) __declspec(novtable) IReference<bool> : impl_IReference<bool> {};
#endif


}

namespace ABI::Windows::Foundation::Collections {

#ifndef WINRT_GENERIC_b32bdca4_5e52_5b27_bc5d_d66a1a268c2a
#define WINRT_GENERIC_b32bdca4_5e52_5b27_bc5d_d66a1a268c2a
template <> struct __declspec(uuid("b32bdca4-5e52-5b27-bc5d-d66a1a268c2a")) __declspec(novtable) IVector<Windows::IInspectable> : impl_IVector<Windows::IInspectable> {};
#endif

#ifndef WINRT_GENERIC_092b849b_60b1_52be_a44a_6fe8e933cbe4
#define WINRT_GENERIC_092b849b_60b1_52be_a44a_6fe8e933cbe4
template <> struct __declspec(uuid("092b849b-60b1-52be-a44a-6fe8e933cbe4")) __declspec(novtable) IIterable<Windows::IInspectable> : impl_IIterable<Windows::IInspectable> {};
#endif

#ifndef WINRT_GENERIC_7bca64fd_150c_5d50_b56b_9f4f474c5930
#define WINRT_GENERIC_7bca64fd_150c_5d50_b56b_9f4f474c5930
template <> struct __declspec(uuid("7bca64fd-150c-5d50-b56b-9f4f474c5930")) __declspec(novtable) IVectorView<float> : impl_IVectorView<float> {};
#endif


}

namespace ABI::Windows::Foundation {

#ifndef WINRT_GENERIC_96e17fbc_78c7_5560_ac3a_587f46db70d6
#define WINRT_GENERIC_96e17fbc_78c7_5560_ac3a_587f46db70d6
template <> struct __declspec(uuid("96e17fbc-78c7-5560-ac3a-587f46db70d6")) __declspec(novtable) TypedEventHandler<Windows::UI::Xaml::Controls::Primitives::FlyoutBase, Windows::UI::Xaml::Controls::Primitives::FlyoutBaseClosingEventArgs> : impl_TypedEventHandler<Windows::UI::Xaml::Controls::Primitives::FlyoutBase, Windows::UI::Xaml::Controls::Primitives::FlyoutBaseClosingEventArgs> {};
#endif


}

namespace ABI::Windows::Foundation::Collections {

#ifndef WINRT_GENERIC_44a94f2d_04f8_5091_b336_be7892dd10be
#define WINRT_GENERIC_44a94f2d_04f8_5091_b336_be7892dd10be
template <> struct __declspec(uuid("44a94f2d-04f8-5091-b336-be7892dd10be")) __declspec(novtable) IIterator<Windows::IInspectable> : impl_IIterator<Windows::IInspectable> {};
#endif

#ifndef WINRT_GENERIC_42614e61_b0aa_5e72_9354_2771db20b7a8
#define WINRT_GENERIC_42614e61_b0aa_5e72_9354_2771db20b7a8
template <> struct __declspec(uuid("42614e61-b0aa-5e72-9354-2771db20b7a8")) __declspec(novtable) IIterator<float> : impl_IIterator<float> {};
#endif

#ifndef WINRT_GENERIC_b01bee51_063a_5fda_bd72_d76637bb8cb8
#define WINRT_GENERIC_b01bee51_063a_5fda_bd72_d76637bb8cb8
template <> struct __declspec(uuid("b01bee51-063a-5fda-bd72-d76637bb8cb8")) __declspec(novtable) IIterable<float> : impl_IIterable<float> {};
#endif


}

namespace Windows::UI::Xaml::Controls::Primitives {

struct DragCompletedEventHandler : Windows::IUnknown
{
    DragCompletedEventHandler(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<DragCompletedEventHandler>(m_ptr); }
    template <typename L> DragCompletedEventHandler(L lambda);
    template <typename F> DragCompletedEventHandler (F * function);
    template <typename O, typename M> DragCompletedEventHandler(O * object, M method);
    void operator()(const Windows::IInspectable & sender, const Windows::UI::Xaml::Controls::Primitives::DragCompletedEventArgs & e) const;
};

struct DragDeltaEventHandler : Windows::IUnknown
{
    DragDeltaEventHandler(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<DragDeltaEventHandler>(m_ptr); }
    template <typename L> DragDeltaEventHandler(L lambda);
    template <typename F> DragDeltaEventHandler (F * function);
    template <typename O, typename M> DragDeltaEventHandler(O * object, M method);
    void operator()(const Windows::IInspectable & sender, const Windows::UI::Xaml::Controls::Primitives::DragDeltaEventArgs & e) const;
};

struct DragStartedEventHandler : Windows::IUnknown
{
    DragStartedEventHandler(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<DragStartedEventHandler>(m_ptr); }
    template <typename L> DragStartedEventHandler(L lambda);
    template <typename F> DragStartedEventHandler (F * function);
    template <typename O, typename M> DragStartedEventHandler(O * object, M method);
    void operator()(const Windows::IInspectable & sender, const Windows::UI::Xaml::Controls::Primitives::DragStartedEventArgs & e) const;
};

struct ItemsChangedEventHandler : Windows::IUnknown
{
    ItemsChangedEventHandler(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<ItemsChangedEventHandler>(m_ptr); }
    template <typename L> ItemsChangedEventHandler(L lambda);
    template <typename F> ItemsChangedEventHandler (F * function);
    template <typename O, typename M> ItemsChangedEventHandler(O * object, M method);
    void operator()(const Windows::IInspectable & sender, const Windows::UI::Xaml::Controls::Primitives::ItemsChangedEventArgs & e) const;
};

struct RangeBaseValueChangedEventHandler : Windows::IUnknown
{
    RangeBaseValueChangedEventHandler(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<RangeBaseValueChangedEventHandler>(m_ptr); }
    template <typename L> RangeBaseValueChangedEventHandler(L lambda);
    template <typename F> RangeBaseValueChangedEventHandler (F * function);
    template <typename O, typename M> RangeBaseValueChangedEventHandler(O * object, M method);
    void operator()(const Windows::IInspectable & sender, const Windows::UI::Xaml::Controls::Primitives::RangeBaseValueChangedEventArgs & e) const;
};

struct ScrollEventHandler : Windows::IUnknown
{
    ScrollEventHandler(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<ScrollEventHandler>(m_ptr); }
    template <typename L> ScrollEventHandler(L lambda);
    template <typename F> ScrollEventHandler (F * function);
    template <typename O, typename M> ScrollEventHandler(O * object, M method);
    void operator()(const Windows::IInspectable & sender, const Windows::UI::Xaml::Controls::Primitives::ScrollEventArgs & e) const;
};

struct IAppBarTemplateSettings :
    Windows::IInspectable,
    impl::consume<IAppBarTemplateSettings>
{
    IAppBarTemplateSettings(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IAppBarTemplateSettings>(m_ptr); }
};

struct IButtonBase :
    Windows::IInspectable,
    impl::consume<IButtonBase>
{
    IButtonBase(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IButtonBase>(m_ptr); }
};

struct IButtonBaseFactory :
    Windows::IInspectable,
    impl::consume<IButtonBaseFactory>
{
    IButtonBaseFactory(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IButtonBaseFactory>(m_ptr); }
};

struct IButtonBaseStatics :
    Windows::IInspectable,
    impl::consume<IButtonBaseStatics>
{
    IButtonBaseStatics(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IButtonBaseStatics>(m_ptr); }
};

struct ICalendarPanel :
    Windows::IInspectable,
    impl::consume<ICalendarPanel>
{
    ICalendarPanel(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<ICalendarPanel>(m_ptr); }
};

struct ICalendarViewTemplateSettings :
    Windows::IInspectable,
    impl::consume<ICalendarViewTemplateSettings>
{
    ICalendarViewTemplateSettings(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<ICalendarViewTemplateSettings>(m_ptr); }
};

struct ICarouselPanel :
    Windows::IInspectable,
    impl::consume<ICarouselPanel>
{
    ICarouselPanel(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<ICarouselPanel>(m_ptr); }
};

struct ICarouselPanelFactory :
    Windows::IInspectable,
    impl::consume<ICarouselPanelFactory>
{
    ICarouselPanelFactory(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<ICarouselPanelFactory>(m_ptr); }
};

struct IComboBoxTemplateSettings :
    Windows::IInspectable,
    impl::consume<IComboBoxTemplateSettings>
{
    IComboBoxTemplateSettings(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IComboBoxTemplateSettings>(m_ptr); }
};

struct IComboBoxTemplateSettings2 :
    Windows::IInspectable,
    impl::consume<IComboBoxTemplateSettings2>
{
    IComboBoxTemplateSettings2(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IComboBoxTemplateSettings2>(m_ptr); }
};

struct ICommandBarTemplateSettings :
    Windows::IInspectable,
    impl::consume<ICommandBarTemplateSettings>
{
    ICommandBarTemplateSettings(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<ICommandBarTemplateSettings>(m_ptr); }
};

struct ICommandBarTemplateSettings2 :
    Windows::IInspectable,
    impl::consume<ICommandBarTemplateSettings2>
{
    ICommandBarTemplateSettings2(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<ICommandBarTemplateSettings2>(m_ptr); }
};

struct ICommandBarTemplateSettings3 :
    Windows::IInspectable,
    impl::consume<ICommandBarTemplateSettings3>
{
    ICommandBarTemplateSettings3(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<ICommandBarTemplateSettings3>(m_ptr); }
};

struct IDragCompletedEventArgs :
    Windows::IInspectable,
    impl::consume<IDragCompletedEventArgs>
{
    IDragCompletedEventArgs(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IDragCompletedEventArgs>(m_ptr); }
};

struct IDragCompletedEventArgsFactory :
    Windows::IInspectable,
    impl::consume<IDragCompletedEventArgsFactory>
{
    IDragCompletedEventArgsFactory(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IDragCompletedEventArgsFactory>(m_ptr); }
};

struct IDragDeltaEventArgs :
    Windows::IInspectable,
    impl::consume<IDragDeltaEventArgs>
{
    IDragDeltaEventArgs(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IDragDeltaEventArgs>(m_ptr); }
};

struct IDragDeltaEventArgsFactory :
    Windows::IInspectable,
    impl::consume<IDragDeltaEventArgsFactory>
{
    IDragDeltaEventArgsFactory(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IDragDeltaEventArgsFactory>(m_ptr); }
};

struct IDragStartedEventArgs :
    Windows::IInspectable,
    impl::consume<IDragStartedEventArgs>
{
    IDragStartedEventArgs(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IDragStartedEventArgs>(m_ptr); }
};

struct IDragStartedEventArgsFactory :
    Windows::IInspectable,
    impl::consume<IDragStartedEventArgsFactory>
{
    IDragStartedEventArgsFactory(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IDragStartedEventArgsFactory>(m_ptr); }
};

struct IFlyoutBase :
    Windows::IInspectable,
    impl::consume<IFlyoutBase>
{
    IFlyoutBase(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IFlyoutBase>(m_ptr); }
};

struct IFlyoutBase2 :
    Windows::IInspectable,
    impl::consume<IFlyoutBase2>
{
    IFlyoutBase2(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IFlyoutBase2>(m_ptr); }
};

struct IFlyoutBaseClosingEventArgs :
    Windows::IInspectable,
    impl::consume<IFlyoutBaseClosingEventArgs>
{
    IFlyoutBaseClosingEventArgs(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IFlyoutBaseClosingEventArgs>(m_ptr); }
};

struct IFlyoutBaseFactory :
    Windows::IInspectable,
    impl::consume<IFlyoutBaseFactory>
{
    IFlyoutBaseFactory(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IFlyoutBaseFactory>(m_ptr); }
};

struct IFlyoutBaseOverrides :
    Windows::IInspectable,
    impl::consume<IFlyoutBaseOverrides>
{
    IFlyoutBaseOverrides(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IFlyoutBaseOverrides>(m_ptr); }
};

struct IFlyoutBaseStatics :
    Windows::IInspectable,
    impl::consume<IFlyoutBaseStatics>
{
    IFlyoutBaseStatics(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IFlyoutBaseStatics>(m_ptr); }
};

struct IFlyoutBaseStatics2 :
    Windows::IInspectable,
    impl::consume<IFlyoutBaseStatics2>
{
    IFlyoutBaseStatics2(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IFlyoutBaseStatics2>(m_ptr); }
};

struct IGeneratorPositionHelper :
    Windows::IInspectable,
    impl::consume<IGeneratorPositionHelper>
{
    IGeneratorPositionHelper(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IGeneratorPositionHelper>(m_ptr); }
};

struct IGeneratorPositionHelperStatics :
    Windows::IInspectable,
    impl::consume<IGeneratorPositionHelperStatics>
{
    IGeneratorPositionHelperStatics(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IGeneratorPositionHelperStatics>(m_ptr); }
};

struct IGridViewItemPresenter :
    Windows::IInspectable,
    impl::consume<IGridViewItemPresenter>
{
    IGridViewItemPresenter(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IGridViewItemPresenter>(m_ptr); }
};

struct IGridViewItemPresenterFactory :
    Windows::IInspectable,
    impl::consume<IGridViewItemPresenterFactory>
{
    IGridViewItemPresenterFactory(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IGridViewItemPresenterFactory>(m_ptr); }
};

struct IGridViewItemPresenterStatics :
    Windows::IInspectable,
    impl::consume<IGridViewItemPresenterStatics>
{
    IGridViewItemPresenterStatics(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IGridViewItemPresenterStatics>(m_ptr); }
};

struct IGridViewItemTemplateSettings :
    Windows::IInspectable,
    impl::consume<IGridViewItemTemplateSettings>
{
    IGridViewItemTemplateSettings(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IGridViewItemTemplateSettings>(m_ptr); }
};

struct IItemsChangedEventArgs :
    Windows::IInspectable,
    impl::consume<IItemsChangedEventArgs>
{
    IItemsChangedEventArgs(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IItemsChangedEventArgs>(m_ptr); }
};

struct IJumpListItemBackgroundConverter :
    Windows::IInspectable,
    impl::consume<IJumpListItemBackgroundConverter>
{
    IJumpListItemBackgroundConverter(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IJumpListItemBackgroundConverter>(m_ptr); }
};

struct IJumpListItemBackgroundConverterStatics :
    Windows::IInspectable,
    impl::consume<IJumpListItemBackgroundConverterStatics>
{
    IJumpListItemBackgroundConverterStatics(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IJumpListItemBackgroundConverterStatics>(m_ptr); }
};

struct IJumpListItemForegroundConverter :
    Windows::IInspectable,
    impl::consume<IJumpListItemForegroundConverter>
{
    IJumpListItemForegroundConverter(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IJumpListItemForegroundConverter>(m_ptr); }
};

struct IJumpListItemForegroundConverterStatics :
    Windows::IInspectable,
    impl::consume<IJumpListItemForegroundConverterStatics>
{
    IJumpListItemForegroundConverterStatics(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IJumpListItemForegroundConverterStatics>(m_ptr); }
};

struct ILayoutInformation :
    Windows::IInspectable,
    impl::consume<ILayoutInformation>
{
    ILayoutInformation(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<ILayoutInformation>(m_ptr); }
};

struct ILayoutInformationStatics :
    Windows::IInspectable,
    impl::consume<ILayoutInformationStatics>
{
    ILayoutInformationStatics(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<ILayoutInformationStatics>(m_ptr); }
};

struct IListViewItemPresenter :
    Windows::IInspectable,
    impl::consume<IListViewItemPresenter>
{
    IListViewItemPresenter(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IListViewItemPresenter>(m_ptr); }
};

struct IListViewItemPresenter2 :
    Windows::IInspectable,
    impl::consume<IListViewItemPresenter2>
{
    IListViewItemPresenter2(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IListViewItemPresenter2>(m_ptr); }
};

struct IListViewItemPresenterFactory :
    Windows::IInspectable,
    impl::consume<IListViewItemPresenterFactory>
{
    IListViewItemPresenterFactory(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IListViewItemPresenterFactory>(m_ptr); }
};

struct IListViewItemPresenterStatics :
    Windows::IInspectable,
    impl::consume<IListViewItemPresenterStatics>
{
    IListViewItemPresenterStatics(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IListViewItemPresenterStatics>(m_ptr); }
};

struct IListViewItemPresenterStatics2 :
    Windows::IInspectable,
    impl::consume<IListViewItemPresenterStatics2>
{
    IListViewItemPresenterStatics2(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IListViewItemPresenterStatics2>(m_ptr); }
};

struct IListViewItemTemplateSettings :
    Windows::IInspectable,
    impl::consume<IListViewItemTemplateSettings>
{
    IListViewItemTemplateSettings(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IListViewItemTemplateSettings>(m_ptr); }
};

struct ILoopingSelector :
    Windows::IInspectable,
    impl::consume<ILoopingSelector>
{
    ILoopingSelector(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<ILoopingSelector>(m_ptr); }
};

struct ILoopingSelectorItem :
    Windows::IInspectable,
    impl::consume<ILoopingSelectorItem>
{
    ILoopingSelectorItem(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<ILoopingSelectorItem>(m_ptr); }
};

struct ILoopingSelectorPanel :
    Windows::IInspectable,
    impl::consume<ILoopingSelectorPanel>
{
    ILoopingSelectorPanel(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<ILoopingSelectorPanel>(m_ptr); }
};

struct ILoopingSelectorStatics :
    Windows::IInspectable,
    impl::consume<ILoopingSelectorStatics>
{
    ILoopingSelectorStatics(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<ILoopingSelectorStatics>(m_ptr); }
};

struct IMenuFlyoutPresenterTemplateSettings :
    Windows::IInspectable,
    impl::consume<IMenuFlyoutPresenterTemplateSettings>
{
    IMenuFlyoutPresenterTemplateSettings(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IMenuFlyoutPresenterTemplateSettings>(m_ptr); }
};

struct IOrientedVirtualizingPanel :
    Windows::IInspectable,
    impl::consume<IOrientedVirtualizingPanel>
{
    IOrientedVirtualizingPanel(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IOrientedVirtualizingPanel>(m_ptr); }
};

struct IOrientedVirtualizingPanelFactory :
    Windows::IInspectable,
    impl::consume<IOrientedVirtualizingPanelFactory>
{
    IOrientedVirtualizingPanelFactory(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IOrientedVirtualizingPanelFactory>(m_ptr); }
};

struct IPickerFlyoutBase :
    Windows::IInspectable,
    impl::consume<IPickerFlyoutBase>
{
    IPickerFlyoutBase(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IPickerFlyoutBase>(m_ptr); }
};

struct IPickerFlyoutBaseFactory :
    Windows::IInspectable,
    impl::consume<IPickerFlyoutBaseFactory>
{
    IPickerFlyoutBaseFactory(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IPickerFlyoutBaseFactory>(m_ptr); }
};

struct IPickerFlyoutBaseOverrides :
    Windows::IInspectable,
    impl::consume<IPickerFlyoutBaseOverrides>
{
    IPickerFlyoutBaseOverrides(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IPickerFlyoutBaseOverrides>(m_ptr); }
};

struct IPickerFlyoutBaseStatics :
    Windows::IInspectable,
    impl::consume<IPickerFlyoutBaseStatics>
{
    IPickerFlyoutBaseStatics(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IPickerFlyoutBaseStatics>(m_ptr); }
};

struct IPivotHeaderItem :
    Windows::IInspectable,
    impl::consume<IPivotHeaderItem>
{
    IPivotHeaderItem(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IPivotHeaderItem>(m_ptr); }
};

struct IPivotHeaderItemFactory :
    Windows::IInspectable,
    impl::consume<IPivotHeaderItemFactory>
{
    IPivotHeaderItemFactory(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IPivotHeaderItemFactory>(m_ptr); }
};

struct IPivotHeaderPanel :
    Windows::IInspectable,
    impl::consume<IPivotHeaderPanel>
{
    IPivotHeaderPanel(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IPivotHeaderPanel>(m_ptr); }
};

struct IPivotPanel :
    Windows::IInspectable,
    impl::consume<IPivotPanel>
{
    IPivotPanel(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IPivotPanel>(m_ptr); }
};

struct IPopup :
    Windows::IInspectable,
    impl::consume<IPopup>
{
    IPopup(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IPopup>(m_ptr); }
};

struct IPopup2 :
    Windows::IInspectable,
    impl::consume<IPopup2>
{
    IPopup2(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IPopup2>(m_ptr); }
};

struct IPopupStatics :
    Windows::IInspectable,
    impl::consume<IPopupStatics>
{
    IPopupStatics(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IPopupStatics>(m_ptr); }
};

struct IPopupStatics2 :
    Windows::IInspectable,
    impl::consume<IPopupStatics2>
{
    IPopupStatics2(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IPopupStatics2>(m_ptr); }
};

struct IProgressBarTemplateSettings :
    Windows::IInspectable,
    impl::consume<IProgressBarTemplateSettings>
{
    IProgressBarTemplateSettings(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IProgressBarTemplateSettings>(m_ptr); }
};

struct IProgressRingTemplateSettings :
    Windows::IInspectable,
    impl::consume<IProgressRingTemplateSettings>
{
    IProgressRingTemplateSettings(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IProgressRingTemplateSettings>(m_ptr); }
};

struct IRangeBase :
    Windows::IInspectable,
    impl::consume<IRangeBase>
{
    IRangeBase(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IRangeBase>(m_ptr); }
};

struct IRangeBaseFactory :
    Windows::IInspectable,
    impl::consume<IRangeBaseFactory>
{
    IRangeBaseFactory(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IRangeBaseFactory>(m_ptr); }
};

struct IRangeBaseOverrides :
    Windows::IInspectable,
    impl::consume<IRangeBaseOverrides>
{
    IRangeBaseOverrides(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IRangeBaseOverrides>(m_ptr); }
};

struct IRangeBaseStatics :
    Windows::IInspectable,
    impl::consume<IRangeBaseStatics>
{
    IRangeBaseStatics(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IRangeBaseStatics>(m_ptr); }
};

struct IRangeBaseValueChangedEventArgs :
    Windows::IInspectable,
    impl::consume<IRangeBaseValueChangedEventArgs>
{
    IRangeBaseValueChangedEventArgs(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IRangeBaseValueChangedEventArgs>(m_ptr); }
};

struct IRepeatButton :
    Windows::IInspectable,
    impl::consume<IRepeatButton>
{
    IRepeatButton(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IRepeatButton>(m_ptr); }
};

struct IRepeatButtonStatics :
    Windows::IInspectable,
    impl::consume<IRepeatButtonStatics>
{
    IRepeatButtonStatics(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IRepeatButtonStatics>(m_ptr); }
};

struct IScrollBar :
    Windows::IInspectable,
    impl::consume<IScrollBar>
{
    IScrollBar(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IScrollBar>(m_ptr); }
};

struct IScrollBarStatics :
    Windows::IInspectable,
    impl::consume<IScrollBarStatics>
{
    IScrollBarStatics(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IScrollBarStatics>(m_ptr); }
};

struct IScrollEventArgs :
    Windows::IInspectable,
    impl::consume<IScrollEventArgs>
{
    IScrollEventArgs(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IScrollEventArgs>(m_ptr); }
};

struct IScrollSnapPointsInfo :
    Windows::IInspectable,
    impl::consume<IScrollSnapPointsInfo>
{
    IScrollSnapPointsInfo(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IScrollSnapPointsInfo>(m_ptr); }
};

struct ISelector :
    Windows::IInspectable,
    impl::consume<ISelector>
{
    ISelector(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<ISelector>(m_ptr); }
};

struct ISelectorFactory :
    Windows::IInspectable,
    impl::consume<ISelectorFactory>
{
    ISelectorFactory(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<ISelectorFactory>(m_ptr); }
};

struct ISelectorItem :
    Windows::IInspectable,
    impl::consume<ISelectorItem>
{
    ISelectorItem(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<ISelectorItem>(m_ptr); }
};

struct ISelectorItemFactory :
    Windows::IInspectable,
    impl::consume<ISelectorItemFactory>
{
    ISelectorItemFactory(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<ISelectorItemFactory>(m_ptr); }
};

struct ISelectorItemStatics :
    Windows::IInspectable,
    impl::consume<ISelectorItemStatics>
{
    ISelectorItemStatics(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<ISelectorItemStatics>(m_ptr); }
};

struct ISelectorStatics :
    Windows::IInspectable,
    impl::consume<ISelectorStatics>
{
    ISelectorStatics(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<ISelectorStatics>(m_ptr); }
};

struct ISettingsFlyoutTemplateSettings :
    Windows::IInspectable,
    impl::consume<ISettingsFlyoutTemplateSettings>
{
    ISettingsFlyoutTemplateSettings(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<ISettingsFlyoutTemplateSettings>(m_ptr); }
};

struct ISplitViewTemplateSettings :
    Windows::IInspectable,
    impl::consume<ISplitViewTemplateSettings>
{
    ISplitViewTemplateSettings(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<ISplitViewTemplateSettings>(m_ptr); }
};

struct IThumb :
    Windows::IInspectable,
    impl::consume<IThumb>
{
    IThumb(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IThumb>(m_ptr); }
};

struct IThumbStatics :
    Windows::IInspectable,
    impl::consume<IThumbStatics>
{
    IThumbStatics(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IThumbStatics>(m_ptr); }
};

struct ITickBar :
    Windows::IInspectable,
    impl::consume<ITickBar>
{
    ITickBar(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<ITickBar>(m_ptr); }
};

struct ITickBarStatics :
    Windows::IInspectable,
    impl::consume<ITickBarStatics>
{
    ITickBarStatics(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<ITickBarStatics>(m_ptr); }
};

struct IToggleButton :
    Windows::IInspectable,
    impl::consume<IToggleButton>
{
    IToggleButton(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IToggleButton>(m_ptr); }
};

struct IToggleButtonFactory :
    Windows::IInspectable,
    impl::consume<IToggleButtonFactory>
{
    IToggleButtonFactory(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IToggleButtonFactory>(m_ptr); }
};

struct IToggleButtonOverrides :
    Windows::IInspectable,
    impl::consume<IToggleButtonOverrides>
{
    IToggleButtonOverrides(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IToggleButtonOverrides>(m_ptr); }
};

struct IToggleButtonStatics :
    Windows::IInspectable,
    impl::consume<IToggleButtonStatics>
{
    IToggleButtonStatics(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IToggleButtonStatics>(m_ptr); }
};

struct IToggleSwitchTemplateSettings :
    Windows::IInspectable,
    impl::consume<IToggleSwitchTemplateSettings>
{
    IToggleSwitchTemplateSettings(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IToggleSwitchTemplateSettings>(m_ptr); }
};

struct IToolTipTemplateSettings :
    Windows::IInspectable,
    impl::consume<IToolTipTemplateSettings>
{
    IToolTipTemplateSettings(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IToolTipTemplateSettings>(m_ptr); }
};

}

}
