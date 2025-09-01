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
using CommunityToolkit.WinUI.Helpers;
using Windows.Media.Capture.Frames;
using System.Threading.Tasks;
using System.Runtime.CompilerServices;
using System.Collections.ObjectModel;
using Windows.Media.Capture;
using Windows.Media.Core;
using CommunityToolkit.WinUI.Controls;

// To learn more about WinUI, the WinUI project structure,
// and more about our project templates, see: http://aka.ms/winui-project-info.

namespace WinUIExample.Pages;

/// <summary>
/// An empty page that can be used on its own or navigated to within a Frame.
/// </summary>
public sealed partial class MediaPage : Page
{
    public MediaPage()
    {
        this.InitializeComponent();
        InitializeCameraList();
    }

    public ObservableCollection<string> CameraList { get; set; } = new();

    async void InitializeCameraList()
    {
        var cameraList = await CameraHelper.GetFrameSourceGroupsAsync();
        cameraList.Select(it => it.DisplayName).ToList().ForEach(it => CameraList.Add(it));
        CameraListComboBox.SelectedItem = cameraList.FirstOrDefault()?.DisplayName;
    }


    private async void CameraListComboBox_SelectionChangedAsync(object sender, SelectionChangedEventArgs e)
    {
        // Show camera preview by using the media player control

        var groups = await MediaFrameSourceGroup.FindAllAsync();
        if (groups.Count == 0)
        {
            var dialog = new ContentDialog()
            {
                Title = "No Camera Found",
                CloseButtonText = "Close",
                DefaultButton = ContentDialogButton.Close,
                XamlRoot = this.Content.XamlRoot,
            };
            await dialog.ShowAsync();
            return;
        }

        var group = groups.FirstOrDefault(it => it.DisplayName == CameraListComboBox.SelectedItem.ToString());
        var mediaCapture = new MediaCapture();
        await mediaCapture.InitializeAsync(new MediaCaptureInitializationSettings()
        {
            SourceGroup = group,
            SharingMode = MediaCaptureSharingMode.SharedReadOnly,
            StreamingCaptureMode = StreamingCaptureMode.Video,
            MemoryPreference = MediaCaptureMemoryPreference.Cpu

        });

        var frameSource = mediaCapture.FrameSources[group.SourceInfos[0].Id];
        MediaPlayer1.Source = MediaSource.CreateFromMediaFrameSource(frameSource);

    }

}
