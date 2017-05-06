#pragma once

#include "module.h"

namespace winrt::Microsoft::SDKSamples::Kitchen::implementation
{
    struct BreadBakedEventArgs : BreadBakedEventArgsT<BreadBakedEventArgs>
    {
        BreadBakedEventArgs() = delete;
        BreadBakedEventArgs(Microsoft::SDKSamples::Kitchen::Bread const& bread);

        Microsoft::SDKSamples::Kitchen::Bread Bread();

    private:
        Microsoft::SDKSamples::Kitchen::Bread _bread{nullptr};
    };

    struct BreadBakedEventArgsFactory : BreadBakedEventArgsFactoryT<BreadBakedEventArgsFactory, BreadBakedEventArgs>
    {
    };
}
