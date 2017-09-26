#pragma once

#include "Structs.g.h"

namespace winrt::Complex::Authoring::implementation
{
    struct Structs : StructsT<Structs>
    {
        Structs() = default;

        Windows::Foundation::Rect CopyByValue(Windows::Foundation::Rect const& byValue);
        Windows::Foundation::Rect CopyByRef(Windows::Foundation::Rect const& byRef);
        Complex::Authoring::ComplexStruct PassComplex(Complex::Authoring::ComplexStruct const& complex);
    };
}

namespace winrt::Complex::Authoring::factory_implementation
{
    struct Structs : StructsT<Structs, implementation::Structs>
    {
    };
}
