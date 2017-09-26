#pragma once

#include "Factory.SimpleFactory.g.h"

namespace winrt::Complex::Authoring::Factory::implementation
{
    struct SimpleFactory : SimpleFactoryT<SimpleFactory>
    {
        SimpleFactory() = default;

    };
}

namespace winrt::Complex::Authoring::Factory::factory_implementation
{
    struct SimpleFactory : SimpleFactoryT<SimpleFactory, implementation::SimpleFactory>
    {
    };
}
