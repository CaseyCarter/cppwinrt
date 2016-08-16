
namespace impl
{
    template <typename T>
    struct vector : implements<vector<T>,
                               Windows::Foundation::Collections::IVector<T>,
                               Windows::Foundation::Collections::IIterable<T>>
    {
        vector() = default;

        vector(std::vector<T> && values) : m_storage(std::move(values))
        {}

        template<class InputIt>
        vector(InputIt first, InputIt last) : m_storage(first, last)
        {}

        void Append(const T & value)
        {
            increment_version();
            m_storage.push_back(value);
        }

        void Clear() noexcept
        {
            increment_version();
            m_storage.clear();
        }

        T GetAt(const uint32_t index) const
        {
            if (index >= m_storage.size())
            {
                throw hresult_out_of_bounds();
            }

            return m_storage[index];
        }

        uint32_t GetMany(const uint32_t startIndex, array_ref<T> values) const
        {
            if (startIndex >= m_storage.size())
            {
                return 0;
            }

            uint32_t actual = static_cast<uint32_t>(m_storage.size() - startIndex);

            if (actual > values.size())
            {
                actual = values.size();
            }

            std::copy_n(m_storage.begin() + startIndex, actual, values.begin());
            return actual;
        }

        Windows::Foundation::Collections::IVectorView<T> GetView()
        {
            return make<vector_view_from_vector<T>>(this, m_version, m_version);
        }

        bool IndexOf(const T & value, uint32_t & index) const noexcept
        {
            uint32_t pos = static_cast<uint32_t>(std::find(m_storage.begin(), m_storage.end(), value) - m_storage.begin());
            const bool valid_index = index < m_storage.size();

            index = valid_index ? pos : 0;
            return valid_index;
        }

        void InsertAt(const uint32_t index, const T & value)
        {
            if (index > m_storage.size())
            {
                throw hresult_out_of_bounds();
            }

            increment_version();
            m_storage.insert(m_storage.begin() + index, value);
        }

        void RemoveAt(const uint32_t index)
        {
            if (index >= m_storage.size())
            {
                throw hresult_out_of_bounds();
            }

            increment_version();
            m_storage.erase(m_storage.begin() + index);
        }

        void RemoveAtEnd()
        {
            if (m_storage.empty())
            {
                throw hresult_out_of_bounds();
            }

            increment_version();
            m_storage.pop_back();
        }

        void ReplaceAll(array_ref<const T> value)
        {
            increment_version();
            m_storage.assign(value.begin(), value.end());
        }

        void SetAt(const uint32_t index, const T & value)
        {
            if (index >= m_storage.size())
            {
                throw hresult_out_of_bounds();
            }

            increment_version();
            m_storage[index] = value;
        }

        uint32_t Size() const noexcept
        {
            return static_cast<uint32_t>(m_storage.size());
        }

        Windows::Foundation::Collections::IIterator<T> First() const
        {
            return make<iterator<T>>(*this, m_storage, m_version, m_version);
        }

    private:

        void increment_version()  noexcept
        {
            if (m_version == UINT_MAX)
            {
                m_version = 0;
            }
            else
            {
                m_version++;
            }
        }

        std::vector<T> m_storage;
        uint32_t m_version = 0;
    };

    template <typename T>
    struct vector_view_standalone : implements<vector_view_standalone<T>,
                                               Windows::Foundation::Collections::IVectorView<T>,
                                               Windows::Foundation::Collections::IIterable<T>>
    {
        vector_view_standalone() = default;

        vector_view_standalone(std::vector<T> && values) : m_storage(std::move(values))
        {}

        template<class InputIt>
        vector_view_standalone(InputIt first, InputIt last) : m_storage(first, last)
        {}

        T GetAt(const uint32_t index) const
        {
            if (index >= m_storage.size())
            {
                throw hresult_out_of_bounds();
            }

            return m_storage[index];
        }

        uint32_t GetMany(const uint32_t startIndex, array_ref<T> values) const
        {
            if (startIndex >= m_storage.size())
            {
                return 0;
            }

            uint32_t actual = static_cast<uint32_t>(m_storage.size() - startIndex);

            if (actual > values.size())
            {
                actual = values.size();
            }

            std::copy_n(m_storage.begin() + startIndex, actual, values.begin());
            return actual;
        }

        bool IndexOf(const T & value, uint32_t & index) const noexcept
        {
            uint32_t pos = static_cast<uint32_t>(std::find(m_storage.begin(), m_storage.end(), value) - m_storage.begin());
            const bool valid_index = index < m_storage.size();

            index = valid_index ? pos : 0;
            return valid_index;
        }

        uint32_t Size() const noexcept
        {
            return static_cast<uint32_t>(m_storage.size());
        }

        Windows::Foundation::Collections::IIterator<T> First() const
        {
            return make<iterator_standalone<T>>(*this, m_storage);
        }

    private:

        const std::vector<T> m_storage;
    };

    template <typename T>
    struct vector_view_from_vector : implements<vector_view_from_vector<T>,
                                                Windows::Foundation::Collections::IVectorView<T>,
                                                Windows::Foundation::Collections::IIterable<T>>
    {
        vector_view_from_vector(vector<T>* vector, const uint32_t & owner_version, const uint32_t storage_version) :
            m_owner_version(owner_version),
            m_storage_version(storage_version)
        {
            m_storage.copy_from(vector);
        }

        T GetAt(const uint32_t index) const
        {
            validate_version();

            return m_storage->GetAt(index);
        }

        uint32_t GetMany(const uint32_t startIndex, array_ref<T> values) const
        {
            validate_version();
            return m_storage->GetMany(startIndex, values);
        }

        bool IndexOf(const T & value, uint32_t & index) const
        {
            validate_version();
            return m_storage->IndexOf(value, index);
        }

        uint32_t Size() const
        {
            validate_version();
            return m_storage->Size();
        }

        Windows::Foundation::Collections::IIterator<T> First()
        {
            validate_version();
            return m_storage->First();
        }

    private:

        void validate_version() const
        {
            if (m_storage_version != m_owner_version)
            {
                throw hresult_changed_state();
            }
        }

        com_ptr<vector<T>> m_storage;
        const uint32_t & m_owner_version;
        const uint32_t m_storage_version;
    };

    template <typename T>
    struct iterable : implements<iterable<T>,
                                 Windows::Foundation::Collections::IIterable<T>>
    {
        iterable(std::vector<T> && values) : m_storage(std::move(values))
        {}

        template<class InputIt>
        iterable(InputIt first, InputIt last) : m_storage(first, last)
        {}

        Windows::Foundation::Collections::IIterator<T> First() const
        {
            return make<iterator_standalone<T>>(*this, m_storage);
        }

    private:

        const std::vector<T> m_storage;
    };

    template <typename T>
    struct iterator : implements<iterator<T>,
                                 Windows::Foundation::Collections::IIterator<T>>
    {
        iterator(const Windows::Foundation::Collections::IIterable<T> & owner, const std::vector<T> & values, const uint32_t & owner_version, const uint32_t storage_version) noexcept :
            m_storage(owner),
            m_owner_version(owner_version),
            m_storage_version(storage_version),
            m_current(values.begin()),
            m_end(values.end())
        {}

        T Current() const
        {
            validate_version();

            if (m_current == m_end)
            {
                throw hresult_out_of_bounds();
            }

            return *m_current;
        }

        bool HasCurrent() const
        {
            validate_version();
            return m_current != m_end;
        }

        bool MoveNext()
        {
            validate_version();

            if (m_current != m_end)
            {
                ++m_current;
            }

            return m_current != m_end;
        }

        uint32_t GetMany(array_ref<T> values)
        {
            validate_version();

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

        void validate_version() const
        {
            if (m_storage_version != m_owner_version)
            {
                throw hresult_changed_state();
            }
        }

        const Windows::Foundation::Collections::IIterable<T> m_storage;
        const uint32_t & m_owner_version;
        const uint32_t m_storage_version;
        typename std::vector<T>::const_iterator m_current;
        typename std::vector<T>::const_iterator m_end;
    };

    template <typename T>
    struct iterator_standalone : implements<iterator_standalone<T>,
                                            Windows::Foundation::Collections::IIterator<T>>
    {
        iterator_standalone(const Windows::Foundation::Collections::IIterable<T> & owner, const std::vector<T> & values) noexcept :
            m_storage(owner),
            m_current(values.begin()),
            m_end(values.end())
        {}

        T Current() const
        {
            if (m_current == m_end)
            {
                throw hresult_out_of_bounds();
            }

            return *m_current;
        }

        bool HasCurrent() const
        {
            return m_current != m_end;
        }

        bool MoveNext()
        {
            if (m_current != m_end)
            {
                ++m_current;
            }

            return HasCurrent();
        }

        uint32_t GetMany(array_ref<T> values)
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

        const Windows::Foundation::Collections::IIterable<T> m_storage;
        typename std::vector<T>::const_iterator m_current;
        typename std::vector<T>::const_iterator m_end;
    };
}
