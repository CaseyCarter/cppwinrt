// C++ for the Windows Runtime v1.0.private
// Copyright (c) 2016 Microsoft Corporation. All rights reserved.

#pragma once

#include "Windows.Management.Workplace.1.h"

WINRT_EXPORT namespace winrt {

namespace Windows::Management::Workplace {

struct IMdmAllowPolicyStatics :
    Windows::IInspectable,
    impl::consume<IMdmAllowPolicyStatics>
{
    IMdmAllowPolicyStatics(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IMdmAllowPolicyStatics>(m_ptr); }
};

struct IMdmPolicyStatics2 :
    Windows::IInspectable,
    impl::consume<IMdmPolicyStatics2>
{
    IMdmPolicyStatics2(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IMdmPolicyStatics2>(m_ptr); }
};

}

}
