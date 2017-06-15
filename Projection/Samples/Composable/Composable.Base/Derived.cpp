#include "pch.h"
#include "Derived.h"

namespace winrt::Composable::Base::implementation
{
    hstring Derived::DerivedMethod()
    {
        return L"Composable.Base.Derived.DerivedMethod";
    }

    hstring Derived::CallVirtualPublicDerivedMethod()
    {
        return super().VirtualPublicDerivedMethod();
    }

    hstring Derived::VirtualPublicDerivedMethod()
    {
        return L"Composable.Base.Derived.VirtualPublicDerivedMethod";
    }

    hstring Derived::VirtualInternalRootMethod()
    {
        return L"Composable.Base.Derived.VirtualInternalRootMethod";
    }
}
