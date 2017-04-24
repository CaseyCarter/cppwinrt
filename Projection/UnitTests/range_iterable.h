#pragma once

namespace winrt::samples
{
    namespace wfc = Windows::Foundation::Collections;

    //
    // This implementation of IIterable<T> does *not* copy the input range but merely
    // provides an iterator over an input iterator:
    // http://en.cppreference.com/w/cpp/concept/InputIterator
    //

    template <typename T, typename InputIt>
    struct range_iterable : implements<range_iterable<T, InputIt>, wfc::IIterable<T>>
    {
        range_iterable(InputIt first, InputIt last) noexcept :
            m_first(first),
            m_last(last)
        {}

        wfc::IIterator<T> First() const
        {
            return make<range_iterator>(*this, m_first, m_last);
        }

    private:

        const InputIt m_first;
        const InputIt m_last;

        struct range_iterator : implements<range_iterator, wfc::IIterator<T>>
        {
            range_iterator(const wfc::IIterable<T> & owner, InputIt first, InputIt last) noexcept :
                m_owner(owner),
                m_current(first),
                m_end(last)
            {}

            T Current() const
            {
                if (m_current == m_end)
                {
                    throw hresult_out_of_bounds();
                }

                return *m_current;
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

                std::copy_n(m_current, actual, std::begin(values));
                std::advance(m_current, actual);
                return actual;
            }

        private:

            const wfc::IIterable<T> m_owner;
            InputIt m_current;
            const InputIt m_end;
        };
    };

    template <typename InputIt>
    auto make_range_iterable(InputIt first, InputIt last)
    {
        return make<range_iterable<typename std::iterator_traits<InputIt>::value_type, InputIt>>(first, last);
    }
}
