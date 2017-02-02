// C++ for the Windows Runtime v1.0.private
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "Windows.System.Threading.1.h"

WINRT_EXPORT namespace winrt {

namespace Windows::System::Threading {

struct TimerDestroyedHandler : Windows::IUnknown
{
    TimerDestroyedHandler(std::nullptr_t = nullptr) noexcept {}
    template <typename L> TimerDestroyedHandler(L lambda);
    template <typename F> TimerDestroyedHandler (F * function);
    template <typename O, typename M> TimerDestroyedHandler(O * object, M method);
    void operator()(const Windows::System::Threading::ThreadPoolTimer & timer) const;
};

struct TimerElapsedHandler : Windows::IUnknown
{
    TimerElapsedHandler(std::nullptr_t = nullptr) noexcept {}
    template <typename L> TimerElapsedHandler(L lambda);
    template <typename F> TimerElapsedHandler (F * function);
    template <typename O, typename M> TimerElapsedHandler(O * object, M method);
    void operator()(const Windows::System::Threading::ThreadPoolTimer & timer) const;
};

struct WorkItemHandler : Windows::IUnknown
{
    WorkItemHandler(std::nullptr_t = nullptr) noexcept {}
    template <typename L> WorkItemHandler(L lambda);
    template <typename F> WorkItemHandler (F * function);
    template <typename O, typename M> WorkItemHandler(O * object, M method);
    void operator()(const Windows::Foundation::IAsyncAction & operation) const;
};

struct IThreadPoolStatics :
    Windows::IInspectable,
    impl::consume<IThreadPoolStatics>
{
    IThreadPoolStatics(std::nullptr_t = nullptr) noexcept {}
};

struct IThreadPoolTimer :
    Windows::IInspectable,
    impl::consume<IThreadPoolTimer>
{
    IThreadPoolTimer(std::nullptr_t = nullptr) noexcept {}
};

struct IThreadPoolTimerStatics :
    Windows::IInspectable,
    impl::consume<IThreadPoolTimerStatics>
{
    IThreadPoolTimerStatics(std::nullptr_t = nullptr) noexcept {}
};

}

}
