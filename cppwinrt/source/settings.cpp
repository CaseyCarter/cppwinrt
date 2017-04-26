#include "pch.h"
#include "settings.h"

namespace cppwinrt::settings
{
    std::experimental::filesystem::path first_input;
    std::experimental::filesystem::path output;
    std::wstring platform_version;
    bool create_tests{};
    bool single_header{};
    bool verbose{};
    std::vector<std::string> filters;
    bool overwrite{};
}
