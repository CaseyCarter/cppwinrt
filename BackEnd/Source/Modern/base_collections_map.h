
namespace impl
{
    template <typename K, typename V, typename Container>
    struct single_threaded_map : implements<single_threaded_map<K, V, Container>, wfc::IMap<K, V>, wfc::IMapView<K, V>, wfc::IIterable<wfc::IKeyValuePair<K, V>>>
    {
        static_assert(is_same_v<Container, std::remove_reference_t<Container>>, "Must be constructed with rvalue.");

        using value_type = wfc::IKeyValuePair<K, V>;

        explicit single_threaded_map(Container && values) : m_values(std::forward<Container>(values))
        {
        }

        V Lookup(K const & key) const
        {
            auto pair = m_values.find(key);

            if (pair == m_values.end())
            {
                throw hresult_out_of_bounds();
            }

            return pair->second;
        }

        uint32_t Size() const noexcept
        {
            return static_cast<uint32_t>(m_values.size());
        }

        bool HasKey(K const & key) const noexcept
        {
            return m_values.find(key) != m_values.end();
        }

        wfc::IMapView<K, V> GetView() const
        {
            return *this;
        }

        bool Insert(const K & key, const V & value)
        {
            ++m_version;
            auto pair = m_values.insert_or_assign(key, value);
            return !pair.second;

        }

        void Remove(const K & key)
        {
            ++m_version;
            m_values.erase(key);
        }

        void Clear() noexcept
        {
            ++m_version;
            m_values.clear();
        }

        void Split(wfc::IMapView<K, V> & first, wfc::IMapView<K, V> & second) const noexcept
        {
            first = nullptr;
            second = nullptr;
        }

        wfc::IIterator<value_type> First()
        {
            return make<iterator>(this);
        }

    private:

        Container m_values;
        uint32_t m_version{};

        struct iterator : implements<iterator, wfc::IIterator<value_type>>
        {
            explicit iterator(single_threaded_map<K, V, Container> * owner) noexcept :
            m_version(owner->m_version),
                m_current(owner->m_values.begin()),
                m_end(owner->m_values.end())
            {
                m_owner.copy_from(owner);
            }

            void abi_enter() const
            {
                if (m_version != m_owner->m_version)
                {
                    throw hresult_changed_state();
                }
            }

            value_type Current() const
            {
                if (m_current == m_end)
                {
                    throw hresult_out_of_bounds();
                }

                return collection_traits<value_type>::copy(*m_current);
            }

            bool HasCurrent() const noexcept
            {
                return m_current != m_end;
            }

            bool MoveNext() noexcept
            {
                if (m_current != m_end)
                {
                    ++m_current;
                }

                return HasCurrent();
            }

            uint32_t GetMany(array_view<value_type> values)
            {
                uint32_t actual = static_cast<uint32_t>(std::distance(m_current, m_end));

                if (actual > values.size())
                {
                    actual = values.size();
                }

                collection_traits<value_type>::copy_n(m_current, actual, values.begin());
                std::advance(m_current, actual);
                return actual;
            }

        private:

            com_ptr<single_threaded_map<K, V, Container>> m_owner;
            uint32_t const m_version;
            typename Container::const_iterator m_current;
            typename Container::const_iterator const m_end;
        };
    };
}

template <typename K, typename V, typename Compare = std::less<K>, typename Allocator = std::allocator<std::pair<K const, V>>>
Windows::Foundation::Collections::IMap<K, V> single_threaded_map()
{
    return make<impl::single_threaded_map<K, V, std::map<K, V, Compare, Allocator>>>(std::map<K, V, Compare, Allocator>{});
}

template <typename K, typename V, typename Compare = std::less<K>, typename Allocator = std::allocator<std::pair<K const, V>>>
Windows::Foundation::Collections::IMap<K, V> single_threaded_map(std::map<K, V, Compare, Allocator> && values)
{
    return make<impl::single_threaded_map<K, V, std::map<K, V, Compare, Allocator>>>(std::move(values));
}

template <typename K, typename V, typename Hash = std::hash<K>, typename KeyEqual = std::equal_to<K>, typename Allocator = std::allocator<std::pair<const K, V>>>
Windows::Foundation::Collections::IMap<K, V> single_threaded_map(std::unordered_map<K, V, Hash, KeyEqual, Allocator> && values)
{
    return make<impl::single_threaded_map<K, V, std::unordered_map<K, V, Hash, KeyEqual, Allocator>>>(std::move(values));
}
