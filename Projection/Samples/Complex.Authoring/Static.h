#pragma once

#include "module.h"
#include "Static.g.h"

namespace winrt::Complex::Authoring::implementation
{
    struct Static
    {
        Static() = delete;

        static Windows::Foundation::Rect Bounds();
    };

    struct StaticFactory : StaticFactoryT<StaticFactory, Static>
    {
    };
}
