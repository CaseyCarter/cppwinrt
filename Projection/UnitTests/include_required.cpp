// Do NOT use pch.h for this test. We need to verify that Windows.Foundation.Collections.h is included in isolation.

#include <winrt\Windows.Graphics.Imaging.h>
#include <winrt\Windows.Web.Syndication.h>
#include <winrt\Windows.Web.AtomPub.h>
#include "catch.hpp"

using namespace winrt;

//
// Show that a class that implements an interface in another namespace can call methods on the implemented class
// without explicitly bringing in its <namespace>.h header.
//

TEST_CASE("include, generic")
{
    hstring prop{ L"fakeproperty" };
    Windows::Graphics::Imaging::BitmapPropertySet properties;
    Windows::Graphics::Imaging::BitmapTypedValue val(properties.as<winrt::Windows::Foundation::IInspectable>(), winrt::Windows::Foundation::PropertyType::Inspectable);
    
    // Call a member of an interface in another namespace not explicitly included. In this case, Windows::Foundation::Collection::IMap.
    properties.Insert(prop, val);
    
    // If we didn't throw, we're good. This test is about compilation.
    REQUIRE(true);
}

TEST_CASE("include, runtimeclass")
{
    Windows::Web::AtomPub::AtomPubClient atom;

    // Call a member of an interface in another namespace not explicitly included. In this case, Windows::Web::Syndication::ISyndicationClient.
    atom.MaxResponseBufferSize(100);

    // If we didn't throw, we're good. This test is about compilation.
    REQUIRE(true);
}

// Declare a class that implements an interface pulled in due to dependencies.
// In this case, ISyndicationClient should be defined because classes in Windows::Web::AtomPub require it.
struct CustomSyndicationClient : implements<CustomSyndicationClient, Windows::Web::Syndication::ISyndicationClient>
{
public:
    Windows::Security::Credentials::PasswordCredential ServerCredential() { throw winrt::hresult_not_implemented(); };
    void ServerCredential(const Windows::Security::Credentials::PasswordCredential &) { throw winrt::hresult_not_implemented(); };
    Windows::Security::Credentials::PasswordCredential ProxyCredential() { throw winrt::hresult_not_implemented(); };
    void ProxyCredential(const Windows::Security::Credentials::PasswordCredential &) { throw winrt::hresult_not_implemented(); };
    uint32_t MaxResponseBufferSize() { throw winrt::hresult_not_implemented(); };
    void MaxResponseBufferSize(uint32_t) { throw winrt::hresult_not_implemented(); };
    uint32_t Timeout() { throw winrt::hresult_not_implemented(); };
    void Timeout(uint32_t) { throw winrt::hresult_not_implemented(); };
    bool BypassCacheOnRetrieve() { throw winrt::hresult_not_implemented(); };
    void BypassCacheOnRetrieve(bool) { throw winrt::hresult_not_implemented(); };
    void SetRequestHeader(hstring const&, hstring const&) { throw winrt::hresult_not_implemented(); };
    Windows::Foundation::IAsyncOperationWithProgress<Windows::Web::Syndication::SyndicationFeed, Windows::Web::Syndication::RetrievalProgress> RetrieveFeedAsync(const Windows::Foundation::Uri &) { throw winrt::hresult_not_implemented(); };
};

TEST_CASE("include, implement")
{
    bool exceptionCaught = false;
    CustomSyndicationClient client;
    Windows::Web::Syndication::ISyndicationClient castToClientInterface = static_cast<Windows::Web::Syndication::ISyndicationClient>(client);

    try
    {
        castToClientInterface.BypassCacheOnRetrieve();
    }
    catch (hresult_not_implemented const&)
    {
        exceptionCaught = true;
    }

    REQUIRE(exceptionCaught);
}
