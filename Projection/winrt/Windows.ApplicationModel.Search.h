// C++ for the Windows Runtime v1.0.private
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "base.h"
WINRT_WARNING_PUSH

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
            typename D::abi_guard guard(this->shim());
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
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Enabled());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Locations(impl::abi_arg_out<Windows::Foundation::Collections::IVector<Windows::Storage::StorageFolder>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Locations());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_AqsFilter(impl::abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AqsFilter(*reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_AqsFilter(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().AqsFilter());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_PropertiesToMatch(impl::abi_arg_out<Windows::Foundation::Collections::IVector<hstring>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().PropertiesToMatch());
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
    HRESULT __stdcall get_QueryTextAlternatives(impl::abi_arg_out<Windows::Foundation::Collections::IVectorView<hstring>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().QueryTextAlternatives());
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
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().QueryTextCompositionStart());
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
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().QueryTextCompositionLength());
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
    HRESULT __stdcall get_QueryTextAlternatives(impl::abi_arg_out<Windows::Foundation::Collections::IVectorView<hstring>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().QueryTextAlternatives());
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
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().QueryTextCompositionStart());
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
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().QueryTextCompositionLength());
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
    HRESULT __stdcall abi_CreateInstance(impl::abi_arg_in<Windows::Foundation::Collections::IIterable<hstring>> queryTextAlternatives, uint32_t queryTextCompositionStart, uint32_t queryTextCompositionLength, impl::abi_arg_out<Windows::ApplicationModel::Search::ISearchQueryLinguisticDetails> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().CreateInstance(*reinterpret_cast<const Windows::Foundation::Collections::IIterable<hstring> *>(&queryTextAlternatives), queryTextCompositionStart, queryTextCompositionLength));
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
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Size());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_AppendQuerySuggestion(impl::abi_arg_in<hstring> text) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AppendQuerySuggestion(*reinterpret_cast<const hstring *>(&text));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_AppendQuerySuggestions(impl::abi_arg_in<Windows::Foundation::Collections::IIterable<hstring>> suggestions) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AppendQuerySuggestions(*reinterpret_cast<const Windows::Foundation::Collections::IIterable<hstring> *>(&suggestions));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_AppendResultSuggestion(impl::abi_arg_in<hstring> text, impl::abi_arg_in<hstring> detailText, impl::abi_arg_in<hstring> tag, impl::abi_arg_in<Windows::Storage::Streams::IRandomAccessStreamReference> image, impl::abi_arg_in<hstring> imageAlternateText) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AppendResultSuggestion(*reinterpret_cast<const hstring *>(&text), *reinterpret_cast<const hstring *>(&detailText), *reinterpret_cast<const hstring *>(&tag), *reinterpret_cast<const Windows::Storage::Streams::IRandomAccessStreamReference *>(&image), *reinterpret_cast<const hstring *>(&imageAlternateText));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_AppendSearchSeparator(impl::abi_arg_in<hstring> label) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
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
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IsCanceled());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_SearchSuggestionCollection(impl::abi_arg_out<Windows::ApplicationModel::Search::ISearchSuggestionCollection> collection) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *collection = detach_abi(this->shim().SearchSuggestionCollection());
            return S_OK;
        }
        catch (...)
        {
            *collection = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetDeferral(impl::abi_arg_out<Windows::ApplicationModel::Search::ISearchSuggestionsRequestDeferral> deferral) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *deferral = detach_abi(this->shim().GetDeferral());
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
            typename D::abi_guard guard(this->shim());
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
    check_hresult(WINRT_SHIM(ISearchPaneQueryLinguisticDetails)->get_QueryTextAlternatives(put_abi(value)));
    return value;
}

template <typename D> uint32_t impl_ISearchPaneQueryLinguisticDetails<D>::QueryTextCompositionStart() const
{
    uint32_t value {};
    check_hresult(WINRT_SHIM(ISearchPaneQueryLinguisticDetails)->get_QueryTextCompositionStart(&value));
    return value;
}

template <typename D> uint32_t impl_ISearchPaneQueryLinguisticDetails<D>::QueryTextCompositionLength() const
{
    uint32_t value {};
    check_hresult(WINRT_SHIM(ISearchPaneQueryLinguisticDetails)->get_QueryTextCompositionLength(&value));
    return value;
}

template <typename D> uint32_t impl_ISearchSuggestionCollection<D>::Size() const
{
    uint32_t value {};
    check_hresult(WINRT_SHIM(ISearchSuggestionCollection)->get_Size(&value));
    return value;
}

template <typename D> void impl_ISearchSuggestionCollection<D>::AppendQuerySuggestion(hstring_view text) const
{
    check_hresult(WINRT_SHIM(ISearchSuggestionCollection)->abi_AppendQuerySuggestion(get_abi(text)));
}

template <typename D> void impl_ISearchSuggestionCollection<D>::AppendQuerySuggestions(iterable<hstring> suggestions) const
{
    check_hresult(WINRT_SHIM(ISearchSuggestionCollection)->abi_AppendQuerySuggestions(get_abi(suggestions)));
}

template <typename D> void impl_ISearchSuggestionCollection<D>::AppendResultSuggestion(hstring_view text, hstring_view detailText, hstring_view tag, const Windows::Storage::Streams::IRandomAccessStreamReference & image, hstring_view imageAlternateText) const
{
    check_hresult(WINRT_SHIM(ISearchSuggestionCollection)->abi_AppendResultSuggestion(get_abi(text), get_abi(detailText), get_abi(tag), get_abi(image), get_abi(imageAlternateText)));
}

template <typename D> void impl_ISearchSuggestionCollection<D>::AppendSearchSeparator(hstring_view label) const
{
    check_hresult(WINRT_SHIM(ISearchSuggestionCollection)->abi_AppendSearchSeparator(get_abi(label)));
}

template <typename D> void impl_ILocalContentSuggestionSettings<D>::Enabled(bool value) const
{
    check_hresult(WINRT_SHIM(ILocalContentSuggestionSettings)->put_Enabled(value));
}

template <typename D> bool impl_ILocalContentSuggestionSettings<D>::Enabled() const
{
    bool value {};
    check_hresult(WINRT_SHIM(ILocalContentSuggestionSettings)->get_Enabled(&value));
    return value;
}

template <typename D> Windows::Foundation::Collections::IVector<Windows::Storage::StorageFolder> impl_ILocalContentSuggestionSettings<D>::Locations() const
{
    Windows::Foundation::Collections::IVector<Windows::Storage::StorageFolder> value;
    check_hresult(WINRT_SHIM(ILocalContentSuggestionSettings)->get_Locations(put_abi(value)));
    return value;
}

template <typename D> void impl_ILocalContentSuggestionSettings<D>::AqsFilter(hstring_view value) const
{
    check_hresult(WINRT_SHIM(ILocalContentSuggestionSettings)->put_AqsFilter(get_abi(value)));
}

template <typename D> hstring impl_ILocalContentSuggestionSettings<D>::AqsFilter() const
{
    hstring value;
    check_hresult(WINRT_SHIM(ILocalContentSuggestionSettings)->get_AqsFilter(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::Collections::IVector<hstring> impl_ILocalContentSuggestionSettings<D>::PropertiesToMatch() const
{
    Windows::Foundation::Collections::IVector<hstring> value;
    check_hresult(WINRT_SHIM(ILocalContentSuggestionSettings)->get_PropertiesToMatch(put_abi(value)));
    return value;
}

template <typename D> Windows::ApplicationModel::Search::SearchQueryLinguisticDetails impl_ISearchQueryLinguisticDetailsFactory<D>::CreateInstance(iterable<hstring> queryTextAlternatives, uint32_t queryTextCompositionStart, uint32_t queryTextCompositionLength) const
{
    Windows::ApplicationModel::Search::SearchQueryLinguisticDetails value { nullptr };
    check_hresult(WINRT_SHIM(ISearchQueryLinguisticDetailsFactory)->abi_CreateInstance(get_abi(queryTextAlternatives), queryTextCompositionStart, queryTextCompositionLength, put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::Collections::IVectorView<hstring> impl_ISearchQueryLinguisticDetails<D>::QueryTextAlternatives() const
{
    Windows::Foundation::Collections::IVectorView<hstring> value;
    check_hresult(WINRT_SHIM(ISearchQueryLinguisticDetails)->get_QueryTextAlternatives(put_abi(value)));
    return value;
}

template <typename D> uint32_t impl_ISearchQueryLinguisticDetails<D>::QueryTextCompositionStart() const
{
    uint32_t value {};
    check_hresult(WINRT_SHIM(ISearchQueryLinguisticDetails)->get_QueryTextCompositionStart(&value));
    return value;
}

template <typename D> uint32_t impl_ISearchQueryLinguisticDetails<D>::QueryTextCompositionLength() const
{
    uint32_t value {};
    check_hresult(WINRT_SHIM(ISearchQueryLinguisticDetails)->get_QueryTextCompositionLength(&value));
    return value;
}

template <typename D> void impl_ISearchSuggestionsRequestDeferral<D>::Complete() const
{
    check_hresult(WINRT_SHIM(ISearchSuggestionsRequestDeferral)->abi_Complete());
}

template <typename D> bool impl_ISearchSuggestionsRequest<D>::IsCanceled() const
{
    bool value {};
    check_hresult(WINRT_SHIM(ISearchSuggestionsRequest)->get_IsCanceled(&value));
    return value;
}

template <typename D> Windows::ApplicationModel::Search::SearchSuggestionCollection impl_ISearchSuggestionsRequest<D>::SearchSuggestionCollection() const
{
    Windows::ApplicationModel::Search::SearchSuggestionCollection collection { nullptr };
    check_hresult(WINRT_SHIM(ISearchSuggestionsRequest)->get_SearchSuggestionCollection(put_abi(collection)));
    return collection;
}

template <typename D> Windows::ApplicationModel::Search::SearchSuggestionsRequestDeferral impl_ISearchSuggestionsRequest<D>::GetDeferral() const
{
    Windows::ApplicationModel::Search::SearchSuggestionsRequestDeferral deferral { nullptr };
    check_hresult(WINRT_SHIM(ISearchSuggestionsRequest)->abi_GetDeferral(put_abi(deferral)));
    return deferral;
}

inline LocalContentSuggestionSettings::LocalContentSuggestionSettings() :
    LocalContentSuggestionSettings(activate_instance<LocalContentSuggestionSettings>())
{}

inline SearchQueryLinguisticDetails::SearchQueryLinguisticDetails(iterable<hstring> queryTextAlternatives, uint32_t queryTextCompositionStart, uint32_t queryTextCompositionLength) :
    SearchQueryLinguisticDetails(get_activation_factory<SearchQueryLinguisticDetails, ISearchQueryLinguisticDetailsFactory>().CreateInstance(queryTextAlternatives, queryTextCompositionStart, queryTextCompositionLength))
{}

}

}

template<>
struct std::hash<winrt::Windows::ApplicationModel::Search::ILocalContentSuggestionSettings>
{
    size_t operator()(const winrt::Windows::ApplicationModel::Search::ILocalContentSuggestionSettings & value) const noexcept
    {
        return winrt::impl::hash_unknown(value);
    }
};

template<>
struct std::hash<winrt::Windows::ApplicationModel::Search::ISearchPaneQueryLinguisticDetails>
{
    size_t operator()(const winrt::Windows::ApplicationModel::Search::ISearchPaneQueryLinguisticDetails & value) const noexcept
    {
        return winrt::impl::hash_unknown(value);
    }
};

template<>
struct std::hash<winrt::Windows::ApplicationModel::Search::ISearchQueryLinguisticDetails>
{
    size_t operator()(const winrt::Windows::ApplicationModel::Search::ISearchQueryLinguisticDetails & value) const noexcept
    {
        return winrt::impl::hash_unknown(value);
    }
};

template<>
struct std::hash<winrt::Windows::ApplicationModel::Search::ISearchQueryLinguisticDetailsFactory>
{
    size_t operator()(const winrt::Windows::ApplicationModel::Search::ISearchQueryLinguisticDetailsFactory & value) const noexcept
    {
        return winrt::impl::hash_unknown(value);
    }
};

template<>
struct std::hash<winrt::Windows::ApplicationModel::Search::ISearchSuggestionCollection>
{
    size_t operator()(const winrt::Windows::ApplicationModel::Search::ISearchSuggestionCollection & value) const noexcept
    {
        return winrt::impl::hash_unknown(value);
    }
};

template<>
struct std::hash<winrt::Windows::ApplicationModel::Search::ISearchSuggestionsRequest>
{
    size_t operator()(const winrt::Windows::ApplicationModel::Search::ISearchSuggestionsRequest & value) const noexcept
    {
        return winrt::impl::hash_unknown(value);
    }
};

template<>
struct std::hash<winrt::Windows::ApplicationModel::Search::ISearchSuggestionsRequestDeferral>
{
    size_t operator()(const winrt::Windows::ApplicationModel::Search::ISearchSuggestionsRequestDeferral & value) const noexcept
    {
        return winrt::impl::hash_unknown(value);
    }
};

template<>
struct std::hash<winrt::Windows::ApplicationModel::Search::LocalContentSuggestionSettings>
{
    size_t operator()(const winrt::Windows::ApplicationModel::Search::LocalContentSuggestionSettings & value) const noexcept
    {
        return winrt::impl::hash_unknown(value);
    }
};

template<>
struct std::hash<winrt::Windows::ApplicationModel::Search::SearchPaneQueryLinguisticDetails>
{
    size_t operator()(const winrt::Windows::ApplicationModel::Search::SearchPaneQueryLinguisticDetails & value) const noexcept
    {
        return winrt::impl::hash_unknown(value);
    }
};

template<>
struct std::hash<winrt::Windows::ApplicationModel::Search::SearchQueryLinguisticDetails>
{
    size_t operator()(const winrt::Windows::ApplicationModel::Search::SearchQueryLinguisticDetails & value) const noexcept
    {
        return winrt::impl::hash_unknown(value);
    }
};

template<>
struct std::hash<winrt::Windows::ApplicationModel::Search::SearchSuggestionCollection>
{
    size_t operator()(const winrt::Windows::ApplicationModel::Search::SearchSuggestionCollection & value) const noexcept
    {
        return winrt::impl::hash_unknown(value);
    }
};

template<>
struct std::hash<winrt::Windows::ApplicationModel::Search::SearchSuggestionsRequest>
{
    size_t operator()(const winrt::Windows::ApplicationModel::Search::SearchSuggestionsRequest & value) const noexcept
    {
        return winrt::impl::hash_unknown(value);
    }
};

template<>
struct std::hash<winrt::Windows::ApplicationModel::Search::SearchSuggestionsRequestDeferral>
{
    size_t operator()(const winrt::Windows::ApplicationModel::Search::SearchSuggestionsRequestDeferral & value) const noexcept
    {
        return winrt::impl::hash_unknown(value);
    }
};

WINRT_WARNING_POP
