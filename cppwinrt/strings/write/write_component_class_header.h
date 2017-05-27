#pragma once

#include "module.h"
#include "%.g.h"

namespace winrt::@::implementation
{
    struct % : %T<%@>
    {
%    };

    struct %Factory : %FactoryT<%Factory, %>
    {
    };
}
