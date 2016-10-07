#include "pch.h"

using namespace winrt;

using namespace Windows::ApplicationModel::Activation;
using namespace Windows::UI;
using namespace Windows::UI::Xaml;
using namespace Windows::UI::Xaml::Controls;
using namespace Windows::UI::Xaml::Media;

struct App : ApplicationT<App>
{
public:

    void OnLaunched(LaunchActivatedEventArgs const &)
    {
        TextBlock text;

        text.Text(L"C++ for the Windows Runtime");
        text.FontFamily(FontFamily(L"Segoe UI Semibold"));
        text.FontSize(72.0);
        text.Foreground(SolidColorBrush(Colors::DarkGray()));
        text.VerticalAlignment(VerticalAlignment::Center);
        text.TextAlignment(TextAlignment::Center);
        text.TextWrapping(TextWrapping::Wrap);

        Window window = Window::Current();
        window.Content(text);
        window.Activate();
    }
};

int __stdcall wWinMain(HINSTANCE, HINSTANCE, PWSTR, int)
{
    Application::Start([](auto &&)
    {
        make<App>();
    });
}