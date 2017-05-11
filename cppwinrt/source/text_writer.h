#pragma once

#include "helpers.h"

namespace cppwinrt
{
    static constexpr size_t default_output_capacity{ 48 * 1024 * 1000 };

    class output
    {
        size_t m_output_capacity;
        char* m_begin{};
        char* m_position{};
        std::string m_namespace;

        static constexpr uint32_t count_placeholders(char const* format) noexcept
        {
            uint32_t count = 0;

            for (; *format != '\0'; ++format)
            {
                count += *format == '%';
            }

            return count;
        }

        void append(char const* const value, size_t const count) noexcept
        {
            memcpy(m_position, value, count);
            m_position += count;
            assert(size() <= m_output_capacity);
        }

        template <typename ... Args>
        void append_format(char const* const format, Args ... args) noexcept
        {
            m_position += sprintf_s(m_position, available(), format, args ...);
            assert(size() <= m_output_capacity);
        }

        void write_segment(char const* const value, size_t const count) noexcept
        {
            append(value, count);
        }

        template <typename First, typename ... Rest>
        void write_segment(char const* const value, size_t const count, First const& first, Rest const& ... rest)
        {
            size_t placeholder = 0;

            while (value[placeholder] != '%')
            {
                ++placeholder;
            }

            assert(value[placeholder] == '%');
            append(value, placeholder);
            write_arg(first);
            write_segment(value + placeholder + 1, count - placeholder - 1, rest ...);
        }

        template <typename Arg>
        void write_arg(Arg const& value) // Used with bind_output
        {
            value(*this);
        }

        void write_arg(char const* const value) noexcept
        {
            append(value, strlen(value));
        }

        void write_arg(std::string const& value) noexcept
        {
            append(value.c_str(), value.size());
        }

        void write_arg(std::string_view value) noexcept
        {
            append_format("%.*s", value.size(), value.data());
        }

        void write_arg(int32_t const value) noexcept
        {
            append_format("%d", value);
        }

        void write_arg(uint32_t const value) noexcept
        {
            append_format("0x%X", value);
        }

        void write_arg(char const value) noexcept
        {
            append_format("%hc", value);
        }

        void write_arg(wchar_t const value) noexcept
        {
            append_format("%lc", value);
        }

    public:

        output(output const&) = delete;
        output& operator=(output const&) = delete;

        output(size_t output_capacity = default_output_capacity) :
            m_output_capacity(output_capacity),
            m_begin(static_cast<char*>(malloc(m_output_capacity))),
            m_position(m_begin)
        {
            if (m_begin == nullptr)
            {
                throw std::bad_alloc();
            }
        }

        ~output() noexcept
        {
            free(m_begin);
        }

        uint32_t size() const noexcept
        {
            return static_cast<uint32_t>(m_position - m_begin);
        }

        uint32_t available() const noexcept
        {
            return static_cast<uint32_t>(m_output_capacity - size());
        }

        bool write_namespace(std::string const& ns = {})
        {
            if (m_namespace == ns)
            {
                return false;
            }

            if (!m_namespace.empty())
            {
                write("\n}\n");
            }

            m_namespace = ns;

            if (!m_namespace.empty())
            {
                write("\nnamespace ");

                for (char const c : m_namespace)
                {
                    if (c == '.')
                    {
                        write("::");
                    }
                    else
                    {
                        write(c);
                    }
                }

                write(" {\n");
            }

            return true;
        }

        void write(char const* const value)
        {
            append(value, strlen(value));
        }

        void write(std::string_view value)
        {
            append(value.data(), value.size());
        }

        void write(std::wstring_view value)
        {
            m_position += WideCharToMultiByte(CP_UTF8, 0, value.data(), static_cast<uint32_t>(value.size()), m_position, available(), nullptr, nullptr);
            assert(size() <= m_output_capacity);
        }

        void write(wchar_t const value)
        {
            m_position += WideCharToMultiByte(CP_UTF8, 0, &value, 1, m_position, available(), nullptr, nullptr);
            assert(size() <= m_output_capacity);
        }

        template <typename ... Args>
        void write(char const* const value, Args const& ... args)
        {
            WINRT_ASSERT(count_placeholders(value) == sizeof ... (Args));
            write_segment(value, strlen(value), args ...);
        }

        void save_as(std::string const& filename)
        {
            struct handle
            {
                HANDLE value;

                ~handle()
                {
                    WINRT_VERIFY(CloseHandle(value));
                }
            };

            handle file
            {
                check_handle_invalid(CreateFileA(filename.c_str(),
                GENERIC_WRITE,
                FILE_SHARE_READ,
                nullptr, // default security
                CREATE_ALWAYS,
                FILE_ATTRIBUTE_NORMAL,
                nullptr)) // no template
            };

            DWORD copied = 0;

            check_win32_bool(WriteFile(file.value,
                m_begin,
                static_cast<uint32_t>(size()),
                &copied,
                nullptr));

            WINRT_ASSERT(copied == size());
        }
    };

    template <typename F, typename ... Args>
    auto bind_output(F call, Args&& ... args)
    {
        return std::bind(call, std::placeholders::_1, std::forward<Args>(args) ...);
    }
}
