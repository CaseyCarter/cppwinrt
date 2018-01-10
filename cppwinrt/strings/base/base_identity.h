
namespace winrt::impl
{
    template <size_t Size, typename T, size_t... Index>
    constexpr std::array<T, Size> to_array(T const* value, std::index_sequence<Index...> const) noexcept
    {
        return { value[Index]... };
    }

    template <typename T, size_t Size>
    constexpr auto to_array(std::array<T, Size> const& value) noexcept
    {
        return value;
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

    template <typename T, size_t LeftSize, size_t RightSize, size_t... LeftIndex, size_t... RightIndex>
    constexpr std::array<T, LeftSize + RightSize> concat(
        [[maybe_unused]] std::array<T, LeftSize> const& left,
        [[maybe_unused]] std::array<T, RightSize> const& right,
        std::index_sequence<LeftIndex...> const,
        std::index_sequence<RightIndex...> const) noexcept
    {
        return { left[LeftIndex]..., right[RightIndex]... };
    }

    template <typename T, size_t LeftSize, size_t RightSize>
    constexpr auto operator+(std::array<T, LeftSize> const& left, std::array<T, RightSize> const& right) noexcept
    {
        return concat(left, right, std::make_index_sequence<LeftSize>(), std::make_index_sequence<RightSize>());
    }

    template <typename T, size_t LeftSize, size_t RightSize>
    constexpr auto operator+(std::array<T, LeftSize> const& left, T const(&right)[RightSize]) noexcept
    {
        return left + to_array(right);
    }

    template <typename T, size_t LeftSize, size_t RightSize>
    constexpr auto operator+(T const(&left)[LeftSize], std::array<T, RightSize> const& right) noexcept
    {
        return to_array(left) + right;
    }

    template <typename T, size_t LeftSize>
    constexpr auto operator+(std::array<T, LeftSize> const& left, T const right) noexcept
    {
        return left + std::array<T, 1>{right};
    }

    template <typename T, size_t RightSize>
    constexpr auto operator+(T const left, std::array<T, RightSize> const& right) noexcept
    {
        return std::array<T, 1>{left} + right;
    }

    constexpr std::array<uint8_t, 4> to_array(unsigned long value) noexcept
    {
        return { static_cast<uint8_t>(value & 0x000000ff), static_cast<uint8_t>((value & 0x0000ff00) >> 8), static_cast<uint8_t>((value & 0x00ff0000) >> 16), static_cast<uint8_t>((value & 0xff000000) >> 24) };
    }

    constexpr std::array<uint8_t, 2> to_array(unsigned short value) noexcept
    {
        return { static_cast<uint8_t>(value & 0x00ff), static_cast<uint8_t>((value & 0xff00) >> 8) };
    }

    constexpr auto to_array(GUID const& value) noexcept
    {
        return to_array(value.Data1) + to_array(value.Data2) + to_array(value.Data3) +
            std::array<uint8_t, 8>{ value.Data4[0], value.Data4[1], value.Data4[2], value.Data4[3], value.Data4[4], value.Data4[5], value.Data4[6], value.Data4[7] };
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
    constexpr auto to_array(GUID const& value) noexcept
    {
        return
            static_cast<T>('{') +
            uint32_to_hex<T>(value.Data1) + static_cast<T>('-') +
            uint16_to_hex<T>(value.Data2) + static_cast<T>('-') +
            uint16_to_hex<T>(value.Data3) + static_cast<T>('-') +
            uint16_to_hex<T>(value.Data4[0] << 8 | value.Data4[1]) + static_cast<T>('-') +
            uint16_to_hex<T>(value.Data4[2] << 8 | value.Data4[3]) +
            uint16_to_hex<T>(value.Data4[4] << 8 | value.Data4[5]) +
            uint16_to_hex<T>(value.Data4[6] << 8 | value.Data4[7]) +
            static_cast<T>('}');
    }

    constexpr uint32_t to_guid(uint8_t a, uint8_t b, uint8_t c, uint8_t d) noexcept
    {
        return (static_cast<uint32_t>(d) << 24) | (static_cast<uint32_t>(c) << 16) | (static_cast<uint32_t>(b) << 8) | static_cast<uint32_t>(a);
    }

    constexpr uint16_t to_guid(uint8_t a, uint8_t b) noexcept
    {
        return (static_cast<uint32_t>(b) << 8) | static_cast<uint32_t>(a);
    }

    template <size_t Size>
    constexpr GUID to_guid(std::array<uint8_t, Size> const& arr) noexcept
    {
        return
        {
            to_guid(arr[0], arr[1], arr[2], arr[3]),
            to_guid(arr[4], arr[5]),
            to_guid(arr[6], arr[7]),
            { arr[8], arr[9], arr[10], arr[11], arr[12], arr[13], arr[14], arr[15] }
        };
    }

    template <typename T>
    struct name
    {
#pragma warning(suppress: 4307)
        static constexpr auto value{ to_array<wchar_t>(guid_of<T>()) };
    };

    template <typename T>
    constexpr auto& name_v = name<T>::value;

    template <typename T, size_t Size>
    constexpr std::basic_string_view<T> to_string(std::array<T, Size> const& value) noexcept
    {
        return { value.data(), Size };
    }

    template <typename T, size_t Size>
    constexpr std::wstring_view to_string(T const (&value)[Size]) noexcept
    {
        return { value, Size - 1 };
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
        return
        {
            endian_swap(value.Data1),
            endian_swap(value.Data2),
            endian_swap(value.Data3),
            { value.Data4[0], value.Data4[1], value.Data4[2], value.Data4[3], value.Data4[4], value.Data4[5], value.Data4[6], value.Data4[7] }
        };
    }

    constexpr GUID set_named_guid_fields(GUID value) noexcept
    {
        value.Data3 = static_cast<uint16_t>((value.Data3 & 0x0fff) | (5 << 12));
        value.Data4[0] = static_cast<uint8_t>((value.Data4[0] & 0x3f) | 0x80);
        return value;
    }

    template <typename T, size_t Size, size_t... Index>
    constexpr std::array<uint8_t, Size> char_to_byte_array(std::array<T, Size> const& value, std::index_sequence<Index...> const) noexcept
    {
        return { static_cast<uint8_t>(value[Index])... };
    }

    constexpr auto sha1_rotl(uint8_t bits, uint32_t word) noexcept
    {
        return  (word << bits) | (word >> (32 - bits));
    }

    constexpr auto sha_ch(uint32_t x, uint32_t y, uint32_t z) noexcept
    {
        return (x & y) ^ ((~x) & z);
    }

    constexpr auto sha_parity(uint32_t x, uint32_t y, uint32_t z) noexcept
    {
        return x ^ y ^ z;
    }

    constexpr auto sha_maj(uint32_t x, uint32_t y, uint32_t z) noexcept
    {
        return (x & y) ^ (x & z) ^ (y & z);
    }

    template <size_t Size>
    constexpr std::array<uint32_t, 5> process_msg_block(std::array<uint8_t, Size> const& input, uint32_t start_pos, std::array<uint32_t, 5> const& intermediate_hash) noexcept
    {
        uint32_t const K[4] = { 0x5A827999, 0x6ED9EBA1, 0x8F1BBCDC, 0xCA62C1D6 };
        std::array<uint32_t, 80> W = {};

        int t = 0;
        uint32_t temp = 0;

        for (t = 0; t < 16; t++)
        {
            W[t] = static_cast<uint32_t>(input[start_pos + t * 4]) << 24;
            W[t] = W[t] | static_cast<uint32_t>(input[start_pos + t * 4 + 1]) << 16;
            W[t] = W[t] | static_cast<uint32_t>(input[start_pos + t * 4 + 2]) << 8;
            W[t] = W[t] | static_cast<uint32_t>(input[start_pos + t * 4 + 3]);
        }

        for (t = 16; t < 80; t++)
        {
            W[t] = sha1_rotl(1, W[t - 3] ^ W[t - 8] ^ W[t - 14] ^ W[t - 16]);
        }

        uint32_t A = intermediate_hash[0];
        uint32_t B = intermediate_hash[1];
        uint32_t C = intermediate_hash[2];
        uint32_t D = intermediate_hash[3];
        uint32_t E = intermediate_hash[4];

        for (t = 0; t < 20; t++)
        {
            temp = sha1_rotl(5, A) + sha_ch(B, C, D) + E + W[t] + K[0];
            E = D;
            D = C;
            C = sha1_rotl(30, B);
            B = A;
            A = temp;
        }

        for (t = 20; t < 40; t++)
        {
            temp = sha1_rotl(5, A) + sha_parity(B, C, D) + E + W[t] + K[1];
            E = D;
            D = C;
            C = sha1_rotl(30, B);
            B = A;
            A = temp;
        }

        for (t = 40; t < 60; t++)
        {
            temp = sha1_rotl(5, A) + sha_maj(B, C, D) + E + W[t] + K[2];
            E = D;
            D = C;
            C = sha1_rotl(30, B);
            B = A;
            A = temp;
        }

        for (t = 60; t < 80; t++)
        {
            temp = sha1_rotl(5, A) + sha_parity(B, C, D) + E + W[t] + K[3];
            E = D;
            D = C;
            C = sha1_rotl(30, B);
            B = A;
            A = temp;
        }

        return { intermediate_hash[0] + A, intermediate_hash[1] + B, intermediate_hash[2] + C, intermediate_hash[3] + D, intermediate_hash[4] + E };
    }

    constexpr std::array<uint8_t, 8> size_to_bytes(size_t size) noexcept
    {
        return
        {
            static_cast<uint8_t>((size & 0xff00000000000000) >> 56),
            static_cast<uint8_t>((size & 0x00ff000000000000) >> 48),
            static_cast<uint8_t>((size & 0x0000ff0000000000) >> 40),
            static_cast<uint8_t>((size & 0x000000ff00000000) >> 32),
            static_cast<uint8_t>((size & 0x00000000ff000000) >> 24),
            static_cast<uint8_t>((size & 0x0000000000ff0000) >> 16),
            static_cast<uint8_t>((size & 0x000000000000ff00) >> 8),
            static_cast<uint8_t>((size & 0x00000000000000ff) >> 0)
        };
    }

    template <size_t Size, size_t RemainingSize, size_t... Index>
    constexpr std::array<uint8_t, RemainingSize + 1> make_remaining(std::array<uint8_t, Size> const& input, uint32_t start_pos, std::index_sequence<Index...>) noexcept
    {
        return { input[Index + start_pos]..., 0x80 };
    }

    template <size_t Size>
    constexpr auto make_remaining(std::array<uint8_t, Size> const& input, uint32_t start_pos) noexcept
    {
        constexpr auto remaining_size = Size % 64;
        return make_remaining<Size, remaining_size>(input, start_pos, std::make_index_sequence<remaining_size>());
    }

    template <size_t InputSize, size_t RemainderSize>
    constexpr auto make_buffer(std::array<uint8_t, RemainderSize> const& remaining_buffer) noexcept
    {
        constexpr auto message_length = (RemainderSize + 8 <= 64) ? 64 : 64 * 2;
        constexpr auto padding_length = message_length - RemainderSize - 8;

        auto padding_buffer = std::array<uint8_t, padding_length>{};
        auto length_buffer = size_to_bytes(InputSize * 8);

        return remaining_buffer + padding_buffer + length_buffer;
    }

    template <size_t Size>
    constexpr std::array<uint32_t, 5> finalize_remaining_buffer(std::array<uint8_t, Size> const& input, std::array<uint32_t, 5> const& intermediate_hash) noexcept
    {
        if constexpr (Size == 64)
        {
            return process_msg_block(input, 0, intermediate_hash);
        }
        else if constexpr (Size == 64 * 2)
        {
            return process_msg_block(input, 64, process_msg_block(input, 0, intermediate_hash));
        }
    }

    template <size_t... Index>
    constexpr std::array<uint8_t, 20> get_result(std::array<uint32_t, 5> const& intermediate_hash, std::index_sequence<Index...>) noexcept
    {
        return { static_cast<uint8_t>(intermediate_hash[Index >> 2] >> (8 * (3 - (Index & 0x03))))... };
    }

    constexpr auto get_result(std::array<uint32_t, 5> const& intermediate_hash) noexcept
    {
        return get_result(intermediate_hash, std::make_index_sequence<20>{});
    }

    template <size_t Size>
    constexpr auto calculate_sha1(std::array<uint8_t, Size> const& input) noexcept
    {
        std::array<uint32_t, 5> intermediate_hash{ 0x67452301, 0xEFCDAB89, 0x98BADCFE, 0x10325476, 0xC3D2E1F0 };
        uint32_t i = 0;

        while (i + 64 <= Size)
        {
            intermediate_hash = process_msg_block(input, i, intermediate_hash);
            i += 64;
        }

        intermediate_hash = finalize_remaining_buffer(make_buffer<Size>(make_remaining(input, i)), intermediate_hash);
        return get_result(intermediate_hash);
    }

    template <size_t Size>
    constexpr GUID generate_guid(std::array<char, Size> const& value) noexcept
    {
        GUID namespace_guid = { 0xd57af411, 0x737b, 0xc042,{ 0xab, 0xae, 0x87, 0x8b, 0x1e, 0x16, 0xad, 0xee } };

        auto buffer = to_array(namespace_guid) + char_to_byte_array(value, std::make_index_sequence<Size>());
        auto hash = calculate_sha1(buffer);
        auto big_endian_guid = to_guid(hash);
        auto little_endian_guid = endian_swap(big_endian_guid);
        return set_named_guid_fields(little_endian_guid);
    }

    template <typename TArg, typename... TRest>
    struct arg_collection
    {
        constexpr static auto data{ to_array(signature<TArg>::data) + ";" + arg_collection<TRest...>::data };
    };

    template <typename TArg>
    struct arg_collection<TArg>
    {
        constexpr static auto data{ to_array(signature<TArg>::data) };
    };

    template <typename T>
    struct pinterface_guid
    {
#pragma warning(suppress: 4307)
        static constexpr GUID value{ generate_guid(signature<T>::data) };
    };

    constexpr size_t to_utf8_size(wchar_t const value) noexcept
    {
        if (value <= 0x7F)
        {
            return 1;
        }

        if (value <= 0x7FF)
        {
            return 2;
        }

        return 3;
    }

    constexpr size_t to_utf8(wchar_t const value, char* buffer) noexcept
    {
        if (value <= 0x7F)
        {
            *buffer = static_cast<char>(value);
            return 1;
        }

        if (value <= 0x7FF)
        {
            *buffer = static_cast<char>(0xC0 | (value >> 6));
            *(buffer + 1) = 0x80 | (value & 0x3F);
            return 2;
        }

        *buffer = 0xE0 | (value >> 12);
        *(buffer + 1) = 0x80 | ((value >> 6) & 0x3F);
        *(buffer + 2) = 0x80 | (value & 0x3F);
        return 3;
    }

    template <typename T>
    constexpr size_t to_utf8_size() noexcept
    {
        auto input = to_array(name_v<T>);
        size_t length = 0;

        for (wchar_t const element : input)
        {
            length += to_utf8_size(element);
        }

        return length;
    }

    template <typename T>
    constexpr auto to_utf8() noexcept
    {
        auto input = to_array(name_v<T>);
        std::array<char, to_utf8_size<T>()> output{};
        size_t offset{};

        for (wchar_t const element : input)
        {
            offset += to_utf8(element, &output[offset]);
        }

        return output;
    }

    template <>
    struct name<bool>
    {
        static constexpr auto & value{ L"Boolean" };
        static constexpr auto & data{ "b1" };
    };

    template <>
    struct category<bool>
    {
        using type = basic_category;
    };

    template <>
    struct name<int8_t>
    {
        static constexpr auto & value{ L"Int8" };
        static constexpr auto & data{ "i1" };
    };

    template <>
    struct category<int8_t>
    {
        using type = basic_category;
    };

    template <>
    struct name<int16_t>
    {
        static constexpr auto & value{ L"Int16" };
        static constexpr auto & data{ "i2" };
    };

    template <>
    struct category<int16_t>
    {
        using type = basic_category;
    };

    template <>
    struct name<int32_t>
    {
        static constexpr auto & value{ L"Int32" };
        static constexpr auto & data{ "i4" };
    };

    template <>
    struct category<int32_t>
    {
        using type = basic_category;
    };

    template <>
    struct name<int64_t>
    {
        static constexpr auto & value{ L"Int64" };
        static constexpr auto & data{ "i8" };
    };

    template <>
    struct category<int64_t>
    {
        using type = basic_category;
    };

    template <>
    struct name<uint8_t>
    {
        static constexpr auto & value{ L"UInt8" };
        static constexpr auto & data{ "u1" };
    };

    template <>
    struct category<uint8_t>
    {
        using type = basic_category;
    };

    template <>
    struct name<uint16_t>
    {
        static constexpr auto & value{ L"UInt16" };
        static constexpr auto & data{ "u2" };
    };

    template <>
    struct category<uint16_t>
    {
        using type = basic_category;
    };

    template <>
    struct name<uint32_t>
    {
        static constexpr auto & value{ L"UInt32" };
        static constexpr auto & data{ "u4" };
    };

    template <>
    struct category<uint32_t>
    {
        using type = basic_category;
    };

    template <>
    struct name<uint64_t>
    {
        static constexpr auto & value{ L"UInt64" };
        static constexpr auto & data{ "u8" };
    };

    template <>
    struct category<uint64_t>
    {
        using type = basic_category;
    };

    template <>
    struct name<float>
    {
        static constexpr auto & value{ L"Single" };
        static constexpr auto & data{ "f4" };
    };

    template <>
    struct category<float>
    {
        using type = basic_category;
    };

    template <>
    struct name<double>
    {
        static constexpr auto & value{ L"Double" };
        static constexpr auto & data{ "f8" };
    };

    template <>
    struct category<double>
    {
        using type = basic_category;
    };

    template <>
    struct name<char16_t>
    {
        static constexpr auto & value{ L"Char16" };
        static constexpr auto & data{ "c2" };
    };

    template <>
    struct category<char16_t>
    {
        using type = basic_category;
    };

    template <>
    struct name<GUID>
    {
        static constexpr auto & value{ L"Guid" };
        static constexpr auto & data{ "g16" };
    };

    template <>
    struct category<GUID>
    {
        using type = basic_category;
    };

    template <>
    struct name<HRESULT>
    {
        static constexpr auto & value{ L"Windows.Foundation.HResult" };
    };

    template <>
    struct category<HRESULT>
    {
        using type = struct_category<int32_t>;
    };

    template <>
    struct name<event_token>
    {
        static constexpr auto & value{ L"Windows.Foundation.EventRegistrationToken" };
    };

    template <>
    struct category<event_token>
    {
        using type = struct_category<int64_t>;
    };

    template <typename T>
    struct category_signature<basic_category, T>
    {
        constexpr static auto data{ to_array(name<T>::data) };
    };

    template <typename T>
    struct category_signature<enum_category, T>
    {
        using enum_type = std::underlying_type_t<T>;
        constexpr static auto data{ "enum(" + to_utf8<T>() + ";" + signature<enum_type>::data + ")" };
    };

    template <typename... Fields, typename T>
    struct category_signature<struct_category<Fields...>, T>
    {
        constexpr static auto data{ "struct(" + to_utf8<T>() + ";" + arg_collection<Fields...>::data + ")" };
    };

    template <typename T>
    struct category_signature<class_category, T>
    {
        constexpr static auto data{ "rc(" + to_utf8<T>() + ";" + signature<default_interface_t<T>>::data + ")" };
    };

    template <typename... Args, typename T>
    struct category_signature<pinterface_category<Args...>, T>
    {
        constexpr static auto data{ "pinterface(" + to_array<char>(category<T>::value) + ";" + arg_collection<Args...>::data + ")" };
    };

    template <typename T>
    struct category_signature<interface_category, T>
    {
        constexpr static auto data{ to_array<char>(guid_of<T>()) };
    };

    template <typename T>
    struct category_signature<delegate_category, T>
    {
        constexpr static auto data{ "delegate(" + to_array<char>(guid_of<T>()) + ")" };
    };
}

namespace winrt
{
    template <typename T>
    constexpr std::wstring_view name_of() noexcept
    {
        return impl::to_string(impl::name_v<T>);
    }
}
