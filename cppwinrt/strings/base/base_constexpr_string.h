
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
    constexpr constexpr_array<T, N1 + N2, D> concat(constexpr_array<T, N1, D> const & left, constexpr_array<T, N2, D> const & right, std::index_sequence<Index ...> const, std::index_sequence<Index2 ...> const)
    {
        return { { left[Index] ..., right[Index2] ... } };
    }

    template <typename T, typename D, size_t N, size_t ... Index>
    constexpr constexpr_array<std::remove_cv_t<T>, N, D> to_array(T const (&value)[N], std::index_sequence<Index ...> const)
    {
        return { { value[Index] ... } };    
    }

    template <typename T, typename D, size_t N1, size_t N2>
    constexpr constexpr_array<T, N1 + N2, D> concat(constexpr_array<T, N1, D> const & left, constexpr_array<T, N2, D> const & right) 
    {
        return concat(left, right, std::make_index_sequence<N1>(), std::make_index_sequence<N2>());
    }

    template <typename T, typename D, size_t N1>
    constexpr constexpr_array<T, N1, D> concat(constexpr_array<T, N1, D> const & left, constexpr_array<T, 0, D> const &)
    {
        return left;
    }

    template <typename T, typename D, size_t N1, size_t N2>
    constexpr constexpr_array<T, N1 + N2, D> operator+(constexpr_array<T, N1> const & left, constexpr_array<T, N2, D> const & right)
    {
        return concat(left, right, std::make_index_sequence<N1>(), std::make_index_sequence<N2>());
    }

    template <typename T, size_t N, typename D>
    constexpr constexpr_array<T, N + 1, D> operator+(constexpr_array<T, N> const & left, T const & right) 
    {
        constexpr_array<T, 1, D> temp{ right };
        return concat(left, temp, std::make_index_sequence<N>(), std::make_index_sequence<1>());
    }

    template <typename T, size_t N, typename D>
    constexpr constexpr_array<T, N + 1, D> append(constexpr_array<T, N, D> const & left, T const & right) 
    {
        return concat(left, constexpr_array<T, 1, D>{ {right} }, std::make_index_sequence<N>(), std::make_index_sequence<1>());
    }

    template <typename D, typename T, size_t N>
    constexpr constexpr_array<std::remove_cv_t<T>, N, D> to_array(T const (&value)[N]) 
    {
        return to_array<T, D>(value, std::make_index_sequence<N>());
    }

    template <typename T, size_t N>
    constexpr auto to_array(T const (&value)[N]) 
    {
        return to_array<void>(value);
    }

    struct string_discriminator { };

    template <typename T, size_t N>
    using constexpr_string = constexpr_array<T, N, string_discriminator>;

    template <typename T, size_t N>
    constexpr auto make_constexpr_string(T const (&arr)[N]) 
    {
        return to_array<string_discriminator>(arr);
    }
    
    template <typename T, size_t N>
    constexpr auto make_constexpr_string(constexpr_string<T, N> const & str) 
    {
        return str;
    }

    template <typename T, size_t N, size_t ... Index>
    constexpr constexpr_string<T, sizeof ... (Index)> truncate(constexpr_string<T, N> const & value, std::index_sequence<Index ...>)
    {
        return { { value[Index] ... } };
    }

    template <size_t L, typename T, size_t N>
    constexpr constexpr_string<T, L> truncate(constexpr_string<T, N> const & value)
    {
        return truncate(value, std::make_index_sequence<L>());
    }

    template <typename T, size_t N1, size_t N2>
    constexpr auto string_concat(constexpr_string<T, N1> const & left, constexpr_string<T, N2> const & right)
    {
        return append(concat(truncate<N1 - 1>(left), truncate<N2 - 1>(right)), T());
    }

    template<typename T, size_t N1, size_t N2>
    constexpr auto operator+(constexpr_string<T, N1> const & left, constexpr_string<T, N2> const & right)
    {
        return string_concat(left, right);
    }

    template<typename T, size_t N1, size_t N2>
    constexpr auto operator+(T const (&left)[N1], constexpr_string<T, N2> const & right)
    {
        return string_concat(make_constexpr_string(left), right);
    }

    template<typename T, size_t N1, size_t N2>
    constexpr auto operator+(constexpr_string<T, N1> const & left, T const (&right)[N2])
    {
        return string_concat(left, make_constexpr_string(right));
    }
    
    template <typename T, size_t N1, size_t N2>
    constexpr bool string_compare(T const (&left)[N1], T const (&right)[N2])
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
    constexpr bool operator==(constexpr_string<T, N1> const & left, T const (&right)[N2])
    {
        return string_compare(left.m_elems, right);
    }

    template <typename T, size_t N1, size_t N2>
    constexpr bool operator==(T const (&left)[N1], constexpr_string<T, N2> const & right)
    {
        return string_compare(left, right.m_elems);
    }

    template <typename T, size_t N1, size_t N2>
    constexpr bool operator==(constexpr_string<T, N1> const & left, constexpr_string<T, N2> const & right)
    {
        return string_compare(left.m_elems, right.m_elems);
    }

    template <typename T, size_t Size>
    constexpr auto & string_data(constexpr_string<T, Size> const & value)
    {
        return value.m_elems;
    }

    template <typename T, size_t Size>
    constexpr auto & string_data(T const (&value)[Size])
    {
        return value;
    }
}
