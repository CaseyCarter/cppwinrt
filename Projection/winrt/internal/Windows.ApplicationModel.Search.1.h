// C++ for the Windows Runtime v1.29
// Copyright (c) 2016 Microsoft Corporation

#pragma once

#include "../base.h"
#include "Windows.ApplicationModel.Search.0.h"
#include "Windows.Storage.Streams.0.h"
#include "Windows.Foundation.Collections.1.h"
#include "Windows.Storage.1.h"

WINRT_EXPORT namespace winrt {

namespace ABI::Windows::ApplicationModel::Search {

struct __declspec(uuid("eeaeb062-743d-456e-84a3-23f06f2d15d7")) __declspec(novtable) ILocalContentSuggestionSettings : Windows::IInspectable
{
    virtual HRESULT __stdcall put_Enabled(bool value) = 0;
    virtual HRESULT __stdcall get_Enabled(bool * value) = 0;
    virtual HRESULT __stdcall get_Locations(Windows::Foundation::Collections::IVector<Windows::Storage::StorageFolder> ** value) = 0;
    virtual HRESULT __stdcall put_AqsFilter(hstring value) = 0;
    virtual HRESULT __stdcall get_AqsFilter(hstring * value) = 0;
    virtual HRESULT __stdcall get_PropertiesToMatch(Windows::Foundation::Collections::IVector<hstring> ** value) = 0;
};

struct __declspec(uuid("82fb460e-0940-4b6d-b8d0-642b30989e15")) __declspec(novtable) ISearchPaneQueryLinguisticDetails : Windows::IInspectable
{
    virtual HRESULT __stdcall get_QueryTextAlternatives(Windows::Foundation::Collections::IVectorView<hstring> ** value) = 0;
    virtual HRESULT __stdcall get_QueryTextCompositionStart(uint32_t * value) = 0;
    virtual HRESULT __stdcall get_QueryTextCompositionLength(uint32_t * value) = 0;
};

struct __declspec(uuid("46a1205b-69c9-4745-b72f-a8a4fc8f24ae")) __declspec(novtable) ISearchQueryLinguisticDetails : Windows::IInspectable
{
    virtual HRESULT __stdcall get_QueryTextAlternatives(Windows::Foundation::Collections::IVectorView<hstring> ** value) = 0;
    virtual HRESULT __stdcall get_QueryTextCompositionStart(uint32_t * value) = 0;
    virtual HRESULT __stdcall get_QueryTextCompositionLength(uint32_t * value) = 0;
};

struct __declspec(uuid("cac6c3b8-3c64-4dfd-ad9f-479e4d4065a4")) __declspec(novtable) ISearchQueryLinguisticDetailsFactory : Windows::IInspectable
{
    virtual HRESULT __stdcall abi_CreateInstance(Windows::Foundation::Collections::IIterable<hstring> * queryTextAlternatives, uint32_t queryTextCompositionStart, uint32_t queryTextCompositionLength, Windows::ApplicationModel::Search::ISearchQueryLinguisticDetails ** value) = 0;
};

struct __declspec(uuid("323a8a4b-fbea-4446-abbc-3da7915fdd3a")) __declspec(novtable) ISearchSuggestionCollection : Windows::IInspectable
{
    virtual HRESULT __stdcall get_Size(uint32_t * value) = 0;
    virtual HRESULT __stdcall abi_AppendQuerySuggestion(hstring text) = 0;
    virtual HRESULT __stdcall abi_AppendQuerySuggestions(Windows::Foundation::Collections::IIterable<hstring> * suggestions) = 0;
    virtual HRESULT __stdcall abi_AppendResultSuggestion(hstring text, hstring detailText, hstring tag, Windows::Storage::Streams::IRandomAccessStreamReference * image, hstring imageAlternateText) = 0;
    virtual HRESULT __stdcall abi_AppendSearchSeparator(hstring label) = 0;
};

struct __declspec(uuid("4e4e26a7-44e5-4039-9099-6000ead1f0c6")) __declspec(novtable) ISearchSuggestionsRequest : Windows::IInspectable
{
    virtual HRESULT __stdcall get_IsCanceled(bool * value) = 0;
    virtual HRESULT __stdcall get_SearchSuggestionCollection(Windows::ApplicationModel::Search::ISearchSuggestionCollection ** collection) = 0;
    virtual HRESULT __stdcall abi_GetDeferral(Windows::ApplicationModel::Search::ISearchSuggestionsRequestDeferral ** deferral) = 0;
};

struct __declspec(uuid("b71598a9-c065-456d-a845-1eccec5dc28b")) __declspec(novtable) ISearchSuggestionsRequestDeferral : Windows::IInspectable
{
    virtual HRESULT __stdcall abi_Complete() = 0;
};

}

namespace ABI {

template <> struct traits<Windows::ApplicationModel::Search::LocalContentSuggestionSettings> { using default_interface = Windows::ApplicationModel::Search::ILocalContentSuggestionSettings; };
template <> struct traits<Windows::ApplicationModel::Search::SearchPaneQueryLinguisticDetails> { using default_interface = Windows::ApplicationModel::Search::ISearchPaneQueryLinguisticDetails; };
template <> struct traits<Windows::ApplicationModel::Search::SearchQueryLinguisticDetails> { using default_interface = Windows::ApplicationModel::Search::ISearchQueryLinguisticDetails; };
template <> struct traits<Windows::ApplicationModel::Search::SearchSuggestionCollection> { using default_interface = Windows::ApplicationModel::Search::ISearchSuggestionCollection; };
template <> struct traits<Windows::ApplicationModel::Search::SearchSuggestionsRequest> { using default_interface = Windows::ApplicationModel::Search::ISearchSuggestionsRequest; };
template <> struct traits<Windows::ApplicationModel::Search::SearchSuggestionsRequestDeferral> { using default_interface = Windows::ApplicationModel::Search::ISearchSuggestionsRequestDeferral; };

}

namespace Windows::ApplicationModel::Search {

template <typename T> struct impl_ILocalContentSuggestionSettings;
template <typename T> struct impl_ISearchPaneQueryLinguisticDetails;
template <typename T> struct impl_ISearchQueryLinguisticDetails;
template <typename T> struct impl_ISearchQueryLinguisticDetailsFactory;
template <typename T> struct impl_ISearchSuggestionCollection;
template <typename T> struct impl_ISearchSuggestionsRequest;
template <typename T> struct impl_ISearchSuggestionsRequestDeferral;

}

namespace impl {

template <> struct traits<Windows::ApplicationModel::Search::ILocalContentSuggestionSettings>
{
    using abi = ABI::Windows::ApplicationModel::Search::ILocalContentSuggestionSettings;
    template <typename D> using consume = Windows::ApplicationModel::Search::impl_ILocalContentSuggestionSettings<D>;
};

template <> struct traits<Windows::ApplicationModel::Search::ISearchPaneQueryLinguisticDetails>
{
    using abi = ABI::Windows::ApplicationModel::Search::ISearchPaneQueryLinguisticDetails;
    template <typename D> using consume = Windows::ApplicationModel::Search::impl_ISearchPaneQueryLinguisticDetails<D>;
};

template <> struct traits<Windows::ApplicationModel::Search::ISearchQueryLinguisticDetails>
{
    using abi = ABI::Windows::ApplicationModel::Search::ISearchQueryLinguisticDetails;
    template <typename D> using consume = Windows::ApplicationModel::Search::impl_ISearchQueryLinguisticDetails<D>;
};

template <> struct traits<Windows::ApplicationModel::Search::ISearchQueryLinguisticDetailsFactory>
{
    using abi = ABI::Windows::ApplicationModel::Search::ISearchQueryLinguisticDetailsFactory;
    template <typename D> using consume = Windows::ApplicationModel::Search::impl_ISearchQueryLinguisticDetailsFactory<D>;
};

template <> struct traits<Windows::ApplicationModel::Search::ISearchSuggestionCollection>
{
    using abi = ABI::Windows::ApplicationModel::Search::ISearchSuggestionCollection;
    template <typename D> using consume = Windows::ApplicationModel::Search::impl_ISearchSuggestionCollection<D>;
};

template <> struct traits<Windows::ApplicationModel::Search::ISearchSuggestionsRequest>
{
    using abi = ABI::Windows::ApplicationModel::Search::ISearchSuggestionsRequest;
    template <typename D> using consume = Windows::ApplicationModel::Search::impl_ISearchSuggestionsRequest<D>;
};

template <> struct traits<Windows::ApplicationModel::Search::ISearchSuggestionsRequestDeferral>
{
    using abi = ABI::Windows::ApplicationModel::Search::ISearchSuggestionsRequestDeferral;
    template <typename D> using consume = Windows::ApplicationModel::Search::impl_ISearchSuggestionsRequestDeferral<D>;
};

template <> struct traits<Windows::ApplicationModel::Search::LocalContentSuggestionSettings>
{
    using abi = ABI::Windows::ApplicationModel::Search::LocalContentSuggestionSettings;
    static constexpr const wchar_t * name() noexcept { return L"Windows.ApplicationModel.Search.LocalContentSuggestionSettings"; }
};

template <> struct traits<Windows::ApplicationModel::Search::SearchPaneQueryLinguisticDetails>
{
    using abi = ABI::Windows::ApplicationModel::Search::SearchPaneQueryLinguisticDetails;
    static constexpr const wchar_t * name() noexcept { return L"Windows.ApplicationModel.Search.SearchPaneQueryLinguisticDetails"; }
};

template <> struct traits<Windows::ApplicationModel::Search::SearchQueryLinguisticDetails>
{
    using abi = ABI::Windows::ApplicationModel::Search::SearchQueryLinguisticDetails;
    static constexpr const wchar_t * name() noexcept { return L"Windows.ApplicationModel.Search.SearchQueryLinguisticDetails"; }
};

template <> struct traits<Windows::ApplicationModel::Search::SearchSuggestionCollection>
{
    using abi = ABI::Windows::ApplicationModel::Search::SearchSuggestionCollection;
    static constexpr const wchar_t * name() noexcept { return L"Windows.ApplicationModel.Search.SearchSuggestionCollection"; }
};

template <> struct traits<Windows::ApplicationModel::Search::SearchSuggestionsRequest>
{
    using abi = ABI::Windows::ApplicationModel::Search::SearchSuggestionsRequest;
    static constexpr const wchar_t * name() noexcept { return L"Windows.ApplicationModel.Search.SearchSuggestionsRequest"; }
};

template <> struct traits<Windows::ApplicationModel::Search::SearchSuggestionsRequestDeferral>
{
    using abi = ABI::Windows::ApplicationModel::Search::SearchSuggestionsRequestDeferral;
    static constexpr const wchar_t * name() noexcept { return L"Windows.ApplicationModel.Search.SearchSuggestionsRequestDeferral"; }
};

}

}
