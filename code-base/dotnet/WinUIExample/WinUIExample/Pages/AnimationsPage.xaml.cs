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
public sealed partial class AnimationsPage : Page
{
    public AnimationsPage()
    {
        this.InitializeComponent();
    }

    private void ButtonStoryboard1_Click(object sender, RoutedEventArgs e)
    {
        if (Storyboard1.GetCurrentState() == ClockState.Stopped)
        {
            Storyboard1.Begin();
        }
        else
        {
            Storyboard1.Stop();
        }
    }

    private void ButtonStoryboard2_Click(object sender, RoutedEventArgs e)
    {
        if (Storyboard2.GetCurrentState() == ClockState.Stopped)
        {
            Storyboard2.Begin();
        }
        else
        {
            Storyboard2.Stop();
        }
    }

    private void ButtonStoryboard3_Click(object sender, RoutedEventArgs e)
    {
        if (Storyboard3.GetCurrentState() == ClockState.Stopped)
        {
            Storyboard3.Begin();
        }
        else
        {
            Storyboard3.Stop();
        }
    }
}
