#include "pch.h"
#include "Foo.h"

namespace winrt::Composable::Outer::implementation
{
    hstring Foo::FooMethod()
    {
        throw hresult_not_implemented();
    }
}
