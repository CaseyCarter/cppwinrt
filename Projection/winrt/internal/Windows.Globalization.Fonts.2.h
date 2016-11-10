// C++ for the Windows Runtime v1.0.private
// Copyright (c) 2016 Microsoft Corporation. All rights reserved.

#pragma once

#include "Windows.Globalization.Fonts.1.h"

WINRT_EXPORT namespace winrt {

namespace Windows::Globalization::Fonts {

struct ILanguageFont :
    Windows::IInspectable,
    impl::consume<ILanguageFont>
{
    ILanguageFont(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<ILanguageFont>(m_ptr); }
};

struct ILanguageFontGroup :
    Windows::IInspectable,
    impl::consume<ILanguageFontGroup>
{
    ILanguageFontGroup(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<ILanguageFontGroup>(m_ptr); }
};

struct ILanguageFontGroupFactory :
    Windows::IInspectable,
    impl::consume<ILanguageFontGroupFactory>
{
    ILanguageFontGroupFactory(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<ILanguageFontGroupFactory>(m_ptr); }
};

}

}
