// C++ for the Windows Runtime v1.29
// Copyright (c) 2016 Microsoft Corporation

#pragma once

#include "../base.h"
#include "Windows.Graphics.Imaging.0.h"
#include "Windows.Foundation.0.h"
#include "Windows.Graphics.DirectX.Direct3D11.0.h"
#include "Windows.Storage.Streams.0.h"
#include "Windows.Foundation.Collections.1.h"
#include "Windows.Foundation.1.h"

WINRT_EXPORT namespace winrt {

namespace ABI::Windows::Graphics::Imaging {

struct BitmapBounds
{
    uint32_t X;
    uint32_t Y;
    uint32_t Width;
    uint32_t Height;
};

struct BitmapSize
{
    uint32_t Width;
    uint32_t Height;
};

struct BitmapPlaneDescription
{
    int32_t StartIndex;
    int32_t Width;
    int32_t Height;
    int32_t Stride;
};

}

namespace Windows::Graphics::Imaging {

using BitmapBounds = ABI::Windows::Graphics::Imaging::BitmapBounds;
using BitmapSize = ABI::Windows::Graphics::Imaging::BitmapSize;
using BitmapPlaneDescription = ABI::Windows::Graphics::Imaging::BitmapPlaneDescription;

}

namespace ABI::Windows::Graphics::Imaging {

struct __declspec(uuid("a53e04c4-399c-438c-b28f-a63a6b83d1a1")) __declspec(novtable) IBitmapBuffer : Windows::IInspectable
{
    virtual HRESULT __stdcall abi_GetPlaneCount(int32_t * value) = 0;
    virtual HRESULT __stdcall abi_GetPlaneDescription(int32_t index, Windows::Graphics::Imaging::BitmapPlaneDescription * value) = 0;
};

struct __declspec(uuid("400caaf2-c4b0-4392-a3b0-6f6f9ba95cb4")) __declspec(novtable) IBitmapCodecInformation : Windows::IInspectable
{
    virtual HRESULT __stdcall get_CodecId(GUID * value) = 0;
    virtual HRESULT __stdcall get_FileExtensions(Windows::Foundation::Collections::IVectorView<hstring> ** value) = 0;
    virtual HRESULT __stdcall get_FriendlyName(hstring * value) = 0;
    virtual HRESULT __stdcall get_MimeTypes(Windows::Foundation::Collections::IVectorView<hstring> ** value) = 0;
};

struct __declspec(uuid("acef22ba-1d74-4c91-9dfc-9620745233e6")) __declspec(novtable) IBitmapDecoder : Windows::IInspectable
{
    virtual HRESULT __stdcall get_BitmapContainerProperties(Windows::Graphics::Imaging::IBitmapPropertiesView ** value) = 0;
    virtual HRESULT __stdcall get_DecoderInformation(Windows::Graphics::Imaging::IBitmapCodecInformation ** value) = 0;
    virtual HRESULT __stdcall get_FrameCount(uint32_t * value) = 0;
    virtual HRESULT __stdcall abi_GetPreviewAsync(Windows::Foundation::IAsyncOperation<Windows::Graphics::Imaging::ImageStream> ** asyncInfo) = 0;
    virtual HRESULT __stdcall abi_GetFrameAsync(uint32_t frameIndex, Windows::Foundation::IAsyncOperation<Windows::Graphics::Imaging::BitmapFrame> ** asyncInfo) = 0;
};

struct __declspec(uuid("438ccb26-bcef-4e95-bad6-23a822e58d01")) __declspec(novtable) IBitmapDecoderStatics : Windows::IInspectable
{
    virtual HRESULT __stdcall get_BmpDecoderId(GUID * value) = 0;
    virtual HRESULT __stdcall get_JpegDecoderId(GUID * value) = 0;
    virtual HRESULT __stdcall get_PngDecoderId(GUID * value) = 0;
    virtual HRESULT __stdcall get_TiffDecoderId(GUID * value) = 0;
    virtual HRESULT __stdcall get_GifDecoderId(GUID * value) = 0;
    virtual HRESULT __stdcall get_JpegXRDecoderId(GUID * value) = 0;
    virtual HRESULT __stdcall get_IcoDecoderId(GUID * value) = 0;
    virtual HRESULT __stdcall abi_GetDecoderInformationEnumerator(Windows::Foundation::Collections::IVectorView<Windows::Graphics::Imaging::BitmapCodecInformation> ** decoderInformationEnumerator) = 0;
    virtual HRESULT __stdcall abi_CreateAsync(Windows::Storage::Streams::IRandomAccessStream * stream, Windows::Foundation::IAsyncOperation<Windows::Graphics::Imaging::BitmapDecoder> ** asyncInfo) = 0;
    virtual HRESULT __stdcall abi_CreateWithIdAsync(GUID decoderId, Windows::Storage::Streams::IRandomAccessStream * stream, Windows::Foundation::IAsyncOperation<Windows::Graphics::Imaging::BitmapDecoder> ** asyncInfo) = 0;
};

struct __declspec(uuid("2bc468e3-e1f8-4b54-95e8-32919551ce62")) __declspec(novtable) IBitmapEncoder : Windows::IInspectable
{
    virtual HRESULT __stdcall get_EncoderInformation(Windows::Graphics::Imaging::IBitmapCodecInformation ** value) = 0;
    virtual HRESULT __stdcall get_BitmapProperties(Windows::Graphics::Imaging::IBitmapProperties ** value) = 0;
    virtual HRESULT __stdcall get_BitmapContainerProperties(Windows::Graphics::Imaging::IBitmapProperties ** value) = 0;
    virtual HRESULT __stdcall get_IsThumbnailGenerated(bool * value) = 0;
    virtual HRESULT __stdcall put_IsThumbnailGenerated(bool value) = 0;
    virtual HRESULT __stdcall get_GeneratedThumbnailWidth(uint32_t * value) = 0;
    virtual HRESULT __stdcall put_GeneratedThumbnailWidth(uint32_t value) = 0;
    virtual HRESULT __stdcall get_GeneratedThumbnailHeight(uint32_t * value) = 0;
    virtual HRESULT __stdcall put_GeneratedThumbnailHeight(uint32_t value) = 0;
    virtual HRESULT __stdcall get_BitmapTransform(Windows::Graphics::Imaging::IBitmapTransform ** value) = 0;
    virtual HRESULT __stdcall abi_SetPixelData(winrt::Windows::Graphics::Imaging::BitmapPixelFormat pixelFormat, winrt::Windows::Graphics::Imaging::BitmapAlphaMode alphaMode, uint32_t width, uint32_t height, double dpiX, double dpiY, uint32_t __pixelsSize, uint8_t * pixels) = 0;
    virtual HRESULT __stdcall abi_GoToNextFrameAsync(Windows::Foundation::IAsyncAction ** asyncInfo) = 0;
    virtual HRESULT __stdcall abi_GoToNextFrameWithEncodingOptionsAsync(Windows::Foundation::Collections::IIterable<Windows::Foundation::Collections::IKeyValuePair<hstring, Windows::Graphics::Imaging::BitmapTypedValue>> * encodingOptions, Windows::Foundation::IAsyncAction ** asyncInfo) = 0;
    virtual HRESULT __stdcall abi_FlushAsync(Windows::Foundation::IAsyncAction ** asyncInfo) = 0;
};

struct __declspec(uuid("a74356a7-a4e4-4eb9-8e40-564de7e1ccb2")) __declspec(novtable) IBitmapEncoderStatics : Windows::IInspectable
{
    virtual HRESULT __stdcall get_BmpEncoderId(GUID * value) = 0;
    virtual HRESULT __stdcall get_JpegEncoderId(GUID * value) = 0;
    virtual HRESULT __stdcall get_PngEncoderId(GUID * value) = 0;
    virtual HRESULT __stdcall get_TiffEncoderId(GUID * value) = 0;
    virtual HRESULT __stdcall get_GifEncoderId(GUID * value) = 0;
    virtual HRESULT __stdcall get_JpegXREncoderId(GUID * value) = 0;
    virtual HRESULT __stdcall abi_GetEncoderInformationEnumerator(Windows::Foundation::Collections::IVectorView<Windows::Graphics::Imaging::BitmapCodecInformation> ** encoderInformationEnumerator) = 0;
    virtual HRESULT __stdcall abi_CreateAsync(GUID encoderId, Windows::Storage::Streams::IRandomAccessStream * stream, Windows::Foundation::IAsyncOperation<Windows::Graphics::Imaging::BitmapEncoder> ** asyncInfo) = 0;
    virtual HRESULT __stdcall abi_CreateWithEncodingOptionsAsync(GUID encoderId, Windows::Storage::Streams::IRandomAccessStream * stream, Windows::Foundation::Collections::IIterable<Windows::Foundation::Collections::IKeyValuePair<hstring, Windows::Graphics::Imaging::BitmapTypedValue>> * encodingOptions, Windows::Foundation::IAsyncOperation<Windows::Graphics::Imaging::BitmapEncoder> ** asyncInfo) = 0;
    virtual HRESULT __stdcall abi_CreateForTranscodingAsync(Windows::Storage::Streams::IRandomAccessStream * stream, Windows::Graphics::Imaging::IBitmapDecoder * bitmapDecoder, Windows::Foundation::IAsyncOperation<Windows::Graphics::Imaging::BitmapEncoder> ** asyncInfo) = 0;
    virtual HRESULT __stdcall abi_CreateForInPlacePropertyEncodingAsync(Windows::Graphics::Imaging::IBitmapDecoder * bitmapDecoder, Windows::Foundation::IAsyncOperation<Windows::Graphics::Imaging::BitmapEncoder> ** asyncInfo) = 0;
};

struct __declspec(uuid("686cd241-4330-4c77-ace4-0334968b1768")) __declspec(novtable) IBitmapEncoderWithSoftwareBitmap : Windows::IInspectable
{
    virtual HRESULT __stdcall abi_SetSoftwareBitmap(Windows::Graphics::Imaging::ISoftwareBitmap * bitmap) = 0;
};

struct __declspec(uuid("72a49a1c-8081-438d-91bc-94ecfc8185c6")) __declspec(novtable) IBitmapFrame : Windows::IInspectable
{
    virtual HRESULT __stdcall abi_GetThumbnailAsync(Windows::Foundation::IAsyncOperation<Windows::Graphics::Imaging::ImageStream> ** asyncInfo) = 0;
    virtual HRESULT __stdcall get_BitmapProperties(Windows::Graphics::Imaging::IBitmapPropertiesView ** value) = 0;
    virtual HRESULT __stdcall get_BitmapPixelFormat(winrt::Windows::Graphics::Imaging::BitmapPixelFormat * value) = 0;
    virtual HRESULT __stdcall get_BitmapAlphaMode(winrt::Windows::Graphics::Imaging::BitmapAlphaMode * value) = 0;
    virtual HRESULT __stdcall get_DpiX(double * value) = 0;
    virtual HRESULT __stdcall get_DpiY(double * value) = 0;
    virtual HRESULT __stdcall get_PixelWidth(uint32_t * value) = 0;
    virtual HRESULT __stdcall get_PixelHeight(uint32_t * value) = 0;
    virtual HRESULT __stdcall get_OrientedPixelWidth(uint32_t * value) = 0;
    virtual HRESULT __stdcall get_OrientedPixelHeight(uint32_t * value) = 0;
    virtual HRESULT __stdcall abi_GetPixelDataAsync(Windows::Foundation::IAsyncOperation<Windows::Graphics::Imaging::PixelDataProvider> ** asyncInfo) = 0;
    virtual HRESULT __stdcall abi_GetPixelDataTransformedAsync(winrt::Windows::Graphics::Imaging::BitmapPixelFormat pixelFormat, winrt::Windows::Graphics::Imaging::BitmapAlphaMode alphaMode, Windows::Graphics::Imaging::IBitmapTransform * transform, winrt::Windows::Graphics::Imaging::ExifOrientationMode exifOrientationMode, winrt::Windows::Graphics::Imaging::ColorManagementMode colorManagementMode, Windows::Foundation::IAsyncOperation<Windows::Graphics::Imaging::PixelDataProvider> ** asyncInfo) = 0;
};

struct __declspec(uuid("fe287c9a-420c-4963-87ad-691436e08383")) __declspec(novtable) IBitmapFrameWithSoftwareBitmap : Windows::IInspectable
{
    virtual HRESULT __stdcall abi_GetSoftwareBitmapAsync(Windows::Foundation::IAsyncOperation<Windows::Graphics::Imaging::SoftwareBitmap> ** value) = 0;
    virtual HRESULT __stdcall abi_GetSoftwareBitmapConvertedAsync(winrt::Windows::Graphics::Imaging::BitmapPixelFormat pixelFormat, winrt::Windows::Graphics::Imaging::BitmapAlphaMode alphaMode, Windows::Foundation::IAsyncOperation<Windows::Graphics::Imaging::SoftwareBitmap> ** value) = 0;
    virtual HRESULT __stdcall abi_GetSoftwareBitmapTransformedAsync(winrt::Windows::Graphics::Imaging::BitmapPixelFormat pixelFormat, winrt::Windows::Graphics::Imaging::BitmapAlphaMode alphaMode, Windows::Graphics::Imaging::IBitmapTransform * transform, winrt::Windows::Graphics::Imaging::ExifOrientationMode exifOrientationMode, winrt::Windows::Graphics::Imaging::ColorManagementMode colorManagementMode, Windows::Foundation::IAsyncOperation<Windows::Graphics::Imaging::SoftwareBitmap> ** value) = 0;
};

struct __declspec(uuid("ea9f4f1b-b505-4450-a4d1-e8ca94529d8d")) __declspec(novtable) IBitmapProperties : Windows::IInspectable
{
    virtual HRESULT __stdcall abi_SetPropertiesAsync(Windows::Foundation::Collections::IIterable<Windows::Foundation::Collections::IKeyValuePair<hstring, Windows::Graphics::Imaging::BitmapTypedValue>> * propertiesToSet, Windows::Foundation::IAsyncAction ** asyncInfo) = 0;
};

struct __declspec(uuid("7e0fe87a-3a70-48f8-9c55-196cf5a545f5")) __declspec(novtable) IBitmapPropertiesView : Windows::IInspectable
{
    virtual HRESULT __stdcall abi_GetPropertiesAsync(Windows::Foundation::Collections::IIterable<hstring> * propertiesToRetrieve, Windows::Foundation::IAsyncOperation<Windows::Graphics::Imaging::BitmapPropertySet> ** asyncInfo) = 0;
};

struct __declspec(uuid("ae755344-e268-4d35-adcf-e995d31a8d34")) __declspec(novtable) IBitmapTransform : Windows::IInspectable
{
    virtual HRESULT __stdcall get_ScaledWidth(uint32_t * value) = 0;
    virtual HRESULT __stdcall put_ScaledWidth(uint32_t value) = 0;
    virtual HRESULT __stdcall get_ScaledHeight(uint32_t * value) = 0;
    virtual HRESULT __stdcall put_ScaledHeight(uint32_t value) = 0;
    virtual HRESULT __stdcall get_InterpolationMode(winrt::Windows::Graphics::Imaging::BitmapInterpolationMode * value) = 0;
    virtual HRESULT __stdcall put_InterpolationMode(winrt::Windows::Graphics::Imaging::BitmapInterpolationMode value) = 0;
    virtual HRESULT __stdcall get_Flip(winrt::Windows::Graphics::Imaging::BitmapFlip * value) = 0;
    virtual HRESULT __stdcall put_Flip(winrt::Windows::Graphics::Imaging::BitmapFlip value) = 0;
    virtual HRESULT __stdcall get_Rotation(winrt::Windows::Graphics::Imaging::BitmapRotation * value) = 0;
    virtual HRESULT __stdcall put_Rotation(winrt::Windows::Graphics::Imaging::BitmapRotation value) = 0;
    virtual HRESULT __stdcall get_Bounds(Windows::Graphics::Imaging::BitmapBounds * value) = 0;
    virtual HRESULT __stdcall put_Bounds(Windows::Graphics::Imaging::BitmapBounds value) = 0;
};

struct __declspec(uuid("cd8044a9-2443-4000-b0cd-79316c56f589")) __declspec(novtable) IBitmapTypedValue : Windows::IInspectable
{
    virtual HRESULT __stdcall get_Value(Windows::IInspectable ** value) = 0;
    virtual HRESULT __stdcall get_Type(winrt::Windows::Foundation::PropertyType * value) = 0;
};

struct __declspec(uuid("92dbb599-ce13-46bb-9545-cb3a3f63eb8b")) __declspec(novtable) IBitmapTypedValueFactory : Windows::IInspectable
{
    virtual HRESULT __stdcall abi_Create(Windows::IInspectable * value, winrt::Windows::Foundation::PropertyType type, Windows::Graphics::Imaging::IBitmapTypedValue ** bitmapTypedValue) = 0;
};

struct __declspec(uuid("dd831f25-185c-4595-9fb9-ccbe6ec18a6f")) __declspec(novtable) IPixelDataProvider : Windows::IInspectable
{
    virtual HRESULT __stdcall abi_DetachPixelData(uint32_t * __pixelDataSize, uint8_t ** pixelData) = 0;
};

struct __declspec(uuid("689e0708-7eef-483f-963f-da938818e073")) __declspec(novtable) ISoftwareBitmap : Windows::IInspectable
{
    virtual HRESULT __stdcall get_BitmapPixelFormat(winrt::Windows::Graphics::Imaging::BitmapPixelFormat * value) = 0;
    virtual HRESULT __stdcall get_BitmapAlphaMode(winrt::Windows::Graphics::Imaging::BitmapAlphaMode * value) = 0;
    virtual HRESULT __stdcall get_PixelWidth(int32_t * value) = 0;
    virtual HRESULT __stdcall get_PixelHeight(int32_t * value) = 0;
    virtual HRESULT __stdcall get_IsReadOnly(bool * value) = 0;
    virtual HRESULT __stdcall put_DpiX(double value) = 0;
    virtual HRESULT __stdcall get_DpiX(double * value) = 0;
    virtual HRESULT __stdcall put_DpiY(double value) = 0;
    virtual HRESULT __stdcall get_DpiY(double * value) = 0;
    virtual HRESULT __stdcall abi_LockBuffer(winrt::Windows::Graphics::Imaging::BitmapBufferAccessMode mode, Windows::Graphics::Imaging::IBitmapBuffer ** value) = 0;
    virtual HRESULT __stdcall abi_CopyTo(Windows::Graphics::Imaging::ISoftwareBitmap * bitmap) = 0;
    virtual HRESULT __stdcall abi_CopyFromBuffer(Windows::Storage::Streams::IBuffer * buffer) = 0;
    virtual HRESULT __stdcall abi_CopyToBuffer(Windows::Storage::Streams::IBuffer * buffer) = 0;
    virtual HRESULT __stdcall abi_GetReadOnlyView(Windows::Graphics::Imaging::ISoftwareBitmap ** value) = 0;
};

struct __declspec(uuid("c99feb69-2d62-4d47-a6b3-4fdb6a07fdf8")) __declspec(novtable) ISoftwareBitmapFactory : Windows::IInspectable
{
    virtual HRESULT __stdcall abi_Create(winrt::Windows::Graphics::Imaging::BitmapPixelFormat format, int32_t width, int32_t height, Windows::Graphics::Imaging::ISoftwareBitmap ** value) = 0;
    virtual HRESULT __stdcall abi_CreateWithAlpha(winrt::Windows::Graphics::Imaging::BitmapPixelFormat format, int32_t width, int32_t height, winrt::Windows::Graphics::Imaging::BitmapAlphaMode alpha, Windows::Graphics::Imaging::ISoftwareBitmap ** value) = 0;
};

struct __declspec(uuid("df0385db-672f-4a9d-806e-c2442f343e86")) __declspec(novtable) ISoftwareBitmapStatics : Windows::IInspectable
{
    virtual HRESULT __stdcall abi_Copy(Windows::Graphics::Imaging::ISoftwareBitmap * source, Windows::Graphics::Imaging::ISoftwareBitmap ** value) = 0;
    virtual HRESULT __stdcall abi_Convert(Windows::Graphics::Imaging::ISoftwareBitmap * source, winrt::Windows::Graphics::Imaging::BitmapPixelFormat format, Windows::Graphics::Imaging::ISoftwareBitmap ** value) = 0;
    virtual HRESULT __stdcall abi_ConvertWithAlpha(Windows::Graphics::Imaging::ISoftwareBitmap * source, winrt::Windows::Graphics::Imaging::BitmapPixelFormat format, winrt::Windows::Graphics::Imaging::BitmapAlphaMode alpha, Windows::Graphics::Imaging::ISoftwareBitmap ** value) = 0;
    virtual HRESULT __stdcall abi_CreateCopyFromBuffer(Windows::Storage::Streams::IBuffer * source, winrt::Windows::Graphics::Imaging::BitmapPixelFormat format, int32_t width, int32_t height, Windows::Graphics::Imaging::ISoftwareBitmap ** value) = 0;
    virtual HRESULT __stdcall abi_CreateCopyWithAlphaFromBuffer(Windows::Storage::Streams::IBuffer * source, winrt::Windows::Graphics::Imaging::BitmapPixelFormat format, int32_t width, int32_t height, winrt::Windows::Graphics::Imaging::BitmapAlphaMode alpha, Windows::Graphics::Imaging::ISoftwareBitmap ** value) = 0;
    virtual HRESULT __stdcall abi_CreateCopyFromSurfaceAsync(Windows::Graphics::DirectX::Direct3D11::IDirect3DSurface * surface, Windows::Foundation::IAsyncOperation<Windows::Graphics::Imaging::SoftwareBitmap> ** value) = 0;
    virtual HRESULT __stdcall abi_CreateCopyWithAlphaFromSurfaceAsync(Windows::Graphics::DirectX::Direct3D11::IDirect3DSurface * surface, winrt::Windows::Graphics::Imaging::BitmapAlphaMode alpha, Windows::Foundation::IAsyncOperation<Windows::Graphics::Imaging::SoftwareBitmap> ** value) = 0;
};

}

namespace ABI {

template <> struct traits<Windows::Graphics::Imaging::BitmapBuffer> { using default_interface = Windows::Graphics::Imaging::IBitmapBuffer; };
template <> struct traits<Windows::Graphics::Imaging::BitmapCodecInformation> { using default_interface = Windows::Graphics::Imaging::IBitmapCodecInformation; };
template <> struct traits<Windows::Graphics::Imaging::BitmapDecoder> { using default_interface = Windows::Graphics::Imaging::IBitmapDecoder; };
template <> struct traits<Windows::Graphics::Imaging::BitmapEncoder> { using default_interface = Windows::Graphics::Imaging::IBitmapEncoder; };
template <> struct traits<Windows::Graphics::Imaging::BitmapFrame> { using default_interface = Windows::Graphics::Imaging::IBitmapFrame; };
template <> struct traits<Windows::Graphics::Imaging::BitmapProperties> { using default_interface = Windows::Graphics::Imaging::IBitmapProperties; };
template <> struct traits<Windows::Graphics::Imaging::BitmapPropertiesView> { using default_interface = Windows::Graphics::Imaging::IBitmapPropertiesView; };
template <> struct traits<Windows::Graphics::Imaging::BitmapPropertySet> { using default_interface = Windows::Foundation::Collections::IMap<hstring, Windows::Graphics::Imaging::BitmapTypedValue>; };
template <> struct traits<Windows::Graphics::Imaging::BitmapTransform> { using default_interface = Windows::Graphics::Imaging::IBitmapTransform; };
template <> struct traits<Windows::Graphics::Imaging::BitmapTypedValue> { using default_interface = Windows::Graphics::Imaging::IBitmapTypedValue; };
template <> struct traits<Windows::Graphics::Imaging::ImageStream> { using default_interface = Windows::Storage::Streams::IRandomAccessStreamWithContentType; };
template <> struct traits<Windows::Graphics::Imaging::PixelDataProvider> { using default_interface = Windows::Graphics::Imaging::IPixelDataProvider; };
template <> struct traits<Windows::Graphics::Imaging::SoftwareBitmap> { using default_interface = Windows::Graphics::Imaging::ISoftwareBitmap; };

}

namespace Windows::Graphics::Imaging {

template <typename T> class impl_IBitmapBuffer;
template <typename T> class impl_IBitmapCodecInformation;
template <typename T> class impl_IBitmapDecoder;
template <typename T> class impl_IBitmapDecoderStatics;
template <typename T> class impl_IBitmapEncoder;
template <typename T> class impl_IBitmapEncoderStatics;
template <typename T> class impl_IBitmapEncoderWithSoftwareBitmap;
template <typename T> class impl_IBitmapFrame;
template <typename T> class impl_IBitmapFrameWithSoftwareBitmap;
template <typename T> class impl_IBitmapProperties;
template <typename T> class impl_IBitmapPropertiesView;
template <typename T> class impl_IBitmapTransform;
template <typename T> class impl_IBitmapTypedValue;
template <typename T> class impl_IBitmapTypedValueFactory;
template <typename T> class impl_IPixelDataProvider;
template <typename T> class impl_ISoftwareBitmap;
template <typename T> class impl_ISoftwareBitmapFactory;
template <typename T> class impl_ISoftwareBitmapStatics;

}

namespace impl {

template <> struct traits<Windows::Graphics::Imaging::IBitmapBuffer>
{
    using abi = ABI::Windows::Graphics::Imaging::IBitmapBuffer;
    template <typename D> using consume = Windows::Graphics::Imaging::impl_IBitmapBuffer<D>;
};

template <> struct traits<Windows::Graphics::Imaging::IBitmapCodecInformation>
{
    using abi = ABI::Windows::Graphics::Imaging::IBitmapCodecInformation;
    template <typename D> using consume = Windows::Graphics::Imaging::impl_IBitmapCodecInformation<D>;
};

template <> struct traits<Windows::Graphics::Imaging::IBitmapDecoder>
{
    using abi = ABI::Windows::Graphics::Imaging::IBitmapDecoder;
    template <typename D> using consume = Windows::Graphics::Imaging::impl_IBitmapDecoder<D>;
};

template <> struct traits<Windows::Graphics::Imaging::IBitmapDecoderStatics>
{
    using abi = ABI::Windows::Graphics::Imaging::IBitmapDecoderStatics;
    template <typename D> using consume = Windows::Graphics::Imaging::impl_IBitmapDecoderStatics<D>;
};

template <> struct traits<Windows::Graphics::Imaging::IBitmapEncoder>
{
    using abi = ABI::Windows::Graphics::Imaging::IBitmapEncoder;
    template <typename D> using consume = Windows::Graphics::Imaging::impl_IBitmapEncoder<D>;
};

template <> struct traits<Windows::Graphics::Imaging::IBitmapEncoderStatics>
{
    using abi = ABI::Windows::Graphics::Imaging::IBitmapEncoderStatics;
    template <typename D> using consume = Windows::Graphics::Imaging::impl_IBitmapEncoderStatics<D>;
};

template <> struct traits<Windows::Graphics::Imaging::IBitmapEncoderWithSoftwareBitmap>
{
    using abi = ABI::Windows::Graphics::Imaging::IBitmapEncoderWithSoftwareBitmap;
    template <typename D> using consume = Windows::Graphics::Imaging::impl_IBitmapEncoderWithSoftwareBitmap<D>;
};

template <> struct traits<Windows::Graphics::Imaging::IBitmapFrame>
{
    using abi = ABI::Windows::Graphics::Imaging::IBitmapFrame;
    template <typename D> using consume = Windows::Graphics::Imaging::impl_IBitmapFrame<D>;
};

template <> struct traits<Windows::Graphics::Imaging::IBitmapFrameWithSoftwareBitmap>
{
    using abi = ABI::Windows::Graphics::Imaging::IBitmapFrameWithSoftwareBitmap;
    template <typename D> using consume = Windows::Graphics::Imaging::impl_IBitmapFrameWithSoftwareBitmap<D>;
};

template <> struct traits<Windows::Graphics::Imaging::IBitmapProperties>
{
    using abi = ABI::Windows::Graphics::Imaging::IBitmapProperties;
    template <typename D> using consume = Windows::Graphics::Imaging::impl_IBitmapProperties<D>;
};

template <> struct traits<Windows::Graphics::Imaging::IBitmapPropertiesView>
{
    using abi = ABI::Windows::Graphics::Imaging::IBitmapPropertiesView;
    template <typename D> using consume = Windows::Graphics::Imaging::impl_IBitmapPropertiesView<D>;
};

template <> struct traits<Windows::Graphics::Imaging::IBitmapTransform>
{
    using abi = ABI::Windows::Graphics::Imaging::IBitmapTransform;
    template <typename D> using consume = Windows::Graphics::Imaging::impl_IBitmapTransform<D>;
};

template <> struct traits<Windows::Graphics::Imaging::IBitmapTypedValue>
{
    using abi = ABI::Windows::Graphics::Imaging::IBitmapTypedValue;
    template <typename D> using consume = Windows::Graphics::Imaging::impl_IBitmapTypedValue<D>;
};

template <> struct traits<Windows::Graphics::Imaging::IBitmapTypedValueFactory>
{
    using abi = ABI::Windows::Graphics::Imaging::IBitmapTypedValueFactory;
    template <typename D> using consume = Windows::Graphics::Imaging::impl_IBitmapTypedValueFactory<D>;
};

template <> struct traits<Windows::Graphics::Imaging::IPixelDataProvider>
{
    using abi = ABI::Windows::Graphics::Imaging::IPixelDataProvider;
    template <typename D> using consume = Windows::Graphics::Imaging::impl_IPixelDataProvider<D>;
};

template <> struct traits<Windows::Graphics::Imaging::ISoftwareBitmap>
{
    using abi = ABI::Windows::Graphics::Imaging::ISoftwareBitmap;
    template <typename D> using consume = Windows::Graphics::Imaging::impl_ISoftwareBitmap<D>;
};

template <> struct traits<Windows::Graphics::Imaging::ISoftwareBitmapFactory>
{
    using abi = ABI::Windows::Graphics::Imaging::ISoftwareBitmapFactory;
    template <typename D> using consume = Windows::Graphics::Imaging::impl_ISoftwareBitmapFactory<D>;
};

template <> struct traits<Windows::Graphics::Imaging::ISoftwareBitmapStatics>
{
    using abi = ABI::Windows::Graphics::Imaging::ISoftwareBitmapStatics;
    template <typename D> using consume = Windows::Graphics::Imaging::impl_ISoftwareBitmapStatics<D>;
};

template <> struct traits<Windows::Graphics::Imaging::BitmapBuffer>
{
    using abi = ABI::Windows::Graphics::Imaging::BitmapBuffer;
    using default_interface = Windows::Graphics::Imaging::IBitmapBuffer;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Graphics.Imaging.BitmapBuffer"; }
};

template <> struct traits<Windows::Graphics::Imaging::BitmapCodecInformation>
{
    using abi = ABI::Windows::Graphics::Imaging::BitmapCodecInformation;
    using default_interface = Windows::Graphics::Imaging::IBitmapCodecInformation;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Graphics.Imaging.BitmapCodecInformation"; }
};

template <> struct traits<Windows::Graphics::Imaging::BitmapDecoder>
{
    using abi = ABI::Windows::Graphics::Imaging::BitmapDecoder;
    using default_interface = Windows::Graphics::Imaging::IBitmapDecoder;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Graphics.Imaging.BitmapDecoder"; }
};

template <> struct traits<Windows::Graphics::Imaging::BitmapEncoder>
{
    using abi = ABI::Windows::Graphics::Imaging::BitmapEncoder;
    using default_interface = Windows::Graphics::Imaging::IBitmapEncoder;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Graphics.Imaging.BitmapEncoder"; }
};

template <> struct traits<Windows::Graphics::Imaging::BitmapFrame>
{
    using abi = ABI::Windows::Graphics::Imaging::BitmapFrame;
    using default_interface = Windows::Graphics::Imaging::IBitmapFrame;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Graphics.Imaging.BitmapFrame"; }
};

template <> struct traits<Windows::Graphics::Imaging::BitmapProperties>
{
    using abi = ABI::Windows::Graphics::Imaging::BitmapProperties;
    using default_interface = Windows::Graphics::Imaging::IBitmapProperties;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Graphics.Imaging.BitmapProperties"; }
};

template <> struct traits<Windows::Graphics::Imaging::BitmapPropertiesView>
{
    using abi = ABI::Windows::Graphics::Imaging::BitmapPropertiesView;
    using default_interface = Windows::Graphics::Imaging::IBitmapPropertiesView;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Graphics.Imaging.BitmapPropertiesView"; }
};

template <> struct traits<Windows::Graphics::Imaging::BitmapPropertySet>
{
    using abi = ABI::Windows::Graphics::Imaging::BitmapPropertySet;
    using default_interface = Windows::Foundation::Collections::IMap<hstring, Windows::Graphics::Imaging::BitmapTypedValue>;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Graphics.Imaging.BitmapPropertySet"; }
};

template <> struct traits<Windows::Graphics::Imaging::BitmapTransform>
{
    using abi = ABI::Windows::Graphics::Imaging::BitmapTransform;
    using default_interface = Windows::Graphics::Imaging::IBitmapTransform;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Graphics.Imaging.BitmapTransform"; }
};

template <> struct traits<Windows::Graphics::Imaging::BitmapTypedValue>
{
    using abi = ABI::Windows::Graphics::Imaging::BitmapTypedValue;
    using default_interface = Windows::Graphics::Imaging::IBitmapTypedValue;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Graphics.Imaging.BitmapTypedValue"; }
};

template <> struct traits<Windows::Graphics::Imaging::ImageStream>
{
    using abi = ABI::Windows::Graphics::Imaging::ImageStream;
    using default_interface = Windows::Storage::Streams::IRandomAccessStreamWithContentType;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Graphics.Imaging.ImageStream"; }
};

template <> struct traits<Windows::Graphics::Imaging::PixelDataProvider>
{
    using abi = ABI::Windows::Graphics::Imaging::PixelDataProvider;
    using default_interface = Windows::Graphics::Imaging::IPixelDataProvider;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Graphics.Imaging.PixelDataProvider"; }
};

template <> struct traits<Windows::Graphics::Imaging::SoftwareBitmap>
{
    using abi = ABI::Windows::Graphics::Imaging::SoftwareBitmap;
    using default_interface = Windows::Graphics::Imaging::ISoftwareBitmap;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Graphics.Imaging.SoftwareBitmap"; }
};

}

}