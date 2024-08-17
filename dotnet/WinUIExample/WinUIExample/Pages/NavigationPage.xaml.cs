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
using Microsoft.UI.Xaml.Media.Animation;

// To learn more about WinUI, the WinUI project structure,
// and more about our project templates, see: http://aka.ms/winui-project-info.

namespace WinUIExample.Pages
{
    /// <summary>
    /// An empty page that can be used on its own or navigated to within a Frame.
    /// </summary>
    public sealed partial class NavigationPage : Page
    {
        private int previousSelectedIndex = 0;

        public NavigationPage()
        {
            this.InitializeComponent();
            BreadcrumbBar1.ItemsSource = new string[] { "Home", "Folder1", "Item1", "Folder2", "Item2" };
        }

        private void SelectorBar1_SelectionChanged(SelectorBar sender, SelectorBarSelectionChangedEventArgs args)
        {
            SelectorBarItem selectedItem = sender.SelectedItem;
            int currentSelectedIndex = sender.Items.IndexOf(selectedItem);
            System.Type pageType = currentSelectedIndex switch
            {
                0 => typeof(BasicControlsPage),
                1 => typeof(LayoutsPage),
                2 => typeof(StylesPage),
                _ => typeof(StylesPage),
            };

            var transitionEffect = currentSelectedIndex > previousSelectedIndex ? SlideNavigationTransitionEffect.FromRight : SlideNavigationTransitionEffect.FromLeft;
            SelectorBarContentFrame.Navigate(pageType, null, new SlideNavigationTransitionInfo() { Effect = transitionEffect });
            previousSelectedIndex = currentSelectedIndex;
        }
    }
}
