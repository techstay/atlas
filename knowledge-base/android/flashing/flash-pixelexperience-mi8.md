---
title: "小米8刷入PixelExperience正式版"
date: 2022-01-24T10:14:28+08:00
tags:
  - flashing
  - pixelexperience
  - mi8
categories:
  - Android
---

今天看了一下发现 PixelExperience 有了新版本刷机包了，正好之前我刷的那个还是 beta 版，现在也有了正式版。也就是说，又到了折腾的时候了。

## 下载 ROM

首先自然是下载刷机包了，不过在下载之前，我简单看了一下更新日志，发现事情并不简单。因为现在 PixelExperience 要求使用自己的固件，twrp 不能用了，刷机之前要做的就是重新刷一下固件。而且考虑到之前玩机把数据全玩没了，所以第一件事情就是看看要不要重新备份一下，。好吧，自打上次一来我手机上也没啥有用的东西了，大不了重新再来一次嘛。

既然这样，那就开干吧。首先就是从 [PixelExperience 官网](https://download.pixelexperience.org/dipper) 寻找自己的机型，然后下载固件和 ROM。下载完成之后别忘了校验一下。

```powershell
md5sum .\PixelExperience_dipper-12.0-20220122-1154-OFFICIAL.zip
```

## 刷入 recovery

重启进入 fastboot 模式。

```sh
adb reboot bootloader
```

刷入固件。

```powershell
fastboot flash recovery .\PixelExperience_dipper-12.0-20220122-1154-OFFICIAL.img
```

## 刷入 ROM

手机按音量上 + 电源键，进入 recovery 模式。或者重启进入系统后，用 adb 命令进入恢复模式。此时不出意外的话，应该进入了 PixelExperience 的恢复模式。

```sh
adb reboot recovery
```

选择高级选项，启用 adb。然后回到主界面，选择应用更新 ->从 adb 应用，然后在命令行用旁加载模式上传 ROM。

```powershell
adb sideload .\PixelExperience_dipper-12.0-20220122-1154-OFFICIAL.zip
```

等刷机完成后就可以重启了，不出意外的话就能正常进入系统了。这一步我还是比较忐忑的，不过幸好没出什么问题就成功进入系统了。唯一的缺点就是需要重刷一遍 magisk，这倒不是什么难事，按照教程重新来一遍行了。

值得注意的是，正式版的 PixelExperience 支持 OTA 更新，也就是说可以像使用那些官方 ROM 一样在线更新。以后也不用每次都卡刷了，perfect！
