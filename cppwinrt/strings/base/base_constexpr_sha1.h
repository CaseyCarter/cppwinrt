
namespace winrt::impl
{
    // SHA-1 constexpr implementation. Port of C Reference from https://tools.ietf.org/html/rfc3174 using constexpr.

    constexpr auto message_block_size = 64;
    constexpr auto hash_size = 20;

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

    constexpr uint32_t K[4] = { 0x5A827999, 0x6ED9EBA1, 0x8F1BBCDC, 0xCA62C1D6 };

    template <size_t Size>
    constexpr auto process_msg_block(constexpr_array<uint8_t, Size> const & input, uint32_t start_pos, constexpr_array<uint32_t, 5> const & intermediate_hash
#if _MSC_FULL_VER < 191125303
        , constexpr_array<uint32_t, 80> W = {}
#endif
    ) noexcept {
#if _MSC_FULL_VER >= 191125303
        constexpr_array<uint32_t, 80> W = {};
#endif

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

        return constexpr_array<uint32_t, 5> { { intermediate_hash[0] + A, intermediate_hash[1] + B, intermediate_hash[2] + C, intermediate_hash[3] + D, intermediate_hash[4] + E } };
    }

    constexpr auto size_to_bytes(size_t size) noexcept
    {
        return constexpr_array<uint8_t, 8> { {
                static_cast<uint8_t>((size & 0xff00000000000000) >> 56),
                static_cast<uint8_t>((size & 0x00ff000000000000) >> 48),
                static_cast<uint8_t>((size & 0x0000ff0000000000) >> 40),
                static_cast<uint8_t>((size & 0x000000ff00000000) >> 32),
                static_cast<uint8_t>((size & 0x00000000ff000000) >> 24),
                static_cast<uint8_t>((size & 0x0000000000ff0000) >> 16),
                static_cast<uint8_t>((size & 0x000000000000ff00) >> 8),
                static_cast<uint8_t>((size & 0x00000000000000ff) >> 0) 
            } };
    }

    template <size_t Size, size_t RemainingSize, size_t ... Index>
    constexpr constexpr_array<uint8_t, RemainingSize + 1> make_remaining(constexpr_array<uint8_t, Size> const & input, uint32_t start_pos, std::index_sequence<Index ...>) noexcept
    {
        return constexpr_array<uint8_t, RemainingSize + 1>{ {input[Index + start_pos] ..., 0x80}};
    }

    template <size_t Size>
    constexpr auto make_remaining(constexpr_array<uint8_t, Size> const & input, uint32_t start_pos) noexcept
    {
        constexpr auto remaining_size = Size % message_block_size;
        return make_remaining<Size, remaining_size>(input, start_pos, std::make_index_sequence<remaining_size>());
    }

    template <size_t InputSize, size_t RemainderSize>
    constexpr auto make_buffer(constexpr_array<uint8_t, RemainderSize> const & remaining_buffer) noexcept
    {
#pragma warning(suppress: 6326)
        constexpr auto message_length = (RemainderSize + 8 <= message_block_size) ? message_block_size : message_block_size * 2;
        constexpr auto padding_length = message_length - RemainderSize - 8;

        auto padding_buffer = constexpr_array<uint8_t, padding_length>{};
        auto length_buffer = size_to_bytes(InputSize * 8);

        return concat(concat(remaining_buffer, padding_buffer), length_buffer);
    }

    template <size_t Size>
    constexpr constexpr_array<uint32_t, 5> finalize_remaining_buffer(constexpr_array<uint8_t, Size> const & input, constexpr_array<uint32_t, 5> const & intermediate_hash) noexcept
    {
        throw std::invalid_argument("Size");
        return intermediate_hash;
    }

    template <>
    constexpr constexpr_array<uint32_t, 5> finalize_remaining_buffer<message_block_size>(constexpr_array<uint8_t, message_block_size> const & input, constexpr_array<uint32_t, 5> const & intermediate_hash) noexcept
    {
        return process_msg_block(input, 0, intermediate_hash);
    }

    template <>
    constexpr constexpr_array<uint32_t, 5> finalize_remaining_buffer<message_block_size * 2>(constexpr_array<uint8_t, message_block_size * 2> const & input, constexpr_array<uint32_t, 5> const & intermediate_hash) noexcept
    {
        return process_msg_block(input, message_block_size, process_msg_block(input, 0, intermediate_hash));
    }

    template <size_t Size>
    constexpr auto finalize_msg(constexpr_array<uint8_t, Size> const & input, uint32_t start_pos, constexpr_array<uint32_t, 5> const & intermediate_hash) noexcept
    {
        return finalize_remaining_buffer(make_buffer<Size>(make_remaining(input, start_pos)), intermediate_hash);
    }

    template <size_t ... Index>
    constexpr constexpr_array<uint8_t, hash_size> get_result(constexpr_array<uint32_t, 5> const & intermediate_hash, std::index_sequence<Index ...>) noexcept
    {
        return constexpr_array<uint8_t, hash_size>{ {static_cast<uint8_t>(intermediate_hash[Index >> 2] >> (8 * (3 - (Index & 0x03)))) ...}};
    }

    constexpr auto get_result(constexpr_array<uint32_t, 5> const & intermediate_hash) noexcept
    {
        return get_result(intermediate_hash, std::make_index_sequence<hash_size>{});
    }

    constexpr auto initalize_intermediate_hash() noexcept
    {
        return constexpr_array<uint32_t, 5> { { 0x67452301, 0xEFCDAB89, 0x98BADCFE, 0x10325476, 0xC3D2E1F0 }};
    }

    template <size_t Size>
    constexpr constexpr_array<uint8_t, hash_size> calculate_sha1(constexpr_array<uint8_t, Size> const & input) noexcept
    {
        auto intermediate_hash = initalize_intermediate_hash();
        uint32_t i = 0;

        while (i + message_block_size <= Size)
        {
            intermediate_hash = process_msg_block<Size>(input, i, intermediate_hash);
            i += message_block_size;
        }

        intermediate_hash = finalize_msg<Size>(input, i, intermediate_hash);
        return get_result(intermediate_hash);
    }
}
