#include "Precompiled.h"
#include "Database.h"
#include "Write.h"

// #define WINRT_PROFILE

namespace Modern::Database {

static SQLite::Connection db;

#if defined(WINRT_PROFILE)
static void Profile(void *, const char * statement, sqlite3_uint64 const ns)
{
    sqlite3_uint64 const ms = ns / 1'000'000;

    if (ms > 20)
    {
        Write(printf, "\n% - %\n", ms, statement);
    }
}
#endif

void Initialize()
{
    db.Open(Settings::DatabasePath.c_str());

#if defined(WINRT_PROFILE)
    sqlite3_profile(db.Get(), Profile, nullptr);
#endif
}

void Project()
{
    BatchExecute(db, Strings::PostSql);
}

SQLite::Statement Prepare(char const * text)
{
    return SQLite::Statement(db, text);
}

}
