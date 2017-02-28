// C++ for the Windows Runtime v1.0.private
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once


WINRT_EXPORT namespace winrt {

namespace ABI::Windows::Management::Workplace {

struct IMdmAllowPolicyStatics;
struct IMdmPolicyStatics2;

}

namespace Windows::Management::Workplace {

struct IMdmAllowPolicyStatics;
struct IMdmPolicyStatics2;
struct MdmPolicy;

}

namespace Windows::Management::Workplace {

template <typename T> struct impl_IMdmAllowPolicyStatics;
template <typename T> struct impl_IMdmPolicyStatics2;

}

namespace Windows::Management::Workplace {

enum class MessagingSyncPolicy
{
    Disallowed = 0,
    Allowed = 1,
    Required = 2,
};

}

}
