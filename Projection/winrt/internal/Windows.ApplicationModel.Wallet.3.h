// C++ for the Windows Runtime v1.0.private
// Copyright (c) 2016 Microsoft Corporation. All rights reserved.

#pragma once

#include "Windows.ApplicationModel.Wallet.2.h"

WINRT_EXPORT namespace winrt {

namespace Windows::ApplicationModel::Wallet {

struct WINRT_EBO WalletBarcode :
    Windows::ApplicationModel::Wallet::IWalletBarcode
{
    WalletBarcode(std::nullptr_t) noexcept {}
    WalletBarcode(Windows::ApplicationModel::Wallet::WalletBarcodeSymbology symbology, hstring_ref value);
    WalletBarcode(const Windows::Storage::Streams::IRandomAccessStreamReference & streamToBarcodeImage);
};

struct WINRT_EBO WalletItem :
    Windows::ApplicationModel::Wallet::IWalletItem
{
    WalletItem(std::nullptr_t) noexcept {}
    WalletItem(Windows::ApplicationModel::Wallet::WalletItemKind kind, hstring_ref displayName);
};

struct WINRT_EBO WalletItemCustomProperty :
    Windows::ApplicationModel::Wallet::IWalletItemCustomProperty
{
    WalletItemCustomProperty(std::nullptr_t) noexcept {}
    WalletItemCustomProperty(hstring_ref name, hstring_ref value);
};

struct WINRT_EBO WalletItemStore :
    Windows::ApplicationModel::Wallet::IWalletItemStore
{
    WalletItemStore(std::nullptr_t) noexcept {}
};

struct WalletManager
{
    WalletManager() = delete;
    static Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Wallet::WalletItemStore> RequestStoreAsync();
};

struct WINRT_EBO WalletRelevantLocation :
    Windows::ApplicationModel::Wallet::IWalletRelevantLocation
{
    WalletRelevantLocation(std::nullptr_t) noexcept {}
    WalletRelevantLocation();
};

struct WINRT_EBO WalletTransaction :
    Windows::ApplicationModel::Wallet::IWalletTransaction
{
    WalletTransaction(std::nullptr_t) noexcept {}
    WalletTransaction();
};

struct WINRT_EBO WalletVerb :
    Windows::ApplicationModel::Wallet::IWalletVerb
{
    WalletVerb(std::nullptr_t) noexcept {}
    WalletVerb(hstring_ref name);
};

}

}
