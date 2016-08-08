// C++ for the Windows Runtime v1.29
// Copyright (c) 2016 Microsoft Corporation

#pragma once

#include "..\base.h"
#include "Windows.UI.WebUI.0.h"
#include "Windows.ApplicationModel.0.h"
#include "Windows.ApplicationModel.Activation.0.h"
#include "Windows.ApplicationModel.Background.0.h"
#include "Windows.Foundation.0.h"
#include "Windows.Graphics.Printing.0.h"

WINRT_EXPORT namespace winrt {

namespace ABI::Windows::UI::WebUI {

struct __declspec(uuid("50f1e730-c5d1-4b6b-9adb-8a11756be29c")) __declspec(novtable) ActivatedEventHandler : IUnknown
{
    virtual HRESULT __stdcall abi_Invoke(Windows::IInspectable * sender, Windows::ApplicationModel::Activation::IActivatedEventArgs * eventArgs) = 0;
};

struct __declspec(uuid("2b09a173-b68e-4def-88c1-8de84e5aab2f")) __declspec(novtable) EnteredBackgroundEventHandler : IUnknown
{
    virtual HRESULT __stdcall abi_Invoke(Windows::IInspectable * sender, Windows::ApplicationModel::IEnteredBackgroundEventArgs * e) = 0;
};

struct __declspec(uuid("c3bd1978-a431-49d8-a76a-395a4e03dcf3")) __declspec(novtable) IActivatedDeferral : Windows::IInspectable
{
    virtual HRESULT __stdcall abi_Complete() = 0;
};

struct __declspec(uuid("ca6d5f74-63c2-44a6-b97b-d9a03c20bc9b")) __declspec(novtable) IActivatedEventArgsDeferral : Windows::IInspectable
{
    virtual HRESULT __stdcall get_ActivatedOperation(Windows::UI::WebUI::IActivatedOperation ** value) = 0;
};

struct __declspec(uuid("b6a0b4bc-c6ca-42fd-9818-71904e45fed7")) __declspec(novtable) IActivatedOperation : Windows::IInspectable
{
    virtual HRESULT __stdcall abi_GetDeferral(Windows::UI::WebUI::IActivatedDeferral ** deferral) = 0;
};

struct __declspec(uuid("cea6469a-0e05-467a-abc9-36ec1d4cdcb6")) __declspec(novtable) IHtmlPrintDocumentSource : Windows::IInspectable
{
    virtual HRESULT __stdcall get_Content(winrt::Windows::UI::WebUI::PrintContent * value) = 0;
    virtual HRESULT __stdcall put_Content(winrt::Windows::UI::WebUI::PrintContent value) = 0;
    virtual HRESULT __stdcall get_LeftMargin(float * value) = 0;
    virtual HRESULT __stdcall put_LeftMargin(float value) = 0;
    virtual HRESULT __stdcall get_TopMargin(float * value) = 0;
    virtual HRESULT __stdcall put_TopMargin(float value) = 0;
    virtual HRESULT __stdcall get_RightMargin(float * value) = 0;
    virtual HRESULT __stdcall put_RightMargin(float value) = 0;
    virtual HRESULT __stdcall get_BottomMargin(float * value) = 0;
    virtual HRESULT __stdcall put_BottomMargin(float value) = 0;
    virtual HRESULT __stdcall get_EnableHeaderFooter(bool * value) = 0;
    virtual HRESULT __stdcall put_EnableHeaderFooter(bool value) = 0;
    virtual HRESULT __stdcall get_ShrinkToFit(bool * value) = 0;
    virtual HRESULT __stdcall put_ShrinkToFit(bool value) = 0;
    virtual HRESULT __stdcall get_PercentScale(float * pScalePercent) = 0;
    virtual HRESULT __stdcall put_PercentScale(float scalePercent) = 0;
    virtual HRESULT __stdcall get_PageRange(hstring * pstrPageRange) = 0;
    virtual HRESULT __stdcall abi_TrySetPageRange(hstring strPageRange, bool * pfSuccess) = 0;
};

struct __declspec(uuid("351b86bd-43b3-482b-85db-35d87b517ad9")) __declspec(novtable) IWebUIActivationStatics : Windows::IInspectable
{
    virtual HRESULT __stdcall add_Activated(Windows::UI::WebUI::ActivatedEventHandler * handler, event_token * token) = 0;
    virtual HRESULT __stdcall remove_Activated(event_token token) = 0;
    virtual HRESULT __stdcall add_Suspending(Windows::UI::WebUI::SuspendingEventHandler * handler, event_token * token) = 0;
    virtual HRESULT __stdcall remove_Suspending(event_token token) = 0;
    virtual HRESULT __stdcall add_Resuming(Windows::UI::WebUI::ResumingEventHandler * handler, event_token * token) = 0;
    virtual HRESULT __stdcall remove_Resuming(event_token token) = 0;
    virtual HRESULT __stdcall add_Navigated(Windows::UI::WebUI::NavigatedEventHandler * handler, event_token * token) = 0;
    virtual HRESULT __stdcall remove_Navigated(event_token token) = 0;
};

struct __declspec(uuid("c8e88696-4d78-4aa4-8f06-2a9eadc6c40a")) __declspec(novtable) IWebUIActivationStatics2 : Windows::IInspectable
{
    virtual HRESULT __stdcall add_LeavingBackground(Windows::UI::WebUI::LeavingBackgroundEventHandler * handler, event_token * token) = 0;
    virtual HRESULT __stdcall remove_LeavingBackground(event_token token) = 0;
    virtual HRESULT __stdcall add_EnteredBackground(Windows::UI::WebUI::EnteredBackgroundEventHandler * handler, event_token * token) = 0;
    virtual HRESULT __stdcall remove_EnteredBackground(event_token token) = 0;
    virtual HRESULT __stdcall abi_EnablePrelaunch(bool value) = 0;
};

struct __declspec(uuid("23f12c25-e2f7-4741-bc9c-394595de24dc")) __declspec(novtable) IWebUIBackgroundTaskInstance : Windows::IInspectable
{
    virtual HRESULT __stdcall get_Succeeded(bool * succeeded) = 0;
    virtual HRESULT __stdcall put_Succeeded(bool succeeded) = 0;
};

struct __declspec(uuid("9c7a5291-19ae-4ca3-b94b-fe4ec744a740")) __declspec(novtable) IWebUIBackgroundTaskInstanceStatics : Windows::IInspectable
{
    virtual HRESULT __stdcall get_Current(Windows::UI::WebUI::IWebUIBackgroundTaskInstance ** backgroundTaskInstance) = 0;
};

struct __declspec(uuid("d804204d-831f-46e2-b432-3afce211f962")) __declspec(novtable) IWebUINavigatedDeferral : Windows::IInspectable
{
    virtual HRESULT __stdcall abi_Complete() = 0;
};

struct __declspec(uuid("a75841b8-2499-4030-a69d-15d2d9cfe524")) __declspec(novtable) IWebUINavigatedEventArgs : Windows::IInspectable
{
    virtual HRESULT __stdcall get_NavigatedOperation(Windows::UI::WebUI::IWebUINavigatedOperation ** value) = 0;
};

struct __declspec(uuid("7a965f08-8182-4a89-ab67-8492e8750d4b")) __declspec(novtable) IWebUINavigatedOperation : Windows::IInspectable
{
    virtual HRESULT __stdcall abi_GetDeferral(Windows::UI::WebUI::IWebUINavigatedDeferral ** deferral) = 0;
};

struct __declspec(uuid("00b4ccd9-7a9c-4b6b-9ac4-13474f268bc4")) __declspec(novtable) LeavingBackgroundEventHandler : IUnknown
{
    virtual HRESULT __stdcall abi_Invoke(Windows::IInspectable * sender, Windows::ApplicationModel::ILeavingBackgroundEventArgs * e) = 0;
};

struct __declspec(uuid("7af46fe6-40ca-4e49-a7d6-dbdb330cd1a3")) __declspec(novtable) NavigatedEventHandler : IUnknown
{
    virtual HRESULT __stdcall abi_Invoke(Windows::IInspectable * sender, Windows::UI::WebUI::IWebUINavigatedEventArgs * e) = 0;
};

struct __declspec(uuid("26599ba9-a22d-4806-a728-acadc1d075fa")) __declspec(novtable) ResumingEventHandler : IUnknown
{
    virtual HRESULT __stdcall abi_Invoke(Windows::IInspectable * sender) = 0;
};

struct __declspec(uuid("509c429c-78e2-4883-abc8-8960dcde1b5c")) __declspec(novtable) SuspendingEventHandler : IUnknown
{
    virtual HRESULT __stdcall abi_Invoke(Windows::IInspectable * sender, Windows::ApplicationModel::ISuspendingEventArgs * e) = 0;
};

}

namespace ABI {

template <> struct traits<Windows::UI::WebUI::ActivatedDeferral> { using default_interface = Windows::UI::WebUI::IActivatedDeferral; };
template <> struct traits<Windows::UI::WebUI::ActivatedOperation> { using default_interface = Windows::UI::WebUI::IActivatedOperation; };
template <> struct traits<Windows::UI::WebUI::EnteredBackgroundEventArgs> { using default_interface = Windows::ApplicationModel::IEnteredBackgroundEventArgs; };
template <> struct traits<Windows::UI::WebUI::HtmlPrintDocumentSource> { using default_interface = Windows::UI::WebUI::IHtmlPrintDocumentSource; };
template <> struct traits<Windows::UI::WebUI::LeavingBackgroundEventArgs> { using default_interface = Windows::ApplicationModel::ILeavingBackgroundEventArgs; };
template <> struct traits<Windows::UI::WebUI::SuspendingDeferral> { using default_interface = Windows::ApplicationModel::ISuspendingDeferral; };
template <> struct traits<Windows::UI::WebUI::SuspendingEventArgs> { using default_interface = Windows::ApplicationModel::ISuspendingEventArgs; };
template <> struct traits<Windows::UI::WebUI::SuspendingOperation> { using default_interface = Windows::ApplicationModel::ISuspendingOperation; };
template <> struct traits<Windows::UI::WebUI::WebUIAppointmentsProviderAddAppointmentActivatedEventArgs> { using default_interface = Windows::ApplicationModel::Activation::IAppointmentsProviderAddAppointmentActivatedEventArgs; };
template <> struct traits<Windows::UI::WebUI::WebUIAppointmentsProviderRemoveAppointmentActivatedEventArgs> { using default_interface = Windows::ApplicationModel::Activation::IAppointmentsProviderRemoveAppointmentActivatedEventArgs; };
template <> struct traits<Windows::UI::WebUI::WebUIAppointmentsProviderReplaceAppointmentActivatedEventArgs> { using default_interface = Windows::ApplicationModel::Activation::IAppointmentsProviderReplaceAppointmentActivatedEventArgs; };
template <> struct traits<Windows::UI::WebUI::WebUIAppointmentsProviderShowAppointmentDetailsActivatedEventArgs> { using default_interface = Windows::ApplicationModel::Activation::IAppointmentsProviderShowAppointmentDetailsActivatedEventArgs; };
template <> struct traits<Windows::UI::WebUI::WebUIAppointmentsProviderShowTimeFrameActivatedEventArgs> { using default_interface = Windows::ApplicationModel::Activation::IAppointmentsProviderShowTimeFrameActivatedEventArgs; };
template <> struct traits<Windows::UI::WebUI::WebUIBackgroundTaskInstanceRuntimeClass> { using default_interface = Windows::UI::WebUI::IWebUIBackgroundTaskInstance; };
template <> struct traits<Windows::UI::WebUI::WebUICachedFileUpdaterActivatedEventArgs> { using default_interface = Windows::ApplicationModel::Activation::ICachedFileUpdaterActivatedEventArgs; };
template <> struct traits<Windows::UI::WebUI::WebUIDeviceActivatedEventArgs> { using default_interface = Windows::ApplicationModel::Activation::IDeviceActivatedEventArgs; };
template <> struct traits<Windows::UI::WebUI::WebUIDevicePairingActivatedEventArgs> { using default_interface = Windows::ApplicationModel::Activation::IDevicePairingActivatedEventArgs; };
template <> struct traits<Windows::UI::WebUI::WebUIDialReceiverActivatedEventArgs> { using default_interface = Windows::ApplicationModel::Activation::IDialReceiverActivatedEventArgs; };
template <> struct traits<Windows::UI::WebUI::WebUIFileActivatedEventArgs> { using default_interface = Windows::ApplicationModel::Activation::IFileActivatedEventArgs; };
template <> struct traits<Windows::UI::WebUI::WebUIFileOpenPickerActivatedEventArgs> { using default_interface = Windows::ApplicationModel::Activation::IFileOpenPickerActivatedEventArgs; };
template <> struct traits<Windows::UI::WebUI::WebUIFileOpenPickerContinuationEventArgs> { using default_interface = Windows::ApplicationModel::Activation::IFileOpenPickerContinuationEventArgs; };
template <> struct traits<Windows::UI::WebUI::WebUIFileSavePickerActivatedEventArgs> { using default_interface = Windows::ApplicationModel::Activation::IFileSavePickerActivatedEventArgs; };
template <> struct traits<Windows::UI::WebUI::WebUIFileSavePickerContinuationEventArgs> { using default_interface = Windows::ApplicationModel::Activation::IFileSavePickerContinuationEventArgs; };
template <> struct traits<Windows::UI::WebUI::WebUIFolderPickerContinuationEventArgs> { using default_interface = Windows::ApplicationModel::Activation::IFolderPickerContinuationEventArgs; };
template <> struct traits<Windows::UI::WebUI::WebUILaunchActivatedEventArgs> { using default_interface = Windows::ApplicationModel::Activation::ILaunchActivatedEventArgs; };
template <> struct traits<Windows::UI::WebUI::WebUILockScreenActivatedEventArgs> { using default_interface = Windows::ApplicationModel::Activation::ILockScreenActivatedEventArgs; };
template <> struct traits<Windows::UI::WebUI::WebUINavigatedDeferral> { using default_interface = Windows::UI::WebUI::IWebUINavigatedDeferral; };
template <> struct traits<Windows::UI::WebUI::WebUINavigatedEventArgs> { using default_interface = Windows::UI::WebUI::IWebUINavigatedEventArgs; };
template <> struct traits<Windows::UI::WebUI::WebUINavigatedOperation> { using default_interface = Windows::UI::WebUI::IWebUINavigatedOperation; };
template <> struct traits<Windows::UI::WebUI::WebUIProtocolActivatedEventArgs> { using default_interface = Windows::ApplicationModel::Activation::IProtocolActivatedEventArgs; };
template <> struct traits<Windows::UI::WebUI::WebUIProtocolForResultsActivatedEventArgs> { using default_interface = Windows::ApplicationModel::Activation::IProtocolForResultsActivatedEventArgs; };
template <> struct traits<Windows::UI::WebUI::WebUIRestrictedLaunchActivatedEventArgs> { using default_interface = Windows::ApplicationModel::Activation::IRestrictedLaunchActivatedEventArgs; };
template <> struct traits<Windows::UI::WebUI::WebUIShareTargetActivatedEventArgs> { using default_interface = Windows::ApplicationModel::Activation::IShareTargetActivatedEventArgs; };
template <> struct traits<Windows::UI::WebUI::WebUIToastNotificationActivatedEventArgs> { using default_interface = Windows::ApplicationModel::Activation::IToastNotificationActivatedEventArgs; };
template <> struct traits<Windows::UI::WebUI::WebUIUserDataAccountProviderActivatedEventArgs> { using default_interface = Windows::ApplicationModel::Activation::IUserDataAccountProviderActivatedEventArgs; };
template <> struct traits<Windows::UI::WebUI::WebUIVoiceCommandActivatedEventArgs> { using default_interface = Windows::ApplicationModel::Activation::IVoiceCommandActivatedEventArgs; };
template <> struct traits<Windows::UI::WebUI::WebUIWebAccountProviderActivatedEventArgs> { using default_interface = Windows::ApplicationModel::Activation::IWebAccountProviderActivatedEventArgs; };
template <> struct traits<Windows::UI::WebUI::WebUIWebAuthenticationBrokerContinuationEventArgs> { using default_interface = Windows::ApplicationModel::Activation::IWebAuthenticationBrokerContinuationEventArgs; };

}

namespace Windows::UI::WebUI {

template <typename T> class impl_IActivatedDeferral;
template <typename T> class impl_IActivatedEventArgsDeferral;
template <typename T> class impl_IActivatedOperation;
template <typename T> class impl_IHtmlPrintDocumentSource;
template <typename T> class impl_IWebUIActivationStatics;
template <typename T> class impl_IWebUIActivationStatics2;
template <typename T> class impl_IWebUIBackgroundTaskInstance;
template <typename T> class impl_IWebUIBackgroundTaskInstanceStatics;
template <typename T> class impl_IWebUINavigatedDeferral;
template <typename T> class impl_IWebUINavigatedEventArgs;
template <typename T> class impl_IWebUINavigatedOperation;
template <typename T> struct impl_ActivatedEventHandler;
template <typename T> struct impl_EnteredBackgroundEventHandler;
template <typename T> struct impl_LeavingBackgroundEventHandler;
template <typename T> struct impl_NavigatedEventHandler;
template <typename T> struct impl_ResumingEventHandler;
template <typename T> struct impl_SuspendingEventHandler;

}

namespace impl {

template <> struct traits<Windows::UI::WebUI::ActivatedEventHandler>
{
    using abi = ABI::Windows::UI::WebUI::ActivatedEventHandler;
};

template <> struct traits<Windows::UI::WebUI::EnteredBackgroundEventHandler>
{
    using abi = ABI::Windows::UI::WebUI::EnteredBackgroundEventHandler;
};

template <> struct traits<Windows::UI::WebUI::IActivatedDeferral>
{
    using abi = ABI::Windows::UI::WebUI::IActivatedDeferral;
    template <typename D> using consume = Windows::UI::WebUI::impl_IActivatedDeferral<D>;
};

template <> struct traits<Windows::UI::WebUI::IActivatedEventArgsDeferral>
{
    using abi = ABI::Windows::UI::WebUI::IActivatedEventArgsDeferral;
    template <typename D> using consume = Windows::UI::WebUI::impl_IActivatedEventArgsDeferral<D>;
};

template <> struct traits<Windows::UI::WebUI::IActivatedOperation>
{
    using abi = ABI::Windows::UI::WebUI::IActivatedOperation;
    template <typename D> using consume = Windows::UI::WebUI::impl_IActivatedOperation<D>;
};

template <> struct traits<Windows::UI::WebUI::IHtmlPrintDocumentSource>
{
    using abi = ABI::Windows::UI::WebUI::IHtmlPrintDocumentSource;
    template <typename D> using consume = Windows::UI::WebUI::impl_IHtmlPrintDocumentSource<D>;
};

template <> struct traits<Windows::UI::WebUI::IWebUIActivationStatics>
{
    using abi = ABI::Windows::UI::WebUI::IWebUIActivationStatics;
    template <typename D> using consume = Windows::UI::WebUI::impl_IWebUIActivationStatics<D>;
};

template <> struct traits<Windows::UI::WebUI::IWebUIActivationStatics2>
{
    using abi = ABI::Windows::UI::WebUI::IWebUIActivationStatics2;
    template <typename D> using consume = Windows::UI::WebUI::impl_IWebUIActivationStatics2<D>;
};

template <> struct traits<Windows::UI::WebUI::IWebUIBackgroundTaskInstance>
{
    using abi = ABI::Windows::UI::WebUI::IWebUIBackgroundTaskInstance;
    template <typename D> using consume = Windows::UI::WebUI::impl_IWebUIBackgroundTaskInstance<D>;
};

template <> struct traits<Windows::UI::WebUI::IWebUIBackgroundTaskInstanceStatics>
{
    using abi = ABI::Windows::UI::WebUI::IWebUIBackgroundTaskInstanceStatics;
    template <typename D> using consume = Windows::UI::WebUI::impl_IWebUIBackgroundTaskInstanceStatics<D>;
};

template <> struct traits<Windows::UI::WebUI::IWebUINavigatedDeferral>
{
    using abi = ABI::Windows::UI::WebUI::IWebUINavigatedDeferral;
    template <typename D> using consume = Windows::UI::WebUI::impl_IWebUINavigatedDeferral<D>;
};

template <> struct traits<Windows::UI::WebUI::IWebUINavigatedEventArgs>
{
    using abi = ABI::Windows::UI::WebUI::IWebUINavigatedEventArgs;
    template <typename D> using consume = Windows::UI::WebUI::impl_IWebUINavigatedEventArgs<D>;
};

template <> struct traits<Windows::UI::WebUI::IWebUINavigatedOperation>
{
    using abi = ABI::Windows::UI::WebUI::IWebUINavigatedOperation;
    template <typename D> using consume = Windows::UI::WebUI::impl_IWebUINavigatedOperation<D>;
};

template <> struct traits<Windows::UI::WebUI::LeavingBackgroundEventHandler>
{
    using abi = ABI::Windows::UI::WebUI::LeavingBackgroundEventHandler;
};

template <> struct traits<Windows::UI::WebUI::NavigatedEventHandler>
{
    using abi = ABI::Windows::UI::WebUI::NavigatedEventHandler;
};

template <> struct traits<Windows::UI::WebUI::ResumingEventHandler>
{
    using abi = ABI::Windows::UI::WebUI::ResumingEventHandler;
};

template <> struct traits<Windows::UI::WebUI::SuspendingEventHandler>
{
    using abi = ABI::Windows::UI::WebUI::SuspendingEventHandler;
};

template <> struct traits<Windows::UI::WebUI::ActivatedDeferral>
{
    using abi = ABI::Windows::UI::WebUI::ActivatedDeferral;
    using default_interface = Windows::UI::WebUI::IActivatedDeferral;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.WebUI.ActivatedDeferral"; }
};

template <> struct traits<Windows::UI::WebUI::ActivatedOperation>
{
    using abi = ABI::Windows::UI::WebUI::ActivatedOperation;
    using default_interface = Windows::UI::WebUI::IActivatedOperation;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.WebUI.ActivatedOperation"; }
};

template <> struct traits<Windows::UI::WebUI::EnteredBackgroundEventArgs>
{
    using abi = ABI::Windows::UI::WebUI::EnteredBackgroundEventArgs;
    using default_interface = Windows::ApplicationModel::IEnteredBackgroundEventArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.WebUI.EnteredBackgroundEventArgs"; }
};

template <> struct traits<Windows::UI::WebUI::HtmlPrintDocumentSource>
{
    using abi = ABI::Windows::UI::WebUI::HtmlPrintDocumentSource;
    using default_interface = Windows::UI::WebUI::IHtmlPrintDocumentSource;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.WebUI.HtmlPrintDocumentSource"; }
};

template <> struct traits<Windows::UI::WebUI::LeavingBackgroundEventArgs>
{
    using abi = ABI::Windows::UI::WebUI::LeavingBackgroundEventArgs;
    using default_interface = Windows::ApplicationModel::ILeavingBackgroundEventArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.WebUI.LeavingBackgroundEventArgs"; }
};

template <> struct traits<Windows::UI::WebUI::SuspendingDeferral>
{
    using abi = ABI::Windows::UI::WebUI::SuspendingDeferral;
    using default_interface = Windows::ApplicationModel::ISuspendingDeferral;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.WebUI.SuspendingDeferral"; }
};

template <> struct traits<Windows::UI::WebUI::SuspendingEventArgs>
{
    using abi = ABI::Windows::UI::WebUI::SuspendingEventArgs;
    using default_interface = Windows::ApplicationModel::ISuspendingEventArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.WebUI.SuspendingEventArgs"; }
};

template <> struct traits<Windows::UI::WebUI::SuspendingOperation>
{
    using abi = ABI::Windows::UI::WebUI::SuspendingOperation;
    using default_interface = Windows::ApplicationModel::ISuspendingOperation;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.WebUI.SuspendingOperation"; }
};

template <> struct traits<Windows::UI::WebUI::WebUIApplication>
{
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.WebUI.WebUIApplication"; }
};

template <> struct traits<Windows::UI::WebUI::WebUIAppointmentsProviderAddAppointmentActivatedEventArgs>
{
    using abi = ABI::Windows::UI::WebUI::WebUIAppointmentsProviderAddAppointmentActivatedEventArgs;
    using default_interface = Windows::ApplicationModel::Activation::IAppointmentsProviderAddAppointmentActivatedEventArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.WebUI.WebUIAppointmentsProviderAddAppointmentActivatedEventArgs"; }
};

template <> struct traits<Windows::UI::WebUI::WebUIAppointmentsProviderRemoveAppointmentActivatedEventArgs>
{
    using abi = ABI::Windows::UI::WebUI::WebUIAppointmentsProviderRemoveAppointmentActivatedEventArgs;
    using default_interface = Windows::ApplicationModel::Activation::IAppointmentsProviderRemoveAppointmentActivatedEventArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.WebUI.WebUIAppointmentsProviderRemoveAppointmentActivatedEventArgs"; }
};

template <> struct traits<Windows::UI::WebUI::WebUIAppointmentsProviderReplaceAppointmentActivatedEventArgs>
{
    using abi = ABI::Windows::UI::WebUI::WebUIAppointmentsProviderReplaceAppointmentActivatedEventArgs;
    using default_interface = Windows::ApplicationModel::Activation::IAppointmentsProviderReplaceAppointmentActivatedEventArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.WebUI.WebUIAppointmentsProviderReplaceAppointmentActivatedEventArgs"; }
};

template <> struct traits<Windows::UI::WebUI::WebUIAppointmentsProviderShowAppointmentDetailsActivatedEventArgs>
{
    using abi = ABI::Windows::UI::WebUI::WebUIAppointmentsProviderShowAppointmentDetailsActivatedEventArgs;
    using default_interface = Windows::ApplicationModel::Activation::IAppointmentsProviderShowAppointmentDetailsActivatedEventArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.WebUI.WebUIAppointmentsProviderShowAppointmentDetailsActivatedEventArgs"; }
};

template <> struct traits<Windows::UI::WebUI::WebUIAppointmentsProviderShowTimeFrameActivatedEventArgs>
{
    using abi = ABI::Windows::UI::WebUI::WebUIAppointmentsProviderShowTimeFrameActivatedEventArgs;
    using default_interface = Windows::ApplicationModel::Activation::IAppointmentsProviderShowTimeFrameActivatedEventArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.WebUI.WebUIAppointmentsProviderShowTimeFrameActivatedEventArgs"; }
};

template <> struct traits<Windows::UI::WebUI::WebUIBackgroundTaskInstance>
{
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.WebUI.WebUIBackgroundTaskInstance"; }
};

template <> struct traits<Windows::UI::WebUI::WebUIBackgroundTaskInstanceRuntimeClass>
{
    using abi = ABI::Windows::UI::WebUI::WebUIBackgroundTaskInstanceRuntimeClass;
    using default_interface = Windows::UI::WebUI::IWebUIBackgroundTaskInstance;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.WebUI.WebUIBackgroundTaskInstanceRuntimeClass"; }
};

template <> struct traits<Windows::UI::WebUI::WebUICachedFileUpdaterActivatedEventArgs>
{
    using abi = ABI::Windows::UI::WebUI::WebUICachedFileUpdaterActivatedEventArgs;
    using default_interface = Windows::ApplicationModel::Activation::ICachedFileUpdaterActivatedEventArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.WebUI.WebUICachedFileUpdaterActivatedEventArgs"; }
};

template <> struct traits<Windows::UI::WebUI::WebUIDeviceActivatedEventArgs>
{
    using abi = ABI::Windows::UI::WebUI::WebUIDeviceActivatedEventArgs;
    using default_interface = Windows::ApplicationModel::Activation::IDeviceActivatedEventArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.WebUI.WebUIDeviceActivatedEventArgs"; }
};

template <> struct traits<Windows::UI::WebUI::WebUIDevicePairingActivatedEventArgs>
{
    using abi = ABI::Windows::UI::WebUI::WebUIDevicePairingActivatedEventArgs;
    using default_interface = Windows::ApplicationModel::Activation::IDevicePairingActivatedEventArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.WebUI.WebUIDevicePairingActivatedEventArgs"; }
};

template <> struct traits<Windows::UI::WebUI::WebUIDialReceiverActivatedEventArgs>
{
    using abi = ABI::Windows::UI::WebUI::WebUIDialReceiverActivatedEventArgs;
    using default_interface = Windows::ApplicationModel::Activation::IDialReceiverActivatedEventArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.WebUI.WebUIDialReceiverActivatedEventArgs"; }
};

template <> struct traits<Windows::UI::WebUI::WebUIFileActivatedEventArgs>
{
    using abi = ABI::Windows::UI::WebUI::WebUIFileActivatedEventArgs;
    using default_interface = Windows::ApplicationModel::Activation::IFileActivatedEventArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.WebUI.WebUIFileActivatedEventArgs"; }
};

template <> struct traits<Windows::UI::WebUI::WebUIFileOpenPickerActivatedEventArgs>
{
    using abi = ABI::Windows::UI::WebUI::WebUIFileOpenPickerActivatedEventArgs;
    using default_interface = Windows::ApplicationModel::Activation::IFileOpenPickerActivatedEventArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.WebUI.WebUIFileOpenPickerActivatedEventArgs"; }
};

template <> struct traits<Windows::UI::WebUI::WebUIFileOpenPickerContinuationEventArgs>
{
    using abi = ABI::Windows::UI::WebUI::WebUIFileOpenPickerContinuationEventArgs;
    using default_interface = Windows::ApplicationModel::Activation::IFileOpenPickerContinuationEventArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.WebUI.WebUIFileOpenPickerContinuationEventArgs"; }
};

template <> struct traits<Windows::UI::WebUI::WebUIFileSavePickerActivatedEventArgs>
{
    using abi = ABI::Windows::UI::WebUI::WebUIFileSavePickerActivatedEventArgs;
    using default_interface = Windows::ApplicationModel::Activation::IFileSavePickerActivatedEventArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.WebUI.WebUIFileSavePickerActivatedEventArgs"; }
};

template <> struct traits<Windows::UI::WebUI::WebUIFileSavePickerContinuationEventArgs>
{
    using abi = ABI::Windows::UI::WebUI::WebUIFileSavePickerContinuationEventArgs;
    using default_interface = Windows::ApplicationModel::Activation::IFileSavePickerContinuationEventArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.WebUI.WebUIFileSavePickerContinuationEventArgs"; }
};

template <> struct traits<Windows::UI::WebUI::WebUIFolderPickerContinuationEventArgs>
{
    using abi = ABI::Windows::UI::WebUI::WebUIFolderPickerContinuationEventArgs;
    using default_interface = Windows::ApplicationModel::Activation::IFolderPickerContinuationEventArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.WebUI.WebUIFolderPickerContinuationEventArgs"; }
};

template <> struct traits<Windows::UI::WebUI::WebUILaunchActivatedEventArgs>
{
    using abi = ABI::Windows::UI::WebUI::WebUILaunchActivatedEventArgs;
    using default_interface = Windows::ApplicationModel::Activation::ILaunchActivatedEventArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.WebUI.WebUILaunchActivatedEventArgs"; }
};

template <> struct traits<Windows::UI::WebUI::WebUILockScreenActivatedEventArgs>
{
    using abi = ABI::Windows::UI::WebUI::WebUILockScreenActivatedEventArgs;
    using default_interface = Windows::ApplicationModel::Activation::ILockScreenActivatedEventArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.WebUI.WebUILockScreenActivatedEventArgs"; }
};

template <> struct traits<Windows::UI::WebUI::WebUINavigatedDeferral>
{
    using abi = ABI::Windows::UI::WebUI::WebUINavigatedDeferral;
    using default_interface = Windows::UI::WebUI::IWebUINavigatedDeferral;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.WebUI.WebUINavigatedDeferral"; }
};

template <> struct traits<Windows::UI::WebUI::WebUINavigatedEventArgs>
{
    using abi = ABI::Windows::UI::WebUI::WebUINavigatedEventArgs;
    using default_interface = Windows::UI::WebUI::IWebUINavigatedEventArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.WebUI.WebUINavigatedEventArgs"; }
};

template <> struct traits<Windows::UI::WebUI::WebUINavigatedOperation>
{
    using abi = ABI::Windows::UI::WebUI::WebUINavigatedOperation;
    using default_interface = Windows::UI::WebUI::IWebUINavigatedOperation;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.WebUI.WebUINavigatedOperation"; }
};

template <> struct traits<Windows::UI::WebUI::WebUIProtocolActivatedEventArgs>
{
    using abi = ABI::Windows::UI::WebUI::WebUIProtocolActivatedEventArgs;
    using default_interface = Windows::ApplicationModel::Activation::IProtocolActivatedEventArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.WebUI.WebUIProtocolActivatedEventArgs"; }
};

template <> struct traits<Windows::UI::WebUI::WebUIProtocolForResultsActivatedEventArgs>
{
    using abi = ABI::Windows::UI::WebUI::WebUIProtocolForResultsActivatedEventArgs;
    using default_interface = Windows::ApplicationModel::Activation::IProtocolForResultsActivatedEventArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.WebUI.WebUIProtocolForResultsActivatedEventArgs"; }
};

template <> struct traits<Windows::UI::WebUI::WebUIRestrictedLaunchActivatedEventArgs>
{
    using abi = ABI::Windows::UI::WebUI::WebUIRestrictedLaunchActivatedEventArgs;
    using default_interface = Windows::ApplicationModel::Activation::IRestrictedLaunchActivatedEventArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.WebUI.WebUIRestrictedLaunchActivatedEventArgs"; }
};

template <> struct traits<Windows::UI::WebUI::WebUIShareTargetActivatedEventArgs>
{
    using abi = ABI::Windows::UI::WebUI::WebUIShareTargetActivatedEventArgs;
    using default_interface = Windows::ApplicationModel::Activation::IShareTargetActivatedEventArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.WebUI.WebUIShareTargetActivatedEventArgs"; }
};

template <> struct traits<Windows::UI::WebUI::WebUIToastNotificationActivatedEventArgs>
{
    using abi = ABI::Windows::UI::WebUI::WebUIToastNotificationActivatedEventArgs;
    using default_interface = Windows::ApplicationModel::Activation::IToastNotificationActivatedEventArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.WebUI.WebUIToastNotificationActivatedEventArgs"; }
};

template <> struct traits<Windows::UI::WebUI::WebUIUserDataAccountProviderActivatedEventArgs>
{
    using abi = ABI::Windows::UI::WebUI::WebUIUserDataAccountProviderActivatedEventArgs;
    using default_interface = Windows::ApplicationModel::Activation::IUserDataAccountProviderActivatedEventArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.WebUI.WebUIUserDataAccountProviderActivatedEventArgs"; }
};

template <> struct traits<Windows::UI::WebUI::WebUIVoiceCommandActivatedEventArgs>
{
    using abi = ABI::Windows::UI::WebUI::WebUIVoiceCommandActivatedEventArgs;
    using default_interface = Windows::ApplicationModel::Activation::IVoiceCommandActivatedEventArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.WebUI.WebUIVoiceCommandActivatedEventArgs"; }
};

template <> struct traits<Windows::UI::WebUI::WebUIWebAccountProviderActivatedEventArgs>
{
    using abi = ABI::Windows::UI::WebUI::WebUIWebAccountProviderActivatedEventArgs;
    using default_interface = Windows::ApplicationModel::Activation::IWebAccountProviderActivatedEventArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.WebUI.WebUIWebAccountProviderActivatedEventArgs"; }
};

template <> struct traits<Windows::UI::WebUI::WebUIWebAuthenticationBrokerContinuationEventArgs>
{
    using abi = ABI::Windows::UI::WebUI::WebUIWebAuthenticationBrokerContinuationEventArgs;
    using default_interface = Windows::ApplicationModel::Activation::IWebAuthenticationBrokerContinuationEventArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.WebUI.WebUIWebAuthenticationBrokerContinuationEventArgs"; }
};

}

}