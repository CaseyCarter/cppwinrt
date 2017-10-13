
namespace winrt::impl
{
    template <size_t Size, typename T, size_t... Index>
    constexpr std::array<T, Size> to_array(T const* value, std::index_sequence<Index...> const) noexcept
    {
        return { value[Index]... };
    }

    template <size_t Size>
    constexpr auto to_array(char const(&value)[Size]) noexcept
    {
        return to_array<Size - 1>(value, std::make_index_sequence<Size - 1>());
    }

    template <size_t Size>
    constexpr auto to_array(wchar_t const(&value)[Size]) noexcept
    {
        return to_array<Size - 1>(value, std::make_index_sequence<Size - 1>());
    }

    template <typename T, size_t LeftSize, size_t RightSize, size_t ... LeftIndex, size_t ... RightIndex>
    constexpr std::array<T, LeftSize + RightSize> concat(
        std::array<T, LeftSize> const& left,
        std::array<T, RightSize> const& right,
        std::index_sequence<LeftIndex ...> const,
        std::index_sequence<RightIndex ...> const) noexcept
    {
        return { left[LeftIndex] ..., right[RightIndex] ... };
    }

    template <typename T, size_t LeftSize, size_t RightSize>
    constexpr auto operator+(std::array<T, LeftSize> const& left, std::array<T, RightSize> const& right) noexcept
    {
        return concat(left, right, std::make_index_sequence<LeftSize>(), std::make_index_sequence<RightSize>());
    }

    template <typename T>
    constexpr T to_hex_digit(uint8_t value) noexcept
    {
        value &= 0xF;
        return value < 10 ? static_cast<T>('0') + value : static_cast<T>('a') + (value - 10);
    }

    template <typename T>
    constexpr std::array<T, 2> uint8_to_hex(uint8_t const value) noexcept
    {
        return { to_hex_digit<T>(value >> 4), to_hex_digit<T>(value & 0xF) };
    }

    template <typename T>
    constexpr auto uint16_to_hex(uint16_t value) noexcept
    {
        return uint8_to_hex<T>(static_cast<uint8_t>(value >> 8)) + uint8_to_hex<T>(value & 0xFF);
    }

    template <typename T>
    constexpr auto uint32_to_hex(uint32_t const value) noexcept
    {
        return uint16_to_hex<T>(value >> 16) + uint16_to_hex<T>(value & 0xFFFF);
    }

    template <typename T>
    constexpr auto guid_to_hex(GUID const& value) noexcept
    {
        constexpr std::array<T, 1> open{ static_cast<T>('{') };
        constexpr std::array<T, 1> dash{ static_cast<T>('-') };
        constexpr std::array<T, 1> close{ static_cast<T>('}') };

        return
            open +
            uint32_to_hex<T>(value.Data1) + dash +
            uint16_to_hex<T>(value.Data2) + dash +
            uint16_to_hex<T>(value.Data3) + dash +
            uint16_to_hex<T>(value.Data4[0] << 8 | value.Data4[1]) + dash +
            uint16_to_hex<T>(value.Data4[2] << 8 | value.Data4[3]) +
            uint16_to_hex<T>(value.Data4[4] << 8 | value.Data4[5]) +
            uint16_to_hex<T>(value.Data4[6] << 8 | value.Data4[7]) +
            close;
    }

    template <size_t Size>
    constexpr std::string_view to_string(std::array<char, Size> const& value) noexcept
    {
        return { value.data(), Size };
    }

    template <size_t Size>
    constexpr std::wstring_view to_wstring(std::array<wchar_t, Size> const& value) noexcept
    {
        return { value.data(), Size };
    }

    template <typename T>
    struct name
    {
        static constexpr auto value{ guid_to_hex<wchar_t>(guid_of<T>()) };
    };

    template <typename T>
    constexpr auto& name_v = name<T>::value;

    template <> struct name<::IAgileObject>
    {
        static constexpr auto & value{ L"IAgileObject" };
    };
}
