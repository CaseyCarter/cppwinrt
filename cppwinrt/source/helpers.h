#pragma once

namespace cppwinrt
{
    template<typename T>
    void check_win32_bool(T result)
    {
        if (!result)
        {
            winrt::throw_last_error();
        }
    }

    inline auto check_handle_invalid(HANDLE handle)
    {
        if (handle == INVALID_HANDLE_VALUE)
        {
            winrt::throw_last_error();
        }

        return handle;
    }

    inline bool starts_with(std::string_view value, std::string_view match)
    {
        return 0 == value.compare(0, match.size(), match);
    }

    template <typename T>
    using generator = std::experimental::generator<T>;

    template <typename First, typename ... Rest>
    generator<First> get_values(First const& first, Rest const& ... rest)
    {
        int ignored[] = { (co_yield first, 0), (co_yield rest, 0) ... }; ignored;
    }

    template <typename First, typename ... Rest, typename Value = First::value_type>
    generator<Value> get_container_values(First const& first, Rest const& ... rest)
    {
        for (First const& current : get_values(first, rest ...))
        {
            for (Value const& value : current)
            {
                co_yield value;
            }
        }
    }
}
