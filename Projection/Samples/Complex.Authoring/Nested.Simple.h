#pragma once

#include "module.h"
#include "Nested.Simple.g.h"

namespace winrt::Complex::Authoring::Nested::implementation
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
