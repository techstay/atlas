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

// To learn more about WinUI, the WinUI project structure,
// and more about our project templates, see: http://aka.ms/winui-project-info.

namespace WinUIExample.Pages
{
    /// <summary>
    /// An empty page that can be used on its own or navigated to within a Frame.
    /// </summary>
    public sealed partial class TextControlsPage : Page
    {
        public TextControlsPage()
        {
            this.InitializeComponent();
        }

        private void SpinButtonPlacementModeRadioButtons_SelectionChanged(object sender, SelectionChangedEventArgs e)
        {
            if (sender is RadioButtons radioButtons)
            {
                var mode = (radioButtons.SelectedItem as string) switch
                {
                    "Inline" => NumberBoxSpinButtonPlacementMode.Inline,
                    "Compact" => NumberBoxSpinButtonPlacementMode.Compact,
                    _ => NumberBoxSpinButtonPlacementMode.Hidden,
                };
                NumberBox1.SpinButtonPlacementMode = mode;
            }
        }

        private void AutoSuggestBox1_SuggestionChosen(AutoSuggestBox sender, AutoSuggestBoxSuggestionChosenEventArgs args)
        {
            AutoSuggestBox1.Text = args.SelectedItem.ToString();
        }

        private void AutoSuggestBox1_TextChanged(AutoSuggestBox sender, AutoSuggestBoxTextChangedEventArgs args)
        {
            var fruits = new List<string> { "Apple", "Banana", "Orange", "Pear", "Strawberry", "Mango" };
            if (args.Reason == AutoSuggestionBoxTextChangeReason.UserInput)
            {
                var found = (from fruit in fruits
                             where fruit.ToLower().Contains(sender.Text)
                             select fruit).ToList();
                if (found.Count() == 0)
                {
                    found.Add("No result found.");
                }
                sender.ItemsSource = found;
            }
        }

        private void ShowPasswordCheckBox_Changed(object sender, RoutedEventArgs e)
        {
            PasswordBox1.PasswordRevealMode = ShowPasswordCheckBox.IsChecked == true ? PasswordRevealMode.Visible : PasswordRevealMode.Hidden;
        }
    }
}

