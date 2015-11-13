#include "Precompiled.h"
#include "Path.h"
#include "Output.h"
#include "Strings.h"
#include "Settings.h"
#include "Database.h"

namespace Modern {

void CreateConsole()
{
    Path::SetCurrentDirectory(Database::Out());

    GUID guid;
    check(CoCreateGuid(&guid));

    std::string const name = Database::Name();
    std::string const library = Database::Library();

    OutputFile project(name + ".vcxproj");
    Write<'@'>(project, Strings::Console_vcxproj, guid, name, library, library, library, library);

    OutputFile main("Main.cpp");
    Write(main, Strings::Console_cpp);

    OutputFile precompiled_h("pch.h");
    Write(precompiled_h, Strings::Console_pch_h);

    OutputFile precompiled_cpp("pch.cpp");
    Write(precompiled_cpp, Strings::Console_pch_cpp);
}

}
