#pragma once

#include "module.h"
#include "StructByRef.g.h"

namespace winrt::Complex::Authoring::implementation
{
    struct StructByRef : StructByRefT<StructByRef>
    {
        StructByRef() = default;

        Windows::Foundation::Rect CopyByValue(Windows::Foundation::Rect const& byValue);
        Windows::Foundation::Rect CopyByRef(Windows::Foundation::Rect const& byRef);
    };

    struct StructByRefFactory : StructByRefFactoryT<StructByRefFactory, StructByRef>
    {
    };
}
