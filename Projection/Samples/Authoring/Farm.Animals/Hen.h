#pragma once

#include "module.h"

#if _MSC_FULL_VER < 191125325
#define WINRT_FORCE_INCLUDE_HEN_X_H
#endif

#include "Hen.g.h"

#ifndef _HEN_X_H_
#error "Hen.x.h was not included"
#endif

namespace winrt::Farm::Animals::implementation
{
    struct Hen : HenT<Hen>
    {
        Hen() = default;

        hstring Name();
        Windows::Foundation::IAsyncOperationWithProgress<hstring, uint32_t> LayEggAsync();
    };

    struct HenFactory : HenFactoryT<HenFactory, Hen>
    {
    };
}
