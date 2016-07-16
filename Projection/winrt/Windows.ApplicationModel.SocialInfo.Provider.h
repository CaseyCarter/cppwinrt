// C++ for the Windows Runtime v1.29
// Copyright (c) 2016 Microsoft Corporation

#pragma once

#include "internal\Windows.ApplicationModel.SocialInfo.class.h"
#include "internal\Windows.Foundation.Collections.class.h"
#include "internal\Windows.Foundation.class.h"
#include "internal\Windows.ApplicationModel.SocialInfo.Provider.class.h"
#include "Windows.ApplicationModel.SocialInfo.h"

WINRT_EXPORT namespace winrt {

namespace impl {

template <typename D>
struct produce<D, Windows::ApplicationModel::SocialInfo::Provider::ISocialDashboardItemUpdater> : produce_base<D, Windows::ApplicationModel::SocialInfo::Provider::ISocialDashboardItemUpdater>
{
    HRESULT __stdcall get_OwnerRemoteId(abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            *value = detach(shim().OwnerRemoteId());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Content(abi_arg_out<Windows::ApplicationModel::SocialInfo::ISocialFeedContent> value) noexcept override
    {
        try
        {
            *value = detach(shim().Content());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Timestamp(abi_arg_out<Windows::Foundation::DateTime> value) noexcept override
    {
        try
        {
            *value = detach(shim().Timestamp());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Timestamp(abi_arg_in<Windows::Foundation::DateTime> value) noexcept override
    {
        try
        {
            shim().Timestamp(*reinterpret_cast<const Windows::Foundation::DateTime *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Thumbnail(abi_arg_in<Windows::ApplicationModel::SocialInfo::ISocialItemThumbnail> value) noexcept override
    {
        try
        {
            shim().Thumbnail(*reinterpret_cast<const Windows::ApplicationModel::SocialInfo::SocialItemThumbnail *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Thumbnail(abi_arg_out<Windows::ApplicationModel::SocialInfo::ISocialItemThumbnail> value) noexcept override
    {
        try
        {
            *value = detach(shim().Thumbnail());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_CommitAsync(abi_arg_out<Windows::Foundation::IAsyncAction> operation) noexcept override
    {
        try
        {
            *operation = detach(shim().CommitAsync());
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_TargetUri(abi_arg_out<Windows::Foundation::IUriRuntimeClass> value) noexcept override
    {
        try
        {
            *value = detach(shim().TargetUri());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_TargetUri(abi_arg_in<Windows::Foundation::IUriRuntimeClass> value) noexcept override
    {
        try
        {
            shim().TargetUri(*reinterpret_cast<const Windows::Foundation::Uri *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::ApplicationModel::SocialInfo::Provider::ISocialFeedUpdater> : produce_base<D, Windows::ApplicationModel::SocialInfo::Provider::ISocialFeedUpdater>
{
    HRESULT __stdcall get_OwnerRemoteId(abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            *value = detach(shim().OwnerRemoteId());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Kind(Windows::ApplicationModel::SocialInfo::SocialFeedKind * value) noexcept override
    {
        try
        {
            *value = detach(shim().Kind());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Items(abi_arg_out<Windows::Foundation::Collections::IVector<Windows::ApplicationModel::SocialInfo::SocialFeedItem>> value) noexcept override
    {
        try
        {
            *value = detach(shim().Items());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_CommitAsync(abi_arg_out<Windows::Foundation::IAsyncAction> operation) noexcept override
    {
        try
        {
            *operation = detach(shim().CommitAsync());
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::ApplicationModel::SocialInfo::Provider::ISocialInfoProviderManagerStatics> : produce_base<D, Windows::ApplicationModel::SocialInfo::Provider::ISocialInfoProviderManagerStatics>
{
    HRESULT __stdcall abi_CreateSocialFeedUpdaterAsync(Windows::ApplicationModel::SocialInfo::SocialFeedKind kind, Windows::ApplicationModel::SocialInfo::SocialFeedUpdateMode mode, abi_arg_in<hstring> ownerRemoteId, abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::SocialInfo::Provider::SocialFeedUpdater>> operation) noexcept override
    {
        try
        {
            *operation = detach(shim().CreateSocialFeedUpdaterAsync(kind, mode, *reinterpret_cast<const hstring *>(&ownerRemoteId)));
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_CreateDashboardItemUpdaterAsync(abi_arg_in<hstring> ownerRemoteId, abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::SocialInfo::Provider::SocialDashboardItemUpdater>> operation) noexcept override
    {
        try
        {
            *operation = detach(shim().CreateDashboardItemUpdaterAsync(*reinterpret_cast<const hstring *>(&ownerRemoteId)));
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_UpdateBadgeCountValue(abi_arg_in<hstring> itemRemoteId, int32_t newCount) noexcept override
    {
        try
        {
            shim().UpdateBadgeCountValue(*reinterpret_cast<const hstring *>(&itemRemoteId), newCount);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_ReportNewContentAvailable(abi_arg_in<hstring> contactRemoteId, Windows::ApplicationModel::SocialInfo::SocialFeedKind kind) noexcept override
    {
        try
        {
            shim().ReportNewContentAvailable(*reinterpret_cast<const hstring *>(&contactRemoteId), kind);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_ProvisionAsync(abi_arg_out<Windows::Foundation::IAsyncOperation<bool>> operation) noexcept override
    {
        try
        {
            *operation = detach(shim().ProvisionAsync());
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_DeprovisionAsync(abi_arg_out<Windows::Foundation::IAsyncAction> operation) noexcept override
    {
        try
        {
            *operation = detach(shim().DeprovisionAsync());
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }
};

}

namespace Windows::ApplicationModel::SocialInfo::Provider {

template <typename D> hstring impl_ISocialFeedUpdater<D>::OwnerRemoteId() const
{
    hstring value;
    check_hresult(shim()->get_OwnerRemoteId(put(value)));
    return value;
}

template <typename D> Windows::ApplicationModel::SocialInfo::SocialFeedKind impl_ISocialFeedUpdater<D>::Kind() const
{
    Windows::ApplicationModel::SocialInfo::SocialFeedKind value {};
    check_hresult(shim()->get_Kind(&value));
    return value;
}

template <typename D> Windows::Foundation::Collections::IVector<Windows::ApplicationModel::SocialInfo::SocialFeedItem> impl_ISocialFeedUpdater<D>::Items() const
{
    Windows::Foundation::Collections::IVector<Windows::ApplicationModel::SocialInfo::SocialFeedItem> value;
    check_hresult(shim()->get_Items(put(value)));
    return value;
}

template <typename D> Windows::Foundation::IAsyncAction impl_ISocialFeedUpdater<D>::CommitAsync() const
{
    Windows::Foundation::IAsyncAction operation;
    check_hresult(shim()->abi_CommitAsync(put(operation)));
    return operation;
}

template <typename D> hstring impl_ISocialDashboardItemUpdater<D>::OwnerRemoteId() const
{
    hstring value;
    check_hresult(shim()->get_OwnerRemoteId(put(value)));
    return value;
}

template <typename D> Windows::ApplicationModel::SocialInfo::SocialFeedContent impl_ISocialDashboardItemUpdater<D>::Content() const
{
    Windows::ApplicationModel::SocialInfo::SocialFeedContent value { nullptr };
    check_hresult(shim()->get_Content(put(value)));
    return value;
}

template <typename D> Windows::Foundation::DateTime impl_ISocialDashboardItemUpdater<D>::Timestamp() const
{
    Windows::Foundation::DateTime value {};
    check_hresult(shim()->get_Timestamp(put(value)));
    return value;
}

template <typename D> void impl_ISocialDashboardItemUpdater<D>::Timestamp(const Windows::Foundation::DateTime & value) const
{
    check_hresult(shim()->put_Timestamp(get(value)));
}

template <typename D> void impl_ISocialDashboardItemUpdater<D>::Thumbnail(const Windows::ApplicationModel::SocialInfo::SocialItemThumbnail & value) const
{
    check_hresult(shim()->put_Thumbnail(get(value)));
}

template <typename D> Windows::ApplicationModel::SocialInfo::SocialItemThumbnail impl_ISocialDashboardItemUpdater<D>::Thumbnail() const
{
    Windows::ApplicationModel::SocialInfo::SocialItemThumbnail value { nullptr };
    check_hresult(shim()->get_Thumbnail(put(value)));
    return value;
}

template <typename D> Windows::Foundation::IAsyncAction impl_ISocialDashboardItemUpdater<D>::CommitAsync() const
{
    Windows::Foundation::IAsyncAction operation;
    check_hresult(shim()->abi_CommitAsync(put(operation)));
    return operation;
}

template <typename D> Windows::Foundation::Uri impl_ISocialDashboardItemUpdater<D>::TargetUri() const
{
    Windows::Foundation::Uri value { nullptr };
    check_hresult(shim()->get_TargetUri(put(value)));
    return value;
}

template <typename D> void impl_ISocialDashboardItemUpdater<D>::TargetUri(const Windows::Foundation::Uri & value) const
{
    check_hresult(shim()->put_TargetUri(get(value)));
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::SocialInfo::Provider::SocialFeedUpdater> impl_ISocialInfoProviderManagerStatics<D>::CreateSocialFeedUpdaterAsync(Windows::ApplicationModel::SocialInfo::SocialFeedKind kind, Windows::ApplicationModel::SocialInfo::SocialFeedUpdateMode mode, hstring_ref ownerRemoteId) const
{
    Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::SocialInfo::Provider::SocialFeedUpdater> operation;
    check_hresult(shim()->abi_CreateSocialFeedUpdaterAsync(kind, mode, get(ownerRemoteId), put(operation)));
    return operation;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::SocialInfo::Provider::SocialDashboardItemUpdater> impl_ISocialInfoProviderManagerStatics<D>::CreateDashboardItemUpdaterAsync(hstring_ref ownerRemoteId) const
{
    Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::SocialInfo::Provider::SocialDashboardItemUpdater> operation;
    check_hresult(shim()->abi_CreateDashboardItemUpdaterAsync(get(ownerRemoteId), put(operation)));
    return operation;
}

template <typename D> void impl_ISocialInfoProviderManagerStatics<D>::UpdateBadgeCountValue(hstring_ref itemRemoteId, int32_t newCount) const
{
    check_hresult(shim()->abi_UpdateBadgeCountValue(get(itemRemoteId), newCount));
}

template <typename D> void impl_ISocialInfoProviderManagerStatics<D>::ReportNewContentAvailable(hstring_ref contactRemoteId, Windows::ApplicationModel::SocialInfo::SocialFeedKind kind) const
{
    check_hresult(shim()->abi_ReportNewContentAvailable(get(contactRemoteId), kind));
}

template <typename D> Windows::Foundation::IAsyncOperation<bool> impl_ISocialInfoProviderManagerStatics<D>::ProvisionAsync() const
{
    Windows::Foundation::IAsyncOperation<bool> operation;
    check_hresult(shim()->abi_ProvisionAsync(put(operation)));
    return operation;
}

template <typename D> Windows::Foundation::IAsyncAction impl_ISocialInfoProviderManagerStatics<D>::DeprovisionAsync() const
{
    Windows::Foundation::IAsyncAction operation;
    check_hresult(shim()->abi_DeprovisionAsync(put(operation)));
    return operation;
}

inline Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::SocialInfo::Provider::SocialFeedUpdater> SocialInfoProviderManager::CreateSocialFeedUpdaterAsync(Windows::ApplicationModel::SocialInfo::SocialFeedKind kind, Windows::ApplicationModel::SocialInfo::SocialFeedUpdateMode mode, hstring_ref ownerRemoteId)
{
    return GetActivationFactory<SocialInfoProviderManager, ISocialInfoProviderManagerStatics>().CreateSocialFeedUpdaterAsync(kind, mode, ownerRemoteId);
}

inline Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::SocialInfo::Provider::SocialDashboardItemUpdater> SocialInfoProviderManager::CreateDashboardItemUpdaterAsync(hstring_ref ownerRemoteId)
{
    return GetActivationFactory<SocialInfoProviderManager, ISocialInfoProviderManagerStatics>().CreateDashboardItemUpdaterAsync(ownerRemoteId);
}

inline void SocialInfoProviderManager::UpdateBadgeCountValue(hstring_ref itemRemoteId, int32_t newCount)
{
    GetActivationFactory<SocialInfoProviderManager, ISocialInfoProviderManagerStatics>().UpdateBadgeCountValue(itemRemoteId, newCount);
}

inline void SocialInfoProviderManager::ReportNewContentAvailable(hstring_ref contactRemoteId, Windows::ApplicationModel::SocialInfo::SocialFeedKind kind)
{
    GetActivationFactory<SocialInfoProviderManager, ISocialInfoProviderManagerStatics>().ReportNewContentAvailable(contactRemoteId, kind);
}

inline Windows::Foundation::IAsyncOperation<bool> SocialInfoProviderManager::ProvisionAsync()
{
    return GetActivationFactory<SocialInfoProviderManager, ISocialInfoProviderManagerStatics>().ProvisionAsync();
}

inline Windows::Foundation::IAsyncAction SocialInfoProviderManager::DeprovisionAsync()
{
    return GetActivationFactory<SocialInfoProviderManager, ISocialInfoProviderManagerStatics>().DeprovisionAsync();
}

}

}
