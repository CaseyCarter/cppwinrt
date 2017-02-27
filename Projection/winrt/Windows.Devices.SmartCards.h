// C++ for the Windows Runtime v1.0.private
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "base.h"
WINRT_WARNING_PUSH

#include "internal/Windows.Foundation.3.h"
#include "internal/Windows.Storage.Streams.3.h"
#include "internal/Windows.Devices.SmartCards.3.h"
#include "Windows.Devices.h"
#include "Windows.Foundation.h"

WINRT_EXPORT namespace winrt {

namespace Windows::Devices::SmartCards {

template <typename L> SmartCardPinResetHandler::SmartCardPinResetHandler(L lambda) :
    SmartCardPinResetHandler(impl::make_delegate<impl_SmartCardPinResetHandler<L>, SmartCardPinResetHandler>(std::forward<L>(lambda)))
{}

template <typename F> SmartCardPinResetHandler::SmartCardPinResetHandler(F * function) :
    SmartCardPinResetHandler([=](auto && ... args) { function(args ...); })
{}

template <typename O, typename M> SmartCardPinResetHandler::SmartCardPinResetHandler(O * object, M method) :
    SmartCardPinResetHandler([=](auto && ... args) { ((*object).*(method))(args ...); })
{}

inline void SmartCardPinResetHandler::operator()(const Windows::Devices::SmartCards::SmartCardProvisioning & sender, const Windows::Devices::SmartCards::SmartCardPinResetRequest & request) const
{
    check_hresult((*(abi<SmartCardPinResetHandler> **)this)->abi_Invoke(get_abi(sender), get_abi(request)));
}

}

namespace impl {

template <typename D>
struct produce<D, Windows::Devices::SmartCards::ICardAddedEventArgs> : produce_base<D, Windows::Devices::SmartCards::ICardAddedEventArgs>
{
    HRESULT __stdcall get_SmartCard(impl::abi_arg_out<Windows::Devices::SmartCards::ISmartCard> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().SmartCard());
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
struct produce<D, Windows::Devices::SmartCards::ICardRemovedEventArgs> : produce_base<D, Windows::Devices::SmartCards::ICardRemovedEventArgs>
{
    HRESULT __stdcall get_SmartCard(impl::abi_arg_out<Windows::Devices::SmartCards::ISmartCard> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().SmartCard());
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
struct produce<D, Windows::Devices::SmartCards::ISmartCard> : produce_base<D, Windows::Devices::SmartCards::ISmartCard>
{
    HRESULT __stdcall get_Reader(impl::abi_arg_out<Windows::Devices::SmartCards::ISmartCardReader> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Reader());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetStatusAsync(impl::abi_arg_out<Windows::Foundation::IAsyncOperation<winrt::Windows::Devices::SmartCards::SmartCardStatus>> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().GetStatusAsync());
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetAnswerToResetAsync(impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Storage::Streams::IBuffer>> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().GetAnswerToResetAsync());
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
struct produce<D, Windows::Devices::SmartCards::ISmartCardChallengeContext> : produce_base<D, Windows::Devices::SmartCards::ISmartCardChallengeContext>
{
    HRESULT __stdcall get_Challenge(impl::abi_arg_out<Windows::Storage::Streams::IBuffer> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Challenge());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_VerifyResponseAsync(impl::abi_arg_in<Windows::Storage::Streams::IBuffer> response, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<bool>> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().VerifyResponseAsync(*reinterpret_cast<const Windows::Storage::Streams::IBuffer *>(&response)));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_ProvisionAsync(impl::abi_arg_in<Windows::Storage::Streams::IBuffer> response, bool formatCard, impl::abi_arg_out<Windows::Foundation::IAsyncAction> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().ProvisionAsync(*reinterpret_cast<const Windows::Storage::Streams::IBuffer *>(&response), formatCard));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_ProvisionAsyncWithNewCardId(impl::abi_arg_in<Windows::Storage::Streams::IBuffer> response, bool formatCard, GUID newCardId, impl::abi_arg_out<Windows::Foundation::IAsyncAction> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().ProvisionAsync(*reinterpret_cast<const Windows::Storage::Streams::IBuffer *>(&response), formatCard, newCardId));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_ChangeAdministrativeKeyAsync(impl::abi_arg_in<Windows::Storage::Streams::IBuffer> response, impl::abi_arg_in<Windows::Storage::Streams::IBuffer> newAdministrativeKey, impl::abi_arg_out<Windows::Foundation::IAsyncAction> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().ChangeAdministrativeKeyAsync(*reinterpret_cast<const Windows::Storage::Streams::IBuffer *>(&response), *reinterpret_cast<const Windows::Storage::Streams::IBuffer *>(&newAdministrativeKey)));
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
struct produce<D, Windows::Devices::SmartCards::ISmartCardConnect> : produce_base<D, Windows::Devices::SmartCards::ISmartCardConnect>
{
    HRESULT __stdcall abi_ConnectAsync(impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Devices::SmartCards::SmartCardConnection>> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().ConnectAsync());
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
struct produce<D, Windows::Devices::SmartCards::ISmartCardConnection> : produce_base<D, Windows::Devices::SmartCards::ISmartCardConnection>
{
    HRESULT __stdcall abi_TransmitAsync(impl::abi_arg_in<Windows::Storage::Streams::IBuffer> command, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Storage::Streams::IBuffer>> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().TransmitAsync(*reinterpret_cast<const Windows::Storage::Streams::IBuffer *>(&command)));
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
struct produce<D, Windows::Devices::SmartCards::ISmartCardPinPolicy> : produce_base<D, Windows::Devices::SmartCards::ISmartCardPinPolicy>
{
    HRESULT __stdcall get_MinLength(uint32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().MinLength());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_MinLength(uint32_t value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().MinLength(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_MaxLength(uint32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().MaxLength());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_MaxLength(uint32_t value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().MaxLength(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_UppercaseLetters(Windows::Devices::SmartCards::SmartCardPinCharacterPolicyOption * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().UppercaseLetters());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_UppercaseLetters(Windows::Devices::SmartCards::SmartCardPinCharacterPolicyOption value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().UppercaseLetters(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_LowercaseLetters(Windows::Devices::SmartCards::SmartCardPinCharacterPolicyOption * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().LowercaseLetters());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_LowercaseLetters(Windows::Devices::SmartCards::SmartCardPinCharacterPolicyOption value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().LowercaseLetters(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Digits(Windows::Devices::SmartCards::SmartCardPinCharacterPolicyOption * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Digits());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Digits(Windows::Devices::SmartCards::SmartCardPinCharacterPolicyOption value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Digits(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_SpecialCharacters(Windows::Devices::SmartCards::SmartCardPinCharacterPolicyOption * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().SpecialCharacters());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_SpecialCharacters(Windows::Devices::SmartCards::SmartCardPinCharacterPolicyOption value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SpecialCharacters(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Devices::SmartCards::ISmartCardPinResetDeferral> : produce_base<D, Windows::Devices::SmartCards::ISmartCardPinResetDeferral>
{
    HRESULT __stdcall abi_Complete() noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Complete();
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Devices::SmartCards::ISmartCardPinResetRequest> : produce_base<D, Windows::Devices::SmartCards::ISmartCardPinResetRequest>
{
    HRESULT __stdcall get_Challenge(impl::abi_arg_out<Windows::Storage::Streams::IBuffer> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Challenge());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Deadline(impl::abi_arg_out<Windows::Foundation::DateTime> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Deadline());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetDeferral(impl::abi_arg_out<Windows::Devices::SmartCards::ISmartCardPinResetDeferral> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().GetDeferral());
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_SetResponse(impl::abi_arg_in<Windows::Storage::Streams::IBuffer> response) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SetResponse(*reinterpret_cast<const Windows::Storage::Streams::IBuffer *>(&response));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Devices::SmartCards::ISmartCardProvisioning> : produce_base<D, Windows::Devices::SmartCards::ISmartCardProvisioning>
{
    HRESULT __stdcall get_SmartCard(impl::abi_arg_out<Windows::Devices::SmartCards::ISmartCard> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().SmartCard());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetIdAsync(impl::abi_arg_out<Windows::Foundation::IAsyncOperation<GUID>> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().GetIdAsync());
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetNameAsync(impl::abi_arg_out<Windows::Foundation::IAsyncOperation<hstring>> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().GetNameAsync());
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetChallengeContextAsync(impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Devices::SmartCards::SmartCardChallengeContext>> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().GetChallengeContextAsync());
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_RequestPinChangeAsync(impl::abi_arg_out<Windows::Foundation::IAsyncOperation<bool>> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().RequestPinChangeAsync());
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_RequestPinResetAsync(impl::abi_arg_in<Windows::Devices::SmartCards::SmartCardPinResetHandler> handler, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<bool>> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().RequestPinResetAsync(*reinterpret_cast<const Windows::Devices::SmartCards::SmartCardPinResetHandler *>(&handler)));
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
struct produce<D, Windows::Devices::SmartCards::ISmartCardProvisioning2> : produce_base<D, Windows::Devices::SmartCards::ISmartCardProvisioning2>
{
    HRESULT __stdcall abi_GetAuthorityKeyContainerNameAsync(impl::abi_arg_out<Windows::Foundation::IAsyncOperation<hstring>> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().GetAuthorityKeyContainerNameAsync());
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
struct produce<D, Windows::Devices::SmartCards::ISmartCardProvisioningStatics> : produce_base<D, Windows::Devices::SmartCards::ISmartCardProvisioningStatics>
{
    HRESULT __stdcall abi_FromSmartCardAsync(impl::abi_arg_in<Windows::Devices::SmartCards::ISmartCard> card, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Devices::SmartCards::SmartCardProvisioning>> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().FromSmartCardAsync(*reinterpret_cast<const Windows::Devices::SmartCards::SmartCard *>(&card)));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_RequestVirtualSmartCardCreationAsync(impl::abi_arg_in<hstring> friendlyName, impl::abi_arg_in<Windows::Storage::Streams::IBuffer> administrativeKey, impl::abi_arg_in<Windows::Devices::SmartCards::ISmartCardPinPolicy> pinPolicy, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Devices::SmartCards::SmartCardProvisioning>> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().RequestVirtualSmartCardCreationAsync(*reinterpret_cast<const hstring *>(&friendlyName), *reinterpret_cast<const Windows::Storage::Streams::IBuffer *>(&administrativeKey), *reinterpret_cast<const Windows::Devices::SmartCards::SmartCardPinPolicy *>(&pinPolicy)));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_RequestVirtualSmartCardCreationAsyncWithCardId(impl::abi_arg_in<hstring> friendlyName, impl::abi_arg_in<Windows::Storage::Streams::IBuffer> administrativeKey, impl::abi_arg_in<Windows::Devices::SmartCards::ISmartCardPinPolicy> pinPolicy, GUID cardId, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Devices::SmartCards::SmartCardProvisioning>> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().RequestVirtualSmartCardCreationAsync(*reinterpret_cast<const hstring *>(&friendlyName), *reinterpret_cast<const Windows::Storage::Streams::IBuffer *>(&administrativeKey), *reinterpret_cast<const Windows::Devices::SmartCards::SmartCardPinPolicy *>(&pinPolicy), cardId));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_RequestVirtualSmartCardDeletionAsync(impl::abi_arg_in<Windows::Devices::SmartCards::ISmartCard> card, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<bool>> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().RequestVirtualSmartCardDeletionAsync(*reinterpret_cast<const Windows::Devices::SmartCards::SmartCard *>(&card)));
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
struct produce<D, Windows::Devices::SmartCards::ISmartCardProvisioningStatics2> : produce_base<D, Windows::Devices::SmartCards::ISmartCardProvisioningStatics2>
{
    HRESULT __stdcall abi_RequestAttestedVirtualSmartCardCreationAsync(impl::abi_arg_in<hstring> friendlyName, impl::abi_arg_in<Windows::Storage::Streams::IBuffer> administrativeKey, impl::abi_arg_in<Windows::Devices::SmartCards::ISmartCardPinPolicy> pinPolicy, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Devices::SmartCards::SmartCardProvisioning>> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().RequestAttestedVirtualSmartCardCreationAsync(*reinterpret_cast<const hstring *>(&friendlyName), *reinterpret_cast<const Windows::Storage::Streams::IBuffer *>(&administrativeKey), *reinterpret_cast<const Windows::Devices::SmartCards::SmartCardPinPolicy *>(&pinPolicy)));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_RequestAttestedVirtualSmartCardCreationAsyncWithCardId(impl::abi_arg_in<hstring> friendlyName, impl::abi_arg_in<Windows::Storage::Streams::IBuffer> administrativeKey, impl::abi_arg_in<Windows::Devices::SmartCards::ISmartCardPinPolicy> pinPolicy, GUID cardId, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Devices::SmartCards::SmartCardProvisioning>> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().RequestAttestedVirtualSmartCardCreationAsync(*reinterpret_cast<const hstring *>(&friendlyName), *reinterpret_cast<const Windows::Storage::Streams::IBuffer *>(&administrativeKey), *reinterpret_cast<const Windows::Devices::SmartCards::SmartCardPinPolicy *>(&pinPolicy), cardId));
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
struct produce<D, Windows::Devices::SmartCards::ISmartCardReader> : produce_base<D, Windows::Devices::SmartCards::ISmartCardReader>
{
    HRESULT __stdcall get_DeviceId(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().DeviceId());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Name(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Name());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Kind(Windows::Devices::SmartCards::SmartCardReaderKind * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Kind());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetStatusAsync(impl::abi_arg_out<Windows::Foundation::IAsyncOperation<winrt::Windows::Devices::SmartCards::SmartCardReaderStatus>> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().GetStatusAsync());
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_FindAllCardsAsync(impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::Devices::SmartCards::SmartCard>>> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().FindAllCardsAsync());
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_CardAdded(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::Devices::SmartCards::SmartCardReader, Windows::Devices::SmartCards::CardAddedEventArgs>> handler, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().CardAdded(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::Devices::SmartCards::SmartCardReader, Windows::Devices::SmartCards::CardAddedEventArgs> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_CardAdded(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().CardAdded(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_CardRemoved(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::Devices::SmartCards::SmartCardReader, Windows::Devices::SmartCards::CardRemovedEventArgs>> handler, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().CardRemoved(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::Devices::SmartCards::SmartCardReader, Windows::Devices::SmartCards::CardRemovedEventArgs> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_CardRemoved(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().CardRemoved(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Devices::SmartCards::ISmartCardReaderStatics> : produce_base<D, Windows::Devices::SmartCards::ISmartCardReaderStatics>
{
    HRESULT __stdcall abi_GetDeviceSelector(impl::abi_arg_out<hstring> selector) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *selector = detach_abi(this->shim().GetDeviceSelector());
            return S_OK;
        }
        catch (...)
        {
            *selector = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetDeviceSelectorWithKind(Windows::Devices::SmartCards::SmartCardReaderKind kind, impl::abi_arg_out<hstring> selector) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *selector = detach_abi(this->shim().GetDeviceSelector(kind));
            return S_OK;
        }
        catch (...)
        {
            *selector = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_FromIdAsync(impl::abi_arg_in<hstring> deviceId, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Devices::SmartCards::SmartCardReader>> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().FromIdAsync(*reinterpret_cast<const hstring *>(&deviceId)));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }
};

}

namespace Windows::Devices::SmartCards {

template <typename D> hstring impl_ISmartCardReaderStatics<D>::GetDeviceSelector() const
{
    hstring selector;
    check_hresult(WINRT_SHIM(ISmartCardReaderStatics)->abi_GetDeviceSelector(put_abi(selector)));
    return selector;
}

template <typename D> hstring impl_ISmartCardReaderStatics<D>::GetDeviceSelector(Windows::Devices::SmartCards::SmartCardReaderKind kind) const
{
    hstring selector;
    check_hresult(WINRT_SHIM(ISmartCardReaderStatics)->abi_GetDeviceSelectorWithKind(kind, put_abi(selector)));
    return selector;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Devices::SmartCards::SmartCardReader> impl_ISmartCardReaderStatics<D>::FromIdAsync(hstring_view deviceId) const
{
    Windows::Foundation::IAsyncOperation<Windows::Devices::SmartCards::SmartCardReader> result;
    check_hresult(WINRT_SHIM(ISmartCardReaderStatics)->abi_FromIdAsync(get_abi(deviceId), put_abi(result)));
    return result;
}

template <typename D> hstring impl_ISmartCardReader<D>::DeviceId() const
{
    hstring value;
    check_hresult(WINRT_SHIM(ISmartCardReader)->get_DeviceId(put_abi(value)));
    return value;
}

template <typename D> hstring impl_ISmartCardReader<D>::Name() const
{
    hstring value;
    check_hresult(WINRT_SHIM(ISmartCardReader)->get_Name(put_abi(value)));
    return value;
}

template <typename D> Windows::Devices::SmartCards::SmartCardReaderKind impl_ISmartCardReader<D>::Kind() const
{
    Windows::Devices::SmartCards::SmartCardReaderKind value {};
    check_hresult(WINRT_SHIM(ISmartCardReader)->get_Kind(&value));
    return value;
}

template <typename D> Windows::Foundation::IAsyncOperation<winrt::Windows::Devices::SmartCards::SmartCardReaderStatus> impl_ISmartCardReader<D>::GetStatusAsync() const
{
    Windows::Foundation::IAsyncOperation<winrt::Windows::Devices::SmartCards::SmartCardReaderStatus> result;
    check_hresult(WINRT_SHIM(ISmartCardReader)->abi_GetStatusAsync(put_abi(result)));
    return result;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::Devices::SmartCards::SmartCard>> impl_ISmartCardReader<D>::FindAllCardsAsync() const
{
    Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::Devices::SmartCards::SmartCard>> result;
    check_hresult(WINRT_SHIM(ISmartCardReader)->abi_FindAllCardsAsync(put_abi(result)));
    return result;
}

template <typename D> event_token impl_ISmartCardReader<D>::CardAdded(const Windows::Foundation::TypedEventHandler<Windows::Devices::SmartCards::SmartCardReader, Windows::Devices::SmartCards::CardAddedEventArgs> & handler) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(ISmartCardReader)->add_CardAdded(get_abi(handler), &token));
    return token;
}

template <typename D> event_revoker<ISmartCardReader> impl_ISmartCardReader<D>::CardAdded(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Devices::SmartCards::SmartCardReader, Windows::Devices::SmartCards::CardAddedEventArgs> & handler) const
{
    return impl::make_event_revoker<D, ISmartCardReader>(this, &ABI::Windows::Devices::SmartCards::ISmartCardReader::remove_CardAdded, CardAdded(handler));
}

template <typename D> void impl_ISmartCardReader<D>::CardAdded(event_token token) const
{
    check_hresult(WINRT_SHIM(ISmartCardReader)->remove_CardAdded(token));
}

template <typename D> event_token impl_ISmartCardReader<D>::CardRemoved(const Windows::Foundation::TypedEventHandler<Windows::Devices::SmartCards::SmartCardReader, Windows::Devices::SmartCards::CardRemovedEventArgs> & handler) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(ISmartCardReader)->add_CardRemoved(get_abi(handler), &token));
    return token;
}

template <typename D> event_revoker<ISmartCardReader> impl_ISmartCardReader<D>::CardRemoved(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Devices::SmartCards::SmartCardReader, Windows::Devices::SmartCards::CardRemovedEventArgs> & handler) const
{
    return impl::make_event_revoker<D, ISmartCardReader>(this, &ABI::Windows::Devices::SmartCards::ISmartCardReader::remove_CardRemoved, CardRemoved(handler));
}

template <typename D> void impl_ISmartCardReader<D>::CardRemoved(event_token token) const
{
    check_hresult(WINRT_SHIM(ISmartCardReader)->remove_CardRemoved(token));
}

template <typename D> Windows::Devices::SmartCards::SmartCard impl_ICardAddedEventArgs<D>::SmartCard() const
{
    Windows::Devices::SmartCards::SmartCard value { nullptr };
    check_hresult(WINRT_SHIM(ICardAddedEventArgs)->get_SmartCard(put_abi(value)));
    return value;
}

template <typename D> Windows::Devices::SmartCards::SmartCard impl_ICardRemovedEventArgs<D>::SmartCard() const
{
    Windows::Devices::SmartCards::SmartCard value { nullptr };
    check_hresult(WINRT_SHIM(ICardRemovedEventArgs)->get_SmartCard(put_abi(value)));
    return value;
}

template <typename D> Windows::Devices::SmartCards::SmartCardReader impl_ISmartCard<D>::Reader() const
{
    Windows::Devices::SmartCards::SmartCardReader value { nullptr };
    check_hresult(WINRT_SHIM(ISmartCard)->get_Reader(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::IAsyncOperation<winrt::Windows::Devices::SmartCards::SmartCardStatus> impl_ISmartCard<D>::GetStatusAsync() const
{
    Windows::Foundation::IAsyncOperation<winrt::Windows::Devices::SmartCards::SmartCardStatus> result;
    check_hresult(WINRT_SHIM(ISmartCard)->abi_GetStatusAsync(put_abi(result)));
    return result;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Storage::Streams::IBuffer> impl_ISmartCard<D>::GetAnswerToResetAsync() const
{
    Windows::Foundation::IAsyncOperation<Windows::Storage::Streams::IBuffer> result;
    check_hresult(WINRT_SHIM(ISmartCard)->abi_GetAnswerToResetAsync(put_abi(result)));
    return result;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Devices::SmartCards::SmartCardProvisioning> impl_ISmartCardProvisioningStatics<D>::FromSmartCardAsync(const Windows::Devices::SmartCards::SmartCard & card) const
{
    Windows::Foundation::IAsyncOperation<Windows::Devices::SmartCards::SmartCardProvisioning> result;
    check_hresult(WINRT_SHIM(ISmartCardProvisioningStatics)->abi_FromSmartCardAsync(get_abi(card), put_abi(result)));
    return result;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Devices::SmartCards::SmartCardProvisioning> impl_ISmartCardProvisioningStatics<D>::RequestVirtualSmartCardCreationAsync(hstring_view friendlyName, const Windows::Storage::Streams::IBuffer & administrativeKey, const Windows::Devices::SmartCards::SmartCardPinPolicy & pinPolicy) const
{
    Windows::Foundation::IAsyncOperation<Windows::Devices::SmartCards::SmartCardProvisioning> result;
    check_hresult(WINRT_SHIM(ISmartCardProvisioningStatics)->abi_RequestVirtualSmartCardCreationAsync(get_abi(friendlyName), get_abi(administrativeKey), get_abi(pinPolicy), put_abi(result)));
    return result;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Devices::SmartCards::SmartCardProvisioning> impl_ISmartCardProvisioningStatics<D>::RequestVirtualSmartCardCreationAsync(hstring_view friendlyName, const Windows::Storage::Streams::IBuffer & administrativeKey, const Windows::Devices::SmartCards::SmartCardPinPolicy & pinPolicy, GUID cardId) const
{
    Windows::Foundation::IAsyncOperation<Windows::Devices::SmartCards::SmartCardProvisioning> result;
    check_hresult(WINRT_SHIM(ISmartCardProvisioningStatics)->abi_RequestVirtualSmartCardCreationAsyncWithCardId(get_abi(friendlyName), get_abi(administrativeKey), get_abi(pinPolicy), cardId, put_abi(result)));
    return result;
}

template <typename D> Windows::Foundation::IAsyncOperation<bool> impl_ISmartCardProvisioningStatics<D>::RequestVirtualSmartCardDeletionAsync(const Windows::Devices::SmartCards::SmartCard & card) const
{
    Windows::Foundation::IAsyncOperation<bool> result;
    check_hresult(WINRT_SHIM(ISmartCardProvisioningStatics)->abi_RequestVirtualSmartCardDeletionAsync(get_abi(card), put_abi(result)));
    return result;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Devices::SmartCards::SmartCardProvisioning> impl_ISmartCardProvisioningStatics2<D>::RequestAttestedVirtualSmartCardCreationAsync(hstring_view friendlyName, const Windows::Storage::Streams::IBuffer & administrativeKey, const Windows::Devices::SmartCards::SmartCardPinPolicy & pinPolicy) const
{
    Windows::Foundation::IAsyncOperation<Windows::Devices::SmartCards::SmartCardProvisioning> result;
    check_hresult(WINRT_SHIM(ISmartCardProvisioningStatics2)->abi_RequestAttestedVirtualSmartCardCreationAsync(get_abi(friendlyName), get_abi(administrativeKey), get_abi(pinPolicy), put_abi(result)));
    return result;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Devices::SmartCards::SmartCardProvisioning> impl_ISmartCardProvisioningStatics2<D>::RequestAttestedVirtualSmartCardCreationAsync(hstring_view friendlyName, const Windows::Storage::Streams::IBuffer & administrativeKey, const Windows::Devices::SmartCards::SmartCardPinPolicy & pinPolicy, GUID cardId) const
{
    Windows::Foundation::IAsyncOperation<Windows::Devices::SmartCards::SmartCardProvisioning> result;
    check_hresult(WINRT_SHIM(ISmartCardProvisioningStatics2)->abi_RequestAttestedVirtualSmartCardCreationAsyncWithCardId(get_abi(friendlyName), get_abi(administrativeKey), get_abi(pinPolicy), cardId, put_abi(result)));
    return result;
}

template <typename D> Windows::Devices::SmartCards::SmartCard impl_ISmartCardProvisioning<D>::SmartCard() const
{
    Windows::Devices::SmartCards::SmartCard value { nullptr };
    check_hresult(WINRT_SHIM(ISmartCardProvisioning)->get_SmartCard(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::IAsyncOperation<GUID> impl_ISmartCardProvisioning<D>::GetIdAsync() const
{
    Windows::Foundation::IAsyncOperation<GUID> result;
    check_hresult(WINRT_SHIM(ISmartCardProvisioning)->abi_GetIdAsync(put_abi(result)));
    return result;
}

template <typename D> Windows::Foundation::IAsyncOperation<hstring> impl_ISmartCardProvisioning<D>::GetNameAsync() const
{
    Windows::Foundation::IAsyncOperation<hstring> result;
    check_hresult(WINRT_SHIM(ISmartCardProvisioning)->abi_GetNameAsync(put_abi(result)));
    return result;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Devices::SmartCards::SmartCardChallengeContext> impl_ISmartCardProvisioning<D>::GetChallengeContextAsync() const
{
    Windows::Foundation::IAsyncOperation<Windows::Devices::SmartCards::SmartCardChallengeContext> result;
    check_hresult(WINRT_SHIM(ISmartCardProvisioning)->abi_GetChallengeContextAsync(put_abi(result)));
    return result;
}

template <typename D> Windows::Foundation::IAsyncOperation<bool> impl_ISmartCardProvisioning<D>::RequestPinChangeAsync() const
{
    Windows::Foundation::IAsyncOperation<bool> result;
    check_hresult(WINRT_SHIM(ISmartCardProvisioning)->abi_RequestPinChangeAsync(put_abi(result)));
    return result;
}

template <typename D> Windows::Foundation::IAsyncOperation<bool> impl_ISmartCardProvisioning<D>::RequestPinResetAsync(const Windows::Devices::SmartCards::SmartCardPinResetHandler & handler) const
{
    Windows::Foundation::IAsyncOperation<bool> result;
    check_hresult(WINRT_SHIM(ISmartCardProvisioning)->abi_RequestPinResetAsync(get_abi(handler), put_abi(result)));
    return result;
}

template <typename D> Windows::Foundation::IAsyncOperation<hstring> impl_ISmartCardProvisioning2<D>::GetAuthorityKeyContainerNameAsync() const
{
    Windows::Foundation::IAsyncOperation<hstring> result;
    check_hresult(WINRT_SHIM(ISmartCardProvisioning2)->abi_GetAuthorityKeyContainerNameAsync(put_abi(result)));
    return result;
}

template <typename D> Windows::Storage::Streams::IBuffer impl_ISmartCardPinResetRequest<D>::Challenge() const
{
    Windows::Storage::Streams::IBuffer value;
    check_hresult(WINRT_SHIM(ISmartCardPinResetRequest)->get_Challenge(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::DateTime impl_ISmartCardPinResetRequest<D>::Deadline() const
{
    Windows::Foundation::DateTime value {};
    check_hresult(WINRT_SHIM(ISmartCardPinResetRequest)->get_Deadline(put_abi(value)));
    return value;
}

template <typename D> Windows::Devices::SmartCards::SmartCardPinResetDeferral impl_ISmartCardPinResetRequest<D>::GetDeferral() const
{
    Windows::Devices::SmartCards::SmartCardPinResetDeferral result { nullptr };
    check_hresult(WINRT_SHIM(ISmartCardPinResetRequest)->abi_GetDeferral(put_abi(result)));
    return result;
}

template <typename D> void impl_ISmartCardPinResetRequest<D>::SetResponse(const Windows::Storage::Streams::IBuffer & response) const
{
    check_hresult(WINRT_SHIM(ISmartCardPinResetRequest)->abi_SetResponse(get_abi(response)));
}

template <typename D> void impl_ISmartCardPinResetDeferral<D>::Complete() const
{
    check_hresult(WINRT_SHIM(ISmartCardPinResetDeferral)->abi_Complete());
}

template <typename D> uint32_t impl_ISmartCardPinPolicy<D>::MinLength() const
{
    uint32_t value {};
    check_hresult(WINRT_SHIM(ISmartCardPinPolicy)->get_MinLength(&value));
    return value;
}

template <typename D> void impl_ISmartCardPinPolicy<D>::MinLength(uint32_t value) const
{
    check_hresult(WINRT_SHIM(ISmartCardPinPolicy)->put_MinLength(value));
}

template <typename D> uint32_t impl_ISmartCardPinPolicy<D>::MaxLength() const
{
    uint32_t value {};
    check_hresult(WINRT_SHIM(ISmartCardPinPolicy)->get_MaxLength(&value));
    return value;
}

template <typename D> void impl_ISmartCardPinPolicy<D>::MaxLength(uint32_t value) const
{
    check_hresult(WINRT_SHIM(ISmartCardPinPolicy)->put_MaxLength(value));
}

template <typename D> Windows::Devices::SmartCards::SmartCardPinCharacterPolicyOption impl_ISmartCardPinPolicy<D>::UppercaseLetters() const
{
    Windows::Devices::SmartCards::SmartCardPinCharacterPolicyOption value {};
    check_hresult(WINRT_SHIM(ISmartCardPinPolicy)->get_UppercaseLetters(&value));
    return value;
}

template <typename D> void impl_ISmartCardPinPolicy<D>::UppercaseLetters(Windows::Devices::SmartCards::SmartCardPinCharacterPolicyOption value) const
{
    check_hresult(WINRT_SHIM(ISmartCardPinPolicy)->put_UppercaseLetters(value));
}

template <typename D> Windows::Devices::SmartCards::SmartCardPinCharacterPolicyOption impl_ISmartCardPinPolicy<D>::LowercaseLetters() const
{
    Windows::Devices::SmartCards::SmartCardPinCharacterPolicyOption value {};
    check_hresult(WINRT_SHIM(ISmartCardPinPolicy)->get_LowercaseLetters(&value));
    return value;
}

template <typename D> void impl_ISmartCardPinPolicy<D>::LowercaseLetters(Windows::Devices::SmartCards::SmartCardPinCharacterPolicyOption value) const
{
    check_hresult(WINRT_SHIM(ISmartCardPinPolicy)->put_LowercaseLetters(value));
}

template <typename D> Windows::Devices::SmartCards::SmartCardPinCharacterPolicyOption impl_ISmartCardPinPolicy<D>::Digits() const
{
    Windows::Devices::SmartCards::SmartCardPinCharacterPolicyOption value {};
    check_hresult(WINRT_SHIM(ISmartCardPinPolicy)->get_Digits(&value));
    return value;
}

template <typename D> void impl_ISmartCardPinPolicy<D>::Digits(Windows::Devices::SmartCards::SmartCardPinCharacterPolicyOption value) const
{
    check_hresult(WINRT_SHIM(ISmartCardPinPolicy)->put_Digits(value));
}

template <typename D> Windows::Devices::SmartCards::SmartCardPinCharacterPolicyOption impl_ISmartCardPinPolicy<D>::SpecialCharacters() const
{
    Windows::Devices::SmartCards::SmartCardPinCharacterPolicyOption value {};
    check_hresult(WINRT_SHIM(ISmartCardPinPolicy)->get_SpecialCharacters(&value));
    return value;
}

template <typename D> void impl_ISmartCardPinPolicy<D>::SpecialCharacters(Windows::Devices::SmartCards::SmartCardPinCharacterPolicyOption value) const
{
    check_hresult(WINRT_SHIM(ISmartCardPinPolicy)->put_SpecialCharacters(value));
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Devices::SmartCards::SmartCardConnection> impl_ISmartCardConnect<D>::ConnectAsync() const
{
    Windows::Foundation::IAsyncOperation<Windows::Devices::SmartCards::SmartCardConnection> result;
    check_hresult(WINRT_SHIM(ISmartCardConnect)->abi_ConnectAsync(put_abi(result)));
    return result;
}

template <typename D> Windows::Storage::Streams::IBuffer impl_ISmartCardChallengeContext<D>::Challenge() const
{
    Windows::Storage::Streams::IBuffer value;
    check_hresult(WINRT_SHIM(ISmartCardChallengeContext)->get_Challenge(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::IAsyncOperation<bool> impl_ISmartCardChallengeContext<D>::VerifyResponseAsync(const Windows::Storage::Streams::IBuffer & response) const
{
    Windows::Foundation::IAsyncOperation<bool> result;
    check_hresult(WINRT_SHIM(ISmartCardChallengeContext)->abi_VerifyResponseAsync(get_abi(response), put_abi(result)));
    return result;
}

template <typename D> Windows::Foundation::IAsyncAction impl_ISmartCardChallengeContext<D>::ProvisionAsync(const Windows::Storage::Streams::IBuffer & response, bool formatCard) const
{
    Windows::Foundation::IAsyncAction result;
    check_hresult(WINRT_SHIM(ISmartCardChallengeContext)->abi_ProvisionAsync(get_abi(response), formatCard, put_abi(result)));
    return result;
}

template <typename D> Windows::Foundation::IAsyncAction impl_ISmartCardChallengeContext<D>::ProvisionAsync(const Windows::Storage::Streams::IBuffer & response, bool formatCard, GUID newCardId) const
{
    Windows::Foundation::IAsyncAction result;
    check_hresult(WINRT_SHIM(ISmartCardChallengeContext)->abi_ProvisionAsyncWithNewCardId(get_abi(response), formatCard, newCardId, put_abi(result)));
    return result;
}

template <typename D> Windows::Foundation::IAsyncAction impl_ISmartCardChallengeContext<D>::ChangeAdministrativeKeyAsync(const Windows::Storage::Streams::IBuffer & response, const Windows::Storage::Streams::IBuffer & newAdministrativeKey) const
{
    Windows::Foundation::IAsyncAction result;
    check_hresult(WINRT_SHIM(ISmartCardChallengeContext)->abi_ChangeAdministrativeKeyAsync(get_abi(response), get_abi(newAdministrativeKey), put_abi(result)));
    return result;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Storage::Streams::IBuffer> impl_ISmartCardConnection<D>::TransmitAsync(const Windows::Storage::Streams::IBuffer & command) const
{
    Windows::Foundation::IAsyncOperation<Windows::Storage::Streams::IBuffer> result;
    check_hresult(WINRT_SHIM(ISmartCardConnection)->abi_TransmitAsync(get_abi(command), put_abi(result)));
    return result;
}

inline SmartCardPinPolicy::SmartCardPinPolicy() :
    SmartCardPinPolicy(activate_instance<SmartCardPinPolicy>())
{}

inline Windows::Foundation::IAsyncOperation<Windows::Devices::SmartCards::SmartCardProvisioning> SmartCardProvisioning::FromSmartCardAsync(const Windows::Devices::SmartCards::SmartCard & card)
{
    return get_activation_factory<SmartCardProvisioning, ISmartCardProvisioningStatics>().FromSmartCardAsync(card);
}

inline Windows::Foundation::IAsyncOperation<Windows::Devices::SmartCards::SmartCardProvisioning> SmartCardProvisioning::RequestVirtualSmartCardCreationAsync(hstring_view friendlyName, const Windows::Storage::Streams::IBuffer & administrativeKey, const Windows::Devices::SmartCards::SmartCardPinPolicy & pinPolicy)
{
    return get_activation_factory<SmartCardProvisioning, ISmartCardProvisioningStatics>().RequestVirtualSmartCardCreationAsync(friendlyName, administrativeKey, pinPolicy);
}

inline Windows::Foundation::IAsyncOperation<Windows::Devices::SmartCards::SmartCardProvisioning> SmartCardProvisioning::RequestVirtualSmartCardCreationAsync(hstring_view friendlyName, const Windows::Storage::Streams::IBuffer & administrativeKey, const Windows::Devices::SmartCards::SmartCardPinPolicy & pinPolicy, GUID cardId)
{
    return get_activation_factory<SmartCardProvisioning, ISmartCardProvisioningStatics>().RequestVirtualSmartCardCreationAsync(friendlyName, administrativeKey, pinPolicy, cardId);
}

inline Windows::Foundation::IAsyncOperation<bool> SmartCardProvisioning::RequestVirtualSmartCardDeletionAsync(const Windows::Devices::SmartCards::SmartCard & card)
{
    return get_activation_factory<SmartCardProvisioning, ISmartCardProvisioningStatics>().RequestVirtualSmartCardDeletionAsync(card);
}

inline Windows::Foundation::IAsyncOperation<Windows::Devices::SmartCards::SmartCardProvisioning> SmartCardProvisioning::RequestAttestedVirtualSmartCardCreationAsync(hstring_view friendlyName, const Windows::Storage::Streams::IBuffer & administrativeKey, const Windows::Devices::SmartCards::SmartCardPinPolicy & pinPolicy)
{
    return get_activation_factory<SmartCardProvisioning, ISmartCardProvisioningStatics2>().RequestAttestedVirtualSmartCardCreationAsync(friendlyName, administrativeKey, pinPolicy);
}

inline Windows::Foundation::IAsyncOperation<Windows::Devices::SmartCards::SmartCardProvisioning> SmartCardProvisioning::RequestAttestedVirtualSmartCardCreationAsync(hstring_view friendlyName, const Windows::Storage::Streams::IBuffer & administrativeKey, const Windows::Devices::SmartCards::SmartCardPinPolicy & pinPolicy, GUID cardId)
{
    return get_activation_factory<SmartCardProvisioning, ISmartCardProvisioningStatics2>().RequestAttestedVirtualSmartCardCreationAsync(friendlyName, administrativeKey, pinPolicy, cardId);
}

inline hstring SmartCardReader::GetDeviceSelector()
{
    return get_activation_factory<SmartCardReader, ISmartCardReaderStatics>().GetDeviceSelector();
}

inline hstring SmartCardReader::GetDeviceSelector(Windows::Devices::SmartCards::SmartCardReaderKind kind)
{
    return get_activation_factory<SmartCardReader, ISmartCardReaderStatics>().GetDeviceSelector(kind);
}

inline Windows::Foundation::IAsyncOperation<Windows::Devices::SmartCards::SmartCardReader> SmartCardReader::FromIdAsync(hstring_view deviceId)
{
    return get_activation_factory<SmartCardReader, ISmartCardReaderStatics>().FromIdAsync(deviceId);
}

}

}

template<>
struct std::hash<winrt::Windows::Devices::SmartCards::ICardAddedEventArgs>
{
    size_t operator()(const winrt::Windows::Devices::SmartCards::ICardAddedEventArgs & value) const noexcept
    {
        return winrt::impl::hash_unknown(value);
    }
};

template<>
struct std::hash<winrt::Windows::Devices::SmartCards::ICardRemovedEventArgs>
{
    size_t operator()(const winrt::Windows::Devices::SmartCards::ICardRemovedEventArgs & value) const noexcept
    {
        return winrt::impl::hash_unknown(value);
    }
};

template<>
struct std::hash<winrt::Windows::Devices::SmartCards::ISmartCard>
{
    size_t operator()(const winrt::Windows::Devices::SmartCards::ISmartCard & value) const noexcept
    {
        return winrt::impl::hash_unknown(value);
    }
};

template<>
struct std::hash<winrt::Windows::Devices::SmartCards::ISmartCardChallengeContext>
{
    size_t operator()(const winrt::Windows::Devices::SmartCards::ISmartCardChallengeContext & value) const noexcept
    {
        return winrt::impl::hash_unknown(value);
    }
};

template<>
struct std::hash<winrt::Windows::Devices::SmartCards::ISmartCardConnect>
{
    size_t operator()(const winrt::Windows::Devices::SmartCards::ISmartCardConnect & value) const noexcept
    {
        return winrt::impl::hash_unknown(value);
    }
};

template<>
struct std::hash<winrt::Windows::Devices::SmartCards::ISmartCardConnection>
{
    size_t operator()(const winrt::Windows::Devices::SmartCards::ISmartCardConnection & value) const noexcept
    {
        return winrt::impl::hash_unknown(value);
    }
};

template<>
struct std::hash<winrt::Windows::Devices::SmartCards::ISmartCardPinPolicy>
{
    size_t operator()(const winrt::Windows::Devices::SmartCards::ISmartCardPinPolicy & value) const noexcept
    {
        return winrt::impl::hash_unknown(value);
    }
};

template<>
struct std::hash<winrt::Windows::Devices::SmartCards::ISmartCardPinResetDeferral>
{
    size_t operator()(const winrt::Windows::Devices::SmartCards::ISmartCardPinResetDeferral & value) const noexcept
    {
        return winrt::impl::hash_unknown(value);
    }
};

template<>
struct std::hash<winrt::Windows::Devices::SmartCards::ISmartCardPinResetRequest>
{
    size_t operator()(const winrt::Windows::Devices::SmartCards::ISmartCardPinResetRequest & value) const noexcept
    {
        return winrt::impl::hash_unknown(value);
    }
};

template<>
struct std::hash<winrt::Windows::Devices::SmartCards::ISmartCardProvisioning>
{
    size_t operator()(const winrt::Windows::Devices::SmartCards::ISmartCardProvisioning & value) const noexcept
    {
        return winrt::impl::hash_unknown(value);
    }
};

template<>
struct std::hash<winrt::Windows::Devices::SmartCards::ISmartCardProvisioning2>
{
    size_t operator()(const winrt::Windows::Devices::SmartCards::ISmartCardProvisioning2 & value) const noexcept
    {
        return winrt::impl::hash_unknown(value);
    }
};

template<>
struct std::hash<winrt::Windows::Devices::SmartCards::ISmartCardProvisioningStatics>
{
    size_t operator()(const winrt::Windows::Devices::SmartCards::ISmartCardProvisioningStatics & value) const noexcept
    {
        return winrt::impl::hash_unknown(value);
    }
};

template<>
struct std::hash<winrt::Windows::Devices::SmartCards::ISmartCardProvisioningStatics2>
{
    size_t operator()(const winrt::Windows::Devices::SmartCards::ISmartCardProvisioningStatics2 & value) const noexcept
    {
        return winrt::impl::hash_unknown(value);
    }
};

template<>
struct std::hash<winrt::Windows::Devices::SmartCards::ISmartCardReader>
{
    size_t operator()(const winrt::Windows::Devices::SmartCards::ISmartCardReader & value) const noexcept
    {
        return winrt::impl::hash_unknown(value);
    }
};

template<>
struct std::hash<winrt::Windows::Devices::SmartCards::ISmartCardReaderStatics>
{
    size_t operator()(const winrt::Windows::Devices::SmartCards::ISmartCardReaderStatics & value) const noexcept
    {
        return winrt::impl::hash_unknown(value);
    }
};

template<>
struct std::hash<winrt::Windows::Devices::SmartCards::CardAddedEventArgs>
{
    size_t operator()(const winrt::Windows::Devices::SmartCards::CardAddedEventArgs & value) const noexcept
    {
        return winrt::impl::hash_unknown(value);
    }
};

template<>
struct std::hash<winrt::Windows::Devices::SmartCards::CardRemovedEventArgs>
{
    size_t operator()(const winrt::Windows::Devices::SmartCards::CardRemovedEventArgs & value) const noexcept
    {
        return winrt::impl::hash_unknown(value);
    }
};

template<>
struct std::hash<winrt::Windows::Devices::SmartCards::SmartCard>
{
    size_t operator()(const winrt::Windows::Devices::SmartCards::SmartCard & value) const noexcept
    {
        return winrt::impl::hash_unknown(value);
    }
};

template<>
struct std::hash<winrt::Windows::Devices::SmartCards::SmartCardChallengeContext>
{
    size_t operator()(const winrt::Windows::Devices::SmartCards::SmartCardChallengeContext & value) const noexcept
    {
        return winrt::impl::hash_unknown(value);
    }
};

template<>
struct std::hash<winrt::Windows::Devices::SmartCards::SmartCardConnection>
{
    size_t operator()(const winrt::Windows::Devices::SmartCards::SmartCardConnection & value) const noexcept
    {
        return winrt::impl::hash_unknown(value);
    }
};

template<>
struct std::hash<winrt::Windows::Devices::SmartCards::SmartCardPinPolicy>
{
    size_t operator()(const winrt::Windows::Devices::SmartCards::SmartCardPinPolicy & value) const noexcept
    {
        return winrt::impl::hash_unknown(value);
    }
};

template<>
struct std::hash<winrt::Windows::Devices::SmartCards::SmartCardPinResetDeferral>
{
    size_t operator()(const winrt::Windows::Devices::SmartCards::SmartCardPinResetDeferral & value) const noexcept
    {
        return winrt::impl::hash_unknown(value);
    }
};

template<>
struct std::hash<winrt::Windows::Devices::SmartCards::SmartCardPinResetRequest>
{
    size_t operator()(const winrt::Windows::Devices::SmartCards::SmartCardPinResetRequest & value) const noexcept
    {
        return winrt::impl::hash_unknown(value);
    }
};

template<>
struct std::hash<winrt::Windows::Devices::SmartCards::SmartCardProvisioning>
{
    size_t operator()(const winrt::Windows::Devices::SmartCards::SmartCardProvisioning & value) const noexcept
    {
        return winrt::impl::hash_unknown(value);
    }
};

template<>
struct std::hash<winrt::Windows::Devices::SmartCards::SmartCardReader>
{
    size_t operator()(const winrt::Windows::Devices::SmartCards::SmartCardReader & value) const noexcept
    {
        return winrt::impl::hash_unknown(value);
    }
};

WINRT_WARNING_POP
