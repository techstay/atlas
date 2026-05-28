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

namespace WinUIExample.Pages;

/// <summary>
/// An empty page that can be used on its own or navigated to within a Frame.
/// </summary>
public sealed partial class BasicControlsPage : Page
{
    private int _button1Value = 0;
    private int _repeatButton1Value = 0;
    private bool _toggleButtonValue = false;

    public BasicControlsPage()
    {
        this.InitializeComponent();
    }

    private void Button1_Click(object sender, RoutedEventArgs e)
    {
        Button1.Content = $"Button: {++_button1Value}";
    }

    private void RepeatButton1_Click(object sender, RoutedEventArgs e)
    {
        RepeatButton1.Content = $"RepeatButton: {++_repeatButton1Value}";
    }

    private void ToggleButton1_Click(object sender, RoutedEventArgs e)
    {
        _toggleButtonValue = !_toggleButtonValue;
        ToggleButton1.Content = $"""ToggleButton: {(_toggleButtonValue ? "On" : "Off")}""";
    }
}
