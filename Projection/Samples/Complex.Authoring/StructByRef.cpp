#include "pch.h"
#include "StructByRef.h"

namespace winrt::Complex::Authoring::implementation
{
    Windows::Foundation::Rect StructByRef::CopyByValue(Windows::Foundation::Rect const& byValue)
    {
        throw hresult_not_implemented();
    }

    Windows::Foundation::Rect StructByRef::CopyByRef(Windows::Foundation::Rect const& byRef)
    {
        throw hresult_not_implemented();
    }
}
