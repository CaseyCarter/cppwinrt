#pragma once

#include "handle.h"
#include "FileView.h"
#include "ThrowWindowsError.h"
#include "Write.h"

namespace Modern {

    size_t const OutputCapacity = 32 * 1024 * 1000;

    inline void OptimizeDebugOutput()
    {
#ifdef _DEBUG
        _CrtSetDebugFillThreshold(0);
#endif
    }

    class OutputFile
    {
        Handle<InvalidHandleTraits> m_file;

    public:

        OutputFile(char const * const filename) :
            m_file(CreateFileA(filename,
                               GENERIC_WRITE,
                               FILE_SHARE_READ,
                               nullptr, // default security
                               CREATE_ALWAYS,
                               FILE_ATTRIBUTE_NORMAL,
                               nullptr)) // no template
        {
            if (!m_file)
            {
                ThrowWindowsError();
            }
        }

        void Append(char const * value, size_t const size)
        {
            DWORD copied = 0;

            if (!WriteFile(get(m_file),
                           value,
                           static_cast<DWORD>(size),
                           &copied,
                           nullptr))
            {
                ThrowWindowsError();
            }

            MODERN_ASSERT(copied == static_cast<DWORD>(size));
        }
    };

    inline void Append(OutputFile & target, char const * value, size_t const size)
    {
        target.Append(value, size);
    }

    template <unsigned Count, typename ... Args>
    void AppendFormat(OutputFile & target, char const (&format)[Count], Args ... args)
    {
        std::string temp;
        AppendFormat(temp, format, args ...);
        Append(target, temp.c_str(), temp.size());
    }

    struct Substring
    {
        std::string const & String;
        size_t const Length;

        Substring(std::string const & string, size_t const length) :
            String(string),
            Length(length)
        {}

        Substring(Substring const &) = delete;
        Substring & operator=(Substring const &) = delete;
    };

    template <typename Target>
    void WriteArgument(Target & target, Substring const & value)
    {
        MODERN_ASSERT(value.Length <= value.String.size());

        Append(target, value.String.c_str(), value.Length);
    }

    struct Offset
    {
        std::string const & String;
        size_t const Begin;

        Offset(std::string const & string, size_t const begin) :
            String(string),
            Begin(begin)
        {}

        Offset(Offset const &) = delete;
        Offset & operator=(Offset const &) = delete;
    };

    template <typename Target>
    void WriteArgument(Target & target, Offset const & value)
    {
        MODERN_ASSERT(value.Begin <= value.String.size());

        Append(target, value.String.c_str() + value.Begin, value.String.size() - value.Begin);
    }

    class Output
    {
        char * m_begin = nullptr;
        char * m_position = nullptr;
        std::string m_namespace;
        bool m_abi = false;

    public:

        Output(Output const &) = delete;
        Output & operator=(Output const &) = delete;

        Output() noexcept :
        m_begin(static_cast<char *>(malloc(OutputCapacity))),
            m_position(m_begin)
        {}

        ~Output() noexcept
        {
            free(m_begin);
        }

        char const * Begin() const noexcept
        {
            return m_begin;
        }

        size_t Size() const noexcept
        {
            return m_position - m_begin;
        }

        size_t Available() const noexcept
        {
            return OutputCapacity - Size();
        }

        void Append(char const * value)
        {
            for (; *value; ++value, ++m_position)
            {
                *m_position = *value;
            }

            MODERN_ASSERT(Size() <= OutputCapacity);
        }

        void Append(char const * value, size_t const size)
        {
            memcpy(m_position, value, size);
            m_position += size;
            MODERN_ASSERT(Size() <= OutputCapacity);
        }

        template <unsigned Count, typename ... Args>
        void AppendFormat(char const (&format)[Count], Args ... args)
        {
            m_position += sprintf_s(m_position, Available(), format, args ...);
            MODERN_ASSERT(Size() <= OutputCapacity);
        }

        void WriteTo(char const * filename)
        {
            OutputFile file(filename);
            file.Append(Begin(), Size());
        }

        bool WriteNamespace(std::string const & ns = {})
        {
            if (m_namespace == ns && !m_abi)
            {
                return false;
            }

            m_abi = false;

            if (!m_namespace.empty())
            {
                Write(*this, "\r\n}\r\n");
            }

            m_namespace = ns;

            if (!m_namespace.empty())
            {
                Write(*this, "\r\nnamespace % {\r\n", m_namespace);
            }

            return true;
        }

        bool WriteAbiNamespace(std::string const & ns)
        {
            if (m_namespace == ns && m_abi)
            {
                return false;
            }

            m_abi = true;

            if (!m_namespace.empty())
            {
                Write(*this, "\r\n}\r\n");
            }

            m_namespace = ns;

            if (!m_namespace.empty())
            {
                Write(*this, "\r\nnamespace ABI::% {\r\n", m_namespace);
            }

            return true;
        }
    };

    inline void Append(Output & target, char const * value, size_t const size)
    {
        target.Append(value, size);
    }

    template <unsigned Count, typename ... Args>
    void AppendFormat(Output & target, char const (&format)[Count], Args ... args)
    {
        target.AppendFormat(format, args ...);
    }

}
