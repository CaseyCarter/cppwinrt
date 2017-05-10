#pragma once

namespace cppwinrt::settings
{
    extern std::experimental::filesystem::path first_input;
    extern std::experimental::filesystem::path output;
    extern std::wstring platform_version;
    extern bool component;
    extern bool create_tests;
    extern bool skip_base_header;
    extern bool single_header;
    extern bool verbose;
    extern std::vector<std::string> filters;
    extern bool overwrite;
}
