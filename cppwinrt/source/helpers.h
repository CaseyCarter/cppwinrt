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

    inline auto check_handle_null(HANDLE handle)
    {
        if (!handle)
        {
            winrt::throw_last_error();
        }

        return handle;
    }

    template<typename T, size_t N>
    constexpr std::basic_string_view<T> to_string_view(T const (&s)[N]) noexcept
    {
        return std::basic_string_view<T>{ s, N - 1 };
    }

    inline bool starts_with(std::string_view value, std::string_view match)
    {
        return 0 == value.compare(0, match.size(), match);
    }
}
