// C++ for the Windows Runtime v1.0.private
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "Windows.UI.Xaml.Interop.1.h"

WINRT_EXPORT namespace winrt {

namespace Windows::UI::Xaml::Interop {

struct BindableVectorChangedEventHandler : Windows::IUnknown
{
    BindableVectorChangedEventHandler(std::nullptr_t = nullptr) noexcept {}
    template <typename L> BindableVectorChangedEventHandler(L lambda);
    template <typename F> BindableVectorChangedEventHandler (F * function);
    template <typename O, typename M> BindableVectorChangedEventHandler(O * object, M method);
    void operator()(const Windows::UI::Xaml::Interop::IBindableObservableVector & vector, const Windows::IInspectable & e) const;
};

struct NotifyCollectionChangedEventHandler : Windows::IUnknown
{
    NotifyCollectionChangedEventHandler(std::nullptr_t = nullptr) noexcept {}
    template <typename L> NotifyCollectionChangedEventHandler(L lambda);
    template <typename F> NotifyCollectionChangedEventHandler (F * function);
    template <typename O, typename M> NotifyCollectionChangedEventHandler(O * object, M method);
    void operator()(const Windows::IInspectable & sender, const Windows::UI::Xaml::Interop::NotifyCollectionChangedEventArgs & e) const;
};

struct IBindableIterable :
    Windows::IInspectable,
    impl::consume<IBindableIterable>
{
    IBindableIterable(std::nullptr_t = nullptr) noexcept {}
};

struct IBindableIterator :
    Windows::IInspectable,
    impl::consume<IBindableIterator>
{
    IBindableIterator(std::nullptr_t = nullptr) noexcept {}
};

struct IBindableObservableVector :
    Windows::IInspectable,
    impl::consume<IBindableObservableVector>,
    impl::require<IBindableObservableVector, Windows::UI::Xaml::Interop::IBindableIterable, Windows::UI::Xaml::Interop::IBindableVector>
{
    IBindableObservableVector(std::nullptr_t = nullptr) noexcept {}
};

struct IBindableVector :
    Windows::IInspectable,
    impl::consume<IBindableVector>,
    impl::require<IBindableVector, Windows::UI::Xaml::Interop::IBindableIterable>
{
    IBindableVector(std::nullptr_t = nullptr) noexcept {}
};

struct IBindableVectorView :
    Windows::IInspectable,
    impl::consume<IBindableVectorView>,
    impl::require<IBindableVectorView, Windows::UI::Xaml::Interop::IBindableIterable>
{
    IBindableVectorView(std::nullptr_t = nullptr) noexcept {}
};

struct INotifyCollectionChanged :
    Windows::IInspectable,
    impl::consume<INotifyCollectionChanged>
{
    INotifyCollectionChanged(std::nullptr_t = nullptr) noexcept {}
};

struct INotifyCollectionChangedEventArgs :
    Windows::IInspectable,
    impl::consume<INotifyCollectionChangedEventArgs>
{
    INotifyCollectionChangedEventArgs(std::nullptr_t = nullptr) noexcept {}
};

struct INotifyCollectionChangedEventArgsFactory :
    Windows::IInspectable,
    impl::consume<INotifyCollectionChangedEventArgsFactory>
{
    INotifyCollectionChangedEventArgsFactory(std::nullptr_t = nullptr) noexcept {}
};

}

}
