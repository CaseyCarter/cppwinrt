// C++ for the Windows Runtime v1.29
// Copyright (c) 2016 Microsoft Corporation

#pragma once

#include "internal/Windows.Foundation.3.h"
#include "internal/Windows.Foundation.Collections.3.h"
#include "internal/Windows.Media.3.h"
#include "internal/Windows.Media.Core.3.h"
#include "internal/Windows.Media.Capture.Frames.3.h"
#include "internal/Windows.Media.MediaProperties.3.h"
#include "internal/Windows.Storage.3.h"
#include "internal/Windows.Storage.Streams.3.h"
#include "internal/Windows.Media.Devices.3.h"
#include "internal/Windows.Media.Effects.3.h"
#include "internal/Windows.Graphics.Imaging.3.h"
#include "internal/Windows.Media.Capture.3.h"
#include "Windows.Media.h"
#include "Windows.Foundation.h"
#include "Windows.Storage.Streams.h"

WINRT_EXPORT namespace winrt {

namespace Windows::Media::Capture {

template <typename L> MediaCaptureFailedEventHandler::MediaCaptureFailedEventHandler(L lambda) :
    MediaCaptureFailedEventHandler(impl::make_delegate<impl_MediaCaptureFailedEventHandler<L>, MediaCaptureFailedEventHandler>(std::forward<L>(lambda)))
{}

template <typename F> MediaCaptureFailedEventHandler::MediaCaptureFailedEventHandler(F * function) :
    MediaCaptureFailedEventHandler([=](auto && ... args) { function(args ...); })
{}

template <typename O, typename M> MediaCaptureFailedEventHandler::MediaCaptureFailedEventHandler(O * object, M method) :
    MediaCaptureFailedEventHandler([=](auto && ... args) { ((*object).*(method))(args ...); })
{}

inline void MediaCaptureFailedEventHandler::operator()(const Windows::Media::Capture::MediaCapture & sender, const Windows::Media::Capture::MediaCaptureFailedEventArgs & errorEventArgs) const
{
    check_hresult((*this)->abi_Invoke(get(sender), get(errorEventArgs)));
}

template <typename L> RecordLimitationExceededEventHandler::RecordLimitationExceededEventHandler(L lambda) :
    RecordLimitationExceededEventHandler(impl::make_delegate<impl_RecordLimitationExceededEventHandler<L>, RecordLimitationExceededEventHandler>(std::forward<L>(lambda)))
{}

template <typename F> RecordLimitationExceededEventHandler::RecordLimitationExceededEventHandler(F * function) :
    RecordLimitationExceededEventHandler([=](auto && ... args) { function(args ...); })
{}

template <typename O, typename M> RecordLimitationExceededEventHandler::RecordLimitationExceededEventHandler(O * object, M method) :
    RecordLimitationExceededEventHandler([=](auto && ... args) { ((*object).*(method))(args ...); })
{}

inline void RecordLimitationExceededEventHandler::operator()(const Windows::Media::Capture::MediaCapture & sender) const
{
    check_hresult((*this)->abi_Invoke(get(sender)));
}

}

namespace impl {

template <typename D>
struct produce<D, Windows::Media::Capture::IAdvancedCapturedPhoto> : produce_base<D, Windows::Media::Capture::IAdvancedCapturedPhoto>
{
    HRESULT __stdcall get_Frame(abi_arg_out<Windows::Media::Capture::ICapturedFrame> value) noexcept override
    {
        try
        {
            *value = detach(this->shim().Frame());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Mode(Windows::Media::Devices::AdvancedPhotoMode * value) noexcept override
    {
        try
        {
            *value = detach(this->shim().Mode());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Context(abi_arg_out<Windows::IInspectable> value) noexcept override
    {
        try
        {
            *value = detach(this->shim().Context());
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
struct produce<D, Windows::Media::Capture::IAdvancedCapturedPhoto2> : produce_base<D, Windows::Media::Capture::IAdvancedCapturedPhoto2>
{
    HRESULT __stdcall get_FrameBoundsRelativeToReferencePhoto(abi_arg_out<Windows::Foundation::IReference<Windows::Foundation::Rect>> value) noexcept override
    {
        try
        {
            *value = detach(this->shim().FrameBoundsRelativeToReferencePhoto());
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
struct produce<D, Windows::Media::Capture::IAdvancedPhotoCapture> : produce_base<D, Windows::Media::Capture::IAdvancedPhotoCapture>
{
    HRESULT __stdcall abi_CaptureAsync(abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Media::Capture::AdvancedCapturedPhoto>> operation) noexcept override
    {
        try
        {
            *operation = detach(this->shim().CaptureAsync());
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_CaptureWithContextAsync(abi_arg_in<Windows::IInspectable> context, abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Media::Capture::AdvancedCapturedPhoto>> operation) noexcept override
    {
        try
        {
            *operation = detach(this->shim().CaptureAsync(*reinterpret_cast<const Windows::IInspectable *>(&context)));
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_OptionalReferencePhotoCaptured(abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::Media::Capture::AdvancedPhotoCapture, Windows::Media::Capture::OptionalReferencePhotoCapturedEventArgs>> handler, event_token * token) noexcept override
    {
        try
        {
            *token = detach(this->shim().OptionalReferencePhotoCaptured(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::Media::Capture::AdvancedPhotoCapture, Windows::Media::Capture::OptionalReferencePhotoCapturedEventArgs> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_OptionalReferencePhotoCaptured(event_token token) noexcept override
    {
        try
        {
            this->shim().OptionalReferencePhotoCaptured(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_AllPhotosCaptured(abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::Media::Capture::AdvancedPhotoCapture, Windows::IInspectable>> handler, event_token * token) noexcept override
    {
        try
        {
            *token = detach(this->shim().AllPhotosCaptured(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::Media::Capture::AdvancedPhotoCapture, Windows::IInspectable> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_AllPhotosCaptured(event_token token) noexcept override
    {
        try
        {
            this->shim().AllPhotosCaptured(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_FinishAsync(abi_arg_out<Windows::Foundation::IAsyncAction> operation) noexcept override
    {
        try
        {
            *operation = detach(this->shim().FinishAsync());
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
struct produce<D, Windows::Media::Capture::IAppCapture> : produce_base<D, Windows::Media::Capture::IAppCapture>
{
    HRESULT __stdcall get_IsCapturingAudio(bool * value) noexcept override
    {
        try
        {
            *value = detach(this->shim().IsCapturingAudio());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_IsCapturingVideo(bool * value) noexcept override
    {
        try
        {
            *value = detach(this->shim().IsCapturingVideo());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_CapturingChanged(abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::Media::Capture::AppCapture, Windows::IInspectable>> handler, event_token * token) noexcept override
    {
        try
        {
            *token = detach(this->shim().CapturingChanged(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::Media::Capture::AppCapture, Windows::IInspectable> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_CapturingChanged(event_token token) noexcept override
    {
        try
        {
            this->shim().CapturingChanged(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Media::Capture::IAppCaptureStatics> : produce_base<D, Windows::Media::Capture::IAppCaptureStatics>
{
    HRESULT __stdcall abi_GetForCurrentView(abi_arg_out<Windows::Media::Capture::IAppCapture> value) noexcept override
    {
        try
        {
            *value = detach(this->shim().GetForCurrentView());
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
struct produce<D, Windows::Media::Capture::ICameraCaptureUI> : produce_base<D, Windows::Media::Capture::ICameraCaptureUI>
{
    HRESULT __stdcall get_PhotoSettings(abi_arg_out<Windows::Media::Capture::ICameraCaptureUIPhotoCaptureSettings> value) noexcept override
    {
        try
        {
            *value = detach(this->shim().PhotoSettings());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_VideoSettings(abi_arg_out<Windows::Media::Capture::ICameraCaptureUIVideoCaptureSettings> value) noexcept override
    {
        try
        {
            *value = detach(this->shim().VideoSettings());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_CaptureFileAsync(Windows::Media::Capture::CameraCaptureUIMode mode, abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Storage::StorageFile>> asyncInfo) noexcept override
    {
        try
        {
            *asyncInfo = detach(this->shim().CaptureFileAsync(mode));
            return S_OK;
        }
        catch (...)
        {
            *asyncInfo = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Media::Capture::ICameraCaptureUIPhotoCaptureSettings> : produce_base<D, Windows::Media::Capture::ICameraCaptureUIPhotoCaptureSettings>
{
    HRESULT __stdcall get_Format(Windows::Media::Capture::CameraCaptureUIPhotoFormat * value) noexcept override
    {
        try
        {
            *value = detach(this->shim().Format());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Format(Windows::Media::Capture::CameraCaptureUIPhotoFormat value) noexcept override
    {
        try
        {
            this->shim().Format(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_MaxResolution(Windows::Media::Capture::CameraCaptureUIMaxPhotoResolution * value) noexcept override
    {
        try
        {
            *value = detach(this->shim().MaxResolution());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_MaxResolution(Windows::Media::Capture::CameraCaptureUIMaxPhotoResolution value) noexcept override
    {
        try
        {
            this->shim().MaxResolution(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_CroppedSizeInPixels(abi_arg_out<Windows::Foundation::Size> value) noexcept override
    {
        try
        {
            *value = detach(this->shim().CroppedSizeInPixels());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_CroppedSizeInPixels(abi_arg_in<Windows::Foundation::Size> value) noexcept override
    {
        try
        {
            this->shim().CroppedSizeInPixels(*reinterpret_cast<const Windows::Foundation::Size *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_CroppedAspectRatio(abi_arg_out<Windows::Foundation::Size> value) noexcept override
    {
        try
        {
            *value = detach(this->shim().CroppedAspectRatio());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_CroppedAspectRatio(abi_arg_in<Windows::Foundation::Size> value) noexcept override
    {
        try
        {
            this->shim().CroppedAspectRatio(*reinterpret_cast<const Windows::Foundation::Size *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_AllowCropping(bool * value) noexcept override
    {
        try
        {
            *value = detach(this->shim().AllowCropping());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_AllowCropping(bool value) noexcept override
    {
        try
        {
            this->shim().AllowCropping(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Media::Capture::ICameraCaptureUIVideoCaptureSettings> : produce_base<D, Windows::Media::Capture::ICameraCaptureUIVideoCaptureSettings>
{
    HRESULT __stdcall get_Format(Windows::Media::Capture::CameraCaptureUIVideoFormat * value) noexcept override
    {
        try
        {
            *value = detach(this->shim().Format());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Format(Windows::Media::Capture::CameraCaptureUIVideoFormat value) noexcept override
    {
        try
        {
            this->shim().Format(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_MaxResolution(Windows::Media::Capture::CameraCaptureUIMaxVideoResolution * value) noexcept override
    {
        try
        {
            *value = detach(this->shim().MaxResolution());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_MaxResolution(Windows::Media::Capture::CameraCaptureUIMaxVideoResolution value) noexcept override
    {
        try
        {
            this->shim().MaxResolution(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_MaxDurationInSeconds(float * value) noexcept override
    {
        try
        {
            *value = detach(this->shim().MaxDurationInSeconds());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_MaxDurationInSeconds(float value) noexcept override
    {
        try
        {
            this->shim().MaxDurationInSeconds(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_AllowTrimming(bool * value) noexcept override
    {
        try
        {
            *value = detach(this->shim().AllowTrimming());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_AllowTrimming(bool value) noexcept override
    {
        try
        {
            this->shim().AllowTrimming(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Media::Capture::ICapturedFrame> : produce_base<D, Windows::Media::Capture::ICapturedFrame>
{
    HRESULT __stdcall get_Width(uint32_t * value) noexcept override
    {
        try
        {
            *value = detach(this->shim().Width());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Height(uint32_t * value) noexcept override
    {
        try
        {
            *value = detach(this->shim().Height());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Media::Capture::ICapturedFrameControlValues> : produce_base<D, Windows::Media::Capture::ICapturedFrameControlValues>
{
    HRESULT __stdcall get_Exposure(abi_arg_out<Windows::Foundation::IReference<Windows::Foundation::TimeSpan>> value) noexcept override
    {
        try
        {
            *value = detach(this->shim().Exposure());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ExposureCompensation(abi_arg_out<Windows::Foundation::IReference<float>> value) noexcept override
    {
        try
        {
            *value = detach(this->shim().ExposureCompensation());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_IsoSpeed(abi_arg_out<Windows::Foundation::IReference<uint32_t>> value) noexcept override
    {
        try
        {
            *value = detach(this->shim().IsoSpeed());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Focus(abi_arg_out<Windows::Foundation::IReference<uint32_t>> value) noexcept override
    {
        try
        {
            *value = detach(this->shim().Focus());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_SceneMode(abi_arg_out<Windows::Foundation::IReference<winrt::Windows::Media::Devices::CaptureSceneMode>> value) noexcept override
    {
        try
        {
            *value = detach(this->shim().SceneMode());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Flashed(abi_arg_out<Windows::Foundation::IReference<bool>> value) noexcept override
    {
        try
        {
            *value = detach(this->shim().Flashed());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_FlashPowerPercent(abi_arg_out<Windows::Foundation::IReference<float>> value) noexcept override
    {
        try
        {
            *value = detach(this->shim().FlashPowerPercent());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_WhiteBalance(abi_arg_out<Windows::Foundation::IReference<uint32_t>> value) noexcept override
    {
        try
        {
            *value = detach(this->shim().WhiteBalance());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ZoomFactor(abi_arg_out<Windows::Foundation::IReference<float>> value) noexcept override
    {
        try
        {
            *value = detach(this->shim().ZoomFactor());
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
struct produce<D, Windows::Media::Capture::ICapturedFrameControlValues2> : produce_base<D, Windows::Media::Capture::ICapturedFrameControlValues2>
{
    HRESULT __stdcall get_FocusState(abi_arg_out<Windows::Foundation::IReference<winrt::Windows::Media::Devices::MediaCaptureFocusState>> value) noexcept override
    {
        try
        {
            *value = detach(this->shim().FocusState());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_IsoDigitalGain(abi_arg_out<Windows::Foundation::IReference<double>> value) noexcept override
    {
        try
        {
            *value = detach(this->shim().IsoDigitalGain());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_IsoAnalogGain(abi_arg_out<Windows::Foundation::IReference<double>> value) noexcept override
    {
        try
        {
            *value = detach(this->shim().IsoAnalogGain());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_SensorFrameRate(abi_arg_out<Windows::Media::MediaProperties::IMediaRatio> value) noexcept override
    {
        try
        {
            *value = detach(this->shim().SensorFrameRate());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_WhiteBalanceGain(abi_arg_out<Windows::Foundation::IReference<Windows::Media::Capture::WhiteBalanceGain>> value) noexcept override
    {
        try
        {
            *value = detach(this->shim().WhiteBalanceGain());
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
struct produce<D, Windows::Media::Capture::ICapturedFrameWithSoftwareBitmap> : produce_base<D, Windows::Media::Capture::ICapturedFrameWithSoftwareBitmap>
{
    HRESULT __stdcall get_SoftwareBitmap(abi_arg_out<Windows::Graphics::Imaging::ISoftwareBitmap> value) noexcept override
    {
        try
        {
            *value = detach(this->shim().SoftwareBitmap());
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
struct produce<D, Windows::Media::Capture::ICapturedPhoto> : produce_base<D, Windows::Media::Capture::ICapturedPhoto>
{
    HRESULT __stdcall get_Frame(abi_arg_out<Windows::Media::Capture::ICapturedFrame> value) noexcept override
    {
        try
        {
            *value = detach(this->shim().Frame());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Thumbnail(abi_arg_out<Windows::Media::Capture::ICapturedFrame> value) noexcept override
    {
        try
        {
            *value = detach(this->shim().Thumbnail());
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
struct produce<D, Windows::Media::Capture::ILowLagMediaRecording> : produce_base<D, Windows::Media::Capture::ILowLagMediaRecording>
{
    HRESULT __stdcall abi_StartAsync(abi_arg_out<Windows::Foundation::IAsyncAction> operation) noexcept override
    {
        try
        {
            *operation = detach(this->shim().StartAsync());
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_StopAsync(abi_arg_out<Windows::Foundation::IAsyncAction> operation) noexcept override
    {
        try
        {
            *operation = detach(this->shim().StopAsync());
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_FinishAsync(abi_arg_out<Windows::Foundation::IAsyncAction> operation) noexcept override
    {
        try
        {
            *operation = detach(this->shim().FinishAsync());
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
struct produce<D, Windows::Media::Capture::ILowLagMediaRecording2> : produce_base<D, Windows::Media::Capture::ILowLagMediaRecording2>
{
    HRESULT __stdcall abi_PauseAsync(Windows::Media::Devices::MediaCapturePauseBehavior behavior, abi_arg_out<Windows::Foundation::IAsyncAction> operation) noexcept override
    {
        try
        {
            *operation = detach(this->shim().PauseAsync(behavior));
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_ResumeAsync(abi_arg_out<Windows::Foundation::IAsyncAction> operation) noexcept override
    {
        try
        {
            *operation = detach(this->shim().ResumeAsync());
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
struct produce<D, Windows::Media::Capture::ILowLagMediaRecording3> : produce_base<D, Windows::Media::Capture::ILowLagMediaRecording3>
{
    HRESULT __stdcall abi_PauseWithResultAsync(Windows::Media::Devices::MediaCapturePauseBehavior behavior, abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Media::Capture::MediaCapturePauseResult>> operation) noexcept override
    {
        try
        {
            *operation = detach(this->shim().PauseWithResultAsync(behavior));
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_StopWithResultAsync(abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Media::Capture::MediaCaptureStopResult>> operation) noexcept override
    {
        try
        {
            *operation = detach(this->shim().StopWithResultAsync());
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
struct produce<D, Windows::Media::Capture::ILowLagPhotoCapture> : produce_base<D, Windows::Media::Capture::ILowLagPhotoCapture>
{
    HRESULT __stdcall abi_CaptureAsync(abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Media::Capture::CapturedPhoto>> operation) noexcept override
    {
        try
        {
            *operation = detach(this->shim().CaptureAsync());
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_FinishAsync(abi_arg_out<Windows::Foundation::IAsyncAction> operation) noexcept override
    {
        try
        {
            *operation = detach(this->shim().FinishAsync());
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
struct produce<D, Windows::Media::Capture::ILowLagPhotoSequenceCapture> : produce_base<D, Windows::Media::Capture::ILowLagPhotoSequenceCapture>
{
    HRESULT __stdcall abi_StartAsync(abi_arg_out<Windows::Foundation::IAsyncAction> operation) noexcept override
    {
        try
        {
            *operation = detach(this->shim().StartAsync());
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_StopAsync(abi_arg_out<Windows::Foundation::IAsyncAction> operation) noexcept override
    {
        try
        {
            *operation = detach(this->shim().StopAsync());
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_FinishAsync(abi_arg_out<Windows::Foundation::IAsyncAction> operation) noexcept override
    {
        try
        {
            *operation = detach(this->shim().FinishAsync());
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_PhotoCaptured(abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::Media::Capture::LowLagPhotoSequenceCapture, Windows::Media::Capture::PhotoCapturedEventArgs>> handler, event_token * token) noexcept override
    {
        try
        {
            *token = detach(this->shim().PhotoCaptured(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::Media::Capture::LowLagPhotoSequenceCapture, Windows::Media::Capture::PhotoCapturedEventArgs> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_PhotoCaptured(event_token token) noexcept override
    {
        try
        {
            this->shim().PhotoCaptured(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Media::Capture::IMediaCapture> : produce_base<D, Windows::Media::Capture::IMediaCapture>
{
    HRESULT __stdcall abi_InitializeAsync(abi_arg_out<Windows::Foundation::IAsyncAction> asyncInfo) noexcept override
    {
        try
        {
            *asyncInfo = detach(this->shim().InitializeAsync());
            return S_OK;
        }
        catch (...)
        {
            *asyncInfo = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_InitializeWithSettingsAsync(abi_arg_in<Windows::Media::Capture::IMediaCaptureInitializationSettings> mediaCaptureInitializationSettings, abi_arg_out<Windows::Foundation::IAsyncAction> asyncInfo) noexcept override
    {
        try
        {
            *asyncInfo = detach(this->shim().InitializeAsync(*reinterpret_cast<const Windows::Media::Capture::MediaCaptureInitializationSettings *>(&mediaCaptureInitializationSettings)));
            return S_OK;
        }
        catch (...)
        {
            *asyncInfo = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_StartRecordToStorageFileAsync(abi_arg_in<Windows::Media::MediaProperties::IMediaEncodingProfile> encodingProfile, abi_arg_in<Windows::Storage::IStorageFile> file, abi_arg_out<Windows::Foundation::IAsyncAction> asyncInfo) noexcept override
    {
        try
        {
            *asyncInfo = detach(this->shim().StartRecordToStorageFileAsync(*reinterpret_cast<const Windows::Media::MediaProperties::MediaEncodingProfile *>(&encodingProfile), *reinterpret_cast<const Windows::Storage::IStorageFile *>(&file)));
            return S_OK;
        }
        catch (...)
        {
            *asyncInfo = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_StartRecordToStreamAsync(abi_arg_in<Windows::Media::MediaProperties::IMediaEncodingProfile> encodingProfile, abi_arg_in<Windows::Storage::Streams::IRandomAccessStream> stream, abi_arg_out<Windows::Foundation::IAsyncAction> asyncInfo) noexcept override
    {
        try
        {
            *asyncInfo = detach(this->shim().StartRecordToStreamAsync(*reinterpret_cast<const Windows::Media::MediaProperties::MediaEncodingProfile *>(&encodingProfile), *reinterpret_cast<const Windows::Storage::Streams::IRandomAccessStream *>(&stream)));
            return S_OK;
        }
        catch (...)
        {
            *asyncInfo = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_StartRecordToCustomSinkAsync(abi_arg_in<Windows::Media::MediaProperties::IMediaEncodingProfile> encodingProfile, abi_arg_in<Windows::Media::IMediaExtension> customMediaSink, abi_arg_out<Windows::Foundation::IAsyncAction> asyncInfo) noexcept override
    {
        try
        {
            *asyncInfo = detach(this->shim().StartRecordToCustomSinkAsync(*reinterpret_cast<const Windows::Media::MediaProperties::MediaEncodingProfile *>(&encodingProfile), *reinterpret_cast<const Windows::Media::IMediaExtension *>(&customMediaSink)));
            return S_OK;
        }
        catch (...)
        {
            *asyncInfo = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_StartRecordToCustomSinkIdAsync(abi_arg_in<Windows::Media::MediaProperties::IMediaEncodingProfile> encodingProfile, abi_arg_in<hstring> customSinkActivationId, abi_arg_in<Windows::Foundation::Collections::IPropertySet> customSinkSettings, abi_arg_out<Windows::Foundation::IAsyncAction> asyncInfo) noexcept override
    {
        try
        {
            *asyncInfo = detach(this->shim().StartRecordToCustomSinkAsync(*reinterpret_cast<const Windows::Media::MediaProperties::MediaEncodingProfile *>(&encodingProfile), *reinterpret_cast<const hstring *>(&customSinkActivationId), *reinterpret_cast<const Windows::Foundation::Collections::IPropertySet *>(&customSinkSettings)));
            return S_OK;
        }
        catch (...)
        {
            *asyncInfo = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_StopRecordAsync(abi_arg_out<Windows::Foundation::IAsyncAction> asyncInfo) noexcept override
    {
        try
        {
            *asyncInfo = detach(this->shim().StopRecordAsync());
            return S_OK;
        }
        catch (...)
        {
            *asyncInfo = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_CapturePhotoToStorageFileAsync(abi_arg_in<Windows::Media::MediaProperties::IImageEncodingProperties> type, abi_arg_in<Windows::Storage::IStorageFile> file, abi_arg_out<Windows::Foundation::IAsyncAction> asyncInfo) noexcept override
    {
        try
        {
            *asyncInfo = detach(this->shim().CapturePhotoToStorageFileAsync(*reinterpret_cast<const Windows::Media::MediaProperties::ImageEncodingProperties *>(&type), *reinterpret_cast<const Windows::Storage::IStorageFile *>(&file)));
            return S_OK;
        }
        catch (...)
        {
            *asyncInfo = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_CapturePhotoToStreamAsync(abi_arg_in<Windows::Media::MediaProperties::IImageEncodingProperties> type, abi_arg_in<Windows::Storage::Streams::IRandomAccessStream> stream, abi_arg_out<Windows::Foundation::IAsyncAction> asyncInfo) noexcept override
    {
        try
        {
            *asyncInfo = detach(this->shim().CapturePhotoToStreamAsync(*reinterpret_cast<const Windows::Media::MediaProperties::ImageEncodingProperties *>(&type), *reinterpret_cast<const Windows::Storage::Streams::IRandomAccessStream *>(&stream)));
            return S_OK;
        }
        catch (...)
        {
            *asyncInfo = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_AddEffectAsync(Windows::Media::Capture::MediaStreamType mediaStreamType, abi_arg_in<hstring> effectActivationID, abi_arg_in<Windows::Foundation::Collections::IPropertySet> effectSettings, abi_arg_out<Windows::Foundation::IAsyncAction> asyncInfo) noexcept override
    {
        try
        {
            *asyncInfo = detach(this->shim().AddEffectAsync(mediaStreamType, *reinterpret_cast<const hstring *>(&effectActivationID), *reinterpret_cast<const Windows::Foundation::Collections::IPropertySet *>(&effectSettings)));
            return S_OK;
        }
        catch (...)
        {
            *asyncInfo = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_ClearEffectsAsync(Windows::Media::Capture::MediaStreamType mediaStreamType, abi_arg_out<Windows::Foundation::IAsyncAction> asyncInfo) noexcept override
    {
        try
        {
            *asyncInfo = detach(this->shim().ClearEffectsAsync(mediaStreamType));
            return S_OK;
        }
        catch (...)
        {
            *asyncInfo = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_SetEncoderProperty(Windows::Media::Capture::MediaStreamType mediaStreamType, GUID propertyId, abi_arg_in<Windows::IInspectable> propertyValue) noexcept override
    {
        try
        {
            this->shim().SetEncoderProperty(mediaStreamType, propertyId, *reinterpret_cast<const Windows::IInspectable *>(&propertyValue));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetEncoderProperty(Windows::Media::Capture::MediaStreamType mediaStreamType, GUID propertyId, abi_arg_out<Windows::IInspectable> propertyValue) noexcept override
    {
        try
        {
            *propertyValue = detach(this->shim().GetEncoderProperty(mediaStreamType, propertyId));
            return S_OK;
        }
        catch (...)
        {
            *propertyValue = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_Failed(abi_arg_in<Windows::Media::Capture::MediaCaptureFailedEventHandler> errorEventHandler, event_token * eventCookie) noexcept override
    {
        try
        {
            *eventCookie = detach(this->shim().Failed(*reinterpret_cast<const Windows::Media::Capture::MediaCaptureFailedEventHandler *>(&errorEventHandler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_Failed(event_token eventCookie) noexcept override
    {
        try
        {
            this->shim().Failed(eventCookie);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_RecordLimitationExceeded(abi_arg_in<Windows::Media::Capture::RecordLimitationExceededEventHandler> recordLimitationExceededEventHandler, event_token * eventCookie) noexcept override
    {
        try
        {
            *eventCookie = detach(this->shim().RecordLimitationExceeded(*reinterpret_cast<const Windows::Media::Capture::RecordLimitationExceededEventHandler *>(&recordLimitationExceededEventHandler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_RecordLimitationExceeded(event_token eventCookie) noexcept override
    {
        try
        {
            this->shim().RecordLimitationExceeded(eventCookie);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_MediaCaptureSettings(abi_arg_out<Windows::Media::Capture::IMediaCaptureSettings> value) noexcept override
    {
        try
        {
            *value = detach(this->shim().MediaCaptureSettings());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_AudioDeviceController(abi_arg_out<Windows::Media::Devices::IAudioDeviceController> value) noexcept override
    {
        try
        {
            *value = detach(this->shim().AudioDeviceController());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_VideoDeviceController(abi_arg_out<Windows::Media::Devices::IVideoDeviceController> value) noexcept override
    {
        try
        {
            *value = detach(this->shim().VideoDeviceController());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_SetPreviewMirroring(bool value) noexcept override
    {
        try
        {
            this->shim().SetPreviewMirroring(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetPreviewMirroring(bool * value) noexcept override
    {
        try
        {
            *value = detach(this->shim().GetPreviewMirroring());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_SetPreviewRotation(Windows::Media::Capture::VideoRotation value) noexcept override
    {
        try
        {
            this->shim().SetPreviewRotation(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetPreviewRotation(Windows::Media::Capture::VideoRotation * value) noexcept override
    {
        try
        {
            *value = detach(this->shim().GetPreviewRotation());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_SetRecordRotation(Windows::Media::Capture::VideoRotation value) noexcept override
    {
        try
        {
            this->shim().SetRecordRotation(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetRecordRotation(Windows::Media::Capture::VideoRotation * value) noexcept override
    {
        try
        {
            *value = detach(this->shim().GetRecordRotation());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Media::Capture::IMediaCapture2> : produce_base<D, Windows::Media::Capture::IMediaCapture2>
{
    HRESULT __stdcall abi_PrepareLowLagRecordToStorageFileAsync(abi_arg_in<Windows::Media::MediaProperties::IMediaEncodingProfile> encodingProfile, abi_arg_in<Windows::Storage::IStorageFile> file, abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Media::Capture::LowLagMediaRecording>> operation) noexcept override
    {
        try
        {
            *operation = detach(this->shim().PrepareLowLagRecordToStorageFileAsync(*reinterpret_cast<const Windows::Media::MediaProperties::MediaEncodingProfile *>(&encodingProfile), *reinterpret_cast<const Windows::Storage::IStorageFile *>(&file)));
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_PrepareLowLagRecordToStreamAsync(abi_arg_in<Windows::Media::MediaProperties::IMediaEncodingProfile> encodingProfile, abi_arg_in<Windows::Storage::Streams::IRandomAccessStream> stream, abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Media::Capture::LowLagMediaRecording>> operation) noexcept override
    {
        try
        {
            *operation = detach(this->shim().PrepareLowLagRecordToStreamAsync(*reinterpret_cast<const Windows::Media::MediaProperties::MediaEncodingProfile *>(&encodingProfile), *reinterpret_cast<const Windows::Storage::Streams::IRandomAccessStream *>(&stream)));
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_PrepareLowLagRecordToCustomSinkAsync(abi_arg_in<Windows::Media::MediaProperties::IMediaEncodingProfile> encodingProfile, abi_arg_in<Windows::Media::IMediaExtension> customMediaSink, abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Media::Capture::LowLagMediaRecording>> operation) noexcept override
    {
        try
        {
            *operation = detach(this->shim().PrepareLowLagRecordToCustomSinkAsync(*reinterpret_cast<const Windows::Media::MediaProperties::MediaEncodingProfile *>(&encodingProfile), *reinterpret_cast<const Windows::Media::IMediaExtension *>(&customMediaSink)));
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_PrepareLowLagRecordToCustomSinkIdAsync(abi_arg_in<Windows::Media::MediaProperties::IMediaEncodingProfile> encodingProfile, abi_arg_in<hstring> customSinkActivationId, abi_arg_in<Windows::Foundation::Collections::IPropertySet> customSinkSettings, abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Media::Capture::LowLagMediaRecording>> operation) noexcept override
    {
        try
        {
            *operation = detach(this->shim().PrepareLowLagRecordToCustomSinkAsync(*reinterpret_cast<const Windows::Media::MediaProperties::MediaEncodingProfile *>(&encodingProfile), *reinterpret_cast<const hstring *>(&customSinkActivationId), *reinterpret_cast<const Windows::Foundation::Collections::IPropertySet *>(&customSinkSettings)));
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_PrepareLowLagPhotoCaptureAsync(abi_arg_in<Windows::Media::MediaProperties::IImageEncodingProperties> type, abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Media::Capture::LowLagPhotoCapture>> operation) noexcept override
    {
        try
        {
            *operation = detach(this->shim().PrepareLowLagPhotoCaptureAsync(*reinterpret_cast<const Windows::Media::MediaProperties::ImageEncodingProperties *>(&type)));
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_PrepareLowLagPhotoSequenceCaptureAsync(abi_arg_in<Windows::Media::MediaProperties::IImageEncodingProperties> type, abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Media::Capture::LowLagPhotoSequenceCapture>> operation) noexcept override
    {
        try
        {
            *operation = detach(this->shim().PrepareLowLagPhotoSequenceCaptureAsync(*reinterpret_cast<const Windows::Media::MediaProperties::ImageEncodingProperties *>(&type)));
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_SetEncodingPropertiesAsync(Windows::Media::Capture::MediaStreamType mediaStreamType, abi_arg_in<Windows::Media::MediaProperties::IMediaEncodingProperties> mediaEncodingProperties, abi_arg_in<Windows::Foundation::Collections::IMap<GUID, Windows::IInspectable>> encoderProperties, abi_arg_out<Windows::Foundation::IAsyncAction> operation) noexcept override
    {
        try
        {
            *operation = detach(this->shim().SetEncodingPropertiesAsync(mediaStreamType, *reinterpret_cast<const Windows::Media::MediaProperties::IMediaEncodingProperties *>(&mediaEncodingProperties), *reinterpret_cast<const Windows::Media::MediaProperties::MediaPropertySet *>(&encoderProperties)));
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
struct produce<D, Windows::Media::Capture::IMediaCapture3> : produce_base<D, Windows::Media::Capture::IMediaCapture3>
{
    HRESULT __stdcall abi_PrepareVariablePhotoSequenceCaptureAsync(abi_arg_in<Windows::Media::MediaProperties::IImageEncodingProperties> type, abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Media::Capture::Core::VariablePhotoSequenceCapture>> operation) noexcept override
    {
        try
        {
            *operation = detach(this->shim().PrepareVariablePhotoSequenceCaptureAsync(*reinterpret_cast<const Windows::Media::MediaProperties::ImageEncodingProperties *>(&type)));
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_FocusChanged(abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::Media::Capture::MediaCapture, Windows::Media::Capture::MediaCaptureFocusChangedEventArgs>> handler, event_token * token) noexcept override
    {
        try
        {
            *token = detach(this->shim().FocusChanged(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::Media::Capture::MediaCapture, Windows::Media::Capture::MediaCaptureFocusChangedEventArgs> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_FocusChanged(event_token token) noexcept override
    {
        try
        {
            this->shim().FocusChanged(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_PhotoConfirmationCaptured(abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::Media::Capture::MediaCapture, Windows::Media::Capture::PhotoConfirmationCapturedEventArgs>> handler, event_token * token) noexcept override
    {
        try
        {
            *token = detach(this->shim().PhotoConfirmationCaptured(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::Media::Capture::MediaCapture, Windows::Media::Capture::PhotoConfirmationCapturedEventArgs> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_PhotoConfirmationCaptured(event_token token) noexcept override
    {
        try
        {
            this->shim().PhotoConfirmationCaptured(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Media::Capture::IMediaCapture4> : produce_base<D, Windows::Media::Capture::IMediaCapture4>
{
    HRESULT __stdcall abi_AddAudioEffectAsync(abi_arg_in<Windows::Media::Effects::IAudioEffectDefinition> definition, abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Media::IMediaExtension>> op) noexcept override
    {
        try
        {
            *op = detach(this->shim().AddAudioEffectAsync(*reinterpret_cast<const Windows::Media::Effects::IAudioEffectDefinition *>(&definition)));
            return S_OK;
        }
        catch (...)
        {
            *op = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_AddVideoEffectAsync(abi_arg_in<Windows::Media::Effects::IVideoEffectDefinition> definition, Windows::Media::Capture::MediaStreamType mediaStreamType, abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Media::IMediaExtension>> op) noexcept override
    {
        try
        {
            *op = detach(this->shim().AddVideoEffectAsync(*reinterpret_cast<const Windows::Media::Effects::IVideoEffectDefinition *>(&definition), mediaStreamType));
            return S_OK;
        }
        catch (...)
        {
            *op = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_PauseRecordAsync(Windows::Media::Devices::MediaCapturePauseBehavior behavior, abi_arg_out<Windows::Foundation::IAsyncAction> asyncInfo) noexcept override
    {
        try
        {
            *asyncInfo = detach(this->shim().PauseRecordAsync(behavior));
            return S_OK;
        }
        catch (...)
        {
            *asyncInfo = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_ResumeRecordAsync(abi_arg_out<Windows::Foundation::IAsyncAction> asyncInfo) noexcept override
    {
        try
        {
            *asyncInfo = detach(this->shim().ResumeRecordAsync());
            return S_OK;
        }
        catch (...)
        {
            *asyncInfo = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_CameraStreamStateChanged(abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::Media::Capture::MediaCapture, Windows::IInspectable>> handler, event_token * token) noexcept override
    {
        try
        {
            *token = detach(this->shim().CameraStreamStateChanged(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::Media::Capture::MediaCapture, Windows::IInspectable> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_CameraStreamStateChanged(event_token token) noexcept override
    {
        try
        {
            this->shim().CameraStreamStateChanged(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_CameraStreamState(Windows::Media::Devices::CameraStreamState * streamState) noexcept override
    {
        try
        {
            *streamState = detach(this->shim().CameraStreamState());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetPreviewFrameAsync(abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Media::VideoFrame>> operation) noexcept override
    {
        try
        {
            *operation = detach(this->shim().GetPreviewFrameAsync());
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetPreviewFrameCopyAsync(abi_arg_in<Windows::Media::IVideoFrame> destination, abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Media::VideoFrame>> operation) noexcept override
    {
        try
        {
            *operation = detach(this->shim().GetPreviewFrameAsync(*reinterpret_cast<const Windows::Media::VideoFrame *>(&destination)));
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_ThermalStatusChanged(abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::Media::Capture::MediaCapture, Windows::IInspectable>> handler, event_token * token) noexcept override
    {
        try
        {
            *token = detach(this->shim().ThermalStatusChanged(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::Media::Capture::MediaCapture, Windows::IInspectable> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_ThermalStatusChanged(event_token token) noexcept override
    {
        try
        {
            this->shim().ThermalStatusChanged(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ThermalStatus(Windows::Media::Capture::MediaCaptureThermalStatus * value) noexcept override
    {
        try
        {
            *value = detach(this->shim().ThermalStatus());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_PrepareAdvancedPhotoCaptureAsync(abi_arg_in<Windows::Media::MediaProperties::IImageEncodingProperties> encodingProperties, abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Media::Capture::AdvancedPhotoCapture>> operation) noexcept override
    {
        try
        {
            *operation = detach(this->shim().PrepareAdvancedPhotoCaptureAsync(*reinterpret_cast<const Windows::Media::MediaProperties::ImageEncodingProperties *>(&encodingProperties)));
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
struct produce<D, Windows::Media::Capture::IMediaCapture5> : produce_base<D, Windows::Media::Capture::IMediaCapture5>
{
    HRESULT __stdcall abi_RemoveEffectAsync(abi_arg_in<Windows::Media::IMediaExtension> effect, abi_arg_out<Windows::Foundation::IAsyncAction> asyncInfo) noexcept override
    {
        try
        {
            *asyncInfo = detach(this->shim().RemoveEffectAsync(*reinterpret_cast<const Windows::Media::IMediaExtension *>(&effect)));
            return S_OK;
        }
        catch (...)
        {
            *asyncInfo = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_PauseRecordWithResultAsync(Windows::Media::Devices::MediaCapturePauseBehavior behavior, abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Media::Capture::MediaCapturePauseResult>> operation) noexcept override
    {
        try
        {
            *operation = detach(this->shim().PauseRecordWithResultAsync(behavior));
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_StopRecordWithResultAsync(abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Media::Capture::MediaCaptureStopResult>> operation) noexcept override
    {
        try
        {
            *operation = detach(this->shim().StopRecordWithResultAsync());
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_FrameSources(abi_arg_out<Windows::Foundation::Collections::IMapView<hstring, Windows::Media::Capture::Frames::MediaFrameSource>> value) noexcept override
    {
        try
        {
            *value = detach(this->shim().FrameSources());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_CreateFrameReaderAsync(abi_arg_in<Windows::Media::Capture::Frames::IMediaFrameSource> inputSource, abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Media::Capture::Frames::MediaFrameReader>> value) noexcept override
    {
        try
        {
            *value = detach(this->shim().CreateFrameReaderAsync(*reinterpret_cast<const Windows::Media::Capture::Frames::MediaFrameSource *>(&inputSource)));
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_CreateFrameReaderWithSubtypeAsync(abi_arg_in<Windows::Media::Capture::Frames::IMediaFrameSource> inputSource, abi_arg_in<hstring> outputSubtype, abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Media::Capture::Frames::MediaFrameReader>> value) noexcept override
    {
        try
        {
            *value = detach(this->shim().CreateFrameReaderAsync(*reinterpret_cast<const Windows::Media::Capture::Frames::MediaFrameSource *>(&inputSource), *reinterpret_cast<const hstring *>(&outputSubtype)));
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_CreateFrameReaderWithSubtypeAndSizeAsync(abi_arg_in<Windows::Media::Capture::Frames::IMediaFrameSource> inputSource, abi_arg_in<hstring> outputSubtype, abi_arg_in<Windows::Graphics::Imaging::BitmapSize> outputSize, abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Media::Capture::Frames::MediaFrameReader>> value) noexcept override
    {
        try
        {
            *value = detach(this->shim().CreateFrameReaderAsync(*reinterpret_cast<const Windows::Media::Capture::Frames::MediaFrameSource *>(&inputSource), *reinterpret_cast<const hstring *>(&outputSubtype), *reinterpret_cast<const Windows::Graphics::Imaging::BitmapSize *>(&outputSize)));
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
struct produce<D, Windows::Media::Capture::IMediaCaptureFailedEventArgs> : produce_base<D, Windows::Media::Capture::IMediaCaptureFailedEventArgs>
{
    HRESULT __stdcall get_Message(abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            *value = detach(this->shim().Message());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Code(uint32_t * value) noexcept override
    {
        try
        {
            *value = detach(this->shim().Code());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Media::Capture::IMediaCaptureFocusChangedEventArgs> : produce_base<D, Windows::Media::Capture::IMediaCaptureFocusChangedEventArgs>
{
    HRESULT __stdcall get_FocusState(Windows::Media::Devices::MediaCaptureFocusState * value) noexcept override
    {
        try
        {
            *value = detach(this->shim().FocusState());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Media::Capture::IMediaCaptureInitializationSettings> : produce_base<D, Windows::Media::Capture::IMediaCaptureInitializationSettings>
{
    HRESULT __stdcall put_AudioDeviceId(abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            this->shim().AudioDeviceId(*reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_AudioDeviceId(abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            *value = detach(this->shim().AudioDeviceId());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_VideoDeviceId(abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            this->shim().VideoDeviceId(*reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_VideoDeviceId(abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            *value = detach(this->shim().VideoDeviceId());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_StreamingCaptureMode(Windows::Media::Capture::StreamingCaptureMode value) noexcept override
    {
        try
        {
            this->shim().StreamingCaptureMode(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_StreamingCaptureMode(Windows::Media::Capture::StreamingCaptureMode * value) noexcept override
    {
        try
        {
            *value = detach(this->shim().StreamingCaptureMode());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_PhotoCaptureSource(Windows::Media::Capture::PhotoCaptureSource value) noexcept override
    {
        try
        {
            this->shim().PhotoCaptureSource(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_PhotoCaptureSource(Windows::Media::Capture::PhotoCaptureSource * value) noexcept override
    {
        try
        {
            *value = detach(this->shim().PhotoCaptureSource());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Media::Capture::IMediaCaptureInitializationSettings2> : produce_base<D, Windows::Media::Capture::IMediaCaptureInitializationSettings2>
{
    HRESULT __stdcall put_MediaCategory(Windows::Media::Capture::MediaCategory value) noexcept override
    {
        try
        {
            this->shim().MediaCategory(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_MediaCategory(Windows::Media::Capture::MediaCategory * value) noexcept override
    {
        try
        {
            *value = detach(this->shim().MediaCategory());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_AudioProcessing(Windows::Media::AudioProcessing value) noexcept override
    {
        try
        {
            this->shim().AudioProcessing(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_AudioProcessing(Windows::Media::AudioProcessing * value) noexcept override
    {
        try
        {
            *value = detach(this->shim().AudioProcessing());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Media::Capture::IMediaCaptureInitializationSettings3> : produce_base<D, Windows::Media::Capture::IMediaCaptureInitializationSettings3>
{
    HRESULT __stdcall put_AudioSource(abi_arg_in<Windows::Media::Core::IMediaSource> value) noexcept override
    {
        try
        {
            this->shim().AudioSource(*reinterpret_cast<const Windows::Media::Core::IMediaSource *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_AudioSource(abi_arg_out<Windows::Media::Core::IMediaSource> value) noexcept override
    {
        try
        {
            *value = detach(this->shim().AudioSource());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_VideoSource(abi_arg_in<Windows::Media::Core::IMediaSource> value) noexcept override
    {
        try
        {
            this->shim().VideoSource(*reinterpret_cast<const Windows::Media::Core::IMediaSource *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_VideoSource(abi_arg_out<Windows::Media::Core::IMediaSource> value) noexcept override
    {
        try
        {
            *value = detach(this->shim().VideoSource());
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
struct produce<D, Windows::Media::Capture::IMediaCaptureInitializationSettings4> : produce_base<D, Windows::Media::Capture::IMediaCaptureInitializationSettings4>
{
    HRESULT __stdcall get_VideoProfile(abi_arg_out<Windows::Media::Capture::IMediaCaptureVideoProfile> value) noexcept override
    {
        try
        {
            *value = detach(this->shim().VideoProfile());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_VideoProfile(abi_arg_in<Windows::Media::Capture::IMediaCaptureVideoProfile> value) noexcept override
    {
        try
        {
            this->shim().VideoProfile(*reinterpret_cast<const Windows::Media::Capture::MediaCaptureVideoProfile *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_PreviewMediaDescription(abi_arg_out<Windows::Media::Capture::IMediaCaptureVideoProfileMediaDescription> value) noexcept override
    {
        try
        {
            *value = detach(this->shim().PreviewMediaDescription());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_PreviewMediaDescription(abi_arg_in<Windows::Media::Capture::IMediaCaptureVideoProfileMediaDescription> value) noexcept override
    {
        try
        {
            this->shim().PreviewMediaDescription(*reinterpret_cast<const Windows::Media::Capture::MediaCaptureVideoProfileMediaDescription *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_RecordMediaDescription(abi_arg_out<Windows::Media::Capture::IMediaCaptureVideoProfileMediaDescription> value) noexcept override
    {
        try
        {
            *value = detach(this->shim().RecordMediaDescription());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_RecordMediaDescription(abi_arg_in<Windows::Media::Capture::IMediaCaptureVideoProfileMediaDescription> value) noexcept override
    {
        try
        {
            this->shim().RecordMediaDescription(*reinterpret_cast<const Windows::Media::Capture::MediaCaptureVideoProfileMediaDescription *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_PhotoMediaDescription(abi_arg_out<Windows::Media::Capture::IMediaCaptureVideoProfileMediaDescription> value) noexcept override
    {
        try
        {
            *value = detach(this->shim().PhotoMediaDescription());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_PhotoMediaDescription(abi_arg_in<Windows::Media::Capture::IMediaCaptureVideoProfileMediaDescription> value) noexcept override
    {
        try
        {
            this->shim().PhotoMediaDescription(*reinterpret_cast<const Windows::Media::Capture::MediaCaptureVideoProfileMediaDescription *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Media::Capture::IMediaCaptureInitializationSettings5> : produce_base<D, Windows::Media::Capture::IMediaCaptureInitializationSettings5>
{
    HRESULT __stdcall get_SourceGroup(abi_arg_out<Windows::Media::Capture::Frames::IMediaFrameSourceGroup> value) noexcept override
    {
        try
        {
            *value = detach(this->shim().SourceGroup());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_SourceGroup(abi_arg_in<Windows::Media::Capture::Frames::IMediaFrameSourceGroup> value) noexcept override
    {
        try
        {
            this->shim().SourceGroup(*reinterpret_cast<const Windows::Media::Capture::Frames::MediaFrameSourceGroup *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_SharingMode(Windows::Media::Capture::MediaCaptureSharingMode * value) noexcept override
    {
        try
        {
            *value = detach(this->shim().SharingMode());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_SharingMode(Windows::Media::Capture::MediaCaptureSharingMode value) noexcept override
    {
        try
        {
            this->shim().SharingMode(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_MemoryPreference(Windows::Media::Capture::MediaCaptureMemoryPreference * value) noexcept override
    {
        try
        {
            *value = detach(this->shim().MemoryPreference());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_MemoryPreference(Windows::Media::Capture::MediaCaptureMemoryPreference value) noexcept override
    {
        try
        {
            this->shim().MemoryPreference(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Media::Capture::IMediaCapturePauseResult> : produce_base<D, Windows::Media::Capture::IMediaCapturePauseResult>
{
    HRESULT __stdcall get_LastFrame(abi_arg_out<Windows::Media::IVideoFrame> value) noexcept override
    {
        try
        {
            *value = detach(this->shim().LastFrame());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_RecordDuration(abi_arg_out<Windows::Foundation::TimeSpan> value) noexcept override
    {
        try
        {
            *value = detach(this->shim().RecordDuration());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Media::Capture::IMediaCaptureSettings> : produce_base<D, Windows::Media::Capture::IMediaCaptureSettings>
{
    HRESULT __stdcall get_AudioDeviceId(abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            *value = detach(this->shim().AudioDeviceId());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_VideoDeviceId(abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            *value = detach(this->shim().VideoDeviceId());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_StreamingCaptureMode(Windows::Media::Capture::StreamingCaptureMode * value) noexcept override
    {
        try
        {
            *value = detach(this->shim().StreamingCaptureMode());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_PhotoCaptureSource(Windows::Media::Capture::PhotoCaptureSource * value) noexcept override
    {
        try
        {
            *value = detach(this->shim().PhotoCaptureSource());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_VideoDeviceCharacteristic(Windows::Media::Capture::VideoDeviceCharacteristic * value) noexcept override
    {
        try
        {
            *value = detach(this->shim().VideoDeviceCharacteristic());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Media::Capture::IMediaCaptureSettings2> : produce_base<D, Windows::Media::Capture::IMediaCaptureSettings2>
{
    HRESULT __stdcall get_ConcurrentRecordAndPhotoSupported(bool * value) noexcept override
    {
        try
        {
            *value = detach(this->shim().ConcurrentRecordAndPhotoSupported());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ConcurrentRecordAndPhotoSequenceSupported(bool * value) noexcept override
    {
        try
        {
            *value = detach(this->shim().ConcurrentRecordAndPhotoSequenceSupported());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_CameraSoundRequiredForRegion(bool * value) noexcept override
    {
        try
        {
            *value = detach(this->shim().CameraSoundRequiredForRegion());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Horizontal35mmEquivalentFocalLength(abi_arg_out<Windows::Foundation::IReference<uint32_t>> value) noexcept override
    {
        try
        {
            *value = detach(this->shim().Horizontal35mmEquivalentFocalLength());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_PitchOffsetDegrees(abi_arg_out<Windows::Foundation::IReference<int32_t>> value) noexcept override
    {
        try
        {
            *value = detach(this->shim().PitchOffsetDegrees());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Vertical35mmEquivalentFocalLength(abi_arg_out<Windows::Foundation::IReference<uint32_t>> value) noexcept override
    {
        try
        {
            *value = detach(this->shim().Vertical35mmEquivalentFocalLength());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_MediaCategory(Windows::Media::Capture::MediaCategory * value) noexcept override
    {
        try
        {
            *value = detach(this->shim().MediaCategory());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_AudioProcessing(Windows::Media::AudioProcessing * value) noexcept override
    {
        try
        {
            *value = detach(this->shim().AudioProcessing());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Media::Capture::IMediaCaptureStatics> : produce_base<D, Windows::Media::Capture::IMediaCaptureStatics>
{
    HRESULT __stdcall abi_IsVideoProfileSupported(abi_arg_in<hstring> videoDeviceId, bool * value) noexcept override
    {
        try
        {
            *value = detach(this->shim().IsVideoProfileSupported(*reinterpret_cast<const hstring *>(&videoDeviceId)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_FindAllVideoProfiles(abi_arg_in<hstring> videoDeviceId, abi_arg_out<Windows::Foundation::Collections::IVectorView<Windows::Media::Capture::MediaCaptureVideoProfile>> value) noexcept override
    {
        try
        {
            *value = detach(this->shim().FindAllVideoProfiles(*reinterpret_cast<const hstring *>(&videoDeviceId)));
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_FindConcurrentProfiles(abi_arg_in<hstring> videoDeviceId, abi_arg_out<Windows::Foundation::Collections::IVectorView<Windows::Media::Capture::MediaCaptureVideoProfile>> value) noexcept override
    {
        try
        {
            *value = detach(this->shim().FindConcurrentProfiles(*reinterpret_cast<const hstring *>(&videoDeviceId)));
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_FindKnownVideoProfiles(abi_arg_in<hstring> videoDeviceId, Windows::Media::Capture::KnownVideoProfile name, abi_arg_out<Windows::Foundation::Collections::IVectorView<Windows::Media::Capture::MediaCaptureVideoProfile>> value) noexcept override
    {
        try
        {
            *value = detach(this->shim().FindKnownVideoProfiles(*reinterpret_cast<const hstring *>(&videoDeviceId), name));
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
struct produce<D, Windows::Media::Capture::IMediaCaptureStopResult> : produce_base<D, Windows::Media::Capture::IMediaCaptureStopResult>
{
    HRESULT __stdcall get_LastFrame(abi_arg_out<Windows::Media::IVideoFrame> value) noexcept override
    {
        try
        {
            *value = detach(this->shim().LastFrame());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_RecordDuration(abi_arg_out<Windows::Foundation::TimeSpan> value) noexcept override
    {
        try
        {
            *value = detach(this->shim().RecordDuration());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Media::Capture::IMediaCaptureVideoPreview> : produce_base<D, Windows::Media::Capture::IMediaCaptureVideoPreview>
{
    HRESULT __stdcall abi_StartPreviewAsync(abi_arg_out<Windows::Foundation::IAsyncAction> asyncInfo) noexcept override
    {
        try
        {
            *asyncInfo = detach(this->shim().StartPreviewAsync());
            return S_OK;
        }
        catch (...)
        {
            *asyncInfo = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_StartPreviewToCustomSinkAsync(abi_arg_in<Windows::Media::MediaProperties::IMediaEncodingProfile> encodingProfile, abi_arg_in<Windows::Media::IMediaExtension> customMediaSink, abi_arg_out<Windows::Foundation::IAsyncAction> asyncInfo) noexcept override
    {
        try
        {
            *asyncInfo = detach(this->shim().StartPreviewToCustomSinkAsync(*reinterpret_cast<const Windows::Media::MediaProperties::MediaEncodingProfile *>(&encodingProfile), *reinterpret_cast<const Windows::Media::IMediaExtension *>(&customMediaSink)));
            return S_OK;
        }
        catch (...)
        {
            *asyncInfo = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_StartPreviewToCustomSinkIdAsync(abi_arg_in<Windows::Media::MediaProperties::IMediaEncodingProfile> encodingProfile, abi_arg_in<hstring> customSinkActivationId, abi_arg_in<Windows::Foundation::Collections::IPropertySet> customSinkSettings, abi_arg_out<Windows::Foundation::IAsyncAction> asyncInfo) noexcept override
    {
        try
        {
            *asyncInfo = detach(this->shim().StartPreviewToCustomSinkAsync(*reinterpret_cast<const Windows::Media::MediaProperties::MediaEncodingProfile *>(&encodingProfile), *reinterpret_cast<const hstring *>(&customSinkActivationId), *reinterpret_cast<const Windows::Foundation::Collections::IPropertySet *>(&customSinkSettings)));
            return S_OK;
        }
        catch (...)
        {
            *asyncInfo = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_StopPreviewAsync(abi_arg_out<Windows::Foundation::IAsyncAction> asyncInfo) noexcept override
    {
        try
        {
            *asyncInfo = detach(this->shim().StopPreviewAsync());
            return S_OK;
        }
        catch (...)
        {
            *asyncInfo = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Media::Capture::IMediaCaptureVideoProfile> : produce_base<D, Windows::Media::Capture::IMediaCaptureVideoProfile>
{
    HRESULT __stdcall get_Id(abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            *value = detach(this->shim().Id());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_VideoDeviceId(abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            *value = detach(this->shim().VideoDeviceId());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_SupportedPreviewMediaDescription(abi_arg_out<Windows::Foundation::Collections::IVectorView<Windows::Media::Capture::MediaCaptureVideoProfileMediaDescription>> value) noexcept override
    {
        try
        {
            *value = detach(this->shim().SupportedPreviewMediaDescription());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_SupportedRecordMediaDescription(abi_arg_out<Windows::Foundation::Collections::IVectorView<Windows::Media::Capture::MediaCaptureVideoProfileMediaDescription>> value) noexcept override
    {
        try
        {
            *value = detach(this->shim().SupportedRecordMediaDescription());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_SupportedPhotoMediaDescription(abi_arg_out<Windows::Foundation::Collections::IVectorView<Windows::Media::Capture::MediaCaptureVideoProfileMediaDescription>> value) noexcept override
    {
        try
        {
            *value = detach(this->shim().SupportedPhotoMediaDescription());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetConcurrency(abi_arg_out<Windows::Foundation::Collections::IVectorView<Windows::Media::Capture::MediaCaptureVideoProfile>> value) noexcept override
    {
        try
        {
            *value = detach(this->shim().GetConcurrency());
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
struct produce<D, Windows::Media::Capture::IMediaCaptureVideoProfileMediaDescription> : produce_base<D, Windows::Media::Capture::IMediaCaptureVideoProfileMediaDescription>
{
    HRESULT __stdcall get_Width(uint32_t * value) noexcept override
    {
        try
        {
            *value = detach(this->shim().Width());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Height(uint32_t * value) noexcept override
    {
        try
        {
            *value = detach(this->shim().Height());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_FrameRate(double * value) noexcept override
    {
        try
        {
            *value = detach(this->shim().FrameRate());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_IsVariablePhotoSequenceSupported(bool * value) noexcept override
    {
        try
        {
            *value = detach(this->shim().IsVariablePhotoSequenceSupported());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_IsHdrVideoSupported(bool * value) noexcept override
    {
        try
        {
            *value = detach(this->shim().IsHdrVideoSupported());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Media::Capture::IOptionalReferencePhotoCapturedEventArgs> : produce_base<D, Windows::Media::Capture::IOptionalReferencePhotoCapturedEventArgs>
{
    HRESULT __stdcall get_Frame(abi_arg_out<Windows::Media::Capture::ICapturedFrame> value) noexcept override
    {
        try
        {
            *value = detach(this->shim().Frame());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Context(abi_arg_out<Windows::IInspectable> value) noexcept override
    {
        try
        {
            *value = detach(this->shim().Context());
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
struct produce<D, Windows::Media::Capture::IPhotoCapturedEventArgs> : produce_base<D, Windows::Media::Capture::IPhotoCapturedEventArgs>
{
    HRESULT __stdcall get_Frame(abi_arg_out<Windows::Media::Capture::ICapturedFrame> value) noexcept override
    {
        try
        {
            *value = detach(this->shim().Frame());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Thumbnail(abi_arg_out<Windows::Media::Capture::ICapturedFrame> value) noexcept override
    {
        try
        {
            *value = detach(this->shim().Thumbnail());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_CaptureTimeOffset(abi_arg_out<Windows::Foundation::TimeSpan> value) noexcept override
    {
        try
        {
            *value = detach(this->shim().CaptureTimeOffset());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Media::Capture::IPhotoConfirmationCapturedEventArgs> : produce_base<D, Windows::Media::Capture::IPhotoConfirmationCapturedEventArgs>
{
    HRESULT __stdcall get_Frame(abi_arg_out<Windows::Media::Capture::ICapturedFrame> value) noexcept override
    {
        try
        {
            *value = detach(this->shim().Frame());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_CaptureTimeOffset(abi_arg_out<Windows::Foundation::TimeSpan> value) noexcept override
    {
        try
        {
            *value = detach(this->shim().CaptureTimeOffset());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Media::Capture::IVideoStreamConfiguration> : produce_base<D, Windows::Media::Capture::IVideoStreamConfiguration>
{
    HRESULT __stdcall get_InputProperties(abi_arg_out<Windows::Media::MediaProperties::IVideoEncodingProperties> value) noexcept override
    {
        try
        {
            *value = detach(this->shim().InputProperties());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_OutputProperties(abi_arg_out<Windows::Media::MediaProperties::IVideoEncodingProperties> value) noexcept override
    {
        try
        {
            *value = detach(this->shim().OutputProperties());
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

namespace Windows::Media::Capture {

template <typename D> bool impl_IAppCapture<D>::IsCapturingAudio() const
{
    bool value {};
    check_hresult(shim()->get_IsCapturingAudio(&value));
    return value;
}

template <typename D> bool impl_IAppCapture<D>::IsCapturingVideo() const
{
    bool value {};
    check_hresult(shim()->get_IsCapturingVideo(&value));
    return value;
}

template <typename D> event_token impl_IAppCapture<D>::CapturingChanged(const Windows::Foundation::TypedEventHandler<Windows::Media::Capture::AppCapture, Windows::IInspectable> & handler) const
{
    event_token token {};
    check_hresult(shim()->add_CapturingChanged(get(handler), &token));
    return token;
}

template <typename D> event_revoker<IAppCapture> impl_IAppCapture<D>::CapturingChanged(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Media::Capture::AppCapture, Windows::IInspectable> & handler) const
{
    return impl::make_event_revoker<D, IAppCapture>(this, &ABI::Windows::Media::Capture::IAppCapture::remove_CapturingChanged, CapturingChanged(handler));
}

template <typename D> void impl_IAppCapture<D>::CapturingChanged(event_token token) const
{
    check_hresult(shim()->remove_CapturingChanged(token));
}

template <typename D> Windows::Media::Capture::AppCapture impl_IAppCaptureStatics<D>::GetForCurrentView() const
{
    Windows::Media::Capture::AppCapture value { nullptr };
    check_hresult(shim()->abi_GetForCurrentView(put(value)));
    return value;
}

template <typename D> Windows::Media::Capture::CameraCaptureUIPhotoFormat impl_ICameraCaptureUIPhotoCaptureSettings<D>::Format() const
{
    Windows::Media::Capture::CameraCaptureUIPhotoFormat value {};
    check_hresult(shim()->get_Format(&value));
    return value;
}

template <typename D> void impl_ICameraCaptureUIPhotoCaptureSettings<D>::Format(Windows::Media::Capture::CameraCaptureUIPhotoFormat value) const
{
    check_hresult(shim()->put_Format(value));
}

template <typename D> Windows::Media::Capture::CameraCaptureUIMaxPhotoResolution impl_ICameraCaptureUIPhotoCaptureSettings<D>::MaxResolution() const
{
    Windows::Media::Capture::CameraCaptureUIMaxPhotoResolution value {};
    check_hresult(shim()->get_MaxResolution(&value));
    return value;
}

template <typename D> void impl_ICameraCaptureUIPhotoCaptureSettings<D>::MaxResolution(Windows::Media::Capture::CameraCaptureUIMaxPhotoResolution value) const
{
    check_hresult(shim()->put_MaxResolution(value));
}

template <typename D> Windows::Foundation::Size impl_ICameraCaptureUIPhotoCaptureSettings<D>::CroppedSizeInPixels() const
{
    Windows::Foundation::Size value {};
    check_hresult(shim()->get_CroppedSizeInPixels(put(value)));
    return value;
}

template <typename D> void impl_ICameraCaptureUIPhotoCaptureSettings<D>::CroppedSizeInPixels(const Windows::Foundation::Size & value) const
{
    check_hresult(shim()->put_CroppedSizeInPixels(get(value)));
}

template <typename D> Windows::Foundation::Size impl_ICameraCaptureUIPhotoCaptureSettings<D>::CroppedAspectRatio() const
{
    Windows::Foundation::Size value {};
    check_hresult(shim()->get_CroppedAspectRatio(put(value)));
    return value;
}

template <typename D> void impl_ICameraCaptureUIPhotoCaptureSettings<D>::CroppedAspectRatio(const Windows::Foundation::Size & value) const
{
    check_hresult(shim()->put_CroppedAspectRatio(get(value)));
}

template <typename D> bool impl_ICameraCaptureUIPhotoCaptureSettings<D>::AllowCropping() const
{
    bool value {};
    check_hresult(shim()->get_AllowCropping(&value));
    return value;
}

template <typename D> void impl_ICameraCaptureUIPhotoCaptureSettings<D>::AllowCropping(bool value) const
{
    check_hresult(shim()->put_AllowCropping(value));
}

template <typename D> Windows::Media::Capture::CameraCaptureUIVideoFormat impl_ICameraCaptureUIVideoCaptureSettings<D>::Format() const
{
    Windows::Media::Capture::CameraCaptureUIVideoFormat value {};
    check_hresult(shim()->get_Format(&value));
    return value;
}

template <typename D> void impl_ICameraCaptureUIVideoCaptureSettings<D>::Format(Windows::Media::Capture::CameraCaptureUIVideoFormat value) const
{
    check_hresult(shim()->put_Format(value));
}

template <typename D> Windows::Media::Capture::CameraCaptureUIMaxVideoResolution impl_ICameraCaptureUIVideoCaptureSettings<D>::MaxResolution() const
{
    Windows::Media::Capture::CameraCaptureUIMaxVideoResolution value {};
    check_hresult(shim()->get_MaxResolution(&value));
    return value;
}

template <typename D> void impl_ICameraCaptureUIVideoCaptureSettings<D>::MaxResolution(Windows::Media::Capture::CameraCaptureUIMaxVideoResolution value) const
{
    check_hresult(shim()->put_MaxResolution(value));
}

template <typename D> float impl_ICameraCaptureUIVideoCaptureSettings<D>::MaxDurationInSeconds() const
{
    float value {};
    check_hresult(shim()->get_MaxDurationInSeconds(&value));
    return value;
}

template <typename D> void impl_ICameraCaptureUIVideoCaptureSettings<D>::MaxDurationInSeconds(float value) const
{
    check_hresult(shim()->put_MaxDurationInSeconds(value));
}

template <typename D> bool impl_ICameraCaptureUIVideoCaptureSettings<D>::AllowTrimming() const
{
    bool value {};
    check_hresult(shim()->get_AllowTrimming(&value));
    return value;
}

template <typename D> void impl_ICameraCaptureUIVideoCaptureSettings<D>::AllowTrimming(bool value) const
{
    check_hresult(shim()->put_AllowTrimming(value));
}

template <typename D> Windows::Media::Capture::CameraCaptureUIPhotoCaptureSettings impl_ICameraCaptureUI<D>::PhotoSettings() const
{
    Windows::Media::Capture::CameraCaptureUIPhotoCaptureSettings value { nullptr };
    check_hresult(shim()->get_PhotoSettings(put(value)));
    return value;
}

template <typename D> Windows::Media::Capture::CameraCaptureUIVideoCaptureSettings impl_ICameraCaptureUI<D>::VideoSettings() const
{
    Windows::Media::Capture::CameraCaptureUIVideoCaptureSettings value { nullptr };
    check_hresult(shim()->get_VideoSettings(put(value)));
    return value;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Storage::StorageFile> impl_ICameraCaptureUI<D>::CaptureFileAsync(Windows::Media::Capture::CameraCaptureUIMode mode) const
{
    Windows::Foundation::IAsyncOperation<Windows::Storage::StorageFile> asyncInfo;
    check_hresult(shim()->abi_CaptureFileAsync(mode, put(asyncInfo)));
    return asyncInfo;
}

template <typename D> hstring impl_IMediaCaptureFailedEventArgs<D>::Message() const
{
    hstring value;
    check_hresult(shim()->get_Message(put(value)));
    return value;
}

template <typename D> uint32_t impl_IMediaCaptureFailedEventArgs<D>::Code() const
{
    uint32_t value {};
    check_hresult(shim()->get_Code(&value));
    return value;
}

template <typename D> uint32_t impl_IMediaCaptureVideoProfileMediaDescription<D>::Width() const
{
    uint32_t value {};
    check_hresult(shim()->get_Width(&value));
    return value;
}

template <typename D> uint32_t impl_IMediaCaptureVideoProfileMediaDescription<D>::Height() const
{
    uint32_t value {};
    check_hresult(shim()->get_Height(&value));
    return value;
}

template <typename D> double impl_IMediaCaptureVideoProfileMediaDescription<D>::FrameRate() const
{
    double value {};
    check_hresult(shim()->get_FrameRate(&value));
    return value;
}

template <typename D> bool impl_IMediaCaptureVideoProfileMediaDescription<D>::IsVariablePhotoSequenceSupported() const
{
    bool value {};
    check_hresult(shim()->get_IsVariablePhotoSequenceSupported(&value));
    return value;
}

template <typename D> bool impl_IMediaCaptureVideoProfileMediaDescription<D>::IsHdrVideoSupported() const
{
    bool value {};
    check_hresult(shim()->get_IsHdrVideoSupported(&value));
    return value;
}

template <typename D> hstring impl_IMediaCaptureVideoProfile<D>::Id() const
{
    hstring value;
    check_hresult(shim()->get_Id(put(value)));
    return value;
}

template <typename D> hstring impl_IMediaCaptureVideoProfile<D>::VideoDeviceId() const
{
    hstring value;
    check_hresult(shim()->get_VideoDeviceId(put(value)));
    return value;
}

template <typename D> Windows::Foundation::Collections::IVectorView<Windows::Media::Capture::MediaCaptureVideoProfileMediaDescription> impl_IMediaCaptureVideoProfile<D>::SupportedPreviewMediaDescription() const
{
    Windows::Foundation::Collections::IVectorView<Windows::Media::Capture::MediaCaptureVideoProfileMediaDescription> value;
    check_hresult(shim()->get_SupportedPreviewMediaDescription(put(value)));
    return value;
}

template <typename D> Windows::Foundation::Collections::IVectorView<Windows::Media::Capture::MediaCaptureVideoProfileMediaDescription> impl_IMediaCaptureVideoProfile<D>::SupportedRecordMediaDescription() const
{
    Windows::Foundation::Collections::IVectorView<Windows::Media::Capture::MediaCaptureVideoProfileMediaDescription> value;
    check_hresult(shim()->get_SupportedRecordMediaDescription(put(value)));
    return value;
}

template <typename D> Windows::Foundation::Collections::IVectorView<Windows::Media::Capture::MediaCaptureVideoProfileMediaDescription> impl_IMediaCaptureVideoProfile<D>::SupportedPhotoMediaDescription() const
{
    Windows::Foundation::Collections::IVectorView<Windows::Media::Capture::MediaCaptureVideoProfileMediaDescription> value;
    check_hresult(shim()->get_SupportedPhotoMediaDescription(put(value)));
    return value;
}

template <typename D> Windows::Foundation::Collections::IVectorView<Windows::Media::Capture::MediaCaptureVideoProfile> impl_IMediaCaptureVideoProfile<D>::GetConcurrency() const
{
    Windows::Foundation::Collections::IVectorView<Windows::Media::Capture::MediaCaptureVideoProfile> value;
    check_hresult(shim()->abi_GetConcurrency(put(value)));
    return value;
}

template <typename D> void impl_IMediaCaptureInitializationSettings<D>::AudioDeviceId(hstring_ref value) const
{
    check_hresult(shim()->put_AudioDeviceId(get(value)));
}

template <typename D> hstring impl_IMediaCaptureInitializationSettings<D>::AudioDeviceId() const
{
    hstring value;
    check_hresult(shim()->get_AudioDeviceId(put(value)));
    return value;
}

template <typename D> void impl_IMediaCaptureInitializationSettings<D>::VideoDeviceId(hstring_ref value) const
{
    check_hresult(shim()->put_VideoDeviceId(get(value)));
}

template <typename D> hstring impl_IMediaCaptureInitializationSettings<D>::VideoDeviceId() const
{
    hstring value;
    check_hresult(shim()->get_VideoDeviceId(put(value)));
    return value;
}

template <typename D> void impl_IMediaCaptureInitializationSettings<D>::StreamingCaptureMode(Windows::Media::Capture::StreamingCaptureMode value) const
{
    check_hresult(shim()->put_StreamingCaptureMode(value));
}

template <typename D> Windows::Media::Capture::StreamingCaptureMode impl_IMediaCaptureInitializationSettings<D>::StreamingCaptureMode() const
{
    Windows::Media::Capture::StreamingCaptureMode value {};
    check_hresult(shim()->get_StreamingCaptureMode(&value));
    return value;
}

template <typename D> void impl_IMediaCaptureInitializationSettings<D>::PhotoCaptureSource(Windows::Media::Capture::PhotoCaptureSource value) const
{
    check_hresult(shim()->put_PhotoCaptureSource(value));
}

template <typename D> Windows::Media::Capture::PhotoCaptureSource impl_IMediaCaptureInitializationSettings<D>::PhotoCaptureSource() const
{
    Windows::Media::Capture::PhotoCaptureSource value {};
    check_hresult(shim()->get_PhotoCaptureSource(&value));
    return value;
}

template <typename D> void impl_IMediaCaptureInitializationSettings2<D>::MediaCategory(Windows::Media::Capture::MediaCategory value) const
{
    check_hresult(shim()->put_MediaCategory(value));
}

template <typename D> Windows::Media::Capture::MediaCategory impl_IMediaCaptureInitializationSettings2<D>::MediaCategory() const
{
    Windows::Media::Capture::MediaCategory value {};
    check_hresult(shim()->get_MediaCategory(&value));
    return value;
}

template <typename D> void impl_IMediaCaptureInitializationSettings2<D>::AudioProcessing(Windows::Media::AudioProcessing value) const
{
    check_hresult(shim()->put_AudioProcessing(value));
}

template <typename D> Windows::Media::AudioProcessing impl_IMediaCaptureInitializationSettings2<D>::AudioProcessing() const
{
    Windows::Media::AudioProcessing value {};
    check_hresult(shim()->get_AudioProcessing(&value));
    return value;
}

template <typename D> void impl_IMediaCaptureInitializationSettings3<D>::AudioSource(const Windows::Media::Core::IMediaSource & value) const
{
    check_hresult(shim()->put_AudioSource(get(value)));
}

template <typename D> Windows::Media::Core::IMediaSource impl_IMediaCaptureInitializationSettings3<D>::AudioSource() const
{
    Windows::Media::Core::IMediaSource value;
    check_hresult(shim()->get_AudioSource(put(value)));
    return value;
}

template <typename D> void impl_IMediaCaptureInitializationSettings3<D>::VideoSource(const Windows::Media::Core::IMediaSource & value) const
{
    check_hresult(shim()->put_VideoSource(get(value)));
}

template <typename D> Windows::Media::Core::IMediaSource impl_IMediaCaptureInitializationSettings3<D>::VideoSource() const
{
    Windows::Media::Core::IMediaSource value;
    check_hresult(shim()->get_VideoSource(put(value)));
    return value;
}

template <typename D> Windows::Media::Capture::MediaCaptureVideoProfile impl_IMediaCaptureInitializationSettings4<D>::VideoProfile() const
{
    Windows::Media::Capture::MediaCaptureVideoProfile value { nullptr };
    check_hresult(shim()->get_VideoProfile(put(value)));
    return value;
}

template <typename D> void impl_IMediaCaptureInitializationSettings4<D>::VideoProfile(const Windows::Media::Capture::MediaCaptureVideoProfile & value) const
{
    check_hresult(shim()->put_VideoProfile(get(value)));
}

template <typename D> Windows::Media::Capture::MediaCaptureVideoProfileMediaDescription impl_IMediaCaptureInitializationSettings4<D>::PreviewMediaDescription() const
{
    Windows::Media::Capture::MediaCaptureVideoProfileMediaDescription value { nullptr };
    check_hresult(shim()->get_PreviewMediaDescription(put(value)));
    return value;
}

template <typename D> void impl_IMediaCaptureInitializationSettings4<D>::PreviewMediaDescription(const Windows::Media::Capture::MediaCaptureVideoProfileMediaDescription & value) const
{
    check_hresult(shim()->put_PreviewMediaDescription(get(value)));
}

template <typename D> Windows::Media::Capture::MediaCaptureVideoProfileMediaDescription impl_IMediaCaptureInitializationSettings4<D>::RecordMediaDescription() const
{
    Windows::Media::Capture::MediaCaptureVideoProfileMediaDescription value { nullptr };
    check_hresult(shim()->get_RecordMediaDescription(put(value)));
    return value;
}

template <typename D> void impl_IMediaCaptureInitializationSettings4<D>::RecordMediaDescription(const Windows::Media::Capture::MediaCaptureVideoProfileMediaDescription & value) const
{
    check_hresult(shim()->put_RecordMediaDescription(get(value)));
}

template <typename D> Windows::Media::Capture::MediaCaptureVideoProfileMediaDescription impl_IMediaCaptureInitializationSettings4<D>::PhotoMediaDescription() const
{
    Windows::Media::Capture::MediaCaptureVideoProfileMediaDescription value { nullptr };
    check_hresult(shim()->get_PhotoMediaDescription(put(value)));
    return value;
}

template <typename D> void impl_IMediaCaptureInitializationSettings4<D>::PhotoMediaDescription(const Windows::Media::Capture::MediaCaptureVideoProfileMediaDescription & value) const
{
    check_hresult(shim()->put_PhotoMediaDescription(get(value)));
}

template <typename D> Windows::Media::Capture::Frames::MediaFrameSourceGroup impl_IMediaCaptureInitializationSettings5<D>::SourceGroup() const
{
    Windows::Media::Capture::Frames::MediaFrameSourceGroup value { nullptr };
    check_hresult(shim()->get_SourceGroup(put(value)));
    return value;
}

template <typename D> void impl_IMediaCaptureInitializationSettings5<D>::SourceGroup(const Windows::Media::Capture::Frames::MediaFrameSourceGroup & value) const
{
    check_hresult(shim()->put_SourceGroup(get(value)));
}

template <typename D> Windows::Media::Capture::MediaCaptureSharingMode impl_IMediaCaptureInitializationSettings5<D>::SharingMode() const
{
    Windows::Media::Capture::MediaCaptureSharingMode value {};
    check_hresult(shim()->get_SharingMode(&value));
    return value;
}

template <typename D> void impl_IMediaCaptureInitializationSettings5<D>::SharingMode(Windows::Media::Capture::MediaCaptureSharingMode value) const
{
    check_hresult(shim()->put_SharingMode(value));
}

template <typename D> Windows::Media::Capture::MediaCaptureMemoryPreference impl_IMediaCaptureInitializationSettings5<D>::MemoryPreference() const
{
    Windows::Media::Capture::MediaCaptureMemoryPreference value {};
    check_hresult(shim()->get_MemoryPreference(&value));
    return value;
}

template <typename D> void impl_IMediaCaptureInitializationSettings5<D>::MemoryPreference(Windows::Media::Capture::MediaCaptureMemoryPreference value) const
{
    check_hresult(shim()->put_MemoryPreference(value));
}

template <typename D> bool impl_IMediaCaptureStatics<D>::IsVideoProfileSupported(hstring_ref videoDeviceId) const
{
    bool value {};
    check_hresult(shim()->abi_IsVideoProfileSupported(get(videoDeviceId), &value));
    return value;
}

template <typename D> Windows::Foundation::Collections::IVectorView<Windows::Media::Capture::MediaCaptureVideoProfile> impl_IMediaCaptureStatics<D>::FindAllVideoProfiles(hstring_ref videoDeviceId) const
{
    Windows::Foundation::Collections::IVectorView<Windows::Media::Capture::MediaCaptureVideoProfile> value;
    check_hresult(shim()->abi_FindAllVideoProfiles(get(videoDeviceId), put(value)));
    return value;
}

template <typename D> Windows::Foundation::Collections::IVectorView<Windows::Media::Capture::MediaCaptureVideoProfile> impl_IMediaCaptureStatics<D>::FindConcurrentProfiles(hstring_ref videoDeviceId) const
{
    Windows::Foundation::Collections::IVectorView<Windows::Media::Capture::MediaCaptureVideoProfile> value;
    check_hresult(shim()->abi_FindConcurrentProfiles(get(videoDeviceId), put(value)));
    return value;
}

template <typename D> Windows::Foundation::Collections::IVectorView<Windows::Media::Capture::MediaCaptureVideoProfile> impl_IMediaCaptureStatics<D>::FindKnownVideoProfiles(hstring_ref videoDeviceId, Windows::Media::Capture::KnownVideoProfile name) const
{
    Windows::Foundation::Collections::IVectorView<Windows::Media::Capture::MediaCaptureVideoProfile> value;
    check_hresult(shim()->abi_FindKnownVideoProfiles(get(videoDeviceId), name, put(value)));
    return value;
}

template <typename D> Windows::Foundation::IAsyncAction impl_IMediaCapture<D>::InitializeAsync() const
{
    Windows::Foundation::IAsyncAction asyncInfo;
    check_hresult(shim()->abi_InitializeAsync(put(asyncInfo)));
    return asyncInfo;
}

template <typename D> Windows::Foundation::IAsyncAction impl_IMediaCapture<D>::InitializeAsync(const Windows::Media::Capture::MediaCaptureInitializationSettings & mediaCaptureInitializationSettings) const
{
    Windows::Foundation::IAsyncAction asyncInfo;
    check_hresult(shim()->abi_InitializeWithSettingsAsync(get(mediaCaptureInitializationSettings), put(asyncInfo)));
    return asyncInfo;
}

template <typename D> Windows::Foundation::IAsyncAction impl_IMediaCapture<D>::StartRecordToStorageFileAsync(const Windows::Media::MediaProperties::MediaEncodingProfile & encodingProfile, const Windows::Storage::IStorageFile & file) const
{
    Windows::Foundation::IAsyncAction asyncInfo;
    check_hresult(shim()->abi_StartRecordToStorageFileAsync(get(encodingProfile), get(file), put(asyncInfo)));
    return asyncInfo;
}

template <typename D> Windows::Foundation::IAsyncAction impl_IMediaCapture<D>::StartRecordToStreamAsync(const Windows::Media::MediaProperties::MediaEncodingProfile & encodingProfile, const Windows::Storage::Streams::IRandomAccessStream & stream) const
{
    Windows::Foundation::IAsyncAction asyncInfo;
    check_hresult(shim()->abi_StartRecordToStreamAsync(get(encodingProfile), get(stream), put(asyncInfo)));
    return asyncInfo;
}

template <typename D> Windows::Foundation::IAsyncAction impl_IMediaCapture<D>::StartRecordToCustomSinkAsync(const Windows::Media::MediaProperties::MediaEncodingProfile & encodingProfile, const Windows::Media::IMediaExtension & customMediaSink) const
{
    Windows::Foundation::IAsyncAction asyncInfo;
    check_hresult(shim()->abi_StartRecordToCustomSinkAsync(get(encodingProfile), get(customMediaSink), put(asyncInfo)));
    return asyncInfo;
}

template <typename D> Windows::Foundation::IAsyncAction impl_IMediaCapture<D>::StartRecordToCustomSinkAsync(const Windows::Media::MediaProperties::MediaEncodingProfile & encodingProfile, hstring_ref customSinkActivationId, const Windows::Foundation::Collections::IPropertySet & customSinkSettings) const
{
    Windows::Foundation::IAsyncAction asyncInfo;
    check_hresult(shim()->abi_StartRecordToCustomSinkIdAsync(get(encodingProfile), get(customSinkActivationId), get(customSinkSettings), put(asyncInfo)));
    return asyncInfo;
}

template <typename D> Windows::Foundation::IAsyncAction impl_IMediaCapture<D>::StopRecordAsync() const
{
    Windows::Foundation::IAsyncAction asyncInfo;
    check_hresult(shim()->abi_StopRecordAsync(put(asyncInfo)));
    return asyncInfo;
}

template <typename D> Windows::Foundation::IAsyncAction impl_IMediaCapture<D>::CapturePhotoToStorageFileAsync(const Windows::Media::MediaProperties::ImageEncodingProperties & type, const Windows::Storage::IStorageFile & file) const
{
    Windows::Foundation::IAsyncAction asyncInfo;
    check_hresult(shim()->abi_CapturePhotoToStorageFileAsync(get(type), get(file), put(asyncInfo)));
    return asyncInfo;
}

template <typename D> Windows::Foundation::IAsyncAction impl_IMediaCapture<D>::CapturePhotoToStreamAsync(const Windows::Media::MediaProperties::ImageEncodingProperties & type, const Windows::Storage::Streams::IRandomAccessStream & stream) const
{
    Windows::Foundation::IAsyncAction asyncInfo;
    check_hresult(shim()->abi_CapturePhotoToStreamAsync(get(type), get(stream), put(asyncInfo)));
    return asyncInfo;
}

template <typename D> Windows::Foundation::IAsyncAction impl_IMediaCapture<D>::AddEffectAsync(Windows::Media::Capture::MediaStreamType mediaStreamType, hstring_ref effectActivationID, const Windows::Foundation::Collections::IPropertySet & effectSettings) const
{
    Windows::Foundation::IAsyncAction asyncInfo;
    check_hresult(shim()->abi_AddEffectAsync(mediaStreamType, get(effectActivationID), get(effectSettings), put(asyncInfo)));
    return asyncInfo;
}

template <typename D> Windows::Foundation::IAsyncAction impl_IMediaCapture<D>::ClearEffectsAsync(Windows::Media::Capture::MediaStreamType mediaStreamType) const
{
    Windows::Foundation::IAsyncAction asyncInfo;
    check_hresult(shim()->abi_ClearEffectsAsync(mediaStreamType, put(asyncInfo)));
    return asyncInfo;
}

template <typename D> void impl_IMediaCapture<D>::SetEncoderProperty(Windows::Media::Capture::MediaStreamType mediaStreamType, GUID propertyId, const Windows::IInspectable & propertyValue) const
{
    check_hresult(shim()->abi_SetEncoderProperty(mediaStreamType, propertyId, get(propertyValue)));
}

template <typename D> Windows::IInspectable impl_IMediaCapture<D>::GetEncoderProperty(Windows::Media::Capture::MediaStreamType mediaStreamType, GUID propertyId) const
{
    Windows::IInspectable propertyValue;
    check_hresult(shim()->abi_GetEncoderProperty(mediaStreamType, propertyId, put(propertyValue)));
    return propertyValue;
}

template <typename D> event_token impl_IMediaCapture<D>::Failed(const Windows::Media::Capture::MediaCaptureFailedEventHandler & errorEventHandler) const
{
    event_token eventCookie {};
    check_hresult(shim()->add_Failed(get(errorEventHandler), &eventCookie));
    return eventCookie;
}

template <typename D> event_revoker<IMediaCapture> impl_IMediaCapture<D>::Failed(auto_revoke_t, const Windows::Media::Capture::MediaCaptureFailedEventHandler & errorEventHandler) const
{
    return impl::make_event_revoker<D, IMediaCapture>(this, &ABI::Windows::Media::Capture::IMediaCapture::remove_Failed, Failed(errorEventHandler));
}

template <typename D> void impl_IMediaCapture<D>::Failed(event_token eventCookie) const
{
    check_hresult(shim()->remove_Failed(eventCookie));
}

template <typename D> event_token impl_IMediaCapture<D>::RecordLimitationExceeded(const Windows::Media::Capture::RecordLimitationExceededEventHandler & recordLimitationExceededEventHandler) const
{
    event_token eventCookie {};
    check_hresult(shim()->add_RecordLimitationExceeded(get(recordLimitationExceededEventHandler), &eventCookie));
    return eventCookie;
}

template <typename D> event_revoker<IMediaCapture> impl_IMediaCapture<D>::RecordLimitationExceeded(auto_revoke_t, const Windows::Media::Capture::RecordLimitationExceededEventHandler & recordLimitationExceededEventHandler) const
{
    return impl::make_event_revoker<D, IMediaCapture>(this, &ABI::Windows::Media::Capture::IMediaCapture::remove_RecordLimitationExceeded, RecordLimitationExceeded(recordLimitationExceededEventHandler));
}

template <typename D> void impl_IMediaCapture<D>::RecordLimitationExceeded(event_token eventCookie) const
{
    check_hresult(shim()->remove_RecordLimitationExceeded(eventCookie));
}

template <typename D> Windows::Media::Capture::MediaCaptureSettings impl_IMediaCapture<D>::MediaCaptureSettings() const
{
    Windows::Media::Capture::MediaCaptureSettings value { nullptr };
    check_hresult(shim()->get_MediaCaptureSettings(put(value)));
    return value;
}

template <typename D> Windows::Media::Devices::AudioDeviceController impl_IMediaCapture<D>::AudioDeviceController() const
{
    Windows::Media::Devices::AudioDeviceController value { nullptr };
    check_hresult(shim()->get_AudioDeviceController(put(value)));
    return value;
}

template <typename D> Windows::Media::Devices::VideoDeviceController impl_IMediaCapture<D>::VideoDeviceController() const
{
    Windows::Media::Devices::VideoDeviceController value { nullptr };
    check_hresult(shim()->get_VideoDeviceController(put(value)));
    return value;
}

template <typename D> void impl_IMediaCapture<D>::SetPreviewMirroring(bool value) const
{
    check_hresult(shim()->abi_SetPreviewMirroring(value));
}

template <typename D> bool impl_IMediaCapture<D>::GetPreviewMirroring() const
{
    bool value {};
    check_hresult(shim()->abi_GetPreviewMirroring(&value));
    return value;
}

template <typename D> void impl_IMediaCapture<D>::SetPreviewRotation(Windows::Media::Capture::VideoRotation value) const
{
    check_hresult(shim()->abi_SetPreviewRotation(value));
}

template <typename D> Windows::Media::Capture::VideoRotation impl_IMediaCapture<D>::GetPreviewRotation() const
{
    Windows::Media::Capture::VideoRotation value {};
    check_hresult(shim()->abi_GetPreviewRotation(&value));
    return value;
}

template <typename D> void impl_IMediaCapture<D>::SetRecordRotation(Windows::Media::Capture::VideoRotation value) const
{
    check_hresult(shim()->abi_SetRecordRotation(value));
}

template <typename D> Windows::Media::Capture::VideoRotation impl_IMediaCapture<D>::GetRecordRotation() const
{
    Windows::Media::Capture::VideoRotation value {};
    check_hresult(shim()->abi_GetRecordRotation(&value));
    return value;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Media::Capture::LowLagMediaRecording> impl_IMediaCapture2<D>::PrepareLowLagRecordToStorageFileAsync(const Windows::Media::MediaProperties::MediaEncodingProfile & encodingProfile, const Windows::Storage::IStorageFile & file) const
{
    Windows::Foundation::IAsyncOperation<Windows::Media::Capture::LowLagMediaRecording> operation;
    check_hresult(shim()->abi_PrepareLowLagRecordToStorageFileAsync(get(encodingProfile), get(file), put(operation)));
    return operation;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Media::Capture::LowLagMediaRecording> impl_IMediaCapture2<D>::PrepareLowLagRecordToStreamAsync(const Windows::Media::MediaProperties::MediaEncodingProfile & encodingProfile, const Windows::Storage::Streams::IRandomAccessStream & stream) const
{
    Windows::Foundation::IAsyncOperation<Windows::Media::Capture::LowLagMediaRecording> operation;
    check_hresult(shim()->abi_PrepareLowLagRecordToStreamAsync(get(encodingProfile), get(stream), put(operation)));
    return operation;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Media::Capture::LowLagMediaRecording> impl_IMediaCapture2<D>::PrepareLowLagRecordToCustomSinkAsync(const Windows::Media::MediaProperties::MediaEncodingProfile & encodingProfile, const Windows::Media::IMediaExtension & customMediaSink) const
{
    Windows::Foundation::IAsyncOperation<Windows::Media::Capture::LowLagMediaRecording> operation;
    check_hresult(shim()->abi_PrepareLowLagRecordToCustomSinkAsync(get(encodingProfile), get(customMediaSink), put(operation)));
    return operation;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Media::Capture::LowLagMediaRecording> impl_IMediaCapture2<D>::PrepareLowLagRecordToCustomSinkAsync(const Windows::Media::MediaProperties::MediaEncodingProfile & encodingProfile, hstring_ref customSinkActivationId, const Windows::Foundation::Collections::IPropertySet & customSinkSettings) const
{
    Windows::Foundation::IAsyncOperation<Windows::Media::Capture::LowLagMediaRecording> operation;
    check_hresult(shim()->abi_PrepareLowLagRecordToCustomSinkIdAsync(get(encodingProfile), get(customSinkActivationId), get(customSinkSettings), put(operation)));
    return operation;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Media::Capture::LowLagPhotoCapture> impl_IMediaCapture2<D>::PrepareLowLagPhotoCaptureAsync(const Windows::Media::MediaProperties::ImageEncodingProperties & type) const
{
    Windows::Foundation::IAsyncOperation<Windows::Media::Capture::LowLagPhotoCapture> operation;
    check_hresult(shim()->abi_PrepareLowLagPhotoCaptureAsync(get(type), put(operation)));
    return operation;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Media::Capture::LowLagPhotoSequenceCapture> impl_IMediaCapture2<D>::PrepareLowLagPhotoSequenceCaptureAsync(const Windows::Media::MediaProperties::ImageEncodingProperties & type) const
{
    Windows::Foundation::IAsyncOperation<Windows::Media::Capture::LowLagPhotoSequenceCapture> operation;
    check_hresult(shim()->abi_PrepareLowLagPhotoSequenceCaptureAsync(get(type), put(operation)));
    return operation;
}

template <typename D> Windows::Foundation::IAsyncAction impl_IMediaCapture2<D>::SetEncodingPropertiesAsync(Windows::Media::Capture::MediaStreamType mediaStreamType, const Windows::Media::MediaProperties::IMediaEncodingProperties & mediaEncodingProperties, const Windows::Media::MediaProperties::MediaPropertySet & encoderProperties) const
{
    Windows::Foundation::IAsyncAction operation;
    check_hresult(shim()->abi_SetEncodingPropertiesAsync(mediaStreamType, get(mediaEncodingProperties), get(encoderProperties), put(operation)));
    return operation;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Media::Capture::Core::VariablePhotoSequenceCapture> impl_IMediaCapture3<D>::PrepareVariablePhotoSequenceCaptureAsync(const Windows::Media::MediaProperties::ImageEncodingProperties & type) const
{
    Windows::Foundation::IAsyncOperation<Windows::Media::Capture::Core::VariablePhotoSequenceCapture> operation;
    check_hresult(shim()->abi_PrepareVariablePhotoSequenceCaptureAsync(get(type), put(operation)));
    return operation;
}

template <typename D> event_token impl_IMediaCapture3<D>::FocusChanged(const Windows::Foundation::TypedEventHandler<Windows::Media::Capture::MediaCapture, Windows::Media::Capture::MediaCaptureFocusChangedEventArgs> & handler) const
{
    event_token token {};
    check_hresult(shim()->add_FocusChanged(get(handler), &token));
    return token;
}

template <typename D> event_revoker<IMediaCapture3> impl_IMediaCapture3<D>::FocusChanged(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Media::Capture::MediaCapture, Windows::Media::Capture::MediaCaptureFocusChangedEventArgs> & handler) const
{
    return impl::make_event_revoker<D, IMediaCapture3>(this, &ABI::Windows::Media::Capture::IMediaCapture3::remove_FocusChanged, FocusChanged(handler));
}

template <typename D> void impl_IMediaCapture3<D>::FocusChanged(event_token token) const
{
    check_hresult(shim()->remove_FocusChanged(token));
}

template <typename D> event_token impl_IMediaCapture3<D>::PhotoConfirmationCaptured(const Windows::Foundation::TypedEventHandler<Windows::Media::Capture::MediaCapture, Windows::Media::Capture::PhotoConfirmationCapturedEventArgs> & handler) const
{
    event_token token {};
    check_hresult(shim()->add_PhotoConfirmationCaptured(get(handler), &token));
    return token;
}

template <typename D> event_revoker<IMediaCapture3> impl_IMediaCapture3<D>::PhotoConfirmationCaptured(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Media::Capture::MediaCapture, Windows::Media::Capture::PhotoConfirmationCapturedEventArgs> & handler) const
{
    return impl::make_event_revoker<D, IMediaCapture3>(this, &ABI::Windows::Media::Capture::IMediaCapture3::remove_PhotoConfirmationCaptured, PhotoConfirmationCaptured(handler));
}

template <typename D> void impl_IMediaCapture3<D>::PhotoConfirmationCaptured(event_token token) const
{
    check_hresult(shim()->remove_PhotoConfirmationCaptured(token));
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Media::IMediaExtension> impl_IMediaCapture4<D>::AddAudioEffectAsync(const Windows::Media::Effects::IAudioEffectDefinition & definition) const
{
    Windows::Foundation::IAsyncOperation<Windows::Media::IMediaExtension> op;
    check_hresult(shim()->abi_AddAudioEffectAsync(get(definition), put(op)));
    return op;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Media::IMediaExtension> impl_IMediaCapture4<D>::AddVideoEffectAsync(const Windows::Media::Effects::IVideoEffectDefinition & definition, Windows::Media::Capture::MediaStreamType mediaStreamType) const
{
    Windows::Foundation::IAsyncOperation<Windows::Media::IMediaExtension> op;
    check_hresult(shim()->abi_AddVideoEffectAsync(get(definition), mediaStreamType, put(op)));
    return op;
}

template <typename D> Windows::Foundation::IAsyncAction impl_IMediaCapture4<D>::PauseRecordAsync(Windows::Media::Devices::MediaCapturePauseBehavior behavior) const
{
    Windows::Foundation::IAsyncAction asyncInfo;
    check_hresult(shim()->abi_PauseRecordAsync(behavior, put(asyncInfo)));
    return asyncInfo;
}

template <typename D> Windows::Foundation::IAsyncAction impl_IMediaCapture4<D>::ResumeRecordAsync() const
{
    Windows::Foundation::IAsyncAction asyncInfo;
    check_hresult(shim()->abi_ResumeRecordAsync(put(asyncInfo)));
    return asyncInfo;
}

template <typename D> event_token impl_IMediaCapture4<D>::CameraStreamStateChanged(const Windows::Foundation::TypedEventHandler<Windows::Media::Capture::MediaCapture, Windows::IInspectable> & handler) const
{
    event_token token {};
    check_hresult(shim()->add_CameraStreamStateChanged(get(handler), &token));
    return token;
}

template <typename D> event_revoker<IMediaCapture4> impl_IMediaCapture4<D>::CameraStreamStateChanged(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Media::Capture::MediaCapture, Windows::IInspectable> & handler) const
{
    return impl::make_event_revoker<D, IMediaCapture4>(this, &ABI::Windows::Media::Capture::IMediaCapture4::remove_CameraStreamStateChanged, CameraStreamStateChanged(handler));
}

template <typename D> void impl_IMediaCapture4<D>::CameraStreamStateChanged(event_token token) const
{
    check_hresult(shim()->remove_CameraStreamStateChanged(token));
}

template <typename D> Windows::Media::Devices::CameraStreamState impl_IMediaCapture4<D>::CameraStreamState() const
{
    Windows::Media::Devices::CameraStreamState streamState {};
    check_hresult(shim()->get_CameraStreamState(&streamState));
    return streamState;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Media::VideoFrame> impl_IMediaCapture4<D>::GetPreviewFrameAsync() const
{
    Windows::Foundation::IAsyncOperation<Windows::Media::VideoFrame> operation;
    check_hresult(shim()->abi_GetPreviewFrameAsync(put(operation)));
    return operation;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Media::VideoFrame> impl_IMediaCapture4<D>::GetPreviewFrameAsync(const Windows::Media::VideoFrame & destination) const
{
    Windows::Foundation::IAsyncOperation<Windows::Media::VideoFrame> operation;
    check_hresult(shim()->abi_GetPreviewFrameCopyAsync(get(destination), put(operation)));
    return operation;
}

template <typename D> event_token impl_IMediaCapture4<D>::ThermalStatusChanged(const Windows::Foundation::TypedEventHandler<Windows::Media::Capture::MediaCapture, Windows::IInspectable> & handler) const
{
    event_token token {};
    check_hresult(shim()->add_ThermalStatusChanged(get(handler), &token));
    return token;
}

template <typename D> event_revoker<IMediaCapture4> impl_IMediaCapture4<D>::ThermalStatusChanged(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Media::Capture::MediaCapture, Windows::IInspectable> & handler) const
{
    return impl::make_event_revoker<D, IMediaCapture4>(this, &ABI::Windows::Media::Capture::IMediaCapture4::remove_ThermalStatusChanged, ThermalStatusChanged(handler));
}

template <typename D> void impl_IMediaCapture4<D>::ThermalStatusChanged(event_token token) const
{
    check_hresult(shim()->remove_ThermalStatusChanged(token));
}

template <typename D> Windows::Media::Capture::MediaCaptureThermalStatus impl_IMediaCapture4<D>::ThermalStatus() const
{
    Windows::Media::Capture::MediaCaptureThermalStatus value {};
    check_hresult(shim()->get_ThermalStatus(&value));
    return value;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Media::Capture::AdvancedPhotoCapture> impl_IMediaCapture4<D>::PrepareAdvancedPhotoCaptureAsync(const Windows::Media::MediaProperties::ImageEncodingProperties & encodingProperties) const
{
    Windows::Foundation::IAsyncOperation<Windows::Media::Capture::AdvancedPhotoCapture> operation;
    check_hresult(shim()->abi_PrepareAdvancedPhotoCaptureAsync(get(encodingProperties), put(operation)));
    return operation;
}

template <typename D> Windows::Foundation::IAsyncAction impl_IMediaCapture5<D>::RemoveEffectAsync(const Windows::Media::IMediaExtension & effect) const
{
    Windows::Foundation::IAsyncAction asyncInfo;
    check_hresult(shim()->abi_RemoveEffectAsync(get(effect), put(asyncInfo)));
    return asyncInfo;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Media::Capture::MediaCapturePauseResult> impl_IMediaCapture5<D>::PauseRecordWithResultAsync(Windows::Media::Devices::MediaCapturePauseBehavior behavior) const
{
    Windows::Foundation::IAsyncOperation<Windows::Media::Capture::MediaCapturePauseResult> operation;
    check_hresult(shim()->abi_PauseRecordWithResultAsync(behavior, put(operation)));
    return operation;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Media::Capture::MediaCaptureStopResult> impl_IMediaCapture5<D>::StopRecordWithResultAsync() const
{
    Windows::Foundation::IAsyncOperation<Windows::Media::Capture::MediaCaptureStopResult> operation;
    check_hresult(shim()->abi_StopRecordWithResultAsync(put(operation)));
    return operation;
}

template <typename D> Windows::Foundation::Collections::IMapView<hstring, Windows::Media::Capture::Frames::MediaFrameSource> impl_IMediaCapture5<D>::FrameSources() const
{
    Windows::Foundation::Collections::IMapView<hstring, Windows::Media::Capture::Frames::MediaFrameSource> value;
    check_hresult(shim()->get_FrameSources(put(value)));
    return value;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Media::Capture::Frames::MediaFrameReader> impl_IMediaCapture5<D>::CreateFrameReaderAsync(const Windows::Media::Capture::Frames::MediaFrameSource & inputSource) const
{
    Windows::Foundation::IAsyncOperation<Windows::Media::Capture::Frames::MediaFrameReader> value;
    check_hresult(shim()->abi_CreateFrameReaderAsync(get(inputSource), put(value)));
    return value;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Media::Capture::Frames::MediaFrameReader> impl_IMediaCapture5<D>::CreateFrameReaderAsync(const Windows::Media::Capture::Frames::MediaFrameSource & inputSource, hstring_ref outputSubtype) const
{
    Windows::Foundation::IAsyncOperation<Windows::Media::Capture::Frames::MediaFrameReader> value;
    check_hresult(shim()->abi_CreateFrameReaderWithSubtypeAsync(get(inputSource), get(outputSubtype), put(value)));
    return value;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Media::Capture::Frames::MediaFrameReader> impl_IMediaCapture5<D>::CreateFrameReaderAsync(const Windows::Media::Capture::Frames::MediaFrameSource & inputSource, hstring_ref outputSubtype, const Windows::Graphics::Imaging::BitmapSize & outputSize) const
{
    Windows::Foundation::IAsyncOperation<Windows::Media::Capture::Frames::MediaFrameReader> value;
    check_hresult(shim()->abi_CreateFrameReaderWithSubtypeAndSizeAsync(get(inputSource), get(outputSubtype), get(outputSize), put(value)));
    return value;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Media::Capture::CapturedPhoto> impl_ILowLagPhotoCapture<D>::CaptureAsync() const
{
    Windows::Foundation::IAsyncOperation<Windows::Media::Capture::CapturedPhoto> operation;
    check_hresult(shim()->abi_CaptureAsync(put(operation)));
    return operation;
}

template <typename D> Windows::Foundation::IAsyncAction impl_ILowLagPhotoCapture<D>::FinishAsync() const
{
    Windows::Foundation::IAsyncAction operation;
    check_hresult(shim()->abi_FinishAsync(put(operation)));
    return operation;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Media::Capture::AdvancedCapturedPhoto> impl_IAdvancedPhotoCapture<D>::CaptureAsync() const
{
    Windows::Foundation::IAsyncOperation<Windows::Media::Capture::AdvancedCapturedPhoto> operation;
    check_hresult(shim()->abi_CaptureAsync(put(operation)));
    return operation;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Media::Capture::AdvancedCapturedPhoto> impl_IAdvancedPhotoCapture<D>::CaptureAsync(const Windows::IInspectable & context) const
{
    Windows::Foundation::IAsyncOperation<Windows::Media::Capture::AdvancedCapturedPhoto> operation;
    check_hresult(shim()->abi_CaptureWithContextAsync(get(context), put(operation)));
    return operation;
}

template <typename D> event_token impl_IAdvancedPhotoCapture<D>::OptionalReferencePhotoCaptured(const Windows::Foundation::TypedEventHandler<Windows::Media::Capture::AdvancedPhotoCapture, Windows::Media::Capture::OptionalReferencePhotoCapturedEventArgs> & handler) const
{
    event_token token {};
    check_hresult(shim()->add_OptionalReferencePhotoCaptured(get(handler), &token));
    return token;
}

template <typename D> event_revoker<IAdvancedPhotoCapture> impl_IAdvancedPhotoCapture<D>::OptionalReferencePhotoCaptured(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Media::Capture::AdvancedPhotoCapture, Windows::Media::Capture::OptionalReferencePhotoCapturedEventArgs> & handler) const
{
    return impl::make_event_revoker<D, IAdvancedPhotoCapture>(this, &ABI::Windows::Media::Capture::IAdvancedPhotoCapture::remove_OptionalReferencePhotoCaptured, OptionalReferencePhotoCaptured(handler));
}

template <typename D> void impl_IAdvancedPhotoCapture<D>::OptionalReferencePhotoCaptured(event_token token) const
{
    check_hresult(shim()->remove_OptionalReferencePhotoCaptured(token));
}

template <typename D> event_token impl_IAdvancedPhotoCapture<D>::AllPhotosCaptured(const Windows::Foundation::TypedEventHandler<Windows::Media::Capture::AdvancedPhotoCapture, Windows::IInspectable> & handler) const
{
    event_token token {};
    check_hresult(shim()->add_AllPhotosCaptured(get(handler), &token));
    return token;
}

template <typename D> event_revoker<IAdvancedPhotoCapture> impl_IAdvancedPhotoCapture<D>::AllPhotosCaptured(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Media::Capture::AdvancedPhotoCapture, Windows::IInspectable> & handler) const
{
    return impl::make_event_revoker<D, IAdvancedPhotoCapture>(this, &ABI::Windows::Media::Capture::IAdvancedPhotoCapture::remove_AllPhotosCaptured, AllPhotosCaptured(handler));
}

template <typename D> void impl_IAdvancedPhotoCapture<D>::AllPhotosCaptured(event_token token) const
{
    check_hresult(shim()->remove_AllPhotosCaptured(token));
}

template <typename D> Windows::Foundation::IAsyncAction impl_IAdvancedPhotoCapture<D>::FinishAsync() const
{
    Windows::Foundation::IAsyncAction operation;
    check_hresult(shim()->abi_FinishAsync(put(operation)));
    return operation;
}

template <typename D> Windows::Media::Capture::CapturedFrame impl_IAdvancedCapturedPhoto<D>::Frame() const
{
    Windows::Media::Capture::CapturedFrame value { nullptr };
    check_hresult(shim()->get_Frame(put(value)));
    return value;
}

template <typename D> Windows::Media::Devices::AdvancedPhotoMode impl_IAdvancedCapturedPhoto<D>::Mode() const
{
    Windows::Media::Devices::AdvancedPhotoMode value {};
    check_hresult(shim()->get_Mode(&value));
    return value;
}

template <typename D> Windows::IInspectable impl_IAdvancedCapturedPhoto<D>::Context() const
{
    Windows::IInspectable value;
    check_hresult(shim()->get_Context(put(value)));
    return value;
}

template <typename D> Windows::Foundation::IReference<Windows::Foundation::Rect> impl_IAdvancedCapturedPhoto2<D>::FrameBoundsRelativeToReferencePhoto() const
{
    Windows::Foundation::IReference<Windows::Foundation::Rect> value;
    check_hresult(shim()->get_FrameBoundsRelativeToReferencePhoto(put(value)));
    return value;
}

template <typename D> Windows::Media::Capture::CapturedFrame impl_IOptionalReferencePhotoCapturedEventArgs<D>::Frame() const
{
    Windows::Media::Capture::CapturedFrame value { nullptr };
    check_hresult(shim()->get_Frame(put(value)));
    return value;
}

template <typename D> Windows::IInspectable impl_IOptionalReferencePhotoCapturedEventArgs<D>::Context() const
{
    Windows::IInspectable value;
    check_hresult(shim()->get_Context(put(value)));
    return value;
}

template <typename D> Windows::Foundation::IAsyncAction impl_ILowLagMediaRecording<D>::StartAsync() const
{
    Windows::Foundation::IAsyncAction operation;
    check_hresult(shim()->abi_StartAsync(put(operation)));
    return operation;
}

template <typename D> Windows::Foundation::IAsyncAction impl_ILowLagMediaRecording<D>::StopAsync() const
{
    Windows::Foundation::IAsyncAction operation;
    check_hresult(shim()->abi_StopAsync(put(operation)));
    return operation;
}

template <typename D> Windows::Foundation::IAsyncAction impl_ILowLagMediaRecording<D>::FinishAsync() const
{
    Windows::Foundation::IAsyncAction operation;
    check_hresult(shim()->abi_FinishAsync(put(operation)));
    return operation;
}

template <typename D> Windows::Foundation::IAsyncAction impl_ILowLagMediaRecording2<D>::PauseAsync(Windows::Media::Devices::MediaCapturePauseBehavior behavior) const
{
    Windows::Foundation::IAsyncAction operation;
    check_hresult(shim()->abi_PauseAsync(behavior, put(operation)));
    return operation;
}

template <typename D> Windows::Foundation::IAsyncAction impl_ILowLagMediaRecording2<D>::ResumeAsync() const
{
    Windows::Foundation::IAsyncAction operation;
    check_hresult(shim()->abi_ResumeAsync(put(operation)));
    return operation;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Media::Capture::MediaCapturePauseResult> impl_ILowLagMediaRecording3<D>::PauseWithResultAsync(Windows::Media::Devices::MediaCapturePauseBehavior behavior) const
{
    Windows::Foundation::IAsyncOperation<Windows::Media::Capture::MediaCapturePauseResult> operation;
    check_hresult(shim()->abi_PauseWithResultAsync(behavior, put(operation)));
    return operation;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Media::Capture::MediaCaptureStopResult> impl_ILowLagMediaRecording3<D>::StopWithResultAsync() const
{
    Windows::Foundation::IAsyncOperation<Windows::Media::Capture::MediaCaptureStopResult> operation;
    check_hresult(shim()->abi_StopWithResultAsync(put(operation)));
    return operation;
}

template <typename D> Windows::Media::VideoFrame impl_IMediaCapturePauseResult<D>::LastFrame() const
{
    Windows::Media::VideoFrame value { nullptr };
    check_hresult(shim()->get_LastFrame(put(value)));
    return value;
}

template <typename D> Windows::Foundation::TimeSpan impl_IMediaCapturePauseResult<D>::RecordDuration() const
{
    Windows::Foundation::TimeSpan value {};
    check_hresult(shim()->get_RecordDuration(put(value)));
    return value;
}

template <typename D> Windows::Media::VideoFrame impl_IMediaCaptureStopResult<D>::LastFrame() const
{
    Windows::Media::VideoFrame value { nullptr };
    check_hresult(shim()->get_LastFrame(put(value)));
    return value;
}

template <typename D> Windows::Foundation::TimeSpan impl_IMediaCaptureStopResult<D>::RecordDuration() const
{
    Windows::Foundation::TimeSpan value {};
    check_hresult(shim()->get_RecordDuration(put(value)));
    return value;
}

template <typename D> Windows::Foundation::IAsyncAction impl_ILowLagPhotoSequenceCapture<D>::StartAsync() const
{
    Windows::Foundation::IAsyncAction operation;
    check_hresult(shim()->abi_StartAsync(put(operation)));
    return operation;
}

template <typename D> Windows::Foundation::IAsyncAction impl_ILowLagPhotoSequenceCapture<D>::StopAsync() const
{
    Windows::Foundation::IAsyncAction operation;
    check_hresult(shim()->abi_StopAsync(put(operation)));
    return operation;
}

template <typename D> Windows::Foundation::IAsyncAction impl_ILowLagPhotoSequenceCapture<D>::FinishAsync() const
{
    Windows::Foundation::IAsyncAction operation;
    check_hresult(shim()->abi_FinishAsync(put(operation)));
    return operation;
}

template <typename D> event_token impl_ILowLagPhotoSequenceCapture<D>::PhotoCaptured(const Windows::Foundation::TypedEventHandler<Windows::Media::Capture::LowLagPhotoSequenceCapture, Windows::Media::Capture::PhotoCapturedEventArgs> & handler) const
{
    event_token token {};
    check_hresult(shim()->add_PhotoCaptured(get(handler), &token));
    return token;
}

template <typename D> event_revoker<ILowLagPhotoSequenceCapture> impl_ILowLagPhotoSequenceCapture<D>::PhotoCaptured(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Media::Capture::LowLagPhotoSequenceCapture, Windows::Media::Capture::PhotoCapturedEventArgs> & handler) const
{
    return impl::make_event_revoker<D, ILowLagPhotoSequenceCapture>(this, &ABI::Windows::Media::Capture::ILowLagPhotoSequenceCapture::remove_PhotoCaptured, PhotoCaptured(handler));
}

template <typename D> void impl_ILowLagPhotoSequenceCapture<D>::PhotoCaptured(event_token token) const
{
    check_hresult(shim()->remove_PhotoCaptured(token));
}

template <typename D> Windows::Foundation::IReference<Windows::Foundation::TimeSpan> impl_ICapturedFrameControlValues<D>::Exposure() const
{
    Windows::Foundation::IReference<Windows::Foundation::TimeSpan> value;
    check_hresult(shim()->get_Exposure(put(value)));
    return value;
}

template <typename D> Windows::Foundation::IReference<float> impl_ICapturedFrameControlValues<D>::ExposureCompensation() const
{
    Windows::Foundation::IReference<float> value;
    check_hresult(shim()->get_ExposureCompensation(put(value)));
    return value;
}

template <typename D> Windows::Foundation::IReference<uint32_t> impl_ICapturedFrameControlValues<D>::IsoSpeed() const
{
    Windows::Foundation::IReference<uint32_t> value;
    check_hresult(shim()->get_IsoSpeed(put(value)));
    return value;
}

template <typename D> Windows::Foundation::IReference<uint32_t> impl_ICapturedFrameControlValues<D>::Focus() const
{
    Windows::Foundation::IReference<uint32_t> value;
    check_hresult(shim()->get_Focus(put(value)));
    return value;
}

template <typename D> Windows::Foundation::IReference<winrt::Windows::Media::Devices::CaptureSceneMode> impl_ICapturedFrameControlValues<D>::SceneMode() const
{
    Windows::Foundation::IReference<winrt::Windows::Media::Devices::CaptureSceneMode> value;
    check_hresult(shim()->get_SceneMode(put(value)));
    return value;
}

template <typename D> Windows::Foundation::IReference<bool> impl_ICapturedFrameControlValues<D>::Flashed() const
{
    Windows::Foundation::IReference<bool> value;
    check_hresult(shim()->get_Flashed(put(value)));
    return value;
}

template <typename D> Windows::Foundation::IReference<float> impl_ICapturedFrameControlValues<D>::FlashPowerPercent() const
{
    Windows::Foundation::IReference<float> value;
    check_hresult(shim()->get_FlashPowerPercent(put(value)));
    return value;
}

template <typename D> Windows::Foundation::IReference<uint32_t> impl_ICapturedFrameControlValues<D>::WhiteBalance() const
{
    Windows::Foundation::IReference<uint32_t> value;
    check_hresult(shim()->get_WhiteBalance(put(value)));
    return value;
}

template <typename D> Windows::Foundation::IReference<float> impl_ICapturedFrameControlValues<D>::ZoomFactor() const
{
    Windows::Foundation::IReference<float> value;
    check_hresult(shim()->get_ZoomFactor(put(value)));
    return value;
}

template <typename D> Windows::Foundation::IReference<winrt::Windows::Media::Devices::MediaCaptureFocusState> impl_ICapturedFrameControlValues2<D>::FocusState() const
{
    Windows::Foundation::IReference<winrt::Windows::Media::Devices::MediaCaptureFocusState> value;
    check_hresult(shim()->get_FocusState(put(value)));
    return value;
}

template <typename D> Windows::Foundation::IReference<double> impl_ICapturedFrameControlValues2<D>::IsoDigitalGain() const
{
    Windows::Foundation::IReference<double> value;
    check_hresult(shim()->get_IsoDigitalGain(put(value)));
    return value;
}

template <typename D> Windows::Foundation::IReference<double> impl_ICapturedFrameControlValues2<D>::IsoAnalogGain() const
{
    Windows::Foundation::IReference<double> value;
    check_hresult(shim()->get_IsoAnalogGain(put(value)));
    return value;
}

template <typename D> Windows::Media::MediaProperties::MediaRatio impl_ICapturedFrameControlValues2<D>::SensorFrameRate() const
{
    Windows::Media::MediaProperties::MediaRatio value { nullptr };
    check_hresult(shim()->get_SensorFrameRate(put(value)));
    return value;
}

template <typename D> Windows::Foundation::IReference<Windows::Media::Capture::WhiteBalanceGain> impl_ICapturedFrameControlValues2<D>::WhiteBalanceGain() const
{
    Windows::Foundation::IReference<Windows::Media::Capture::WhiteBalanceGain> value;
    check_hresult(shim()->get_WhiteBalanceGain(put(value)));
    return value;
}

template <typename D> Windows::Media::Capture::CapturedFrame impl_IPhotoCapturedEventArgs<D>::Frame() const
{
    Windows::Media::Capture::CapturedFrame value { nullptr };
    check_hresult(shim()->get_Frame(put(value)));
    return value;
}

template <typename D> Windows::Media::Capture::CapturedFrame impl_IPhotoCapturedEventArgs<D>::Thumbnail() const
{
    Windows::Media::Capture::CapturedFrame value { nullptr };
    check_hresult(shim()->get_Thumbnail(put(value)));
    return value;
}

template <typename D> Windows::Foundation::TimeSpan impl_IPhotoCapturedEventArgs<D>::CaptureTimeOffset() const
{
    Windows::Foundation::TimeSpan value {};
    check_hresult(shim()->get_CaptureTimeOffset(put(value)));
    return value;
}

template <typename D> Windows::Media::Capture::CapturedFrame impl_ICapturedPhoto<D>::Frame() const
{
    Windows::Media::Capture::CapturedFrame value { nullptr };
    check_hresult(shim()->get_Frame(put(value)));
    return value;
}

template <typename D> Windows::Media::Capture::CapturedFrame impl_ICapturedPhoto<D>::Thumbnail() const
{
    Windows::Media::Capture::CapturedFrame value { nullptr };
    check_hresult(shim()->get_Thumbnail(put(value)));
    return value;
}

template <typename D> uint32_t impl_ICapturedFrame<D>::Width() const
{
    uint32_t value {};
    check_hresult(shim()->get_Width(&value));
    return value;
}

template <typename D> uint32_t impl_ICapturedFrame<D>::Height() const
{
    uint32_t value {};
    check_hresult(shim()->get_Height(&value));
    return value;
}

template <typename D> Windows::Graphics::Imaging::SoftwareBitmap impl_ICapturedFrameWithSoftwareBitmap<D>::SoftwareBitmap() const
{
    Windows::Graphics::Imaging::SoftwareBitmap value { nullptr };
    check_hresult(shim()->get_SoftwareBitmap(put(value)));
    return value;
}

template <typename D> Windows::Foundation::IAsyncAction impl_IMediaCaptureVideoPreview<D>::StartPreviewAsync() const
{
    Windows::Foundation::IAsyncAction asyncInfo;
    check_hresult(shim()->abi_StartPreviewAsync(put(asyncInfo)));
    return asyncInfo;
}

template <typename D> Windows::Foundation::IAsyncAction impl_IMediaCaptureVideoPreview<D>::StartPreviewToCustomSinkAsync(const Windows::Media::MediaProperties::MediaEncodingProfile & encodingProfile, const Windows::Media::IMediaExtension & customMediaSink) const
{
    Windows::Foundation::IAsyncAction asyncInfo;
    check_hresult(shim()->abi_StartPreviewToCustomSinkAsync(get(encodingProfile), get(customMediaSink), put(asyncInfo)));
    return asyncInfo;
}

template <typename D> Windows::Foundation::IAsyncAction impl_IMediaCaptureVideoPreview<D>::StartPreviewToCustomSinkAsync(const Windows::Media::MediaProperties::MediaEncodingProfile & encodingProfile, hstring_ref customSinkActivationId, const Windows::Foundation::Collections::IPropertySet & customSinkSettings) const
{
    Windows::Foundation::IAsyncAction asyncInfo;
    check_hresult(shim()->abi_StartPreviewToCustomSinkIdAsync(get(encodingProfile), get(customSinkActivationId), get(customSinkSettings), put(asyncInfo)));
    return asyncInfo;
}

template <typename D> Windows::Foundation::IAsyncAction impl_IMediaCaptureVideoPreview<D>::StopPreviewAsync() const
{
    Windows::Foundation::IAsyncAction asyncInfo;
    check_hresult(shim()->abi_StopPreviewAsync(put(asyncInfo)));
    return asyncInfo;
}

template <typename D> hstring impl_IMediaCaptureSettings<D>::AudioDeviceId() const
{
    hstring value;
    check_hresult(shim()->get_AudioDeviceId(put(value)));
    return value;
}

template <typename D> hstring impl_IMediaCaptureSettings<D>::VideoDeviceId() const
{
    hstring value;
    check_hresult(shim()->get_VideoDeviceId(put(value)));
    return value;
}

template <typename D> Windows::Media::Capture::StreamingCaptureMode impl_IMediaCaptureSettings<D>::StreamingCaptureMode() const
{
    Windows::Media::Capture::StreamingCaptureMode value {};
    check_hresult(shim()->get_StreamingCaptureMode(&value));
    return value;
}

template <typename D> Windows::Media::Capture::PhotoCaptureSource impl_IMediaCaptureSettings<D>::PhotoCaptureSource() const
{
    Windows::Media::Capture::PhotoCaptureSource value {};
    check_hresult(shim()->get_PhotoCaptureSource(&value));
    return value;
}

template <typename D> Windows::Media::Capture::VideoDeviceCharacteristic impl_IMediaCaptureSettings<D>::VideoDeviceCharacteristic() const
{
    Windows::Media::Capture::VideoDeviceCharacteristic value {};
    check_hresult(shim()->get_VideoDeviceCharacteristic(&value));
    return value;
}

template <typename D> bool impl_IMediaCaptureSettings2<D>::ConcurrentRecordAndPhotoSupported() const
{
    bool value {};
    check_hresult(shim()->get_ConcurrentRecordAndPhotoSupported(&value));
    return value;
}

template <typename D> bool impl_IMediaCaptureSettings2<D>::ConcurrentRecordAndPhotoSequenceSupported() const
{
    bool value {};
    check_hresult(shim()->get_ConcurrentRecordAndPhotoSequenceSupported(&value));
    return value;
}

template <typename D> bool impl_IMediaCaptureSettings2<D>::CameraSoundRequiredForRegion() const
{
    bool value {};
    check_hresult(shim()->get_CameraSoundRequiredForRegion(&value));
    return value;
}

template <typename D> Windows::Foundation::IReference<uint32_t> impl_IMediaCaptureSettings2<D>::Horizontal35mmEquivalentFocalLength() const
{
    Windows::Foundation::IReference<uint32_t> value;
    check_hresult(shim()->get_Horizontal35mmEquivalentFocalLength(put(value)));
    return value;
}

template <typename D> Windows::Foundation::IReference<int32_t> impl_IMediaCaptureSettings2<D>::PitchOffsetDegrees() const
{
    Windows::Foundation::IReference<int32_t> value;
    check_hresult(shim()->get_PitchOffsetDegrees(put(value)));
    return value;
}

template <typename D> Windows::Foundation::IReference<uint32_t> impl_IMediaCaptureSettings2<D>::Vertical35mmEquivalentFocalLength() const
{
    Windows::Foundation::IReference<uint32_t> value;
    check_hresult(shim()->get_Vertical35mmEquivalentFocalLength(put(value)));
    return value;
}

template <typename D> Windows::Media::Capture::MediaCategory impl_IMediaCaptureSettings2<D>::MediaCategory() const
{
    Windows::Media::Capture::MediaCategory value {};
    check_hresult(shim()->get_MediaCategory(&value));
    return value;
}

template <typename D> Windows::Media::AudioProcessing impl_IMediaCaptureSettings2<D>::AudioProcessing() const
{
    Windows::Media::AudioProcessing value {};
    check_hresult(shim()->get_AudioProcessing(&value));
    return value;
}

template <typename D> Windows::Media::Devices::MediaCaptureFocusState impl_IMediaCaptureFocusChangedEventArgs<D>::FocusState() const
{
    Windows::Media::Devices::MediaCaptureFocusState value {};
    check_hresult(shim()->get_FocusState(&value));
    return value;
}

template <typename D> Windows::Media::Capture::CapturedFrame impl_IPhotoConfirmationCapturedEventArgs<D>::Frame() const
{
    Windows::Media::Capture::CapturedFrame value { nullptr };
    check_hresult(shim()->get_Frame(put(value)));
    return value;
}

template <typename D> Windows::Foundation::TimeSpan impl_IPhotoConfirmationCapturedEventArgs<D>::CaptureTimeOffset() const
{
    Windows::Foundation::TimeSpan value {};
    check_hresult(shim()->get_CaptureTimeOffset(put(value)));
    return value;
}

template <typename D> Windows::Media::MediaProperties::VideoEncodingProperties impl_IVideoStreamConfiguration<D>::InputProperties() const
{
    Windows::Media::MediaProperties::VideoEncodingProperties value { nullptr };
    check_hresult(shim()->get_InputProperties(put(value)));
    return value;
}

template <typename D> Windows::Media::MediaProperties::VideoEncodingProperties impl_IVideoStreamConfiguration<D>::OutputProperties() const
{
    Windows::Media::MediaProperties::VideoEncodingProperties value { nullptr };
    check_hresult(shim()->get_OutputProperties(put(value)));
    return value;
}

inline Windows::Media::Capture::AppCapture AppCapture::GetForCurrentView()
{
    return get_activation_factory<AppCapture, IAppCaptureStatics>().GetForCurrentView();
}

inline CameraCaptureUI::CameraCaptureUI() :
    CameraCaptureUI(activate_instance<CameraCaptureUI>())
{}

inline MediaCapture::MediaCapture() :
    MediaCapture(activate_instance<MediaCapture>())
{}

inline bool MediaCapture::IsVideoProfileSupported(hstring_ref videoDeviceId)
{
    return get_activation_factory<MediaCapture, IMediaCaptureStatics>().IsVideoProfileSupported(videoDeviceId);
}

inline Windows::Foundation::Collections::IVectorView<Windows::Media::Capture::MediaCaptureVideoProfile> MediaCapture::FindAllVideoProfiles(hstring_ref videoDeviceId)
{
    return get_activation_factory<MediaCapture, IMediaCaptureStatics>().FindAllVideoProfiles(videoDeviceId);
}

inline Windows::Foundation::Collections::IVectorView<Windows::Media::Capture::MediaCaptureVideoProfile> MediaCapture::FindConcurrentProfiles(hstring_ref videoDeviceId)
{
    return get_activation_factory<MediaCapture, IMediaCaptureStatics>().FindConcurrentProfiles(videoDeviceId);
}

inline Windows::Foundation::Collections::IVectorView<Windows::Media::Capture::MediaCaptureVideoProfile> MediaCapture::FindKnownVideoProfiles(hstring_ref videoDeviceId, Windows::Media::Capture::KnownVideoProfile name)
{
    return get_activation_factory<MediaCapture, IMediaCaptureStatics>().FindKnownVideoProfiles(videoDeviceId, name);
}

inline MediaCaptureInitializationSettings::MediaCaptureInitializationSettings() :
    MediaCaptureInitializationSettings(activate_instance<MediaCaptureInitializationSettings>())
{}

}

}