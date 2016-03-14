#pragma once

#include <string>

namespace Modern {

inline std::wstring Format(DWORD const result,
                           HMODULE module = nullptr)
{
    PWSTR buffer = nullptr;
    std::wstring message;

    DWORD flags = FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_IGNORE_INSERTS;

    if (module)
    {
        flags |= FORMAT_MESSAGE_FROM_HMODULE;
    }

    if (FormatMessageW(flags,
                       module,
                       result,
                       MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),
                       reinterpret_cast<PWSTR>(&buffer),
                       0, // size
                       nullptr)) // args
    {
        message = buffer;
        LocalFree(buffer);

        while (!message.empty() && iswspace(message.back()))
        {
            message.resize(message.size() - 1);
        }
    }

    return message;
};

}
