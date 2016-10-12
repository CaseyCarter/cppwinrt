#pragma once

namespace Modern {

class Arguments
{
    char ** m_begin;
    char ** m_end;

public:

    Arguments(int argc, char ** argv) noexcept :
        m_begin(argv),
        m_end(argv + argc)
    {}

    char ** begin() const noexcept
    {
        return m_begin;
    }

    char ** end() const noexcept
    {
        return m_end;
    }
};

}
