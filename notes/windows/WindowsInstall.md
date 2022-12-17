# windows 安装笔记

## 写在前面

- UPDATE1: 我的 windows 安装笔记。由于不小心安装了流氓软件，导致我系统动不动就死机，以至于我才重装系统没几个月就又不得不重装系统，真的是烦透了。而且上次重装系统的笔记记录因为放到了另一个待整理的仓库中，已经被我干掉了。所以不得不从头记一遍笔记。
- UPDATE2: 之前安装的 Win10 还是蛮好用的，除了系统的 emoji 表情没有 Win11 的好看。不过前两天看到别人新安装的 Win11 看起来还是很好用的，于是又手痒了起来，费了点功夫又重装了一遍系统。所以这次的 Windows 安装笔记又可以更新了。
- UPDATE3: win11 的卡顿老毛病又犯了，每次动不动卡个一分钟，勉强可以忍，然而这次竟然连着卡顿十分钟，实在忍不了了，所以又装回了 win10，不得不承认，虽然我很喜欢 win11 的新 emoji，但是还是 win10 比较流畅。
- UPDATE4: 今天不知道啥情况，突然蓝屏了好几次，然后我在 onedrive 文件保管箱中保存文件的时候，资源管理器多次未响应，重启之后点右键再次出现问题，感觉又到了不得不重装系统的时候了。那就在重装回 win11 吧，毕竟过了这么久，问题大概应该修复了吧。之前我在 VHD 双系统里面玩 Win11 感觉还是可以的，反正 Win11 22H2 也更新了，那么就这么定了。

## 必备工作

### 代理

后续安装可能需要代理。

- github 加速 <https://ghproxy.com>
- clash-for-windows <https://github.com/Fndroid/clash_for_windows_pkg/releases>

### 备份和恢复配置

如果是重新安装的系统，可以直接使用原版镜像安装，在安装的时候不格式化 C 盘，这样旧系统会存放到`Windows.old`文件夹中，方便以后从旧系统中恢复文件和配置，一般要备份的文件有

- 桌面文件
- ssh 密钥 (`~/.ssh/`)
- gpg 密钥 (`~/.gnupg`或`~/Appdata/Roaming/gnupg`)
- 我的文档 (游戏存档、一些软件的工程文件、虚拟机等)
- git 仓库
- 其他主文件夹中的配置文件 (`.gitconfig`、`.npmrc`等)

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

现在商店里将所有应用更新一遍，这样就能使用 winget 命令行工具了。无法更新或者没有商店的话，也可以手动下载安装包来安装 <https://github.com/microsoft/winget-cli/releases>。

然后参考[scoop](scoop.md)配置。

## 系统配置

### 激活

安装 business 版系统就可以方便的激活，需要管理员权限。

```powershell
slmgr /skms kms.03k.org
slmgr /ato
```

### 卸载 win11 小组件

win11 新增了小组件功能，但是说白了就是一个信息聚合组件，没有什么用处，直接卸载即可。卸载完成之后小组件按钮可能仍然在任务栏驻留，这时候重启资源管理器应该就不会再见到它了 (需要管理员权限)。

```powershell
winget uninstall MicrosoftWindows.Client.WebExperience_cw5n1h2txyewy
```

### 禁用 Ctrl+空格

默认情况下`Ctrl+空格`是输入法中英文切换的快捷键，而这个快捷键常常作为代码补全的快捷键，经常敲代码的同学建议禁用这个快捷键，为代码补全让路。下载[注册表文件](/windows/disable-ctrl-space-hotkey.reg)(右键链接另存为)，使用管理员权限执行`disable-ctrl-space-toggle.reg`注册表文件，重启电脑即可。

### 系统时间

如果同时安装了 linux 双系统的话，推荐同时让 windows 使用 UTC 代替本地时间，这样两个系统之间的时间就不会冲突了。

```powershell
reg add "HKEY_LOCAL_MACHINE\System\CurrentControlSet\Control\TimeZoneInformation" /v RealTimeIsUniversal /d 1 /t REG_DWORD /f
```

配置完成后，最好立即对时一次 (需要管理员权限)。

```cmd
w32tm /resync
```

## 软件安装

### 安装字体

我的 vscode 配置需要安装思源黑体等几个字体。

```powershell
scoop install Source-Han-Mono-SC Source-Han-Mono-TC Source-Han-Sans-SC Source-Han-Sans-TC Source-Han-Sans-J
scoop install LiberationMono-NF
scoop install Meslo-NF-Mono FantasqueSansMono-NF-Mono
```

### 驱动软件

- [VC++可再发行程序包](https://learn.microsoft.com/en-US/cpp/windows/latest-supported-vc-redist)
- [英伟达 Geforce Experience](https://www.nvidia.com/en-us/geforce/geforce-experience/)
- [yamaha usb driver](https://usa.yamaha.com/support/updates/yamaha_steinberg_usb_driver_for_win.html)
- [视频解码器](https://codecguide.com/klcp_beta.htm)
- [AMD Ryzen Master](https://www.amd.com/zh-hans/technologies/ryzen-master)

### 工具软件

- [TrafficMonitor](https://gitee.com/zhongyang219/TrafficMonitor/releases)
- [gitkraken](https://www.gitkraken.com/download/windows64)
- [tightvnc](https://www.tightvnc.com/download.php)
- [vscode](https://code.visualstudio.com)
- [sandboxie plus](https://github.com/sandboxie-plus/Sandboxie/releases)
- [jetbrains tool app](https://www.jetbrains.com/toolbox-app/)

```powershell
winget install GnuPG.Gpg4win
winget install Microsoft.PowerToys
winget install Telegram.TelegramDesktop
winget install OBSProject.OBSStudio
winget install Audacity.Audacity
scoop install snipaste screentogif ffmpeg busybox vim yt-dlp imageglass exiftool
```

### 应用软件

- [火绒杀毒软件](https://www.huorong.cn/person5.html)
- [搜狗输入法](https://pinyin.sogou.com/)
- [360 压缩国际版](https://www.360totalsecurity.com/zh-cn/360zip/)
- [qq](https://im.qq.com/pcqq)
- [微信](https://pc.weixin.qq.com)
- [potplayer](https://potplayer.daum.net)
- [夜神模拟器](https://www.yeshen.com)
- [有道词典](http://cidian.youdao.com/index.html)
- [全民 K 歌](https://kg.qq.com/index-pc.html)
- [qq 音乐](https://y.qq.com)
- [网易云音乐](https://music.163.com/#/download)

## 收尾工作

确认系统安装和配置完毕之后，就可以清理之前的旧系统了。

以管理员权限打开*磁盘清理*，选择 C 盘，然后清理掉所有不需要的内容。
