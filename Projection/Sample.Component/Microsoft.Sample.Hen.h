#pragma once

#include "Microsoft.Sample.h"

namespace winrt::Microsoft::Sample {

struct HenInstance : HenT<HenInstance>
{
    hstring ToString();
};

struct HenFactory : HenFactoryT<HenFactory, HenInstance>
{
};

}
