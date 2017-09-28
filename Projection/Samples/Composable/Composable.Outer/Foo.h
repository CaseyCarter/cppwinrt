#pragma once

#include "Foo.g.h"

namespace winrt::Composable::Outer::implementation
{
    struct Foo : FooT<Foo>
    {
        Foo() = default;

        hstring FooMethod();

        void TestRequired() const;
    };
}

namespace winrt::Composable::Outer::factory_implementation
{
    struct Foo : FooT<Foo, implementation::Foo>
    {
    };
}
