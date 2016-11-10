// C++ for the Windows Runtime v1.0.private
// Copyright (c) 2016 Microsoft Corporation. All rights reserved.

#pragma once

#include "Windows.UI.Text.1.h"

WINRT_EXPORT namespace winrt {

namespace Windows::UI::Text {

struct IFontWeights :
    Windows::IInspectable,
    impl::consume<IFontWeights>
{
    IFontWeights(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IFontWeights>(m_ptr); }
};

struct IFontWeightsStatics :
    Windows::IInspectable,
    impl::consume<IFontWeightsStatics>
{
    IFontWeightsStatics(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IFontWeightsStatics>(m_ptr); }
};

struct ITextCharacterFormat :
    Windows::IInspectable,
    impl::consume<ITextCharacterFormat>
{
    ITextCharacterFormat(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<ITextCharacterFormat>(m_ptr); }
};

struct ITextConstantsStatics :
    Windows::IInspectable,
    impl::consume<ITextConstantsStatics>
{
    ITextConstantsStatics(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<ITextConstantsStatics>(m_ptr); }
};

struct ITextDocument :
    Windows::IInspectable,
    impl::consume<ITextDocument>
{
    ITextDocument(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<ITextDocument>(m_ptr); }
};

struct ITextParagraphFormat :
    Windows::IInspectable,
    impl::consume<ITextParagraphFormat>
{
    ITextParagraphFormat(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<ITextParagraphFormat>(m_ptr); }
};

struct ITextRange :
    Windows::IInspectable,
    impl::consume<ITextRange>
{
    ITextRange(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<ITextRange>(m_ptr); }
};

struct ITextSelection :
    Windows::IInspectable,
    impl::consume<ITextSelection>,
    impl::require<ITextSelection, Windows::UI::Text::ITextRange>
{
    ITextSelection(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<ITextSelection>(m_ptr); }
};

}

}
