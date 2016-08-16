#include "pch.h"
#include "catch.hpp"

using namespace winrt::Windows::Foundation::Collections;

#pragma region "Tests, IVector"

TEST_CASE("IVector,create,rvalue")
{
    std::vector<int> stdVector{ 1, 2 };
    IVector<int> vector = winrt::make<winrt::impl::vector<int>>(std::move(stdVector));
    REQUIRE(vector != nullptr);
    REQUIRE(vector.Size() == 2);
    REQUIRE(vector.GetAt(0) == 1);
    REQUIRE(vector.GetAt(1) == 2);
}

TEST_CASE("IVector,create, iterators")
{
    std::vector<int> stdVector{ 1, 2 };
    IVector<int> vector = winrt::make<winrt::impl::vector<int>>(stdVector.data(), stdVector.data() + stdVector.size());
    REQUIRE(vector != nullptr);
    REQUIRE(vector.Size() == 2);
    REQUIRE(vector.GetAt(0) == 1);
    REQUIRE(vector.GetAt(1) == 2);
}

TEST_CASE("IVector,create, il")
{
    auto il = { 1, 2 };
    IVector<int> vector = winrt::make<winrt::impl::vector<int>>(il);
    REQUIRE(vector != nullptr);
    REQUIRE(vector.Size() == 2);
    REQUIRE(vector.GetAt(0) == 1);
    REQUIRE(vector.GetAt(1) == 2);
}

TEST_CASE("IVector,create,empty")
{
    IVector<int> vector = winrt::make<winrt::impl::vector<int>>();
    REQUIRE(vector != nullptr);
    REQUIRE(vector.Size() == 0);
}

TEST_CASE("IVector,append")
{
    std::vector<int> stdVector{ 1, 2, 3 };
    IVector<int> vector = winrt::make<winrt::impl::vector<int>>();

    for (auto& value : stdVector)
    {
        vector.Append(value);
    }

    REQUIRE(vector.GetAt(0) == 1);
    REQUIRE(vector.GetAt(1) == 2);
    REQUIRE(vector.GetAt(2) == 3);
}

TEST_CASE("IVector,Clear, non empty vector")
{
    std::vector<int> stdVector{ 1, 2, 3 };
    IVector<int> vector = winrt::make<winrt::impl::vector<int>>(std::move(stdVector));

    REQUIRE(vector.Size() == 3);
    vector.Clear();
    REQUIRE(vector.Size() == 0);
}

TEST_CASE("IVector,Clear, empty vector")
{
    std::vector<int> stdVector{ 1, 2, 3 };
    IVector<int> vector = winrt::make<winrt::impl::vector<int>>();

    REQUIRE(vector.Size() == 0);
    // Call on empty shall have no effect (eg, not throw)
    vector.Clear();
    REQUIRE(vector.Size() == 0);
}

TEST_CASE("IVector,GetAt, empty vector")
{
    IVector<int> vector = winrt::make<winrt::impl::vector<int>>();

    REQUIRE_THROWS_AS(vector.GetAt(0), winrt::hresult_out_of_bounds);
}

TEST_CASE("IVector,GetAt")
{
    std::vector<int> stdVector{ 1, 2, 3 };
    IVector<int> vector = winrt::make<winrt::impl::vector<int>>(std::move(stdVector));

    REQUIRE(vector.GetAt(0) == 1);
    REQUIRE(vector.GetAt(1) == 2);
    REQUIRE(vector.GetAt(2) == 3);
}

TEST_CASE("IVector,GetAt, out of bounds")
{
    std::vector<int> stdVector{ 1, 2, 3 };
    IVector<int> vector = winrt::make<winrt::impl::vector<int>>(std::move(stdVector));

    REQUIRE_THROWS_AS(vector.GetAt(3), winrt::hresult_out_of_bounds);
}

TEST_CASE("IVector,GetMany, empty vector")
{
    IVector<int> vector = winrt::make<winrt::impl::vector<int>>();
    winrt::array_ref<int> output;

    REQUIRE(vector.GetMany(0, output) == 0);
}

TEST_CASE("IVector,GetMany, empty vector, index past the size")
{
    std::vector<int> stdVector{ 1, 2, 3 };
    IVector<int> vector = winrt::make<winrt::impl::vector<int>>(std::move(stdVector));
    std::array<int, 3> output{ 0, 0, 0 };

    REQUIRE(vector.GetMany(3, output) == 0);
}

TEST_CASE("IVector,GetMany, empty vector, index way past the size")
{
    std::vector<int> stdVector{ 1, 2, 3 };
    IVector<int> vector = winrt::make<winrt::impl::vector<int>>(std::move(stdVector));
    std::array<int, 3> output{ 0, 0, 0 };

    REQUIRE(vector.GetMany(40, output) == 0);
}

TEST_CASE("IVector,GetMany, non empty vector")
{
    std::vector<int> stdVector{ 1, 2, 3 };
    IVector<int> vector = winrt::make<winrt::impl::vector<int>>(std::move(stdVector));
    std::array<int, 3> output{ 0, 0, 0 };

    auto count = vector.GetMany(0, output);
    REQUIRE(count == 3);

    REQUIRE(output[0] == 1);
    REQUIRE(output[1] == 2);
    REQUIRE(output[2] == 3);
}

TEST_CASE("IVector,GetMany,request less than size of IVector,beginning of the IVector")
{
    std::vector<int> stdVector{ 1, 2, 3 };
    IVector<int> vector = winrt::make<winrt::impl::vector<int>>(std::move(stdVector));
    std::array<int, 2> output{ 0, 0 };

    auto count = vector.GetMany(0, output);
    REQUIRE(count == 2);

    REQUIRE(output[0] == 1);
    REQUIRE(output[1] == 2);
}

TEST_CASE("IVector,GetMany,request less than size of IVector,middle of the IVector")
{
    std::vector<int> stdVector{ 1, 2, 3, 4 };
    IVector<int> vector = winrt::make<winrt::impl::vector<int>>(std::move(stdVector));
    std::array<int, 2> output{ 0, 0 };

    auto count = vector.GetMany(1, output);
    REQUIRE(count == 2);

    REQUIRE(output[0] == 2);
    REQUIRE(output[1] == 3);
}

TEST_CASE("IVector,GetMany,request less than size of IVector,end of the IVector")
{
    std::vector<int> stdVector{ 1, 2, 3, 4 };
    IVector<int> vector = winrt::make<winrt::impl::vector<int>>(std::move(stdVector));
    std::array<int, 2> output{ 0, 0 };

    auto count = vector.GetMany(2, output);
    REQUIRE(count == 2);

    REQUIRE(output[0] == 3);
    REQUIRE(output[1] == 4);
}

TEST_CASE("IVector,GetMany,request less than size of IVector,past of the end of the vector")
{
    std::vector<int> stdVector{ 1, 2, 3 };
    IVector<int> vector = winrt::make<winrt::impl::vector<int>>(std::move(stdVector));
    std::array<int, 2> output{ 0, 0 };

    auto count = vector.GetMany(2, output);
    REQUIRE(count == 1);

    REQUIRE(output[0] == 3);
    // Call did not write a value
    REQUIRE(output[1] == 0);
}

TEST_CASE("IVector,GetMany,request more than size of IVector,past of the end of the vector")
{
    std::vector<int> stdVector{ 1, 2, 3 };
    IVector<int> vector = winrt::make<winrt::impl::vector<int>>(std::move(stdVector));
    std::array<int, 4> output{ 0, 0, 0, 0 };

    auto count = vector.GetMany(0, output);
    REQUIRE(count == 3);

    REQUIRE(output[0] == 1);
    REQUIRE(output[1] == 2);
    REQUIRE(output[2] == 3);
    // Call did not write a value
    REQUIRE(output[3] == 0);
}

TEST_CASE("IVector,GetVectorView")
{
    std::vector<int> stdVector{ 1, 2, 3 };
    IVector<int> vector = winrt::make<winrt::impl::vector<int>>(std::move(stdVector));
    IVectorView<int> view = vector.GetView();
    REQUIRE(view != nullptr);

    REQUIRE(vector.Size() == view.Size());
    REQUIRE(view.Size() == 3);
    REQUIRE(vector.GetAt(0) == view.GetAt(0));
    REQUIRE(vector.GetAt(0) == 1);
    REQUIRE(vector.GetAt(1) == view.GetAt(1));
    REQUIRE(vector.GetAt(1) == 2);
    REQUIRE(vector.GetAt(2) == view.GetAt(2));
    REQUIRE(vector.GetAt(2) == 3);
}

TEST_CASE("IVector,IndexOf, items exist")
{
    std::vector<int> stdVector{ 1, 2, 3 };
    IVector<int> vector = winrt::make<winrt::impl::vector<int>>(std::move(stdVector));

    uint32_t index = 0;
    bool found = false;

    found = vector.IndexOf(1, index);
    REQUIRE(found);
    REQUIRE(index == 0);
    found = vector.IndexOf(2, index);
    REQUIRE(found);
    REQUIRE(index == 1);
    found = vector.IndexOf(3, index);
    REQUIRE(found);
    REQUIRE(index == 2);
}

TEST_CASE("IVector,IndexOf, item does not exists, vector is not empty")
{
    std::vector<int> stdVector{ 1, 2, 3 };
    IVector<int> vector = winrt::make<winrt::impl::vector<int>>(std::move(stdVector));
    REQUIRE(vector != nullptr);

    uint32_t index = 9999;
    bool found = false;

    found = vector.IndexOf(10, index);
    REQUIRE_FALSE(found);
    REQUIRE(index == 0);
}

TEST_CASE("IVector,IndexOf, item does not exists, vector is empty")
{
    IVector<int> vector = winrt::make<winrt::impl::vector<int>>();
    REQUIRE(vector != nullptr);

    uint32_t index = 9999;
    bool found = false;

    found = vector.IndexOf(10, index);
    REQUIRE_FALSE(found);
    REQUIRE(index == 0);
}

TEST_CASE("IVector,InsertAt, index 0, vector not empty")
{
    std::vector<int> stdVector{ 1, 2 };
    const uint32_t stdVectorCount = static_cast<uint32_t>(stdVector.size());
    IVector<int> vector = winrt::make<winrt::impl::vector<int>>(std::move(stdVector));
    const int value = 10;

    REQUIRE(vector.Size() == stdVectorCount);
    vector.InsertAt(0, value);
    REQUIRE(vector.Size() == stdVectorCount + 1);

    REQUIRE(vector.GetAt(0) == value);
    REQUIRE(vector.GetAt(1) == 1);
    REQUIRE(vector.GetAt(2) == 2);
}

TEST_CASE("IVector,InsertAt, index 0, vector is empty")
{
    IVector<int> vector = winrt::make<winrt::impl::vector<int>>();
    const int value = 10;

    REQUIRE(vector.Size() == 0);
    vector.InsertAt(0, value);
    REQUIRE(vector.Size() == 1);

    REQUIRE(vector.GetAt(0) == value);
}

TEST_CASE("IVector,InsertAt, index in the middle of the vector")
{
    std::vector<int> stdVector{ 1, 2 };
    IVector<int> vector = winrt::make<winrt::impl::vector<int>>(std::move(stdVector));
    const int value = 10;

    REQUIRE(vector.Size() == 2);
    vector.InsertAt(1, value);
    REQUIRE(vector.Size() == 3);

    REQUIRE(vector.GetAt(0) == 1);
    REQUIRE(vector.GetAt(1) == value);
    REQUIRE(vector.GetAt(2) == 2);
}

TEST_CASE("IVector,InsertAt, index at the end of the vector")
{
    std::vector<int> stdVector{ 1, 2 };
    IVector<int> vector = winrt::make<winrt::impl::vector<int>>(std::move(stdVector));
    const int value = 10;

    REQUIRE(vector.Size() == 2);
    vector.InsertAt(2, value);
    REQUIRE(vector.Size() == 3);

    REQUIRE(vector.GetAt(0) == 1);
    REQUIRE(vector.GetAt(1) == 2);
    REQUIRE(vector.GetAt(2) == value);
}

TEST_CASE("IVector,InsertAt, index past the end of the vector, vector is not empty")
{
    std::vector<int> stdVector{ 1, 2 };
    IVector<int> vector = winrt::make<winrt::impl::vector<int>>(std::move(stdVector));

    REQUIRE(vector.Size() == 2);
    REQUIRE_THROWS_AS(vector.InsertAt(10, 5), winrt::hresult_out_of_bounds);
}

TEST_CASE("IVector,InsertAt, index past the end of the vector, vector is empty")
{
    IVector<int> vector = winrt::make<winrt::impl::vector<int>>();

    REQUIRE(vector.Size() == 0);
    REQUIRE_THROWS_AS(vector.InsertAt(10, 5), winrt::hresult_out_of_bounds);
}

TEST_CASE("IVector,RemoveAt, past the end of the vector, vector is empty")
{
    IVector<int> vector = winrt::make<winrt::impl::vector<int>>();

    REQUIRE_THROWS_AS(vector.RemoveAt(0), winrt::hresult_out_of_bounds);
}

TEST_CASE("IVector,RemoveAt, past the end of the vector, vector is not empty")
{
    std::vector<int> stdVector{ 1, 2 };
    IVector<int> vector = winrt::make<winrt::impl::vector<int>>(std::move(stdVector));

    REQUIRE_THROWS_AS(vector.RemoveAt(2), winrt::hresult_out_of_bounds);
}

TEST_CASE("IVector,RemoveAt, first element, vector is not empty")
{
    std::vector<int> stdVector{ 1, 2 };
    IVector<int> vector = winrt::make<winrt::impl::vector<int>>(std::move(stdVector));

    REQUIRE(vector.Size() == 2);
    vector.RemoveAt(0);
    REQUIRE(vector.Size() == 1);

    REQUIRE(vector.GetAt(0) == 2);
}

TEST_CASE("IVector,RemoveAt, last element, vector is not empty")
{
    std::vector<int> stdVector{ 1, 2, 3 };
    IVector<int> vector = winrt::make<winrt::impl::vector<int>>(std::move(stdVector));

    REQUIRE(vector.Size() == 3);
    vector.RemoveAt(2);
    REQUIRE(vector.Size() == 2);

    REQUIRE(vector.GetAt(0) == 1);
    REQUIRE(vector.GetAt(1) == 2);
}

TEST_CASE("IVector,RemoveAt, item in the middle of the vector, vector is not empty")
{
    std::vector<int> stdVector{ 1, 2, 3 };
    IVector<int> vector = winrt::make<winrt::impl::vector<int>>(std::move(stdVector));

    REQUIRE(vector.Size() == 3);
    vector.RemoveAt(1);
    REQUIRE(vector.Size() == 2);

    REQUIRE(vector.GetAt(0) == 1);
    REQUIRE(vector.GetAt(1) == 3);
}

TEST_CASE("IVector,RemoveAtEnd, past the end of the vector, vector is empty")
{
    IVector<int> vector = winrt::make<winrt::impl::vector<int>>();

    REQUIRE_THROWS_AS(vector.RemoveAtEnd(), winrt::hresult_out_of_bounds);
}

TEST_CASE("IVector,RemoveAtEnd, vector is not empty, no elements left after the removal")
{
    std::vector<int> stdVector{ 1 };
    IVector<int> vector = winrt::make<winrt::impl::vector<int>>(std::move(stdVector));

    vector.RemoveAtEnd();
    REQUIRE(vector.Size() == 0);
}

TEST_CASE("IVector,RemoveAtEnd, vector is not empty, elements remain after the removal")
{
    std::vector<int> stdVector{ 1, 2 };
    IVector<int> vector = winrt::make<winrt::impl::vector<int>>(std::move(stdVector));

    vector.RemoveAtEnd();
    REQUIRE(vector.Size() == 1);
    REQUIRE(vector.GetAt(0) == 1);
}

TEST_CASE("IVector,ReplaceAll, vector is empty")
{
    IVector<int> vector = winrt::make<winrt::impl::vector<int>>();
    std::array<int, 2> elements{ 1, 2 };

    vector.ReplaceAll(elements);
    REQUIRE(vector.Size() == elements.size());

    REQUIRE(vector.GetAt(0) == elements[0]);
    REQUIRE(vector.GetAt(1) == elements[1]);
}

TEST_CASE("IVector,ReplaceAll, vector is not empty, replace same number of elements")
{
    std::vector<int> stdVector{ 1, 2 };
    std::array<int, 2> elements{ 3, 4 };
    IVector<int> vector = winrt::make<winrt::impl::vector<int>>(std::move(stdVector));

    vector.ReplaceAll(elements);
    REQUIRE(vector.Size() == 2);
    REQUIRE(vector.GetAt(0) == 3);
    REQUIRE(vector.GetAt(1) == 4);
}

TEST_CASE("IVector,ReplaceAll, vector is not empty, replace with a higher number of elements")
{
    std::vector<int> stdVector{ 1, 2 };
    std::array<int, 3> elements{ 3, 4, 5 };
    IVector<int> vector = winrt::make<winrt::impl::vector<int>>(std::move(stdVector));

    vector.ReplaceAll(elements);
    REQUIRE(vector.Size() == 3);
    REQUIRE(vector.GetAt(0) == 3);
    REQUIRE(vector.GetAt(1) == 4);
    REQUIRE(vector.GetAt(2) == 5);
}

TEST_CASE("IVector,ReplaceAll, vector is not empty, replace with a less number of elements")
{
    std::vector<int> stdVector{ 1, 2 };
    std::array<int, 1> elements{ 3 };
    IVector<int> vector = winrt::make<winrt::impl::vector<int>>(std::move(stdVector));

    vector.ReplaceAll(elements);
    REQUIRE(vector.Size() == 1);
    REQUIRE(vector.GetAt(0) == 3);
}

TEST_CASE("IVector,ReplaceAll, vector is not empty, replace with no elements")
{
    std::vector<int> stdVector{ 1, 2 };
    winrt::array_ref<const int> elements;
    IVector<int> vector = winrt::make<winrt::impl::vector<int>>(std::move(stdVector));

    vector.ReplaceAll(elements);
    REQUIRE(vector.Size() == 0);
}

TEST_CASE("IVector,SetAt, vector is empty, first index")
{
    IVector<int> vector = winrt::make<winrt::impl::vector<int>>();

    REQUIRE_THROWS_AS(vector.SetAt(0, 10), winrt::hresult_out_of_bounds);
}

TEST_CASE("IVector,SetAt, vector is not empty, first index")
{
    std::vector<int> stdVector{ 1, 2 };
    IVector<int> vector = winrt::make<winrt::impl::vector<int>>(std::move(stdVector));
    const int value = 10;

    vector.SetAt(0, value);
    REQUIRE(vector.Size() == 2);
    REQUIRE(vector.GetAt(0) == value);
    REQUIRE(vector.GetAt(1) == 2);
}

TEST_CASE("IVector,SetAt, vector is not empty, index in the middle")
{
    std::vector<int> stdVector{ 1, 2, 3 };
    IVector<int> vector = winrt::make<winrt::impl::vector<int>>(std::move(stdVector));
    const int value = 10;

    vector.SetAt(1, value);
    REQUIRE(vector.Size() == 3);
    REQUIRE(vector.GetAt(0) == 1);
    REQUIRE(vector.GetAt(1) == value);
    REQUIRE(vector.GetAt(2) == 3);
}

TEST_CASE("IVector,SetAt, vector is not empty, last index")
{
    std::vector<int> stdVector{ 1, 2, 3 };
    IVector<int> vector = winrt::make<winrt::impl::vector<int>>(std::move(stdVector));
    const int value = 10;

    vector.SetAt(2, value);
    REQUIRE(vector.Size() == 3);
    REQUIRE(vector.GetAt(0) == 1);
    REQUIRE(vector.GetAt(1) == 2);
    REQUIRE(vector.GetAt(2) == value);
}

TEST_CASE("IVector,SetAt, vector is not empty, index past the end of the vector")
{
    std::vector<int> stdVector{ 1, 2, 3 };
    IVector<int> vector = winrt::make<winrt::impl::vector<int>>(std::move(stdVector));

    REQUIRE_THROWS_AS(vector.SetAt(3, 10), winrt::hresult_out_of_bounds);
}

#pragma endregion

#pragma region "Tests, IIterable, standalone"

TEST_CASE("IIterable,create,rvalue")
{
    std::vector<int> stdVector{ 1, 2 };
    IIterable<int> iter = winrt::make<winrt::impl::iterable<int>>(std::move(stdVector));
    REQUIRE(iter != nullptr);
    IIterator<int> itor = iter.First();
    REQUIRE(itor != nullptr);

    REQUIRE(itor.Current() == 1);
    REQUIRE(itor.MoveNext());
    REQUIRE(itor.Current() == 2);
    REQUIRE_FALSE(itor.MoveNext());
}

TEST_CASE("IIterable,create,iterators")
{
    std::vector<int> stdVector{ 1, 2 };
    IIterable<int> iter = winrt::make<winrt::impl::iterable<int>>(stdVector.data(), stdVector.data() + stdVector.size());
    REQUIRE(iter != nullptr);
    IIterator<int> itor = iter.First();
    REQUIRE(itor != nullptr);

    REQUIRE(itor.Current() == 1);
    REQUIRE(itor.MoveNext());
    REQUIRE(itor.Current() == 2);
    REQUIRE_FALSE(itor.MoveNext());
}

TEST_CASE("IIterable,create, il")
{
    auto il = { 1, 2 };
    IIterable<int> iter = winrt::make<winrt::impl::iterable<int>>(il);
    REQUIRE(iter != nullptr);
    IIterator<int> itor = iter.First();
    REQUIRE(itor != nullptr);

    REQUIRE(itor.Current() == 1);
    REQUIRE(itor.MoveNext());
    REQUIRE(itor.Current() == 2);
    REQUIRE_FALSE(itor.MoveNext());
}

#pragma endregion

#pragma region "Tests, IIterable, from vector"

TEST_CASE("IIterable, from vector, create,rvalue")
{
    std::vector<int> stdVector{ 1, 2 };
    IVector<int> vector = winrt::make<winrt::impl::vector<int>>(std::move(stdVector));
    IIterable<int> iter = vector;
    REQUIRE(iter != nullptr);
    IIterator<int> itor = iter.First();
    REQUIRE(itor != nullptr);

    REQUIRE(itor.Current() == 1);
    REQUIRE(itor.MoveNext());
    REQUIRE(itor.Current() == 2);
    REQUIRE_FALSE(itor.MoveNext());
}

TEST_CASE("IIterable, from vector, create,iterators")
{
    std::vector<int> stdVector{ 1, 2 };
    IVector<int> vector = winrt::make<winrt::impl::vector<int>>(stdVector.data(), stdVector.data() + stdVector.size());
    IIterable<int> iter = vector;
    REQUIRE(iter != nullptr);
    IIterator<int> itor = iter.First();
    REQUIRE(itor != nullptr);

    REQUIRE(itor.Current() == 1);
    REQUIRE(itor.MoveNext());
    REQUIRE(itor.Current() == 2);
    REQUIRE_FALSE(itor.MoveNext());
}

TEST_CASE("IIterable, from vector, create,il")
{
    auto il = { 1, 2 };
    IVector<int> vector = winrt::make<winrt::impl::vector<int>>(il);
    IIterable<int> iter = vector;
    REQUIRE(iter != nullptr);
    IIterator<int> itor = iter.First();
    REQUIRE(itor != nullptr);

    REQUIRE(itor.Current() == 1);
    REQUIRE(itor.MoveNext());
    REQUIRE(itor.Current() == 2);
    REQUIRE_FALSE(itor.MoveNext());
}

#pragma endregion

#pragma region "Tests, IIterable, from vectorview created from vector"

TEST_CASE("IIterable, from vectorview created from vector, rvalue")
{
    std::vector<int> stdVector{ 1, 2 };
    IVector<int> vector = winrt::make<winrt::impl::vector<int>>(std::move(stdVector));
    IVectorView<int> view = vector.GetView();
    IIterable<int> iter = view;
    REQUIRE(iter != nullptr);
    IIterator<int> itor = iter.First();
    REQUIRE(itor != nullptr);

    REQUIRE(itor.Current() == 1);
    REQUIRE(itor.MoveNext());
    REQUIRE(itor.Current() == 2);
    REQUIRE_FALSE(itor.MoveNext());
}

TEST_CASE("IIterable, from vectorview created from vector, create,iterators")
{
    std::vector<int> stdVector{ 1, 2 };
    IVector<int> vector = winrt::make<winrt::impl::vector<int>>(stdVector.data(), stdVector.data() + stdVector.size());
    IVectorView<int> view = vector.GetView();
    IIterable<int> iter = view;
    REQUIRE(iter != nullptr);
    IIterator<int> itor = iter.First();
    REQUIRE(itor != nullptr);

    REQUIRE(itor.Current() == 1);
    REQUIRE(itor.MoveNext());
    REQUIRE(itor.Current() == 2);
    REQUIRE_FALSE(itor.MoveNext());
}

TEST_CASE("IIterable, from vectorview created from vector, create,il")
{
    auto il = { 1, 2 };
    IVector<int> vector = winrt::make<winrt::impl::vector<int>>(il);
    IVectorView<int> view = vector.GetView();
    IIterable<int> iter = view;
    REQUIRE(iter != nullptr);
    IIterator<int> itor = iter.First();
    REQUIRE(itor != nullptr);

    REQUIRE(itor.Current() == 1);
    REQUIRE(itor.MoveNext());
    REQUIRE(itor.Current() == 2);
    REQUIRE_FALSE(itor.MoveNext());
}

#pragma endregion

#pragma region "Tests, IIterable, from vectorview created as standalone"

TEST_CASE("IIterable, from vectorview created as standalone, rvalue")
{
    std::vector<int> stdVector{ 1, 2 };
    IVectorView<int> view = winrt::make<winrt::impl::vector_view_standalone<int>>(std::move(stdVector));
    IIterable<int> iter = view;
    REQUIRE(iter != nullptr);
    IIterator<int> itor = iter.First();
    REQUIRE(itor != nullptr);

    REQUIRE(itor.Current() == 1);
    REQUIRE(itor.MoveNext());
    REQUIRE(itor.Current() == 2);
    REQUIRE_FALSE(itor.MoveNext());
}

TEST_CASE("IIterable, from vectorview created as standalone, create,iterators")
{
    std::vector<int> stdVector{ 1, 2 };
    IVectorView<int> view = winrt::make<winrt::impl::vector_view_standalone<int>>(stdVector.data(), stdVector.data() + stdVector.size());
    IIterable<int> iter = view;
    REQUIRE(iter != nullptr);
    IIterator<int> itor = iter.First();
    REQUIRE(itor != nullptr);

    REQUIRE(itor.Current() == 1);
    REQUIRE(itor.MoveNext());
    REQUIRE(itor.Current() == 2);
    REQUIRE_FALSE(itor.MoveNext());
}

TEST_CASE("IIterable, from vectorview created as standalone, create,il")
{
    auto il = { 1, 2 };
    IVectorView<int> view = winrt::make<winrt::impl::vector_view_standalone<int>>(il);
    IIterable<int> iter = view;
    REQUIRE(iter != nullptr);
    IIterator<int> itor = iter.First();
    REQUIRE(itor != nullptr);

    REQUIRE(itor.Current() == 1);
    REQUIRE(itor.MoveNext());
    REQUIRE(itor.Current() == 2);
    REQUIRE_FALSE(itor.MoveNext());
}

#pragma endregion

#pragma region "Tests, IIterator"

TEST_CASE("IIterator,current,current has value")
{
    std::vector<int> stdVector{ 1, 2 };
    IIterable<int> iter = winrt::make<winrt::impl::iterable<int>>(std::move(stdVector));
    IIterator<int> itor = iter.First();
    REQUIRE(itor != nullptr);
    REQUIRE(itor.Current() == 1);
}

TEST_CASE("IIterator,current,throws when empty")
{
    std::vector<int> stdVector;
    IIterable<int> iter = winrt::make<winrt::impl::iterable<int>>(std::move(stdVector));
    IIterator<int> itor = iter.First();
    REQUIRE(itor != nullptr);
    REQUIRE_THROWS_AS(itor.Current(), winrt::hresult_out_of_bounds);
}

TEST_CASE("IIterator,HasCurrent,true")
{
    std::vector<int> stdVector{ 1, 2 };
    IIterable<int> iter = winrt::make<winrt::impl::iterable<int>>(std::move(stdVector));
    IIterator<int> itor = iter.First();
    REQUIRE(itor.HasCurrent());
}

TEST_CASE("IIterator,HasCurrent,false")
{
    std::vector<int> stdVector;;
    IIterable<int> iter = winrt::make<winrt::impl::iterable<int>>(std::move(stdVector));
    IIterator<int> itor = iter.First();
    REQUIRE(itor.HasCurrent() == false);
}

TEST_CASE("IIterator,MoveNext")
{
    std::vector<int> stdVector{ 1, 2 };
    std::vector<int> expectedValues = stdVector;
    IIterable<int> iter = winrt::make<winrt::impl::iterable<int>>(std::move(stdVector));
    IIterator<int> itor = iter.First();

    int index = 0;
    while (itor.HasCurrent())
    {
        auto itorValue = itor.Current();
        auto stdVectorValue = expectedValues[index];
        REQUIRE(itorValue == stdVectorValue);

        index++;
        itor.MoveNext();
    }

    REQUIRE(index == 2);
}

TEST_CASE("IIterator,Invalidate iterator, Current")
{
    std::vector<int> stdVector{ 1, 2 };
    IVector<int> iter = winrt::make<winrt::impl::vector<int>>(std::move(stdVector));
    IIterator<int> itor = iter.First();

    iter.Append(3);
    REQUIRE_THROWS_AS(itor.Current(), winrt::hresult_changed_state);
}

TEST_CASE("IIterator,Invalidate iterator, HasCurrent")
{
    std::vector<int> stdVector{ 1, 2 };
    IVector<int> vector = winrt::make<winrt::impl::vector<int>>(std::move(stdVector));
    IIterator<int> itor = vector.First();

    vector.Append(3);
    REQUIRE_THROWS_AS(itor.HasCurrent(), winrt::hresult_changed_state);
}

TEST_CASE("IIterator,Invalidate iterator, MoveNext")
{
    std::vector<int> stdVector{ 1, 2 };
    IVector<int> vector = winrt::make<winrt::impl::vector<int>>(std::move(stdVector));
    IIterator<int> itor = vector.First();

    vector.Append(3);
    REQUIRE_THROWS_AS(itor.MoveNext(), winrt::hresult_changed_state);
}

TEST_CASE("IIterator,Invalidate iterator, GetMany")
{
    std::vector<int> stdVector{ 1, 2 };
    IVector<int> vector = winrt::make<winrt::impl::vector<int>>(std::move(stdVector));
    IIterator<int> itor = vector.First();
    std::array<int, 2> output;

    vector.Append(3);
    REQUIRE_THROWS_AS(itor.GetMany(output), winrt::hresult_changed_state);
}

TEST_CASE("IIterator,GetMany, output array has less size than the iterator")
{
    std::vector<int> stdVector{ 1, 2 };
    IIterable<int> iter = winrt::make<winrt::impl::iterable<int>>(std::move(stdVector));
    IIterator<int> itor = iter.First();
    std::array<int, 1> output;

    REQUIRE(itor.GetMany(output) == 1);
    REQUIRE(output.size() == 1);
    REQUIRE(output.at(0) == 1);
}

TEST_CASE("IIterator,GetMany, output array has the same number of elements")
{
    std::vector<int> stdVector{ 1, 2 };
    IIterable<int> iter = winrt::make<winrt::impl::iterable<int>>(std::move(stdVector));
    IIterator<int> itor = iter.First();
    std::array<int, 2> output;

    REQUIRE(itor.GetMany(output) == 2);
    REQUIRE(output.size() == 2);
    REQUIRE(output.at(0) == 1);
    REQUIRE(output.at(1) == 2);
}

TEST_CASE("IIterator,GetMany, output array has more slots than the iterator")
{
    std::vector<int> stdVector{ 1, 2 };
    IIterable<int> iter = winrt::make<winrt::impl::iterable<int>>(std::move(stdVector));
    IIterator<int> itor = iter.First();
    std::array<int, 3> output{ 0, 0, 0 };

    REQUIRE(itor.GetMany(output) == 2);
    REQUIRE(output.size() == 3);
    REQUIRE(output.at(0) == 1);
    REQUIRE(output.at(1) == 2);
    REQUIRE(output.at(2) == 0);
}

#pragma endregion

#pragma region "IVector, IVectorView, IIterable, for loop invalidation"

TEST_CASE("IVector, for loop , changing vector does not invalidate iterator")
{
    std::vector<int> stdVector{ 1, 2 };
    IVector<int> vector = winrt::make<winrt::impl::vector<int>>(std::move(stdVector));

    // This bypasses normal iterator creation, hence no invalidation
    for (auto value : vector)
    {
        value;
        vector.Append(3);
    }
}

TEST_CASE("IVectorView, for loop , changing vector invalidates iterator created from the view")
{
    std::vector<int> stdVector{ 1, 2 };
    IVector<int> vector = winrt::make<winrt::impl::vector<int>>(std::move(stdVector));
    IVectorView<int> view = vector.GetView();

    auto func = [&]
    {
        for (auto value : view)
        {
            value;
            vector.Append(3);
        }
    };

    REQUIRE_THROWS_AS(func(), winrt::hresult_changed_state);
}

TEST_CASE("IIterable, for loop , Invalidate iterator")
{
    std::vector<int> stdVector{ 1, 2 };
    IVector<int> vector = winrt::make<winrt::impl::vector<int>>(std::move(stdVector));
    IIterable<int> iter = vector;

    auto func = [&]
    {
        for (auto value : iter)
        {
            value;
            vector.Append(3);
        }
    };

    REQUIRE_THROWS_AS(func(), winrt::hresult_changed_state);
}

#pragma endregion

#pragma region "Tests, IVectorView, standalone"

TEST_CASE("IVectorView,create,rvalue")
{
    std::vector<int> stdVector{ 1, 2 };
    IVectorView<int> view = winrt::make<winrt::impl::vector_view_standalone<int>>(std::move(stdVector));
    REQUIRE(view != nullptr);
    REQUIRE(view.Size() == 2);
    REQUIRE(view.GetAt(0) == 1);
    REQUIRE(view.GetAt(1) == 2);
}

TEST_CASE("IVectorView,create,iterators")
{
    std::vector<int> stdVector{ 1, 2 };
    IVectorView<int> view = winrt::make<winrt::impl::vector_view_standalone<int>>(stdVector.data(), stdVector.data() + stdVector.size());
    REQUIRE(view != nullptr);
    REQUIRE(view.Size() == 2);
    REQUIRE(view.GetAt(0) == 1);
    REQUIRE(view.GetAt(1) == 2);
}

TEST_CASE("IVectorView,create,il")
{
    auto il = { 1, 2 };
    IVectorView<int> view = winrt::make<winrt::impl::vector_view_standalone<int>>(il);
    REQUIRE(view != nullptr);
    REQUIRE(view.Size() == 2);
    REQUIRE(view.GetAt(0) == 1);
    REQUIRE(view.GetAt(1) == 2);
}

TEST_CASE("IVectorView,create,empty")
{
    IVectorView<int> view = winrt::make<winrt::impl::vector_view_standalone<int>>();
    REQUIRE(view != nullptr);
    REQUIRE(view.Size() == 0);
}

TEST_CASE("IVectorView,GetAt, empty vector")
{
    IVectorView<int> view = winrt::make<winrt::impl::vector_view_standalone<int>>();

    REQUIRE_THROWS_AS(view.GetAt(0), winrt::hresult_out_of_bounds);
}

TEST_CASE("IVectorView,GetAt")
{
    std::vector<int> stdVector{ 1, 2, 3 };
    IVectorView<int> view = winrt::make<winrt::impl::vector_view_standalone<int>>(std::move(stdVector));

    REQUIRE(view.GetAt(0) == 1);
    REQUIRE(view.GetAt(1) == 2);
    REQUIRE(view.GetAt(2) == 3);
}

TEST_CASE("IVectorView,GetAt, out of bounds")
{
    std::vector<int> stdVector{ 1, 2, 3 };
    IVectorView<int> view = winrt::make<winrt::impl::vector_view_standalone<int>>(std::move(stdVector));

    REQUIRE_THROWS_AS(view.GetAt(3), winrt::hresult_out_of_bounds);
}

TEST_CASE("IVectorView, GetAt, invalid index")
{
    std::vector<int> stdVector{ 1, 2 };
    IVectorView<int> view = winrt::make<winrt::impl::vector_view_standalone<int>>(std::move(stdVector));
    
    REQUIRE_THROWS_AS(view.GetAt(3), winrt::hresult_out_of_bounds);
}

TEST_CASE("IVectorView,GetMany, empty vector")
{
    IVectorView<int> view = winrt::make<winrt::impl::vector_view_standalone<int>>();
    winrt::array_ref<int> output;

    REQUIRE(view.GetMany(0, output) == 0);
}

TEST_CASE("IVectorView,GetMany, empty vector, index past the size")
{
    std::vector<int> stdVector{ 1, 2, 3 };
    IVectorView<int> view = winrt::make<winrt::impl::vector_view_standalone<int>>(std::move(stdVector));
    std::array<int, 3> output{ 0, 0, 0 };

    REQUIRE(view.GetMany(3, output) == 0);
}

TEST_CASE("IVectorView,GetMany, empty vector, index way past the size")
{
    std::vector<int> stdVector{ 1, 2, 3 };
    IVectorView<int> view = winrt::make<winrt::impl::vector_view_standalone<int>>(std::move(stdVector));
    std::array<int, 3> output{ 0, 0, 0 };

    REQUIRE(view.GetMany(40, output) == 0);
}

TEST_CASE("IVectorView,GetMany, non empty vector")
{
    std::vector<int> stdVector{ 1, 2, 3 };
    IVectorView<int> view = winrt::make<winrt::impl::vector_view_standalone<int>>(std::move(stdVector));
    std::array<int, 3> output{ 0, 0, 0 };

    auto count = view.GetMany(0, output);
    REQUIRE(count == 3);

    REQUIRE(output[0] == 1);
    REQUIRE(output[1] == 2);
    REQUIRE(output[2] == 3);
}

TEST_CASE("IVectorView,GetMany,request less than size of IVector,beginning of the IVector")
{
    std::vector<int> stdVector{ 1, 2, 3 };
    IVectorView<int> view = winrt::make<winrt::impl::vector_view_standalone<int>>(std::move(stdVector));
    std::array<int, 2> output{ 0, 0 };

    auto count = view.GetMany(0, output);
    REQUIRE(count == 2);

    REQUIRE(output[0] == 1);
    REQUIRE(output[1] == 2);
}

TEST_CASE("IVectorView,GetMany,request less than size of IVector,middle of the IVector")
{
    std::vector<int> stdVector{ 1, 2, 3, 4 };
    IVectorView<int> view = winrt::make<winrt::impl::vector_view_standalone<int>>(std::move(stdVector));
    std::array<int, 2> output{ 0, 0 };

    auto count = view.GetMany(1, output);
    REQUIRE(count == 2);

    REQUIRE(output[0] == 2);
    REQUIRE(output[1] == 3);
}

TEST_CASE("IVectorView,GetMany,request less than size of IVector,end of the IVector")
{
    std::vector<int> stdVector{ 1, 2, 3, 4 };
    IVectorView<int> view = winrt::make<winrt::impl::vector_view_standalone<int>>(std::move(stdVector));
    std::array<int, 2> output{ 0, 0 };

    auto count = view.GetMany(2, output);
    REQUIRE(count == 2);

    REQUIRE(output[0] == 3);
    REQUIRE(output[1] == 4);
}

TEST_CASE("IVectorView,GetMany,request less than size of IVector,past of the end of the vector")
{
    std::vector<int> stdVector{ 1, 2, 3 };
    IVectorView<int> view = winrt::make<winrt::impl::vector_view_standalone<int>>(std::move(stdVector));
    std::array<int, 2> output{ 0, 0 };

    auto count = view.GetMany(2, output);
    REQUIRE(count == 1);

    REQUIRE(output[0] == 3);
    // Call did not write a value
    REQUIRE(output[1] == 0);
}

TEST_CASE("IVectorView,GetMany,request more than size of IVector,past of the end of the vector")
{
    std::vector<int> stdVector{ 1, 2, 3 };
    IVectorView<int> view = winrt::make<winrt::impl::vector_view_standalone<int>>(std::move(stdVector));
    std::array<int, 4> output{ 0, 0, 0, 0 };

    auto count = view.GetMany(0, output);
    REQUIRE(count == 3);

    REQUIRE(output[0] == 1);
    REQUIRE(output[1] == 2);
    REQUIRE(output[2] == 3);
    // Call did not write a value
    REQUIRE(output[3] == 0);
}

TEST_CASE("IVectorView,IndexOf, items exist")
{
    std::vector<int> stdVector{ 1, 2, 3 };
    IVectorView<int> view = winrt::make<winrt::impl::vector_view_standalone<int>>(std::move(stdVector));

    uint32_t index = 0;
    bool found = false;

    found = view.IndexOf(1, index);
    REQUIRE(found);
    REQUIRE(index == 0);
    found = view.IndexOf(2, index);
    REQUIRE(found);
    REQUIRE(index == 1);
    found = view.IndexOf(3, index);
    REQUIRE(found);
    REQUIRE(index == 2);
}

TEST_CASE("IVectorView,IndexOf, item does not exists, vector is not empty")
{
    std::vector<int> stdVector{ 1, 2, 3 };
    IVectorView<int> view = winrt::make<winrt::impl::vector_view_standalone<int>>(std::move(stdVector));

    uint32_t index = 9999;
    bool found = false;

    found = view.IndexOf(10, index);
    REQUIRE_FALSE(found);
    REQUIRE(index == 0);
}

TEST_CASE("IVectorView,IndexOf, item does not exists, vector is empty")
{
    IVectorView<int> view = winrt::make<winrt::impl::vector_view_standalone<int>>();

    uint32_t index = 9999;
    bool found = false;

    found = view.IndexOf(10, index);
    REQUIRE_FALSE(found);
    REQUIRE(index == 0);
}

#pragma endregion

#pragma region "Tests, IVectorView from IVector"

TEST_CASE("IVectorView, from Vector,create,rvalue")
{
    std::vector<int> stdVector{ 1, 2 };
    IVector<int> vector = winrt::make<winrt::impl::vector<int>>(std::move(stdVector));
    IVectorView<int> view = vector.GetView();
    REQUIRE(view != nullptr);
    REQUIRE(view.Size() == 2);
    REQUIRE(view.GetAt(0) == 1);
    REQUIRE(view.GetAt(1) == 2);
}

TEST_CASE("IVectorView, from Vector,create,iterators")
{
    std::vector<int> stdVector{ 1, 2 };
    IVector<int> vector = winrt::make<winrt::impl::vector<int>>(stdVector.data(), stdVector.data() + stdVector.size());
    IVectorView<int> view = vector.GetView();
    REQUIRE(view != nullptr);
    REQUIRE(view.Size() == 2);
    REQUIRE(view.GetAt(0) == 1);
    REQUIRE(view.GetAt(1) == 2);
}

TEST_CASE("IVectorView, from Vector,create,il")
{
    auto il = { 1, 2 };
    IVector<int> vector = winrt::make<winrt::impl::vector<int>>(il);
    IVectorView<int> view = vector.GetView();
    REQUIRE(view != nullptr);
    REQUIRE(view.Size() == 2);
    REQUIRE(view.GetAt(0) == 1);
    REQUIRE(view.GetAt(1) == 2);
}

TEST_CASE("IVectorView, from Vector,create,empty")
{
    IVector<int> vector = winrt::make<winrt::impl::vector<int>>();
    IVectorView<int> view = vector.GetView();

    REQUIRE(view != nullptr);
    REQUIRE(view.Size() == 0);
}

TEST_CASE("IVectorView, from Vector,GetAt, empty vector")
{
    IVector<int> vector = winrt::make<winrt::impl::vector<int>>();
    IVectorView<int> view = vector.GetView();

    REQUIRE_THROWS_AS(view.GetAt(0), winrt::hresult_out_of_bounds);
}

TEST_CASE("IVectorView, from Vector,GetAt")
{
    std::vector<int> stdVector{ 1, 2, 3 };
    IVector<int> vector = winrt::make<winrt::impl::vector<int>>(std::move(stdVector));
    IVectorView<int> view = vector.GetView();

    REQUIRE(view.GetAt(0) == 1);
    REQUIRE(view.GetAt(1) == 2);
    REQUIRE(view.GetAt(2) == 3);
}

TEST_CASE("IVectorView, from Vector,GetAt, out of bounds")
{
    std::vector<int> stdVector{ 1, 2, 3 };
    IVector<int> vector = winrt::make<winrt::impl::vector<int>>(std::move(stdVector));
    IVectorView<int> view = vector.GetView();


    REQUIRE_THROWS_AS(view.GetAt(3), winrt::hresult_out_of_bounds);
}

TEST_CASE("IVectorView, from Vector, GetAt, invalid index")
{
    std::vector<int> stdVector{ 1, 2 };
    IVector<int> vector = winrt::make<winrt::impl::vector<int>>(std::move(stdVector));
    IVectorView<int> view = vector.GetView();

    
    REQUIRE_THROWS_AS(view.GetAt(3), winrt::hresult_out_of_bounds);
}

TEST_CASE("IVectorView, from Vector,GetMany, empty vector")
{
    IVector<int> vector = winrt::make<winrt::impl::vector<int>>();
    IVectorView<int> view = vector.GetView();
    winrt::array_ref<int> output;

    REQUIRE(view.GetMany(0, output) == 0);
}

TEST_CASE("IVectorView, from Vector,GetMany, empty vector, index past the size")
{
    std::vector<int> stdVector{ 1, 2, 3 };
    IVector<int> vector = winrt::make<winrt::impl::vector<int>>(std::move(stdVector));
    IVectorView<int> view = vector.GetView();
    std::array<int, 3> output{ 0, 0, 0 };

    REQUIRE(view.GetMany(3, output) == 0);
}

TEST_CASE("IVectorView, from Vector,GetMany, non empty vector")
{
    std::vector<int> stdVector{ 1, 2, 3 };
    IVector<int> vector = winrt::make<winrt::impl::vector<int>>(std::move(stdVector));
    IVectorView<int> view = vector.GetView();
    std::array<int, 3> output{ 0, 0, 0 };

    auto count = view.GetMany(0, output);
    REQUIRE(count == 3);

    REQUIRE(output[0] == 1);
    REQUIRE(output[1] == 2);
    REQUIRE(output[2] == 3);
}

TEST_CASE("IVectorView, from Vector,GetMany,request less than size of IVector,beginning of the IVector")
{
    std::vector<int> stdVector{ 1, 2, 3 };
    IVector<int> vector = winrt::make<winrt::impl::vector<int>>(std::move(stdVector));
    IVectorView<int> view = vector.GetView();
    std::array<int, 2> output{ 0, 0 };

    auto count = view.GetMany(0, output);
    REQUIRE(count == 2);

    REQUIRE(output[0] == 1);
    REQUIRE(output[1] == 2);
}

TEST_CASE("IVectorView, from Vector,GetMany,request less than size of IVector,middle of the IVector")
{
    std::vector<int> stdVector{ 1, 2, 3, 4 };
    IVector<int> vector = winrt::make<winrt::impl::vector<int>>(std::move(stdVector));
    IVectorView<int> view = vector.GetView();
    std::array<int, 2> output{ 0, 0 };

    auto count = view.GetMany(1, output);
    REQUIRE(count == 2);

    REQUIRE(output[0] == 2);
    REQUIRE(output[1] == 3);
}

TEST_CASE("IVectorView, from Vector,GetMany,request less than size of IVector,end of the IVector")
{
    std::vector<int> stdVector{ 1, 2, 3, 4 };
    IVector<int> vector = winrt::make<winrt::impl::vector<int>>(std::move(stdVector));
    IVectorView<int> view = vector.GetView();
    std::array<int, 2> output{ 0, 0 };

    auto count = view.GetMany(2, output);
    REQUIRE(count == 2);

    REQUIRE(output[0] == 3);
    REQUIRE(output[1] == 4);
}

TEST_CASE("IVectorView, from Vector,GetMany,request less than size of IVector,past of the end of the vector")
{
    std::vector<int> stdVector{ 1, 2, 3 };
    IVector<int> vector = winrt::make<winrt::impl::vector<int>>(std::move(stdVector));
    IVectorView<int> view = vector.GetView();
    std::array<int, 2> output{ 0, 0 };

    auto count = view.GetMany(2, output);
    REQUIRE(count == 1);

    REQUIRE(output[0] == 3);
    // Call did not write a value
    REQUIRE(output[1] == 0);
}

TEST_CASE("IVectorView, from Vector,GetMany,request more than size of IVector,past of the end of the vector")
{
    std::vector<int> stdVector{ 1, 2, 3 };
    IVector<int> vector = winrt::make<winrt::impl::vector<int>>(std::move(stdVector));
    IVectorView<int> view = vector.GetView();
    std::array<int, 4> output{ 0, 0, 0, 0 };

    auto count = view.GetMany(0, output);
    REQUIRE(count == 3);

    REQUIRE(output[0] == 1);
    REQUIRE(output[1] == 2);
    REQUIRE(output[2] == 3);
    // Call did not write a value
    REQUIRE(output[3] == 0);
}

TEST_CASE("IVectorView, from Vector,IndexOf, items exist")
{
    std::vector<int> stdVector{ 1, 2, 3 };
    IVector<int> vector = winrt::make<winrt::impl::vector<int>>(std::move(stdVector));
    IVectorView<int> view = vector.GetView();

    uint32_t index = 0;
    bool found = false;

    found = view.IndexOf(1, index);
    REQUIRE(found);
    REQUIRE(index == 0);
    found = view.IndexOf(2, index);
    REQUIRE(found);
    REQUIRE(index == 1);
    found = view.IndexOf(3, index);
    REQUIRE(found);
    REQUIRE(index == 2);
}

TEST_CASE("IVectorView, from Vector,IndexOf, item does not exists, vector is not empty")
{
    std::vector<int> stdVector{ 1, 2, 3 };
    IVector<int> vector = winrt::make<winrt::impl::vector<int>>(std::move(stdVector));
    IVectorView<int> view = vector.GetView();

    uint32_t index = 9999;
    bool found = false;

    found = view.IndexOf(10, index);
    REQUIRE_FALSE(found);
    REQUIRE(index == 0);
}

TEST_CASE("IVectorView, from Vector,IndexOf, item does not exists, vector is empty")
{
    IVector<int> vector = winrt::make<winrt::impl::vector<int>>();
    IVectorView<int> view = vector.GetView();

    uint32_t index = 9999;
    bool found = false;

    found = view.IndexOf(10, index);
    REQUIRE_FALSE(found);
    REQUIRE(index == 0);
}

#pragma endregion

#pragma region "Tests, Projected IVector, create"

TEST_CASE("IVector, projected type,create,rvalue")
{
    std::vector<int> stdVector{ 1, 2 };
    IVector<int> vector(std::move(stdVector));
    REQUIRE(vector != nullptr);
    REQUIRE(vector.Size() == 2);
    REQUIRE(vector.GetAt(0) == 1);
    REQUIRE(vector.GetAt(1) == 2);
}

TEST_CASE("IVector, projected type,create,iterators")
{
    std::vector<int> stdVector{ 1, 2 };
    IVector<int> vector(stdVector.data(), stdVector.data() + stdVector.size());
    REQUIRE(vector != nullptr);
    REQUIRE(vector.Size() == 2);
    REQUIRE(vector.GetAt(0) == 1);
    REQUIRE(vector.GetAt(1) == 2);
}

TEST_CASE("IVector, projected type,create,begin-end")
{
    auto il = { 1, 2 };
    IVector<int> vector(il);
    REQUIRE(vector != nullptr);
    REQUIRE(vector.Size() == 2);
    REQUIRE(vector.GetAt(0) == 1);
    REQUIRE(vector.GetAt(1) == 2);
}

#pragma endregion

#pragma region "Tests, Projected IVectorView, create"

TEST_CASE("IVectorView, projected type,create,rvalue")
{
    std::vector<int> stdVector{ 1, 2 };
    IVectorView<int> view(std::move(stdVector));
    REQUIRE(view != nullptr);
    REQUIRE(view.Size() == 2);
    REQUIRE(view.GetAt(0) == 1);
    REQUIRE(view.GetAt(1) == 2);
}

TEST_CASE("IVectorView, projected type,create,iterators")
{
    std::vector<int> stdVector{ 1, 2 };
    IVectorView<int> view(stdVector.data(), stdVector.data() + stdVector.size());
    REQUIRE(view != nullptr);
    REQUIRE(view.Size() == 2);
    REQUIRE(view.GetAt(0) == 1);
    REQUIRE(view.GetAt(1) == 2);
}

TEST_CASE("IVectorView, projected type,create,il")
{
    auto il = { 1, 2 };
    IVectorView<int> view(il);
    REQUIRE(view != nullptr);
    REQUIRE(view.Size() == 2);
    REQUIRE(view.GetAt(0) == 1);
    REQUIRE(view.GetAt(1) == 2);
}

#pragma endregion

#pragma region "Tests, Projected IIterable, create"

TEST_CASE("IIterable, projected type,create,rvalue")
{
    std::vector<int> stdVector{ 1, 2 };
    IIterable<int> iter(std::move(stdVector));
    REQUIRE(iter != nullptr);
    IIterator<int> itor = iter.First();
    REQUIRE(itor != nullptr);

    REQUIRE(itor.HasCurrent());
    REQUIRE(itor.Current() == 1);
    REQUIRE(itor.MoveNext());
    REQUIRE(itor.Current() == 2);
    REQUIRE_FALSE(itor.MoveNext());
}

TEST_CASE("IIterable, projected type,create,iterators")
{
    std::vector<int> stdVector{ 1, 2 };
   IIterable<int> iter(stdVector.data(), stdVector.data() + stdVector.size());
    REQUIRE(iter != nullptr);
    IIterator<int> itor = iter.First();
    REQUIRE(itor != nullptr);

    REQUIRE(itor.HasCurrent());
    REQUIRE(itor.Current() == 1);
    REQUIRE(itor.MoveNext());
    REQUIRE(itor.Current() == 2);
    REQUIRE_FALSE(itor.MoveNext());
}

TEST_CASE("IIterable, projected type,create,il")
{
    auto il = { 1, 2 };
    IIterable<int> iter(il);
    REQUIRE(iter != nullptr);
    IIterator<int> itor = iter.First();
    REQUIRE(itor != nullptr);

    REQUIRE(itor.HasCurrent());
    REQUIRE(itor.Current() == 1);
    REQUIRE(itor.MoveNext());
    REQUIRE(itor.Current() == 2);
    REQUIRE_FALSE(itor.MoveNext());
}

#pragma endregion

#pragma region "Tests, calling function with IVector"

void FunctionThatTakesIVector(IVector<int> vector)
{
    REQUIRE(vector.Size() == 2);
    REQUIRE(vector.GetAt(0) == 1);
    REQUIRE(vector.GetAt(1) == 2);
}

TEST_CASE("IVector, projected type,call function,rvalue")
{
    std::vector<int> stdVector{ 1, 2 };
    FunctionThatTakesIVector(std::move(stdVector));
}

TEST_CASE("IVector, projected type,call function,il")
{
    FunctionThatTakesIVector({ 1, 2 });
}

#pragma endregion

#pragma region "Tests, calling function with IVectorView"

void FunctionThatTakesIVectorView(IVectorView<int> view)
{
    REQUIRE(view.Size() == 2);
    REQUIRE(view.GetAt(0) == 1);
    REQUIRE(view.GetAt(1) == 2);
}

TEST_CASE("IVectorView, projected type,call function,rvalue")
{
    std::vector<int> stdVector{ 1, 2 };
    FunctionThatTakesIVectorView(std::move(stdVector));
}

TEST_CASE("IVectorView, projected type,call function,il")
{
    FunctionThatTakesIVectorView({ 1, 2 });
}

#pragma endregion

#pragma region "Tests, calling function with IIterable"

void FunctionThatTakesIIterable(IIterable<int> iter)
{
    IIterator<int> itor = iter.First();

    REQUIRE(itor.HasCurrent());
    REQUIRE(itor.Current() == 1);
    REQUIRE(itor.MoveNext());
    REQUIRE(itor.Current() == 2);
    REQUIRE_FALSE(itor.MoveNext());
}

TEST_CASE("IIterable, projected type,call function,rvalue")
{
    std::vector<int> stdVector{ 1, 2 };
    FunctionThatTakesIIterable(std::move(stdVector));
}

TEST_CASE("IIterable, projected type,call function,il")
{
    FunctionThatTakesIIterable({ 1, 2 });
}

#pragma endregion

#pragma region "Tests, IVector, equal operator, rvalue"

TEST_CASE("IVector, equal operator, rvalue")
{
    std::vector<int> stdVector{ 1, 2 };
    IVector<int> vector = std::move(stdVector);
    REQUIRE(vector != nullptr);

    REQUIRE(vector.Size() == 2);
    REQUIRE(vector.GetAt(0) == 1);
    REQUIRE(vector.GetAt(1) == 2);
}

TEST_CASE("IVector, equal operator, il")
{
    IVector<int> vector  = { 1, 2 };
    REQUIRE(vector != nullptr);

    REQUIRE(vector.Size() == 2);
    REQUIRE(vector.GetAt(0) == 1);
    REQUIRE(vector.GetAt(1) == 2);
}

#pragma endregion

#pragma region "Tests, IVectorView, equal operator, rvalue"

TEST_CASE("IVectorView, equal operator, rvalue")
{
    std::vector<int> stdVector{ 1, 2 };
    IVectorView<int> view = std::move(stdVector);
    REQUIRE(view != nullptr);

    REQUIRE(view.Size() == 2);
    REQUIRE(view.GetAt(0) == 1);
    REQUIRE(view.GetAt(1) == 2);
}

TEST_CASE("IVectorView, equal operator, il")
{
    IVectorView<int> view = { 1, 2 };
    REQUIRE(view != nullptr);

    REQUIRE(view.Size() == 2);
    REQUIRE(view.GetAt(0) == 1);
    REQUIRE(view.GetAt(1) == 2);
}

#pragma endregion

#pragma region "Tests, IITerable, equal operator, rvalue"

TEST_CASE("IITerable, equal operator, rvalue")
{
    std::vector<int> stdVector{ 1, 2 };
    IVectorView<int> iter = std::move(stdVector);
    REQUIRE(iter != nullptr);
    IIterator<int> itor = iter.First();

    REQUIRE(itor.HasCurrent());
    REQUIRE(itor.Current() == 1);
    REQUIRE(itor.MoveNext());
    REQUIRE(itor.Current() == 2);
    REQUIRE_FALSE(itor.MoveNext());
}

TEST_CASE("IITerable, equal operator, il")
{
    IVectorView<int> iter = { 1, 2 };
    REQUIRE(iter != nullptr);
    IIterator<int> itor = iter.First();

    REQUIRE(itor.HasCurrent());
    REQUIRE(itor.Current() == 1);
    REQUIRE(itor.MoveNext());
    REQUIRE(itor.Current() == 2);
    REQUIRE_FALSE(itor.MoveNext());
}

#pragma endregion

#pragma region "IVector, inline il"

TEST_CASE("IVector, inline il")
{
    IVector<int> vector  { 1, 2 };
    REQUIRE(vector != nullptr);

    REQUIRE(vector.Size() == 2);
    REQUIRE(vector.GetAt(0) == 1);
    REQUIRE(vector.GetAt(1) == 2);
}

#pragma endregion

#pragma region "IVectorView, inline il"

TEST_CASE("IVectorView, inline il")
{
    IVectorView<int> view { 1, 2 };
    REQUIRE(view != nullptr);

    REQUIRE(view.Size() == 2);
    REQUIRE(view.GetAt(0) == 1);
    REQUIRE(view.GetAt(1) == 2);
}

#pragma endregion

#pragma region "IIterable, inline il"

TEST_CASE("IIterable, inline il")
{
    IIterable<int> iter { 1, 2 };
    REQUIRE(iter != nullptr);
    IIterator<int> itor = iter.First();

    REQUIRE(itor.HasCurrent());
    REQUIRE(itor.Current() == 1);
    REQUIRE(itor.MoveNext());
    REQUIRE(itor.Current() == 2);
    REQUIRE_FALSE(itor.MoveNext());
}

#pragma endregion