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

    Write(target, Strings::Logo, VERSION_STRING, year);
}

template <typename Target>
static void WriteRootNamespaceBegin(Target & target)
{
    Write(target, "\r\n\r\nWINRT_EXPORT namespace winrt {\r\n");
}

template <typename Target>
static void WriteRootNamespaceEnd(Target & target)
{
    Write(target, "\r\n}\r\n");
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
    Output out;
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
    Write(out, Strings::base_weak);                  // #include "base_weak.h"
    Write(out, Strings::base_implements);            // #include "base_implements.h"
    Write(out, Strings::base_composable);            // #include "base_composable.h"
    Write(out, Strings::base_event_consume);         // #include "base_event_consume.h"
    Write(out, Strings::base_activation);            // #include "base_activation.h"
    Write(out, Strings::base_delegate);              // #include "base_delegate.h"
    Write(out, Strings::base_reference);             // #include "base_reference.h"
    Write(out, Strings::base_collections_consume);   // #include "base_collections_consume.h"
    Write(out, Strings::base_collections_produce);   // #include "base_collections_produce.h"
    Write(out, Strings::base_collections_impl);      // #include "base_collections_impl.h"
    Write(out, Strings::base_foundation);            // #include "base_foundation.h"
    Write(out, Strings::base_async_consume);         // #include "base_async_consume.h"
    Write(out, Strings::base_async_produce);         // #include "base_async_produce.h"
    Write(out, Strings::base_agile);                 // #include "base_agile.h"
    Write(out, Strings::base_await_consume);         // #include "base_await_consume.h"
    Write(out, Strings::base_await_produce);         // #include "base_await_produce.h"

    WriteRootNamespaceEnd(out);
    Write(out, Strings::base_std_hash);

    Write(out, "\r\n#ifdef WINRT_ASYNC\r\n");
    out.WriteNamespace("std::experimental");
    Write(out, Strings::base_std_fire_and_forget);
    Write(out, Strings::base_std_async_action);
    Write(out, Strings::base_std_async_action_with_progress);
    Write(out, Strings::base_std_async_operation);
    Write(out, Strings::base_std_async_operation_with_progress);
    out.WriteNamespace();
    Write(out, "\r\n#endif\r\n");

    out.WriteTo("..\\base.h");
}

static void WritePplHeader()
{
    OutputFile out("..\\ppl.h");
    WriteLogo(out);
    Write(out, Strings::PragmaOnce);
    Write(out, Strings::base_ppl);
}

static void GenerateForward()
{
    Output out;
    WriteLogo(out);
    Write(out, Strings::PragmaOnce);

    WriteRootNamespaceBegin(out);

    WriteForwards(out);
    WriteEnumerations(out);

    out.WriteNamespace();
    WriteRootNamespaceEnd(out);
    out.WriteTo(Settings::FileNamespaceDotName + Settings::ForwardLayerExtension);
}

static void GenerateAbi()
{
    Output out;
    WriteLogo(out);
    Write(out, Strings::PragmaOnce);

    WriteRequiredForwards(out);
    WriteRequiredAbiHeadersForAbi(out);

    WriteRootNamespaceBegin(out);

    WriteStructures(out);
    WriteAbiInterfaces(out);
    WriteAbiClassDeclarations(out);

    WriteInterfaceImplForwards(out);

    WriteInterfaceTraits(out);

    out.WriteNamespace();
    WriteRootNamespaceEnd(out);
    out.WriteTo(Settings::FileNamespaceDotName + Settings::AbiLayerExtension);
}

static void GenerateInterface()
{
    Output out;
    WriteLogo(out);
    Write(out, Strings::PragmaOnce);

    Write(out, Strings::WriteInclude, Settings::FileNamespaceDotName + Settings::AbiLayerExtension);

    WriteRequiredAbiHeadersForInterface(out);
    WriteRequiredInterfaceIncludes(out);

    WriteRootNamespaceBegin(out);

    WriteGenericInterfaces(out);
    WriteInterfaceConsumers(out);
    WriteInterfaceDefinitions(out);

    out.WriteNamespace();
    WriteRootNamespaceEnd(out);
    out.WriteTo(Settings::FileNamespaceDotName + Settings::InterfaceLayerExtension);
}

static void GenerateClassDecl()
{
    Output out;
    WriteLogo(out);
    Write(out, Strings::PragmaOnce);

    Write(out, Strings::WriteInclude, Settings::FileNamespaceDotName + Settings::InterfaceLayerExtension);

    WriteRootNamespaceBegin(out);

    WriteDelegates(out);
    WriteClassDeclarations(out);

    out.WriteNamespace();
    WriteRootNamespaceEnd(out);
    out.WriteTo(Settings::FileNamespaceDotName + Settings::ClassDeclLayerExtension);
}

static void GenerateClassImpl(bool overridesExist, bool composablesExist, std::vector<std::string>& processedNamespaces)
{
    Output out;
    WriteLogo(out);
    Write(out, Strings::PragmaOnce);

    WriteRequiredClasses(out);
    Write(out, Strings::WriteInclude, Settings::InternalPath + Settings::FileNamespaceDotName + Settings::ClassDeclLayerExtension);

    // Include the full definition of parent namespaces. Some may not have any declarations. If not, go back another level.
    std::string parentNamespace = Settings::FileNamespaceDotName;
    
    size_t dotIndex;
    while ((dotIndex = parentNamespace.find_last_of(".")) != std::string::npos)
    {
        parentNamespace = parentNamespace.substr(0, dotIndex);
        if (std::find(processedNamespaces.begin(), processedNamespaces.end(), parentNamespace) != processedNamespaces.end())
        {
            Write(out, Strings::WriteInclude, parentNamespace + ".h");
            break;
        }
    }

    WriteDefinitionsForRequiredInterfaces(out);

    if (overridesExist)
    {
        Write(out, Strings::WriteInclude, Settings::InternalPath + Settings::FileNamespaceDotName + Settings::OverrideLayerExtension);
    }

    if (composablesExist)
    {
        Write(out, Strings::WriteInclude, Settings::InternalPath + Settings::FileNamespaceDotName + Settings::ComposableLayerExtension);
    }

    WriteRootNamespaceBegin(out);

    WriteDelegateShims(out);
    WriteInterfaceProducers(out);
    WriteInterfacesMethodDefinitions(out);
    WriteClassDefinitions(out);
    
    out.WriteNamespace();
    WriteRootNamespaceEnd(out);
    out.WriteTo("..\\" + Settings::FileNamespaceDotName + ".h");
}

static bool GenerateOverrides()
{
    Output out;
    WriteLogo(out);
    Write(out, Strings::PragmaOnce);

    WriteRootNamespaceBegin(out);

    if (!WriteOverrides(out))
    {
        return false;
    }

    out.WriteNamespace();
    WriteRootNamespaceEnd(out);
    out.WriteTo(Settings::FileNamespaceDotName + Settings::OverrideLayerExtension);

    return true;
}

static bool GenerateComposables()
{
    Output out;
    WriteLogo(out);
    Write(out, Strings::PragmaOnce);

    WriteRequiredOverrides(out);

    WriteRootNamespaceBegin(out);

    if (!WriteComposable(out))
    {
        return false;
    }

    out.WriteNamespace();
    WriteRootNamespaceEnd(out);
    out.WriteTo(Settings::FileNamespaceDotName + Settings::ComposableLayerExtension);

    return true;
}

static void WriteLibrary()
{
    std::string path = Settings::OutPath;
    Path::Append(path, Settings::PublicPath);
    Path::Append(path, Settings::InternalPath);
    Path::CreateDirectory(path);
    Path::SetCurrentDirectory(path);

    WriteBaseHeader();
    WritePplHeader();

    std::vector<std::string> processedNamespaces;

    Database::GetNamespaces([&]()
    {
        processedNamespaces.push_back(Settings::FileNamespaceDotName);

        GenerateForward();
        GenerateAbi();
        GenerateInterface();
        GenerateClassDecl();
        GenerateClassImpl(GenerateOverrides(), GenerateComposables(), processedNamespaces);
    });
}

}
