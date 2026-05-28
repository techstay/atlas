---
title: "Android"
date: 2026-05-15T01:18:06+08:00
tags:
  - tech
  - android
categories:
  - 技术
---

## 刷机

### 安装工具

- adb，`scopo install adb`
- [小米刷机工具](https://xiaomirom.com/download-xiaomi-flash-tool-miflash/)，安装驱动，如果刷机出现 `press key to shutdown` 错误，参考 [这里](https://miuiver.com/press-any-key-to-shutdown/),\*\* 线刷的时候切记在刷机工具右下角选择第一个选项，避免刷机完成后自动上锁前功尽弃。

### 下载包

- [twrp](https://dl.twrp.me)
- [lineageos](https://download.lineageos.org/)
- [pixelexperience](https://download.pixelexperience.org/devices)
- [NikGapps](https://nikgapps.com)
- https://github.com/MustardChef/WSABuilds

### 刷 recovery

进入工程模式，`adb reboot bootloader` 或者关机后按*音量下 + 电源*，刷 recovery。

```sh
fastboot flash recovery <recovery.img>
```

如果 fastboot 很快退出，终端显示 `?????`，参考 [这个帖子](https://forum.xda-developers.com/t/fix-fastboot-issues-on-ryzen-based-pcs.4186321/)。

如果是锐龙处理器，fastboot 没反应，使用下面的命令修复注册表，一次一条命令，执行完重启电脑。

```cmd
reg add "HKEY_LOCAL_MACHINE\SYSTEM\CurrentControlSet\Control\usbflags\18D1D00D0100" /v "osvc" /t REG_BINARY /d "0000" /f
reg add "HKEY_LOCAL_MACHINE\SYSTEM\CurrentControlSet\Control\usbflags\18D1D00D0100" /v "SkipContainerIdQuery" /t REG_BINARY /d "01000000" /f
reg add "HKEY_LOCAL_MACHINE\SYSTEM\CurrentControlSet\Control\usbflags\18D1D00D0100" /v "SkipBOSDescriptorQuery" /t REG_BINARY /d "01000000" /f
```

### 刷系统

按音量上 + 电源键进入 recovery，选择旁加载，刷入系统。

```sh
adb sideload <file>
```

### 刷 magisk

先 [下载 magisk](https://github.com/topjohnwu/Magisk/releases)，安装到手机上。打开 magisk，查看手机是否支持 ramdisk，如果支持，就继续。

找到刷机包，解压其中的 `boot.img` 文件，传输到手机中。

```powershell
adb push .\boot.img /sdcard/
```

再看看手机是否存在单独的 vbmeta 分区。

```sh
adb shell ls -l /dev/block/by-name |grep vbmeta
```

在手机 magisk 程序中选择刚刚上传的 `boot.img` 文件，开始修补。如果手机没有单独的 vbmeta 分区，修补选项勾选*Patch vbmeta in boot image*。小米 5 没有该分区，所以需要勾选。修补完成后，记下修补文件名。

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

## 不常用命令

### 修改 ntp 服务器

```sh
adb shell "settings put global ntp_server ntp.ntsc.ac.cn"
```

### 消除 wifi 叉号

操作完切换一下飞行模式。

```shell
# 进入shell模式
adb shell
# 在shell中输入以下命令
settings delete global captive_portal_http_url
settings delete global captive_portal_https_url
settings put global captive_portal_http_url http://developers.google.cn/generate_204
settings put global captive_portal_https_url https://developers.google.cn/generate_204
```

### linux 服务器

安装以下软件

- [busybox](https://github.com/SmartPack/BusyBox-Installer/releases)，在 app 里安装 busybox，路径 `/system/xbin`
- [linux deploy](https://github.com/meefik/linuxdeploy/releases)

在 linux deploy 中，将路径设置为 `/system/xbin/`，系统选择 debian，用户选择 root 用户，其他按需配置。
