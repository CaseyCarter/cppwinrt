
namespace impl 
{
    constexpr size_t bytes_needed(wchar_t const & ch)
    {
        if (ch <= 0x7F)
        {
            return 1;
        }

        if (ch <= 0x7FF)
        {
            return 2;
        }

        return 3;
    }

    template <size_t Size>
    constexpr size_t utf8_name_length(wchar_t const (&str)[Size])
    {
        size_t length = 0;

        for (size_t index = 0; index < Size; index++)
        {
            length += bytes_needed(str[index]);
        }

        return length;
    }

    template <size_t Size>
    constexpr size_t utf8_name_length(constexpr_string<wchar_t, Size> const & str)
    {
        return utf8_name_length(str.elems_);
    }

    constexpr size_t wchar_to_utf8(wchar_t const & ch, char * buf)
    {
        if (ch <= 0x7F)
        {
            *buf = static_cast<char>(ch);
            return 1;
        }

        if (ch <= 0x7FF)
        {
            *buf = static_cast<char>(0xC0 | (ch >> 6));
            *(buf + 1) = 0x80 | (ch & 0x3F);
            return 2;
        }

        *buf = 0xE0 | (ch >> 12);
        *(buf + 1) = 0x80 | ((ch >> 6) & 0x3F);
        *(buf + 2) = 0x80 | (ch & 0x3F);
        return 3;
    }

    template <size_t Utf8Size, size_t Size>
    constexpr auto wchar_string_to_utf8(wchar_t const (&str)[Size])
    {
        char utf8[Utf8Size] = {};
        size_t utf8_index = 0;

        for (size_t index = 0; index < Size; index++)
        {
            utf8_index += wchar_to_utf8(str[index], &utf8[utf8_index]);
        }

        return make_constexpr_string(utf8);
    }

    template <size_t Utf8Size, size_t Size>
    constexpr auto wchar_string_to_utf8(constexpr_string<wchar_t, Size> const & str)
    {
        return wchar_string_to_utf8<Utf8Size>(str.elems_);
    }

    template <typename T>
    struct name_utf8
    {
        constexpr static auto value{ wchar_string_to_utf8<utf8_name_length(name_v<T>)>(name_v<T>) };
    };

    template <typename T>
    constexpr auto & name_utf8_v = name_utf8<T>::value;

    template <>
    struct name<bool>
    {
        static constexpr auto & value { L"Boolean" };
        static constexpr auto & data { "b1" };
    };

    template <>
    struct category<bool>
    {
        using type = basic_category;
    };

    template <>
    struct name<int16_t>
    {
        static constexpr auto & value { L"Int16" };
        static constexpr auto & data { "i2" };
    };

    template <>
    struct category<int16_t>
    {
        using type = basic_category;
    };

    template <>
    struct name<int32_t>
    {
        static constexpr auto & value { L"Int32" };
        static constexpr auto & data { "i4" };
    };

    template <>
    struct category<int32_t>
    {
        using type = basic_category;
    };

    template <>
    struct name<int64_t>
    {
        static constexpr auto & value { L"Int64" };
        static constexpr auto & data { "i8" };
    };

    template <>
    struct category<int64_t>
    {
        using type = basic_category;
    };

    template <>
    struct name<uint8_t>
    {
        static constexpr auto & value { L"UInt8" };
        static constexpr auto & data { "u1" };
    };

    template <>
    struct category<uint8_t>
    {
        using type = basic_category;
    };

    template <>
    struct name<uint16_t>
    {
        static constexpr auto & value { L"UInt16" };
        static constexpr auto & data { "u2" };
    };

    template <>
    struct category<uint16_t>
    {
        using type = basic_category;
    };

    template <>
    struct name<uint32_t>
    {
        static constexpr auto & value { L"UInt32" };
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
        static constexpr auto & value { L"UInt64" };
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
        static constexpr auto & value { L"Single" };
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
        static constexpr auto & value { L"Double" };
        static constexpr auto & data{ "f8" };
    };

    template <>
    struct category<double>
    {
        using type = basic_category;
    };

    template <>
    struct name<wchar_t>
    {
        static constexpr auto & value { L"Char16" };
        static constexpr auto & data{ "c2" };
    };

    template <>
    struct category<wchar_t>
    {
        using type = basic_category;
    };

    template <>
    struct name<GUID>
    {
        static constexpr auto & value { L"Guid" };
        static constexpr auto & data{ "g16" };
    };

    template <>
    struct category<GUID>
    {
        using type = basic_category;
    };

    template <typename T>
    struct category_signature<basic_category, T>
    {
        constexpr static auto data { make_constexpr_string(name<T>::data) };
    };

    template <typename T>
    struct category_signature<enum_category, T>
    {
        using enum_type = std::underlying_type_t<T>;
        constexpr static auto data{ "enum(" + name_utf8_v<T> + ";" + signature<enum_type>::data + ")" };
    };

    template <typename ... Fields, typename T>
    struct category_signature<struct_category<Fields ...>, T>
    {
        constexpr static auto data { "struct(" + name_utf8_v<T>+ ";" + arg_collection<Fields ...>::data + ")" };
    };

    template <typename T>
    struct category_signature<class_category, T>
    {
        constexpr static auto data { "rc(" + name_utf8_v<T> + ";" + signature<typename default_interface<T>::type>::data + ")" };
    };

    template <typename ... Args, typename T>
    struct category_signature<pinterface_category<Args ...>, T>
    {
        constexpr static auto data{ "pinterface(" + guid_to_string(category<T>::value) + ";" + arg_collection<Args ...>::data + ")" };
    };

    template <typename T>
    struct category_signature<interface_category, T>
    {
        constexpr static auto data{ guid_to_string(guid<T>::value) };
    };

    template <typename T>
    struct category_signature<delegate_category, T>
    {
        constexpr static auto data{ "delegate(" + guid_to_string(guid<T>::value) + ")" };
    };
}
