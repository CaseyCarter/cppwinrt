// C++ for the Windows Runtime v1.29
// Copyright (c) 2016 Microsoft Corporation

#pragma once

#include "Windows.Devices.Sensors.Custom.1.h"

WINRT_EXPORT namespace winrt {

namespace ABI::Windows::Foundation::Collections {

#ifndef WINRT_GENERIC_09335560_6c6b_5a26_9348_97b781132b20
#define WINRT_GENERIC_09335560_6c6b_5a26_9348_97b781132b20
template <> struct __declspec(uuid("09335560-6c6b-5a26-9348-97b781132b20")) __declspec(novtable) IKeyValuePair<hstring, Windows::IInspectable> : impl_IKeyValuePair<hstring, Windows::IInspectable> {};
#endif

#ifndef WINRT_GENERIC_bb78502a_f79d_54fa_92c9_90c5039fdf7e
#define WINRT_GENERIC_bb78502a_f79d_54fa_92c9_90c5039fdf7e
template <> struct __declspec(uuid("bb78502a-f79d-54fa-92c9-90c5039fdf7e")) __declspec(novtable) IMapView<hstring, Windows::IInspectable> : impl_IMapView<hstring, Windows::IInspectable> {};
#endif


}

namespace ABI::Windows::Foundation {

#ifndef WINRT_GENERIC_7fbfbe55_9674_54e3_a269_9caa820ed23c
#define WINRT_GENERIC_7fbfbe55_9674_54e3_a269_9caa820ed23c
template <> struct __declspec(uuid("7fbfbe55-9674-54e3-a269-9caa820ed23c")) __declspec(novtable) IAsyncOperation<Windows::Devices::Sensors::Custom::CustomSensor> : impl_IAsyncOperation<Windows::Devices::Sensors::Custom::CustomSensor> {};
#endif

#ifndef WINRT_GENERIC_aa9460cb_f08c_5963_b232_cc4075e984e7
#define WINRT_GENERIC_aa9460cb_f08c_5963_b232_cc4075e984e7
template <> struct __declspec(uuid("aa9460cb-f08c-5963-b232-cc4075e984e7")) __declspec(novtable) TypedEventHandler<Windows::Devices::Sensors::Custom::CustomSensor, Windows::Devices::Sensors::Custom::CustomSensorReadingChangedEventArgs> : impl_TypedEventHandler<Windows::Devices::Sensors::Custom::CustomSensor, Windows::Devices::Sensors::Custom::CustomSensorReadingChangedEventArgs> {};
#endif

#ifndef WINRT_GENERIC_808b62d7_6e02_5680_a59e_118a98a4e70f
#define WINRT_GENERIC_808b62d7_6e02_5680_a59e_118a98a4e70f
template <> struct __declspec(uuid("808b62d7-6e02-5680-a59e-118a98a4e70f")) __declspec(novtable) AsyncOperationCompletedHandler<Windows::Devices::Sensors::Custom::CustomSensor> : impl_AsyncOperationCompletedHandler<Windows::Devices::Sensors::Custom::CustomSensor> {};
#endif


}

namespace ABI::Windows::Foundation::Collections {

#ifndef WINRT_GENERIC_fe2f3d47_5d47_5499_8374_430c7cda0204
#define WINRT_GENERIC_fe2f3d47_5d47_5499_8374_430c7cda0204
template <> struct __declspec(uuid("fe2f3d47-5d47-5499-8374-430c7cda0204")) __declspec(novtable) IIterable<Windows::Foundation::Collections::IKeyValuePair<hstring, Windows::IInspectable>> : impl_IIterable<Windows::Foundation::Collections::IKeyValuePair<hstring, Windows::IInspectable>> {};
#endif

#ifndef WINRT_GENERIC_5db5fa32_707c_5849_a06b_91c8eb9d10e8
#define WINRT_GENERIC_5db5fa32_707c_5849_a06b_91c8eb9d10e8
template <> struct __declspec(uuid("5db5fa32-707c-5849-a06b-91c8eb9d10e8")) __declspec(novtable) IIterator<Windows::Foundation::Collections::IKeyValuePair<hstring, Windows::IInspectable>> : impl_IIterator<Windows::Foundation::Collections::IKeyValuePair<hstring, Windows::IInspectable>> {};
#endif


}

namespace Windows::Devices::Sensors::Custom {

template <typename D>
struct WINRT_EBO impl_ICustomSensor
{
    Windows::Devices::Sensors::Custom::CustomSensorReading GetCurrentReading() const;
    uint32_t MinimumReportInterval() const;
    void ReportInterval(uint32_t value) const;
    uint32_t ReportInterval() const;
    hstring DeviceId() const;
    event_token ReadingChanged(const Windows::Foundation::TypedEventHandler<Windows::Devices::Sensors::Custom::CustomSensor, Windows::Devices::Sensors::Custom::CustomSensorReadingChangedEventArgs> & handler) const;
    using ReadingChanged_revoker = event_revoker<ICustomSensor>;
    ReadingChanged_revoker ReadingChanged(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Devices::Sensors::Custom::CustomSensor, Windows::Devices::Sensors::Custom::CustomSensorReadingChangedEventArgs> & handler) const;
    void ReadingChanged(event_token token) const;
};

template <typename D>
struct WINRT_EBO impl_ICustomSensorReading
{
    Windows::Foundation::DateTime Timestamp() const;
    Windows::Foundation::Collections::IMapView<hstring, Windows::IInspectable> Properties() const;
};

template <typename D>
struct WINRT_EBO impl_ICustomSensorReadingChangedEventArgs
{
    Windows::Devices::Sensors::Custom::CustomSensorReading Reading() const;
};

template <typename D>
struct WINRT_EBO impl_ICustomSensorStatics
{
    hstring GetDeviceSelector(GUID interfaceId) const;
    Windows::Foundation::IAsyncOperation<Windows::Devices::Sensors::Custom::CustomSensor> FromIdAsync(hstring_ref sensorId) const;
};

struct ICustomSensor :
    Windows::IInspectable,
    impl::consume<ICustomSensor>
{
    ICustomSensor(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<ICustomSensor>(m_ptr); }
};

struct ICustomSensorReading :
    Windows::IInspectable,
    impl::consume<ICustomSensorReading>
{
    ICustomSensorReading(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<ICustomSensorReading>(m_ptr); }
};

struct ICustomSensorReadingChangedEventArgs :
    Windows::IInspectable,
    impl::consume<ICustomSensorReadingChangedEventArgs>
{
    ICustomSensorReadingChangedEventArgs(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<ICustomSensorReadingChangedEventArgs>(m_ptr); }
};

struct ICustomSensorStatics :
    Windows::IInspectable,
    impl::consume<ICustomSensorStatics>
{
    ICustomSensorStatics(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<ICustomSensorStatics>(m_ptr); }
};

}

}
