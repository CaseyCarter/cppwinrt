// C++ for the Windows Runtime v1.29
// Copyright (c) 2016 Microsoft Corporation

#pragma once

#include "internal\Windows.Security.Credentials.class.h"
#include "internal\Windows.Foundation.Collections.class.h"
#include "internal\Windows.Foundation.class.h"
#include "internal\Windows.Storage.class.h"
#include "internal\Windows.Storage.Streams.class.h"
#include "internal\Windows.UI.Notifications.class.h"
#include "internal\Windows.Web.class.h"
#include "internal\Windows.ApplicationModel.Background.class.h"
#include "internal\Windows.Networking.BackgroundTransfer.class.h"
#include "Windows.Networking.h"

WINRT_EXPORT namespace winrt {

namespace impl {

template <typename D>
struct produce<D, Windows::Networking::BackgroundTransfer::IBackgroundDownloader> : produce_base<D, Windows::Networking::BackgroundTransfer::IBackgroundDownloader>
{
    HRESULT __stdcall abi_CreateDownload(abi_arg_in<Windows::Foundation::IUriRuntimeClass> uri, abi_arg_in<Windows::Storage::IStorageFile> resultFile, abi_arg_out<Windows::Networking::BackgroundTransfer::IDownloadOperation> operation) noexcept override
    {
        try
        {
            *operation = detach(shim().CreateDownload(*reinterpret_cast<const Windows::Foundation::Uri *>(&uri), *reinterpret_cast<const Windows::Storage::IStorageFile *>(&resultFile)));
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_CreateDownloadFromFile(abi_arg_in<Windows::Foundation::IUriRuntimeClass> uri, abi_arg_in<Windows::Storage::IStorageFile> resultFile, abi_arg_in<Windows::Storage::IStorageFile> requestBodyFile, abi_arg_out<Windows::Networking::BackgroundTransfer::IDownloadOperation> operation) noexcept override
    {
        try
        {
            *operation = detach(shim().CreateDownload(*reinterpret_cast<const Windows::Foundation::Uri *>(&uri), *reinterpret_cast<const Windows::Storage::IStorageFile *>(&resultFile), *reinterpret_cast<const Windows::Storage::IStorageFile *>(&requestBodyFile)));
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_CreateDownloadAsync(abi_arg_in<Windows::Foundation::IUriRuntimeClass> uri, abi_arg_in<Windows::Storage::IStorageFile> resultFile, abi_arg_in<Windows::Storage::Streams::IInputStream> requestBodyStream, abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Networking::BackgroundTransfer::DownloadOperation>> operation) noexcept override
    {
        try
        {
            *operation = detach(shim().CreateDownloadAsync(*reinterpret_cast<const Windows::Foundation::Uri *>(&uri), *reinterpret_cast<const Windows::Storage::IStorageFile *>(&resultFile), *reinterpret_cast<const Windows::Storage::Streams::IInputStream *>(&requestBodyStream)));
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Networking::BackgroundTransfer::IBackgroundDownloader2> : produce_base<D, Windows::Networking::BackgroundTransfer::IBackgroundDownloader2>
{
    HRESULT __stdcall get_TransferGroup(abi_arg_out<Windows::Networking::BackgroundTransfer::IBackgroundTransferGroup> value) noexcept override
    {
        try
        {
            *value = detach(shim().TransferGroup());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_TransferGroup(abi_arg_in<Windows::Networking::BackgroundTransfer::IBackgroundTransferGroup> value) noexcept override
    {
        try
        {
            shim().TransferGroup(*reinterpret_cast<const Windows::Networking::BackgroundTransfer::BackgroundTransferGroup *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_SuccessToastNotification(abi_arg_out<Windows::UI::Notifications::IToastNotification> value) noexcept override
    {
        try
        {
            *value = detach(shim().SuccessToastNotification());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_SuccessToastNotification(abi_arg_in<Windows::UI::Notifications::IToastNotification> value) noexcept override
    {
        try
        {
            shim().SuccessToastNotification(*reinterpret_cast<const Windows::UI::Notifications::ToastNotification *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_FailureToastNotification(abi_arg_out<Windows::UI::Notifications::IToastNotification> value) noexcept override
    {
        try
        {
            *value = detach(shim().FailureToastNotification());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_FailureToastNotification(abi_arg_in<Windows::UI::Notifications::IToastNotification> value) noexcept override
    {
        try
        {
            shim().FailureToastNotification(*reinterpret_cast<const Windows::UI::Notifications::ToastNotification *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_SuccessTileNotification(abi_arg_out<Windows::UI::Notifications::ITileNotification> value) noexcept override
    {
        try
        {
            *value = detach(shim().SuccessTileNotification());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_SuccessTileNotification(abi_arg_in<Windows::UI::Notifications::ITileNotification> value) noexcept override
    {
        try
        {
            shim().SuccessTileNotification(*reinterpret_cast<const Windows::UI::Notifications::TileNotification *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_FailureTileNotification(abi_arg_out<Windows::UI::Notifications::ITileNotification> value) noexcept override
    {
        try
        {
            *value = detach(shim().FailureTileNotification());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_FailureTileNotification(abi_arg_in<Windows::UI::Notifications::ITileNotification> value) noexcept override
    {
        try
        {
            shim().FailureTileNotification(*reinterpret_cast<const Windows::UI::Notifications::TileNotification *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Networking::BackgroundTransfer::IBackgroundDownloader3> : produce_base<D, Windows::Networking::BackgroundTransfer::IBackgroundDownloader3>
{
    HRESULT __stdcall get_CompletionGroup(abi_arg_out<Windows::Networking::BackgroundTransfer::IBackgroundTransferCompletionGroup> value) noexcept override
    {
        try
        {
            *value = detach(shim().CompletionGroup());
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
struct produce<D, Windows::Networking::BackgroundTransfer::IBackgroundDownloaderFactory> : produce_base<D, Windows::Networking::BackgroundTransfer::IBackgroundDownloaderFactory>
{
    HRESULT __stdcall abi_CreateWithCompletionGroup(abi_arg_in<Windows::Networking::BackgroundTransfer::IBackgroundTransferCompletionGroup> completionGroup, abi_arg_out<Windows::Networking::BackgroundTransfer::IBackgroundDownloader> backgroundDownloader) noexcept override
    {
        try
        {
            *backgroundDownloader = detach(shim().CreateWithCompletionGroup(*reinterpret_cast<const Windows::Networking::BackgroundTransfer::BackgroundTransferCompletionGroup *>(&completionGroup)));
            return S_OK;
        }
        catch (...)
        {
            *backgroundDownloader = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Networking::BackgroundTransfer::IBackgroundDownloaderStaticMethods> : produce_base<D, Windows::Networking::BackgroundTransfer::IBackgroundDownloaderStaticMethods>
{
    HRESULT __stdcall abi_GetCurrentDownloadsAsync(abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::Networking::BackgroundTransfer::DownloadOperation>>> operation) noexcept override
    {
        try
        {
            *operation = detach(shim().GetCurrentDownloadsAsync());
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetCurrentDownloadsForGroupAsync(abi_arg_in<hstring> group, abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::Networking::BackgroundTransfer::DownloadOperation>>> operation) noexcept override
    {
        try
        {
            *operation = detach(shim().GetCurrentDownloadsAsync(*reinterpret_cast<const hstring *>(&group)));
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Networking::BackgroundTransfer::IBackgroundDownloaderStaticMethods2> : produce_base<D, Windows::Networking::BackgroundTransfer::IBackgroundDownloaderStaticMethods2>
{
    HRESULT __stdcall abi_GetCurrentDownloadsForTransferGroupAsync(abi_arg_in<Windows::Networking::BackgroundTransfer::IBackgroundTransferGroup> group, abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::Networking::BackgroundTransfer::DownloadOperation>>> operation) noexcept override
    {
        try
        {
            *operation = detach(shim().GetCurrentDownloadsForTransferGroupAsync(*reinterpret_cast<const Windows::Networking::BackgroundTransfer::BackgroundTransferGroup *>(&group)));
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Networking::BackgroundTransfer::IBackgroundDownloaderUserConsent> : produce_base<D, Windows::Networking::BackgroundTransfer::IBackgroundDownloaderUserConsent>
{
    HRESULT __stdcall abi_RequestUnconstrainedDownloadsAsync(abi_arg_in<Windows::Foundation::Collections::IIterable<Windows::Networking::BackgroundTransfer::DownloadOperation>> operations, abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Networking::BackgroundTransfer::UnconstrainedTransferRequestResult>> operation) noexcept override
    {
        try
        {
            *operation = detach(shim().RequestUnconstrainedDownloadsAsync(*reinterpret_cast<const Windows::Foundation::Collections::IIterable<Windows::Networking::BackgroundTransfer::DownloadOperation> *>(&operations)));
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Networking::BackgroundTransfer::IBackgroundTransferBase> : produce_base<D, Windows::Networking::BackgroundTransfer::IBackgroundTransferBase>
{
    HRESULT __stdcall abi_SetRequestHeader(abi_arg_in<hstring> headerName, abi_arg_in<hstring> headerValue) noexcept override
    {
        try
        {
            shim().SetRequestHeader(*reinterpret_cast<const hstring *>(&headerName), *reinterpret_cast<const hstring *>(&headerValue));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ServerCredential(abi_arg_out<Windows::Security::Credentials::IPasswordCredential> credential) noexcept override
    {
        try
        {
            *credential = detach(shim().ServerCredential());
            return S_OK;
        }
        catch (...)
        {
            *credential = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_ServerCredential(abi_arg_in<Windows::Security::Credentials::IPasswordCredential> credential) noexcept override
    {
        try
        {
            shim().ServerCredential(*reinterpret_cast<const Windows::Security::Credentials::PasswordCredential *>(&credential));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ProxyCredential(abi_arg_out<Windows::Security::Credentials::IPasswordCredential> credential) noexcept override
    {
        try
        {
            *credential = detach(shim().ProxyCredential());
            return S_OK;
        }
        catch (...)
        {
            *credential = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_ProxyCredential(abi_arg_in<Windows::Security::Credentials::IPasswordCredential> credential) noexcept override
    {
        try
        {
            shim().ProxyCredential(*reinterpret_cast<const Windows::Security::Credentials::PasswordCredential *>(&credential));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Method(abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            *value = detach(shim().Method());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Method(abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            shim().Method(*reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Group(abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            *value = detach(shim().Group());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Group(abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            shim().Group(*reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_CostPolicy(Windows::Networking::BackgroundTransfer::BackgroundTransferCostPolicy * value) noexcept override
    {
        try
        {
            *value = detach(shim().CostPolicy());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_CostPolicy(Windows::Networking::BackgroundTransfer::BackgroundTransferCostPolicy value) noexcept override
    {
        try
        {
            shim().CostPolicy(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Networking::BackgroundTransfer::IBackgroundTransferCompletionGroup> : produce_base<D, Windows::Networking::BackgroundTransfer::IBackgroundTransferCompletionGroup>
{
    HRESULT __stdcall get_Trigger(abi_arg_out<Windows::ApplicationModel::Background::IBackgroundTrigger> value) noexcept override
    {
        try
        {
            *value = detach(shim().Trigger());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_IsEnabled(bool * value) noexcept override
    {
        try
        {
            *value = detach(shim().IsEnabled());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_Enable() noexcept override
    {
        try
        {
            shim().Enable();
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Networking::BackgroundTransfer::IBackgroundTransferCompletionGroupTriggerDetails> : produce_base<D, Windows::Networking::BackgroundTransfer::IBackgroundTransferCompletionGroupTriggerDetails>
{
    HRESULT __stdcall get_Downloads(abi_arg_out<Windows::Foundation::Collections::IVectorView<Windows::Networking::BackgroundTransfer::DownloadOperation>> value) noexcept override
    {
        try
        {
            *value = detach(shim().Downloads());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Uploads(abi_arg_out<Windows::Foundation::Collections::IVectorView<Windows::Networking::BackgroundTransfer::UploadOperation>> value) noexcept override
    {
        try
        {
            *value = detach(shim().Uploads());
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
struct produce<D, Windows::Networking::BackgroundTransfer::IBackgroundTransferContentPart> : produce_base<D, Windows::Networking::BackgroundTransfer::IBackgroundTransferContentPart>
{
    HRESULT __stdcall abi_SetHeader(abi_arg_in<hstring> headerName, abi_arg_in<hstring> headerValue) noexcept override
    {
        try
        {
            shim().SetHeader(*reinterpret_cast<const hstring *>(&headerName), *reinterpret_cast<const hstring *>(&headerValue));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_SetText(abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            shim().SetText(*reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_SetFile(abi_arg_in<Windows::Storage::IStorageFile> value) noexcept override
    {
        try
        {
            shim().SetFile(*reinterpret_cast<const Windows::Storage::IStorageFile *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Networking::BackgroundTransfer::IBackgroundTransferContentPartFactory> : produce_base<D, Windows::Networking::BackgroundTransfer::IBackgroundTransferContentPartFactory>
{
    HRESULT __stdcall abi_CreateWithName(abi_arg_in<hstring> name, abi_arg_out<Windows::Networking::BackgroundTransfer::IBackgroundTransferContentPart> value) noexcept override
    {
        try
        {
            *value = detach(shim().CreateWithName(*reinterpret_cast<const hstring *>(&name)));
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_CreateWithNameAndFileName(abi_arg_in<hstring> name, abi_arg_in<hstring> fileName, abi_arg_out<Windows::Networking::BackgroundTransfer::IBackgroundTransferContentPart> value) noexcept override
    {
        try
        {
            *value = detach(shim().CreateWithNameAndFileName(*reinterpret_cast<const hstring *>(&name), *reinterpret_cast<const hstring *>(&fileName)));
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
struct produce<D, Windows::Networking::BackgroundTransfer::IBackgroundTransferErrorStaticMethods> : produce_base<D, Windows::Networking::BackgroundTransfer::IBackgroundTransferErrorStaticMethods>
{
    HRESULT __stdcall abi_GetStatus(int32_t hresult, Windows::Web::WebErrorStatus * status) noexcept override
    {
        try
        {
            *status = detach(shim().GetStatus(hresult));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Networking::BackgroundTransfer::IBackgroundTransferGroup> : produce_base<D, Windows::Networking::BackgroundTransfer::IBackgroundTransferGroup>
{
    HRESULT __stdcall get_Name(abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            *value = detach(shim().Name());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_TransferBehavior(Windows::Networking::BackgroundTransfer::BackgroundTransferBehavior * value) noexcept override
    {
        try
        {
            *value = detach(shim().TransferBehavior());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_TransferBehavior(Windows::Networking::BackgroundTransfer::BackgroundTransferBehavior value) noexcept override
    {
        try
        {
            shim().TransferBehavior(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Networking::BackgroundTransfer::IBackgroundTransferGroupStatics> : produce_base<D, Windows::Networking::BackgroundTransfer::IBackgroundTransferGroupStatics>
{
    HRESULT __stdcall abi_CreateGroup(abi_arg_in<hstring> name, abi_arg_out<Windows::Networking::BackgroundTransfer::IBackgroundTransferGroup> value) noexcept override
    {
        try
        {
            *value = detach(shim().CreateGroup(*reinterpret_cast<const hstring *>(&name)));
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
struct produce<D, Windows::Networking::BackgroundTransfer::IBackgroundTransferOperation> : produce_base<D, Windows::Networking::BackgroundTransfer::IBackgroundTransferOperation>
{
    HRESULT __stdcall get_Guid(GUID * value) noexcept override
    {
        try
        {
            *value = detach(shim().Guid());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_RequestedUri(abi_arg_out<Windows::Foundation::IUriRuntimeClass> value) noexcept override
    {
        try
        {
            *value = detach(shim().RequestedUri());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Method(abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            *value = detach(shim().Method());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Group(abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            *value = detach(shim().Group());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_CostPolicy(Windows::Networking::BackgroundTransfer::BackgroundTransferCostPolicy * value) noexcept override
    {
        try
        {
            *value = detach(shim().CostPolicy());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_CostPolicy(Windows::Networking::BackgroundTransfer::BackgroundTransferCostPolicy value) noexcept override
    {
        try
        {
            shim().CostPolicy(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetResultStreamAt(uint64_t position, abi_arg_out<Windows::Storage::Streams::IInputStream> value) noexcept override
    {
        try
        {
            *value = detach(shim().GetResultStreamAt(position));
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetResponseInformation(abi_arg_out<Windows::Networking::BackgroundTransfer::IResponseInformation> value) noexcept override
    {
        try
        {
            *value = detach(shim().GetResponseInformation());
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
struct produce<D, Windows::Networking::BackgroundTransfer::IBackgroundTransferOperationPriority> : produce_base<D, Windows::Networking::BackgroundTransfer::IBackgroundTransferOperationPriority>
{
    HRESULT __stdcall get_Priority(Windows::Networking::BackgroundTransfer::BackgroundTransferPriority * value) noexcept override
    {
        try
        {
            *value = detach(shim().Priority());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Priority(Windows::Networking::BackgroundTransfer::BackgroundTransferPriority value) noexcept override
    {
        try
        {
            shim().Priority(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Networking::BackgroundTransfer::IBackgroundUploader> : produce_base<D, Windows::Networking::BackgroundTransfer::IBackgroundUploader>
{
    HRESULT __stdcall abi_CreateUpload(abi_arg_in<Windows::Foundation::IUriRuntimeClass> uri, abi_arg_in<Windows::Storage::IStorageFile> sourceFile, abi_arg_out<Windows::Networking::BackgroundTransfer::IUploadOperation> operation) noexcept override
    {
        try
        {
            *operation = detach(shim().CreateUpload(*reinterpret_cast<const Windows::Foundation::Uri *>(&uri), *reinterpret_cast<const Windows::Storage::IStorageFile *>(&sourceFile)));
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_CreateUploadFromStreamAsync(abi_arg_in<Windows::Foundation::IUriRuntimeClass> uri, abi_arg_in<Windows::Storage::Streams::IInputStream> sourceStream, abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Networking::BackgroundTransfer::UploadOperation>> operation) noexcept override
    {
        try
        {
            *operation = detach(shim().CreateUploadFromStreamAsync(*reinterpret_cast<const Windows::Foundation::Uri *>(&uri), *reinterpret_cast<const Windows::Storage::Streams::IInputStream *>(&sourceStream)));
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_CreateUploadWithFormDataAndAutoBoundaryAsync(abi_arg_in<Windows::Foundation::IUriRuntimeClass> uri, abi_arg_in<Windows::Foundation::Collections::IIterable<Windows::Networking::BackgroundTransfer::BackgroundTransferContentPart>> parts, abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Networking::BackgroundTransfer::UploadOperation>> operation) noexcept override
    {
        try
        {
            *operation = detach(shim().CreateUploadAsync(*reinterpret_cast<const Windows::Foundation::Uri *>(&uri), *reinterpret_cast<const Windows::Foundation::Collections::IIterable<Windows::Networking::BackgroundTransfer::BackgroundTransferContentPart> *>(&parts)));
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_CreateUploadWithSubTypeAsync(abi_arg_in<Windows::Foundation::IUriRuntimeClass> uri, abi_arg_in<Windows::Foundation::Collections::IIterable<Windows::Networking::BackgroundTransfer::BackgroundTransferContentPart>> parts, abi_arg_in<hstring> subType, abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Networking::BackgroundTransfer::UploadOperation>> operation) noexcept override
    {
        try
        {
            *operation = detach(shim().CreateUploadAsync(*reinterpret_cast<const Windows::Foundation::Uri *>(&uri), *reinterpret_cast<const Windows::Foundation::Collections::IIterable<Windows::Networking::BackgroundTransfer::BackgroundTransferContentPart> *>(&parts), *reinterpret_cast<const hstring *>(&subType)));
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_CreateUploadWithSubTypeAndBoundaryAsync(abi_arg_in<Windows::Foundation::IUriRuntimeClass> uri, abi_arg_in<Windows::Foundation::Collections::IIterable<Windows::Networking::BackgroundTransfer::BackgroundTransferContentPart>> parts, abi_arg_in<hstring> subType, abi_arg_in<hstring> boundary, abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Networking::BackgroundTransfer::UploadOperation>> operation) noexcept override
    {
        try
        {
            *operation = detach(shim().CreateUploadAsync(*reinterpret_cast<const Windows::Foundation::Uri *>(&uri), *reinterpret_cast<const Windows::Foundation::Collections::IIterable<Windows::Networking::BackgroundTransfer::BackgroundTransferContentPart> *>(&parts), *reinterpret_cast<const hstring *>(&subType), *reinterpret_cast<const hstring *>(&boundary)));
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Networking::BackgroundTransfer::IBackgroundUploader2> : produce_base<D, Windows::Networking::BackgroundTransfer::IBackgroundUploader2>
{
    HRESULT __stdcall get_TransferGroup(abi_arg_out<Windows::Networking::BackgroundTransfer::IBackgroundTransferGroup> value) noexcept override
    {
        try
        {
            *value = detach(shim().TransferGroup());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_TransferGroup(abi_arg_in<Windows::Networking::BackgroundTransfer::IBackgroundTransferGroup> value) noexcept override
    {
        try
        {
            shim().TransferGroup(*reinterpret_cast<const Windows::Networking::BackgroundTransfer::BackgroundTransferGroup *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_SuccessToastNotification(abi_arg_out<Windows::UI::Notifications::IToastNotification> value) noexcept override
    {
        try
        {
            *value = detach(shim().SuccessToastNotification());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_SuccessToastNotification(abi_arg_in<Windows::UI::Notifications::IToastNotification> value) noexcept override
    {
        try
        {
            shim().SuccessToastNotification(*reinterpret_cast<const Windows::UI::Notifications::ToastNotification *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_FailureToastNotification(abi_arg_out<Windows::UI::Notifications::IToastNotification> value) noexcept override
    {
        try
        {
            *value = detach(shim().FailureToastNotification());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_FailureToastNotification(abi_arg_in<Windows::UI::Notifications::IToastNotification> value) noexcept override
    {
        try
        {
            shim().FailureToastNotification(*reinterpret_cast<const Windows::UI::Notifications::ToastNotification *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_SuccessTileNotification(abi_arg_out<Windows::UI::Notifications::ITileNotification> value) noexcept override
    {
        try
        {
            *value = detach(shim().SuccessTileNotification());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_SuccessTileNotification(abi_arg_in<Windows::UI::Notifications::ITileNotification> value) noexcept override
    {
        try
        {
            shim().SuccessTileNotification(*reinterpret_cast<const Windows::UI::Notifications::TileNotification *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_FailureTileNotification(abi_arg_out<Windows::UI::Notifications::ITileNotification> value) noexcept override
    {
        try
        {
            *value = detach(shim().FailureTileNotification());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_FailureTileNotification(abi_arg_in<Windows::UI::Notifications::ITileNotification> value) noexcept override
    {
        try
        {
            shim().FailureTileNotification(*reinterpret_cast<const Windows::UI::Notifications::TileNotification *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Networking::BackgroundTransfer::IBackgroundUploader3> : produce_base<D, Windows::Networking::BackgroundTransfer::IBackgroundUploader3>
{
    HRESULT __stdcall get_CompletionGroup(abi_arg_out<Windows::Networking::BackgroundTransfer::IBackgroundTransferCompletionGroup> value) noexcept override
    {
        try
        {
            *value = detach(shim().CompletionGroup());
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
struct produce<D, Windows::Networking::BackgroundTransfer::IBackgroundUploaderFactory> : produce_base<D, Windows::Networking::BackgroundTransfer::IBackgroundUploaderFactory>
{
    HRESULT __stdcall abi_CreateWithCompletionGroup(abi_arg_in<Windows::Networking::BackgroundTransfer::IBackgroundTransferCompletionGroup> completionGroup, abi_arg_out<Windows::Networking::BackgroundTransfer::IBackgroundUploader> backgroundUploader) noexcept override
    {
        try
        {
            *backgroundUploader = detach(shim().CreateWithCompletionGroup(*reinterpret_cast<const Windows::Networking::BackgroundTransfer::BackgroundTransferCompletionGroup *>(&completionGroup)));
            return S_OK;
        }
        catch (...)
        {
            *backgroundUploader = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Networking::BackgroundTransfer::IBackgroundUploaderStaticMethods> : produce_base<D, Windows::Networking::BackgroundTransfer::IBackgroundUploaderStaticMethods>
{
    HRESULT __stdcall abi_GetCurrentUploadsAsync(abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::Networking::BackgroundTransfer::UploadOperation>>> operation) noexcept override
    {
        try
        {
            *operation = detach(shim().GetCurrentUploadsAsync());
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetCurrentUploadsForGroupAsync(abi_arg_in<hstring> group, abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::Networking::BackgroundTransfer::UploadOperation>>> operation) noexcept override
    {
        try
        {
            *operation = detach(shim().GetCurrentUploadsAsync(*reinterpret_cast<const hstring *>(&group)));
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Networking::BackgroundTransfer::IBackgroundUploaderStaticMethods2> : produce_base<D, Windows::Networking::BackgroundTransfer::IBackgroundUploaderStaticMethods2>
{
    HRESULT __stdcall abi_GetCurrentUploadsForTransferGroupAsync(abi_arg_in<Windows::Networking::BackgroundTransfer::IBackgroundTransferGroup> group, abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::Networking::BackgroundTransfer::UploadOperation>>> operation) noexcept override
    {
        try
        {
            *operation = detach(shim().GetCurrentUploadsForTransferGroupAsync(*reinterpret_cast<const Windows::Networking::BackgroundTransfer::BackgroundTransferGroup *>(&group)));
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Networking::BackgroundTransfer::IBackgroundUploaderUserConsent> : produce_base<D, Windows::Networking::BackgroundTransfer::IBackgroundUploaderUserConsent>
{
    HRESULT __stdcall abi_RequestUnconstrainedUploadsAsync(abi_arg_in<Windows::Foundation::Collections::IIterable<Windows::Networking::BackgroundTransfer::UploadOperation>> operations, abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Networking::BackgroundTransfer::UnconstrainedTransferRequestResult>> operation) noexcept override
    {
        try
        {
            *operation = detach(shim().RequestUnconstrainedUploadsAsync(*reinterpret_cast<const Windows::Foundation::Collections::IIterable<Windows::Networking::BackgroundTransfer::UploadOperation> *>(&operations)));
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Networking::BackgroundTransfer::IContentPrefetcher> : produce_base<D, Windows::Networking::BackgroundTransfer::IContentPrefetcher>
{
    HRESULT __stdcall get_ContentUris(abi_arg_out<Windows::Foundation::Collections::IVector<Windows::Foundation::Uri>> value) noexcept override
    {
        try
        {
            *value = detach(shim().ContentUris());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_IndirectContentUri(abi_arg_in<Windows::Foundation::IUriRuntimeClass> value) noexcept override
    {
        try
        {
            shim().IndirectContentUri(*reinterpret_cast<const Windows::Foundation::Uri *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_IndirectContentUri(abi_arg_out<Windows::Foundation::IUriRuntimeClass> value) noexcept override
    {
        try
        {
            *value = detach(shim().IndirectContentUri());
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
struct produce<D, Windows::Networking::BackgroundTransfer::IContentPrefetcherTime> : produce_base<D, Windows::Networking::BackgroundTransfer::IContentPrefetcherTime>
{
    HRESULT __stdcall get_LastSuccessfulPrefetchTime(abi_arg_out<Windows::Foundation::IReference<Windows::Foundation::DateTime>> value) noexcept override
    {
        try
        {
            *value = detach(shim().LastSuccessfulPrefetchTime());
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
struct produce<D, Windows::Networking::BackgroundTransfer::IDownloadOperation> : produce_base<D, Windows::Networking::BackgroundTransfer::IDownloadOperation>
{
    HRESULT __stdcall get_ResultFile(abi_arg_out<Windows::Storage::IStorageFile> value) noexcept override
    {
        try
        {
            *value = detach(shim().ResultFile());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Progress(abi_arg_out<Windows::Networking::BackgroundTransfer::BackgroundDownloadProgress> value) noexcept override
    {
        try
        {
            *value = detach(shim().Progress());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_StartAsync(abi_arg_out<Windows::Foundation::IAsyncOperationWithProgress<Windows::Networking::BackgroundTransfer::DownloadOperation, Windows::Networking::BackgroundTransfer::DownloadOperation>> operation) noexcept override
    {
        try
        {
            *operation = detach(shim().StartAsync());
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_AttachAsync(abi_arg_out<Windows::Foundation::IAsyncOperationWithProgress<Windows::Networking::BackgroundTransfer::DownloadOperation, Windows::Networking::BackgroundTransfer::DownloadOperation>> operation) noexcept override
    {
        try
        {
            *operation = detach(shim().AttachAsync());
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_Pause() noexcept override
    {
        try
        {
            shim().Pause();
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_Resume() noexcept override
    {
        try
        {
            shim().Resume();
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Networking::BackgroundTransfer::IDownloadOperation2> : produce_base<D, Windows::Networking::BackgroundTransfer::IDownloadOperation2>
{
    HRESULT __stdcall get_TransferGroup(abi_arg_out<Windows::Networking::BackgroundTransfer::IBackgroundTransferGroup> value) noexcept override
    {
        try
        {
            *value = detach(shim().TransferGroup());
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
struct produce<D, Windows::Networking::BackgroundTransfer::IResponseInformation> : produce_base<D, Windows::Networking::BackgroundTransfer::IResponseInformation>
{
    HRESULT __stdcall get_IsResumable(bool * value) noexcept override
    {
        try
        {
            *value = detach(shim().IsResumable());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ActualUri(abi_arg_out<Windows::Foundation::IUriRuntimeClass> value) noexcept override
    {
        try
        {
            *value = detach(shim().ActualUri());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_StatusCode(uint32_t * value) noexcept override
    {
        try
        {
            *value = detach(shim().StatusCode());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Headers(abi_arg_out<Windows::Foundation::Collections::IMapView<hstring, hstring>> value) noexcept override
    {
        try
        {
            *value = detach(shim().Headers());
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
struct produce<D, Windows::Networking::BackgroundTransfer::IUnconstrainedTransferRequestResult> : produce_base<D, Windows::Networking::BackgroundTransfer::IUnconstrainedTransferRequestResult>
{
    HRESULT __stdcall get_IsUnconstrained(bool * value) noexcept override
    {
        try
        {
            *value = detach(shim().IsUnconstrained());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Networking::BackgroundTransfer::IUploadOperation> : produce_base<D, Windows::Networking::BackgroundTransfer::IUploadOperation>
{
    HRESULT __stdcall get_SourceFile(abi_arg_out<Windows::Storage::IStorageFile> value) noexcept override
    {
        try
        {
            *value = detach(shim().SourceFile());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Progress(abi_arg_out<Windows::Networking::BackgroundTransfer::BackgroundUploadProgress> value) noexcept override
    {
        try
        {
            *value = detach(shim().Progress());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_StartAsync(abi_arg_out<Windows::Foundation::IAsyncOperationWithProgress<Windows::Networking::BackgroundTransfer::UploadOperation, Windows::Networking::BackgroundTransfer::UploadOperation>> operation) noexcept override
    {
        try
        {
            *operation = detach(shim().StartAsync());
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_AttachAsync(abi_arg_out<Windows::Foundation::IAsyncOperationWithProgress<Windows::Networking::BackgroundTransfer::UploadOperation, Windows::Networking::BackgroundTransfer::UploadOperation>> operation) noexcept override
    {
        try
        {
            *operation = detach(shim().AttachAsync());
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Networking::BackgroundTransfer::IUploadOperation2> : produce_base<D, Windows::Networking::BackgroundTransfer::IUploadOperation2>
{
    HRESULT __stdcall get_TransferGroup(abi_arg_out<Windows::Networking::BackgroundTransfer::IBackgroundTransferGroup> value) noexcept override
    {
        try
        {
            *value = detach(shim().TransferGroup());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }
};

}

namespace Windows::Networking::BackgroundTransfer {

template <typename D> void impl_IBackgroundTransferBase<D>::SetRequestHeader(hstring_ref headerName, hstring_ref headerValue) const
{
    check_hresult(shim()->abi_SetRequestHeader(get(headerName), get(headerValue)));
}

template <typename D> Windows::Security::Credentials::PasswordCredential impl_IBackgroundTransferBase<D>::ServerCredential() const
{
    Windows::Security::Credentials::PasswordCredential credential { nullptr };
    check_hresult(shim()->get_ServerCredential(put(credential)));
    return credential;
}

template <typename D> void impl_IBackgroundTransferBase<D>::ServerCredential(const Windows::Security::Credentials::PasswordCredential & credential) const
{
    check_hresult(shim()->put_ServerCredential(get(credential)));
}

template <typename D> Windows::Security::Credentials::PasswordCredential impl_IBackgroundTransferBase<D>::ProxyCredential() const
{
    Windows::Security::Credentials::PasswordCredential credential { nullptr };
    check_hresult(shim()->get_ProxyCredential(put(credential)));
    return credential;
}

template <typename D> void impl_IBackgroundTransferBase<D>::ProxyCredential(const Windows::Security::Credentials::PasswordCredential & credential) const
{
    check_hresult(shim()->put_ProxyCredential(get(credential)));
}

template <typename D> hstring impl_IBackgroundTransferBase<D>::Method() const
{
    hstring value;
    check_hresult(shim()->get_Method(put(value)));
    return value;
}

template <typename D> void impl_IBackgroundTransferBase<D>::Method(hstring_ref value) const
{
    check_hresult(shim()->put_Method(get(value)));
}

template <typename D> hstring impl_IBackgroundTransferBase<D>::Group() const
{
    hstring value;
    check_hresult(shim()->get_Group(put(value)));
    return value;
}

template <typename D> void impl_IBackgroundTransferBase<D>::Group(hstring_ref value) const
{
    check_hresult(shim()->put_Group(get(value)));
}

template <typename D> Windows::Networking::BackgroundTransfer::BackgroundTransferCostPolicy impl_IBackgroundTransferBase<D>::CostPolicy() const
{
    Windows::Networking::BackgroundTransfer::BackgroundTransferCostPolicy value {};
    check_hresult(shim()->get_CostPolicy(&value));
    return value;
}

template <typename D> void impl_IBackgroundTransferBase<D>::CostPolicy(Windows::Networking::BackgroundTransfer::BackgroundTransferCostPolicy value) const
{
    check_hresult(shim()->put_CostPolicy(value));
}

template <typename D> bool impl_IUnconstrainedTransferRequestResult<D>::IsUnconstrained() const
{
    bool value {};
    check_hresult(shim()->get_IsUnconstrained(&value));
    return value;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Networking::BackgroundTransfer::UnconstrainedTransferRequestResult> impl_IBackgroundDownloaderUserConsent<D>::RequestUnconstrainedDownloadsAsync(const Windows::Foundation::Collections::IIterable<Windows::Networking::BackgroundTransfer::DownloadOperation> & operations) const
{
    Windows::Foundation::IAsyncOperation<Windows::Networking::BackgroundTransfer::UnconstrainedTransferRequestResult> operation;
    check_hresult(shim()->abi_RequestUnconstrainedDownloadsAsync(get(operations), put(operation)));
    return operation;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Networking::BackgroundTransfer::UnconstrainedTransferRequestResult> impl_IBackgroundUploaderUserConsent<D>::RequestUnconstrainedUploadsAsync(const Windows::Foundation::Collections::IIterable<Windows::Networking::BackgroundTransfer::UploadOperation> & operations) const
{
    Windows::Foundation::IAsyncOperation<Windows::Networking::BackgroundTransfer::UnconstrainedTransferRequestResult> operation;
    check_hresult(shim()->abi_RequestUnconstrainedUploadsAsync(get(operations), put(operation)));
    return operation;
}

template <typename D> Windows::Networking::BackgroundTransfer::DownloadOperation impl_IBackgroundDownloader<D>::CreateDownload(const Windows::Foundation::Uri & uri, const Windows::Storage::IStorageFile & resultFile) const
{
    Windows::Networking::BackgroundTransfer::DownloadOperation operation { nullptr };
    check_hresult(shim()->abi_CreateDownload(get(uri), get(resultFile), put(operation)));
    return operation;
}

template <typename D> Windows::Networking::BackgroundTransfer::DownloadOperation impl_IBackgroundDownloader<D>::CreateDownload(const Windows::Foundation::Uri & uri, const Windows::Storage::IStorageFile & resultFile, const Windows::Storage::IStorageFile & requestBodyFile) const
{
    Windows::Networking::BackgroundTransfer::DownloadOperation operation { nullptr };
    check_hresult(shim()->abi_CreateDownloadFromFile(get(uri), get(resultFile), get(requestBodyFile), put(operation)));
    return operation;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Networking::BackgroundTransfer::DownloadOperation> impl_IBackgroundDownloader<D>::CreateDownloadAsync(const Windows::Foundation::Uri & uri, const Windows::Storage::IStorageFile & resultFile, const Windows::Storage::Streams::IInputStream & requestBodyStream) const
{
    Windows::Foundation::IAsyncOperation<Windows::Networking::BackgroundTransfer::DownloadOperation> operation;
    check_hresult(shim()->abi_CreateDownloadAsync(get(uri), get(resultFile), get(requestBodyStream), put(operation)));
    return operation;
}

template <typename D> Windows::Networking::BackgroundTransfer::BackgroundTransferGroup impl_IBackgroundDownloader2<D>::TransferGroup() const
{
    Windows::Networking::BackgroundTransfer::BackgroundTransferGroup value { nullptr };
    check_hresult(shim()->get_TransferGroup(put(value)));
    return value;
}

template <typename D> void impl_IBackgroundDownloader2<D>::TransferGroup(const Windows::Networking::BackgroundTransfer::BackgroundTransferGroup & value) const
{
    check_hresult(shim()->put_TransferGroup(get(value)));
}

template <typename D> Windows::UI::Notifications::ToastNotification impl_IBackgroundDownloader2<D>::SuccessToastNotification() const
{
    Windows::UI::Notifications::ToastNotification value { nullptr };
    check_hresult(shim()->get_SuccessToastNotification(put(value)));
    return value;
}

template <typename D> void impl_IBackgroundDownloader2<D>::SuccessToastNotification(const Windows::UI::Notifications::ToastNotification & value) const
{
    check_hresult(shim()->put_SuccessToastNotification(get(value)));
}

template <typename D> Windows::UI::Notifications::ToastNotification impl_IBackgroundDownloader2<D>::FailureToastNotification() const
{
    Windows::UI::Notifications::ToastNotification value { nullptr };
    check_hresult(shim()->get_FailureToastNotification(put(value)));
    return value;
}

template <typename D> void impl_IBackgroundDownloader2<D>::FailureToastNotification(const Windows::UI::Notifications::ToastNotification & value) const
{
    check_hresult(shim()->put_FailureToastNotification(get(value)));
}

template <typename D> Windows::UI::Notifications::TileNotification impl_IBackgroundDownloader2<D>::SuccessTileNotification() const
{
    Windows::UI::Notifications::TileNotification value { nullptr };
    check_hresult(shim()->get_SuccessTileNotification(put(value)));
    return value;
}

template <typename D> void impl_IBackgroundDownloader2<D>::SuccessTileNotification(const Windows::UI::Notifications::TileNotification & value) const
{
    check_hresult(shim()->put_SuccessTileNotification(get(value)));
}

template <typename D> Windows::UI::Notifications::TileNotification impl_IBackgroundDownloader2<D>::FailureTileNotification() const
{
    Windows::UI::Notifications::TileNotification value { nullptr };
    check_hresult(shim()->get_FailureTileNotification(put(value)));
    return value;
}

template <typename D> void impl_IBackgroundDownloader2<D>::FailureTileNotification(const Windows::UI::Notifications::TileNotification & value) const
{
    check_hresult(shim()->put_FailureTileNotification(get(value)));
}

template <typename D> Windows::Networking::BackgroundTransfer::BackgroundTransferCompletionGroup impl_IBackgroundDownloader3<D>::CompletionGroup() const
{
    Windows::Networking::BackgroundTransfer::BackgroundTransferCompletionGroup value { nullptr };
    check_hresult(shim()->get_CompletionGroup(put(value)));
    return value;
}

template <typename D> Windows::Networking::BackgroundTransfer::UploadOperation impl_IBackgroundUploader<D>::CreateUpload(const Windows::Foundation::Uri & uri, const Windows::Storage::IStorageFile & sourceFile) const
{
    Windows::Networking::BackgroundTransfer::UploadOperation operation { nullptr };
    check_hresult(shim()->abi_CreateUpload(get(uri), get(sourceFile), put(operation)));
    return operation;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Networking::BackgroundTransfer::UploadOperation> impl_IBackgroundUploader<D>::CreateUploadFromStreamAsync(const Windows::Foundation::Uri & uri, const Windows::Storage::Streams::IInputStream & sourceStream) const
{
    Windows::Foundation::IAsyncOperation<Windows::Networking::BackgroundTransfer::UploadOperation> operation;
    check_hresult(shim()->abi_CreateUploadFromStreamAsync(get(uri), get(sourceStream), put(operation)));
    return operation;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Networking::BackgroundTransfer::UploadOperation> impl_IBackgroundUploader<D>::CreateUploadAsync(const Windows::Foundation::Uri & uri, const Windows::Foundation::Collections::IIterable<Windows::Networking::BackgroundTransfer::BackgroundTransferContentPart> & parts) const
{
    Windows::Foundation::IAsyncOperation<Windows::Networking::BackgroundTransfer::UploadOperation> operation;
    check_hresult(shim()->abi_CreateUploadWithFormDataAndAutoBoundaryAsync(get(uri), get(parts), put(operation)));
    return operation;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Networking::BackgroundTransfer::UploadOperation> impl_IBackgroundUploader<D>::CreateUploadAsync(const Windows::Foundation::Uri & uri, const Windows::Foundation::Collections::IIterable<Windows::Networking::BackgroundTransfer::BackgroundTransferContentPart> & parts, hstring_ref subType) const
{
    Windows::Foundation::IAsyncOperation<Windows::Networking::BackgroundTransfer::UploadOperation> operation;
    check_hresult(shim()->abi_CreateUploadWithSubTypeAsync(get(uri), get(parts), get(subType), put(operation)));
    return operation;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Networking::BackgroundTransfer::UploadOperation> impl_IBackgroundUploader<D>::CreateUploadAsync(const Windows::Foundation::Uri & uri, const Windows::Foundation::Collections::IIterable<Windows::Networking::BackgroundTransfer::BackgroundTransferContentPart> & parts, hstring_ref subType, hstring_ref boundary) const
{
    Windows::Foundation::IAsyncOperation<Windows::Networking::BackgroundTransfer::UploadOperation> operation;
    check_hresult(shim()->abi_CreateUploadWithSubTypeAndBoundaryAsync(get(uri), get(parts), get(subType), get(boundary), put(operation)));
    return operation;
}

template <typename D> Windows::Networking::BackgroundTransfer::BackgroundTransferGroup impl_IBackgroundUploader2<D>::TransferGroup() const
{
    Windows::Networking::BackgroundTransfer::BackgroundTransferGroup value { nullptr };
    check_hresult(shim()->get_TransferGroup(put(value)));
    return value;
}

template <typename D> void impl_IBackgroundUploader2<D>::TransferGroup(const Windows::Networking::BackgroundTransfer::BackgroundTransferGroup & value) const
{
    check_hresult(shim()->put_TransferGroup(get(value)));
}

template <typename D> Windows::UI::Notifications::ToastNotification impl_IBackgroundUploader2<D>::SuccessToastNotification() const
{
    Windows::UI::Notifications::ToastNotification value { nullptr };
    check_hresult(shim()->get_SuccessToastNotification(put(value)));
    return value;
}

template <typename D> void impl_IBackgroundUploader2<D>::SuccessToastNotification(const Windows::UI::Notifications::ToastNotification & value) const
{
    check_hresult(shim()->put_SuccessToastNotification(get(value)));
}

template <typename D> Windows::UI::Notifications::ToastNotification impl_IBackgroundUploader2<D>::FailureToastNotification() const
{
    Windows::UI::Notifications::ToastNotification value { nullptr };
    check_hresult(shim()->get_FailureToastNotification(put(value)));
    return value;
}

template <typename D> void impl_IBackgroundUploader2<D>::FailureToastNotification(const Windows::UI::Notifications::ToastNotification & value) const
{
    check_hresult(shim()->put_FailureToastNotification(get(value)));
}

template <typename D> Windows::UI::Notifications::TileNotification impl_IBackgroundUploader2<D>::SuccessTileNotification() const
{
    Windows::UI::Notifications::TileNotification value { nullptr };
    check_hresult(shim()->get_SuccessTileNotification(put(value)));
    return value;
}

template <typename D> void impl_IBackgroundUploader2<D>::SuccessTileNotification(const Windows::UI::Notifications::TileNotification & value) const
{
    check_hresult(shim()->put_SuccessTileNotification(get(value)));
}

template <typename D> Windows::UI::Notifications::TileNotification impl_IBackgroundUploader2<D>::FailureTileNotification() const
{
    Windows::UI::Notifications::TileNotification value { nullptr };
    check_hresult(shim()->get_FailureTileNotification(put(value)));
    return value;
}

template <typename D> void impl_IBackgroundUploader2<D>::FailureTileNotification(const Windows::UI::Notifications::TileNotification & value) const
{
    check_hresult(shim()->put_FailureTileNotification(get(value)));
}

template <typename D> Windows::Networking::BackgroundTransfer::BackgroundTransferCompletionGroup impl_IBackgroundUploader3<D>::CompletionGroup() const
{
    Windows::Networking::BackgroundTransfer::BackgroundTransferCompletionGroup value { nullptr };
    check_hresult(shim()->get_CompletionGroup(put(value)));
    return value;
}

template <typename D> GUID impl_IBackgroundTransferOperation<D>::Guid() const
{
    GUID value {};
    check_hresult(shim()->get_Guid(&value));
    return value;
}

template <typename D> Windows::Foundation::Uri impl_IBackgroundTransferOperation<D>::RequestedUri() const
{
    Windows::Foundation::Uri value { nullptr };
    check_hresult(shim()->get_RequestedUri(put(value)));
    return value;
}

template <typename D> hstring impl_IBackgroundTransferOperation<D>::Method() const
{
    hstring value;
    check_hresult(shim()->get_Method(put(value)));
    return value;
}

template <typename D> hstring impl_IBackgroundTransferOperation<D>::Group() const
{
    hstring value;
    check_hresult(shim()->get_Group(put(value)));
    return value;
}

template <typename D> Windows::Networking::BackgroundTransfer::BackgroundTransferCostPolicy impl_IBackgroundTransferOperation<D>::CostPolicy() const
{
    Windows::Networking::BackgroundTransfer::BackgroundTransferCostPolicy value {};
    check_hresult(shim()->get_CostPolicy(&value));
    return value;
}

template <typename D> void impl_IBackgroundTransferOperation<D>::CostPolicy(Windows::Networking::BackgroundTransfer::BackgroundTransferCostPolicy value) const
{
    check_hresult(shim()->put_CostPolicy(value));
}

template <typename D> Windows::Storage::Streams::IInputStream impl_IBackgroundTransferOperation<D>::GetResultStreamAt(uint64_t position) const
{
    Windows::Storage::Streams::IInputStream value;
    check_hresult(shim()->abi_GetResultStreamAt(position, put(value)));
    return value;
}

template <typename D> Windows::Networking::BackgroundTransfer::ResponseInformation impl_IBackgroundTransferOperation<D>::GetResponseInformation() const
{
    Windows::Networking::BackgroundTransfer::ResponseInformation value { nullptr };
    check_hresult(shim()->abi_GetResponseInformation(put(value)));
    return value;
}

template <typename D> Windows::Networking::BackgroundTransfer::BackgroundTransferPriority impl_IBackgroundTransferOperationPriority<D>::Priority() const
{
    Windows::Networking::BackgroundTransfer::BackgroundTransferPriority value {};
    check_hresult(shim()->get_Priority(&value));
    return value;
}

template <typename D> void impl_IBackgroundTransferOperationPriority<D>::Priority(Windows::Networking::BackgroundTransfer::BackgroundTransferPriority value) const
{
    check_hresult(shim()->put_Priority(value));
}

template <typename D> Windows::Storage::IStorageFile impl_IDownloadOperation<D>::ResultFile() const
{
    Windows::Storage::IStorageFile value;
    check_hresult(shim()->get_ResultFile(put(value)));
    return value;
}

template <typename D> Windows::Networking::BackgroundTransfer::BackgroundDownloadProgress impl_IDownloadOperation<D>::Progress() const
{
    Windows::Networking::BackgroundTransfer::BackgroundDownloadProgress value {};
    check_hresult(shim()->get_Progress(put(value)));
    return value;
}

template <typename D> Windows::Foundation::IAsyncOperationWithProgress<Windows::Networking::BackgroundTransfer::DownloadOperation, Windows::Networking::BackgroundTransfer::DownloadOperation> impl_IDownloadOperation<D>::StartAsync() const
{
    Windows::Foundation::IAsyncOperationWithProgress<Windows::Networking::BackgroundTransfer::DownloadOperation, Windows::Networking::BackgroundTransfer::DownloadOperation> operation;
    check_hresult(shim()->abi_StartAsync(put(operation)));
    return operation;
}

template <typename D> Windows::Foundation::IAsyncOperationWithProgress<Windows::Networking::BackgroundTransfer::DownloadOperation, Windows::Networking::BackgroundTransfer::DownloadOperation> impl_IDownloadOperation<D>::AttachAsync() const
{
    Windows::Foundation::IAsyncOperationWithProgress<Windows::Networking::BackgroundTransfer::DownloadOperation, Windows::Networking::BackgroundTransfer::DownloadOperation> operation;
    check_hresult(shim()->abi_AttachAsync(put(operation)));
    return operation;
}

template <typename D> void impl_IDownloadOperation<D>::Pause() const
{
    check_hresult(shim()->abi_Pause());
}

template <typename D> void impl_IDownloadOperation<D>::Resume() const
{
    check_hresult(shim()->abi_Resume());
}

template <typename D> Windows::Networking::BackgroundTransfer::BackgroundTransferGroup impl_IDownloadOperation2<D>::TransferGroup() const
{
    Windows::Networking::BackgroundTransfer::BackgroundTransferGroup value { nullptr };
    check_hresult(shim()->get_TransferGroup(put(value)));
    return value;
}

template <typename D> Windows::Storage::IStorageFile impl_IUploadOperation<D>::SourceFile() const
{
    Windows::Storage::IStorageFile value;
    check_hresult(shim()->get_SourceFile(put(value)));
    return value;
}

template <typename D> Windows::Networking::BackgroundTransfer::BackgroundUploadProgress impl_IUploadOperation<D>::Progress() const
{
    Windows::Networking::BackgroundTransfer::BackgroundUploadProgress value {};
    check_hresult(shim()->get_Progress(put(value)));
    return value;
}

template <typename D> Windows::Foundation::IAsyncOperationWithProgress<Windows::Networking::BackgroundTransfer::UploadOperation, Windows::Networking::BackgroundTransfer::UploadOperation> impl_IUploadOperation<D>::StartAsync() const
{
    Windows::Foundation::IAsyncOperationWithProgress<Windows::Networking::BackgroundTransfer::UploadOperation, Windows::Networking::BackgroundTransfer::UploadOperation> operation;
    check_hresult(shim()->abi_StartAsync(put(operation)));
    return operation;
}

template <typename D> Windows::Foundation::IAsyncOperationWithProgress<Windows::Networking::BackgroundTransfer::UploadOperation, Windows::Networking::BackgroundTransfer::UploadOperation> impl_IUploadOperation<D>::AttachAsync() const
{
    Windows::Foundation::IAsyncOperationWithProgress<Windows::Networking::BackgroundTransfer::UploadOperation, Windows::Networking::BackgroundTransfer::UploadOperation> operation;
    check_hresult(shim()->abi_AttachAsync(put(operation)));
    return operation;
}

template <typename D> Windows::Networking::BackgroundTransfer::BackgroundTransferGroup impl_IUploadOperation2<D>::TransferGroup() const
{
    Windows::Networking::BackgroundTransfer::BackgroundTransferGroup value { nullptr };
    check_hresult(shim()->get_TransferGroup(put(value)));
    return value;
}

template <typename D> Windows::Networking::BackgroundTransfer::BackgroundDownloader impl_IBackgroundDownloaderFactory<D>::CreateWithCompletionGroup(const Windows::Networking::BackgroundTransfer::BackgroundTransferCompletionGroup & completionGroup) const
{
    Windows::Networking::BackgroundTransfer::BackgroundDownloader backgroundDownloader { nullptr };
    check_hresult(shim()->abi_CreateWithCompletionGroup(get(completionGroup), put(backgroundDownloader)));
    return backgroundDownloader;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::Networking::BackgroundTransfer::DownloadOperation>> impl_IBackgroundDownloaderStaticMethods<D>::GetCurrentDownloadsAsync() const
{
    Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::Networking::BackgroundTransfer::DownloadOperation>> operation;
    check_hresult(shim()->abi_GetCurrentDownloadsAsync(put(operation)));
    return operation;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::Networking::BackgroundTransfer::DownloadOperation>> impl_IBackgroundDownloaderStaticMethods<D>::GetCurrentDownloadsAsync(hstring_ref group) const
{
    Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::Networking::BackgroundTransfer::DownloadOperation>> operation;
    check_hresult(shim()->abi_GetCurrentDownloadsForGroupAsync(get(group), put(operation)));
    return operation;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::Networking::BackgroundTransfer::DownloadOperation>> impl_IBackgroundDownloaderStaticMethods2<D>::GetCurrentDownloadsForTransferGroupAsync(const Windows::Networking::BackgroundTransfer::BackgroundTransferGroup & group) const
{
    Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::Networking::BackgroundTransfer::DownloadOperation>> operation;
    check_hresult(shim()->abi_GetCurrentDownloadsForTransferGroupAsync(get(group), put(operation)));
    return operation;
}

template <typename D> Windows::Networking::BackgroundTransfer::BackgroundUploader impl_IBackgroundUploaderFactory<D>::CreateWithCompletionGroup(const Windows::Networking::BackgroundTransfer::BackgroundTransferCompletionGroup & completionGroup) const
{
    Windows::Networking::BackgroundTransfer::BackgroundUploader backgroundUploader { nullptr };
    check_hresult(shim()->abi_CreateWithCompletionGroup(get(completionGroup), put(backgroundUploader)));
    return backgroundUploader;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::Networking::BackgroundTransfer::UploadOperation>> impl_IBackgroundUploaderStaticMethods<D>::GetCurrentUploadsAsync() const
{
    Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::Networking::BackgroundTransfer::UploadOperation>> operation;
    check_hresult(shim()->abi_GetCurrentUploadsAsync(put(operation)));
    return operation;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::Networking::BackgroundTransfer::UploadOperation>> impl_IBackgroundUploaderStaticMethods<D>::GetCurrentUploadsAsync(hstring_ref group) const
{
    Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::Networking::BackgroundTransfer::UploadOperation>> operation;
    check_hresult(shim()->abi_GetCurrentUploadsForGroupAsync(get(group), put(operation)));
    return operation;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::Networking::BackgroundTransfer::UploadOperation>> impl_IBackgroundUploaderStaticMethods2<D>::GetCurrentUploadsForTransferGroupAsync(const Windows::Networking::BackgroundTransfer::BackgroundTransferGroup & group) const
{
    Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::Networking::BackgroundTransfer::UploadOperation>> operation;
    check_hresult(shim()->abi_GetCurrentUploadsForTransferGroupAsync(get(group), put(operation)));
    return operation;
}

template <typename D> bool impl_IResponseInformation<D>::IsResumable() const
{
    bool value {};
    check_hresult(shim()->get_IsResumable(&value));
    return value;
}

template <typename D> Windows::Foundation::Uri impl_IResponseInformation<D>::ActualUri() const
{
    Windows::Foundation::Uri value { nullptr };
    check_hresult(shim()->get_ActualUri(put(value)));
    return value;
}

template <typename D> uint32_t impl_IResponseInformation<D>::StatusCode() const
{
    uint32_t value {};
    check_hresult(shim()->get_StatusCode(&value));
    return value;
}

template <typename D> Windows::Foundation::Collections::IMapView<hstring, hstring> impl_IResponseInformation<D>::Headers() const
{
    Windows::Foundation::Collections::IMapView<hstring, hstring> value;
    check_hresult(shim()->get_Headers(put(value)));
    return value;
}

template <typename D> Windows::Web::WebErrorStatus impl_IBackgroundTransferErrorStaticMethods<D>::GetStatus(int32_t hresult) const
{
    Windows::Web::WebErrorStatus status {};
    check_hresult(shim()->abi_GetStatus(hresult, &status));
    return status;
}

template <typename D> void impl_IBackgroundTransferContentPart<D>::SetHeader(hstring_ref headerName, hstring_ref headerValue) const
{
    check_hresult(shim()->abi_SetHeader(get(headerName), get(headerValue)));
}

template <typename D> void impl_IBackgroundTransferContentPart<D>::SetText(hstring_ref value) const
{
    check_hresult(shim()->abi_SetText(get(value)));
}

template <typename D> void impl_IBackgroundTransferContentPart<D>::SetFile(const Windows::Storage::IStorageFile & value) const
{
    check_hresult(shim()->abi_SetFile(get(value)));
}

template <typename D> Windows::Networking::BackgroundTransfer::BackgroundTransferContentPart impl_IBackgroundTransferContentPartFactory<D>::CreateWithName(hstring_ref name) const
{
    Windows::Networking::BackgroundTransfer::BackgroundTransferContentPart value { nullptr };
    check_hresult(shim()->abi_CreateWithName(get(name), put(value)));
    return value;
}

template <typename D> Windows::Networking::BackgroundTransfer::BackgroundTransferContentPart impl_IBackgroundTransferContentPartFactory<D>::CreateWithNameAndFileName(hstring_ref name, hstring_ref fileName) const
{
    Windows::Networking::BackgroundTransfer::BackgroundTransferContentPart value { nullptr };
    check_hresult(shim()->abi_CreateWithNameAndFileName(get(name), get(fileName), put(value)));
    return value;
}

template <typename D> hstring impl_IBackgroundTransferGroup<D>::Name() const
{
    hstring value;
    check_hresult(shim()->get_Name(put(value)));
    return value;
}

template <typename D> Windows::Networking::BackgroundTransfer::BackgroundTransferBehavior impl_IBackgroundTransferGroup<D>::TransferBehavior() const
{
    Windows::Networking::BackgroundTransfer::BackgroundTransferBehavior value {};
    check_hresult(shim()->get_TransferBehavior(&value));
    return value;
}

template <typename D> void impl_IBackgroundTransferGroup<D>::TransferBehavior(Windows::Networking::BackgroundTransfer::BackgroundTransferBehavior value) const
{
    check_hresult(shim()->put_TransferBehavior(value));
}

template <typename D> Windows::Networking::BackgroundTransfer::BackgroundTransferGroup impl_IBackgroundTransferGroupStatics<D>::CreateGroup(hstring_ref name) const
{
    Windows::Networking::BackgroundTransfer::BackgroundTransferGroup value { nullptr };
    check_hresult(shim()->abi_CreateGroup(get(name), put(value)));
    return value;
}

template <typename D> Windows::Foundation::IReference<Windows::Foundation::DateTime> impl_IContentPrefetcherTime<D>::LastSuccessfulPrefetchTime() const
{
    Windows::Foundation::IReference<Windows::Foundation::DateTime> value;
    check_hresult(shim()->get_LastSuccessfulPrefetchTime(put(value)));
    return value;
}

template <typename D> Windows::Foundation::Collections::IVector<Windows::Foundation::Uri> impl_IContentPrefetcher<D>::ContentUris() const
{
    Windows::Foundation::Collections::IVector<Windows::Foundation::Uri> value;
    check_hresult(shim()->get_ContentUris(put(value)));
    return value;
}

template <typename D> void impl_IContentPrefetcher<D>::IndirectContentUri(const Windows::Foundation::Uri & value) const
{
    check_hresult(shim()->put_IndirectContentUri(get(value)));
}

template <typename D> Windows::Foundation::Uri impl_IContentPrefetcher<D>::IndirectContentUri() const
{
    Windows::Foundation::Uri value { nullptr };
    check_hresult(shim()->get_IndirectContentUri(put(value)));
    return value;
}

template <typename D> Windows::ApplicationModel::Background::IBackgroundTrigger impl_IBackgroundTransferCompletionGroup<D>::Trigger() const
{
    Windows::ApplicationModel::Background::IBackgroundTrigger value;
    check_hresult(shim()->get_Trigger(put(value)));
    return value;
}

template <typename D> bool impl_IBackgroundTransferCompletionGroup<D>::IsEnabled() const
{
    bool value {};
    check_hresult(shim()->get_IsEnabled(&value));
    return value;
}

template <typename D> void impl_IBackgroundTransferCompletionGroup<D>::Enable() const
{
    check_hresult(shim()->abi_Enable());
}

template <typename D> Windows::Foundation::Collections::IVectorView<Windows::Networking::BackgroundTransfer::DownloadOperation> impl_IBackgroundTransferCompletionGroupTriggerDetails<D>::Downloads() const
{
    Windows::Foundation::Collections::IVectorView<Windows::Networking::BackgroundTransfer::DownloadOperation> value;
    check_hresult(shim()->get_Downloads(put(value)));
    return value;
}

template <typename D> Windows::Foundation::Collections::IVectorView<Windows::Networking::BackgroundTransfer::UploadOperation> impl_IBackgroundTransferCompletionGroupTriggerDetails<D>::Uploads() const
{
    Windows::Foundation::Collections::IVectorView<Windows::Networking::BackgroundTransfer::UploadOperation> value;
    check_hresult(shim()->get_Uploads(put(value)));
    return value;
}

inline BackgroundDownloader::BackgroundDownloader() :
    BackgroundDownloader(activate_instance<BackgroundDownloader>())
{}

inline BackgroundDownloader::BackgroundDownloader(const Windows::Networking::BackgroundTransfer::BackgroundTransferCompletionGroup & completionGroup) :
    BackgroundDownloader(get_activation_factory<BackgroundDownloader, IBackgroundDownloaderFactory>().CreateWithCompletionGroup(completionGroup))
{}

inline Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::Networking::BackgroundTransfer::DownloadOperation>> BackgroundDownloader::GetCurrentDownloadsAsync()
{
    return get_activation_factory<BackgroundDownloader, IBackgroundDownloaderStaticMethods>().GetCurrentDownloadsAsync();
}

inline Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::Networking::BackgroundTransfer::DownloadOperation>> BackgroundDownloader::GetCurrentDownloadsAsync(hstring_ref group)
{
    return get_activation_factory<BackgroundDownloader, IBackgroundDownloaderStaticMethods>().GetCurrentDownloadsAsync(group);
}

inline Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::Networking::BackgroundTransfer::DownloadOperation>> BackgroundDownloader::GetCurrentDownloadsForTransferGroupAsync(const Windows::Networking::BackgroundTransfer::BackgroundTransferGroup & group)
{
    return get_activation_factory<BackgroundDownloader, IBackgroundDownloaderStaticMethods2>().GetCurrentDownloadsForTransferGroupAsync(group);
}

inline Windows::Foundation::IAsyncOperation<Windows::Networking::BackgroundTransfer::UnconstrainedTransferRequestResult> BackgroundDownloader::RequestUnconstrainedDownloadsAsync(const Windows::Foundation::Collections::IIterable<Windows::Networking::BackgroundTransfer::DownloadOperation> & operations)
{
    return get_activation_factory<BackgroundDownloader, IBackgroundDownloaderUserConsent>().RequestUnconstrainedDownloadsAsync(operations);
}

inline BackgroundTransferCompletionGroup::BackgroundTransferCompletionGroup() :
    BackgroundTransferCompletionGroup(activate_instance<BackgroundTransferCompletionGroup>())
{}

inline BackgroundTransferContentPart::BackgroundTransferContentPart() :
    BackgroundTransferContentPart(activate_instance<BackgroundTransferContentPart>())
{}

inline BackgroundTransferContentPart::BackgroundTransferContentPart(hstring_ref name) :
    BackgroundTransferContentPart(get_activation_factory<BackgroundTransferContentPart, IBackgroundTransferContentPartFactory>().CreateWithName(name))
{}

inline BackgroundTransferContentPart::BackgroundTransferContentPart(hstring_ref name, hstring_ref fileName) :
    BackgroundTransferContentPart(get_activation_factory<BackgroundTransferContentPart, IBackgroundTransferContentPartFactory>().CreateWithNameAndFileName(name, fileName))
{}

inline Windows::Web::WebErrorStatus BackgroundTransferError::GetStatus(int32_t hresult)
{
    return get_activation_factory<BackgroundTransferError, IBackgroundTransferErrorStaticMethods>().GetStatus(hresult);
}

inline Windows::Networking::BackgroundTransfer::BackgroundTransferGroup BackgroundTransferGroup::CreateGroup(hstring_ref name)
{
    return get_activation_factory<BackgroundTransferGroup, IBackgroundTransferGroupStatics>().CreateGroup(name);
}

inline BackgroundUploader::BackgroundUploader() :
    BackgroundUploader(activate_instance<BackgroundUploader>())
{}

inline BackgroundUploader::BackgroundUploader(const Windows::Networking::BackgroundTransfer::BackgroundTransferCompletionGroup & completionGroup) :
    BackgroundUploader(get_activation_factory<BackgroundUploader, IBackgroundUploaderFactory>().CreateWithCompletionGroup(completionGroup))
{}

inline Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::Networking::BackgroundTransfer::UploadOperation>> BackgroundUploader::GetCurrentUploadsAsync()
{
    return get_activation_factory<BackgroundUploader, IBackgroundUploaderStaticMethods>().GetCurrentUploadsAsync();
}

inline Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::Networking::BackgroundTransfer::UploadOperation>> BackgroundUploader::GetCurrentUploadsAsync(hstring_ref group)
{
    return get_activation_factory<BackgroundUploader, IBackgroundUploaderStaticMethods>().GetCurrentUploadsAsync(group);
}

inline Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::Networking::BackgroundTransfer::UploadOperation>> BackgroundUploader::GetCurrentUploadsForTransferGroupAsync(const Windows::Networking::BackgroundTransfer::BackgroundTransferGroup & group)
{
    return get_activation_factory<BackgroundUploader, IBackgroundUploaderStaticMethods2>().GetCurrentUploadsForTransferGroupAsync(group);
}

inline Windows::Foundation::IAsyncOperation<Windows::Networking::BackgroundTransfer::UnconstrainedTransferRequestResult> BackgroundUploader::RequestUnconstrainedUploadsAsync(const Windows::Foundation::Collections::IIterable<Windows::Networking::BackgroundTransfer::UploadOperation> & operations)
{
    return get_activation_factory<BackgroundUploader, IBackgroundUploaderUserConsent>().RequestUnconstrainedUploadsAsync(operations);
}

inline Windows::Foundation::Collections::IVector<Windows::Foundation::Uri> ContentPrefetcher::ContentUris()
{
    return get_activation_factory<ContentPrefetcher, IContentPrefetcher>().ContentUris();
}

inline void ContentPrefetcher::IndirectContentUri(const Windows::Foundation::Uri & value)
{
    get_activation_factory<ContentPrefetcher, IContentPrefetcher>().IndirectContentUri(value);
}

inline Windows::Foundation::Uri ContentPrefetcher::IndirectContentUri()
{
    return get_activation_factory<ContentPrefetcher, IContentPrefetcher>().IndirectContentUri();
}

inline Windows::Foundation::IReference<Windows::Foundation::DateTime> ContentPrefetcher::LastSuccessfulPrefetchTime()
{
    return get_activation_factory<ContentPrefetcher, IContentPrefetcherTime>().LastSuccessfulPrefetchTime();
}

}

}
