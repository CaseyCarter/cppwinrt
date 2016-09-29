// C++ for the Windows Runtime v1.0.private
// Copyright (c) 2016 Microsoft Corporation

#pragma once

#include "Windows.ApplicationModel.Search.1.h"

WINRT_EXPORT namespace winrt {

namespace ABI::Windows::Foundation::Collections {

#ifndef WINRT_GENERIC_98b9acc1_4b56_532e_ac73_03d5291cca90
#define WINRT_GENERIC_98b9acc1_4b56_532e_ac73_03d5291cca90
template <> struct __declspec(uuid("98b9acc1-4b56-532e-ac73-03d5291cca90")) __declspec(novtable) IVector<hstring> : impl_IVector<hstring> {};
#endif

#ifndef WINRT_GENERIC_2f13c006_a03a_5f69_b090_75a43e33423e
#define WINRT_GENERIC_2f13c006_a03a_5f69_b090_75a43e33423e
template <> struct __declspec(uuid("2f13c006-a03a-5f69-b090-75a43e33423e")) __declspec(novtable) IVectorView<hstring> : impl_IVectorView<hstring> {};
#endif

#ifndef WINRT_GENERIC_e2fcc7c1_3bfc_5a0b_b2b0_72e769d1cb7e
#define WINRT_GENERIC_e2fcc7c1_3bfc_5a0b_b2b0_72e769d1cb7e
template <> struct __declspec(uuid("e2fcc7c1-3bfc-5a0b-b2b0-72e769d1cb7e")) __declspec(novtable) IIterable<hstring> : impl_IIterable<hstring> {};
#endif

#ifndef WINRT_GENERIC_6c26b7be_5f01_5a60_9dd7_fd17be3a9dd6
#define WINRT_GENERIC_6c26b7be_5f01_5a60_9dd7_fd17be3a9dd6
template <> struct __declspec(uuid("6c26b7be-5f01-5a60-9dd7-fd17be3a9dd6")) __declspec(novtable) IVector<Windows::Storage::StorageFolder> : impl_IVector<Windows::Storage::StorageFolder> {};
#endif

#ifndef WINRT_GENERIC_e20debc6_dc4e_542e_a2e7_a24d19c8dd62
#define WINRT_GENERIC_e20debc6_dc4e_542e_a2e7_a24d19c8dd62
template <> struct __declspec(uuid("e20debc6-dc4e-542e-a2e7-a24d19c8dd62")) __declspec(novtable) IVectorView<Windows::Storage::StorageFolder> : impl_IVectorView<Windows::Storage::StorageFolder> {};
#endif

#ifndef WINRT_GENERIC_8c304ebb_6615_50a4_8829_879ecd443236
#define WINRT_GENERIC_8c304ebb_6615_50a4_8829_879ecd443236
template <> struct __declspec(uuid("8c304ebb-6615-50a4-8829-879ecd443236")) __declspec(novtable) IIterator<hstring> : impl_IIterator<hstring> {};
#endif

#ifndef WINRT_GENERIC_5aac96fb_b3b9_5a7f_a920_4b5a8df81168
#define WINRT_GENERIC_5aac96fb_b3b9_5a7f_a920_4b5a8df81168
template <> struct __declspec(uuid("5aac96fb-b3b9-5a7f-a920-4b5a8df81168")) __declspec(novtable) IIterator<Windows::Storage::StorageFolder> : impl_IIterator<Windows::Storage::StorageFolder> {};
#endif

#ifndef WINRT_GENERIC_4669befc_ae5c_52b1_8a97_5466ce61e94e
#define WINRT_GENERIC_4669befc_ae5c_52b1_8a97_5466ce61e94e
template <> struct __declspec(uuid("4669befc-ae5c-52b1-8a97-5466ce61e94e")) __declspec(novtable) IIterable<Windows::Storage::StorageFolder> : impl_IIterable<Windows::Storage::StorageFolder> {};
#endif


}

namespace Windows::ApplicationModel::Search {

template <typename D>
struct WINRT_EBO impl_ILocalContentSuggestionSettings
{
    void Enabled(bool value) const;
    bool Enabled() const;
    Windows::Foundation::Collections::IVector<Windows::Storage::StorageFolder> Locations() const;
    void AqsFilter(hstring_ref value) const;
    hstring AqsFilter() const;
    Windows::Foundation::Collections::IVector<hstring> PropertiesToMatch() const;
};

template <typename D>
struct WINRT_EBO impl_ISearchPaneQueryLinguisticDetails
{
    Windows::Foundation::Collections::IVectorView<hstring> QueryTextAlternatives() const;
    uint32_t QueryTextCompositionStart() const;
    uint32_t QueryTextCompositionLength() const;
};

template <typename D>
struct WINRT_EBO impl_ISearchQueryLinguisticDetails
{
    Windows::Foundation::Collections::IVectorView<hstring> QueryTextAlternatives() const;
    uint32_t QueryTextCompositionStart() const;
    uint32_t QueryTextCompositionLength() const;
};

template <typename D>
struct WINRT_EBO impl_ISearchQueryLinguisticDetailsFactory
{
    Windows::ApplicationModel::Search::SearchQueryLinguisticDetails CreateInstance(const Windows::Foundation::Collections::IIterable<hstring> & queryTextAlternatives, uint32_t queryTextCompositionStart, uint32_t queryTextCompositionLength) const;
};

template <typename D>
struct WINRT_EBO impl_ISearchSuggestionCollection
{
    uint32_t Size() const;
    void AppendQuerySuggestion(hstring_ref text) const;
    void AppendQuerySuggestions(const Windows::Foundation::Collections::IIterable<hstring> & suggestions) const;
    void AppendResultSuggestion(hstring_ref text, hstring_ref detailText, hstring_ref tag, const Windows::Storage::Streams::IRandomAccessStreamReference & image, hstring_ref imageAlternateText) const;
    void AppendSearchSeparator(hstring_ref label) const;
};

template <typename D>
struct WINRT_EBO impl_ISearchSuggestionsRequest
{
    bool IsCanceled() const;
    Windows::ApplicationModel::Search::SearchSuggestionCollection SearchSuggestionCollection() const;
    Windows::ApplicationModel::Search::SearchSuggestionsRequestDeferral GetDeferral() const;
};

template <typename D>
struct WINRT_EBO impl_ISearchSuggestionsRequestDeferral
{
    void Complete() const;
};

struct ILocalContentSuggestionSettings :
    Windows::IInspectable,
    impl::consume<ILocalContentSuggestionSettings>
{
    ILocalContentSuggestionSettings(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<ILocalContentSuggestionSettings>(m_ptr); }
};

struct ISearchPaneQueryLinguisticDetails :
    Windows::IInspectable,
    impl::consume<ISearchPaneQueryLinguisticDetails>
{
    ISearchPaneQueryLinguisticDetails(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<ISearchPaneQueryLinguisticDetails>(m_ptr); }
};

struct ISearchQueryLinguisticDetails :
    Windows::IInspectable,
    impl::consume<ISearchQueryLinguisticDetails>
{
    ISearchQueryLinguisticDetails(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<ISearchQueryLinguisticDetails>(m_ptr); }
};

struct ISearchQueryLinguisticDetailsFactory :
    Windows::IInspectable,
    impl::consume<ISearchQueryLinguisticDetailsFactory>
{
    ISearchQueryLinguisticDetailsFactory(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<ISearchQueryLinguisticDetailsFactory>(m_ptr); }
};

struct ISearchSuggestionCollection :
    Windows::IInspectable,
    impl::consume<ISearchSuggestionCollection>
{
    ISearchSuggestionCollection(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<ISearchSuggestionCollection>(m_ptr); }
};

struct ISearchSuggestionsRequest :
    Windows::IInspectable,
    impl::consume<ISearchSuggestionsRequest>
{
    ISearchSuggestionsRequest(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<ISearchSuggestionsRequest>(m_ptr); }
};

struct ISearchSuggestionsRequestDeferral :
    Windows::IInspectable,
    impl::consume<ISearchSuggestionsRequestDeferral>
{
    ISearchSuggestionsRequestDeferral(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<ISearchSuggestionsRequestDeferral>(m_ptr); }
};

}

}
