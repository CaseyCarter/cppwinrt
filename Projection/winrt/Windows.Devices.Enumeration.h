// C++ for the Windows Runtime v1.29
// Copyright (c) 2016 Microsoft Corporation

#pragma once

#include "internal\Windows.UI.class.h"
#include "internal\Windows.Foundation.Collections.class.h"
#include "internal\Windows.Foundation.class.h"
#include "internal\Windows.UI.Popups.class.h"
#include "internal\Windows.ApplicationModel.Background.class.h"
#include "internal\Windows.Devices.Enumeration.class.h"
#include "Windows.Devices.h"
#include "Windows.Foundation.Collections.h"
#include "Windows.Storage.Streams.h"

WINRT_EXPORT namespace winrt {

namespace impl {

template <typename D>
struct produce<D, Windows::Devices::Enumeration::IDeviceAccessChangedEventArgs> : produce_base<D, Windows::Devices::Enumeration::IDeviceAccessChangedEventArgs>
{
    HRESULT __stdcall get_Status(Windows::Devices::Enumeration::DeviceAccessStatus * value) noexcept override
    {
        try
        {
            *value = detach(shim().Status());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Devices::Enumeration::IDeviceAccessChangedEventArgs2> : produce_base<D, Windows::Devices::Enumeration::IDeviceAccessChangedEventArgs2>
{
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
};

template <typename D>
struct produce<D, Windows::Devices::Enumeration::IDeviceAccessInformation> : produce_base<D, Windows::Devices::Enumeration::IDeviceAccessInformation>
{
    HRESULT __stdcall add_AccessChanged(abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::Devices::Enumeration::DeviceAccessInformation, Windows::Devices::Enumeration::DeviceAccessChangedEventArgs>> handler, event_token * cookie) noexcept override
    {
        try
        {
            *cookie = detach(shim().AccessChanged(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::Devices::Enumeration::DeviceAccessInformation, Windows::Devices::Enumeration::DeviceAccessChangedEventArgs> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_AccessChanged(event_token cookie) noexcept override
    {
        try
        {
            shim().AccessChanged(cookie);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_CurrentStatus(Windows::Devices::Enumeration::DeviceAccessStatus * status) noexcept override
    {
        try
        {
            *status = detach(shim().CurrentStatus());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Devices::Enumeration::IDeviceAccessInformationStatics> : produce_base<D, Windows::Devices::Enumeration::IDeviceAccessInformationStatics>
{
    HRESULT __stdcall abi_CreateFromId(abi_arg_in<hstring> deviceId, abi_arg_out<Windows::Devices::Enumeration::IDeviceAccessInformation> value) noexcept override
    {
        try
        {
            *value = detach(shim().CreateFromId(*reinterpret_cast<const hstring *>(&deviceId)));
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_CreateFromDeviceClassId(GUID deviceClassId, abi_arg_out<Windows::Devices::Enumeration::IDeviceAccessInformation> value) noexcept override
    {
        try
        {
            *value = detach(shim().CreateFromDeviceClassId(deviceClassId));
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_CreateFromDeviceClass(Windows::Devices::Enumeration::DeviceClass deviceClass, abi_arg_out<Windows::Devices::Enumeration::IDeviceAccessInformation> value) noexcept override
    {
        try
        {
            *value = detach(shim().CreateFromDeviceClass(deviceClass));
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
struct produce<D, Windows::Devices::Enumeration::IDeviceConnectionChangeTriggerDetails> : produce_base<D, Windows::Devices::Enumeration::IDeviceConnectionChangeTriggerDetails>
{
    HRESULT __stdcall get_DeviceId(abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            *value = detach(shim().DeviceId());
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
struct produce<D, Windows::Devices::Enumeration::IDeviceDisconnectButtonClickedEventArgs> : produce_base<D, Windows::Devices::Enumeration::IDeviceDisconnectButtonClickedEventArgs>
{
    HRESULT __stdcall get_Device(abi_arg_out<Windows::Devices::Enumeration::IDeviceInformation> value) noexcept override
    {
        try
        {
            *value = detach(shim().Device());
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
struct produce<D, Windows::Devices::Enumeration::IDeviceInformation> : produce_base<D, Windows::Devices::Enumeration::IDeviceInformation>
{
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

    HRESULT __stdcall get_IsEnabled(bool * value) noexcept override
    {
        try
        {
            *value = detach(shim().IsEnabled());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_IsDefault(bool * value) noexcept override
    {
        try
        {
            *value = detach(shim().IsDefault());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_EnclosureLocation(abi_arg_out<Windows::Devices::Enumeration::IEnclosureLocation> value) noexcept override
    {
        try
        {
            *value = detach(shim().EnclosureLocation());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Properties(abi_arg_out<Windows::Foundation::Collections::IMapView<hstring, Windows::IInspectable>> value) noexcept override
    {
        try
        {
            *value = detach(shim().Properties());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_Update(abi_arg_in<Windows::Devices::Enumeration::IDeviceInformationUpdate> updateInfo) noexcept override
    {
        try
        {
            shim().Update(*reinterpret_cast<const Windows::Devices::Enumeration::DeviceInformationUpdate *>(&updateInfo));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetThumbnailAsync(abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Devices::Enumeration::DeviceThumbnail>> asyncOp) noexcept override
    {
        try
        {
            *asyncOp = detach(shim().GetThumbnailAsync());
            return S_OK;
        }
        catch (...)
        {
            *asyncOp = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetGlyphThumbnailAsync(abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Devices::Enumeration::DeviceThumbnail>> asyncOp) noexcept override
    {
        try
        {
            *asyncOp = detach(shim().GetGlyphThumbnailAsync());
            return S_OK;
        }
        catch (...)
        {
            *asyncOp = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Devices::Enumeration::IDeviceInformation2> : produce_base<D, Windows::Devices::Enumeration::IDeviceInformation2>
{
    HRESULT __stdcall get_Kind(Windows::Devices::Enumeration::DeviceInformationKind * value) noexcept override
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

    HRESULT __stdcall get_Pairing(abi_arg_out<Windows::Devices::Enumeration::IDeviceInformationPairing> value) noexcept override
    {
        try
        {
            *value = detach(shim().Pairing());
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
struct produce<D, Windows::Devices::Enumeration::IDeviceInformationCustomPairing> : produce_base<D, Windows::Devices::Enumeration::IDeviceInformationCustomPairing>
{
    HRESULT __stdcall abi_PairAsync(Windows::Devices::Enumeration::DevicePairingKinds pairingKindsSupported, abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Devices::Enumeration::DevicePairingResult>> result) noexcept override
    {
        try
        {
            *result = detach(shim().PairAsync(pairingKindsSupported));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_PairWithProtectionLevelAsync(Windows::Devices::Enumeration::DevicePairingKinds pairingKindsSupported, Windows::Devices::Enumeration::DevicePairingProtectionLevel minProtectionLevel, abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Devices::Enumeration::DevicePairingResult>> result) noexcept override
    {
        try
        {
            *result = detach(shim().PairAsync(pairingKindsSupported, minProtectionLevel));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_PairWithProtectionLevelAndSettingsAsync(Windows::Devices::Enumeration::DevicePairingKinds pairingKindsSupported, Windows::Devices::Enumeration::DevicePairingProtectionLevel minProtectionLevel, abi_arg_in<Windows::Devices::Enumeration::IDevicePairingSettings> devicePairingSettings, abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Devices::Enumeration::DevicePairingResult>> result) noexcept override
    {
        try
        {
            *result = detach(shim().PairAsync(pairingKindsSupported, minProtectionLevel, *reinterpret_cast<const Windows::Devices::Enumeration::IDevicePairingSettings *>(&devicePairingSettings)));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_PairingRequested(abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::Devices::Enumeration::DeviceInformationCustomPairing, Windows::Devices::Enumeration::DevicePairingRequestedEventArgs>> handler, event_token * token) noexcept override
    {
        try
        {
            *token = detach(shim().PairingRequested(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::Devices::Enumeration::DeviceInformationCustomPairing, Windows::Devices::Enumeration::DevicePairingRequestedEventArgs> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_PairingRequested(event_token token) noexcept override
    {
        try
        {
            shim().PairingRequested(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Devices::Enumeration::IDeviceInformationPairing> : produce_base<D, Windows::Devices::Enumeration::IDeviceInformationPairing>
{
    HRESULT __stdcall get_IsPaired(bool * value) noexcept override
    {
        try
        {
            *value = detach(shim().IsPaired());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_CanPair(bool * value) noexcept override
    {
        try
        {
            *value = detach(shim().CanPair());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_PairAsync(abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Devices::Enumeration::DevicePairingResult>> result) noexcept override
    {
        try
        {
            *result = detach(shim().PairAsync());
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_PairWithProtectionLevelAsync(Windows::Devices::Enumeration::DevicePairingProtectionLevel minProtectionLevel, abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Devices::Enumeration::DevicePairingResult>> result) noexcept override
    {
        try
        {
            *result = detach(shim().PairAsync(minProtectionLevel));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Devices::Enumeration::IDeviceInformationPairing2> : produce_base<D, Windows::Devices::Enumeration::IDeviceInformationPairing2>
{
    HRESULT __stdcall get_ProtectionLevel(Windows::Devices::Enumeration::DevicePairingProtectionLevel * value) noexcept override
    {
        try
        {
            *value = detach(shim().ProtectionLevel());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Custom(abi_arg_out<Windows::Devices::Enumeration::IDeviceInformationCustomPairing> value) noexcept override
    {
        try
        {
            *value = detach(shim().Custom());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_PairWithProtectionLevelAndSettingsAsync(Windows::Devices::Enumeration::DevicePairingProtectionLevel minProtectionLevel, abi_arg_in<Windows::Devices::Enumeration::IDevicePairingSettings> devicePairingSettings, abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Devices::Enumeration::DevicePairingResult>> result) noexcept override
    {
        try
        {
            *result = detach(shim().PairAsync(minProtectionLevel, *reinterpret_cast<const Windows::Devices::Enumeration::IDevicePairingSettings *>(&devicePairingSettings)));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_UnpairAsync(abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Devices::Enumeration::DeviceUnpairingResult>> result) noexcept override
    {
        try
        {
            *result = detach(shim().UnpairAsync());
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Devices::Enumeration::IDeviceInformationPairingStatics> : produce_base<D, Windows::Devices::Enumeration::IDeviceInformationPairingStatics>
{
    HRESULT __stdcall abi_TryRegisterForAllInboundPairingRequests(Windows::Devices::Enumeration::DevicePairingKinds pairingKindsSupported, bool * result) noexcept override
    {
        try
        {
            *result = detach(shim().TryRegisterForAllInboundPairingRequests(pairingKindsSupported));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Devices::Enumeration::IDeviceInformationStatics> : produce_base<D, Windows::Devices::Enumeration::IDeviceInformationStatics>
{
    HRESULT __stdcall abi_CreateFromIdAsync(abi_arg_in<hstring> deviceId, abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Devices::Enumeration::DeviceInformation>> asyncOp) noexcept override
    {
        try
        {
            *asyncOp = detach(shim().CreateFromIdAsync(*reinterpret_cast<const hstring *>(&deviceId)));
            return S_OK;
        }
        catch (...)
        {
            *asyncOp = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_CreateFromIdAsyncAdditionalProperties(abi_arg_in<hstring> deviceId, abi_arg_in<Windows::Foundation::Collections::IIterable<hstring>> additionalProperties, abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Devices::Enumeration::DeviceInformation>> asyncOp) noexcept override
    {
        try
        {
            *asyncOp = detach(shim().CreateFromIdAsync(*reinterpret_cast<const hstring *>(&deviceId), *reinterpret_cast<const Windows::Foundation::Collections::IIterable<hstring> *>(&additionalProperties)));
            return S_OK;
        }
        catch (...)
        {
            *asyncOp = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_FindAllAsync(abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Devices::Enumeration::DeviceInformationCollection>> asyncOp) noexcept override
    {
        try
        {
            *asyncOp = detach(shim().FindAllAsync());
            return S_OK;
        }
        catch (...)
        {
            *asyncOp = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_FindAllAsyncDeviceClass(Windows::Devices::Enumeration::DeviceClass deviceClass, abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Devices::Enumeration::DeviceInformationCollection>> asyncOp) noexcept override
    {
        try
        {
            *asyncOp = detach(shim().FindAllAsync(deviceClass));
            return S_OK;
        }
        catch (...)
        {
            *asyncOp = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_FindAllAsyncAqsFilter(abi_arg_in<hstring> aqsFilter, abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Devices::Enumeration::DeviceInformationCollection>> asyncOp) noexcept override
    {
        try
        {
            *asyncOp = detach(shim().FindAllAsync(*reinterpret_cast<const hstring *>(&aqsFilter)));
            return S_OK;
        }
        catch (...)
        {
            *asyncOp = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_FindAllAsyncAqsFilterAndAdditionalProperties(abi_arg_in<hstring> aqsFilter, abi_arg_in<Windows::Foundation::Collections::IIterable<hstring>> additionalProperties, abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Devices::Enumeration::DeviceInformationCollection>> asyncOp) noexcept override
    {
        try
        {
            *asyncOp = detach(shim().FindAllAsync(*reinterpret_cast<const hstring *>(&aqsFilter), *reinterpret_cast<const Windows::Foundation::Collections::IIterable<hstring> *>(&additionalProperties)));
            return S_OK;
        }
        catch (...)
        {
            *asyncOp = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_CreateWatcher(abi_arg_out<Windows::Devices::Enumeration::IDeviceWatcher> watcher) noexcept override
    {
        try
        {
            *watcher = detach(shim().CreateWatcher());
            return S_OK;
        }
        catch (...)
        {
            *watcher = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_CreateWatcherDeviceClass(Windows::Devices::Enumeration::DeviceClass deviceClass, abi_arg_out<Windows::Devices::Enumeration::IDeviceWatcher> watcher) noexcept override
    {
        try
        {
            *watcher = detach(shim().CreateWatcher(deviceClass));
            return S_OK;
        }
        catch (...)
        {
            *watcher = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_CreateWatcherAqsFilter(abi_arg_in<hstring> aqsFilter, abi_arg_out<Windows::Devices::Enumeration::IDeviceWatcher> watcher) noexcept override
    {
        try
        {
            *watcher = detach(shim().CreateWatcher(*reinterpret_cast<const hstring *>(&aqsFilter)));
            return S_OK;
        }
        catch (...)
        {
            *watcher = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_CreateWatcherAqsFilterAndAdditionalProperties(abi_arg_in<hstring> aqsFilter, abi_arg_in<Windows::Foundation::Collections::IIterable<hstring>> additionalProperties, abi_arg_out<Windows::Devices::Enumeration::IDeviceWatcher> watcher) noexcept override
    {
        try
        {
            *watcher = detach(shim().CreateWatcher(*reinterpret_cast<const hstring *>(&aqsFilter), *reinterpret_cast<const Windows::Foundation::Collections::IIterable<hstring> *>(&additionalProperties)));
            return S_OK;
        }
        catch (...)
        {
            *watcher = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Devices::Enumeration::IDeviceInformationStatics2> : produce_base<D, Windows::Devices::Enumeration::IDeviceInformationStatics2>
{
    HRESULT __stdcall abi_GetAqsFilterFromDeviceClass(Windows::Devices::Enumeration::DeviceClass deviceClass, abi_arg_out<hstring> aqsFilter) noexcept override
    {
        try
        {
            *aqsFilter = detach(shim().GetAqsFilterFromDeviceClass(deviceClass));
            return S_OK;
        }
        catch (...)
        {
            *aqsFilter = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_CreateFromIdAsyncWithKindAndAdditionalProperties(abi_arg_in<hstring> deviceId, abi_arg_in<Windows::Foundation::Collections::IIterable<hstring>> additionalProperties, Windows::Devices::Enumeration::DeviceInformationKind kind, abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Devices::Enumeration::DeviceInformation>> asyncOp) noexcept override
    {
        try
        {
            *asyncOp = detach(shim().CreateFromIdAsync(*reinterpret_cast<const hstring *>(&deviceId), *reinterpret_cast<const Windows::Foundation::Collections::IIterable<hstring> *>(&additionalProperties), kind));
            return S_OK;
        }
        catch (...)
        {
            *asyncOp = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_FindAllAsyncWithKindAqsFilterAndAdditionalProperties(abi_arg_in<hstring> aqsFilter, abi_arg_in<Windows::Foundation::Collections::IIterable<hstring>> additionalProperties, Windows::Devices::Enumeration::DeviceInformationKind kind, abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Devices::Enumeration::DeviceInformationCollection>> asyncOp) noexcept override
    {
        try
        {
            *asyncOp = detach(shim().FindAllAsync(*reinterpret_cast<const hstring *>(&aqsFilter), *reinterpret_cast<const Windows::Foundation::Collections::IIterable<hstring> *>(&additionalProperties), kind));
            return S_OK;
        }
        catch (...)
        {
            *asyncOp = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_CreateWatcherWithKindAqsFilterAndAdditionalProperties(abi_arg_in<hstring> aqsFilter, abi_arg_in<Windows::Foundation::Collections::IIterable<hstring>> additionalProperties, Windows::Devices::Enumeration::DeviceInformationKind kind, abi_arg_out<Windows::Devices::Enumeration::IDeviceWatcher> watcher) noexcept override
    {
        try
        {
            *watcher = detach(shim().CreateWatcher(*reinterpret_cast<const hstring *>(&aqsFilter), *reinterpret_cast<const Windows::Foundation::Collections::IIterable<hstring> *>(&additionalProperties), kind));
            return S_OK;
        }
        catch (...)
        {
            *watcher = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Devices::Enumeration::IDeviceInformationUpdate> : produce_base<D, Windows::Devices::Enumeration::IDeviceInformationUpdate>
{
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

    HRESULT __stdcall get_Properties(abi_arg_out<Windows::Foundation::Collections::IMapView<hstring, Windows::IInspectable>> value) noexcept override
    {
        try
        {
            *value = detach(shim().Properties());
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
struct produce<D, Windows::Devices::Enumeration::IDeviceInformationUpdate2> : produce_base<D, Windows::Devices::Enumeration::IDeviceInformationUpdate2>
{
    HRESULT __stdcall get_Kind(Windows::Devices::Enumeration::DeviceInformationKind * value) noexcept override
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
};

template <typename D>
struct produce<D, Windows::Devices::Enumeration::IDevicePairingRequestedEventArgs> : produce_base<D, Windows::Devices::Enumeration::IDevicePairingRequestedEventArgs>
{
    HRESULT __stdcall get_DeviceInformation(abi_arg_out<Windows::Devices::Enumeration::IDeviceInformation> value) noexcept override
    {
        try
        {
            *value = detach(shim().DeviceInformation());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_PairingKind(Windows::Devices::Enumeration::DevicePairingKinds * value) noexcept override
    {
        try
        {
            *value = detach(shim().PairingKind());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Pin(abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            *value = detach(shim().Pin());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_Accept() noexcept override
    {
        try
        {
            shim().Accept();
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_AcceptWithPin(abi_arg_in<hstring> pin) noexcept override
    {
        try
        {
            shim().Accept(*reinterpret_cast<const hstring *>(&pin));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetDeferral(abi_arg_out<Windows::Foundation::IDeferral> result) noexcept override
    {
        try
        {
            *result = detach(shim().GetDeferral());
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Devices::Enumeration::IDevicePairingResult> : produce_base<D, Windows::Devices::Enumeration::IDevicePairingResult>
{
    HRESULT __stdcall get_Status(Windows::Devices::Enumeration::DevicePairingResultStatus * status) noexcept override
    {
        try
        {
            *status = detach(shim().Status());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ProtectionLevelUsed(Windows::Devices::Enumeration::DevicePairingProtectionLevel * value) noexcept override
    {
        try
        {
            *value = detach(shim().ProtectionLevelUsed());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Devices::Enumeration::IDevicePairingSettings> : produce_base<D, Windows::Devices::Enumeration::IDevicePairingSettings>
{};

template <typename D>
struct produce<D, Windows::Devices::Enumeration::IDevicePicker> : produce_base<D, Windows::Devices::Enumeration::IDevicePicker>
{
    HRESULT __stdcall get_Filter(abi_arg_out<Windows::Devices::Enumeration::IDevicePickerFilter> filter) noexcept override
    {
        try
        {
            *filter = detach(shim().Filter());
            return S_OK;
        }
        catch (...)
        {
            *filter = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Appearance(abi_arg_out<Windows::Devices::Enumeration::IDevicePickerAppearance> value) noexcept override
    {
        try
        {
            *value = detach(shim().Appearance());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_RequestedProperties(abi_arg_out<Windows::Foundation::Collections::IVector<hstring>> value) noexcept override
    {
        try
        {
            *value = detach(shim().RequestedProperties());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_DeviceSelected(abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::Devices::Enumeration::DevicePicker, Windows::Devices::Enumeration::DeviceSelectedEventArgs>> handler, event_token * token) noexcept override
    {
        try
        {
            *token = detach(shim().DeviceSelected(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::Devices::Enumeration::DevicePicker, Windows::Devices::Enumeration::DeviceSelectedEventArgs> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_DeviceSelected(event_token token) noexcept override
    {
        try
        {
            shim().DeviceSelected(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_DisconnectButtonClicked(abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::Devices::Enumeration::DevicePicker, Windows::Devices::Enumeration::DeviceDisconnectButtonClickedEventArgs>> handler, event_token * token) noexcept override
    {
        try
        {
            *token = detach(shim().DisconnectButtonClicked(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::Devices::Enumeration::DevicePicker, Windows::Devices::Enumeration::DeviceDisconnectButtonClickedEventArgs> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_DisconnectButtonClicked(event_token token) noexcept override
    {
        try
        {
            shim().DisconnectButtonClicked(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_DevicePickerDismissed(abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::Devices::Enumeration::DevicePicker, Windows::IInspectable>> handler, event_token * token) noexcept override
    {
        try
        {
            *token = detach(shim().DevicePickerDismissed(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::Devices::Enumeration::DevicePicker, Windows::IInspectable> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_DevicePickerDismissed(event_token token) noexcept override
    {
        try
        {
            shim().DevicePickerDismissed(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_Show(abi_arg_in<Windows::Foundation::Rect> selection) noexcept override
    {
        try
        {
            shim().Show(*reinterpret_cast<const Windows::Foundation::Rect *>(&selection));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_ShowWithPlacement(abi_arg_in<Windows::Foundation::Rect> selection, Windows::UI::Popups::Placement placement) noexcept override
    {
        try
        {
            shim().Show(*reinterpret_cast<const Windows::Foundation::Rect *>(&selection), placement);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_PickSingleDeviceAsync(abi_arg_in<Windows::Foundation::Rect> selection, abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Devices::Enumeration::DeviceInformation>> operation) noexcept override
    {
        try
        {
            *operation = detach(shim().PickSingleDeviceAsync(*reinterpret_cast<const Windows::Foundation::Rect *>(&selection)));
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_PickSingleDeviceAsyncWithPlacement(abi_arg_in<Windows::Foundation::Rect> selection, Windows::UI::Popups::Placement placement, abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Devices::Enumeration::DeviceInformation>> operation) noexcept override
    {
        try
        {
            *operation = detach(shim().PickSingleDeviceAsync(*reinterpret_cast<const Windows::Foundation::Rect *>(&selection), placement));
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_Hide() noexcept override
    {
        try
        {
            shim().Hide();
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_SetDisplayStatus(abi_arg_in<Windows::Devices::Enumeration::IDeviceInformation> device, abi_arg_in<hstring> status, Windows::Devices::Enumeration::DevicePickerDisplayStatusOptions options) noexcept override
    {
        try
        {
            shim().SetDisplayStatus(*reinterpret_cast<const Windows::Devices::Enumeration::DeviceInformation *>(&device), *reinterpret_cast<const hstring *>(&status), options);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Devices::Enumeration::IDevicePickerAppearance> : produce_base<D, Windows::Devices::Enumeration::IDevicePickerAppearance>
{
    HRESULT __stdcall get_Title(abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            *value = detach(shim().Title());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Title(abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            shim().Title(*reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ForegroundColor(abi_arg_out<Windows::UI::Color> value) noexcept override
    {
        try
        {
            *value = detach(shim().ForegroundColor());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_ForegroundColor(abi_arg_in<Windows::UI::Color> value) noexcept override
    {
        try
        {
            shim().ForegroundColor(*reinterpret_cast<const Windows::UI::Color *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_BackgroundColor(abi_arg_out<Windows::UI::Color> value) noexcept override
    {
        try
        {
            *value = detach(shim().BackgroundColor());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_BackgroundColor(abi_arg_in<Windows::UI::Color> value) noexcept override
    {
        try
        {
            shim().BackgroundColor(*reinterpret_cast<const Windows::UI::Color *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_AccentColor(abi_arg_out<Windows::UI::Color> value) noexcept override
    {
        try
        {
            *value = detach(shim().AccentColor());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_AccentColor(abi_arg_in<Windows::UI::Color> value) noexcept override
    {
        try
        {
            shim().AccentColor(*reinterpret_cast<const Windows::UI::Color *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_SelectedForegroundColor(abi_arg_out<Windows::UI::Color> value) noexcept override
    {
        try
        {
            *value = detach(shim().SelectedForegroundColor());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_SelectedForegroundColor(abi_arg_in<Windows::UI::Color> value) noexcept override
    {
        try
        {
            shim().SelectedForegroundColor(*reinterpret_cast<const Windows::UI::Color *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_SelectedBackgroundColor(abi_arg_out<Windows::UI::Color> value) noexcept override
    {
        try
        {
            *value = detach(shim().SelectedBackgroundColor());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_SelectedBackgroundColor(abi_arg_in<Windows::UI::Color> value) noexcept override
    {
        try
        {
            shim().SelectedBackgroundColor(*reinterpret_cast<const Windows::UI::Color *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_SelectedAccentColor(abi_arg_out<Windows::UI::Color> value) noexcept override
    {
        try
        {
            *value = detach(shim().SelectedAccentColor());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_SelectedAccentColor(abi_arg_in<Windows::UI::Color> value) noexcept override
    {
        try
        {
            shim().SelectedAccentColor(*reinterpret_cast<const Windows::UI::Color *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Devices::Enumeration::IDevicePickerFilter> : produce_base<D, Windows::Devices::Enumeration::IDevicePickerFilter>
{
    HRESULT __stdcall get_SupportedDeviceClasses(abi_arg_out<Windows::Foundation::Collections::IVector<winrt::Windows::Devices::Enumeration::DeviceClass>> value) noexcept override
    {
        try
        {
            *value = detach(shim().SupportedDeviceClasses());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_SupportedDeviceSelectors(abi_arg_out<Windows::Foundation::Collections::IVector<hstring>> value) noexcept override
    {
        try
        {
            *value = detach(shim().SupportedDeviceSelectors());
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
struct produce<D, Windows::Devices::Enumeration::IDeviceSelectedEventArgs> : produce_base<D, Windows::Devices::Enumeration::IDeviceSelectedEventArgs>
{
    HRESULT __stdcall get_SelectedDevice(abi_arg_out<Windows::Devices::Enumeration::IDeviceInformation> value) noexcept override
    {
        try
        {
            *value = detach(shim().SelectedDevice());
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
struct produce<D, Windows::Devices::Enumeration::IDeviceUnpairingResult> : produce_base<D, Windows::Devices::Enumeration::IDeviceUnpairingResult>
{
    HRESULT __stdcall get_Status(Windows::Devices::Enumeration::DeviceUnpairingResultStatus * status) noexcept override
    {
        try
        {
            *status = detach(shim().Status());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Devices::Enumeration::IDeviceWatcher> : produce_base<D, Windows::Devices::Enumeration::IDeviceWatcher>
{
    HRESULT __stdcall add_Added(abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::Devices::Enumeration::DeviceWatcher, Windows::Devices::Enumeration::DeviceInformation>> handler, event_token * token) noexcept override
    {
        try
        {
            *token = detach(shim().Added(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::Devices::Enumeration::DeviceWatcher, Windows::Devices::Enumeration::DeviceInformation> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_Added(event_token token) noexcept override
    {
        try
        {
            shim().Added(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_Updated(abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::Devices::Enumeration::DeviceWatcher, Windows::Devices::Enumeration::DeviceInformationUpdate>> handler, event_token * token) noexcept override
    {
        try
        {
            *token = detach(shim().Updated(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::Devices::Enumeration::DeviceWatcher, Windows::Devices::Enumeration::DeviceInformationUpdate> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_Updated(event_token token) noexcept override
    {
        try
        {
            shim().Updated(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_Removed(abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::Devices::Enumeration::DeviceWatcher, Windows::Devices::Enumeration::DeviceInformationUpdate>> handler, event_token * token) noexcept override
    {
        try
        {
            *token = detach(shim().Removed(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::Devices::Enumeration::DeviceWatcher, Windows::Devices::Enumeration::DeviceInformationUpdate> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_Removed(event_token token) noexcept override
    {
        try
        {
            shim().Removed(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_EnumerationCompleted(abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::Devices::Enumeration::DeviceWatcher, Windows::IInspectable>> handler, event_token * token) noexcept override
    {
        try
        {
            *token = detach(shim().EnumerationCompleted(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::Devices::Enumeration::DeviceWatcher, Windows::IInspectable> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_EnumerationCompleted(event_token token) noexcept override
    {
        try
        {
            shim().EnumerationCompleted(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_Stopped(abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::Devices::Enumeration::DeviceWatcher, Windows::IInspectable>> handler, event_token * token) noexcept override
    {
        try
        {
            *token = detach(shim().Stopped(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::Devices::Enumeration::DeviceWatcher, Windows::IInspectable> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_Stopped(event_token token) noexcept override
    {
        try
        {
            shim().Stopped(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Status(Windows::Devices::Enumeration::DeviceWatcherStatus * status) noexcept override
    {
        try
        {
            *status = detach(shim().Status());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_Start() noexcept override
    {
        try
        {
            shim().Start();
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_Stop() noexcept override
    {
        try
        {
            shim().Stop();
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Devices::Enumeration::IDeviceWatcher2> : produce_base<D, Windows::Devices::Enumeration::IDeviceWatcher2>
{
    HRESULT __stdcall abi_GetBackgroundTrigger(abi_arg_in<Windows::Foundation::Collections::IIterable<winrt::Windows::Devices::Enumeration::DeviceWatcherEventKind>> requestedEventKinds, abi_arg_out<Windows::ApplicationModel::Background::IDeviceWatcherTrigger> trigger) noexcept override
    {
        try
        {
            *trigger = detach(shim().GetBackgroundTrigger(*reinterpret_cast<const Windows::Foundation::Collections::IIterable<winrt::Windows::Devices::Enumeration::DeviceWatcherEventKind> *>(&requestedEventKinds)));
            return S_OK;
        }
        catch (...)
        {
            *trigger = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Devices::Enumeration::IDeviceWatcherEvent> : produce_base<D, Windows::Devices::Enumeration::IDeviceWatcherEvent>
{
    HRESULT __stdcall get_Kind(Windows::Devices::Enumeration::DeviceWatcherEventKind * value) noexcept override
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

    HRESULT __stdcall get_DeviceInformation(abi_arg_out<Windows::Devices::Enumeration::IDeviceInformation> value) noexcept override
    {
        try
        {
            *value = detach(shim().DeviceInformation());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_DeviceInformationUpdate(abi_arg_out<Windows::Devices::Enumeration::IDeviceInformationUpdate> value) noexcept override
    {
        try
        {
            *value = detach(shim().DeviceInformationUpdate());
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
struct produce<D, Windows::Devices::Enumeration::IDeviceWatcherTriggerDetails> : produce_base<D, Windows::Devices::Enumeration::IDeviceWatcherTriggerDetails>
{
    HRESULT __stdcall get_DeviceWatcherEvents(abi_arg_out<Windows::Foundation::Collections::IVectorView<Windows::Devices::Enumeration::DeviceWatcherEvent>> value) noexcept override
    {
        try
        {
            *value = detach(shim().DeviceWatcherEvents());
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
struct produce<D, Windows::Devices::Enumeration::IEnclosureLocation> : produce_base<D, Windows::Devices::Enumeration::IEnclosureLocation>
{
    HRESULT __stdcall get_InDock(bool * value) noexcept override
    {
        try
        {
            *value = detach(shim().InDock());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_InLid(bool * value) noexcept override
    {
        try
        {
            *value = detach(shim().InLid());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Panel(Windows::Devices::Enumeration::Panel * value) noexcept override
    {
        try
        {
            *value = detach(shim().Panel());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Devices::Enumeration::IEnclosureLocation2> : produce_base<D, Windows::Devices::Enumeration::IEnclosureLocation2>
{
    HRESULT __stdcall get_RotationAngleInDegreesClockwise(uint32_t * value) noexcept override
    {
        try
        {
            *value = detach(shim().RotationAngleInDegreesClockwise());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

}

namespace Windows::Devices::Enumeration {

template <typename D> hstring impl_IDeviceConnectionChangeTriggerDetails<D>::DeviceId() const
{
    hstring value;
    check_hresult(shim()->get_DeviceId(put(value)));
    return value;
}

template <typename D> hstring impl_IDevicePickerAppearance<D>::Title() const
{
    hstring value;
    check_hresult(shim()->get_Title(put(value)));
    return value;
}

template <typename D> void impl_IDevicePickerAppearance<D>::Title(hstring_ref value) const
{
    check_hresult(shim()->put_Title(get(value)));
}

template <typename D> Windows::UI::Color impl_IDevicePickerAppearance<D>::ForegroundColor() const
{
    Windows::UI::Color value {};
    check_hresult(shim()->get_ForegroundColor(put(value)));
    return value;
}

template <typename D> void impl_IDevicePickerAppearance<D>::ForegroundColor(const Windows::UI::Color & value) const
{
    check_hresult(shim()->put_ForegroundColor(get(value)));
}

template <typename D> Windows::UI::Color impl_IDevicePickerAppearance<D>::BackgroundColor() const
{
    Windows::UI::Color value {};
    check_hresult(shim()->get_BackgroundColor(put(value)));
    return value;
}

template <typename D> void impl_IDevicePickerAppearance<D>::BackgroundColor(const Windows::UI::Color & value) const
{
    check_hresult(shim()->put_BackgroundColor(get(value)));
}

template <typename D> Windows::UI::Color impl_IDevicePickerAppearance<D>::AccentColor() const
{
    Windows::UI::Color value {};
    check_hresult(shim()->get_AccentColor(put(value)));
    return value;
}

template <typename D> void impl_IDevicePickerAppearance<D>::AccentColor(const Windows::UI::Color & value) const
{
    check_hresult(shim()->put_AccentColor(get(value)));
}

template <typename D> Windows::UI::Color impl_IDevicePickerAppearance<D>::SelectedForegroundColor() const
{
    Windows::UI::Color value {};
    check_hresult(shim()->get_SelectedForegroundColor(put(value)));
    return value;
}

template <typename D> void impl_IDevicePickerAppearance<D>::SelectedForegroundColor(const Windows::UI::Color & value) const
{
    check_hresult(shim()->put_SelectedForegroundColor(get(value)));
}

template <typename D> Windows::UI::Color impl_IDevicePickerAppearance<D>::SelectedBackgroundColor() const
{
    Windows::UI::Color value {};
    check_hresult(shim()->get_SelectedBackgroundColor(put(value)));
    return value;
}

template <typename D> void impl_IDevicePickerAppearance<D>::SelectedBackgroundColor(const Windows::UI::Color & value) const
{
    check_hresult(shim()->put_SelectedBackgroundColor(get(value)));
}

template <typename D> Windows::UI::Color impl_IDevicePickerAppearance<D>::SelectedAccentColor() const
{
    Windows::UI::Color value {};
    check_hresult(shim()->get_SelectedAccentColor(put(value)));
    return value;
}

template <typename D> void impl_IDevicePickerAppearance<D>::SelectedAccentColor(const Windows::UI::Color & value) const
{
    check_hresult(shim()->put_SelectedAccentColor(get(value)));
}

template <typename D> Windows::Devices::Enumeration::DeviceInformation impl_IDeviceSelectedEventArgs<D>::SelectedDevice() const
{
    Windows::Devices::Enumeration::DeviceInformation value { nullptr };
    check_hresult(shim()->get_SelectedDevice(put(value)));
    return value;
}

template <typename D> Windows::Devices::Enumeration::DeviceInformation impl_IDeviceDisconnectButtonClickedEventArgs<D>::Device() const
{
    Windows::Devices::Enumeration::DeviceInformation value { nullptr };
    check_hresult(shim()->get_Device(put(value)));
    return value;
}

template <typename D> Windows::Foundation::Collections::IVector<winrt::Windows::Devices::Enumeration::DeviceClass> impl_IDevicePickerFilter<D>::SupportedDeviceClasses() const
{
    Windows::Foundation::Collections::IVector<winrt::Windows::Devices::Enumeration::DeviceClass> value;
    check_hresult(shim()->get_SupportedDeviceClasses(put(value)));
    return value;
}

template <typename D> Windows::Foundation::Collections::IVector<hstring> impl_IDevicePickerFilter<D>::SupportedDeviceSelectors() const
{
    Windows::Foundation::Collections::IVector<hstring> value;
    check_hresult(shim()->get_SupportedDeviceSelectors(put(value)));
    return value;
}

template <typename D> Windows::Devices::Enumeration::DevicePickerFilter impl_IDevicePicker<D>::Filter() const
{
    Windows::Devices::Enumeration::DevicePickerFilter filter { nullptr };
    check_hresult(shim()->get_Filter(put(filter)));
    return filter;
}

template <typename D> Windows::Devices::Enumeration::DevicePickerAppearance impl_IDevicePicker<D>::Appearance() const
{
    Windows::Devices::Enumeration::DevicePickerAppearance value { nullptr };
    check_hresult(shim()->get_Appearance(put(value)));
    return value;
}

template <typename D> Windows::Foundation::Collections::IVector<hstring> impl_IDevicePicker<D>::RequestedProperties() const
{
    Windows::Foundation::Collections::IVector<hstring> value;
    check_hresult(shim()->get_RequestedProperties(put(value)));
    return value;
}

template <typename D> event_token impl_IDevicePicker<D>::DeviceSelected(const Windows::Foundation::TypedEventHandler<Windows::Devices::Enumeration::DevicePicker, Windows::Devices::Enumeration::DeviceSelectedEventArgs> & handler) const
{
    event_token token {};
    check_hresult(shim()->add_DeviceSelected(get(handler), &token));
    return token;
}

template <typename D> event_revoker<IDevicePicker> impl_IDevicePicker<D>::DeviceSelected(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Devices::Enumeration::DevicePicker, Windows::Devices::Enumeration::DeviceSelectedEventArgs> & handler) const
{
    return impl::make_event_revoker<D, IDevicePicker>(this, &ABI::Windows::Devices::Enumeration::IDevicePicker::remove_DeviceSelected, DeviceSelected(handler));
}

template <typename D> void impl_IDevicePicker<D>::DeviceSelected(event_token token) const
{
    check_hresult(shim()->remove_DeviceSelected(token));
}

template <typename D> event_token impl_IDevicePicker<D>::DisconnectButtonClicked(const Windows::Foundation::TypedEventHandler<Windows::Devices::Enumeration::DevicePicker, Windows::Devices::Enumeration::DeviceDisconnectButtonClickedEventArgs> & handler) const
{
    event_token token {};
    check_hresult(shim()->add_DisconnectButtonClicked(get(handler), &token));
    return token;
}

template <typename D> event_revoker<IDevicePicker> impl_IDevicePicker<D>::DisconnectButtonClicked(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Devices::Enumeration::DevicePicker, Windows::Devices::Enumeration::DeviceDisconnectButtonClickedEventArgs> & handler) const
{
    return impl::make_event_revoker<D, IDevicePicker>(this, &ABI::Windows::Devices::Enumeration::IDevicePicker::remove_DisconnectButtonClicked, DisconnectButtonClicked(handler));
}

template <typename D> void impl_IDevicePicker<D>::DisconnectButtonClicked(event_token token) const
{
    check_hresult(shim()->remove_DisconnectButtonClicked(token));
}

template <typename D> event_token impl_IDevicePicker<D>::DevicePickerDismissed(const Windows::Foundation::TypedEventHandler<Windows::Devices::Enumeration::DevicePicker, Windows::IInspectable> & handler) const
{
    event_token token {};
    check_hresult(shim()->add_DevicePickerDismissed(get(handler), &token));
    return token;
}

template <typename D> event_revoker<IDevicePicker> impl_IDevicePicker<D>::DevicePickerDismissed(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Devices::Enumeration::DevicePicker, Windows::IInspectable> & handler) const
{
    return impl::make_event_revoker<D, IDevicePicker>(this, &ABI::Windows::Devices::Enumeration::IDevicePicker::remove_DevicePickerDismissed, DevicePickerDismissed(handler));
}

template <typename D> void impl_IDevicePicker<D>::DevicePickerDismissed(event_token token) const
{
    check_hresult(shim()->remove_DevicePickerDismissed(token));
}

template <typename D> void impl_IDevicePicker<D>::Show(const Windows::Foundation::Rect & selection) const
{
    check_hresult(shim()->abi_Show(get(selection)));
}

template <typename D> void impl_IDevicePicker<D>::Show(const Windows::Foundation::Rect & selection, Windows::UI::Popups::Placement placement) const
{
    check_hresult(shim()->abi_ShowWithPlacement(get(selection), placement));
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Devices::Enumeration::DeviceInformation> impl_IDevicePicker<D>::PickSingleDeviceAsync(const Windows::Foundation::Rect & selection) const
{
    Windows::Foundation::IAsyncOperation<Windows::Devices::Enumeration::DeviceInformation> operation;
    check_hresult(shim()->abi_PickSingleDeviceAsync(get(selection), put(operation)));
    return operation;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Devices::Enumeration::DeviceInformation> impl_IDevicePicker<D>::PickSingleDeviceAsync(const Windows::Foundation::Rect & selection, Windows::UI::Popups::Placement placement) const
{
    Windows::Foundation::IAsyncOperation<Windows::Devices::Enumeration::DeviceInformation> operation;
    check_hresult(shim()->abi_PickSingleDeviceAsyncWithPlacement(get(selection), placement, put(operation)));
    return operation;
}

template <typename D> void impl_IDevicePicker<D>::Hide() const
{
    check_hresult(shim()->abi_Hide());
}

template <typename D> void impl_IDevicePicker<D>::SetDisplayStatus(const Windows::Devices::Enumeration::DeviceInformation & device, hstring_ref status, Windows::Devices::Enumeration::DevicePickerDisplayStatusOptions options) const
{
    check_hresult(shim()->abi_SetDisplayStatus(get(device), get(status), options));
}

template <typename D> bool impl_IEnclosureLocation<D>::InDock() const
{
    bool value {};
    check_hresult(shim()->get_InDock(&value));
    return value;
}

template <typename D> bool impl_IEnclosureLocation<D>::InLid() const
{
    bool value {};
    check_hresult(shim()->get_InLid(&value));
    return value;
}

template <typename D> Windows::Devices::Enumeration::Panel impl_IEnclosureLocation<D>::Panel() const
{
    Windows::Devices::Enumeration::Panel value {};
    check_hresult(shim()->get_Panel(&value));
    return value;
}

template <typename D> uint32_t impl_IEnclosureLocation2<D>::RotationAngleInDegreesClockwise() const
{
    uint32_t value {};
    check_hresult(shim()->get_RotationAngleInDegreesClockwise(&value));
    return value;
}

template <typename D> hstring impl_IDeviceInformationUpdate<D>::Id() const
{
    hstring value;
    check_hresult(shim()->get_Id(put(value)));
    return value;
}

template <typename D> Windows::Foundation::Collections::IMapView<hstring, Windows::IInspectable> impl_IDeviceInformationUpdate<D>::Properties() const
{
    Windows::Foundation::Collections::IMapView<hstring, Windows::IInspectable> value;
    check_hresult(shim()->get_Properties(put(value)));
    return value;
}

template <typename D> Windows::Devices::Enumeration::DeviceInformationKind impl_IDeviceInformationUpdate2<D>::Kind() const
{
    Windows::Devices::Enumeration::DeviceInformationKind value {};
    check_hresult(shim()->get_Kind(&value));
    return value;
}

template <typename D> event_token impl_IDeviceWatcher<D>::Added(const Windows::Foundation::TypedEventHandler<Windows::Devices::Enumeration::DeviceWatcher, Windows::Devices::Enumeration::DeviceInformation> & handler) const
{
    event_token token {};
    check_hresult(shim()->add_Added(get(handler), &token));
    return token;
}

template <typename D> event_revoker<IDeviceWatcher> impl_IDeviceWatcher<D>::Added(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Devices::Enumeration::DeviceWatcher, Windows::Devices::Enumeration::DeviceInformation> & handler) const
{
    return impl::make_event_revoker<D, IDeviceWatcher>(this, &ABI::Windows::Devices::Enumeration::IDeviceWatcher::remove_Added, Added(handler));
}

template <typename D> void impl_IDeviceWatcher<D>::Added(event_token token) const
{
    check_hresult(shim()->remove_Added(token));
}

template <typename D> event_token impl_IDeviceWatcher<D>::Updated(const Windows::Foundation::TypedEventHandler<Windows::Devices::Enumeration::DeviceWatcher, Windows::Devices::Enumeration::DeviceInformationUpdate> & handler) const
{
    event_token token {};
    check_hresult(shim()->add_Updated(get(handler), &token));
    return token;
}

template <typename D> event_revoker<IDeviceWatcher> impl_IDeviceWatcher<D>::Updated(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Devices::Enumeration::DeviceWatcher, Windows::Devices::Enumeration::DeviceInformationUpdate> & handler) const
{
    return impl::make_event_revoker<D, IDeviceWatcher>(this, &ABI::Windows::Devices::Enumeration::IDeviceWatcher::remove_Updated, Updated(handler));
}

template <typename D> void impl_IDeviceWatcher<D>::Updated(event_token token) const
{
    check_hresult(shim()->remove_Updated(token));
}

template <typename D> event_token impl_IDeviceWatcher<D>::Removed(const Windows::Foundation::TypedEventHandler<Windows::Devices::Enumeration::DeviceWatcher, Windows::Devices::Enumeration::DeviceInformationUpdate> & handler) const
{
    event_token token {};
    check_hresult(shim()->add_Removed(get(handler), &token));
    return token;
}

template <typename D> event_revoker<IDeviceWatcher> impl_IDeviceWatcher<D>::Removed(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Devices::Enumeration::DeviceWatcher, Windows::Devices::Enumeration::DeviceInformationUpdate> & handler) const
{
    return impl::make_event_revoker<D, IDeviceWatcher>(this, &ABI::Windows::Devices::Enumeration::IDeviceWatcher::remove_Removed, Removed(handler));
}

template <typename D> void impl_IDeviceWatcher<D>::Removed(event_token token) const
{
    check_hresult(shim()->remove_Removed(token));
}

template <typename D> event_token impl_IDeviceWatcher<D>::EnumerationCompleted(const Windows::Foundation::TypedEventHandler<Windows::Devices::Enumeration::DeviceWatcher, Windows::IInspectable> & handler) const
{
    event_token token {};
    check_hresult(shim()->add_EnumerationCompleted(get(handler), &token));
    return token;
}

template <typename D> event_revoker<IDeviceWatcher> impl_IDeviceWatcher<D>::EnumerationCompleted(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Devices::Enumeration::DeviceWatcher, Windows::IInspectable> & handler) const
{
    return impl::make_event_revoker<D, IDeviceWatcher>(this, &ABI::Windows::Devices::Enumeration::IDeviceWatcher::remove_EnumerationCompleted, EnumerationCompleted(handler));
}

template <typename D> void impl_IDeviceWatcher<D>::EnumerationCompleted(event_token token) const
{
    check_hresult(shim()->remove_EnumerationCompleted(token));
}

template <typename D> event_token impl_IDeviceWatcher<D>::Stopped(const Windows::Foundation::TypedEventHandler<Windows::Devices::Enumeration::DeviceWatcher, Windows::IInspectable> & handler) const
{
    event_token token {};
    check_hresult(shim()->add_Stopped(get(handler), &token));
    return token;
}

template <typename D> event_revoker<IDeviceWatcher> impl_IDeviceWatcher<D>::Stopped(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Devices::Enumeration::DeviceWatcher, Windows::IInspectable> & handler) const
{
    return impl::make_event_revoker<D, IDeviceWatcher>(this, &ABI::Windows::Devices::Enumeration::IDeviceWatcher::remove_Stopped, Stopped(handler));
}

template <typename D> void impl_IDeviceWatcher<D>::Stopped(event_token token) const
{
    check_hresult(shim()->remove_Stopped(token));
}

template <typename D> Windows::Devices::Enumeration::DeviceWatcherStatus impl_IDeviceWatcher<D>::Status() const
{
    Windows::Devices::Enumeration::DeviceWatcherStatus status {};
    check_hresult(shim()->get_Status(&status));
    return status;
}

template <typename D> void impl_IDeviceWatcher<D>::Start() const
{
    check_hresult(shim()->abi_Start());
}

template <typename D> void impl_IDeviceWatcher<D>::Stop() const
{
    check_hresult(shim()->abi_Stop());
}

template <typename D> Windows::ApplicationModel::Background::DeviceWatcherTrigger impl_IDeviceWatcher2<D>::GetBackgroundTrigger(const Windows::Foundation::Collections::IIterable<winrt::Windows::Devices::Enumeration::DeviceWatcherEventKind> & requestedEventKinds) const
{
    Windows::ApplicationModel::Background::DeviceWatcherTrigger trigger { nullptr };
    check_hresult(shim()->abi_GetBackgroundTrigger(get(requestedEventKinds), put(trigger)));
    return trigger;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Devices::Enumeration::DeviceInformation> impl_IDeviceInformationStatics<D>::CreateFromIdAsync(hstring_ref deviceId) const
{
    Windows::Foundation::IAsyncOperation<Windows::Devices::Enumeration::DeviceInformation> asyncOp;
    check_hresult(shim()->abi_CreateFromIdAsync(get(deviceId), put(asyncOp)));
    return asyncOp;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Devices::Enumeration::DeviceInformation> impl_IDeviceInformationStatics<D>::CreateFromIdAsync(hstring_ref deviceId, const Windows::Foundation::Collections::IIterable<hstring> & additionalProperties) const
{
    Windows::Foundation::IAsyncOperation<Windows::Devices::Enumeration::DeviceInformation> asyncOp;
    check_hresult(shim()->abi_CreateFromIdAsyncAdditionalProperties(get(deviceId), get(additionalProperties), put(asyncOp)));
    return asyncOp;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Devices::Enumeration::DeviceInformationCollection> impl_IDeviceInformationStatics<D>::FindAllAsync() const
{
    Windows::Foundation::IAsyncOperation<Windows::Devices::Enumeration::DeviceInformationCollection> asyncOp;
    check_hresult(shim()->abi_FindAllAsync(put(asyncOp)));
    return asyncOp;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Devices::Enumeration::DeviceInformationCollection> impl_IDeviceInformationStatics<D>::FindAllAsync(Windows::Devices::Enumeration::DeviceClass deviceClass) const
{
    Windows::Foundation::IAsyncOperation<Windows::Devices::Enumeration::DeviceInformationCollection> asyncOp;
    check_hresult(shim()->abi_FindAllAsyncDeviceClass(deviceClass, put(asyncOp)));
    return asyncOp;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Devices::Enumeration::DeviceInformationCollection> impl_IDeviceInformationStatics<D>::FindAllAsync(hstring_ref aqsFilter) const
{
    Windows::Foundation::IAsyncOperation<Windows::Devices::Enumeration::DeviceInformationCollection> asyncOp;
    check_hresult(shim()->abi_FindAllAsyncAqsFilter(get(aqsFilter), put(asyncOp)));
    return asyncOp;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Devices::Enumeration::DeviceInformationCollection> impl_IDeviceInformationStatics<D>::FindAllAsync(hstring_ref aqsFilter, const Windows::Foundation::Collections::IIterable<hstring> & additionalProperties) const
{
    Windows::Foundation::IAsyncOperation<Windows::Devices::Enumeration::DeviceInformationCollection> asyncOp;
    check_hresult(shim()->abi_FindAllAsyncAqsFilterAndAdditionalProperties(get(aqsFilter), get(additionalProperties), put(asyncOp)));
    return asyncOp;
}

template <typename D> Windows::Devices::Enumeration::DeviceWatcher impl_IDeviceInformationStatics<D>::CreateWatcher() const
{
    Windows::Devices::Enumeration::DeviceWatcher watcher { nullptr };
    check_hresult(shim()->abi_CreateWatcher(put(watcher)));
    return watcher;
}

template <typename D> Windows::Devices::Enumeration::DeviceWatcher impl_IDeviceInformationStatics<D>::CreateWatcher(Windows::Devices::Enumeration::DeviceClass deviceClass) const
{
    Windows::Devices::Enumeration::DeviceWatcher watcher { nullptr };
    check_hresult(shim()->abi_CreateWatcherDeviceClass(deviceClass, put(watcher)));
    return watcher;
}

template <typename D> Windows::Devices::Enumeration::DeviceWatcher impl_IDeviceInformationStatics<D>::CreateWatcher(hstring_ref aqsFilter) const
{
    Windows::Devices::Enumeration::DeviceWatcher watcher { nullptr };
    check_hresult(shim()->abi_CreateWatcherAqsFilter(get(aqsFilter), put(watcher)));
    return watcher;
}

template <typename D> Windows::Devices::Enumeration::DeviceWatcher impl_IDeviceInformationStatics<D>::CreateWatcher(hstring_ref aqsFilter, const Windows::Foundation::Collections::IIterable<hstring> & additionalProperties) const
{
    Windows::Devices::Enumeration::DeviceWatcher watcher { nullptr };
    check_hresult(shim()->abi_CreateWatcherAqsFilterAndAdditionalProperties(get(aqsFilter), get(additionalProperties), put(watcher)));
    return watcher;
}

template <typename D> hstring impl_IDeviceInformationStatics2<D>::GetAqsFilterFromDeviceClass(Windows::Devices::Enumeration::DeviceClass deviceClass) const
{
    hstring aqsFilter;
    check_hresult(shim()->abi_GetAqsFilterFromDeviceClass(deviceClass, put(aqsFilter)));
    return aqsFilter;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Devices::Enumeration::DeviceInformation> impl_IDeviceInformationStatics2<D>::CreateFromIdAsync(hstring_ref deviceId, const Windows::Foundation::Collections::IIterable<hstring> & additionalProperties, Windows::Devices::Enumeration::DeviceInformationKind kind) const
{
    Windows::Foundation::IAsyncOperation<Windows::Devices::Enumeration::DeviceInformation> asyncOp;
    check_hresult(shim()->abi_CreateFromIdAsyncWithKindAndAdditionalProperties(get(deviceId), get(additionalProperties), kind, put(asyncOp)));
    return asyncOp;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Devices::Enumeration::DeviceInformationCollection> impl_IDeviceInformationStatics2<D>::FindAllAsync(hstring_ref aqsFilter, const Windows::Foundation::Collections::IIterable<hstring> & additionalProperties, Windows::Devices::Enumeration::DeviceInformationKind kind) const
{
    Windows::Foundation::IAsyncOperation<Windows::Devices::Enumeration::DeviceInformationCollection> asyncOp;
    check_hresult(shim()->abi_FindAllAsyncWithKindAqsFilterAndAdditionalProperties(get(aqsFilter), get(additionalProperties), kind, put(asyncOp)));
    return asyncOp;
}

template <typename D> Windows::Devices::Enumeration::DeviceWatcher impl_IDeviceInformationStatics2<D>::CreateWatcher(hstring_ref aqsFilter, const Windows::Foundation::Collections::IIterable<hstring> & additionalProperties, Windows::Devices::Enumeration::DeviceInformationKind kind) const
{
    Windows::Devices::Enumeration::DeviceWatcher watcher { nullptr };
    check_hresult(shim()->abi_CreateWatcherWithKindAqsFilterAndAdditionalProperties(get(aqsFilter), get(additionalProperties), kind, put(watcher)));
    return watcher;
}

template <typename D> hstring impl_IDeviceInformation<D>::Id() const
{
    hstring value;
    check_hresult(shim()->get_Id(put(value)));
    return value;
}

template <typename D> hstring impl_IDeviceInformation<D>::Name() const
{
    hstring value;
    check_hresult(shim()->get_Name(put(value)));
    return value;
}

template <typename D> bool impl_IDeviceInformation<D>::IsEnabled() const
{
    bool value {};
    check_hresult(shim()->get_IsEnabled(&value));
    return value;
}

template <typename D> bool impl_IDeviceInformation<D>::IsDefault() const
{
    bool value {};
    check_hresult(shim()->get_IsDefault(&value));
    return value;
}

template <typename D> Windows::Devices::Enumeration::EnclosureLocation impl_IDeviceInformation<D>::EnclosureLocation() const
{
    Windows::Devices::Enumeration::EnclosureLocation value { nullptr };
    check_hresult(shim()->get_EnclosureLocation(put(value)));
    return value;
}

template <typename D> Windows::Foundation::Collections::IMapView<hstring, Windows::IInspectable> impl_IDeviceInformation<D>::Properties() const
{
    Windows::Foundation::Collections::IMapView<hstring, Windows::IInspectable> value;
    check_hresult(shim()->get_Properties(put(value)));
    return value;
}

template <typename D> void impl_IDeviceInformation<D>::Update(const Windows::Devices::Enumeration::DeviceInformationUpdate & updateInfo) const
{
    check_hresult(shim()->abi_Update(get(updateInfo)));
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Devices::Enumeration::DeviceThumbnail> impl_IDeviceInformation<D>::GetThumbnailAsync() const
{
    Windows::Foundation::IAsyncOperation<Windows::Devices::Enumeration::DeviceThumbnail> asyncOp;
    check_hresult(shim()->abi_GetThumbnailAsync(put(asyncOp)));
    return asyncOp;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Devices::Enumeration::DeviceThumbnail> impl_IDeviceInformation<D>::GetGlyphThumbnailAsync() const
{
    Windows::Foundation::IAsyncOperation<Windows::Devices::Enumeration::DeviceThumbnail> asyncOp;
    check_hresult(shim()->abi_GetGlyphThumbnailAsync(put(asyncOp)));
    return asyncOp;
}

template <typename D> Windows::Devices::Enumeration::DevicePairingResultStatus impl_IDevicePairingResult<D>::Status() const
{
    Windows::Devices::Enumeration::DevicePairingResultStatus status {};
    check_hresult(shim()->get_Status(&status));
    return status;
}

template <typename D> Windows::Devices::Enumeration::DevicePairingProtectionLevel impl_IDevicePairingResult<D>::ProtectionLevelUsed() const
{
    Windows::Devices::Enumeration::DevicePairingProtectionLevel value {};
    check_hresult(shim()->get_ProtectionLevelUsed(&value));
    return value;
}

template <typename D> Windows::Devices::Enumeration::DeviceUnpairingResultStatus impl_IDeviceUnpairingResult<D>::Status() const
{
    Windows::Devices::Enumeration::DeviceUnpairingResultStatus status {};
    check_hresult(shim()->get_Status(&status));
    return status;
}

template <typename D> Windows::Devices::Enumeration::DeviceInformation impl_IDevicePairingRequestedEventArgs<D>::DeviceInformation() const
{
    Windows::Devices::Enumeration::DeviceInformation value { nullptr };
    check_hresult(shim()->get_DeviceInformation(put(value)));
    return value;
}

template <typename D> Windows::Devices::Enumeration::DevicePairingKinds impl_IDevicePairingRequestedEventArgs<D>::PairingKind() const
{
    Windows::Devices::Enumeration::DevicePairingKinds value {};
    check_hresult(shim()->get_PairingKind(&value));
    return value;
}

template <typename D> hstring impl_IDevicePairingRequestedEventArgs<D>::Pin() const
{
    hstring value;
    check_hresult(shim()->get_Pin(put(value)));
    return value;
}

template <typename D> void impl_IDevicePairingRequestedEventArgs<D>::Accept() const
{
    check_hresult(shim()->abi_Accept());
}

template <typename D> void impl_IDevicePairingRequestedEventArgs<D>::Accept(hstring_ref pin) const
{
    check_hresult(shim()->abi_AcceptWithPin(get(pin)));
}

template <typename D> Windows::Foundation::Deferral impl_IDevicePairingRequestedEventArgs<D>::GetDeferral() const
{
    Windows::Foundation::Deferral result { nullptr };
    check_hresult(shim()->abi_GetDeferral(put(result)));
    return result;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Devices::Enumeration::DevicePairingResult> impl_IDeviceInformationCustomPairing<D>::PairAsync(Windows::Devices::Enumeration::DevicePairingKinds pairingKindsSupported) const
{
    Windows::Foundation::IAsyncOperation<Windows::Devices::Enumeration::DevicePairingResult> result;
    check_hresult(shim()->abi_PairAsync(pairingKindsSupported, put(result)));
    return result;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Devices::Enumeration::DevicePairingResult> impl_IDeviceInformationCustomPairing<D>::PairAsync(Windows::Devices::Enumeration::DevicePairingKinds pairingKindsSupported, Windows::Devices::Enumeration::DevicePairingProtectionLevel minProtectionLevel) const
{
    Windows::Foundation::IAsyncOperation<Windows::Devices::Enumeration::DevicePairingResult> result;
    check_hresult(shim()->abi_PairWithProtectionLevelAsync(pairingKindsSupported, minProtectionLevel, put(result)));
    return result;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Devices::Enumeration::DevicePairingResult> impl_IDeviceInformationCustomPairing<D>::PairAsync(Windows::Devices::Enumeration::DevicePairingKinds pairingKindsSupported, Windows::Devices::Enumeration::DevicePairingProtectionLevel minProtectionLevel, const Windows::Devices::Enumeration::IDevicePairingSettings & devicePairingSettings) const
{
    Windows::Foundation::IAsyncOperation<Windows::Devices::Enumeration::DevicePairingResult> result;
    check_hresult(shim()->abi_PairWithProtectionLevelAndSettingsAsync(pairingKindsSupported, minProtectionLevel, get(devicePairingSettings), put(result)));
    return result;
}

template <typename D> event_token impl_IDeviceInformationCustomPairing<D>::PairingRequested(const Windows::Foundation::TypedEventHandler<Windows::Devices::Enumeration::DeviceInformationCustomPairing, Windows::Devices::Enumeration::DevicePairingRequestedEventArgs> & handler) const
{
    event_token token {};
    check_hresult(shim()->add_PairingRequested(get(handler), &token));
    return token;
}

template <typename D> event_revoker<IDeviceInformationCustomPairing> impl_IDeviceInformationCustomPairing<D>::PairingRequested(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Devices::Enumeration::DeviceInformationCustomPairing, Windows::Devices::Enumeration::DevicePairingRequestedEventArgs> & handler) const
{
    return impl::make_event_revoker<D, IDeviceInformationCustomPairing>(this, &ABI::Windows::Devices::Enumeration::IDeviceInformationCustomPairing::remove_PairingRequested, PairingRequested(handler));
}

template <typename D> void impl_IDeviceInformationCustomPairing<D>::PairingRequested(event_token token) const
{
    check_hresult(shim()->remove_PairingRequested(token));
}

template <typename D> bool impl_IDeviceInformationPairing<D>::IsPaired() const
{
    bool value {};
    check_hresult(shim()->get_IsPaired(&value));
    return value;
}

template <typename D> bool impl_IDeviceInformationPairing<D>::CanPair() const
{
    bool value {};
    check_hresult(shim()->get_CanPair(&value));
    return value;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Devices::Enumeration::DevicePairingResult> impl_IDeviceInformationPairing<D>::PairAsync() const
{
    Windows::Foundation::IAsyncOperation<Windows::Devices::Enumeration::DevicePairingResult> result;
    check_hresult(shim()->abi_PairAsync(put(result)));
    return result;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Devices::Enumeration::DevicePairingResult> impl_IDeviceInformationPairing<D>::PairAsync(Windows::Devices::Enumeration::DevicePairingProtectionLevel minProtectionLevel) const
{
    Windows::Foundation::IAsyncOperation<Windows::Devices::Enumeration::DevicePairingResult> result;
    check_hresult(shim()->abi_PairWithProtectionLevelAsync(minProtectionLevel, put(result)));
    return result;
}

template <typename D> Windows::Devices::Enumeration::DevicePairingProtectionLevel impl_IDeviceInformationPairing2<D>::ProtectionLevel() const
{
    Windows::Devices::Enumeration::DevicePairingProtectionLevel value {};
    check_hresult(shim()->get_ProtectionLevel(&value));
    return value;
}

template <typename D> Windows::Devices::Enumeration::DeviceInformationCustomPairing impl_IDeviceInformationPairing2<D>::Custom() const
{
    Windows::Devices::Enumeration::DeviceInformationCustomPairing value { nullptr };
    check_hresult(shim()->get_Custom(put(value)));
    return value;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Devices::Enumeration::DevicePairingResult> impl_IDeviceInformationPairing2<D>::PairAsync(Windows::Devices::Enumeration::DevicePairingProtectionLevel minProtectionLevel, const Windows::Devices::Enumeration::IDevicePairingSettings & devicePairingSettings) const
{
    Windows::Foundation::IAsyncOperation<Windows::Devices::Enumeration::DevicePairingResult> result;
    check_hresult(shim()->abi_PairWithProtectionLevelAndSettingsAsync(minProtectionLevel, get(devicePairingSettings), put(result)));
    return result;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Devices::Enumeration::DeviceUnpairingResult> impl_IDeviceInformationPairing2<D>::UnpairAsync() const
{
    Windows::Foundation::IAsyncOperation<Windows::Devices::Enumeration::DeviceUnpairingResult> result;
    check_hresult(shim()->abi_UnpairAsync(put(result)));
    return result;
}

template <typename D> bool impl_IDeviceInformationPairingStatics<D>::TryRegisterForAllInboundPairingRequests(Windows::Devices::Enumeration::DevicePairingKinds pairingKindsSupported) const
{
    bool result {};
    check_hresult(shim()->abi_TryRegisterForAllInboundPairingRequests(pairingKindsSupported, &result));
    return result;
}

template <typename D> Windows::Devices::Enumeration::DeviceInformationKind impl_IDeviceInformation2<D>::Kind() const
{
    Windows::Devices::Enumeration::DeviceInformationKind value {};
    check_hresult(shim()->get_Kind(&value));
    return value;
}

template <typename D> Windows::Devices::Enumeration::DeviceInformationPairing impl_IDeviceInformation2<D>::Pairing() const
{
    Windows::Devices::Enumeration::DeviceInformationPairing value { nullptr };
    check_hresult(shim()->get_Pairing(put(value)));
    return value;
}

template <typename D> Windows::Devices::Enumeration::DeviceAccessStatus impl_IDeviceAccessChangedEventArgs<D>::Status() const
{
    Windows::Devices::Enumeration::DeviceAccessStatus value {};
    check_hresult(shim()->get_Status(&value));
    return value;
}

template <typename D> hstring impl_IDeviceAccessChangedEventArgs2<D>::Id() const
{
    hstring value;
    check_hresult(shim()->get_Id(put(value)));
    return value;
}

template <typename D> event_token impl_IDeviceAccessInformation<D>::AccessChanged(const Windows::Foundation::TypedEventHandler<Windows::Devices::Enumeration::DeviceAccessInformation, Windows::Devices::Enumeration::DeviceAccessChangedEventArgs> & handler) const
{
    event_token cookie {};
    check_hresult(shim()->add_AccessChanged(get(handler), &cookie));
    return cookie;
}

template <typename D> event_revoker<IDeviceAccessInformation> impl_IDeviceAccessInformation<D>::AccessChanged(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Devices::Enumeration::DeviceAccessInformation, Windows::Devices::Enumeration::DeviceAccessChangedEventArgs> & handler) const
{
    return impl::make_event_revoker<D, IDeviceAccessInformation>(this, &ABI::Windows::Devices::Enumeration::IDeviceAccessInformation::remove_AccessChanged, AccessChanged(handler));
}

template <typename D> void impl_IDeviceAccessInformation<D>::AccessChanged(event_token cookie) const
{
    check_hresult(shim()->remove_AccessChanged(cookie));
}

template <typename D> Windows::Devices::Enumeration::DeviceAccessStatus impl_IDeviceAccessInformation<D>::CurrentStatus() const
{
    Windows::Devices::Enumeration::DeviceAccessStatus status {};
    check_hresult(shim()->get_CurrentStatus(&status));
    return status;
}

template <typename D> Windows::Devices::Enumeration::DeviceAccessInformation impl_IDeviceAccessInformationStatics<D>::CreateFromId(hstring_ref deviceId) const
{
    Windows::Devices::Enumeration::DeviceAccessInformation value { nullptr };
    check_hresult(shim()->abi_CreateFromId(get(deviceId), put(value)));
    return value;
}

template <typename D> Windows::Devices::Enumeration::DeviceAccessInformation impl_IDeviceAccessInformationStatics<D>::CreateFromDeviceClassId(GUID deviceClassId) const
{
    Windows::Devices::Enumeration::DeviceAccessInformation value { nullptr };
    check_hresult(shim()->abi_CreateFromDeviceClassId(deviceClassId, put(value)));
    return value;
}

template <typename D> Windows::Devices::Enumeration::DeviceAccessInformation impl_IDeviceAccessInformationStatics<D>::CreateFromDeviceClass(Windows::Devices::Enumeration::DeviceClass deviceClass) const
{
    Windows::Devices::Enumeration::DeviceAccessInformation value { nullptr };
    check_hresult(shim()->abi_CreateFromDeviceClass(deviceClass, put(value)));
    return value;
}

template <typename D> Windows::Devices::Enumeration::DeviceWatcherEventKind impl_IDeviceWatcherEvent<D>::Kind() const
{
    Windows::Devices::Enumeration::DeviceWatcherEventKind value {};
    check_hresult(shim()->get_Kind(&value));
    return value;
}

template <typename D> Windows::Devices::Enumeration::DeviceInformation impl_IDeviceWatcherEvent<D>::DeviceInformation() const
{
    Windows::Devices::Enumeration::DeviceInformation value { nullptr };
    check_hresult(shim()->get_DeviceInformation(put(value)));
    return value;
}

template <typename D> Windows::Devices::Enumeration::DeviceInformationUpdate impl_IDeviceWatcherEvent<D>::DeviceInformationUpdate() const
{
    Windows::Devices::Enumeration::DeviceInformationUpdate value { nullptr };
    check_hresult(shim()->get_DeviceInformationUpdate(put(value)));
    return value;
}

template <typename D> Windows::Foundation::Collections::IVectorView<Windows::Devices::Enumeration::DeviceWatcherEvent> impl_IDeviceWatcherTriggerDetails<D>::DeviceWatcherEvents() const
{
    Windows::Foundation::Collections::IVectorView<Windows::Devices::Enumeration::DeviceWatcherEvent> value;
    check_hresult(shim()->get_DeviceWatcherEvents(put(value)));
    return value;
}

inline Windows::Devices::Enumeration::DeviceAccessInformation DeviceAccessInformation::CreateFromId(hstring_ref deviceId)
{
    return GetActivationFactory<DeviceAccessInformation, IDeviceAccessInformationStatics>().CreateFromId(deviceId);
}

inline Windows::Devices::Enumeration::DeviceAccessInformation DeviceAccessInformation::CreateFromDeviceClassId(GUID deviceClassId)
{
    return GetActivationFactory<DeviceAccessInformation, IDeviceAccessInformationStatics>().CreateFromDeviceClassId(deviceClassId);
}

inline Windows::Devices::Enumeration::DeviceAccessInformation DeviceAccessInformation::CreateFromDeviceClass(Windows::Devices::Enumeration::DeviceClass deviceClass)
{
    return GetActivationFactory<DeviceAccessInformation, IDeviceAccessInformationStatics>().CreateFromDeviceClass(deviceClass);
}

inline Windows::Foundation::IAsyncOperation<Windows::Devices::Enumeration::DeviceInformation> DeviceInformation::CreateFromIdAsync(hstring_ref deviceId)
{
    return GetActivationFactory<DeviceInformation, IDeviceInformationStatics>().CreateFromIdAsync(deviceId);
}

inline Windows::Foundation::IAsyncOperation<Windows::Devices::Enumeration::DeviceInformation> DeviceInformation::CreateFromIdAsync(hstring_ref deviceId, const Windows::Foundation::Collections::IIterable<hstring> & additionalProperties)
{
    return GetActivationFactory<DeviceInformation, IDeviceInformationStatics>().CreateFromIdAsync(deviceId, additionalProperties);
}

inline Windows::Foundation::IAsyncOperation<Windows::Devices::Enumeration::DeviceInformationCollection> DeviceInformation::FindAllAsync()
{
    return GetActivationFactory<DeviceInformation, IDeviceInformationStatics>().FindAllAsync();
}

inline Windows::Foundation::IAsyncOperation<Windows::Devices::Enumeration::DeviceInformationCollection> DeviceInformation::FindAllAsync(Windows::Devices::Enumeration::DeviceClass deviceClass)
{
    return GetActivationFactory<DeviceInformation, IDeviceInformationStatics>().FindAllAsync(deviceClass);
}

inline Windows::Foundation::IAsyncOperation<Windows::Devices::Enumeration::DeviceInformationCollection> DeviceInformation::FindAllAsync(hstring_ref aqsFilter)
{
    return GetActivationFactory<DeviceInformation, IDeviceInformationStatics>().FindAllAsync(aqsFilter);
}

inline Windows::Foundation::IAsyncOperation<Windows::Devices::Enumeration::DeviceInformationCollection> DeviceInformation::FindAllAsync(hstring_ref aqsFilter, const Windows::Foundation::Collections::IIterable<hstring> & additionalProperties)
{
    return GetActivationFactory<DeviceInformation, IDeviceInformationStatics>().FindAllAsync(aqsFilter, additionalProperties);
}

inline Windows::Devices::Enumeration::DeviceWatcher DeviceInformation::CreateWatcher()
{
    return GetActivationFactory<DeviceInformation, IDeviceInformationStatics>().CreateWatcher();
}

inline Windows::Devices::Enumeration::DeviceWatcher DeviceInformation::CreateWatcher(Windows::Devices::Enumeration::DeviceClass deviceClass)
{
    return GetActivationFactory<DeviceInformation, IDeviceInformationStatics>().CreateWatcher(deviceClass);
}

inline Windows::Devices::Enumeration::DeviceWatcher DeviceInformation::CreateWatcher(hstring_ref aqsFilter)
{
    return GetActivationFactory<DeviceInformation, IDeviceInformationStatics>().CreateWatcher(aqsFilter);
}

inline Windows::Devices::Enumeration::DeviceWatcher DeviceInformation::CreateWatcher(hstring_ref aqsFilter, const Windows::Foundation::Collections::IIterable<hstring> & additionalProperties)
{
    return GetActivationFactory<DeviceInformation, IDeviceInformationStatics>().CreateWatcher(aqsFilter, additionalProperties);
}

inline hstring DeviceInformation::GetAqsFilterFromDeviceClass(Windows::Devices::Enumeration::DeviceClass deviceClass)
{
    return GetActivationFactory<DeviceInformation, IDeviceInformationStatics2>().GetAqsFilterFromDeviceClass(deviceClass);
}

inline Windows::Foundation::IAsyncOperation<Windows::Devices::Enumeration::DeviceInformation> DeviceInformation::CreateFromIdAsync(hstring_ref deviceId, const Windows::Foundation::Collections::IIterable<hstring> & additionalProperties, Windows::Devices::Enumeration::DeviceInformationKind kind)
{
    return GetActivationFactory<DeviceInformation, IDeviceInformationStatics2>().CreateFromIdAsync(deviceId, additionalProperties, kind);
}

inline Windows::Foundation::IAsyncOperation<Windows::Devices::Enumeration::DeviceInformationCollection> DeviceInformation::FindAllAsync(hstring_ref aqsFilter, const Windows::Foundation::Collections::IIterable<hstring> & additionalProperties, Windows::Devices::Enumeration::DeviceInformationKind kind)
{
    return GetActivationFactory<DeviceInformation, IDeviceInformationStatics2>().FindAllAsync(aqsFilter, additionalProperties, kind);
}

inline Windows::Devices::Enumeration::DeviceWatcher DeviceInformation::CreateWatcher(hstring_ref aqsFilter, const Windows::Foundation::Collections::IIterable<hstring> & additionalProperties, Windows::Devices::Enumeration::DeviceInformationKind kind)
{
    return GetActivationFactory<DeviceInformation, IDeviceInformationStatics2>().CreateWatcher(aqsFilter, additionalProperties, kind);
}

inline bool DeviceInformationPairing::TryRegisterForAllInboundPairingRequests(Windows::Devices::Enumeration::DevicePairingKinds pairingKindsSupported)
{
    return GetActivationFactory<DeviceInformationPairing, IDeviceInformationPairingStatics>().TryRegisterForAllInboundPairingRequests(pairingKindsSupported);
}

inline DevicePicker::DevicePicker() :
    DevicePicker(ActivateInstance<DevicePicker>())
{}

}

}
