
namespace impl
{
    template <typename T, typename Container>
    struct single_threaded_vector : implements<single_threaded_vector<T, Container>, wfc::IVector<T>, wfc::IVectorView<T>, wfc::IIterable<T>>
    {
        static_assert(std::is_same_v<Container, std::remove_reference_t<Container>>, "Must be constructed with rvalue.");

        explicit single_threaded_vector(Container&& values) : m_values(std::forward<Container>(values))
        {
        }

        T GetAt(uint32_t const index) const
        {
            if (index >= m_values.size())
            {
                throw hresult_out_of_bounds();
            }

            return m_values[index];
        }

        uint32_t Size() const noexcept
        {
            return static_cast<uint32_t>(m_values.size());
        }

        wfc::IVectorView<T> GetView()
        {
            return*this;
        }

        bool IndexOf(T const& value, uint32_t& index) const noexcept
        {
            index = static_cast<uint32_t>(std::find(m_values.begin(), m_values.end(), value) - m_values.begin());
            return index < m_values.size();
        }

        void SetAt(uint32_t const index, T const& value)
        {
            if (index >= m_values.size())
            {
                throw hresult_out_of_bounds();
            }

            ++m_version;
            m_values[index] = value;
        }

        void InsertAt(uint32_t const index, T const& value)
        {
            if (index > m_values.size())
            {
                throw hresult_out_of_bounds();
            }

            ++m_version;
            m_values.insert(m_values.begin() + index, value);
        }

        void RemoveAt(uint32_t const index)
        {
            if (index >= m_values.size())
            {
                throw hresult_out_of_bounds();
            }

            ++m_version;
            m_values.erase(m_values.begin() + index);
        }

        void Append(T const& value)
        {
            ++m_version;
            m_values.push_back(value);
        }

        void RemoveAtEnd()
        {
            if (m_values.empty())
            {
                throw hresult_out_of_bounds();
            }

            ++m_version;
            m_values.pop_back();
        }

        void Clear() noexcept
        {
            ++m_version;
            m_values.clear();
        }

        uint32_t GetMany(uint32_t const startIndex, array_view<T> values) const
        {
            if (startIndex >= m_values.size())
            {
                return 0;
            }

            uint32_t actual = static_cast<uint32_t>(m_values.size() - startIndex);

            if (actual > values.size())
            {
                actual = values.size();
            }

            std::copy_n(m_values.begin() + startIndex, actual, values.begin());
            return actual;
        }

        void ReplaceAll(array_view<T const> value)
        {
            ++m_version;
            m_values.assign(value.begin(), value.end());
        }

        wfc::IIterator<T> First()
        {
            return make<iterator>(this);
        }

    private:

        Container m_values;
        uint32_t m_version{};

        struct iterator : implements<iterator, wfc::IIterator<T>>
        {
            explicit iterator(single_threaded_vector<T, Container>* owner) noexcept :
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

            T Current() const
            {
                if (m_current == m_end)
                {
                    throw hresult_out_of_bounds();
                }

                return*m_current;
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

            uint32_t GetMany(array_view<T> values)
            {
                uint32_t actual = static_cast<uint32_t>(std::distance(m_current, m_end));

                if (actual > values.size())
                {
                    actual = values.size();
                }

                std::copy_n(m_current, actual, values.begin());
                std::advance(m_current, actual);
                return actual;
            }

        private:

            com_ptr<single_threaded_vector<T, Container>> m_owner;
            uint32_t const m_version;
            typename Container::const_iterator m_current;
            typename Container::const_iterator const m_end;
        };
    };
}

template <typename T, typename Allocator = std::allocator<T>>
Windows::Foundation::Collections::IVector<T> single_threaded_vector(std::vector<T, Allocator>&& values = {})
{
    return make<impl::single_threaded_vector<T, std::vector<T, Allocator>>>(std::move(values));
}
