// C++ for the Windows Runtime v1.0.private
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "Windows.Data.Xml.Xsl.1.h"

WINRT_EXPORT namespace winrt {

namespace Windows::Data::Xml::Xsl {

struct IXsltProcessor :
    Windows::IInspectable,
    impl::consume<IXsltProcessor>
{
    IXsltProcessor(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IXsltProcessor>(m_ptr); }
};

struct IXsltProcessor2 :
    Windows::IInspectable,
    impl::consume<IXsltProcessor2>
{
    IXsltProcessor2(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IXsltProcessor2>(m_ptr); }
};

struct IXsltProcessorFactory :
    Windows::IInspectable,
    impl::consume<IXsltProcessorFactory>
{
    IXsltProcessorFactory(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IXsltProcessorFactory>(m_ptr); }
};

}

}
