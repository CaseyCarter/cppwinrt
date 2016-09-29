// C++ for the Windows Runtime v1.0.private
// Copyright (c) 2016 Microsoft Corporation

#pragma once

#include "Windows.Perception.People.2.h"

WINRT_EXPORT namespace winrt {

namespace Windows::Perception::People {

struct WINRT_EBO HeadPose :
    Windows::Perception::People::IHeadPose
{
    HeadPose(std::nullptr_t) noexcept {}
};

}

}
