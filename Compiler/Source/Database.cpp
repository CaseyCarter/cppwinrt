#include "Precompiled.h"
#include "Database.h"
#include "Strings.h"
#include "Output.h"
#include "Version.h"

namespace Modern { namespace Database {

static SQLite::Connection db;

void Initialize()
{
    db.Open(Settings::DatabasePath.c_str());
}

SQLite::Statement Prepare(char const * text)
{
    return SQLite::Statement(db, text);
}

}}
