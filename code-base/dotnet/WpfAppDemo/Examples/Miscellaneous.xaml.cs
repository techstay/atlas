using System.ComponentModel;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Threading;

namespace WpfAppDemo.Examples
{
    /// <summary>
    ///     Miscellaneous.xaml 的交互逻辑
    /// </summary>
    public partial class Miscellaneous : UserControl
    {
        public Miscellaneous()
        {
            InitializeComponent();
            DispatcherTimer timer = new() { Interval = TimeSpan.FromMilliseconds(1) };
            timer.Tick += TimerTick;
            timer.Start();
        }

        private void TimerTick(object sender, EventArgs e)
        {
            LblTime.Content = DateTime.Now.ToString("HH:mm:ss.fff");
        }

        private void BtnDoSynchronousCalculation_Click(object sender, RoutedEventArgs e)
        {
            int n = 10;
            PbCalculationProgress.Value = 0;
            LbResults.Items.Clear();

            for (int i = 0; i < n; i++)
            {
                LbResults.Items.Add(i);
                Thread.Sleep(300);
                PbCalculationProgress.Value = (i + 1) * 100 / n;
            }

            MessageBox.Show("Work completed.");
        }

        private void BtnDoAsynchronousCalculation_Click(object sender, RoutedEventArgs e)
        {
            PbCalculationProgress.Value = 0;
            LbResults.Items.Clear();

            BackgroundWorker worker = new();
            worker.WorkerReportsProgress = true;
            worker.DoWork += WorkerDoWork;
            worker.ProgressChanged += Worker_ProgressChanged;
            worker.RunWorkerCompleted += Worker_RunWorkerCompleted;
            worker.RunWorkerAsync(10);
        }

        private void WorkerDoWork(object sender, DoWorkEventArgs e)
        {
            int n = (int)e.Argument!;
            for (int i = 0; i < n; i++)
            {
                int progressPercentage = (i + 1) * 100 / n;
                (sender as BackgroundWorker)?.ReportProgress(progressPercentage, i);
                Thread.Sleep(300);
            }

            e.Result = "Background work completed.";
        }

        private void Worker_ProgressChanged(object sender, ProgressChangedEventArgs e)
        {
            PbCalculationProgress.Value = e.ProgressPercentage;
            if (e.UserState != null)
            {
                LbResults.Items.Add(e.UserState);
            }
        }

        private void Worker_RunWorkerCompleted(object sender, RunWorkerCompletedEventArgs e)
        {
            MessageBox.Show(e.Result?.ToString() ?? "");
        }
    }
}