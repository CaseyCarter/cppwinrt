#include "pch.h"
#include "Root.h"

namespace winrt::Composable::Base::implementation
{
    hstring Root::RootMethod()
    {
        return L"Composable.Base.Root.RootMethod";
    }

    hstring Root::VirtualInternalRootMethod()
    {
        return L"Composable.Base.Root.VirtualInternalRootMethod";
    }

    hstring Root::CallVirtualPublicRootMethod()
    {
        return super().VirtualPublicRootMethod();
    }

    hstring Root::VirtualPublicRootMethod()
    {
        return L"Composable.Base.Root.VirtualPublicRootMethod";
    }
}
