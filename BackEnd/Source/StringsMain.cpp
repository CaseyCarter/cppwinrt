#include "Path.h"
#include "FileView.h"
#include "Output.h"

namespace Modern {
    
template <typename Target>
void WriteArgument(Target & target, char const value)
{
    AppendFormat(target, "%02x", value);
}

}

int main()
{
	using namespace Modern;
	
	OptimizeDebugOutput();

    Path::SetCurrentDirectory("..\\Source\\Modern");

    Output h;
    Output cpp;

    Write(h, "#pragma once\n\nnamespace Modern { namespace Strings {\n\n");
    Write(cpp, "#include \"Precompiled.h\"\n\nnamespace Modern { namespace Strings {\n\n");

    Path::FindFiles("*", [&](char const * name)
    {
        FileView file(name);
        MODERN_ASSERT(file);

        size_t fileSize = file.Size() + 1;
        size_t const length = Path::FindExtension(name) - name;
        std::string const variableName(name, length);

        Write(cpp, "extern char const %[] = { ", variableName);

        for (char const c : file)
        {
            if ('\r' == c)
            {
                --fileSize;
                continue;
            }

            Write(cpp, "0x%,", c);
        }

        Write(cpp, "0x00 };\n\n");
        Write(h, "extern char const %[%];\n", variableName, fileSize);
    });

    Write(h, "\n}}\n");
    Write(cpp, "}}\n");

    h.WriteTo("..\\Strings.h");
    cpp.WriteTo("..\\Strings.cpp");
}
