// C++ for the Windows Runtime v1.0.private
// Copyright (c) 2016 Microsoft Corporation. All rights reserved.

#pragma once

#include "Windows.System.Power.1.h"

WINRT_EXPORT namespace winrt {

namespace ABI::Windows::Foundation {

#ifndef WINRT_GENERIC_c50898f6_c536_5f47_8583_8b2c2438a13b
#define WINRT_GENERIC_c50898f6_c536_5f47_8583_8b2c2438a13b
template <> struct __declspec(uuid("c50898f6-c536-5f47-8583-8b2c2438a13b")) __declspec(novtable) EventHandler<Windows::IInspectable> : impl_EventHandler<Windows::IInspectable> {};
#endif


}

namespace Windows::System::Power {

struct IBackgroundEnergyManagerStatics :
    Windows::IInspectable,
    impl::consume<IBackgroundEnergyManagerStatics>
{
    IBackgroundEnergyManagerStatics(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IBackgroundEnergyManagerStatics>(m_ptr); }
};

struct IForegroundEnergyManagerStatics :
    Windows::IInspectable,
    impl::consume<IForegroundEnergyManagerStatics>
{
    IForegroundEnergyManagerStatics(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IForegroundEnergyManagerStatics>(m_ptr); }
};

struct IPowerManagerStatics :
    Windows::IInspectable,
    impl::consume<IPowerManagerStatics>
{
    IPowerManagerStatics(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IPowerManagerStatics>(m_ptr); }
};

}

}
