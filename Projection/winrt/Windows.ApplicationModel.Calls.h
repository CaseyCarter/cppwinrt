// C++ for the Windows Runtime v1.0.private
// Copyright (c) 2016 Microsoft Corporation. All rights reserved.

#pragma once

#include "internal/Windows.Foundation.3.h"
#include "internal/Windows.Foundation.Collections.3.h"
#include "internal/Windows.System.3.h"
#include "internal/Windows.ApplicationModel.Calls.3.h"
#include "Windows.ApplicationModel.h"

WINRT_EXPORT namespace winrt {

namespace impl {

template <typename D>
struct produce<D, Windows::ApplicationModel::Calls::ICallAnswerEventArgs> : produce_base<D, Windows::ApplicationModel::Calls::ICallAnswerEventArgs>
{
    HRESULT __stdcall get_AcceptedMedia(Windows::ApplicationModel::Calls::VoipPhoneCallMedia * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach(this->shim().AcceptedMedia());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::ApplicationModel::Calls::ICallRejectEventArgs> : produce_base<D, Windows::ApplicationModel::Calls::ICallRejectEventArgs>
{
    HRESULT __stdcall get_RejectReason(Windows::ApplicationModel::Calls::VoipPhoneCallRejectReason * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach(this->shim().RejectReason());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::ApplicationModel::Calls::ICallStateChangeEventArgs> : produce_base<D, Windows::ApplicationModel::Calls::ICallStateChangeEventArgs>
{
    HRESULT __stdcall get_State(Windows::ApplicationModel::Calls::VoipPhoneCallState * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach(this->shim().State());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::ApplicationModel::Calls::IMuteChangeEventArgs> : produce_base<D, Windows::ApplicationModel::Calls::IMuteChangeEventArgs>
{
    HRESULT __stdcall get_Muted(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach(this->shim().Muted());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::ApplicationModel::Calls::IPhoneCallHistoryEntry> : produce_base<D, Windows::ApplicationModel::Calls::IPhoneCallHistoryEntry>
{
    HRESULT __stdcall get_Id(abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach(this->shim().Id());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Address(abi_arg_out<Windows::ApplicationModel::Calls::IPhoneCallHistoryEntryAddress> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach(this->shim().Address());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Address(abi_arg_in<Windows::ApplicationModel::Calls::IPhoneCallHistoryEntryAddress> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Address(*reinterpret_cast<const Windows::ApplicationModel::Calls::PhoneCallHistoryEntryAddress *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Duration(abi_arg_out<Windows::Foundation::IReference<Windows::Foundation::TimeSpan>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach(this->shim().Duration());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Duration(abi_arg_in<Windows::Foundation::IReference<Windows::Foundation::TimeSpan>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Duration(*reinterpret_cast<const Windows::Foundation::IReference<Windows::Foundation::TimeSpan> *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_IsCallerIdBlocked(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach(this->shim().IsCallerIdBlocked());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_IsCallerIdBlocked(bool value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().IsCallerIdBlocked(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_IsEmergency(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach(this->shim().IsEmergency());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_IsEmergency(bool value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().IsEmergency(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_IsIncoming(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach(this->shim().IsIncoming());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_IsIncoming(bool value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().IsIncoming(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_IsMissed(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach(this->shim().IsMissed());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_IsMissed(bool value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().IsMissed(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_IsRinging(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach(this->shim().IsRinging());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_IsRinging(bool value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().IsRinging(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_IsSeen(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach(this->shim().IsSeen());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_IsSeen(bool value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().IsSeen(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_IsSuppressed(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach(this->shim().IsSuppressed());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_IsSuppressed(bool value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().IsSuppressed(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_IsVoicemail(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach(this->shim().IsVoicemail());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_IsVoicemail(bool value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().IsVoicemail(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Media(Windows::ApplicationModel::Calls::PhoneCallHistoryEntryMedia * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach(this->shim().Media());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Media(Windows::ApplicationModel::Calls::PhoneCallHistoryEntryMedia value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Media(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_OtherAppReadAccess(Windows::ApplicationModel::Calls::PhoneCallHistoryEntryOtherAppReadAccess * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach(this->shim().OtherAppReadAccess());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_OtherAppReadAccess(Windows::ApplicationModel::Calls::PhoneCallHistoryEntryOtherAppReadAccess value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().OtherAppReadAccess(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_RemoteId(abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach(this->shim().RemoteId());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_RemoteId(abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().RemoteId(*reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_SourceDisplayName(abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach(this->shim().SourceDisplayName());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_SourceId(abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach(this->shim().SourceId());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_SourceId(abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SourceId(*reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_SourceIdKind(Windows::ApplicationModel::Calls::PhoneCallHistorySourceIdKind * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach(this->shim().SourceIdKind());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_SourceIdKind(Windows::ApplicationModel::Calls::PhoneCallHistorySourceIdKind value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SourceIdKind(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_StartTime(abi_arg_out<Windows::Foundation::DateTime> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach(this->shim().StartTime());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_StartTime(abi_arg_in<Windows::Foundation::DateTime> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().StartTime(*reinterpret_cast<const Windows::Foundation::DateTime *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::ApplicationModel::Calls::IPhoneCallHistoryEntryAddress> : produce_base<D, Windows::ApplicationModel::Calls::IPhoneCallHistoryEntryAddress>
{
    HRESULT __stdcall get_ContactId(abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach(this->shim().ContactId());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_ContactId(abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ContactId(*reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_DisplayName(abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach(this->shim().DisplayName());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_DisplayName(abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().DisplayName(*reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_RawAddress(abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach(this->shim().RawAddress());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_RawAddress(abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().RawAddress(*reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_RawAddressKind(Windows::ApplicationModel::Calls::PhoneCallHistoryEntryRawAddressKind * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach(this->shim().RawAddressKind());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_RawAddressKind(Windows::ApplicationModel::Calls::PhoneCallHistoryEntryRawAddressKind value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().RawAddressKind(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::ApplicationModel::Calls::IPhoneCallHistoryEntryAddressFactory> : produce_base<D, Windows::ApplicationModel::Calls::IPhoneCallHistoryEntryAddressFactory>
{
    HRESULT __stdcall abi_Create(abi_arg_in<hstring> rawAddress, Windows::ApplicationModel::Calls::PhoneCallHistoryEntryRawAddressKind rawAddressKind, abi_arg_out<Windows::ApplicationModel::Calls::IPhoneCallHistoryEntryAddress> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach(this->shim().Create(*reinterpret_cast<const hstring *>(&rawAddress), rawAddressKind));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::ApplicationModel::Calls::IPhoneCallHistoryEntryQueryOptions> : produce_base<D, Windows::ApplicationModel::Calls::IPhoneCallHistoryEntryQueryOptions>
{
    HRESULT __stdcall get_DesiredMedia(Windows::ApplicationModel::Calls::PhoneCallHistoryEntryQueryDesiredMedia * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach(this->shim().DesiredMedia());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_DesiredMedia(Windows::ApplicationModel::Calls::PhoneCallHistoryEntryQueryDesiredMedia value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().DesiredMedia(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_SourceIds(abi_arg_out<Windows::Foundation::Collections::IVector<hstring>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach(this->shim().SourceIds());
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
struct produce<D, Windows::ApplicationModel::Calls::IPhoneCallHistoryEntryReader> : produce_base<D, Windows::ApplicationModel::Calls::IPhoneCallHistoryEntryReader>
{
    HRESULT __stdcall abi_ReadBatchAsync(abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::ApplicationModel::Calls::PhoneCallHistoryEntry>>> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach(this->shim().ReadBatchAsync());
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::ApplicationModel::Calls::IPhoneCallHistoryManagerForUser> : produce_base<D, Windows::ApplicationModel::Calls::IPhoneCallHistoryManagerForUser>
{
    HRESULT __stdcall abi_RequestStoreAsync(Windows::ApplicationModel::Calls::PhoneCallHistoryStoreAccessType accessType, abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Calls::PhoneCallHistoryStore>> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach(this->shim().RequestStoreAsync(accessType));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_User(abi_arg_out<Windows::System::IUser> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach(this->shim().User());
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
struct produce<D, Windows::ApplicationModel::Calls::IPhoneCallHistoryManagerStatics> : produce_base<D, Windows::ApplicationModel::Calls::IPhoneCallHistoryManagerStatics>
{
    HRESULT __stdcall abi_RequestStoreAsync(Windows::ApplicationModel::Calls::PhoneCallHistoryStoreAccessType accessType, abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Calls::PhoneCallHistoryStore>> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach(this->shim().RequestStoreAsync(accessType));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::ApplicationModel::Calls::IPhoneCallHistoryManagerStatics2> : produce_base<D, Windows::ApplicationModel::Calls::IPhoneCallHistoryManagerStatics2>
{
    HRESULT __stdcall abi_GetForUser(abi_arg_in<Windows::System::IUser> user, abi_arg_out<Windows::ApplicationModel::Calls::IPhoneCallHistoryManagerForUser> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach(this->shim().GetForUser(*reinterpret_cast<const Windows::System::User *>(&user)));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::ApplicationModel::Calls::IPhoneCallHistoryStore> : produce_base<D, Windows::ApplicationModel::Calls::IPhoneCallHistoryStore>
{
    HRESULT __stdcall abi_GetEntryAsync(abi_arg_in<hstring> callHistoryEntryId, abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Calls::PhoneCallHistoryEntry>> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach(this->shim().GetEntryAsync(*reinterpret_cast<const hstring *>(&callHistoryEntryId)));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetEntryReader(abi_arg_out<Windows::ApplicationModel::Calls::IPhoneCallHistoryEntryReader> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach(this->shim().GetEntryReader());
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetEntryReaderWithOptions(abi_arg_in<Windows::ApplicationModel::Calls::IPhoneCallHistoryEntryQueryOptions> queryOptions, abi_arg_out<Windows::ApplicationModel::Calls::IPhoneCallHistoryEntryReader> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach(this->shim().GetEntryReader(*reinterpret_cast<const Windows::ApplicationModel::Calls::PhoneCallHistoryEntryQueryOptions *>(&queryOptions)));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_SaveEntryAsync(abi_arg_in<Windows::ApplicationModel::Calls::IPhoneCallHistoryEntry> callHistoryEntry, abi_arg_out<Windows::Foundation::IAsyncAction> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach(this->shim().SaveEntryAsync(*reinterpret_cast<const Windows::ApplicationModel::Calls::PhoneCallHistoryEntry *>(&callHistoryEntry)));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_DeleteEntryAsync(abi_arg_in<Windows::ApplicationModel::Calls::IPhoneCallHistoryEntry> callHistoryEntry, abi_arg_out<Windows::Foundation::IAsyncAction> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach(this->shim().DeleteEntryAsync(*reinterpret_cast<const Windows::ApplicationModel::Calls::PhoneCallHistoryEntry *>(&callHistoryEntry)));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_DeleteEntriesAsync(abi_arg_in<Windows::Foundation::Collections::IIterable<Windows::ApplicationModel::Calls::PhoneCallHistoryEntry>> callHistoryEntries, abi_arg_out<Windows::Foundation::IAsyncAction> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach(this->shim().DeleteEntriesAsync(*reinterpret_cast<const Windows::Foundation::Collections::IIterable<Windows::ApplicationModel::Calls::PhoneCallHistoryEntry> *>(&callHistoryEntries)));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_MarkEntryAsSeenAsync(abi_arg_in<Windows::ApplicationModel::Calls::IPhoneCallHistoryEntry> callHistoryEntry, abi_arg_out<Windows::Foundation::IAsyncAction> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach(this->shim().MarkEntryAsSeenAsync(*reinterpret_cast<const Windows::ApplicationModel::Calls::PhoneCallHistoryEntry *>(&callHistoryEntry)));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_MarkEntriesAsSeenAsync(abi_arg_in<Windows::Foundation::Collections::IIterable<Windows::ApplicationModel::Calls::PhoneCallHistoryEntry>> callHistoryEntries, abi_arg_out<Windows::Foundation::IAsyncAction> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach(this->shim().MarkEntriesAsSeenAsync(*reinterpret_cast<const Windows::Foundation::Collections::IIterable<Windows::ApplicationModel::Calls::PhoneCallHistoryEntry> *>(&callHistoryEntries)));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetUnseenCountAsync(abi_arg_out<Windows::Foundation::IAsyncOperation<uint32_t>> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach(this->shim().GetUnseenCountAsync());
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_MarkAllAsSeenAsync(abi_arg_out<Windows::Foundation::IAsyncAction> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach(this->shim().MarkAllAsSeenAsync());
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetSourcesUnseenCountAsync(abi_arg_in<Windows::Foundation::Collections::IIterable<hstring>> sourceIds, abi_arg_out<Windows::Foundation::IAsyncOperation<uint32_t>> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach(this->shim().GetSourcesUnseenCountAsync(*reinterpret_cast<const Windows::Foundation::Collections::IIterable<hstring> *>(&sourceIds)));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_MarkSourcesAsSeenAsync(abi_arg_in<Windows::Foundation::Collections::IIterable<hstring>> sourceIds, abi_arg_out<Windows::Foundation::IAsyncAction> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach(this->shim().MarkSourcesAsSeenAsync(*reinterpret_cast<const Windows::Foundation::Collections::IIterable<hstring> *>(&sourceIds)));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::ApplicationModel::Calls::IVoipCallCoordinator> : produce_base<D, Windows::ApplicationModel::Calls::IVoipCallCoordinator>
{
    HRESULT __stdcall abi_ReserveCallResourcesAsync(abi_arg_in<hstring> taskEntryPoint, abi_arg_out<Windows::Foundation::IAsyncOperation<winrt::Windows::ApplicationModel::Calls::VoipPhoneCallResourceReservationStatus>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach(this->shim().ReserveCallResourcesAsync(*reinterpret_cast<const hstring *>(&taskEntryPoint)));
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_MuteStateChanged(abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Calls::VoipCallCoordinator, Windows::ApplicationModel::Calls::MuteChangeEventArgs>> muteChangeHandler, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach(this->shim().MuteStateChanged(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Calls::VoipCallCoordinator, Windows::ApplicationModel::Calls::MuteChangeEventArgs> *>(&muteChangeHandler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_MuteStateChanged(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().MuteStateChanged(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_RequestNewIncomingCall(abi_arg_in<hstring> context, abi_arg_in<hstring> contactName, abi_arg_in<hstring> contactNumber, abi_arg_in<Windows::Foundation::IUriRuntimeClass> contactImage, abi_arg_in<hstring> serviceName, abi_arg_in<Windows::Foundation::IUriRuntimeClass> brandingImage, abi_arg_in<hstring> callDetails, abi_arg_in<Windows::Foundation::IUriRuntimeClass> ringtone, Windows::ApplicationModel::Calls::VoipPhoneCallMedia media, abi_arg_in<Windows::Foundation::TimeSpan> ringTimeout, abi_arg_out<Windows::ApplicationModel::Calls::IVoipPhoneCall> call) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *call = detach(this->shim().RequestNewIncomingCall(*reinterpret_cast<const hstring *>(&context), *reinterpret_cast<const hstring *>(&contactName), *reinterpret_cast<const hstring *>(&contactNumber), *reinterpret_cast<const Windows::Foundation::Uri *>(&contactImage), *reinterpret_cast<const hstring *>(&serviceName), *reinterpret_cast<const Windows::Foundation::Uri *>(&brandingImage), *reinterpret_cast<const hstring *>(&callDetails), *reinterpret_cast<const Windows::Foundation::Uri *>(&ringtone), media, *reinterpret_cast<const Windows::Foundation::TimeSpan *>(&ringTimeout)));
            return S_OK;
        }
        catch (...)
        {
            *call = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_RequestNewOutgoingCall(abi_arg_in<hstring> context, abi_arg_in<hstring> contactName, abi_arg_in<hstring> serviceName, Windows::ApplicationModel::Calls::VoipPhoneCallMedia media, abi_arg_out<Windows::ApplicationModel::Calls::IVoipPhoneCall> call) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *call = detach(this->shim().RequestNewOutgoingCall(*reinterpret_cast<const hstring *>(&context), *reinterpret_cast<const hstring *>(&contactName), *reinterpret_cast<const hstring *>(&serviceName), media));
            return S_OK;
        }
        catch (...)
        {
            *call = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_NotifyMuted() noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().NotifyMuted();
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_NotifyUnmuted() noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().NotifyUnmuted();
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_RequestOutgoingUpgradeToVideoCall(GUID callUpgradeGuid, abi_arg_in<hstring> context, abi_arg_in<hstring> contactName, abi_arg_in<hstring> serviceName, abi_arg_out<Windows::ApplicationModel::Calls::IVoipPhoneCall> call) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *call = detach(this->shim().RequestOutgoingUpgradeToVideoCall(callUpgradeGuid, *reinterpret_cast<const hstring *>(&context), *reinterpret_cast<const hstring *>(&contactName), *reinterpret_cast<const hstring *>(&serviceName)));
            return S_OK;
        }
        catch (...)
        {
            *call = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_RequestIncomingUpgradeToVideoCall(abi_arg_in<hstring> context, abi_arg_in<hstring> contactName, abi_arg_in<hstring> contactNumber, abi_arg_in<Windows::Foundation::IUriRuntimeClass> contactImage, abi_arg_in<hstring> serviceName, abi_arg_in<Windows::Foundation::IUriRuntimeClass> brandingImage, abi_arg_in<hstring> callDetails, abi_arg_in<Windows::Foundation::IUriRuntimeClass> ringtone, abi_arg_in<Windows::Foundation::TimeSpan> ringTimeout, abi_arg_out<Windows::ApplicationModel::Calls::IVoipPhoneCall> call) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *call = detach(this->shim().RequestIncomingUpgradeToVideoCall(*reinterpret_cast<const hstring *>(&context), *reinterpret_cast<const hstring *>(&contactName), *reinterpret_cast<const hstring *>(&contactNumber), *reinterpret_cast<const Windows::Foundation::Uri *>(&contactImage), *reinterpret_cast<const hstring *>(&serviceName), *reinterpret_cast<const Windows::Foundation::Uri *>(&brandingImage), *reinterpret_cast<const hstring *>(&callDetails), *reinterpret_cast<const Windows::Foundation::Uri *>(&ringtone), *reinterpret_cast<const Windows::Foundation::TimeSpan *>(&ringTimeout)));
            return S_OK;
        }
        catch (...)
        {
            *call = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_TerminateCellularCall(GUID callUpgradeGuid) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().TerminateCellularCall(callUpgradeGuid);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_CancelUpgrade(GUID callUpgradeGuid) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().CancelUpgrade(callUpgradeGuid);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::ApplicationModel::Calls::IVoipCallCoordinatorStatics> : produce_base<D, Windows::ApplicationModel::Calls::IVoipCallCoordinatorStatics>
{
    HRESULT __stdcall abi_GetDefault(abi_arg_out<Windows::ApplicationModel::Calls::IVoipCallCoordinator> coordinator) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *coordinator = detach(this->shim().GetDefault());
            return S_OK;
        }
        catch (...)
        {
            *coordinator = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::ApplicationModel::Calls::IVoipPhoneCall> : produce_base<D, Windows::ApplicationModel::Calls::IVoipPhoneCall>
{
    HRESULT __stdcall add_EndRequested(abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Calls::VoipPhoneCall, Windows::ApplicationModel::Calls::CallStateChangeEventArgs>> handler, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach(this->shim().EndRequested(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Calls::VoipPhoneCall, Windows::ApplicationModel::Calls::CallStateChangeEventArgs> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_EndRequested(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().EndRequested(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_HoldRequested(abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Calls::VoipPhoneCall, Windows::ApplicationModel::Calls::CallStateChangeEventArgs>> handler, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach(this->shim().HoldRequested(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Calls::VoipPhoneCall, Windows::ApplicationModel::Calls::CallStateChangeEventArgs> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_HoldRequested(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().HoldRequested(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_ResumeRequested(abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Calls::VoipPhoneCall, Windows::ApplicationModel::Calls::CallStateChangeEventArgs>> handler, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach(this->shim().ResumeRequested(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Calls::VoipPhoneCall, Windows::ApplicationModel::Calls::CallStateChangeEventArgs> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_ResumeRequested(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ResumeRequested(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_AnswerRequested(abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Calls::VoipPhoneCall, Windows::ApplicationModel::Calls::CallAnswerEventArgs>> acceptHandler, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach(this->shim().AnswerRequested(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Calls::VoipPhoneCall, Windows::ApplicationModel::Calls::CallAnswerEventArgs> *>(&acceptHandler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_AnswerRequested(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AnswerRequested(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_RejectRequested(abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Calls::VoipPhoneCall, Windows::ApplicationModel::Calls::CallRejectEventArgs>> rejectHandler, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach(this->shim().RejectRequested(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Calls::VoipPhoneCall, Windows::ApplicationModel::Calls::CallRejectEventArgs> *>(&rejectHandler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_RejectRequested(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().RejectRequested(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_NotifyCallHeld() noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().NotifyCallHeld();
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_NotifyCallActive() noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().NotifyCallActive();
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_NotifyCallEnded() noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().NotifyCallEnded();
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ContactName(abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach(this->shim().ContactName());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_ContactName(abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ContactName(*reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_StartTime(abi_arg_out<Windows::Foundation::DateTime> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach(this->shim().StartTime());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_StartTime(abi_arg_in<Windows::Foundation::DateTime> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().StartTime(*reinterpret_cast<const Windows::Foundation::DateTime *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_CallMedia(Windows::ApplicationModel::Calls::VoipPhoneCallMedia * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach(this->shim().CallMedia());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_CallMedia(Windows::ApplicationModel::Calls::VoipPhoneCallMedia value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().CallMedia(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_NotifyCallReady() noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().NotifyCallReady();
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

}

namespace Windows::ApplicationModel::Calls {

template <typename D> Windows::ApplicationModel::Calls::VoipPhoneCallState impl_ICallStateChangeEventArgs<D>::State() const
{
    Windows::ApplicationModel::Calls::VoipPhoneCallState value {};
    check_hresult(static_cast<const ICallStateChangeEventArgs &>(static_cast<const D &>(*this))->get_State(&value));
    return value;
}

template <typename D> Windows::ApplicationModel::Calls::VoipPhoneCallMedia impl_ICallAnswerEventArgs<D>::AcceptedMedia() const
{
    Windows::ApplicationModel::Calls::VoipPhoneCallMedia value {};
    check_hresult(static_cast<const ICallAnswerEventArgs &>(static_cast<const D &>(*this))->get_AcceptedMedia(&value));
    return value;
}

template <typename D> Windows::ApplicationModel::Calls::VoipPhoneCallRejectReason impl_ICallRejectEventArgs<D>::RejectReason() const
{
    Windows::ApplicationModel::Calls::VoipPhoneCallRejectReason value {};
    check_hresult(static_cast<const ICallRejectEventArgs &>(static_cast<const D &>(*this))->get_RejectReason(&value));
    return value;
}

template <typename D> event_token impl_IVoipPhoneCall<D>::EndRequested(const Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Calls::VoipPhoneCall, Windows::ApplicationModel::Calls::CallStateChangeEventArgs> & handler) const
{
    event_token token {};
    check_hresult(static_cast<const IVoipPhoneCall &>(static_cast<const D &>(*this))->add_EndRequested(get(handler), &token));
    return token;
}

template <typename D> event_revoker<IVoipPhoneCall> impl_IVoipPhoneCall<D>::EndRequested(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Calls::VoipPhoneCall, Windows::ApplicationModel::Calls::CallStateChangeEventArgs> & handler) const
{
    return impl::make_event_revoker<D, IVoipPhoneCall>(this, &ABI::Windows::ApplicationModel::Calls::IVoipPhoneCall::remove_EndRequested, EndRequested(handler));
}

template <typename D> void impl_IVoipPhoneCall<D>::EndRequested(event_token token) const
{
    check_hresult(static_cast<const IVoipPhoneCall &>(static_cast<const D &>(*this))->remove_EndRequested(token));
}

template <typename D> event_token impl_IVoipPhoneCall<D>::HoldRequested(const Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Calls::VoipPhoneCall, Windows::ApplicationModel::Calls::CallStateChangeEventArgs> & handler) const
{
    event_token token {};
    check_hresult(static_cast<const IVoipPhoneCall &>(static_cast<const D &>(*this))->add_HoldRequested(get(handler), &token));
    return token;
}

template <typename D> event_revoker<IVoipPhoneCall> impl_IVoipPhoneCall<D>::HoldRequested(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Calls::VoipPhoneCall, Windows::ApplicationModel::Calls::CallStateChangeEventArgs> & handler) const
{
    return impl::make_event_revoker<D, IVoipPhoneCall>(this, &ABI::Windows::ApplicationModel::Calls::IVoipPhoneCall::remove_HoldRequested, HoldRequested(handler));
}

template <typename D> void impl_IVoipPhoneCall<D>::HoldRequested(event_token token) const
{
    check_hresult(static_cast<const IVoipPhoneCall &>(static_cast<const D &>(*this))->remove_HoldRequested(token));
}

template <typename D> event_token impl_IVoipPhoneCall<D>::ResumeRequested(const Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Calls::VoipPhoneCall, Windows::ApplicationModel::Calls::CallStateChangeEventArgs> & handler) const
{
    event_token token {};
    check_hresult(static_cast<const IVoipPhoneCall &>(static_cast<const D &>(*this))->add_ResumeRequested(get(handler), &token));
    return token;
}

template <typename D> event_revoker<IVoipPhoneCall> impl_IVoipPhoneCall<D>::ResumeRequested(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Calls::VoipPhoneCall, Windows::ApplicationModel::Calls::CallStateChangeEventArgs> & handler) const
{
    return impl::make_event_revoker<D, IVoipPhoneCall>(this, &ABI::Windows::ApplicationModel::Calls::IVoipPhoneCall::remove_ResumeRequested, ResumeRequested(handler));
}

template <typename D> void impl_IVoipPhoneCall<D>::ResumeRequested(event_token token) const
{
    check_hresult(static_cast<const IVoipPhoneCall &>(static_cast<const D &>(*this))->remove_ResumeRequested(token));
}

template <typename D> event_token impl_IVoipPhoneCall<D>::AnswerRequested(const Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Calls::VoipPhoneCall, Windows::ApplicationModel::Calls::CallAnswerEventArgs> & acceptHandler) const
{
    event_token token {};
    check_hresult(static_cast<const IVoipPhoneCall &>(static_cast<const D &>(*this))->add_AnswerRequested(get(acceptHandler), &token));
    return token;
}

template <typename D> event_revoker<IVoipPhoneCall> impl_IVoipPhoneCall<D>::AnswerRequested(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Calls::VoipPhoneCall, Windows::ApplicationModel::Calls::CallAnswerEventArgs> & acceptHandler) const
{
    return impl::make_event_revoker<D, IVoipPhoneCall>(this, &ABI::Windows::ApplicationModel::Calls::IVoipPhoneCall::remove_AnswerRequested, AnswerRequested(acceptHandler));
}

template <typename D> void impl_IVoipPhoneCall<D>::AnswerRequested(event_token token) const
{
    check_hresult(static_cast<const IVoipPhoneCall &>(static_cast<const D &>(*this))->remove_AnswerRequested(token));
}

template <typename D> event_token impl_IVoipPhoneCall<D>::RejectRequested(const Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Calls::VoipPhoneCall, Windows::ApplicationModel::Calls::CallRejectEventArgs> & rejectHandler) const
{
    event_token token {};
    check_hresult(static_cast<const IVoipPhoneCall &>(static_cast<const D &>(*this))->add_RejectRequested(get(rejectHandler), &token));
    return token;
}

template <typename D> event_revoker<IVoipPhoneCall> impl_IVoipPhoneCall<D>::RejectRequested(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Calls::VoipPhoneCall, Windows::ApplicationModel::Calls::CallRejectEventArgs> & rejectHandler) const
{
    return impl::make_event_revoker<D, IVoipPhoneCall>(this, &ABI::Windows::ApplicationModel::Calls::IVoipPhoneCall::remove_RejectRequested, RejectRequested(rejectHandler));
}

template <typename D> void impl_IVoipPhoneCall<D>::RejectRequested(event_token token) const
{
    check_hresult(static_cast<const IVoipPhoneCall &>(static_cast<const D &>(*this))->remove_RejectRequested(token));
}

template <typename D> void impl_IVoipPhoneCall<D>::NotifyCallHeld() const
{
    check_hresult(static_cast<const IVoipPhoneCall &>(static_cast<const D &>(*this))->abi_NotifyCallHeld());
}

template <typename D> void impl_IVoipPhoneCall<D>::NotifyCallActive() const
{
    check_hresult(static_cast<const IVoipPhoneCall &>(static_cast<const D &>(*this))->abi_NotifyCallActive());
}

template <typename D> void impl_IVoipPhoneCall<D>::NotifyCallEnded() const
{
    check_hresult(static_cast<const IVoipPhoneCall &>(static_cast<const D &>(*this))->abi_NotifyCallEnded());
}

template <typename D> hstring impl_IVoipPhoneCall<D>::ContactName() const
{
    hstring value;
    check_hresult(static_cast<const IVoipPhoneCall &>(static_cast<const D &>(*this))->get_ContactName(put(value)));
    return value;
}

template <typename D> void impl_IVoipPhoneCall<D>::ContactName(hstring_ref value) const
{
    check_hresult(static_cast<const IVoipPhoneCall &>(static_cast<const D &>(*this))->put_ContactName(get(value)));
}

template <typename D> Windows::Foundation::DateTime impl_IVoipPhoneCall<D>::StartTime() const
{
    Windows::Foundation::DateTime value {};
    check_hresult(static_cast<const IVoipPhoneCall &>(static_cast<const D &>(*this))->get_StartTime(put(value)));
    return value;
}

template <typename D> void impl_IVoipPhoneCall<D>::StartTime(const Windows::Foundation::DateTime & value) const
{
    check_hresult(static_cast<const IVoipPhoneCall &>(static_cast<const D &>(*this))->put_StartTime(get(value)));
}

template <typename D> Windows::ApplicationModel::Calls::VoipPhoneCallMedia impl_IVoipPhoneCall<D>::CallMedia() const
{
    Windows::ApplicationModel::Calls::VoipPhoneCallMedia value {};
    check_hresult(static_cast<const IVoipPhoneCall &>(static_cast<const D &>(*this))->get_CallMedia(&value));
    return value;
}

template <typename D> void impl_IVoipPhoneCall<D>::CallMedia(Windows::ApplicationModel::Calls::VoipPhoneCallMedia value) const
{
    check_hresult(static_cast<const IVoipPhoneCall &>(static_cast<const D &>(*this))->put_CallMedia(value));
}

template <typename D> void impl_IVoipPhoneCall<D>::NotifyCallReady() const
{
    check_hresult(static_cast<const IVoipPhoneCall &>(static_cast<const D &>(*this))->abi_NotifyCallReady());
}

template <typename D> bool impl_IMuteChangeEventArgs<D>::Muted() const
{
    bool value {};
    check_hresult(static_cast<const IMuteChangeEventArgs &>(static_cast<const D &>(*this))->get_Muted(&value));
    return value;
}

template <typename D> Windows::Foundation::IAsyncOperation<winrt::Windows::ApplicationModel::Calls::VoipPhoneCallResourceReservationStatus> impl_IVoipCallCoordinator<D>::ReserveCallResourcesAsync(hstring_ref taskEntryPoint) const
{
    Windows::Foundation::IAsyncOperation<winrt::Windows::ApplicationModel::Calls::VoipPhoneCallResourceReservationStatus> operation;
    check_hresult(static_cast<const IVoipCallCoordinator &>(static_cast<const D &>(*this))->abi_ReserveCallResourcesAsync(get(taskEntryPoint), put(operation)));
    return operation;
}

template <typename D> event_token impl_IVoipCallCoordinator<D>::MuteStateChanged(const Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Calls::VoipCallCoordinator, Windows::ApplicationModel::Calls::MuteChangeEventArgs> & muteChangeHandler) const
{
    event_token token {};
    check_hresult(static_cast<const IVoipCallCoordinator &>(static_cast<const D &>(*this))->add_MuteStateChanged(get(muteChangeHandler), &token));
    return token;
}

template <typename D> event_revoker<IVoipCallCoordinator> impl_IVoipCallCoordinator<D>::MuteStateChanged(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Calls::VoipCallCoordinator, Windows::ApplicationModel::Calls::MuteChangeEventArgs> & muteChangeHandler) const
{
    return impl::make_event_revoker<D, IVoipCallCoordinator>(this, &ABI::Windows::ApplicationModel::Calls::IVoipCallCoordinator::remove_MuteStateChanged, MuteStateChanged(muteChangeHandler));
}

template <typename D> void impl_IVoipCallCoordinator<D>::MuteStateChanged(event_token token) const
{
    check_hresult(static_cast<const IVoipCallCoordinator &>(static_cast<const D &>(*this))->remove_MuteStateChanged(token));
}

template <typename D> Windows::ApplicationModel::Calls::VoipPhoneCall impl_IVoipCallCoordinator<D>::RequestNewIncomingCall(hstring_ref context, hstring_ref contactName, hstring_ref contactNumber, const Windows::Foundation::Uri & contactImage, hstring_ref serviceName, const Windows::Foundation::Uri & brandingImage, hstring_ref callDetails, const Windows::Foundation::Uri & ringtone, Windows::ApplicationModel::Calls::VoipPhoneCallMedia media, const Windows::Foundation::TimeSpan & ringTimeout) const
{
    Windows::ApplicationModel::Calls::VoipPhoneCall call { nullptr };
    check_hresult(static_cast<const IVoipCallCoordinator &>(static_cast<const D &>(*this))->abi_RequestNewIncomingCall(get(context), get(contactName), get(contactNumber), get(contactImage), get(serviceName), get(brandingImage), get(callDetails), get(ringtone), media, get(ringTimeout), put(call)));
    return call;
}

template <typename D> Windows::ApplicationModel::Calls::VoipPhoneCall impl_IVoipCallCoordinator<D>::RequestNewOutgoingCall(hstring_ref context, hstring_ref contactName, hstring_ref serviceName, Windows::ApplicationModel::Calls::VoipPhoneCallMedia media) const
{
    Windows::ApplicationModel::Calls::VoipPhoneCall call { nullptr };
    check_hresult(static_cast<const IVoipCallCoordinator &>(static_cast<const D &>(*this))->abi_RequestNewOutgoingCall(get(context), get(contactName), get(serviceName), media, put(call)));
    return call;
}

template <typename D> void impl_IVoipCallCoordinator<D>::NotifyMuted() const
{
    check_hresult(static_cast<const IVoipCallCoordinator &>(static_cast<const D &>(*this))->abi_NotifyMuted());
}

template <typename D> void impl_IVoipCallCoordinator<D>::NotifyUnmuted() const
{
    check_hresult(static_cast<const IVoipCallCoordinator &>(static_cast<const D &>(*this))->abi_NotifyUnmuted());
}

template <typename D> Windows::ApplicationModel::Calls::VoipPhoneCall impl_IVoipCallCoordinator<D>::RequestOutgoingUpgradeToVideoCall(GUID callUpgradeGuid, hstring_ref context, hstring_ref contactName, hstring_ref serviceName) const
{
    Windows::ApplicationModel::Calls::VoipPhoneCall call { nullptr };
    check_hresult(static_cast<const IVoipCallCoordinator &>(static_cast<const D &>(*this))->abi_RequestOutgoingUpgradeToVideoCall(callUpgradeGuid, get(context), get(contactName), get(serviceName), put(call)));
    return call;
}

template <typename D> Windows::ApplicationModel::Calls::VoipPhoneCall impl_IVoipCallCoordinator<D>::RequestIncomingUpgradeToVideoCall(hstring_ref context, hstring_ref contactName, hstring_ref contactNumber, const Windows::Foundation::Uri & contactImage, hstring_ref serviceName, const Windows::Foundation::Uri & brandingImage, hstring_ref callDetails, const Windows::Foundation::Uri & ringtone, const Windows::Foundation::TimeSpan & ringTimeout) const
{
    Windows::ApplicationModel::Calls::VoipPhoneCall call { nullptr };
    check_hresult(static_cast<const IVoipCallCoordinator &>(static_cast<const D &>(*this))->abi_RequestIncomingUpgradeToVideoCall(get(context), get(contactName), get(contactNumber), get(contactImage), get(serviceName), get(brandingImage), get(callDetails), get(ringtone), get(ringTimeout), put(call)));
    return call;
}

template <typename D> void impl_IVoipCallCoordinator<D>::TerminateCellularCall(GUID callUpgradeGuid) const
{
    check_hresult(static_cast<const IVoipCallCoordinator &>(static_cast<const D &>(*this))->abi_TerminateCellularCall(callUpgradeGuid));
}

template <typename D> void impl_IVoipCallCoordinator<D>::CancelUpgrade(GUID callUpgradeGuid) const
{
    check_hresult(static_cast<const IVoipCallCoordinator &>(static_cast<const D &>(*this))->abi_CancelUpgrade(callUpgradeGuid));
}

template <typename D> Windows::ApplicationModel::Calls::VoipCallCoordinator impl_IVoipCallCoordinatorStatics<D>::GetDefault() const
{
    Windows::ApplicationModel::Calls::VoipCallCoordinator coordinator { nullptr };
    check_hresult(static_cast<const IVoipCallCoordinatorStatics &>(static_cast<const D &>(*this))->abi_GetDefault(put(coordinator)));
    return coordinator;
}

template <typename D> hstring impl_IPhoneCallHistoryEntry<D>::Id() const
{
    hstring value;
    check_hresult(static_cast<const IPhoneCallHistoryEntry &>(static_cast<const D &>(*this))->get_Id(put(value)));
    return value;
}

template <typename D> Windows::ApplicationModel::Calls::PhoneCallHistoryEntryAddress impl_IPhoneCallHistoryEntry<D>::Address() const
{
    Windows::ApplicationModel::Calls::PhoneCallHistoryEntryAddress value { nullptr };
    check_hresult(static_cast<const IPhoneCallHistoryEntry &>(static_cast<const D &>(*this))->get_Address(put(value)));
    return value;
}

template <typename D> void impl_IPhoneCallHistoryEntry<D>::Address(const Windows::ApplicationModel::Calls::PhoneCallHistoryEntryAddress & value) const
{
    check_hresult(static_cast<const IPhoneCallHistoryEntry &>(static_cast<const D &>(*this))->put_Address(get(value)));
}

template <typename D> Windows::Foundation::IReference<Windows::Foundation::TimeSpan> impl_IPhoneCallHistoryEntry<D>::Duration() const
{
    Windows::Foundation::IReference<Windows::Foundation::TimeSpan> value;
    check_hresult(static_cast<const IPhoneCallHistoryEntry &>(static_cast<const D &>(*this))->get_Duration(put(value)));
    return value;
}

template <typename D> void impl_IPhoneCallHistoryEntry<D>::Duration(const Windows::Foundation::IReference<Windows::Foundation::TimeSpan> & value) const
{
    check_hresult(static_cast<const IPhoneCallHistoryEntry &>(static_cast<const D &>(*this))->put_Duration(get(value)));
}

template <typename D> bool impl_IPhoneCallHistoryEntry<D>::IsCallerIdBlocked() const
{
    bool value {};
    check_hresult(static_cast<const IPhoneCallHistoryEntry &>(static_cast<const D &>(*this))->get_IsCallerIdBlocked(&value));
    return value;
}

template <typename D> void impl_IPhoneCallHistoryEntry<D>::IsCallerIdBlocked(bool value) const
{
    check_hresult(static_cast<const IPhoneCallHistoryEntry &>(static_cast<const D &>(*this))->put_IsCallerIdBlocked(value));
}

template <typename D> bool impl_IPhoneCallHistoryEntry<D>::IsEmergency() const
{
    bool value {};
    check_hresult(static_cast<const IPhoneCallHistoryEntry &>(static_cast<const D &>(*this))->get_IsEmergency(&value));
    return value;
}

template <typename D> void impl_IPhoneCallHistoryEntry<D>::IsEmergency(bool value) const
{
    check_hresult(static_cast<const IPhoneCallHistoryEntry &>(static_cast<const D &>(*this))->put_IsEmergency(value));
}

template <typename D> bool impl_IPhoneCallHistoryEntry<D>::IsIncoming() const
{
    bool value {};
    check_hresult(static_cast<const IPhoneCallHistoryEntry &>(static_cast<const D &>(*this))->get_IsIncoming(&value));
    return value;
}

template <typename D> void impl_IPhoneCallHistoryEntry<D>::IsIncoming(bool value) const
{
    check_hresult(static_cast<const IPhoneCallHistoryEntry &>(static_cast<const D &>(*this))->put_IsIncoming(value));
}

template <typename D> bool impl_IPhoneCallHistoryEntry<D>::IsMissed() const
{
    bool value {};
    check_hresult(static_cast<const IPhoneCallHistoryEntry &>(static_cast<const D &>(*this))->get_IsMissed(&value));
    return value;
}

template <typename D> void impl_IPhoneCallHistoryEntry<D>::IsMissed(bool value) const
{
    check_hresult(static_cast<const IPhoneCallHistoryEntry &>(static_cast<const D &>(*this))->put_IsMissed(value));
}

template <typename D> bool impl_IPhoneCallHistoryEntry<D>::IsRinging() const
{
    bool value {};
    check_hresult(static_cast<const IPhoneCallHistoryEntry &>(static_cast<const D &>(*this))->get_IsRinging(&value));
    return value;
}

template <typename D> void impl_IPhoneCallHistoryEntry<D>::IsRinging(bool value) const
{
    check_hresult(static_cast<const IPhoneCallHistoryEntry &>(static_cast<const D &>(*this))->put_IsRinging(value));
}

template <typename D> bool impl_IPhoneCallHistoryEntry<D>::IsSeen() const
{
    bool value {};
    check_hresult(static_cast<const IPhoneCallHistoryEntry &>(static_cast<const D &>(*this))->get_IsSeen(&value));
    return value;
}

template <typename D> void impl_IPhoneCallHistoryEntry<D>::IsSeen(bool value) const
{
    check_hresult(static_cast<const IPhoneCallHistoryEntry &>(static_cast<const D &>(*this))->put_IsSeen(value));
}

template <typename D> bool impl_IPhoneCallHistoryEntry<D>::IsSuppressed() const
{
    bool value {};
    check_hresult(static_cast<const IPhoneCallHistoryEntry &>(static_cast<const D &>(*this))->get_IsSuppressed(&value));
    return value;
}

template <typename D> void impl_IPhoneCallHistoryEntry<D>::IsSuppressed(bool value) const
{
    check_hresult(static_cast<const IPhoneCallHistoryEntry &>(static_cast<const D &>(*this))->put_IsSuppressed(value));
}

template <typename D> bool impl_IPhoneCallHistoryEntry<D>::IsVoicemail() const
{
    bool value {};
    check_hresult(static_cast<const IPhoneCallHistoryEntry &>(static_cast<const D &>(*this))->get_IsVoicemail(&value));
    return value;
}

template <typename D> void impl_IPhoneCallHistoryEntry<D>::IsVoicemail(bool value) const
{
    check_hresult(static_cast<const IPhoneCallHistoryEntry &>(static_cast<const D &>(*this))->put_IsVoicemail(value));
}

template <typename D> Windows::ApplicationModel::Calls::PhoneCallHistoryEntryMedia impl_IPhoneCallHistoryEntry<D>::Media() const
{
    Windows::ApplicationModel::Calls::PhoneCallHistoryEntryMedia value {};
    check_hresult(static_cast<const IPhoneCallHistoryEntry &>(static_cast<const D &>(*this))->get_Media(&value));
    return value;
}

template <typename D> void impl_IPhoneCallHistoryEntry<D>::Media(Windows::ApplicationModel::Calls::PhoneCallHistoryEntryMedia value) const
{
    check_hresult(static_cast<const IPhoneCallHistoryEntry &>(static_cast<const D &>(*this))->put_Media(value));
}

template <typename D> Windows::ApplicationModel::Calls::PhoneCallHistoryEntryOtherAppReadAccess impl_IPhoneCallHistoryEntry<D>::OtherAppReadAccess() const
{
    Windows::ApplicationModel::Calls::PhoneCallHistoryEntryOtherAppReadAccess value {};
    check_hresult(static_cast<const IPhoneCallHistoryEntry &>(static_cast<const D &>(*this))->get_OtherAppReadAccess(&value));
    return value;
}

template <typename D> void impl_IPhoneCallHistoryEntry<D>::OtherAppReadAccess(Windows::ApplicationModel::Calls::PhoneCallHistoryEntryOtherAppReadAccess value) const
{
    check_hresult(static_cast<const IPhoneCallHistoryEntry &>(static_cast<const D &>(*this))->put_OtherAppReadAccess(value));
}

template <typename D> hstring impl_IPhoneCallHistoryEntry<D>::RemoteId() const
{
    hstring value;
    check_hresult(static_cast<const IPhoneCallHistoryEntry &>(static_cast<const D &>(*this))->get_RemoteId(put(value)));
    return value;
}

template <typename D> void impl_IPhoneCallHistoryEntry<D>::RemoteId(hstring_ref value) const
{
    check_hresult(static_cast<const IPhoneCallHistoryEntry &>(static_cast<const D &>(*this))->put_RemoteId(get(value)));
}

template <typename D> hstring impl_IPhoneCallHistoryEntry<D>::SourceDisplayName() const
{
    hstring value;
    check_hresult(static_cast<const IPhoneCallHistoryEntry &>(static_cast<const D &>(*this))->get_SourceDisplayName(put(value)));
    return value;
}

template <typename D> hstring impl_IPhoneCallHistoryEntry<D>::SourceId() const
{
    hstring value;
    check_hresult(static_cast<const IPhoneCallHistoryEntry &>(static_cast<const D &>(*this))->get_SourceId(put(value)));
    return value;
}

template <typename D> void impl_IPhoneCallHistoryEntry<D>::SourceId(hstring_ref value) const
{
    check_hresult(static_cast<const IPhoneCallHistoryEntry &>(static_cast<const D &>(*this))->put_SourceId(get(value)));
}

template <typename D> Windows::ApplicationModel::Calls::PhoneCallHistorySourceIdKind impl_IPhoneCallHistoryEntry<D>::SourceIdKind() const
{
    Windows::ApplicationModel::Calls::PhoneCallHistorySourceIdKind value {};
    check_hresult(static_cast<const IPhoneCallHistoryEntry &>(static_cast<const D &>(*this))->get_SourceIdKind(&value));
    return value;
}

template <typename D> void impl_IPhoneCallHistoryEntry<D>::SourceIdKind(Windows::ApplicationModel::Calls::PhoneCallHistorySourceIdKind value) const
{
    check_hresult(static_cast<const IPhoneCallHistoryEntry &>(static_cast<const D &>(*this))->put_SourceIdKind(value));
}

template <typename D> Windows::Foundation::DateTime impl_IPhoneCallHistoryEntry<D>::StartTime() const
{
    Windows::Foundation::DateTime value {};
    check_hresult(static_cast<const IPhoneCallHistoryEntry &>(static_cast<const D &>(*this))->get_StartTime(put(value)));
    return value;
}

template <typename D> void impl_IPhoneCallHistoryEntry<D>::StartTime(const Windows::Foundation::DateTime & value) const
{
    check_hresult(static_cast<const IPhoneCallHistoryEntry &>(static_cast<const D &>(*this))->put_StartTime(get(value)));
}

template <typename D> hstring impl_IPhoneCallHistoryEntryAddress<D>::ContactId() const
{
    hstring value;
    check_hresult(static_cast<const IPhoneCallHistoryEntryAddress &>(static_cast<const D &>(*this))->get_ContactId(put(value)));
    return value;
}

template <typename D> void impl_IPhoneCallHistoryEntryAddress<D>::ContactId(hstring_ref value) const
{
    check_hresult(static_cast<const IPhoneCallHistoryEntryAddress &>(static_cast<const D &>(*this))->put_ContactId(get(value)));
}

template <typename D> hstring impl_IPhoneCallHistoryEntryAddress<D>::DisplayName() const
{
    hstring value;
    check_hresult(static_cast<const IPhoneCallHistoryEntryAddress &>(static_cast<const D &>(*this))->get_DisplayName(put(value)));
    return value;
}

template <typename D> void impl_IPhoneCallHistoryEntryAddress<D>::DisplayName(hstring_ref value) const
{
    check_hresult(static_cast<const IPhoneCallHistoryEntryAddress &>(static_cast<const D &>(*this))->put_DisplayName(get(value)));
}

template <typename D> hstring impl_IPhoneCallHistoryEntryAddress<D>::RawAddress() const
{
    hstring value;
    check_hresult(static_cast<const IPhoneCallHistoryEntryAddress &>(static_cast<const D &>(*this))->get_RawAddress(put(value)));
    return value;
}

template <typename D> void impl_IPhoneCallHistoryEntryAddress<D>::RawAddress(hstring_ref value) const
{
    check_hresult(static_cast<const IPhoneCallHistoryEntryAddress &>(static_cast<const D &>(*this))->put_RawAddress(get(value)));
}

template <typename D> Windows::ApplicationModel::Calls::PhoneCallHistoryEntryRawAddressKind impl_IPhoneCallHistoryEntryAddress<D>::RawAddressKind() const
{
    Windows::ApplicationModel::Calls::PhoneCallHistoryEntryRawAddressKind value {};
    check_hresult(static_cast<const IPhoneCallHistoryEntryAddress &>(static_cast<const D &>(*this))->get_RawAddressKind(&value));
    return value;
}

template <typename D> void impl_IPhoneCallHistoryEntryAddress<D>::RawAddressKind(Windows::ApplicationModel::Calls::PhoneCallHistoryEntryRawAddressKind value) const
{
    check_hresult(static_cast<const IPhoneCallHistoryEntryAddress &>(static_cast<const D &>(*this))->put_RawAddressKind(value));
}

template <typename D> Windows::ApplicationModel::Calls::PhoneCallHistoryEntryAddress impl_IPhoneCallHistoryEntryAddressFactory<D>::Create(hstring_ref rawAddress, Windows::ApplicationModel::Calls::PhoneCallHistoryEntryRawAddressKind rawAddressKind) const
{
    Windows::ApplicationModel::Calls::PhoneCallHistoryEntryAddress result { nullptr };
    check_hresult(static_cast<const IPhoneCallHistoryEntryAddressFactory &>(static_cast<const D &>(*this))->abi_Create(get(rawAddress), rawAddressKind, put(result)));
    return result;
}

template <typename D> Windows::ApplicationModel::Calls::PhoneCallHistoryEntryQueryDesiredMedia impl_IPhoneCallHistoryEntryQueryOptions<D>::DesiredMedia() const
{
    Windows::ApplicationModel::Calls::PhoneCallHistoryEntryQueryDesiredMedia value {};
    check_hresult(static_cast<const IPhoneCallHistoryEntryQueryOptions &>(static_cast<const D &>(*this))->get_DesiredMedia(&value));
    return value;
}

template <typename D> void impl_IPhoneCallHistoryEntryQueryOptions<D>::DesiredMedia(Windows::ApplicationModel::Calls::PhoneCallHistoryEntryQueryDesiredMedia value) const
{
    check_hresult(static_cast<const IPhoneCallHistoryEntryQueryOptions &>(static_cast<const D &>(*this))->put_DesiredMedia(value));
}

template <typename D> Windows::Foundation::Collections::IVector<hstring> impl_IPhoneCallHistoryEntryQueryOptions<D>::SourceIds() const
{
    Windows::Foundation::Collections::IVector<hstring> value;
    check_hresult(static_cast<const IPhoneCallHistoryEntryQueryOptions &>(static_cast<const D &>(*this))->get_SourceIds(put(value)));
    return value;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::ApplicationModel::Calls::PhoneCallHistoryEntry>> impl_IPhoneCallHistoryEntryReader<D>::ReadBatchAsync() const
{
    Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::ApplicationModel::Calls::PhoneCallHistoryEntry>> result;
    check_hresult(static_cast<const IPhoneCallHistoryEntryReader &>(static_cast<const D &>(*this))->abi_ReadBatchAsync(put(result)));
    return result;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Calls::PhoneCallHistoryEntry> impl_IPhoneCallHistoryStore<D>::GetEntryAsync(hstring_ref callHistoryEntryId) const
{
    Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Calls::PhoneCallHistoryEntry> result;
    check_hresult(static_cast<const IPhoneCallHistoryStore &>(static_cast<const D &>(*this))->abi_GetEntryAsync(get(callHistoryEntryId), put(result)));
    return result;
}

template <typename D> Windows::ApplicationModel::Calls::PhoneCallHistoryEntryReader impl_IPhoneCallHistoryStore<D>::GetEntryReader() const
{
    Windows::ApplicationModel::Calls::PhoneCallHistoryEntryReader result { nullptr };
    check_hresult(static_cast<const IPhoneCallHistoryStore &>(static_cast<const D &>(*this))->abi_GetEntryReader(put(result)));
    return result;
}

template <typename D> Windows::ApplicationModel::Calls::PhoneCallHistoryEntryReader impl_IPhoneCallHistoryStore<D>::GetEntryReader(const Windows::ApplicationModel::Calls::PhoneCallHistoryEntryQueryOptions & queryOptions) const
{
    Windows::ApplicationModel::Calls::PhoneCallHistoryEntryReader result { nullptr };
    check_hresult(static_cast<const IPhoneCallHistoryStore &>(static_cast<const D &>(*this))->abi_GetEntryReaderWithOptions(get(queryOptions), put(result)));
    return result;
}

template <typename D> Windows::Foundation::IAsyncAction impl_IPhoneCallHistoryStore<D>::SaveEntryAsync(const Windows::ApplicationModel::Calls::PhoneCallHistoryEntry & callHistoryEntry) const
{
    Windows::Foundation::IAsyncAction result;
    check_hresult(static_cast<const IPhoneCallHistoryStore &>(static_cast<const D &>(*this))->abi_SaveEntryAsync(get(callHistoryEntry), put(result)));
    return result;
}

template <typename D> Windows::Foundation::IAsyncAction impl_IPhoneCallHistoryStore<D>::DeleteEntryAsync(const Windows::ApplicationModel::Calls::PhoneCallHistoryEntry & callHistoryEntry) const
{
    Windows::Foundation::IAsyncAction result;
    check_hresult(static_cast<const IPhoneCallHistoryStore &>(static_cast<const D &>(*this))->abi_DeleteEntryAsync(get(callHistoryEntry), put(result)));
    return result;
}

template <typename D> Windows::Foundation::IAsyncAction impl_IPhoneCallHistoryStore<D>::DeleteEntriesAsync(const Windows::Foundation::Collections::IIterable<Windows::ApplicationModel::Calls::PhoneCallHistoryEntry> & callHistoryEntries) const
{
    Windows::Foundation::IAsyncAction result;
    check_hresult(static_cast<const IPhoneCallHistoryStore &>(static_cast<const D &>(*this))->abi_DeleteEntriesAsync(get(callHistoryEntries), put(result)));
    return result;
}

template <typename D> Windows::Foundation::IAsyncAction impl_IPhoneCallHistoryStore<D>::MarkEntryAsSeenAsync(const Windows::ApplicationModel::Calls::PhoneCallHistoryEntry & callHistoryEntry) const
{
    Windows::Foundation::IAsyncAction result;
    check_hresult(static_cast<const IPhoneCallHistoryStore &>(static_cast<const D &>(*this))->abi_MarkEntryAsSeenAsync(get(callHistoryEntry), put(result)));
    return result;
}

template <typename D> Windows::Foundation::IAsyncAction impl_IPhoneCallHistoryStore<D>::MarkEntriesAsSeenAsync(const Windows::Foundation::Collections::IIterable<Windows::ApplicationModel::Calls::PhoneCallHistoryEntry> & callHistoryEntries) const
{
    Windows::Foundation::IAsyncAction result;
    check_hresult(static_cast<const IPhoneCallHistoryStore &>(static_cast<const D &>(*this))->abi_MarkEntriesAsSeenAsync(get(callHistoryEntries), put(result)));
    return result;
}

template <typename D> Windows::Foundation::IAsyncOperation<uint32_t> impl_IPhoneCallHistoryStore<D>::GetUnseenCountAsync() const
{
    Windows::Foundation::IAsyncOperation<uint32_t> result;
    check_hresult(static_cast<const IPhoneCallHistoryStore &>(static_cast<const D &>(*this))->abi_GetUnseenCountAsync(put(result)));
    return result;
}

template <typename D> Windows::Foundation::IAsyncAction impl_IPhoneCallHistoryStore<D>::MarkAllAsSeenAsync() const
{
    Windows::Foundation::IAsyncAction result;
    check_hresult(static_cast<const IPhoneCallHistoryStore &>(static_cast<const D &>(*this))->abi_MarkAllAsSeenAsync(put(result)));
    return result;
}

template <typename D> Windows::Foundation::IAsyncOperation<uint32_t> impl_IPhoneCallHistoryStore<D>::GetSourcesUnseenCountAsync(const Windows::Foundation::Collections::IIterable<hstring> & sourceIds) const
{
    Windows::Foundation::IAsyncOperation<uint32_t> result;
    check_hresult(static_cast<const IPhoneCallHistoryStore &>(static_cast<const D &>(*this))->abi_GetSourcesUnseenCountAsync(get(sourceIds), put(result)));
    return result;
}

template <typename D> Windows::Foundation::IAsyncAction impl_IPhoneCallHistoryStore<D>::MarkSourcesAsSeenAsync(const Windows::Foundation::Collections::IIterable<hstring> & sourceIds) const
{
    Windows::Foundation::IAsyncAction result;
    check_hresult(static_cast<const IPhoneCallHistoryStore &>(static_cast<const D &>(*this))->abi_MarkSourcesAsSeenAsync(get(sourceIds), put(result)));
    return result;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Calls::PhoneCallHistoryStore> impl_IPhoneCallHistoryManagerStatics<D>::RequestStoreAsync(Windows::ApplicationModel::Calls::PhoneCallHistoryStoreAccessType accessType) const
{
    Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Calls::PhoneCallHistoryStore> result;
    check_hresult(static_cast<const IPhoneCallHistoryManagerStatics &>(static_cast<const D &>(*this))->abi_RequestStoreAsync(accessType, put(result)));
    return result;
}

template <typename D> Windows::ApplicationModel::Calls::PhoneCallHistoryManagerForUser impl_IPhoneCallHistoryManagerStatics2<D>::GetForUser(const Windows::System::User & user) const
{
    Windows::ApplicationModel::Calls::PhoneCallHistoryManagerForUser result { nullptr };
    check_hresult(static_cast<const IPhoneCallHistoryManagerStatics2 &>(static_cast<const D &>(*this))->abi_GetForUser(get(user), put(result)));
    return result;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Calls::PhoneCallHistoryStore> impl_IPhoneCallHistoryManagerForUser<D>::RequestStoreAsync(Windows::ApplicationModel::Calls::PhoneCallHistoryStoreAccessType accessType) const
{
    Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Calls::PhoneCallHistoryStore> result;
    check_hresult(static_cast<const IPhoneCallHistoryManagerForUser &>(static_cast<const D &>(*this))->abi_RequestStoreAsync(accessType, put(result)));
    return result;
}

template <typename D> Windows::System::User impl_IPhoneCallHistoryManagerForUser<D>::User() const
{
    Windows::System::User value { nullptr };
    check_hresult(static_cast<const IPhoneCallHistoryManagerForUser &>(static_cast<const D &>(*this))->get_User(put(value)));
    return value;
}

inline PhoneCallHistoryEntry::PhoneCallHistoryEntry() :
    PhoneCallHistoryEntry(activate_instance<PhoneCallHistoryEntry>())
{}

inline PhoneCallHistoryEntryAddress::PhoneCallHistoryEntryAddress() :
    PhoneCallHistoryEntryAddress(activate_instance<PhoneCallHistoryEntryAddress>())
{}

inline PhoneCallHistoryEntryAddress::PhoneCallHistoryEntryAddress(hstring_ref rawAddress, Windows::ApplicationModel::Calls::PhoneCallHistoryEntryRawAddressKind rawAddressKind) :
    PhoneCallHistoryEntryAddress(get_activation_factory<PhoneCallHistoryEntryAddress, IPhoneCallHistoryEntryAddressFactory>().Create(rawAddress, rawAddressKind))
{}

inline PhoneCallHistoryEntryQueryOptions::PhoneCallHistoryEntryQueryOptions() :
    PhoneCallHistoryEntryQueryOptions(activate_instance<PhoneCallHistoryEntryQueryOptions>())
{}

inline Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Calls::PhoneCallHistoryStore> PhoneCallHistoryManager::RequestStoreAsync(Windows::ApplicationModel::Calls::PhoneCallHistoryStoreAccessType accessType)
{
    return get_activation_factory<PhoneCallHistoryManager, IPhoneCallHistoryManagerStatics>().RequestStoreAsync(accessType);
}

inline Windows::ApplicationModel::Calls::PhoneCallHistoryManagerForUser PhoneCallHistoryManager::GetForUser(const Windows::System::User & user)
{
    return get_activation_factory<PhoneCallHistoryManager, IPhoneCallHistoryManagerStatics2>().GetForUser(user);
}

inline Windows::ApplicationModel::Calls::VoipCallCoordinator VoipCallCoordinator::GetDefault()
{
    return get_activation_factory<VoipCallCoordinator, IVoipCallCoordinatorStatics>().GetDefault();
}

}

}
