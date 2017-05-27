#pragma once

#include "module.h"
#include "Root.g.h"

namespace winrt::Composable::Base::implementation
{
    struct Root : RootT<Root>
    {
        Root() = default;

        hstring RootMethod();
        hstring VirtualInternalRootMethod();
        hstring CallVirtualPublicRootMethod();
        hstring VirtualPublicRootMethod();
    };

    struct RootFactory : RootFactoryT<RootFactory, Root>
    {
    };
}
