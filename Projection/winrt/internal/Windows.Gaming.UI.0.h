// C++ for the Windows Runtime v1.0.private
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once


WINRT_EXPORT namespace winrt {

namespace ABI::Windows::Gaming::UI {

struct IGameBarStatics;
struct IGameChatOverlay;
struct IGameChatOverlayStatics;
struct GameChatOverlay;

}

namespace Windows::Gaming::UI {

struct IGameBarStatics;
struct IGameChatOverlay;
struct IGameChatOverlayStatics;
struct GameBar;
struct GameChatOverlay;

}

namespace Windows::Gaming::UI {

template <typename T> struct impl_IGameBarStatics;
template <typename T> struct impl_IGameChatOverlay;
template <typename T> struct impl_IGameChatOverlayStatics;

}

namespace Windows::Gaming::UI {

enum class GameChatMessageOrigin
{
    Voice = 0,
    Text = 1,
};

enum class GameChatOverlayPosition
{
    BottomCenter = 0,
    BottomLeft = 1,
    BottomRight = 2,
    MiddleRight = 3,
    MiddleLeft = 4,
    TopCenter = 5,
    TopLeft = 6,
    TopRight = 7,
};

}

}
