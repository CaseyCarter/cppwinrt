#pragma once

#include "module.h"

namespace winrt::Microsoft::SDKSamples::Kitchen::implementation
{
    struct Bread : BreadT<Bread>
    {
        Bread() = delete;
        Bread(hstring const& flavor);

        hstring Flavor();

    private:
        hstring _flavor{};
    };

    struct BreadFactory : BreadFactoryT<BreadFactory, Bread>
    {
    };
}
