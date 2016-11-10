// C++ for the Windows Runtime v1.0.private
// Copyright (c) 2016 Microsoft Corporation. All rights reserved.

#pragma once

#include "../base.h"
#include "Windows.ApplicationModel.Calls.0.h"
#include "Windows.Foundation.0.h"
#include "Windows.System.0.h"
#include "Windows.Foundation.1.h"
#include "Windows.Foundation.Collections.1.h"

WINRT_EXPORT namespace winrt {

namespace ABI::Windows::ApplicationModel::Calls {

struct __declspec(uuid("fd789617-2dd7-4c8c-b2bd-95d17a5bb733")) __declspec(novtable) ICallAnswerEventArgs : Windows::IInspectable
{
    virtual HRESULT __stdcall get_AcceptedMedia(winrt::Windows::ApplicationModel::Calls::VoipPhoneCallMedia * value) = 0;
};

struct __declspec(uuid("da47fad7-13d4-4d92-a1c2-b77811ee37ec")) __declspec(novtable) ICallRejectEventArgs : Windows::IInspectable
{
    virtual HRESULT __stdcall get_RejectReason(winrt::Windows::ApplicationModel::Calls::VoipPhoneCallRejectReason * value) = 0;
};

struct __declspec(uuid("eab2349e-66f5-47f9-9fb5-459c5198c720")) __declspec(novtable) ICallStateChangeEventArgs : Windows::IInspectable
{
    virtual HRESULT __stdcall get_State(winrt::Windows::ApplicationModel::Calls::VoipPhoneCallState * value) = 0;
};

struct __declspec(uuid("8585e159-0c41-432c-814d-c5f1fdf530be")) __declspec(novtable) IMuteChangeEventArgs : Windows::IInspectable
{
    virtual HRESULT __stdcall get_Muted(bool * value) = 0;
};

struct __declspec(uuid("fab0e129-32a4-4b85-83d1-f90d8c23a857")) __declspec(novtable) IPhoneCallHistoryEntry : Windows::IInspectable
{
    virtual HRESULT __stdcall get_Id(hstring * value) = 0;
    virtual HRESULT __stdcall get_Address(Windows::ApplicationModel::Calls::IPhoneCallHistoryEntryAddress ** value) = 0;
    virtual HRESULT __stdcall put_Address(Windows::ApplicationModel::Calls::IPhoneCallHistoryEntryAddress * value) = 0;
    virtual HRESULT __stdcall get_Duration(Windows::Foundation::IReference<Windows::Foundation::TimeSpan> ** value) = 0;
    virtual HRESULT __stdcall put_Duration(Windows::Foundation::IReference<Windows::Foundation::TimeSpan> * value) = 0;
    virtual HRESULT __stdcall get_IsCallerIdBlocked(bool * value) = 0;
    virtual HRESULT __stdcall put_IsCallerIdBlocked(bool value) = 0;
    virtual HRESULT __stdcall get_IsEmergency(bool * value) = 0;
    virtual HRESULT __stdcall put_IsEmergency(bool value) = 0;
    virtual HRESULT __stdcall get_IsIncoming(bool * value) = 0;
    virtual HRESULT __stdcall put_IsIncoming(bool value) = 0;
    virtual HRESULT __stdcall get_IsMissed(bool * value) = 0;
    virtual HRESULT __stdcall put_IsMissed(bool value) = 0;
    virtual HRESULT __stdcall get_IsRinging(bool * value) = 0;
    virtual HRESULT __stdcall put_IsRinging(bool value) = 0;
    virtual HRESULT __stdcall get_IsSeen(bool * value) = 0;
    virtual HRESULT __stdcall put_IsSeen(bool value) = 0;
    virtual HRESULT __stdcall get_IsSuppressed(bool * value) = 0;
    virtual HRESULT __stdcall put_IsSuppressed(bool value) = 0;
    virtual HRESULT __stdcall get_IsVoicemail(bool * value) = 0;
    virtual HRESULT __stdcall put_IsVoicemail(bool value) = 0;
    virtual HRESULT __stdcall get_Media(winrt::Windows::ApplicationModel::Calls::PhoneCallHistoryEntryMedia * value) = 0;
    virtual HRESULT __stdcall put_Media(winrt::Windows::ApplicationModel::Calls::PhoneCallHistoryEntryMedia value) = 0;
    virtual HRESULT __stdcall get_OtherAppReadAccess(winrt::Windows::ApplicationModel::Calls::PhoneCallHistoryEntryOtherAppReadAccess * value) = 0;
    virtual HRESULT __stdcall put_OtherAppReadAccess(winrt::Windows::ApplicationModel::Calls::PhoneCallHistoryEntryOtherAppReadAccess value) = 0;
    virtual HRESULT __stdcall get_RemoteId(hstring * value) = 0;
    virtual HRESULT __stdcall put_RemoteId(hstring value) = 0;
    virtual HRESULT __stdcall get_SourceDisplayName(hstring * value) = 0;
    virtual HRESULT __stdcall get_SourceId(hstring * value) = 0;
    virtual HRESULT __stdcall put_SourceId(hstring value) = 0;
    virtual HRESULT __stdcall get_SourceIdKind(winrt::Windows::ApplicationModel::Calls::PhoneCallHistorySourceIdKind * value) = 0;
    virtual HRESULT __stdcall put_SourceIdKind(winrt::Windows::ApplicationModel::Calls::PhoneCallHistorySourceIdKind value) = 0;
    virtual HRESULT __stdcall get_StartTime(Windows::Foundation::DateTime * value) = 0;
    virtual HRESULT __stdcall put_StartTime(Windows::Foundation::DateTime value) = 0;
};

struct __declspec(uuid("30f159da-3955-4042-84e6-66eebf82e67f")) __declspec(novtable) IPhoneCallHistoryEntryAddress : Windows::IInspectable
{
    virtual HRESULT __stdcall get_ContactId(hstring * value) = 0;
    virtual HRESULT __stdcall put_ContactId(hstring value) = 0;
    virtual HRESULT __stdcall get_DisplayName(hstring * value) = 0;
    virtual HRESULT __stdcall put_DisplayName(hstring value) = 0;
    virtual HRESULT __stdcall get_RawAddress(hstring * value) = 0;
    virtual HRESULT __stdcall put_RawAddress(hstring value) = 0;
    virtual HRESULT __stdcall get_RawAddressKind(winrt::Windows::ApplicationModel::Calls::PhoneCallHistoryEntryRawAddressKind * value) = 0;
    virtual HRESULT __stdcall put_RawAddressKind(winrt::Windows::ApplicationModel::Calls::PhoneCallHistoryEntryRawAddressKind value) = 0;
};

struct __declspec(uuid("fb0fadba-c7f0-4bb6-9f6b-ba5d73209aca")) __declspec(novtable) IPhoneCallHistoryEntryAddressFactory : Windows::IInspectable
{
    virtual HRESULT __stdcall abi_Create(hstring rawAddress, winrt::Windows::ApplicationModel::Calls::PhoneCallHistoryEntryRawAddressKind rawAddressKind, Windows::ApplicationModel::Calls::IPhoneCallHistoryEntryAddress ** result) = 0;
};

struct __declspec(uuid("9c5fe15c-8bed-40ca-b06e-c4ca8eae5c87")) __declspec(novtable) IPhoneCallHistoryEntryQueryOptions : Windows::IInspectable
{
    virtual HRESULT __stdcall get_DesiredMedia(winrt::Windows::ApplicationModel::Calls::PhoneCallHistoryEntryQueryDesiredMedia * value) = 0;
    virtual HRESULT __stdcall put_DesiredMedia(winrt::Windows::ApplicationModel::Calls::PhoneCallHistoryEntryQueryDesiredMedia value) = 0;
    virtual HRESULT __stdcall get_SourceIds(Windows::Foundation::Collections::IVector<hstring> ** value) = 0;
};

struct __declspec(uuid("61ece4be-8d86-479f-8404-a9846920fee6")) __declspec(novtable) IPhoneCallHistoryEntryReader : Windows::IInspectable
{
    virtual HRESULT __stdcall abi_ReadBatchAsync(Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::ApplicationModel::Calls::PhoneCallHistoryEntry>> ** result) = 0;
};

struct __declspec(uuid("d925c523-f55f-4353-9db4-0205a5265a55")) __declspec(novtable) IPhoneCallHistoryManagerForUser : Windows::IInspectable
{
    virtual HRESULT __stdcall abi_RequestStoreAsync(winrt::Windows::ApplicationModel::Calls::PhoneCallHistoryStoreAccessType accessType, Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Calls::PhoneCallHistoryStore> ** result) = 0;
    virtual HRESULT __stdcall get_User(Windows::System::IUser ** value) = 0;
};

struct __declspec(uuid("f5a6da39-b31f-4f45-ac8e-1b08893c1b50")) __declspec(novtable) IPhoneCallHistoryManagerStatics : Windows::IInspectable
{
    virtual HRESULT __stdcall abi_RequestStoreAsync(winrt::Windows::ApplicationModel::Calls::PhoneCallHistoryStoreAccessType accessType, Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Calls::PhoneCallHistoryStore> ** result) = 0;
};

struct __declspec(uuid("efd474f0-a2db-4188-9e92-bc3cfa6813cf")) __declspec(novtable) IPhoneCallHistoryManagerStatics2 : Windows::IInspectable
{
    virtual HRESULT __stdcall abi_GetForUser(Windows::System::IUser * user, Windows::ApplicationModel::Calls::IPhoneCallHistoryManagerForUser ** result) = 0;
};

struct __declspec(uuid("2f907db8-b40e-422b-8545-cb1910a61c52")) __declspec(novtable) IPhoneCallHistoryStore : Windows::IInspectable
{
    virtual HRESULT __stdcall abi_GetEntryAsync(hstring callHistoryEntryId, Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Calls::PhoneCallHistoryEntry> ** result) = 0;
    virtual HRESULT __stdcall abi_GetEntryReader(Windows::ApplicationModel::Calls::IPhoneCallHistoryEntryReader ** result) = 0;
    virtual HRESULT __stdcall abi_GetEntryReaderWithOptions(Windows::ApplicationModel::Calls::IPhoneCallHistoryEntryQueryOptions * queryOptions, Windows::ApplicationModel::Calls::IPhoneCallHistoryEntryReader ** result) = 0;
    virtual HRESULT __stdcall abi_SaveEntryAsync(Windows::ApplicationModel::Calls::IPhoneCallHistoryEntry * callHistoryEntry, Windows::Foundation::IAsyncAction ** result) = 0;
    virtual HRESULT __stdcall abi_DeleteEntryAsync(Windows::ApplicationModel::Calls::IPhoneCallHistoryEntry * callHistoryEntry, Windows::Foundation::IAsyncAction ** result) = 0;
    virtual HRESULT __stdcall abi_DeleteEntriesAsync(Windows::Foundation::Collections::IIterable<Windows::ApplicationModel::Calls::PhoneCallHistoryEntry> * callHistoryEntries, Windows::Foundation::IAsyncAction ** result) = 0;
    virtual HRESULT __stdcall abi_MarkEntryAsSeenAsync(Windows::ApplicationModel::Calls::IPhoneCallHistoryEntry * callHistoryEntry, Windows::Foundation::IAsyncAction ** result) = 0;
    virtual HRESULT __stdcall abi_MarkEntriesAsSeenAsync(Windows::Foundation::Collections::IIterable<Windows::ApplicationModel::Calls::PhoneCallHistoryEntry> * callHistoryEntries, Windows::Foundation::IAsyncAction ** result) = 0;
    virtual HRESULT __stdcall abi_GetUnseenCountAsync(Windows::Foundation::IAsyncOperation<uint32_t> ** result) = 0;
    virtual HRESULT __stdcall abi_MarkAllAsSeenAsync(Windows::Foundation::IAsyncAction ** result) = 0;
    virtual HRESULT __stdcall abi_GetSourcesUnseenCountAsync(Windows::Foundation::Collections::IIterable<hstring> * sourceIds, Windows::Foundation::IAsyncOperation<uint32_t> ** result) = 0;
    virtual HRESULT __stdcall abi_MarkSourcesAsSeenAsync(Windows::Foundation::Collections::IIterable<hstring> * sourceIds, Windows::Foundation::IAsyncAction ** result) = 0;
};

struct __declspec(uuid("4f118bcf-e8ef-4434-9c5f-a8d893fafe79")) __declspec(novtable) IVoipCallCoordinator : Windows::IInspectable
{
    virtual HRESULT __stdcall abi_ReserveCallResourcesAsync(hstring taskEntryPoint, Windows::Foundation::IAsyncOperation<winrt::Windows::ApplicationModel::Calls::VoipPhoneCallResourceReservationStatus> ** operation) = 0;
    virtual HRESULT __stdcall add_MuteStateChanged(Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Calls::VoipCallCoordinator, Windows::ApplicationModel::Calls::MuteChangeEventArgs> * muteChangeHandler, event_token * token) = 0;
    virtual HRESULT __stdcall remove_MuteStateChanged(event_token token) = 0;
    virtual HRESULT __stdcall abi_RequestNewIncomingCall(hstring context, hstring contactName, hstring contactNumber, Windows::Foundation::IUriRuntimeClass * contactImage, hstring serviceName, Windows::Foundation::IUriRuntimeClass * brandingImage, hstring callDetails, Windows::Foundation::IUriRuntimeClass * ringtone, winrt::Windows::ApplicationModel::Calls::VoipPhoneCallMedia media, Windows::Foundation::TimeSpan ringTimeout, Windows::ApplicationModel::Calls::IVoipPhoneCall ** call) = 0;
    virtual HRESULT __stdcall abi_RequestNewOutgoingCall(hstring context, hstring contactName, hstring serviceName, winrt::Windows::ApplicationModel::Calls::VoipPhoneCallMedia media, Windows::ApplicationModel::Calls::IVoipPhoneCall ** call) = 0;
    virtual HRESULT __stdcall abi_NotifyMuted() = 0;
    virtual HRESULT __stdcall abi_NotifyUnmuted() = 0;
    virtual HRESULT __stdcall abi_RequestOutgoingUpgradeToVideoCall(GUID callUpgradeGuid, hstring context, hstring contactName, hstring serviceName, Windows::ApplicationModel::Calls::IVoipPhoneCall ** call) = 0;
    virtual HRESULT __stdcall abi_RequestIncomingUpgradeToVideoCall(hstring context, hstring contactName, hstring contactNumber, Windows::Foundation::IUriRuntimeClass * contactImage, hstring serviceName, Windows::Foundation::IUriRuntimeClass * brandingImage, hstring callDetails, Windows::Foundation::IUriRuntimeClass * ringtone, Windows::Foundation::TimeSpan ringTimeout, Windows::ApplicationModel::Calls::IVoipPhoneCall ** call) = 0;
    virtual HRESULT __stdcall abi_TerminateCellularCall(GUID callUpgradeGuid) = 0;
    virtual HRESULT __stdcall abi_CancelUpgrade(GUID callUpgradeGuid) = 0;
};

struct __declspec(uuid("7f5d1f2b-e04a-4d10-b31a-a55c922cc2fb")) __declspec(novtable) IVoipCallCoordinatorStatics : Windows::IInspectable
{
    virtual HRESULT __stdcall abi_GetDefault(Windows::ApplicationModel::Calls::IVoipCallCoordinator ** coordinator) = 0;
};

struct __declspec(uuid("6cf1f19a-7794-4a5a-8c68-ae87947a6990")) __declspec(novtable) IVoipPhoneCall : Windows::IInspectable
{
    virtual HRESULT __stdcall add_EndRequested(Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Calls::VoipPhoneCall, Windows::ApplicationModel::Calls::CallStateChangeEventArgs> * handler, event_token * token) = 0;
    virtual HRESULT __stdcall remove_EndRequested(event_token token) = 0;
    virtual HRESULT __stdcall add_HoldRequested(Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Calls::VoipPhoneCall, Windows::ApplicationModel::Calls::CallStateChangeEventArgs> * handler, event_token * token) = 0;
    virtual HRESULT __stdcall remove_HoldRequested(event_token token) = 0;
    virtual HRESULT __stdcall add_ResumeRequested(Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Calls::VoipPhoneCall, Windows::ApplicationModel::Calls::CallStateChangeEventArgs> * handler, event_token * token) = 0;
    virtual HRESULT __stdcall remove_ResumeRequested(event_token token) = 0;
    virtual HRESULT __stdcall add_AnswerRequested(Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Calls::VoipPhoneCall, Windows::ApplicationModel::Calls::CallAnswerEventArgs> * acceptHandler, event_token * token) = 0;
    virtual HRESULT __stdcall remove_AnswerRequested(event_token token) = 0;
    virtual HRESULT __stdcall add_RejectRequested(Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Calls::VoipPhoneCall, Windows::ApplicationModel::Calls::CallRejectEventArgs> * rejectHandler, event_token * token) = 0;
    virtual HRESULT __stdcall remove_RejectRequested(event_token token) = 0;
    virtual HRESULT __stdcall abi_NotifyCallHeld() = 0;
    virtual HRESULT __stdcall abi_NotifyCallActive() = 0;
    virtual HRESULT __stdcall abi_NotifyCallEnded() = 0;
    virtual HRESULT __stdcall get_ContactName(hstring * value) = 0;
    virtual HRESULT __stdcall put_ContactName(hstring value) = 0;
    virtual HRESULT __stdcall get_StartTime(Windows::Foundation::DateTime * value) = 0;
    virtual HRESULT __stdcall put_StartTime(Windows::Foundation::DateTime value) = 0;
    virtual HRESULT __stdcall get_CallMedia(winrt::Windows::ApplicationModel::Calls::VoipPhoneCallMedia * value) = 0;
    virtual HRESULT __stdcall put_CallMedia(winrt::Windows::ApplicationModel::Calls::VoipPhoneCallMedia value) = 0;
    virtual HRESULT __stdcall abi_NotifyCallReady() = 0;
};

}

namespace ABI {

template <> struct traits<Windows::ApplicationModel::Calls::CallAnswerEventArgs> { using default_interface = Windows::ApplicationModel::Calls::ICallAnswerEventArgs; };
template <> struct traits<Windows::ApplicationModel::Calls::CallRejectEventArgs> { using default_interface = Windows::ApplicationModel::Calls::ICallRejectEventArgs; };
template <> struct traits<Windows::ApplicationModel::Calls::CallStateChangeEventArgs> { using default_interface = Windows::ApplicationModel::Calls::ICallStateChangeEventArgs; };
template <> struct traits<Windows::ApplicationModel::Calls::MuteChangeEventArgs> { using default_interface = Windows::ApplicationModel::Calls::IMuteChangeEventArgs; };
template <> struct traits<Windows::ApplicationModel::Calls::PhoneCallHistoryEntry> { using default_interface = Windows::ApplicationModel::Calls::IPhoneCallHistoryEntry; };
template <> struct traits<Windows::ApplicationModel::Calls::PhoneCallHistoryEntryAddress> { using default_interface = Windows::ApplicationModel::Calls::IPhoneCallHistoryEntryAddress; };
template <> struct traits<Windows::ApplicationModel::Calls::PhoneCallHistoryEntryQueryOptions> { using default_interface = Windows::ApplicationModel::Calls::IPhoneCallHistoryEntryQueryOptions; };
template <> struct traits<Windows::ApplicationModel::Calls::PhoneCallHistoryEntryReader> { using default_interface = Windows::ApplicationModel::Calls::IPhoneCallHistoryEntryReader; };
template <> struct traits<Windows::ApplicationModel::Calls::PhoneCallHistoryManagerForUser> { using default_interface = Windows::ApplicationModel::Calls::IPhoneCallHistoryManagerForUser; };
template <> struct traits<Windows::ApplicationModel::Calls::PhoneCallHistoryStore> { using default_interface = Windows::ApplicationModel::Calls::IPhoneCallHistoryStore; };
template <> struct traits<Windows::ApplicationModel::Calls::VoipCallCoordinator> { using default_interface = Windows::ApplicationModel::Calls::IVoipCallCoordinator; };
template <> struct traits<Windows::ApplicationModel::Calls::VoipPhoneCall> { using default_interface = Windows::ApplicationModel::Calls::IVoipPhoneCall; };

}

namespace Windows::ApplicationModel::Calls {

template <typename D>
struct WINRT_EBO impl_ICallAnswerEventArgs
{
    Windows::ApplicationModel::Calls::VoipPhoneCallMedia AcceptedMedia() const;
};

template <typename D>
struct WINRT_EBO impl_ICallRejectEventArgs
{
    Windows::ApplicationModel::Calls::VoipPhoneCallRejectReason RejectReason() const;
};

template <typename D>
struct WINRT_EBO impl_ICallStateChangeEventArgs
{
    Windows::ApplicationModel::Calls::VoipPhoneCallState State() const;
};

template <typename D>
struct WINRT_EBO impl_IMuteChangeEventArgs
{
    bool Muted() const;
};

template <typename D>
struct WINRT_EBO impl_IPhoneCallHistoryEntry
{
    hstring Id() const;
    Windows::ApplicationModel::Calls::PhoneCallHistoryEntryAddress Address() const;
    void Address(const Windows::ApplicationModel::Calls::PhoneCallHistoryEntryAddress & value) const;
    Windows::Foundation::IReference<Windows::Foundation::TimeSpan> Duration() const;
    void Duration(const Windows::Foundation::IReference<Windows::Foundation::TimeSpan> & value) const;
    bool IsCallerIdBlocked() const;
    void IsCallerIdBlocked(bool value) const;
    bool IsEmergency() const;
    void IsEmergency(bool value) const;
    bool IsIncoming() const;
    void IsIncoming(bool value) const;
    bool IsMissed() const;
    void IsMissed(bool value) const;
    bool IsRinging() const;
    void IsRinging(bool value) const;
    bool IsSeen() const;
    void IsSeen(bool value) const;
    bool IsSuppressed() const;
    void IsSuppressed(bool value) const;
    bool IsVoicemail() const;
    void IsVoicemail(bool value) const;
    Windows::ApplicationModel::Calls::PhoneCallHistoryEntryMedia Media() const;
    void Media(Windows::ApplicationModel::Calls::PhoneCallHistoryEntryMedia value) const;
    Windows::ApplicationModel::Calls::PhoneCallHistoryEntryOtherAppReadAccess OtherAppReadAccess() const;
    void OtherAppReadAccess(Windows::ApplicationModel::Calls::PhoneCallHistoryEntryOtherAppReadAccess value) const;
    hstring RemoteId() const;
    void RemoteId(hstring_ref value) const;
    hstring SourceDisplayName() const;
    hstring SourceId() const;
    void SourceId(hstring_ref value) const;
    Windows::ApplicationModel::Calls::PhoneCallHistorySourceIdKind SourceIdKind() const;
    void SourceIdKind(Windows::ApplicationModel::Calls::PhoneCallHistorySourceIdKind value) const;
    Windows::Foundation::DateTime StartTime() const;
    void StartTime(const Windows::Foundation::DateTime & value) const;
};

template <typename D>
struct WINRT_EBO impl_IPhoneCallHistoryEntryAddress
{
    hstring ContactId() const;
    void ContactId(hstring_ref value) const;
    hstring DisplayName() const;
    void DisplayName(hstring_ref value) const;
    hstring RawAddress() const;
    void RawAddress(hstring_ref value) const;
    Windows::ApplicationModel::Calls::PhoneCallHistoryEntryRawAddressKind RawAddressKind() const;
    void RawAddressKind(Windows::ApplicationModel::Calls::PhoneCallHistoryEntryRawAddressKind value) const;
};

template <typename D>
struct WINRT_EBO impl_IPhoneCallHistoryEntryAddressFactory
{
    Windows::ApplicationModel::Calls::PhoneCallHistoryEntryAddress Create(hstring_ref rawAddress, Windows::ApplicationModel::Calls::PhoneCallHistoryEntryRawAddressKind rawAddressKind) const;
};

template <typename D>
struct WINRT_EBO impl_IPhoneCallHistoryEntryQueryOptions
{
    Windows::ApplicationModel::Calls::PhoneCallHistoryEntryQueryDesiredMedia DesiredMedia() const;
    void DesiredMedia(Windows::ApplicationModel::Calls::PhoneCallHistoryEntryQueryDesiredMedia value) const;
    Windows::Foundation::Collections::IVector<hstring> SourceIds() const;
};

template <typename D>
struct WINRT_EBO impl_IPhoneCallHistoryEntryReader
{
    Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::ApplicationModel::Calls::PhoneCallHistoryEntry>> ReadBatchAsync() const;
};

template <typename D>
struct WINRT_EBO impl_IPhoneCallHistoryManagerForUser
{
    Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Calls::PhoneCallHistoryStore> RequestStoreAsync(Windows::ApplicationModel::Calls::PhoneCallHistoryStoreAccessType accessType) const;
    Windows::System::User User() const;
};

template <typename D>
struct WINRT_EBO impl_IPhoneCallHistoryManagerStatics
{
    Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Calls::PhoneCallHistoryStore> RequestStoreAsync(Windows::ApplicationModel::Calls::PhoneCallHistoryStoreAccessType accessType) const;
};

template <typename D>
struct WINRT_EBO impl_IPhoneCallHistoryManagerStatics2
{
    Windows::ApplicationModel::Calls::PhoneCallHistoryManagerForUser GetForUser(const Windows::System::User & user) const;
};

template <typename D>
struct WINRT_EBO impl_IPhoneCallHistoryStore
{
    Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Calls::PhoneCallHistoryEntry> GetEntryAsync(hstring_ref callHistoryEntryId) const;
    Windows::ApplicationModel::Calls::PhoneCallHistoryEntryReader GetEntryReader() const;
    Windows::ApplicationModel::Calls::PhoneCallHistoryEntryReader GetEntryReader(const Windows::ApplicationModel::Calls::PhoneCallHistoryEntryQueryOptions & queryOptions) const;
    Windows::Foundation::IAsyncAction SaveEntryAsync(const Windows::ApplicationModel::Calls::PhoneCallHistoryEntry & callHistoryEntry) const;
    Windows::Foundation::IAsyncAction DeleteEntryAsync(const Windows::ApplicationModel::Calls::PhoneCallHistoryEntry & callHistoryEntry) const;
    Windows::Foundation::IAsyncAction DeleteEntriesAsync(const Windows::Foundation::Collections::IIterable<Windows::ApplicationModel::Calls::PhoneCallHistoryEntry> & callHistoryEntries) const;
    Windows::Foundation::IAsyncAction MarkEntryAsSeenAsync(const Windows::ApplicationModel::Calls::PhoneCallHistoryEntry & callHistoryEntry) const;
    Windows::Foundation::IAsyncAction MarkEntriesAsSeenAsync(const Windows::Foundation::Collections::IIterable<Windows::ApplicationModel::Calls::PhoneCallHistoryEntry> & callHistoryEntries) const;
    Windows::Foundation::IAsyncOperation<uint32_t> GetUnseenCountAsync() const;
    Windows::Foundation::IAsyncAction MarkAllAsSeenAsync() const;
    Windows::Foundation::IAsyncOperation<uint32_t> GetSourcesUnseenCountAsync(const Windows::Foundation::Collections::IIterable<hstring> & sourceIds) const;
    Windows::Foundation::IAsyncAction MarkSourcesAsSeenAsync(const Windows::Foundation::Collections::IIterable<hstring> & sourceIds) const;
};

template <typename D>
struct WINRT_EBO impl_IVoipCallCoordinator
{
    Windows::Foundation::IAsyncOperation<winrt::Windows::ApplicationModel::Calls::VoipPhoneCallResourceReservationStatus> ReserveCallResourcesAsync(hstring_ref taskEntryPoint) const;
    event_token MuteStateChanged(const Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Calls::VoipCallCoordinator, Windows::ApplicationModel::Calls::MuteChangeEventArgs> & muteChangeHandler) const;
    using MuteStateChanged_revoker = event_revoker<IVoipCallCoordinator>;
    MuteStateChanged_revoker MuteStateChanged(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Calls::VoipCallCoordinator, Windows::ApplicationModel::Calls::MuteChangeEventArgs> & muteChangeHandler) const;
    void MuteStateChanged(event_token token) const;
    Windows::ApplicationModel::Calls::VoipPhoneCall RequestNewIncomingCall(hstring_ref context, hstring_ref contactName, hstring_ref contactNumber, const Windows::Foundation::Uri & contactImage, hstring_ref serviceName, const Windows::Foundation::Uri & brandingImage, hstring_ref callDetails, const Windows::Foundation::Uri & ringtone, Windows::ApplicationModel::Calls::VoipPhoneCallMedia media, const Windows::Foundation::TimeSpan & ringTimeout) const;
    Windows::ApplicationModel::Calls::VoipPhoneCall RequestNewOutgoingCall(hstring_ref context, hstring_ref contactName, hstring_ref serviceName, Windows::ApplicationModel::Calls::VoipPhoneCallMedia media) const;
    void NotifyMuted() const;
    void NotifyUnmuted() const;
    Windows::ApplicationModel::Calls::VoipPhoneCall RequestOutgoingUpgradeToVideoCall(GUID callUpgradeGuid, hstring_ref context, hstring_ref contactName, hstring_ref serviceName) const;
    Windows::ApplicationModel::Calls::VoipPhoneCall RequestIncomingUpgradeToVideoCall(hstring_ref context, hstring_ref contactName, hstring_ref contactNumber, const Windows::Foundation::Uri & contactImage, hstring_ref serviceName, const Windows::Foundation::Uri & brandingImage, hstring_ref callDetails, const Windows::Foundation::Uri & ringtone, const Windows::Foundation::TimeSpan & ringTimeout) const;
    void TerminateCellularCall(GUID callUpgradeGuid) const;
    void CancelUpgrade(GUID callUpgradeGuid) const;
};

template <typename D>
struct WINRT_EBO impl_IVoipCallCoordinatorStatics
{
    Windows::ApplicationModel::Calls::VoipCallCoordinator GetDefault() const;
};

template <typename D>
struct WINRT_EBO impl_IVoipPhoneCall
{
    event_token EndRequested(const Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Calls::VoipPhoneCall, Windows::ApplicationModel::Calls::CallStateChangeEventArgs> & handler) const;
    using EndRequested_revoker = event_revoker<IVoipPhoneCall>;
    EndRequested_revoker EndRequested(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Calls::VoipPhoneCall, Windows::ApplicationModel::Calls::CallStateChangeEventArgs> & handler) const;
    void EndRequested(event_token token) const;
    event_token HoldRequested(const Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Calls::VoipPhoneCall, Windows::ApplicationModel::Calls::CallStateChangeEventArgs> & handler) const;
    using HoldRequested_revoker = event_revoker<IVoipPhoneCall>;
    HoldRequested_revoker HoldRequested(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Calls::VoipPhoneCall, Windows::ApplicationModel::Calls::CallStateChangeEventArgs> & handler) const;
    void HoldRequested(event_token token) const;
    event_token ResumeRequested(const Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Calls::VoipPhoneCall, Windows::ApplicationModel::Calls::CallStateChangeEventArgs> & handler) const;
    using ResumeRequested_revoker = event_revoker<IVoipPhoneCall>;
    ResumeRequested_revoker ResumeRequested(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Calls::VoipPhoneCall, Windows::ApplicationModel::Calls::CallStateChangeEventArgs> & handler) const;
    void ResumeRequested(event_token token) const;
    event_token AnswerRequested(const Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Calls::VoipPhoneCall, Windows::ApplicationModel::Calls::CallAnswerEventArgs> & acceptHandler) const;
    using AnswerRequested_revoker = event_revoker<IVoipPhoneCall>;
    AnswerRequested_revoker AnswerRequested(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Calls::VoipPhoneCall, Windows::ApplicationModel::Calls::CallAnswerEventArgs> & acceptHandler) const;
    void AnswerRequested(event_token token) const;
    event_token RejectRequested(const Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Calls::VoipPhoneCall, Windows::ApplicationModel::Calls::CallRejectEventArgs> & rejectHandler) const;
    using RejectRequested_revoker = event_revoker<IVoipPhoneCall>;
    RejectRequested_revoker RejectRequested(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Calls::VoipPhoneCall, Windows::ApplicationModel::Calls::CallRejectEventArgs> & rejectHandler) const;
    void RejectRequested(event_token token) const;
    void NotifyCallHeld() const;
    void NotifyCallActive() const;
    void NotifyCallEnded() const;
    hstring ContactName() const;
    void ContactName(hstring_ref value) const;
    Windows::Foundation::DateTime StartTime() const;
    void StartTime(const Windows::Foundation::DateTime & value) const;
    Windows::ApplicationModel::Calls::VoipPhoneCallMedia CallMedia() const;
    void CallMedia(Windows::ApplicationModel::Calls::VoipPhoneCallMedia value) const;
    void NotifyCallReady() const;
};

}

namespace impl {

template <> struct traits<Windows::ApplicationModel::Calls::ICallAnswerEventArgs>
{
    using abi = ABI::Windows::ApplicationModel::Calls::ICallAnswerEventArgs;
    template <typename D> using consume = Windows::ApplicationModel::Calls::impl_ICallAnswerEventArgs<D>;
};

template <> struct traits<Windows::ApplicationModel::Calls::ICallRejectEventArgs>
{
    using abi = ABI::Windows::ApplicationModel::Calls::ICallRejectEventArgs;
    template <typename D> using consume = Windows::ApplicationModel::Calls::impl_ICallRejectEventArgs<D>;
};

template <> struct traits<Windows::ApplicationModel::Calls::ICallStateChangeEventArgs>
{
    using abi = ABI::Windows::ApplicationModel::Calls::ICallStateChangeEventArgs;
    template <typename D> using consume = Windows::ApplicationModel::Calls::impl_ICallStateChangeEventArgs<D>;
};

template <> struct traits<Windows::ApplicationModel::Calls::IMuteChangeEventArgs>
{
    using abi = ABI::Windows::ApplicationModel::Calls::IMuteChangeEventArgs;
    template <typename D> using consume = Windows::ApplicationModel::Calls::impl_IMuteChangeEventArgs<D>;
};

template <> struct traits<Windows::ApplicationModel::Calls::IPhoneCallHistoryEntry>
{
    using abi = ABI::Windows::ApplicationModel::Calls::IPhoneCallHistoryEntry;
    template <typename D> using consume = Windows::ApplicationModel::Calls::impl_IPhoneCallHistoryEntry<D>;
};

template <> struct traits<Windows::ApplicationModel::Calls::IPhoneCallHistoryEntryAddress>
{
    using abi = ABI::Windows::ApplicationModel::Calls::IPhoneCallHistoryEntryAddress;
    template <typename D> using consume = Windows::ApplicationModel::Calls::impl_IPhoneCallHistoryEntryAddress<D>;
};

template <> struct traits<Windows::ApplicationModel::Calls::IPhoneCallHistoryEntryAddressFactory>
{
    using abi = ABI::Windows::ApplicationModel::Calls::IPhoneCallHistoryEntryAddressFactory;
    template <typename D> using consume = Windows::ApplicationModel::Calls::impl_IPhoneCallHistoryEntryAddressFactory<D>;
};

template <> struct traits<Windows::ApplicationModel::Calls::IPhoneCallHistoryEntryQueryOptions>
{
    using abi = ABI::Windows::ApplicationModel::Calls::IPhoneCallHistoryEntryQueryOptions;
    template <typename D> using consume = Windows::ApplicationModel::Calls::impl_IPhoneCallHistoryEntryQueryOptions<D>;
};

template <> struct traits<Windows::ApplicationModel::Calls::IPhoneCallHistoryEntryReader>
{
    using abi = ABI::Windows::ApplicationModel::Calls::IPhoneCallHistoryEntryReader;
    template <typename D> using consume = Windows::ApplicationModel::Calls::impl_IPhoneCallHistoryEntryReader<D>;
};

template <> struct traits<Windows::ApplicationModel::Calls::IPhoneCallHistoryManagerForUser>
{
    using abi = ABI::Windows::ApplicationModel::Calls::IPhoneCallHistoryManagerForUser;
    template <typename D> using consume = Windows::ApplicationModel::Calls::impl_IPhoneCallHistoryManagerForUser<D>;
};

template <> struct traits<Windows::ApplicationModel::Calls::IPhoneCallHistoryManagerStatics>
{
    using abi = ABI::Windows::ApplicationModel::Calls::IPhoneCallHistoryManagerStatics;
    template <typename D> using consume = Windows::ApplicationModel::Calls::impl_IPhoneCallHistoryManagerStatics<D>;
};

template <> struct traits<Windows::ApplicationModel::Calls::IPhoneCallHistoryManagerStatics2>
{
    using abi = ABI::Windows::ApplicationModel::Calls::IPhoneCallHistoryManagerStatics2;
    template <typename D> using consume = Windows::ApplicationModel::Calls::impl_IPhoneCallHistoryManagerStatics2<D>;
};

template <> struct traits<Windows::ApplicationModel::Calls::IPhoneCallHistoryStore>
{
    using abi = ABI::Windows::ApplicationModel::Calls::IPhoneCallHistoryStore;
    template <typename D> using consume = Windows::ApplicationModel::Calls::impl_IPhoneCallHistoryStore<D>;
};

template <> struct traits<Windows::ApplicationModel::Calls::IVoipCallCoordinator>
{
    using abi = ABI::Windows::ApplicationModel::Calls::IVoipCallCoordinator;
    template <typename D> using consume = Windows::ApplicationModel::Calls::impl_IVoipCallCoordinator<D>;
};

template <> struct traits<Windows::ApplicationModel::Calls::IVoipCallCoordinatorStatics>
{
    using abi = ABI::Windows::ApplicationModel::Calls::IVoipCallCoordinatorStatics;
    template <typename D> using consume = Windows::ApplicationModel::Calls::impl_IVoipCallCoordinatorStatics<D>;
};

template <> struct traits<Windows::ApplicationModel::Calls::IVoipPhoneCall>
{
    using abi = ABI::Windows::ApplicationModel::Calls::IVoipPhoneCall;
    template <typename D> using consume = Windows::ApplicationModel::Calls::impl_IVoipPhoneCall<D>;
};

template <> struct traits<Windows::ApplicationModel::Calls::CallAnswerEventArgs>
{
    using abi = ABI::Windows::ApplicationModel::Calls::CallAnswerEventArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.ApplicationModel.Calls.CallAnswerEventArgs"; }
};

template <> struct traits<Windows::ApplicationModel::Calls::CallRejectEventArgs>
{
    using abi = ABI::Windows::ApplicationModel::Calls::CallRejectEventArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.ApplicationModel.Calls.CallRejectEventArgs"; }
};

template <> struct traits<Windows::ApplicationModel::Calls::CallStateChangeEventArgs>
{
    using abi = ABI::Windows::ApplicationModel::Calls::CallStateChangeEventArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.ApplicationModel.Calls.CallStateChangeEventArgs"; }
};

template <> struct traits<Windows::ApplicationModel::Calls::MuteChangeEventArgs>
{
    using abi = ABI::Windows::ApplicationModel::Calls::MuteChangeEventArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.ApplicationModel.Calls.MuteChangeEventArgs"; }
};

template <> struct traits<Windows::ApplicationModel::Calls::PhoneCallHistoryEntry>
{
    using abi = ABI::Windows::ApplicationModel::Calls::PhoneCallHistoryEntry;
    static constexpr const wchar_t * name() noexcept { return L"Windows.ApplicationModel.Calls.PhoneCallHistoryEntry"; }
};

template <> struct traits<Windows::ApplicationModel::Calls::PhoneCallHistoryEntryAddress>
{
    using abi = ABI::Windows::ApplicationModel::Calls::PhoneCallHistoryEntryAddress;
    static constexpr const wchar_t * name() noexcept { return L"Windows.ApplicationModel.Calls.PhoneCallHistoryEntryAddress"; }
};

template <> struct traits<Windows::ApplicationModel::Calls::PhoneCallHistoryEntryQueryOptions>
{
    using abi = ABI::Windows::ApplicationModel::Calls::PhoneCallHistoryEntryQueryOptions;
    static constexpr const wchar_t * name() noexcept { return L"Windows.ApplicationModel.Calls.PhoneCallHistoryEntryQueryOptions"; }
};

template <> struct traits<Windows::ApplicationModel::Calls::PhoneCallHistoryEntryReader>
{
    using abi = ABI::Windows::ApplicationModel::Calls::PhoneCallHistoryEntryReader;
    static constexpr const wchar_t * name() noexcept { return L"Windows.ApplicationModel.Calls.PhoneCallHistoryEntryReader"; }
};

template <> struct traits<Windows::ApplicationModel::Calls::PhoneCallHistoryManager>
{
    static constexpr const wchar_t * name() noexcept { return L"Windows.ApplicationModel.Calls.PhoneCallHistoryManager"; }
};

template <> struct traits<Windows::ApplicationModel::Calls::PhoneCallHistoryManagerForUser>
{
    using abi = ABI::Windows::ApplicationModel::Calls::PhoneCallHistoryManagerForUser;
    static constexpr const wchar_t * name() noexcept { return L"Windows.ApplicationModel.Calls.PhoneCallHistoryManagerForUser"; }
};

template <> struct traits<Windows::ApplicationModel::Calls::PhoneCallHistoryStore>
{
    using abi = ABI::Windows::ApplicationModel::Calls::PhoneCallHistoryStore;
    static constexpr const wchar_t * name() noexcept { return L"Windows.ApplicationModel.Calls.PhoneCallHistoryStore"; }
};

template <> struct traits<Windows::ApplicationModel::Calls::VoipCallCoordinator>
{
    using abi = ABI::Windows::ApplicationModel::Calls::VoipCallCoordinator;
    static constexpr const wchar_t * name() noexcept { return L"Windows.ApplicationModel.Calls.VoipCallCoordinator"; }
};

template <> struct traits<Windows::ApplicationModel::Calls::VoipPhoneCall>
{
    using abi = ABI::Windows::ApplicationModel::Calls::VoipPhoneCall;
    static constexpr const wchar_t * name() noexcept { return L"Windows.ApplicationModel.Calls.VoipPhoneCall"; }
};

}

}
