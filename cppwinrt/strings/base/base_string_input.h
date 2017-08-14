
WINRT_EXPORT namespace winrt::param
{
    struct hstring
    {
        hstring(std::nullptr_t = nullptr) noexcept : m_handle(nullptr) {}
        hstring(hstring const& values) = delete;
        hstring& operator=(hstring const& values) = delete;

        hstring(winrt::hstring const& value) : m_handle(get_abi(value))
        {
        }

        hstring(std::wstring_view const& value)
        {
            WINRT_VERIFY_(S_OK, WindowsCreateStringReference(value.data(), static_cast<uint32_t>(value.size()), &m_header, &m_handle));
        }

        hstring(std::wstring const& value) : hstring(std::wstring_view(value))
        {
        }

        hstring(wchar_t const* const value) : hstring(std::wstring_view(value))
        {
        }

    private:

        HSTRING m_handle;
        HSTRING_HEADER m_header;
    };

    inline HSTRING get_abi(hstring const& object) noexcept
    {
        return *(HSTRING*)(&object);
    }
}
