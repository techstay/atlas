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
using Windows.Storage;

// To learn more about WinUI, the WinUI project structure,
// and more about our project templates, see: http://aka.ms/winui-project-info.

namespace WinUIExample.Pages;

/// <summary>
/// An empty page that can be used on its own or navigated to within a Frame.
/// </summary>
public sealed partial class SettingsPage : Page
{
    public SettingsPage()
    {
        var localSettings = ApplicationData.Current.LocalSettings;
        var savedBackdrop = localSettings.Values["SystemBackdrop"] as string ?? "None";
        // Ensure the initial selection reflects the saved value so we don't momentarily switch to "None".
        SystemBackdrop = savedBackdrop;

        var savedTheme = localSettings.Values["AppTheme"] as string ?? "Auto";
        ApplicationTheme = savedTheme;
        this.InitializeComponent();
    }

    public string SystemBackdrop { get; set; } = "None";
    public string ApplicationTheme { get; set; } = "Auto";

    readonly List<string> SystemBackdropOptions = ["Mica", "Acrylic", "None"];
    readonly List<string> ApplicationThemeOptions = ["Light", "Dark", "Auto"];

    private void SystemBackdropRadioButtons_SelectionChanged(object sender, SelectionChangedEventArgs e)
    {
        var localSettings = ApplicationData.Current.LocalSettings;
        if (e.AddedItems == null || e.AddedItems.Count == 0)
        {
            return;
        }
        var selectedItem = e.AddedItems[0] as string;
        if (string.IsNullOrEmpty(selectedItem))
        {
            return;
        }
        if (selectedItem == localSettings.Values["SystemBackdrop"] as string)
        {
            return;
        }
        var selectedIndex = SystemBackdropOptions.IndexOf(selectedItem);
        var mainWindow = (Application.Current as App).MainWindow;
        mainWindow.SystemBackdrop = selectedIndex switch
        {
            0 => new MicaBackdrop(),
            1 => new DesktopAcrylicBackdrop(),
            _ => null
        };
        localSettings.Values["SystemBackdrop"] = selectedItem;
    }

    private void ApplicationThemeRadioButtons_SelectionChanged(object sender, SelectionChangedEventArgs e)
    {
        var localSettings = ApplicationData.Current.LocalSettings;
        if (e.AddedItems == null || e.AddedItems.Count == 0)
        {
            return;
        }
        var selectedItem = e.AddedItems[0] as string;
        if (string.IsNullOrEmpty(selectedItem))
        {
            return;
        }
        if (selectedItem == localSettings.Values["AppTheme"] as string)
        {
            return;
        }

        // Apply to the window's root content so it updates immediately.
        var mainWindow = (Application.Current as App).MainWindow;
        if (mainWindow.Content is FrameworkElement root)
        {
            root.RequestedTheme = selectedItem switch
            {
                "Light" => ElementTheme.Light,
                "Dark" => ElementTheme.Dark,
                _ => ElementTheme.Default
            };
        }

        localSettings.Values["AppTheme"] = selectedItem;
    }
}
