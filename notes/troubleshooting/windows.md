# windows

## 问题列表

### HyperV 动态端口号

如果你开启了 HyperV 功能，那么很有可能会出现莫名其妙的端口号占用问题，一些聪明的程序可能会使用随机端口号来工作，而一些比较死板的程序则会直接无法启动。当你使用 tcpview 等程序查看端口号占用情况的时候，则会发现其实这个端口号并没有被占用。而当重启之后，这个问题又会悄悄消失。

我被这个问题困扰了许久，最后终于在大佬的指点下解决了这个问题。根本原因是 Windows 的动态端口号机制，会占用一些端口号保留使用，本来这个机制保留的端口号是从 49152 开始，不会和主流应用冲突。**但是如果你开启了 HyperV，那么动态端口号就会改为从 1024 开始，那么很多常用的端口号都有可能被保留，导致依赖这些端口号的程序无法正常工作！**

知道了问题，那么解决起来就十分简单了。首先打开管理员权限的 powershell，查看一下动态端口号的范围。

```powershell
netsh interface ipv4 show dynamicport tcp
# 或者
Get-NetTCPSetting|select SettingName, DynamicPortRange*
```

如果你开启了 HyperV 的话，那么这里显示的应该会从 1024 开始，那么恭喜你中招了。解决办法很简单，重新指定一下端口号范围即可。

```powershell
netsh int ipv4 set dynamic tcp start=40000 num=10000
# 或者
Set-NetTCPSetting -DynamicPortRangeStartPort 40000 -DynamicPortRangeNumberOfPorts 10000
```

### 自带图片查看器颜色发黄

这个问题网络上也有很多方案，不过大多已经过期，无法参考。这里记录一下我的解决方案，win11 可用。

这是颜色配置文件的问题。点击*设置->系统->屏幕*，这里默认情况下使用的应该是显示器的颜色配置文件。

[![zMSFG4.md.png](https://s1.ax1x.com/2022/11/20/zMSFG4.md.png)](https://imgse.com/i/zMSFG4)

这时候可以修改为系统默认的颜色配置文件。方法很简单，在设置左边的搜索框内搜索*校准显示器*，然后打开校准显示器窗口，一路下一步，最后点击完成。

[![zMSao8.png](https://s1.ax1x.com/2022/11/20/zMSao8.png)](https://imgse.com/i/zMSao8)

这时候返回刚才的界面，应该已经多了一个颜色配置文件，选择它。这时候 windows 自带的照片查看器应该就没有显示发黄的问题了。

[![zMSyyn.png](https://s1.ax1x.com/2022/11/20/zMSyyn.png)](https://imgse.com/i/zMSyyn)

### win11 卡顿问题

这个问题比较复杂，也是很多人都遇到过的一个问题，目前我也在寻找解决方案。

目前试过以下解决方案，均没有解决问题，又或者是我自己确实运行的程序过多了。

首先尝试更新一下显卡驱动，win11 自带的显卡驱动比较旧，也有可能导致卡顿，更新到最新版或许可以解决卡顿。

如果 CPU 是 AMD 的，也有可能是 AMD 主板的 fTPM 功能导致，可以考虑在主板中关闭 fTPM 功能。

如果不行的话，也有可能是系统配置问题，尝试在`调整Windows的外观和性能`对话框中减少特效，或许也可能解决问题。

如果没有解决卡顿问题，还可以尝试关闭内存压缩。

```powershell
Disable-MMAgent -MemoryCompression
```

当然，由于 win11 卡顿方面反馈的确实比较多，或许只是系统优化问题，只能等待微软慢慢修复解决了。

参考链接：

- <https://www.v2ex.com/t/818084>
- <https://www.xitongtang.com/class/win11/32546.html>
