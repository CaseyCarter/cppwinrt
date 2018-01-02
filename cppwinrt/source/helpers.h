#pragma once

#include <cstdio>

namespace cppwinrt
{
    struct invalid_usage
    {
        std::wstring message = L"Invalid usage";
        std::wstring arg = L"";
        HRESULT code = E_INVALIDARG;
    };

    template<typename T>
    void unreferenced_parameter(T const&)
    {
    }

    inline bool starts_with(std::string_view value, std::string_view match)
    {
        return 0 == value.compare(0, match.size(), match);
    }

    inline bool ends_with(std::string_view value, std::string_view match)
    {
        return value.size() >= match.size() &&
               0 == value.compare(value.size() - match.size(), match.size(), match);
    }

    template <typename First, typename... Rest>
    generator<First> get_values(First const& first, Rest const&... rest)
    {
        int ignored[] = { (co_yield first, 0), (co_yield rest, 0)... }; ignored;
    }

    template <typename First, typename... Rest, typename Value = First::value_type>
    generator<Value> get_container_values(First const& first, Rest const&... rest)
    {
        for (First const& current : get_values(first, rest...))
        {
            for (Value const& value : current)
            {
                co_yield value;
            }
        }
    }

    template <typename... Args>
    void print_error(Args&&... args)
    {
        fprintf(stderr, std::forward<Args>(args)...);
    }
}
