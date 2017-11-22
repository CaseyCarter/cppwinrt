#pragma once

#include "FastInputVector.g.h"

namespace winrt::Component::implementation
{
    struct FastInputVector : FastInputVectorT<FastInputVector>
    {
        FastInputVector(Windows::Foundation::Collections::IVectorView<hstring> const& in);

        void Close();
        Windows::Foundation::Collections::IIterator<hstring> First();
        event_token VectorChanged(Windows::Foundation::Collections::VectorChangedEventHandler<hstring> const& vhnd);
        void VectorChanged(event_token const& token);
        hstring GetAt(uint32_t index);
        uint32_t Size();
        Windows::Foundation::Collections::IVectorView<hstring> GetView();
        bool IndexOf(hstring const& value, uint32_t& index);
        void SetAt(uint32_t index, hstring const& value);
        void InsertAt(uint32_t index, hstring const& value);
        void RemoveAt(uint32_t index);
        void Append(hstring const& value);
        void RemoveAtEnd();
        void Clear();
        uint32_t GetMany(uint32_t startIndex, array_view<hstring> items);
        void ReplaceAll(array_view<hstring const> items);

    private:

        Windows::Foundation::Collections::IVector<hstring> m_vector;
    };
}

namespace winrt::Component::factory_implementation
{
    struct FastInputVector : FastInputVectorT<FastInputVector, implementation::FastInputVector>
    {
    };
}
