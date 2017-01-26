// C++ for the Windows Runtime v1.0.private
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "Windows.UI.Xaml.Navigation.1.h"
#include "Windows.UI.Xaml.1.h"
#include "Windows.UI.Xaml.2.h"

WINRT_EXPORT namespace winrt {

namespace Windows::UI::Xaml::Navigation {

struct LoadCompletedEventHandler : Windows::IUnknown
{
    LoadCompletedEventHandler(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<LoadCompletedEventHandler>(m_ptr); }
    template <typename L> LoadCompletedEventHandler(L lambda);
    template <typename F> LoadCompletedEventHandler (F * function);
    template <typename O, typename M> LoadCompletedEventHandler(O * object, M method);
    void operator()(const Windows::IInspectable & sender, const Windows::UI::Xaml::Navigation::NavigationEventArgs & e) const;
};

struct NavigatedEventHandler : Windows::IUnknown
{
    NavigatedEventHandler(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<NavigatedEventHandler>(m_ptr); }
    template <typename L> NavigatedEventHandler(L lambda);
    template <typename F> NavigatedEventHandler (F * function);
    template <typename O, typename M> NavigatedEventHandler(O * object, M method);
    void operator()(const Windows::IInspectable & sender, const Windows::UI::Xaml::Navigation::NavigationEventArgs & e) const;
};

struct NavigatingCancelEventHandler : Windows::IUnknown
{
    NavigatingCancelEventHandler(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<NavigatingCancelEventHandler>(m_ptr); }
    template <typename L> NavigatingCancelEventHandler(L lambda);
    template <typename F> NavigatingCancelEventHandler (F * function);
    template <typename O, typename M> NavigatingCancelEventHandler(O * object, M method);
    void operator()(const Windows::IInspectable & sender, const Windows::UI::Xaml::Navigation::NavigatingCancelEventArgs & e) const;
};

struct NavigationFailedEventHandler : Windows::IUnknown
{
    NavigationFailedEventHandler(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<NavigationFailedEventHandler>(m_ptr); }
    template <typename L> NavigationFailedEventHandler(L lambda);
    template <typename F> NavigationFailedEventHandler (F * function);
    template <typename O, typename M> NavigationFailedEventHandler(O * object, M method);
    void operator()(const Windows::IInspectable & sender, const Windows::UI::Xaml::Navigation::NavigationFailedEventArgs & e) const;
};

struct NavigationStoppedEventHandler : Windows::IUnknown
{
    NavigationStoppedEventHandler(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<NavigationStoppedEventHandler>(m_ptr); }
    template <typename L> NavigationStoppedEventHandler(L lambda);
    template <typename F> NavigationStoppedEventHandler (F * function);
    template <typename O, typename M> NavigationStoppedEventHandler(O * object, M method);
    void operator()(const Windows::IInspectable & sender, const Windows::UI::Xaml::Navigation::NavigationEventArgs & e) const;
};

struct INavigatingCancelEventArgs :
    Windows::IInspectable,
    impl::consume<INavigatingCancelEventArgs>
{
    INavigatingCancelEventArgs(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<INavigatingCancelEventArgs>(m_ptr); }
};

struct INavigatingCancelEventArgs2 :
    Windows::IInspectable,
    impl::consume<INavigatingCancelEventArgs2>
{
    INavigatingCancelEventArgs2(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<INavigatingCancelEventArgs2>(m_ptr); }
};

struct INavigationEventArgs :
    Windows::IInspectable,
    impl::consume<INavigationEventArgs>
{
    INavigationEventArgs(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<INavigationEventArgs>(m_ptr); }
};

struct INavigationEventArgs2 :
    Windows::IInspectable,
    impl::consume<INavigationEventArgs2>
{
    INavigationEventArgs2(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<INavigationEventArgs2>(m_ptr); }
};

struct INavigationFailedEventArgs :
    Windows::IInspectable,
    impl::consume<INavigationFailedEventArgs>
{
    INavigationFailedEventArgs(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<INavigationFailedEventArgs>(m_ptr); }
};

struct IPageStackEntry :
    Windows::IInspectable,
    impl::consume<IPageStackEntry>
{
    IPageStackEntry(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IPageStackEntry>(m_ptr); }
};

struct IPageStackEntryFactory :
    Windows::IInspectable,
    impl::consume<IPageStackEntryFactory>
{
    IPageStackEntryFactory(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IPageStackEntryFactory>(m_ptr); }
};

struct IPageStackEntryStatics :
    Windows::IInspectable,
    impl::consume<IPageStackEntryStatics>
{
    IPageStackEntryStatics(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IPageStackEntryStatics>(m_ptr); }
};

}

}
