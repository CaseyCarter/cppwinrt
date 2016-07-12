// C++ for the Windows Runtime v1.29
// Copyright (c) 2016 Microsoft Corporation

#pragma once

#include "Windows.UI.Xaml.Controls.Primitives.override.h"
#include "Windows.UI.Xaml.override.h"

WINRT_EXPORT namespace winrt {

namespace Windows::UI::Xaml::Controls {

template <typename D, typename ... Interfaces> struct AppBarT :
    overrides<D, Windows::UI::Xaml::Controls::IContentControlOverridesT<D>, Windows::UI::Xaml::Controls::IAppBarOverridesT<D>, Windows::UI::Xaml::Controls::IAppBarOverrides3T<D>, Windows::UI::Xaml::IUIElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverrides2T<D>, Windows::UI::Xaml::Controls::IControlOverridesT<D>, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::Controls::IContentControl, Windows::UI::Xaml::Controls::IContentControl2, Windows::UI::Xaml::Controls::IAppBar, Windows::UI::Xaml::Controls::IAppBar2, Windows::UI::Xaml::Controls::IAppBar3, Windows::UI::Xaml::Controls::IAppBar4, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IUIElement4, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::IFrameworkElement4, Windows::UI::Xaml::Controls::IControl, Windows::UI::Xaml::Controls::IControlProtected, Windows::UI::Xaml::Controls::IControl2, Windows::UI::Xaml::Controls::IControl3, Windows::UI::Xaml::Controls::IControl4>
{
    using composable = AppBar;

protected:

    AppBarT()
    {
        GetActivationFactory<AppBar, IAppBarFactory>().CreateInstance(*this, m_inner);
    }
};

template <typename D, typename ... Interfaces> struct AppBarButtonT :
    overrides<D, Windows::UI::Xaml::Controls::IContentControlOverridesT<D>, Windows::UI::Xaml::IUIElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverrides2T<D>, Windows::UI::Xaml::Controls::IControlOverridesT<D>, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::Controls::IContentControl, Windows::UI::Xaml::Controls::IContentControl2, Windows::UI::Xaml::Controls::IButton, Windows::UI::Xaml::Controls::IButtonWithFlyout, Windows::UI::Xaml::Controls::Primitives::IButtonBase, Windows::UI::Xaml::Controls::ICommandBarElement, Windows::UI::Xaml::Controls::ICommandBarElement2, Windows::UI::Xaml::Controls::IAppBarButton, Windows::UI::Xaml::Controls::IAppBarButton3, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IUIElement4, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::IFrameworkElement4, Windows::UI::Xaml::Controls::IControl, Windows::UI::Xaml::Controls::IControlProtected, Windows::UI::Xaml::Controls::IControl2, Windows::UI::Xaml::Controls::IControl3, Windows::UI::Xaml::Controls::IControl4>
{
    using composable = AppBarButton;

protected:

    AppBarButtonT()
    {
        GetActivationFactory<AppBarButton, IAppBarButtonFactory>().CreateInstance(*this, m_inner);
    }
};

template <typename D, typename ... Interfaces> struct AppBarSeparatorT :
    overrides<D, Windows::UI::Xaml::IUIElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverrides2T<D>, Windows::UI::Xaml::Controls::IControlOverridesT<D>, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::Controls::ICommandBarElement, Windows::UI::Xaml::Controls::ICommandBarElement2, Windows::UI::Xaml::Controls::IAppBarSeparator, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IUIElement4, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::IFrameworkElement4, Windows::UI::Xaml::Controls::IControl, Windows::UI::Xaml::Controls::IControlProtected, Windows::UI::Xaml::Controls::IControl2, Windows::UI::Xaml::Controls::IControl3, Windows::UI::Xaml::Controls::IControl4>
{
    using composable = AppBarSeparator;

protected:

    AppBarSeparatorT()
    {
        GetActivationFactory<AppBarSeparator, IAppBarSeparatorFactory>().CreateInstance(*this, m_inner);
    }
};

template <typename D, typename ... Interfaces> struct AppBarToggleButtonT :
    overrides<D, Windows::UI::Xaml::Controls::IContentControlOverridesT<D>, Windows::UI::Xaml::Controls::Primitives::IToggleButtonOverridesT<D>, Windows::UI::Xaml::IUIElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverrides2T<D>, Windows::UI::Xaml::Controls::IControlOverridesT<D>, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::Controls::IContentControl, Windows::UI::Xaml::Controls::IContentControl2, Windows::UI::Xaml::Controls::Primitives::IButtonBase, Windows::UI::Xaml::Controls::Primitives::IToggleButton, Windows::UI::Xaml::Controls::ICommandBarElement, Windows::UI::Xaml::Controls::ICommandBarElement2, Windows::UI::Xaml::Controls::IAppBarToggleButton, Windows::UI::Xaml::Controls::IAppBarToggleButton3, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IUIElement4, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::IFrameworkElement4, Windows::UI::Xaml::Controls::IControl, Windows::UI::Xaml::Controls::IControlProtected, Windows::UI::Xaml::Controls::IControl2, Windows::UI::Xaml::Controls::IControl3, Windows::UI::Xaml::Controls::IControl4>
{
    using composable = AppBarToggleButton;

protected:

    AppBarToggleButtonT()
    {
        GetActivationFactory<AppBarToggleButton, IAppBarToggleButtonFactory>().CreateInstance(*this, m_inner);
    }
};

template <typename D, typename ... Interfaces> struct BitmapIconT :
    overrides<D, Windows::UI::Xaml::IUIElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverrides2T<D>, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::Controls::IIconElement, Windows::UI::Xaml::Controls::IBitmapIcon, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IUIElement4, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::IFrameworkElement4>
{
    using composable = BitmapIcon;

protected:

    BitmapIconT()
    {
        GetActivationFactory<BitmapIcon, IBitmapIconFactory>().CreateInstance(*this, m_inner);
    }
};

template <typename D, typename ... Interfaces> struct ButtonT :
    overrides<D, Windows::UI::Xaml::Controls::IContentControlOverridesT<D>, Windows::UI::Xaml::IUIElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverrides2T<D>, Windows::UI::Xaml::Controls::IControlOverridesT<D>, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::Controls::IContentControl, Windows::UI::Xaml::Controls::IContentControl2, Windows::UI::Xaml::Controls::IButton, Windows::UI::Xaml::Controls::IButtonWithFlyout, Windows::UI::Xaml::Controls::Primitives::IButtonBase, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IUIElement4, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::IFrameworkElement4, Windows::UI::Xaml::Controls::IControl, Windows::UI::Xaml::Controls::IControlProtected, Windows::UI::Xaml::Controls::IControl2, Windows::UI::Xaml::Controls::IControl3, Windows::UI::Xaml::Controls::IControl4>
{
    using composable = Button;

protected:

    ButtonT()
    {
        GetActivationFactory<Button, IButtonFactory>().CreateInstance(*this, m_inner);
    }
};

template <typename D, typename ... Interfaces> struct CalendarDatePickerT :
    overrides<D, Windows::UI::Xaml::IUIElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverrides2T<D>, Windows::UI::Xaml::Controls::IControlOverridesT<D>, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::Controls::ICalendarDatePicker, Windows::UI::Xaml::Controls::ICalendarDatePicker2, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IUIElement4, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::IFrameworkElement4, Windows::UI::Xaml::Controls::IControl, Windows::UI::Xaml::Controls::IControlProtected, Windows::UI::Xaml::Controls::IControl2, Windows::UI::Xaml::Controls::IControl3, Windows::UI::Xaml::Controls::IControl4>
{
    using composable = CalendarDatePicker;

protected:

    CalendarDatePickerT()
    {
        GetActivationFactory<CalendarDatePicker, ICalendarDatePickerFactory>().CreateInstance(*this, m_inner);
    }
};

template <typename D, typename ... Interfaces> struct CalendarViewT :
    overrides<D, Windows::UI::Xaml::IUIElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverrides2T<D>, Windows::UI::Xaml::Controls::IControlOverridesT<D>, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::Controls::ICalendarView, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IUIElement4, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::IFrameworkElement4, Windows::UI::Xaml::Controls::IControl, Windows::UI::Xaml::Controls::IControlProtected, Windows::UI::Xaml::Controls::IControl2, Windows::UI::Xaml::Controls::IControl3, Windows::UI::Xaml::Controls::IControl4>
{
    using composable = CalendarView;

protected:

    CalendarViewT()
    {
        GetActivationFactory<CalendarView, ICalendarViewFactory>().CreateInstance(*this, m_inner);
    }
};

template <typename D, typename ... Interfaces> struct CalendarViewDayItemT :
    overrides<D, Windows::UI::Xaml::IUIElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverrides2T<D>, Windows::UI::Xaml::Controls::IControlOverridesT<D>, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::Controls::ICalendarViewDayItem, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IUIElement4, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::IFrameworkElement4, Windows::UI::Xaml::Controls::IControl, Windows::UI::Xaml::Controls::IControlProtected, Windows::UI::Xaml::Controls::IControl2, Windows::UI::Xaml::Controls::IControl3, Windows::UI::Xaml::Controls::IControl4>
{
    using composable = CalendarViewDayItem;

protected:

    CalendarViewDayItemT()
    {
        GetActivationFactory<CalendarViewDayItem, ICalendarViewDayItemFactory>().CreateInstance(*this, m_inner);
    }
};

template <typename D, typename ... Interfaces> struct CanvasT :
    overrides<D, Windows::UI::Xaml::IUIElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverrides2T<D>, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::Controls::IPanel, Windows::UI::Xaml::Controls::ICanvas, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IUIElement4, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::IFrameworkElement4>
{
    using composable = Canvas;

protected:

    CanvasT()
    {
        GetActivationFactory<Canvas, ICanvasFactory>().CreateInstance(*this, m_inner);
    }
};

template <typename D, typename ... Interfaces> struct CheckBoxT :
    overrides<D, Windows::UI::Xaml::Controls::IContentControlOverridesT<D>, Windows::UI::Xaml::Controls::Primitives::IToggleButtonOverridesT<D>, Windows::UI::Xaml::IUIElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverrides2T<D>, Windows::UI::Xaml::Controls::IControlOverridesT<D>, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::Controls::IContentControl, Windows::UI::Xaml::Controls::IContentControl2, Windows::UI::Xaml::Controls::ICheckBox, Windows::UI::Xaml::Controls::Primitives::IButtonBase, Windows::UI::Xaml::Controls::Primitives::IToggleButton, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IUIElement4, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::IFrameworkElement4, Windows::UI::Xaml::Controls::IControl, Windows::UI::Xaml::Controls::IControlProtected, Windows::UI::Xaml::Controls::IControl2, Windows::UI::Xaml::Controls::IControl3, Windows::UI::Xaml::Controls::IControl4>
{
    using composable = CheckBox;

protected:

    CheckBoxT()
    {
        GetActivationFactory<CheckBox, ICheckBoxFactory>().CreateInstance(*this, m_inner);
    }
};

template <typename D, typename ... Interfaces> struct ComboBoxT :
    overrides<D, Windows::UI::Xaml::Controls::IItemsControlOverridesT<D>, Windows::UI::Xaml::Controls::IComboBoxOverridesT<D>, Windows::UI::Xaml::IUIElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverrides2T<D>, Windows::UI::Xaml::Controls::IControlOverridesT<D>, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::Controls::IItemContainerMapping, Windows::UI::Xaml::Controls::IItemsControl, Windows::UI::Xaml::Controls::IItemsControl2, Windows::UI::Xaml::Controls::IItemsControl3, Windows::UI::Xaml::Controls::IComboBox, Windows::UI::Xaml::Controls::IComboBox2, Windows::UI::Xaml::Controls::IComboBox3, Windows::UI::Xaml::Controls::Primitives::ISelector, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IUIElement4, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::IFrameworkElement4, Windows::UI::Xaml::Controls::IControl, Windows::UI::Xaml::Controls::IControlProtected, Windows::UI::Xaml::Controls::IControl2, Windows::UI::Xaml::Controls::IControl3, Windows::UI::Xaml::Controls::IControl4>
{
    using composable = ComboBox;

protected:

    ComboBoxT()
    {
        GetActivationFactory<ComboBox, IComboBoxFactory>().CreateInstance(*this, m_inner);
    }
};

template <typename D, typename ... Interfaces> struct ComboBoxItemT :
    overrides<D, Windows::UI::Xaml::Controls::IContentControlOverridesT<D>, Windows::UI::Xaml::IUIElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverrides2T<D>, Windows::UI::Xaml::Controls::IControlOverridesT<D>, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::Controls::IContentControl, Windows::UI::Xaml::Controls::IContentControl2, Windows::UI::Xaml::Controls::IComboBoxItem, Windows::UI::Xaml::Controls::Primitives::ISelectorItem, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IUIElement4, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::IFrameworkElement4, Windows::UI::Xaml::Controls::IControl, Windows::UI::Xaml::Controls::IControlProtected, Windows::UI::Xaml::Controls::IControl2, Windows::UI::Xaml::Controls::IControl3, Windows::UI::Xaml::Controls::IControl4>
{
    using composable = ComboBoxItem;

protected:

    ComboBoxItemT()
    {
        GetActivationFactory<ComboBoxItem, IComboBoxItemFactory>().CreateInstance(*this, m_inner);
    }
};

template <typename D, typename ... Interfaces> struct CommandBarT :
    overrides<D, Windows::UI::Xaml::Controls::IContentControlOverridesT<D>, Windows::UI::Xaml::Controls::IAppBarOverridesT<D>, Windows::UI::Xaml::Controls::IAppBarOverrides3T<D>, Windows::UI::Xaml::IUIElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverrides2T<D>, Windows::UI::Xaml::Controls::IControlOverridesT<D>, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::Controls::IContentControl, Windows::UI::Xaml::Controls::IContentControl2, Windows::UI::Xaml::Controls::IAppBar, Windows::UI::Xaml::Controls::IAppBar2, Windows::UI::Xaml::Controls::IAppBar3, Windows::UI::Xaml::Controls::IAppBar4, Windows::UI::Xaml::Controls::ICommandBar, Windows::UI::Xaml::Controls::ICommandBar2, Windows::UI::Xaml::Controls::ICommandBar3, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IUIElement4, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::IFrameworkElement4, Windows::UI::Xaml::Controls::IControl, Windows::UI::Xaml::Controls::IControlProtected, Windows::UI::Xaml::Controls::IControl2, Windows::UI::Xaml::Controls::IControl3, Windows::UI::Xaml::Controls::IControl4>
{
    using composable = CommandBar;

protected:

    CommandBarT()
    {
        GetActivationFactory<CommandBar, ICommandBarFactory>().CreateInstance(*this, m_inner);
    }
};

template <typename D, typename ... Interfaces> struct CommandBarOverflowPresenterT :
    overrides<D, Windows::UI::Xaml::Controls::IItemsControlOverridesT<D>, Windows::UI::Xaml::IUIElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverrides2T<D>, Windows::UI::Xaml::Controls::IControlOverridesT<D>, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::Controls::IItemContainerMapping, Windows::UI::Xaml::Controls::IItemsControl, Windows::UI::Xaml::Controls::IItemsControl2, Windows::UI::Xaml::Controls::IItemsControl3, Windows::UI::Xaml::Controls::ICommandBarOverflowPresenter, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IUIElement4, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::IFrameworkElement4, Windows::UI::Xaml::Controls::IControl, Windows::UI::Xaml::Controls::IControlProtected, Windows::UI::Xaml::Controls::IControl2, Windows::UI::Xaml::Controls::IControl3, Windows::UI::Xaml::Controls::IControl4>
{
    using composable = CommandBarOverflowPresenter;

protected:

    CommandBarOverflowPresenterT()
    {
        GetActivationFactory<CommandBarOverflowPresenter, ICommandBarOverflowPresenterFactory>().CreateInstance(*this, m_inner);
    }
};

template <typename D, typename ... Interfaces> struct ContentControlT :
    overrides<D, Windows::UI::Xaml::Controls::IContentControlOverridesT<D>, Windows::UI::Xaml::IUIElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverrides2T<D>, Windows::UI::Xaml::Controls::IControlOverridesT<D>, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::Controls::IContentControl, Windows::UI::Xaml::Controls::IContentControl2, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IUIElement4, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::IFrameworkElement4, Windows::UI::Xaml::Controls::IControl, Windows::UI::Xaml::Controls::IControlProtected, Windows::UI::Xaml::Controls::IControl2, Windows::UI::Xaml::Controls::IControl3, Windows::UI::Xaml::Controls::IControl4>
{
    using composable = ContentControl;

protected:

    ContentControlT()
    {
        GetActivationFactory<ContentControl, IContentControlFactory>().CreateInstance(*this, m_inner);
    }
};

template <typename D, typename ... Interfaces> struct ContentDialogT :
    overrides<D, Windows::UI::Xaml::Controls::IContentControlOverridesT<D>, Windows::UI::Xaml::IUIElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverrides2T<D>, Windows::UI::Xaml::Controls::IControlOverridesT<D>, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::Controls::IContentControl, Windows::UI::Xaml::Controls::IContentControl2, Windows::UI::Xaml::Controls::IContentDialog, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IUIElement4, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::IFrameworkElement4, Windows::UI::Xaml::Controls::IControl, Windows::UI::Xaml::Controls::IControlProtected, Windows::UI::Xaml::Controls::IControl2, Windows::UI::Xaml::Controls::IControl3, Windows::UI::Xaml::Controls::IControl4>
{
    using composable = ContentDialog;

protected:

    ContentDialogT()
    {
        GetActivationFactory<ContentDialog, IContentDialogFactory>().CreateInstance(*this, m_inner);
    }
};

template <typename D, typename ... Interfaces> struct ContentPresenterT :
    overrides<D, Windows::UI::Xaml::Controls::IContentPresenterOverridesT<D>, Windows::UI::Xaml::IUIElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverrides2T<D>, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::Controls::IContentPresenter, Windows::UI::Xaml::Controls::IContentPresenter2, Windows::UI::Xaml::Controls::IContentPresenter3, Windows::UI::Xaml::Controls::IContentPresenter4, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IUIElement4, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::IFrameworkElement4>
{
    using composable = ContentPresenter;

protected:

    ContentPresenterT()
    {
        GetActivationFactory<ContentPresenter, IContentPresenterFactory>().CreateInstance(*this, m_inner);
    }
};

template <typename D, typename ... Interfaces> struct ControlT :
    overrides<D, Windows::UI::Xaml::IUIElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverrides2T<D>, Windows::UI::Xaml::Controls::IControlOverridesT<D>, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IUIElement4, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::IFrameworkElement4, Windows::UI::Xaml::Controls::IControl, Windows::UI::Xaml::Controls::IControlProtected, Windows::UI::Xaml::Controls::IControl2, Windows::UI::Xaml::Controls::IControl3, Windows::UI::Xaml::Controls::IControl4>
{
    using composable = Control;

protected:

    ControlT()
    {
        GetActivationFactory<Control, IControlFactory>().CreateInstance(*this, m_inner);
    }
};

template <typename D, typename ... Interfaces> struct DataTemplateSelectorT :
    overrides<D, Windows::UI::Xaml::Controls::IDataTemplateSelectorOverridesT<D>, Windows::UI::Xaml::Controls::IDataTemplateSelectorOverrides2T<D>, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::Controls::IDataTemplateSelector, Windows::UI::Xaml::Controls::IDataTemplateSelector2>
{
    using composable = DataTemplateSelector;

protected:

    DataTemplateSelectorT()
    {
        GetActivationFactory<DataTemplateSelector, IDataTemplateSelectorFactory>().CreateInstance(*this, m_inner);
    }
};

template <typename D, typename ... Interfaces> struct DatePickerT :
    overrides<D, Windows::UI::Xaml::IUIElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverrides2T<D>, Windows::UI::Xaml::Controls::IControlOverridesT<D>, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::Controls::IDatePicker, Windows::UI::Xaml::Controls::IDatePicker2, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IUIElement4, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::IFrameworkElement4, Windows::UI::Xaml::Controls::IControl, Windows::UI::Xaml::Controls::IControlProtected, Windows::UI::Xaml::Controls::IControl2, Windows::UI::Xaml::Controls::IControl3, Windows::UI::Xaml::Controls::IControl4>
{
    using composable = DatePicker;

protected:

    DatePickerT()
    {
        GetActivationFactory<DatePicker, IDatePickerFactory>().CreateInstance(*this, m_inner);
    }
};

template <typename D, typename ... Interfaces> struct FlipViewT :
    overrides<D, Windows::UI::Xaml::Controls::IItemsControlOverridesT<D>, Windows::UI::Xaml::IUIElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverrides2T<D>, Windows::UI::Xaml::Controls::IControlOverridesT<D>, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::Controls::IItemContainerMapping, Windows::UI::Xaml::Controls::IItemsControl, Windows::UI::Xaml::Controls::IItemsControl2, Windows::UI::Xaml::Controls::IItemsControl3, Windows::UI::Xaml::Controls::IFlipView, Windows::UI::Xaml::Controls::IFlipView2, Windows::UI::Xaml::Controls::Primitives::ISelector, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IUIElement4, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::IFrameworkElement4, Windows::UI::Xaml::Controls::IControl, Windows::UI::Xaml::Controls::IControlProtected, Windows::UI::Xaml::Controls::IControl2, Windows::UI::Xaml::Controls::IControl3, Windows::UI::Xaml::Controls::IControl4>
{
    using composable = FlipView;

protected:

    FlipViewT()
    {
        GetActivationFactory<FlipView, IFlipViewFactory>().CreateInstance(*this, m_inner);
    }
};

template <typename D, typename ... Interfaces> struct FlipViewItemT :
    overrides<D, Windows::UI::Xaml::Controls::IContentControlOverridesT<D>, Windows::UI::Xaml::IUIElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverrides2T<D>, Windows::UI::Xaml::Controls::IControlOverridesT<D>, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::Controls::IContentControl, Windows::UI::Xaml::Controls::IContentControl2, Windows::UI::Xaml::Controls::IFlipViewItem, Windows::UI::Xaml::Controls::Primitives::ISelectorItem, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IUIElement4, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::IFrameworkElement4, Windows::UI::Xaml::Controls::IControl, Windows::UI::Xaml::Controls::IControlProtected, Windows::UI::Xaml::Controls::IControl2, Windows::UI::Xaml::Controls::IControl3, Windows::UI::Xaml::Controls::IControl4>
{
    using composable = FlipViewItem;

protected:

    FlipViewItemT()
    {
        GetActivationFactory<FlipViewItem, IFlipViewItemFactory>().CreateInstance(*this, m_inner);
    }
};

template <typename D, typename ... Interfaces> struct FlyoutT :
    overrides<D, Windows::UI::Xaml::Controls::Primitives::IFlyoutBaseOverridesT<D>, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::Controls::IFlyout, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Controls::Primitives::IFlyoutBase, Windows::UI::Xaml::Controls::Primitives::IFlyoutBase2>
{
    using composable = Flyout;

protected:

    FlyoutT()
    {
        GetActivationFactory<Flyout, IFlyoutFactory>().CreateInstance(*this, m_inner);
    }
};

template <typename D, typename ... Interfaces> struct FlyoutPresenterT :
    overrides<D, Windows::UI::Xaml::Controls::IContentControlOverridesT<D>, Windows::UI::Xaml::IUIElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverrides2T<D>, Windows::UI::Xaml::Controls::IControlOverridesT<D>, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::Controls::IContentControl, Windows::UI::Xaml::Controls::IContentControl2, Windows::UI::Xaml::Controls::IFlyoutPresenter, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IUIElement4, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::IFrameworkElement4, Windows::UI::Xaml::Controls::IControl, Windows::UI::Xaml::Controls::IControlProtected, Windows::UI::Xaml::Controls::IControl2, Windows::UI::Xaml::Controls::IControl3, Windows::UI::Xaml::Controls::IControl4>
{
    using composable = FlyoutPresenter;

protected:

    FlyoutPresenterT()
    {
        GetActivationFactory<FlyoutPresenter, IFlyoutPresenterFactory>().CreateInstance(*this, m_inner);
    }
};

template <typename D, typename ... Interfaces> struct FontIconT :
    overrides<D, Windows::UI::Xaml::IUIElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverrides2T<D>, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::Controls::IIconElement, Windows::UI::Xaml::Controls::IFontIcon, Windows::UI::Xaml::Controls::IFontIcon2, Windows::UI::Xaml::Controls::IFontIcon3, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IUIElement4, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::IFrameworkElement4>
{
    using composable = FontIcon;

protected:

    FontIconT()
    {
        GetActivationFactory<FontIcon, IFontIconFactory>().CreateInstance(*this, m_inner);
    }
};

template <typename D, typename ... Interfaces> struct FrameT :
    overrides<D, Windows::UI::Xaml::Controls::IContentControlOverridesT<D>, Windows::UI::Xaml::IUIElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverrides2T<D>, Windows::UI::Xaml::Controls::IControlOverridesT<D>, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::Controls::INavigate, Windows::UI::Xaml::Controls::IContentControl, Windows::UI::Xaml::Controls::IContentControl2, Windows::UI::Xaml::Controls::IFrame, Windows::UI::Xaml::Controls::IFrame2, Windows::UI::Xaml::Controls::IFrame3, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IUIElement4, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::IFrameworkElement4, Windows::UI::Xaml::Controls::IControl, Windows::UI::Xaml::Controls::IControlProtected, Windows::UI::Xaml::Controls::IControl2, Windows::UI::Xaml::Controls::IControl3, Windows::UI::Xaml::Controls::IControl4>
{
    using composable = Frame;

protected:

    FrameT()
    {
        GetActivationFactory<Frame, IFrameFactory>().CreateInstance(*this, m_inner);
    }
};

template <typename D, typename ... Interfaces> struct GridT :
    overrides<D, Windows::UI::Xaml::IUIElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverrides2T<D>, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::Controls::IPanel, Windows::UI::Xaml::Controls::IGrid, Windows::UI::Xaml::Controls::IGrid2, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IUIElement4, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::IFrameworkElement4>
{
    using composable = Grid;

protected:

    GridT()
    {
        GetActivationFactory<Grid, IGridFactory>().CreateInstance(*this, m_inner);
    }
};

template <typename D, typename ... Interfaces> struct GridViewT :
    overrides<D, Windows::UI::Xaml::Controls::IItemsControlOverridesT<D>, Windows::UI::Xaml::IUIElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverrides2T<D>, Windows::UI::Xaml::Controls::IControlOverridesT<D>, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::Controls::IItemContainerMapping, Windows::UI::Xaml::Controls::ISemanticZoomInformation, Windows::UI::Xaml::Controls::IItemsControl, Windows::UI::Xaml::Controls::IItemsControl2, Windows::UI::Xaml::Controls::IItemsControl3, Windows::UI::Xaml::Controls::IListViewBase, Windows::UI::Xaml::Controls::IListViewBase2, Windows::UI::Xaml::Controls::IListViewBase3, Windows::UI::Xaml::Controls::IListViewBase4, Windows::UI::Xaml::Controls::IListViewBase5, Windows::UI::Xaml::Controls::Primitives::ISelector, Windows::UI::Xaml::Controls::IGridView, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IUIElement4, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::IFrameworkElement4, Windows::UI::Xaml::Controls::IControl, Windows::UI::Xaml::Controls::IControlProtected, Windows::UI::Xaml::Controls::IControl2, Windows::UI::Xaml::Controls::IControl3, Windows::UI::Xaml::Controls::IControl4>
{
    using composable = GridView;

protected:

    GridViewT()
    {
        GetActivationFactory<GridView, IGridViewFactory>().CreateInstance(*this, m_inner);
    }
};

template <typename D, typename ... Interfaces> struct GridViewHeaderItemT :
    overrides<D, Windows::UI::Xaml::Controls::IContentControlOverridesT<D>, Windows::UI::Xaml::IUIElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverrides2T<D>, Windows::UI::Xaml::Controls::IControlOverridesT<D>, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::Controls::IContentControl, Windows::UI::Xaml::Controls::IContentControl2, Windows::UI::Xaml::Controls::IListViewBaseHeaderItem, Windows::UI::Xaml::Controls::IGridViewHeaderItem, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IUIElement4, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::IFrameworkElement4, Windows::UI::Xaml::Controls::IControl, Windows::UI::Xaml::Controls::IControlProtected, Windows::UI::Xaml::Controls::IControl2, Windows::UI::Xaml::Controls::IControl3, Windows::UI::Xaml::Controls::IControl4>
{
    using composable = GridViewHeaderItem;

protected:

    GridViewHeaderItemT()
    {
        GetActivationFactory<GridViewHeaderItem, IGridViewHeaderItemFactory>().CreateInstance(*this, m_inner);
    }
};

template <typename D, typename ... Interfaces> struct GridViewItemT :
    overrides<D, Windows::UI::Xaml::Controls::IContentControlOverridesT<D>, Windows::UI::Xaml::IUIElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverrides2T<D>, Windows::UI::Xaml::Controls::IControlOverridesT<D>, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::Controls::IContentControl, Windows::UI::Xaml::Controls::IContentControl2, Windows::UI::Xaml::Controls::Primitives::ISelectorItem, Windows::UI::Xaml::Controls::IGridViewItem, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IUIElement4, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::IFrameworkElement4, Windows::UI::Xaml::Controls::IControl, Windows::UI::Xaml::Controls::IControlProtected, Windows::UI::Xaml::Controls::IControl2, Windows::UI::Xaml::Controls::IControl3, Windows::UI::Xaml::Controls::IControl4>
{
    using composable = GridViewItem;

protected:

    GridViewItemT()
    {
        GetActivationFactory<GridViewItem, IGridViewItemFactory>().CreateInstance(*this, m_inner);
    }
};

template <typename D, typename ... Interfaces> struct GroupItemT :
    overrides<D, Windows::UI::Xaml::Controls::IContentControlOverridesT<D>, Windows::UI::Xaml::IUIElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverrides2T<D>, Windows::UI::Xaml::Controls::IControlOverridesT<D>, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::Controls::IContentControl, Windows::UI::Xaml::Controls::IContentControl2, Windows::UI::Xaml::Controls::IGroupItem, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IUIElement4, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::IFrameworkElement4, Windows::UI::Xaml::Controls::IControl, Windows::UI::Xaml::Controls::IControlProtected, Windows::UI::Xaml::Controls::IControl2, Windows::UI::Xaml::Controls::IControl3, Windows::UI::Xaml::Controls::IControl4>
{
    using composable = GroupItem;

protected:

    GroupItemT()
    {
        GetActivationFactory<GroupItem, IGroupItemFactory>().CreateInstance(*this, m_inner);
    }
};

template <typename D, typename ... Interfaces> struct GroupStyleT :
    overrides<D, Windows::IInspectable, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::Controls::IGroupStyle, Windows::UI::Xaml::Controls::IGroupStyle2, Windows::UI::Xaml::Data::INotifyPropertyChanged>
{
    using composable = GroupStyle;

protected:

    GroupStyleT()
    {
        GetActivationFactory<GroupStyle, IGroupStyleFactory>().CreateInstance(*this, m_inner);
    }
};

template <typename D, typename ... Interfaces> struct GroupStyleSelectorT :
    overrides<D, Windows::UI::Xaml::Controls::IGroupStyleSelectorOverridesT<D>, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::Controls::IGroupStyleSelector>
{
    using composable = GroupStyleSelector;

protected:

    GroupStyleSelectorT()
    {
        GetActivationFactory<GroupStyleSelector, IGroupStyleSelectorFactory>().CreateInstance(*this, m_inner);
    }
};

template <typename D, typename ... Interfaces> struct HubT :
    overrides<D, Windows::UI::Xaml::IUIElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverrides2T<D>, Windows::UI::Xaml::Controls::IControlOverridesT<D>, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::Controls::ISemanticZoomInformation, Windows::UI::Xaml::Controls::IHub, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IUIElement4, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::IFrameworkElement4, Windows::UI::Xaml::Controls::IControl, Windows::UI::Xaml::Controls::IControlProtected, Windows::UI::Xaml::Controls::IControl2, Windows::UI::Xaml::Controls::IControl3, Windows::UI::Xaml::Controls::IControl4>
{
    using composable = Hub;

protected:

    HubT()
    {
        GetActivationFactory<Hub, IHubFactory>().CreateInstance(*this, m_inner);
    }
};

template <typename D, typename ... Interfaces> struct HubSectionT :
    overrides<D, Windows::UI::Xaml::IUIElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverrides2T<D>, Windows::UI::Xaml::Controls::IControlOverridesT<D>, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::Controls::IHubSection, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IUIElement4, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::IFrameworkElement4, Windows::UI::Xaml::Controls::IControl, Windows::UI::Xaml::Controls::IControlProtected, Windows::UI::Xaml::Controls::IControl2, Windows::UI::Xaml::Controls::IControl3, Windows::UI::Xaml::Controls::IControl4>
{
    using composable = HubSection;

protected:

    HubSectionT()
    {
        GetActivationFactory<HubSection, IHubSectionFactory>().CreateInstance(*this, m_inner);
    }
};

template <typename D, typename ... Interfaces> struct HyperlinkButtonT :
    overrides<D, Windows::UI::Xaml::Controls::IContentControlOverridesT<D>, Windows::UI::Xaml::IUIElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverrides2T<D>, Windows::UI::Xaml::Controls::IControlOverridesT<D>, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::Controls::IContentControl, Windows::UI::Xaml::Controls::IContentControl2, Windows::UI::Xaml::Controls::IHyperlinkButton, Windows::UI::Xaml::Controls::Primitives::IButtonBase, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IUIElement4, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::IFrameworkElement4, Windows::UI::Xaml::Controls::IControl, Windows::UI::Xaml::Controls::IControlProtected, Windows::UI::Xaml::Controls::IControl2, Windows::UI::Xaml::Controls::IControl3, Windows::UI::Xaml::Controls::IControl4>
{
    using composable = HyperlinkButton;

protected:

    HyperlinkButtonT()
    {
        GetActivationFactory<HyperlinkButton, IHyperlinkButtonFactory>().CreateInstance(*this, m_inner);
    }
};

template <typename D, typename ... Interfaces> struct InkCanvasT :
    overrides<D, Windows::UI::Xaml::IUIElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverrides2T<D>, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::Controls::IInkCanvas, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IUIElement4, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::IFrameworkElement4>
{
    using composable = InkCanvas;

protected:

    InkCanvasT()
    {
        GetActivationFactory<InkCanvas, IInkCanvasFactory>().CreateInstance(*this, m_inner);
    }
};

template <typename D, typename ... Interfaces> struct InkToolbarT :
    overrides<D, Windows::UI::Xaml::IUIElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverrides2T<D>, Windows::UI::Xaml::Controls::IControlOverridesT<D>, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IUIElement4, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::IFrameworkElement4, Windows::UI::Xaml::Controls::IControl, Windows::UI::Xaml::Controls::IControlProtected, Windows::UI::Xaml::Controls::IControl2, Windows::UI::Xaml::Controls::IControl3, Windows::UI::Xaml::Controls::IControl4, Windows::UI::Xaml::Controls::IInkToolbar>
{
    using composable = InkToolbar;

protected:

    InkToolbarT()
    {
        GetActivationFactory<InkToolbar, IInkToolbarFactory>().CreateInstance(*this, m_inner);
    }
};

template <typename D, typename ... Interfaces> struct InkToolbarBallpointPenButtonT :
    overrides<D, Windows::UI::Xaml::Controls::IContentControlOverridesT<D>, Windows::UI::Xaml::Controls::Primitives::IToggleButtonOverridesT<D>, Windows::UI::Xaml::IUIElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverrides2T<D>, Windows::UI::Xaml::Controls::IControlOverridesT<D>, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::Controls::IContentControl, Windows::UI::Xaml::Controls::IContentControl2, Windows::UI::Xaml::Controls::IRadioButton, Windows::UI::Xaml::Controls::Primitives::IButtonBase, Windows::UI::Xaml::Controls::Primitives::IToggleButton, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IUIElement4, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::IFrameworkElement4, Windows::UI::Xaml::Controls::IControl, Windows::UI::Xaml::Controls::IControlProtected, Windows::UI::Xaml::Controls::IControl2, Windows::UI::Xaml::Controls::IControl3, Windows::UI::Xaml::Controls::IControl4, Windows::UI::Xaml::Controls::IInkToolbarToolButton, Windows::UI::Xaml::Controls::IInkToolbarPenButton, Windows::UI::Xaml::Controls::IInkToolbarBallpointPenButton>
{
    using composable = InkToolbarBallpointPenButton;

protected:

    InkToolbarBallpointPenButtonT()
    {
        GetActivationFactory<InkToolbarBallpointPenButton, IInkToolbarBallpointPenButtonFactory>().CreateInstance(*this, m_inner);
    }
};

template <typename D, typename ... Interfaces> struct InkToolbarCustomPenT :
    overrides<D, Windows::UI::Xaml::Controls::IInkToolbarCustomPenOverridesT<D>, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Controls::IInkToolbarCustomPen>
{
    using composable = InkToolbarCustomPen;

protected:

    InkToolbarCustomPenT()
    {
        GetActivationFactory<InkToolbarCustomPen, IInkToolbarCustomPenFactory>().CreateInstance(*this, m_inner);
    }
};

template <typename D, typename ... Interfaces> struct InkToolbarCustomPenButtonT :
    overrides<D, Windows::UI::Xaml::Controls::IContentControlOverridesT<D>, Windows::UI::Xaml::Controls::Primitives::IToggleButtonOverridesT<D>, Windows::UI::Xaml::IUIElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverrides2T<D>, Windows::UI::Xaml::Controls::IControlOverridesT<D>, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::Controls::IContentControl, Windows::UI::Xaml::Controls::IContentControl2, Windows::UI::Xaml::Controls::IRadioButton, Windows::UI::Xaml::Controls::Primitives::IButtonBase, Windows::UI::Xaml::Controls::Primitives::IToggleButton, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IUIElement4, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::IFrameworkElement4, Windows::UI::Xaml::Controls::IControl, Windows::UI::Xaml::Controls::IControlProtected, Windows::UI::Xaml::Controls::IControl2, Windows::UI::Xaml::Controls::IControl3, Windows::UI::Xaml::Controls::IControl4, Windows::UI::Xaml::Controls::IInkToolbarToolButton, Windows::UI::Xaml::Controls::IInkToolbarPenButton, Windows::UI::Xaml::Controls::IInkToolbarCustomPenButton>
{
    using composable = InkToolbarCustomPenButton;

protected:

    InkToolbarCustomPenButtonT()
    {
        GetActivationFactory<InkToolbarCustomPenButton, IInkToolbarCustomPenButtonFactory>().CreateInstance(*this, m_inner);
    }
};

template <typename D, typename ... Interfaces> struct InkToolbarCustomToggleButtonT :
    overrides<D, Windows::UI::Xaml::Controls::IContentControlOverridesT<D>, Windows::UI::Xaml::Controls::Primitives::IToggleButtonOverridesT<D>, Windows::UI::Xaml::IUIElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverrides2T<D>, Windows::UI::Xaml::Controls::IControlOverridesT<D>, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::Controls::IContentControl, Windows::UI::Xaml::Controls::IContentControl2, Windows::UI::Xaml::Controls::ICheckBox, Windows::UI::Xaml::Controls::Primitives::IButtonBase, Windows::UI::Xaml::Controls::Primitives::IToggleButton, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IUIElement4, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::IFrameworkElement4, Windows::UI::Xaml::Controls::IControl, Windows::UI::Xaml::Controls::IControlProtected, Windows::UI::Xaml::Controls::IControl2, Windows::UI::Xaml::Controls::IControl3, Windows::UI::Xaml::Controls::IControl4, Windows::UI::Xaml::Controls::IInkToolbarToggleButton, Windows::UI::Xaml::Controls::IInkToolbarCustomToggleButton>
{
    using composable = InkToolbarCustomToggleButton;

protected:

    InkToolbarCustomToggleButtonT()
    {
        GetActivationFactory<InkToolbarCustomToggleButton, IInkToolbarCustomToggleButtonFactory>().CreateInstance(*this, m_inner);
    }
};

template <typename D, typename ... Interfaces> struct InkToolbarCustomToolButtonT :
    overrides<D, Windows::UI::Xaml::Controls::IContentControlOverridesT<D>, Windows::UI::Xaml::Controls::Primitives::IToggleButtonOverridesT<D>, Windows::UI::Xaml::IUIElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverrides2T<D>, Windows::UI::Xaml::Controls::IControlOverridesT<D>, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::Controls::IContentControl, Windows::UI::Xaml::Controls::IContentControl2, Windows::UI::Xaml::Controls::IRadioButton, Windows::UI::Xaml::Controls::Primitives::IButtonBase, Windows::UI::Xaml::Controls::Primitives::IToggleButton, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IUIElement4, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::IFrameworkElement4, Windows::UI::Xaml::Controls::IControl, Windows::UI::Xaml::Controls::IControlProtected, Windows::UI::Xaml::Controls::IControl2, Windows::UI::Xaml::Controls::IControl3, Windows::UI::Xaml::Controls::IControl4, Windows::UI::Xaml::Controls::IInkToolbarToolButton, Windows::UI::Xaml::Controls::IInkToolbarCustomToolButton>
{
    using composable = InkToolbarCustomToolButton;

protected:

    InkToolbarCustomToolButtonT()
    {
        GetActivationFactory<InkToolbarCustomToolButton, IInkToolbarCustomToolButtonFactory>().CreateInstance(*this, m_inner);
    }
};

template <typename D, typename ... Interfaces> struct InkToolbarEraserButtonT :
    overrides<D, Windows::UI::Xaml::Controls::IContentControlOverridesT<D>, Windows::UI::Xaml::Controls::Primitives::IToggleButtonOverridesT<D>, Windows::UI::Xaml::IUIElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverrides2T<D>, Windows::UI::Xaml::Controls::IControlOverridesT<D>, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::Controls::IContentControl, Windows::UI::Xaml::Controls::IContentControl2, Windows::UI::Xaml::Controls::IRadioButton, Windows::UI::Xaml::Controls::Primitives::IButtonBase, Windows::UI::Xaml::Controls::Primitives::IToggleButton, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IUIElement4, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::IFrameworkElement4, Windows::UI::Xaml::Controls::IControl, Windows::UI::Xaml::Controls::IControlProtected, Windows::UI::Xaml::Controls::IControl2, Windows::UI::Xaml::Controls::IControl3, Windows::UI::Xaml::Controls::IControl4, Windows::UI::Xaml::Controls::IInkToolbarToolButton, Windows::UI::Xaml::Controls::IInkToolbarEraserButton>
{
    using composable = InkToolbarEraserButton;

protected:

    InkToolbarEraserButtonT()
    {
        GetActivationFactory<InkToolbarEraserButton, IInkToolbarEraserButtonFactory>().CreateInstance(*this, m_inner);
    }
};

template <typename D, typename ... Interfaces> struct InkToolbarHighlighterButtonT :
    overrides<D, Windows::UI::Xaml::Controls::IContentControlOverridesT<D>, Windows::UI::Xaml::Controls::Primitives::IToggleButtonOverridesT<D>, Windows::UI::Xaml::IUIElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverrides2T<D>, Windows::UI::Xaml::Controls::IControlOverridesT<D>, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::Controls::IContentControl, Windows::UI::Xaml::Controls::IContentControl2, Windows::UI::Xaml::Controls::IRadioButton, Windows::UI::Xaml::Controls::Primitives::IButtonBase, Windows::UI::Xaml::Controls::Primitives::IToggleButton, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IUIElement4, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::IFrameworkElement4, Windows::UI::Xaml::Controls::IControl, Windows::UI::Xaml::Controls::IControlProtected, Windows::UI::Xaml::Controls::IControl2, Windows::UI::Xaml::Controls::IControl3, Windows::UI::Xaml::Controls::IControl4, Windows::UI::Xaml::Controls::IInkToolbarToolButton, Windows::UI::Xaml::Controls::IInkToolbarPenButton, Windows::UI::Xaml::Controls::IInkToolbarHighlighterButton>
{
    using composable = InkToolbarHighlighterButton;

protected:

    InkToolbarHighlighterButtonT()
    {
        GetActivationFactory<InkToolbarHighlighterButton, IInkToolbarHighlighterButtonFactory>().CreateInstance(*this, m_inner);
    }
};

template <typename D, typename ... Interfaces> struct InkToolbarPenConfigurationControlT :
    overrides<D, Windows::UI::Xaml::IUIElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverrides2T<D>, Windows::UI::Xaml::Controls::IControlOverridesT<D>, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IUIElement4, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::IFrameworkElement4, Windows::UI::Xaml::Controls::IControl, Windows::UI::Xaml::Controls::IControlProtected, Windows::UI::Xaml::Controls::IControl2, Windows::UI::Xaml::Controls::IControl3, Windows::UI::Xaml::Controls::IControl4, Windows::UI::Xaml::Controls::IInkToolbarPenConfigurationControl>
{
    using composable = InkToolbarPenConfigurationControl;

protected:

    InkToolbarPenConfigurationControlT()
    {
        GetActivationFactory<InkToolbarPenConfigurationControl, IInkToolbarPenConfigurationControlFactory>().CreateInstance(*this, m_inner);
    }
};

template <typename D, typename ... Interfaces> struct InkToolbarPencilButtonT :
    overrides<D, Windows::UI::Xaml::Controls::IContentControlOverridesT<D>, Windows::UI::Xaml::Controls::Primitives::IToggleButtonOverridesT<D>, Windows::UI::Xaml::IUIElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverrides2T<D>, Windows::UI::Xaml::Controls::IControlOverridesT<D>, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::Controls::IContentControl, Windows::UI::Xaml::Controls::IContentControl2, Windows::UI::Xaml::Controls::IRadioButton, Windows::UI::Xaml::Controls::Primitives::IButtonBase, Windows::UI::Xaml::Controls::Primitives::IToggleButton, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IUIElement4, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::IFrameworkElement4, Windows::UI::Xaml::Controls::IControl, Windows::UI::Xaml::Controls::IControlProtected, Windows::UI::Xaml::Controls::IControl2, Windows::UI::Xaml::Controls::IControl3, Windows::UI::Xaml::Controls::IControl4, Windows::UI::Xaml::Controls::IInkToolbarToolButton, Windows::UI::Xaml::Controls::IInkToolbarPenButton, Windows::UI::Xaml::Controls::IInkToolbarPencilButton>
{
    using composable = InkToolbarPencilButton;

protected:

    InkToolbarPencilButtonT()
    {
        GetActivationFactory<InkToolbarPencilButton, IInkToolbarPencilButtonFactory>().CreateInstance(*this, m_inner);
    }
};

template <typename D, typename ... Interfaces> struct InkToolbarRulerButtonT :
    overrides<D, Windows::UI::Xaml::Controls::IContentControlOverridesT<D>, Windows::UI::Xaml::Controls::Primitives::IToggleButtonOverridesT<D>, Windows::UI::Xaml::IUIElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverrides2T<D>, Windows::UI::Xaml::Controls::IControlOverridesT<D>, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::Controls::IContentControl, Windows::UI::Xaml::Controls::IContentControl2, Windows::UI::Xaml::Controls::ICheckBox, Windows::UI::Xaml::Controls::Primitives::IButtonBase, Windows::UI::Xaml::Controls::Primitives::IToggleButton, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IUIElement4, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::IFrameworkElement4, Windows::UI::Xaml::Controls::IControl, Windows::UI::Xaml::Controls::IControlProtected, Windows::UI::Xaml::Controls::IControl2, Windows::UI::Xaml::Controls::IControl3, Windows::UI::Xaml::Controls::IControl4, Windows::UI::Xaml::Controls::IInkToolbarToggleButton, Windows::UI::Xaml::Controls::IInkToolbarRulerButton>
{
    using composable = InkToolbarRulerButton;

protected:

    InkToolbarRulerButtonT()
    {
        GetActivationFactory<InkToolbarRulerButton, IInkToolbarRulerButtonFactory>().CreateInstance(*this, m_inner);
    }
};

template <typename D, typename ... Interfaces> struct ItemsControlT :
    overrides<D, Windows::UI::Xaml::Controls::IItemsControlOverridesT<D>, Windows::UI::Xaml::IUIElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverrides2T<D>, Windows::UI::Xaml::Controls::IControlOverridesT<D>, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::Controls::IItemContainerMapping, Windows::UI::Xaml::Controls::IItemsControl, Windows::UI::Xaml::Controls::IItemsControl2, Windows::UI::Xaml::Controls::IItemsControl3, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IUIElement4, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::IFrameworkElement4, Windows::UI::Xaml::Controls::IControl, Windows::UI::Xaml::Controls::IControlProtected, Windows::UI::Xaml::Controls::IControl2, Windows::UI::Xaml::Controls::IControl3, Windows::UI::Xaml::Controls::IControl4>
{
    using composable = ItemsControl;

protected:

    ItemsControlT()
    {
        GetActivationFactory<ItemsControl, IItemsControlFactory>().CreateInstance(*this, m_inner);
    }
};

template <typename D, typename ... Interfaces> struct ListBoxT :
    overrides<D, Windows::UI::Xaml::Controls::IItemsControlOverridesT<D>, Windows::UI::Xaml::IUIElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverrides2T<D>, Windows::UI::Xaml::Controls::IControlOverridesT<D>, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::Controls::IItemContainerMapping, Windows::UI::Xaml::Controls::IItemsControl, Windows::UI::Xaml::Controls::IItemsControl2, Windows::UI::Xaml::Controls::IItemsControl3, Windows::UI::Xaml::Controls::IListBox, Windows::UI::Xaml::Controls::IListBox2, Windows::UI::Xaml::Controls::Primitives::ISelector, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IUIElement4, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::IFrameworkElement4, Windows::UI::Xaml::Controls::IControl, Windows::UI::Xaml::Controls::IControlProtected, Windows::UI::Xaml::Controls::IControl2, Windows::UI::Xaml::Controls::IControl3, Windows::UI::Xaml::Controls::IControl4>
{
    using composable = ListBox;

protected:

    ListBoxT()
    {
        GetActivationFactory<ListBox, IListBoxFactory>().CreateInstance(*this, m_inner);
    }
};

template <typename D, typename ... Interfaces> struct ListBoxItemT :
    overrides<D, Windows::UI::Xaml::Controls::IContentControlOverridesT<D>, Windows::UI::Xaml::IUIElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverrides2T<D>, Windows::UI::Xaml::Controls::IControlOverridesT<D>, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::Controls::IContentControl, Windows::UI::Xaml::Controls::IContentControl2, Windows::UI::Xaml::Controls::IListBoxItem, Windows::UI::Xaml::Controls::Primitives::ISelectorItem, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IUIElement4, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::IFrameworkElement4, Windows::UI::Xaml::Controls::IControl, Windows::UI::Xaml::Controls::IControlProtected, Windows::UI::Xaml::Controls::IControl2, Windows::UI::Xaml::Controls::IControl3, Windows::UI::Xaml::Controls::IControl4>
{
    using composable = ListBoxItem;

protected:

    ListBoxItemT()
    {
        GetActivationFactory<ListBoxItem, IListBoxItemFactory>().CreateInstance(*this, m_inner);
    }
};

template <typename D, typename ... Interfaces> struct ListViewT :
    overrides<D, Windows::UI::Xaml::Controls::IItemsControlOverridesT<D>, Windows::UI::Xaml::IUIElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverrides2T<D>, Windows::UI::Xaml::Controls::IControlOverridesT<D>, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::Controls::IItemContainerMapping, Windows::UI::Xaml::Controls::ISemanticZoomInformation, Windows::UI::Xaml::Controls::IItemsControl, Windows::UI::Xaml::Controls::IItemsControl2, Windows::UI::Xaml::Controls::IItemsControl3, Windows::UI::Xaml::Controls::IListViewBase, Windows::UI::Xaml::Controls::IListViewBase2, Windows::UI::Xaml::Controls::IListViewBase3, Windows::UI::Xaml::Controls::IListViewBase4, Windows::UI::Xaml::Controls::IListViewBase5, Windows::UI::Xaml::Controls::Primitives::ISelector, Windows::UI::Xaml::Controls::IListView, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IUIElement4, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::IFrameworkElement4, Windows::UI::Xaml::Controls::IControl, Windows::UI::Xaml::Controls::IControlProtected, Windows::UI::Xaml::Controls::IControl2, Windows::UI::Xaml::Controls::IControl3, Windows::UI::Xaml::Controls::IControl4>
{
    using composable = ListView;

protected:

    ListViewT()
    {
        GetActivationFactory<ListView, IListViewFactory>().CreateInstance(*this, m_inner);
    }
};

template <typename D, typename ... Interfaces> struct ListViewBaseT :
    overrides<D, Windows::UI::Xaml::Controls::IItemsControlOverridesT<D>, Windows::UI::Xaml::IUIElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverrides2T<D>, Windows::UI::Xaml::Controls::IControlOverridesT<D>, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::Controls::IItemContainerMapping, Windows::UI::Xaml::Controls::ISemanticZoomInformation, Windows::UI::Xaml::Controls::IItemsControl, Windows::UI::Xaml::Controls::IItemsControl2, Windows::UI::Xaml::Controls::IItemsControl3, Windows::UI::Xaml::Controls::IListViewBase, Windows::UI::Xaml::Controls::IListViewBase2, Windows::UI::Xaml::Controls::IListViewBase3, Windows::UI::Xaml::Controls::IListViewBase4, Windows::UI::Xaml::Controls::IListViewBase5, Windows::UI::Xaml::Controls::Primitives::ISelector, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IUIElement4, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::IFrameworkElement4, Windows::UI::Xaml::Controls::IControl, Windows::UI::Xaml::Controls::IControlProtected, Windows::UI::Xaml::Controls::IControl2, Windows::UI::Xaml::Controls::IControl3, Windows::UI::Xaml::Controls::IControl4>
{
    using composable = ListViewBase;

protected:

    ListViewBaseT()
    {
        GetActivationFactory<ListViewBase, IListViewBaseFactory>().CreateInstance(*this, m_inner);
    }
};

template <typename D, typename ... Interfaces> struct ListViewHeaderItemT :
    overrides<D, Windows::UI::Xaml::Controls::IContentControlOverridesT<D>, Windows::UI::Xaml::IUIElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverrides2T<D>, Windows::UI::Xaml::Controls::IControlOverridesT<D>, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::Controls::IContentControl, Windows::UI::Xaml::Controls::IContentControl2, Windows::UI::Xaml::Controls::IListViewBaseHeaderItem, Windows::UI::Xaml::Controls::IListViewHeaderItem, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IUIElement4, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::IFrameworkElement4, Windows::UI::Xaml::Controls::IControl, Windows::UI::Xaml::Controls::IControlProtected, Windows::UI::Xaml::Controls::IControl2, Windows::UI::Xaml::Controls::IControl3, Windows::UI::Xaml::Controls::IControl4>
{
    using composable = ListViewHeaderItem;

protected:

    ListViewHeaderItemT()
    {
        GetActivationFactory<ListViewHeaderItem, IListViewHeaderItemFactory>().CreateInstance(*this, m_inner);
    }
};

template <typename D, typename ... Interfaces> struct ListViewItemT :
    overrides<D, Windows::UI::Xaml::Controls::IContentControlOverridesT<D>, Windows::UI::Xaml::IUIElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverrides2T<D>, Windows::UI::Xaml::Controls::IControlOverridesT<D>, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::Controls::IContentControl, Windows::UI::Xaml::Controls::IContentControl2, Windows::UI::Xaml::Controls::Primitives::ISelectorItem, Windows::UI::Xaml::Controls::IListViewItem, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IUIElement4, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::IFrameworkElement4, Windows::UI::Xaml::Controls::IControl, Windows::UI::Xaml::Controls::IControlProtected, Windows::UI::Xaml::Controls::IControl2, Windows::UI::Xaml::Controls::IControl3, Windows::UI::Xaml::Controls::IControl4>
{
    using composable = ListViewItem;

protected:

    ListViewItemT()
    {
        GetActivationFactory<ListViewItem, IListViewItemFactory>().CreateInstance(*this, m_inner);
    }
};

template <typename D, typename ... Interfaces> struct MediaPlayerElementT :
    overrides<D, Windows::UI::Xaml::IUIElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverrides2T<D>, Windows::UI::Xaml::Controls::IControlOverridesT<D>, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::Controls::IMediaPlayerElement, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IUIElement4, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::IFrameworkElement4, Windows::UI::Xaml::Controls::IControl, Windows::UI::Xaml::Controls::IControlProtected, Windows::UI::Xaml::Controls::IControl2, Windows::UI::Xaml::Controls::IControl3, Windows::UI::Xaml::Controls::IControl4>
{
    using composable = MediaPlayerElement;

protected:

    MediaPlayerElementT()
    {
        GetActivationFactory<MediaPlayerElement, IMediaPlayerElementFactory>().CreateInstance(*this, m_inner);
    }
};

template <typename D, typename ... Interfaces> struct MediaPlayerPresenterT :
    overrides<D, Windows::UI::Xaml::IUIElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverrides2T<D>, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::Controls::IMediaPlayerPresenter, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IUIElement4, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::IFrameworkElement4>
{
    using composable = MediaPlayerPresenter;

protected:

    MediaPlayerPresenterT()
    {
        GetActivationFactory<MediaPlayerPresenter, IMediaPlayerPresenterFactory>().CreateInstance(*this, m_inner);
    }
};

template <typename D, typename ... Interfaces> struct MediaTransportControlsT :
    overrides<D, Windows::UI::Xaml::IUIElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverrides2T<D>, Windows::UI::Xaml::Controls::IControlOverridesT<D>, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::Controls::IMediaTransportControls, Windows::UI::Xaml::Controls::IMediaTransportControls2, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IUIElement4, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::IFrameworkElement4, Windows::UI::Xaml::Controls::IControl, Windows::UI::Xaml::Controls::IControlProtected, Windows::UI::Xaml::Controls::IControl2, Windows::UI::Xaml::Controls::IControl3, Windows::UI::Xaml::Controls::IControl4>
{
    using composable = MediaTransportControls;

protected:

    MediaTransportControlsT()
    {
        GetActivationFactory<MediaTransportControls, IMediaTransportControlsFactory>().CreateInstance(*this, m_inner);
    }
};

template <typename D, typename ... Interfaces> struct MenuFlyoutT :
    overrides<D, Windows::UI::Xaml::Controls::Primitives::IFlyoutBaseOverridesT<D>, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::Controls::IMenuFlyout, Windows::UI::Xaml::Controls::IMenuFlyout2, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Controls::Primitives::IFlyoutBase, Windows::UI::Xaml::Controls::Primitives::IFlyoutBase2>
{
    using composable = MenuFlyout;

protected:

    MenuFlyoutT()
    {
        GetActivationFactory<MenuFlyout, IMenuFlyoutFactory>().CreateInstance(*this, m_inner);
    }
};

template <typename D, typename ... Interfaces> struct MenuFlyoutItemT :
    overrides<D, Windows::UI::Xaml::IUIElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverrides2T<D>, Windows::UI::Xaml::Controls::IControlOverridesT<D>, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::Controls::IMenuFlyoutItemBase, Windows::UI::Xaml::Controls::IMenuFlyoutItem, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IUIElement4, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::IFrameworkElement4, Windows::UI::Xaml::Controls::IControl, Windows::UI::Xaml::Controls::IControlProtected, Windows::UI::Xaml::Controls::IControl2, Windows::UI::Xaml::Controls::IControl3, Windows::UI::Xaml::Controls::IControl4>
{
    using composable = MenuFlyoutItem;

protected:

    MenuFlyoutItemT()
    {
        GetActivationFactory<MenuFlyoutItem, IMenuFlyoutItemFactory>().CreateInstance(*this, m_inner);
    }
};

template <typename D, typename ... Interfaces> struct MenuFlyoutPresenterT :
    overrides<D, Windows::UI::Xaml::Controls::IItemsControlOverridesT<D>, Windows::UI::Xaml::IUIElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverrides2T<D>, Windows::UI::Xaml::Controls::IControlOverridesT<D>, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::Controls::IItemContainerMapping, Windows::UI::Xaml::Controls::IItemsControl, Windows::UI::Xaml::Controls::IItemsControl2, Windows::UI::Xaml::Controls::IItemsControl3, Windows::UI::Xaml::Controls::IMenuFlyoutPresenter, Windows::UI::Xaml::Controls::IMenuFlyoutPresenter2, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IUIElement4, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::IFrameworkElement4, Windows::UI::Xaml::Controls::IControl, Windows::UI::Xaml::Controls::IControlProtected, Windows::UI::Xaml::Controls::IControl2, Windows::UI::Xaml::Controls::IControl3, Windows::UI::Xaml::Controls::IControl4>
{
    using composable = MenuFlyoutPresenter;

protected:

    MenuFlyoutPresenterT()
    {
        GetActivationFactory<MenuFlyoutPresenter, IMenuFlyoutPresenterFactory>().CreateInstance(*this, m_inner);
    }
};

template <typename D, typename ... Interfaces> struct MenuFlyoutSeparatorT :
    overrides<D, Windows::UI::Xaml::IUIElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverrides2T<D>, Windows::UI::Xaml::Controls::IControlOverridesT<D>, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::Controls::IMenuFlyoutItemBase, Windows::UI::Xaml::Controls::IMenuFlyoutSeparator, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IUIElement4, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::IFrameworkElement4, Windows::UI::Xaml::Controls::IControl, Windows::UI::Xaml::Controls::IControlProtected, Windows::UI::Xaml::Controls::IControl2, Windows::UI::Xaml::Controls::IControl3, Windows::UI::Xaml::Controls::IControl4>
{
    using composable = MenuFlyoutSeparator;

protected:

    MenuFlyoutSeparatorT()
    {
        GetActivationFactory<MenuFlyoutSeparator, IMenuFlyoutSeparatorFactory>().CreateInstance(*this, m_inner);
    }
};

template <typename D, typename ... Interfaces> struct PageT :
    overrides<D, Windows::UI::Xaml::Controls::IPageOverridesT<D>, Windows::UI::Xaml::IUIElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverrides2T<D>, Windows::UI::Xaml::Controls::IControlOverridesT<D>, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::Controls::IUserControl, Windows::UI::Xaml::Controls::IPage, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IUIElement4, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::IFrameworkElement4, Windows::UI::Xaml::Controls::IControl, Windows::UI::Xaml::Controls::IControlProtected, Windows::UI::Xaml::Controls::IControl2, Windows::UI::Xaml::Controls::IControl3, Windows::UI::Xaml::Controls::IControl4>
{
    using composable = Page;

protected:

    PageT()
    {
        GetActivationFactory<Page, IPageFactory>().CreateInstance(*this, m_inner);
    }
};

template <typename D, typename ... Interfaces> struct PanelT :
    overrides<D, Windows::UI::Xaml::IUIElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverrides2T<D>, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::Controls::IPanel, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IUIElement4, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::IFrameworkElement4>
{
    using composable = Panel;

protected:

    PanelT()
    {
        GetActivationFactory<Panel, IPanelFactory>().CreateInstance(*this, m_inner);
    }
};

template <typename D, typename ... Interfaces> struct PathIconT :
    overrides<D, Windows::UI::Xaml::IUIElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverrides2T<D>, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::Controls::IIconElement, Windows::UI::Xaml::Controls::IPathIcon, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IUIElement4, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::IFrameworkElement4>
{
    using composable = PathIcon;

protected:

    PathIconT()
    {
        GetActivationFactory<PathIcon, IPathIconFactory>().CreateInstance(*this, m_inner);
    }
};

template <typename D, typename ... Interfaces> struct PivotT :
    overrides<D, Windows::UI::Xaml::Controls::IItemsControlOverridesT<D>, Windows::UI::Xaml::IUIElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverrides2T<D>, Windows::UI::Xaml::Controls::IControlOverridesT<D>, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::Controls::IItemContainerMapping, Windows::UI::Xaml::Controls::IItemsControl, Windows::UI::Xaml::Controls::IItemsControl2, Windows::UI::Xaml::Controls::IItemsControl3, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IUIElement4, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::IFrameworkElement4, Windows::UI::Xaml::Controls::IControl, Windows::UI::Xaml::Controls::IControlProtected, Windows::UI::Xaml::Controls::IControl2, Windows::UI::Xaml::Controls::IControl3, Windows::UI::Xaml::Controls::IControl4, Windows::UI::Xaml::Controls::IPivot, Windows::UI::Xaml::Controls::IPivot2, Windows::UI::Xaml::Controls::IPivot3>
{
    using composable = Pivot;

protected:

    PivotT()
    {
        GetActivationFactory<Pivot, IPivotFactory>().CreateInstance(*this, m_inner);
    }
};

template <typename D, typename ... Interfaces> struct PivotItemT :
    overrides<D, Windows::UI::Xaml::Controls::IContentControlOverridesT<D>, Windows::UI::Xaml::IUIElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverrides2T<D>, Windows::UI::Xaml::Controls::IControlOverridesT<D>, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::Controls::IContentControl, Windows::UI::Xaml::Controls::IContentControl2, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IUIElement4, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::IFrameworkElement4, Windows::UI::Xaml::Controls::IControl, Windows::UI::Xaml::Controls::IControlProtected, Windows::UI::Xaml::Controls::IControl2, Windows::UI::Xaml::Controls::IControl3, Windows::UI::Xaml::Controls::IControl4, Windows::UI::Xaml::Controls::IPivotItem>
{
    using composable = PivotItem;

protected:

    PivotItemT()
    {
        GetActivationFactory<PivotItem, IPivotItemFactory>().CreateInstance(*this, m_inner);
    }
};

template <typename D, typename ... Interfaces> struct ProgressBarT :
    overrides<D, Windows::UI::Xaml::Controls::Primitives::IRangeBaseOverridesT<D>, Windows::UI::Xaml::IUIElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverrides2T<D>, Windows::UI::Xaml::Controls::IControlOverridesT<D>, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::Controls::IProgressBar, Windows::UI::Xaml::Controls::Primitives::IRangeBase, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IUIElement4, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::IFrameworkElement4, Windows::UI::Xaml::Controls::IControl, Windows::UI::Xaml::Controls::IControlProtected, Windows::UI::Xaml::Controls::IControl2, Windows::UI::Xaml::Controls::IControl3, Windows::UI::Xaml::Controls::IControl4>
{
    using composable = ProgressBar;

protected:

    ProgressBarT()
    {
        GetActivationFactory<ProgressBar, IProgressBarFactory>().CreateInstance(*this, m_inner);
    }
};

template <typename D, typename ... Interfaces> struct RadioButtonT :
    overrides<D, Windows::UI::Xaml::Controls::IContentControlOverridesT<D>, Windows::UI::Xaml::Controls::Primitives::IToggleButtonOverridesT<D>, Windows::UI::Xaml::IUIElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverrides2T<D>, Windows::UI::Xaml::Controls::IControlOverridesT<D>, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::Controls::IContentControl, Windows::UI::Xaml::Controls::IContentControl2, Windows::UI::Xaml::Controls::IRadioButton, Windows::UI::Xaml::Controls::Primitives::IButtonBase, Windows::UI::Xaml::Controls::Primitives::IToggleButton, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IUIElement4, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::IFrameworkElement4, Windows::UI::Xaml::Controls::IControl, Windows::UI::Xaml::Controls::IControlProtected, Windows::UI::Xaml::Controls::IControl2, Windows::UI::Xaml::Controls::IControl3, Windows::UI::Xaml::Controls::IControl4>
{
    using composable = RadioButton;

protected:

    RadioButtonT()
    {
        GetActivationFactory<RadioButton, IRadioButtonFactory>().CreateInstance(*this, m_inner);
    }
};

template <typename D, typename ... Interfaces> struct RelativePanelT :
    overrides<D, Windows::UI::Xaml::IUIElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverrides2T<D>, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::Controls::IPanel, Windows::UI::Xaml::Controls::IRelativePanel, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IUIElement4, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::IFrameworkElement4>
{
    using composable = RelativePanel;

protected:

    RelativePanelT()
    {
        GetActivationFactory<RelativePanel, IRelativePanelFactory>().CreateInstance(*this, m_inner);
    }
};

template <typename D, typename ... Interfaces> struct RichEditBoxT :
    overrides<D, Windows::UI::Xaml::IUIElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverrides2T<D>, Windows::UI::Xaml::Controls::IControlOverridesT<D>, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::Controls::IRichEditBox, Windows::UI::Xaml::Controls::IRichEditBox2, Windows::UI::Xaml::Controls::IRichEditBox3, Windows::UI::Xaml::Controls::IRichEditBox4, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IUIElement4, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::IFrameworkElement4, Windows::UI::Xaml::Controls::IControl, Windows::UI::Xaml::Controls::IControlProtected, Windows::UI::Xaml::Controls::IControl2, Windows::UI::Xaml::Controls::IControl3, Windows::UI::Xaml::Controls::IControl4>
{
    using composable = RichEditBox;

protected:

    RichEditBoxT()
    {
        GetActivationFactory<RichEditBox, IRichEditBoxFactory>().CreateInstance(*this, m_inner);
    }
};

template <typename D, typename ... Interfaces> struct SearchBoxT :
    overrides<D, Windows::UI::Xaml::IUIElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverrides2T<D>, Windows::UI::Xaml::Controls::IControlOverridesT<D>, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::Controls::ISearchBox, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IUIElement4, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::IFrameworkElement4, Windows::UI::Xaml::Controls::IControl, Windows::UI::Xaml::Controls::IControlProtected, Windows::UI::Xaml::Controls::IControl2, Windows::UI::Xaml::Controls::IControl3, Windows::UI::Xaml::Controls::IControl4>
{
    using composable = SearchBox;

protected:

    SearchBoxT()
    {
        GetActivationFactory<SearchBox, ISearchBoxFactory>().CreateInstance(*this, m_inner);
    }
};

template <typename D, typename ... Interfaces> struct SelectionChangedEventArgsT :
    overrides<D, Windows::IInspectable, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::Controls::ISelectionChangedEventArgs, Windows::UI::Xaml::IRoutedEventArgs>
{
    using composable = SelectionChangedEventArgs;

protected:

    SelectionChangedEventArgsT(const Windows::Foundation::Collections::IVector<Windows::IInspectable> & removedItems, const Windows::Foundation::Collections::IVector<Windows::IInspectable> & addedItems)
    {
        GetActivationFactory<SelectionChangedEventArgs, ISelectionChangedEventArgsFactory>().CreateInstanceWithRemovedItemsAndAddedItems(removedItems, addedItems, *this, m_inner);
    }
};

template <typename D, typename ... Interfaces> struct SettingsFlyoutT :
    overrides<D, Windows::UI::Xaml::Controls::IContentControlOverridesT<D>, Windows::UI::Xaml::IUIElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverrides2T<D>, Windows::UI::Xaml::Controls::IControlOverridesT<D>, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::Controls::IContentControl, Windows::UI::Xaml::Controls::IContentControl2, Windows::UI::Xaml::Controls::ISettingsFlyout, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IUIElement4, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::IFrameworkElement4, Windows::UI::Xaml::Controls::IControl, Windows::UI::Xaml::Controls::IControlProtected, Windows::UI::Xaml::Controls::IControl2, Windows::UI::Xaml::Controls::IControl3, Windows::UI::Xaml::Controls::IControl4>
{
    using composable = SettingsFlyout;

protected:

    SettingsFlyoutT()
    {
        GetActivationFactory<SettingsFlyout, ISettingsFlyoutFactory>().CreateInstance(*this, m_inner);
    }
};

template <typename D, typename ... Interfaces> struct SliderT :
    overrides<D, Windows::UI::Xaml::Controls::Primitives::IRangeBaseOverridesT<D>, Windows::UI::Xaml::IUIElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverrides2T<D>, Windows::UI::Xaml::Controls::IControlOverridesT<D>, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::Controls::ISlider, Windows::UI::Xaml::Controls::ISlider2, Windows::UI::Xaml::Controls::Primitives::IRangeBase, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IUIElement4, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::IFrameworkElement4, Windows::UI::Xaml::Controls::IControl, Windows::UI::Xaml::Controls::IControlProtected, Windows::UI::Xaml::Controls::IControl2, Windows::UI::Xaml::Controls::IControl3, Windows::UI::Xaml::Controls::IControl4>
{
    using composable = Slider;

protected:

    SliderT()
    {
        GetActivationFactory<Slider, ISliderFactory>().CreateInstance(*this, m_inner);
    }
};

template <typename D, typename ... Interfaces> struct SplitViewT :
    overrides<D, Windows::UI::Xaml::IUIElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverrides2T<D>, Windows::UI::Xaml::Controls::IControlOverridesT<D>, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::Controls::ISplitView, Windows::UI::Xaml::Controls::ISplitView2, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IUIElement4, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::IFrameworkElement4, Windows::UI::Xaml::Controls::IControl, Windows::UI::Xaml::Controls::IControlProtected, Windows::UI::Xaml::Controls::IControl2, Windows::UI::Xaml::Controls::IControl3, Windows::UI::Xaml::Controls::IControl4>
{
    using composable = SplitView;

protected:

    SplitViewT()
    {
        GetActivationFactory<SplitView, ISplitViewFactory>().CreateInstance(*this, m_inner);
    }
};

template <typename D, typename ... Interfaces> struct StackPanelT :
    overrides<D, Windows::UI::Xaml::IUIElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverrides2T<D>, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::Controls::IInsertionPanel, Windows::UI::Xaml::Controls::IPanel, Windows::UI::Xaml::Controls::IStackPanel, Windows::UI::Xaml::Controls::IStackPanel2, Windows::UI::Xaml::Controls::Primitives::IScrollSnapPointsInfo, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IUIElement4, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::IFrameworkElement4>
{
    using composable = StackPanel;

protected:

    StackPanelT()
    {
        GetActivationFactory<StackPanel, IStackPanelFactory>().CreateInstance(*this, m_inner);
    }
};

template <typename D, typename ... Interfaces> struct StyleSelectorT :
    overrides<D, Windows::UI::Xaml::Controls::IStyleSelectorOverridesT<D>, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::Controls::IStyleSelector>
{
    using composable = StyleSelector;

protected:

    StyleSelectorT()
    {
        GetActivationFactory<StyleSelector, IStyleSelectorFactory>().CreateInstance(*this, m_inner);
    }
};

template <typename D, typename ... Interfaces> struct SwapChainBackgroundPanelT :
    overrides<D, Windows::UI::Xaml::IUIElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverrides2T<D>, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::Controls::IPanel, Windows::UI::Xaml::Controls::IGrid, Windows::UI::Xaml::Controls::IGrid2, Windows::UI::Xaml::Controls::ISwapChainBackgroundPanel, Windows::UI::Xaml::Controls::ISwapChainBackgroundPanel2, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IUIElement4, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::IFrameworkElement4>
{
    using composable = SwapChainBackgroundPanel;

protected:

    SwapChainBackgroundPanelT()
    {
        GetActivationFactory<SwapChainBackgroundPanel, ISwapChainBackgroundPanelFactory>().CreateInstance(*this, m_inner);
    }
};

template <typename D, typename ... Interfaces> struct SwapChainPanelT :
    overrides<D, Windows::UI::Xaml::IUIElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverrides2T<D>, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::Controls::IPanel, Windows::UI::Xaml::Controls::IGrid, Windows::UI::Xaml::Controls::IGrid2, Windows::UI::Xaml::Controls::ISwapChainPanel, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IUIElement4, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::IFrameworkElement4>
{
    using composable = SwapChainPanel;

protected:

    SwapChainPanelT()
    {
        GetActivationFactory<SwapChainPanel, ISwapChainPanelFactory>().CreateInstance(*this, m_inner);
    }
};

template <typename D, typename ... Interfaces> struct TextBoxT :
    overrides<D, Windows::UI::Xaml::IUIElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverrides2T<D>, Windows::UI::Xaml::Controls::IControlOverridesT<D>, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::Controls::ITextBox, Windows::UI::Xaml::Controls::ITextBox2, Windows::UI::Xaml::Controls::ITextBox3, Windows::UI::Xaml::Controls::ITextBox4, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IUIElement4, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::IFrameworkElement4, Windows::UI::Xaml::Controls::IControl, Windows::UI::Xaml::Controls::IControlProtected, Windows::UI::Xaml::Controls::IControl2, Windows::UI::Xaml::Controls::IControl3, Windows::UI::Xaml::Controls::IControl4>
{
    using composable = TextBox;

protected:

    TextBoxT()
    {
        GetActivationFactory<TextBox, ITextBoxFactory>().CreateInstance(*this, m_inner);
    }
};

template <typename D, typename ... Interfaces> struct TimePickerT :
    overrides<D, Windows::UI::Xaml::IUIElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverrides2T<D>, Windows::UI::Xaml::Controls::IControlOverridesT<D>, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::Controls::ITimePicker, Windows::UI::Xaml::Controls::ITimePicker2, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IUIElement4, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::IFrameworkElement4, Windows::UI::Xaml::Controls::IControl, Windows::UI::Xaml::Controls::IControlProtected, Windows::UI::Xaml::Controls::IControl2, Windows::UI::Xaml::Controls::IControl3, Windows::UI::Xaml::Controls::IControl4>
{
    using composable = TimePicker;

protected:

    TimePickerT()
    {
        GetActivationFactory<TimePicker, ITimePickerFactory>().CreateInstance(*this, m_inner);
    }
};

template <typename D, typename ... Interfaces> struct ToggleMenuFlyoutItemT :
    overrides<D, Windows::UI::Xaml::IUIElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverrides2T<D>, Windows::UI::Xaml::Controls::IControlOverridesT<D>, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::Controls::IMenuFlyoutItemBase, Windows::UI::Xaml::Controls::IMenuFlyoutItem, Windows::UI::Xaml::Controls::IToggleMenuFlyoutItem, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IUIElement4, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::IFrameworkElement4, Windows::UI::Xaml::Controls::IControl, Windows::UI::Xaml::Controls::IControlProtected, Windows::UI::Xaml::Controls::IControl2, Windows::UI::Xaml::Controls::IControl3, Windows::UI::Xaml::Controls::IControl4>
{
    using composable = ToggleMenuFlyoutItem;

protected:

    ToggleMenuFlyoutItemT()
    {
        GetActivationFactory<ToggleMenuFlyoutItem, IToggleMenuFlyoutItemFactory>().CreateInstance(*this, m_inner);
    }
};

template <typename D, typename ... Interfaces> struct ToolTipT :
    overrides<D, Windows::UI::Xaml::Controls::IContentControlOverridesT<D>, Windows::UI::Xaml::IUIElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverrides2T<D>, Windows::UI::Xaml::Controls::IControlOverridesT<D>, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::Controls::IContentControl, Windows::UI::Xaml::Controls::IContentControl2, Windows::UI::Xaml::Controls::IToolTip, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IUIElement4, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::IFrameworkElement4, Windows::UI::Xaml::Controls::IControl, Windows::UI::Xaml::Controls::IControlProtected, Windows::UI::Xaml::Controls::IControl2, Windows::UI::Xaml::Controls::IControl3, Windows::UI::Xaml::Controls::IControl4>
{
    using composable = ToolTip;

protected:

    ToolTipT()
    {
        GetActivationFactory<ToolTip, IToolTipFactory>().CreateInstance(*this, m_inner);
    }
};

template <typename D, typename ... Interfaces> struct UserControlT :
    overrides<D, Windows::UI::Xaml::IUIElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverrides2T<D>, Windows::UI::Xaml::Controls::IControlOverridesT<D>, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::Controls::IUserControl, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IUIElement4, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::IFrameworkElement4, Windows::UI::Xaml::Controls::IControl, Windows::UI::Xaml::Controls::IControlProtected, Windows::UI::Xaml::Controls::IControl2, Windows::UI::Xaml::Controls::IControl3, Windows::UI::Xaml::Controls::IControl4>
{
    using composable = UserControl;

protected:

    UserControlT()
    {
        GetActivationFactory<UserControl, IUserControlFactory>().CreateInstance(*this, m_inner);
    }
};

}

}
