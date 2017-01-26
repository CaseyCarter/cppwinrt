// C++ for the Windows Runtime v1.0.private
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "Windows.Media.MediaProperties.1.h"

WINRT_EXPORT namespace winrt {

namespace ABI::Windows::Foundation::Collections {

#ifndef WINRT_GENERIC_5ee3189c_7dbf_5998_ad07_5414fb82567c
#define WINRT_GENERIC_5ee3189c_7dbf_5998_ad07_5414fb82567c
template <> struct __declspec(uuid("5ee3189c-7dbf-5998-ad07-5414fb82567c")) __declspec(novtable) IMap<GUID, Windows::IInspectable> : impl_IMap<GUID, Windows::IInspectable> {};
#endif

#ifndef WINRT_GENERIC_3bda1540_d089_5a1a_8f0d_94eba8068e58
#define WINRT_GENERIC_3bda1540_d089_5a1a_8f0d_94eba8068e58
template <> struct __declspec(uuid("3bda1540-d089-5a1a-8f0d-94eba8068e58")) __declspec(novtable) IKeyValuePair<GUID, Windows::IInspectable> : impl_IKeyValuePair<GUID, Windows::IInspectable> {};
#endif


}

namespace ABI::Windows::Foundation {

#ifndef WINRT_GENERIC_d4f86f16_c6cf_57c8_9743_5ec20c31ab79
#define WINRT_GENERIC_d4f86f16_c6cf_57c8_9743_5ec20c31ab79
template <> struct __declspec(uuid("d4f86f16-c6cf-57c8-9743-5ec20c31ab79")) __declspec(novtable) IAsyncOperation<Windows::Media::MediaProperties::MediaEncodingProfile> : impl_IAsyncOperation<Windows::Media::MediaProperties::MediaEncodingProfile> {};
#endif


}

namespace ABI::Windows::Foundation::Collections {

#ifndef WINRT_GENERIC_e4d2c732_bbc1_5ef4_869f_5007ceb55f6e
#define WINRT_GENERIC_e4d2c732_bbc1_5ef4_869f_5007ceb55f6e
template <> struct __declspec(uuid("e4d2c732-bbc1-5ef4-869f-5007ceb55f6e")) __declspec(novtable) IMapView<GUID, Windows::IInspectable> : impl_IMapView<GUID, Windows::IInspectable> {};
#endif


}

namespace ABI::Windows::Foundation {

#ifndef WINRT_GENERIC_37296fc1_86da_58a0_90c0_c807bd94395e
#define WINRT_GENERIC_37296fc1_86da_58a0_90c0_c807bd94395e
template <> struct __declspec(uuid("37296fc1-86da-58a0-90c0-c807bd94395e")) __declspec(novtable) AsyncOperationCompletedHandler<Windows::Media::MediaProperties::MediaEncodingProfile> : impl_AsyncOperationCompletedHandler<Windows::Media::MediaProperties::MediaEncodingProfile> {};
#endif


}

namespace ABI::Windows::Foundation::Collections {

#ifndef WINRT_GENERIC_f3b20528_e3b3_5331_b2d0_0c2623aee785
#define WINRT_GENERIC_f3b20528_e3b3_5331_b2d0_0c2623aee785
template <> struct __declspec(uuid("f3b20528-e3b3-5331-b2d0-0c2623aee785")) __declspec(novtable) IIterable<Windows::Foundation::Collections::IKeyValuePair<GUID, Windows::IInspectable>> : impl_IIterable<Windows::Foundation::Collections::IKeyValuePair<GUID, Windows::IInspectable>> {};
#endif

#ifndef WINRT_GENERIC_4f25059a_0b9a_5f25_9b9e_4b9f1d22ff65
#define WINRT_GENERIC_4f25059a_0b9a_5f25_9b9e_4b9f1d22ff65
template <> struct __declspec(uuid("4f25059a-0b9a-5f25-9b9e-4b9f1d22ff65")) __declspec(novtable) IIterator<Windows::Foundation::Collections::IKeyValuePair<GUID, Windows::IInspectable>> : impl_IIterator<Windows::Foundation::Collections::IKeyValuePair<GUID, Windows::IInspectable>> {};
#endif


}

namespace Windows::Media::MediaProperties {

struct IAudioEncodingProperties :
    Windows::IInspectable,
    impl::consume<IAudioEncodingProperties>,
    impl::require<IAudioEncodingProperties, Windows::Media::MediaProperties::IMediaEncodingProperties>
{
    IAudioEncodingProperties(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IAudioEncodingProperties>(m_ptr); }
};

struct IAudioEncodingPropertiesStatics :
    Windows::IInspectable,
    impl::consume<IAudioEncodingPropertiesStatics>
{
    IAudioEncodingPropertiesStatics(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IAudioEncodingPropertiesStatics>(m_ptr); }
};

struct IAudioEncodingPropertiesWithFormatUserData :
    Windows::IInspectable,
    impl::consume<IAudioEncodingPropertiesWithFormatUserData>
{
    IAudioEncodingPropertiesWithFormatUserData(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IAudioEncodingPropertiesWithFormatUserData>(m_ptr); }
};

struct IContainerEncodingProperties :
    Windows::IInspectable,
    impl::consume<IContainerEncodingProperties>,
    impl::require<IContainerEncodingProperties, Windows::Media::MediaProperties::IMediaEncodingProperties>
{
    IContainerEncodingProperties(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IContainerEncodingProperties>(m_ptr); }
};

struct IH264ProfileIdsStatics :
    Windows::IInspectable,
    impl::consume<IH264ProfileIdsStatics>
{
    IH264ProfileIdsStatics(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IH264ProfileIdsStatics>(m_ptr); }
};

struct IImageEncodingProperties :
    Windows::IInspectable,
    impl::consume<IImageEncodingProperties>,
    impl::require<IImageEncodingProperties, Windows::Media::MediaProperties::IMediaEncodingProperties>
{
    IImageEncodingProperties(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IImageEncodingProperties>(m_ptr); }
};

struct IImageEncodingPropertiesStatics :
    Windows::IInspectable,
    impl::consume<IImageEncodingPropertiesStatics>
{
    IImageEncodingPropertiesStatics(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IImageEncodingPropertiesStatics>(m_ptr); }
};

struct IImageEncodingPropertiesStatics2 :
    Windows::IInspectable,
    impl::consume<IImageEncodingPropertiesStatics2>
{
    IImageEncodingPropertiesStatics2(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IImageEncodingPropertiesStatics2>(m_ptr); }
};

struct IMediaEncodingProfile :
    Windows::IInspectable,
    impl::consume<IMediaEncodingProfile>
{
    IMediaEncodingProfile(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IMediaEncodingProfile>(m_ptr); }
};

struct IMediaEncodingProfileStatics :
    Windows::IInspectable,
    impl::consume<IMediaEncodingProfileStatics>
{
    IMediaEncodingProfileStatics(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IMediaEncodingProfileStatics>(m_ptr); }
};

struct IMediaEncodingProfileStatics2 :
    Windows::IInspectable,
    impl::consume<IMediaEncodingProfileStatics2>
{
    IMediaEncodingProfileStatics2(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IMediaEncodingProfileStatics2>(m_ptr); }
};

struct IMediaEncodingProperties :
    Windows::IInspectable,
    impl::consume<IMediaEncodingProperties>
{
    IMediaEncodingProperties(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IMediaEncodingProperties>(m_ptr); }
};

struct IMediaEncodingSubtypesStatics :
    Windows::IInspectable,
    impl::consume<IMediaEncodingSubtypesStatics>
{
    IMediaEncodingSubtypesStatics(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IMediaEncodingSubtypesStatics>(m_ptr); }
};

struct IMediaRatio :
    Windows::IInspectable,
    impl::consume<IMediaRatio>
{
    IMediaRatio(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IMediaRatio>(m_ptr); }
};

struct IMpeg2ProfileIdsStatics :
    Windows::IInspectable,
    impl::consume<IMpeg2ProfileIdsStatics>
{
    IMpeg2ProfileIdsStatics(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IMpeg2ProfileIdsStatics>(m_ptr); }
};

struct IVideoEncodingProperties :
    Windows::IInspectable,
    impl::consume<IVideoEncodingProperties>,
    impl::require<IVideoEncodingProperties, Windows::Media::MediaProperties::IMediaEncodingProperties>
{
    IVideoEncodingProperties(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IVideoEncodingProperties>(m_ptr); }
};

struct IVideoEncodingProperties2 :
    Windows::IInspectable,
    impl::consume<IVideoEncodingProperties2>
{
    IVideoEncodingProperties2(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IVideoEncodingProperties2>(m_ptr); }
};

struct IVideoEncodingProperties3 :
    Windows::IInspectable,
    impl::consume<IVideoEncodingProperties3>
{
    IVideoEncodingProperties3(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IVideoEncodingProperties3>(m_ptr); }
};

struct IVideoEncodingPropertiesStatics :
    Windows::IInspectable,
    impl::consume<IVideoEncodingPropertiesStatics>
{
    IVideoEncodingPropertiesStatics(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IVideoEncodingPropertiesStatics>(m_ptr); }
};

}

}
