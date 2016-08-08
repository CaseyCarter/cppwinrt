// C++ for the Windows Runtime v1.29
// Copyright (c) 2016 Microsoft Corporation

#pragma once

#include "internal\Windows.Storage.3.h"
#include "internal\Windows.Foundation.3.h"
#include "internal\Windows.Foundation.Collections.3.h"
#include "internal\Windows.Media.SpeechRecognition.3.h"
#include "internal\Windows.Globalization.3.h"
#include "internal\Windows.ApplicationModel.AppService.3.h"
#include "internal\Windows.ApplicationModel.VoiceCommands.3.h"
#include "Windows.ApplicationModel.h"

WINRT_EXPORT namespace winrt {

namespace impl {

template <typename D>
struct produce<D, Windows::ApplicationModel::VoiceCommands::IVoiceCommand> : produce_base<D, Windows::ApplicationModel::VoiceCommands::IVoiceCommand>
{
    HRESULT __stdcall get_CommandName(abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            *value = detach(this->shim().CommandName());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Properties(abi_arg_out<Windows::Foundation::Collections::IMapView<hstring, Windows::Foundation::Collections::IVectorView<hstring>>> value) noexcept override
    {
        try
        {
            *value = detach(this->shim().Properties());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_SpeechRecognitionResult(abi_arg_out<Windows::Media::SpeechRecognition::ISpeechRecognitionResult> value) noexcept override
    {
        try
        {
            *value = detach(this->shim().SpeechRecognitionResult());
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
struct produce<D, Windows::ApplicationModel::VoiceCommands::IVoiceCommandCompletedEventArgs> : produce_base<D, Windows::ApplicationModel::VoiceCommands::IVoiceCommandCompletedEventArgs>
{
    HRESULT __stdcall get_Reason(Windows::ApplicationModel::VoiceCommands::VoiceCommandCompletionReason * value) noexcept override
    {
        try
        {
            *value = detach(this->shim().Reason());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::ApplicationModel::VoiceCommands::IVoiceCommandConfirmationResult> : produce_base<D, Windows::ApplicationModel::VoiceCommands::IVoiceCommandConfirmationResult>
{
    HRESULT __stdcall get_Confirmed(bool * value) noexcept override
    {
        try
        {
            *value = detach(this->shim().Confirmed());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::ApplicationModel::VoiceCommands::IVoiceCommandContentTile> : produce_base<D, Windows::ApplicationModel::VoiceCommands::IVoiceCommandContentTile>
{
    HRESULT __stdcall get_Title(abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            *value = detach(this->shim().Title());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Title(abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            this->shim().Title(*reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_TextLine1(abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            *value = detach(this->shim().TextLine1());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_TextLine1(abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            this->shim().TextLine1(*reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_TextLine2(abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            *value = detach(this->shim().TextLine2());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_TextLine2(abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            this->shim().TextLine2(*reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_TextLine3(abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            *value = detach(this->shim().TextLine3());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_TextLine3(abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            this->shim().TextLine3(*reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Image(abi_arg_out<Windows::Storage::IStorageFile> value) noexcept override
    {
        try
        {
            *value = detach(this->shim().Image());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Image(abi_arg_in<Windows::Storage::IStorageFile> value) noexcept override
    {
        try
        {
            this->shim().Image(*reinterpret_cast<const Windows::Storage::IStorageFile *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_AppContext(abi_arg_out<Windows::IInspectable> value) noexcept override
    {
        try
        {
            *value = detach(this->shim().AppContext());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_AppContext(abi_arg_in<Windows::IInspectable> value) noexcept override
    {
        try
        {
            this->shim().AppContext(*reinterpret_cast<const Windows::IInspectable *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_AppLaunchArgument(abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            *value = detach(this->shim().AppLaunchArgument());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_AppLaunchArgument(abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            this->shim().AppLaunchArgument(*reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ContentTileType(Windows::ApplicationModel::VoiceCommands::VoiceCommandContentTileType * value) noexcept override
    {
        try
        {
            *value = detach(this->shim().ContentTileType());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_ContentTileType(Windows::ApplicationModel::VoiceCommands::VoiceCommandContentTileType value) noexcept override
    {
        try
        {
            this->shim().ContentTileType(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::ApplicationModel::VoiceCommands::IVoiceCommandDefinition> : produce_base<D, Windows::ApplicationModel::VoiceCommands::IVoiceCommandDefinition>
{
    HRESULT __stdcall get_Language(abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            *value = detach(this->shim().Language());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Name(abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            *value = detach(this->shim().Name());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_SetPhraseListAsync(abi_arg_in<hstring> phraseListName, abi_arg_in<Windows::Foundation::Collections::IIterable<hstring>> phraseList, abi_arg_out<Windows::Foundation::IAsyncAction> updateAction) noexcept override
    {
        try
        {
            *updateAction = detach(this->shim().SetPhraseListAsync(*reinterpret_cast<const hstring *>(&phraseListName), *reinterpret_cast<const Windows::Foundation::Collections::IIterable<hstring> *>(&phraseList)));
            return S_OK;
        }
        catch (...)
        {
            *updateAction = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::ApplicationModel::VoiceCommands::IVoiceCommandDefinitionManagerStatics> : produce_base<D, Windows::ApplicationModel::VoiceCommands::IVoiceCommandDefinitionManagerStatics>
{
    HRESULT __stdcall abi_InstallCommandDefinitionsFromStorageFileAsync(abi_arg_in<Windows::Storage::IStorageFile> file, abi_arg_out<Windows::Foundation::IAsyncAction> installAction) noexcept override
    {
        try
        {
            *installAction = detach(this->shim().InstallCommandDefinitionsFromStorageFileAsync(*reinterpret_cast<const Windows::Storage::StorageFile *>(&file)));
            return S_OK;
        }
        catch (...)
        {
            *installAction = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_InstalledCommandDefinitions(abi_arg_out<Windows::Foundation::Collections::IMapView<hstring, Windows::ApplicationModel::VoiceCommands::VoiceCommandDefinition>> voiceCommandDefinitions) noexcept override
    {
        try
        {
            *voiceCommandDefinitions = detach(this->shim().InstalledCommandDefinitions());
            return S_OK;
        }
        catch (...)
        {
            *voiceCommandDefinitions = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::ApplicationModel::VoiceCommands::IVoiceCommandDisambiguationResult> : produce_base<D, Windows::ApplicationModel::VoiceCommands::IVoiceCommandDisambiguationResult>
{
    HRESULT __stdcall get_SelectedItem(abi_arg_out<Windows::ApplicationModel::VoiceCommands::IVoiceCommandContentTile> value) noexcept override
    {
        try
        {
            *value = detach(this->shim().SelectedItem());
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
struct produce<D, Windows::ApplicationModel::VoiceCommands::IVoiceCommandResponse> : produce_base<D, Windows::ApplicationModel::VoiceCommands::IVoiceCommandResponse>
{
    HRESULT __stdcall get_Message(abi_arg_out<Windows::ApplicationModel::VoiceCommands::IVoiceCommandUserMessage> value) noexcept override
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

    HRESULT __stdcall put_Message(abi_arg_in<Windows::ApplicationModel::VoiceCommands::IVoiceCommandUserMessage> value) noexcept override
    {
        try
        {
            this->shim().Message(*reinterpret_cast<const Windows::ApplicationModel::VoiceCommands::VoiceCommandUserMessage *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_RepeatMessage(abi_arg_out<Windows::ApplicationModel::VoiceCommands::IVoiceCommandUserMessage> value) noexcept override
    {
        try
        {
            *value = detach(this->shim().RepeatMessage());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_RepeatMessage(abi_arg_in<Windows::ApplicationModel::VoiceCommands::IVoiceCommandUserMessage> value) noexcept override
    {
        try
        {
            this->shim().RepeatMessage(*reinterpret_cast<const Windows::ApplicationModel::VoiceCommands::VoiceCommandUserMessage *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_AppLaunchArgument(abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            *value = detach(this->shim().AppLaunchArgument());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_AppLaunchArgument(abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            this->shim().AppLaunchArgument(*reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_VoiceCommandContentTiles(abi_arg_out<Windows::Foundation::Collections::IVector<Windows::ApplicationModel::VoiceCommands::VoiceCommandContentTile>> value) noexcept override
    {
        try
        {
            *value = detach(this->shim().VoiceCommandContentTiles());
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
struct produce<D, Windows::ApplicationModel::VoiceCommands::IVoiceCommandResponseStatics> : produce_base<D, Windows::ApplicationModel::VoiceCommands::IVoiceCommandResponseStatics>
{
    HRESULT __stdcall get_MaxSupportedVoiceCommandContentTiles(uint32_t * value) noexcept override
    {
        try
        {
            *value = detach(this->shim().MaxSupportedVoiceCommandContentTiles());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_CreateResponse(abi_arg_in<Windows::ApplicationModel::VoiceCommands::IVoiceCommandUserMessage> userMessage, abi_arg_out<Windows::ApplicationModel::VoiceCommands::IVoiceCommandResponse> response) noexcept override
    {
        try
        {
            *response = detach(this->shim().CreateResponse(*reinterpret_cast<const Windows::ApplicationModel::VoiceCommands::VoiceCommandUserMessage *>(&userMessage)));
            return S_OK;
        }
        catch (...)
        {
            *response = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_CreateResponseWithTiles(abi_arg_in<Windows::ApplicationModel::VoiceCommands::IVoiceCommandUserMessage> message, abi_arg_in<Windows::Foundation::Collections::IIterable<Windows::ApplicationModel::VoiceCommands::VoiceCommandContentTile>> contentTiles, abi_arg_out<Windows::ApplicationModel::VoiceCommands::IVoiceCommandResponse> response) noexcept override
    {
        try
        {
            *response = detach(this->shim().CreateResponse(*reinterpret_cast<const Windows::ApplicationModel::VoiceCommands::VoiceCommandUserMessage *>(&message), *reinterpret_cast<const Windows::Foundation::Collections::IIterable<Windows::ApplicationModel::VoiceCommands::VoiceCommandContentTile> *>(&contentTiles)));
            return S_OK;
        }
        catch (...)
        {
            *response = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_CreateResponseForPrompt(abi_arg_in<Windows::ApplicationModel::VoiceCommands::IVoiceCommandUserMessage> message, abi_arg_in<Windows::ApplicationModel::VoiceCommands::IVoiceCommandUserMessage> repeatMessage, abi_arg_out<Windows::ApplicationModel::VoiceCommands::IVoiceCommandResponse> response) noexcept override
    {
        try
        {
            *response = detach(this->shim().CreateResponseForPrompt(*reinterpret_cast<const Windows::ApplicationModel::VoiceCommands::VoiceCommandUserMessage *>(&message), *reinterpret_cast<const Windows::ApplicationModel::VoiceCommands::VoiceCommandUserMessage *>(&repeatMessage)));
            return S_OK;
        }
        catch (...)
        {
            *response = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_CreateResponseForPromptWithTiles(abi_arg_in<Windows::ApplicationModel::VoiceCommands::IVoiceCommandUserMessage> message, abi_arg_in<Windows::ApplicationModel::VoiceCommands::IVoiceCommandUserMessage> repeatMessage, abi_arg_in<Windows::Foundation::Collections::IIterable<Windows::ApplicationModel::VoiceCommands::VoiceCommandContentTile>> contentTiles, abi_arg_out<Windows::ApplicationModel::VoiceCommands::IVoiceCommandResponse> response) noexcept override
    {
        try
        {
            *response = detach(this->shim().CreateResponseForPrompt(*reinterpret_cast<const Windows::ApplicationModel::VoiceCommands::VoiceCommandUserMessage *>(&message), *reinterpret_cast<const Windows::ApplicationModel::VoiceCommands::VoiceCommandUserMessage *>(&repeatMessage), *reinterpret_cast<const Windows::Foundation::Collections::IIterable<Windows::ApplicationModel::VoiceCommands::VoiceCommandContentTile> *>(&contentTiles)));
            return S_OK;
        }
        catch (...)
        {
            *response = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::ApplicationModel::VoiceCommands::IVoiceCommandServiceConnection> : produce_base<D, Windows::ApplicationModel::VoiceCommands::IVoiceCommandServiceConnection>
{
    HRESULT __stdcall abi_GetVoiceCommandAsync(abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::VoiceCommands::VoiceCommand>> operation) noexcept override
    {
        try
        {
            *operation = detach(this->shim().GetVoiceCommandAsync());
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_RequestConfirmationAsync(abi_arg_in<Windows::ApplicationModel::VoiceCommands::IVoiceCommandResponse> response, abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::VoiceCommands::VoiceCommandConfirmationResult>> operation) noexcept override
    {
        try
        {
            *operation = detach(this->shim().RequestConfirmationAsync(*reinterpret_cast<const Windows::ApplicationModel::VoiceCommands::VoiceCommandResponse *>(&response)));
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_RequestDisambiguationAsync(abi_arg_in<Windows::ApplicationModel::VoiceCommands::IVoiceCommandResponse> response, abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::VoiceCommands::VoiceCommandDisambiguationResult>> operation) noexcept override
    {
        try
        {
            *operation = detach(this->shim().RequestDisambiguationAsync(*reinterpret_cast<const Windows::ApplicationModel::VoiceCommands::VoiceCommandResponse *>(&response)));
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_ReportProgressAsync(abi_arg_in<Windows::ApplicationModel::VoiceCommands::IVoiceCommandResponse> response, abi_arg_out<Windows::Foundation::IAsyncAction> action) noexcept override
    {
        try
        {
            *action = detach(this->shim().ReportProgressAsync(*reinterpret_cast<const Windows::ApplicationModel::VoiceCommands::VoiceCommandResponse *>(&response)));
            return S_OK;
        }
        catch (...)
        {
            *action = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_ReportSuccessAsync(abi_arg_in<Windows::ApplicationModel::VoiceCommands::IVoiceCommandResponse> response, abi_arg_out<Windows::Foundation::IAsyncAction> action) noexcept override
    {
        try
        {
            *action = detach(this->shim().ReportSuccessAsync(*reinterpret_cast<const Windows::ApplicationModel::VoiceCommands::VoiceCommandResponse *>(&response)));
            return S_OK;
        }
        catch (...)
        {
            *action = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_ReportFailureAsync(abi_arg_in<Windows::ApplicationModel::VoiceCommands::IVoiceCommandResponse> response, abi_arg_out<Windows::Foundation::IAsyncAction> action) noexcept override
    {
        try
        {
            *action = detach(this->shim().ReportFailureAsync(*reinterpret_cast<const Windows::ApplicationModel::VoiceCommands::VoiceCommandResponse *>(&response)));
            return S_OK;
        }
        catch (...)
        {
            *action = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_RequestAppLaunchAsync(abi_arg_in<Windows::ApplicationModel::VoiceCommands::IVoiceCommandResponse> response, abi_arg_out<Windows::Foundation::IAsyncAction> action) noexcept override
    {
        try
        {
            *action = detach(this->shim().RequestAppLaunchAsync(*reinterpret_cast<const Windows::ApplicationModel::VoiceCommands::VoiceCommandResponse *>(&response)));
            return S_OK;
        }
        catch (...)
        {
            *action = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Language(abi_arg_out<Windows::Globalization::ILanguage> language) noexcept override
    {
        try
        {
            *language = detach(this->shim().Language());
            return S_OK;
        }
        catch (...)
        {
            *language = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_VoiceCommandCompleted(abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::VoiceCommands::VoiceCommandServiceConnection, Windows::ApplicationModel::VoiceCommands::VoiceCommandCompletedEventArgs>> handler, event_token * token) noexcept override
    {
        try
        {
            *token = detach(this->shim().VoiceCommandCompleted(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::VoiceCommands::VoiceCommandServiceConnection, Windows::ApplicationModel::VoiceCommands::VoiceCommandCompletedEventArgs> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_VoiceCommandCompleted(event_token token) noexcept override
    {
        try
        {
            this->shim().VoiceCommandCompleted(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::ApplicationModel::VoiceCommands::IVoiceCommandServiceConnectionStatics> : produce_base<D, Windows::ApplicationModel::VoiceCommands::IVoiceCommandServiceConnectionStatics>
{
    HRESULT __stdcall abi_FromAppServiceTriggerDetails(abi_arg_in<Windows::ApplicationModel::AppService::IAppServiceTriggerDetails> triggerDetails, abi_arg_out<Windows::ApplicationModel::VoiceCommands::IVoiceCommandServiceConnection> value) noexcept override
    {
        try
        {
            *value = detach(this->shim().FromAppServiceTriggerDetails(*reinterpret_cast<const Windows::ApplicationModel::AppService::AppServiceTriggerDetails *>(&triggerDetails)));
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
struct produce<D, Windows::ApplicationModel::VoiceCommands::IVoiceCommandUserMessage> : produce_base<D, Windows::ApplicationModel::VoiceCommands::IVoiceCommandUserMessage>
{
    HRESULT __stdcall get_DisplayMessage(abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            *value = detach(this->shim().DisplayMessage());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_DisplayMessage(abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            this->shim().DisplayMessage(*reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_SpokenMessage(abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            *value = detach(this->shim().SpokenMessage());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_SpokenMessage(abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            this->shim().SpokenMessage(*reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

}

namespace Windows::ApplicationModel::VoiceCommands {

template <typename D> Windows::Foundation::IAsyncAction impl_IVoiceCommandDefinitionManagerStatics<D>::InstallCommandDefinitionsFromStorageFileAsync(const Windows::Storage::StorageFile & file) const
{
    Windows::Foundation::IAsyncAction installAction;
    check_hresult(shim()->abi_InstallCommandDefinitionsFromStorageFileAsync(get(file), put(installAction)));
    return installAction;
}

template <typename D> Windows::Foundation::Collections::IMapView<hstring, Windows::ApplicationModel::VoiceCommands::VoiceCommandDefinition> impl_IVoiceCommandDefinitionManagerStatics<D>::InstalledCommandDefinitions() const
{
    Windows::Foundation::Collections::IMapView<hstring, Windows::ApplicationModel::VoiceCommands::VoiceCommandDefinition> voiceCommandDefinitions;
    check_hresult(shim()->get_InstalledCommandDefinitions(put(voiceCommandDefinitions)));
    return voiceCommandDefinitions;
}

template <typename D> hstring impl_IVoiceCommandDefinition<D>::Language() const
{
    hstring value;
    check_hresult(shim()->get_Language(put(value)));
    return value;
}

template <typename D> hstring impl_IVoiceCommandDefinition<D>::Name() const
{
    hstring value;
    check_hresult(shim()->get_Name(put(value)));
    return value;
}

template <typename D> Windows::Foundation::IAsyncAction impl_IVoiceCommandDefinition<D>::SetPhraseListAsync(hstring_ref phraseListName, const Windows::Foundation::Collections::IIterable<hstring> & phraseList) const
{
    Windows::Foundation::IAsyncAction updateAction;
    check_hresult(shim()->abi_SetPhraseListAsync(get(phraseListName), get(phraseList), put(updateAction)));
    return updateAction;
}

template <typename D> hstring impl_IVoiceCommandContentTile<D>::Title() const
{
    hstring value;
    check_hresult(shim()->get_Title(put(value)));
    return value;
}

template <typename D> void impl_IVoiceCommandContentTile<D>::Title(hstring_ref value) const
{
    check_hresult(shim()->put_Title(get(value)));
}

template <typename D> hstring impl_IVoiceCommandContentTile<D>::TextLine1() const
{
    hstring value;
    check_hresult(shim()->get_TextLine1(put(value)));
    return value;
}

template <typename D> void impl_IVoiceCommandContentTile<D>::TextLine1(hstring_ref value) const
{
    check_hresult(shim()->put_TextLine1(get(value)));
}

template <typename D> hstring impl_IVoiceCommandContentTile<D>::TextLine2() const
{
    hstring value;
    check_hresult(shim()->get_TextLine2(put(value)));
    return value;
}

template <typename D> void impl_IVoiceCommandContentTile<D>::TextLine2(hstring_ref value) const
{
    check_hresult(shim()->put_TextLine2(get(value)));
}

template <typename D> hstring impl_IVoiceCommandContentTile<D>::TextLine3() const
{
    hstring value;
    check_hresult(shim()->get_TextLine3(put(value)));
    return value;
}

template <typename D> void impl_IVoiceCommandContentTile<D>::TextLine3(hstring_ref value) const
{
    check_hresult(shim()->put_TextLine3(get(value)));
}

template <typename D> Windows::Storage::IStorageFile impl_IVoiceCommandContentTile<D>::Image() const
{
    Windows::Storage::IStorageFile value;
    check_hresult(shim()->get_Image(put(value)));
    return value;
}

template <typename D> void impl_IVoiceCommandContentTile<D>::Image(const Windows::Storage::IStorageFile & value) const
{
    check_hresult(shim()->put_Image(get(value)));
}

template <typename D> Windows::IInspectable impl_IVoiceCommandContentTile<D>::AppContext() const
{
    Windows::IInspectable value;
    check_hresult(shim()->get_AppContext(put(value)));
    return value;
}

template <typename D> void impl_IVoiceCommandContentTile<D>::AppContext(const Windows::IInspectable & value) const
{
    check_hresult(shim()->put_AppContext(get(value)));
}

template <typename D> hstring impl_IVoiceCommandContentTile<D>::AppLaunchArgument() const
{
    hstring value;
    check_hresult(shim()->get_AppLaunchArgument(put(value)));
    return value;
}

template <typename D> void impl_IVoiceCommandContentTile<D>::AppLaunchArgument(hstring_ref value) const
{
    check_hresult(shim()->put_AppLaunchArgument(get(value)));
}

template <typename D> Windows::ApplicationModel::VoiceCommands::VoiceCommandContentTileType impl_IVoiceCommandContentTile<D>::ContentTileType() const
{
    Windows::ApplicationModel::VoiceCommands::VoiceCommandContentTileType value {};
    check_hresult(shim()->get_ContentTileType(&value));
    return value;
}

template <typename D> void impl_IVoiceCommandContentTile<D>::ContentTileType(Windows::ApplicationModel::VoiceCommands::VoiceCommandContentTileType value) const
{
    check_hresult(shim()->put_ContentTileType(value));
}

template <typename D> hstring impl_IVoiceCommandUserMessage<D>::DisplayMessage() const
{
    hstring value;
    check_hresult(shim()->get_DisplayMessage(put(value)));
    return value;
}

template <typename D> void impl_IVoiceCommandUserMessage<D>::DisplayMessage(hstring_ref value) const
{
    check_hresult(shim()->put_DisplayMessage(get(value)));
}

template <typename D> hstring impl_IVoiceCommandUserMessage<D>::SpokenMessage() const
{
    hstring value;
    check_hresult(shim()->get_SpokenMessage(put(value)));
    return value;
}

template <typename D> void impl_IVoiceCommandUserMessage<D>::SpokenMessage(hstring_ref value) const
{
    check_hresult(shim()->put_SpokenMessage(get(value)));
}

template <typename D> hstring impl_IVoiceCommand<D>::CommandName() const
{
    hstring value;
    check_hresult(shim()->get_CommandName(put(value)));
    return value;
}

template <typename D> Windows::Foundation::Collections::IMapView<hstring, Windows::Foundation::Collections::IVectorView<hstring>> impl_IVoiceCommand<D>::Properties() const
{
    Windows::Foundation::Collections::IMapView<hstring, Windows::Foundation::Collections::IVectorView<hstring>> value;
    check_hresult(shim()->get_Properties(put(value)));
    return value;
}

template <typename D> Windows::Media::SpeechRecognition::SpeechRecognitionResult impl_IVoiceCommand<D>::SpeechRecognitionResult() const
{
    Windows::Media::SpeechRecognition::SpeechRecognitionResult value { nullptr };
    check_hresult(shim()->get_SpeechRecognitionResult(put(value)));
    return value;
}

template <typename D> Windows::ApplicationModel::VoiceCommands::VoiceCommandCompletionReason impl_IVoiceCommandCompletedEventArgs<D>::Reason() const
{
    Windows::ApplicationModel::VoiceCommands::VoiceCommandCompletionReason value {};
    check_hresult(shim()->get_Reason(&value));
    return value;
}

template <typename D> Windows::ApplicationModel::VoiceCommands::VoiceCommandContentTile impl_IVoiceCommandDisambiguationResult<D>::SelectedItem() const
{
    Windows::ApplicationModel::VoiceCommands::VoiceCommandContentTile value { nullptr };
    check_hresult(shim()->get_SelectedItem(put(value)));
    return value;
}

template <typename D> bool impl_IVoiceCommandConfirmationResult<D>::Confirmed() const
{
    bool value {};
    check_hresult(shim()->get_Confirmed(&value));
    return value;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::VoiceCommands::VoiceCommand> impl_IVoiceCommandServiceConnection<D>::GetVoiceCommandAsync() const
{
    Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::VoiceCommands::VoiceCommand> operation;
    check_hresult(shim()->abi_GetVoiceCommandAsync(put(operation)));
    return operation;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::VoiceCommands::VoiceCommandConfirmationResult> impl_IVoiceCommandServiceConnection<D>::RequestConfirmationAsync(const Windows::ApplicationModel::VoiceCommands::VoiceCommandResponse & response) const
{
    Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::VoiceCommands::VoiceCommandConfirmationResult> operation;
    check_hresult(shim()->abi_RequestConfirmationAsync(get(response), put(operation)));
    return operation;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::VoiceCommands::VoiceCommandDisambiguationResult> impl_IVoiceCommandServiceConnection<D>::RequestDisambiguationAsync(const Windows::ApplicationModel::VoiceCommands::VoiceCommandResponse & response) const
{
    Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::VoiceCommands::VoiceCommandDisambiguationResult> operation;
    check_hresult(shim()->abi_RequestDisambiguationAsync(get(response), put(operation)));
    return operation;
}

template <typename D> Windows::Foundation::IAsyncAction impl_IVoiceCommandServiceConnection<D>::ReportProgressAsync(const Windows::ApplicationModel::VoiceCommands::VoiceCommandResponse & response) const
{
    Windows::Foundation::IAsyncAction action;
    check_hresult(shim()->abi_ReportProgressAsync(get(response), put(action)));
    return action;
}

template <typename D> Windows::Foundation::IAsyncAction impl_IVoiceCommandServiceConnection<D>::ReportSuccessAsync(const Windows::ApplicationModel::VoiceCommands::VoiceCommandResponse & response) const
{
    Windows::Foundation::IAsyncAction action;
    check_hresult(shim()->abi_ReportSuccessAsync(get(response), put(action)));
    return action;
}

template <typename D> Windows::Foundation::IAsyncAction impl_IVoiceCommandServiceConnection<D>::ReportFailureAsync(const Windows::ApplicationModel::VoiceCommands::VoiceCommandResponse & response) const
{
    Windows::Foundation::IAsyncAction action;
    check_hresult(shim()->abi_ReportFailureAsync(get(response), put(action)));
    return action;
}

template <typename D> Windows::Foundation::IAsyncAction impl_IVoiceCommandServiceConnection<D>::RequestAppLaunchAsync(const Windows::ApplicationModel::VoiceCommands::VoiceCommandResponse & response) const
{
    Windows::Foundation::IAsyncAction action;
    check_hresult(shim()->abi_RequestAppLaunchAsync(get(response), put(action)));
    return action;
}

template <typename D> Windows::Globalization::Language impl_IVoiceCommandServiceConnection<D>::Language() const
{
    Windows::Globalization::Language language { nullptr };
    check_hresult(shim()->get_Language(put(language)));
    return language;
}

template <typename D> event_token impl_IVoiceCommandServiceConnection<D>::VoiceCommandCompleted(const Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::VoiceCommands::VoiceCommandServiceConnection, Windows::ApplicationModel::VoiceCommands::VoiceCommandCompletedEventArgs> & handler) const
{
    event_token token {};
    check_hresult(shim()->add_VoiceCommandCompleted(get(handler), &token));
    return token;
}

template <typename D> event_revoker<IVoiceCommandServiceConnection> impl_IVoiceCommandServiceConnection<D>::VoiceCommandCompleted(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::VoiceCommands::VoiceCommandServiceConnection, Windows::ApplicationModel::VoiceCommands::VoiceCommandCompletedEventArgs> & handler) const
{
    return impl::make_event_revoker<D, IVoiceCommandServiceConnection>(this, &ABI::Windows::ApplicationModel::VoiceCommands::IVoiceCommandServiceConnection::remove_VoiceCommandCompleted, VoiceCommandCompleted(handler));
}

template <typename D> void impl_IVoiceCommandServiceConnection<D>::VoiceCommandCompleted(event_token token) const
{
    check_hresult(shim()->remove_VoiceCommandCompleted(token));
}

template <typename D> Windows::ApplicationModel::VoiceCommands::VoiceCommandServiceConnection impl_IVoiceCommandServiceConnectionStatics<D>::FromAppServiceTriggerDetails(const Windows::ApplicationModel::AppService::AppServiceTriggerDetails & triggerDetails) const
{
    Windows::ApplicationModel::VoiceCommands::VoiceCommandServiceConnection value { nullptr };
    check_hresult(shim()->abi_FromAppServiceTriggerDetails(get(triggerDetails), put(value)));
    return value;
}

template <typename D> uint32_t impl_IVoiceCommandResponseStatics<D>::MaxSupportedVoiceCommandContentTiles() const
{
    uint32_t value {};
    check_hresult(shim()->get_MaxSupportedVoiceCommandContentTiles(&value));
    return value;
}

template <typename D> Windows::ApplicationModel::VoiceCommands::VoiceCommandResponse impl_IVoiceCommandResponseStatics<D>::CreateResponse(const Windows::ApplicationModel::VoiceCommands::VoiceCommandUserMessage & userMessage) const
{
    Windows::ApplicationModel::VoiceCommands::VoiceCommandResponse response { nullptr };
    check_hresult(shim()->abi_CreateResponse(get(userMessage), put(response)));
    return response;
}

template <typename D> Windows::ApplicationModel::VoiceCommands::VoiceCommandResponse impl_IVoiceCommandResponseStatics<D>::CreateResponse(const Windows::ApplicationModel::VoiceCommands::VoiceCommandUserMessage & message, const Windows::Foundation::Collections::IIterable<Windows::ApplicationModel::VoiceCommands::VoiceCommandContentTile> & contentTiles) const
{
    Windows::ApplicationModel::VoiceCommands::VoiceCommandResponse response { nullptr };
    check_hresult(shim()->abi_CreateResponseWithTiles(get(message), get(contentTiles), put(response)));
    return response;
}

template <typename D> Windows::ApplicationModel::VoiceCommands::VoiceCommandResponse impl_IVoiceCommandResponseStatics<D>::CreateResponseForPrompt(const Windows::ApplicationModel::VoiceCommands::VoiceCommandUserMessage & message, const Windows::ApplicationModel::VoiceCommands::VoiceCommandUserMessage & repeatMessage) const
{
    Windows::ApplicationModel::VoiceCommands::VoiceCommandResponse response { nullptr };
    check_hresult(shim()->abi_CreateResponseForPrompt(get(message), get(repeatMessage), put(response)));
    return response;
}

template <typename D> Windows::ApplicationModel::VoiceCommands::VoiceCommandResponse impl_IVoiceCommandResponseStatics<D>::CreateResponseForPrompt(const Windows::ApplicationModel::VoiceCommands::VoiceCommandUserMessage & message, const Windows::ApplicationModel::VoiceCommands::VoiceCommandUserMessage & repeatMessage, const Windows::Foundation::Collections::IIterable<Windows::ApplicationModel::VoiceCommands::VoiceCommandContentTile> & contentTiles) const
{
    Windows::ApplicationModel::VoiceCommands::VoiceCommandResponse response { nullptr };
    check_hresult(shim()->abi_CreateResponseForPromptWithTiles(get(message), get(repeatMessage), get(contentTiles), put(response)));
    return response;
}

template <typename D> Windows::ApplicationModel::VoiceCommands::VoiceCommandUserMessage impl_IVoiceCommandResponse<D>::Message() const
{
    Windows::ApplicationModel::VoiceCommands::VoiceCommandUserMessage value { nullptr };
    check_hresult(shim()->get_Message(put(value)));
    return value;
}

template <typename D> void impl_IVoiceCommandResponse<D>::Message(const Windows::ApplicationModel::VoiceCommands::VoiceCommandUserMessage & value) const
{
    check_hresult(shim()->put_Message(get(value)));
}

template <typename D> Windows::ApplicationModel::VoiceCommands::VoiceCommandUserMessage impl_IVoiceCommandResponse<D>::RepeatMessage() const
{
    Windows::ApplicationModel::VoiceCommands::VoiceCommandUserMessage value { nullptr };
    check_hresult(shim()->get_RepeatMessage(put(value)));
    return value;
}

template <typename D> void impl_IVoiceCommandResponse<D>::RepeatMessage(const Windows::ApplicationModel::VoiceCommands::VoiceCommandUserMessage & value) const
{
    check_hresult(shim()->put_RepeatMessage(get(value)));
}

template <typename D> hstring impl_IVoiceCommandResponse<D>::AppLaunchArgument() const
{
    hstring value;
    check_hresult(shim()->get_AppLaunchArgument(put(value)));
    return value;
}

template <typename D> void impl_IVoiceCommandResponse<D>::AppLaunchArgument(hstring_ref value) const
{
    check_hresult(shim()->put_AppLaunchArgument(get(value)));
}

template <typename D> Windows::Foundation::Collections::IVector<Windows::ApplicationModel::VoiceCommands::VoiceCommandContentTile> impl_IVoiceCommandResponse<D>::VoiceCommandContentTiles() const
{
    Windows::Foundation::Collections::IVector<Windows::ApplicationModel::VoiceCommands::VoiceCommandContentTile> value;
    check_hresult(shim()->get_VoiceCommandContentTiles(put(value)));
    return value;
}

inline VoiceCommandContentTile::VoiceCommandContentTile() :
    VoiceCommandContentTile(activate_instance<VoiceCommandContentTile>())
{}

inline Windows::Foundation::IAsyncAction VoiceCommandDefinitionManager::InstallCommandDefinitionsFromStorageFileAsync(const Windows::Storage::StorageFile & file)
{
    return get_activation_factory<VoiceCommandDefinitionManager, IVoiceCommandDefinitionManagerStatics>().InstallCommandDefinitionsFromStorageFileAsync(file);
}

inline Windows::Foundation::Collections::IMapView<hstring, Windows::ApplicationModel::VoiceCommands::VoiceCommandDefinition> VoiceCommandDefinitionManager::InstalledCommandDefinitions()
{
    return get_activation_factory<VoiceCommandDefinitionManager, IVoiceCommandDefinitionManagerStatics>().InstalledCommandDefinitions();
}

inline uint32_t VoiceCommandResponse::MaxSupportedVoiceCommandContentTiles()
{
    return get_activation_factory<VoiceCommandResponse, IVoiceCommandResponseStatics>().MaxSupportedVoiceCommandContentTiles();
}

inline Windows::ApplicationModel::VoiceCommands::VoiceCommandResponse VoiceCommandResponse::CreateResponse(const Windows::ApplicationModel::VoiceCommands::VoiceCommandUserMessage & userMessage)
{
    return get_activation_factory<VoiceCommandResponse, IVoiceCommandResponseStatics>().CreateResponse(userMessage);
}

inline Windows::ApplicationModel::VoiceCommands::VoiceCommandResponse VoiceCommandResponse::CreateResponse(const Windows::ApplicationModel::VoiceCommands::VoiceCommandUserMessage & message, const Windows::Foundation::Collections::IIterable<Windows::ApplicationModel::VoiceCommands::VoiceCommandContentTile> & contentTiles)
{
    return get_activation_factory<VoiceCommandResponse, IVoiceCommandResponseStatics>().CreateResponse(message, contentTiles);
}

inline Windows::ApplicationModel::VoiceCommands::VoiceCommandResponse VoiceCommandResponse::CreateResponseForPrompt(const Windows::ApplicationModel::VoiceCommands::VoiceCommandUserMessage & message, const Windows::ApplicationModel::VoiceCommands::VoiceCommandUserMessage & repeatMessage)
{
    return get_activation_factory<VoiceCommandResponse, IVoiceCommandResponseStatics>().CreateResponseForPrompt(message, repeatMessage);
}

inline Windows::ApplicationModel::VoiceCommands::VoiceCommandResponse VoiceCommandResponse::CreateResponseForPrompt(const Windows::ApplicationModel::VoiceCommands::VoiceCommandUserMessage & message, const Windows::ApplicationModel::VoiceCommands::VoiceCommandUserMessage & repeatMessage, const Windows::Foundation::Collections::IIterable<Windows::ApplicationModel::VoiceCommands::VoiceCommandContentTile> & contentTiles)
{
    return get_activation_factory<VoiceCommandResponse, IVoiceCommandResponseStatics>().CreateResponseForPrompt(message, repeatMessage, contentTiles);
}

inline Windows::ApplicationModel::VoiceCommands::VoiceCommandServiceConnection VoiceCommandServiceConnection::FromAppServiceTriggerDetails(const Windows::ApplicationModel::AppService::AppServiceTriggerDetails & triggerDetails)
{
    return get_activation_factory<VoiceCommandServiceConnection, IVoiceCommandServiceConnectionStatics>().FromAppServiceTriggerDetails(triggerDetails);
}

inline VoiceCommandUserMessage::VoiceCommandUserMessage() :
    VoiceCommandUserMessage(activate_instance<VoiceCommandUserMessage>())
{}

}

}
