# windows 安装笔记

[TOC]

## 写在前面

- UPDATE1: 我的 windows 安装笔记。由于不小心安装了流氓软件，导致我系统动不动就死机，以至于我才重装系统没几个月就又不得不重装系统，真的是烦透了。而且上次重装系统的笔记记录因为放到了另一个待整理的仓库中，已经被我干掉了。所以不得不从头记一遍笔记。
- UPDATE2: 之前安装的 Win10 还是蛮好用的，除了系统的 emoji 表情没有 Win11 的好看。不过前两天看到别人新安装的 Win11 看起来还是很好用的，于是又手痒了起来，费了点功夫又重装了一遍系统。所以这次的 Windows 安装笔记又可以更新了。
- UPDATE3: win11 的卡顿老毛病又犯了，每次动不动卡个一分钟，勉强可以忍，然而这次竟然连着卡顿十分钟，实在忍不了了，所以又装回了 win10，不得不承认，虽然我很喜欢 win11 的新 emoji，但是还是 win10 比较流畅。

## 必备工作

### 代理

安装代理软件，加速后续的下载。

- github 加速 <https://shrill-pond-3e81.hunsh.workers.dev/>
- github 加速 <https://toolwa.com/github/>
- clash-for-windows <https://github.com/Fndroid/clash_for_windows_pkg/releases>

### 恢复配置

如果是重新安装的系统，可以直接使用原版镜像安装，在安装的时候不格式化 C 盘，这样旧系统会存放到`Windows.old`文件夹中，方便以后从旧系统中恢复文件和配置，如

- 桌面文件
- ssh 和 gpg 密钥
- 我的文档里面的配置文件
- git 仓库等

如果是 git 仓库，那么可能会遇到用户权限的问题，有两种方法可以解决这个问题。第一种就是直接在 git 配置中指定安全文件夹。

```powershell
git config --global --add safe.directory C:/Users/techstay/Desktop/dotfiles
```

第二种就是将用户权限重新指定为当前用户所有。方法如下：

1. 右键点击属性，切换到安全选项卡
1. 点击高级按钮，打开高级安全配置对话框
1. 将所有者改为当前用户，并勾选`替换子容器和对象的所有者`
1. 然后一路点击确定即可

这时候使用 git 命令应该就不会出现问题了。

### 包管理器

安装 scoop。

```powershell
# 首先设置允许运行远程脚本
Set-ExecutionPolicy RemoteSigned -Scope CurrentUser

# 安装scoop
Invoke-Expression (New-Object System.Net.WebClient).DownloadString('https://get.scoop.sh')

# 设置代理
scoop config proxy 'localhost:7890'

# 安装aria2加速
scoop install aria2

# 安装git，添加bucket时必需
scoop install git-with-openssh

# 设置git代理，加快下载速度
git config --global http.proxy http://localhost:7890

# 添加bucket
scoop bucket add extras
scoop bucket add nerd-fonts
scoop bucket add java
```

安装 winget，可以在应用商店里搜索`应用安装程序`，也可以手动下载安装包来安装 <https://github.com/microsoft/winget-cli/releases>。

## 系统配置

### 激活

安装 business 版系统就可以方便的激活，需要管理员权限。

```powershell
slmgr /skms kms.03k.org
slmgr /ato
```

### 卸载 win11 小组件

win11 新增了小组件功能，但是说白了就是一个信息聚合组件，没有什么用处，直接卸载即可。卸载完成之后小组件按钮可能仍然在任务栏驻留，这时候重启资源管理器应该就不会再见到它了(需要管理员权限)。

```powershell
winget uninstall MicrosoftWindows.Client.WebExperience_cw5n1h2txyewy
```

### 禁用 Ctrl+空格

默认情况下`Ctrl+空格`是输入法中英文切换的快捷键，而这个快捷键常常作为代码补全的快捷键，经常敲代码的同学建议禁用这个快捷键，为代码补全让路。使用管理员权限执行`disable-ctrl-space-toggle.reg`注册表文件，重启电脑即可。

### 系统时间

通过下面的命令使用阿里云的对时服务，需要管理员权限。

```powershell
Set-ItemProperty -Path "HKLM:\SOFTWARE\Microsoft\Windows\CurrentVersion\DateTime\Servers" -Name "0" -Value "ntp.aliyun.com" -Type "String"
Set-ItemProperty -Path "HKLM:\SOFTWARE\Microsoft\Windows\CurrentVersion\DateTime\Servers" -Name "(default)" -Value 0
```

如果同时安装了 linux 双系统的话，推荐同时让 windows 使用 UTC 代替本地时间，这样两个系统之间的时间就不会冲突了。

```powershell
reg add "HKEY_LOCAL_MACHINE\System\CurrentControlSet\Control\TimeZoneInformation" /v RealTimeIsUniversal /d 1 /t REG_DWORD /f
```

### 安装字体

安装几个常用的字体。

```powershell
scoop install Source-Han-Mono-SC Source-Han-Mono-TC Source-Han-Sans-SC Source-Han-Sans-TC Source-Han-Sans-J
scoop install LiberationMono-NF
scoop install Meslo-NF-Mono FantasqueSansMono-NF-Mono
```

### 软件安装

可通过命令行安装的软件:

```powershell
winget install GnuPG.Gpg4win
winget install Microsoft.PowerToys
winget install Telegram.TelegramDesktop
winget install OBSProject.OBSStudio
winget install Audacity.Audacity
scoop install snipaste screentogif ffmpeg busybox vim yt-dlp imageglass exiftool
```

其他软件安装:

- [火绒杀毒软件](https://www.huorong.cn/person5.html)
- [搜狗输入法](https://pinyin.sogou.com/)
- [360 压缩国际版](https://www.360totalsecurity.com/zh-cn/360zip/)
- [qq](https://im.qq.com/pcqq)
- [微信](https://pc.weixin.qq.com)
- [gitkraken](https://www.gitkraken.com/download/windows64)
- [jetbrains tool app](https://www.jetbrains.com/toolbox-app/)
- [sandboxie plus](https://github.com/sandboxie-plus/Sandboxie/releases)
- [其他软件资源](../software-resources/README.md)
- [potplayer](https://potplayer.daum.net)
- [视频解码器](https://codecguide.com/klcp_beta.htm)
- [AMD Ryzen Master](https://www.amd.com/zh-hans/technologies/ryzen-master)
- [yamaha usb driver](https://usa.yamaha.com/support/updates/yamaha_steinberg_usb_driver_for_win.html)
- [夜神模拟器](https://www.yeshen.com)
- [英伟达 Geforce Experience](https://www.nvidia.com/en-us/geforce/geforce-experience/)
- [有道词典](http://cidian.youdao.com/index.html)
- [vscode](https://code.visualstudio.com)
- [tightvnc](https://www.tightvnc.com/download.php)
- [全民 K 歌](https://kg.qq.com/index-pc.html)
- [qq 音乐](https://y.qq.com)
- [网易云音乐](https://music.163.com/#/download)
