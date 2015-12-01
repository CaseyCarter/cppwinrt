#include "Precompiled.h"
#include "Path.h"
#include "Database.h"
#include "Idl.h"
#include "Strings.h"
#include "Output.h"
#include "Writers.h"
#include "Version.h"
#include "Year.h"

namespace Modern {

static char const * ExcludedFiles [] =
{
    // TODO: find way to automatically skip these for future-proofing
    "Windows.Graphics.Display.Interop.idl",
    "Windows.Foundation.CustomAttributes.idl",
    "Windows.UI.Xaml.CustomAttributes.idl",
	"Windows.ApplicationModel.contactstemp.idl",
	"windows.web.http.diagnostics.idl",
};

static void WriteLibrary();

template <unsigned Count>
bool StartsWithNoCase(char const * target, char const (&match)[Count]) noexcept
{
	return 0 == _strnicmp(target, match, Count - 1);
}

void CreateLibrary()
{
    Write(printf, Strings::LibraryReading);

    Path::SetCurrentDirectory(Database::Sdk());

	bool const noxaml = Options::NoXaml == (Settings::Options & Options::NoXaml);

    Database::Includes([&]
    {
        Path::FindFiles(Settings::Include + "*.idl", [&](char const * filename)
        {
            for (char const * exclude : ExcludedFiles)
            {
                if (0 == _stricmp(exclude, filename))
                {
                    return;
                }
            }

			if (noxaml)
			{
				if (StartsWithNoCase(filename, "Windows.UI.Xaml"))
				{
					return;
				}
			}

            if (int const sourceId = Database::AddSource(filename, true))
            {
                Idl::Parse(sourceId, filename);
            }
        });
    });

    Database::GetHeaders([&](char const * filename)
    {
        Idl::ParseHeader(filename);
    });

    Write(printf, Strings::LibraryProjecting);
    Database::Project();

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
	OutputFile out("pre.h");
	WriteLogo(out);
	Write(out, Strings::base_dependencies);
	Write(out, Strings::base_error);
	Write(out, Strings::base_accessors);
	Write(out, Strings::base_handle);
	Write(out, Strings::base_implements);
	Write(out, Strings::base_meta);
	Write(out, Strings::base_string);
	Write(out, Strings::base_comptr);
	Write(out, Strings::base_lock);
	Write(out, Strings::base_windows);
	Write(out, Strings::base_activation);
	Write(out, Strings::base_generic);
	Write(out, Strings::base_collections_consume);
	Write(out, Strings::base_collections_produce);
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
    std::string path = Database::Out();
    Path::Append(path, "winrt");
    Path::CreateDirectory(path);
    Path::SetCurrentDirectory(path);

    WriteModernHeader();
	WriteBaseHeader();
	WritePostHeader();

	//WriteSupportingHeader("debug.h", Strings::Debug);
	//WriteSupportingHeader("implements.h", Strings::Implements);
	//WriteSupportingHeader("comptr.h", Strings::ComPtr);
	//WriteSupportingHeader("handle.h", Strings::Handle);
	//WriteSupportingHeader("await.h", Strings::Await);
 //   WriteSupportingHeader("references.h", Strings::References);

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

	if (Database::IncludesCoreWindow())
	{
		Write(extend, Strings::ApplicationModel);
	}

	extend.WriteTo("sdk.extend.h");
}

}
