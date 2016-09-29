// C++ for the Windows Runtime v1.0.private
// Copyright (c) 2016 Microsoft Corporation

#pragma once

#include "internal/Windows.Foundation.Collections.3.h"
#include "internal/Windows.Storage.Streams.3.h"
#include "internal/Windows.ApplicationModel.Search.3.h"
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
            this->shim().Enabled(value);
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
            *value = detach(this->shim().Enabled());
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
            *value = detach(this->shim().Locations());
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
            this->shim().AqsFilter(*reinterpret_cast<const hstring *>(&value));
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
            *value = detach(this->shim().AqsFilter());
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
            *value = detach(this->shim().PropertiesToMatch());
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
            *value = detach(this->shim().QueryTextAlternatives());
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
            *value = detach(this->shim().QueryTextCompositionStart());
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
            *value = detach(this->shim().QueryTextCompositionLength());
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
            *value = detach(this->shim().QueryTextAlternatives());
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
            *value = detach(this->shim().QueryTextCompositionStart());
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
            *value = detach(this->shim().QueryTextCompositionLength());
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
            *value = detach(this->shim().CreateInstance(*reinterpret_cast<const Windows::Foundation::Collections::IIterable<hstring> *>(&queryTextAlternatives), queryTextCompositionStart, queryTextCompositionLength));
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
            *value = detach(this->shim().Size());
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
            this->shim().AppendQuerySuggestion(*reinterpret_cast<const hstring *>(&text));
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
            this->shim().AppendQuerySuggestions(*reinterpret_cast<const Windows::Foundation::Collections::IIterable<hstring> *>(&suggestions));
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
            this->shim().AppendResultSuggestion(*reinterpret_cast<const hstring *>(&text), *reinterpret_cast<const hstring *>(&detailText), *reinterpret_cast<const hstring *>(&tag), *reinterpret_cast<const Windows::Storage::Streams::IRandomAccessStreamReference *>(&image), *reinterpret_cast<const hstring *>(&imageAlternateText));
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
            this->shim().AppendSearchSeparator(*reinterpret_cast<const hstring *>(&label));
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
            *value = detach(this->shim().IsCanceled());
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
            *collection = detach(this->shim().SearchSuggestionCollection());
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
            *deferral = detach(this->shim().GetDeferral());
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
            this->shim().Complete();
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
    check_hresult(static_cast<const ISearchPaneQueryLinguisticDetails &>(static_cast<const D &>(*this))->get_QueryTextAlternatives(put(value)));
    return value;
}

template <typename D> uint32_t impl_ISearchPaneQueryLinguisticDetails<D>::QueryTextCompositionStart() const
{
    uint32_t value {};
    check_hresult(static_cast<const ISearchPaneQueryLinguisticDetails &>(static_cast<const D &>(*this))->get_QueryTextCompositionStart(&value));
    return value;
}

template <typename D> uint32_t impl_ISearchPaneQueryLinguisticDetails<D>::QueryTextCompositionLength() const
{
    uint32_t value {};
    check_hresult(static_cast<const ISearchPaneQueryLinguisticDetails &>(static_cast<const D &>(*this))->get_QueryTextCompositionLength(&value));
    return value;
}

template <typename D> uint32_t impl_ISearchSuggestionCollection<D>::Size() const
{
    uint32_t value {};
    check_hresult(static_cast<const ISearchSuggestionCollection &>(static_cast<const D &>(*this))->get_Size(&value));
    return value;
}

template <typename D> void impl_ISearchSuggestionCollection<D>::AppendQuerySuggestion(hstring_ref text) const
{
    check_hresult(static_cast<const ISearchSuggestionCollection &>(static_cast<const D &>(*this))->abi_AppendQuerySuggestion(get(text)));
}

template <typename D> void impl_ISearchSuggestionCollection<D>::AppendQuerySuggestions(const Windows::Foundation::Collections::IIterable<hstring> & suggestions) const
{
    check_hresult(static_cast<const ISearchSuggestionCollection &>(static_cast<const D &>(*this))->abi_AppendQuerySuggestions(get(suggestions)));
}

template <typename D> void impl_ISearchSuggestionCollection<D>::AppendResultSuggestion(hstring_ref text, hstring_ref detailText, hstring_ref tag, const Windows::Storage::Streams::IRandomAccessStreamReference & image, hstring_ref imageAlternateText) const
{
    check_hresult(static_cast<const ISearchSuggestionCollection &>(static_cast<const D &>(*this))->abi_AppendResultSuggestion(get(text), get(detailText), get(tag), get(image), get(imageAlternateText)));
}

template <typename D> void impl_ISearchSuggestionCollection<D>::AppendSearchSeparator(hstring_ref label) const
{
    check_hresult(static_cast<const ISearchSuggestionCollection &>(static_cast<const D &>(*this))->abi_AppendSearchSeparator(get(label)));
}

template <typename D> void impl_ILocalContentSuggestionSettings<D>::Enabled(bool value) const
{
    check_hresult(static_cast<const ILocalContentSuggestionSettings &>(static_cast<const D &>(*this))->put_Enabled(value));
}

template <typename D> bool impl_ILocalContentSuggestionSettings<D>::Enabled() const
{
    bool value {};
    check_hresult(static_cast<const ILocalContentSuggestionSettings &>(static_cast<const D &>(*this))->get_Enabled(&value));
    return value;
}

template <typename D> Windows::Foundation::Collections::IVector<Windows::Storage::StorageFolder> impl_ILocalContentSuggestionSettings<D>::Locations() const
{
    Windows::Foundation::Collections::IVector<Windows::Storage::StorageFolder> value;
    check_hresult(static_cast<const ILocalContentSuggestionSettings &>(static_cast<const D &>(*this))->get_Locations(put(value)));
    return value;
}

template <typename D> void impl_ILocalContentSuggestionSettings<D>::AqsFilter(hstring_ref value) const
{
    check_hresult(static_cast<const ILocalContentSuggestionSettings &>(static_cast<const D &>(*this))->put_AqsFilter(get(value)));
}

template <typename D> hstring impl_ILocalContentSuggestionSettings<D>::AqsFilter() const
{
    hstring value;
    check_hresult(static_cast<const ILocalContentSuggestionSettings &>(static_cast<const D &>(*this))->get_AqsFilter(put(value)));
    return value;
}

template <typename D> Windows::Foundation::Collections::IVector<hstring> impl_ILocalContentSuggestionSettings<D>::PropertiesToMatch() const
{
    Windows::Foundation::Collections::IVector<hstring> value;
    check_hresult(static_cast<const ILocalContentSuggestionSettings &>(static_cast<const D &>(*this))->get_PropertiesToMatch(put(value)));
    return value;
}

template <typename D> Windows::ApplicationModel::Search::SearchQueryLinguisticDetails impl_ISearchQueryLinguisticDetailsFactory<D>::CreateInstance(const Windows::Foundation::Collections::IIterable<hstring> & queryTextAlternatives, uint32_t queryTextCompositionStart, uint32_t queryTextCompositionLength) const
{
    Windows::ApplicationModel::Search::SearchQueryLinguisticDetails value { nullptr };
    check_hresult(static_cast<const ISearchQueryLinguisticDetailsFactory &>(static_cast<const D &>(*this))->abi_CreateInstance(get(queryTextAlternatives), queryTextCompositionStart, queryTextCompositionLength, put(value)));
    return value;
}

template <typename D> Windows::Foundation::Collections::IVectorView<hstring> impl_ISearchQueryLinguisticDetails<D>::QueryTextAlternatives() const
{
    Windows::Foundation::Collections::IVectorView<hstring> value;
    check_hresult(static_cast<const ISearchQueryLinguisticDetails &>(static_cast<const D &>(*this))->get_QueryTextAlternatives(put(value)));
    return value;
}

template <typename D> uint32_t impl_ISearchQueryLinguisticDetails<D>::QueryTextCompositionStart() const
{
    uint32_t value {};
    check_hresult(static_cast<const ISearchQueryLinguisticDetails &>(static_cast<const D &>(*this))->get_QueryTextCompositionStart(&value));
    return value;
}

template <typename D> uint32_t impl_ISearchQueryLinguisticDetails<D>::QueryTextCompositionLength() const
{
    uint32_t value {};
    check_hresult(static_cast<const ISearchQueryLinguisticDetails &>(static_cast<const D &>(*this))->get_QueryTextCompositionLength(&value));
    return value;
}

template <typename D> void impl_ISearchSuggestionsRequestDeferral<D>::Complete() const
{
    check_hresult(static_cast<const ISearchSuggestionsRequestDeferral &>(static_cast<const D &>(*this))->abi_Complete());
}

template <typename D> bool impl_ISearchSuggestionsRequest<D>::IsCanceled() const
{
    bool value {};
    check_hresult(static_cast<const ISearchSuggestionsRequest &>(static_cast<const D &>(*this))->get_IsCanceled(&value));
    return value;
}

template <typename D> Windows::ApplicationModel::Search::SearchSuggestionCollection impl_ISearchSuggestionsRequest<D>::SearchSuggestionCollection() const
{
    Windows::ApplicationModel::Search::SearchSuggestionCollection collection { nullptr };
    check_hresult(static_cast<const ISearchSuggestionsRequest &>(static_cast<const D &>(*this))->get_SearchSuggestionCollection(put(collection)));
    return collection;
}

template <typename D> Windows::ApplicationModel::Search::SearchSuggestionsRequestDeferral impl_ISearchSuggestionsRequest<D>::GetDeferral() const
{
    Windows::ApplicationModel::Search::SearchSuggestionsRequestDeferral deferral { nullptr };
    check_hresult(static_cast<const ISearchSuggestionsRequest &>(static_cast<const D &>(*this))->abi_GetDeferral(put(deferral)));
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
