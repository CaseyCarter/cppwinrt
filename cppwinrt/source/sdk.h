#pragma once

namespace cppwinrt
{
    struct registry_traits : winrt::impl::handle_traits<HKEY>
    {
        static void close(HKEY value) noexcept
        {
            WINRT_VERIFY_(ERROR_SUCCESS, RegCloseKey(value));
        }
    };

    using registry_key = winrt::impl::handle<registry_traits>;

    inline void check_registry(LONG result)
    {
        if (result != ERROR_SUCCESS)
        {
            winrt::impl::throw_hresult(HRESULT_FROM_WIN32(result));
        }
    }

    inline std::experimental::filesystem::path get_sdk_path()
    {
        registry_key key;

        check_registry(RegOpenKeyEx(
            HKEY_LOCAL_MACHINE,
            L"SOFTWARE\\Microsoft\\Windows Kits\\Installed Roots",
            0,
            KEY_READ,
            key.put()));

        DWORD path_size = 0;

        check_registry(RegQueryValueEx(
            key.get(),
            L"KitsRoot10",
            nullptr,
            nullptr,
            nullptr,
            &path_size));

        std::wstring root((path_size / sizeof(wchar_t)) - 1, L'?');

        check_registry(RegQueryValueEx(
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
            STGM_READ, winrt::put_abi(stream)));

        winrt::com_ptr<IXmlReader> reader;

        winrt::check_hresult(CreateXmlReader(
            __uuidof(IXmlReader),
            reinterpret_cast<void**>(put_abi(reader)),
            0));

        winrt::check_hresult(reader->SetInput(get_abi(stream)));
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

    inline void add_winmds_from_sdk(std::vector<std::wstring>& winmd_specs, std::wstring version)
    {
        try
        {
            std::experimental::filesystem::path const sdk_path = get_sdk_path();
            bool const include_extensions = version.back() == L'+';

            if (include_extensions)
            {
                version.pop_back();
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
        catch (winrt::hresult_error const& e)
        {
            throw invalid_usage{ L"Could not find Windows SDK: ", std::wstring(e.message()), e.code() };
        }
    }
}
