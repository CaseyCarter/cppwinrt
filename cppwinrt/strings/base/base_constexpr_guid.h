
namespace winrt::impl 
{
    template<size_t Size>
    using byte_array = constexpr_array<uint8_t, Size>;

    constexpr byte_array<4> to_byte_array(unsigned long value) noexcept
    {
        return byte_array<4> { { static_cast<uint8_t>(value & 0x000000ff), static_cast<uint8_t>((value & 0x0000ff00) >> 8), static_cast<uint8_t>((value & 0x00ff0000) >> 16), static_cast<uint8_t>((value & 0xff000000) >> 24) } };
    }

    constexpr uint32_t bytes_to_u4(uint8_t a, uint8_t b, uint8_t c, uint8_t d) noexcept
    {
        return (static_cast<uint32_t>(d) << 24) | (static_cast<uint32_t>(c) << 16) | (static_cast<uint32_t>(b) << 8) | static_cast<uint32_t>(a);
    }

    constexpr byte_array<2> to_byte_array(unsigned short value) noexcept
    {
        return byte_array<2> { { static_cast<uint8_t>(value & 0x00ff), static_cast<uint8_t>((value & 0xff00) >> 8) } };
    }

    constexpr uint16_t bytes_to_u2(uint8_t a, uint8_t b) noexcept
    {
        return (static_cast<uint32_t>(b) << 8) | static_cast<uint32_t>(a);
    }

    constexpr byte_array<16> to_byte_array(GUID const& value) noexcept
    {
        return concat(concat(concat(to_byte_array(value.Data1), to_byte_array(value.Data2)), to_byte_array(value.Data3)), to_array(value.Data4));
    }

    template <size_t Size>
    constexpr GUID bytes_to_guid(constexpr_array<uint8_t, Size> const& arr) noexcept
    {
        static_assert (Size >= 16, "buffer passed to define_guid must be at least 16 bytes long");
        return { bytes_to_u4(arr[0], arr[1], arr[2], arr[3]),
            bytes_to_u2(arr[4], arr[5]),
            bytes_to_u2(arr[6], arr[7]),
            { arr[8], arr[9], arr[10], arr[11], arr[12], arr[13], arr[14], arr[15] } };
    }

    constexpr unsigned long endian_swap(unsigned long value) noexcept
    {
        return (value & 0xFF000000) >> 24 | (value & 0x00FF0000) >> 8 | (value & 0x0000FF00) << 8 | (value & 0x000000FF) << 24;
    }

    constexpr unsigned short endian_swap(unsigned short value) noexcept
    {
        return (value & 0xFF00) >> 8 | (value & 0x00FF) << 8;
    }

    constexpr GUID endian_swap(GUID const& value) noexcept
    {
        return { endian_swap(value.Data1),
            endian_swap(value.Data2),
            endian_swap(value.Data3),
            { value.Data4[0], value.Data4[1], value.Data4[2], value.Data4[3], value.Data4[4], value.Data4[5], value.Data4[6], value.Data4[7] } };
    }

    template <size_t ... GuidIndex, size_t ... SigIndex, size_t Size>
    constexpr constexpr_array<uint8_t, Size + 15> create_guid_gen_buffer(std::index_sequence<GuidIndex ...>, std::index_sequence<SigIndex ...>, constexpr_array<uint8_t, 16> const & guid, constexpr_string<char, Size> const & sig) noexcept
    {
        return constexpr_array<uint8_t, Size + 15>{ {guid[GuidIndex] ..., static_cast<uint8_t>(sig[SigIndex]) ...}};
    }

    template <size_t Size>
    constexpr constexpr_array<uint8_t, Size + 15> create_guid_gen_buffer(GUID const & guid, constexpr_string<char, Size> const & str) noexcept
    {
        return create_guid_gen_buffer(std::make_index_sequence<16>{}, std::make_index_sequence<Size - 1>{}, to_byte_array(guid), str);
    }

    constexpr GUID set_named_guid_fields(GUID const & id) noexcept
    {
        return { id.Data1, id.Data2, static_cast<uint16_t>((id.Data3 & 0x0fff) | (5 << 12)),
        { static_cast<uint8_t>((id.Data4[0] & 0x3f) | 0x80), id.Data4[1], id.Data4[2], id.Data4[3], id.Data4[4], id.Data4[5], id.Data4[6], id.Data4[7] } };
    }

    template <size_t Size>
    constexpr GUID generate_guid(GUID const & namespace_guid, constexpr_string<char, Size> const & source_string) noexcept
    {
        auto big_endian_ns_guid = endian_swap(namespace_guid);
        auto buffer = create_guid_gen_buffer(big_endian_ns_guid, source_string);
        auto hash = calculate_sha1(buffer);
        auto big_endian_guid = bytes_to_guid(hash);
        auto little_endian_guid = endian_swap(big_endian_guid);
        return set_named_guid_fields(little_endian_guid);
    }

    constexpr bool compare_guids(GUID const & rguid1, GUID const & rguid2) noexcept
    {
        return rguid1.Data1 == rguid2.Data1 && rguid1.Data2 == rguid2.Data2 && rguid1.Data3 == rguid2.Data3 &&
            rguid1.Data4[0] == rguid2.Data4[0] &&
            rguid1.Data4[1] == rguid2.Data4[1] &&
            rguid1.Data4[2] == rguid2.Data4[2] &&
            rguid1.Data4[3] == rguid2.Data4[3] &&
            rguid1.Data4[4] == rguid2.Data4[4] &&
            rguid1.Data4[5] == rguid2.Data4[5] &&
            rguid1.Data4[6] == rguid2.Data4[6] &&
            rguid1.Data4[7] == rguid2.Data4[7];
    }

    constexpr char to_hex_char(uint8_t nibble) noexcept
    {
        auto n = nibble & 0xF;
        return static_cast<char>(n < 10 ? '0' + n : 'a' + (n - 10));
    }

    constexpr constexpr_string<char, 3> u1_to_hex_string(uint8_t _byte) noexcept
    {
        return make_constexpr_string({ to_hex_char(_byte >> 4), to_hex_char(_byte & 0xF), '\0' });
    }

    constexpr constexpr_string<char, 5> u2_to_hex_string(uint16_t _short) noexcept
    {
        return u1_to_hex_string(static_cast<uint8_t>(_short >> 8)) + u1_to_hex_string(_short & 0xFF);
    }

    constexpr constexpr_string<char, 9> u4_to_hex_string(uint32_t _int) noexcept
    {
        return u2_to_hex_string(_int >> 16) + u2_to_hex_string(_int & 0xFFFF);
    }

    // namespace guid needed by RFC 4122 and used by pinterface guid generation algorithm
    constexpr GUID pinterface_namespace_guid = { 0x11f47ad5, 0x7b73, 0x42c0,{ 0xab, 0xae, 0x87, 0x8b, 0x1e, 0x16, 0xad, 0xee } };

    template <typename TArg, typename ... TRest>
    struct arg_collection
    {
        constexpr static auto data{ make_constexpr_string(signature<TArg>::data) + ";" + arg_collection<TRest ...>::data };
    };

    template <typename TArg>
    struct arg_collection<TArg>
    {
        constexpr static auto data{ make_constexpr_string(signature<TArg>::data) };
    };

    constexpr constexpr_string<char, 39> guid_to_string(GUID const & id) noexcept
    {
        return "{" + u4_to_hex_string(id.Data1) +
            "-" + u2_to_hex_string(id.Data2) +
            "-" + u2_to_hex_string(id.Data3) +
            "-" + u2_to_hex_string((id.Data4[0] << 8) | id.Data4[1]) +
            "-" + u2_to_hex_string((id.Data4[2] << 8) | id.Data4[3]) +
            u2_to_hex_string((id.Data4[4] << 8) | id.Data4[5]) +
            u2_to_hex_string((id.Data4[6] << 8) | id.Data4[7]) +
            "}";
    }

    template <typename T>
    struct pinterface_guid
    {
#pragma warning(suppress: 4307)
        static constexpr GUID value{ generate_guid(pinterface_namespace_guid, signature<T>::data) };
    };
}

