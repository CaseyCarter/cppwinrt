// C++ for the Windows Runtime v1.29
// Copyright (c) 2016 Microsoft Corporation

#pragma once

#include "Windows.Foundation.Collections.2.h"

WINRT_EXPORT namespace winrt {

namespace Windows::Foundation::Collections {

struct WINRT_EBO PropertySet :
    Windows::Foundation::Collections::IPropertySet
{
    PropertySet(std::nullptr_t) noexcept {}
    PropertySet();
};

struct WINRT_EBO StringMap :
    Windows::Foundation::Collections::IMap<hstring, hstring>
{
    StringMap(std::nullptr_t) noexcept {}
    StringMap();
};

struct WINRT_EBO ValueSet :
    Windows::Foundation::Collections::IPropertySet
{
    ValueSet(std::nullptr_t) noexcept {}
    ValueSet();
};

}

}