#include "pch.h"
#include "FastInputVector.h"

namespace winrt::Component::implementation
{
    FastInputVector::FastInputVector(Windows::Foundation::Collections::IVectorView<hstring> const& in) :
        m_vector(single_threaded_vector<hstring>())
    {
        for (auto&& string : in)
        {
            m_vector.Append(string);
        }
    }

    void FastInputVector::Close()
    {
        throw hresult_not_implemented();
    }

    Windows::Foundation::Collections::IIterator<hstring> FastInputVector::First()
    {
        return m_vector.First();
    }

    event_token FastInputVector::VectorChanged(Windows::Foundation::Collections::VectorChangedEventHandler<hstring> const&)
    {
        throw hresult_not_implemented();
    }

    void FastInputVector::VectorChanged(event_token const&)
    {
        throw hresult_not_implemented();
    }

    hstring FastInputVector::GetAt(uint32_t index)
    {
        return m_vector.GetAt(index);
    }

    uint32_t FastInputVector::Size()
    {
        return m_vector.Size();
    }

    Windows::Foundation::Collections::IVectorView<hstring> FastInputVector::GetView()
    {
        return m_vector.GetView();
    }

    bool FastInputVector::IndexOf(hstring const& value, uint32_t& index)
    {
        return m_vector.IndexOf(value, index);
    }

    void FastInputVector::SetAt(uint32_t index, hstring const& value)
    {
        m_vector.SetAt(index, value);
    }

    void FastInputVector::InsertAt(uint32_t index, hstring const& value)
    {
        m_vector.InsertAt(index, value);
    }

    void FastInputVector::RemoveAt(uint32_t index)
    {
        m_vector.RemoveAt(index);
    }

    void FastInputVector::Append(hstring const& value)
    {
        m_vector.Append(value);
    }

    void FastInputVector::RemoveAtEnd()
    {
        m_vector.RemoveAtEnd();
    }

    void FastInputVector::Clear()
    {
        m_vector.Clear();
    }

    uint32_t FastInputVector::GetMany(uint32_t startIndex, array_view<hstring> items)
    {
        return m_vector.GetMany(startIndex, items);
    }

    void FastInputVector::ReplaceAll(array_view<hstring const> items)
    {
        m_vector.ReplaceAll(items);
    }
}
