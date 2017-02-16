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
        IInspectable ActivateInstance()
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
    Windows::Foundation::IUnknown s = make<NoWeak>().as<Windows::Foundation::IUnknown>();

    REQUIRE_THROWS_AS(make_weak(s), hresult_no_interface);

    try
    {
        weak_ref<Windows::Foundation::IUnknown> w = s;
        REQUIRE(false);
    }
    catch (hresult_no_interface const &) {}
}

TEST_CASE("weak,QI")
{
    SECTION("weak")
    {
        IStringable object = make<Weak>();
        REQUIRE(object.try_as<ABI::Windows::Foundation::IInspectable>());
        REQUIRE(object.try_as<ABI::Windows::Foundation::IWeakReferenceSource>());
        REQUIRE(!object.try_as<ABI::Windows::Foundation::IWeakReference>());

        com_ptr<ABI::Windows::Foundation::IWeakReferenceSource> source = object.as<ABI::Windows::Foundation::IWeakReferenceSource>();
        REQUIRE(!source.try_as<ABI::Windows::Foundation::IWeakReference>());
        REQUIRE(source.try_as<ABI::Windows::Foundation::IWeakReferenceSource>());
        REQUIRE(object.as<::IUnknown>() == source.as<::IUnknown>());
        REQUIRE(object.as<ABI::Windows::Foundation::IInspectable>() == source.as<ABI::Windows::Foundation::IInspectable>());

        com_ptr<ABI::Windows::Foundation::IWeakReference> ref;
        REQUIRE(S_OK == source->abi_GetWeakReference(put_abi(ref)));
        REQUIRE(!ref.try_as<ABI::Windows::Foundation::IWeakReferenceSource>());
        REQUIRE(!ref.try_as<ABI::Windows::Foundation::IInspectable>());
        REQUIRE(ref.as<ABI::Windows::Foundation::IWeakReference>() == ref);
        REQUIRE(ref.as<::IUnknown>() != object.as<::IUnknown>());
    }

    SECTION("no-weak")
    {
        com_ptr<::IUnknown> object = make<NoWeak>();
        REQUIRE(!object.try_as<ABI::Windows::Foundation::IInspectable>());
        REQUIRE(!object.try_as<ABI::Windows::Foundation::IWeakReferenceSource>());
        REQUIRE(!object.try_as<ABI::Windows::Foundation::IWeakReference>());
    }

    SECTION("factory")
    {
        IActivationFactory object = make<Factory>();
        REQUIRE(object.try_as<ABI::Windows::Foundation::IInspectable>());
        REQUIRE(!object.try_as<ABI::Windows::Foundation::IWeakReferenceSource>());
    }

    SECTION("no_weak_ref")
    {
        IStringable object = make<NoWeakRef>();
        REQUIRE(object.try_as<ABI::Windows::Foundation::IInspectable>());
        REQUIRE(!object.try_as<ABI::Windows::Foundation::IWeakReferenceSource>());
    }
}

TEST_CASE("weak,lifetime")
{
    {
        IStringable object = make<Weak>();
    }
    {
        IStringable object = make<Weak>();
        object.as<ABI::Windows::Foundation::IWeakReferenceSource>();
    }
    {
        IStringable object = make<Weak>();
        com_ptr<ABI::Windows::Foundation::IWeakReferenceSource> source = object.as<ABI::Windows::Foundation::IWeakReferenceSource>();
    }
    {
        IStringable object = make<Weak>();
        com_ptr<ABI::Windows::Foundation::IWeakReferenceSource> source = object.as<ABI::Windows::Foundation::IWeakReferenceSource>();
        com_ptr<ABI::Windows::Foundation::IWeakReference> ref;
        check_hresult(source->abi_GetWeakReference(put_abi(ref)));
    }
    {
        IStringable object = make<Weak>();
        com_ptr<ABI::Windows::Foundation::IWeakReferenceSource> source = object.as<ABI::Windows::Foundation::IWeakReferenceSource>();
        com_ptr<ABI::Windows::Foundation::IWeakReference> ref;
        check_hresult(source->abi_GetWeakReference(put_abi(ref)));
        IStringable object2;
        check_hresult(ref->abi_Resolve(put_abi(object2)));
        REQUIRE(object == object2);
    }
    {
        IStringable object = make<Weak>();
        com_ptr<ABI::Windows::Foundation::IWeakReference> ref;
        check_hresult(object.as<ABI::Windows::Foundation::IWeakReferenceSource>()->abi_GetWeakReference(put_abi(ref)));
        IStringable object2;
        check_hresult(ref->abi_Resolve(put_abi(object2)));
        REQUIRE(object == object2);
    }
    {
        IStringable object = make<Weak>();
        com_ptr<ABI::Windows::Foundation::IWeakReferenceSource> source = object.as<ABI::Windows::Foundation::IWeakReferenceSource>();
        object = nullptr;
        com_ptr<ABI::Windows::Foundation::IWeakReference> ref;
        check_hresult(source->abi_GetWeakReference(put_abi(ref)));
        check_hresult(ref->abi_Resolve(put_abi(object)));
        REQUIRE(object.ToString() == L"Weak");
    }
    {
        IStringable object = make<Weak>();
        com_ptr<ABI::Windows::Foundation::IWeakReferenceSource> source = object.as<ABI::Windows::Foundation::IWeakReferenceSource>();
        com_ptr<ABI::Windows::Foundation::IWeakReference> ref;
        check_hresult(source->abi_GetWeakReference(put_abi(ref)));
        source = nullptr;
        IStringable object2;
        check_hresult(ref->abi_Resolve(put_abi(object2)));
        REQUIRE(object.ToString() == L"Weak");
    }
    {
        IStringable object = make<Weak>();
        com_ptr<ABI::Windows::Foundation::IWeakReferenceSource> source = object.as<ABI::Windows::Foundation::IWeakReferenceSource>();
        object = nullptr;
        com_ptr<ABI::Windows::Foundation::IWeakReference> ref;
        check_hresult(source->abi_GetWeakReference(put_abi(ref)));
        source = nullptr;
        check_hresult(ref->abi_Resolve(put_abi(object)));
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
        com_ptr<ABI::Windows::Foundation::IWeakReferenceSource> source = object.as<ABI::Windows::Foundation::IWeakReferenceSource>();
        com_ptr<ABI::Windows::Foundation::IWeakReference> ref;
        check_hresult(source->abi_GetWeakReference(put_abi(ref)));

        REQUIRE(object.try_as<IAgileObject>());
        REQUIRE(ref.try_as<IAgileObject>());
        REQUIRE(object.as<IAgileObject>() == source.as<IAgileObject>());
        REQUIRE(object.as<IAgileObject>() != ref.as<IAgileObject>());
    }

    {
        IStringable object = make<WeakNonAgile>();
        com_ptr<ABI::Windows::Foundation::IWeakReferenceSource> source = object.as<ABI::Windows::Foundation::IWeakReferenceSource>();
        com_ptr<ABI::Windows::Foundation::IWeakReference> ref;
        check_hresult(source->abi_GetWeakReference(put_abi(ref)));

        REQUIRE(!object.try_as<IAgileObject>());
        REQUIRE(!ref.try_as<IAgileObject>());
    }
}