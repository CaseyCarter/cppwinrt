#pragma once

#include <regex>
#include <stdlib.h>
#include <xmllite.h>
#include "settings.h"

namespace cppwinrt
{
    struct registry_traits
    {
        using type = HKEY;

        static void close(type value) noexcept
        {
            WINRT_VERIFY_(ERROR_SUCCESS, RegCloseKey(value));
        }

        static constexpr type invalid() noexcept
        {
            return nullptr;
        }
    };

    using registry_key = winrt::handle_type<registry_traits>;

    inline std::experimental::filesystem::path get_sdk_path()
    {
        registry_key key;

        winrt::impl::check_win32(RegOpenKeyEx(
            HKEY_LOCAL_MACHINE,
            L"SOFTWARE\\Microsoft\\Windows Kits\\Installed Roots",
            0,
            KEY_READ,
            key.put()));

        DWORD path_size = 0;

        winrt::impl::check_win32(RegQueryValueEx(
            key.get(),
            L"KitsRoot10",
            nullptr,
            nullptr,
            nullptr,
            &path_size));

        std::wstring root((path_size / sizeof(wchar_t)) - 1, L'?');

        winrt::impl::check_win32(RegQueryValueEx(
            key.get(),
            L"KitsRoot10",
            nullptr,
            nullptr,
            reinterpret_cast<BYTE*>(root.data()),
            &path_size));

        return root;
    }

    inline void add_winmds_from_xml(
        std::vector<std::wstring>& winmd_specs,
        std::wstring const& version,
        std::experimental::filesystem::path const& sdk_path,
        std::experimental::filesystem::path path)
    {
        winrt::com_ptr<IStream> stream;

        winrt::check_hresult(SHCreateStreamOnFile(
            path.c_str(),
            STGM_READ, stream.put()));

        winrt::com_ptr<IXmlReader> reader;

        winrt::check_hresult(CreateXmlReader(
            __uuidof(IXmlReader),
            reader.put_void(),
            0));

        winrt::check_hresult(reader->SetInput(stream.get()));
        XmlNodeType node_type = XmlNodeType_None;

        while (S_OK == reader->Read(&node_type))
        {
            if (node_type != XmlNodeType_Element)
            {
                continue;
            }

            wchar_t const* value{ nullptr };
            winrt::check_hresult(reader->GetLocalName(&value, nullptr));

            if (0 != wcscmp(value, L"ApiContract"))
            {
                continue;
            }

            path = sdk_path;
            path /= L"References";
            path /= version;

            winrt::check_hresult(reader->MoveToAttributeByName(L"name", nullptr));
            winrt::check_hresult(reader->GetValue(&value, nullptr));
            path /= value;

            winrt::check_hresult(reader->MoveToAttributeByName(L"version", nullptr));
            winrt::check_hresult(reader->GetValue(&value, nullptr));
            path /= value;

            winrt::check_hresult(reader->MoveToAttributeByName(L"name", nullptr));
            winrt::check_hresult(reader->GetValue(&value, nullptr));
            path /= value;

            path += L".winmd";
            winmd_specs.push_back(path);
        }
    }

    inline std::wstring detect_sdk_version()
    {
        std::array<wchar_t, MAX_PATH> module_path;
        auto size = GetModuleFileNameW(nullptr, module_path.data(), static_cast<DWORD>(module_path.size()));
        check_win32_bool(size);
        std::wregex versionRx(LR"((\d+\.\d+\.\d+\.\d+))");
        std::wcmatch versionMatch;
        if (std::regex_search(module_path.data(), versionMatch, versionRx))
        {
            return versionMatch[1].str();
        }

        registry_key key;
        winrt::impl::check_win32(RegOpenKeyEx(
            HKEY_LOCAL_MACHINE,
            L"SOFTWARE\\Microsoft\\Windows Kits\\Installed Roots",
            0,
            KEY_READ,
            key.put()));

        std::wstring sdk_version{ L"10.0.15063.0" };
        DWORD index{ 0 };
        ULONG version_parts[4]{ 0 };
        std::array<wchar_t, MAX_PATH> kit_root;
        while (RegEnumKeyW(key.get(), index++, kit_root.data(), static_cast<DWORD>(kit_root.size())) == ERROR_SUCCESS)
        {
            if (!std::regex_search(kit_root.data(), versionMatch, versionRx))
            {
                continue;
            }
            std::wstring version_str{ versionMatch[1].str() };
            wchar_t * next_part{ version_str.data() };
            for (int i = 0; ; ++i)
            {
                auto version_part = wcstoul(next_part, &next_part, 10);
                if (version_part < version_parts[i])
                {
                    break;
                }
                version_parts[i] = version_part;
                if (i == _countof(version_parts) - 1)
                {
                    sdk_version = version_str;
                    break;
                }
                if (!next_part)
                {
                    break;
                }
                ++next_part;
            }
        }

        return sdk_version;
    }

    inline void add_winmds_from_sdk(std::vector<std::wstring>& winmd_specs, std::wstring version, bool is_ref)
    {
        try
        {
            std::experimental::filesystem::path const sdk_path = get_sdk_path();
            bool const include_extensions = version.back() == L'+';

            if (include_extensions)
            {
                version.pop_back();
            }

            if (version == L"sdk")
            {
                version = detect_sdk_version();
                if (version.empty())
                {
                    throw invalid_usage{ L"Could not determine current SDK version." };
                }
            }

            if (is_ref)
            {
                settings::platform_version = version;
            }

            std::experimental::filesystem::path path = sdk_path;
            path /= L"Platforms\\UAP";
            path /= version;
            path /= L"Platform.xml";

            add_winmds_from_xml(winmd_specs, version, sdk_path, path);

            if (!include_extensions)
            {
                return;
            }

            for (std::experimental::filesystem::directory_entry const& item :
                std::experimental::filesystem::directory_iterator(sdk_path / L"Extension SDKs"))
            {
                path = item.path() / version;
                path /= L"SDKManifest.xml";

                add_winmds_from_xml(winmd_specs, version, sdk_path, path);
            }
        }
        catch (winrt::hresult_error const&)
        {
            throw invalid_usage{ L"Could not resolve metadata specification: ", version };
        }
    }

}
