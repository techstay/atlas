using System.Globalization;
using System.Windows.Controls;
using System.Windows.Data;

namespace WpfAppDemo.Examples
{
    /// <summary>
    ///     Trigger.xaml 的交互逻辑
    /// </summary>
    public partial class Trigger : UserControl
    {
        public Trigger()
        {
            InitializeComponent();
        }
    }

    [ValueConversion(typeof(string), typeof(string))]
    public class UpperCaseConverter : IValueConverter
    {
        public object Convert(object value, Type targetType, object parameter, CultureInfo culture)
        {
            return value?.ToString()?.ToUpper() ?? "";
        }

        public object ConvertBack(object value, Type targetType, object parameter,
            CultureInfo culture)
        {
            throw new NotImplementedException();
        }
    }
}