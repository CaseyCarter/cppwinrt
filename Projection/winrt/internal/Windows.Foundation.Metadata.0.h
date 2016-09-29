// C++ for the Windows Runtime v1.0.private
// Copyright (c) 2016 Microsoft Corporation

#pragma once


WINRT_EXPORT namespace winrt {

namespace ABI::Windows::Foundation::Metadata {

struct IApiInformationStatics;

}

namespace Windows::Foundation::Metadata {

struct IApiInformationStatics;
struct ApiInformation;

}

namespace Windows::Foundation::Metadata {

enum class GCPressureAmount
{
    Low = 0,
    Medium = 1,
    High = 2,
};

}

}
