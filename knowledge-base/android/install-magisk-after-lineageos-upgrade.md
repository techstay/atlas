---
title: "Lineageos更新后安装magisk的方法"
date: 2022-01-30T12:16:02+08:00
tags:
  - 安卓
categories:
  - 安卓
---

今天又把旧手机拿出来更新了一下 lineageos 系统，上次安装的 magisk 理所应当的失效了，又需要重新安装一次。不过其实也不用那么麻烦，在 lineageos 的更新选项里有一条 `安装后删除更新`，不要选中这个，在 OTA 更新完之后，点击更新包右边的 `...` 图标，选择导出更新。

这样就会把完整更新包保存到 `Android/data/org.lineageos.updater` 目录下，在手机端就可以选择 `boot.img` 文件并解压。然后就可以在 magisk 中选择修补文件，再将修补后的 `boot.img` 在电脑端用 adb 刷入。

```powershell
adb pull /sdcard/Download/magisk_patched-24100_6PSTi.img
adb reboot bootloader
fastboot flash boot .\magisk_patched-24100_6PSTi.img
```
