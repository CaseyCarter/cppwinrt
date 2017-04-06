// C++ for the Windows Runtime v1.0.private
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "Windows.ApplicationModel.Calls.1.h"

WINRT_EXPORT namespace winrt {

namespace ABI::Windows::Foundation {

#ifndef WINRT_GENERIC_1e00c6cc_e14c_51ce_93f3_0a0a9a3f3eec
#define WINRT_GENERIC_1e00c6cc_e14c_51ce_93f3_0a0a9a3f3eec
template <> struct __declspec(uuid("1e00c6cc-e14c-51ce-93f3-0a0a9a3f3eec")) __declspec(novtable) TypedEventHandler<Windows::ApplicationModel::Calls::VoipPhoneCall, Windows::ApplicationModel::Calls::CallStateChangeEventArgs> : impl_TypedEventHandler<Windows::ApplicationModel::Calls::VoipPhoneCall, Windows::ApplicationModel::Calls::CallStateChangeEventArgs> {};
#endif

#ifndef WINRT_GENERIC_d47be4da_c00c_5faa_bfa5_1b11e0c3ccc1
#define WINRT_GENERIC_d47be4da_c00c_5faa_bfa5_1b11e0c3ccc1
template <> struct __declspec(uuid("d47be4da-c00c-5faa-bfa5-1b11e0c3ccc1")) __declspec(novtable) TypedEventHandler<Windows::ApplicationModel::Calls::VoipPhoneCall, Windows::ApplicationModel::Calls::CallAnswerEventArgs> : impl_TypedEventHandler<Windows::ApplicationModel::Calls::VoipPhoneCall, Windows::ApplicationModel::Calls::CallAnswerEventArgs> {};
#endif

#ifndef WINRT_GENERIC_d06255ce_0967_5441_8fe6_ed2e7008197e
#define WINRT_GENERIC_d06255ce_0967_5441_8fe6_ed2e7008197e
template <> struct __declspec(uuid("d06255ce-0967-5441-8fe6-ed2e7008197e")) __declspec(novtable) TypedEventHandler<Windows::ApplicationModel::Calls::VoipPhoneCall, Windows::ApplicationModel::Calls::CallRejectEventArgs> : impl_TypedEventHandler<Windows::ApplicationModel::Calls::VoipPhoneCall, Windows::ApplicationModel::Calls::CallRejectEventArgs> {};
#endif

#ifndef WINRT_GENERIC_8528be80_7ce9_5668_8e48_469ae5ba9ead
#define WINRT_GENERIC_8528be80_7ce9_5668_8e48_469ae5ba9ead
template <> struct __declspec(uuid("8528be80-7ce9-5668-8e48-469ae5ba9ead")) __declspec(novtable) IAsyncOperation<winrt::Windows::ApplicationModel::Calls::VoipPhoneCallResourceReservationStatus> : impl_IAsyncOperation<winrt::Windows::ApplicationModel::Calls::VoipPhoneCallResourceReservationStatus> {};
#endif

#ifndef WINRT_GENERIC_ecafec77_4bf6_57b7_86c6_e2feca5b5aee
#define WINRT_GENERIC_ecafec77_4bf6_57b7_86c6_e2feca5b5aee
template <> struct __declspec(uuid("ecafec77-4bf6-57b7-86c6-e2feca5b5aee")) __declspec(novtable) TypedEventHandler<Windows::ApplicationModel::Calls::VoipCallCoordinator, Windows::ApplicationModel::Calls::MuteChangeEventArgs> : impl_TypedEventHandler<Windows::ApplicationModel::Calls::VoipCallCoordinator, Windows::ApplicationModel::Calls::MuteChangeEventArgs> {};
#endif

#ifndef WINRT_GENERIC_ef60385f_be78_584b_aaef_7829ada2b0de
#define WINRT_GENERIC_ef60385f_be78_584b_aaef_7829ada2b0de
template <> struct __declspec(uuid("ef60385f-be78-584b-aaef-7829ada2b0de")) __declspec(novtable) IAsyncOperation<uint32_t> : impl_IAsyncOperation<uint32_t> {};
#endif


}

namespace ABI::Windows::Foundation::Collections {

#ifndef WINRT_GENERIC_e2fcc7c1_3bfc_5a0b_b2b0_72e769d1cb7e
#define WINRT_GENERIC_e2fcc7c1_3bfc_5a0b_b2b0_72e769d1cb7e
template <> struct __declspec(uuid("e2fcc7c1-3bfc-5a0b-b2b0-72e769d1cb7e")) __declspec(novtable) IIterable<hstring> : impl_IIterable<hstring> {};
#endif

#ifndef WINRT_GENERIC_2f13c006_a03a_5f69_b090_75a43e33423e
#define WINRT_GENERIC_2f13c006_a03a_5f69_b090_75a43e33423e
template <> struct __declspec(uuid("2f13c006-a03a-5f69-b090-75a43e33423e")) __declspec(novtable) IVectorView<hstring> : impl_IVectorView<hstring> {};
#endif

#ifndef WINRT_GENERIC_98b9acc1_4b56_532e_ac73_03d5291cca90
#define WINRT_GENERIC_98b9acc1_4b56_532e_ac73_03d5291cca90
template <> struct __declspec(uuid("98b9acc1-4b56-532e-ac73-03d5291cca90")) __declspec(novtable) IVector<hstring> : impl_IVector<hstring> {};
#endif


}

namespace ABI::Windows::Foundation {

#ifndef WINRT_GENERIC_604d0c4c_91de_5c2a_935f_362f13eaf800
#define WINRT_GENERIC_604d0c4c_91de_5c2a_935f_362f13eaf800
template <> struct __declspec(uuid("604d0c4c-91de-5c2a-935f-362f13eaf800")) __declspec(novtable) IReference<Windows::Foundation::TimeSpan> : impl_IReference<Windows::Foundation::TimeSpan> {};
#endif


}

namespace ABI::Windows::Foundation::Collections {

#ifndef WINRT_GENERIC_452ce6ed_a06d_58fb_be06_cb4330b7f5c7
#define WINRT_GENERIC_452ce6ed_a06d_58fb_be06_cb4330b7f5c7
template <> struct __declspec(uuid("452ce6ed-a06d-58fb-be06-cb4330b7f5c7")) __declspec(novtable) IVectorView<Windows::ApplicationModel::Calls::PhoneCallHistoryEntry> : impl_IVectorView<Windows::ApplicationModel::Calls::PhoneCallHistoryEntry> {};
#endif


}

namespace ABI::Windows::Foundation {

#ifndef WINRT_GENERIC_785e7cca_90e2_5d03_8f23_b3358d09c951
#define WINRT_GENERIC_785e7cca_90e2_5d03_8f23_b3358d09c951
template <> struct __declspec(uuid("785e7cca-90e2-5d03-8f23-b3358d09c951")) __declspec(novtable) IAsyncOperation<Windows::ApplicationModel::Calls::PhoneCallHistoryEntry> : impl_IAsyncOperation<Windows::ApplicationModel::Calls::PhoneCallHistoryEntry> {};
#endif


}

namespace ABI::Windows::Foundation::Collections {

#ifndef WINRT_GENERIC_a3f93eea_c846_52c7_aa5a_3306707f6369
#define WINRT_GENERIC_a3f93eea_c846_52c7_aa5a_3306707f6369
template <> struct __declspec(uuid("a3f93eea-c846-52c7-aa5a-3306707f6369")) __declspec(novtable) IIterable<Windows::ApplicationModel::Calls::PhoneCallHistoryEntry> : impl_IIterable<Windows::ApplicationModel::Calls::PhoneCallHistoryEntry> {};
#endif


}

namespace ABI::Windows::Foundation {

#ifndef WINRT_GENERIC_0d9a97b0_8796_52bf_80da_b1435fe64a26
#define WINRT_GENERIC_0d9a97b0_8796_52bf_80da_b1435fe64a26
template <> struct __declspec(uuid("0d9a97b0-8796-52bf-80da-b1435fe64a26")) __declspec(novtable) IAsyncOperation<Windows::ApplicationModel::Calls::PhoneCallHistoryStore> : impl_IAsyncOperation<Windows::ApplicationModel::Calls::PhoneCallHistoryStore> {};
#endif

#ifndef WINRT_GENERIC_7a27b20f_647a_53fc_80f0_a79d083ce531
#define WINRT_GENERIC_7a27b20f_647a_53fc_80f0_a79d083ce531
template <> struct __declspec(uuid("7a27b20f-647a-53fc-80f0-a79d083ce531")) __declspec(novtable) AsyncOperationCompletedHandler<winrt::Windows::ApplicationModel::Calls::VoipPhoneCallResourceReservationStatus> : impl_AsyncOperationCompletedHandler<winrt::Windows::ApplicationModel::Calls::VoipPhoneCallResourceReservationStatus> {};
#endif

#ifndef WINRT_GENERIC_9343b6e7_e3d2_5e4a_ab2d_2bce4919a6a4
#define WINRT_GENERIC_9343b6e7_e3d2_5e4a_ab2d_2bce4919a6a4
template <> struct __declspec(uuid("9343b6e7-e3d2-5e4a-ab2d-2bce4919a6a4")) __declspec(novtable) AsyncOperationCompletedHandler<uint32_t> : impl_AsyncOperationCompletedHandler<uint32_t> {};
#endif


}

namespace ABI::Windows::Foundation::Collections {

#ifndef WINRT_GENERIC_8c304ebb_6615_50a4_8829_879ecd443236
#define WINRT_GENERIC_8c304ebb_6615_50a4_8829_879ecd443236
template <> struct __declspec(uuid("8c304ebb-6615-50a4-8829-879ecd443236")) __declspec(novtable) IIterator<hstring> : impl_IIterator<hstring> {};
#endif

#ifndef WINRT_GENERIC_569f74f9_1abc_53ab_aa2c_2d97f04fcc12
#define WINRT_GENERIC_569f74f9_1abc_53ab_aa2c_2d97f04fcc12
template <> struct __declspec(uuid("569f74f9-1abc-53ab-aa2c-2d97f04fcc12")) __declspec(novtable) IVector<Windows::ApplicationModel::Calls::PhoneCallHistoryEntry> : impl_IVector<Windows::ApplicationModel::Calls::PhoneCallHistoryEntry> {};
#endif

#ifndef WINRT_GENERIC_c1cf3870_064a_54d5_afab_d1dc4ee26ccb
#define WINRT_GENERIC_c1cf3870_064a_54d5_afab_d1dc4ee26ccb
template <> struct __declspec(uuid("c1cf3870-064a-54d5-afab-d1dc4ee26ccb")) __declspec(novtable) IIterator<Windows::ApplicationModel::Calls::PhoneCallHistoryEntry> : impl_IIterator<Windows::ApplicationModel::Calls::PhoneCallHistoryEntry> {};
#endif


}

namespace ABI::Windows::Foundation {

#ifndef WINRT_GENERIC_3234244b_abee_561d_b247_79b832822055
#define WINRT_GENERIC_3234244b_abee_561d_b247_79b832822055
template <> struct __declspec(uuid("3234244b-abee-561d-b247-79b832822055")) __declspec(novtable) AsyncOperationCompletedHandler<Windows::ApplicationModel::Calls::PhoneCallHistoryEntry> : impl_AsyncOperationCompletedHandler<Windows::ApplicationModel::Calls::PhoneCallHistoryEntry> {};
#endif

#ifndef WINRT_GENERIC_226a138b_79ea_56d3_adc2_a40db8d8c9b0
#define WINRT_GENERIC_226a138b_79ea_56d3_adc2_a40db8d8c9b0
template <> struct __declspec(uuid("226a138b-79ea-56d3-adc2-a40db8d8c9b0")) __declspec(novtable) AsyncOperationCompletedHandler<Windows::ApplicationModel::Calls::PhoneCallHistoryStore> : impl_AsyncOperationCompletedHandler<Windows::ApplicationModel::Calls::PhoneCallHistoryStore> {};
#endif

#ifndef WINRT_GENERIC_2258b912_eb70_5361_b20a_731e15bb9097
#define WINRT_GENERIC_2258b912_eb70_5361_b20a_731e15bb9097
template <> struct __declspec(uuid("2258b912-eb70-5361-b20a-731e15bb9097")) __declspec(novtable) IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::ApplicationModel::Calls::PhoneCallHistoryEntry>> : impl_IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::ApplicationModel::Calls::PhoneCallHistoryEntry>> {};
#endif

#ifndef WINRT_GENERIC_1ef6a805_fd84_5756_a180_353dd72db275
#define WINRT_GENERIC_1ef6a805_fd84_5756_a180_353dd72db275
template <> struct __declspec(uuid("1ef6a805-fd84-5756-a180-353dd72db275")) __declspec(novtable) AsyncOperationCompletedHandler<Windows::Foundation::Collections::IVectorView<Windows::ApplicationModel::Calls::PhoneCallHistoryEntry>> : impl_AsyncOperationCompletedHandler<Windows::Foundation::Collections::IVectorView<Windows::ApplicationModel::Calls::PhoneCallHistoryEntry>> {};
#endif


}

namespace Windows::ApplicationModel::Calls {

struct ICallAnswerEventArgs :
    Windows::Foundation::IInspectable,
    impl::consume<ICallAnswerEventArgs>
{
    ICallAnswerEventArgs(std::nullptr_t = nullptr) noexcept {}
};

struct ICallRejectEventArgs :
    Windows::Foundation::IInspectable,
    impl::consume<ICallRejectEventArgs>
{
    ICallRejectEventArgs(std::nullptr_t = nullptr) noexcept {}
};

struct ICallStateChangeEventArgs :
    Windows::Foundation::IInspectable,
    impl::consume<ICallStateChangeEventArgs>
{
    ICallStateChangeEventArgs(std::nullptr_t = nullptr) noexcept {}
};

struct IMuteChangeEventArgs :
    Windows::Foundation::IInspectable,
    impl::consume<IMuteChangeEventArgs>
{
    IMuteChangeEventArgs(std::nullptr_t = nullptr) noexcept {}
};

struct IPhoneCallHistoryEntry :
    Windows::Foundation::IInspectable,
    impl::consume<IPhoneCallHistoryEntry>
{
    IPhoneCallHistoryEntry(std::nullptr_t = nullptr) noexcept {}
};

struct IPhoneCallHistoryEntryAddress :
    Windows::Foundation::IInspectable,
    impl::consume<IPhoneCallHistoryEntryAddress>
{
    IPhoneCallHistoryEntryAddress(std::nullptr_t = nullptr) noexcept {}
};

struct IPhoneCallHistoryEntryAddressFactory :
    Windows::Foundation::IInspectable,
    impl::consume<IPhoneCallHistoryEntryAddressFactory>
{
    IPhoneCallHistoryEntryAddressFactory(std::nullptr_t = nullptr) noexcept {}
};

struct IPhoneCallHistoryEntryQueryOptions :
    Windows::Foundation::IInspectable,
    impl::consume<IPhoneCallHistoryEntryQueryOptions>
{
    IPhoneCallHistoryEntryQueryOptions(std::nullptr_t = nullptr) noexcept {}
};

struct IPhoneCallHistoryEntryReader :
    Windows::Foundation::IInspectable,
    impl::consume<IPhoneCallHistoryEntryReader>
{
    IPhoneCallHistoryEntryReader(std::nullptr_t = nullptr) noexcept {}
};

struct IPhoneCallHistoryManagerForUser :
    Windows::Foundation::IInspectable,
    impl::consume<IPhoneCallHistoryManagerForUser>
{
    IPhoneCallHistoryManagerForUser(std::nullptr_t = nullptr) noexcept {}
};

struct IPhoneCallHistoryManagerStatics :
    Windows::Foundation::IInspectable,
    impl::consume<IPhoneCallHistoryManagerStatics>
{
    IPhoneCallHistoryManagerStatics(std::nullptr_t = nullptr) noexcept {}
};

struct IPhoneCallHistoryManagerStatics2 :
    Windows::Foundation::IInspectable,
    impl::consume<IPhoneCallHistoryManagerStatics2>
{
    IPhoneCallHistoryManagerStatics2(std::nullptr_t = nullptr) noexcept {}
};

struct IPhoneCallHistoryStore :
    Windows::Foundation::IInspectable,
    impl::consume<IPhoneCallHistoryStore>
{
    IPhoneCallHistoryStore(std::nullptr_t = nullptr) noexcept {}
};

struct IVoipCallCoordinator :
    Windows::Foundation::IInspectable,
    impl::consume<IVoipCallCoordinator>
{
    IVoipCallCoordinator(std::nullptr_t = nullptr) noexcept {}
};

struct IVoipCallCoordinatorStatics :
    Windows::Foundation::IInspectable,
    impl::consume<IVoipCallCoordinatorStatics>
{
    IVoipCallCoordinatorStatics(std::nullptr_t = nullptr) noexcept {}
};

struct IVoipPhoneCall :
    Windows::Foundation::IInspectable,
    impl::consume<IVoipPhoneCall>
{
    IVoipPhoneCall(std::nullptr_t = nullptr) noexcept {}
};

}

}
