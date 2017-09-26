#pragma once

#include "Simple.g.h"

namespace winrt::Complex::Authoring::implementation
{
    struct Simple : SimpleT<Simple>
    {
        Simple() = default;

        hstring Name();
    };
}

namespace winrt::Complex::Authoring::factory_implementation
{
    struct Simple : SimpleT<Simple, implementation::Simple>
    {
    };
}
