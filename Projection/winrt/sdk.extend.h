// C++ for the Windows Runtime v1.29
// Copyright (c) 2016 Microsoft Corporation

#pragma once

WINRT_EXPORT namespace winrt {

namespace Windows { namespace UI { namespace Xaml {

template <typename D, typename A = ABI::Windows::UI::Xaml::IApplicationOverrides>
class IApplicationOverridesT : public A
{
    D & shim() noexcept { return *static_cast<D *>(this); }

public:

    using IApplicationOverrides = winrt::Windows::UI::Xaml::IApplicationOverrides;

    void OnActivated(const Windows::ApplicationModel::Activation::IActivatedEventArgs & args)
    {
        shim().as<IApplicationOverrides>().OnActivated(args);
    }

    void OnLaunched(const Windows::ApplicationModel::Activation::LaunchActivatedEventArgs & args)
    {
        shim().as<IApplicationOverrides>().OnLaunched(args);
    }

    void OnFileActivated(const Windows::ApplicationModel::Activation::FileActivatedEventArgs & args)
    {
        shim().as<IApplicationOverrides>().OnFileActivated(args);
    }

    void OnSearchActivated(const Windows::ApplicationModel::Activation::SearchActivatedEventArgs & args)
    {
        shim().as<IApplicationOverrides>().OnSearchActivated(args);
    }

    void OnShareTargetActivated(const Windows::ApplicationModel::Activation::ShareTargetActivatedEventArgs & args)
    {
        shim().as<IApplicationOverrides>().OnShareTargetActivated(args);
    }

    void OnFileOpenPickerActivated(const Windows::ApplicationModel::Activation::FileOpenPickerActivatedEventArgs & args)
    {
        shim().as<IApplicationOverrides>().OnFileOpenPickerActivated(args);
    }

    void OnFileSavePickerActivated(const Windows::ApplicationModel::Activation::FileSavePickerActivatedEventArgs & args)
    {
        shim().as<IApplicationOverrides>().OnFileSavePickerActivated(args);
    }

    void OnCachedFileUpdaterActivated(const Windows::ApplicationModel::Activation::CachedFileUpdaterActivatedEventArgs & args)
    {
        shim().as<IApplicationOverrides>().OnCachedFileUpdaterActivated(args);
    }

    void OnWindowCreated(const Windows::UI::Xaml::WindowCreatedEventArgs & args)
    {
        shim().as<IApplicationOverrides>().OnWindowCreated(args);
    }

    HRESULT __stdcall abi_OnActivated(abi_arg_in<Windows::ApplicationModel::Activation::IActivatedEventArgs> args) noexcept override
    {
        try
        {
            shim().OnActivated(*reinterpret_cast<const Windows::ApplicationModel::Activation::IActivatedEventArgs *>(&args));
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
            shim().OnLaunched(*reinterpret_cast<const Windows::ApplicationModel::Activation::LaunchActivatedEventArgs *>(&args));
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
            shim().OnFileActivated(*reinterpret_cast<const Windows::ApplicationModel::Activation::FileActivatedEventArgs *>(&args));
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
            shim().OnSearchActivated(*reinterpret_cast<const Windows::ApplicationModel::Activation::SearchActivatedEventArgs *>(&args));
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
            shim().OnShareTargetActivated(*reinterpret_cast<const Windows::ApplicationModel::Activation::ShareTargetActivatedEventArgs *>(&args));
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
            shim().OnFileOpenPickerActivated(*reinterpret_cast<const Windows::ApplicationModel::Activation::FileOpenPickerActivatedEventArgs *>(&args));
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
            shim().OnFileSavePickerActivated(*reinterpret_cast<const Windows::ApplicationModel::Activation::FileSavePickerActivatedEventArgs *>(&args));
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
            shim().OnCachedFileUpdaterActivated(*reinterpret_cast<const Windows::ApplicationModel::Activation::CachedFileUpdaterActivatedEventArgs *>(&args));
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
            shim().OnWindowCreated(*reinterpret_cast<const Windows::UI::Xaml::WindowCreatedEventArgs *>(&args));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D, typename A = ABI::Windows::UI::Xaml::IApplicationOverrides2>
class IApplicationOverrides2T : public A
{
    D & shim() noexcept { return *static_cast<D *>(this); }

public:

    using IApplicationOverrides2 = winrt::Windows::UI::Xaml::IApplicationOverrides2;

    void OnBackgroundActivated(const Windows::ApplicationModel::Activation::BackgroundActivatedEventArgs & args)
    {
        shim().as<IApplicationOverrides2>().OnBackgroundActivated(args);
    }

    HRESULT __stdcall abi_OnBackgroundActivated(abi_arg_in<Windows::ApplicationModel::Activation::IBackgroundActivatedEventArgs> args) noexcept override
    {
        try
        {
            shim().OnBackgroundActivated(*reinterpret_cast<const Windows::ApplicationModel::Activation::BackgroundActivatedEventArgs *>(&args));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D, typename A = ABI::Windows::UI::Xaml::IFrameworkElementOverrides>
class IFrameworkElementOverridesT : public A
{
    D & shim() noexcept { return *static_cast<D *>(this); }

public:

    using IFrameworkElementOverrides = winrt::Windows::UI::Xaml::IFrameworkElementOverrides;

    Windows::Foundation::Size MeasureOverride(const Windows::Foundation::Size & availableSize)
    {
        return shim().as<IFrameworkElementOverrides>().MeasureOverride(availableSize);
    }

    Windows::Foundation::Size ArrangeOverride(const Windows::Foundation::Size & finalSize)
    {
        return shim().as<IFrameworkElementOverrides>().ArrangeOverride(finalSize);
    }

    void OnApplyTemplate()
    {
        shim().as<IFrameworkElementOverrides>().OnApplyTemplate();
    }

    HRESULT __stdcall abi_MeasureOverride(abi_arg_in<Windows::Foundation::Size> availableSize, abi_arg_out<Windows::Foundation::Size> returnValue) noexcept override
    {
        try
        {
            *returnValue = detach(shim().MeasureOverride(*reinterpret_cast<const Windows::Foundation::Size *>(&availableSize)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_ArrangeOverride(abi_arg_in<Windows::Foundation::Size> finalSize, abi_arg_out<Windows::Foundation::Size> returnValue) noexcept override
    {
        try
        {
            *returnValue = detach(shim().ArrangeOverride(*reinterpret_cast<const Windows::Foundation::Size *>(&finalSize)));
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
            shim().OnApplyTemplate();
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D, typename A = ABI::Windows::UI::Xaml::IFrameworkElementOverrides2>
class IFrameworkElementOverrides2T : public A
{
    D & shim() noexcept { return *static_cast<D *>(this); }

public:

    using IFrameworkElementOverrides2 = winrt::Windows::UI::Xaml::IFrameworkElementOverrides2;

    bool GoToElementStateCore(hstring_ref stateName, bool useTransitions)
    {
        return shim().as<IFrameworkElementOverrides2>().GoToElementStateCore(stateName, useTransitions);
    }

    HRESULT __stdcall abi_GoToElementStateCore(abi_arg_in<hstring> stateName, bool useTransitions, bool * returnValue) noexcept override
    {
        try
        {
            *returnValue = detach(shim().GoToElementStateCore(*reinterpret_cast<const hstring *>(&stateName), useTransitions));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D, typename A = ABI::Windows::UI::Xaml::IUIElementOverrides>
class IUIElementOverridesT : public A
{
    D & shim() noexcept { return *static_cast<D *>(this); }

public:

    using IUIElementOverrides = winrt::Windows::UI::Xaml::IUIElementOverrides;

    Windows::UI::Xaml::Automation::Peers::AutomationPeer OnCreateAutomationPeer()
    {
        return shim().as<IUIElementOverrides>().OnCreateAutomationPeer();
    }

    void OnDisconnectVisualChildren()
    {
        shim().as<IUIElementOverrides>().OnDisconnectVisualChildren();
    }

    Windows::Foundation::Collections::IIterable<Windows::Foundation::Collections::IIterable<Windows::Foundation::Point>> FindSubElementsForTouchTargeting(const Windows::Foundation::Point & point, const Windows::Foundation::Rect & boundingRect)
    {
        return shim().as<IUIElementOverrides>().FindSubElementsForTouchTargeting(point, boundingRect);
    }

    HRESULT __stdcall abi_OnCreateAutomationPeer(abi_arg_out<Windows::UI::Xaml::Automation::Peers::IAutomationPeer> returnValue) noexcept override
    {
        try
        {
            *returnValue = detach(shim().OnCreateAutomationPeer());
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
            shim().OnDisconnectVisualChildren();
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_FindSubElementsForTouchTargeting(abi_arg_in<Windows::Foundation::Point> point, abi_arg_in<Windows::Foundation::Rect> boundingRect, abi_arg_out<Windows::Foundation::Collections::IIterable<Windows::Foundation::Collections::IIterable<Windows::Foundation::Point>>> returnValue) noexcept override
    {
        try
        {
            *returnValue = detach(shim().FindSubElementsForTouchTargeting(*reinterpret_cast<const Windows::Foundation::Point *>(&point), *reinterpret_cast<const Windows::Foundation::Rect *>(&boundingRect)));
            return S_OK;
        }
        catch (...)
        {
            *returnValue = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D, typename A = ABI::Windows::UI::Xaml::IVisualStateManagerOverrides>
class IVisualStateManagerOverridesT : public A
{
    D & shim() noexcept { return *static_cast<D *>(this); }

public:

    using IVisualStateManagerOverrides = winrt::Windows::UI::Xaml::IVisualStateManagerOverrides;

    bool GoToStateCore(const Windows::UI::Xaml::Controls::Control & control, const Windows::UI::Xaml::FrameworkElement & templateRoot, hstring_ref stateName, const Windows::UI::Xaml::VisualStateGroup & group, const Windows::UI::Xaml::VisualState & state, bool useTransitions)
    {
        return shim().as<IVisualStateManagerOverrides>().GoToStateCore(control, templateRoot, stateName, group, state, useTransitions);
    }

    HRESULT __stdcall abi_GoToStateCore(abi_arg_in<Windows::UI::Xaml::Controls::IControl> control, abi_arg_in<Windows::UI::Xaml::IFrameworkElement> templateRoot, abi_arg_in<hstring> stateName, abi_arg_in<Windows::UI::Xaml::IVisualStateGroup> group, abi_arg_in<Windows::UI::Xaml::IVisualState> state, bool useTransitions, bool * returnValue) noexcept override
    {
        try
        {
            *returnValue = detach(shim().GoToStateCore(*reinterpret_cast<const Windows::UI::Xaml::Controls::Control *>(&control), *reinterpret_cast<const Windows::UI::Xaml::FrameworkElement *>(&templateRoot), *reinterpret_cast<const hstring *>(&stateName), *reinterpret_cast<const Windows::UI::Xaml::VisualStateGroup *>(&group), *reinterpret_cast<const Windows::UI::Xaml::VisualState *>(&state), useTransitions));
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

template <typename D, typename A = ABI::Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides>
class IAutomationPeerOverridesT : public A
{
    D & shim() noexcept { return *static_cast<D *>(this); }

public:

    using IAutomationPeerOverrides = winrt::Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides;

    Windows::IInspectable GetPatternCore(Windows::UI::Xaml::Automation::Peers::PatternInterface patternInterface)
    {
        return shim().as<IAutomationPeerOverrides>().GetPatternCore(patternInterface);
    }

    hstring GetAcceleratorKeyCore()
    {
        return shim().as<IAutomationPeerOverrides>().GetAcceleratorKeyCore();
    }

    hstring GetAccessKeyCore()
    {
        return shim().as<IAutomationPeerOverrides>().GetAccessKeyCore();
    }

    Windows::UI::Xaml::Automation::Peers::AutomationControlType GetAutomationControlTypeCore()
    {
        return shim().as<IAutomationPeerOverrides>().GetAutomationControlTypeCore();
    }

    hstring GetAutomationIdCore()
    {
        return shim().as<IAutomationPeerOverrides>().GetAutomationIdCore();
    }

    Windows::Foundation::Rect GetBoundingRectangleCore()
    {
        return shim().as<IAutomationPeerOverrides>().GetBoundingRectangleCore();
    }

    Windows::Foundation::Collections::IVector<Windows::UI::Xaml::Automation::Peers::AutomationPeer> GetChildrenCore()
    {
        return shim().as<IAutomationPeerOverrides>().GetChildrenCore();
    }

    hstring GetClassNameCore()
    {
        return shim().as<IAutomationPeerOverrides>().GetClassNameCore();
    }

    Windows::Foundation::Point GetClickablePointCore()
    {
        return shim().as<IAutomationPeerOverrides>().GetClickablePointCore();
    }

    hstring GetHelpTextCore()
    {
        return shim().as<IAutomationPeerOverrides>().GetHelpTextCore();
    }

    hstring GetItemStatusCore()
    {
        return shim().as<IAutomationPeerOverrides>().GetItemStatusCore();
    }

    hstring GetItemTypeCore()
    {
        return shim().as<IAutomationPeerOverrides>().GetItemTypeCore();
    }

    Windows::UI::Xaml::Automation::Peers::AutomationPeer GetLabeledByCore()
    {
        return shim().as<IAutomationPeerOverrides>().GetLabeledByCore();
    }

    hstring GetLocalizedControlTypeCore()
    {
        return shim().as<IAutomationPeerOverrides>().GetLocalizedControlTypeCore();
    }

    hstring GetNameCore()
    {
        return shim().as<IAutomationPeerOverrides>().GetNameCore();
    }

    Windows::UI::Xaml::Automation::Peers::AutomationOrientation GetOrientationCore()
    {
        return shim().as<IAutomationPeerOverrides>().GetOrientationCore();
    }

    bool HasKeyboardFocusCore()
    {
        return shim().as<IAutomationPeerOverrides>().HasKeyboardFocusCore();
    }

    bool IsContentElementCore()
    {
        return shim().as<IAutomationPeerOverrides>().IsContentElementCore();
    }

    bool IsControlElementCore()
    {
        return shim().as<IAutomationPeerOverrides>().IsControlElementCore();
    }

    bool IsEnabledCore()
    {
        return shim().as<IAutomationPeerOverrides>().IsEnabledCore();
    }

    bool IsKeyboardFocusableCore()
    {
        return shim().as<IAutomationPeerOverrides>().IsKeyboardFocusableCore();
    }

    bool IsOffscreenCore()
    {
        return shim().as<IAutomationPeerOverrides>().IsOffscreenCore();
    }

    bool IsPasswordCore()
    {
        return shim().as<IAutomationPeerOverrides>().IsPasswordCore();
    }

    bool IsRequiredForFormCore()
    {
        return shim().as<IAutomationPeerOverrides>().IsRequiredForFormCore();
    }

    void SetFocusCore()
    {
        shim().as<IAutomationPeerOverrides>().SetFocusCore();
    }

    Windows::UI::Xaml::Automation::Peers::AutomationPeer GetPeerFromPointCore(const Windows::Foundation::Point & point)
    {
        return shim().as<IAutomationPeerOverrides>().GetPeerFromPointCore(point);
    }

    Windows::UI::Xaml::Automation::Peers::AutomationLiveSetting GetLiveSettingCore()
    {
        return shim().as<IAutomationPeerOverrides>().GetLiveSettingCore();
    }

    HRESULT __stdcall abi_GetPatternCore(Windows::UI::Xaml::Automation::Peers::PatternInterface patternInterface, abi_arg_out<Windows::IInspectable> returnValue) noexcept override
    {
        try
        {
            *returnValue = detach(shim().GetPatternCore(patternInterface));
            return S_OK;
        }
        catch (...)
        {
            *returnValue = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetAcceleratorKeyCore(abi_arg_out<hstring> returnValue) noexcept override
    {
        try
        {
            *returnValue = detach(shim().GetAcceleratorKeyCore());
            return S_OK;
        }
        catch (...)
        {
            *returnValue = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetAccessKeyCore(abi_arg_out<hstring> returnValue) noexcept override
    {
        try
        {
            *returnValue = detach(shim().GetAccessKeyCore());
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
            *returnValue = detach(shim().GetAutomationControlTypeCore());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetAutomationIdCore(abi_arg_out<hstring> returnValue) noexcept override
    {
        try
        {
            *returnValue = detach(shim().GetAutomationIdCore());
            return S_OK;
        }
        catch (...)
        {
            *returnValue = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetBoundingRectangleCore(abi_arg_out<Windows::Foundation::Rect> returnValue) noexcept override
    {
        try
        {
            *returnValue = detach(shim().GetBoundingRectangleCore());
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
            *returnValue = detach(shim().GetChildrenCore());
            return S_OK;
        }
        catch (...)
        {
            *returnValue = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetClassNameCore(abi_arg_out<hstring> returnValue) noexcept override
    {
        try
        {
            *returnValue = detach(shim().GetClassNameCore());
            return S_OK;
        }
        catch (...)
        {
            *returnValue = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetClickablePointCore(abi_arg_out<Windows::Foundation::Point> returnValue) noexcept override
    {
        try
        {
            *returnValue = detach(shim().GetClickablePointCore());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetHelpTextCore(abi_arg_out<hstring> returnValue) noexcept override
    {
        try
        {
            *returnValue = detach(shim().GetHelpTextCore());
            return S_OK;
        }
        catch (...)
        {
            *returnValue = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetItemStatusCore(abi_arg_out<hstring> returnValue) noexcept override
    {
        try
        {
            *returnValue = detach(shim().GetItemStatusCore());
            return S_OK;
        }
        catch (...)
        {
            *returnValue = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetItemTypeCore(abi_arg_out<hstring> returnValue) noexcept override
    {
        try
        {
            *returnValue = detach(shim().GetItemTypeCore());
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
            *returnValue = detach(shim().GetLabeledByCore());
            return S_OK;
        }
        catch (...)
        {
            *returnValue = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetLocalizedControlTypeCore(abi_arg_out<hstring> returnValue) noexcept override
    {
        try
        {
            *returnValue = detach(shim().GetLocalizedControlTypeCore());
            return S_OK;
        }
        catch (...)
        {
            *returnValue = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetNameCore(abi_arg_out<hstring> returnValue) noexcept override
    {
        try
        {
            *returnValue = detach(shim().GetNameCore());
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
            *returnValue = detach(shim().GetOrientationCore());
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
            *returnValue = detach(shim().HasKeyboardFocusCore());
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
            *returnValue = detach(shim().IsContentElementCore());
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
            *returnValue = detach(shim().IsControlElementCore());
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
            *returnValue = detach(shim().IsEnabledCore());
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
            *returnValue = detach(shim().IsKeyboardFocusableCore());
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
            *returnValue = detach(shim().IsOffscreenCore());
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
            *returnValue = detach(shim().IsPasswordCore());
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
            *returnValue = detach(shim().IsRequiredForFormCore());
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
            shim().SetFocusCore();
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetPeerFromPointCore(abi_arg_in<Windows::Foundation::Point> point, abi_arg_out<Windows::UI::Xaml::Automation::Peers::IAutomationPeer> returnValue) noexcept override
    {
        try
        {
            *returnValue = detach(shim().GetPeerFromPointCore(*reinterpret_cast<const Windows::Foundation::Point *>(&point)));
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
            *returnValue = detach(shim().GetLiveSettingCore());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D, typename A = ABI::Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2>
class IAutomationPeerOverrides2T : public A
{
    D & shim() noexcept { return *static_cast<D *>(this); }

public:

    using IAutomationPeerOverrides2 = winrt::Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2;

    void ShowContextMenuCore()
    {
        shim().as<IAutomationPeerOverrides2>().ShowContextMenuCore();
    }

    Windows::Foundation::Collections::IVectorView<Windows::UI::Xaml::Automation::Peers::AutomationPeer> GetControlledPeersCore()
    {
        return shim().as<IAutomationPeerOverrides2>().GetControlledPeersCore();
    }

    HRESULT __stdcall abi_ShowContextMenuCore() noexcept override
    {
        try
        {
            shim().ShowContextMenuCore();
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
            *returnValue = detach(shim().GetControlledPeersCore());
            return S_OK;
        }
        catch (...)
        {
            *returnValue = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D, typename A = ABI::Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3>
class IAutomationPeerOverrides3T : public A
{
    D & shim() noexcept { return *static_cast<D *>(this); }

public:

    using IAutomationPeerOverrides3 = winrt::Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3;

    Windows::IInspectable NavigateCore(Windows::UI::Xaml::Automation::Peers::AutomationNavigationDirection direction)
    {
        return shim().as<IAutomationPeerOverrides3>().NavigateCore(direction);
    }

    Windows::IInspectable GetElementFromPointCore(const Windows::Foundation::Point & pointInWindowCoordinates)
    {
        return shim().as<IAutomationPeerOverrides3>().GetElementFromPointCore(pointInWindowCoordinates);
    }

    Windows::IInspectable GetFocusedElementCore()
    {
        return shim().as<IAutomationPeerOverrides3>().GetFocusedElementCore();
    }

    Windows::Foundation::Collections::IVector<Windows::UI::Xaml::Automation::Peers::AutomationPeerAnnotation> GetAnnotationsCore()
    {
        return shim().as<IAutomationPeerOverrides3>().GetAnnotationsCore();
    }

    int32_t GetPositionInSetCore()
    {
        return shim().as<IAutomationPeerOverrides3>().GetPositionInSetCore();
    }

    int32_t GetSizeOfSetCore()
    {
        return shim().as<IAutomationPeerOverrides3>().GetSizeOfSetCore();
    }

    int32_t GetLevelCore()
    {
        return shim().as<IAutomationPeerOverrides3>().GetLevelCore();
    }

    HRESULT __stdcall abi_NavigateCore(Windows::UI::Xaml::Automation::Peers::AutomationNavigationDirection direction, abi_arg_out<Windows::IInspectable> returnValue) noexcept override
    {
        try
        {
            *returnValue = detach(shim().NavigateCore(direction));
            return S_OK;
        }
        catch (...)
        {
            *returnValue = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetElementFromPointCore(abi_arg_in<Windows::Foundation::Point> pointInWindowCoordinates, abi_arg_out<Windows::IInspectable> returnValue) noexcept override
    {
        try
        {
            *returnValue = detach(shim().GetElementFromPointCore(*reinterpret_cast<const Windows::Foundation::Point *>(&pointInWindowCoordinates)));
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
            *returnValue = detach(shim().GetFocusedElementCore());
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
            *returnValue = detach(shim().GetAnnotationsCore());
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
            *returnValue = detach(shim().GetPositionInSetCore());
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
            *returnValue = detach(shim().GetSizeOfSetCore());
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
            *returnValue = detach(shim().GetLevelCore());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D, typename A = ABI::Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides4>
class IAutomationPeerOverrides4T : public A
{
    D & shim() noexcept { return *static_cast<D *>(this); }

public:

    using IAutomationPeerOverrides4 = winrt::Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides4;

    Windows::UI::Xaml::Automation::Peers::AutomationLandmarkType GetLandmarkTypeCore()
    {
        return shim().as<IAutomationPeerOverrides4>().GetLandmarkTypeCore();
    }

    hstring GetLocalizedLandmarkTypeCore()
    {
        return shim().as<IAutomationPeerOverrides4>().GetLocalizedLandmarkTypeCore();
    }

    HRESULT __stdcall abi_GetLandmarkTypeCore(Windows::UI::Xaml::Automation::Peers::AutomationLandmarkType * returnValue) noexcept override
    {
        try
        {
            *returnValue = detach(shim().GetLandmarkTypeCore());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetLocalizedLandmarkTypeCore(abi_arg_out<hstring> returnValue) noexcept override
    {
        try
        {
            *returnValue = detach(shim().GetLocalizedLandmarkTypeCore());
            return S_OK;
        }
        catch (...)
        {
            *returnValue = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D, typename A = ABI::Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides5>
class IAutomationPeerOverrides5T : public A
{
    D & shim() noexcept { return *static_cast<D *>(this); }

public:

    using IAutomationPeerOverrides5 = winrt::Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides5;

    bool IsPeripheralCore()
    {
        return shim().as<IAutomationPeerOverrides5>().IsPeripheralCore();
    }

    bool IsDataValidForFormCore()
    {
        return shim().as<IAutomationPeerOverrides5>().IsDataValidForFormCore();
    }

    hstring GetFullDescriptionCore()
    {
        return shim().as<IAutomationPeerOverrides5>().GetFullDescriptionCore();
    }

    Windows::Foundation::Collections::IIterable<Windows::UI::Xaml::Automation::Peers::AutomationPeer> GetDescribedByCore()
    {
        return shim().as<IAutomationPeerOverrides5>().GetDescribedByCore();
    }

    Windows::Foundation::Collections::IIterable<Windows::UI::Xaml::Automation::Peers::AutomationPeer> GetFlowsToCore()
    {
        return shim().as<IAutomationPeerOverrides5>().GetFlowsToCore();
    }

    Windows::Foundation::Collections::IIterable<Windows::UI::Xaml::Automation::Peers::AutomationPeer> GetFlowsFromCore()
    {
        return shim().as<IAutomationPeerOverrides5>().GetFlowsFromCore();
    }

    HRESULT __stdcall abi_IsPeripheralCore(bool * returnValue) noexcept override
    {
        try
        {
            *returnValue = detach(shim().IsPeripheralCore());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_IsDataValidForFormCore(bool * returnValue) noexcept override
    {
        try
        {
            *returnValue = detach(shim().IsDataValidForFormCore());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetFullDescriptionCore(abi_arg_out<hstring> returnValue) noexcept override
    {
        try
        {
            *returnValue = detach(shim().GetFullDescriptionCore());
            return S_OK;
        }
        catch (...)
        {
            *returnValue = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetDescribedByCore(abi_arg_out<Windows::Foundation::Collections::IIterable<Windows::UI::Xaml::Automation::Peers::AutomationPeer>> returnValue) noexcept override
    {
        try
        {
            *returnValue = detach(shim().GetDescribedByCore());
            return S_OK;
        }
        catch (...)
        {
            *returnValue = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetFlowsToCore(abi_arg_out<Windows::Foundation::Collections::IIterable<Windows::UI::Xaml::Automation::Peers::AutomationPeer>> returnValue) noexcept override
    {
        try
        {
            *returnValue = detach(shim().GetFlowsToCore());
            return S_OK;
        }
        catch (...)
        {
            *returnValue = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetFlowsFromCore(abi_arg_out<Windows::Foundation::Collections::IIterable<Windows::UI::Xaml::Automation::Peers::AutomationPeer>> returnValue) noexcept override
    {
        try
        {
            *returnValue = detach(shim().GetFlowsFromCore());
            return S_OK;
        }
        catch (...)
        {
            *returnValue = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D, typename A = ABI::Windows::UI::Xaml::Automation::Peers::IItemsControlAutomationPeerOverrides2>
class IItemsControlAutomationPeerOverrides2T : public A
{
    D & shim() noexcept { return *static_cast<D *>(this); }

public:

    using IItemsControlAutomationPeerOverrides2 = winrt::Windows::UI::Xaml::Automation::Peers::IItemsControlAutomationPeerOverrides2;

    Windows::UI::Xaml::Automation::Peers::ItemAutomationPeer OnCreateItemAutomationPeer(const Windows::IInspectable & item)
    {
        return shim().as<IItemsControlAutomationPeerOverrides2>().OnCreateItemAutomationPeer(item);
    }

    HRESULT __stdcall abi_OnCreateItemAutomationPeer(abi_arg_in<Windows::IInspectable> item, abi_arg_out<Windows::UI::Xaml::Automation::Peers::IItemAutomationPeer> returnValue) noexcept override
    {
        try
        {
            *returnValue = detach(shim().OnCreateItemAutomationPeer(*reinterpret_cast<const Windows::IInspectable *>(&item)));
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

template <typename D, typename A = ABI::Windows::UI::Xaml::Controls::IAppBarOverrides>
class IAppBarOverridesT : public A
{
    D & shim() noexcept { return *static_cast<D *>(this); }

public:

    using IAppBarOverrides = winrt::Windows::UI::Xaml::Controls::IAppBarOverrides;

    void OnClosed(const Windows::IInspectable & e)
    {
        shim().as<IAppBarOverrides>().OnClosed(e);
    }

    void OnOpened(const Windows::IInspectable & e)
    {
        shim().as<IAppBarOverrides>().OnOpened(e);
    }

    HRESULT __stdcall abi_OnClosed(abi_arg_in<Windows::IInspectable> e) noexcept override
    {
        try
        {
            shim().OnClosed(*reinterpret_cast<const Windows::IInspectable *>(&e));
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
            shim().OnOpened(*reinterpret_cast<const Windows::IInspectable *>(&e));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D, typename A = ABI::Windows::UI::Xaml::Controls::IAppBarOverrides3>
class IAppBarOverrides3T : public A
{
    D & shim() noexcept { return *static_cast<D *>(this); }

public:

    using IAppBarOverrides3 = winrt::Windows::UI::Xaml::Controls::IAppBarOverrides3;

    void OnClosing(const Windows::IInspectable & e)
    {
        shim().as<IAppBarOverrides3>().OnClosing(e);
    }

    void OnOpening(const Windows::IInspectable & e)
    {
        shim().as<IAppBarOverrides3>().OnOpening(e);
    }

    HRESULT __stdcall abi_OnClosing(abi_arg_in<Windows::IInspectable> e) noexcept override
    {
        try
        {
            shim().OnClosing(*reinterpret_cast<const Windows::IInspectable *>(&e));
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
            shim().OnOpening(*reinterpret_cast<const Windows::IInspectable *>(&e));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D, typename A = ABI::Windows::UI::Xaml::Controls::IComboBoxOverrides>
class IComboBoxOverridesT : public A
{
    D & shim() noexcept { return *static_cast<D *>(this); }

public:

    using IComboBoxOverrides = winrt::Windows::UI::Xaml::Controls::IComboBoxOverrides;

    void OnDropDownClosed(const Windows::IInspectable & e)
    {
        shim().as<IComboBoxOverrides>().OnDropDownClosed(e);
    }

    void OnDropDownOpened(const Windows::IInspectable & e)
    {
        shim().as<IComboBoxOverrides>().OnDropDownOpened(e);
    }

    HRESULT __stdcall abi_OnDropDownClosed(abi_arg_in<Windows::IInspectable> e) noexcept override
    {
        try
        {
            shim().OnDropDownClosed(*reinterpret_cast<const Windows::IInspectable *>(&e));
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
            shim().OnDropDownOpened(*reinterpret_cast<const Windows::IInspectable *>(&e));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D, typename A = ABI::Windows::UI::Xaml::Controls::IContentControlOverrides>
class IContentControlOverridesT : public A
{
    D & shim() noexcept { return *static_cast<D *>(this); }

public:

    using IContentControlOverrides = winrt::Windows::UI::Xaml::Controls::IContentControlOverrides;

    void OnContentChanged(const Windows::IInspectable & oldContent, const Windows::IInspectable & newContent)
    {
        shim().as<IContentControlOverrides>().OnContentChanged(oldContent, newContent);
    }

    void OnContentTemplateChanged(const Windows::UI::Xaml::DataTemplate & oldContentTemplate, const Windows::UI::Xaml::DataTemplate & newContentTemplate)
    {
        shim().as<IContentControlOverrides>().OnContentTemplateChanged(oldContentTemplate, newContentTemplate);
    }

    void OnContentTemplateSelectorChanged(const Windows::UI::Xaml::Controls::DataTemplateSelector & oldContentTemplateSelector, const Windows::UI::Xaml::Controls::DataTemplateSelector & newContentTemplateSelector)
    {
        shim().as<IContentControlOverrides>().OnContentTemplateSelectorChanged(oldContentTemplateSelector, newContentTemplateSelector);
    }

    HRESULT __stdcall abi_OnContentChanged(abi_arg_in<Windows::IInspectable> oldContent, abi_arg_in<Windows::IInspectable> newContent) noexcept override
    {
        try
        {
            shim().OnContentChanged(*reinterpret_cast<const Windows::IInspectable *>(&oldContent), *reinterpret_cast<const Windows::IInspectable *>(&newContent));
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
            shim().OnContentTemplateChanged(*reinterpret_cast<const Windows::UI::Xaml::DataTemplate *>(&oldContentTemplate), *reinterpret_cast<const Windows::UI::Xaml::DataTemplate *>(&newContentTemplate));
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
            shim().OnContentTemplateSelectorChanged(*reinterpret_cast<const Windows::UI::Xaml::Controls::DataTemplateSelector *>(&oldContentTemplateSelector), *reinterpret_cast<const Windows::UI::Xaml::Controls::DataTemplateSelector *>(&newContentTemplateSelector));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D, typename A = ABI::Windows::UI::Xaml::Controls::IContentPresenterOverrides>
class IContentPresenterOverridesT : public A
{
    D & shim() noexcept { return *static_cast<D *>(this); }

public:

    using IContentPresenterOverrides = winrt::Windows::UI::Xaml::Controls::IContentPresenterOverrides;

    void OnContentTemplateChanged(const Windows::UI::Xaml::DataTemplate & oldContentTemplate, const Windows::UI::Xaml::DataTemplate & newContentTemplate)
    {
        shim().as<IContentPresenterOverrides>().OnContentTemplateChanged(oldContentTemplate, newContentTemplate);
    }

    void OnContentTemplateSelectorChanged(const Windows::UI::Xaml::Controls::DataTemplateSelector & oldContentTemplateSelector, const Windows::UI::Xaml::Controls::DataTemplateSelector & newContentTemplateSelector)
    {
        shim().as<IContentPresenterOverrides>().OnContentTemplateSelectorChanged(oldContentTemplateSelector, newContentTemplateSelector);
    }

    HRESULT __stdcall abi_OnContentTemplateChanged(abi_arg_in<Windows::UI::Xaml::IDataTemplate> oldContentTemplate, abi_arg_in<Windows::UI::Xaml::IDataTemplate> newContentTemplate) noexcept override
    {
        try
        {
            shim().OnContentTemplateChanged(*reinterpret_cast<const Windows::UI::Xaml::DataTemplate *>(&oldContentTemplate), *reinterpret_cast<const Windows::UI::Xaml::DataTemplate *>(&newContentTemplate));
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
            shim().OnContentTemplateSelectorChanged(*reinterpret_cast<const Windows::UI::Xaml::Controls::DataTemplateSelector *>(&oldContentTemplateSelector), *reinterpret_cast<const Windows::UI::Xaml::Controls::DataTemplateSelector *>(&newContentTemplateSelector));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D, typename A = ABI::Windows::UI::Xaml::Controls::IControlOverrides>
class IControlOverridesT : public A
{
    D & shim() noexcept { return *static_cast<D *>(this); }

public:

    using IControlOverrides = winrt::Windows::UI::Xaml::Controls::IControlOverrides;

    void OnPointerEntered(const Windows::UI::Xaml::Input::PointerRoutedEventArgs & e)
    {
        shim().as<IControlOverrides>().OnPointerEntered(e);
    }

    void OnPointerPressed(const Windows::UI::Xaml::Input::PointerRoutedEventArgs & e)
    {
        shim().as<IControlOverrides>().OnPointerPressed(e);
    }

    void OnPointerMoved(const Windows::UI::Xaml::Input::PointerRoutedEventArgs & e)
    {
        shim().as<IControlOverrides>().OnPointerMoved(e);
    }

    void OnPointerReleased(const Windows::UI::Xaml::Input::PointerRoutedEventArgs & e)
    {
        shim().as<IControlOverrides>().OnPointerReleased(e);
    }

    void OnPointerExited(const Windows::UI::Xaml::Input::PointerRoutedEventArgs & e)
    {
        shim().as<IControlOverrides>().OnPointerExited(e);
    }

    void OnPointerCaptureLost(const Windows::UI::Xaml::Input::PointerRoutedEventArgs & e)
    {
        shim().as<IControlOverrides>().OnPointerCaptureLost(e);
    }

    void OnPointerCanceled(const Windows::UI::Xaml::Input::PointerRoutedEventArgs & e)
    {
        shim().as<IControlOverrides>().OnPointerCanceled(e);
    }

    void OnPointerWheelChanged(const Windows::UI::Xaml::Input::PointerRoutedEventArgs & e)
    {
        shim().as<IControlOverrides>().OnPointerWheelChanged(e);
    }

    void OnTapped(const Windows::UI::Xaml::Input::TappedRoutedEventArgs & e)
    {
        shim().as<IControlOverrides>().OnTapped(e);
    }

    void OnDoubleTapped(const Windows::UI::Xaml::Input::DoubleTappedRoutedEventArgs & e)
    {
        shim().as<IControlOverrides>().OnDoubleTapped(e);
    }

    void OnHolding(const Windows::UI::Xaml::Input::HoldingRoutedEventArgs & e)
    {
        shim().as<IControlOverrides>().OnHolding(e);
    }

    void OnRightTapped(const Windows::UI::Xaml::Input::RightTappedRoutedEventArgs & e)
    {
        shim().as<IControlOverrides>().OnRightTapped(e);
    }

    void OnManipulationStarting(const Windows::UI::Xaml::Input::ManipulationStartingRoutedEventArgs & e)
    {
        shim().as<IControlOverrides>().OnManipulationStarting(e);
    }

    void OnManipulationInertiaStarting(const Windows::UI::Xaml::Input::ManipulationInertiaStartingRoutedEventArgs & e)
    {
        shim().as<IControlOverrides>().OnManipulationInertiaStarting(e);
    }

    void OnManipulationStarted(const Windows::UI::Xaml::Input::ManipulationStartedRoutedEventArgs & e)
    {
        shim().as<IControlOverrides>().OnManipulationStarted(e);
    }

    void OnManipulationDelta(const Windows::UI::Xaml::Input::ManipulationDeltaRoutedEventArgs & e)
    {
        shim().as<IControlOverrides>().OnManipulationDelta(e);
    }

    void OnManipulationCompleted(const Windows::UI::Xaml::Input::ManipulationCompletedRoutedEventArgs & e)
    {
        shim().as<IControlOverrides>().OnManipulationCompleted(e);
    }

    void OnKeyUp(const Windows::UI::Xaml::Input::KeyRoutedEventArgs & e)
    {
        shim().as<IControlOverrides>().OnKeyUp(e);
    }

    void OnKeyDown(const Windows::UI::Xaml::Input::KeyRoutedEventArgs & e)
    {
        shim().as<IControlOverrides>().OnKeyDown(e);
    }

    void OnGotFocus(const Windows::UI::Xaml::RoutedEventArgs & e)
    {
        shim().as<IControlOverrides>().OnGotFocus(e);
    }

    void OnLostFocus(const Windows::UI::Xaml::RoutedEventArgs & e)
    {
        shim().as<IControlOverrides>().OnLostFocus(e);
    }

    void OnDragEnter(const Windows::UI::Xaml::DragEventArgs & e)
    {
        shim().as<IControlOverrides>().OnDragEnter(e);
    }

    void OnDragLeave(const Windows::UI::Xaml::DragEventArgs & e)
    {
        shim().as<IControlOverrides>().OnDragLeave(e);
    }

    void OnDragOver(const Windows::UI::Xaml::DragEventArgs & e)
    {
        shim().as<IControlOverrides>().OnDragOver(e);
    }

    void OnDrop(const Windows::UI::Xaml::DragEventArgs & e)
    {
        shim().as<IControlOverrides>().OnDrop(e);
    }

    HRESULT __stdcall abi_OnPointerEntered(abi_arg_in<Windows::UI::Xaml::Input::IPointerRoutedEventArgs> e) noexcept override
    {
        try
        {
            shim().OnPointerEntered(*reinterpret_cast<const Windows::UI::Xaml::Input::PointerRoutedEventArgs *>(&e));
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
            shim().OnPointerPressed(*reinterpret_cast<const Windows::UI::Xaml::Input::PointerRoutedEventArgs *>(&e));
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
            shim().OnPointerMoved(*reinterpret_cast<const Windows::UI::Xaml::Input::PointerRoutedEventArgs *>(&e));
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
            shim().OnPointerReleased(*reinterpret_cast<const Windows::UI::Xaml::Input::PointerRoutedEventArgs *>(&e));
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
            shim().OnPointerExited(*reinterpret_cast<const Windows::UI::Xaml::Input::PointerRoutedEventArgs *>(&e));
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
            shim().OnPointerCaptureLost(*reinterpret_cast<const Windows::UI::Xaml::Input::PointerRoutedEventArgs *>(&e));
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
            shim().OnPointerCanceled(*reinterpret_cast<const Windows::UI::Xaml::Input::PointerRoutedEventArgs *>(&e));
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
            shim().OnPointerWheelChanged(*reinterpret_cast<const Windows::UI::Xaml::Input::PointerRoutedEventArgs *>(&e));
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
            shim().OnTapped(*reinterpret_cast<const Windows::UI::Xaml::Input::TappedRoutedEventArgs *>(&e));
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
            shim().OnDoubleTapped(*reinterpret_cast<const Windows::UI::Xaml::Input::DoubleTappedRoutedEventArgs *>(&e));
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
            shim().OnHolding(*reinterpret_cast<const Windows::UI::Xaml::Input::HoldingRoutedEventArgs *>(&e));
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
            shim().OnRightTapped(*reinterpret_cast<const Windows::UI::Xaml::Input::RightTappedRoutedEventArgs *>(&e));
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
            shim().OnManipulationStarting(*reinterpret_cast<const Windows::UI::Xaml::Input::ManipulationStartingRoutedEventArgs *>(&e));
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
            shim().OnManipulationInertiaStarting(*reinterpret_cast<const Windows::UI::Xaml::Input::ManipulationInertiaStartingRoutedEventArgs *>(&e));
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
            shim().OnManipulationStarted(*reinterpret_cast<const Windows::UI::Xaml::Input::ManipulationStartedRoutedEventArgs *>(&e));
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
            shim().OnManipulationDelta(*reinterpret_cast<const Windows::UI::Xaml::Input::ManipulationDeltaRoutedEventArgs *>(&e));
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
            shim().OnManipulationCompleted(*reinterpret_cast<const Windows::UI::Xaml::Input::ManipulationCompletedRoutedEventArgs *>(&e));
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
            shim().OnKeyUp(*reinterpret_cast<const Windows::UI::Xaml::Input::KeyRoutedEventArgs *>(&e));
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
            shim().OnKeyDown(*reinterpret_cast<const Windows::UI::Xaml::Input::KeyRoutedEventArgs *>(&e));
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
            shim().OnGotFocus(*reinterpret_cast<const Windows::UI::Xaml::RoutedEventArgs *>(&e));
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
            shim().OnLostFocus(*reinterpret_cast<const Windows::UI::Xaml::RoutedEventArgs *>(&e));
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
            shim().OnDragEnter(*reinterpret_cast<const Windows::UI::Xaml::DragEventArgs *>(&e));
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
            shim().OnDragLeave(*reinterpret_cast<const Windows::UI::Xaml::DragEventArgs *>(&e));
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
            shim().OnDragOver(*reinterpret_cast<const Windows::UI::Xaml::DragEventArgs *>(&e));
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
            shim().OnDrop(*reinterpret_cast<const Windows::UI::Xaml::DragEventArgs *>(&e));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D, typename A = ABI::Windows::UI::Xaml::Controls::IDataTemplateSelectorOverrides>
class IDataTemplateSelectorOverridesT : public A
{
    D & shim() noexcept { return *static_cast<D *>(this); }

public:

    using IDataTemplateSelectorOverrides = winrt::Windows::UI::Xaml::Controls::IDataTemplateSelectorOverrides;

    Windows::UI::Xaml::DataTemplate SelectTemplateCore(const Windows::IInspectable & item, const Windows::UI::Xaml::DependencyObject & container)
    {
        return shim().as<IDataTemplateSelectorOverrides>().SelectTemplateCore(item, container);
    }

    HRESULT __stdcall abi_SelectTemplateCore(abi_arg_in<Windows::IInspectable> item, abi_arg_in<Windows::UI::Xaml::IDependencyObject> container, abi_arg_out<Windows::UI::Xaml::IDataTemplate> returnValue) noexcept override
    {
        try
        {
            *returnValue = detach(shim().SelectTemplateCore(*reinterpret_cast<const Windows::IInspectable *>(&item), *reinterpret_cast<const Windows::UI::Xaml::DependencyObject *>(&container)));
            return S_OK;
        }
        catch (...)
        {
            *returnValue = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D, typename A = ABI::Windows::UI::Xaml::Controls::IDataTemplateSelectorOverrides2>
class IDataTemplateSelectorOverrides2T : public A
{
    D & shim() noexcept { return *static_cast<D *>(this); }

public:

    using IDataTemplateSelectorOverrides2 = winrt::Windows::UI::Xaml::Controls::IDataTemplateSelectorOverrides2;

    Windows::UI::Xaml::DataTemplate SelectTemplateCore(const Windows::IInspectable & item)
    {
        return shim().as<IDataTemplateSelectorOverrides2>().SelectTemplateCore(item);
    }

    HRESULT __stdcall abi_SelectTemplateForItemCore(abi_arg_in<Windows::IInspectable> item, abi_arg_out<Windows::UI::Xaml::IDataTemplate> returnValue) noexcept override
    {
        try
        {
            *returnValue = detach(shim().SelectTemplateCore(*reinterpret_cast<const Windows::IInspectable *>(&item)));
            return S_OK;
        }
        catch (...)
        {
            *returnValue = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D, typename A = ABI::Windows::UI::Xaml::Controls::IGroupStyleSelectorOverrides>
class IGroupStyleSelectorOverridesT : public A
{
    D & shim() noexcept { return *static_cast<D *>(this); }

public:

    using IGroupStyleSelectorOverrides = winrt::Windows::UI::Xaml::Controls::IGroupStyleSelectorOverrides;

    Windows::UI::Xaml::Controls::GroupStyle SelectGroupStyleCore(const Windows::IInspectable & group, uint32_t level)
    {
        return shim().as<IGroupStyleSelectorOverrides>().SelectGroupStyleCore(group, level);
    }

    HRESULT __stdcall abi_SelectGroupStyleCore(abi_arg_in<Windows::IInspectable> group, uint32_t level, abi_arg_out<Windows::UI::Xaml::Controls::IGroupStyle> returnValue) noexcept override
    {
        try
        {
            *returnValue = detach(shim().SelectGroupStyleCore(*reinterpret_cast<const Windows::IInspectable *>(&group), level));
            return S_OK;
        }
        catch (...)
        {
            *returnValue = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D, typename A = ABI::Windows::UI::Xaml::Controls::IInkToolbarCustomPenOverrides>
class IInkToolbarCustomPenOverridesT : public A
{
    D & shim() noexcept { return *static_cast<D *>(this); }

public:

    using IInkToolbarCustomPenOverrides = winrt::Windows::UI::Xaml::Controls::IInkToolbarCustomPenOverrides;

    Windows::UI::Input::Inking::InkDrawingAttributes CreateInkDrawingAttributesCore(const Windows::UI::Xaml::Media::Brush & brush, double strokeWidth)
    {
        return shim().as<IInkToolbarCustomPenOverrides>().CreateInkDrawingAttributesCore(brush, strokeWidth);
    }

    HRESULT __stdcall abi_CreateInkDrawingAttributesCore(abi_arg_in<Windows::UI::Xaml::Media::IBrush> brush, double strokeWidth, abi_arg_out<Windows::UI::Input::Inking::IInkDrawingAttributes> returnValue) noexcept override
    {
        try
        {
            *returnValue = detach(shim().CreateInkDrawingAttributesCore(*reinterpret_cast<const Windows::UI::Xaml::Media::Brush *>(&brush), strokeWidth));
            return S_OK;
        }
        catch (...)
        {
            *returnValue = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D, typename A = ABI::Windows::UI::Xaml::Controls::IItemsControlOverrides>
class IItemsControlOverridesT : public A
{
    D & shim() noexcept { return *static_cast<D *>(this); }

public:

    using IItemsControlOverrides = winrt::Windows::UI::Xaml::Controls::IItemsControlOverrides;

    bool IsItemItsOwnContainerOverride(const Windows::IInspectable & item)
    {
        return shim().as<IItemsControlOverrides>().IsItemItsOwnContainerOverride(item);
    }

    Windows::UI::Xaml::DependencyObject GetContainerForItemOverride()
    {
        return shim().as<IItemsControlOverrides>().GetContainerForItemOverride();
    }

    void ClearContainerForItemOverride(const Windows::UI::Xaml::DependencyObject & element, const Windows::IInspectable & item)
    {
        shim().as<IItemsControlOverrides>().ClearContainerForItemOverride(element, item);
    }

    void PrepareContainerForItemOverride(const Windows::UI::Xaml::DependencyObject & element, const Windows::IInspectable & item)
    {
        shim().as<IItemsControlOverrides>().PrepareContainerForItemOverride(element, item);
    }

    void OnItemsChanged(const Windows::IInspectable & e)
    {
        shim().as<IItemsControlOverrides>().OnItemsChanged(e);
    }

    void OnItemContainerStyleChanged(const Windows::UI::Xaml::Style & oldItemContainerStyle, const Windows::UI::Xaml::Style & newItemContainerStyle)
    {
        shim().as<IItemsControlOverrides>().OnItemContainerStyleChanged(oldItemContainerStyle, newItemContainerStyle);
    }

    void OnItemContainerStyleSelectorChanged(const Windows::UI::Xaml::Controls::StyleSelector & oldItemContainerStyleSelector, const Windows::UI::Xaml::Controls::StyleSelector & newItemContainerStyleSelector)
    {
        shim().as<IItemsControlOverrides>().OnItemContainerStyleSelectorChanged(oldItemContainerStyleSelector, newItemContainerStyleSelector);
    }

    void OnItemTemplateChanged(const Windows::UI::Xaml::DataTemplate & oldItemTemplate, const Windows::UI::Xaml::DataTemplate & newItemTemplate)
    {
        shim().as<IItemsControlOverrides>().OnItemTemplateChanged(oldItemTemplate, newItemTemplate);
    }

    void OnItemTemplateSelectorChanged(const Windows::UI::Xaml::Controls::DataTemplateSelector & oldItemTemplateSelector, const Windows::UI::Xaml::Controls::DataTemplateSelector & newItemTemplateSelector)
    {
        shim().as<IItemsControlOverrides>().OnItemTemplateSelectorChanged(oldItemTemplateSelector, newItemTemplateSelector);
    }

    void OnGroupStyleSelectorChanged(const Windows::UI::Xaml::Controls::GroupStyleSelector & oldGroupStyleSelector, const Windows::UI::Xaml::Controls::GroupStyleSelector & newGroupStyleSelector)
    {
        shim().as<IItemsControlOverrides>().OnGroupStyleSelectorChanged(oldGroupStyleSelector, newGroupStyleSelector);
    }

    HRESULT __stdcall abi_IsItemItsOwnContainerOverride(abi_arg_in<Windows::IInspectable> item, bool * returnValue) noexcept override
    {
        try
        {
            *returnValue = detach(shim().IsItemItsOwnContainerOverride(*reinterpret_cast<const Windows::IInspectable *>(&item)));
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
            *returnValue = detach(shim().GetContainerForItemOverride());
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
            shim().ClearContainerForItemOverride(*reinterpret_cast<const Windows::UI::Xaml::DependencyObject *>(&element), *reinterpret_cast<const Windows::IInspectable *>(&item));
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
            shim().PrepareContainerForItemOverride(*reinterpret_cast<const Windows::UI::Xaml::DependencyObject *>(&element), *reinterpret_cast<const Windows::IInspectable *>(&item));
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
            shim().OnItemsChanged(*reinterpret_cast<const Windows::IInspectable *>(&e));
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
            shim().OnItemContainerStyleChanged(*reinterpret_cast<const Windows::UI::Xaml::Style *>(&oldItemContainerStyle), *reinterpret_cast<const Windows::UI::Xaml::Style *>(&newItemContainerStyle));
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
            shim().OnItemContainerStyleSelectorChanged(*reinterpret_cast<const Windows::UI::Xaml::Controls::StyleSelector *>(&oldItemContainerStyleSelector), *reinterpret_cast<const Windows::UI::Xaml::Controls::StyleSelector *>(&newItemContainerStyleSelector));
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
            shim().OnItemTemplateChanged(*reinterpret_cast<const Windows::UI::Xaml::DataTemplate *>(&oldItemTemplate), *reinterpret_cast<const Windows::UI::Xaml::DataTemplate *>(&newItemTemplate));
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
            shim().OnItemTemplateSelectorChanged(*reinterpret_cast<const Windows::UI::Xaml::Controls::DataTemplateSelector *>(&oldItemTemplateSelector), *reinterpret_cast<const Windows::UI::Xaml::Controls::DataTemplateSelector *>(&newItemTemplateSelector));
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
            shim().OnGroupStyleSelectorChanged(*reinterpret_cast<const Windows::UI::Xaml::Controls::GroupStyleSelector *>(&oldGroupStyleSelector), *reinterpret_cast<const Windows::UI::Xaml::Controls::GroupStyleSelector *>(&newGroupStyleSelector));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D, typename A = ABI::Windows::UI::Xaml::Controls::IPageOverrides>
class IPageOverridesT : public A
{
    D & shim() noexcept { return *static_cast<D *>(this); }

public:

    using IPageOverrides = winrt::Windows::UI::Xaml::Controls::IPageOverrides;

    void OnNavigatedFrom(const Windows::UI::Xaml::Navigation::NavigationEventArgs & e)
    {
        shim().as<IPageOverrides>().OnNavigatedFrom(e);
    }

    void OnNavigatedTo(const Windows::UI::Xaml::Navigation::NavigationEventArgs & e)
    {
        shim().as<IPageOverrides>().OnNavigatedTo(e);
    }

    void OnNavigatingFrom(const Windows::UI::Xaml::Navigation::NavigatingCancelEventArgs & e)
    {
        shim().as<IPageOverrides>().OnNavigatingFrom(e);
    }

    HRESULT __stdcall abi_OnNavigatedFrom(abi_arg_in<Windows::UI::Xaml::Navigation::INavigationEventArgs> e) noexcept override
    {
        try
        {
            shim().OnNavigatedFrom(*reinterpret_cast<const Windows::UI::Xaml::Navigation::NavigationEventArgs *>(&e));
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
            shim().OnNavigatedTo(*reinterpret_cast<const Windows::UI::Xaml::Navigation::NavigationEventArgs *>(&e));
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
            shim().OnNavigatingFrom(*reinterpret_cast<const Windows::UI::Xaml::Navigation::NavigatingCancelEventArgs *>(&e));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D, typename A = ABI::Windows::UI::Xaml::Controls::IStyleSelectorOverrides>
class IStyleSelectorOverridesT : public A
{
    D & shim() noexcept { return *static_cast<D *>(this); }

public:

    using IStyleSelectorOverrides = winrt::Windows::UI::Xaml::Controls::IStyleSelectorOverrides;

    Windows::UI::Xaml::Style SelectStyleCore(const Windows::IInspectable & item, const Windows::UI::Xaml::DependencyObject & container)
    {
        return shim().as<IStyleSelectorOverrides>().SelectStyleCore(item, container);
    }

    HRESULT __stdcall abi_SelectStyleCore(abi_arg_in<Windows::IInspectable> item, abi_arg_in<Windows::UI::Xaml::IDependencyObject> container, abi_arg_out<Windows::UI::Xaml::IStyle> returnValue) noexcept override
    {
        try
        {
            *returnValue = detach(shim().SelectStyleCore(*reinterpret_cast<const Windows::IInspectable *>(&item), *reinterpret_cast<const Windows::UI::Xaml::DependencyObject *>(&container)));
            return S_OK;
        }
        catch (...)
        {
            *returnValue = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D, typename A = ABI::Windows::UI::Xaml::Controls::IToggleSwitchOverrides>
class IToggleSwitchOverridesT : public A
{
    D & shim() noexcept { return *static_cast<D *>(this); }

public:

    using IToggleSwitchOverrides = winrt::Windows::UI::Xaml::Controls::IToggleSwitchOverrides;

    void OnToggled()
    {
        shim().as<IToggleSwitchOverrides>().OnToggled();
    }

    void OnOnContentChanged(const Windows::IInspectable & oldContent, const Windows::IInspectable & newContent)
    {
        shim().as<IToggleSwitchOverrides>().OnOnContentChanged(oldContent, newContent);
    }

    void OnOffContentChanged(const Windows::IInspectable & oldContent, const Windows::IInspectable & newContent)
    {
        shim().as<IToggleSwitchOverrides>().OnOffContentChanged(oldContent, newContent);
    }

    void OnHeaderChanged(const Windows::IInspectable & oldContent, const Windows::IInspectable & newContent)
    {
        shim().as<IToggleSwitchOverrides>().OnHeaderChanged(oldContent, newContent);
    }

    HRESULT __stdcall abi_OnToggled() noexcept override
    {
        try
        {
            shim().OnToggled();
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
            shim().OnOnContentChanged(*reinterpret_cast<const Windows::IInspectable *>(&oldContent), *reinterpret_cast<const Windows::IInspectable *>(&newContent));
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
            shim().OnOffContentChanged(*reinterpret_cast<const Windows::IInspectable *>(&oldContent), *reinterpret_cast<const Windows::IInspectable *>(&newContent));
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
            shim().OnHeaderChanged(*reinterpret_cast<const Windows::IInspectable *>(&oldContent), *reinterpret_cast<const Windows::IInspectable *>(&newContent));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D, typename A = ABI::Windows::UI::Xaml::Controls::IVirtualizingPanelOverrides>
class IVirtualizingPanelOverridesT : public A
{
    D & shim() noexcept { return *static_cast<D *>(this); }

public:

    using IVirtualizingPanelOverrides = winrt::Windows::UI::Xaml::Controls::IVirtualizingPanelOverrides;

    void OnItemsChanged(const Windows::IInspectable & sender, const Windows::UI::Xaml::Controls::Primitives::ItemsChangedEventArgs & args)
    {
        shim().as<IVirtualizingPanelOverrides>().OnItemsChanged(sender, args);
    }

    void OnClearChildren()
    {
        shim().as<IVirtualizingPanelOverrides>().OnClearChildren();
    }

    void BringIndexIntoView(int32_t index)
    {
        shim().as<IVirtualizingPanelOverrides>().BringIndexIntoView(index);
    }

    HRESULT __stdcall abi_OnItemsChanged(abi_arg_in<Windows::IInspectable> sender, abi_arg_in<Windows::UI::Xaml::Controls::Primitives::IItemsChangedEventArgs> args) noexcept override
    {
        try
        {
            shim().OnItemsChanged(*reinterpret_cast<const Windows::IInspectable *>(&sender), *reinterpret_cast<const Windows::UI::Xaml::Controls::Primitives::ItemsChangedEventArgs *>(&args));
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
            shim().OnClearChildren();
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
            shim().BringIndexIntoView(index);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D, typename A = ABI::Windows::UI::Xaml::Controls::IVirtualizingStackPanelOverrides>
class IVirtualizingStackPanelOverridesT : public A
{
    D & shim() noexcept { return *static_cast<D *>(this); }

public:

    using IVirtualizingStackPanelOverrides = winrt::Windows::UI::Xaml::Controls::IVirtualizingStackPanelOverrides;

    void OnCleanUpVirtualizedItem(const Windows::UI::Xaml::Controls::CleanUpVirtualizedItemEventArgs & e)
    {
        shim().as<IVirtualizingStackPanelOverrides>().OnCleanUpVirtualizedItem(e);
    }

    HRESULT __stdcall abi_OnCleanUpVirtualizedItem(abi_arg_in<Windows::UI::Xaml::Controls::ICleanUpVirtualizedItemEventArgs> e) noexcept override
    {
        try
        {
            shim().OnCleanUpVirtualizedItem(*reinterpret_cast<const Windows::UI::Xaml::Controls::CleanUpVirtualizedItemEventArgs *>(&e));
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

template <typename D, typename A = ABI::Windows::UI::Xaml::Controls::Primitives::IFlyoutBaseOverrides>
class IFlyoutBaseOverridesT : public A
{
    D & shim() noexcept { return *static_cast<D *>(this); }

public:

    using IFlyoutBaseOverrides = winrt::Windows::UI::Xaml::Controls::Primitives::IFlyoutBaseOverrides;

    Windows::UI::Xaml::Controls::Control CreatePresenter()
    {
        return shim().as<IFlyoutBaseOverrides>().CreatePresenter();
    }

    HRESULT __stdcall abi_CreatePresenter(abi_arg_out<Windows::UI::Xaml::Controls::IControl> returnValue) noexcept override
    {
        try
        {
            *returnValue = detach(shim().CreatePresenter());
            return S_OK;
        }
        catch (...)
        {
            *returnValue = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D, typename A = ABI::Windows::UI::Xaml::Controls::Primitives::IPickerFlyoutBaseOverrides>
class IPickerFlyoutBaseOverridesT : public A
{
    D & shim() noexcept { return *static_cast<D *>(this); }

public:

    using IPickerFlyoutBaseOverrides = winrt::Windows::UI::Xaml::Controls::Primitives::IPickerFlyoutBaseOverrides;

    void OnConfirmed()
    {
        shim().as<IPickerFlyoutBaseOverrides>().OnConfirmed();
    }

    bool ShouldShowConfirmationButtons()
    {
        return shim().as<IPickerFlyoutBaseOverrides>().ShouldShowConfirmationButtons();
    }

    HRESULT __stdcall abi_OnConfirmed() noexcept override
    {
        try
        {
            shim().OnConfirmed();
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
            *returnValue = detach(shim().ShouldShowConfirmationButtons());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D, typename A = ABI::Windows::UI::Xaml::Controls::Primitives::IRangeBaseOverrides>
class IRangeBaseOverridesT : public A
{
    D & shim() noexcept { return *static_cast<D *>(this); }

public:

    using IRangeBaseOverrides = winrt::Windows::UI::Xaml::Controls::Primitives::IRangeBaseOverrides;

    void OnMinimumChanged(double oldMinimum, double newMinimum)
    {
        shim().as<IRangeBaseOverrides>().OnMinimumChanged(oldMinimum, newMinimum);
    }

    void OnMaximumChanged(double oldMaximum, double newMaximum)
    {
        shim().as<IRangeBaseOverrides>().OnMaximumChanged(oldMaximum, newMaximum);
    }

    void OnValueChanged(double oldValue, double newValue)
    {
        shim().as<IRangeBaseOverrides>().OnValueChanged(oldValue, newValue);
    }

    HRESULT __stdcall abi_OnMinimumChanged(double oldMinimum, double newMinimum) noexcept override
    {
        try
        {
            shim().OnMinimumChanged(oldMinimum, newMinimum);
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
            shim().OnMaximumChanged(oldMaximum, newMaximum);
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
            shim().OnValueChanged(oldValue, newValue);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D, typename A = ABI::Windows::UI::Xaml::Controls::Primitives::IToggleButtonOverrides>
class IToggleButtonOverridesT : public A
{
    D & shim() noexcept { return *static_cast<D *>(this); }

public:

    using IToggleButtonOverrides = winrt::Windows::UI::Xaml::Controls::Primitives::IToggleButtonOverrides;

    void OnToggle()
    {
        shim().as<IToggleButtonOverrides>().OnToggle();
    }

    HRESULT __stdcall abi_OnToggle() noexcept override
    {
        try
        {
            shim().OnToggle();
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

template <typename D, typename A = ABI::Windows::UI::Xaml::Documents::ITextElementOverrides>
class ITextElementOverridesT : public A
{
    D & shim() noexcept { return *static_cast<D *>(this); }

public:

    using ITextElementOverrides = winrt::Windows::UI::Xaml::Documents::ITextElementOverrides;

    void OnDisconnectVisualChildren()
    {
        shim().as<ITextElementOverrides>().OnDisconnectVisualChildren();
    }

    HRESULT __stdcall abi_OnDisconnectVisualChildren() noexcept override
    {
        try
        {
            shim().OnDisconnectVisualChildren();
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

template <typename D, typename A = ABI::Windows::UI::Xaml::Media::IGeneralTransformOverrides>
class IGeneralTransformOverridesT : public A
{
    D & shim() noexcept { return *static_cast<D *>(this); }

public:

    using IGeneralTransformOverrides = winrt::Windows::UI::Xaml::Media::IGeneralTransformOverrides;

    Windows::UI::Xaml::Media::GeneralTransform InverseCore()
    {
        return shim().as<IGeneralTransformOverrides>().InverseCore();
    }

    bool TryTransformCore(const Windows::Foundation::Point & inPoint, Windows::Foundation::Point & outPoint)
    {
        return shim().as<IGeneralTransformOverrides>().TryTransformCore(inPoint, outPoint);
    }

    Windows::Foundation::Rect TransformBoundsCore(const Windows::Foundation::Rect & rect)
    {
        return shim().as<IGeneralTransformOverrides>().TransformBoundsCore(rect);
    }

    HRESULT __stdcall get_InverseCore(abi_arg_out<Windows::UI::Xaml::Media::IGeneralTransform> value) noexcept override
    {
        try
        {
            *value = detach(shim().InverseCore());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_TryTransformCore(abi_arg_in<Windows::Foundation::Point> inPoint, abi_arg_out<Windows::Foundation::Point> outPoint, bool * returnValue) noexcept override
    {
        try
        {
            *returnValue = detach(shim().TryTransformCore(*reinterpret_cast<const Windows::Foundation::Point *>(&inPoint), *outPoint));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_TransformBoundsCore(abi_arg_in<Windows::Foundation::Rect> rect, abi_arg_out<Windows::Foundation::Rect> returnValue) noexcept override
    {
        try
        {
            *returnValue = detach(shim().TransformBoundsCore(*reinterpret_cast<const Windows::Foundation::Rect *>(&rect)));
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

template <typename D, typename A = ABI::Windows::UI::Xaml::Media::Animation::INavigationTransitionInfoOverrides>
class INavigationTransitionInfoOverridesT : public A
{
    D & shim() noexcept { return *static_cast<D *>(this); }

public:

    using INavigationTransitionInfoOverrides = winrt::Windows::UI::Xaml::Media::Animation::INavigationTransitionInfoOverrides;

    hstring GetNavigationStateCore()
    {
        return shim().as<INavigationTransitionInfoOverrides>().GetNavigationStateCore();
    }

    void SetNavigationStateCore(hstring_ref navigationState)
    {
        shim().as<INavigationTransitionInfoOverrides>().SetNavigationStateCore(navigationState);
    }

    HRESULT __stdcall abi_GetNavigationStateCore(abi_arg_out<hstring> returnValue) noexcept override
    {
        try
        {
            *returnValue = detach(shim().GetNavigationStateCore());
            return S_OK;
        }
        catch (...)
        {
            *returnValue = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_SetNavigationStateCore(abi_arg_in<hstring> navigationState) noexcept override
    {
        try
        {
            shim().SetNavigationStateCore(*reinterpret_cast<const hstring *>(&navigationState));
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

template <typename D, typename A = ABI::Windows::UI::Xaml::Media::Imaging::IXamlRenderingBackgroundTaskOverrides>
class IXamlRenderingBackgroundTaskOverridesT : public A
{
    D & shim() noexcept { return *static_cast<D *>(this); }

public:

    using IXamlRenderingBackgroundTaskOverrides = winrt::Windows::UI::Xaml::Media::Imaging::IXamlRenderingBackgroundTaskOverrides;

    void OnRun(const Windows::ApplicationModel::Background::IBackgroundTaskInstance & taskInstance)
    {
        shim().as<IXamlRenderingBackgroundTaskOverrides>().OnRun(taskInstance);
    }

    HRESULT __stdcall abi_OnRun(abi_arg_in<Windows::ApplicationModel::Background::IBackgroundTaskInstance> taskInstance) noexcept override
    {
        try
        {
            shim().OnRun(*reinterpret_cast<const Windows::ApplicationModel::Background::IBackgroundTaskInstance *>(&taskInstance));
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

template <typename D, typename A = ABI::Windows::UI::Xaml::Resources::ICustomXamlResourceLoaderOverrides>
class ICustomXamlResourceLoaderOverridesT : public A
{
    D & shim() noexcept { return *static_cast<D *>(this); }

public:

    using ICustomXamlResourceLoaderOverrides = winrt::Windows::UI::Xaml::Resources::ICustomXamlResourceLoaderOverrides;

    Windows::IInspectable GetResource(hstring_ref resourceId, hstring_ref objectType, hstring_ref propertyName, hstring_ref propertyType)
    {
        return shim().as<ICustomXamlResourceLoaderOverrides>().GetResource(resourceId, objectType, propertyName, propertyType);
    }

    HRESULT __stdcall abi_GetResource(abi_arg_in<hstring> resourceId, abi_arg_in<hstring> objectType, abi_arg_in<hstring> propertyName, abi_arg_in<hstring> propertyType, abi_arg_out<Windows::IInspectable> returnValue) noexcept override
    {
        try
        {
            *returnValue = detach(shim().GetResource(*reinterpret_cast<const hstring *>(&resourceId), *reinterpret_cast<const hstring *>(&objectType), *reinterpret_cast<const hstring *>(&propertyName), *reinterpret_cast<const hstring *>(&propertyType)));
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

template <typename D, typename ... Interfaces> struct AdaptiveTriggerT :
    overrides<D, Windows::IInspectable, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IStateTriggerBase, Windows::UI::Xaml::IStateTriggerBaseProtected, Windows::UI::Xaml::IAdaptiveTrigger>
{
    using composable = AdaptiveTrigger;

protected:

    AdaptiveTriggerT()
    {
        GetActivationFactory<AdaptiveTrigger, IAdaptiveTriggerFactory>().CreateInstance(*this, m_inner);
    }
};

template <typename D, typename ... Interfaces> struct ApplicationT :
    overrides<D, Windows::UI::Xaml::IApplicationOverridesT<D>, Windows::UI::Xaml::IApplicationOverrides2T<D>, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::IApplication, Windows::UI::Xaml::IApplication2>
{
    using composable = Application;

protected:

    ApplicationT()
    {
        GetActivationFactory<Application, IApplicationFactory>().CreateInstance(*this, m_inner);
    }
};

template <typename D, typename ... Interfaces> struct DataTemplateT :
    overrides<D, Windows::IInspectable, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IFrameworkTemplate, Windows::UI::Xaml::IDataTemplate>
{
    using composable = DataTemplate;

protected:

    DataTemplateT()
    {
        GetActivationFactory<DataTemplate, IDataTemplateFactory>().CreateInstance(*this, m_inner);
    }
};

template <typename D, typename ... Interfaces> struct DataTemplateKeyT :
    overrides<D, Windows::IInspectable, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::IDataTemplateKey>
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

template <typename D, typename ... Interfaces> struct DependencyObjectT :
    overrides<D, Windows::IInspectable, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2>
{
    using composable = DependencyObject;

protected:

    DependencyObjectT()
    {
        GetActivationFactory<DependencyObject, IDependencyObjectFactory>().CreateInstance(*this, m_inner);
    }
};

template <typename D, typename ... Interfaces> struct DependencyObjectCollectionT :
    overrides<D, Windows::IInspectable, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::Foundation::Collections::IObservableVector<Windows::UI::Xaml::DependencyObject>>
{
    using composable = DependencyObjectCollection;

protected:

    DependencyObjectCollectionT()
    {
        GetActivationFactory<DependencyObjectCollection, IDependencyObjectCollectionFactory>().CreateInstance(*this, m_inner);
    }
};

template <typename D, typename ... Interfaces> struct DispatcherTimerT :
    overrides<D, Windows::IInspectable, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::IDispatcherTimer>
{
    using composable = DispatcherTimer;

protected:

    DispatcherTimerT()
    {
        GetActivationFactory<DispatcherTimer, IDispatcherTimerFactory>().CreateInstance(*this, m_inner);
    }
};

template <typename D, typename ... Interfaces> struct FrameworkElementT :
    overrides<D, Windows::UI::Xaml::IUIElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverrides2T<D>, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IUIElement4, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::IFrameworkElement4>
{
    using composable = FrameworkElement;

protected:

    FrameworkElementT()
    {
        GetActivationFactory<FrameworkElement, IFrameworkElementFactory>().CreateInstance(*this, m_inner);
    }
};

template <typename D, typename ... Interfaces> struct FrameworkTemplateT :
    overrides<D, Windows::IInspectable, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IFrameworkTemplate>
{
    using composable = FrameworkTemplate;

protected:

    FrameworkTemplateT()
    {
        GetActivationFactory<FrameworkTemplate, IFrameworkTemplateFactory>().CreateInstance(*this, m_inner);
    }
};

template <typename D, typename ... Interfaces> struct PropertyMetadataT :
    overrides<D, Windows::IInspectable, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::IPropertyMetadata>
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

template <typename D, typename ... Interfaces> struct ResourceDictionaryT :
    overrides<D, Windows::IInspectable, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IResourceDictionary, Windows::Foundation::Collections::IMap<Windows::IInspectable, Windows::IInspectable>, Windows::Foundation::Collections::IIterable<Windows::Foundation::Collections::IKeyValuePair<Windows::IInspectable, Windows::IInspectable>>>
{
    using composable = ResourceDictionary;

protected:

    ResourceDictionaryT()
    {
        GetActivationFactory<ResourceDictionary, IResourceDictionaryFactory>().CreateInstance(*this, m_inner);
    }
};

template <typename D, typename ... Interfaces> struct RoutedEventArgsT :
    overrides<D, Windows::IInspectable, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::IRoutedEventArgs>
{
    using composable = RoutedEventArgs;

protected:

    RoutedEventArgsT()
    {
        GetActivationFactory<RoutedEventArgs, IRoutedEventArgsFactory>().CreateInstance(*this, m_inner);
    }
};

template <typename D, typename ... Interfaces> struct StateTriggerBaseT :
    overrides<D, Windows::IInspectable, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IStateTriggerBase, Windows::UI::Xaml::IStateTriggerBaseProtected>
{
    using composable = StateTriggerBase;

protected:

    StateTriggerBaseT()
    {
        GetActivationFactory<StateTriggerBase, IStateTriggerBaseFactory>().CreateInstance(*this, m_inner);
    }
};

template <typename D, typename ... Interfaces> struct VisualStateManagerT :
    overrides<D, Windows::UI::Xaml::IVisualStateManagerOverridesT<D>, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IVisualStateManager, Windows::UI::Xaml::IVisualStateManagerProtected>
{
    using composable = VisualStateManager;

protected:

    VisualStateManagerT()
    {
        GetActivationFactory<VisualStateManager, IVisualStateManagerFactory>().CreateInstance(*this, m_inner);
    }
};

template <typename D, typename ... Interfaces> struct VisualTransitionT :
    overrides<D, Windows::IInspectable, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IVisualTransition>
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

template <typename D, typename ... Interfaces> struct AppBarAutomationPeerT :
    overrides<D, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverridesT<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2T<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3T<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides4T<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides5T<D>, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer, Windows::UI::Xaml::Automation::Peers::IAutomationPeerProtected, Windows::UI::Xaml::Automation::Peers::IAutomationPeer2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer3, Windows::UI::Xaml::Automation::Peers::IAutomationPeer4, Windows::UI::Xaml::Automation::Peers::IAutomationPeer5, Windows::UI::Xaml::Automation::Peers::IFrameworkElementAutomationPeer, Windows::UI::Xaml::Automation::Peers::IAppBarAutomationPeer, Windows::UI::Xaml::Automation::Provider::IToggleProvider, Windows::UI::Xaml::Automation::Provider::IExpandCollapseProvider, Windows::UI::Xaml::Automation::Provider::IWindowProvider>
{
    using composable = AppBarAutomationPeer;

protected:

    AppBarAutomationPeerT(const Windows::UI::Xaml::Controls::AppBar & owner)
    {
        GetActivationFactory<AppBarAutomationPeer, IAppBarAutomationPeerFactory>().CreateInstanceWithOwner(owner, *this, m_inner);
    }
};

template <typename D, typename ... Interfaces> struct AppBarButtonAutomationPeerT :
    overrides<D, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverridesT<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2T<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3T<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides4T<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides5T<D>, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer, Windows::UI::Xaml::Automation::Peers::IAutomationPeerProtected, Windows::UI::Xaml::Automation::Peers::IAutomationPeer2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer3, Windows::UI::Xaml::Automation::Peers::IAutomationPeer4, Windows::UI::Xaml::Automation::Peers::IAutomationPeer5, Windows::UI::Xaml::Automation::Peers::IFrameworkElementAutomationPeer, Windows::UI::Xaml::Automation::Peers::IButtonBaseAutomationPeer, Windows::UI::Xaml::Automation::Peers::IButtonAutomationPeer, Windows::UI::Xaml::Automation::Provider::IInvokeProvider, Windows::UI::Xaml::Automation::Peers::IAppBarButtonAutomationPeer>
{
    using composable = AppBarButtonAutomationPeer;

protected:

    AppBarButtonAutomationPeerT(const Windows::UI::Xaml::Controls::AppBarButton & owner)
    {
        GetActivationFactory<AppBarButtonAutomationPeer, IAppBarButtonAutomationPeerFactory>().CreateInstanceWithOwner(owner, *this, m_inner);
    }
};

template <typename D, typename ... Interfaces> struct AppBarToggleButtonAutomationPeerT :
    overrides<D, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverridesT<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2T<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3T<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides4T<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides5T<D>, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer, Windows::UI::Xaml::Automation::Peers::IAutomationPeerProtected, Windows::UI::Xaml::Automation::Peers::IAutomationPeer2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer3, Windows::UI::Xaml::Automation::Peers::IAutomationPeer4, Windows::UI::Xaml::Automation::Peers::IAutomationPeer5, Windows::UI::Xaml::Automation::Peers::IFrameworkElementAutomationPeer, Windows::UI::Xaml::Automation::Peers::IButtonBaseAutomationPeer, Windows::UI::Xaml::Automation::Peers::IToggleButtonAutomationPeer, Windows::UI::Xaml::Automation::Provider::IToggleProvider, Windows::UI::Xaml::Automation::Peers::IAppBarToggleButtonAutomationPeer>
{
    using composable = AppBarToggleButtonAutomationPeer;

protected:

    AppBarToggleButtonAutomationPeerT(const Windows::UI::Xaml::Controls::AppBarToggleButton & owner)
    {
        GetActivationFactory<AppBarToggleButtonAutomationPeer, IAppBarToggleButtonAutomationPeerFactory>().CreateInstanceWithOwner(owner, *this, m_inner);
    }
};

template <typename D, typename ... Interfaces> struct AutomationPeerT :
    overrides<D, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverridesT<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2T<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3T<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides4T<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides5T<D>, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer, Windows::UI::Xaml::Automation::Peers::IAutomationPeerProtected, Windows::UI::Xaml::Automation::Peers::IAutomationPeer2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer3, Windows::UI::Xaml::Automation::Peers::IAutomationPeer4, Windows::UI::Xaml::Automation::Peers::IAutomationPeer5>
{
    using composable = AutomationPeer;

protected:

    AutomationPeerT()
    {
        GetActivationFactory<AutomationPeer, IAutomationPeerFactory>().CreateInstance(*this, m_inner);
    }
};

template <typename D, typename ... Interfaces> struct ButtonAutomationPeerT :
    overrides<D, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverridesT<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2T<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3T<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides4T<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides5T<D>, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer, Windows::UI::Xaml::Automation::Peers::IAutomationPeerProtected, Windows::UI::Xaml::Automation::Peers::IAutomationPeer2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer3, Windows::UI::Xaml::Automation::Peers::IAutomationPeer4, Windows::UI::Xaml::Automation::Peers::IAutomationPeer5, Windows::UI::Xaml::Automation::Peers::IFrameworkElementAutomationPeer, Windows::UI::Xaml::Automation::Peers::IButtonBaseAutomationPeer, Windows::UI::Xaml::Automation::Peers::IButtonAutomationPeer, Windows::UI::Xaml::Automation::Provider::IInvokeProvider>
{
    using composable = ButtonAutomationPeer;

protected:

    ButtonAutomationPeerT(const Windows::UI::Xaml::Controls::Button & owner)
    {
        GetActivationFactory<ButtonAutomationPeer, IButtonAutomationPeerFactory>().CreateInstanceWithOwner(owner, *this, m_inner);
    }
};

template <typename D, typename ... Interfaces> struct ButtonBaseAutomationPeerT :
    overrides<D, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverridesT<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2T<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3T<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides4T<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides5T<D>, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer, Windows::UI::Xaml::Automation::Peers::IAutomationPeerProtected, Windows::UI::Xaml::Automation::Peers::IAutomationPeer2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer3, Windows::UI::Xaml::Automation::Peers::IAutomationPeer4, Windows::UI::Xaml::Automation::Peers::IAutomationPeer5, Windows::UI::Xaml::Automation::Peers::IFrameworkElementAutomationPeer, Windows::UI::Xaml::Automation::Peers::IButtonBaseAutomationPeer>
{
    using composable = ButtonBaseAutomationPeer;

protected:

    ButtonBaseAutomationPeerT(const Windows::UI::Xaml::Controls::Primitives::ButtonBase & owner)
    {
        GetActivationFactory<ButtonBaseAutomationPeer, IButtonBaseAutomationPeerFactory>().CreateInstanceWithOwner(owner, *this, m_inner);
    }
};

template <typename D, typename ... Interfaces> struct CaptureElementAutomationPeerT :
    overrides<D, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverridesT<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2T<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3T<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides4T<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides5T<D>, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer, Windows::UI::Xaml::Automation::Peers::IAutomationPeerProtected, Windows::UI::Xaml::Automation::Peers::IAutomationPeer2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer3, Windows::UI::Xaml::Automation::Peers::IAutomationPeer4, Windows::UI::Xaml::Automation::Peers::IAutomationPeer5, Windows::UI::Xaml::Automation::Peers::IFrameworkElementAutomationPeer, Windows::UI::Xaml::Automation::Peers::ICaptureElementAutomationPeer>
{
    using composable = CaptureElementAutomationPeer;

protected:

    CaptureElementAutomationPeerT(const Windows::UI::Xaml::Controls::CaptureElement & owner)
    {
        GetActivationFactory<CaptureElementAutomationPeer, ICaptureElementAutomationPeerFactory>().CreateInstanceWithOwner(owner, *this, m_inner);
    }
};

template <typename D, typename ... Interfaces> struct CheckBoxAutomationPeerT :
    overrides<D, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverridesT<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2T<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3T<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides4T<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides5T<D>, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer, Windows::UI::Xaml::Automation::Peers::IAutomationPeerProtected, Windows::UI::Xaml::Automation::Peers::IAutomationPeer2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer3, Windows::UI::Xaml::Automation::Peers::IAutomationPeer4, Windows::UI::Xaml::Automation::Peers::IAutomationPeer5, Windows::UI::Xaml::Automation::Peers::IFrameworkElementAutomationPeer, Windows::UI::Xaml::Automation::Peers::IButtonBaseAutomationPeer, Windows::UI::Xaml::Automation::Peers::IToggleButtonAutomationPeer, Windows::UI::Xaml::Automation::Provider::IToggleProvider, Windows::UI::Xaml::Automation::Peers::ICheckBoxAutomationPeer>
{
    using composable = CheckBoxAutomationPeer;

protected:

    CheckBoxAutomationPeerT(const Windows::UI::Xaml::Controls::CheckBox & owner)
    {
        GetActivationFactory<CheckBoxAutomationPeer, ICheckBoxAutomationPeerFactory>().CreateInstanceWithOwner(owner, *this, m_inner);
    }
};

template <typename D, typename ... Interfaces> struct ComboBoxAutomationPeerT :
    overrides<D, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverridesT<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2T<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3T<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides4T<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides5T<D>, Windows::UI::Xaml::Automation::Peers::IItemsControlAutomationPeerOverrides2T<D>, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer, Windows::UI::Xaml::Automation::Peers::IAutomationPeerProtected, Windows::UI::Xaml::Automation::Peers::IAutomationPeer2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer3, Windows::UI::Xaml::Automation::Peers::IAutomationPeer4, Windows::UI::Xaml::Automation::Peers::IAutomationPeer5, Windows::UI::Xaml::Automation::Peers::IFrameworkElementAutomationPeer, Windows::UI::Xaml::Automation::Peers::IItemsControlAutomationPeer, Windows::UI::Xaml::Automation::Provider::IItemContainerProvider, Windows::UI::Xaml::Automation::Peers::IItemsControlAutomationPeer2, Windows::UI::Xaml::Automation::Peers::ISelectorAutomationPeer, Windows::UI::Xaml::Automation::Provider::ISelectionProvider, Windows::UI::Xaml::Automation::Peers::IComboBoxAutomationPeer, Windows::UI::Xaml::Automation::Provider::IExpandCollapseProvider, Windows::UI::Xaml::Automation::Provider::IValueProvider, Windows::UI::Xaml::Automation::Provider::IWindowProvider>
{
    using composable = ComboBoxAutomationPeer;

protected:

    ComboBoxAutomationPeerT(const Windows::UI::Xaml::Controls::ComboBox & owner)
    {
        GetActivationFactory<ComboBoxAutomationPeer, IComboBoxAutomationPeerFactory>().CreateInstanceWithOwner(owner, *this, m_inner);
    }
};

template <typename D, typename ... Interfaces> struct ComboBoxItemAutomationPeerT :
    overrides<D, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverridesT<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2T<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3T<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides4T<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides5T<D>, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer, Windows::UI::Xaml::Automation::Peers::IAutomationPeerProtected, Windows::UI::Xaml::Automation::Peers::IAutomationPeer2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer3, Windows::UI::Xaml::Automation::Peers::IAutomationPeer4, Windows::UI::Xaml::Automation::Peers::IAutomationPeer5, Windows::UI::Xaml::Automation::Peers::IFrameworkElementAutomationPeer, Windows::UI::Xaml::Automation::Peers::IComboBoxItemAutomationPeer>
{
    using composable = ComboBoxItemAutomationPeer;

protected:

    ComboBoxItemAutomationPeerT(const Windows::UI::Xaml::Controls::ComboBoxItem & owner)
    {
        GetActivationFactory<ComboBoxItemAutomationPeer, IComboBoxItemAutomationPeerFactory>().CreateInstanceWithOwner(owner, *this, m_inner);
    }
};

template <typename D, typename ... Interfaces> struct ComboBoxItemDataAutomationPeerT :
    overrides<D, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverridesT<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2T<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3T<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides4T<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides5T<D>, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer, Windows::UI::Xaml::Automation::Peers::IAutomationPeerProtected, Windows::UI::Xaml::Automation::Peers::IAutomationPeer2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer3, Windows::UI::Xaml::Automation::Peers::IAutomationPeer4, Windows::UI::Xaml::Automation::Peers::IAutomationPeer5, Windows::UI::Xaml::Automation::Peers::IItemAutomationPeer, Windows::UI::Xaml::Automation::Provider::IVirtualizedItemProvider, Windows::UI::Xaml::Automation::Peers::ISelectorItemAutomationPeer, Windows::UI::Xaml::Automation::Provider::ISelectionItemProvider, Windows::UI::Xaml::Automation::Peers::IComboBoxItemDataAutomationPeer, Windows::UI::Xaml::Automation::Provider::IScrollItemProvider>
{
    using composable = ComboBoxItemDataAutomationPeer;

protected:

    ComboBoxItemDataAutomationPeerT(const Windows::IInspectable & item, const Windows::UI::Xaml::Automation::Peers::ComboBoxAutomationPeer & parent)
    {
        GetActivationFactory<ComboBoxItemDataAutomationPeer, IComboBoxItemDataAutomationPeerFactory>().CreateInstanceWithParentAndItem(item, parent, *this, m_inner);
    }
};

template <typename D, typename ... Interfaces> struct DatePickerAutomationPeerT :
    overrides<D, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverridesT<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2T<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3T<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides4T<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides5T<D>, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer, Windows::UI::Xaml::Automation::Peers::IAutomationPeerProtected, Windows::UI::Xaml::Automation::Peers::IAutomationPeer2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer3, Windows::UI::Xaml::Automation::Peers::IAutomationPeer4, Windows::UI::Xaml::Automation::Peers::IAutomationPeer5, Windows::UI::Xaml::Automation::Peers::IFrameworkElementAutomationPeer, Windows::UI::Xaml::Automation::Peers::IDatePickerAutomationPeer>
{
    using composable = DatePickerAutomationPeer;

protected:

    DatePickerAutomationPeerT(const Windows::UI::Xaml::Controls::DatePicker & owner)
    {
        GetActivationFactory<DatePickerAutomationPeer, IDatePickerAutomationPeerFactory>().CreateInstanceWithOwner(owner, *this, m_inner);
    }
};

template <typename D, typename ... Interfaces> struct FlipViewAutomationPeerT :
    overrides<D, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverridesT<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2T<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3T<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides4T<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides5T<D>, Windows::UI::Xaml::Automation::Peers::IItemsControlAutomationPeerOverrides2T<D>, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer, Windows::UI::Xaml::Automation::Peers::IAutomationPeerProtected, Windows::UI::Xaml::Automation::Peers::IAutomationPeer2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer3, Windows::UI::Xaml::Automation::Peers::IAutomationPeer4, Windows::UI::Xaml::Automation::Peers::IAutomationPeer5, Windows::UI::Xaml::Automation::Peers::IFrameworkElementAutomationPeer, Windows::UI::Xaml::Automation::Peers::IItemsControlAutomationPeer, Windows::UI::Xaml::Automation::Provider::IItemContainerProvider, Windows::UI::Xaml::Automation::Peers::IItemsControlAutomationPeer2, Windows::UI::Xaml::Automation::Peers::ISelectorAutomationPeer, Windows::UI::Xaml::Automation::Provider::ISelectionProvider, Windows::UI::Xaml::Automation::Peers::IFlipViewAutomationPeer>
{
    using composable = FlipViewAutomationPeer;

protected:

    FlipViewAutomationPeerT(const Windows::UI::Xaml::Controls::FlipView & owner)
    {
        GetActivationFactory<FlipViewAutomationPeer, IFlipViewAutomationPeerFactory>().CreateInstanceWithOwner(owner, *this, m_inner);
    }
};

template <typename D, typename ... Interfaces> struct FlipViewItemAutomationPeerT :
    overrides<D, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverridesT<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2T<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3T<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides4T<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides5T<D>, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer, Windows::UI::Xaml::Automation::Peers::IAutomationPeerProtected, Windows::UI::Xaml::Automation::Peers::IAutomationPeer2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer3, Windows::UI::Xaml::Automation::Peers::IAutomationPeer4, Windows::UI::Xaml::Automation::Peers::IAutomationPeer5, Windows::UI::Xaml::Automation::Peers::IFrameworkElementAutomationPeer, Windows::UI::Xaml::Automation::Peers::IFlipViewItemAutomationPeer>
{
    using composable = FlipViewItemAutomationPeer;

protected:

    FlipViewItemAutomationPeerT(const Windows::UI::Xaml::Controls::FlipViewItem & owner)
    {
        GetActivationFactory<FlipViewItemAutomationPeer, IFlipViewItemAutomationPeerFactory>().CreateInstanceWithOwner(owner, *this, m_inner);
    }
};

template <typename D, typename ... Interfaces> struct FlipViewItemDataAutomationPeerT :
    overrides<D, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverridesT<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2T<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3T<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides4T<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides5T<D>, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer, Windows::UI::Xaml::Automation::Peers::IAutomationPeerProtected, Windows::UI::Xaml::Automation::Peers::IAutomationPeer2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer3, Windows::UI::Xaml::Automation::Peers::IAutomationPeer4, Windows::UI::Xaml::Automation::Peers::IAutomationPeer5, Windows::UI::Xaml::Automation::Peers::IItemAutomationPeer, Windows::UI::Xaml::Automation::Provider::IVirtualizedItemProvider, Windows::UI::Xaml::Automation::Peers::ISelectorItemAutomationPeer, Windows::UI::Xaml::Automation::Provider::ISelectionItemProvider, Windows::UI::Xaml::Automation::Peers::IFlipViewItemDataAutomationPeer, Windows::UI::Xaml::Automation::Provider::IScrollItemProvider>
{
    using composable = FlipViewItemDataAutomationPeer;

protected:

    FlipViewItemDataAutomationPeerT(const Windows::IInspectable & item, const Windows::UI::Xaml::Automation::Peers::FlipViewAutomationPeer & parent)
    {
        GetActivationFactory<FlipViewItemDataAutomationPeer, IFlipViewItemDataAutomationPeerFactory>().CreateInstanceWithParentAndItem(item, parent, *this, m_inner);
    }
};

template <typename D, typename ... Interfaces> struct FlyoutPresenterAutomationPeerT :
    overrides<D, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverridesT<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2T<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3T<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides4T<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides5T<D>, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer, Windows::UI::Xaml::Automation::Peers::IAutomationPeerProtected, Windows::UI::Xaml::Automation::Peers::IAutomationPeer2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer3, Windows::UI::Xaml::Automation::Peers::IAutomationPeer4, Windows::UI::Xaml::Automation::Peers::IAutomationPeer5, Windows::UI::Xaml::Automation::Peers::IFrameworkElementAutomationPeer, Windows::UI::Xaml::Automation::Peers::IFlyoutPresenterAutomationPeer>
{
    using composable = FlyoutPresenterAutomationPeer;

protected:

    FlyoutPresenterAutomationPeerT(const Windows::UI::Xaml::Controls::FlyoutPresenter & owner)
    {
        GetActivationFactory<FlyoutPresenterAutomationPeer, IFlyoutPresenterAutomationPeerFactory>().CreateInstanceWithOwner(owner, *this, m_inner);
    }
};

template <typename D, typename ... Interfaces> struct FrameworkElementAutomationPeerT :
    overrides<D, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverridesT<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2T<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3T<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides4T<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides5T<D>, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer, Windows::UI::Xaml::Automation::Peers::IAutomationPeerProtected, Windows::UI::Xaml::Automation::Peers::IAutomationPeer2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer3, Windows::UI::Xaml::Automation::Peers::IAutomationPeer4, Windows::UI::Xaml::Automation::Peers::IAutomationPeer5, Windows::UI::Xaml::Automation::Peers::IFrameworkElementAutomationPeer>
{
    using composable = FrameworkElementAutomationPeer;

protected:

    FrameworkElementAutomationPeerT(const Windows::UI::Xaml::FrameworkElement & owner)
    {
        GetActivationFactory<FrameworkElementAutomationPeer, IFrameworkElementAutomationPeerFactory>().CreateInstanceWithOwner(owner, *this, m_inner);
    }
};

template <typename D, typename ... Interfaces> struct GridViewAutomationPeerT :
    overrides<D, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverridesT<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2T<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3T<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides4T<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides5T<D>, Windows::UI::Xaml::Automation::Peers::IItemsControlAutomationPeerOverrides2T<D>, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer, Windows::UI::Xaml::Automation::Peers::IAutomationPeerProtected, Windows::UI::Xaml::Automation::Peers::IAutomationPeer2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer3, Windows::UI::Xaml::Automation::Peers::IAutomationPeer4, Windows::UI::Xaml::Automation::Peers::IAutomationPeer5, Windows::UI::Xaml::Automation::Peers::IFrameworkElementAutomationPeer, Windows::UI::Xaml::Automation::Peers::IItemsControlAutomationPeer, Windows::UI::Xaml::Automation::Provider::IItemContainerProvider, Windows::UI::Xaml::Automation::Peers::IItemsControlAutomationPeer2, Windows::UI::Xaml::Automation::Peers::ISelectorAutomationPeer, Windows::UI::Xaml::Automation::Provider::ISelectionProvider, Windows::UI::Xaml::Automation::Peers::IListViewBaseAutomationPeer, Windows::UI::Xaml::Automation::Provider::IDropTargetProvider, Windows::UI::Xaml::Automation::Peers::IGridViewAutomationPeer>
{
    using composable = GridViewAutomationPeer;

protected:

    GridViewAutomationPeerT(const Windows::UI::Xaml::Controls::GridView & owner)
    {
        GetActivationFactory<GridViewAutomationPeer, IGridViewAutomationPeerFactory>().CreateInstanceWithOwner(owner, *this, m_inner);
    }
};

template <typename D, typename ... Interfaces> struct GridViewHeaderItemAutomationPeerT :
    overrides<D, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverridesT<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2T<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3T<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides4T<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides5T<D>, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer, Windows::UI::Xaml::Automation::Peers::IAutomationPeerProtected, Windows::UI::Xaml::Automation::Peers::IAutomationPeer2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer3, Windows::UI::Xaml::Automation::Peers::IAutomationPeer4, Windows::UI::Xaml::Automation::Peers::IAutomationPeer5, Windows::UI::Xaml::Automation::Peers::IFrameworkElementAutomationPeer, Windows::UI::Xaml::Automation::Peers::IListViewBaseHeaderItemAutomationPeer, Windows::UI::Xaml::Automation::Peers::IGridViewHeaderItemAutomationPeer>
{
    using composable = GridViewHeaderItemAutomationPeer;

protected:

    GridViewHeaderItemAutomationPeerT(const Windows::UI::Xaml::Controls::GridViewHeaderItem & owner)
    {
        GetActivationFactory<GridViewHeaderItemAutomationPeer, IGridViewHeaderItemAutomationPeerFactory>().CreateInstanceWithOwner(owner, *this, m_inner);
    }
};

template <typename D, typename ... Interfaces> struct GridViewItemAutomationPeerT :
    overrides<D, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverridesT<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2T<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3T<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides4T<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides5T<D>, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer, Windows::UI::Xaml::Automation::Peers::IAutomationPeerProtected, Windows::UI::Xaml::Automation::Peers::IAutomationPeer2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer3, Windows::UI::Xaml::Automation::Peers::IAutomationPeer4, Windows::UI::Xaml::Automation::Peers::IAutomationPeer5, Windows::UI::Xaml::Automation::Peers::IFrameworkElementAutomationPeer, Windows::UI::Xaml::Automation::Peers::IGridViewItemAutomationPeer>
{
    using composable = GridViewItemAutomationPeer;

protected:

    GridViewItemAutomationPeerT(const Windows::UI::Xaml::Controls::GridViewItem & owner)
    {
        GetActivationFactory<GridViewItemAutomationPeer, IGridViewItemAutomationPeerFactory>().CreateInstanceWithOwner(owner, *this, m_inner);
    }
};

template <typename D, typename ... Interfaces> struct GridViewItemDataAutomationPeerT :
    overrides<D, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverridesT<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2T<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3T<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides4T<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides5T<D>, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer, Windows::UI::Xaml::Automation::Peers::IAutomationPeerProtected, Windows::UI::Xaml::Automation::Peers::IAutomationPeer2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer3, Windows::UI::Xaml::Automation::Peers::IAutomationPeer4, Windows::UI::Xaml::Automation::Peers::IAutomationPeer5, Windows::UI::Xaml::Automation::Peers::IItemAutomationPeer, Windows::UI::Xaml::Automation::Provider::IVirtualizedItemProvider, Windows::UI::Xaml::Automation::Peers::ISelectorItemAutomationPeer, Windows::UI::Xaml::Automation::Provider::ISelectionItemProvider, Windows::UI::Xaml::Automation::Peers::IGridViewItemDataAutomationPeer, Windows::UI::Xaml::Automation::Provider::IScrollItemProvider>
{
    using composable = GridViewItemDataAutomationPeer;

protected:

    GridViewItemDataAutomationPeerT(const Windows::IInspectable & item, const Windows::UI::Xaml::Automation::Peers::GridViewAutomationPeer & parent)
    {
        GetActivationFactory<GridViewItemDataAutomationPeer, IGridViewItemDataAutomationPeerFactory>().CreateInstanceWithParentAndItem(item, parent, *this, m_inner);
    }
};

template <typename D, typename ... Interfaces> struct GroupItemAutomationPeerT :
    overrides<D, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverridesT<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2T<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3T<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides4T<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides5T<D>, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer, Windows::UI::Xaml::Automation::Peers::IAutomationPeerProtected, Windows::UI::Xaml::Automation::Peers::IAutomationPeer2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer3, Windows::UI::Xaml::Automation::Peers::IAutomationPeer4, Windows::UI::Xaml::Automation::Peers::IAutomationPeer5, Windows::UI::Xaml::Automation::Peers::IFrameworkElementAutomationPeer, Windows::UI::Xaml::Automation::Peers::IGroupItemAutomationPeer>
{
    using composable = GroupItemAutomationPeer;

protected:

    GroupItemAutomationPeerT(const Windows::UI::Xaml::Controls::GroupItem & owner)
    {
        GetActivationFactory<GroupItemAutomationPeer, IGroupItemAutomationPeerFactory>().CreateInstanceWithOwner(owner, *this, m_inner);
    }
};

template <typename D, typename ... Interfaces> struct HubAutomationPeerT :
    overrides<D, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverridesT<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2T<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3T<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides4T<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides5T<D>, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer, Windows::UI::Xaml::Automation::Peers::IAutomationPeerProtected, Windows::UI::Xaml::Automation::Peers::IAutomationPeer2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer3, Windows::UI::Xaml::Automation::Peers::IAutomationPeer4, Windows::UI::Xaml::Automation::Peers::IAutomationPeer5, Windows::UI::Xaml::Automation::Peers::IFrameworkElementAutomationPeer, Windows::UI::Xaml::Automation::Peers::IHubAutomationPeer>
{
    using composable = HubAutomationPeer;

protected:

    HubAutomationPeerT(const Windows::UI::Xaml::Controls::Hub & owner)
    {
        GetActivationFactory<HubAutomationPeer, IHubAutomationPeerFactory>().CreateInstanceWithOwner(owner, *this, m_inner);
    }
};

template <typename D, typename ... Interfaces> struct HubSectionAutomationPeerT :
    overrides<D, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverridesT<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2T<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3T<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides4T<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides5T<D>, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer, Windows::UI::Xaml::Automation::Peers::IAutomationPeerProtected, Windows::UI::Xaml::Automation::Peers::IAutomationPeer2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer3, Windows::UI::Xaml::Automation::Peers::IAutomationPeer4, Windows::UI::Xaml::Automation::Peers::IAutomationPeer5, Windows::UI::Xaml::Automation::Peers::IFrameworkElementAutomationPeer, Windows::UI::Xaml::Automation::Peers::IHubSectionAutomationPeer, Windows::UI::Xaml::Automation::Provider::IScrollItemProvider>
{
    using composable = HubSectionAutomationPeer;

protected:

    HubSectionAutomationPeerT(const Windows::UI::Xaml::Controls::HubSection & owner)
    {
        GetActivationFactory<HubSectionAutomationPeer, IHubSectionAutomationPeerFactory>().CreateInstanceWithOwner(owner, *this, m_inner);
    }
};

template <typename D, typename ... Interfaces> struct HyperlinkButtonAutomationPeerT :
    overrides<D, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverridesT<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2T<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3T<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides4T<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides5T<D>, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer, Windows::UI::Xaml::Automation::Peers::IAutomationPeerProtected, Windows::UI::Xaml::Automation::Peers::IAutomationPeer2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer3, Windows::UI::Xaml::Automation::Peers::IAutomationPeer4, Windows::UI::Xaml::Automation::Peers::IAutomationPeer5, Windows::UI::Xaml::Automation::Peers::IFrameworkElementAutomationPeer, Windows::UI::Xaml::Automation::Peers::IButtonBaseAutomationPeer, Windows::UI::Xaml::Automation::Peers::IHyperlinkButtonAutomationPeer, Windows::UI::Xaml::Automation::Provider::IInvokeProvider>
{
    using composable = HyperlinkButtonAutomationPeer;

protected:

    HyperlinkButtonAutomationPeerT(const Windows::UI::Xaml::Controls::HyperlinkButton & owner)
    {
        GetActivationFactory<HyperlinkButtonAutomationPeer, IHyperlinkButtonAutomationPeerFactory>().CreateInstanceWithOwner(owner, *this, m_inner);
    }
};

template <typename D, typename ... Interfaces> struct ImageAutomationPeerT :
    overrides<D, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverridesT<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2T<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3T<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides4T<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides5T<D>, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer, Windows::UI::Xaml::Automation::Peers::IAutomationPeerProtected, Windows::UI::Xaml::Automation::Peers::IAutomationPeer2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer3, Windows::UI::Xaml::Automation::Peers::IAutomationPeer4, Windows::UI::Xaml::Automation::Peers::IAutomationPeer5, Windows::UI::Xaml::Automation::Peers::IFrameworkElementAutomationPeer, Windows::UI::Xaml::Automation::Peers::IImageAutomationPeer>
{
    using composable = ImageAutomationPeer;

protected:

    ImageAutomationPeerT(const Windows::UI::Xaml::Controls::Image & owner)
    {
        GetActivationFactory<ImageAutomationPeer, IImageAutomationPeerFactory>().CreateInstanceWithOwner(owner, *this, m_inner);
    }
};

template <typename D, typename ... Interfaces> struct ItemAutomationPeerT :
    overrides<D, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverridesT<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2T<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3T<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides4T<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides5T<D>, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer, Windows::UI::Xaml::Automation::Peers::IAutomationPeerProtected, Windows::UI::Xaml::Automation::Peers::IAutomationPeer2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer3, Windows::UI::Xaml::Automation::Peers::IAutomationPeer4, Windows::UI::Xaml::Automation::Peers::IAutomationPeer5, Windows::UI::Xaml::Automation::Peers::IItemAutomationPeer, Windows::UI::Xaml::Automation::Provider::IVirtualizedItemProvider>
{
    using composable = ItemAutomationPeer;

protected:

    ItemAutomationPeerT(const Windows::IInspectable & item, const Windows::UI::Xaml::Automation::Peers::ItemsControlAutomationPeer & parent)
    {
        GetActivationFactory<ItemAutomationPeer, IItemAutomationPeerFactory>().CreateInstanceWithParentAndItem(item, parent, *this, m_inner);
    }
};

template <typename D, typename ... Interfaces> struct ItemsControlAutomationPeerT :
    overrides<D, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverridesT<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2T<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3T<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides4T<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides5T<D>, Windows::UI::Xaml::Automation::Peers::IItemsControlAutomationPeerOverrides2T<D>, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer, Windows::UI::Xaml::Automation::Peers::IAutomationPeerProtected, Windows::UI::Xaml::Automation::Peers::IAutomationPeer2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer3, Windows::UI::Xaml::Automation::Peers::IAutomationPeer4, Windows::UI::Xaml::Automation::Peers::IAutomationPeer5, Windows::UI::Xaml::Automation::Peers::IFrameworkElementAutomationPeer, Windows::UI::Xaml::Automation::Peers::IItemsControlAutomationPeer, Windows::UI::Xaml::Automation::Provider::IItemContainerProvider, Windows::UI::Xaml::Automation::Peers::IItemsControlAutomationPeer2>
{
    using composable = ItemsControlAutomationPeer;

protected:

    ItemsControlAutomationPeerT(const Windows::UI::Xaml::Controls::ItemsControl & owner)
    {
        GetActivationFactory<ItemsControlAutomationPeer, IItemsControlAutomationPeerFactory>().CreateInstanceWithOwner(owner, *this, m_inner);
    }
};

template <typename D, typename ... Interfaces> struct ListBoxAutomationPeerT :
    overrides<D, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverridesT<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2T<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3T<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides4T<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides5T<D>, Windows::UI::Xaml::Automation::Peers::IItemsControlAutomationPeerOverrides2T<D>, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer, Windows::UI::Xaml::Automation::Peers::IAutomationPeerProtected, Windows::UI::Xaml::Automation::Peers::IAutomationPeer2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer3, Windows::UI::Xaml::Automation::Peers::IAutomationPeer4, Windows::UI::Xaml::Automation::Peers::IAutomationPeer5, Windows::UI::Xaml::Automation::Peers::IFrameworkElementAutomationPeer, Windows::UI::Xaml::Automation::Peers::IItemsControlAutomationPeer, Windows::UI::Xaml::Automation::Provider::IItemContainerProvider, Windows::UI::Xaml::Automation::Peers::IItemsControlAutomationPeer2, Windows::UI::Xaml::Automation::Peers::ISelectorAutomationPeer, Windows::UI::Xaml::Automation::Provider::ISelectionProvider, Windows::UI::Xaml::Automation::Peers::IListBoxAutomationPeer>
{
    using composable = ListBoxAutomationPeer;

protected:

    ListBoxAutomationPeerT(const Windows::UI::Xaml::Controls::ListBox & owner)
    {
        GetActivationFactory<ListBoxAutomationPeer, IListBoxAutomationPeerFactory>().CreateInstanceWithOwner(owner, *this, m_inner);
    }
};

template <typename D, typename ... Interfaces> struct ListBoxItemAutomationPeerT :
    overrides<D, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverridesT<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2T<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3T<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides4T<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides5T<D>, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer, Windows::UI::Xaml::Automation::Peers::IAutomationPeerProtected, Windows::UI::Xaml::Automation::Peers::IAutomationPeer2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer3, Windows::UI::Xaml::Automation::Peers::IAutomationPeer4, Windows::UI::Xaml::Automation::Peers::IAutomationPeer5, Windows::UI::Xaml::Automation::Peers::IFrameworkElementAutomationPeer, Windows::UI::Xaml::Automation::Peers::IListBoxItemAutomationPeer>
{
    using composable = ListBoxItemAutomationPeer;

protected:

    ListBoxItemAutomationPeerT(const Windows::UI::Xaml::Controls::ListBoxItem & owner)
    {
        GetActivationFactory<ListBoxItemAutomationPeer, IListBoxItemAutomationPeerFactory>().CreateInstanceWithOwner(owner, *this, m_inner);
    }
};

template <typename D, typename ... Interfaces> struct ListBoxItemDataAutomationPeerT :
    overrides<D, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverridesT<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2T<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3T<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides4T<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides5T<D>, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer, Windows::UI::Xaml::Automation::Peers::IAutomationPeerProtected, Windows::UI::Xaml::Automation::Peers::IAutomationPeer2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer3, Windows::UI::Xaml::Automation::Peers::IAutomationPeer4, Windows::UI::Xaml::Automation::Peers::IAutomationPeer5, Windows::UI::Xaml::Automation::Peers::IItemAutomationPeer, Windows::UI::Xaml::Automation::Provider::IVirtualizedItemProvider, Windows::UI::Xaml::Automation::Peers::ISelectorItemAutomationPeer, Windows::UI::Xaml::Automation::Provider::ISelectionItemProvider, Windows::UI::Xaml::Automation::Peers::IListBoxItemDataAutomationPeer, Windows::UI::Xaml::Automation::Provider::IScrollItemProvider>
{
    using composable = ListBoxItemDataAutomationPeer;

protected:

    ListBoxItemDataAutomationPeerT(const Windows::IInspectable & item, const Windows::UI::Xaml::Automation::Peers::ListBoxAutomationPeer & parent)
    {
        GetActivationFactory<ListBoxItemDataAutomationPeer, IListBoxItemDataAutomationPeerFactory>().CreateInstanceWithParentAndItem(item, parent, *this, m_inner);
    }
};

template <typename D, typename ... Interfaces> struct ListViewAutomationPeerT :
    overrides<D, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverridesT<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2T<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3T<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides4T<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides5T<D>, Windows::UI::Xaml::Automation::Peers::IItemsControlAutomationPeerOverrides2T<D>, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer, Windows::UI::Xaml::Automation::Peers::IAutomationPeerProtected, Windows::UI::Xaml::Automation::Peers::IAutomationPeer2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer3, Windows::UI::Xaml::Automation::Peers::IAutomationPeer4, Windows::UI::Xaml::Automation::Peers::IAutomationPeer5, Windows::UI::Xaml::Automation::Peers::IFrameworkElementAutomationPeer, Windows::UI::Xaml::Automation::Peers::IItemsControlAutomationPeer, Windows::UI::Xaml::Automation::Provider::IItemContainerProvider, Windows::UI::Xaml::Automation::Peers::IItemsControlAutomationPeer2, Windows::UI::Xaml::Automation::Peers::ISelectorAutomationPeer, Windows::UI::Xaml::Automation::Provider::ISelectionProvider, Windows::UI::Xaml::Automation::Peers::IListViewBaseAutomationPeer, Windows::UI::Xaml::Automation::Provider::IDropTargetProvider, Windows::UI::Xaml::Automation::Peers::IListViewAutomationPeer>
{
    using composable = ListViewAutomationPeer;

protected:

    ListViewAutomationPeerT(const Windows::UI::Xaml::Controls::ListView & owner)
    {
        GetActivationFactory<ListViewAutomationPeer, IListViewAutomationPeerFactory>().CreateInstanceWithOwner(owner, *this, m_inner);
    }
};

template <typename D, typename ... Interfaces> struct ListViewBaseAutomationPeerT :
    overrides<D, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverridesT<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2T<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3T<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides4T<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides5T<D>, Windows::UI::Xaml::Automation::Peers::IItemsControlAutomationPeerOverrides2T<D>, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer, Windows::UI::Xaml::Automation::Peers::IAutomationPeerProtected, Windows::UI::Xaml::Automation::Peers::IAutomationPeer2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer3, Windows::UI::Xaml::Automation::Peers::IAutomationPeer4, Windows::UI::Xaml::Automation::Peers::IAutomationPeer5, Windows::UI::Xaml::Automation::Peers::IFrameworkElementAutomationPeer, Windows::UI::Xaml::Automation::Peers::IItemsControlAutomationPeer, Windows::UI::Xaml::Automation::Provider::IItemContainerProvider, Windows::UI::Xaml::Automation::Peers::IItemsControlAutomationPeer2, Windows::UI::Xaml::Automation::Peers::ISelectorAutomationPeer, Windows::UI::Xaml::Automation::Provider::ISelectionProvider, Windows::UI::Xaml::Automation::Peers::IListViewBaseAutomationPeer, Windows::UI::Xaml::Automation::Provider::IDropTargetProvider>
{
    using composable = ListViewBaseAutomationPeer;

protected:

    ListViewBaseAutomationPeerT(const Windows::UI::Xaml::Controls::ListViewBase & owner)
    {
        GetActivationFactory<ListViewBaseAutomationPeer, IListViewBaseAutomationPeerFactory>().CreateInstanceWithOwner(owner, *this, m_inner);
    }
};

template <typename D, typename ... Interfaces> struct ListViewBaseHeaderItemAutomationPeerT :
    overrides<D, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverridesT<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2T<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3T<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides4T<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides5T<D>, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer, Windows::UI::Xaml::Automation::Peers::IAutomationPeerProtected, Windows::UI::Xaml::Automation::Peers::IAutomationPeer2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer3, Windows::UI::Xaml::Automation::Peers::IAutomationPeer4, Windows::UI::Xaml::Automation::Peers::IAutomationPeer5, Windows::UI::Xaml::Automation::Peers::IFrameworkElementAutomationPeer, Windows::UI::Xaml::Automation::Peers::IListViewBaseHeaderItemAutomationPeer>
{
    using composable = ListViewBaseHeaderItemAutomationPeer;

protected:

    ListViewBaseHeaderItemAutomationPeerT(const Windows::UI::Xaml::Controls::ListViewBaseHeaderItem & owner)
    {
        GetActivationFactory<ListViewBaseHeaderItemAutomationPeer, IListViewBaseHeaderItemAutomationPeerFactory>().CreateInstanceWithOwner(owner, *this, m_inner);
    }
};

template <typename D, typename ... Interfaces> struct ListViewHeaderItemAutomationPeerT :
    overrides<D, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverridesT<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2T<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3T<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides4T<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides5T<D>, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer, Windows::UI::Xaml::Automation::Peers::IAutomationPeerProtected, Windows::UI::Xaml::Automation::Peers::IAutomationPeer2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer3, Windows::UI::Xaml::Automation::Peers::IAutomationPeer4, Windows::UI::Xaml::Automation::Peers::IAutomationPeer5, Windows::UI::Xaml::Automation::Peers::IFrameworkElementAutomationPeer, Windows::UI::Xaml::Automation::Peers::IListViewBaseHeaderItemAutomationPeer, Windows::UI::Xaml::Automation::Peers::IListViewHeaderItemAutomationPeer>
{
    using composable = ListViewHeaderItemAutomationPeer;

protected:

    ListViewHeaderItemAutomationPeerT(const Windows::UI::Xaml::Controls::ListViewHeaderItem & owner)
    {
        GetActivationFactory<ListViewHeaderItemAutomationPeer, IListViewHeaderItemAutomationPeerFactory>().CreateInstanceWithOwner(owner, *this, m_inner);
    }
};

template <typename D, typename ... Interfaces> struct ListViewItemAutomationPeerT :
    overrides<D, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverridesT<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2T<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3T<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides4T<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides5T<D>, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer, Windows::UI::Xaml::Automation::Peers::IAutomationPeerProtected, Windows::UI::Xaml::Automation::Peers::IAutomationPeer2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer3, Windows::UI::Xaml::Automation::Peers::IAutomationPeer4, Windows::UI::Xaml::Automation::Peers::IAutomationPeer5, Windows::UI::Xaml::Automation::Peers::IFrameworkElementAutomationPeer, Windows::UI::Xaml::Automation::Peers::IListViewItemAutomationPeer>
{
    using composable = ListViewItemAutomationPeer;

protected:

    ListViewItemAutomationPeerT(const Windows::UI::Xaml::Controls::ListViewItem & owner)
    {
        GetActivationFactory<ListViewItemAutomationPeer, IListViewItemAutomationPeerFactory>().CreateInstanceWithOwner(owner, *this, m_inner);
    }
};

template <typename D, typename ... Interfaces> struct ListViewItemDataAutomationPeerT :
    overrides<D, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverridesT<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2T<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3T<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides4T<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides5T<D>, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer, Windows::UI::Xaml::Automation::Peers::IAutomationPeerProtected, Windows::UI::Xaml::Automation::Peers::IAutomationPeer2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer3, Windows::UI::Xaml::Automation::Peers::IAutomationPeer4, Windows::UI::Xaml::Automation::Peers::IAutomationPeer5, Windows::UI::Xaml::Automation::Peers::IItemAutomationPeer, Windows::UI::Xaml::Automation::Provider::IVirtualizedItemProvider, Windows::UI::Xaml::Automation::Peers::ISelectorItemAutomationPeer, Windows::UI::Xaml::Automation::Provider::ISelectionItemProvider, Windows::UI::Xaml::Automation::Peers::IListViewItemDataAutomationPeer, Windows::UI::Xaml::Automation::Provider::IScrollItemProvider>
{
    using composable = ListViewItemDataAutomationPeer;

protected:

    ListViewItemDataAutomationPeerT(const Windows::IInspectable & item, const Windows::UI::Xaml::Automation::Peers::ListViewBaseAutomationPeer & parent)
    {
        GetActivationFactory<ListViewItemDataAutomationPeer, IListViewItemDataAutomationPeerFactory>().CreateInstanceWithParentAndItem(item, parent, *this, m_inner);
    }
};

template <typename D, typename ... Interfaces> struct MediaElementAutomationPeerT :
    overrides<D, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverridesT<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2T<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3T<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides4T<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides5T<D>, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer, Windows::UI::Xaml::Automation::Peers::IAutomationPeerProtected, Windows::UI::Xaml::Automation::Peers::IAutomationPeer2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer3, Windows::UI::Xaml::Automation::Peers::IAutomationPeer4, Windows::UI::Xaml::Automation::Peers::IAutomationPeer5, Windows::UI::Xaml::Automation::Peers::IFrameworkElementAutomationPeer, Windows::UI::Xaml::Automation::Peers::IMediaElementAutomationPeer>
{
    using composable = MediaElementAutomationPeer;

protected:

    MediaElementAutomationPeerT(const Windows::UI::Xaml::Controls::MediaElement & owner)
    {
        GetActivationFactory<MediaElementAutomationPeer, IMediaElementAutomationPeerFactory>().CreateInstanceWithOwner(owner, *this, m_inner);
    }
};

template <typename D, typename ... Interfaces> struct MediaPlayerElementAutomationPeerT :
    overrides<D, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverridesT<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2T<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3T<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides4T<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides5T<D>, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer, Windows::UI::Xaml::Automation::Peers::IAutomationPeerProtected, Windows::UI::Xaml::Automation::Peers::IAutomationPeer2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer3, Windows::UI::Xaml::Automation::Peers::IAutomationPeer4, Windows::UI::Xaml::Automation::Peers::IAutomationPeer5, Windows::UI::Xaml::Automation::Peers::IFrameworkElementAutomationPeer, Windows::UI::Xaml::Automation::Peers::IMediaPlayerElementAutomationPeer>
{
    using composable = MediaPlayerElementAutomationPeer;

protected:

    MediaPlayerElementAutomationPeerT(const Windows::UI::Xaml::Controls::MediaPlayerElement & owner)
    {
        GetActivationFactory<MediaPlayerElementAutomationPeer, IMediaPlayerElementAutomationPeerFactory>().CreateInstanceWithOwner(owner, *this, m_inner);
    }
};

template <typename D, typename ... Interfaces> struct MediaTransportControlsAutomationPeerT :
    overrides<D, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverridesT<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2T<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3T<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides4T<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides5T<D>, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer, Windows::UI::Xaml::Automation::Peers::IAutomationPeerProtected, Windows::UI::Xaml::Automation::Peers::IAutomationPeer2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer3, Windows::UI::Xaml::Automation::Peers::IAutomationPeer4, Windows::UI::Xaml::Automation::Peers::IAutomationPeer5, Windows::UI::Xaml::Automation::Peers::IFrameworkElementAutomationPeer, Windows::UI::Xaml::Automation::Peers::IMediaTransportControlsAutomationPeer>
{
    using composable = MediaTransportControlsAutomationPeer;

protected:

    MediaTransportControlsAutomationPeerT(const Windows::UI::Xaml::Controls::MediaTransportControls & owner)
    {
        GetActivationFactory<MediaTransportControlsAutomationPeer, IMediaTransportControlsAutomationPeerFactory>().CreateInstanceWithOwner(owner, *this, m_inner);
    }
};

template <typename D, typename ... Interfaces> struct MenuFlyoutItemAutomationPeerT :
    overrides<D, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverridesT<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2T<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3T<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides4T<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides5T<D>, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer, Windows::UI::Xaml::Automation::Peers::IAutomationPeerProtected, Windows::UI::Xaml::Automation::Peers::IAutomationPeer2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer3, Windows::UI::Xaml::Automation::Peers::IAutomationPeer4, Windows::UI::Xaml::Automation::Peers::IAutomationPeer5, Windows::UI::Xaml::Automation::Peers::IFrameworkElementAutomationPeer, Windows::UI::Xaml::Automation::Peers::IMenuFlyoutItemAutomationPeer, Windows::UI::Xaml::Automation::Provider::IInvokeProvider>
{
    using composable = MenuFlyoutItemAutomationPeer;

protected:

    MenuFlyoutItemAutomationPeerT(const Windows::UI::Xaml::Controls::MenuFlyoutItem & owner)
    {
        GetActivationFactory<MenuFlyoutItemAutomationPeer, IMenuFlyoutItemAutomationPeerFactory>().CreateInstanceWithOwner(owner, *this, m_inner);
    }
};

template <typename D, typename ... Interfaces> struct MenuFlyoutPresenterAutomationPeerT :
    overrides<D, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverridesT<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2T<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3T<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides4T<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides5T<D>, Windows::UI::Xaml::Automation::Peers::IItemsControlAutomationPeerOverrides2T<D>, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer, Windows::UI::Xaml::Automation::Peers::IAutomationPeerProtected, Windows::UI::Xaml::Automation::Peers::IAutomationPeer2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer3, Windows::UI::Xaml::Automation::Peers::IAutomationPeer4, Windows::UI::Xaml::Automation::Peers::IAutomationPeer5, Windows::UI::Xaml::Automation::Peers::IFrameworkElementAutomationPeer, Windows::UI::Xaml::Automation::Peers::IItemsControlAutomationPeer, Windows::UI::Xaml::Automation::Provider::IItemContainerProvider, Windows::UI::Xaml::Automation::Peers::IItemsControlAutomationPeer2, Windows::UI::Xaml::Automation::Peers::IMenuFlyoutPresenterAutomationPeer>
{
    using composable = MenuFlyoutPresenterAutomationPeer;

protected:

    MenuFlyoutPresenterAutomationPeerT(const Windows::UI::Xaml::Controls::MenuFlyoutPresenter & owner)
    {
        GetActivationFactory<MenuFlyoutPresenterAutomationPeer, IMenuFlyoutPresenterAutomationPeerFactory>().CreateInstanceWithOwner(owner, *this, m_inner);
    }
};

template <typename D, typename ... Interfaces> struct PasswordBoxAutomationPeerT :
    overrides<D, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverridesT<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2T<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3T<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides4T<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides5T<D>, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer, Windows::UI::Xaml::Automation::Peers::IAutomationPeerProtected, Windows::UI::Xaml::Automation::Peers::IAutomationPeer2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer3, Windows::UI::Xaml::Automation::Peers::IAutomationPeer4, Windows::UI::Xaml::Automation::Peers::IAutomationPeer5, Windows::UI::Xaml::Automation::Peers::IFrameworkElementAutomationPeer, Windows::UI::Xaml::Automation::Peers::IPasswordBoxAutomationPeer>
{
    using composable = PasswordBoxAutomationPeer;

protected:

    PasswordBoxAutomationPeerT(const Windows::UI::Xaml::Controls::PasswordBox & owner)
    {
        GetActivationFactory<PasswordBoxAutomationPeer, IPasswordBoxAutomationPeerFactory>().CreateInstanceWithOwner(owner, *this, m_inner);
    }
};

template <typename D, typename ... Interfaces> struct ProgressBarAutomationPeerT :
    overrides<D, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverridesT<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2T<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3T<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides4T<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides5T<D>, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer, Windows::UI::Xaml::Automation::Peers::IAutomationPeerProtected, Windows::UI::Xaml::Automation::Peers::IAutomationPeer2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer3, Windows::UI::Xaml::Automation::Peers::IAutomationPeer4, Windows::UI::Xaml::Automation::Peers::IAutomationPeer5, Windows::UI::Xaml::Automation::Peers::IFrameworkElementAutomationPeer, Windows::UI::Xaml::Automation::Peers::IRangeBaseAutomationPeer, Windows::UI::Xaml::Automation::Provider::IRangeValueProvider, Windows::UI::Xaml::Automation::Peers::IProgressBarAutomationPeer>
{
    using composable = ProgressBarAutomationPeer;

protected:

    ProgressBarAutomationPeerT(const Windows::UI::Xaml::Controls::ProgressBar & owner)
    {
        GetActivationFactory<ProgressBarAutomationPeer, IProgressBarAutomationPeerFactory>().CreateInstanceWithOwner(owner, *this, m_inner);
    }
};

template <typename D, typename ... Interfaces> struct ProgressRingAutomationPeerT :
    overrides<D, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverridesT<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2T<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3T<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides4T<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides5T<D>, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer, Windows::UI::Xaml::Automation::Peers::IAutomationPeerProtected, Windows::UI::Xaml::Automation::Peers::IAutomationPeer2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer3, Windows::UI::Xaml::Automation::Peers::IAutomationPeer4, Windows::UI::Xaml::Automation::Peers::IAutomationPeer5, Windows::UI::Xaml::Automation::Peers::IFrameworkElementAutomationPeer, Windows::UI::Xaml::Automation::Peers::IProgressRingAutomationPeer>
{
    using composable = ProgressRingAutomationPeer;

protected:

    ProgressRingAutomationPeerT(const Windows::UI::Xaml::Controls::ProgressRing & owner)
    {
        GetActivationFactory<ProgressRingAutomationPeer, IProgressRingAutomationPeerFactory>().CreateInstanceWithOwner(owner, *this, m_inner);
    }
};

template <typename D, typename ... Interfaces> struct RadioButtonAutomationPeerT :
    overrides<D, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverridesT<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2T<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3T<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides4T<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides5T<D>, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer, Windows::UI::Xaml::Automation::Peers::IAutomationPeerProtected, Windows::UI::Xaml::Automation::Peers::IAutomationPeer2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer3, Windows::UI::Xaml::Automation::Peers::IAutomationPeer4, Windows::UI::Xaml::Automation::Peers::IAutomationPeer5, Windows::UI::Xaml::Automation::Peers::IFrameworkElementAutomationPeer, Windows::UI::Xaml::Automation::Peers::IButtonBaseAutomationPeer, Windows::UI::Xaml::Automation::Peers::IToggleButtonAutomationPeer, Windows::UI::Xaml::Automation::Provider::IToggleProvider, Windows::UI::Xaml::Automation::Peers::IRadioButtonAutomationPeer, Windows::UI::Xaml::Automation::Provider::ISelectionItemProvider>
{
    using composable = RadioButtonAutomationPeer;

protected:

    RadioButtonAutomationPeerT(const Windows::UI::Xaml::Controls::RadioButton & owner)
    {
        GetActivationFactory<RadioButtonAutomationPeer, IRadioButtonAutomationPeerFactory>().CreateInstanceWithOwner(owner, *this, m_inner);
    }
};

template <typename D, typename ... Interfaces> struct RangeBaseAutomationPeerT :
    overrides<D, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverridesT<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2T<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3T<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides4T<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides5T<D>, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer, Windows::UI::Xaml::Automation::Peers::IAutomationPeerProtected, Windows::UI::Xaml::Automation::Peers::IAutomationPeer2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer3, Windows::UI::Xaml::Automation::Peers::IAutomationPeer4, Windows::UI::Xaml::Automation::Peers::IAutomationPeer5, Windows::UI::Xaml::Automation::Peers::IFrameworkElementAutomationPeer, Windows::UI::Xaml::Automation::Peers::IRangeBaseAutomationPeer, Windows::UI::Xaml::Automation::Provider::IRangeValueProvider>
{
    using composable = RangeBaseAutomationPeer;

protected:

    RangeBaseAutomationPeerT(const Windows::UI::Xaml::Controls::Primitives::RangeBase & owner)
    {
        GetActivationFactory<RangeBaseAutomationPeer, IRangeBaseAutomationPeerFactory>().CreateInstanceWithOwner(owner, *this, m_inner);
    }
};

template <typename D, typename ... Interfaces> struct RepeatButtonAutomationPeerT :
    overrides<D, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverridesT<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2T<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3T<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides4T<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides5T<D>, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer, Windows::UI::Xaml::Automation::Peers::IAutomationPeerProtected, Windows::UI::Xaml::Automation::Peers::IAutomationPeer2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer3, Windows::UI::Xaml::Automation::Peers::IAutomationPeer4, Windows::UI::Xaml::Automation::Peers::IAutomationPeer5, Windows::UI::Xaml::Automation::Peers::IFrameworkElementAutomationPeer, Windows::UI::Xaml::Automation::Peers::IButtonBaseAutomationPeer, Windows::UI::Xaml::Automation::Peers::IRepeatButtonAutomationPeer, Windows::UI::Xaml::Automation::Provider::IInvokeProvider>
{
    using composable = RepeatButtonAutomationPeer;

protected:

    RepeatButtonAutomationPeerT(const Windows::UI::Xaml::Controls::Primitives::RepeatButton & owner)
    {
        GetActivationFactory<RepeatButtonAutomationPeer, IRepeatButtonAutomationPeerFactory>().CreateInstanceWithOwner(owner, *this, m_inner);
    }
};

template <typename D, typename ... Interfaces> struct RichEditBoxAutomationPeerT :
    overrides<D, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverridesT<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2T<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3T<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides4T<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides5T<D>, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer, Windows::UI::Xaml::Automation::Peers::IAutomationPeerProtected, Windows::UI::Xaml::Automation::Peers::IAutomationPeer2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer3, Windows::UI::Xaml::Automation::Peers::IAutomationPeer4, Windows::UI::Xaml::Automation::Peers::IAutomationPeer5, Windows::UI::Xaml::Automation::Peers::IFrameworkElementAutomationPeer, Windows::UI::Xaml::Automation::Peers::IRichEditBoxAutomationPeer>
{
    using composable = RichEditBoxAutomationPeer;

protected:

    RichEditBoxAutomationPeerT(const Windows::UI::Xaml::Controls::RichEditBox & owner)
    {
        GetActivationFactory<RichEditBoxAutomationPeer, IRichEditBoxAutomationPeerFactory>().CreateInstanceWithOwner(owner, *this, m_inner);
    }
};

template <typename D, typename ... Interfaces> struct RichTextBlockAutomationPeerT :
    overrides<D, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverridesT<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2T<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3T<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides4T<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides5T<D>, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer, Windows::UI::Xaml::Automation::Peers::IAutomationPeerProtected, Windows::UI::Xaml::Automation::Peers::IAutomationPeer2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer3, Windows::UI::Xaml::Automation::Peers::IAutomationPeer4, Windows::UI::Xaml::Automation::Peers::IAutomationPeer5, Windows::UI::Xaml::Automation::Peers::IFrameworkElementAutomationPeer, Windows::UI::Xaml::Automation::Peers::IRichTextBlockAutomationPeer>
{
    using composable = RichTextBlockAutomationPeer;

protected:

    RichTextBlockAutomationPeerT(const Windows::UI::Xaml::Controls::RichTextBlock & owner)
    {
        GetActivationFactory<RichTextBlockAutomationPeer, IRichTextBlockAutomationPeerFactory>().CreateInstanceWithOwner(owner, *this, m_inner);
    }
};

template <typename D, typename ... Interfaces> struct RichTextBlockOverflowAutomationPeerT :
    overrides<D, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverridesT<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2T<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3T<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides4T<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides5T<D>, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer, Windows::UI::Xaml::Automation::Peers::IAutomationPeerProtected, Windows::UI::Xaml::Automation::Peers::IAutomationPeer2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer3, Windows::UI::Xaml::Automation::Peers::IAutomationPeer4, Windows::UI::Xaml::Automation::Peers::IAutomationPeer5, Windows::UI::Xaml::Automation::Peers::IFrameworkElementAutomationPeer, Windows::UI::Xaml::Automation::Peers::IRichTextBlockOverflowAutomationPeer>
{
    using composable = RichTextBlockOverflowAutomationPeer;

protected:

    RichTextBlockOverflowAutomationPeerT(const Windows::UI::Xaml::Controls::RichTextBlockOverflow & owner)
    {
        GetActivationFactory<RichTextBlockOverflowAutomationPeer, IRichTextBlockOverflowAutomationPeerFactory>().CreateInstanceWithOwner(owner, *this, m_inner);
    }
};

template <typename D, typename ... Interfaces> struct ScrollBarAutomationPeerT :
    overrides<D, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverridesT<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2T<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3T<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides4T<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides5T<D>, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer, Windows::UI::Xaml::Automation::Peers::IAutomationPeerProtected, Windows::UI::Xaml::Automation::Peers::IAutomationPeer2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer3, Windows::UI::Xaml::Automation::Peers::IAutomationPeer4, Windows::UI::Xaml::Automation::Peers::IAutomationPeer5, Windows::UI::Xaml::Automation::Peers::IFrameworkElementAutomationPeer, Windows::UI::Xaml::Automation::Peers::IRangeBaseAutomationPeer, Windows::UI::Xaml::Automation::Provider::IRangeValueProvider, Windows::UI::Xaml::Automation::Peers::IScrollBarAutomationPeer>
{
    using composable = ScrollBarAutomationPeer;

protected:

    ScrollBarAutomationPeerT(const Windows::UI::Xaml::Controls::Primitives::ScrollBar & owner)
    {
        GetActivationFactory<ScrollBarAutomationPeer, IScrollBarAutomationPeerFactory>().CreateInstanceWithOwner(owner, *this, m_inner);
    }
};

template <typename D, typename ... Interfaces> struct ScrollViewerAutomationPeerT :
    overrides<D, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverridesT<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2T<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3T<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides4T<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides5T<D>, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer, Windows::UI::Xaml::Automation::Peers::IAutomationPeerProtected, Windows::UI::Xaml::Automation::Peers::IAutomationPeer2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer3, Windows::UI::Xaml::Automation::Peers::IAutomationPeer4, Windows::UI::Xaml::Automation::Peers::IAutomationPeer5, Windows::UI::Xaml::Automation::Peers::IFrameworkElementAutomationPeer, Windows::UI::Xaml::Automation::Peers::IScrollViewerAutomationPeer, Windows::UI::Xaml::Automation::Provider::IScrollProvider>
{
    using composable = ScrollViewerAutomationPeer;

protected:

    ScrollViewerAutomationPeerT(const Windows::UI::Xaml::Controls::ScrollViewer & owner)
    {
        GetActivationFactory<ScrollViewerAutomationPeer, IScrollViewerAutomationPeerFactory>().CreateInstanceWithOwner(owner, *this, m_inner);
    }
};

template <typename D, typename ... Interfaces> struct SearchBoxAutomationPeerT :
    overrides<D, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverridesT<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2T<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3T<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides4T<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides5T<D>, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer, Windows::UI::Xaml::Automation::Peers::IAutomationPeerProtected, Windows::UI::Xaml::Automation::Peers::IAutomationPeer2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer3, Windows::UI::Xaml::Automation::Peers::IAutomationPeer4, Windows::UI::Xaml::Automation::Peers::IAutomationPeer5, Windows::UI::Xaml::Automation::Peers::IFrameworkElementAutomationPeer, Windows::UI::Xaml::Automation::Peers::ISearchBoxAutomationPeer>
{
    using composable = SearchBoxAutomationPeer;

protected:

    SearchBoxAutomationPeerT(const Windows::UI::Xaml::Controls::SearchBox & owner)
    {
        GetActivationFactory<SearchBoxAutomationPeer, ISearchBoxAutomationPeerFactory>().CreateInstanceWithOwner(owner, *this, m_inner);
    }
};

template <typename D, typename ... Interfaces> struct SelectorAutomationPeerT :
    overrides<D, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverridesT<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2T<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3T<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides4T<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides5T<D>, Windows::UI::Xaml::Automation::Peers::IItemsControlAutomationPeerOverrides2T<D>, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer, Windows::UI::Xaml::Automation::Peers::IAutomationPeerProtected, Windows::UI::Xaml::Automation::Peers::IAutomationPeer2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer3, Windows::UI::Xaml::Automation::Peers::IAutomationPeer4, Windows::UI::Xaml::Automation::Peers::IAutomationPeer5, Windows::UI::Xaml::Automation::Peers::IFrameworkElementAutomationPeer, Windows::UI::Xaml::Automation::Peers::IItemsControlAutomationPeer, Windows::UI::Xaml::Automation::Provider::IItemContainerProvider, Windows::UI::Xaml::Automation::Peers::IItemsControlAutomationPeer2, Windows::UI::Xaml::Automation::Peers::ISelectorAutomationPeer, Windows::UI::Xaml::Automation::Provider::ISelectionProvider>
{
    using composable = SelectorAutomationPeer;

protected:

    SelectorAutomationPeerT(const Windows::UI::Xaml::Controls::Primitives::Selector & owner)
    {
        GetActivationFactory<SelectorAutomationPeer, ISelectorAutomationPeerFactory>().CreateInstanceWithOwner(owner, *this, m_inner);
    }
};

template <typename D, typename ... Interfaces> struct SelectorItemAutomationPeerT :
    overrides<D, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverridesT<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2T<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3T<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides4T<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides5T<D>, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer, Windows::UI::Xaml::Automation::Peers::IAutomationPeerProtected, Windows::UI::Xaml::Automation::Peers::IAutomationPeer2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer3, Windows::UI::Xaml::Automation::Peers::IAutomationPeer4, Windows::UI::Xaml::Automation::Peers::IAutomationPeer5, Windows::UI::Xaml::Automation::Peers::IItemAutomationPeer, Windows::UI::Xaml::Automation::Provider::IVirtualizedItemProvider, Windows::UI::Xaml::Automation::Peers::ISelectorItemAutomationPeer, Windows::UI::Xaml::Automation::Provider::ISelectionItemProvider>
{
    using composable = SelectorItemAutomationPeer;

protected:

    SelectorItemAutomationPeerT(const Windows::IInspectable & item, const Windows::UI::Xaml::Automation::Peers::SelectorAutomationPeer & parent)
    {
        GetActivationFactory<SelectorItemAutomationPeer, ISelectorItemAutomationPeerFactory>().CreateInstanceWithParentAndItem(item, parent, *this, m_inner);
    }
};

template <typename D, typename ... Interfaces> struct SemanticZoomAutomationPeerT :
    overrides<D, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverridesT<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2T<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3T<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides4T<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides5T<D>, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer, Windows::UI::Xaml::Automation::Peers::IAutomationPeerProtected, Windows::UI::Xaml::Automation::Peers::IAutomationPeer2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer3, Windows::UI::Xaml::Automation::Peers::IAutomationPeer4, Windows::UI::Xaml::Automation::Peers::IAutomationPeer5, Windows::UI::Xaml::Automation::Peers::IFrameworkElementAutomationPeer, Windows::UI::Xaml::Automation::Peers::ISemanticZoomAutomationPeer, Windows::UI::Xaml::Automation::Provider::IToggleProvider>
{
    using composable = SemanticZoomAutomationPeer;

protected:

    SemanticZoomAutomationPeerT(const Windows::UI::Xaml::Controls::SemanticZoom & owner)
    {
        GetActivationFactory<SemanticZoomAutomationPeer, ISemanticZoomAutomationPeerFactory>().CreateInstanceWithOwner(owner, *this, m_inner);
    }
};

template <typename D, typename ... Interfaces> struct SettingsFlyoutAutomationPeerT :
    overrides<D, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverridesT<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2T<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3T<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides4T<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides5T<D>, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer, Windows::UI::Xaml::Automation::Peers::IAutomationPeerProtected, Windows::UI::Xaml::Automation::Peers::IAutomationPeer2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer3, Windows::UI::Xaml::Automation::Peers::IAutomationPeer4, Windows::UI::Xaml::Automation::Peers::IAutomationPeer5, Windows::UI::Xaml::Automation::Peers::IFrameworkElementAutomationPeer, Windows::UI::Xaml::Automation::Peers::ISettingsFlyoutAutomationPeer>
{
    using composable = SettingsFlyoutAutomationPeer;

protected:

    SettingsFlyoutAutomationPeerT(const Windows::UI::Xaml::Controls::SettingsFlyout & owner)
    {
        GetActivationFactory<SettingsFlyoutAutomationPeer, ISettingsFlyoutAutomationPeerFactory>().CreateInstanceWithOwner(owner, *this, m_inner);
    }
};

template <typename D, typename ... Interfaces> struct SliderAutomationPeerT :
    overrides<D, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverridesT<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2T<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3T<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides4T<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides5T<D>, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer, Windows::UI::Xaml::Automation::Peers::IAutomationPeerProtected, Windows::UI::Xaml::Automation::Peers::IAutomationPeer2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer3, Windows::UI::Xaml::Automation::Peers::IAutomationPeer4, Windows::UI::Xaml::Automation::Peers::IAutomationPeer5, Windows::UI::Xaml::Automation::Peers::IFrameworkElementAutomationPeer, Windows::UI::Xaml::Automation::Peers::IRangeBaseAutomationPeer, Windows::UI::Xaml::Automation::Provider::IRangeValueProvider, Windows::UI::Xaml::Automation::Peers::ISliderAutomationPeer>
{
    using composable = SliderAutomationPeer;

protected:

    SliderAutomationPeerT(const Windows::UI::Xaml::Controls::Slider & owner)
    {
        GetActivationFactory<SliderAutomationPeer, ISliderAutomationPeerFactory>().CreateInstanceWithOwner(owner, *this, m_inner);
    }
};

template <typename D, typename ... Interfaces> struct TextBlockAutomationPeerT :
    overrides<D, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverridesT<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2T<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3T<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides4T<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides5T<D>, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer, Windows::UI::Xaml::Automation::Peers::IAutomationPeerProtected, Windows::UI::Xaml::Automation::Peers::IAutomationPeer2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer3, Windows::UI::Xaml::Automation::Peers::IAutomationPeer4, Windows::UI::Xaml::Automation::Peers::IAutomationPeer5, Windows::UI::Xaml::Automation::Peers::IFrameworkElementAutomationPeer, Windows::UI::Xaml::Automation::Peers::ITextBlockAutomationPeer>
{
    using composable = TextBlockAutomationPeer;

protected:

    TextBlockAutomationPeerT(const Windows::UI::Xaml::Controls::TextBlock & owner)
    {
        GetActivationFactory<TextBlockAutomationPeer, ITextBlockAutomationPeerFactory>().CreateInstanceWithOwner(owner, *this, m_inner);
    }
};

template <typename D, typename ... Interfaces> struct TextBoxAutomationPeerT :
    overrides<D, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverridesT<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2T<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3T<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides4T<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides5T<D>, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer, Windows::UI::Xaml::Automation::Peers::IAutomationPeerProtected, Windows::UI::Xaml::Automation::Peers::IAutomationPeer2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer3, Windows::UI::Xaml::Automation::Peers::IAutomationPeer4, Windows::UI::Xaml::Automation::Peers::IAutomationPeer5, Windows::UI::Xaml::Automation::Peers::IFrameworkElementAutomationPeer, Windows::UI::Xaml::Automation::Peers::ITextBoxAutomationPeer>
{
    using composable = TextBoxAutomationPeer;

protected:

    TextBoxAutomationPeerT(const Windows::UI::Xaml::Controls::TextBox & owner)
    {
        GetActivationFactory<TextBoxAutomationPeer, ITextBoxAutomationPeerFactory>().CreateInstanceWithOwner(owner, *this, m_inner);
    }
};

template <typename D, typename ... Interfaces> struct ThumbAutomationPeerT :
    overrides<D, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverridesT<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2T<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3T<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides4T<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides5T<D>, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer, Windows::UI::Xaml::Automation::Peers::IAutomationPeerProtected, Windows::UI::Xaml::Automation::Peers::IAutomationPeer2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer3, Windows::UI::Xaml::Automation::Peers::IAutomationPeer4, Windows::UI::Xaml::Automation::Peers::IAutomationPeer5, Windows::UI::Xaml::Automation::Peers::IFrameworkElementAutomationPeer, Windows::UI::Xaml::Automation::Peers::IThumbAutomationPeer>
{
    using composable = ThumbAutomationPeer;

protected:

    ThumbAutomationPeerT(const Windows::UI::Xaml::Controls::Primitives::Thumb & owner)
    {
        GetActivationFactory<ThumbAutomationPeer, IThumbAutomationPeerFactory>().CreateInstanceWithOwner(owner, *this, m_inner);
    }
};

template <typename D, typename ... Interfaces> struct TimePickerAutomationPeerT :
    overrides<D, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverridesT<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2T<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3T<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides4T<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides5T<D>, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer, Windows::UI::Xaml::Automation::Peers::IAutomationPeerProtected, Windows::UI::Xaml::Automation::Peers::IAutomationPeer2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer3, Windows::UI::Xaml::Automation::Peers::IAutomationPeer4, Windows::UI::Xaml::Automation::Peers::IAutomationPeer5, Windows::UI::Xaml::Automation::Peers::IFrameworkElementAutomationPeer, Windows::UI::Xaml::Automation::Peers::ITimePickerAutomationPeer>
{
    using composable = TimePickerAutomationPeer;

protected:

    TimePickerAutomationPeerT(const Windows::UI::Xaml::Controls::TimePicker & owner)
    {
        GetActivationFactory<TimePickerAutomationPeer, ITimePickerAutomationPeerFactory>().CreateInstanceWithOwner(owner, *this, m_inner);
    }
};

template <typename D, typename ... Interfaces> struct ToggleButtonAutomationPeerT :
    overrides<D, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverridesT<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2T<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3T<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides4T<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides5T<D>, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer, Windows::UI::Xaml::Automation::Peers::IAutomationPeerProtected, Windows::UI::Xaml::Automation::Peers::IAutomationPeer2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer3, Windows::UI::Xaml::Automation::Peers::IAutomationPeer4, Windows::UI::Xaml::Automation::Peers::IAutomationPeer5, Windows::UI::Xaml::Automation::Peers::IFrameworkElementAutomationPeer, Windows::UI::Xaml::Automation::Peers::IButtonBaseAutomationPeer, Windows::UI::Xaml::Automation::Peers::IToggleButtonAutomationPeer, Windows::UI::Xaml::Automation::Provider::IToggleProvider>
{
    using composable = ToggleButtonAutomationPeer;

protected:

    ToggleButtonAutomationPeerT(const Windows::UI::Xaml::Controls::Primitives::ToggleButton & owner)
    {
        GetActivationFactory<ToggleButtonAutomationPeer, IToggleButtonAutomationPeerFactory>().CreateInstanceWithOwner(owner, *this, m_inner);
    }
};

template <typename D, typename ... Interfaces> struct ToggleMenuFlyoutItemAutomationPeerT :
    overrides<D, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverridesT<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2T<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3T<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides4T<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides5T<D>, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer, Windows::UI::Xaml::Automation::Peers::IAutomationPeerProtected, Windows::UI::Xaml::Automation::Peers::IAutomationPeer2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer3, Windows::UI::Xaml::Automation::Peers::IAutomationPeer4, Windows::UI::Xaml::Automation::Peers::IAutomationPeer5, Windows::UI::Xaml::Automation::Peers::IFrameworkElementAutomationPeer, Windows::UI::Xaml::Automation::Peers::IToggleMenuFlyoutItemAutomationPeer, Windows::UI::Xaml::Automation::Provider::IToggleProvider>
{
    using composable = ToggleMenuFlyoutItemAutomationPeer;

protected:

    ToggleMenuFlyoutItemAutomationPeerT(const Windows::UI::Xaml::Controls::ToggleMenuFlyoutItem & owner)
    {
        GetActivationFactory<ToggleMenuFlyoutItemAutomationPeer, IToggleMenuFlyoutItemAutomationPeerFactory>().CreateInstanceWithOwner(owner, *this, m_inner);
    }
};

template <typename D, typename ... Interfaces> struct ToggleSwitchAutomationPeerT :
    overrides<D, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverridesT<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2T<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3T<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides4T<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides5T<D>, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer, Windows::UI::Xaml::Automation::Peers::IAutomationPeerProtected, Windows::UI::Xaml::Automation::Peers::IAutomationPeer2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer3, Windows::UI::Xaml::Automation::Peers::IAutomationPeer4, Windows::UI::Xaml::Automation::Peers::IAutomationPeer5, Windows::UI::Xaml::Automation::Peers::IFrameworkElementAutomationPeer, Windows::UI::Xaml::Automation::Peers::IToggleSwitchAutomationPeer, Windows::UI::Xaml::Automation::Provider::IToggleProvider>
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

template <typename D, typename ... Interfaces> struct AppBarT :
    overrides<D, Windows::UI::Xaml::IUIElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverrides2T<D>, Windows::UI::Xaml::Controls::IControlOverridesT<D>, Windows::UI::Xaml::Controls::IContentControlOverridesT<D>, Windows::UI::Xaml::Controls::IAppBarOverridesT<D>, Windows::UI::Xaml::Controls::IAppBarOverrides3T<D>, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IUIElement4, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::IFrameworkElement4, Windows::UI::Xaml::Controls::IControl, Windows::UI::Xaml::Controls::IControlProtected, Windows::UI::Xaml::Controls::IControl2, Windows::UI::Xaml::Controls::IControl3, Windows::UI::Xaml::Controls::IControl4, Windows::UI::Xaml::Controls::IContentControl, Windows::UI::Xaml::Controls::IContentControl2, Windows::UI::Xaml::Controls::IAppBar, Windows::UI::Xaml::Controls::IAppBar2, Windows::UI::Xaml::Controls::IAppBar3, Windows::UI::Xaml::Controls::IAppBar4>
{
    using composable = AppBar;

protected:

    AppBarT()
    {
        GetActivationFactory<AppBar, IAppBarFactory>().CreateInstance(*this, m_inner);
    }
};

template <typename D, typename ... Interfaces> struct AppBarButtonT :
    overrides<D, Windows::UI::Xaml::IUIElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverrides2T<D>, Windows::UI::Xaml::Controls::IControlOverridesT<D>, Windows::UI::Xaml::Controls::IContentControlOverridesT<D>, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IUIElement4, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::IFrameworkElement4, Windows::UI::Xaml::Controls::IControl, Windows::UI::Xaml::Controls::IControlProtected, Windows::UI::Xaml::Controls::IControl2, Windows::UI::Xaml::Controls::IControl3, Windows::UI::Xaml::Controls::IControl4, Windows::UI::Xaml::Controls::IContentControl, Windows::UI::Xaml::Controls::IContentControl2, Windows::UI::Xaml::Controls::Primitives::IButtonBase, Windows::UI::Xaml::Controls::IButton, Windows::UI::Xaml::Controls::IButtonWithFlyout, Windows::UI::Xaml::Controls::IAppBarButton, Windows::UI::Xaml::Controls::ICommandBarElement, Windows::UI::Xaml::Controls::IAppBarButton3, Windows::UI::Xaml::Controls::ICommandBarElement2>
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
    impl::require<D, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IUIElement4, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::IFrameworkElement4, Windows::UI::Xaml::Controls::IControl, Windows::UI::Xaml::Controls::IControlProtected, Windows::UI::Xaml::Controls::IControl2, Windows::UI::Xaml::Controls::IControl3, Windows::UI::Xaml::Controls::IControl4, Windows::UI::Xaml::Controls::IAppBarSeparator, Windows::UI::Xaml::Controls::ICommandBarElement, Windows::UI::Xaml::Controls::ICommandBarElement2>
{
    using composable = AppBarSeparator;

protected:

    AppBarSeparatorT()
    {
        GetActivationFactory<AppBarSeparator, IAppBarSeparatorFactory>().CreateInstance(*this, m_inner);
    }
};

template <typename D, typename ... Interfaces> struct AppBarToggleButtonT :
    overrides<D, Windows::UI::Xaml::IUIElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverrides2T<D>, Windows::UI::Xaml::Controls::IControlOverridesT<D>, Windows::UI::Xaml::Controls::IContentControlOverridesT<D>, Windows::UI::Xaml::Controls::Primitives::IToggleButtonOverridesT<D>, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IUIElement4, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::IFrameworkElement4, Windows::UI::Xaml::Controls::IControl, Windows::UI::Xaml::Controls::IControlProtected, Windows::UI::Xaml::Controls::IControl2, Windows::UI::Xaml::Controls::IControl3, Windows::UI::Xaml::Controls::IControl4, Windows::UI::Xaml::Controls::IContentControl, Windows::UI::Xaml::Controls::IContentControl2, Windows::UI::Xaml::Controls::Primitives::IButtonBase, Windows::UI::Xaml::Controls::Primitives::IToggleButton, Windows::UI::Xaml::Controls::IAppBarToggleButton, Windows::UI::Xaml::Controls::ICommandBarElement, Windows::UI::Xaml::Controls::IAppBarToggleButton3, Windows::UI::Xaml::Controls::ICommandBarElement2>
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
    impl::require<D, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IUIElement4, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::IFrameworkElement4, Windows::UI::Xaml::Controls::IIconElement, Windows::UI::Xaml::Controls::IBitmapIcon>
{
    using composable = BitmapIcon;

protected:

    BitmapIconT()
    {
        GetActivationFactory<BitmapIcon, IBitmapIconFactory>().CreateInstance(*this, m_inner);
    }
};

template <typename D, typename ... Interfaces> struct ButtonT :
    overrides<D, Windows::UI::Xaml::IUIElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverrides2T<D>, Windows::UI::Xaml::Controls::IControlOverridesT<D>, Windows::UI::Xaml::Controls::IContentControlOverridesT<D>, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IUIElement4, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::IFrameworkElement4, Windows::UI::Xaml::Controls::IControl, Windows::UI::Xaml::Controls::IControlProtected, Windows::UI::Xaml::Controls::IControl2, Windows::UI::Xaml::Controls::IControl3, Windows::UI::Xaml::Controls::IControl4, Windows::UI::Xaml::Controls::IContentControl, Windows::UI::Xaml::Controls::IContentControl2, Windows::UI::Xaml::Controls::Primitives::IButtonBase, Windows::UI::Xaml::Controls::IButton, Windows::UI::Xaml::Controls::IButtonWithFlyout>
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
    impl::require<D, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IUIElement4, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::IFrameworkElement4, Windows::UI::Xaml::Controls::IControl, Windows::UI::Xaml::Controls::IControlProtected, Windows::UI::Xaml::Controls::IControl2, Windows::UI::Xaml::Controls::IControl3, Windows::UI::Xaml::Controls::IControl4, Windows::UI::Xaml::Controls::ICalendarDatePicker, Windows::UI::Xaml::Controls::ICalendarDatePicker2>
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
    impl::require<D, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IUIElement4, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::IFrameworkElement4, Windows::UI::Xaml::Controls::IControl, Windows::UI::Xaml::Controls::IControlProtected, Windows::UI::Xaml::Controls::IControl2, Windows::UI::Xaml::Controls::IControl3, Windows::UI::Xaml::Controls::IControl4, Windows::UI::Xaml::Controls::ICalendarView>
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
    impl::require<D, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IUIElement4, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::IFrameworkElement4, Windows::UI::Xaml::Controls::IControl, Windows::UI::Xaml::Controls::IControlProtected, Windows::UI::Xaml::Controls::IControl2, Windows::UI::Xaml::Controls::IControl3, Windows::UI::Xaml::Controls::IControl4, Windows::UI::Xaml::Controls::ICalendarViewDayItem>
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
    impl::require<D, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IUIElement4, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::IFrameworkElement4, Windows::UI::Xaml::Controls::IPanel, Windows::UI::Xaml::Controls::ICanvas>
{
    using composable = Canvas;

protected:

    CanvasT()
    {
        GetActivationFactory<Canvas, ICanvasFactory>().CreateInstance(*this, m_inner);
    }
};

template <typename D, typename ... Interfaces> struct CheckBoxT :
    overrides<D, Windows::UI::Xaml::IUIElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverrides2T<D>, Windows::UI::Xaml::Controls::IControlOverridesT<D>, Windows::UI::Xaml::Controls::IContentControlOverridesT<D>, Windows::UI::Xaml::Controls::Primitives::IToggleButtonOverridesT<D>, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IUIElement4, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::IFrameworkElement4, Windows::UI::Xaml::Controls::IControl, Windows::UI::Xaml::Controls::IControlProtected, Windows::UI::Xaml::Controls::IControl2, Windows::UI::Xaml::Controls::IControl3, Windows::UI::Xaml::Controls::IControl4, Windows::UI::Xaml::Controls::IContentControl, Windows::UI::Xaml::Controls::IContentControl2, Windows::UI::Xaml::Controls::Primitives::IButtonBase, Windows::UI::Xaml::Controls::Primitives::IToggleButton, Windows::UI::Xaml::Controls::ICheckBox>
{
    using composable = CheckBox;

protected:

    CheckBoxT()
    {
        GetActivationFactory<CheckBox, ICheckBoxFactory>().CreateInstance(*this, m_inner);
    }
};

template <typename D, typename ... Interfaces> struct ComboBoxT :
    overrides<D, Windows::UI::Xaml::IUIElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverrides2T<D>, Windows::UI::Xaml::Controls::IControlOverridesT<D>, Windows::UI::Xaml::Controls::IItemsControlOverridesT<D>, Windows::UI::Xaml::Controls::IComboBoxOverridesT<D>, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IUIElement4, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::IFrameworkElement4, Windows::UI::Xaml::Controls::IControl, Windows::UI::Xaml::Controls::IControlProtected, Windows::UI::Xaml::Controls::IControl2, Windows::UI::Xaml::Controls::IControl3, Windows::UI::Xaml::Controls::IControl4, Windows::UI::Xaml::Controls::IItemsControl, Windows::UI::Xaml::Controls::IItemsControl2, Windows::UI::Xaml::Controls::IItemContainerMapping, Windows::UI::Xaml::Controls::IItemsControl3, Windows::UI::Xaml::Controls::Primitives::ISelector, Windows::UI::Xaml::Controls::IComboBox, Windows::UI::Xaml::Controls::IComboBox2, Windows::UI::Xaml::Controls::IComboBox3>
{
    using composable = ComboBox;

protected:

    ComboBoxT()
    {
        GetActivationFactory<ComboBox, IComboBoxFactory>().CreateInstance(*this, m_inner);
    }
};

template <typename D, typename ... Interfaces> struct ComboBoxItemT :
    overrides<D, Windows::UI::Xaml::IUIElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverrides2T<D>, Windows::UI::Xaml::Controls::IControlOverridesT<D>, Windows::UI::Xaml::Controls::IContentControlOverridesT<D>, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IUIElement4, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::IFrameworkElement4, Windows::UI::Xaml::Controls::IControl, Windows::UI::Xaml::Controls::IControlProtected, Windows::UI::Xaml::Controls::IControl2, Windows::UI::Xaml::Controls::IControl3, Windows::UI::Xaml::Controls::IControl4, Windows::UI::Xaml::Controls::IContentControl, Windows::UI::Xaml::Controls::IContentControl2, Windows::UI::Xaml::Controls::Primitives::ISelectorItem, Windows::UI::Xaml::Controls::IComboBoxItem>
{
    using composable = ComboBoxItem;

protected:

    ComboBoxItemT()
    {
        GetActivationFactory<ComboBoxItem, IComboBoxItemFactory>().CreateInstance(*this, m_inner);
    }
};

template <typename D, typename ... Interfaces> struct CommandBarT :
    overrides<D, Windows::UI::Xaml::IUIElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverrides2T<D>, Windows::UI::Xaml::Controls::IControlOverridesT<D>, Windows::UI::Xaml::Controls::IContentControlOverridesT<D>, Windows::UI::Xaml::Controls::IAppBarOverridesT<D>, Windows::UI::Xaml::Controls::IAppBarOverrides3T<D>, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IUIElement4, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::IFrameworkElement4, Windows::UI::Xaml::Controls::IControl, Windows::UI::Xaml::Controls::IControlProtected, Windows::UI::Xaml::Controls::IControl2, Windows::UI::Xaml::Controls::IControl3, Windows::UI::Xaml::Controls::IControl4, Windows::UI::Xaml::Controls::IContentControl, Windows::UI::Xaml::Controls::IContentControl2, Windows::UI::Xaml::Controls::IAppBar, Windows::UI::Xaml::Controls::IAppBar2, Windows::UI::Xaml::Controls::IAppBar3, Windows::UI::Xaml::Controls::IAppBar4, Windows::UI::Xaml::Controls::ICommandBar, Windows::UI::Xaml::Controls::ICommandBar2, Windows::UI::Xaml::Controls::ICommandBar3>
{
    using composable = CommandBar;

protected:

    CommandBarT()
    {
        GetActivationFactory<CommandBar, ICommandBarFactory>().CreateInstance(*this, m_inner);
    }
};

template <typename D, typename ... Interfaces> struct CommandBarOverflowPresenterT :
    overrides<D, Windows::UI::Xaml::IUIElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverrides2T<D>, Windows::UI::Xaml::Controls::IControlOverridesT<D>, Windows::UI::Xaml::Controls::IItemsControlOverridesT<D>, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IUIElement4, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::IFrameworkElement4, Windows::UI::Xaml::Controls::IControl, Windows::UI::Xaml::Controls::IControlProtected, Windows::UI::Xaml::Controls::IControl2, Windows::UI::Xaml::Controls::IControl3, Windows::UI::Xaml::Controls::IControl4, Windows::UI::Xaml::Controls::IItemsControl, Windows::UI::Xaml::Controls::IItemsControl2, Windows::UI::Xaml::Controls::IItemContainerMapping, Windows::UI::Xaml::Controls::IItemsControl3, Windows::UI::Xaml::Controls::ICommandBarOverflowPresenter>
{
    using composable = CommandBarOverflowPresenter;

protected:

    CommandBarOverflowPresenterT()
    {
        GetActivationFactory<CommandBarOverflowPresenter, ICommandBarOverflowPresenterFactory>().CreateInstance(*this, m_inner);
    }
};

template <typename D, typename ... Interfaces> struct ContentControlT :
    overrides<D, Windows::UI::Xaml::IUIElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverrides2T<D>, Windows::UI::Xaml::Controls::IControlOverridesT<D>, Windows::UI::Xaml::Controls::IContentControlOverridesT<D>, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IUIElement4, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::IFrameworkElement4, Windows::UI::Xaml::Controls::IControl, Windows::UI::Xaml::Controls::IControlProtected, Windows::UI::Xaml::Controls::IControl2, Windows::UI::Xaml::Controls::IControl3, Windows::UI::Xaml::Controls::IControl4, Windows::UI::Xaml::Controls::IContentControl, Windows::UI::Xaml::Controls::IContentControl2>
{
    using composable = ContentControl;

protected:

    ContentControlT()
    {
        GetActivationFactory<ContentControl, IContentControlFactory>().CreateInstance(*this, m_inner);
    }
};

template <typename D, typename ... Interfaces> struct ContentDialogT :
    overrides<D, Windows::UI::Xaml::IUIElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverrides2T<D>, Windows::UI::Xaml::Controls::IControlOverridesT<D>, Windows::UI::Xaml::Controls::IContentControlOverridesT<D>, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IUIElement4, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::IFrameworkElement4, Windows::UI::Xaml::Controls::IControl, Windows::UI::Xaml::Controls::IControlProtected, Windows::UI::Xaml::Controls::IControl2, Windows::UI::Xaml::Controls::IControl3, Windows::UI::Xaml::Controls::IControl4, Windows::UI::Xaml::Controls::IContentControl, Windows::UI::Xaml::Controls::IContentControl2, Windows::UI::Xaml::Controls::IContentDialog>
{
    using composable = ContentDialog;

protected:

    ContentDialogT()
    {
        GetActivationFactory<ContentDialog, IContentDialogFactory>().CreateInstance(*this, m_inner);
    }
};

template <typename D, typename ... Interfaces> struct ContentPresenterT :
    overrides<D, Windows::UI::Xaml::IUIElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverrides2T<D>, Windows::UI::Xaml::Controls::IContentPresenterOverridesT<D>, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IUIElement4, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::IFrameworkElement4, Windows::UI::Xaml::Controls::IContentPresenter, Windows::UI::Xaml::Controls::IContentPresenter2, Windows::UI::Xaml::Controls::IContentPresenter3, Windows::UI::Xaml::Controls::IContentPresenter4>
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
    impl::require<D, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IUIElement4, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::IFrameworkElement4, Windows::UI::Xaml::Controls::IControl, Windows::UI::Xaml::Controls::IControlProtected, Windows::UI::Xaml::Controls::IControl2, Windows::UI::Xaml::Controls::IControl3, Windows::UI::Xaml::Controls::IControl4, Windows::UI::Xaml::Controls::IDatePicker, Windows::UI::Xaml::Controls::IDatePicker2>
{
    using composable = DatePicker;

protected:

    DatePickerT()
    {
        GetActivationFactory<DatePicker, IDatePickerFactory>().CreateInstance(*this, m_inner);
    }
};

template <typename D, typename ... Interfaces> struct FlipViewT :
    overrides<D, Windows::UI::Xaml::IUIElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverrides2T<D>, Windows::UI::Xaml::Controls::IControlOverridesT<D>, Windows::UI::Xaml::Controls::IItemsControlOverridesT<D>, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IUIElement4, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::IFrameworkElement4, Windows::UI::Xaml::Controls::IControl, Windows::UI::Xaml::Controls::IControlProtected, Windows::UI::Xaml::Controls::IControl2, Windows::UI::Xaml::Controls::IControl3, Windows::UI::Xaml::Controls::IControl4, Windows::UI::Xaml::Controls::IItemsControl, Windows::UI::Xaml::Controls::IItemsControl2, Windows::UI::Xaml::Controls::IItemContainerMapping, Windows::UI::Xaml::Controls::IItemsControl3, Windows::UI::Xaml::Controls::Primitives::ISelector, Windows::UI::Xaml::Controls::IFlipView, Windows::UI::Xaml::Controls::IFlipView2>
{
    using composable = FlipView;

protected:

    FlipViewT()
    {
        GetActivationFactory<FlipView, IFlipViewFactory>().CreateInstance(*this, m_inner);
    }
};

template <typename D, typename ... Interfaces> struct FlipViewItemT :
    overrides<D, Windows::UI::Xaml::IUIElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverrides2T<D>, Windows::UI::Xaml::Controls::IControlOverridesT<D>, Windows::UI::Xaml::Controls::IContentControlOverridesT<D>, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IUIElement4, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::IFrameworkElement4, Windows::UI::Xaml::Controls::IControl, Windows::UI::Xaml::Controls::IControlProtected, Windows::UI::Xaml::Controls::IControl2, Windows::UI::Xaml::Controls::IControl3, Windows::UI::Xaml::Controls::IControl4, Windows::UI::Xaml::Controls::IContentControl, Windows::UI::Xaml::Controls::IContentControl2, Windows::UI::Xaml::Controls::Primitives::ISelectorItem, Windows::UI::Xaml::Controls::IFlipViewItem>
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
    impl::require<D, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Controls::Primitives::IFlyoutBase, Windows::UI::Xaml::Controls::Primitives::IFlyoutBase2, Windows::UI::Xaml::Controls::IFlyout>
{
    using composable = Flyout;

protected:

    FlyoutT()
    {
        GetActivationFactory<Flyout, IFlyoutFactory>().CreateInstance(*this, m_inner);
    }
};

template <typename D, typename ... Interfaces> struct FlyoutPresenterT :
    overrides<D, Windows::UI::Xaml::IUIElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverrides2T<D>, Windows::UI::Xaml::Controls::IControlOverridesT<D>, Windows::UI::Xaml::Controls::IContentControlOverridesT<D>, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IUIElement4, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::IFrameworkElement4, Windows::UI::Xaml::Controls::IControl, Windows::UI::Xaml::Controls::IControlProtected, Windows::UI::Xaml::Controls::IControl2, Windows::UI::Xaml::Controls::IControl3, Windows::UI::Xaml::Controls::IControl4, Windows::UI::Xaml::Controls::IContentControl, Windows::UI::Xaml::Controls::IContentControl2, Windows::UI::Xaml::Controls::IFlyoutPresenter>
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
    impl::require<D, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IUIElement4, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::IFrameworkElement4, Windows::UI::Xaml::Controls::IIconElement, Windows::UI::Xaml::Controls::IFontIcon, Windows::UI::Xaml::Controls::IFontIcon2, Windows::UI::Xaml::Controls::IFontIcon3>
{
    using composable = FontIcon;

protected:

    FontIconT()
    {
        GetActivationFactory<FontIcon, IFontIconFactory>().CreateInstance(*this, m_inner);
    }
};

template <typename D, typename ... Interfaces> struct FrameT :
    overrides<D, Windows::UI::Xaml::IUIElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverrides2T<D>, Windows::UI::Xaml::Controls::IControlOverridesT<D>, Windows::UI::Xaml::Controls::IContentControlOverridesT<D>, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IUIElement4, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::IFrameworkElement4, Windows::UI::Xaml::Controls::IControl, Windows::UI::Xaml::Controls::IControlProtected, Windows::UI::Xaml::Controls::IControl2, Windows::UI::Xaml::Controls::IControl3, Windows::UI::Xaml::Controls::IControl4, Windows::UI::Xaml::Controls::IContentControl, Windows::UI::Xaml::Controls::IContentControl2, Windows::UI::Xaml::Controls::IFrame, Windows::UI::Xaml::Controls::INavigate, Windows::UI::Xaml::Controls::IFrame2, Windows::UI::Xaml::Controls::IFrame3>
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
    impl::require<D, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IUIElement4, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::IFrameworkElement4, Windows::UI::Xaml::Controls::IPanel, Windows::UI::Xaml::Controls::IGrid, Windows::UI::Xaml::Controls::IGrid2>
{
    using composable = Grid;

protected:

    GridT()
    {
        GetActivationFactory<Grid, IGridFactory>().CreateInstance(*this, m_inner);
    }
};

template <typename D, typename ... Interfaces> struct GridViewT :
    overrides<D, Windows::UI::Xaml::IUIElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverrides2T<D>, Windows::UI::Xaml::Controls::IControlOverridesT<D>, Windows::UI::Xaml::Controls::IItemsControlOverridesT<D>, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IUIElement4, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::IFrameworkElement4, Windows::UI::Xaml::Controls::IControl, Windows::UI::Xaml::Controls::IControlProtected, Windows::UI::Xaml::Controls::IControl2, Windows::UI::Xaml::Controls::IControl3, Windows::UI::Xaml::Controls::IControl4, Windows::UI::Xaml::Controls::IItemsControl, Windows::UI::Xaml::Controls::IItemsControl2, Windows::UI::Xaml::Controls::IItemContainerMapping, Windows::UI::Xaml::Controls::IItemsControl3, Windows::UI::Xaml::Controls::Primitives::ISelector, Windows::UI::Xaml::Controls::IListViewBase, Windows::UI::Xaml::Controls::ISemanticZoomInformation, Windows::UI::Xaml::Controls::IListViewBase2, Windows::UI::Xaml::Controls::IListViewBase3, Windows::UI::Xaml::Controls::IListViewBase4, Windows::UI::Xaml::Controls::IListViewBase5, Windows::UI::Xaml::Controls::IGridView>
{
    using composable = GridView;

protected:

    GridViewT()
    {
        GetActivationFactory<GridView, IGridViewFactory>().CreateInstance(*this, m_inner);
    }
};

template <typename D, typename ... Interfaces> struct GridViewHeaderItemT :
    overrides<D, Windows::UI::Xaml::IUIElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverrides2T<D>, Windows::UI::Xaml::Controls::IControlOverridesT<D>, Windows::UI::Xaml::Controls::IContentControlOverridesT<D>, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IUIElement4, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::IFrameworkElement4, Windows::UI::Xaml::Controls::IControl, Windows::UI::Xaml::Controls::IControlProtected, Windows::UI::Xaml::Controls::IControl2, Windows::UI::Xaml::Controls::IControl3, Windows::UI::Xaml::Controls::IControl4, Windows::UI::Xaml::Controls::IContentControl, Windows::UI::Xaml::Controls::IContentControl2, Windows::UI::Xaml::Controls::IListViewBaseHeaderItem, Windows::UI::Xaml::Controls::IGridViewHeaderItem>
{
    using composable = GridViewHeaderItem;

protected:

    GridViewHeaderItemT()
    {
        GetActivationFactory<GridViewHeaderItem, IGridViewHeaderItemFactory>().CreateInstance(*this, m_inner);
    }
};

template <typename D, typename ... Interfaces> struct GridViewItemT :
    overrides<D, Windows::UI::Xaml::IUIElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverrides2T<D>, Windows::UI::Xaml::Controls::IControlOverridesT<D>, Windows::UI::Xaml::Controls::IContentControlOverridesT<D>, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IUIElement4, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::IFrameworkElement4, Windows::UI::Xaml::Controls::IControl, Windows::UI::Xaml::Controls::IControlProtected, Windows::UI::Xaml::Controls::IControl2, Windows::UI::Xaml::Controls::IControl3, Windows::UI::Xaml::Controls::IControl4, Windows::UI::Xaml::Controls::IContentControl, Windows::UI::Xaml::Controls::IContentControl2, Windows::UI::Xaml::Controls::Primitives::ISelectorItem, Windows::UI::Xaml::Controls::IGridViewItem>
{
    using composable = GridViewItem;

protected:

    GridViewItemT()
    {
        GetActivationFactory<GridViewItem, IGridViewItemFactory>().CreateInstance(*this, m_inner);
    }
};

template <typename D, typename ... Interfaces> struct GroupItemT :
    overrides<D, Windows::UI::Xaml::IUIElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverrides2T<D>, Windows::UI::Xaml::Controls::IControlOverridesT<D>, Windows::UI::Xaml::Controls::IContentControlOverridesT<D>, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IUIElement4, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::IFrameworkElement4, Windows::UI::Xaml::Controls::IControl, Windows::UI::Xaml::Controls::IControlProtected, Windows::UI::Xaml::Controls::IControl2, Windows::UI::Xaml::Controls::IControl3, Windows::UI::Xaml::Controls::IControl4, Windows::UI::Xaml::Controls::IContentControl, Windows::UI::Xaml::Controls::IContentControl2, Windows::UI::Xaml::Controls::IGroupItem>
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
    impl::require<D, Windows::UI::Xaml::Controls::IGroupStyle, Windows::UI::Xaml::Data::INotifyPropertyChanged, Windows::UI::Xaml::Controls::IGroupStyle2>
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
    impl::require<D, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IUIElement4, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::IFrameworkElement4, Windows::UI::Xaml::Controls::IControl, Windows::UI::Xaml::Controls::IControlProtected, Windows::UI::Xaml::Controls::IControl2, Windows::UI::Xaml::Controls::IControl3, Windows::UI::Xaml::Controls::IControl4, Windows::UI::Xaml::Controls::IHub, Windows::UI::Xaml::Controls::ISemanticZoomInformation>
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
    impl::require<D, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IUIElement4, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::IFrameworkElement4, Windows::UI::Xaml::Controls::IControl, Windows::UI::Xaml::Controls::IControlProtected, Windows::UI::Xaml::Controls::IControl2, Windows::UI::Xaml::Controls::IControl3, Windows::UI::Xaml::Controls::IControl4, Windows::UI::Xaml::Controls::IHubSection>
{
    using composable = HubSection;

protected:

    HubSectionT()
    {
        GetActivationFactory<HubSection, IHubSectionFactory>().CreateInstance(*this, m_inner);
    }
};

template <typename D, typename ... Interfaces> struct HyperlinkButtonT :
    overrides<D, Windows::UI::Xaml::IUIElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverrides2T<D>, Windows::UI::Xaml::Controls::IControlOverridesT<D>, Windows::UI::Xaml::Controls::IContentControlOverridesT<D>, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IUIElement4, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::IFrameworkElement4, Windows::UI::Xaml::Controls::IControl, Windows::UI::Xaml::Controls::IControlProtected, Windows::UI::Xaml::Controls::IControl2, Windows::UI::Xaml::Controls::IControl3, Windows::UI::Xaml::Controls::IControl4, Windows::UI::Xaml::Controls::IContentControl, Windows::UI::Xaml::Controls::IContentControl2, Windows::UI::Xaml::Controls::Primitives::IButtonBase, Windows::UI::Xaml::Controls::IHyperlinkButton>
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
    impl::require<D, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IUIElement4, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::IFrameworkElement4, Windows::UI::Xaml::Controls::IInkCanvas>
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
    overrides<D, Windows::UI::Xaml::IUIElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverrides2T<D>, Windows::UI::Xaml::Controls::IControlOverridesT<D>, Windows::UI::Xaml::Controls::IContentControlOverridesT<D>, Windows::UI::Xaml::Controls::Primitives::IToggleButtonOverridesT<D>, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IUIElement4, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::IFrameworkElement4, Windows::UI::Xaml::Controls::IControl, Windows::UI::Xaml::Controls::IControlProtected, Windows::UI::Xaml::Controls::IControl2, Windows::UI::Xaml::Controls::IControl3, Windows::UI::Xaml::Controls::IControl4, Windows::UI::Xaml::Controls::IContentControl, Windows::UI::Xaml::Controls::IContentControl2, Windows::UI::Xaml::Controls::Primitives::IButtonBase, Windows::UI::Xaml::Controls::Primitives::IToggleButton, Windows::UI::Xaml::Controls::IRadioButton, Windows::UI::Xaml::Controls::IInkToolbarToolButton, Windows::UI::Xaml::Controls::IInkToolbarPenButton, Windows::UI::Xaml::Controls::IInkToolbarBallpointPenButton>
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
    overrides<D, Windows::UI::Xaml::IUIElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverrides2T<D>, Windows::UI::Xaml::Controls::IControlOverridesT<D>, Windows::UI::Xaml::Controls::IContentControlOverridesT<D>, Windows::UI::Xaml::Controls::Primitives::IToggleButtonOverridesT<D>, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IUIElement4, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::IFrameworkElement4, Windows::UI::Xaml::Controls::IControl, Windows::UI::Xaml::Controls::IControlProtected, Windows::UI::Xaml::Controls::IControl2, Windows::UI::Xaml::Controls::IControl3, Windows::UI::Xaml::Controls::IControl4, Windows::UI::Xaml::Controls::IContentControl, Windows::UI::Xaml::Controls::IContentControl2, Windows::UI::Xaml::Controls::Primitives::IButtonBase, Windows::UI::Xaml::Controls::Primitives::IToggleButton, Windows::UI::Xaml::Controls::IRadioButton, Windows::UI::Xaml::Controls::IInkToolbarToolButton, Windows::UI::Xaml::Controls::IInkToolbarPenButton, Windows::UI::Xaml::Controls::IInkToolbarCustomPenButton>
{
    using composable = InkToolbarCustomPenButton;

protected:

    InkToolbarCustomPenButtonT()
    {
        GetActivationFactory<InkToolbarCustomPenButton, IInkToolbarCustomPenButtonFactory>().CreateInstance(*this, m_inner);
    }
};

template <typename D, typename ... Interfaces> struct InkToolbarCustomToggleButtonT :
    overrides<D, Windows::UI::Xaml::IUIElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverrides2T<D>, Windows::UI::Xaml::Controls::IControlOverridesT<D>, Windows::UI::Xaml::Controls::IContentControlOverridesT<D>, Windows::UI::Xaml::Controls::Primitives::IToggleButtonOverridesT<D>, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IUIElement4, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::IFrameworkElement4, Windows::UI::Xaml::Controls::IControl, Windows::UI::Xaml::Controls::IControlProtected, Windows::UI::Xaml::Controls::IControl2, Windows::UI::Xaml::Controls::IControl3, Windows::UI::Xaml::Controls::IControl4, Windows::UI::Xaml::Controls::IContentControl, Windows::UI::Xaml::Controls::IContentControl2, Windows::UI::Xaml::Controls::Primitives::IButtonBase, Windows::UI::Xaml::Controls::Primitives::IToggleButton, Windows::UI::Xaml::Controls::ICheckBox, Windows::UI::Xaml::Controls::IInkToolbarToggleButton, Windows::UI::Xaml::Controls::IInkToolbarCustomToggleButton>
{
    using composable = InkToolbarCustomToggleButton;

protected:

    InkToolbarCustomToggleButtonT()
    {
        GetActivationFactory<InkToolbarCustomToggleButton, IInkToolbarCustomToggleButtonFactory>().CreateInstance(*this, m_inner);
    }
};

template <typename D, typename ... Interfaces> struct InkToolbarCustomToolButtonT :
    overrides<D, Windows::UI::Xaml::IUIElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverrides2T<D>, Windows::UI::Xaml::Controls::IControlOverridesT<D>, Windows::UI::Xaml::Controls::IContentControlOverridesT<D>, Windows::UI::Xaml::Controls::Primitives::IToggleButtonOverridesT<D>, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IUIElement4, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::IFrameworkElement4, Windows::UI::Xaml::Controls::IControl, Windows::UI::Xaml::Controls::IControlProtected, Windows::UI::Xaml::Controls::IControl2, Windows::UI::Xaml::Controls::IControl3, Windows::UI::Xaml::Controls::IControl4, Windows::UI::Xaml::Controls::IContentControl, Windows::UI::Xaml::Controls::IContentControl2, Windows::UI::Xaml::Controls::Primitives::IButtonBase, Windows::UI::Xaml::Controls::Primitives::IToggleButton, Windows::UI::Xaml::Controls::IRadioButton, Windows::UI::Xaml::Controls::IInkToolbarToolButton, Windows::UI::Xaml::Controls::IInkToolbarCustomToolButton>
{
    using composable = InkToolbarCustomToolButton;

protected:

    InkToolbarCustomToolButtonT()
    {
        GetActivationFactory<InkToolbarCustomToolButton, IInkToolbarCustomToolButtonFactory>().CreateInstance(*this, m_inner);
    }
};

template <typename D, typename ... Interfaces> struct InkToolbarEraserButtonT :
    overrides<D, Windows::UI::Xaml::IUIElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverrides2T<D>, Windows::UI::Xaml::Controls::IControlOverridesT<D>, Windows::UI::Xaml::Controls::IContentControlOverridesT<D>, Windows::UI::Xaml::Controls::Primitives::IToggleButtonOverridesT<D>, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IUIElement4, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::IFrameworkElement4, Windows::UI::Xaml::Controls::IControl, Windows::UI::Xaml::Controls::IControlProtected, Windows::UI::Xaml::Controls::IControl2, Windows::UI::Xaml::Controls::IControl3, Windows::UI::Xaml::Controls::IControl4, Windows::UI::Xaml::Controls::IContentControl, Windows::UI::Xaml::Controls::IContentControl2, Windows::UI::Xaml::Controls::Primitives::IButtonBase, Windows::UI::Xaml::Controls::Primitives::IToggleButton, Windows::UI::Xaml::Controls::IRadioButton, Windows::UI::Xaml::Controls::IInkToolbarToolButton, Windows::UI::Xaml::Controls::IInkToolbarEraserButton>
{
    using composable = InkToolbarEraserButton;

protected:

    InkToolbarEraserButtonT()
    {
        GetActivationFactory<InkToolbarEraserButton, IInkToolbarEraserButtonFactory>().CreateInstance(*this, m_inner);
    }
};

template <typename D, typename ... Interfaces> struct InkToolbarHighlighterButtonT :
    overrides<D, Windows::UI::Xaml::IUIElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverrides2T<D>, Windows::UI::Xaml::Controls::IControlOverridesT<D>, Windows::UI::Xaml::Controls::IContentControlOverridesT<D>, Windows::UI::Xaml::Controls::Primitives::IToggleButtonOverridesT<D>, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IUIElement4, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::IFrameworkElement4, Windows::UI::Xaml::Controls::IControl, Windows::UI::Xaml::Controls::IControlProtected, Windows::UI::Xaml::Controls::IControl2, Windows::UI::Xaml::Controls::IControl3, Windows::UI::Xaml::Controls::IControl4, Windows::UI::Xaml::Controls::IContentControl, Windows::UI::Xaml::Controls::IContentControl2, Windows::UI::Xaml::Controls::Primitives::IButtonBase, Windows::UI::Xaml::Controls::Primitives::IToggleButton, Windows::UI::Xaml::Controls::IRadioButton, Windows::UI::Xaml::Controls::IInkToolbarToolButton, Windows::UI::Xaml::Controls::IInkToolbarPenButton, Windows::UI::Xaml::Controls::IInkToolbarHighlighterButton>
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
    overrides<D, Windows::UI::Xaml::IUIElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverrides2T<D>, Windows::UI::Xaml::Controls::IControlOverridesT<D>, Windows::UI::Xaml::Controls::IContentControlOverridesT<D>, Windows::UI::Xaml::Controls::Primitives::IToggleButtonOverridesT<D>, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IUIElement4, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::IFrameworkElement4, Windows::UI::Xaml::Controls::IControl, Windows::UI::Xaml::Controls::IControlProtected, Windows::UI::Xaml::Controls::IControl2, Windows::UI::Xaml::Controls::IControl3, Windows::UI::Xaml::Controls::IControl4, Windows::UI::Xaml::Controls::IContentControl, Windows::UI::Xaml::Controls::IContentControl2, Windows::UI::Xaml::Controls::Primitives::IButtonBase, Windows::UI::Xaml::Controls::Primitives::IToggleButton, Windows::UI::Xaml::Controls::IRadioButton, Windows::UI::Xaml::Controls::IInkToolbarToolButton, Windows::UI::Xaml::Controls::IInkToolbarPenButton, Windows::UI::Xaml::Controls::IInkToolbarPencilButton>
{
    using composable = InkToolbarPencilButton;

protected:

    InkToolbarPencilButtonT()
    {
        GetActivationFactory<InkToolbarPencilButton, IInkToolbarPencilButtonFactory>().CreateInstance(*this, m_inner);
    }
};

template <typename D, typename ... Interfaces> struct InkToolbarRulerButtonT :
    overrides<D, Windows::UI::Xaml::IUIElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverrides2T<D>, Windows::UI::Xaml::Controls::IControlOverridesT<D>, Windows::UI::Xaml::Controls::IContentControlOverridesT<D>, Windows::UI::Xaml::Controls::Primitives::IToggleButtonOverridesT<D>, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IUIElement4, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::IFrameworkElement4, Windows::UI::Xaml::Controls::IControl, Windows::UI::Xaml::Controls::IControlProtected, Windows::UI::Xaml::Controls::IControl2, Windows::UI::Xaml::Controls::IControl3, Windows::UI::Xaml::Controls::IControl4, Windows::UI::Xaml::Controls::IContentControl, Windows::UI::Xaml::Controls::IContentControl2, Windows::UI::Xaml::Controls::Primitives::IButtonBase, Windows::UI::Xaml::Controls::Primitives::IToggleButton, Windows::UI::Xaml::Controls::ICheckBox, Windows::UI::Xaml::Controls::IInkToolbarToggleButton, Windows::UI::Xaml::Controls::IInkToolbarRulerButton>
{
    using composable = InkToolbarRulerButton;

protected:

    InkToolbarRulerButtonT()
    {
        GetActivationFactory<InkToolbarRulerButton, IInkToolbarRulerButtonFactory>().CreateInstance(*this, m_inner);
    }
};

template <typename D, typename ... Interfaces> struct ItemsControlT :
    overrides<D, Windows::UI::Xaml::IUIElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverrides2T<D>, Windows::UI::Xaml::Controls::IControlOverridesT<D>, Windows::UI::Xaml::Controls::IItemsControlOverridesT<D>, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IUIElement4, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::IFrameworkElement4, Windows::UI::Xaml::Controls::IControl, Windows::UI::Xaml::Controls::IControlProtected, Windows::UI::Xaml::Controls::IControl2, Windows::UI::Xaml::Controls::IControl3, Windows::UI::Xaml::Controls::IControl4, Windows::UI::Xaml::Controls::IItemsControl, Windows::UI::Xaml::Controls::IItemsControl2, Windows::UI::Xaml::Controls::IItemContainerMapping, Windows::UI::Xaml::Controls::IItemsControl3>
{
    using composable = ItemsControl;

protected:

    ItemsControlT()
    {
        GetActivationFactory<ItemsControl, IItemsControlFactory>().CreateInstance(*this, m_inner);
    }
};

template <typename D, typename ... Interfaces> struct ListBoxT :
    overrides<D, Windows::UI::Xaml::IUIElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverrides2T<D>, Windows::UI::Xaml::Controls::IControlOverridesT<D>, Windows::UI::Xaml::Controls::IItemsControlOverridesT<D>, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IUIElement4, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::IFrameworkElement4, Windows::UI::Xaml::Controls::IControl, Windows::UI::Xaml::Controls::IControlProtected, Windows::UI::Xaml::Controls::IControl2, Windows::UI::Xaml::Controls::IControl3, Windows::UI::Xaml::Controls::IControl4, Windows::UI::Xaml::Controls::IItemsControl, Windows::UI::Xaml::Controls::IItemsControl2, Windows::UI::Xaml::Controls::IItemContainerMapping, Windows::UI::Xaml::Controls::IItemsControl3, Windows::UI::Xaml::Controls::Primitives::ISelector, Windows::UI::Xaml::Controls::IListBox, Windows::UI::Xaml::Controls::IListBox2>
{
    using composable = ListBox;

protected:

    ListBoxT()
    {
        GetActivationFactory<ListBox, IListBoxFactory>().CreateInstance(*this, m_inner);
    }
};

template <typename D, typename ... Interfaces> struct ListBoxItemT :
    overrides<D, Windows::UI::Xaml::IUIElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverrides2T<D>, Windows::UI::Xaml::Controls::IControlOverridesT<D>, Windows::UI::Xaml::Controls::IContentControlOverridesT<D>, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IUIElement4, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::IFrameworkElement4, Windows::UI::Xaml::Controls::IControl, Windows::UI::Xaml::Controls::IControlProtected, Windows::UI::Xaml::Controls::IControl2, Windows::UI::Xaml::Controls::IControl3, Windows::UI::Xaml::Controls::IControl4, Windows::UI::Xaml::Controls::IContentControl, Windows::UI::Xaml::Controls::IContentControl2, Windows::UI::Xaml::Controls::Primitives::ISelectorItem, Windows::UI::Xaml::Controls::IListBoxItem>
{
    using composable = ListBoxItem;

protected:

    ListBoxItemT()
    {
        GetActivationFactory<ListBoxItem, IListBoxItemFactory>().CreateInstance(*this, m_inner);
    }
};

template <typename D, typename ... Interfaces> struct ListViewT :
    overrides<D, Windows::UI::Xaml::IUIElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverrides2T<D>, Windows::UI::Xaml::Controls::IControlOverridesT<D>, Windows::UI::Xaml::Controls::IItemsControlOverridesT<D>, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IUIElement4, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::IFrameworkElement4, Windows::UI::Xaml::Controls::IControl, Windows::UI::Xaml::Controls::IControlProtected, Windows::UI::Xaml::Controls::IControl2, Windows::UI::Xaml::Controls::IControl3, Windows::UI::Xaml::Controls::IControl4, Windows::UI::Xaml::Controls::IItemsControl, Windows::UI::Xaml::Controls::IItemsControl2, Windows::UI::Xaml::Controls::IItemContainerMapping, Windows::UI::Xaml::Controls::IItemsControl3, Windows::UI::Xaml::Controls::Primitives::ISelector, Windows::UI::Xaml::Controls::IListViewBase, Windows::UI::Xaml::Controls::ISemanticZoomInformation, Windows::UI::Xaml::Controls::IListViewBase2, Windows::UI::Xaml::Controls::IListViewBase3, Windows::UI::Xaml::Controls::IListViewBase4, Windows::UI::Xaml::Controls::IListViewBase5, Windows::UI::Xaml::Controls::IListView>
{
    using composable = ListView;

protected:

    ListViewT()
    {
        GetActivationFactory<ListView, IListViewFactory>().CreateInstance(*this, m_inner);
    }
};

template <typename D, typename ... Interfaces> struct ListViewBaseT :
    overrides<D, Windows::UI::Xaml::IUIElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverrides2T<D>, Windows::UI::Xaml::Controls::IControlOverridesT<D>, Windows::UI::Xaml::Controls::IItemsControlOverridesT<D>, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IUIElement4, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::IFrameworkElement4, Windows::UI::Xaml::Controls::IControl, Windows::UI::Xaml::Controls::IControlProtected, Windows::UI::Xaml::Controls::IControl2, Windows::UI::Xaml::Controls::IControl3, Windows::UI::Xaml::Controls::IControl4, Windows::UI::Xaml::Controls::IItemsControl, Windows::UI::Xaml::Controls::IItemsControl2, Windows::UI::Xaml::Controls::IItemContainerMapping, Windows::UI::Xaml::Controls::IItemsControl3, Windows::UI::Xaml::Controls::Primitives::ISelector, Windows::UI::Xaml::Controls::IListViewBase, Windows::UI::Xaml::Controls::ISemanticZoomInformation, Windows::UI::Xaml::Controls::IListViewBase2, Windows::UI::Xaml::Controls::IListViewBase3, Windows::UI::Xaml::Controls::IListViewBase4, Windows::UI::Xaml::Controls::IListViewBase5>
{
    using composable = ListViewBase;

protected:

    ListViewBaseT()
    {
        GetActivationFactory<ListViewBase, IListViewBaseFactory>().CreateInstance(*this, m_inner);
    }
};

template <typename D, typename ... Interfaces> struct ListViewHeaderItemT :
    overrides<D, Windows::UI::Xaml::IUIElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverrides2T<D>, Windows::UI::Xaml::Controls::IControlOverridesT<D>, Windows::UI::Xaml::Controls::IContentControlOverridesT<D>, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IUIElement4, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::IFrameworkElement4, Windows::UI::Xaml::Controls::IControl, Windows::UI::Xaml::Controls::IControlProtected, Windows::UI::Xaml::Controls::IControl2, Windows::UI::Xaml::Controls::IControl3, Windows::UI::Xaml::Controls::IControl4, Windows::UI::Xaml::Controls::IContentControl, Windows::UI::Xaml::Controls::IContentControl2, Windows::UI::Xaml::Controls::IListViewBaseHeaderItem, Windows::UI::Xaml::Controls::IListViewHeaderItem>
{
    using composable = ListViewHeaderItem;

protected:

    ListViewHeaderItemT()
    {
        GetActivationFactory<ListViewHeaderItem, IListViewHeaderItemFactory>().CreateInstance(*this, m_inner);
    }
};

template <typename D, typename ... Interfaces> struct ListViewItemT :
    overrides<D, Windows::UI::Xaml::IUIElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverrides2T<D>, Windows::UI::Xaml::Controls::IControlOverridesT<D>, Windows::UI::Xaml::Controls::IContentControlOverridesT<D>, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IUIElement4, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::IFrameworkElement4, Windows::UI::Xaml::Controls::IControl, Windows::UI::Xaml::Controls::IControlProtected, Windows::UI::Xaml::Controls::IControl2, Windows::UI::Xaml::Controls::IControl3, Windows::UI::Xaml::Controls::IControl4, Windows::UI::Xaml::Controls::IContentControl, Windows::UI::Xaml::Controls::IContentControl2, Windows::UI::Xaml::Controls::Primitives::ISelectorItem, Windows::UI::Xaml::Controls::IListViewItem>
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
    impl::require<D, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IUIElement4, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::IFrameworkElement4, Windows::UI::Xaml::Controls::IControl, Windows::UI::Xaml::Controls::IControlProtected, Windows::UI::Xaml::Controls::IControl2, Windows::UI::Xaml::Controls::IControl3, Windows::UI::Xaml::Controls::IControl4, Windows::UI::Xaml::Controls::IMediaPlayerElement>
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
    impl::require<D, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IUIElement4, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::IFrameworkElement4, Windows::UI::Xaml::Controls::IMediaPlayerPresenter>
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
    impl::require<D, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IUIElement4, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::IFrameworkElement4, Windows::UI::Xaml::Controls::IControl, Windows::UI::Xaml::Controls::IControlProtected, Windows::UI::Xaml::Controls::IControl2, Windows::UI::Xaml::Controls::IControl3, Windows::UI::Xaml::Controls::IControl4, Windows::UI::Xaml::Controls::IMediaTransportControls, Windows::UI::Xaml::Controls::IMediaTransportControls2>
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
    impl::require<D, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Controls::Primitives::IFlyoutBase, Windows::UI::Xaml::Controls::Primitives::IFlyoutBase2, Windows::UI::Xaml::Controls::IMenuFlyout, Windows::UI::Xaml::Controls::IMenuFlyout2>
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
    impl::require<D, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IUIElement4, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::IFrameworkElement4, Windows::UI::Xaml::Controls::IControl, Windows::UI::Xaml::Controls::IControlProtected, Windows::UI::Xaml::Controls::IControl2, Windows::UI::Xaml::Controls::IControl3, Windows::UI::Xaml::Controls::IControl4, Windows::UI::Xaml::Controls::IMenuFlyoutItemBase, Windows::UI::Xaml::Controls::IMenuFlyoutItem>
{
    using composable = MenuFlyoutItem;

protected:

    MenuFlyoutItemT()
    {
        GetActivationFactory<MenuFlyoutItem, IMenuFlyoutItemFactory>().CreateInstance(*this, m_inner);
    }
};

template <typename D, typename ... Interfaces> struct MenuFlyoutPresenterT :
    overrides<D, Windows::UI::Xaml::IUIElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverrides2T<D>, Windows::UI::Xaml::Controls::IControlOverridesT<D>, Windows::UI::Xaml::Controls::IItemsControlOverridesT<D>, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IUIElement4, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::IFrameworkElement4, Windows::UI::Xaml::Controls::IControl, Windows::UI::Xaml::Controls::IControlProtected, Windows::UI::Xaml::Controls::IControl2, Windows::UI::Xaml::Controls::IControl3, Windows::UI::Xaml::Controls::IControl4, Windows::UI::Xaml::Controls::IItemsControl, Windows::UI::Xaml::Controls::IItemsControl2, Windows::UI::Xaml::Controls::IItemContainerMapping, Windows::UI::Xaml::Controls::IItemsControl3, Windows::UI::Xaml::Controls::IMenuFlyoutPresenter, Windows::UI::Xaml::Controls::IMenuFlyoutPresenter2>
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
    impl::require<D, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IUIElement4, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::IFrameworkElement4, Windows::UI::Xaml::Controls::IControl, Windows::UI::Xaml::Controls::IControlProtected, Windows::UI::Xaml::Controls::IControl2, Windows::UI::Xaml::Controls::IControl3, Windows::UI::Xaml::Controls::IControl4, Windows::UI::Xaml::Controls::IMenuFlyoutItemBase, Windows::UI::Xaml::Controls::IMenuFlyoutSeparator>
{
    using composable = MenuFlyoutSeparator;

protected:

    MenuFlyoutSeparatorT()
    {
        GetActivationFactory<MenuFlyoutSeparator, IMenuFlyoutSeparatorFactory>().CreateInstance(*this, m_inner);
    }
};

template <typename D, typename ... Interfaces> struct PageT :
    overrides<D, Windows::UI::Xaml::IUIElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverrides2T<D>, Windows::UI::Xaml::Controls::IControlOverridesT<D>, Windows::UI::Xaml::Controls::IPageOverridesT<D>, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IUIElement4, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::IFrameworkElement4, Windows::UI::Xaml::Controls::IControl, Windows::UI::Xaml::Controls::IControlProtected, Windows::UI::Xaml::Controls::IControl2, Windows::UI::Xaml::Controls::IControl3, Windows::UI::Xaml::Controls::IControl4, Windows::UI::Xaml::Controls::IUserControl, Windows::UI::Xaml::Controls::IPage>
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
    impl::require<D, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IUIElement4, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::IFrameworkElement4, Windows::UI::Xaml::Controls::IPanel>
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
    impl::require<D, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IUIElement4, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::IFrameworkElement4, Windows::UI::Xaml::Controls::IIconElement, Windows::UI::Xaml::Controls::IPathIcon>
{
    using composable = PathIcon;

protected:

    PathIconT()
    {
        GetActivationFactory<PathIcon, IPathIconFactory>().CreateInstance(*this, m_inner);
    }
};

template <typename D, typename ... Interfaces> struct PivotT :
    overrides<D, Windows::UI::Xaml::IUIElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverrides2T<D>, Windows::UI::Xaml::Controls::IControlOverridesT<D>, Windows::UI::Xaml::Controls::IItemsControlOverridesT<D>, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IUIElement4, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::IFrameworkElement4, Windows::UI::Xaml::Controls::IControl, Windows::UI::Xaml::Controls::IControlProtected, Windows::UI::Xaml::Controls::IControl2, Windows::UI::Xaml::Controls::IControl3, Windows::UI::Xaml::Controls::IControl4, Windows::UI::Xaml::Controls::IItemsControl, Windows::UI::Xaml::Controls::IItemsControl2, Windows::UI::Xaml::Controls::IItemContainerMapping, Windows::UI::Xaml::Controls::IItemsControl3, Windows::UI::Xaml::Controls::IPivot, Windows::UI::Xaml::Controls::IPivot2, Windows::UI::Xaml::Controls::IPivot3>
{
    using composable = Pivot;

protected:

    PivotT()
    {
        GetActivationFactory<Pivot, IPivotFactory>().CreateInstance(*this, m_inner);
    }
};

template <typename D, typename ... Interfaces> struct PivotItemT :
    overrides<D, Windows::UI::Xaml::IUIElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverrides2T<D>, Windows::UI::Xaml::Controls::IControlOverridesT<D>, Windows::UI::Xaml::Controls::IContentControlOverridesT<D>, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IUIElement4, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::IFrameworkElement4, Windows::UI::Xaml::Controls::IControl, Windows::UI::Xaml::Controls::IControlProtected, Windows::UI::Xaml::Controls::IControl2, Windows::UI::Xaml::Controls::IControl3, Windows::UI::Xaml::Controls::IControl4, Windows::UI::Xaml::Controls::IContentControl, Windows::UI::Xaml::Controls::IContentControl2, Windows::UI::Xaml::Controls::IPivotItem>
{
    using composable = PivotItem;

protected:

    PivotItemT()
    {
        GetActivationFactory<PivotItem, IPivotItemFactory>().CreateInstance(*this, m_inner);
    }
};

template <typename D, typename ... Interfaces> struct ProgressBarT :
    overrides<D, Windows::UI::Xaml::IUIElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverrides2T<D>, Windows::UI::Xaml::Controls::IControlOverridesT<D>, Windows::UI::Xaml::Controls::Primitives::IRangeBaseOverridesT<D>, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IUIElement4, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::IFrameworkElement4, Windows::UI::Xaml::Controls::IControl, Windows::UI::Xaml::Controls::IControlProtected, Windows::UI::Xaml::Controls::IControl2, Windows::UI::Xaml::Controls::IControl3, Windows::UI::Xaml::Controls::IControl4, Windows::UI::Xaml::Controls::Primitives::IRangeBase, Windows::UI::Xaml::Controls::IProgressBar>
{
    using composable = ProgressBar;

protected:

    ProgressBarT()
    {
        GetActivationFactory<ProgressBar, IProgressBarFactory>().CreateInstance(*this, m_inner);
    }
};

template <typename D, typename ... Interfaces> struct RadioButtonT :
    overrides<D, Windows::UI::Xaml::IUIElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverrides2T<D>, Windows::UI::Xaml::Controls::IControlOverridesT<D>, Windows::UI::Xaml::Controls::IContentControlOverridesT<D>, Windows::UI::Xaml::Controls::Primitives::IToggleButtonOverridesT<D>, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IUIElement4, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::IFrameworkElement4, Windows::UI::Xaml::Controls::IControl, Windows::UI::Xaml::Controls::IControlProtected, Windows::UI::Xaml::Controls::IControl2, Windows::UI::Xaml::Controls::IControl3, Windows::UI::Xaml::Controls::IControl4, Windows::UI::Xaml::Controls::IContentControl, Windows::UI::Xaml::Controls::IContentControl2, Windows::UI::Xaml::Controls::Primitives::IButtonBase, Windows::UI::Xaml::Controls::Primitives::IToggleButton, Windows::UI::Xaml::Controls::IRadioButton>
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
    impl::require<D, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IUIElement4, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::IFrameworkElement4, Windows::UI::Xaml::Controls::IPanel, Windows::UI::Xaml::Controls::IRelativePanel>
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
    impl::require<D, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IUIElement4, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::IFrameworkElement4, Windows::UI::Xaml::Controls::IControl, Windows::UI::Xaml::Controls::IControlProtected, Windows::UI::Xaml::Controls::IControl2, Windows::UI::Xaml::Controls::IControl3, Windows::UI::Xaml::Controls::IControl4, Windows::UI::Xaml::Controls::IRichEditBox, Windows::UI::Xaml::Controls::IRichEditBox2, Windows::UI::Xaml::Controls::IRichEditBox3, Windows::UI::Xaml::Controls::IRichEditBox4>
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
    impl::require<D, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IUIElement4, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::IFrameworkElement4, Windows::UI::Xaml::Controls::IControl, Windows::UI::Xaml::Controls::IControlProtected, Windows::UI::Xaml::Controls::IControl2, Windows::UI::Xaml::Controls::IControl3, Windows::UI::Xaml::Controls::IControl4, Windows::UI::Xaml::Controls::ISearchBox>
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
    impl::require<D, Windows::UI::Xaml::IRoutedEventArgs, Windows::UI::Xaml::Controls::ISelectionChangedEventArgs>
{
    using composable = SelectionChangedEventArgs;

protected:

    SelectionChangedEventArgsT(const Windows::Foundation::Collections::IVector<Windows::IInspectable> & removedItems, const Windows::Foundation::Collections::IVector<Windows::IInspectable> & addedItems)
    {
        GetActivationFactory<SelectionChangedEventArgs, ISelectionChangedEventArgsFactory>().CreateInstanceWithRemovedItemsAndAddedItems(removedItems, addedItems, *this, m_inner);
    }
};

template <typename D, typename ... Interfaces> struct SettingsFlyoutT :
    overrides<D, Windows::UI::Xaml::IUIElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverrides2T<D>, Windows::UI::Xaml::Controls::IControlOverridesT<D>, Windows::UI::Xaml::Controls::IContentControlOverridesT<D>, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IUIElement4, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::IFrameworkElement4, Windows::UI::Xaml::Controls::IControl, Windows::UI::Xaml::Controls::IControlProtected, Windows::UI::Xaml::Controls::IControl2, Windows::UI::Xaml::Controls::IControl3, Windows::UI::Xaml::Controls::IControl4, Windows::UI::Xaml::Controls::IContentControl, Windows::UI::Xaml::Controls::IContentControl2, Windows::UI::Xaml::Controls::ISettingsFlyout>
{
    using composable = SettingsFlyout;

protected:

    SettingsFlyoutT()
    {
        GetActivationFactory<SettingsFlyout, ISettingsFlyoutFactory>().CreateInstance(*this, m_inner);
    }
};

template <typename D, typename ... Interfaces> struct SliderT :
    overrides<D, Windows::UI::Xaml::IUIElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverrides2T<D>, Windows::UI::Xaml::Controls::IControlOverridesT<D>, Windows::UI::Xaml::Controls::Primitives::IRangeBaseOverridesT<D>, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IUIElement4, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::IFrameworkElement4, Windows::UI::Xaml::Controls::IControl, Windows::UI::Xaml::Controls::IControlProtected, Windows::UI::Xaml::Controls::IControl2, Windows::UI::Xaml::Controls::IControl3, Windows::UI::Xaml::Controls::IControl4, Windows::UI::Xaml::Controls::Primitives::IRangeBase, Windows::UI::Xaml::Controls::ISlider, Windows::UI::Xaml::Controls::ISlider2>
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
    impl::require<D, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IUIElement4, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::IFrameworkElement4, Windows::UI::Xaml::Controls::IControl, Windows::UI::Xaml::Controls::IControlProtected, Windows::UI::Xaml::Controls::IControl2, Windows::UI::Xaml::Controls::IControl3, Windows::UI::Xaml::Controls::IControl4, Windows::UI::Xaml::Controls::ISplitView, Windows::UI::Xaml::Controls::ISplitView2>
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
    impl::require<D, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IUIElement4, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::IFrameworkElement4, Windows::UI::Xaml::Controls::IPanel, Windows::UI::Xaml::Controls::IStackPanel, Windows::UI::Xaml::Controls::Primitives::IScrollSnapPointsInfo, Windows::UI::Xaml::Controls::IStackPanel2, Windows::UI::Xaml::Controls::IInsertionPanel>
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
    impl::require<D, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IUIElement4, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::IFrameworkElement4, Windows::UI::Xaml::Controls::IPanel, Windows::UI::Xaml::Controls::IGrid, Windows::UI::Xaml::Controls::IGrid2, Windows::UI::Xaml::Controls::ISwapChainBackgroundPanel, Windows::UI::Xaml::Controls::ISwapChainBackgroundPanel2>
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
    impl::require<D, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IUIElement4, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::IFrameworkElement4, Windows::UI::Xaml::Controls::IPanel, Windows::UI::Xaml::Controls::IGrid, Windows::UI::Xaml::Controls::IGrid2, Windows::UI::Xaml::Controls::ISwapChainPanel>
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
    impl::require<D, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IUIElement4, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::IFrameworkElement4, Windows::UI::Xaml::Controls::IControl, Windows::UI::Xaml::Controls::IControlProtected, Windows::UI::Xaml::Controls::IControl2, Windows::UI::Xaml::Controls::IControl3, Windows::UI::Xaml::Controls::IControl4, Windows::UI::Xaml::Controls::ITextBox, Windows::UI::Xaml::Controls::ITextBox2, Windows::UI::Xaml::Controls::ITextBox3, Windows::UI::Xaml::Controls::ITextBox4>
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
    impl::require<D, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IUIElement4, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::IFrameworkElement4, Windows::UI::Xaml::Controls::IControl, Windows::UI::Xaml::Controls::IControlProtected, Windows::UI::Xaml::Controls::IControl2, Windows::UI::Xaml::Controls::IControl3, Windows::UI::Xaml::Controls::IControl4, Windows::UI::Xaml::Controls::ITimePicker, Windows::UI::Xaml::Controls::ITimePicker2>
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
    impl::require<D, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IUIElement4, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::IFrameworkElement4, Windows::UI::Xaml::Controls::IControl, Windows::UI::Xaml::Controls::IControlProtected, Windows::UI::Xaml::Controls::IControl2, Windows::UI::Xaml::Controls::IControl3, Windows::UI::Xaml::Controls::IControl4, Windows::UI::Xaml::Controls::IMenuFlyoutItemBase, Windows::UI::Xaml::Controls::IMenuFlyoutItem, Windows::UI::Xaml::Controls::IToggleMenuFlyoutItem>
{
    using composable = ToggleMenuFlyoutItem;

protected:

    ToggleMenuFlyoutItemT()
    {
        GetActivationFactory<ToggleMenuFlyoutItem, IToggleMenuFlyoutItemFactory>().CreateInstance(*this, m_inner);
    }
};

template <typename D, typename ... Interfaces> struct ToolTipT :
    overrides<D, Windows::UI::Xaml::IUIElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverrides2T<D>, Windows::UI::Xaml::Controls::IControlOverridesT<D>, Windows::UI::Xaml::Controls::IContentControlOverridesT<D>, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IUIElement4, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::IFrameworkElement4, Windows::UI::Xaml::Controls::IControl, Windows::UI::Xaml::Controls::IControlProtected, Windows::UI::Xaml::Controls::IControl2, Windows::UI::Xaml::Controls::IControl3, Windows::UI::Xaml::Controls::IControl4, Windows::UI::Xaml::Controls::IContentControl, Windows::UI::Xaml::Controls::IContentControl2, Windows::UI::Xaml::Controls::IToolTip>
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
    impl::require<D, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IUIElement4, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::IFrameworkElement4, Windows::UI::Xaml::Controls::IControl, Windows::UI::Xaml::Controls::IControlProtected, Windows::UI::Xaml::Controls::IControl2, Windows::UI::Xaml::Controls::IControl3, Windows::UI::Xaml::Controls::IControl4, Windows::UI::Xaml::Controls::IUserControl>
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

template <typename D, typename ... Interfaces> struct CustomMapTileDataSourceT :
    overrides<D, Windows::IInspectable, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Controls::Maps::IMapTileDataSource, Windows::UI::Xaml::Controls::Maps::ICustomMapTileDataSource>
{
    using composable = CustomMapTileDataSource;

protected:

    CustomMapTileDataSourceT()
    {
        GetActivationFactory<CustomMapTileDataSource, ICustomMapTileDataSourceFactory>().CreateInstance(*this, m_inner);
    }
};

template <typename D, typename ... Interfaces> struct HttpMapTileDataSourceT :
    overrides<D, Windows::IInspectable, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Controls::Maps::IMapTileDataSource, Windows::UI::Xaml::Controls::Maps::IHttpMapTileDataSource>
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

template <typename D, typename ... Interfaces> struct LocalMapTileDataSourceT :
    overrides<D, Windows::IInspectable, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Controls::Maps::IMapTileDataSource, Windows::UI::Xaml::Controls::Maps::ILocalMapTileDataSource>
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

template <typename D, typename ... Interfaces> struct MapCustomExperienceT :
    overrides<D, Windows::IInspectable, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Controls::Maps::IMapCustomExperience>
{
    using composable = MapCustomExperience;

protected:

    MapCustomExperienceT()
    {
        GetActivationFactory<MapCustomExperience, IMapCustomExperienceFactory>().CreateInstance(*this, m_inner);
    }
};

template <typename D, typename ... Interfaces> struct MapElementT :
    overrides<D, Windows::IInspectable, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Controls::Maps::IMapElement, Windows::UI::Xaml::Controls::Maps::IMapElement2>
{
    using composable = MapElement;

protected:

    MapElementT()
    {
        GetActivationFactory<MapElement, IMapElementFactory>().CreateInstance(*this, m_inner);
    }
};

template <typename D, typename ... Interfaces> struct MapRouteViewT :
    overrides<D, Windows::IInspectable, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Controls::Maps::IMapRouteView>
{
    using composable = MapRouteView;

protected:

    MapRouteViewT(const Windows::Services::Maps::MapRoute & route)
    {
        GetActivationFactory<MapRouteView, IMapRouteViewFactory>().CreateInstanceWithMapRoute(route, *this, m_inner);
    }
};

template <typename D, typename ... Interfaces> struct MapTileDataSourceT :
    overrides<D, Windows::IInspectable, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Controls::Maps::IMapTileDataSource>
{
    using composable = MapTileDataSource;

protected:

    MapTileDataSourceT()
    {
        GetActivationFactory<MapTileDataSource, IMapTileDataSourceFactory>().CreateInstance(*this, m_inner);
    }
};

template <typename D, typename ... Interfaces> struct MapTileSourceT :
    overrides<D, Windows::IInspectable, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Controls::Maps::IMapTileSource>
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

template <typename D, typename ... Interfaces> struct ButtonBaseT :
    overrides<D, Windows::UI::Xaml::IUIElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverrides2T<D>, Windows::UI::Xaml::Controls::IControlOverridesT<D>, Windows::UI::Xaml::Controls::IContentControlOverridesT<D>, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IUIElement4, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::IFrameworkElement4, Windows::UI::Xaml::Controls::IControl, Windows::UI::Xaml::Controls::IControlProtected, Windows::UI::Xaml::Controls::IControl2, Windows::UI::Xaml::Controls::IControl3, Windows::UI::Xaml::Controls::IControl4, Windows::UI::Xaml::Controls::IContentControl, Windows::UI::Xaml::Controls::IContentControl2, Windows::UI::Xaml::Controls::Primitives::IButtonBase>
{
    using composable = ButtonBase;

protected:

    ButtonBaseT()
    {
        GetActivationFactory<ButtonBase, IButtonBaseFactory>().CreateInstance(*this, m_inner);
    }
};

template <typename D, typename ... Interfaces> struct CarouselPanelT :
    overrides<D, Windows::UI::Xaml::IUIElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverrides2T<D>, Windows::UI::Xaml::Controls::IVirtualizingPanelOverridesT<D>, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IUIElement4, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::IFrameworkElement4, Windows::UI::Xaml::Controls::IPanel, Windows::UI::Xaml::Controls::IVirtualizingPanel, Windows::UI::Xaml::Controls::IVirtualizingPanelProtected, Windows::UI::Xaml::Controls::Primitives::ICarouselPanel, Windows::UI::Xaml::Controls::Primitives::IScrollSnapPointsInfo>
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
    impl::require<D, Windows::UI::Xaml::IRoutedEventArgs, Windows::UI::Xaml::Controls::Primitives::IDragCompletedEventArgs>
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
    impl::require<D, Windows::UI::Xaml::IRoutedEventArgs, Windows::UI::Xaml::Controls::Primitives::IDragDeltaEventArgs>
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
    impl::require<D, Windows::UI::Xaml::IRoutedEventArgs, Windows::UI::Xaml::Controls::Primitives::IDragStartedEventArgs>
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
    overrides<D, Windows::UI::Xaml::IUIElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverrides2T<D>, Windows::UI::Xaml::Controls::IContentPresenterOverridesT<D>, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IUIElement4, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::IFrameworkElement4, Windows::UI::Xaml::Controls::IContentPresenter, Windows::UI::Xaml::Controls::IContentPresenter2, Windows::UI::Xaml::Controls::IContentPresenter3, Windows::UI::Xaml::Controls::IContentPresenter4, Windows::UI::Xaml::Controls::Primitives::IGridViewItemPresenter>
{
    using composable = GridViewItemPresenter;

protected:

    GridViewItemPresenterT()
    {
        GetActivationFactory<GridViewItemPresenter, IGridViewItemPresenterFactory>().CreateInstance(*this, m_inner);
    }
};

template <typename D, typename ... Interfaces> struct ListViewItemPresenterT :
    overrides<D, Windows::UI::Xaml::IUIElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverrides2T<D>, Windows::UI::Xaml::Controls::IContentPresenterOverridesT<D>, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IUIElement4, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::IFrameworkElement4, Windows::UI::Xaml::Controls::IContentPresenter, Windows::UI::Xaml::Controls::IContentPresenter2, Windows::UI::Xaml::Controls::IContentPresenter3, Windows::UI::Xaml::Controls::IContentPresenter4, Windows::UI::Xaml::Controls::Primitives::IListViewItemPresenter, Windows::UI::Xaml::Controls::Primitives::IListViewItemPresenter2>
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
    overrides<D, Windows::UI::Xaml::IUIElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverrides2T<D>, Windows::UI::Xaml::Controls::IControlOverridesT<D>, Windows::UI::Xaml::Controls::IContentControlOverridesT<D>, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IUIElement4, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::IFrameworkElement4, Windows::UI::Xaml::Controls::IControl, Windows::UI::Xaml::Controls::IControlProtected, Windows::UI::Xaml::Controls::IControl2, Windows::UI::Xaml::Controls::IControl3, Windows::UI::Xaml::Controls::IControl4, Windows::UI::Xaml::Controls::IContentControl, Windows::UI::Xaml::Controls::IContentControl2, Windows::UI::Xaml::Controls::Primitives::IPivotHeaderItem>
{
    using composable = PivotHeaderItem;

protected:

    PivotHeaderItemT()
    {
        GetActivationFactory<PivotHeaderItem, IPivotHeaderItemFactory>().CreateInstance(*this, m_inner);
    }
};

template <typename D, typename ... Interfaces> struct RangeBaseT :
    overrides<D, Windows::UI::Xaml::IUIElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverrides2T<D>, Windows::UI::Xaml::Controls::IControlOverridesT<D>, Windows::UI::Xaml::Controls::Primitives::IRangeBaseOverridesT<D>, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IUIElement4, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::IFrameworkElement4, Windows::UI::Xaml::Controls::IControl, Windows::UI::Xaml::Controls::IControlProtected, Windows::UI::Xaml::Controls::IControl2, Windows::UI::Xaml::Controls::IControl3, Windows::UI::Xaml::Controls::IControl4, Windows::UI::Xaml::Controls::Primitives::IRangeBase>
{
    using composable = RangeBase;

protected:

    RangeBaseT()
    {
        GetActivationFactory<RangeBase, IRangeBaseFactory>().CreateInstance(*this, m_inner);
    }
};

template <typename D, typename ... Interfaces> struct SelectorItemT :
    overrides<D, Windows::UI::Xaml::IUIElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverrides2T<D>, Windows::UI::Xaml::Controls::IControlOverridesT<D>, Windows::UI::Xaml::Controls::IContentControlOverridesT<D>, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IUIElement4, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::IFrameworkElement4, Windows::UI::Xaml::Controls::IControl, Windows::UI::Xaml::Controls::IControlProtected, Windows::UI::Xaml::Controls::IControl2, Windows::UI::Xaml::Controls::IControl3, Windows::UI::Xaml::Controls::IControl4, Windows::UI::Xaml::Controls::IContentControl, Windows::UI::Xaml::Controls::IContentControl2, Windows::UI::Xaml::Controls::Primitives::ISelectorItem>
{
    using composable = SelectorItem;

protected:

    SelectorItemT()
    {
        GetActivationFactory<SelectorItem, ISelectorItemFactory>().CreateInstance(*this, m_inner);
    }
};

template <typename D, typename ... Interfaces> struct ToggleButtonT :
    overrides<D, Windows::UI::Xaml::IUIElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverrides2T<D>, Windows::UI::Xaml::Controls::IControlOverridesT<D>, Windows::UI::Xaml::Controls::IContentControlOverridesT<D>, Windows::UI::Xaml::Controls::Primitives::IToggleButtonOverridesT<D>, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IUIElement4, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::IFrameworkElement4, Windows::UI::Xaml::Controls::IControl, Windows::UI::Xaml::Controls::IControlProtected, Windows::UI::Xaml::Controls::IControl2, Windows::UI::Xaml::Controls::IControl3, Windows::UI::Xaml::Controls::IControl4, Windows::UI::Xaml::Controls::IContentControl, Windows::UI::Xaml::Controls::IContentControl2, Windows::UI::Xaml::Controls::Primitives::IButtonBase, Windows::UI::Xaml::Controls::Primitives::IToggleButton>
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

template <typename D, typename ... Interfaces> struct BindingT :
    overrides<D, Windows::IInspectable, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Data::IBindingBase, Windows::UI::Xaml::Data::IBinding, Windows::UI::Xaml::Data::IBinding2>
{
    using composable = Binding;

protected:

    BindingT()
    {
        GetActivationFactory<Binding, IBindingFactory>().CreateInstance(*this, m_inner);
    }
};

template <typename D, typename ... Interfaces> struct BindingBaseT :
    overrides<D, Windows::IInspectable, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Data::IBindingBase>
{
    using composable = BindingBase;

protected:

    BindingBaseT()
    {
        GetActivationFactory<BindingBase, IBindingBaseFactory>().CreateInstance(*this, m_inner);
    }
};

template <typename D, typename ... Interfaces> struct CurrentChangingEventArgsT :
    overrides<D, Windows::IInspectable, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::Data::ICurrentChangingEventArgs>
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

template <typename D, typename ... Interfaces> struct ItemIndexRangeT :
    overrides<D, Windows::IInspectable, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::Data::IItemIndexRange>
{
    using composable = ItemIndexRange;

protected:

    ItemIndexRangeT(int32_t firstIndex, uint32_t length)
    {
        GetActivationFactory<ItemIndexRange, IItemIndexRangeFactory>().CreateInstance(firstIndex, length, *this, m_inner);
    }
};

template <typename D, typename ... Interfaces> struct PropertyChangedEventArgsT :
    overrides<D, Windows::IInspectable, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::Data::IPropertyChangedEventArgs>
{
    using composable = PropertyChangedEventArgs;

protected:

    PropertyChangedEventArgsT(hstring_ref name)
    {
        GetActivationFactory<PropertyChangedEventArgs, IPropertyChangedEventArgsFactory>().CreateInstance(name, *this, m_inner);
    }
};

template <typename D, typename ... Interfaces> struct RelativeSourceT :
    overrides<D, Windows::IInspectable, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Data::IRelativeSource>
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

template <typename D, typename ... Interfaces> struct BlockT :
    overrides<D, Windows::UI::Xaml::Documents::ITextElementOverridesT<D>, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Documents::ITextElement, Windows::UI::Xaml::Documents::ITextElement2, Windows::UI::Xaml::Documents::ITextElement3, Windows::UI::Xaml::Documents::IBlock>
{
    using composable = Block;

protected:

    BlockT()
    {
        GetActivationFactory<Block, IBlockFactory>().CreateInstance(*this, m_inner);
    }
};

template <typename D, typename ... Interfaces> struct InlineT :
    overrides<D, Windows::UI::Xaml::Documents::ITextElementOverridesT<D>, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Documents::ITextElement, Windows::UI::Xaml::Documents::ITextElement2, Windows::UI::Xaml::Documents::ITextElement3, Windows::UI::Xaml::Documents::IInline>
{
    using composable = Inline;

protected:

    InlineT()
    {
        GetActivationFactory<Inline, IInlineFactory>().CreateInstance(*this, m_inner);
    }
};

template <typename D, typename ... Interfaces> struct SpanT :
    overrides<D, Windows::UI::Xaml::Documents::ITextElementOverridesT<D>, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Documents::ITextElement, Windows::UI::Xaml::Documents::ITextElement2, Windows::UI::Xaml::Documents::ITextElement3, Windows::UI::Xaml::Documents::IInline, Windows::UI::Xaml::Documents::ISpan>
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

template <typename D, typename ... Interfaces> struct ManipulationStartedRoutedEventArgsT :
    overrides<D, Windows::IInspectable, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::IRoutedEventArgs, Windows::UI::Xaml::Input::IManipulationStartedRoutedEventArgs>
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

template <typename D, typename ... Interfaces> struct NotifyCollectionChangedEventArgsT :
    overrides<D, Windows::IInspectable, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::Interop::INotifyCollectionChangedEventArgs>
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

template <typename D, typename ... Interfaces> struct BrushT :
    overrides<D, Windows::IInspectable, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Media::IBrush>
{
    using composable = Brush;

protected:

    BrushT()
    {
        GetActivationFactory<Brush, IBrushFactory>().CreateInstance(*this, m_inner);
    }
};

template <typename D, typename ... Interfaces> struct CacheModeT :
    overrides<D, Windows::IInspectable, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Media::ICacheMode>
{
    using composable = CacheMode;

protected:

    CacheModeT()
    {
        GetActivationFactory<CacheMode, ICacheModeFactory>().CreateInstance(*this, m_inner);
    }
};

template <typename D, typename ... Interfaces> struct FontFamilyT :
    overrides<D, Windows::IInspectable, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::Media::IFontFamily>
{
    using composable = FontFamily;

protected:

    FontFamilyT(hstring_ref familyName)
    {
        GetActivationFactory<FontFamily, IFontFamilyFactory>().CreateInstanceWithName(familyName, *this, m_inner);
    }
};

template <typename D, typename ... Interfaces> struct GeneralTransformT :
    overrides<D, Windows::UI::Xaml::Media::IGeneralTransformOverridesT<D>, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Media::IGeneralTransform>
{
    using composable = GeneralTransform;

protected:

    GeneralTransformT()
    {
        GetActivationFactory<GeneralTransform, IGeneralTransformFactory>().CreateInstance(*this, m_inner);
    }
};

template <typename D, typename ... Interfaces> struct GradientBrushT :
    overrides<D, Windows::IInspectable, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Media::IBrush, Windows::UI::Xaml::Media::IGradientBrush>
{
    using composable = GradientBrush;

protected:

    GradientBrushT()
    {
        GetActivationFactory<GradientBrush, IGradientBrushFactory>().CreateInstance(*this, m_inner);
    }
};

template <typename D, typename ... Interfaces> struct ProjectionT :
    overrides<D, Windows::IInspectable, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Media::IProjection>
{
    using composable = Projection;

protected:

    ProjectionT()
    {
        GetActivationFactory<Projection, IProjectionFactory>().CreateInstance(*this, m_inner);
    }
};

template <typename D, typename ... Interfaces> struct TileBrushT :
    overrides<D, Windows::IInspectable, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Media::IBrush, Windows::UI::Xaml::Media::ITileBrush>
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

template <typename D, typename ... Interfaces> struct ColorKeyFrameT :
    overrides<D, Windows::IInspectable, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Media::Animation::IColorKeyFrame>
{
    using composable = ColorKeyFrame;

protected:

    ColorKeyFrameT()
    {
        GetActivationFactory<ColorKeyFrame, IColorKeyFrameFactory>().CreateInstance(*this, m_inner);
    }
};

template <typename D, typename ... Interfaces> struct DoubleKeyFrameT :
    overrides<D, Windows::IInspectable, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Media::Animation::IDoubleKeyFrame>
{
    using composable = DoubleKeyFrame;

protected:

    DoubleKeyFrameT()
    {
        GetActivationFactory<DoubleKeyFrame, IDoubleKeyFrameFactory>().CreateInstance(*this, m_inner);
    }
};

template <typename D, typename ... Interfaces> struct NavigationTransitionInfoT :
    overrides<D, Windows::UI::Xaml::Media::Animation::INavigationTransitionInfoOverridesT<D>, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Media::Animation::INavigationTransitionInfo>
{
    using composable = NavigationTransitionInfo;

protected:

    NavigationTransitionInfoT()
    {
        GetActivationFactory<NavigationTransitionInfo, INavigationTransitionInfoFactory>().CreateInstance(*this, m_inner);
    }
};

template <typename D, typename ... Interfaces> struct ObjectKeyFrameT :
    overrides<D, Windows::IInspectable, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Media::Animation::IObjectKeyFrame>
{
    using composable = ObjectKeyFrame;

protected:

    ObjectKeyFrameT()
    {
        GetActivationFactory<ObjectKeyFrame, IObjectKeyFrameFactory>().CreateInstance(*this, m_inner);
    }
};

template <typename D, typename ... Interfaces> struct PointKeyFrameT :
    overrides<D, Windows::IInspectable, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Media::Animation::IPointKeyFrame>
{
    using composable = PointKeyFrame;

protected:

    PointKeyFrameT()
    {
        GetActivationFactory<PointKeyFrame, IPointKeyFrameFactory>().CreateInstance(*this, m_inner);
    }
};

template <typename D, typename ... Interfaces> struct TimelineT :
    overrides<D, Windows::IInspectable, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Media::Animation::ITimeline>
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

template <typename D, typename ... Interfaces> struct BitmapSourceT :
    overrides<D, Windows::IInspectable, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Media::IImageSource, Windows::UI::Xaml::Media::Imaging::IBitmapSource>
{
    using composable = BitmapSource;

protected:

    BitmapSourceT()
    {
        GetActivationFactory<BitmapSource, IBitmapSourceFactory>().CreateInstance(*this, m_inner);
    }
};

template <typename D, typename ... Interfaces> struct SurfaceImageSourceT :
    overrides<D, Windows::IInspectable, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Media::IImageSource, Windows::UI::Xaml::Media::Imaging::ISurfaceImageSource>
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

template <typename D, typename ... Interfaces> struct XamlRenderingBackgroundTaskT :
    overrides<D, Windows::UI::Xaml::Media::Imaging::IXamlRenderingBackgroundTaskOverridesT<D>, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::Media::Imaging::IXamlRenderingBackgroundTask>
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

template <typename D, typename ... Interfaces> struct Transform3DT :
    overrides<D, Windows::IInspectable, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Media::Media3D::ITransform3D>
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

template <typename D, typename ... Interfaces> struct PrintDocumentT :
    overrides<D, Windows::IInspectable, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Printing::IPrintDocument>
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

template <typename D, typename ... Interfaces> struct CustomXamlResourceLoaderT :
    overrides<D, Windows::UI::Xaml::Resources::ICustomXamlResourceLoaderOverridesT<D>, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::Resources::ICustomXamlResourceLoader>
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

template <typename D, typename ... Interfaces> struct PathT :
    overrides<D, Windows::UI::Xaml::IUIElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverrides2T<D>, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IUIElement4, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::IFrameworkElement4, Windows::UI::Xaml::Shapes::IShape, Windows::UI::Xaml::Shapes::IShape2, Windows::UI::Xaml::Shapes::IPath>
{
    using composable = Path;

protected:

    PathT()
    {
        GetActivationFactory<Path, IPathFactory>().CreateInstance(*this, m_inner);
    }
};

template <typename D, typename ... Interfaces> struct ShapeT :
    overrides<D, Windows::UI::Xaml::IUIElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverrides2T<D>, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IUIElement4, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::IFrameworkElement4, Windows::UI::Xaml::Shapes::IShape, Windows::UI::Xaml::Shapes::IShape2>
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
