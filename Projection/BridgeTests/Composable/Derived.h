#pragma once

#include "Derived.g.h"

namespace winrt::Composable::implementation
{
    struct Derived : DerivedT<Derived>
    {
        Derived() = default;
        explicit Derived(const hstring& name)
            : base_type(name)
        {}

        hstring VirtualMethod() override;
        hstring OverridableVirtualMethod() override;
    };
}

namespace winrt::Composable::factory_implementation
{
    struct Derived : DerivedT<Derived, implementation::Derived>
    {
    };
}
