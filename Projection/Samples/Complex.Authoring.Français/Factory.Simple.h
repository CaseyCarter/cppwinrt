#pragma once

#include "Factory\Simple.g.h"

namespace winrt::Complex::Authoring::Factory::implementation
{
    struct Simple : SimpleT<Simple>
    {
        Simple() = default;

    };
}

namespace winrt::Complex::Authoring::Factory::factory_implementation
{
    struct Simple : SimpleT<Simple, implementation::Simple>
    {
    };
}
