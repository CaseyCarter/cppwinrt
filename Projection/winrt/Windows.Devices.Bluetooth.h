// C++ for the Windows Runtime v1.29
// Copyright (c) 2016 Microsoft Corporation

#pragma once

#include "internal\Windows.Foundation.class.h"
#include "internal\Windows.Networking.class.h"
#include "internal\Windows.Foundation.Collections.class.h"
#include "internal\Windows.Devices.Enumeration.class.h"
#include "internal\Windows.Devices.Bluetooth.Rfcomm.class.h"
#include "internal\Windows.Devices.Bluetooth.GenericAttributeProfile.class.h"
#include "internal\Windows.Devices.Bluetooth.class.h"
#include "Windows.Devices.h"

WINRT_EXPORT namespace winrt {

namespace impl {

template <typename D>
struct produce<D, Windows::Devices::Bluetooth::IBluetoothClassOfDevice> : produce_base<D, Windows::Devices::Bluetooth::IBluetoothClassOfDevice>
{
    HRESULT __stdcall get_RawValue(uint32_t * value) noexcept override
    {
        try
        {
            *value = detach(shim().RawValue());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_MajorClass(Windows::Devices::Bluetooth::BluetoothMajorClass * value) noexcept override
    {
        try
        {
            *value = detach(shim().MajorClass());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_MinorClass(Windows::Devices::Bluetooth::BluetoothMinorClass * value) noexcept override
    {
        try
        {
            *value = detach(shim().MinorClass());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ServiceCapabilities(Windows::Devices::Bluetooth::BluetoothServiceCapabilities * value) noexcept override
    {
        try
        {
            *value = detach(shim().ServiceCapabilities());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Devices::Bluetooth::IBluetoothClassOfDeviceStatics> : produce_base<D, Windows::Devices::Bluetooth::IBluetoothClassOfDeviceStatics>
{
    HRESULT __stdcall abi_FromRawValue(uint32_t rawValue, abi_arg_out<Windows::Devices::Bluetooth::IBluetoothClassOfDevice> classOfDevice) noexcept override
    {
        try
        {
            *classOfDevice = detach(shim().FromRawValue(rawValue));
            return S_OK;
        }
        catch (...)
        {
            *classOfDevice = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_FromParts(Windows::Devices::Bluetooth::BluetoothMajorClass majorClass, Windows::Devices::Bluetooth::BluetoothMinorClass minorClass, Windows::Devices::Bluetooth::BluetoothServiceCapabilities serviceCapabilities, abi_arg_out<Windows::Devices::Bluetooth::IBluetoothClassOfDevice> classOfDevice) noexcept override
    {
        try
        {
            *classOfDevice = detach(shim().FromParts(majorClass, minorClass, serviceCapabilities));
            return S_OK;
        }
        catch (...)
        {
            *classOfDevice = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Devices::Bluetooth::IBluetoothDevice> : produce_base<D, Windows::Devices::Bluetooth::IBluetoothDevice>
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

    HRESULT __stdcall get_HostName(abi_arg_out<Windows::Networking::IHostName> value) noexcept override
    {
        try
        {
            *value = detach(shim().HostName());
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

    HRESULT __stdcall get_ClassOfDevice(abi_arg_out<Windows::Devices::Bluetooth::IBluetoothClassOfDevice> value) noexcept override
    {
        try
        {
            *value = detach(shim().ClassOfDevice());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_SdpRecords(abi_arg_out<Windows::Foundation::Collections::IVectorView<Windows::Storage::Streams::IBuffer>> value) noexcept override
    {
        try
        {
            *value = detach(shim().SdpRecords());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_RfcommServices(abi_arg_out<Windows::Foundation::Collections::IVectorView<Windows::Devices::Bluetooth::Rfcomm::RfcommDeviceService>> value) noexcept override
    {
        try
        {
            *value = detach(shim().RfcommServices());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ConnectionStatus(Windows::Devices::Bluetooth::BluetoothConnectionStatus * value) noexcept override
    {
        try
        {
            *value = detach(shim().ConnectionStatus());
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

    HRESULT __stdcall add_NameChanged(abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::Devices::Bluetooth::BluetoothDevice, Windows::IInspectable>> handler, event_token * token) noexcept override
    {
        try
        {
            *token = detach(shim().NameChanged(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::Devices::Bluetooth::BluetoothDevice, Windows::IInspectable> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_NameChanged(event_token token) noexcept override
    {
        try
        {
            shim().NameChanged(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_SdpRecordsChanged(abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::Devices::Bluetooth::BluetoothDevice, Windows::IInspectable>> handler, event_token * token) noexcept override
    {
        try
        {
            *token = detach(shim().SdpRecordsChanged(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::Devices::Bluetooth::BluetoothDevice, Windows::IInspectable> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_SdpRecordsChanged(event_token token) noexcept override
    {
        try
        {
            shim().SdpRecordsChanged(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_ConnectionStatusChanged(abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::Devices::Bluetooth::BluetoothDevice, Windows::IInspectable>> handler, event_token * token) noexcept override
    {
        try
        {
            *token = detach(shim().ConnectionStatusChanged(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::Devices::Bluetooth::BluetoothDevice, Windows::IInspectable> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_ConnectionStatusChanged(event_token token) noexcept override
    {
        try
        {
            shim().ConnectionStatusChanged(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Devices::Bluetooth::IBluetoothDevice2> : produce_base<D, Windows::Devices::Bluetooth::IBluetoothDevice2>
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
};

template <typename D>
struct produce<D, Windows::Devices::Bluetooth::IBluetoothDevice3> : produce_base<D, Windows::Devices::Bluetooth::IBluetoothDevice3>
{
    HRESULT __stdcall get_DeviceAccessInformation(abi_arg_out<Windows::Devices::Enumeration::IDeviceAccessInformation> value) noexcept override
    {
        try
        {
            *value = detach(shim().DeviceAccessInformation());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_RequestAccessAsync(abi_arg_out<Windows::Foundation::IAsyncOperation<winrt::Windows::Devices::Enumeration::DeviceAccessStatus>> value) noexcept override
    {
        try
        {
            *value = detach(shim().RequestAccessAsync());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetRfcommServicesAsync(abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Devices::Bluetooth::Rfcomm::RfcommDeviceServicesResult>> operation) noexcept override
    {
        try
        {
            *operation = detach(shim().GetRfcommServicesAsync());
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetRfcommServicesWithCacheModeAsync(Windows::Devices::Bluetooth::BluetoothCacheMode cacheMode, abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Devices::Bluetooth::Rfcomm::RfcommDeviceServicesResult>> operation) noexcept override
    {
        try
        {
            *operation = detach(shim().GetRfcommServicesAsync(cacheMode));
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetRfcommServicesForIdAsync(abi_arg_in<Windows::Devices::Bluetooth::Rfcomm::IRfcommServiceId> serviceId, abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Devices::Bluetooth::Rfcomm::RfcommDeviceServicesResult>> operation) noexcept override
    {
        try
        {
            *operation = detach(shim().GetRfcommServicesForIdAsync(*reinterpret_cast<const Windows::Devices::Bluetooth::Rfcomm::RfcommServiceId *>(&serviceId)));
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetRfcommServicesForIdWithCacheModeAsync(abi_arg_in<Windows::Devices::Bluetooth::Rfcomm::IRfcommServiceId> serviceId, Windows::Devices::Bluetooth::BluetoothCacheMode cacheMode, abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Devices::Bluetooth::Rfcomm::RfcommDeviceServicesResult>> operation) noexcept override
    {
        try
        {
            *operation = detach(shim().GetRfcommServicesForIdAsync(*reinterpret_cast<const Windows::Devices::Bluetooth::Rfcomm::RfcommServiceId *>(&serviceId), cacheMode));
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
struct produce<D, Windows::Devices::Bluetooth::IBluetoothDeviceStatics> : produce_base<D, Windows::Devices::Bluetooth::IBluetoothDeviceStatics>
{
    HRESULT __stdcall abi_FromIdAsync(abi_arg_in<hstring> deviceId, abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Devices::Bluetooth::BluetoothDevice>> operation) noexcept override
    {
        try
        {
            *operation = detach(shim().FromIdAsync(*reinterpret_cast<const hstring *>(&deviceId)));
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_FromHostNameAsync(abi_arg_in<Windows::Networking::IHostName> hostName, abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Devices::Bluetooth::BluetoothDevice>> operation) noexcept override
    {
        try
        {
            *operation = detach(shim().FromHostNameAsync(*reinterpret_cast<const Windows::Networking::HostName *>(&hostName)));
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_FromBluetoothAddressAsync(uint64_t address, abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Devices::Bluetooth::BluetoothDevice>> operation) noexcept override
    {
        try
        {
            *operation = detach(shim().FromBluetoothAddressAsync(address));
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetDeviceSelector(abi_arg_out<hstring> deviceSelector) noexcept override
    {
        try
        {
            *deviceSelector = detach(shim().GetDeviceSelector());
            return S_OK;
        }
        catch (...)
        {
            *deviceSelector = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Devices::Bluetooth::IBluetoothDeviceStatics2> : produce_base<D, Windows::Devices::Bluetooth::IBluetoothDeviceStatics2>
{
    HRESULT __stdcall abi_GetDeviceSelectorFromPairingState(bool pairingState, abi_arg_out<hstring> deviceSelector) noexcept override
    {
        try
        {
            *deviceSelector = detach(shim().GetDeviceSelectorFromPairingState(pairingState));
            return S_OK;
        }
        catch (...)
        {
            *deviceSelector = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetDeviceSelectorFromConnectionStatus(Windows::Devices::Bluetooth::BluetoothConnectionStatus connectionStatus, abi_arg_out<hstring> deviceSelector) noexcept override
    {
        try
        {
            *deviceSelector = detach(shim().GetDeviceSelectorFromConnectionStatus(connectionStatus));
            return S_OK;
        }
        catch (...)
        {
            *deviceSelector = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetDeviceSelectorFromDeviceName(abi_arg_in<hstring> deviceName, abi_arg_out<hstring> deviceSelector) noexcept override
    {
        try
        {
            *deviceSelector = detach(shim().GetDeviceSelectorFromDeviceName(*reinterpret_cast<const hstring *>(&deviceName)));
            return S_OK;
        }
        catch (...)
        {
            *deviceSelector = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetDeviceSelectorFromBluetoothAddress(uint64_t bluetoothAddress, abi_arg_out<hstring> deviceSelector) noexcept override
    {
        try
        {
            *deviceSelector = detach(shim().GetDeviceSelectorFromBluetoothAddress(bluetoothAddress));
            return S_OK;
        }
        catch (...)
        {
            *deviceSelector = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetDeviceSelectorFromClassOfDevice(abi_arg_in<Windows::Devices::Bluetooth::IBluetoothClassOfDevice> classOfDevice, abi_arg_out<hstring> deviceSelector) noexcept override
    {
        try
        {
            *deviceSelector = detach(shim().GetDeviceSelectorFromClassOfDevice(*reinterpret_cast<const Windows::Devices::Bluetooth::BluetoothClassOfDevice *>(&classOfDevice)));
            return S_OK;
        }
        catch (...)
        {
            *deviceSelector = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Devices::Bluetooth::IBluetoothLEAppearance> : produce_base<D, Windows::Devices::Bluetooth::IBluetoothLEAppearance>
{
    HRESULT __stdcall get_RawValue(uint16_t * value) noexcept override
    {
        try
        {
            *value = detach(shim().RawValue());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Category(uint16_t * value) noexcept override
    {
        try
        {
            *value = detach(shim().Category());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_SubCategory(uint16_t * value) noexcept override
    {
        try
        {
            *value = detach(shim().SubCategory());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Devices::Bluetooth::IBluetoothLEAppearanceCategoriesStatics> : produce_base<D, Windows::Devices::Bluetooth::IBluetoothLEAppearanceCategoriesStatics>
{
    HRESULT __stdcall get_Uncategorized(uint16_t * value) noexcept override
    {
        try
        {
            *value = detach(shim().Uncategorized());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Phone(uint16_t * value) noexcept override
    {
        try
        {
            *value = detach(shim().Phone());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Computer(uint16_t * value) noexcept override
    {
        try
        {
            *value = detach(shim().Computer());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Watch(uint16_t * value) noexcept override
    {
        try
        {
            *value = detach(shim().Watch());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Clock(uint16_t * value) noexcept override
    {
        try
        {
            *value = detach(shim().Clock());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Display(uint16_t * value) noexcept override
    {
        try
        {
            *value = detach(shim().Display());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_RemoteControl(uint16_t * value) noexcept override
    {
        try
        {
            *value = detach(shim().RemoteControl());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_EyeGlasses(uint16_t * value) noexcept override
    {
        try
        {
            *value = detach(shim().EyeGlasses());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Tag(uint16_t * value) noexcept override
    {
        try
        {
            *value = detach(shim().Tag());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Keyring(uint16_t * value) noexcept override
    {
        try
        {
            *value = detach(shim().Keyring());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_MediaPlayer(uint16_t * value) noexcept override
    {
        try
        {
            *value = detach(shim().MediaPlayer());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_BarcodeScanner(uint16_t * value) noexcept override
    {
        try
        {
            *value = detach(shim().BarcodeScanner());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Thermometer(uint16_t * value) noexcept override
    {
        try
        {
            *value = detach(shim().Thermometer());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_HeartRate(uint16_t * value) noexcept override
    {
        try
        {
            *value = detach(shim().HeartRate());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_BloodPressure(uint16_t * value) noexcept override
    {
        try
        {
            *value = detach(shim().BloodPressure());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_HumanInterfaceDevice(uint16_t * value) noexcept override
    {
        try
        {
            *value = detach(shim().HumanInterfaceDevice());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_GlucoseMeter(uint16_t * value) noexcept override
    {
        try
        {
            *value = detach(shim().GlucoseMeter());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_RunningWalking(uint16_t * value) noexcept override
    {
        try
        {
            *value = detach(shim().RunningWalking());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Cycling(uint16_t * value) noexcept override
    {
        try
        {
            *value = detach(shim().Cycling());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_PulseOximeter(uint16_t * value) noexcept override
    {
        try
        {
            *value = detach(shim().PulseOximeter());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_WeightScale(uint16_t * value) noexcept override
    {
        try
        {
            *value = detach(shim().WeightScale());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_OutdoorSportActivity(uint16_t * value) noexcept override
    {
        try
        {
            *value = detach(shim().OutdoorSportActivity());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Devices::Bluetooth::IBluetoothLEAppearanceStatics> : produce_base<D, Windows::Devices::Bluetooth::IBluetoothLEAppearanceStatics>
{
    HRESULT __stdcall abi_FromRawValue(uint16_t rawValue, abi_arg_out<Windows::Devices::Bluetooth::IBluetoothLEAppearance> appearance) noexcept override
    {
        try
        {
            *appearance = detach(shim().FromRawValue(rawValue));
            return S_OK;
        }
        catch (...)
        {
            *appearance = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_FromParts(uint16_t appearanceCategory, uint16_t appearanceSubCategory, abi_arg_out<Windows::Devices::Bluetooth::IBluetoothLEAppearance> appearance) noexcept override
    {
        try
        {
            *appearance = detach(shim().FromParts(appearanceCategory, appearanceSubCategory));
            return S_OK;
        }
        catch (...)
        {
            *appearance = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Devices::Bluetooth::IBluetoothLEAppearanceSubcategoriesStatics> : produce_base<D, Windows::Devices::Bluetooth::IBluetoothLEAppearanceSubcategoriesStatics>
{
    HRESULT __stdcall get_Generic(uint16_t * value) noexcept override
    {
        try
        {
            *value = detach(shim().Generic());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_SportsWatch(uint16_t * value) noexcept override
    {
        try
        {
            *value = detach(shim().SportsWatch());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ThermometerEar(uint16_t * value) noexcept override
    {
        try
        {
            *value = detach(shim().ThermometerEar());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_HeartRateBelt(uint16_t * value) noexcept override
    {
        try
        {
            *value = detach(shim().HeartRateBelt());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_BloodPressureArm(uint16_t * value) noexcept override
    {
        try
        {
            *value = detach(shim().BloodPressureArm());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_BloodPressureWrist(uint16_t * value) noexcept override
    {
        try
        {
            *value = detach(shim().BloodPressureWrist());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Keyboard(uint16_t * value) noexcept override
    {
        try
        {
            *value = detach(shim().Keyboard());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Mouse(uint16_t * value) noexcept override
    {
        try
        {
            *value = detach(shim().Mouse());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Joystick(uint16_t * value) noexcept override
    {
        try
        {
            *value = detach(shim().Joystick());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Gamepad(uint16_t * value) noexcept override
    {
        try
        {
            *value = detach(shim().Gamepad());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_DigitizerTablet(uint16_t * value) noexcept override
    {
        try
        {
            *value = detach(shim().DigitizerTablet());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_CardReader(uint16_t * value) noexcept override
    {
        try
        {
            *value = detach(shim().CardReader());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_DigitalPen(uint16_t * value) noexcept override
    {
        try
        {
            *value = detach(shim().DigitalPen());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_BarcodeScanner(uint16_t * value) noexcept override
    {
        try
        {
            *value = detach(shim().BarcodeScanner());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_RunningWalkingInShoe(uint16_t * value) noexcept override
    {
        try
        {
            *value = detach(shim().RunningWalkingInShoe());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_RunningWalkingOnShoe(uint16_t * value) noexcept override
    {
        try
        {
            *value = detach(shim().RunningWalkingOnShoe());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_RunningWalkingOnHip(uint16_t * value) noexcept override
    {
        try
        {
            *value = detach(shim().RunningWalkingOnHip());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_CyclingComputer(uint16_t * value) noexcept override
    {
        try
        {
            *value = detach(shim().CyclingComputer());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_CyclingSpeedSensor(uint16_t * value) noexcept override
    {
        try
        {
            *value = detach(shim().CyclingSpeedSensor());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_CyclingCadenceSensor(uint16_t * value) noexcept override
    {
        try
        {
            *value = detach(shim().CyclingCadenceSensor());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_CyclingPowerSensor(uint16_t * value) noexcept override
    {
        try
        {
            *value = detach(shim().CyclingPowerSensor());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_CyclingSpeedCadenceSensor(uint16_t * value) noexcept override
    {
        try
        {
            *value = detach(shim().CyclingSpeedCadenceSensor());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_OximeterFingertip(uint16_t * value) noexcept override
    {
        try
        {
            *value = detach(shim().OximeterFingertip());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_OximeterWristWorn(uint16_t * value) noexcept override
    {
        try
        {
            *value = detach(shim().OximeterWristWorn());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_LocationDisplay(uint16_t * value) noexcept override
    {
        try
        {
            *value = detach(shim().LocationDisplay());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_LocationNavigationDisplay(uint16_t * value) noexcept override
    {
        try
        {
            *value = detach(shim().LocationNavigationDisplay());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_LocationPod(uint16_t * value) noexcept override
    {
        try
        {
            *value = detach(shim().LocationPod());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_LocationNavigationPod(uint16_t * value) noexcept override
    {
        try
        {
            *value = detach(shim().LocationNavigationPod());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Devices::Bluetooth::IBluetoothLEDevice> : produce_base<D, Windows::Devices::Bluetooth::IBluetoothLEDevice>
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

    HRESULT __stdcall get_GattServices(abi_arg_out<Windows::Foundation::Collections::IVectorView<Windows::Devices::Bluetooth::GenericAttributeProfile::GattDeviceService>> value) noexcept override
    {
        try
        {
            *value = detach(shim().GattServices());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ConnectionStatus(Windows::Devices::Bluetooth::BluetoothConnectionStatus * value) noexcept override
    {
        try
        {
            *value = detach(shim().ConnectionStatus());
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

    HRESULT __stdcall abi_GetGattService(GUID serviceUuid, abi_arg_out<Windows::Devices::Bluetooth::GenericAttributeProfile::IGattDeviceService> service) noexcept override
    {
        try
        {
            *service = detach(shim().GetGattService(serviceUuid));
            return S_OK;
        }
        catch (...)
        {
            *service = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_NameChanged(abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::Devices::Bluetooth::BluetoothLEDevice, Windows::IInspectable>> handler, event_token * token) noexcept override
    {
        try
        {
            *token = detach(shim().NameChanged(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::Devices::Bluetooth::BluetoothLEDevice, Windows::IInspectable> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_NameChanged(event_token token) noexcept override
    {
        try
        {
            shim().NameChanged(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_GattServicesChanged(abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::Devices::Bluetooth::BluetoothLEDevice, Windows::IInspectable>> handler, event_token * token) noexcept override
    {
        try
        {
            *token = detach(shim().GattServicesChanged(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::Devices::Bluetooth::BluetoothLEDevice, Windows::IInspectable> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_GattServicesChanged(event_token token) noexcept override
    {
        try
        {
            shim().GattServicesChanged(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_ConnectionStatusChanged(abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::Devices::Bluetooth::BluetoothLEDevice, Windows::IInspectable>> handler, event_token * token) noexcept override
    {
        try
        {
            *token = detach(shim().ConnectionStatusChanged(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::Devices::Bluetooth::BluetoothLEDevice, Windows::IInspectable> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_ConnectionStatusChanged(event_token token) noexcept override
    {
        try
        {
            shim().ConnectionStatusChanged(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Devices::Bluetooth::IBluetoothLEDevice2> : produce_base<D, Windows::Devices::Bluetooth::IBluetoothLEDevice2>
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

    HRESULT __stdcall get_Appearance(abi_arg_out<Windows::Devices::Bluetooth::IBluetoothLEAppearance> value) noexcept override
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

    HRESULT __stdcall get_BluetoothAddressType(Windows::Devices::Bluetooth::BluetoothAddressType * value) noexcept override
    {
        try
        {
            *value = detach(shim().BluetoothAddressType());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Devices::Bluetooth::IBluetoothLEDeviceStatics> : produce_base<D, Windows::Devices::Bluetooth::IBluetoothLEDeviceStatics>
{
    HRESULT __stdcall abi_FromIdAsync(abi_arg_in<hstring> deviceId, abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Devices::Bluetooth::BluetoothLEDevice>> operation) noexcept override
    {
        try
        {
            *operation = detach(shim().FromIdAsync(*reinterpret_cast<const hstring *>(&deviceId)));
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_FromBluetoothAddressAsync(uint64_t bluetoothAddress, abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Devices::Bluetooth::BluetoothLEDevice>> operation) noexcept override
    {
        try
        {
            *operation = detach(shim().FromBluetoothAddressAsync(bluetoothAddress));
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetDeviceSelector(abi_arg_out<hstring> deviceSelector) noexcept override
    {
        try
        {
            *deviceSelector = detach(shim().GetDeviceSelector());
            return S_OK;
        }
        catch (...)
        {
            *deviceSelector = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Devices::Bluetooth::IBluetoothLEDeviceStatics2> : produce_base<D, Windows::Devices::Bluetooth::IBluetoothLEDeviceStatics2>
{
    HRESULT __stdcall abi_GetDeviceSelectorFromPairingState(bool pairingState, abi_arg_out<hstring> deviceSelector) noexcept override
    {
        try
        {
            *deviceSelector = detach(shim().GetDeviceSelectorFromPairingState(pairingState));
            return S_OK;
        }
        catch (...)
        {
            *deviceSelector = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetDeviceSelectorFromConnectionStatus(Windows::Devices::Bluetooth::BluetoothConnectionStatus connectionStatus, abi_arg_out<hstring> deviceSelector) noexcept override
    {
        try
        {
            *deviceSelector = detach(shim().GetDeviceSelectorFromConnectionStatus(connectionStatus));
            return S_OK;
        }
        catch (...)
        {
            *deviceSelector = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetDeviceSelectorFromDeviceName(abi_arg_in<hstring> deviceName, abi_arg_out<hstring> deviceSelector) noexcept override
    {
        try
        {
            *deviceSelector = detach(shim().GetDeviceSelectorFromDeviceName(*reinterpret_cast<const hstring *>(&deviceName)));
            return S_OK;
        }
        catch (...)
        {
            *deviceSelector = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetDeviceSelectorFromBluetoothAddress(uint64_t bluetoothAddress, abi_arg_out<hstring> deviceSelector) noexcept override
    {
        try
        {
            *deviceSelector = detach(shim().GetDeviceSelectorFromBluetoothAddress(bluetoothAddress));
            return S_OK;
        }
        catch (...)
        {
            *deviceSelector = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetDeviceSelectorFromBluetoothAddressWithBluetoothAddressType(uint64_t bluetoothAddress, Windows::Devices::Bluetooth::BluetoothAddressType bluetoothAddressType, abi_arg_out<hstring> deviceSelector) noexcept override
    {
        try
        {
            *deviceSelector = detach(shim().GetDeviceSelectorFromBluetoothAddress(bluetoothAddress, bluetoothAddressType));
            return S_OK;
        }
        catch (...)
        {
            *deviceSelector = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetDeviceSelectorFromAppearance(abi_arg_in<Windows::Devices::Bluetooth::IBluetoothLEAppearance> appearance, abi_arg_out<hstring> deviceSelector) noexcept override
    {
        try
        {
            *deviceSelector = detach(shim().GetDeviceSelectorFromAppearance(*reinterpret_cast<const Windows::Devices::Bluetooth::BluetoothLEAppearance *>(&appearance)));
            return S_OK;
        }
        catch (...)
        {
            *deviceSelector = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_FromBluetoothAddressWithBluetoothAddressTypeAsync(uint64_t bluetoothAddress, Windows::Devices::Bluetooth::BluetoothAddressType bluetoothAddressType, abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Devices::Bluetooth::BluetoothLEDevice>> operation) noexcept override
    {
        try
        {
            *operation = detach(shim().FromBluetoothAddressAsync(bluetoothAddress, bluetoothAddressType));
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
struct produce<D, Windows::Devices::Bluetooth::IBluetoothSignalStrengthFilter> : produce_base<D, Windows::Devices::Bluetooth::IBluetoothSignalStrengthFilter>
{
    HRESULT __stdcall get_InRangeThresholdInDBm(abi_arg_out<Windows::Foundation::IReference<int16_t>> value) noexcept override
    {
        try
        {
            *value = detach(shim().InRangeThresholdInDBm());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_InRangeThresholdInDBm(abi_arg_in<Windows::Foundation::IReference<int16_t>> value) noexcept override
    {
        try
        {
            shim().InRangeThresholdInDBm(*reinterpret_cast<const Windows::Foundation::IReference<int16_t> *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_OutOfRangeThresholdInDBm(abi_arg_out<Windows::Foundation::IReference<int16_t>> value) noexcept override
    {
        try
        {
            *value = detach(shim().OutOfRangeThresholdInDBm());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_OutOfRangeThresholdInDBm(abi_arg_in<Windows::Foundation::IReference<int16_t>> value) noexcept override
    {
        try
        {
            shim().OutOfRangeThresholdInDBm(*reinterpret_cast<const Windows::Foundation::IReference<int16_t> *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_OutOfRangeTimeout(abi_arg_out<Windows::Foundation::IReference<Windows::Foundation::TimeSpan>> value) noexcept override
    {
        try
        {
            *value = detach(shim().OutOfRangeTimeout());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_OutOfRangeTimeout(abi_arg_in<Windows::Foundation::IReference<Windows::Foundation::TimeSpan>> value) noexcept override
    {
        try
        {
            shim().OutOfRangeTimeout(*reinterpret_cast<const Windows::Foundation::IReference<Windows::Foundation::TimeSpan> *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_SamplingInterval(abi_arg_out<Windows::Foundation::IReference<Windows::Foundation::TimeSpan>> value) noexcept override
    {
        try
        {
            *value = detach(shim().SamplingInterval());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_SamplingInterval(abi_arg_in<Windows::Foundation::IReference<Windows::Foundation::TimeSpan>> value) noexcept override
    {
        try
        {
            shim().SamplingInterval(*reinterpret_cast<const Windows::Foundation::IReference<Windows::Foundation::TimeSpan> *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

}

namespace Windows::Devices::Bluetooth {

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Devices::Bluetooth::BluetoothDevice> impl_IBluetoothDeviceStatics<D>::FromIdAsync(hstring_ref deviceId) const
{
    Windows::Foundation::IAsyncOperation<Windows::Devices::Bluetooth::BluetoothDevice> operation;
    check_hresult(shim()->abi_FromIdAsync(get(deviceId), put(operation)));
    return operation;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Devices::Bluetooth::BluetoothDevice> impl_IBluetoothDeviceStatics<D>::FromHostNameAsync(const Windows::Networking::HostName & hostName) const
{
    Windows::Foundation::IAsyncOperation<Windows::Devices::Bluetooth::BluetoothDevice> operation;
    check_hresult(shim()->abi_FromHostNameAsync(get(hostName), put(operation)));
    return operation;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Devices::Bluetooth::BluetoothDevice> impl_IBluetoothDeviceStatics<D>::FromBluetoothAddressAsync(uint64_t address) const
{
    Windows::Foundation::IAsyncOperation<Windows::Devices::Bluetooth::BluetoothDevice> operation;
    check_hresult(shim()->abi_FromBluetoothAddressAsync(address, put(operation)));
    return operation;
}

template <typename D> hstring impl_IBluetoothDeviceStatics<D>::GetDeviceSelector() const
{
    hstring deviceSelector;
    check_hresult(shim()->abi_GetDeviceSelector(put(deviceSelector)));
    return deviceSelector;
}

template <typename D> hstring impl_IBluetoothDeviceStatics2<D>::GetDeviceSelectorFromPairingState(bool pairingState) const
{
    hstring deviceSelector;
    check_hresult(shim()->abi_GetDeviceSelectorFromPairingState(pairingState, put(deviceSelector)));
    return deviceSelector;
}

template <typename D> hstring impl_IBluetoothDeviceStatics2<D>::GetDeviceSelectorFromConnectionStatus(Windows::Devices::Bluetooth::BluetoothConnectionStatus connectionStatus) const
{
    hstring deviceSelector;
    check_hresult(shim()->abi_GetDeviceSelectorFromConnectionStatus(connectionStatus, put(deviceSelector)));
    return deviceSelector;
}

template <typename D> hstring impl_IBluetoothDeviceStatics2<D>::GetDeviceSelectorFromDeviceName(hstring_ref deviceName) const
{
    hstring deviceSelector;
    check_hresult(shim()->abi_GetDeviceSelectorFromDeviceName(get(deviceName), put(deviceSelector)));
    return deviceSelector;
}

template <typename D> hstring impl_IBluetoothDeviceStatics2<D>::GetDeviceSelectorFromBluetoothAddress(uint64_t bluetoothAddress) const
{
    hstring deviceSelector;
    check_hresult(shim()->abi_GetDeviceSelectorFromBluetoothAddress(bluetoothAddress, put(deviceSelector)));
    return deviceSelector;
}

template <typename D> hstring impl_IBluetoothDeviceStatics2<D>::GetDeviceSelectorFromClassOfDevice(const Windows::Devices::Bluetooth::BluetoothClassOfDevice & classOfDevice) const
{
    hstring deviceSelector;
    check_hresult(shim()->abi_GetDeviceSelectorFromClassOfDevice(get(classOfDevice), put(deviceSelector)));
    return deviceSelector;
}

template <typename D> hstring impl_IBluetoothDevice<D>::DeviceId() const
{
    hstring value;
    check_hresult(shim()->get_DeviceId(put(value)));
    return value;
}

template <typename D> Windows::Networking::HostName impl_IBluetoothDevice<D>::HostName() const
{
    Windows::Networking::HostName value { nullptr };
    check_hresult(shim()->get_HostName(put(value)));
    return value;
}

template <typename D> hstring impl_IBluetoothDevice<D>::Name() const
{
    hstring value;
    check_hresult(shim()->get_Name(put(value)));
    return value;
}

template <typename D> Windows::Devices::Bluetooth::BluetoothClassOfDevice impl_IBluetoothDevice<D>::ClassOfDevice() const
{
    Windows::Devices::Bluetooth::BluetoothClassOfDevice value { nullptr };
    check_hresult(shim()->get_ClassOfDevice(put(value)));
    return value;
}

template <typename D> Windows::Foundation::Collections::IVectorView<Windows::Storage::Streams::IBuffer> impl_IBluetoothDevice<D>::SdpRecords() const
{
    Windows::Foundation::Collections::IVectorView<Windows::Storage::Streams::IBuffer> value;
    check_hresult(shim()->get_SdpRecords(put(value)));
    return value;
}

template <typename D> Windows::Foundation::Collections::IVectorView<Windows::Devices::Bluetooth::Rfcomm::RfcommDeviceService> impl_IBluetoothDevice<D>::RfcommServices() const
{
    Windows::Foundation::Collections::IVectorView<Windows::Devices::Bluetooth::Rfcomm::RfcommDeviceService> value;
    check_hresult(shim()->get_RfcommServices(put(value)));
    return value;
}

template <typename D> Windows::Devices::Bluetooth::BluetoothConnectionStatus impl_IBluetoothDevice<D>::ConnectionStatus() const
{
    Windows::Devices::Bluetooth::BluetoothConnectionStatus value {};
    check_hresult(shim()->get_ConnectionStatus(&value));
    return value;
}

template <typename D> uint64_t impl_IBluetoothDevice<D>::BluetoothAddress() const
{
    uint64_t value {};
    check_hresult(shim()->get_BluetoothAddress(&value));
    return value;
}

template <typename D> event_token impl_IBluetoothDevice<D>::NameChanged(const Windows::Foundation::TypedEventHandler<Windows::Devices::Bluetooth::BluetoothDevice, Windows::IInspectable> & handler) const
{
    event_token token {};
    check_hresult(shim()->add_NameChanged(get(handler), &token));
    return token;
}

template <typename D> event_revoker<IBluetoothDevice> impl_IBluetoothDevice<D>::NameChanged(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Devices::Bluetooth::BluetoothDevice, Windows::IInspectable> & handler) const
{
    return impl::make_event_revoker<D, IBluetoothDevice>(this, &ABI::Windows::Devices::Bluetooth::IBluetoothDevice::remove_NameChanged, NameChanged(handler));
}

template <typename D> void impl_IBluetoothDevice<D>::NameChanged(event_token token) const
{
    check_hresult(shim()->remove_NameChanged(token));
}

template <typename D> event_token impl_IBluetoothDevice<D>::SdpRecordsChanged(const Windows::Foundation::TypedEventHandler<Windows::Devices::Bluetooth::BluetoothDevice, Windows::IInspectable> & handler) const
{
    event_token token {};
    check_hresult(shim()->add_SdpRecordsChanged(get(handler), &token));
    return token;
}

template <typename D> event_revoker<IBluetoothDevice> impl_IBluetoothDevice<D>::SdpRecordsChanged(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Devices::Bluetooth::BluetoothDevice, Windows::IInspectable> & handler) const
{
    return impl::make_event_revoker<D, IBluetoothDevice>(this, &ABI::Windows::Devices::Bluetooth::IBluetoothDevice::remove_SdpRecordsChanged, SdpRecordsChanged(handler));
}

template <typename D> void impl_IBluetoothDevice<D>::SdpRecordsChanged(event_token token) const
{
    check_hresult(shim()->remove_SdpRecordsChanged(token));
}

template <typename D> event_token impl_IBluetoothDevice<D>::ConnectionStatusChanged(const Windows::Foundation::TypedEventHandler<Windows::Devices::Bluetooth::BluetoothDevice, Windows::IInspectable> & handler) const
{
    event_token token {};
    check_hresult(shim()->add_ConnectionStatusChanged(get(handler), &token));
    return token;
}

template <typename D> event_revoker<IBluetoothDevice> impl_IBluetoothDevice<D>::ConnectionStatusChanged(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Devices::Bluetooth::BluetoothDevice, Windows::IInspectable> & handler) const
{
    return impl::make_event_revoker<D, IBluetoothDevice>(this, &ABI::Windows::Devices::Bluetooth::IBluetoothDevice::remove_ConnectionStatusChanged, ConnectionStatusChanged(handler));
}

template <typename D> void impl_IBluetoothDevice<D>::ConnectionStatusChanged(event_token token) const
{
    check_hresult(shim()->remove_ConnectionStatusChanged(token));
}

template <typename D> Windows::Devices::Enumeration::DeviceInformation impl_IBluetoothDevice2<D>::DeviceInformation() const
{
    Windows::Devices::Enumeration::DeviceInformation value { nullptr };
    check_hresult(shim()->get_DeviceInformation(put(value)));
    return value;
}

template <typename D> Windows::Devices::Enumeration::DeviceAccessInformation impl_IBluetoothDevice3<D>::DeviceAccessInformation() const
{
    Windows::Devices::Enumeration::DeviceAccessInformation value { nullptr };
    check_hresult(shim()->get_DeviceAccessInformation(put(value)));
    return value;
}

template <typename D> Windows::Foundation::IAsyncOperation<winrt::Windows::Devices::Enumeration::DeviceAccessStatus> impl_IBluetoothDevice3<D>::RequestAccessAsync() const
{
    Windows::Foundation::IAsyncOperation<winrt::Windows::Devices::Enumeration::DeviceAccessStatus> value;
    check_hresult(shim()->abi_RequestAccessAsync(put(value)));
    return value;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Devices::Bluetooth::Rfcomm::RfcommDeviceServicesResult> impl_IBluetoothDevice3<D>::GetRfcommServicesAsync() const
{
    Windows::Foundation::IAsyncOperation<Windows::Devices::Bluetooth::Rfcomm::RfcommDeviceServicesResult> operation;
    check_hresult(shim()->abi_GetRfcommServicesAsync(put(operation)));
    return operation;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Devices::Bluetooth::Rfcomm::RfcommDeviceServicesResult> impl_IBluetoothDevice3<D>::GetRfcommServicesAsync(Windows::Devices::Bluetooth::BluetoothCacheMode cacheMode) const
{
    Windows::Foundation::IAsyncOperation<Windows::Devices::Bluetooth::Rfcomm::RfcommDeviceServicesResult> operation;
    check_hresult(shim()->abi_GetRfcommServicesWithCacheModeAsync(cacheMode, put(operation)));
    return operation;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Devices::Bluetooth::Rfcomm::RfcommDeviceServicesResult> impl_IBluetoothDevice3<D>::GetRfcommServicesForIdAsync(const Windows::Devices::Bluetooth::Rfcomm::RfcommServiceId & serviceId) const
{
    Windows::Foundation::IAsyncOperation<Windows::Devices::Bluetooth::Rfcomm::RfcommDeviceServicesResult> operation;
    check_hresult(shim()->abi_GetRfcommServicesForIdAsync(get(serviceId), put(operation)));
    return operation;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Devices::Bluetooth::Rfcomm::RfcommDeviceServicesResult> impl_IBluetoothDevice3<D>::GetRfcommServicesForIdAsync(const Windows::Devices::Bluetooth::Rfcomm::RfcommServiceId & serviceId, Windows::Devices::Bluetooth::BluetoothCacheMode cacheMode) const
{
    Windows::Foundation::IAsyncOperation<Windows::Devices::Bluetooth::Rfcomm::RfcommDeviceServicesResult> operation;
    check_hresult(shim()->abi_GetRfcommServicesForIdWithCacheModeAsync(get(serviceId), cacheMode, put(operation)));
    return operation;
}

template <typename D> uint16_t impl_IBluetoothLEAppearanceCategoriesStatics<D>::Uncategorized() const
{
    uint16_t value {};
    check_hresult(shim()->get_Uncategorized(&value));
    return value;
}

template <typename D> uint16_t impl_IBluetoothLEAppearanceCategoriesStatics<D>::Phone() const
{
    uint16_t value {};
    check_hresult(shim()->get_Phone(&value));
    return value;
}

template <typename D> uint16_t impl_IBluetoothLEAppearanceCategoriesStatics<D>::Computer() const
{
    uint16_t value {};
    check_hresult(shim()->get_Computer(&value));
    return value;
}

template <typename D> uint16_t impl_IBluetoothLEAppearanceCategoriesStatics<D>::Watch() const
{
    uint16_t value {};
    check_hresult(shim()->get_Watch(&value));
    return value;
}

template <typename D> uint16_t impl_IBluetoothLEAppearanceCategoriesStatics<D>::Clock() const
{
    uint16_t value {};
    check_hresult(shim()->get_Clock(&value));
    return value;
}

template <typename D> uint16_t impl_IBluetoothLEAppearanceCategoriesStatics<D>::Display() const
{
    uint16_t value {};
    check_hresult(shim()->get_Display(&value));
    return value;
}

template <typename D> uint16_t impl_IBluetoothLEAppearanceCategoriesStatics<D>::RemoteControl() const
{
    uint16_t value {};
    check_hresult(shim()->get_RemoteControl(&value));
    return value;
}

template <typename D> uint16_t impl_IBluetoothLEAppearanceCategoriesStatics<D>::EyeGlasses() const
{
    uint16_t value {};
    check_hresult(shim()->get_EyeGlasses(&value));
    return value;
}

template <typename D> uint16_t impl_IBluetoothLEAppearanceCategoriesStatics<D>::Tag() const
{
    uint16_t value {};
    check_hresult(shim()->get_Tag(&value));
    return value;
}

template <typename D> uint16_t impl_IBluetoothLEAppearanceCategoriesStatics<D>::Keyring() const
{
    uint16_t value {};
    check_hresult(shim()->get_Keyring(&value));
    return value;
}

template <typename D> uint16_t impl_IBluetoothLEAppearanceCategoriesStatics<D>::MediaPlayer() const
{
    uint16_t value {};
    check_hresult(shim()->get_MediaPlayer(&value));
    return value;
}

template <typename D> uint16_t impl_IBluetoothLEAppearanceCategoriesStatics<D>::BarcodeScanner() const
{
    uint16_t value {};
    check_hresult(shim()->get_BarcodeScanner(&value));
    return value;
}

template <typename D> uint16_t impl_IBluetoothLEAppearanceCategoriesStatics<D>::Thermometer() const
{
    uint16_t value {};
    check_hresult(shim()->get_Thermometer(&value));
    return value;
}

template <typename D> uint16_t impl_IBluetoothLEAppearanceCategoriesStatics<D>::HeartRate() const
{
    uint16_t value {};
    check_hresult(shim()->get_HeartRate(&value));
    return value;
}

template <typename D> uint16_t impl_IBluetoothLEAppearanceCategoriesStatics<D>::BloodPressure() const
{
    uint16_t value {};
    check_hresult(shim()->get_BloodPressure(&value));
    return value;
}

template <typename D> uint16_t impl_IBluetoothLEAppearanceCategoriesStatics<D>::HumanInterfaceDevice() const
{
    uint16_t value {};
    check_hresult(shim()->get_HumanInterfaceDevice(&value));
    return value;
}

template <typename D> uint16_t impl_IBluetoothLEAppearanceCategoriesStatics<D>::GlucoseMeter() const
{
    uint16_t value {};
    check_hresult(shim()->get_GlucoseMeter(&value));
    return value;
}

template <typename D> uint16_t impl_IBluetoothLEAppearanceCategoriesStatics<D>::RunningWalking() const
{
    uint16_t value {};
    check_hresult(shim()->get_RunningWalking(&value));
    return value;
}

template <typename D> uint16_t impl_IBluetoothLEAppearanceCategoriesStatics<D>::Cycling() const
{
    uint16_t value {};
    check_hresult(shim()->get_Cycling(&value));
    return value;
}

template <typename D> uint16_t impl_IBluetoothLEAppearanceCategoriesStatics<D>::PulseOximeter() const
{
    uint16_t value {};
    check_hresult(shim()->get_PulseOximeter(&value));
    return value;
}

template <typename D> uint16_t impl_IBluetoothLEAppearanceCategoriesStatics<D>::WeightScale() const
{
    uint16_t value {};
    check_hresult(shim()->get_WeightScale(&value));
    return value;
}

template <typename D> uint16_t impl_IBluetoothLEAppearanceCategoriesStatics<D>::OutdoorSportActivity() const
{
    uint16_t value {};
    check_hresult(shim()->get_OutdoorSportActivity(&value));
    return value;
}

template <typename D> uint16_t impl_IBluetoothLEAppearanceSubcategoriesStatics<D>::Generic() const
{
    uint16_t value {};
    check_hresult(shim()->get_Generic(&value));
    return value;
}

template <typename D> uint16_t impl_IBluetoothLEAppearanceSubcategoriesStatics<D>::SportsWatch() const
{
    uint16_t value {};
    check_hresult(shim()->get_SportsWatch(&value));
    return value;
}

template <typename D> uint16_t impl_IBluetoothLEAppearanceSubcategoriesStatics<D>::ThermometerEar() const
{
    uint16_t value {};
    check_hresult(shim()->get_ThermometerEar(&value));
    return value;
}

template <typename D> uint16_t impl_IBluetoothLEAppearanceSubcategoriesStatics<D>::HeartRateBelt() const
{
    uint16_t value {};
    check_hresult(shim()->get_HeartRateBelt(&value));
    return value;
}

template <typename D> uint16_t impl_IBluetoothLEAppearanceSubcategoriesStatics<D>::BloodPressureArm() const
{
    uint16_t value {};
    check_hresult(shim()->get_BloodPressureArm(&value));
    return value;
}

template <typename D> uint16_t impl_IBluetoothLEAppearanceSubcategoriesStatics<D>::BloodPressureWrist() const
{
    uint16_t value {};
    check_hresult(shim()->get_BloodPressureWrist(&value));
    return value;
}

template <typename D> uint16_t impl_IBluetoothLEAppearanceSubcategoriesStatics<D>::Keyboard() const
{
    uint16_t value {};
    check_hresult(shim()->get_Keyboard(&value));
    return value;
}

template <typename D> uint16_t impl_IBluetoothLEAppearanceSubcategoriesStatics<D>::Mouse() const
{
    uint16_t value {};
    check_hresult(shim()->get_Mouse(&value));
    return value;
}

template <typename D> uint16_t impl_IBluetoothLEAppearanceSubcategoriesStatics<D>::Joystick() const
{
    uint16_t value {};
    check_hresult(shim()->get_Joystick(&value));
    return value;
}

template <typename D> uint16_t impl_IBluetoothLEAppearanceSubcategoriesStatics<D>::Gamepad() const
{
    uint16_t value {};
    check_hresult(shim()->get_Gamepad(&value));
    return value;
}

template <typename D> uint16_t impl_IBluetoothLEAppearanceSubcategoriesStatics<D>::DigitizerTablet() const
{
    uint16_t value {};
    check_hresult(shim()->get_DigitizerTablet(&value));
    return value;
}

template <typename D> uint16_t impl_IBluetoothLEAppearanceSubcategoriesStatics<D>::CardReader() const
{
    uint16_t value {};
    check_hresult(shim()->get_CardReader(&value));
    return value;
}

template <typename D> uint16_t impl_IBluetoothLEAppearanceSubcategoriesStatics<D>::DigitalPen() const
{
    uint16_t value {};
    check_hresult(shim()->get_DigitalPen(&value));
    return value;
}

template <typename D> uint16_t impl_IBluetoothLEAppearanceSubcategoriesStatics<D>::BarcodeScanner() const
{
    uint16_t value {};
    check_hresult(shim()->get_BarcodeScanner(&value));
    return value;
}

template <typename D> uint16_t impl_IBluetoothLEAppearanceSubcategoriesStatics<D>::RunningWalkingInShoe() const
{
    uint16_t value {};
    check_hresult(shim()->get_RunningWalkingInShoe(&value));
    return value;
}

template <typename D> uint16_t impl_IBluetoothLEAppearanceSubcategoriesStatics<D>::RunningWalkingOnShoe() const
{
    uint16_t value {};
    check_hresult(shim()->get_RunningWalkingOnShoe(&value));
    return value;
}

template <typename D> uint16_t impl_IBluetoothLEAppearanceSubcategoriesStatics<D>::RunningWalkingOnHip() const
{
    uint16_t value {};
    check_hresult(shim()->get_RunningWalkingOnHip(&value));
    return value;
}

template <typename D> uint16_t impl_IBluetoothLEAppearanceSubcategoriesStatics<D>::CyclingComputer() const
{
    uint16_t value {};
    check_hresult(shim()->get_CyclingComputer(&value));
    return value;
}

template <typename D> uint16_t impl_IBluetoothLEAppearanceSubcategoriesStatics<D>::CyclingSpeedSensor() const
{
    uint16_t value {};
    check_hresult(shim()->get_CyclingSpeedSensor(&value));
    return value;
}

template <typename D> uint16_t impl_IBluetoothLEAppearanceSubcategoriesStatics<D>::CyclingCadenceSensor() const
{
    uint16_t value {};
    check_hresult(shim()->get_CyclingCadenceSensor(&value));
    return value;
}

template <typename D> uint16_t impl_IBluetoothLEAppearanceSubcategoriesStatics<D>::CyclingPowerSensor() const
{
    uint16_t value {};
    check_hresult(shim()->get_CyclingPowerSensor(&value));
    return value;
}

template <typename D> uint16_t impl_IBluetoothLEAppearanceSubcategoriesStatics<D>::CyclingSpeedCadenceSensor() const
{
    uint16_t value {};
    check_hresult(shim()->get_CyclingSpeedCadenceSensor(&value));
    return value;
}

template <typename D> uint16_t impl_IBluetoothLEAppearanceSubcategoriesStatics<D>::OximeterFingertip() const
{
    uint16_t value {};
    check_hresult(shim()->get_OximeterFingertip(&value));
    return value;
}

template <typename D> uint16_t impl_IBluetoothLEAppearanceSubcategoriesStatics<D>::OximeterWristWorn() const
{
    uint16_t value {};
    check_hresult(shim()->get_OximeterWristWorn(&value));
    return value;
}

template <typename D> uint16_t impl_IBluetoothLEAppearanceSubcategoriesStatics<D>::LocationDisplay() const
{
    uint16_t value {};
    check_hresult(shim()->get_LocationDisplay(&value));
    return value;
}

template <typename D> uint16_t impl_IBluetoothLEAppearanceSubcategoriesStatics<D>::LocationNavigationDisplay() const
{
    uint16_t value {};
    check_hresult(shim()->get_LocationNavigationDisplay(&value));
    return value;
}

template <typename D> uint16_t impl_IBluetoothLEAppearanceSubcategoriesStatics<D>::LocationPod() const
{
    uint16_t value {};
    check_hresult(shim()->get_LocationPod(&value));
    return value;
}

template <typename D> uint16_t impl_IBluetoothLEAppearanceSubcategoriesStatics<D>::LocationNavigationPod() const
{
    uint16_t value {};
    check_hresult(shim()->get_LocationNavigationPod(&value));
    return value;
}

template <typename D> uint16_t impl_IBluetoothLEAppearance<D>::RawValue() const
{
    uint16_t value {};
    check_hresult(shim()->get_RawValue(&value));
    return value;
}

template <typename D> uint16_t impl_IBluetoothLEAppearance<D>::Category() const
{
    uint16_t value {};
    check_hresult(shim()->get_Category(&value));
    return value;
}

template <typename D> uint16_t impl_IBluetoothLEAppearance<D>::SubCategory() const
{
    uint16_t value {};
    check_hresult(shim()->get_SubCategory(&value));
    return value;
}

template <typename D> Windows::Devices::Bluetooth::BluetoothLEAppearance impl_IBluetoothLEAppearanceStatics<D>::FromRawValue(uint16_t rawValue) const
{
    Windows::Devices::Bluetooth::BluetoothLEAppearance appearance { nullptr };
    check_hresult(shim()->abi_FromRawValue(rawValue, put(appearance)));
    return appearance;
}

template <typename D> Windows::Devices::Bluetooth::BluetoothLEAppearance impl_IBluetoothLEAppearanceStatics<D>::FromParts(uint16_t appearanceCategory, uint16_t appearanceSubCategory) const
{
    Windows::Devices::Bluetooth::BluetoothLEAppearance appearance { nullptr };
    check_hresult(shim()->abi_FromParts(appearanceCategory, appearanceSubCategory, put(appearance)));
    return appearance;
}

template <typename D> hstring impl_IBluetoothLEDevice<D>::DeviceId() const
{
    hstring value;
    check_hresult(shim()->get_DeviceId(put(value)));
    return value;
}

template <typename D> hstring impl_IBluetoothLEDevice<D>::Name() const
{
    hstring value;
    check_hresult(shim()->get_Name(put(value)));
    return value;
}

template <typename D> Windows::Foundation::Collections::IVectorView<Windows::Devices::Bluetooth::GenericAttributeProfile::GattDeviceService> impl_IBluetoothLEDevice<D>::GattServices() const
{
    Windows::Foundation::Collections::IVectorView<Windows::Devices::Bluetooth::GenericAttributeProfile::GattDeviceService> value;
    check_hresult(shim()->get_GattServices(put(value)));
    return value;
}

template <typename D> Windows::Devices::Bluetooth::BluetoothConnectionStatus impl_IBluetoothLEDevice<D>::ConnectionStatus() const
{
    Windows::Devices::Bluetooth::BluetoothConnectionStatus value {};
    check_hresult(shim()->get_ConnectionStatus(&value));
    return value;
}

template <typename D> uint64_t impl_IBluetoothLEDevice<D>::BluetoothAddress() const
{
    uint64_t value {};
    check_hresult(shim()->get_BluetoothAddress(&value));
    return value;
}

template <typename D> Windows::Devices::Bluetooth::GenericAttributeProfile::GattDeviceService impl_IBluetoothLEDevice<D>::GetGattService(GUID serviceUuid) const
{
    Windows::Devices::Bluetooth::GenericAttributeProfile::GattDeviceService service { nullptr };
    check_hresult(shim()->abi_GetGattService(serviceUuid, put(service)));
    return service;
}

template <typename D> event_token impl_IBluetoothLEDevice<D>::NameChanged(const Windows::Foundation::TypedEventHandler<Windows::Devices::Bluetooth::BluetoothLEDevice, Windows::IInspectable> & handler) const
{
    event_token token {};
    check_hresult(shim()->add_NameChanged(get(handler), &token));
    return token;
}

template <typename D> event_revoker<IBluetoothLEDevice> impl_IBluetoothLEDevice<D>::NameChanged(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Devices::Bluetooth::BluetoothLEDevice, Windows::IInspectable> & handler) const
{
    return impl::make_event_revoker<D, IBluetoothLEDevice>(this, &ABI::Windows::Devices::Bluetooth::IBluetoothLEDevice::remove_NameChanged, NameChanged(handler));
}

template <typename D> void impl_IBluetoothLEDevice<D>::NameChanged(event_token token) const
{
    check_hresult(shim()->remove_NameChanged(token));
}

template <typename D> event_token impl_IBluetoothLEDevice<D>::GattServicesChanged(const Windows::Foundation::TypedEventHandler<Windows::Devices::Bluetooth::BluetoothLEDevice, Windows::IInspectable> & handler) const
{
    event_token token {};
    check_hresult(shim()->add_GattServicesChanged(get(handler), &token));
    return token;
}

template <typename D> event_revoker<IBluetoothLEDevice> impl_IBluetoothLEDevice<D>::GattServicesChanged(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Devices::Bluetooth::BluetoothLEDevice, Windows::IInspectable> & handler) const
{
    return impl::make_event_revoker<D, IBluetoothLEDevice>(this, &ABI::Windows::Devices::Bluetooth::IBluetoothLEDevice::remove_GattServicesChanged, GattServicesChanged(handler));
}

template <typename D> void impl_IBluetoothLEDevice<D>::GattServicesChanged(event_token token) const
{
    check_hresult(shim()->remove_GattServicesChanged(token));
}

template <typename D> event_token impl_IBluetoothLEDevice<D>::ConnectionStatusChanged(const Windows::Foundation::TypedEventHandler<Windows::Devices::Bluetooth::BluetoothLEDevice, Windows::IInspectable> & handler) const
{
    event_token token {};
    check_hresult(shim()->add_ConnectionStatusChanged(get(handler), &token));
    return token;
}

template <typename D> event_revoker<IBluetoothLEDevice> impl_IBluetoothLEDevice<D>::ConnectionStatusChanged(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Devices::Bluetooth::BluetoothLEDevice, Windows::IInspectable> & handler) const
{
    return impl::make_event_revoker<D, IBluetoothLEDevice>(this, &ABI::Windows::Devices::Bluetooth::IBluetoothLEDevice::remove_ConnectionStatusChanged, ConnectionStatusChanged(handler));
}

template <typename D> void impl_IBluetoothLEDevice<D>::ConnectionStatusChanged(event_token token) const
{
    check_hresult(shim()->remove_ConnectionStatusChanged(token));
}

template <typename D> Windows::Devices::Enumeration::DeviceInformation impl_IBluetoothLEDevice2<D>::DeviceInformation() const
{
    Windows::Devices::Enumeration::DeviceInformation value { nullptr };
    check_hresult(shim()->get_DeviceInformation(put(value)));
    return value;
}

template <typename D> Windows::Devices::Bluetooth::BluetoothLEAppearance impl_IBluetoothLEDevice2<D>::Appearance() const
{
    Windows::Devices::Bluetooth::BluetoothLEAppearance value { nullptr };
    check_hresult(shim()->get_Appearance(put(value)));
    return value;
}

template <typename D> Windows::Devices::Bluetooth::BluetoothAddressType impl_IBluetoothLEDevice2<D>::BluetoothAddressType() const
{
    Windows::Devices::Bluetooth::BluetoothAddressType value {};
    check_hresult(shim()->get_BluetoothAddressType(&value));
    return value;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Devices::Bluetooth::BluetoothLEDevice> impl_IBluetoothLEDeviceStatics<D>::FromIdAsync(hstring_ref deviceId) const
{
    Windows::Foundation::IAsyncOperation<Windows::Devices::Bluetooth::BluetoothLEDevice> operation;
    check_hresult(shim()->abi_FromIdAsync(get(deviceId), put(operation)));
    return operation;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Devices::Bluetooth::BluetoothLEDevice> impl_IBluetoothLEDeviceStatics<D>::FromBluetoothAddressAsync(uint64_t bluetoothAddress) const
{
    Windows::Foundation::IAsyncOperation<Windows::Devices::Bluetooth::BluetoothLEDevice> operation;
    check_hresult(shim()->abi_FromBluetoothAddressAsync(bluetoothAddress, put(operation)));
    return operation;
}

template <typename D> hstring impl_IBluetoothLEDeviceStatics<D>::GetDeviceSelector() const
{
    hstring deviceSelector;
    check_hresult(shim()->abi_GetDeviceSelector(put(deviceSelector)));
    return deviceSelector;
}

template <typename D> hstring impl_IBluetoothLEDeviceStatics2<D>::GetDeviceSelectorFromPairingState(bool pairingState) const
{
    hstring deviceSelector;
    check_hresult(shim()->abi_GetDeviceSelectorFromPairingState(pairingState, put(deviceSelector)));
    return deviceSelector;
}

template <typename D> hstring impl_IBluetoothLEDeviceStatics2<D>::GetDeviceSelectorFromConnectionStatus(Windows::Devices::Bluetooth::BluetoothConnectionStatus connectionStatus) const
{
    hstring deviceSelector;
    check_hresult(shim()->abi_GetDeviceSelectorFromConnectionStatus(connectionStatus, put(deviceSelector)));
    return deviceSelector;
}

template <typename D> hstring impl_IBluetoothLEDeviceStatics2<D>::GetDeviceSelectorFromDeviceName(hstring_ref deviceName) const
{
    hstring deviceSelector;
    check_hresult(shim()->abi_GetDeviceSelectorFromDeviceName(get(deviceName), put(deviceSelector)));
    return deviceSelector;
}

template <typename D> hstring impl_IBluetoothLEDeviceStatics2<D>::GetDeviceSelectorFromBluetoothAddress(uint64_t bluetoothAddress) const
{
    hstring deviceSelector;
    check_hresult(shim()->abi_GetDeviceSelectorFromBluetoothAddress(bluetoothAddress, put(deviceSelector)));
    return deviceSelector;
}

template <typename D> hstring impl_IBluetoothLEDeviceStatics2<D>::GetDeviceSelectorFromBluetoothAddress(uint64_t bluetoothAddress, Windows::Devices::Bluetooth::BluetoothAddressType bluetoothAddressType) const
{
    hstring deviceSelector;
    check_hresult(shim()->abi_GetDeviceSelectorFromBluetoothAddressWithBluetoothAddressType(bluetoothAddress, bluetoothAddressType, put(deviceSelector)));
    return deviceSelector;
}

template <typename D> hstring impl_IBluetoothLEDeviceStatics2<D>::GetDeviceSelectorFromAppearance(const Windows::Devices::Bluetooth::BluetoothLEAppearance & appearance) const
{
    hstring deviceSelector;
    check_hresult(shim()->abi_GetDeviceSelectorFromAppearance(get(appearance), put(deviceSelector)));
    return deviceSelector;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Devices::Bluetooth::BluetoothLEDevice> impl_IBluetoothLEDeviceStatics2<D>::FromBluetoothAddressAsync(uint64_t bluetoothAddress, Windows::Devices::Bluetooth::BluetoothAddressType bluetoothAddressType) const
{
    Windows::Foundation::IAsyncOperation<Windows::Devices::Bluetooth::BluetoothLEDevice> operation;
    check_hresult(shim()->abi_FromBluetoothAddressWithBluetoothAddressTypeAsync(bluetoothAddress, bluetoothAddressType, put(operation)));
    return operation;
}

template <typename D> uint32_t impl_IBluetoothClassOfDevice<D>::RawValue() const
{
    uint32_t value {};
    check_hresult(shim()->get_RawValue(&value));
    return value;
}

template <typename D> Windows::Devices::Bluetooth::BluetoothMajorClass impl_IBluetoothClassOfDevice<D>::MajorClass() const
{
    Windows::Devices::Bluetooth::BluetoothMajorClass value {};
    check_hresult(shim()->get_MajorClass(&value));
    return value;
}

template <typename D> Windows::Devices::Bluetooth::BluetoothMinorClass impl_IBluetoothClassOfDevice<D>::MinorClass() const
{
    Windows::Devices::Bluetooth::BluetoothMinorClass value {};
    check_hresult(shim()->get_MinorClass(&value));
    return value;
}

template <typename D> Windows::Devices::Bluetooth::BluetoothServiceCapabilities impl_IBluetoothClassOfDevice<D>::ServiceCapabilities() const
{
    Windows::Devices::Bluetooth::BluetoothServiceCapabilities value {};
    check_hresult(shim()->get_ServiceCapabilities(&value));
    return value;
}

template <typename D> Windows::Devices::Bluetooth::BluetoothClassOfDevice impl_IBluetoothClassOfDeviceStatics<D>::FromRawValue(uint32_t rawValue) const
{
    Windows::Devices::Bluetooth::BluetoothClassOfDevice classOfDevice { nullptr };
    check_hresult(shim()->abi_FromRawValue(rawValue, put(classOfDevice)));
    return classOfDevice;
}

template <typename D> Windows::Devices::Bluetooth::BluetoothClassOfDevice impl_IBluetoothClassOfDeviceStatics<D>::FromParts(Windows::Devices::Bluetooth::BluetoothMajorClass majorClass, Windows::Devices::Bluetooth::BluetoothMinorClass minorClass, Windows::Devices::Bluetooth::BluetoothServiceCapabilities serviceCapabilities) const
{
    Windows::Devices::Bluetooth::BluetoothClassOfDevice classOfDevice { nullptr };
    check_hresult(shim()->abi_FromParts(majorClass, minorClass, serviceCapabilities, put(classOfDevice)));
    return classOfDevice;
}

template <typename D> Windows::Foundation::IReference<int16_t> impl_IBluetoothSignalStrengthFilter<D>::InRangeThresholdInDBm() const
{
    Windows::Foundation::IReference<int16_t> value;
    check_hresult(shim()->get_InRangeThresholdInDBm(put(value)));
    return value;
}

template <typename D> void impl_IBluetoothSignalStrengthFilter<D>::InRangeThresholdInDBm(const Windows::Foundation::IReference<int16_t> & value) const
{
    check_hresult(shim()->put_InRangeThresholdInDBm(get(value)));
}

template <typename D> Windows::Foundation::IReference<int16_t> impl_IBluetoothSignalStrengthFilter<D>::OutOfRangeThresholdInDBm() const
{
    Windows::Foundation::IReference<int16_t> value;
    check_hresult(shim()->get_OutOfRangeThresholdInDBm(put(value)));
    return value;
}

template <typename D> void impl_IBluetoothSignalStrengthFilter<D>::OutOfRangeThresholdInDBm(const Windows::Foundation::IReference<int16_t> & value) const
{
    check_hresult(shim()->put_OutOfRangeThresholdInDBm(get(value)));
}

template <typename D> Windows::Foundation::IReference<Windows::Foundation::TimeSpan> impl_IBluetoothSignalStrengthFilter<D>::OutOfRangeTimeout() const
{
    Windows::Foundation::IReference<Windows::Foundation::TimeSpan> value;
    check_hresult(shim()->get_OutOfRangeTimeout(put(value)));
    return value;
}

template <typename D> void impl_IBluetoothSignalStrengthFilter<D>::OutOfRangeTimeout(const Windows::Foundation::IReference<Windows::Foundation::TimeSpan> & value) const
{
    check_hresult(shim()->put_OutOfRangeTimeout(get(value)));
}

template <typename D> Windows::Foundation::IReference<Windows::Foundation::TimeSpan> impl_IBluetoothSignalStrengthFilter<D>::SamplingInterval() const
{
    Windows::Foundation::IReference<Windows::Foundation::TimeSpan> value;
    check_hresult(shim()->get_SamplingInterval(put(value)));
    return value;
}

template <typename D> void impl_IBluetoothSignalStrengthFilter<D>::SamplingInterval(const Windows::Foundation::IReference<Windows::Foundation::TimeSpan> & value) const
{
    check_hresult(shim()->put_SamplingInterval(get(value)));
}

inline Windows::Devices::Bluetooth::BluetoothClassOfDevice BluetoothClassOfDevice::FromRawValue(uint32_t rawValue)
{
    return GetActivationFactory<BluetoothClassOfDevice, IBluetoothClassOfDeviceStatics>().FromRawValue(rawValue);
}

inline Windows::Devices::Bluetooth::BluetoothClassOfDevice BluetoothClassOfDevice::FromParts(Windows::Devices::Bluetooth::BluetoothMajorClass majorClass, Windows::Devices::Bluetooth::BluetoothMinorClass minorClass, Windows::Devices::Bluetooth::BluetoothServiceCapabilities serviceCapabilities)
{
    return GetActivationFactory<BluetoothClassOfDevice, IBluetoothClassOfDeviceStatics>().FromParts(majorClass, minorClass, serviceCapabilities);
}

inline Windows::Foundation::IAsyncOperation<Windows::Devices::Bluetooth::BluetoothDevice> BluetoothDevice::FromIdAsync(hstring_ref deviceId)
{
    return GetActivationFactory<BluetoothDevice, IBluetoothDeviceStatics>().FromIdAsync(deviceId);
}

inline Windows::Foundation::IAsyncOperation<Windows::Devices::Bluetooth::BluetoothDevice> BluetoothDevice::FromHostNameAsync(const Windows::Networking::HostName & hostName)
{
    return GetActivationFactory<BluetoothDevice, IBluetoothDeviceStatics>().FromHostNameAsync(hostName);
}

inline Windows::Foundation::IAsyncOperation<Windows::Devices::Bluetooth::BluetoothDevice> BluetoothDevice::FromBluetoothAddressAsync(uint64_t address)
{
    return GetActivationFactory<BluetoothDevice, IBluetoothDeviceStatics>().FromBluetoothAddressAsync(address);
}

inline hstring BluetoothDevice::GetDeviceSelector()
{
    return GetActivationFactory<BluetoothDevice, IBluetoothDeviceStatics>().GetDeviceSelector();
}

inline hstring BluetoothDevice::GetDeviceSelectorFromPairingState(bool pairingState)
{
    return GetActivationFactory<BluetoothDevice, IBluetoothDeviceStatics2>().GetDeviceSelectorFromPairingState(pairingState);
}

inline hstring BluetoothDevice::GetDeviceSelectorFromConnectionStatus(Windows::Devices::Bluetooth::BluetoothConnectionStatus connectionStatus)
{
    return GetActivationFactory<BluetoothDevice, IBluetoothDeviceStatics2>().GetDeviceSelectorFromConnectionStatus(connectionStatus);
}

inline hstring BluetoothDevice::GetDeviceSelectorFromDeviceName(hstring_ref deviceName)
{
    return GetActivationFactory<BluetoothDevice, IBluetoothDeviceStatics2>().GetDeviceSelectorFromDeviceName(deviceName);
}

inline hstring BluetoothDevice::GetDeviceSelectorFromBluetoothAddress(uint64_t bluetoothAddress)
{
    return GetActivationFactory<BluetoothDevice, IBluetoothDeviceStatics2>().GetDeviceSelectorFromBluetoothAddress(bluetoothAddress);
}

inline hstring BluetoothDevice::GetDeviceSelectorFromClassOfDevice(const Windows::Devices::Bluetooth::BluetoothClassOfDevice & classOfDevice)
{
    return GetActivationFactory<BluetoothDevice, IBluetoothDeviceStatics2>().GetDeviceSelectorFromClassOfDevice(classOfDevice);
}

inline Windows::Devices::Bluetooth::BluetoothLEAppearance BluetoothLEAppearance::FromRawValue(uint16_t rawValue)
{
    return GetActivationFactory<BluetoothLEAppearance, IBluetoothLEAppearanceStatics>().FromRawValue(rawValue);
}

inline Windows::Devices::Bluetooth::BluetoothLEAppearance BluetoothLEAppearance::FromParts(uint16_t appearanceCategory, uint16_t appearanceSubCategory)
{
    return GetActivationFactory<BluetoothLEAppearance, IBluetoothLEAppearanceStatics>().FromParts(appearanceCategory, appearanceSubCategory);
}

inline uint16_t BluetoothLEAppearanceCategories::Uncategorized()
{
    return GetActivationFactory<BluetoothLEAppearanceCategories, IBluetoothLEAppearanceCategoriesStatics>().Uncategorized();
}

inline uint16_t BluetoothLEAppearanceCategories::Phone()
{
    return GetActivationFactory<BluetoothLEAppearanceCategories, IBluetoothLEAppearanceCategoriesStatics>().Phone();
}

inline uint16_t BluetoothLEAppearanceCategories::Computer()
{
    return GetActivationFactory<BluetoothLEAppearanceCategories, IBluetoothLEAppearanceCategoriesStatics>().Computer();
}

inline uint16_t BluetoothLEAppearanceCategories::Watch()
{
    return GetActivationFactory<BluetoothLEAppearanceCategories, IBluetoothLEAppearanceCategoriesStatics>().Watch();
}

inline uint16_t BluetoothLEAppearanceCategories::Clock()
{
    return GetActivationFactory<BluetoothLEAppearanceCategories, IBluetoothLEAppearanceCategoriesStatics>().Clock();
}

inline uint16_t BluetoothLEAppearanceCategories::Display()
{
    return GetActivationFactory<BluetoothLEAppearanceCategories, IBluetoothLEAppearanceCategoriesStatics>().Display();
}

inline uint16_t BluetoothLEAppearanceCategories::RemoteControl()
{
    return GetActivationFactory<BluetoothLEAppearanceCategories, IBluetoothLEAppearanceCategoriesStatics>().RemoteControl();
}

inline uint16_t BluetoothLEAppearanceCategories::EyeGlasses()
{
    return GetActivationFactory<BluetoothLEAppearanceCategories, IBluetoothLEAppearanceCategoriesStatics>().EyeGlasses();
}

inline uint16_t BluetoothLEAppearanceCategories::Tag()
{
    return GetActivationFactory<BluetoothLEAppearanceCategories, IBluetoothLEAppearanceCategoriesStatics>().Tag();
}

inline uint16_t BluetoothLEAppearanceCategories::Keyring()
{
    return GetActivationFactory<BluetoothLEAppearanceCategories, IBluetoothLEAppearanceCategoriesStatics>().Keyring();
}

inline uint16_t BluetoothLEAppearanceCategories::MediaPlayer()
{
    return GetActivationFactory<BluetoothLEAppearanceCategories, IBluetoothLEAppearanceCategoriesStatics>().MediaPlayer();
}

inline uint16_t BluetoothLEAppearanceCategories::BarcodeScanner()
{
    return GetActivationFactory<BluetoothLEAppearanceCategories, IBluetoothLEAppearanceCategoriesStatics>().BarcodeScanner();
}

inline uint16_t BluetoothLEAppearanceCategories::Thermometer()
{
    return GetActivationFactory<BluetoothLEAppearanceCategories, IBluetoothLEAppearanceCategoriesStatics>().Thermometer();
}

inline uint16_t BluetoothLEAppearanceCategories::HeartRate()
{
    return GetActivationFactory<BluetoothLEAppearanceCategories, IBluetoothLEAppearanceCategoriesStatics>().HeartRate();
}

inline uint16_t BluetoothLEAppearanceCategories::BloodPressure()
{
    return GetActivationFactory<BluetoothLEAppearanceCategories, IBluetoothLEAppearanceCategoriesStatics>().BloodPressure();
}

inline uint16_t BluetoothLEAppearanceCategories::HumanInterfaceDevice()
{
    return GetActivationFactory<BluetoothLEAppearanceCategories, IBluetoothLEAppearanceCategoriesStatics>().HumanInterfaceDevice();
}

inline uint16_t BluetoothLEAppearanceCategories::GlucoseMeter()
{
    return GetActivationFactory<BluetoothLEAppearanceCategories, IBluetoothLEAppearanceCategoriesStatics>().GlucoseMeter();
}

inline uint16_t BluetoothLEAppearanceCategories::RunningWalking()
{
    return GetActivationFactory<BluetoothLEAppearanceCategories, IBluetoothLEAppearanceCategoriesStatics>().RunningWalking();
}

inline uint16_t BluetoothLEAppearanceCategories::Cycling()
{
    return GetActivationFactory<BluetoothLEAppearanceCategories, IBluetoothLEAppearanceCategoriesStatics>().Cycling();
}

inline uint16_t BluetoothLEAppearanceCategories::PulseOximeter()
{
    return GetActivationFactory<BluetoothLEAppearanceCategories, IBluetoothLEAppearanceCategoriesStatics>().PulseOximeter();
}

inline uint16_t BluetoothLEAppearanceCategories::WeightScale()
{
    return GetActivationFactory<BluetoothLEAppearanceCategories, IBluetoothLEAppearanceCategoriesStatics>().WeightScale();
}

inline uint16_t BluetoothLEAppearanceCategories::OutdoorSportActivity()
{
    return GetActivationFactory<BluetoothLEAppearanceCategories, IBluetoothLEAppearanceCategoriesStatics>().OutdoorSportActivity();
}

inline uint16_t BluetoothLEAppearanceSubcategories::Generic()
{
    return GetActivationFactory<BluetoothLEAppearanceSubcategories, IBluetoothLEAppearanceSubcategoriesStatics>().Generic();
}

inline uint16_t BluetoothLEAppearanceSubcategories::SportsWatch()
{
    return GetActivationFactory<BluetoothLEAppearanceSubcategories, IBluetoothLEAppearanceSubcategoriesStatics>().SportsWatch();
}

inline uint16_t BluetoothLEAppearanceSubcategories::ThermometerEar()
{
    return GetActivationFactory<BluetoothLEAppearanceSubcategories, IBluetoothLEAppearanceSubcategoriesStatics>().ThermometerEar();
}

inline uint16_t BluetoothLEAppearanceSubcategories::HeartRateBelt()
{
    return GetActivationFactory<BluetoothLEAppearanceSubcategories, IBluetoothLEAppearanceSubcategoriesStatics>().HeartRateBelt();
}

inline uint16_t BluetoothLEAppearanceSubcategories::BloodPressureArm()
{
    return GetActivationFactory<BluetoothLEAppearanceSubcategories, IBluetoothLEAppearanceSubcategoriesStatics>().BloodPressureArm();
}

inline uint16_t BluetoothLEAppearanceSubcategories::BloodPressureWrist()
{
    return GetActivationFactory<BluetoothLEAppearanceSubcategories, IBluetoothLEAppearanceSubcategoriesStatics>().BloodPressureWrist();
}

inline uint16_t BluetoothLEAppearanceSubcategories::Keyboard()
{
    return GetActivationFactory<BluetoothLEAppearanceSubcategories, IBluetoothLEAppearanceSubcategoriesStatics>().Keyboard();
}

inline uint16_t BluetoothLEAppearanceSubcategories::Mouse()
{
    return GetActivationFactory<BluetoothLEAppearanceSubcategories, IBluetoothLEAppearanceSubcategoriesStatics>().Mouse();
}

inline uint16_t BluetoothLEAppearanceSubcategories::Joystick()
{
    return GetActivationFactory<BluetoothLEAppearanceSubcategories, IBluetoothLEAppearanceSubcategoriesStatics>().Joystick();
}

inline uint16_t BluetoothLEAppearanceSubcategories::Gamepad()
{
    return GetActivationFactory<BluetoothLEAppearanceSubcategories, IBluetoothLEAppearanceSubcategoriesStatics>().Gamepad();
}

inline uint16_t BluetoothLEAppearanceSubcategories::DigitizerTablet()
{
    return GetActivationFactory<BluetoothLEAppearanceSubcategories, IBluetoothLEAppearanceSubcategoriesStatics>().DigitizerTablet();
}

inline uint16_t BluetoothLEAppearanceSubcategories::CardReader()
{
    return GetActivationFactory<BluetoothLEAppearanceSubcategories, IBluetoothLEAppearanceSubcategoriesStatics>().CardReader();
}

inline uint16_t BluetoothLEAppearanceSubcategories::DigitalPen()
{
    return GetActivationFactory<BluetoothLEAppearanceSubcategories, IBluetoothLEAppearanceSubcategoriesStatics>().DigitalPen();
}

inline uint16_t BluetoothLEAppearanceSubcategories::BarcodeScanner()
{
    return GetActivationFactory<BluetoothLEAppearanceSubcategories, IBluetoothLEAppearanceSubcategoriesStatics>().BarcodeScanner();
}

inline uint16_t BluetoothLEAppearanceSubcategories::RunningWalkingInShoe()
{
    return GetActivationFactory<BluetoothLEAppearanceSubcategories, IBluetoothLEAppearanceSubcategoriesStatics>().RunningWalkingInShoe();
}

inline uint16_t BluetoothLEAppearanceSubcategories::RunningWalkingOnShoe()
{
    return GetActivationFactory<BluetoothLEAppearanceSubcategories, IBluetoothLEAppearanceSubcategoriesStatics>().RunningWalkingOnShoe();
}

inline uint16_t BluetoothLEAppearanceSubcategories::RunningWalkingOnHip()
{
    return GetActivationFactory<BluetoothLEAppearanceSubcategories, IBluetoothLEAppearanceSubcategoriesStatics>().RunningWalkingOnHip();
}

inline uint16_t BluetoothLEAppearanceSubcategories::CyclingComputer()
{
    return GetActivationFactory<BluetoothLEAppearanceSubcategories, IBluetoothLEAppearanceSubcategoriesStatics>().CyclingComputer();
}

inline uint16_t BluetoothLEAppearanceSubcategories::CyclingSpeedSensor()
{
    return GetActivationFactory<BluetoothLEAppearanceSubcategories, IBluetoothLEAppearanceSubcategoriesStatics>().CyclingSpeedSensor();
}

inline uint16_t BluetoothLEAppearanceSubcategories::CyclingCadenceSensor()
{
    return GetActivationFactory<BluetoothLEAppearanceSubcategories, IBluetoothLEAppearanceSubcategoriesStatics>().CyclingCadenceSensor();
}

inline uint16_t BluetoothLEAppearanceSubcategories::CyclingPowerSensor()
{
    return GetActivationFactory<BluetoothLEAppearanceSubcategories, IBluetoothLEAppearanceSubcategoriesStatics>().CyclingPowerSensor();
}

inline uint16_t BluetoothLEAppearanceSubcategories::CyclingSpeedCadenceSensor()
{
    return GetActivationFactory<BluetoothLEAppearanceSubcategories, IBluetoothLEAppearanceSubcategoriesStatics>().CyclingSpeedCadenceSensor();
}

inline uint16_t BluetoothLEAppearanceSubcategories::OximeterFingertip()
{
    return GetActivationFactory<BluetoothLEAppearanceSubcategories, IBluetoothLEAppearanceSubcategoriesStatics>().OximeterFingertip();
}

inline uint16_t BluetoothLEAppearanceSubcategories::OximeterWristWorn()
{
    return GetActivationFactory<BluetoothLEAppearanceSubcategories, IBluetoothLEAppearanceSubcategoriesStatics>().OximeterWristWorn();
}

inline uint16_t BluetoothLEAppearanceSubcategories::LocationDisplay()
{
    return GetActivationFactory<BluetoothLEAppearanceSubcategories, IBluetoothLEAppearanceSubcategoriesStatics>().LocationDisplay();
}

inline uint16_t BluetoothLEAppearanceSubcategories::LocationNavigationDisplay()
{
    return GetActivationFactory<BluetoothLEAppearanceSubcategories, IBluetoothLEAppearanceSubcategoriesStatics>().LocationNavigationDisplay();
}

inline uint16_t BluetoothLEAppearanceSubcategories::LocationPod()
{
    return GetActivationFactory<BluetoothLEAppearanceSubcategories, IBluetoothLEAppearanceSubcategoriesStatics>().LocationPod();
}

inline uint16_t BluetoothLEAppearanceSubcategories::LocationNavigationPod()
{
    return GetActivationFactory<BluetoothLEAppearanceSubcategories, IBluetoothLEAppearanceSubcategoriesStatics>().LocationNavigationPod();
}

inline Windows::Foundation::IAsyncOperation<Windows::Devices::Bluetooth::BluetoothLEDevice> BluetoothLEDevice::FromIdAsync(hstring_ref deviceId)
{
    return GetActivationFactory<BluetoothLEDevice, IBluetoothLEDeviceStatics>().FromIdAsync(deviceId);
}

inline Windows::Foundation::IAsyncOperation<Windows::Devices::Bluetooth::BluetoothLEDevice> BluetoothLEDevice::FromBluetoothAddressAsync(uint64_t bluetoothAddress)
{
    return GetActivationFactory<BluetoothLEDevice, IBluetoothLEDeviceStatics>().FromBluetoothAddressAsync(bluetoothAddress);
}

inline hstring BluetoothLEDevice::GetDeviceSelector()
{
    return GetActivationFactory<BluetoothLEDevice, IBluetoothLEDeviceStatics>().GetDeviceSelector();
}

inline hstring BluetoothLEDevice::GetDeviceSelectorFromPairingState(bool pairingState)
{
    return GetActivationFactory<BluetoothLEDevice, IBluetoothLEDeviceStatics2>().GetDeviceSelectorFromPairingState(pairingState);
}

inline hstring BluetoothLEDevice::GetDeviceSelectorFromConnectionStatus(Windows::Devices::Bluetooth::BluetoothConnectionStatus connectionStatus)
{
    return GetActivationFactory<BluetoothLEDevice, IBluetoothLEDeviceStatics2>().GetDeviceSelectorFromConnectionStatus(connectionStatus);
}

inline hstring BluetoothLEDevice::GetDeviceSelectorFromDeviceName(hstring_ref deviceName)
{
    return GetActivationFactory<BluetoothLEDevice, IBluetoothLEDeviceStatics2>().GetDeviceSelectorFromDeviceName(deviceName);
}

inline hstring BluetoothLEDevice::GetDeviceSelectorFromBluetoothAddress(uint64_t bluetoothAddress)
{
    return GetActivationFactory<BluetoothLEDevice, IBluetoothLEDeviceStatics2>().GetDeviceSelectorFromBluetoothAddress(bluetoothAddress);
}

inline hstring BluetoothLEDevice::GetDeviceSelectorFromBluetoothAddress(uint64_t bluetoothAddress, Windows::Devices::Bluetooth::BluetoothAddressType bluetoothAddressType)
{
    return GetActivationFactory<BluetoothLEDevice, IBluetoothLEDeviceStatics2>().GetDeviceSelectorFromBluetoothAddress(bluetoothAddress, bluetoothAddressType);
}

inline hstring BluetoothLEDevice::GetDeviceSelectorFromAppearance(const Windows::Devices::Bluetooth::BluetoothLEAppearance & appearance)
{
    return GetActivationFactory<BluetoothLEDevice, IBluetoothLEDeviceStatics2>().GetDeviceSelectorFromAppearance(appearance);
}

inline Windows::Foundation::IAsyncOperation<Windows::Devices::Bluetooth::BluetoothLEDevice> BluetoothLEDevice::FromBluetoothAddressAsync(uint64_t bluetoothAddress, Windows::Devices::Bluetooth::BluetoothAddressType bluetoothAddressType)
{
    return GetActivationFactory<BluetoothLEDevice, IBluetoothLEDeviceStatics2>().FromBluetoothAddressAsync(bluetoothAddress, bluetoothAddressType);
}

inline BluetoothSignalStrengthFilter::BluetoothSignalStrengthFilter() :
    BluetoothSignalStrengthFilter(ActivateInstance<BluetoothSignalStrengthFilter>())
{}

}

}
