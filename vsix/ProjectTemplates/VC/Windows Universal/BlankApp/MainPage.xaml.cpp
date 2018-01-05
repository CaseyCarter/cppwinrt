#include "pch.h"
#include "MainPage.xaml.h"

using namespace winrt;
using namespace Windows::UI::Xaml;

namespace winrt::$projectname$::implementation
{
    MainPage::MainPage()
    {
        InitializeComponent();
    }

    void MainPage::ClickHandler(IInspectable const&, RoutedEventArgs const&)
    {
        Button().Content(box_value(L"Clicked"));
    }
}
