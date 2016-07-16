// C++ for the Windows Runtime v1.29
// Copyright (c) 2016 Microsoft Corporation

#pragma once

#include "internal\Windows.Foundation.class.h"
#include "internal\Windows.Foundation.Collections.class.h"
#include "internal\Windows.Devices.Bluetooth.class.h"
#include "internal\Windows.Storage.Streams.class.h"
#include "internal\Windows.Devices.Bluetooth.Advertisement.class.h"
#include "Windows.Devices.Bluetooth.h"

WINRT_EXPORT namespace winrt {

namespace impl {

template <typename D>
struct produce<D, Windows::Devices::Bluetooth::Advertisement::IBluetoothLEAdvertisement> : produce_base<D, Windows::Devices::Bluetooth::Advertisement::IBluetoothLEAdvertisement>
{
    HRESULT __stdcall get_Flags(abi_arg_out<Windows::Foundation::IReference<winrt::Windows::Devices::Bluetooth::Advertisement::BluetoothLEAdvertisementFlags>> value) noexcept override
    {
        try
        {
            *value = detach(shim().Flags());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Flags(abi_arg_in<Windows::Foundation::IReference<winrt::Windows::Devices::Bluetooth::Advertisement::BluetoothLEAdvertisementFlags>> value) noexcept override
    {
        try
        {
            shim().Flags(*reinterpret_cast<const Windows::Foundation::IReference<winrt::Windows::Devices::Bluetooth::Advertisement::BluetoothLEAdvertisementFlags> *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_LocalName(abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            *value = detach(shim().LocalName());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_LocalName(abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            shim().LocalName(*reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ServiceUuids(abi_arg_out<Windows::Foundation::Collections::IVector<GUID>> value) noexcept override
    {
        try
        {
            *value = detach(shim().ServiceUuids());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ManufacturerData(abi_arg_out<Windows::Foundation::Collections::IVector<Windows::Devices::Bluetooth::Advertisement::BluetoothLEManufacturerData>> value) noexcept override
    {
        try
        {
            *value = detach(shim().ManufacturerData());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_DataSections(abi_arg_out<Windows::Foundation::Collections::IVector<Windows::Devices::Bluetooth::Advertisement::BluetoothLEAdvertisementDataSection>> value) noexcept override
    {
        try
        {
            *value = detach(shim().DataSections());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetManufacturerDataByCompanyId(uint16_t companyId, abi_arg_out<Windows::Foundation::Collections::IVectorView<Windows::Devices::Bluetooth::Advertisement::BluetoothLEManufacturerData>> dataList) noexcept override
    {
        try
        {
            *dataList = detach(shim().GetManufacturerDataByCompanyId(companyId));
            return S_OK;
        }
        catch (...)
        {
            *dataList = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetSectionsByType(uint8_t type, abi_arg_out<Windows::Foundation::Collections::IVectorView<Windows::Devices::Bluetooth::Advertisement::BluetoothLEAdvertisementDataSection>> sectionList) noexcept override
    {
        try
        {
            *sectionList = detach(shim().GetSectionsByType(type));
            return S_OK;
        }
        catch (...)
        {
            *sectionList = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Devices::Bluetooth::Advertisement::IBluetoothLEAdvertisementBytePattern> : produce_base<D, Windows::Devices::Bluetooth::Advertisement::IBluetoothLEAdvertisementBytePattern>
{
    HRESULT __stdcall get_DataType(uint8_t * value) noexcept override
    {
        try
        {
            *value = detach(shim().DataType());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_DataType(uint8_t value) noexcept override
    {
        try
        {
            shim().DataType(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Offset(int16_t * value) noexcept override
    {
        try
        {
            *value = detach(shim().Offset());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Offset(int16_t value) noexcept override
    {
        try
        {
            shim().Offset(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Data(abi_arg_out<Windows::Storage::Streams::IBuffer> value) noexcept override
    {
        try
        {
            *value = detach(shim().Data());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Data(abi_arg_in<Windows::Storage::Streams::IBuffer> value) noexcept override
    {
        try
        {
            shim().Data(*reinterpret_cast<const Windows::Storage::Streams::IBuffer *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Devices::Bluetooth::Advertisement::IBluetoothLEAdvertisementBytePatternFactory> : produce_base<D, Windows::Devices::Bluetooth::Advertisement::IBluetoothLEAdvertisementBytePatternFactory>
{
    HRESULT __stdcall abi_Create(uint8_t dataType, int16_t offset, abi_arg_in<Windows::Storage::Streams::IBuffer> data, abi_arg_out<Windows::Devices::Bluetooth::Advertisement::IBluetoothLEAdvertisementBytePattern> value) noexcept override
    {
        try
        {
            *value = detach(shim().Create(dataType, offset, *reinterpret_cast<const Windows::Storage::Streams::IBuffer *>(&data)));
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
struct produce<D, Windows::Devices::Bluetooth::Advertisement::IBluetoothLEAdvertisementDataSection> : produce_base<D, Windows::Devices::Bluetooth::Advertisement::IBluetoothLEAdvertisementDataSection>
{
    HRESULT __stdcall get_DataType(uint8_t * value) noexcept override
    {
        try
        {
            *value = detach(shim().DataType());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_DataType(uint8_t value) noexcept override
    {
        try
        {
            shim().DataType(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Data(abi_arg_out<Windows::Storage::Streams::IBuffer> value) noexcept override
    {
        try
        {
            *value = detach(shim().Data());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Data(abi_arg_in<Windows::Storage::Streams::IBuffer> value) noexcept override
    {
        try
        {
            shim().Data(*reinterpret_cast<const Windows::Storage::Streams::IBuffer *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Devices::Bluetooth::Advertisement::IBluetoothLEAdvertisementDataSectionFactory> : produce_base<D, Windows::Devices::Bluetooth::Advertisement::IBluetoothLEAdvertisementDataSectionFactory>
{
    HRESULT __stdcall abi_Create(uint8_t dataType, abi_arg_in<Windows::Storage::Streams::IBuffer> data, abi_arg_out<Windows::Devices::Bluetooth::Advertisement::IBluetoothLEAdvertisementDataSection> value) noexcept override
    {
        try
        {
            *value = detach(shim().Create(dataType, *reinterpret_cast<const Windows::Storage::Streams::IBuffer *>(&data)));
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
struct produce<D, Windows::Devices::Bluetooth::Advertisement::IBluetoothLEAdvertisementDataTypesStatics> : produce_base<D, Windows::Devices::Bluetooth::Advertisement::IBluetoothLEAdvertisementDataTypesStatics>
{
    HRESULT __stdcall get_Flags(uint8_t * value) noexcept override
    {
        try
        {
            *value = detach(shim().Flags());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_IncompleteService16BitUuids(uint8_t * value) noexcept override
    {
        try
        {
            *value = detach(shim().IncompleteService16BitUuids());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_CompleteService16BitUuids(uint8_t * value) noexcept override
    {
        try
        {
            *value = detach(shim().CompleteService16BitUuids());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_IncompleteService32BitUuids(uint8_t * value) noexcept override
    {
        try
        {
            *value = detach(shim().IncompleteService32BitUuids());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_CompleteService32BitUuids(uint8_t * value) noexcept override
    {
        try
        {
            *value = detach(shim().CompleteService32BitUuids());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_IncompleteService128BitUuids(uint8_t * value) noexcept override
    {
        try
        {
            *value = detach(shim().IncompleteService128BitUuids());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_CompleteService128BitUuids(uint8_t * value) noexcept override
    {
        try
        {
            *value = detach(shim().CompleteService128BitUuids());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ShortenedLocalName(uint8_t * value) noexcept override
    {
        try
        {
            *value = detach(shim().ShortenedLocalName());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_CompleteLocalName(uint8_t * value) noexcept override
    {
        try
        {
            *value = detach(shim().CompleteLocalName());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_TxPowerLevel(uint8_t * value) noexcept override
    {
        try
        {
            *value = detach(shim().TxPowerLevel());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_SlaveConnectionIntervalRange(uint8_t * value) noexcept override
    {
        try
        {
            *value = detach(shim().SlaveConnectionIntervalRange());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ServiceSolicitation16BitUuids(uint8_t * value) noexcept override
    {
        try
        {
            *value = detach(shim().ServiceSolicitation16BitUuids());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ServiceSolicitation32BitUuids(uint8_t * value) noexcept override
    {
        try
        {
            *value = detach(shim().ServiceSolicitation32BitUuids());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ServiceSolicitation128BitUuids(uint8_t * value) noexcept override
    {
        try
        {
            *value = detach(shim().ServiceSolicitation128BitUuids());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ServiceData16BitUuids(uint8_t * value) noexcept override
    {
        try
        {
            *value = detach(shim().ServiceData16BitUuids());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ServiceData32BitUuids(uint8_t * value) noexcept override
    {
        try
        {
            *value = detach(shim().ServiceData32BitUuids());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ServiceData128BitUuids(uint8_t * value) noexcept override
    {
        try
        {
            *value = detach(shim().ServiceData128BitUuids());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_PublicTargetAddress(uint8_t * value) noexcept override
    {
        try
        {
            *value = detach(shim().PublicTargetAddress());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_RandomTargetAddress(uint8_t * value) noexcept override
    {
        try
        {
            *value = detach(shim().RandomTargetAddress());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Appearance(uint8_t * value) noexcept override
    {
        try
        {
            *value = detach(shim().Appearance());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_AdvertisingInterval(uint8_t * value) noexcept override
    {
        try
        {
            *value = detach(shim().AdvertisingInterval());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ManufacturerSpecificData(uint8_t * value) noexcept override
    {
        try
        {
            *value = detach(shim().ManufacturerSpecificData());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Devices::Bluetooth::Advertisement::IBluetoothLEAdvertisementFilter> : produce_base<D, Windows::Devices::Bluetooth::Advertisement::IBluetoothLEAdvertisementFilter>
{
    HRESULT __stdcall get_Advertisement(abi_arg_out<Windows::Devices::Bluetooth::Advertisement::IBluetoothLEAdvertisement> value) noexcept override
    {
        try
        {
            *value = detach(shim().Advertisement());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Advertisement(abi_arg_in<Windows::Devices::Bluetooth::Advertisement::IBluetoothLEAdvertisement> value) noexcept override
    {
        try
        {
            shim().Advertisement(*reinterpret_cast<const Windows::Devices::Bluetooth::Advertisement::BluetoothLEAdvertisement *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_BytePatterns(abi_arg_out<Windows::Foundation::Collections::IVector<Windows::Devices::Bluetooth::Advertisement::BluetoothLEAdvertisementBytePattern>> value) noexcept override
    {
        try
        {
            *value = detach(shim().BytePatterns());
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
struct produce<D, Windows::Devices::Bluetooth::Advertisement::IBluetoothLEAdvertisementPublisher> : produce_base<D, Windows::Devices::Bluetooth::Advertisement::IBluetoothLEAdvertisementPublisher>
{
    HRESULT __stdcall get_Status(Windows::Devices::Bluetooth::Advertisement::BluetoothLEAdvertisementPublisherStatus * value) noexcept override
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

    HRESULT __stdcall get_Advertisement(abi_arg_out<Windows::Devices::Bluetooth::Advertisement::IBluetoothLEAdvertisement> value) noexcept override
    {
        try
        {
            *value = detach(shim().Advertisement());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
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

    HRESULT __stdcall add_StatusChanged(abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::Devices::Bluetooth::Advertisement::BluetoothLEAdvertisementPublisher, Windows::Devices::Bluetooth::Advertisement::BluetoothLEAdvertisementPublisherStatusChangedEventArgs>> handler, event_token * token) noexcept override
    {
        try
        {
            *token = detach(shim().StatusChanged(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::Devices::Bluetooth::Advertisement::BluetoothLEAdvertisementPublisher, Windows::Devices::Bluetooth::Advertisement::BluetoothLEAdvertisementPublisherStatusChangedEventArgs> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_StatusChanged(event_token token) noexcept override
    {
        try
        {
            shim().StatusChanged(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Devices::Bluetooth::Advertisement::IBluetoothLEAdvertisementPublisherFactory> : produce_base<D, Windows::Devices::Bluetooth::Advertisement::IBluetoothLEAdvertisementPublisherFactory>
{
    HRESULT __stdcall abi_Create(abi_arg_in<Windows::Devices::Bluetooth::Advertisement::IBluetoothLEAdvertisement> advertisement, abi_arg_out<Windows::Devices::Bluetooth::Advertisement::IBluetoothLEAdvertisementPublisher> value) noexcept override
    {
        try
        {
            *value = detach(shim().Create(*reinterpret_cast<const Windows::Devices::Bluetooth::Advertisement::BluetoothLEAdvertisement *>(&advertisement)));
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
struct produce<D, Windows::Devices::Bluetooth::Advertisement::IBluetoothLEAdvertisementPublisherStatusChangedEventArgs> : produce_base<D, Windows::Devices::Bluetooth::Advertisement::IBluetoothLEAdvertisementPublisherStatusChangedEventArgs>
{
    HRESULT __stdcall get_Status(Windows::Devices::Bluetooth::Advertisement::BluetoothLEAdvertisementPublisherStatus * value) noexcept override
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

    HRESULT __stdcall get_Error(Windows::Devices::Bluetooth::BluetoothError * value) noexcept override
    {
        try
        {
            *value = detach(shim().Error());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Devices::Bluetooth::Advertisement::IBluetoothLEAdvertisementReceivedEventArgs> : produce_base<D, Windows::Devices::Bluetooth::Advertisement::IBluetoothLEAdvertisementReceivedEventArgs>
{
    HRESULT __stdcall get_RawSignalStrengthInDBm(int16_t * value) noexcept override
    {
        try
        {
            *value = detach(shim().RawSignalStrengthInDBm());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_BluetoothAddress(uint64_t * value) noexcept override
    {
        try
        {
            *value = detach(shim().BluetoothAddress());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_AdvertisementType(Windows::Devices::Bluetooth::Advertisement::BluetoothLEAdvertisementType * value) noexcept override
    {
        try
        {
            *value = detach(shim().AdvertisementType());
            return S_OK;
        }
        catch (...)
        {
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

    HRESULT __stdcall get_Advertisement(abi_arg_out<Windows::Devices::Bluetooth::Advertisement::IBluetoothLEAdvertisement> value) noexcept override
    {
        try
        {
            *value = detach(shim().Advertisement());
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
struct produce<D, Windows::Devices::Bluetooth::Advertisement::IBluetoothLEAdvertisementWatcher> : produce_base<D, Windows::Devices::Bluetooth::Advertisement::IBluetoothLEAdvertisementWatcher>
{
    HRESULT __stdcall get_MinSamplingInterval(abi_arg_out<Windows::Foundation::TimeSpan> value) noexcept override
    {
        try
        {
            *value = detach(shim().MinSamplingInterval());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_MaxSamplingInterval(abi_arg_out<Windows::Foundation::TimeSpan> value) noexcept override
    {
        try
        {
            *value = detach(shim().MaxSamplingInterval());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_MinOutOfRangeTimeout(abi_arg_out<Windows::Foundation::TimeSpan> value) noexcept override
    {
        try
        {
            *value = detach(shim().MinOutOfRangeTimeout());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_MaxOutOfRangeTimeout(abi_arg_out<Windows::Foundation::TimeSpan> value) noexcept override
    {
        try
        {
            *value = detach(shim().MaxOutOfRangeTimeout());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Status(Windows::Devices::Bluetooth::Advertisement::BluetoothLEAdvertisementWatcherStatus * value) noexcept override
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

    HRESULT __stdcall get_ScanningMode(Windows::Devices::Bluetooth::Advertisement::BluetoothLEScanningMode * value) noexcept override
    {
        try
        {
            *value = detach(shim().ScanningMode());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_ScanningMode(Windows::Devices::Bluetooth::Advertisement::BluetoothLEScanningMode value) noexcept override
    {
        try
        {
            shim().ScanningMode(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_SignalStrengthFilter(abi_arg_out<Windows::Devices::Bluetooth::IBluetoothSignalStrengthFilter> value) noexcept override
    {
        try
        {
            *value = detach(shim().SignalStrengthFilter());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_SignalStrengthFilter(abi_arg_in<Windows::Devices::Bluetooth::IBluetoothSignalStrengthFilter> value) noexcept override
    {
        try
        {
            shim().SignalStrengthFilter(*reinterpret_cast<const Windows::Devices::Bluetooth::BluetoothSignalStrengthFilter *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_AdvertisementFilter(abi_arg_out<Windows::Devices::Bluetooth::Advertisement::IBluetoothLEAdvertisementFilter> value) noexcept override
    {
        try
        {
            *value = detach(shim().AdvertisementFilter());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_AdvertisementFilter(abi_arg_in<Windows::Devices::Bluetooth::Advertisement::IBluetoothLEAdvertisementFilter> value) noexcept override
    {
        try
        {
            shim().AdvertisementFilter(*reinterpret_cast<const Windows::Devices::Bluetooth::Advertisement::BluetoothLEAdvertisementFilter *>(&value));
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

    HRESULT __stdcall add_Received(abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::Devices::Bluetooth::Advertisement::BluetoothLEAdvertisementWatcher, Windows::Devices::Bluetooth::Advertisement::BluetoothLEAdvertisementReceivedEventArgs>> handler, event_token * token) noexcept override
    {
        try
        {
            *token = detach(shim().Received(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::Devices::Bluetooth::Advertisement::BluetoothLEAdvertisementWatcher, Windows::Devices::Bluetooth::Advertisement::BluetoothLEAdvertisementReceivedEventArgs> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_Received(event_token token) noexcept override
    {
        try
        {
            shim().Received(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_Stopped(abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::Devices::Bluetooth::Advertisement::BluetoothLEAdvertisementWatcher, Windows::Devices::Bluetooth::Advertisement::BluetoothLEAdvertisementWatcherStoppedEventArgs>> handler, event_token * token) noexcept override
    {
        try
        {
            *token = detach(shim().Stopped(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::Devices::Bluetooth::Advertisement::BluetoothLEAdvertisementWatcher, Windows::Devices::Bluetooth::Advertisement::BluetoothLEAdvertisementWatcherStoppedEventArgs> *>(&handler)));
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
};

template <typename D>
struct produce<D, Windows::Devices::Bluetooth::Advertisement::IBluetoothLEAdvertisementWatcherFactory> : produce_base<D, Windows::Devices::Bluetooth::Advertisement::IBluetoothLEAdvertisementWatcherFactory>
{
    HRESULT __stdcall abi_Create(abi_arg_in<Windows::Devices::Bluetooth::Advertisement::IBluetoothLEAdvertisementFilter> advertisementFilter, abi_arg_out<Windows::Devices::Bluetooth::Advertisement::IBluetoothLEAdvertisementWatcher> value) noexcept override
    {
        try
        {
            *value = detach(shim().Create(*reinterpret_cast<const Windows::Devices::Bluetooth::Advertisement::BluetoothLEAdvertisementFilter *>(&advertisementFilter)));
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
struct produce<D, Windows::Devices::Bluetooth::Advertisement::IBluetoothLEAdvertisementWatcherStoppedEventArgs> : produce_base<D, Windows::Devices::Bluetooth::Advertisement::IBluetoothLEAdvertisementWatcherStoppedEventArgs>
{
    HRESULT __stdcall get_Error(Windows::Devices::Bluetooth::BluetoothError * value) noexcept override
    {
        try
        {
            *value = detach(shim().Error());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Devices::Bluetooth::Advertisement::IBluetoothLEManufacturerData> : produce_base<D, Windows::Devices::Bluetooth::Advertisement::IBluetoothLEManufacturerData>
{
    HRESULT __stdcall get_CompanyId(uint16_t * value) noexcept override
    {
        try
        {
            *value = detach(shim().CompanyId());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_CompanyId(uint16_t value) noexcept override
    {
        try
        {
            shim().CompanyId(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Data(abi_arg_out<Windows::Storage::Streams::IBuffer> value) noexcept override
    {
        try
        {
            *value = detach(shim().Data());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Data(abi_arg_in<Windows::Storage::Streams::IBuffer> value) noexcept override
    {
        try
        {
            shim().Data(*reinterpret_cast<const Windows::Storage::Streams::IBuffer *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Devices::Bluetooth::Advertisement::IBluetoothLEManufacturerDataFactory> : produce_base<D, Windows::Devices::Bluetooth::Advertisement::IBluetoothLEManufacturerDataFactory>
{
    HRESULT __stdcall abi_Create(uint16_t companyId, abi_arg_in<Windows::Storage::Streams::IBuffer> data, abi_arg_out<Windows::Devices::Bluetooth::Advertisement::IBluetoothLEManufacturerData> value) noexcept override
    {
        try
        {
            *value = detach(shim().Create(companyId, *reinterpret_cast<const Windows::Storage::Streams::IBuffer *>(&data)));
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }
};

}

namespace Windows::Devices::Bluetooth::Advertisement {

template <typename D> Windows::Foundation::IReference<winrt::Windows::Devices::Bluetooth::Advertisement::BluetoothLEAdvertisementFlags> impl_IBluetoothLEAdvertisement<D>::Flags() const
{
    Windows::Foundation::IReference<winrt::Windows::Devices::Bluetooth::Advertisement::BluetoothLEAdvertisementFlags> value;
    check_hresult(shim()->get_Flags(put(value)));
    return value;
}

template <typename D> void impl_IBluetoothLEAdvertisement<D>::Flags(const Windows::Foundation::IReference<winrt::Windows::Devices::Bluetooth::Advertisement::BluetoothLEAdvertisementFlags> & value) const
{
    check_hresult(shim()->put_Flags(get(value)));
}

template <typename D> hstring impl_IBluetoothLEAdvertisement<D>::LocalName() const
{
    hstring value;
    check_hresult(shim()->get_LocalName(put(value)));
    return value;
}

template <typename D> void impl_IBluetoothLEAdvertisement<D>::LocalName(hstring_ref value) const
{
    check_hresult(shim()->put_LocalName(get(value)));
}

template <typename D> Windows::Foundation::Collections::IVector<GUID> impl_IBluetoothLEAdvertisement<D>::ServiceUuids() const
{
    Windows::Foundation::Collections::IVector<GUID> value;
    check_hresult(shim()->get_ServiceUuids(put(value)));
    return value;
}

template <typename D> Windows::Foundation::Collections::IVector<Windows::Devices::Bluetooth::Advertisement::BluetoothLEManufacturerData> impl_IBluetoothLEAdvertisement<D>::ManufacturerData() const
{
    Windows::Foundation::Collections::IVector<Windows::Devices::Bluetooth::Advertisement::BluetoothLEManufacturerData> value;
    check_hresult(shim()->get_ManufacturerData(put(value)));
    return value;
}

template <typename D> Windows::Foundation::Collections::IVector<Windows::Devices::Bluetooth::Advertisement::BluetoothLEAdvertisementDataSection> impl_IBluetoothLEAdvertisement<D>::DataSections() const
{
    Windows::Foundation::Collections::IVector<Windows::Devices::Bluetooth::Advertisement::BluetoothLEAdvertisementDataSection> value;
    check_hresult(shim()->get_DataSections(put(value)));
    return value;
}

template <typename D> Windows::Foundation::Collections::IVectorView<Windows::Devices::Bluetooth::Advertisement::BluetoothLEManufacturerData> impl_IBluetoothLEAdvertisement<D>::GetManufacturerDataByCompanyId(uint16_t companyId) const
{
    Windows::Foundation::Collections::IVectorView<Windows::Devices::Bluetooth::Advertisement::BluetoothLEManufacturerData> dataList;
    check_hresult(shim()->abi_GetManufacturerDataByCompanyId(companyId, put(dataList)));
    return dataList;
}

template <typename D> Windows::Foundation::Collections::IVectorView<Windows::Devices::Bluetooth::Advertisement::BluetoothLEAdvertisementDataSection> impl_IBluetoothLEAdvertisement<D>::GetSectionsByType(uint8_t type) const
{
    Windows::Foundation::Collections::IVectorView<Windows::Devices::Bluetooth::Advertisement::BluetoothLEAdvertisementDataSection> sectionList;
    check_hresult(shim()->abi_GetSectionsByType(type, put(sectionList)));
    return sectionList;
}

template <typename D> Windows::Devices::Bluetooth::Advertisement::BluetoothLEAdvertisement impl_IBluetoothLEAdvertisementFilter<D>::Advertisement() const
{
    Windows::Devices::Bluetooth::Advertisement::BluetoothLEAdvertisement value { nullptr };
    check_hresult(shim()->get_Advertisement(put(value)));
    return value;
}

template <typename D> void impl_IBluetoothLEAdvertisementFilter<D>::Advertisement(const Windows::Devices::Bluetooth::Advertisement::BluetoothLEAdvertisement & value) const
{
    check_hresult(shim()->put_Advertisement(get(value)));
}

template <typename D> Windows::Foundation::Collections::IVector<Windows::Devices::Bluetooth::Advertisement::BluetoothLEAdvertisementBytePattern> impl_IBluetoothLEAdvertisementFilter<D>::BytePatterns() const
{
    Windows::Foundation::Collections::IVector<Windows::Devices::Bluetooth::Advertisement::BluetoothLEAdvertisementBytePattern> value;
    check_hresult(shim()->get_BytePatterns(put(value)));
    return value;
}

template <typename D> Windows::Devices::Bluetooth::BluetoothError impl_IBluetoothLEAdvertisementWatcherStoppedEventArgs<D>::Error() const
{
    Windows::Devices::Bluetooth::BluetoothError value {};
    check_hresult(shim()->get_Error(&value));
    return value;
}

template <typename D> Windows::Devices::Bluetooth::Advertisement::BluetoothLEAdvertisementWatcher impl_IBluetoothLEAdvertisementWatcherFactory<D>::Create(const Windows::Devices::Bluetooth::Advertisement::BluetoothLEAdvertisementFilter & advertisementFilter) const
{
    Windows::Devices::Bluetooth::Advertisement::BluetoothLEAdvertisementWatcher value { nullptr };
    check_hresult(shim()->abi_Create(get(advertisementFilter), put(value)));
    return value;
}

template <typename D> Windows::Foundation::TimeSpan impl_IBluetoothLEAdvertisementWatcher<D>::MinSamplingInterval() const
{
    Windows::Foundation::TimeSpan value {};
    check_hresult(shim()->get_MinSamplingInterval(put(value)));
    return value;
}

template <typename D> Windows::Foundation::TimeSpan impl_IBluetoothLEAdvertisementWatcher<D>::MaxSamplingInterval() const
{
    Windows::Foundation::TimeSpan value {};
    check_hresult(shim()->get_MaxSamplingInterval(put(value)));
    return value;
}

template <typename D> Windows::Foundation::TimeSpan impl_IBluetoothLEAdvertisementWatcher<D>::MinOutOfRangeTimeout() const
{
    Windows::Foundation::TimeSpan value {};
    check_hresult(shim()->get_MinOutOfRangeTimeout(put(value)));
    return value;
}

template <typename D> Windows::Foundation::TimeSpan impl_IBluetoothLEAdvertisementWatcher<D>::MaxOutOfRangeTimeout() const
{
    Windows::Foundation::TimeSpan value {};
    check_hresult(shim()->get_MaxOutOfRangeTimeout(put(value)));
    return value;
}

template <typename D> Windows::Devices::Bluetooth::Advertisement::BluetoothLEAdvertisementWatcherStatus impl_IBluetoothLEAdvertisementWatcher<D>::Status() const
{
    Windows::Devices::Bluetooth::Advertisement::BluetoothLEAdvertisementWatcherStatus value {};
    check_hresult(shim()->get_Status(&value));
    return value;
}

template <typename D> Windows::Devices::Bluetooth::Advertisement::BluetoothLEScanningMode impl_IBluetoothLEAdvertisementWatcher<D>::ScanningMode() const
{
    Windows::Devices::Bluetooth::Advertisement::BluetoothLEScanningMode value {};
    check_hresult(shim()->get_ScanningMode(&value));
    return value;
}

template <typename D> void impl_IBluetoothLEAdvertisementWatcher<D>::ScanningMode(Windows::Devices::Bluetooth::Advertisement::BluetoothLEScanningMode value) const
{
    check_hresult(shim()->put_ScanningMode(value));
}

template <typename D> Windows::Devices::Bluetooth::BluetoothSignalStrengthFilter impl_IBluetoothLEAdvertisementWatcher<D>::SignalStrengthFilter() const
{
    Windows::Devices::Bluetooth::BluetoothSignalStrengthFilter value { nullptr };
    check_hresult(shim()->get_SignalStrengthFilter(put(value)));
    return value;
}

template <typename D> void impl_IBluetoothLEAdvertisementWatcher<D>::SignalStrengthFilter(const Windows::Devices::Bluetooth::BluetoothSignalStrengthFilter & value) const
{
    check_hresult(shim()->put_SignalStrengthFilter(get(value)));
}

template <typename D> Windows::Devices::Bluetooth::Advertisement::BluetoothLEAdvertisementFilter impl_IBluetoothLEAdvertisementWatcher<D>::AdvertisementFilter() const
{
    Windows::Devices::Bluetooth::Advertisement::BluetoothLEAdvertisementFilter value { nullptr };
    check_hresult(shim()->get_AdvertisementFilter(put(value)));
    return value;
}

template <typename D> void impl_IBluetoothLEAdvertisementWatcher<D>::AdvertisementFilter(const Windows::Devices::Bluetooth::Advertisement::BluetoothLEAdvertisementFilter & value) const
{
    check_hresult(shim()->put_AdvertisementFilter(get(value)));
}

template <typename D> void impl_IBluetoothLEAdvertisementWatcher<D>::Start() const
{
    check_hresult(shim()->abi_Start());
}

template <typename D> void impl_IBluetoothLEAdvertisementWatcher<D>::Stop() const
{
    check_hresult(shim()->abi_Stop());
}

template <typename D> event_token impl_IBluetoothLEAdvertisementWatcher<D>::Received(const Windows::Foundation::TypedEventHandler<Windows::Devices::Bluetooth::Advertisement::BluetoothLEAdvertisementWatcher, Windows::Devices::Bluetooth::Advertisement::BluetoothLEAdvertisementReceivedEventArgs> & handler) const
{
    event_token token {};
    check_hresult(shim()->add_Received(get(handler), &token));
    return token;
}

template <typename D> event_revoker<IBluetoothLEAdvertisementWatcher> impl_IBluetoothLEAdvertisementWatcher<D>::Received(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Devices::Bluetooth::Advertisement::BluetoothLEAdvertisementWatcher, Windows::Devices::Bluetooth::Advertisement::BluetoothLEAdvertisementReceivedEventArgs> & handler) const
{
    return impl::make_event_revoker<D, IBluetoothLEAdvertisementWatcher>(this, &ABI::Windows::Devices::Bluetooth::Advertisement::IBluetoothLEAdvertisementWatcher::remove_Received, Received(handler));
}

template <typename D> void impl_IBluetoothLEAdvertisementWatcher<D>::Received(event_token token) const
{
    check_hresult(shim()->remove_Received(token));
}

template <typename D> event_token impl_IBluetoothLEAdvertisementWatcher<D>::Stopped(const Windows::Foundation::TypedEventHandler<Windows::Devices::Bluetooth::Advertisement::BluetoothLEAdvertisementWatcher, Windows::Devices::Bluetooth::Advertisement::BluetoothLEAdvertisementWatcherStoppedEventArgs> & handler) const
{
    event_token token {};
    check_hresult(shim()->add_Stopped(get(handler), &token));
    return token;
}

template <typename D> event_revoker<IBluetoothLEAdvertisementWatcher> impl_IBluetoothLEAdvertisementWatcher<D>::Stopped(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Devices::Bluetooth::Advertisement::BluetoothLEAdvertisementWatcher, Windows::Devices::Bluetooth::Advertisement::BluetoothLEAdvertisementWatcherStoppedEventArgs> & handler) const
{
    return impl::make_event_revoker<D, IBluetoothLEAdvertisementWatcher>(this, &ABI::Windows::Devices::Bluetooth::Advertisement::IBluetoothLEAdvertisementWatcher::remove_Stopped, Stopped(handler));
}

template <typename D> void impl_IBluetoothLEAdvertisementWatcher<D>::Stopped(event_token token) const
{
    check_hresult(shim()->remove_Stopped(token));
}

template <typename D> int16_t impl_IBluetoothLEAdvertisementReceivedEventArgs<D>::RawSignalStrengthInDBm() const
{
    int16_t value {};
    check_hresult(shim()->get_RawSignalStrengthInDBm(&value));
    return value;
}

template <typename D> uint64_t impl_IBluetoothLEAdvertisementReceivedEventArgs<D>::BluetoothAddress() const
{
    uint64_t value {};
    check_hresult(shim()->get_BluetoothAddress(&value));
    return value;
}

template <typename D> Windows::Devices::Bluetooth::Advertisement::BluetoothLEAdvertisementType impl_IBluetoothLEAdvertisementReceivedEventArgs<D>::AdvertisementType() const
{
    Windows::Devices::Bluetooth::Advertisement::BluetoothLEAdvertisementType value {};
    check_hresult(shim()->get_AdvertisementType(&value));
    return value;
}

template <typename D> Windows::Foundation::DateTime impl_IBluetoothLEAdvertisementReceivedEventArgs<D>::Timestamp() const
{
    Windows::Foundation::DateTime value {};
    check_hresult(shim()->get_Timestamp(put(value)));
    return value;
}

template <typename D> Windows::Devices::Bluetooth::Advertisement::BluetoothLEAdvertisement impl_IBluetoothLEAdvertisementReceivedEventArgs<D>::Advertisement() const
{
    Windows::Devices::Bluetooth::Advertisement::BluetoothLEAdvertisement value { nullptr };
    check_hresult(shim()->get_Advertisement(put(value)));
    return value;
}

template <typename D> Windows::Devices::Bluetooth::Advertisement::BluetoothLEAdvertisementDataSection impl_IBluetoothLEAdvertisementDataSectionFactory<D>::Create(uint8_t dataType, const Windows::Storage::Streams::IBuffer & data) const
{
    Windows::Devices::Bluetooth::Advertisement::BluetoothLEAdvertisementDataSection value { nullptr };
    check_hresult(shim()->abi_Create(dataType, get(data), put(value)));
    return value;
}

template <typename D> uint8_t impl_IBluetoothLEAdvertisementDataSection<D>::DataType() const
{
    uint8_t value {};
    check_hresult(shim()->get_DataType(&value));
    return value;
}

template <typename D> void impl_IBluetoothLEAdvertisementDataSection<D>::DataType(uint8_t value) const
{
    check_hresult(shim()->put_DataType(value));
}

template <typename D> Windows::Storage::Streams::IBuffer impl_IBluetoothLEAdvertisementDataSection<D>::Data() const
{
    Windows::Storage::Streams::IBuffer value;
    check_hresult(shim()->get_Data(put(value)));
    return value;
}

template <typename D> void impl_IBluetoothLEAdvertisementDataSection<D>::Data(const Windows::Storage::Streams::IBuffer & value) const
{
    check_hresult(shim()->put_Data(get(value)));
}

template <typename D> Windows::Devices::Bluetooth::Advertisement::BluetoothLEManufacturerData impl_IBluetoothLEManufacturerDataFactory<D>::Create(uint16_t companyId, const Windows::Storage::Streams::IBuffer & data) const
{
    Windows::Devices::Bluetooth::Advertisement::BluetoothLEManufacturerData value { nullptr };
    check_hresult(shim()->abi_Create(companyId, get(data), put(value)));
    return value;
}

template <typename D> uint16_t impl_IBluetoothLEManufacturerData<D>::CompanyId() const
{
    uint16_t value {};
    check_hresult(shim()->get_CompanyId(&value));
    return value;
}

template <typename D> void impl_IBluetoothLEManufacturerData<D>::CompanyId(uint16_t value) const
{
    check_hresult(shim()->put_CompanyId(value));
}

template <typename D> Windows::Storage::Streams::IBuffer impl_IBluetoothLEManufacturerData<D>::Data() const
{
    Windows::Storage::Streams::IBuffer value;
    check_hresult(shim()->get_Data(put(value)));
    return value;
}

template <typename D> void impl_IBluetoothLEManufacturerData<D>::Data(const Windows::Storage::Streams::IBuffer & value) const
{
    check_hresult(shim()->put_Data(get(value)));
}

template <typename D> Windows::Devices::Bluetooth::Advertisement::BluetoothLEAdvertisementBytePattern impl_IBluetoothLEAdvertisementBytePatternFactory<D>::Create(uint8_t dataType, int16_t offset, const Windows::Storage::Streams::IBuffer & data) const
{
    Windows::Devices::Bluetooth::Advertisement::BluetoothLEAdvertisementBytePattern value { nullptr };
    check_hresult(shim()->abi_Create(dataType, offset, get(data), put(value)));
    return value;
}

template <typename D> uint8_t impl_IBluetoothLEAdvertisementBytePattern<D>::DataType() const
{
    uint8_t value {};
    check_hresult(shim()->get_DataType(&value));
    return value;
}

template <typename D> void impl_IBluetoothLEAdvertisementBytePattern<D>::DataType(uint8_t value) const
{
    check_hresult(shim()->put_DataType(value));
}

template <typename D> int16_t impl_IBluetoothLEAdvertisementBytePattern<D>::Offset() const
{
    int16_t value {};
    check_hresult(shim()->get_Offset(&value));
    return value;
}

template <typename D> void impl_IBluetoothLEAdvertisementBytePattern<D>::Offset(int16_t value) const
{
    check_hresult(shim()->put_Offset(value));
}

template <typename D> Windows::Storage::Streams::IBuffer impl_IBluetoothLEAdvertisementBytePattern<D>::Data() const
{
    Windows::Storage::Streams::IBuffer value;
    check_hresult(shim()->get_Data(put(value)));
    return value;
}

template <typename D> void impl_IBluetoothLEAdvertisementBytePattern<D>::Data(const Windows::Storage::Streams::IBuffer & value) const
{
    check_hresult(shim()->put_Data(get(value)));
}

template <typename D> uint8_t impl_IBluetoothLEAdvertisementDataTypesStatics<D>::Flags() const
{
    uint8_t value {};
    check_hresult(shim()->get_Flags(&value));
    return value;
}

template <typename D> uint8_t impl_IBluetoothLEAdvertisementDataTypesStatics<D>::IncompleteService16BitUuids() const
{
    uint8_t value {};
    check_hresult(shim()->get_IncompleteService16BitUuids(&value));
    return value;
}

template <typename D> uint8_t impl_IBluetoothLEAdvertisementDataTypesStatics<D>::CompleteService16BitUuids() const
{
    uint8_t value {};
    check_hresult(shim()->get_CompleteService16BitUuids(&value));
    return value;
}

template <typename D> uint8_t impl_IBluetoothLEAdvertisementDataTypesStatics<D>::IncompleteService32BitUuids() const
{
    uint8_t value {};
    check_hresult(shim()->get_IncompleteService32BitUuids(&value));
    return value;
}

template <typename D> uint8_t impl_IBluetoothLEAdvertisementDataTypesStatics<D>::CompleteService32BitUuids() const
{
    uint8_t value {};
    check_hresult(shim()->get_CompleteService32BitUuids(&value));
    return value;
}

template <typename D> uint8_t impl_IBluetoothLEAdvertisementDataTypesStatics<D>::IncompleteService128BitUuids() const
{
    uint8_t value {};
    check_hresult(shim()->get_IncompleteService128BitUuids(&value));
    return value;
}

template <typename D> uint8_t impl_IBluetoothLEAdvertisementDataTypesStatics<D>::CompleteService128BitUuids() const
{
    uint8_t value {};
    check_hresult(shim()->get_CompleteService128BitUuids(&value));
    return value;
}

template <typename D> uint8_t impl_IBluetoothLEAdvertisementDataTypesStatics<D>::ShortenedLocalName() const
{
    uint8_t value {};
    check_hresult(shim()->get_ShortenedLocalName(&value));
    return value;
}

template <typename D> uint8_t impl_IBluetoothLEAdvertisementDataTypesStatics<D>::CompleteLocalName() const
{
    uint8_t value {};
    check_hresult(shim()->get_CompleteLocalName(&value));
    return value;
}

template <typename D> uint8_t impl_IBluetoothLEAdvertisementDataTypesStatics<D>::TxPowerLevel() const
{
    uint8_t value {};
    check_hresult(shim()->get_TxPowerLevel(&value));
    return value;
}

template <typename D> uint8_t impl_IBluetoothLEAdvertisementDataTypesStatics<D>::SlaveConnectionIntervalRange() const
{
    uint8_t value {};
    check_hresult(shim()->get_SlaveConnectionIntervalRange(&value));
    return value;
}

template <typename D> uint8_t impl_IBluetoothLEAdvertisementDataTypesStatics<D>::ServiceSolicitation16BitUuids() const
{
    uint8_t value {};
    check_hresult(shim()->get_ServiceSolicitation16BitUuids(&value));
    return value;
}

template <typename D> uint8_t impl_IBluetoothLEAdvertisementDataTypesStatics<D>::ServiceSolicitation32BitUuids() const
{
    uint8_t value {};
    check_hresult(shim()->get_ServiceSolicitation32BitUuids(&value));
    return value;
}

template <typename D> uint8_t impl_IBluetoothLEAdvertisementDataTypesStatics<D>::ServiceSolicitation128BitUuids() const
{
    uint8_t value {};
    check_hresult(shim()->get_ServiceSolicitation128BitUuids(&value));
    return value;
}

template <typename D> uint8_t impl_IBluetoothLEAdvertisementDataTypesStatics<D>::ServiceData16BitUuids() const
{
    uint8_t value {};
    check_hresult(shim()->get_ServiceData16BitUuids(&value));
    return value;
}

template <typename D> uint8_t impl_IBluetoothLEAdvertisementDataTypesStatics<D>::ServiceData32BitUuids() const
{
    uint8_t value {};
    check_hresult(shim()->get_ServiceData32BitUuids(&value));
    return value;
}

template <typename D> uint8_t impl_IBluetoothLEAdvertisementDataTypesStatics<D>::ServiceData128BitUuids() const
{
    uint8_t value {};
    check_hresult(shim()->get_ServiceData128BitUuids(&value));
    return value;
}

template <typename D> uint8_t impl_IBluetoothLEAdvertisementDataTypesStatics<D>::PublicTargetAddress() const
{
    uint8_t value {};
    check_hresult(shim()->get_PublicTargetAddress(&value));
    return value;
}

template <typename D> uint8_t impl_IBluetoothLEAdvertisementDataTypesStatics<D>::RandomTargetAddress() const
{
    uint8_t value {};
    check_hresult(shim()->get_RandomTargetAddress(&value));
    return value;
}

template <typename D> uint8_t impl_IBluetoothLEAdvertisementDataTypesStatics<D>::Appearance() const
{
    uint8_t value {};
    check_hresult(shim()->get_Appearance(&value));
    return value;
}

template <typename D> uint8_t impl_IBluetoothLEAdvertisementDataTypesStatics<D>::AdvertisingInterval() const
{
    uint8_t value {};
    check_hresult(shim()->get_AdvertisingInterval(&value));
    return value;
}

template <typename D> uint8_t impl_IBluetoothLEAdvertisementDataTypesStatics<D>::ManufacturerSpecificData() const
{
    uint8_t value {};
    check_hresult(shim()->get_ManufacturerSpecificData(&value));
    return value;
}

template <typename D> Windows::Devices::Bluetooth::Advertisement::BluetoothLEAdvertisementPublisherStatus impl_IBluetoothLEAdvertisementPublisherStatusChangedEventArgs<D>::Status() const
{
    Windows::Devices::Bluetooth::Advertisement::BluetoothLEAdvertisementPublisherStatus value {};
    check_hresult(shim()->get_Status(&value));
    return value;
}

template <typename D> Windows::Devices::Bluetooth::BluetoothError impl_IBluetoothLEAdvertisementPublisherStatusChangedEventArgs<D>::Error() const
{
    Windows::Devices::Bluetooth::BluetoothError value {};
    check_hresult(shim()->get_Error(&value));
    return value;
}

template <typename D> Windows::Devices::Bluetooth::Advertisement::BluetoothLEAdvertisementPublisher impl_IBluetoothLEAdvertisementPublisherFactory<D>::Create(const Windows::Devices::Bluetooth::Advertisement::BluetoothLEAdvertisement & advertisement) const
{
    Windows::Devices::Bluetooth::Advertisement::BluetoothLEAdvertisementPublisher value { nullptr };
    check_hresult(shim()->abi_Create(get(advertisement), put(value)));
    return value;
}

template <typename D> Windows::Devices::Bluetooth::Advertisement::BluetoothLEAdvertisementPublisherStatus impl_IBluetoothLEAdvertisementPublisher<D>::Status() const
{
    Windows::Devices::Bluetooth::Advertisement::BluetoothLEAdvertisementPublisherStatus value {};
    check_hresult(shim()->get_Status(&value));
    return value;
}

template <typename D> Windows::Devices::Bluetooth::Advertisement::BluetoothLEAdvertisement impl_IBluetoothLEAdvertisementPublisher<D>::Advertisement() const
{
    Windows::Devices::Bluetooth::Advertisement::BluetoothLEAdvertisement value { nullptr };
    check_hresult(shim()->get_Advertisement(put(value)));
    return value;
}

template <typename D> void impl_IBluetoothLEAdvertisementPublisher<D>::Start() const
{
    check_hresult(shim()->abi_Start());
}

template <typename D> void impl_IBluetoothLEAdvertisementPublisher<D>::Stop() const
{
    check_hresult(shim()->abi_Stop());
}

template <typename D> event_token impl_IBluetoothLEAdvertisementPublisher<D>::StatusChanged(const Windows::Foundation::TypedEventHandler<Windows::Devices::Bluetooth::Advertisement::BluetoothLEAdvertisementPublisher, Windows::Devices::Bluetooth::Advertisement::BluetoothLEAdvertisementPublisherStatusChangedEventArgs> & handler) const
{
    event_token token {};
    check_hresult(shim()->add_StatusChanged(get(handler), &token));
    return token;
}

template <typename D> event_revoker<IBluetoothLEAdvertisementPublisher> impl_IBluetoothLEAdvertisementPublisher<D>::StatusChanged(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Devices::Bluetooth::Advertisement::BluetoothLEAdvertisementPublisher, Windows::Devices::Bluetooth::Advertisement::BluetoothLEAdvertisementPublisherStatusChangedEventArgs> & handler) const
{
    return impl::make_event_revoker<D, IBluetoothLEAdvertisementPublisher>(this, &ABI::Windows::Devices::Bluetooth::Advertisement::IBluetoothLEAdvertisementPublisher::remove_StatusChanged, StatusChanged(handler));
}

template <typename D> void impl_IBluetoothLEAdvertisementPublisher<D>::StatusChanged(event_token token) const
{
    check_hresult(shim()->remove_StatusChanged(token));
}

inline BluetoothLEAdvertisement::BluetoothLEAdvertisement() :
    BluetoothLEAdvertisement(ActivateInstance<BluetoothLEAdvertisement>())
{}

inline BluetoothLEAdvertisementBytePattern::BluetoothLEAdvertisementBytePattern() :
    BluetoothLEAdvertisementBytePattern(ActivateInstance<BluetoothLEAdvertisementBytePattern>())
{}

inline BluetoothLEAdvertisementBytePattern::BluetoothLEAdvertisementBytePattern(uint8_t dataType, int16_t offset, const Windows::Storage::Streams::IBuffer & data) :
    BluetoothLEAdvertisementBytePattern(GetActivationFactory<BluetoothLEAdvertisementBytePattern, IBluetoothLEAdvertisementBytePatternFactory>().Create(dataType, offset, data))
{}

inline BluetoothLEAdvertisementDataSection::BluetoothLEAdvertisementDataSection() :
    BluetoothLEAdvertisementDataSection(ActivateInstance<BluetoothLEAdvertisementDataSection>())
{}

inline BluetoothLEAdvertisementDataSection::BluetoothLEAdvertisementDataSection(uint8_t dataType, const Windows::Storage::Streams::IBuffer & data) :
    BluetoothLEAdvertisementDataSection(GetActivationFactory<BluetoothLEAdvertisementDataSection, IBluetoothLEAdvertisementDataSectionFactory>().Create(dataType, data))
{}

inline uint8_t BluetoothLEAdvertisementDataTypes::Flags()
{
    return GetActivationFactory<BluetoothLEAdvertisementDataTypes, IBluetoothLEAdvertisementDataTypesStatics>().Flags();
}

inline uint8_t BluetoothLEAdvertisementDataTypes::IncompleteService16BitUuids()
{
    return GetActivationFactory<BluetoothLEAdvertisementDataTypes, IBluetoothLEAdvertisementDataTypesStatics>().IncompleteService16BitUuids();
}

inline uint8_t BluetoothLEAdvertisementDataTypes::CompleteService16BitUuids()
{
    return GetActivationFactory<BluetoothLEAdvertisementDataTypes, IBluetoothLEAdvertisementDataTypesStatics>().CompleteService16BitUuids();
}

inline uint8_t BluetoothLEAdvertisementDataTypes::IncompleteService32BitUuids()
{
    return GetActivationFactory<BluetoothLEAdvertisementDataTypes, IBluetoothLEAdvertisementDataTypesStatics>().IncompleteService32BitUuids();
}

inline uint8_t BluetoothLEAdvertisementDataTypes::CompleteService32BitUuids()
{
    return GetActivationFactory<BluetoothLEAdvertisementDataTypes, IBluetoothLEAdvertisementDataTypesStatics>().CompleteService32BitUuids();
}

inline uint8_t BluetoothLEAdvertisementDataTypes::IncompleteService128BitUuids()
{
    return GetActivationFactory<BluetoothLEAdvertisementDataTypes, IBluetoothLEAdvertisementDataTypesStatics>().IncompleteService128BitUuids();
}

inline uint8_t BluetoothLEAdvertisementDataTypes::CompleteService128BitUuids()
{
    return GetActivationFactory<BluetoothLEAdvertisementDataTypes, IBluetoothLEAdvertisementDataTypesStatics>().CompleteService128BitUuids();
}

inline uint8_t BluetoothLEAdvertisementDataTypes::ShortenedLocalName()
{
    return GetActivationFactory<BluetoothLEAdvertisementDataTypes, IBluetoothLEAdvertisementDataTypesStatics>().ShortenedLocalName();
}

inline uint8_t BluetoothLEAdvertisementDataTypes::CompleteLocalName()
{
    return GetActivationFactory<BluetoothLEAdvertisementDataTypes, IBluetoothLEAdvertisementDataTypesStatics>().CompleteLocalName();
}

inline uint8_t BluetoothLEAdvertisementDataTypes::TxPowerLevel()
{
    return GetActivationFactory<BluetoothLEAdvertisementDataTypes, IBluetoothLEAdvertisementDataTypesStatics>().TxPowerLevel();
}

inline uint8_t BluetoothLEAdvertisementDataTypes::SlaveConnectionIntervalRange()
{
    return GetActivationFactory<BluetoothLEAdvertisementDataTypes, IBluetoothLEAdvertisementDataTypesStatics>().SlaveConnectionIntervalRange();
}

inline uint8_t BluetoothLEAdvertisementDataTypes::ServiceSolicitation16BitUuids()
{
    return GetActivationFactory<BluetoothLEAdvertisementDataTypes, IBluetoothLEAdvertisementDataTypesStatics>().ServiceSolicitation16BitUuids();
}

inline uint8_t BluetoothLEAdvertisementDataTypes::ServiceSolicitation32BitUuids()
{
    return GetActivationFactory<BluetoothLEAdvertisementDataTypes, IBluetoothLEAdvertisementDataTypesStatics>().ServiceSolicitation32BitUuids();
}

inline uint8_t BluetoothLEAdvertisementDataTypes::ServiceSolicitation128BitUuids()
{
    return GetActivationFactory<BluetoothLEAdvertisementDataTypes, IBluetoothLEAdvertisementDataTypesStatics>().ServiceSolicitation128BitUuids();
}

inline uint8_t BluetoothLEAdvertisementDataTypes::ServiceData16BitUuids()
{
    return GetActivationFactory<BluetoothLEAdvertisementDataTypes, IBluetoothLEAdvertisementDataTypesStatics>().ServiceData16BitUuids();
}

inline uint8_t BluetoothLEAdvertisementDataTypes::ServiceData32BitUuids()
{
    return GetActivationFactory<BluetoothLEAdvertisementDataTypes, IBluetoothLEAdvertisementDataTypesStatics>().ServiceData32BitUuids();
}

inline uint8_t BluetoothLEAdvertisementDataTypes::ServiceData128BitUuids()
{
    return GetActivationFactory<BluetoothLEAdvertisementDataTypes, IBluetoothLEAdvertisementDataTypesStatics>().ServiceData128BitUuids();
}

inline uint8_t BluetoothLEAdvertisementDataTypes::PublicTargetAddress()
{
    return GetActivationFactory<BluetoothLEAdvertisementDataTypes, IBluetoothLEAdvertisementDataTypesStatics>().PublicTargetAddress();
}

inline uint8_t BluetoothLEAdvertisementDataTypes::RandomTargetAddress()
{
    return GetActivationFactory<BluetoothLEAdvertisementDataTypes, IBluetoothLEAdvertisementDataTypesStatics>().RandomTargetAddress();
}

inline uint8_t BluetoothLEAdvertisementDataTypes::Appearance()
{
    return GetActivationFactory<BluetoothLEAdvertisementDataTypes, IBluetoothLEAdvertisementDataTypesStatics>().Appearance();
}

inline uint8_t BluetoothLEAdvertisementDataTypes::AdvertisingInterval()
{
    return GetActivationFactory<BluetoothLEAdvertisementDataTypes, IBluetoothLEAdvertisementDataTypesStatics>().AdvertisingInterval();
}

inline uint8_t BluetoothLEAdvertisementDataTypes::ManufacturerSpecificData()
{
    return GetActivationFactory<BluetoothLEAdvertisementDataTypes, IBluetoothLEAdvertisementDataTypesStatics>().ManufacturerSpecificData();
}

inline BluetoothLEAdvertisementFilter::BluetoothLEAdvertisementFilter() :
    BluetoothLEAdvertisementFilter(ActivateInstance<BluetoothLEAdvertisementFilter>())
{}

inline BluetoothLEAdvertisementPublisher::BluetoothLEAdvertisementPublisher() :
    BluetoothLEAdvertisementPublisher(ActivateInstance<BluetoothLEAdvertisementPublisher>())
{}

inline BluetoothLEAdvertisementPublisher::BluetoothLEAdvertisementPublisher(const Windows::Devices::Bluetooth::Advertisement::BluetoothLEAdvertisement & advertisement) :
    BluetoothLEAdvertisementPublisher(GetActivationFactory<BluetoothLEAdvertisementPublisher, IBluetoothLEAdvertisementPublisherFactory>().Create(advertisement))
{}

inline BluetoothLEAdvertisementWatcher::BluetoothLEAdvertisementWatcher() :
    BluetoothLEAdvertisementWatcher(ActivateInstance<BluetoothLEAdvertisementWatcher>())
{}

inline BluetoothLEAdvertisementWatcher::BluetoothLEAdvertisementWatcher(const Windows::Devices::Bluetooth::Advertisement::BluetoothLEAdvertisementFilter & advertisementFilter) :
    BluetoothLEAdvertisementWatcher(GetActivationFactory<BluetoothLEAdvertisementWatcher, IBluetoothLEAdvertisementWatcherFactory>().Create(advertisementFilter))
{}

inline BluetoothLEManufacturerData::BluetoothLEManufacturerData() :
    BluetoothLEManufacturerData(ActivateInstance<BluetoothLEManufacturerData>())
{}

inline BluetoothLEManufacturerData::BluetoothLEManufacturerData(uint16_t companyId, const Windows::Storage::Streams::IBuffer & data) :
    BluetoothLEManufacturerData(GetActivationFactory<BluetoothLEManufacturerData, IBluetoothLEManufacturerDataFactory>().Create(companyId, data))
{}

}

}
