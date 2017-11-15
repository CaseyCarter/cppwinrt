#pragma once

#include "Nested\Simple.g.h"

namespace winrt::Complex::Authoring::Nested::implementation
{
    struct Simple : SimpleT<Simple>
    {
        Simple() = default;

        hstring Name();
    };
}

namespace winrt::Complex::Authoring::Nested::factory_implementation
{
    struct Simple : SimpleT<Simple, implementation::Simple>
    {
    };
}
