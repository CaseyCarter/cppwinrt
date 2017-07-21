#pragma once

#include "Hen.g.h"

namespace winrt::Farm::Animals::implementation
{
    struct Hen : HenT<Hen>
    {
        Hen() = default;

        hstring Name();
        Windows::Foundation::IAsyncOperationWithProgress<Farm::Animals::Egg, uint32_t> LayEggAsync();
    };
}

namespace winrt::Farm::Animals::factory_implementation
{
    struct Hen : HenT<Hen, implementation::Hen>
    {
    };
}
