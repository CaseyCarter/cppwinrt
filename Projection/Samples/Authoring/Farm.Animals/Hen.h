#pragma once

#include "module.h"
#include "Hen.g.h"

namespace winrt::Farm::Animals::implementation
{
    struct Hen : HenT<Hen>
    {
        Hen() = default;

        hstring Name();
        Windows::Foundation::IAsyncOperationWithProgress<Farm::Animals::Egg, uint32_t> LayEggAsync();
    };

    struct HenFactory : HenFactoryT<HenFactory, Hen>
    {
    };
}
