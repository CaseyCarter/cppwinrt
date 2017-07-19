#pragma once

#include "module.h"
#include "Simple.g.h"

namespace winrt::Complex::Authoring::implementation
{
    struct Simple : SimpleT<Simple>
    {
        Simple() = default;

        hstring Name();
    };

    struct SimpleFactory : SimpleFactoryT<SimpleFactory, Simple>
    {
    };
}
