#pragma once

namespace cppwinrt
{
    class file_view
    {
        char const * m_begin{};
        char const * m_end{};

        void open_map(HANDLE file)
        {
            struct handle
            {
                HANDLE value{};

                explicit operator bool() const
                {
                    return value != nullptr;
                }

                ~handle()
                {
                    WINRT_ASSERT(*this);
                    WINRT_VERIFY(CloseHandle(value));
                }
            };

            handle map
            {
                CreateFileMapping(file,
                nullptr, // default security
                PAGE_READONLY,
                0, 0, // entire file
                nullptr) // unnamed
            };

            if (!map)
            {
                winrt::throw_last_error();
            }

            LARGE_INTEGER size = {};

            if (!GetFileSizeEx(file, &size))
            {
                winrt::hresult_invalid_argument();
            }

            m_begin = static_cast<char *>(MapViewOfFile(map.value,
                                                        FILE_MAP_READ,
                                                        0, 0, // offset
                                                        0)); // entire file

            if (!m_begin)
            {
                winrt::throw_last_error();
            }

            m_end = m_begin + size.QuadPart;
        }

        void open_file(wchar_t const * const filename)
        {
            struct handle
            {
                HANDLE value{ INVALID_HANDLE_VALUE };

                explicit operator bool() const
                {
                    return value != INVALID_HANDLE_VALUE;
                }

                ~handle()
                {
                    WINRT_ASSERT(*this);
                    WINRT_VERIFY(CloseHandle(value));
                }
            };

            handle file
            {
                CreateFileW(filename,
                GENERIC_READ,
                FILE_SHARE_READ,
                nullptr, // default security
                OPEN_EXISTING,
                FILE_ATTRIBUTE_NORMAL,
                nullptr) // no template
            };

            if (!file)
            {
                winrt::throw_last_error();
            }

            open_map(file.value);
        }

    public:

        file_view(wchar_t const * const filename)
        {
            open_file(filename);
        }

        char const * begin() const noexcept
        {
            return m_begin;
        }

        char const * end() const noexcept
        {
            return m_end;
        }

        size_t size() const noexcept
        {
            return m_end - m_begin;
        }
    };
}
