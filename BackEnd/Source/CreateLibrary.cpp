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

void CreateLibrary()
{
    Database::Project();
    WriteLibrary();
}

template <typename Target>
static void WriteLogo(Target & target)
{
    static unsigned const year = Year();

    Write(target, Strings::Logo, VERSION_COMMA, year);
}

template <typename Target>
static void WriteRootNamespaceBegin(Target & target)
{
    Write(target, "\r\nWINRT_EXPORT namespace winrt {\r\n");
}

template <typename Target>
static void WriteRootNamespaceEnd(Target & target)
{
    Write(target, "\r\n}\r\n");
}

static void WriteModernHeader()
{
    OutputFile target("..\\winrt.h");
    WriteLogo(target);
    Write(target, Strings::base_modern);
}

static void WriteWindowsNumerics()
{
    // Note: this is in the RS1 SDK - remove this once the RS1 SDK is available.

    OutputFile impl("..\\WindowsNumerics.impl.h");
    Write(impl, Strings::WindowsNumerics_impl);

    OutputFile inl("..\\WindowsNumerics.inl");
    Write(inl, Strings::WindowsNumerics);
}

static void WriteModule()
{
    OutputFile target("..\\winrt.ixx");
    WriteLogo(target);
    Write(target, Strings::base_module);
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
    Write(out, Strings::PragmaOnce);

    Write(out, Strings::base_dependencies);          // #include "base_dependencies.h"
    Write(out, Strings::base_macros);                // #include "base_macros.h"

    WriteRootNamespaceBegin(out);

    Write(out, Strings::base_accessors);             // #include "base_accessors.h"
    Write(out, Strings::base_handle);                // #include "base_handle.h"
    Write(out, Strings::base_meta);                  // #include "base_meta.h"
    Write(out, Strings::base_com_ptr);               // #include "base_com_ptr.h"
    Write(out, Strings::base_string);                // #include "base_string.h"
    Write(out, Strings::base_string_hstring);        // #include "base_string_hstring.h"
    Write(out, Strings::base_string_hstring_ref);    // #include "base_string_hstring_ref.h"
    Write(out, Strings::base_string_operators);      // #include "base_string_operators.h"
    Write(out, Strings::base_error);                 // #include "base_error.h"
    Write(out, Strings::base_lock);                  // #include "base_lock.h"
    Write(out, Strings::base_array);                 // #include "base_array.h"
    Write(out, Strings::base_windows);               // #include "base_windows.h"
    Write(out, Strings::base_implements);            // #include "base_implements.h"
    Write(out, Strings::base_weak);                  // #include "base_weak.h"
    Write(out, Strings::base_composable);            // #include "base_composable.h"
    Write(out, Strings::base_event_consume);         // #include "base_event_consume.h"
    Write(out, Strings::base_activation);            // #include "base_activation.h"
    Write(out, Strings::base_generic);               // #include "base_generic.h"
    Write(out, Strings::base_collections_consume);   // #include "base_collections_consume.h"
    Write(out, Strings::base_async);                 // #include "base_async.h"
    Write(out, Strings::base_foundation);            // #include "base_foundation.h"
    Write(out, Strings::base_await_consume);         // #include "base_await_consume.h"

    WriteRootNamespaceEnd(out);

    Write(out, Strings::base_std);
}

static void WriteLibrary()
{
    std::string path = Settings::OutPath;
    Path::Append(path, "winrt");
    Path::CreateDirectory(path);
    Path::SetCurrentDirectory(path);

    WriteModernHeader();
    WriteModule();
    WriteBaseHeader();
    WriteWindowsNumerics();

    Output abi;
    WriteLogo(abi);
    Write(abi, Strings::PragmaOnce);
    WriteRootNamespaceBegin(abi);
    WriteEnumerations(abi);
    WriteStructures(abi);
    WriteAbiInterfaceDeclarations(abi);
    WriteAbiInterfaces(abi);
    WriteAbiClassDeclarations(abi);
    WriteGenericInterfaces(abi);
    WriteRootNamespaceEnd(abi);
    abi.WriteTo("sdk.abi.h");

    Output meta;
    WriteLogo(meta);
    Write(meta, Strings::PragmaOnce);
    WriteRootNamespaceBegin(meta);
    WriteDeclarations(meta);
    WriteInterfaceConsumers(meta);
    WriteInterfaceTraits(meta);
    WriteInterfaceDefinitions(meta);
    WriteClassDeclarations(meta);
    WriteInterfaceProducers(meta);
    WriteRootNamespaceEnd(meta);
    meta.WriteTo("sdk.meta.h");

    Output shim;
    WriteLogo(shim);
    Write(shim, Strings::PragmaOnce);
    WriteRootNamespaceBegin(shim);
    WriteDelegates(shim);
    WriteInterfacesMethodDefinitions(shim);
    WriteClassDefinitions(shim);
    WriteRootNamespaceEnd(shim);
    shim.WriteTo("sdk.shim.h");

    Output extend;
    WriteLogo(extend);
    Write(extend, Strings::PragmaOnce);
    WriteRootNamespaceBegin(extend);
    WriteOverrides(extend);
    WriteComposable(extend);
    WriteRootNamespaceEnd(extend);
    extend.WriteTo("sdk.extend.h");
}

}
