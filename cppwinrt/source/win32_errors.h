#pragma once

namespace cppwinrt
{
    template<typename T>
    __forceinline void check_win32_bool(T result)
    {
        if (!result)
        {
            winrt::throw_last_error();
        }
    }

    __forceinline auto check_handle_invalid(HANDLE handle)
    {
        if (handle == INVALID_HANDLE_VALUE)
        {
            winrt::throw_last_error();
        }

        return handle;
    }

    __forceinline auto check_handle_null(HANDLE handle)
    {
        if (!handle)
        {
            winrt::throw_last_error();
        }

        return handle;
    }
}
