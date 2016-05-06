#include "Precompiled.h"

#include "Arguments.h"
#include "Database.h"
#include "FormatMessage.h"
#include "Output.h"
#include "Path.h"
#include "Settings.h"
#include "Strings.h"
#include "Timer.h"
#include "Version.h"
#include "Year.h"

struct UsageException {};

static void ParseUsage(int argc, char ** argv);
static void PrepareUsage();

namespace Modern {

void CreateLibrary();

}

int __cdecl main(int argc, char ** argv)
{
    using namespace Modern;

    OptimizeDebugOutput();

    try
    {
        // Parse command line args
        ParseUsage(argc, argv);

        if (Options::None == (Settings::Options & Options::NoLogo))
        {
            Write(printf, Strings::ConsoleHeader, VERSION_COMMA, Year());
        }

        // Do setup work for command line args
        PrepareUsage();

        long long const start = Timer::Now();

        // Read the database and output the header files
        CreateLibrary();

        // Output the elapsed time
        if (Options::Time == (Settings::Options & Options::Time))
        {
            Write(printf, Strings::TimeCompleted, Timer::Elapsed(start));
        }
    }
    catch (UsageException)
    {
        Write(printf, Strings::ConsoleHeader, VERSION_COMMA, Year());
        Write(printf, Strings::Usage);
    }
    catch (Exception const & e)
    {
        Write(printf, Strings::OutputError, Format(e.Result), e.Result);
    }
    catch (SQLite::Exception const & e)
    {
        Write(printf, Strings::SQLiteError, e.Message, e.Result);
    }
}

static void ParseUsage(int argc, char ** argv)
{
    using namespace Modern;

    if (argc < 2)
    {
        throw UsageException();
    }

    Settings::DatabasePath = argv[1];

    Options last = Options::None;

    for (char const * arg : Arguments(argc - 2, argv + 2))
    {
        if (arg[0] == '/' || arg[0] == '-')
        {
            ++arg;

            if (0 == strcmp(arg, "out"))
            {
                last = Options::Out;
                Settings::Options |= last;
            }
            else if (0 == strcmp(arg, "nologo"))
            {
                last = Options::NoLogo;
                Settings::Options |= last;
            }
            else if (0 == strcmp(arg, "time"))
            {
                last = Options::Time;
                Settings::Options |= last;
            }
            else
            {
                throw UsageException();
            }
        }
        else if (last == Options::Out)
        {
            Settings::OutPath = arg;
        }
        else
        {
            throw UsageException();
        }
    }
}

static void PrepareUsage()
{
    using namespace Modern;

    // Prepare the output path
    std::string out = Settings::OutPath;

    if (!out.empty())
    {
        if (Path::IsRelative(out))
        {
            Path::CombineIntoSecond(Path::GetCurrentDirectory(), out);
        }
    }
    else
    {
        out = Path::GetCurrentDirectory();
    }

    Settings::OutPath = out;

    // Open db
    Database::Initialize();
}
