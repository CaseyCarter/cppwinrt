// C++ for the Windows Runtime v1.0.private
// Copyright (c) 2016 Microsoft Corporation. All rights reserved.

#pragma once

#include "Windows.Media.ContentRestrictions.2.h"

WINRT_EXPORT namespace winrt {

namespace Windows::Media::ContentRestrictions {

struct WINRT_EBO ContentRestrictionsBrowsePolicy :
    Windows::Media::ContentRestrictions::IContentRestrictionsBrowsePolicy
{
    ContentRestrictionsBrowsePolicy(std::nullptr_t) noexcept {}
};

struct WINRT_EBO RatedContentDescription :
    Windows::Media::ContentRestrictions::IRatedContentDescription
{
    RatedContentDescription(std::nullptr_t) noexcept {}
    RatedContentDescription(hstring_ref id, hstring_ref title, Windows::Media::ContentRestrictions::RatedContentCategory category);
};

struct WINRT_EBO RatedContentRestrictions :
    Windows::Media::ContentRestrictions::IRatedContentRestrictions
{
    RatedContentRestrictions(std::nullptr_t) noexcept {}
    RatedContentRestrictions();
    RatedContentRestrictions(uint32_t maxAgeRating);
};

}

}
