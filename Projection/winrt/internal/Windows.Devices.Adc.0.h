// C++ for the Windows Runtime v1.0.private
// Copyright (c) 2016 Microsoft Corporation

#pragma once


WINRT_EXPORT namespace winrt {

namespace ABI::Windows::Devices::Adc {

struct IAdcChannel;
struct IAdcController;
struct IAdcControllerStatics;
struct IAdcControllerStatics2;
struct AdcChannel;
struct AdcController;

}

namespace Windows::Devices::Adc {

struct IAdcChannel;
struct IAdcController;
struct IAdcControllerStatics;
struct IAdcControllerStatics2;
struct AdcChannel;
struct AdcController;

}

namespace Windows::Devices::Adc {

enum class AdcChannelMode
{
    SingleEnded = 0,
    Differential = 1,
};

}

}
