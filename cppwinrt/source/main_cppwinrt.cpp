#include "pch.h"
#include <fstream>
#include "text_writer.h"
#include "code_writer.h"
#include "winmd_reader.h"
#include "strings.h"
#include "version.h"
#include "settings.h"
#include "platform_writer.h"
#include "component_writer.h"

using namespace cppwinrt;
using namespace std::chrono;
using namespace std::experimental::filesystem;

namespace
{
    namespace usage
    {
        std::vector<std::wstring> inputs;
        std::vector<std::wstring> refs;
    }

    struct invalid_usage {
        std::wstring message = L"Invalid usage";
        std::wstring arg = L"";
        HRESULT code = E_INVALIDARG;
    };

    bool is_winmd(path const& filename)
    {
        std::wstring extension = filename.extension();
        std::transform(extension.begin(), extension.end(), extension.begin(), towlower);

        return extension == L".winmd";
    }

    std::experimental::generator<std::wstring> enum_args(int const argc, wchar_t** argv);

    std::experimental::generator<std::wstring> enum_response_file(path response_path)
    {
        if (is_directory(response_path) || is_winmd(response_path))
        {
            throw invalid_usage{ L"Invalid usage - '@' is reserved for response files" };
        }
        std::array<wchar_t, 8192> line_buf;
        std::wifstream response_file(absolute(response_path).c_str());
        while (response_file.getline(line_buf.data(), line_buf.size()))
        {
            int argc;
            wchar_t** argv;
            argv = CommandLineToArgvW(line_buf.data(), &argc);
            winrt::impl::check_pointer(argv);
            for (auto const& arg : enum_args(argc, argv))
            {
                co_yield arg;
            }
        }
    }

    std::experimental::generator<std::wstring> enum_args(int const argc, wchar_t** argv)
    {
        for (int i = 0; i < argc; ++i)
        {
            if (argv[i][0] == L'@')
            {
                for (auto const& arg : enum_response_file(argv[i] + 1))
                {
                    co_yield arg;
                }
                continue;
            }
            co_yield argv[i];
        }
    }

    void print_usage(bool detailed = false)
    {
        time_t t{ time(nullptr) };
        tm tm{};
        localtime_s(&tm, &t);

        printf(strings::print_usage, CPPWINRT_VERSION_STRING, 1900 + tm.tm_year);
        if (detailed)
        {
            printf(strings::print_usage_details);
        }
    }

    enum class option
    {
        none,
        in,
        ref,
        out,
        component,
        filter,
        tests,
        natvis,
        verbose,
        overwrite,
        help,
    };

    void add_winmd_spec(std::vector<std::wstring>& winmd_specs, std::wstring const& winmd_spec)
    {
        if (_wcsicmp(winmd_spec.c_str(), L"local") == 0)
        {
            std::array<wchar_t, MAX_PATH> path;
            check_win32_bool(ExpandEnvironmentStrings(L"%windir%\\System32\\WinMetadata", path.data(), static_cast<DWORD>(path.size())));
            winmd_specs.emplace_back(path.data());
        }
        else
        {
            winmd_specs.emplace_back(winmd_spec);
        }
    }

    bool parse_usage(int const argc, wchar_t** argv)
    {
        if (argc < 2)
        {
            print_usage();
            return false;
        }

        static const struct
        {
            wchar_t const* string;
            option value;
        }
        options[] =
        {
            { L"in", option::in },
            { L"ref", option::ref },
            { L"out", option::out },
            { L"component", option::component },
            { L"filter", option::filter },
            { L"tests", option::tests },
            { L"natvis", option::natvis },
            { L"verbose", option::verbose },
            { L"write", option::overwrite },
            { L"help", option::help },
        };

        option last_option{};
        for (auto arg_str : enum_args(argc - 1, argv + 1))
        {
            auto arg = arg_str.c_str();

            if (arg[0] == '/' || arg[0] == '-')
            {
                ++arg;
                option cur_option = option::none;
                for (auto const& o : options)
                {
                    if (0 == wcsncmp(arg, o.string, wcslen(arg)))
                    {
                        cur_option = o.value;
                        break;
                    }
                }
                switch (cur_option)
                {
                case option::none:
                    throw invalid_usage{ L"Unsupported option: ", arg };
                case option::component:
                    settings::component = true;
                    break;
                case option::tests:
                    settings::create_tests = true;
                    break;
                case option::natvis:
                    settings::create_natvis = true;
                    break;
                case option::verbose:
                    settings::verbose = true;
                    break;
                case option::overwrite:
                    settings::overwrite = true;
                    break;
                case option::help:
                    print_usage(true);
                    return false;
                default:
                    last_option = cur_option;
                    break;
                }
                continue;
            }

            switch (last_option)
            {
            case option::none:
                break;
            case option::in:
                if (settings::first_input.empty())
                {
                    settings::first_input = arg;
                }
                add_winmd_spec(usage::inputs, arg);
                break;
            case option::ref: 
                settings::skip_base_header = true;
                add_winmd_spec(usage::refs, arg);
                break;
            case option::out: 
                settings::output = arg; 
                last_option = option::none; 
                break;
            case option::filter: 
                {
                    std::wstring filter(arg);
                    settings::filters.emplace_back(filter.begin(), filter.end());
                }
                break;
            default: 
                throw invalid_usage{ L"Internal error: ", 
                    options[static_cast<size_t>(last_option) - 1].string, HRESULT_FROM_WIN32(ERROR_INTERNAL_ERROR) };
            }
        }

        return true;
    }

    std::experimental::generator<path> enum_winmd_files(std::vector<std::wstring> winmd_specs)
    {
        for (auto const& winmd_spec : winmd_specs)
        {
            path winmd_path(winmd_spec);
            winmd_path = absolute(winmd_path);
            winmd_path = canonical(winmd_path);
            if (is_directory(winmd_path.c_str()))
            {
                for (directory_entry const& item : std::experimental::filesystem::recursive_directory_iterator(winmd_path.c_str()))
                {
                    if (is_winmd(item.path()))
                    {
                        co_yield{ item.path() };
                    }
                }
            }
            else if (is_winmd(winmd_path.c_str()))
            {
                co_yield{ winmd_path };
            }
            else
            {
                throw invalid_usage{ L"Invalid winmd spec: ", winmd_spec };
            }
        }
    }

    std::vector<path> get_winmd_files(std::vector<std::wstring> winmd_specs)
    {
        std::vector<path> files;
        for (auto file : enum_winmd_files(winmd_specs))
        {
            files.push_back(file);
        }
        std::sort(files.begin(), files.end());
        files.erase(std::unique(files.begin(), files.end()), files.end());
        return files;
    }

    void prepare_input()
    {
        auto inputs = get_winmd_files(usage::inputs);
        for(auto const& input: inputs)
        {
            if (settings::verbose)
            {
                printf(" in:   %ls\n", input.c_str());
            }
            meta::open_database(input, false);
        }

        auto refs = get_winmd_files(usage::refs);
        refs.erase(std::remove_if(refs.begin(), refs.end(),
            [&](path const& p)
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

        settings::output = absolute(settings::output);
        create_directories(settings::output); // fs::canonical requires the folder to exist...
        settings::output = canonical(settings::output);
        if (settings::verbose)
        {
            printf(" out:  %ls\n", settings::output.c_str());
        }

        meta::index_types();
    }

    void init_crt()
    {
#ifdef _DEBUG
        // Provides faster output for debug builds
        _CrtSetDebugFillThreshold(0);

        // Control reporting behavior of _ASSERT/_ASSERTE
        _CrtSetReportMode(_CRT_ASSERT, _CRTDBG_MODE_FILE | _CRTDBG_MODE_WNDW);
        _CrtSetReportFile(_CRT_ASSERT, _CRTDBG_FILE_STDERR);
#endif
    }

    void run_cppwinrt(int argc, wchar_t** argv)
    {
        init_crt();
        winrt::init_apartment();

        auto start = high_resolution_clock::now();

        if (!parse_usage(argc, argv))
        {
            return;
        }

        prepare_input();

        if (settings::component)
        {
            write_component();
        }
        else
        {
            write_platform();
        }

        if (settings::verbose)
        {
            printf(" time: %llums\n", duration_cast<milliseconds>(high_resolution_clock::now() - start).count());
        }
    }
}

int wmain(int argc, wchar_t** argv)
{
    try
    {
        run_cppwinrt(argc, argv);
    }
    catch (winrt::hresult_error const& e)
    {
        printf(strings::print_hresult_error, e.code(), e.message().c_str());
    }
    catch (std::exception const& e)
    {
        printf(strings::print_exception, E_FAIL, e.what());
    }
    catch (invalid_usage const& e)
    {
        printf(strings::print_invalid_usage, e.code, e.message.c_str(), e.arg.c_str());
    }
}
