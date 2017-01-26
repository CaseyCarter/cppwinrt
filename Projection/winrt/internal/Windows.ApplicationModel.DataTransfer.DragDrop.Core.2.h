// C++ for the Windows Runtime v1.0.private
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "Windows.ApplicationModel.DataTransfer.DragDrop.Core.1.h"

WINRT_EXPORT namespace winrt {

namespace ABI::Windows::Foundation {

#ifndef WINRT_GENERIC_8b98aea9_64f0_5672_b30e_dfd9c2e4f6fe
#define WINRT_GENERIC_8b98aea9_64f0_5672_b30e_dfd9c2e4f6fe
template <> struct __declspec(uuid("8b98aea9-64f0-5672-b30e-dfd9c2e4f6fe")) __declspec(novtable) IAsyncOperation<winrt::Windows::ApplicationModel::DataTransfer::DataPackageOperation> : impl_IAsyncOperation<winrt::Windows::ApplicationModel::DataTransfer::DataPackageOperation> {};
#endif

#ifndef WINRT_GENERIC_a4c3b1c1_b8ad_58cb_acc0_8ef37eae4ed4
#define WINRT_GENERIC_a4c3b1c1_b8ad_58cb_acc0_8ef37eae4ed4
template <> struct __declspec(uuid("a4c3b1c1-b8ad-58cb-acc0-8ef37eae4ed4")) __declspec(novtable) TypedEventHandler<Windows::ApplicationModel::DataTransfer::DragDrop::Core::CoreDragDropManager, Windows::ApplicationModel::DataTransfer::DragDrop::Core::CoreDropOperationTargetRequestedEventArgs> : impl_TypedEventHandler<Windows::ApplicationModel::DataTransfer::DragDrop::Core::CoreDragDropManager, Windows::ApplicationModel::DataTransfer::DragDrop::Core::CoreDropOperationTargetRequestedEventArgs> {};
#endif

#ifndef WINRT_GENERIC_add21d46_17df_5a43_a685_3262fce84643
#define WINRT_GENERIC_add21d46_17df_5a43_a685_3262fce84643
template <> struct __declspec(uuid("add21d46-17df-5a43-a685-3262fce84643")) __declspec(novtable) AsyncOperationCompletedHandler<winrt::Windows::ApplicationModel::DataTransfer::DataPackageOperation> : impl_AsyncOperationCompletedHandler<winrt::Windows::ApplicationModel::DataTransfer::DataPackageOperation> {};
#endif


}

namespace Windows::ApplicationModel::DataTransfer::DragDrop::Core {

struct ICoreDragDropManager :
    Windows::IInspectable,
    impl::consume<ICoreDragDropManager>
{
    ICoreDragDropManager(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<ICoreDragDropManager>(m_ptr); }
};

struct ICoreDragDropManagerStatics :
    Windows::IInspectable,
    impl::consume<ICoreDragDropManagerStatics>
{
    ICoreDragDropManagerStatics(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<ICoreDragDropManagerStatics>(m_ptr); }
};

struct ICoreDragInfo :
    Windows::IInspectable,
    impl::consume<ICoreDragInfo>
{
    ICoreDragInfo(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<ICoreDragInfo>(m_ptr); }
};

struct ICoreDragInfo2 :
    Windows::IInspectable,
    impl::consume<ICoreDragInfo2>,
    impl::require<ICoreDragInfo2, Windows::ApplicationModel::DataTransfer::DragDrop::Core::ICoreDragInfo>
{
    ICoreDragInfo2(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<ICoreDragInfo2>(m_ptr); }
};

struct ICoreDragOperation :
    Windows::IInspectable,
    impl::consume<ICoreDragOperation>
{
    ICoreDragOperation(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<ICoreDragOperation>(m_ptr); }
};

struct ICoreDragOperation2 :
    Windows::IInspectable,
    impl::consume<ICoreDragOperation2>,
    impl::require<ICoreDragOperation2, Windows::ApplicationModel::DataTransfer::DragDrop::Core::ICoreDragOperation>
{
    ICoreDragOperation2(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<ICoreDragOperation2>(m_ptr); }
};

struct ICoreDragUIOverride :
    Windows::IInspectable,
    impl::consume<ICoreDragUIOverride>
{
    ICoreDragUIOverride(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<ICoreDragUIOverride>(m_ptr); }
};

struct ICoreDropOperationTarget :
    Windows::IInspectable,
    impl::consume<ICoreDropOperationTarget>
{
    ICoreDropOperationTarget(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<ICoreDropOperationTarget>(m_ptr); }
};

struct ICoreDropOperationTargetRequestedEventArgs :
    Windows::IInspectable,
    impl::consume<ICoreDropOperationTargetRequestedEventArgs>
{
    ICoreDropOperationTargetRequestedEventArgs(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<ICoreDropOperationTargetRequestedEventArgs>(m_ptr); }
};

}

}
