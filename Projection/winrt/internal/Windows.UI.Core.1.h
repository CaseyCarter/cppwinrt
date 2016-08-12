// C++ for the Windows Runtime v1.29
// Copyright (c) 2016 Microsoft Corporation

#pragma once

#include "../base.h"
#include "Windows.UI.Core.0.h"
#include "Windows.Foundation.0.h"
#include "Windows.Foundation.Collections.0.h"
#include "Windows.System.0.h"
#include "Windows.UI.Input.0.h"
#include "Windows.UI.Input.1.h"
#include "Windows.Foundation.Collections.1.h"
#include "Windows.Foundation.1.h"

WINRT_EXPORT namespace winrt {

namespace ABI::Windows::UI::Core {

struct CorePhysicalKeyStatus
{
    uint32_t RepeatCount;
    uint32_t ScanCode;
    bool IsExtendedKey;
    bool IsMenuKeyDown;
    bool WasKeyDown;
    bool IsKeyReleased;
};

struct CoreProximityEvaluation
{
    int32_t Score;
    Windows::Foundation::Point AdjustedPoint;
};

}

namespace Windows::UI::Core {

using CorePhysicalKeyStatus = ABI::Windows::UI::Core::CorePhysicalKeyStatus;
using CoreProximityEvaluation = ABI::Windows::UI::Core::CoreProximityEvaluation;

}

namespace ABI::Windows::UI::Core {

struct __declspec(uuid("d1f276c4-98d8-4636-bf49-eb79507548e9")) __declspec(novtable) DispatchedHandler : IUnknown
{
    virtual HRESULT __stdcall abi_Invoke() = 0;
};

struct __declspec(uuid("ff1c4c4a-9287-470b-836e-9086e3126ade")) __declspec(novtable) IAcceleratorKeyEventArgs : Windows::IInspectable
{
    virtual HRESULT __stdcall get_EventType(winrt::Windows::UI::Core::CoreAcceleratorKeyEventType * value) = 0;
    virtual HRESULT __stdcall get_VirtualKey(winrt::Windows::System::VirtualKey * value) = 0;
    virtual HRESULT __stdcall get_KeyStatus(Windows::UI::Core::CorePhysicalKeyStatus * value) = 0;
};

struct __declspec(uuid("d300a9f6-2f7e-4873-a555-166e596ee1c5")) __declspec(novtable) IAcceleratorKeyEventArgs2 : Windows::IInspectable
{
    virtual HRESULT __stdcall get_DeviceId(hstring * value) = 0;
};

struct __declspec(uuid("961ff258-21bf-4b42-a298-fa479d4c52e2")) __declspec(novtable) IAutomationProviderRequestedEventArgs : Windows::IInspectable
{
    virtual HRESULT __stdcall get_AutomationProvider(Windows::IInspectable ** value) = 0;
    virtual HRESULT __stdcall put_AutomationProvider(Windows::IInspectable * value) = 0;
};

struct __declspec(uuid("d603d28a-e411-4a4e-ba41-6a327a8675bc")) __declspec(novtable) IBackRequestedEventArgs : Windows::IInspectable
{
    virtual HRESULT __stdcall get_Handled(bool * value) = 0;
    virtual HRESULT __stdcall put_Handled(bool value) = 0;
};

struct __declspec(uuid("c584659f-99b2-4bcc-bd33-04e63f42902e")) __declspec(novtable) ICharacterReceivedEventArgs : Windows::IInspectable
{
    virtual HRESULT __stdcall get_KeyCode(uint32_t * value) = 0;
    virtual HRESULT __stdcall get_KeyStatus(Windows::UI::Core::CorePhysicalKeyStatus * value) = 0;
};

struct __declspec(uuid("347c11d7-f6f8-40e3-b29f-ae50d3e86486")) __declspec(novtable) IClosestInteractiveBoundsRequestedEventArgs : Windows::IInspectable
{
    virtual HRESULT __stdcall get_PointerPosition(Windows::Foundation::Point * value) = 0;
    virtual HRESULT __stdcall get_SearchBounds(Windows::Foundation::Rect * value) = 0;
    virtual HRESULT __stdcall get_ClosestInteractiveBounds(Windows::Foundation::Rect * value) = 0;
    virtual HRESULT __stdcall put_ClosestInteractiveBounds(Windows::Foundation::Rect value) = 0;
};

struct __declspec(uuid("9ffdf7f5-b8c9-4ef0-b7d2-1de626561fc8")) __declspec(novtable) ICoreAcceleratorKeys : Windows::IInspectable
{
    virtual HRESULT __stdcall add_AcceleratorKeyActivated(Windows::Foundation::TypedEventHandler<Windows::UI::Core::CoreDispatcher, Windows::UI::Core::AcceleratorKeyEventArgs> * handler, event_token * pCookie) = 0;
    virtual HRESULT __stdcall remove_AcceleratorKeyActivated(event_token cookie) = 0;
};

struct __declspec(uuid("f303043a-e8bf-4e8e-ae69-c9dadd57a114")) __declspec(novtable) ICoreClosestInteractiveBoundsRequested : Windows::IInspectable
{
    virtual HRESULT __stdcall add_ClosestInteractiveBoundsRequested(Windows::Foundation::TypedEventHandler<Windows::UI::Core::CoreComponentInputSource, Windows::UI::Core::ClosestInteractiveBoundsRequestedEventArgs> * handler, event_token * pCookie) = 0;
    virtual HRESULT __stdcall remove_ClosestInteractiveBoundsRequested(event_token cookie) = 0;
};

struct __declspec(uuid("52f96fa3-8742-4411-ae69-79a85f29ac8b")) __declspec(novtable) ICoreComponentFocusable : Windows::IInspectable
{
    virtual HRESULT __stdcall get_HasFocus(bool * value) = 0;
    virtual HRESULT __stdcall add_GotFocus(Windows::Foundation::TypedEventHandler<Windows::IInspectable, Windows::UI::Core::CoreWindowEventArgs> * handler, event_token * pCookie) = 0;
    virtual HRESULT __stdcall remove_GotFocus(event_token cookie) = 0;
    virtual HRESULT __stdcall add_LostFocus(Windows::Foundation::TypedEventHandler<Windows::IInspectable, Windows::UI::Core::CoreWindowEventArgs> * handler, event_token * pCookie) = 0;
    virtual HRESULT __stdcall remove_LostFocus(event_token cookie) = 0;
};

struct __declspec(uuid("96893acf-111d-442c-8a77-b87992f8e2d6")) __declspec(novtable) ICoreCursor : Windows::IInspectable
{
    virtual HRESULT __stdcall get_Id(uint32_t * value) = 0;
    virtual HRESULT __stdcall get_Type(winrt::Windows::UI::Core::CoreCursorType * value) = 0;
};

struct __declspec(uuid("f6359621-a79d-4ed3-8c32-a9ef9d6b76a4")) __declspec(novtable) ICoreCursorFactory : Windows::IInspectable
{
    virtual HRESULT __stdcall abi_CreateCursor(winrt::Windows::UI::Core::CoreCursorType type, uint32_t id, Windows::UI::Core::ICoreCursor ** cursor) = 0;
};

struct __declspec(uuid("60db2fa8-b705-4fde-a7d6-ebbb1891d39e")) __declspec(novtable) ICoreDispatcher : Windows::IInspectable
{
    virtual HRESULT __stdcall get_HasThreadAccess(bool * value) = 0;
    virtual HRESULT __stdcall abi_ProcessEvents(winrt::Windows::UI::Core::CoreProcessEventsOption options) = 0;
    virtual HRESULT __stdcall abi_RunAsync(winrt::Windows::UI::Core::CoreDispatcherPriority priority, Windows::UI::Core::DispatchedHandler * agileCallback, Windows::Foundation::IAsyncAction ** asyncAction) = 0;
    virtual HRESULT __stdcall abi_RunIdleAsync(Windows::UI::Core::IdleDispatchedHandler * agileCallback, Windows::Foundation::IAsyncAction ** asyncAction) = 0;
};

struct __declspec(uuid("6f5e63c7-e3aa-4eae-b0e0-dcf321ca4b2f")) __declspec(novtable) ICoreDispatcher2 : Windows::IInspectable
{
    virtual HRESULT __stdcall abi_TryRunAsync(winrt::Windows::UI::Core::CoreDispatcherPriority priority, Windows::UI::Core::DispatchedHandler * agileCallback, Windows::Foundation::IAsyncOperation<bool> ** asyncOperation) = 0;
    virtual HRESULT __stdcall abi_TryRunIdleAsync(Windows::UI::Core::IdleDispatchedHandler * agileCallback, Windows::Foundation::IAsyncOperation<bool> ** asyncOperation) = 0;
};

struct __declspec(uuid("bafaecad-484d-41be-ba80-1d58c65263ea")) __declspec(novtable) ICoreDispatcherWithTaskPriority : Windows::IInspectable
{
    virtual HRESULT __stdcall get_CurrentPriority(winrt::Windows::UI::Core::CoreDispatcherPriority * value) = 0;
    virtual HRESULT __stdcall put_CurrentPriority(winrt::Windows::UI::Core::CoreDispatcherPriority value) = 0;
    virtual HRESULT __stdcall abi_ShouldYield(bool * value) = 0;
    virtual HRESULT __stdcall abi_ShouldYieldToPriority(winrt::Windows::UI::Core::CoreDispatcherPriority priority, bool * value) = 0;
    virtual HRESULT __stdcall abi_StopProcessEvents() = 0;
};

struct __declspec(uuid("9f488807-4580-4be8-be68-92a9311713bb")) __declspec(novtable) ICoreInputSourceBase : Windows::IInspectable
{
    virtual HRESULT __stdcall get_Dispatcher(Windows::UI::Core::ICoreDispatcher ** value) = 0;
    virtual HRESULT __stdcall get_IsInputEnabled(bool * value) = 0;
    virtual HRESULT __stdcall put_IsInputEnabled(bool value) = 0;
    virtual HRESULT __stdcall add_InputEnabled(Windows::Foundation::TypedEventHandler<Windows::IInspectable, Windows::UI::Core::InputEnabledEventArgs> * handler, event_token * pCookie) = 0;
    virtual HRESULT __stdcall remove_InputEnabled(event_token cookie) = 0;
};

struct __declspec(uuid("231c9088-e469-4df1-b208-6e490d71cb90")) __declspec(novtable) ICoreKeyboardInputSource : Windows::IInspectable
{
    virtual HRESULT __stdcall abi_GetCurrentKeyState(winrt::Windows::System::VirtualKey virtualKey, winrt::Windows::UI::Core::CoreVirtualKeyStates * KeyState) = 0;
    virtual HRESULT __stdcall add_CharacterReceived(Windows::Foundation::TypedEventHandler<Windows::IInspectable, Windows::UI::Core::CharacterReceivedEventArgs> * handler, event_token * pCookie) = 0;
    virtual HRESULT __stdcall remove_CharacterReceived(event_token cookie) = 0;
    virtual HRESULT __stdcall add_KeyDown(Windows::Foundation::TypedEventHandler<Windows::IInspectable, Windows::UI::Core::KeyEventArgs> * handler, event_token * pCookie) = 0;
    virtual HRESULT __stdcall remove_KeyDown(event_token cookie) = 0;
    virtual HRESULT __stdcall add_KeyUp(Windows::Foundation::TypedEventHandler<Windows::IInspectable, Windows::UI::Core::KeyEventArgs> * handler, event_token * pCookie) = 0;
    virtual HRESULT __stdcall remove_KeyUp(event_token cookie) = 0;
};

struct __declspec(uuid("fa24cb94-f963-47a5-8778-207c482b0afd")) __declspec(novtable) ICoreKeyboardInputSource2 : Windows::IInspectable
{
    virtual HRESULT __stdcall abi_GetCurrentKeyEventDeviceId(hstring * value) = 0;
};

struct __declspec(uuid("bbf1bb18-e47a-48eb-8807-f8f8d3ea4551")) __declspec(novtable) ICorePointerInputSource : Windows::IInspectable
{
    virtual HRESULT __stdcall abi_ReleasePointerCapture() = 0;
    virtual HRESULT __stdcall abi_SetPointerCapture() = 0;
    virtual HRESULT __stdcall get_HasCapture(bool * value) = 0;
    virtual HRESULT __stdcall get_PointerPosition(Windows::Foundation::Point * value) = 0;
    virtual HRESULT __stdcall get_PointerCursor(Windows::UI::Core::ICoreCursor ** value) = 0;
    virtual HRESULT __stdcall put_PointerCursor(Windows::UI::Core::ICoreCursor * value) = 0;
    virtual HRESULT __stdcall add_PointerCaptureLost(Windows::Foundation::TypedEventHandler<Windows::IInspectable, Windows::UI::Core::PointerEventArgs> * handler, event_token * cookie) = 0;
    virtual HRESULT __stdcall remove_PointerCaptureLost(event_token cookie) = 0;
    virtual HRESULT __stdcall add_PointerEntered(Windows::Foundation::TypedEventHandler<Windows::IInspectable, Windows::UI::Core::PointerEventArgs> * handler, event_token * cookie) = 0;
    virtual HRESULT __stdcall remove_PointerEntered(event_token cookie) = 0;
    virtual HRESULT __stdcall add_PointerExited(Windows::Foundation::TypedEventHandler<Windows::IInspectable, Windows::UI::Core::PointerEventArgs> * handler, event_token * cookie) = 0;
    virtual HRESULT __stdcall remove_PointerExited(event_token cookie) = 0;
    virtual HRESULT __stdcall add_PointerMoved(Windows::Foundation::TypedEventHandler<Windows::IInspectable, Windows::UI::Core::PointerEventArgs> * handler, event_token * cookie) = 0;
    virtual HRESULT __stdcall remove_PointerMoved(event_token cookie) = 0;
    virtual HRESULT __stdcall add_PointerPressed(Windows::Foundation::TypedEventHandler<Windows::IInspectable, Windows::UI::Core::PointerEventArgs> * handler, event_token * cookie) = 0;
    virtual HRESULT __stdcall remove_PointerPressed(event_token cookie) = 0;
    virtual HRESULT __stdcall add_PointerReleased(Windows::Foundation::TypedEventHandler<Windows::IInspectable, Windows::UI::Core::PointerEventArgs> * handler, event_token * cookie) = 0;
    virtual HRESULT __stdcall remove_PointerReleased(event_token cookie) = 0;
    virtual HRESULT __stdcall add_PointerWheelChanged(Windows::Foundation::TypedEventHandler<Windows::IInspectable, Windows::UI::Core::PointerEventArgs> * handler, event_token * cookie) = 0;
    virtual HRESULT __stdcall remove_PointerWheelChanged(event_token cookie) = 0;
};

struct __declspec(uuid("8f9d0c94-5688-4b0c-a9f1-f931f7fa3dc3")) __declspec(novtable) ICorePointerRedirector : Windows::IInspectable
{
    virtual HRESULT __stdcall add_PointerRoutedAway(Windows::Foundation::TypedEventHandler<Windows::UI::Core::ICorePointerRedirector, Windows::UI::Core::PointerEventArgs> * handler, event_token * cookie) = 0;
    virtual HRESULT __stdcall remove_PointerRoutedAway(event_token cookie) = 0;
    virtual HRESULT __stdcall add_PointerRoutedTo(Windows::Foundation::TypedEventHandler<Windows::UI::Core::ICorePointerRedirector, Windows::UI::Core::PointerEventArgs> * handler, event_token * cookie) = 0;
    virtual HRESULT __stdcall remove_PointerRoutedTo(event_token cookie) = 0;
    virtual HRESULT __stdcall add_PointerRoutedReleased(Windows::Foundation::TypedEventHandler<Windows::UI::Core::ICorePointerRedirector, Windows::UI::Core::PointerEventArgs> * handler, event_token * cookie) = 0;
    virtual HRESULT __stdcall remove_PointerRoutedReleased(event_token cookie) = 0;
};

struct __declspec(uuid("b1d8a289-3acf-4124-9fa3-ea8aba353c21")) __declspec(novtable) ICoreTouchHitTesting : Windows::IInspectable
{
    virtual HRESULT __stdcall add_TouchHitTesting(Windows::Foundation::TypedEventHandler<Windows::IInspectable, Windows::UI::Core::TouchHitTestingEventArgs> * handler, event_token * pCookie) = 0;
    virtual HRESULT __stdcall remove_TouchHitTesting(event_token cookie) = 0;
};

struct __declspec(uuid("79b9d5f2-879e-4b89-b798-79e47598030c")) __declspec(novtable) ICoreWindow : Windows::IInspectable
{
    virtual HRESULT __stdcall get_AutomationHostProvider(Windows::IInspectable ** value) = 0;
    virtual HRESULT __stdcall get_Bounds(Windows::Foundation::Rect * value) = 0;
    virtual HRESULT __stdcall get_CustomProperties(Windows::Foundation::Collections::IPropertySet ** value) = 0;
    virtual HRESULT __stdcall get_Dispatcher(Windows::UI::Core::ICoreDispatcher ** value) = 0;
    virtual HRESULT __stdcall get_FlowDirection(winrt::Windows::UI::Core::CoreWindowFlowDirection * value) = 0;
    virtual HRESULT __stdcall put_FlowDirection(winrt::Windows::UI::Core::CoreWindowFlowDirection value) = 0;
    virtual HRESULT __stdcall get_IsInputEnabled(bool * value) = 0;
    virtual HRESULT __stdcall put_IsInputEnabled(bool value) = 0;
    virtual HRESULT __stdcall get_PointerCursor(Windows::UI::Core::ICoreCursor ** value) = 0;
    virtual HRESULT __stdcall put_PointerCursor(Windows::UI::Core::ICoreCursor * value) = 0;
    virtual HRESULT __stdcall get_PointerPosition(Windows::Foundation::Point * value) = 0;
    virtual HRESULT __stdcall get_Visible(bool * value) = 0;
    virtual HRESULT __stdcall abi_Activate() = 0;
    virtual HRESULT __stdcall abi_Close() = 0;
    virtual HRESULT __stdcall abi_GetAsyncKeyState(winrt::Windows::System::VirtualKey virtualKey, winrt::Windows::UI::Core::CoreVirtualKeyStates * KeyState) = 0;
    virtual HRESULT __stdcall abi_GetKeyState(winrt::Windows::System::VirtualKey virtualKey, winrt::Windows::UI::Core::CoreVirtualKeyStates * KeyState) = 0;
    virtual HRESULT __stdcall abi_ReleasePointerCapture() = 0;
    virtual HRESULT __stdcall abi_SetPointerCapture() = 0;
    virtual HRESULT __stdcall add_Activated(Windows::Foundation::TypedEventHandler<Windows::UI::Core::CoreWindow, Windows::UI::Core::WindowActivatedEventArgs> * handler, event_token * pCookie) = 0;
    virtual HRESULT __stdcall remove_Activated(event_token cookie) = 0;
    virtual HRESULT __stdcall add_AutomationProviderRequested(Windows::Foundation::TypedEventHandler<Windows::UI::Core::CoreWindow, Windows::UI::Core::AutomationProviderRequestedEventArgs> * handler, event_token * cookie) = 0;
    virtual HRESULT __stdcall remove_AutomationProviderRequested(event_token cookie) = 0;
    virtual HRESULT __stdcall add_CharacterReceived(Windows::Foundation::TypedEventHandler<Windows::UI::Core::CoreWindow, Windows::UI::Core::CharacterReceivedEventArgs> * handler, event_token * pCookie) = 0;
    virtual HRESULT __stdcall remove_CharacterReceived(event_token cookie) = 0;
    virtual HRESULT __stdcall add_Closed(Windows::Foundation::TypedEventHandler<Windows::UI::Core::CoreWindow, Windows::UI::Core::CoreWindowEventArgs> * handler, event_token * pCookie) = 0;
    virtual HRESULT __stdcall remove_Closed(event_token cookie) = 0;
    virtual HRESULT __stdcall add_InputEnabled(Windows::Foundation::TypedEventHandler<Windows::UI::Core::CoreWindow, Windows::UI::Core::InputEnabledEventArgs> * handler, event_token * pCookie) = 0;
    virtual HRESULT __stdcall remove_InputEnabled(event_token cookie) = 0;
    virtual HRESULT __stdcall add_KeyDown(Windows::Foundation::TypedEventHandler<Windows::UI::Core::CoreWindow, Windows::UI::Core::KeyEventArgs> * handler, event_token * pCookie) = 0;
    virtual HRESULT __stdcall remove_KeyDown(event_token cookie) = 0;
    virtual HRESULT __stdcall add_KeyUp(Windows::Foundation::TypedEventHandler<Windows::UI::Core::CoreWindow, Windows::UI::Core::KeyEventArgs> * handler, event_token * pCookie) = 0;
    virtual HRESULT __stdcall remove_KeyUp(event_token cookie) = 0;
    virtual HRESULT __stdcall add_PointerCaptureLost(Windows::Foundation::TypedEventHandler<Windows::UI::Core::CoreWindow, Windows::UI::Core::PointerEventArgs> * handler, event_token * cookie) = 0;
    virtual HRESULT __stdcall remove_PointerCaptureLost(event_token cookie) = 0;
    virtual HRESULT __stdcall add_PointerEntered(Windows::Foundation::TypedEventHandler<Windows::UI::Core::CoreWindow, Windows::UI::Core::PointerEventArgs> * handler, event_token * cookie) = 0;
    virtual HRESULT __stdcall remove_PointerEntered(event_token cookie) = 0;
    virtual HRESULT __stdcall add_PointerExited(Windows::Foundation::TypedEventHandler<Windows::UI::Core::CoreWindow, Windows::UI::Core::PointerEventArgs> * handler, event_token * cookie) = 0;
    virtual HRESULT __stdcall remove_PointerExited(event_token cookie) = 0;
    virtual HRESULT __stdcall add_PointerMoved(Windows::Foundation::TypedEventHandler<Windows::UI::Core::CoreWindow, Windows::UI::Core::PointerEventArgs> * handler, event_token * cookie) = 0;
    virtual HRESULT __stdcall remove_PointerMoved(event_token cookie) = 0;
    virtual HRESULT __stdcall add_PointerPressed(Windows::Foundation::TypedEventHandler<Windows::UI::Core::CoreWindow, Windows::UI::Core::PointerEventArgs> * handler, event_token * cookie) = 0;
    virtual HRESULT __stdcall remove_PointerPressed(event_token cookie) = 0;
    virtual HRESULT __stdcall add_PointerReleased(Windows::Foundation::TypedEventHandler<Windows::UI::Core::CoreWindow, Windows::UI::Core::PointerEventArgs> * handler, event_token * cookie) = 0;
    virtual HRESULT __stdcall remove_PointerReleased(event_token cookie) = 0;
    virtual HRESULT __stdcall add_TouchHitTesting(Windows::Foundation::TypedEventHandler<Windows::UI::Core::CoreWindow, Windows::UI::Core::TouchHitTestingEventArgs> * handler, event_token * pCookie) = 0;
    virtual HRESULT __stdcall remove_TouchHitTesting(event_token cookie) = 0;
    virtual HRESULT __stdcall add_PointerWheelChanged(Windows::Foundation::TypedEventHandler<Windows::UI::Core::CoreWindow, Windows::UI::Core::PointerEventArgs> * handler, event_token * cookie) = 0;
    virtual HRESULT __stdcall remove_PointerWheelChanged(event_token cookie) = 0;
    virtual HRESULT __stdcall add_SizeChanged(Windows::Foundation::TypedEventHandler<Windows::UI::Core::CoreWindow, Windows::UI::Core::WindowSizeChangedEventArgs> * handler, event_token * pCookie) = 0;
    virtual HRESULT __stdcall remove_SizeChanged(event_token cookie) = 0;
    virtual HRESULT __stdcall add_VisibilityChanged(Windows::Foundation::TypedEventHandler<Windows::UI::Core::CoreWindow, Windows::UI::Core::VisibilityChangedEventArgs> * handler, event_token * pCookie) = 0;
    virtual HRESULT __stdcall remove_VisibilityChanged(event_token cookie) = 0;
};

struct __declspec(uuid("7c2b1b85-6917-4361-9c02-0d9e3a420b95")) __declspec(novtable) ICoreWindow2 : Windows::IInspectable
{
    virtual HRESULT __stdcall put_PointerPosition(Windows::Foundation::Point value) = 0;
};

struct __declspec(uuid("32c20dd8-faef-4375-a2ab-32640e4815c7")) __declspec(novtable) ICoreWindow3 : Windows::IInspectable
{
    virtual HRESULT __stdcall add_ClosestInteractiveBoundsRequested(Windows::Foundation::TypedEventHandler<Windows::UI::Core::CoreWindow, Windows::UI::Core::ClosestInteractiveBoundsRequestedEventArgs> * handler, event_token * pCookie) = 0;
    virtual HRESULT __stdcall remove_ClosestInteractiveBoundsRequested(event_token cookie) = 0;
    virtual HRESULT __stdcall abi_GetCurrentKeyEventDeviceId(hstring * value) = 0;
};

struct __declspec(uuid("272b1ef3-c633-4da5-a26c-c6d0f56b29da")) __declspec(novtable) ICoreWindowEventArgs : Windows::IInspectable
{
    virtual HRESULT __stdcall get_Handled(bool * value) = 0;
    virtual HRESULT __stdcall put_Handled(bool value) = 0;
};

struct __declspec(uuid("b8f0b925-b350-48b3-a198-5c1a84700243")) __declspec(novtable) ICoreWindowResizeManager : Windows::IInspectable
{
    virtual HRESULT __stdcall abi_NotifyLayoutCompleted() = 0;
};

struct __declspec(uuid("bb74f27b-a544-4301-80e6-0ae033ef4536")) __declspec(novtable) ICoreWindowResizeManagerLayoutCapability : Windows::IInspectable
{
    virtual HRESULT __stdcall put_ShouldWaitForLayoutCompletion(bool value) = 0;
    virtual HRESULT __stdcall get_ShouldWaitForLayoutCompletion(bool * value) = 0;
};

struct __declspec(uuid("ae4a9045-6d70-49db-8e68-46ffbd17d38d")) __declspec(novtable) ICoreWindowResizeManagerStatics : Windows::IInspectable
{
    virtual HRESULT __stdcall abi_GetForCurrentView(Windows::UI::Core::ICoreWindowResizeManager ** CoreWindowResizeManager) = 0;
};

struct __declspec(uuid("4d239005-3c2a-41b1-9022-536bb9cf93b1")) __declspec(novtable) ICoreWindowStatic : Windows::IInspectable
{
    virtual HRESULT __stdcall abi_GetForCurrentThread(Windows::UI::Core::ICoreWindow ** ppWindow) = 0;
};

struct __declspec(uuid("98bb6a24-dc1c-43cb-b4ed-d1c0eb2391f3")) __declspec(novtable) IIdleDispatchedHandlerArgs : Windows::IInspectable
{
    virtual HRESULT __stdcall get_IsDispatcherIdle(bool * value) = 0;
};

struct __declspec(uuid("188f20d6-9873-464a-ace5-57e010f465e6")) __declspec(novtable) IInitializeWithCoreWindow : Windows::IInspectable
{
    virtual HRESULT __stdcall abi_Initialize(Windows::UI::Core::ICoreWindow * window) = 0;
};

struct __declspec(uuid("80371d4f-2fd8-4c24-aa86-3163a87b4e5a")) __declspec(novtable) IInputEnabledEventArgs : Windows::IInspectable
{
    virtual HRESULT __stdcall get_InputEnabled(bool * value) = 0;
};

struct __declspec(uuid("5ff5e930-2544-4a17-bd78-1f2fdebb106b")) __declspec(novtable) IKeyEventArgs : Windows::IInspectable
{
    virtual HRESULT __stdcall get_VirtualKey(winrt::Windows::System::VirtualKey * value) = 0;
    virtual HRESULT __stdcall get_KeyStatus(Windows::UI::Core::CorePhysicalKeyStatus * value) = 0;
};

struct __declspec(uuid("583add98-0790-4571-9b12-645ef9d79e42")) __declspec(novtable) IKeyEventArgs2 : Windows::IInspectable
{
    virtual HRESULT __stdcall get_DeviceId(hstring * value) = 0;
};

struct __declspec(uuid("920d9cb1-a5fc-4a21-8c09-49dfe6ffe25f")) __declspec(novtable) IPointerEventArgs : Windows::IInspectable
{
    virtual HRESULT __stdcall get_CurrentPoint(Windows::UI::Input::IPointerPoint ** value) = 0;
    virtual HRESULT __stdcall get_KeyModifiers(winrt::Windows::System::VirtualKeyModifiers * value) = 0;
    virtual HRESULT __stdcall abi_GetIntermediatePoints(Windows::Foundation::Collections::IVector<Windows::UI::Input::PointerPoint> ** value) = 0;
};

struct __declspec(uuid("93023118-cf50-42a6-9706-69107fa122e1")) __declspec(novtable) ISystemNavigationManager : Windows::IInspectable
{
    virtual HRESULT __stdcall add_BackRequested(Windows::Foundation::EventHandler<Windows::UI::Core::BackRequestedEventArgs> * handler, event_token * token) = 0;
    virtual HRESULT __stdcall remove_BackRequested(event_token token) = 0;
};

struct __declspec(uuid("8c510401-67be-49ae-9509-671c1e54a389")) __declspec(novtable) ISystemNavigationManager2 : Windows::IInspectable
{
    virtual HRESULT __stdcall get_AppViewBackButtonVisibility(winrt::Windows::UI::Core::AppViewBackButtonVisibility * value) = 0;
    virtual HRESULT __stdcall put_AppViewBackButtonVisibility(winrt::Windows::UI::Core::AppViewBackButtonVisibility value) = 0;
};

struct __declspec(uuid("dc52b5ce-bee0-4305-8c54-68228ed683b5")) __declspec(novtable) ISystemNavigationManagerStatics : Windows::IInspectable
{
    virtual HRESULT __stdcall abi_GetForCurrentView(Windows::UI::Core::ISystemNavigationManager ** loader) = 0;
};

struct __declspec(uuid("22f3b823-0b7c-424e-9df7-33d4f962931b")) __declspec(novtable) ITouchHitTestingEventArgs : Windows::IInspectable
{
    virtual HRESULT __stdcall get_ProximityEvaluation(Windows::UI::Core::CoreProximityEvaluation * value) = 0;
    virtual HRESULT __stdcall put_ProximityEvaluation(Windows::UI::Core::CoreProximityEvaluation value) = 0;
    virtual HRESULT __stdcall get_Point(Windows::Foundation::Point * value) = 0;
    virtual HRESULT __stdcall get_BoundingBox(Windows::Foundation::Rect * value) = 0;
    virtual HRESULT __stdcall abi_EvaluateProximityToRect(Windows::Foundation::Rect controlBoundingBox, Windows::UI::Core::CoreProximityEvaluation * proximityEvaluation) = 0;
    virtual HRESULT __stdcall abi_EvaluateProximityToPolygon(uint32_t __controlVerticesSize, Windows::Foundation::Point * controlVertices, Windows::UI::Core::CoreProximityEvaluation * proximityEvaluation) = 0;
};

struct __declspec(uuid("bf9918ea-d801-4564-a495-b1e84f8ad085")) __declspec(novtable) IVisibilityChangedEventArgs : Windows::IInspectable
{
    virtual HRESULT __stdcall get_Visible(bool * value) = 0;
};

struct __declspec(uuid("179d65e7-4658-4cb6-aa13-41d094ea255e")) __declspec(novtable) IWindowActivatedEventArgs : Windows::IInspectable
{
    virtual HRESULT __stdcall get_WindowActivationState(winrt::Windows::UI::Core::CoreWindowActivationState * value) = 0;
};

struct __declspec(uuid("5a200ec7-0426-47dc-b86c-6f475915e451")) __declspec(novtable) IWindowSizeChangedEventArgs : Windows::IInspectable
{
    virtual HRESULT __stdcall get_Size(Windows::Foundation::Size * value) = 0;
};

struct __declspec(uuid("a42b0c24-7f21-4abc-99c1-8f01007f0880")) __declspec(novtable) IdleDispatchedHandler : IUnknown
{
    virtual HRESULT __stdcall abi_Invoke(Windows::UI::Core::IIdleDispatchedHandlerArgs * e) = 0;
};

}

namespace ABI {

template <> struct traits<Windows::UI::Core::AcceleratorKeyEventArgs> { using default_interface = Windows::UI::Core::IAcceleratorKeyEventArgs; };
template <> struct traits<Windows::UI::Core::AutomationProviderRequestedEventArgs> { using default_interface = Windows::UI::Core::IAutomationProviderRequestedEventArgs; };
template <> struct traits<Windows::UI::Core::BackRequestedEventArgs> { using default_interface = Windows::UI::Core::IBackRequestedEventArgs; };
template <> struct traits<Windows::UI::Core::CharacterReceivedEventArgs> { using default_interface = Windows::UI::Core::ICharacterReceivedEventArgs; };
template <> struct traits<Windows::UI::Core::ClosestInteractiveBoundsRequestedEventArgs> { using default_interface = Windows::UI::Core::IClosestInteractiveBoundsRequestedEventArgs; };
template <> struct traits<Windows::UI::Core::CoreAcceleratorKeys> { using default_interface = Windows::UI::Core::ICoreAcceleratorKeys; };
template <> struct traits<Windows::UI::Core::CoreComponentInputSource> { using default_interface = Windows::UI::Core::ICoreInputSourceBase; };
template <> struct traits<Windows::UI::Core::CoreCursor> { using default_interface = Windows::UI::Core::ICoreCursor; };
template <> struct traits<Windows::UI::Core::CoreDispatcher> { using default_interface = Windows::UI::Core::ICoreDispatcher; };
template <> struct traits<Windows::UI::Core::CoreIndependentInputSource> { using default_interface = Windows::UI::Core::ICoreInputSourceBase; };
template <> struct traits<Windows::UI::Core::CoreWindow> { using default_interface = Windows::UI::Core::ICoreWindow; };
template <> struct traits<Windows::UI::Core::CoreWindowEventArgs> { using default_interface = Windows::UI::Core::ICoreWindowEventArgs; };
template <> struct traits<Windows::UI::Core::CoreWindowResizeManager> { using default_interface = Windows::UI::Core::ICoreWindowResizeManager; };
template <> struct traits<Windows::UI::Core::IdleDispatchedHandlerArgs> { using default_interface = Windows::UI::Core::IIdleDispatchedHandlerArgs; };
template <> struct traits<Windows::UI::Core::InputEnabledEventArgs> { using default_interface = Windows::UI::Core::IInputEnabledEventArgs; };
template <> struct traits<Windows::UI::Core::KeyEventArgs> { using default_interface = Windows::UI::Core::IKeyEventArgs; };
template <> struct traits<Windows::UI::Core::PointerEventArgs> { using default_interface = Windows::UI::Core::IPointerEventArgs; };
template <> struct traits<Windows::UI::Core::SystemNavigationManager> { using default_interface = Windows::UI::Core::ISystemNavigationManager; };
template <> struct traits<Windows::UI::Core::TouchHitTestingEventArgs> { using default_interface = Windows::UI::Core::ITouchHitTestingEventArgs; };
template <> struct traits<Windows::UI::Core::VisibilityChangedEventArgs> { using default_interface = Windows::UI::Core::IVisibilityChangedEventArgs; };
template <> struct traits<Windows::UI::Core::WindowActivatedEventArgs> { using default_interface = Windows::UI::Core::IWindowActivatedEventArgs; };
template <> struct traits<Windows::UI::Core::WindowSizeChangedEventArgs> { using default_interface = Windows::UI::Core::IWindowSizeChangedEventArgs; };

}

namespace Windows::UI::Core {

template <typename T> class impl_IAcceleratorKeyEventArgs;
template <typename T> class impl_IAcceleratorKeyEventArgs2;
template <typename T> class impl_IAutomationProviderRequestedEventArgs;
template <typename T> class impl_IBackRequestedEventArgs;
template <typename T> class impl_ICharacterReceivedEventArgs;
template <typename T> class impl_IClosestInteractiveBoundsRequestedEventArgs;
template <typename T> class impl_ICoreAcceleratorKeys;
template <typename T> class impl_ICoreClosestInteractiveBoundsRequested;
template <typename T> class impl_ICoreComponentFocusable;
template <typename T> class impl_ICoreCursor;
template <typename T> class impl_ICoreCursorFactory;
template <typename T> class impl_ICoreDispatcher;
template <typename T> class impl_ICoreDispatcher2;
template <typename T> class impl_ICoreDispatcherWithTaskPriority;
template <typename T> class impl_ICoreInputSourceBase;
template <typename T> class impl_ICoreKeyboardInputSource;
template <typename T> class impl_ICoreKeyboardInputSource2;
template <typename T> class impl_ICorePointerInputSource;
template <typename T> class impl_ICorePointerRedirector;
template <typename T> class impl_ICoreTouchHitTesting;
template <typename T> class impl_ICoreWindow;
template <typename T> class impl_ICoreWindow2;
template <typename T> class impl_ICoreWindow3;
template <typename T> class impl_ICoreWindowEventArgs;
template <typename T> class impl_ICoreWindowResizeManager;
template <typename T> class impl_ICoreWindowResizeManagerLayoutCapability;
template <typename T> class impl_ICoreWindowResizeManagerStatics;
template <typename T> class impl_ICoreWindowStatic;
template <typename T> class impl_IIdleDispatchedHandlerArgs;
template <typename T> class impl_IInitializeWithCoreWindow;
template <typename T> class impl_IInputEnabledEventArgs;
template <typename T> class impl_IKeyEventArgs;
template <typename T> class impl_IKeyEventArgs2;
template <typename T> class impl_IPointerEventArgs;
template <typename T> class impl_ISystemNavigationManager;
template <typename T> class impl_ISystemNavigationManager2;
template <typename T> class impl_ISystemNavigationManagerStatics;
template <typename T> class impl_ITouchHitTestingEventArgs;
template <typename T> class impl_IVisibilityChangedEventArgs;
template <typename T> class impl_IWindowActivatedEventArgs;
template <typename T> class impl_IWindowSizeChangedEventArgs;
template <typename T> struct impl_DispatchedHandler;
template <typename T> struct impl_IdleDispatchedHandler;

}

namespace impl {

template <> struct traits<Windows::UI::Core::DispatchedHandler>
{
    using abi = ABI::Windows::UI::Core::DispatchedHandler;
};

template <> struct traits<Windows::UI::Core::IAcceleratorKeyEventArgs>
{
    using abi = ABI::Windows::UI::Core::IAcceleratorKeyEventArgs;
    template <typename D> using consume = Windows::UI::Core::impl_IAcceleratorKeyEventArgs<D>;
};

template <> struct traits<Windows::UI::Core::IAcceleratorKeyEventArgs2>
{
    using abi = ABI::Windows::UI::Core::IAcceleratorKeyEventArgs2;
    template <typename D> using consume = Windows::UI::Core::impl_IAcceleratorKeyEventArgs2<D>;
};

template <> struct traits<Windows::UI::Core::IAutomationProviderRequestedEventArgs>
{
    using abi = ABI::Windows::UI::Core::IAutomationProviderRequestedEventArgs;
    template <typename D> using consume = Windows::UI::Core::impl_IAutomationProviderRequestedEventArgs<D>;
};

template <> struct traits<Windows::UI::Core::IBackRequestedEventArgs>
{
    using abi = ABI::Windows::UI::Core::IBackRequestedEventArgs;
    template <typename D> using consume = Windows::UI::Core::impl_IBackRequestedEventArgs<D>;
};

template <> struct traits<Windows::UI::Core::ICharacterReceivedEventArgs>
{
    using abi = ABI::Windows::UI::Core::ICharacterReceivedEventArgs;
    template <typename D> using consume = Windows::UI::Core::impl_ICharacterReceivedEventArgs<D>;
};

template <> struct traits<Windows::UI::Core::IClosestInteractiveBoundsRequestedEventArgs>
{
    using abi = ABI::Windows::UI::Core::IClosestInteractiveBoundsRequestedEventArgs;
    template <typename D> using consume = Windows::UI::Core::impl_IClosestInteractiveBoundsRequestedEventArgs<D>;
};

template <> struct traits<Windows::UI::Core::ICoreAcceleratorKeys>
{
    using abi = ABI::Windows::UI::Core::ICoreAcceleratorKeys;
    template <typename D> using consume = Windows::UI::Core::impl_ICoreAcceleratorKeys<D>;
};

template <> struct traits<Windows::UI::Core::ICoreClosestInteractiveBoundsRequested>
{
    using abi = ABI::Windows::UI::Core::ICoreClosestInteractiveBoundsRequested;
    template <typename D> using consume = Windows::UI::Core::impl_ICoreClosestInteractiveBoundsRequested<D>;
};

template <> struct traits<Windows::UI::Core::ICoreComponentFocusable>
{
    using abi = ABI::Windows::UI::Core::ICoreComponentFocusable;
    template <typename D> using consume = Windows::UI::Core::impl_ICoreComponentFocusable<D>;
};

template <> struct traits<Windows::UI::Core::ICoreCursor>
{
    using abi = ABI::Windows::UI::Core::ICoreCursor;
    template <typename D> using consume = Windows::UI::Core::impl_ICoreCursor<D>;
};

template <> struct traits<Windows::UI::Core::ICoreCursorFactory>
{
    using abi = ABI::Windows::UI::Core::ICoreCursorFactory;
    template <typename D> using consume = Windows::UI::Core::impl_ICoreCursorFactory<D>;
};

template <> struct traits<Windows::UI::Core::ICoreDispatcher>
{
    using abi = ABI::Windows::UI::Core::ICoreDispatcher;
    template <typename D> using consume = Windows::UI::Core::impl_ICoreDispatcher<D>;
};

template <> struct traits<Windows::UI::Core::ICoreDispatcher2>
{
    using abi = ABI::Windows::UI::Core::ICoreDispatcher2;
    template <typename D> using consume = Windows::UI::Core::impl_ICoreDispatcher2<D>;
};

template <> struct traits<Windows::UI::Core::ICoreDispatcherWithTaskPriority>
{
    using abi = ABI::Windows::UI::Core::ICoreDispatcherWithTaskPriority;
    template <typename D> using consume = Windows::UI::Core::impl_ICoreDispatcherWithTaskPriority<D>;
};

template <> struct traits<Windows::UI::Core::ICoreInputSourceBase>
{
    using abi = ABI::Windows::UI::Core::ICoreInputSourceBase;
    template <typename D> using consume = Windows::UI::Core::impl_ICoreInputSourceBase<D>;
};

template <> struct traits<Windows::UI::Core::ICoreKeyboardInputSource>
{
    using abi = ABI::Windows::UI::Core::ICoreKeyboardInputSource;
    template <typename D> using consume = Windows::UI::Core::impl_ICoreKeyboardInputSource<D>;
};

template <> struct traits<Windows::UI::Core::ICoreKeyboardInputSource2>
{
    using abi = ABI::Windows::UI::Core::ICoreKeyboardInputSource2;
    template <typename D> using consume = Windows::UI::Core::impl_ICoreKeyboardInputSource2<D>;
};

template <> struct traits<Windows::UI::Core::ICorePointerInputSource>
{
    using abi = ABI::Windows::UI::Core::ICorePointerInputSource;
    template <typename D> using consume = Windows::UI::Core::impl_ICorePointerInputSource<D>;
};

template <> struct traits<Windows::UI::Core::ICorePointerRedirector>
{
    using abi = ABI::Windows::UI::Core::ICorePointerRedirector;
    template <typename D> using consume = Windows::UI::Core::impl_ICorePointerRedirector<D>;
};

template <> struct traits<Windows::UI::Core::ICoreTouchHitTesting>
{
    using abi = ABI::Windows::UI::Core::ICoreTouchHitTesting;
    template <typename D> using consume = Windows::UI::Core::impl_ICoreTouchHitTesting<D>;
};

template <> struct traits<Windows::UI::Core::ICoreWindow>
{
    using abi = ABI::Windows::UI::Core::ICoreWindow;
    template <typename D> using consume = Windows::UI::Core::impl_ICoreWindow<D>;
};

template <> struct traits<Windows::UI::Core::ICoreWindow2>
{
    using abi = ABI::Windows::UI::Core::ICoreWindow2;
    template <typename D> using consume = Windows::UI::Core::impl_ICoreWindow2<D>;
};

template <> struct traits<Windows::UI::Core::ICoreWindow3>
{
    using abi = ABI::Windows::UI::Core::ICoreWindow3;
    template <typename D> using consume = Windows::UI::Core::impl_ICoreWindow3<D>;
};

template <> struct traits<Windows::UI::Core::ICoreWindowEventArgs>
{
    using abi = ABI::Windows::UI::Core::ICoreWindowEventArgs;
    template <typename D> using consume = Windows::UI::Core::impl_ICoreWindowEventArgs<D>;
};

template <> struct traits<Windows::UI::Core::ICoreWindowResizeManager>
{
    using abi = ABI::Windows::UI::Core::ICoreWindowResizeManager;
    template <typename D> using consume = Windows::UI::Core::impl_ICoreWindowResizeManager<D>;
};

template <> struct traits<Windows::UI::Core::ICoreWindowResizeManagerLayoutCapability>
{
    using abi = ABI::Windows::UI::Core::ICoreWindowResizeManagerLayoutCapability;
    template <typename D> using consume = Windows::UI::Core::impl_ICoreWindowResizeManagerLayoutCapability<D>;
};

template <> struct traits<Windows::UI::Core::ICoreWindowResizeManagerStatics>
{
    using abi = ABI::Windows::UI::Core::ICoreWindowResizeManagerStatics;
    template <typename D> using consume = Windows::UI::Core::impl_ICoreWindowResizeManagerStatics<D>;
};

template <> struct traits<Windows::UI::Core::ICoreWindowStatic>
{
    using abi = ABI::Windows::UI::Core::ICoreWindowStatic;
    template <typename D> using consume = Windows::UI::Core::impl_ICoreWindowStatic<D>;
};

template <> struct traits<Windows::UI::Core::IIdleDispatchedHandlerArgs>
{
    using abi = ABI::Windows::UI::Core::IIdleDispatchedHandlerArgs;
    template <typename D> using consume = Windows::UI::Core::impl_IIdleDispatchedHandlerArgs<D>;
};

template <> struct traits<Windows::UI::Core::IInitializeWithCoreWindow>
{
    using abi = ABI::Windows::UI::Core::IInitializeWithCoreWindow;
    template <typename D> using consume = Windows::UI::Core::impl_IInitializeWithCoreWindow<D>;
};

template <> struct traits<Windows::UI::Core::IInputEnabledEventArgs>
{
    using abi = ABI::Windows::UI::Core::IInputEnabledEventArgs;
    template <typename D> using consume = Windows::UI::Core::impl_IInputEnabledEventArgs<D>;
};

template <> struct traits<Windows::UI::Core::IKeyEventArgs>
{
    using abi = ABI::Windows::UI::Core::IKeyEventArgs;
    template <typename D> using consume = Windows::UI::Core::impl_IKeyEventArgs<D>;
};

template <> struct traits<Windows::UI::Core::IKeyEventArgs2>
{
    using abi = ABI::Windows::UI::Core::IKeyEventArgs2;
    template <typename D> using consume = Windows::UI::Core::impl_IKeyEventArgs2<D>;
};

template <> struct traits<Windows::UI::Core::IPointerEventArgs>
{
    using abi = ABI::Windows::UI::Core::IPointerEventArgs;
    template <typename D> using consume = Windows::UI::Core::impl_IPointerEventArgs<D>;
};

template <> struct traits<Windows::UI::Core::ISystemNavigationManager>
{
    using abi = ABI::Windows::UI::Core::ISystemNavigationManager;
    template <typename D> using consume = Windows::UI::Core::impl_ISystemNavigationManager<D>;
};

template <> struct traits<Windows::UI::Core::ISystemNavigationManager2>
{
    using abi = ABI::Windows::UI::Core::ISystemNavigationManager2;
    template <typename D> using consume = Windows::UI::Core::impl_ISystemNavigationManager2<D>;
};

template <> struct traits<Windows::UI::Core::ISystemNavigationManagerStatics>
{
    using abi = ABI::Windows::UI::Core::ISystemNavigationManagerStatics;
    template <typename D> using consume = Windows::UI::Core::impl_ISystemNavigationManagerStatics<D>;
};

template <> struct traits<Windows::UI::Core::ITouchHitTestingEventArgs>
{
    using abi = ABI::Windows::UI::Core::ITouchHitTestingEventArgs;
    template <typename D> using consume = Windows::UI::Core::impl_ITouchHitTestingEventArgs<D>;
};

template <> struct traits<Windows::UI::Core::IVisibilityChangedEventArgs>
{
    using abi = ABI::Windows::UI::Core::IVisibilityChangedEventArgs;
    template <typename D> using consume = Windows::UI::Core::impl_IVisibilityChangedEventArgs<D>;
};

template <> struct traits<Windows::UI::Core::IWindowActivatedEventArgs>
{
    using abi = ABI::Windows::UI::Core::IWindowActivatedEventArgs;
    template <typename D> using consume = Windows::UI::Core::impl_IWindowActivatedEventArgs<D>;
};

template <> struct traits<Windows::UI::Core::IWindowSizeChangedEventArgs>
{
    using abi = ABI::Windows::UI::Core::IWindowSizeChangedEventArgs;
    template <typename D> using consume = Windows::UI::Core::impl_IWindowSizeChangedEventArgs<D>;
};

template <> struct traits<Windows::UI::Core::IdleDispatchedHandler>
{
    using abi = ABI::Windows::UI::Core::IdleDispatchedHandler;
};

template <> struct traits<Windows::UI::Core::AcceleratorKeyEventArgs>
{
    using abi = ABI::Windows::UI::Core::AcceleratorKeyEventArgs;
    using default_interface = Windows::UI::Core::IAcceleratorKeyEventArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Core.AcceleratorKeyEventArgs"; }
};

template <> struct traits<Windows::UI::Core::AutomationProviderRequestedEventArgs>
{
    using abi = ABI::Windows::UI::Core::AutomationProviderRequestedEventArgs;
    using default_interface = Windows::UI::Core::IAutomationProviderRequestedEventArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Core.AutomationProviderRequestedEventArgs"; }
};

template <> struct traits<Windows::UI::Core::BackRequestedEventArgs>
{
    using abi = ABI::Windows::UI::Core::BackRequestedEventArgs;
    using default_interface = Windows::UI::Core::IBackRequestedEventArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Core.BackRequestedEventArgs"; }
};

template <> struct traits<Windows::UI::Core::CharacterReceivedEventArgs>
{
    using abi = ABI::Windows::UI::Core::CharacterReceivedEventArgs;
    using default_interface = Windows::UI::Core::ICharacterReceivedEventArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Core.CharacterReceivedEventArgs"; }
};

template <> struct traits<Windows::UI::Core::ClosestInteractiveBoundsRequestedEventArgs>
{
    using abi = ABI::Windows::UI::Core::ClosestInteractiveBoundsRequestedEventArgs;
    using default_interface = Windows::UI::Core::IClosestInteractiveBoundsRequestedEventArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Core.ClosestInteractiveBoundsRequestedEventArgs"; }
};

template <> struct traits<Windows::UI::Core::CoreAcceleratorKeys>
{
    using abi = ABI::Windows::UI::Core::CoreAcceleratorKeys;
    using default_interface = Windows::UI::Core::ICoreAcceleratorKeys;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Core.CoreAcceleratorKeys"; }
};

template <> struct traits<Windows::UI::Core::CoreComponentInputSource>
{
    using abi = ABI::Windows::UI::Core::CoreComponentInputSource;
    using default_interface = Windows::UI::Core::ICoreInputSourceBase;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Core.CoreComponentInputSource"; }
};

template <> struct traits<Windows::UI::Core::CoreCursor>
{
    using abi = ABI::Windows::UI::Core::CoreCursor;
    using default_interface = Windows::UI::Core::ICoreCursor;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Core.CoreCursor"; }
};

template <> struct traits<Windows::UI::Core::CoreDispatcher>
{
    using abi = ABI::Windows::UI::Core::CoreDispatcher;
    using default_interface = Windows::UI::Core::ICoreDispatcher;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Core.CoreDispatcher"; }
};

template <> struct traits<Windows::UI::Core::CoreIndependentInputSource>
{
    using abi = ABI::Windows::UI::Core::CoreIndependentInputSource;
    using default_interface = Windows::UI::Core::ICoreInputSourceBase;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Core.CoreIndependentInputSource"; }
};

template <> struct traits<Windows::UI::Core::CoreWindow>
{
    using abi = ABI::Windows::UI::Core::CoreWindow;
    using default_interface = Windows::UI::Core::ICoreWindow;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Core.CoreWindow"; }
};

template <> struct traits<Windows::UI::Core::CoreWindowEventArgs>
{
    using abi = ABI::Windows::UI::Core::CoreWindowEventArgs;
    using default_interface = Windows::UI::Core::ICoreWindowEventArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Core.CoreWindowEventArgs"; }
};

template <> struct traits<Windows::UI::Core::CoreWindowResizeManager>
{
    using abi = ABI::Windows::UI::Core::CoreWindowResizeManager;
    using default_interface = Windows::UI::Core::ICoreWindowResizeManager;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Core.CoreWindowResizeManager"; }
};

template <> struct traits<Windows::UI::Core::IdleDispatchedHandlerArgs>
{
    using abi = ABI::Windows::UI::Core::IdleDispatchedHandlerArgs;
    using default_interface = Windows::UI::Core::IIdleDispatchedHandlerArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Core.IdleDispatchedHandlerArgs"; }
};

template <> struct traits<Windows::UI::Core::InputEnabledEventArgs>
{
    using abi = ABI::Windows::UI::Core::InputEnabledEventArgs;
    using default_interface = Windows::UI::Core::IInputEnabledEventArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Core.InputEnabledEventArgs"; }
};

template <> struct traits<Windows::UI::Core::KeyEventArgs>
{
    using abi = ABI::Windows::UI::Core::KeyEventArgs;
    using default_interface = Windows::UI::Core::IKeyEventArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Core.KeyEventArgs"; }
};

template <> struct traits<Windows::UI::Core::PointerEventArgs>
{
    using abi = ABI::Windows::UI::Core::PointerEventArgs;
    using default_interface = Windows::UI::Core::IPointerEventArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Core.PointerEventArgs"; }
};

template <> struct traits<Windows::UI::Core::SystemNavigationManager>
{
    using abi = ABI::Windows::UI::Core::SystemNavigationManager;
    using default_interface = Windows::UI::Core::ISystemNavigationManager;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Core.SystemNavigationManager"; }
};

template <> struct traits<Windows::UI::Core::TouchHitTestingEventArgs>
{
    using abi = ABI::Windows::UI::Core::TouchHitTestingEventArgs;
    using default_interface = Windows::UI::Core::ITouchHitTestingEventArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Core.TouchHitTestingEventArgs"; }
};

template <> struct traits<Windows::UI::Core::VisibilityChangedEventArgs>
{
    using abi = ABI::Windows::UI::Core::VisibilityChangedEventArgs;
    using default_interface = Windows::UI::Core::IVisibilityChangedEventArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Core.VisibilityChangedEventArgs"; }
};

template <> struct traits<Windows::UI::Core::WindowActivatedEventArgs>
{
    using abi = ABI::Windows::UI::Core::WindowActivatedEventArgs;
    using default_interface = Windows::UI::Core::IWindowActivatedEventArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Core.WindowActivatedEventArgs"; }
};

template <> struct traits<Windows::UI::Core::WindowSizeChangedEventArgs>
{
    using abi = ABI::Windows::UI::Core::WindowSizeChangedEventArgs;
    using default_interface = Windows::UI::Core::IWindowSizeChangedEventArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Core.WindowSizeChangedEventArgs"; }
};

}

}
