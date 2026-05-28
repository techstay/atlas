using Microsoft.UI.Xaml;
using Microsoft.UI.Xaml.Controls;
using Microsoft.UI.Xaml.Controls.Primitives;
using Microsoft.UI.Xaml.Data;
using Microsoft.UI.Xaml.Input;
using Microsoft.UI.Xaml.Media;
using Microsoft.UI.Xaml.Navigation;
using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Runtime.InteropServices.WindowsRuntime;
using Windows.Foundation;
using Windows.Foundation.Collections;
using WinUIExample.Pages;
using Windows.Storage;

// To learn more about WinUI, the WinUI project structure,
// and more about our project templates, see: http://aka.ms/winui-project-info.

namespace WinUIExample;

/// <summary>
/// An empty window that can be used on its own or navigated to within a Frame.
/// </summary>
public sealed partial class MainWindow : Window
{
    public MainWindow()
    {
        this.InitializeComponent();
        ExtendsContentIntoTitleBar = true;

        var saved = ApplicationData.Current.LocalSettings.Values["SystemBackdrop"] as string ?? "None";
        SystemBackdrop = saved switch
        {
            "Mica" => new MicaBackdrop(),
            "Acrylic" => new DesktopAcrylicBackdrop(),
            _ => null
        };

        // Apply saved app theme to the root content
        var savedTheme = ApplicationData.Current.LocalSettings.Values["AppTheme"] as string ?? "Auto";
        if (Content is FrameworkElement root)
        {
            root.RequestedTheme = savedTheme switch
            {
                "Light" => ElementTheme.Light,
                "Dark" => ElementTheme.Dark,
                _ => ElementTheme.Default
            };
        }
    }

    private void NavigationView_Loaded(object sender, RoutedEventArgs e)
    {
        NavigationView.SelectedItem = NavigationView.MenuItems[0];
    }

    private void NavigationView_SelectionChanged(NavigationView sender, NavigationViewSelectionChangedEventArgs args)
    {
        if (args.IsSettingsSelected)
        {
            ContentFrame.Navigate(typeof(SettingsPage), args.RecommendedNavigationTransitionInfo);
        }
        else if (args.SelectedItemContainer != null)
        {
            NavigationView.Header = args.SelectedItemContainer.Content.ToString();
            Type navigationType = Type.GetType(args.SelectedItemContainer.Tag.ToString());
            ContentFrame.Navigate(navigationType, args.RecommendedNavigationTransitionInfo);
        }
    }

    private void NavigationView_BackRequested(NavigationView sender, NavigationViewBackRequestedEventArgs args)
    {
        ContentFrame.GoBack();
    }
}

