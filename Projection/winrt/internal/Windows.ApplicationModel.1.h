// C++ for the Windows Runtime v1.0.private
// Copyright (c) 2016 Microsoft Corporation

#pragma once

#include "../base.h"
#include "Windows.ApplicationModel.0.h"
#include "Windows.Foundation.0.h"
#include "Windows.Storage.0.h"
#include "Windows.Storage.Streams.0.h"
#include "Windows.System.0.h"
#include "Windows.Foundation.Collections.1.h"
#include "Windows.ApplicationModel.Core.1.h"
#include "Windows.Foundation.1.h"

WINRT_EXPORT namespace winrt {

namespace ABI::Windows::ApplicationModel {

struct PackageVersion
{
    uint16_t Major;
    uint16_t Minor;
    uint16_t Build;
    uint16_t Revision;
};

}

namespace Windows::ApplicationModel {

using PackageVersion = ABI::Windows::ApplicationModel::PackageVersion;

}

namespace ABI::Windows::ApplicationModel {

struct __declspec(uuid("1aeb1103-e4d4-41aa-a4f6-c4a276e79eac")) __declspec(novtable) IAppDisplayInfo : Windows::IInspectable
{
    virtual HRESULT __stdcall get_DisplayName(hstring * value) = 0;
    virtual HRESULT __stdcall get_Description(hstring * value) = 0;
    virtual HRESULT __stdcall abi_GetLogo(Windows::Foundation::Size size, Windows::Storage::Streams::IRandomAccessStreamReference ** value) = 0;
};

struct __declspec(uuid("cf7f59b3-6a09-4de8-a6c0-5792d56880d1")) __declspec(novtable) IAppInfo : Windows::IInspectable
{
    virtual HRESULT __stdcall get_Id(hstring * value) = 0;
    virtual HRESULT __stdcall get_AppUserModelId(hstring * value) = 0;
    virtual HRESULT __stdcall get_DisplayInfo(Windows::ApplicationModel::IAppDisplayInfo ** value) = 0;
    virtual HRESULT __stdcall get_PackageFamilyName(hstring * value) = 0;
};

struct __declspec(uuid("2c3893cc-f81a-4e7a-b857-76a80887e185")) __declspec(novtable) IDesignModeStatics : Windows::IInspectable
{
    virtual HRESULT __stdcall get_DesignModeEnabled(bool * value) = 0;
};

struct __declspec(uuid("f722dcc2-9827-403d-aaed-ecca9ac17398")) __declspec(novtable) IEnteredBackgroundEventArgs : Windows::IInspectable
{
    virtual HRESULT __stdcall abi_GetDeferral(Windows::Foundation::IDeferral ** value) = 0;
};

struct __declspec(uuid("39c6ec9a-ae6e-46f9-a07a-cfc23f88733e")) __declspec(novtable) ILeavingBackgroundEventArgs : Windows::IInspectable
{
    virtual HRESULT __stdcall abi_GetDeferral(Windows::Foundation::IDeferral ** value) = 0;
};

struct __declspec(uuid("163c792f-bd75-413c-bf23-b1fe7b95d825")) __declspec(novtable) IPackage : Windows::IInspectable
{
    virtual HRESULT __stdcall get_Id(Windows::ApplicationModel::IPackageId ** value) = 0;
    virtual HRESULT __stdcall get_InstalledLocation(Windows::Storage::IStorageFolder ** value) = 0;
    virtual HRESULT __stdcall get_IsFramework(bool * value) = 0;
    virtual HRESULT __stdcall get_Dependencies(Windows::Foundation::Collections::IVectorView<Windows::ApplicationModel::Package> ** value) = 0;
};

struct __declspec(uuid("a6612fb6-7688-4ace-95fb-359538e7aa01")) __declspec(novtable) IPackage2 : Windows::IInspectable
{
    virtual HRESULT __stdcall get_DisplayName(hstring * value) = 0;
    virtual HRESULT __stdcall get_PublisherDisplayName(hstring * value) = 0;
    virtual HRESULT __stdcall get_Description(hstring * value) = 0;
    virtual HRESULT __stdcall get_Logo(Windows::Foundation::IUriRuntimeClass ** value) = 0;
    virtual HRESULT __stdcall get_IsResourcePackage(bool * value) = 0;
    virtual HRESULT __stdcall get_IsBundle(bool * value) = 0;
    virtual HRESULT __stdcall get_IsDevelopmentMode(bool * value) = 0;
};

struct __declspec(uuid("5f738b61-f86a-4917-93d1-f1ee9d3b35d9")) __declspec(novtable) IPackage3 : Windows::IInspectable
{
    virtual HRESULT __stdcall get_Status(Windows::ApplicationModel::IPackageStatus ** value) = 0;
    virtual HRESULT __stdcall get_InstalledDate(Windows::Foundation::DateTime * value) = 0;
    virtual HRESULT __stdcall abi_GetAppListEntriesAsync(Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::ApplicationModel::Core::AppListEntry>> ** operation) = 0;
};

struct __declspec(uuid("65aed1ae-b95b-450c-882b-6255187f397e")) __declspec(novtable) IPackage4 : Windows::IInspectable
{
    virtual HRESULT __stdcall get_SignatureKind(winrt::Windows::ApplicationModel::PackageSignatureKind * value) = 0;
    virtual HRESULT __stdcall get_IsOptional(bool * value) = 0;
    virtual HRESULT __stdcall abi_VerifyContentIntegrityAsync(Windows::Foundation::IAsyncOperation<bool> ** operation) = 0;
};

struct __declspec(uuid("230a3751-9de3-4445-be74-91fb325abefe")) __declspec(novtable) IPackageCatalog : Windows::IInspectable
{
    virtual HRESULT __stdcall add_PackageStaging(Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::PackageCatalog, Windows::ApplicationModel::PackageStagingEventArgs> * handler, event_token * token) = 0;
    virtual HRESULT __stdcall remove_PackageStaging(event_token token) = 0;
    virtual HRESULT __stdcall add_PackageInstalling(Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::PackageCatalog, Windows::ApplicationModel::PackageInstallingEventArgs> * handler, event_token * token) = 0;
    virtual HRESULT __stdcall remove_PackageInstalling(event_token token) = 0;
    virtual HRESULT __stdcall add_PackageUpdating(Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::PackageCatalog, Windows::ApplicationModel::PackageUpdatingEventArgs> * handler, event_token * token) = 0;
    virtual HRESULT __stdcall remove_PackageUpdating(event_token token) = 0;
    virtual HRESULT __stdcall add_PackageUninstalling(Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::PackageCatalog, Windows::ApplicationModel::PackageUninstallingEventArgs> * handler, event_token * token) = 0;
    virtual HRESULT __stdcall remove_PackageUninstalling(event_token token) = 0;
    virtual HRESULT __stdcall add_PackageStatusChanged(Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::PackageCatalog, Windows::ApplicationModel::PackageStatusChangedEventArgs> * handler, event_token * token) = 0;
    virtual HRESULT __stdcall remove_PackageStatusChanged(event_token token) = 0;
};

struct __declspec(uuid("a18c9696-e65b-4634-ba21-5e63eb7244a7")) __declspec(novtable) IPackageCatalogStatics : Windows::IInspectable
{
    virtual HRESULT __stdcall abi_OpenForCurrentPackage(Windows::ApplicationModel::IPackageCatalog ** value) = 0;
    virtual HRESULT __stdcall abi_OpenForCurrentUser(Windows::ApplicationModel::IPackageCatalog ** value) = 0;
};

struct __declspec(uuid("1adb665e-37c7-4790-9980-dd7ae74e8bb2")) __declspec(novtable) IPackageId : Windows::IInspectable
{
    virtual HRESULT __stdcall get_Name(hstring * value) = 0;
    virtual HRESULT __stdcall get_Version(Windows::ApplicationModel::PackageVersion * value) = 0;
    virtual HRESULT __stdcall get_Architecture(winrt::Windows::System::ProcessorArchitecture * value) = 0;
    virtual HRESULT __stdcall get_ResourceId(hstring * value) = 0;
    virtual HRESULT __stdcall get_Publisher(hstring * value) = 0;
    virtual HRESULT __stdcall get_PublisherId(hstring * value) = 0;
    virtual HRESULT __stdcall get_FullName(hstring * value) = 0;
    virtual HRESULT __stdcall get_FamilyName(hstring * value) = 0;
};

struct __declspec(uuid("40577a7c-0c9e-443d-9074-855f5ce0a08d")) __declspec(novtable) IPackageIdWithMetadata : Windows::IInspectable
{
    virtual HRESULT __stdcall get_ProductId(hstring * value) = 0;
    virtual HRESULT __stdcall get_Author(hstring * value) = 0;
};

struct __declspec(uuid("97741eb7-ab7a-401a-8b61-eb0e7faff237")) __declspec(novtable) IPackageInstallingEventArgs : Windows::IInspectable
{
    virtual HRESULT __stdcall get_ActivityId(GUID * value) = 0;
    virtual HRESULT __stdcall get_Package(Windows::ApplicationModel::IPackage ** value) = 0;
    virtual HRESULT __stdcall get_Progress(double * value) = 0;
    virtual HRESULT __stdcall get_IsComplete(bool * value) = 0;
    virtual HRESULT __stdcall get_ErrorCode(HRESULT * value) = 0;
};

struct __declspec(uuid("1041682d-54e2-4f51-b828-9ef7046c210f")) __declspec(novtable) IPackageStagingEventArgs : Windows::IInspectable
{
    virtual HRESULT __stdcall get_ActivityId(GUID * value) = 0;
    virtual HRESULT __stdcall get_Package(Windows::ApplicationModel::IPackage ** value) = 0;
    virtual HRESULT __stdcall get_Progress(double * value) = 0;
    virtual HRESULT __stdcall get_IsComplete(bool * value) = 0;
    virtual HRESULT __stdcall get_ErrorCode(HRESULT * value) = 0;
};

struct __declspec(uuid("4e534bdf-2960-4878-97a4-9624deb72f2d")) __declspec(novtable) IPackageStatics : Windows::IInspectable
{
    virtual HRESULT __stdcall get_Current(Windows::ApplicationModel::IPackage ** value) = 0;
};

struct __declspec(uuid("5fe74f71-a365-4c09-a02d-046d525ea1da")) __declspec(novtable) IPackageStatus : Windows::IInspectable
{
    virtual HRESULT __stdcall abi_VerifyIsOK(bool * value) = 0;
    virtual HRESULT __stdcall get_NotAvailable(bool * value) = 0;
    virtual HRESULT __stdcall get_PackageOffline(bool * value) = 0;
    virtual HRESULT __stdcall get_DataOffline(bool * value) = 0;
    virtual HRESULT __stdcall get_Disabled(bool * value) = 0;
    virtual HRESULT __stdcall get_NeedsRemediation(bool * value) = 0;
    virtual HRESULT __stdcall get_LicenseIssue(bool * value) = 0;
    virtual HRESULT __stdcall get_Modified(bool * value) = 0;
    virtual HRESULT __stdcall get_Tampered(bool * value) = 0;
    virtual HRESULT __stdcall get_DependencyIssue(bool * value) = 0;
    virtual HRESULT __stdcall get_Servicing(bool * value) = 0;
    virtual HRESULT __stdcall get_DeploymentInProgress(bool * value) = 0;
};

struct __declspec(uuid("437d714d-bd80-4a70-bc50-f6e796509575")) __declspec(novtable) IPackageStatusChangedEventArgs : Windows::IInspectable
{
    virtual HRESULT __stdcall get_Package(Windows::ApplicationModel::IPackage ** value) = 0;
};

struct __declspec(uuid("4443aa52-ab22-44cd-82bb-4ec9b827367a")) __declspec(novtable) IPackageUninstallingEventArgs : Windows::IInspectable
{
    virtual HRESULT __stdcall get_ActivityId(GUID * value) = 0;
    virtual HRESULT __stdcall get_Package(Windows::ApplicationModel::IPackage ** value) = 0;
    virtual HRESULT __stdcall get_Progress(double * value) = 0;
    virtual HRESULT __stdcall get_IsComplete(bool * value) = 0;
    virtual HRESULT __stdcall get_ErrorCode(HRESULT * value) = 0;
};

struct __declspec(uuid("cd7b4228-fd74-443e-b114-23e677b0e86f")) __declspec(novtable) IPackageUpdatingEventArgs : Windows::IInspectable
{
    virtual HRESULT __stdcall get_ActivityId(GUID * value) = 0;
    virtual HRESULT __stdcall get_SourcePackage(Windows::ApplicationModel::IPackage ** value) = 0;
    virtual HRESULT __stdcall get_TargetPackage(Windows::ApplicationModel::IPackage ** value) = 0;
    virtual HRESULT __stdcall get_Progress(double * value) = 0;
    virtual HRESULT __stdcall get_IsComplete(bool * value) = 0;
    virtual HRESULT __stdcall get_ErrorCode(HRESULT * value) = 0;
};

struct __declspec(uuid("95949780-1de9-40f2-b452-0de9f1910012")) __declspec(novtable) IPackageWithMetadata : Windows::IInspectable
{
    virtual HRESULT __stdcall get_InstallDate(Windows::Foundation::DateTime * value) = 0;
    virtual HRESULT __stdcall abi_GetThumbnailToken(hstring * value) = 0;
    virtual HRESULT __stdcall abi_Launch(hstring parameters) = 0;
};

struct __declspec(uuid("59140509-8bc9-4eb4-b636-dabdc4f46f66")) __declspec(novtable) ISuspendingDeferral : Windows::IInspectable
{
    virtual HRESULT __stdcall abi_Complete() = 0;
};

struct __declspec(uuid("96061c05-2dba-4d08-b0bd-2b30a131c6aa")) __declspec(novtable) ISuspendingEventArgs : Windows::IInspectable
{
    virtual HRESULT __stdcall get_SuspendingOperation(Windows::ApplicationModel::ISuspendingOperation ** value) = 0;
};

struct __declspec(uuid("9da4ca41-20e1-4e9b-9f65-a9f435340c3a")) __declspec(novtable) ISuspendingOperation : Windows::IInspectable
{
    virtual HRESULT __stdcall abi_GetDeferral(Windows::ApplicationModel::ISuspendingDeferral ** deferral) = 0;
    virtual HRESULT __stdcall get_Deadline(Windows::Foundation::DateTime * value) = 0;
};

}

namespace ABI {

template <> struct traits<Windows::ApplicationModel::AppDisplayInfo> { using default_interface = Windows::ApplicationModel::IAppDisplayInfo; };
template <> struct traits<Windows::ApplicationModel::AppInfo> { using default_interface = Windows::ApplicationModel::IAppInfo; };
template <> struct traits<Windows::ApplicationModel::EnteredBackgroundEventArgs> { using default_interface = Windows::ApplicationModel::IEnteredBackgroundEventArgs; };
template <> struct traits<Windows::ApplicationModel::LeavingBackgroundEventArgs> { using default_interface = Windows::ApplicationModel::ILeavingBackgroundEventArgs; };
template <> struct traits<Windows::ApplicationModel::Package> { using default_interface = Windows::ApplicationModel::IPackage; };
template <> struct traits<Windows::ApplicationModel::PackageCatalog> { using default_interface = Windows::ApplicationModel::IPackageCatalog; };
template <> struct traits<Windows::ApplicationModel::PackageId> { using default_interface = Windows::ApplicationModel::IPackageId; };
template <> struct traits<Windows::ApplicationModel::PackageInstallingEventArgs> { using default_interface = Windows::ApplicationModel::IPackageInstallingEventArgs; };
template <> struct traits<Windows::ApplicationModel::PackageStagingEventArgs> { using default_interface = Windows::ApplicationModel::IPackageStagingEventArgs; };
template <> struct traits<Windows::ApplicationModel::PackageStatus> { using default_interface = Windows::ApplicationModel::IPackageStatus; };
template <> struct traits<Windows::ApplicationModel::PackageStatusChangedEventArgs> { using default_interface = Windows::ApplicationModel::IPackageStatusChangedEventArgs; };
template <> struct traits<Windows::ApplicationModel::PackageUninstallingEventArgs> { using default_interface = Windows::ApplicationModel::IPackageUninstallingEventArgs; };
template <> struct traits<Windows::ApplicationModel::PackageUpdatingEventArgs> { using default_interface = Windows::ApplicationModel::IPackageUpdatingEventArgs; };
template <> struct traits<Windows::ApplicationModel::SuspendingDeferral> { using default_interface = Windows::ApplicationModel::ISuspendingDeferral; };
template <> struct traits<Windows::ApplicationModel::SuspendingEventArgs> { using default_interface = Windows::ApplicationModel::ISuspendingEventArgs; };
template <> struct traits<Windows::ApplicationModel::SuspendingOperation> { using default_interface = Windows::ApplicationModel::ISuspendingOperation; };

}

namespace Windows::ApplicationModel {

template <typename T> struct impl_IAppDisplayInfo;
template <typename T> struct impl_IAppInfo;
template <typename T> struct impl_IDesignModeStatics;
template <typename T> struct impl_IEnteredBackgroundEventArgs;
template <typename T> struct impl_ILeavingBackgroundEventArgs;
template <typename T> struct impl_IPackage;
template <typename T> struct impl_IPackage2;
template <typename T> struct impl_IPackage3;
template <typename T> struct impl_IPackage4;
template <typename T> struct impl_IPackageCatalog;
template <typename T> struct impl_IPackageCatalogStatics;
template <typename T> struct impl_IPackageId;
template <typename T> struct impl_IPackageIdWithMetadata;
template <typename T> struct impl_IPackageInstallingEventArgs;
template <typename T> struct impl_IPackageStagingEventArgs;
template <typename T> struct impl_IPackageStatics;
template <typename T> struct impl_IPackageStatus;
template <typename T> struct impl_IPackageStatusChangedEventArgs;
template <typename T> struct impl_IPackageUninstallingEventArgs;
template <typename T> struct impl_IPackageUpdatingEventArgs;
template <typename T> struct impl_IPackageWithMetadata;
template <typename T> struct impl_ISuspendingDeferral;
template <typename T> struct impl_ISuspendingEventArgs;
template <typename T> struct impl_ISuspendingOperation;

}

namespace impl {

template <> struct traits<Windows::ApplicationModel::IAppDisplayInfo>
{
    using abi = ABI::Windows::ApplicationModel::IAppDisplayInfo;
    template <typename D> using consume = Windows::ApplicationModel::impl_IAppDisplayInfo<D>;
};

template <> struct traits<Windows::ApplicationModel::IAppInfo>
{
    using abi = ABI::Windows::ApplicationModel::IAppInfo;
    template <typename D> using consume = Windows::ApplicationModel::impl_IAppInfo<D>;
};

template <> struct traits<Windows::ApplicationModel::IDesignModeStatics>
{
    using abi = ABI::Windows::ApplicationModel::IDesignModeStatics;
    template <typename D> using consume = Windows::ApplicationModel::impl_IDesignModeStatics<D>;
};

template <> struct traits<Windows::ApplicationModel::IEnteredBackgroundEventArgs>
{
    using abi = ABI::Windows::ApplicationModel::IEnteredBackgroundEventArgs;
    template <typename D> using consume = Windows::ApplicationModel::impl_IEnteredBackgroundEventArgs<D>;
};

template <> struct traits<Windows::ApplicationModel::ILeavingBackgroundEventArgs>
{
    using abi = ABI::Windows::ApplicationModel::ILeavingBackgroundEventArgs;
    template <typename D> using consume = Windows::ApplicationModel::impl_ILeavingBackgroundEventArgs<D>;
};

template <> struct traits<Windows::ApplicationModel::IPackage>
{
    using abi = ABI::Windows::ApplicationModel::IPackage;
    template <typename D> using consume = Windows::ApplicationModel::impl_IPackage<D>;
};

template <> struct traits<Windows::ApplicationModel::IPackage2>
{
    using abi = ABI::Windows::ApplicationModel::IPackage2;
    template <typename D> using consume = Windows::ApplicationModel::impl_IPackage2<D>;
};

template <> struct traits<Windows::ApplicationModel::IPackage3>
{
    using abi = ABI::Windows::ApplicationModel::IPackage3;
    template <typename D> using consume = Windows::ApplicationModel::impl_IPackage3<D>;
};

template <> struct traits<Windows::ApplicationModel::IPackage4>
{
    using abi = ABI::Windows::ApplicationModel::IPackage4;
    template <typename D> using consume = Windows::ApplicationModel::impl_IPackage4<D>;
};

template <> struct traits<Windows::ApplicationModel::IPackageCatalog>
{
    using abi = ABI::Windows::ApplicationModel::IPackageCatalog;
    template <typename D> using consume = Windows::ApplicationModel::impl_IPackageCatalog<D>;
};

template <> struct traits<Windows::ApplicationModel::IPackageCatalogStatics>
{
    using abi = ABI::Windows::ApplicationModel::IPackageCatalogStatics;
    template <typename D> using consume = Windows::ApplicationModel::impl_IPackageCatalogStatics<D>;
};

template <> struct traits<Windows::ApplicationModel::IPackageId>
{
    using abi = ABI::Windows::ApplicationModel::IPackageId;
    template <typename D> using consume = Windows::ApplicationModel::impl_IPackageId<D>;
};

template <> struct traits<Windows::ApplicationModel::IPackageIdWithMetadata>
{
    using abi = ABI::Windows::ApplicationModel::IPackageIdWithMetadata;
    template <typename D> using consume = Windows::ApplicationModel::impl_IPackageIdWithMetadata<D>;
};

template <> struct traits<Windows::ApplicationModel::IPackageInstallingEventArgs>
{
    using abi = ABI::Windows::ApplicationModel::IPackageInstallingEventArgs;
    template <typename D> using consume = Windows::ApplicationModel::impl_IPackageInstallingEventArgs<D>;
};

template <> struct traits<Windows::ApplicationModel::IPackageStagingEventArgs>
{
    using abi = ABI::Windows::ApplicationModel::IPackageStagingEventArgs;
    template <typename D> using consume = Windows::ApplicationModel::impl_IPackageStagingEventArgs<D>;
};

template <> struct traits<Windows::ApplicationModel::IPackageStatics>
{
    using abi = ABI::Windows::ApplicationModel::IPackageStatics;
    template <typename D> using consume = Windows::ApplicationModel::impl_IPackageStatics<D>;
};

template <> struct traits<Windows::ApplicationModel::IPackageStatus>
{
    using abi = ABI::Windows::ApplicationModel::IPackageStatus;
    template <typename D> using consume = Windows::ApplicationModel::impl_IPackageStatus<D>;
};

template <> struct traits<Windows::ApplicationModel::IPackageStatusChangedEventArgs>
{
    using abi = ABI::Windows::ApplicationModel::IPackageStatusChangedEventArgs;
    template <typename D> using consume = Windows::ApplicationModel::impl_IPackageStatusChangedEventArgs<D>;
};

template <> struct traits<Windows::ApplicationModel::IPackageUninstallingEventArgs>
{
    using abi = ABI::Windows::ApplicationModel::IPackageUninstallingEventArgs;
    template <typename D> using consume = Windows::ApplicationModel::impl_IPackageUninstallingEventArgs<D>;
};

template <> struct traits<Windows::ApplicationModel::IPackageUpdatingEventArgs>
{
    using abi = ABI::Windows::ApplicationModel::IPackageUpdatingEventArgs;
    template <typename D> using consume = Windows::ApplicationModel::impl_IPackageUpdatingEventArgs<D>;
};

template <> struct traits<Windows::ApplicationModel::IPackageWithMetadata>
{
    using abi = ABI::Windows::ApplicationModel::IPackageWithMetadata;
    template <typename D> using consume = Windows::ApplicationModel::impl_IPackageWithMetadata<D>;
};

template <> struct traits<Windows::ApplicationModel::ISuspendingDeferral>
{
    using abi = ABI::Windows::ApplicationModel::ISuspendingDeferral;
    template <typename D> using consume = Windows::ApplicationModel::impl_ISuspendingDeferral<D>;
};

template <> struct traits<Windows::ApplicationModel::ISuspendingEventArgs>
{
    using abi = ABI::Windows::ApplicationModel::ISuspendingEventArgs;
    template <typename D> using consume = Windows::ApplicationModel::impl_ISuspendingEventArgs<D>;
};

template <> struct traits<Windows::ApplicationModel::ISuspendingOperation>
{
    using abi = ABI::Windows::ApplicationModel::ISuspendingOperation;
    template <typename D> using consume = Windows::ApplicationModel::impl_ISuspendingOperation<D>;
};

template <> struct traits<Windows::ApplicationModel::AppDisplayInfo>
{
    using abi = ABI::Windows::ApplicationModel::AppDisplayInfo;
    static constexpr const wchar_t * name() noexcept { return L"Windows.ApplicationModel.AppDisplayInfo"; }
};

template <> struct traits<Windows::ApplicationModel::AppInfo>
{
    using abi = ABI::Windows::ApplicationModel::AppInfo;
    static constexpr const wchar_t * name() noexcept { return L"Windows.ApplicationModel.AppInfo"; }
};

template <> struct traits<Windows::ApplicationModel::DesignMode>
{
    static constexpr const wchar_t * name() noexcept { return L"Windows.ApplicationModel.DesignMode"; }
};

template <> struct traits<Windows::ApplicationModel::EnteredBackgroundEventArgs>
{
    using abi = ABI::Windows::ApplicationModel::EnteredBackgroundEventArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.ApplicationModel.EnteredBackgroundEventArgs"; }
};

template <> struct traits<Windows::ApplicationModel::LeavingBackgroundEventArgs>
{
    using abi = ABI::Windows::ApplicationModel::LeavingBackgroundEventArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.ApplicationModel.LeavingBackgroundEventArgs"; }
};

template <> struct traits<Windows::ApplicationModel::Package>
{
    using abi = ABI::Windows::ApplicationModel::Package;
    static constexpr const wchar_t * name() noexcept { return L"Windows.ApplicationModel.Package"; }
};

template <> struct traits<Windows::ApplicationModel::PackageCatalog>
{
    using abi = ABI::Windows::ApplicationModel::PackageCatalog;
    static constexpr const wchar_t * name() noexcept { return L"Windows.ApplicationModel.PackageCatalog"; }
};

template <> struct traits<Windows::ApplicationModel::PackageId>
{
    using abi = ABI::Windows::ApplicationModel::PackageId;
    static constexpr const wchar_t * name() noexcept { return L"Windows.ApplicationModel.PackageId"; }
};

template <> struct traits<Windows::ApplicationModel::PackageInstallingEventArgs>
{
    using abi = ABI::Windows::ApplicationModel::PackageInstallingEventArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.ApplicationModel.PackageInstallingEventArgs"; }
};

template <> struct traits<Windows::ApplicationModel::PackageStagingEventArgs>
{
    using abi = ABI::Windows::ApplicationModel::PackageStagingEventArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.ApplicationModel.PackageStagingEventArgs"; }
};

template <> struct traits<Windows::ApplicationModel::PackageStatus>
{
    using abi = ABI::Windows::ApplicationModel::PackageStatus;
    static constexpr const wchar_t * name() noexcept { return L"Windows.ApplicationModel.PackageStatus"; }
};

template <> struct traits<Windows::ApplicationModel::PackageStatusChangedEventArgs>
{
    using abi = ABI::Windows::ApplicationModel::PackageStatusChangedEventArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.ApplicationModel.PackageStatusChangedEventArgs"; }
};

template <> struct traits<Windows::ApplicationModel::PackageUninstallingEventArgs>
{
    using abi = ABI::Windows::ApplicationModel::PackageUninstallingEventArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.ApplicationModel.PackageUninstallingEventArgs"; }
};

template <> struct traits<Windows::ApplicationModel::PackageUpdatingEventArgs>
{
    using abi = ABI::Windows::ApplicationModel::PackageUpdatingEventArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.ApplicationModel.PackageUpdatingEventArgs"; }
};

template <> struct traits<Windows::ApplicationModel::SuspendingDeferral>
{
    using abi = ABI::Windows::ApplicationModel::SuspendingDeferral;
    static constexpr const wchar_t * name() noexcept { return L"Windows.ApplicationModel.SuspendingDeferral"; }
};

template <> struct traits<Windows::ApplicationModel::SuspendingEventArgs>
{
    using abi = ABI::Windows::ApplicationModel::SuspendingEventArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.ApplicationModel.SuspendingEventArgs"; }
};

template <> struct traits<Windows::ApplicationModel::SuspendingOperation>
{
    using abi = ABI::Windows::ApplicationModel::SuspendingOperation;
    static constexpr const wchar_t * name() noexcept { return L"Windows.ApplicationModel.SuspendingOperation"; }
};

}

}
