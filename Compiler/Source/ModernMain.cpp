#include "Precompiled.h"
#include "Path.h"
#include "Strings.h"
#include "Version.h"
#include "Timer.h"
#include "Output.h"
#include "Arguments.h"
#include "Database.h"
#include "Idl.h"
#include "Year.h"
#include "FormatMessage.h"
#include <stdio.h>

struct UsageException {};
struct LibraryNotFoundException {};
struct SdkNotFoundException {};
struct ProjectFolderExistsException {};
struct ProjectNameRequiredException {};

static void ParseUsage(int argc, char ** argv);
static void PrepareUsage();
static void RunCommand();
static void SaveDatabase();

namespace Modern {

void CreateLibrary();
void CreateComponent();
void CreateConsole();
void CreateDesktop();
void CreateStore();

}

int main(int argc, char ** argv)
{
	using namespace Modern;

    OptimizeDebugOutput();

    try
    {
        Database::Initialize();

        ParseUsage(argc, argv);

        if (Options::None == (Settings::Options & Options::NoLogo))
        {
			Write(printf, Strings::ConsoleHeader, VERSION_COMMA, Year());
        }

        PrepareUsage();

        long long const start = Timer::Now();

        RunCommand();

        if (Options::Time == (Settings::Options & Options::Time))
        {
            Write(printf, Strings::TimeCompleted, Timer::Elapsed(start));
        }

        if (Options::Database == (Settings::Options & Options::Database))
        {
            SaveDatabase();
        }
    }
    catch (UsageException)
    {
		Write(printf, Strings::ConsoleHeader, VERSION_COMMA, Year());
		Write(printf, Strings::Usage);
    }
    catch (LibraryNotFoundException)
    {
		Write(printf, Strings::LibraryNotFound);
    }
    catch (SdkNotFoundException)
    {
		Write(printf, Strings::SdkNotFound);
    }
    catch (ProjectFolderExistsException)
    {
		Write(printf, Strings::ProjectFolderExists);
    }
    catch (ProjectNameRequiredException)
    {
		Write(printf, Strings::ProjectNameRequired);
    }
    catch (Exception const & e)
    {
		Write(printf, Strings::OutputError, Format(e.Result), e.Result);
    }
    catch (Idl::Exception const & e)
    {
		Write(printf, Strings::IdlError, static_cast<unsigned>(e.Reason), e.File, e.Line);
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

    char const * command = argv[1];

    if (0 == strcmp(command, "library"))
    {
        Database::Command(Command::Library);
    }
    else if (0 == strcmp(command, "component"))
    {
        Database::Command(Command::Component);
    }
    else if (0 == strcmp(command, "console"))
    {
        Database::Command(Command::Console);
    }
    else if (0 == strcmp(command, "desktop"))
    {
        Database::Command(Command::Desktop);
    }
    else if (0 == strcmp(command, "universal"))
    {
        Database::Command(Command::Store);
    }
    else
    {
        throw UsageException();
    }

    Options last = Options::None;
    std::regex const validNamespace("[\\w\\.\\*]+");
    std::regex const validName("[\\w\\.]+");

    for (char const * arg : Arguments(argc - 2, argv + 2))
    {
        if (arg[0] == '/' || arg[0] == '-')
        {
            ++arg;

            if (0 == strcmp(arg, "include"))
            {
                last = Options::Include;
                Settings::Options |= last;
            }
            else if (0 == strcmp(arg, "library"))
            {
                last = Options::Library;
                Settings::Options |= last;
            }
            else if (0 == strcmp(arg, "name"))
            {
                last = Options::Name;
                Settings::Options |= last;
            }
            else if (0 == strcmp(arg, "out"))
            {
                last = Options::Out;
                Settings::Options |= last;
            }
            else if (0 == strcmp(arg, "sdk"))
            {
                last = Options::Sdk;
                Settings::Options |= last;
            }
            else if (0 == strcmp(arg, "db"))
            {
                last = Options::Database;
                Settings::Options |= last;
            }
			else if (0 == strcmp(arg, "noxaml"))
			{
				last = Options::NoXaml;
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
            else if (0 == strcmp(arg, "debug"))
            {
                last = Options::Debug;
                Settings::Options |= last;
            }
			else if (0 == strcmp(arg, "depends"))
			{
				last = Options::Depends;
                Settings::Options |= last;
			}
			else
            {
                throw UsageException();
            }
        }
        else if (last == Options::Include)
        {
            if (!std::regex_match(arg, validNamespace))
            {
                throw UsageException();
            }

            Database::Include(arg);
        }
        else if (last == Options::Library)
        {
            Database::Library(arg);
        }
        else if (last == Options::Name)
        {
            if (!std::regex_match(arg, validName))
            {
                throw UsageException();
            }

            Database::Name(arg);
        }
        else if (last == Options::Out)
        {
            Database::Out(arg);
        }
        else if (last == Options::Sdk)
        {
            Database::Sdk(arg);
        }
        else
        {
            throw UsageException();
        }
    }
}

// TODO: push all this version code into a Version header

struct Version
{
    int A, B, C, D;
};

static bool ParseInt(char const * & text, int & value)
{
    bool digit = false;
    value = 0;

    for (; isdigit(*text); ++text)
    {
        digit = true;
        value = 10 * value + (*text - '0');
    }

    return digit;
}

static bool ParseVersion(char const * text, Version & version)
{
    if (!ParseInt(text, version.A))
    {
        return false;
    }

    if ('.' == *text++)
    if (ParseInt(text, version.B))
    if ('.' == *text++)
    if (ParseInt(text, version.C))
    if ('.' == *text++)
    ParseInt(text, version.D);

    return true;
}

static void AppendHighestVersion(std::string & path)
{
	using namespace Modern;

    Path::Append(path, "*");
    size_t const size = path.size() - 1;

    Version highest = { -1, -1, -1, -1 };

    auto capture = [&](Version const & latest, char const * const match)
    {
        highest = latest;
        path.resize(size);
        Path::Append(path, match);
    };

    Path::FindFolders(path, [&](char const * const match)
    {
        Version latest = {};

        if (ParseVersion(match, latest))
        {
            if (latest.A > highest.A)
            {
                capture(latest, match);
                return;
            }

            if (latest.A == highest.A)
            {
                if (latest.B > highest.B)
                {
                    capture(latest, match);
                    return;
                }

                if (latest.B == highest.B)
                {
                    if (latest.C > highest.C)
                    {
                        capture(latest, match);
                        return;
                    }

                    if (latest.C == highest.C)
                    {
                        if (latest.D > highest.D)
                        {
                            capture(latest, match);
                            return;
                        }
                    }
                }
            }
        }
    });

    if (highest.A == -1)
    {
        throw SdkNotFoundException();
    }
}

static void PrepareUsage()
{
	using namespace Modern;

    std::string out = Database::Out();

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

    Command const command = Database::Command();

    if (command == Command::Library)
    {
        if (!Database::HasIncludes())
        {
            Database::Include("Windows.");
        }

        if (Database::Sdk().empty())
        {
            std::string sdk = Path::GetKnownFolder(FOLDERID_ProgramFilesX86);

            Path::Append(sdk, "Windows Kits");
            AppendHighestVersion(sdk);
            Path::Append(sdk, "Include");
            AppendHighestVersion(sdk);
            Path::Append(sdk, "winrt");

            if (!Path::Exists(sdk))
            {
                throw SdkNotFoundException();
            }

            Database::Sdk(sdk);
        }
    }
    else
    {
        std::string const name = Database::Name();

        if (name.empty())
        {
            throw ProjectNameRequiredException();
        }

        Path::Append(out, name);

        std::string library = Database::Library();

        if (library.empty())
        {
            library = Path::GetCurrentDirectory();
        }
        else if (Path::IsRelative(library))
        {
            Path::CombineIntoSecond(Path::GetCurrentDirectory(), library);
        }

        if (!Path::Exists(Path::Combine(library, "winrt.h")))
        {
            throw LibraryNotFoundException();
        }

        library = Path::ToRelative(out, true, library, true);
        Database::Library(library);
    }

    Database::Out(out);

    if (!Path::CreateDirectory(out) && command != Command::Library && command != Command::Component)
    {
        throw ProjectFolderExistsException();
    }
}

static void RunCommand()
{
	using namespace Modern;

    Command const command = Database::Command();

    if (command == Command::Library)
    {
        CreateLibrary();
    }
    else if (command == Command::Component)
    {
        CreateComponent();
    }
    else if (command == Command::Console)
    {
        CreateConsole();
    }
    else if (command == Command::Desktop)
    {
        CreateDesktop();
    }
    else if (command == Command::Store)
    {
        CreateStore();
    }
    else MODERN_ASSERT(false);
}

static void SaveDatabase()
{
	using namespace Modern;

    Command const command = Database::Command();

    if (command == Command::Library)
    {
        std::string path = Database::Out();
        Path::Append(path, "Modern.db");
        Database::SaveToFile(path);
    }
    else if (command == Command::Component)
    {
        std::string path = Database::Out();
        Path::Append(path, Database::Name());
        path += ".db";
        Database::SaveToFile(path);
    }
}
