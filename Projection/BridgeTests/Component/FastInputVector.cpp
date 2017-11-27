#include "pch.h"
#include "FastInputVector.h"

namespace winrt::Component::implementation
{
    using namespace Windows::Foundation::Collections;

    FastInputVector::FastInputVector(IVectorView<hstring> const& in) :
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

    IIterator<hstring> FastInputVector::First()
    {
        return m_vector.First();
    }

    hstring FastInputVector::GetAt(uint32_t index)
    {
        return m_vector.GetAt(index);
    }

    uint32_t FastInputVector::Size()
    {
        return m_vector.Size();
    }

    IVectorView<hstring> FastInputVector::GetView()
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
