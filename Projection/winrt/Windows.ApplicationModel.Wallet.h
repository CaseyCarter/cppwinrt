// C++ for the Windows Runtime v1.29
// Copyright (c) 2016 Microsoft Corporation

#pragma once

#include "internal\Windows.Foundation.class.h"
#include "internal\Windows.Storage.Streams.class.h"
#include "internal\Windows.UI.class.h"
#include "internal\Windows.Foundation.Collections.class.h"
#include "internal\Windows.Devices.Geolocation.class.h"
#include "internal\Windows.ApplicationModel.Wallet.class.h"
#include "Windows.ApplicationModel.h"

WINRT_EXPORT namespace winrt {

namespace impl {

template <typename D>
struct produce<D, Windows::ApplicationModel::Wallet::IWalletBarcode> : produce_base<D, Windows::ApplicationModel::Wallet::IWalletBarcode>
{
    HRESULT __stdcall get_Symbology(Windows::ApplicationModel::Wallet::WalletBarcodeSymbology * value) noexcept override
    {
        try
        {
            *value = detach(shim().Symbology());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Value(abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            *value = detach(shim().Value());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetImageAsync(abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Storage::Streams::IRandomAccessStreamReference>> operation) noexcept override
    {
        try
        {
            *operation = detach(shim().GetImageAsync());
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
struct produce<D, Windows::ApplicationModel::Wallet::IWalletBarcodeFactory> : produce_base<D, Windows::ApplicationModel::Wallet::IWalletBarcodeFactory>
{
    HRESULT __stdcall abi_CreateWalletBarcode(Windows::ApplicationModel::Wallet::WalletBarcodeSymbology symbology, abi_arg_in<hstring> value, abi_arg_out<Windows::ApplicationModel::Wallet::IWalletBarcode> barcode) noexcept override
    {
        try
        {
            *barcode = detach(shim().CreateWalletBarcode(symbology, *reinterpret_cast<const hstring *>(&value)));
            return S_OK;
        }
        catch (...)
        {
            *barcode = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_CreateCustomWalletBarcode(abi_arg_in<Windows::Storage::Streams::IRandomAccessStreamReference> streamToBarcodeImage, abi_arg_out<Windows::ApplicationModel::Wallet::IWalletBarcode> barcode) noexcept override
    {
        try
        {
            *barcode = detach(shim().CreateCustomWalletBarcode(*reinterpret_cast<const Windows::Storage::Streams::IRandomAccessStreamReference *>(&streamToBarcodeImage)));
            return S_OK;
        }
        catch (...)
        {
            *barcode = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::ApplicationModel::Wallet::IWalletItem> : produce_base<D, Windows::ApplicationModel::Wallet::IWalletItem>
{
    HRESULT __stdcall get_DisplayName(abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            *value = detach(shim().DisplayName());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_DisplayName(abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            shim().DisplayName(*reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Id(abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            *value = detach(shim().Id());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_IsAcknowledged(bool * value) noexcept override
    {
        try
        {
            *value = detach(shim().IsAcknowledged());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_IsAcknowledged(bool value) noexcept override
    {
        try
        {
            shim().IsAcknowledged(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_IssuerDisplayName(abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            *value = detach(shim().IssuerDisplayName());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_IssuerDisplayName(abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            shim().IssuerDisplayName(*reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_LastUpdated(abi_arg_out<Windows::Foundation::IReference<Windows::Foundation::DateTime>> value) noexcept override
    {
        try
        {
            *value = detach(shim().LastUpdated());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_LastUpdated(abi_arg_in<Windows::Foundation::IReference<Windows::Foundation::DateTime>> value) noexcept override
    {
        try
        {
            shim().LastUpdated(*reinterpret_cast<const Windows::Foundation::IReference<Windows::Foundation::DateTime> *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Kind(Windows::ApplicationModel::Wallet::WalletItemKind * value) noexcept override
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

    HRESULT __stdcall get_Barcode(abi_arg_out<Windows::ApplicationModel::Wallet::IWalletBarcode> value) noexcept override
    {
        try
        {
            *value = detach(shim().Barcode());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Barcode(abi_arg_in<Windows::ApplicationModel::Wallet::IWalletBarcode> value) noexcept override
    {
        try
        {
            shim().Barcode(*reinterpret_cast<const Windows::ApplicationModel::Wallet::WalletBarcode *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ExpirationDate(abi_arg_out<Windows::Foundation::IReference<Windows::Foundation::DateTime>> value) noexcept override
    {
        try
        {
            *value = detach(shim().ExpirationDate());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_ExpirationDate(abi_arg_in<Windows::Foundation::IReference<Windows::Foundation::DateTime>> value) noexcept override
    {
        try
        {
            shim().ExpirationDate(*reinterpret_cast<const Windows::Foundation::IReference<Windows::Foundation::DateTime> *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Logo159x159(abi_arg_out<Windows::Storage::Streams::IRandomAccessStreamReference> value) noexcept override
    {
        try
        {
            *value = detach(shim().Logo159x159());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Logo159x159(abi_arg_in<Windows::Storage::Streams::IRandomAccessStreamReference> value) noexcept override
    {
        try
        {
            shim().Logo159x159(*reinterpret_cast<const Windows::Storage::Streams::IRandomAccessStreamReference *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Logo336x336(abi_arg_out<Windows::Storage::Streams::IRandomAccessStreamReference> value) noexcept override
    {
        try
        {
            *value = detach(shim().Logo336x336());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Logo336x336(abi_arg_in<Windows::Storage::Streams::IRandomAccessStreamReference> value) noexcept override
    {
        try
        {
            shim().Logo336x336(*reinterpret_cast<const Windows::Storage::Streams::IRandomAccessStreamReference *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Logo99x99(abi_arg_out<Windows::Storage::Streams::IRandomAccessStreamReference> value) noexcept override
    {
        try
        {
            *value = detach(shim().Logo99x99());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Logo99x99(abi_arg_in<Windows::Storage::Streams::IRandomAccessStreamReference> value) noexcept override
    {
        try
        {
            shim().Logo99x99(*reinterpret_cast<const Windows::Storage::Streams::IRandomAccessStreamReference *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_DisplayMessage(abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            *value = detach(shim().DisplayMessage());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_DisplayMessage(abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            shim().DisplayMessage(*reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_IsDisplayMessageLaunchable(bool * value) noexcept override
    {
        try
        {
            *value = detach(shim().IsDisplayMessageLaunchable());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_IsDisplayMessageLaunchable(bool value) noexcept override
    {
        try
        {
            shim().IsDisplayMessageLaunchable(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_LogoText(abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            *value = detach(shim().LogoText());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_LogoText(abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            shim().LogoText(*reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_HeaderColor(abi_arg_out<Windows::UI::Color> value) noexcept override
    {
        try
        {
            *value = detach(shim().HeaderColor());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_HeaderColor(abi_arg_in<Windows::UI::Color> value) noexcept override
    {
        try
        {
            shim().HeaderColor(*reinterpret_cast<const Windows::UI::Color *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_BodyColor(abi_arg_out<Windows::UI::Color> value) noexcept override
    {
        try
        {
            *value = detach(shim().BodyColor());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_BodyColor(abi_arg_in<Windows::UI::Color> value) noexcept override
    {
        try
        {
            shim().BodyColor(*reinterpret_cast<const Windows::UI::Color *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_HeaderFontColor(abi_arg_out<Windows::UI::Color> value) noexcept override
    {
        try
        {
            *value = detach(shim().HeaderFontColor());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_HeaderFontColor(abi_arg_in<Windows::UI::Color> value) noexcept override
    {
        try
        {
            shim().HeaderFontColor(*reinterpret_cast<const Windows::UI::Color *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_BodyFontColor(abi_arg_out<Windows::UI::Color> value) noexcept override
    {
        try
        {
            *value = detach(shim().BodyFontColor());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_BodyFontColor(abi_arg_in<Windows::UI::Color> value) noexcept override
    {
        try
        {
            shim().BodyFontColor(*reinterpret_cast<const Windows::UI::Color *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_HeaderBackgroundImage(abi_arg_out<Windows::Storage::Streams::IRandomAccessStreamReference> value) noexcept override
    {
        try
        {
            *value = detach(shim().HeaderBackgroundImage());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_HeaderBackgroundImage(abi_arg_in<Windows::Storage::Streams::IRandomAccessStreamReference> value) noexcept override
    {
        try
        {
            shim().HeaderBackgroundImage(*reinterpret_cast<const Windows::Storage::Streams::IRandomAccessStreamReference *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_BodyBackgroundImage(abi_arg_out<Windows::Storage::Streams::IRandomAccessStreamReference> value) noexcept override
    {
        try
        {
            *value = detach(shim().BodyBackgroundImage());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_BodyBackgroundImage(abi_arg_in<Windows::Storage::Streams::IRandomAccessStreamReference> value) noexcept override
    {
        try
        {
            shim().BodyBackgroundImage(*reinterpret_cast<const Windows::Storage::Streams::IRandomAccessStreamReference *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_LogoImage(abi_arg_out<Windows::Storage::Streams::IRandomAccessStreamReference> value) noexcept override
    {
        try
        {
            *value = detach(shim().LogoImage());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_LogoImage(abi_arg_in<Windows::Storage::Streams::IRandomAccessStreamReference> value) noexcept override
    {
        try
        {
            shim().LogoImage(*reinterpret_cast<const Windows::Storage::Streams::IRandomAccessStreamReference *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_PromotionalImage(abi_arg_out<Windows::Storage::Streams::IRandomAccessStreamReference> value) noexcept override
    {
        try
        {
            *value = detach(shim().PromotionalImage());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_PromotionalImage(abi_arg_in<Windows::Storage::Streams::IRandomAccessStreamReference> value) noexcept override
    {
        try
        {
            shim().PromotionalImage(*reinterpret_cast<const Windows::Storage::Streams::IRandomAccessStreamReference *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_RelevantDate(abi_arg_out<Windows::Foundation::IReference<Windows::Foundation::DateTime>> value) noexcept override
    {
        try
        {
            *value = detach(shim().RelevantDate());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_RelevantDate(abi_arg_in<Windows::Foundation::IReference<Windows::Foundation::DateTime>> value) noexcept override
    {
        try
        {
            shim().RelevantDate(*reinterpret_cast<const Windows::Foundation::IReference<Windows::Foundation::DateTime> *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_RelevantDateDisplayMessage(abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            *value = detach(shim().RelevantDateDisplayMessage());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_RelevantDateDisplayMessage(abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            shim().RelevantDateDisplayMessage(*reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_TransactionHistory(abi_arg_out<Windows::Foundation::Collections::IMap<hstring, Windows::ApplicationModel::Wallet::WalletTransaction>> value) noexcept override
    {
        try
        {
            *value = detach(shim().TransactionHistory());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_RelevantLocations(abi_arg_out<Windows::Foundation::Collections::IMap<hstring, Windows::ApplicationModel::Wallet::WalletRelevantLocation>> value) noexcept override
    {
        try
        {
            *value = detach(shim().RelevantLocations());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_IsMoreTransactionHistoryLaunchable(bool * value) noexcept override
    {
        try
        {
            *value = detach(shim().IsMoreTransactionHistoryLaunchable());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_IsMoreTransactionHistoryLaunchable(bool value) noexcept override
    {
        try
        {
            shim().IsMoreTransactionHistoryLaunchable(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_DisplayProperties(abi_arg_out<Windows::Foundation::Collections::IMap<hstring, Windows::ApplicationModel::Wallet::WalletItemCustomProperty>> value) noexcept override
    {
        try
        {
            *value = detach(shim().DisplayProperties());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Verbs(abi_arg_out<Windows::Foundation::Collections::IMap<hstring, Windows::ApplicationModel::Wallet::WalletVerb>> value) noexcept override
    {
        try
        {
            *value = detach(shim().Verbs());
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
struct produce<D, Windows::ApplicationModel::Wallet::IWalletItemCustomProperty> : produce_base<D, Windows::ApplicationModel::Wallet::IWalletItemCustomProperty>
{
    HRESULT __stdcall get_Name(abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            *value = detach(shim().Name());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Name(abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            shim().Name(*reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Value(abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            *value = detach(shim().Value());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Value(abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            shim().Value(*reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_AutoDetectLinks(bool * value) noexcept override
    {
        try
        {
            *value = detach(shim().AutoDetectLinks());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_AutoDetectLinks(bool value) noexcept override
    {
        try
        {
            shim().AutoDetectLinks(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_DetailViewPosition(Windows::ApplicationModel::Wallet::WalletDetailViewPosition * value) noexcept override
    {
        try
        {
            *value = detach(shim().DetailViewPosition());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_DetailViewPosition(Windows::ApplicationModel::Wallet::WalletDetailViewPosition value) noexcept override
    {
        try
        {
            shim().DetailViewPosition(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_SummaryViewPosition(Windows::ApplicationModel::Wallet::WalletSummaryViewPosition * value) noexcept override
    {
        try
        {
            *value = detach(shim().SummaryViewPosition());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_SummaryViewPosition(Windows::ApplicationModel::Wallet::WalletSummaryViewPosition value) noexcept override
    {
        try
        {
            shim().SummaryViewPosition(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::ApplicationModel::Wallet::IWalletItemCustomPropertyFactory> : produce_base<D, Windows::ApplicationModel::Wallet::IWalletItemCustomPropertyFactory>
{
    HRESULT __stdcall abi_CreateWalletItemCustomProperty(abi_arg_in<hstring> name, abi_arg_in<hstring> value, abi_arg_out<Windows::ApplicationModel::Wallet::IWalletItemCustomProperty> walletItemCustomProperty) noexcept override
    {
        try
        {
            *walletItemCustomProperty = detach(shim().CreateWalletItemCustomProperty(*reinterpret_cast<const hstring *>(&name), *reinterpret_cast<const hstring *>(&value)));
            return S_OK;
        }
        catch (...)
        {
            *walletItemCustomProperty = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::ApplicationModel::Wallet::IWalletItemFactory> : produce_base<D, Windows::ApplicationModel::Wallet::IWalletItemFactory>
{
    HRESULT __stdcall abi_CreateWalletItem(Windows::ApplicationModel::Wallet::WalletItemKind kind, abi_arg_in<hstring> displayName, abi_arg_out<Windows::ApplicationModel::Wallet::IWalletItem> walletItem) noexcept override
    {
        try
        {
            *walletItem = detach(shim().CreateWalletItem(kind, *reinterpret_cast<const hstring *>(&displayName)));
            return S_OK;
        }
        catch (...)
        {
            *walletItem = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::ApplicationModel::Wallet::IWalletItemStore> : produce_base<D, Windows::ApplicationModel::Wallet::IWalletItemStore>
{
    HRESULT __stdcall abi_AddAsync(abi_arg_in<hstring> id, abi_arg_in<Windows::ApplicationModel::Wallet::IWalletItem> item, abi_arg_out<Windows::Foundation::IAsyncAction> operation) noexcept override
    {
        try
        {
            *operation = detach(shim().AddAsync(*reinterpret_cast<const hstring *>(&id), *reinterpret_cast<const Windows::ApplicationModel::Wallet::WalletItem *>(&item)));
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_ClearAsync(abi_arg_out<Windows::Foundation::IAsyncAction> operation) noexcept override
    {
        try
        {
            *operation = detach(shim().ClearAsync());
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetWalletItemAsync(abi_arg_in<hstring> id, abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Wallet::WalletItem>> operation) noexcept override
    {
        try
        {
            *operation = detach(shim().GetWalletItemAsync(*reinterpret_cast<const hstring *>(&id)));
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetItemsAsync(abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::ApplicationModel::Wallet::WalletItem>>> operation) noexcept override
    {
        try
        {
            *operation = detach(shim().GetItemsAsync());
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetItemsWithKindAsync(Windows::ApplicationModel::Wallet::WalletItemKind kind, abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::ApplicationModel::Wallet::WalletItem>>> operation) noexcept override
    {
        try
        {
            *operation = detach(shim().GetItemsAsync(kind));
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_ImportItemAsync(abi_arg_in<Windows::Storage::Streams::IRandomAccessStreamReference> stream, abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Wallet::WalletItem>> operation) noexcept override
    {
        try
        {
            *operation = detach(shim().ImportItemAsync(*reinterpret_cast<const Windows::Storage::Streams::IRandomAccessStreamReference *>(&stream)));
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_DeleteAsync(abi_arg_in<hstring> id, abi_arg_out<Windows::Foundation::IAsyncAction> operation) noexcept override
    {
        try
        {
            *operation = detach(shim().DeleteAsync(*reinterpret_cast<const hstring *>(&id)));
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_ShowAsync(abi_arg_out<Windows::Foundation::IAsyncAction> operation) noexcept override
    {
        try
        {
            *operation = detach(shim().ShowAsync());
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_ShowItemAsync(abi_arg_in<hstring> id, abi_arg_out<Windows::Foundation::IAsyncAction> operation) noexcept override
    {
        try
        {
            *operation = detach(shim().ShowAsync(*reinterpret_cast<const hstring *>(&id)));
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_UpdateAsync(abi_arg_in<Windows::ApplicationModel::Wallet::IWalletItem> item, abi_arg_out<Windows::Foundation::IAsyncAction> operation) noexcept override
    {
        try
        {
            *operation = detach(shim().UpdateAsync(*reinterpret_cast<const Windows::ApplicationModel::Wallet::WalletItem *>(&item)));
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
struct produce<D, Windows::ApplicationModel::Wallet::IWalletItemStore2> : produce_base<D, Windows::ApplicationModel::Wallet::IWalletItemStore2>
{
    HRESULT __stdcall add_ItemsChanged(abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Wallet::WalletItemStore, Windows::IInspectable>> handler, event_token * cookie) noexcept override
    {
        try
        {
            *cookie = detach(shim().ItemsChanged(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Wallet::WalletItemStore, Windows::IInspectable> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_ItemsChanged(event_token cookie) noexcept override
    {
        try
        {
            shim().ItemsChanged(cookie);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::ApplicationModel::Wallet::IWalletManagerStatics> : produce_base<D, Windows::ApplicationModel::Wallet::IWalletManagerStatics>
{
    HRESULT __stdcall abi_RequestStoreAsync(abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Wallet::WalletItemStore>> operation) noexcept override
    {
        try
        {
            *operation = detach(shim().RequestStoreAsync());
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
struct produce<D, Windows::ApplicationModel::Wallet::IWalletRelevantLocation> : produce_base<D, Windows::ApplicationModel::Wallet::IWalletRelevantLocation>
{
    HRESULT __stdcall get_Position(abi_arg_out<Windows::Devices::Geolocation::BasicGeoposition> value) noexcept override
    {
        try
        {
            *value = detach(shim().Position());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Position(abi_arg_in<Windows::Devices::Geolocation::BasicGeoposition> value) noexcept override
    {
        try
        {
            shim().Position(*reinterpret_cast<const Windows::Devices::Geolocation::BasicGeoposition *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_DisplayMessage(abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            *value = detach(shim().DisplayMessage());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_DisplayMessage(abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            shim().DisplayMessage(*reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::ApplicationModel::Wallet::IWalletTransaction> : produce_base<D, Windows::ApplicationModel::Wallet::IWalletTransaction>
{
    HRESULT __stdcall get_Description(abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            *value = detach(shim().Description());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Description(abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            shim().Description(*reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_DisplayAmount(abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            *value = detach(shim().DisplayAmount());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_DisplayAmount(abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            shim().DisplayAmount(*reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_IgnoreTimeOfDay(bool * value) noexcept override
    {
        try
        {
            *value = detach(shim().IgnoreTimeOfDay());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_IgnoreTimeOfDay(bool value) noexcept override
    {
        try
        {
            shim().IgnoreTimeOfDay(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_DisplayLocation(abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            *value = detach(shim().DisplayLocation());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_DisplayLocation(abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            shim().DisplayLocation(*reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_TransactionDate(abi_arg_out<Windows::Foundation::IReference<Windows::Foundation::DateTime>> value) noexcept override
    {
        try
        {
            *value = detach(shim().TransactionDate());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_TransactionDate(abi_arg_in<Windows::Foundation::IReference<Windows::Foundation::DateTime>> value) noexcept override
    {
        try
        {
            shim().TransactionDate(*reinterpret_cast<const Windows::Foundation::IReference<Windows::Foundation::DateTime> *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_IsLaunchable(bool * value) noexcept override
    {
        try
        {
            *value = detach(shim().IsLaunchable());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_IsLaunchable(bool value) noexcept override
    {
        try
        {
            shim().IsLaunchable(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::ApplicationModel::Wallet::IWalletVerb> : produce_base<D, Windows::ApplicationModel::Wallet::IWalletVerb>
{
    HRESULT __stdcall get_Name(abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            *value = detach(shim().Name());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Name(abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            shim().Name(*reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::ApplicationModel::Wallet::IWalletVerbFactory> : produce_base<D, Windows::ApplicationModel::Wallet::IWalletVerbFactory>
{
    HRESULT __stdcall abi_CreateWalletVerb(abi_arg_in<hstring> name, abi_arg_out<Windows::ApplicationModel::Wallet::IWalletVerb> WalletVerb) noexcept override
    {
        try
        {
            *WalletVerb = detach(shim().CreateWalletVerb(*reinterpret_cast<const hstring *>(&name)));
            return S_OK;
        }
        catch (...)
        {
            *WalletVerb = nullptr;
            return impl::to_hresult();
        }
    }
};

}

namespace Windows::ApplicationModel::Wallet {

template <typename D> Windows::ApplicationModel::Wallet::WalletBarcodeSymbology impl_IWalletBarcode<D>::Symbology() const
{
    Windows::ApplicationModel::Wallet::WalletBarcodeSymbology value {};
    check_hresult(shim()->get_Symbology(&value));
    return value;
}

template <typename D> hstring impl_IWalletBarcode<D>::Value() const
{
    hstring value;
    check_hresult(shim()->get_Value(put(value)));
    return value;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Storage::Streams::IRandomAccessStreamReference> impl_IWalletBarcode<D>::GetImageAsync() const
{
    Windows::Foundation::IAsyncOperation<Windows::Storage::Streams::IRandomAccessStreamReference> operation;
    check_hresult(shim()->abi_GetImageAsync(put(operation)));
    return operation;
}

template <typename D> hstring impl_IWalletItemCustomProperty<D>::Name() const
{
    hstring value;
    check_hresult(shim()->get_Name(put(value)));
    return value;
}

template <typename D> void impl_IWalletItemCustomProperty<D>::Name(hstring_ref value) const
{
    check_hresult(shim()->put_Name(get(value)));
}

template <typename D> hstring impl_IWalletItemCustomProperty<D>::Value() const
{
    hstring value;
    check_hresult(shim()->get_Value(put(value)));
    return value;
}

template <typename D> void impl_IWalletItemCustomProperty<D>::Value(hstring_ref value) const
{
    check_hresult(shim()->put_Value(get(value)));
}

template <typename D> bool impl_IWalletItemCustomProperty<D>::AutoDetectLinks() const
{
    bool value {};
    check_hresult(shim()->get_AutoDetectLinks(&value));
    return value;
}

template <typename D> void impl_IWalletItemCustomProperty<D>::AutoDetectLinks(bool value) const
{
    check_hresult(shim()->put_AutoDetectLinks(value));
}

template <typename D> Windows::ApplicationModel::Wallet::WalletDetailViewPosition impl_IWalletItemCustomProperty<D>::DetailViewPosition() const
{
    Windows::ApplicationModel::Wallet::WalletDetailViewPosition value {};
    check_hresult(shim()->get_DetailViewPosition(&value));
    return value;
}

template <typename D> void impl_IWalletItemCustomProperty<D>::DetailViewPosition(Windows::ApplicationModel::Wallet::WalletDetailViewPosition value) const
{
    check_hresult(shim()->put_DetailViewPosition(value));
}

template <typename D> Windows::ApplicationModel::Wallet::WalletSummaryViewPosition impl_IWalletItemCustomProperty<D>::SummaryViewPosition() const
{
    Windows::ApplicationModel::Wallet::WalletSummaryViewPosition value {};
    check_hresult(shim()->get_SummaryViewPosition(&value));
    return value;
}

template <typename D> void impl_IWalletItemCustomProperty<D>::SummaryViewPosition(Windows::ApplicationModel::Wallet::WalletSummaryViewPosition value) const
{
    check_hresult(shim()->put_SummaryViewPosition(value));
}

template <typename D> hstring impl_IWalletVerb<D>::Name() const
{
    hstring value;
    check_hresult(shim()->get_Name(put(value)));
    return value;
}

template <typename D> void impl_IWalletVerb<D>::Name(hstring_ref value) const
{
    check_hresult(shim()->put_Name(get(value)));
}

template <typename D> hstring impl_IWalletItem<D>::DisplayName() const
{
    hstring value;
    check_hresult(shim()->get_DisplayName(put(value)));
    return value;
}

template <typename D> void impl_IWalletItem<D>::DisplayName(hstring_ref value) const
{
    check_hresult(shim()->put_DisplayName(get(value)));
}

template <typename D> hstring impl_IWalletItem<D>::Id() const
{
    hstring value;
    check_hresult(shim()->get_Id(put(value)));
    return value;
}

template <typename D> bool impl_IWalletItem<D>::IsAcknowledged() const
{
    bool value {};
    check_hresult(shim()->get_IsAcknowledged(&value));
    return value;
}

template <typename D> void impl_IWalletItem<D>::IsAcknowledged(bool value) const
{
    check_hresult(shim()->put_IsAcknowledged(value));
}

template <typename D> hstring impl_IWalletItem<D>::IssuerDisplayName() const
{
    hstring value;
    check_hresult(shim()->get_IssuerDisplayName(put(value)));
    return value;
}

template <typename D> void impl_IWalletItem<D>::IssuerDisplayName(hstring_ref value) const
{
    check_hresult(shim()->put_IssuerDisplayName(get(value)));
}

template <typename D> Windows::Foundation::IReference<Windows::Foundation::DateTime> impl_IWalletItem<D>::LastUpdated() const
{
    Windows::Foundation::IReference<Windows::Foundation::DateTime> value;
    check_hresult(shim()->get_LastUpdated(put(value)));
    return value;
}

template <typename D> void impl_IWalletItem<D>::LastUpdated(const Windows::Foundation::IReference<Windows::Foundation::DateTime> & value) const
{
    check_hresult(shim()->put_LastUpdated(get(value)));
}

template <typename D> Windows::ApplicationModel::Wallet::WalletItemKind impl_IWalletItem<D>::Kind() const
{
    Windows::ApplicationModel::Wallet::WalletItemKind value {};
    check_hresult(shim()->get_Kind(&value));
    return value;
}

template <typename D> Windows::ApplicationModel::Wallet::WalletBarcode impl_IWalletItem<D>::Barcode() const
{
    Windows::ApplicationModel::Wallet::WalletBarcode value { nullptr };
    check_hresult(shim()->get_Barcode(put(value)));
    return value;
}

template <typename D> void impl_IWalletItem<D>::Barcode(const Windows::ApplicationModel::Wallet::WalletBarcode & value) const
{
    check_hresult(shim()->put_Barcode(get(value)));
}

template <typename D> Windows::Foundation::IReference<Windows::Foundation::DateTime> impl_IWalletItem<D>::ExpirationDate() const
{
    Windows::Foundation::IReference<Windows::Foundation::DateTime> value;
    check_hresult(shim()->get_ExpirationDate(put(value)));
    return value;
}

template <typename D> void impl_IWalletItem<D>::ExpirationDate(const Windows::Foundation::IReference<Windows::Foundation::DateTime> & value) const
{
    check_hresult(shim()->put_ExpirationDate(get(value)));
}

template <typename D> Windows::Storage::Streams::IRandomAccessStreamReference impl_IWalletItem<D>::Logo159x159() const
{
    Windows::Storage::Streams::IRandomAccessStreamReference value;
    check_hresult(shim()->get_Logo159x159(put(value)));
    return value;
}

template <typename D> void impl_IWalletItem<D>::Logo159x159(const Windows::Storage::Streams::IRandomAccessStreamReference & value) const
{
    check_hresult(shim()->put_Logo159x159(get(value)));
}

template <typename D> Windows::Storage::Streams::IRandomAccessStreamReference impl_IWalletItem<D>::Logo336x336() const
{
    Windows::Storage::Streams::IRandomAccessStreamReference value;
    check_hresult(shim()->get_Logo336x336(put(value)));
    return value;
}

template <typename D> void impl_IWalletItem<D>::Logo336x336(const Windows::Storage::Streams::IRandomAccessStreamReference & value) const
{
    check_hresult(shim()->put_Logo336x336(get(value)));
}

template <typename D> Windows::Storage::Streams::IRandomAccessStreamReference impl_IWalletItem<D>::Logo99x99() const
{
    Windows::Storage::Streams::IRandomAccessStreamReference value;
    check_hresult(shim()->get_Logo99x99(put(value)));
    return value;
}

template <typename D> void impl_IWalletItem<D>::Logo99x99(const Windows::Storage::Streams::IRandomAccessStreamReference & value) const
{
    check_hresult(shim()->put_Logo99x99(get(value)));
}

template <typename D> hstring impl_IWalletItem<D>::DisplayMessage() const
{
    hstring value;
    check_hresult(shim()->get_DisplayMessage(put(value)));
    return value;
}

template <typename D> void impl_IWalletItem<D>::DisplayMessage(hstring_ref value) const
{
    check_hresult(shim()->put_DisplayMessage(get(value)));
}

template <typename D> bool impl_IWalletItem<D>::IsDisplayMessageLaunchable() const
{
    bool value {};
    check_hresult(shim()->get_IsDisplayMessageLaunchable(&value));
    return value;
}

template <typename D> void impl_IWalletItem<D>::IsDisplayMessageLaunchable(bool value) const
{
    check_hresult(shim()->put_IsDisplayMessageLaunchable(value));
}

template <typename D> hstring impl_IWalletItem<D>::LogoText() const
{
    hstring value;
    check_hresult(shim()->get_LogoText(put(value)));
    return value;
}

template <typename D> void impl_IWalletItem<D>::LogoText(hstring_ref value) const
{
    check_hresult(shim()->put_LogoText(get(value)));
}

template <typename D> Windows::UI::Color impl_IWalletItem<D>::HeaderColor() const
{
    Windows::UI::Color value {};
    check_hresult(shim()->get_HeaderColor(put(value)));
    return value;
}

template <typename D> void impl_IWalletItem<D>::HeaderColor(const Windows::UI::Color & value) const
{
    check_hresult(shim()->put_HeaderColor(get(value)));
}

template <typename D> Windows::UI::Color impl_IWalletItem<D>::BodyColor() const
{
    Windows::UI::Color value {};
    check_hresult(shim()->get_BodyColor(put(value)));
    return value;
}

template <typename D> void impl_IWalletItem<D>::BodyColor(const Windows::UI::Color & value) const
{
    check_hresult(shim()->put_BodyColor(get(value)));
}

template <typename D> Windows::UI::Color impl_IWalletItem<D>::HeaderFontColor() const
{
    Windows::UI::Color value {};
    check_hresult(shim()->get_HeaderFontColor(put(value)));
    return value;
}

template <typename D> void impl_IWalletItem<D>::HeaderFontColor(const Windows::UI::Color & value) const
{
    check_hresult(shim()->put_HeaderFontColor(get(value)));
}

template <typename D> Windows::UI::Color impl_IWalletItem<D>::BodyFontColor() const
{
    Windows::UI::Color value {};
    check_hresult(shim()->get_BodyFontColor(put(value)));
    return value;
}

template <typename D> void impl_IWalletItem<D>::BodyFontColor(const Windows::UI::Color & value) const
{
    check_hresult(shim()->put_BodyFontColor(get(value)));
}

template <typename D> Windows::Storage::Streams::IRandomAccessStreamReference impl_IWalletItem<D>::HeaderBackgroundImage() const
{
    Windows::Storage::Streams::IRandomAccessStreamReference value;
    check_hresult(shim()->get_HeaderBackgroundImage(put(value)));
    return value;
}

template <typename D> void impl_IWalletItem<D>::HeaderBackgroundImage(const Windows::Storage::Streams::IRandomAccessStreamReference & value) const
{
    check_hresult(shim()->put_HeaderBackgroundImage(get(value)));
}

template <typename D> Windows::Storage::Streams::IRandomAccessStreamReference impl_IWalletItem<D>::BodyBackgroundImage() const
{
    Windows::Storage::Streams::IRandomAccessStreamReference value;
    check_hresult(shim()->get_BodyBackgroundImage(put(value)));
    return value;
}

template <typename D> void impl_IWalletItem<D>::BodyBackgroundImage(const Windows::Storage::Streams::IRandomAccessStreamReference & value) const
{
    check_hresult(shim()->put_BodyBackgroundImage(get(value)));
}

template <typename D> Windows::Storage::Streams::IRandomAccessStreamReference impl_IWalletItem<D>::LogoImage() const
{
    Windows::Storage::Streams::IRandomAccessStreamReference value;
    check_hresult(shim()->get_LogoImage(put(value)));
    return value;
}

template <typename D> void impl_IWalletItem<D>::LogoImage(const Windows::Storage::Streams::IRandomAccessStreamReference & value) const
{
    check_hresult(shim()->put_LogoImage(get(value)));
}

template <typename D> Windows::Storage::Streams::IRandomAccessStreamReference impl_IWalletItem<D>::PromotionalImage() const
{
    Windows::Storage::Streams::IRandomAccessStreamReference value;
    check_hresult(shim()->get_PromotionalImage(put(value)));
    return value;
}

template <typename D> void impl_IWalletItem<D>::PromotionalImage(const Windows::Storage::Streams::IRandomAccessStreamReference & value) const
{
    check_hresult(shim()->put_PromotionalImage(get(value)));
}

template <typename D> Windows::Foundation::IReference<Windows::Foundation::DateTime> impl_IWalletItem<D>::RelevantDate() const
{
    Windows::Foundation::IReference<Windows::Foundation::DateTime> value;
    check_hresult(shim()->get_RelevantDate(put(value)));
    return value;
}

template <typename D> void impl_IWalletItem<D>::RelevantDate(const Windows::Foundation::IReference<Windows::Foundation::DateTime> & value) const
{
    check_hresult(shim()->put_RelevantDate(get(value)));
}

template <typename D> hstring impl_IWalletItem<D>::RelevantDateDisplayMessage() const
{
    hstring value;
    check_hresult(shim()->get_RelevantDateDisplayMessage(put(value)));
    return value;
}

template <typename D> void impl_IWalletItem<D>::RelevantDateDisplayMessage(hstring_ref value) const
{
    check_hresult(shim()->put_RelevantDateDisplayMessage(get(value)));
}

template <typename D> Windows::Foundation::Collections::IMap<hstring, Windows::ApplicationModel::Wallet::WalletTransaction> impl_IWalletItem<D>::TransactionHistory() const
{
    Windows::Foundation::Collections::IMap<hstring, Windows::ApplicationModel::Wallet::WalletTransaction> value;
    check_hresult(shim()->get_TransactionHistory(put(value)));
    return value;
}

template <typename D> Windows::Foundation::Collections::IMap<hstring, Windows::ApplicationModel::Wallet::WalletRelevantLocation> impl_IWalletItem<D>::RelevantLocations() const
{
    Windows::Foundation::Collections::IMap<hstring, Windows::ApplicationModel::Wallet::WalletRelevantLocation> value;
    check_hresult(shim()->get_RelevantLocations(put(value)));
    return value;
}

template <typename D> bool impl_IWalletItem<D>::IsMoreTransactionHistoryLaunchable() const
{
    bool value {};
    check_hresult(shim()->get_IsMoreTransactionHistoryLaunchable(&value));
    return value;
}

template <typename D> void impl_IWalletItem<D>::IsMoreTransactionHistoryLaunchable(bool value) const
{
    check_hresult(shim()->put_IsMoreTransactionHistoryLaunchable(value));
}

template <typename D> Windows::Foundation::Collections::IMap<hstring, Windows::ApplicationModel::Wallet::WalletItemCustomProperty> impl_IWalletItem<D>::DisplayProperties() const
{
    Windows::Foundation::Collections::IMap<hstring, Windows::ApplicationModel::Wallet::WalletItemCustomProperty> value;
    check_hresult(shim()->get_DisplayProperties(put(value)));
    return value;
}

template <typename D> Windows::Foundation::Collections::IMap<hstring, Windows::ApplicationModel::Wallet::WalletVerb> impl_IWalletItem<D>::Verbs() const
{
    Windows::Foundation::Collections::IMap<hstring, Windows::ApplicationModel::Wallet::WalletVerb> value;
    check_hresult(shim()->get_Verbs(put(value)));
    return value;
}

template <typename D> hstring impl_IWalletTransaction<D>::Description() const
{
    hstring value;
    check_hresult(shim()->get_Description(put(value)));
    return value;
}

template <typename D> void impl_IWalletTransaction<D>::Description(hstring_ref value) const
{
    check_hresult(shim()->put_Description(get(value)));
}

template <typename D> hstring impl_IWalletTransaction<D>::DisplayAmount() const
{
    hstring value;
    check_hresult(shim()->get_DisplayAmount(put(value)));
    return value;
}

template <typename D> void impl_IWalletTransaction<D>::DisplayAmount(hstring_ref value) const
{
    check_hresult(shim()->put_DisplayAmount(get(value)));
}

template <typename D> bool impl_IWalletTransaction<D>::IgnoreTimeOfDay() const
{
    bool value {};
    check_hresult(shim()->get_IgnoreTimeOfDay(&value));
    return value;
}

template <typename D> void impl_IWalletTransaction<D>::IgnoreTimeOfDay(bool value) const
{
    check_hresult(shim()->put_IgnoreTimeOfDay(value));
}

template <typename D> hstring impl_IWalletTransaction<D>::DisplayLocation() const
{
    hstring value;
    check_hresult(shim()->get_DisplayLocation(put(value)));
    return value;
}

template <typename D> void impl_IWalletTransaction<D>::DisplayLocation(hstring_ref value) const
{
    check_hresult(shim()->put_DisplayLocation(get(value)));
}

template <typename D> Windows::Foundation::IReference<Windows::Foundation::DateTime> impl_IWalletTransaction<D>::TransactionDate() const
{
    Windows::Foundation::IReference<Windows::Foundation::DateTime> value;
    check_hresult(shim()->get_TransactionDate(put(value)));
    return value;
}

template <typename D> void impl_IWalletTransaction<D>::TransactionDate(const Windows::Foundation::IReference<Windows::Foundation::DateTime> & value) const
{
    check_hresult(shim()->put_TransactionDate(get(value)));
}

template <typename D> bool impl_IWalletTransaction<D>::IsLaunchable() const
{
    bool value {};
    check_hresult(shim()->get_IsLaunchable(&value));
    return value;
}

template <typename D> void impl_IWalletTransaction<D>::IsLaunchable(bool value) const
{
    check_hresult(shim()->put_IsLaunchable(value));
}

template <typename D> Windows::Devices::Geolocation::BasicGeoposition impl_IWalletRelevantLocation<D>::Position() const
{
    Windows::Devices::Geolocation::BasicGeoposition value {};
    check_hresult(shim()->get_Position(put(value)));
    return value;
}

template <typename D> void impl_IWalletRelevantLocation<D>::Position(const Windows::Devices::Geolocation::BasicGeoposition & value) const
{
    check_hresult(shim()->put_Position(get(value)));
}

template <typename D> hstring impl_IWalletRelevantLocation<D>::DisplayMessage() const
{
    hstring value;
    check_hresult(shim()->get_DisplayMessage(put(value)));
    return value;
}

template <typename D> void impl_IWalletRelevantLocation<D>::DisplayMessage(hstring_ref value) const
{
    check_hresult(shim()->put_DisplayMessage(get(value)));
}

template <typename D> Windows::Foundation::IAsyncAction impl_IWalletItemStore<D>::AddAsync(hstring_ref id, const Windows::ApplicationModel::Wallet::WalletItem & item) const
{
    Windows::Foundation::IAsyncAction operation;
    check_hresult(shim()->abi_AddAsync(get(id), get(item), put(operation)));
    return operation;
}

template <typename D> Windows::Foundation::IAsyncAction impl_IWalletItemStore<D>::ClearAsync() const
{
    Windows::Foundation::IAsyncAction operation;
    check_hresult(shim()->abi_ClearAsync(put(operation)));
    return operation;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Wallet::WalletItem> impl_IWalletItemStore<D>::GetWalletItemAsync(hstring_ref id) const
{
    Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Wallet::WalletItem> operation;
    check_hresult(shim()->abi_GetWalletItemAsync(get(id), put(operation)));
    return operation;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::ApplicationModel::Wallet::WalletItem>> impl_IWalletItemStore<D>::GetItemsAsync() const
{
    Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::ApplicationModel::Wallet::WalletItem>> operation;
    check_hresult(shim()->abi_GetItemsAsync(put(operation)));
    return operation;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::ApplicationModel::Wallet::WalletItem>> impl_IWalletItemStore<D>::GetItemsAsync(Windows::ApplicationModel::Wallet::WalletItemKind kind) const
{
    Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::ApplicationModel::Wallet::WalletItem>> operation;
    check_hresult(shim()->abi_GetItemsWithKindAsync(kind, put(operation)));
    return operation;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Wallet::WalletItem> impl_IWalletItemStore<D>::ImportItemAsync(const Windows::Storage::Streams::IRandomAccessStreamReference & stream) const
{
    Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Wallet::WalletItem> operation;
    check_hresult(shim()->abi_ImportItemAsync(get(stream), put(operation)));
    return operation;
}

template <typename D> Windows::Foundation::IAsyncAction impl_IWalletItemStore<D>::DeleteAsync(hstring_ref id) const
{
    Windows::Foundation::IAsyncAction operation;
    check_hresult(shim()->abi_DeleteAsync(get(id), put(operation)));
    return operation;
}

template <typename D> Windows::Foundation::IAsyncAction impl_IWalletItemStore<D>::ShowAsync() const
{
    Windows::Foundation::IAsyncAction operation;
    check_hresult(shim()->abi_ShowAsync(put(operation)));
    return operation;
}

template <typename D> Windows::Foundation::IAsyncAction impl_IWalletItemStore<D>::ShowAsync(hstring_ref id) const
{
    Windows::Foundation::IAsyncAction operation;
    check_hresult(shim()->abi_ShowItemAsync(get(id), put(operation)));
    return operation;
}

template <typename D> Windows::Foundation::IAsyncAction impl_IWalletItemStore<D>::UpdateAsync(const Windows::ApplicationModel::Wallet::WalletItem & item) const
{
    Windows::Foundation::IAsyncAction operation;
    check_hresult(shim()->abi_UpdateAsync(get(item), put(operation)));
    return operation;
}

template <typename D> event_token impl_IWalletItemStore2<D>::ItemsChanged(const Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Wallet::WalletItemStore, Windows::IInspectable> & handler) const
{
    event_token cookie {};
    check_hresult(shim()->add_ItemsChanged(get(handler), &cookie));
    return cookie;
}

template <typename D> event_revoker<IWalletItemStore2> impl_IWalletItemStore2<D>::ItemsChanged(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Wallet::WalletItemStore, Windows::IInspectable> & handler) const
{
    return impl::make_event_revoker<D, IWalletItemStore2>(this, &ABI::Windows::ApplicationModel::Wallet::IWalletItemStore2::remove_ItemsChanged, ItemsChanged(handler));
}

template <typename D> void impl_IWalletItemStore2<D>::ItemsChanged(event_token cookie) const
{
    check_hresult(shim()->remove_ItemsChanged(cookie));
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Wallet::WalletItemStore> impl_IWalletManagerStatics<D>::RequestStoreAsync() const
{
    Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Wallet::WalletItemStore> operation;
    check_hresult(shim()->abi_RequestStoreAsync(put(operation)));
    return operation;
}

template <typename D> Windows::ApplicationModel::Wallet::WalletItemCustomProperty impl_IWalletItemCustomPropertyFactory<D>::CreateWalletItemCustomProperty(hstring_ref name, hstring_ref value) const
{
    Windows::ApplicationModel::Wallet::WalletItemCustomProperty walletItemCustomProperty { nullptr };
    check_hresult(shim()->abi_CreateWalletItemCustomProperty(get(name), get(value), put(walletItemCustomProperty)));
    return walletItemCustomProperty;
}

template <typename D> Windows::ApplicationModel::Wallet::WalletVerb impl_IWalletVerbFactory<D>::CreateWalletVerb(hstring_ref name) const
{
    Windows::ApplicationModel::Wallet::WalletVerb WalletVerb { nullptr };
    check_hresult(shim()->abi_CreateWalletVerb(get(name), put(WalletVerb)));
    return WalletVerb;
}

template <typename D> Windows::ApplicationModel::Wallet::WalletItem impl_IWalletItemFactory<D>::CreateWalletItem(Windows::ApplicationModel::Wallet::WalletItemKind kind, hstring_ref displayName) const
{
    Windows::ApplicationModel::Wallet::WalletItem walletItem { nullptr };
    check_hresult(shim()->abi_CreateWalletItem(kind, get(displayName), put(walletItem)));
    return walletItem;
}

template <typename D> Windows::ApplicationModel::Wallet::WalletBarcode impl_IWalletBarcodeFactory<D>::CreateWalletBarcode(Windows::ApplicationModel::Wallet::WalletBarcodeSymbology symbology, hstring_ref value) const
{
    Windows::ApplicationModel::Wallet::WalletBarcode barcode { nullptr };
    check_hresult(shim()->abi_CreateWalletBarcode(symbology, get(value), put(barcode)));
    return barcode;
}

template <typename D> Windows::ApplicationModel::Wallet::WalletBarcode impl_IWalletBarcodeFactory<D>::CreateCustomWalletBarcode(const Windows::Storage::Streams::IRandomAccessStreamReference & streamToBarcodeImage) const
{
    Windows::ApplicationModel::Wallet::WalletBarcode barcode { nullptr };
    check_hresult(shim()->abi_CreateCustomWalletBarcode(get(streamToBarcodeImage), put(barcode)));
    return barcode;
}

inline WalletBarcode::WalletBarcode(Windows::ApplicationModel::Wallet::WalletBarcodeSymbology symbology, hstring_ref value) :
    WalletBarcode(GetActivationFactory<WalletBarcode, IWalletBarcodeFactory>().CreateWalletBarcode(symbology, value))
{}

inline WalletBarcode::WalletBarcode(const Windows::Storage::Streams::IRandomAccessStreamReference & streamToBarcodeImage) :
    WalletBarcode(GetActivationFactory<WalletBarcode, IWalletBarcodeFactory>().CreateCustomWalletBarcode(streamToBarcodeImage))
{}

inline WalletItem::WalletItem(Windows::ApplicationModel::Wallet::WalletItemKind kind, hstring_ref displayName) :
    WalletItem(GetActivationFactory<WalletItem, IWalletItemFactory>().CreateWalletItem(kind, displayName))
{}

inline WalletItemCustomProperty::WalletItemCustomProperty(hstring_ref name, hstring_ref value) :
    WalletItemCustomProperty(GetActivationFactory<WalletItemCustomProperty, IWalletItemCustomPropertyFactory>().CreateWalletItemCustomProperty(name, value))
{}

inline Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Wallet::WalletItemStore> WalletManager::RequestStoreAsync()
{
    return GetActivationFactory<WalletManager, IWalletManagerStatics>().RequestStoreAsync();
}

inline WalletRelevantLocation::WalletRelevantLocation() :
    WalletRelevantLocation(ActivateInstance<WalletRelevantLocation>())
{}

inline WalletTransaction::WalletTransaction() :
    WalletTransaction(ActivateInstance<WalletTransaction>())
{}

inline WalletVerb::WalletVerb(hstring_ref name) :
    WalletVerb(GetActivationFactory<WalletVerb, IWalletVerbFactory>().CreateWalletVerb(name))
{}

}

}
