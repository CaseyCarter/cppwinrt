#include "pch.h"
#include "catch.hpp"

using namespace winrt;
using namespace Windows::Foundation;

namespace
{
    struct Weak : implements<Weak, IStringable>
    {
        hstring ToString()
        {
            return L"Weak";
        }
    };

    struct WeakNonAgile : implements<WeakNonAgile, IStringable, non_agile>
    {
        hstring ToString()
        {
            return L"WeakNonAgile";
        }
    };

    struct NoWeak : implements<NoWeak, ::IUnknown>
    {
    };

    struct Factory : implements<Factory, IActivationFactory>
    {
        Windows::IInspectable ActivateInstance()
        {
            return nullptr;
        }
    };

    struct NoWeakRef : implements<NoWeakRef, IStringable, no_weak_ref>
    {
        hstring ToString()
        {
            return L"NoWeakRef";
        }
    };
}

TEST_CASE("weak,source")
{
    SECTION("resolved")
    {
        IStringable a = make<Weak>();

        weak_ref<IStringable> w = a;
        IStringable b = w.get();
        REQUIRE(b.ToString() == L"Weak");

        // still one outstanding reference
        b = nullptr;
        b = w.get();
        REQUIRE(b != nullptr);

        // no outstanding references
        a = nullptr;
        b = nullptr;
        b = w.get();
        REQUIRE(b == nullptr);
    }

    SECTION("unresolved")
    {
        // default construct
        weak_ref<IStringable> w;

        w = make<Weak>(); // reference is lost right here
        IStringable b = w.get();
        REQUIRE(b == nullptr);
    }

    SECTION("make_weak")
    {
        IStringable a = make<Weak>();
        auto w = make_weak(a);
        IStringable b = w.get();
        REQUIRE(b.ToString() == L"Weak");
    }
}

TEST_CASE("weak,none")
{
    Windows::IUnknown s = make<NoWeak>().as<Windows::IUnknown>();

    REQUIRE_THROWS_AS(make_weak(s), hresult_no_interface);

    try
    {
        weak_ref<Windows::IUnknown> w = s;
        REQUIRE(false);
    }
    catch (hresult_no_interface const &) {}
}

TEST_CASE("weak,QI")
{
    SECTION("weak")
    {
        IStringable object = make<Weak>();
        REQUIRE(object.try_as<ABI::Windows::IInspectable>());
        REQUIRE(object.try_as<ABI::Windows::IWeakReferenceSource>());
        REQUIRE(!object.try_as<ABI::Windows::IWeakReference>());

        com_ptr<ABI::Windows::IWeakReferenceSource> source = object.as<ABI::Windows::IWeakReferenceSource>();
        REQUIRE(!source.try_as<ABI::Windows::IWeakReference>());
        REQUIRE(source.try_as<ABI::Windows::IWeakReferenceSource>());
        REQUIRE(object.as<::IUnknown>() == source.as<::IUnknown>());
        REQUIRE(object.as<ABI::Windows::IInspectable>() == source.as<ABI::Windows::IInspectable>());

        com_ptr<ABI::Windows::IWeakReference> ref;
        REQUIRE(S_OK == source->abi_GetWeakReference(put(ref)));
        REQUIRE(!ref.try_as<ABI::Windows::IWeakReferenceSource>());
        REQUIRE(!ref.try_as<ABI::Windows::IInspectable>());
        REQUIRE(ref.as<ABI::Windows::IWeakReference>() == ref);
        REQUIRE(ref.as<::IUnknown>() != object.as<::IUnknown>());
    }

    SECTION("no-weak")
    {
        com_ptr<::IUnknown> object = make<NoWeak>();
        REQUIRE(!object.try_as<ABI::Windows::IInspectable>());
        REQUIRE(!object.try_as<ABI::Windows::IWeakReferenceSource>());
        REQUIRE(!object.try_as<ABI::Windows::IWeakReference>());
    }

    SECTION("factory")
    {
        IActivationFactory object = make<Factory>();
        REQUIRE(object.try_as<ABI::Windows::IInspectable>());
        REQUIRE(!object.try_as<ABI::Windows::IWeakReferenceSource>());
    }

    SECTION("no_weak_ref")
    {
        IStringable object = make<NoWeakRef>();
        REQUIRE(object.try_as<ABI::Windows::IInspectable>());
        REQUIRE(!object.try_as<ABI::Windows::IWeakReferenceSource>());
    }
}

TEST_CASE("weak,lifetime")
{
    {
        IStringable object = make<Weak>();
    }
    {
        IStringable object = make<Weak>();
        object.as<ABI::Windows::IWeakReferenceSource>();
    }
    {
        IStringable object = make<Weak>();
        com_ptr<ABI::Windows::IWeakReferenceSource> source = object.as<ABI::Windows::IWeakReferenceSource>();
    }
    {
        IStringable object = make<Weak>();
        com_ptr<ABI::Windows::IWeakReferenceSource> source = object.as<ABI::Windows::IWeakReferenceSource>();
        com_ptr<ABI::Windows::IWeakReference> ref;
        check_hresult(source->abi_GetWeakReference(put(ref)));
    }
    {
        IStringable object = make<Weak>();
        com_ptr<ABI::Windows::IWeakReferenceSource> source = object.as<ABI::Windows::IWeakReferenceSource>();
        com_ptr<ABI::Windows::IWeakReference> ref;
        check_hresult(source->abi_GetWeakReference(put(ref)));
        IStringable object2;
        check_hresult(ref->abi_Resolve(put(object2)));
        REQUIRE(object == object2);
    }
    {
        IStringable object = make<Weak>();
        com_ptr<ABI::Windows::IWeakReference> ref;
        check_hresult(object.as<ABI::Windows::IWeakReferenceSource>()->abi_GetWeakReference(put(ref)));
        IStringable object2;
        check_hresult(ref->abi_Resolve(put(object2)));
        REQUIRE(object == object2);
    }
    {
        IStringable object = make<Weak>();
        com_ptr<ABI::Windows::IWeakReferenceSource> source = object.as<ABI::Windows::IWeakReferenceSource>();
        object = nullptr;
        com_ptr<ABI::Windows::IWeakReference> ref;
        check_hresult(source->abi_GetWeakReference(put(ref)));
        check_hresult(ref->abi_Resolve(put(object)));
        REQUIRE(object.ToString() == L"Weak");
    }
    {
        IStringable object = make<Weak>();
        com_ptr<ABI::Windows::IWeakReferenceSource> source = object.as<ABI::Windows::IWeakReferenceSource>();
        com_ptr<ABI::Windows::IWeakReference> ref;
        check_hresult(source->abi_GetWeakReference(put(ref)));
        source = nullptr;
        IStringable object2;
        check_hresult(ref->abi_Resolve(put(object2)));
        REQUIRE(object.ToString() == L"Weak");
    }
    {
        IStringable object = make<Weak>();
        com_ptr<ABI::Windows::IWeakReferenceSource> source = object.as<ABI::Windows::IWeakReferenceSource>();
        object = nullptr;
        com_ptr<ABI::Windows::IWeakReference> ref;
        check_hresult(source->abi_GetWeakReference(put(ref)));
        source = nullptr;
        check_hresult(ref->abi_Resolve(put(object)));
        REQUIRE(object == nullptr);
    }

    {
        IStringable object = make<Weak>();
        weak_ref<IStringable> ref = object;
        REQUIRE(ref.get() == object);
    }
    {
        IStringable object = make<Weak>();
        weak_ref<IStringable> ref = object;
        object = nullptr;
        REQUIRE(ref.get() == nullptr);
    }
    {
        weak_ref<IStringable> ref = make<Weak>();
        REQUIRE(ref.get() == nullptr);
    }
    {
        IStringable object = make<Weak>();
        auto ref = make_weak(object);
        REQUIRE(ref.get() == object);
    }
    {
        IStringable object = make<Weak>();
        auto ref = make_weak(object);
        object = nullptr;
        REQUIRE(ref.get() == nullptr);
    }

    {
        IStringable object = make<Weak>();
        com_ptr<ABI::Windows::IWeakReferenceSource> source = object.as<ABI::Windows::IWeakReferenceSource>();
        com_ptr<ABI::Windows::IWeakReference> ref;
        check_hresult(source->abi_GetWeakReference(put(ref)));

        REQUIRE(object.try_as<IAgileObject>());
        REQUIRE(ref.try_as<IAgileObject>());
        REQUIRE(object.as<IAgileObject>() == source.as<IAgileObject>());
        REQUIRE(object.as<IAgileObject>() != ref.as<IAgileObject>());
    }

    {
        IStringable object = make<WeakNonAgile>();
        com_ptr<ABI::Windows::IWeakReferenceSource> source = object.as<ABI::Windows::IWeakReferenceSource>();
        com_ptr<ABI::Windows::IWeakReference> ref;
        check_hresult(source->abi_GetWeakReference(put(ref)));

        REQUIRE(!object.try_as<IAgileObject>());
        REQUIRE(!ref.try_as<IAgileObject>());
    }
}