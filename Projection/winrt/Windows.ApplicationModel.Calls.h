// C++ for the Windows Runtime v1.0.private
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "base.h"
WINRT_WARNING_PUSH

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
            *value = detach_abi(this->shim().AcceptedMedia());
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
            *value = detach_abi(this->shim().RejectReason());
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
            *value = detach_abi(this->shim().State());
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
            *value = detach_abi(this->shim().Muted());
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
    HRESULT __stdcall get_Id(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Id());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Address(impl::abi_arg_out<Windows::ApplicationModel::Calls::IPhoneCallHistoryEntryAddress> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Address());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Address(impl::abi_arg_in<Windows::ApplicationModel::Calls::IPhoneCallHistoryEntryAddress> value) noexcept override
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

    HRESULT __stdcall get_Duration(impl::abi_arg_out<Windows::Foundation::IReference<Windows::Foundation::TimeSpan>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Duration());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Duration(impl::abi_arg_in<Windows::Foundation::IReference<Windows::Foundation::TimeSpan>> value) noexcept override
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
            *value = detach_abi(this->shim().IsCallerIdBlocked());
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
            *value = detach_abi(this->shim().IsEmergency());
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
            *value = detach_abi(this->shim().IsIncoming());
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
            *value = detach_abi(this->shim().IsMissed());
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
            *value = detach_abi(this->shim().IsRinging());
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
            *value = detach_abi(this->shim().IsSeen());
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
            *value = detach_abi(this->shim().IsSuppressed());
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
            *value = detach_abi(this->shim().IsVoicemail());
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
            *value = detach_abi(this->shim().Media());
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
            *value = detach_abi(this->shim().OtherAppReadAccess());
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

    HRESULT __stdcall get_RemoteId(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().RemoteId());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_RemoteId(impl::abi_arg_in<hstring> value) noexcept override
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

    HRESULT __stdcall get_SourceDisplayName(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().SourceDisplayName());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_SourceId(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().SourceId());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_SourceId(impl::abi_arg_in<hstring> value) noexcept override
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
            *value = detach_abi(this->shim().SourceIdKind());
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

    HRESULT __stdcall get_StartTime(impl::abi_arg_out<Windows::Foundation::DateTime> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().StartTime());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_StartTime(impl::abi_arg_in<Windows::Foundation::DateTime> value) noexcept override
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
    HRESULT __stdcall get_ContactId(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ContactId());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_ContactId(impl::abi_arg_in<hstring> value) noexcept override
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

    HRESULT __stdcall get_DisplayName(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().DisplayName());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_DisplayName(impl::abi_arg_in<hstring> value) noexcept override
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

    HRESULT __stdcall get_RawAddress(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().RawAddress());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_RawAddress(impl::abi_arg_in<hstring> value) noexcept override
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
            *value = detach_abi(this->shim().RawAddressKind());
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
    HRESULT __stdcall abi_Create(impl::abi_arg_in<hstring> rawAddress, Windows::ApplicationModel::Calls::PhoneCallHistoryEntryRawAddressKind rawAddressKind, impl::abi_arg_out<Windows::ApplicationModel::Calls::IPhoneCallHistoryEntryAddress> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().Create(*reinterpret_cast<const hstring *>(&rawAddress), rawAddressKind));
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
            *value = detach_abi(this->shim().DesiredMedia());
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

    HRESULT __stdcall get_SourceIds(impl::abi_arg_out<Windows::Foundation::Collections::IVector<hstring>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().SourceIds());
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
    HRESULT __stdcall abi_ReadBatchAsync(impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::ApplicationModel::Calls::PhoneCallHistoryEntry>>> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().ReadBatchAsync());
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
    HRESULT __stdcall abi_RequestStoreAsync(Windows::ApplicationModel::Calls::PhoneCallHistoryStoreAccessType accessType, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Calls::PhoneCallHistoryStore>> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().RequestStoreAsync(accessType));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_User(impl::abi_arg_out<Windows::System::IUser> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().User());
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
    HRESULT __stdcall abi_RequestStoreAsync(Windows::ApplicationModel::Calls::PhoneCallHistoryStoreAccessType accessType, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Calls::PhoneCallHistoryStore>> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().RequestStoreAsync(accessType));
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
    HRESULT __stdcall abi_GetForUser(impl::abi_arg_in<Windows::System::IUser> user, impl::abi_arg_out<Windows::ApplicationModel::Calls::IPhoneCallHistoryManagerForUser> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().GetForUser(*reinterpret_cast<const Windows::System::User *>(&user)));
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
    HRESULT __stdcall abi_GetEntryAsync(impl::abi_arg_in<hstring> callHistoryEntryId, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Calls::PhoneCallHistoryEntry>> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().GetEntryAsync(*reinterpret_cast<const hstring *>(&callHistoryEntryId)));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetEntryReader(impl::abi_arg_out<Windows::ApplicationModel::Calls::IPhoneCallHistoryEntryReader> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().GetEntryReader());
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetEntryReaderWithOptions(impl::abi_arg_in<Windows::ApplicationModel::Calls::IPhoneCallHistoryEntryQueryOptions> queryOptions, impl::abi_arg_out<Windows::ApplicationModel::Calls::IPhoneCallHistoryEntryReader> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().GetEntryReader(*reinterpret_cast<const Windows::ApplicationModel::Calls::PhoneCallHistoryEntryQueryOptions *>(&queryOptions)));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_SaveEntryAsync(impl::abi_arg_in<Windows::ApplicationModel::Calls::IPhoneCallHistoryEntry> callHistoryEntry, impl::abi_arg_out<Windows::Foundation::IAsyncAction> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().SaveEntryAsync(*reinterpret_cast<const Windows::ApplicationModel::Calls::PhoneCallHistoryEntry *>(&callHistoryEntry)));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_DeleteEntryAsync(impl::abi_arg_in<Windows::ApplicationModel::Calls::IPhoneCallHistoryEntry> callHistoryEntry, impl::abi_arg_out<Windows::Foundation::IAsyncAction> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().DeleteEntryAsync(*reinterpret_cast<const Windows::ApplicationModel::Calls::PhoneCallHistoryEntry *>(&callHistoryEntry)));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_DeleteEntriesAsync(impl::abi_arg_in<Windows::Foundation::Collections::IIterable<Windows::ApplicationModel::Calls::PhoneCallHistoryEntry>> callHistoryEntries, impl::abi_arg_out<Windows::Foundation::IAsyncAction> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().DeleteEntriesAsync(*reinterpret_cast<const Windows::Foundation::Collections::IIterable<Windows::ApplicationModel::Calls::PhoneCallHistoryEntry> *>(&callHistoryEntries)));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_MarkEntryAsSeenAsync(impl::abi_arg_in<Windows::ApplicationModel::Calls::IPhoneCallHistoryEntry> callHistoryEntry, impl::abi_arg_out<Windows::Foundation::IAsyncAction> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().MarkEntryAsSeenAsync(*reinterpret_cast<const Windows::ApplicationModel::Calls::PhoneCallHistoryEntry *>(&callHistoryEntry)));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_MarkEntriesAsSeenAsync(impl::abi_arg_in<Windows::Foundation::Collections::IIterable<Windows::ApplicationModel::Calls::PhoneCallHistoryEntry>> callHistoryEntries, impl::abi_arg_out<Windows::Foundation::IAsyncAction> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().MarkEntriesAsSeenAsync(*reinterpret_cast<const Windows::Foundation::Collections::IIterable<Windows::ApplicationModel::Calls::PhoneCallHistoryEntry> *>(&callHistoryEntries)));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetUnseenCountAsync(impl::abi_arg_out<Windows::Foundation::IAsyncOperation<uint32_t>> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().GetUnseenCountAsync());
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_MarkAllAsSeenAsync(impl::abi_arg_out<Windows::Foundation::IAsyncAction> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().MarkAllAsSeenAsync());
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetSourcesUnseenCountAsync(impl::abi_arg_in<Windows::Foundation::Collections::IIterable<hstring>> sourceIds, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<uint32_t>> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().GetSourcesUnseenCountAsync(*reinterpret_cast<const Windows::Foundation::Collections::IIterable<hstring> *>(&sourceIds)));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_MarkSourcesAsSeenAsync(impl::abi_arg_in<Windows::Foundation::Collections::IIterable<hstring>> sourceIds, impl::abi_arg_out<Windows::Foundation::IAsyncAction> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().MarkSourcesAsSeenAsync(*reinterpret_cast<const Windows::Foundation::Collections::IIterable<hstring> *>(&sourceIds)));
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
    HRESULT __stdcall abi_ReserveCallResourcesAsync(impl::abi_arg_in<hstring> taskEntryPoint, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<winrt::Windows::ApplicationModel::Calls::VoipPhoneCallResourceReservationStatus>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().ReserveCallResourcesAsync(*reinterpret_cast<const hstring *>(&taskEntryPoint)));
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_MuteStateChanged(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Calls::VoipCallCoordinator, Windows::ApplicationModel::Calls::MuteChangeEventArgs>> muteChangeHandler, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().MuteStateChanged(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Calls::VoipCallCoordinator, Windows::ApplicationModel::Calls::MuteChangeEventArgs> *>(&muteChangeHandler)));
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

    HRESULT __stdcall abi_RequestNewIncomingCall(impl::abi_arg_in<hstring> context, impl::abi_arg_in<hstring> contactName, impl::abi_arg_in<hstring> contactNumber, impl::abi_arg_in<Windows::Foundation::IUriRuntimeClass> contactImage, impl::abi_arg_in<hstring> serviceName, impl::abi_arg_in<Windows::Foundation::IUriRuntimeClass> brandingImage, impl::abi_arg_in<hstring> callDetails, impl::abi_arg_in<Windows::Foundation::IUriRuntimeClass> ringtone, Windows::ApplicationModel::Calls::VoipPhoneCallMedia media, impl::abi_arg_in<Windows::Foundation::TimeSpan> ringTimeout, impl::abi_arg_out<Windows::ApplicationModel::Calls::IVoipPhoneCall> call) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *call = detach_abi(this->shim().RequestNewIncomingCall(*reinterpret_cast<const hstring *>(&context), *reinterpret_cast<const hstring *>(&contactName), *reinterpret_cast<const hstring *>(&contactNumber), *reinterpret_cast<const Windows::Foundation::Uri *>(&contactImage), *reinterpret_cast<const hstring *>(&serviceName), *reinterpret_cast<const Windows::Foundation::Uri *>(&brandingImage), *reinterpret_cast<const hstring *>(&callDetails), *reinterpret_cast<const Windows::Foundation::Uri *>(&ringtone), media, *reinterpret_cast<const Windows::Foundation::TimeSpan *>(&ringTimeout)));
            return S_OK;
        }
        catch (...)
        {
            *call = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_RequestNewOutgoingCall(impl::abi_arg_in<hstring> context, impl::abi_arg_in<hstring> contactName, impl::abi_arg_in<hstring> serviceName, Windows::ApplicationModel::Calls::VoipPhoneCallMedia media, impl::abi_arg_out<Windows::ApplicationModel::Calls::IVoipPhoneCall> call) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *call = detach_abi(this->shim().RequestNewOutgoingCall(*reinterpret_cast<const hstring *>(&context), *reinterpret_cast<const hstring *>(&contactName), *reinterpret_cast<const hstring *>(&serviceName), media));
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

    HRESULT __stdcall abi_RequestOutgoingUpgradeToVideoCall(GUID callUpgradeGuid, impl::abi_arg_in<hstring> context, impl::abi_arg_in<hstring> contactName, impl::abi_arg_in<hstring> serviceName, impl::abi_arg_out<Windows::ApplicationModel::Calls::IVoipPhoneCall> call) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *call = detach_abi(this->shim().RequestOutgoingUpgradeToVideoCall(callUpgradeGuid, *reinterpret_cast<const hstring *>(&context), *reinterpret_cast<const hstring *>(&contactName), *reinterpret_cast<const hstring *>(&serviceName)));
            return S_OK;
        }
        catch (...)
        {
            *call = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_RequestIncomingUpgradeToVideoCall(impl::abi_arg_in<hstring> context, impl::abi_arg_in<hstring> contactName, impl::abi_arg_in<hstring> contactNumber, impl::abi_arg_in<Windows::Foundation::IUriRuntimeClass> contactImage, impl::abi_arg_in<hstring> serviceName, impl::abi_arg_in<Windows::Foundation::IUriRuntimeClass> brandingImage, impl::abi_arg_in<hstring> callDetails, impl::abi_arg_in<Windows::Foundation::IUriRuntimeClass> ringtone, impl::abi_arg_in<Windows::Foundation::TimeSpan> ringTimeout, impl::abi_arg_out<Windows::ApplicationModel::Calls::IVoipPhoneCall> call) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *call = detach_abi(this->shim().RequestIncomingUpgradeToVideoCall(*reinterpret_cast<const hstring *>(&context), *reinterpret_cast<const hstring *>(&contactName), *reinterpret_cast<const hstring *>(&contactNumber), *reinterpret_cast<const Windows::Foundation::Uri *>(&contactImage), *reinterpret_cast<const hstring *>(&serviceName), *reinterpret_cast<const Windows::Foundation::Uri *>(&brandingImage), *reinterpret_cast<const hstring *>(&callDetails), *reinterpret_cast<const Windows::Foundation::Uri *>(&ringtone), *reinterpret_cast<const Windows::Foundation::TimeSpan *>(&ringTimeout)));
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
    HRESULT __stdcall abi_GetDefault(impl::abi_arg_out<Windows::ApplicationModel::Calls::IVoipCallCoordinator> coordinator) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *coordinator = detach_abi(this->shim().GetDefault());
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
    HRESULT __stdcall add_EndRequested(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Calls::VoipPhoneCall, Windows::ApplicationModel::Calls::CallStateChangeEventArgs>> handler, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().EndRequested(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Calls::VoipPhoneCall, Windows::ApplicationModel::Calls::CallStateChangeEventArgs> *>(&handler)));
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

    HRESULT __stdcall add_HoldRequested(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Calls::VoipPhoneCall, Windows::ApplicationModel::Calls::CallStateChangeEventArgs>> handler, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().HoldRequested(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Calls::VoipPhoneCall, Windows::ApplicationModel::Calls::CallStateChangeEventArgs> *>(&handler)));
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

    HRESULT __stdcall add_ResumeRequested(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Calls::VoipPhoneCall, Windows::ApplicationModel::Calls::CallStateChangeEventArgs>> handler, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().ResumeRequested(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Calls::VoipPhoneCall, Windows::ApplicationModel::Calls::CallStateChangeEventArgs> *>(&handler)));
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

    HRESULT __stdcall add_AnswerRequested(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Calls::VoipPhoneCall, Windows::ApplicationModel::Calls::CallAnswerEventArgs>> acceptHandler, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().AnswerRequested(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Calls::VoipPhoneCall, Windows::ApplicationModel::Calls::CallAnswerEventArgs> *>(&acceptHandler)));
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

    HRESULT __stdcall add_RejectRequested(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Calls::VoipPhoneCall, Windows::ApplicationModel::Calls::CallRejectEventArgs>> rejectHandler, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().RejectRequested(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Calls::VoipPhoneCall, Windows::ApplicationModel::Calls::CallRejectEventArgs> *>(&rejectHandler)));
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

    HRESULT __stdcall get_ContactName(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ContactName());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_ContactName(impl::abi_arg_in<hstring> value) noexcept override
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

    HRESULT __stdcall get_StartTime(impl::abi_arg_out<Windows::Foundation::DateTime> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().StartTime());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_StartTime(impl::abi_arg_in<Windows::Foundation::DateTime> value) noexcept override
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
            *value = detach_abi(this->shim().CallMedia());
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
    check_hresult(WINRT_SHIM(ICallStateChangeEventArgs)->get_State(&value));
    return value;
}

template <typename D> Windows::ApplicationModel::Calls::VoipPhoneCallMedia impl_ICallAnswerEventArgs<D>::AcceptedMedia() const
{
    Windows::ApplicationModel::Calls::VoipPhoneCallMedia value {};
    check_hresult(WINRT_SHIM(ICallAnswerEventArgs)->get_AcceptedMedia(&value));
    return value;
}

template <typename D> Windows::ApplicationModel::Calls::VoipPhoneCallRejectReason impl_ICallRejectEventArgs<D>::RejectReason() const
{
    Windows::ApplicationModel::Calls::VoipPhoneCallRejectReason value {};
    check_hresult(WINRT_SHIM(ICallRejectEventArgs)->get_RejectReason(&value));
    return value;
}

template <typename D> event_token impl_IVoipPhoneCall<D>::EndRequested(const Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Calls::VoipPhoneCall, Windows::ApplicationModel::Calls::CallStateChangeEventArgs> & handler) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(IVoipPhoneCall)->add_EndRequested(get_abi(handler), &token));
    return token;
}

template <typename D> event_revoker<IVoipPhoneCall> impl_IVoipPhoneCall<D>::EndRequested(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Calls::VoipPhoneCall, Windows::ApplicationModel::Calls::CallStateChangeEventArgs> & handler) const
{
    return impl::make_event_revoker<D, IVoipPhoneCall>(this, &ABI::Windows::ApplicationModel::Calls::IVoipPhoneCall::remove_EndRequested, EndRequested(handler));
}

template <typename D> void impl_IVoipPhoneCall<D>::EndRequested(event_token token) const
{
    check_hresult(WINRT_SHIM(IVoipPhoneCall)->remove_EndRequested(token));
}

template <typename D> event_token impl_IVoipPhoneCall<D>::HoldRequested(const Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Calls::VoipPhoneCall, Windows::ApplicationModel::Calls::CallStateChangeEventArgs> & handler) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(IVoipPhoneCall)->add_HoldRequested(get_abi(handler), &token));
    return token;
}

template <typename D> event_revoker<IVoipPhoneCall> impl_IVoipPhoneCall<D>::HoldRequested(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Calls::VoipPhoneCall, Windows::ApplicationModel::Calls::CallStateChangeEventArgs> & handler) const
{
    return impl::make_event_revoker<D, IVoipPhoneCall>(this, &ABI::Windows::ApplicationModel::Calls::IVoipPhoneCall::remove_HoldRequested, HoldRequested(handler));
}

template <typename D> void impl_IVoipPhoneCall<D>::HoldRequested(event_token token) const
{
    check_hresult(WINRT_SHIM(IVoipPhoneCall)->remove_HoldRequested(token));
}

template <typename D> event_token impl_IVoipPhoneCall<D>::ResumeRequested(const Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Calls::VoipPhoneCall, Windows::ApplicationModel::Calls::CallStateChangeEventArgs> & handler) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(IVoipPhoneCall)->add_ResumeRequested(get_abi(handler), &token));
    return token;
}

template <typename D> event_revoker<IVoipPhoneCall> impl_IVoipPhoneCall<D>::ResumeRequested(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Calls::VoipPhoneCall, Windows::ApplicationModel::Calls::CallStateChangeEventArgs> & handler) const
{
    return impl::make_event_revoker<D, IVoipPhoneCall>(this, &ABI::Windows::ApplicationModel::Calls::IVoipPhoneCall::remove_ResumeRequested, ResumeRequested(handler));
}

template <typename D> void impl_IVoipPhoneCall<D>::ResumeRequested(event_token token) const
{
    check_hresult(WINRT_SHIM(IVoipPhoneCall)->remove_ResumeRequested(token));
}

template <typename D> event_token impl_IVoipPhoneCall<D>::AnswerRequested(const Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Calls::VoipPhoneCall, Windows::ApplicationModel::Calls::CallAnswerEventArgs> & acceptHandler) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(IVoipPhoneCall)->add_AnswerRequested(get_abi(acceptHandler), &token));
    return token;
}

template <typename D> event_revoker<IVoipPhoneCall> impl_IVoipPhoneCall<D>::AnswerRequested(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Calls::VoipPhoneCall, Windows::ApplicationModel::Calls::CallAnswerEventArgs> & acceptHandler) const
{
    return impl::make_event_revoker<D, IVoipPhoneCall>(this, &ABI::Windows::ApplicationModel::Calls::IVoipPhoneCall::remove_AnswerRequested, AnswerRequested(acceptHandler));
}

template <typename D> void impl_IVoipPhoneCall<D>::AnswerRequested(event_token token) const
{
    check_hresult(WINRT_SHIM(IVoipPhoneCall)->remove_AnswerRequested(token));
}

template <typename D> event_token impl_IVoipPhoneCall<D>::RejectRequested(const Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Calls::VoipPhoneCall, Windows::ApplicationModel::Calls::CallRejectEventArgs> & rejectHandler) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(IVoipPhoneCall)->add_RejectRequested(get_abi(rejectHandler), &token));
    return token;
}

template <typename D> event_revoker<IVoipPhoneCall> impl_IVoipPhoneCall<D>::RejectRequested(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Calls::VoipPhoneCall, Windows::ApplicationModel::Calls::CallRejectEventArgs> & rejectHandler) const
{
    return impl::make_event_revoker<D, IVoipPhoneCall>(this, &ABI::Windows::ApplicationModel::Calls::IVoipPhoneCall::remove_RejectRequested, RejectRequested(rejectHandler));
}

template <typename D> void impl_IVoipPhoneCall<D>::RejectRequested(event_token token) const
{
    check_hresult(WINRT_SHIM(IVoipPhoneCall)->remove_RejectRequested(token));
}

template <typename D> void impl_IVoipPhoneCall<D>::NotifyCallHeld() const
{
    check_hresult(WINRT_SHIM(IVoipPhoneCall)->abi_NotifyCallHeld());
}

template <typename D> void impl_IVoipPhoneCall<D>::NotifyCallActive() const
{
    check_hresult(WINRT_SHIM(IVoipPhoneCall)->abi_NotifyCallActive());
}

template <typename D> void impl_IVoipPhoneCall<D>::NotifyCallEnded() const
{
    check_hresult(WINRT_SHIM(IVoipPhoneCall)->abi_NotifyCallEnded());
}

template <typename D> hstring impl_IVoipPhoneCall<D>::ContactName() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IVoipPhoneCall)->get_ContactName(put_abi(value)));
    return value;
}

template <typename D> void impl_IVoipPhoneCall<D>::ContactName(hstring_view value) const
{
    check_hresult(WINRT_SHIM(IVoipPhoneCall)->put_ContactName(get_abi(value)));
}

template <typename D> Windows::Foundation::DateTime impl_IVoipPhoneCall<D>::StartTime() const
{
    Windows::Foundation::DateTime value {};
    check_hresult(WINRT_SHIM(IVoipPhoneCall)->get_StartTime(put_abi(value)));
    return value;
}

template <typename D> void impl_IVoipPhoneCall<D>::StartTime(const Windows::Foundation::DateTime & value) const
{
    check_hresult(WINRT_SHIM(IVoipPhoneCall)->put_StartTime(get_abi(value)));
}

template <typename D> Windows::ApplicationModel::Calls::VoipPhoneCallMedia impl_IVoipPhoneCall<D>::CallMedia() const
{
    Windows::ApplicationModel::Calls::VoipPhoneCallMedia value {};
    check_hresult(WINRT_SHIM(IVoipPhoneCall)->get_CallMedia(&value));
    return value;
}

template <typename D> void impl_IVoipPhoneCall<D>::CallMedia(Windows::ApplicationModel::Calls::VoipPhoneCallMedia value) const
{
    check_hresult(WINRT_SHIM(IVoipPhoneCall)->put_CallMedia(value));
}

template <typename D> void impl_IVoipPhoneCall<D>::NotifyCallReady() const
{
    check_hresult(WINRT_SHIM(IVoipPhoneCall)->abi_NotifyCallReady());
}

template <typename D> bool impl_IMuteChangeEventArgs<D>::Muted() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IMuteChangeEventArgs)->get_Muted(&value));
    return value;
}

template <typename D> Windows::Foundation::IAsyncOperation<winrt::Windows::ApplicationModel::Calls::VoipPhoneCallResourceReservationStatus> impl_IVoipCallCoordinator<D>::ReserveCallResourcesAsync(hstring_view taskEntryPoint) const
{
    Windows::Foundation::IAsyncOperation<winrt::Windows::ApplicationModel::Calls::VoipPhoneCallResourceReservationStatus> operation;
    check_hresult(WINRT_SHIM(IVoipCallCoordinator)->abi_ReserveCallResourcesAsync(get_abi(taskEntryPoint), put_abi(operation)));
    return operation;
}

template <typename D> event_token impl_IVoipCallCoordinator<D>::MuteStateChanged(const Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Calls::VoipCallCoordinator, Windows::ApplicationModel::Calls::MuteChangeEventArgs> & muteChangeHandler) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(IVoipCallCoordinator)->add_MuteStateChanged(get_abi(muteChangeHandler), &token));
    return token;
}

template <typename D> event_revoker<IVoipCallCoordinator> impl_IVoipCallCoordinator<D>::MuteStateChanged(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Calls::VoipCallCoordinator, Windows::ApplicationModel::Calls::MuteChangeEventArgs> & muteChangeHandler) const
{
    return impl::make_event_revoker<D, IVoipCallCoordinator>(this, &ABI::Windows::ApplicationModel::Calls::IVoipCallCoordinator::remove_MuteStateChanged, MuteStateChanged(muteChangeHandler));
}

template <typename D> void impl_IVoipCallCoordinator<D>::MuteStateChanged(event_token token) const
{
    check_hresult(WINRT_SHIM(IVoipCallCoordinator)->remove_MuteStateChanged(token));
}

template <typename D> Windows::ApplicationModel::Calls::VoipPhoneCall impl_IVoipCallCoordinator<D>::RequestNewIncomingCall(hstring_view context, hstring_view contactName, hstring_view contactNumber, const Windows::Foundation::Uri & contactImage, hstring_view serviceName, const Windows::Foundation::Uri & brandingImage, hstring_view callDetails, const Windows::Foundation::Uri & ringtone, Windows::ApplicationModel::Calls::VoipPhoneCallMedia media, const Windows::Foundation::TimeSpan & ringTimeout) const
{
    Windows::ApplicationModel::Calls::VoipPhoneCall call { nullptr };
    check_hresult(WINRT_SHIM(IVoipCallCoordinator)->abi_RequestNewIncomingCall(get_abi(context), get_abi(contactName), get_abi(contactNumber), get_abi(contactImage), get_abi(serviceName), get_abi(brandingImage), get_abi(callDetails), get_abi(ringtone), media, get_abi(ringTimeout), put_abi(call)));
    return call;
}

template <typename D> Windows::ApplicationModel::Calls::VoipPhoneCall impl_IVoipCallCoordinator<D>::RequestNewOutgoingCall(hstring_view context, hstring_view contactName, hstring_view serviceName, Windows::ApplicationModel::Calls::VoipPhoneCallMedia media) const
{
    Windows::ApplicationModel::Calls::VoipPhoneCall call { nullptr };
    check_hresult(WINRT_SHIM(IVoipCallCoordinator)->abi_RequestNewOutgoingCall(get_abi(context), get_abi(contactName), get_abi(serviceName), media, put_abi(call)));
    return call;
}

template <typename D> void impl_IVoipCallCoordinator<D>::NotifyMuted() const
{
    check_hresult(WINRT_SHIM(IVoipCallCoordinator)->abi_NotifyMuted());
}

template <typename D> void impl_IVoipCallCoordinator<D>::NotifyUnmuted() const
{
    check_hresult(WINRT_SHIM(IVoipCallCoordinator)->abi_NotifyUnmuted());
}

template <typename D> Windows::ApplicationModel::Calls::VoipPhoneCall impl_IVoipCallCoordinator<D>::RequestOutgoingUpgradeToVideoCall(GUID callUpgradeGuid, hstring_view context, hstring_view contactName, hstring_view serviceName) const
{
    Windows::ApplicationModel::Calls::VoipPhoneCall call { nullptr };
    check_hresult(WINRT_SHIM(IVoipCallCoordinator)->abi_RequestOutgoingUpgradeToVideoCall(callUpgradeGuid, get_abi(context), get_abi(contactName), get_abi(serviceName), put_abi(call)));
    return call;
}

template <typename D> Windows::ApplicationModel::Calls::VoipPhoneCall impl_IVoipCallCoordinator<D>::RequestIncomingUpgradeToVideoCall(hstring_view context, hstring_view contactName, hstring_view contactNumber, const Windows::Foundation::Uri & contactImage, hstring_view serviceName, const Windows::Foundation::Uri & brandingImage, hstring_view callDetails, const Windows::Foundation::Uri & ringtone, const Windows::Foundation::TimeSpan & ringTimeout) const
{
    Windows::ApplicationModel::Calls::VoipPhoneCall call { nullptr };
    check_hresult(WINRT_SHIM(IVoipCallCoordinator)->abi_RequestIncomingUpgradeToVideoCall(get_abi(context), get_abi(contactName), get_abi(contactNumber), get_abi(contactImage), get_abi(serviceName), get_abi(brandingImage), get_abi(callDetails), get_abi(ringtone), get_abi(ringTimeout), put_abi(call)));
    return call;
}

template <typename D> void impl_IVoipCallCoordinator<D>::TerminateCellularCall(GUID callUpgradeGuid) const
{
    check_hresult(WINRT_SHIM(IVoipCallCoordinator)->abi_TerminateCellularCall(callUpgradeGuid));
}

template <typename D> void impl_IVoipCallCoordinator<D>::CancelUpgrade(GUID callUpgradeGuid) const
{
    check_hresult(WINRT_SHIM(IVoipCallCoordinator)->abi_CancelUpgrade(callUpgradeGuid));
}

template <typename D> Windows::ApplicationModel::Calls::VoipCallCoordinator impl_IVoipCallCoordinatorStatics<D>::GetDefault() const
{
    Windows::ApplicationModel::Calls::VoipCallCoordinator coordinator { nullptr };
    check_hresult(WINRT_SHIM(IVoipCallCoordinatorStatics)->abi_GetDefault(put_abi(coordinator)));
    return coordinator;
}

template <typename D> hstring impl_IPhoneCallHistoryEntry<D>::Id() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IPhoneCallHistoryEntry)->get_Id(put_abi(value)));
    return value;
}

template <typename D> Windows::ApplicationModel::Calls::PhoneCallHistoryEntryAddress impl_IPhoneCallHistoryEntry<D>::Address() const
{
    Windows::ApplicationModel::Calls::PhoneCallHistoryEntryAddress value { nullptr };
    check_hresult(WINRT_SHIM(IPhoneCallHistoryEntry)->get_Address(put_abi(value)));
    return value;
}

template <typename D> void impl_IPhoneCallHistoryEntry<D>::Address(const Windows::ApplicationModel::Calls::PhoneCallHistoryEntryAddress & value) const
{
    check_hresult(WINRT_SHIM(IPhoneCallHistoryEntry)->put_Address(get_abi(value)));
}

template <typename D> Windows::Foundation::IReference<Windows::Foundation::TimeSpan> impl_IPhoneCallHistoryEntry<D>::Duration() const
{
    Windows::Foundation::IReference<Windows::Foundation::TimeSpan> value;
    check_hresult(WINRT_SHIM(IPhoneCallHistoryEntry)->get_Duration(put_abi(value)));
    return value;
}

template <typename D> void impl_IPhoneCallHistoryEntry<D>::Duration(const optional<Windows::Foundation::TimeSpan> & value) const
{
    check_hresult(WINRT_SHIM(IPhoneCallHistoryEntry)->put_Duration(get_abi(value)));
}

template <typename D> bool impl_IPhoneCallHistoryEntry<D>::IsCallerIdBlocked() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IPhoneCallHistoryEntry)->get_IsCallerIdBlocked(&value));
    return value;
}

template <typename D> void impl_IPhoneCallHistoryEntry<D>::IsCallerIdBlocked(bool value) const
{
    check_hresult(WINRT_SHIM(IPhoneCallHistoryEntry)->put_IsCallerIdBlocked(value));
}

template <typename D> bool impl_IPhoneCallHistoryEntry<D>::IsEmergency() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IPhoneCallHistoryEntry)->get_IsEmergency(&value));
    return value;
}

template <typename D> void impl_IPhoneCallHistoryEntry<D>::IsEmergency(bool value) const
{
    check_hresult(WINRT_SHIM(IPhoneCallHistoryEntry)->put_IsEmergency(value));
}

template <typename D> bool impl_IPhoneCallHistoryEntry<D>::IsIncoming() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IPhoneCallHistoryEntry)->get_IsIncoming(&value));
    return value;
}

template <typename D> void impl_IPhoneCallHistoryEntry<D>::IsIncoming(bool value) const
{
    check_hresult(WINRT_SHIM(IPhoneCallHistoryEntry)->put_IsIncoming(value));
}

template <typename D> bool impl_IPhoneCallHistoryEntry<D>::IsMissed() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IPhoneCallHistoryEntry)->get_IsMissed(&value));
    return value;
}

template <typename D> void impl_IPhoneCallHistoryEntry<D>::IsMissed(bool value) const
{
    check_hresult(WINRT_SHIM(IPhoneCallHistoryEntry)->put_IsMissed(value));
}

template <typename D> bool impl_IPhoneCallHistoryEntry<D>::IsRinging() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IPhoneCallHistoryEntry)->get_IsRinging(&value));
    return value;
}

template <typename D> void impl_IPhoneCallHistoryEntry<D>::IsRinging(bool value) const
{
    check_hresult(WINRT_SHIM(IPhoneCallHistoryEntry)->put_IsRinging(value));
}

template <typename D> bool impl_IPhoneCallHistoryEntry<D>::IsSeen() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IPhoneCallHistoryEntry)->get_IsSeen(&value));
    return value;
}

template <typename D> void impl_IPhoneCallHistoryEntry<D>::IsSeen(bool value) const
{
    check_hresult(WINRT_SHIM(IPhoneCallHistoryEntry)->put_IsSeen(value));
}

template <typename D> bool impl_IPhoneCallHistoryEntry<D>::IsSuppressed() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IPhoneCallHistoryEntry)->get_IsSuppressed(&value));
    return value;
}

template <typename D> void impl_IPhoneCallHistoryEntry<D>::IsSuppressed(bool value) const
{
    check_hresult(WINRT_SHIM(IPhoneCallHistoryEntry)->put_IsSuppressed(value));
}

template <typename D> bool impl_IPhoneCallHistoryEntry<D>::IsVoicemail() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IPhoneCallHistoryEntry)->get_IsVoicemail(&value));
    return value;
}

template <typename D> void impl_IPhoneCallHistoryEntry<D>::IsVoicemail(bool value) const
{
    check_hresult(WINRT_SHIM(IPhoneCallHistoryEntry)->put_IsVoicemail(value));
}

template <typename D> Windows::ApplicationModel::Calls::PhoneCallHistoryEntryMedia impl_IPhoneCallHistoryEntry<D>::Media() const
{
    Windows::ApplicationModel::Calls::PhoneCallHistoryEntryMedia value {};
    check_hresult(WINRT_SHIM(IPhoneCallHistoryEntry)->get_Media(&value));
    return value;
}

template <typename D> void impl_IPhoneCallHistoryEntry<D>::Media(Windows::ApplicationModel::Calls::PhoneCallHistoryEntryMedia value) const
{
    check_hresult(WINRT_SHIM(IPhoneCallHistoryEntry)->put_Media(value));
}

template <typename D> Windows::ApplicationModel::Calls::PhoneCallHistoryEntryOtherAppReadAccess impl_IPhoneCallHistoryEntry<D>::OtherAppReadAccess() const
{
    Windows::ApplicationModel::Calls::PhoneCallHistoryEntryOtherAppReadAccess value {};
    check_hresult(WINRT_SHIM(IPhoneCallHistoryEntry)->get_OtherAppReadAccess(&value));
    return value;
}

template <typename D> void impl_IPhoneCallHistoryEntry<D>::OtherAppReadAccess(Windows::ApplicationModel::Calls::PhoneCallHistoryEntryOtherAppReadAccess value) const
{
    check_hresult(WINRT_SHIM(IPhoneCallHistoryEntry)->put_OtherAppReadAccess(value));
}

template <typename D> hstring impl_IPhoneCallHistoryEntry<D>::RemoteId() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IPhoneCallHistoryEntry)->get_RemoteId(put_abi(value)));
    return value;
}

template <typename D> void impl_IPhoneCallHistoryEntry<D>::RemoteId(hstring_view value) const
{
    check_hresult(WINRT_SHIM(IPhoneCallHistoryEntry)->put_RemoteId(get_abi(value)));
}

template <typename D> hstring impl_IPhoneCallHistoryEntry<D>::SourceDisplayName() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IPhoneCallHistoryEntry)->get_SourceDisplayName(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IPhoneCallHistoryEntry<D>::SourceId() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IPhoneCallHistoryEntry)->get_SourceId(put_abi(value)));
    return value;
}

template <typename D> void impl_IPhoneCallHistoryEntry<D>::SourceId(hstring_view value) const
{
    check_hresult(WINRT_SHIM(IPhoneCallHistoryEntry)->put_SourceId(get_abi(value)));
}

template <typename D> Windows::ApplicationModel::Calls::PhoneCallHistorySourceIdKind impl_IPhoneCallHistoryEntry<D>::SourceIdKind() const
{
    Windows::ApplicationModel::Calls::PhoneCallHistorySourceIdKind value {};
    check_hresult(WINRT_SHIM(IPhoneCallHistoryEntry)->get_SourceIdKind(&value));
    return value;
}

template <typename D> void impl_IPhoneCallHistoryEntry<D>::SourceIdKind(Windows::ApplicationModel::Calls::PhoneCallHistorySourceIdKind value) const
{
    check_hresult(WINRT_SHIM(IPhoneCallHistoryEntry)->put_SourceIdKind(value));
}

template <typename D> Windows::Foundation::DateTime impl_IPhoneCallHistoryEntry<D>::StartTime() const
{
    Windows::Foundation::DateTime value {};
    check_hresult(WINRT_SHIM(IPhoneCallHistoryEntry)->get_StartTime(put_abi(value)));
    return value;
}

template <typename D> void impl_IPhoneCallHistoryEntry<D>::StartTime(const Windows::Foundation::DateTime & value) const
{
    check_hresult(WINRT_SHIM(IPhoneCallHistoryEntry)->put_StartTime(get_abi(value)));
}

template <typename D> hstring impl_IPhoneCallHistoryEntryAddress<D>::ContactId() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IPhoneCallHistoryEntryAddress)->get_ContactId(put_abi(value)));
    return value;
}

template <typename D> void impl_IPhoneCallHistoryEntryAddress<D>::ContactId(hstring_view value) const
{
    check_hresult(WINRT_SHIM(IPhoneCallHistoryEntryAddress)->put_ContactId(get_abi(value)));
}

template <typename D> hstring impl_IPhoneCallHistoryEntryAddress<D>::DisplayName() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IPhoneCallHistoryEntryAddress)->get_DisplayName(put_abi(value)));
    return value;
}

template <typename D> void impl_IPhoneCallHistoryEntryAddress<D>::DisplayName(hstring_view value) const
{
    check_hresult(WINRT_SHIM(IPhoneCallHistoryEntryAddress)->put_DisplayName(get_abi(value)));
}

template <typename D> hstring impl_IPhoneCallHistoryEntryAddress<D>::RawAddress() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IPhoneCallHistoryEntryAddress)->get_RawAddress(put_abi(value)));
    return value;
}

template <typename D> void impl_IPhoneCallHistoryEntryAddress<D>::RawAddress(hstring_view value) const
{
    check_hresult(WINRT_SHIM(IPhoneCallHistoryEntryAddress)->put_RawAddress(get_abi(value)));
}

template <typename D> Windows::ApplicationModel::Calls::PhoneCallHistoryEntryRawAddressKind impl_IPhoneCallHistoryEntryAddress<D>::RawAddressKind() const
{
    Windows::ApplicationModel::Calls::PhoneCallHistoryEntryRawAddressKind value {};
    check_hresult(WINRT_SHIM(IPhoneCallHistoryEntryAddress)->get_RawAddressKind(&value));
    return value;
}

template <typename D> void impl_IPhoneCallHistoryEntryAddress<D>::RawAddressKind(Windows::ApplicationModel::Calls::PhoneCallHistoryEntryRawAddressKind value) const
{
    check_hresult(WINRT_SHIM(IPhoneCallHistoryEntryAddress)->put_RawAddressKind(value));
}

template <typename D> Windows::ApplicationModel::Calls::PhoneCallHistoryEntryAddress impl_IPhoneCallHistoryEntryAddressFactory<D>::Create(hstring_view rawAddress, Windows::ApplicationModel::Calls::PhoneCallHistoryEntryRawAddressKind rawAddressKind) const
{
    Windows::ApplicationModel::Calls::PhoneCallHistoryEntryAddress result { nullptr };
    check_hresult(WINRT_SHIM(IPhoneCallHistoryEntryAddressFactory)->abi_Create(get_abi(rawAddress), rawAddressKind, put_abi(result)));
    return result;
}

template <typename D> Windows::ApplicationModel::Calls::PhoneCallHistoryEntryQueryDesiredMedia impl_IPhoneCallHistoryEntryQueryOptions<D>::DesiredMedia() const
{
    Windows::ApplicationModel::Calls::PhoneCallHistoryEntryQueryDesiredMedia value {};
    check_hresult(WINRT_SHIM(IPhoneCallHistoryEntryQueryOptions)->get_DesiredMedia(&value));
    return value;
}

template <typename D> void impl_IPhoneCallHistoryEntryQueryOptions<D>::DesiredMedia(Windows::ApplicationModel::Calls::PhoneCallHistoryEntryQueryDesiredMedia value) const
{
    check_hresult(WINRT_SHIM(IPhoneCallHistoryEntryQueryOptions)->put_DesiredMedia(value));
}

template <typename D> Windows::Foundation::Collections::IVector<hstring> impl_IPhoneCallHistoryEntryQueryOptions<D>::SourceIds() const
{
    Windows::Foundation::Collections::IVector<hstring> value;
    check_hresult(WINRT_SHIM(IPhoneCallHistoryEntryQueryOptions)->get_SourceIds(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::ApplicationModel::Calls::PhoneCallHistoryEntry>> impl_IPhoneCallHistoryEntryReader<D>::ReadBatchAsync() const
{
    Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::ApplicationModel::Calls::PhoneCallHistoryEntry>> result;
    check_hresult(WINRT_SHIM(IPhoneCallHistoryEntryReader)->abi_ReadBatchAsync(put_abi(result)));
    return result;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Calls::PhoneCallHistoryEntry> impl_IPhoneCallHistoryStore<D>::GetEntryAsync(hstring_view callHistoryEntryId) const
{
    Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Calls::PhoneCallHistoryEntry> result;
    check_hresult(WINRT_SHIM(IPhoneCallHistoryStore)->abi_GetEntryAsync(get_abi(callHistoryEntryId), put_abi(result)));
    return result;
}

template <typename D> Windows::ApplicationModel::Calls::PhoneCallHistoryEntryReader impl_IPhoneCallHistoryStore<D>::GetEntryReader() const
{
    Windows::ApplicationModel::Calls::PhoneCallHistoryEntryReader result { nullptr };
    check_hresult(WINRT_SHIM(IPhoneCallHistoryStore)->abi_GetEntryReader(put_abi(result)));
    return result;
}

template <typename D> Windows::ApplicationModel::Calls::PhoneCallHistoryEntryReader impl_IPhoneCallHistoryStore<D>::GetEntryReader(const Windows::ApplicationModel::Calls::PhoneCallHistoryEntryQueryOptions & queryOptions) const
{
    Windows::ApplicationModel::Calls::PhoneCallHistoryEntryReader result { nullptr };
    check_hresult(WINRT_SHIM(IPhoneCallHistoryStore)->abi_GetEntryReaderWithOptions(get_abi(queryOptions), put_abi(result)));
    return result;
}

template <typename D> Windows::Foundation::IAsyncAction impl_IPhoneCallHistoryStore<D>::SaveEntryAsync(const Windows::ApplicationModel::Calls::PhoneCallHistoryEntry & callHistoryEntry) const
{
    Windows::Foundation::IAsyncAction result;
    check_hresult(WINRT_SHIM(IPhoneCallHistoryStore)->abi_SaveEntryAsync(get_abi(callHistoryEntry), put_abi(result)));
    return result;
}

template <typename D> Windows::Foundation::IAsyncAction impl_IPhoneCallHistoryStore<D>::DeleteEntryAsync(const Windows::ApplicationModel::Calls::PhoneCallHistoryEntry & callHistoryEntry) const
{
    Windows::Foundation::IAsyncAction result;
    check_hresult(WINRT_SHIM(IPhoneCallHistoryStore)->abi_DeleteEntryAsync(get_abi(callHistoryEntry), put_abi(result)));
    return result;
}

template <typename D> Windows::Foundation::IAsyncAction impl_IPhoneCallHistoryStore<D>::DeleteEntriesAsync(iterable<Windows::ApplicationModel::Calls::PhoneCallHistoryEntry> callHistoryEntries) const
{
    Windows::Foundation::IAsyncAction result;
    check_hresult(WINRT_SHIM(IPhoneCallHistoryStore)->abi_DeleteEntriesAsync(get_abi(callHistoryEntries), put_abi(result)));
    return result;
}

template <typename D> Windows::Foundation::IAsyncAction impl_IPhoneCallHistoryStore<D>::MarkEntryAsSeenAsync(const Windows::ApplicationModel::Calls::PhoneCallHistoryEntry & callHistoryEntry) const
{
    Windows::Foundation::IAsyncAction result;
    check_hresult(WINRT_SHIM(IPhoneCallHistoryStore)->abi_MarkEntryAsSeenAsync(get_abi(callHistoryEntry), put_abi(result)));
    return result;
}

template <typename D> Windows::Foundation::IAsyncAction impl_IPhoneCallHistoryStore<D>::MarkEntriesAsSeenAsync(iterable<Windows::ApplicationModel::Calls::PhoneCallHistoryEntry> callHistoryEntries) const
{
    Windows::Foundation::IAsyncAction result;
    check_hresult(WINRT_SHIM(IPhoneCallHistoryStore)->abi_MarkEntriesAsSeenAsync(get_abi(callHistoryEntries), put_abi(result)));
    return result;
}

template <typename D> Windows::Foundation::IAsyncOperation<uint32_t> impl_IPhoneCallHistoryStore<D>::GetUnseenCountAsync() const
{
    Windows::Foundation::IAsyncOperation<uint32_t> result;
    check_hresult(WINRT_SHIM(IPhoneCallHistoryStore)->abi_GetUnseenCountAsync(put_abi(result)));
    return result;
}

template <typename D> Windows::Foundation::IAsyncAction impl_IPhoneCallHistoryStore<D>::MarkAllAsSeenAsync() const
{
    Windows::Foundation::IAsyncAction result;
    check_hresult(WINRT_SHIM(IPhoneCallHistoryStore)->abi_MarkAllAsSeenAsync(put_abi(result)));
    return result;
}

template <typename D> Windows::Foundation::IAsyncOperation<uint32_t> impl_IPhoneCallHistoryStore<D>::GetSourcesUnseenCountAsync(iterable<hstring> sourceIds) const
{
    Windows::Foundation::IAsyncOperation<uint32_t> result;
    check_hresult(WINRT_SHIM(IPhoneCallHistoryStore)->abi_GetSourcesUnseenCountAsync(get_abi(sourceIds), put_abi(result)));
    return result;
}

template <typename D> Windows::Foundation::IAsyncAction impl_IPhoneCallHistoryStore<D>::MarkSourcesAsSeenAsync(iterable<hstring> sourceIds) const
{
    Windows::Foundation::IAsyncAction result;
    check_hresult(WINRT_SHIM(IPhoneCallHistoryStore)->abi_MarkSourcesAsSeenAsync(get_abi(sourceIds), put_abi(result)));
    return result;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Calls::PhoneCallHistoryStore> impl_IPhoneCallHistoryManagerStatics<D>::RequestStoreAsync(Windows::ApplicationModel::Calls::PhoneCallHistoryStoreAccessType accessType) const
{
    Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Calls::PhoneCallHistoryStore> result;
    check_hresult(WINRT_SHIM(IPhoneCallHistoryManagerStatics)->abi_RequestStoreAsync(accessType, put_abi(result)));
    return result;
}

template <typename D> Windows::ApplicationModel::Calls::PhoneCallHistoryManagerForUser impl_IPhoneCallHistoryManagerStatics2<D>::GetForUser(const Windows::System::User & user) const
{
    Windows::ApplicationModel::Calls::PhoneCallHistoryManagerForUser result { nullptr };
    check_hresult(WINRT_SHIM(IPhoneCallHistoryManagerStatics2)->abi_GetForUser(get_abi(user), put_abi(result)));
    return result;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Calls::PhoneCallHistoryStore> impl_IPhoneCallHistoryManagerForUser<D>::RequestStoreAsync(Windows::ApplicationModel::Calls::PhoneCallHistoryStoreAccessType accessType) const
{
    Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Calls::PhoneCallHistoryStore> result;
    check_hresult(WINRT_SHIM(IPhoneCallHistoryManagerForUser)->abi_RequestStoreAsync(accessType, put_abi(result)));
    return result;
}

template <typename D> Windows::System::User impl_IPhoneCallHistoryManagerForUser<D>::User() const
{
    Windows::System::User value { nullptr };
    check_hresult(WINRT_SHIM(IPhoneCallHistoryManagerForUser)->get_User(put_abi(value)));
    return value;
}

inline PhoneCallHistoryEntry::PhoneCallHistoryEntry() :
    PhoneCallHistoryEntry(activate_instance<PhoneCallHistoryEntry>())
{}

inline PhoneCallHistoryEntryAddress::PhoneCallHistoryEntryAddress() :
    PhoneCallHistoryEntryAddress(activate_instance<PhoneCallHistoryEntryAddress>())
{}

inline PhoneCallHistoryEntryAddress::PhoneCallHistoryEntryAddress(hstring_view rawAddress, Windows::ApplicationModel::Calls::PhoneCallHistoryEntryRawAddressKind rawAddressKind) :
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

template<>
struct std::hash<winrt::Windows::ApplicationModel::Calls::ICallAnswerEventArgs>
{
    size_t operator()(const winrt::Windows::ApplicationModel::Calls::ICallAnswerEventArgs & value) const noexcept
    {
        return winrt::impl::hash_unknown(value);
    }
};

template<>
struct std::hash<winrt::Windows::ApplicationModel::Calls::ICallRejectEventArgs>
{
    size_t operator()(const winrt::Windows::ApplicationModel::Calls::ICallRejectEventArgs & value) const noexcept
    {
        return winrt::impl::hash_unknown(value);
    }
};

template<>
struct std::hash<winrt::Windows::ApplicationModel::Calls::ICallStateChangeEventArgs>
{
    size_t operator()(const winrt::Windows::ApplicationModel::Calls::ICallStateChangeEventArgs & value) const noexcept
    {
        return winrt::impl::hash_unknown(value);
    }
};

template<>
struct std::hash<winrt::Windows::ApplicationModel::Calls::IMuteChangeEventArgs>
{
    size_t operator()(const winrt::Windows::ApplicationModel::Calls::IMuteChangeEventArgs & value) const noexcept
    {
        return winrt::impl::hash_unknown(value);
    }
};

template<>
struct std::hash<winrt::Windows::ApplicationModel::Calls::IPhoneCallHistoryEntry>
{
    size_t operator()(const winrt::Windows::ApplicationModel::Calls::IPhoneCallHistoryEntry & value) const noexcept
    {
        return winrt::impl::hash_unknown(value);
    }
};

template<>
struct std::hash<winrt::Windows::ApplicationModel::Calls::IPhoneCallHistoryEntryAddress>
{
    size_t operator()(const winrt::Windows::ApplicationModel::Calls::IPhoneCallHistoryEntryAddress & value) const noexcept
    {
        return winrt::impl::hash_unknown(value);
    }
};

template<>
struct std::hash<winrt::Windows::ApplicationModel::Calls::IPhoneCallHistoryEntryAddressFactory>
{
    size_t operator()(const winrt::Windows::ApplicationModel::Calls::IPhoneCallHistoryEntryAddressFactory & value) const noexcept
    {
        return winrt::impl::hash_unknown(value);
    }
};

template<>
struct std::hash<winrt::Windows::ApplicationModel::Calls::IPhoneCallHistoryEntryQueryOptions>
{
    size_t operator()(const winrt::Windows::ApplicationModel::Calls::IPhoneCallHistoryEntryQueryOptions & value) const noexcept
    {
        return winrt::impl::hash_unknown(value);
    }
};

template<>
struct std::hash<winrt::Windows::ApplicationModel::Calls::IPhoneCallHistoryEntryReader>
{
    size_t operator()(const winrt::Windows::ApplicationModel::Calls::IPhoneCallHistoryEntryReader & value) const noexcept
    {
        return winrt::impl::hash_unknown(value);
    }
};

template<>
struct std::hash<winrt::Windows::ApplicationModel::Calls::IPhoneCallHistoryManagerForUser>
{
    size_t operator()(const winrt::Windows::ApplicationModel::Calls::IPhoneCallHistoryManagerForUser & value) const noexcept
    {
        return winrt::impl::hash_unknown(value);
    }
};

template<>
struct std::hash<winrt::Windows::ApplicationModel::Calls::IPhoneCallHistoryManagerStatics>
{
    size_t operator()(const winrt::Windows::ApplicationModel::Calls::IPhoneCallHistoryManagerStatics & value) const noexcept
    {
        return winrt::impl::hash_unknown(value);
    }
};

template<>
struct std::hash<winrt::Windows::ApplicationModel::Calls::IPhoneCallHistoryManagerStatics2>
{
    size_t operator()(const winrt::Windows::ApplicationModel::Calls::IPhoneCallHistoryManagerStatics2 & value) const noexcept
    {
        return winrt::impl::hash_unknown(value);
    }
};

template<>
struct std::hash<winrt::Windows::ApplicationModel::Calls::IPhoneCallHistoryStore>
{
    size_t operator()(const winrt::Windows::ApplicationModel::Calls::IPhoneCallHistoryStore & value) const noexcept
    {
        return winrt::impl::hash_unknown(value);
    }
};

template<>
struct std::hash<winrt::Windows::ApplicationModel::Calls::IVoipCallCoordinator>
{
    size_t operator()(const winrt::Windows::ApplicationModel::Calls::IVoipCallCoordinator & value) const noexcept
    {
        return winrt::impl::hash_unknown(value);
    }
};

template<>
struct std::hash<winrt::Windows::ApplicationModel::Calls::IVoipCallCoordinatorStatics>
{
    size_t operator()(const winrt::Windows::ApplicationModel::Calls::IVoipCallCoordinatorStatics & value) const noexcept
    {
        return winrt::impl::hash_unknown(value);
    }
};

template<>
struct std::hash<winrt::Windows::ApplicationModel::Calls::IVoipPhoneCall>
{
    size_t operator()(const winrt::Windows::ApplicationModel::Calls::IVoipPhoneCall & value) const noexcept
    {
        return winrt::impl::hash_unknown(value);
    }
};

template<>
struct std::hash<winrt::Windows::ApplicationModel::Calls::CallAnswerEventArgs>
{
    size_t operator()(const winrt::Windows::ApplicationModel::Calls::CallAnswerEventArgs & value) const noexcept
    {
        return winrt::impl::hash_unknown(value);
    }
};

template<>
struct std::hash<winrt::Windows::ApplicationModel::Calls::CallRejectEventArgs>
{
    size_t operator()(const winrt::Windows::ApplicationModel::Calls::CallRejectEventArgs & value) const noexcept
    {
        return winrt::impl::hash_unknown(value);
    }
};

template<>
struct std::hash<winrt::Windows::ApplicationModel::Calls::CallStateChangeEventArgs>
{
    size_t operator()(const winrt::Windows::ApplicationModel::Calls::CallStateChangeEventArgs & value) const noexcept
    {
        return winrt::impl::hash_unknown(value);
    }
};

template<>
struct std::hash<winrt::Windows::ApplicationModel::Calls::MuteChangeEventArgs>
{
    size_t operator()(const winrt::Windows::ApplicationModel::Calls::MuteChangeEventArgs & value) const noexcept
    {
        return winrt::impl::hash_unknown(value);
    }
};

template<>
struct std::hash<winrt::Windows::ApplicationModel::Calls::PhoneCallHistoryEntry>
{
    size_t operator()(const winrt::Windows::ApplicationModel::Calls::PhoneCallHistoryEntry & value) const noexcept
    {
        return winrt::impl::hash_unknown(value);
    }
};

template<>
struct std::hash<winrt::Windows::ApplicationModel::Calls::PhoneCallHistoryEntryAddress>
{
    size_t operator()(const winrt::Windows::ApplicationModel::Calls::PhoneCallHistoryEntryAddress & value) const noexcept
    {
        return winrt::impl::hash_unknown(value);
    }
};

template<>
struct std::hash<winrt::Windows::ApplicationModel::Calls::PhoneCallHistoryEntryQueryOptions>
{
    size_t operator()(const winrt::Windows::ApplicationModel::Calls::PhoneCallHistoryEntryQueryOptions & value) const noexcept
    {
        return winrt::impl::hash_unknown(value);
    }
};

template<>
struct std::hash<winrt::Windows::ApplicationModel::Calls::PhoneCallHistoryEntryReader>
{
    size_t operator()(const winrt::Windows::ApplicationModel::Calls::PhoneCallHistoryEntryReader & value) const noexcept
    {
        return winrt::impl::hash_unknown(value);
    }
};

template<>
struct std::hash<winrt::Windows::ApplicationModel::Calls::PhoneCallHistoryManagerForUser>
{
    size_t operator()(const winrt::Windows::ApplicationModel::Calls::PhoneCallHistoryManagerForUser & value) const noexcept
    {
        return winrt::impl::hash_unknown(value);
    }
};

template<>
struct std::hash<winrt::Windows::ApplicationModel::Calls::PhoneCallHistoryStore>
{
    size_t operator()(const winrt::Windows::ApplicationModel::Calls::PhoneCallHistoryStore & value) const noexcept
    {
        return winrt::impl::hash_unknown(value);
    }
};

template<>
struct std::hash<winrt::Windows::ApplicationModel::Calls::VoipCallCoordinator>
{
    size_t operator()(const winrt::Windows::ApplicationModel::Calls::VoipCallCoordinator & value) const noexcept
    {
        return winrt::impl::hash_unknown(value);
    }
};

template<>
struct std::hash<winrt::Windows::ApplicationModel::Calls::VoipPhoneCall>
{
    size_t operator()(const winrt::Windows::ApplicationModel::Calls::VoipPhoneCall & value) const noexcept
    {
        return winrt::impl::hash_unknown(value);
    }
};

WINRT_WARNING_POP
