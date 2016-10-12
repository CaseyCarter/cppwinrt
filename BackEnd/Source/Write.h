#pragma once

namespace Modern::Internal {

template <char Placeholder, typename Target>
void Write(Target & target, char const * const value, size_t const size)
{
    Append(target, value, size);
}

template <char Placeholder, typename Target, typename First, typename ... Rest>
void Write(Target & target, char const * const value, size_t const size, First const & first, Rest const & ... rest)
{
    size_t placeholder = 0;

    while (value[placeholder] != Placeholder)
    {
        ++placeholder;
    }

    MODERN_ASSERT(value[placeholder] == Placeholder);
    Append(target, value, placeholder);
    WriteArgument(target, first);
    Write<Placeholder>(target, value + placeholder + 1, size - placeholder - 1, rest ...);
}

template <char Placeholder>
unsigned CountPlaceholders(char const * format)
{
    unsigned count = 0;

    for (; *format != '\0'; ++format)
    {
        count += *format == Placeholder;
    }

    return count;
}

}

namespace Modern {

//
// Targets
//

inline void Append(std::string & target, char const * value, size_t const size)
{
    target.append(value, size);
}

template <unsigned Count, typename ... Args>
void AppendFormat(std::string & target, char const (&format)[Count], Args ... args)
{
    int const back = static_cast<int>(target.size());

    int const size = snprintf(nullptr, 0, format, args ...);

    target.resize(back + size);

    snprintf(&target[back], size + 1, format, args ...);
}

template <typename P>
void Append(P target, char const * const value, size_t const size)
{
    target("%.*s", size, value);
}

template <typename P, unsigned Count, typename ... Args>
void AppendFormat(P target, char const (&format)[Count], Args ... args)
{
    target(format, args ...);
}

inline void Append(FILE * target, char const * const value, size_t const size)
{
    fprintf(target, "%.*s", static_cast<int>(size), value);
}

template <unsigned Count, typename ... Args>
void AppendFormat(FILE * target, char const (&format)[Count], Args ... args)
{
    fprintf(target, format, args ...);
}

//
// Arguments
//

template <typename Target, typename Arg>
void WriteArgument(Target & target, Arg value)
{
    value(target);
}

template <typename Target>
void WriteArgument(Target & target, char const * const value)
{
    AppendFormat(target, "%s", value);
}

template <typename Target>
void WriteArgument(Target & target, int const value)
{
    AppendFormat(target, "%d", value);
}

template <typename Target>
void WriteArgument(Target & target, unsigned const value)
{
    AppendFormat(target, "%u", value);
}

template <typename Target>
void WriteArgument(Target & target, unsigned long long const value)
{
    AppendFormat(target, "%u", value);
}

template <typename Target>
void WriteArgument(Target & target, float const value)
{
    AppendFormat(target, "%.2f", value);
}

template <typename Target>
void WriteArgument(Target & target, HRESULT const value)
{
    AppendFormat(target, "0x%X", value);
}

template <typename Target>
void WriteArgument(Target & target, std::string const & value)
{
    Append(target, value.c_str(), value.size());
}

template <typename Target>
void WriteArgument(Target & target, std::wstring const & value)
{
    AppendFormat(target, "%.*ls", value.size(), value.c_str());
}

//
// Driver
//

template <typename Target>
void Write(Target & target, std::string const & text)
{
    Internal::Write<'%'>(target, text.c_str(), text.size());
}

template <typename Target, unsigned Count>
void Write(Target & target, char const (&text)[Count])
{
    Internal::Write<'%'>(target, text, Count - 1);
}

template <char Placeholder = '%', typename Target, unsigned Count, typename ... Args>
void Write(Target & target, char const (&format)[Count], Args const & ... args)
{
    MODERN_ASSERT(Internal::CountPlaceholders<Placeholder>(format) == sizeof ... (args));
    Internal::Write<Placeholder>(target, format, Count - 1, args ...);
}

template <typename F, typename ... Args>
auto Bind(F call, Args && ... args)
{
    return std::bind(call, std::placeholders::_1, std::forward<Args>(args) ...);
}

}
