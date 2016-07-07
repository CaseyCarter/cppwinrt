#pragma once

#include "Microsoft.Sample.h"

namespace winrt { namespace Microsoft { namespace Sample {

struct HenInstance : HenT<HenInstance>
{
    hstring ToString();
};

struct HenFactory : HenFactoryT<HenFactory, HenInstance>
{
};

}}}
