// C++ for the Windows Runtime v1.29
// Copyright (c) 2016 Microsoft Corporation

#pragma once

#include "Windows.ApplicationModel.DataTransfer.ShareTarget.1.h"

WINRT_EXPORT namespace winrt {

namespace ABI::Windows::Foundation::Collections {

#ifndef WINRT_GENERIC_98b9acc1_4b56_532e_ac73_03d5291cca90
#define WINRT_GENERIC_98b9acc1_4b56_532e_ac73_03d5291cca90
template <> struct __declspec(uuid("98b9acc1-4b56-532e-ac73-03d5291cca90")) __declspec(novtable) IVector<hstring> : impl_IVector<hstring> {};
#endif

#ifndef WINRT_GENERIC_2f13c006_a03a_5f69_b090_75a43e33423e
#define WINRT_GENERIC_2f13c006_a03a_5f69_b090_75a43e33423e
template <> struct __declspec(uuid("2f13c006-a03a-5f69-b090-75a43e33423e")) __declspec(novtable) IVectorView<hstring> : impl_IVectorView<hstring> {};
#endif

#ifndef WINRT_GENERIC_e2fcc7c1_3bfc_5a0b_b2b0_72e769d1cb7e
#define WINRT_GENERIC_e2fcc7c1_3bfc_5a0b_b2b0_72e769d1cb7e
template <> struct __declspec(uuid("e2fcc7c1-3bfc-5a0b-b2b0-72e769d1cb7e")) __declspec(novtable) IIterable<hstring> : impl_IIterable<hstring> {};
#endif

#ifndef WINRT_GENERIC_8c304ebb_6615_50a4_8829_879ecd443236
#define WINRT_GENERIC_8c304ebb_6615_50a4_8829_879ecd443236
template <> struct __declspec(uuid("8c304ebb-6615-50a4-8829-879ecd443236")) __declspec(novtable) IIterator<hstring> : impl_IIterator<hstring> {};
#endif


}

namespace Windows::ApplicationModel::DataTransfer::ShareTarget {

template <typename D>
class WINRT_EBO impl_IQuickLink
{
    auto shim() const { return impl::shim<D, IQuickLink>(this); }

public:

    hstring Title() const;
    void Title(hstring_ref value) const;
    Windows::Storage::Streams::RandomAccessStreamReference Thumbnail() const;
    void Thumbnail(const Windows::Storage::Streams::RandomAccessStreamReference & value) const;
    hstring Id() const;
    void Id(hstring_ref value) const;
    Windows::Foundation::Collections::IVector<hstring> SupportedDataFormats() const;
    Windows::Foundation::Collections::IVector<hstring> SupportedFileTypes() const;
};

template <typename D>
class WINRT_EBO impl_IShareOperation
{
    auto shim() const { return impl::shim<D, IShareOperation>(this); }

public:

    Windows::ApplicationModel::DataTransfer::DataPackageView Data() const;
    hstring QuickLinkId() const;
    void RemoveThisQuickLink() const;
    void ReportStarted() const;
    void ReportDataRetrieved() const;
    void ReportSubmittedBackgroundTask() const;
    void ReportCompleted(const Windows::ApplicationModel::DataTransfer::ShareTarget::QuickLink & quicklink) const;
    void ReportCompleted() const;
    void ReportError(hstring_ref value) const;
};

template <typename D>
class WINRT_EBO impl_IShareOperation2
{
    auto shim() const { return impl::shim<D, IShareOperation2>(this); }

public:

    void DismissUI() const;
};

struct IQuickLink :
    Windows::IInspectable,
    impl::consume<IQuickLink>
{
    IQuickLink(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IQuickLink>(m_ptr); }
};

struct IShareOperation :
    Windows::IInspectable,
    impl::consume<IShareOperation>
{
    IShareOperation(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IShareOperation>(m_ptr); }
};

struct IShareOperation2 :
    Windows::IInspectable,
    impl::consume<IShareOperation2>
{
    IShareOperation2(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IShareOperation2>(m_ptr); }
};

}

}