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

    inline bool ends_with(std::string_view value, std::string_view match)
    {
        return value.size() >= match.size() &&
               0 == value.compare(value.size() - match.size(), match.size(), match);
    }

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

    inline std::string to_string(std::wstring_view source)
    {
        std::string result(source.size(), '?');

        auto WideCharToMultiByte = [&]
        {
            WINRT_ASSERT(source.size() <= result.size());

            return ::WideCharToMultiByte(
                CP_UTF8,
                0,
                source.data(),
                static_cast<uint32_t>(source.size()),
                result.data(),
                static_cast<uint32_t>(result.size()),
                nullptr,
                nullptr);
        };

        int size = WideCharToMultiByte();

        while (size == 0)
        {
            result.resize(result.size() * 2);
            size = WideCharToMultiByte();
        }

        result.resize(size);
        return result;
    }

    template <typename ... Args>
    void print_error(Args&& ... args)
    {
        fprintf(stderr, std::forward<Args>(args) ...);
    }
}
