#pragma once

namespace cppwinrt::settings
{
    extern std::string component_name;
    extern std::experimental::filesystem::path output;
    extern std::wstring platform_version;
    extern bool component;
    extern bool create_tests;
    extern bool create_natvis;
    extern bool skip_base_headers;
    extern bool verbose;
    extern std::vector<std::string> filters;
    extern bool overwrite;
}
