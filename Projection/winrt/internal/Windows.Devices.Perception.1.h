// C++ for the Windows Runtime v1.29
// Copyright (c) 2016 Microsoft Corporation

#pragma once

#include "../base.h"
#include "Windows.Devices.Perception.0.h"
#include "Windows.Devices.Enumeration.0.h"
#include "Windows.Foundation.0.h"
#include "Windows.Foundation.Collections.0.h"
#include "Windows.Graphics.Imaging.0.h"
#include "Windows.Media.0.h"
#include "Windows.Media.Devices.Core.0.h"
#include "Windows.Foundation.1.h"
#include "Windows.Foundation.Collections.1.h"

WINRT_EXPORT namespace winrt {

namespace ABI::Windows::Devices::Perception {

struct __declspec(uuid("08c03978-437a-4d97-a663-fd3195600249")) __declspec(novtable) IKnownCameraIntrinsicsPropertiesStatics : Windows::IInspectable
{
    virtual HRESULT __stdcall get_FocalLength(hstring * value) = 0;
    virtual HRESULT __stdcall get_PrincipalPoint(hstring * value) = 0;
    virtual HRESULT __stdcall get_RadialDistortion(hstring * value) = 0;
    virtual HRESULT __stdcall get_TangentialDistortion(hstring * value) = 0;
};

struct __declspec(uuid("5df1cca2-01f8-4a87-b859-d5e5b7e1de4b")) __declspec(novtable) IKnownPerceptionColorFrameSourcePropertiesStatics : Windows::IInspectable
{
    virtual HRESULT __stdcall get_Exposure(hstring * value) = 0;
    virtual HRESULT __stdcall get_AutoExposureEnabled(hstring * value) = 0;
    virtual HRESULT __stdcall get_ExposureCompensation(hstring * value) = 0;
};

struct __declspec(uuid("5df1cca2-01f8-4a87-b859-d5e5b7e1de4a")) __declspec(novtable) IKnownPerceptionDepthFrameSourcePropertiesStatics : Windows::IInspectable
{
    virtual HRESULT __stdcall get_MinDepth(hstring * value) = 0;
    virtual HRESULT __stdcall get_MaxDepth(hstring * value) = 0;
};

struct __declspec(uuid("5df1cca2-01f8-4a87-b859-d5e5b7e1de47")) __declspec(novtable) IKnownPerceptionFrameSourcePropertiesStatics : Windows::IInspectable
{
    virtual HRESULT __stdcall get_Id(hstring * value) = 0;
    virtual HRESULT __stdcall get_PhysicalDeviceIds(hstring * value) = 0;
    virtual HRESULT __stdcall get_FrameKind(hstring * value) = 0;
    virtual HRESULT __stdcall get_DeviceModelVersion(hstring * value) = 0;
    virtual HRESULT __stdcall get_EnclosureLocation(hstring * value) = 0;
};

struct __declspec(uuid("a9c86871-05dc-4a4d-8a5c-a4ecf26bbc46")) __declspec(novtable) IKnownPerceptionFrameSourcePropertiesStatics2 : Windows::IInspectable
{
    virtual HRESULT __stdcall get_DeviceId(hstring * value) = 0;
};

struct __declspec(uuid("5df1cca2-01f8-4a87-b859-d5e5b7e1de49")) __declspec(novtable) IKnownPerceptionInfraredFrameSourcePropertiesStatics : Windows::IInspectable
{
    virtual HRESULT __stdcall get_Exposure(hstring * value) = 0;
    virtual HRESULT __stdcall get_AutoExposureEnabled(hstring * value) = 0;
    virtual HRESULT __stdcall get_ExposureCompensation(hstring * value) = 0;
    virtual HRESULT __stdcall get_ActiveIlluminationEnabled(hstring * value) = 0;
    virtual HRESULT __stdcall get_AmbientSubtractionEnabled(hstring * value) = 0;
    virtual HRESULT __stdcall get_StructureLightPatternEnabled(hstring * value) = 0;
    virtual HRESULT __stdcall get_InterleavedIlluminationEnabled(hstring * value) = 0;
};

struct __declspec(uuid("5df1cca2-01f8-4a87-b859-d5e5b7e1de48")) __declspec(novtable) IKnownPerceptionVideoFrameSourcePropertiesStatics : Windows::IInspectable
{
    virtual HRESULT __stdcall get_VideoProfile(hstring * value) = 0;
    virtual HRESULT __stdcall get_SupportedVideoProfiles(hstring * value) = 0;
    virtual HRESULT __stdcall get_AvailableVideoProfiles(hstring * value) = 0;
    virtual HRESULT __stdcall get_IsMirrored(hstring * value) = 0;
    virtual HRESULT __stdcall get_CameraIntrinsics(hstring * value) = 0;
};

struct __declspec(uuid("8f08e2e7-5a76-43e3-a13a-da3d91a9ef98")) __declspec(novtable) IKnownPerceptionVideoProfilePropertiesStatics : Windows::IInspectable
{
    virtual HRESULT __stdcall get_BitmapPixelFormat(hstring * value) = 0;
    virtual HRESULT __stdcall get_BitmapAlphaMode(hstring * value) = 0;
    virtual HRESULT __stdcall get_Width(hstring * value) = 0;
    virtual HRESULT __stdcall get_Height(hstring * value) = 0;
    virtual HRESULT __stdcall get_FrameDuration(hstring * value) = 0;
};

struct __declspec(uuid("fe621549-2cbf-4f94-9861-f817ea317747")) __declspec(novtable) IPerceptionColorFrame : Windows::IInspectable
{
    virtual HRESULT __stdcall get_VideoFrame(Windows::Media::IVideoFrame ** value) = 0;
};

struct __declspec(uuid("8fad02d5-86f7-4d8d-b966-5a3761ba9f59")) __declspec(novtable) IPerceptionColorFrameArrivedEventArgs : Windows::IInspectable
{
    virtual HRESULT __stdcall get_RelativeTime(Windows::Foundation::TimeSpan * value) = 0;
    virtual HRESULT __stdcall abi_TryOpenFrame(Windows::Devices::Perception::IPerceptionColorFrame ** result) = 0;
};

struct __declspec(uuid("7650f56e-b9f5-461b-83ad-f222af2aaadc")) __declspec(novtable) IPerceptionColorFrameReader : Windows::IInspectable
{
    virtual HRESULT __stdcall add_FrameArrived(Windows::Foundation::TypedEventHandler<Windows::Devices::Perception::PerceptionColorFrameReader, Windows::Devices::Perception::PerceptionColorFrameArrivedEventArgs> * handler, event_token * token) = 0;
    virtual HRESULT __stdcall remove_FrameArrived(event_token token) = 0;
    virtual HRESULT __stdcall get_Source(Windows::Devices::Perception::IPerceptionColorFrameSource ** value) = 0;
    virtual HRESULT __stdcall get_IsPaused(bool * value) = 0;
    virtual HRESULT __stdcall put_IsPaused(bool value) = 0;
    virtual HRESULT __stdcall abi_TryReadLatestFrame(Windows::Devices::Perception::IPerceptionColorFrame ** result) = 0;
};

struct __declspec(uuid("dc6dba7c-0b58-468d-9ca1-6db04cc0477c")) __declspec(novtable) IPerceptionColorFrameSource : Windows::IInspectable
{
    virtual HRESULT __stdcall add_AvailableChanged(Windows::Foundation::TypedEventHandler<Windows::Devices::Perception::PerceptionColorFrameSource, Windows::IInspectable> * handler, event_token * token) = 0;
    virtual HRESULT __stdcall remove_AvailableChanged(event_token token) = 0;
    virtual HRESULT __stdcall add_ActiveChanged(Windows::Foundation::TypedEventHandler<Windows::Devices::Perception::PerceptionColorFrameSource, Windows::IInspectable> * handler, event_token * token) = 0;
    virtual HRESULT __stdcall remove_ActiveChanged(event_token token) = 0;
    virtual HRESULT __stdcall add_PropertiesChanged(Windows::Foundation::TypedEventHandler<Windows::Devices::Perception::PerceptionColorFrameSource, Windows::Devices::Perception::PerceptionFrameSourcePropertiesChangedEventArgs> * handler, event_token * token) = 0;
    virtual HRESULT __stdcall remove_PropertiesChanged(event_token token) = 0;
    virtual HRESULT __stdcall add_VideoProfileChanged(Windows::Foundation::TypedEventHandler<Windows::Devices::Perception::PerceptionColorFrameSource, Windows::IInspectable> * handler, event_token * token) = 0;
    virtual HRESULT __stdcall remove_VideoProfileChanged(event_token token) = 0;
    virtual HRESULT __stdcall add_CameraIntrinsicsChanged(Windows::Foundation::TypedEventHandler<Windows::Devices::Perception::PerceptionColorFrameSource, Windows::IInspectable> * handler, event_token * token) = 0;
    virtual HRESULT __stdcall remove_CameraIntrinsicsChanged(event_token token) = 0;
    virtual HRESULT __stdcall get_Id(hstring * value) = 0;
    virtual HRESULT __stdcall get_DisplayName(hstring * value) = 0;
    virtual HRESULT __stdcall get_DeviceKind(hstring * value) = 0;
    virtual HRESULT __stdcall get_Available(bool * value) = 0;
    virtual HRESULT __stdcall get_Active(bool * value) = 0;
    virtual HRESULT __stdcall get_IsControlled(bool * value) = 0;
    virtual HRESULT __stdcall get_Properties(Windows::Foundation::Collections::IMapView<hstring, Windows::IInspectable> ** value) = 0;
    virtual HRESULT __stdcall get_SupportedVideoProfiles(Windows::Foundation::Collections::IVectorView<Windows::Devices::Perception::PerceptionVideoProfile> ** value) = 0;
    virtual HRESULT __stdcall get_AvailableVideoProfiles(Windows::Foundation::Collections::IVectorView<Windows::Devices::Perception::PerceptionVideoProfile> ** value) = 0;
    virtual HRESULT __stdcall get_VideoProfile(Windows::Devices::Perception::IPerceptionVideoProfile ** value) = 0;
    virtual HRESULT __stdcall get_CameraIntrinsics(Windows::Media::Devices::Core::ICameraIntrinsics ** value) = 0;
    virtual HRESULT __stdcall abi_AcquireControlSession(Windows::Devices::Perception::IPerceptionControlSession ** value) = 0;
    virtual HRESULT __stdcall abi_CanControlIndependentlyFrom(hstring targetId, bool * result) = 0;
    virtual HRESULT __stdcall abi_IsCorrelatedWith(hstring targetId, bool * result) = 0;
    virtual HRESULT __stdcall abi_TryGetTransformTo(hstring targetId, Windows::Foundation::Numerics::float4x4 * result, bool * hasResult) = 0;
    virtual HRESULT __stdcall abi_TryGetDepthCorrelatedCameraIntrinsicsAsync(Windows::Devices::Perception::IPerceptionDepthFrameSource * correlatedDepthFrameSource, Windows::Foundation::IAsyncOperation<Windows::Devices::Perception::PerceptionDepthCorrelatedCameraIntrinsics> ** result) = 0;
    virtual HRESULT __stdcall abi_TryGetDepthCorrelatedCoordinateMapperAsync(hstring targetSourceId, Windows::Devices::Perception::IPerceptionDepthFrameSource * correlatedDepthFrameSource, Windows::Foundation::IAsyncOperation<Windows::Devices::Perception::PerceptionDepthCorrelatedCoordinateMapper> ** result) = 0;
    virtual HRESULT __stdcall abi_TrySetVideoProfileAsync(Windows::Devices::Perception::IPerceptionControlSession * controlSession, Windows::Devices::Perception::IPerceptionVideoProfile * profile, Windows::Foundation::IAsyncOperation<Windows::Devices::Perception::PerceptionFrameSourcePropertyChangeResult> ** result) = 0;
    virtual HRESULT __stdcall abi_OpenReader(Windows::Devices::Perception::IPerceptionColorFrameReader ** result) = 0;
};

struct __declspec(uuid("f88008e5-5631-45ed-ad98-8c6aa04cfb91")) __declspec(novtable) IPerceptionColorFrameSource2 : Windows::IInspectable
{
    virtual HRESULT __stdcall get_DeviceId(hstring * value) = 0;
};

struct __declspec(uuid("d16bf4e6-da24-442c-bbd5-55549b5b94f3")) __declspec(novtable) IPerceptionColorFrameSourceAddedEventArgs : Windows::IInspectable
{
    virtual HRESULT __stdcall get_FrameSource(Windows::Devices::Perception::IPerceptionColorFrameSource ** value) = 0;
};

struct __declspec(uuid("d277fa69-eb4c-42ef-ba4f-288f615c93c1")) __declspec(novtable) IPerceptionColorFrameSourceRemovedEventArgs : Windows::IInspectable
{
    virtual HRESULT __stdcall get_FrameSource(Windows::Devices::Perception::IPerceptionColorFrameSource ** value) = 0;
};

struct __declspec(uuid("5df3cca2-01f8-4a87-b859-d5e5b7e1de49")) __declspec(novtable) IPerceptionColorFrameSourceStatics : Windows::IInspectable
{
    virtual HRESULT __stdcall abi_CreateWatcher(Windows::Devices::Perception::IPerceptionColorFrameSourceWatcher ** watcher) = 0;
    virtual HRESULT __stdcall abi_FindAllAsync(Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::Devices::Perception::PerceptionColorFrameSource>> ** result) = 0;
    virtual HRESULT __stdcall abi_FromIdAsync(hstring id, Windows::Foundation::IAsyncOperation<Windows::Devices::Perception::PerceptionColorFrameSource> ** result) = 0;
    virtual HRESULT __stdcall abi_RequestAccessAsync(Windows::Foundation::IAsyncOperation<winrt::Windows::Devices::Perception::PerceptionFrameSourceAccessStatus> ** result) = 0;
};

struct __declspec(uuid("96bd1392-e667-40c4-89f9-1462dea6a9cc")) __declspec(novtable) IPerceptionColorFrameSourceWatcher : Windows::IInspectable
{
    virtual HRESULT __stdcall add_SourceAdded(Windows::Foundation::TypedEventHandler<Windows::Devices::Perception::PerceptionColorFrameSourceWatcher, Windows::Devices::Perception::PerceptionColorFrameSourceAddedEventArgs> * handler, event_token * token) = 0;
    virtual HRESULT __stdcall remove_SourceAdded(event_token token) = 0;
    virtual HRESULT __stdcall add_SourceRemoved(Windows::Foundation::TypedEventHandler<Windows::Devices::Perception::PerceptionColorFrameSourceWatcher, Windows::Devices::Perception::PerceptionColorFrameSourceRemovedEventArgs> * handler, event_token * token) = 0;
    virtual HRESULT __stdcall remove_SourceRemoved(event_token token) = 0;
    virtual HRESULT __stdcall add_Stopped(Windows::Foundation::TypedEventHandler<Windows::Devices::Perception::PerceptionColorFrameSourceWatcher, Windows::IInspectable> * handler, event_token * token) = 0;
    virtual HRESULT __stdcall remove_Stopped(event_token token) = 0;
    virtual HRESULT __stdcall add_EnumerationCompleted(Windows::Foundation::TypedEventHandler<Windows::Devices::Perception::PerceptionColorFrameSourceWatcher, Windows::IInspectable> * handler, event_token * token) = 0;
    virtual HRESULT __stdcall remove_EnumerationCompleted(event_token token) = 0;
    virtual HRESULT __stdcall get_Status(winrt::Windows::Devices::Enumeration::DeviceWatcherStatus * value) = 0;
    virtual HRESULT __stdcall abi_Start() = 0;
    virtual HRESULT __stdcall abi_Stop() = 0;
};

struct __declspec(uuid("99998653-5a3d-417f-9239-f1889e548b48")) __declspec(novtable) IPerceptionControlSession : Windows::IInspectable
{
    virtual HRESULT __stdcall add_ControlLost(Windows::Foundation::TypedEventHandler<Windows::Devices::Perception::PerceptionControlSession, Windows::IInspectable> * handler, event_token * token) = 0;
    virtual HRESULT __stdcall remove_ControlLost(event_token token) = 0;
    virtual HRESULT __stdcall abi_TrySetPropertyAsync(hstring name, Windows::IInspectable * value, Windows::Foundation::IAsyncOperation<Windows::Devices::Perception::PerceptionFrameSourcePropertyChangeResult> ** result) = 0;
};

struct __declspec(uuid("6548ca01-86de-5be1-6582-807fcf4c95cf")) __declspec(novtable) IPerceptionDepthCorrelatedCameraIntrinsics : Windows::IInspectable
{
    virtual HRESULT __stdcall abi_UnprojectPixelAtCorrelatedDepth(Windows::Foundation::Point pixelCoordinate, Windows::Devices::Perception::IPerceptionDepthFrame * depthFrame, Windows::Foundation::Numerics::float3 * result) = 0;
    virtual HRESULT __stdcall abi_UnprojectPixelsAtCorrelatedDepth(uint32_t __sourceCoordinatesSize, Windows::Foundation::Point * sourceCoordinates, Windows::Devices::Perception::IPerceptionDepthFrame * depthFrame, uint32_t __resultsSize, Windows::Foundation::Numerics::float3 * results) = 0;
    virtual HRESULT __stdcall abi_UnprojectRegionPixelsAtCorrelatedDepthAsync(Windows::Foundation::Rect region, Windows::Devices::Perception::IPerceptionDepthFrame * depthFrame, uint32_t __resultsSize, Windows::Foundation::Numerics::float3 * results, Windows::Foundation::IAsyncAction ** result) = 0;
    virtual HRESULT __stdcall abi_UnprojectAllPixelsAtCorrelatedDepthAsync(Windows::Devices::Perception::IPerceptionDepthFrame * depthFrame, uint32_t __resultsSize, Windows::Foundation::Numerics::float3 * results, Windows::Foundation::IAsyncAction ** result) = 0;
};

struct __declspec(uuid("5b4d9d1d-b5f6-469c-b8c2-b97a45e6863b")) __declspec(novtable) IPerceptionDepthCorrelatedCoordinateMapper : Windows::IInspectable
{
    virtual HRESULT __stdcall abi_MapPixelToTarget(Windows::Foundation::Point sourcePixelCoordinate, Windows::Devices::Perception::IPerceptionDepthFrame * depthFrame, Windows::Foundation::Point * result) = 0;
    virtual HRESULT __stdcall abi_MapPixelsToTarget(uint32_t __sourceCoordinatesSize, Windows::Foundation::Point * sourceCoordinates, Windows::Devices::Perception::IPerceptionDepthFrame * depthFrame, uint32_t __resultsSize, Windows::Foundation::Point * results) = 0;
    virtual HRESULT __stdcall abi_MapRegionOfPixelsToTargetAsync(Windows::Foundation::Rect region, Windows::Devices::Perception::IPerceptionDepthFrame * depthFrame, uint32_t __targetCoordinatesSize, Windows::Foundation::Point * targetCoordinates, Windows::Foundation::IAsyncAction ** result) = 0;
    virtual HRESULT __stdcall abi_MapAllPixelsToTargetAsync(Windows::Devices::Perception::IPerceptionDepthFrame * depthFrame, uint32_t __targetCoordinatesSize, Windows::Foundation::Point * targetCoordinates, Windows::Foundation::IAsyncAction ** result) = 0;
};

struct __declspec(uuid("a37b81fc-9906-4ffd-9161-0024b360b657")) __declspec(novtable) IPerceptionDepthFrame : Windows::IInspectable
{
    virtual HRESULT __stdcall get_VideoFrame(Windows::Media::IVideoFrame ** value) = 0;
};

struct __declspec(uuid("443d25b2-b282-4637-9173-ac978435c985")) __declspec(novtable) IPerceptionDepthFrameArrivedEventArgs : Windows::IInspectable
{
    virtual HRESULT __stdcall get_RelativeTime(Windows::Foundation::TimeSpan * value) = 0;
    virtual HRESULT __stdcall abi_TryOpenFrame(Windows::Devices::Perception::IPerceptionDepthFrame ** result) = 0;
};

struct __declspec(uuid("b1a3c09f-299b-4612-a4f7-270f25a096ec")) __declspec(novtable) IPerceptionDepthFrameReader : Windows::IInspectable
{
    virtual HRESULT __stdcall add_FrameArrived(Windows::Foundation::TypedEventHandler<Windows::Devices::Perception::PerceptionDepthFrameReader, Windows::Devices::Perception::PerceptionDepthFrameArrivedEventArgs> * handler, event_token * token) = 0;
    virtual HRESULT __stdcall remove_FrameArrived(event_token token) = 0;
    virtual HRESULT __stdcall get_Source(Windows::Devices::Perception::IPerceptionDepthFrameSource ** value) = 0;
    virtual HRESULT __stdcall get_IsPaused(bool * value) = 0;
    virtual HRESULT __stdcall put_IsPaused(bool value) = 0;
    virtual HRESULT __stdcall abi_TryReadLatestFrame(Windows::Devices::Perception::IPerceptionDepthFrame ** result) = 0;
};

struct __declspec(uuid("79d433d6-47fb-4df1-bfc9-f01d40bd9942")) __declspec(novtable) IPerceptionDepthFrameSource : Windows::IInspectable
{
    virtual HRESULT __stdcall add_AvailableChanged(Windows::Foundation::TypedEventHandler<Windows::Devices::Perception::PerceptionDepthFrameSource, Windows::IInspectable> * handler, event_token * token) = 0;
    virtual HRESULT __stdcall remove_AvailableChanged(event_token token) = 0;
    virtual HRESULT __stdcall add_ActiveChanged(Windows::Foundation::TypedEventHandler<Windows::Devices::Perception::PerceptionDepthFrameSource, Windows::IInspectable> * handler, event_token * token) = 0;
    virtual HRESULT __stdcall remove_ActiveChanged(event_token token) = 0;
    virtual HRESULT __stdcall add_PropertiesChanged(Windows::Foundation::TypedEventHandler<Windows::Devices::Perception::PerceptionDepthFrameSource, Windows::Devices::Perception::PerceptionFrameSourcePropertiesChangedEventArgs> * handler, event_token * token) = 0;
    virtual HRESULT __stdcall remove_PropertiesChanged(event_token token) = 0;
    virtual HRESULT __stdcall add_VideoProfileChanged(Windows::Foundation::TypedEventHandler<Windows::Devices::Perception::PerceptionDepthFrameSource, Windows::IInspectable> * handler, event_token * token) = 0;
    virtual HRESULT __stdcall remove_VideoProfileChanged(event_token token) = 0;
    virtual HRESULT __stdcall add_CameraIntrinsicsChanged(Windows::Foundation::TypedEventHandler<Windows::Devices::Perception::PerceptionDepthFrameSource, Windows::IInspectable> * handler, event_token * token) = 0;
    virtual HRESULT __stdcall remove_CameraIntrinsicsChanged(event_token token) = 0;
    virtual HRESULT __stdcall get_Id(hstring * value) = 0;
    virtual HRESULT __stdcall get_DisplayName(hstring * value) = 0;
    virtual HRESULT __stdcall get_DeviceKind(hstring * value) = 0;
    virtual HRESULT __stdcall get_Available(bool * value) = 0;
    virtual HRESULT __stdcall get_Active(bool * value) = 0;
    virtual HRESULT __stdcall get_IsControlled(bool * value) = 0;
    virtual HRESULT __stdcall get_Properties(Windows::Foundation::Collections::IMapView<hstring, Windows::IInspectable> ** value) = 0;
    virtual HRESULT __stdcall get_SupportedVideoProfiles(Windows::Foundation::Collections::IVectorView<Windows::Devices::Perception::PerceptionVideoProfile> ** value) = 0;
    virtual HRESULT __stdcall get_AvailableVideoProfiles(Windows::Foundation::Collections::IVectorView<Windows::Devices::Perception::PerceptionVideoProfile> ** value) = 0;
    virtual HRESULT __stdcall get_VideoProfile(Windows::Devices::Perception::IPerceptionVideoProfile ** value) = 0;
    virtual HRESULT __stdcall get_CameraIntrinsics(Windows::Media::Devices::Core::ICameraIntrinsics ** value) = 0;
    virtual HRESULT __stdcall abi_AcquireControlSession(Windows::Devices::Perception::IPerceptionControlSession ** result) = 0;
    virtual HRESULT __stdcall abi_CanControlIndependentlyFrom(hstring targetId, bool * result) = 0;
    virtual HRESULT __stdcall abi_IsCorrelatedWith(hstring targetId, bool * result) = 0;
    virtual HRESULT __stdcall abi_TryGetTransformTo(hstring targetId, Windows::Foundation::Numerics::float4x4 * result, bool * hasResult) = 0;
    virtual HRESULT __stdcall abi_TryGetDepthCorrelatedCameraIntrinsicsAsync(Windows::Devices::Perception::IPerceptionDepthFrameSource * target, Windows::Foundation::IAsyncOperation<Windows::Devices::Perception::PerceptionDepthCorrelatedCameraIntrinsics> ** result) = 0;
    virtual HRESULT __stdcall abi_TryGetDepthCorrelatedCoordinateMapperAsync(hstring targetId, Windows::Devices::Perception::IPerceptionDepthFrameSource * depthFrameSourceToMapWith, Windows::Foundation::IAsyncOperation<Windows::Devices::Perception::PerceptionDepthCorrelatedCoordinateMapper> ** result) = 0;
    virtual HRESULT __stdcall abi_TrySetVideoProfileAsync(Windows::Devices::Perception::IPerceptionControlSession * controlSession, Windows::Devices::Perception::IPerceptionVideoProfile * profile, Windows::Foundation::IAsyncOperation<Windows::Devices::Perception::PerceptionFrameSourcePropertyChangeResult> ** result) = 0;
    virtual HRESULT __stdcall abi_OpenReader(Windows::Devices::Perception::IPerceptionDepthFrameReader ** result) = 0;
};

struct __declspec(uuid("e3d23d2e-6e2c-4e6d-91d9-704cd8dff79d")) __declspec(novtable) IPerceptionDepthFrameSource2 : Windows::IInspectable
{
    virtual HRESULT __stdcall get_DeviceId(hstring * value) = 0;
};

struct __declspec(uuid("93a48168-8bf8-45d2-a2f8-4ac0931cc7a6")) __declspec(novtable) IPerceptionDepthFrameSourceAddedEventArgs : Windows::IInspectable
{
    virtual HRESULT __stdcall get_FrameSource(Windows::Devices::Perception::IPerceptionDepthFrameSource ** value) = 0;
};

struct __declspec(uuid("a0c0cc4d-e96c-4d81-86dd-38b95e49c6df")) __declspec(novtable) IPerceptionDepthFrameSourceRemovedEventArgs : Windows::IInspectable
{
    virtual HRESULT __stdcall get_FrameSource(Windows::Devices::Perception::IPerceptionDepthFrameSource ** value) = 0;
};

struct __declspec(uuid("5df3cca2-01f8-4a87-b859-d5e5b7e1de48")) __declspec(novtable) IPerceptionDepthFrameSourceStatics : Windows::IInspectable
{
    virtual HRESULT __stdcall abi_CreateWatcher(Windows::Devices::Perception::IPerceptionDepthFrameSourceWatcher ** watcher) = 0;
    virtual HRESULT __stdcall abi_FindAllAsync(Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::Devices::Perception::PerceptionDepthFrameSource>> ** result) = 0;
    virtual HRESULT __stdcall abi_FromIdAsync(hstring id, Windows::Foundation::IAsyncOperation<Windows::Devices::Perception::PerceptionDepthFrameSource> ** result) = 0;
    virtual HRESULT __stdcall abi_RequestAccessAsync(Windows::Foundation::IAsyncOperation<winrt::Windows::Devices::Perception::PerceptionFrameSourceAccessStatus> ** result) = 0;
};

struct __declspec(uuid("780e96d1-8d02-4d2b-ada4-5ba624a0eb10")) __declspec(novtable) IPerceptionDepthFrameSourceWatcher : Windows::IInspectable
{
    virtual HRESULT __stdcall add_SourceAdded(Windows::Foundation::TypedEventHandler<Windows::Devices::Perception::PerceptionDepthFrameSourceWatcher, Windows::Devices::Perception::PerceptionDepthFrameSourceAddedEventArgs> * handler, event_token * token) = 0;
    virtual HRESULT __stdcall remove_SourceAdded(event_token token) = 0;
    virtual HRESULT __stdcall add_SourceRemoved(Windows::Foundation::TypedEventHandler<Windows::Devices::Perception::PerceptionDepthFrameSourceWatcher, Windows::Devices::Perception::PerceptionDepthFrameSourceRemovedEventArgs> * handler, event_token * token) = 0;
    virtual HRESULT __stdcall remove_SourceRemoved(event_token token) = 0;
    virtual HRESULT __stdcall add_Stopped(Windows::Foundation::TypedEventHandler<Windows::Devices::Perception::PerceptionDepthFrameSourceWatcher, Windows::IInspectable> * handler, event_token * token) = 0;
    virtual HRESULT __stdcall remove_Stopped(event_token token) = 0;
    virtual HRESULT __stdcall add_EnumerationCompleted(Windows::Foundation::TypedEventHandler<Windows::Devices::Perception::PerceptionDepthFrameSourceWatcher, Windows::IInspectable> * handler, event_token * token) = 0;
    virtual HRESULT __stdcall remove_EnumerationCompleted(event_token token) = 0;
    virtual HRESULT __stdcall get_Status(winrt::Windows::Devices::Enumeration::DeviceWatcherStatus * value) = 0;
    virtual HRESULT __stdcall abi_Start() = 0;
    virtual HRESULT __stdcall abi_Stop() = 0;
};

struct __declspec(uuid("6c68e068-bcf1-4ecc-b891-7625d1244b6b")) __declspec(novtable) IPerceptionFrameSourcePropertiesChangedEventArgs : Windows::IInspectable
{
    virtual HRESULT __stdcall get_CollectionChange(winrt::Windows::Foundation::Collections::CollectionChange * value) = 0;
    virtual HRESULT __stdcall get_Key(hstring * value) = 0;
};

struct __declspec(uuid("1e33390a-3c90-4d22-b898-f42bba6418ff")) __declspec(novtable) IPerceptionFrameSourcePropertyChangeResult : Windows::IInspectable
{
    virtual HRESULT __stdcall get_Status(winrt::Windows::Devices::Perception::PerceptionFrameSourcePropertyChangeStatus * value) = 0;
    virtual HRESULT __stdcall get_NewValue(Windows::IInspectable ** value) = 0;
};

struct __declspec(uuid("b0886276-849e-4c7a-8ae6-b56064532153")) __declspec(novtable) IPerceptionInfraredFrame : Windows::IInspectable
{
    virtual HRESULT __stdcall get_VideoFrame(Windows::Media::IVideoFrame ** value) = 0;
};

struct __declspec(uuid("9f77fac7-b4bd-4857-9d50-be8ef075daef")) __declspec(novtable) IPerceptionInfraredFrameArrivedEventArgs : Windows::IInspectable
{
    virtual HRESULT __stdcall get_RelativeTime(Windows::Foundation::TimeSpan * value) = 0;
    virtual HRESULT __stdcall abi_TryOpenFrame(Windows::Devices::Perception::IPerceptionInfraredFrame ** result) = 0;
};

struct __declspec(uuid("7960ce18-d39b-4fc8-a04a-929734c6756c")) __declspec(novtable) IPerceptionInfraredFrameReader : Windows::IInspectable
{
    virtual HRESULT __stdcall add_FrameArrived(Windows::Foundation::TypedEventHandler<Windows::Devices::Perception::PerceptionInfraredFrameReader, Windows::Devices::Perception::PerceptionInfraredFrameArrivedEventArgs> * handler, event_token * token) = 0;
    virtual HRESULT __stdcall remove_FrameArrived(event_token token) = 0;
    virtual HRESULT __stdcall get_Source(Windows::Devices::Perception::IPerceptionInfraredFrameSource ** value) = 0;
    virtual HRESULT __stdcall get_IsPaused(bool * value) = 0;
    virtual HRESULT __stdcall put_IsPaused(bool value) = 0;
    virtual HRESULT __stdcall abi_TryReadLatestFrame(Windows::Devices::Perception::IPerceptionInfraredFrame ** result) = 0;
};

struct __declspec(uuid("55b08742-1808-494e-9e30-9d2a7be8f700")) __declspec(novtable) IPerceptionInfraredFrameSource : Windows::IInspectable
{
    virtual HRESULT __stdcall add_AvailableChanged(Windows::Foundation::TypedEventHandler<Windows::Devices::Perception::PerceptionInfraredFrameSource, Windows::IInspectable> * handler, event_token * token) = 0;
    virtual HRESULT __stdcall remove_AvailableChanged(event_token token) = 0;
    virtual HRESULT __stdcall add_ActiveChanged(Windows::Foundation::TypedEventHandler<Windows::Devices::Perception::PerceptionInfraredFrameSource, Windows::IInspectable> * handler, event_token * token) = 0;
    virtual HRESULT __stdcall remove_ActiveChanged(event_token token) = 0;
    virtual HRESULT __stdcall add_PropertiesChanged(Windows::Foundation::TypedEventHandler<Windows::Devices::Perception::PerceptionInfraredFrameSource, Windows::Devices::Perception::PerceptionFrameSourcePropertiesChangedEventArgs> * handler, event_token * token) = 0;
    virtual HRESULT __stdcall remove_PropertiesChanged(event_token token) = 0;
    virtual HRESULT __stdcall add_VideoProfileChanged(Windows::Foundation::TypedEventHandler<Windows::Devices::Perception::PerceptionInfraredFrameSource, Windows::IInspectable> * handler, event_token * token) = 0;
    virtual HRESULT __stdcall remove_VideoProfileChanged(event_token token) = 0;
    virtual HRESULT __stdcall add_CameraIntrinsicsChanged(Windows::Foundation::TypedEventHandler<Windows::Devices::Perception::PerceptionInfraredFrameSource, Windows::IInspectable> * handler, event_token * token) = 0;
    virtual HRESULT __stdcall remove_CameraIntrinsicsChanged(event_token token) = 0;
    virtual HRESULT __stdcall get_Id(hstring * value) = 0;
    virtual HRESULT __stdcall get_DisplayName(hstring * value) = 0;
    virtual HRESULT __stdcall get_DeviceKind(hstring * value) = 0;
    virtual HRESULT __stdcall get_Available(bool * value) = 0;
    virtual HRESULT __stdcall get_Active(bool * value) = 0;
    virtual HRESULT __stdcall get_IsControlled(bool * value) = 0;
    virtual HRESULT __stdcall get_Properties(Windows::Foundation::Collections::IMapView<hstring, Windows::IInspectable> ** value) = 0;
    virtual HRESULT __stdcall get_SupportedVideoProfiles(Windows::Foundation::Collections::IVectorView<Windows::Devices::Perception::PerceptionVideoProfile> ** value) = 0;
    virtual HRESULT __stdcall get_AvailableVideoProfiles(Windows::Foundation::Collections::IVectorView<Windows::Devices::Perception::PerceptionVideoProfile> ** value) = 0;
    virtual HRESULT __stdcall get_VideoProfile(Windows::Devices::Perception::IPerceptionVideoProfile ** value) = 0;
    virtual HRESULT __stdcall get_CameraIntrinsics(Windows::Media::Devices::Core::ICameraIntrinsics ** value) = 0;
    virtual HRESULT __stdcall abi_AcquireControlSession(Windows::Devices::Perception::IPerceptionControlSession ** result) = 0;
    virtual HRESULT __stdcall abi_CanControlIndependentlyFrom(hstring targetId, bool * result) = 0;
    virtual HRESULT __stdcall abi_IsCorrelatedWith(hstring targetId, bool * result) = 0;
    virtual HRESULT __stdcall abi_TryGetTransformTo(hstring targetId, Windows::Foundation::Numerics::float4x4 * result, bool * hasResult) = 0;
    virtual HRESULT __stdcall abi_TryGetDepthCorrelatedCameraIntrinsicsAsync(Windows::Devices::Perception::IPerceptionDepthFrameSource * target, Windows::Foundation::IAsyncOperation<Windows::Devices::Perception::PerceptionDepthCorrelatedCameraIntrinsics> ** result) = 0;
    virtual HRESULT __stdcall abi_TryGetDepthCorrelatedCoordinateMapperAsync(hstring targetId, Windows::Devices::Perception::IPerceptionDepthFrameSource * depthFrameSourceToMapWith, Windows::Foundation::IAsyncOperation<Windows::Devices::Perception::PerceptionDepthCorrelatedCoordinateMapper> ** result) = 0;
    virtual HRESULT __stdcall abi_TrySetVideoProfileAsync(Windows::Devices::Perception::IPerceptionControlSession * controlSession, Windows::Devices::Perception::IPerceptionVideoProfile * profile, Windows::Foundation::IAsyncOperation<Windows::Devices::Perception::PerceptionFrameSourcePropertyChangeResult> ** result) = 0;
    virtual HRESULT __stdcall abi_OpenReader(Windows::Devices::Perception::IPerceptionInfraredFrameReader ** result) = 0;
};

struct __declspec(uuid("dcd4d798-4b0b-4300-8d85-410817faa032")) __declspec(novtable) IPerceptionInfraredFrameSource2 : Windows::IInspectable
{
    virtual HRESULT __stdcall get_DeviceId(hstring * value) = 0;
};

struct __declspec(uuid("6d334120-95ce-4660-907a-d98035aa2b7c")) __declspec(novtable) IPerceptionInfraredFrameSourceAddedEventArgs : Windows::IInspectable
{
    virtual HRESULT __stdcall get_FrameSource(Windows::Devices::Perception::IPerceptionInfraredFrameSource ** value) = 0;
};

struct __declspec(uuid("ea1a8071-7a70-4a61-af94-07303853f695")) __declspec(novtable) IPerceptionInfraredFrameSourceRemovedEventArgs : Windows::IInspectable
{
    virtual HRESULT __stdcall get_FrameSource(Windows::Devices::Perception::IPerceptionInfraredFrameSource ** value) = 0;
};

struct __declspec(uuid("5df3cca2-01f8-4a87-b859-d5e5b7e1de47")) __declspec(novtable) IPerceptionInfraredFrameSourceStatics : Windows::IInspectable
{
    virtual HRESULT __stdcall abi_CreateWatcher(Windows::Devices::Perception::IPerceptionInfraredFrameSourceWatcher ** watcher) = 0;
    virtual HRESULT __stdcall abi_FindAllAsync(Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::Devices::Perception::PerceptionInfraredFrameSource>> ** result) = 0;
    virtual HRESULT __stdcall abi_FromIdAsync(hstring id, Windows::Foundation::IAsyncOperation<Windows::Devices::Perception::PerceptionInfraredFrameSource> ** result) = 0;
    virtual HRESULT __stdcall abi_RequestAccessAsync(Windows::Foundation::IAsyncOperation<winrt::Windows::Devices::Perception::PerceptionFrameSourceAccessStatus> ** result) = 0;
};

struct __declspec(uuid("383cff99-d70c-444d-a8b0-720c2e66fe3b")) __declspec(novtable) IPerceptionInfraredFrameSourceWatcher : Windows::IInspectable
{
    virtual HRESULT __stdcall add_SourceAdded(Windows::Foundation::TypedEventHandler<Windows::Devices::Perception::PerceptionInfraredFrameSourceWatcher, Windows::Devices::Perception::PerceptionInfraredFrameSourceAddedEventArgs> * handler, event_token * token) = 0;
    virtual HRESULT __stdcall remove_SourceAdded(event_token token) = 0;
    virtual HRESULT __stdcall add_SourceRemoved(Windows::Foundation::TypedEventHandler<Windows::Devices::Perception::PerceptionInfraredFrameSourceWatcher, Windows::Devices::Perception::PerceptionInfraredFrameSourceRemovedEventArgs> * handler, event_token * token) = 0;
    virtual HRESULT __stdcall remove_SourceRemoved(event_token token) = 0;
    virtual HRESULT __stdcall add_Stopped(Windows::Foundation::TypedEventHandler<Windows::Devices::Perception::PerceptionInfraredFrameSourceWatcher, Windows::IInspectable> * handler, event_token * token) = 0;
    virtual HRESULT __stdcall remove_Stopped(event_token token) = 0;
    virtual HRESULT __stdcall add_EnumerationCompleted(Windows::Foundation::TypedEventHandler<Windows::Devices::Perception::PerceptionInfraredFrameSourceWatcher, Windows::IInspectable> * handler, event_token * token) = 0;
    virtual HRESULT __stdcall remove_EnumerationCompleted(event_token token) = 0;
    virtual HRESULT __stdcall get_Status(winrt::Windows::Devices::Enumeration::DeviceWatcherStatus * value) = 0;
    virtual HRESULT __stdcall abi_Start() = 0;
    virtual HRESULT __stdcall abi_Stop() = 0;
};

struct __declspec(uuid("75763ea3-011a-470e-8225-6f05ade25648")) __declspec(novtable) IPerceptionVideoProfile : Windows::IInspectable
{
    virtual HRESULT __stdcall get_BitmapPixelFormat(winrt::Windows::Graphics::Imaging::BitmapPixelFormat * value) = 0;
    virtual HRESULT __stdcall get_BitmapAlphaMode(winrt::Windows::Graphics::Imaging::BitmapAlphaMode * value) = 0;
    virtual HRESULT __stdcall get_Width(int32_t * value) = 0;
    virtual HRESULT __stdcall get_Height(int32_t * value) = 0;
    virtual HRESULT __stdcall get_FrameDuration(Windows::Foundation::TimeSpan * value) = 0;
    virtual HRESULT __stdcall abi_IsEqual(Windows::Devices::Perception::IPerceptionVideoProfile * other, bool * result) = 0;
};

}

namespace ABI {

template <> struct traits<Windows::Devices::Perception::PerceptionColorFrame> { using default_interface = Windows::Devices::Perception::IPerceptionColorFrame; };
template <> struct traits<Windows::Devices::Perception::PerceptionColorFrameArrivedEventArgs> { using default_interface = Windows::Devices::Perception::IPerceptionColorFrameArrivedEventArgs; };
template <> struct traits<Windows::Devices::Perception::PerceptionColorFrameReader> { using default_interface = Windows::Devices::Perception::IPerceptionColorFrameReader; };
template <> struct traits<Windows::Devices::Perception::PerceptionColorFrameSource> { using default_interface = Windows::Devices::Perception::IPerceptionColorFrameSource; };
template <> struct traits<Windows::Devices::Perception::PerceptionColorFrameSourceAddedEventArgs> { using default_interface = Windows::Devices::Perception::IPerceptionColorFrameSourceAddedEventArgs; };
template <> struct traits<Windows::Devices::Perception::PerceptionColorFrameSourceRemovedEventArgs> { using default_interface = Windows::Devices::Perception::IPerceptionColorFrameSourceRemovedEventArgs; };
template <> struct traits<Windows::Devices::Perception::PerceptionColorFrameSourceWatcher> { using default_interface = Windows::Devices::Perception::IPerceptionColorFrameSourceWatcher; };
template <> struct traits<Windows::Devices::Perception::PerceptionControlSession> { using default_interface = Windows::Devices::Perception::IPerceptionControlSession; };
template <> struct traits<Windows::Devices::Perception::PerceptionDepthCorrelatedCameraIntrinsics> { using default_interface = Windows::Devices::Perception::IPerceptionDepthCorrelatedCameraIntrinsics; };
template <> struct traits<Windows::Devices::Perception::PerceptionDepthCorrelatedCoordinateMapper> { using default_interface = Windows::Devices::Perception::IPerceptionDepthCorrelatedCoordinateMapper; };
template <> struct traits<Windows::Devices::Perception::PerceptionDepthFrame> { using default_interface = Windows::Devices::Perception::IPerceptionDepthFrame; };
template <> struct traits<Windows::Devices::Perception::PerceptionDepthFrameArrivedEventArgs> { using default_interface = Windows::Devices::Perception::IPerceptionDepthFrameArrivedEventArgs; };
template <> struct traits<Windows::Devices::Perception::PerceptionDepthFrameReader> { using default_interface = Windows::Devices::Perception::IPerceptionDepthFrameReader; };
template <> struct traits<Windows::Devices::Perception::PerceptionDepthFrameSource> { using default_interface = Windows::Devices::Perception::IPerceptionDepthFrameSource; };
template <> struct traits<Windows::Devices::Perception::PerceptionDepthFrameSourceAddedEventArgs> { using default_interface = Windows::Devices::Perception::IPerceptionDepthFrameSourceAddedEventArgs; };
template <> struct traits<Windows::Devices::Perception::PerceptionDepthFrameSourceRemovedEventArgs> { using default_interface = Windows::Devices::Perception::IPerceptionDepthFrameSourceRemovedEventArgs; };
template <> struct traits<Windows::Devices::Perception::PerceptionDepthFrameSourceWatcher> { using default_interface = Windows::Devices::Perception::IPerceptionDepthFrameSourceWatcher; };
template <> struct traits<Windows::Devices::Perception::PerceptionFrameSourcePropertiesChangedEventArgs> { using default_interface = Windows::Devices::Perception::IPerceptionFrameSourcePropertiesChangedEventArgs; };
template <> struct traits<Windows::Devices::Perception::PerceptionFrameSourcePropertyChangeResult> { using default_interface = Windows::Devices::Perception::IPerceptionFrameSourcePropertyChangeResult; };
template <> struct traits<Windows::Devices::Perception::PerceptionInfraredFrame> { using default_interface = Windows::Devices::Perception::IPerceptionInfraredFrame; };
template <> struct traits<Windows::Devices::Perception::PerceptionInfraredFrameArrivedEventArgs> { using default_interface = Windows::Devices::Perception::IPerceptionInfraredFrameArrivedEventArgs; };
template <> struct traits<Windows::Devices::Perception::PerceptionInfraredFrameReader> { using default_interface = Windows::Devices::Perception::IPerceptionInfraredFrameReader; };
template <> struct traits<Windows::Devices::Perception::PerceptionInfraredFrameSource> { using default_interface = Windows::Devices::Perception::IPerceptionInfraredFrameSource; };
template <> struct traits<Windows::Devices::Perception::PerceptionInfraredFrameSourceAddedEventArgs> { using default_interface = Windows::Devices::Perception::IPerceptionInfraredFrameSourceAddedEventArgs; };
template <> struct traits<Windows::Devices::Perception::PerceptionInfraredFrameSourceRemovedEventArgs> { using default_interface = Windows::Devices::Perception::IPerceptionInfraredFrameSourceRemovedEventArgs; };
template <> struct traits<Windows::Devices::Perception::PerceptionInfraredFrameSourceWatcher> { using default_interface = Windows::Devices::Perception::IPerceptionInfraredFrameSourceWatcher; };
template <> struct traits<Windows::Devices::Perception::PerceptionVideoProfile> { using default_interface = Windows::Devices::Perception::IPerceptionVideoProfile; };

}

namespace Windows::Devices::Perception {

template <typename T> class impl_IKnownCameraIntrinsicsPropertiesStatics;
template <typename T> class impl_IKnownPerceptionColorFrameSourcePropertiesStatics;
template <typename T> class impl_IKnownPerceptionDepthFrameSourcePropertiesStatics;
template <typename T> class impl_IKnownPerceptionFrameSourcePropertiesStatics;
template <typename T> class impl_IKnownPerceptionFrameSourcePropertiesStatics2;
template <typename T> class impl_IKnownPerceptionInfraredFrameSourcePropertiesStatics;
template <typename T> class impl_IKnownPerceptionVideoFrameSourcePropertiesStatics;
template <typename T> class impl_IKnownPerceptionVideoProfilePropertiesStatics;
template <typename T> class impl_IPerceptionColorFrame;
template <typename T> class impl_IPerceptionColorFrameArrivedEventArgs;
template <typename T> class impl_IPerceptionColorFrameReader;
template <typename T> class impl_IPerceptionColorFrameSource;
template <typename T> class impl_IPerceptionColorFrameSource2;
template <typename T> class impl_IPerceptionColorFrameSourceAddedEventArgs;
template <typename T> class impl_IPerceptionColorFrameSourceRemovedEventArgs;
template <typename T> class impl_IPerceptionColorFrameSourceStatics;
template <typename T> class impl_IPerceptionColorFrameSourceWatcher;
template <typename T> class impl_IPerceptionControlSession;
template <typename T> class impl_IPerceptionDepthCorrelatedCameraIntrinsics;
template <typename T> class impl_IPerceptionDepthCorrelatedCoordinateMapper;
template <typename T> class impl_IPerceptionDepthFrame;
template <typename T> class impl_IPerceptionDepthFrameArrivedEventArgs;
template <typename T> class impl_IPerceptionDepthFrameReader;
template <typename T> class impl_IPerceptionDepthFrameSource;
template <typename T> class impl_IPerceptionDepthFrameSource2;
template <typename T> class impl_IPerceptionDepthFrameSourceAddedEventArgs;
template <typename T> class impl_IPerceptionDepthFrameSourceRemovedEventArgs;
template <typename T> class impl_IPerceptionDepthFrameSourceStatics;
template <typename T> class impl_IPerceptionDepthFrameSourceWatcher;
template <typename T> class impl_IPerceptionFrameSourcePropertiesChangedEventArgs;
template <typename T> class impl_IPerceptionFrameSourcePropertyChangeResult;
template <typename T> class impl_IPerceptionInfraredFrame;
template <typename T> class impl_IPerceptionInfraredFrameArrivedEventArgs;
template <typename T> class impl_IPerceptionInfraredFrameReader;
template <typename T> class impl_IPerceptionInfraredFrameSource;
template <typename T> class impl_IPerceptionInfraredFrameSource2;
template <typename T> class impl_IPerceptionInfraredFrameSourceAddedEventArgs;
template <typename T> class impl_IPerceptionInfraredFrameSourceRemovedEventArgs;
template <typename T> class impl_IPerceptionInfraredFrameSourceStatics;
template <typename T> class impl_IPerceptionInfraredFrameSourceWatcher;
template <typename T> class impl_IPerceptionVideoProfile;

}

namespace impl {

template <> struct traits<Windows::Devices::Perception::IKnownCameraIntrinsicsPropertiesStatics>
{
    using abi = ABI::Windows::Devices::Perception::IKnownCameraIntrinsicsPropertiesStatics;
    template <typename D> using consume = Windows::Devices::Perception::impl_IKnownCameraIntrinsicsPropertiesStatics<D>;
};

template <> struct traits<Windows::Devices::Perception::IKnownPerceptionColorFrameSourcePropertiesStatics>
{
    using abi = ABI::Windows::Devices::Perception::IKnownPerceptionColorFrameSourcePropertiesStatics;
    template <typename D> using consume = Windows::Devices::Perception::impl_IKnownPerceptionColorFrameSourcePropertiesStatics<D>;
};

template <> struct traits<Windows::Devices::Perception::IKnownPerceptionDepthFrameSourcePropertiesStatics>
{
    using abi = ABI::Windows::Devices::Perception::IKnownPerceptionDepthFrameSourcePropertiesStatics;
    template <typename D> using consume = Windows::Devices::Perception::impl_IKnownPerceptionDepthFrameSourcePropertiesStatics<D>;
};

template <> struct traits<Windows::Devices::Perception::IKnownPerceptionFrameSourcePropertiesStatics>
{
    using abi = ABI::Windows::Devices::Perception::IKnownPerceptionFrameSourcePropertiesStatics;
    template <typename D> using consume = Windows::Devices::Perception::impl_IKnownPerceptionFrameSourcePropertiesStatics<D>;
};

template <> struct traits<Windows::Devices::Perception::IKnownPerceptionFrameSourcePropertiesStatics2>
{
    using abi = ABI::Windows::Devices::Perception::IKnownPerceptionFrameSourcePropertiesStatics2;
    template <typename D> using consume = Windows::Devices::Perception::impl_IKnownPerceptionFrameSourcePropertiesStatics2<D>;
};

template <> struct traits<Windows::Devices::Perception::IKnownPerceptionInfraredFrameSourcePropertiesStatics>
{
    using abi = ABI::Windows::Devices::Perception::IKnownPerceptionInfraredFrameSourcePropertiesStatics;
    template <typename D> using consume = Windows::Devices::Perception::impl_IKnownPerceptionInfraredFrameSourcePropertiesStatics<D>;
};

template <> struct traits<Windows::Devices::Perception::IKnownPerceptionVideoFrameSourcePropertiesStatics>
{
    using abi = ABI::Windows::Devices::Perception::IKnownPerceptionVideoFrameSourcePropertiesStatics;
    template <typename D> using consume = Windows::Devices::Perception::impl_IKnownPerceptionVideoFrameSourcePropertiesStatics<D>;
};

template <> struct traits<Windows::Devices::Perception::IKnownPerceptionVideoProfilePropertiesStatics>
{
    using abi = ABI::Windows::Devices::Perception::IKnownPerceptionVideoProfilePropertiesStatics;
    template <typename D> using consume = Windows::Devices::Perception::impl_IKnownPerceptionVideoProfilePropertiesStatics<D>;
};

template <> struct traits<Windows::Devices::Perception::IPerceptionColorFrame>
{
    using abi = ABI::Windows::Devices::Perception::IPerceptionColorFrame;
    template <typename D> using consume = Windows::Devices::Perception::impl_IPerceptionColorFrame<D>;
};

template <> struct traits<Windows::Devices::Perception::IPerceptionColorFrameArrivedEventArgs>
{
    using abi = ABI::Windows::Devices::Perception::IPerceptionColorFrameArrivedEventArgs;
    template <typename D> using consume = Windows::Devices::Perception::impl_IPerceptionColorFrameArrivedEventArgs<D>;
};

template <> struct traits<Windows::Devices::Perception::IPerceptionColorFrameReader>
{
    using abi = ABI::Windows::Devices::Perception::IPerceptionColorFrameReader;
    template <typename D> using consume = Windows::Devices::Perception::impl_IPerceptionColorFrameReader<D>;
};

template <> struct traits<Windows::Devices::Perception::IPerceptionColorFrameSource>
{
    using abi = ABI::Windows::Devices::Perception::IPerceptionColorFrameSource;
    template <typename D> using consume = Windows::Devices::Perception::impl_IPerceptionColorFrameSource<D>;
};

template <> struct traits<Windows::Devices::Perception::IPerceptionColorFrameSource2>
{
    using abi = ABI::Windows::Devices::Perception::IPerceptionColorFrameSource2;
    template <typename D> using consume = Windows::Devices::Perception::impl_IPerceptionColorFrameSource2<D>;
};

template <> struct traits<Windows::Devices::Perception::IPerceptionColorFrameSourceAddedEventArgs>
{
    using abi = ABI::Windows::Devices::Perception::IPerceptionColorFrameSourceAddedEventArgs;
    template <typename D> using consume = Windows::Devices::Perception::impl_IPerceptionColorFrameSourceAddedEventArgs<D>;
};

template <> struct traits<Windows::Devices::Perception::IPerceptionColorFrameSourceRemovedEventArgs>
{
    using abi = ABI::Windows::Devices::Perception::IPerceptionColorFrameSourceRemovedEventArgs;
    template <typename D> using consume = Windows::Devices::Perception::impl_IPerceptionColorFrameSourceRemovedEventArgs<D>;
};

template <> struct traits<Windows::Devices::Perception::IPerceptionColorFrameSourceStatics>
{
    using abi = ABI::Windows::Devices::Perception::IPerceptionColorFrameSourceStatics;
    template <typename D> using consume = Windows::Devices::Perception::impl_IPerceptionColorFrameSourceStatics<D>;
};

template <> struct traits<Windows::Devices::Perception::IPerceptionColorFrameSourceWatcher>
{
    using abi = ABI::Windows::Devices::Perception::IPerceptionColorFrameSourceWatcher;
    template <typename D> using consume = Windows::Devices::Perception::impl_IPerceptionColorFrameSourceWatcher<D>;
};

template <> struct traits<Windows::Devices::Perception::IPerceptionControlSession>
{
    using abi = ABI::Windows::Devices::Perception::IPerceptionControlSession;
    template <typename D> using consume = Windows::Devices::Perception::impl_IPerceptionControlSession<D>;
};

template <> struct traits<Windows::Devices::Perception::IPerceptionDepthCorrelatedCameraIntrinsics>
{
    using abi = ABI::Windows::Devices::Perception::IPerceptionDepthCorrelatedCameraIntrinsics;
    template <typename D> using consume = Windows::Devices::Perception::impl_IPerceptionDepthCorrelatedCameraIntrinsics<D>;
};

template <> struct traits<Windows::Devices::Perception::IPerceptionDepthCorrelatedCoordinateMapper>
{
    using abi = ABI::Windows::Devices::Perception::IPerceptionDepthCorrelatedCoordinateMapper;
    template <typename D> using consume = Windows::Devices::Perception::impl_IPerceptionDepthCorrelatedCoordinateMapper<D>;
};

template <> struct traits<Windows::Devices::Perception::IPerceptionDepthFrame>
{
    using abi = ABI::Windows::Devices::Perception::IPerceptionDepthFrame;
    template <typename D> using consume = Windows::Devices::Perception::impl_IPerceptionDepthFrame<D>;
};

template <> struct traits<Windows::Devices::Perception::IPerceptionDepthFrameArrivedEventArgs>
{
    using abi = ABI::Windows::Devices::Perception::IPerceptionDepthFrameArrivedEventArgs;
    template <typename D> using consume = Windows::Devices::Perception::impl_IPerceptionDepthFrameArrivedEventArgs<D>;
};

template <> struct traits<Windows::Devices::Perception::IPerceptionDepthFrameReader>
{
    using abi = ABI::Windows::Devices::Perception::IPerceptionDepthFrameReader;
    template <typename D> using consume = Windows::Devices::Perception::impl_IPerceptionDepthFrameReader<D>;
};

template <> struct traits<Windows::Devices::Perception::IPerceptionDepthFrameSource>
{
    using abi = ABI::Windows::Devices::Perception::IPerceptionDepthFrameSource;
    template <typename D> using consume = Windows::Devices::Perception::impl_IPerceptionDepthFrameSource<D>;
};

template <> struct traits<Windows::Devices::Perception::IPerceptionDepthFrameSource2>
{
    using abi = ABI::Windows::Devices::Perception::IPerceptionDepthFrameSource2;
    template <typename D> using consume = Windows::Devices::Perception::impl_IPerceptionDepthFrameSource2<D>;
};

template <> struct traits<Windows::Devices::Perception::IPerceptionDepthFrameSourceAddedEventArgs>
{
    using abi = ABI::Windows::Devices::Perception::IPerceptionDepthFrameSourceAddedEventArgs;
    template <typename D> using consume = Windows::Devices::Perception::impl_IPerceptionDepthFrameSourceAddedEventArgs<D>;
};

template <> struct traits<Windows::Devices::Perception::IPerceptionDepthFrameSourceRemovedEventArgs>
{
    using abi = ABI::Windows::Devices::Perception::IPerceptionDepthFrameSourceRemovedEventArgs;
    template <typename D> using consume = Windows::Devices::Perception::impl_IPerceptionDepthFrameSourceRemovedEventArgs<D>;
};

template <> struct traits<Windows::Devices::Perception::IPerceptionDepthFrameSourceStatics>
{
    using abi = ABI::Windows::Devices::Perception::IPerceptionDepthFrameSourceStatics;
    template <typename D> using consume = Windows::Devices::Perception::impl_IPerceptionDepthFrameSourceStatics<D>;
};

template <> struct traits<Windows::Devices::Perception::IPerceptionDepthFrameSourceWatcher>
{
    using abi = ABI::Windows::Devices::Perception::IPerceptionDepthFrameSourceWatcher;
    template <typename D> using consume = Windows::Devices::Perception::impl_IPerceptionDepthFrameSourceWatcher<D>;
};

template <> struct traits<Windows::Devices::Perception::IPerceptionFrameSourcePropertiesChangedEventArgs>
{
    using abi = ABI::Windows::Devices::Perception::IPerceptionFrameSourcePropertiesChangedEventArgs;
    template <typename D> using consume = Windows::Devices::Perception::impl_IPerceptionFrameSourcePropertiesChangedEventArgs<D>;
};

template <> struct traits<Windows::Devices::Perception::IPerceptionFrameSourcePropertyChangeResult>
{
    using abi = ABI::Windows::Devices::Perception::IPerceptionFrameSourcePropertyChangeResult;
    template <typename D> using consume = Windows::Devices::Perception::impl_IPerceptionFrameSourcePropertyChangeResult<D>;
};

template <> struct traits<Windows::Devices::Perception::IPerceptionInfraredFrame>
{
    using abi = ABI::Windows::Devices::Perception::IPerceptionInfraredFrame;
    template <typename D> using consume = Windows::Devices::Perception::impl_IPerceptionInfraredFrame<D>;
};

template <> struct traits<Windows::Devices::Perception::IPerceptionInfraredFrameArrivedEventArgs>
{
    using abi = ABI::Windows::Devices::Perception::IPerceptionInfraredFrameArrivedEventArgs;
    template <typename D> using consume = Windows::Devices::Perception::impl_IPerceptionInfraredFrameArrivedEventArgs<D>;
};

template <> struct traits<Windows::Devices::Perception::IPerceptionInfraredFrameReader>
{
    using abi = ABI::Windows::Devices::Perception::IPerceptionInfraredFrameReader;
    template <typename D> using consume = Windows::Devices::Perception::impl_IPerceptionInfraredFrameReader<D>;
};

template <> struct traits<Windows::Devices::Perception::IPerceptionInfraredFrameSource>
{
    using abi = ABI::Windows::Devices::Perception::IPerceptionInfraredFrameSource;
    template <typename D> using consume = Windows::Devices::Perception::impl_IPerceptionInfraredFrameSource<D>;
};

template <> struct traits<Windows::Devices::Perception::IPerceptionInfraredFrameSource2>
{
    using abi = ABI::Windows::Devices::Perception::IPerceptionInfraredFrameSource2;
    template <typename D> using consume = Windows::Devices::Perception::impl_IPerceptionInfraredFrameSource2<D>;
};

template <> struct traits<Windows::Devices::Perception::IPerceptionInfraredFrameSourceAddedEventArgs>
{
    using abi = ABI::Windows::Devices::Perception::IPerceptionInfraredFrameSourceAddedEventArgs;
    template <typename D> using consume = Windows::Devices::Perception::impl_IPerceptionInfraredFrameSourceAddedEventArgs<D>;
};

template <> struct traits<Windows::Devices::Perception::IPerceptionInfraredFrameSourceRemovedEventArgs>
{
    using abi = ABI::Windows::Devices::Perception::IPerceptionInfraredFrameSourceRemovedEventArgs;
    template <typename D> using consume = Windows::Devices::Perception::impl_IPerceptionInfraredFrameSourceRemovedEventArgs<D>;
};

template <> struct traits<Windows::Devices::Perception::IPerceptionInfraredFrameSourceStatics>
{
    using abi = ABI::Windows::Devices::Perception::IPerceptionInfraredFrameSourceStatics;
    template <typename D> using consume = Windows::Devices::Perception::impl_IPerceptionInfraredFrameSourceStatics<D>;
};

template <> struct traits<Windows::Devices::Perception::IPerceptionInfraredFrameSourceWatcher>
{
    using abi = ABI::Windows::Devices::Perception::IPerceptionInfraredFrameSourceWatcher;
    template <typename D> using consume = Windows::Devices::Perception::impl_IPerceptionInfraredFrameSourceWatcher<D>;
};

template <> struct traits<Windows::Devices::Perception::IPerceptionVideoProfile>
{
    using abi = ABI::Windows::Devices::Perception::IPerceptionVideoProfile;
    template <typename D> using consume = Windows::Devices::Perception::impl_IPerceptionVideoProfile<D>;
};

template <> struct traits<Windows::Devices::Perception::KnownCameraIntrinsicsProperties>
{
    static constexpr const wchar_t * name() noexcept { return L"Windows.Devices.Perception.KnownCameraIntrinsicsProperties"; }
};

template <> struct traits<Windows::Devices::Perception::KnownPerceptionColorFrameSourceProperties>
{
    static constexpr const wchar_t * name() noexcept { return L"Windows.Devices.Perception.KnownPerceptionColorFrameSourceProperties"; }
};

template <> struct traits<Windows::Devices::Perception::KnownPerceptionDepthFrameSourceProperties>
{
    static constexpr const wchar_t * name() noexcept { return L"Windows.Devices.Perception.KnownPerceptionDepthFrameSourceProperties"; }
};

template <> struct traits<Windows::Devices::Perception::KnownPerceptionFrameSourceProperties>
{
    static constexpr const wchar_t * name() noexcept { return L"Windows.Devices.Perception.KnownPerceptionFrameSourceProperties"; }
};

template <> struct traits<Windows::Devices::Perception::KnownPerceptionInfraredFrameSourceProperties>
{
    static constexpr const wchar_t * name() noexcept { return L"Windows.Devices.Perception.KnownPerceptionInfraredFrameSourceProperties"; }
};

template <> struct traits<Windows::Devices::Perception::KnownPerceptionVideoFrameSourceProperties>
{
    static constexpr const wchar_t * name() noexcept { return L"Windows.Devices.Perception.KnownPerceptionVideoFrameSourceProperties"; }
};

template <> struct traits<Windows::Devices::Perception::KnownPerceptionVideoProfileProperties>
{
    static constexpr const wchar_t * name() noexcept { return L"Windows.Devices.Perception.KnownPerceptionVideoProfileProperties"; }
};

template <> struct traits<Windows::Devices::Perception::PerceptionColorFrame>
{
    using abi = ABI::Windows::Devices::Perception::PerceptionColorFrame;
    using default_interface = Windows::Devices::Perception::IPerceptionColorFrame;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Devices.Perception.PerceptionColorFrame"; }
};

template <> struct traits<Windows::Devices::Perception::PerceptionColorFrameArrivedEventArgs>
{
    using abi = ABI::Windows::Devices::Perception::PerceptionColorFrameArrivedEventArgs;
    using default_interface = Windows::Devices::Perception::IPerceptionColorFrameArrivedEventArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Devices.Perception.PerceptionColorFrameArrivedEventArgs"; }
};

template <> struct traits<Windows::Devices::Perception::PerceptionColorFrameReader>
{
    using abi = ABI::Windows::Devices::Perception::PerceptionColorFrameReader;
    using default_interface = Windows::Devices::Perception::IPerceptionColorFrameReader;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Devices.Perception.PerceptionColorFrameReader"; }
};

template <> struct traits<Windows::Devices::Perception::PerceptionColorFrameSource>
{
    using abi = ABI::Windows::Devices::Perception::PerceptionColorFrameSource;
    using default_interface = Windows::Devices::Perception::IPerceptionColorFrameSource;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Devices.Perception.PerceptionColorFrameSource"; }
};

template <> struct traits<Windows::Devices::Perception::PerceptionColorFrameSourceAddedEventArgs>
{
    using abi = ABI::Windows::Devices::Perception::PerceptionColorFrameSourceAddedEventArgs;
    using default_interface = Windows::Devices::Perception::IPerceptionColorFrameSourceAddedEventArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Devices.Perception.PerceptionColorFrameSourceAddedEventArgs"; }
};

template <> struct traits<Windows::Devices::Perception::PerceptionColorFrameSourceRemovedEventArgs>
{
    using abi = ABI::Windows::Devices::Perception::PerceptionColorFrameSourceRemovedEventArgs;
    using default_interface = Windows::Devices::Perception::IPerceptionColorFrameSourceRemovedEventArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Devices.Perception.PerceptionColorFrameSourceRemovedEventArgs"; }
};

template <> struct traits<Windows::Devices::Perception::PerceptionColorFrameSourceWatcher>
{
    using abi = ABI::Windows::Devices::Perception::PerceptionColorFrameSourceWatcher;
    using default_interface = Windows::Devices::Perception::IPerceptionColorFrameSourceWatcher;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Devices.Perception.PerceptionColorFrameSourceWatcher"; }
};

template <> struct traits<Windows::Devices::Perception::PerceptionControlSession>
{
    using abi = ABI::Windows::Devices::Perception::PerceptionControlSession;
    using default_interface = Windows::Devices::Perception::IPerceptionControlSession;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Devices.Perception.PerceptionControlSession"; }
};

template <> struct traits<Windows::Devices::Perception::PerceptionDepthCorrelatedCameraIntrinsics>
{
    using abi = ABI::Windows::Devices::Perception::PerceptionDepthCorrelatedCameraIntrinsics;
    using default_interface = Windows::Devices::Perception::IPerceptionDepthCorrelatedCameraIntrinsics;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Devices.Perception.PerceptionDepthCorrelatedCameraIntrinsics"; }
};

template <> struct traits<Windows::Devices::Perception::PerceptionDepthCorrelatedCoordinateMapper>
{
    using abi = ABI::Windows::Devices::Perception::PerceptionDepthCorrelatedCoordinateMapper;
    using default_interface = Windows::Devices::Perception::IPerceptionDepthCorrelatedCoordinateMapper;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Devices.Perception.PerceptionDepthCorrelatedCoordinateMapper"; }
};

template <> struct traits<Windows::Devices::Perception::PerceptionDepthFrame>
{
    using abi = ABI::Windows::Devices::Perception::PerceptionDepthFrame;
    using default_interface = Windows::Devices::Perception::IPerceptionDepthFrame;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Devices.Perception.PerceptionDepthFrame"; }
};

template <> struct traits<Windows::Devices::Perception::PerceptionDepthFrameArrivedEventArgs>
{
    using abi = ABI::Windows::Devices::Perception::PerceptionDepthFrameArrivedEventArgs;
    using default_interface = Windows::Devices::Perception::IPerceptionDepthFrameArrivedEventArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Devices.Perception.PerceptionDepthFrameArrivedEventArgs"; }
};

template <> struct traits<Windows::Devices::Perception::PerceptionDepthFrameReader>
{
    using abi = ABI::Windows::Devices::Perception::PerceptionDepthFrameReader;
    using default_interface = Windows::Devices::Perception::IPerceptionDepthFrameReader;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Devices.Perception.PerceptionDepthFrameReader"; }
};

template <> struct traits<Windows::Devices::Perception::PerceptionDepthFrameSource>
{
    using abi = ABI::Windows::Devices::Perception::PerceptionDepthFrameSource;
    using default_interface = Windows::Devices::Perception::IPerceptionDepthFrameSource;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Devices.Perception.PerceptionDepthFrameSource"; }
};

template <> struct traits<Windows::Devices::Perception::PerceptionDepthFrameSourceAddedEventArgs>
{
    using abi = ABI::Windows::Devices::Perception::PerceptionDepthFrameSourceAddedEventArgs;
    using default_interface = Windows::Devices::Perception::IPerceptionDepthFrameSourceAddedEventArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Devices.Perception.PerceptionDepthFrameSourceAddedEventArgs"; }
};

template <> struct traits<Windows::Devices::Perception::PerceptionDepthFrameSourceRemovedEventArgs>
{
    using abi = ABI::Windows::Devices::Perception::PerceptionDepthFrameSourceRemovedEventArgs;
    using default_interface = Windows::Devices::Perception::IPerceptionDepthFrameSourceRemovedEventArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Devices.Perception.PerceptionDepthFrameSourceRemovedEventArgs"; }
};

template <> struct traits<Windows::Devices::Perception::PerceptionDepthFrameSourceWatcher>
{
    using abi = ABI::Windows::Devices::Perception::PerceptionDepthFrameSourceWatcher;
    using default_interface = Windows::Devices::Perception::IPerceptionDepthFrameSourceWatcher;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Devices.Perception.PerceptionDepthFrameSourceWatcher"; }
};

template <> struct traits<Windows::Devices::Perception::PerceptionFrameSourcePropertiesChangedEventArgs>
{
    using abi = ABI::Windows::Devices::Perception::PerceptionFrameSourcePropertiesChangedEventArgs;
    using default_interface = Windows::Devices::Perception::IPerceptionFrameSourcePropertiesChangedEventArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Devices.Perception.PerceptionFrameSourcePropertiesChangedEventArgs"; }
};

template <> struct traits<Windows::Devices::Perception::PerceptionFrameSourcePropertyChangeResult>
{
    using abi = ABI::Windows::Devices::Perception::PerceptionFrameSourcePropertyChangeResult;
    using default_interface = Windows::Devices::Perception::IPerceptionFrameSourcePropertyChangeResult;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Devices.Perception.PerceptionFrameSourcePropertyChangeResult"; }
};

template <> struct traits<Windows::Devices::Perception::PerceptionInfraredFrame>
{
    using abi = ABI::Windows::Devices::Perception::PerceptionInfraredFrame;
    using default_interface = Windows::Devices::Perception::IPerceptionInfraredFrame;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Devices.Perception.PerceptionInfraredFrame"; }
};

template <> struct traits<Windows::Devices::Perception::PerceptionInfraredFrameArrivedEventArgs>
{
    using abi = ABI::Windows::Devices::Perception::PerceptionInfraredFrameArrivedEventArgs;
    using default_interface = Windows::Devices::Perception::IPerceptionInfraredFrameArrivedEventArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Devices.Perception.PerceptionInfraredFrameArrivedEventArgs"; }
};

template <> struct traits<Windows::Devices::Perception::PerceptionInfraredFrameReader>
{
    using abi = ABI::Windows::Devices::Perception::PerceptionInfraredFrameReader;
    using default_interface = Windows::Devices::Perception::IPerceptionInfraredFrameReader;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Devices.Perception.PerceptionInfraredFrameReader"; }
};

template <> struct traits<Windows::Devices::Perception::PerceptionInfraredFrameSource>
{
    using abi = ABI::Windows::Devices::Perception::PerceptionInfraredFrameSource;
    using default_interface = Windows::Devices::Perception::IPerceptionInfraredFrameSource;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Devices.Perception.PerceptionInfraredFrameSource"; }
};

template <> struct traits<Windows::Devices::Perception::PerceptionInfraredFrameSourceAddedEventArgs>
{
    using abi = ABI::Windows::Devices::Perception::PerceptionInfraredFrameSourceAddedEventArgs;
    using default_interface = Windows::Devices::Perception::IPerceptionInfraredFrameSourceAddedEventArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Devices.Perception.PerceptionInfraredFrameSourceAddedEventArgs"; }
};

template <> struct traits<Windows::Devices::Perception::PerceptionInfraredFrameSourceRemovedEventArgs>
{
    using abi = ABI::Windows::Devices::Perception::PerceptionInfraredFrameSourceRemovedEventArgs;
    using default_interface = Windows::Devices::Perception::IPerceptionInfraredFrameSourceRemovedEventArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Devices.Perception.PerceptionInfraredFrameSourceRemovedEventArgs"; }
};

template <> struct traits<Windows::Devices::Perception::PerceptionInfraredFrameSourceWatcher>
{
    using abi = ABI::Windows::Devices::Perception::PerceptionInfraredFrameSourceWatcher;
    using default_interface = Windows::Devices::Perception::IPerceptionInfraredFrameSourceWatcher;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Devices.Perception.PerceptionInfraredFrameSourceWatcher"; }
};

template <> struct traits<Windows::Devices::Perception::PerceptionVideoProfile>
{
    using abi = ABI::Windows::Devices::Perception::PerceptionVideoProfile;
    using default_interface = Windows::Devices::Perception::IPerceptionVideoProfile;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Devices.Perception.PerceptionVideoProfile"; }
};

}

}