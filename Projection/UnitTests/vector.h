#pragma once

//
// What follows is a complete reference implementation of IVector/IVectorView/IIterable/IIterator used for testing
// both the consumer and producer sides of the projection of these collection interfaces.
//

namespace winrt { namespace impl {

struct VectorChangedEventArgs : implements<VectorChangedEventArgs,
                                           Windows::Foundation::Collections::IVectorChangedEventArgs>
{
    Windows::Foundation::Collections::CollectionChange m_change;
    uint32_t m_index;

    VectorChangedEventArgs(Windows::Foundation::Collections::CollectionChange change, uint32_t index) noexcept :
        m_change(change),
        m_index(index)
    {}

    Windows::Foundation::Collections::CollectionChange CollectionChange() const noexcept
    {
        return m_change;
    }

    uint32_t Index() const noexcept
    {
        return m_index;
    }
};

template <typename T>
struct Iterator : implements<Iterator<T>,
                             Windows::Foundation::Collections::IIterator<T>>
{
    Iterator(const Windows::Foundation::Collections::IVectorView<T> & v) : v(v)
    {}

    T Current() const
    {
        return v.GetAt(i);
    }

    bool HasCurrent() const
    {
        return i < v.Size();
    }

    bool MoveNext()
    {
        return ++i < v.Size();
    }

    uint32_t GetMany(array_view<T> values) const
    {
        return v.GetMany(i, values);
    }

private:

    Windows::Foundation::Collections::IVectorView<T> v;
    uint32_t i = 0;
};

template <typename T>
struct Vector : implements<Vector<T>,
                           Windows::Foundation::Collections::IObservableVector<T>,
                           Windows::Foundation::Collections::IVector<T>,
                           Windows::Foundation::Collections::IVectorView<T>,
                           Windows::Foundation::Collections::IIterable<T>>
{
    Vector() = default;

    Vector(std::vector<T> && v) :
        v(std::move(v))
    {}

    Vector(const std::vector<T> & v) :
        v(v)
    {}

    T GetAt(const uint32_t index) const
    {
        if (index >= v.size())
        {
            throw hresult_out_of_bounds();
        }

        return v[index];
    }

    uint32_t Size() const
    {
        return static_cast<uint32_t>(v.size());
    }

    Windows::Foundation::Collections::IVectorView<T> GetView() const
    {
        return *this;
    }

    bool IndexOf(const T & value, uint32_t & index) const
    {
        index = static_cast<uint32_t>(std::find(begin(v), end(v), value) - begin(v));
        return index < v.size();
    }

    void SetAt(const uint32_t index, const T & value)
    {
        if (index >= v.size())
        {
            throw hresult_out_of_bounds();
        }

        v[index] = value;
    }

    void InsertAt(const uint32_t index, const T & value)
    {
        if (index > v.size())
        {
            throw hresult_out_of_bounds();
        }

        // This is very inefficient but it will do for testing.
        m_vectorChanged(*this, make<VectorChangedEventArgs>(CollectionChange::ItemInserted, index));

        v.insert(begin(v) + index, value);
    }

    void RemoveAt(const uint32_t index)
    {
        if (index >= v.size())
        {
            throw hresult_out_of_bounds();
        }

        v.erase(begin(v) + index);
    }

    void Append(const T & value)
    {
        v.push_back(value);
    }

    void RemoveAtEnd()
    {
        if (v.empty())
        {
            throw hresult_out_of_bounds();
        }

        v.pop_back();
    }

    void Clear()
    {
        v.clear();
    }

    uint32_t GetMany(const uint32_t startIndex, array_view<T> values) const
    {
        if (v.size() <= startIndex)
        {
            return 0;
        }

        uint32_t actual = static_cast<uint32_t>(v.size() - startIndex);

        if (actual > values.size())
        {
            actual = values.size();
        }

        // Using private copy_n function because Visual C++ thinks that std::copy_n is unsafe.
        copy_n(begin(v) + startIndex, actual, std::begin(values));

        return actual;
    }

    void ReplaceAll(array_view<const T> value)
    {
        v.assign(std::begin(value), std::end(value));
    }

    Windows::Foundation::Collections::IIterator<T> First() const
    {
        return make<Iterator<T>>(*this);
    }

    event_token VectorChanged(const Windows::Foundation::Collections::VectorChangedEventHandler<T> & handler)
    {
        return m_vectorChanged.add(handler);
    }

    void VectorChanged(const event_token cookie)
    {
        m_vectorChanged.remove(cookie);
    }

private:

    template<typename InputIt, typename Size, typename OutputIt>
    static void copy_n(InputIt first, Size count, OutputIt result)
    {
        while (count--)
        {
            *result++ = *first++;
        }
    }

    std::vector<T> v;
    agile_event<Windows::Foundation::Collections::VectorChangedEventHandler<T>> m_vectorChanged;
};

}}
