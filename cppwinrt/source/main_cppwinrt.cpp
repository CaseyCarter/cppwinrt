#include "pch.h"
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
    enum class command
    {
        none,
        platform,
        header,
        component,
    };

    enum class option
    {
        none,
        in,
        out,
        version,
        filter,
    };

    namespace usage
    {
        ::command command{};
        bool platform_input{};
        std::vector<std::pair<std::wstring, bool>> input;
    }

    std::experimental::generator<wchar_t const*> enum_args(int const argc, wchar_t** argv)
    {
        for (int i = 0; i < argc; ++i)
        {
            co_yield argv[i];
        }
    }

    struct invalid_usage {};

    void print_usage()
    {
        time_t t{ time(nullptr) };
        tm tm{};
        localtime_s(&tm, &t);

        printf(strings::print_usage, CPPWINRT_VERSION_STRING, 1900 + tm.tm_year);
    }

    bool parse_usage(int const argc, wchar_t** argv)
    {
        if (argc < 2)
        {
            print_usage();
            return false;
        }

        if (0 == wcscmp(argv[1], L"platform"))
        {
            if (usage::command == command::none)
            {
                usage::command = command::platform;
            }
            else if (usage::command != command::platform)
            {
                usage::platform_input = true;
            }
        }
        else if (0 == wcscmp(argv[1], L"header"))
        {
            usage::command = command::header;
        }
        else if (0 == wcscmp(argv[1], L"component"))
        {
            usage::command = command::component;
        }
        else
        {
            throw invalid_usage();
        }

        option last_option{};

        for (wchar_t const* arg : enum_args(argc - 2, argv + 2))
        {
            if (arg[0] == '/' || arg[0] == '-')
            {
                ++arg;
                last_option = option::none;

                if (0 == wcscmp(arg, L"in"))
                {
                    last_option = option::in;
                }
                else if (0 == wcscmp(arg, L"out"))
                {
                    last_option = option::out;
                }
                else if (0 == wcscmp(arg, L"v"))
                {
                    last_option = option::version;
                }
                else if (0 == wcscmp(arg, L"f"))
                {
                    last_option = option::filter;
                }
                else if (0 == wcscmp(arg, L"single"))
                {
                    settings::single_header = true;
                }
                else if (0 == wcscmp(arg, L"tests"))
                {
                    settings::create_tests = true;
                }
                else if (0 == wcscmp(arg, L"verbose"))
                {
                    settings::verbose = true;
                }
                else
                {
                    throw invalid_usage();
                }
            }
            else if (last_option == option::in)
            {
                if (usage::command != command::platform && settings::first_input.empty())
                {
                    settings::first_input = arg;
                }

                usage::input.emplace_back(arg, usage::platform_input);
            }
            else if (last_option == option::out)
            {
                settings::output = arg;
            }
            else if (last_option == option::version)
            {
                settings::platform_version = arg;
            }
            else if (last_option == option::filter)
            {
                std::wstring filter(arg);
                settings::filters.emplace_back(filter.begin(), filter.end());
            }
            else
            {
                throw invalid_usage();
            }
        }

        return true;
    }

    bool is_winmd(path const& filename)
    {
        std::wstring extension = filename.extension();
        std::transform(extension.begin(), extension.end(), extension.begin(), towlower);

        return extension == L".winmd";
    }

    std::experimental::generator<std::pair<std::wstring, bool>> enum_winmd_files()
    {
        for (auto&& input : usage::input)
        {
            path input_path(input.first);
            input_path = absolute(input_path);
            input_path = canonical(input_path);
            if (is_directory(input_path.c_str()))
            {
                for (directory_entry const& item : recursive_directory_iterator(input_path.c_str()))
                {
                    if (is_winmd(item.path()))
                    {
                        co_yield{ item.path(), input.second };
                    }
                }
            }
            else if (is_winmd(input_path.c_str()))
            {
                co_yield{ input_path, input.second };
            }
            else
            {
                throw invalid_usage();
            }
        }
    }

    bool includes_foundation_input()
    {
        WINRT_ASSERT(usage::command != command::platform);

        return usage::input.end() != std::find_if(usage::input.begin(), usage::input.end(),
            [](std::pair<std::wstring, bool> const& value)
        {
            return value.second;
        });
    }

    void include_win_metadata(bool foundation)
    {
        std::array<wchar_t, MAX_PATH> path;
        check_win32_bool(ExpandEnvironmentStrings(L"%windir%\\System32\\WinMetadata", path.data(), MAX_PATH));
        usage::input.emplace_back(path.data(), foundation);
    }

    void prepare_input()
    {
        if (usage::input.empty())
        {
            include_win_metadata(usage::platform_input);
        }

        if (usage::command != command::platform && !includes_foundation_input())
        {
            include_win_metadata(true);
        }

        settings::output = absolute(settings::output);
        create_directories(settings::output); // fs::canonical requires the folder to exist...
        settings::output = canonical(settings::output);

        for (std::pair<std::wstring, bool> const& file : enum_winmd_files())
        {
            if (settings::verbose)
            {
                printf(" in:   %ls%s\n", file.first.c_str(), (file.second ? " (platform)" : ""));
            }

            meta::open_database(file.first, file.second);
        }

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

        if (usage::command == command::platform)
        {
            write_platform();
        }
        else if (usage::command == command::header)
        {
            write_header();
        }
        else if (usage::command == command::component)
        {
            write_component();
        }
        else
        {
            WINRT_ASSERT(false);
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
    catch (invalid_usage const&)
    {
        printf(strings::print_invalid_usage, E_INVALIDARG);
    }
}
