// C++ for the Windows Runtime v1.0.private
// Copyright (c) 2016 Microsoft Corporation. All rights reserved.

#pragma once


WINRT_EXPORT namespace winrt {

namespace ABI::Windows::Media::Capture {

struct WhiteBalanceGain;

}

namespace Windows::Media::Capture {

using WhiteBalanceGain = ABI::Windows::Media::Capture::WhiteBalanceGain;

}

namespace ABI::Windows::Media::Capture {

struct IAdvancedCapturedPhoto;
struct IAdvancedCapturedPhoto2;
struct IAdvancedPhotoCapture;
struct IAppCapture;
struct IAppCaptureStatics;
struct ICameraCaptureUI;
struct ICameraCaptureUIPhotoCaptureSettings;
struct ICameraCaptureUIVideoCaptureSettings;
struct ICapturedFrame;
struct ICapturedFrameControlValues;
struct ICapturedFrameControlValues2;
struct ICapturedFrameWithSoftwareBitmap;
struct ICapturedPhoto;
struct ILowLagMediaRecording;
struct ILowLagMediaRecording2;
struct ILowLagMediaRecording3;
struct ILowLagPhotoCapture;
struct ILowLagPhotoSequenceCapture;
struct IMediaCapture;
struct IMediaCapture2;
struct IMediaCapture3;
struct IMediaCapture4;
struct IMediaCapture5;
struct IMediaCaptureFailedEventArgs;
struct IMediaCaptureFocusChangedEventArgs;
struct IMediaCaptureInitializationSettings;
struct IMediaCaptureInitializationSettings2;
struct IMediaCaptureInitializationSettings3;
struct IMediaCaptureInitializationSettings4;
struct IMediaCaptureInitializationSettings5;
struct IMediaCapturePauseResult;
struct IMediaCaptureSettings;
struct IMediaCaptureSettings2;
struct IMediaCaptureStatics;
struct IMediaCaptureStopResult;
struct IMediaCaptureVideoPreview;
struct IMediaCaptureVideoProfile;
struct IMediaCaptureVideoProfileMediaDescription;
struct IOptionalReferencePhotoCapturedEventArgs;
struct IPhotoCapturedEventArgs;
struct IPhotoConfirmationCapturedEventArgs;
struct IVideoStreamConfiguration;
struct MediaCaptureFailedEventHandler;
struct RecordLimitationExceededEventHandler;
struct AdvancedCapturedPhoto;
struct AdvancedPhotoCapture;
struct AppCapture;
struct CameraCaptureUI;
struct CameraCaptureUIPhotoCaptureSettings;
struct CameraCaptureUIVideoCaptureSettings;
struct CapturedFrame;
struct CapturedFrameControlValues;
struct CapturedPhoto;
struct LowLagMediaRecording;
struct LowLagPhotoCapture;
struct LowLagPhotoSequenceCapture;
struct MediaCapture;
struct MediaCaptureFailedEventArgs;
struct MediaCaptureFocusChangedEventArgs;
struct MediaCaptureInitializationSettings;
struct MediaCapturePauseResult;
struct MediaCaptureSettings;
struct MediaCaptureStopResult;
struct MediaCaptureVideoProfile;
struct MediaCaptureVideoProfileMediaDescription;
struct OptionalReferencePhotoCapturedEventArgs;
struct PhotoCapturedEventArgs;
struct PhotoConfirmationCapturedEventArgs;
struct VideoStreamConfiguration;

}

namespace Windows::Media::Capture {

struct MediaCaptureFailedEventHandler;
struct RecordLimitationExceededEventHandler;
struct IAdvancedCapturedPhoto;
struct IAdvancedCapturedPhoto2;
struct IAdvancedPhotoCapture;
struct IAppCapture;
struct IAppCaptureStatics;
struct ICameraCaptureUI;
struct ICameraCaptureUIPhotoCaptureSettings;
struct ICameraCaptureUIVideoCaptureSettings;
struct ICapturedFrame;
struct ICapturedFrameControlValues;
struct ICapturedFrameControlValues2;
struct ICapturedFrameWithSoftwareBitmap;
struct ICapturedPhoto;
struct ILowLagMediaRecording;
struct ILowLagMediaRecording2;
struct ILowLagMediaRecording3;
struct ILowLagPhotoCapture;
struct ILowLagPhotoSequenceCapture;
struct IMediaCapture;
struct IMediaCapture2;
struct IMediaCapture3;
struct IMediaCapture4;
struct IMediaCapture5;
struct IMediaCaptureFailedEventArgs;
struct IMediaCaptureFocusChangedEventArgs;
struct IMediaCaptureInitializationSettings;
struct IMediaCaptureInitializationSettings2;
struct IMediaCaptureInitializationSettings3;
struct IMediaCaptureInitializationSettings4;
struct IMediaCaptureInitializationSettings5;
struct IMediaCapturePauseResult;
struct IMediaCaptureSettings;
struct IMediaCaptureSettings2;
struct IMediaCaptureStatics;
struct IMediaCaptureStopResult;
struct IMediaCaptureVideoPreview;
struct IMediaCaptureVideoProfile;
struct IMediaCaptureVideoProfileMediaDescription;
struct IOptionalReferencePhotoCapturedEventArgs;
struct IPhotoCapturedEventArgs;
struct IPhotoConfirmationCapturedEventArgs;
struct IVideoStreamConfiguration;
struct AdvancedCapturedPhoto;
struct AdvancedPhotoCapture;
struct AppCapture;
struct CameraCaptureUI;
struct CameraCaptureUIPhotoCaptureSettings;
struct CameraCaptureUIVideoCaptureSettings;
struct CapturedFrame;
struct CapturedFrameControlValues;
struct CapturedPhoto;
struct LowLagMediaRecording;
struct LowLagPhotoCapture;
struct LowLagPhotoSequenceCapture;
struct MediaCapture;
struct MediaCaptureFailedEventArgs;
struct MediaCaptureFocusChangedEventArgs;
struct MediaCaptureInitializationSettings;
struct MediaCapturePauseResult;
struct MediaCaptureSettings;
struct MediaCaptureStopResult;
struct MediaCaptureVideoProfile;
struct MediaCaptureVideoProfileMediaDescription;
struct OptionalReferencePhotoCapturedEventArgs;
struct PhotoCapturedEventArgs;
struct PhotoConfirmationCapturedEventArgs;
struct VideoStreamConfiguration;

}

namespace Windows::Media::Capture {

template <typename T> struct impl_IAdvancedCapturedPhoto;
template <typename T> struct impl_IAdvancedCapturedPhoto2;
template <typename T> struct impl_IAdvancedPhotoCapture;
template <typename T> struct impl_IAppCapture;
template <typename T> struct impl_IAppCaptureStatics;
template <typename T> struct impl_ICameraCaptureUI;
template <typename T> struct impl_ICameraCaptureUIPhotoCaptureSettings;
template <typename T> struct impl_ICameraCaptureUIVideoCaptureSettings;
template <typename T> struct impl_ICapturedFrame;
template <typename T> struct impl_ICapturedFrameControlValues;
template <typename T> struct impl_ICapturedFrameControlValues2;
template <typename T> struct impl_ICapturedFrameWithSoftwareBitmap;
template <typename T> struct impl_ICapturedPhoto;
template <typename T> struct impl_ILowLagMediaRecording;
template <typename T> struct impl_ILowLagMediaRecording2;
template <typename T> struct impl_ILowLagMediaRecording3;
template <typename T> struct impl_ILowLagPhotoCapture;
template <typename T> struct impl_ILowLagPhotoSequenceCapture;
template <typename T> struct impl_IMediaCapture;
template <typename T> struct impl_IMediaCapture2;
template <typename T> struct impl_IMediaCapture3;
template <typename T> struct impl_IMediaCapture4;
template <typename T> struct impl_IMediaCapture5;
template <typename T> struct impl_IMediaCaptureFailedEventArgs;
template <typename T> struct impl_IMediaCaptureFocusChangedEventArgs;
template <typename T> struct impl_IMediaCaptureInitializationSettings;
template <typename T> struct impl_IMediaCaptureInitializationSettings2;
template <typename T> struct impl_IMediaCaptureInitializationSettings3;
template <typename T> struct impl_IMediaCaptureInitializationSettings4;
template <typename T> struct impl_IMediaCaptureInitializationSettings5;
template <typename T> struct impl_IMediaCapturePauseResult;
template <typename T> struct impl_IMediaCaptureSettings;
template <typename T> struct impl_IMediaCaptureSettings2;
template <typename T> struct impl_IMediaCaptureStatics;
template <typename T> struct impl_IMediaCaptureStopResult;
template <typename T> struct impl_IMediaCaptureVideoPreview;
template <typename T> struct impl_IMediaCaptureVideoProfile;
template <typename T> struct impl_IMediaCaptureVideoProfileMediaDescription;
template <typename T> struct impl_IOptionalReferencePhotoCapturedEventArgs;
template <typename T> struct impl_IPhotoCapturedEventArgs;
template <typename T> struct impl_IPhotoConfirmationCapturedEventArgs;
template <typename T> struct impl_IVideoStreamConfiguration;
template <typename T> struct impl_MediaCaptureFailedEventHandler;
template <typename T> struct impl_RecordLimitationExceededEventHandler;

}

namespace Windows::Media::Capture {

enum class CameraCaptureUIMaxPhotoResolution
{
    HighestAvailable = 0,
    VerySmallQvga = 1,
    SmallVga = 2,
    MediumXga = 3,
    Large3M = 4,
    VeryLarge5M = 5,
};

enum class CameraCaptureUIMaxVideoResolution
{
    HighestAvailable = 0,
    LowDefinition = 1,
    StandardDefinition = 2,
    HighDefinition = 3,
};

enum class CameraCaptureUIMode
{
    PhotoOrVideo = 0,
    Photo = 1,
    Video = 2,
};

enum class CameraCaptureUIPhotoFormat
{
    Jpeg = 0,
    Png = 1,
    JpegXR = 2,
};

enum class CameraCaptureUIVideoFormat
{
    Mp4 = 0,
    Wmv = 1,
};

enum class KnownVideoProfile
{
    VideoRecording = 0,
    HighQualityPhoto = 1,
    BalancedVideoAndPhoto = 2,
    VideoConferencing = 3,
    PhotoSequence = 4,
};

enum class MediaCaptureMemoryPreference
{
    Auto = 0,
    Cpu = 1,
};

enum class MediaCaptureSharingMode
{
    ExclusiveControl = 0,
    SharedReadOnly = 1,
};

enum class MediaCaptureThermalStatus
{
    Normal = 0,
    Overheated = 1,
};

enum class MediaCategory
{
    Other = 0,
    Communications = 1,
    Media = 2,
    GameChat = 3,
    Speech = 4,
};

enum class MediaStreamType
{
    VideoPreview = 0,
    VideoRecord = 1,
    Audio = 2,
    Photo = 3,
};

enum class PhotoCaptureSource
{
    Auto = 0,
    VideoPreview = 1,
    Photo = 2,
};

enum class PowerlineFrequency
{
    Disabled = 0,
    FiftyHertz = 1,
    SixtyHertz = 2,
    Auto = 3,
};

enum class StreamingCaptureMode
{
    AudioAndVideo = 0,
    Audio = 1,
    Video = 2,
};

enum class VideoDeviceCharacteristic
{
    AllStreamsIndependent = 0,
    PreviewRecordStreamsIdentical = 1,
    PreviewPhotoStreamsIdentical = 2,
    RecordPhotoStreamsIdentical = 3,
    AllStreamsIdentical = 4,
};

enum class VideoRotation
{
    None = 0,
    Clockwise90Degrees = 1,
    Clockwise180Degrees = 2,
    Clockwise270Degrees = 3,
};

}

}
