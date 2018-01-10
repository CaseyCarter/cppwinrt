#pragma once

#include "CustomBase.g.h"

namespace winrt::Component::implementation
{
    struct CustomBase : CustomBaseT<CustomBase>
    {
        CustomBase()
            : base_type(L"CustomBase")
        {}

        virtual hstring CustomVirtualMethod();
    };
}

namespace winrt::Component::factory_implementation
{
    struct CustomBase : CustomBaseT<CustomBase, implementation::CustomBase>
    {
    };
}
