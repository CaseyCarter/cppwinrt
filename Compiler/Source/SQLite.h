#pragma once

#include <Modern\Handle.h>
#include "sqlite3.h"
#include <string>

namespace Modern { namespace SQLite { 

enum class Type
{
    Integer = SQLITE_INTEGER,
    Float = SQLITE_FLOAT,
    Blob = SQLITE_BLOB,
    Null = SQLITE_NULL,
    Text = SQLITE_TEXT,
};

struct Exception
{
    int Result = 0;
    std::string Message;

    explicit Exception(sqlite3 * const connection) :
        Result(sqlite3_extended_errcode(connection)),
        Message(sqlite3_errmsg(connection))
    {}
};

class Connection
{
    struct ConnectionHandleTraits : HandleTraits<sqlite3 *>
    {
        static void Close(Type value) noexcept
        {
            MODERN_VERIFY_(SQLITE_OK, sqlite3_close(value));
        }
    };

    using ConnectionHandle = Handle<ConnectionHandleTraits>;
    ConnectionHandle m_handle;

    template <typename F, typename C>
    void InternalOpen(F open, C const * const filename)
    {
        Connection temp;

        if (SQLITE_OK != open(filename, put(temp.m_handle)))
        {
            temp.ThrowLastError();
        }

        swap(m_handle, temp.m_handle);
    }

public:

    Connection() noexcept = default;

    template <typename C>
    explicit Connection(C const * const filename)
    {
        Open(filename);
    }

    template <typename C>
    explicit Connection(std::basic_string<C> const & filename) :
        Connection(filename.c_str())
    {}

    static Connection Memory()
    {
        return Connection(":memory:");
    }

    static Connection WideMemory()
    {
        return Connection(L":memory:");
    }

    __declspec(noreturn) void ThrowLastError() const
    {
        throw Exception(Get());
    }

    explicit operator bool() const noexcept
    {
        return static_cast<bool>(m_handle);
    }

    sqlite3 * Get() const noexcept
    {
        return get(m_handle);
    }

    void Open(char const * const filename)
    {
        InternalOpen(sqlite3_open, filename);
    }

    void Open(wchar_t const * const filename)
    {
        InternalOpen(sqlite3_open16, filename);
    }

    long long RowId() const noexcept
    {
        return sqlite3_last_insert_rowid(Get());
    }

    int Changes() const noexcept
    {
        return sqlite3_changes(get(m_handle));
    }

    template <typename F>
    void Profile(F callback, void * const context = nullptr)
    {
        sqlite3_profile(Get(), callback, context);
    }
};

class Backup
{
    struct BackupHandleTraits : HandleTraits<sqlite3_backup *>
    {
        static void Close(Type value) noexcept
        {
            sqlite3_backup_finish(value);
        }
    };

    using BackupHandle = Handle<BackupHandleTraits>;
    BackupHandle m_handle;
    Connection const * m_destination = nullptr;

public:

    Backup(Connection const & destination,
           Connection const & source,
           char const * const destinationName = "main",
           char const * const sourceName = "main") :
        m_handle(sqlite3_backup_init(destination.Get(),
                                     destinationName,
                                     source.Get(),
                                     sourceName)),
        m_destination(&destination)
    {
        if (!m_handle)
        {
            destination.ThrowLastError();
        }
    }

    sqlite3_backup * Get() const noexcept
    {
        return get(m_handle);
    }

    bool Step(int const pages = -1)
    {
        int const result = sqlite3_backup_step(Get(), pages);

        if (result == SQLITE_OK) return true;
        if (result == SQLITE_DONE) return false;

        // Reset() calls sqlite3_backup_finish() so that error information 
        // will be made available through the destination connection.
        m_handle.Close();
        m_destination->ThrowLastError();
    }
};

template <typename T>
struct Reader
{
    int GetInt(int const column = 0) const noexcept
    {
        return sqlite3_column_int(static_cast<T const *>(this)->Get(), column);
    }

    bool GetBool(int const column = 0) const noexcept
    {
        return 0 != GetInt(column);
    }

    char const * GetString(int const column = 0) const noexcept
    {
        return reinterpret_cast<char const *>(sqlite3_column_text(static_cast<T const *>(this)->Get(), column));
    }

    wchar_t const * GetWideString(int const column = 0) const noexcept
    {
        return static_cast<wchar_t const *>(sqlite3_column_text16(static_cast<T const *>(this)->Get(), column));
    }

    int GetStringLength(int const column = 0) const noexcept
    {
        return sqlite3_column_bytes(static_cast<T const *>(this)->Get(), column);
    }

    int GetWideStringLength(int const column = 0) const noexcept
    {
        return sqlite3_column_bytes16(static_cast<T const *>(this)->Get(), column) / sizeof(wchar_t);
    }

    Type GetType(int const column = 0) const noexcept
    {
        return static_cast<Type>(sqlite3_column_type(static_cast<T const *>(this)->Get(), column));
    }
};

class Statement : public Reader<Statement>
{
    struct StatementHandleTraits : HandleTraits<sqlite3_stmt *>
    {
        static void Close(Type value) noexcept
        {
            sqlite3_finalize(value);
        }
    };

    using StatementHandle = Handle<StatementHandleTraits>;
    StatementHandle m_handle;

    template <typename F, typename C, typename ... Values>
    void InternalPrepare(Connection const & connection, F prepare, C const * const text, Values && ... values)
    {
        MODERN_ASSERT(connection);

        if (SQLITE_OK != prepare(connection.Get(), text, -1, put(m_handle), nullptr))
        {
            connection.ThrowLastError();
        }

        BindAll(std::forward<Values>(values) ...);
    }

    void InternalBind(int) const noexcept
    {}

    template <typename First, typename ... Rest>
    void InternalBind(int const index, First && first, Rest && ... rest) const
    {
        Bind(index, std::forward<First>(first));
        InternalBind(index + 1, std::forward<Rest>(rest) ...);
    }


public:

    Statement() noexcept = default;

    template <typename C, typename ... Values>
    Statement(Connection const & connection, C const * const text, Values && ... values)
    {
        Prepare(connection, text, std::forward<Values>(values) ...);
    }

    explicit operator bool() const noexcept
    {
        return static_cast<bool>(m_handle);
    }

    sqlite3_stmt * Get() const noexcept
    {
        return get(m_handle);
    }

    __declspec(noreturn) void ThrowLastError() const
    {
        throw Exception(sqlite3_db_handle(Get()));
    }

    template <typename ... Values>
    void Prepare(Connection const & connection, char const * const text, Values && ... values)
    {
        InternalPrepare(connection, sqlite3_prepare_v2, text, std::forward<Values>(values) ...);
    }

    template <typename ... Values>
    void Prepare(Connection const & connection, wchar_t const * const text, Values && ... values)
    {
        InternalPrepare(connection, sqlite3_prepare16_v2, text, std::forward<Values>(values) ...);
    }

    bool Step() const
    {
        int const result = sqlite3_step(Get());

        if (result == SQLITE_ROW) return true;
        if (result == SQLITE_DONE) return false;

        ThrowLastError();
    }

    void Execute() const
    {
        MODERN_VERIFY(!Step());
    }

    void Bind(int const index, int const value) const
    {
        if (SQLITE_OK != sqlite3_bind_int(Get(), index, value))
        {
            ThrowLastError();
        }
    }

    void Bind(int const index, long long const value) const
    {
        if (SQLITE_OK != sqlite3_bind_int64(Get(), index, value))
        {
            ThrowLastError();
        }
    }

    void Bind(int const index, double const value) const
    {
        if (SQLITE_OK != sqlite3_bind_double(Get(), index, value))
        {
            ThrowLastError();
        }
    }

    void Bind(int const index, char const * const value, int const size = -1) const
    {
        if (SQLITE_OK != sqlite3_bind_text(Get(), index, value, size, SQLITE_STATIC))
        {
            ThrowLastError();
        }
    }

    void Bind(int const index, wchar_t const * const value, int const size = -1) const
    {
        if (SQLITE_OK != sqlite3_bind_text16(Get(), index, value, size, SQLITE_STATIC))
        {
            ThrowLastError();
        }
    }

    void Bind(int const index, std::string const & value) const
    {
        Bind(index, value.c_str(), value.size());
    }

    void Bind(int const index, std::wstring const & value) const
    {
        Bind(index, value.c_str(), value.size() * sizeof(wchar_t));
    }

    void Bind(int const index, std::string && value) const
    {
        if (SQLITE_OK != sqlite3_bind_text(Get(), index, value.c_str(), value.size(), SQLITE_TRANSIENT))
        {
            ThrowLastError();
        }
    }

    void Bind(int const index, std::wstring && value) const
    {
        if (SQLITE_OK != sqlite3_bind_text16(Get(), index, value.c_str(), value.size() * sizeof(wchar_t), SQLITE_TRANSIENT))
        {
            ThrowLastError();
        }
    }

    template <typename ... Values>
    void BindAll(Values && ... values) const
    {
        InternalBind(1, std::forward<Values>(values) ...);
    }

    template <typename ... Values>
    void Reset(Values && ... values) const
    {
        if (SQLITE_OK != sqlite3_reset(Get()))
        {
            ThrowLastError();
        }

        BindAll(values ...);
    }
};

class Row : public Reader<Row>
{
    sqlite3_stmt * m_statement = nullptr;

public:

    sqlite3_stmt * Get() const noexcept
    {
        return m_statement;
    }

    Row(sqlite3_stmt * const statement) noexcept :
    m_statement(statement)
    {}
};

class RowIterator
{
    Statement const * m_statement = nullptr;

public:

    RowIterator() noexcept = default;

    RowIterator(Statement const & statement) noexcept
    {
        if (statement.Step())
        {
            m_statement = &statement;
        }
    }

    RowIterator & operator++() noexcept
    {
        if (!m_statement->Step())
        {
            m_statement = nullptr;
        }

        return *this;
    }

    bool operator !=(RowIterator const & other) const noexcept
    {
        return m_statement != other.m_statement;
    }

    Row operator *() const noexcept
    {
        return Row(m_statement->Get());
    }
};

inline RowIterator begin(Statement const & statement) noexcept
{
    return RowIterator(statement);
}

inline RowIterator end(Statement const &) noexcept
{
    return RowIterator();
}

template <typename C, typename ... Values>
void Execute(Connection const & connection, C const * const text, Values && ... values)
{
    Statement(connection, text, std::forward<Values>(values) ...).Execute();
}

inline void BatchExecute(Connection const & connection, char const * const text)
{
    if (SQLITE_OK != sqlite3_exec(connection.Get(), text, nullptr, nullptr, nullptr))
    {
        connection.ThrowLastError();
    }
}

}}
