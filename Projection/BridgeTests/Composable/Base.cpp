#include "pch.h"
#include "Base.h"

namespace winrt::Composable::implementation
{
    hstring Base::VirtualMethod()
    {
        return L"Base::VirtualMethod";
    }

    hstring Base::CallOverridableMethod()
    {
        return super().OverridableMethod();
    }

    hstring Base::CallOverridableVirtualMethod()
    {
        return super().OverridableVirtualMethod();
    }

    hstring Base::OverridableMethod()
    {
        return L"Base::OverridableMethod";
    }

    hstring Base::OverridableVirtualMethod()
    {
        return L"Base::OverridableVirtualMethod";
    }

    hstring Base::Name() const
    {
        return m_name;
    }
}
