#pragma once

namespace winrt::samples
{
    namespace wfc = Windows::Foundation::Collections;

    //
    // This example either copies or moves a std::vector so that it effectively owns the underlying
    // collection. This is the simplest and safest approach since the lifetime of the IIterable<T>
    // is not related to the original container.
    //

    template <typename T>
    struct vector_iterable : implements<vector_iterable<T>, wfc::IIterable<T>>
    {
        vector_iterable(std::vector<T> && values) :
            m_values(std::move(values))
        {}

        vector_iterable(const std::vector<T> & values) :
            m_values(values)
        {}

        template <typename InputIt>
        vector_iterable(InputIt first, InputIt last) :
            m_values(first, last)
        {}

        wfc::IIterator<T> First() const
        {
            return make<vector_iterator>(*this, m_values);
        }

    private:

        const std::vector<T> m_values;

        struct vector_iterator : implements<vector_iterator, wfc::IIterator<T>>
        {
            vector_iterator(const wfc::IIterable<T> & owner, const std::vector<T> & values) noexcept :
                m_owner(owner),
                m_current(begin(values)),
                m_end(end(values))
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
            typename std::vector<T>::const_iterator m_current;
            const typename std::vector<T>::const_iterator m_end;
        };
    };
}
