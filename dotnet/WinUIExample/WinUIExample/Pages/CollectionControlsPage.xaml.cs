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
    public sealed partial class CollectionControlsPage : Page
    {
        public CollectionControlsPage()
        {
            this.InitializeComponent();
        }

        public List<string> MyItems { get; set; } = ["one", "two", "three", "four"];

        public List<string> MyImageUrls { get; set; } = new List<string> {
            "https://i.pinimg.com/564x/a0/52/c1/a052c135e5d7c0d457941299c65b35c8.jpg",
            "https://i.pinimg.com/564x/db/a0/d6/dba0d6ab6cb5d75851e7298c0af9acde.jpg",
            "https://i.pinimg.com/564x/5d/5e/e8/5d5ee8679b25510f2946f069ca1ea681.jpg",
            "https://i.pinimg.com/564x/d7/33/97/d7339785d3629a686176cd1f6b9849c1.jpg",
            "https://i.pinimg.com/474x/23/be/29/23be294bb2b58a4c6d842a46abb6c09d.jpg",
            "https://i.pinimg.com/474x/26/95/16/26951652734e5601e8519bcc9e79d665.jpg",
            "https://i.pinimg.com/564x/5e/e7/00/5ee700f1c0608ed075a8d5313eeff5c9.jpg"
        };
    }
}
