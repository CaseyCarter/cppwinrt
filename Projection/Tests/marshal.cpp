#include "pch.h"
#include "catch.hpp"

// These tests do not attempt to test the FTM itself, but merely to confirm that the presence and
// absence of the non_agile marker does indeed produce the correct reponses from QueryInterface.
// CoMarshalInterfaceXxxx is also used to exercise the code paths. Also, these tests confirm that
// the weak reference object inherits the same agility as the source. Although much of this is 
// tested elsewhere, it was helpful to have these tests as a set.

using namespace winrt;
using namespace Windows::Foundation;

namespace
{
    struct Agile : implements<Agile, IStringable>
    {
        hstring ToString()
        {
            return L"Agile";
        }
    };

    struct NonAgile : implements<NonAgile, IStringable, non_agile>
    {
        hstring ToString()
        {
            return L"NonAgile";
        }
    };
}

TEST_CASE("marshal agile")
{
    IStringable agile = make<Agile>();
    WINRT_ASSERT(agile.as<IAgileObject>());
    WINRT_ASSERT(agile.as<IMarshal>());

    com_ptr<IStream> stream;
    check_hresult(CoMarshalInterThreadInterfaceInStream(__uuidof(abi<IStringable>), get_abi(agile), put_abi(stream)));
    IStringable copy;
    check_hresult(CoUnmarshalInterface(get_abi(stream), __uuidof(abi<IStringable>), reinterpret_cast<void **>(put_abi(copy))));

    REQUIRE(copy.ToString() == L"Agile");
}

TEST_CASE("marshal non-agile")
{
    IStringable non = make<NonAgile>();
    WINRT_ASSERT(!non.try_as<IAgileObject>());
    WINRT_ASSERT(!non.try_as<IMarshal>());
}

TEST_CASE("marshal agile weak-ref")
{
    IStringable agile = make<Agile>();
    com_ptr<ABI::Windows::Foundation::IWeakReferenceSource> source = agile.as<ABI::Windows::Foundation::IWeakReferenceSource>();
    com_ptr<ABI::Windows::Foundation::IWeakReference> ref;
    check_hresult(source->abi_GetWeakReference(put_abi(ref)));

    WINRT_ASSERT(ref.as<IAgileObject>());
    WINRT_ASSERT(ref.as<IMarshal>());

    com_ptr<IStream> stream;
    check_hresult(CoMarshalInterThreadInterfaceInStream(__uuidof(ABI::Windows::Foundation::IWeakReference), get_abi(ref), put_abi(stream)));
    com_ptr<ABI::Windows::Foundation::IWeakReference> ref_copy;
    check_hresult(CoUnmarshalInterface(get_abi(stream), __uuidof(ABI::Windows::Foundation::IWeakReference), reinterpret_cast<void **>(put_abi(ref_copy))));

    IStringable copy;
    check_hresult(ref_copy->abi_Resolve(put_abi(copy)));

    REQUIRE(copy.ToString() == L"Agile");
}

TEST_CASE("marshal non-agile weak-ref")
{
    IStringable non = make<NonAgile>();
    com_ptr<ABI::Windows::Foundation::IWeakReferenceSource> source = non.as<ABI::Windows::Foundation::IWeakReferenceSource>();
    com_ptr<ABI::Windows::Foundation::IWeakReference> ref;
    check_hresult(source->abi_GetWeakReference(put_abi(ref)));

    WINRT_ASSERT(!ref.try_as<IAgileObject>());
    WINRT_ASSERT(!ref.try_as<IMarshal>());
}
