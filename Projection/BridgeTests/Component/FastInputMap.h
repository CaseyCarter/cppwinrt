#pragma once

#include "FastInputMap.g.h"

namespace winrt::Component::implementation
{
    struct FastInputMap : FastInputMapT<FastInputMap>
    {
        FastInputMap() = delete;
        FastInputMap(Windows::Foundation::Collections::IMapView<hstring, hstring> const& in);

        void Close();
        Windows::Foundation::Collections::IIterator<Windows::Foundation::Collections::IKeyValuePair<hstring, hstring>> First();
        hstring Lookup(hstring const& key);
        uint32_t Size();
        bool HasKey(hstring const& key);
        Windows::Foundation::Collections::IMapView<hstring, hstring> GetView();
        bool Insert(hstring const& key, hstring const& value);
        void Remove(hstring const& key);
        void Clear();
        void Split(Windows::Foundation::Collections::IMapView<hstring, hstring>& first, Windows::Foundation::Collections::IMapView<hstring, hstring>& second);

    private:

        Windows::Foundation::Collections::IMap<hstring, hstring> m_map;
    };
}

namespace winrt::Component::factory_implementation
{
    struct FastInputMap : FastInputMapT<FastInputMap, implementation::FastInputMap>
    {
    };
}
