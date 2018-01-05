#include "pch.h"
#include "catch.hpp"

using namespace std::string_view_literals;
using namespace winrt;
using namespace Windows::Foundation::Collections;

TEST_CASE("FastStrings")
{
    {
        IVector<hstring> c = single_threaded_vector<hstring>();
        uint32_t index = 123;
        c.IndexOf(L"hello"sv, index);
        c.Append(L"hello"sv);
        c.SetAt(0, L"hello"sv);
        c.InsertAt(1, L"world"sv);

        IVectorView<hstring> v = c.GetView();
        v.IndexOf(L"hello"sv, index);
    }

    {
        IMap<hstring, int> c = single_threaded_map<hstring, int>();
        c.Insert(L"hello"sv, 1);
        c.Lookup(L"hello"sv);
        c.HasKey(L"hello"sv);
        c.Remove(L"hello"sv);
        c.Insert(L"hello"sv, 1);

        IMapView<hstring, int> v = c.GetView();
        v.Lookup(L"hello"sv);
        v.HasKey(L"hello"sv);
    }
}
