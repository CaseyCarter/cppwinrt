// C++ for the Windows Runtime v1.0.private
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "Windows.Globalization.PhoneNumberFormatting.1.h"
#include "Windows.Foundation.1.h"

WINRT_EXPORT namespace winrt {

namespace Windows::Globalization::PhoneNumberFormatting {

struct IPhoneNumberFormatter :
    Windows::IInspectable,
    impl::consume<IPhoneNumberFormatter>
{
    IPhoneNumberFormatter(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IPhoneNumberFormatter>(m_ptr); }
};

struct IPhoneNumberFormatterStatics :
    Windows::IInspectable,
    impl::consume<IPhoneNumberFormatterStatics>
{
    IPhoneNumberFormatterStatics(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IPhoneNumberFormatterStatics>(m_ptr); }
};

struct IPhoneNumberInfo :
    Windows::IInspectable,
    impl::consume<IPhoneNumberInfo>
{
    IPhoneNumberInfo(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IPhoneNumberInfo>(m_ptr); }
};

struct IPhoneNumberInfoFactory :
    Windows::IInspectable,
    impl::consume<IPhoneNumberInfoFactory>
{
    IPhoneNumberInfoFactory(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IPhoneNumberInfoFactory>(m_ptr); }
};

struct IPhoneNumberInfoStatics :
    Windows::IInspectable,
    impl::consume<IPhoneNumberInfoStatics>
{
    IPhoneNumberInfoStatics(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IPhoneNumberInfoStatics>(m_ptr); }
};

}

}
