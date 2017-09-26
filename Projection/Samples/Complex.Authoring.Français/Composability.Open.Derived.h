#pragma once

#include "Composability.Open.Derived.g.h"

namespace winrt::Complex::Authoring::Composability::Open::implementation
{
    struct Derived : DerivedT<Derived>
    {
        Derived() = default;

        void MethodOnDerived();
    };
}

namespace winrt::Complex::Authoring::Composability::Open::factory_implementation
{
    struct Derived : DerivedT<Derived, implementation::Derived>
    {
    };
}
