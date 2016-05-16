#include "pch.h"
#include "catch.hpp"

using namespace winrt;
using namespace Windows::Foundation;

static uint32_t s_refs = 0;

struct count_implements
{
    count_implements()
    {
        ++s_refs;
    }

    ~count_implements()
    {
        --s_refs;
    }
};

//
// IUnknown
//

struct impl_abi_unknown : implements<impl_abi_unknown, IUnknown>, count_implements
{};

TEST_CASE("implements, abi_unknown")
{
    REQUIRE(s_refs == 0);

    {
        com_ptr<IUnknown> unknown = make<impl_abi_unknown>();
        REQUIRE(s_refs == 1);

        unknown.as<IUnknown>(); // query self succeeds

        REQUIRE_THROWS_AS(unknown.as<ABI::Windows::IInspectable>(), hresult_no_interface);
    }

    REQUIRE(s_refs == 0);
}

struct impl_unknown : implements<impl_unknown, Windows::IUnknown>, count_implements
{};

TEST_CASE("implements, unknown")
{
    REQUIRE(s_refs == 0);

    {
        Windows::IUnknown unknown = make<impl_unknown>();
        REQUIRE(s_refs == 1);

        unknown.as<IUnknown>(); // query self succeeds
        REQUIRE_THROWS_AS(unknown.as<ABI::Windows::IInspectable>(), hresult_no_interface);
    }

    REQUIRE(s_refs == 0);
}

//
// IInspectable
//

struct impl_abi_inspectable : implements<impl_abi_inspectable, ABI::Windows::IInspectable>, count_implements
{};

TEST_CASE("implements, abi_inspectable")
{
    REQUIRE(s_refs == 0);

    {
        com_ptr<IUnknown> unknown = make<impl_abi_inspectable>();
        REQUIRE(s_refs == 1);

        unknown.as<IUnknown>();
        unknown.as<ABI::Windows::IInspectable>();
        REQUIRE_THROWS_AS(unknown.as<IUriRuntimeClass>(), hresult_no_interface);
    }

    REQUIRE(s_refs == 0);
}

struct impl_inspectable : implements<impl_inspectable, Windows::IInspectable>, count_implements
{};

TEST_CASE("implements, inspectable")
{
    REQUIRE(s_refs == 0);

    {
        Windows::IUnknown unknown = make<impl_inspectable>();
        REQUIRE(s_refs == 1);

        unknown.as<IUnknown>();
        unknown.as<ABI::Windows::IInspectable>();
        REQUIRE_THROWS_AS(unknown.as<IUriRuntimeClass>(), hresult_no_interface);
    }

    REQUIRE(s_refs == 0);
}

//
// GetRuntimeClassName
//

struct impl_GetRuntimeClassName : implements<impl_GetRuntimeClassName, Windows::IInspectable>
{
    hstring RuntimeClassName()
    {
        return L"impl_GetRuntimeClassName";
    }
};

TEST_CASE("implements, GetRuntimeClassName")
{
    Windows::IInspectable inspectable = make<impl_GetRuntimeClassName>();

    hstring name = inspectable.RuntimeClassName();

    REQUIRE(name == L"impl_GetRuntimeClassName");
}

struct impl_NoRuntimeClassName : implements<impl_NoRuntimeClassName, Windows::IInspectable>
{
};

TEST_CASE("implements, NoRuntimeClassName")
{
    Windows::IInspectable inspectable = make<impl_NoRuntimeClassName>();

    REQUIRE_THROWS_AS(inspectable.RuntimeClassName(), hresult_not_implemented);
}

//
// GetIids
//

struct impl_GetIids_none : implements<impl_GetIids_none, cloaked<Windows::IInspectable>>
{};

TEST_CASE("implements, impl_GetIids_none")
{
    Windows::IInspectable inspectable = make<impl_GetIids_none>();
    inspectable.as<IUnknown>();
    inspectable.as<ABI::Windows::IInspectable>();
    REQUIRE_THROWS_AS(inspectable.as<IUriRuntimeClass>(), hresult_no_interface);

    com_array<GUID> iids = inspectable.Iids();

    REQUIRE(iids.empty());
}

struct impl_GetIids_IInspectable : implements<impl_GetIids_IInspectable, Windows::IInspectable>
{};

TEST_CASE("implements, impl_GetIids_IInspectable")
{
    Windows::IInspectable inspectable = make<impl_GetIids_IInspectable>();
    inspectable.as<IUnknown>();
    inspectable.as<ABI::Windows::IInspectable>();
    REQUIRE_THROWS_AS(inspectable.as<IUriRuntimeClass>(), hresult_no_interface);

    com_array<GUID> iids = inspectable.Iids();

    REQUIRE(iids.size() == 1);
    REQUIRE(iids[0] == __uuidof(ABI::Windows::IInspectable));
}

struct impl_GetIids_IUriRuntimeClass : implements<impl_GetIids_IUriRuntimeClass, IUriRuntimeClass>
{};

TEST_CASE("implements, impl_GetIids_IUriRuntimeClass")
{
    IUriRuntimeClass uri = make<impl_GetIids_IUriRuntimeClass>();
    uri.as<IUnknown>();
    uri.as<ABI::Windows::IInspectable>();
    uri.as<IUriRuntimeClass>();
    REQUIRE_THROWS_AS(uri.as<IStringable>(), hresult_no_interface);

    com_array<GUID> iids = uri.Iids();

    REQUIRE(iids.size() == 1);
    REQUIRE(iids[0] == __uuidof(abi<IUriRuntimeClass>));
}

struct impl_GetIids_Uri : implements<impl_GetIids_Uri,
                                     IUriRuntimeClass,
                                     IUriRuntimeClassWithAbsoluteCanonicalUri,
                                     IStringable>
{};

TEST_CASE("implements, impl_GetIids_Uri")
{
    IUriRuntimeClass uri = make<impl_GetIids_Uri>();
    uri.as<IUnknown>();
    uri.as<ABI::Windows::IInspectable>();
    uri.as<IUriRuntimeClass>();
    uri.as<IUriRuntimeClassWithAbsoluteCanonicalUri>();
    uri.as<IStringable>();
    REQUIRE_THROWS_AS(uri.as<IClosable>(), hresult_no_interface);

    com_array<GUID> iids = uri.Iids();

    REQUIRE(iids.size() == 3);
    REQUIRE(iids[0] == __uuidof(abi<IUriRuntimeClass>));
    REQUIRE(iids[1] == __uuidof(abi<IUriRuntimeClassWithAbsoluteCanonicalUri>));
    REQUIRE(iids[2] == __uuidof(abi<IStringable>));
}

struct impl_GetIids_Uri_first_cloaked1 : implements<impl_GetIids_Uri_first_cloaked1,
                                                   cloaked<IUriRuntimeClass>,
                                                   IUriRuntimeClassWithAbsoluteCanonicalUri,
                                                   IStringable>
{};

TEST_CASE("implements, impl_GetIids_Uri_first_cloaked1")
{
    IUriRuntimeClass uri = make<impl_GetIids_Uri_first_cloaked1>();
    uri.as<IUnknown>();
    uri.as<ABI::Windows::IInspectable>();
    uri.as<IUriRuntimeClass>();
    uri.as<IUriRuntimeClassWithAbsoluteCanonicalUri>();
    uri.as<IStringable>();
    REQUIRE_THROWS_AS(uri.as<IClosable>(), hresult_no_interface);

    com_array<GUID> iids = uri.Iids();

    REQUIRE(iids.size() == 2);
    REQUIRE(iids[0] == __uuidof(abi<IUriRuntimeClassWithAbsoluteCanonicalUri>));
    REQUIRE(iids[1] == __uuidof(abi<IStringable>));
}

struct impl_GetIids_Uri_first_cloaked2 : implements<impl_GetIids_Uri_first_cloaked2,
                                                    IUriRuntimeClass,
                                                    cloaked<IUriRuntimeClassWithAbsoluteCanonicalUri>,
                                                    IStringable>
{};

TEST_CASE("implements, impl_GetIids_Uri_first_cloaked2")
{
    IUriRuntimeClass uri = make<impl_GetIids_Uri_first_cloaked2>();
    uri.as<IUnknown>();
    uri.as<ABI::Windows::IInspectable>();
    uri.as<IUriRuntimeClass>();
    uri.as<IUriRuntimeClassWithAbsoluteCanonicalUri>();
    uri.as<IStringable>();
    REQUIRE_THROWS_AS(uri.as<IClosable>(), hresult_no_interface);

    com_array<GUID> iids = uri.Iids();

    REQUIRE(iids.size() == 2);
    REQUIRE(iids[0] == __uuidof(abi<IUriRuntimeClass>));
    REQUIRE(iids[1] == __uuidof(abi<IStringable>));
}

struct impl_GetIids_Uri_first_cloaked3 : implements<impl_GetIids_Uri_first_cloaked3,
                                                    IUriRuntimeClass,
                                                    IUriRuntimeClassWithAbsoluteCanonicalUri,
                                                    cloaked<IStringable>>
{};

//
// Even though this test only produces two uncloaked interfaces (just like the one above), implements could in theory be implemented 
// in a way that the test above would work but this one would not.
//
TEST_CASE("implements, impl_GetIids_Uri_first_cloaked3")
{
    IUriRuntimeClass uri = make<impl_GetIids_Uri_first_cloaked3>();
    uri.as<IUnknown>();
    uri.as<ABI::Windows::IInspectable>();
    uri.as<IUriRuntimeClass>();
    uri.as<IUriRuntimeClassWithAbsoluteCanonicalUri>();
    uri.as<IStringable>();
    REQUIRE_THROWS_AS(uri.as<IClosable>(), hresult_no_interface);

    com_array<GUID> iids = uri.Iids();

    REQUIRE(iids.size() == 2);
    REQUIRE(iids[0] == __uuidof(abi<IUriRuntimeClass>));
    REQUIRE(iids[1] == __uuidof(abi<IUriRuntimeClassWithAbsoluteCanonicalUri>));
}

using namespace Windows::ApplicationModel::Store;

struct impl_GetIids_Uri_first_cloaked4 : implements<impl_GetIids_Uri_first_cloaked4,
                                                    abi<LicenseChangedEventHandler>,
                                                    IUriRuntimeClass,
                                                    IUriRuntimeClassWithAbsoluteCanonicalUri,
                                                    cloaked<IStringable>>, count_implements
{
    HRESULT __stdcall abi_Invoke() override
    {
        return S_OK;
    }
};

TEST_CASE("implements, impl_GetIids_Uri_first_cloaked4")
{
    REQUIRE(s_refs == 0);

    {
        com_ptr<IUnknown> uri = make<impl_GetIids_Uri_first_cloaked4>();

        REQUIRE(s_refs == 1);

        com_ptr<IUnknown> a = uri.as<IUnknown>();
        com_ptr<ABI::Windows::IInspectable> b = uri.as<ABI::Windows::IInspectable>();
        LicenseChangedEventHandler c = uri.as<LicenseChangedEventHandler>();
        com_ptr<LicenseChangedEventHandler> d = uri.as<abi<LicenseChangedEventHandler>>();
        IUriRuntimeClass e = uri.as<IUriRuntimeClass>();
        IUriRuntimeClassWithAbsoluteCanonicalUri f = uri.as<IUriRuntimeClassWithAbsoluteCanonicalUri>();
        IStringable g = uri.as<IStringable>();
        REQUIRE_THROWS_AS(uri.as<IClosable>(), hresult_no_interface);

        com_array<GUID> iids = uri.as<Windows::IInspectable>().Iids();

        REQUIRE(iids.size() == 2);
        REQUIRE(iids[0] == __uuidof(abi<IUriRuntimeClass>));
        REQUIRE(iids[1] == __uuidof(abi<IUriRuntimeClassWithAbsoluteCanonicalUri>));
    }

    REQUIRE(s_refs == 0);
}
