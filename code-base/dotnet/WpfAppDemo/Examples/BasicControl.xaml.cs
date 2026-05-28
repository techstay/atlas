using System.Windows;
using System.Windows.Controls;

namespace WpfAppDemo.Examples
{
    /// <summary>
    ///     BasicControl.xaml 的交互逻辑
    /// </summary>
    public partial class BasicControl : UserControl
    {
        public BasicControl()
        {
            InitializeComponent();
        }

        private void Button_Click(object sender, RoutedEventArgs e)
        {
            MessageBox.Show("Button clicked.");
        }

        private void ButtonPassword_Click(object sender, RoutedEventArgs e)
        {
            MessageBox.Show($"Password is {PasswordBox.Password}");
        }


        private void CheckBox_Changed(object sender, RoutedEventArgs e)
        {
            if (CheckBox1.IsChecked == CheckBox2.IsChecked && CheckBox3.IsChecked == CheckBox2.IsChecked)
            {
                CheckBoxAll.IsChecked = CheckBox1.IsChecked;
            }
            else
            {
                CheckBoxAll.IsChecked = null;
            }
        }

        private void CheckBoxAll_Changed(object sender, RoutedEventArgs e)
        {
            bool? value = CheckBoxAll.IsChecked;
            if (value.HasValue)
            {
                CheckBox1.IsChecked = value;
                CheckBox2.IsChecked = value;
                CheckBox3.IsChecked = value;
            }
        }

        private void RadioButton_Click(object sender, RoutedEventArgs e)
        {
            RadioButtonValue.Text = ((RadioButton)sender).Content as string ?? string.Empty;
        }
    }
}