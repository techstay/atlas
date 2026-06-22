---
title: "重装笔记"
date: 2026-05-15T01:18:06+08:00
tags:
  - windows
categories:
  - Windows
---

## 必备工作

### 翻墙

提前下载 clash 软件，防止失联。

订阅链接： https://update.glados-config.com/clash/75286/262acb6/88159/glados.yaml

### 备份和恢复配置

如果是重新安装的系统，可以直接使用原版镜像安装，在安装的时候不格式化 C 盘，这样旧系统会存放到 `Windows.old` 文件夹中，方便以后从旧系统中恢复文件和配置，一般要备份的文件有

- 桌面文件
- ssh 密钥 (`~/.ssh/`)
- gpg 密钥 (`~/.gnupg` 或 `~/Appdata/Roaming/gnupg`)
- 我的文档 (游戏存档、一些软件的工程文件、虚拟机等)
- git 仓库
- 其他配置文件 (如 activitywatch 的配置文件)
- 默认在 `C:\Program Files` 下安装的游戏和软件
- 环境变量

```
QT_QPA_PLATFORM=windows:fontengine=freetype
```

配置文件最好通过 [dotfiles](https://github.com/techstay/dotfiles-windows) 的方式管理起来，这样以后恢复起来也非常方便。

如果是 git 仓库，那么可能会遇到用户权限的问题，有两种方法可以解决这个问题。第一种就是直接在 git 配置中指定安全文件夹。

```powershell
git config --global --add safe.directory C:/Users/techstay/Desktop/*
```

第二种就是将用户权限重新指定为当前用户所有。方法如下：

1. 右键点击属性，切换到安全选项卡
2. 点击高级按钮，打开高级安全配置对话框
3. 将所有者改为当前用户，并勾选 `替换子容器和对象的所有者`
4. 然后一路点击确定即可

这时候使用 git 命令应该就不会出现问题了。

#### 模拟器

安装 mumu 模拟器之后，找到下面路径，复制数据文件到新安装的。

```
C:\Windows.old\Program Files\NetEase\MuMu\vms\MuMuPlayer-12.0-0
```

#### 代码编辑器

复制 `$HOME/.vscode` 扩展文件夹。然后再复制 `$USERHOME/AppData/Roaming/Code` 配置文件夹。

### 包管理器

主要使用 winget 和 [scoop](scoop.md) 两个包管理器，需要安装的软件会记录在后面。

## 系统配置

### 激活

安装 business 版系统就可以方便的激活，需要管理员权限。补充：[一些公开的公共KMS列表](https://www.coolhub.top/tech-articles/kms_list.html)。

```powershell
slmgr /skms kms.03k.org
slmgr /ato
```

或者使用 [通用版激活脚本](https://github.com/massgravel/Microsoft-Activation-Scripts)，

```sh
irm https://massgrave.dev/get | iex
```

### 卸载 win11 小组件

```powershell
winget uninstall MicrosoftWindows.Client.WebExperience_cw5n1h2txyewy
```

### 禁用 Ctrl+ 空格

默认情况下 `Ctrl+空格` 是输入法中英文切换的快捷键，而这个快捷键常常作为代码补全的快捷键，经常敲代码的同学建议禁用这个快捷键，为代码补全让路。下载 [注册表文件](/windows/disable-ctrl-space-hotkey.reg)(右键链接另存为)，使用管理员权限执行 `disable-ctrl-space-toggle.reg` 注册表文件，重启电脑即可。

### 系统时间

如果同时安装了 linux 双系统的话，推荐同时让 windows 使用 UTC 代替本地时间，这样两个系统之间的时间就不会冲突了。只有 win 系统的话可以完全忽略该配置。

```powershell
reg add "HKEY_LOCAL_MACHINE\System\CurrentControlSet\Control\TimeZoneInformation" /v RealTimeIsUniversal /d 1 /t REG_QWORD /f
```

配置完成后，最好立即对时一次 (需要管理员权限)。

```cmd
w32tm /resync
```

### 系统优化

Optimizer

## 软件安装

### 字体

```powershell
# 可能需要sudo scoop -g install fontname
# 思源黑体 思源宋体 终端nerd-fonts字体
scoop install Source-Han-Serif-SC Source-Han-Serif-TC Source-Han-Serif-J Source-Han-Serif-K
scoop install Source-Han-Sans-SC Source-Han-Sans-TC Source-Han-Sans-K Source-Han-Sans-J Source-Han-Sans-HC
scoop install LiberationMono-NF
scoop install Meslo-NF-Mono FantasqueSansMono-NF-Mono
```

- Oppo Sans https://www.coloros.com/article/A00000074/
- Mi Sans https://hyperos.mi.com/font/en/download/
- 思源黑体 https://github.com/adobe-fonts/source-han-sans/releases

### 驱动软件

- [VC++可再发行程序包](https://learn.microsoft.com/en-US/cpp/windows/latest-supported-vc-redist)
- [Download NVIDIA App for Gamers and Creators | NVIDIA](https://www.nvidia.com/en-us/software/nvidia-app/?nvid=nv-int-pastpbnr-694846)
- [yamaha usb driver](https://usa.yamaha.com/support/updates/yamaha_steinberg_usb_driver_for_win.html)
- [视频解码器](https://codecguide.com/klcp_beta.htm)
- [AMD Ryzen Master](https://www.amd.com/zh-hans/technologies/ryzen-master)

### 工具软件

- [TrafficMonitor](https://gitee.com/zhongyang219/TrafficMonitor/releases)
- [gitkraken](https://www.gitkraken.com/download/windows64)
- [sandboxie plus](https://github.com/sandboxie-plus/Sandboxie/releases)
- [jetbrains tool app](https://www.jetbrains.com/toolbox-app/)
- [tailscale](https://tailscale.com/download)
- [optimizer](https://github.com/hellzerg/optimizer/releases)

```powershell
winget install `
  Microsoft.DotNet.SDK.7 `
  GnuPG.Gpg4win `
  Microsoft.PowerToys `
  Telegram.TelegramDesktop `
  Cloudflare.Warp `
  voidtools.everything `
  ActivityWatch.ActivityWatch `
  OBSProject.OBSStudio `
  Microsoft.VCRedist.2015+.x64 `
  Microsoft.VisualStudioCode `
  Audacity.Audacity `
  Fork.Fork `
  tailscale.tailscale `
  Obsidian.Obsidian `
  Datronicsoft.SpacedeskDriver.Server

scoop install screentogif ffmpeg busybox vim yt-dlp imageglass exiftool
```

WindowsUtility

```powershell
iwr -useb https://christitus.com/win | iex
```

### 应用软件

- [qq](https://im.qq.com/pcqq)
- [微信](https://pc.weixin.qq.com)
- [potplayer](https://potplayer.daum.net)
- [MuMu模拟器官网*安卓12模拟器*网易手游模拟器](https://mumu.163.com/)
- [欧陆词典](https://www.eudic.net/v4/en/app/download)
- [全民 K 歌](https://kg.qq.com/index-pc.html)
- [qq 音乐](https://y.qq.com)
- [网易云音乐](https://music.163.com/#/download)

## 美化

- 破解第三方主题 https://mhoefs.eu/software_uxtheme.php?lang=en
- 系统字体修改工具 https://github.com/Tatsu-syo/noMeiryoUI
- 全局开启亚力克特效 https://github.com/MicaForEveryone/MicaForEveryone ，需要安装 [.NET 3.1](https://dotnet.microsoft.com/zh-cn/download/dotnet/thank-you/runtime-desktop-3.1.32-windows-x64-installer)

## 收尾工作

确认系统安装和配置完毕之后，就可以清理之前的旧系统了。

以管理员权限打开*磁盘清理*，选择 C 盘，然后清理掉所有不需要的内容。
