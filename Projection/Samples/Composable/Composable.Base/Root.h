#pragma once

#include "Root.g.h"

namespace winrt::Composable::Base::implementation
{
    struct Root : RootT<Root>
    {
        Root() = default;

        hstring RootMethod();
        virtual hstring VirtualInternalRootMethod();
        hstring CallVirtualPublicRootMethod();
        hstring VirtualPublicRootMethod();
    };
}

namespace winrt::Composable::Base::factory_implementation
{
    struct Root : RootT<Root, implementation::Root>
    {
    };
}
