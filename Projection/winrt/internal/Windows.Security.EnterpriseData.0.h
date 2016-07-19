// C++ for the Windows Runtime v1.29
// Copyright (c) 2016 Microsoft Corporation

#pragma once


WINRT_EXPORT namespace winrt {

namespace Windows::Security::EnterpriseData {

enum class ProtectionPolicyEvaluationResult
{
    Allowed = 0,
    Blocked = 1,
    ConsentRequired = 2,
};

}

}
