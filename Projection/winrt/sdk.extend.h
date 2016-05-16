// C++ for the Windows Runtime v1.29
// Copyright (c) 2016 Microsoft Corporation

#pragma once

WINRT_EXPORT namespace winrt {

namespace Windows { namespace UI { namespace Xaml {

template <typename T, typename A = ABI::Windows::UI::Xaml::IApplicationOverrides>
struct IApplicationOverridesT : A
{
    void OnActivated(const Windows::ApplicationModel::Activation::IActivatedEventArgs & args)
    {
        static_cast<T *>(this)->as<Windows::UI::Xaml::IApplicationOverrides>().OnActivated(args);
    }

    void OnLaunched(const Windows::ApplicationModel::Activation::LaunchActivatedEventArgs & args)
    {
        static_cast<T *>(this)->as<Windows::UI::Xaml::IApplicationOverrides>().OnLaunched(args);
    }

    void OnFileActivated(const Windows::ApplicationModel::Activation::FileActivatedEventArgs & args)
    {
        static_cast<T *>(this)->as<Windows::UI::Xaml::IApplicationOverrides>().OnFileActivated(args);
    }

    void OnSearchActivated(const Windows::ApplicationModel::Activation::SearchActivatedEventArgs & args)
    {
        static_cast<T *>(this)->as<Windows::UI::Xaml::IApplicationOverrides>().OnSearchActivated(args);
    }

    void OnShareTargetActivated(const Windows::ApplicationModel::Activation::ShareTargetActivatedEventArgs & args)
    {
        static_cast<T *>(this)->as<Windows::UI::Xaml::IApplicationOverrides>().OnShareTargetActivated(args);
    }

    void OnFileOpenPickerActivated(const Windows::ApplicationModel::Activation::FileOpenPickerActivatedEventArgs & args)
    {
        static_cast<T *>(this)->as<Windows::UI::Xaml::IApplicationOverrides>().OnFileOpenPickerActivated(args);
    }

    void OnFileSavePickerActivated(const Windows::ApplicationModel::Activation::FileSavePickerActivatedEventArgs & args)
    {
        static_cast<T *>(this)->as<Windows::UI::Xaml::IApplicationOverrides>().OnFileSavePickerActivated(args);
    }

    void OnCachedFileUpdaterActivated(const Windows::ApplicationModel::Activation::CachedFileUpdaterActivatedEventArgs & args)
    {
        static_cast<T *>(this)->as<Windows::UI::Xaml::IApplicationOverrides>().OnCachedFileUpdaterActivated(args);
    }

    void OnWindowCreated(const Windows::UI::Xaml::WindowCreatedEventArgs & args)
    {
        static_cast<T *>(this)->as<Windows::UI::Xaml::IApplicationOverrides>().OnWindowCreated(args);
    }

    HRESULT __stdcall abi_OnActivated(abi_arg_in<Windows::ApplicationModel::Activation::IActivatedEventArgs> args) noexcept override
    {
        try
        {
            static_cast<T *>(this)->OnActivated(*reinterpret_cast<const Windows::ApplicationModel::Activation::IActivatedEventArgs *>(&args));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_OnLaunched(abi_arg_in<Windows::ApplicationModel::Activation::ILaunchActivatedEventArgs> args) noexcept override
    {
        try
        {
            static_cast<T *>(this)->OnLaunched(*reinterpret_cast<const Windows::ApplicationModel::Activation::LaunchActivatedEventArgs *>(&args));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_OnFileActivated(abi_arg_in<Windows::ApplicationModel::Activation::IFileActivatedEventArgs> args) noexcept override
    {
        try
        {
            static_cast<T *>(this)->OnFileActivated(*reinterpret_cast<const Windows::ApplicationModel::Activation::FileActivatedEventArgs *>(&args));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_OnSearchActivated(abi_arg_in<Windows::ApplicationModel::Activation::ISearchActivatedEventArgs> args) noexcept override
    {
        try
        {
            static_cast<T *>(this)->OnSearchActivated(*reinterpret_cast<const Windows::ApplicationModel::Activation::SearchActivatedEventArgs *>(&args));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_OnShareTargetActivated(abi_arg_in<Windows::ApplicationModel::Activation::IShareTargetActivatedEventArgs> args) noexcept override
    {
        try
        {
            static_cast<T *>(this)->OnShareTargetActivated(*reinterpret_cast<const Windows::ApplicationModel::Activation::ShareTargetActivatedEventArgs *>(&args));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_OnFileOpenPickerActivated(abi_arg_in<Windows::ApplicationModel::Activation::IFileOpenPickerActivatedEventArgs> args) noexcept override
    {
        try
        {
            static_cast<T *>(this)->OnFileOpenPickerActivated(*reinterpret_cast<const Windows::ApplicationModel::Activation::FileOpenPickerActivatedEventArgs *>(&args));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_OnFileSavePickerActivated(abi_arg_in<Windows::ApplicationModel::Activation::IFileSavePickerActivatedEventArgs> args) noexcept override
    {
        try
        {
            static_cast<T *>(this)->OnFileSavePickerActivated(*reinterpret_cast<const Windows::ApplicationModel::Activation::FileSavePickerActivatedEventArgs *>(&args));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_OnCachedFileUpdaterActivated(abi_arg_in<Windows::ApplicationModel::Activation::ICachedFileUpdaterActivatedEventArgs> args) noexcept override
    {
        try
        {
            static_cast<T *>(this)->OnCachedFileUpdaterActivated(*reinterpret_cast<const Windows::ApplicationModel::Activation::CachedFileUpdaterActivatedEventArgs *>(&args));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_OnWindowCreated(abi_arg_in<Windows::UI::Xaml::IWindowCreatedEventArgs> args) noexcept override
    {
        try
        {
            static_cast<T *>(this)->OnWindowCreated(*reinterpret_cast<const Windows::UI::Xaml::WindowCreatedEventArgs *>(&args));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename T, typename A = ABI::Windows::UI::Xaml::IFrameworkElementOverrides>
struct IFrameworkElementOverridesT : A
{
    Windows::Foundation::Size MeasureOverride(const Windows::Foundation::Size & availableSize)
    {
        return static_cast<T *>(this)->as<Windows::UI::Xaml::IFrameworkElementOverrides>().MeasureOverride(availableSize);
    }

    Windows::Foundation::Size ArrangeOverride(const Windows::Foundation::Size & finalSize)
    {
        return static_cast<T *>(this)->as<Windows::UI::Xaml::IFrameworkElementOverrides>().ArrangeOverride(finalSize);
    }

    void OnApplyTemplate()
    {
        static_cast<T *>(this)->as<Windows::UI::Xaml::IFrameworkElementOverrides>().OnApplyTemplate();
    }

    HRESULT __stdcall abi_MeasureOverride(Windows::Foundation::Size availableSize, Windows::Foundation::Size * returnValue) noexcept override
    {
        try
        {
            *returnValue = detach(static_cast<T *>(this)->MeasureOverride(availableSize));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_ArrangeOverride(Windows::Foundation::Size finalSize, Windows::Foundation::Size * returnValue) noexcept override
    {
        try
        {
            *returnValue = detach(static_cast<T *>(this)->ArrangeOverride(finalSize));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_OnApplyTemplate() noexcept override
    {
        try
        {
            static_cast<T *>(this)->OnApplyTemplate();
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename T, typename A = ABI::Windows::UI::Xaml::IFrameworkElementOverrides2>
struct IFrameworkElementOverrides2T : A
{
    bool GoToElementStateCore(hstring_ref stateName, bool useTransitions)
    {
        return static_cast<T *>(this)->as<Windows::UI::Xaml::IFrameworkElementOverrides2>().GoToElementStateCore(stateName, useTransitions);
    }

    HRESULT __stdcall abi_GoToElementStateCore(HSTRING stateName, bool useTransitions, bool * returnValue) noexcept override
    {
        try
        {
            *returnValue = detach(static_cast<T *>(this)->GoToElementStateCore(*reinterpret_cast<const hstring *>(&stateName), useTransitions));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename T, typename A = ABI::Windows::UI::Xaml::IUIElementOverrides>
struct IUIElementOverridesT : A
{
    Windows::UI::Xaml::Automation::Peers::AutomationPeer OnCreateAutomationPeer()
    {
        return static_cast<T *>(this)->as<Windows::UI::Xaml::IUIElementOverrides>().OnCreateAutomationPeer();
    }

    void OnDisconnectVisualChildren()
    {
        static_cast<T *>(this)->as<Windows::UI::Xaml::IUIElementOverrides>().OnDisconnectVisualChildren();
    }

    Windows::Foundation::Collections::IIterable<Windows::Foundation::Collections::IIterable<winrt::Windows::Foundation::Point>> FindSubElementsForTouchTargeting(const Windows::Foundation::Point & point, const Windows::Foundation::Rect & boundingRect)
    {
        return static_cast<T *>(this)->as<Windows::UI::Xaml::IUIElementOverrides>().FindSubElementsForTouchTargeting(point, boundingRect);
    }

    HRESULT __stdcall abi_OnCreateAutomationPeer(abi_arg_out<Windows::UI::Xaml::Automation::Peers::IAutomationPeer> returnValue) noexcept override
    {
        try
        {
            *returnValue = detach(static_cast<T *>(this)->OnCreateAutomationPeer());
            return S_OK;
        }
        catch (...)
        {
            *returnValue = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_OnDisconnectVisualChildren() noexcept override
    {
        try
        {
            static_cast<T *>(this)->OnDisconnectVisualChildren();
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_FindSubElementsForTouchTargeting(Windows::Foundation::Point point, Windows::Foundation::Rect boundingRect, abi_arg_out<Windows::Foundation::Collections::IIterable<Windows::Foundation::Collections::IIterable<winrt::Windows::Foundation::Point>>> returnValue) noexcept override
    {
        try
        {
            *returnValue = detach(static_cast<T *>(this)->FindSubElementsForTouchTargeting(point, boundingRect));
            return S_OK;
        }
        catch (...)
        {
            *returnValue = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename T, typename A = ABI::Windows::UI::Xaml::IVisualStateManagerOverrides>
struct IVisualStateManagerOverridesT : A
{
    bool GoToStateCore(const Windows::UI::Xaml::Controls::Control & control, const Windows::UI::Xaml::FrameworkElement & templateRoot, hstring_ref stateName, const Windows::UI::Xaml::VisualStateGroup & group, const Windows::UI::Xaml::VisualState & state, bool useTransitions)
    {
        return static_cast<T *>(this)->as<Windows::UI::Xaml::IVisualStateManagerOverrides>().GoToStateCore(control, templateRoot, stateName, group, state, useTransitions);
    }

    HRESULT __stdcall abi_GoToStateCore(abi_arg_in<Windows::UI::Xaml::Controls::IControl> control, abi_arg_in<Windows::UI::Xaml::IFrameworkElement> templateRoot, HSTRING stateName, abi_arg_in<Windows::UI::Xaml::IVisualStateGroup> group, abi_arg_in<Windows::UI::Xaml::IVisualState> state, bool useTransitions, bool * returnValue) noexcept override
    {
        try
        {
            *returnValue = detach(static_cast<T *>(this)->GoToStateCore(*reinterpret_cast<const Windows::UI::Xaml::Controls::Control *>(&control), *reinterpret_cast<const Windows::UI::Xaml::FrameworkElement *>(&templateRoot), *reinterpret_cast<const hstring *>(&stateName), *reinterpret_cast<const Windows::UI::Xaml::VisualStateGroup *>(&group), *reinterpret_cast<const Windows::UI::Xaml::VisualState *>(&state), useTransitions));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

}}}

namespace Windows { namespace UI { namespace Xaml { namespace Automation { namespace Peers {

template <typename T, typename A = ABI::Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides>
struct IAutomationPeerOverridesT : A
{
    Windows::IInspectable GetPatternCore(Windows::UI::Xaml::Automation::Peers::PatternInterface patternInterface)
    {
        return static_cast<T *>(this)->as<Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides>().GetPatternCore(patternInterface);
    }

    hstring GetAcceleratorKeyCore()
    {
        return static_cast<T *>(this)->as<Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides>().GetAcceleratorKeyCore();
    }

    hstring GetAccessKeyCore()
    {
        return static_cast<T *>(this)->as<Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides>().GetAccessKeyCore();
    }

    Windows::UI::Xaml::Automation::Peers::AutomationControlType GetAutomationControlTypeCore()
    {
        return static_cast<T *>(this)->as<Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides>().GetAutomationControlTypeCore();
    }

    hstring GetAutomationIdCore()
    {
        return static_cast<T *>(this)->as<Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides>().GetAutomationIdCore();
    }

    Windows::Foundation::Rect GetBoundingRectangleCore()
    {
        return static_cast<T *>(this)->as<Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides>().GetBoundingRectangleCore();
    }

    Windows::Foundation::Collections::IVector<Windows::UI::Xaml::Automation::Peers::AutomationPeer> GetChildrenCore()
    {
        return static_cast<T *>(this)->as<Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides>().GetChildrenCore();
    }

    hstring GetClassNameCore()
    {
        return static_cast<T *>(this)->as<Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides>().GetClassNameCore();
    }

    Windows::Foundation::Point GetClickablePointCore()
    {
        return static_cast<T *>(this)->as<Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides>().GetClickablePointCore();
    }

    hstring GetHelpTextCore()
    {
        return static_cast<T *>(this)->as<Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides>().GetHelpTextCore();
    }

    hstring GetItemStatusCore()
    {
        return static_cast<T *>(this)->as<Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides>().GetItemStatusCore();
    }

    hstring GetItemTypeCore()
    {
        return static_cast<T *>(this)->as<Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides>().GetItemTypeCore();
    }

    Windows::UI::Xaml::Automation::Peers::AutomationPeer GetLabeledByCore()
    {
        return static_cast<T *>(this)->as<Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides>().GetLabeledByCore();
    }

    hstring GetLocalizedControlTypeCore()
    {
        return static_cast<T *>(this)->as<Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides>().GetLocalizedControlTypeCore();
    }

    hstring GetNameCore()
    {
        return static_cast<T *>(this)->as<Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides>().GetNameCore();
    }

    Windows::UI::Xaml::Automation::Peers::AutomationOrientation GetOrientationCore()
    {
        return static_cast<T *>(this)->as<Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides>().GetOrientationCore();
    }

    bool HasKeyboardFocusCore()
    {
        return static_cast<T *>(this)->as<Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides>().HasKeyboardFocusCore();
    }

    bool IsContentElementCore()
    {
        return static_cast<T *>(this)->as<Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides>().IsContentElementCore();
    }

    bool IsControlElementCore()
    {
        return static_cast<T *>(this)->as<Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides>().IsControlElementCore();
    }

    bool IsEnabledCore()
    {
        return static_cast<T *>(this)->as<Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides>().IsEnabledCore();
    }

    bool IsKeyboardFocusableCore()
    {
        return static_cast<T *>(this)->as<Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides>().IsKeyboardFocusableCore();
    }

    bool IsOffscreenCore()
    {
        return static_cast<T *>(this)->as<Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides>().IsOffscreenCore();
    }

    bool IsPasswordCore()
    {
        return static_cast<T *>(this)->as<Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides>().IsPasswordCore();
    }

    bool IsRequiredForFormCore()
    {
        return static_cast<T *>(this)->as<Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides>().IsRequiredForFormCore();
    }

    void SetFocusCore()
    {
        static_cast<T *>(this)->as<Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides>().SetFocusCore();
    }

    Windows::UI::Xaml::Automation::Peers::AutomationPeer GetPeerFromPointCore(const Windows::Foundation::Point & point)
    {
        return static_cast<T *>(this)->as<Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides>().GetPeerFromPointCore(point);
    }

    Windows::UI::Xaml::Automation::Peers::AutomationLiveSetting GetLiveSettingCore()
    {
        return static_cast<T *>(this)->as<Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides>().GetLiveSettingCore();
    }

    HRESULT __stdcall abi_GetPatternCore(Windows::UI::Xaml::Automation::Peers::PatternInterface patternInterface, abi_arg_out<Windows::IInspectable> returnValue) noexcept override
    {
        try
        {
            *returnValue = detach(static_cast<T *>(this)->GetPatternCore(patternInterface));
            return S_OK;
        }
        catch (...)
        {
            *returnValue = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetAcceleratorKeyCore(HSTRING * returnValue) noexcept override
    {
        try
        {
            *returnValue = detach(static_cast<T *>(this)->GetAcceleratorKeyCore());
            return S_OK;
        }
        catch (...)
        {
            *returnValue = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetAccessKeyCore(HSTRING * returnValue) noexcept override
    {
        try
        {
            *returnValue = detach(static_cast<T *>(this)->GetAccessKeyCore());
            return S_OK;
        }
        catch (...)
        {
            *returnValue = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetAutomationControlTypeCore(Windows::UI::Xaml::Automation::Peers::AutomationControlType * returnValue) noexcept override
    {
        try
        {
            *returnValue = detach(static_cast<T *>(this)->GetAutomationControlTypeCore());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetAutomationIdCore(HSTRING * returnValue) noexcept override
    {
        try
        {
            *returnValue = detach(static_cast<T *>(this)->GetAutomationIdCore());
            return S_OK;
        }
        catch (...)
        {
            *returnValue = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetBoundingRectangleCore(Windows::Foundation::Rect * returnValue) noexcept override
    {
        try
        {
            *returnValue = detach(static_cast<T *>(this)->GetBoundingRectangleCore());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetChildrenCore(abi_arg_out<Windows::Foundation::Collections::IVector<Windows::UI::Xaml::Automation::Peers::AutomationPeer>> returnValue) noexcept override
    {
        try
        {
            *returnValue = detach(static_cast<T *>(this)->GetChildrenCore());
            return S_OK;
        }
        catch (...)
        {
            *returnValue = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetClassNameCore(HSTRING * returnValue) noexcept override
    {
        try
        {
            *returnValue = detach(static_cast<T *>(this)->GetClassNameCore());
            return S_OK;
        }
        catch (...)
        {
            *returnValue = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetClickablePointCore(Windows::Foundation::Point * returnValue) noexcept override
    {
        try
        {
            *returnValue = detach(static_cast<T *>(this)->GetClickablePointCore());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetHelpTextCore(HSTRING * returnValue) noexcept override
    {
        try
        {
            *returnValue = detach(static_cast<T *>(this)->GetHelpTextCore());
            return S_OK;
        }
        catch (...)
        {
            *returnValue = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetItemStatusCore(HSTRING * returnValue) noexcept override
    {
        try
        {
            *returnValue = detach(static_cast<T *>(this)->GetItemStatusCore());
            return S_OK;
        }
        catch (...)
        {
            *returnValue = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetItemTypeCore(HSTRING * returnValue) noexcept override
    {
        try
        {
            *returnValue = detach(static_cast<T *>(this)->GetItemTypeCore());
            return S_OK;
        }
        catch (...)
        {
            *returnValue = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetLabeledByCore(abi_arg_out<Windows::UI::Xaml::Automation::Peers::IAutomationPeer> returnValue) noexcept override
    {
        try
        {
            *returnValue = detach(static_cast<T *>(this)->GetLabeledByCore());
            return S_OK;
        }
        catch (...)
        {
            *returnValue = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetLocalizedControlTypeCore(HSTRING * returnValue) noexcept override
    {
        try
        {
            *returnValue = detach(static_cast<T *>(this)->GetLocalizedControlTypeCore());
            return S_OK;
        }
        catch (...)
        {
            *returnValue = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetNameCore(HSTRING * returnValue) noexcept override
    {
        try
        {
            *returnValue = detach(static_cast<T *>(this)->GetNameCore());
            return S_OK;
        }
        catch (...)
        {
            *returnValue = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetOrientationCore(Windows::UI::Xaml::Automation::Peers::AutomationOrientation * returnValue) noexcept override
    {
        try
        {
            *returnValue = detach(static_cast<T *>(this)->GetOrientationCore());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_HasKeyboardFocusCore(bool * returnValue) noexcept override
    {
        try
        {
            *returnValue = detach(static_cast<T *>(this)->HasKeyboardFocusCore());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_IsContentElementCore(bool * returnValue) noexcept override
    {
        try
        {
            *returnValue = detach(static_cast<T *>(this)->IsContentElementCore());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_IsControlElementCore(bool * returnValue) noexcept override
    {
        try
        {
            *returnValue = detach(static_cast<T *>(this)->IsControlElementCore());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_IsEnabledCore(bool * returnValue) noexcept override
    {
        try
        {
            *returnValue = detach(static_cast<T *>(this)->IsEnabledCore());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_IsKeyboardFocusableCore(bool * returnValue) noexcept override
    {
        try
        {
            *returnValue = detach(static_cast<T *>(this)->IsKeyboardFocusableCore());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_IsOffscreenCore(bool * returnValue) noexcept override
    {
        try
        {
            *returnValue = detach(static_cast<T *>(this)->IsOffscreenCore());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_IsPasswordCore(bool * returnValue) noexcept override
    {
        try
        {
            *returnValue = detach(static_cast<T *>(this)->IsPasswordCore());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_IsRequiredForFormCore(bool * returnValue) noexcept override
    {
        try
        {
            *returnValue = detach(static_cast<T *>(this)->IsRequiredForFormCore());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_SetFocusCore() noexcept override
    {
        try
        {
            static_cast<T *>(this)->SetFocusCore();
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetPeerFromPointCore(Windows::Foundation::Point point, abi_arg_out<Windows::UI::Xaml::Automation::Peers::IAutomationPeer> returnValue) noexcept override
    {
        try
        {
            *returnValue = detach(static_cast<T *>(this)->GetPeerFromPointCore(point));
            return S_OK;
        }
        catch (...)
        {
            *returnValue = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetLiveSettingCore(Windows::UI::Xaml::Automation::Peers::AutomationLiveSetting * returnValue) noexcept override
    {
        try
        {
            *returnValue = detach(static_cast<T *>(this)->GetLiveSettingCore());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename T, typename A = ABI::Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2>
struct IAutomationPeerOverrides2T : A
{
    void ShowContextMenuCore()
    {
        static_cast<T *>(this)->as<Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2>().ShowContextMenuCore();
    }

    Windows::Foundation::Collections::IVectorView<Windows::UI::Xaml::Automation::Peers::AutomationPeer> GetControlledPeersCore()
    {
        return static_cast<T *>(this)->as<Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2>().GetControlledPeersCore();
    }

    HRESULT __stdcall abi_ShowContextMenuCore() noexcept override
    {
        try
        {
            static_cast<T *>(this)->ShowContextMenuCore();
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetControlledPeersCore(abi_arg_out<Windows::Foundation::Collections::IVectorView<Windows::UI::Xaml::Automation::Peers::AutomationPeer>> returnValue) noexcept override
    {
        try
        {
            *returnValue = detach(static_cast<T *>(this)->GetControlledPeersCore());
            return S_OK;
        }
        catch (...)
        {
            *returnValue = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename T, typename A = ABI::Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3>
struct IAutomationPeerOverrides3T : A
{
    Windows::IInspectable NavigateCore(Windows::UI::Xaml::Automation::Peers::AutomationNavigationDirection direction)
    {
        return static_cast<T *>(this)->as<Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3>().NavigateCore(direction);
    }

    Windows::IInspectable GetElementFromPointCore(const Windows::Foundation::Point & pointInWindowCoordinates)
    {
        return static_cast<T *>(this)->as<Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3>().GetElementFromPointCore(pointInWindowCoordinates);
    }

    Windows::IInspectable GetFocusedElementCore()
    {
        return static_cast<T *>(this)->as<Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3>().GetFocusedElementCore();
    }

    Windows::Foundation::Collections::IVector<Windows::UI::Xaml::Automation::Peers::AutomationPeerAnnotation> GetAnnotationsCore()
    {
        return static_cast<T *>(this)->as<Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3>().GetAnnotationsCore();
    }

    int32_t GetPositionInSetCore()
    {
        return static_cast<T *>(this)->as<Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3>().GetPositionInSetCore();
    }

    int32_t GetSizeOfSetCore()
    {
        return static_cast<T *>(this)->as<Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3>().GetSizeOfSetCore();
    }

    int32_t GetLevelCore()
    {
        return static_cast<T *>(this)->as<Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3>().GetLevelCore();
    }

    HRESULT __stdcall abi_NavigateCore(Windows::UI::Xaml::Automation::Peers::AutomationNavigationDirection direction, abi_arg_out<Windows::IInspectable> returnValue) noexcept override
    {
        try
        {
            *returnValue = detach(static_cast<T *>(this)->NavigateCore(direction));
            return S_OK;
        }
        catch (...)
        {
            *returnValue = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetElementFromPointCore(Windows::Foundation::Point pointInWindowCoordinates, abi_arg_out<Windows::IInspectable> returnValue) noexcept override
    {
        try
        {
            *returnValue = detach(static_cast<T *>(this)->GetElementFromPointCore(pointInWindowCoordinates));
            return S_OK;
        }
        catch (...)
        {
            *returnValue = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetFocusedElementCore(abi_arg_out<Windows::IInspectable> returnValue) noexcept override
    {
        try
        {
            *returnValue = detach(static_cast<T *>(this)->GetFocusedElementCore());
            return S_OK;
        }
        catch (...)
        {
            *returnValue = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetAnnotationsCore(abi_arg_out<Windows::Foundation::Collections::IVector<Windows::UI::Xaml::Automation::Peers::AutomationPeerAnnotation>> returnValue) noexcept override
    {
        try
        {
            *returnValue = detach(static_cast<T *>(this)->GetAnnotationsCore());
            return S_OK;
        }
        catch (...)
        {
            *returnValue = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetPositionInSetCore(int32_t * returnValue) noexcept override
    {
        try
        {
            *returnValue = detach(static_cast<T *>(this)->GetPositionInSetCore());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetSizeOfSetCore(int32_t * returnValue) noexcept override
    {
        try
        {
            *returnValue = detach(static_cast<T *>(this)->GetSizeOfSetCore());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetLevelCore(int32_t * returnValue) noexcept override
    {
        try
        {
            *returnValue = detach(static_cast<T *>(this)->GetLevelCore());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename T, typename A = ABI::Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides4>
struct IAutomationPeerOverrides4T : A
{
    Windows::UI::Xaml::Automation::Peers::AutomationLandmarkType GetLandmarkTypeCore()
    {
        return static_cast<T *>(this)->as<Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides4>().GetLandmarkTypeCore();
    }

    hstring GetLocalizedLandmarkTypeCore()
    {
        return static_cast<T *>(this)->as<Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides4>().GetLocalizedLandmarkTypeCore();
    }

    HRESULT __stdcall abi_GetLandmarkTypeCore(Windows::UI::Xaml::Automation::Peers::AutomationLandmarkType * returnValue) noexcept override
    {
        try
        {
            *returnValue = detach(static_cast<T *>(this)->GetLandmarkTypeCore());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetLocalizedLandmarkTypeCore(HSTRING * returnValue) noexcept override
    {
        try
        {
            *returnValue = detach(static_cast<T *>(this)->GetLocalizedLandmarkTypeCore());
            return S_OK;
        }
        catch (...)
        {
            *returnValue = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename T, typename A = ABI::Windows::UI::Xaml::Automation::Peers::IItemsControlAutomationPeerOverrides2>
struct IItemsControlAutomationPeerOverrides2T : A
{
    Windows::UI::Xaml::Automation::Peers::ItemAutomationPeer OnCreateItemAutomationPeer(const Windows::IInspectable & item)
    {
        return static_cast<T *>(this)->as<Windows::UI::Xaml::Automation::Peers::IItemsControlAutomationPeerOverrides2>().OnCreateItemAutomationPeer(item);
    }

    HRESULT __stdcall abi_OnCreateItemAutomationPeer(abi_arg_in<Windows::IInspectable> item, abi_arg_out<Windows::UI::Xaml::Automation::Peers::IItemAutomationPeer> returnValue) noexcept override
    {
        try
        {
            *returnValue = detach(static_cast<T *>(this)->OnCreateItemAutomationPeer(*reinterpret_cast<const Windows::IInspectable *>(&item)));
            return S_OK;
        }
        catch (...)
        {
            *returnValue = nullptr;
            return impl::to_hresult();
        }
    }
};

}}}}}

namespace Windows { namespace UI { namespace Xaml { namespace Controls {

template <typename T, typename A = ABI::Windows::UI::Xaml::Controls::IAppBarOverrides>
struct IAppBarOverridesT : A
{
    void OnClosed(const Windows::IInspectable & e)
    {
        static_cast<T *>(this)->as<Windows::UI::Xaml::Controls::IAppBarOverrides>().OnClosed(e);
    }

    void OnOpened(const Windows::IInspectable & e)
    {
        static_cast<T *>(this)->as<Windows::UI::Xaml::Controls::IAppBarOverrides>().OnOpened(e);
    }

    HRESULT __stdcall abi_OnClosed(abi_arg_in<Windows::IInspectable> e) noexcept override
    {
        try
        {
            static_cast<T *>(this)->OnClosed(*reinterpret_cast<const Windows::IInspectable *>(&e));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_OnOpened(abi_arg_in<Windows::IInspectable> e) noexcept override
    {
        try
        {
            static_cast<T *>(this)->OnOpened(*reinterpret_cast<const Windows::IInspectable *>(&e));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename T, typename A = ABI::Windows::UI::Xaml::Controls::IAppBarOverrides3>
struct IAppBarOverrides3T : A
{
    void OnClosing(const Windows::IInspectable & e)
    {
        static_cast<T *>(this)->as<Windows::UI::Xaml::Controls::IAppBarOverrides3>().OnClosing(e);
    }

    void OnOpening(const Windows::IInspectable & e)
    {
        static_cast<T *>(this)->as<Windows::UI::Xaml::Controls::IAppBarOverrides3>().OnOpening(e);
    }

    HRESULT __stdcall abi_OnClosing(abi_arg_in<Windows::IInspectable> e) noexcept override
    {
        try
        {
            static_cast<T *>(this)->OnClosing(*reinterpret_cast<const Windows::IInspectable *>(&e));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_OnOpening(abi_arg_in<Windows::IInspectable> e) noexcept override
    {
        try
        {
            static_cast<T *>(this)->OnOpening(*reinterpret_cast<const Windows::IInspectable *>(&e));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename T, typename A = ABI::Windows::UI::Xaml::Controls::IComboBoxOverrides>
struct IComboBoxOverridesT : A
{
    void OnDropDownClosed(const Windows::IInspectable & e)
    {
        static_cast<T *>(this)->as<Windows::UI::Xaml::Controls::IComboBoxOverrides>().OnDropDownClosed(e);
    }

    void OnDropDownOpened(const Windows::IInspectable & e)
    {
        static_cast<T *>(this)->as<Windows::UI::Xaml::Controls::IComboBoxOverrides>().OnDropDownOpened(e);
    }

    HRESULT __stdcall abi_OnDropDownClosed(abi_arg_in<Windows::IInspectable> e) noexcept override
    {
        try
        {
            static_cast<T *>(this)->OnDropDownClosed(*reinterpret_cast<const Windows::IInspectable *>(&e));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_OnDropDownOpened(abi_arg_in<Windows::IInspectable> e) noexcept override
    {
        try
        {
            static_cast<T *>(this)->OnDropDownOpened(*reinterpret_cast<const Windows::IInspectable *>(&e));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename T, typename A = ABI::Windows::UI::Xaml::Controls::IContentControlOverrides>
struct IContentControlOverridesT : A
{
    void OnContentChanged(const Windows::IInspectable & oldContent, const Windows::IInspectable & newContent)
    {
        static_cast<T *>(this)->as<Windows::UI::Xaml::Controls::IContentControlOverrides>().OnContentChanged(oldContent, newContent);
    }

    void OnContentTemplateChanged(const Windows::UI::Xaml::DataTemplate & oldContentTemplate, const Windows::UI::Xaml::DataTemplate & newContentTemplate)
    {
        static_cast<T *>(this)->as<Windows::UI::Xaml::Controls::IContentControlOverrides>().OnContentTemplateChanged(oldContentTemplate, newContentTemplate);
    }

    void OnContentTemplateSelectorChanged(const Windows::UI::Xaml::Controls::DataTemplateSelector & oldContentTemplateSelector, const Windows::UI::Xaml::Controls::DataTemplateSelector & newContentTemplateSelector)
    {
        static_cast<T *>(this)->as<Windows::UI::Xaml::Controls::IContentControlOverrides>().OnContentTemplateSelectorChanged(oldContentTemplateSelector, newContentTemplateSelector);
    }

    HRESULT __stdcall abi_OnContentChanged(abi_arg_in<Windows::IInspectable> oldContent, abi_arg_in<Windows::IInspectable> newContent) noexcept override
    {
        try
        {
            static_cast<T *>(this)->OnContentChanged(*reinterpret_cast<const Windows::IInspectable *>(&oldContent), *reinterpret_cast<const Windows::IInspectable *>(&newContent));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_OnContentTemplateChanged(abi_arg_in<Windows::UI::Xaml::IDataTemplate> oldContentTemplate, abi_arg_in<Windows::UI::Xaml::IDataTemplate> newContentTemplate) noexcept override
    {
        try
        {
            static_cast<T *>(this)->OnContentTemplateChanged(*reinterpret_cast<const Windows::UI::Xaml::DataTemplate *>(&oldContentTemplate), *reinterpret_cast<const Windows::UI::Xaml::DataTemplate *>(&newContentTemplate));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_OnContentTemplateSelectorChanged(abi_arg_in<Windows::UI::Xaml::Controls::IDataTemplateSelector> oldContentTemplateSelector, abi_arg_in<Windows::UI::Xaml::Controls::IDataTemplateSelector> newContentTemplateSelector) noexcept override
    {
        try
        {
            static_cast<T *>(this)->OnContentTemplateSelectorChanged(*reinterpret_cast<const Windows::UI::Xaml::Controls::DataTemplateSelector *>(&oldContentTemplateSelector), *reinterpret_cast<const Windows::UI::Xaml::Controls::DataTemplateSelector *>(&newContentTemplateSelector));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename T, typename A = ABI::Windows::UI::Xaml::Controls::IContentPresenterOverrides>
struct IContentPresenterOverridesT : A
{
    void OnContentTemplateChanged(const Windows::UI::Xaml::DataTemplate & oldContentTemplate, const Windows::UI::Xaml::DataTemplate & newContentTemplate)
    {
        static_cast<T *>(this)->as<Windows::UI::Xaml::Controls::IContentPresenterOverrides>().OnContentTemplateChanged(oldContentTemplate, newContentTemplate);
    }

    void OnContentTemplateSelectorChanged(const Windows::UI::Xaml::Controls::DataTemplateSelector & oldContentTemplateSelector, const Windows::UI::Xaml::Controls::DataTemplateSelector & newContentTemplateSelector)
    {
        static_cast<T *>(this)->as<Windows::UI::Xaml::Controls::IContentPresenterOverrides>().OnContentTemplateSelectorChanged(oldContentTemplateSelector, newContentTemplateSelector);
    }

    HRESULT __stdcall abi_OnContentTemplateChanged(abi_arg_in<Windows::UI::Xaml::IDataTemplate> oldContentTemplate, abi_arg_in<Windows::UI::Xaml::IDataTemplate> newContentTemplate) noexcept override
    {
        try
        {
            static_cast<T *>(this)->OnContentTemplateChanged(*reinterpret_cast<const Windows::UI::Xaml::DataTemplate *>(&oldContentTemplate), *reinterpret_cast<const Windows::UI::Xaml::DataTemplate *>(&newContentTemplate));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_OnContentTemplateSelectorChanged(abi_arg_in<Windows::UI::Xaml::Controls::IDataTemplateSelector> oldContentTemplateSelector, abi_arg_in<Windows::UI::Xaml::Controls::IDataTemplateSelector> newContentTemplateSelector) noexcept override
    {
        try
        {
            static_cast<T *>(this)->OnContentTemplateSelectorChanged(*reinterpret_cast<const Windows::UI::Xaml::Controls::DataTemplateSelector *>(&oldContentTemplateSelector), *reinterpret_cast<const Windows::UI::Xaml::Controls::DataTemplateSelector *>(&newContentTemplateSelector));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename T, typename A = ABI::Windows::UI::Xaml::Controls::IControlOverrides>
struct IControlOverridesT : A
{
    void OnPointerEntered(const Windows::UI::Xaml::Input::PointerRoutedEventArgs & e)
    {
        static_cast<T *>(this)->as<Windows::UI::Xaml::Controls::IControlOverrides>().OnPointerEntered(e);
    }

    void OnPointerPressed(const Windows::UI::Xaml::Input::PointerRoutedEventArgs & e)
    {
        static_cast<T *>(this)->as<Windows::UI::Xaml::Controls::IControlOverrides>().OnPointerPressed(e);
    }

    void OnPointerMoved(const Windows::UI::Xaml::Input::PointerRoutedEventArgs & e)
    {
        static_cast<T *>(this)->as<Windows::UI::Xaml::Controls::IControlOverrides>().OnPointerMoved(e);
    }

    void OnPointerReleased(const Windows::UI::Xaml::Input::PointerRoutedEventArgs & e)
    {
        static_cast<T *>(this)->as<Windows::UI::Xaml::Controls::IControlOverrides>().OnPointerReleased(e);
    }

    void OnPointerExited(const Windows::UI::Xaml::Input::PointerRoutedEventArgs & e)
    {
        static_cast<T *>(this)->as<Windows::UI::Xaml::Controls::IControlOverrides>().OnPointerExited(e);
    }

    void OnPointerCaptureLost(const Windows::UI::Xaml::Input::PointerRoutedEventArgs & e)
    {
        static_cast<T *>(this)->as<Windows::UI::Xaml::Controls::IControlOverrides>().OnPointerCaptureLost(e);
    }

    void OnPointerCanceled(const Windows::UI::Xaml::Input::PointerRoutedEventArgs & e)
    {
        static_cast<T *>(this)->as<Windows::UI::Xaml::Controls::IControlOverrides>().OnPointerCanceled(e);
    }

    void OnPointerWheelChanged(const Windows::UI::Xaml::Input::PointerRoutedEventArgs & e)
    {
        static_cast<T *>(this)->as<Windows::UI::Xaml::Controls::IControlOverrides>().OnPointerWheelChanged(e);
    }

    void OnTapped(const Windows::UI::Xaml::Input::TappedRoutedEventArgs & e)
    {
        static_cast<T *>(this)->as<Windows::UI::Xaml::Controls::IControlOverrides>().OnTapped(e);
    }

    void OnDoubleTapped(const Windows::UI::Xaml::Input::DoubleTappedRoutedEventArgs & e)
    {
        static_cast<T *>(this)->as<Windows::UI::Xaml::Controls::IControlOverrides>().OnDoubleTapped(e);
    }

    void OnHolding(const Windows::UI::Xaml::Input::HoldingRoutedEventArgs & e)
    {
        static_cast<T *>(this)->as<Windows::UI::Xaml::Controls::IControlOverrides>().OnHolding(e);
    }

    void OnRightTapped(const Windows::UI::Xaml::Input::RightTappedRoutedEventArgs & e)
    {
        static_cast<T *>(this)->as<Windows::UI::Xaml::Controls::IControlOverrides>().OnRightTapped(e);
    }

    void OnManipulationStarting(const Windows::UI::Xaml::Input::ManipulationStartingRoutedEventArgs & e)
    {
        static_cast<T *>(this)->as<Windows::UI::Xaml::Controls::IControlOverrides>().OnManipulationStarting(e);
    }

    void OnManipulationInertiaStarting(const Windows::UI::Xaml::Input::ManipulationInertiaStartingRoutedEventArgs & e)
    {
        static_cast<T *>(this)->as<Windows::UI::Xaml::Controls::IControlOverrides>().OnManipulationInertiaStarting(e);
    }

    void OnManipulationStarted(const Windows::UI::Xaml::Input::ManipulationStartedRoutedEventArgs & e)
    {
        static_cast<T *>(this)->as<Windows::UI::Xaml::Controls::IControlOverrides>().OnManipulationStarted(e);
    }

    void OnManipulationDelta(const Windows::UI::Xaml::Input::ManipulationDeltaRoutedEventArgs & e)
    {
        static_cast<T *>(this)->as<Windows::UI::Xaml::Controls::IControlOverrides>().OnManipulationDelta(e);
    }

    void OnManipulationCompleted(const Windows::UI::Xaml::Input::ManipulationCompletedRoutedEventArgs & e)
    {
        static_cast<T *>(this)->as<Windows::UI::Xaml::Controls::IControlOverrides>().OnManipulationCompleted(e);
    }

    void OnKeyUp(const Windows::UI::Xaml::Input::KeyRoutedEventArgs & e)
    {
        static_cast<T *>(this)->as<Windows::UI::Xaml::Controls::IControlOverrides>().OnKeyUp(e);
    }

    void OnKeyDown(const Windows::UI::Xaml::Input::KeyRoutedEventArgs & e)
    {
        static_cast<T *>(this)->as<Windows::UI::Xaml::Controls::IControlOverrides>().OnKeyDown(e);
    }

    void OnGotFocus(const Windows::UI::Xaml::RoutedEventArgs & e)
    {
        static_cast<T *>(this)->as<Windows::UI::Xaml::Controls::IControlOverrides>().OnGotFocus(e);
    }

    void OnLostFocus(const Windows::UI::Xaml::RoutedEventArgs & e)
    {
        static_cast<T *>(this)->as<Windows::UI::Xaml::Controls::IControlOverrides>().OnLostFocus(e);
    }

    void OnDragEnter(const Windows::UI::Xaml::DragEventArgs & e)
    {
        static_cast<T *>(this)->as<Windows::UI::Xaml::Controls::IControlOverrides>().OnDragEnter(e);
    }

    void OnDragLeave(const Windows::UI::Xaml::DragEventArgs & e)
    {
        static_cast<T *>(this)->as<Windows::UI::Xaml::Controls::IControlOverrides>().OnDragLeave(e);
    }

    void OnDragOver(const Windows::UI::Xaml::DragEventArgs & e)
    {
        static_cast<T *>(this)->as<Windows::UI::Xaml::Controls::IControlOverrides>().OnDragOver(e);
    }

    void OnDrop(const Windows::UI::Xaml::DragEventArgs & e)
    {
        static_cast<T *>(this)->as<Windows::UI::Xaml::Controls::IControlOverrides>().OnDrop(e);
    }

    HRESULT __stdcall abi_OnPointerEntered(abi_arg_in<Windows::UI::Xaml::Input::IPointerRoutedEventArgs> e) noexcept override
    {
        try
        {
            static_cast<T *>(this)->OnPointerEntered(*reinterpret_cast<const Windows::UI::Xaml::Input::PointerRoutedEventArgs *>(&e));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_OnPointerPressed(abi_arg_in<Windows::UI::Xaml::Input::IPointerRoutedEventArgs> e) noexcept override
    {
        try
        {
            static_cast<T *>(this)->OnPointerPressed(*reinterpret_cast<const Windows::UI::Xaml::Input::PointerRoutedEventArgs *>(&e));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_OnPointerMoved(abi_arg_in<Windows::UI::Xaml::Input::IPointerRoutedEventArgs> e) noexcept override
    {
        try
        {
            static_cast<T *>(this)->OnPointerMoved(*reinterpret_cast<const Windows::UI::Xaml::Input::PointerRoutedEventArgs *>(&e));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_OnPointerReleased(abi_arg_in<Windows::UI::Xaml::Input::IPointerRoutedEventArgs> e) noexcept override
    {
        try
        {
            static_cast<T *>(this)->OnPointerReleased(*reinterpret_cast<const Windows::UI::Xaml::Input::PointerRoutedEventArgs *>(&e));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_OnPointerExited(abi_arg_in<Windows::UI::Xaml::Input::IPointerRoutedEventArgs> e) noexcept override
    {
        try
        {
            static_cast<T *>(this)->OnPointerExited(*reinterpret_cast<const Windows::UI::Xaml::Input::PointerRoutedEventArgs *>(&e));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_OnPointerCaptureLost(abi_arg_in<Windows::UI::Xaml::Input::IPointerRoutedEventArgs> e) noexcept override
    {
        try
        {
            static_cast<T *>(this)->OnPointerCaptureLost(*reinterpret_cast<const Windows::UI::Xaml::Input::PointerRoutedEventArgs *>(&e));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_OnPointerCanceled(abi_arg_in<Windows::UI::Xaml::Input::IPointerRoutedEventArgs> e) noexcept override
    {
        try
        {
            static_cast<T *>(this)->OnPointerCanceled(*reinterpret_cast<const Windows::UI::Xaml::Input::PointerRoutedEventArgs *>(&e));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_OnPointerWheelChanged(abi_arg_in<Windows::UI::Xaml::Input::IPointerRoutedEventArgs> e) noexcept override
    {
        try
        {
            static_cast<T *>(this)->OnPointerWheelChanged(*reinterpret_cast<const Windows::UI::Xaml::Input::PointerRoutedEventArgs *>(&e));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_OnTapped(abi_arg_in<Windows::UI::Xaml::Input::ITappedRoutedEventArgs> e) noexcept override
    {
        try
        {
            static_cast<T *>(this)->OnTapped(*reinterpret_cast<const Windows::UI::Xaml::Input::TappedRoutedEventArgs *>(&e));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_OnDoubleTapped(abi_arg_in<Windows::UI::Xaml::Input::IDoubleTappedRoutedEventArgs> e) noexcept override
    {
        try
        {
            static_cast<T *>(this)->OnDoubleTapped(*reinterpret_cast<const Windows::UI::Xaml::Input::DoubleTappedRoutedEventArgs *>(&e));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_OnHolding(abi_arg_in<Windows::UI::Xaml::Input::IHoldingRoutedEventArgs> e) noexcept override
    {
        try
        {
            static_cast<T *>(this)->OnHolding(*reinterpret_cast<const Windows::UI::Xaml::Input::HoldingRoutedEventArgs *>(&e));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_OnRightTapped(abi_arg_in<Windows::UI::Xaml::Input::IRightTappedRoutedEventArgs> e) noexcept override
    {
        try
        {
            static_cast<T *>(this)->OnRightTapped(*reinterpret_cast<const Windows::UI::Xaml::Input::RightTappedRoutedEventArgs *>(&e));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_OnManipulationStarting(abi_arg_in<Windows::UI::Xaml::Input::IManipulationStartingRoutedEventArgs> e) noexcept override
    {
        try
        {
            static_cast<T *>(this)->OnManipulationStarting(*reinterpret_cast<const Windows::UI::Xaml::Input::ManipulationStartingRoutedEventArgs *>(&e));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_OnManipulationInertiaStarting(abi_arg_in<Windows::UI::Xaml::Input::IManipulationInertiaStartingRoutedEventArgs> e) noexcept override
    {
        try
        {
            static_cast<T *>(this)->OnManipulationInertiaStarting(*reinterpret_cast<const Windows::UI::Xaml::Input::ManipulationInertiaStartingRoutedEventArgs *>(&e));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_OnManipulationStarted(abi_arg_in<Windows::UI::Xaml::Input::IManipulationStartedRoutedEventArgs> e) noexcept override
    {
        try
        {
            static_cast<T *>(this)->OnManipulationStarted(*reinterpret_cast<const Windows::UI::Xaml::Input::ManipulationStartedRoutedEventArgs *>(&e));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_OnManipulationDelta(abi_arg_in<Windows::UI::Xaml::Input::IManipulationDeltaRoutedEventArgs> e) noexcept override
    {
        try
        {
            static_cast<T *>(this)->OnManipulationDelta(*reinterpret_cast<const Windows::UI::Xaml::Input::ManipulationDeltaRoutedEventArgs *>(&e));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_OnManipulationCompleted(abi_arg_in<Windows::UI::Xaml::Input::IManipulationCompletedRoutedEventArgs> e) noexcept override
    {
        try
        {
            static_cast<T *>(this)->OnManipulationCompleted(*reinterpret_cast<const Windows::UI::Xaml::Input::ManipulationCompletedRoutedEventArgs *>(&e));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_OnKeyUp(abi_arg_in<Windows::UI::Xaml::Input::IKeyRoutedEventArgs> e) noexcept override
    {
        try
        {
            static_cast<T *>(this)->OnKeyUp(*reinterpret_cast<const Windows::UI::Xaml::Input::KeyRoutedEventArgs *>(&e));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_OnKeyDown(abi_arg_in<Windows::UI::Xaml::Input::IKeyRoutedEventArgs> e) noexcept override
    {
        try
        {
            static_cast<T *>(this)->OnKeyDown(*reinterpret_cast<const Windows::UI::Xaml::Input::KeyRoutedEventArgs *>(&e));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_OnGotFocus(abi_arg_in<Windows::UI::Xaml::IRoutedEventArgs> e) noexcept override
    {
        try
        {
            static_cast<T *>(this)->OnGotFocus(*reinterpret_cast<const Windows::UI::Xaml::RoutedEventArgs *>(&e));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_OnLostFocus(abi_arg_in<Windows::UI::Xaml::IRoutedEventArgs> e) noexcept override
    {
        try
        {
            static_cast<T *>(this)->OnLostFocus(*reinterpret_cast<const Windows::UI::Xaml::RoutedEventArgs *>(&e));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_OnDragEnter(abi_arg_in<Windows::UI::Xaml::IDragEventArgs> e) noexcept override
    {
        try
        {
            static_cast<T *>(this)->OnDragEnter(*reinterpret_cast<const Windows::UI::Xaml::DragEventArgs *>(&e));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_OnDragLeave(abi_arg_in<Windows::UI::Xaml::IDragEventArgs> e) noexcept override
    {
        try
        {
            static_cast<T *>(this)->OnDragLeave(*reinterpret_cast<const Windows::UI::Xaml::DragEventArgs *>(&e));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_OnDragOver(abi_arg_in<Windows::UI::Xaml::IDragEventArgs> e) noexcept override
    {
        try
        {
            static_cast<T *>(this)->OnDragOver(*reinterpret_cast<const Windows::UI::Xaml::DragEventArgs *>(&e));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_OnDrop(abi_arg_in<Windows::UI::Xaml::IDragEventArgs> e) noexcept override
    {
        try
        {
            static_cast<T *>(this)->OnDrop(*reinterpret_cast<const Windows::UI::Xaml::DragEventArgs *>(&e));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename T, typename A = ABI::Windows::UI::Xaml::Controls::IDataTemplateSelectorOverrides>
struct IDataTemplateSelectorOverridesT : A
{
    Windows::UI::Xaml::DataTemplate SelectTemplateCore(const Windows::IInspectable & item, const Windows::UI::Xaml::DependencyObject & container)
    {
        return static_cast<T *>(this)->as<Windows::UI::Xaml::Controls::IDataTemplateSelectorOverrides>().SelectTemplateCore(item, container);
    }

    HRESULT __stdcall abi_SelectTemplateCore(abi_arg_in<Windows::IInspectable> item, abi_arg_in<Windows::UI::Xaml::IDependencyObject> container, abi_arg_out<Windows::UI::Xaml::IDataTemplate> returnValue) noexcept override
    {
        try
        {
            *returnValue = detach(static_cast<T *>(this)->SelectTemplateCore(*reinterpret_cast<const Windows::IInspectable *>(&item), *reinterpret_cast<const Windows::UI::Xaml::DependencyObject *>(&container)));
            return S_OK;
        }
        catch (...)
        {
            *returnValue = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename T, typename A = ABI::Windows::UI::Xaml::Controls::IDataTemplateSelectorOverrides2>
struct IDataTemplateSelectorOverrides2T : A
{
    Windows::UI::Xaml::DataTemplate SelectTemplateCore(const Windows::IInspectable & item)
    {
        return static_cast<T *>(this)->as<Windows::UI::Xaml::Controls::IDataTemplateSelectorOverrides2>().SelectTemplateCore(item);
    }

    HRESULT __stdcall abi_SelectTemplateForItemCore(abi_arg_in<Windows::IInspectable> item, abi_arg_out<Windows::UI::Xaml::IDataTemplate> returnValue) noexcept override
    {
        try
        {
            *returnValue = detach(static_cast<T *>(this)->SelectTemplateCore(*reinterpret_cast<const Windows::IInspectable *>(&item)));
            return S_OK;
        }
        catch (...)
        {
            *returnValue = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename T, typename A = ABI::Windows::UI::Xaml::Controls::IGroupStyleSelectorOverrides>
struct IGroupStyleSelectorOverridesT : A
{
    Windows::UI::Xaml::Controls::GroupStyle SelectGroupStyleCore(const Windows::IInspectable & group, uint32_t level)
    {
        return static_cast<T *>(this)->as<Windows::UI::Xaml::Controls::IGroupStyleSelectorOverrides>().SelectGroupStyleCore(group, level);
    }

    HRESULT __stdcall abi_SelectGroupStyleCore(abi_arg_in<Windows::IInspectable> group, uint32_t level, abi_arg_out<Windows::UI::Xaml::Controls::IGroupStyle> returnValue) noexcept override
    {
        try
        {
            *returnValue = detach(static_cast<T *>(this)->SelectGroupStyleCore(*reinterpret_cast<const Windows::IInspectable *>(&group), level));
            return S_OK;
        }
        catch (...)
        {
            *returnValue = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename T, typename A = ABI::Windows::UI::Xaml::Controls::IItemsControlOverrides>
struct IItemsControlOverridesT : A
{
    bool IsItemItsOwnContainerOverride(const Windows::IInspectable & item)
    {
        return static_cast<T *>(this)->as<Windows::UI::Xaml::Controls::IItemsControlOverrides>().IsItemItsOwnContainerOverride(item);
    }

    Windows::UI::Xaml::DependencyObject GetContainerForItemOverride()
    {
        return static_cast<T *>(this)->as<Windows::UI::Xaml::Controls::IItemsControlOverrides>().GetContainerForItemOverride();
    }

    void ClearContainerForItemOverride(const Windows::UI::Xaml::DependencyObject & element, const Windows::IInspectable & item)
    {
        static_cast<T *>(this)->as<Windows::UI::Xaml::Controls::IItemsControlOverrides>().ClearContainerForItemOverride(element, item);
    }

    void PrepareContainerForItemOverride(const Windows::UI::Xaml::DependencyObject & element, const Windows::IInspectable & item)
    {
        static_cast<T *>(this)->as<Windows::UI::Xaml::Controls::IItemsControlOverrides>().PrepareContainerForItemOverride(element, item);
    }

    void OnItemsChanged(const Windows::IInspectable & e)
    {
        static_cast<T *>(this)->as<Windows::UI::Xaml::Controls::IItemsControlOverrides>().OnItemsChanged(e);
    }

    void OnItemContainerStyleChanged(const Windows::UI::Xaml::Style & oldItemContainerStyle, const Windows::UI::Xaml::Style & newItemContainerStyle)
    {
        static_cast<T *>(this)->as<Windows::UI::Xaml::Controls::IItemsControlOverrides>().OnItemContainerStyleChanged(oldItemContainerStyle, newItemContainerStyle);
    }

    void OnItemContainerStyleSelectorChanged(const Windows::UI::Xaml::Controls::StyleSelector & oldItemContainerStyleSelector, const Windows::UI::Xaml::Controls::StyleSelector & newItemContainerStyleSelector)
    {
        static_cast<T *>(this)->as<Windows::UI::Xaml::Controls::IItemsControlOverrides>().OnItemContainerStyleSelectorChanged(oldItemContainerStyleSelector, newItemContainerStyleSelector);
    }

    void OnItemTemplateChanged(const Windows::UI::Xaml::DataTemplate & oldItemTemplate, const Windows::UI::Xaml::DataTemplate & newItemTemplate)
    {
        static_cast<T *>(this)->as<Windows::UI::Xaml::Controls::IItemsControlOverrides>().OnItemTemplateChanged(oldItemTemplate, newItemTemplate);
    }

    void OnItemTemplateSelectorChanged(const Windows::UI::Xaml::Controls::DataTemplateSelector & oldItemTemplateSelector, const Windows::UI::Xaml::Controls::DataTemplateSelector & newItemTemplateSelector)
    {
        static_cast<T *>(this)->as<Windows::UI::Xaml::Controls::IItemsControlOverrides>().OnItemTemplateSelectorChanged(oldItemTemplateSelector, newItemTemplateSelector);
    }

    void OnGroupStyleSelectorChanged(const Windows::UI::Xaml::Controls::GroupStyleSelector & oldGroupStyleSelector, const Windows::UI::Xaml::Controls::GroupStyleSelector & newGroupStyleSelector)
    {
        static_cast<T *>(this)->as<Windows::UI::Xaml::Controls::IItemsControlOverrides>().OnGroupStyleSelectorChanged(oldGroupStyleSelector, newGroupStyleSelector);
    }

    HRESULT __stdcall abi_IsItemItsOwnContainerOverride(abi_arg_in<Windows::IInspectable> item, bool * returnValue) noexcept override
    {
        try
        {
            *returnValue = detach(static_cast<T *>(this)->IsItemItsOwnContainerOverride(*reinterpret_cast<const Windows::IInspectable *>(&item)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetContainerForItemOverride(abi_arg_out<Windows::UI::Xaml::IDependencyObject> returnValue) noexcept override
    {
        try
        {
            *returnValue = detach(static_cast<T *>(this)->GetContainerForItemOverride());
            return S_OK;
        }
        catch (...)
        {
            *returnValue = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_ClearContainerForItemOverride(abi_arg_in<Windows::UI::Xaml::IDependencyObject> element, abi_arg_in<Windows::IInspectable> item) noexcept override
    {
        try
        {
            static_cast<T *>(this)->ClearContainerForItemOverride(*reinterpret_cast<const Windows::UI::Xaml::DependencyObject *>(&element), *reinterpret_cast<const Windows::IInspectable *>(&item));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_PrepareContainerForItemOverride(abi_arg_in<Windows::UI::Xaml::IDependencyObject> element, abi_arg_in<Windows::IInspectable> item) noexcept override
    {
        try
        {
            static_cast<T *>(this)->PrepareContainerForItemOverride(*reinterpret_cast<const Windows::UI::Xaml::DependencyObject *>(&element), *reinterpret_cast<const Windows::IInspectable *>(&item));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_OnItemsChanged(abi_arg_in<Windows::IInspectable> e) noexcept override
    {
        try
        {
            static_cast<T *>(this)->OnItemsChanged(*reinterpret_cast<const Windows::IInspectable *>(&e));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_OnItemContainerStyleChanged(abi_arg_in<Windows::UI::Xaml::IStyle> oldItemContainerStyle, abi_arg_in<Windows::UI::Xaml::IStyle> newItemContainerStyle) noexcept override
    {
        try
        {
            static_cast<T *>(this)->OnItemContainerStyleChanged(*reinterpret_cast<const Windows::UI::Xaml::Style *>(&oldItemContainerStyle), *reinterpret_cast<const Windows::UI::Xaml::Style *>(&newItemContainerStyle));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_OnItemContainerStyleSelectorChanged(abi_arg_in<Windows::UI::Xaml::Controls::IStyleSelector> oldItemContainerStyleSelector, abi_arg_in<Windows::UI::Xaml::Controls::IStyleSelector> newItemContainerStyleSelector) noexcept override
    {
        try
        {
            static_cast<T *>(this)->OnItemContainerStyleSelectorChanged(*reinterpret_cast<const Windows::UI::Xaml::Controls::StyleSelector *>(&oldItemContainerStyleSelector), *reinterpret_cast<const Windows::UI::Xaml::Controls::StyleSelector *>(&newItemContainerStyleSelector));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_OnItemTemplateChanged(abi_arg_in<Windows::UI::Xaml::IDataTemplate> oldItemTemplate, abi_arg_in<Windows::UI::Xaml::IDataTemplate> newItemTemplate) noexcept override
    {
        try
        {
            static_cast<T *>(this)->OnItemTemplateChanged(*reinterpret_cast<const Windows::UI::Xaml::DataTemplate *>(&oldItemTemplate), *reinterpret_cast<const Windows::UI::Xaml::DataTemplate *>(&newItemTemplate));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_OnItemTemplateSelectorChanged(abi_arg_in<Windows::UI::Xaml::Controls::IDataTemplateSelector> oldItemTemplateSelector, abi_arg_in<Windows::UI::Xaml::Controls::IDataTemplateSelector> newItemTemplateSelector) noexcept override
    {
        try
        {
            static_cast<T *>(this)->OnItemTemplateSelectorChanged(*reinterpret_cast<const Windows::UI::Xaml::Controls::DataTemplateSelector *>(&oldItemTemplateSelector), *reinterpret_cast<const Windows::UI::Xaml::Controls::DataTemplateSelector *>(&newItemTemplateSelector));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_OnGroupStyleSelectorChanged(abi_arg_in<Windows::UI::Xaml::Controls::IGroupStyleSelector> oldGroupStyleSelector, abi_arg_in<Windows::UI::Xaml::Controls::IGroupStyleSelector> newGroupStyleSelector) noexcept override
    {
        try
        {
            static_cast<T *>(this)->OnGroupStyleSelectorChanged(*reinterpret_cast<const Windows::UI::Xaml::Controls::GroupStyleSelector *>(&oldGroupStyleSelector), *reinterpret_cast<const Windows::UI::Xaml::Controls::GroupStyleSelector *>(&newGroupStyleSelector));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename T, typename A = ABI::Windows::UI::Xaml::Controls::IPageOverrides>
struct IPageOverridesT : A
{
    void OnNavigatedFrom(const Windows::UI::Xaml::Navigation::NavigationEventArgs & e)
    {
        static_cast<T *>(this)->as<Windows::UI::Xaml::Controls::IPageOverrides>().OnNavigatedFrom(e);
    }

    void OnNavigatedTo(const Windows::UI::Xaml::Navigation::NavigationEventArgs & e)
    {
        static_cast<T *>(this)->as<Windows::UI::Xaml::Controls::IPageOverrides>().OnNavigatedTo(e);
    }

    void OnNavigatingFrom(const Windows::UI::Xaml::Navigation::NavigatingCancelEventArgs & e)
    {
        static_cast<T *>(this)->as<Windows::UI::Xaml::Controls::IPageOverrides>().OnNavigatingFrom(e);
    }

    HRESULT __stdcall abi_OnNavigatedFrom(abi_arg_in<Windows::UI::Xaml::Navigation::INavigationEventArgs> e) noexcept override
    {
        try
        {
            static_cast<T *>(this)->OnNavigatedFrom(*reinterpret_cast<const Windows::UI::Xaml::Navigation::NavigationEventArgs *>(&e));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_OnNavigatedTo(abi_arg_in<Windows::UI::Xaml::Navigation::INavigationEventArgs> e) noexcept override
    {
        try
        {
            static_cast<T *>(this)->OnNavigatedTo(*reinterpret_cast<const Windows::UI::Xaml::Navigation::NavigationEventArgs *>(&e));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_OnNavigatingFrom(abi_arg_in<Windows::UI::Xaml::Navigation::INavigatingCancelEventArgs> e) noexcept override
    {
        try
        {
            static_cast<T *>(this)->OnNavigatingFrom(*reinterpret_cast<const Windows::UI::Xaml::Navigation::NavigatingCancelEventArgs *>(&e));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename T, typename A = ABI::Windows::UI::Xaml::Controls::IStyleSelectorOverrides>
struct IStyleSelectorOverridesT : A
{
    Windows::UI::Xaml::Style SelectStyleCore(const Windows::IInspectable & item, const Windows::UI::Xaml::DependencyObject & container)
    {
        return static_cast<T *>(this)->as<Windows::UI::Xaml::Controls::IStyleSelectorOverrides>().SelectStyleCore(item, container);
    }

    HRESULT __stdcall abi_SelectStyleCore(abi_arg_in<Windows::IInspectable> item, abi_arg_in<Windows::UI::Xaml::IDependencyObject> container, abi_arg_out<Windows::UI::Xaml::IStyle> returnValue) noexcept override
    {
        try
        {
            *returnValue = detach(static_cast<T *>(this)->SelectStyleCore(*reinterpret_cast<const Windows::IInspectable *>(&item), *reinterpret_cast<const Windows::UI::Xaml::DependencyObject *>(&container)));
            return S_OK;
        }
        catch (...)
        {
            *returnValue = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename T, typename A = ABI::Windows::UI::Xaml::Controls::IToggleSwitchOverrides>
struct IToggleSwitchOverridesT : A
{
    void OnToggled()
    {
        static_cast<T *>(this)->as<Windows::UI::Xaml::Controls::IToggleSwitchOverrides>().OnToggled();
    }

    void OnOnContentChanged(const Windows::IInspectable & oldContent, const Windows::IInspectable & newContent)
    {
        static_cast<T *>(this)->as<Windows::UI::Xaml::Controls::IToggleSwitchOverrides>().OnOnContentChanged(oldContent, newContent);
    }

    void OnOffContentChanged(const Windows::IInspectable & oldContent, const Windows::IInspectable & newContent)
    {
        static_cast<T *>(this)->as<Windows::UI::Xaml::Controls::IToggleSwitchOverrides>().OnOffContentChanged(oldContent, newContent);
    }

    void OnHeaderChanged(const Windows::IInspectable & oldContent, const Windows::IInspectable & newContent)
    {
        static_cast<T *>(this)->as<Windows::UI::Xaml::Controls::IToggleSwitchOverrides>().OnHeaderChanged(oldContent, newContent);
    }

    HRESULT __stdcall abi_OnToggled() noexcept override
    {
        try
        {
            static_cast<T *>(this)->OnToggled();
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_OnOnContentChanged(abi_arg_in<Windows::IInspectable> oldContent, abi_arg_in<Windows::IInspectable> newContent) noexcept override
    {
        try
        {
            static_cast<T *>(this)->OnOnContentChanged(*reinterpret_cast<const Windows::IInspectable *>(&oldContent), *reinterpret_cast<const Windows::IInspectable *>(&newContent));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_OnOffContentChanged(abi_arg_in<Windows::IInspectable> oldContent, abi_arg_in<Windows::IInspectable> newContent) noexcept override
    {
        try
        {
            static_cast<T *>(this)->OnOffContentChanged(*reinterpret_cast<const Windows::IInspectable *>(&oldContent), *reinterpret_cast<const Windows::IInspectable *>(&newContent));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_OnHeaderChanged(abi_arg_in<Windows::IInspectable> oldContent, abi_arg_in<Windows::IInspectable> newContent) noexcept override
    {
        try
        {
            static_cast<T *>(this)->OnHeaderChanged(*reinterpret_cast<const Windows::IInspectable *>(&oldContent), *reinterpret_cast<const Windows::IInspectable *>(&newContent));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename T, typename A = ABI::Windows::UI::Xaml::Controls::IVirtualizingPanelOverrides>
struct IVirtualizingPanelOverridesT : A
{
    void OnItemsChanged(const Windows::IInspectable & sender, const Windows::UI::Xaml::Controls::Primitives::ItemsChangedEventArgs & args)
    {
        static_cast<T *>(this)->as<Windows::UI::Xaml::Controls::IVirtualizingPanelOverrides>().OnItemsChanged(sender, args);
    }

    void OnClearChildren()
    {
        static_cast<T *>(this)->as<Windows::UI::Xaml::Controls::IVirtualizingPanelOverrides>().OnClearChildren();
    }

    void BringIndexIntoView(int32_t index)
    {
        static_cast<T *>(this)->as<Windows::UI::Xaml::Controls::IVirtualizingPanelOverrides>().BringIndexIntoView(index);
    }

    HRESULT __stdcall abi_OnItemsChanged(abi_arg_in<Windows::IInspectable> sender, abi_arg_in<Windows::UI::Xaml::Controls::Primitives::IItemsChangedEventArgs> args) noexcept override
    {
        try
        {
            static_cast<T *>(this)->OnItemsChanged(*reinterpret_cast<const Windows::IInspectable *>(&sender), *reinterpret_cast<const Windows::UI::Xaml::Controls::Primitives::ItemsChangedEventArgs *>(&args));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_OnClearChildren() noexcept override
    {
        try
        {
            static_cast<T *>(this)->OnClearChildren();
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_BringIndexIntoView(int32_t index) noexcept override
    {
        try
        {
            static_cast<T *>(this)->BringIndexIntoView(index);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename T, typename A = ABI::Windows::UI::Xaml::Controls::IVirtualizingStackPanelOverrides>
struct IVirtualizingStackPanelOverridesT : A
{
    void OnCleanUpVirtualizedItem(const Windows::UI::Xaml::Controls::CleanUpVirtualizedItemEventArgs & e)
    {
        static_cast<T *>(this)->as<Windows::UI::Xaml::Controls::IVirtualizingStackPanelOverrides>().OnCleanUpVirtualizedItem(e);
    }

    HRESULT __stdcall abi_OnCleanUpVirtualizedItem(abi_arg_in<Windows::UI::Xaml::Controls::ICleanUpVirtualizedItemEventArgs> e) noexcept override
    {
        try
        {
            static_cast<T *>(this)->OnCleanUpVirtualizedItem(*reinterpret_cast<const Windows::UI::Xaml::Controls::CleanUpVirtualizedItemEventArgs *>(&e));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

}}}}

namespace Windows { namespace UI { namespace Xaml { namespace Controls { namespace Primitives {

template <typename T, typename A = ABI::Windows::UI::Xaml::Controls::Primitives::IFlyoutBaseOverrides>
struct IFlyoutBaseOverridesT : A
{
    Windows::UI::Xaml::Controls::Control CreatePresenter()
    {
        return static_cast<T *>(this)->as<Windows::UI::Xaml::Controls::Primitives::IFlyoutBaseOverrides>().CreatePresenter();
    }

    HRESULT __stdcall abi_CreatePresenter(abi_arg_out<Windows::UI::Xaml::Controls::IControl> returnValue) noexcept override
    {
        try
        {
            *returnValue = detach(static_cast<T *>(this)->CreatePresenter());
            return S_OK;
        }
        catch (...)
        {
            *returnValue = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename T, typename A = ABI::Windows::UI::Xaml::Controls::Primitives::IPickerFlyoutBaseOverrides>
struct IPickerFlyoutBaseOverridesT : A
{
    void OnConfirmed()
    {
        static_cast<T *>(this)->as<Windows::UI::Xaml::Controls::Primitives::IPickerFlyoutBaseOverrides>().OnConfirmed();
    }

    bool ShouldShowConfirmationButtons()
    {
        return static_cast<T *>(this)->as<Windows::UI::Xaml::Controls::Primitives::IPickerFlyoutBaseOverrides>().ShouldShowConfirmationButtons();
    }

    HRESULT __stdcall abi_OnConfirmed() noexcept override
    {
        try
        {
            static_cast<T *>(this)->OnConfirmed();
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_ShouldShowConfirmationButtons(bool * returnValue) noexcept override
    {
        try
        {
            *returnValue = detach(static_cast<T *>(this)->ShouldShowConfirmationButtons());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename T, typename A = ABI::Windows::UI::Xaml::Controls::Primitives::IRangeBaseOverrides>
struct IRangeBaseOverridesT : A
{
    void OnMinimumChanged(double oldMinimum, double newMinimum)
    {
        static_cast<T *>(this)->as<Windows::UI::Xaml::Controls::Primitives::IRangeBaseOverrides>().OnMinimumChanged(oldMinimum, newMinimum);
    }

    void OnMaximumChanged(double oldMaximum, double newMaximum)
    {
        static_cast<T *>(this)->as<Windows::UI::Xaml::Controls::Primitives::IRangeBaseOverrides>().OnMaximumChanged(oldMaximum, newMaximum);
    }

    void OnValueChanged(double oldValue, double newValue)
    {
        static_cast<T *>(this)->as<Windows::UI::Xaml::Controls::Primitives::IRangeBaseOverrides>().OnValueChanged(oldValue, newValue);
    }

    HRESULT __stdcall abi_OnMinimumChanged(double oldMinimum, double newMinimum) noexcept override
    {
        try
        {
            static_cast<T *>(this)->OnMinimumChanged(oldMinimum, newMinimum);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_OnMaximumChanged(double oldMaximum, double newMaximum) noexcept override
    {
        try
        {
            static_cast<T *>(this)->OnMaximumChanged(oldMaximum, newMaximum);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_OnValueChanged(double oldValue, double newValue) noexcept override
    {
        try
        {
            static_cast<T *>(this)->OnValueChanged(oldValue, newValue);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename T, typename A = ABI::Windows::UI::Xaml::Controls::Primitives::IToggleButtonOverrides>
struct IToggleButtonOverridesT : A
{
    void OnToggle()
    {
        static_cast<T *>(this)->as<Windows::UI::Xaml::Controls::Primitives::IToggleButtonOverrides>().OnToggle();
    }

    HRESULT __stdcall abi_OnToggle() noexcept override
    {
        try
        {
            static_cast<T *>(this)->OnToggle();
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

}}}}}

namespace Windows { namespace UI { namespace Xaml { namespace Documents {

template <typename T, typename A = ABI::Windows::UI::Xaml::Documents::ITextElementOverrides>
struct ITextElementOverridesT : A
{
    void OnDisconnectVisualChildren()
    {
        static_cast<T *>(this)->as<Windows::UI::Xaml::Documents::ITextElementOverrides>().OnDisconnectVisualChildren();
    }

    HRESULT __stdcall abi_OnDisconnectVisualChildren() noexcept override
    {
        try
        {
            static_cast<T *>(this)->OnDisconnectVisualChildren();
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

}}}}

namespace Windows { namespace UI { namespace Xaml { namespace Media {

template <typename T, typename A = ABI::Windows::UI::Xaml::Media::IGeneralTransformOverrides>
struct IGeneralTransformOverridesT : A
{
    Windows::UI::Xaml::Media::GeneralTransform InverseCore()
    {
        return static_cast<T *>(this)->as<Windows::UI::Xaml::Media::IGeneralTransformOverrides>().InverseCore();
    }

    bool TryTransformCore(const Windows::Foundation::Point & inPoint, Windows::Foundation::Point & outPoint)
    {
        return static_cast<T *>(this)->as<Windows::UI::Xaml::Media::IGeneralTransformOverrides>().TryTransformCore(inPoint, outPoint);
    }

    Windows::Foundation::Rect TransformBoundsCore(const Windows::Foundation::Rect & rect)
    {
        return static_cast<T *>(this)->as<Windows::UI::Xaml::Media::IGeneralTransformOverrides>().TransformBoundsCore(rect);
    }

    HRESULT __stdcall get_InverseCore(abi_arg_out<Windows::UI::Xaml::Media::IGeneralTransform> value) noexcept override
    {
        try
        {
            *value = detach(static_cast<T *>(this)->InverseCore());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_TryTransformCore(Windows::Foundation::Point inPoint, Windows::Foundation::Point * outPoint, bool * returnValue) noexcept override
    {
        try
        {
            *returnValue = detach(static_cast<T *>(this)->TryTransformCore(inPoint, *outPoint));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_TransformBoundsCore(Windows::Foundation::Rect rect, Windows::Foundation::Rect * returnValue) noexcept override
    {
        try
        {
            *returnValue = detach(static_cast<T *>(this)->TransformBoundsCore(rect));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

}}}}

namespace Windows { namespace UI { namespace Xaml { namespace Media { namespace Animation {

template <typename T, typename A = ABI::Windows::UI::Xaml::Media::Animation::INavigationTransitionInfoOverrides>
struct INavigationTransitionInfoOverridesT : A
{
    hstring GetNavigationStateCore()
    {
        return static_cast<T *>(this)->as<Windows::UI::Xaml::Media::Animation::INavigationTransitionInfoOverrides>().GetNavigationStateCore();
    }

    void SetNavigationStateCore(hstring_ref navigationState)
    {
        static_cast<T *>(this)->as<Windows::UI::Xaml::Media::Animation::INavigationTransitionInfoOverrides>().SetNavigationStateCore(navigationState);
    }

    HRESULT __stdcall abi_GetNavigationStateCore(HSTRING * returnValue) noexcept override
    {
        try
        {
            *returnValue = detach(static_cast<T *>(this)->GetNavigationStateCore());
            return S_OK;
        }
        catch (...)
        {
            *returnValue = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_SetNavigationStateCore(HSTRING navigationState) noexcept override
    {
        try
        {
            static_cast<T *>(this)->SetNavigationStateCore(*reinterpret_cast<const hstring *>(&navigationState));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

}}}}}

namespace Windows { namespace UI { namespace Xaml { namespace Media { namespace Imaging {

template <typename T, typename A = ABI::Windows::UI::Xaml::Media::Imaging::IXamlRenderingBackgroundTaskOverrides>
struct IXamlRenderingBackgroundTaskOverridesT : A
{
    void OnRun(const Windows::ApplicationModel::Background::IBackgroundTaskInstance & taskInstance)
    {
        static_cast<T *>(this)->as<Windows::UI::Xaml::Media::Imaging::IXamlRenderingBackgroundTaskOverrides>().OnRun(taskInstance);
    }

    HRESULT __stdcall abi_OnRun(abi_arg_in<Windows::ApplicationModel::Background::IBackgroundTaskInstance> taskInstance) noexcept override
    {
        try
        {
            static_cast<T *>(this)->OnRun(*reinterpret_cast<const Windows::ApplicationModel::Background::IBackgroundTaskInstance *>(&taskInstance));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

}}}}}

namespace Windows { namespace UI { namespace Xaml { namespace Resources {

template <typename T, typename A = ABI::Windows::UI::Xaml::Resources::ICustomXamlResourceLoaderOverrides>
struct ICustomXamlResourceLoaderOverridesT : A
{
    Windows::IInspectable GetResource(hstring_ref resourceId, hstring_ref objectType, hstring_ref propertyName, hstring_ref propertyType)
    {
        return static_cast<T *>(this)->as<Windows::UI::Xaml::Resources::ICustomXamlResourceLoaderOverrides>().GetResource(resourceId, objectType, propertyName, propertyType);
    }

    HRESULT __stdcall abi_GetResource(HSTRING resourceId, HSTRING objectType, HSTRING propertyName, HSTRING propertyType, abi_arg_out<Windows::IInspectable> returnValue) noexcept override
    {
        try
        {
            *returnValue = detach(static_cast<T *>(this)->GetResource(*reinterpret_cast<const hstring *>(&resourceId), *reinterpret_cast<const hstring *>(&objectType), *reinterpret_cast<const hstring *>(&propertyName), *reinterpret_cast<const hstring *>(&propertyType)));
            return S_OK;
        }
        catch (...)
        {
            *returnValue = nullptr;
            return impl::to_hresult();
        }
    }
};

}}}}

namespace Windows { namespace UI { namespace Xaml {

template <typename T, typename ... Interfaces> struct AdaptiveTriggerT :
    overrides<T, Windows::IInspectable, Interfaces ...>,
    requires<T, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IStateTriggerBase, Windows::UI::Xaml::IStateTriggerBaseProtected, Windows::UI::Xaml::IAdaptiveTrigger>
{
    using composable = AdaptiveTrigger;

protected:

    AdaptiveTriggerT()
    {
        GetActivationFactory<AdaptiveTrigger, IAdaptiveTriggerFactory>().CreateInstance(*this, m_inner);
    }
};

template <typename T, typename ... Interfaces> struct ApplicationT :
    overrides<T, Windows::UI::Xaml::IApplicationOverridesT<T>, Interfaces ...>,
    requires<T, Windows::UI::Xaml::IApplication>
{
    using composable = Application;

protected:

    ApplicationT()
    {
        GetActivationFactory<Application, IApplicationFactory>().CreateInstance(*this, m_inner);
    }
};

template <typename T, typename ... Interfaces> struct DataTemplateT :
    overrides<T, Windows::IInspectable, Interfaces ...>,
    requires<T, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IFrameworkTemplate, Windows::UI::Xaml::IDataTemplate>
{
    using composable = DataTemplate;

protected:

    DataTemplateT()
    {
        GetActivationFactory<DataTemplate, IDataTemplateFactory>().CreateInstance(*this, m_inner);
    }
};

template <typename T, typename ... Interfaces> struct DataTemplateKeyT :
    overrides<T, Windows::IInspectable, Interfaces ...>,
    requires<T, Windows::UI::Xaml::IDataTemplateKey>
{
    using composable = DataTemplateKey;

protected:

    DataTemplateKeyT()
    {
        GetActivationFactory<DataTemplateKey, IDataTemplateKeyFactory>().CreateInstance(*this, m_inner);
    }

    DataTemplateKeyT(const Windows::IInspectable & dataType)
    {
        GetActivationFactory<DataTemplateKey, IDataTemplateKeyFactory>().CreateInstanceWithType(dataType, *this, m_inner);
    }
};

template <typename T, typename ... Interfaces> struct DependencyObjectT :
    overrides<T, Windows::IInspectable, Interfaces ...>,
    requires<T, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2>
{
    using composable = DependencyObject;

protected:

    DependencyObjectT()
    {
        GetActivationFactory<DependencyObject, IDependencyObjectFactory>().CreateInstance(*this, m_inner);
    }
};

template <typename T, typename ... Interfaces> struct DependencyObjectCollectionT :
    overrides<T, Windows::IInspectable, Interfaces ...>,
    requires<T, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::Foundation::Collections::IObservableVector<Windows::UI::Xaml::DependencyObject>>
{
    using composable = DependencyObjectCollection;

protected:

    DependencyObjectCollectionT()
    {
        GetActivationFactory<DependencyObjectCollection, IDependencyObjectCollectionFactory>().CreateInstance(*this, m_inner);
    }
};

template <typename T, typename ... Interfaces> struct DispatcherTimerT :
    overrides<T, Windows::IInspectable, Interfaces ...>,
    requires<T, Windows::UI::Xaml::IDispatcherTimer>
{
    using composable = DispatcherTimer;

protected:

    DispatcherTimerT()
    {
        GetActivationFactory<DispatcherTimer, IDispatcherTimerFactory>().CreateInstance(*this, m_inner);
    }
};

template <typename T, typename ... Interfaces> struct FrameworkElementT :
    overrides<T, Windows::UI::Xaml::IUIElementOverridesT<T>, Windows::UI::Xaml::IFrameworkElementOverridesT<T>, Windows::UI::Xaml::IFrameworkElementOverrides2T<T>, Interfaces ...>,
    requires<T, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElement3>
{
    using composable = FrameworkElement;

protected:

    FrameworkElementT()
    {
        GetActivationFactory<FrameworkElement, IFrameworkElementFactory>().CreateInstance(*this, m_inner);
    }
};

template <typename T, typename ... Interfaces> struct FrameworkTemplateT :
    overrides<T, Windows::IInspectable, Interfaces ...>,
    requires<T, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IFrameworkTemplate>
{
    using composable = FrameworkTemplate;

protected:

    FrameworkTemplateT()
    {
        GetActivationFactory<FrameworkTemplate, IFrameworkTemplateFactory>().CreateInstance(*this, m_inner);
    }
};

template <typename T, typename ... Interfaces> struct PropertyMetadataT :
    overrides<T, Windows::IInspectable, Interfaces ...>,
    requires<T, Windows::UI::Xaml::IPropertyMetadata>
{
    using composable = PropertyMetadata;

protected:

    PropertyMetadataT(const Windows::IInspectable & defaultValue)
    {
        GetActivationFactory<PropertyMetadata, IPropertyMetadataFactory>().CreateInstanceWithDefaultValue(defaultValue, *this, m_inner);
    }

    PropertyMetadataT(const Windows::IInspectable & defaultValue, const Windows::UI::Xaml::PropertyChangedCallback & propertyChangedCallback)
    {
        GetActivationFactory<PropertyMetadata, IPropertyMetadataFactory>().CreateInstanceWithDefaultValueAndCallback(defaultValue, propertyChangedCallback, *this, m_inner);
    }
};

template <typename T, typename ... Interfaces> struct ResourceDictionaryT :
    overrides<T, Windows::IInspectable, Interfaces ...>,
    requires<T, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IResourceDictionary, Windows::Foundation::Collections::IMap<Windows::IInspectable, Windows::IInspectable>, Windows::Foundation::Collections::IIterable<Windows::Foundation::Collections::IKeyValuePair<Windows::IInspectable, Windows::IInspectable>>>
{
    using composable = ResourceDictionary;

protected:

    ResourceDictionaryT()
    {
        GetActivationFactory<ResourceDictionary, IResourceDictionaryFactory>().CreateInstance(*this, m_inner);
    }
};

template <typename T, typename ... Interfaces> struct RoutedEventArgsT :
    overrides<T, Windows::IInspectable, Interfaces ...>,
    requires<T, Windows::UI::Xaml::IRoutedEventArgs>
{
    using composable = RoutedEventArgs;

protected:

    RoutedEventArgsT()
    {
        GetActivationFactory<RoutedEventArgs, IRoutedEventArgsFactory>().CreateInstance(*this, m_inner);
    }
};

template <typename T, typename ... Interfaces> struct StateTriggerBaseT :
    overrides<T, Windows::IInspectable, Interfaces ...>,
    requires<T, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IStateTriggerBase, Windows::UI::Xaml::IStateTriggerBaseProtected>
{
    using composable = StateTriggerBase;

protected:

    StateTriggerBaseT()
    {
        GetActivationFactory<StateTriggerBase, IStateTriggerBaseFactory>().CreateInstance(*this, m_inner);
    }
};

template <typename T, typename ... Interfaces> struct VisualStateManagerT :
    overrides<T, Windows::UI::Xaml::IVisualStateManagerOverridesT<T>, Interfaces ...>,
    requires<T, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IVisualStateManager, Windows::UI::Xaml::IVisualStateManagerProtected>
{
    using composable = VisualStateManager;

protected:

    VisualStateManagerT()
    {
        GetActivationFactory<VisualStateManager, IVisualStateManagerFactory>().CreateInstance(*this, m_inner);
    }
};

template <typename T, typename ... Interfaces> struct VisualTransitionT :
    overrides<T, Windows::IInspectable, Interfaces ...>,
    requires<T, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IVisualTransition>
{
    using composable = VisualTransition;

protected:

    VisualTransitionT()
    {
        GetActivationFactory<VisualTransition, IVisualTransitionFactory>().CreateInstance(*this, m_inner);
    }
};

}}}

namespace Windows { namespace UI { namespace Xaml { namespace Automation { namespace Peers {

template <typename T, typename ... Interfaces> struct AppBarAutomationPeerT :
    overrides<T, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverridesT<T>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2T<T>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3T<T>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides4T<T>, Interfaces ...>,
    requires<T, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer, Windows::UI::Xaml::Automation::Peers::IAutomationPeerProtected, Windows::UI::Xaml::Automation::Peers::IAutomationPeer2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer3, Windows::UI::Xaml::Automation::Peers::IAutomationPeer4, Windows::UI::Xaml::Automation::Peers::IFrameworkElementAutomationPeer, Windows::UI::Xaml::Automation::Peers::IAppBarAutomationPeer, Windows::UI::Xaml::Automation::Provider::IToggleProvider, Windows::UI::Xaml::Automation::Provider::IExpandCollapseProvider>
{
    using composable = AppBarAutomationPeer;

protected:

    AppBarAutomationPeerT(const Windows::UI::Xaml::Controls::AppBar & owner)
    {
        GetActivationFactory<AppBarAutomationPeer, IAppBarAutomationPeerFactory>().CreateInstanceWithOwner(owner, *this, m_inner);
    }
};

template <typename T, typename ... Interfaces> struct AppBarButtonAutomationPeerT :
    overrides<T, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverridesT<T>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2T<T>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3T<T>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides4T<T>, Interfaces ...>,
    requires<T, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer, Windows::UI::Xaml::Automation::Peers::IAutomationPeerProtected, Windows::UI::Xaml::Automation::Peers::IAutomationPeer2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer3, Windows::UI::Xaml::Automation::Peers::IAutomationPeer4, Windows::UI::Xaml::Automation::Peers::IFrameworkElementAutomationPeer, Windows::UI::Xaml::Automation::Peers::IButtonBaseAutomationPeer, Windows::UI::Xaml::Automation::Peers::IButtonAutomationPeer, Windows::UI::Xaml::Automation::Provider::IInvokeProvider, Windows::UI::Xaml::Automation::Peers::IAppBarButtonAutomationPeer>
{
    using composable = AppBarButtonAutomationPeer;

protected:

    AppBarButtonAutomationPeerT(const Windows::UI::Xaml::Controls::AppBarButton & owner)
    {
        GetActivationFactory<AppBarButtonAutomationPeer, IAppBarButtonAutomationPeerFactory>().CreateInstanceWithOwner(owner, *this, m_inner);
    }
};

template <typename T, typename ... Interfaces> struct AppBarToggleButtonAutomationPeerT :
    overrides<T, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverridesT<T>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2T<T>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3T<T>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides4T<T>, Interfaces ...>,
    requires<T, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer, Windows::UI::Xaml::Automation::Peers::IAutomationPeerProtected, Windows::UI::Xaml::Automation::Peers::IAutomationPeer2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer3, Windows::UI::Xaml::Automation::Peers::IAutomationPeer4, Windows::UI::Xaml::Automation::Peers::IFrameworkElementAutomationPeer, Windows::UI::Xaml::Automation::Peers::IButtonBaseAutomationPeer, Windows::UI::Xaml::Automation::Peers::IToggleButtonAutomationPeer, Windows::UI::Xaml::Automation::Provider::IToggleProvider, Windows::UI::Xaml::Automation::Peers::IAppBarToggleButtonAutomationPeer>
{
    using composable = AppBarToggleButtonAutomationPeer;

protected:

    AppBarToggleButtonAutomationPeerT(const Windows::UI::Xaml::Controls::AppBarToggleButton & owner)
    {
        GetActivationFactory<AppBarToggleButtonAutomationPeer, IAppBarToggleButtonAutomationPeerFactory>().CreateInstanceWithOwner(owner, *this, m_inner);
    }
};

template <typename T, typename ... Interfaces> struct AutomationPeerT :
    overrides<T, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverridesT<T>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2T<T>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3T<T>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides4T<T>, Interfaces ...>,
    requires<T, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer, Windows::UI::Xaml::Automation::Peers::IAutomationPeerProtected, Windows::UI::Xaml::Automation::Peers::IAutomationPeer2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer3, Windows::UI::Xaml::Automation::Peers::IAutomationPeer4>
{
    using composable = AutomationPeer;

protected:

    AutomationPeerT()
    {
        GetActivationFactory<AutomationPeer, IAutomationPeerFactory>().CreateInstance(*this, m_inner);
    }
};

template <typename T, typename ... Interfaces> struct ButtonAutomationPeerT :
    overrides<T, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverridesT<T>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2T<T>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3T<T>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides4T<T>, Interfaces ...>,
    requires<T, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer, Windows::UI::Xaml::Automation::Peers::IAutomationPeerProtected, Windows::UI::Xaml::Automation::Peers::IAutomationPeer2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer3, Windows::UI::Xaml::Automation::Peers::IAutomationPeer4, Windows::UI::Xaml::Automation::Peers::IFrameworkElementAutomationPeer, Windows::UI::Xaml::Automation::Peers::IButtonBaseAutomationPeer, Windows::UI::Xaml::Automation::Peers::IButtonAutomationPeer, Windows::UI::Xaml::Automation::Provider::IInvokeProvider>
{
    using composable = ButtonAutomationPeer;

protected:

    ButtonAutomationPeerT(const Windows::UI::Xaml::Controls::Button & owner)
    {
        GetActivationFactory<ButtonAutomationPeer, IButtonAutomationPeerFactory>().CreateInstanceWithOwner(owner, *this, m_inner);
    }
};

template <typename T, typename ... Interfaces> struct ButtonBaseAutomationPeerT :
    overrides<T, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverridesT<T>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2T<T>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3T<T>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides4T<T>, Interfaces ...>,
    requires<T, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer, Windows::UI::Xaml::Automation::Peers::IAutomationPeerProtected, Windows::UI::Xaml::Automation::Peers::IAutomationPeer2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer3, Windows::UI::Xaml::Automation::Peers::IAutomationPeer4, Windows::UI::Xaml::Automation::Peers::IFrameworkElementAutomationPeer, Windows::UI::Xaml::Automation::Peers::IButtonBaseAutomationPeer>
{
    using composable = ButtonBaseAutomationPeer;

protected:

    ButtonBaseAutomationPeerT(const Windows::UI::Xaml::Controls::Primitives::ButtonBase & owner)
    {
        GetActivationFactory<ButtonBaseAutomationPeer, IButtonBaseAutomationPeerFactory>().CreateInstanceWithOwner(owner, *this, m_inner);
    }
};

template <typename T, typename ... Interfaces> struct CaptureElementAutomationPeerT :
    overrides<T, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverridesT<T>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2T<T>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3T<T>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides4T<T>, Interfaces ...>,
    requires<T, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer, Windows::UI::Xaml::Automation::Peers::IAutomationPeerProtected, Windows::UI::Xaml::Automation::Peers::IAutomationPeer2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer3, Windows::UI::Xaml::Automation::Peers::IAutomationPeer4, Windows::UI::Xaml::Automation::Peers::IFrameworkElementAutomationPeer, Windows::UI::Xaml::Automation::Peers::ICaptureElementAutomationPeer>
{
    using composable = CaptureElementAutomationPeer;

protected:

    CaptureElementAutomationPeerT(const Windows::UI::Xaml::Controls::CaptureElement & owner)
    {
        GetActivationFactory<CaptureElementAutomationPeer, ICaptureElementAutomationPeerFactory>().CreateInstanceWithOwner(owner, *this, m_inner);
    }
};

template <typename T, typename ... Interfaces> struct CheckBoxAutomationPeerT :
    overrides<T, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverridesT<T>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2T<T>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3T<T>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides4T<T>, Interfaces ...>,
    requires<T, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer, Windows::UI::Xaml::Automation::Peers::IAutomationPeerProtected, Windows::UI::Xaml::Automation::Peers::IAutomationPeer2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer3, Windows::UI::Xaml::Automation::Peers::IAutomationPeer4, Windows::UI::Xaml::Automation::Peers::IFrameworkElementAutomationPeer, Windows::UI::Xaml::Automation::Peers::IButtonBaseAutomationPeer, Windows::UI::Xaml::Automation::Peers::IToggleButtonAutomationPeer, Windows::UI::Xaml::Automation::Provider::IToggleProvider, Windows::UI::Xaml::Automation::Peers::ICheckBoxAutomationPeer>
{
    using composable = CheckBoxAutomationPeer;

protected:

    CheckBoxAutomationPeerT(const Windows::UI::Xaml::Controls::CheckBox & owner)
    {
        GetActivationFactory<CheckBoxAutomationPeer, ICheckBoxAutomationPeerFactory>().CreateInstanceWithOwner(owner, *this, m_inner);
    }
};

template <typename T, typename ... Interfaces> struct ComboBoxAutomationPeerT :
    overrides<T, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverridesT<T>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2T<T>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3T<T>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides4T<T>, Windows::UI::Xaml::Automation::Peers::IItemsControlAutomationPeerOverrides2T<T>, Interfaces ...>,
    requires<T, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer, Windows::UI::Xaml::Automation::Peers::IAutomationPeerProtected, Windows::UI::Xaml::Automation::Peers::IAutomationPeer2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer3, Windows::UI::Xaml::Automation::Peers::IAutomationPeer4, Windows::UI::Xaml::Automation::Peers::IFrameworkElementAutomationPeer, Windows::UI::Xaml::Automation::Peers::IItemsControlAutomationPeer, Windows::UI::Xaml::Automation::Provider::IItemContainerProvider, Windows::UI::Xaml::Automation::Peers::IItemsControlAutomationPeer2, Windows::UI::Xaml::Automation::Peers::ISelectorAutomationPeer, Windows::UI::Xaml::Automation::Provider::ISelectionProvider, Windows::UI::Xaml::Automation::Peers::IComboBoxAutomationPeer, Windows::UI::Xaml::Automation::Provider::IExpandCollapseProvider, Windows::UI::Xaml::Automation::Provider::IValueProvider>
{
    using composable = ComboBoxAutomationPeer;

protected:

    ComboBoxAutomationPeerT(const Windows::UI::Xaml::Controls::ComboBox & owner)
    {
        GetActivationFactory<ComboBoxAutomationPeer, IComboBoxAutomationPeerFactory>().CreateInstanceWithOwner(owner, *this, m_inner);
    }
};

template <typename T, typename ... Interfaces> struct ComboBoxItemAutomationPeerT :
    overrides<T, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverridesT<T>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2T<T>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3T<T>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides4T<T>, Interfaces ...>,
    requires<T, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer, Windows::UI::Xaml::Automation::Peers::IAutomationPeerProtected, Windows::UI::Xaml::Automation::Peers::IAutomationPeer2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer3, Windows::UI::Xaml::Automation::Peers::IAutomationPeer4, Windows::UI::Xaml::Automation::Peers::IFrameworkElementAutomationPeer, Windows::UI::Xaml::Automation::Peers::IComboBoxItemAutomationPeer>
{
    using composable = ComboBoxItemAutomationPeer;

protected:

    ComboBoxItemAutomationPeerT(const Windows::UI::Xaml::Controls::ComboBoxItem & owner)
    {
        GetActivationFactory<ComboBoxItemAutomationPeer, IComboBoxItemAutomationPeerFactory>().CreateInstanceWithOwner(owner, *this, m_inner);
    }
};

template <typename T, typename ... Interfaces> struct ComboBoxItemDataAutomationPeerT :
    overrides<T, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverridesT<T>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2T<T>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3T<T>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides4T<T>, Interfaces ...>,
    requires<T, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer, Windows::UI::Xaml::Automation::Peers::IAutomationPeerProtected, Windows::UI::Xaml::Automation::Peers::IAutomationPeer2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer3, Windows::UI::Xaml::Automation::Peers::IAutomationPeer4, Windows::UI::Xaml::Automation::Peers::IItemAutomationPeer, Windows::UI::Xaml::Automation::Provider::IVirtualizedItemProvider, Windows::UI::Xaml::Automation::Peers::ISelectorItemAutomationPeer, Windows::UI::Xaml::Automation::Provider::ISelectionItemProvider, Windows::UI::Xaml::Automation::Peers::IComboBoxItemDataAutomationPeer, Windows::UI::Xaml::Automation::Provider::IScrollItemProvider>
{
    using composable = ComboBoxItemDataAutomationPeer;

protected:

    ComboBoxItemDataAutomationPeerT(const Windows::IInspectable & item, const Windows::UI::Xaml::Automation::Peers::ComboBoxAutomationPeer & parent)
    {
        GetActivationFactory<ComboBoxItemDataAutomationPeer, IComboBoxItemDataAutomationPeerFactory>().CreateInstanceWithParentAndItem(item, parent, *this, m_inner);
    }
};

template <typename T, typename ... Interfaces> struct DatePickerAutomationPeerT :
    overrides<T, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverridesT<T>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2T<T>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3T<T>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides4T<T>, Interfaces ...>,
    requires<T, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer, Windows::UI::Xaml::Automation::Peers::IAutomationPeerProtected, Windows::UI::Xaml::Automation::Peers::IAutomationPeer2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer3, Windows::UI::Xaml::Automation::Peers::IAutomationPeer4, Windows::UI::Xaml::Automation::Peers::IFrameworkElementAutomationPeer, Windows::UI::Xaml::Automation::Peers::IDatePickerAutomationPeer>
{
    using composable = DatePickerAutomationPeer;

protected:

    DatePickerAutomationPeerT(const Windows::UI::Xaml::Controls::DatePicker & owner)
    {
        GetActivationFactory<DatePickerAutomationPeer, IDatePickerAutomationPeerFactory>().CreateInstanceWithOwner(owner, *this, m_inner);
    }
};

template <typename T, typename ... Interfaces> struct FlipViewAutomationPeerT :
    overrides<T, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverridesT<T>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2T<T>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3T<T>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides4T<T>, Windows::UI::Xaml::Automation::Peers::IItemsControlAutomationPeerOverrides2T<T>, Interfaces ...>,
    requires<T, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer, Windows::UI::Xaml::Automation::Peers::IAutomationPeerProtected, Windows::UI::Xaml::Automation::Peers::IAutomationPeer2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer3, Windows::UI::Xaml::Automation::Peers::IAutomationPeer4, Windows::UI::Xaml::Automation::Peers::IFrameworkElementAutomationPeer, Windows::UI::Xaml::Automation::Peers::IItemsControlAutomationPeer, Windows::UI::Xaml::Automation::Provider::IItemContainerProvider, Windows::UI::Xaml::Automation::Peers::IItemsControlAutomationPeer2, Windows::UI::Xaml::Automation::Peers::ISelectorAutomationPeer, Windows::UI::Xaml::Automation::Provider::ISelectionProvider, Windows::UI::Xaml::Automation::Peers::IFlipViewAutomationPeer>
{
    using composable = FlipViewAutomationPeer;

protected:

    FlipViewAutomationPeerT(const Windows::UI::Xaml::Controls::FlipView & owner)
    {
        GetActivationFactory<FlipViewAutomationPeer, IFlipViewAutomationPeerFactory>().CreateInstanceWithOwner(owner, *this, m_inner);
    }
};

template <typename T, typename ... Interfaces> struct FlipViewItemAutomationPeerT :
    overrides<T, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverridesT<T>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2T<T>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3T<T>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides4T<T>, Interfaces ...>,
    requires<T, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer, Windows::UI::Xaml::Automation::Peers::IAutomationPeerProtected, Windows::UI::Xaml::Automation::Peers::IAutomationPeer2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer3, Windows::UI::Xaml::Automation::Peers::IAutomationPeer4, Windows::UI::Xaml::Automation::Peers::IFrameworkElementAutomationPeer, Windows::UI::Xaml::Automation::Peers::IFlipViewItemAutomationPeer>
{
    using composable = FlipViewItemAutomationPeer;

protected:

    FlipViewItemAutomationPeerT(const Windows::UI::Xaml::Controls::FlipViewItem & owner)
    {
        GetActivationFactory<FlipViewItemAutomationPeer, IFlipViewItemAutomationPeerFactory>().CreateInstanceWithOwner(owner, *this, m_inner);
    }
};

template <typename T, typename ... Interfaces> struct FlipViewItemDataAutomationPeerT :
    overrides<T, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverridesT<T>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2T<T>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3T<T>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides4T<T>, Interfaces ...>,
    requires<T, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer, Windows::UI::Xaml::Automation::Peers::IAutomationPeerProtected, Windows::UI::Xaml::Automation::Peers::IAutomationPeer2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer3, Windows::UI::Xaml::Automation::Peers::IAutomationPeer4, Windows::UI::Xaml::Automation::Peers::IItemAutomationPeer, Windows::UI::Xaml::Automation::Provider::IVirtualizedItemProvider, Windows::UI::Xaml::Automation::Peers::ISelectorItemAutomationPeer, Windows::UI::Xaml::Automation::Provider::ISelectionItemProvider, Windows::UI::Xaml::Automation::Peers::IFlipViewItemDataAutomationPeer, Windows::UI::Xaml::Automation::Provider::IScrollItemProvider>
{
    using composable = FlipViewItemDataAutomationPeer;

protected:

    FlipViewItemDataAutomationPeerT(const Windows::IInspectable & item, const Windows::UI::Xaml::Automation::Peers::FlipViewAutomationPeer & parent)
    {
        GetActivationFactory<FlipViewItemDataAutomationPeer, IFlipViewItemDataAutomationPeerFactory>().CreateInstanceWithParentAndItem(item, parent, *this, m_inner);
    }
};

template <typename T, typename ... Interfaces> struct FlyoutPresenterAutomationPeerT :
    overrides<T, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverridesT<T>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2T<T>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3T<T>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides4T<T>, Interfaces ...>,
    requires<T, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer, Windows::UI::Xaml::Automation::Peers::IAutomationPeerProtected, Windows::UI::Xaml::Automation::Peers::IAutomationPeer2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer3, Windows::UI::Xaml::Automation::Peers::IAutomationPeer4, Windows::UI::Xaml::Automation::Peers::IFrameworkElementAutomationPeer, Windows::UI::Xaml::Automation::Peers::IFlyoutPresenterAutomationPeer>
{
    using composable = FlyoutPresenterAutomationPeer;

protected:

    FlyoutPresenterAutomationPeerT(const Windows::UI::Xaml::Controls::FlyoutPresenter & owner)
    {
        GetActivationFactory<FlyoutPresenterAutomationPeer, IFlyoutPresenterAutomationPeerFactory>().CreateInstanceWithOwner(owner, *this, m_inner);
    }
};

template <typename T, typename ... Interfaces> struct FrameworkElementAutomationPeerT :
    overrides<T, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverridesT<T>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2T<T>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3T<T>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides4T<T>, Interfaces ...>,
    requires<T, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer, Windows::UI::Xaml::Automation::Peers::IAutomationPeerProtected, Windows::UI::Xaml::Automation::Peers::IAutomationPeer2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer3, Windows::UI::Xaml::Automation::Peers::IAutomationPeer4, Windows::UI::Xaml::Automation::Peers::IFrameworkElementAutomationPeer>
{
    using composable = FrameworkElementAutomationPeer;

protected:

    FrameworkElementAutomationPeerT(const Windows::UI::Xaml::FrameworkElement & owner)
    {
        GetActivationFactory<FrameworkElementAutomationPeer, IFrameworkElementAutomationPeerFactory>().CreateInstanceWithOwner(owner, *this, m_inner);
    }
};

template <typename T, typename ... Interfaces> struct GridViewAutomationPeerT :
    overrides<T, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverridesT<T>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2T<T>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3T<T>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides4T<T>, Windows::UI::Xaml::Automation::Peers::IItemsControlAutomationPeerOverrides2T<T>, Interfaces ...>,
    requires<T, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer, Windows::UI::Xaml::Automation::Peers::IAutomationPeerProtected, Windows::UI::Xaml::Automation::Peers::IAutomationPeer2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer3, Windows::UI::Xaml::Automation::Peers::IAutomationPeer4, Windows::UI::Xaml::Automation::Peers::IFrameworkElementAutomationPeer, Windows::UI::Xaml::Automation::Peers::IItemsControlAutomationPeer, Windows::UI::Xaml::Automation::Provider::IItemContainerProvider, Windows::UI::Xaml::Automation::Peers::IItemsControlAutomationPeer2, Windows::UI::Xaml::Automation::Peers::ISelectorAutomationPeer, Windows::UI::Xaml::Automation::Provider::ISelectionProvider, Windows::UI::Xaml::Automation::Peers::IListViewBaseAutomationPeer, Windows::UI::Xaml::Automation::Provider::IDropTargetProvider, Windows::UI::Xaml::Automation::Peers::IGridViewAutomationPeer>
{
    using composable = GridViewAutomationPeer;

protected:

    GridViewAutomationPeerT(const Windows::UI::Xaml::Controls::GridView & owner)
    {
        GetActivationFactory<GridViewAutomationPeer, IGridViewAutomationPeerFactory>().CreateInstanceWithOwner(owner, *this, m_inner);
    }
};

template <typename T, typename ... Interfaces> struct GridViewHeaderItemAutomationPeerT :
    overrides<T, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverridesT<T>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2T<T>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3T<T>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides4T<T>, Interfaces ...>,
    requires<T, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer, Windows::UI::Xaml::Automation::Peers::IAutomationPeerProtected, Windows::UI::Xaml::Automation::Peers::IAutomationPeer2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer3, Windows::UI::Xaml::Automation::Peers::IAutomationPeer4, Windows::UI::Xaml::Automation::Peers::IFrameworkElementAutomationPeer, Windows::UI::Xaml::Automation::Peers::IListViewBaseHeaderItemAutomationPeer, Windows::UI::Xaml::Automation::Peers::IGridViewHeaderItemAutomationPeer>
{
    using composable = GridViewHeaderItemAutomationPeer;

protected:

    GridViewHeaderItemAutomationPeerT(const Windows::UI::Xaml::Controls::GridViewHeaderItem & owner)
    {
        GetActivationFactory<GridViewHeaderItemAutomationPeer, IGridViewHeaderItemAutomationPeerFactory>().CreateInstanceWithOwner(owner, *this, m_inner);
    }
};

template <typename T, typename ... Interfaces> struct GridViewItemAutomationPeerT :
    overrides<T, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverridesT<T>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2T<T>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3T<T>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides4T<T>, Interfaces ...>,
    requires<T, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer, Windows::UI::Xaml::Automation::Peers::IAutomationPeerProtected, Windows::UI::Xaml::Automation::Peers::IAutomationPeer2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer3, Windows::UI::Xaml::Automation::Peers::IAutomationPeer4, Windows::UI::Xaml::Automation::Peers::IFrameworkElementAutomationPeer, Windows::UI::Xaml::Automation::Peers::IGridViewItemAutomationPeer>
{
    using composable = GridViewItemAutomationPeer;

protected:

    GridViewItemAutomationPeerT(const Windows::UI::Xaml::Controls::GridViewItem & owner)
    {
        GetActivationFactory<GridViewItemAutomationPeer, IGridViewItemAutomationPeerFactory>().CreateInstanceWithOwner(owner, *this, m_inner);
    }
};

template <typename T, typename ... Interfaces> struct GridViewItemDataAutomationPeerT :
    overrides<T, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverridesT<T>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2T<T>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3T<T>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides4T<T>, Interfaces ...>,
    requires<T, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer, Windows::UI::Xaml::Automation::Peers::IAutomationPeerProtected, Windows::UI::Xaml::Automation::Peers::IAutomationPeer2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer3, Windows::UI::Xaml::Automation::Peers::IAutomationPeer4, Windows::UI::Xaml::Automation::Peers::IItemAutomationPeer, Windows::UI::Xaml::Automation::Provider::IVirtualizedItemProvider, Windows::UI::Xaml::Automation::Peers::ISelectorItemAutomationPeer, Windows::UI::Xaml::Automation::Provider::ISelectionItemProvider, Windows::UI::Xaml::Automation::Peers::IGridViewItemDataAutomationPeer, Windows::UI::Xaml::Automation::Provider::IScrollItemProvider>
{
    using composable = GridViewItemDataAutomationPeer;

protected:

    GridViewItemDataAutomationPeerT(const Windows::IInspectable & item, const Windows::UI::Xaml::Automation::Peers::GridViewAutomationPeer & parent)
    {
        GetActivationFactory<GridViewItemDataAutomationPeer, IGridViewItemDataAutomationPeerFactory>().CreateInstanceWithParentAndItem(item, parent, *this, m_inner);
    }
};

template <typename T, typename ... Interfaces> struct GroupItemAutomationPeerT :
    overrides<T, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverridesT<T>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2T<T>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3T<T>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides4T<T>, Interfaces ...>,
    requires<T, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer, Windows::UI::Xaml::Automation::Peers::IAutomationPeerProtected, Windows::UI::Xaml::Automation::Peers::IAutomationPeer2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer3, Windows::UI::Xaml::Automation::Peers::IAutomationPeer4, Windows::UI::Xaml::Automation::Peers::IFrameworkElementAutomationPeer, Windows::UI::Xaml::Automation::Peers::IGroupItemAutomationPeer>
{
    using composable = GroupItemAutomationPeer;

protected:

    GroupItemAutomationPeerT(const Windows::UI::Xaml::Controls::GroupItem & owner)
    {
        GetActivationFactory<GroupItemAutomationPeer, IGroupItemAutomationPeerFactory>().CreateInstanceWithOwner(owner, *this, m_inner);
    }
};

template <typename T, typename ... Interfaces> struct HubAutomationPeerT :
    overrides<T, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverridesT<T>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2T<T>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3T<T>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides4T<T>, Interfaces ...>,
    requires<T, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer, Windows::UI::Xaml::Automation::Peers::IAutomationPeerProtected, Windows::UI::Xaml::Automation::Peers::IAutomationPeer2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer3, Windows::UI::Xaml::Automation::Peers::IAutomationPeer4, Windows::UI::Xaml::Automation::Peers::IFrameworkElementAutomationPeer, Windows::UI::Xaml::Automation::Peers::IHubAutomationPeer>
{
    using composable = HubAutomationPeer;

protected:

    HubAutomationPeerT(const Windows::UI::Xaml::Controls::Hub & owner)
    {
        GetActivationFactory<HubAutomationPeer, IHubAutomationPeerFactory>().CreateInstanceWithOwner(owner, *this, m_inner);
    }
};

template <typename T, typename ... Interfaces> struct HubSectionAutomationPeerT :
    overrides<T, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverridesT<T>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2T<T>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3T<T>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides4T<T>, Interfaces ...>,
    requires<T, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer, Windows::UI::Xaml::Automation::Peers::IAutomationPeerProtected, Windows::UI::Xaml::Automation::Peers::IAutomationPeer2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer3, Windows::UI::Xaml::Automation::Peers::IAutomationPeer4, Windows::UI::Xaml::Automation::Peers::IFrameworkElementAutomationPeer, Windows::UI::Xaml::Automation::Peers::IHubSectionAutomationPeer, Windows::UI::Xaml::Automation::Provider::IScrollItemProvider>
{
    using composable = HubSectionAutomationPeer;

protected:

    HubSectionAutomationPeerT(const Windows::UI::Xaml::Controls::HubSection & owner)
    {
        GetActivationFactory<HubSectionAutomationPeer, IHubSectionAutomationPeerFactory>().CreateInstanceWithOwner(owner, *this, m_inner);
    }
};

template <typename T, typename ... Interfaces> struct HyperlinkButtonAutomationPeerT :
    overrides<T, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverridesT<T>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2T<T>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3T<T>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides4T<T>, Interfaces ...>,
    requires<T, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer, Windows::UI::Xaml::Automation::Peers::IAutomationPeerProtected, Windows::UI::Xaml::Automation::Peers::IAutomationPeer2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer3, Windows::UI::Xaml::Automation::Peers::IAutomationPeer4, Windows::UI::Xaml::Automation::Peers::IFrameworkElementAutomationPeer, Windows::UI::Xaml::Automation::Peers::IButtonBaseAutomationPeer, Windows::UI::Xaml::Automation::Peers::IHyperlinkButtonAutomationPeer, Windows::UI::Xaml::Automation::Provider::IInvokeProvider>
{
    using composable = HyperlinkButtonAutomationPeer;

protected:

    HyperlinkButtonAutomationPeerT(const Windows::UI::Xaml::Controls::HyperlinkButton & owner)
    {
        GetActivationFactory<HyperlinkButtonAutomationPeer, IHyperlinkButtonAutomationPeerFactory>().CreateInstanceWithOwner(owner, *this, m_inner);
    }
};

template <typename T, typename ... Interfaces> struct ImageAutomationPeerT :
    overrides<T, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverridesT<T>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2T<T>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3T<T>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides4T<T>, Interfaces ...>,
    requires<T, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer, Windows::UI::Xaml::Automation::Peers::IAutomationPeerProtected, Windows::UI::Xaml::Automation::Peers::IAutomationPeer2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer3, Windows::UI::Xaml::Automation::Peers::IAutomationPeer4, Windows::UI::Xaml::Automation::Peers::IFrameworkElementAutomationPeer, Windows::UI::Xaml::Automation::Peers::IImageAutomationPeer>
{
    using composable = ImageAutomationPeer;

protected:

    ImageAutomationPeerT(const Windows::UI::Xaml::Controls::Image & owner)
    {
        GetActivationFactory<ImageAutomationPeer, IImageAutomationPeerFactory>().CreateInstanceWithOwner(owner, *this, m_inner);
    }
};

template <typename T, typename ... Interfaces> struct ItemAutomationPeerT :
    overrides<T, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverridesT<T>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2T<T>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3T<T>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides4T<T>, Interfaces ...>,
    requires<T, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer, Windows::UI::Xaml::Automation::Peers::IAutomationPeerProtected, Windows::UI::Xaml::Automation::Peers::IAutomationPeer2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer3, Windows::UI::Xaml::Automation::Peers::IAutomationPeer4, Windows::UI::Xaml::Automation::Peers::IItemAutomationPeer, Windows::UI::Xaml::Automation::Provider::IVirtualizedItemProvider>
{
    using composable = ItemAutomationPeer;

protected:

    ItemAutomationPeerT(const Windows::IInspectable & item, const Windows::UI::Xaml::Automation::Peers::ItemsControlAutomationPeer & parent)
    {
        GetActivationFactory<ItemAutomationPeer, IItemAutomationPeerFactory>().CreateInstanceWithParentAndItem(item, parent, *this, m_inner);
    }
};

template <typename T, typename ... Interfaces> struct ItemsControlAutomationPeerT :
    overrides<T, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverridesT<T>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2T<T>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3T<T>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides4T<T>, Windows::UI::Xaml::Automation::Peers::IItemsControlAutomationPeerOverrides2T<T>, Interfaces ...>,
    requires<T, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer, Windows::UI::Xaml::Automation::Peers::IAutomationPeerProtected, Windows::UI::Xaml::Automation::Peers::IAutomationPeer2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer3, Windows::UI::Xaml::Automation::Peers::IAutomationPeer4, Windows::UI::Xaml::Automation::Peers::IFrameworkElementAutomationPeer, Windows::UI::Xaml::Automation::Peers::IItemsControlAutomationPeer, Windows::UI::Xaml::Automation::Provider::IItemContainerProvider, Windows::UI::Xaml::Automation::Peers::IItemsControlAutomationPeer2>
{
    using composable = ItemsControlAutomationPeer;

protected:

    ItemsControlAutomationPeerT(const Windows::UI::Xaml::Controls::ItemsControl & owner)
    {
        GetActivationFactory<ItemsControlAutomationPeer, IItemsControlAutomationPeerFactory>().CreateInstanceWithOwner(owner, *this, m_inner);
    }
};

template <typename T, typename ... Interfaces> struct ListBoxAutomationPeerT :
    overrides<T, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverridesT<T>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2T<T>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3T<T>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides4T<T>, Windows::UI::Xaml::Automation::Peers::IItemsControlAutomationPeerOverrides2T<T>, Interfaces ...>,
    requires<T, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer, Windows::UI::Xaml::Automation::Peers::IAutomationPeerProtected, Windows::UI::Xaml::Automation::Peers::IAutomationPeer2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer3, Windows::UI::Xaml::Automation::Peers::IAutomationPeer4, Windows::UI::Xaml::Automation::Peers::IFrameworkElementAutomationPeer, Windows::UI::Xaml::Automation::Peers::IItemsControlAutomationPeer, Windows::UI::Xaml::Automation::Provider::IItemContainerProvider, Windows::UI::Xaml::Automation::Peers::IItemsControlAutomationPeer2, Windows::UI::Xaml::Automation::Peers::ISelectorAutomationPeer, Windows::UI::Xaml::Automation::Provider::ISelectionProvider, Windows::UI::Xaml::Automation::Peers::IListBoxAutomationPeer>
{
    using composable = ListBoxAutomationPeer;

protected:

    ListBoxAutomationPeerT(const Windows::UI::Xaml::Controls::ListBox & owner)
    {
        GetActivationFactory<ListBoxAutomationPeer, IListBoxAutomationPeerFactory>().CreateInstanceWithOwner(owner, *this, m_inner);
    }
};

template <typename T, typename ... Interfaces> struct ListBoxItemAutomationPeerT :
    overrides<T, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverridesT<T>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2T<T>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3T<T>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides4T<T>, Interfaces ...>,
    requires<T, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer, Windows::UI::Xaml::Automation::Peers::IAutomationPeerProtected, Windows::UI::Xaml::Automation::Peers::IAutomationPeer2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer3, Windows::UI::Xaml::Automation::Peers::IAutomationPeer4, Windows::UI::Xaml::Automation::Peers::IFrameworkElementAutomationPeer, Windows::UI::Xaml::Automation::Peers::IListBoxItemAutomationPeer>
{
    using composable = ListBoxItemAutomationPeer;

protected:

    ListBoxItemAutomationPeerT(const Windows::UI::Xaml::Controls::ListBoxItem & owner)
    {
        GetActivationFactory<ListBoxItemAutomationPeer, IListBoxItemAutomationPeerFactory>().CreateInstanceWithOwner(owner, *this, m_inner);
    }
};

template <typename T, typename ... Interfaces> struct ListBoxItemDataAutomationPeerT :
    overrides<T, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverridesT<T>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2T<T>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3T<T>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides4T<T>, Interfaces ...>,
    requires<T, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer, Windows::UI::Xaml::Automation::Peers::IAutomationPeerProtected, Windows::UI::Xaml::Automation::Peers::IAutomationPeer2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer3, Windows::UI::Xaml::Automation::Peers::IAutomationPeer4, Windows::UI::Xaml::Automation::Peers::IItemAutomationPeer, Windows::UI::Xaml::Automation::Provider::IVirtualizedItemProvider, Windows::UI::Xaml::Automation::Peers::ISelectorItemAutomationPeer, Windows::UI::Xaml::Automation::Provider::ISelectionItemProvider, Windows::UI::Xaml::Automation::Peers::IListBoxItemDataAutomationPeer, Windows::UI::Xaml::Automation::Provider::IScrollItemProvider>
{
    using composable = ListBoxItemDataAutomationPeer;

protected:

    ListBoxItemDataAutomationPeerT(const Windows::IInspectable & item, const Windows::UI::Xaml::Automation::Peers::ListBoxAutomationPeer & parent)
    {
        GetActivationFactory<ListBoxItemDataAutomationPeer, IListBoxItemDataAutomationPeerFactory>().CreateInstanceWithParentAndItem(item, parent, *this, m_inner);
    }
};

template <typename T, typename ... Interfaces> struct ListViewAutomationPeerT :
    overrides<T, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverridesT<T>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2T<T>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3T<T>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides4T<T>, Windows::UI::Xaml::Automation::Peers::IItemsControlAutomationPeerOverrides2T<T>, Interfaces ...>,
    requires<T, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer, Windows::UI::Xaml::Automation::Peers::IAutomationPeerProtected, Windows::UI::Xaml::Automation::Peers::IAutomationPeer2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer3, Windows::UI::Xaml::Automation::Peers::IAutomationPeer4, Windows::UI::Xaml::Automation::Peers::IFrameworkElementAutomationPeer, Windows::UI::Xaml::Automation::Peers::IItemsControlAutomationPeer, Windows::UI::Xaml::Automation::Provider::IItemContainerProvider, Windows::UI::Xaml::Automation::Peers::IItemsControlAutomationPeer2, Windows::UI::Xaml::Automation::Peers::ISelectorAutomationPeer, Windows::UI::Xaml::Automation::Provider::ISelectionProvider, Windows::UI::Xaml::Automation::Peers::IListViewBaseAutomationPeer, Windows::UI::Xaml::Automation::Provider::IDropTargetProvider, Windows::UI::Xaml::Automation::Peers::IListViewAutomationPeer>
{
    using composable = ListViewAutomationPeer;

protected:

    ListViewAutomationPeerT(const Windows::UI::Xaml::Controls::ListView & owner)
    {
        GetActivationFactory<ListViewAutomationPeer, IListViewAutomationPeerFactory>().CreateInstanceWithOwner(owner, *this, m_inner);
    }
};

template <typename T, typename ... Interfaces> struct ListViewBaseAutomationPeerT :
    overrides<T, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverridesT<T>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2T<T>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3T<T>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides4T<T>, Windows::UI::Xaml::Automation::Peers::IItemsControlAutomationPeerOverrides2T<T>, Interfaces ...>,
    requires<T, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer, Windows::UI::Xaml::Automation::Peers::IAutomationPeerProtected, Windows::UI::Xaml::Automation::Peers::IAutomationPeer2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer3, Windows::UI::Xaml::Automation::Peers::IAutomationPeer4, Windows::UI::Xaml::Automation::Peers::IFrameworkElementAutomationPeer, Windows::UI::Xaml::Automation::Peers::IItemsControlAutomationPeer, Windows::UI::Xaml::Automation::Provider::IItemContainerProvider, Windows::UI::Xaml::Automation::Peers::IItemsControlAutomationPeer2, Windows::UI::Xaml::Automation::Peers::ISelectorAutomationPeer, Windows::UI::Xaml::Automation::Provider::ISelectionProvider, Windows::UI::Xaml::Automation::Peers::IListViewBaseAutomationPeer, Windows::UI::Xaml::Automation::Provider::IDropTargetProvider>
{
    using composable = ListViewBaseAutomationPeer;

protected:

    ListViewBaseAutomationPeerT(const Windows::UI::Xaml::Controls::ListViewBase & owner)
    {
        GetActivationFactory<ListViewBaseAutomationPeer, IListViewBaseAutomationPeerFactory>().CreateInstanceWithOwner(owner, *this, m_inner);
    }
};

template <typename T, typename ... Interfaces> struct ListViewBaseHeaderItemAutomationPeerT :
    overrides<T, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverridesT<T>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2T<T>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3T<T>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides4T<T>, Interfaces ...>,
    requires<T, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer, Windows::UI::Xaml::Automation::Peers::IAutomationPeerProtected, Windows::UI::Xaml::Automation::Peers::IAutomationPeer2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer3, Windows::UI::Xaml::Automation::Peers::IAutomationPeer4, Windows::UI::Xaml::Automation::Peers::IFrameworkElementAutomationPeer, Windows::UI::Xaml::Automation::Peers::IListViewBaseHeaderItemAutomationPeer>
{
    using composable = ListViewBaseHeaderItemAutomationPeer;

protected:

    ListViewBaseHeaderItemAutomationPeerT(const Windows::UI::Xaml::Controls::ListViewBaseHeaderItem & owner)
    {
        GetActivationFactory<ListViewBaseHeaderItemAutomationPeer, IListViewBaseHeaderItemAutomationPeerFactory>().CreateInstanceWithOwner(owner, *this, m_inner);
    }
};

template <typename T, typename ... Interfaces> struct ListViewHeaderItemAutomationPeerT :
    overrides<T, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverridesT<T>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2T<T>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3T<T>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides4T<T>, Interfaces ...>,
    requires<T, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer, Windows::UI::Xaml::Automation::Peers::IAutomationPeerProtected, Windows::UI::Xaml::Automation::Peers::IAutomationPeer2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer3, Windows::UI::Xaml::Automation::Peers::IAutomationPeer4, Windows::UI::Xaml::Automation::Peers::IFrameworkElementAutomationPeer, Windows::UI::Xaml::Automation::Peers::IListViewBaseHeaderItemAutomationPeer, Windows::UI::Xaml::Automation::Peers::IListViewHeaderItemAutomationPeer>
{
    using composable = ListViewHeaderItemAutomationPeer;

protected:

    ListViewHeaderItemAutomationPeerT(const Windows::UI::Xaml::Controls::ListViewHeaderItem & owner)
    {
        GetActivationFactory<ListViewHeaderItemAutomationPeer, IListViewHeaderItemAutomationPeerFactory>().CreateInstanceWithOwner(owner, *this, m_inner);
    }
};

template <typename T, typename ... Interfaces> struct ListViewItemAutomationPeerT :
    overrides<T, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverridesT<T>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2T<T>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3T<T>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides4T<T>, Interfaces ...>,
    requires<T, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer, Windows::UI::Xaml::Automation::Peers::IAutomationPeerProtected, Windows::UI::Xaml::Automation::Peers::IAutomationPeer2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer3, Windows::UI::Xaml::Automation::Peers::IAutomationPeer4, Windows::UI::Xaml::Automation::Peers::IFrameworkElementAutomationPeer, Windows::UI::Xaml::Automation::Peers::IListViewItemAutomationPeer>
{
    using composable = ListViewItemAutomationPeer;

protected:

    ListViewItemAutomationPeerT(const Windows::UI::Xaml::Controls::ListViewItem & owner)
    {
        GetActivationFactory<ListViewItemAutomationPeer, IListViewItemAutomationPeerFactory>().CreateInstanceWithOwner(owner, *this, m_inner);
    }
};

template <typename T, typename ... Interfaces> struct ListViewItemDataAutomationPeerT :
    overrides<T, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverridesT<T>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2T<T>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3T<T>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides4T<T>, Interfaces ...>,
    requires<T, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer, Windows::UI::Xaml::Automation::Peers::IAutomationPeerProtected, Windows::UI::Xaml::Automation::Peers::IAutomationPeer2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer3, Windows::UI::Xaml::Automation::Peers::IAutomationPeer4, Windows::UI::Xaml::Automation::Peers::IItemAutomationPeer, Windows::UI::Xaml::Automation::Provider::IVirtualizedItemProvider, Windows::UI::Xaml::Automation::Peers::ISelectorItemAutomationPeer, Windows::UI::Xaml::Automation::Provider::ISelectionItemProvider, Windows::UI::Xaml::Automation::Peers::IListViewItemDataAutomationPeer, Windows::UI::Xaml::Automation::Provider::IScrollItemProvider>
{
    using composable = ListViewItemDataAutomationPeer;

protected:

    ListViewItemDataAutomationPeerT(const Windows::IInspectable & item, const Windows::UI::Xaml::Automation::Peers::ListViewBaseAutomationPeer & parent)
    {
        GetActivationFactory<ListViewItemDataAutomationPeer, IListViewItemDataAutomationPeerFactory>().CreateInstanceWithParentAndItem(item, parent, *this, m_inner);
    }
};

template <typename T, typename ... Interfaces> struct MediaElementAutomationPeerT :
    overrides<T, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverridesT<T>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2T<T>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3T<T>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides4T<T>, Interfaces ...>,
    requires<T, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer, Windows::UI::Xaml::Automation::Peers::IAutomationPeerProtected, Windows::UI::Xaml::Automation::Peers::IAutomationPeer2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer3, Windows::UI::Xaml::Automation::Peers::IAutomationPeer4, Windows::UI::Xaml::Automation::Peers::IFrameworkElementAutomationPeer, Windows::UI::Xaml::Automation::Peers::IMediaElementAutomationPeer>
{
    using composable = MediaElementAutomationPeer;

protected:

    MediaElementAutomationPeerT(const Windows::UI::Xaml::Controls::MediaElement & owner)
    {
        GetActivationFactory<MediaElementAutomationPeer, IMediaElementAutomationPeerFactory>().CreateInstanceWithOwner(owner, *this, m_inner);
    }
};

template <typename T, typename ... Interfaces> struct MediaTransportControlsAutomationPeerT :
    overrides<T, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverridesT<T>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2T<T>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3T<T>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides4T<T>, Interfaces ...>,
    requires<T, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer, Windows::UI::Xaml::Automation::Peers::IAutomationPeerProtected, Windows::UI::Xaml::Automation::Peers::IAutomationPeer2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer3, Windows::UI::Xaml::Automation::Peers::IAutomationPeer4, Windows::UI::Xaml::Automation::Peers::IFrameworkElementAutomationPeer, Windows::UI::Xaml::Automation::Peers::IMediaTransportControlsAutomationPeer>
{
    using composable = MediaTransportControlsAutomationPeer;

protected:

    MediaTransportControlsAutomationPeerT(const Windows::UI::Xaml::Controls::MediaTransportControls & owner)
    {
        GetActivationFactory<MediaTransportControlsAutomationPeer, IMediaTransportControlsAutomationPeerFactory>().CreateInstanceWithOwner(owner, *this, m_inner);
    }
};

template <typename T, typename ... Interfaces> struct MenuFlyoutItemAutomationPeerT :
    overrides<T, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverridesT<T>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2T<T>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3T<T>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides4T<T>, Interfaces ...>,
    requires<T, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer, Windows::UI::Xaml::Automation::Peers::IAutomationPeerProtected, Windows::UI::Xaml::Automation::Peers::IAutomationPeer2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer3, Windows::UI::Xaml::Automation::Peers::IAutomationPeer4, Windows::UI::Xaml::Automation::Peers::IFrameworkElementAutomationPeer, Windows::UI::Xaml::Automation::Peers::IMenuFlyoutItemAutomationPeer, Windows::UI::Xaml::Automation::Provider::IInvokeProvider>
{
    using composable = MenuFlyoutItemAutomationPeer;

protected:

    MenuFlyoutItemAutomationPeerT(const Windows::UI::Xaml::Controls::MenuFlyoutItem & owner)
    {
        GetActivationFactory<MenuFlyoutItemAutomationPeer, IMenuFlyoutItemAutomationPeerFactory>().CreateInstanceWithOwner(owner, *this, m_inner);
    }
};

template <typename T, typename ... Interfaces> struct MenuFlyoutPresenterAutomationPeerT :
    overrides<T, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverridesT<T>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2T<T>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3T<T>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides4T<T>, Windows::UI::Xaml::Automation::Peers::IItemsControlAutomationPeerOverrides2T<T>, Interfaces ...>,
    requires<T, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer, Windows::UI::Xaml::Automation::Peers::IAutomationPeerProtected, Windows::UI::Xaml::Automation::Peers::IAutomationPeer2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer3, Windows::UI::Xaml::Automation::Peers::IAutomationPeer4, Windows::UI::Xaml::Automation::Peers::IFrameworkElementAutomationPeer, Windows::UI::Xaml::Automation::Peers::IItemsControlAutomationPeer, Windows::UI::Xaml::Automation::Provider::IItemContainerProvider, Windows::UI::Xaml::Automation::Peers::IItemsControlAutomationPeer2, Windows::UI::Xaml::Automation::Peers::IMenuFlyoutPresenterAutomationPeer>
{
    using composable = MenuFlyoutPresenterAutomationPeer;

protected:

    MenuFlyoutPresenterAutomationPeerT(const Windows::UI::Xaml::Controls::MenuFlyoutPresenter & owner)
    {
        GetActivationFactory<MenuFlyoutPresenterAutomationPeer, IMenuFlyoutPresenterAutomationPeerFactory>().CreateInstanceWithOwner(owner, *this, m_inner);
    }
};

template <typename T, typename ... Interfaces> struct PasswordBoxAutomationPeerT :
    overrides<T, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverridesT<T>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2T<T>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3T<T>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides4T<T>, Interfaces ...>,
    requires<T, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer, Windows::UI::Xaml::Automation::Peers::IAutomationPeerProtected, Windows::UI::Xaml::Automation::Peers::IAutomationPeer2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer3, Windows::UI::Xaml::Automation::Peers::IAutomationPeer4, Windows::UI::Xaml::Automation::Peers::IFrameworkElementAutomationPeer, Windows::UI::Xaml::Automation::Peers::IPasswordBoxAutomationPeer>
{
    using composable = PasswordBoxAutomationPeer;

protected:

    PasswordBoxAutomationPeerT(const Windows::UI::Xaml::Controls::PasswordBox & owner)
    {
        GetActivationFactory<PasswordBoxAutomationPeer, IPasswordBoxAutomationPeerFactory>().CreateInstanceWithOwner(owner, *this, m_inner);
    }
};

template <typename T, typename ... Interfaces> struct ProgressBarAutomationPeerT :
    overrides<T, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverridesT<T>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2T<T>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3T<T>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides4T<T>, Interfaces ...>,
    requires<T, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer, Windows::UI::Xaml::Automation::Peers::IAutomationPeerProtected, Windows::UI::Xaml::Automation::Peers::IAutomationPeer2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer3, Windows::UI::Xaml::Automation::Peers::IAutomationPeer4, Windows::UI::Xaml::Automation::Peers::IFrameworkElementAutomationPeer, Windows::UI::Xaml::Automation::Peers::IRangeBaseAutomationPeer, Windows::UI::Xaml::Automation::Provider::IRangeValueProvider, Windows::UI::Xaml::Automation::Peers::IProgressBarAutomationPeer>
{
    using composable = ProgressBarAutomationPeer;

protected:

    ProgressBarAutomationPeerT(const Windows::UI::Xaml::Controls::ProgressBar & owner)
    {
        GetActivationFactory<ProgressBarAutomationPeer, IProgressBarAutomationPeerFactory>().CreateInstanceWithOwner(owner, *this, m_inner);
    }
};

template <typename T, typename ... Interfaces> struct ProgressRingAutomationPeerT :
    overrides<T, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverridesT<T>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2T<T>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3T<T>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides4T<T>, Interfaces ...>,
    requires<T, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer, Windows::UI::Xaml::Automation::Peers::IAutomationPeerProtected, Windows::UI::Xaml::Automation::Peers::IAutomationPeer2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer3, Windows::UI::Xaml::Automation::Peers::IAutomationPeer4, Windows::UI::Xaml::Automation::Peers::IFrameworkElementAutomationPeer, Windows::UI::Xaml::Automation::Peers::IProgressRingAutomationPeer>
{
    using composable = ProgressRingAutomationPeer;

protected:

    ProgressRingAutomationPeerT(const Windows::UI::Xaml::Controls::ProgressRing & owner)
    {
        GetActivationFactory<ProgressRingAutomationPeer, IProgressRingAutomationPeerFactory>().CreateInstanceWithOwner(owner, *this, m_inner);
    }
};

template <typename T, typename ... Interfaces> struct RadioButtonAutomationPeerT :
    overrides<T, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverridesT<T>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2T<T>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3T<T>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides4T<T>, Interfaces ...>,
    requires<T, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer, Windows::UI::Xaml::Automation::Peers::IAutomationPeerProtected, Windows::UI::Xaml::Automation::Peers::IAutomationPeer2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer3, Windows::UI::Xaml::Automation::Peers::IAutomationPeer4, Windows::UI::Xaml::Automation::Peers::IFrameworkElementAutomationPeer, Windows::UI::Xaml::Automation::Peers::IButtonBaseAutomationPeer, Windows::UI::Xaml::Automation::Peers::IToggleButtonAutomationPeer, Windows::UI::Xaml::Automation::Provider::IToggleProvider, Windows::UI::Xaml::Automation::Peers::IRadioButtonAutomationPeer, Windows::UI::Xaml::Automation::Provider::ISelectionItemProvider>
{
    using composable = RadioButtonAutomationPeer;

protected:

    RadioButtonAutomationPeerT(const Windows::UI::Xaml::Controls::RadioButton & owner)
    {
        GetActivationFactory<RadioButtonAutomationPeer, IRadioButtonAutomationPeerFactory>().CreateInstanceWithOwner(owner, *this, m_inner);
    }
};

template <typename T, typename ... Interfaces> struct RangeBaseAutomationPeerT :
    overrides<T, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverridesT<T>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2T<T>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3T<T>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides4T<T>, Interfaces ...>,
    requires<T, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer, Windows::UI::Xaml::Automation::Peers::IAutomationPeerProtected, Windows::UI::Xaml::Automation::Peers::IAutomationPeer2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer3, Windows::UI::Xaml::Automation::Peers::IAutomationPeer4, Windows::UI::Xaml::Automation::Peers::IFrameworkElementAutomationPeer, Windows::UI::Xaml::Automation::Peers::IRangeBaseAutomationPeer, Windows::UI::Xaml::Automation::Provider::IRangeValueProvider>
{
    using composable = RangeBaseAutomationPeer;

protected:

    RangeBaseAutomationPeerT(const Windows::UI::Xaml::Controls::Primitives::RangeBase & owner)
    {
        GetActivationFactory<RangeBaseAutomationPeer, IRangeBaseAutomationPeerFactory>().CreateInstanceWithOwner(owner, *this, m_inner);
    }
};

template <typename T, typename ... Interfaces> struct RepeatButtonAutomationPeerT :
    overrides<T, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverridesT<T>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2T<T>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3T<T>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides4T<T>, Interfaces ...>,
    requires<T, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer, Windows::UI::Xaml::Automation::Peers::IAutomationPeerProtected, Windows::UI::Xaml::Automation::Peers::IAutomationPeer2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer3, Windows::UI::Xaml::Automation::Peers::IAutomationPeer4, Windows::UI::Xaml::Automation::Peers::IFrameworkElementAutomationPeer, Windows::UI::Xaml::Automation::Peers::IButtonBaseAutomationPeer, Windows::UI::Xaml::Automation::Peers::IRepeatButtonAutomationPeer, Windows::UI::Xaml::Automation::Provider::IInvokeProvider>
{
    using composable = RepeatButtonAutomationPeer;

protected:

    RepeatButtonAutomationPeerT(const Windows::UI::Xaml::Controls::Primitives::RepeatButton & owner)
    {
        GetActivationFactory<RepeatButtonAutomationPeer, IRepeatButtonAutomationPeerFactory>().CreateInstanceWithOwner(owner, *this, m_inner);
    }
};

template <typename T, typename ... Interfaces> struct RichEditBoxAutomationPeerT :
    overrides<T, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverridesT<T>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2T<T>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3T<T>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides4T<T>, Interfaces ...>,
    requires<T, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer, Windows::UI::Xaml::Automation::Peers::IAutomationPeerProtected, Windows::UI::Xaml::Automation::Peers::IAutomationPeer2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer3, Windows::UI::Xaml::Automation::Peers::IAutomationPeer4, Windows::UI::Xaml::Automation::Peers::IFrameworkElementAutomationPeer, Windows::UI::Xaml::Automation::Peers::IRichEditBoxAutomationPeer>
{
    using composable = RichEditBoxAutomationPeer;

protected:

    RichEditBoxAutomationPeerT(const Windows::UI::Xaml::Controls::RichEditBox & owner)
    {
        GetActivationFactory<RichEditBoxAutomationPeer, IRichEditBoxAutomationPeerFactory>().CreateInstanceWithOwner(owner, *this, m_inner);
    }
};

template <typename T, typename ... Interfaces> struct RichTextBlockAutomationPeerT :
    overrides<T, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverridesT<T>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2T<T>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3T<T>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides4T<T>, Interfaces ...>,
    requires<T, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer, Windows::UI::Xaml::Automation::Peers::IAutomationPeerProtected, Windows::UI::Xaml::Automation::Peers::IAutomationPeer2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer3, Windows::UI::Xaml::Automation::Peers::IAutomationPeer4, Windows::UI::Xaml::Automation::Peers::IFrameworkElementAutomationPeer, Windows::UI::Xaml::Automation::Peers::IRichTextBlockAutomationPeer>
{
    using composable = RichTextBlockAutomationPeer;

protected:

    RichTextBlockAutomationPeerT(const Windows::UI::Xaml::Controls::RichTextBlock & owner)
    {
        GetActivationFactory<RichTextBlockAutomationPeer, IRichTextBlockAutomationPeerFactory>().CreateInstanceWithOwner(owner, *this, m_inner);
    }
};

template <typename T, typename ... Interfaces> struct RichTextBlockOverflowAutomationPeerT :
    overrides<T, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverridesT<T>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2T<T>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3T<T>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides4T<T>, Interfaces ...>,
    requires<T, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer, Windows::UI::Xaml::Automation::Peers::IAutomationPeerProtected, Windows::UI::Xaml::Automation::Peers::IAutomationPeer2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer3, Windows::UI::Xaml::Automation::Peers::IAutomationPeer4, Windows::UI::Xaml::Automation::Peers::IFrameworkElementAutomationPeer, Windows::UI::Xaml::Automation::Peers::IRichTextBlockOverflowAutomationPeer>
{
    using composable = RichTextBlockOverflowAutomationPeer;

protected:

    RichTextBlockOverflowAutomationPeerT(const Windows::UI::Xaml::Controls::RichTextBlockOverflow & owner)
    {
        GetActivationFactory<RichTextBlockOverflowAutomationPeer, IRichTextBlockOverflowAutomationPeerFactory>().CreateInstanceWithOwner(owner, *this, m_inner);
    }
};

template <typename T, typename ... Interfaces> struct ScrollBarAutomationPeerT :
    overrides<T, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverridesT<T>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2T<T>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3T<T>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides4T<T>, Interfaces ...>,
    requires<T, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer, Windows::UI::Xaml::Automation::Peers::IAutomationPeerProtected, Windows::UI::Xaml::Automation::Peers::IAutomationPeer2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer3, Windows::UI::Xaml::Automation::Peers::IAutomationPeer4, Windows::UI::Xaml::Automation::Peers::IFrameworkElementAutomationPeer, Windows::UI::Xaml::Automation::Peers::IRangeBaseAutomationPeer, Windows::UI::Xaml::Automation::Provider::IRangeValueProvider, Windows::UI::Xaml::Automation::Peers::IScrollBarAutomationPeer>
{
    using composable = ScrollBarAutomationPeer;

protected:

    ScrollBarAutomationPeerT(const Windows::UI::Xaml::Controls::Primitives::ScrollBar & owner)
    {
        GetActivationFactory<ScrollBarAutomationPeer, IScrollBarAutomationPeerFactory>().CreateInstanceWithOwner(owner, *this, m_inner);
    }
};

template <typename T, typename ... Interfaces> struct ScrollViewerAutomationPeerT :
    overrides<T, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverridesT<T>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2T<T>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3T<T>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides4T<T>, Interfaces ...>,
    requires<T, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer, Windows::UI::Xaml::Automation::Peers::IAutomationPeerProtected, Windows::UI::Xaml::Automation::Peers::IAutomationPeer2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer3, Windows::UI::Xaml::Automation::Peers::IAutomationPeer4, Windows::UI::Xaml::Automation::Peers::IFrameworkElementAutomationPeer, Windows::UI::Xaml::Automation::Peers::IScrollViewerAutomationPeer, Windows::UI::Xaml::Automation::Provider::IScrollProvider>
{
    using composable = ScrollViewerAutomationPeer;

protected:

    ScrollViewerAutomationPeerT(const Windows::UI::Xaml::Controls::ScrollViewer & owner)
    {
        GetActivationFactory<ScrollViewerAutomationPeer, IScrollViewerAutomationPeerFactory>().CreateInstanceWithOwner(owner, *this, m_inner);
    }
};

template <typename T, typename ... Interfaces> struct SearchBoxAutomationPeerT :
    overrides<T, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverridesT<T>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2T<T>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3T<T>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides4T<T>, Interfaces ...>,
    requires<T, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer, Windows::UI::Xaml::Automation::Peers::IAutomationPeerProtected, Windows::UI::Xaml::Automation::Peers::IAutomationPeer2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer3, Windows::UI::Xaml::Automation::Peers::IAutomationPeer4, Windows::UI::Xaml::Automation::Peers::IFrameworkElementAutomationPeer, Windows::UI::Xaml::Automation::Peers::ISearchBoxAutomationPeer>
{
    using composable = SearchBoxAutomationPeer;

protected:

    SearchBoxAutomationPeerT(const Windows::UI::Xaml::Controls::SearchBox & owner)
    {
        GetActivationFactory<SearchBoxAutomationPeer, ISearchBoxAutomationPeerFactory>().CreateInstanceWithOwner(owner, *this, m_inner);
    }
};

template <typename T, typename ... Interfaces> struct SelectorAutomationPeerT :
    overrides<T, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverridesT<T>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2T<T>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3T<T>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides4T<T>, Windows::UI::Xaml::Automation::Peers::IItemsControlAutomationPeerOverrides2T<T>, Interfaces ...>,
    requires<T, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer, Windows::UI::Xaml::Automation::Peers::IAutomationPeerProtected, Windows::UI::Xaml::Automation::Peers::IAutomationPeer2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer3, Windows::UI::Xaml::Automation::Peers::IAutomationPeer4, Windows::UI::Xaml::Automation::Peers::IFrameworkElementAutomationPeer, Windows::UI::Xaml::Automation::Peers::IItemsControlAutomationPeer, Windows::UI::Xaml::Automation::Provider::IItemContainerProvider, Windows::UI::Xaml::Automation::Peers::IItemsControlAutomationPeer2, Windows::UI::Xaml::Automation::Peers::ISelectorAutomationPeer, Windows::UI::Xaml::Automation::Provider::ISelectionProvider>
{
    using composable = SelectorAutomationPeer;

protected:

    SelectorAutomationPeerT(const Windows::UI::Xaml::Controls::Primitives::Selector & owner)
    {
        GetActivationFactory<SelectorAutomationPeer, ISelectorAutomationPeerFactory>().CreateInstanceWithOwner(owner, *this, m_inner);
    }
};

template <typename T, typename ... Interfaces> struct SelectorItemAutomationPeerT :
    overrides<T, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverridesT<T>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2T<T>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3T<T>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides4T<T>, Interfaces ...>,
    requires<T, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer, Windows::UI::Xaml::Automation::Peers::IAutomationPeerProtected, Windows::UI::Xaml::Automation::Peers::IAutomationPeer2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer3, Windows::UI::Xaml::Automation::Peers::IAutomationPeer4, Windows::UI::Xaml::Automation::Peers::IItemAutomationPeer, Windows::UI::Xaml::Automation::Provider::IVirtualizedItemProvider, Windows::UI::Xaml::Automation::Peers::ISelectorItemAutomationPeer, Windows::UI::Xaml::Automation::Provider::ISelectionItemProvider>
{
    using composable = SelectorItemAutomationPeer;

protected:

    SelectorItemAutomationPeerT(const Windows::IInspectable & item, const Windows::UI::Xaml::Automation::Peers::SelectorAutomationPeer & parent)
    {
        GetActivationFactory<SelectorItemAutomationPeer, ISelectorItemAutomationPeerFactory>().CreateInstanceWithParentAndItem(item, parent, *this, m_inner);
    }
};

template <typename T, typename ... Interfaces> struct SemanticZoomAutomationPeerT :
    overrides<T, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverridesT<T>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2T<T>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3T<T>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides4T<T>, Interfaces ...>,
    requires<T, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer, Windows::UI::Xaml::Automation::Peers::IAutomationPeerProtected, Windows::UI::Xaml::Automation::Peers::IAutomationPeer2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer3, Windows::UI::Xaml::Automation::Peers::IAutomationPeer4, Windows::UI::Xaml::Automation::Peers::IFrameworkElementAutomationPeer, Windows::UI::Xaml::Automation::Peers::ISemanticZoomAutomationPeer, Windows::UI::Xaml::Automation::Provider::IToggleProvider>
{
    using composable = SemanticZoomAutomationPeer;

protected:

    SemanticZoomAutomationPeerT(const Windows::UI::Xaml::Controls::SemanticZoom & owner)
    {
        GetActivationFactory<SemanticZoomAutomationPeer, ISemanticZoomAutomationPeerFactory>().CreateInstanceWithOwner(owner, *this, m_inner);
    }
};

template <typename T, typename ... Interfaces> struct SettingsFlyoutAutomationPeerT :
    overrides<T, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverridesT<T>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2T<T>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3T<T>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides4T<T>, Interfaces ...>,
    requires<T, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer, Windows::UI::Xaml::Automation::Peers::IAutomationPeerProtected, Windows::UI::Xaml::Automation::Peers::IAutomationPeer2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer3, Windows::UI::Xaml::Automation::Peers::IAutomationPeer4, Windows::UI::Xaml::Automation::Peers::IFrameworkElementAutomationPeer, Windows::UI::Xaml::Automation::Peers::ISettingsFlyoutAutomationPeer>
{
    using composable = SettingsFlyoutAutomationPeer;

protected:

    SettingsFlyoutAutomationPeerT(const Windows::UI::Xaml::Controls::SettingsFlyout & owner)
    {
        GetActivationFactory<SettingsFlyoutAutomationPeer, ISettingsFlyoutAutomationPeerFactory>().CreateInstanceWithOwner(owner, *this, m_inner);
    }
};

template <typename T, typename ... Interfaces> struct SliderAutomationPeerT :
    overrides<T, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverridesT<T>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2T<T>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3T<T>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides4T<T>, Interfaces ...>,
    requires<T, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer, Windows::UI::Xaml::Automation::Peers::IAutomationPeerProtected, Windows::UI::Xaml::Automation::Peers::IAutomationPeer2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer3, Windows::UI::Xaml::Automation::Peers::IAutomationPeer4, Windows::UI::Xaml::Automation::Peers::IFrameworkElementAutomationPeer, Windows::UI::Xaml::Automation::Peers::IRangeBaseAutomationPeer, Windows::UI::Xaml::Automation::Provider::IRangeValueProvider, Windows::UI::Xaml::Automation::Peers::ISliderAutomationPeer>
{
    using composable = SliderAutomationPeer;

protected:

    SliderAutomationPeerT(const Windows::UI::Xaml::Controls::Slider & owner)
    {
        GetActivationFactory<SliderAutomationPeer, ISliderAutomationPeerFactory>().CreateInstanceWithOwner(owner, *this, m_inner);
    }
};

template <typename T, typename ... Interfaces> struct TextBlockAutomationPeerT :
    overrides<T, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverridesT<T>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2T<T>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3T<T>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides4T<T>, Interfaces ...>,
    requires<T, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer, Windows::UI::Xaml::Automation::Peers::IAutomationPeerProtected, Windows::UI::Xaml::Automation::Peers::IAutomationPeer2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer3, Windows::UI::Xaml::Automation::Peers::IAutomationPeer4, Windows::UI::Xaml::Automation::Peers::IFrameworkElementAutomationPeer, Windows::UI::Xaml::Automation::Peers::ITextBlockAutomationPeer>
{
    using composable = TextBlockAutomationPeer;

protected:

    TextBlockAutomationPeerT(const Windows::UI::Xaml::Controls::TextBlock & owner)
    {
        GetActivationFactory<TextBlockAutomationPeer, ITextBlockAutomationPeerFactory>().CreateInstanceWithOwner(owner, *this, m_inner);
    }
};

template <typename T, typename ... Interfaces> struct TextBoxAutomationPeerT :
    overrides<T, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverridesT<T>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2T<T>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3T<T>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides4T<T>, Interfaces ...>,
    requires<T, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer, Windows::UI::Xaml::Automation::Peers::IAutomationPeerProtected, Windows::UI::Xaml::Automation::Peers::IAutomationPeer2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer3, Windows::UI::Xaml::Automation::Peers::IAutomationPeer4, Windows::UI::Xaml::Automation::Peers::IFrameworkElementAutomationPeer, Windows::UI::Xaml::Automation::Peers::ITextBoxAutomationPeer>
{
    using composable = TextBoxAutomationPeer;

protected:

    TextBoxAutomationPeerT(const Windows::UI::Xaml::Controls::TextBox & owner)
    {
        GetActivationFactory<TextBoxAutomationPeer, ITextBoxAutomationPeerFactory>().CreateInstanceWithOwner(owner, *this, m_inner);
    }
};

template <typename T, typename ... Interfaces> struct ThumbAutomationPeerT :
    overrides<T, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverridesT<T>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2T<T>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3T<T>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides4T<T>, Interfaces ...>,
    requires<T, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer, Windows::UI::Xaml::Automation::Peers::IAutomationPeerProtected, Windows::UI::Xaml::Automation::Peers::IAutomationPeer2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer3, Windows::UI::Xaml::Automation::Peers::IAutomationPeer4, Windows::UI::Xaml::Automation::Peers::IFrameworkElementAutomationPeer, Windows::UI::Xaml::Automation::Peers::IThumbAutomationPeer>
{
    using composable = ThumbAutomationPeer;

protected:

    ThumbAutomationPeerT(const Windows::UI::Xaml::Controls::Primitives::Thumb & owner)
    {
        GetActivationFactory<ThumbAutomationPeer, IThumbAutomationPeerFactory>().CreateInstanceWithOwner(owner, *this, m_inner);
    }
};

template <typename T, typename ... Interfaces> struct TimePickerAutomationPeerT :
    overrides<T, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverridesT<T>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2T<T>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3T<T>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides4T<T>, Interfaces ...>,
    requires<T, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer, Windows::UI::Xaml::Automation::Peers::IAutomationPeerProtected, Windows::UI::Xaml::Automation::Peers::IAutomationPeer2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer3, Windows::UI::Xaml::Automation::Peers::IAutomationPeer4, Windows::UI::Xaml::Automation::Peers::IFrameworkElementAutomationPeer, Windows::UI::Xaml::Automation::Peers::ITimePickerAutomationPeer>
{
    using composable = TimePickerAutomationPeer;

protected:

    TimePickerAutomationPeerT(const Windows::UI::Xaml::Controls::TimePicker & owner)
    {
        GetActivationFactory<TimePickerAutomationPeer, ITimePickerAutomationPeerFactory>().CreateInstanceWithOwner(owner, *this, m_inner);
    }
};

template <typename T, typename ... Interfaces> struct ToggleButtonAutomationPeerT :
    overrides<T, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverridesT<T>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2T<T>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3T<T>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides4T<T>, Interfaces ...>,
    requires<T, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer, Windows::UI::Xaml::Automation::Peers::IAutomationPeerProtected, Windows::UI::Xaml::Automation::Peers::IAutomationPeer2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer3, Windows::UI::Xaml::Automation::Peers::IAutomationPeer4, Windows::UI::Xaml::Automation::Peers::IFrameworkElementAutomationPeer, Windows::UI::Xaml::Automation::Peers::IButtonBaseAutomationPeer, Windows::UI::Xaml::Automation::Peers::IToggleButtonAutomationPeer, Windows::UI::Xaml::Automation::Provider::IToggleProvider>
{
    using composable = ToggleButtonAutomationPeer;

protected:

    ToggleButtonAutomationPeerT(const Windows::UI::Xaml::Controls::Primitives::ToggleButton & owner)
    {
        GetActivationFactory<ToggleButtonAutomationPeer, IToggleButtonAutomationPeerFactory>().CreateInstanceWithOwner(owner, *this, m_inner);
    }
};

template <typename T, typename ... Interfaces> struct ToggleMenuFlyoutItemAutomationPeerT :
    overrides<T, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverridesT<T>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2T<T>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3T<T>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides4T<T>, Interfaces ...>,
    requires<T, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer, Windows::UI::Xaml::Automation::Peers::IAutomationPeerProtected, Windows::UI::Xaml::Automation::Peers::IAutomationPeer2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer3, Windows::UI::Xaml::Automation::Peers::IAutomationPeer4, Windows::UI::Xaml::Automation::Peers::IFrameworkElementAutomationPeer, Windows::UI::Xaml::Automation::Peers::IToggleMenuFlyoutItemAutomationPeer, Windows::UI::Xaml::Automation::Provider::IToggleProvider>
{
    using composable = ToggleMenuFlyoutItemAutomationPeer;

protected:

    ToggleMenuFlyoutItemAutomationPeerT(const Windows::UI::Xaml::Controls::ToggleMenuFlyoutItem & owner)
    {
        GetActivationFactory<ToggleMenuFlyoutItemAutomationPeer, IToggleMenuFlyoutItemAutomationPeerFactory>().CreateInstanceWithOwner(owner, *this, m_inner);
    }
};

template <typename T, typename ... Interfaces> struct ToggleSwitchAutomationPeerT :
    overrides<T, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverridesT<T>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2T<T>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3T<T>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides4T<T>, Interfaces ...>,
    requires<T, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer, Windows::UI::Xaml::Automation::Peers::IAutomationPeerProtected, Windows::UI::Xaml::Automation::Peers::IAutomationPeer2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer3, Windows::UI::Xaml::Automation::Peers::IAutomationPeer4, Windows::UI::Xaml::Automation::Peers::IFrameworkElementAutomationPeer, Windows::UI::Xaml::Automation::Peers::IToggleSwitchAutomationPeer, Windows::UI::Xaml::Automation::Provider::IToggleProvider>
{
    using composable = ToggleSwitchAutomationPeer;

protected:

    ToggleSwitchAutomationPeerT(const Windows::UI::Xaml::Controls::ToggleSwitch & owner)
    {
        GetActivationFactory<ToggleSwitchAutomationPeer, IToggleSwitchAutomationPeerFactory>().CreateInstanceWithOwner(owner, *this, m_inner);
    }
};

}}}}}

namespace Windows { namespace UI { namespace Xaml { namespace Controls {

template <typename T, typename ... Interfaces> struct AppBarT :
    overrides<T, Windows::UI::Xaml::IUIElementOverridesT<T>, Windows::UI::Xaml::IFrameworkElementOverridesT<T>, Windows::UI::Xaml::IFrameworkElementOverrides2T<T>, Windows::UI::Xaml::Controls::IControlOverridesT<T>, Windows::UI::Xaml::Controls::IContentControlOverridesT<T>, Windows::UI::Xaml::Controls::IAppBarOverridesT<T>, Windows::UI::Xaml::Controls::IAppBarOverrides3T<T>, Interfaces ...>,
    requires<T, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::Controls::IControl, Windows::UI::Xaml::Controls::IControlProtected, Windows::UI::Xaml::Controls::IControl2, Windows::UI::Xaml::Controls::IControl3, Windows::UI::Xaml::Controls::IContentControl, Windows::UI::Xaml::Controls::IContentControl2, Windows::UI::Xaml::Controls::IAppBar, Windows::UI::Xaml::Controls::IAppBar2, Windows::UI::Xaml::Controls::IAppBar3>
{
    using composable = AppBar;

protected:

    AppBarT()
    {
        GetActivationFactory<AppBar, IAppBarFactory>().CreateInstance(*this, m_inner);
    }
};

template <typename T, typename ... Interfaces> struct AppBarButtonT :
    overrides<T, Windows::UI::Xaml::IUIElementOverridesT<T>, Windows::UI::Xaml::IFrameworkElementOverridesT<T>, Windows::UI::Xaml::IFrameworkElementOverrides2T<T>, Windows::UI::Xaml::Controls::IControlOverridesT<T>, Windows::UI::Xaml::Controls::IContentControlOverridesT<T>, Interfaces ...>,
    requires<T, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::Controls::IControl, Windows::UI::Xaml::Controls::IControlProtected, Windows::UI::Xaml::Controls::IControl2, Windows::UI::Xaml::Controls::IControl3, Windows::UI::Xaml::Controls::IContentControl, Windows::UI::Xaml::Controls::IContentControl2, Windows::UI::Xaml::Controls::Primitives::IButtonBase, Windows::UI::Xaml::Controls::IButton, Windows::UI::Xaml::Controls::IButtonWithFlyout, Windows::UI::Xaml::Controls::IAppBarButton, Windows::UI::Xaml::Controls::ICommandBarElement>
{
    using composable = AppBarButton;

protected:

    AppBarButtonT()
    {
        GetActivationFactory<AppBarButton, IAppBarButtonFactory>().CreateInstance(*this, m_inner);
    }
};

template <typename T, typename ... Interfaces> struct AppBarSeparatorT :
    overrides<T, Windows::UI::Xaml::IUIElementOverridesT<T>, Windows::UI::Xaml::IFrameworkElementOverridesT<T>, Windows::UI::Xaml::IFrameworkElementOverrides2T<T>, Windows::UI::Xaml::Controls::IControlOverridesT<T>, Interfaces ...>,
    requires<T, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::Controls::IControl, Windows::UI::Xaml::Controls::IControlProtected, Windows::UI::Xaml::Controls::IControl2, Windows::UI::Xaml::Controls::IControl3, Windows::UI::Xaml::Controls::IAppBarSeparator, Windows::UI::Xaml::Controls::ICommandBarElement>
{
    using composable = AppBarSeparator;

protected:

    AppBarSeparatorT()
    {
        GetActivationFactory<AppBarSeparator, IAppBarSeparatorFactory>().CreateInstance(*this, m_inner);
    }
};

template <typename T, typename ... Interfaces> struct AppBarToggleButtonT :
    overrides<T, Windows::UI::Xaml::IUIElementOverridesT<T>, Windows::UI::Xaml::IFrameworkElementOverridesT<T>, Windows::UI::Xaml::IFrameworkElementOverrides2T<T>, Windows::UI::Xaml::Controls::IControlOverridesT<T>, Windows::UI::Xaml::Controls::IContentControlOverridesT<T>, Windows::UI::Xaml::Controls::Primitives::IToggleButtonOverridesT<T>, Interfaces ...>,
    requires<T, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::Controls::IControl, Windows::UI::Xaml::Controls::IControlProtected, Windows::UI::Xaml::Controls::IControl2, Windows::UI::Xaml::Controls::IControl3, Windows::UI::Xaml::Controls::IContentControl, Windows::UI::Xaml::Controls::IContentControl2, Windows::UI::Xaml::Controls::Primitives::IButtonBase, Windows::UI::Xaml::Controls::Primitives::IToggleButton, Windows::UI::Xaml::Controls::IAppBarToggleButton, Windows::UI::Xaml::Controls::ICommandBarElement>
{
    using composable = AppBarToggleButton;

protected:

    AppBarToggleButtonT()
    {
        GetActivationFactory<AppBarToggleButton, IAppBarToggleButtonFactory>().CreateInstance(*this, m_inner);
    }
};

template <typename T, typename ... Interfaces> struct BitmapIconT :
    overrides<T, Windows::UI::Xaml::IUIElementOverridesT<T>, Windows::UI::Xaml::IFrameworkElementOverridesT<T>, Windows::UI::Xaml::IFrameworkElementOverrides2T<T>, Interfaces ...>,
    requires<T, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::Controls::IIconElement, Windows::UI::Xaml::Controls::IBitmapIcon>
{
    using composable = BitmapIcon;

protected:

    BitmapIconT()
    {
        GetActivationFactory<BitmapIcon, IBitmapIconFactory>().CreateInstance(*this, m_inner);
    }
};

template <typename T, typename ... Interfaces> struct ButtonT :
    overrides<T, Windows::UI::Xaml::IUIElementOverridesT<T>, Windows::UI::Xaml::IFrameworkElementOverridesT<T>, Windows::UI::Xaml::IFrameworkElementOverrides2T<T>, Windows::UI::Xaml::Controls::IControlOverridesT<T>, Windows::UI::Xaml::Controls::IContentControlOverridesT<T>, Interfaces ...>,
    requires<T, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::Controls::IControl, Windows::UI::Xaml::Controls::IControlProtected, Windows::UI::Xaml::Controls::IControl2, Windows::UI::Xaml::Controls::IControl3, Windows::UI::Xaml::Controls::IContentControl, Windows::UI::Xaml::Controls::IContentControl2, Windows::UI::Xaml::Controls::Primitives::IButtonBase, Windows::UI::Xaml::Controls::IButton, Windows::UI::Xaml::Controls::IButtonWithFlyout>
{
    using composable = Button;

protected:

    ButtonT()
    {
        GetActivationFactory<Button, IButtonFactory>().CreateInstance(*this, m_inner);
    }
};

template <typename T, typename ... Interfaces> struct CalendarDatePickerT :
    overrides<T, Windows::UI::Xaml::IUIElementOverridesT<T>, Windows::UI::Xaml::IFrameworkElementOverridesT<T>, Windows::UI::Xaml::IFrameworkElementOverrides2T<T>, Windows::UI::Xaml::Controls::IControlOverridesT<T>, Interfaces ...>,
    requires<T, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::Controls::IControl, Windows::UI::Xaml::Controls::IControlProtected, Windows::UI::Xaml::Controls::IControl2, Windows::UI::Xaml::Controls::IControl3, Windows::UI::Xaml::Controls::ICalendarDatePicker>
{
    using composable = CalendarDatePicker;

protected:

    CalendarDatePickerT()
    {
        GetActivationFactory<CalendarDatePicker, ICalendarDatePickerFactory>().CreateInstance(*this, m_inner);
    }
};

template <typename T, typename ... Interfaces> struct CalendarViewT :
    overrides<T, Windows::UI::Xaml::IUIElementOverridesT<T>, Windows::UI::Xaml::IFrameworkElementOverridesT<T>, Windows::UI::Xaml::IFrameworkElementOverrides2T<T>, Windows::UI::Xaml::Controls::IControlOverridesT<T>, Interfaces ...>,
    requires<T, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::Controls::IControl, Windows::UI::Xaml::Controls::IControlProtected, Windows::UI::Xaml::Controls::IControl2, Windows::UI::Xaml::Controls::IControl3, Windows::UI::Xaml::Controls::ICalendarView>
{
    using composable = CalendarView;

protected:

    CalendarViewT()
    {
        GetActivationFactory<CalendarView, ICalendarViewFactory>().CreateInstance(*this, m_inner);
    }
};

template <typename T, typename ... Interfaces> struct CalendarViewDayItemT :
    overrides<T, Windows::UI::Xaml::IUIElementOverridesT<T>, Windows::UI::Xaml::IFrameworkElementOverridesT<T>, Windows::UI::Xaml::IFrameworkElementOverrides2T<T>, Windows::UI::Xaml::Controls::IControlOverridesT<T>, Interfaces ...>,
    requires<T, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::Controls::IControl, Windows::UI::Xaml::Controls::IControlProtected, Windows::UI::Xaml::Controls::IControl2, Windows::UI::Xaml::Controls::IControl3, Windows::UI::Xaml::Controls::ICalendarViewDayItem>
{
    using composable = CalendarViewDayItem;

protected:

    CalendarViewDayItemT()
    {
        GetActivationFactory<CalendarViewDayItem, ICalendarViewDayItemFactory>().CreateInstance(*this, m_inner);
    }
};

template <typename T, typename ... Interfaces> struct CanvasT :
    overrides<T, Windows::UI::Xaml::IUIElementOverridesT<T>, Windows::UI::Xaml::IFrameworkElementOverridesT<T>, Windows::UI::Xaml::IFrameworkElementOverrides2T<T>, Interfaces ...>,
    requires<T, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::Controls::IPanel, Windows::UI::Xaml::Controls::ICanvas>
{
    using composable = Canvas;

protected:

    CanvasT()
    {
        GetActivationFactory<Canvas, ICanvasFactory>().CreateInstance(*this, m_inner);
    }
};

template <typename T, typename ... Interfaces> struct CheckBoxT :
    overrides<T, Windows::UI::Xaml::IUIElementOverridesT<T>, Windows::UI::Xaml::IFrameworkElementOverridesT<T>, Windows::UI::Xaml::IFrameworkElementOverrides2T<T>, Windows::UI::Xaml::Controls::IControlOverridesT<T>, Windows::UI::Xaml::Controls::IContentControlOverridesT<T>, Windows::UI::Xaml::Controls::Primitives::IToggleButtonOverridesT<T>, Interfaces ...>,
    requires<T, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::Controls::IControl, Windows::UI::Xaml::Controls::IControlProtected, Windows::UI::Xaml::Controls::IControl2, Windows::UI::Xaml::Controls::IControl3, Windows::UI::Xaml::Controls::IContentControl, Windows::UI::Xaml::Controls::IContentControl2, Windows::UI::Xaml::Controls::Primitives::IButtonBase, Windows::UI::Xaml::Controls::Primitives::IToggleButton, Windows::UI::Xaml::Controls::ICheckBox>
{
    using composable = CheckBox;

protected:

    CheckBoxT()
    {
        GetActivationFactory<CheckBox, ICheckBoxFactory>().CreateInstance(*this, m_inner);
    }
};

template <typename T, typename ... Interfaces> struct ComboBoxT :
    overrides<T, Windows::UI::Xaml::IUIElementOverridesT<T>, Windows::UI::Xaml::IFrameworkElementOverridesT<T>, Windows::UI::Xaml::IFrameworkElementOverrides2T<T>, Windows::UI::Xaml::Controls::IControlOverridesT<T>, Windows::UI::Xaml::Controls::IItemsControlOverridesT<T>, Windows::UI::Xaml::Controls::IComboBoxOverridesT<T>, Interfaces ...>,
    requires<T, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::Controls::IControl, Windows::UI::Xaml::Controls::IControlProtected, Windows::UI::Xaml::Controls::IControl2, Windows::UI::Xaml::Controls::IControl3, Windows::UI::Xaml::Controls::IItemsControl, Windows::UI::Xaml::Controls::IItemsControl2, Windows::UI::Xaml::Controls::IItemContainerMapping, Windows::UI::Xaml::Controls::IItemsControl3, Windows::UI::Xaml::Controls::Primitives::ISelector, Windows::UI::Xaml::Controls::IComboBox, Windows::UI::Xaml::Controls::IComboBox2>
{
    using composable = ComboBox;

protected:

    ComboBoxT()
    {
        GetActivationFactory<ComboBox, IComboBoxFactory>().CreateInstance(*this, m_inner);
    }
};

template <typename T, typename ... Interfaces> struct ComboBoxItemT :
    overrides<T, Windows::UI::Xaml::IUIElementOverridesT<T>, Windows::UI::Xaml::IFrameworkElementOverridesT<T>, Windows::UI::Xaml::IFrameworkElementOverrides2T<T>, Windows::UI::Xaml::Controls::IControlOverridesT<T>, Windows::UI::Xaml::Controls::IContentControlOverridesT<T>, Interfaces ...>,
    requires<T, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::Controls::IControl, Windows::UI::Xaml::Controls::IControlProtected, Windows::UI::Xaml::Controls::IControl2, Windows::UI::Xaml::Controls::IControl3, Windows::UI::Xaml::Controls::IContentControl, Windows::UI::Xaml::Controls::IContentControl2, Windows::UI::Xaml::Controls::Primitives::ISelectorItem, Windows::UI::Xaml::Controls::IComboBoxItem>
{
    using composable = ComboBoxItem;

protected:

    ComboBoxItemT()
    {
        GetActivationFactory<ComboBoxItem, IComboBoxItemFactory>().CreateInstance(*this, m_inner);
    }
};

template <typename T, typename ... Interfaces> struct CommandBarT :
    overrides<T, Windows::UI::Xaml::IUIElementOverridesT<T>, Windows::UI::Xaml::IFrameworkElementOverridesT<T>, Windows::UI::Xaml::IFrameworkElementOverrides2T<T>, Windows::UI::Xaml::Controls::IControlOverridesT<T>, Windows::UI::Xaml::Controls::IContentControlOverridesT<T>, Windows::UI::Xaml::Controls::IAppBarOverridesT<T>, Windows::UI::Xaml::Controls::IAppBarOverrides3T<T>, Interfaces ...>,
    requires<T, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::Controls::IControl, Windows::UI::Xaml::Controls::IControlProtected, Windows::UI::Xaml::Controls::IControl2, Windows::UI::Xaml::Controls::IControl3, Windows::UI::Xaml::Controls::IContentControl, Windows::UI::Xaml::Controls::IContentControl2, Windows::UI::Xaml::Controls::IAppBar, Windows::UI::Xaml::Controls::IAppBar2, Windows::UI::Xaml::Controls::IAppBar3, Windows::UI::Xaml::Controls::ICommandBar, Windows::UI::Xaml::Controls::ICommandBar2>
{
    using composable = CommandBar;

protected:

    CommandBarT()
    {
        GetActivationFactory<CommandBar, ICommandBarFactory>().CreateInstance(*this, m_inner);
    }
};

template <typename T, typename ... Interfaces> struct CommandBarOverflowPresenterT :
    overrides<T, Windows::UI::Xaml::IUIElementOverridesT<T>, Windows::UI::Xaml::IFrameworkElementOverridesT<T>, Windows::UI::Xaml::IFrameworkElementOverrides2T<T>, Windows::UI::Xaml::Controls::IControlOverridesT<T>, Windows::UI::Xaml::Controls::IItemsControlOverridesT<T>, Interfaces ...>,
    requires<T, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::Controls::IControl, Windows::UI::Xaml::Controls::IControlProtected, Windows::UI::Xaml::Controls::IControl2, Windows::UI::Xaml::Controls::IControl3, Windows::UI::Xaml::Controls::IItemsControl, Windows::UI::Xaml::Controls::IItemsControl2, Windows::UI::Xaml::Controls::IItemContainerMapping, Windows::UI::Xaml::Controls::IItemsControl3, Windows::UI::Xaml::Controls::ICommandBarOverflowPresenter>
{
    using composable = CommandBarOverflowPresenter;

protected:

    CommandBarOverflowPresenterT()
    {
        GetActivationFactory<CommandBarOverflowPresenter, ICommandBarOverflowPresenterFactory>().CreateInstance(*this, m_inner);
    }
};

template <typename T, typename ... Interfaces> struct ContentControlT :
    overrides<T, Windows::UI::Xaml::IUIElementOverridesT<T>, Windows::UI::Xaml::IFrameworkElementOverridesT<T>, Windows::UI::Xaml::IFrameworkElementOverrides2T<T>, Windows::UI::Xaml::Controls::IControlOverridesT<T>, Windows::UI::Xaml::Controls::IContentControlOverridesT<T>, Interfaces ...>,
    requires<T, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::Controls::IControl, Windows::UI::Xaml::Controls::IControlProtected, Windows::UI::Xaml::Controls::IControl2, Windows::UI::Xaml::Controls::IControl3, Windows::UI::Xaml::Controls::IContentControl, Windows::UI::Xaml::Controls::IContentControl2>
{
    using composable = ContentControl;

protected:

    ContentControlT()
    {
        GetActivationFactory<ContentControl, IContentControlFactory>().CreateInstance(*this, m_inner);
    }
};

template <typename T, typename ... Interfaces> struct ContentDialogT :
    overrides<T, Windows::UI::Xaml::IUIElementOverridesT<T>, Windows::UI::Xaml::IFrameworkElementOverridesT<T>, Windows::UI::Xaml::IFrameworkElementOverrides2T<T>, Windows::UI::Xaml::Controls::IControlOverridesT<T>, Windows::UI::Xaml::Controls::IContentControlOverridesT<T>, Interfaces ...>,
    requires<T, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::Controls::IControl, Windows::UI::Xaml::Controls::IControlProtected, Windows::UI::Xaml::Controls::IControl2, Windows::UI::Xaml::Controls::IControl3, Windows::UI::Xaml::Controls::IContentControl, Windows::UI::Xaml::Controls::IContentControl2, Windows::UI::Xaml::Controls::IContentDialog>
{
    using composable = ContentDialog;

protected:

    ContentDialogT()
    {
        GetActivationFactory<ContentDialog, IContentDialogFactory>().CreateInstance(*this, m_inner);
    }
};

template <typename T, typename ... Interfaces> struct ContentPresenterT :
    overrides<T, Windows::UI::Xaml::IUIElementOverridesT<T>, Windows::UI::Xaml::IFrameworkElementOverridesT<T>, Windows::UI::Xaml::IFrameworkElementOverrides2T<T>, Windows::UI::Xaml::Controls::IContentPresenterOverridesT<T>, Interfaces ...>,
    requires<T, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::Controls::IContentPresenter, Windows::UI::Xaml::Controls::IContentPresenter2, Windows::UI::Xaml::Controls::IContentPresenter3, Windows::UI::Xaml::Controls::IContentPresenter4>
{
    using composable = ContentPresenter;

protected:

    ContentPresenterT()
    {
        GetActivationFactory<ContentPresenter, IContentPresenterFactory>().CreateInstance(*this, m_inner);
    }
};

template <typename T, typename ... Interfaces> struct ControlT :
    overrides<T, Windows::UI::Xaml::IUIElementOverridesT<T>, Windows::UI::Xaml::IFrameworkElementOverridesT<T>, Windows::UI::Xaml::IFrameworkElementOverrides2T<T>, Windows::UI::Xaml::Controls::IControlOverridesT<T>, Interfaces ...>,
    requires<T, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::Controls::IControl, Windows::UI::Xaml::Controls::IControlProtected, Windows::UI::Xaml::Controls::IControl2, Windows::UI::Xaml::Controls::IControl3>
{
    using composable = Control;

protected:

    ControlT()
    {
        GetActivationFactory<Control, IControlFactory>().CreateInstance(*this, m_inner);
    }
};

template <typename T, typename ... Interfaces> struct DataTemplateSelectorT :
    overrides<T, Windows::UI::Xaml::Controls::IDataTemplateSelectorOverridesT<T>, Windows::UI::Xaml::Controls::IDataTemplateSelectorOverrides2T<T>, Interfaces ...>,
    requires<T, Windows::UI::Xaml::Controls::IDataTemplateSelector, Windows::UI::Xaml::Controls::IDataTemplateSelector2>
{
    using composable = DataTemplateSelector;

protected:

    DataTemplateSelectorT()
    {
        GetActivationFactory<DataTemplateSelector, IDataTemplateSelectorFactory>().CreateInstance(*this, m_inner);
    }
};

template <typename T, typename ... Interfaces> struct DatePickerT :
    overrides<T, Windows::UI::Xaml::IUIElementOverridesT<T>, Windows::UI::Xaml::IFrameworkElementOverridesT<T>, Windows::UI::Xaml::IFrameworkElementOverrides2T<T>, Windows::UI::Xaml::Controls::IControlOverridesT<T>, Interfaces ...>,
    requires<T, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::Controls::IControl, Windows::UI::Xaml::Controls::IControlProtected, Windows::UI::Xaml::Controls::IControl2, Windows::UI::Xaml::Controls::IControl3, Windows::UI::Xaml::Controls::IDatePicker>
{
    using composable = DatePicker;

protected:

    DatePickerT()
    {
        GetActivationFactory<DatePicker, IDatePickerFactory>().CreateInstance(*this, m_inner);
    }
};

template <typename T, typename ... Interfaces> struct FlipViewT :
    overrides<T, Windows::UI::Xaml::IUIElementOverridesT<T>, Windows::UI::Xaml::IFrameworkElementOverridesT<T>, Windows::UI::Xaml::IFrameworkElementOverrides2T<T>, Windows::UI::Xaml::Controls::IControlOverridesT<T>, Windows::UI::Xaml::Controls::IItemsControlOverridesT<T>, Interfaces ...>,
    requires<T, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::Controls::IControl, Windows::UI::Xaml::Controls::IControlProtected, Windows::UI::Xaml::Controls::IControl2, Windows::UI::Xaml::Controls::IControl3, Windows::UI::Xaml::Controls::IItemsControl, Windows::UI::Xaml::Controls::IItemsControl2, Windows::UI::Xaml::Controls::IItemContainerMapping, Windows::UI::Xaml::Controls::IItemsControl3, Windows::UI::Xaml::Controls::Primitives::ISelector, Windows::UI::Xaml::Controls::IFlipView, Windows::UI::Xaml::Controls::IFlipView2>
{
    using composable = FlipView;

protected:

    FlipViewT()
    {
        GetActivationFactory<FlipView, IFlipViewFactory>().CreateInstance(*this, m_inner);
    }
};

template <typename T, typename ... Interfaces> struct FlipViewItemT :
    overrides<T, Windows::UI::Xaml::IUIElementOverridesT<T>, Windows::UI::Xaml::IFrameworkElementOverridesT<T>, Windows::UI::Xaml::IFrameworkElementOverrides2T<T>, Windows::UI::Xaml::Controls::IControlOverridesT<T>, Windows::UI::Xaml::Controls::IContentControlOverridesT<T>, Interfaces ...>,
    requires<T, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::Controls::IControl, Windows::UI::Xaml::Controls::IControlProtected, Windows::UI::Xaml::Controls::IControl2, Windows::UI::Xaml::Controls::IControl3, Windows::UI::Xaml::Controls::IContentControl, Windows::UI::Xaml::Controls::IContentControl2, Windows::UI::Xaml::Controls::Primitives::ISelectorItem, Windows::UI::Xaml::Controls::IFlipViewItem>
{
    using composable = FlipViewItem;

protected:

    FlipViewItemT()
    {
        GetActivationFactory<FlipViewItem, IFlipViewItemFactory>().CreateInstance(*this, m_inner);
    }
};

template <typename T, typename ... Interfaces> struct FlyoutT :
    overrides<T, Windows::UI::Xaml::Controls::Primitives::IFlyoutBaseOverridesT<T>, Interfaces ...>,
    requires<T, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Controls::Primitives::IFlyoutBase, Windows::UI::Xaml::Controls::IFlyout>
{
    using composable = Flyout;

protected:

    FlyoutT()
    {
        GetActivationFactory<Flyout, IFlyoutFactory>().CreateInstance(*this, m_inner);
    }
};

template <typename T, typename ... Interfaces> struct FlyoutPresenterT :
    overrides<T, Windows::UI::Xaml::IUIElementOverridesT<T>, Windows::UI::Xaml::IFrameworkElementOverridesT<T>, Windows::UI::Xaml::IFrameworkElementOverrides2T<T>, Windows::UI::Xaml::Controls::IControlOverridesT<T>, Windows::UI::Xaml::Controls::IContentControlOverridesT<T>, Interfaces ...>,
    requires<T, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::Controls::IControl, Windows::UI::Xaml::Controls::IControlProtected, Windows::UI::Xaml::Controls::IControl2, Windows::UI::Xaml::Controls::IControl3, Windows::UI::Xaml::Controls::IContentControl, Windows::UI::Xaml::Controls::IContentControl2, Windows::UI::Xaml::Controls::IFlyoutPresenter>
{
    using composable = FlyoutPresenter;

protected:

    FlyoutPresenterT()
    {
        GetActivationFactory<FlyoutPresenter, IFlyoutPresenterFactory>().CreateInstance(*this, m_inner);
    }
};

template <typename T, typename ... Interfaces> struct FontIconT :
    overrides<T, Windows::UI::Xaml::IUIElementOverridesT<T>, Windows::UI::Xaml::IFrameworkElementOverridesT<T>, Windows::UI::Xaml::IFrameworkElementOverrides2T<T>, Interfaces ...>,
    requires<T, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::Controls::IIconElement, Windows::UI::Xaml::Controls::IFontIcon, Windows::UI::Xaml::Controls::IFontIcon2, Windows::UI::Xaml::Controls::IFontIcon3>
{
    using composable = FontIcon;

protected:

    FontIconT()
    {
        GetActivationFactory<FontIcon, IFontIconFactory>().CreateInstance(*this, m_inner);
    }
};

template <typename T, typename ... Interfaces> struct FrameT :
    overrides<T, Windows::UI::Xaml::IUIElementOverridesT<T>, Windows::UI::Xaml::IFrameworkElementOverridesT<T>, Windows::UI::Xaml::IFrameworkElementOverrides2T<T>, Windows::UI::Xaml::Controls::IControlOverridesT<T>, Windows::UI::Xaml::Controls::IContentControlOverridesT<T>, Interfaces ...>,
    requires<T, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::Controls::IControl, Windows::UI::Xaml::Controls::IControlProtected, Windows::UI::Xaml::Controls::IControl2, Windows::UI::Xaml::Controls::IControl3, Windows::UI::Xaml::Controls::IContentControl, Windows::UI::Xaml::Controls::IContentControl2, Windows::UI::Xaml::Controls::IFrame, Windows::UI::Xaml::Controls::INavigate, Windows::UI::Xaml::Controls::IFrame2, Windows::UI::Xaml::Controls::IFrame3>
{
    using composable = Frame;

protected:

    FrameT()
    {
        GetActivationFactory<Frame, IFrameFactory>().CreateInstance(*this, m_inner);
    }
};

template <typename T, typename ... Interfaces> struct GridT :
    overrides<T, Windows::UI::Xaml::IUIElementOverridesT<T>, Windows::UI::Xaml::IFrameworkElementOverridesT<T>, Windows::UI::Xaml::IFrameworkElementOverrides2T<T>, Interfaces ...>,
    requires<T, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::Controls::IPanel, Windows::UI::Xaml::Controls::IGrid, Windows::UI::Xaml::Controls::IGrid2>
{
    using composable = Grid;

protected:

    GridT()
    {
        GetActivationFactory<Grid, IGridFactory>().CreateInstance(*this, m_inner);
    }
};

template <typename T, typename ... Interfaces> struct GridViewT :
    overrides<T, Windows::UI::Xaml::IUIElementOverridesT<T>, Windows::UI::Xaml::IFrameworkElementOverridesT<T>, Windows::UI::Xaml::IFrameworkElementOverrides2T<T>, Windows::UI::Xaml::Controls::IControlOverridesT<T>, Windows::UI::Xaml::Controls::IItemsControlOverridesT<T>, Interfaces ...>,
    requires<T, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::Controls::IControl, Windows::UI::Xaml::Controls::IControlProtected, Windows::UI::Xaml::Controls::IControl2, Windows::UI::Xaml::Controls::IControl3, Windows::UI::Xaml::Controls::IItemsControl, Windows::UI::Xaml::Controls::IItemsControl2, Windows::UI::Xaml::Controls::IItemContainerMapping, Windows::UI::Xaml::Controls::IItemsControl3, Windows::UI::Xaml::Controls::Primitives::ISelector, Windows::UI::Xaml::Controls::IListViewBase, Windows::UI::Xaml::Controls::ISemanticZoomInformation, Windows::UI::Xaml::Controls::IListViewBase2, Windows::UI::Xaml::Controls::IListViewBase3, Windows::UI::Xaml::Controls::IListViewBase4, Windows::UI::Xaml::Controls::IGridView>
{
    using composable = GridView;

protected:

    GridViewT()
    {
        GetActivationFactory<GridView, IGridViewFactory>().CreateInstance(*this, m_inner);
    }
};

template <typename T, typename ... Interfaces> struct GridViewHeaderItemT :
    overrides<T, Windows::UI::Xaml::IUIElementOverridesT<T>, Windows::UI::Xaml::IFrameworkElementOverridesT<T>, Windows::UI::Xaml::IFrameworkElementOverrides2T<T>, Windows::UI::Xaml::Controls::IControlOverridesT<T>, Windows::UI::Xaml::Controls::IContentControlOverridesT<T>, Interfaces ...>,
    requires<T, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::Controls::IControl, Windows::UI::Xaml::Controls::IControlProtected, Windows::UI::Xaml::Controls::IControl2, Windows::UI::Xaml::Controls::IControl3, Windows::UI::Xaml::Controls::IContentControl, Windows::UI::Xaml::Controls::IContentControl2, Windows::UI::Xaml::Controls::IListViewBaseHeaderItem, Windows::UI::Xaml::Controls::IGridViewHeaderItem>
{
    using composable = GridViewHeaderItem;

protected:

    GridViewHeaderItemT()
    {
        GetActivationFactory<GridViewHeaderItem, IGridViewHeaderItemFactory>().CreateInstance(*this, m_inner);
    }
};

template <typename T, typename ... Interfaces> struct GridViewItemT :
    overrides<T, Windows::UI::Xaml::IUIElementOverridesT<T>, Windows::UI::Xaml::IFrameworkElementOverridesT<T>, Windows::UI::Xaml::IFrameworkElementOverrides2T<T>, Windows::UI::Xaml::Controls::IControlOverridesT<T>, Windows::UI::Xaml::Controls::IContentControlOverridesT<T>, Interfaces ...>,
    requires<T, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::Controls::IControl, Windows::UI::Xaml::Controls::IControlProtected, Windows::UI::Xaml::Controls::IControl2, Windows::UI::Xaml::Controls::IControl3, Windows::UI::Xaml::Controls::IContentControl, Windows::UI::Xaml::Controls::IContentControl2, Windows::UI::Xaml::Controls::Primitives::ISelectorItem, Windows::UI::Xaml::Controls::IGridViewItem>
{
    using composable = GridViewItem;

protected:

    GridViewItemT()
    {
        GetActivationFactory<GridViewItem, IGridViewItemFactory>().CreateInstance(*this, m_inner);
    }
};

template <typename T, typename ... Interfaces> struct GroupItemT :
    overrides<T, Windows::UI::Xaml::IUIElementOverridesT<T>, Windows::UI::Xaml::IFrameworkElementOverridesT<T>, Windows::UI::Xaml::IFrameworkElementOverrides2T<T>, Windows::UI::Xaml::Controls::IControlOverridesT<T>, Windows::UI::Xaml::Controls::IContentControlOverridesT<T>, Interfaces ...>,
    requires<T, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::Controls::IControl, Windows::UI::Xaml::Controls::IControlProtected, Windows::UI::Xaml::Controls::IControl2, Windows::UI::Xaml::Controls::IControl3, Windows::UI::Xaml::Controls::IContentControl, Windows::UI::Xaml::Controls::IContentControl2, Windows::UI::Xaml::Controls::IGroupItem>
{
    using composable = GroupItem;

protected:

    GroupItemT()
    {
        GetActivationFactory<GroupItem, IGroupItemFactory>().CreateInstance(*this, m_inner);
    }
};

template <typename T, typename ... Interfaces> struct GroupStyleT :
    overrides<T, Windows::IInspectable, Interfaces ...>,
    requires<T, Windows::UI::Xaml::Controls::IGroupStyle, Windows::UI::Xaml::Data::INotifyPropertyChanged, Windows::UI::Xaml::Controls::IGroupStyle2>
{
    using composable = GroupStyle;

protected:

    GroupStyleT()
    {
        GetActivationFactory<GroupStyle, IGroupStyleFactory>().CreateInstance(*this, m_inner);
    }
};

template <typename T, typename ... Interfaces> struct GroupStyleSelectorT :
    overrides<T, Windows::UI::Xaml::Controls::IGroupStyleSelectorOverridesT<T>, Interfaces ...>,
    requires<T, Windows::UI::Xaml::Controls::IGroupStyleSelector>
{
    using composable = GroupStyleSelector;

protected:

    GroupStyleSelectorT()
    {
        GetActivationFactory<GroupStyleSelector, IGroupStyleSelectorFactory>().CreateInstance(*this, m_inner);
    }
};

template <typename T, typename ... Interfaces> struct HubT :
    overrides<T, Windows::UI::Xaml::IUIElementOverridesT<T>, Windows::UI::Xaml::IFrameworkElementOverridesT<T>, Windows::UI::Xaml::IFrameworkElementOverrides2T<T>, Windows::UI::Xaml::Controls::IControlOverridesT<T>, Interfaces ...>,
    requires<T, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::Controls::IControl, Windows::UI::Xaml::Controls::IControlProtected, Windows::UI::Xaml::Controls::IControl2, Windows::UI::Xaml::Controls::IControl3, Windows::UI::Xaml::Controls::IHub, Windows::UI::Xaml::Controls::ISemanticZoomInformation>
{
    using composable = Hub;

protected:

    HubT()
    {
        GetActivationFactory<Hub, IHubFactory>().CreateInstance(*this, m_inner);
    }
};

template <typename T, typename ... Interfaces> struct HubSectionT :
    overrides<T, Windows::UI::Xaml::IUIElementOverridesT<T>, Windows::UI::Xaml::IFrameworkElementOverridesT<T>, Windows::UI::Xaml::IFrameworkElementOverrides2T<T>, Windows::UI::Xaml::Controls::IControlOverridesT<T>, Interfaces ...>,
    requires<T, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::Controls::IControl, Windows::UI::Xaml::Controls::IControlProtected, Windows::UI::Xaml::Controls::IControl2, Windows::UI::Xaml::Controls::IControl3, Windows::UI::Xaml::Controls::IHubSection>
{
    using composable = HubSection;

protected:

    HubSectionT()
    {
        GetActivationFactory<HubSection, IHubSectionFactory>().CreateInstance(*this, m_inner);
    }
};

template <typename T, typename ... Interfaces> struct HyperlinkButtonT :
    overrides<T, Windows::UI::Xaml::IUIElementOverridesT<T>, Windows::UI::Xaml::IFrameworkElementOverridesT<T>, Windows::UI::Xaml::IFrameworkElementOverrides2T<T>, Windows::UI::Xaml::Controls::IControlOverridesT<T>, Windows::UI::Xaml::Controls::IContentControlOverridesT<T>, Interfaces ...>,
    requires<T, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::Controls::IControl, Windows::UI::Xaml::Controls::IControlProtected, Windows::UI::Xaml::Controls::IControl2, Windows::UI::Xaml::Controls::IControl3, Windows::UI::Xaml::Controls::IContentControl, Windows::UI::Xaml::Controls::IContentControl2, Windows::UI::Xaml::Controls::Primitives::IButtonBase, Windows::UI::Xaml::Controls::IHyperlinkButton>
{
    using composable = HyperlinkButton;

protected:

    HyperlinkButtonT()
    {
        GetActivationFactory<HyperlinkButton, IHyperlinkButtonFactory>().CreateInstance(*this, m_inner);
    }
};

template <typename T, typename ... Interfaces> struct InkCanvasT :
    overrides<T, Windows::UI::Xaml::IUIElementOverridesT<T>, Windows::UI::Xaml::IFrameworkElementOverridesT<T>, Windows::UI::Xaml::IFrameworkElementOverrides2T<T>, Interfaces ...>,
    requires<T, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::Controls::IInkCanvas>
{
    using composable = InkCanvas;

protected:

    InkCanvasT()
    {
        GetActivationFactory<InkCanvas, IInkCanvasFactory>().CreateInstance(*this, m_inner);
    }
};

template <typename T, typename ... Interfaces> struct ItemsControlT :
    overrides<T, Windows::UI::Xaml::IUIElementOverridesT<T>, Windows::UI::Xaml::IFrameworkElementOverridesT<T>, Windows::UI::Xaml::IFrameworkElementOverrides2T<T>, Windows::UI::Xaml::Controls::IControlOverridesT<T>, Windows::UI::Xaml::Controls::IItemsControlOverridesT<T>, Interfaces ...>,
    requires<T, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::Controls::IControl, Windows::UI::Xaml::Controls::IControlProtected, Windows::UI::Xaml::Controls::IControl2, Windows::UI::Xaml::Controls::IControl3, Windows::UI::Xaml::Controls::IItemsControl, Windows::UI::Xaml::Controls::IItemsControl2, Windows::UI::Xaml::Controls::IItemContainerMapping, Windows::UI::Xaml::Controls::IItemsControl3>
{
    using composable = ItemsControl;

protected:

    ItemsControlT()
    {
        GetActivationFactory<ItemsControl, IItemsControlFactory>().CreateInstance(*this, m_inner);
    }
};

template <typename T, typename ... Interfaces> struct ListBoxT :
    overrides<T, Windows::UI::Xaml::IUIElementOverridesT<T>, Windows::UI::Xaml::IFrameworkElementOverridesT<T>, Windows::UI::Xaml::IFrameworkElementOverrides2T<T>, Windows::UI::Xaml::Controls::IControlOverridesT<T>, Windows::UI::Xaml::Controls::IItemsControlOverridesT<T>, Interfaces ...>,
    requires<T, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::Controls::IControl, Windows::UI::Xaml::Controls::IControlProtected, Windows::UI::Xaml::Controls::IControl2, Windows::UI::Xaml::Controls::IControl3, Windows::UI::Xaml::Controls::IItemsControl, Windows::UI::Xaml::Controls::IItemsControl2, Windows::UI::Xaml::Controls::IItemContainerMapping, Windows::UI::Xaml::Controls::IItemsControl3, Windows::UI::Xaml::Controls::Primitives::ISelector, Windows::UI::Xaml::Controls::IListBox>
{
    using composable = ListBox;

protected:

    ListBoxT()
    {
        GetActivationFactory<ListBox, IListBoxFactory>().CreateInstance(*this, m_inner);
    }
};

template <typename T, typename ... Interfaces> struct ListBoxItemT :
    overrides<T, Windows::UI::Xaml::IUIElementOverridesT<T>, Windows::UI::Xaml::IFrameworkElementOverridesT<T>, Windows::UI::Xaml::IFrameworkElementOverrides2T<T>, Windows::UI::Xaml::Controls::IControlOverridesT<T>, Windows::UI::Xaml::Controls::IContentControlOverridesT<T>, Interfaces ...>,
    requires<T, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::Controls::IControl, Windows::UI::Xaml::Controls::IControlProtected, Windows::UI::Xaml::Controls::IControl2, Windows::UI::Xaml::Controls::IControl3, Windows::UI::Xaml::Controls::IContentControl, Windows::UI::Xaml::Controls::IContentControl2, Windows::UI::Xaml::Controls::Primitives::ISelectorItem, Windows::UI::Xaml::Controls::IListBoxItem>
{
    using composable = ListBoxItem;

protected:

    ListBoxItemT()
    {
        GetActivationFactory<ListBoxItem, IListBoxItemFactory>().CreateInstance(*this, m_inner);
    }
};

template <typename T, typename ... Interfaces> struct ListViewT :
    overrides<T, Windows::UI::Xaml::IUIElementOverridesT<T>, Windows::UI::Xaml::IFrameworkElementOverridesT<T>, Windows::UI::Xaml::IFrameworkElementOverrides2T<T>, Windows::UI::Xaml::Controls::IControlOverridesT<T>, Windows::UI::Xaml::Controls::IItemsControlOverridesT<T>, Interfaces ...>,
    requires<T, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::Controls::IControl, Windows::UI::Xaml::Controls::IControlProtected, Windows::UI::Xaml::Controls::IControl2, Windows::UI::Xaml::Controls::IControl3, Windows::UI::Xaml::Controls::IItemsControl, Windows::UI::Xaml::Controls::IItemsControl2, Windows::UI::Xaml::Controls::IItemContainerMapping, Windows::UI::Xaml::Controls::IItemsControl3, Windows::UI::Xaml::Controls::Primitives::ISelector, Windows::UI::Xaml::Controls::IListViewBase, Windows::UI::Xaml::Controls::ISemanticZoomInformation, Windows::UI::Xaml::Controls::IListViewBase2, Windows::UI::Xaml::Controls::IListViewBase3, Windows::UI::Xaml::Controls::IListViewBase4, Windows::UI::Xaml::Controls::IListView>
{
    using composable = ListView;

protected:

    ListViewT()
    {
        GetActivationFactory<ListView, IListViewFactory>().CreateInstance(*this, m_inner);
    }
};

template <typename T, typename ... Interfaces> struct ListViewBaseT :
    overrides<T, Windows::UI::Xaml::IUIElementOverridesT<T>, Windows::UI::Xaml::IFrameworkElementOverridesT<T>, Windows::UI::Xaml::IFrameworkElementOverrides2T<T>, Windows::UI::Xaml::Controls::IControlOverridesT<T>, Windows::UI::Xaml::Controls::IItemsControlOverridesT<T>, Interfaces ...>,
    requires<T, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::Controls::IControl, Windows::UI::Xaml::Controls::IControlProtected, Windows::UI::Xaml::Controls::IControl2, Windows::UI::Xaml::Controls::IControl3, Windows::UI::Xaml::Controls::IItemsControl, Windows::UI::Xaml::Controls::IItemsControl2, Windows::UI::Xaml::Controls::IItemContainerMapping, Windows::UI::Xaml::Controls::IItemsControl3, Windows::UI::Xaml::Controls::Primitives::ISelector, Windows::UI::Xaml::Controls::IListViewBase, Windows::UI::Xaml::Controls::ISemanticZoomInformation, Windows::UI::Xaml::Controls::IListViewBase2, Windows::UI::Xaml::Controls::IListViewBase3, Windows::UI::Xaml::Controls::IListViewBase4>
{
    using composable = ListViewBase;

protected:

    ListViewBaseT()
    {
        GetActivationFactory<ListViewBase, IListViewBaseFactory>().CreateInstance(*this, m_inner);
    }
};

template <typename T, typename ... Interfaces> struct ListViewHeaderItemT :
    overrides<T, Windows::UI::Xaml::IUIElementOverridesT<T>, Windows::UI::Xaml::IFrameworkElementOverridesT<T>, Windows::UI::Xaml::IFrameworkElementOverrides2T<T>, Windows::UI::Xaml::Controls::IControlOverridesT<T>, Windows::UI::Xaml::Controls::IContentControlOverridesT<T>, Interfaces ...>,
    requires<T, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::Controls::IControl, Windows::UI::Xaml::Controls::IControlProtected, Windows::UI::Xaml::Controls::IControl2, Windows::UI::Xaml::Controls::IControl3, Windows::UI::Xaml::Controls::IContentControl, Windows::UI::Xaml::Controls::IContentControl2, Windows::UI::Xaml::Controls::IListViewBaseHeaderItem, Windows::UI::Xaml::Controls::IListViewHeaderItem>
{
    using composable = ListViewHeaderItem;

protected:

    ListViewHeaderItemT()
    {
        GetActivationFactory<ListViewHeaderItem, IListViewHeaderItemFactory>().CreateInstance(*this, m_inner);
    }
};

template <typename T, typename ... Interfaces> struct ListViewItemT :
    overrides<T, Windows::UI::Xaml::IUIElementOverridesT<T>, Windows::UI::Xaml::IFrameworkElementOverridesT<T>, Windows::UI::Xaml::IFrameworkElementOverrides2T<T>, Windows::UI::Xaml::Controls::IControlOverridesT<T>, Windows::UI::Xaml::Controls::IContentControlOverridesT<T>, Interfaces ...>,
    requires<T, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::Controls::IControl, Windows::UI::Xaml::Controls::IControlProtected, Windows::UI::Xaml::Controls::IControl2, Windows::UI::Xaml::Controls::IControl3, Windows::UI::Xaml::Controls::IContentControl, Windows::UI::Xaml::Controls::IContentControl2, Windows::UI::Xaml::Controls::Primitives::ISelectorItem, Windows::UI::Xaml::Controls::IListViewItem>
{
    using composable = ListViewItem;

protected:

    ListViewItemT()
    {
        GetActivationFactory<ListViewItem, IListViewItemFactory>().CreateInstance(*this, m_inner);
    }
};

template <typename T, typename ... Interfaces> struct MediaTransportControlsT :
    overrides<T, Windows::UI::Xaml::IUIElementOverridesT<T>, Windows::UI::Xaml::IFrameworkElementOverridesT<T>, Windows::UI::Xaml::IFrameworkElementOverrides2T<T>, Windows::UI::Xaml::Controls::IControlOverridesT<T>, Interfaces ...>,
    requires<T, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::Controls::IControl, Windows::UI::Xaml::Controls::IControlProtected, Windows::UI::Xaml::Controls::IControl2, Windows::UI::Xaml::Controls::IControl3, Windows::UI::Xaml::Controls::IMediaTransportControls>
{
    using composable = MediaTransportControls;

protected:

    MediaTransportControlsT()
    {
        GetActivationFactory<MediaTransportControls, IMediaTransportControlsFactory>().CreateInstance(*this, m_inner);
    }
};

template <typename T, typename ... Interfaces> struct MenuFlyoutT :
    overrides<T, Windows::UI::Xaml::Controls::Primitives::IFlyoutBaseOverridesT<T>, Interfaces ...>,
    requires<T, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Controls::Primitives::IFlyoutBase, Windows::UI::Xaml::Controls::IMenuFlyout, Windows::UI::Xaml::Controls::IMenuFlyout2>
{
    using composable = MenuFlyout;

protected:

    MenuFlyoutT()
    {
        GetActivationFactory<MenuFlyout, IMenuFlyoutFactory>().CreateInstance(*this, m_inner);
    }
};

template <typename T, typename ... Interfaces> struct MenuFlyoutItemT :
    overrides<T, Windows::UI::Xaml::IUIElementOverridesT<T>, Windows::UI::Xaml::IFrameworkElementOverridesT<T>, Windows::UI::Xaml::IFrameworkElementOverrides2T<T>, Windows::UI::Xaml::Controls::IControlOverridesT<T>, Interfaces ...>,
    requires<T, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::Controls::IControl, Windows::UI::Xaml::Controls::IControlProtected, Windows::UI::Xaml::Controls::IControl2, Windows::UI::Xaml::Controls::IControl3, Windows::UI::Xaml::Controls::IMenuFlyoutItemBase, Windows::UI::Xaml::Controls::IMenuFlyoutItem>
{
    using composable = MenuFlyoutItem;

protected:

    MenuFlyoutItemT()
    {
        GetActivationFactory<MenuFlyoutItem, IMenuFlyoutItemFactory>().CreateInstance(*this, m_inner);
    }
};

template <typename T, typename ... Interfaces> struct MenuFlyoutPresenterT :
    overrides<T, Windows::UI::Xaml::IUIElementOverridesT<T>, Windows::UI::Xaml::IFrameworkElementOverridesT<T>, Windows::UI::Xaml::IFrameworkElementOverrides2T<T>, Windows::UI::Xaml::Controls::IControlOverridesT<T>, Windows::UI::Xaml::Controls::IItemsControlOverridesT<T>, Interfaces ...>,
    requires<T, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::Controls::IControl, Windows::UI::Xaml::Controls::IControlProtected, Windows::UI::Xaml::Controls::IControl2, Windows::UI::Xaml::Controls::IControl3, Windows::UI::Xaml::Controls::IItemsControl, Windows::UI::Xaml::Controls::IItemsControl2, Windows::UI::Xaml::Controls::IItemContainerMapping, Windows::UI::Xaml::Controls::IItemsControl3, Windows::UI::Xaml::Controls::IMenuFlyoutPresenter, Windows::UI::Xaml::Controls::IMenuFlyoutPresenter2>
{
    using composable = MenuFlyoutPresenter;

protected:

    MenuFlyoutPresenterT()
    {
        GetActivationFactory<MenuFlyoutPresenter, IMenuFlyoutPresenterFactory>().CreateInstance(*this, m_inner);
    }
};

template <typename T, typename ... Interfaces> struct MenuFlyoutSeparatorT :
    overrides<T, Windows::UI::Xaml::IUIElementOverridesT<T>, Windows::UI::Xaml::IFrameworkElementOverridesT<T>, Windows::UI::Xaml::IFrameworkElementOverrides2T<T>, Windows::UI::Xaml::Controls::IControlOverridesT<T>, Interfaces ...>,
    requires<T, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::Controls::IControl, Windows::UI::Xaml::Controls::IControlProtected, Windows::UI::Xaml::Controls::IControl2, Windows::UI::Xaml::Controls::IControl3, Windows::UI::Xaml::Controls::IMenuFlyoutItemBase, Windows::UI::Xaml::Controls::IMenuFlyoutSeparator>
{
    using composable = MenuFlyoutSeparator;

protected:

    MenuFlyoutSeparatorT()
    {
        GetActivationFactory<MenuFlyoutSeparator, IMenuFlyoutSeparatorFactory>().CreateInstance(*this, m_inner);
    }
};

template <typename T, typename ... Interfaces> struct PageT :
    overrides<T, Windows::UI::Xaml::IUIElementOverridesT<T>, Windows::UI::Xaml::IFrameworkElementOverridesT<T>, Windows::UI::Xaml::IFrameworkElementOverrides2T<T>, Windows::UI::Xaml::Controls::IControlOverridesT<T>, Windows::UI::Xaml::Controls::IPageOverridesT<T>, Interfaces ...>,
    requires<T, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::Controls::IControl, Windows::UI::Xaml::Controls::IControlProtected, Windows::UI::Xaml::Controls::IControl2, Windows::UI::Xaml::Controls::IControl3, Windows::UI::Xaml::Controls::IUserControl, Windows::UI::Xaml::Controls::IPage>
{
    using composable = Page;

protected:

    PageT()
    {
        GetActivationFactory<Page, IPageFactory>().CreateInstance(*this, m_inner);
    }
};

template <typename T, typename ... Interfaces> struct PanelT :
    overrides<T, Windows::UI::Xaml::IUIElementOverridesT<T>, Windows::UI::Xaml::IFrameworkElementOverridesT<T>, Windows::UI::Xaml::IFrameworkElementOverrides2T<T>, Interfaces ...>,
    requires<T, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::Controls::IPanel>
{
    using composable = Panel;

protected:

    PanelT()
    {
        GetActivationFactory<Panel, IPanelFactory>().CreateInstance(*this, m_inner);
    }
};

template <typename T, typename ... Interfaces> struct PathIconT :
    overrides<T, Windows::UI::Xaml::IUIElementOverridesT<T>, Windows::UI::Xaml::IFrameworkElementOverridesT<T>, Windows::UI::Xaml::IFrameworkElementOverrides2T<T>, Interfaces ...>,
    requires<T, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::Controls::IIconElement, Windows::UI::Xaml::Controls::IPathIcon>
{
    using composable = PathIcon;

protected:

    PathIconT()
    {
        GetActivationFactory<PathIcon, IPathIconFactory>().CreateInstance(*this, m_inner);
    }
};

template <typename T, typename ... Interfaces> struct PivotT :
    overrides<T, Windows::UI::Xaml::IUIElementOverridesT<T>, Windows::UI::Xaml::IFrameworkElementOverridesT<T>, Windows::UI::Xaml::IFrameworkElementOverrides2T<T>, Windows::UI::Xaml::Controls::IControlOverridesT<T>, Windows::UI::Xaml::Controls::IItemsControlOverridesT<T>, Interfaces ...>,
    requires<T, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::Controls::IControl, Windows::UI::Xaml::Controls::IControlProtected, Windows::UI::Xaml::Controls::IControl2, Windows::UI::Xaml::Controls::IControl3, Windows::UI::Xaml::Controls::IItemsControl, Windows::UI::Xaml::Controls::IItemsControl2, Windows::UI::Xaml::Controls::IItemContainerMapping, Windows::UI::Xaml::Controls::IItemsControl3, Windows::UI::Xaml::Controls::IPivot, Windows::UI::Xaml::Controls::IPivot2>
{
    using composable = Pivot;

protected:

    PivotT()
    {
        GetActivationFactory<Pivot, IPivotFactory>().CreateInstance(*this, m_inner);
    }
};

template <typename T, typename ... Interfaces> struct PivotItemT :
    overrides<T, Windows::UI::Xaml::IUIElementOverridesT<T>, Windows::UI::Xaml::IFrameworkElementOverridesT<T>, Windows::UI::Xaml::IFrameworkElementOverrides2T<T>, Windows::UI::Xaml::Controls::IControlOverridesT<T>, Windows::UI::Xaml::Controls::IContentControlOverridesT<T>, Interfaces ...>,
    requires<T, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::Controls::IControl, Windows::UI::Xaml::Controls::IControlProtected, Windows::UI::Xaml::Controls::IControl2, Windows::UI::Xaml::Controls::IControl3, Windows::UI::Xaml::Controls::IContentControl, Windows::UI::Xaml::Controls::IContentControl2, Windows::UI::Xaml::Controls::IPivotItem>
{
    using composable = PivotItem;

protected:

    PivotItemT()
    {
        GetActivationFactory<PivotItem, IPivotItemFactory>().CreateInstance(*this, m_inner);
    }
};

template <typename T, typename ... Interfaces> struct ProgressBarT :
    overrides<T, Windows::UI::Xaml::IUIElementOverridesT<T>, Windows::UI::Xaml::IFrameworkElementOverridesT<T>, Windows::UI::Xaml::IFrameworkElementOverrides2T<T>, Windows::UI::Xaml::Controls::IControlOverridesT<T>, Windows::UI::Xaml::Controls::Primitives::IRangeBaseOverridesT<T>, Interfaces ...>,
    requires<T, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::Controls::IControl, Windows::UI::Xaml::Controls::IControlProtected, Windows::UI::Xaml::Controls::IControl2, Windows::UI::Xaml::Controls::IControl3, Windows::UI::Xaml::Controls::Primitives::IRangeBase, Windows::UI::Xaml::Controls::IProgressBar>
{
    using composable = ProgressBar;

protected:

    ProgressBarT()
    {
        GetActivationFactory<ProgressBar, IProgressBarFactory>().CreateInstance(*this, m_inner);
    }
};

template <typename T, typename ... Interfaces> struct RadioButtonT :
    overrides<T, Windows::UI::Xaml::IUIElementOverridesT<T>, Windows::UI::Xaml::IFrameworkElementOverridesT<T>, Windows::UI::Xaml::IFrameworkElementOverrides2T<T>, Windows::UI::Xaml::Controls::IControlOverridesT<T>, Windows::UI::Xaml::Controls::IContentControlOverridesT<T>, Windows::UI::Xaml::Controls::Primitives::IToggleButtonOverridesT<T>, Interfaces ...>,
    requires<T, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::Controls::IControl, Windows::UI::Xaml::Controls::IControlProtected, Windows::UI::Xaml::Controls::IControl2, Windows::UI::Xaml::Controls::IControl3, Windows::UI::Xaml::Controls::IContentControl, Windows::UI::Xaml::Controls::IContentControl2, Windows::UI::Xaml::Controls::Primitives::IButtonBase, Windows::UI::Xaml::Controls::Primitives::IToggleButton, Windows::UI::Xaml::Controls::IRadioButton>
{
    using composable = RadioButton;

protected:

    RadioButtonT()
    {
        GetActivationFactory<RadioButton, IRadioButtonFactory>().CreateInstance(*this, m_inner);
    }
};

template <typename T, typename ... Interfaces> struct RelativePanelT :
    overrides<T, Windows::UI::Xaml::IUIElementOverridesT<T>, Windows::UI::Xaml::IFrameworkElementOverridesT<T>, Windows::UI::Xaml::IFrameworkElementOverrides2T<T>, Interfaces ...>,
    requires<T, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::Controls::IPanel, Windows::UI::Xaml::Controls::IRelativePanel>
{
    using composable = RelativePanel;

protected:

    RelativePanelT()
    {
        GetActivationFactory<RelativePanel, IRelativePanelFactory>().CreateInstance(*this, m_inner);
    }
};

template <typename T, typename ... Interfaces> struct RichEditBoxT :
    overrides<T, Windows::UI::Xaml::IUIElementOverridesT<T>, Windows::UI::Xaml::IFrameworkElementOverridesT<T>, Windows::UI::Xaml::IFrameworkElementOverrides2T<T>, Windows::UI::Xaml::Controls::IControlOverridesT<T>, Interfaces ...>,
    requires<T, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::Controls::IControl, Windows::UI::Xaml::Controls::IControlProtected, Windows::UI::Xaml::Controls::IControl2, Windows::UI::Xaml::Controls::IControl3, Windows::UI::Xaml::Controls::IRichEditBox, Windows::UI::Xaml::Controls::IRichEditBox2, Windows::UI::Xaml::Controls::IRichEditBox3, Windows::UI::Xaml::Controls::IRichEditBox4>
{
    using composable = RichEditBox;

protected:

    RichEditBoxT()
    {
        GetActivationFactory<RichEditBox, IRichEditBoxFactory>().CreateInstance(*this, m_inner);
    }
};

template <typename T, typename ... Interfaces> struct SearchBoxT :
    overrides<T, Windows::UI::Xaml::IUIElementOverridesT<T>, Windows::UI::Xaml::IFrameworkElementOverridesT<T>, Windows::UI::Xaml::IFrameworkElementOverrides2T<T>, Windows::UI::Xaml::Controls::IControlOverridesT<T>, Interfaces ...>,
    requires<T, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::Controls::IControl, Windows::UI::Xaml::Controls::IControlProtected, Windows::UI::Xaml::Controls::IControl2, Windows::UI::Xaml::Controls::IControl3, Windows::UI::Xaml::Controls::ISearchBox>
{
    using composable = SearchBox;

protected:

    SearchBoxT()
    {
        GetActivationFactory<SearchBox, ISearchBoxFactory>().CreateInstance(*this, m_inner);
    }
};

template <typename T, typename ... Interfaces> struct SelectionChangedEventArgsT :
    overrides<T, Windows::IInspectable, Interfaces ...>,
    requires<T, Windows::UI::Xaml::IRoutedEventArgs, Windows::UI::Xaml::Controls::ISelectionChangedEventArgs>
{
    using composable = SelectionChangedEventArgs;

protected:

    SelectionChangedEventArgsT(const Windows::Foundation::Collections::IVector<Windows::IInspectable> & removedItems, const Windows::Foundation::Collections::IVector<Windows::IInspectable> & addedItems)
    {
        GetActivationFactory<SelectionChangedEventArgs, ISelectionChangedEventArgsFactory>().CreateInstanceWithRemovedItemsAndAddedItems(removedItems, addedItems, *this, m_inner);
    }
};

template <typename T, typename ... Interfaces> struct SettingsFlyoutT :
    overrides<T, Windows::UI::Xaml::IUIElementOverridesT<T>, Windows::UI::Xaml::IFrameworkElementOverridesT<T>, Windows::UI::Xaml::IFrameworkElementOverrides2T<T>, Windows::UI::Xaml::Controls::IControlOverridesT<T>, Windows::UI::Xaml::Controls::IContentControlOverridesT<T>, Interfaces ...>,
    requires<T, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::Controls::IControl, Windows::UI::Xaml::Controls::IControlProtected, Windows::UI::Xaml::Controls::IControl2, Windows::UI::Xaml::Controls::IControl3, Windows::UI::Xaml::Controls::IContentControl, Windows::UI::Xaml::Controls::IContentControl2, Windows::UI::Xaml::Controls::ISettingsFlyout>
{
    using composable = SettingsFlyout;

protected:

    SettingsFlyoutT()
    {
        GetActivationFactory<SettingsFlyout, ISettingsFlyoutFactory>().CreateInstance(*this, m_inner);
    }
};

template <typename T, typename ... Interfaces> struct SliderT :
    overrides<T, Windows::UI::Xaml::IUIElementOverridesT<T>, Windows::UI::Xaml::IFrameworkElementOverridesT<T>, Windows::UI::Xaml::IFrameworkElementOverrides2T<T>, Windows::UI::Xaml::Controls::IControlOverridesT<T>, Windows::UI::Xaml::Controls::Primitives::IRangeBaseOverridesT<T>, Interfaces ...>,
    requires<T, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::Controls::IControl, Windows::UI::Xaml::Controls::IControlProtected, Windows::UI::Xaml::Controls::IControl2, Windows::UI::Xaml::Controls::IControl3, Windows::UI::Xaml::Controls::Primitives::IRangeBase, Windows::UI::Xaml::Controls::ISlider, Windows::UI::Xaml::Controls::ISlider2>
{
    using composable = Slider;

protected:

    SliderT()
    {
        GetActivationFactory<Slider, ISliderFactory>().CreateInstance(*this, m_inner);
    }
};

template <typename T, typename ... Interfaces> struct SplitViewT :
    overrides<T, Windows::UI::Xaml::IUIElementOverridesT<T>, Windows::UI::Xaml::IFrameworkElementOverridesT<T>, Windows::UI::Xaml::IFrameworkElementOverrides2T<T>, Windows::UI::Xaml::Controls::IControlOverridesT<T>, Interfaces ...>,
    requires<T, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::Controls::IControl, Windows::UI::Xaml::Controls::IControlProtected, Windows::UI::Xaml::Controls::IControl2, Windows::UI::Xaml::Controls::IControl3, Windows::UI::Xaml::Controls::ISplitView>
{
    using composable = SplitView;

protected:

    SplitViewT()
    {
        GetActivationFactory<SplitView, ISplitViewFactory>().CreateInstance(*this, m_inner);
    }
};

template <typename T, typename ... Interfaces> struct StackPanelT :
    overrides<T, Windows::UI::Xaml::IUIElementOverridesT<T>, Windows::UI::Xaml::IFrameworkElementOverridesT<T>, Windows::UI::Xaml::IFrameworkElementOverrides2T<T>, Interfaces ...>,
    requires<T, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::Controls::IPanel, Windows::UI::Xaml::Controls::IStackPanel, Windows::UI::Xaml::Controls::Primitives::IScrollSnapPointsInfo, Windows::UI::Xaml::Controls::IStackPanel2>
{
    using composable = StackPanel;

protected:

    StackPanelT()
    {
        GetActivationFactory<StackPanel, IStackPanelFactory>().CreateInstance(*this, m_inner);
    }
};

template <typename T, typename ... Interfaces> struct StyleSelectorT :
    overrides<T, Windows::UI::Xaml::Controls::IStyleSelectorOverridesT<T>, Interfaces ...>,
    requires<T, Windows::UI::Xaml::Controls::IStyleSelector>
{
    using composable = StyleSelector;

protected:

    StyleSelectorT()
    {
        GetActivationFactory<StyleSelector, IStyleSelectorFactory>().CreateInstance(*this, m_inner);
    }
};

template <typename T, typename ... Interfaces> struct SwapChainBackgroundPanelT :
    overrides<T, Windows::UI::Xaml::IUIElementOverridesT<T>, Windows::UI::Xaml::IFrameworkElementOverridesT<T>, Windows::UI::Xaml::IFrameworkElementOverrides2T<T>, Interfaces ...>,
    requires<T, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::Controls::IPanel, Windows::UI::Xaml::Controls::IGrid, Windows::UI::Xaml::Controls::IGrid2, Windows::UI::Xaml::Controls::ISwapChainBackgroundPanel, Windows::UI::Xaml::Controls::ISwapChainBackgroundPanel2>
{
    using composable = SwapChainBackgroundPanel;

protected:

    SwapChainBackgroundPanelT()
    {
        GetActivationFactory<SwapChainBackgroundPanel, ISwapChainBackgroundPanelFactory>().CreateInstance(*this, m_inner);
    }
};

template <typename T, typename ... Interfaces> struct SwapChainPanelT :
    overrides<T, Windows::UI::Xaml::IUIElementOverridesT<T>, Windows::UI::Xaml::IFrameworkElementOverridesT<T>, Windows::UI::Xaml::IFrameworkElementOverrides2T<T>, Interfaces ...>,
    requires<T, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::Controls::IPanel, Windows::UI::Xaml::Controls::IGrid, Windows::UI::Xaml::Controls::IGrid2, Windows::UI::Xaml::Controls::ISwapChainPanel>
{
    using composable = SwapChainPanel;

protected:

    SwapChainPanelT()
    {
        GetActivationFactory<SwapChainPanel, ISwapChainPanelFactory>().CreateInstance(*this, m_inner);
    }
};

template <typename T, typename ... Interfaces> struct TextBoxT :
    overrides<T, Windows::UI::Xaml::IUIElementOverridesT<T>, Windows::UI::Xaml::IFrameworkElementOverridesT<T>, Windows::UI::Xaml::IFrameworkElementOverrides2T<T>, Windows::UI::Xaml::Controls::IControlOverridesT<T>, Interfaces ...>,
    requires<T, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::Controls::IControl, Windows::UI::Xaml::Controls::IControlProtected, Windows::UI::Xaml::Controls::IControl2, Windows::UI::Xaml::Controls::IControl3, Windows::UI::Xaml::Controls::ITextBox, Windows::UI::Xaml::Controls::ITextBox2, Windows::UI::Xaml::Controls::ITextBox3, Windows::UI::Xaml::Controls::ITextBox4>
{
    using composable = TextBox;

protected:

    TextBoxT()
    {
        GetActivationFactory<TextBox, ITextBoxFactory>().CreateInstance(*this, m_inner);
    }
};

template <typename T, typename ... Interfaces> struct TimePickerT :
    overrides<T, Windows::UI::Xaml::IUIElementOverridesT<T>, Windows::UI::Xaml::IFrameworkElementOverridesT<T>, Windows::UI::Xaml::IFrameworkElementOverrides2T<T>, Windows::UI::Xaml::Controls::IControlOverridesT<T>, Interfaces ...>,
    requires<T, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::Controls::IControl, Windows::UI::Xaml::Controls::IControlProtected, Windows::UI::Xaml::Controls::IControl2, Windows::UI::Xaml::Controls::IControl3, Windows::UI::Xaml::Controls::ITimePicker>
{
    using composable = TimePicker;

protected:

    TimePickerT()
    {
        GetActivationFactory<TimePicker, ITimePickerFactory>().CreateInstance(*this, m_inner);
    }
};

template <typename T, typename ... Interfaces> struct ToggleMenuFlyoutItemT :
    overrides<T, Windows::UI::Xaml::IUIElementOverridesT<T>, Windows::UI::Xaml::IFrameworkElementOverridesT<T>, Windows::UI::Xaml::IFrameworkElementOverrides2T<T>, Windows::UI::Xaml::Controls::IControlOverridesT<T>, Interfaces ...>,
    requires<T, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::Controls::IControl, Windows::UI::Xaml::Controls::IControlProtected, Windows::UI::Xaml::Controls::IControl2, Windows::UI::Xaml::Controls::IControl3, Windows::UI::Xaml::Controls::IMenuFlyoutItemBase, Windows::UI::Xaml::Controls::IMenuFlyoutItem, Windows::UI::Xaml::Controls::IToggleMenuFlyoutItem>
{
    using composable = ToggleMenuFlyoutItem;

protected:

    ToggleMenuFlyoutItemT()
    {
        GetActivationFactory<ToggleMenuFlyoutItem, IToggleMenuFlyoutItemFactory>().CreateInstance(*this, m_inner);
    }
};

template <typename T, typename ... Interfaces> struct ToolTipT :
    overrides<T, Windows::UI::Xaml::IUIElementOverridesT<T>, Windows::UI::Xaml::IFrameworkElementOverridesT<T>, Windows::UI::Xaml::IFrameworkElementOverrides2T<T>, Windows::UI::Xaml::Controls::IControlOverridesT<T>, Windows::UI::Xaml::Controls::IContentControlOverridesT<T>, Interfaces ...>,
    requires<T, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::Controls::IControl, Windows::UI::Xaml::Controls::IControlProtected, Windows::UI::Xaml::Controls::IControl2, Windows::UI::Xaml::Controls::IControl3, Windows::UI::Xaml::Controls::IContentControl, Windows::UI::Xaml::Controls::IContentControl2, Windows::UI::Xaml::Controls::IToolTip>
{
    using composable = ToolTip;

protected:

    ToolTipT()
    {
        GetActivationFactory<ToolTip, IToolTipFactory>().CreateInstance(*this, m_inner);
    }
};

template <typename T, typename ... Interfaces> struct UserControlT :
    overrides<T, Windows::UI::Xaml::IUIElementOverridesT<T>, Windows::UI::Xaml::IFrameworkElementOverridesT<T>, Windows::UI::Xaml::IFrameworkElementOverrides2T<T>, Windows::UI::Xaml::Controls::IControlOverridesT<T>, Interfaces ...>,
    requires<T, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::Controls::IControl, Windows::UI::Xaml::Controls::IControlProtected, Windows::UI::Xaml::Controls::IControl2, Windows::UI::Xaml::Controls::IControl3, Windows::UI::Xaml::Controls::IUserControl>
{
    using composable = UserControl;

protected:

    UserControlT()
    {
        GetActivationFactory<UserControl, IUserControlFactory>().CreateInstance(*this, m_inner);
    }
};

}}}}

namespace Windows { namespace UI { namespace Xaml { namespace Controls { namespace Maps {

template <typename T, typename ... Interfaces> struct CustomMapTileDataSourceT :
    overrides<T, Windows::IInspectable, Interfaces ...>,
    requires<T, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Controls::Maps::IMapTileDataSource, Windows::UI::Xaml::Controls::Maps::ICustomMapTileDataSource>
{
    using composable = CustomMapTileDataSource;

protected:

    CustomMapTileDataSourceT()
    {
        GetActivationFactory<CustomMapTileDataSource, ICustomMapTileDataSourceFactory>().CreateInstance(*this, m_inner);
    }
};

template <typename T, typename ... Interfaces> struct HttpMapTileDataSourceT :
    overrides<T, Windows::IInspectable, Interfaces ...>,
    requires<T, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Controls::Maps::IMapTileDataSource, Windows::UI::Xaml::Controls::Maps::IHttpMapTileDataSource>
{
    using composable = HttpMapTileDataSource;

protected:

    HttpMapTileDataSourceT()
    {
        GetActivationFactory<HttpMapTileDataSource, IHttpMapTileDataSourceFactory>().CreateInstance(*this, m_inner);
    }

    HttpMapTileDataSourceT(hstring_ref uriFormatString)
    {
        GetActivationFactory<HttpMapTileDataSource, IHttpMapTileDataSourceFactory>().CreateInstanceWithUriFormatString(uriFormatString, *this, m_inner);
    }
};

template <typename T, typename ... Interfaces> struct LocalMapTileDataSourceT :
    overrides<T, Windows::IInspectable, Interfaces ...>,
    requires<T, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Controls::Maps::IMapTileDataSource, Windows::UI::Xaml::Controls::Maps::ILocalMapTileDataSource>
{
    using composable = LocalMapTileDataSource;

protected:

    LocalMapTileDataSourceT()
    {
        GetActivationFactory<LocalMapTileDataSource, ILocalMapTileDataSourceFactory>().CreateInstance(*this, m_inner);
    }

    LocalMapTileDataSourceT(hstring_ref uriFormatString)
    {
        GetActivationFactory<LocalMapTileDataSource, ILocalMapTileDataSourceFactory>().CreateInstanceWithUriFormatString(uriFormatString, *this, m_inner);
    }
};

template <typename T, typename ... Interfaces> struct MapCustomExperienceT :
    overrides<T, Windows::IInspectable, Interfaces ...>,
    requires<T, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Controls::Maps::IMapCustomExperience>
{
    using composable = MapCustomExperience;

protected:

    MapCustomExperienceT()
    {
        GetActivationFactory<MapCustomExperience, IMapCustomExperienceFactory>().CreateInstance(*this, m_inner);
    }
};

template <typename T, typename ... Interfaces> struct MapElementT :
    overrides<T, Windows::IInspectable, Interfaces ...>,
    requires<T, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Controls::Maps::IMapElement, Windows::UI::Xaml::Controls::Maps::IMapElement2>
{
    using composable = MapElement;

protected:

    MapElementT()
    {
        GetActivationFactory<MapElement, IMapElementFactory>().CreateInstance(*this, m_inner);
    }
};

template <typename T, typename ... Interfaces> struct MapRouteViewT :
    overrides<T, Windows::IInspectable, Interfaces ...>,
    requires<T, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Controls::Maps::IMapRouteView>
{
    using composable = MapRouteView;

protected:

    MapRouteViewT(const Windows::Services::Maps::MapRoute & route)
    {
        GetActivationFactory<MapRouteView, IMapRouteViewFactory>().CreateInstanceWithMapRoute(route, *this, m_inner);
    }
};

template <typename T, typename ... Interfaces> struct MapTileDataSourceT :
    overrides<T, Windows::IInspectable, Interfaces ...>,
    requires<T, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Controls::Maps::IMapTileDataSource>
{
    using composable = MapTileDataSource;

protected:

    MapTileDataSourceT()
    {
        GetActivationFactory<MapTileDataSource, IMapTileDataSourceFactory>().CreateInstance(*this, m_inner);
    }
};

template <typename T, typename ... Interfaces> struct MapTileSourceT :
    overrides<T, Windows::IInspectable, Interfaces ...>,
    requires<T, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Controls::Maps::IMapTileSource>
{
    using composable = MapTileSource;

protected:

    MapTileSourceT()
    {
        GetActivationFactory<MapTileSource, IMapTileSourceFactory>().CreateInstance(*this, m_inner);
    }

    MapTileSourceT(const Windows::UI::Xaml::Controls::Maps::MapTileDataSource & dataSource)
    {
        GetActivationFactory<MapTileSource, IMapTileSourceFactory>().CreateInstanceWithDataSource(dataSource, *this, m_inner);
    }

    MapTileSourceT(const Windows::UI::Xaml::Controls::Maps::MapTileDataSource & dataSource, const Windows::UI::Xaml::Controls::Maps::MapZoomLevelRange & zoomLevelRange)
    {
        GetActivationFactory<MapTileSource, IMapTileSourceFactory>().CreateInstanceWithDataSourceAndZoomRange(dataSource, zoomLevelRange, *this, m_inner);
    }

    MapTileSourceT(const Windows::UI::Xaml::Controls::Maps::MapTileDataSource & dataSource, const Windows::UI::Xaml::Controls::Maps::MapZoomLevelRange & zoomLevelRange, const Windows::Devices::Geolocation::GeoboundingBox & bounds)
    {
        GetActivationFactory<MapTileSource, IMapTileSourceFactory>().CreateInstanceWithDataSourceZoomRangeAndBounds(dataSource, zoomLevelRange, bounds, *this, m_inner);
    }

    MapTileSourceT(const Windows::UI::Xaml::Controls::Maps::MapTileDataSource & dataSource, const Windows::UI::Xaml::Controls::Maps::MapZoomLevelRange & zoomLevelRange, const Windows::Devices::Geolocation::GeoboundingBox & bounds, int32_t tileSizeInPixels)
    {
        GetActivationFactory<MapTileSource, IMapTileSourceFactory>().CreateInstanceWithDataSourceZoomRangeBoundsAndTileSize(dataSource, zoomLevelRange, bounds, tileSizeInPixels, *this, m_inner);
    }
};

}}}}}

namespace Windows { namespace UI { namespace Xaml { namespace Controls { namespace Primitives {

template <typename T, typename ... Interfaces> struct ButtonBaseT :
    overrides<T, Windows::UI::Xaml::IUIElementOverridesT<T>, Windows::UI::Xaml::IFrameworkElementOverridesT<T>, Windows::UI::Xaml::IFrameworkElementOverrides2T<T>, Windows::UI::Xaml::Controls::IControlOverridesT<T>, Windows::UI::Xaml::Controls::IContentControlOverridesT<T>, Interfaces ...>,
    requires<T, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::Controls::IControl, Windows::UI::Xaml::Controls::IControlProtected, Windows::UI::Xaml::Controls::IControl2, Windows::UI::Xaml::Controls::IControl3, Windows::UI::Xaml::Controls::IContentControl, Windows::UI::Xaml::Controls::IContentControl2, Windows::UI::Xaml::Controls::Primitives::IButtonBase>
{
    using composable = ButtonBase;

protected:

    ButtonBaseT()
    {
        GetActivationFactory<ButtonBase, IButtonBaseFactory>().CreateInstance(*this, m_inner);
    }
};

template <typename T, typename ... Interfaces> struct CarouselPanelT :
    overrides<T, Windows::UI::Xaml::IUIElementOverridesT<T>, Windows::UI::Xaml::IFrameworkElementOverridesT<T>, Windows::UI::Xaml::IFrameworkElementOverrides2T<T>, Windows::UI::Xaml::Controls::IVirtualizingPanelOverridesT<T>, Interfaces ...>,
    requires<T, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::Controls::IPanel, Windows::UI::Xaml::Controls::IVirtualizingPanel, Windows::UI::Xaml::Controls::IVirtualizingPanelProtected, Windows::UI::Xaml::Controls::Primitives::ICarouselPanel, Windows::UI::Xaml::Controls::Primitives::IScrollSnapPointsInfo>
{
    using composable = CarouselPanel;

protected:

    CarouselPanelT()
    {
        GetActivationFactory<CarouselPanel, ICarouselPanelFactory>().CreateInstance(*this, m_inner);
    }
};

template <typename T, typename ... Interfaces> struct DragCompletedEventArgsT :
    overrides<T, Windows::IInspectable, Interfaces ...>,
    requires<T, Windows::UI::Xaml::IRoutedEventArgs, Windows::UI::Xaml::Controls::Primitives::IDragCompletedEventArgs>
{
    using composable = DragCompletedEventArgs;

protected:

    DragCompletedEventArgsT(double horizontalChange, double verticalChange, bool canceled)
    {
        GetActivationFactory<DragCompletedEventArgs, IDragCompletedEventArgsFactory>().CreateInstanceWithHorizontalChangeVerticalChangeAndCanceled(horizontalChange, verticalChange, canceled, *this, m_inner);
    }
};

template <typename T, typename ... Interfaces> struct DragDeltaEventArgsT :
    overrides<T, Windows::IInspectable, Interfaces ...>,
    requires<T, Windows::UI::Xaml::IRoutedEventArgs, Windows::UI::Xaml::Controls::Primitives::IDragDeltaEventArgs>
{
    using composable = DragDeltaEventArgs;

protected:

    DragDeltaEventArgsT(double horizontalChange, double verticalChange)
    {
        GetActivationFactory<DragDeltaEventArgs, IDragDeltaEventArgsFactory>().CreateInstanceWithHorizontalChangeAndVerticalChange(horizontalChange, verticalChange, *this, m_inner);
    }
};

template <typename T, typename ... Interfaces> struct DragStartedEventArgsT :
    overrides<T, Windows::IInspectable, Interfaces ...>,
    requires<T, Windows::UI::Xaml::IRoutedEventArgs, Windows::UI::Xaml::Controls::Primitives::IDragStartedEventArgs>
{
    using composable = DragStartedEventArgs;

protected:

    DragStartedEventArgsT(double horizontalOffset, double verticalOffset)
    {
        GetActivationFactory<DragStartedEventArgs, IDragStartedEventArgsFactory>().CreateInstanceWithHorizontalOffsetAndVerticalOffset(horizontalOffset, verticalOffset, *this, m_inner);
    }
};

template <typename T, typename ... Interfaces> struct FlyoutBaseT :
    overrides<T, Windows::UI::Xaml::Controls::Primitives::IFlyoutBaseOverridesT<T>, Interfaces ...>,
    requires<T, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Controls::Primitives::IFlyoutBase>
{
    using composable = FlyoutBase;

protected:

    FlyoutBaseT()
    {
        GetActivationFactory<FlyoutBase, IFlyoutBaseFactory>().CreateInstance(*this, m_inner);
    }
};

template <typename T, typename ... Interfaces> struct GridViewItemPresenterT :
    overrides<T, Windows::UI::Xaml::IUIElementOverridesT<T>, Windows::UI::Xaml::IFrameworkElementOverridesT<T>, Windows::UI::Xaml::IFrameworkElementOverrides2T<T>, Windows::UI::Xaml::Controls::IContentPresenterOverridesT<T>, Interfaces ...>,
    requires<T, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::Controls::IContentPresenter, Windows::UI::Xaml::Controls::IContentPresenter2, Windows::UI::Xaml::Controls::IContentPresenter3, Windows::UI::Xaml::Controls::IContentPresenter4, Windows::UI::Xaml::Controls::Primitives::IGridViewItemPresenter>
{
    using composable = GridViewItemPresenter;

protected:

    GridViewItemPresenterT()
    {
        GetActivationFactory<GridViewItemPresenter, IGridViewItemPresenterFactory>().CreateInstance(*this, m_inner);
    }
};

template <typename T, typename ... Interfaces> struct ListViewItemPresenterT :
    overrides<T, Windows::UI::Xaml::IUIElementOverridesT<T>, Windows::UI::Xaml::IFrameworkElementOverridesT<T>, Windows::UI::Xaml::IFrameworkElementOverrides2T<T>, Windows::UI::Xaml::Controls::IContentPresenterOverridesT<T>, Interfaces ...>,
    requires<T, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::Controls::IContentPresenter, Windows::UI::Xaml::Controls::IContentPresenter2, Windows::UI::Xaml::Controls::IContentPresenter3, Windows::UI::Xaml::Controls::IContentPresenter4, Windows::UI::Xaml::Controls::Primitives::IListViewItemPresenter, Windows::UI::Xaml::Controls::Primitives::IListViewItemPresenter2>
{
    using composable = ListViewItemPresenter;

protected:

    ListViewItemPresenterT()
    {
        GetActivationFactory<ListViewItemPresenter, IListViewItemPresenterFactory>().CreateInstance(*this, m_inner);
    }
};

template <typename T, typename ... Interfaces> struct PickerFlyoutBaseT :
    overrides<T, Windows::UI::Xaml::Controls::Primitives::IFlyoutBaseOverridesT<T>, Windows::UI::Xaml::Controls::Primitives::IPickerFlyoutBaseOverridesT<T>, Interfaces ...>,
    requires<T, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Controls::Primitives::IFlyoutBase, Windows::UI::Xaml::Controls::Primitives::IPickerFlyoutBase>
{
    using composable = PickerFlyoutBase;

protected:

    PickerFlyoutBaseT()
    {
        GetActivationFactory<PickerFlyoutBase, IPickerFlyoutBaseFactory>().CreateInstance(*this, m_inner);
    }
};

template <typename T, typename ... Interfaces> struct PivotHeaderItemT :
    overrides<T, Windows::UI::Xaml::IUIElementOverridesT<T>, Windows::UI::Xaml::IFrameworkElementOverridesT<T>, Windows::UI::Xaml::IFrameworkElementOverrides2T<T>, Windows::UI::Xaml::Controls::IControlOverridesT<T>, Windows::UI::Xaml::Controls::IContentControlOverridesT<T>, Interfaces ...>,
    requires<T, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::Controls::IControl, Windows::UI::Xaml::Controls::IControlProtected, Windows::UI::Xaml::Controls::IControl2, Windows::UI::Xaml::Controls::IControl3, Windows::UI::Xaml::Controls::IContentControl, Windows::UI::Xaml::Controls::IContentControl2, Windows::UI::Xaml::Controls::Primitives::IPivotHeaderItem>
{
    using composable = PivotHeaderItem;

protected:

    PivotHeaderItemT()
    {
        GetActivationFactory<PivotHeaderItem, IPivotHeaderItemFactory>().CreateInstance(*this, m_inner);
    }
};

template <typename T, typename ... Interfaces> struct RangeBaseT :
    overrides<T, Windows::UI::Xaml::IUIElementOverridesT<T>, Windows::UI::Xaml::IFrameworkElementOverridesT<T>, Windows::UI::Xaml::IFrameworkElementOverrides2T<T>, Windows::UI::Xaml::Controls::IControlOverridesT<T>, Windows::UI::Xaml::Controls::Primitives::IRangeBaseOverridesT<T>, Interfaces ...>,
    requires<T, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::Controls::IControl, Windows::UI::Xaml::Controls::IControlProtected, Windows::UI::Xaml::Controls::IControl2, Windows::UI::Xaml::Controls::IControl3, Windows::UI::Xaml::Controls::Primitives::IRangeBase>
{
    using composable = RangeBase;

protected:

    RangeBaseT()
    {
        GetActivationFactory<RangeBase, IRangeBaseFactory>().CreateInstance(*this, m_inner);
    }
};

template <typename T, typename ... Interfaces> struct SelectorItemT :
    overrides<T, Windows::UI::Xaml::IUIElementOverridesT<T>, Windows::UI::Xaml::IFrameworkElementOverridesT<T>, Windows::UI::Xaml::IFrameworkElementOverrides2T<T>, Windows::UI::Xaml::Controls::IControlOverridesT<T>, Windows::UI::Xaml::Controls::IContentControlOverridesT<T>, Interfaces ...>,
    requires<T, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::Controls::IControl, Windows::UI::Xaml::Controls::IControlProtected, Windows::UI::Xaml::Controls::IControl2, Windows::UI::Xaml::Controls::IControl3, Windows::UI::Xaml::Controls::IContentControl, Windows::UI::Xaml::Controls::IContentControl2, Windows::UI::Xaml::Controls::Primitives::ISelectorItem>
{
    using composable = SelectorItem;

protected:

    SelectorItemT()
    {
        GetActivationFactory<SelectorItem, ISelectorItemFactory>().CreateInstance(*this, m_inner);
    }
};

template <typename T, typename ... Interfaces> struct ToggleButtonT :
    overrides<T, Windows::UI::Xaml::IUIElementOverridesT<T>, Windows::UI::Xaml::IFrameworkElementOverridesT<T>, Windows::UI::Xaml::IFrameworkElementOverrides2T<T>, Windows::UI::Xaml::Controls::IControlOverridesT<T>, Windows::UI::Xaml::Controls::IContentControlOverridesT<T>, Windows::UI::Xaml::Controls::Primitives::IToggleButtonOverridesT<T>, Interfaces ...>,
    requires<T, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::Controls::IControl, Windows::UI::Xaml::Controls::IControlProtected, Windows::UI::Xaml::Controls::IControl2, Windows::UI::Xaml::Controls::IControl3, Windows::UI::Xaml::Controls::IContentControl, Windows::UI::Xaml::Controls::IContentControl2, Windows::UI::Xaml::Controls::Primitives::IButtonBase, Windows::UI::Xaml::Controls::Primitives::IToggleButton>
{
    using composable = ToggleButton;

protected:

    ToggleButtonT()
    {
        GetActivationFactory<ToggleButton, IToggleButtonFactory>().CreateInstance(*this, m_inner);
    }
};

}}}}}

namespace Windows { namespace UI { namespace Xaml { namespace Data {

template <typename T, typename ... Interfaces> struct BindingT :
    overrides<T, Windows::IInspectable, Interfaces ...>,
    requires<T, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Data::IBindingBase, Windows::UI::Xaml::Data::IBinding, Windows::UI::Xaml::Data::IBinding2>
{
    using composable = Binding;

protected:

    BindingT()
    {
        GetActivationFactory<Binding, IBindingFactory>().CreateInstance(*this, m_inner);
    }
};

template <typename T, typename ... Interfaces> struct BindingBaseT :
    overrides<T, Windows::IInspectable, Interfaces ...>,
    requires<T, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Data::IBindingBase>
{
    using composable = BindingBase;

protected:

    BindingBaseT()
    {
        GetActivationFactory<BindingBase, IBindingBaseFactory>().CreateInstance(*this, m_inner);
    }
};

template <typename T, typename ... Interfaces> struct CurrentChangingEventArgsT :
    overrides<T, Windows::IInspectable, Interfaces ...>,
    requires<T, Windows::UI::Xaml::Data::ICurrentChangingEventArgs>
{
    using composable = CurrentChangingEventArgs;

protected:

    CurrentChangingEventArgsT()
    {
        GetActivationFactory<CurrentChangingEventArgs, ICurrentChangingEventArgsFactory>().CreateInstance(*this, m_inner);
    }

    CurrentChangingEventArgsT(bool isCancelable)
    {
        GetActivationFactory<CurrentChangingEventArgs, ICurrentChangingEventArgsFactory>().CreateWithCancelableParameter(isCancelable, *this, m_inner);
    }
};

template <typename T, typename ... Interfaces> struct ItemIndexRangeT :
    overrides<T, Windows::IInspectable, Interfaces ...>,
    requires<T, Windows::UI::Xaml::Data::IItemIndexRange>
{
    using composable = ItemIndexRange;

protected:

    ItemIndexRangeT(int32_t firstIndex, uint32_t length)
    {
        GetActivationFactory<ItemIndexRange, IItemIndexRangeFactory>().CreateInstance(firstIndex, length, *this, m_inner);
    }
};

template <typename T, typename ... Interfaces> struct PropertyChangedEventArgsT :
    overrides<T, Windows::IInspectable, Interfaces ...>,
    requires<T, Windows::UI::Xaml::Data::IPropertyChangedEventArgs>
{
    using composable = PropertyChangedEventArgs;

protected:

    PropertyChangedEventArgsT(hstring_ref name)
    {
        GetActivationFactory<PropertyChangedEventArgs, IPropertyChangedEventArgsFactory>().CreateInstance(name, *this, m_inner);
    }
};

template <typename T, typename ... Interfaces> struct RelativeSourceT :
    overrides<T, Windows::IInspectable, Interfaces ...>,
    requires<T, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Data::IRelativeSource>
{
    using composable = RelativeSource;

protected:

    RelativeSourceT()
    {
        GetActivationFactory<RelativeSource, IRelativeSourceFactory>().CreateInstance(*this, m_inner);
    }
};

}}}}

namespace Windows { namespace UI { namespace Xaml { namespace Documents {

template <typename T, typename ... Interfaces> struct BlockT :
    overrides<T, Windows::UI::Xaml::Documents::ITextElementOverridesT<T>, Interfaces ...>,
    requires<T, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Documents::ITextElement, Windows::UI::Xaml::Documents::ITextElement2, Windows::UI::Xaml::Documents::IBlock>
{
    using composable = Block;

protected:

    BlockT()
    {
        GetActivationFactory<Block, IBlockFactory>().CreateInstance(*this, m_inner);
    }
};

template <typename T, typename ... Interfaces> struct InlineT :
    overrides<T, Windows::UI::Xaml::Documents::ITextElementOverridesT<T>, Interfaces ...>,
    requires<T, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Documents::ITextElement, Windows::UI::Xaml::Documents::ITextElement2, Windows::UI::Xaml::Documents::IInline>
{
    using composable = Inline;

protected:

    InlineT()
    {
        GetActivationFactory<Inline, IInlineFactory>().CreateInstance(*this, m_inner);
    }
};

template <typename T, typename ... Interfaces> struct SpanT :
    overrides<T, Windows::UI::Xaml::Documents::ITextElementOverridesT<T>, Interfaces ...>,
    requires<T, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Documents::ITextElement, Windows::UI::Xaml::Documents::ITextElement2, Windows::UI::Xaml::Documents::IInline, Windows::UI::Xaml::Documents::ISpan>
{
    using composable = Span;

protected:

    SpanT()
    {
        GetActivationFactory<Span, ISpanFactory>().CreateInstance(*this, m_inner);
    }
};

}}}}

namespace Windows { namespace UI { namespace Xaml { namespace Input {

template <typename T, typename ... Interfaces> struct ManipulationStartedRoutedEventArgsT :
    overrides<T, Windows::IInspectable, Interfaces ...>,
    requires<T, Windows::UI::Xaml::IRoutedEventArgs, Windows::UI::Xaml::Input::IManipulationStartedRoutedEventArgs>
{
    using composable = ManipulationStartedRoutedEventArgs;

protected:

    ManipulationStartedRoutedEventArgsT()
    {
        GetActivationFactory<ManipulationStartedRoutedEventArgs, IManipulationStartedRoutedEventArgsFactory>().CreateInstance(*this, m_inner);
    }
};

}}}}

namespace Windows { namespace UI { namespace Xaml { namespace Interop {

template <typename T, typename ... Interfaces> struct NotifyCollectionChangedEventArgsT :
    overrides<T, Windows::IInspectable, Interfaces ...>,
    requires<T, Windows::UI::Xaml::Interop::INotifyCollectionChangedEventArgs>
{
    using composable = NotifyCollectionChangedEventArgs;

protected:

    NotifyCollectionChangedEventArgsT(Windows::UI::Xaml::Interop::NotifyCollectionChangedAction action, const Windows::UI::Xaml::Interop::IBindableVector & newItems, const Windows::UI::Xaml::Interop::IBindableVector & oldItems, int32_t newIndex, int32_t oldIndex)
    {
        GetActivationFactory<NotifyCollectionChangedEventArgs, INotifyCollectionChangedEventArgsFactory>().CreateInstanceWithAllParameters(action, newItems, oldItems, newIndex, oldIndex, *this, m_inner);
    }
};

}}}}

namespace Windows { namespace UI { namespace Xaml { namespace Media {

template <typename T, typename ... Interfaces> struct BrushT :
    overrides<T, Windows::IInspectable, Interfaces ...>,
    requires<T, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Media::IBrush>
{
    using composable = Brush;

protected:

    BrushT()
    {
        GetActivationFactory<Brush, IBrushFactory>().CreateInstance(*this, m_inner);
    }
};

template <typename T, typename ... Interfaces> struct CacheModeT :
    overrides<T, Windows::IInspectable, Interfaces ...>,
    requires<T, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Media::ICacheMode>
{
    using composable = CacheMode;

protected:

    CacheModeT()
    {
        GetActivationFactory<CacheMode, ICacheModeFactory>().CreateInstance(*this, m_inner);
    }
};

template <typename T, typename ... Interfaces> struct FontFamilyT :
    overrides<T, Windows::IInspectable, Interfaces ...>,
    requires<T, Windows::UI::Xaml::Media::IFontFamily>
{
    using composable = FontFamily;

protected:

    FontFamilyT(hstring_ref familyName)
    {
        GetActivationFactory<FontFamily, IFontFamilyFactory>().CreateInstanceWithName(familyName, *this, m_inner);
    }
};

template <typename T, typename ... Interfaces> struct GeneralTransformT :
    overrides<T, Windows::UI::Xaml::Media::IGeneralTransformOverridesT<T>, Interfaces ...>,
    requires<T, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Media::IGeneralTransform>
{
    using composable = GeneralTransform;

protected:

    GeneralTransformT()
    {
        GetActivationFactory<GeneralTransform, IGeneralTransformFactory>().CreateInstance(*this, m_inner);
    }
};

template <typename T, typename ... Interfaces> struct GradientBrushT :
    overrides<T, Windows::IInspectable, Interfaces ...>,
    requires<T, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Media::IBrush, Windows::UI::Xaml::Media::IGradientBrush>
{
    using composable = GradientBrush;

protected:

    GradientBrushT()
    {
        GetActivationFactory<GradientBrush, IGradientBrushFactory>().CreateInstance(*this, m_inner);
    }
};

template <typename T, typename ... Interfaces> struct ProjectionT :
    overrides<T, Windows::IInspectable, Interfaces ...>,
    requires<T, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Media::IProjection>
{
    using composable = Projection;

protected:

    ProjectionT()
    {
        GetActivationFactory<Projection, IProjectionFactory>().CreateInstance(*this, m_inner);
    }
};

template <typename T, typename ... Interfaces> struct TileBrushT :
    overrides<T, Windows::IInspectable, Interfaces ...>,
    requires<T, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Media::IBrush, Windows::UI::Xaml::Media::ITileBrush>
{
    using composable = TileBrush;

protected:

    TileBrushT()
    {
        GetActivationFactory<TileBrush, ITileBrushFactory>().CreateInstance(*this, m_inner);
    }
};

}}}}

namespace Windows { namespace UI { namespace Xaml { namespace Media { namespace Animation {

template <typename T, typename ... Interfaces> struct ColorKeyFrameT :
    overrides<T, Windows::IInspectable, Interfaces ...>,
    requires<T, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Media::Animation::IColorKeyFrame>
{
    using composable = ColorKeyFrame;

protected:

    ColorKeyFrameT()
    {
        GetActivationFactory<ColorKeyFrame, IColorKeyFrameFactory>().CreateInstance(*this, m_inner);
    }
};

template <typename T, typename ... Interfaces> struct DoubleKeyFrameT :
    overrides<T, Windows::IInspectable, Interfaces ...>,
    requires<T, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Media::Animation::IDoubleKeyFrame>
{
    using composable = DoubleKeyFrame;

protected:

    DoubleKeyFrameT()
    {
        GetActivationFactory<DoubleKeyFrame, IDoubleKeyFrameFactory>().CreateInstance(*this, m_inner);
    }
};

template <typename T, typename ... Interfaces> struct NavigationTransitionInfoT :
    overrides<T, Windows::UI::Xaml::Media::Animation::INavigationTransitionInfoOverridesT<T>, Interfaces ...>,
    requires<T, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Media::Animation::INavigationTransitionInfo>
{
    using composable = NavigationTransitionInfo;

protected:

    NavigationTransitionInfoT()
    {
        GetActivationFactory<NavigationTransitionInfo, INavigationTransitionInfoFactory>().CreateInstance(*this, m_inner);
    }
};

template <typename T, typename ... Interfaces> struct ObjectKeyFrameT :
    overrides<T, Windows::IInspectable, Interfaces ...>,
    requires<T, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Media::Animation::IObjectKeyFrame>
{
    using composable = ObjectKeyFrame;

protected:

    ObjectKeyFrameT()
    {
        GetActivationFactory<ObjectKeyFrame, IObjectKeyFrameFactory>().CreateInstance(*this, m_inner);
    }
};

template <typename T, typename ... Interfaces> struct PointKeyFrameT :
    overrides<T, Windows::IInspectable, Interfaces ...>,
    requires<T, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Media::Animation::IPointKeyFrame>
{
    using composable = PointKeyFrame;

protected:

    PointKeyFrameT()
    {
        GetActivationFactory<PointKeyFrame, IPointKeyFrameFactory>().CreateInstance(*this, m_inner);
    }
};

template <typename T, typename ... Interfaces> struct TimelineT :
    overrides<T, Windows::IInspectable, Interfaces ...>,
    requires<T, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Media::Animation::ITimeline>
{
    using composable = Timeline;

protected:

    TimelineT()
    {
        GetActivationFactory<Timeline, ITimelineFactory>().CreateInstance(*this, m_inner);
    }
};

}}}}}

namespace Windows { namespace UI { namespace Xaml { namespace Media { namespace Imaging {

template <typename T, typename ... Interfaces> struct BitmapSourceT :
    overrides<T, Windows::IInspectable, Interfaces ...>,
    requires<T, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Media::IImageSource, Windows::UI::Xaml::Media::Imaging::IBitmapSource>
{
    using composable = BitmapSource;

protected:

    BitmapSourceT()
    {
        GetActivationFactory<BitmapSource, IBitmapSourceFactory>().CreateInstance(*this, m_inner);
    }
};

template <typename T, typename ... Interfaces> struct SurfaceImageSourceT :
    overrides<T, Windows::IInspectable, Interfaces ...>,
    requires<T, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Media::IImageSource, Windows::UI::Xaml::Media::Imaging::ISurfaceImageSource>
{
    using composable = SurfaceImageSource;

protected:

    SurfaceImageSourceT(int32_t pixelWidth, int32_t pixelHeight)
    {
        GetActivationFactory<SurfaceImageSource, ISurfaceImageSourceFactory>().CreateInstanceWithDimensions(pixelWidth, pixelHeight, *this, m_inner);
    }

    SurfaceImageSourceT(int32_t pixelWidth, int32_t pixelHeight, bool isOpaque)
    {
        GetActivationFactory<SurfaceImageSource, ISurfaceImageSourceFactory>().CreateInstanceWithDimensionsAndOpacity(pixelWidth, pixelHeight, isOpaque, *this, m_inner);
    }
};

template <typename T, typename ... Interfaces> struct XamlRenderingBackgroundTaskT :
    overrides<T, Windows::UI::Xaml::Media::Imaging::IXamlRenderingBackgroundTaskOverridesT<T>, Interfaces ...>,
    requires<T, Windows::UI::Xaml::Media::Imaging::IXamlRenderingBackgroundTask>
{
    using composable = XamlRenderingBackgroundTask;

protected:

    XamlRenderingBackgroundTaskT()
    {
        GetActivationFactory<XamlRenderingBackgroundTask, IXamlRenderingBackgroundTaskFactory>().CreateInstance(*this, m_inner);
    }
};

}}}}}

namespace Windows { namespace UI { namespace Xaml { namespace Media { namespace Media3D {

template <typename T, typename ... Interfaces> struct Transform3DT :
    overrides<T, Windows::IInspectable, Interfaces ...>,
    requires<T, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Media::Media3D::ITransform3D>
{
    using composable = Transform3D;

protected:

    Transform3DT()
    {
        GetActivationFactory<Transform3D, ITransform3DFactory>().CreateInstance(*this, m_inner);
    }
};

}}}}}

namespace Windows { namespace UI { namespace Xaml { namespace Printing {

template <typename T, typename ... Interfaces> struct PrintDocumentT :
    overrides<T, Windows::IInspectable, Interfaces ...>,
    requires<T, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Printing::IPrintDocument>
{
    using composable = PrintDocument;

protected:

    PrintDocumentT()
    {
        GetActivationFactory<PrintDocument, IPrintDocumentFactory>().CreateInstance(*this, m_inner);
    }
};

}}}}

namespace Windows { namespace UI { namespace Xaml { namespace Resources {

template <typename T, typename ... Interfaces> struct CustomXamlResourceLoaderT :
    overrides<T, Windows::UI::Xaml::Resources::ICustomXamlResourceLoaderOverridesT<T>, Interfaces ...>,
    requires<T, Windows::UI::Xaml::Resources::ICustomXamlResourceLoader>
{
    using composable = CustomXamlResourceLoader;

protected:

    CustomXamlResourceLoaderT()
    {
        GetActivationFactory<CustomXamlResourceLoader, ICustomXamlResourceLoaderFactory>().CreateInstance(*this, m_inner);
    }
};

}}}}

namespace Windows { namespace UI { namespace Xaml { namespace Shapes {

template <typename T, typename ... Interfaces> struct PathT :
    overrides<T, Windows::UI::Xaml::IUIElementOverridesT<T>, Windows::UI::Xaml::IFrameworkElementOverridesT<T>, Windows::UI::Xaml::IFrameworkElementOverrides2T<T>, Interfaces ...>,
    requires<T, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::Shapes::IShape, Windows::UI::Xaml::Shapes::IPath>
{
    using composable = Path;

protected:

    PathT()
    {
        GetActivationFactory<Path, IPathFactory>().CreateInstance(*this, m_inner);
    }
};

template <typename T, typename ... Interfaces> struct ShapeT :
    overrides<T, Windows::UI::Xaml::IUIElementOverridesT<T>, Windows::UI::Xaml::IFrameworkElementOverridesT<T>, Windows::UI::Xaml::IFrameworkElementOverrides2T<T>, Interfaces ...>,
    requires<T, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::Shapes::IShape>
{
    using composable = Shape;

protected:

    ShapeT()
    {
        GetActivationFactory<Shape, IShapeFactory>().CreateInstance(*this, m_inner);
    }
};

}}}}

}
