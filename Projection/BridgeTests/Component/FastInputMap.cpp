#include "pch.h"
#include "FastInputMap.h"

namespace winrt::Component::implementation
{
    using namespace Windows::Foundation::Collections;

    FastInputMap::FastInputMap(IMapView<hstring, hstring> const& in) :
        m_map(single_threaded_map<hstring, hstring>())
    {
        for (auto&& pair : in)
        {
            m_map.Insert(pair.Key(), pair.Value());
        }
    }

    void FastInputMap::Close()
    {
        throw hresult_not_implemented();
    }

    IIterator<IKeyValuePair<hstring, hstring>> FastInputMap::First()
    {
        return m_map.First();
    }

    hstring FastInputMap::Lookup(hstring const& key)
    {
        return m_map.Lookup(key);
    }

    uint32_t FastInputMap::Size()
    {
        return m_map.Size();
    }

    bool FastInputMap::HasKey(hstring const& key)
    {
        return m_map.HasKey(key);
    }

    IMapView<hstring, hstring> FastInputMap::GetView()
    {
        return m_map.GetView();
    }

    bool FastInputMap::Insert(hstring const& key, hstring const& value)
    {
        return m_map.Insert(key, value);
    }

    void FastInputMap::Remove(hstring const& key)
    {
        m_map.Remove(key);
    }

    void FastInputMap::Clear()
    {
        m_map.Clear();
    }

    void FastInputMap::Split(IMapView<hstring, hstring>& first, IMapView<hstring, hstring>& second)
    {
        throw hresult_not_implemented();
    }
}
