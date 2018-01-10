#include "pch.h"
#include "winmd_reader.h"
#include "settings.h"
#include "helpers.h"
#include "sdk.h"
#include "winmd_access.h"

using namespace winrt;
using namespace cppwinrt;
using namespace std::chrono;
using namespace std::experimental::filesystem;

namespace winmd_paths
{
    std::vector<std::wstring> inputs;
    std::vector<std::wstring> refs;
}

void add_winmd_spec(std::vector<std::wstring>& winmd_specs, std::wstring const& winmd_spec, bool is_ref)
{
    if (_wcsicmp(winmd_spec.c_str(), L"local") == 0)
    {
        std::array<wchar_t, MAX_PATH> path;
        check_bool(ExpandEnvironmentStrings(L"%windir%\\System32\\WinMetadata", path.data(), static_cast<DWORD>(path.size())));
        winmd_specs.emplace_back(path.data());
        return;
    }

    if (std::experimental::filesystem::exists(winmd_spec))
    {
        winmd_specs.emplace_back(winmd_spec);
        return;
    }

    add_winmds_from_sdk(winmd_specs, winmd_spec, is_ref);
}

void add_input_spec(std::wstring const& winmd_spec)
{
    add_winmd_spec(winmd_paths::inputs, winmd_spec, false);
}

bool is_winmd(std::experimental::filesystem::path const& filename)
{
    std::wstring extension = filename.extension();
    std::transform(extension.begin(), extension.end(), extension.begin(), towlower);

    return extension == L".winmd";
}

generator<std::experimental::filesystem::path> enum_winmd_files(std::vector<std::wstring> const& winmd_specs)
{
    for (auto const& winmd_spec : winmd_specs)
    {
        std::experimental::filesystem::path winmd_path(winmd_spec);
        winmd_path = absolute(winmd_path);
        winmd_path = canonical(winmd_path);

        if (is_directory(winmd_path))
        {
            for (std::experimental::filesystem::directory_entry const& item : std::experimental::filesystem::recursive_directory_iterator(winmd_path))
            {
                std::experimental::filesystem::path const& item_path = item.path();

                if (is_winmd(item_path))
                {
                    co_yield{ item_path };
                }
            }
        }
        else if (is_winmd(winmd_path))
        {
            co_yield{ winmd_path };
        }
        else
        {
            throw invalid_usage{ L"Invalid winmd spec: ", winmd_spec };
        }
    }
}

std::vector<std::experimental::filesystem::path> get_winmd_files(std::vector<std::wstring> const& winmd_specs)
{
    std::vector<std::experimental::filesystem::path> files;
    for (auto const& file : enum_winmd_files(winmd_specs))
    {
        std::wstring file_lower = file.wstring();
        std::transform(file_lower.begin(), file_lower.end(), file_lower.begin(), towlower);
        files.emplace_back(file_lower);
    }
    std::sort(files.begin(), files.end());
    files.erase(std::unique(files.begin(), files.end()), files.end());
    return files;
}

void prepare_metadata()
{
    if (meta::get_index().empty())
    {
        auto inputs = get_winmd_files(winmd_paths::inputs);
        for (auto const& input : inputs)
        {
            if (settings::verbose)
            {
                printf(" in:   %ls\n", input.c_str());
            }
            meta::open_database(input, false);
        }

        auto refs = get_winmd_files(winmd_paths::refs);
        refs.erase(std::remove_if(refs.begin(), refs.end(),
            [&](std::experimental::filesystem::path const& p)
        {
            return std::find(inputs.begin(), inputs.end(), p) != inputs.end();
        }),
            refs.end());
        for (auto const& ref : refs)
        {
            if (settings::verbose)
            {
                printf(" ref:  %ls\n", ref.c_str());
            }
            meta::open_database(ref, true);
        }

        settings::inputs = std::move(inputs);
        settings::refs = std::move(refs);

        if (!settings::no_output)
        {
            settings::output = absolute(settings::output);
            settings::output = canonical(settings::output);
            if (settings::verbose)
            {
                printf(" out:  %ls\n", settings::output.c_str());
                if (!winmd_paths::refs.empty())
                {
                    printf(" sdk:  %ls\n", settings::platform_version.c_str());
                }
            }

            settings::projection = settings::output / "winrt";
            settings::impl = settings::projection / "impl";
            settings::tests = settings::output / "CompileTests";
            create_directories(settings::impl);
        }

        if (!settings::sources.empty())
        {
            create_directories(settings::sources);
        }
        if (settings::create_tests)
        {
            create_directories(settings::tests);
        }

        meta::build_index();
    }
}