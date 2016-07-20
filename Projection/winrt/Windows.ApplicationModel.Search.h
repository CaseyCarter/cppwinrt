// C++ for the Windows Runtime v1.29
// Copyright (c) 2016 Microsoft Corporation

#pragma once

#include "internal\Windows.Foundation.Collections.class.h"
#include "internal\Windows.Storage.Streams.class.h"
#include "internal\Windows.ApplicationModel.Search.class.h"
#include "Windows.ApplicationModel.h"

WINRT_EXPORT namespace winrt {

namespace impl {

template <typename D>
struct produce<D, Windows::ApplicationModel::Search::ILocalContentSuggestionSettings> : produce_base<D, Windows::ApplicationModel::Search::ILocalContentSuggestionSettings>
{
    HRESULT __stdcall put_Enabled(bool value) noexcept override
    {
        try
        {
            shim().Enabled(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Enabled(bool * value) noexcept override
    {
        try
        {
            *value = detach(shim().Enabled());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Locations(abi_arg_out<Windows::Foundation::Collections::IVector<Windows::Storage::StorageFolder>> value) noexcept override
    {
        try
        {
            *value = detach(shim().Locations());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_AqsFilter(abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            shim().AqsFilter(*reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_AqsFilter(abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            *value = detach(shim().AqsFilter());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_PropertiesToMatch(abi_arg_out<Windows::Foundation::Collections::IVector<hstring>> value) noexcept override
    {
        try
        {
            *value = detach(shim().PropertiesToMatch());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::ApplicationModel::Search::ISearchPaneQueryLinguisticDetails> : produce_base<D, Windows::ApplicationModel::Search::ISearchPaneQueryLinguisticDetails>
{
    HRESULT __stdcall get_QueryTextAlternatives(abi_arg_out<Windows::Foundation::Collections::IVectorView<hstring>> value) noexcept override
    {
        try
        {
            *value = detach(shim().QueryTextAlternatives());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_QueryTextCompositionStart(uint32_t * value) noexcept override
    {
        try
        {
            *value = detach(shim().QueryTextCompositionStart());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_QueryTextCompositionLength(uint32_t * value) noexcept override
    {
        try
        {
            *value = detach(shim().QueryTextCompositionLength());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::ApplicationModel::Search::ISearchQueryLinguisticDetails> : produce_base<D, Windows::ApplicationModel::Search::ISearchQueryLinguisticDetails>
{
    HRESULT __stdcall get_QueryTextAlternatives(abi_arg_out<Windows::Foundation::Collections::IVectorView<hstring>> value) noexcept override
    {
        try
        {
            *value = detach(shim().QueryTextAlternatives());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_QueryTextCompositionStart(uint32_t * value) noexcept override
    {
        try
        {
            *value = detach(shim().QueryTextCompositionStart());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_QueryTextCompositionLength(uint32_t * value) noexcept override
    {
        try
        {
            *value = detach(shim().QueryTextCompositionLength());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::ApplicationModel::Search::ISearchQueryLinguisticDetailsFactory> : produce_base<D, Windows::ApplicationModel::Search::ISearchQueryLinguisticDetailsFactory>
{
    HRESULT __stdcall abi_CreateInstance(abi_arg_in<Windows::Foundation::Collections::IIterable<hstring>> queryTextAlternatives, uint32_t queryTextCompositionStart, uint32_t queryTextCompositionLength, abi_arg_out<Windows::ApplicationModel::Search::ISearchQueryLinguisticDetails> value) noexcept override
    {
        try
        {
            *value = detach(shim().CreateInstance(*reinterpret_cast<const Windows::Foundation::Collections::IIterable<hstring> *>(&queryTextAlternatives), queryTextCompositionStart, queryTextCompositionLength));
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::ApplicationModel::Search::ISearchSuggestionCollection> : produce_base<D, Windows::ApplicationModel::Search::ISearchSuggestionCollection>
{
    HRESULT __stdcall get_Size(uint32_t * value) noexcept override
    {
        try
        {
            *value = detach(shim().Size());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_AppendQuerySuggestion(abi_arg_in<hstring> text) noexcept override
    {
        try
        {
            shim().AppendQuerySuggestion(*reinterpret_cast<const hstring *>(&text));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_AppendQuerySuggestions(abi_arg_in<Windows::Foundation::Collections::IIterable<hstring>> suggestions) noexcept override
    {
        try
        {
            shim().AppendQuerySuggestions(*reinterpret_cast<const Windows::Foundation::Collections::IIterable<hstring> *>(&suggestions));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_AppendResultSuggestion(abi_arg_in<hstring> text, abi_arg_in<hstring> detailText, abi_arg_in<hstring> tag, abi_arg_in<Windows::Storage::Streams::IRandomAccessStreamReference> image, abi_arg_in<hstring> imageAlternateText) noexcept override
    {
        try
        {
            shim().AppendResultSuggestion(*reinterpret_cast<const hstring *>(&text), *reinterpret_cast<const hstring *>(&detailText), *reinterpret_cast<const hstring *>(&tag), *reinterpret_cast<const Windows::Storage::Streams::IRandomAccessStreamReference *>(&image), *reinterpret_cast<const hstring *>(&imageAlternateText));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_AppendSearchSeparator(abi_arg_in<hstring> label) noexcept override
    {
        try
        {
            shim().AppendSearchSeparator(*reinterpret_cast<const hstring *>(&label));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::ApplicationModel::Search::ISearchSuggestionsRequest> : produce_base<D, Windows::ApplicationModel::Search::ISearchSuggestionsRequest>
{
    HRESULT __stdcall get_IsCanceled(bool * value) noexcept override
    {
        try
        {
            *value = detach(shim().IsCanceled());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_SearchSuggestionCollection(abi_arg_out<Windows::ApplicationModel::Search::ISearchSuggestionCollection> collection) noexcept override
    {
        try
        {
            *collection = detach(shim().SearchSuggestionCollection());
            return S_OK;
        }
        catch (...)
        {
            *collection = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetDeferral(abi_arg_out<Windows::ApplicationModel::Search::ISearchSuggestionsRequestDeferral> deferral) noexcept override
    {
        try
        {
            *deferral = detach(shim().GetDeferral());
            return S_OK;
        }
        catch (...)
        {
            *deferral = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::ApplicationModel::Search::ISearchSuggestionsRequestDeferral> : produce_base<D, Windows::ApplicationModel::Search::ISearchSuggestionsRequestDeferral>
{
    HRESULT __stdcall abi_Complete() noexcept override
    {
        try
        {
            shim().Complete();
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

}

namespace Windows::ApplicationModel::Search {

template <typename D> Windows::Foundation::Collections::IVectorView<hstring> impl_ISearchPaneQueryLinguisticDetails<D>::QueryTextAlternatives() const
{
    Windows::Foundation::Collections::IVectorView<hstring> value;
    check_hresult(shim()->get_QueryTextAlternatives(put(value)));
    return value;
}

template <typename D> uint32_t impl_ISearchPaneQueryLinguisticDetails<D>::QueryTextCompositionStart() const
{
    uint32_t value {};
    check_hresult(shim()->get_QueryTextCompositionStart(&value));
    return value;
}

template <typename D> uint32_t impl_ISearchPaneQueryLinguisticDetails<D>::QueryTextCompositionLength() const
{
    uint32_t value {};
    check_hresult(shim()->get_QueryTextCompositionLength(&value));
    return value;
}

template <typename D> uint32_t impl_ISearchSuggestionCollection<D>::Size() const
{
    uint32_t value {};
    check_hresult(shim()->get_Size(&value));
    return value;
}

template <typename D> void impl_ISearchSuggestionCollection<D>::AppendQuerySuggestion(hstring_ref text) const
{
    check_hresult(shim()->abi_AppendQuerySuggestion(get(text)));
}

template <typename D> void impl_ISearchSuggestionCollection<D>::AppendQuerySuggestions(const Windows::Foundation::Collections::IIterable<hstring> & suggestions) const
{
    check_hresult(shim()->abi_AppendQuerySuggestions(get(suggestions)));
}

template <typename D> void impl_ISearchSuggestionCollection<D>::AppendResultSuggestion(hstring_ref text, hstring_ref detailText, hstring_ref tag, const Windows::Storage::Streams::IRandomAccessStreamReference & image, hstring_ref imageAlternateText) const
{
    check_hresult(shim()->abi_AppendResultSuggestion(get(text), get(detailText), get(tag), get(image), get(imageAlternateText)));
}

template <typename D> void impl_ISearchSuggestionCollection<D>::AppendSearchSeparator(hstring_ref label) const
{
    check_hresult(shim()->abi_AppendSearchSeparator(get(label)));
}

template <typename D> void impl_ILocalContentSuggestionSettings<D>::Enabled(bool value) const
{
    check_hresult(shim()->put_Enabled(value));
}

template <typename D> bool impl_ILocalContentSuggestionSettings<D>::Enabled() const
{
    bool value {};
    check_hresult(shim()->get_Enabled(&value));
    return value;
}

template <typename D> Windows::Foundation::Collections::IVector<Windows::Storage::StorageFolder> impl_ILocalContentSuggestionSettings<D>::Locations() const
{
    Windows::Foundation::Collections::IVector<Windows::Storage::StorageFolder> value;
    check_hresult(shim()->get_Locations(put(value)));
    return value;
}

template <typename D> void impl_ILocalContentSuggestionSettings<D>::AqsFilter(hstring_ref value) const
{
    check_hresult(shim()->put_AqsFilter(get(value)));
}

template <typename D> hstring impl_ILocalContentSuggestionSettings<D>::AqsFilter() const
{
    hstring value;
    check_hresult(shim()->get_AqsFilter(put(value)));
    return value;
}

template <typename D> Windows::Foundation::Collections::IVector<hstring> impl_ILocalContentSuggestionSettings<D>::PropertiesToMatch() const
{
    Windows::Foundation::Collections::IVector<hstring> value;
    check_hresult(shim()->get_PropertiesToMatch(put(value)));
    return value;
}

template <typename D> Windows::ApplicationModel::Search::SearchQueryLinguisticDetails impl_ISearchQueryLinguisticDetailsFactory<D>::CreateInstance(const Windows::Foundation::Collections::IIterable<hstring> & queryTextAlternatives, uint32_t queryTextCompositionStart, uint32_t queryTextCompositionLength) const
{
    Windows::ApplicationModel::Search::SearchQueryLinguisticDetails value { nullptr };
    check_hresult(shim()->abi_CreateInstance(get(queryTextAlternatives), queryTextCompositionStart, queryTextCompositionLength, put(value)));
    return value;
}

template <typename D> Windows::Foundation::Collections::IVectorView<hstring> impl_ISearchQueryLinguisticDetails<D>::QueryTextAlternatives() const
{
    Windows::Foundation::Collections::IVectorView<hstring> value;
    check_hresult(shim()->get_QueryTextAlternatives(put(value)));
    return value;
}

template <typename D> uint32_t impl_ISearchQueryLinguisticDetails<D>::QueryTextCompositionStart() const
{
    uint32_t value {};
    check_hresult(shim()->get_QueryTextCompositionStart(&value));
    return value;
}

template <typename D> uint32_t impl_ISearchQueryLinguisticDetails<D>::QueryTextCompositionLength() const
{
    uint32_t value {};
    check_hresult(shim()->get_QueryTextCompositionLength(&value));
    return value;
}

template <typename D> void impl_ISearchSuggestionsRequestDeferral<D>::Complete() const
{
    check_hresult(shim()->abi_Complete());
}

template <typename D> bool impl_ISearchSuggestionsRequest<D>::IsCanceled() const
{
    bool value {};
    check_hresult(shim()->get_IsCanceled(&value));
    return value;
}

template <typename D> Windows::ApplicationModel::Search::SearchSuggestionCollection impl_ISearchSuggestionsRequest<D>::SearchSuggestionCollection() const
{
    Windows::ApplicationModel::Search::SearchSuggestionCollection collection { nullptr };
    check_hresult(shim()->get_SearchSuggestionCollection(put(collection)));
    return collection;
}

template <typename D> Windows::ApplicationModel::Search::SearchSuggestionsRequestDeferral impl_ISearchSuggestionsRequest<D>::GetDeferral() const
{
    Windows::ApplicationModel::Search::SearchSuggestionsRequestDeferral deferral { nullptr };
    check_hresult(shim()->abi_GetDeferral(put(deferral)));
    return deferral;
}

inline LocalContentSuggestionSettings::LocalContentSuggestionSettings() :
    LocalContentSuggestionSettings(activate_instance<LocalContentSuggestionSettings>())
{}

inline SearchQueryLinguisticDetails::SearchQueryLinguisticDetails(const Windows::Foundation::Collections::IIterable<hstring> & queryTextAlternatives, uint32_t queryTextCompositionStart, uint32_t queryTextCompositionLength) :
    SearchQueryLinguisticDetails(get_activation_factory<SearchQueryLinguisticDetails, ISearchQueryLinguisticDetailsFactory>().CreateInstance(queryTextAlternatives, queryTextCompositionStart, queryTextCompositionLength))
{}

}

}
