#include "pch.h"
#include "Bread.h"

namespace winrt::Microsoft::SDKSamples::Kitchen::implementation
{
    Bread::Bread(hstring const& flavor)
        : _flavor(flavor)
    {
    }

    hstring Bread::Flavor()
    {
        return _flavor;
    }
}
