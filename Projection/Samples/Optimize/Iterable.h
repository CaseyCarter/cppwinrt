#pragma once

namespace winrt {

template <typename T>
struct Iterable : implements<Iterable<T>, Windows::Foundation::Collections::IIterable<T>>
{
    Iterable(std::vector<T> && values) :
        m_values(std::move(values))
    {}

    Iterable(const std::vector<T> & values) :
        m_values(values)
    {}

    Windows::Foundation::Collections::IIterator<T> First() const
    {
        return make<Iterator>(*this, m_values);
    }
    
private:

    const std::vector<T> m_values;

    struct Iterator : implements<Iterator, Windows::Foundation::Collections::IIterator<T>>
    {
        Iterator(const Windows::Foundation::Collections::IIterable<T> & owner, const std::vector<T> & values) :
            m_owner(owner),
            m_current(begin(values)),
            m_end(end(values))
        {}

        T Current() const
        {
            if (m_current >= m_end)
            {
                throw hresult_out_of_bounds();
            }

            return *m_current;
        }

        bool HasCurrent() const noexcept
        {
            return m_current < m_end;
        }

        bool MoveNext() noexcept
        {
            if (m_current < m_end)
            {
                ++m_current;
            }

            return HasCurrent();
        }

        uint32_t GetMany(array_ref<T> values) noexcept
        {
            uint32_t actual = static_cast<uint32_t>(m_end - m_current);

            if (actual > values.size())
            {
                actual = values.size();
            }

            std::copy_n(m_current, actual, std::begin(values));

            m_current += actual;
            return actual;
        }

    private:

        const Windows::Foundation::Collections::IIterable<T> m_owner;
        typename std::vector<T>::const_iterator m_current;
        const typename std::vector<T>::const_iterator m_end;
    };
};

}