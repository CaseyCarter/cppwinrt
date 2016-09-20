
namespace impl
{
    struct collection_version
    {
        collection_version()
        {}

        void increment()  noexcept
        {
            m_version++;
        }

        uint32_t get() const noexcept
        {
            return m_version;
        }

    private:

        uint32_t m_version = 0;
    };

    struct collection_version_validator
    {
        collection_version_validator(collection_version& owner_version, uint32_t expected_version) noexcept : 
            m_owner_version(owner_version), 
            m_expected_version(expected_version)
        {}

        void validate() const
        {
            if (m_expected_version != m_owner_version.get())
            {
                throw hresult_changed_state();
            }
        }

    private:

        const uint32_t m_expected_version;
        collection_version& m_owner_version;
    };

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
            m_version.increment();
            m_storage.push_back(value);
        }

        void Clear() noexcept
        {
            m_version.increment();
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
            return make<vector_view_from_vector<T>>(this, m_version, m_version.get());
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

            m_version.increment();
            m_storage.insert(m_storage.begin() + index, value);
        }

        void RemoveAt(const uint32_t index)
        {
            if (index >= m_storage.size())
            {
                throw hresult_out_of_bounds();
            }

            m_version.increment();
            m_storage.erase(m_storage.begin() + index);
        }

        void RemoveAtEnd()
        {
            if (m_storage.empty())
            {
                throw hresult_out_of_bounds();
            }

            m_version.increment();
            m_storage.pop_back();
        }

        void ReplaceAll(array_ref<const T> value)
        {
            m_version.increment();
            m_storage.assign(value.begin(), value.end());
        }

        void SetAt(const uint32_t index, const T & value)
        {
            if (index >= m_storage.size())
            {
                throw hresult_out_of_bounds();
            }

            m_version.increment();
            m_storage[index] = value;
        }

        uint32_t Size() const noexcept
        {
            return static_cast<uint32_t>(m_storage.size());
        }

        Windows::Foundation::Collections::IIterator<T> First()
        {
            return make<iterator<T, std::vector<T>>>(*this, m_storage, m_version, m_version.get());
        }

    private:

        std::vector<T> m_storage;
        collection_version m_version;
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
            return make<iterator_standalone<T, std::vector<T>>>(*this, m_storage);
        }

    private:

        const std::vector<T> m_storage;
    };

    template <typename T>
    struct vector_view_from_vector : implements<vector_view_from_vector<T>,
                                                Windows::Foundation::Collections::IVectorView<T>,
                                                Windows::Foundation::Collections::IIterable<T>>
    {
        vector_view_from_vector(vector<T>* vector, collection_version & owner_version, const uint32_t expected_version) :
            version_validator(owner_version, expected_version)
        {
            m_storage.copy_from(vector);
        }

        T GetAt(const uint32_t index) const
        {
            version_validator.validate();
            return m_storage->GetAt(index);
        }

        uint32_t GetMany(const uint32_t startIndex, array_ref<T> values) const
        {
            version_validator.validate();
            return m_storage->GetMany(startIndex, values);
        }

        bool IndexOf(const T & value, uint32_t & index) const
        {
            version_validator.validate();
            return m_storage->IndexOf(value, index);
        }

        uint32_t Size() const
        {
            version_validator.validate();
            return m_storage->Size();
        }

        Windows::Foundation::Collections::IIterator<T> First()
        {
            version_validator.validate();
            return m_storage->First();
        }

    private:

        com_ptr<vector<T>> m_storage;
        collection_version_validator version_validator;
    };

    template <typename T, typename CONTAINER>
    struct iterable : implements<iterable<T, CONTAINER>,
                                 Windows::Foundation::Collections::IIterable<T>>
    {
        iterable(CONTAINER && values) : m_storage(std::move(values))
        {}

        template<class InputIt>
        iterable(InputIt first, InputIt last) : m_storage(first, last)
        {}

        Windows::Foundation::Collections::IIterator<T> First() const
        {
            return make<iterator_standalone<T, CONTAINER>>(*this, m_storage);
        }

    private:

        const CONTAINER m_storage;
    };

    template <typename T, typename CONTAINER>
    struct iterator : implements<iterator<T, CONTAINER>,
                                 Windows::Foundation::Collections::IIterator<T>>
    {
        iterator(const Windows::Foundation::Collections::IIterable<T> & owner, const CONTAINER & values, collection_version & owner_version, const uint32_t storage_version) noexcept :
            m_storage(owner),
            version_validator(owner_version, storage_version),
            m_current(values.begin()),
            m_end(values.end())
        {}

        T Current() const
        {
            version_validator.validate();

            if (m_current == m_end)
            {
                throw hresult_out_of_bounds();
            }

            return *m_current;
        }

        bool HasCurrent() const
        {
            version_validator.validate();
            return m_current != m_end;
        }

        bool MoveNext()
        {
            version_validator.validate();

            if (m_current != m_end)
            {
                ++m_current;
            }

            return m_current != m_end;
        }

        uint32_t GetMany(array_ref<T> values)
        {
            version_validator.validate();

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
        collection_version_validator version_validator;
        typename CONTAINER::const_iterator m_current;
        typename CONTAINER::const_iterator m_end;
    };

    template <typename T, typename CONTAINER>
    struct iterator_standalone : implements<iterator_standalone<T, CONTAINER>,
                                            Windows::Foundation::Collections::IIterator<T>>
    {
        iterator_standalone(const Windows::Foundation::Collections::IIterable<T> & owner, const CONTAINER & values) noexcept :
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
        typename CONTAINER::const_iterator m_current;
        typename CONTAINER::const_iterator m_end;
    };

    template <typename K, typename V>
    struct key_value_pair : implements<key_value_pair<K, V>,
                                       Windows::Foundation::Collections::IKeyValuePair<K, V>>
    {
        key_value_pair(const K & key, const V & value) :
            m_key(key),
            m_value(value)
        {}

        K Key() const
        {
            return m_key;
        }

        V Value() const
        {
            return m_value;
        }

    private:

        K m_key;
        V m_value;
    };

    template <typename K, typename V, typename CONTAINER>
    struct map : implements<map<K, V, CONTAINER>,
                            Windows::Foundation::Collections::IMap<K, V>,
                            Windows::Foundation::Collections::IIterable<Windows::Foundation::Collections::IKeyValuePair<K, V>>>
    {
        map() = default;

        map(CONTAINER && values) : m_storage(std::move(values))
        {}

        template<class InputIt>
        map(InputIt first, InputIt last) : m_storage(first, last)
        {}

        map(std::initializer_list<std::pair<K, V>> values) : map(values.begin(), values.end())
        {}

        void Clear() noexcept
        {
            m_version.increment();
            m_storage.clear();
        }

        uint32_t Size() const noexcept
        {
            return static_cast<uint32_t>(m_storage.size());
        }

        Windows::Foundation::Collections::IMapView<K, V> GetView()
        {
            return make<map_view_from_map<K, V, CONTAINER>>(this, m_version, m_version.get());
        }

        bool HasKey(const K & key) const noexcept
        {
            return m_storage.find(key) != m_storage.end();
        }

        bool Insert(const K & key, const V & value)
        {
            m_version.increment();
            auto pair = m_storage.insert_or_assign(key, value);
            return !pair.second;
        }

        V Lookup(const K & key) const
        {
            auto pair = m_storage.find(key);

            if (pair == m_storage.end())
            {
                throw hresult_out_of_bounds();
            }

            return pair->second;
        }

        void Remove(const K & key) noexcept
        {
            m_version.increment();
            m_storage.erase(key);
        }

        Windows::Foundation::Collections::IIterator<Windows::Foundation::Collections::IKeyValuePair<K, V>> First()
        {
            return make<iterator<IKeyValuePair<K, V>, CONTAINER>>(*this, m_storage, m_version, m_version.get());
        }

    private:

        CONTAINER m_storage;
        collection_version m_version;
    };

    template <typename K, typename V, typename CONTAINER>
    struct map_view_from_map : implements<map_view_from_map<K, V, CONTAINER>,
                                          Windows::Foundation::Collections::IMapView<K, V>,
                                          Windows::Foundation::Collections::IIterable<Windows::Foundation::Collections::IKeyValuePair<K, V>>>
    {
        map_view_from_map(map<K, V, CONTAINER>* map, collection_version & owner_version, const uint32_t storage_version) : 
            version_validator(owner_version, storage_version)
        {
            m_storage.copy_from(map);
        }

        bool HasKey(const K & key) const
        {
            version_validator.validate();
            return m_storage->HasKey(key);
        }

        V Lookup(const K & key) const
        {
            version_validator.validate();
            return m_storage->Lookup(key);
        }

        uint32_t Size() const
        {
            version_validator.validate();
            return m_storage->Size();
        }

        void Split(Windows::Foundation::Collections::IMapView<K, V> & firstPartition, Windows::Foundation::Collections::IMapView<K, V> & secondPartition) const
        {
            version_validator.validate();

            firstPartition = nullptr;
            secondPartition = nullptr;
        }

        Windows::Foundation::Collections::IIterator<Windows::Foundation::Collections::IKeyValuePair<K, V>> First()
        {
            version_validator.validate();
            return m_storage->First();
        }

    private:

        com_ptr<map<K, V, CONTAINER>> m_storage;
        collection_version_validator version_validator;
    };

    template <typename K, typename V, typename CONTAINER>
    struct map_view_standalone: implements<map_view_standalone<K, V, CONTAINER>,
                                           Windows::Foundation::Collections::IMapView<K, V>,
                                           Windows::Foundation::Collections::IIterable<Windows::Foundation::Collections::IKeyValuePair<K, V>>>
    {
        map_view_standalone() = default;

        map_view_standalone(CONTAINER && values) : m_storage(std::move(values))
        {}

        template<class InputIt>
        map_view_standalone(InputIt first, InputIt last) : m_storage(first, last)
        {}

        map_view_standalone(std::initializer_list<std::pair<K, V>> values) : map_view_standalone(values.begin(), values.end())
        {}

        bool HasKey(const K & key) const noexcept
        {
            return m_storage.find(key) != m_storage.end();
        }

        V Lookup(const K & key) const
        {
            auto pair = m_storage.find(key);

            if (pair == m_storage.end())
            {
                throw hresult_out_of_bounds();
            }

            return pair->second;
        }

        uint32_t Size() const noexcept
        {
           return static_cast<uint32_t>(m_storage.size());
        }

        void Split(Windows::Foundation::Collections::IMapView<K, V> & firstPartition, Windows::Foundation::Collections::IMapView<K, V> & secondPartition) const noexcept
        {
            firstPartition = nullptr;
            secondPartition = nullptr;
        }

        Windows::Foundation::Collections::IIterator<Windows::Foundation::Collections::IKeyValuePair<K, V>> First()
        {
            return make<impl::iterator_standalone<Windows::Foundation::Collections::IKeyValuePair<K, V>, CONTAINER>>(*this, m_storage);
        }

    private:

        CONTAINER m_storage;
    };
}
