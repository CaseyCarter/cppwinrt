#pragma once

#include "module.h"
#include "Derived.g.h"
#include "Root.h"

namespace winrt::Composable::Base::implementation
{
    struct Derived : DerivedT<Derived, Composable::Base::implementation::Root>
    {
        Derived() = default;

        hstring DerivedMethod();
        hstring CallVirtualPublicDerivedMethod();
        hstring VirtualPublicDerivedMethod();
    };

    struct DerivedFactory : DerivedFactoryT<DerivedFactory, Derived>
    {
    };
}
