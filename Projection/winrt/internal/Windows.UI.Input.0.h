// C++ for the Windows Runtime v1.0.private
// Copyright (c) 2016 Microsoft Corporation. All rights reserved.

#pragma once


WINRT_EXPORT namespace winrt {

namespace ABI::Windows::UI::Input {

struct ManipulationDelta;
struct ManipulationVelocities;
struct CrossSlideThresholds;

}

namespace Windows::UI::Input {

using ManipulationDelta = ABI::Windows::UI::Input::ManipulationDelta;
using ManipulationVelocities = ABI::Windows::UI::Input::ManipulationVelocities;
using CrossSlideThresholds = ABI::Windows::UI::Input::CrossSlideThresholds;

}

namespace ABI::Windows::UI::Input {

struct ICrossSlidingEventArgs;
struct IDraggingEventArgs;
struct IEdgeGesture;
struct IEdgeGestureEventArgs;
struct IEdgeGestureStatics;
struct IGestureRecognizer;
struct IHoldingEventArgs;
struct IKeyboardDeliveryInterceptor;
struct IKeyboardDeliveryInterceptorStatics;
struct IManipulationCompletedEventArgs;
struct IManipulationInertiaStartingEventArgs;
struct IManipulationStartedEventArgs;
struct IManipulationUpdatedEventArgs;
struct IMouseWheelParameters;
struct IPointerPoint;
struct IPointerPointProperties;
struct IPointerPointProperties2;
struct IPointerPointStatics;
struct IPointerPointTransform;
struct IPointerVisualizationSettings;
struct IPointerVisualizationSettingsStatics;
struct IRadialController;
struct IRadialControllerButtonClickedEventArgs;
struct IRadialControllerConfiguration;
struct IRadialControllerConfigurationStatics;
struct IRadialControllerControlAcquiredEventArgs;
struct IRadialControllerMenu;
struct IRadialControllerMenuItem;
struct IRadialControllerMenuItemStatics;
struct IRadialControllerRotationChangedEventArgs;
struct IRadialControllerScreenContact;
struct IRadialControllerScreenContactContinuedEventArgs;
struct IRadialControllerScreenContactStartedEventArgs;
struct IRadialControllerStatics;
struct IRightTappedEventArgs;
struct ITappedEventArgs;
struct CrossSlidingEventArgs;
struct DraggingEventArgs;
struct EdgeGesture;
struct EdgeGestureEventArgs;
struct GestureRecognizer;
struct HoldingEventArgs;
struct KeyboardDeliveryInterceptor;
struct ManipulationCompletedEventArgs;
struct ManipulationInertiaStartingEventArgs;
struct ManipulationStartedEventArgs;
struct ManipulationUpdatedEventArgs;
struct MouseWheelParameters;
struct PointerPoint;
struct PointerPointProperties;
struct PointerVisualizationSettings;
struct RadialController;
struct RadialControllerButtonClickedEventArgs;
struct RadialControllerConfiguration;
struct RadialControllerControlAcquiredEventArgs;
struct RadialControllerMenu;
struct RadialControllerMenuItem;
struct RadialControllerRotationChangedEventArgs;
struct RadialControllerScreenContact;
struct RadialControllerScreenContactContinuedEventArgs;
struct RadialControllerScreenContactStartedEventArgs;
struct RightTappedEventArgs;
struct TappedEventArgs;

}

namespace Windows::UI::Input {

struct ICrossSlidingEventArgs;
struct IDraggingEventArgs;
struct IEdgeGesture;
struct IEdgeGestureEventArgs;
struct IEdgeGestureStatics;
struct IGestureRecognizer;
struct IHoldingEventArgs;
struct IKeyboardDeliveryInterceptor;
struct IKeyboardDeliveryInterceptorStatics;
struct IManipulationCompletedEventArgs;
struct IManipulationInertiaStartingEventArgs;
struct IManipulationStartedEventArgs;
struct IManipulationUpdatedEventArgs;
struct IMouseWheelParameters;
struct IPointerPoint;
struct IPointerPointProperties;
struct IPointerPointProperties2;
struct IPointerPointStatics;
struct IPointerPointTransform;
struct IPointerVisualizationSettings;
struct IPointerVisualizationSettingsStatics;
struct IRadialController;
struct IRadialControllerButtonClickedEventArgs;
struct IRadialControllerConfiguration;
struct IRadialControllerConfigurationStatics;
struct IRadialControllerControlAcquiredEventArgs;
struct IRadialControllerMenu;
struct IRadialControllerMenuItem;
struct IRadialControllerMenuItemStatics;
struct IRadialControllerRotationChangedEventArgs;
struct IRadialControllerScreenContact;
struct IRadialControllerScreenContactContinuedEventArgs;
struct IRadialControllerScreenContactStartedEventArgs;
struct IRadialControllerStatics;
struct IRightTappedEventArgs;
struct ITappedEventArgs;
struct CrossSlidingEventArgs;
struct DraggingEventArgs;
struct EdgeGesture;
struct EdgeGestureEventArgs;
struct GestureRecognizer;
struct HoldingEventArgs;
struct KeyboardDeliveryInterceptor;
struct ManipulationCompletedEventArgs;
struct ManipulationInertiaStartingEventArgs;
struct ManipulationStartedEventArgs;
struct ManipulationUpdatedEventArgs;
struct MouseWheelParameters;
struct PointerPoint;
struct PointerPointProperties;
struct PointerVisualizationSettings;
struct RadialController;
struct RadialControllerButtonClickedEventArgs;
struct RadialControllerConfiguration;
struct RadialControllerControlAcquiredEventArgs;
struct RadialControllerMenu;
struct RadialControllerMenuItem;
struct RadialControllerRotationChangedEventArgs;
struct RadialControllerScreenContact;
struct RadialControllerScreenContactContinuedEventArgs;
struct RadialControllerScreenContactStartedEventArgs;
struct RightTappedEventArgs;
struct TappedEventArgs;

}

namespace Windows::UI::Input {

enum class CrossSlidingState
{
    Started = 0,
    Dragging = 1,
    Selecting = 2,
    SelectSpeedBumping = 3,
    SpeedBumping = 4,
    Rearranging = 5,
    Completed = 6,
};

enum class DraggingState
{
    Started = 0,
    Continuing = 1,
    Completed = 2,
};

enum class EdgeGestureKind
{
    Touch = 0,
    Keyboard = 1,
    Mouse = 2,
};

enum class GestureSettings : unsigned
{
    None = 0x0,
    Tap = 0x1,
    DoubleTap = 0x2,
    Hold = 0x4,
    HoldWithMouse = 0x8,
    RightTap = 0x10,
    Drag = 0x20,
    ManipulationTranslateX = 0x40,
    ManipulationTranslateY = 0x80,
    ManipulationTranslateRailsX = 0x100,
    ManipulationTranslateRailsY = 0x200,
    ManipulationRotate = 0x400,
    ManipulationScale = 0x800,
    ManipulationTranslateInertia = 0x1000,
    ManipulationRotateInertia = 0x2000,
    ManipulationScaleInertia = 0x4000,
    CrossSlide = 0x8000,
    ManipulationMultipleFingerPanning = 0x10000,
};

DEFINE_ENUM_FLAG_OPERATORS(GestureSettings)

enum class HoldingState
{
    Started = 0,
    Completed = 1,
    Canceled = 2,
};

enum class PointerUpdateKind
{
    Other = 0,
    LeftButtonPressed = 1,
    LeftButtonReleased = 2,
    RightButtonPressed = 3,
    RightButtonReleased = 4,
    MiddleButtonPressed = 5,
    MiddleButtonReleased = 6,
    XButton1Pressed = 7,
    XButton1Released = 8,
    XButton2Pressed = 9,
    XButton2Released = 10,
};

enum class RadialControllerMenuKnownIcon
{
    Scroll = 0,
    Zoom = 1,
    UndoRedo = 2,
    Volume = 3,
    NextPreviousTrack = 4,
    Ruler = 5,
    InkColor = 6,
    InkThickness = 7,
    PenType = 8,
};

enum class RadialControllerSystemMenuItemKind
{
    Scroll = 0,
    Zoom = 1,
    UndoRedo = 2,
    Volume = 3,
    NextPreviousTrack = 4,
};

}

}
