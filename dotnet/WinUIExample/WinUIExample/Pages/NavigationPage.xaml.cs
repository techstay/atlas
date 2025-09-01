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

namespace WinUIExample.Pages;

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
            0 => typeof(SamplePage1),
            1 => typeof(SamplePage2),
            2 => typeof(SamplePage3),
            _ => typeof(SamplePage2),
        };

        var transitionEffect = currentSelectedIndex > previousSelectedIndex ? SlideNavigationTransitionEffect.FromRight : SlideNavigationTransitionEffect.FromLeft;
        SelectorBarContentFrame.Navigate(pageType, null, new SlideNavigationTransitionInfo() { Effect = transitionEffect });
        previousSelectedIndex = currentSelectedIndex;
    }

    private void TabView_AddTabButtonClick(TabView sender, object args)
    {
        sender.TabItems.Add(CreateNewTab(sender.TabItems.Count));
    }

    private void TabView_TabCloseRequested(TabView sender, TabViewTabCloseRequestedEventArgs args)
    {
        (sender as TabView).TabItems.Remove(args.Tab);
    }

    private void TabView_Loaded(object sender, RoutedEventArgs e)
    {
        for (int i = 0; i < 3; i++)
        {
            (sender as TabView).TabItems.Add(CreateNewTab(i));
        }
    }

    private TabViewItem CreateNewTab(int index)
    {
        TabViewItem tab = new TabViewItem();
        tab.Header = $"Tab {index + 1}";
        tab.IconSource = new Microsoft.UI.Xaml.Controls.SymbolIconSource() { Symbol = Symbol.Document };

        Frame frame = new Frame();
        switch (index % 3)
        {
            case 0:
                frame.Navigate(typeof(SamplePage1));
                break;
            case 1:
                frame.Navigate(typeof(SamplePage2));
                break;
            case 2:
                frame.Navigate(typeof(SamplePage3));
                break;
        }
        tab.Content = frame;
        return tab;
    }
}
