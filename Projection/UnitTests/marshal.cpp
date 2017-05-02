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
    check_hresult(CoMarshalInterThreadInterfaceInStream(impl::guid_v<IStringable>, get_abi(agile), put_abi(stream)));
    IStringable copy;
    check_hresult(CoUnmarshalInterface(get_abi(stream), impl::guid_v<IStringable>, reinterpret_cast<void **>(put_abi(copy))));

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
    com_ptr<abi_t<impl::IWeakReferenceSource>> source = agile.as<abi_t<impl::IWeakReferenceSource>>();
    com_ptr<abi_t<impl::IWeakReference>> ref;
    check_hresult(source->GetWeakReference(put_abi(ref)));

    WINRT_ASSERT(ref.as<IAgileObject>());
    WINRT_ASSERT(ref.as<IMarshal>());

    com_ptr<IStream> stream;
    check_hresult(CoMarshalInterThreadInterfaceInStream(impl::guid_v<impl::IWeakReference>, get_abi(ref), put_abi(stream)));
    com_ptr<abi_t<impl::IWeakReference>> ref_copy;
    check_hresult(CoUnmarshalInterface(get_abi(stream), impl::guid_v<impl::IWeakReference>, reinterpret_cast<void **>(put_abi(ref_copy))));

    IStringable copy;
    check_hresult(ref_copy->Resolve(put_abi(copy)));

    REQUIRE(copy.ToString() == L"Agile");
}

TEST_CASE("marshal non-agile weak-ref")
{
    IStringable non = make<NonAgile>();
    com_ptr<abi_t<impl::IWeakReferenceSource>> source = non.as<abi_t<impl::IWeakReferenceSource>>();
    com_ptr<abi_t<impl::IWeakReference>> ref;
    check_hresult(source->GetWeakReference(put_abi(ref)));

    WINRT_ASSERT(!ref.try_as<IAgileObject>());
    WINRT_ASSERT(!ref.try_as<IMarshal>());
}
