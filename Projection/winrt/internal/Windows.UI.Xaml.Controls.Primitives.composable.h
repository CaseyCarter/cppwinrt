// C++ for the Windows Runtime v1.29
// Copyright (c) 2016 Microsoft Corporation

#pragma once

#include "Windows.UI.Xaml.Controls.override.h"
#include "Windows.UI.Xaml.override.h"

WINRT_EXPORT namespace winrt {

namespace Windows::UI::Xaml::Controls::Primitives {

template <typename D, typename ... Interfaces> struct ButtonBaseT :
    overrides<D, Windows::UI::Xaml::Controls::IContentControlOverridesT<D>, Windows::UI::Xaml::IUIElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverrides2T<D>, Windows::UI::Xaml::Controls::IControlOverridesT<D>, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::Controls::IContentControl, Windows::UI::Xaml::Controls::IContentControl2, Windows::UI::Xaml::Controls::Primitives::IButtonBase, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IUIElement4, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::IFrameworkElement4, Windows::UI::Xaml::Controls::IControl, Windows::UI::Xaml::Controls::IControlProtected, Windows::UI::Xaml::Controls::IControl2, Windows::UI::Xaml::Controls::IControl3, Windows::UI::Xaml::Controls::IControl4>
{
    using composable = ButtonBase;

protected:

    ButtonBaseT()
    {
        GetActivationFactory<ButtonBase, IButtonBaseFactory>().CreateInstance(*this, m_inner);
    }
};

template <typename D, typename ... Interfaces> struct CarouselPanelT :
    overrides<D, Windows::UI::Xaml::Controls::IVirtualizingPanelOverridesT<D>, Windows::UI::Xaml::IUIElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverrides2T<D>, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::Controls::IPanel, Windows::UI::Xaml::Controls::IVirtualizingPanel, Windows::UI::Xaml::Controls::IVirtualizingPanelProtected, Windows::UI::Xaml::Controls::Primitives::IScrollSnapPointsInfo, Windows::UI::Xaml::Controls::Primitives::ICarouselPanel, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IUIElement4, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::IFrameworkElement4>
{
    using composable = CarouselPanel;

protected:

    CarouselPanelT()
    {
        GetActivationFactory<CarouselPanel, ICarouselPanelFactory>().CreateInstance(*this, m_inner);
    }
};

template <typename D, typename ... Interfaces> struct DragCompletedEventArgsT :
    overrides<D, Windows::IInspectable, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::Controls::Primitives::IDragCompletedEventArgs, Windows::UI::Xaml::IRoutedEventArgs>
{
    using composable = DragCompletedEventArgs;

protected:

    DragCompletedEventArgsT(double horizontalChange, double verticalChange, bool canceled)
    {
        GetActivationFactory<DragCompletedEventArgs, IDragCompletedEventArgsFactory>().CreateInstanceWithHorizontalChangeVerticalChangeAndCanceled(horizontalChange, verticalChange, canceled, *this, m_inner);
    }
};

template <typename D, typename ... Interfaces> struct DragDeltaEventArgsT :
    overrides<D, Windows::IInspectable, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::Controls::Primitives::IDragDeltaEventArgs, Windows::UI::Xaml::IRoutedEventArgs>
{
    using composable = DragDeltaEventArgs;

protected:

    DragDeltaEventArgsT(double horizontalChange, double verticalChange)
    {
        GetActivationFactory<DragDeltaEventArgs, IDragDeltaEventArgsFactory>().CreateInstanceWithHorizontalChangeAndVerticalChange(horizontalChange, verticalChange, *this, m_inner);
    }
};

template <typename D, typename ... Interfaces> struct DragStartedEventArgsT :
    overrides<D, Windows::IInspectable, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::Controls::Primitives::IDragStartedEventArgs, Windows::UI::Xaml::IRoutedEventArgs>
{
    using composable = DragStartedEventArgs;

protected:

    DragStartedEventArgsT(double horizontalOffset, double verticalOffset)
    {
        GetActivationFactory<DragStartedEventArgs, IDragStartedEventArgsFactory>().CreateInstanceWithHorizontalOffsetAndVerticalOffset(horizontalOffset, verticalOffset, *this, m_inner);
    }
};

template <typename D, typename ... Interfaces> struct FlyoutBaseT :
    overrides<D, Windows::UI::Xaml::Controls::Primitives::IFlyoutBaseOverridesT<D>, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Controls::Primitives::IFlyoutBase, Windows::UI::Xaml::Controls::Primitives::IFlyoutBase2>
{
    using composable = FlyoutBase;

protected:

    FlyoutBaseT()
    {
        GetActivationFactory<FlyoutBase, IFlyoutBaseFactory>().CreateInstance(*this, m_inner);
    }
};

template <typename D, typename ... Interfaces> struct GridViewItemPresenterT :
    overrides<D, Windows::UI::Xaml::Controls::IContentPresenterOverridesT<D>, Windows::UI::Xaml::IUIElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverrides2T<D>, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::Controls::IContentPresenter, Windows::UI::Xaml::Controls::IContentPresenter2, Windows::UI::Xaml::Controls::IContentPresenter3, Windows::UI::Xaml::Controls::IContentPresenter4, Windows::UI::Xaml::Controls::Primitives::IGridViewItemPresenter, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IUIElement4, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::IFrameworkElement4>
{
    using composable = GridViewItemPresenter;

protected:

    GridViewItemPresenterT()
    {
        GetActivationFactory<GridViewItemPresenter, IGridViewItemPresenterFactory>().CreateInstance(*this, m_inner);
    }
};

template <typename D, typename ... Interfaces> struct ListViewItemPresenterT :
    overrides<D, Windows::UI::Xaml::Controls::IContentPresenterOverridesT<D>, Windows::UI::Xaml::IUIElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverrides2T<D>, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::Controls::IContentPresenter, Windows::UI::Xaml::Controls::IContentPresenter2, Windows::UI::Xaml::Controls::IContentPresenter3, Windows::UI::Xaml::Controls::IContentPresenter4, Windows::UI::Xaml::Controls::Primitives::IListViewItemPresenter, Windows::UI::Xaml::Controls::Primitives::IListViewItemPresenter2, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IUIElement4, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::IFrameworkElement4>
{
    using composable = ListViewItemPresenter;

protected:

    ListViewItemPresenterT()
    {
        GetActivationFactory<ListViewItemPresenter, IListViewItemPresenterFactory>().CreateInstance(*this, m_inner);
    }
};

template <typename D, typename ... Interfaces> struct PickerFlyoutBaseT :
    overrides<D, Windows::UI::Xaml::Controls::Primitives::IFlyoutBaseOverridesT<D>, Windows::UI::Xaml::Controls::Primitives::IPickerFlyoutBaseOverridesT<D>, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Controls::Primitives::IFlyoutBase, Windows::UI::Xaml::Controls::Primitives::IFlyoutBase2, Windows::UI::Xaml::Controls::Primitives::IPickerFlyoutBase>
{
    using composable = PickerFlyoutBase;

protected:

    PickerFlyoutBaseT()
    {
        GetActivationFactory<PickerFlyoutBase, IPickerFlyoutBaseFactory>().CreateInstance(*this, m_inner);
    }
};

template <typename D, typename ... Interfaces> struct PivotHeaderItemT :
    overrides<D, Windows::UI::Xaml::Controls::IContentControlOverridesT<D>, Windows::UI::Xaml::IUIElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverrides2T<D>, Windows::UI::Xaml::Controls::IControlOverridesT<D>, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::Controls::IContentControl, Windows::UI::Xaml::Controls::IContentControl2, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IUIElement4, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::IFrameworkElement4, Windows::UI::Xaml::Controls::IControl, Windows::UI::Xaml::Controls::IControlProtected, Windows::UI::Xaml::Controls::IControl2, Windows::UI::Xaml::Controls::IControl3, Windows::UI::Xaml::Controls::IControl4, Windows::UI::Xaml::Controls::Primitives::IPivotHeaderItem>
{
    using composable = PivotHeaderItem;

protected:

    PivotHeaderItemT()
    {
        GetActivationFactory<PivotHeaderItem, IPivotHeaderItemFactory>().CreateInstance(*this, m_inner);
    }
};

template <typename D, typename ... Interfaces> struct RangeBaseT :
    overrides<D, Windows::UI::Xaml::Controls::Primitives::IRangeBaseOverridesT<D>, Windows::UI::Xaml::IUIElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverrides2T<D>, Windows::UI::Xaml::Controls::IControlOverridesT<D>, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::Controls::Primitives::IRangeBase, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IUIElement4, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::IFrameworkElement4, Windows::UI::Xaml::Controls::IControl, Windows::UI::Xaml::Controls::IControlProtected, Windows::UI::Xaml::Controls::IControl2, Windows::UI::Xaml::Controls::IControl3, Windows::UI::Xaml::Controls::IControl4>
{
    using composable = RangeBase;

protected:

    RangeBaseT()
    {
        GetActivationFactory<RangeBase, IRangeBaseFactory>().CreateInstance(*this, m_inner);
    }
};

template <typename D, typename ... Interfaces> struct SelectorItemT :
    overrides<D, Windows::UI::Xaml::Controls::IContentControlOverridesT<D>, Windows::UI::Xaml::IUIElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverrides2T<D>, Windows::UI::Xaml::Controls::IControlOverridesT<D>, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::Controls::IContentControl, Windows::UI::Xaml::Controls::IContentControl2, Windows::UI::Xaml::Controls::Primitives::ISelectorItem, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IUIElement4, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::IFrameworkElement4, Windows::UI::Xaml::Controls::IControl, Windows::UI::Xaml::Controls::IControlProtected, Windows::UI::Xaml::Controls::IControl2, Windows::UI::Xaml::Controls::IControl3, Windows::UI::Xaml::Controls::IControl4>
{
    using composable = SelectorItem;

protected:

    SelectorItemT()
    {
        GetActivationFactory<SelectorItem, ISelectorItemFactory>().CreateInstance(*this, m_inner);
    }
};

template <typename D, typename ... Interfaces> struct ToggleButtonT :
    overrides<D, Windows::UI::Xaml::Controls::IContentControlOverridesT<D>, Windows::UI::Xaml::Controls::Primitives::IToggleButtonOverridesT<D>, Windows::UI::Xaml::IUIElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverrides2T<D>, Windows::UI::Xaml::Controls::IControlOverridesT<D>, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::Controls::IContentControl, Windows::UI::Xaml::Controls::IContentControl2, Windows::UI::Xaml::Controls::Primitives::IButtonBase, Windows::UI::Xaml::Controls::Primitives::IToggleButton, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IUIElement4, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::IFrameworkElement4, Windows::UI::Xaml::Controls::IControl, Windows::UI::Xaml::Controls::IControlProtected, Windows::UI::Xaml::Controls::IControl2, Windows::UI::Xaml::Controls::IControl3, Windows::UI::Xaml::Controls::IControl4>
{
    using composable = ToggleButton;

protected:

    ToggleButtonT()
    {
        GetActivationFactory<ToggleButton, IToggleButtonFactory>().CreateInstance(*this, m_inner);
    }
};

}

}
