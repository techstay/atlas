---
title: 安卓刷机与调试速查手册
date: 2026-05-15T01:18:06+08:00
tags:
  - flashing
  - adb
  - magisk
  - twrp
categories:
  - Android
---

## 下载资源

- [TWRP Recovery](https://dl.twrp.me) — 第三方 Recovery，刷机必备，支持各机型
- [LineageOS](https://download.lineageos.org/) — 最主流的开源类原生 ROM
- [PixelExperience](https://download.pixelexperience.org/devices) — 模拟 Pixel 体验的类原生 ROM
- [NikGapps](https://nikgapps.com) — 轻量 GApps 套件，可按需选择安装组件
- [Magisk](https://github.com/topjohnwu/Magisk/releases) — 系统级 Root 工具，支持模块扩展
- [小米刷机工具 (MiFlash)](https://xiaomirom.com/download-xiaomi-flash-tool-miflash/) — 小米官方线刷工具，需安装驱动

## 刷机

### 安装工具

- adb，`scoop install adb`
- MiFlash 线刷时需安装驱动，如果出现 `press key to shutdown` 错误，参考 [这里](https://miuiver.com/press-any-key-to-shutdown/)。**线刷的时候切记在刷机工具右下角选择第一个选项，避免刷机完成后自动上锁前功尽弃。**

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

先下载安装 Magisk，安装到手机上。打开 magisk，查看手机是否支持 ramdisk，如果支持，就继续。

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

## 系统调优

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
