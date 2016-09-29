// C++ for the Windows Runtime v1.0.private
// Copyright (c) 2016 Microsoft Corporation

#pragma once

#include "Windows.Devices.Printers.Extensions.2.h"

WINRT_EXPORT namespace winrt {

namespace Windows::Devices::Printers::Extensions {

struct WINRT_EBO Print3DWorkflow :
    Windows::Devices::Printers::Extensions::IPrint3DWorkflow,
    impl::require<Print3DWorkflow, Windows::Devices::Printers::Extensions::IPrint3DWorkflow2>
{
    Print3DWorkflow(std::nullptr_t) noexcept {}
};

struct WINRT_EBO Print3DWorkflowPrintRequestedEventArgs :
    Windows::Devices::Printers::Extensions::IPrint3DWorkflowPrintRequestedEventArgs
{
    Print3DWorkflowPrintRequestedEventArgs(std::nullptr_t) noexcept {}
};

struct WINRT_EBO Print3DWorkflowPrinterChangedEventArgs :
    Windows::Devices::Printers::Extensions::IPrint3DWorkflowPrinterChangedEventArgs
{
    Print3DWorkflowPrinterChangedEventArgs(std::nullptr_t) noexcept {}
};

}

}
