#pragma once

#include "StructByRef.g.h"

namespace winrt::Complex::Authoring::implementation
{
    struct StructByRef : StructByRefT<StructByRef>
    {
        StructByRef() = default;

        Windows::Foundation::Rect CopyByValue(Windows::Foundation::Rect const& byValue);
        Windows::Foundation::Rect CopyByRef(Windows::Foundation::Rect const& byRef);
    };
}

namespace winrt::Complex::Authoring::factory_implementation
{
    struct StructByRef : StructByRefT<StructByRef, implementation::StructByRef>
    {
    };
}
