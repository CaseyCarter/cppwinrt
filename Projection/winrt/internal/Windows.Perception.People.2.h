// C++ for the Windows Runtime v1.0.private
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "Windows.Perception.People.1.h"

WINRT_EXPORT namespace winrt {

namespace Windows::Perception::People {

struct IHeadPose :
    Windows::IInspectable,
    impl::consume<IHeadPose>
{
    IHeadPose(std::nullptr_t = nullptr) noexcept {}
};

}

}
