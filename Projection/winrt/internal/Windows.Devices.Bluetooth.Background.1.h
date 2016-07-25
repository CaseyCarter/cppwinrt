// C++ for the Windows Runtime v1.29
// Copyright (c) 2016 Microsoft Corporation

#pragma once

#include "..\base.h"
#include "Windows.Devices.Bluetooth.Background.0.h"
#include "Windows.Devices.Bluetooth.0.h"
#include "Windows.Devices.Bluetooth.Advertisement.0.h"
#include "Windows.Devices.Bluetooth.GenericAttributeProfile.0.h"
#include "Windows.Devices.Bluetooth.Rfcomm.0.h"
#include "Windows.Networking.Sockets.0.h"
#include "Windows.Storage.Streams.0.h"
#include "Windows.Devices.Bluetooth.Advertisement.1.h"
#include "Windows.Foundation.Collections.1.h"

WINRT_EXPORT namespace winrt {

namespace ABI::Windows::Devices::Bluetooth::Background {

struct __declspec(uuid("610eca86-3480-41c9-a918-7ddadf207e00")) __declspec(novtable) IBluetoothLEAdvertisementPublisherTriggerDetails : Windows::IInspectable
{
    virtual HRESULT __stdcall get_Status(winrt::Windows::Devices::Bluetooth::Advertisement::BluetoothLEAdvertisementPublisherStatus * value) = 0;
    virtual HRESULT __stdcall get_Error(winrt::Windows::Devices::Bluetooth::BluetoothError * value) = 0;
};

struct __declspec(uuid("a7db5ad7-2257-4e69-9784-fee645c1dce0")) __declspec(novtable) IBluetoothLEAdvertisementWatcherTriggerDetails : Windows::IInspectable
{
    virtual HRESULT __stdcall get_Error(winrt::Windows::Devices::Bluetooth::BluetoothError * value) = 0;
    virtual HRESULT __stdcall get_Advertisements(Windows::Foundation::Collections::IVectorView<Windows::Devices::Bluetooth::Advertisement::BluetoothLEAdvertisementReceivedEventArgs> ** value) = 0;
    virtual HRESULT __stdcall get_SignalStrengthFilter(Windows::Devices::Bluetooth::IBluetoothSignalStrengthFilter ** value) = 0;
};

struct __declspec(uuid("9ba03b18-0fec-436a-93b1-f46c697532a2")) __declspec(novtable) IGattCharacteristicNotificationTriggerDetails : Windows::IInspectable
{
    virtual HRESULT __stdcall get_Characteristic(Windows::Devices::Bluetooth::GenericAttributeProfile::IGattCharacteristic ** value) = 0;
    virtual HRESULT __stdcall get_Value(Windows::Storage::Streams::IBuffer ** value) = 0;
};

struct __declspec(uuid("f922734d-2e3c-4efc-ab59-fc5cf96f97e3")) __declspec(novtable) IRfcommConnectionTriggerDetails : Windows::IInspectable
{
    virtual HRESULT __stdcall get_Socket(Windows::Networking::Sockets::IStreamSocket ** value) = 0;
    virtual HRESULT __stdcall get_Incoming(bool * value) = 0;
    virtual HRESULT __stdcall get_RemoteDevice(Windows::Devices::Bluetooth::IBluetoothDevice ** value) = 0;
};

struct __declspec(uuid("6d3e75a8-5429-4059-92e3-1e8b65528707")) __declspec(novtable) IRfcommInboundConnectionInformation : Windows::IInspectable
{
    virtual HRESULT __stdcall get_SdpRecord(Windows::Storage::Streams::IBuffer ** value) = 0;
    virtual HRESULT __stdcall put_SdpRecord(Windows::Storage::Streams::IBuffer * value) = 0;
    virtual HRESULT __stdcall get_LocalServiceId(Windows::Devices::Bluetooth::Rfcomm::IRfcommServiceId ** value) = 0;
    virtual HRESULT __stdcall put_LocalServiceId(Windows::Devices::Bluetooth::Rfcomm::IRfcommServiceId * value) = 0;
    virtual HRESULT __stdcall get_ServiceCapabilities(winrt::Windows::Devices::Bluetooth::BluetoothServiceCapabilities * value) = 0;
    virtual HRESULT __stdcall put_ServiceCapabilities(winrt::Windows::Devices::Bluetooth::BluetoothServiceCapabilities value) = 0;
};

struct __declspec(uuid("b091227b-f434-4cb0-99b1-4ab8cedaedd7")) __declspec(novtable) IRfcommOutboundConnectionInformation : Windows::IInspectable
{
    virtual HRESULT __stdcall get_RemoteServiceId(Windows::Devices::Bluetooth::Rfcomm::IRfcommServiceId ** value) = 0;
    virtual HRESULT __stdcall put_RemoteServiceId(Windows::Devices::Bluetooth::Rfcomm::IRfcommServiceId * value) = 0;
};

}

namespace ABI {

template <> struct traits<Windows::Devices::Bluetooth::Background::BluetoothLEAdvertisementPublisherTriggerDetails> { using default_interface = Windows::Devices::Bluetooth::Background::IBluetoothLEAdvertisementPublisherTriggerDetails; };
template <> struct traits<Windows::Devices::Bluetooth::Background::BluetoothLEAdvertisementWatcherTriggerDetails> { using default_interface = Windows::Devices::Bluetooth::Background::IBluetoothLEAdvertisementWatcherTriggerDetails; };
template <> struct traits<Windows::Devices::Bluetooth::Background::GattCharacteristicNotificationTriggerDetails> { using default_interface = Windows::Devices::Bluetooth::Background::IGattCharacteristicNotificationTriggerDetails; };
template <> struct traits<Windows::Devices::Bluetooth::Background::RfcommConnectionTriggerDetails> { using default_interface = Windows::Devices::Bluetooth::Background::IRfcommConnectionTriggerDetails; };
template <> struct traits<Windows::Devices::Bluetooth::Background::RfcommInboundConnectionInformation> { using default_interface = Windows::Devices::Bluetooth::Background::IRfcommInboundConnectionInformation; };
template <> struct traits<Windows::Devices::Bluetooth::Background::RfcommOutboundConnectionInformation> { using default_interface = Windows::Devices::Bluetooth::Background::IRfcommOutboundConnectionInformation; };

}

namespace Windows::Devices::Bluetooth::Background {

template <typename T> class impl_IBluetoothLEAdvertisementPublisherTriggerDetails;
template <typename T> class impl_IBluetoothLEAdvertisementWatcherTriggerDetails;
template <typename T> class impl_IGattCharacteristicNotificationTriggerDetails;
template <typename T> class impl_IRfcommConnectionTriggerDetails;
template <typename T> class impl_IRfcommInboundConnectionInformation;
template <typename T> class impl_IRfcommOutboundConnectionInformation;

}

namespace impl {

template <> struct traits<Windows::Devices::Bluetooth::Background::IBluetoothLEAdvertisementPublisherTriggerDetails>
{
    using abi = ABI::Windows::Devices::Bluetooth::Background::IBluetoothLEAdvertisementPublisherTriggerDetails;
    template <typename D> using consume = Windows::Devices::Bluetooth::Background::impl_IBluetoothLEAdvertisementPublisherTriggerDetails<D>;
};

template <> struct traits<Windows::Devices::Bluetooth::Background::IBluetoothLEAdvertisementWatcherTriggerDetails>
{
    using abi = ABI::Windows::Devices::Bluetooth::Background::IBluetoothLEAdvertisementWatcherTriggerDetails;
    template <typename D> using consume = Windows::Devices::Bluetooth::Background::impl_IBluetoothLEAdvertisementWatcherTriggerDetails<D>;
};

template <> struct traits<Windows::Devices::Bluetooth::Background::IGattCharacteristicNotificationTriggerDetails>
{
    using abi = ABI::Windows::Devices::Bluetooth::Background::IGattCharacteristicNotificationTriggerDetails;
    template <typename D> using consume = Windows::Devices::Bluetooth::Background::impl_IGattCharacteristicNotificationTriggerDetails<D>;
};

template <> struct traits<Windows::Devices::Bluetooth::Background::IRfcommConnectionTriggerDetails>
{
    using abi = ABI::Windows::Devices::Bluetooth::Background::IRfcommConnectionTriggerDetails;
    template <typename D> using consume = Windows::Devices::Bluetooth::Background::impl_IRfcommConnectionTriggerDetails<D>;
};

template <> struct traits<Windows::Devices::Bluetooth::Background::IRfcommInboundConnectionInformation>
{
    using abi = ABI::Windows::Devices::Bluetooth::Background::IRfcommInboundConnectionInformation;
    template <typename D> using consume = Windows::Devices::Bluetooth::Background::impl_IRfcommInboundConnectionInformation<D>;
};

template <> struct traits<Windows::Devices::Bluetooth::Background::IRfcommOutboundConnectionInformation>
{
    using abi = ABI::Windows::Devices::Bluetooth::Background::IRfcommOutboundConnectionInformation;
    template <typename D> using consume = Windows::Devices::Bluetooth::Background::impl_IRfcommOutboundConnectionInformation<D>;
};

template <> struct traits<Windows::Devices::Bluetooth::Background::BluetoothLEAdvertisementPublisherTriggerDetails>
{
    using abi = ABI::Windows::Devices::Bluetooth::Background::BluetoothLEAdvertisementPublisherTriggerDetails;
    using default_interface = Windows::Devices::Bluetooth::Background::IBluetoothLEAdvertisementPublisherTriggerDetails;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Devices.Bluetooth.Background.BluetoothLEAdvertisementPublisherTriggerDetails"; }
};

template <> struct traits<Windows::Devices::Bluetooth::Background::BluetoothLEAdvertisementWatcherTriggerDetails>
{
    using abi = ABI::Windows::Devices::Bluetooth::Background::BluetoothLEAdvertisementWatcherTriggerDetails;
    using default_interface = Windows::Devices::Bluetooth::Background::IBluetoothLEAdvertisementWatcherTriggerDetails;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Devices.Bluetooth.Background.BluetoothLEAdvertisementWatcherTriggerDetails"; }
};

template <> struct traits<Windows::Devices::Bluetooth::Background::GattCharacteristicNotificationTriggerDetails>
{
    using abi = ABI::Windows::Devices::Bluetooth::Background::GattCharacteristicNotificationTriggerDetails;
    using default_interface = Windows::Devices::Bluetooth::Background::IGattCharacteristicNotificationTriggerDetails;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Devices.Bluetooth.Background.GattCharacteristicNotificationTriggerDetails"; }
};

template <> struct traits<Windows::Devices::Bluetooth::Background::RfcommConnectionTriggerDetails>
{
    using abi = ABI::Windows::Devices::Bluetooth::Background::RfcommConnectionTriggerDetails;
    using default_interface = Windows::Devices::Bluetooth::Background::IRfcommConnectionTriggerDetails;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Devices.Bluetooth.Background.RfcommConnectionTriggerDetails"; }
};

template <> struct traits<Windows::Devices::Bluetooth::Background::RfcommInboundConnectionInformation>
{
    using abi = ABI::Windows::Devices::Bluetooth::Background::RfcommInboundConnectionInformation;
    using default_interface = Windows::Devices::Bluetooth::Background::IRfcommInboundConnectionInformation;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Devices.Bluetooth.Background.RfcommInboundConnectionInformation"; }
};

template <> struct traits<Windows::Devices::Bluetooth::Background::RfcommOutboundConnectionInformation>
{
    using abi = ABI::Windows::Devices::Bluetooth::Background::RfcommOutboundConnectionInformation;
    using default_interface = Windows::Devices::Bluetooth::Background::IRfcommOutboundConnectionInformation;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Devices.Bluetooth.Background.RfcommOutboundConnectionInformation"; }
};

}

}
