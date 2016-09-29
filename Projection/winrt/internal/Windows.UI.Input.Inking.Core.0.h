// C++ for the Windows Runtime v1.0.private
// Copyright (c) 2016 Microsoft Corporation

#pragma once


WINRT_EXPORT namespace winrt {

namespace ABI::Windows::UI::Input::Inking::Core {

struct ICoreInkIndependentInputSource;
struct ICoreInkIndependentInputSourceStatics;
struct ICoreWetStrokeUpdateEventArgs;
struct ICoreWetStrokeUpdateSource;
struct ICoreWetStrokeUpdateSourceStatics;
struct CoreInkIndependentInputSource;
struct CoreWetStrokeUpdateEventArgs;
struct CoreWetStrokeUpdateSource;

}

namespace Windows::UI::Input::Inking::Core {

struct ICoreInkIndependentInputSource;
struct ICoreInkIndependentInputSourceStatics;
struct ICoreWetStrokeUpdateEventArgs;
struct ICoreWetStrokeUpdateSource;
struct ICoreWetStrokeUpdateSourceStatics;
struct CoreInkIndependentInputSource;
struct CoreWetStrokeUpdateEventArgs;
struct CoreWetStrokeUpdateSource;

}

namespace Windows::UI::Input::Inking::Core {

enum class CoreWetStrokeDisposition
{
    Inking = 0,
    Completed = 1,
    Canceled = 2,
};

}

}
