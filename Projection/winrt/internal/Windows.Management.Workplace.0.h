// C++ for the Windows Runtime v1.0.private
// Copyright (c) 2016 Microsoft Corporation

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

enum class MessagingSyncPolicy
{
    Disallowed = 0,
    Allowed = 1,
    Required = 2,
};

}

}
