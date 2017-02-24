
namespace impl
{
    template <typename T, typename Container>
    struct input_iterable : implements<input_iterable<T, Container>, non_agile, no_weak_ref, wfc::IIterable<T>>
    {
        static_assert(std::is_same_v<Container, std::remove_reference_t<Container>>, "Must be constructed with rvalue.");

        explicit input_iterable(Container && values) : m_values(std::forward<Container>(values))
        {
        }

        wfc::IIterator<T> First()
        {
            return make<iterator>(this);
        }

    private:

        Container const m_values;

        struct iterator : implements<iterator, non_agile, no_weak_ref, wfc::IIterator<T>>
        {
            explicit iterator(input_iterable<T, Container> * owner) noexcept :
                m_current(owner->m_values.begin()),
                m_end(owner->m_values.end())
            {
                m_owner.copy_from(owner);
            }

            T Current() const
            {
                if (m_current == m_end)
                {
                    throw hresult_out_of_bounds();
                }

                return collection_traits<T>::copy(*m_current);
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

                collection_traits<T>::copy_n(m_current, actual, values.begin());
                std::advance(m_current, actual);
                return actual;
            }

        private:

            com_ptr<input_iterable<T, Container>> m_owner;
            typename Container::const_iterator m_current;
            typename Container::const_iterator const m_end;
        };
    };

    template <typename T, typename InputIt>
    struct scoped_input_iterable : input_scope, implements<scoped_input_iterable<T, InputIt>, non_agile, no_weak_ref, wfc::IIterable<T>>
    {
        void abi_enter() const
        {
            check_scope();
        }

        scoped_input_iterable(InputIt first, InputIt last) : m_begin(first), m_end(last)
        {
        }

        wfc::IIterator<T> First()
        {
            return make<iterator>(this);
        }

    private:

        InputIt const m_begin;
        InputIt const m_end;

        struct iterator : implements<iterator, non_agile, no_weak_ref, wfc::IIterator<T>>
        {
            void abi_enter() const
            {
                m_owner->check_scope();
            }

            explicit iterator(scoped_input_iterable<T, InputIt> * owner) noexcept :
                m_current(owner->m_begin),
                m_end(owner->m_end)
            {
                m_owner.copy_from(owner);
            }

            T Current() const
            {
                if (m_current == m_end)
                {
                    throw hresult_out_of_bounds();
                }

                return collection_traits<T>::copy(*m_current);
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

                collection_traits<T>::copy_n(m_current, actual, values.begin());
                std::advance(m_current, actual);
                return actual;
            }

        private:

            com_ptr<scoped_input_iterable<T, InputIt>> m_owner;
            InputIt m_current;
            InputIt const m_end;
        };
    };

    template <typename T, typename Container>
    auto make_input_iterable(Container && values)
    {
        return make<input_iterable<T, Container>>(std::forward<Container>(values));
    }

    template <typename T, typename InputIt>
    auto make_scoped_input_iterable(InputIt first, InputIt last)
    {
        using interface_type = wfc::IIterable<T>;
        std::pair<interface_type, input_scope *> result;
        auto ptr = new scoped_input_iterable<T, InputIt>(first, last);
        *put_abi(result.first) = to_abi<interface_type>(ptr);
        result.second = ptr;
        return result;
    }
}

template <typename T>
struct iterable
{
    using value_type = T;
    using interface_type = Windows::Foundation::Collections::IIterable<value_type>;

    iterable(std::nullptr_t) noexcept
    {
    }

    iterable(iterable const & values) noexcept : m_owned(false)
    {
        attach_abi(m_pair.first, get_abi(values));
    }

    iterable(interface_type const & values) noexcept : m_owned(false)
    {
        attach_abi(m_pair.first, get_abi(values));
    }

    template <typename Collection, std::enable_if_t<std::is_convertible_v<Collection, interface_type>> * = nullptr>
    iterable(Collection const & values) noexcept : m_owned(true)
    {
        m_pair.first = values;
    }

    template <typename Allocator>
    iterable(std::vector<value_type, Allocator> && values) : m_pair(impl::make_input_iterable<value_type>(std::move(values)), nullptr)
    {
    }

    template <typename Allocator>
    iterable(std::vector<value_type, Allocator> const & values) : m_pair(impl::make_scoped_input_iterable<value_type>(values.begin(), values.end()))
    {
    }

    iterable(std::initializer_list<value_type> values) : m_pair(impl::make_scoped_input_iterable<value_type>(values.begin(), values.end()))
    {
    }

    template<class InputIt>
    iterable(InputIt first, InputIt last) : m_pair(impl::make_scoped_input_iterable<value_type>(first, last))
    {
    }

    ~iterable() noexcept
    {
        if (m_pair.second)
        {
            m_pair.second->invalidate_scope();
        }

        if (!m_owned)
        {
            detach_abi(m_pair.first);
        }
    }

private:

    std::pair<interface_type, impl::input_scope *> m_pair;
    bool m_owned{true};
};

template <typename K, typename V>
struct iterable<Windows::Foundation::Collections::IKeyValuePair<K, V>>
{
    using value_type = Windows::Foundation::Collections::IKeyValuePair<K, V>;
    using interface_type = Windows::Foundation::Collections::IIterable<value_type>;

    iterable(std::nullptr_t) noexcept
    {
    }

    iterable(iterable const & values) noexcept : m_owned(false)
    {
        attach_abi(m_pair.first, get_abi(values));
    }

    iterable(interface_type const & values) noexcept : m_owned(false)
    {
        attach_abi(m_pair.first, get_abi(values));
    }

    template <typename Collection, std::enable_if_t<std::is_convertible_v<Collection, interface_type>> * = nullptr>
    iterable(Collection const & values) noexcept : m_owned(true)
    {
        m_pair.first = values;
    }

    template <typename Compare, typename Allocator>
    iterable(std::map<K, V, Compare, Allocator> && values) : m_pair(impl::make_input_iterable<value_type>(std::move(values)), nullptr)
    {
    }

    template <typename Compare, typename Allocator>
    iterable(std::map<K, V, Compare, Allocator> const & values) : m_pair(impl::make_scoped_input_iterable<value_type>(values.begin(), values.end()))
    {
    }

    template <typename Hash, typename KeyEqual, typename Allocator>
    iterable(std::unordered_map<K, V, Hash, KeyEqual, Allocator> && values) : m_pair(impl::make_input_iterable<value_type>(std::move(values)), nullptr)
    {
    }

    template <typename Hash, typename KeyEqual, typename Allocator>
    iterable(std::unordered_map<K, V, Hash, KeyEqual, Allocator> const & values) : m_pair(impl::make_scoped_input_iterable<value_type>(values.begin(), values.end()))
    {
    }

    iterable(std::initializer_list<std::pair<K const, V>> values) : m_pair(impl::make_scoped_input_iterable<value_type>(values.begin(), values.end()))
    {
    }

    template<class InputIt>
    iterable(InputIt first, InputIt last) : m_pair(impl::make_scoped_input_iterable<value_type>(first, last))
    {
    }

    ~iterable() noexcept
    {
        if (m_pair.second)
        {
            m_pair.second->invalidate_scope();
        }

        if (!m_owned)
        {
            detach_abi(m_pair.first);
        }
    }

private:

    std::pair<interface_type, impl::input_scope *> m_pair;
    bool m_owned{ true };
};

template <typename T>
auto get_abi(const iterable<T> & object) noexcept
{
    return *reinterpret_cast<abi<Windows::Foundation::Collections::IIterable<T>> **>(&const_cast<iterable<T> &>(object));
}