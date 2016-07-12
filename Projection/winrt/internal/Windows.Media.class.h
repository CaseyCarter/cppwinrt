// C++ for the Windows Runtime v1.29
// Copyright (c) 2016 Microsoft Corporation

#pragma once

#include "Windows.Media.interface.h"

WINRT_EXPORT namespace winrt {

namespace Windows::Media {

struct WINRT_EBO AudioBuffer :
    Windows::Media::IAudioBuffer
{
    AudioBuffer(std::nullptr_t) noexcept {}
};

struct WINRT_EBO AudioFrame :
    Windows::Media::IAudioFrame
{
    AudioFrame(std::nullptr_t) noexcept {}
    AudioFrame(uint32_t capacity);
};

struct WINRT_EBO AutoRepeatModeChangeRequestedEventArgs :
    Windows::Media::IAutoRepeatModeChangeRequestedEventArgs
{
    AutoRepeatModeChangeRequestedEventArgs(std::nullptr_t) noexcept {}
};

struct WINRT_EBO ImageDisplayProperties :
    Windows::Media::IImageDisplayProperties
{
    ImageDisplayProperties(std::nullptr_t) noexcept {}
};

struct WINRT_EBO MediaExtensionManager :
    Windows::Media::IMediaExtensionManager
{
    MediaExtensionManager(std::nullptr_t) noexcept {}
    MediaExtensionManager();
};

struct MediaMarkerTypes
{
    MediaMarkerTypes() = delete;
    static hstring Bookmark();
};

struct WINRT_EBO MediaProcessingTriggerDetails :
    Windows::Media::IMediaProcessingTriggerDetails
{
    MediaProcessingTriggerDetails(std::nullptr_t) noexcept {}
};

struct WINRT_EBO MediaTimelineController :
    Windows::Media::IMediaTimelineController
{
    MediaTimelineController(std::nullptr_t) noexcept {}
    MediaTimelineController();
};

struct WINRT_EBO MusicDisplayProperties :
    Windows::Media::IMusicDisplayProperties,
    impl::require<MusicDisplayProperties, Windows::Media::IMusicDisplayProperties2, Windows::Media::IMusicDisplayProperties3>
{
    MusicDisplayProperties(std::nullptr_t) noexcept {}
};

struct WINRT_EBO PlaybackPositionChangeRequestedEventArgs :
    Windows::Media::IPlaybackPositionChangeRequestedEventArgs
{
    PlaybackPositionChangeRequestedEventArgs(std::nullptr_t) noexcept {}
};

struct WINRT_EBO PlaybackRateChangeRequestedEventArgs :
    Windows::Media::IPlaybackRateChangeRequestedEventArgs
{
    PlaybackRateChangeRequestedEventArgs(std::nullptr_t) noexcept {}
};

struct WINRT_EBO ShuffleEnabledChangeRequestedEventArgs :
    Windows::Media::IShuffleEnabledChangeRequestedEventArgs
{
    ShuffleEnabledChangeRequestedEventArgs(std::nullptr_t) noexcept {}
};

struct WINRT_EBO SystemMediaTransportControls :
    Windows::Media::ISystemMediaTransportControls,
    impl::require<SystemMediaTransportControls, Windows::Media::ISystemMediaTransportControls2>
{
    SystemMediaTransportControls(std::nullptr_t) noexcept {}
    static Windows::Media::SystemMediaTransportControls GetForCurrentView();
};

struct WINRT_EBO SystemMediaTransportControlsButtonPressedEventArgs :
    Windows::Media::ISystemMediaTransportControlsButtonPressedEventArgs
{
    SystemMediaTransportControlsButtonPressedEventArgs(std::nullptr_t) noexcept {}
};

struct WINRT_EBO SystemMediaTransportControlsDisplayUpdater :
    Windows::Media::ISystemMediaTransportControlsDisplayUpdater
{
    SystemMediaTransportControlsDisplayUpdater(std::nullptr_t) noexcept {}
};

struct WINRT_EBO SystemMediaTransportControlsPropertyChangedEventArgs :
    Windows::Media::ISystemMediaTransportControlsPropertyChangedEventArgs
{
    SystemMediaTransportControlsPropertyChangedEventArgs(std::nullptr_t) noexcept {}
};

struct WINRT_EBO SystemMediaTransportControlsTimelineProperties :
    Windows::Media::ISystemMediaTransportControlsTimelineProperties
{
    SystemMediaTransportControlsTimelineProperties(std::nullptr_t) noexcept {}
    SystemMediaTransportControlsTimelineProperties();
};

struct WINRT_EBO VideoDisplayProperties :
    Windows::Media::IVideoDisplayProperties,
    impl::require<VideoDisplayProperties, Windows::Media::IVideoDisplayProperties2>
{
    VideoDisplayProperties(std::nullptr_t) noexcept {}
};

struct VideoEffects
{
    VideoEffects() = delete;
    static hstring VideoStabilization();
};

struct WINRT_EBO VideoFrame :
    Windows::Media::IVideoFrame
{
    VideoFrame(std::nullptr_t) noexcept {}
    VideoFrame(Windows::Graphics::Imaging::BitmapPixelFormat format, int32_t width, int32_t height);
    VideoFrame(Windows::Graphics::Imaging::BitmapPixelFormat format, int32_t width, int32_t height, Windows::Graphics::Imaging::BitmapAlphaMode alpha);
};

}

}
