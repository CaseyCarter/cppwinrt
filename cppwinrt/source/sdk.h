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

    inline void add_winmds_from_sdk(std::vector<std::wstring>& winmd_specs, std::wstring const& version)
    {
        try
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

            std::experimental::filesystem::path path = root;
            path /= L"Platforms\\UAP";
            path /= version;
            path /= L"Platform.xml";

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

                path = root;
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
        catch (winrt::hresult_error const& e)
        {
            throw invalid_usage{ L"Could not find Windows SDK: ", std::wstring(e.message()), e.code() };
        }
    }
}
