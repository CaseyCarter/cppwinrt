// C++ for the Windows Runtime v1.0.private
// Copyright (c) 2016 Microsoft Corporation. All rights reserved.

#pragma once

#include "Windows.System.Power.Diagnostics.1.h"

WINRT_EXPORT namespace winrt {

namespace Windows::System::Power::Diagnostics {

struct IBackgroundEnergyDiagnosticsStatics :
    Windows::IInspectable,
    impl::consume<IBackgroundEnergyDiagnosticsStatics>
{
    IBackgroundEnergyDiagnosticsStatics(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IBackgroundEnergyDiagnosticsStatics>(m_ptr); }
};

struct IForegroundEnergyDiagnosticsStatics :
    Windows::IInspectable,
    impl::consume<IForegroundEnergyDiagnosticsStatics>
{
    IForegroundEnergyDiagnosticsStatics(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IForegroundEnergyDiagnosticsStatics>(m_ptr); }
};

}

}
