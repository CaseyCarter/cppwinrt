#include "pch.h"
#include "catch.hpp"

//
// These tests cover the production of the three core interfaces namely IUnknown, IInspectable, and IActivationFactory.
// Tests ensure that the ABI surface lines up on the consumer and producer sides and this is mainly done simply by calling
// the various inteface methods.
//

using namespace winrt;
using namespace Windows::Foundation;

//
// IUnknown - tests the most basic support of producing implementations.
//

struct produce_IUnknown : implements<produce_IUnknown, Windows::IUnknown>
{
    bool & m_destroyed;
    produce_IUnknown(bool & destroyed) : m_destroyed(destroyed) { m_destroyed = false; }
    ~produce_IUnknown() { m_destroyed = true; }
};

TEST_CASE("produce_IUnknown")
{
    bool destroyed = false;
    Windows::IUnknown p = make<produce_IUnknown>(destroyed);

    {
        // Basic query works for IUnknown.

        com_ptr<Windows::IUnknown> qi;
        REQUIRE(S_OK == p->QueryInterface(put(qi)));
        REQUIRE(qi);
    }
    {
        // Query for unsupported interface is rejected.

        com_ptr<Windows::IInspectable> qi;
        REQUIRE(E_NOINTERFACE == p->QueryInterface(put(qi)));
        REQUIRE(!qi);
    }
    {
        // C++/WinRT won't let you call AddRef and Release so we confirm they work
        // by retrieving a raw pointer to IUnknown here.

        ::IUnknown * raw = get(p);
        raw->AddRef();
        raw->Release();
    }

    REQUIRE(!destroyed);
    p = nullptr;
    REQUIRE(destroyed);
}

// Unprojected (ABI) interfaces can be implemented.

struct produce_IUnknown_ABI : implements<produce_IUnknown_ABI, ::IUnknown>
{
    bool & m_destroyed;
    produce_IUnknown_ABI(bool & destroyed) : m_destroyed(destroyed) { m_destroyed = false; }
    ~produce_IUnknown_ABI() { m_destroyed = true; }
};

TEST_CASE("produce_IUnknown_ABI")
{
    bool destroyed = false;
    com_ptr<::IUnknown> p = make<produce_IUnknown_ABI>(destroyed);

    REQUIRE(!destroyed);
    p = nullptr;
    REQUIRE(destroyed);
}

//
// IInspectable - tests support for producing implementations with just IInspectable.
//

struct produce_IInspectable : implements<produce_IInspectable, Windows::IInspectable>
{
    bool & m_destroyed;
    produce_IInspectable(bool & destroyed) : m_destroyed(destroyed) { m_destroyed = false; }
    ~produce_IInspectable() { m_destroyed = true; }
};

TEST_CASE("produce_IInspectable")
{
    bool destroyed = false;
    Windows::IInspectable p = make<produce_IInspectable>(destroyed);

    {
        // Basic query works for IUnknown.

        com_ptr<Windows::IUnknown> qi;
        REQUIRE(S_OK == p->QueryInterface(put(qi)));
        REQUIRE(qi);
    }
    {
        // Query works for IInspectable.

        com_ptr<Windows::IInspectable> qi;
        REQUIRE(S_OK == p->QueryInterface(put(qi)));
        REQUIRE(qi);
    }
    {
        // Query for unsupported interface is rejected.

        com_ptr<IActivationFactory> qi;
        REQUIRE(E_NOINTERFACE == p->QueryInterface(put(qi)));
        REQUIRE(!qi);
    }

    REQUIRE(!destroyed);
    p = nullptr;
    REQUIRE(destroyed);
}

// Unprojected (ABI) interfaces can be implemented.

struct produce_IInspectable_ABI : implements<produce_IInspectable_ABI, ABI::Windows::IInspectable>
{
    bool & m_destroyed;
    produce_IInspectable_ABI(bool & destroyed) : m_destroyed(destroyed) { m_destroyed = false; }
    ~produce_IInspectable_ABI() { m_destroyed = true; }
};

TEST_CASE("produce_IInspectable_ABI")
{
    bool destroyed = false;
    com_ptr<ABI::Windows::IInspectable> p = make<produce_IInspectable_ABI>(destroyed);
    REQUIRE(!destroyed);
    p = nullptr;
    REQUIRE(destroyed);
}

// RuntimeClassName may optionally be implemented with the projection.

struct produce_IInspectable_No_RuntimeClassName : implements<produce_IInspectable_No_RuntimeClassName, Windows::IInspectable>
{
};

struct produce_IInspectable_RuntimeClassName : implements<produce_IInspectable_RuntimeClassName, Windows::IInspectable>
{
    hstring GetRuntimeClassName()
    {
        return L"produce_IInspectable_RuntimeClassName";
    }
};

TEST_CASE("produce_IInspectable_RuntimeClassName")
{
    Windows::IInspectable without = make<produce_IInspectable_No_RuntimeClassName>();
    REQUIRE_THROWS_AS(GetRuntimeClassName(without), hresult_not_implemented);

    Windows::IInspectable with = make<produce_IInspectable_RuntimeClassName>();
    REQUIRE(GetRuntimeClassName(with) == L"produce_IInspectable_RuntimeClassName");
}

//
// IActivationFactory
//

struct produce_IActivationFactory_Instance : implements<produce_IActivationFactory_Instance, IStringable>
{
    hstring ToString()
    {
        return L"produce_IActivationFactory_Instance";
    }
};

struct produce_IActivationFactory : implements<produce_IActivationFactory, IActivationFactory>
{
    bool & m_destroyed;
    produce_IActivationFactory(bool & destroyed) : m_destroyed(destroyed) { m_destroyed = false; }
    ~produce_IActivationFactory() { m_destroyed = true; }

    Windows::IInspectable ActivateInstance()
    {
        return make<produce_IActivationFactory_Instance>();
    }
};

TEST_CASE("produce_IActivationFactory")
{
    bool destroyed = false;
    IActivationFactory p = make<produce_IActivationFactory>(destroyed);

    IStringable i = p.ActivateInstance().as<IStringable>();
    REQUIRE(i.ToString() == L"produce_IActivationFactory_Instance");

    REQUIRE(!destroyed);
    p = nullptr;
    REQUIRE(destroyed);
}

// Unprojected (ABI) interfaces can be implemented.

struct produce_IActivationFactory_ABI : implements<produce_IActivationFactory_ABI, ABI::Windows::Foundation::IActivationFactory>
{
    bool & m_destroyed;
    produce_IActivationFactory_ABI(bool & destroyed) : m_destroyed(destroyed) { m_destroyed = false; }
    ~produce_IActivationFactory_ABI() { m_destroyed = true; }

    HRESULT __stdcall abi_ActivateInstance(ABI::Windows::IInspectable ** instance)
    {
        *instance = nullptr;
        return E_NOTIMPL;
    }
};

TEST_CASE("produce_IActivationFactory_ABI")
{
    bool destroyed = false;
    com_ptr<ABI::Windows::Foundation::IActivationFactory> p = make<produce_IActivationFactory_ABI>(destroyed);

    com_ptr<Windows::IInspectable> i;
    REQUIRE(E_NOTIMPL == p->abi_ActivateInstance(put(i)));

    REQUIRE(!destroyed);
    p = nullptr;
    REQUIRE(destroyed);
}