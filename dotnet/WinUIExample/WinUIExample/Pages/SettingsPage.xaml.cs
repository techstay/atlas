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

// To learn more about WinUI, the WinUI project structure,
// and more about our project templates, see: http://aka.ms/winui-project-info.

namespace WinUIExample.Pages
{
    /// <summary>
    /// An empty page that can be used on its own or navigated to within a Frame.
    /// </summary>
    public sealed partial class SettingsPage : Page
    {
        public SettingsPage()
        {
            this.InitializeComponent();
        }

        readonly List<string> SystemBackdropOptions = ["Mica", "Acrylic", "None"];
        readonly List<string> ApplicationThemeOptions = ["Light", "Dark"];
        Settings Settings { get; set; } = new();

        private void SystemBackdropRadioButtons_SelectionChanged(object sender, SelectionChangedEventArgs e)
        {
            var selectedItem = e.AddedItems[0] as string;
            var selectedIndex = SystemBackdropOptions.IndexOf(selectedItem);
            var mainWindow = (Application.Current as App).MainWindow;
            mainWindow.SystemBackdrop = selectedIndex switch
            {
                0 => new MicaBackdrop(),
                1 => new DesktopAcrylicBackdrop(),
                _ => null
            };

            Settings.SystemBackdrop = selectedItem;
        }


    }
}

record Settings
{
    public string SystemBackdrop { get; set; } = "None";

}
