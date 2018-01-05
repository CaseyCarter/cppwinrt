//
// MainPage.xaml.h
// Declaration of the MainPage class.
//

#pragma once

#include "MainPage.g.h"

namespace winrt::$projectname$::implementation
{
    struct MainPage : MainPageT<MainPage>
    {
        MainPage();

        void ClickHandler(IInspectable const& sender, ::winrt::Windows::UI::Xaml::RoutedEventArgs const& e);
    };
}

namespace winrt::$projectname$::factory_implementation
{
    struct MainPage : MainPageT<MainPage, implementation::MainPage>
    {
    };
}
