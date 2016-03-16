#include "Precompiled.h"
#include "Path.h"
#include "Database.h"
#include "Strings.h"
#include "Output.h"
#include "Writers.h"
#include "Version.h"
#include "Year.h"

namespace Modern {

static void WriteLibrary();

template <unsigned Count>
bool StartsWithNoCase(char const * target, char const (&match)[Count]) noexcept
{
    return 0 == _strnicmp(target, match, Count - 1);
}

void CreateLibrary()
{
    Write(printf, Strings::LibraryWriting);
    WriteLibrary();
}

template <typename Target>
static void WriteLogo(Target & target)
{
    static unsigned const year = Year();

    Write(target, Strings::Logo, VERSION_COMMA, year);
}

static void WriteModernHeader()
{
    OutputFile target("..\\winrt.h");
    WriteLogo(target);
    Write(target, Strings::base_modern);
}

template <unsigned Count>
static void WriteSupportingHeader(char const * filename, char const (&text)[Count])
{
    OutputFile target(filename);
    WriteLogo(target);
    Write(target, text);
}

static void WriteBaseHeader()
{
    OutputFile out("base.h");
    WriteLogo(out);
    Write(out, Strings::base_dependencies);        // #include "base_dependencies.h"
    Write(out, Strings::base_debug);               // #include "base_debug.h"
    Write(out, Strings::base_accessors);           // #include "base_accessors.h"
    Write(out, Strings::base_comptr);              // #include "base_comptr.h"
    Write(out, Strings::base_handle);              // #include "base_handle.h"
    Write(out, Strings::base_error);               // #include "base_error.h"
    Write(out, Strings::base_implements);          // #include "base_implements.h"
    Write(out, Strings::base_meta);                // #include "base_meta.h"
    Write(out, Strings::base_string);              // #include "base_string.h"
    Write(out, Strings::base_string_hstring);      // #include "base_string_hstring.h"
    Write(out, Strings::base_string_hstring_ref);  // #include "base_string_hstring_ref.h"
    Write(out, Strings::base_string_operators);    // #include "base_string_operators.h"
    Write(out, Strings::base_lock);                // #include "base_lock.h"
    Write(out, Strings::base_windows);             // #include "base_windows.h"
    Write(out, Strings::base_activation);          // #include "base_activation.h"
    Write(out, Strings::base_generic);             // #include "base_generic.h"
    Write(out, Strings::base_collections_consume); // #include "base_collections_consume.h"
    Write(out, Strings::base_collections_produce); // #include "base_collections_produce.h"
    Write(out, Strings::base_weak);                // #include "base_weak.h"

    Write(out, Strings::base_std);
}

static void WritePostHeader()
{
    OutputFile out("post.h");
    WriteLogo(out);
    Write(out, Strings::base_await_consume);
    Write(out, Strings::base_reference);
}

static void WriteLibrary()
{
    std::string path = Settings::OutPath;
    Path::Append(path, "winrt");
    Path::CreateDirectory(path);
    Path::SetCurrentDirectory(path);

    WriteModernHeader();
    WriteBaseHeader();
    WritePostHeader();

    Output meta;
    WriteLogo(meta);
    Write(meta, Strings::PragmaOnce);
    WriteDeclarations(meta);

    Output shim;
    WriteLogo(shim);
    Write(shim, Strings::PragmaOnce);
    WriteDelegates(shim);

    Output abi;
    WriteLogo(abi);
    Write(abi, Strings::PragmaOnce);
    WriteEnumerations(abi);
    WriteStructures(abi);
    WriteAbiInterfaceDeclarations(abi);

    WriteInterfaces(meta, shim, abi);
    WriteAbiClassDeclarations(abi);
    WriteImplementation(meta);
    WriteInterfaceDefinitions(meta);
    WriteClasses(meta, shim);
    WriteGenericInterfaces(abi);

    meta.WriteTo("sdk.meta.h");
    shim.WriteTo("sdk.shim.h");
    abi.WriteTo("sdk.abi.h");

    Output extend;
    WriteLogo(extend);
    Write(extend, Strings::PragmaOnce);
    WriteOverrides(extend);
    WriteComposable(extend);

    //// Once xbox version ships, use a more flexible solution
    // If CoreWindow classes are present in the DB, include overridable classes
    // like IFrameworkViewT and IFrameworkViewSourceT
    if (Database::IncludesCoreWindow())
    {
        Write(extend, Strings::ApplicationModel);
    }

    extend.WriteTo("sdk.extend.h");
}

}
