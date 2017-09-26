#pragma once

#include "Static.g.h"

namespace winrt::Complex::Authoring::implementation
{
    struct Static
    {
        Static() = delete;

        static Windows::Foundation::Rect Bounds();
    };
}

namespace winrt::Complex::Authoring::factory_implementation
{
    struct Static : StaticT<Static, implementation::Static>
    {
    };
}
