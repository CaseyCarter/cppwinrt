// C++ for the Windows Runtime v1.29
// Copyright (c) 2016 Microsoft Corporation

#pragma once

#include "internal\Windows.Media.FaceAnalysis.class.h"
#include "internal\Windows.Graphics.Imaging.class.h"
#include "internal\Windows.Foundation.class.h"
#include "internal\Windows.Foundation.Collections.class.h"
#include "internal\Windows.Media.class.h"
#include "Windows.Media.h"

WINRT_EXPORT namespace winrt {

namespace impl {

template <typename D>
struct produce<D, Windows::Media::FaceAnalysis::IDetectedFace> : produce_base<D, Windows::Media::FaceAnalysis::IDetectedFace>
{
    HRESULT __stdcall get_FaceBox(abi_arg_out<Windows::Graphics::Imaging::BitmapBounds> returnValue) noexcept override
    {
        try
        {
            *returnValue = detach(shim().FaceBox());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Media::FaceAnalysis::IFaceDetector> : produce_base<D, Windows::Media::FaceAnalysis::IFaceDetector>
{
    HRESULT __stdcall abi_DetectFacesAsync(abi_arg_in<Windows::Graphics::Imaging::ISoftwareBitmap> image, abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVector<Windows::Media::FaceAnalysis::DetectedFace>>> returnValue) noexcept override
    {
        try
        {
            *returnValue = detach(shim().DetectFacesAsync(*reinterpret_cast<const Windows::Graphics::Imaging::SoftwareBitmap *>(&image)));
            return S_OK;
        }
        catch (...)
        {
            *returnValue = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_DetectFacesWithSearchAreaAsync(abi_arg_in<Windows::Graphics::Imaging::ISoftwareBitmap> image, abi_arg_in<Windows::Graphics::Imaging::BitmapBounds> searchArea, abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVector<Windows::Media::FaceAnalysis::DetectedFace>>> returnValue) noexcept override
    {
        try
        {
            *returnValue = detach(shim().DetectFacesAsync(*reinterpret_cast<const Windows::Graphics::Imaging::SoftwareBitmap *>(&image), *reinterpret_cast<const Windows::Graphics::Imaging::BitmapBounds *>(&searchArea)));
            return S_OK;
        }
        catch (...)
        {
            *returnValue = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_MinDetectableFaceSize(abi_arg_out<Windows::Graphics::Imaging::BitmapSize> returnValue) noexcept override
    {
        try
        {
            *returnValue = detach(shim().MinDetectableFaceSize());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_MinDetectableFaceSize(abi_arg_in<Windows::Graphics::Imaging::BitmapSize> value) noexcept override
    {
        try
        {
            shim().MinDetectableFaceSize(*reinterpret_cast<const Windows::Graphics::Imaging::BitmapSize *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_MaxDetectableFaceSize(abi_arg_out<Windows::Graphics::Imaging::BitmapSize> returnValue) noexcept override
    {
        try
        {
            *returnValue = detach(shim().MaxDetectableFaceSize());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_MaxDetectableFaceSize(abi_arg_in<Windows::Graphics::Imaging::BitmapSize> value) noexcept override
    {
        try
        {
            shim().MaxDetectableFaceSize(*reinterpret_cast<const Windows::Graphics::Imaging::BitmapSize *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Media::FaceAnalysis::IFaceDetectorStatics> : produce_base<D, Windows::Media::FaceAnalysis::IFaceDetectorStatics>
{
    HRESULT __stdcall abi_CreateAsync(abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Media::FaceAnalysis::FaceDetector>> returnValue) noexcept override
    {
        try
        {
            *returnValue = detach(shim().CreateAsync());
            return S_OK;
        }
        catch (...)
        {
            *returnValue = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetSupportedBitmapPixelFormats(abi_arg_out<Windows::Foundation::Collections::IVectorView<winrt::Windows::Graphics::Imaging::BitmapPixelFormat>> result) noexcept override
    {
        try
        {
            *result = detach(shim().GetSupportedBitmapPixelFormats());
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_IsBitmapPixelFormatSupported(Windows::Graphics::Imaging::BitmapPixelFormat bitmapPixelFormat, bool * result) noexcept override
    {
        try
        {
            *result = detach(shim().IsBitmapPixelFormatSupported(bitmapPixelFormat));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_IsSupported(bool * returnValue) noexcept override
    {
        try
        {
            *returnValue = detach(shim().IsSupported());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Media::FaceAnalysis::IFaceTracker> : produce_base<D, Windows::Media::FaceAnalysis::IFaceTracker>
{
    HRESULT __stdcall abi_ProcessNextFrameAsync(abi_arg_in<Windows::Media::IVideoFrame> videoFrame, abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVector<Windows::Media::FaceAnalysis::DetectedFace>>> returnValue) noexcept override
    {
        try
        {
            *returnValue = detach(shim().ProcessNextFrameAsync(*reinterpret_cast<const Windows::Media::VideoFrame *>(&videoFrame)));
            return S_OK;
        }
        catch (...)
        {
            *returnValue = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_MinDetectableFaceSize(abi_arg_out<Windows::Graphics::Imaging::BitmapSize> returnValue) noexcept override
    {
        try
        {
            *returnValue = detach(shim().MinDetectableFaceSize());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_MinDetectableFaceSize(abi_arg_in<Windows::Graphics::Imaging::BitmapSize> value) noexcept override
    {
        try
        {
            shim().MinDetectableFaceSize(*reinterpret_cast<const Windows::Graphics::Imaging::BitmapSize *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_MaxDetectableFaceSize(abi_arg_out<Windows::Graphics::Imaging::BitmapSize> returnValue) noexcept override
    {
        try
        {
            *returnValue = detach(shim().MaxDetectableFaceSize());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_MaxDetectableFaceSize(abi_arg_in<Windows::Graphics::Imaging::BitmapSize> value) noexcept override
    {
        try
        {
            shim().MaxDetectableFaceSize(*reinterpret_cast<const Windows::Graphics::Imaging::BitmapSize *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Media::FaceAnalysis::IFaceTrackerStatics> : produce_base<D, Windows::Media::FaceAnalysis::IFaceTrackerStatics>
{
    HRESULT __stdcall abi_CreateAsync(abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Media::FaceAnalysis::FaceTracker>> returnValue) noexcept override
    {
        try
        {
            *returnValue = detach(shim().CreateAsync());
            return S_OK;
        }
        catch (...)
        {
            *returnValue = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetSupportedBitmapPixelFormats(abi_arg_out<Windows::Foundation::Collections::IVectorView<winrt::Windows::Graphics::Imaging::BitmapPixelFormat>> result) noexcept override
    {
        try
        {
            *result = detach(shim().GetSupportedBitmapPixelFormats());
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_IsBitmapPixelFormatSupported(Windows::Graphics::Imaging::BitmapPixelFormat bitmapPixelFormat, bool * result) noexcept override
    {
        try
        {
            *result = detach(shim().IsBitmapPixelFormatSupported(bitmapPixelFormat));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_IsSupported(bool * returnValue) noexcept override
    {
        try
        {
            *returnValue = detach(shim().IsSupported());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

}

namespace Windows::Media::FaceAnalysis {

template <typename D> Windows::Graphics::Imaging::BitmapBounds impl_IDetectedFace<D>::FaceBox() const
{
    Windows::Graphics::Imaging::BitmapBounds returnValue {};
    check_hresult(shim()->get_FaceBox(put(returnValue)));
    return returnValue;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVector<Windows::Media::FaceAnalysis::DetectedFace>> impl_IFaceDetector<D>::DetectFacesAsync(const Windows::Graphics::Imaging::SoftwareBitmap & image) const
{
    Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVector<Windows::Media::FaceAnalysis::DetectedFace>> returnValue;
    check_hresult(shim()->abi_DetectFacesAsync(get(image), put(returnValue)));
    return returnValue;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVector<Windows::Media::FaceAnalysis::DetectedFace>> impl_IFaceDetector<D>::DetectFacesAsync(const Windows::Graphics::Imaging::SoftwareBitmap & image, const Windows::Graphics::Imaging::BitmapBounds & searchArea) const
{
    Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVector<Windows::Media::FaceAnalysis::DetectedFace>> returnValue;
    check_hresult(shim()->abi_DetectFacesWithSearchAreaAsync(get(image), get(searchArea), put(returnValue)));
    return returnValue;
}

template <typename D> Windows::Graphics::Imaging::BitmapSize impl_IFaceDetector<D>::MinDetectableFaceSize() const
{
    Windows::Graphics::Imaging::BitmapSize returnValue {};
    check_hresult(shim()->get_MinDetectableFaceSize(put(returnValue)));
    return returnValue;
}

template <typename D> void impl_IFaceDetector<D>::MinDetectableFaceSize(const Windows::Graphics::Imaging::BitmapSize & value) const
{
    check_hresult(shim()->put_MinDetectableFaceSize(get(value)));
}

template <typename D> Windows::Graphics::Imaging::BitmapSize impl_IFaceDetector<D>::MaxDetectableFaceSize() const
{
    Windows::Graphics::Imaging::BitmapSize returnValue {};
    check_hresult(shim()->get_MaxDetectableFaceSize(put(returnValue)));
    return returnValue;
}

template <typename D> void impl_IFaceDetector<D>::MaxDetectableFaceSize(const Windows::Graphics::Imaging::BitmapSize & value) const
{
    check_hresult(shim()->put_MaxDetectableFaceSize(get(value)));
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Media::FaceAnalysis::FaceDetector> impl_IFaceDetectorStatics<D>::CreateAsync() const
{
    Windows::Foundation::IAsyncOperation<Windows::Media::FaceAnalysis::FaceDetector> returnValue;
    check_hresult(shim()->abi_CreateAsync(put(returnValue)));
    return returnValue;
}

template <typename D> Windows::Foundation::Collections::IVectorView<winrt::Windows::Graphics::Imaging::BitmapPixelFormat> impl_IFaceDetectorStatics<D>::GetSupportedBitmapPixelFormats() const
{
    Windows::Foundation::Collections::IVectorView<winrt::Windows::Graphics::Imaging::BitmapPixelFormat> result;
    check_hresult(shim()->abi_GetSupportedBitmapPixelFormats(put(result)));
    return result;
}

template <typename D> bool impl_IFaceDetectorStatics<D>::IsBitmapPixelFormatSupported(Windows::Graphics::Imaging::BitmapPixelFormat bitmapPixelFormat) const
{
    bool result {};
    check_hresult(shim()->abi_IsBitmapPixelFormatSupported(bitmapPixelFormat, &result));
    return result;
}

template <typename D> bool impl_IFaceDetectorStatics<D>::IsSupported() const
{
    bool returnValue {};
    check_hresult(shim()->get_IsSupported(&returnValue));
    return returnValue;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVector<Windows::Media::FaceAnalysis::DetectedFace>> impl_IFaceTracker<D>::ProcessNextFrameAsync(const Windows::Media::VideoFrame & videoFrame) const
{
    Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVector<Windows::Media::FaceAnalysis::DetectedFace>> returnValue;
    check_hresult(shim()->abi_ProcessNextFrameAsync(get(videoFrame), put(returnValue)));
    return returnValue;
}

template <typename D> Windows::Graphics::Imaging::BitmapSize impl_IFaceTracker<D>::MinDetectableFaceSize() const
{
    Windows::Graphics::Imaging::BitmapSize returnValue {};
    check_hresult(shim()->get_MinDetectableFaceSize(put(returnValue)));
    return returnValue;
}

template <typename D> void impl_IFaceTracker<D>::MinDetectableFaceSize(const Windows::Graphics::Imaging::BitmapSize & value) const
{
    check_hresult(shim()->put_MinDetectableFaceSize(get(value)));
}

template <typename D> Windows::Graphics::Imaging::BitmapSize impl_IFaceTracker<D>::MaxDetectableFaceSize() const
{
    Windows::Graphics::Imaging::BitmapSize returnValue {};
    check_hresult(shim()->get_MaxDetectableFaceSize(put(returnValue)));
    return returnValue;
}

template <typename D> void impl_IFaceTracker<D>::MaxDetectableFaceSize(const Windows::Graphics::Imaging::BitmapSize & value) const
{
    check_hresult(shim()->put_MaxDetectableFaceSize(get(value)));
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Media::FaceAnalysis::FaceTracker> impl_IFaceTrackerStatics<D>::CreateAsync() const
{
    Windows::Foundation::IAsyncOperation<Windows::Media::FaceAnalysis::FaceTracker> returnValue;
    check_hresult(shim()->abi_CreateAsync(put(returnValue)));
    return returnValue;
}

template <typename D> Windows::Foundation::Collections::IVectorView<winrt::Windows::Graphics::Imaging::BitmapPixelFormat> impl_IFaceTrackerStatics<D>::GetSupportedBitmapPixelFormats() const
{
    Windows::Foundation::Collections::IVectorView<winrt::Windows::Graphics::Imaging::BitmapPixelFormat> result;
    check_hresult(shim()->abi_GetSupportedBitmapPixelFormats(put(result)));
    return result;
}

template <typename D> bool impl_IFaceTrackerStatics<D>::IsBitmapPixelFormatSupported(Windows::Graphics::Imaging::BitmapPixelFormat bitmapPixelFormat) const
{
    bool result {};
    check_hresult(shim()->abi_IsBitmapPixelFormatSupported(bitmapPixelFormat, &result));
    return result;
}

template <typename D> bool impl_IFaceTrackerStatics<D>::IsSupported() const
{
    bool returnValue {};
    check_hresult(shim()->get_IsSupported(&returnValue));
    return returnValue;
}

inline Windows::Foundation::IAsyncOperation<Windows::Media::FaceAnalysis::FaceDetector> FaceDetector::CreateAsync()
{
    return GetActivationFactory<FaceDetector, IFaceDetectorStatics>().CreateAsync();
}

inline Windows::Foundation::Collections::IVectorView<winrt::Windows::Graphics::Imaging::BitmapPixelFormat> FaceDetector::GetSupportedBitmapPixelFormats()
{
    return GetActivationFactory<FaceDetector, IFaceDetectorStatics>().GetSupportedBitmapPixelFormats();
}

inline bool FaceDetector::IsBitmapPixelFormatSupported(Windows::Graphics::Imaging::BitmapPixelFormat bitmapPixelFormat)
{
    return GetActivationFactory<FaceDetector, IFaceDetectorStatics>().IsBitmapPixelFormatSupported(bitmapPixelFormat);
}

inline bool FaceDetector::IsSupported()
{
    return GetActivationFactory<FaceDetector, IFaceDetectorStatics>().IsSupported();
}

inline Windows::Foundation::IAsyncOperation<Windows::Media::FaceAnalysis::FaceTracker> FaceTracker::CreateAsync()
{
    return GetActivationFactory<FaceTracker, IFaceTrackerStatics>().CreateAsync();
}

inline Windows::Foundation::Collections::IVectorView<winrt::Windows::Graphics::Imaging::BitmapPixelFormat> FaceTracker::GetSupportedBitmapPixelFormats()
{
    return GetActivationFactory<FaceTracker, IFaceTrackerStatics>().GetSupportedBitmapPixelFormats();
}

inline bool FaceTracker::IsBitmapPixelFormatSupported(Windows::Graphics::Imaging::BitmapPixelFormat bitmapPixelFormat)
{
    return GetActivationFactory<FaceTracker, IFaceTrackerStatics>().IsBitmapPixelFormatSupported(bitmapPixelFormat);
}

inline bool FaceTracker::IsSupported()
{
    return GetActivationFactory<FaceTracker, IFaceTrackerStatics>().IsSupported();
}

}

}
