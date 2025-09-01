using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Runtime.InteropServices.WindowsRuntime;
using Windows.Foundation;
using Windows.Foundation.Collections;
using Microsoft.UI.Xaml;
using Microsoft.UI.Xaml.Controls;
using Microsoft.UI.Xaml.Controls.Primitives;
using Microsoft.UI.Xaml.Data;
using Microsoft.UI.Xaml.Input;
using Microsoft.UI.Xaml.Media;
using Microsoft.UI.Xaml.Navigation;
using System.Collections.ObjectModel;

// To learn more about WinUI, the WinUI project structure,
// and more about our project templates, see: http://aka.ms/winui-project-info.

namespace WinUIExample.Pages;

/// <summary>
/// An empty page that can be used on its own or navigated to within a Frame.
/// </summary>
public sealed partial class LocalizationsPage : Page
{
    public LocalizationsPage()
    {
        this.InitializeComponent();
    }
    public ObservableCollection<string> LocaleOptions { get; } = ["zh-CN", "en-US", "ja-JP",];

    private void RadioButtonsChangeLocale_SelectionChanged(object sender, SelectionChangedEventArgs e)
    {
        var radioButtons = sender as RadioButtons;
        if (radioButtons != null && radioButtons.SelectedItem is string)
        {
            var locale = radioButtons.SelectedItem as string;
            var resourceContext = new Windows.ApplicationModel.Resources.Core.ResourceContext();
            resourceContext.Languages = new string[] { locale };
            var resourceMap = Windows.ApplicationModel.Resources.Core.ResourceManager.Current.MainResourceMap.GetSubtree("Resources");
            TextBlockChangeLocale.Text = resourceMap.GetValue("ChangeLocale", resourceContext).ValueAsString;
            TextBlockGreeting.Text = resourceMap.GetValue("Greeting", resourceContext).ValueAsString;
        }
    }
}
