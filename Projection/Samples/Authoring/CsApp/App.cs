using System;
using Windows.ApplicationModel.Activation;
using Windows.Foundation;
using Windows.UI;
using Windows.UI.Xaml;
using Windows.UI.Xaml.Controls;
using Windows.UI.Xaml.Media;
using Windows.UI.ViewManagement;
using System.Diagnostics;
using Farm.Animals;

class App : Application
{
    protected override void OnLaunched(LaunchActivatedEventArgs e)
    {
        TextBlock block = new TextBlock();

        block.FontFamily = new FontFamily("Segoe UI Semibold");
        block.FontSize = 96.0;
        block.Foreground = new SolidColorBrush(Colors.HotPink);
        block.VerticalAlignment = VerticalAlignment.Center;
        block.TextAlignment = TextAlignment.Center;

        var hen = new Hen();
        block.Text = hen.Français;

        Window window = Window.Current;
        window.Content = block;
        window.Activate();

        LayEgg(hen, block);
    }

    async void LayEgg(Hen hen, TextBlock block)
    {
        var operation = hen.LayEggAsync();

        operation.Progress = (sender, args) =>
        {
            Debug.WriteLine("Cooking {0}%", args);
        };

        block.Text = await operation;
    }

    static void Main()
    {
        ApplicationView.PreferredLaunchViewSize = new Size(1000, 600);
        ApplicationView.PreferredLaunchWindowingMode = ApplicationViewWindowingMode.PreferredLaunchViewSize;

        Application.Start(o =>
        {
            new App();
        });
    }
}
