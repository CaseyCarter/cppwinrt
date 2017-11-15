#pragma once

#include "Composability\Closed\Base.g.h"

namespace winrt::Complex::Authoring::Composability::Closed::implementation
{
    struct Base : BaseT<Base>
    {
        Base() = delete;

        void MethodOnBase();
    };
}
