#include "pch.h"
#include "Windows.Foundation.Uri.h"

namespace winrt::Windows::Foundation::implementation
{
    Uri::Uri(hstring const& uri)
    {
        throw hresult_not_implemented();
    }

    Uri::Uri(hstring const& baseUri, hstring const& relativeUri)
    {
        throw hresult_not_implemented();
    }

    hstring Uri::AbsoluteUri()
    {
        throw hresult_not_implemented();
    }

    hstring Uri::DisplayUri()
    {
        throw hresult_not_implemented();
    }

    hstring Uri::Domain()
    {
        throw hresult_not_implemented();
    }

    hstring Uri::Extension()
    {
        throw hresult_not_implemented();
    }

    hstring Uri::Fragment()
    {
        throw hresult_not_implemented();
    }

    hstring Uri::Host()
    {
        throw hresult_not_implemented();
    }

    hstring Uri::Password()
    {
        throw hresult_not_implemented();
    }

    hstring Uri::Path()
    {
        throw hresult_not_implemented();
    }

    hstring Uri::Query()
    {
        throw hresult_not_implemented();
    }

    Windows::Foundation::WwwFormUrlDecoder Uri::QueryParsed()
    {
        throw hresult_not_implemented();
    }

    hstring Uri::RawUri()
    {
        throw hresult_not_implemented();
    }

    hstring Uri::SchemeName()
    {
        throw hresult_not_implemented();
    }

    hstring Uri::UserName()
    {
        throw hresult_not_implemented();
    }

    int32_t Uri::Port()
    {
        throw hresult_not_implemented();
    }

    bool Uri::Suspicious()
    {
        throw hresult_not_implemented();
    }

    bool Uri::Equals(Windows::Foundation::Uri const& pUri)
    {
        throw hresult_not_implemented();
    }

    Windows::Foundation::Uri Uri::CombineUri(hstring const& relativeUri)
    {
        throw hresult_not_implemented();
    }

    hstring Uri::ToString()
    {
        throw hresult_not_implemented();
    }

    hstring Uri::AbsoluteCanonicalUri()
    {
        throw hresult_not_implemented();
    }

    hstring Uri::DisplayIri()
    {
        throw hresult_not_implemented();
    }

    hstring Uri::UnescapeComponent(hstring const& toUnescape)
    {
        throw hresult_not_implemented();
    }

    hstring Uri::EscapeComponent(hstring const& toEscape)
    {
        throw hresult_not_implemented();
    }
}
