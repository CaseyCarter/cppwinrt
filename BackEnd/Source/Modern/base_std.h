
namespace std {

template <> struct hash<winrt::hstring> : unary_function<winrt::hstring, size_t>
{
    size_t operator()(winrt::hstring const & value) const noexcept
    {
        uint32_t length = 0;
        wchar_t const * const buffer = WindowsGetStringRawBuffer(get(value), &length);

        return _Hash_seq(reinterpret_cast<const unsigned char *>(buffer), length * sizeof(wchar_t));
    }
};

}
