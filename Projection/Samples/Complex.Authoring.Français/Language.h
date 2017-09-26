#pragma once

#include "Language.g.h"

namespace winrt::Complex::Authoring::implementation
{
    struct Language : LanguageT<Language>
    {
        Language() = default;

        hstring Français();
    };
}

namespace winrt::Complex::Authoring::factory_implementation
{
    struct Language : LanguageT<Language, implementation::Language>
    {
    };
}
