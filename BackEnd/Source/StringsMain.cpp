#include "Path.h"
#include "FileView.h"
#include "Output.h"
#include <algorithm>

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

    Path::SetCurrentDirectory("Source\\Modern");

    Output h;
    Output cpp;

    Write(h, "#pragma once\r\n\r\nnamespace Modern::Strings {\r\n\r\n");
    Write(cpp, "#include \"Precompiled.h\"\r\n\r\nnamespace Modern::Strings {\r\n\r\n");

    Path::FindFiles("*", [&](char const * name, bool const folder)
    {
        if (folder)
        {
            return;
        }

        FileView file(name);
        MODERN_ASSERT(file);

        size_t fileSize = file.Size() + 1;
        size_t const length = Path::FindExtension(name) - name;
        std::string variableName(name, length);

        std::replace(begin(variableName), end(variableName), '.', '_');

        Write(cpp, "extern char const %[] = { ", variableName);

        for (char const c : file)
        {
            if ('\r' == c)
            {
                --fileSize;
                continue;
            }

            if ('\n' == c)
            {
                ++fileSize;
                Write(cpp, "0x%,", '\r');
            }

            Write(cpp, "0x%,", c);
        }

        Write(cpp, "0x00 };\r\n\r\n");
        Write(h, "extern char const %[%];\r\n", variableName, fileSize);
    });

    Write(h, "\r\n}\r\n");
    Write(cpp, "}\r\n");

    h.WriteTo("..\\Strings.h");
    cpp.WriteTo("..\\Strings.cpp");
}