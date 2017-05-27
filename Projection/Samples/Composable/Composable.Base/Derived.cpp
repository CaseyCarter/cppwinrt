#include "pch.h"
#include "Derived.h"

namespace winrt::Composable::Base::implementation
{
    hstring Derived::DerivedMethod()
    {
        throw hresult_not_implemented();
    }

    hstring Derived::CallVirtualPublicDerivedMethod()
    {
        throw hresult_not_implemented();
    }

    hstring Derived::VirtualPublicDerivedMethod()
    {
        throw hresult_not_implemented();
    }
}
