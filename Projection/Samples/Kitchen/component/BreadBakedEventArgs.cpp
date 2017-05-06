#include "pch.h"
#include "BreadBakedEventArgs.h"

using namespace winrt;
using namespace Microsoft::SDKSamples::Kitchen;

namespace winrt::Microsoft::SDKSamples::Kitchen::implementation
{
    BreadBakedEventArgs::BreadBakedEventArgs(Kitchen::Bread const& bread) 
        : _bread(bread) 
    {
    }

    Bread BreadBakedEventArgs::Bread()
    {
        return _bread;
    }
}
