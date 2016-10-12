// C++ for the Windows Runtime v1.0.private
// Copyright (c) 2016 Microsoft Corporation. All rights reserved.

#pragma once


WINRT_EXPORT namespace winrt {

namespace ABI::Windows::Devices::Printers::Extensions {

struct IPrint3DWorkflow;
struct IPrint3DWorkflow2;
struct IPrint3DWorkflowPrintRequestedEventArgs;
struct IPrint3DWorkflowPrinterChangedEventArgs;
struct Print3DWorkflow;
struct Print3DWorkflowPrintRequestedEventArgs;
struct Print3DWorkflowPrinterChangedEventArgs;

}

namespace Windows::Devices::Printers::Extensions {

struct IPrint3DWorkflow;
struct IPrint3DWorkflow2;
struct IPrint3DWorkflowPrintRequestedEventArgs;
struct IPrint3DWorkflowPrinterChangedEventArgs;
struct Print3DWorkflow;
struct Print3DWorkflowPrintRequestedEventArgs;
struct Print3DWorkflowPrinterChangedEventArgs;

}

namespace Windows::Devices::Printers::Extensions {

enum class Print3DWorkflowDetail
{
    Unknown = 0,
    ModelExceedsPrintBed = 1,
    UploadFailed = 2,
    InvalidMaterialSelection = 3,
    InvalidModel = 4,
    ModelNotManifold = 5,
    InvalidPrintTicket = 6,
};

enum class Print3DWorkflowStatus
{
    Abandoned = 0,
    Canceled = 1,
    Failed = 2,
    Slicing = 3,
    Submitted = 4,
};

}

}
