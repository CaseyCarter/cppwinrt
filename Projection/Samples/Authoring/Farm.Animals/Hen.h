#pragma once

#include "module.h"
#include "Hen.g.h"

namespace winrt::Farm::Animals::implementation
{
    struct Hen : HenT<Hen>
    {
        Hen() = default;

        hstring Français();
        Windows::Foundation::IAsyncOperationWithProgress<Farm::Animals::Egg, uint32_t> LayEggAsync();
        Windows::Foundation::Rect StructByValue(Windows::Foundation::Rect const& byValue);
        Windows::Foundation::Rect StructByRef(Windows::Foundation::Rect const& byRef);
    };

    struct HenFactory : HenFactoryT<HenFactory, Hen>
    {
    };
}
