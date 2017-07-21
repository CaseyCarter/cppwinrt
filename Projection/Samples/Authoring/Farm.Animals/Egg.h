#pragma once

#include "Egg.g.h"

namespace winrt::Farm::Animals::implementation
{
    struct Egg : EggT<Egg>
    {
        Egg() = delete;
        Egg(Farm::Animals::Hen const& mother);

        Farm::Animals::Hen Mother();

    private:

        Farm::Animals::Hen m_mother{ nullptr };
    };
}

namespace winrt::Farm::Animals::factory_implementation
{
    struct Egg : EggT<Egg, implementation::Egg>
    {
    };
}
