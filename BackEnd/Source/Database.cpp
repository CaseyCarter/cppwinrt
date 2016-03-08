#include "Precompiled.h"
#include "Database.h"
#include "Strings.h"
#include "Output.h"
#include "Version.h"

namespace Modern { namespace Database {

static SQLite::Connection db;

static void Profile(void *, const char * statement, sqlite3_uint64 const ns)
{
    sqlite3_uint64 const ms = ns / 1000000;

    if (ms > 10)
    {
        Write(printf, "%llims - %s\n", ms, statement);
    }
}

void Initialize()
{
    db = SQLite::Connection::Memory();
    BatchExecute(db, Strings::PreSql);

    Execute(db, "insert into Settings (Version) values (?)", VERSION_STRING);
}

void Project()
{
    BatchExecute(db, Strings::PostSql);
}

void Profile()
{
    sqlite3_profile(db.Get(), Profile, nullptr);
}

void SaveToFile(std::string const & filename)
{
    SQLite::Connection file(filename);
    SQLite::Backup backup(file, db);
    backup.Step();
}

SQLite::Statement Prepare(char const * text)
{
    return SQLite::Statement(db, text);
}

int RowId() noexcept
{
    return static_cast<int>(db.RowId());
}

int Changes() noexcept
{
    return db.Changes();
}

}}
