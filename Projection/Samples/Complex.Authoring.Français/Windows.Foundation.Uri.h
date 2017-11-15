#pragma once

#include "Windows\Foundation\Uri.g.h"

namespace winrt::Windows::Foundation::implementation
{
    struct Uri : UriT<Uri>
    {
        Uri() = delete;
        Uri(hstring const& uri);
        Uri(hstring const& baseUri, hstring const& relativeUri);

        hstring AbsoluteUri();
        hstring DisplayUri();
        hstring Domain();
        hstring Extension();
        hstring Fragment();
        hstring Host();
        hstring Password();
        hstring Path();
        hstring Query();
        Windows::Foundation::WwwFormUrlDecoder QueryParsed();
        hstring RawUri();
        hstring SchemeName();
        hstring UserName();
        int32_t Port();
        bool Suspicious();
        bool Equals(Windows::Foundation::Uri const& pUri);
        Windows::Foundation::Uri CombineUri(hstring const& relativeUri);
        hstring ToString();
        hstring AbsoluteCanonicalUri();
        hstring DisplayIri();

        static hstring UnescapeComponent(hstring const& toUnescape);
        static hstring EscapeComponent(hstring const& toEscape);
    };
}

namespace winrt::Windows::Foundation::factory_implementation
{
    struct Uri : UriT<Uri, implementation::Uri>
    {
    };
}
