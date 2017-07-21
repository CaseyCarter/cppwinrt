#pragma once

#include "%.g.h"

namespace winrt::@::implementation
{
    struct % : %T<%@>
    {
%    };
}

namespace winrt::@::factory_implementation
{
    struct % : %T<%, implementation::%>
    {
    };
}
