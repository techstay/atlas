# 小米手机刷机记录

手里的老小米 5/8，没事干就拿出来刷个机，记录一下步骤，下次照做就行。

## 准备工作

### 安装工具

安装 adb 调试工具

```sh
scoop install adb
```

从[这里](https://xiaomirom.com/download-xiaomi-flash-tool-miflash/)下载小米刷机工具，刷坏了还可以直接用这个救砖。

### 安装驱动

首先需要安装驱动，不然识别不到手机。先将手机和电脑用 USB 线连接，注意连接到 USB2.0 的口上，使用 3.0 的口可能识别不了。

然后手机关机长按*音量下+电源键*进入工程模式，这时候电脑打开设备管理器，应该就会看到未识别的安卓设备，点击更新驱动程序，设备变为正常状态。

这时候使用`fastboot devices`测试，显示出设备，驱动就算安装成功了。

### 下载包

- [twrp](https://dl.twrp.me)
- [lineageos](https://download.lineageos.org/)
- [pixelexperience](https://download.pixelexperience.org/devices)
- [NikGapps](https://nikgapps.com)

所有包下载之后最好先校验一下，防止损坏。

## 开始刷机

### 刷 recovery

首先进入工程模式，`adb reboot bootloader`或者关机后按*音量下+电源*。

```powershell
fastboot flash recovery .\twrp-3.7.0_9-0-gemini.img
```

### 修复问题

如果是锐龙处理器，而且 fastboot 没反应，可以尝试添加注册表来修复。一次运行一行，全部运行完毕后，重启电脑，问题应当解决。

```reg
reg add "HKEY_LOCAL_MACHINE\SYSTEM\CurrentControlSet\Control\usbflags\18D1D00D0100" /v "osvc" /t REG_BINARY /d "0000" /f
reg add "HKEY_LOCAL_MACHINE\SYSTEM\CurrentControlSet\Control\usbflags\18D1D00D0100" /v "SkipContainerIdQuery" /t REG_BINARY /d "01000000" /f
reg add "HKEY_LOCAL_MACHINE\SYSTEM\CurrentControlSet\Control\usbflags\18D1D00D0100" /v "SkipBOSDescriptorQuery" /t REG_BINARY /d "01000000" /f
```

### 刷系统

成功刷入 recovery 之后，重启手机，按*音量上+电源键*进入 recovery 模式，开启旁加载，然后刷系统。

```sh
adb sideload xxx.zip
```

### 刷 magisk

先[下载 magisk](https://github.com/topjohnwu/Magisk/releases)，安装到手机上。打开 magisk，查看手机是否支持 ramdisk，如果支持，就继续。

找到刷机包，解压其中的`boot.img`文件，传输到手机中。

```powershell
adb push .\boot.img /sdcard/
```

再看看手机是否存在单独的 vbmeta 分区，没有输出说明没有 vbmeta 分区。

```sh
adb shell ls -l /dev/block/by-name |grep vbmeta
```

在手机 magisk 程序中选择刚刚上传的`boot.img`文件，开始修补。如果手机没有单独的 vbmeta 分区，修补选项勾选*Patch vbmeta in boot image*。我的小米 5 没有该分区，所以需要勾选。修补完成后，记下修补文件名。

```sh
adb shell "ls /sdcard/Download"
```

然后将文件拉取出来。

```sh
adb pull /sdcard/Download/magisk_patched-25200_Y3F5J.img
```

重启到工程模式。

```sh
adb reboot bootloader
```

刷入新的 boot 镜像。

```powershell
fastboot flash boot .\magisk_patched-25200_AeHvN.img
```
