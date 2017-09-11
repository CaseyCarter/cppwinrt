#pragma once

#include "helpers.h"

namespace cppwinrt
{
    static constexpr size_t default_output_capacity{ 16 * 1024 };

    class output
    {
        std::vector<char> m_buffer;

        static constexpr uint32_t count_placeholders(std::string_view format) noexcept
        {
            uint32_t count = 0;

            bool escape = false;
            for (char const c : format)
            {
                if (c == '^')
                {
                    escape = true;
                    continue;
                }
                if ((c == '%' || c == '@') && !escape)
                {
                    ++count;
                }
                escape = false;
            }

            return count;
        }

        void append(std::string_view value) noexcept
        {
            m_buffer.insert(m_buffer.end(), value.begin(), value.end());
        }

        void append(char const value) noexcept
        {
            m_buffer.push_back(value);
        }

        void write_segment(std::string_view value) noexcept
        {
            append(value);
        }

        template <typename First, typename ... Rest>
        void write_segment(std::string_view value, First const& first, Rest const& ... rest)
        {
            size_t offset = value.find_first_of("^%@");
            WINRT_ASSERT(offset != std::string_view::npos);
            append(value.substr(0, offset));

            if (value[offset] == '^')
            {
                char next = value[offset + 1];
                if (next == '%' || next == '@')
                {
                    append(next);
                    offset++;
                }
                else
                {
                    append('^');
                }
                write_segment(value.substr(offset + 1), first, rest ...);
            }
            else
            {
                if (value[offset] == '%')
                {
                    write_arg(first);
                }
                else
                {
                    write_code_arg(first);
                }
                write_segment(value.substr(offset + 1), rest ...);
            }
        }

        template <typename F>
#if _MSC_FULL_VER < 191125325
        auto write_code_arg(F const&)->std::enable_if_t<std::is_callable_v<F(output&)>>
#else
        auto write_code_arg(F const&)->std::enable_if_t<std::is_invocable_v<F, output&>>
#endif
        {
            WINRT_ASSERT(false);
        }

        void write_code_arg(int)
        {
            WINRT_ASSERT(false);
        }

        void write_code_arg(std::string_view value) noexcept
        {
            for (char c : value)
            {
                if (c == '.')
                {
                    append("::");
                }
                else
                {
                    append(c);
                }
            }
        }

        template <typename F>
#if _MSC_FULL_VER < 191125325
        auto write_arg(F const& f)->std::enable_if_t<std::is_callable_v<F(output&)>>
#else
        auto write_arg(F const& f) -> std::enable_if_t<std::is_invocable_v<F, output&>>
#endif
        {
            f(*this);
        }

        void write_arg(std::string_view value) noexcept
        {
            append(value);
        }

        void write_arg(char const value) noexcept
        {
            append(value);
        }

        void write_arg(int32_t const value) noexcept
        {
            append(std::to_string(value));
        }

        void write_arg(uint32_t const value) noexcept
        {
            char buffer[11];
            size_t const size = sprintf_s(buffer, "0x%X", value);
            append({ buffer, size });
        }

        uint32_t size() const noexcept
        {
            return static_cast<uint32_t>(m_buffer.size());
        }

    public:

        output(output const&) = delete;
        output& operator=(output const&) = delete;

        explicit output()
        {
            m_buffer.reserve(default_output_capacity);
        }

        void write_impl_namespace()
        {
            write("\nnamespace winrt::impl {\n");
        }

        void write_std_namespace()
        {
            write("\nWINRT_EXPORT namespace std {\n");
        }

        void write_meta_namespace(std::string_view ns)
        {
            write("\nWINRT_EXPORT namespace winrt::@ {\n", ns);
        }

        void write_component_namespace(std::string_view ns)
        {
            write("\nnamespace winrt::@ {\n", ns);
        }

        void write_close_namespace()
        {
            write("\n}\n");
        }

        void write(std::string_view value)
        {
            append(value);
        }

        void write(char const value)
        {
            append(value);
        }

        template <typename ... Args>
        void write(std::string_view value, Args const& ... args)
        {
            WINRT_ASSERT(count_placeholders(value) == sizeof ... (Args));
            write_segment(value, args ...);
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

            std::array<uint8_t, 3> byte_order_mark{ 0xEF, 0xBB, 0xBF };

            check_win32_bool(WriteFile(file.value,
                byte_order_mark.data(),
                static_cast<uint32_t>(byte_order_mark.size()),
                &copied,
                nullptr));

            WINRT_ASSERT(copied == byte_order_mark.size());

            check_win32_bool(WriteFile(file.value,
                m_buffer.data(),
                size(),
                &copied,
                nullptr));

            WINRT_ASSERT(copied == size());
        }

        void save_as(std::experimental::filesystem::path const& filename)
        {
            save_as(filename.string());
        }
    };

    template <typename F, typename ... Args>
    auto bind_output(F writer, Args const& ... args)
    {
        return [&, writer](output& out)
        {
            writer(out, args ...);
        };
    }
}
