#include "pch.h"
#include "settings.h"

using namespace std::experimental::filesystem;

namespace cppwinrt::settings
{
    std::string component_name;
    std::vector<path> inputs;
    std::vector<path> refs;
    path output;
    path generated;
    path projection;
    path impl;
    path tests;
    std::vector<std::string> filters;
    std::wstring platform_version{L"10.0.15063.0"};
    bool component{};
    bool create_tests{};
    bool create_natvis{};
    bool skip_base_headers{};
    bool verbose{};
    bool overwrite{};
    bool brackets{};
}
