
namespace impl
{
    namespace wfc = Windows::Foundation::Collections;

    template <typename K, typename V>
    struct key_value_pair : implements<key_value_pair<K, V>, wfc::IKeyValuePair<K, V>>
    {
        explicit key_value_pair(std::pair<const K, V> const & value) : m_value(value)
        {}

        K Key() const
        {
            return m_value.first;
        }

        V Value() const
        {
            return m_value.second;
        }

    private:

        std::pair<const K, V> const m_value;
    };

    template <typename T>
    struct collection_traits
    {
        static T copy(T const & value)
        {
            return value;
        }

        template<typename InputIt, typename Size, typename OutputIt>
        static auto copy_n(InputIt first, Size count, OutputIt result)
        {
            return std::copy_n(first, count, result);
        }
    };

    template <typename K, typename V>
    struct collection_traits<wfc::IKeyValuePair<K, V>>
    {
        static auto copy(std::pair<const K, V> const & value)
        {
            return make<key_value_pair<K, V>>(value);
        }

        template<typename InputIt, typename Size, typename OutputIt>
        static auto copy_n(InputIt first, Size count, OutputIt result)
        {
            return std::transform(first, std::next(first, count), result, [](std::pair<const K, V> const & value)
            {
                return make<key_value_pair<K, V>>(value);
            });
        }
    };

    struct input_scope
    {
        void invalidate_scope() noexcept
        {
            m_invalid = true;
        }

        void check_scope() const
        {
            if (m_invalid)
            {
                throw hresult_illegal_method_call();
            }
        }

    private:

        bool m_invalid{};
    };
}
