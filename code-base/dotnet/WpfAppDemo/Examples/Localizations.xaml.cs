using System.Globalization;
using System.Windows;
using System.Windows.Controls;

namespace WpfAppDemo.Examples
{
    /// <summary>
    ///     Localizations.xaml 的交互逻辑
    /// </summary>
    public partial class Localizations : UserControl
    {
        public Localizations()
        {
            InitializeComponent();
        }

        private void CultureInfoSwitchButton_Click(object sender, RoutedEventArgs e)
        {
            Thread.CurrentThread.CurrentCulture = new CultureInfo((sender as Button)?.Tag.ToString() ?? string.Empty);
            LblNumber.Content = 123456789.42d.ToString("N2");
            LblDate.Content = DateTime.Now.ToString();
        }
    }
}