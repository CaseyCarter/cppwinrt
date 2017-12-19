#pragma once

#include "Composability/Open/Derived.g.h"
#include "Composability.Open.Base.h"

namespace winrt::Complex::Authoring::Composability::Open::implementation
{
    struct Derived : DerivedT<Derived, Complex::Authoring::Composability::Open::implementation::Base>
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
