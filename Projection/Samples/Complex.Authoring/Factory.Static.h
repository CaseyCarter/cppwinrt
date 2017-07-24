﻿#pragma once

#include "Factory.Static.g.h"

namespace winrt::Complex::Authoring::Factory::implementation
{
    struct Static
    {
        Static() = delete;

    };
}

namespace winrt::Complex::Authoring::Factory::factory_implementation
{
    struct Static : StaticT<Static, implementation::Static>
    {
    };
}