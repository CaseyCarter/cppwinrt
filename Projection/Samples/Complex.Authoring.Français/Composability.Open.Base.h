#pragma once

#include "Composability\Open\Base.g.h"

namespace winrt::Complex::Authoring::Composability::Open::implementation
{
    struct Base : BaseT<Base>
    {
        Base() = default;

        void MethodOnBase();
    };
}

namespace winrt::Complex::Authoring::Composability::Open::factory_implementation
{
    struct Base : BaseT<Base, implementation::Base>
    {
    };
}
