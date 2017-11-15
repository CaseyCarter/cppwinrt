#pragma once

#include "Composability\Closed\Derived.g.h"

namespace winrt::Complex::Authoring::Composability::Closed::implementation
{
    struct Derived : DerivedT<Derived>
    {
        Derived() = delete;

        void MethodOnDerived();
    };
}
