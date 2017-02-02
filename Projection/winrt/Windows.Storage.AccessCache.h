// C++ for the Windows Runtime v1.0.private
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "internal/Windows.Storage.3.h"
#include "internal/Windows.Foundation.3.h"
#include "internal/Windows.Foundation.Collections.3.h"
#include "internal/Windows.Storage.AccessCache.3.h"
#include "Windows.Storage.h"
#include "Windows.Foundation.Collections.h"

WINRT_EXPORT namespace winrt {

namespace impl {

template <typename D>
struct produce<D, Windows::Storage::AccessCache::IItemRemovedEventArgs> : produce_base<D, Windows::Storage::AccessCache::IItemRemovedEventArgs>
{
    HRESULT __stdcall get_RemovedEntry(abi_arg_out<Windows::Storage::AccessCache::AccessListEntry> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach(this->shim().RemovedEntry());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Storage::AccessCache::IStorageApplicationPermissionsStatics> : produce_base<D, Windows::Storage::AccessCache::IStorageApplicationPermissionsStatics>
{
    HRESULT __stdcall get_FutureAccessList(abi_arg_out<Windows::Storage::AccessCache::IStorageItemAccessList> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach(this->shim().FutureAccessList());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_MostRecentlyUsedList(abi_arg_out<Windows::Storage::AccessCache::IStorageItemMostRecentlyUsedList> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach(this->shim().MostRecentlyUsedList());
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
struct produce<D, Windows::Storage::AccessCache::IStorageItemAccessList> : produce_base<D, Windows::Storage::AccessCache::IStorageItemAccessList>
{
    HRESULT __stdcall abi_AddOverloadDefaultMetadata(abi_arg_in<Windows::Storage::IStorageItem> file, abi_arg_out<hstring> token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach(this->shim().Add(*reinterpret_cast<const Windows::Storage::IStorageItem *>(&file)));
            return S_OK;
        }
        catch (...)
        {
            *token = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_Add(abi_arg_in<Windows::Storage::IStorageItem> file, abi_arg_in<hstring> metadata, abi_arg_out<hstring> token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach(this->shim().Add(*reinterpret_cast<const Windows::Storage::IStorageItem *>(&file), *reinterpret_cast<const hstring *>(&metadata)));
            return S_OK;
        }
        catch (...)
        {
            *token = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_AddOrReplaceOverloadDefaultMetadata(abi_arg_in<hstring> token, abi_arg_in<Windows::Storage::IStorageItem> file) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AddOrReplace(*reinterpret_cast<const hstring *>(&token), *reinterpret_cast<const Windows::Storage::IStorageItem *>(&file));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_AddOrReplace(abi_arg_in<hstring> token, abi_arg_in<Windows::Storage::IStorageItem> file, abi_arg_in<hstring> metadata) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AddOrReplace(*reinterpret_cast<const hstring *>(&token), *reinterpret_cast<const Windows::Storage::IStorageItem *>(&file), *reinterpret_cast<const hstring *>(&metadata));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetItemAsync(abi_arg_in<hstring> token, abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Storage::IStorageItem>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach(this->shim().GetItemAsync(*reinterpret_cast<const hstring *>(&token)));
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetFileAsync(abi_arg_in<hstring> token, abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Storage::StorageFile>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach(this->shim().GetFileAsync(*reinterpret_cast<const hstring *>(&token)));
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetFolderAsync(abi_arg_in<hstring> token, abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Storage::StorageFolder>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach(this->shim().GetFolderAsync(*reinterpret_cast<const hstring *>(&token)));
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetItemWithOptionsAsync(abi_arg_in<hstring> token, Windows::Storage::AccessCache::AccessCacheOptions options, abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Storage::IStorageItem>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach(this->shim().GetItemAsync(*reinterpret_cast<const hstring *>(&token), options));
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetFileWithOptionsAsync(abi_arg_in<hstring> token, Windows::Storage::AccessCache::AccessCacheOptions options, abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Storage::StorageFile>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach(this->shim().GetFileAsync(*reinterpret_cast<const hstring *>(&token), options));
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetFolderWithOptionsAsync(abi_arg_in<hstring> token, Windows::Storage::AccessCache::AccessCacheOptions options, abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Storage::StorageFolder>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach(this->shim().GetFolderAsync(*reinterpret_cast<const hstring *>(&token), options));
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_Remove(abi_arg_in<hstring> token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Remove(*reinterpret_cast<const hstring *>(&token));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_ContainsItem(abi_arg_in<hstring> token, bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach(this->shim().ContainsItem(*reinterpret_cast<const hstring *>(&token)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_Clear() noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Clear();
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_CheckAccess(abi_arg_in<Windows::Storage::IStorageItem> file, bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach(this->shim().CheckAccess(*reinterpret_cast<const Windows::Storage::IStorageItem *>(&file)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Entries(abi_arg_out<Windows::Foundation::Collections::IVectorView<Windows::Storage::AccessCache::AccessListEntry>> entries) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *entries = detach(this->shim().Entries());
            return S_OK;
        }
        catch (...)
        {
            *entries = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_MaximumItemsAllowed(uint32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach(this->shim().MaximumItemsAllowed());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Storage::AccessCache::IStorageItemMostRecentlyUsedList> : produce_base<D, Windows::Storage::AccessCache::IStorageItemMostRecentlyUsedList>
{
    HRESULT __stdcall add_ItemRemoved(abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::Storage::AccessCache::StorageItemMostRecentlyUsedList, Windows::Storage::AccessCache::ItemRemovedEventArgs>> handler, event_token * eventCookie) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *eventCookie = detach(this->shim().ItemRemoved(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::Storage::AccessCache::StorageItemMostRecentlyUsedList, Windows::Storage::AccessCache::ItemRemovedEventArgs> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_ItemRemoved(event_token eventCookie) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ItemRemoved(eventCookie);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Storage::AccessCache::IStorageItemMostRecentlyUsedList2> : produce_base<D, Windows::Storage::AccessCache::IStorageItemMostRecentlyUsedList2>
{
    HRESULT __stdcall abi_AddWithMetadataAndVisibility(abi_arg_in<Windows::Storage::IStorageItem> file, abi_arg_in<hstring> metadata, Windows::Storage::AccessCache::RecentStorageItemVisibility visibility, abi_arg_out<hstring> token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach(this->shim().Add(*reinterpret_cast<const Windows::Storage::IStorageItem *>(&file), *reinterpret_cast<const hstring *>(&metadata), visibility));
            return S_OK;
        }
        catch (...)
        {
            *token = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_AddOrReplaceWithMetadataAndVisibility(abi_arg_in<hstring> token, abi_arg_in<Windows::Storage::IStorageItem> file, abi_arg_in<hstring> metadata, Windows::Storage::AccessCache::RecentStorageItemVisibility visibility) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AddOrReplace(*reinterpret_cast<const hstring *>(&token), *reinterpret_cast<const Windows::Storage::IStorageItem *>(&file), *reinterpret_cast<const hstring *>(&metadata), visibility);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

}

namespace Windows::Storage::AccessCache {

template <typename D> Windows::Storage::AccessCache::AccessListEntry impl_IItemRemovedEventArgs<D>::RemovedEntry() const
{
    Windows::Storage::AccessCache::AccessListEntry value {};
    check_hresult(WINRT_SHIM(IItemRemovedEventArgs)->get_RemovedEntry(put(value)));
    return value;
}

template <typename D> hstring impl_IStorageItemAccessList<D>::Add(const Windows::Storage::IStorageItem & file) const
{
    hstring token;
    check_hresult(WINRT_SHIM(IStorageItemAccessList)->abi_AddOverloadDefaultMetadata(get(file), put(token)));
    return token;
}

template <typename D> hstring impl_IStorageItemAccessList<D>::Add(const Windows::Storage::IStorageItem & file, hstring_ref metadata) const
{
    hstring token;
    check_hresult(WINRT_SHIM(IStorageItemAccessList)->abi_Add(get(file), get(metadata), put(token)));
    return token;
}

template <typename D> void impl_IStorageItemAccessList<D>::AddOrReplace(hstring_ref token, const Windows::Storage::IStorageItem & file) const
{
    check_hresult(WINRT_SHIM(IStorageItemAccessList)->abi_AddOrReplaceOverloadDefaultMetadata(get(token), get(file)));
}

template <typename D> void impl_IStorageItemAccessList<D>::AddOrReplace(hstring_ref token, const Windows::Storage::IStorageItem & file, hstring_ref metadata) const
{
    check_hresult(WINRT_SHIM(IStorageItemAccessList)->abi_AddOrReplace(get(token), get(file), get(metadata)));
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Storage::IStorageItem> impl_IStorageItemAccessList<D>::GetItemAsync(hstring_ref token) const
{
    Windows::Foundation::IAsyncOperation<Windows::Storage::IStorageItem> operation;
    check_hresult(WINRT_SHIM(IStorageItemAccessList)->abi_GetItemAsync(get(token), put(operation)));
    return operation;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Storage::StorageFile> impl_IStorageItemAccessList<D>::GetFileAsync(hstring_ref token) const
{
    Windows::Foundation::IAsyncOperation<Windows::Storage::StorageFile> operation;
    check_hresult(WINRT_SHIM(IStorageItemAccessList)->abi_GetFileAsync(get(token), put(operation)));
    return operation;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Storage::StorageFolder> impl_IStorageItemAccessList<D>::GetFolderAsync(hstring_ref token) const
{
    Windows::Foundation::IAsyncOperation<Windows::Storage::StorageFolder> operation;
    check_hresult(WINRT_SHIM(IStorageItemAccessList)->abi_GetFolderAsync(get(token), put(operation)));
    return operation;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Storage::IStorageItem> impl_IStorageItemAccessList<D>::GetItemAsync(hstring_ref token, Windows::Storage::AccessCache::AccessCacheOptions options) const
{
    Windows::Foundation::IAsyncOperation<Windows::Storage::IStorageItem> operation;
    check_hresult(WINRT_SHIM(IStorageItemAccessList)->abi_GetItemWithOptionsAsync(get(token), options, put(operation)));
    return operation;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Storage::StorageFile> impl_IStorageItemAccessList<D>::GetFileAsync(hstring_ref token, Windows::Storage::AccessCache::AccessCacheOptions options) const
{
    Windows::Foundation::IAsyncOperation<Windows::Storage::StorageFile> operation;
    check_hresult(WINRT_SHIM(IStorageItemAccessList)->abi_GetFileWithOptionsAsync(get(token), options, put(operation)));
    return operation;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Storage::StorageFolder> impl_IStorageItemAccessList<D>::GetFolderAsync(hstring_ref token, Windows::Storage::AccessCache::AccessCacheOptions options) const
{
    Windows::Foundation::IAsyncOperation<Windows::Storage::StorageFolder> operation;
    check_hresult(WINRT_SHIM(IStorageItemAccessList)->abi_GetFolderWithOptionsAsync(get(token), options, put(operation)));
    return operation;
}

template <typename D> void impl_IStorageItemAccessList<D>::Remove(hstring_ref token) const
{
    check_hresult(WINRT_SHIM(IStorageItemAccessList)->abi_Remove(get(token)));
}

template <typename D> bool impl_IStorageItemAccessList<D>::ContainsItem(hstring_ref token) const
{
    bool value {};
    check_hresult(WINRT_SHIM(IStorageItemAccessList)->abi_ContainsItem(get(token), &value));
    return value;
}

template <typename D> void impl_IStorageItemAccessList<D>::Clear() const
{
    check_hresult(WINRT_SHIM(IStorageItemAccessList)->abi_Clear());
}

template <typename D> bool impl_IStorageItemAccessList<D>::CheckAccess(const Windows::Storage::IStorageItem & file) const
{
    bool value {};
    check_hresult(WINRT_SHIM(IStorageItemAccessList)->abi_CheckAccess(get(file), &value));
    return value;
}

template <typename D> Windows::Storage::AccessCache::AccessListEntryView impl_IStorageItemAccessList<D>::Entries() const
{
    Windows::Storage::AccessCache::AccessListEntryView entries { nullptr };
    check_hresult(WINRT_SHIM(IStorageItemAccessList)->get_Entries(put(entries)));
    return entries;
}

template <typename D> uint32_t impl_IStorageItemAccessList<D>::MaximumItemsAllowed() const
{
    uint32_t value {};
    check_hresult(WINRT_SHIM(IStorageItemAccessList)->get_MaximumItemsAllowed(&value));
    return value;
}

template <typename D> event_token impl_IStorageItemMostRecentlyUsedList<D>::ItemRemoved(const Windows::Foundation::TypedEventHandler<Windows::Storage::AccessCache::StorageItemMostRecentlyUsedList, Windows::Storage::AccessCache::ItemRemovedEventArgs> & handler) const
{
    event_token eventCookie {};
    check_hresult(WINRT_SHIM(IStorageItemMostRecentlyUsedList)->add_ItemRemoved(get(handler), &eventCookie));
    return eventCookie;
}

template <typename D> event_revoker<IStorageItemMostRecentlyUsedList> impl_IStorageItemMostRecentlyUsedList<D>::ItemRemoved(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Storage::AccessCache::StorageItemMostRecentlyUsedList, Windows::Storage::AccessCache::ItemRemovedEventArgs> & handler) const
{
    return impl::make_event_revoker<D, IStorageItemMostRecentlyUsedList>(this, &ABI::Windows::Storage::AccessCache::IStorageItemMostRecentlyUsedList::remove_ItemRemoved, ItemRemoved(handler));
}

template <typename D> void impl_IStorageItemMostRecentlyUsedList<D>::ItemRemoved(event_token eventCookie) const
{
    check_hresult(WINRT_SHIM(IStorageItemMostRecentlyUsedList)->remove_ItemRemoved(eventCookie));
}

template <typename D> hstring impl_IStorageItemMostRecentlyUsedList2<D>::Add(const Windows::Storage::IStorageItem & file, hstring_ref metadata, Windows::Storage::AccessCache::RecentStorageItemVisibility visibility) const
{
    hstring token;
    check_hresult(WINRT_SHIM(IStorageItemMostRecentlyUsedList2)->abi_AddWithMetadataAndVisibility(get(file), get(metadata), visibility, put(token)));
    return token;
}

template <typename D> void impl_IStorageItemMostRecentlyUsedList2<D>::AddOrReplace(hstring_ref token, const Windows::Storage::IStorageItem & file, hstring_ref metadata, Windows::Storage::AccessCache::RecentStorageItemVisibility visibility) const
{
    check_hresult(WINRT_SHIM(IStorageItemMostRecentlyUsedList2)->abi_AddOrReplaceWithMetadataAndVisibility(get(token), get(file), get(metadata), visibility));
}

template <typename D> Windows::Storage::AccessCache::StorageItemAccessList impl_IStorageApplicationPermissionsStatics<D>::FutureAccessList() const
{
    Windows::Storage::AccessCache::StorageItemAccessList value { nullptr };
    check_hresult(WINRT_SHIM(IStorageApplicationPermissionsStatics)->get_FutureAccessList(put(value)));
    return value;
}

template <typename D> Windows::Storage::AccessCache::StorageItemMostRecentlyUsedList impl_IStorageApplicationPermissionsStatics<D>::MostRecentlyUsedList() const
{
    Windows::Storage::AccessCache::StorageItemMostRecentlyUsedList value { nullptr };
    check_hresult(WINRT_SHIM(IStorageApplicationPermissionsStatics)->get_MostRecentlyUsedList(put(value)));
    return value;
}

inline Windows::Storage::AccessCache::StorageItemAccessList StorageApplicationPermissions::FutureAccessList()
{
    return get_activation_factory<StorageApplicationPermissions, IStorageApplicationPermissionsStatics>().FutureAccessList();
}

inline Windows::Storage::AccessCache::StorageItemMostRecentlyUsedList StorageApplicationPermissions::MostRecentlyUsedList()
{
    return get_activation_factory<StorageApplicationPermissions, IStorageApplicationPermissionsStatics>().MostRecentlyUsedList();
}

}

}
