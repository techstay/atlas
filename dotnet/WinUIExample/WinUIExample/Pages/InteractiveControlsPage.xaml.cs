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
    public sealed partial class InteractiveControlsPage : Page
    {
        public InteractiveControlsPage()
        {
            this.InitializeComponent();
        }
        private void TeachingTipButton_Click(object sender, RoutedEventArgs e)
        {
            TeachingTip1.IsOpen = true;
        }

        private async void ShowDialogButton_Click(object sender, RoutedEventArgs e)
        {
            var dialog = new ContentDialog
            {
                Title = "Dialog Title",
                Content = "Dialog Content",
                PrimaryButtonText = "Yes",
                SecondaryButtonText = "No",
                CloseButtonText = "Cancel",
                DefaultButton = ContentDialogButton.Primary,
                XamlRoot = this.XamlRoot
            };

            var result = await dialog.ShowAsync();
            if (result == ContentDialogResult.Primary)
            {
                DialogText.Text = "User clicked Yes";
            }
            else if (result == ContentDialogResult.Secondary)
            {
                DialogText.Text = "User clicked No";
            }
            else
            {
                DialogText.Text = "User clicked Cancel";
            }
        }

    }
}
