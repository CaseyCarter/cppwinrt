#include "pch.h"
#include "settings.h"

namespace cppwinrt::settings
{
    std::experimental::filesystem::path first_input;
    std::experimental::filesystem::path output;
    std::vector<std::string> filters;
    std::wstring platform_version;
    bool component{};
    bool create_tests{};
    bool create_natvis{};
    bool skip_base_header{};
    bool single_header{};
    bool verbose{};
    bool overwrite{};
}
