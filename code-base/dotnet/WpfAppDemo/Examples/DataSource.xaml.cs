using System.Windows.Controls;
using System.Windows.Media;

namespace WpfAppDemo.Examples
{
    /// <summary>
    ///     DataSource.xaml 的交互逻辑
    /// </summary>
    public partial class DataSource : UserControl
    {
        public DataSource()
        {
            InitializeComponent();
            ItemControl.ItemsSource = new List<string> { "one", "two", "three", "four" };
            ColorComboBox.ItemsSource = typeof(Colors).GetProperties();
            List<Person> dataSource =
                [new("张三", 18, "zhangsan@qq.com"), new("李四", 19, "lisi@qq.com"), new("王五", 20, "wangwu@qq.com")];
            ListView.ItemsSource = dataSource;
            DataGrid.ItemsSource = dataSource;
        }
    }

    internal record Person(string Name, int Age, string Email);
}