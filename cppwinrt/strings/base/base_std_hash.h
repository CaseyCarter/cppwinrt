
namespace winrt::impl
{
    inline size_t hash_data(const void* ptr, size_t numBytes) noexcept
    {
#ifdef WINRT_64
        constexpr size_t fnv_offset_basis = 14695981039346656037ULL;
        constexpr size_t fnv_prime = 1099511628211ULL;
#else
        constexpr size_t fnv_offset_basis = 2166136261U;
        constexpr size_t fnv_prime = 16777619U;
#endif
        size_t result = fnv_offset_basis;
        const uint8_t* const buffer = static_cast<const uint8_t*>(ptr);
        for (size_t next = 0; next < numBytes; ++next)
        {
            result ^= buffer[next];
            result *= fnv_prime;
        }
        return result;
    }

    inline size_t hash_unknown(const Windows::Foundation::IUnknown& value) noexcept
    {
        ::IUnknown* abi_value = nullptr;
        if (value)
        {
            abi_value = get_abi(value.as<Windows::Foundation::IUnknown>());
        }
        return std::hash<::IUnknown*>{}(abi_value);
    }

    template<typename T>
    struct impl_hash_unknown
    {
        size_t operator()(const T& value) const noexcept
        {
            return winrt::impl::hash_unknown(value);
        }
    };
}

WINRT_EXPORT namespace std
{
    template<> struct hash<winrt::hstring>
    {
        size_t operator()(const winrt::hstring& value) const noexcept
        {
            uint32_t length = 0;
            const wchar_t* const buffer = WindowsGetStringRawBuffer(get_abi(value), &length);
            return winrt::impl::hash_data(buffer, length * sizeof(wchar_t));
        }
    };
}
