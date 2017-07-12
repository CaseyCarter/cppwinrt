#pragma once

#include "module.h"
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

    struct EggFactory : EggFactoryT<EggFactory, Egg>
    {
    };
}
