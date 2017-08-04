#include "pch.h"
#include "settings.h"

namespace cppwinrt::settings
{
    std::string component_name;
    std::experimental::filesystem::path output;
    std::vector<std::string> filters;
    std::wstring platform_version;
    bool component{};
    bool create_tests{};
    bool create_natvis{};
    bool skip_base_headers{};
    bool verbose{};
    bool overwrite{};
    bool brackets{};
}
