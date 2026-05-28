using System.Collections.ObjectModel;
using System.ComponentModel;
using System.Windows;
using System.Windows.Controls;

namespace WpfAppDemo.Examples
{
    /// <summary>
    ///     DataBinding.xaml 的交互逻辑
    /// </summary>
    public partial class DataBindings : UserControl
    {
        private readonly ObservableCollection<User> _users = new();

        public DataBindings()
        {
            InitializeComponent();
            DataContext = this;

            _users.Add(new User("John Doe"));
            _users.Add(new User("Jane Doe"));
            LbUsers.ItemsSource = _users;
        }

        public string WindowTitle => Window.GetWindow(this)!.Title;

        public double WindowHeight => Window.GetWindow(this)!.Height;

        public double WindowWidth => Window.GetWindow(this)!.Width;

        private void BtnAddUser_Click(object sender, RoutedEventArgs e)
        {
            _users.Add(new User("New user"));
        }

        private void BtnChangeUser_Click(object sender, RoutedEventArgs e)
        {
            if (LbUsers.SelectedItem is User selectedItem)
            {
                selectedItem.Name = "Random Name";
            }
        }

        private void BtnDeleteUser_Click(object sender, RoutedEventArgs e)
        {
            if (LbUsers.SelectedItem is User selectedItem)
            {
                _users.Remove(selectedItem);
            }
        }
    }

    public class User(string name) : INotifyPropertyChanged
    {
        private string _name = name;

        public string Name
        {
            get => _name;
            set
            {
                if (_name != value)
                {
                    _name = value;
                    NotifyPropertyChanged("Name");
                }
            }
        }

        public event PropertyChangedEventHandler? PropertyChanged;

        private void NotifyPropertyChanged(string propName)
        {
            PropertyChanged?.Invoke(this, new PropertyChangedEventArgs(propName));
        }
    }
}