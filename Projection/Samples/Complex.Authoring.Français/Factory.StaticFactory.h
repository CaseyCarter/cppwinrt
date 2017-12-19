#pragma once

#include "Factory/StaticFactory.g.h"

namespace winrt::Complex::Authoring::Factory::implementation
{
    struct StaticFactory
    {
        StaticFactory() = delete;

        static void StaticMethod();
    };
}

namespace winrt::Complex::Authoring::Factory::factory_implementation
{
    struct StaticFactory : StaticFactoryT<StaticFactory, implementation::StaticFactory>
    {
    };
}
