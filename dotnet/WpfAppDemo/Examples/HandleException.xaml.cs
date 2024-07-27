using System.Windows;
using System.Windows.Controls;

namespace WpfAppDemo.Examples
{
    /// <summary>
    ///     HandleException.xaml 的交互逻辑
    /// </summary>
    public partial class HandleException : UserControl
    {
        public HandleException()
        {
            InitializeComponent();
        }

        private void Button1_Click(object sender, RoutedEventArgs e)
        {
            string s = null;
            try
            {
                s.Trim();
            }
            catch (Exception ex)
            {
                MessageBox.Show($"A handled exception just occurred: {ex.Message}", "Handled Exception Sample",
                    MessageBoxButton.OK, MessageBoxImage.Warning);
            }
        }

        private void Button2_Click(object sender, RoutedEventArgs e)
        {
            throw new Exception("This is a test exception.");
        }
    }
}