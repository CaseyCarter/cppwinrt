#pragma once

#include "module.h"
#include "Language.g.h"

namespace winrt::Complex::Authoring::implementation
{
    struct Language : LanguageT<Language>
    {
        Language() = default;

        hstring Français();
    };

    struct LanguageFactory : LanguageFactoryT<LanguageFactory, Language>
    {
    };
}
