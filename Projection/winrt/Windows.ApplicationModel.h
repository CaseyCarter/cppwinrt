// C++ for the Windows Runtime v1.0.private
// Copyright (c) 2016 Microsoft Corporation

#pragma once

#include "internal/Windows.Foundation.3.h"
#include "internal/Windows.Storage.Streams.3.h"
#include "internal/Windows.System.3.h"
#include "internal/Windows.Storage.3.h"
#include "internal/Windows.Foundation.Collections.3.h"
#include "internal/Windows.ApplicationModel.3.h"

WINRT_EXPORT namespace winrt {

namespace impl {

template <typename D>
struct produce<D, Windows::ApplicationModel::IAppDisplayInfo> : produce_base<D, Windows::ApplicationModel::IAppDisplayInfo>
{
    HRESULT __stdcall get_DisplayName(abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            *value = detach(this->shim().DisplayName());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Description(abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            *value = detach(this->shim().Description());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetLogo(abi_arg_in<Windows::Foundation::Size> size, abi_arg_out<Windows::Storage::Streams::IRandomAccessStreamReference> value) noexcept override
    {
        try
        {
            *value = detach(this->shim().GetLogo(*reinterpret_cast<const Windows::Foundation::Size *>(&size)));
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
struct produce<D, Windows::ApplicationModel::IAppInfo> : produce_base<D, Windows::ApplicationModel::IAppInfo>
{
    HRESULT __stdcall get_Id(abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            *value = detach(this->shim().Id());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_AppUserModelId(abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            *value = detach(this->shim().AppUserModelId());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_DisplayInfo(abi_arg_out<Windows::ApplicationModel::IAppDisplayInfo> value) noexcept override
    {
        try
        {
            *value = detach(this->shim().DisplayInfo());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_PackageFamilyName(abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            *value = detach(this->shim().PackageFamilyName());
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
struct produce<D, Windows::ApplicationModel::IDesignModeStatics> : produce_base<D, Windows::ApplicationModel::IDesignModeStatics>
{
    HRESULT __stdcall get_DesignModeEnabled(bool * value) noexcept override
    {
        try
        {
            *value = detach(this->shim().DesignModeEnabled());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::ApplicationModel::IEnteredBackgroundEventArgs> : produce_base<D, Windows::ApplicationModel::IEnteredBackgroundEventArgs>
{
    HRESULT __stdcall abi_GetDeferral(abi_arg_out<Windows::Foundation::IDeferral> value) noexcept override
    {
        try
        {
            *value = detach(this->shim().GetDeferral());
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
struct produce<D, Windows::ApplicationModel::ILeavingBackgroundEventArgs> : produce_base<D, Windows::ApplicationModel::ILeavingBackgroundEventArgs>
{
    HRESULT __stdcall abi_GetDeferral(abi_arg_out<Windows::Foundation::IDeferral> value) noexcept override
    {
        try
        {
            *value = detach(this->shim().GetDeferral());
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
struct produce<D, Windows::ApplicationModel::IPackage> : produce_base<D, Windows::ApplicationModel::IPackage>
{
    HRESULT __stdcall get_Id(abi_arg_out<Windows::ApplicationModel::IPackageId> value) noexcept override
    {
        try
        {
            *value = detach(this->shim().Id());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_InstalledLocation(abi_arg_out<Windows::Storage::IStorageFolder> value) noexcept override
    {
        try
        {
            *value = detach(this->shim().InstalledLocation());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_IsFramework(bool * value) noexcept override
    {
        try
        {
            *value = detach(this->shim().IsFramework());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Dependencies(abi_arg_out<Windows::Foundation::Collections::IVectorView<Windows::ApplicationModel::Package>> value) noexcept override
    {
        try
        {
            *value = detach(this->shim().Dependencies());
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
struct produce<D, Windows::ApplicationModel::IPackage2> : produce_base<D, Windows::ApplicationModel::IPackage2>
{
    HRESULT __stdcall get_DisplayName(abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            *value = detach(this->shim().DisplayName());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_PublisherDisplayName(abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            *value = detach(this->shim().PublisherDisplayName());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Description(abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            *value = detach(this->shim().Description());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Logo(abi_arg_out<Windows::Foundation::IUriRuntimeClass> value) noexcept override
    {
        try
        {
            *value = detach(this->shim().Logo());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_IsResourcePackage(bool * value) noexcept override
    {
        try
        {
            *value = detach(this->shim().IsResourcePackage());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_IsBundle(bool * value) noexcept override
    {
        try
        {
            *value = detach(this->shim().IsBundle());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_IsDevelopmentMode(bool * value) noexcept override
    {
        try
        {
            *value = detach(this->shim().IsDevelopmentMode());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::ApplicationModel::IPackage3> : produce_base<D, Windows::ApplicationModel::IPackage3>
{
    HRESULT __stdcall get_Status(abi_arg_out<Windows::ApplicationModel::IPackageStatus> value) noexcept override
    {
        try
        {
            *value = detach(this->shim().Status());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_InstalledDate(abi_arg_out<Windows::Foundation::DateTime> value) noexcept override
    {
        try
        {
            *value = detach(this->shim().InstalledDate());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetAppListEntriesAsync(abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::ApplicationModel::Core::AppListEntry>>> operation) noexcept override
    {
        try
        {
            *operation = detach(this->shim().GetAppListEntriesAsync());
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
struct produce<D, Windows::ApplicationModel::IPackage4> : produce_base<D, Windows::ApplicationModel::IPackage4>
{
    HRESULT __stdcall get_SignatureKind(Windows::ApplicationModel::PackageSignatureKind * value) noexcept override
    {
        try
        {
            *value = detach(this->shim().SignatureKind());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_IsOptional(bool * value) noexcept override
    {
        try
        {
            *value = detach(this->shim().IsOptional());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_VerifyContentIntegrityAsync(abi_arg_out<Windows::Foundation::IAsyncOperation<bool>> operation) noexcept override
    {
        try
        {
            *operation = detach(this->shim().VerifyContentIntegrityAsync());
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
struct produce<D, Windows::ApplicationModel::IPackageCatalog> : produce_base<D, Windows::ApplicationModel::IPackageCatalog>
{
    HRESULT __stdcall add_PackageStaging(abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::PackageCatalog, Windows::ApplicationModel::PackageStagingEventArgs>> handler, event_token * token) noexcept override
    {
        try
        {
            *token = detach(this->shim().PackageStaging(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::PackageCatalog, Windows::ApplicationModel::PackageStagingEventArgs> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_PackageStaging(event_token token) noexcept override
    {
        try
        {
            this->shim().PackageStaging(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_PackageInstalling(abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::PackageCatalog, Windows::ApplicationModel::PackageInstallingEventArgs>> handler, event_token * token) noexcept override
    {
        try
        {
            *token = detach(this->shim().PackageInstalling(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::PackageCatalog, Windows::ApplicationModel::PackageInstallingEventArgs> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_PackageInstalling(event_token token) noexcept override
    {
        try
        {
            this->shim().PackageInstalling(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_PackageUpdating(abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::PackageCatalog, Windows::ApplicationModel::PackageUpdatingEventArgs>> handler, event_token * token) noexcept override
    {
        try
        {
            *token = detach(this->shim().PackageUpdating(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::PackageCatalog, Windows::ApplicationModel::PackageUpdatingEventArgs> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_PackageUpdating(event_token token) noexcept override
    {
        try
        {
            this->shim().PackageUpdating(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_PackageUninstalling(abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::PackageCatalog, Windows::ApplicationModel::PackageUninstallingEventArgs>> handler, event_token * token) noexcept override
    {
        try
        {
            *token = detach(this->shim().PackageUninstalling(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::PackageCatalog, Windows::ApplicationModel::PackageUninstallingEventArgs> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_PackageUninstalling(event_token token) noexcept override
    {
        try
        {
            this->shim().PackageUninstalling(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_PackageStatusChanged(abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::PackageCatalog, Windows::ApplicationModel::PackageStatusChangedEventArgs>> handler, event_token * token) noexcept override
    {
        try
        {
            *token = detach(this->shim().PackageStatusChanged(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::PackageCatalog, Windows::ApplicationModel::PackageStatusChangedEventArgs> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_PackageStatusChanged(event_token token) noexcept override
    {
        try
        {
            this->shim().PackageStatusChanged(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::ApplicationModel::IPackageCatalogStatics> : produce_base<D, Windows::ApplicationModel::IPackageCatalogStatics>
{
    HRESULT __stdcall abi_OpenForCurrentPackage(abi_arg_out<Windows::ApplicationModel::IPackageCatalog> value) noexcept override
    {
        try
        {
            *value = detach(this->shim().OpenForCurrentPackage());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_OpenForCurrentUser(abi_arg_out<Windows::ApplicationModel::IPackageCatalog> value) noexcept override
    {
        try
        {
            *value = detach(this->shim().OpenForCurrentUser());
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
struct produce<D, Windows::ApplicationModel::IPackageId> : produce_base<D, Windows::ApplicationModel::IPackageId>
{
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

    HRESULT __stdcall get_Version(abi_arg_out<Windows::ApplicationModel::PackageVersion> value) noexcept override
    {
        try
        {
            *value = detach(this->shim().Version());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Architecture(Windows::System::ProcessorArchitecture * value) noexcept override
    {
        try
        {
            *value = detach(this->shim().Architecture());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ResourceId(abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            *value = detach(this->shim().ResourceId());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Publisher(abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            *value = detach(this->shim().Publisher());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_PublisherId(abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            *value = detach(this->shim().PublisherId());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_FullName(abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            *value = detach(this->shim().FullName());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_FamilyName(abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            *value = detach(this->shim().FamilyName());
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
struct produce<D, Windows::ApplicationModel::IPackageIdWithMetadata> : produce_base<D, Windows::ApplicationModel::IPackageIdWithMetadata>
{
    HRESULT __stdcall get_ProductId(abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            *value = detach(this->shim().ProductId());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Author(abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            *value = detach(this->shim().Author());
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
struct produce<D, Windows::ApplicationModel::IPackageInstallingEventArgs> : produce_base<D, Windows::ApplicationModel::IPackageInstallingEventArgs>
{
    HRESULT __stdcall get_ActivityId(GUID * value) noexcept override
    {
        try
        {
            *value = detach(this->shim().ActivityId());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Package(abi_arg_out<Windows::ApplicationModel::IPackage> value) noexcept override
    {
        try
        {
            *value = detach(this->shim().Package());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Progress(double * value) noexcept override
    {
        try
        {
            *value = detach(this->shim().Progress());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_IsComplete(bool * value) noexcept override
    {
        try
        {
            *value = detach(this->shim().IsComplete());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ErrorCode(HRESULT * value) noexcept override
    {
        try
        {
            *value = detach(this->shim().ErrorCode());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::ApplicationModel::IPackageStagingEventArgs> : produce_base<D, Windows::ApplicationModel::IPackageStagingEventArgs>
{
    HRESULT __stdcall get_ActivityId(GUID * value) noexcept override
    {
        try
        {
            *value = detach(this->shim().ActivityId());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Package(abi_arg_out<Windows::ApplicationModel::IPackage> value) noexcept override
    {
        try
        {
            *value = detach(this->shim().Package());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Progress(double * value) noexcept override
    {
        try
        {
            *value = detach(this->shim().Progress());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_IsComplete(bool * value) noexcept override
    {
        try
        {
            *value = detach(this->shim().IsComplete());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ErrorCode(HRESULT * value) noexcept override
    {
        try
        {
            *value = detach(this->shim().ErrorCode());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::ApplicationModel::IPackageStatics> : produce_base<D, Windows::ApplicationModel::IPackageStatics>
{
    HRESULT __stdcall get_Current(abi_arg_out<Windows::ApplicationModel::IPackage> value) noexcept override
    {
        try
        {
            *value = detach(this->shim().Current());
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
struct produce<D, Windows::ApplicationModel::IPackageStatus> : produce_base<D, Windows::ApplicationModel::IPackageStatus>
{
    HRESULT __stdcall abi_VerifyIsOK(bool * value) noexcept override
    {
        try
        {
            *value = detach(this->shim().VerifyIsOK());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_NotAvailable(bool * value) noexcept override
    {
        try
        {
            *value = detach(this->shim().NotAvailable());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_PackageOffline(bool * value) noexcept override
    {
        try
        {
            *value = detach(this->shim().PackageOffline());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_DataOffline(bool * value) noexcept override
    {
        try
        {
            *value = detach(this->shim().DataOffline());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Disabled(bool * value) noexcept override
    {
        try
        {
            *value = detach(this->shim().Disabled());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_NeedsRemediation(bool * value) noexcept override
    {
        try
        {
            *value = detach(this->shim().NeedsRemediation());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_LicenseIssue(bool * value) noexcept override
    {
        try
        {
            *value = detach(this->shim().LicenseIssue());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Modified(bool * value) noexcept override
    {
        try
        {
            *value = detach(this->shim().Modified());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Tampered(bool * value) noexcept override
    {
        try
        {
            *value = detach(this->shim().Tampered());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_DependencyIssue(bool * value) noexcept override
    {
        try
        {
            *value = detach(this->shim().DependencyIssue());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Servicing(bool * value) noexcept override
    {
        try
        {
            *value = detach(this->shim().Servicing());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_DeploymentInProgress(bool * value) noexcept override
    {
        try
        {
            *value = detach(this->shim().DeploymentInProgress());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::ApplicationModel::IPackageStatusChangedEventArgs> : produce_base<D, Windows::ApplicationModel::IPackageStatusChangedEventArgs>
{
    HRESULT __stdcall get_Package(abi_arg_out<Windows::ApplicationModel::IPackage> value) noexcept override
    {
        try
        {
            *value = detach(this->shim().Package());
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
struct produce<D, Windows::ApplicationModel::IPackageUninstallingEventArgs> : produce_base<D, Windows::ApplicationModel::IPackageUninstallingEventArgs>
{
    HRESULT __stdcall get_ActivityId(GUID * value) noexcept override
    {
        try
        {
            *value = detach(this->shim().ActivityId());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Package(abi_arg_out<Windows::ApplicationModel::IPackage> value) noexcept override
    {
        try
        {
            *value = detach(this->shim().Package());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Progress(double * value) noexcept override
    {
        try
        {
            *value = detach(this->shim().Progress());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_IsComplete(bool * value) noexcept override
    {
        try
        {
            *value = detach(this->shim().IsComplete());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ErrorCode(HRESULT * value) noexcept override
    {
        try
        {
            *value = detach(this->shim().ErrorCode());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::ApplicationModel::IPackageUpdatingEventArgs> : produce_base<D, Windows::ApplicationModel::IPackageUpdatingEventArgs>
{
    HRESULT __stdcall get_ActivityId(GUID * value) noexcept override
    {
        try
        {
            *value = detach(this->shim().ActivityId());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_SourcePackage(abi_arg_out<Windows::ApplicationModel::IPackage> value) noexcept override
    {
        try
        {
            *value = detach(this->shim().SourcePackage());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_TargetPackage(abi_arg_out<Windows::ApplicationModel::IPackage> value) noexcept override
    {
        try
        {
            *value = detach(this->shim().TargetPackage());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Progress(double * value) noexcept override
    {
        try
        {
            *value = detach(this->shim().Progress());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_IsComplete(bool * value) noexcept override
    {
        try
        {
            *value = detach(this->shim().IsComplete());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ErrorCode(HRESULT * value) noexcept override
    {
        try
        {
            *value = detach(this->shim().ErrorCode());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::ApplicationModel::IPackageWithMetadata> : produce_base<D, Windows::ApplicationModel::IPackageWithMetadata>
{
    HRESULT __stdcall get_InstallDate(abi_arg_out<Windows::Foundation::DateTime> value) noexcept override
    {
        try
        {
            *value = detach(this->shim().InstallDate());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetThumbnailToken(abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            *value = detach(this->shim().GetThumbnailToken());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_Launch(abi_arg_in<hstring> parameters) noexcept override
    {
        try
        {
            this->shim().Launch(*reinterpret_cast<const hstring *>(&parameters));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::ApplicationModel::ISuspendingDeferral> : produce_base<D, Windows::ApplicationModel::ISuspendingDeferral>
{
    HRESULT __stdcall abi_Complete() noexcept override
    {
        try
        {
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
struct produce<D, Windows::ApplicationModel::ISuspendingEventArgs> : produce_base<D, Windows::ApplicationModel::ISuspendingEventArgs>
{
    HRESULT __stdcall get_SuspendingOperation(abi_arg_out<Windows::ApplicationModel::ISuspendingOperation> value) noexcept override
    {
        try
        {
            *value = detach(this->shim().SuspendingOperation());
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
struct produce<D, Windows::ApplicationModel::ISuspendingOperation> : produce_base<D, Windows::ApplicationModel::ISuspendingOperation>
{
    HRESULT __stdcall abi_GetDeferral(abi_arg_out<Windows::ApplicationModel::ISuspendingDeferral> deferral) noexcept override
    {
        try
        {
            *deferral = detach(this->shim().GetDeferral());
            return S_OK;
        }
        catch (...)
        {
            *deferral = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Deadline(abi_arg_out<Windows::Foundation::DateTime> value) noexcept override
    {
        try
        {
            *value = detach(this->shim().Deadline());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

}

namespace Windows::ApplicationModel {

template <typename D> hstring impl_IAppDisplayInfo<D>::DisplayName() const
{
    hstring value;
    check_hresult(static_cast<const IAppDisplayInfo &>(static_cast<const D &>(*this))->get_DisplayName(put(value)));
    return value;
}

template <typename D> hstring impl_IAppDisplayInfo<D>::Description() const
{
    hstring value;
    check_hresult(static_cast<const IAppDisplayInfo &>(static_cast<const D &>(*this))->get_Description(put(value)));
    return value;
}

template <typename D> Windows::Storage::Streams::RandomAccessStreamReference impl_IAppDisplayInfo<D>::GetLogo(const Windows::Foundation::Size & size) const
{
    Windows::Storage::Streams::RandomAccessStreamReference value { nullptr };
    check_hresult(static_cast<const IAppDisplayInfo &>(static_cast<const D &>(*this))->abi_GetLogo(get(size), put(value)));
    return value;
}

template <typename D> hstring impl_IAppInfo<D>::Id() const
{
    hstring value;
    check_hresult(static_cast<const IAppInfo &>(static_cast<const D &>(*this))->get_Id(put(value)));
    return value;
}

template <typename D> hstring impl_IAppInfo<D>::AppUserModelId() const
{
    hstring value;
    check_hresult(static_cast<const IAppInfo &>(static_cast<const D &>(*this))->get_AppUserModelId(put(value)));
    return value;
}

template <typename D> Windows::ApplicationModel::AppDisplayInfo impl_IAppInfo<D>::DisplayInfo() const
{
    Windows::ApplicationModel::AppDisplayInfo value { nullptr };
    check_hresult(static_cast<const IAppInfo &>(static_cast<const D &>(*this))->get_DisplayInfo(put(value)));
    return value;
}

template <typename D> hstring impl_IAppInfo<D>::PackageFamilyName() const
{
    hstring value;
    check_hresult(static_cast<const IAppInfo &>(static_cast<const D &>(*this))->get_PackageFamilyName(put(value)));
    return value;
}

template <typename D> void impl_ISuspendingDeferral<D>::Complete() const
{
    check_hresult(static_cast<const ISuspendingDeferral &>(static_cast<const D &>(*this))->abi_Complete());
}

template <typename D> Windows::ApplicationModel::SuspendingDeferral impl_ISuspendingOperation<D>::GetDeferral() const
{
    Windows::ApplicationModel::SuspendingDeferral deferral { nullptr };
    check_hresult(static_cast<const ISuspendingOperation &>(static_cast<const D &>(*this))->abi_GetDeferral(put(deferral)));
    return deferral;
}

template <typename D> Windows::Foundation::DateTime impl_ISuspendingOperation<D>::Deadline() const
{
    Windows::Foundation::DateTime value {};
    check_hresult(static_cast<const ISuspendingOperation &>(static_cast<const D &>(*this))->get_Deadline(put(value)));
    return value;
}

template <typename D> Windows::ApplicationModel::SuspendingOperation impl_ISuspendingEventArgs<D>::SuspendingOperation() const
{
    Windows::ApplicationModel::SuspendingOperation value { nullptr };
    check_hresult(static_cast<const ISuspendingEventArgs &>(static_cast<const D &>(*this))->get_SuspendingOperation(put(value)));
    return value;
}

template <typename D> Windows::Foundation::Deferral impl_ILeavingBackgroundEventArgs<D>::GetDeferral() const
{
    Windows::Foundation::Deferral value { nullptr };
    check_hresult(static_cast<const ILeavingBackgroundEventArgs &>(static_cast<const D &>(*this))->abi_GetDeferral(put(value)));
    return value;
}

template <typename D> Windows::Foundation::Deferral impl_IEnteredBackgroundEventArgs<D>::GetDeferral() const
{
    Windows::Foundation::Deferral value { nullptr };
    check_hresult(static_cast<const IEnteredBackgroundEventArgs &>(static_cast<const D &>(*this))->abi_GetDeferral(put(value)));
    return value;
}

template <typename D> hstring impl_IPackageIdWithMetadata<D>::ProductId() const
{
    hstring value;
    check_hresult(static_cast<const IPackageIdWithMetadata &>(static_cast<const D &>(*this))->get_ProductId(put(value)));
    return value;
}

template <typename D> hstring impl_IPackageIdWithMetadata<D>::Author() const
{
    hstring value;
    check_hresult(static_cast<const IPackageIdWithMetadata &>(static_cast<const D &>(*this))->get_Author(put(value)));
    return value;
}

template <typename D> Windows::Foundation::DateTime impl_IPackageWithMetadata<D>::InstallDate() const
{
    Windows::Foundation::DateTime value {};
    check_hresult(static_cast<const IPackageWithMetadata &>(static_cast<const D &>(*this))->get_InstallDate(put(value)));
    return value;
}

template <typename D> hstring impl_IPackageWithMetadata<D>::GetThumbnailToken() const
{
    hstring value;
    check_hresult(static_cast<const IPackageWithMetadata &>(static_cast<const D &>(*this))->abi_GetThumbnailToken(put(value)));
    return value;
}

template <typename D> void impl_IPackageWithMetadata<D>::Launch(hstring_ref parameters) const
{
    check_hresult(static_cast<const IPackageWithMetadata &>(static_cast<const D &>(*this))->abi_Launch(get(parameters)));
}

template <typename D> bool impl_IPackageStatus<D>::VerifyIsOK() const
{
    bool value {};
    check_hresult(static_cast<const IPackageStatus &>(static_cast<const D &>(*this))->abi_VerifyIsOK(&value));
    return value;
}

template <typename D> bool impl_IPackageStatus<D>::NotAvailable() const
{
    bool value {};
    check_hresult(static_cast<const IPackageStatus &>(static_cast<const D &>(*this))->get_NotAvailable(&value));
    return value;
}

template <typename D> bool impl_IPackageStatus<D>::PackageOffline() const
{
    bool value {};
    check_hresult(static_cast<const IPackageStatus &>(static_cast<const D &>(*this))->get_PackageOffline(&value));
    return value;
}

template <typename D> bool impl_IPackageStatus<D>::DataOffline() const
{
    bool value {};
    check_hresult(static_cast<const IPackageStatus &>(static_cast<const D &>(*this))->get_DataOffline(&value));
    return value;
}

template <typename D> bool impl_IPackageStatus<D>::Disabled() const
{
    bool value {};
    check_hresult(static_cast<const IPackageStatus &>(static_cast<const D &>(*this))->get_Disabled(&value));
    return value;
}

template <typename D> bool impl_IPackageStatus<D>::NeedsRemediation() const
{
    bool value {};
    check_hresult(static_cast<const IPackageStatus &>(static_cast<const D &>(*this))->get_NeedsRemediation(&value));
    return value;
}

template <typename D> bool impl_IPackageStatus<D>::LicenseIssue() const
{
    bool value {};
    check_hresult(static_cast<const IPackageStatus &>(static_cast<const D &>(*this))->get_LicenseIssue(&value));
    return value;
}

template <typename D> bool impl_IPackageStatus<D>::Modified() const
{
    bool value {};
    check_hresult(static_cast<const IPackageStatus &>(static_cast<const D &>(*this))->get_Modified(&value));
    return value;
}

template <typename D> bool impl_IPackageStatus<D>::Tampered() const
{
    bool value {};
    check_hresult(static_cast<const IPackageStatus &>(static_cast<const D &>(*this))->get_Tampered(&value));
    return value;
}

template <typename D> bool impl_IPackageStatus<D>::DependencyIssue() const
{
    bool value {};
    check_hresult(static_cast<const IPackageStatus &>(static_cast<const D &>(*this))->get_DependencyIssue(&value));
    return value;
}

template <typename D> bool impl_IPackageStatus<D>::Servicing() const
{
    bool value {};
    check_hresult(static_cast<const IPackageStatus &>(static_cast<const D &>(*this))->get_Servicing(&value));
    return value;
}

template <typename D> bool impl_IPackageStatus<D>::DeploymentInProgress() const
{
    bool value {};
    check_hresult(static_cast<const IPackageStatus &>(static_cast<const D &>(*this))->get_DeploymentInProgress(&value));
    return value;
}

template <typename D> hstring impl_IPackageId<D>::Name() const
{
    hstring value;
    check_hresult(static_cast<const IPackageId &>(static_cast<const D &>(*this))->get_Name(put(value)));
    return value;
}

template <typename D> Windows::ApplicationModel::PackageVersion impl_IPackageId<D>::Version() const
{
    Windows::ApplicationModel::PackageVersion value {};
    check_hresult(static_cast<const IPackageId &>(static_cast<const D &>(*this))->get_Version(put(value)));
    return value;
}

template <typename D> Windows::System::ProcessorArchitecture impl_IPackageId<D>::Architecture() const
{
    Windows::System::ProcessorArchitecture value {};
    check_hresult(static_cast<const IPackageId &>(static_cast<const D &>(*this))->get_Architecture(&value));
    return value;
}

template <typename D> hstring impl_IPackageId<D>::ResourceId() const
{
    hstring value;
    check_hresult(static_cast<const IPackageId &>(static_cast<const D &>(*this))->get_ResourceId(put(value)));
    return value;
}

template <typename D> hstring impl_IPackageId<D>::Publisher() const
{
    hstring value;
    check_hresult(static_cast<const IPackageId &>(static_cast<const D &>(*this))->get_Publisher(put(value)));
    return value;
}

template <typename D> hstring impl_IPackageId<D>::PublisherId() const
{
    hstring value;
    check_hresult(static_cast<const IPackageId &>(static_cast<const D &>(*this))->get_PublisherId(put(value)));
    return value;
}

template <typename D> hstring impl_IPackageId<D>::FullName() const
{
    hstring value;
    check_hresult(static_cast<const IPackageId &>(static_cast<const D &>(*this))->get_FullName(put(value)));
    return value;
}

template <typename D> hstring impl_IPackageId<D>::FamilyName() const
{
    hstring value;
    check_hresult(static_cast<const IPackageId &>(static_cast<const D &>(*this))->get_FamilyName(put(value)));
    return value;
}

template <typename D> Windows::ApplicationModel::PackageId impl_IPackage<D>::Id() const
{
    Windows::ApplicationModel::PackageId value { nullptr };
    check_hresult(static_cast<const IPackage &>(static_cast<const D &>(*this))->get_Id(put(value)));
    return value;
}

template <typename D> Windows::Storage::StorageFolder impl_IPackage<D>::InstalledLocation() const
{
    Windows::Storage::StorageFolder value { nullptr };
    check_hresult(static_cast<const IPackage &>(static_cast<const D &>(*this))->get_InstalledLocation(put(value)));
    return value;
}

template <typename D> bool impl_IPackage<D>::IsFramework() const
{
    bool value {};
    check_hresult(static_cast<const IPackage &>(static_cast<const D &>(*this))->get_IsFramework(&value));
    return value;
}

template <typename D> Windows::Foundation::Collections::IVectorView<Windows::ApplicationModel::Package> impl_IPackage<D>::Dependencies() const
{
    Windows::Foundation::Collections::IVectorView<Windows::ApplicationModel::Package> value;
    check_hresult(static_cast<const IPackage &>(static_cast<const D &>(*this))->get_Dependencies(put(value)));
    return value;
}

template <typename D> hstring impl_IPackage2<D>::DisplayName() const
{
    hstring value;
    check_hresult(static_cast<const IPackage2 &>(static_cast<const D &>(*this))->get_DisplayName(put(value)));
    return value;
}

template <typename D> hstring impl_IPackage2<D>::PublisherDisplayName() const
{
    hstring value;
    check_hresult(static_cast<const IPackage2 &>(static_cast<const D &>(*this))->get_PublisherDisplayName(put(value)));
    return value;
}

template <typename D> hstring impl_IPackage2<D>::Description() const
{
    hstring value;
    check_hresult(static_cast<const IPackage2 &>(static_cast<const D &>(*this))->get_Description(put(value)));
    return value;
}

template <typename D> Windows::Foundation::Uri impl_IPackage2<D>::Logo() const
{
    Windows::Foundation::Uri value { nullptr };
    check_hresult(static_cast<const IPackage2 &>(static_cast<const D &>(*this))->get_Logo(put(value)));
    return value;
}

template <typename D> bool impl_IPackage2<D>::IsResourcePackage() const
{
    bool value {};
    check_hresult(static_cast<const IPackage2 &>(static_cast<const D &>(*this))->get_IsResourcePackage(&value));
    return value;
}

template <typename D> bool impl_IPackage2<D>::IsBundle() const
{
    bool value {};
    check_hresult(static_cast<const IPackage2 &>(static_cast<const D &>(*this))->get_IsBundle(&value));
    return value;
}

template <typename D> bool impl_IPackage2<D>::IsDevelopmentMode() const
{
    bool value {};
    check_hresult(static_cast<const IPackage2 &>(static_cast<const D &>(*this))->get_IsDevelopmentMode(&value));
    return value;
}

template <typename D> Windows::ApplicationModel::PackageStatus impl_IPackage3<D>::Status() const
{
    Windows::ApplicationModel::PackageStatus value { nullptr };
    check_hresult(static_cast<const IPackage3 &>(static_cast<const D &>(*this))->get_Status(put(value)));
    return value;
}

template <typename D> Windows::Foundation::DateTime impl_IPackage3<D>::InstalledDate() const
{
    Windows::Foundation::DateTime value {};
    check_hresult(static_cast<const IPackage3 &>(static_cast<const D &>(*this))->get_InstalledDate(put(value)));
    return value;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::ApplicationModel::Core::AppListEntry>> impl_IPackage3<D>::GetAppListEntriesAsync() const
{
    Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::ApplicationModel::Core::AppListEntry>> operation;
    check_hresult(static_cast<const IPackage3 &>(static_cast<const D &>(*this))->abi_GetAppListEntriesAsync(put(operation)));
    return operation;
}

template <typename D> Windows::ApplicationModel::PackageSignatureKind impl_IPackage4<D>::SignatureKind() const
{
    Windows::ApplicationModel::PackageSignatureKind value {};
    check_hresult(static_cast<const IPackage4 &>(static_cast<const D &>(*this))->get_SignatureKind(&value));
    return value;
}

template <typename D> bool impl_IPackage4<D>::IsOptional() const
{
    bool value {};
    check_hresult(static_cast<const IPackage4 &>(static_cast<const D &>(*this))->get_IsOptional(&value));
    return value;
}

template <typename D> Windows::Foundation::IAsyncOperation<bool> impl_IPackage4<D>::VerifyContentIntegrityAsync() const
{
    Windows::Foundation::IAsyncOperation<bool> operation;
    check_hresult(static_cast<const IPackage4 &>(static_cast<const D &>(*this))->abi_VerifyContentIntegrityAsync(put(operation)));
    return operation;
}

template <typename D> Windows::ApplicationModel::Package impl_IPackageStatics<D>::Current() const
{
    Windows::ApplicationModel::Package value { nullptr };
    check_hresult(static_cast<const IPackageStatics &>(static_cast<const D &>(*this))->get_Current(put(value)));
    return value;
}

template <typename D> GUID impl_IPackageStagingEventArgs<D>::ActivityId() const
{
    GUID value {};
    check_hresult(static_cast<const IPackageStagingEventArgs &>(static_cast<const D &>(*this))->get_ActivityId(&value));
    return value;
}

template <typename D> Windows::ApplicationModel::Package impl_IPackageStagingEventArgs<D>::Package() const
{
    Windows::ApplicationModel::Package value { nullptr };
    check_hresult(static_cast<const IPackageStagingEventArgs &>(static_cast<const D &>(*this))->get_Package(put(value)));
    return value;
}

template <typename D> double impl_IPackageStagingEventArgs<D>::Progress() const
{
    double value {};
    check_hresult(static_cast<const IPackageStagingEventArgs &>(static_cast<const D &>(*this))->get_Progress(&value));
    return value;
}

template <typename D> bool impl_IPackageStagingEventArgs<D>::IsComplete() const
{
    bool value {};
    check_hresult(static_cast<const IPackageStagingEventArgs &>(static_cast<const D &>(*this))->get_IsComplete(&value));
    return value;
}

template <typename D> HRESULT impl_IPackageStagingEventArgs<D>::ErrorCode() const
{
    HRESULT value {};
    check_hresult(static_cast<const IPackageStagingEventArgs &>(static_cast<const D &>(*this))->get_ErrorCode(&value));
    return value;
}

template <typename D> GUID impl_IPackageInstallingEventArgs<D>::ActivityId() const
{
    GUID value {};
    check_hresult(static_cast<const IPackageInstallingEventArgs &>(static_cast<const D &>(*this))->get_ActivityId(&value));
    return value;
}

template <typename D> Windows::ApplicationModel::Package impl_IPackageInstallingEventArgs<D>::Package() const
{
    Windows::ApplicationModel::Package value { nullptr };
    check_hresult(static_cast<const IPackageInstallingEventArgs &>(static_cast<const D &>(*this))->get_Package(put(value)));
    return value;
}

template <typename D> double impl_IPackageInstallingEventArgs<D>::Progress() const
{
    double value {};
    check_hresult(static_cast<const IPackageInstallingEventArgs &>(static_cast<const D &>(*this))->get_Progress(&value));
    return value;
}

template <typename D> bool impl_IPackageInstallingEventArgs<D>::IsComplete() const
{
    bool value {};
    check_hresult(static_cast<const IPackageInstallingEventArgs &>(static_cast<const D &>(*this))->get_IsComplete(&value));
    return value;
}

template <typename D> HRESULT impl_IPackageInstallingEventArgs<D>::ErrorCode() const
{
    HRESULT value {};
    check_hresult(static_cast<const IPackageInstallingEventArgs &>(static_cast<const D &>(*this))->get_ErrorCode(&value));
    return value;
}

template <typename D> GUID impl_IPackageUpdatingEventArgs<D>::ActivityId() const
{
    GUID value {};
    check_hresult(static_cast<const IPackageUpdatingEventArgs &>(static_cast<const D &>(*this))->get_ActivityId(&value));
    return value;
}

template <typename D> Windows::ApplicationModel::Package impl_IPackageUpdatingEventArgs<D>::SourcePackage() const
{
    Windows::ApplicationModel::Package value { nullptr };
    check_hresult(static_cast<const IPackageUpdatingEventArgs &>(static_cast<const D &>(*this))->get_SourcePackage(put(value)));
    return value;
}

template <typename D> Windows::ApplicationModel::Package impl_IPackageUpdatingEventArgs<D>::TargetPackage() const
{
    Windows::ApplicationModel::Package value { nullptr };
    check_hresult(static_cast<const IPackageUpdatingEventArgs &>(static_cast<const D &>(*this))->get_TargetPackage(put(value)));
    return value;
}

template <typename D> double impl_IPackageUpdatingEventArgs<D>::Progress() const
{
    double value {};
    check_hresult(static_cast<const IPackageUpdatingEventArgs &>(static_cast<const D &>(*this))->get_Progress(&value));
    return value;
}

template <typename D> bool impl_IPackageUpdatingEventArgs<D>::IsComplete() const
{
    bool value {};
    check_hresult(static_cast<const IPackageUpdatingEventArgs &>(static_cast<const D &>(*this))->get_IsComplete(&value));
    return value;
}

template <typename D> HRESULT impl_IPackageUpdatingEventArgs<D>::ErrorCode() const
{
    HRESULT value {};
    check_hresult(static_cast<const IPackageUpdatingEventArgs &>(static_cast<const D &>(*this))->get_ErrorCode(&value));
    return value;
}

template <typename D> GUID impl_IPackageUninstallingEventArgs<D>::ActivityId() const
{
    GUID value {};
    check_hresult(static_cast<const IPackageUninstallingEventArgs &>(static_cast<const D &>(*this))->get_ActivityId(&value));
    return value;
}

template <typename D> Windows::ApplicationModel::Package impl_IPackageUninstallingEventArgs<D>::Package() const
{
    Windows::ApplicationModel::Package value { nullptr };
    check_hresult(static_cast<const IPackageUninstallingEventArgs &>(static_cast<const D &>(*this))->get_Package(put(value)));
    return value;
}

template <typename D> double impl_IPackageUninstallingEventArgs<D>::Progress() const
{
    double value {};
    check_hresult(static_cast<const IPackageUninstallingEventArgs &>(static_cast<const D &>(*this))->get_Progress(&value));
    return value;
}

template <typename D> bool impl_IPackageUninstallingEventArgs<D>::IsComplete() const
{
    bool value {};
    check_hresult(static_cast<const IPackageUninstallingEventArgs &>(static_cast<const D &>(*this))->get_IsComplete(&value));
    return value;
}

template <typename D> HRESULT impl_IPackageUninstallingEventArgs<D>::ErrorCode() const
{
    HRESULT value {};
    check_hresult(static_cast<const IPackageUninstallingEventArgs &>(static_cast<const D &>(*this))->get_ErrorCode(&value));
    return value;
}

template <typename D> Windows::ApplicationModel::Package impl_IPackageStatusChangedEventArgs<D>::Package() const
{
    Windows::ApplicationModel::Package value { nullptr };
    check_hresult(static_cast<const IPackageStatusChangedEventArgs &>(static_cast<const D &>(*this))->get_Package(put(value)));
    return value;
}

template <typename D> event_token impl_IPackageCatalog<D>::PackageStaging(const Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::PackageCatalog, Windows::ApplicationModel::PackageStagingEventArgs> & handler) const
{
    event_token token {};
    check_hresult(static_cast<const IPackageCatalog &>(static_cast<const D &>(*this))->add_PackageStaging(get(handler), &token));
    return token;
}

template <typename D> event_revoker<IPackageCatalog> impl_IPackageCatalog<D>::PackageStaging(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::PackageCatalog, Windows::ApplicationModel::PackageStagingEventArgs> & handler) const
{
    return impl::make_event_revoker<D, IPackageCatalog>(this, &ABI::Windows::ApplicationModel::IPackageCatalog::remove_PackageStaging, PackageStaging(handler));
}

template <typename D> void impl_IPackageCatalog<D>::PackageStaging(event_token token) const
{
    check_hresult(static_cast<const IPackageCatalog &>(static_cast<const D &>(*this))->remove_PackageStaging(token));
}

template <typename D> event_token impl_IPackageCatalog<D>::PackageInstalling(const Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::PackageCatalog, Windows::ApplicationModel::PackageInstallingEventArgs> & handler) const
{
    event_token token {};
    check_hresult(static_cast<const IPackageCatalog &>(static_cast<const D &>(*this))->add_PackageInstalling(get(handler), &token));
    return token;
}

template <typename D> event_revoker<IPackageCatalog> impl_IPackageCatalog<D>::PackageInstalling(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::PackageCatalog, Windows::ApplicationModel::PackageInstallingEventArgs> & handler) const
{
    return impl::make_event_revoker<D, IPackageCatalog>(this, &ABI::Windows::ApplicationModel::IPackageCatalog::remove_PackageInstalling, PackageInstalling(handler));
}

template <typename D> void impl_IPackageCatalog<D>::PackageInstalling(event_token token) const
{
    check_hresult(static_cast<const IPackageCatalog &>(static_cast<const D &>(*this))->remove_PackageInstalling(token));
}

template <typename D> event_token impl_IPackageCatalog<D>::PackageUpdating(const Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::PackageCatalog, Windows::ApplicationModel::PackageUpdatingEventArgs> & handler) const
{
    event_token token {};
    check_hresult(static_cast<const IPackageCatalog &>(static_cast<const D &>(*this))->add_PackageUpdating(get(handler), &token));
    return token;
}

template <typename D> event_revoker<IPackageCatalog> impl_IPackageCatalog<D>::PackageUpdating(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::PackageCatalog, Windows::ApplicationModel::PackageUpdatingEventArgs> & handler) const
{
    return impl::make_event_revoker<D, IPackageCatalog>(this, &ABI::Windows::ApplicationModel::IPackageCatalog::remove_PackageUpdating, PackageUpdating(handler));
}

template <typename D> void impl_IPackageCatalog<D>::PackageUpdating(event_token token) const
{
    check_hresult(static_cast<const IPackageCatalog &>(static_cast<const D &>(*this))->remove_PackageUpdating(token));
}

template <typename D> event_token impl_IPackageCatalog<D>::PackageUninstalling(const Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::PackageCatalog, Windows::ApplicationModel::PackageUninstallingEventArgs> & handler) const
{
    event_token token {};
    check_hresult(static_cast<const IPackageCatalog &>(static_cast<const D &>(*this))->add_PackageUninstalling(get(handler), &token));
    return token;
}

template <typename D> event_revoker<IPackageCatalog> impl_IPackageCatalog<D>::PackageUninstalling(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::PackageCatalog, Windows::ApplicationModel::PackageUninstallingEventArgs> & handler) const
{
    return impl::make_event_revoker<D, IPackageCatalog>(this, &ABI::Windows::ApplicationModel::IPackageCatalog::remove_PackageUninstalling, PackageUninstalling(handler));
}

template <typename D> void impl_IPackageCatalog<D>::PackageUninstalling(event_token token) const
{
    check_hresult(static_cast<const IPackageCatalog &>(static_cast<const D &>(*this))->remove_PackageUninstalling(token));
}

template <typename D> event_token impl_IPackageCatalog<D>::PackageStatusChanged(const Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::PackageCatalog, Windows::ApplicationModel::PackageStatusChangedEventArgs> & handler) const
{
    event_token token {};
    check_hresult(static_cast<const IPackageCatalog &>(static_cast<const D &>(*this))->add_PackageStatusChanged(get(handler), &token));
    return token;
}

template <typename D> event_revoker<IPackageCatalog> impl_IPackageCatalog<D>::PackageStatusChanged(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::PackageCatalog, Windows::ApplicationModel::PackageStatusChangedEventArgs> & handler) const
{
    return impl::make_event_revoker<D, IPackageCatalog>(this, &ABI::Windows::ApplicationModel::IPackageCatalog::remove_PackageStatusChanged, PackageStatusChanged(handler));
}

template <typename D> void impl_IPackageCatalog<D>::PackageStatusChanged(event_token token) const
{
    check_hresult(static_cast<const IPackageCatalog &>(static_cast<const D &>(*this))->remove_PackageStatusChanged(token));
}

template <typename D> Windows::ApplicationModel::PackageCatalog impl_IPackageCatalogStatics<D>::OpenForCurrentPackage() const
{
    Windows::ApplicationModel::PackageCatalog value { nullptr };
    check_hresult(static_cast<const IPackageCatalogStatics &>(static_cast<const D &>(*this))->abi_OpenForCurrentPackage(put(value)));
    return value;
}

template <typename D> Windows::ApplicationModel::PackageCatalog impl_IPackageCatalogStatics<D>::OpenForCurrentUser() const
{
    Windows::ApplicationModel::PackageCatalog value { nullptr };
    check_hresult(static_cast<const IPackageCatalogStatics &>(static_cast<const D &>(*this))->abi_OpenForCurrentUser(put(value)));
    return value;
}

template <typename D> bool impl_IDesignModeStatics<D>::DesignModeEnabled() const
{
    bool value {};
    check_hresult(static_cast<const IDesignModeStatics &>(static_cast<const D &>(*this))->get_DesignModeEnabled(&value));
    return value;
}

inline bool DesignMode::DesignModeEnabled()
{
    return get_activation_factory<DesignMode, IDesignModeStatics>().DesignModeEnabled();
}

inline Windows::ApplicationModel::Package Package::Current()
{
    return get_activation_factory<Package, IPackageStatics>().Current();
}

inline Windows::ApplicationModel::PackageCatalog PackageCatalog::OpenForCurrentPackage()
{
    return get_activation_factory<PackageCatalog, IPackageCatalogStatics>().OpenForCurrentPackage();
}

inline Windows::ApplicationModel::PackageCatalog PackageCatalog::OpenForCurrentUser()
{
    return get_activation_factory<PackageCatalog, IPackageCatalogStatics>().OpenForCurrentUser();
}

}

}
