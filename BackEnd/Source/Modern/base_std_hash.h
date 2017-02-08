
namespace std {

template <> struct hash<winrt::hstring>
{
    size_t operator()(const winrt::hstring & value) const noexcept
    {
#ifdef WINRT_64
        const size_t fnv_offset_basis = 14695981039346656037ULL;
        const size_t fnv_prime = 1099511628211ULL;
#else
        const size_t fnv_offset_basis = 2166136261U;
        const size_t fnv_prime = 16777619U;
#endif

        uint32_t length = 0;

        const uint8_t * const buffer = reinterpret_cast<const uint8_t *>(WindowsGetStringRawBuffer(get_abi(value),
                                                                                                   &length));

        length *= sizeof(wchar_t);
        size_t result = fnv_offset_basis;

        for (size_t next = 0; next < length; ++next)
        {
            result ^= buffer[next];
            result *= fnv_prime;
        }

        return result;
    }
};

}
