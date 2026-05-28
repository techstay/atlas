---
title: "小米8刷入LineageOS的记录"
date: 2021-12-13T15:22:16+08:00
tags:
  - 安卓
categories:
  - 安卓
---

因为最近要用到几个需要谷歌服务的应用，再加上小米 8 差不多已经被官方放弃了。所以我决定将手里这台米 8 刷成 LineageOS，让它重新焕发第二春。

## 谨慎刷机

现在绝大多数厂商的保修策略都是一旦用户解锁并刷机，就会失去保修资格。所以建议大家不要在自己新买的主力机上刷机，如果想折腾着玩的话，最好用那种刚好过了保修期的备用机刷机。刷机的时候也要注意甄别刷机包，不要随意去刷那种来路不明的包，推荐使用那些口碑较好的社区包或者开源的刷机包（LineageOS）等。

## 准备工作

刷机其实也是一件比较麻烦的事情，要准备的东西还是蛮多的。

- 解锁工具，从小米官方下载<https://www.miui.com/unlock/index.html>
- adb 工具，可以用 scoop 直接安装 `scoop install adb`
- gpg 工具，可以用 scoop 直接安装 `scoop install gpg`
- twrp，小米 8 对应的在这里<https://dl.twrp.me/dipper/twrp-3.6.0_9-0-dipper.img.html>，最好同时下载 asc 校验文件方便验证文件完整性
- LineageOS，小米 8 对应的刷机包<https://download.lineageos.org/dipper>，最好也校验一下
- gapps，既然要刷类原生系统，谷歌应用自然少不了，<https://opengapps.org>，我喜欢使用 pico 版，只包含最基本的功能，毕竟不是每个人都喜欢谷歌全家桶

特别的，如果没有特殊说明，下面的所有命令默认都在 windows 的 Powershell 中运行。

## 解锁手机

刷机的第一步自然是解锁手机了。如果之前从未解锁过手机的话，需要在手机的开发者选项里面找到设备解锁状态，并绑定小米账号和 SIM 卡，然后等待 360 小时也就是 15 天才能解锁。注意不要重复绑定，否则可能会重新计算天数。

然后用小米账号登录解锁工具，手机关机，按住电源 + 音量下重启进入 fastboot 模式，然后使用解锁工具解锁。或者有 adb 命令的话，也可以用命令重启手机到 fastboot 模式。解锁手机会清除所有数据，所以要提前备份重要数据。

```sh
adb reboot fastboot
```

## 刷入 twrp recovery

在刷入 twrp 之前，最好校验一下文件，保证文件完整无误。校验时需要 gpg 工具。首先在这里下载 twrp 的公钥<https://dl.twrp.me/public.asc>，然后将其导入。

```powershell
gpg --import .\public.asc
```

然后就可以用它来验证了，如果出现类似下面的信息，说明下载的 twrp 没有问题，可以放心刷入了。

```powershell
gpg --verify .\twrp-3.6.0_9-0-dipper.img.asc .\twrp-3.6.0_9-0-dipper.img

# gpg: checking the trustdb
# gpg: no ultimately trusted keys found
# gpg: Good signature from "TeamWin <admin@teamw.in>" [unknown]
# gpg: WARNING: This key is not certified with a trusted signature!
# gpg:          There is no indication that the signature belongs to the owner.
# Primary key fingerprint: 9570 7D42 307C 9D41 D09B  F709 1D85 97D7 891A 43DF
```

然后将手机关键，按电源 + 音量下进入 fastboot 模式，输入下面的命令刷入 twrp，出现 ok 字样就说明刷入成功了。

```powershell
fastboot flash recovery .\twrp-3.6.0_9-0-dipper.img

# Sending 'recovery' (43712 KB)                      OKAY [  1.107s]
# Writing 'recovery'                                 OKAY [  0.110s]
# Finished. Total time: 1.228s
```

## 刷入 LineageOS

在刷入 LineageOS 之前，同样最好进行一下校验操作。将下面命令得到的结果和下载包下面小字处的 SHA256 校验码比对，一样就说明没有问题，可以放心刷入了。

```powershell
Get-FileHash -Algorithm SHA256 .\lineage-18.1-20211209-nightly-dipper-signed.zip
```

然后按住电源 + 音量上进入 recovery 模式，这时候可以看到新刷入的 twrp 了。它功能很强大，也可以设定中文语言。因为我手机上没有啥有用的东西，所以我就选择了清除所有数据，一般情况下使用默认选项即可。

清除完成后就可以刷入新系统了，twrp 支持旁加载功能，这样我们不必将刷机包预先放到手机存储里面，直接用 USB 线就可以传输。选择 twrp 的高级 ->adb sideload，手机就会进入等待模式，这时候在终端中输入下面的命令，即可开始传输刷机包。

```powershell
adb sideload .\lineage-18.1-20211209-nightly-dipper-signed.zip
```

## 刷入 gapps

刷机完成别着急开机，别忘了再把 gapps 刷进去。同样刷机之前最好先校验一下。

```powershell
Get-FileHash -Algorithm MD5 .\open_gapps-arm64-11.0-pico-20211211.zip
```

同样使用旁加载的方式刷入。等待操作完成之后，就可以重启手机了。不知道什么情况 twrp 会提示没有安装系统，不过其实已经安装了，正常重启即可。刷入谷歌框架之后，开机会要求验证谷歌账号，请自备上网工具。
