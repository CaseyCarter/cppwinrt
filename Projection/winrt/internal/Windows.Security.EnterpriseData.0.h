// C++ for the Windows Runtime v1.0.private
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once


WINRT_EXPORT namespace winrt {

namespace Windows::Security::Cryptography::DataProtection {


}

namespace Windows::Security::EnterpriseData {

enum class ProtectionPolicyEvaluationResult
{
    Allowed = 0,
    Blocked = 1,
    ConsentRequired = 2,
};

}

}