#pragma once

#include "Factory.StaticFactory.g.h"

namespace winrt::Complex::Authoring::Factory::implementation
{
    struct StaticFactory
    {
        StaticFactory() = delete;

    };
}

namespace winrt::Complex::Authoring::Factory::factory_implementation
{
    struct StaticFactory : StaticFactoryT<StaticFactory, implementation::StaticFactory>
    {
    };
}
