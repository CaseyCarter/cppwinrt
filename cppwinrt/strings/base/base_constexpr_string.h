
namespace winrt::impl 
{
    template <typename T, size_t N, typename D = void>
    struct constexpr_array 
    {
        using value_type = T;
        using size_type = size_t;
        using reference = value_type &;
        using const_reference = value_type const &;

        constexpr size_type size() const noexcept 
        {
            return N;
        }

        constexpr const_reference operator[](size_type i) const noexcept
        {
            return m_elems[i];
        }

        constexpr reference operator[](size_type i) noexcept
        {
            return m_elems[i];
        }

        constexpr const T * data() const noexcept
        {
            return m_elems;
        }

        T m_elems[N];
    };

    template <typename T, typename D>
    struct constexpr_array <T, 0, D>
    {
        using value_type = T;
        using size_type = size_t;
        using reference = value_type &;
        using const_reference = value_type const &;

        constexpr size_type size() const noexcept
        {
            return 0;
        }

        constexpr const T * data() const noexcept
        {
            return nullptr;
        }

        T const * m_elems = nullptr;
    };

    template <typename T, typename D, size_t N1, size_t N2, size_t ... Index, size_t ... Index2>
    constexpr constexpr_array<T, N1 + N2, D> concat(constexpr_array<T, N1, D> const & left, constexpr_array<T, N2, D> const & right, std::index_sequence<Index ...> const, std::index_sequence<Index2 ...> const) noexcept
    {
        return { { left[Index] ..., right[Index2] ... } };
    }

    template <typename T, typename D, size_t N, size_t ... Index>
    constexpr constexpr_array<std::remove_cv_t<T>, N, D> to_array(T const (&value)[N], std::index_sequence<Index ...> const) noexcept
    {
        return { { value[Index] ... } };    
    }

    template <typename T, typename D, size_t N1, size_t N2>
    constexpr constexpr_array<T, N1 + N2, D> concat(constexpr_array<T, N1, D> const & left, constexpr_array<T, N2, D> const & right) noexcept
    {
        return concat(left, right, std::make_index_sequence<N1>(), std::make_index_sequence<N2>());
    }

    template <typename T, typename D, size_t N1>
    constexpr constexpr_array<T, N1, D> concat(constexpr_array<T, N1, D> const & left, constexpr_array<T, 0, D> const &) noexcept
    {
        return left;
    }

    template <typename T, typename D, size_t N1, size_t N2>
    constexpr constexpr_array<T, N1 + N2, D> operator+(constexpr_array<T, N1> const & left, constexpr_array<T, N2, D> const & right) noexcept
    {
        return concat(left, right, std::make_index_sequence<N1>(), std::make_index_sequence<N2>());
    }

    template <typename T, size_t N, typename D>
    constexpr constexpr_array<T, N + 1, D> operator+(constexpr_array<T, N> const & left, T const & right) noexcept
    {
        constexpr_array<T, 1, D> temp{ right };
        return concat(left, temp, std::make_index_sequence<N>(), std::make_index_sequence<1>());
    }

    template <typename T, size_t N, typename D>
    constexpr constexpr_array<T, N + 1, D> append(constexpr_array<T, N, D> const & left, T const & right) noexcept
    {
        return concat(left, constexpr_array<T, 1, D>{ {right} }, std::make_index_sequence<N>(), std::make_index_sequence<1>());
    }

    template <typename D, typename T, size_t N>
    constexpr constexpr_array<std::remove_cv_t<T>, N, D> to_array(T const (&value)[N]) noexcept
    {
        return to_array<T, D>(value, std::make_index_sequence<N>());
    }

    template <typename T, size_t N>
    constexpr auto to_array(T const (&value)[N]) noexcept
    {
        return to_array<void>(value);
    }

    struct string_discriminator { };

    template <typename T, size_t N>
    using constexpr_string = constexpr_array<T, N, string_discriminator>;

    template <typename T, size_t N>
    constexpr auto make_constexpr_string(T const (&arr)[N]) noexcept
    {
        return to_array<string_discriminator>(arr);
    }
    
    template <typename T, size_t N>
    constexpr auto make_constexpr_string(constexpr_string<T, N> const & str) noexcept
    {
        return str;
    }

    template <typename T, size_t N, size_t ... Index>
    constexpr constexpr_string<T, sizeof ... (Index)> truncate(constexpr_string<T, N> const & value, std::index_sequence<Index ...>) noexcept
    {
        return { { value[Index] ... } };
    }

    template <size_t L, typename T, size_t N>
    constexpr constexpr_string<T, L> truncate(constexpr_string<T, N> const & value) noexcept
    {
        return truncate(value, std::make_index_sequence<L>());
    }

    template <typename T, size_t N1, size_t N2>
    constexpr auto string_concat(constexpr_string<T, N1> const & left, constexpr_string<T, N2> const & right) noexcept
    {
        return append(concat(truncate<N1 - 1>(left), truncate<N2 - 1>(right)), T());
    }

    template<typename T, size_t N1, size_t N2>
    constexpr auto operator+(constexpr_string<T, N1> const & left, constexpr_string<T, N2> const & right) noexcept
    {
        return string_concat(left, right);
    }

    template<typename T, size_t N1, size_t N2>
    constexpr auto operator+(T const (&left)[N1], constexpr_string<T, N2> const & right) noexcept
    {
        return string_concat(make_constexpr_string(left), right);
    }

    template<typename T, size_t N1, size_t N2>
    constexpr auto operator+(constexpr_string<T, N1> const & left, T const (&right)[N2]) noexcept
    {
        return string_concat(left, make_constexpr_string(right));
    }
    
    template <typename T, size_t N1, size_t N2>
    constexpr bool string_compare(T const (&left)[N1], T const (&right)[N2]) noexcept
    {
        if constexpr(N1 != N2)
        {
            return false;
        }

        for (size_t index = 0; index < N1; index++)
        {
            if (left[index] != right[index])
            {
                return false;
            }
        }

        return true;
    }

    template <typename T, size_t N1, size_t N2>
    constexpr bool operator==(constexpr_string<T, N1> const & left, T const (&right)[N2]) noexcept
    {
        return string_compare(left.m_elems, right);
    }

    template <typename T, size_t N1, size_t N2>
    constexpr bool operator==(T const (&left)[N1], constexpr_string<T, N2> const & right) noexcept
    {
        return string_compare(left, right.m_elems);
    }

    template <typename T, size_t N1, size_t N2>
    constexpr bool operator==(constexpr_string<T, N1> const & left, constexpr_string<T, N2> const & right) noexcept
    {
        return string_compare(left.m_elems, right.m_elems);
    }

    template <typename T, size_t Size>
    constexpr std::wstring_view string_data(constexpr_string<T, Size> const & value) noexcept
    {
        return { value.m_elems, Size - 1 };
    }

    template <typename T, size_t Size>
    constexpr std::wstring_view string_data(std::array<T, Size> const & value) noexcept
    {
        return { value.data(), Size };
    }

    template <typename T, size_t Size>
    constexpr std::wstring_view string_data(T const (&value)[Size]) noexcept
    {
        return { value, Size - 1 };
    }
}

namespace winrt
{
    template <typename T>
    inline constexpr std::wstring_view name_of() noexcept
    {
        return impl::string_data(impl::name_v<T>);
    }
}