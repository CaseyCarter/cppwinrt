#include "pch.h"
#include "catch.hpp"

using namespace winrt;
using namespace Windows::Foundation;
using namespace Windows::Foundation::Collections;
using namespace Component;

TEST_CASE("FastInput")
{
    FastInput fast;

    {
        REQUIRE(fast.String(L"One") == L"One");
        REQUIRE(fast.String(std::wstring_view(L"One")) == L"One");
        REQUIRE(fast.String(std::wstring(L"One")) == L"One");
        REQUIRE(fast.String(hstring(L"One")) == L"One");
    }

    {
        REQUIRE(fast.Array({ L"One",L"Two",L"Three" }) == L"OneTwoThree");
        REQUIRE(fast.Array(std::vector<hstring>{ L"One", L"Two", L"Three" }) == L"OneTwoThree");
        REQUIRE(fast.Array(std::array<hstring, 3>{ L"One", L"Two", L"Three" }) == L"OneTwoThree");

        // TODO: array_view doesn't bind to... wait for it array_view or com_array.
        // Need to define com_array without inheriting from array_view.
        // Then array_view can bind to com_array for input and symmetry.
    }

    {
        REQUIRE(fast.Iterable({ L"One",L"Two",L"Three" }) == L"OneTwoThree");
        REQUIRE_THROWS_AS(fast.UseIterable(), hresult_illegal_method_call);

        REQUIRE(fast.Iterable(std::vector<hstring>{ L"One", L"Two", L"Three" }) == L"OneTwoThree");
        fast.UseIterable();

        std::vector<hstring> vector{ L"One",L"Two",L"Three" };
        REQUIRE(fast.Iterable(vector) == L"OneTwoThree");
        REQUIRE_THROWS_AS(fast.UseIterable(), hresult_illegal_method_call);

        IVector<hstring> convertible = single_threaded_vector<hstring>({ L"One",L"Two",L"Three" });
        REQUIRE(fast.Iterable(convertible) == L"OneTwoThree");
        fast.UseIterable();

        std::array<hstring, 3> range{ L"One",L"Two",L"Three" };
        REQUIRE(fast.Iterable({ range.begin(), range.end() }) == L"OneTwoThree");
        REQUIRE_THROWS_AS(fast.UseIterable(), hresult_illegal_method_call);

        IIterable<hstring> actual = single_threaded_vector<hstring>({ L"One",L"Two",L"Three" });
        REQUIRE(fast.Iterable(actual) == L"OneTwoThree");
        fast.UseIterable();

        REQUIRE(fast.Iterable(nullptr) == L"nullptr");
    }

    {
        REQUIRE(fast.VectorView({ L"One",L"Two",L"Three" }) == L"OneTwoThree");
        REQUIRE_THROWS_AS(fast.UseIterable(), hresult_illegal_method_call);

        REQUIRE(fast.VectorView(std::vector<hstring>{ L"One", L"Two", L"Three" }) == L"OneTwoThree");
        fast.UseIterable();

        std::vector<hstring> vector{ L"One",L"Two",L"Three" };
        REQUIRE(fast.VectorView(vector) == L"OneTwoThree");
        REQUIRE_THROWS_AS(fast.UseIterable(), hresult_illegal_method_call);

        FastInputVector convertible({ L"One",L"Two",L"Three" });
        REQUIRE(fast.VectorView(convertible) == L"OneTwoThree");
        fast.UseIterable();

        std::array<hstring, 3> range{ L"One",L"Two",L"Three" };
        REQUIRE(fast.VectorView({ range.begin(), range.end() }) == L"OneTwoThree");
        REQUIRE_THROWS_AS(fast.UseIterable(), hresult_illegal_method_call);

        IVectorView<hstring> actual = single_threaded_vector<hstring>({ L"One",L"Two",L"Three" }).GetView();
        REQUIRE(fast.VectorView(actual) == L"OneTwoThree");
        fast.UseIterable();

        REQUIRE(fast.VectorView(nullptr) == L"nullptr");
    }

    {
        REQUIRE(fast.Vector({ L"One",L"Two",L"Three" }) == L"OneTwoThree");
        fast.UseIterable();

        REQUIRE(fast.Vector(std::vector<hstring>{ L"One", L"Two", L"Three" }) == L"OneTwoThree");
        fast.UseIterable();

        FastInputVector convertible({ L"One",L"Two",L"Three" });
        REQUIRE(fast.Vector(convertible) == L"OneTwoThree");
        fast.UseIterable();

        IVector<hstring> actual = single_threaded_vector<hstring>({ L"One",L"Two",L"Three" });
        REQUIRE(fast.Vector(actual) == L"OneTwoThree");
        fast.UseIterable();

        REQUIRE(fast.Vector(nullptr) == L"nullptr");
    }

    {
        FastInputVector convertible({ L"One",L"Two",L"Three" });
        REQUIRE(fast.ObservableVector(convertible) == L"OneTwoThree");
        fast.UseIterable();

        IObservableVector<hstring> actual = FastInputVector({ L"One",L"Two",L"Three" });
        REQUIRE(fast.ObservableVector(actual) == L"OneTwoThree");
        fast.UseIterable();

        REQUIRE(fast.ObservableVector(nullptr) == L"nullptr");
    }

    {
        REQUIRE(fast.IterablePair({ { L"A",L"a" },{ L"B",L"b" },{ L"C",L"c" } }) == L"AaBbCc");
        REQUIRE_THROWS_AS(fast.UseIterablePair(), hresult_illegal_method_call);

        REQUIRE(fast.IterablePair(std::map<hstring, hstring>{ { L"A", L"a" }, { L"B",L"b" }, { L"C",L"c" } }) == L"AaBbCc");
        fast.UseIterablePair();

        REQUIRE(fast.IterablePair(std::unordered_map<hstring, hstring>{ { L"A", L"a" }, { L"B",L"b" }, { L"C",L"c" } }) == L"AaBbCc");
        fast.UseIterablePair();

        std::map<hstring, hstring> map{ { { L"A", L"a" }, { L"B",L"b" }, { L"C",L"c" } } };
        REQUIRE(fast.IterablePair(map) == L"AaBbCc");
        REQUIRE_THROWS_AS(fast.UseIterablePair(), hresult_illegal_method_call);

        IMap<hstring, hstring> convertible = single_threaded_map<hstring, hstring>(std::map<hstring, hstring>{ { { L"A", L"a" }, { L"B",L"b" }, { L"C",L"c" } } });
        REQUIRE(fast.IterablePair(convertible) == L"AaBbCc");
        fast.UseIterablePair();

        std::unordered_map<hstring, hstring> range{ { { L"A", L"a" }, { L"B",L"b" }, { L"C",L"c" } } };
        REQUIRE(fast.IterablePair({ range.begin(), range.end() }) == L"AaBbCc");
        REQUIRE_THROWS_AS(fast.UseIterablePair(), hresult_illegal_method_call);

        IIterable<IKeyValuePair<hstring, hstring>> actual = single_threaded_map<hstring>(std::map<hstring, hstring>{ { { L"A", L"a" }, { L"B",L"b" }, { L"C",L"c" } } });
        REQUIRE(fast.IterablePair(actual) == L"AaBbCc");
        fast.UseIterablePair();

        REQUIRE(fast.IterablePair(nullptr) == L"nullptr");
    }
}
