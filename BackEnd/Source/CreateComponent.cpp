#include "Precompiled.h"
#include "Path.h"
#include "Output.h"
#include "Strings.h"
#include "Idl.h"
#include "Database.h"
#include "Writers.h"

namespace Modern {

using namespace Database;

static void CreateProject(std::string const & name, std::string const & source)
{
    GUID guid;
    check(CoCreateGuid(&guid));

    std::string const library = Database::Library();

    OutputFile project(name + ".vcxproj");
    Write<'@'>(project, Strings::Component_vcxproj, guid, name, library, library, library, library, library, library, name, name);

    OutputFile idl(source);
    Write(idl, Strings::Component_idl, name);

    OutputFile component_def("component.def");
    Write(component_def, Strings::Component_def);

    OutputFile precompiled_h("pch.h");
    Write(precompiled_h, Strings::Component_pch_h);

    OutputFile precompiled_cpp("pch.cpp");
    Write(precompiled_cpp, Strings::Component_pch_cpp);
}

static void CreateComponentSourceFile()
{
    Output out;
    WriteComponentSource(out);

    out.WriteTo("component.cpp");
}

static void CreateComponentHeaderFile()
{
    Output out;
    WriteComponentHeader(out);

    out.WriteTo("component.h");
}

static void CreateProjection(std::string const & name)
{
    std::string const filename = name + ".h";

    Output meta;
    WriteDeclarations(meta);

    Output shim;
    WriteDelegates(shim);

    Output abi;
    WriteEnumerations(abi);
    WriteStructures(abi);
    WriteAbiInterfaceDeclarations(abi);

    WriteInterfaces(meta, shim, abi);
    WriteAbiClassDeclarations(abi);
    WriteImplementation(meta);
    WriteInterfaceDefinitions(meta);
    WriteClasses(meta, shim);
    WriteGenericInterfaces(abi);

    Output extend;
    WriteOverrides(extend);
    WriteComposable(extend);

    Output out;
    Write(out, "#pragma once\n");
    out.Append(abi.Begin(), abi.Size());
    out.Append(meta.Begin(), meta.Size());
    out.Append(shim.Begin(), shim.Size());
    out.Append(extend.Begin(), extend.Size());

    out.WriteTo(filename.c_str());
}

static void CreateClasses(std::string const & /*name*/)
{
    GetComponentClasses([&]
    {
        std::string filename = Settings::ClassDotName + ".h";

        if (!Path::Exists(filename))
        {
            Output output;

            WriteComponentClassHeader(output);

            output.WriteTo(filename.c_str());
        }

        Path::RenameExtension(filename, ".cpp");

        if (!Path::Exists(filename))
        {
            Output output;

            WriteComponentClassSource(output);

            output.WriteTo(filename.c_str());
        }
    });
}

void CreateComponent()
{
    Path::SetCurrentDirectory(Database::Out());

    std::string const name = Database::Name();
    std::string const source = name + ".idl";

    if (!Path::Exists(source))
    {
        CreateProject(name, source);
    }
    else
    {
        int const sourceId = Database::AddSource(source.c_str(), true);
        MODERN_ASSERT(sourceId != 0);
        Idl::Parse(sourceId, source.c_str());

        Database::Project();
        CreateClasses(name);
    }

    CreateComponentSourceFile();
    CreateComponentHeaderFile();
    CreateProjection(name);
}

}
