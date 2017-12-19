#pragma once

#include "Composability/Closed/Derived.g.h"
#include "Composability.Closed.Base.h"

namespace winrt::Complex::Authoring::Composability::Closed::implementation
{
    struct Derived : DerivedT<Derived, Complex::Authoring::Composability::Closed::implementation::Base>
    {
        Derived() = delete;

        void MethodOnDerived();
    };
}
