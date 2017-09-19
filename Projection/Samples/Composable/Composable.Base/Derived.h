#pragma once

#include "Derived.g.h"
#include "Root.h"

namespace winrt::Composable::Base::implementation
{
    struct Derived : DerivedT<Derived>
    {
        Derived() = default;
        explicit Derived(winrt::hstring const&) {}

        hstring DerivedMethod();
        hstring CallVirtualPublicDerivedMethod();
        hstring VirtualPublicDerivedMethod();
        hstring VirtualInternalRootMethod() override;
    };
}

namespace winrt::Composable::Base::factory_implementation
{
    struct Derived : DerivedT<Derived, implementation::Derived>
    {
    };
}
