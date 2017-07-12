#include "pch.h"
#include "Egg.h"

namespace winrt::Farm::Animals::implementation
{
    Egg::Egg(Farm::Animals::Hen const& mother) :
        m_mother(mother)
    {
    }

    Farm::Animals::Hen Egg::Mother()
    {
        return m_mother;
    }
}
