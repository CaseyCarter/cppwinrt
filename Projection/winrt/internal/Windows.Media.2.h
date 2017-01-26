// C++ for the Windows Runtime v1.0.private
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "Windows.Media.1.h"
#include "Windows.Foundation.1.h"

WINRT_EXPORT namespace winrt {

namespace ABI::Windows::Foundation {

#ifndef WINRT_GENERIC_cdb5efb3_5788_509d_9be1_71ccb8a3362a
#define WINRT_GENERIC_cdb5efb3_5788_509d_9be1_71ccb8a3362a
template <> struct __declspec(uuid("cdb5efb3-5788-509d-9be1-71ccb8a3362a")) __declspec(novtable) IAsyncOperation<bool> : impl_IAsyncOperation<bool> {};
#endif

#ifndef WINRT_GENERIC_604d0c4c_91de_5c2a_935f_362f13eaf800
#define WINRT_GENERIC_604d0c4c_91de_5c2a_935f_362f13eaf800
template <> struct __declspec(uuid("604d0c4c-91de-5c2a-935f-362f13eaf800")) __declspec(novtable) IReference<Windows::Foundation::TimeSpan> : impl_IReference<Windows::Foundation::TimeSpan> {};
#endif


}

namespace ABI::Windows::Foundation::Collections {

#ifndef WINRT_GENERIC_98b9acc1_4b56_532e_ac73_03d5291cca90
#define WINRT_GENERIC_98b9acc1_4b56_532e_ac73_03d5291cca90
template <> struct __declspec(uuid("98b9acc1-4b56-532e-ac73-03d5291cca90")) __declspec(novtable) IVector<hstring> : impl_IVector<hstring> {};
#endif

#ifndef WINRT_GENERIC_2f13c006_a03a_5f69_b090_75a43e33423e
#define WINRT_GENERIC_2f13c006_a03a_5f69_b090_75a43e33423e
template <> struct __declspec(uuid("2f13c006-a03a-5f69-b090-75a43e33423e")) __declspec(novtable) IVectorView<hstring> : impl_IVectorView<hstring> {};
#endif

#ifndef WINRT_GENERIC_e2fcc7c1_3bfc_5a0b_b2b0_72e769d1cb7e
#define WINRT_GENERIC_e2fcc7c1_3bfc_5a0b_b2b0_72e769d1cb7e
template <> struct __declspec(uuid("e2fcc7c1-3bfc-5a0b-b2b0-72e769d1cb7e")) __declspec(novtable) IIterable<hstring> : impl_IIterable<hstring> {};
#endif

#ifndef WINRT_GENERIC_b543562c_02b1_5824_80a8_9854130cdadd
#define WINRT_GENERIC_b543562c_02b1_5824_80a8_9854130cdadd
template <> struct __declspec(uuid("b543562c-02b1-5824-80a8-9854130cdadd")) __declspec(novtable) IVectorView<Windows::Media::IMediaMarker> : impl_IVectorView<Windows::Media::IMediaMarker> {};
#endif


}

namespace ABI::Windows::Foundation {

#ifndef WINRT_GENERIC_0557e996_7b23_5bae_aa81_ea0d671143a4
#define WINRT_GENERIC_0557e996_7b23_5bae_aa81_ea0d671143a4
template <> struct __declspec(uuid("0557e996-7b23-5bae-aa81-ea0d671143a4")) __declspec(novtable) TypedEventHandler<Windows::Media::SystemMediaTransportControls, Windows::Media::SystemMediaTransportControlsButtonPressedEventArgs> : impl_TypedEventHandler<Windows::Media::SystemMediaTransportControls, Windows::Media::SystemMediaTransportControlsButtonPressedEventArgs> {};
#endif

#ifndef WINRT_GENERIC_9fd61dad_1746_5fa1_a908_ef7cb4603c85
#define WINRT_GENERIC_9fd61dad_1746_5fa1_a908_ef7cb4603c85
template <> struct __declspec(uuid("9fd61dad-1746-5fa1-a908-ef7cb4603c85")) __declspec(novtable) TypedEventHandler<Windows::Media::SystemMediaTransportControls, Windows::Media::SystemMediaTransportControlsPropertyChangedEventArgs> : impl_TypedEventHandler<Windows::Media::SystemMediaTransportControls, Windows::Media::SystemMediaTransportControlsPropertyChangedEventArgs> {};
#endif

#ifndef WINRT_GENERIC_44e34f15_bdc0_50a7_ace4_39e91fb753f1
#define WINRT_GENERIC_44e34f15_bdc0_50a7_ace4_39e91fb753f1
template <> struct __declspec(uuid("44e34f15-bdc0-50a7-ace4-39e91fb753f1")) __declspec(novtable) TypedEventHandler<Windows::Media::SystemMediaTransportControls, Windows::Media::PlaybackPositionChangeRequestedEventArgs> : impl_TypedEventHandler<Windows::Media::SystemMediaTransportControls, Windows::Media::PlaybackPositionChangeRequestedEventArgs> {};
#endif

#ifndef WINRT_GENERIC_15eb0182_6366_5b9f_bd8c_8ab4fa9d7cd9
#define WINRT_GENERIC_15eb0182_6366_5b9f_bd8c_8ab4fa9d7cd9
template <> struct __declspec(uuid("15eb0182-6366-5b9f-bd8c-8ab4fa9d7cd9")) __declspec(novtable) TypedEventHandler<Windows::Media::SystemMediaTransportControls, Windows::Media::PlaybackRateChangeRequestedEventArgs> : impl_TypedEventHandler<Windows::Media::SystemMediaTransportControls, Windows::Media::PlaybackRateChangeRequestedEventArgs> {};
#endif

#ifndef WINRT_GENERIC_17ecea80_27e4_5dae_abb4_c858ad1c5307
#define WINRT_GENERIC_17ecea80_27e4_5dae_abb4_c858ad1c5307
template <> struct __declspec(uuid("17ecea80-27e4-5dae-abb4-c858ad1c5307")) __declspec(novtable) TypedEventHandler<Windows::Media::SystemMediaTransportControls, Windows::Media::ShuffleEnabledChangeRequestedEventArgs> : impl_TypedEventHandler<Windows::Media::SystemMediaTransportControls, Windows::Media::ShuffleEnabledChangeRequestedEventArgs> {};
#endif

#ifndef WINRT_GENERIC_a6214bde_02d5_55b3_ab0d_c6031be70da1
#define WINRT_GENERIC_a6214bde_02d5_55b3_ab0d_c6031be70da1
template <> struct __declspec(uuid("a6214bde-02d5-55b3-ab0d-c6031be70da1")) __declspec(novtable) TypedEventHandler<Windows::Media::SystemMediaTransportControls, Windows::Media::AutoRepeatModeChangeRequestedEventArgs> : impl_TypedEventHandler<Windows::Media::SystemMediaTransportControls, Windows::Media::AutoRepeatModeChangeRequestedEventArgs> {};
#endif

#ifndef WINRT_GENERIC_5c43e195_7d39_5d0d_a309_1991e68acdb7
#define WINRT_GENERIC_5c43e195_7d39_5d0d_a309_1991e68acdb7
template <> struct __declspec(uuid("5c43e195-7d39-5d0d-a309-1991e68acdb7")) __declspec(novtable) TypedEventHandler<Windows::Media::MediaTimelineController, Windows::IInspectable> : impl_TypedEventHandler<Windows::Media::MediaTimelineController, Windows::IInspectable> {};
#endif

#ifndef WINRT_GENERIC_c1d3d1a2_ae17_5a5f_b5a2_bdcc8844889a
#define WINRT_GENERIC_c1d3d1a2_ae17_5a5f_b5a2_bdcc8844889a
template <> struct __declspec(uuid("c1d3d1a2-ae17-5a5f-b5a2-bdcc8844889a")) __declspec(novtable) AsyncOperationCompletedHandler<bool> : impl_AsyncOperationCompletedHandler<bool> {};
#endif


}

namespace ABI::Windows::Foundation::Collections {

#ifndef WINRT_GENERIC_8c304ebb_6615_50a4_8829_879ecd443236
#define WINRT_GENERIC_8c304ebb_6615_50a4_8829_879ecd443236
template <> struct __declspec(uuid("8c304ebb-6615-50a4-8829-879ecd443236")) __declspec(novtable) IIterator<hstring> : impl_IIterator<hstring> {};
#endif

#ifndef WINRT_GENERIC_f464661e_88bc_5cea_93cd_0c123f17d258
#define WINRT_GENERIC_f464661e_88bc_5cea_93cd_0c123f17d258
template <> struct __declspec(uuid("f464661e-88bc-5cea-93cd-0c123f17d258")) __declspec(novtable) IIterator<Windows::Media::IMediaMarker> : impl_IIterator<Windows::Media::IMediaMarker> {};
#endif

#ifndef WINRT_GENERIC_a1c0a397_0364_5e4c_9dca_7cd7011bd114
#define WINRT_GENERIC_a1c0a397_0364_5e4c_9dca_7cd7011bd114
template <> struct __declspec(uuid("a1c0a397-0364-5e4c-9dca-7cd7011bd114")) __declspec(novtable) IIterable<Windows::Media::IMediaMarker> : impl_IIterable<Windows::Media::IMediaMarker> {};
#endif


}

namespace Windows::Media {

struct IAudioBuffer :
    Windows::IInspectable,
    impl::consume<IAudioBuffer>,
    impl::require<IAudioBuffer, Windows::Foundation::IClosable, Windows::Foundation::IMemoryBuffer>
{
    IAudioBuffer(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IAudioBuffer>(m_ptr); }
};

struct IAudioFrame :
    Windows::IInspectable,
    impl::consume<IAudioFrame>,
    impl::require<IAudioFrame, Windows::Foundation::IClosable, Windows::Media::IMediaFrame>
{
    IAudioFrame(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IAudioFrame>(m_ptr); }
};

struct IAudioFrameFactory :
    Windows::IInspectable,
    impl::consume<IAudioFrameFactory>
{
    IAudioFrameFactory(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IAudioFrameFactory>(m_ptr); }
};

struct IAutoRepeatModeChangeRequestedEventArgs :
    Windows::IInspectable,
    impl::consume<IAutoRepeatModeChangeRequestedEventArgs>
{
    IAutoRepeatModeChangeRequestedEventArgs(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IAutoRepeatModeChangeRequestedEventArgs>(m_ptr); }
};

struct IImageDisplayProperties :
    Windows::IInspectable,
    impl::consume<IImageDisplayProperties>
{
    IImageDisplayProperties(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IImageDisplayProperties>(m_ptr); }
};

struct IMediaExtension :
    Windows::IInspectable,
    impl::consume<IMediaExtension>
{
    IMediaExtension(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IMediaExtension>(m_ptr); }
};

struct IMediaExtensionManager :
    Windows::IInspectable,
    impl::consume<IMediaExtensionManager>
{
    IMediaExtensionManager(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IMediaExtensionManager>(m_ptr); }
};

struct IMediaFrame :
    Windows::IInspectable,
    impl::consume<IMediaFrame>,
    impl::require<IMediaFrame, Windows::Foundation::IClosable>
{
    IMediaFrame(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IMediaFrame>(m_ptr); }
};

struct IMediaMarker :
    Windows::IInspectable,
    impl::consume<IMediaMarker>
{
    IMediaMarker(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IMediaMarker>(m_ptr); }
};

struct IMediaMarkerTypesStatics :
    Windows::IInspectable,
    impl::consume<IMediaMarkerTypesStatics>
{
    IMediaMarkerTypesStatics(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IMediaMarkerTypesStatics>(m_ptr); }
};

struct IMediaMarkers :
    Windows::IInspectable,
    impl::consume<IMediaMarkers>
{
    IMediaMarkers(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IMediaMarkers>(m_ptr); }
};

struct IMediaProcessingTriggerDetails :
    Windows::IInspectable,
    impl::consume<IMediaProcessingTriggerDetails>
{
    IMediaProcessingTriggerDetails(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IMediaProcessingTriggerDetails>(m_ptr); }
};

struct IMediaTimelineController :
    Windows::IInspectable,
    impl::consume<IMediaTimelineController>
{
    IMediaTimelineController(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IMediaTimelineController>(m_ptr); }
};

struct IMusicDisplayProperties :
    Windows::IInspectable,
    impl::consume<IMusicDisplayProperties>
{
    IMusicDisplayProperties(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IMusicDisplayProperties>(m_ptr); }
};

struct IMusicDisplayProperties2 :
    Windows::IInspectable,
    impl::consume<IMusicDisplayProperties2>
{
    IMusicDisplayProperties2(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IMusicDisplayProperties2>(m_ptr); }
};

struct IMusicDisplayProperties3 :
    Windows::IInspectable,
    impl::consume<IMusicDisplayProperties3>
{
    IMusicDisplayProperties3(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IMusicDisplayProperties3>(m_ptr); }
};

struct IPlaybackPositionChangeRequestedEventArgs :
    Windows::IInspectable,
    impl::consume<IPlaybackPositionChangeRequestedEventArgs>
{
    IPlaybackPositionChangeRequestedEventArgs(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IPlaybackPositionChangeRequestedEventArgs>(m_ptr); }
};

struct IPlaybackRateChangeRequestedEventArgs :
    Windows::IInspectable,
    impl::consume<IPlaybackRateChangeRequestedEventArgs>
{
    IPlaybackRateChangeRequestedEventArgs(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IPlaybackRateChangeRequestedEventArgs>(m_ptr); }
};

struct IShuffleEnabledChangeRequestedEventArgs :
    Windows::IInspectable,
    impl::consume<IShuffleEnabledChangeRequestedEventArgs>
{
    IShuffleEnabledChangeRequestedEventArgs(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IShuffleEnabledChangeRequestedEventArgs>(m_ptr); }
};

struct ISystemMediaTransportControls :
    Windows::IInspectable,
    impl::consume<ISystemMediaTransportControls>
{
    ISystemMediaTransportControls(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<ISystemMediaTransportControls>(m_ptr); }
};

struct ISystemMediaTransportControls2 :
    Windows::IInspectable,
    impl::consume<ISystemMediaTransportControls2>
{
    ISystemMediaTransportControls2(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<ISystemMediaTransportControls2>(m_ptr); }
};

struct ISystemMediaTransportControlsButtonPressedEventArgs :
    Windows::IInspectable,
    impl::consume<ISystemMediaTransportControlsButtonPressedEventArgs>
{
    ISystemMediaTransportControlsButtonPressedEventArgs(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<ISystemMediaTransportControlsButtonPressedEventArgs>(m_ptr); }
};

struct ISystemMediaTransportControlsDisplayUpdater :
    Windows::IInspectable,
    impl::consume<ISystemMediaTransportControlsDisplayUpdater>
{
    ISystemMediaTransportControlsDisplayUpdater(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<ISystemMediaTransportControlsDisplayUpdater>(m_ptr); }
};

struct ISystemMediaTransportControlsPropertyChangedEventArgs :
    Windows::IInspectable,
    impl::consume<ISystemMediaTransportControlsPropertyChangedEventArgs>
{
    ISystemMediaTransportControlsPropertyChangedEventArgs(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<ISystemMediaTransportControlsPropertyChangedEventArgs>(m_ptr); }
};

struct ISystemMediaTransportControlsStatics :
    Windows::IInspectable,
    impl::consume<ISystemMediaTransportControlsStatics>
{
    ISystemMediaTransportControlsStatics(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<ISystemMediaTransportControlsStatics>(m_ptr); }
};

struct ISystemMediaTransportControlsTimelineProperties :
    Windows::IInspectable,
    impl::consume<ISystemMediaTransportControlsTimelineProperties>
{
    ISystemMediaTransportControlsTimelineProperties(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<ISystemMediaTransportControlsTimelineProperties>(m_ptr); }
};

struct IVideoDisplayProperties :
    Windows::IInspectable,
    impl::consume<IVideoDisplayProperties>
{
    IVideoDisplayProperties(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IVideoDisplayProperties>(m_ptr); }
};

struct IVideoDisplayProperties2 :
    Windows::IInspectable,
    impl::consume<IVideoDisplayProperties2>
{
    IVideoDisplayProperties2(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IVideoDisplayProperties2>(m_ptr); }
};

struct IVideoEffectsStatics :
    Windows::IInspectable,
    impl::consume<IVideoEffectsStatics>
{
    IVideoEffectsStatics(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IVideoEffectsStatics>(m_ptr); }
};

struct IVideoFrame :
    Windows::IInspectable,
    impl::consume<IVideoFrame>,
    impl::require<IVideoFrame, Windows::Foundation::IClosable, Windows::Media::IMediaFrame>
{
    IVideoFrame(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IVideoFrame>(m_ptr); }
};

struct IVideoFrameFactory :
    Windows::IInspectable,
    impl::consume<IVideoFrameFactory>
{
    IVideoFrameFactory(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IVideoFrameFactory>(m_ptr); }
};

}

}
